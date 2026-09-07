// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/sectionedlistpanel.cpp
// Functions: 97
// ============================================================

#include "vgui2\vgui_controls\sectionedlistpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00434450
// Name: public: virtual bool vgui::SectionedListPanel::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::SectionedListPanel::IsItemIDValid(vgui::SectionedListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // ecx
  bool v3; // zf
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v4; // ecx
  bool result; // al

  result = false;
  if ( itemID >= 0 && itemID < this->m_Items.m_Memory.m_nAllocationCount && itemID <= this->m_Items.m_LastAlloc.index )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    v3 = m_pMemory[itemID].m_Previous == itemID;
    v4 = &m_pMemory[itemID];
    if ( !v3 || v4->m_Next == itemID )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004558B0
// Name: public: static char const __near * vgui::SectionedListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SectionedListPanel::GetPanelClassName()
{
  return "SectionedListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004558C0
// Name: private: static void __near * vgui::SectionedListPanel::GetVar_m_bShowColumns(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::SectionedListPanel::GetVar_m_bShowColumns(vgui::Panel *panel)
{
  return (char *)&panel[1] + 173;
}

//------------------------------------------------------------------------------
// Address: 0x004558D0
// Name: public: static char const __near * vgui::CSectionHeader::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CSectionHeader::GetPanelClassName()
{
  return "CSectionHeader";
}

//------------------------------------------------------------------------------
// Address: 0x004558E0
// Name: public: static char const __near * vgui::CItemButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CItemButton::GetPanelClassName()
{
  return "CItemButton";
}

//------------------------------------------------------------------------------
// Address: 0x004558F0
// Name: public: void vgui::CItemButton::GetCellBounds(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::GetCellBounds(vgui::CItemButton *this, int column, int *xpos, int *columnWide)
{
  int v5; // edi
  int v6; // ebx
  vgui::IImage *v7; // eax
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int colCount; // [esp+Ch] [ebp-8h]
  int wide; // [esp+10h] [ebp-4h] BYREF

  *xpos = 0;
  *columnWide = 0;
  v5 = 0;
  colCount = this->m_pListPanel->GetColumnCountBySection(this: this->m_pListPanel, a2: this->m_iSectionID);
  if ( colCount > 0 )
  {
    do
    {
      v6 = this->m_pListPanel->GetColumnWidthBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v5);
      v7 = this->GetImageAtIndex(this, a2: v5);
      if ( v7 != nullptr )
      {
        v7->GetContentSize(this: v7, a2: &wide, a3: &tall);
        if ( v6 < 0 )
          v6 = wide;
        else
          wide = v6;
        if ( v5 == column )
        {
          *columnWide = v6;
          return;
        }
        *xpos += v6;
      }
      ++v5;
    }
    while ( v5 < colCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004559A0
// Name: public: void vgui::CItemButton::GetMaxCellBounds(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::GetMaxCellBounds(vgui::CItemButton *this, int column, int *xpos, int *columnWide)
{
  int v6; // esi
  int v7; // eax
  int colCount; // [esp+18h] [ebp+Ch]

  *xpos = 0;
  *columnWide = 0;
  v6 = 0;
  colCount = this->m_pListPanel->GetColumnCountBySection(this: this->m_pListPanel, a2: this->m_iSectionID);
  if ( colCount > 0 )
  {
    while ( 1 )
    {
      v7 = this->m_pListPanel->GetColumnWidthBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v6);
      if ( v6 == column )
        break;
      *xpos += v7;
      if ( ++v6 >= colCount )
        return;
    }
    *columnWide = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455A20
// Name: protected: virtual void vgui::SectionedListPanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::SectionedListPanel::ApplySettings(
        vgui::SectionedListPanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  int Int; // eax
  vgui::ISchemeManager *v5; // edi
  vgui::ISchemeManager_vtbl *v6; // ebx
  int v7; // eax

  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "linespacing", defaultValue: 0);
  this->m_iLineSpacing = Int;
  if ( Int == 0 )
    this->m_iLineSpacing = 20;
  if ( this->IsProportional(this) )
  {
    v5 = g_pVGuiSchemeManager;
    v6 = g_pVGuiSchemeManager->__vftable;
    v7 = ((int (__thiscall *)(vgui::SectionedListPanel *, int))this->GetScheme)(a1: this, a2: this->m_iLineSpacing);
    this->m_iLineSpacing = ((int (__thiscall *)(vgui::ISchemeManager *, int))v6->GetProportionalScaledValueEx)(
                             a1: v5,
                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455A90
// Name: public: virtual void vgui::SectionedListPanel::SetVerticalScrollbar(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetVerticalScrollbar(vgui::SectionedListPanel *this, bool state)
{
  this->m_bVerticalScrollbarEnabled = state;
}

//------------------------------------------------------------------------------
// Address: 0x00455AA0
// Name: public: virtual bool vgui::SectionedListPanel::AddColumnToSection(int,char const __near *,char const __near *,int,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::SectionedListPanel::AddColumnToSection(
        vgui::SectionedListPanel *this,
        int sectionID,
        const char *columnName,
        const char *columnText,
        int columnFlags,
        int width,
        unsigned int fallbackFont)
{
  wchar_t *v8; // eax
  wchar_t wtext[64]; // [esp+8h] [ebp-80h] BYREF

  v8 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: columnText);
  if ( v8 == nullptr )
  {
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: columnText, a3: wtext, a4: 128);
    v8 = wtext;
  }
  return this->AddColumnToSection(
           this,
           a2: sectionID,
           a3: columnName,
           a4: v8,
           a5: columnFlags,
           a6: width,
           a7: fallbackFont);
}

//------------------------------------------------------------------------------
// Address: 0x00455B10
// Name: protected: virtual void vgui::SectionedListPanel::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::OnMouseWheeled(vgui::SectionedListPanel *this, int delta)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  int v5; // eax

  if ( vgui::PHandle::Get(this: &this->m_hEditModePanel) != nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: "MouseWheeled", firstKey: "delta", firstValue: delta);
      vgui::Panel::CallParentFunction(this, message: v4);
    }
    else
    {
      vgui::Panel::CallParentFunction(this, message: nullptr);
    }
  }
  else
  {
    v5 = this->m_pScrollBar->GetValue(this: this->m_pScrollBar);
    this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: v5 - 60 * delta);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455BA0
// Name: protected: virtual void vgui::SectionedListPanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::OnSizeChanged(vgui::SectionedListPanel *this, int wide, int tall)
{
  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00455BF0
// Name: protected: virtual void vgui::SectionedListPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::OnMousePressed(vgui::SectionedListPanel *this, ButtonCode_t code)
{
  if ( this->m_clickable )
    this->ClearSelection(this);
}

//------------------------------------------------------------------------------
// Address: 0x00455C10
// Name: public: virtual void vgui::SectionedListPanel::EnterEditMode(int,int,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::EnterEditMode(
        vgui::SectionedListPanel *this,
        int itemID,
        int column,
        vgui::Panel *editPanel)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hEditModePanel, pPanel: editPanel);
  this->m_iEditModeItemID = itemID;
  this->m_iEditModeColumn = column;
  editPanel->SetParent_2(this: editPanel, a2: this);
  editPanel->SetVisible(this: editPanel, a2: true);
  editPanel->RequestFocus(this: editPanel, a2: 0);
  editPanel->MoveToFront(this: editPanel);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00455C80
// Name: public: virtual void vgui::SectionedListPanel::LeaveEditMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::LeaveEditMode(vgui::SectionedListPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax

  if ( vgui::PHandle::Get(this: &this->m_hEditModePanel) != nullptr )
  {
    this->InvalidateItem(this, a2: this->m_iEditModeItemID);
    v2 = vgui::PHandle::Get(this: &this->m_hEditModePanel);
    v2->SetVisible(this: v2, a2: false);
    v3 = vgui::PHandle::Get(this: &this->m_hEditModePanel);
    v3->SetParent_2(this: v3, a2: nullptr);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hEditModePanel, pPanel: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455CF0
// Name: public: virtual bool vgui::SectionedListPanel::IsInEditMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::SectionedListPanel::IsInEditMode(vgui::SectionedListPanel *this)
{
  return vgui::PHandle::Get(this: &this->m_hEditModePanel) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00455D10
// Name: public: virtual void vgui::SectionedListPanel::SetImageList(class vgui::ImageList __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetImageList(
        vgui::SectionedListPanel *this,
        vgui::ImageList *imageList,
        bool deleteImageListWhenDone)
{
  this->m_bDeleteImageListWhenDone = deleteImageListWhenDone;
  this->m_pImageList = imageList;
}

//------------------------------------------------------------------------------
// Address: 0x00455D30
// Name: public: void CUtlMemory<struct vgui::SectionedListPanel::section_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::SectionedListPanel::section_t,int>::Grow(
        CUtlMemory<vgui::SectionedListPanel::section_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::SectionedListPanel::section_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::SectionedListPanel::section_t *)_g_pMemAlloc->Realloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: m_pMemory,
                                                                 a3: v7);
    else
      this->m_pMemory = (vgui::SectionedListPanel::section_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455DE0
// Name: public: vgui::CSectionHeader::CSectionHeader(class vgui::SectionedListPanel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
vgui::CSectionHeader *__thiscall vgui::CSectionHeader::CSectionHeader(
        vgui::CSectionHeader *this,
        vgui::SectionedListPanel *parent,
        char *name,
        int sectionID)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Label::Label(this, parent, panelName: name, text: defaultValue);
  this->__vftable = (vgui::CSectionHeader_vtbl *)&vgui::CSectionHeader::`vftable';
  if ( `vgui::CSectionHeader::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSectionHeader");
    v5->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::CSectionHeader::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSectionHeader");
    v6->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::CSectionHeader::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSectionHeader");
    v7->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_SectionDividerColor = 0;
  this->m_pListPanel = parent;
  this->m_iSectionID = sectionID;
  vgui::Label::SetTextImageIndex(this, newIndex: -1);
  vgui::Label::ClearImages(this);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00455EE0
// Name: public: virtual void vgui::CSectionHeader::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CSectionHeader::Paint(vgui::CSectionHeader *this)
{
  Color m_SectionDividerColor; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  int v5; // eax
  int v6; // [esp-4h] [ebp-20h]
  int x; // [esp+Ch] [ebp-10h] BYREF
  int wide; // [esp+10h] [ebp-Ch] BYREF
  int tall; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  vgui::Label::Paint(this);
  vgui::Panel::GetBounds(this, &x, &y, &wide, &tall);
  m_SectionDividerColor = this->m_SectionDividerColor;
  y = tall - 2;
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: m_SectionDividerColor);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v6 = y + 1;
  v5 = vgui::Panel::GetWide(this);
  v4->DrawFilledRect(this: v3, a2: 1, a3: y, a4: v5 - 2, a5: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00455F50
// Name: public: virtual void vgui::CSectionHeader::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CSectionHeader::PerformLayout(vgui::CSectionHeader *this)
{
  int v2; // edi
  int (__thiscall *GetImageCount)(vgui::Label *); // eax
  int v4; // ebx
  vgui::IImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *v7; // ebx
  vgui::TextImage_vtbl *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // eax
  vgui::TextImage_vtbl *v11; // edi
  Color *v12; // eax
  int v13; // ebx
  int v14; // eax
  vgui::SectionedListPanel *m_pListPanel; // ecx
  int m_iSectionID; // edx
  int v17; // eax
  vgui::CSectionHeader_vtbl *v18; // edx
  int v19; // eax
  vgui::TextImage *v20; // edi
  int v21; // eax
  int v22; // ecx
  int v23; // ebx
  vgui::IImage *v24; // eax
  int v25; // eax
  void (__thiscall *SetImageBounds)(vgui::Label *, int, int, int); // edx
  vgui::TextImage_vtbl *v27; // ebx
  unsigned int v28; // eax
  vgui::TextImage_vtbl *v29; // ebx
  int v30; // eax
  int tall; // [esp+Ch] [ebp-34h] BYREF
  int v32; // [esp+10h] [ebp-30h] BYREF
  int itall; // [esp+14h] [ebp-2Ch] BYREF
  int i; // [esp+18h] [ebp-28h]
  int columnFlags; // [esp+1Ch] [ebp-24h]
  int columnWidth; // [esp+20h] [ebp-20h]
  int contentWide; // [esp+24h] [ebp-1Ch]
  int iwide; // [esp+28h] [ebp-18h] BYREF
  int wide; // [esp+2Ch] [ebp-14h] BYREF
  int maxWidth; // [esp+30h] [ebp-10h]
  int colCount; // [esp+34h] [ebp-Ch]
  int v42; // [esp+38h] [ebp-8h]
  int xpos; // [esp+3Ch] [ebp-4h]

  vgui::Label::PerformLayout(this);
  v2 = this->m_pListPanel->GetColumnCountBySection(this: this->m_pListPanel, a2: this->m_iSectionID);
  GetImageCount = this->GetImageCount;
  colCount = v2;
  if ( v2 != GetImageCount(this) )
  {
    v4 = 0;
    for ( maxWidth = 0; v4 < v2; maxWidth = v4 )
    {
      if ( (this->m_pListPanel->GetColumnFlagsBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v4) & 1) != 0 )
      {
        v5 = nullptr;
      }
      else
      {
        v6 = (vgui::TextImage *)operator new(nSize: 0x80u);
        if ( v6 != nullptr )
          v7 = vgui::TextImage::TextImage(this: v6, text: defaultValue);
        else
          v7 = nullptr;
        v8 = v7->__vftable;
        v9 = this->GetFont(this);
        v8->SetFont(this: v7, a2: v9);
        v10 = this->m_pListPanel->GetColumnFallbackFontBySection(
                this: this->m_pListPanel,
                a2: this->m_iSectionID,
                a3: maxWidth);
        if ( v10 != 0 )
          vgui::TextImage::SetUseFallbackFont(this: v7, bState: true, hFallback: v10);
        v11 = v7->__vftable;
        v12 = this->GetFgColor(this, result: &v32);
        v11->SetColor(this: v7, a2: *v12);
        v2 = colCount;
        v5 = v7;
        v4 = maxWidth;
      }
      this->SetImageAtIndex(this, a2: v4++, a3: v5, a4: 0);
    }
  }
  for ( i = 2; i != 0; --i )
  {
    v13 = 0;
    xpos = 0;
    v42 = 0;
    if ( v2 > 0 )
    {
      do
      {
        v14 = this->m_pListPanel->GetColumnFlagsBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v13);
        m_pListPanel = this->m_pListPanel;
        m_iSectionID = this->m_iSectionID;
        columnFlags = v14;
        v17 = m_pListPanel->GetColumnWidthBySection(this: m_pListPanel, a2: m_iSectionID, a3: v13);
        v18 = this->__vftable;
        columnWidth = v17;
        maxWidth = v17;
        v19 = (int)v18->GetImageAtIndex(this, a2: v13);
        v20 = (vgui::TextImage *)v19;
        if ( v19 != 0 )
        {
          (*(void (__thiscall **)(int, int *, int *))(*(_DWORD *)v19 + 8))(a1: v19, a2: &wide, a3: &tall);
          v21 = wide;
          v22 = columnFlags & 0x10;
          contentWide = wide;
          v32 = v22;
          if ( (columnFlags & 0x10) == 0 )
          {
            v23 = v13 + 1;
            if ( v23 < colCount )
            {
              do
              {
                iwide = 0;
                itall = 0;
                if ( this->GetImageAtIndex(this, a2: v23) != nullptr )
                {
                  v24 = this->GetImageAtIndex(this, a2: v23);
                  v24->GetContentSize(this: v24, a2: &iwide, a3: &itall);
                }
                if ( iwide == 0 )
                {
                  v25 = this->m_pListPanel->GetColumnWidthBySection(
                          this: this->m_pListPanel,
                          a2: this->m_iSectionID,
                          a3: v23);
                  maxWidth += v25;
                }
                ++v23;
              }
              while ( v23 < colCount );
              v21 = wide;
              v22 = v32;
            }
            v13 = v42;
          }
          if ( maxWidth >= 0 )
          {
            v21 = maxWidth;
            wide = maxWidth;
          }
          SetImageBounds = this->SetImageBounds;
          if ( v22 != 0 )
            SetImageBounds(this, a2: v13, a3: xpos + v21 - contentWide, a4: contentWide - 2);
          else
            SetImageBounds(this, a2: v13, a3: xpos, a4: v21 - 2);
          xpos += columnWidth;
          if ( (columnFlags & 1) == 0 )
          {
            v27 = v20->__vftable;
            v28 = this->GetFont(this);
            v27->SetFont(this: v20, a2: v28);
            v29 = v20->__vftable;
            v30 = ((int (__thiscall *)(vgui::SectionedListPanel *, int, int, _DWORD))this->m_pListPanel->GetColumnTextBySection)(
                    a1: this->m_pListPanel,
                    a2: this->m_iSectionID,
                    a3: v42,
                    a4: 0);
            ((void (__thiscall *)(vgui::TextImage *, int))v29->SetText)(a1: v20, a2: v30);
            vgui::TextImage::ResizeImageToContentMaxWidth(this: v20, nMaxWidth: maxWidth);
            v13 = v42;
          }
        }
        else
        {
          xpos += columnWidth;
        }
        v42 = ++v13;
      }
      while ( v13 < colCount );
      v2 = colCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456220
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CSectionHeader::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CSectionHeader::GetMessageMap(vgui::CSectionHeader *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CSectionHeader::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CSectionHeader::GetMessageMap'::`2'::s_pMap;
  `vgui::CSectionHeader::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSectionHeader");
  `vgui::CSectionHeader::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00456250
// Name: public: virtual struct PanelAnimationMap __near * vgui::CSectionHeader::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CSectionHeader::GetAnimMap(vgui::CSectionHeader *this)
{
  return FindOrAddPanelAnimationMap(className: "CSectionHeader");
}

//------------------------------------------------------------------------------
// Address: 0x00456260
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CSectionHeader::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CSectionHeader::GetKBMap(vgui::CSectionHeader *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CSectionHeader::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CSectionHeader::GetKBMap'::`2'::s_pMap;
  `vgui::CSectionHeader::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSectionHeader");
  `vgui::CSectionHeader::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00456290
// Name: public: vgui::CSectionHeader::CSectionHeader(class vgui::SectionedListPanel __near *,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
vgui::CSectionHeader *__thiscall vgui::CSectionHeader::CSectionHeader(
        vgui::CSectionHeader *this,
        vgui::SectionedListPanel *parent,
        const wchar_t *name,
        int sectionID)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Label::Label(this, parent, panelName: "SectionHeader", text: defaultValue);
  this->__vftable = (vgui::CSectionHeader_vtbl *)&vgui::CSectionHeader::`vftable';
  if ( `vgui::CSectionHeader::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSectionHeader");
    v5->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::CSectionHeader::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSectionHeader");
    v6->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::CSectionHeader::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSectionHeader");
    v7->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_SectionDividerColor = 0;
  vgui::Label::SetText(this, unicodeString: name, bClearUnlocalizedSymbol: false);
  vgui::Panel::SetVisible(this, state: 0);
  this->m_pListPanel = parent;
  this->m_iSectionID = sectionID;
  vgui::Label::SetTextImageIndex(this, newIndex: -1);
  vgui::Label::ClearImages(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004563A0
// Name: public: virtual void vgui::CSectionHeader::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CSectionHeader::ApplySchemeSettings(vgui::CSectionHeader *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CSectionHeader_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CSectionHeader_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  vgui::CSectionHeader_vtbl *v9; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v11; // al
  int v12; // eax
  _BYTE v13[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "SectionedListPanel.HeaderTextColor", a4: v2);
  ((void (__thiscall *)(vgui::CSectionHeader *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  this->m_SectionDividerColor = *this->GetSchemeColor_2(
                                   this,
                                   result: &pScheme,
                                   a3: "SectionedListPanel.DividerColor",
                                   a4: v2);
  v6 = this->__vftable;
  v7 = this->GetBgColor(this, result: &pScheme);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::CSectionHeader *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v6->GetSchemeColor)(
                   a1: this,
                   a2: (Color *)v13,
                   a3: "SectionedListPanelHeader.BgColor",
                   a4: *v7,
                   a5: v2);
  ((void (__thiscall *)(vgui::CSectionHeader *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
  if ( this->m_pListPanel->m_hHeaderFont != 0 )
  {
    this->SetFont(this, a2: this->m_pListPanel->m_hHeaderFont);
  }
  else
  {
    v9 = this->__vftable;
    IsProportional = this->IsProportional;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v11 = IsProportional(this);
    v12 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v11);
    v9->SetFont(this, a2: v12);
  }
  this->ClearImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x004564C0
// Name: private: void vgui::SectionedListPanel::SetSelectedItem(class vgui::CItemButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::SectionedListPanel::SetSelectedItem(
        vgui::SectionedListPanel *this@<ecx>,
        int a2@<esi>,
        vgui::CItemButton *item)
{
  vgui::Panel *v4; // esi
  void (__thiscall *SetPaintBackgroundEnabled)(vgui::Panel *, bool); // edx
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // esi
  void (__thiscall *v8)(vgui::Panel *, bool); // eax
  KeyValues *v9; // esi
  int v10; // eax
  KeyValues *v11; // eax
  int v12; // [esp-4h] [ebp-Ch]

  if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != item )
  {
    v12 = a2;
    if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->m_hSelectedItem);
      if ( LOBYTE(v4[1].m_nResizeDeltaX) != 0 )
      {
        SetPaintBackgroundEnabled = v4->SetPaintBackgroundEnabled;
        LOBYTE(v4[1].m_nResizeDeltaX) = 0;
        SetPaintBackgroundEnabled(this: v4, a2: false);
        v4->InvalidateLayout(this: v4, a2: false, a3: false);
        ((void (__thiscall *)(vgui::Panel *, int))v4->Repaint)(a1: v4, a2: v12);
      }
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hSelectedItem, pPanel: item);
    if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != nullptr )
    {
      v6 = vgui::PHandle::Get(this: &this->m_hSelectedItem);
      v7 = v6;
      if ( LOBYTE(v6[1].m_nResizeDeltaX) != 1 )
      {
        v6->RequestFocus(this: v6, a2: 0);
        v8 = v7->SetPaintBackgroundEnabled;
        LOBYTE(v7[1].m_nResizeDeltaX) = 1;
        v8(this: v7, a2: true);
        v7->InvalidateLayout(this: v7, a2: false, a3: false);
        v7->Repaint(this: v7);
      }
    }
    ((void (__thiscall *)(vgui::SectionedListPanel *, int))this->Repaint)(a1: this, a2: v12);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
    {
      if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != nullptr )
        v10 = *(_DWORD *)&vgui::PHandle::Get(this: &this->m_hSelectedItem)[1]._flags.m_nFlags;
      else
        v10 = -1;
      v11 = KeyValues::KeyValues(this: v9, setName: "ItemSelected", firstKey: "itemID", firstValue: v10);
      this->PostActionSignal(this, a2: v11);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456620
// Name: public: virtual int vgui::SectionedListPanel::GetSelectedItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetSelectedItem(vgui::SectionedListPanel *this)
{
  vgui::DHANDLE<vgui::CItemButton> *p_m_hSelectedItem; // esi

  p_m_hSelectedItem = &this->m_hSelectedItem;
  if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != nullptr )
    return *(_DWORD *)&vgui::PHandle::Get(this: p_m_hSelectedItem)[1]._flags.m_nFlags;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00456650
// Name: public: virtual int vgui::SectionedListPanel::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetItemCount(vgui::SectionedListPanel *this)
{
  return this->m_SortedItems.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00456660
// Name: protected: virtual void vgui::SectionedListPanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::OnSetFocus(vgui::SectionedListPanel *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hSelectedItem);
    v2->RequestFocus(this: v2, a2: 0);
  }
  else
  {
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004566A0
// Name: public: void CUtlMemory<struct vgui::SectionedListPanel::column_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::SectionedListPanel::column_t,int>::Grow(
        CUtlMemory<vgui::SectionedListPanel::column_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::SectionedListPanel::column_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 172 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::SectionedListPanel::column_t *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: v7);
    else
      this->m_pMemory = (vgui::SectionedListPanel::column_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456740
// Name: public: virtual void vgui::SectionedListPanel::SetItemFgColor(int,class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetItemFgColor(vgui::SectionedListPanel *this, int itemID, Color color)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // ecx
  int v5; // esi

  if ( itemID >= 0 && itemID < this->m_Items.m_Memory.m_nAllocationCount && itemID <= this->m_Items.m_LastAlloc.index )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    v5 = itemID;
    if ( m_pMemory[itemID].m_Previous != itemID || m_pMemory[v5].m_Next == itemID )
    {
      m_pMemory[v5].m_Element->SetFgColor(this: m_pMemory[v5].m_Element, a2: color);
      this->m_Items.m_Memory.m_pMemory[v5].m_Element->SetOverrideColors(
        this: this->m_Items.m_Memory.m_pMemory[v5].m_Element,
        a2: true);
      this->m_Items.m_Memory.m_pMemory[v5].m_Element->InvalidateLayout(
        this: this->m_Items.m_Memory.m_pMemory[v5].m_Element,
        a2: false,
        a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004567C0
// Name: public: virtual void vgui::SectionedListPanel::SetItemBgColor(int,class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetItemBgColor(vgui::SectionedListPanel *this, int itemID, Color color)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // ecx
  int v5; // esi

  if ( itemID >= 0 && itemID < this->m_Items.m_Memory.m_nAllocationCount && itemID <= this->m_Items.m_LastAlloc.index )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    v5 = itemID;
    if ( m_pMemory[itemID].m_Previous != itemID || m_pMemory[v5].m_Next == itemID )
    {
      m_pMemory[v5].m_Element->SetBgColor(this: m_pMemory[v5].m_Element, a2: color);
      this->m_Items.m_Memory.m_pMemory[v5].m_Element->SetPaintBackgroundEnabled(
        this: this->m_Items.m_Memory.m_pMemory[v5].m_Element,
        a2: true);
      this->m_Items.m_Memory.m_pMemory[v5].m_Element->SetOverrideColors(
        this: this->m_Items.m_Memory.m_pMemory[v5].m_Element,
        a2: true);
      this->m_Items.m_Memory.m_pMemory[v5].m_Element->InvalidateLayout(
        this: this->m_Items.m_Memory.m_pMemory[v5].m_Element,
        a2: false,
        a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456850
// Name: public: virtual void vgui::SectionedListPanel::SetItemFont(int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetItemFont(vgui::SectionedListPanel *this, int itemID, unsigned int font)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // esi
  int v4; // edx

  if ( itemID >= 0 && itemID < this->m_Items.m_Memory.m_nAllocationCount && itemID <= this->m_Items.m_LastAlloc.index )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    v4 = itemID;
    if ( m_pMemory[itemID].m_Previous != itemID || m_pMemory[v4].m_Next == itemID )
      m_pMemory[v4].m_Element->SetFont(this: m_pMemory[v4].m_Element, a2: font);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004568A0
// Name: public: virtual void vgui::SectionedListPanel::SetSectionFgColor(int,class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetSectionFgColor(vgui::SectionedListPanel *this, int sectionID, Color color)
{
  vgui::CSectionHeader *m_pHeader; // ecx

  if ( sectionID >= 0 && sectionID < this->m_Sections.m_Size )
  {
    m_pHeader = this->m_Sections.m_Memory.m_pMemory[sectionID].m_pHeader;
    m_pHeader->m_SectionDividerColor = color;
    m_pHeader->SetFgColor(this: m_pHeader, a2: color);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004568E0
// Name: public: virtual void vgui::SectionedListPanel::SetSectionDividerColor(int,class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetSectionDividerColor(
        vgui::SectionedListPanel *this,
        int sectionID,
        Color color)
{
  if ( sectionID >= 0 && sectionID < this->m_Sections.m_Size )
    this->m_Sections.m_Memory.m_pMemory[sectionID].m_pHeader->m_SectionDividerColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x00456910
// Name: public: virtual void vgui::SectionedListPanel::SetSectionAlwaysVisible(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetSectionAlwaysVisible(
        vgui::SectionedListPanel *this,
        int sectionID,
        bool visible)
{
  if ( sectionID >= 0 && sectionID < this->m_Sections.m_Size )
    this->m_Sections.m_Memory.m_pMemory[sectionID].m_bAlwaysVisible = visible;
}

//------------------------------------------------------------------------------
// Address: 0x00456940
// Name: public: virtual void vgui::SectionedListPanel::SetFontSection(int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetFontSection(
        vgui::SectionedListPanel *this,
        int sectionID,
        unsigned int font)
{
  vgui::CSectionHeader *m_pHeader; // ecx

  if ( sectionID >= 0 && sectionID < this->m_Sections.m_Size )
  {
    m_pHeader = this->m_Sections.m_Memory.m_pMemory[sectionID].m_pHeader;
    m_pHeader->SetFont(this: m_pHeader, a2: font);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456980
// Name: public: virtual void vgui::SectionedListPanel::ClearSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::SectionedListPanel::ClearSelection(vgui::SectionedListPanel *this@<ecx>, int a2@<esi>)
{
  vgui::SectionedListPanel::SetSelectedItem(this, a2, item: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00456990
// Name: public: void vgui::SectionedListPanel::MoveSelectionDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::MoveSelectionDown(vgui::SectionedListPanel *this)
{
  int v2; // eax
  int m_Size; // edx
  int v4; // ecx
  vgui::CItemButton **m_pMemory; // edi
  int m_iID; // edi

  v2 = this->GetSelectedItem(this);
  if ( v2 != -1 )
  {
    m_Size = this->m_SortedItems.m_Size;
    if ( m_Size != 0 )
    {
      v4 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_SortedItems.m_Memory.m_pMemory;
        do
        {
          if ( (*m_pMemory)->m_iID == v2 )
            break;
          ++v4;
          ++m_pMemory;
        }
        while ( v4 < m_Size );
      }
      if ( v4 < m_Size - 1 )
      {
        m_iID = this->m_SortedItems.m_Memory.m_pMemory[v4 + 1]->m_iID;
        vgui::SectionedListPanel::SetSelectedItem(
          this,
          a2: (int)this,
          item: this->m_Items.m_Memory.m_pMemory[m_iID].m_Element);
        this->ScrollToItem(this, a2: m_iID);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456A10
// Name: public: void vgui::SectionedListPanel::MoveSelectionUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::MoveSelectionUp(vgui::SectionedListPanel *this)
{
  int v2; // eax
  int m_Size; // edi
  int v4; // ecx
  vgui::CItemButton **m_pMemory; // edx
  int m_iID; // edi

  v2 = this->GetSelectedItem(this);
  if ( v2 != -1 )
  {
    m_Size = this->m_SortedItems.m_Size;
    if ( m_Size != 0 )
    {
      v4 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_SortedItems.m_Memory.m_pMemory;
        do
        {
          if ( (*m_pMemory)->m_iID == v2 )
            break;
          ++v4;
          ++m_pMemory;
        }
        while ( v4 < m_Size );
        if ( v4 != 0 && v4 < m_Size )
        {
          m_iID = this->m_SortedItems.m_Memory.m_pMemory[v4 - 1]->m_iID;
          vgui::SectionedListPanel::SetSelectedItem(
            this,
            a2: (int)this,
            item: this->m_Items.m_Memory.m_pMemory[m_iID].m_Element);
          this->ScrollToItem(this, a2: m_iID);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456A90
// Name: public: virtual void vgui::SectionedListPanel::SetSelectedItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetSelectedItem(vgui::SectionedListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0 && itemID < this->m_Items.m_Memory.m_nAllocationCount && itemID <= this->m_Items.m_LastAlloc.index )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    v3 = itemID;
    if ( m_pMemory[itemID].m_Previous != itemID || m_pMemory[v3].m_Next == itemID )
      vgui::SectionedListPanel::SetSelectedItem(this, a2: (int)m_pMemory, item: m_pMemory[v3].m_Element);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456B30
// Name: public: virtual int vgui::SectionedListPanel::GetItemSection(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetItemSection(vgui::SectionedListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_Items.m_Memory.m_nAllocationCount
    && itemID <= this->m_Items.m_LastAlloc.index
    && ((m_pMemory = this->m_Items.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->m_iSectionID;
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456B90
// Name: public: virtual int vgui::SectionedListPanel::GetItemIDFromRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetItemIDFromRow(vgui::SectionedListPanel *this, int row)
{
  if ( row >= 0 && row < this->m_SortedItems.m_Size )
    return this->m_SortedItems.m_Memory.m_pMemory[row]->m_iID;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00456BC0
// Name: public: virtual int vgui::SectionedListPanel::GetRowFromItemID(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetRowFromItemID(vgui::SectionedListPanel *this, int itemID)
{
  int m_Size; // edx
  int result; // eax
  vgui::CItemButton **i; // ecx

  m_Size = this->m_SortedItems.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_SortedItems.m_Memory.m_pMemory; (*i)->m_iID != itemID; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00456C00
// Name: public: virtual bool vgui::SectionedListPanel::GetCellBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::GetCellBounds(
        vgui::SectionedListPanel *this,
        int itemID,
        int column,
        int *x,
        int *y,
        int *wide,
        int *tall)
{
  vgui::CItemButton *m_Element; // esi

  *tall = 0;
  *wide = 0;
  *y = 0;
  *x = 0;
  if ( !this->IsItemIDValid(this, a2: itemID) )
    return 0;
  m_Element = this->m_Items.m_Memory.m_pMemory[itemID].m_Element;
  if ( !m_Element->IsVisible(this: m_Element) )
    return 0;
  vgui::Panel::GetBounds(this: m_Element, x, y, wide, tall);
  vgui::CItemButton::GetCellBounds(this: m_Element, column, xpos: x, columnWide: wide);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00456C90
// Name: public: virtual bool vgui::SectionedListPanel::GetMaxCellBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::GetMaxCellBounds(
        vgui::SectionedListPanel *this,
        int itemID,
        int column,
        int *x,
        int *y,
        int *wide,
        int *tall)
{
  vgui::CItemButton *m_Element; // esi

  *tall = 0;
  *wide = 0;
  *y = 0;
  *x = 0;
  if ( !this->IsItemIDValid(this, a2: itemID) )
    return 0;
  m_Element = this->m_Items.m_Memory.m_pMemory[itemID].m_Element;
  if ( !m_Element->IsVisible(this: m_Element) )
    return 0;
  vgui::Panel::GetBounds(this: m_Element, x, y, wide, tall);
  vgui::CItemButton::GetMaxCellBounds(this: m_Element, column, xpos: x, columnWide: wide);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00456D20
// Name: public: virtual bool vgui::SectionedListPanel::GetItemBounds(int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::GetItemBounds(
        vgui::SectionedListPanel *this,
        int itemID,
        int *x,
        int *y,
        int *wide,
        int *tall)
{
  vgui::CItemButton *m_Element; // esi

  *tall = 0;
  *wide = 0;
  *y = 0;
  *x = 0;
  if ( !this->IsItemIDValid(this, a2: itemID) )
    return 0;
  m_Element = this->m_Items.m_Memory.m_pMemory[itemID].m_Element;
  if ( !m_Element->IsVisible(this: m_Element) )
    return 0;
  vgui::Panel::GetBounds(this: m_Element, x, y, wide, tall);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00456DB0
// Name: public: virtual void vgui::SectionedListPanel::InvalidateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::InvalidateItem(vgui::SectionedListPanel *this, int itemID)
{
  int v3; // esi

  if ( this->IsItemIDValid(this, a2: itemID) )
  {
    v3 = itemID;
    this->m_Items.m_Memory.m_pMemory[v3].m_Element->InvalidateLayout(
      this: this->m_Items.m_Memory.m_pMemory[v3].m_Element,
      a2: false,
      a3: false);
    this->m_Items.m_Memory.m_pMemory[v3].m_Element->Repaint(this: this->m_Items.m_Memory.m_pMemory[v3].m_Element);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456E00
// Name: public: virtual unsigned long vgui::SectionedListPanel::GetColumnFallbackFontBySection(int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::SectionedListPanel::GetColumnFallbackFontBySection(
        vgui::SectionedListPanel *this,
        int sectionID,
        int columnIndex)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  int v8; // eax
  bool v9; // cc
  vgui::SectionedListPanel::section_t *v10; // eax

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 >= 0 && (v8 = v4, v9 = columnIndex < m_pMemory[v8].m_Columns.m_Size, v10 = &m_pMemory[v8], v9) )
    return v10->m_Columns.m_Memory.m_pMemory[columnIndex].m_hFallbackFont;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00456FD0
// Name: public: void vgui::CItemButton::SetSectionID(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CItemButton::SetSectionID(vgui::CItemButton *this@<ecx>, int a2@<edi>, int sectionID)
{
  int i; // edi
  vgui::TextImage *v5; // ecx

  if ( sectionID != this->m_iSectionID )
  {
    ((void (__thiscall *)(vgui::CItemButton *, int))this->ClearImages)(a1: this, a2);
    for ( i = 0; i < this->m_TextImages.m_Size; ++i )
    {
      v5 = this->m_TextImages.m_Memory.m_pMemory[i];
      if ( v5 != nullptr )
        ((void (__thiscall *)(vgui::TextImage *, int))v5->dtr_IImage)(a1: v5, a2: 1);
    }
    this->m_TextImages.m_Size = 0;
    ((void (__thiscall *)(vgui::CItemButton *, _DWORD))this->InvalidateLayout)(a1: this, a2: 0);
  }
  this->m_iSectionID = sectionID;
}

//------------------------------------------------------------------------------
// Address: 0x00457050
// Name: private: void vgui::SectionedListPanel::LayoutPanels(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::LayoutPanels(vgui::SectionedListPanel *this, int *contentTall)
{
  unsigned int v3; // eax
  int v4; // eax
  vgui::ScrollBar *m_pScrollBar; // ecx
  int v6; // edi
  bool (__thiscall *IsVisible)(vgui::Panel *); // eax
  int v8; // ebx
  vgui::SectionedListPanel::section_t *v9; // edi
  int v10; // eax
  int m_iID; // ecx
  vgui::CItemButton *v12; // edi
  vgui::Panel *v13; // eax
  int xpos; // [esp+8h] [ebp-24h] BYREF
  int cwide; // [esp+Ch] [ebp-20h] BYREF
  int sectionIndex; // [esp+10h] [ebp-1Ch]
  unsigned int v17; // [esp+14h] [ebp-18h]
  int iEnd; // [esp+18h] [ebp-14h]
  int wide; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int tall; // [esp+24h] [ebp-8h]
  int iStart; // [esp+28h] [ebp-4h]

  if ( this->m_Sections.m_Size != 0
    && (v3 = this->m_Sections.m_Memory.m_pMemory->m_pHeader->GetFont(this: this->m_Sections.m_Memory.m_pMemory->m_pHeader)) != 0 )
  {
    tall = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v3) + 7;
  }
  else
  {
    tall = 20;
  }
  v4 = vgui::Panel::GetWide(this);
  m_pScrollBar = this->m_pScrollBar;
  v6 = v4 - 10;
  IsVisible = m_pScrollBar->IsVisible;
  wide = v6;
  v8 = 5;
  if ( IsVisible(this: m_pScrollBar) )
  {
    v8 = 5 - this->m_pScrollBar->GetValue(this: this->m_pScrollBar);
    wide = v6 - vgui::Panel::GetWide(this: this->m_pScrollBar);
  }
  sectionIndex = 0;
  if ( this->m_Sections.m_Size > 0 )
  {
    v17 = 0;
    do
    {
      v9 = &this->m_Sections.m_Memory.m_pMemory[v17 / 0x24];
      iStart = -1;
      iEnd = -1;
      v10 = 0;
      if ( this->m_SortedItems.m_Size > 0 )
      {
        m_iID = v9->m_iID;
        i = (int)this->m_SortedItems.m_Memory.m_pMemory;
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)i + 432) == m_iID )
          {
            if ( iStart == -1 )
              iStart = v10;
            iEnd = v10;
          }
          i += 4;
          ++v10;
        }
        while ( v10 < this->m_SortedItems.m_Size );
        if ( iStart != -1 )
          goto LABEL_19;
      }
      if ( v9->m_bAlwaysVisible )
      {
LABEL_19:
        if ( this->m_bDrawSectionHeaders )
        {
          vgui::Panel::SetBounds(this: v9->m_pHeader, x: 5, y: v8, wide, tall);
          v9->m_pHeader->SetVisible(this: v9->m_pHeader, a2: true);
          v8 += tall;
        }
        else
        {
          v9->m_pHeader->SetVisible(this: v9->m_pHeader, a2: false);
        }
        if ( iStart != -1 || !v9->m_bAlwaysVisible )
        {
          for ( i = iStart; i <= iEnd; ++i )
          {
            v12 = this->m_SortedItems.m_Memory.m_pMemory[i];
            vgui::Panel::SetBounds(this: v12, x: 5, y: v8, wide, tall: this->m_iLineSpacing);
            if ( vgui::PHandle::Get(this: &this->m_hEditModePanel) != nullptr && this->m_iEditModeItemID == v12->m_iID )
            {
              vgui::CItemButton::GetCellBounds(this: v12, column: 1, &xpos, columnWide: &cwide);
              v13 = vgui::PHandle::Get(this: &this->m_hEditModePanel);
              vgui::Panel::SetBounds(this: v13, x: xpos, y: v8, wide: cwide, tall);
            }
            v8 += this->m_iLineSpacing;
          }
        }
        v8 += 8;
      }
      else
      {
        v9->m_pHeader->SetVisible(this: v9->m_pHeader, a2: false);
      }
      v17 += 36;
      ++sectionIndex;
    }
    while ( sectionIndex < this->m_Sections.m_Size );
  }
  *contentTall = v8;
  if ( this->m_pScrollBar->IsVisible(this: this->m_pScrollBar) )
    *contentTall += this->m_pScrollBar->GetValue(this: this->m_pScrollBar);
}

//------------------------------------------------------------------------------
// Address: 0x004572B0
// Name: public: virtual void vgui::SectionedListPanel::ScrollToItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::ScrollToItem(vgui::SectionedListPanel *this, int iItem)
{
  unsigned int v3; // eax
  int v4; // ebx
  int v5; // edi
  int x; // [esp+Ch] [ebp-18h] BYREF
  int cy; // [esp+10h] [ebp-14h] BYREF
  int cwide; // [esp+14h] [ebp-10h] BYREF
  int itemX; // [esp+18h] [ebp-Ch] BYREF
  int ctall; // [esp+1Ch] [ebp-8h] BYREF
  int itemY; // [esp+20h] [ebp-4h] BYREF

  if ( this->m_Sections.m_Size != 0
    && (v3 = this->m_Sections.m_Memory.m_pMemory->m_pHeader->GetFont(this: this->m_Sections.m_Memory.m_pMemory->m_pHeader)) != 0 )
  {
    v4 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v3) + 7;
  }
  else
  {
    v4 = 20;
  }
  v5 = this->m_pScrollBar->GetValue(this: this->m_pScrollBar);
  vgui::Panel::GetPos(this: this->m_Items.m_Memory.m_pMemory[iItem].m_Element, x: &itemX, y: &itemY);
  itemY += v5;
  vgui::Panel::GetBounds(this, &x, y: &cy, wide: &cwide, tall: &ctall);
  if ( this->m_iContentHeight <= ctall )
  {
    this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: 0);
  }
  else
  {
    if ( itemY < v5 )
    {
      this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: itemY);
      this->Repaint(this);
      return;
    }
    if ( itemY > v5 + ctall - v4 )
    {
      this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: v4 + itemY - ctall);
      this->Repaint(this);
      return;
    }
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004573D0
// Name: protected: virtual void vgui::SectionedListPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::ApplySchemeSettings(vgui::SectionedListPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::SectionedListPanel_vtbl *v4; // ebx
  Color *v5; // eax
  _DWORD *v6; // eax
  vgui::SectionedListPanel_vtbl *v7; // ebx
  int v8; // eax
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // ecx
  int v11; // eax
  _BYTE v12[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetBgColor(this, result: &pScheme);
  v6 = (_DWORD *)((int (__thiscall *)(vgui::SectionedListPanel *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
                   a1: this,
                   a2: (Color *)v12,
                   a3: "SectionedListPanel.BgColor",
                   a4: *v5,
                   a5: v2);
  ((void (__thiscall *)(vgui::SectionedListPanel *, _DWORD))v4->SetBgColor)(a1: this, a2: *v6);
  v7 = this->__vftable;
  v8 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v7->SetBorder(this, a2: (vgui::IBorder *)v8);
  m_Head = this->m_Items.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    do
    {
      v11 = m_Head;
      m_pMemory[v11].m_Element->m_bShowColumns = this->m_bShowColumns;
      m_pMemory = this->m_Items.m_Memory.m_pMemory;
      m_Head = m_pMemory[v11].m_Next;
    }
    while ( m_Head != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457470
// Name: public: virtual void vgui::SectionedListPanel::SetProportional(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetProportional(vgui::SectionedListPanel *this, BOOL state)
{
  BOOL v2; // ebx
  int v4; // esi
  int v5; // ebx
  vgui::CSectionHeader *m_pHeader; // ecx
  int m_Head; // esi
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // eax
  int v9; // esi

  v2 = state;
  vgui::Panel::SetProportional(this, state);
  v4 = 0;
  if ( this->m_Sections.m_Size > 0 )
  {
    v5 = 0;
    do
    {
      m_pHeader = this->m_Sections.m_Memory.m_pMemory[v5].m_pHeader;
      m_pHeader->SetProportional(this: m_pHeader, a2: state);
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_Sections.m_Size );
    v2 = state;
  }
  m_Head = this->m_Items.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    do
    {
      v9 = m_Head;
      m_pMemory[v9].m_Element->SetProportional(this: m_pMemory[v9].m_Element, a2: v2);
      m_pMemory = this->m_Items.m_Memory.m_pMemory;
      m_Head = m_pMemory[v9].m_Next;
    }
    while ( m_Head != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457500
// Name: public: virtual bool vgui::SectionedListPanel::ModifyColumn(int,char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::ModifyColumn(
        vgui::SectionedListPanel *this,
        int sectionID,
        const char *columnName,
        const wchar_t *columnText)
{
  int m_Size; // edx
  int v5; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // edi
  vgui::SectionedListPanel::section_t *i; // ecx
  vgui::SectionedListPanel::section_t *v9; // edi
  int v10; // esi
  int v11; // ebx
  int m_szColumnName; // esi

  m_Size = this->m_Sections.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v5 >= m_Size )
      return 0;
  }
  if ( v5 < 0 )
    return 0;
  v9 = &m_pMemory[v5];
  v10 = 0;
  if ( v9->m_Columns.m_Size <= 0 )
    return 0;
  v11 = 0;
  do
  {
    if ( _V_stricmp(s1: v9->m_Columns.m_Memory.m_pMemory[v11].m_szColumnName, s2: columnName) == 0 )
      break;
    ++v10;
    ++v11;
  }
  while ( v10 < v9->m_Columns.m_Size );
  if ( v10 < 0 || v10 >= v9->m_Columns.m_Size )
    return 0;
  m_szColumnName = (int)v9->m_Columns.m_Memory.m_pMemory[v10].m_szColumnName;
  wcsncpy(dest: (unsigned __int16 *)(m_szColumnName + 32), source: columnText, count: 0x40u);
  *(_WORD *)(m_szColumnName + 158) = 0;
  v9->m_pHeader->InvalidateLayout(this: v9->m_pHeader, a2: false, a3: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004575C0
// Name: public: virtual bool vgui::SectionedListPanel::ModifyItem(int,int,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::SectionedListPanel::ModifyItem@<al>(
        vgui::SectionedListPanel *this@<ecx>,
        int a2@<ebx>,
        int itemID,
        int sectionID,
        KeyValues *data)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // ecx
  int v7; // edi
  vgui::CItemButton *m_Element; // ebx
  KeyValues *m_pData; // ecx
  KeyValues *Copy; // eax
  vgui::CItemButton_vtbl *v12; // edx

  if ( itemID < 0 )
    return 0;
  if ( itemID >= this->m_Items.m_Memory.m_nAllocationCount )
    return 0;
  if ( itemID > this->m_Items.m_LastAlloc.index )
    return 0;
  m_pMemory = this->m_Items.m_Memory.m_pMemory;
  v7 = itemID;
  if ( m_pMemory[itemID].m_Previous == itemID && m_pMemory[v7].m_Next != itemID )
    return 0;
  ((void (__thiscall *)(vgui::SectionedListPanel *, _DWORD, _DWORD, int))this->InvalidateLayout)(
    a1: this,
    a2: 0,
    a3: 0,
    a4: a2);
  vgui::CItemButton::SetSectionID(this: this->m_Items.m_Memory.m_pMemory[v7].m_Element, a2: v7 * 12, sectionID);
  m_Element = this->m_Items.m_Memory.m_pMemory[v7].m_Element;
  m_pData = m_Element->m_pData;
  if ( m_pData != nullptr )
    KeyValues::deleteThis(this: m_pData);
  Copy = KeyValues::MakeCopy(this: data);
  v12 = m_Element->__vftable;
  m_Element->m_pData = Copy;
  ((void (__thiscall *)(vgui::CItemButton *, _DWORD))v12->InvalidateLayout)(a1: m_Element, a2: 0);
  this->m_Items.m_Memory.m_pMemory[v7].m_Element->InvalidateLayout(
    this: this->m_Items.m_Memory.m_pMemory[v7].m_Element,
    a2: false,
    a3: false);
  this->m_bSortNeeded = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00457680
// Name: public: virtual int vgui::SectionedListPanel::GetColumnCountBySection(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetColumnCountBySection(vgui::SectionedListPanel *this, int sectionID)
{
  int m_Size; // edx
  int v3; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // edi
  vgui::SectionedListPanel::section_t *i; // ecx

  m_Size = this->m_Sections.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  if ( v3 >= 0 )
    return m_pMemory[v3].m_Columns.m_Size;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004576D0
// Name: public: virtual char const __near * vgui::SectionedListPanel::GetColumnNameBySection(int,int)
// Source: json
//------------------------------------------------------------------------------
vgui::SectionedListPanel::column_t *__thiscall vgui::SectionedListPanel::GetColumnNameBySection(
        vgui::SectionedListPanel *this,
        int sectionID,
        int columnIndex)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  vgui::SectionedListPanel::section_t *v8; // ecx

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  if ( v4 < 0 )
    return nullptr;
  v8 = &m_pMemory[v4];
  if ( columnIndex >= v8->m_Columns.m_Size )
    return nullptr;
  else
    return &v8->m_Columns.m_Memory.m_pMemory[columnIndex];
}

//------------------------------------------------------------------------------
// Address: 0x00457730
// Name: public: virtual wchar_t const __near * vgui::SectionedListPanel::GetColumnTextBySection(int,int)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall vgui::SectionedListPanel::GetColumnTextBySection(
        vgui::SectionedListPanel *this,
        int sectionID,
        int columnIndex)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  int v8; // eax
  bool v9; // cc
  vgui::SectionedListPanel::section_t *v10; // eax

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  if ( v4 >= 0 && (v8 = v4, v9 = columnIndex < m_pMemory[v8].m_Columns.m_Size, v10 = &m_pMemory[v8], v9) )
    return v10->m_Columns.m_Memory.m_pMemory[columnIndex].m_szColumnText;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00457790
// Name: public: virtual int vgui::SectionedListPanel::GetColumnFlagsBySection(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetColumnFlagsBySection(
        vgui::SectionedListPanel *this,
        int sectionID,
        int columnIndex)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  int v8; // eax
  bool v9; // cc
  vgui::SectionedListPanel::section_t *v10; // eax

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 >= 0 && (v8 = v4, v9 = columnIndex < m_pMemory[v8].m_Columns.m_Size, v10 = &m_pMemory[v8], v9) )
    return v10->m_Columns.m_Memory.m_pMemory[columnIndex].m_iColumnFlags;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00457800
// Name: public: virtual int vgui::SectionedListPanel::GetColumnWidthBySection(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetColumnWidthBySection(
        vgui::SectionedListPanel *this,
        int sectionID,
        int columnIndex)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  int v8; // eax
  bool v9; // cc
  vgui::SectionedListPanel::section_t *v10; // eax

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 >= 0 && (v8 = v4, v9 = columnIndex < m_pMemory[v8].m_Columns.m_Size, v10 = &m_pMemory[v8], v9) )
    return v10->m_Columns.m_Memory.m_pMemory[columnIndex].m_iWidth;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00457870
// Name: public: virtual int vgui::SectionedListPanel::GetColumnIndexByName(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetColumnIndexByName(
        vgui::SectionedListPanel *this,
        int sectionID,
        char *name)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // ebx
  vgui::SectionedListPanel::section_t *i; // ecx
  int v8; // esi
  int v9; // edi
  bool v10; // cc
  vgui::SectionedListPanel::section_t *v11; // eax
  int j; // ebx

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 < 0 )
    return 0;
  v8 = v4;
  v9 = 0;
  v10 = m_pMemory[v4].m_Columns.m_Size <= 0;
  v11 = &m_pMemory[v4];
  if ( v10 )
    return -1;
  for ( j = 0; _V_strcmp(s1: v11->m_Columns.m_Memory.m_pMemory[j].m_szColumnName, s2: name) != 0; ++j )
  {
    ++v9;
    v11 = &this->m_Sections.m_Memory.m_pMemory[v8];
    if ( v9 >= v11->m_Columns.m_Size )
      return -1;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00457920
// Name: protected: virtual void vgui::SectionedListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::SectionedListPanel::OnKeyCodeTyped(vgui::SectionedListPanel *this@<ecx>, int a2@<ebx>, int code)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  unsigned int v6; // eax
  int v7; // edi
  vgui::SectionedListPanel_vtbl *v8; // edx
  int m_iID; // edi
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v10; // eax
  int v11; // ebx
  int v12; // eax
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // edx
  vgui::SectionedListPanel_vtbl *v14; // edx
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v15; // eax
  int v16; // ebx
  int v17; // eax
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v18; // edx
  int x; // [esp+4h] [ebp-14h] BYREF
  int cy; // [esp+8h] [ebp-10h] BYREF
  int cwide; // [esp+Ch] [ebp-Ch] BYREF
  int ctall; // [esp+10h] [ebp-8h] BYREF
  int rowsperpage; // [esp+14h] [ebp-4h]
  int secID; // [esp+20h] [ebp+8h]
  int secIDa; // [esp+20h] [ebp+8h]

  if ( vgui::PHandle::Get(this: &this->m_hEditModePanel) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "KeyCodeTyped", firstKey: "code", firstValue: code);
      vgui::Panel::CallParentFunction(this, message: v5);
    }
    else
    {
      vgui::Panel::CallParentFunction(this, message: nullptr);
    }
    return;
  }
  if ( this->m_Sections.m_Size != 0
    && (v6 = this->m_Sections.m_Memory.m_pMemory->m_pHeader->GetFont(this: this->m_Sections.m_Memory.m_pMemory->m_pHeader)) != 0 )
  {
    v7 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6) + 7;
  }
  else
  {
    v7 = 20;
  }
  switch ( code )
  {
    case 'Z':
      vgui::SectionedListPanel::MoveSelectionDown(this);
      return;
    case 'X':
      vgui::SectionedListPanel::MoveSelectionUp(this);
      return;
    case 'M':
      vgui::Panel::GetBounds(this, &x, y: &cy, wide: &cwide, tall: &ctall);
      v8 = this->__vftable;
      rowsperpage = ctall / v7;
      m_iID = ((int (__thiscall *)(vgui::SectionedListPanel *, int))v8->GetSelectedItem)(a1: this, a2);
      v10 = &this->m_Items.m_Memory.m_pMemory[m_iID];
      secID = v10->m_Element->m_iSectionID;
      v11 = 0;
      v12 = CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int>>::Find(
              this: &this->m_SortedItems,
              src: &v10->m_Element);
      while ( v11 < rowsperpage )
      {
        if ( ++v12 < 0 || v12 >= this->m_SortedItems.m_Size )
          break;
        m_iID = this->m_SortedItems.m_Memory.m_pMemory[v12]->m_iID;
        m_pMemory = this->m_Items.m_Memory.m_pMemory;
        ++v11;
        if ( m_pMemory[m_iID].m_Element->m_iSectionID != secID )
        {
          secID = m_pMemory[m_iID].m_Element->m_iSectionID;
          ++v11;
        }
      }
      goto LABEL_28;
    case 'L':
      vgui::Panel::GetBounds(this, x: &cwide, y: &cy, wide: &x, tall: &ctall);
      v14 = this->__vftable;
      rowsperpage = ctall / v7;
      m_iID = ((int (__thiscall *)(vgui::SectionedListPanel *, int))v14->GetSelectedItem)(a1: this, a2);
      v15 = &this->m_Items.m_Memory.m_pMemory[m_iID];
      secIDa = v15->m_Element->m_iSectionID;
      v16 = 0;
      v17 = CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int>>::Find(
              this: &this->m_SortedItems,
              src: &v15->m_Element);
      if ( rowsperpage <= 0 )
      {
LABEL_28:
        vgui::SectionedListPanel::SetSelectedItem(
          this,
          a2: (int)this,
          item: this->m_Items.m_Memory.m_pMemory[m_iID].m_Element);
        this->ScrollToItem(this, a2: m_iID);
        return;
      }
      while ( --v17 >= 0 && v17 < this->m_SortedItems.m_Size )
      {
        m_iID = this->m_SortedItems.m_Memory.m_pMemory[v17]->m_iID;
        v18 = this->m_Items.m_Memory.m_pMemory;
        ++v16;
        if ( v18[m_iID].m_Element->m_iSectionID != secIDa )
        {
          secIDa = v18[m_iID].m_Element->m_iSectionID;
          ++v16;
        }
        if ( v16 >= rowsperpage )
          goto LABEL_28;
      }
      vgui::SectionedListPanel::SetSelectedItem(
        this,
        a2: (int)this,
        item: this->m_Items.m_Memory.m_pMemory[m_iID].m_Element);
      this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: 0);
      break;
    case 'Y':
    case '[':
LABEL_35:
      break;
    default:
      vgui::Panel::OnKeyCodeTyped(this, keycode: (ButtonCode_t)code);
      goto LABEL_35;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457CB0
// Name: public: vgui::CItemButton::CItemButton(class vgui::SectionedListPanel __near *,int)
// Source: json
//------------------------------------------------------------------------------
vgui::CItemButton *__thiscall vgui::CItemButton::CItemButton(
        vgui::CItemButton *this,
        vgui::SectionedListPanel *parent,
        int itemID)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::CItemButton_vtbl *v7; // eax
  void (__thiscall *SetPaintBackgroundEnabled)(vgui::Panel *, bool); // edx

  vgui::Label::Label(this, parent, panelName: nullptr, text: "< item >");
  this->__vftable = (vgui::CItemButton_vtbl *)&vgui::CItemButton::`vftable';
  if ( `vgui::CItemButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CItemButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CItemButton");
    v4->pfnClassName = vgui::CItemButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::CItemButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CItemButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CItemButton");
    v5->pfnClassName = vgui::CItemButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::CItemButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CItemButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CItemButton");
    v6->pfnClassName = vgui::CItemButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_FgColor2 = 0;
  this->m_BgColor = 0;
  this->m_ArmedFgColor1 = 0;
  this->m_ArmedFgColor2 = 0;
  this->m_OutOfFocusSelectedTextColor = 0;
  this->m_ArmedBgColor = 0;
  this->m_SelectionBG2Color = 0;
  this->m_TextImages.m_Memory.m_pMemory = nullptr;
  this->m_TextImages.m_Memory.m_nAllocationCount = 0;
  this->m_TextImages.m_Memory.m_nGrowSize = 0;
  this->m_TextImages.m_Size = 0;
  this->m_TextImages.m_pElements = nullptr;
  v7 = this->__vftable;
  this->m_pListPanel = parent;
  this->m_iID = itemID;
  SetPaintBackgroundEnabled = v7->SetPaintBackgroundEnabled;
  this->m_pData = nullptr;
  *(_WORD *)&this->m_bSelected = 0;
  this->m_iSectionID = -1;
  SetPaintBackgroundEnabled(this, a2: false);
  this->SetTextImageIndex(this, a2: -1);
  this->ClearImages(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00457E10
// Name: public: virtual void vgui::CItemButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CItemButton::Paint(vgui::CItemButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // eax
  const char *v6; // eax
  vgui::SectionedListPanel *m_pListPanel; // ecx
  int m_iSectionID; // edx
  char v9; // bl
  int Int; // ebx
  vgui::IImage *v11; // eax
  int v12; // eax
  vgui::ISurface_vtbl *v13; // ebx
  int colCount; // [esp+4h] [ebp-24h]
  int maxWidth; // [esp+8h] [ebp-20h]
  vgui::ISurface *maxWidtha; // [esp+8h] [ebp-20h]
  int v19; // [esp+Ch] [ebp-1Ch] BYREF
  const char *keyname; // [esp+10h] [ebp-18h]
  int wide; // [esp+14h] [ebp-14h] BYREF
  int tall; // [esp+18h] [ebp-10h] BYREF
  int imageWide; // [esp+1Ch] [ebp-Ch] BYREF
  int xpos; // [esp+20h] [ebp-8h]
  vgui::IImage *image; // [esp+24h] [ebp-4h]

  vgui::Label::Paint(this);
  if ( this->m_bShowColumns )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
    v4 = 0;
    g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
    v5 = this->m_pListPanel->GetColumnCountBySection(this: this->m_pListPanel, a2: this->m_iSectionID);
    colCount = v5;
    if ( this->m_pData != nullptr && v5 >= 0 )
    {
      xpos = 0;
      if ( v5 > 0 )
      {
        do
        {
          v6 = (const char *)((int (__thiscall *)(vgui::SectionedListPanel *, int, int, int, int))this->m_pListPanel->GetColumnNameBySection)(
                               a1: this->m_pListPanel,
                               a2: this->m_iSectionID,
                               a3: v4,
                               a4: a2,
                               a5: a3);
          m_pListPanel = this->m_pListPanel;
          m_iSectionID = this->m_iSectionID;
          keyname = v6;
          v9 = m_pListPanel->GetColumnFlagsBySection(this: m_pListPanel, a2: m_iSectionID, a3: v4);
          maxWidth = this->m_pListPanel->GetColumnWidthBySection(
                       this: this->m_pListPanel,
                       a2: this->m_iSectionID,
                       a3: v4);
          image = nullptr;
          if ( (v9 & 2) != 0 )
          {
            if ( this->m_pListPanel->m_pImageList == nullptr )
              goto LABEL_12;
            Int = KeyValues::GetInt(this: this->m_pData, keyName: (char *)keyname, defaultValue: 0);
            if ( !vgui::ImageList::IsValidIndex(this: this->m_pListPanel->m_pImageList, imageIndex: Int) || Int <= 0 )
              goto LABEL_12;
            v11 = vgui::ImageList::GetImage(this: this->m_pListPanel->m_pImageList, imageIndex: Int);
          }
          else
          {
            v11 = this->GetImageAtIndex(this, a2: v4);
          }
          image = v11;
LABEL_12:
          imageWide = 0;
          v19 = 0;
          if ( image != nullptr )
            image->GetContentSize(this: image, a2: &imageWide, a3: &v19);
          v12 = maxWidth;
          if ( maxWidth < 0 )
            v12 = imageWide;
          xpos += v12;
          v13 = g_pVGuiSurface->__vftable;
          maxWidtha = g_pVGuiSurface;
          a3 = vgui::Panel::GetTall(this);
          a2 = xpos;
          ((void (__thiscall *)(vgui::ISurface *, int, _DWORD))v13->DrawOutlinedRect)(a1: maxWidtha, a2: xpos, a3: 0);
          ++v4;
        }
        while ( v4 < colCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457FD0
// Name: public: virtual void vgui::CItemButton::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::OnKillFocus(vgui::CItemButton *this)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00457FF0
// Name: public: virtual void vgui::CItemButton::SetOverrideColors(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::SetOverrideColors(vgui::CItemButton *this, bool state)
{
  this->m_bOverrideColors = state;
}

//------------------------------------------------------------------------------
// Address: 0x00458000
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CItemButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CItemButton::GetMessageMap(vgui::CItemButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CItemButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CItemButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CItemButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CItemButton");
  `vgui::CItemButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00458030
// Name: public: virtual struct PanelAnimationMap __near * vgui::CItemButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CItemButton::GetAnimMap(vgui::CItemButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CItemButton");
}

//------------------------------------------------------------------------------
// Address: 0x00458040
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CItemButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CItemButton::GetKBMap(vgui::CItemButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CItemButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CItemButton::GetKBMap'::`2'::s_pMap;
  `vgui::CItemButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CItemButton");
  `vgui::CItemButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00458070
// Name: public: virtual void vgui::CItemButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::ApplySchemeSettings(vgui::CItemButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CItemButton_vtbl *v4; // ebx
  Color *v5; // eax
  int m_hRowFont; // eax
  int v7; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v9; // al
  _BYTE v10[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->m_ArmedFgColor1 = *this->GetSchemeColor_2(
                             this,
                             result: &pScheme,
                             a3: "SectionedListPanel.BrightTextColor",
                             a4: v2);
  this->m_ArmedFgColor2 = *this->GetSchemeColor_2(
                             this,
                             result: &pScheme,
                             a3: "SectionedListPanel.SelectedTextColor",
                             a4: v2);
  this->m_OutOfFocusSelectedTextColor = *this->GetSchemeColor_2(
                                           this,
                                           result: &pScheme,
                                           a3: "SectionedListPanel.OutOfFocusSelectedTextColor",
                                           a4: v2);
  this->m_ArmedBgColor = *this->GetSchemeColor_2(
                            this,
                            result: &pScheme,
                            a3: "SectionedListPanel.SelectedBgColor",
                            a4: v2);
  this->m_FgColor2 = *this->GetSchemeColor_2(this, result: &pScheme, a3: "SectionedListPanel.TextColor", a4: v2);
  v4 = this->__vftable;
  v5 = this->GetBgColor(this, result: &pScheme);
  this->m_BgColor = *((int (__thiscall *)(vgui::CItemButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
                       a1: this,
                       a2: (Color *)v10,
                       a3: "SectionedListPanel.BgColor",
                       a4: *v5,
                       a5: v2);
  this->m_SelectionBG2Color = *this->GetSchemeColor_2(
                                 this,
                                 result: &pScheme,
                                 a3: "SectionedListPanel.OutOfFocusSelectedBgColor",
                                 a4: v2);
  m_hRowFont = this->m_pListPanel->m_hRowFont;
  if ( m_hRowFont != 0
    || (v7 = (int)v2->GetResourceString(this: v2, a2: "SectionedListPanel.Font"),
        IsProportional = this->IsProportional,
        pScheme = (vgui::IScheme *)v2->__vftable,
        v9 = IsProportional(this),
        (m_hRowFont = ((int (__thiscall *)(vgui::IScheme *, int, bool))pScheme[3].__vftable)(a1: v2, a2: v7, a3: v9)) != 0) )
  {
    this->SetFont(this, a2: m_hRowFont);
  }
  this->ClearImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x004581D0
// Name: public: virtual void vgui::CItemButton::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::PaintBackground(vgui::CItemButton *this)
{
  unsigned int v2; // ebx
  vgui::IPanel *v3; // edi
  unsigned int (__thiscall *GetVParent)(vgui::Panel *); // eax
  int v5; // eax
  vgui::ISurface_vtbl *v6; // ebx
  int v7; // eax
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  vgui::IPanel_vtbl *v10; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  if ( !this->m_bSelected || this->m_pListPanel->IsInEditMode(this: this->m_pListPanel) )
  {
    v6 = g_pVGuiSurface->__vftable;
    v7 = (int)*this->GetBgColor(this, result: &v10);
    ((void (__stdcall *)(int))v6->DrawSetColor)(a1: v7);
  }
  else
  {
    v2 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
    if ( this->HasFocus(this)
      || v2 != 0
      && (v3 = g_pVGuiPanel,
          GetVParent = this->GetVParent,
          v10 = g_pVGuiPanel->__vftable,
          v5 = GetVParent(this),
          v10->HasParent(this: v3, a2: v2, a3: v5)) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->m_ArmedBgColor);
    }
    else
    {
      ((void (__stdcall *)(_DWORD))g_pVGuiSurface->DrawSetColor)(a1: *(_DWORD *)&this->m_SelectionBG2Color);
    }
  }
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x004582C0
// Name: public: virtual void vgui::CItemButton::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::OnMousePressed(vgui::CItemButton *this, ButtonCode_t code)
{
  vgui::SectionedListPanel *m_pListPanel; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  m_pListPanel = this->m_pListPanel;
  if ( m_pListPanel != nullptr && m_pListPanel->m_clickable )
  {
    if ( code == KEY_COUNT )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "ItemLeftClick", firstKey: "itemID", firstValue: this->m_iID);
      else
        v5 = nullptr;
      this->m_pListPanel->PostActionSignal(this: this->m_pListPanel, a2: v5);
      vgui::SectionedListPanel::SetSelectedItem(this: this->m_pListPanel, a2: (int)this, item: this);
    }
    else
    {
      if ( code == MOUSE_RIGHT )
      {
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
          v7 = KeyValues::KeyValues(this: v6, setName: "ItemContextMenu", firstKey: "itemID", firstValue: this->m_iID);
        else
          v7 = nullptr;
        KeyValues::SetPtr(this: v7, keyName: "SubPanel", value: this);
        this->m_pListPanel->PostActionSignal(this: this->m_pListPanel, a2: v7);
      }
      vgui::SectionedListPanel::SetSelectedItem(this: this->m_pListPanel, a2: (int)this, item: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004583A0
// Name: public: virtual void vgui::CItemButton::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::OnMouseDoublePressed(vgui::CItemButton *this, ButtonCode_t code)
{
  vgui::SectionedListPanel *m_pListPanel; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  m_pListPanel = this->m_pListPanel;
  if ( m_pListPanel != nullptr && m_pListPanel->m_clickable )
  {
    if ( code == KEY_COUNT )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "ItemDoubleLeftClick", firstKey: "itemID", firstValue: this->m_iID);
      else
        v5 = nullptr;
      this->m_pListPanel->PostActionSignal(this: this->m_pListPanel, a2: v5);
      this->m_pListPanel->OnKeyCodeTyped(this: this->m_pListPanel, a2: KEY_ENTER);
      vgui::SectionedListPanel::SetSelectedItem(this: this->m_pListPanel, a2: (int)this, item: this);
    }
    else
    {
      this->OnMousePressed(this, a2: code);
      vgui::SectionedListPanel::SetSelectedItem(this: this->m_pListPanel, a2: (int)this, item: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458490
// Name: public: static void vgui::SectionedListPanel::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::SectionedListPanel::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::SectionedListPanel::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::SectionedListPanel::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::SectionedListPanel::`vcall'{1032,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "SectionedListPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ScrollBarSliderMoved";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458520
// Name: public: static void vgui::SectionedListPanel::PanelAnimationVar_m_bShowColumns::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::SectionedListPanel::PanelAnimationVar_m_bShowColumns::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::SectionedListPanel::PanelAnimationVar_m_bShowColumns::InitVar'::`2'::bAdded )
  {
    `vgui::SectionedListPanel::PanelAnimationVar_m_bShowColumns::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "SectionedListPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "show_columns";
    src.m_pszVariable = "m_bShowColumns";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "false";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::SectionedListPanel::GetVar_m_bShowColumns;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458580
// Name: public: virtual void vgui::CItemButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::PerformLayout(vgui::CItemButton *this)
{
  int v2; // eax
  bool v3; // zf
  int v4; // edi
  int v5; // ebx
  vgui::TextImage *v6; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  vgui::TextImage **m_pMemory; // ecx
  int v10; // eax
  vgui::TextImage **v11; // ebx
  vgui::TextImage_vtbl *v12; // edi
  unsigned int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  int v16; // ebx
  int v17; // ebx
  const char *v18; // eax
  vgui::SectionedListPanel *m_pListPanel; // ecx
  int m_iSectionID; // edx
  int v21; // eax
  vgui::SectionedListPanel *v22; // ecx
  int (__thiscall *GetColumnWidthBySection)(vgui::SectionedListPanel *, int, int); // edx
  vgui::TextImage *v24; // edi
  int Int; // eax
  vgui::ImageList *m_pImageList; // ecx
  vgui::IImage *v27; // eax
  vgui::TextImage *v28; // eax
  vgui::TextImage_vtbl *v29; // ebx
  char *String; // eax
  unsigned int v31; // eax
  unsigned int v32; // ebx
  vgui::CItemButton_vtbl *v33; // edx
  vgui::IPanel_vtbl *v34; // ebx
  int v35; // eax
  void (__thiscall *SetColor)(struct vgui::TextImage *, Color); // edx
  vgui::IPanel_vtbl *v37; // ebx
  unsigned int v38; // eax
  vgui::TextImage_vtbl *v39; // ebx
  Color *v40; // eax
  int v41; // eax
  int v42; // edi
  int v43; // [esp-4h] [ebp-3Ch]
  char v44[4]; // [esp+Ch] [ebp-2Ch] BYREF
  int v45; // [esp+10h] [ebp-28h]
  int tall; // [esp+14h] [ebp-24h] BYREF
  vgui::IPanel *v47; // [esp+18h] [ebp-20h]
  int colCount; // [esp+1Ch] [ebp-1Ch]
  int maxWidth; // [esp+20h] [ebp-18h]
  unsigned int focus; // [esp+24h] [ebp-14h]
  int imageWide; // [esp+28h] [ebp-10h] BYREF
  int columnFlags; // [esp+2Ch] [ebp-Ch]
  vgui::TextImage *image; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]

  v2 = this->m_pListPanel->GetColumnCountBySection(this: this->m_pListPanel, a2: this->m_iSectionID);
  v3 = this->m_pData == nullptr;
  v4 = v2;
  colCount = v2;
  if ( v3 || v2 < 1 )
  {
    this->SetText(this, a2: "< unset >");
  }
  else
  {
    if ( v2 != this->GetImageCount(this) )
    {
      v5 = 0;
      for ( i = 0; v5 < v4; i = v5 )
      {
        if ( (this->m_pListPanel->GetColumnFlagsBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v5) & 2) == 0 )
        {
          v6 = (vgui::TextImage *)operator new(nSize: 0x80u);
          if ( v6 != nullptr )
            image = vgui::TextImage::TextImage(this: v6, text: defaultValue);
          else
            image = nullptr;
          m_Size = this->m_TextImages.m_Size;
          m_nAllocationCount = this->m_TextImages.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_TextImages,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_TextImages.m_Size;
          m_pMemory = this->m_TextImages.m_Memory.m_pMemory;
          v10 = this->m_TextImages.m_Size - m_Size - 1;
          this->m_TextImages.m_pElements = m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
          v11 = &this->m_TextImages.m_Memory.m_pMemory[m_Size];
          if ( v11 != nullptr )
            *v11 = image;
          v12 = image->__vftable;
          v13 = this->GetFont(this);
          v12->SetFont(this: image, a2: v13);
          v14 = this->m_pListPanel->GetColumnFallbackFontBySection(
                  this: this->m_pListPanel,
                  a2: this->m_iSectionID,
                  a3: i);
          if ( v14 != 0 )
            vgui::TextImage::SetUseFallbackFont(this: image, bState: true, hFallback: v14);
          this->SetImageAtIndex(this, a2: i, a3: image, a4: 0);
          v4 = colCount;
          v5 = i;
        }
        ++v5;
      }
      v15 = this->GetImageCount(this);
      if ( v15 < v4 )
      {
        v16 = v4 - v15;
        do
        {
          this->AddImage(this, a2: nullptr, a3: 0);
          --v16;
        }
        while ( v16 != 0 );
      }
    }
    v17 = 0;
    image = nullptr;
    i = 0;
    if ( v4 > 0 )
    {
      while ( 1 )
      {
        v18 = this->m_pListPanel->GetColumnNameBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v17);
        m_pListPanel = this->m_pListPanel;
        m_iSectionID = this->m_iSectionID;
        focus = (unsigned int)v18;
        v21 = m_pListPanel->GetColumnFlagsBySection(this: m_pListPanel, a2: m_iSectionID, a3: v17);
        v22 = this->m_pListPanel;
        GetColumnWidthBySection = v22->GetColumnWidthBySection;
        columnFlags = v21;
        maxWidth = GetColumnWidthBySection(this: v22, a2: this->m_iSectionID, a3: v17);
        v24 = nullptr;
        v45 = columnFlags & 2;
        if ( (columnFlags & 2) != 0 )
        {
          if ( this->m_pListPanel->m_pImageList != nullptr )
          {
            Int = KeyValues::GetInt(this: this->m_pData, keyName: (char *)focus, defaultValue: 0);
            m_pImageList = this->m_pListPanel->m_pImageList;
            focus = Int;
            if ( vgui::ImageList::IsValidIndex(this: m_pImageList, imageIndex: Int) && (int)focus > 0 )
            {
              v24 = (vgui::TextImage *)vgui::ImageList::GetImage(
                                         this: this->m_pListPanel->m_pImageList,
                                         imageIndex: focus);
              this->SetImageAtIndex(this, a2: v17, a3: v24, a4: 0);
            }
          }
          goto LABEL_46;
        }
        v27 = this->GetImageAtIndex(this, a2: v17);
        v28 = (vgui::TextImage *)__RTDynamicCast(
                                   inptr: v27,
                                   VfDelta: 0,
                                   SrcType: &vgui::IImage `RTTI Type Descriptor',
                                   TargetType: &vgui::TextImage `RTTI Type Descriptor',
                                   isReference: 0);
        v24 = v28;
        if ( v28 != nullptr )
          break;
LABEL_46:
        v41 = 0;
        imageWide = 0;
        tall = 0;
        if ( v24 != nullptr )
        {
          v24->GetContentSize(this: v24, a2: &imageWide, a3: &tall);
          v41 = imageWide;
        }
        v42 = maxWidth;
        if ( maxWidth < 0 )
          v42 = v41;
        if ( v17 != 0 || v45 != 0 )
        {
          if ( (columnFlags & 8) != 0 )
          {
            this->SetImageBounds(
              this,
              a2: v17,
              a3: (int)image + v42 / 2 - imageWide / 2,
              a4: v42 - (v42 / 2 - imageWide / 2) - 2);
          }
          else
          {
            v43 = v42 - 2;
            if ( (columnFlags & 0x10) != 0 )
              this->SetImageBounds(this, a2: v17, a3: (int)image + v42 - v41, a4: v43);
            else
              this->SetImageBounds(this, a2: v17, a3: (int)image, a4: v43);
          }
        }
        else
        {
          this->SetImageBounds(this, a2: 0, a3: (int)image->_pos + 2, a4: v42 - 8);
        }
        image = (vgui::TextImage *)((char *)image + v42);
        i = ++v17;
        if ( v17 >= colCount )
        {
          vgui::Label::PerformLayout(this);
          return;
        }
      }
      v29 = v28->__vftable;
      String = KeyValues::GetString(this: this->m_pData, keyName: (char *)focus, defaultValue: defaultValue);
      v29->SetText_2(this: v24, a2: String);
      vgui::TextImage::ResizeImageToContentMaxWidth(this: v24, nMaxWidth: maxWidth);
      v31 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
      v3 = !this->m_bOverrideColors;
      v32 = v31;
      focus = v31;
      if ( v3 )
      {
        if ( !this->m_bSelected || this->m_pListPanel->IsInEditMode(this: this->m_pListPanel) )
        {
          SetColor = v24->SetColor;
          if ( (columnFlags & 4) != 0 )
            ((void (__thiscall *)(vgui::TextImage *, _DWORD))SetColor)(a1: v24, a2: *(_DWORD *)&this->m_ArmedFgColor1);
          else
            ((void (__thiscall *)(vgui::TextImage *, _DWORD))SetColor)(a1: v24, a2: *(_DWORD *)&this->m_FgColor2);
          goto LABEL_45;
        }
        if ( !this->HasFocus(this) )
        {
          if ( v32 == 0
            || (v33 = this->__vftable,
                v34 = g_pVGuiPanel->__vftable,
                v47 = g_pVGuiPanel,
                v35 = v33->GetVParent(this),
                !v34->HasParent(this: v47, a2: focus, a3: v35)) )
          {
            ((void (__thiscall *)(vgui::TextImage *, _DWORD))v24->SetColor)(
              a1: v24,
              a2: *(_DWORD *)&this->m_OutOfFocusSelectedTextColor);
LABEL_45:
            v17 = i;
            goto LABEL_46;
          }
        }
      }
      else if ( !this->m_bSelected
             || !this->HasFocus(this)
             && (v32 == 0
              || (v37 = g_pVGuiPanel->__vftable,
                  v47 = g_pVGuiPanel,
                  v38 = this->GetVParent(this),
                  !v37->HasParent(this: v47, a2: focus, a3: v38))) )
      {
        v39 = v24->__vftable;
        v40 = this->GetFgColor(this, result: v44);
        v39->SetColor(this: v24, a2: *v40);
        goto LABEL_45;
      }
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v24->SetColor)(a1: v24, a2: *(_DWORD *)&this->m_ArmedFgColor2);
      goto LABEL_45;
    }
  }
  vgui::Label::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00458A70
// Name: private: void vgui::SectionedListPanel::ReSortList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::ReSortList(vgui::SectionedListPanel *this)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_SortedItems; // esi
  int m_Head; // ebx
  int v3; // edi
  bool v4; // zf
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v7; // ebx
  vgui::TreeNode **v8; // edx
  int v9; // eax
  vgui::CItemButton **v10; // edi
  int v11; // edx
  vgui::TreeNode **v12; // eax
  vgui::TreeNode **v13; // edx
  int v14; // eax
  vgui::CItemButton **v15; // edi
  vgui::TreeNode **v16; // edi
  int v17; // eax
  vgui::TreeNode **v18; // edx
  int v19; // eax
  vgui::CItemButton **v20; // edi
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v21; // [esp+4h] [ebp-1Ch]
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v22; // [esp+4h] [ebp-1Ch]
  int sectionStart; // [esp+8h] [ebp-18h]
  int sectionIndex; // [esp+Ch] [ebp-14h]
  vgui::SectionedListPanel::section_t *section; // [esp+10h] [ebp-10h]
  int v26; // [esp+14h] [ebp-Ch]
  int v27; // [esp+18h] [ebp-8h]
  vgui::SectionedListPanel *v28; // [esp+1Ch] [ebp-4h]

  p_m_SortedItems = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SortedItems;
  this->m_SortedItems.m_Size = 0;
  v28 = this;
  sectionIndex = 0;
  if ( this->m_Sections.m_Size > 0 )
  {
    v27 = 0;
    do
    {
      m_Head = this->m_Items.m_Head;
      section = &this->m_Sections.m_Memory.m_pMemory[v27];
      for ( sectionStart = this->m_SortedItems.m_Size; m_Head != -1; m_Head = this->m_Items.m_Memory.m_pMemory[v26].m_Next )
      {
        v26 = m_Head;
        v21 = &this->m_Items.m_Memory.m_pMemory[m_Head];
        if ( v21->m_Element->m_iSectionID == this->m_Sections.m_Memory.m_pMemory[v27].m_iID )
        {
          if ( section->m_pSortFunc != nullptr )
          {
            v3 = sectionStart;
            v4 = sectionStart == this->m_SortedItems.m_Size;
            if ( sectionStart < this->m_SortedItems.m_Size )
            {
              while ( !section->m_pSortFunc(
                         a1: this,
                         a2: m_Head,
                         a3: p_m_SortedItems->m_pMemory[v3][1].m_LastNavDirection) )
              {
                if ( ++v3 >= v28->m_SortedItems.m_Size )
                  break;
                this = v28;
              }
              this = v28;
              v4 = v3 == v28->m_SortedItems.m_Size;
            }
            if ( v4 )
            {
              m_pMemory = p_m_SortedItems[1].m_pMemory;
              m_nAllocationCount = p_m_SortedItems->m_nAllocationCount;
              v7 = &this->m_Items.m_Memory.m_pMemory[v26];
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
              {
                CUtlMemory<unsigned long,int>::Grow(this: p_m_SortedItems, num: (int)m_pMemory - m_nAllocationCount + 1);
                this = v28;
              }
              ++p_m_SortedItems[1].m_pMemory;
              v8 = p_m_SortedItems->m_pMemory;
              v9 = (char *)p_m_SortedItems[1].m_pMemory - (char *)m_pMemory - 1;
              p_m_SortedItems[1].m_nAllocationCount = (int)p_m_SortedItems->m_pMemory;
              if ( v9 > 0 )
              {
                _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
                this = v28;
              }
              v10 = (vgui::CItemButton **)&p_m_SortedItems->m_pMemory[(_DWORD)m_pMemory];
              if ( v10 != nullptr )
                *v10 = v7->m_Element;
            }
            else
            {
              v11 = p_m_SortedItems->m_nAllocationCount;
              v22 = &this->m_Items.m_Memory.m_pMemory[v26];
              v12 = p_m_SortedItems[1].m_pMemory;
              if ( (int)v12 + 1 > v11 )
              {
                CUtlMemory<unsigned long,int>::Grow(this: p_m_SortedItems, num: (int)v12 - v11 + 1);
                this = v28;
              }
              ++p_m_SortedItems[1].m_pMemory;
              v13 = p_m_SortedItems->m_pMemory;
              v14 = (int)p_m_SortedItems[1].m_pMemory - v3 - 1;
              p_m_SortedItems[1].m_nAllocationCount = (int)p_m_SortedItems->m_pMemory;
              if ( v14 > 0 )
              {
                _V_memmove(dest: &v13[v3 + 1], src: &v13[v3], count: 4 * v14);
                this = v28;
              }
              v15 = (vgui::CItemButton **)&p_m_SortedItems->m_pMemory[v3];
              if ( v15 != nullptr )
                *v15 = v22->m_Element;
            }
          }
          else
          {
            v16 = p_m_SortedItems[1].m_pMemory;
            v17 = p_m_SortedItems->m_nAllocationCount;
            if ( (int)v16 + 1 > v17 )
            {
              CUtlMemory<unsigned long,int>::Grow(this: p_m_SortedItems, num: (int)v16 - v17 + 1);
              this = v28;
            }
            ++p_m_SortedItems[1].m_pMemory;
            v18 = p_m_SortedItems->m_pMemory;
            v19 = (char *)p_m_SortedItems[1].m_pMemory - (char *)v16 - 1;
            p_m_SortedItems[1].m_nAllocationCount = (int)p_m_SortedItems->m_pMemory;
            if ( v19 > 0 )
            {
              _V_memmove(dest: &v18[(_DWORD)v16 + 1], src: &v18[(_DWORD)v16], count: 4 * v19);
              this = v28;
            }
            v20 = (vgui::CItemButton **)&p_m_SortedItems->m_pMemory[(_DWORD)v16];
            if ( v20 != nullptr )
              *v20 = v21->m_Element;
          }
        }
      }
      ++v27;
      ++sectionIndex;
    }
    while ( sectionIndex < this->m_Sections.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458CA0
// Name: protected: virtual void vgui::SectionedListPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::PerformLayout(vgui::SectionedListPanel *this)
{
  int Wide; // eax
  int v3; // eax
  int v4; // [esp-4h] [ebp-1Ch]
  int x; // [esp+8h] [ebp-10h] BYREF
  int cy; // [esp+Ch] [ebp-Ch] BYREF
  int cwide; // [esp+10h] [ebp-8h] BYREF
  int ctall; // [esp+14h] [ebp-4h] BYREF

  if ( this->m_bSortNeeded )
  {
    vgui::SectionedListPanel::ReSortList(this);
    this->m_bSortNeeded = false;
  }
  vgui::Panel::PerformLayout(this);
  vgui::SectionedListPanel::LayoutPanels(this, contentTall: &this->m_iContentHeight);
  vgui::Panel::GetBounds(this, &x, y: &cy, wide: &cwide, tall: &ctall);
  if ( this->m_iContentHeight > ctall && this->m_bVerticalScrollbarEnabled )
  {
    this->m_pScrollBar->SetVisible(this: this->m_pScrollBar, a2: true);
    this->m_pScrollBar->MoveToFront(this: this->m_pScrollBar);
    Wide = vgui::Panel::GetWide(this: this->m_pScrollBar);
    vgui::Panel::SetPos(this: this->m_pScrollBar, x: cwide - Wide - 2, y: 0);
    v4 = ctall - 2;
    v3 = vgui::Panel::GetWide(this: this->m_pScrollBar);
    vgui::Panel::SetSize(this: this->m_pScrollBar, wide: v3, tall: v4);
    this->m_pScrollBar->SetRangeWindow(this: this->m_pScrollBar, a2: ctall);
    this->m_pScrollBar->SetRange(this: this->m_pScrollBar, a2: 0, a3: this->m_iContentHeight);
    this->m_pScrollBar->InvalidateLayout(this: this->m_pScrollBar, a2: false, a3: false);
    this->m_pScrollBar->Repaint(this: this->m_pScrollBar);
    vgui::SectionedListPanel::LayoutPanels(this, contentTall: &this->m_iContentHeight);
  }
  else
  {
    this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: 0);
    this->m_pScrollBar->SetVisible(this: this->m_pScrollBar, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458DF0
// Name: public: virtual void vgui::SectionedListPanel::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::GetContentSize(vgui::SectionedListPanel *this, int *wide, int *tall)
{
  if ( this->IsLayoutInvalid(this) )
  {
    if ( this->m_bSortNeeded )
    {
      vgui::SectionedListPanel::ReSortList(this);
      this->m_bSortNeeded = false;
    }
    vgui::SectionedListPanel::LayoutPanels(this, contentTall: &this->m_iContentHeight);
  }
  *wide = vgui::Panel::GetWide(this);
  *tall = this->m_iContentHeight;
}

//------------------------------------------------------------------------------
// Address: 0x00458EB0
// Name: public: virtual bool vgui::SectionedListPanel::AddColumnToSection(int,char const __near *,wchar_t const __near *,int,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::AddColumnToSection(
        vgui::SectionedListPanel *this,
        int sectionID,
        char *columnName,
        const wchar_t *columnText,
        int columnFlags,
        int width,
        unsigned int fallbackFont)
{
  int m_Size; // edx
  int v8; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  int m_szColumnName; // esi

  m_Size = this->m_Sections.m_Size;
  v8 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v8 >= m_Size )
      return 0;
  }
  if ( v8 < 0 )
    return 0;
  m_szColumnName = (int)m_pMemory[v8].m_Columns.m_Memory.m_pMemory[CUtlVector<vgui::SectionedListPanel::column_t,CUtlMemory<vgui::SectionedListPanel::column_t,int>>::AddToTail(this: &m_pMemory[v8].m_Columns)].m_szColumnName;
  V_strncpy(pDest: (char *)m_szColumnName, pSrc: columnName, maxLen: 32);
  wcsncpy(dest: (unsigned __int16 *)(m_szColumnName + 32), source: columnText, count: 0x40u);
  *(_WORD *)(m_szColumnName + 158) = 0;
  *(_DWORD *)(m_szColumnName + 164) = width;
  *(_DWORD *)(m_szColumnName + 160) = columnFlags;
  *(_DWORD *)(m_szColumnName + 168) = fallbackFont;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00458F60
// Name: public: virtual bool vgui::SectionedListPanel::RemoveItem(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::RemoveItem(vgui::SectionedListPanel *this, int itemID)
{
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *p_m_Items; // esi
  int v3; // edi
  int v4; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // ecx

  p_m_Items = (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Items;
  if ( itemID < 0 )
    return 0;
  if ( itemID >= this->m_Items.m_Memory.m_nAllocationCount )
    return 0;
  if ( itemID > this->m_Items.m_LastAlloc.index )
    return 0;
  v3 = itemID;
  v4 = (int)&p_m_Items->m_Memory.m_pMemory[itemID];
  if ( *(_DWORD *)(v4 + 4) == itemID && *(_DWORD *)(v4 + 8) != itemID )
    return 0;
  CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_SortedItems,
    src: &p_m_Items->m_Memory.m_pMemory[v3].m_Element);
  m_pMemory = p_m_Items->m_Memory.m_pMemory;
  this->m_bSortNeeded = true;
  m_pMemory[v3].m_Element->MarkForDeletion(this: m_pMemory[v3].m_Element);
  CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
    this: p_m_Items,
    elem: itemID);
  p_m_Items->m_Memory.m_pMemory[v3].m_Next = p_m_Items->m_FirstFree;
  p_m_Items->m_FirstFree = itemID;
  this->InvalidateLayout(this, a2: false, a3: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00459080
// Name: public: virtual void vgui::SectionedListPanel::DeleteAllItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::DeleteAllItems(vgui::SectionedListPanel *this)
{
  vgui::SectionedListPanel *v1; // esi
  int m_Head; // edi
  CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int> > *p_m_FreeItems; // ebx
  unsigned int v4; // edi
  vgui::CItemButton *m_Element; // esi
  void (__thiscall *SetPaintBackgroundEnabled)(vgui::Panel *, bool); // eax
  int v7; // eax
  int v8; // esi
  int v9; // ecx
  int m_Tail; // eax

  v1 = this;
  m_Head = this->m_Items.m_Head;
  if ( m_Head != -1 )
  {
    p_m_FreeItems = &this->m_FreeItems;
    do
    {
      v4 = m_Head;
      v1->m_Items.m_Memory.m_pMemory[v4].m_Element->SetVisible(
        this: v1->m_Items.m_Memory.m_pMemory[v4].m_Element,
        a2: false);
      m_Element = v1->m_Items.m_Memory.m_pMemory[v4].m_Element;
      SetPaintBackgroundEnabled = m_Element->SetPaintBackgroundEnabled;
      *(_WORD *)&m_Element->m_bSelected = 0;
      m_Element->m_iSectionID = -1;
      SetPaintBackgroundEnabled(this: m_Element, a2: false);
      m_Element->SetTextImageIndex(this: m_Element, a2: -1);
      m_Element->ClearImages(this: m_Element);
      v7 = CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int>>::AllocInternal(
             this: p_m_FreeItems,
             multilist: false);
      v8 = v7;
      if ( v7 == -1 )
      {
        v8 = -1;
      }
      else
      {
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
          this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)p_m_FreeItems,
          elem: v7);
        v9 = (int)&p_m_FreeItems->m_Memory.m_pMemory[v8];
        *(_DWORD *)(v9 + 8) = -1;
        m_Tail = p_m_FreeItems->m_Tail;
        *(_DWORD *)(v9 + 4) = m_Tail;
        p_m_FreeItems->m_Tail = v8;
        if ( m_Tail == -1 )
          p_m_FreeItems->m_Head = v8;
        else
          p_m_FreeItems->m_Memory.m_pMemory[m_Tail].m_Next = v8;
        ++p_m_FreeItems->m_ElementCount;
      }
      p_m_FreeItems->m_Memory.m_pMemory[v8].m_Element = this->m_Items.m_Memory.m_pMemory[v4].m_Element;
      m_Head = this->m_Items.m_Memory.m_pMemory[v4].m_Next;
      v1 = this;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&v1->m_Items);
  v1->m_SortedItems.m_Size = 0;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &v1->m_hSelectedItem, pPanel: nullptr);
  v1->InvalidateLayout(this: v1, a2: false, a3: false);
  v1->m_bSortNeeded = true;
}

//------------------------------------------------------------------------------
// Address: 0x004591C0
// Name: private: int vgui::SectionedListPanel::GetNewItemButton(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetNewItemButton(vgui::SectionedListPanel *this)
{
  int v2; // eax
  int v3; // edi
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v4; // ecx
  int m_Tail; // eax
  int m_Head; // esi
  vgui::CItemButton *v8; // eax
  vgui::CItemButton *v9; // [esp+10h] [ebp-4h]

  v2 = CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int>>::AllocInternal(
         this: &this->m_Items,
         multilist: false);
  v3 = v2;
  if ( v2 == -1 )
  {
    v3 = -1;
  }
  else
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Items,
      elem: v2);
    v4 = &this->m_Items.m_Memory.m_pMemory[v3];
    v4->m_Next = -1;
    m_Tail = this->m_Items.m_Tail;
    v4->m_Previous = m_Tail;
    this->m_Items.m_Tail = v3;
    if ( m_Tail == -1 )
      this->m_Items.m_Head = v3;
    else
      this->m_Items.m_Memory.m_pMemory[m_Tail].m_Next = v3;
    ++this->m_Items.m_ElementCount;
  }
  if ( this->m_FreeItems.m_ElementCount != 0 )
  {
    this->m_Items.m_Memory.m_pMemory[v3].m_Element = this->m_FreeItems.m_Memory.m_pMemory[this->m_FreeItems.m_Head].m_Element;
    this->m_Items.m_Memory.m_pMemory[v3].m_Element->m_iID = v3;
    this->m_Items.m_Memory.m_pMemory[v3].m_Element->SetVisible(
      this: this->m_Items.m_Memory.m_pMemory[v3].m_Element,
      a2: true);
    m_Head = this->m_FreeItems.m_Head;
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_FreeItems,
      elem: m_Head);
    this->m_FreeItems.m_Memory.m_pMemory[m_Head].m_Next = this->m_FreeItems.m_FirstFree;
    this->m_FreeItems.m_FirstFree = m_Head;
    return v3;
  }
  else
  {
    v8 = (vgui::CItemButton *)operator new(nSize: 0x1ECu);
    if ( v8 != nullptr )
    {
      v9 = vgui::CItemButton::CItemButton(this: v8, parent: this, itemID: v3);
      vgui::Panel::MakeReadyForUse(this: v9);
    }
    else
    {
      v9 = nullptr;
      vgui::Panel::MakeReadyForUse(this: nullptr);
    }
    this->m_Items.m_Memory.m_pMemory[v3].m_Element = v9;
    this->m_Items.m_Memory.m_pMemory[v3].m_Element->m_bShowColumns = this->m_bShowColumns;
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004593D0
// Name: public: virtual void vgui::SectionedListPanel::RemoveAllSections(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::RemoveAllSections(vgui::SectionedListPanel *this)
{
  int m_Size; // eax
  int v3; // edi
  int v4; // ebx
  vgui::CSectionHeader *m_pHeader; // ecx
  vgui::CSectionHeader *v6; // ecx

  m_Size = this->m_Sections.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    v4 = 0;
    do
    {
      if ( v3 >= 0 && v3 < m_Size )
      {
        m_pHeader = this->m_Sections.m_Memory.m_pMemory[v4].m_pHeader;
        m_pHeader->SetVisible(this: m_pHeader, a2: false);
        v6 = this->m_Sections.m_Memory.m_pMemory[v4].m_pHeader;
        v6->MarkForDeletion(this: v6);
      }
      m_Size = this->m_Sections.m_Size;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::RemoveAll(this: &this->m_Sections);
  CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::RemoveAll(this: &this->m_Sections);
  if ( this->m_Sections.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Sections.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Sections.m_Memory.m_pMemory);
      this->m_Sections.m_Memory.m_pMemory = nullptr;
    }
    this->m_Sections.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Sections.m_pElements = this->m_Sections.m_Memory.m_pMemory;
  this->m_SortedItems.m_Size = 0;
  this->InvalidateLayout(this, a2: false, a3: false);
  vgui::SectionedListPanel::ReSortList(this);
}

//------------------------------------------------------------------------------
// Address: 0x004594A0
// Name: public: virtual int vgui::SectionedListPanel::AddItem(int,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::AddItem(vgui::SectionedListPanel *this, int sectionID, const KeyValues *data)
{
  int NewItemButton; // edi

  NewItemButton = vgui::SectionedListPanel::GetNewItemButton(this);
  this->ModifyItem(this, a2: NewItemButton, a3: sectionID, a4: data);
  CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int>>::InsertBefore(
    this: &this->m_SortedItems,
    elem: this->m_SortedItems.m_Size,
    src: &this->m_Items.m_Memory.m_pMemory[NewItemButton].m_Element);
  this->m_bSortNeeded = true;
  return NewItemButton;
}

//------------------------------------------------------------------------------
// Address: 0x00459560
// Name: public: vgui::SectionedListPanel::SectionedListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::SectionedListPanel *__thiscall vgui::SectionedListPanel::SectionedListPanel(
        vgui::SectionedListPanel *this,
        vgui::Panel *parent,
        char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // edx
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v8; // ecx
  vgui::ScrollBar *v9; // eax
  vgui::ScrollBar *v10; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::SectionedListPanel_vtbl *)&vgui::SectionedListPanel::`vftable';
  if ( `vgui::SectionedListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SectionedListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "SectionedListPanel");
    v4->pfnClassName = vgui::SectionedListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::SectionedListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SectionedListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "SectionedListPanel");
    v5->pfnClassName = vgui::SectionedListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::SectionedListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SectionedListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "SectionedListPanel");
    v6->pfnClassName = vgui::SectionedListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::SectionedListPanel::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  this->m_hSelectedItem.m_iPanelID = -1;
  this->m_Sections.m_Memory.m_pMemory = nullptr;
  this->m_Sections.m_Memory.m_nAllocationCount = 0;
  this->m_Sections.m_Memory.m_nGrowSize = 0;
  this->m_Sections.m_Size = 0;
  this->m_Sections.m_pElements = nullptr;
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_LastAlloc.index = -1;
  m_pMemory = this->m_Items.m_Memory.m_pMemory;
  this->m_Items.m_Head = -1;
  this->m_Items.m_Tail = -1;
  this->m_Items.m_FirstFree = -1;
  this->m_Items.m_ElementCount = 0;
  this->m_Items.m_NumAlloced = 0;
  this->m_Items.m_pElements = m_pMemory;
  this->m_FreeItems.m_Memory.m_pMemory = nullptr;
  this->m_FreeItems.m_Memory.m_nAllocationCount = 0;
  this->m_FreeItems.m_Memory.m_nGrowSize = 0;
  this->m_FreeItems.m_LastAlloc.index = -1;
  v8 = this->m_FreeItems.m_Memory.m_pMemory;
  this->m_FreeItems.m_Head = -1;
  this->m_FreeItems.m_Tail = -1;
  this->m_FreeItems.m_FirstFree = -1;
  this->m_FreeItems.m_ElementCount = 0;
  this->m_FreeItems.m_NumAlloced = 0;
  this->m_FreeItems.m_pElements = v8;
  this->m_SortedItems.m_Memory.m_pMemory = nullptr;
  this->m_SortedItems.m_Memory.m_nAllocationCount = 0;
  this->m_SortedItems.m_Memory.m_nGrowSize = 0;
  this->m_SortedItems.m_Size = 0;
  this->m_SortedItems.m_pElements = nullptr;
  this->m_hEditModePanel.m_iPanelID = -1;
  vgui::SectionedListPanel::PanelAnimationVar_m_bShowColumns::InitVar();
  v9 = (vgui::ScrollBar *)operator new(nSize: 0x17Cu);
  if ( v9 != nullptr )
    v10 = vgui::ScrollBar::ScrollBar(this: v9, parent: this, panelName: "SectionedScrollBar", vertical: true);
  else
    v10 = nullptr;
  this->m_pScrollBar = v10;
  v10->SetVisible(this: v10, a2: false);
  this->m_pScrollBar->AddActionSignalTarget_2(this: this->m_pScrollBar, a2: this);
  this->m_iEditModeItemID = 0;
  this->m_iEditModeColumn = 0;
  this->m_pImageList = nullptr;
  this->m_bDeleteImageListWhenDone = false;
  this->m_hHeaderFont = 0;
  this->m_hRowFont = 0;
  this->m_iLineSpacing = 20;
  *(_DWORD *)&this->m_bSortNeeded = 16843008;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00459780
// Name: public: virtual void vgui::SectionedListPanel::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::RemoveAll(vgui::SectionedListPanel *this)
{
  this->DeleteAllItems(this);
}

//------------------------------------------------------------------------------
// Address: 0x00459790
// Name: public: virtual int vgui::SectionedListPanel::GetLineSpacing(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetLineSpacing(vgui::SectionedListPanel *this)
{
  return this->m_iLineSpacing;
}

//------------------------------------------------------------------------------
// Address: 0x004597A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SectionedListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SectionedListPanel::GetMessageMap(vgui::SectionedListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SectionedListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SectionedListPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::SectionedListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SectionedListPanel");
  `vgui::SectionedListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004597D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::SectionedListPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SectionedListPanel::GetAnimMap(vgui::SectionedListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "SectionedListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004597E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SectionedListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SectionedListPanel::GetKBMap(vgui::SectionedListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SectionedListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SectionedListPanel::GetKBMap'::`2'::s_pMap;
  `vgui::SectionedListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SectionedListPanel");
  `vgui::SectionedListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00459810
// Name: public: virtual vgui::SectionedListPanel::~SectionedListPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::~SectionedListPanel(vgui::SectionedListPanel *this)
{
  this->__vftable = (vgui::SectionedListPanel_vtbl *)&vgui::SectionedListPanel::`vftable';
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SortedItems);
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_FreeItems);
  if ( this->m_FreeItems.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FreeItems.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FreeItems.m_Memory.m_pMemory);
      this->m_FreeItems.m_Memory.m_pMemory = nullptr;
    }
    this->m_FreeItems.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Items);
  if ( this->m_Items.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Items.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Items.m_Memory.m_pMemory);
      this->m_Items.m_Memory.m_pMemory = nullptr;
    }
    this->m_Items.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::~CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>(this: &this->m_Sections);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004598C0
// Name: public: virtual void vgui::SectionedListPanel::AddSection(int,char const __near *,bool (*)(class vgui::SectionedListPanel __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::AddSection(
        vgui::SectionedListPanel *this,
        int sectionID,
        char *name,
        bool (__cdecl *sortFunc)(vgui::SectionedListPanel *, int, int))
{
  vgui::CSectionHeader *v5; // eax
  vgui::CSectionHeader *v6; // edi
  int v7; // eax

  v5 = (vgui::CSectionHeader *)operator new(nSize: 0x1B4u);
  if ( v5 != nullptr )
    v6 = vgui::CSectionHeader::CSectionHeader(this: v5, parent: this, name, sectionID);
  else
    v6 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v6);
  v7 = CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::InsertBefore(
         this: &this->m_Sections,
         elem: this->m_Sections.m_Size);
  this->m_Sections.m_Memory.m_pMemory[v7].m_iID = sectionID;
  this->m_Sections.m_Memory.m_pMemory[v7].m_pHeader = v6;
  this->m_Sections.m_Memory.m_pMemory[v7].m_pSortFunc = sortFunc;
  this->m_Sections.m_Memory.m_pMemory[v7].m_bAlwaysVisible = false;
}

//------------------------------------------------------------------------------
// Address: 0x00459950
// Name: public: virtual void vgui::SectionedListPanel::AddSection(int,wchar_t const __near *,bool (*)(class vgui::SectionedListPanel __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::AddSection(
        vgui::SectionedListPanel *this,
        int sectionID,
        const wchar_t *name,
        bool (__cdecl *sortFunc)(vgui::SectionedListPanel *, int, int))
{
  vgui::CSectionHeader *v5; // eax
  vgui::CSectionHeader *v6; // edi
  int v7; // eax

  v5 = (vgui::CSectionHeader *)operator new(nSize: 0x1B4u);
  if ( v5 != nullptr )
    v6 = vgui::CSectionHeader::CSectionHeader(this: v5, parent: this, name, sectionID);
  else
    v6 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v6);
  v7 = CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::InsertBefore(
         this: &this->m_Sections,
         elem: this->m_Sections.m_Size);
  this->m_Sections.m_Memory.m_pMemory[v7].m_iID = sectionID;
  this->m_Sections.m_Memory.m_pMemory[v7].m_pHeader = v6;
  this->m_Sections.m_Memory.m_pMemory[v7].m_pSortFunc = sortFunc;
  this->m_Sections.m_Memory.m_pMemory[v7].m_bAlwaysVisible = false;
}

//------------------------------------------------------------------------------
// Address: 0x004599E0
// Name: Create_SectionedListPanel
// Source: json
//------------------------------------------------------------------------------
vgui::SectionedListPanel *__cdecl Create_SectionedListPanel()
{
  vgui::SectionedListPanel *v0; // eax

  v0 = (vgui::SectionedListPanel *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::SectionedListPanel::SectionedListPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1039BD80
// Name: public: virtual void vgui::CItemButton::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::OnKillFocus(vgui::CItemButton *this)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  CHudScope::LevelInit((vgui::TextEntry *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103ADAE0
// Name: public: virtual bool vgui::SectionedListPanel::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::SectionedListPanel::IsItemIDValid(vgui::SectionedListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // ecx
  bool v3; // zf
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v4; // ecx
  bool result; // al

  result = false;
  if ( itemID >= 0 && itemID < this->m_Items.m_Memory.m_nAllocationCount && itemID <= this->m_Items.m_LastAlloc.index )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    v3 = m_pMemory[itemID].m_Previous == itemID;
    v4 = &m_pMemory[itemID];
    if ( !v3 || v4->m_Next == itemID )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C7A40
// Name: private: static void __near * vgui::SectionedListPanel::GetVar_m_bShowColumns(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl vgui::SectionedListPanel::GetVar_m_bShowColumns(vgui::Panel *panel)
{
  return (char *)&panel[1] + 173;
}

//------------------------------------------------------------------------------
// Address: 0x103C7A50
// Name: public: static char const __near * vgui::CSectionHeader::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CSectionHeader::GetPanelClassName()
{
  return "CSectionHeader";
}

//------------------------------------------------------------------------------
// Address: 0x103C7A60
// Name: public: static char const __near * vgui::CItemButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CItemButton::GetPanelClassName()
{
  return "CItemButton";
}

//------------------------------------------------------------------------------
// Address: 0x103C7A70
// Name: public: void vgui::CItemButton::GetCellBounds(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::GetCellBounds(vgui::CItemButton *this, int column, int *xpos, int *columnWide)
{
  int v5; // edi
  int v6; // ebx
  vgui::IImage *v7; // eax
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int colCount; // [esp+Ch] [ebp-8h]
  int wide; // [esp+10h] [ebp-4h] BYREF

  *xpos = 0;
  *columnWide = 0;
  v5 = 0;
  colCount = this->m_pListPanel->GetColumnCountBySection(this: this->m_pListPanel, a2: this->m_iSectionID);
  if ( colCount > 0 )
  {
    do
    {
      v6 = this->m_pListPanel->GetColumnWidthBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v5);
      v7 = this->GetImageAtIndex(this, a2: v5);
      if ( v7 != nullptr )
      {
        v7->GetContentSize(this: v7, a2: &wide, a3: &tall);
        if ( v6 < 0 )
          v6 = wide;
        else
          wide = v6;
        if ( v5 == column )
        {
          *columnWide = v6;
          return;
        }
        *xpos += v6;
      }
      ++v5;
    }
    while ( v5 < colCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C7B20
// Name: public: void vgui::CItemButton::GetMaxCellBounds(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::GetMaxCellBounds(vgui::CItemButton *this, int column, int *xpos, int *columnWide)
{
  int v6; // esi
  int v7; // eax
  int colCount; // [esp+18h] [ebp+Ch]

  *xpos = 0;
  *columnWide = 0;
  v6 = 0;
  colCount = this->m_pListPanel->GetColumnCountBySection(this: this->m_pListPanel, a2: this->m_iSectionID);
  if ( colCount > 0 )
  {
    while ( 1 )
    {
      v7 = this->m_pListPanel->GetColumnWidthBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v6);
      if ( v6 == column )
        break;
      *xpos += v7;
      if ( ++v6 >= colCount )
        return;
    }
    *columnWide = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C7BA0
// Name: protected: virtual void vgui::SectionedListPanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::SectionedListPanel::ApplySettings(
        vgui::SectionedListPanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  int Int; // eax
  vgui::ISchemeManager *v5; // edi
  vgui::ISchemeManager_vtbl *v6; // ebx
  int v7; // eax

  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "linespacing", defaultValue: 0);
  this->m_iLineSpacing = Int;
  if ( Int == 0 )
    this->m_iLineSpacing = 20;
  if ( this->IsProportional(this) )
  {
    v5 = g_pVGuiSchemeManager;
    v6 = g_pVGuiSchemeManager->__vftable;
    v7 = ((int (__thiscall *)(vgui::SectionedListPanel *, int))this->GetScheme)(a1: this, a2: this->m_iLineSpacing);
    this->m_iLineSpacing = ((int (__thiscall *)(vgui::ISchemeManager *, int))v6->GetProportionalScaledValueEx)(
                             a1: v5,
                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C7C10
// Name: public: virtual void vgui::SectionedListPanel::SetVerticalScrollbar(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetVerticalScrollbar(vgui::SectionedListPanel *this, bool state)
{
  this->m_bVerticalScrollbarEnabled = state;
}

//------------------------------------------------------------------------------
// Address: 0x103C7C20
// Name: public: virtual bool vgui::SectionedListPanel::AddColumnToSection(int,char const __near *,char const __near *,int,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::SectionedListPanel::AddColumnToSection(
        vgui::SectionedListPanel *this,
        int sectionID,
        const char *columnName,
        const char *columnText,
        int columnFlags,
        int width,
        unsigned int fallbackFont)
{
  wchar_t *v8; // eax
  wchar_t wtext[64]; // [esp+8h] [ebp-80h] BYREF

  v8 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: columnText);
  if ( v8 == nullptr )
  {
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: columnText, a3: wtext, a4: 128);
    v8 = wtext;
  }
  return this->AddColumnToSection(
           this,
           a2: sectionID,
           a3: columnName,
           a4: v8,
           a5: columnFlags,
           a6: width,
           a7: fallbackFont);
}

//------------------------------------------------------------------------------
// Address: 0x103C7C90
// Name: protected: virtual void vgui::SectionedListPanel::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::OnMouseWheeled(vgui::SectionedListPanel *this, int delta)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  int v5; // eax

  if ( vgui::PHandle::Get(this: &this->m_hEditModePanel) != nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: "MouseWheeled", firstKey: "delta", firstValue: delta);
      vgui::Panel::CallParentFunction(this, message: v4);
    }
    else
    {
      vgui::Panel::CallParentFunction(this, message: nullptr);
    }
  }
  else
  {
    v5 = this->m_pScrollBar->GetValue(this: this->m_pScrollBar);
    this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: v5 - 60 * delta);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C7D20
// Name: protected: virtual void vgui::SectionedListPanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::OnSizeChanged(vgui::SectionedListPanel *this, int wide, int tall)
{
  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C7D70
// Name: protected: virtual void vgui::SectionedListPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::OnMousePressed(vgui::SectionedListPanel *this, ButtonCode_t code)
{
  if ( this->m_clickable )
    this->ClearSelection(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C7D90
// Name: public: virtual void vgui::SectionedListPanel::EnterEditMode(int,int,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::EnterEditMode(
        vgui::SectionedListPanel *this,
        int itemID,
        int column,
        vgui::Panel *editPanel)
{
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hEditModePanel, pPanel: editPanel);
  this->m_iEditModeItemID = itemID;
  this->m_iEditModeColumn = column;
  editPanel->SetParent_2(this: editPanel, a2: this);
  editPanel->SetVisible(this: editPanel, a2: true);
  editPanel->RequestFocus(this: editPanel, a2: 0);
  editPanel->MoveToFront(this: editPanel);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103C7E00
// Name: public: virtual void vgui::SectionedListPanel::LeaveEditMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::LeaveEditMode(vgui::SectionedListPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax

  if ( vgui::PHandle::Get(this: &this->m_hEditModePanel) != nullptr )
  {
    this->InvalidateItem(this, a2: this->m_iEditModeItemID);
    v2 = vgui::PHandle::Get(this: &this->m_hEditModePanel);
    v2->SetVisible(this: v2, a2: false);
    v3 = vgui::PHandle::Get(this: &this->m_hEditModePanel);
    v3->SetParent_2(this: v3, a2: nullptr);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hEditModePanel, pPanel: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C7E70
// Name: public: virtual bool vgui::SectionedListPanel::IsInEditMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::SectionedListPanel::IsInEditMode(vgui::SectionedListPanel *this)
{
  return vgui::PHandle::Get(this: &this->m_hEditModePanel) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C7E90
// Name: public: virtual void vgui::SectionedListPanel::SetImageList(class vgui::ImageList __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetImageList(
        vgui::SectionedListPanel *this,
        vgui::ImageList *imageList,
        bool deleteImageListWhenDone)
{
  this->m_bDeleteImageListWhenDone = deleteImageListWhenDone;
  this->m_pImageList = imageList;
}

//------------------------------------------------------------------------------
// Address: 0x103C7EC0
// Name: public: vgui::CSectionHeader::CSectionHeader(class vgui::SectionedListPanel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
vgui::CSectionHeader *__thiscall vgui::CSectionHeader::CSectionHeader(
        vgui::CSectionHeader *this,
        vgui::SectionedListPanel *parent,
        const char *name,
        int sectionID)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Label::Label(this, parent, panelName: name, text: prType);
  this->__vftable = (vgui::CSectionHeader_vtbl *)&vgui::CSectionHeader::`vftable';
  if ( `vgui::CSectionHeader::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSectionHeader");
    v5->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::CSectionHeader::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSectionHeader");
    v6->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::CSectionHeader::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSectionHeader");
    v7->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_SectionDividerColor = 0;
  this->m_pListPanel = parent;
  this->m_iSectionID = sectionID;
  vgui::Label::SetTextImageIndex(this, newIndex: -1);
  vgui::Label::ClearImages(this);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C7FC0
// Name: public: virtual void vgui::CSectionHeader::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CSectionHeader::Paint(vgui::CSectionHeader *this)
{
  Color m_SectionDividerColor; // eax
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  int v5; // eax
  int v6; // [esp-4h] [ebp-20h]
  int x; // [esp+Ch] [ebp-10h] BYREF
  int wide; // [esp+10h] [ebp-Ch] BYREF
  int tall; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  vgui::Label::Paint(this);
  vgui::Panel::GetBounds(this, &x, &y, &wide, &tall);
  m_SectionDividerColor = this->m_SectionDividerColor;
  y = tall - 2;
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: m_SectionDividerColor);
  v3 = g_pVGuiSurface;
  v4 = g_pVGuiSurface->__vftable;
  v6 = y + 1;
  v5 = vgui::Panel::GetWide(this);
  v4->DrawFilledRect(this: v3, a2: 1, a3: y, a4: v5 - 2, a5: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103C8030
// Name: public: virtual void vgui::CSectionHeader::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CSectionHeader::PerformLayout(vgui::CSectionHeader *this)
{
  int v2; // edi
  int (__thiscall *GetImageCount)(vgui::Label *); // eax
  int v4; // ebx
  vgui::IImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *v7; // ebx
  vgui::TextImage_vtbl *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // eax
  vgui::TextImage_vtbl *v11; // edi
  Color *v12; // eax
  int v13; // ebx
  int v14; // eax
  vgui::SectionedListPanel *m_pListPanel; // ecx
  int m_iSectionID; // edx
  int v17; // eax
  vgui::CSectionHeader_vtbl *v18; // edx
  int v19; // eax
  vgui::TextImage *v20; // edi
  int v21; // eax
  int v22; // ecx
  int v23; // ebx
  vgui::IImage *v24; // eax
  int v25; // eax
  void (__thiscall *SetImageBounds)(vgui::Label *, int, int, int); // edx
  vgui::TextImage_vtbl *v27; // ebx
  unsigned int v28; // eax
  vgui::TextImage_vtbl *v29; // ebx
  int v30; // eax
  int tall; // [esp+Ch] [ebp-34h] BYREF
  int v32; // [esp+10h] [ebp-30h] BYREF
  int itall; // [esp+14h] [ebp-2Ch] BYREF
  int i; // [esp+18h] [ebp-28h]
  int columnFlags; // [esp+1Ch] [ebp-24h]
  int columnWidth; // [esp+20h] [ebp-20h]
  int contentWide; // [esp+24h] [ebp-1Ch]
  int iwide; // [esp+28h] [ebp-18h] BYREF
  int wide; // [esp+2Ch] [ebp-14h] BYREF
  int maxWidth; // [esp+30h] [ebp-10h]
  int colCount; // [esp+34h] [ebp-Ch]
  int v42; // [esp+38h] [ebp-8h]
  int xpos; // [esp+3Ch] [ebp-4h]

  vgui::Label::PerformLayout(this);
  v2 = this->m_pListPanel->GetColumnCountBySection(this: this->m_pListPanel, a2: this->m_iSectionID);
  GetImageCount = this->GetImageCount;
  colCount = v2;
  if ( v2 != GetImageCount(this) )
  {
    v4 = 0;
    for ( maxWidth = 0; v4 < v2; maxWidth = v4 )
    {
      if ( (this->m_pListPanel->GetColumnFlagsBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v4) & 1) != 0 )
      {
        v5 = nullptr;
      }
      else
      {
        v6 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
        if ( v6 != nullptr )
          v7 = vgui::TextImage::TextImage(this: v6, text: prType);
        else
          v7 = nullptr;
        v8 = v7->__vftable;
        v9 = this->GetFont(this);
        v8->SetFont(this: v7, a2: v9);
        v10 = this->m_pListPanel->GetColumnFallbackFontBySection(
                this: this->m_pListPanel,
                a2: this->m_iSectionID,
                a3: maxWidth);
        if ( v10 != 0 )
          vgui::TextImage::SetUseFallbackFont(this: v7, bState: true, hFallback: v10);
        v11 = v7->__vftable;
        v12 = this->GetFgColor(this, result: &v32);
        v11->SetColor(this: v7, a2: *v12);
        v2 = colCount;
        v5 = v7;
        v4 = maxWidth;
      }
      this->SetImageAtIndex(this, a2: v4++, a3: v5, a4: 0);
    }
  }
  for ( i = 2; i != 0; --i )
  {
    v13 = 0;
    xpos = 0;
    v42 = 0;
    if ( v2 > 0 )
    {
      do
      {
        v14 = this->m_pListPanel->GetColumnFlagsBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v13);
        m_pListPanel = this->m_pListPanel;
        m_iSectionID = this->m_iSectionID;
        columnFlags = v14;
        v17 = m_pListPanel->GetColumnWidthBySection(this: m_pListPanel, a2: m_iSectionID, a3: v13);
        v18 = this->__vftable;
        columnWidth = v17;
        maxWidth = v17;
        v19 = (int)v18->GetImageAtIndex(this, a2: v13);
        v20 = (vgui::TextImage *)v19;
        if ( v19 != 0 )
        {
          (*(void (__thiscall **)(int, int *, int *))(*(_DWORD *)v19 + 8))(a1: v19, a2: &wide, a3: &tall);
          v21 = wide;
          v22 = columnFlags & 0x10;
          contentWide = wide;
          v32 = v22;
          if ( (columnFlags & 0x10) == 0 )
          {
            v23 = v13 + 1;
            if ( v23 < colCount )
            {
              do
              {
                iwide = 0;
                itall = 0;
                if ( this->GetImageAtIndex(this, a2: v23) != nullptr )
                {
                  v24 = this->GetImageAtIndex(this, a2: v23);
                  v24->GetContentSize(this: v24, a2: &iwide, a3: &itall);
                }
                if ( iwide == 0 )
                {
                  v25 = this->m_pListPanel->GetColumnWidthBySection(
                          this: this->m_pListPanel,
                          a2: this->m_iSectionID,
                          a3: v23);
                  maxWidth += v25;
                }
                ++v23;
              }
              while ( v23 < colCount );
              v21 = wide;
              v22 = v32;
            }
            v13 = v42;
          }
          if ( maxWidth >= 0 )
          {
            v21 = maxWidth;
            wide = maxWidth;
          }
          SetImageBounds = this->SetImageBounds;
          if ( v22 != 0 )
            SetImageBounds(this, a2: v13, a3: xpos + v21 - contentWide, a4: contentWide - 2);
          else
            SetImageBounds(this, a2: v13, a3: xpos, a4: v21 - 2);
          xpos += columnWidth;
          if ( (columnFlags & 1) == 0 )
          {
            v27 = v20->__vftable;
            v28 = this->GetFont(this);
            v27->SetFont(this: v20, a2: v28);
            v29 = v20->__vftable;
            v30 = ((int (__thiscall *)(vgui::SectionedListPanel *, int, int, _DWORD))this->m_pListPanel->GetColumnTextBySection)(
                    a1: this->m_pListPanel,
                    a2: this->m_iSectionID,
                    a3: v42,
                    a4: 0);
            ((void (__thiscall *)(vgui::TextImage *, int))v29->SetText)(a1: v20, a2: v30);
            vgui::TextImage::ResizeImageToContentMaxWidth(this: v20, nMaxWidth: maxWidth);
            v13 = v42;
          }
        }
        else
        {
          xpos += columnWidth;
        }
        v42 = ++v13;
      }
      while ( v13 < colCount );
      v2 = colCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8300
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CSectionHeader::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CSectionHeader::GetMessageMap(vgui::CSectionHeader *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CSectionHeader::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CSectionHeader::GetMessageMap'::`2'::s_pMap;
  `vgui::CSectionHeader::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSectionHeader");
  `vgui::CSectionHeader::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C8330
// Name: public: virtual struct PanelAnimationMap __near * vgui::CSectionHeader::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CSectionHeader::GetAnimMap(vgui::CSectionHeader *this)
{
  return FindOrAddPanelAnimationMap(className: "CSectionHeader");
}

//------------------------------------------------------------------------------
// Address: 0x103C8340
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CSectionHeader::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CSectionHeader::GetKBMap(vgui::CSectionHeader *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CSectionHeader::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CSectionHeader::GetKBMap'::`2'::s_pMap;
  `vgui::CSectionHeader::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSectionHeader");
  `vgui::CSectionHeader::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C8370
// Name: public: vgui::CSectionHeader::CSectionHeader(class vgui::SectionedListPanel __near *,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
vgui::CSectionHeader *__thiscall vgui::CSectionHeader::CSectionHeader(
        vgui::CSectionHeader *this,
        vgui::SectionedListPanel *parent,
        const wchar_t *name,
        int sectionID)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Label::Label(this, parent, panelName: "SectionHeader", text: prType);
  this->__vftable = (vgui::CSectionHeader_vtbl *)&vgui::CSectionHeader::`vftable';
  if ( `vgui::CSectionHeader::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSectionHeader");
    v5->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::CSectionHeader::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSectionHeader");
    v6->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::CSectionHeader::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CSectionHeader::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSectionHeader");
    v7->pfnClassName = vgui::CSectionHeader::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_SectionDividerColor = 0;
  vgui::Label::SetText(this, unicodeString: name, bClearUnlocalizedSymbol: false);
  vgui::Panel::SetVisible(this, state: 0);
  this->m_pListPanel = parent;
  this->m_iSectionID = sectionID;
  vgui::Label::SetTextImageIndex(this, newIndex: -1);
  vgui::Label::ClearImages(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C8480
// Name: public: virtual void vgui::CSectionHeader::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CSectionHeader::ApplySchemeSettings(vgui::CSectionHeader *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CSectionHeader_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::CSectionHeader_vtbl *v6; // ebx
  Color *v7; // eax
  _DWORD *v8; // eax
  vgui::CSectionHeader_vtbl *v9; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v11; // al
  int v12; // eax
  _BYTE v13[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "SectionedListPanel.HeaderTextColor", a4: v2);
  ((void (__thiscall *)(vgui::CSectionHeader *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  this->m_SectionDividerColor = *this->GetSchemeColor_2(
                                   this,
                                   result: &pScheme,
                                   a3: "SectionedListPanel.DividerColor",
                                   a4: v2);
  v6 = this->__vftable;
  v7 = this->GetBgColor(this, result: &pScheme);
  v8 = (_DWORD *)((int (__thiscall *)(vgui::CSectionHeader *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v6->GetSchemeColor)(
                   a1: this,
                   a2: (Color *)v13,
                   a3: "SectionedListPanelHeader.BgColor",
                   a4: *v7,
                   a5: v2);
  ((void (__thiscall *)(vgui::CSectionHeader *, _DWORD))v6->SetBgColor)(a1: this, a2: *v8);
  if ( this->m_pListPanel->m_hHeaderFont != 0 )
  {
    this->SetFont(this, a2: this->m_pListPanel->m_hHeaderFont);
  }
  else
  {
    v9 = this->__vftable;
    IsProportional = this->IsProportional;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v11 = IsProportional(this);
    v12 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v11);
    v9->SetFont(this, a2: v12);
  }
  this->ClearImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C85A0
// Name: private: void vgui::SectionedListPanel::SetSelectedItem(class vgui::CItemButton __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::SectionedListPanel::SetSelectedItem(
        vgui::SectionedListPanel *this@<ecx>,
        int a2@<esi>,
        vgui::CItemButton *item)
{
  vgui::Panel *v4; // esi
  void (__thiscall *SetPaintBackgroundEnabled)(vgui::Panel *, bool); // edx
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // esi
  void (__thiscall *v8)(vgui::Panel *, bool); // eax
  KeyValues *v9; // esi
  int v10; // eax
  KeyValues *v11; // eax
  int v12; // [esp-4h] [ebp-Ch]

  if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != item )
  {
    v12 = a2;
    if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: &this->m_hSelectedItem);
      if ( LOBYTE(v4[1].m_nResizeDeltaX) != 0 )
      {
        SetPaintBackgroundEnabled = v4->SetPaintBackgroundEnabled;
        LOBYTE(v4[1].m_nResizeDeltaX) = 0;
        SetPaintBackgroundEnabled(this: v4, a2: false);
        v4->InvalidateLayout(this: v4, a2: false, a3: false);
        ((void (__thiscall *)(vgui::Panel *, int))v4->Repaint)(a1: v4, a2: v12);
      }
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hSelectedItem, pPanel: item);
    if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != nullptr )
    {
      v6 = vgui::PHandle::Get(this: &this->m_hSelectedItem);
      v7 = v6;
      if ( LOBYTE(v6[1].m_nResizeDeltaX) != 1 )
      {
        v6->RequestFocus(this: v6, a2: 0);
        v8 = v7->SetPaintBackgroundEnabled;
        LOBYTE(v7[1].m_nResizeDeltaX) = 1;
        v8(this: v7, a2: true);
        v7->InvalidateLayout(this: v7, a2: false, a3: false);
        v7->Repaint(this: v7);
      }
    }
    ((void (__thiscall *)(vgui::SectionedListPanel *, int))this->Repaint)(a1: this, a2: v12);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
    {
      if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != nullptr )
        v10 = *(_DWORD *)&vgui::PHandle::Get(this: &this->m_hSelectedItem)[1]._flags.m_nFlags;
      else
        v10 = -1;
      v11 = KeyValues::KeyValues(this: v9, setName: "ItemSelected", firstKey: "itemID", firstValue: v10);
      this->PostActionSignal(this, a2: v11);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8700
// Name: public: virtual int vgui::SectionedListPanel::GetSelectedItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetSelectedItem(vgui::SectionedListPanel *this)
{
  vgui::DHANDLE<vgui::CItemButton> *p_m_hSelectedItem; // esi

  p_m_hSelectedItem = &this->m_hSelectedItem;
  if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != nullptr )
    return *(_DWORD *)&vgui::PHandle::Get(this: p_m_hSelectedItem)[1]._flags.m_nFlags;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103C8730
// Name: public: virtual int vgui::SectionedListPanel::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetItemCount(vgui::SectionedListPanel *this)
{
  return this->m_SortedItems.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103C8740
// Name: protected: virtual void vgui::SectionedListPanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::OnSetFocus(vgui::SectionedListPanel *this)
{
  vgui::Panel *v2; // eax

  if ( vgui::PHandle::Get(this: &this->m_hSelectedItem) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hSelectedItem);
    v2->RequestFocus(this: v2, a2: 0);
  }
  else
  {
    CHudScope::LevelInit((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8780
// Name: public: void CUtlMemory<struct vgui::SectionedListPanel::column_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::SectionedListPanel::column_t,int>::Grow(
        CUtlMemory<vgui::SectionedListPanel::column_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::SectionedListPanel::column_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 172 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::SectionedListPanel::column_t *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: v7);
    else
      this->m_pMemory = (vgui::SectionedListPanel::column_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8820
// Name: public: virtual void vgui::SectionedListPanel::SetItemFgColor(int,class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetItemFgColor(vgui::SectionedListPanel *this, int itemID, Color color)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // ecx
  int v5; // esi

  if ( itemID >= 0 && itemID < this->m_Items.m_Memory.m_nAllocationCount && itemID <= this->m_Items.m_LastAlloc.index )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    v5 = itemID;
    if ( m_pMemory[itemID].m_Previous != itemID || m_pMemory[v5].m_Next == itemID )
    {
      m_pMemory[v5].m_Element->SetFgColor(this: m_pMemory[v5].m_Element, a2: color);
      this->m_Items.m_Memory.m_pMemory[v5].m_Element->SetOverrideColors(
        this: this->m_Items.m_Memory.m_pMemory[v5].m_Element,
        a2: true);
      this->m_Items.m_Memory.m_pMemory[v5].m_Element->InvalidateLayout(
        this: this->m_Items.m_Memory.m_pMemory[v5].m_Element,
        a2: false,
        a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C88A0
// Name: public: virtual void vgui::SectionedListPanel::SetItemBgColor(int,class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetItemBgColor(vgui::SectionedListPanel *this, int itemID, Color color)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // ecx
  int v5; // esi

  if ( itemID >= 0 && itemID < this->m_Items.m_Memory.m_nAllocationCount && itemID <= this->m_Items.m_LastAlloc.index )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    v5 = itemID;
    if ( m_pMemory[itemID].m_Previous != itemID || m_pMemory[v5].m_Next == itemID )
    {
      m_pMemory[v5].m_Element->SetBgColor(this: m_pMemory[v5].m_Element, a2: color);
      this->m_Items.m_Memory.m_pMemory[v5].m_Element->SetPaintBackgroundEnabled(
        this: this->m_Items.m_Memory.m_pMemory[v5].m_Element,
        a2: true);
      this->m_Items.m_Memory.m_pMemory[v5].m_Element->SetOverrideColors(
        this: this->m_Items.m_Memory.m_pMemory[v5].m_Element,
        a2: true);
      this->m_Items.m_Memory.m_pMemory[v5].m_Element->InvalidateLayout(
        this: this->m_Items.m_Memory.m_pMemory[v5].m_Element,
        a2: false,
        a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8930
// Name: public: virtual void vgui::SectionedListPanel::SetItemFont(int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetItemFont(vgui::SectionedListPanel *this, int itemID, unsigned int font)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // esi
  int v4; // edx

  if ( itemID >= 0 && itemID < this->m_Items.m_Memory.m_nAllocationCount && itemID <= this->m_Items.m_LastAlloc.index )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    v4 = itemID;
    if ( m_pMemory[itemID].m_Previous != itemID || m_pMemory[v4].m_Next == itemID )
      m_pMemory[v4].m_Element->SetFont(this: m_pMemory[v4].m_Element, a2: font);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8980
// Name: public: virtual void vgui::SectionedListPanel::SetSectionFgColor(int,class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetSectionFgColor(vgui::SectionedListPanel *this, int sectionID, Color color)
{
  vgui::CSectionHeader *m_pHeader; // ecx

  if ( sectionID >= 0 && sectionID < this->m_Sections.m_Size )
  {
    m_pHeader = this->m_Sections.m_Memory.m_pMemory[sectionID].m_pHeader;
    m_pHeader->m_SectionDividerColor = color;
    m_pHeader->SetFgColor(this: m_pHeader, a2: color);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C89C0
// Name: public: virtual void vgui::SectionedListPanel::SetSectionDividerColor(int,class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetSectionDividerColor(
        vgui::SectionedListPanel *this,
        int sectionID,
        Color color)
{
  if ( sectionID >= 0 && sectionID < this->m_Sections.m_Size )
    this->m_Sections.m_Memory.m_pMemory[sectionID].m_pHeader->m_SectionDividerColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x103C89F0
// Name: public: virtual void vgui::SectionedListPanel::SetSectionAlwaysVisible(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetSectionAlwaysVisible(
        vgui::SectionedListPanel *this,
        int sectionID,
        bool visible)
{
  if ( sectionID >= 0 && sectionID < this->m_Sections.m_Size )
    this->m_Sections.m_Memory.m_pMemory[sectionID].m_bAlwaysVisible = visible;
}

//------------------------------------------------------------------------------
// Address: 0x103C8A20
// Name: public: virtual void vgui::SectionedListPanel::SetFontSection(int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetFontSection(
        vgui::SectionedListPanel *this,
        int sectionID,
        unsigned int font)
{
  vgui::CSectionHeader *m_pHeader; // ecx

  if ( sectionID >= 0 && sectionID < this->m_Sections.m_Size )
  {
    m_pHeader = this->m_Sections.m_Memory.m_pMemory[sectionID].m_pHeader;
    m_pHeader->SetFont(this: m_pHeader, a2: font);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8A60
// Name: public: virtual void vgui::SectionedListPanel::ClearSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::SectionedListPanel::ClearSelection(vgui::SectionedListPanel *this@<ecx>, int a2@<esi>)
{
  vgui::SectionedListPanel::SetSelectedItem(this, a2, item: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103C8A70
// Name: public: void vgui::SectionedListPanel::MoveSelectionDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::MoveSelectionDown(vgui::SectionedListPanel *this)
{
  int v2; // eax
  int m_Size; // edx
  int v4; // ecx
  vgui::CItemButton **m_pMemory; // edi
  int m_iID; // edi

  v2 = this->GetSelectedItem(this);
  if ( v2 != -1 )
  {
    m_Size = this->m_SortedItems.m_Size;
    if ( m_Size != 0 )
    {
      v4 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_SortedItems.m_Memory.m_pMemory;
        do
        {
          if ( (*m_pMemory)->m_iID == v2 )
            break;
          ++v4;
          ++m_pMemory;
        }
        while ( v4 < m_Size );
      }
      if ( v4 < m_Size - 1 )
      {
        m_iID = this->m_SortedItems.m_Memory.m_pMemory[v4 + 1]->m_iID;
        vgui::SectionedListPanel::SetSelectedItem(
          this,
          a2: (int)this,
          item: this->m_Items.m_Memory.m_pMemory[m_iID].m_Element);
        this->ScrollToItem(this, a2: m_iID);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8AF0
// Name: public: void vgui::SectionedListPanel::MoveSelectionUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::MoveSelectionUp(vgui::SectionedListPanel *this)
{
  int v2; // eax
  int m_Size; // edi
  int v4; // ecx
  vgui::CItemButton **m_pMemory; // edx
  int m_iID; // edi

  v2 = this->GetSelectedItem(this);
  if ( v2 != -1 )
  {
    m_Size = this->m_SortedItems.m_Size;
    if ( m_Size != 0 )
    {
      v4 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_SortedItems.m_Memory.m_pMemory;
        do
        {
          if ( (*m_pMemory)->m_iID == v2 )
            break;
          ++v4;
          ++m_pMemory;
        }
        while ( v4 < m_Size );
        if ( v4 != 0 && v4 < m_Size )
        {
          m_iID = this->m_SortedItems.m_Memory.m_pMemory[v4 - 1]->m_iID;
          vgui::SectionedListPanel::SetSelectedItem(
            this,
            a2: (int)this,
            item: this->m_Items.m_Memory.m_pMemory[m_iID].m_Element);
          this->ScrollToItem(this, a2: m_iID);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8B70
// Name: public: virtual void vgui::SectionedListPanel::SetSelectedItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetSelectedItem(vgui::SectionedListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0 && itemID < this->m_Items.m_Memory.m_nAllocationCount && itemID <= this->m_Items.m_LastAlloc.index )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    v3 = itemID;
    if ( m_pMemory[itemID].m_Previous != itemID || m_pMemory[v3].m_Next == itemID )
      vgui::SectionedListPanel::SetSelectedItem(this, a2: (int)m_pMemory, item: m_pMemory[v3].m_Element);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8C10
// Name: public: virtual int vgui::SectionedListPanel::GetItemSection(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetItemSection(vgui::SectionedListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_Items.m_Memory.m_nAllocationCount
    && itemID <= this->m_Items.m_LastAlloc.index
    && ((m_pMemory = this->m_Items.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->m_iSectionID;
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8C60
// Name: public: virtual int vgui::SectionedListPanel::GetItemIDFromRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetItemIDFromRow(vgui::SectionedListPanel *this, int row)
{
  if ( row >= 0 && row < this->m_SortedItems.m_Size )
    return this->m_SortedItems.m_Memory.m_pMemory[row]->m_iID;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103C8C90
// Name: public: virtual int vgui::SectionedListPanel::GetRowFromItemID(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetRowFromItemID(vgui::SectionedListPanel *this, int itemID)
{
  int m_Size; // edx
  int result; // eax
  vgui::CItemButton **i; // ecx

  m_Size = this->m_SortedItems.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_SortedItems.m_Memory.m_pMemory; (*i)->m_iID != itemID; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C8CD0
// Name: public: virtual bool vgui::SectionedListPanel::GetCellBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::GetCellBounds(
        vgui::SectionedListPanel *this,
        int itemID,
        int column,
        int *x,
        int *y,
        int *wide,
        int *tall)
{
  vgui::CItemButton *m_Element; // esi

  *tall = 0;
  *wide = 0;
  *y = 0;
  *x = 0;
  if ( !this->IsItemIDValid(this, a2: itemID) )
    return 0;
  m_Element = this->m_Items.m_Memory.m_pMemory[itemID].m_Element;
  if ( !m_Element->IsVisible(this: m_Element) )
    return 0;
  vgui::Panel::GetBounds(this: m_Element, x, y, wide, tall);
  vgui::CItemButton::GetCellBounds(this: m_Element, column, xpos: x, columnWide: wide);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C8D60
// Name: public: virtual bool vgui::SectionedListPanel::GetMaxCellBounds(int,int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::GetMaxCellBounds(
        vgui::SectionedListPanel *this,
        int itemID,
        int column,
        int *x,
        int *y,
        int *wide,
        int *tall)
{
  vgui::CItemButton *m_Element; // esi

  *tall = 0;
  *wide = 0;
  *y = 0;
  *x = 0;
  if ( !this->IsItemIDValid(this, a2: itemID) )
    return 0;
  m_Element = this->m_Items.m_Memory.m_pMemory[itemID].m_Element;
  if ( !m_Element->IsVisible(this: m_Element) )
    return 0;
  vgui::Panel::GetBounds(this: m_Element, x, y, wide, tall);
  vgui::CItemButton::GetMaxCellBounds(this: m_Element, column, xpos: x, columnWide: wide);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C8DF0
// Name: public: virtual bool vgui::SectionedListPanel::GetItemBounds(int,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::GetItemBounds(
        vgui::SectionedListPanel *this,
        int itemID,
        int *x,
        int *y,
        int *wide,
        int *tall)
{
  vgui::CItemButton *m_Element; // esi

  *tall = 0;
  *wide = 0;
  *y = 0;
  *x = 0;
  if ( !this->IsItemIDValid(this, a2: itemID) )
    return 0;
  m_Element = this->m_Items.m_Memory.m_pMemory[itemID].m_Element;
  if ( !m_Element->IsVisible(this: m_Element) )
    return 0;
  vgui::Panel::GetBounds(this: m_Element, x, y, wide, tall);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C8E80
// Name: public: virtual void vgui::SectionedListPanel::InvalidateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::InvalidateItem(vgui::SectionedListPanel *this, int itemID)
{
  int v3; // esi

  if ( this->IsItemIDValid(this, a2: itemID) )
  {
    v3 = itemID;
    this->m_Items.m_Memory.m_pMemory[v3].m_Element->InvalidateLayout(
      this: this->m_Items.m_Memory.m_pMemory[v3].m_Element,
      a2: false,
      a3: false);
    this->m_Items.m_Memory.m_pMemory[v3].m_Element->Repaint(this: this->m_Items.m_Memory.m_pMemory[v3].m_Element);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8ED0
// Name: public: virtual unsigned long vgui::SectionedListPanel::GetColumnFallbackFontBySection(int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::SectionedListPanel::GetColumnFallbackFontBySection(
        vgui::SectionedListPanel *this,
        int sectionID,
        int columnIndex)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  int v8; // eax
  bool v9; // cc
  vgui::SectionedListPanel::section_t *v10; // eax

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 >= 0 && (v8 = v4, v9 = columnIndex < m_pMemory[v8].m_Columns.m_Size, v10 = &m_pMemory[v8], v9) )
    return v10->m_Columns.m_Memory.m_pMemory[columnIndex].m_hFallbackFont;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C90B0
// Name: public: void vgui::CItemButton::SetSectionID(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CItemButton::SetSectionID(vgui::CItemButton *this@<ecx>, int a2@<edi>, int sectionID)
{
  int i; // edi
  vgui::TextImage *v5; // ecx

  if ( sectionID != this->m_iSectionID )
  {
    ((void (__thiscall *)(vgui::CItemButton *, int))this->ClearImages)(a1: this, a2);
    for ( i = 0; i < this->m_TextImages.m_Size; ++i )
    {
      v5 = this->m_TextImages.m_Memory.m_pMemory[i];
      if ( v5 != nullptr )
        ((void (__thiscall *)(vgui::TextImage *, int))v5->dtr_IImage)(a1: v5, a2: 1);
    }
    this->m_TextImages.m_Size = 0;
    ((void (__thiscall *)(vgui::CItemButton *, _DWORD))this->InvalidateLayout)(a1: this, a2: 0);
  }
  this->m_iSectionID = sectionID;
}

//------------------------------------------------------------------------------
// Address: 0x103C9130
// Name: private: void vgui::SectionedListPanel::LayoutPanels(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::LayoutPanels(vgui::SectionedListPanel *this, int *contentTall)
{
  unsigned int v3; // eax
  int v4; // eax
  vgui::ScrollBar *m_pScrollBar; // ecx
  int v6; // edi
  bool (__thiscall *IsVisible)(vgui::Panel *); // eax
  int v8; // ebx
  vgui::SectionedListPanel::section_t *v9; // edi
  int v10; // eax
  int m_iID; // ecx
  vgui::CItemButton *v12; // edi
  vgui::Panel *v13; // eax
  int xpos; // [esp+8h] [ebp-24h] BYREF
  int cwide; // [esp+Ch] [ebp-20h] BYREF
  int sectionIndex; // [esp+10h] [ebp-1Ch]
  unsigned int v17; // [esp+14h] [ebp-18h]
  int iEnd; // [esp+18h] [ebp-14h]
  int wide; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int tall; // [esp+24h] [ebp-8h]
  int iStart; // [esp+28h] [ebp-4h]

  if ( this->m_Sections.m_Size != 0
    && (v3 = this->m_Sections.m_Memory.m_pMemory->m_pHeader->GetFont(this: this->m_Sections.m_Memory.m_pMemory->m_pHeader)) != 0 )
  {
    tall = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v3) + 7;
  }
  else
  {
    tall = 20;
  }
  v4 = vgui::Panel::GetWide(this);
  m_pScrollBar = this->m_pScrollBar;
  v6 = v4 - 10;
  IsVisible = m_pScrollBar->IsVisible;
  wide = v6;
  v8 = 5;
  if ( IsVisible(this: m_pScrollBar) )
  {
    v8 = 5 - this->m_pScrollBar->GetValue(this: this->m_pScrollBar);
    wide = v6 - vgui::Panel::GetWide(this: this->m_pScrollBar);
  }
  sectionIndex = 0;
  if ( this->m_Sections.m_Size > 0 )
  {
    v17 = 0;
    do
    {
      v9 = &this->m_Sections.m_Memory.m_pMemory[v17 / 0x24];
      iStart = -1;
      iEnd = -1;
      v10 = 0;
      if ( this->m_SortedItems.m_Size > 0 )
      {
        m_iID = v9->m_iID;
        i = (int)this->m_SortedItems.m_Memory.m_pMemory;
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)i + 432) == m_iID )
          {
            if ( iStart == -1 )
              iStart = v10;
            iEnd = v10;
          }
          i += 4;
          ++v10;
        }
        while ( v10 < this->m_SortedItems.m_Size );
        if ( iStart != -1 )
          goto LABEL_19;
      }
      if ( v9->m_bAlwaysVisible )
      {
LABEL_19:
        if ( this->m_bDrawSectionHeaders )
        {
          vgui::Panel::SetBounds(this: v9->m_pHeader, x: 5, y: v8, wide, tall);
          v9->m_pHeader->SetVisible(this: v9->m_pHeader, a2: true);
          v8 += tall;
        }
        else
        {
          v9->m_pHeader->SetVisible(this: v9->m_pHeader, a2: false);
        }
        if ( iStart != -1 || !v9->m_bAlwaysVisible )
        {
          for ( i = iStart; i <= iEnd; ++i )
          {
            v12 = this->m_SortedItems.m_Memory.m_pMemory[i];
            vgui::Panel::SetBounds(this: v12, x: 5, y: v8, wide, tall: this->m_iLineSpacing);
            if ( vgui::PHandle::Get(this: &this->m_hEditModePanel) != nullptr && this->m_iEditModeItemID == v12->m_iID )
            {
              vgui::CItemButton::GetCellBounds(this: v12, column: 1, &xpos, columnWide: &cwide);
              v13 = vgui::PHandle::Get(this: &this->m_hEditModePanel);
              vgui::Panel::SetBounds(this: v13, x: xpos, y: v8, wide: cwide, tall);
            }
            v8 += this->m_iLineSpacing;
          }
        }
        v8 += 8;
      }
      else
      {
        v9->m_pHeader->SetVisible(this: v9->m_pHeader, a2: false);
      }
      v17 += 36;
      ++sectionIndex;
    }
    while ( sectionIndex < this->m_Sections.m_Size );
  }
  *contentTall = v8;
  if ( this->m_pScrollBar->IsVisible(this: this->m_pScrollBar) )
    *contentTall += this->m_pScrollBar->GetValue(this: this->m_pScrollBar);
}

//------------------------------------------------------------------------------
// Address: 0x103C9390
// Name: public: virtual void vgui::SectionedListPanel::ScrollToItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::ScrollToItem(vgui::SectionedListPanel *this, int iItem)
{
  unsigned int v3; // eax
  int v4; // ebx
  int v5; // edi
  int x; // [esp+Ch] [ebp-18h] BYREF
  int cy; // [esp+10h] [ebp-14h] BYREF
  int cwide; // [esp+14h] [ebp-10h] BYREF
  int itemX; // [esp+18h] [ebp-Ch] BYREF
  int ctall; // [esp+1Ch] [ebp-8h] BYREF
  int itemY; // [esp+20h] [ebp-4h] BYREF

  if ( this->m_Sections.m_Size != 0
    && (v3 = this->m_Sections.m_Memory.m_pMemory->m_pHeader->GetFont(this: this->m_Sections.m_Memory.m_pMemory->m_pHeader)) != 0 )
  {
    v4 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v3) + 7;
  }
  else
  {
    v4 = 20;
  }
  v5 = this->m_pScrollBar->GetValue(this: this->m_pScrollBar);
  vgui::Panel::GetPos(this: this->m_Items.m_Memory.m_pMemory[iItem].m_Element, x: &itemX, y: &itemY);
  itemY += v5;
  vgui::Panel::GetBounds(this, &x, y: &cy, wide: &cwide, tall: &ctall);
  if ( this->m_iContentHeight <= ctall )
  {
    this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: 0);
  }
  else
  {
    if ( itemY < v5 )
    {
      this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: itemY);
      this->Repaint(this);
      return;
    }
    if ( itemY > v5 + ctall - v4 )
    {
      this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: v4 + itemY - ctall);
      this->Repaint(this);
      return;
    }
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C94B0
// Name: protected: virtual void vgui::SectionedListPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::ApplySchemeSettings(vgui::SectionedListPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::SectionedListPanel_vtbl *v4; // ebx
  Color *v5; // eax
  _DWORD *v6; // eax
  vgui::SectionedListPanel_vtbl *v7; // ebx
  int v8; // eax
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // ecx
  int v11; // eax
  _BYTE v12[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetBgColor(this, result: &pScheme);
  v6 = (_DWORD *)((int (__thiscall *)(vgui::SectionedListPanel *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
                   a1: this,
                   a2: (Color *)v12,
                   a3: "SectionedListPanel.BgColor",
                   a4: *v5,
                   a5: v2);
  ((void (__thiscall *)(vgui::SectionedListPanel *, _DWORD))v4->SetBgColor)(a1: this, a2: *v6);
  v7 = this->__vftable;
  v8 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v7->SetBorder(this, a2: (vgui::IBorder *)v8);
  m_Head = this->m_Items.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    do
    {
      v11 = m_Head;
      m_pMemory[v11].m_Element->m_bShowColumns = this->m_bShowColumns;
      m_pMemory = this->m_Items.m_Memory.m_pMemory;
      m_Head = m_pMemory[v11].m_Next;
    }
    while ( m_Head != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C9550
// Name: public: virtual void vgui::SectionedListPanel::SetProportional(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::SetProportional(vgui::SectionedListPanel *this, BOOL state)
{
  BOOL v2; // ebx
  int v4; // esi
  int v5; // ebx
  vgui::CSectionHeader *m_pHeader; // ecx
  int m_Head; // esi
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // eax
  int v9; // esi

  v2 = state;
  vgui::Panel::SetProportional(this, state);
  v4 = 0;
  if ( this->m_Sections.m_Size > 0 )
  {
    v5 = 0;
    do
    {
      m_pHeader = this->m_Sections.m_Memory.m_pMemory[v5].m_pHeader;
      m_pHeader->SetProportional(this: m_pHeader, a2: state);
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_Sections.m_Size );
    v2 = state;
  }
  m_Head = this->m_Items.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    do
    {
      v9 = m_Head;
      m_pMemory[v9].m_Element->SetProportional(this: m_pMemory[v9].m_Element, a2: v2);
      m_pMemory = this->m_Items.m_Memory.m_pMemory;
      m_Head = m_pMemory[v9].m_Next;
    }
    while ( m_Head != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C95E0
// Name: public: virtual bool vgui::SectionedListPanel::ModifyColumn(int,char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::ModifyColumn(
        vgui::SectionedListPanel *this,
        int sectionID,
        const char *columnName,
        const wchar_t *columnText)
{
  int m_Size; // edx
  int v5; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // edi
  vgui::SectionedListPanel::section_t *i; // ecx
  vgui::SectionedListPanel::section_t *v9; // edi
  int v10; // esi
  int v11; // ebx
  int m_szColumnName; // esi

  m_Size = this->m_Sections.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v5 >= m_Size )
      return 0;
  }
  if ( v5 < 0 )
    return 0;
  v9 = &m_pMemory[v5];
  v10 = 0;
  if ( v9->m_Columns.m_Size <= 0 )
    return 0;
  v11 = 0;
  do
  {
    if ( _V_stricmp(s1: v9->m_Columns.m_Memory.m_pMemory[v11].m_szColumnName, s2: columnName) == 0 )
      break;
    ++v10;
    ++v11;
  }
  while ( v10 < v9->m_Columns.m_Size );
  if ( v10 < 0 || v10 >= v9->m_Columns.m_Size )
    return 0;
  m_szColumnName = (int)v9->m_Columns.m_Memory.m_pMemory[v10].m_szColumnName;
  wcsncpy(dest: (unsigned __int16 *)(m_szColumnName + 32), source: columnText, count: 0x40u);
  *(_WORD *)(m_szColumnName + 158) = 0;
  v9->m_pHeader->InvalidateLayout(this: v9->m_pHeader, a2: false, a3: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C96A0
// Name: public: virtual bool vgui::SectionedListPanel::ModifyItem(int,int,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::SectionedListPanel::ModifyItem@<al>(
        vgui::SectionedListPanel *this@<ecx>,
        int a2@<ebx>,
        int itemID,
        int sectionID,
        KeyValues *data)
{
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // ecx
  int v7; // edi
  vgui::CItemButton *m_Element; // ebx
  KeyValues *m_pData; // ecx
  KeyValues *Copy; // eax
  vgui::CItemButton_vtbl *v12; // edx

  if ( itemID < 0 )
    return 0;
  if ( itemID >= this->m_Items.m_Memory.m_nAllocationCount )
    return 0;
  if ( itemID > this->m_Items.m_LastAlloc.index )
    return 0;
  m_pMemory = this->m_Items.m_Memory.m_pMemory;
  v7 = itemID;
  if ( m_pMemory[itemID].m_Previous == itemID && m_pMemory[v7].m_Next != itemID )
    return 0;
  ((void (__thiscall *)(vgui::SectionedListPanel *, _DWORD, _DWORD, int))this->InvalidateLayout)(
    a1: this,
    a2: 0,
    a3: 0,
    a4: a2);
  vgui::CItemButton::SetSectionID(this: this->m_Items.m_Memory.m_pMemory[v7].m_Element, sectionID);
  m_Element = this->m_Items.m_Memory.m_pMemory[v7].m_Element;
  m_pData = m_Element->m_pData;
  if ( m_pData != nullptr )
    KeyValues::deleteThis(this: m_pData);
  Copy = KeyValues::MakeCopy(this: data);
  v12 = m_Element->__vftable;
  m_Element->m_pData = Copy;
  ((void (__thiscall *)(vgui::CItemButton *, _DWORD))v12->InvalidateLayout)(a1: m_Element, a2: 0);
  this->m_Items.m_Memory.m_pMemory[v7].m_Element->InvalidateLayout(
    this: this->m_Items.m_Memory.m_pMemory[v7].m_Element,
    a2: false,
    a3: false);
  this->m_bSortNeeded = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C9760
// Name: public: virtual int vgui::SectionedListPanel::GetColumnCountBySection(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetColumnCountBySection(vgui::SectionedListPanel *this, int sectionID)
{
  int m_Size; // edx
  int v3; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // edi
  vgui::SectionedListPanel::section_t *i; // ecx

  m_Size = this->m_Sections.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  if ( v3 >= 0 )
    return m_pMemory[v3].m_Columns.m_Size;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C97B0
// Name: public: virtual char const __near * vgui::SectionedListPanel::GetColumnNameBySection(int,int)
// Source: json
//------------------------------------------------------------------------------
vgui::SectionedListPanel::column_t *__thiscall vgui::SectionedListPanel::GetColumnNameBySection(
        vgui::SectionedListPanel *this,
        int sectionID,
        int columnIndex)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  vgui::SectionedListPanel::section_t *v8; // ecx

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  if ( v4 < 0 )
    return nullptr;
  v8 = &m_pMemory[v4];
  if ( columnIndex >= v8->m_Columns.m_Size )
    return nullptr;
  else
    return &v8->m_Columns.m_Memory.m_pMemory[columnIndex];
}

//------------------------------------------------------------------------------
// Address: 0x103C9810
// Name: public: virtual wchar_t const __near * vgui::SectionedListPanel::GetColumnTextBySection(int,int)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall vgui::SectionedListPanel::GetColumnTextBySection(
        vgui::SectionedListPanel *this,
        int sectionID,
        int columnIndex)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  int v8; // eax
  bool v9; // cc
  vgui::SectionedListPanel::section_t *v10; // eax

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  if ( v4 >= 0 && (v8 = v4, v9 = columnIndex < m_pMemory[v8].m_Columns.m_Size, v10 = &m_pMemory[v8], v9) )
    return v10->m_Columns.m_Memory.m_pMemory[columnIndex].m_szColumnText;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C9870
// Name: public: virtual int vgui::SectionedListPanel::GetColumnFlagsBySection(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetColumnFlagsBySection(
        vgui::SectionedListPanel *this,
        int sectionID,
        int columnIndex)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  int v8; // eax
  bool v9; // cc
  vgui::SectionedListPanel::section_t *v10; // eax

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 >= 0 && (v8 = v4, v9 = columnIndex < m_pMemory[v8].m_Columns.m_Size, v10 = &m_pMemory[v8], v9) )
    return v10->m_Columns.m_Memory.m_pMemory[columnIndex].m_iColumnFlags;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C98E0
// Name: public: virtual int vgui::SectionedListPanel::GetColumnWidthBySection(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetColumnWidthBySection(
        vgui::SectionedListPanel *this,
        int sectionID,
        int columnIndex)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  int v8; // eax
  bool v9; // cc
  vgui::SectionedListPanel::section_t *v10; // eax

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 >= 0 && (v8 = v4, v9 = columnIndex < m_pMemory[v8].m_Columns.m_Size, v10 = &m_pMemory[v8], v9) )
    return v10->m_Columns.m_Memory.m_pMemory[columnIndex].m_iWidth;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C9950
// Name: public: virtual int vgui::SectionedListPanel::GetColumnIndexByName(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetColumnIndexByName(
        vgui::SectionedListPanel *this,
        int sectionID,
        char *name)
{
  int m_Size; // edx
  int v4; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // ebx
  vgui::SectionedListPanel::section_t *i; // ecx
  int v8; // esi
  int v9; // edi
  bool v10; // cc
  vgui::SectionedListPanel::section_t *v11; // eax
  int j; // ebx

  m_Size = this->m_Sections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 < 0 )
    return 0;
  v8 = v4;
  v9 = 0;
  v10 = m_pMemory[v4].m_Columns.m_Size <= 0;
  v11 = &m_pMemory[v4];
  if ( v10 )
    return -1;
  for ( j = 0; _V_strcmp(s1: v11->m_Columns.m_Memory.m_pMemory[j].m_szColumnName, s2: name) != 0; ++j )
  {
    ++v9;
    v11 = &this->m_Sections.m_Memory.m_pMemory[v8];
    if ( v9 >= v11->m_Columns.m_Size )
      return -1;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x103C9A00
// Name: protected: virtual void vgui::SectionedListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::SectionedListPanel::OnKeyCodeTyped(vgui::SectionedListPanel *this@<ecx>, int a2@<ebx>, int code)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  unsigned int v6; // eax
  int v7; // edi
  vgui::SectionedListPanel_vtbl *v8; // edx
  int m_iID; // edi
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v10; // eax
  int v11; // ebx
  int v12; // eax
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // edx
  vgui::SectionedListPanel_vtbl *v14; // edx
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v15; // eax
  int v16; // ebx
  int v17; // eax
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v18; // edx
  int x; // [esp+4h] [ebp-14h] BYREF
  int cy; // [esp+8h] [ebp-10h] BYREF
  int cwide; // [esp+Ch] [ebp-Ch] BYREF
  int ctall; // [esp+10h] [ebp-8h] BYREF
  int rowsperpage; // [esp+14h] [ebp-4h]
  int secID; // [esp+20h] [ebp+8h]
  int secIDa; // [esp+20h] [ebp+8h]

  if ( vgui::PHandle::Get(this: &this->m_hEditModePanel) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "KeyCodeTyped", firstKey: "code", firstValue: code);
      vgui::Panel::CallParentFunction(this, message: v5);
    }
    else
    {
      vgui::Panel::CallParentFunction(this, message: nullptr);
    }
    return;
  }
  if ( this->m_Sections.m_Size != 0
    && (v6 = this->m_Sections.m_Memory.m_pMemory->m_pHeader->GetFont(this: this->m_Sections.m_Memory.m_pMemory->m_pHeader)) != 0 )
  {
    v7 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v6) + 7;
  }
  else
  {
    v7 = 20;
  }
  switch ( code )
  {
    case 'Z':
      vgui::SectionedListPanel::MoveSelectionDown(this);
      return;
    case 'X':
      vgui::SectionedListPanel::MoveSelectionUp(this);
      return;
    case 'M':
      vgui::Panel::GetBounds(this, &x, y: &cy, wide: &cwide, tall: &ctall);
      v8 = this->__vftable;
      rowsperpage = ctall / v7;
      m_iID = ((int (__thiscall *)(vgui::SectionedListPanel *, int))v8->GetSelectedItem)(a1: this, a2);
      v10 = &this->m_Items.m_Memory.m_pMemory[m_iID];
      secID = v10->m_Element->m_iSectionID;
      v11 = 0;
      v12 = CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int>>::Find(
              this: &this->m_SortedItems,
              src: &v10->m_Element);
      while ( v11 < rowsperpage )
      {
        if ( ++v12 < 0 || v12 >= this->m_SortedItems.m_Size )
          break;
        m_iID = this->m_SortedItems.m_Memory.m_pMemory[v12]->m_iID;
        m_pMemory = this->m_Items.m_Memory.m_pMemory;
        ++v11;
        if ( m_pMemory[m_iID].m_Element->m_iSectionID != secID )
        {
          secID = m_pMemory[m_iID].m_Element->m_iSectionID;
          ++v11;
        }
      }
      goto LABEL_28;
    case 'L':
      vgui::Panel::GetBounds(this, x: &cwide, y: &cy, wide: &x, tall: &ctall);
      v14 = this->__vftable;
      rowsperpage = ctall / v7;
      m_iID = ((int (__thiscall *)(vgui::SectionedListPanel *, int))v14->GetSelectedItem)(a1: this, a2);
      v15 = &this->m_Items.m_Memory.m_pMemory[m_iID];
      secIDa = v15->m_Element->m_iSectionID;
      v16 = 0;
      v17 = CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int>>::Find(
              this: &this->m_SortedItems,
              src: &v15->m_Element);
      if ( rowsperpage <= 0 )
      {
LABEL_28:
        vgui::SectionedListPanel::SetSelectedItem(
          this,
          a2: (int)this,
          item: this->m_Items.m_Memory.m_pMemory[m_iID].m_Element);
        this->ScrollToItem(this, a2: m_iID);
        return;
      }
      while ( --v17 >= 0 && v17 < this->m_SortedItems.m_Size )
      {
        m_iID = this->m_SortedItems.m_Memory.m_pMemory[v17]->m_iID;
        v18 = this->m_Items.m_Memory.m_pMemory;
        ++v16;
        if ( v18[m_iID].m_Element->m_iSectionID != secIDa )
        {
          secIDa = v18[m_iID].m_Element->m_iSectionID;
          ++v16;
        }
        if ( v16 >= rowsperpage )
          goto LABEL_28;
      }
      vgui::SectionedListPanel::SetSelectedItem(
        this,
        a2: (int)this,
        item: this->m_Items.m_Memory.m_pMemory[m_iID].m_Element);
      this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: 0);
      break;
    case 'Y':
    case '[':
LABEL_35:
      break;
    default:
      vgui::Panel::OnKeyCodeTyped(this, keycode: (ButtonCode_t)code);
      goto LABEL_35;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C9D00
// Name: public: vgui::CItemButton::CItemButton(class vgui::SectionedListPanel __near *,int)
// Source: json
//------------------------------------------------------------------------------
vgui::CItemButton *__thiscall vgui::CItemButton::CItemButton(
        vgui::CItemButton *this,
        vgui::SectionedListPanel *parent,
        int itemID)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::CItemButton_vtbl *v7; // eax
  void (__thiscall *SetPaintBackgroundEnabled)(vgui::Panel *, bool); // edx

  vgui::Label::Label(this, parent, panelName: nullptr, text: "< item >");
  this->__vftable = (vgui::CItemButton_vtbl *)&vgui::CItemButton::`vftable';
  if ( `vgui::CItemButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CItemButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CItemButton");
    v4->pfnClassName = vgui::CItemButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::CItemButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CItemButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CItemButton");
    v5->pfnClassName = vgui::CItemButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::CItemButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CItemButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CItemButton");
    v6->pfnClassName = vgui::CItemButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  this->m_FgColor2 = 0;
  this->m_BgColor = 0;
  this->m_ArmedFgColor1 = 0;
  this->m_ArmedFgColor2 = 0;
  this->m_OutOfFocusSelectedTextColor = 0;
  this->m_ArmedBgColor = 0;
  this->m_SelectionBG2Color = 0;
  this->m_TextImages.m_Memory.m_pMemory = nullptr;
  this->m_TextImages.m_Memory.m_nAllocationCount = 0;
  this->m_TextImages.m_Memory.m_nGrowSize = 0;
  this->m_TextImages.m_Size = 0;
  this->m_TextImages.m_pElements = nullptr;
  v7 = this->__vftable;
  this->m_pListPanel = parent;
  this->m_iID = itemID;
  SetPaintBackgroundEnabled = v7->SetPaintBackgroundEnabled;
  this->m_pData = nullptr;
  *(_WORD *)&this->m_bSelected = 0;
  this->m_iSectionID = -1;
  SetPaintBackgroundEnabled(this, a2: false);
  this->SetTextImageIndex(this, a2: -1);
  this->ClearImages(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C9E60
// Name: public: virtual void vgui::CItemButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CItemButton::Paint(vgui::CItemButton *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi
  int v5; // eax
  const char *v6; // eax
  vgui::SectionedListPanel *m_pListPanel; // ecx
  int m_iSectionID; // edx
  char v9; // bl
  int Int; // ebx
  vgui::IImage *v11; // eax
  int v12; // eax
  vgui::ISurface_vtbl *v13; // ebx
  int colCount; // [esp+4h] [ebp-24h]
  int maxWidth; // [esp+8h] [ebp-20h]
  vgui::ISurface *maxWidtha; // [esp+8h] [ebp-20h]
  int v19; // [esp+Ch] [ebp-1Ch] BYREF
  const char *keyname; // [esp+10h] [ebp-18h]
  int wide; // [esp+14h] [ebp-14h] BYREF
  int tall; // [esp+18h] [ebp-10h] BYREF
  int imageWide; // [esp+1Ch] [ebp-Ch] BYREF
  int xpos; // [esp+20h] [ebp-8h]
  vgui::IImage *image; // [esp+24h] [ebp-4h]

  vgui::Label::Paint(this);
  if ( this->m_bShowColumns )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
    v4 = 0;
    g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
    v5 = this->m_pListPanel->GetColumnCountBySection(this: this->m_pListPanel, a2: this->m_iSectionID);
    colCount = v5;
    if ( this->m_pData != nullptr && v5 >= 0 )
    {
      xpos = 0;
      if ( v5 > 0 )
      {
        do
        {
          v6 = (const char *)((int (__thiscall *)(vgui::SectionedListPanel *, int, int, int, int))this->m_pListPanel->GetColumnNameBySection)(
                               a1: this->m_pListPanel,
                               a2: this->m_iSectionID,
                               a3: v4,
                               a4: a2,
                               a5: a3);
          m_pListPanel = this->m_pListPanel;
          m_iSectionID = this->m_iSectionID;
          keyname = v6;
          v9 = m_pListPanel->GetColumnFlagsBySection(this: m_pListPanel, a2: m_iSectionID, a3: v4);
          maxWidth = this->m_pListPanel->GetColumnWidthBySection(
                       this: this->m_pListPanel,
                       a2: this->m_iSectionID,
                       a3: v4);
          image = nullptr;
          if ( (v9 & 2) != 0 )
          {
            if ( this->m_pListPanel->m_pImageList == nullptr )
              goto LABEL_12;
            Int = KeyValues::GetInt(this: this->m_pData, keyName: (char *)keyname, defaultValue: 0);
            if ( !vgui::ImageList::IsValidIndex(this: this->m_pListPanel->m_pImageList, imageIndex: Int) || Int <= 0 )
              goto LABEL_12;
            v11 = vgui::ImageList::GetImage(this: this->m_pListPanel->m_pImageList, imageIndex: Int);
          }
          else
          {
            v11 = this->GetImageAtIndex(this, a2: v4);
          }
          image = v11;
LABEL_12:
          imageWide = 0;
          v19 = 0;
          if ( image != nullptr )
            image->GetContentSize(this: image, a2: &imageWide, a3: &v19);
          v12 = maxWidth;
          if ( maxWidth < 0 )
            v12 = imageWide;
          xpos += v12;
          v13 = g_pVGuiSurface->__vftable;
          maxWidtha = g_pVGuiSurface;
          a3 = vgui::Panel::GetTall(this);
          a2 = xpos;
          ((void (__thiscall *)(vgui::ISurface *, int, _DWORD))v13->DrawOutlinedRect)(a1: maxWidtha, a2: xpos, a3: 0);
          ++v4;
        }
        while ( v4 < colCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CA020
// Name: public: virtual void vgui::CItemButton::SetOverrideColors(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::SetOverrideColors(vgui::CItemButton *this, bool state)
{
  this->m_bOverrideColors = state;
}

//------------------------------------------------------------------------------
// Address: 0x103CA030
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CItemButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CItemButton::GetMessageMap(vgui::CItemButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CItemButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CItemButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CItemButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CItemButton");
  `vgui::CItemButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103CA060
// Name: public: virtual struct PanelAnimationMap __near * vgui::CItemButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CItemButton::GetAnimMap(vgui::CItemButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CItemButton");
}

//------------------------------------------------------------------------------
// Address: 0x103CA070
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CItemButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CItemButton::GetKBMap(vgui::CItemButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CItemButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CItemButton::GetKBMap'::`2'::s_pMap;
  `vgui::CItemButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CItemButton");
  `vgui::CItemButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103CA0A0
// Name: public: virtual void vgui::CItemButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::ApplySchemeSettings(vgui::CItemButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CItemButton_vtbl *v4; // ebx
  Color *v5; // eax
  int m_hRowFont; // eax
  int v7; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v9; // al
  _BYTE v10[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  this->m_ArmedFgColor1 = *this->GetSchemeColor_2(
                             this,
                             result: &pScheme,
                             a3: "SectionedListPanel.BrightTextColor",
                             a4: v2);
  this->m_ArmedFgColor2 = *this->GetSchemeColor_2(
                             this,
                             result: &pScheme,
                             a3: "SectionedListPanel.SelectedTextColor",
                             a4: v2);
  this->m_OutOfFocusSelectedTextColor = *this->GetSchemeColor_2(
                                           this,
                                           result: &pScheme,
                                           a3: "SectionedListPanel.OutOfFocusSelectedTextColor",
                                           a4: v2);
  this->m_ArmedBgColor = *this->GetSchemeColor_2(
                            this,
                            result: &pScheme,
                            a3: "SectionedListPanel.SelectedBgColor",
                            a4: v2);
  this->m_FgColor2 = *this->GetSchemeColor_2(this, result: &pScheme, a3: "SectionedListPanel.TextColor", a4: v2);
  v4 = this->__vftable;
  v5 = this->GetBgColor(this, result: &pScheme);
  this->m_BgColor = *((int (__thiscall *)(vgui::CItemButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v4->GetSchemeColor)(
                       a1: this,
                       a2: (Color *)v10,
                       a3: "SectionedListPanel.BgColor",
                       a4: *v5,
                       a5: v2);
  this->m_SelectionBG2Color = *this->GetSchemeColor_2(
                                 this,
                                 result: &pScheme,
                                 a3: "SectionedListPanel.OutOfFocusSelectedBgColor",
                                 a4: v2);
  m_hRowFont = this->m_pListPanel->m_hRowFont;
  if ( m_hRowFont != 0
    || (v7 = (int)v2->GetResourceString(this: v2, a2: "SectionedListPanel.Font"),
        IsProportional = this->IsProportional,
        pScheme = (vgui::IScheme *)v2->__vftable,
        v9 = IsProportional(this),
        (m_hRowFont = ((int (__thiscall *)(vgui::IScheme *, int, bool))pScheme[3].__vftable)(a1: v2, a2: v7, a3: v9)) != 0) )
  {
    this->SetFont(this, a2: m_hRowFont);
  }
  this->ClearImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CA200
// Name: public: virtual void vgui::CItemButton::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::PaintBackground(vgui::CItemButton *this)
{
  unsigned int v2; // ebx
  vgui::IPanel *v3; // edi
  unsigned int (__thiscall *GetVParent)(vgui::Panel *); // eax
  int v5; // eax
  vgui::ISurface_vtbl *v6; // ebx
  int v7; // eax
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  vgui::IPanel_vtbl *v10; // [esp+14h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  if ( !this->m_bSelected || this->m_pListPanel->IsInEditMode(this: this->m_pListPanel) )
  {
    v6 = g_pVGuiSurface->__vftable;
    v7 = (int)*this->GetBgColor(this, result: &v10);
    ((void (__stdcall *)(int))v6->DrawSetColor)(a1: v7);
  }
  else
  {
    v2 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
    if ( this->HasFocus(this)
      || v2 != 0
      && (v3 = g_pVGuiPanel,
          GetVParent = this->GetVParent,
          v10 = g_pVGuiPanel->__vftable,
          v5 = GetVParent(this),
          v10->HasParent(this: v3, a2: v2, a3: v5)) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->m_ArmedBgColor);
    }
    else
    {
      ((void (__stdcall *)(_DWORD))g_pVGuiSurface->DrawSetColor)(a1: *(_DWORD *)&this->m_SelectionBG2Color);
    }
  }
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x103CA2F0
// Name: public: virtual void vgui::CItemButton::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::OnMousePressed(vgui::CItemButton *this, ButtonCode_t code)
{
  vgui::SectionedListPanel *m_pListPanel; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  m_pListPanel = this->m_pListPanel;
  if ( m_pListPanel != nullptr && m_pListPanel->m_clickable )
  {
    if ( code == KEY_COUNT )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "ItemLeftClick", firstKey: "itemID", firstValue: this->m_iID);
      else
        v5 = nullptr;
      this->m_pListPanel->PostActionSignal(this: this->m_pListPanel, a2: v5);
      vgui::SectionedListPanel::SetSelectedItem(this: this->m_pListPanel, a2: (int)this, item: this);
    }
    else
    {
      if ( code == MOUSE_RIGHT )
      {
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
          v7 = KeyValues::KeyValues(this: v6, setName: "ItemContextMenu", firstKey: "itemID", firstValue: this->m_iID);
        else
          v7 = nullptr;
        KeyValues::SetPtr(this: v7, keyName: "SubPanel", value: this);
        this->m_pListPanel->PostActionSignal(this: this->m_pListPanel, a2: v7);
      }
      vgui::SectionedListPanel::SetSelectedItem(this: this->m_pListPanel, a2: (int)this, item: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CA3D0
// Name: public: virtual void vgui::CItemButton::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::OnMouseDoublePressed(vgui::CItemButton *this, ButtonCode_t code)
{
  vgui::SectionedListPanel *m_pListPanel; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  m_pListPanel = this->m_pListPanel;
  if ( m_pListPanel != nullptr && m_pListPanel->m_clickable )
  {
    if ( code == KEY_COUNT )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "ItemDoubleLeftClick", firstKey: "itemID", firstValue: this->m_iID);
      else
        v5 = nullptr;
      this->m_pListPanel->PostActionSignal(this: this->m_pListPanel, a2: v5);
      this->m_pListPanel->OnKeyCodeTyped(this: this->m_pListPanel, a2: KEY_ENTER);
      vgui::SectionedListPanel::SetSelectedItem(this: this->m_pListPanel, a2: (int)this, item: this);
    }
    else
    {
      this->OnMousePressed(this, a2: code);
      vgui::SectionedListPanel::SetSelectedItem(this: this->m_pListPanel, a2: (int)this, item: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CA4C0
// Name: public: static void vgui::SectionedListPanel::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::SectionedListPanel::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::SectionedListPanel::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::SectionedListPanel::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::SectionedListPanel::`vcall'{1032,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "SectionedListPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ScrollBarSliderMoved";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CA550
// Name: public: static void vgui::SectionedListPanel::PanelAnimationVar_m_bShowColumns::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::SectionedListPanel::PanelAnimationVar_m_bShowColumns::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::SectionedListPanel::PanelAnimationVar_m_bShowColumns::InitVar'::`2'::bAdded )
  {
    `vgui::SectionedListPanel::PanelAnimationVar_m_bShowColumns::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "SectionedListPanel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "show_columns";
    src.m_pszVariable = "m_bShowColumns";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "false";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::SectionedListPanel::GetVar_m_bShowColumns;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CA5B0
// Name: public: virtual void vgui::CItemButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CItemButton::PerformLayout(vgui::CItemButton *this)
{
  int v2; // eax
  bool v3; // zf
  int v4; // edi
  int v5; // ebx
  vgui::TextImage *v6; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  vgui::TextImage **m_pMemory; // ecx
  int v10; // eax
  vgui::TextImage **v11; // ebx
  vgui::TextImage_vtbl *v12; // edi
  unsigned int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  int v16; // ebx
  int v17; // ebx
  const char *v18; // eax
  vgui::SectionedListPanel *m_pListPanel; // ecx
  int m_iSectionID; // edx
  int v21; // eax
  vgui::SectionedListPanel *v22; // ecx
  int (__thiscall *GetColumnWidthBySection)(vgui::SectionedListPanel *, int, int); // edx
  vgui::TextImage *v24; // edi
  int Int; // eax
  vgui::ImageList *m_pImageList; // ecx
  vgui::IImage *v27; // eax
  vgui::TextImage *v28; // eax
  vgui::TextImage_vtbl *v29; // ebx
  char *String; // eax
  unsigned int v31; // eax
  unsigned int v32; // ebx
  vgui::CItemButton_vtbl *v33; // edx
  vgui::IPanel_vtbl *v34; // ebx
  int v35; // eax
  void (__thiscall *SetColor)(struct vgui::TextImage *, Color); // edx
  vgui::IPanel_vtbl *v37; // ebx
  unsigned int v38; // eax
  vgui::TextImage_vtbl *v39; // ebx
  Color *v40; // eax
  int v41; // eax
  int v42; // edi
  int v43; // [esp-4h] [ebp-3Ch]
  char v44[4]; // [esp+Ch] [ebp-2Ch] BYREF
  int v45; // [esp+10h] [ebp-28h]
  int tall; // [esp+14h] [ebp-24h] BYREF
  vgui::IPanel *v47; // [esp+18h] [ebp-20h]
  int colCount; // [esp+1Ch] [ebp-1Ch]
  int maxWidth; // [esp+20h] [ebp-18h]
  unsigned int focus; // [esp+24h] [ebp-14h]
  int imageWide; // [esp+28h] [ebp-10h] BYREF
  int columnFlags; // [esp+2Ch] [ebp-Ch]
  vgui::TextImage *image; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]

  v2 = this->m_pListPanel->GetColumnCountBySection(this: this->m_pListPanel, a2: this->m_iSectionID);
  v3 = this->m_pData == nullptr;
  v4 = v2;
  colCount = v2;
  if ( v3 || v2 < 1 )
  {
    this->SetText(this, a2: "< unset >");
  }
  else
  {
    if ( v2 != this->GetImageCount(this) )
    {
      v5 = 0;
      for ( i = 0; v5 < v4; i = v5 )
      {
        if ( (this->m_pListPanel->GetColumnFlagsBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v5) & 2) == 0 )
        {
          v6 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
          if ( v6 != nullptr )
            image = vgui::TextImage::TextImage(this: v6, text: prType);
          else
            image = nullptr;
          m_Size = this->m_TextImages.m_Size;
          m_nAllocationCount = this->m_TextImages.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_TextImages,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_TextImages.m_Size;
          m_pMemory = this->m_TextImages.m_Memory.m_pMemory;
          v10 = this->m_TextImages.m_Size - m_Size - 1;
          this->m_TextImages.m_pElements = m_pMemory;
          if ( v10 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v10);
          v11 = &this->m_TextImages.m_Memory.m_pMemory[m_Size];
          if ( v11 != nullptr )
            *v11 = image;
          v12 = image->__vftable;
          v13 = this->GetFont(this);
          v12->SetFont(this: image, a2: v13);
          v14 = this->m_pListPanel->GetColumnFallbackFontBySection(
                  this: this->m_pListPanel,
                  a2: this->m_iSectionID,
                  a3: i);
          if ( v14 != 0 )
            vgui::TextImage::SetUseFallbackFont(this: image, bState: true, hFallback: v14);
          this->SetImageAtIndex(this, a2: i, a3: image, a4: 0);
          v4 = colCount;
          v5 = i;
        }
        ++v5;
      }
      v15 = this->GetImageCount(this);
      if ( v15 < v4 )
      {
        v16 = v4 - v15;
        do
        {
          this->AddImage(this, a2: nullptr, a3: 0);
          --v16;
        }
        while ( v16 != 0 );
      }
    }
    v17 = 0;
    image = nullptr;
    i = 0;
    if ( v4 > 0 )
    {
      while ( 1 )
      {
        v18 = this->m_pListPanel->GetColumnNameBySection(this: this->m_pListPanel, a2: this->m_iSectionID, a3: v17);
        m_pListPanel = this->m_pListPanel;
        m_iSectionID = this->m_iSectionID;
        focus = (unsigned int)v18;
        v21 = m_pListPanel->GetColumnFlagsBySection(this: m_pListPanel, a2: m_iSectionID, a3: v17);
        v22 = this->m_pListPanel;
        GetColumnWidthBySection = v22->GetColumnWidthBySection;
        columnFlags = v21;
        maxWidth = GetColumnWidthBySection(this: v22, a2: this->m_iSectionID, a3: v17);
        v24 = nullptr;
        v45 = columnFlags & 2;
        if ( (columnFlags & 2) != 0 )
        {
          if ( this->m_pListPanel->m_pImageList != nullptr )
          {
            Int = KeyValues::GetInt(this: this->m_pData, keyName: (char *)focus, defaultValue: 0);
            m_pImageList = this->m_pListPanel->m_pImageList;
            focus = Int;
            if ( vgui::ImageList::IsValidIndex(this: m_pImageList, imageIndex: Int) && (int)focus > 0 )
            {
              v24 = (vgui::TextImage *)vgui::ImageList::GetImage(
                                         this: this->m_pListPanel->m_pImageList,
                                         imageIndex: focus);
              this->SetImageAtIndex(this, a2: v17, a3: v24, a4: 0);
            }
          }
          goto LABEL_46;
        }
        v27 = this->GetImageAtIndex(this, a2: v17);
        v28 = (vgui::TextImage *)__RTDynamicCast(
                                   inptr: v27,
                                   VfDelta: 0,
                                   SrcType: &vgui::IImage `RTTI Type Descriptor',
                                   TargetType: &vgui::TextImage `RTTI Type Descriptor',
                                   isReference: 0);
        v24 = v28;
        if ( v28 != nullptr )
          break;
LABEL_46:
        v41 = 0;
        imageWide = 0;
        tall = 0;
        if ( v24 != nullptr )
        {
          v24->GetContentSize(this: v24, a2: &imageWide, a3: &tall);
          v41 = imageWide;
        }
        v42 = maxWidth;
        if ( maxWidth < 0 )
          v42 = v41;
        if ( v17 != 0 || v45 != 0 )
        {
          if ( (columnFlags & 8) != 0 )
          {
            this->SetImageBounds(
              this,
              a2: v17,
              a3: (int)image + v42 / 2 - imageWide / 2,
              a4: v42 - (v42 / 2 - imageWide / 2) - 2);
          }
          else
          {
            v43 = v42 - 2;
            if ( (columnFlags & 0x10) != 0 )
              this->SetImageBounds(this, a2: v17, a3: (int)image + v42 - v41, a4: v43);
            else
              this->SetImageBounds(this, a2: v17, a3: (int)image, a4: v43);
          }
        }
        else
        {
          this->SetImageBounds(this, a2: 0, a3: (int)image->_pos + 2, a4: v42 - 8);
        }
        image = (vgui::TextImage *)((char *)image + v42);
        i = ++v17;
        if ( v17 >= colCount )
        {
          vgui::Label::PerformLayout(this);
          return;
        }
      }
      v29 = v28->__vftable;
      String = KeyValues::GetString(this: this->m_pData, keyName: (char *)focus, defaultValue: prType);
      v29->SetText_2(this: v24, a2: String);
      vgui::TextImage::ResizeImageToContentMaxWidth(this: v24, nMaxWidth: maxWidth);
      v31 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
      v3 = !this->m_bOverrideColors;
      v32 = v31;
      focus = v31;
      if ( v3 )
      {
        if ( !this->m_bSelected || this->m_pListPanel->IsInEditMode(this: this->m_pListPanel) )
        {
          SetColor = v24->SetColor;
          if ( (columnFlags & 4) != 0 )
            ((void (__thiscall *)(vgui::TextImage *, _DWORD))SetColor)(a1: v24, a2: *(_DWORD *)&this->m_ArmedFgColor1);
          else
            ((void (__thiscall *)(vgui::TextImage *, _DWORD))SetColor)(a1: v24, a2: *(_DWORD *)&this->m_FgColor2);
          goto LABEL_45;
        }
        if ( !this->HasFocus(this) )
        {
          if ( v32 == 0
            || (v33 = this->__vftable,
                v34 = g_pVGuiPanel->__vftable,
                v47 = g_pVGuiPanel,
                v35 = v33->GetVParent(this),
                !v34->HasParent(this: v47, a2: focus, a3: v35)) )
          {
            ((void (__thiscall *)(vgui::TextImage *, _DWORD))v24->SetColor)(
              a1: v24,
              a2: *(_DWORD *)&this->m_OutOfFocusSelectedTextColor);
LABEL_45:
            v17 = i;
            goto LABEL_46;
          }
        }
      }
      else if ( !this->m_bSelected
             || !this->HasFocus(this)
             && (v32 == 0
              || (v37 = g_pVGuiPanel->__vftable,
                  v47 = g_pVGuiPanel,
                  v38 = this->GetVParent(this),
                  !v37->HasParent(this: v47, a2: focus, a3: v38))) )
      {
        v39 = v24->__vftable;
        v40 = this->GetFgColor(this, result: v44);
        v39->SetColor(this: v24, a2: *v40);
        goto LABEL_45;
      }
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))v24->SetColor)(a1: v24, a2: *(_DWORD *)&this->m_ArmedFgColor2);
      goto LABEL_45;
    }
  }
  vgui::Label::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CAAA0
// Name: private: void vgui::SectionedListPanel::ReSortList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::ReSortList(vgui::SectionedListPanel *this)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_SortedItems; // esi
  int m_Head; // ebx
  int v3; // edi
  bool v4; // zf
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v7; // ebx
  vgui::TreeNode **v8; // edx
  int v9; // eax
  vgui::CItemButton **v10; // edi
  int v11; // edx
  vgui::TreeNode **v12; // eax
  vgui::TreeNode **v13; // edx
  int v14; // eax
  vgui::CItemButton **v15; // edi
  vgui::TreeNode **v16; // edi
  int v17; // eax
  vgui::TreeNode **v18; // edx
  int v19; // eax
  vgui::CItemButton **v20; // edi
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v21; // [esp+4h] [ebp-1Ch]
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v22; // [esp+4h] [ebp-1Ch]
  int sectionStart; // [esp+8h] [ebp-18h]
  int sectionIndex; // [esp+Ch] [ebp-14h]
  vgui::SectionedListPanel::section_t *section; // [esp+10h] [ebp-10h]
  int v26; // [esp+14h] [ebp-Ch]
  int v27; // [esp+18h] [ebp-8h]
  vgui::SectionedListPanel *v28; // [esp+1Ch] [ebp-4h]

  p_m_SortedItems = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SortedItems;
  this->m_SortedItems.m_Size = 0;
  v28 = this;
  sectionIndex = 0;
  if ( this->m_Sections.m_Size > 0 )
  {
    v27 = 0;
    do
    {
      m_Head = this->m_Items.m_Head;
      section = &this->m_Sections.m_Memory.m_pMemory[v27];
      for ( sectionStart = this->m_SortedItems.m_Size; m_Head != -1; m_Head = this->m_Items.m_Memory.m_pMemory[v26].m_Next )
      {
        v26 = m_Head;
        v21 = &this->m_Items.m_Memory.m_pMemory[m_Head];
        if ( v21->m_Element->m_iSectionID == this->m_Sections.m_Memory.m_pMemory[v27].m_iID )
        {
          if ( section->m_pSortFunc != nullptr )
          {
            v3 = sectionStart;
            v4 = sectionStart == this->m_SortedItems.m_Size;
            if ( sectionStart < this->m_SortedItems.m_Size )
            {
              while ( !section->m_pSortFunc(
                         a1: this,
                         a2: m_Head,
                         a3: p_m_SortedItems->m_pMemory[v3][1].m_LastNavDirection) )
              {
                if ( ++v3 >= v28->m_SortedItems.m_Size )
                  break;
                this = v28;
              }
              this = v28;
              v4 = v3 == v28->m_SortedItems.m_Size;
            }
            if ( v4 )
            {
              m_pMemory = p_m_SortedItems[1].m_pMemory;
              m_nAllocationCount = p_m_SortedItems->m_nAllocationCount;
              v7 = &this->m_Items.m_Memory.m_pMemory[v26];
              if ( (int)m_pMemory + 1 > m_nAllocationCount )
              {
                CUtlMemory<CChoreoActor *,int>::Grow(
                  this: p_m_SortedItems,
                  num: (int)m_pMemory - m_nAllocationCount + 1);
                this = v28;
              }
              ++p_m_SortedItems[1].m_pMemory;
              v8 = p_m_SortedItems->m_pMemory;
              v9 = (char *)p_m_SortedItems[1].m_pMemory - (char *)m_pMemory - 1;
              p_m_SortedItems[1].m_nAllocationCount = (int)p_m_SortedItems->m_pMemory;
              if ( v9 > 0 )
              {
                _V_memmove(
                  dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
                  src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
                  count: 4 * v9);
                this = v28;
              }
              v10 = (vgui::CItemButton **)&p_m_SortedItems->m_pMemory[(_DWORD)m_pMemory];
              if ( v10 != nullptr )
                *v10 = v7->m_Element;
            }
            else
            {
              v11 = p_m_SortedItems->m_nAllocationCount;
              v22 = &this->m_Items.m_Memory.m_pMemory[v26];
              v12 = p_m_SortedItems[1].m_pMemory;
              if ( (int)v12 + 1 > v11 )
              {
                CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_SortedItems, num: (int)v12 - v11 + 1);
                this = v28;
              }
              ++p_m_SortedItems[1].m_pMemory;
              v13 = p_m_SortedItems->m_pMemory;
              v14 = (int)p_m_SortedItems[1].m_pMemory - v3 - 1;
              p_m_SortedItems[1].m_nAllocationCount = (int)p_m_SortedItems->m_pMemory;
              if ( v14 > 0 )
              {
                _V_memmove(dest: (unsigned __int8 *)&v13[v3 + 1], src: (unsigned __int8 *)&v13[v3], count: 4 * v14);
                this = v28;
              }
              v15 = (vgui::CItemButton **)&p_m_SortedItems->m_pMemory[v3];
              if ( v15 != nullptr )
                *v15 = v22->m_Element;
            }
          }
          else
          {
            v16 = p_m_SortedItems[1].m_pMemory;
            v17 = p_m_SortedItems->m_nAllocationCount;
            if ( (int)v16 + 1 > v17 )
            {
              CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_SortedItems, num: (int)v16 - v17 + 1);
              this = v28;
            }
            ++p_m_SortedItems[1].m_pMemory;
            v18 = p_m_SortedItems->m_pMemory;
            v19 = (char *)p_m_SortedItems[1].m_pMemory - (char *)v16 - 1;
            p_m_SortedItems[1].m_nAllocationCount = (int)p_m_SortedItems->m_pMemory;
            if ( v19 > 0 )
            {
              _V_memmove(
                dest: (unsigned __int8 *)&v18[(_DWORD)v16 + 1],
                src: (unsigned __int8 *)&v18[(_DWORD)v16],
                count: 4 * v19);
              this = v28;
            }
            v20 = (vgui::CItemButton **)&p_m_SortedItems->m_pMemory[(_DWORD)v16];
            if ( v20 != nullptr )
              *v20 = v21->m_Element;
          }
        }
      }
      ++v27;
      ++sectionIndex;
    }
    while ( sectionIndex < this->m_Sections.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CACD0
// Name: protected: virtual void vgui::SectionedListPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::PerformLayout(vgui::SectionedListPanel *this)
{
  int Wide; // eax
  int v3; // eax
  int v4; // [esp-4h] [ebp-1Ch]
  int x; // [esp+8h] [ebp-10h] BYREF
  int cy; // [esp+Ch] [ebp-Ch] BYREF
  int cwide; // [esp+10h] [ebp-8h] BYREF
  int ctall; // [esp+14h] [ebp-4h] BYREF

  if ( this->m_bSortNeeded )
  {
    vgui::SectionedListPanel::ReSortList(this);
    this->m_bSortNeeded = false;
  }
  vgui::Panel::PerformLayout(this);
  vgui::SectionedListPanel::LayoutPanels(this, contentTall: &this->m_iContentHeight);
  vgui::Panel::GetBounds(this, &x, y: &cy, wide: &cwide, tall: &ctall);
  if ( this->m_iContentHeight > ctall && this->m_bVerticalScrollbarEnabled )
  {
    this->m_pScrollBar->SetVisible(this: this->m_pScrollBar, a2: true);
    this->m_pScrollBar->MoveToFront(this: this->m_pScrollBar);
    Wide = vgui::Panel::GetWide(this: this->m_pScrollBar);
    vgui::Panel::SetPos(this: this->m_pScrollBar, x: cwide - Wide - 2, y: 0);
    v4 = ctall - 2;
    v3 = vgui::Panel::GetWide(this: this->m_pScrollBar);
    vgui::Panel::SetSize(this: this->m_pScrollBar, wide: v3, tall: v4);
    this->m_pScrollBar->SetRangeWindow(this: this->m_pScrollBar, a2: ctall);
    this->m_pScrollBar->SetRange(this: this->m_pScrollBar, a2: 0, a3: this->m_iContentHeight);
    this->m_pScrollBar->InvalidateLayout(this: this->m_pScrollBar, a2: false, a3: false);
    this->m_pScrollBar->Repaint(this: this->m_pScrollBar);
    vgui::SectionedListPanel::LayoutPanels(this, contentTall: &this->m_iContentHeight);
  }
  else
  {
    this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: 0);
    this->m_pScrollBar->SetVisible(this: this->m_pScrollBar, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CAE20
// Name: public: virtual void vgui::SectionedListPanel::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::GetContentSize(vgui::SectionedListPanel *this, int *wide, int *tall)
{
  if ( this->IsLayoutInvalid(this) )
  {
    if ( this->m_bSortNeeded )
    {
      vgui::SectionedListPanel::ReSortList(this);
      this->m_bSortNeeded = false;
    }
    vgui::SectionedListPanel::LayoutPanels(this, contentTall: &this->m_iContentHeight);
  }
  *wide = vgui::Panel::GetWide(this);
  *tall = this->m_iContentHeight;
}

//------------------------------------------------------------------------------
// Address: 0x103CAEE0
// Name: public: virtual bool vgui::SectionedListPanel::AddColumnToSection(int,char const __near *,wchar_t const __near *,int,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::AddColumnToSection(
        vgui::SectionedListPanel *this,
        int sectionID,
        char *columnName,
        const wchar_t *columnText,
        int columnFlags,
        int width,
        unsigned int fallbackFont)
{
  int m_Size; // edx
  int v8; // eax
  vgui::SectionedListPanel::section_t *m_pMemory; // esi
  vgui::SectionedListPanel::section_t *i; // ecx
  int m_szColumnName; // esi

  m_Size = this->m_Sections.m_Size;
  v8 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_iID != sectionID; ++i )
  {
    if ( ++v8 >= m_Size )
      return 0;
  }
  if ( v8 < 0 )
    return 0;
  m_szColumnName = (int)m_pMemory[v8].m_Columns.m_Memory.m_pMemory[CUtlVector<vgui::SectionedListPanel::column_t,CUtlMemory<vgui::SectionedListPanel::column_t,int>>::AddToTail(this: &m_pMemory[v8].m_Columns)].m_szColumnName;
  V_strncpy(pDest: (char *)m_szColumnName, pSrc: columnName, maxLen: 32);
  wcsncpy(dest: (unsigned __int16 *)(m_szColumnName + 32), source: columnText, count: 0x40u);
  *(_WORD *)(m_szColumnName + 158) = 0;
  *(_DWORD *)(m_szColumnName + 164) = width;
  *(_DWORD *)(m_szColumnName + 160) = columnFlags;
  *(_DWORD *)(m_szColumnName + 168) = fallbackFont;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103CAF90
// Name: public: virtual bool vgui::SectionedListPanel::RemoveItem(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::SectionedListPanel::RemoveItem(vgui::SectionedListPanel *this, int itemID)
{
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *p_m_Items; // esi
  int v3; // edi
  int v4; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // ecx

  p_m_Items = (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Items;
  if ( itemID < 0 )
    return 0;
  if ( itemID >= this->m_Items.m_Memory.m_nAllocationCount )
    return 0;
  if ( itemID > this->m_Items.m_LastAlloc.index )
    return 0;
  v3 = itemID;
  v4 = (int)&p_m_Items->m_Memory.m_pMemory[itemID];
  if ( *(_DWORD *)(v4 + 4) == itemID && *(_DWORD *)(v4 + 8) != itemID )
    return 0;
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_SortedItems,
    src: &p_m_Items->m_Memory.m_pMemory[v3].m_Element);
  m_pMemory = p_m_Items->m_Memory.m_pMemory;
  this->m_bSortNeeded = true;
  m_pMemory[v3].m_Element->MarkForDeletion(this: m_pMemory[v3].m_Element);
  CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
    this: p_m_Items,
    elem: itemID);
  p_m_Items->m_Memory.m_pMemory[v3].m_Next = p_m_Items->m_FirstFree;
  p_m_Items->m_FirstFree = itemID;
  this->InvalidateLayout(this, a2: false, a3: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103CB0B0
// Name: public: virtual void vgui::SectionedListPanel::DeleteAllItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::DeleteAllItems(vgui::SectionedListPanel *this)
{
  vgui::SectionedListPanel *v1; // esi
  int m_Head; // edi
  CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int> > *p_m_FreeItems; // ebx
  unsigned int v4; // edi
  vgui::CItemButton *m_Element; // esi
  void (__thiscall *SetPaintBackgroundEnabled)(vgui::Panel *, bool); // eax
  int v7; // eax
  int v8; // esi
  int v9; // ecx
  int m_Tail; // eax

  v1 = this;
  m_Head = this->m_Items.m_Head;
  if ( m_Head != -1 )
  {
    p_m_FreeItems = &this->m_FreeItems;
    do
    {
      v4 = m_Head;
      v1->m_Items.m_Memory.m_pMemory[v4].m_Element->SetVisible(
        this: v1->m_Items.m_Memory.m_pMemory[v4].m_Element,
        a2: false);
      m_Element = v1->m_Items.m_Memory.m_pMemory[v4].m_Element;
      SetPaintBackgroundEnabled = m_Element->SetPaintBackgroundEnabled;
      *(_WORD *)&m_Element->m_bSelected = 0;
      m_Element->m_iSectionID = -1;
      SetPaintBackgroundEnabled(this: m_Element, a2: false);
      m_Element->SetTextImageIndex(this: m_Element, a2: -1);
      m_Element->ClearImages(this: m_Element);
      v7 = CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int>>::AllocInternal(
             this: p_m_FreeItems,
             multilist: false);
      v8 = v7;
      if ( v7 == -1 )
      {
        v8 = -1;
      }
      else
      {
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
          this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)p_m_FreeItems,
          elem: v7);
        v9 = (int)&p_m_FreeItems->m_Memory.m_pMemory[v8];
        *(_DWORD *)(v9 + 8) = -1;
        m_Tail = p_m_FreeItems->m_Tail;
        *(_DWORD *)(v9 + 4) = m_Tail;
        p_m_FreeItems->m_Tail = v8;
        if ( m_Tail == -1 )
          p_m_FreeItems->m_Head = v8;
        else
          p_m_FreeItems->m_Memory.m_pMemory[m_Tail].m_Next = v8;
        ++p_m_FreeItems->m_ElementCount;
      }
      p_m_FreeItems->m_Memory.m_pMemory[v8].m_Element = this->m_Items.m_Memory.m_pMemory[v4].m_Element;
      m_Head = this->m_Items.m_Memory.m_pMemory[v4].m_Next;
      v1 = this;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&v1->m_Items);
  v1->m_SortedItems.m_Size = 0;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &v1->m_hSelectedItem, pPanel: nullptr);
  v1->InvalidateLayout(this: v1, a2: false, a3: false);
  v1->m_bSortNeeded = true;
}

//------------------------------------------------------------------------------
// Address: 0x103CB1F0
// Name: private: int vgui::SectionedListPanel::GetNewItemButton(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetNewItemButton(vgui::SectionedListPanel *this)
{
  int v2; // eax
  int v3; // edi
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v4; // ecx
  int m_Tail; // eax
  int m_Head; // esi
  vgui::CItemButton *v8; // eax
  vgui::CItemButton *v9; // [esp+10h] [ebp-4h]

  v2 = CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int>>::AllocInternal(
         this: &this->m_Items,
         multilist: false);
  v3 = v2;
  if ( v2 == -1 )
  {
    v3 = -1;
  }
  else
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Items,
      elem: v2);
    v4 = &this->m_Items.m_Memory.m_pMemory[v3];
    v4->m_Next = -1;
    m_Tail = this->m_Items.m_Tail;
    v4->m_Previous = m_Tail;
    this->m_Items.m_Tail = v3;
    if ( m_Tail == -1 )
      this->m_Items.m_Head = v3;
    else
      this->m_Items.m_Memory.m_pMemory[m_Tail].m_Next = v3;
    ++this->m_Items.m_ElementCount;
  }
  if ( this->m_FreeItems.m_ElementCount != 0 )
  {
    this->m_Items.m_Memory.m_pMemory[v3].m_Element = this->m_FreeItems.m_Memory.m_pMemory[this->m_FreeItems.m_Head].m_Element;
    this->m_Items.m_Memory.m_pMemory[v3].m_Element->m_iID = v3;
    this->m_Items.m_Memory.m_pMemory[v3].m_Element->SetVisible(
      this: this->m_Items.m_Memory.m_pMemory[v3].m_Element,
      a2: true);
    m_Head = this->m_FreeItems.m_Head;
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_FreeItems,
      elem: m_Head);
    this->m_FreeItems.m_Memory.m_pMemory[m_Head].m_Next = this->m_FreeItems.m_FirstFree;
    this->m_FreeItems.m_FirstFree = m_Head;
    return v3;
  }
  else
  {
    v8 = (vgui::CItemButton *)MemAlloc_Alloc(nSize: 0x1ECu);
    if ( v8 != nullptr )
    {
      v9 = vgui::CItemButton::CItemButton(this: v8, parent: this, itemID: v3);
      vgui::Panel::MakeReadyForUse(this: v9);
    }
    else
    {
      v9 = nullptr;
      vgui::Panel::MakeReadyForUse(this: nullptr);
    }
    this->m_Items.m_Memory.m_pMemory[v3].m_Element = v9;
    this->m_Items.m_Memory.m_pMemory[v3].m_Element->m_bShowColumns = this->m_bShowColumns;
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CB400
// Name: public: virtual void vgui::SectionedListPanel::RemoveAllSections(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::RemoveAllSections(vgui::SectionedListPanel *this)
{
  int m_Size; // eax
  int v3; // edi
  int v4; // ebx
  vgui::CSectionHeader *m_pHeader; // ecx
  vgui::CSectionHeader *v6; // ecx

  m_Size = this->m_Sections.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    v4 = 0;
    do
    {
      if ( v3 >= 0 && v3 < m_Size )
      {
        m_pHeader = this->m_Sections.m_Memory.m_pMemory[v4].m_pHeader;
        m_pHeader->SetVisible(this: m_pHeader, a2: false);
        v6 = this->m_Sections.m_Memory.m_pMemory[v4].m_pHeader;
        v6->MarkForDeletion(this: v6);
      }
      m_Size = this->m_Sections.m_Size;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::RemoveAll(this: &this->m_Sections);
  CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::RemoveAll(this: &this->m_Sections);
  if ( this->m_Sections.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Sections.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Sections.m_Memory.m_pMemory);
      this->m_Sections.m_Memory.m_pMemory = nullptr;
    }
    this->m_Sections.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Sections.m_pElements = this->m_Sections.m_Memory.m_pMemory;
  this->m_SortedItems.m_Size = 0;
  this->InvalidateLayout(this, a2: false, a3: false);
  vgui::SectionedListPanel::ReSortList(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CB4D0
// Name: public: virtual int vgui::SectionedListPanel::AddItem(int,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::AddItem(vgui::SectionedListPanel *this, int sectionID, const KeyValues *data)
{
  int NewItemButton; // edi

  NewItemButton = vgui::SectionedListPanel::GetNewItemButton(this);
  this->ModifyItem(this, a2: NewItemButton, a3: sectionID, a4: data);
  CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int>>::InsertBefore(
    this: &this->m_SortedItems,
    elem: this->m_SortedItems.m_Size,
    src: &this->m_Items.m_Memory.m_pMemory[NewItemButton].m_Element);
  this->m_bSortNeeded = true;
  return NewItemButton;
}

//------------------------------------------------------------------------------
// Address: 0x103CB590
// Name: public: vgui::SectionedListPanel::SectionedListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::SectionedListPanel *__thiscall vgui::SectionedListPanel::SectionedListPanel(
        vgui::SectionedListPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlLinkedListElem_t<vgui::CItemButton *,int> *m_pMemory; // edx
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v8; // ecx
  vgui::ScrollBar *v9; // eax
  vgui::ScrollBar *v10; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::SectionedListPanel_vtbl *)&vgui::SectionedListPanel::`vftable';
  if ( `vgui::SectionedListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SectionedListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "SectionedListPanel");
    v4->pfnClassName = vgui::SectionedListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::SectionedListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::SectionedListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "SectionedListPanel");
    v5->pfnClassName = vgui::SectionedListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::SectionedListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::SectionedListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "SectionedListPanel");
    v6->pfnClassName = vgui::SectionedListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::SectionedListPanel::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  this->m_hSelectedItem.m_iPanelID = -1;
  this->m_Sections.m_Memory.m_pMemory = nullptr;
  this->m_Sections.m_Memory.m_nAllocationCount = 0;
  this->m_Sections.m_Memory.m_nGrowSize = 0;
  this->m_Sections.m_Size = 0;
  this->m_Sections.m_pElements = nullptr;
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_LastAlloc.index = -1;
  m_pMemory = this->m_Items.m_Memory.m_pMemory;
  this->m_Items.m_Head = -1;
  this->m_Items.m_Tail = -1;
  this->m_Items.m_FirstFree = -1;
  this->m_Items.m_ElementCount = 0;
  this->m_Items.m_NumAlloced = 0;
  this->m_Items.m_pElements = m_pMemory;
  this->m_FreeItems.m_Memory.m_pMemory = nullptr;
  this->m_FreeItems.m_Memory.m_nAllocationCount = 0;
  this->m_FreeItems.m_Memory.m_nGrowSize = 0;
  this->m_FreeItems.m_LastAlloc.index = -1;
  v8 = this->m_FreeItems.m_Memory.m_pMemory;
  this->m_FreeItems.m_Head = -1;
  this->m_FreeItems.m_Tail = -1;
  this->m_FreeItems.m_FirstFree = -1;
  this->m_FreeItems.m_ElementCount = 0;
  this->m_FreeItems.m_NumAlloced = 0;
  this->m_FreeItems.m_pElements = v8;
  this->m_SortedItems.m_Memory.m_pMemory = nullptr;
  this->m_SortedItems.m_Memory.m_nAllocationCount = 0;
  this->m_SortedItems.m_Memory.m_nGrowSize = 0;
  this->m_SortedItems.m_Size = 0;
  this->m_SortedItems.m_pElements = nullptr;
  this->m_hEditModePanel.m_iPanelID = -1;
  vgui::SectionedListPanel::PanelAnimationVar_m_bShowColumns::InitVar();
  v9 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v9 != nullptr )
    v10 = vgui::ScrollBar::ScrollBar(this: v9, parent: this, panelName: "SectionedScrollBar", vertical: true);
  else
    v10 = nullptr;
  this->m_pScrollBar = v10;
  v10->SetVisible(this: v10, a2: false);
  this->m_pScrollBar->AddActionSignalTarget_2(this: this->m_pScrollBar, a2: this);
  this->m_iEditModeItemID = 0;
  this->m_iEditModeColumn = 0;
  this->m_pImageList = nullptr;
  this->m_bDeleteImageListWhenDone = false;
  this->m_hHeaderFont = 0;
  this->m_hRowFont = 0;
  this->m_iLineSpacing = 20;
  *(_DWORD *)&this->m_bSortNeeded = 16843008;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103CB7B0
// Name: public: virtual vgui::SectionedListPanel::~SectionedListPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::~SectionedListPanel(vgui::SectionedListPanel *this)
{
  this->__vftable = (vgui::SectionedListPanel_vtbl *)&vgui::SectionedListPanel::`vftable';
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SortedItems);
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_FreeItems);
  if ( this->m_FreeItems.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FreeItems.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FreeItems.m_Memory.m_pMemory);
      this->m_FreeItems.m_Memory.m_pMemory = nullptr;
    }
    this->m_FreeItems.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_Items);
  if ( this->m_Items.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Items.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Items.m_Memory.m_pMemory);
      this->m_Items.m_Memory.m_pMemory = nullptr;
    }
    this->m_Items.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::~CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>(this: &this->m_Sections);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CB860
// Name: public: virtual void vgui::SectionedListPanel::AddSection(int,char const __near *,bool (*)(class vgui::SectionedListPanel __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::AddSection(
        vgui::SectionedListPanel *this,
        int sectionID,
        const char *name,
        bool (__cdecl *sortFunc)(vgui::SectionedListPanel *, int, int))
{
  vgui::CSectionHeader *v5; // eax
  vgui::CSectionHeader *v6; // edi
  int v7; // eax

  v5 = (vgui::CSectionHeader *)MemAlloc_Alloc(nSize: 0x1B4u);
  if ( v5 != nullptr )
    v6 = vgui::CSectionHeader::CSectionHeader(this: v5, parent: this, name, sectionID);
  else
    v6 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v6);
  v7 = CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::InsertBefore(
         this: &this->m_Sections,
         elem: this->m_Sections.m_Size);
  this->m_Sections.m_Memory.m_pMemory[v7].m_iID = sectionID;
  this->m_Sections.m_Memory.m_pMemory[v7].m_pHeader = v6;
  this->m_Sections.m_Memory.m_pMemory[v7].m_pSortFunc = sortFunc;
  this->m_Sections.m_Memory.m_pMemory[v7].m_bAlwaysVisible = false;
}

//------------------------------------------------------------------------------
// Address: 0x103CB8F0
// Name: public: virtual void vgui::SectionedListPanel::AddSection(int,wchar_t const __near *,bool (*)(class vgui::SectionedListPanel __near *,int,int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::AddSection(
        vgui::SectionedListPanel *this,
        int sectionID,
        const wchar_t *name,
        bool (__cdecl *sortFunc)(vgui::SectionedListPanel *, int, int))
{
  vgui::CSectionHeader *v5; // eax
  vgui::CSectionHeader *v6; // edi
  int v7; // eax

  v5 = (vgui::CSectionHeader *)MemAlloc_Alloc(nSize: 0x1B4u);
  if ( v5 != nullptr )
    v6 = vgui::CSectionHeader::CSectionHeader(this: v5, parent: this, name, sectionID);
  else
    v6 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v6);
  v7 = CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::InsertBefore(
         this: &this->m_Sections,
         elem: this->m_Sections.m_Size);
  this->m_Sections.m_Memory.m_pMemory[v7].m_iID = sectionID;
  this->m_Sections.m_Memory.m_pMemory[v7].m_pHeader = v6;
  this->m_Sections.m_Memory.m_pMemory[v7].m_pSortFunc = sortFunc;
  this->m_Sections.m_Memory.m_pMemory[v7].m_bAlwaysVisible = false;
}

//------------------------------------------------------------------------------
// Address: 0x103CB980
// Name: Create_SectionedListPanel
// Source: json
//------------------------------------------------------------------------------
vgui::SectionedListPanel *__cdecl Create_SectionedListPanel()
{
  vgui::SectionedListPanel *v0; // eax

  v0 = (vgui::SectionedListPanel *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::SectionedListPanel::SectionedListPanel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace client
