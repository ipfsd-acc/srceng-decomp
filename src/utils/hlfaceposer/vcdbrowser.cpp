// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/vcdbrowser.cpp
// Functions: 26
// ============================================================

#include "utils\hlfaceposer\vcdbrowser.h"

//------------------------------------------------------------------------------
// Address: 0x00485BB0
// Name: public: void CUtlSymbolTree::_PopulateTree(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTree::_PopulateTree(CUtlSymbolTree *this, void *pathId, void **path)
{
  char *v4; // ebx
  char *v5; // eax
  void **FirstChild; // esi
  const char *Label; // eax
  char *v8; // [esp-4h] [ebp-214h]
  char sz[512]; // [esp+Ch] [ebp-204h] BYREF
  char *check; // [esp+20Ch] [ebp-4h]
  void **cur; // [esp+21Ch] [ebp+Ch]

  _V_strcpy(dest: sz, src: (const char *)path);
  v4 = sz;
  cur = nullptr;
  do
  {
    if ( *v4 == 0 )
      break;
    v5 = _V_strstr(s1: v4, search: "/");
    if ( v5 == nullptr )
      v5 = _V_strstr(s1: v4, search: "\\");
    check = v4;
    if ( v5 != nullptr )
    {
      *v5 = 0;
      v4 = v5 + 1;
    }
    else
    {
      v4 = nullptr;
    }
    FirstChild = mxTreeView::getFirstChild(this, item: cur);
    if ( FirstChild != nullptr )
    {
      while ( 1 )
      {
        v8 = check;
        Label = mxTreeView::getLabel(this, item: FirstChild);
        if ( _V_stricmp(s1: Label, s2: v8) == 0 )
          break;
        FirstChild = mxTreeView::getNextChild(this, item: FirstChild);
        if ( FirstChild == nullptr )
          goto LABEL_11;
      }
      cur = FirstChild;
    }
    else
    {
LABEL_11:
      cur = mxTreeView::add(this, parent: cur, item: check);
    }
  }
  while ( v4 != nullptr );
  mxTreeView::setUserData(this, item: cur, userData: pathId);
}

//------------------------------------------------------------------------------
// Address: 0x00485C90
// Name: public: CVCDOptionsWindow::CVCDOptionsWindow(class CVCDBrowser __near *)
// Source: json
//------------------------------------------------------------------------------
CVCDOptionsWindow *__thiscall CVCDOptionsWindow::CVCDOptionsWindow(CVCDOptionsWindow *this, CVCDBrowser *browser)
{
  mxButton *v3; // [esp+0h] [ebp-1Ch]
  mxLineEdit *v4; // [esp+4h] [ebp-18h]
  mxButton *v5; // [esp+8h] [ebp-14h]
  mxButton *v7; // [esp+10h] [ebp-Ch]
  mxLineEdit *v8; // [esp+14h] [ebp-8h]
  mxButton *v9; // [esp+18h] [ebp-4h]

  mxWindow::mxWindow(this, parent: browser, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  this->__vftable = (CVCDOptionsWindow_vtbl *)&CVCDOptionsWindow::`vftable';
  this->m_pBrowser = browser;
  FacePoser_AddWindowStyle(w: this, addbits: 100663296);
  this->m_szSearchString[0] = 0;
  v9 = (mxButton *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v5 = mxButton::mxButton(this: v9, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Open", id: 1000);
  else
    v5 = nullptr;
  this->m_pOpen = v5;
  v8 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    v4 = mxLineEdit::mxLineEdit(this: v8, parent: this, x: 0, y: 0, w: 0, h: 0, label: defaultValue, id: 1001, style: 0);
  else
    v4 = nullptr;
  this->m_pSearch = v4;
  v7 = (mxButton *)operator new(nSize: 0xCu);
  if ( v7 != nullptr )
    v3 = mxButton::mxButton(this: v7, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Cancel", id: 1002);
  else
    v3 = nullptr;
  this->m_pCancelSearch = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00485DC0
// Name: public: virtual bool CVCDOptionsWindow::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVCDOptionsWindow::PaintBackground(CVCDOptionsWindow *this)
{
  ((void (__thiscall *)(CVCDOptionsWindow *, CVCDOptionsWindow *))this->redraw)(a1: this, a2: this);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00485DE0
// Name: public: char const __near * CVCDOptionsWindow::GetSearchString(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CVCDOptionsWindow::GetSearchString(CVCDOptionsWindow *this)
{
  return this->m_szSearchString;
}

//------------------------------------------------------------------------------
// Address: 0x00485E00
// Name: private: void CVCDBrowser::OpenVCD(void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVCDBrowser::OpenVCD(CVCDBrowser *this@<ecx>, int a2@<ebx>, int a3@<edi>, void *const *handle)
{
  char *v4; // eax
  char pFullPath[260]; // [esp+0h] [ebp-304h] BYREF
  char fn[512]; // [esp+104h] [ebp-200h] BYREF

  if ( filesystem->String(this: filesystem, a2: handle, a3: fn, a4: 512) )
  {
    v4 = (char *)filesystem->RelativePathToFullPath(
                   this: filesystem,
                   a2: fn,
                   a3: "GAME",
                   a4: pFullPath,
                   a5: 260,
                   a6: 0,
                   a7: 0);
    if ( v4 == nullptr )
      v4 = fn;
    CChoreoView::LoadSceneFromFile(this: g_pChoreoView, a2, a3, filename: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00485E80
// Name: public: void CVCDBrowser::SetCurrent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDBrowser::SetCurrent(CVCDBrowser *this, const char *filename)
{
  const char *v2; // esi
  int ItemCount; // ebx
  int i; // esi
  int v6; // eax
  CVCDList *m_pListView; // ecx
  char fixed[512]; // [esp+Ch] [ebp-400h] BYREF
  char fn[512]; // [esp+20Ch] [ebp-200h] BYREF

  v2 = filename;
  if ( filename != nullptr
    && (V_strnicmp(s1: filename, s2: "sound/", n: 6) == 0 || V_strnicmp(s1: v2, s2: "sound\\", n: 6) == 0) )
  {
    v2 += 6;
  }
  V_strncpy(pDest: fn, pSrc: v2, maxLen: 512);
  V_FixSlashes(pname: fn, separator: 92);
  ItemCount = mxListView::getItemCount(this: this->m_pListView);
  for ( i = 0; i < ItemCount; ++i )
  {
    filename = (const char *)mxListView::getUserData(this: this->m_pListView, item: i, column: 0);
    if ( filesystem->String(this: filesystem, a2: (void *const *)&filename, a3: fixed, a4: 512) )
    {
      V_FixSlashes(pname: fixed, separator: 92);
      v6 = _V_stricmp(s1: fixed, s2: fn);
      m_pListView = this->m_pListView;
      if ( v6 != 0 )
      {
        mxListView::setSelected(this: m_pListView, item: i, b: false);
      }
      else
      {
        mxListView::scrollToItem(this: m_pListView, item: i);
        mxListView::setSelected(this: this->m_pListView, item: i, b: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00485F90
// Name: protected: static int CUtlSortVector<void __near *,class CVCDBrowser::CNameLessFunc>::CompareHelper(void __near *,void __near * const __near *,void __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<void *,CVCDBrowser::CNameLessFunc>::CompareHelper(
        void *context,
        void *const *lhs,
        void *const *rhs)
{
  if ( *rhs <= *lhs )
    return *rhs < *lhs;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00486F50
// Name: public: void CUtlSymbolTree::PopulateTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTree::PopulateTree(CUtlSymbolTree *this)
{
  UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int> *i; // esi
  void **FirstChild; // eax

  for ( i = (UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int> *)CUtlRBTree<CUtlSymbolTree::FileTreePath,int,bool (__cdecl *)(CUtlSymbolTree::FileTreePath const &,CUtlSymbolTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int>>::FirstInorder(this: &this->m_Paths);
        i != (UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int> *)-1;
        i = CUtlRBTree<CUtlSymbolTree::FileTreePath,int,bool (__cdecl *)(CUtlSymbolTree::FileTreePath const &,CUtlSymbolTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int>>::NextInorder(
              this: &this->m_Paths,
              (int)i) )
  {
    CUtlSymbolTree::_PopulateTree(this, pathId: i, path: (void **)&this->m_Paths.m_Elements.m_pMemory[(_DWORD)i].m_Data);
  }
  FirstChild = mxTreeView::getFirstChild(this, item: nullptr);
  mxTreeView::setOpen(this, item: FirstChild, b: true);
}

//------------------------------------------------------------------------------
// Address: 0x00486FB0
// Name: private: void CVCDBrowser::RemoveAllSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDBrowser::RemoveAllSounds(CVCDBrowser *this)
{
  CUtlSymbolTree *m_pFileTree; // esi

  this->m_AllVCDs.m_Size = 0;
  if ( this->m_AllVCDs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_AllVCDs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AllVCDs.m_Memory.m_pMemory);
      this->m_AllVCDs.m_Memory.m_pMemory = nullptr;
    }
    this->m_AllVCDs.m_Memory.m_nAllocationCount = 0;
  }
  this->m_AllVCDs.m_pElements = this->m_AllVCDs.m_Memory.m_pMemory;
  this->m_Scripts.m_Size = 0;
  this->m_CurrentSelection.m_Size = 0;
  m_pFileTree = this->m_pFileTree;
  mxTreeView::removeAll(this: m_pFileTree);
  CUtlRBTree<CUtlSymbolTree::FileTreePath,int,bool (__cdecl *)(CUtlSymbolTree::FileTreePath const &,CUtlSymbolTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int>>::RemoveAll(this: &m_pFileTree->m_Paths);
}

//------------------------------------------------------------------------------
// Address: 0x004870F0
// Name: public: virtual void CVCDBrowser::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CVCDBrowser::OnDelete(CVCDBrowser *this)
{
  CVCDBrowser::RemoveAllSounds(this);
}

//------------------------------------------------------------------------------
// Address: 0x00487100
// Name: private: void CVCDBrowser::PopulateTree(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDBrowser::PopulateTree(CVCDBrowser *this, const char *subdirectory)
{
  signed int m_Size; // esi
  CVCDOptionsWindow *m_pOptions; // ecx
  const char *v5; // edi
  int v6; // edx
  void *const *v7; // eax
  IFileSystem_vtbl *v8; // edx
  signed int v9; // edi
  void **m_pMemory; // ecx
  void **v11; // edi
  CVCDList *m_pListView; // ecx
  int NextSelectedItem; // eax
  const char *Label; // eax
  void **v15; // edi
  int v16; // esi
  int v17; // esi
  char prevSelectedName[512]; // [esp+Ch] [ebp-634h] BYREF
  char subdir[512]; // [esp+20Ch] [ebp-434h] BYREF
  char name[512]; // [esp+40Ch] [ebp-234h] BYREF
  void *const *vcd; // [esp+60Ch] [ebp-34h]
  void *context; // [esp+610h] [ebp-30h] BYREF
  int c; // [esp+614h] [ebp-2Ch]
  int len; // [esp+618h] [ebp-28h]
  CUtlSortVector<void *,CVCDBrowser::CNameLessFunc> sorted; // [esp+61Ch] [ebp-24h] BYREF
  const char *texttofind; // [esp+638h] [ebp-8h]
  int i; // [esp+63Ch] [ebp-4h]

  m_Size = 0;
  subdir[0] = 0;
  memset(&sorted, 0, 25);
  texttofind = nullptr;
  if ( this->m_bTextSearch )
  {
    m_pOptions = this->m_pOptions;
    v5 = nullptr;
    subdirectory = nullptr;
    texttofind = CVCDOptionsWindow::GetSearchString(this: m_pOptions);
  }
  else
  {
    v5 = subdirectory;
  }
  len = 0;
  if ( v5 != nullptr )
  {
    len = _V_strlen(str: v5);
    V_strncpy(pDest: subdir, pSrc: v5, maxLen: 512);
    _V_strlower(start: subdir);
    V_FixSlashes(pname: subdir, separator: 92);
  }
  v6 = 0;
  c = this->m_AllVCDs.m_Size;
  i = 0;
  if ( c > 0 )
  {
    do
    {
      v7 = &this->m_AllVCDs.m_Memory.m_pMemory[v6];
      v8 = filesystem->IAppSystem::__vftable;
      vcd = v7;
      if ( v8->String(this: filesystem, a2: v7, a3: name, a4: 512)
        && (subdirectory == nullptr || V_strnicmp(s1: subdir, s2: name, n: len) == 0)
        && (!this->m_bTextSearch || texttofind == nullptr || V_stristr(pStr: name, pSearch: texttofind) != nullptr) )
      {
        sorted.m_bNeedsSort = true;
        v9 = m_Size;
        if ( m_Size + 1 > sorted.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IFacePoserToolWindow *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&sorted,
            num: m_Size - sorted.m_Memory.m_nAllocationCount + 1);
          m_Size = sorted.m_Size;
        }
        m_pMemory = sorted.m_Memory.m_pMemory;
        sorted.m_Size = ++m_Size;
        sorted.m_pElements = sorted.m_Memory.m_pMemory;
        if ( m_Size - v9 - 1 > 0 )
        {
          _V_memmove(
            dest: &sorted.m_Memory.m_pMemory[v9 + 1],
            src: &sorted.m_Memory.m_pMemory[v9],
            count: 4 * (m_Size - v9 - 1));
          m_pMemory = sorted.m_Memory.m_pMemory;
        }
        v11 = &m_pMemory[v9];
        if ( v11 != nullptr )
          *v11 = *vcd;
      }
      v6 = i + 1;
      i = v6;
    }
    while ( v6 < c );
    if ( sorted.m_bNeedsSort && m_Size > 1 )
    {
      context = sorted.m_pLessContext;
      c = (int)&subdirectory + 3;
      qsort_s(
        base: sorted.m_Memory.m_pMemory,
        num: m_Size,
        width: 4u,
        comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<void *,CVCDBrowser::CNameLessFunc>::CompareHelper,
        &context);
    }
  }
  m_pListView = this->m_pListView;
  prevSelectedName[0] = 0;
  if ( mxListView::getNumSelected(this: m_pListView) == 1 )
  {
    NextSelectedItem = mxListView::getNextSelectedItem(this: this->m_pListView, startitem: 0);
    if ( NextSelectedItem >= 0 )
    {
      Label = mxListView::getLabel(this: this->m_pListView, item: NextSelectedItem, column: 0);
      _V_strcpy(dest: prevSelectedName, src: Label);
    }
  }
  mxListView::removeAll(this: this->m_pListView);
  mxListView::setDrawingEnabled(this: this->m_pListView, draw: false);
  i = -1;
  if ( m_Size > 0 )
  {
    v15 = sorted.m_Memory.m_pMemory;
    for ( subdirectory = (const char *)m_Size; subdirectory != nullptr; --subdirectory )
    {
      if ( filesystem->String(this: filesystem, a2: v15, a3: name, a4: 512) )
      {
        v16 = mxListView::add(this: this->m_pListView, item: name);
        mxListView::setUserData(this: this->m_pListView, item: v16, column: 0, userData: *v15);
        if ( _V_stricmp(s1: prevSelectedName, s2: name) == 0 )
          i = v16;
      }
      ++v15;
    }
  }
  mxListView::setDrawingEnabled(this: this->m_pListView, draw: true);
  v17 = i;
  if ( i != -1 )
  {
    mxListView::setSelected(this: this->m_pListView, item: i, b: true);
    mxListView::scrollToItem(this: this->m_pListView, item: v17);
  }
  if ( sorted.m_Memory.m_nGrowSize >= 0 && sorted.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sorted.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00487400
// Name: public: void CVCDBrowser::BuildSelectionList(class CUtlVector<void __near *,class CUtlMemory<void __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDBrowser::BuildSelectionList(
        CVCDBrowser *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *selected)
{
  int v3; // ebx
  int NextSelectedItem; // eax
  void *UserData; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  void **v8; // ecx
  int v9; // eax
  void **v10; // eax
  void *vcd; // [esp+18h] [ebp+8h]

  selected[1].m_pMemory = nullptr;
  v3 = -1;
  while ( 1 )
  {
    NextSelectedItem = mxListView::getNextSelectedItem(this: this->m_pListView, startitem: v3);
    v3 = NextSelectedItem;
    if ( NextSelectedItem == -1 )
      break;
    UserData = mxListView::getUserData(this: this->m_pListView, item: NextSelectedItem, column: 0);
    m_pMemory = (int)selected[1].m_pMemory;
    vcd = UserData;
    m_nAllocationCount = selected->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: selected, num: m_pMemory - m_nAllocationCount + 1);
    ++selected[1].m_pMemory;
    v8 = (void **)selected->m_pMemory;
    v9 = (int)selected[1].m_pMemory - m_pMemory - 1;
    selected[1].m_nAllocationCount = (int)selected->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
    v10 = (void **)&selected->m_pMemory[m_pMemory];
    if ( v10 != nullptr )
      *v10 = vcd;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004874B0
// Name: private: void CVCDBrowser::ShowContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDBrowser::ShowContextMenu(CVCDBrowser *this)
{
  IFacePoserToolWindow *v2; // eax
  CUtlVector<void *,CUtlMemory<void *,int> > *p_m_CurrentSelection; // edi
  HWND Handle; // eax
  mxPopupMenu *v5; // eax
  mxPopupMenu *v6; // ebx
  char sz[512]; // [esp+8h] [ebp-408h] BYREF
  char name[512]; // [esp+208h] [ebp-208h] BYREF
  tagPOINT pt; // [esp+408h] [ebp-8h] BYREF

  if ( this != nullptr )
    v2 = &this->IFacePoserToolWindow;
  else
    v2 = nullptr;
  IFacePoserToolWindow::SetActiveTool(tool: v2);
  p_m_CurrentSelection = &this->m_CurrentSelection;
  CVCDBrowser::BuildSelectionList(
    this,
    selected: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CurrentSelection);
  if ( this->m_CurrentSelection.m_Size > 0 )
  {
    GetCursorPos(lpPoint: &pt);
    Handle = (HWND)mxWidget::getHandle(this);
    ScreenToClient(hWnd: Handle, lpPoint: &pt);
    v5 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v5 != nullptr )
      v6 = mxPopupMenu::mxPopupMenu(this: v5);
    else
      v6 = nullptr;
    if ( this->m_CurrentSelection.m_Size == 1
      && *p_m_CurrentSelection->m_Memory.m_pMemory != nullptr
      && filesystem->String(this: filesystem, a2: p_m_CurrentSelection->m_Memory.m_pMemory, a3: name, a4: 512) )
    {
      V_snprintf(pDest: sz, maxLen: 512, pFormat: "&Open '%s'", name);
      mxPopupMenu::add(this: v6, item: sz, id: 1000);
    }
    mxPopupMenu::popup(this: v6, widget: this, x: pt.x, y: pt.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004875A0
// Name: public: void CVCDBrowser::OnOpen(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVCDBrowser::OnOpen(CVCDBrowser *this@<ecx>, int a2@<ebx>)
{
  IFacePoserToolWindow *v3; // eax

  if ( this != nullptr )
    v3 = &this->IFacePoserToolWindow;
  else
    v3 = nullptr;
  IFacePoserToolWindow::SetActiveTool(tool: v3);
  CVCDBrowser::BuildSelectionList(
    this,
    selected: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CurrentSelection);
  if ( this->m_CurrentSelection.m_Size == 1 )
    CVCDBrowser::OpenVCD(
      this,
      a2,
      a3: (int)&this->m_CurrentSelection,
      handle: this->m_CurrentSelection.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004875E0
// Name: public: void CVCDBrowser::OnCancelSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDBrowser::OnCancelSearch(CVCDBrowser *this)
{
  IFacePoserToolWindow *v2; // eax
  CUtlSymbolTree *m_pFileTree; // esi
  void **SelectedItem; // eax
  unsigned int UserData; // eax

  if ( this != nullptr )
    v2 = &this->IFacePoserToolWindow;
  else
    v2 = nullptr;
  IFacePoserToolWindow::SetActiveTool(tool: v2);
  m_pFileTree = this->m_pFileTree;
  this->m_bTextSearch = false;
  SelectedItem = mxTreeView::getSelectedItem(this: m_pFileTree);
  UserData = (unsigned int)mxTreeView::getUserData(this: m_pFileTree, item: SelectedItem);
  if ( UserData >= m_pFileTree->m_Paths.m_NumElements )
    CVCDBrowser::PopulateTree(this, subdirectory: defaultValue);
  else
    CVCDBrowser::PopulateTree(this, subdirectory: m_pFileTree->m_Paths.m_Elements.m_pMemory[UserData].m_Data.path);
}

//------------------------------------------------------------------------------
// Address: 0x00487680
// Name: public: virtual int CVCDBrowser::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVCDBrowser::handleEvent(CVCDBrowser *this, mxEvent *event)
{
  mxEvent *v2; // ebx
  IFacePoserToolWindow *v4; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  CUtlSymbolTree::FileTreePath *SelectedPath; // eax
  int flags; // ebx
  int NextSelectedItem; // eax
  int v14; // [esp-4h] [ebp-14h]
  int iret; // [esp+Ch] [ebp-4h]

  v2 = event;
  v4 = &this->IFacePoserToolWindow;
  iret = 0;
  if ( this->HandleToolEvent(this: &this->IFacePoserToolWindow, a2: event) )
    return 0;
  v6 = v2->event;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 == 0 )
    {
      v8 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_pOptions, x: 0, y: 0, w: v8, h: 20);
      v9 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pFileTree, x: 0, y: 20, w: 175, h: v9 - 20);
      v14 = mxWidget::h2(this) - 20;
      v10 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_pListView, x: 175, y: 20, w: v10 - 175, h: v14);
      return 1;
    }
    if ( v7 == 18 )
      return 1;
    return iret;
  }
  iret = 1;
  switch ( v2->action )
  {
    case 0x65:
      IFacePoserToolWindow::SetActiveTool(tool: v4);
      flags = v2->flags;
      if ( flags == 1 )
      {
        CVCDBrowser::ShowContextMenu(this);
        return 1;
      }
      if ( flags == 2 && mxListView::getNumSelected(this: this->m_pListView) == 1 )
      {
        NextSelectedItem = mxListView::getNextSelectedItem(this: this->m_pListView, startitem: -1);
        if ( NextSelectedItem >= 0 )
        {
          event = (mxEvent *)mxListView::getUserData(this: this->m_pListView, item: NextSelectedItem, column: 0);
          CVCDBrowser::OpenVCD(this, a2: 2, a3: (int)v4, handle: (void *const *)&event);
        }
      }
      return iret;
    case 0x66:
      IFacePoserToolWindow::SetActiveTool(tool: v4);
      SelectedPath = CWaveFileTree::GetSelectedPath(this: this->m_pFileTree);
      CVCDBrowser::PopulateTree(this, subdirectory: SelectedPath->path);
      return 1;
    case 0x3E8:
      CVCDBrowser::OnOpen(this, a2: (int)v2);
      return 1;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487830
// Name: public: void CVCDBrowser::OnSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDBrowser::OnSearch(CVCDBrowser *this)
{
  CVCDOptionsWindow *m_pOptions; // ecx
  char *SearchString; // eax

  if ( *CVCDOptionsWindow::GetSearchString(this: this->m_pOptions) != 0 )
  {
    IFacePoserToolWindow::SetActiveTool(tool: &this->IFacePoserToolWindow);
    m_pOptions = this->m_pOptions;
    this->m_bTextSearch = true;
    SearchString = CVCDOptionsWindow::GetSearchString(this: m_pOptions);
    CVCDBrowser::PopulateTree(this, subdirectory: SearchString);
  }
  else
  {
    CVCDBrowser::OnCancelSearch(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004878F0
// Name: private: bool CVCDBrowser::LoadVCDsFilesInDirectory(class CUtlSortVector<void __near *,class CVCDBrowser::CNameLessFunc> __near &,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVCDBrowser::LoadVCDsFilesInDirectory(
        CVCDBrowser *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *soundlist,
        char *pDirectoryName,
        int nDirectoryNameLen)
{
  int v4; // ebx
  void *v5; // esp
  const char *v7; // edi
  int v8; // edi
  void *v9; // esp
  void *v10; // eax
  int m_pMemory; // edi
  void *v12; // ebx
  int m_nAllocationCount; // eax
  void **v14; // ecx
  int v15; // eax
  void **v16; // eax
  CUtlSymbolTree *m_pFileTree; // esi
  char v18[12]; // [esp+0h] [ebp-11Ch] BYREF
  CUtlSymbolTree::FileTreePath dest; // [esp+Ch] [ebp-110h] BYREF
  CVCDBrowser *v20; // [esp+110h] [ebp-Ch]
  const char *v21; // [esp+114h] [ebp-8h]
  int v22; // [esp+118h] [ebp-4h] BYREF

  v4 = nDirectoryNameLen;
  v20 = this;
  v5 = alloca(nDirectoryNameLen + 7);
  V_snprintf(pDest: v18, maxLen: nDirectoryNameLen + 7, pFormat: "%s/*.vcd", pDirectoryName);
  if ( filesystem == nullptr )
    return 0;
  v7 = filesystem->FindFirst(this: filesystem, a2: v18, a3: &v22);
  v21 = v7;
  if ( v7 != nullptr )
  {
    while ( 1 )
    {
      if ( !filesystem->FindIsDirectory(this: filesystem, a2: v22) )
      {
        v8 = _V_strlen(str: v7) + v4 + 2;
        v9 = alloca(v8);
        V_snprintf(pDest: v18, maxLen: v8, pFormat: "%s/%s", pDirectoryName, v21);
        V_strnlwr(s: v18, count: v8);
        v10 = filesystem->FindOrAddFileName(this: filesystem, a2: v18);
        m_pMemory = (int)soundlist[1].m_pMemory;
        v12 = v10;
        m_nAllocationCount = soundlist->m_nAllocationCount;
        LOBYTE(soundlist[2].m_pMemory) = 1;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: soundlist, num: m_pMemory - m_nAllocationCount + 1);
        ++soundlist[1].m_pMemory;
        v14 = (void **)soundlist->m_pMemory;
        v15 = (int)soundlist[1].m_pMemory - m_pMemory - 1;
        soundlist[1].m_nAllocationCount = (int)soundlist->m_pMemory;
        if ( v15 > 0 )
          _V_memmove(dest: &v14[m_pMemory + 1], src: &v14[m_pMemory], count: 4 * v15);
        v16 = (void **)&soundlist->m_pMemory[m_pMemory];
        if ( v16 != nullptr )
          *v16 = v12;
      }
      v21 = filesystem->FindNext(this: filesystem, a2: v22);
      if ( v21 == nullptr )
        break;
      v7 = v21;
      v4 = nDirectoryNameLen;
    }
  }
  m_pFileTree = v20->m_pFileTree;
  _V_strcpy(dest: dest.path, src: pDirectoryName);
  if ( CUtlRBTree<CUtlSymbolTree::FileTreePath,int,bool (__cdecl *)(CUtlSymbolTree::FileTreePath const &,CUtlSymbolTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int>>::Find(
         this: &m_pFileTree->m_Paths,
         search: &dest) == -1 )
    CUtlRBTree<CUtlSymbolTree::FileTreePath,int,bool (__cdecl *)(CUtlSymbolTree::FileTreePath const &,CUtlSymbolTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int>>::Insert(
      this: &m_pFileTree->m_Paths,
      insert: &dest);
  filesystem->FindClose(this: filesystem, a2: v22);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00487AA0
// Name: private: bool CVCDBrowser::InitDirectoryRecursive(class CUtlSortVector<void __near *,class CVCDBrowser::CNameLessFunc> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVCDBrowser::InitDirectoryRecursive(
        CVCDBrowser *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *soundlist,
        char *pDirectoryName)
{
  char *v3; // esi
  int v5; // edi
  void *v7; // esp
  char *v8; // edi
  char v9; // al
  const char *(__thiscall *FindFirst)(IFileSystem *, const char *, int *); // edx
  unsigned int v11; // edi
  const char *i; // esi
  char v13; // al
  void *v14; // esp
  unsigned int v15; // eax
  char *v16; // edi
  char v17; // cl
  char v18; // [esp-1h] [ebp-19h] BYREF
  char v19[12]; // [esp+0h] [ebp-18h] BYREF
  CVCDBrowser *v20; // [esp+Ch] [ebp-Ch]
  char *pWildCard; // [esp+10h] [ebp-8h]
  int nDirectoryNameLen; // [esp+14h] [ebp-4h]

  v3 = pDirectoryName;
  v20 = this;
  v5 = _V_strlen(str: pDirectoryName);
  nDirectoryNameLen = v5;
  if ( CVCDBrowser::LoadVCDsFilesInDirectory(this, soundlist, pDirectoryName: v3, nDirectoryNameLen: v5) == 0 )
    return 0;
  v7 = alloca(v5 + 4);
  pWildCard = v19;
  strcpy(v19, v3);
  v8 = &v18;
  do
    v9 = *++v8;
  while ( v9 != 0 );
  strcpy(v8, "/*.");
  FindFirst = filesystem->FindFirst;
  v11 = ++nDirectoryNameLen;
  for ( i = FindFirst(this: filesystem, a2: v19, a3: (int *)&pDirectoryName);
        i != nullptr;
        i = filesystem->FindNext(this: filesystem, a2: pDirectoryName) )
  {
    if ( *i == 46 )
    {
      v13 = i[1];
      if ( v13 == 46 || v13 == 0 )
        continue;
    }
    if ( filesystem->FindIsDirectory(this: filesystem, a2: (int)pDirectoryName) )
    {
      v14 = alloca(_V_strlen(str: i) + v11 + 1);
      memcpy(dst: (unsigned __int8 *)v19, src: (unsigned __int8 *)pWildCard, count: v11);
      v19[v11] = 0;
      v15 = strlen(i) + 1;
      v16 = &v18;
      do
        v17 = *++v16;
      while ( v17 != 0 );
      qmemcpy(v16, i, v15);
      if ( !CVCDBrowser::InitDirectoryRecursive(
              this: v20,
              (CUtlSortVector<void *,CVCDBrowser::CNameLessFunc> *)soundlist,
              pDirectoryName: v19) )
        return 0;
      v11 = nDirectoryNameLen;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00487C00
// Name: private: void CVCDBrowser::LoadAllSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVCDBrowser::LoadAllSounds(CVCDBrowser *this)
{
  Color v2; // ecx
  signed int m_Size; // eax
  _DWORD context[2]; // [esp+8h] [ebp-Ch] BYREF
  char v5; // [esp+13h] [ebp-1h] BYREF

  CVCDBrowser::RemoveAllSounds(this);
  Con_Printf(a1: v2, fmt: "Building list of all .vcds in sound/ folder\n");
  CVCDBrowser::InitDirectoryRecursive(
    this,
    soundlist: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_AllVCDs,
    pDirectoryName: "scenes");
  if ( this->m_AllVCDs.m_bNeedsSort )
  {
    m_Size = this->m_AllVCDs.m_Size;
    this->m_AllVCDs.m_bNeedsSort = false;
    if ( m_Size > 1 )
    {
      context[0] = this->m_AllVCDs.m_pLessContext;
      context[1] = &v5;
      qsort_s(
        base: this->m_AllVCDs.m_Memory.m_pMemory,
        num: m_Size,
        width: 4u,
        comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<void *,CVCDBrowser::CNameLessFunc>::CompareHelper,
        context);
    }
  }
  CUtlSymbolTree::PopulateTree(this: this->m_pFileTree);
}

//------------------------------------------------------------------------------
// Address: 0x00487C80
// Name: public: virtual int CVCDOptionsWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CVCDOptionsWindow::handleEvent@<eax>(CVCDOptionsWindow *this@<ecx>, int a2@<ebx>, mxEvent *event)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int action; // [esp+0h] [ebp-1Ch]
  int v8; // [esp+8h] [ebp-14h]
  int iret; // [esp+18h] [ebp-4h]

  iret = 0;
  v8 = event->event;
  if ( v8 != 0 )
  {
    if ( v8 == 1 )
    {
      iret = 1;
      v3 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pOpen, x: 1, y: 1, w: 120, h: v3 - 2);
      v4 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pCancelSearch, x: 131, y: 1, w: 120, h: v4 - 2);
      v5 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pSearch, x: 261, y: 0, w: 360, h: v5 - 1);
    }
    else if ( v8 == 11 && event->action == 1001 )
    {
      if ( event->event == 11 )
      {
        mxLineEdit::getText(this: this->m_pSearch, buf: this->m_szSearchString, bufsize: 0x100u);
        CVCDBrowser::OnSearch(this: this->m_pBrowser);
      }
      return 1;
    }
  }
  else
  {
    action = event->action;
    switch ( action )
    {
      case 1000:
        iret = 1;
        CVCDBrowser::OnOpen(this: this->m_pBrowser, a2);
        break;
      case 1001:
        return 1;
      case 1002:
        iret = 1;
        this->m_szSearchString[0] = 0;
        mxLineEdit::clear(this: this->m_pSearch);
        CVCDBrowser::OnCancelSearch(this: this->m_pBrowser);
        break;
      default:
        break;
    }
  }
  return iret;
}

//------------------------------------------------------------------------------
// Address: 0x00487E20
// Name: public: CVCDBrowser::CVCDBrowser(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
CVCDBrowser *__thiscall CVCDBrowser::CVCDBrowser(CVCDBrowser *this, mxWindow *parent)
{
  mxListView *v3; // eax
  CVCDList *v4; // edi
  CVCDOptionsWindow *v5; // eax
  CVCDOptionsWindow *v6; // eax
  mxTreeView *v7; // eax
  CUtlSymbolTree *v8; // edi

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "VCDBrowser",
    displaynameroot: "VCDs");
  this->mxWindow::mxWidget::__vftable = (CVCDBrowser_vtbl *)&CVCDBrowser::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&CVCDBrowser::`vftable'{for `IFacePoserToolWindow'};
  this->m_AllVCDs.m_Memory.m_pMemory = nullptr;
  this->m_AllVCDs.m_Memory.m_nAllocationCount = 0;
  this->m_AllVCDs.m_Memory.m_nGrowSize = 0;
  this->m_AllVCDs.m_Size = 0;
  this->m_AllVCDs.m_pElements = nullptr;
  this->m_AllVCDs.m_pLessContext = nullptr;
  this->m_AllVCDs.m_bNeedsSort = false;
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_ScriptTable, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_Scripts.m_Memory.m_pMemory = nullptr;
  this->m_Scripts.m_Memory.m_nAllocationCount = 0;
  this->m_Scripts.m_Memory.m_nGrowSize = 0;
  this->m_Scripts.m_Size = 0;
  this->m_Scripts.m_pElements = nullptr;
  this->m_CurrentSelection.m_Memory.m_pMemory = nullptr;
  this->m_CurrentSelection.m_Memory.m_nAllocationCount = 0;
  this->m_CurrentSelection.m_Memory.m_nGrowSize = 0;
  this->m_CurrentSelection.m_Size = 0;
  this->m_CurrentSelection.m_pElements = nullptr;
  IFacePoserToolWindow::SetAutoProcess(this: &this->IFacePoserToolWindow, autoprocess: false);
  this->m_bTextSearch = false;
  this->m_nPrevProcessed = -1;
  v3 = (mxListView *)operator new(nSize: 0xCu);
  v4 = (CVCDList *)v3;
  if ( v3 != nullptr )
  {
    mxListView::mxListView(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, id: 101);
    v4->__vftable = (CVCDList_vtbl *)&CVCDList::`vftable';
    mxListView::insertTextColumn(this: v4, column: 0, width: 700, label: "VCD");
  }
  else
  {
    v4 = nullptr;
  }
  this->m_pListView = v4;
  v5 = (CVCDOptionsWindow *)operator new(nSize: 0x11Cu);
  if ( v5 != nullptr )
    v6 = CVCDOptionsWindow::CVCDOptionsWindow(this: v5, browser: this);
  else
    v6 = nullptr;
  this->m_pOptions = v6;
  v7 = (mxTreeView *)operator new(nSize: 0x30u);
  v8 = (CUtlSymbolTree *)v7;
  if ( v7 != nullptr )
  {
    mxTreeView::mxTreeView(this: v7, parent: this, x: 0, y: 0, w: 0, h: 0, id: 102);
    v8->__vftable = (CUtlSymbolTree_vtbl *)&CUtlSymbolTree::`vftable';
    v8->m_Paths.m_LessFunc = CUtlSymbolTree::FileTreeLessFunc;
    v8->m_Paths.m_Elements.m_pMemory = nullptr;
    v8->m_Paths.m_Elements.m_nAllocationCount = 0;
    v8->m_Paths.m_Elements.m_nGrowSize = 0;
    v8->m_Paths.m_Root = -1;
    v8->m_Paths.m_NumElements = 0;
    v8->m_Paths.m_FirstFree = -1;
    v8->m_Paths.m_LastAlloc.index = -1;
    v8->m_Paths.m_pElements = v8->m_Paths.m_Elements.m_pMemory;
  }
  else
  {
    v8 = nullptr;
  }
  this->m_pFileTree = v8;
  CVCDBrowser::LoadAllSounds(this);
  CVCDBrowser::PopulateTree(this, subdirectory: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004880A0
// Name: public: static bool CUtlSymbolTree::FileTreeLessFunc(struct CUtlSymbolTree::FileTreePath const __near &,struct CUtlSymbolTree::FileTreePath const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CUtlSymbolTree::FileTreeLessFunc(
        const CUtlSymbolTree::FileTreePath *lhs,
        const CUtlSymbolTree::FileTreePath *rhs)
{
  return _V_stricmp(s1: lhs->path, s2: rhs->path) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B2610
// Name: public: int CUtlSortVector<struct SceneImageEntry_t,class CSceneImageEntryLessFunc>::FindLessOrEqual(struct SceneImageEntry_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::FindLessOrEqual(
        CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc> *this,
        const SceneImageEntry_t *src)
{
  int v3; // esi
  int v4; // ecx
  SceneImageEntry_t *m_pMemory; // ebx
  unsigned int crcFilename; // edi
  int result; // eax
  unsigned int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    crcFilename = src->crcFilename;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].crcFilename;
      if ( crcFilename <= v8 )
      {
        if ( crcFilename >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004B26F0
// Name: public: int CUtlSortVector<struct SceneImageEntry_t,class CSceneImageEntryLessFunc>::Find(struct SceneImageEntry_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::Find(
        CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc> *this,
        const SceneImageEntry_t *src)
{
  int v3; // esi
  int v4; // ecx
  SceneImageEntry_t *m_pMemory; // ebx
  unsigned int crcFilename; // edi
  int result; // eax
  unsigned int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    crcFilename = src->crcFilename;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].crcFilename;
      if ( crcFilename <= v8 )
      {
        if ( crcFilename >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B2830
// Name: public: int CUtlSortVector<struct SceneImageEntry_t,class CSceneImageEntryLessFunc>::Insert(struct SceneImageEntry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::Insert(
        CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc> *this,
        const SceneImageEntry_t *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  SceneImageEntry_t *m_pMemory; // ecx
  int v8; // eax
  SceneImageEntry_t *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 150);
  }
  LessOrEqual = CUtlSortVector<SceneImageEntry_t,CSceneImageEntryLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<SceneImageEntry_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 16 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}
