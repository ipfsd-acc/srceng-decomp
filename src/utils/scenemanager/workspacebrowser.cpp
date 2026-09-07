// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/workspacebrowser.cpp
// Functions: 8
// ============================================================

#include "utils\scenemanager\workspacebrowser.h"

//------------------------------------------------------------------------------
// Address: 0x0041A840
// Name: public: static int CWorkspaceBrowser::CompareFunc(long,long,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CWorkspaceBrowser::CompareFunc(unsigned int lParam1, unsigned int lParam2, int lParamSort)
{
  int v3; // eax
  int v4; // ecx

  v3 = *(_DWORD *)(lParam2 + 8);
  v4 = *(_DWORD *)(lParam1 + 8);
  if ( v4 < v3 )
    return -1;
  if ( v4 <= v3 )
    return lParam1 < lParam2 ? -1 : 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A880
// Name: public: CWorkspaceBrowser::CWorkspaceBrowser(class mxWindow __near *,class CWorkspaceManager __near *,int)
// Source: json
//------------------------------------------------------------------------------
CWorkspaceBrowser *__thiscall CWorkspaceBrowser::CWorkspaceBrowser(
        CWorkspaceBrowser *this,
        mxWindow *parent,
        CWorkspaceManager *manager,
        int id)
{
  mxTreeView *v5; // eax
  CBrowserTree *v6; // edi
  CWorkspaceManager *WorkspaceManager; // eax
  _IMAGELIST *ImageList; // eax

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: "Workspace Browser", style: id);
  this->__vftable = (CWorkspaceBrowser_vtbl *)&CWorkspaceBrowser::`vftable';
  this->m_pManager = manager;
  SceneManager_MakeToolWindow(w: this, smallcaption: false);
  this->m_pLastSelected = nullptr;
  this->m_pCurrentWorkspace = nullptr;
  v5 = (mxTreeView *)operator new(nSize: 0xCu);
  v6 = (CBrowserTree *)v5;
  if ( v5 != nullptr )
  {
    mxTreeView::mxTreeView(this: v5, parent: this, x: 0, y: 0, w: 0, h: 0, id: 101);
    v6->__vftable = (CBrowserTree_vtbl *)&CBrowserTree::`vftable';
  }
  else
  {
    v6 = nullptr;
  }
  this->m_pTree = v6;
  WorkspaceManager = GetWorkspaceManager();
  ImageList = CWorkspaceManager::CreateImageList(this: WorkspaceManager);
  mxTreeView::setImageList(this: this->m_pTree, himagelist: ImageList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041A920
// Name: public: void CWorkspaceBrowser::PopulateTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceBrowser::PopulateTree(CWorkspaceBrowser *this)
{
  CWorkspace *m_pCurrentWorkspace; // esi
  int ProjectCount; // eax
  int v4; // eax
  void **Item; // ebx
  int v6; // eax
  int v7; // [esp-8h] [ebp-90h]
  int v8; // [esp-8h] [ebp-90h]
  int v9; // [esp-8h] [ebp-90h]
  char sz[128]; // [esp+8h] [ebp-80h] BYREF

  m_pCurrentWorkspace = this->m_pCurrentWorkspace;
  this->m_pLastSelected = nullptr;
  if ( m_pCurrentWorkspace != nullptr )
  {
    if ( CWorkspace::GetProjectCount(this: m_pCurrentWorkspace) == 1 )
    {
      ProjectCount = CWorkspace::GetProjectCount(this: m_pCurrentWorkspace);
      v7 = ((int (__thiscall *)(CWorkspace *, int))m_pCurrentWorkspace->GetName)(
             a1: m_pCurrentWorkspace,
             a2: ProjectCount);
      V_snprintf(pDest: sz, maxLen: 128, pFormat: "Workspace '%s': %i project", v7);
    }
    else
    {
      v4 = CWorkspace::GetProjectCount(this: m_pCurrentWorkspace);
      v8 = ((int (__thiscall *)(CWorkspace *, int))m_pCurrentWorkspace->GetName)(a1: m_pCurrentWorkspace, a2: v4);
      V_snprintf(pDest: sz, maxLen: 128, pFormat: "Workspace '%s': %i projects", v8);
    }
    Item = ITreeItem::FindItem(this: m_pCurrentWorkspace, tree: this->m_pTree, parent: nullptr, recurse: false);
    if ( Item == nullptr )
      Item = mxTreeView::add(this: this->m_pTree, parent: nullptr, item: sz);
    mxTreeView::setLabel(this: this->m_pTree, item: Item, label: sz);
    v9 = m_pCurrentWorkspace->GetIconIndex(this: m_pCurrentWorkspace);
    v6 = m_pCurrentWorkspace->GetIconIndex(this: m_pCurrentWorkspace);
    mxTreeView::setImages(this: this->m_pTree, item: Item, imagenormal: v6, imageselected: v9);
    mxTreeView::setUserData(this: this->m_pTree, item: Item, userData: m_pCurrentWorkspace);
    CWorkspace::ValidateTree(this: m_pCurrentWorkspace, tree: this->m_pTree, parent: Item);
    mxTreeView::setOpen(this: this->m_pTree, item: Item, b: true);
    mxTreeView::sortTree(
      this: this->m_pTree,
      parent: Item,
      recurse: true,
      func: CWorkspaceBrowser::CompareFunc,
      parameter: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AA20
// Name: public: void CWorkspaceBrowser::SetWorkspace(class CWorkspace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceBrowser::SetWorkspace(CWorkspaceBrowser *this, CWorkspace *w)
{
  this->m_pCurrentWorkspace = w;
  CWorkspaceBrowser::PopulateTree(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA40
// Name: public: void CWorkspaceBrowser::AddProject(class CProject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceBrowser::AddProject(CWorkspaceBrowser *this, CProject *project)
{
  CWorkspace *m_pCurrentWorkspace; // ecx

  m_pCurrentWorkspace = this->m_pCurrentWorkspace;
  if ( m_pCurrentWorkspace != nullptr )
  {
    CWorkspace::AddProject(this: m_pCurrentWorkspace, project);
    CWorkspaceBrowser::PopulateTree(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AA80
// Name: private: void CWorkspaceBrowser::OnTreeItemSelected(int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceBrowser::OnTreeItemSelected(
        CWorkspaceBrowser *this,
        int x,
        int y,
        bool rightmouse,
        bool doubleclick)
{
  void **SelectedItem; // eax
  ITreeItem *UserData; // eax
  ITreeItem *v8; // edi
  CWorkspaceManager *m_pManager; // ecx
  HWND Handle; // eax
  tagPOINT pt; // [esp+4h] [ebp-8h] BYREF

  SelectedItem = mxTreeView::getSelectedItem(this: this->m_pTree);
  if ( SelectedItem != nullptr )
  {
    UserData = (ITreeItem *)mxTreeView::getUserData(this: this->m_pTree, item: SelectedItem);
    v8 = UserData;
    if ( UserData != nullptr )
    {
      m_pManager = this->m_pManager;
      this->m_pLastSelected = UserData;
      CWorkspaceManager::UpdateMenus(this: m_pManager);
      if ( v8->GetSoundEntry(this: v8) != nullptr || v8->GetWaveFile(this: v8) != nullptr )
        CWorkspaceManager::OnSoundShowInBrowsers(this: this->m_pManager);
      if ( rightmouse )
      {
        GetCursorPos(lpPoint: &pt);
        Handle = (HWND)mxWidget::getHandle(this: this->m_pManager);
        ScreenToClient(hWnd: Handle, lpPoint: &pt);
        CWorkspaceManager::ShowContextMenu(this: this->m_pManager, x: pt.x, y: pt.y, p: this->m_pLastSelected);
      }
      else if ( doubleclick )
      {
        CWorkspaceManager::OnDoubleClicked(this: this->m_pManager, item: this->m_pLastSelected);
      }
    }
    else
    {
      Con_Printf(fmt: "No userdata for item\n");
    }
  }
  else
  {
    Con_Printf(fmt: "No item selected\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AB60
// Name: public: void CWorkspaceBrowser::JumpTo(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceBrowser::JumpTo(CWorkspaceBrowser *this, ITreeItem *item)
{
  void **v3; // eax

  v3 = ITreeItem::FindItem(this: item, tree: this->m_pTree, parent: nullptr, recurse: true);
  if ( v3 != nullptr )
    mxTreeView::scrollTo(this: this->m_pTree, item: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0041ABC0
// Name: public: virtual int CWorkspaceBrowser::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWorkspaceBrowser::handleEvent(CWorkspaceBrowser *this, mxEvent *event)
{
  int v3; // edx
  BOOL result; // eax
  int v5; // edx
  int v6; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  int v8; // [esp-4h] [ebp-8h]

  v3 = event->event;
  result = false;
  if ( v3 != 0 )
  {
    v5 = v3 - 1;
    if ( v5 != 0 )
    {
      return v5 == 18;
    }
    else
    {
      v8 = mxWidget::h2(this);
      v6 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_pTree, x: 0, y: 0, w: v6, h: v8);
      WorkspaceManager = GetWorkspaceManager();
      CWorkspaceManager::SetWorkspaceDirty(this: WorkspaceManager);
      return true;
    }
  }
  else if ( event->action == 101 )
  {
    CWorkspaceBrowser::OnTreeItemSelected(
      this,
      x: event->x,
      y: event->y,
      rightmouse: event->flags == 1,
      doubleclick: event->flags == 2);
    return true;
  }
  return result;
}
