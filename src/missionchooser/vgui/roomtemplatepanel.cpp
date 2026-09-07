// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/roomtemplatepanel.cpp
// Functions: 16
// ============================================================

#include "missionchooser\vgui\roomtemplatepanel.h"

//------------------------------------------------------------------------------
// Address: 0x1002A920
// Name: public: static char const __near * CRoomTemplatePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRoomTemplatePanel::GetPanelClassName()
{
  return "CRoomTemplatePanel";
}

//------------------------------------------------------------------------------
// Address: 0x1002A930
// Name: public: virtual void CRoomTemplatePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplatePanel::ApplySchemeSettings(CRoomTemplatePanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel_vtbl *v4; // ebx
  vgui::IBorder *v5; // eax
  vgui::Label_vtbl *v6; // ebx
  unsigned int v7; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v4 = this->m_pSelectedOutline->__vftable;
  v5 = pScheme->GetBorder(this: pScheme, a2: "SelectedRoomBorder");
  v4->SetBorder(this: this->m_pSelectedOutline, a2: v5);
  this->m_pSelectedOutline->SetPaintBackgroundEnabled(this: this->m_pSelectedOutline, a2: false);
  this->m_pTagsLabel->SetPaintBackgroundEnabled(this: this->m_pTagsLabel, a2: false);
  v6 = this->m_pTagsLabel->__vftable;
  v7 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  v6->SetFont(this: this->m_pTagsLabel, a2: v7);
  if ( this->m_bRoomTemplateBrowserMode )
  {
    if ( g_pTileGenDialog != nullptr && g_pTileGenDialog->m_pCursorTemplate == this->m_pRoomTemplate )
      this->m_pSelectedOutline->SetVisible(this: this->m_pSelectedOutline, a2: true);
    else
      this->m_pSelectedOutline->SetVisible(this: this->m_pSelectedOutline, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AA10
// Name: public: class vgui::Menu __near * vgui::DHANDLE<class vgui::Menu>::Get(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
vgui::Menu *__thiscall vgui::DHANDLE<vgui::Menu>::Get(vgui::DHANDLE<vgui::Menu> *this)
{
  return (vgui::Menu *)vgui::PHandle::Get(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002AA20
// Name: public: class vgui::Menu __near * vgui::DHANDLE<class vgui::Menu>::operator=(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::DHANDLE<vgui::Menu>::operator=(vgui::DHANDLE<vgui::Menu> *this, vgui::Menu *pPanel)
{
  return (vgui::Menu *)vgui::DHANDLE<CDragDropHelperPanel>::operator=(this, pPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1002AA30
// Name: public: virtual void CRoomTemplatePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplatePanel::PerformLayout(CRoomTemplatePanel *this)
{
  int m_fTileSize; // edi
  int Wide; // eax
  int v4; // eax
  const CRoomTemplate *m_pRoomTemplate; // eax
  int v6; // ecx
  int m_nTilesX; // eax
  int v8; // ebx
  int v9; // eax
  const CRoomTemplate *v10; // eax
  int i; // ebx
  CRoomTemplateExit *v12; // eax
  int Tall; // [esp-Ch] [ebp-1Ch]
  int v14; // [esp-Ch] [ebp-1Ch]
  int y; // [esp+4h] [ebp-Ch]
  int v16; // [esp+8h] [ebp-8h]
  int x; // [esp+Ch] [ebp-4h]

  vgui::Panel::PerformLayout(this);
  if ( this->m_pRoomTemplate != nullptr && g_pTileGenDialog != nullptr )
  {
    m_fTileSize = (int)g_pTileGenDialog->m_fTileSize;
    vgui::Panel::SetSize(
      this,
      wide: m_fTileSize * this->m_pRoomTemplate->m_nTilesX,
      tall: m_fTileSize * this->m_pRoomTemplate->m_nTilesY);
    Tall = vgui::Panel::GetTall(this);
    Wide = vgui::Panel::GetWide(this);
    vgui::Panel::SetBounds(this: this->m_pRoomTGAPanel, x: 0, y: 0, wide: Wide, tall: Tall);
    v14 = vgui::Panel::GetTall(this);
    v4 = vgui::Panel::GetWide(this);
    vgui::Panel::SetBounds(this: this->m_pSelectedOutline, x: 0, y: 0, wide: v4, tall: v14);
    m_pRoomTemplate = this->m_pRoomTemplate;
    v6 = 0;
    y = 0;
    if ( m_pRoomTemplate->m_nTilesY > 0 )
    {
      v16 = 0;
      do
      {
        m_nTilesX = m_pRoomTemplate->m_nTilesX;
        v8 = 0;
        if ( m_nTilesX > 0 )
        {
          x = 0;
          do
          {
            v9 = v8 + v6 * m_nTilesX;
            if ( this->m_pGridImagePanels.m_Size > v9 )
            {
              vgui::Panel::SetBounds(
                this: this->m_pGridImagePanels.m_Memory.m_pMemory[v9],
                x,
                y: v16,
                wide: m_fTileSize,
                tall: m_fTileSize);
              v6 = y;
            }
            m_nTilesX = this->m_pRoomTemplate->m_nTilesX;
            x += m_fTileSize;
            ++v8;
          }
          while ( v8 < m_nTilesX );
        }
        m_pRoomTemplate = this->m_pRoomTemplate;
        v16 += m_fTileSize;
        y = ++v6;
      }
      while ( v6 < m_pRoomTemplate->m_nTilesY );
    }
    v10 = this->m_pRoomTemplate;
    for ( i = 0; i < v10->m_Exits.m_Size; ++i )
    {
      v12 = v10->m_Exits.m_Memory.m_pMemory[i];
      if ( v12 != nullptr && this->m_pExitImagePanels.m_Size > i )
        vgui::Panel::SetBounds(
          this: this->m_pExitImagePanels.m_Memory.m_pMemory[i],
          x: m_fTileSize * v12->m_iXPos,
          y: m_fTileSize * v12->m_iYPos,
          wide: m_fTileSize,
          tall: m_fTileSize);
      v10 = this->m_pRoomTemplate;
    }
    this->m_pTagsLabel->SizeToContents(this: this->m_pTagsLabel);
    vgui::Panel::SetPos(this: this->m_pTagsLabel, x: 4, y: 0);
    this->m_pTagsLabel->InvalidateLayout(this: this->m_pTagsLabel, a2: true, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ABD0
// Name: public: virtual void CRoomTemplatePanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplatePanel::OnMouseReleased(CRoomTemplatePanel *this, int code)
{
  int v3; // ecx
  vgui::Panel *v4; // eax
  int m_fTileSize; // ecx
  int v6; // ebx
  vgui::Panel *v7; // esi
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  int v10; // ecx
  _DWORD *v11; // edx
  _DWORD *v12; // eax
  vgui::Menu *v13; // eax
  vgui::Menu *v14; // ebx
  vgui::Menu *v15; // eax
  vgui::Menu *v16; // edi
  vgui::Menu *v17; // eax
  vgui::Menu *v18; // esi
  vgui::MessageBox *v19; // eax
  vgui::MessageBox *v20; // eax
  CRoomTemplateEditDialog *v21; // esi
  CRoomTemplate *Room; // eax
  CRoomTemplateEditDialog *v23; // esi
  vgui::DHANDLE<vgui::Menu> *p_m_hMenu; // [esp+Ch] [ebp-28h]
  int iTileY; // [esp+10h] [ebp-24h]
  vgui::Panel *parent; // [esp+18h] [ebp-1Ch]
  int iTileX; // [esp+1Ch] [ebp-18h]
  int rx; // [esp+20h] [ebp-14h] BYREF
  int ry; // [esp+24h] [ebp-10h] BYREF
  int mx; // [esp+28h] [ebp-Ch] BYREF
  int my; // [esp+2Ch] [ebp-8h] BYREF
  bool bHasWestExit; // [esp+31h] [ebp-3h]
  bool bHasSouthExit; // [esp+32h] [ebp-2h]
  bool bHasEastExit; // [esp+33h] [ebp-1h]
  char bHasNorthExit_3; // [esp+3Fh] [ebp+Bh]

  if ( this->m_bRoomTemplateEditMode && code == 108 )
  {
    ry = 0;
    rx = 0;
    vgui::Panel::LocalToScreen(this, x: &rx, y: &ry);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
    v3 = my - ry;
    mx -= rx;
    my -= ry;
    if ( mx >= 0 && v3 >= 0 )
    {
      p_m_hMenu = &this->m_hMenu;
      if ( vgui::PHandle::Get(this: &this->m_hMenu) != nullptr )
      {
        v4 = vgui::PHandle::Get(this: &this->m_hMenu);
        v4->MarkForDeletion(this: v4);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hMenu, pPanel: nullptr);
      }
      m_fTileSize = (int)g_pTileGenDialog->m_fTileSize;
      iTileX = mx / m_fTileSize;
      v6 = my / m_fTileSize;
      iTileY = my / m_fTileSize;
      v7 = this->GetParent(this);
      parent = v7;
      v8 = __RTDynamicCast(
             inptr: v7,
             VfDelta: 0,
             SrcType: &vgui::Panel `RTTI Type Descriptor',
             TargetType: &CRoomTemplateEditDialog `RTTI Type Descriptor',
             isReference: 0);
      if ( v8 != nullptr )
      {
        v8[150] = iTileX;
        v8[151] = v6;
        v9 = (_DWORD *)v8[152];
        v10 = v9[3] - 1;
        bHasNorthExit_3 = 0;
        bHasEastExit = false;
        bHasSouthExit = false;
        bHasWestExit = false;
        if ( v10 >= 0 )
        {
          v11 = (_DWORD *)(*v9 + 4 * v10);
          do
          {
            v12 = (_DWORD *)*v11;
            if ( *(_DWORD *)*v11 == iTileX && v12[1] == iTileY )
            {
              switch ( v12[2] )
              {
                case 0:
                  bHasNorthExit_3 = 1;
                  break;
                case 1:
                  bHasEastExit = true;
                  break;
                case 2:
                  bHasSouthExit = true;
                  break;
                case 3:
                  bHasWestExit = true;
                  break;
                default:
                  break;
              }
            }
            --v11;
            --v10;
          }
          while ( v10 >= 0 );
        }
        v13 = (vgui::Menu *)operator new(nSize: 0x420u);
        if ( v13 != nullptr )
          v14 = vgui::Menu::Menu(this: v13, parent: this, panelName: "EditExitMenu");
        else
          v14 = nullptr;
        if ( bHasNorthExit_3 != 0 )
          v14->AddMenuItem(this: v14, a2: "North exit", a3: "EditExitNorth", a4: v7, a5: nullptr);
        if ( bHasEastExit )
          v14->AddMenuItem(this: v14, a2: "East exit", a3: "EditExitEast", a4: v7, a5: nullptr);
        if ( bHasSouthExit )
          v14->AddMenuItem(this: v14, a2: "South exit", a3: "EditExitSouth", a4: v7, a5: nullptr);
        if ( bHasWestExit )
          v14->AddMenuItem(this: v14, a2: "West exit", a3: "EditExitWest", a4: v7, a5: nullptr);
        v15 = (vgui::Menu *)operator new(nSize: 0x420u);
        if ( v15 != nullptr )
          v16 = vgui::Menu::Menu(this: v15, parent: this, panelName: "AddExitMenu");
        else
          v16 = nullptr;
        if ( bHasNorthExit_3 == 0 )
          v16->AddMenuItem(this: v16, a2: "To the north", a3: "AddExitNorth", a4: v7, a5: nullptr);
        if ( !bHasEastExit )
          v16->AddMenuItem(this: v16, a2: "To the east", a3: "AddExitEast", a4: v7, a5: nullptr);
        if ( !bHasSouthExit )
          v16->AddMenuItem(this: v16, a2: "To the south", a3: "AddExitSouth", a4: v7, a5: nullptr);
        if ( !bHasWestExit )
          v16->AddMenuItem(this: v16, a2: "To the west", a3: "AddExitWest", a4: v7, a5: nullptr);
        v17 = (vgui::Menu *)operator new(nSize: 0x420u);
        if ( v17 != nullptr )
          v18 = vgui::Menu::Menu(this: v17, parent: this, panelName: "RightClickMenu");
        else
          v18 = nullptr;
        v18->AddMenuItem(
          this: v18,
          a2: "Clear all exits from this tile",
          a3: "ClearExitsFromTile",
          a4: parent,
          a5: nullptr);
        v18->AddMenuItem(
          this: v18,
          a2: "Clear all exits from this room template",
          a3: "ClearAllExits",
          a4: parent,
          a5: nullptr);
        v18->AddCascadingMenuItem(
          this: v18,
          a2: "AddExit",
          a3: "Add exit to this tile...",
          a4: szDescription,
          a5: this,
          a6: v16,
          a7: nullptr);
        v18->AddCascadingMenuItem(
          this: v18,
          a2: "EditExit",
          a3: "Exit properties...",
          a4: szDescription,
          a5: this,
          a6: v14,
          a7: nullptr);
        vgui::Panel::SetPos(this: v18, x: rx + mx, y: ry + my);
        v18->SetVisible(this: v18, a2: true);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_hMenu, pPanel: v18);
      }
      else
      {
        v19 = (vgui::MessageBox *)operator new(nSize: 0x234u);
        if ( v19 != nullptr )
        {
          v20 = vgui::MessageBox::MessageBox(
                  this: v19,
                  title: "Error",
                  text: "Couldn't cast RoomTemplatePanel's parent to RoomTemplateEditDialog",
                  parent: this);
          v20->DoModal_2(this: v20, a2: nullptr);
        }
        else
        {
          (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
        }
      }
    }
  }
  else
  {
    if ( this->m_bRoomTemplateBrowserMode )
    {
      if ( code == 107 )
      {
        CTileGenDialog::SetCursorRoomTemplate(this: g_pTileGenDialog, pRoomTemplate: this->m_pRoomTemplate);
        vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: 107);
        return;
      }
      if ( code == 108 && this->m_pRoomTemplate != nullptr )
      {
        v21 = (CRoomTemplateEditDialog *)operator new(nSize: 0x268u);
        if ( v21 != nullptr )
        {
          Room = CLevelTheme::FindRoom(
                   this: this->m_pRoomTemplate->m_pLevelTheme,
                   szRoomTemplate: this->m_pRoomTemplate->m_FullName);
          v23 = CRoomTemplateEditDialog::CRoomTemplateEditDialog(
                  this: v21,
                  parent: g_pTileGenDialog,
                  name: "RoomTemplateEditDialog",
                  pRoomTemplate: Room,
                  bCreatingNew: false);
        }
        else
        {
          v23 = nullptr;
        }
        v23->AddActionSignalTarget_2(this: v23, a2: g_pTileGenDialog);
        v23->DoModal(this: v23);
      }
    }
    vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B060
// Name: public: virtual CRoomTemplatePanel::~CRoomTemplatePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplatePanel::~CRoomTemplatePanel(CRoomTemplatePanel *this)
{
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (CRoomTemplatePanel_vtbl *)&CRoomTemplatePanel::`vftable';
  src = (vgui::TreeNode *)this;
  CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_pRoomTemplatePanels,
    &src);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_pExitImagePanels);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_pGridImagePanels);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002B0A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CRoomTemplatePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRoomTemplatePanel::GetMessageMap(CRoomTemplatePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRoomTemplatePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRoomTemplatePanel::GetMessageMap'::`2'::s_pMap;
  `CRoomTemplatePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplatePanel");
  `CRoomTemplatePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B0D0
// Name: public: virtual struct PanelAnimationMap __near * CRoomTemplatePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRoomTemplatePanel::GetAnimMap(CRoomTemplatePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CRoomTemplatePanel");
}

//------------------------------------------------------------------------------
// Address: 0x1002B0E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRoomTemplatePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRoomTemplatePanel::GetKBMap(CRoomTemplatePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRoomTemplatePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRoomTemplatePanel::GetKBMap'::`2'::s_pMap;
  `CRoomTemplatePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRoomTemplatePanel");
  `CRoomTemplatePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B110
// Name: public: CRoomTemplatePanel::CRoomTemplatePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRoomTemplatePanel *__thiscall CRoomTemplatePanel::CRoomTemplatePanel(
        CRoomTemplatePanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CMissionChooserTGAImagePanel *v7; // eax
  CMissionChooserTGAImagePanel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Label *v11; // eax
  vgui::Label *v12; // eax
  int m_Size; // eax
  int v14; // edi
  CRoomTemplatePanel **m_pMemory; // ecx
  int v16; // eax
  CRoomTemplatePanel **v17; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CRoomTemplatePanel_vtbl *)&CRoomTemplatePanel::`vftable';
  if ( `CRoomTemplatePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CRoomTemplatePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplatePanel");
    v4->pfnClassName = CRoomTemplatePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CRoomTemplatePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRoomTemplatePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CRoomTemplatePanel");
    v5->pfnClassName = CRoomTemplatePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CRoomTemplatePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRoomTemplatePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CRoomTemplatePanel");
    v6->pfnClassName = CRoomTemplatePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_pGridImagePanels.m_Memory.m_pMemory = nullptr;
  this->m_pGridImagePanels.m_Memory.m_nAllocationCount = 0;
  this->m_pGridImagePanels.m_Memory.m_nGrowSize = 0;
  this->m_pGridImagePanels.m_Size = 0;
  this->m_pGridImagePanels.m_pElements = nullptr;
  this->m_pExitImagePanels.m_Memory.m_pMemory = nullptr;
  this->m_pExitImagePanels.m_Memory.m_nAllocationCount = 0;
  this->m_pExitImagePanels.m_Memory.m_nGrowSize = 0;
  this->m_pExitImagePanels.m_Size = 0;
  this->m_pExitImagePanels.m_pElements = nullptr;
  this->m_hMenu.m_iPanelID = -1;
  this->m_pRoomTemplate = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hMenu, pPanel: nullptr);
  v7 = (CMissionChooserTGAImagePanel *)operator new(nSize: 0x258u);
  if ( v7 != nullptr )
    v8 = CMissionChooserTGAImagePanel::CMissionChooserTGAImagePanel(this: v7, parent: this, name: "RoomTGAPanel");
  else
    v8 = nullptr;
  this->m_pRoomTGAPanel = v8;
  v8->SetMouseInputEnabled(this: v8, a2: false);
  v9 = (vgui::Panel *)operator new(nSize: 0x14Cu);
  if ( v9 != nullptr )
    v10 = vgui::Panel::Panel(this: v9, parent: this, panelName: "SelectedBorder");
  else
    v10 = nullptr;
  this->m_pSelectedOutline = v10;
  v10->SetVisible(this: v10, a2: false);
  this->m_pSelectedOutline->SetMouseInputEnabled(this: this->m_pSelectedOutline, a2: false);
  vgui::Panel::SetZPos(this: this->m_pSelectedOutline, z: 10);
  this->m_iLastTilesX = -1;
  this->m_iLastTilesY = -1;
  *(_WORD *)&this->m_bRoomTemplateEditMode = 0;
  *(_WORD *)&this->m_bForceShowExits = 0;
  v11 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v11 != nullptr )
    v12 = vgui::Label::Label(this: v11, parent: this, panelName: "TagsLabel", text: szDescription);
  else
    v12 = nullptr;
  this->m_pTagsLabel = v12;
  v12->SetMouseInputEnabled(this: v12, a2: false);
  this->m_pTagsLabel->SetContentAlignment(this: this->m_pTagsLabel, a2: a_northwest);
  vgui::Panel::SetZPos(this: this->m_pTagsLabel, z: 2);
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  m_Size = g_pRoomTemplatePanels.m_Size;
  v14 = g_pRoomTemplatePanels.m_Size;
  if ( g_pRoomTemplatePanels.m_Size + 1 > g_pRoomTemplatePanels.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_pRoomTemplatePanels,
      num: g_pRoomTemplatePanels.m_Size - g_pRoomTemplatePanels.m_Memory.m_nAllocationCount + 1);
    m_Size = g_pRoomTemplatePanels.m_Size;
  }
  m_pMemory = g_pRoomTemplatePanels.m_Memory.m_pMemory;
  g_pRoomTemplatePanels.m_Size = m_Size + 1;
  v16 = m_Size - v14;
  g_pRoomTemplatePanels.m_pElements = g_pRoomTemplatePanels.m_Memory.m_pMemory;
  if ( v16 > 0 )
  {
    _V_memmove(
      dest: &g_pRoomTemplatePanels.m_Memory.m_pMemory[v14 + 1],
      src: &g_pRoomTemplatePanels.m_Memory.m_pMemory[v14],
      count: 4 * v16);
    m_pMemory = g_pRoomTemplatePanels.m_Memory.m_pMemory;
  }
  v17 = &m_pMemory[v14];
  if ( v17 != nullptr )
    *v17 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002B3F0
// Name: public: void CRoomTemplatePanel::UpdateImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplatePanel::UpdateImages(CRoomTemplatePanel *this)
{
  CMissionChooserTGAImagePanel *v2; // edi
  int j; // esi
  CMissionChooserTGAImagePanel *v4; // ecx
  const CRoomTemplate *m_pRoomTemplate; // eax
  const char *m_szName; // ecx
  const CRoomTemplate *v7; // eax
  int v8; // esi
  CMissionChooserTGAImagePanel *v9; // ecx
  CMissionChooserTGAImagePanel *v10; // ecx
  const CRoomTemplate *v11; // ecx
  CMissionChooserTGAImagePanel *v12; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CMissionChooserTGAImagePanel **m_pMemory; // ecx
  int v16; // eax
  CMissionChooserTGAImagePanel **v17; // edi
  CRoomTemplateExit *v18; // edi
  CMissionChooserTGAImagePanel *v19; // eax
  CMissionChooserTGAImagePanel *v20; // esi
  ExitDirection_t m_ExitDirection; // eax
  __int32 v22; // eax
  int v23; // esi
  int v24; // eax
  CMissionChooserTGAImagePanel **v25; // ecx
  int v26; // eax
  CMissionChooserTGAImagePanel **v27; // esi
  char buffer[260]; // [esp+Ch] [ebp-110h] BYREF
  int iExits; // [esp+110h] [ebp-Ch]
  int i; // [esp+114h] [ebp-8h]
  CMissionChooserTGAImagePanel *pExitImagePanel; // [esp+118h] [ebp-4h]

  v2 = nullptr;
  for ( j = 0; j < this->m_pExitImagePanels.m_Size; ++j )
  {
    v4 = this->m_pExitImagePanels.m_Memory.m_pMemory[j];
    v4->MarkForDeletion(this: v4);
  }
  this->m_pExitImagePanels.m_Size = 0;
  m_pRoomTemplate = this->m_pRoomTemplate;
  buffer[0] = 0;
  if ( m_pRoomTemplate != nullptr )
  {
    m_szName = m_pRoomTemplate->m_pLevelTheme->m_szName;
    if ( m_szName != nullptr )
      V_snprintf(
        pDest: buffer,
        maxLen: 260,
        pFormat: "tilegen/roomtemplates/%s/%s.tga",
        m_szName,
        m_pRoomTemplate->m_FullName);
  }
  CMissionChooserTGAImagePanel::SetTGA(this: this->m_pRoomTGAPanel, filename: buffer, pPathID: nullptr);
  v7 = this->m_pRoomTemplate;
  if ( v7 != nullptr && v7->m_pLevelTheme != nullptr )
  {
    this->m_iLastTilesX = v7->m_nTilesX;
    v8 = 0;
    for ( this->m_iLastTilesY = v7->m_nTilesY; v8 < this->m_pGridImagePanels.m_Size; ++v8 )
    {
      v9 = this->m_pGridImagePanels.m_Memory.m_pMemory[v8];
      v9->SetVisible(this: v9, a2: false);
      v10 = this->m_pGridImagePanels.m_Memory.m_pMemory[v8];
      v10->MarkForDeletion(this: v10);
    }
    this->m_pGridImagePanels.m_Size = 0;
    if ( g_pTileGenDialog->m_bShowTileSquares || this->m_bForceShowTileSquares )
    {
      v11 = this->m_pRoomTemplate;
      if ( v11->m_nTilesX * v11->m_nTilesY > 0 )
      {
        i = v11->m_nTilesX * v11->m_nTilesY;
        do
        {
          v12 = (CMissionChooserTGAImagePanel *)operator new(nSize: 0x258u);
          if ( v12 != nullptr )
          {
            v2 = CMissionChooserTGAImagePanel::CMissionChooserTGAImagePanel(
                   this: v12,
                   parent: this,
                   name: "GridImagePanel");
            pExitImagePanel = v2;
          }
          else
          {
            pExitImagePanel = nullptr;
          }
          v2->SetMouseInputEnabled(this: v2, a2: false);
          CMissionChooserTGAImagePanel::SetTGA(
            this: v2,
            filename: "tilegen/roomtemplates/gridsquare.tga",
            pPathID: nullptr);
          m_Size = this->m_pGridImagePanels.m_Size;
          m_nAllocationCount = this->m_pGridImagePanels.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pGridImagePanels,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_pGridImagePanels.m_Size;
          m_pMemory = this->m_pGridImagePanels.m_Memory.m_pMemory;
          v16 = this->m_pGridImagePanels.m_Size - m_Size - 1;
          this->m_pGridImagePanels.m_pElements = m_pMemory;
          if ( v16 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v16);
          v17 = &this->m_pGridImagePanels.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = pExitImagePanel;
          v2 = nullptr;
          --i;
        }
        while ( i != 0 );
      }
    }
    if ( g_pTileGenDialog->m_bShowExits || this->m_bForceShowExits )
    {
      iExits = this->m_pRoomTemplate->m_Exits.m_Size;
      for ( i = 0; i < iExits; ++i )
      {
        v18 = this->m_pRoomTemplate->m_Exits.m_Memory.m_pMemory[i];
        v19 = (CMissionChooserTGAImagePanel *)operator new(nSize: 0x258u);
        if ( v19 != nullptr )
        {
          v20 = CMissionChooserTGAImagePanel::CMissionChooserTGAImagePanel(
                  this: v19,
                  parent: this,
                  name: "ExitImagePanel");
          pExitImagePanel = v20;
        }
        else
        {
          pExitImagePanel = nullptr;
          v20 = nullptr;
        }
        v20->SetMouseInputEnabled(this: v20, a2: false);
        m_ExitDirection = v18->m_ExitDirection;
        if ( m_ExitDirection != EXITDIR_BEGIN )
        {
          v22 = m_ExitDirection - 1;
          if ( v22 != 0 )
          {
            if ( v22 == 1 )
              CMissionChooserTGAImagePanel::SetTGA(
                this: v20,
                filename: "tilegen/roomtemplates/exitsouth.tga",
                pPathID: nullptr);
            else
              CMissionChooserTGAImagePanel::SetTGA(
                this: v20,
                filename: "tilegen/roomtemplates/exitwest.tga",
                pPathID: nullptr);
          }
          else
          {
            CMissionChooserTGAImagePanel::SetTGA(
              this: v20,
              filename: "tilegen/roomtemplates/exiteast.tga",
              pPathID: nullptr);
          }
        }
        else
        {
          CMissionChooserTGAImagePanel::SetTGA(
            this: v20,
            filename: "tilegen/roomtemplates/exitnorth.tga",
            pPathID: nullptr);
        }
        v23 = this->m_pExitImagePanels.m_Size;
        v24 = this->m_pExitImagePanels.m_Memory.m_nAllocationCount;
        if ( v23 + 1 > v24 )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pExitImagePanels,
            num: v23 - v24 + 1);
        ++this->m_pExitImagePanels.m_Size;
        v25 = this->m_pExitImagePanels.m_Memory.m_pMemory;
        v26 = this->m_pExitImagePanels.m_Size - v23 - 1;
        this->m_pExitImagePanels.m_pElements = v25;
        if ( v26 > 0 )
          _V_memmove(dest: &v25[v23 + 1], src: &v25[v23], count: 4 * v26);
        v27 = &this->m_pExitImagePanels.m_Memory.m_pMemory[v23];
        if ( v27 != nullptr )
          *v27 = pExitImagePanel;
      }
    }
    this->InvalidateLayout(this, a2: true, a3: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B740
// Name: public: static void CRoomTemplatePanel::UpdateAllImages(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CRoomTemplatePanel::UpdateAllImages()
{
  int v0; // edi
  CRoomTemplatePanel *v1; // ebx
  int j; // esi
  CMissionChooserTGAImagePanel *v3; // ecx
  const CRoomTemplate *m_pRoomTemplate; // eax
  const char *m_szName; // ecx
  const CRoomTemplate *v6; // eax
  int v7; // esi
  CMissionChooserTGAImagePanel *v8; // ecx
  CMissionChooserTGAImagePanel *v9; // ecx
  const CRoomTemplate *v10; // ecx
  CMissionChooserTGAImagePanel *v11; // eax
  CMissionChooserTGAImagePanel *v12; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CMissionChooserTGAImagePanel **m_pMemory; // ecx
  int v16; // eax
  CMissionChooserTGAImagePanel **v17; // edi
  CRoomTemplateExit *v18; // edi
  CMissionChooserTGAImagePanel *v19; // eax
  CMissionChooserTGAImagePanel *v20; // esi
  ExitDirection_t m_ExitDirection; // eax
  __int32 v22; // eax
  int v23; // edi
  int v24; // eax
  CMissionChooserTGAImagePanel **v25; // ecx
  int v26; // eax
  CMissionChooserTGAImagePanel **v27; // edi
  char pDest[260]; // [esp+4h] [ebp-118h] BYREF
  int v29; // [esp+108h] [ebp-14h]
  int iCount; // [esp+10Ch] [ebp-10h]
  int i; // [esp+110h] [ebp-Ch]
  int k; // [esp+114h] [ebp-8h]
  CMissionChooserTGAImagePanel *v33; // [esp+118h] [ebp-4h]

  v0 = 0;
  iCount = g_pRoomTemplatePanels.m_Size;
  for ( i = 0; v0 < iCount; i = v0 )
  {
    v1 = g_pRoomTemplatePanels.m_Memory.m_pMemory[v0];
    if ( v1 != nullptr )
    {
      for ( j = 0; j < v1->m_pExitImagePanels.m_Size; ++j )
      {
        v3 = v1->m_pExitImagePanels.m_Memory.m_pMemory[j];
        v3->MarkForDeletion(this: v3);
      }
      v1->m_pExitImagePanels.m_Size = 0;
      m_pRoomTemplate = v1->m_pRoomTemplate;
      pDest[0] = 0;
      if ( m_pRoomTemplate != nullptr )
      {
        m_szName = m_pRoomTemplate->m_pLevelTheme->m_szName;
        if ( m_szName != nullptr )
          V_snprintf(
            pDest,
            maxLen: 260,
            pFormat: "tilegen/roomtemplates/%s/%s.tga",
            m_szName,
            m_pRoomTemplate->m_FullName);
      }
      CMissionChooserTGAImagePanel::SetTGA(this: v1->m_pRoomTGAPanel, filename: pDest, pPathID: nullptr);
      v6 = v1->m_pRoomTemplate;
      if ( v6 != nullptr && v6->m_pLevelTheme != nullptr )
      {
        v1->m_iLastTilesX = v6->m_nTilesX;
        v7 = 0;
        for ( v1->m_iLastTilesY = v6->m_nTilesY; v7 < v1->m_pGridImagePanels.m_Size; ++v7 )
        {
          v8 = v1->m_pGridImagePanels.m_Memory.m_pMemory[v7];
          v8->SetVisible(this: v8, a2: false);
          v9 = v1->m_pGridImagePanels.m_Memory.m_pMemory[v7];
          v9->MarkForDeletion(this: v9);
        }
        v1->m_pGridImagePanels.m_Size = 0;
        if ( g_pTileGenDialog->m_bShowTileSquares || v1->m_bForceShowTileSquares )
        {
          v10 = v1->m_pRoomTemplate;
          if ( v10->m_nTilesX * v10->m_nTilesY > 0 )
          {
            k = v10->m_nTilesX * v10->m_nTilesY;
            do
            {
              v11 = (CMissionChooserTGAImagePanel *)operator new(nSize: 0x258u);
              if ( v11 != nullptr )
              {
                v12 = CMissionChooserTGAImagePanel::CMissionChooserTGAImagePanel(
                        this: v11,
                        parent: v1,
                        name: "GridImagePanel");
                v33 = v12;
              }
              else
              {
                v33 = nullptr;
                v12 = nullptr;
              }
              v12->SetMouseInputEnabled(this: v12, a2: false);
              CMissionChooserTGAImagePanel::SetTGA(
                this: v12,
                filename: "tilegen/roomtemplates/gridsquare.tga",
                pPathID: nullptr);
              m_Size = v1->m_pGridImagePanels.m_Size;
              m_nAllocationCount = v1->m_pGridImagePanels.m_Memory.m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                  this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_pGridImagePanels,
                  num: m_Size - m_nAllocationCount + 1);
              ++v1->m_pGridImagePanels.m_Size;
              m_pMemory = v1->m_pGridImagePanels.m_Memory.m_pMemory;
              v16 = v1->m_pGridImagePanels.m_Size - m_Size - 1;
              v1->m_pGridImagePanels.m_pElements = m_pMemory;
              if ( v16 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v16);
              v17 = &v1->m_pGridImagePanels.m_Memory.m_pMemory[m_Size];
              if ( v17 != nullptr )
                *v17 = v33;
              --k;
            }
            while ( k != 0 );
          }
        }
        if ( g_pTileGenDialog->m_bShowExits || v1->m_bForceShowExits )
        {
          v29 = v1->m_pRoomTemplate->m_Exits.m_Size;
          for ( k = 0; k < v29; ++k )
          {
            v18 = v1->m_pRoomTemplate->m_Exits.m_Memory.m_pMemory[k];
            v19 = (CMissionChooserTGAImagePanel *)operator new(nSize: 0x258u);
            if ( v19 != nullptr )
            {
              v20 = CMissionChooserTGAImagePanel::CMissionChooserTGAImagePanel(
                      this: v19,
                      parent: v1,
                      name: "ExitImagePanel");
              v33 = v20;
            }
            else
            {
              v33 = nullptr;
              v20 = nullptr;
            }
            v20->SetMouseInputEnabled(this: v20, a2: false);
            m_ExitDirection = v18->m_ExitDirection;
            if ( m_ExitDirection != EXITDIR_BEGIN )
            {
              v22 = m_ExitDirection - 1;
              if ( v22 != 0 )
              {
                if ( v22 == 1 )
                  CMissionChooserTGAImagePanel::SetTGA(
                    this: v20,
                    filename: "tilegen/roomtemplates/exitsouth.tga",
                    pPathID: nullptr);
                else
                  CMissionChooserTGAImagePanel::SetTGA(
                    this: v20,
                    filename: "tilegen/roomtemplates/exitwest.tga",
                    pPathID: nullptr);
              }
              else
              {
                CMissionChooserTGAImagePanel::SetTGA(
                  this: v20,
                  filename: "tilegen/roomtemplates/exiteast.tga",
                  pPathID: nullptr);
              }
            }
            else
            {
              CMissionChooserTGAImagePanel::SetTGA(
                this: v20,
                filename: "tilegen/roomtemplates/exitnorth.tga",
                pPathID: nullptr);
            }
            v23 = v1->m_pExitImagePanels.m_Size;
            v24 = v1->m_pExitImagePanels.m_Memory.m_nAllocationCount;
            if ( v23 + 1 > v24 )
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_pExitImagePanels,
                num: v23 - v24 + 1);
            ++v1->m_pExitImagePanels.m_Size;
            v25 = v1->m_pExitImagePanels.m_Memory.m_pMemory;
            v26 = v1->m_pExitImagePanels.m_Size - v23 - 1;
            v1->m_pExitImagePanels.m_pElements = v25;
            if ( v26 > 0 )
              _V_memmove(dest: &v25[v23 + 1], src: &v25[v23], count: 4 * v26);
            v27 = &v1->m_pExitImagePanels.m_Memory.m_pMemory[v23];
            if ( v27 != nullptr )
              *v27 = v33;
          }
        }
        v1->InvalidateLayout(this: v1, a2: true, a3: true);
        v1->Repaint(this: v1);
        v0 = i;
      }
    }
    ++v0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BAD0
// Name: public: void CRoomTemplatePanel::SetRoomTemplate(class CRoomTemplate const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplatePanel::SetRoomTemplate(CRoomTemplatePanel *this, const CRoomTemplate *pTemplate)
{
  vgui::Tooltip *Tooltip; // eax
  vgui::Tooltip *v4; // eax
  int v5; // esi
  char buffer[2048]; // [esp+8h] [ebp-800h] BYREF

  this->m_pRoomTemplate = pTemplate;
  CRoomTemplatePanel::UpdateImages(this);
  if ( pTemplate != nullptr )
  {
    Tooltip = vgui::Panel::GetTooltip(this);
    vgui::Tooltip::SetText(this: Tooltip, text: pTemplate->m_FullName);
    v4 = vgui::Panel::GetTooltip(this);
    vgui::Tooltip::SetTooltipFormatToSingleLine(this: v4);
    v5 = 0;
    for ( buffer[0] = 0; v5 < pTemplate->m_Tags.m_Size; ++v5 )
      V_snprintf(pDest: buffer, maxLen: 2048, pFormat: "%s\n%s", buffer, pTemplate->m_Tags.m_Memory.m_pMemory[v5]);
    this->m_pTagsLabel->SetText(this: this->m_pTagsLabel, a2: buffer);
  }
  else
  {
    this->m_pTagsLabel->SetText(this: this->m_pTagsLabel, a2: szDescription);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100823D0
// Name: public: vgui::DHANDLE<class vgui::Menu>::operator class vgui::Menu __near *(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(vgui::PHandle *this)
{
  unsigned int v1; // edi
  vgui::IPanel *v2; // esi
  vgui::IPanel_vtbl *v3; // ebx
  const char *ControlsModuleName; // eax

  if ( this->m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: this->m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x10082410
// Name: public: class CDragDropHelperPanel __near * vgui::DHANDLE<class CDragDropHelperPanel>::operator=(class CDragDropHelperPanel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::DHANDLE<CDragDropHelperPanel>::operator=(vgui::PHandle *this, vgui::Panel *pPanel)
{
  vgui::IVGui *v2; // edi
  vgui::IVGui_vtbl *v3; // ebx
  int v4; // eax

  if ( pPanel != nullptr )
  {
    v2 = g_pVGui;
    v3 = g_pVGui->__vftable;
    v4 = pPanel->GetVPanel(this: pPanel);
    this->m_iPanelID = v3->PanelToHandle(this: v2, a2: v4);
    return pPanel;
  }
  else
  {
    this->m_iPanelID = -1;
    return nullptr;
  }
}
