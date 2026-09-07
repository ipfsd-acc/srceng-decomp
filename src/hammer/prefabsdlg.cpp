// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/prefabsdlg.cpp
// Functions: 80
// ============================================================

#include "hammer\prefabsdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100F28B0
// Name: IsValidFilename
// Source: json
//------------------------------------------------------------------------------
int __usercall IsValidFilename@<eax>(const char *pszString@<eax>)
{
  const char *v1; // esi
  unsigned __int8 v2; // al
  int v3; // edi
  int v4; // eax

  v1 = pszString;
  if ( *pszString == 0 )
    return 1;
  while ( 1 )
  {
    v2 = *v1++;
    if ( v2 <= 0x7Fu )
    {
      v3 = v2;
      if ( isalpha(c: v2) == 0 && isdigit(c: v3) == 0 )
      {
        strchr(string: " $%`-_@~'!(){}^#&", chr: v3);
        if ( v4 == 0 )
          break;
      }
    }
    if ( *v1 == 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F2910
// Name: protected: void CPrefabsDlg::SetCurObject(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::SetCurObject(CPrefabsDlg *this, int iItem)
{
  unsigned int ItemData; // eax
  CPrefab *ID; // eax

  this->iCurObject = iItem;
  if ( iItem == -1 )
  {
    CWnd::SetWindowTextA(this: &this->m_ObjectNotes, lpszString: &var);
  }
  else
  {
    ItemData = CListCtrl::GetItemData(this: &this->m_Objects, nItem: iItem);
    ID = CPrefab::FindID(dwID: ItemData);
    CWnd::SetWindowTextA(this: &this->m_ObjectNotes, lpszString: ID->szNotes);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2970
// Name: protected: void CPrefabsDlg::OnItemchangedObjects(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::OnItemchangedObjects(CPrefabsDlg *this, tagNMHDR *pNMHDR, int *pResult)
{
  *pResult = 0;
  if ( (pNMHDR[2].idFrom & 8) != 0 && (pNMHDR[1].code & 1) != 0 )
    CPrefabsDlg::SetCurObject(this, iItem: (int)pNMHDR[1].hwndFrom);
}

//------------------------------------------------------------------------------
// Address: 0x100F29A0
// Name: protected: void CPrefabsDlg::OnEndlabeleditObjects(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::OnEndlabeleditObjects(CPrefabsDlg *this, tagNMHDR *pNMHDR, int *pResult)
{
  unsigned int ItemData; // eax
  CPrefab *ID; // eax
  char *code; // ecx
  char *szName; // edx
  char v8; // al

  *pResult = 0;
  if ( pNMHDR[2].code != 0 )
  {
    ItemData = CListCtrl::GetItemData(this: &this->m_Objects, nItem: pNMHDR[1].idFrom);
    ID = CPrefab::FindID(dwID: ItemData);
    code = (char *)pNMHDR[2].code;
    szName = ID->szName;
    do
    {
      v8 = *code;
      *szName++ = *code++;
    }
    while ( v8 != 0 );
    CListCtrl::SetItemText(
      this: &this->m_Objects,
      nItem: pNMHDR[1].idFrom,
      nSubItem: 0,
      lpszText: (char *)pNMHDR[2].code);
    this->bCurLibraryModified = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2A10
// Name: public: struct CComCtlWrapper::ImageList_SetBkColor_Type CComCtlWrapper::GetProcAddress_ImageList_SetBkColor(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_SetBkColor_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_SetBkColor(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_SetBkColor_Type *result)
{
  HINSTANCE__ *ModuleHandleA; // eax
  HINSTANCE__ *LibraryA; // eax

  if ( this->m__ImageList_SetBkColor.p == nullptr )
  {
    if ( this->m_hModule == nullptr )
    {
      ModuleHandleA = GetModuleHandleA(lpModuleName: this->m_strModuleName.m_pszData);
      this->m_hModule = ModuleHandleA;
      if ( ModuleHandleA == nullptr )
      {
        LibraryA = LoadLibraryA(lpLibFileName: this->m_strModuleName.m_pszData);
        this->m_hModule = LibraryA;
        this->m_bFreeLib = LibraryA != nullptr;
      }
    }
    this->m__ImageList_SetBkColor.p = (unsigned int (__stdcall *)(struct _IMAGELIST *, unsigned int))GetProcAddress(hModule: this->m_hModule, lpProcName: "ImageList_SetBkColor");
  }
  result->p = (unsigned int (__stdcall *)(struct _IMAGELIST *, unsigned int))this->m__ImageList_SetBkColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F2A70
// Name: public: unsigned long CComCtlWrapper::_ImageList_SetBkColor(struct _IMAGELIST __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CComCtlWrapper::_ImageList_SetBkColor(
        CComCtlWrapper *this,
        struct _IMAGELIST *himl,
        unsigned int clrBk)
{
  DWORD LastError; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v6; // eax
  unsigned int (__stdcall *p)(struct _IMAGELIST *, unsigned int); // esi
  unsigned int v9; // ebx
  int v10; // [esp+0h] [ebp-30h]
  CComCtlWrapper::ImageList_SetBkColor_Type v11; // [esp+Ch] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  unsigned int v13; // [esp+14h] [ebp-1Ch]
  int v14; // [esp+2Ch] [ebp-4h]

  LastError = 0;
  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v6 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v13 = 0;
  if ( !v6 )
    return 0;
  v14 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_SetBkColor(this, result: &v11);
  p = this->m__ImageList_SetBkColor.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v9 = ((int (__stdcall *)(struct _IMAGELIST *, unsigned int, int))p)(a1: himl, a2: clrBk, a3: v10);
  v13 = v9;
  v14 = -1;
  if ( v9 == 0 )
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v9 == 0 )
    SetLastError(dwErrCode: LastError);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x100F2B50
// Name: public: CPrefabsDlg::CPrefabsDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CPrefabsDlg *__thiscall CPrefabsDlg::CPrefabsDlg(CPrefabsDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0xCDu, pParentWnd: pParent);
  this->__vftable = (CPrefabsDlg_vtbl *)&CPrefabsDlg::`vftable';
  CWnd::CWnd(this: &this->m_Objects);
  this->m_Objects.__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
  CWnd::CWnd(this: &this->m_ObjectNotes);
  this->m_ObjectNotes.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_LibraryNotes);
  this->m_LibraryNotes.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_Libraries);
  this->m_Libraries.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CImageList::CImageList(this: &this->PrefabImages);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F2C60
// Name: protected: virtual void CPrefabsDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::DoDataExchange(CPrefabsDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x4AA, rControl: (HWND__ *)&this->m_Objects);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_ObjectNotes);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4B2, rControl: (HWND__ *)&this->m_LibraryNotes);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3EF, rControl: (HWND__ *)&this->m_Libraries);
}

//------------------------------------------------------------------------------
// Address: 0x100F2CC0
// Name: protected: void CPrefabsDlg::AddToObjectList(class CPrefab __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::AddToObjectList(CPrefabsDlg *this, CPrefab *pPrefab, LRESULT iItem, int bReplace)
{
  int v5; // eax
  LRESULT inserted; // eax

  if ( iItem == -1 )
    iItem = SendMessageA(hWnd: this->m_Objects.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  if ( bReplace != 0 )
    SendMessageA(hWnd: this->m_Objects.m_hWnd, Msg: 0x1008u, wParam: iItem, lParam: 0);
  v5 = pPrefab->GetType(this: pPrefab);
  inserted = CListCtrl::InsertItem(
               this: &this->m_Objects,
               nMask: 3u,
               nItem: iItem,
               lpszItem: pPrefab->szName,
               nState: 0,
               nStateMask: 0,
               nImage: v5 == 3,
               lParam: 0);
  CListCtrl::SetItem(
    this: &this->m_Objects,
    nItem: inserted,
    nSubItem: 0,
    nMask: 4u,
    lpszItem: nullptr,
    nImage: 0,
    nState: 0,
    nStateMask: 0,
    lParam: pPrefab->dwID);
  this->bCurLibraryModified = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F2D70
// Name: protected: void CPrefabsDlg::OnEditobject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::OnEditobject(CPrefabsDlg *this)
{
  int iCurObject; // eax
  unsigned int ItemData; // eax
  HMENU PopupMenu; // eax
  CWnd *DlgItem; // eax
  CRect r; // [esp+4h] [ebp-24h] BYREF
  CMenu menu; // [esp+14h] [ebp-14h] BYREF
  int v8; // [esp+24h] [ebp-4h]

  iCurObject = this->iCurObject;
  if ( iCurObject != -1 )
  {
    ItemData = CListCtrl::GetItemData(this: &this->m_Objects, nItem: iCurObject);
    if ( CPrefab::FindID(dwID: ItemData) != nullptr )
    {
      menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
      menu.m_hMenu = nullptr;
      v8 = 0;
      PopupMenu = CreatePopupMenu();
      CMenu::Attach(this: &menu, hMenu: PopupMenu);
      AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x6Eu, lpNewItem: "Name and Description");
      AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x6Fu, lpNewItem: "Prefab Data");
      DlgItem = CWnd::GetDlgItem(this, nID: 1199);
      memset(&r, 0, sizeof(r));
      GetWindowRect(hWnd: DlgItem->m_hWnd, lpRect: &r);
      CMenu::TrackPopupMenu(this: &menu, nFlags: 0, x: r.left, y: r.bottom, pWnd: this, lpRect: nullptr);
      v8 = -1;
      menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
      CMenu::DestroyMenu(this: &menu);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2E60
// Name: protected: void CPrefabsDlg::OnSelchangeLibraries(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::OnSelchangeLibraries(CPrefabsDlg *this)
{
  LRESULT v2; // eax
  CPrefabLibrary *ID; // eax
  WPARAM v4; // eax
  LRESULT v5; // eax
  CPrefabLibrary *v6; // ebx
  CPrefab *v7; // esi
  int v8; // eax
  int v9; // eax
  LRESULT inserted; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-24h]
  __POSITION *p; // [esp+8h] [ebp-Ch] BYREF
  int nItem; // [esp+Ch] [ebp-8h]
  int iItem; // [esp+10h] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x150u, wParam: this->iCurLibrary, lParam: 0);
  ID = CPrefabLibrary::FindID(dwID: v2);
  if ( this->bCurLibraryModified != 0 )
    ID->Save(this: ID, a2: nullptr, a3: 0);
  SendMessageA(hWnd: this->m_Objects.m_hWnd, Msg: 0x1009u, wParam: 0, lParam: 0);
  this->iCurLibrary = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  m_hWnd = this->m_Libraries.m_hWnd;
  this->bCurLibraryModified = 0;
  v4 = SendMessageA(hWnd: m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v4 != -1 )
  {
    v5 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x150u, wParam: v4, lParam: 0);
    v6 = CPrefabLibrary::FindID(dwID: v5);
    if ( v6 != nullptr )
    {
      SendMessageA(hWnd: this->m_Objects.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
      p = (__POSITION *)1;
      v7 = CPrefabLibrary::EnumPrefabs(this: v6, &p);
      v8 = 0;
      iItem = 0;
      if ( v7 != nullptr )
      {
        while ( 1 )
        {
          nItem = v8;
          if ( v8 == -1 )
            nItem = SendMessageA(hWnd: this->m_Objects.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
          v9 = v7->GetType(this: v7);
          inserted = CListCtrl::InsertItem(
                       this: &this->m_Objects,
                       nMask: 3u,
                       nItem,
                       lpszItem: v7->szName,
                       nState: 0,
                       nStateMask: 0,
                       nImage: v9 == 3,
                       lParam: 0);
          CListCtrl::SetItem(
            this: &this->m_Objects,
            nItem: inserted,
            nSubItem: 0,
            nMask: 4u,
            lpszItem: nullptr,
            nImage: 0,
            nState: 0,
            nStateMask: 0,
            lParam: v7->dwID);
          ++iItem;
          this->bCurLibraryModified = 1;
          v7 = CPrefabLibrary::EnumPrefabs(this: v6, &p);
          if ( v7 == nullptr )
            break;
          v8 = iItem;
        }
      }
      SendMessageA(hWnd: this->m_Objects.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
      InvalidateRect(hWnd: this->m_Objects.m_hWnd, lpRect: nullptr, bErase: true);
      CWnd::SetWindowTextA(this: &this->m_LibraryNotes, lpszString: v6->szNotes);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3020
// Name: protected: void CPrefabsDlg::OnRemovelibrary(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::OnRemovelibrary(CPrefabsDlg *this)
{
  WPARAM v2; // eax
  LRESULT v3; // eax
  CPrefabLibrary *ID; // edi
  HWND__ *m_hWnd; // [esp-14h] [ebp-20h]
  WPARAM wParam; // [esp+8h] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  wParam = v2;
  if ( v2 != -1 )
  {
    v3 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
    ID = CPrefabLibrary::FindID(dwID: v3);
    if ( ID != nullptr
      && AfxMessageBox(
           lpszText: "Are you sure you want to delete this library from your hard drive?",
           nType: 4u,
           nIDHelp: 0) == 6 )
    {
      ID->DeleteFileA(this: ID);
      CPrefabLibrary::~CPrefabLibrary(this: ID);
      operator delete(p: ID);
      m_hWnd = this->m_Libraries.m_hWnd;
      this->bCurLibraryModified = 0;
      SendMessageA(hWnd: m_hWnd, Msg: 0x144u, wParam, lParam: 0);
      SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
      CPrefabsDlg::OnSelchangeLibraries(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F30E0
// Name: protected: void CPrefabsDlg::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::OnClose(CPrefabsDlg *this)
{
  WPARAM v2; // eax
  CPrefabLibrary *ID; // eax
  LRESULT v4; // eax

  v2 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v2 == -1 )
  {
    ID = nullptr;
  }
  else
  {
    v4 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
    ID = CPrefabLibrary::FindID(dwID: v4);
  }
  if ( this->bCurLibraryModified != 0 && ID != nullptr )
    ID->Save(this: ID, a2: nullptr, a3: 0);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F3150
// Name: protected: void CPrefabsDlg::EditObjectData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::EditObjectData(CPrefabsDlg *this)
{
  CWinApp *m_pCurrentWinApp; // ebx
  WPARAM v3; // eax
  LRESULT v4; // eax
  CPrefabLibrary *ID; // eax
  CMapDoc *v6; // edi
  CPrefab *v7; // eax
  unsigned int ItemData; // eax

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( this->bCurLibraryModified != 0 )
  {
    v3 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v3 != -1 )
    {
      v4 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x150u, wParam: v3, lParam: 0);
      ID = CPrefabLibrary::FindID(dwID: v4);
      if ( ID != nullptr )
        ID->Save(this: ID, a2: nullptr, a3: 0);
    }
  }
  v6 = (CMapDoc *)(*(int (__thiscall **)(unsigned int, _DWORD, int))(*(_DWORD *)m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                   + 132))(
                    a1: m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl,
                    a2: 0,
                    a3: 1);
  if ( this->iCurObject == -1 )
  {
    v7 = nullptr;
  }
  else
  {
    ItemData = CListCtrl::GetItemData(this: &this->m_Objects, nItem: this->iCurObject);
    v7 = CPrefab::FindID(dwID: ItemData);
  }
  CMapDoc::EditPrefab3D(this: v6, dwPrefabID: v7->dwID);
  CDialog::EndDialog(this, nResult: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100F3210
// Name: protected: void CPrefabsDlg::OnRemoveobject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::OnRemoveobject(CPrefabsDlg *this)
{
  void (__stdcall *v1)(HWND, UINT, WPARAM, LPARAM); // ebx
  LRESULT v3; // esi
  WPARAM v4; // eax
  LRESULT v5; // eax
  unsigned int ItemData; // eax
  CObject *ID; // ebx
  int bConfirmed; // [esp+Ch] [ebp-8h]
  CPrefabLibrary *pLibrary; // [esp+10h] [ebp-4h]

  v1 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  v3 = SendMessageA(hWnd: this->m_Objects.m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2);
  bConfirmed = 0;
  v4 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v4 == -1 )
  {
    pLibrary = nullptr;
  }
  else
  {
    v5 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x150u, wParam: v4, lParam: 0);
    pLibrary = CPrefabLibrary::FindID(dwID: v5);
  }
  if ( v3 != -1 )
  {
    do
    {
      ItemData = CListCtrl::GetItemData(this: &this->m_Objects, nItem: v3);
      ID = (CObject *)CPrefab::FindID(dwID: ItemData);
      if ( ID != nullptr )
      {
        if ( bConfirmed == 0 )
        {
          if ( AfxMessageBox(lpszText: "Are you sure you want to delete these items?", nType: 4u, nIDHelp: 0) == 7 )
            return;
          SendMessageA(hWnd: this->m_Objects.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
        }
        bConfirmed = 1;
        CPrefabLibrary::Remove(this: pLibrary, pPrefab: ID);
        ((void (__thiscall *)(CObject *, int))ID->GetRuntimeClass)(a1: ID, a2: 1);
        SendMessageA(hWnd: this->m_Objects.m_hWnd, Msg: 0x1008u, wParam: v3--, lParam: 0);
      }
      v3 = SendMessageA(hWnd: this->m_Objects.m_hWnd, Msg: 0x100Cu, wParam: v3, lParam: 2);
    }
    while ( v3 != -1 );
    v1 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  }
  pLibrary->Save(this: pLibrary, a2: nullptr, a3: 0);
  v1(hWnd: this->m_Objects.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  InvalidateRect(hWnd: this->m_Objects.m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x100F3360
// Name: protected: virtual int CPrefabsDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabsDlg::OnInitDialog(CPrefabsDlg *this)
{
  void *p_PrefabImages; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  struct _IMAGELIST *v4; // eax
  CPrefabLibrary *i; // edi
  WPARAM v6; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-20h]
  struct _IMAGELIST *m_hImageList; // [esp-8h] [ebp-18h]
  LRESULT v10; // [esp-4h] [ebp-14h]
  __POSITION *p; // [esp+Ch] [ebp-4h] BYREF

  CDialog::OnInitDialog(this);
  this->iCurObject = -1;
  CWnd::SetWindowTextA(this: &this->m_ObjectNotes, lpszString: &var);
  p_PrefabImages = &this->PrefabImages;
  CImageList::Create(this: &this->PrefabImages, nBitmapID: (const char *)0xD0, cx: 32, nGrow: 1, crMask: 0xFFFF00u);
  v10 = SendMessageA(hWnd: this->m_Objects.m_hWnd, Msg: 0x1000u, wParam: 0, lParam: 0);
  m_hImageList = this->PrefabImages.m_hImageList;
  ModuleState = AfxGetModuleState();
  CComCtlWrapper::_ImageList_SetBkColor(
    this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
    himl: m_hImageList,
    clrBk: v10);
  if ( this != (CPrefabsDlg *)-624 )
    p_PrefabImages = this->PrefabImages.m_hImageList;
  v4 = (struct _IMAGELIST *)SendMessageA(
                              hWnd: this->m_Objects.m_hWnd,
                              Msg: 0x1003u,
                              wParam: 0,
                              lParam: (LPARAM)p_PrefabImages);
  CImageList::FromHandle(h: v4);
  p = (__POSITION *)1;
  for ( i = CPrefabLibrary::EnumLibraries(&p, eType: LibType_None);
        i != nullptr;
        i = CPrefabLibrary::EnumLibraries(&p, eType: LibType_None) )
  {
    v6 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)i->m_szName);
    SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x151u, wParam: v6, lParam: i->dwID);
  }
  m_hWnd = this->m_Libraries.m_hWnd;
  this->iCurLibrary = 0;
  this->bCurLibraryModified = 0;
  SendMessageA(hWnd: m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
  CPrefabsDlg::OnSelchangeLibraries(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F3480
// Name: protected: void CPrefabsDlg::OnAddlibrary(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::OnAddlibrary(CPrefabsDlg *this)
{
  CPrefabLibraryRMF *v2; // eax
  CPrefabLibraryRMF *v3; // esi
  char *m_pszData; // ecx
  char *szNotes; // edx
  char v6; // al
  LRESULT v7; // eax
  HWND__ *m_hWnd; // [esp-14h] [ebp-234h]
  LPARAM dwID; // [esp-8h] [ebp-228h]
  CEditPrefabDlg dlg; // [esp+8h] [ebp-218h] BYREF
  int iIndex; // [esp+210h] [ebp-10h]
  int v12; // [esp+21Ch] [ebp-4h]

  CEditPrefabDlg::CEditPrefabDlg(this: &dlg, pParent: nullptr);
  v12 = 0;
  if ( CDialog::DoModal(this: &dlg) == 2 )
  {
LABEL_5:
    v12 = -1;
    CEditPrefabDlg::~CEditPrefabDlg(this: &dlg);
  }
  else
  {
    while ( IsValidFilename(pszString: dlg.m_strName.m_pszData) == 0 )
    {
      if ( AfxMessageBox(
             lpszText: "That's not a valid name - some of the characters aren't\n"
             "acceptable. Try using a name with only A-Z, 0-9, space,\n"
             "and these characters: $%`-_@~'!(){}^#&",
             nType: 1u,
             nIDHelp: 0) == 1 )
      {
        v12 = -1;
        CEditPrefabDlg::~CEditPrefabDlg(this: &dlg);
        CEditPrefabDlg::CEditPrefabDlg(this: &dlg, pParent: nullptr);
        v12 = 0;
        if ( CDialog::DoModal(this: &dlg) != 2 )
          continue;
      }
      goto LABEL_5;
    }
    v2 = (CPrefabLibraryRMF *)operator new(nSize: 0x300u);
    iIndex = (int)v2;
    LOBYTE(v12) = 1;
    if ( v2 != nullptr )
      v3 = CPrefabLibraryRMF::CPrefabLibraryRMF(this: v2);
    else
      v3 = nullptr;
    LOBYTE(v12) = 0;
    v3->SetName(this: v3, a2: dlg.m_strName.m_pszData);
    m_pszData = dlg.m_strDescript.m_pszData;
    szNotes = v3->szNotes;
    do
    {
      v6 = *m_pszData;
      *szNotes++ = *m_pszData++;
    }
    while ( v6 != 0 );
    v7 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v3->m_szName);
    dwID = v3->dwID;
    m_hWnd = this->m_Libraries.m_hWnd;
    iIndex = v7;
    SendMessageA(hWnd: m_hWnd, Msg: 0x151u, wParam: v7, lParam: dwID);
    SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x14Eu, wParam: iIndex, lParam: 0);
    CPrefabsDlg::OnSelchangeLibraries(this);
    this->bCurLibraryModified = 1;
    v12 = -1;
    CEditPrefabDlg::~CEditPrefabDlg(this: &dlg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3600
// Name: protected: void CPrefabsDlg::OnAddobject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::OnAddobject(CPrefabsDlg *this)
{
  WPARAM v2; // eax
  LRESULT v3; // eax
  int IsAlwaysLargeImage; // eax
  char *v5; // eax
  char *v6; // edx
  char v7; // cl
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // edi
  char *v10; // esi
  char *v11; // eax
  int v12; // edx
  char v13; // cl
  int v14; // kr04_4
  int v15; // eax
  int v16; // eax
  CPrefabRMF *v17; // eax
  CPrefabRMF *v18; // esi
  CPrefabRMF *v19; // eax
  CPrefabLibrary *v20; // esi
  HWND__ *m_hWnd; // [esp-10h] [ebp-C50h]
  unsigned int v22; // [esp-4h] [ebp-C44h]
  char szFiles[2048]; // [esp+Ch] [ebp-C34h] BYREF
  CFileDialog dlg; // [esp+80Ch] [ebp-434h] BYREF
  char szDir[260]; // [esp+A10h] [ebp-230h] BYREF
  char szFile[260]; // [esp+B14h] [ebp-12Ch] BYREF
  void *v27; // [esp+C18h] [ebp-28h]
  CPrefabLibrary *pLibrary; // [esp+C1Ch] [ebp-24h]
  CPrefabsDlg *v29; // [esp+C20h] [ebp-20h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFullPath; // [esp+C24h] [ebp-1Ch] BYREF
  int bOneFile; // [esp+C28h] [ebp-18h]
  char *p; // [esp+C2Ch] [ebp-14h]
  int iItem; // [esp+C30h] [ebp-10h]
  int v34; // [esp+C3Ch] [ebp-4h]

  m_hWnd = this->m_Libraries.m_hWnd;
  v29 = this;
  v2 = SendMessageA(hWnd: m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v2 == -1 )
    return;
  v3 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
  pLibrary = CPrefabLibrary::FindID(dwID: v3);
  if ( pLibrary == nullptr )
    return;
  CFileDialog::CFileDialog(
    this: &dlg,
    bOpenFileDialog: 1,
    lpszDefExt: nullptr,
    lpszFileName: nullptr,
    dwFlags: 0x20120Cu,
    lpszFilter: "Prefab files (*.map;*.rmf;*.os)|*.map; *.rmf; *.os|Game MAP files (*.map)|*.map|Worldcraft RMF files (*.rmf)|*.rmf||",
    pParentWnd: this,
    dwSize: 0,
    bVistaStyle: 1);
  v34 = 0;
  if ( CFileDialog::DoModal(this: &dlg) == 2 )
    goto LABEL_31;
  v22 = *(_DWORD *)(CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&dlg) + 32);
  IsAlwaysLargeImage = CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&dlg);
  memcpy(dst: (unsigned __int8 *)szFiles, src: *(unsigned __int8 **)(IsAlwaysLargeImage + 28), count: v22);
  v5 = *(char **)(CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&dlg) + 28);
  v6 = szDir;
  do
  {
    v7 = *v5;
    *v6++ = *v5++;
  }
  while ( v7 != 0 );
  bOneFile = 0;
  p = &szFiles[strlen(szDir) + 1];
  if ( *p == 0 )
  {
    bOneFile = 1;
    p = szDir;
  }
  CPrefab::EnableCaching(b: 0);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  strFullPath.m_pszData = m_pszData;
  LOBYTE(v34) = 2;
  iItem = SendMessageA(hWnd: v29->m_Objects.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  while ( 1 )
  {
    v10 = p;
    v11 = p;
    v12 = szFile - p;
    do
    {
      v13 = *v11;
      v11[v12] = *v11;
      ++v11;
    }
    while ( v13 != 0 );
    if ( szFile[0] == 0 )
      break;
    v14 = strlen(szFile);
    p = &v10[v14 + 1];
    if ( bOneFile != 0 )
      ATL::CSimpleStringT<char,0>::SetString(this: &strFullPath, pszSrc: szFile, nLength: v14);
    else
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: &strFullPath,
        pszFormat: "%s\\%s",
        szDir,
        szFile);
    m_pszData = strFullPath.m_pszData;
    v15 = CPrefab::CheckFileType(pszFilename: strFullPath.m_pszData);
    if ( v15 != 0 )
    {
      v16 = v15 - 1;
      if ( v16 == 0 )
      {
        v19 = (CPrefabRMF *)operator new(nSize: 0x22Cu);
        v27 = v19;
        LOBYTE(v34) = 3;
        if ( v19 != nullptr )
          v18 = CPrefabRMF::CPrefabRMF(this: v19);
        else
          v18 = nullptr;
        LOBYTE(v34) = 2;
        CPrefabRMF::Init(this: v18, pszFilename: m_pszData, bLoadNow: 1, dwFlags: 0);
        goto LABEL_27;
      }
      if ( v16 == 1 )
      {
        v17 = (CPrefabRMF *)operator new(nSize: 0x22Cu);
        v27 = v17;
        LOBYTE(v34) = 4;
        if ( v17 != nullptr )
        {
          v18 = CPrefabRMF::CPrefabRMF(this: v17);
          LOBYTE(v34) = 2;
          CPrefabRMF::Init(this: v18, pszFilename: m_pszData, bLoadNow: 1, dwFlags: 1);
        }
        else
        {
          v18 = nullptr;
          LOBYTE(v34) = 2;
          CPrefabRMF::Init(this: nullptr, pszFilename: m_pszData, bLoadNow: 1, dwFlags: 1);
        }
LABEL_27:
        if ( v18 != nullptr )
        {
          CPrefabLibrary::Add(this: pLibrary, pPrefab: (CObject *)v18);
          CPrefabsDlg::AddToObjectList(this: v29, pPrefab: v18, iItem: iItem++, bReplace: 0);
          if ( bOneFile != 0 )
            break;
        }
      }
    }
  }
  v20 = pLibrary;
  CPrefabLibrary::Sort(this: pLibrary);
  v20->Save(this: v20, a2: nullptr, a3: 0);
  CPrefab::FreeAllData();
  CPrefab::EnableCaching(b: 1);
  v29->bCurLibraryModified = 0;
  LOBYTE(v34) = 0;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
LABEL_31:
  v34 = -1;
  CFileDialog::~CFileDialog(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x100F3900
// Name: protected: void CPrefabsDlg::EditObjectInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::EditObjectInfo(CPrefabsDlg *this)
{
  int iCurObject; // esi
  CPrefab *ID; // ebx
  unsigned int ItemData; // eax
  int v4; // eax
  int v5; // eax
  char *m_pszData; // ecx
  char *szName; // edx
  char v8; // al
  char *v9; // ecx
  char *szNotes; // edx
  char v11; // al
  CPrefabsDlg *v12; // esi
  CEditPrefabDlg dlg; // [esp+Ch] [ebp-21Ch] BYREF
  CPrefabsDlg *v14; // [esp+214h] [ebp-14h]
  int iSel; // [esp+218h] [ebp-10h]
  int v16; // [esp+224h] [ebp-4h]

  iCurObject = this->iCurObject;
  v14 = this;
  iSel = -1;
  if ( iCurObject == -1 )
  {
    ID = nullptr;
  }
  else
  {
    ItemData = CListCtrl::GetItemData(this: &this->m_Objects, nItem: iCurObject);
    iSel = iCurObject;
    ID = CPrefab::FindID(dwID: ItemData);
  }
  CEditPrefabDlg::CEditPrefabDlg(this: &dlg, pParent: nullptr);
  v16 = 0;
  if ( ID == (CPrefab *)-4 )
    v4 = 0;
  else
    v4 = strlen(ID->szName);
  ATL::CSimpleStringT<char,0>::SetString(this: &dlg.m_strName, pszSrc: ID->szName, nLength: v4);
  if ( ID == (CPrefab *)-35 )
    v5 = 0;
  else
    v5 = strlen(ID->szNotes);
  ATL::CSimpleStringT<char,0>::SetString(this: &dlg.m_strDescript, pszSrc: ID->szNotes, nLength: v5);
  CEditPrefabDlg::SetRanges(this: &dlg, iMaxDescript: 500, iMaxName: -1);
  if ( CDialog::DoModal(this: &dlg) != 2 )
  {
    m_pszData = dlg.m_strName.m_pszData;
    szName = ID->szName;
    do
    {
      v8 = *m_pszData;
      *szName++ = *m_pszData++;
    }
    while ( v8 != 0 );
    v9 = dlg.m_strDescript.m_pszData;
    szNotes = ID->szNotes;
    do
    {
      v11 = *v9;
      *szNotes++ = *v9++;
    }
    while ( v11 != 0 );
    v12 = v14;
    CPrefabsDlg::AddToObjectList(this: v14, pPrefab: ID, iItem: iSel, bReplace: 1);
    v12->bCurLibraryModified = 1;
  }
  v16 = -1;
  CEditPrefabDlg::~CEditPrefabDlg(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x100F3A40
// Name: protected: void CPrefabsDlg::OnExportobject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::OnExportobject(CPrefabsDlg *this)
{
  CPrefabsDlg *v1; // edi
  unsigned int ItemData; // eax
  CPrefab *ID; // esi
  CAfxStringMgr *StringManager; // eax
  int v5; // eax
  char *m_pszData; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *PathName; // eax
  const char *v8; // ecx
  ATL::CStringData *v9; // eax
  volatile signed __int32 *v10; // edi
  ATL::CStringData *v11; // ebx
  char *v12; // eax
  int v13; // edi
  int v14; // eax
  unsigned int v15; // ebx
  volatile signed __int32 *v16; // esi
  HWND__ *m_hWnd; // [esp-10h] [ebp-238h]
  CFileDialog dlg; // [esp+4h] [ebp-224h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+208h] [ebp-20h] BYREF
  CPrefab *pPrefab; // [esp+20Ch] [ebp-1Ch]
  CPrefabsDlg *v21; // [esp+210h] [ebp-18h]
  int iIndex; // [esp+214h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFilename; // [esp+218h] [ebp-10h] BYREF
  int v24; // [esp+224h] [ebp-4h]

  v1 = this;
  m_hWnd = this->m_Objects.m_hWnd;
  v21 = this;
  iIndex = SendMessageA(hWnd: m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 2);
  if ( iIndex == -1 )
    return;
  while ( 1 )
  {
    ItemData = CListCtrl::GetItemData(this: &v1->m_Objects, nItem: iIndex);
    ID = CPrefab::FindID(dwID: ItemData);
    pPrefab = ID;
    if ( ID != nullptr )
      break;
LABEL_30:
    iIndex = SendMessageA(hWnd: v1->m_Objects.m_hWnd, Msg: 0x100Cu, wParam: iIndex, lParam: 2);
    if ( iIndex == -1 )
      return;
  }
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strFilename.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v24 = 1;
  if ( ID == (CPrefab *)-4 )
    v5 = 0;
  else
    v5 = strlen(ID->szName);
  ATL::CSimpleStringT<char,0>::SetString(this: &strFilename, pszSrc: ID->szName, nLength: v5);
  m_pszData = strFilename.m_pszData;
  CFileDialog::CFileDialog(
    this: &dlg,
    bOpenFileDialog: 0,
    lpszDefExt: "map",
    lpszFileName: strFilename.m_pszData,
    dwFlags: 6u,
    lpszFilter: "Map files|*.map;*.rmf|",
    pParentWnd: v1,
    dwSize: 0,
    bVistaStyle: 1);
  LOBYTE(v24) = 2;
  if ( CFileDialog::DoModal(this: &dlg) != 2 )
  {
    PathName = CFileDialog::GetPathName(this: &dlg, &result);
    LOBYTE(v24) = 4;
    v8 = PathName->m_pszData;
    v9 = (ATL::CStringData *)(PathName->m_pszData - 16);
    v10 = (volatile signed __int32 *)(m_pszData - 16);
    if ( v9 != (ATL::CStringData *)(m_pszData - 16) )
    {
      if ( *((int *)v10 + 3) >= 0 && v9->pStringMgr == (ATL::IAtlStringMgr *)*v10 )
      {
        v11 = ATL::CSimpleStringT<char,0>::CloneData(pData: v9);
        if ( _InterlockedDecrement(v10 + 3) <= 0 )
          (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v10 + 4))(a1: v10);
        m_pszData = (char *)&v11[1];
        strFilename.m_pszData = (char *)&v11[1];
      }
      else
      {
        ATL::CSimpleStringT<char,0>::SetString(this: &strFilename, pszSrc: v8, nLength: *((_DWORD *)v8 - 3));
        m_pszData = strFilename.m_pszData;
      }
    }
    LOBYTE(v24) = 2;
    v12 = result.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v12 + 4))(a1: v12);
    if ( *((int *)m_pszData - 3) > 0 )
    {
      _mbschr(string: m_pszData, c: 0x2Eu);
      if ( v14 != 0 )
        v13 = v14 - (_DWORD)m_pszData;
      else
        v13 = -1;
    }
    else
    {
      v13 = -1;
    }
    v15 = 0;
    if ( v13 != -1 )
    {
      if ( ((1 - *((_DWORD *)m_pszData - 1)) | *((_DWORD *)m_pszData - 2)) < 0 )
      {
        ATL::CSimpleStringT<char,0>::PrepareWrite2(this: &strFilename, nLength: 0);
        m_pszData = strFilename.m_pszData;
      }
      if ( V_strncasecmp(s1: &m_pszData[v13 + 1], s2: "map", n: 3) == 0 )
        v15 = 1;
    }
    pPrefab->Save(this: pPrefab, a2: m_pszData, a3: v15);
    LOBYTE(v24) = 1;
    CFileDialog::~CFileDialog(this: &dlg);
    v24 = -1;
    if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
      (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
        a1: *((_DWORD *)m_pszData - 4),
        a2: m_pszData - 16);
    v1 = v21;
    goto LABEL_30;
  }
  LOBYTE(v24) = 1;
  CFileDialog::~CFileDialog(this: &dlg);
  v24 = -1;
  v16 = (volatile signed __int32 *)(m_pszData - 16);
  if ( _InterlockedDecrement(v16 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v16 + 4))(a1: v16);
}

//------------------------------------------------------------------------------
// Address: 0x100F3CF0
// Name: protected: void CPrefabsDlg::OnEditlibrary(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabsDlg::OnEditlibrary(CPrefabsDlg *this)
{
  WPARAM v2; // eax
  WPARAM v3; // ebx
  LRESULT v4; // eax
  int m_szName; // eax
  int szNotes; // eax
  char *m_pszData; // ecx
  char *v8; // edx
  char v9; // al
  WPARAM v10; // eax
  CEditPrefabDlg dlg; // [esp+Ch] [ebp-21Ch] BYREF
  char *v12; // [esp+214h] [ebp-14h]
  CPrefabLibrary *ID; // [esp+218h] [ebp-10h]
  int v14; // [esp+224h] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  v3 = v2;
  if ( v2 != -1 )
  {
    v4 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
    ID = CPrefabLibrary::FindID(dwID: v4);
    if ( ID != nullptr )
    {
      CEditPrefabDlg::CEditPrefabDlg(this: &dlg, pParent: nullptr);
      v14 = 0;
      m_szName = (int)ID->m_szName;
      if ( ID != (CPrefabLibrary *)-32 )
      {
        v12 = &ID->m_szName[1];
        m_szName = strlen(ID->m_szName);
      }
      ATL::CSimpleStringT<char,0>::SetString(this: &dlg.m_strName, pszSrc: ID->m_szName, nLength: m_szName);
      szNotes = (int)ID->szNotes;
      if ( ID != (CPrefabLibrary *)-63 )
        szNotes = strlen(ID->szNotes);
      ATL::CSimpleStringT<char,0>::SetString(this: &dlg.m_strDescript, pszSrc: ID->szNotes, nLength: szNotes);
      while ( CDialog::DoModal(this: &dlg) != 2 )
      {
        if ( IsValidFilename(pszString: dlg.m_strName.m_pszData) != 0 )
        {
          ID->SetName(this: ID, a2: dlg.m_strName.m_pszData);
          m_pszData = dlg.m_strDescript.m_pszData;
          v8 = ID->szNotes;
          do
          {
            v9 = *m_pszData;
            *v8++ = *m_pszData++;
          }
          while ( v9 != 0 );
          SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
          SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x144u, wParam: v3, lParam: 0);
          v10 = SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x14Au, wParam: v3, lParam: (LPARAM)ID->m_szName);
          SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x151u, wParam: v10, lParam: ID->dwID);
          SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
          InvalidateRect(hWnd: this->m_Libraries.m_hWnd, lpRect: nullptr, bErase: true);
          SendMessageA(hWnd: this->m_Libraries.m_hWnd, Msg: 0x14Eu, wParam: v3, lParam: 0);
          CPrefabsDlg::OnSelchangeLibraries(this);
          this->bCurLibraryModified = 1;
          break;
        }
        if ( AfxMessageBox(
               lpszText: "That's not a valid name - some of the characters aren't\n"
               "acceptable. Try using a name with only A-Z, 0-9, space,\n"
               "and these characters: $%`-_@~'!(){}^#&",
               nType: 1u,
               nIDHelp: 0) != 1 )
          break;
      }
      v14 = -1;
      CEditPrefabDlg::~CEditPrefabDlg(this: &dlg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3ED0
// Name: protected: int CPrefabsDlg::HandleEditObjectPopup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabsDlg::HandleEditObjectPopup(CPrefabsDlg *this, unsigned int nID)
{
  if ( nID == 110 )
  {
    CPrefabsDlg::EditObjectInfo(this);
  }
  else if ( nID == 111 )
  {
    CPrefabsDlg::EditObjectData(this);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F3F00
// Name: protected: virtual struct AFX_MSGMAP const __near * CPrefabsDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CPrefabsDlg::GetMessageMap(CPrefabsDlg *this)
{
  return (const AFX_MSGMAP *)&off_105F17F0;
}

//------------------------------------------------------------------------------
// Address: 0x1033B9E4
// Name: public: struct CComCtlWrapper::InitCommonControls_Type CComCtlWrapper::GetProcAddress_InitCommonControls(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::InitCommonControls_Type *__thiscall CComCtlWrapper::GetProcAddress_InitCommonControls(
        CComCtlWrapper *this,
        CComCtlWrapper::InitCommonControls_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__InitCommonControls.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__InitCommonControls.p = (void (__stdcall *)())GetProcAddress(
                                                            hModule: ModuleHandleA,
                                                            lpProcName: "InitCommonControls");
  }
  result->p = (void (__stdcall *)())this->m__InitCommonControls;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033BA13
// Name: public: void CComCtlWrapper::_InitCommonControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CComCtlWrapper::_InitCommonControls(CComCtlWrapper *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  void (__stdcall *p)(); // esi
  int v4; // [esp+0h] [ebp-30h]
  CComCtlWrapper::InitCommonControls_Type result; // [esp+10h] [ebp-20h] BYREF
  ULONG_PTR ulActCtxCookie[6]; // [esp+14h] [ebp-1Ch] BYREF
  int v7; // [esp+2Ch] [ebp-4h]

  ulActCtxCookie[0] = 0;
  ModuleState = AfxGetModuleState();
  if ( ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: ulActCtxCookie) )
  {
    v7 = 0;
    CComCtlWrapper::GetProcAddress_InitCommonControls(this, &result);
    p = this->m__InitCommonControls.p;
    if ( p == nullptr )
      AfxThrowInvalidArgException();
    ((void (__stdcall *)(int))p)(a1: v4);
    v7 = -2;
    DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie[0]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033BA80
// Name: public: struct CComCtlWrapper::InitCommonControlsEx_Type CComCtlWrapper::GetProcAddress_InitCommonControlsEx(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::InitCommonControlsEx_Type *__thiscall CComCtlWrapper::GetProcAddress_InitCommonControlsEx(
        CComCtlWrapper *this,
        CComCtlWrapper::InitCommonControlsEx_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__InitCommonControlsEx.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__InitCommonControlsEx.p = (int (__stdcall *)(tagINITCOMMONCONTROLSEX *))GetProcAddress(
                                                                                      hModule: ModuleHandleA,
                                                                                      lpProcName: "InitCommonControlsEx");
  }
  result->p = (int (__stdcall *)(tagINITCOMMONCONTROLSEX *))this->m__InitCommonControlsEx;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033BAAF
// Name: public: int CComCtlWrapper::_InitCommonControlsEx(struct tagINITCOMMONCONTROLSEX __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_InitCommonControlsEx(CComCtlWrapper *this, tagINITCOMMONCONTROLSEX *unnamed1)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v4; // eax
  int (__stdcall *p)(tagINITCOMMONCONTROLSEX *); // eax
  BOOL v7; // esi
  DWORD LastError; // edi
  int v9; // [esp+0h] [ebp-34h]
  CComCtlWrapper::InitCommonControlsEx_Type v10; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  int v12; // [esp+18h] [ebp-1Ch]
  int v13; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v4 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v12 = 0;
  if ( !v4 )
    return 0;
  v13 = 0;
  CComCtlWrapper::GetProcAddress_InitCommonControlsEx(this, result: &v10);
  p = this->m__InitCommonControlsEx.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v12 = ((int (__stdcall *)(tagINITCOMMONCONTROLSEX *, int))p)(a1: unnamed1, a2: v9);
  v13 = -2;
  v7 = v12 == 0;
  if ( v12 != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v7 )
    SetLastError(dwErrCode: LastError);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1034185B
// Name: public: struct CComCtlWrapper::ImageList_GetImageInfo_Type CComCtlWrapper::GetProcAddress_ImageList_GetImageInfo(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_GetImageInfo_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_GetImageInfo(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_GetImageInfo_Type *result)
{
  CComCtlWrapper::ImageList_GetImageInfo_Type *p_m__ImageList_GetImageInfo; // esi
  HMODULE ModuleHandleA; // eax

  p_m__ImageList_GetImageInfo = &this->m__ImageList_GetImageInfo;
  if ( this->m__ImageList_GetImageInfo.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    p_m__ImageList_GetImageInfo->p = (int (__stdcall *)(struct _IMAGELIST *, int, _IMAGEINFO *))GetProcAddress(
                                                                                                  hModule: ModuleHandleA,
                                                                                                  lpProcName: "ImageList_GetImageInfo");
  }
  result->p = p_m__ImageList_GetImageInfo->p;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034188B
// Name: public: int CComCtlWrapper::_ImageList_GetImageInfo(struct _IMAGELIST __near *,int,struct _IMAGEINFO __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_GetImageInfo(
        CComCtlWrapper *this,
        struct _IMAGELIST *himl,
        int i,
        _IMAGEINFO *pImageInfo)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v6; // eax
  int (__stdcall *p)(struct _IMAGELIST *, int, _IMAGEINFO *); // eax
  BOOL v9; // esi
  DWORD LastError; // edi
  int v11; // [esp+0h] [ebp-34h]
  CComCtlWrapper::ImageList_GetImageInfo_Type v12; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  int v14; // [esp+18h] [ebp-1Ch]
  int v15; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v6 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v14 = 0;
  if ( !v6 )
    return 0;
  v15 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_GetImageInfo(this, result: &v12);
  p = this->m__ImageList_GetImageInfo.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v14 = ((int (__stdcall *)(struct _IMAGELIST *, int, _IMAGEINFO *, int))p)(a1: himl, a2: i, a3: pImageInfo, a4: v11);
  v15 = -2;
  v9 = v14 == 0;
  if ( v14 != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v9 )
    SetLastError(dwErrCode: LastError);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x1034315C
// Name: public: CComCtlWrapper::CComCtlWrapper(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper *__thiscall CComCtlWrapper::CComCtlWrapper(CComCtlWrapper *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strModuleName; // [esp+10h] [ebp-10h] BYREF
  int v4; // [esp+1Ch] [ebp-4h]

  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &strModuleName,
    pszSrc: "comctl32.dll");
  v4 = 0;
  CDllIsolationWrapperBase::CDllIsolationWrapperBase(this, &strModuleName);
  ATL::CStringData::Release(this: (ATL::CStringData *)strModuleName.m_pszData - 1);
  this->__vftable = (CComCtlWrapper_vtbl *)&CComCtlWrapper::`vftable';
  this->m__InitCommonControls.p = nullptr;
  this->m__InitCommonControlsEx.p = nullptr;
  this->m__ImageList_Create.p = nullptr;
  this->m__ImageList_Destroy.p = nullptr;
  this->m__ImageList_GetImageCount.p = nullptr;
  this->m__ImageList_SetImageCount.p = nullptr;
  this->m__ImageList_Add.p = nullptr;
  this->m__ImageList_ReplaceIcon.p = nullptr;
  this->m__ImageList_SetBkColor.p = nullptr;
  this->m__ImageList_GetBkColor.p = nullptr;
  this->m__ImageList_SetOverlayImage.p = nullptr;
  this->m__ImageList_Draw.p = nullptr;
  this->m__ImageList_Replace.p = nullptr;
  this->m__ImageList_AddMasked.p = nullptr;
  this->m__ImageList_DrawEx.p = nullptr;
  this->m__ImageList_DrawIndirect.p = nullptr;
  this->m__ImageList_Remove.p = nullptr;
  this->m__ImageList_GetIcon.p = nullptr;
  this->m__ImageList_LoadImageA.p = nullptr;
  this->m__ImageList_LoadImageW.p = nullptr;
  this->m__ImageList_Copy.p = nullptr;
  this->m__ImageList_BeginDrag.p = nullptr;
  this->m__ImageList_EndDrag.p = nullptr;
  this->m__ImageList_DragEnter.p = nullptr;
  this->m__ImageList_DragLeave.p = nullptr;
  this->m__ImageList_DragMove.p = nullptr;
  this->m__ImageList_SetDragCursorImage.p = nullptr;
  this->m__ImageList_DragShowNolock.p = nullptr;
  this->m__ImageList_GetDragImage.p = nullptr;
  this->m__ImageList_Read.p = nullptr;
  this->m__ImageList_Write.p = nullptr;
  this->m__ImageList_ReadEx.p = nullptr;
  this->m__ImageList_WriteEx.p = nullptr;
  this->m__ImageList_GetIconSize.p = nullptr;
  this->m__ImageList_SetIconSize.p = nullptr;
  this->m__ImageList_GetImageInfo.p = nullptr;
  this->m__ImageList_Merge.p = nullptr;
  this->m__ImageList_Duplicate.p = nullptr;
  this->m__CreateToolbarEx.p = nullptr;
  this->m__CreateMappedBitmap.p = nullptr;
  this->m__DrawStatusTextA.p = nullptr;
  this->m__DrawStatusTextW.p = nullptr;
  this->m__CreateStatusWindowA.p = nullptr;
  this->m__CreateStatusWindowW.p = nullptr;
  this->m__MenuHelp.p = nullptr;
  this->m__ShowHideMenuCtl.p = nullptr;
  this->m__GetEffectiveClientRect.p = nullptr;
  this->m__MakeDragList.p = nullptr;
  this->m__DrawInsert.p = nullptr;
  this->m__LBItemFromPt.p = nullptr;
  this->m__CreateUpDownControl.p = nullptr;
  this->m__InitMUILanguage.p = nullptr;
  this->m__GetMUILanguage.p = nullptr;
  this->m__DSA_Create.p = nullptr;
  this->m__DSA_Destroy.p = nullptr;
  this->m__DSA_DestroyCallback.p = nullptr;
  this->m__DSA_GetItemPtr.p = nullptr;
  this->m__DSA_InsertItem.p = nullptr;
  this->m__DPA_Create.p = nullptr;
  this->m__DPA_Destroy.p = nullptr;
  this->m__DPA_DeletePtr.p = nullptr;
  this->m__DPA_DeleteAllPtrs.p = nullptr;
  this->m__DPA_EnumCallback.p = nullptr;
  this->m__DPA_DestroyCallback.p = nullptr;
  this->m__DPA_SetPtr.p = nullptr;
  this->m__DPA_InsertPtr.p = nullptr;
  this->m__DPA_GetPtr.p = nullptr;
  this->m__DPA_Sort.p = nullptr;
  this->m__DPA_Search.p = nullptr;
  this->m__Str_SetPtrW.p = nullptr;
  this->m___TrackMouseEvent.p = nullptr;
  this->m__FlatSB_EnableScrollBar.p = nullptr;
  this->m__FlatSB_ShowScrollBar.p = nullptr;
  this->m__FlatSB_GetScrollRange.p = nullptr;
  this->m__FlatSB_GetScrollInfo.p = nullptr;
  this->m__FlatSB_GetScrollPos.p = nullptr;
  this->m__FlatSB_GetScrollProp.p = nullptr;
  this->m__FlatSB_GetScrollPropPtr.p = nullptr;
  this->m__FlatSB_SetScrollPos.p = nullptr;
  this->m__FlatSB_SetScrollInfo.p = nullptr;
  this->m__FlatSB_SetScrollRange.p = nullptr;
  this->m__FlatSB_SetScrollProp.p = nullptr;
  this->m__InitializeFlatSB.p = nullptr;
  this->m__UninitializeFlatSB.p = nullptr;
  this->m__SetWindowSubclass.p = nullptr;
  this->m__GetWindowSubclass.p = nullptr;
  this->m__RemoveWindowSubclass.p = nullptr;
  this->m__DefSubclassProc.p = nullptr;
  this->m__DrawShadowText.p = nullptr;
  this->m__CreatePropertySheetPageA.p = nullptr;
  this->m__CreatePropertySheetPageW.p = nullptr;
  this->m__DestroyPropertySheetPage.p = nullptr;
  this->m__PropertySheetA.p = nullptr;
  this->m__PropertySheetW.p = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034AD64
// Name: public: struct CComCtlWrapper::ImageList_Create_Type CComCtlWrapper::GetProcAddress_ImageList_Create(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_Create_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_Create(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_Create_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__ImageList_Create.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__ImageList_Create.p = (struct _IMAGELIST *(__stdcall *)(int, int, unsigned int, int, int))GetProcAddress(hModule: ModuleHandleA, lpProcName: "ImageList_Create");
  }
  result->p = (struct _IMAGELIST *(__stdcall *)(int, int, unsigned int, int, int))this->m__ImageList_Create;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034AD93
// Name: public: struct _IMAGELIST __near * CComCtlWrapper::_ImageList_Create(int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
struct _IMAGELIST *__thiscall CComCtlWrapper::_ImageList_Create(
        CComCtlWrapper *this,
        int cx,
        int cy,
        unsigned int flags,
        int cInitial,
        int cGrow)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v8; // eax
  struct _IMAGELIST *(__stdcall *p)(int, int, unsigned int, int, int); // eax
  BOOL v11; // esi
  DWORD LastError; // edi
  int v13; // [esp+0h] [ebp-34h]
  CComCtlWrapper::ImageList_Create_Type v14; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  struct _IMAGELIST *v16; // [esp+18h] [ebp-1Ch]
  int v17; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v8 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v16 = nullptr;
  if ( !v8 )
    return nullptr;
  v17 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_Create(this, result: &v14);
  p = this->m__ImageList_Create.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v16 = (struct _IMAGELIST *)((int (__stdcall *)(int, int, unsigned int, int, int, int))p)(
                               a1: cx,
                               a2: cy,
                               a3: flags,
                               a4: cInitial,
                               a5: cGrow,
                               a6: v13);
  v17 = -2;
  v11 = v16 == nullptr;
  if ( v16 != nullptr )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v11 )
    SetLastError(dwErrCode: LastError);
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x1034AE43
// Name: public: struct CComCtlWrapper::ImageList_Destroy_Type CComCtlWrapper::GetProcAddress_ImageList_Destroy(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_Destroy_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_Destroy(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_Destroy_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__ImageList_Destroy.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__ImageList_Destroy.p = (int (__stdcall *)(struct _IMAGELIST *))GetProcAddress(
                                                                             hModule: ModuleHandleA,
                                                                             lpProcName: "ImageList_Destroy");
  }
  result->p = (int (__stdcall *)(struct _IMAGELIST *))this->m__ImageList_Destroy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034AE72
// Name: public: int CComCtlWrapper::_ImageList_Destroy(struct _IMAGELIST __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_Destroy(CComCtlWrapper *this, struct _IMAGELIST *himl)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v4; // eax
  int (__stdcall *p)(struct _IMAGELIST *); // eax
  BOOL v7; // esi
  DWORD LastError; // edi
  int v9; // [esp+0h] [ebp-34h]
  CComCtlWrapper::ImageList_Destroy_Type v10; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  int v12; // [esp+18h] [ebp-1Ch]
  int v13; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v4 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v12 = 0;
  if ( !v4 )
    return 0;
  v13 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_Destroy(this, result: &v10);
  p = this->m__ImageList_Destroy.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v12 = ((int (__stdcall *)(struct _IMAGELIST *, int))p)(a1: himl, a2: v9);
  v13 = -2;
  v7 = v12 == 0;
  if ( v12 != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v7 )
    SetLastError(dwErrCode: LastError);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1034AF16
// Name: public: struct CComCtlWrapper::ImageList_LoadImageA_Type CComCtlWrapper::GetProcAddress_ImageList_LoadImageA(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_LoadImageA_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_LoadImageA(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_LoadImageA_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__ImageList_LoadImageA.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__ImageList_LoadImageA.p = (struct _IMAGELIST *(__stdcall *)(HINSTANCE__ *, const char *, int, int, unsigned int, unsigned int, unsigned int))GetProcAddress(hModule: ModuleHandleA, lpProcName: "ImageList_LoadImageA");
  }
  result->p = (struct _IMAGELIST *(__stdcall *)(HINSTANCE__ *, const char *, int, int, unsigned int, unsigned int, unsigned int))this->m__ImageList_LoadImageA;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034AF45
// Name: public: struct _IMAGELIST __near * CComCtlWrapper::_ImageList_LoadImageA(struct HINSTANCE__ __near *,char const __near *,int,int,unsigned long,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct _IMAGELIST *__thiscall CComCtlWrapper::_ImageList_LoadImageA(
        CComCtlWrapper *this,
        HINSTANCE__ *hi,
        const char *lpbmp,
        int cx,
        int cGrow,
        unsigned int crMask,
        unsigned int uType,
        unsigned int uFlags)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v10; // eax
  struct _IMAGELIST *(__stdcall *p)(HINSTANCE__ *, const char *, int, int, unsigned int, unsigned int, unsigned int); // eax
  BOOL v13; // esi
  DWORD LastError; // edi
  int v15; // [esp+0h] [ebp-34h]
  CComCtlWrapper::ImageList_LoadImageA_Type v16; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  struct _IMAGELIST *v18; // [esp+18h] [ebp-1Ch]
  int v19; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v10 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v18 = nullptr;
  if ( !v10 )
    return nullptr;
  v19 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_LoadImageA(this, result: &v16);
  p = this->m__ImageList_LoadImageA.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v18 = (struct _IMAGELIST *)((int (__stdcall *)(HINSTANCE__ *, const char *, int, int, unsigned int, unsigned int, unsigned int, int))p)(
                               a1: hi,
                               a2: lpbmp,
                               a3: cx,
                               a4: cGrow,
                               a5: crMask,
                               a6: uType,
                               a7: uFlags,
                               a8: v15);
  v19 = -2;
  v13 = v18 == nullptr;
  if ( v18 != nullptr )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v13 )
    SetLastError(dwErrCode: LastError);
  return v18;
}

//------------------------------------------------------------------------------
// Address: 0x10350F2E
// Name: public: struct CComCtlWrapper::CreatePropertySheetPageA_Type CComCtlWrapper::GetProcAddress_CreatePropertySheetPageA(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::CreatePropertySheetPageA_Type *__thiscall CComCtlWrapper::GetProcAddress_CreatePropertySheetPageA(
        CComCtlWrapper *this,
        CComCtlWrapper::CreatePropertySheetPageA_Type *result)
{
  CComCtlWrapper::CreatePropertySheetPageA_Type *p_m__CreatePropertySheetPageA; // esi
  HMODULE ModuleHandleA; // eax

  p_m__CreatePropertySheetPageA = &this->m__CreatePropertySheetPageA;
  if ( this->m__CreatePropertySheetPageA.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    p_m__CreatePropertySheetPageA->p = (struct _PSP *(__stdcall *)(const _PROPSHEETPAGEA *))GetProcAddress(
                                                                                              hModule: ModuleHandleA,
                                                                                              lpProcName: "CreatePropertySheetPageA");
  }
  result->p = p_m__CreatePropertySheetPageA->p;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10350F5E
// Name: public: struct _PSP __near * CComCtlWrapper::_CreatePropertySheetPageA(struct _PROPSHEETPAGEA const __near *)
// Source: json
//------------------------------------------------------------------------------
struct _PSP *__thiscall CComCtlWrapper::_CreatePropertySheetPageA(
        CComCtlWrapper *this,
        const _PROPSHEETPAGEA *constPropSheetPagePointer)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v4; // eax
  struct _PSP *(__stdcall *p)(const _PROPSHEETPAGEA *); // eax
  BOOL v7; // esi
  DWORD LastError; // edi
  int v9; // [esp+0h] [ebp-34h]
  CComCtlWrapper::CreatePropertySheetPageA_Type v10; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  struct _PSP *v12; // [esp+18h] [ebp-1Ch]
  int v13; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v4 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v12 = nullptr;
  if ( !v4 )
    return nullptr;
  v13 = 0;
  CComCtlWrapper::GetProcAddress_CreatePropertySheetPageA(this, result: &v10);
  p = this->m__CreatePropertySheetPageA.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v12 = (struct _PSP *)((int (__stdcall *)(const _PROPSHEETPAGEA *, int))p)(a1: constPropSheetPagePointer, a2: v9);
  v13 = -2;
  v7 = v12 == nullptr;
  if ( v12 != nullptr )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v7 )
    SetLastError(dwErrCode: LastError);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x10351005
// Name: public: struct CComCtlWrapper::DestroyPropertySheetPage_Type CComCtlWrapper::GetProcAddress_DestroyPropertySheetPage(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::DestroyPropertySheetPage_Type *__thiscall CComCtlWrapper::GetProcAddress_DestroyPropertySheetPage(
        CComCtlWrapper *this,
        CComCtlWrapper::DestroyPropertySheetPage_Type *result)
{
  CComCtlWrapper::DestroyPropertySheetPage_Type *p_m__DestroyPropertySheetPage; // esi
  HMODULE ModuleHandleA; // eax

  p_m__DestroyPropertySheetPage = &this->m__DestroyPropertySheetPage;
  if ( this->m__DestroyPropertySheetPage.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    p_m__DestroyPropertySheetPage->p = (int (__stdcall *)(struct _PSP *))GetProcAddress(
                                                                           hModule: ModuleHandleA,
                                                                           lpProcName: "DestroyPropertySheetPage");
  }
  result->p = p_m__DestroyPropertySheetPage->p;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10351035
// Name: public: int CComCtlWrapper::_DestroyPropertySheetPage(struct _PSP __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_DestroyPropertySheetPage(CComCtlWrapper *this, struct _PSP *unnamed1)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v4; // eax
  int (__stdcall *p)(struct _PSP *); // eax
  BOOL v7; // esi
  DWORD LastError; // edi
  int v9; // [esp+0h] [ebp-34h]
  CComCtlWrapper::DestroyPropertySheetPage_Type v10; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  int v12; // [esp+18h] [ebp-1Ch]
  int v13; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v4 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v12 = 0;
  if ( !v4 )
    return 0;
  v13 = 0;
  CComCtlWrapper::GetProcAddress_DestroyPropertySheetPage(this, result: &v10);
  p = this->m__DestroyPropertySheetPage.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v12 = ((int (__stdcall *)(struct _PSP *, int))p)(a1: unnamed1, a2: v9);
  v13 = -2;
  v7 = v12 == 0;
  if ( v12 != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v7 )
    SetLastError(dwErrCode: LastError);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x103510DC
// Name: public: struct CComCtlWrapper::PropertySheetA_Type CComCtlWrapper::GetProcAddress_PropertySheetA(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::PropertySheetA_Type *__thiscall CComCtlWrapper::GetProcAddress_PropertySheetA(
        CComCtlWrapper *this,
        CComCtlWrapper::PropertySheetA_Type *result)
{
  CComCtlWrapper::PropertySheetA_Type *p_m__PropertySheetA; // esi
  HMODULE ModuleHandleA; // eax

  p_m__PropertySheetA = &this->m__PropertySheetA;
  if ( this->m__PropertySheetA.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    p_m__PropertySheetA->p = (int (__stdcall *)(const _PROPSHEETHEADERA_V2 *))GetProcAddress(
                                                                                hModule: ModuleHandleA,
                                                                                lpProcName: "PropertySheetA");
  }
  result->p = p_m__PropertySheetA->p;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035110C
// Name: public: int CComCtlWrapper::_PropertySheetA(struct _PROPSHEETHEADERA_V2 const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_PropertySheetA(CComCtlWrapper *this, const _PROPSHEETHEADERA_V2 *unnamed1)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v4; // eax
  int (__stdcall *p)(const _PROPSHEETHEADERA_V2 *); // esi
  BOOL v7; // esi
  DWORD LastError; // edi
  int v9; // [esp+0h] [ebp-34h]
  CComCtlWrapper::PropertySheetA_Type v10; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  int v12; // [esp+18h] [ebp-1Ch]
  int v13; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v4 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v12 = -1;
  if ( !v4 )
    return -1;
  v13 = 0;
  CComCtlWrapper::GetProcAddress_PropertySheetA(this, result: &v10);
  p = this->m__PropertySheetA.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v12 = ((int (__stdcall *)(const _PROPSHEETHEADERA_V2 *, int))p)(a1: unnamed1, a2: v9);
  v13 = -2;
  v7 = v12 == -1;
  if ( v12 == -1 )
    LastError = GetLastError();
  else
    LastError = 0;
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v7 )
    SetLastError(dwErrCode: LastError);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1038A47B
// Name: public: struct CComCtlWrapper::ImageList_GetImageCount_Type CComCtlWrapper::GetProcAddress_ImageList_GetImageCount(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_GetImageCount_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_GetImageCount(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_GetImageCount_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__ImageList_GetImageCount.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__ImageList_GetImageCount.p = (int (__stdcall *)(struct _IMAGELIST *))GetProcAddress(
                                                                                   hModule: ModuleHandleA,
                                                                                   lpProcName: "ImageList_GetImageCount");
  }
  result->p = (int (__stdcall *)(struct _IMAGELIST *))this->m__ImageList_GetImageCount;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1038A4AA
// Name: public: int CComCtlWrapper::_ImageList_GetImageCount(struct _IMAGELIST __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_GetImageCount(CComCtlWrapper *this, struct _IMAGELIST *himl)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v4; // eax
  int (__stdcall *p)(struct _IMAGELIST *); // eax
  BOOL v7; // esi
  DWORD LastError; // edi
  int v9; // [esp+0h] [ebp-34h]
  CComCtlWrapper::ImageList_GetImageCount_Type v10; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  int v12; // [esp+18h] [ebp-1Ch]
  int v13; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v4 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v12 = 0;
  if ( !v4 )
    return 0;
  v13 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_GetImageCount(this, result: &v10);
  p = this->m__ImageList_GetImageCount.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v12 = ((int (__stdcall *)(struct _IMAGELIST *, int))p)(a1: himl, a2: v9);
  v13 = -2;
  v7 = v12 == 0;
  if ( v12 != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v7 )
    SetLastError(dwErrCode: LastError);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1038A708
// Name: public: struct CComCtlWrapper::ImageList_Remove_Type CComCtlWrapper::GetProcAddress_ImageList_Remove(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_Remove_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_Remove(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_Remove_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__ImageList_Remove.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__ImageList_Remove.p = (int (__stdcall *)(struct _IMAGELIST *, int))GetProcAddress(
                                                                                 hModule: ModuleHandleA,
                                                                                 lpProcName: "ImageList_Remove");
  }
  result->p = (int (__stdcall *)(struct _IMAGELIST *, int))this->m__ImageList_Remove;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1038A737
// Name: public: int CComCtlWrapper::_ImageList_Remove(struct _IMAGELIST __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_Remove(CComCtlWrapper *this, struct _IMAGELIST *himl, int i)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v5; // eax
  int (__stdcall *p)(struct _IMAGELIST *, int); // eax
  BOOL v8; // esi
  DWORD LastError; // edi
  int v10; // [esp+0h] [ebp-34h]
  CComCtlWrapper::ImageList_Remove_Type v11; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  int v13; // [esp+18h] [ebp-1Ch]
  int v14; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v5 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v13 = 0;
  if ( !v5 )
    return 0;
  v14 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_Remove(this, result: &v11);
  p = this->m__ImageList_Remove.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v13 = ((int (__stdcall *)(struct _IMAGELIST *, int, int))p)(a1: himl, a2: i, a3: v10);
  v14 = -2;
  v8 = v13 == 0;
  if ( v13 != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v8 )
    SetLastError(dwErrCode: LastError);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x103904B8
// Name: public: struct CComCtlWrapper::ImageList_GetIcon_Type CComCtlWrapper::GetProcAddress_ImageList_GetIcon(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_GetIcon_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_GetIcon(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_GetIcon_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__ImageList_GetIcon.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__ImageList_GetIcon.p = (HICON__ *(__stdcall *)(struct _IMAGELIST *, int, unsigned int))GetProcAddress(
                                                                                                     hModule: ModuleHandleA,
                                                                                                     lpProcName: "ImageList_GetIcon");
  }
  result->p = (HICON__ *(__stdcall *)(struct _IMAGELIST *, int, unsigned int))this->m__ImageList_GetIcon;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103904E7
// Name: public: struct HICON__ __near * CComCtlWrapper::_ImageList_GetIcon(struct _IMAGELIST __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HICON__ *__thiscall CComCtlWrapper::_ImageList_GetIcon(
        CComCtlWrapper *this,
        struct _IMAGELIST *himl,
        int i,
        unsigned int flags)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v6; // eax
  HICON__ *(__stdcall *p)(struct _IMAGELIST *, int, unsigned int); // eax
  BOOL v9; // esi
  DWORD LastError; // edi
  int v11; // [esp+0h] [ebp-34h]
  CComCtlWrapper::ImageList_GetIcon_Type v12; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  HICON__ *v14; // [esp+18h] [ebp-1Ch]
  int v15; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v6 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v14 = nullptr;
  if ( !v6 )
    return nullptr;
  v15 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_GetIcon(this, result: &v12);
  p = this->m__ImageList_GetIcon.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v14 = (HICON__ *)((int (__stdcall *)(struct _IMAGELIST *, int, unsigned int, int))p)(
                     a1: himl,
                     a2: i,
                     a3: flags,
                     a4: v11);
  v15 = -2;
  v9 = v14 == nullptr;
  if ( v14 != nullptr )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v9 )
    SetLastError(dwErrCode: LastError);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x103A3CB8
// Name: public: struct CComCtlWrapper::ImageList_AddMasked_Type CComCtlWrapper::GetProcAddress_ImageList_AddMasked(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_AddMasked_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_AddMasked(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_AddMasked_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__ImageList_AddMasked.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__ImageList_AddMasked.p = (int (__stdcall *)(struct _IMAGELIST *, HBITMAP__ *, unsigned int))GetProcAddress(hModule: ModuleHandleA, lpProcName: "ImageList_AddMasked");
  }
  result->p = (int (__stdcall *)(struct _IMAGELIST *, HBITMAP__ *, unsigned int))this->m__ImageList_AddMasked;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A3CE7
// Name: public: int CComCtlWrapper::_ImageList_AddMasked(struct _IMAGELIST __near *,struct HBITMAP__ __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_AddMasked(
        CComCtlWrapper *this,
        struct _IMAGELIST *himl,
        HBITMAP__ *hbmImage,
        unsigned int crMask)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v6; // eax
  int (__stdcall *p)(struct _IMAGELIST *, HBITMAP__ *, unsigned int); // esi
  BOOL v9; // esi
  DWORD LastError; // edi
  int v11; // [esp+0h] [ebp-34h]
  CComCtlWrapper::ImageList_AddMasked_Type v12; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  int v14; // [esp+18h] [ebp-1Ch]
  int v15; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v6 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v14 = -1;
  if ( !v6 )
    return -1;
  v15 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_AddMasked(this, result: &v12);
  p = this->m__ImageList_AddMasked.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v14 = ((int (__stdcall *)(struct _IMAGELIST *, HBITMAP__ *, unsigned int, int))p)(
          a1: himl,
          a2: hbmImage,
          a3: crMask,
          a4: v11);
  v15 = -2;
  v9 = v14 == -1;
  if ( v14 == -1 )
    LastError = GetLastError();
  else
    LastError = 0;
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v9 )
    SetLastError(dwErrCode: LastError);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x1033BB53
// Name: public: CInternalGlobalLock::~CInternalGlobalLock(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CInternalGlobalLock::~CInternalGlobalLock(CInternalGlobalLock *this)
{
  CInternalGlobalLock::Unlock(this);
}

//------------------------------------------------------------------------------
// Address: 0x10343380
// Name: public: CCommDlgWrapper::CCommDlgWrapper(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCommDlgWrapper *__thiscall CCommDlgWrapper::CCommDlgWrapper(CCommDlgWrapper *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strModuleName; // [esp+10h] [ebp-10h] BYREF
  int v4; // [esp+1Ch] [ebp-4h]

  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &strModuleName,
    pszSrc: "comdlg32.dll");
  v4 = 0;
  CDllIsolationWrapperBase::CDllIsolationWrapperBase(this, &strModuleName);
  ATL::CStringData::Release(this: (ATL::CStringData *)strModuleName.m_pszData - 1);
  this->__vftable = (CCommDlgWrapper_vtbl *)&CCommDlgWrapper::`vftable';
  this->m__GetOpenFileNameA.p = nullptr;
  this->m__GetOpenFileNameW.p = nullptr;
  this->m__GetSaveFileNameA.p = nullptr;
  this->m__GetSaveFileNameW.p = nullptr;
  this->m__GetFileTitleA.p = nullptr;
  this->m__GetFileTitleW.p = nullptr;
  this->m__ChooseColorA.p = nullptr;
  this->m__ChooseColorW.p = nullptr;
  this->m__FindTextA.p = nullptr;
  this->m__FindTextW.p = nullptr;
  this->m__ReplaceTextA.p = nullptr;
  this->m__ReplaceTextW.p = nullptr;
  this->m__ChooseFontA.p = nullptr;
  this->m__ChooseFontW.p = nullptr;
  this->m__PrintDlgA.p = nullptr;
  this->m__PrintDlgW.p = nullptr;
  this->m__CommDlgExtendedError.p = nullptr;
  this->m__PageSetupDlgA.p = nullptr;
  this->m__PageSetupDlgW.p = nullptr;
  this->m__PrintDlgExA.p = nullptr;
  this->m__PrintDlgExW.p = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10343403
// Name: public: CShellWrapper::CShellWrapper(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CShellWrapper *__thiscall CShellWrapper::CShellWrapper(CShellWrapper *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strModuleName; // [esp+10h] [ebp-10h] BYREF
  int v4; // [esp+1Ch] [ebp-4h]

  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &strModuleName,
    pszSrc: "shell32.dll");
  v4 = 0;
  CDllIsolationWrapperBase::CDllIsolationWrapperBase(this, &strModuleName);
  ATL::CStringData::Release(this: (ATL::CStringData *)strModuleName.m_pszData - 1);
  this->__vftable = (CShellWrapper_vtbl *)&CShellWrapper::`vftable';
  this->m__InitNetworkAddressControl.p = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034346A
// Name: public: AFX_MODULE_STATE::AFX_MODULE_STATE(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_MODULE_STATE *__thiscall AFX_MODULE_STATE::AFX_MODULE_STATE(AFX_MODULE_STATE *this, unsigned __int8 bDLL)
{
  CAfxStringMgr *StringManager; // eax
  CComCtlWrapper *v4; // ecx
  CComCtlWrapper *v5; // eax
  CCommDlgWrapper *v6; // ecx
  CCommDlgWrapper *v7; // eax
  CShellWrapper *v8; // ecx
  CShellWrapper *v9; // eax

  this->__vftable = (AFX_MODULE_STATE_vtbl *)&AFX_MODULE_STATE::`vftable';
  this->m_classList.m_pHead = nullptr;
  this->m_classList.m_nNextOffset = 0;
  this->m_factoryList.m_pHead = nullptr;
  this->m_factoryList.m_nNextOffset = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strUnregisterList, pStringMgr: StringManager);
  this->m_lockList.m_pHead = nullptr;
  this->m_lockList.m_nNextOffset = 0;
  this->m_typeLibCache.m_lcid = -1;
  this->m_typeLibCache.m_ptlib = nullptr;
  this->m_typeLibCache.m_ptinfo = nullptr;
  this->m_typeLibCache.m_cRef = 0;
  this->m_factoryList.m_nNextOffset = 32;
  this->m_classList.m_nNextOffset = 20;
  this->m_fRegisteredClasses = 0;
  this->m_bDLL = bDLL;
  ATL::CSimpleStringT<char,0>::PrepareWrite(this: &this->m_strUnregisterList, nLength: 4096);
  this->m_bUserCtrl = 1;
  this->m_lockList.m_nNextOffset = 24;
  this->m_pDllIsolationWrappers = (CDllIsolationWrapperBase **)operator new(nSize: 0xCu);
  v4 = (CComCtlWrapper *)CNoTrackObject::operator new(nSize: 0x188u);
  if ( v4 != nullptr )
    v5 = CComCtlWrapper::CComCtlWrapper(this: v4);
  else
    v5 = nullptr;
  *this->m_pDllIsolationWrappers = v5;
  v6 = (CCommDlgWrapper *)CNoTrackObject::operator new(nSize: 0x64u);
  if ( v6 != nullptr )
    v7 = CCommDlgWrapper::CCommDlgWrapper(this: v6);
  else
    v7 = nullptr;
  *((_DWORD *)this->m_pDllIsolationWrappers + 1) = v7;
  v8 = (CShellWrapper *)CNoTrackObject::operator new(nSize: 0x14u);
  if ( v8 != nullptr )
    v9 = CShellWrapper::CShellWrapper(this: v8);
  else
    v9 = nullptr;
  *((_DWORD *)this->m_pDllIsolationWrappers + 2) = v9;
  this->m_bSetAmbientActCtx = 1;
  this->m_hActCtx = nullptr;
  this->m_bInitNetworkAddressControl = 0;
  this->m_bInitNetworkAddressControlCalled = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103435CA
// Name: public: static class CNoTrackObject __near * CProcessLocal<class _AFX_BASE_MODULE_STATE>::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_MODULE_STATE *__stdcall CProcessLocal<_AFX_BASE_MODULE_STATE>::CreateObject()
{
  AFX_MODULE_STATE *v0; // esi
  AFX_MODULE_STATE *result; // eax

  v0 = (AFX_MODULE_STATE *)CNoTrackObject::operator new(nSize: 0x8Cu);
  result = nullptr;
  if ( v0 != nullptr )
  {
    AFX_MODULE_STATE::AFX_MODULE_STATE(this: v0, bDLL: 1u);
    v0->__vftable = (AFX_MODULE_STATE_vtbl *)&_AFX_BASE_MODULE_STATE::`vftable';
    return v0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10343605
// Name: class AFX_MODULE_STATE __near * AfxGetModuleState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_MODULE_STATE *__stdcall AfxGetModuleState()
{
  CNoTrackObject *Data; // eax
  AFX_MODULE_STATE *result; // eax

  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  if ( Data == nullptr
    || (result = (AFX_MODULE_STATE *)Data[1].__vftable) == nullptr
    && (result = (AFX_MODULE_STATE *)CProcessLocalObject::GetData(
                                       this: &_afxBaseModuleState,
                                       pfnCreateObject: (CNoTrackObject *(__stdcall *)())CProcessLocal<_AFX_BASE_MODULE_STATE>::CreateObject)) == nullptr )
  {
    AfxThrowInvalidArgException();
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10343638
// Name: class AFX_MODULE_THREAD_STATE __near * AfxGetModuleThreadState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_MODULE_THREAD_STATE *__stdcall AfxGetModuleThreadState()
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_THREAD_STATE *result; // eax

  ModuleState = AfxGetModuleState();
  result = CThreadLocal<AFX_MODULE_THREAD_STATE>::GetData(this: &ModuleState->m_thread);
  if ( result == nullptr )
    AfxThrowInvalidArgException();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034364F
// Name: public: AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(class AFX_MODULE_STATE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_MAINTAIN_STATE2 *__thiscall AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(
        AFX_MAINTAIN_STATE2 *this,
        AFX_MODULE_STATE *pNewState)
{
  void *m_hActCtx; // eax

  this->m_bValidActCtxCookie = AfxGetModuleState()->m_bSetAmbientActCtx != 0
                            && (m_hActCtx = pNewState->m_hActCtx) != (void *)-1
                            && ActivateActCtx(hActCtx: m_hActCtx, lpCookie: &this->m_ulActCtxCookie);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034AFFB
// Name: struct _IMAGELIST __near * AfxImageList_Create(int,int,unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct _IMAGELIST *__stdcall AfxImageList_Create(int cx, int cy, unsigned int flags, int cInitial, int cGrow)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  return CComCtlWrapper::_ImageList_Create(
           this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
           cx,
           cy,
           flags,
           cInitial,
           cGrow);
}

//------------------------------------------------------------------------------
// Address: 0x1034B022
// Name: class CHandleMap __near * afxMapHIMAGELIST(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHandleMap *__stdcall afxMapHIMAGELIST(int bCreate)
{
  AFX_MODULE_THREAD_STATE *ModuleThreadState; // esi
  int (__cdecl *v2)(unsigned int); // ebx
  CHandleMap *v3; // ecx
  CHandleMap *v4; // eax

  ModuleThreadState = AfxGetModuleThreadState();
  if ( ModuleThreadState->m_pmapHIMAGELIST == nullptr && bCreate != 0 )
  {
    v2 = AfxSetNewHandler(pfnNewHandler: (int (__cdecl *)(unsigned int))AfxCriticalNewHandler);
    v3 = (CHandleMap *)operator new(nSize: 0x60u);
    if ( v3 != nullptr )
      v4 = CHandleMap::CHandleMap(
             this: v3,
             pClass: &CImageList::classCImageList,
             pfnConstructObject: ConstructDestruct<CImageList>::Construct,
             pfnDestructObject: ConstructDestruct<CGdiObject>::Destruct,
             nOffset: 4u,
             nHandles: 1);
    else
      v4 = nullptr;
    ModuleThreadState->m_pmapHIMAGELIST = v4;
    AfxSetNewHandler(pfnNewHandler: v2);
  }
  return ModuleThreadState->m_pmapHIMAGELIST;
}

//------------------------------------------------------------------------------
// Address: 0x1038A54E
// Name: public: class CMDIChildWndEx __near * CMDIClientAreaWnd::FindNextRegisteredWithTaskbarMDIChild(class CMFCTabCtrl __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMDIChildWndEx *__thiscall CMDIClientAreaWnd::FindNextRegisteredWithTaskbarMDIChild(
        CMDIClientAreaWnd *this,
        CMFCTabCtrl *pTabCtrl,
        int iStartFrom)
{
  int v4; // edi
  int v5; // ebx
  CWnd *v6; // eax
  CMDIChildWndEx *v7; // eax
  CMDIChildWndEx *v8; // edi

  if ( pTabCtrl == nullptr )
    return nullptr;
  v4 = iStartFrom;
  if ( iStartFrom < 0 )
    v4 = 0;
  v5 = v4;
  if ( v4 >= pTabCtrl->GetTabsNum(this: pTabCtrl) )
    return nullptr;
  while ( 1 )
  {
    v6 = pTabCtrl->GetTabWnd(this: pTabCtrl, a2: v5);
    v7 = (CMDIChildWndEx *)AfxDynamicDownCast(pClass: &CMDIChildWndEx::classCMDIChildWndEx, pObject: v6);
    v8 = v7;
    if ( v7 != nullptr && v7->m_hWnd != nullptr && CMDIChildWndEx::IsRegisteredWithTaskbarTabs(this: v7) != 0 )
      break;
    if ( ++v5 >= pTabCtrl->GetTabsNum(this: pTabCtrl) )
      return nullptr;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1038A5C5
// Name: public: void CMDIClientAreaWnd::SetActiveTab(struct HWND__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIClientAreaWnd::SetActiveTab(CMDIClientAreaWnd *this, HWND__ *hwnd)
{
  CWnd *v3; // eax
  CObject *v4; // eax
  CMFCBaseTabCtrl *v5; // esi
  CFrameWnd *TopLevelFrame; // eax
  CMFCTabCtrl *ActiveTabWnd; // eax
  CMFCBaseTabCtrl *v8; // edi
  CMFCTabCtrl_vtbl *v9; // eax
  int v10; // eax
  CMFCBaseTabCtrl_vtbl *v11; // eax
  int v12; // eax
  int v13; // eax
  HWND m_hWnd; // [esp-Ch] [ebp-30h]
  CMDIChildWndEx *pMDIChild; // [esp+8h] [ebp-1Ch]
  int iTab; // [esp+Ch] [ebp-18h]
  CRect rectTabWnd; // [esp+10h] [ebp-14h] BYREF

  if ( this->m_bDisableUpdateTabs == 0 )
  {
    if ( this->m_bIsMDITabbedGroup != 0 )
    {
      v3 = CWnd::FromHandle(hWnd: hwnd);
      v4 = AfxDynamicDownCast(pClass: &CMDIChildWndEx::classCMDIChildWndEx, pObject: v3);
      pMDIChild = (CMDIChildWndEx *)v4;
      if ( v4 != nullptr )
      {
        v5 = (CMFCBaseTabCtrl *)v4[70].__vftable;
        if ( v5 != nullptr )
        {
          iTab = v5->GetTabFromHwnd(this: v5, a2: hwnd);
          if ( iTab >= 0 )
          {
            m_hWnd = v5->m_hWnd;
            memset(&rectTabWnd, 0, sizeof(rectTabWnd));
            GetClientRect(hWnd: m_hWnd, lpRect: &rectTabWnd);
            if ( IsRectEmpty(lprc: &rectTabWnd) )
            {
              TopLevelFrame = CWnd::GetTopLevelFrame(this: pMDIChild);
              if ( TopLevelFrame != nullptr )
                TopLevelFrame->RecalcLayout(this: TopLevelFrame, a2: 1);
            }
            ActiveTabWnd = CMDIClientAreaWnd::FindActiveTabWnd(this);
            v8 = ActiveTabWnd;
            if ( ActiveTabWnd != nullptr )
            {
              v9 = ActiveTabWnd->__vftable;
              HIDWORD(v8[1].m_ulGestureArg) = 0;
              v10 = v9->GetActiveTab(this: (struct CMFCTabCtrl *)v8);
              CMFCBaseTabCtrl::InvalidateTab(this: v8, iTab: v10);
            }
            v11 = v5->__vftable;
            HIDWORD(v5[1].m_ulGestureArg) = 1;
            v11->SetActiveTab(this: v5, a2: iTab);
            v12 = v5->GetActiveTab(this: v5);
            CMFCBaseTabCtrl::InvalidateTab(this: v5, iTab: v12);
          }
        }
      }
    }
    else if ( this->m_bTabIsVisible != 0 )
    {
      v13 = this->m_wndTab.GetTabFromHwnd(this: &this->m_wndTab, a2: hwnd);
      if ( v13 >= 0 )
        this->m_wndTab.SetActiveTab(this: &this->m_wndTab, a2: v13);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038A7DE
// Name: private: int CMDIClientAreaWnd::IsKeepClientEdge(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMDIClientAreaWnd::IsKeepClientEdge(CMDIClientAreaWnd *this)
{
  BOOL v1; // esi
  HWND__ *v3; // eax
  CWnd *v4; // eax
  CWnd *v5; // ebx
  BOOL result; // eax

  v1 = false;
  v3 = (HWND__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x229u, wParam: 0, lParam: 0);
  if ( v3 != nullptr )
  {
    v4 = CWnd::FromHandle(hWnd: v3);
    v5 = v4;
    if ( v4 != nullptr && IsWindow(hWnd: v4->m_hWnd) )
      v1 = (CWnd::GetStyle(this: v5) & 0x80000) != 0;
  }
  result = false;
  if ( this->m_bIsMDITabbedGroup == 0 )
    return v1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1038A836
// Name: protected: long CMDIClientAreaWnd::OnGetDragBounds(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIClientAreaWnd::OnGetDragBounds(CMDIClientAreaWnd *this, CMFCTabCtrl *wp, tagRECT *lp)
{
  bool v4; // zf
  int m_nResizeMargin; // esi
  HWND m_hWnd; // [esp-8h] [ebp-40h]
  CMFCTabCtrl *pNextTabWnd; // [esp+Ch] [ebp-2Ch]
  CRect rectNextTabWnd; // [esp+14h] [ebp-24h] BYREF
  CRect rectTabWndToResize; // [esp+24h] [ebp-14h] BYREF

  if ( this->m_bIsMDITabbedGroup == 0 )
    return 0;
  if ( this->m_lstTabbedGroups.m_nCount == 0 )
    return 0;
  if ( wp == nullptr )
    return 0;
  pNextTabWnd = CMDIClientAreaWnd::GetNextTabWnd(this, pOrgTabWnd: wp, bWithoutAsserts: 0);
  if ( pNextTabWnd == nullptr )
    return 0;
  m_hWnd = wp->m_hWnd;
  memset(&rectTabWndToResize, 0, sizeof(rectTabWndToResize));
  memset(&rectNextTabWnd, 0, sizeof(rectNextTabWnd));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectTabWndToResize);
  GetWindowRect(hWnd: pNextTabWnd->m_hWnd, lpRect: &rectNextTabWnd);
  UnionRect(lprcDst: &rectTabWndToResize, lprcSrc1: &rectTabWndToResize, lprcSrc2: &rectNextTabWnd);
  v4 = this->m_groupAlignment == GROUP_VERT_ALIGN;
  m_nResizeMargin = this->m_nResizeMargin;
  if ( v4 )
  {
    rectTabWndToResize.left += m_nResizeMargin;
    rectTabWndToResize.right -= m_nResizeMargin;
  }
  else
  {
    rectTabWndToResize.top += m_nResizeMargin;
    rectTabWndToResize.bottom -= m_nResizeMargin;
  }
  CopyRect(lprcDst: lp, lprcSrc: &rectTabWndToResize);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1038A906
// Name: protected: long CMDIClientAreaWnd::OnDragComplete(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIClientAreaWnd::OnDragComplete(CMDIClientAreaWnd *this, CMFCTabCtrl *wp, tagPOINT *lp)
{
  CMFCTabCtrl *pNextTabWnd; // [esp+10h] [ebp-18h]
  CRect rectNextWnd; // [esp+14h] [ebp-14h] BYREF

  if ( this->m_bIsMDITabbedGroup == 0 )
    return 0;
  if ( this->m_lstTabbedGroups.m_nCount == 0 )
    return 0;
  pNextTabWnd = CMDIClientAreaWnd::GetNextTabWnd(this, pOrgTabWnd: wp, bWithoutAsserts: 0);
  if ( pNextTabWnd == nullptr )
    return 0;
  CWnd::ScreenToClient(this, lpRect: lp);
  CWnd::SetWindowPos(
    this: wp,
    pWndInsertAfter: nullptr,
    x: -1,
    y: -1,
    cx: lp[1].x - lp->x,
    cy: lp[1].y - lp->y,
    nFlags: 0x16u);
  memset(&rectNextWnd, 0, sizeof(rectNextWnd));
  GetWindowRect(hWnd: pNextTabWnd->m_hWnd, lpRect: &rectNextWnd);
  CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rectNextWnd);
  if ( this->m_groupAlignment == GROUP_VERT_ALIGN )
    rectNextWnd.left = lp[1].x;
  else
    rectNextWnd.top = lp[1].y;
  CWnd::SetWindowPos(
    this: pNextTabWnd,
    pWndInsertAfter: nullptr,
    x: rectNextWnd.left,
    y: rectNextWnd.top,
    cx: rectNextWnd.right - rectNextWnd.left,
    cy: rectNextWnd.bottom - rectNextWnd.top,
    nFlags: 0x14u);
  CMDIClientAreaWnd::AdjustMDIChildren(this, pTabWnd: wp);
  CMDIClientAreaWnd::AdjustMDIChildren(this, pTabWnd: pNextTabWnd);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1038A9FF
// Name: private: class CMFCTabCtrl __near * CMDIClientAreaWnd::CreateNewTabGroup(class CMFCTabCtrl __near *,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTabCtrl *__thiscall CMDIClientAreaWnd::CreateNewTabGroup(
        CMDIClientAreaWnd *this,
        CMFCTabCtrl *pTabWndAfter,
        CRect rectGroup,
        int bVertical)
{
  int right; // ecx
  int bottom; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-34h]
  __POSITION *pos; // [esp+Ch] [ebp-20h]
  CMDIClientAreaWnd::GROUP_ALIGNMENT resizeMode; // [esp+10h] [ebp-1Ch]
  CMFCTabCtrl *pNewTabWnd; // [esp+14h] [ebp-18h]
  CRect rectWndAfter; // [esp+18h] [ebp-14h] BYREF

  pos = (__POSITION *)CPtrList::Find(this: &this->m_lstTabbedGroups, searchValue: pTabWndAfter, startAfter: nullptr);
  if ( pos == nullptr )
    return nullptr;
  pNewTabWnd = this->CreateTabGroup(this, a2: 0);
  resizeMode = (bVertical == 0) + 1;
  CMFCTabCtrl::SetResizeMode(this: pTabWndAfter, (CMFCTabCtrl::ResizeMode)resizeMode);
  CObList::InsertAfter(this: &this->m_lstTabbedGroups, position: pos, newElement: pNewTabWnd);
  if ( pNewTabWnd != this->m_lstTabbedGroups.m_pNodeTail->data )
    CMFCTabCtrl::SetResizeMode(this: pNewTabWnd, (CMFCTabCtrl::ResizeMode)resizeMode);
  this->m_groupAlignment = resizeMode;
  m_hWnd = pTabWndAfter->m_hWnd;
  memset(&rectWndAfter, 0, sizeof(rectWndAfter));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectWndAfter);
  CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rectGroup);
  CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rectWndAfter);
  if ( bVertical != 0 )
  {
    right = rectGroup.left - rectGroup.right + rectWndAfter.right;
    bottom = rectWndAfter.bottom;
    rectWndAfter.right = right;
    rectGroup.top = rectWndAfter.top;
    rectGroup.bottom = rectWndAfter.bottom;
  }
  else
  {
    bottom = rectGroup.top - rectGroup.bottom + rectWndAfter.bottom;
    rectGroup.left = rectWndAfter.left;
    right = rectWndAfter.right;
    rectWndAfter.bottom = bottom;
    rectGroup.right = rectWndAfter.right;
  }
  CWnd::SetWindowPos(
    this: pTabWndAfter,
    pWndInsertAfter: nullptr,
    x: -1,
    y: -1,
    cx: right - rectWndAfter.left,
    cy: bottom - rectWndAfter.top,
    nFlags: 0x16u);
  CWnd::SetWindowPos(
    this: pNewTabWnd,
    pWndInsertAfter: nullptr,
    x: rectGroup.left,
    y: rectGroup.top,
    cx: rectGroup.right - rectGroup.left,
    cy: rectGroup.bottom - rectGroup.top,
    nFlags: 0x14u);
  CMDIClientAreaWnd::AdjustMDIChildren(this, pTabWnd: pTabWndAfter);
  return pNewTabWnd;
}

//------------------------------------------------------------------------------
// Address: 0x1038AB42
// Name: public: class CMFCTabCtrl __near * CMDIClientAreaWnd::FindActiveTabWndByActiveChild(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTabCtrl *__thiscall CMDIClientAreaWnd::FindActiveTabWndByActiveChild(CMDIClientAreaWnd *this)
{
  HWND__ *v2; // eax
  int iIndex; // [esp+4h] [ebp-4h] BYREF

  v2 = (HWND__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x229u, wParam: 0, lParam: 0);
  iIndex = -1;
  return CMDIClientAreaWnd::FindTabWndByChild(this, hWndChild: v2, &iIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1038AB70
// Name: private: class CMFCTabCtrl __near * CMDIClientAreaWnd::TabWndFromPoint(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTabCtrl *__thiscall CMDIClientAreaWnd::TabWndFromPoint(CMDIClientAreaWnd *this, CPoint ptScreen)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *v3; // eax
  CObject *v4; // edi
  CObject *data; // [esp-4h] [ebp-20h]
  CRect rectWnd; // [esp+8h] [ebp-14h] BYREF

  m_pNodeHead = this->m_lstTabbedGroups.m_pNodeHead;
  do
  {
    if ( m_pNodeHead == nullptr )
      return nullptr;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v3 = AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: data);
    memset(&rectWnd, 0, sizeof(rectWnd));
    v4 = v3;
    GetWindowRect(hWnd: (HWND)v3[8].__vftable, lpRect: &rectWnd);
  }
  while ( !PtInRect(lprc: &rectWnd, pt: ptScreen.tagPOINT) );
  return (CMFCTabCtrl *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1038ABF5
// Name: private: void CMDIClientAreaWnd::DrawNewGroupRect(struct tagRECT const __near *,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIClientAreaWnd::DrawNewGroupRect(
        CMDIClientAreaWnd *this,
        const tagRECT *lpRectNew,
        tagRECT *lpRectOld)
{
  HWND DesktopWindow; // eax
  CWnd *v4; // eax
  tagSIZE v5; // [esp-1Ch] [ebp-8Ch]
  tagSIZE v6; // [esp-10h] [ebp-80h]
  CWindowDC v7; // [esp+10h] [ebp-60h] BYREF
  int v8; // [esp+28h] [ebp-48h]
  RECT *v9; // [esp+2Ch] [ebp-44h]
  tagRECT rcDst; // [esp+30h] [ebp-40h] BYREF
  tagRECT rc; // [esp+40h] [ebp-30h] BYREF
  tagRECT RectLast; // [esp+50h] [ebp-20h] BYREF
  int v13; // [esp+6Ch] [ebp-4h]

  v9 = lpRectOld;
  DesktopWindow = GetDesktopWindow();
  v4 = CWnd::FromHandle(hWnd: DesktopWindow);
  CWindowDC::CWindowDC(this: &v7, pWnd: v4);
  v13 = 0;
  v8 = 4;
  memset(&rc, 0, sizeof(rc));
  SetRectEmpty(lprc: &rc);
  memset(&RectLast, 0, sizeof(RectLast));
  SetRectEmpty(lprc: &RectLast);
  if ( lpRectNew != nullptr )
  {
    CopyRect(lprcDst: &rcDst, lprcSrc: lpRectNew);
    rc = rcDst;
  }
  if ( v9 != nullptr )
  {
    CopyRect(lprcDst: &rcDst, lprcSrc: v9);
    RectLast = rcDst;
  }
  v6.cy = v8;
  v6.cx = 4;
  v5.cy = v8;
  v5.cx = 4;
  CDC::DrawDragRect(
    this: &v7,
    lpRect: &rc,
    size: v5,
    lpRectLast: &RectLast,
    sizeLast: v6,
    pBrush: nullptr,
    pBrushLast: nullptr);
  v13 = -1;
  CWindowDC::~CWindowDC(this: &v7);
}

//------------------------------------------------------------------------------
// Address: 0x1038ACBB
// Name: public: void CMDIClientAreaWnd::CloseAllWindows(class CMFCTabCtrl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIClientAreaWnd::CloseAllWindows(CMDIClientAreaWnd *this, CMFCTabCtrl *pTabWnd)
{
  int i; // ebx
  CWnd *v4; // eax
  CObject *v5; // eax
  HWND Window; // eax
  CWnd *j; // eax
  CObject *v8; // eax
  HWND v9; // eax
  CWnd *v10; // esi
  CObList::CNode *m_pNodeHead; // esi
  CObject *v12; // eax
  CObject *data; // [esp-4h] [ebp-3Ch]
  CObList lstWindows; // [esp+10h] [ebp-28h] BYREF
  int v15; // [esp+34h] [ebp-4h]

  if ( pTabWnd != nullptr )
  {
    for ( i = pTabWnd->GetTabsNum(this: pTabWnd) - 1; i >= 0; --i )
    {
      v4 = pTabWnd->GetTabWnd(this: pTabWnd, a2: i);
      v5 = AfxDynamicDownCast(pClass: &CMDIChildWndEx::classCMDIChildWndEx, pObject: v4);
      if ( v5 != nullptr )
        SendMessageA(hWnd: (HWND)v5[8].__vftable, Msg: 0x10u, wParam: 0, lParam: 0);
    }
  }
  else
  {
    CObList::CObList(this: &lstWindows, nBlockSize: 10);
    v15 = 0;
    Window = GetWindow(hWnd: this->m_hWnd, uCmd: 5u);
    for ( j = CWnd::FromHandle(hWnd: Window); ; j = CWnd::FromHandle(hWnd: v9) )
    {
      v10 = j;
      if ( j == nullptr )
        break;
      v8 = AfxDynamicDownCast(pClass: &CMDIChildWndEx::classCMDIChildWndEx, pObject: j);
      if ( v8 != nullptr )
        CPtrList::AddTail(this: &lstWindows, newElement: v8);
      v9 = GetWindow(hWnd: v10->m_hWnd, uCmd: 2u);
    }
    m_pNodeHead = lstWindows.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      v12 = AfxDynamicDownCast(pClass: &CMDIChildWndEx::classCMDIChildWndEx, pObject: data);
      SendMessageA(hWnd: (HWND)v12[8].__vftable, Msg: 0x10u, wParam: 0, lParam: 0);
    }
    v15 = -1;
    CObList::~CObList(this: &lstWindows);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038ADAE
// Name: protected: long CMDIClientAreaWnd::OnMDINext(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIClientAreaWnd::OnMDINext(CMDIClientAreaWnd *this, unsigned int wp, __POSITION *lp)
{
  int m_bIsMDITabbedGroup; // eax
  CMFCTabCtrl *ActiveTabWnd; // edi
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  CObList::CNode *m_pNodeTail; // eax
  int v11; // edi
  CObject *v12; // eax
  HWND__ *v13; // eax
  int v14; // ecx
  BOOL bNext; // [esp+8h] [ebp-Ch]
  int m_nCount; // [esp+10h] [ebp-4h]
  __POSITION *posActive; // [esp+20h] [ebp+Ch]

  m_bIsMDITabbedGroup = this->m_bIsMDITabbedGroup;
  if ( m_bIsMDITabbedGroup == 0 && this->m_bTabIsEnabled == 0 )
    return CWnd::Default(this);
  bNext = lp == nullptr;
  if ( m_bIsMDITabbedGroup != 0 )
    ActiveTabWnd = CMDIClientAreaWnd::FindActiveTabWnd(this);
  else
    ActiveTabWnd = &this->m_wndTab;
  if ( this->m_bIsMDITabbedGroup != 0 )
    posActive = (__POSITION *)CPtrList::Find(
                                this: &this->m_lstTabbedGroups,
                                searchValue: ActiveTabWnd,
                                startAfter: nullptr);
  else
    posActive = nullptr;
  v7 = this->m_bIsMDITabbedGroup;
  if ( v7 != 0 )
    m_nCount = this->m_lstTabbedGroups.m_nCount;
  else
    m_nCount = 0;
  if ( v7 != 0 && posActive == nullptr )
    goto LABEL_15;
  v8 = ActiveTabWnd->GetActiveTab(this: ActiveTabWnd);
  if ( bNext )
    v9 = v8 + 1;
  else
    v9 = v8 - 1;
  if ( v9 < 0 )
  {
    if ( m_nCount > 0 )
    {
      if ( posActive == nullptr )
        goto LABEL_15;
      m_pNodeTail = *(CObList::CNode **)&posActive[4];
      posActive = (__POSITION *)m_pNodeTail;
      if ( m_pNodeTail == nullptr )
        m_pNodeTail = this->m_lstTabbedGroups.m_pNodeTail;
      ActiveTabWnd = (CMFCTabCtrl *)AfxDynamicDownCast(
                                      pClass: &CMFCTabCtrl::classCMFCTabCtrl,
                                      pObject: m_pNodeTail->data);
    }
    if ( ActiveTabWnd == nullptr )
      goto LABEL_15;
    v9 = ActiveTabWnd->GetTabsNum(this: ActiveTabWnd) - 1;
  }
  if ( v9 >= ActiveTabWnd->GetTabsNum(this: ActiveTabWnd) )
  {
    if ( m_nCount > 0 )
    {
      if ( posActive == nullptr )
        goto LABEL_15;
      v11 = *(_DWORD *)posActive;
      AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: *(CObject **)&posActive[8]);
      if ( v11 != 0 )
        v12 = AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: *(CObject **)(v11 + 8));
      else
        v12 = AfxDynamicDownCast(
                pClass: &CMFCTabCtrl::classCMFCTabCtrl,
                pObject: this->m_lstTabbedGroups.m_pNodeHead->data);
      ActiveTabWnd = (CMFCTabCtrl *)v12;
    }
    if ( ActiveTabWnd != nullptr )
    {
      v9 = 0;
      goto LABEL_36;
    }
LABEL_15:
    AfxThrowInvalidArgException();
  }
LABEL_36:
  v13 = (HWND__ *)ActiveTabWnd->GetTabWnd(this: ActiveTabWnd, a2: v9);
  if ( v13 != nullptr )
    v14 = *((_DWORD *)v13 + 8);
  else
    v14 = 0;
  if ( v14 != wp )
  {
    if ( v13 != nullptr )
      v13 = *((HWND__ **)v13 + 8);
    CMDIClientAreaWnd::SetActiveTab(this, hwnd: v13);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1038AF1D
// Name: public: virtual CList<class CMDIChildWndEx __near *,class CMDIChildWndEx __near *>::~CList<class CMDIChildWndEx __near *,class CMDIChildWndEx __near *>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<CMDIChildWndEx *,CMDIChildWndEx *>::~CList<CMDIChildWndEx *,CMDIChildWndEx *>(
        CList<CMDIChildWndEx *,CMDIChildWndEx *> *this)
{
  this->__vftable = (CList<CMDIChildWndEx *,CMDIChildWndEx *>_vtbl *)&CList<CMDIChildWndEx *,CMDIChildWndEx *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll((CList<HWND__ *,HWND__ * &> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103A3D94
// Name: int AfxImageList_AddMasked(struct _IMAGELIST __near *,struct HBITMAP__ __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxImageList_AddMasked(struct _IMAGELIST *himl, HBITMAP__ *hbmImage, unsigned int crMask)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  return CComCtlWrapper::_ImageList_AddMasked(
           this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
           himl,
           hbmImage,
           crMask);
}

//------------------------------------------------------------------------------
// Address: 0x103A3DB5
// Name: protected: void CMFCEditBrowseCtrl::SetInternalImage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::SetInternalImage(CMFCEditBrowseCtrl *this)
{
  CImageList *p_m_ImageBrowse; // ecx
  const char *v3; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  HANDLE ImageA; // ebx
  unsigned int v6; // eax
  CGdiObject *v7; // eax
  HBITMAP__ *m_hObject; // ecx
  AFX_MODULE_STATE *v9; // eax
  struct _IMAGELIST *m_hImageList; // [esp-Ch] [ebp-30h]
  HBITMAP__ *v11; // [esp-8h] [ebp-2Ch]
  int v12; // [esp-4h] [ebp-28h]
  tagBITMAP bmpObj; // [esp+Ch] [ebp-18h] BYREF

  p_m_ImageBrowse = &this->m_ImageBrowse;
  if ( p_m_ImageBrowse != nullptr && p_m_ImageBrowse->m_hImageList != nullptr )
    CImageList::DeleteImageList(this: p_m_ImageBrowse);
  v3 = (const char *)(AFX_GLOBAL_DATA::Is32BitIcons(this: &afxGlobalData) != 0 ? 17049 : 17032);
  ModuleState = AfxGetModuleState();
  ImageA = LoadImageA(hInst: ModuleState->m_hCurrentResourceHandle, name: v3, type: 0, cx: 0, cy: 0, fuLoad: 0x2000u);
  if ( ImageA != nullptr )
  {
    GetObjectA(h: ImageA, c: 24, pv: &bmpObj);
    switch ( bmpObj.bmBitsPixel )
    {
      case 8u:
        v12 = 9;
        break;
      case 0x10u:
        v12 = 17;
        break;
      case 0x18u:
        v12 = 25;
        break;
      default:
        v6 = bmpObj.bmBitsPixel == 32 ? 33 : 5;
LABEL_13:
        CImageList::Create(this: &this->m_ImageBrowse, cx: 16, cy: 16, nFlags: v6, nInitial: 0, nGrow: 0);
        v7 = CGdiObject::FromHandle(h: ImageA);
        if ( v7 != nullptr )
          m_hObject = (HBITMAP__ *)v7->m_hObject;
        else
          m_hObject = nullptr;
        v11 = m_hObject;
        m_hImageList = this->m_ImageBrowse.m_hImageList;
        v9 = AfxGetModuleState();
        CComCtlWrapper::_ImageList_AddMasked(
          this: *(CComCtlWrapper **)v9->m_pDllIsolationWrappers,
          himl: m_hImageList,
          hbmImage: v11,
          crMask: 0xFF00FFu);
        this->m_sizeImage.cx = 16;
        this->m_sizeImage.cy = 16;
        this->m_bDefaultImage = 1;
        return;
    }
    v6 = v12;
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A3EB8
// Name: public: virtual void CMFCEditBrowseCtrl::OnAfterUpdate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnAfterUpdate(CMFCEditBrowseCtrl *this)
{
  HWND__ *m_hWnd; // esi
  WPARAM DlgCtrlID; // ebx
  CWnd *Owner; // eax
  HWND__ *v5; // ebx
  CWnd *v6; // eax
  int wParam; // [esp+4h] [ebp-4h]

  if ( CWnd::GetOwner(this) != nullptr )
  {
    if ( this != nullptr )
      m_hWnd = this->m_hWnd;
    else
      m_hWnd = nullptr;
    DlgCtrlID = CWnd::GetDlgCtrlID(this);
    Owner = CWnd::GetOwner(this);
    PostMessageA(hWnd: Owner->m_hWnd, Msg: 0x300u, wParam: DlgCtrlID, lParam: (LPARAM)m_hWnd);
    if ( this != nullptr )
      v5 = this->m_hWnd;
    else
      v5 = nullptr;
    wParam = CWnd::GetDlgCtrlID(this);
    v6 = CWnd::GetOwner(this);
    PostMessageA(hWnd: v6->m_hWnd, Msg: 0x400u, wParam, lParam: (LPARAM)v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A3F28
// Name: public: CMFCEditBrowseCtrl::CMFCEditBrowseCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCEditBrowseCtrl *__thiscall CMFCEditBrowseCtrl::CMFCEditBrowseCtrl(CMFCEditBrowseCtrl *this)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v3; // eax
  CAfxStringMgr *v4; // eax

  CWnd::CWnd(this);
  this->__vftable = (CMFCEditBrowseCtrl_vtbl *)&CMFCEditBrowseCtrl::`vftable';
  this->m_rectBtn.left = 0;
  this->m_rectBtn.top = 0;
  this->m_rectBtn.right = 0;
  this->m_rectBtn.bottom = 0;
  this->m_sizeImage.cx = 0;
  this->m_sizeImage.cy = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strLabel, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strDefFileExt, pStringMgr: v3);
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strFileFilter, pStringMgr: v4);
  CImageList::CImageList(this: &this->m_ImageBrowse);
  SetRectEmpty(lprc: &this->m_rectBtn);
  this->m_sizeImage.cx = 0;
  this->m_bIsButtonPressed = 0;
  this->m_bIsButtonHighlighted = 0;
  this->m_bIsButtonCaptured = 0;
  this->m_Mode = BrowseMode_None;
  this->m_sizeImage.cy = 0;
  this->m_nBrowseButtonWidth = 20;
  this->m_bDefaultImage = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A3FF0
// Name: public: virtual CMFCEditBrowseCtrl::~CMFCEditBrowseCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::~CMFCEditBrowseCtrl(CMFCEditBrowseCtrl *this)
{
  this->__vftable = (CMFCEditBrowseCtrl_vtbl *)&CMFCEditBrowseCtrl::`vftable';
  CImageList::~CImageList(this: &this->m_ImageBrowse);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strFileFilter.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strDefFileExt.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strLabel.m_pszData - 1);
  CEdit::~CEdit(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A4054
// Name: public: virtual void CMFCEditBrowseCtrl::OnDrawBrowseButton(class CDC __near *,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnDrawBrowseButton(
        CMFCEditBrowseCtrl *this,
        CDC *pDC,
        CRect rect,
        int bIsButtonPressed,
        int bHighlight)
{
  int v5; // esi
  CMFCVisualManager *Instance; // eax
  int v7; // esi
  int v8; // edi
  CMFCVisualManager *v9; // eax
  CGdiObject *v10; // eax
  CFont *pFont; // [esp+Ch] [ebp-28h]
  unsigned int clrText; // [esp+10h] [ebp-24h] BYREF
  unsigned int clrTextOld; // [esp+14h] [ebp-20h]
  CMFCEditBrowseCtrl *v14; // [esp+18h] [ebp-1Ch]
  int nTextMode; // [esp+1Ch] [ebp-18h]
  CRect rectText; // [esp+20h] [ebp-14h] BYREF

  v5 = 0;
  v14 = this;
  if ( bIsButtonPressed != 0 )
  {
    v5 = 1;
  }
  else if ( bHighlight != 0 )
  {
    v5 = 2;
  }
  clrText = afxGlobalData.clrBtnText;
  Instance = CMFCVisualManager::GetInstance();
  if ( ((int (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, CMFCEditBrowseCtrl *, int, unsigned int *))Instance->OnDrawBrowseButton)(
         a1: Instance,
         a2: pDC,
         a3: rect.left,
         a4: rect.top,
         a5: rect.right,
         a6: rect.bottom,
         a7: v14,
         a8: v5,
         a9: &clrText) != 0 )
  {
    nTextMode = 0;
    clrTextOld = (unsigned int)&v14->m_ImageBrowse;
    if ( v14 == (CMFCEditBrowseCtrl *)-176 || v14->m_ImageBrowse.m_hImageList == nullptr )
    {
      if ( *((_DWORD *)v14->m_strLabel.m_pszData - 3) != 0 )
      {
        clrTextOld = pDC->SetTextColor(this: pDC, a2: clrText);
        nTextMode = CDC::SetBkMode(this: pDC, nBkMode: 1);
        v10 = pDC->SelectStockObject(this: pDC, a2: 17);
        rectText = rect;
        pFont = (CFont *)v10;
        InflateRect(lprc: &rectText, dx: -1, dy: -2);
        OffsetRect(lprc: &rectText, dx: 0, dy: -2);
        if ( bIsButtonPressed != 0 )
          OffsetRect(lprc: &rectText, dx: 1, dy: 1);
        pDC->DrawTextA(
          this: pDC,
          a2: v14->m_strLabel.m_pszData,
          a3: *((_DWORD *)v14->m_strLabel.m_pszData - 3),
          a4: &rectText,
          a5: 37u);
        pDC->SetTextColor(this: pDC, a2: clrTextOld);
        CDC::SetBkMode(this: pDC, nBkMode: nTextMode);
        pDC->SelectObject(this: pDC, a2: pFont);
      }
    }
    else
    {
      if ( v14->m_bDefaultImage != 0 )
      {
        if ( v14->m_Mode == BrowseMode_File )
        {
          nTextMode = 1;
        }
        else if ( v14->m_Mode == BrowseMode_Folder )
        {
          nTextMode = 0;
        }
      }
      v7 = (rect.right + rect.left) / 2 - v14->m_sizeImage.cx / 2;
      v8 = (rect.top + rect.bottom) / 2 - v14->m_sizeImage.cy / 2;
      if ( bIsButtonPressed != 0 )
      {
        v9 = CMFCVisualManager::GetInstance();
        if ( v9->IsOffsetPressedButton(this: v9) != 0 )
        {
          ++v7;
          ++v8;
        }
      }
      CImageList::Draw(
        this: (CImageList *)clrTextOld,
        (HDC__ *)pDC,
        nImage: nTextMode,
        pt: (tagPOINT)__PAIR64__(v8, v7),
        nStyle: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A4211
// Name: public: void CMFCEditBrowseCtrl::EnableFolderBrowseButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::EnableFolderBrowseButton(CMFCEditBrowseCtrl *this)
{
  if ( this == nullptr || this->m_hWnd == nullptr || afxShellManager == nullptr )
    AfxThrowInvalidArgException();
  this->m_Mode = BrowseMode_Folder;
  CMFCEditBrowseCtrl::SetInternalImage(this);
  this->OnChangeLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A4269
// Name: public: virtual int CMFCEditBrowseCtrl::OnIllegalFileName(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCEditBrowseCtrl::OnIllegalFileName(
        CMFCEditBrowseCtrl *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strFileName)
{
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  CAfxStringMgr *v5; // eax
  char *m_pszData; // esi
  char *v7; // edi
  char *v9; // [esp-8h] [ebp-2Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strMessage; // [esp+10h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strError; // [esp+14h] [ebp-10h] BYREF
  int v12; // [esp+20h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strError, pStringMgr: StringManager);
  v12 = 0;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: 0xF100u);
  if ( StringResourceHandle != nullptr )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &strError,
      hInstance: StringResourceHandle,
      nID: 0xF100u);
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strMessage, pStringMgr: v5);
  m_pszData = strError.m_pszData;
  v9 = strFileName->m_pszData;
  LOBYTE(v12) = 1;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &strMessage,
    pszFormat: "%s\r\n%s",
    v9,
    strError.m_pszData);
  v7 = strMessage.m_pszData;
  CWnd::MessageBoxA(this, lpszText: strMessage.m_pszData, lpszCaption: nullptr, nType: 0x30u);
  ATL::CStringData::Release(this: (ATL::CStringData *)v7 - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  return 0;
}
