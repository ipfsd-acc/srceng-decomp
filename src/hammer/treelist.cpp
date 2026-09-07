// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/treelist.cpp
// Functions: 132
// ============================================================

#include "hammer\treelist.h"

//------------------------------------------------------------------------------
// Address: 0x100B8560
// Name: protected: void CTreeList::OnEndLabelEdit(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnEndLabelEdit(CTreeList *this, tagNMHDR *pNMHDR, int *pResult)
{
  void *ItemData; // eax

  if ( pNMHDR[2].idFrom != 0 )
  {
    ItemData = (void *)CTreeCtrl::GetItemData(this, hItem: (struct _TREEITEM *)pNMHDR[1].idFrom);
    if ( ItemData != nullptr )
    {
      this->OnRenameItem(this, a2: ItemData, a3: (const char *)pNMHDR[2].idFrom);
      *pResult = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B85A0
// Name: private: int CTreeList::GetCheck(struct _TREEITEM __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTreeList::GetCheck(CTreeList *this, struct _TREEITEM *hItem)
{
  unsigned int v2; // eax

  v2 = CTreeCtrl::GetItemState(this, hItem, nStateMask: 0xF000u) & 0xF000;
  if ( v2 == 0x2000 )
    return 1;
  else
    return -(v2 != 4096);
}

//------------------------------------------------------------------------------
// Address: 0x100B8610
// Name: public: class CImageList __near * CTreeCtrl::SetImageList(class CImageList __near *,int)
// Source: json
//------------------------------------------------------------------------------
CImageList *__thiscall CTreeCtrl::SetImageList(CTreeCtrl *this, CImageList *pImageList, WPARAM nImageList)
{
  struct _IMAGELIST *m_hImageList; // eax
  struct _IMAGELIST *v4; // eax

  m_hImageList = (struct _IMAGELIST *)pImageList;
  if ( pImageList != nullptr )
    m_hImageList = pImageList->m_hImageList;
  v4 = (struct _IMAGELIST *)SendMessageA(
                              hWnd: this->m_hWnd,
                              Msg: 0x1109u,
                              wParam: nImageList,
                              lParam: (LPARAM)m_hImageList);
  return CImageList::FromHandle(h: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100B8640
// Name: public: int CTreeCtrl::EnsureVisible(struct _TREEITEM __near *)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CTreeCtrl::EnsureVisible(CTreeCtrl *this, struct _TREEITEM *hItem)
{
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x1114u, wParam: 0, lParam: (LPARAM)hItem);
}

//------------------------------------------------------------------------------
// Address: 0x100B8660
// Name: UnsetItemData_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnsetItemData_R(CTreeCtrl *pCtrl, struct _TREEITEM *hItem)
{
  struct _TREEITEM *i; // esi

  CTreeCtrl::SetItem(
    this: pCtrl,
    hItem,
    nMask: 4u,
    lpszItem: nullptr,
    nImage: 0,
    nSelectedImage: 0,
    nState: 0,
    nStateMask: 0,
    lParam: 0);
  for ( i = (struct _TREEITEM *)SendMessageA(hWnd: pCtrl->m_hWnd, Msg: 0x110Au, wParam: 4u, lParam: (LPARAM)hItem);
        i != nullptr;
        i = (struct _TREEITEM *)SendMessageA(hWnd: pCtrl->m_hWnd, Msg: 0x110Au, wParam: 1u, lParam: (LPARAM)i) )
  {
    UnsetItemData_R(pCtrl, hItem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B86D0
// Name: private: void CTreeList::ExpandRecursive(struct _TREEITEM __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::ExpandRecursive(CTreeList *this, struct _TREEITEM *hItem)
{
  struct _TREEITEM *i; // esi

  if ( hItem != nullptr )
  {
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x1102u, wParam: 2u, lParam: (LPARAM)hItem);
    if ( CTreeCtrl::ItemHasChildren(this, hItem) != 0 )
    {
      for ( i = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 4u, lParam: (LPARAM)hItem);
            i != nullptr;
            i = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 1u, lParam: (LPARAM)i) )
      {
        CTreeList::ExpandRecursive(this, hItem: i);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8740
// Name: public: void CTreeList::ExpandAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::ExpandAll(CTreeList *this)
{
  LRESULT (__stdcall *v1)(HWND, UINT, WPARAM, LPARAM); // esi
  struct _TREEITEM *i; // ebx
  struct _TREEITEM *j; // esi

  v1 = SendMessageA;
  for ( i = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 0, lParam: 0);
        i != nullptr;
        i = (struct _TREEITEM *)v1(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 1u, lParam: (LPARAM)i) )
  {
    v1(hWnd: this->m_hWnd, Msg: 0x1102u, wParam: 2u, lParam: (LPARAM)i);
    if ( CTreeCtrl::ItemHasChildren(this, hItem: i) != 0 )
    {
      for ( j = (struct _TREEITEM *)v1(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 4u, lParam: (LPARAM)i);
            j != nullptr;
            j = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 1u, lParam: (LPARAM)j) )
      {
        CTreeList::ExpandRecursive(this, hItem: j);
      }
      v1 = SendMessageA;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B87D0
// Name: private: struct _TREEITEM __near * CTreeList::FindHTreeItemRecursive(struct _TREEITEM __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
struct _TREEITEM *__thiscall CTreeList::FindHTreeItemRecursive(CTreeList *this, struct _TREEITEM *hItem, void *pItem)
{
  struct _TREEITEM *result; // eax
  struct _TREEITEM *v5; // esi

  if ( hItem == nullptr )
    return nullptr;
  if ( (void *)CTreeCtrl::GetItemData(this, hItem) == pItem )
    return hItem;
  if ( CTreeCtrl::ItemHasChildren(this, hItem) == 0 )
    return nullptr;
  v5 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 4u, lParam: (LPARAM)hItem);
  if ( v5 == nullptr )
    return nullptr;
  while ( 1 )
  {
    result = CTreeList::FindHTreeItemRecursive(this, hItem: v5, pItem);
    if ( result != nullptr )
      break;
    v5 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 1u, lParam: (LPARAM)v5);
    if ( v5 == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B8850
// Name: private: struct _TREEITEM __near * CTreeList::FindHTreeItem(void __near *)
// Source: json
//------------------------------------------------------------------------------
struct _TREEITEM *__thiscall CTreeList::FindHTreeItem(CTreeList *this, void *pItem)
{
  struct _TREEITEM *v3; // esi
  struct _TREEITEM *result; // eax

  v3 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 0, lParam: 0);
  if ( v3 == nullptr )
    return nullptr;
  while ( 1 )
  {
    result = CTreeList::FindHTreeItemRecursive(this, hItem: v3, pItem);
    if ( result != nullptr )
      break;
    v3 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 1u, lParam: (LPARAM)v3);
    if ( v3 == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B88A0
// Name: public: void __near * CTreeList::GetSelectedItem(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CTreeList::GetSelectedItem(CTreeList *this)
{
  struct _TREEITEM *v2; // eax

  v2 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 9u, lParam: 0);
  if ( v2 != nullptr )
    return CTreeCtrl::GetItemData(this, hItem: v2);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B88D0
// Name: protected: void CTreeList::OnLButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnLButtonDown(CTreeList *this, unsigned int nFlags, CPoint point)
{
  unsigned int uFlags; // [esp+4h] [ebp-4h] BYREF

  if ( CTreeCtrl::HitTest(this, pt: point, pFlags: &uFlags) == nullptr || (uFlags & 0x40) == 0 )
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B8910
// Name: protected: void CTreeList::OnLButtonDblClk(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnLButtonDblClk(CTreeList *this, unsigned int nFlags, CPoint point)
{
  unsigned int uFlags; // [esp+4h] [ebp-4h] BYREF

  if ( CTreeCtrl::HitTest(this, pt: point, pFlags: &uFlags) == nullptr || (uFlags & 2) == 0 )
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B8950
// Name: protected: void CTreeList::OnSelChange(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnSelChange(CTreeList *this, tagNMHDR *pNMHDR, tagNMHDR *pResult)
{
  HWND Parent; // eax
  CWnd *v5; // edi
  WPARAM DlgCtrlID; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  if ( v5 != nullptr )
  {
    DlgCtrlID = CWnd::GetDlgCtrlID(this);
    PostMessageA(hWnd: v5->m_hWnd, Msg: g_uSelChangeMsg, wParam: DlgCtrlID, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8990
// Name: protected: void CTreeList::OnKeyDown(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnKeyDown(CTreeList *this, tagNMHDR *pNMHDR, int *pResult)
{
  HWND Parent; // eax
  CWnd *v4; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  if ( v4 != nullptr )
    PostMessageA(
      hWnd: v4->m_hWnd,
      Msg: g_uKeyDownMsg,
      wParam: LOWORD(pNMHDR[1].hwndFrom),
      lParam: *(LPARAM *)((char *)&pNMHDR[1].hwndFrom + 2));
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B89E0
// Name: protected: void CTreeList::OnRButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnRButtonDown(CTreeList *this, unsigned int nFlags, CPoint point)
{
  HWND v3; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-4h]

  this->m_ptRButtonDown.x = point.x;
  m_hWnd = this->m_hWnd;
  this->m_bRButtonDown = true;
  this->m_ptRButtonDown.y = point.y;
  this->m_hDragItem = nullptr;
  v3 = SetCapture(hWnd: m_hWnd);
  CWnd::FromHandle(hWnd: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100B8A20
// Name: protected: void CTreeList::OnTimer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnTimer(CTreeList *this, unsigned int nIDEvent)
{
  LRESULT v3; // ebx
  LPARAM v4; // eax
  int v5; // ebx
  LPARAM v6; // eax
  LPARAM v7; // eax
  struct _TREEITEM *v8; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-28h]
  CRect rect; // [esp+4h] [ebp-18h] BYREF
  CPoint point; // [esp+14h] [ebp-8h] BYREF

  if ( nIDEvent == 1 )
  {
    point = 0;
    GetCursorPos(lpPoint: &point);
    m_hWnd = this->m_hWnd;
    memset(&rect, 0, sizeof(rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
    if ( !PtInRect(lprc: &rect, pt: point.tagPOINT) )
    {
      if ( point.y <= rect.bottom )
      {
        if ( point.y < rect.top )
        {
          v7 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 5u, lParam: 0);
          v8 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 7u, lParam: v7);
          if ( v8 != nullptr )
            CTreeCtrl::EnsureVisible(this, hItem: v8);
        }
      }
      else
      {
        v3 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1110u, wParam: 0, lParam: 0);
        v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 5u, lParam: 0);
        if ( v3 > 1 )
        {
          v5 = v3 - 1;
          do
          {
            v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 6u, lParam: v4);
            --v5;
          }
          while ( v5 != 0 );
        }
        v6 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 6u, lParam: v4);
        if ( v6 != 0 )
          SendMessageA(hWnd: this->m_hWnd, Msg: 0x1114u, wParam: 0, lParam: v6);
      }
    }
  }
  else
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8B30
// Name: public: void CTreeList::SelectItem(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::SelectItem(CTreeList *this, void *pItem)
{
  struct _TREEITEM *HTreeItem; // eax

  HTreeItem = CTreeList::FindHTreeItem(this, pItem);
  if ( HTreeItem != nullptr )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Bu, wParam: 9u, lParam: (LPARAM)HTreeItem);
}

//------------------------------------------------------------------------------
// Address: 0x100B8B60
// Name: public: void CTreeList::SetCheck(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::SetCheck(CTreeList *this, void *pItem, int nCheckState)
{
  struct _TREEITEM *HTreeItem; // eax
  unsigned int v5; // ecx

  HTreeItem = CTreeList::FindHTreeItem(this, pItem);
  if ( HTreeItem != nullptr )
  {
    v5 = 4096;
    if ( nCheckState == 1 )
    {
      v5 = 0x2000;
    }
    else if ( nCheckState != 0 )
    {
      v5 = 12288;
    }
    CTreeCtrl::SetItem(
      this,
      hItem: HTreeItem,
      nMask: 8u,
      lpszItem: nullptr,
      nImage: 0,
      nSelectedImage: 0,
      nState: v5,
      nStateMask: 0xF000u,
      lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8BB0
// Name: public: int CTreeList::GetCheck(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTreeList::GetCheck(CTreeList *this, void *pItem)
{
  struct _TREEITEM *HTreeItem; // eax
  unsigned int v4; // eax

  HTreeItem = CTreeList::FindHTreeItem(this, pItem);
  if ( HTreeItem == nullptr )
    return 0;
  v4 = CTreeCtrl::GetItemState(this, hItem: HTreeItem, nStateMask: 0xF000u) & 0xF000;
  if ( v4 == 0x2000 )
    return 1;
  else
    return -(v4 != 4096);
}

//------------------------------------------------------------------------------
// Address: 0x100B8C00
// Name: public: int CTreeList::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTreeList::GetItemCount(CTreeList *this)
{
  return this->m_Items.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100B8C10
// Name: public: void CTreeList::UpdateItem(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::UpdateItem(CTreeList *this, void *pItem, const char *pszText)
{
  struct _TREEITEM *HTreeItem; // eax

  HTreeItem = CTreeList::FindHTreeItem(this, pItem);
  if ( HTreeItem != nullptr )
    CTreeCtrl::SetItem(
      this,
      hItem: HTreeItem,
      nMask: 1u,
      lpszItem: pszText,
      nImage: 0,
      nSelectedImage: 0,
      nState: 0,
      nStateMask: 0,
      lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100B8C40
// Name: public: struct CComCtlWrapper::ImageList_SetOverlayImage_Type CComCtlWrapper::GetProcAddress_ImageList_SetOverlayImage(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_SetOverlayImage_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_SetOverlayImage(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_SetOverlayImage_Type *result)
{
  HINSTANCE__ *ModuleHandleA; // eax
  HINSTANCE__ *LibraryA; // eax

  if ( this->m__ImageList_SetOverlayImage.p == nullptr )
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
    this->m__ImageList_SetOverlayImage.p = (int (__stdcall *)(struct _IMAGELIST *, int, int))GetProcAddress(
                                                                                               hModule: this->m_hModule,
                                                                                               lpProcName: "ImageList_SetOverlayImage");
  }
  result->p = (int (__stdcall *)(struct _IMAGELIST *, int, int))this->m__ImageList_SetOverlayImage;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B8CA0
// Name: public: int CComCtlWrapper::_ImageList_SetOverlayImage(struct _IMAGELIST __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_SetOverlayImage(
        CComCtlWrapper *this,
        struct _IMAGELIST *himl,
        int iImage,
        int iOverlay)
{
  DWORD LastError; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v7; // eax
  int (__stdcall *p)(struct _IMAGELIST *, int, int); // esi
  int v10; // ebx
  int v11; // [esp+0h] [ebp-30h]
  CComCtlWrapper::ImageList_SetOverlayImage_Type v12; // [esp+Ch] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int v14; // [esp+14h] [ebp-1Ch]
  int v15; // [esp+2Ch] [ebp-4h]

  LastError = 0;
  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v7 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v14 = 0;
  if ( !v7 )
    return 0;
  v15 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_SetOverlayImage(this, result: &v12);
  p = this->m__ImageList_SetOverlayImage.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v10 = ((int (__stdcall *)(struct _IMAGELIST *, int, int, int))p)(a1: himl, a2: iImage, a3: iOverlay, a4: v11);
  v14 = v10;
  v15 = -1;
  if ( v10 == 0 )
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v10 == 0 )
    SetLastError(dwErrCode: LastError);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x100B8D90
// Name: public: struct CComCtlWrapper::ImageList_BeginDrag_Type CComCtlWrapper::GetProcAddress_ImageList_BeginDrag(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_BeginDrag_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_BeginDrag(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_BeginDrag_Type *result)
{
  HINSTANCE__ *ModuleHandleA; // eax
  HINSTANCE__ *LibraryA; // eax

  if ( this->m__ImageList_BeginDrag.p == nullptr )
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
    this->m__ImageList_BeginDrag.p = (int (__stdcall *)(struct _IMAGELIST *, int, int, int))GetProcAddress(
                                                                                              hModule: this->m_hModule,
                                                                                              lpProcName: "ImageList_BeginDrag");
  }
  result->p = (int (__stdcall *)(struct _IMAGELIST *, int, int, int))this->m__ImageList_BeginDrag;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B8DF0
// Name: public: int CComCtlWrapper::_ImageList_BeginDrag(struct _IMAGELIST __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_BeginDrag(
        CComCtlWrapper *this,
        struct _IMAGELIST *himlTrack,
        int iTrack,
        int dxHotspot,
        int dyHotspot)
{
  DWORD LastError; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v8; // eax
  int (__stdcall *p)(struct _IMAGELIST *, int, int, int); // esi
  int v11; // ebx
  int v12; // [esp+0h] [ebp-30h]
  CComCtlWrapper::ImageList_BeginDrag_Type v13; // [esp+Ch] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int v15; // [esp+14h] [ebp-1Ch]
  int v16; // [esp+2Ch] [ebp-4h]

  LastError = 0;
  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v8 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v15 = 0;
  if ( !v8 )
    return 0;
  v16 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_BeginDrag(this, result: &v13);
  p = this->m__ImageList_BeginDrag.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v11 = ((int (__stdcall *)(struct _IMAGELIST *, int, int, int, int))p)(
          a1: himlTrack,
          a2: iTrack,
          a3: dxHotspot,
          a4: dyHotspot,
          a5: v12);
  v15 = v11;
  v16 = -1;
  if ( v11 == 0 )
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v11 == 0 )
    SetLastError(dwErrCode: LastError);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x100B8EE0
// Name: public: struct CComCtlWrapper::ImageList_EndDrag_Type CComCtlWrapper::GetProcAddress_ImageList_EndDrag(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_EndDrag_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_EndDrag(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_EndDrag_Type *result)
{
  HINSTANCE__ *ModuleHandleA; // eax
  HINSTANCE__ *LibraryA; // eax

  if ( this->m__ImageList_EndDrag.p == nullptr )
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
    this->m__ImageList_EndDrag.p = (void (__stdcall *)())GetProcAddress(
                                                           hModule: this->m_hModule,
                                                           lpProcName: "ImageList_EndDrag");
  }
  result->p = (void (__stdcall *)())this->m__ImageList_EndDrag;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B8F40
// Name: public: void CComCtlWrapper::_ImageList_EndDrag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CComCtlWrapper::_ImageList_EndDrag(CComCtlWrapper *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  void (__stdcall *p)(); // esi
  int v4; // [esp+0h] [ebp-2Ch]
  CComCtlWrapper::ImageList_EndDrag_Type result; // [esp+Ch] [ebp-20h] BYREF
  ULONG_PTR ulActCtxCookie[3]; // [esp+10h] [ebp-1Ch] BYREF
  int v7; // [esp+28h] [ebp-4h]

  ulActCtxCookie[0] = 0;
  ModuleState = AfxGetModuleState();
  if ( ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: ulActCtxCookie) )
  {
    v7 = 0;
    CComCtlWrapper::GetProcAddress_ImageList_EndDrag(this, &result);
    p = this->m__ImageList_EndDrag.p;
    if ( p == nullptr )
      AfxThrowInvalidArgException();
    ((void (__stdcall *)(int))p)(a1: v4);
    v7 = -1;
    DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie[0]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8FE0
// Name: public: struct CComCtlWrapper::ImageList_DragEnter_Type CComCtlWrapper::GetProcAddress_ImageList_DragEnter(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_DragEnter_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_DragEnter(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_DragEnter_Type *result)
{
  HINSTANCE__ *ModuleHandleA; // eax
  HINSTANCE__ *LibraryA; // eax

  if ( this->m__ImageList_DragEnter.p == nullptr )
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
    this->m__ImageList_DragEnter.p = (int (__stdcall *)(HWND__ *, int, int))GetProcAddress(
                                                                              hModule: this->m_hModule,
                                                                              lpProcName: "ImageList_DragEnter");
  }
  result->p = (int (__stdcall *)(HWND__ *, int, int))this->m__ImageList_DragEnter;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B9040
// Name: public: int CComCtlWrapper::_ImageList_DragEnter(struct HWND__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_DragEnter(CComCtlWrapper *this, HWND__ *hwndLock, int x, int y)
{
  DWORD LastError; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v7; // eax
  int (__stdcall *p)(HWND__ *, int, int); // esi
  int v10; // ebx
  int v11; // [esp+0h] [ebp-30h]
  CComCtlWrapper::ImageList_DragEnter_Type v12; // [esp+Ch] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int v14; // [esp+14h] [ebp-1Ch]
  int v15; // [esp+2Ch] [ebp-4h]

  LastError = 0;
  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v7 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v14 = 0;
  if ( !v7 )
    return 0;
  v15 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_DragEnter(this, result: &v12);
  p = this->m__ImageList_DragEnter.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v10 = ((int (__stdcall *)(HWND__ *, int, int, int))p)(a1: hwndLock, a2: x, a3: y, a4: v11);
  v14 = v10;
  v15 = -1;
  if ( v10 == 0 )
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v10 == 0 )
    SetLastError(dwErrCode: LastError);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x100B9130
// Name: public: struct CComCtlWrapper::ImageList_DragLeave_Type CComCtlWrapper::GetProcAddress_ImageList_DragLeave(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_DragLeave_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_DragLeave(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_DragLeave_Type *result)
{
  HINSTANCE__ *ModuleHandleA; // eax
  HINSTANCE__ *LibraryA; // eax

  if ( this->m__ImageList_DragLeave.p == nullptr )
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
    this->m__ImageList_DragLeave.p = (int (__stdcall *)(HWND__ *))GetProcAddress(
                                                                    hModule: this->m_hModule,
                                                                    lpProcName: "ImageList_DragLeave");
  }
  result->p = (int (__stdcall *)(HWND__ *))this->m__ImageList_DragLeave;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B9190
// Name: public: int CComCtlWrapper::_ImageList_DragLeave(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_DragLeave(CComCtlWrapper *this, HWND__ *hwndLock)
{
  DWORD LastError; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v5; // eax
  int (__stdcall *p)(HWND__ *); // esi
  int v8; // ebx
  int v9; // [esp+0h] [ebp-30h]
  CComCtlWrapper::ImageList_DragLeave_Type v10; // [esp+Ch] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int v12; // [esp+14h] [ebp-1Ch]
  int v13; // [esp+2Ch] [ebp-4h]

  LastError = 0;
  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v5 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v12 = 0;
  if ( !v5 )
    return 0;
  v13 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_DragLeave(this, result: &v10);
  p = this->m__ImageList_DragLeave.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v8 = ((int (__stdcall *)(HWND__ *, int))p)(a1: hwndLock, a2: v9);
  v12 = v8;
  v13 = -1;
  if ( v8 == 0 )
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v8 == 0 )
    SetLastError(dwErrCode: LastError);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100B9270
// Name: public: struct CComCtlWrapper::ImageList_DragMove_Type CComCtlWrapper::GetProcAddress_ImageList_DragMove(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_DragMove_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_DragMove(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_DragMove_Type *result)
{
  HINSTANCE__ *ModuleHandleA; // eax
  HINSTANCE__ *LibraryA; // eax

  if ( this->m__ImageList_DragMove.p == nullptr )
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
    this->m__ImageList_DragMove.p = (int (__stdcall *)(int, int))GetProcAddress(
                                                                   hModule: this->m_hModule,
                                                                   lpProcName: "ImageList_DragMove");
  }
  result->p = (int (__stdcall *)(int, int))this->m__ImageList_DragMove;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B92D0
// Name: public: int CComCtlWrapper::_ImageList_DragMove(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_DragMove(CComCtlWrapper *this, int x, int y)
{
  DWORD LastError; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v6; // eax
  int (__stdcall *p)(int, int); // esi
  int v9; // ebx
  int v10; // [esp+0h] [ebp-30h]
  CComCtlWrapper::ImageList_DragMove_Type v11; // [esp+Ch] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int v13; // [esp+14h] [ebp-1Ch]
  int v14; // [esp+2Ch] [ebp-4h]

  LastError = 0;
  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v6 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v13 = 0;
  if ( !v6 )
    return 0;
  v14 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_DragMove(this, result: &v11);
  p = this->m__ImageList_DragMove.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v9 = ((int (__stdcall *)(int, int, int))p)(a1: x, a2: y, a3: v10);
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
// Address: 0x100B93B0
// Name: public: struct CComCtlWrapper::ImageList_DragShowNolock_Type CComCtlWrapper::GetProcAddress_ImageList_DragShowNolock(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_DragShowNolock_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_DragShowNolock(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_DragShowNolock_Type *result)
{
  HINSTANCE__ *ModuleHandleA; // eax
  HINSTANCE__ *LibraryA; // eax

  if ( this->m__ImageList_DragShowNolock.p == nullptr )
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
    this->m__ImageList_DragShowNolock.p = (int (__stdcall *)(int))GetProcAddress(
                                                                    hModule: this->m_hModule,
                                                                    lpProcName: "ImageList_DragShowNolock");
  }
  result->p = (int (__stdcall *)(int))this->m__ImageList_DragShowNolock;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B9410
// Name: public: int CComCtlWrapper::_ImageList_DragShowNolock(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_DragShowNolock(CComCtlWrapper *this, int fShow)
{
  DWORD LastError; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v5; // eax
  int (__stdcall *p)(int); // esi
  int v8; // ebx
  int v9; // [esp+0h] [ebp-30h]
  CComCtlWrapper::ImageList_DragShowNolock_Type v10; // [esp+Ch] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int v12; // [esp+14h] [ebp-1Ch]
  int v13; // [esp+2Ch] [ebp-4h]

  LastError = 0;
  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v5 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v12 = 0;
  if ( !v5 )
    return 0;
  v13 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_DragShowNolock(this, result: &v10);
  p = this->m__ImageList_DragShowNolock.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v8 = ((int (__stdcall *)(int, int))p)(a1: fShow, a2: v9);
  v12 = v8;
  v13 = -1;
  if ( v8 == 0 )
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v8 == 0 )
    SetLastError(dwErrCode: LastError);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100B94F0
// Name: public: static int CImageList::DragLeave(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CImageList::DragLeave(CWnd *pWndLock)
{
  AFX_MODULE_STATE *v1; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-4h]

  if ( pWndLock != nullptr )
  {
    m_hWnd = pWndLock->m_hWnd;
    ModuleState = AfxGetModuleState();
    return CComCtlWrapper::_ImageList_DragLeave(
             this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
             hwndLock: m_hWnd);
  }
  else
  {
    v1 = AfxGetModuleState();
    return CComCtlWrapper::_ImageList_DragLeave(
             this: *(CComCtlWrapper **)v1->m_pDllIsolationWrappers,
             hwndLock: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9530
// Name: public: void CTreeList::EnableChecks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::EnableChecks(CTreeList *this)
{
  CImageList *p_m_cNormalImageList; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v4; // eax
  struct _IMAGELIST *v5; // eax
  struct _IMAGELIST *m_hImageList; // [esp-Ch] [ebp-14h]
  struct _IMAGELIST *v7; // [esp-Ch] [ebp-14h]

  p_m_cNormalImageList = &this->m_cNormalImageList;
  if ( this == (CTreeList *)-136 || this->m_cNormalImageList.m_hImageList == nullptr )
  {
    CImageList::Create(this: &this->m_cNormalImageList, nBitmapID: 0xDFu, cx: 16, nGrow: 1, crMask: 0xFFFFFFu);
    m_hImageList = this->m_cNormalImageList.m_hImageList;
    ModuleState = AfxGetModuleState();
    CComCtlWrapper::_ImageList_SetOverlayImage(
      this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
      himl: m_hImageList,
      iImage: 1,
      iOverlay: 1);
    v7 = this->m_cNormalImageList.m_hImageList;
    v4 = AfxGetModuleState();
    CComCtlWrapper::_ImageList_SetOverlayImage(
      this: *(CComCtlWrapper **)v4->m_pDllIsolationWrappers,
      himl: v7,
      iImage: 2,
      iOverlay: 2);
  }
  if ( p_m_cNormalImageList != nullptr )
    p_m_cNormalImageList = (CImageList *)p_m_cNormalImageList->m_hImageList;
  v5 = (struct _IMAGELIST *)SendMessageA(
                              hWnd: this->m_hWnd,
                              Msg: 0x1109u,
                              wParam: 2u,
                              lParam: (LPARAM)p_m_cNormalImageList);
  CImageList::FromHandle(h: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100B95B0
// Name: public: void CTreeList::DeleteAllItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::DeleteAllItems(CTreeList *this)
{
  if ( this != nullptr && this->m_hWnd != nullptr && this->m_Items.m_Size > 0 )
    UnsetItemData_R(pCtrl: this, hItem: (struct _TREEITEM *)0xFFFF0000);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x1101u, wParam: 0, lParam: -65536);
  this->m_Items.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B9600
// Name: public: void CTreeList::EnsureVisible(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::EnsureVisible(CTreeList *this, void *pItem)
{
  struct _TREEITEM *HTreeItem; // eax

  HTreeItem = CTreeList::FindHTreeItem(this, pItem);
  if ( HTreeItem != nullptr )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x1114u, wParam: 0, lParam: (LPARAM)HTreeItem);
}

//------------------------------------------------------------------------------
// Address: 0x100B9630
// Name: public: void CTreeList::CollapseItem(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::CollapseItem(CTreeList *this, void *pItem)
{
  struct _TREEITEM *HTreeItem; // eax

  HTreeItem = CTreeList::FindHTreeItem(this, pItem);
  if ( HTreeItem != nullptr )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x1102u, wParam: 1u, lParam: (LPARAM)HTreeItem);
}

//------------------------------------------------------------------------------
// Address: 0x100B9660
// Name: public: int CTreeList::GetSelectedIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTreeList::GetSelectedIndex(CTreeList *this)
{
  struct _TREEITEM *v2; // eax
  unsigned int ItemData; // edx
  int m_Size; // ecx
  int result; // eax
  void **i; // esi

  v2 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 9u, lParam: 0);
  if ( v2 == nullptr )
    return -1;
  ItemData = CTreeCtrl::GetItemData(this, hItem: v2);
  if ( ItemData == 0 )
    return -1;
  m_Size = this->m_Items.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Items.m_Memory.m_pMemory; *i != (void *)ItemData; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B96C0
// Name: private: void CTreeList::BeginDrag(class CPoint,struct _TREEITEM __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::BeginDrag(CTreeList *this, CPoint point, struct _TREEITEM *hItem)
{
  CImageList *DragImage; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v6; // eax
  HWND v7; // eax
  struct _IMAGELIST *m_hImageList; // [esp-10h] [ebp-14h]
  HWND__ *m_hWnd; // [esp-Ch] [ebp-10h]

  this->m_hDragItem = hItem;
  if ( hItem != nullptr )
  {
    DragImage = CTreeCtrl::CreateDragImage(this, hItem);
    this->m_pDragImageList = DragImage;
    if ( DragImage != nullptr )
    {
      m_hImageList = DragImage->m_hImageList;
      ModuleState = AfxGetModuleState();
      CComCtlWrapper::_ImageList_BeginDrag(
        this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
        himlTrack: m_hImageList,
        iTrack: 0,
        dxHotspot: 0,
        dyHotspot: 0);
      m_hWnd = this->m_hWnd;
      v6 = AfxGetModuleState();
      CComCtlWrapper::_ImageList_DragEnter(
        this: *(CComCtlWrapper **)v6->m_pDllIsolationWrappers,
        hwndLock: m_hWnd,
        x: point.x,
        y: point.y);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Bu, wParam: 8u, lParam: 0);
    }
    SetTimer(hWnd: this->m_hWnd, nIDEvent: 1u, uElapse: 0x12Cu, lpTimerFunc: nullptr);
    v7 = SetCapture(hWnd: this->m_hWnd);
    CWnd::FromHandle(hWnd: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9760
// Name: private: void CTreeList::Drop(enum CTreeList::DropType_t,unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::Drop(CTreeList *this, CTreeList::DropType_t eDropType, unsigned int nFlags, CPoint point)
{
  struct _TREEITEM *m_hDragItem; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v7; // eax
  CImageList *m_pDragImageList; // ecx
  WPARAM ItemData; // ebx
  struct _TREEITEM *v10; // eax
  LPARAM v11; // edi
  HWND Parent; // eax
  CWnd *v13; // eax
  UINT v14; // ecx
  HWND__ *m_hWnd; // [esp-4h] [ebp-10h]

  SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Bu, wParam: 8u, lParam: 0);
  m_hDragItem = this->m_hDragItem;
  this->m_hDragItem = nullptr;
  if ( this->m_pDragImageList != nullptr )
  {
    m_hWnd = this->m_hWnd;
    ModuleState = AfxGetModuleState();
    CComCtlWrapper::_ImageList_DragLeave(
      this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
      hwndLock: m_hWnd);
    v7 = AfxGetModuleState();
    CComCtlWrapper::_ImageList_EndDrag(this: *(CComCtlWrapper **)v7->m_pDllIsolationWrappers);
    m_pDragImageList = this->m_pDragImageList;
    if ( m_pDragImageList != nullptr )
      ((void (__thiscall *)(CImageList *, int))m_pDragImageList->dtr_CObject)(a1: m_pDragImageList, a2: 1);
    this->m_pDragImageList = nullptr;
  }
  ItemData = CTreeCtrl::GetItemData(this, hItem: m_hDragItem);
  v10 = CTreeCtrl::HitTest(this, pt: point, pFlags: nullptr);
  if ( v10 != m_hDragItem )
  {
    v11 = 0;
    if ( v10 != nullptr )
      v11 = CTreeCtrl::GetItemData(this, hItem: v10);
    if ( ItemData != v11 )
    {
      Parent = GetParent(hWnd: this->m_hWnd);
      v13 = CWnd::FromHandle(hWnd: Parent);
      if ( v13 != nullptr )
      {
        v14 = g_uLeftDragDropMsg;
        if ( eDropType != DROP_LEFT )
          v14 = g_uRightDragDropMsg;
        PostMessageA(hWnd: v13->m_hWnd, Msg: v14, wParam: ItemData, lParam: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9840
// Name: protected: void CTreeList::OnMouseMove(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnMouseMove(CTreeList *this, unsigned int nFlags, CPoint point)
{
  struct _TREEITEM *v4; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  struct _TREEITEM *v6; // edi
  AFX_MODULE_STATE *v7; // eax
  AFX_MODULE_STATE *v8; // eax
  HWND__ *m_hWnd; // [esp-14h] [ebp-18h]

  CWnd::Default(this);
  if ( !this->m_bRButtonDown )
    goto LABEL_6;
  if ( this->m_hDragItem == nullptr )
  {
    if ( point.x != this->m_ptRButtonDown.x && point.y != this->m_ptRButtonDown.y )
    {
      v4 = CTreeCtrl::HitTest(this, pt: this->m_ptRButtonDown, pFlags: nullptr);
      CTreeList::BeginDrag(this, point, hItem: v4);
    }
LABEL_6:
    if ( this->m_hDragItem == nullptr )
      return;
  }
  if ( this->m_pDragImageList != nullptr )
  {
    ModuleState = AfxGetModuleState();
    CComCtlWrapper::_ImageList_DragMove(
      this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
      x: point.x,
      y: point.y);
  }
  v6 = CTreeCtrl::HitTest(this, pt: point, pFlags: nullptr);
  if ( v6 != (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 8u, lParam: 0) )
  {
    if ( this->m_pDragImageList != nullptr )
    {
      CImageList::DragLeave(pWndLock: this);
      v7 = AfxGetModuleState();
      CComCtlWrapper::_ImageList_DragShowNolock(this: *(CComCtlWrapper **)v7->m_pDllIsolationWrappers, fShow: 0);
    }
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Bu, wParam: 8u, lParam: (LPARAM)v6);
    if ( this->m_pDragImageList != nullptr )
    {
      m_hWnd = this->m_hWnd;
      v8 = AfxGetModuleState();
      CComCtlWrapper::_ImageList_DragEnter(
        this: *(CComCtlWrapper **)v8->m_pDllIsolationWrappers,
        hwndLock: m_hWnd,
        x: point.x,
        y: point.y);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9940
// Name: public: void CTreeList::SelectNearestItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::SelectNearestItem(CTreeList *this, int nItem)
{
  int v2; // eax
  int m_Size; // ecx
  struct _TREEITEM *HTreeItem; // eax

  v2 = nItem;
  m_Size = this->m_Items.m_Size;
  if ( m_Size > 0 && m_Size <= nItem )
    v2 = m_Size - 1;
  if ( v2 >= 0 && v2 < m_Size )
  {
    HTreeItem = CTreeList::FindHTreeItem(this, pItem: this->m_Items.m_Memory.m_pMemory[v2]);
    if ( HTreeItem != nullptr )
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Bu, wParam: 9u, lParam: (LPARAM)HTreeItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9990
// Name: public: void CTreeList::EnsureVisible(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::EnsureVisible(CTreeList *this, int nItem)
{
  int v2; // eax
  int m_Size; // ecx
  struct _TREEITEM *HTreeItem; // eax

  v2 = nItem;
  m_Size = this->m_Items.m_Size;
  if ( m_Size > 0 && m_Size <= nItem )
    v2 = m_Size - 1;
  if ( v2 >= 0 && v2 < m_Size )
  {
    HTreeItem = CTreeList::FindHTreeItem(this, pItem: this->m_Items.m_Memory.m_pMemory[v2]);
    if ( HTreeItem != nullptr )
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x1114u, wParam: 0, lParam: (LPARAM)HTreeItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9A00
// Name: public: void CTreeList::RestoreTreeListExpandStates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::RestoreTreeListExpandStates(CTreeList *this)
{
  int v2; // ecx
  TreeListItemState_t *m_pMemory; // eax
  struct _TREEITEM *v4; // esi
  struct _TREEITEM *HTreeItemRecursive; // eax
  void *thisPair; // [esp+4h] [ebp-Ch]
  int thisPair_4; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  CTreeList::ExpandAll(this);
  v2 = 0;
  i = 0;
  if ( this->m_ItemState.m_Size > 0 )
  {
    while ( 1 )
    {
      m_pMemory = this->m_ItemState.m_Memory.m_pMemory;
      thisPair = m_pMemory[v2].pItem;
      thisPair_4 = *(_DWORD *)&m_pMemory[v2].bExpanded;
      v4 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 0, lParam: 0);
      if ( v4 != nullptr )
      {
        while ( 1 )
        {
          HTreeItemRecursive = CTreeList::FindHTreeItemRecursive(this, hItem: v4, pItem: thisPair);
          if ( HTreeItemRecursive != nullptr )
            break;
          v4 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 1u, lParam: (LPARAM)v4);
          if ( v4 == nullptr )
            goto LABEL_11;
        }
        if ( (_BYTE)thisPair_4 != 0 )
          SendMessageA(hWnd: this->m_hWnd, Msg: 0x1102u, wParam: 2u, lParam: (LPARAM)HTreeItemRecursive);
        else
          SendMessageA(hWnd: this->m_hWnd, Msg: 0x1102u, wParam: 1u, lParam: (LPARAM)HTreeItemRecursive);
      }
LABEL_11:
      if ( ++i >= this->m_ItemState.m_Size )
        break;
      v2 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9AD0
// Name: protected: void CTreeList::OnLButtonUp(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnLButtonUp(CTreeList *this, unsigned int nFlags, CPoint point)
{
  struct _TREEITEM *v4; // ebx
  HWND Parent; // eax
  LPARAM v6; // esi
  WPARAM ItemData; // eax
  CWnd *pwndParent; // [esp+4h] [ebp-4h]

  KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
  ReleaseCapture();
  if ( this->m_hDragItem != nullptr )
  {
    CTreeList::Drop(this, eDropType: DROP_LEFT, nFlags, point);
  }
  else
  {
    v4 = CTreeCtrl::HitTest(this, pt: point, pFlags: &nFlags);
    if ( v4 != nullptr && (nFlags & 0x40) != 0 )
    {
      Parent = GetParent(hWnd: this->m_hWnd);
      pwndParent = CWnd::FromHandle(hWnd: Parent);
      if ( pwndParent != nullptr )
      {
        v6 = CTreeList::GetCheck(this, hItem: v4) == 0;
        ItemData = CTreeCtrl::GetItemData(this, hItem: v4);
        PostMessageA(hWnd: pwndParent->m_hWnd, Msg: g_uToggleStateMsg, wParam: ItemData, lParam: v6);
      }
    }
    else
    {
      CWnd::Default(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9B90
// Name: protected: void CTreeList::OnBegindrag(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnBegindrag(CTreeList *this, tagNMHDR *pNMHDR, int *pResult)
{
  CTreeList::BeginDrag(this, point: *(CPoint *)&pNMHDR[8].hwndFrom, hItem: (struct _TREEITEM *)pNMHDR[5].hwndFrom);
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B9BC0
// Name: protected: void CTreeList::OnContextMenu(class CWnd __near *,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnContextMenu(CTreeList *this, CWnd *pWnd, CPoint point)
{
  bool v4; // zf

  KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
  ReleaseCapture();
  v4 = this->m_hDragItem == nullptr;
  this->m_bRButtonDown = false;
  if ( v4 )
    CWnd::Default(this);
  else
    CTreeList::Drop(this, eDropType: DROP_RIGHT, nFlags: 0, point);
}

//------------------------------------------------------------------------------
// Address: 0x100B9C10
// Name: protected: void CTreeList::OnRButtonUp(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::OnRButtonUp(CTreeList *this, unsigned int nFlags, CPoint point)
{
  bool v4; // zf

  KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
  ReleaseCapture();
  v4 = this->m_hDragItem == nullptr;
  this->m_bRButtonDown = false;
  if ( v4 )
    CWnd::Default(this);
  else
    CTreeList::Drop(this, eDropType: DROP_RIGHT, nFlags, point);
}

//------------------------------------------------------------------------------
// Address: 0x100B9C60
// Name: public: CTreeList::CTreeList(void)
// Source: json
//------------------------------------------------------------------------------
CTreeList *__thiscall CTreeList::CTreeList(CTreeList *this)
{
  void **m_pMemory; // ecx
  TreeListItemState_t *v3; // ecx

  CWnd::CWnd(this);
  this->__vftable = (CTreeList_vtbl *)&CTreeCtrl::`vftable';
  this->__vftable = (CTreeList_vtbl *)&CTreeList::`vftable';
  this->m_ptRButtonDown.x = 0;
  this->m_ptRButtonDown.y = 0;
  this->m_ptLDown.x = 0;
  this->m_ptLDown.y = 0;
  CImageList::CImageList(this: &this->m_cNormalImageList);
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Items.m_Memory.m_pMemory;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = m_pMemory;
  this->m_ItemState.m_Memory.m_pMemory = nullptr;
  this->m_ItemState.m_Memory.m_nAllocationCount = 0;
  this->m_ItemState.m_Memory.m_nGrowSize = 0;
  v3 = this->m_ItemState.m_Memory.m_pMemory;
  this->m_ItemState.m_Size = 0;
  this->m_ItemState.m_pElements = v3;
  this->m_pDragImageList = nullptr;
  this->m_hDragItem = nullptr;
  this->m_bRButtonDown = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B9D30
// Name: public: virtual CTreeList::~CTreeList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::~CTreeList(CTreeList *this)
{
  CUtlVector<TreeListItemState_t,CUtlMemory<TreeListItemState_t,int> > *p_m_ItemState; // esi
  CUtlVector<void *,CUtlMemory<void *,int> > *p_m_Items; // esi

  this->__vftable = (CTreeList_vtbl *)&CTreeList::`vftable';
  p_m_ItemState = &this->m_ItemState;
  this->m_ItemState.m_Size = 0;
  if ( this->m_ItemState.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ItemState->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ItemState->m_Memory.m_pMemory);
      p_m_ItemState->m_Memory.m_pMemory = nullptr;
    }
    p_m_ItemState->m_Memory.m_nAllocationCount = 0;
  }
  p_m_ItemState->m_pElements = p_m_ItemState->m_Memory.m_pMemory;
  if ( p_m_ItemState->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ItemState->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ItemState->m_Memory.m_pMemory);
      p_m_ItemState->m_Memory.m_pMemory = nullptr;
    }
    p_m_ItemState->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Items = &this->m_Items;
  this->m_Items.m_Size = 0;
  if ( this->m_Items.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Items->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Items->m_Memory.m_pMemory);
      p_m_Items->m_Memory.m_pMemory = nullptr;
    }
    this->m_Items.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Items.m_pElements = this->m_Items.m_Memory.m_pMemory;
  if ( this->m_Items.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Items->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Items->m_Memory.m_pMemory);
      p_m_Items->m_Memory.m_pMemory = nullptr;
    }
    this->m_Items.m_Memory.m_nAllocationCount = 0;
  }
  CImageList::~CImageList(this: &this->m_cNormalImageList);
  CTreeCtrl::~CTreeCtrl(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B9E30
// Name: protected: virtual struct AFX_MSGMAP const __near * CTreeList::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CTreeList::GetMessageMap(CTreeList *this)
{
  return (const AFX_MSGMAP *)&off_105E7B80;
}

//------------------------------------------------------------------------------
// Address: 0x100B9E70
// Name: public: void CTreeList::AddItem(void __near *,void __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::AddItem(
        CTreeList *this,
        void *pItem,
        struct _TREEITEM *pParent,
        const char *pText,
        bool bHasCheckBox)
{
  struct _TREEITEM *HTreeItem; // eax
  struct _TREEITEM *inserted; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  void **m_pMemory; // ecx
  int v11; // eax
  void **v12; // edi
  struct _TREEITEM *hItem; // [esp+10h] [ebp+Ch]

  HTreeItem = (struct _TREEITEM *)-65536;
  if ( pParent != nullptr )
    HTreeItem = CTreeList::FindHTreeItem(this, pItem: pParent);
  inserted = CTreeCtrl::InsertItem(
               this,
               nMask: 1u,
               lpszItem: pText,
               nImage: 0,
               nSelectedImage: 0,
               nState: 0,
               nStateMask: 0,
               lParam: 0,
               hParent: HTreeItem,
               hInsertAfter: (struct _TREEITEM *)0xFFFF0002);
  hItem = inserted;
  if ( inserted != nullptr )
  {
    CTreeCtrl::SetItem(
      this,
      hItem: inserted,
      nMask: 4u,
      lpszItem: nullptr,
      nImage: 0,
      nSelectedImage: 0,
      nState: 0,
      nStateMask: 0,
      lParam: (int)pItem);
    m_Size = this->m_Items.m_Size;
    m_nAllocationCount = this->m_Items.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow(
        this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_Items,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Items.m_Size;
    m_pMemory = this->m_Items.m_Memory.m_pMemory;
    v11 = this->m_Items.m_Size - m_Size - 1;
    this->m_Items.m_pElements = m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
    v12 = &this->m_Items.m_Memory.m_pMemory[m_Size];
    if ( v12 != nullptr )
      *v12 = pItem;
    if ( bHasCheckBox )
      CTreeCtrl::SetItem(
        this,
        hItem,
        nMask: 8u,
        lpszItem: nullptr,
        nImage: 0,
        nSelectedImage: 0,
        nState: 0x1000u,
        nStateMask: 0xF000u,
        lParam: 0);
    else
      CTreeCtrl::SetItem(
        this,
        hItem,
        nMask: 8u,
        lpszItem: nullptr,
        nImage: 0,
        nSelectedImage: 0,
        nState: 0,
        nStateMask: 0xF000u,
        lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9F80
// Name: public: void CTreeList::SaveTreeListExpandStates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeList::SaveTreeListExpandStates(CTreeList *this)
{
  int m_Size; // edx
  int v3; // eax
  TreeListItemState_t *m_pMemory; // ecx
  struct _TREEITEM *v5; // esi
  struct _TREEITEM *HTreeItemRecursive; // eax
  int v7; // esi
  int m_nAllocationCount; // eax
  TreeListItemState_t *v9; // ecx
  int v10; // eax
  TreeListItemState_t *v11; // esi
  int newState_4; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  void *pItem; // [esp+18h] [ebp-4h]

  for ( i = 0; i < this->m_Items.m_Size; ++i )
  {
    pItem = this->m_Items.m_Memory.m_pMemory[i];
    m_Size = this->m_ItemState.m_Size;
    v3 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_ItemState.m_Memory.m_pMemory;
      while ( pItem != m_pMemory->pItem )
      {
        ++v3;
        ++m_pMemory;
        if ( v3 >= m_Size )
          goto LABEL_10;
      }
      if ( m_Size - v3 - 1 > 0 )
        _V_memmove(
          dest: &this->m_ItemState.m_Memory.m_pMemory[v3],
          src: &this->m_ItemState.m_Memory.m_pMemory[v3 + 1],
          count: 8 * (m_Size - v3 - 1));
      --this->m_ItemState.m_Size;
    }
LABEL_10:
    v5 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 0, lParam: 0);
    if ( v5 != nullptr )
    {
      while ( 1 )
      {
        HTreeItemRecursive = CTreeList::FindHTreeItemRecursive(this, hItem: v5, pItem);
        if ( HTreeItemRecursive != nullptr )
          break;
        v5 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 1u, lParam: (LPARAM)v5);
        if ( v5 == nullptr )
          goto LABEL_13;
      }
    }
    else
    {
LABEL_13:
      HTreeItemRecursive = nullptr;
    }
    LOBYTE(newState_4) = 0;
    if ( HTreeItemRecursive != nullptr )
      LOBYTE(newState_4) = (CTreeCtrl::GetItemState(this, hItem: HTreeItemRecursive, nStateMask: 0x20u) & 0x20) != 0;
    v7 = this->m_ItemState.m_Size;
    m_nAllocationCount = this->m_ItemState.m_Memory.m_nAllocationCount;
    if ( v7 + 1 > m_nAllocationCount )
      CUtlMemory<UsedTexture_t,int>::Grow(
        this: (CUtlMemory<CDispPaintMgr::DispVertPair_t,int> *)&this->m_ItemState,
        num: v7 - m_nAllocationCount + 1);
    ++this->m_ItemState.m_Size;
    v9 = this->m_ItemState.m_Memory.m_pMemory;
    v10 = this->m_ItemState.m_Size - v7 - 1;
    this->m_ItemState.m_pElements = v9;
    if ( v10 > 0 )
      _V_memmove(dest: &v9[v7 + 1], src: &v9[v7], count: 8 * v10);
    v11 = &this->m_ItemState.m_Memory.m_pMemory[v7];
    if ( v11 != nullptr )
    {
      v11->pItem = pItem;
      *(_DWORD *)&v11->bExpanded = newState_4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10338FFB
// Name: public: virtual void CCmdUI::SetCheck(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCmdUI::SetCheck(CCmdUI *this, WPARAM nCheck)
{
  CMenu *m_pMenu; // ecx
  UINT m_nIndex; // eax
  CWnd *m_pOther; // eax

  m_pMenu = this->m_pMenu;
  if ( m_pMenu != nullptr )
  {
    if ( this->m_pSubMenu == nullptr )
    {
      m_nIndex = this->m_nIndex;
      if ( m_nIndex >= this->m_nIndexMax )
        goto LABEL_4;
      CheckMenuItem(hMenu: m_pMenu->m_hMenu, uIDCheckItem: m_nIndex, uCheck: (nCheck != 0 ? 8 : 0) | 0x400);
    }
  }
  else
  {
    m_pOther = this->m_pOther;
    if ( m_pOther == nullptr )
LABEL_4:
      AfxThrowInvalidArgException();
    if ( (SendMessageA(hWnd: m_pOther->m_hWnd, Msg: 0x87u, wParam: 0, lParam: 0) & 0x2000) != 0 )
      SendMessageA(hWnd: this->m_pOther->m_hWnd, Msg: 0xF1u, wParam: nCheck, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034A730
// Name: public: virtual CTreeCtrl::~CTreeCtrl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeCtrl::~CTreeCtrl(CTreeCtrl *this)
{
  this->__vftable = (CTreeCtrl_vtbl *)&CTreeCtrl::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034A761
// Name: public: int CTreeCtrl::GetItemRect(struct _TREEITEM __near *,struct tagRECT __near *,int)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CTreeCtrl::GetItemRect(CTreeCtrl *this, struct _TREEITEM *hItem, tagRECT *lpRect, WPARAM bTextOnly)
{
  lpRect->left = (int)hItem;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x1104u, wParam: bTextOnly, lParam: (LPARAM)lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x1034A784
// Name: public: unsigned int CTreeCtrl::GetItemState(struct _TREEITEM __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CTreeCtrl::GetItemState(CTreeCtrl *this, struct _TREEITEM *hItem, unsigned int nStateMask)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-38h]
  tagTVITEMA item; // [esp+0h] [ebp-28h] BYREF

  item.state = 0;
  item.hItem = hItem;
  item.stateMask = nStateMask;
  m_hWnd = this->m_hWnd;
  item.mask = 8;
  SendMessageA(hWnd: m_hWnd, Msg: 0x110Cu, wParam: 0, lParam: (LPARAM)&item);
  return item.state;
}

//------------------------------------------------------------------------------
// Address: 0x1034A7BE
// Name: public: unsigned long CTreeCtrl::GetItemData(struct _TREEITEM __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTreeCtrl::GetItemData(CTreeCtrl *this, struct _TREEITEM *hItem)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-3Ch]
  tagTVITEMA item; // [esp+4h] [ebp-28h] BYREF

  if ( !IsWindow(hWnd: this->m_hWnd) || hItem == nullptr )
    AfxThrowInvalidArgException();
  item.hItem = hItem;
  m_hWnd = this->m_hWnd;
  item.mask = 4;
  SendMessageA(hWnd: m_hWnd, Msg: 0x110Cu, wParam: 0, lParam: (LPARAM)&item);
  return item.lParam;
}

//------------------------------------------------------------------------------
// Address: 0x1034A808
// Name: public: int CTreeCtrl::ItemHasChildren(struct _TREEITEM __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTreeCtrl::ItemHasChildren(CTreeCtrl *this, struct _TREEITEM *hItem)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-38h]
  tagTVITEMA item; // [esp+0h] [ebp-28h] BYREF

  item.hItem = hItem;
  m_hWnd = this->m_hWnd;
  item.mask = 64;
  SendMessageA(hWnd: m_hWnd, Msg: 0x110Cu, wParam: 0, lParam: (LPARAM)&item);
  return item.cChildren;
}

//------------------------------------------------------------------------------
// Address: 0x1034A838
// Name: public: int CTreeCtrl::SetItem(struct _TREEITEM __near *,unsigned int,char const __near *,int,int,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CTreeCtrl::SetItem(
        CTreeCtrl *this,
        struct _TREEITEM *hItem,
        unsigned int nMask,
        char *lpszItem,
        int nImage,
        int nSelectedImage,
        unsigned int nState,
        unsigned int nStateMask,
        int lParam)
{
  tagTVITEMA item; // [esp+0h] [ebp-28h] BYREF

  item.hItem = hItem;
  item.mask = nMask;
  item.pszText = lpszItem;
  item.iImage = nImage;
  item.iSelectedImage = nSelectedImage;
  item.state = nState;
  item.stateMask = nStateMask;
  item.lParam = lParam;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Du, wParam: 0, lParam: (LPARAM)&item);
}

//------------------------------------------------------------------------------
// Address: 0x1034A888
// Name: public: struct _TREEITEM __near * CTreeCtrl::InsertItem(unsigned int,char const __near *,int,int,unsigned int,unsigned int,long,struct _TREEITEM __near *,struct _TREEITEM __near *)
// Source: json
//------------------------------------------------------------------------------
struct _TREEITEM *__thiscall CTreeCtrl::InsertItem(
        CTreeCtrl *this,
        unsigned int nMask,
        char *lpszItem,
        unsigned int nImage,
        unsigned int nSelectedImage,
        unsigned int nState,
        unsigned int nStateMask,
        int lParam,
        struct _TREEITEM *hParent,
        struct _TREEITEM *hInsertAfter)
{
  tagTVINSERTSTRUCTA tvis; // [esp+0h] [ebp-44h] BYREF

  tvis.hParent = hParent;
  tvis.hInsertAfter = hInsertAfter;
  tvis.itemex.mask = nMask;
  tvis.itemex.pszText = lpszItem;
  *(_QWORD *)&tvis.item.iImage = __PAIR64__(nSelectedImage, nImage);
  *(_QWORD *)&tvis.item.state = __PAIR64__(nStateMask, nState);
  tvis.itemex.lParam = lParam;
  return (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1100u, wParam: 0, lParam: (LPARAM)&tvis);
}

//------------------------------------------------------------------------------
// Address: 0x1034A8DE
// Name: public: struct _TREEITEM __near * CTreeCtrl::HitTest(class CPoint,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
struct _TREEITEM *__thiscall CTreeCtrl::HitTest(CTreeCtrl *this, tagPOINT pt, unsigned int *pFlags)
{
  struct _TREEITEM *result; // eax
  tagTVHITTESTINFO hti; // [esp+0h] [ebp-10h] BYREF

  hti.pt = pt;
  result = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1111u, wParam: 0, lParam: (LPARAM)&hti);
  if ( pFlags != nullptr )
    *pFlags = hti.flags;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034ABEA
// Name: public: virtual struct CRuntimeClass __near * CTreeCtrl::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CTreeCtrl::GetRuntimeClass(CTreeCtrl *this)
{
  return &CTreeCtrl::classCTreeCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x1034B1AB
// Name: protected: void CTreeCtrl::RemoveImageList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeCtrl::RemoveImageList(CTreeCtrl *this, WPARAM nImageList)
{
  struct _IMAGELIST *v3; // eax

  v3 = (struct _IMAGELIST *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1108u, wParam: nImageList, lParam: 0);
  if ( CImageList::FromHandlePermanent(h: v3) != nullptr )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x1109u, wParam: nImageList, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1034B1E8
// Name: public: void CTreeCtrl::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTreeCtrl::OnDestroy(CTreeCtrl *this)
{
  CTreeCtrl::RemoveImageList(this, nImageList: 0);
  CTreeCtrl::RemoveImageList(this, nImageList: 2u);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034B205
// Name: public: class CImageList __near * CTreeCtrl::CreateDragImage(struct _TREEITEM __near *)
// Source: json
//------------------------------------------------------------------------------
CImageList *__thiscall CTreeCtrl::CreateDragImage(CTreeCtrl *this, struct _TREEITEM *hItem)
{
  CImageList *v2; // esi
  struct _IMAGELIST *v3; // edi
  CImageList *v5; // eax

  v2 = nullptr;
  v3 = (struct _IMAGELIST *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1112u, wParam: 0, lParam: (LPARAM)hItem);
  if ( v3 == nullptr )
    return nullptr;
  v5 = (CImageList *)operator new(nSize: 8u);
  if ( v5 != nullptr )
  {
    v5->m_hImageList = nullptr;
    v5->__vftable = (CImageList_vtbl *)&CImageList::`vftable';
    v2 = v5;
  }
  CImageList::Attach(this: v2, hImageList: v3);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1034B381
// Name: protected: virtual struct AFX_MSGMAP const __near * CTreeCtrl::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CTreeCtrl::GetMessageMap(CTreeCtrl *this)
{
  return &messageMap_17;
}

//------------------------------------------------------------------------------
// Address: 0x103502C3
// Name: public: virtual void CStatusCmdUI::SetCheck(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatusCmdUI::SetCheck(CStatusCmdUI *this, int nCheck)
{
  CStatusBar *m_pOther; // ecx
  unsigned int m_nIndex; // edx
  unsigned int v5; // eax

  m_pOther = (CStatusBar *)this->m_pOther;
  m_nIndex = this->m_nIndex;
  v5 = *((_DWORD *)m_pOther->m_pData + 5 * m_nIndex + 2) & 0xFFFFFDFF;
  if ( nCheck != 0 )
    v5 |= 0x200u;
  CStatusBar::SetPaneStyle(this: m_pOther, nIndex: m_nIndex, nStyle: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10354885
// Name: public: virtual void CToolCmdUI::SetCheck(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CToolCmdUI::SetCheck(CToolCmdUI *this@<ecx>, int a2@<ebx>, int nCheck)
{
  CToolBar *m_pOther; // edi
  unsigned int v5; // eax

  m_pOther = (CToolBar *)this->m_pOther;
  v5 = CToolBar::GetButtonStyle(this: m_pOther, nIndex: this->m_nIndex) & 0xFFEEFFFF;
  if ( nCheck == 1 )
  {
    v5 |= 0x10000u;
  }
  else if ( nCheck == 2 )
  {
    v5 |= 0x100000u;
  }
  CToolBar::SetButtonStyle(this: m_pOther, a2, nIndex: this->m_nIndex, nStyle: v5 | 2);
}

//------------------------------------------------------------------------------
// Address: 0x103991BA
// Name: protected: void CVSListBox::OnEndLabelEdit(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVSListBox::OnEndLabelEdit(CVSListBox *this, tagNMHDR *pNMHDR, int *pResult)
{
  CList<CMFCButton *,CMFCButton *>::CNode *m_pNodeTail; // esi
  CWnd *data; // ecx

  if ( pNMHDR == nullptr || pNMHDR == (tagNMHDR *)-12 )
LABEL_2:
    AfxThrowInvalidArgException();
  this->OnEndEditLabel(this, a2: (const char *)pNMHDR[2].code);
  m_pNodeTail = this->m_lstButtons.m_pNodeTail;
  while ( m_pNodeTail != nullptr )
  {
    data = m_pNodeTail->data;
    m_pNodeTail = m_pNodeTail->pPrev;
    if ( data == nullptr )
      goto LABEL_2;
    CWnd::EnableWindow(this: data, bEnable: 1);
  }
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039A592
// Name: public: int CTreeCtrl::DeleteAllItems(void)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CTreeCtrl::DeleteAllItems(CTreeCtrl *this)
{
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x1101u, wParam: 0, lParam: -65536);
}

//------------------------------------------------------------------------------
// Address: 0x103AC5A6
// Name: public: virtual void CMFCToolBarCmdUI::SetCheck(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarCmdUI::SetCheck(CMFCToolBarCmdUI *this, int nCheck)
{
  int v2; // ebx
  CMFCToolBar *m_pOther; // edi
  unsigned int v5; // eax

  v2 = nCheck;
  if ( nCheck > 2 )
    v2 = 1;
  m_pOther = (CMFCToolBar *)this->m_pOther;
  if ( m_pOther == nullptr )
    AfxThrowInvalidArgException();
  v5 = CMFCToolBar::GetButtonStyle(this: m_pOther, nIndex: this->m_nIndex) & 0xFFEEFFFF;
  if ( v2 == 1 )
  {
    v5 |= 0x10000u;
  }
  else if ( v2 == 2 )
  {
    v5 |= 0x100000u;
  }
  m_pOther->SetButtonStyle(this: m_pOther, a2: this->m_nIndex, a3: v5 | 2);
}

//------------------------------------------------------------------------------
// Address: 0x103F1628
// Name: public: virtual void CMFCRibbonCmdUI::SetCheck(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCmdUI::SetCheck(CMFCRibbonCmdUI *this, int nCheck)
{
  int v3; // esi
  CRect *p_m_rect; // esi
  CWnd *m_pOther; // eax
  RECT rcUpdate; // [esp+8h] [ebp-14h] BYREF

  v3 = nCheck == 1;
  if ( this->m_pUpdated->IsChecked(this: this->m_pUpdated) != v3 )
  {
    this->m_pUpdated->m_bIsChecked = v3;
    this->m_pUpdated->OnCheck(this: this->m_pUpdated, a2: v3);
    p_m_rect = &this->m_pUpdated->m_rect;
    rcUpdate.left = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    rcUpdate.top = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    rcUpdate.right = p_m_rect->left;
    m_pOther = this->m_pOther;
    rcUpdate.bottom = p_m_rect->top;
    RedrawWindow(hWnd: m_pOther->m_hWnd, lprcUpdate: &rcUpdate, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10421ACC
// Name: public: virtual long COleDropTarget::XDropTarget::DragLeave(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall COleDropTarget::XDropTarget::DragLeave(COleDropTarget::XDropTarget *this)
{
  CWnd *v1; // ebx
  COleDataObject dataObject; // [esp+Ch] [ebp-18h] BYREF
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+1Ch] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 6));
  v1 = CWnd::FromHandle(hWnd: *((HWND__ **)this - 5));
  *((_DWORD *)this - 3) = 0xFFFF;
  COleDataObject::COleDataObject(this: &dataObject);
  COleDataObject::Attach(this: &dataObject, lpDataObject: *((IDataObject **)this - 4), bAutoRelease: 0);
  (*(void (__thiscall **)(COleDropTarget::XDropTarget *, CWnd *))(*((_DWORD *)this - 13) + 100))(a1: this - 13, a2: v1);
  _AfxRelease(lplpUnknown: (IUnknown **)this - 4);
  COleDataObject::Release(this: &dataObject);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10421B36
// Name: public: virtual long COleDropTarget::XDropTarget::Drop(struct IDataObject __near *,unsigned long,struct _POINTL,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall COleDropTarget::XDropTarget::Drop(
        COleDropTarget::XDropTarget *this,
        IDataObject *lpDataObject,
        unsigned int dwKeyState,
        CPoint pt,
        unsigned int *pdwEffect)
{
  COleDropTarget::XDropTarget *v5; // esi
  CWnd *v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // edi
  int v9; // edx
  int v10; // eax
  COleDropTarget::XDropTarget_vtbl *v11; // eax
  HWND__ *v13; // [esp-4h] [ebp-48h]
  COleDataObject dataObject; // [esp+10h] [ebp-34h] BYREF
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+20h] [ebp-24h] BYREF
  CPoint point; // [esp+28h] [ebp-1Ch] BYREF
  int v17; // [esp+40h] [ebp-4h]

  v5 = this - 13;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 6));
  v17 = 0;
  if ( lpDataObject != nullptr && pdwEffect != nullptr )
  {
    v13 = (HWND__ *)v5[8].__vftable;
    LOBYTE(v17) = 1;
    v5[10].__vftable = (COleDropTarget::XDropTarget_vtbl *)0xFFFF;
    v6 = CWnd::FromHandle(hWnd: v13);
    COleDataObject::COleDataObject(this: &dataObject);
    LOBYTE(v17) = 2;
    COleDataObject::Attach(this: &dataObject, lpDataObject, bAutoRelease: 0);
    point = pt;
    ScreenToClient(hWnd: v6->m_hWnd, lpPoint: &point);
    v7 = ((int (__thiscall *)(COleDropTarget::XDropTarget *, CWnd *, COleDataObject *, unsigned int))v5->__vftable[3].AddRef)(
           a1: v5,
           a2: v6,
           a3: &dataObject,
           a4: dwKeyState);
    v8 = _AfxFilterDropEffect(dropEffect: v7, dwEffects: *pdwEffect);
    v10 = ((int (__thiscall *)(COleDropTarget::XDropTarget *, CWnd *, COleDataObject *, unsigned int, int, int, int))v5->__vftable[3].DragEnter)(
            a1: v5,
            a2: v6,
            a3: &dataObject,
            a4: v8,
            a5: v9,
            a6: point.x,
            a7: point.y);
    if ( v10 == -1 )
    {
      v11 = v5->__vftable;
      if ( v8 != 0 )
      {
        if ( ((int (__thiscall *)(COleDropTarget::XDropTarget *, CWnd *, COleDataObject *, unsigned int, int, int))v11[3].Release)(
               a1: v5,
               a2: v6,
               a3: &dataObject,
               a4: v8,
               a5: point.x,
               a6: point.y) == 0 )
          v8 = 0;
      }
      else
      {
        ((void (__thiscall *)(COleDropTarget::XDropTarget *, CWnd *))v11[3].DragOver)(a1: v5, a2: v6);
      }
    }
    else
    {
      v8 = v10;
    }
    _AfxRelease(lplpUnknown: (IUnknown **)&v5[9]);
    *pdwEffect = v8;
    LOBYTE(v17) = 1;
    COleDataObject::Release(this: &dataObject);
    v17 = -1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    return 0;
  }
  else
  {
    v17 = -1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    return -2147024809;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10339075
// Name: public: virtual void CCmdUI::SetText(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCmdUI::SetText(CCmdUI *this, const char *lpszText)
{
  CMenu *m_pMenu; // eax
  UINT MenuState; // eax
  UINT m_nIndex; // ecx
  unsigned int v6; // eax
  CWnd *m_pOther; // esi

  if ( lpszText == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  m_pMenu = this->m_pMenu;
  if ( m_pMenu != nullptr )
  {
    if ( this->m_pSubMenu == nullptr )
    {
      MenuState = GetMenuState(hMenu: m_pMenu->m_hMenu, uId: this->m_nIndex, uFlags: 0x400u);
      m_nIndex = this->m_nIndex;
      v6 = MenuState & 0xFFFFF6FB;
      if ( m_nIndex >= this->m_nIndexMax )
        goto LABEL_2;
      ModifyMenuA(
        hMnu: this->m_pMenu->m_hMenu,
        uPosition: m_nIndex,
        uFlags: v6 | 0x400,
        uIDNewItem: this->m_nID,
        lpNewItem: lpszText);
    }
  }
  else
  {
    m_pOther = this->m_pOther;
    if ( m_pOther == nullptr )
      goto LABEL_2;
    AfxSetWindowText(hWndCtrl: m_pOther->m_hWnd, lpszNew: lpszText);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103390E6
// Name: void _AfxLoadDotBitmap(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxLoadDotBitmap()
{
  unsigned int v0; // eax
  int v1; // ecx
  unsigned int v2; // eax
  int v3; // ebx
  int v4; // esi
  int v5; // edi
  unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // edx
  int v8; // esi
  __int16 v9; // bx
  int i; // [esp+Ch] [ebp-90h]
  int size; // [esp+10h] [ebp-8Ch]
  int size_4; // [esp+14h] [ebp-88h]
  unsigned __int8 rgbBitmap[128]; // [esp+18h] [ebp-84h] BYREF

  v0 = GetMenuCheckMarkDimensions();
  v1 = (__int16)v0;
  v2 = HIWORD(v0);
  v3 = (__int16)v2;
  size = v1;
  size_4 = (__int16)v2;
  if ( v1 <= 4 || (__int16)v2 <= 5 )
    AfxThrowInvalidArgException();
  if ( v1 > 32 )
  {
    v1 = 32;
    size = 32;
  }
  v4 = (v1 + 15) >> 4;
  v5 = 16 * v4 + (v1 - 4) / 2 - v1;
  if ( v5 > 12 )
    LOBYTE(v5) = 12;
  if ( (__int16)v2 > 32 )
  {
    v3 = 32;
    size_4 = 32;
  }
  memset(dst: rgbBitmap, value: 0xFFu, count: sizeof(rgbBitmap));
  v6 = &rgbBitmap[2 * v4 * ((v3 - 6) >> 1)];
  v7 = _afxDot;
  v8 = 2 * v4;
  for ( i = 5; i != 0; --i )
  {
    v9 = *v7++ << v5;
    *v6 = (unsigned __int16)~v9 >> 8;
    v6[1] = ~(_BYTE)v9;
    v6 += v8;
  }
  afxData.hbmMenuDot = CreateBitmap(nWidth: size, nHeight: size_4, nPlanes: 1u, nBitCount: 1u, lpBits: rgbBitmap);
  if ( afxData.hbmMenuDot == nullptr )
    afxData.hbmMenuDot = LoadBitmapW(hInstance: nullptr, lpBitmapName: (LPCWSTR)0x7FE3);
}

//------------------------------------------------------------------------------
// Address: 0x10339207
// Name: public: virtual void CCmdUI::SetRadio(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCmdUI::SetRadio(CCmdUI *this, int bOn)
{
  this->SetCheck(this, a2: bOn != 0);
  if ( this->m_pMenu != nullptr && this->m_pSubMenu == nullptr )
  {
    if ( this->m_nIndex >= this->m_nIndexMax )
      AfxThrowInvalidArgException();
    if ( afxData.hbmMenuDot != nullptr || (_AfxLoadDotBitmap(), afxData.hbmMenuDot != nullptr) )
      SetMenuItemBitmaps(
        hMenu: this->m_pMenu->m_hMenu,
        uPosition: this->m_nIndex,
        uFlags: 0x400u,
        hBitmapUnchecked: nullptr,
        hBitmapChecked: afxData.hbmMenuDot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103502FC
// Name: public: int CStatusBar::SetIndicators(unsigned int const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::SetIndicators(CStatusBar *this, const unsigned int *lpIDArray, int nIDCount)
{
  CStatusBar *v3; // edi
  int result; // eax
  void *v5; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pData; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v7; // esi
  unsigned int v8; // eax
  CSize *TextExtent; // eax
  CStatusBar *v10; // ecx
  CClientDC dcScreen; // [esp+10h] [ebp-38h] BYREF
  CSize v12; // [esp+24h] [ebp-24h] BYREF
  CStatusBar *v13; // [esp+2Ch] [ebp-1Ch]
  int bResult; // [esp+30h] [ebp-18h]
  void *hOldFont; // [esp+34h] [ebp-14h]
  int i; // [esp+38h] [ebp-10h]
  int v17; // [esp+44h] [ebp-4h]

  v3 = this;
  v13 = this;
  result = CStatusBar::AllocElements(this, nElements: nIDCount, cbElement: 20);
  if ( result != 0 )
  {
    bResult = 1;
    if ( lpIDArray != nullptr )
    {
      v5 = (void *)SendMessageA(hWnd: v3->m_hWnd, Msg: 0x31u, wParam: 0, lParam: 0);
      CClientDC::CClientDC(this: &dcScreen, pWnd: nullptr);
      v17 = 0;
      hOldFont = nullptr;
      if ( v5 != nullptr )
        hOldFont = SelectObject(hdc: dcScreen.m_hDC, h: v5);
      m_pData = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)v3->m_pData;
      i = 0;
      if ( nIDCount > 0 )
      {
        v7 = m_pData + 4;
        do
        {
          v8 = *lpIDArray++;
          v7[-1].m_pszData = (char *)((int)v7[-1].m_pszData | 1);
          m_pData->m_pszData = (char *)v8;
          if ( v8 != 0 )
          {
            if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(this: v7, nID: v8) == nullptr
              || (TextExtent = CDC::GetTextExtent(this: &dcScreen, result: &v12, str: v7),
                  v10 = v13,
                  v7[-3].m_pszData = (char *)TextExtent->cx,
                  CStatusBar::SetPaneText(this: v10, nIndex: i, lpszNewText: v7->m_pszData, bUpdate: 0) == 0) )
            {
              bResult = 0;
              break;
            }
          }
          else
          {
            v7[-3].m_pszData = (char *)(GetSystemMetrics(nIndex: 0) / 4);
            if ( i == 0 )
              v7[-2].m_pszData = (char *)((int)v7[-2].m_pszData | 0x8000100);
          }
          m_pData += 5;
          v7 += 5;
          ++i;
        }
        while ( i < nIDCount );
      }
      if ( hOldFont != nullptr )
        SelectObject(hdc: dcScreen.m_hDC, h: hOldFont);
      v17 = -1;
      CClientDC::~CClientDC(this: &dcScreen);
      v3 = v13;
    }
    CStatusBar::UpdateAllPanes(this: v3, bUpdateRects: 1, bUpdateText: 1);
    return bResult;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10350424
// Name: protected: virtual struct AFX_MSGMAP const __near * CStatusBar::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CStatusBar::GetMessageMap(CStatusBar *this)
{
  return (const AFX_MSGMAP *)&off_10676F3C;
}

//------------------------------------------------------------------------------
// Address: 0x1035042A
// Name: unsigned int AfxPropPageCallback(struct HWND__ __near *,unsigned int,struct _PROPSHEETPAGEA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall AfxPropPageCallback(HWND__ *__formal, unsigned int message, _PROPSHEETPAGEA *pPropPage)
{
  if ( message == 1 )
  {
    AfxUnhookWindowCreate();
  }
  else if ( message == 2 )
  {
    AfxHookWindowCreate(pWnd: (CWnd *)pPropPage->lParam);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10399202
// Name: public: virtual int CVSListBox::EditItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CVSListBox::EditItem(CVSListBox *this, int iIndex)
{
  CListCtrl *m_pWndList; // ecx
  CEdit *v4; // eax
  CListCtrl *v5; // ecx
  CList<CMFCButton *,CMFCButton *>::CNode *m_pNodeTail; // esi
  CWnd *data; // ecx
  CEdit *pEdit; // [esp+10h] [ebp-28h]
  CRect rectEdit; // [esp+14h] [ebp-24h] BYREF
  CRect rectItem; // [esp+24h] [ebp-14h] BYREF

  this->m_wndEdit.m_pParentList = nullptr;
  this->m_wndEdit.m_bLocked = 0;
  if ( this == nullptr )
    return 0;
  if ( this->m_hWnd == nullptr )
    return 0;
  m_pWndList = this->m_pWndList;
  if ( m_pWndList == nullptr )
    return 0;
  CWnd::SetFocus(this: m_pWndList);
  v4 = CListCtrl::EditLabel(this: this->m_pWndList, nItem: iIndex);
  pEdit = v4;
  if ( v4 == nullptr )
    return 0;
  CWnd::SubclassWindow(this: &this->m_wndEdit, hWnd: v4->m_hWnd);
  CMFCEditBrowseCtrl::EnableBrowseButton(this: &this->m_wndEdit, bEnable: this->m_bBrowseButton, szLabel: "...");
  v5 = this->m_pWndList;
  memset(&rectItem, 0, sizeof(rectItem));
  CListCtrl::GetItemRect(this: v5, nItem: iIndex, lpRect: &rectItem, nCode: 2u);
  memset(&rectEdit, 0, sizeof(rectEdit));
  GetClientRect(hWnd: pEdit->m_hWnd, lpRect: &rectEdit);
  CWnd::SetWindowPos(
    this: pEdit,
    pWndInsertAfter: nullptr,
    x: -1,
    y: -1,
    cx: rectItem.right - rectItem.left,
    cy: rectEdit.bottom - rectEdit.top,
    nFlags: 0x16u);
  this->m_wndEdit.m_pParentList = this;
  this->m_wndEdit.m_bLocked = 1;
  m_pNodeTail = this->m_lstButtons.m_pNodeTail;
  while ( m_pNodeTail != nullptr )
  {
    data = m_pNodeTail->data;
    m_pNodeTail = m_pNodeTail->pPrev;
    if ( data == nullptr )
      AfxThrowInvalidArgException();
    CWnd::EnableWindow(this: data, bEnable: 0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1039932D
// Name: protected: virtual void CVSListBox::OnSizeList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBox::OnSizeList(CVSListBox *this)
{
  HWND__ *m_hWnd; // ecx
  __int16 v3; // si
  __int16 v4; // si
  __int16 SystemMetrics; // ax
  CRect rectClient; // [esp+4h] [ebp-14h] BYREF

  if ( this != nullptr )
  {
    m_hWnd = this->m_hWnd;
    if ( m_hWnd != nullptr && this->m_pWndList != nullptr )
    {
      memset(&rectClient, 0, sizeof(rectClient));
      GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
      v3 = LOWORD(rectClient.right) - LOWORD(rectClient.left);
      v4 = v3 - 2 * GetSystemMetrics(nIndex: 45);
      SystemMetrics = GetSystemMetrics(nIndex: 2);
      SendMessageA(
        hWnd: this->m_pWndList->m_hWnd,
        Msg: 0x101Eu,
        wParam: 0,
        lParam: (unsigned __int16)(v4 - SystemMetrics));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103993B3
// Name: protected: virtual void CVSListBox::SetItemText(int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBox::SetItemText(
        CVSListBox *this,
        int iIndex,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strText)
{
  CListCtrl *m_pWndList; // ecx

  if ( this != nullptr && this->m_hWnd != nullptr )
  {
    m_pWndList = this->m_pWndList;
    if ( m_pWndList != nullptr )
      CListCtrl::SetItemText(this: m_pWndList, nItem: iIndex, nSubItem: 0, lpszText: strText->m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103993DF
// Name: public: virtual int CVSListBox::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CVSListBox::PreTranslateMessage(CVSListBox *this, tagMSG *pMsg)
{
  tagMSG *v2; // edi
  CListCtrl *m_pWndList; // ecx
  CListCtrl *v5; // eax
  CWnd *m_hWnd; // ebx
  HWND Focus; // eax
  CWnd *v8; // eax
  signed int v9; // eax
  HWND v10; // eax
  BOOL v12; // edx
  HWND__ *v13; // [esp-4h] [ebp-20h]
  tagPOINT Point; // [esp+Ch] [ebp-10h] BYREF
  int iItem; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h]

  v2 = pMsg;
  if ( pMsg->message != 513 )
    goto LABEL_16;
  m_pWndList = this->m_pWndList;
  if ( m_pWndList == nullptr || CListCtrl::GetEditControl(this: m_pWndList) != nullptr )
    goto LABEL_16;
  v5 = this->m_pWndList;
  if ( v5 != nullptr )
    m_hWnd = (CWnd *)v5->m_hWnd;
  else
    m_hWnd = nullptr;
  Focus = GetFocus();
  v8 = CWnd::FromHandle(hWnd: Focus);
  if ( v8 != nullptr )
    v8 = (CWnd *)v8->m_hWnd;
  if ( m_hWnd == v8 )
  {
    this->m_ptClick.x = -1;
    this->m_ptClick.y = -1;
    iItem = v2->pt.x;
    y = v2->pt.y;
    ScreenToClient(hWnd: this->m_pWndList->m_hWnd, lpPoint: (LPPOINT)&iItem);
    v9 = CListCtrl::HitTest(this: this->m_pWndList, pt: (CPoint)__PAIR64__(y, iItem), pFlags: (unsigned int *)&pMsg);
    if ( v9 >= 0
      && ((unsigned __int8)pMsg & 4) != 0
      && (SendMessageA(hWnd: this->m_pWndList->m_hWnd, Msg: 0x102Cu, wParam: v9, lParam: 3) & 3) == 3 )
    {
      v13 = this->m_hWnd;
      this->m_ptClick.x = iItem;
      this->m_ptClick.y = y;
      v10 = SetCapture(hWnd: v13);
      CWnd::FromHandle(hWnd: v10);
      return 1;
    }
  }
  else
  {
LABEL_16:
    if ( v2->message == 514 && CPoint::operator!=(this: &this->m_ptClick, point: (tagPOINT)-1LL) )
    {
      ReleaseCapture();
      Point = v2->pt;
      ScreenToClient(hWnd: this->m_pWndList->m_hWnd, lpPoint: &Point);
      y = CListCtrl::HitTest(this: this->m_pWndList, pt: (CPoint)Point, pFlags: nullptr);
      v12 = false;
      if ( y >= 0 )
      {
        pMsg = (tagMSG *)abs(lnumber: Point.x - this->m_ptClick.x);
        if ( (int)pMsg < GetSystemMetrics(nIndex: 68) )
        {
          pMsg = (tagMSG *)abs(lnumber: Point.y - this->m_ptClick.y);
          if ( (int)pMsg < GetSystemMetrics(nIndex: 69) )
            v12 = true;
        }
      }
      this->m_ptClick.x = -1;
      this->m_ptClick.y = -1;
      if ( v12 )
        this->EditItem(this, a2: y);
      return 1;
    }
  }
  return CWnd::PreTranslateMessage(this, pMsg: v2);
}

//------------------------------------------------------------------------------
// Address: 0x103995CA
// Name: public: class CPropertyPage __near * CList<class CPropertyPage __near *,class CPropertyPage __near *>::RemoveHead(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPropertyGridProperty *__thiscall CList<CPropertyPage *,CPropertyPage *>::RemoveHead(
        CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *> *this)
{
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // edx
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *pNext; // eax
  CMFCPropertyGridProperty *data; // esi

  m_pNodeHead = this->m_pNodeHead;
  if ( m_pNodeHead == nullptr )
    AfxThrowInvalidArgException();
  pNext = m_pNodeHead->pNext;
  data = m_pNodeHead->data;
  this->m_pNodeHead = m_pNodeHead->pNext;
  if ( pNext != nullptr )
    pNext->pPrev = nullptr;
  else
    this->m_pNodeTail = nullptr;
  CList<unsigned int,unsigned int>::FreeNode(
    (CList<unsigned int,unsigned int> *)this,
    pNode: (CList<unsigned int,unsigned int>::CNode *)m_pNodeHead);
  return data;
}

//------------------------------------------------------------------------------
// Address: 0x103995F7
// Name: public: virtual CList<class CMFCButton __near *,class CMFCButton __near *>::~CList<class CMFCButton __near *,class CMFCButton __near *>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<CMFCButton *,CMFCButton *>::~CList<CMFCButton *,CMFCButton *>(
        CList<CMFCButton *,CMFCButton *> *this)
{
  this->__vftable = (CList<CMFCButton *,CMFCButton *>_vtbl *)&CList<CMFCButton *,CMFCButton *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll((CList<HWND__ *,HWND__ * &> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10399602
// Name: public: virtual CList<unsigned long,unsigned long>::~CList<unsigned long,unsigned long>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<unsigned long,unsigned long>::~CList<unsigned long,unsigned long>(
        CList<unsigned long,unsigned long> *this)
{
  this->__vftable = (CList<unsigned long,unsigned long>_vtbl *)&CList<unsigned long,unsigned long>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll((CList<HWND__ *,HWND__ * &> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1039A5A8
// Name: public: CMFCShellTreeCtrl::CMFCShellTreeCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCShellTreeCtrl *__thiscall CMFCShellTreeCtrl::CMFCShellTreeCtrl(CMFCShellTreeCtrl *this)
{
  CWnd::CWnd(this);
  this->m_hwndRelatedList = nullptr;
  this->m_bNoNotify = 0;
  this->__vftable = (CMFCShellTreeCtrl_vtbl *)&CMFCShellTreeCtrl::`vftable';
  this->m_bContextMenu = 1;
  this->m_dwFlags = 32;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1039A5FC
// Name: protected: void CMFCShellTreeCtrl::OnRButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShellTreeCtrl::OnRButtonDown(CMFCShellTreeCtrl *this, unsigned int __formal, CPoint point)
{
  struct _TREEITEM *v4; // eax
  unsigned int nFlags; // [esp+4h] [ebp-4h] BYREF

  CWnd::SetFocus(this);
  nFlags = 0;
  v4 = CTreeCtrl::HitTest(this, pt: point.tagPOINT, pFlags: &nFlags);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Bu, wParam: 9u, lParam: (LPARAM)v4);
}

//------------------------------------------------------------------------------
// Address: 0x1039A635
// Name: public: virtual int CMFCShellTreeCtrl::OnChildNotify(unsigned int,unsigned int,long,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCShellTreeCtrl::OnChildNotify(
        CMFCShellTreeCtrl *this,
        unsigned int message,
        unsigned int wParam,
        int lParam,
        int *pLResult)
{
  CMFCShellListCtrl *RelatedList; // edi
  struct _TREEITEM *v7; // eax
  int ItemData; // eax
  CMFCShellListCtrl_vtbl *v9; // edx

  if ( message != 78 || this->m_bNoNotify != 0 )
    return CWnd::OnChildNotify(this, uMsg: message, wParam, lParam, pResult: pLResult);
  if ( lParam == 0 )
    AfxThrowInvalidArgException();
  if ( *(_DWORD *)(lParam + 8) != -402 )
    return CWnd::OnChildNotify(this, uMsg: message, wParam, lParam, pResult: pLResult);
  RelatedList = CMFCShellTreeCtrl::GetRelatedList(this);
  if ( RelatedList == nullptr || SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 9u, lParam: 0) == 0 )
    return CWnd::OnChildNotify(this, uMsg: message, wParam, lParam, pResult: pLResult);
  v7 = (struct _TREEITEM *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 9u, lParam: 0);
  ItemData = CTreeCtrl::GetItemData(this, hItem: v7);
  v9 = RelatedList->__vftable;
  RelatedList->m_bNoNotify = 1;
  v9->DisplayFolder(this: RelatedList, a2: (_AFX_SHELLITEMINFO *)ItemData);
  RelatedList->m_bNoNotify = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1039A6D2
// Name: public: virtual CList<struct _ITEMIDLIST __near *,struct _ITEMIDLIST __near *>::~CList<struct _ITEMIDLIST __near *,struct _ITEMIDLIST __near *>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<_ITEMIDLIST *,_ITEMIDLIST *>::~CList<_ITEMIDLIST *,_ITEMIDLIST *>(
        CList<_ITEMIDLIST *,_ITEMIDLIST *> *this)
{
  this->__vftable = (CList<_ITEMIDLIST *,_ITEMIDLIST *>_vtbl *)&CList<_ITEMIDLIST *,_ITEMIDLIST *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll((CList<HWND__ *,HWND__ * &> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1039A704
// Name: protected: struct CList<unsigned int,unsigned int>::CNode __near * CList<unsigned int,unsigned int>::NewNode(struct CList<unsigned int,unsigned int>::CNode __near *,struct CList<unsigned int,unsigned int>::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<HWND__ *,HWND__ * &>::CNode *__thiscall CList<unsigned int,unsigned int>::NewNode(
        CList<HWND__ *,HWND__ * &> *this,
        CList<HWND__ *,HWND__ * &>::CNode *pPrev,
        CList<HWND__ *,HWND__ * &>::CNode *pNext)
{
  CPlex *v4; // eax
  int v5; // ecx
  CList<HWND__ *,HWND__ * &>::CNode *i; // eax
  CList<HWND__ *,HWND__ * &>::CNode *result; // eax

  if ( this->m_pNodeFree == nullptr )
  {
    v4 = CPlex::Create(pHead: &this->m_pBlocks, nMax: this->m_nBlockSize, cbElement: 0xCu);
    v5 = this->m_nBlockSize - 1;
    for ( i = (CList<HWND__ *,HWND__ * &>::CNode *)&v4[3 * this->m_nBlockSize - 2]; v5 >= 0; --v5 )
    {
      i->pNext = this->m_pNodeFree;
      this->m_pNodeFree = i--;
    }
  }
  result = this->m_pNodeFree;
  if ( result == nullptr )
    AfxThrowInvalidArgException();
  this->m_pNodeFree = result->pNext;
  result->pPrev = pPrev;
  result->pNext = pNext;
  ++this->m_nCount;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039A761
// Name: public: struct __POSITION __near * CList<class CMFCPropertyGridProperty __near *,class CMFCPropertyGridProperty __near *>::AddHead(class CMFCPropertyGridProperty __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *__thiscall CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::AddHead(
        CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *> *this,
        CMFCPropertyGridProperty *newElement)
{
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *result; // eax
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // ecx

  result = (CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *)CList<unsigned int,unsigned int>::NewNode(
                                                                                    (CList<HWND__ *,HWND__ * &> *)this,
                                                                                    pPrev: nullptr,
                                                                                    pNext: (CList<HWND__ *,HWND__ * &>::CNode *)this->m_pNodeHead);
  result->data = newElement;
  m_pNodeHead = this->m_pNodeHead;
  if ( m_pNodeHead != nullptr )
    m_pNodeHead->pPrev = result;
  else
    this->m_pNodeTail = result;
  this->m_pNodeHead = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039A790
// Name: public: struct __POSITION __near * CList<class CFrameWnd __near *,class CFrameWnd __near *>::AddTail(class CFrameWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<CFrameWnd *,CFrameWnd *>::CNode *__thiscall CList<CFrameWnd *,CFrameWnd *>::AddTail(
        CList<CFrameWnd *,CFrameWnd *> *this,
        CFrameWnd *newElement)
{
  CList<CFrameWnd *,CFrameWnd *>::CNode *result; // eax
  CList<CFrameWnd *,CFrameWnd *>::CNode *m_pNodeTail; // ecx

  result = (CList<CFrameWnd *,CFrameWnd *>::CNode *)CList<unsigned int,unsigned int>::NewNode(
                                                      (CList<HWND__ *,HWND__ * &> *)this,
                                                      pPrev: (CList<HWND__ *,HWND__ * &>::CNode *)this->m_pNodeTail,
                                                      pNext: nullptr);
  result->data = newElement;
  m_pNodeTail = this->m_pNodeTail;
  if ( m_pNodeTail != nullptr )
    m_pNodeTail->pNext = result;
  else
    this->m_pNodeHead = result;
  this->m_pNodeTail = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039A7BE
// Name: public: int CMFCShellTreeCtrl::SelectPath(struct _ITEMIDLIST const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCShellTreeCtrl::SelectPath(CMFCShellTreeCtrl *this, _ITEMIDLIST *lpidl)
{
  LPARAM v4; // eax
  CMFCPropertyGridProperty *v5; // eax
  int i; // eax
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // eax
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *pNext; // ecx
  const char *data; // eax
  int ItemData; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-328h]
  LPARAM v12; // [esp-4h] [ebp-31Ch]
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *> v13; // [esp+10h] [ebp-308h] BYREF
  int v14; // [esp+2Ch] [ebp-2ECh]
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *v15; // [esp+30h] [ebp-2E8h]
  LPCSTR pszPath; // [esp+34h] [ebp-2E4h]
  int v17; // [esp+38h] [ebp-2E0h]
  CMFCPropertyGridProperty *newElement; // [esp+3Ch] [ebp-2DCh] BYREF
  _ITEMIDLIST *pidl; // [esp+40h] [ebp-2D8h]
  LPARAM lParam; // [esp+44h] [ebp-2D4h]
  SHFILEINFOA psfi; // [esp+48h] [ebp-2D0h] BYREF
  SHFILEINFOA v22; // [esp+1A8h] [ebp-170h] BYREF
  int v23; // [esp+314h] [ebp-4h]

  pidl = lpidl;
  v14 = 0;
  if ( lpidl == nullptr )
    return 0;
  v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 0, lParam: 0);
  m_hWnd = this->m_hWnd;
  lParam = v4;
  SendMessageA(hWnd: m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  if ( CShellManager::GetItemCount(this: afxShellManager, pidl) != 0 )
  {
    v13.__vftable = (CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>_vtbl *)&CList<_ITEMIDLIST *,_ITEMIDLIST *>::`vftable';
    memset(&v13.m_pNodeHead, 0, 20);
    v13.m_nBlockSize = 10;
    v23 = 0;
    v5 = (CMFCPropertyGridProperty *)CShellManager::CopyItem(this: afxShellManager, pidlSource: pidl);
    CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::AddHead(this: &v13, newElement: v5);
    for ( i = CShellManager::GetParentItem(this: afxShellManager, lpidl: pidl, lpidlParent: (_ITEMIDLIST **)&newElement);
          i > 0;
          i = CShellManager::GetParentItem(
                this: afxShellManager,
                lpidl: (const _ITEMIDLIST *)newElement,
                lpidlParent: (_ITEMIDLIST **)&newElement) )
    {
      CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::AddHead(this: &v13, newElement);
    }
    m_pNodeHead = v13.m_pNodeHead;
    if ( v13.m_pNodeHead != nullptr )
    {
      while ( 1 )
      {
        pNext = m_pNodeHead->pNext;
        data = (const char *)m_pNodeHead->data;
        v15 = pNext;
        pszPath = data;
        if ( lParam != 0 )
        {
          if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 4u, lParam) == 0 )
            SendMessageA(hWnd: this->m_hWnd, Msg: 0x1102u, wParam: 2u, lParam);
          v17 = 0;
          pidl = (_ITEMIDLIST *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 4u, lParam);
          do
          {
            if ( pidl == nullptr )
              break;
            ItemData = CTreeCtrl::GetItemData(this, hItem: (struct _TREEITEM *)pidl);
            if ( ItemData != 0
              && SHGetFileInfoA(
                   pszPath: *(LPCSTR *)(ItemData + 4),
                   dwFileAttributes: 0,
                   &psfi,
                   cbFileInfo: 0x160u,
                   uFlags: 0x208u) != 0
              && SHGetFileInfoA(pszPath, dwFileAttributes: 0, psfi: &v22, cbFileInfo: 0x160u, uFlags: 0x208u) != 0
              && lstrcmpA(lpString1: psfi.szDisplayName, lpString2: v22.szDisplayName) == 0 )
            {
              v17 = 1;
              lParam = (LPARAM)pidl;
            }
            pidl = (_ITEMIDLIST *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 1u, lParam: (LPARAM)pidl);
          }
          while ( v17 == 0 );
          if ( v17 == 0 )
            lParam = 0;
        }
        CShellManager::FreeItem(this: afxShellManager, pidl: (_ITEMIDLIST *)pszPath);
        if ( v15 == nullptr )
          break;
        m_pNodeHead = v15;
      }
    }
    v23 = -1;
    v13.__vftable = (CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>_vtbl *)&CList<_ITEMIDLIST *,_ITEMIDLIST *>::`vftable';
    CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&v13);
  }
  if ( lParam != 0 )
  {
    v12 = lParam;
    this->m_bNoNotify = 1;
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Bu, wParam: 9u, lParam: v12);
    if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 4u, lParam) == 0 )
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x1102u, wParam: 2u, lParam);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x1114u, wParam: 0, lParam);
    this->m_bNoNotify = 0;
    v14 = 1;
  }
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x1039AAB3
// Name: protected: int CMFCShellTreeCtrl::GetRootItems(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCShellTreeCtrl::GetRootItems(CMFCShellTreeCtrl *this)
{
  _AFX_SHELLITEMINFO *v3; // esi
  CMFCShellTreeCtrl_vtbl *v4; // eax
  LPARAM v5; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-A4h]
  int v7; // [esp-4h] [ebp-98h]
  tagTVINSERTSTRUCTA tvInsert; // [esp+10h] [ebp-84h] BYREF
  tagTVITEMA tvItem; // [esp+54h] [ebp-40h]
  IShellFolder *pDesktop; // [esp+7Ch] [ebp-18h] BYREF
  _ITEMIDLIST *pidl; // [esp+80h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strItem; // [esp+84h] [ebp-10h] BYREF
  int v13; // [esp+90h] [ebp-4h]

  if ( afxShellManager == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  if ( SHGetSpecialFolderLocation(hwnd: nullptr, csidl: 0, ppidl: &pidl) < 0 || SHGetDesktopFolder(ppshf: &pDesktop) < 0 )
    return 0;
  tvItem.mask = 103;
  v3 = (_AFX_SHELLITEMINFO *)GlobalAlloc(uFlags: 0x40u, dwBytes: 0xCu);
  if ( v3 == nullptr )
    goto LABEL_2;
  v3->pidlRel = pidl;
  v3->pidlFQ = CShellManager::CopyItem(this: afxShellManager, pidlSource: pidl);
  v3->pParentFolder = nullptr;
  v4 = this->__vftable;
  tvItem.lParam = (int)v3;
  v4->OnGetItemText(this, result: &strItem, a3: v3);
  v7 = *((_DWORD *)strItem.m_pszData - 3);
  v13 = 0;
  tvItem.pszText = ATL::CSimpleStringT<char,0>::PrepareWrite(this: &strItem, nLength: v7);
  tvItem.iImage = this->OnGetItemIcon(this, a2: v3, a3: 0);
  tvItem.iSelectedImage = this->OnGetItemIcon(this, a2: v3, a3: 1);
  tvItem.cChildren = 1;
  m_hWnd = this->m_hWnd;
  tvInsert.item = tvItem;
  tvInsert.hInsertAfter = (struct _TREEITEM *)-65534;
  tvInsert.hParent = (struct _TREEITEM *)-65536;
  v5 = SendMessageA(hWnd: m_hWnd, Msg: 0x1100u, wParam: 0, lParam: (LPARAM)&tvInsert);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x1102u, wParam: 2u, lParam: v5);
  pDesktop->Release(this: pDesktop);
  ATL::CStringData::Release(this: (ATL::CStringData *)strItem.m_pszData - 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1039ABDC
// Name: protected: virtual long CMFCShellTreeCtrl::EnumObjects(struct _TREEITEM __near *,struct IShellFolder __near *,struct _ITEMIDLIST __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCShellTreeCtrl::EnumObjects(
        CMFCShellTreeCtrl *this,
        struct _TREEITEM *hParentItem,
        IShellFolder *pParentFolder,
        _ITEMIDLIST *pidlParent)
{
  IShellFolder *v5; // edi
  IShellFolder_vtbl *v6; // eax
  HRESULT result; // eax
  IShellFolder_vtbl *v8; // eax
  _AFX_SHELLITEMINFO *v9; // esi
  CMFCShellTreeCtrl_vtbl *v10; // eax
  IShellFolder_vtbl *v11; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-ACh]
  int v13; // [esp-4h] [ebp-A0h]
  tagTVINSERTSTRUCTA tvInsert; // [esp+10h] [ebp-8Ch] BYREF
  tagTVITEMA tvItem; // [esp+54h] [ebp-48h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strItem; // [esp+7Ch] [ebp-20h] BYREF
  unsigned int dwAttribs; // [esp+80h] [ebp-1Ch] BYREF
  IEnumIDList *pEnum; // [esp+84h] [ebp-18h] BYREF
  _ITEMIDLIST *pidlTemp; // [esp+88h] [ebp-14h] BYREF
  unsigned int dwFetched[3]; // [esp+8Ch] [ebp-10h] BYREF
  int v21; // [esp+98h] [ebp-4h]

  v5 = pParentFolder;
  v6 = pParentFolder->__vftable;
  pEnum = nullptr;
  result = v6->EnumObjects(this: pParentFolder, a2: nullptr, a3: this->m_dwFlags, a4: &pEnum);
  if ( result >= 0 && pEnum != nullptr )
  {
    dwFetched[0] = 1;
    if ( pEnum->Next(this: pEnum, a2: 1u, a3: &pidlTemp, a4: dwFetched) >= 0 )
    {
      while ( dwFetched[0] != 0 )
      {
        memset(dst: (unsigned __int8 *)&tvItem, value: 0, count: sizeof(tvItem));
        v8 = v5->__vftable;
        tvItem.mask = 103;
        v8->AddRef(this: v5);
        v9 = (_AFX_SHELLITEMINFO *)GlobalAlloc(uFlags: 0x40u, dwBytes: 0xCu);
        if ( v9 == nullptr )
          AfxThrowInvalidArgException();
        v9->pidlRel = pidlTemp;
        v9->pidlFQ = CShellManager::ConcatenateItem(this: afxShellManager, pidl1: pidlParent, pidl2: pidlTemp);
        v9->pParentFolder = v5;
        v10 = this->__vftable;
        tvItem.lParam = (int)v9;
        v10->OnGetItemText(this, result: &strItem, a3: v9);
        v13 = *((_DWORD *)strItem.m_pszData - 3);
        v21 = 0;
        tvItem.pszText = ATL::CSimpleStringT<char,0>::PrepareWrite(this: &strItem, nLength: v13);
        tvItem.iImage = this->OnGetItemIcon(this, a2: v9, a3: 0);
        tvItem.iSelectedImage = this->OnGetItemIcon(this, a2: v9, a3: 1);
        v11 = v5->__vftable;
        dwAttribs = -1341145072;
        v11->GetAttributesOf(this: v5, a2: 1u, a3: (const _ITEMIDLIST **)&pidlTemp, a4: &dwAttribs);
        tvItem.cChildren = dwAttribs & 0x90000000;
        if ( (dwAttribs & 0x20000) != 0 )
        {
          tvItem.mask |= 8u;
          tvItem.stateMask |= 0xF00u;
          tvItem.state |= 0x100u;
        }
        tvInsert.item = tvItem;
        tvInsert.hParent = hParentItem;
        m_hWnd = this->m_hWnd;
        tvInsert.hInsertAfter = (struct _TREEITEM *)-65534;
        SendMessageA(hWnd: m_hWnd, Msg: 0x1100u, wParam: 0, lParam: (LPARAM)&tvInsert);
        dwFetched[0] = 0;
        v21 = -1;
        ATL::CStringData::Release(this: (ATL::CStringData *)strItem.m_pszData - 1);
        if ( pEnum->Next(this: pEnum, a2: 1u, a3: &pidlTemp, a4: dwFetched) < 0 )
          break;
        v5 = pParentFolder;
      }
    }
    pEnum->Release(this: pEnum);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039AD8F
// Name: public: void CMFCShellTreeCtrl::Refresh(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShellTreeCtrl::Refresh(CMFCShellTreeCtrl *this)
{
  CMFCShellTreeCtrl *m_hWnd; // esi

  m_hWnd = this;
  CTreeCtrl::DeleteAllItems(this);
  CMFCShellTreeCtrl::GetRootItems(this: m_hWnd);
  if ( m_hWnd != nullptr )
    m_hWnd = (CMFCShellTreeCtrl *)m_hWnd->m_hWnd;
  SendMessageA(hWnd: (HWND)m_hWnd, Msg: 0x1121u, wParam: 0x64u, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1039ADB9
// Name: protected: void CMFCShellTreeCtrl::InitTree(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShellTreeCtrl::InitTree(CMFCShellTreeCtrl *this)
{
  struct _IMAGELIST *v2; // eax
  CImageList *v3; // eax
  _SHFILEINFOA sfi; // [esp+4h] [ebp-26Ch] BYREF
  CHAR szWinDir[264]; // [esp+164h] [ebp-10Ch] BYREF

  if ( GetWindowsDirectoryA(lpBuffer: szWinDir, uSize: 0x104u) != 0 )
  {
    v2 = (struct _IMAGELIST *)SHGetFileInfoA(
                                pszPath: szWinDir,
                                dwFileAttributes: 0,
                                psfi: &sfi,
                                cbFileInfo: 0x160u,
                                uFlags: 0x4001u);
    v3 = CImageList::FromHandle(h: v2);
    CTreeCtrl::SetImageList(this, pImageList: v3, nImageList: 0);
  }
  CMFCShellTreeCtrl::Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039AE2B
// Name: protected: long CMFCShellTreeCtrl::OnInitControl(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCShellTreeCtrl::OnInitControl(CMFCShellTreeCtrl *this, unsigned int wParam, const char *lParam)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v5; // eax
  CTagManager tagManager; // [esp+10h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDst; // [esp+18h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strEnableShellContextMenu; // [esp+1Ch] [ebp-10h] BYREF
  int v10; // [esp+28h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDst, pStringMgr: StringManager);
  v10 = 0;
  CMFCControlContainer::UTF8ToString(lpSrc: lParam, &strDst, nLength: wParam);
  CTagManager::CTagManager(this: &tagManager, lpszBuffer: strDst.m_pszData);
  LOBYTE(v10) = 1;
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strEnableShellContextMenu, pStringMgr: v5);
  LOBYTE(v10) = 2;
  if ( CTagManager::ExcludeTag(
         this: &tagManager,
         lpszTag: "MFCShellTreeCtrl_EnableShellContextMenu",
         strTag: &strEnableShellContextMenu,
         bIsCharsList: 0) != 0
    && *((_DWORD *)strEnableShellContextMenu.m_pszData - 3) != 0 )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: &strEnableShellContextMenu);
    this->m_bContextMenu = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
                             this: &strEnableShellContextMenu,
                             psz: "TRUE") == 0;
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)strEnableShellContextMenu.m_pszData - 1);
  LOBYTE(v10) = 0;
  CTagManager::~CTagManager(this: &tagManager);
  ATL::CStringData::Release(this: (ATL::CStringData *)strDst.m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039AEE4
// Name: protected: int CMFCShellTreeCtrl::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCShellTreeCtrl::OnCreate(CMFCShellTreeCtrl *this, tagCREATESTRUCTA *lpCreateStruct)
{
  if ( CWnd::Default(this) == -1 || afxShellManager == nullptr )
    return -1;
  CMFCShellTreeCtrl::InitTree(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039AF10
// Name: protected: int CMFCShellTreeCtrl::GetChildItems(struct _TREEITEM __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCShellTreeCtrl::GetChildItems(CMFCShellTreeCtrl *this, struct _TREEITEM *hParentItem)
{
  AFX_MODULE_STATE *ModuleState; // eax
  int v5; // ecx
  HRESULT v6; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-6Ch]
  HWND__ *v8; // [esp-10h] [ebp-6Ch]
  tagTVITEMA tvItem; // [esp+10h] [ebp-4Ch] BYREF
  tagTVSORTCB tvSort; // [esp+38h] [ebp-24h] BYREF
  _AFX_SHELLITEMINFO *pItem; // [esp+44h] [ebp-18h]
  int v12; // [esp+48h] [ebp-14h]
  IShellFolder *pParentFolder; // [esp+4Ch] [ebp-10h] BYREF
  int v14; // [esp+58h] [ebp-4h]

  ModuleState = AfxGetModuleState();
  CCmdTarget::BeginWaitCursor(this: ModuleState->m_pCurrentWinApp);
  v14 = 0;
  memset(dst: (unsigned __int8 *)&tvItem, value: 0, count: sizeof(tvItem));
  tvItem.hItem = hParentItem;
  m_hWnd = this->m_hWnd;
  tvItem.mask = 4;
  if ( SendMessageA(hWnd: m_hWnd, Msg: 0x110Cu, wParam: 0, lParam: (LPARAM)&tvItem) == 0 )
    goto LABEL_2;
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  pItem = (_AFX_SHELLITEMINFO *)tvItem.lParam;
  if ( tvItem.lParam == 0 )
    AfxThrowInvalidArgException();
  pParentFolder = nullptr;
  v5 = *(_DWORD *)tvItem.lParam;
  v12 = v5;
  if ( v5 != 0 )
    v6 = (*(int (__stdcall **)(int, _DWORD, _DWORD, GUID *, IShellFolder **))(*(_DWORD *)v5 + 20))(
           a1: v12,
           a2: *(_DWORD *)(tvItem.lParam + 8),
           a3: 0,
           a4: &IID_IShellFolder,
           a5: &pParentFolder);
  else
    v6 = SHGetDesktopFolder(ppshf: &pParentFolder);
  if ( v6 < 0 )
  {
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
LABEL_2:
    v14 = -1;
    CWaitCursor::~CWaitCursor(this: (CWaitCursor *)&hParentItem + 3);
    return 0;
  }
  this->EnumObjects(this, a2: hParentItem, a3: pParentFolder, a4: pItem->pidlFQ);
  tvSort.hParent = hParentItem;
  v8 = this->m_hWnd;
  tvSort.lpfnCompare = (int (__stdcall *)(int, int, int))CMFCShellTreeCtrl::CompareProc;
  tvSort.lParam = 0;
  SendMessageA(hWnd: v8, Msg: 0x1115u, wParam: 0, lParam: (LPARAM)&tvSort);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  pParentFolder->Release(this: pParentFolder);
  v14 = -1;
  CWaitCursor::~CWaitCursor(this: (CWaitCursor *)&hParentItem + 3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103F169D
// Name: public: virtual void CMFCRibbonCmdUI::SetText(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCmdUI::SetText(CMFCRibbonCmdUI *this, const char *lpszText)
{
  CRect *p_m_rect; // esi
  CWnd *m_pOther; // eax
  RECT rcUpdate; // [esp+8h] [ebp-14h] BYREF

  if ( lpszText == nullptr )
    AfxThrowInvalidArgException();
  if ( lstrcmpA(lpString1: this->m_pUpdated->m_strText.m_pszData, lpString2: lpszText) != 0 )
  {
    this->m_pUpdated->SetText(this: this->m_pUpdated, a2: lpszText);
    p_m_rect = &this->m_pUpdated->m_rect;
    rcUpdate.left = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    rcUpdate.top = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    rcUpdate.right = p_m_rect->left;
    m_pOther = this->m_pOther;
    rcUpdate.bottom = p_m_rect->top;
    RedrawWindow(hWnd: m_pOther->m_hWnd, lprcUpdate: &rcUpdate, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F1710
// Name: public: static class CObject __near * CMFCRibbonCaptionButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonCaptionButton *__stdcall CMFCRibbonCaptionButton::CreateObject()
{
  CMFCRibbonCaptionButton *v0; // ecx
  CMFCRibbonCaptionButton *result; // eax

  v0 = (CMFCRibbonCaptionButton *)operator new(nSize: 0x168u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCRibbonCaptionButton::CMFCRibbonCaptionButton(this: v0, uiCmd: 0, hwndMDIChild: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F1742
// Name: protected: virtual void CMFCRibbonCaptionButton::OnLButtonUp(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCaptionButton::OnLButtonUp(CMFCRibbonCaptionButton *this, CPoint __formal)
{
  HWND__ *m_hwndMDIChild; // eax
  HWND Parent; // eax
  CWnd *v5; // eax

  if ( this->IsPressed(this) != 0 && this->IsHighlighted(this) != 0 )
  {
    m_hwndMDIChild = this->m_hwndMDIChild;
    if ( m_hwndMDIChild != nullptr )
    {
      PostMessageA(hWnd: m_hwndMDIChild, Msg: 0x112u, wParam: this->m_nID, lParam: 0);
    }
    else
    {
      Parent = GetParent(hWnd: this->m_pRibbonBar->m_hWnd);
      v5 = CWnd::FromHandle(hWnd: Parent);
      PostMessageA(hWnd: v5->m_hWnd, Msg: 0x112u, wParam: this->m_nID, lParam: 0);
    }
    this->m_bIsHighlighted = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F179F
// Name: public: void CMFCRibbonBar::PopTooltip(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::PopTooltip(CMFCRibbonBar *this)
{
  CToolTipCtrl *m_pToolTip; // eax

  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
    SendMessageA(hWnd: m_pToolTip->m_hWnd, Msg: 0x41Cu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103F17C2
// Name: public: void CMFCRibbonBar::ToggleMimimizeState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::ToggleMimimizeState(CMFCRibbonBar *this)
{
  CMFCRibbonCategory *m_pActiveCategory; // ecx

  m_pActiveCategory = this->m_pActiveCategory;
  if ( m_pActiveCategory != nullptr )
  {
    CMFCRibbonCategory::ShowElements(this: m_pActiveCategory, bShow: this->m_dwHideFlags == 1);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F17F7
// Name: public: int CMFCRibbonBar::OnSysKeyUp(class CFrameWnd __near *,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonBar::OnSysKeyUp(CMFCRibbonBar *this, CFrameWnd *pFrameWnd, unsigned int wParam, int __formal)
{
  HWND Focus; // eax
  CMFCRibbonBar *v7; // ecx

  if ( this->m_bKeyTips != 0 )
  {
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
    if ( wParam != 18 )
      return false;
    Focus = GetFocus();
    if ( CWnd::FromHandle(hWnd: Focus) == this )
    {
      if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr )
      {
LABEL_11:
        RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
        return true;
      }
      v7 = (CMFCRibbonBar *)pFrameWnd;
    }
    else
    {
      v7 = this;
    }
    CWnd::SetFocus(this: v7);
    goto LABEL_11;
  }
  return wParam == 121 || wParam == 18;
}

//------------------------------------------------------------------------------
// Address: 0x103F186A
// Name: public: void CMFCRibbonBar::ShowCategory(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::ShowCategory(CMFCRibbonBar *this, int nIndex, int bShow)
{
  if ( nIndex >= 0 && nIndex < this->m_arCategories.m_nSize )
    this->m_arCategories.m_pData[nIndex]->m_bIsVisible = bShow;
}

//------------------------------------------------------------------------------
// Address: 0x103F1891
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonBar::FindByID(unsigned int,int,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonDefaultPanelButton *__thiscall CMFCRibbonBar::FindByID(
        CMFCRibbonBar *this,
        unsigned int uiCmdID,
        int bVisibleOnly,
        int bExcludeQAT)
{
  CMFCRibbonDefaultPanelButton *result; // eax
  CMFCRibbonCategory *m_pMainCategory; // ecx
  int v7; // edi
  CMFCRibbonCategory *v8; // ecx

  if ( bExcludeQAT != 0
    || (result = (CMFCRibbonDefaultPanelButton *)((int (__stdcall *)(unsigned int))this->m_QAToolbar.FindByID)(a1: uiCmdID)) == nullptr )
  {
    m_pMainCategory = this->m_pMainCategory;
    if ( m_pMainCategory == nullptr
      || (result = CMFCRibbonCategory::FindByID(this: m_pMainCategory, uiCmdID, bVisibleOnly)) == nullptr )
    {
      v7 = 0;
      if ( this->m_arCategories.m_nSize <= 0 )
      {
        return (CMFCRibbonDefaultPanelButton *)this->m_TabElements.FindByID(this: &this->m_TabElements, a2: uiCmdID);
      }
      else
      {
        while ( 1 )
        {
          if ( v7 < 0 || v7 >= this->m_arCategories.m_nSize )
            AfxThrowInvalidArgException();
          v8 = this->m_arCategories.m_pData[v7];
          if ( bVisibleOnly == 0 || v8->m_bIsVisible != 0 )
          {
            result = CMFCRibbonCategory::FindByID(this: v8, uiCmdID, bVisibleOnly);
            if ( result != nullptr )
              break;
          }
          if ( ++v7 >= this->m_arCategories.m_nSize )
            return (CMFCRibbonDefaultPanelButton *)this->m_TabElements.FindByID(this: &this->m_TabElements, a2: uiCmdID);
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F192E
// Name: public: void CMFCRibbonBar::GetElementsByID(unsigned int,class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::GetElementsByID(
        CMFCRibbonBar *this,
        unsigned int uiCmdID,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arButtons)
{
  int v4; // edi
  CMFCRibbonCategory *m_pMainCategory; // ecx

  v4 = 0;
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arButtons,
    nNewSize: 0,
    nGrowBy: -1);
  m_pMainCategory = this->m_pMainCategory;
  if ( m_pMainCategory != nullptr )
    CMFCRibbonCategory::GetElementsByID(this: m_pMainCategory, uiCmdID, arButtons);
  if ( this->m_arCategories.m_nSize > 0 )
  {
    do
    {
      if ( v4 < 0 || v4 >= this->m_arCategories.m_nSize )
        AfxThrowInvalidArgException();
      CMFCRibbonCategory::GetElementsByID(this: this->m_arCategories.m_pData[v4++], uiCmdID, arButtons);
    }
    while ( v4 < this->m_arCategories.m_nSize );
  }
  this->m_QAToolbar.GetElementsByID(this: &this->m_QAToolbar, a2: uiCmdID, a3: arButtons);
  this->m_TabElements.GetElementsByID(this: &this->m_TabElements, a2: uiCmdID, a3: arButtons);
}

//------------------------------------------------------------------------------
// Address: 0x103F19BA
// Name: public: int CMFCRibbonBar::DrawMenuImage(class CDC __near *,class CMFCToolBarMenuButton const __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBar::DrawMenuImage(
        CMFCRibbonBar *this,
        CDC *pDC,
        const CMFCToolBarMenuButton *pMenuItem,
        const CRect *rectImage)
{
  unsigned int m_nID; // eax
  CMFCRibbonDefaultPanelButton *v5; // eax
  _DWORD *v6; // ebx
  int m_bIsRibbonImageScale; // edi
  int v8; // ecx
  int v9; // eax
  int result; // eax
  int bWasDisabled; // [esp+Ch] [ebp-30h]
  int bWasChecked; // [esp+1Ch] [ebp-20h]
  CSize sizeElemImage; // [esp+20h] [ebp-1Ch] BYREF
  CRect rectDraw; // [esp+28h] [ebp-14h] BYREF

  m_nID = pMenuItem->m_nID;
  if ( m_nID != 0 )
  {
    if ( m_nID == -10002 )
      m_nID = 57635;
    if ( m_nID == -10003 )
      m_nID = 57634;
    if ( m_nID == -10004 )
      m_nID = 57637;
    if ( m_nID == -10005 )
      m_nID = 57642;
    v5 = CMFCRibbonBar::FindByID(this, uiCmdID: m_nID, bVisibleOnly: 0, bExcludeQAT: 1);
    v6 = &v5->__vftable;
    if ( v5 != nullptr )
    {
      m_bIsRibbonImageScale = afxGlobalData.m_bIsRibbonImageScale;
      afxGlobalData.m_bIsRibbonImageScale = 0;
      v5->GetImageSize(this: v5, result: &sizeElemImage, a3: RibbonImageSmall);
      if ( sizeElemImage.cx != 0 || sizeElemImage.cy != 0 )
      {
        v8 = rectImage->right - rectImage->left;
        if ( sizeElemImage.cx <= v8 )
        {
          v9 = rectImage->bottom - rectImage->top;
          if ( sizeElemImage.cy <= v9 )
          {
            rectDraw = *rectImage;
            InflateRect(lprc: &rectDraw, dx: (v8 - sizeElemImage.cx) / -2, dy: (v9 - sizeElemImage.cy) / -2);
            bWasDisabled = (*(int (__thiscall **)(_DWORD *))(*v6 + 56))(a1: v6);
            bWasChecked = (*(int (__thiscall **)(_DWORD *))(*v6 + 60))(a1: v6);
            v6[30] = pMenuItem->m_nStyle & 0x40000;
            v6[31] = pMenuItem->m_nStyle & 0x10000;
            result = (*(int (__thiscall **)(_DWORD *, CDC *, int, int, int, int))(*v6 + 184))(
                       a1: v6,
                       a2: pDC,
                       a3: rectDraw.left,
                       a4: rectDraw.top,
                       a5: rectDraw.right,
                       a6: rectDraw.bottom);
            v6[30] = bWasDisabled;
            v6[31] = bWasChecked;
            afxGlobalData.m_bIsRibbonImageScale = m_bIsRibbonImageScale;
            return result;
          }
        }
      }
      afxGlobalData.m_bIsRibbonImageScale = m_bIsRibbonImageScale;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103F1B17
// Name: protected: void CMFCRibbonBar::ShowSysMenu(class CPoint const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::ShowSysMenu(CMFCRibbonBar *this, const CPoint *point)
{
  HWND Parent; // eax
  CWnd *v4; // eax
  HWND m_hWnd; // eax
  HMENU SystemMenu; // eax
  CMenu *v7; // eax
  CMenu *v8; // esi
  HMENU m_hMenu; // eax
  HWND v10; // eax
  CWnd *v11; // eax
  HWND v12; // eax
  CWnd *v13; // eax
  HWND v14; // eax
  CWnd *v15; // eax
  HWND v16; // eax
  CWnd *v17; // eax
  CWnd *Owner; // eax
  HWND v19; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  if ( v4 != nullptr )
  {
    m_hWnd = v4->m_hWnd;
    if ( m_hWnd != nullptr )
    {
      SystemMenu = GetSystemMenu(hWnd: m_hWnd, bRevert: false);
      v7 = CMenu::FromHandle(hMenu: SystemMenu);
      v8 = v7;
      if ( v7 != nullptr )
      {
        m_hMenu = v7->m_hMenu;
        if ( m_hMenu != nullptr )
        {
          SetMenuDefaultItem(hMenu: m_hMenu, uItem: 0xF060u, fByPos: 0);
          v10 = GetParent(hWnd: this->m_hWnd);
          v11 = CWnd::FromHandle(hWnd: v10);
          if ( IsZoomed(hWnd: v11->m_hWnd) )
          {
            EnableMenuItem(hMenu: v8->m_hMenu, uIDEnableItem: 0xF000u, uEnable: 3u);
            EnableMenuItem(hMenu: v8->m_hMenu, uIDEnableItem: 0xF010u, uEnable: 3u);
            EnableMenuItem(hMenu: v8->m_hMenu, uIDEnableItem: 0xF030u, uEnable: 3u);
            EnableMenuItem(hMenu: v8->m_hMenu, uIDEnableItem: 0xF120u, uEnable: 0);
          }
          else
          {
            EnableMenuItem(hMenu: v8->m_hMenu, uIDEnableItem: 0xF120u, uEnable: 3u);
            EnableMenuItem(hMenu: v8->m_hMenu, uIDEnableItem: 0xF000u, uEnable: 0);
            EnableMenuItem(hMenu: v8->m_hMenu, uIDEnableItem: 0xF010u, uEnable: 0);
            EnableMenuItem(hMenu: v8->m_hMenu, uIDEnableItem: 0xF030u, uEnable: 0);
          }
          v12 = GetParent(hWnd: this->m_hWnd);
          v13 = CWnd::FromHandle(hWnd: v12);
          if ( (CWnd::GetStyle(this: v13) & 0x10000) == 0 )
          {
            DeleteMenu(hMenu: v8->m_hMenu, uPosition: 0xF120u, uFlags: 0);
            DeleteMenu(hMenu: v8->m_hMenu, uPosition: 0xF030u, uFlags: 0);
          }
          v14 = GetParent(hWnd: this->m_hWnd);
          v15 = CWnd::FromHandle(hWnd: v14);
          if ( (CWnd::GetStyle(this: v15) & 0x20000) == 0 )
            DeleteMenu(hMenu: v8->m_hMenu, uPosition: 0xF020u, uFlags: 0);
          if ( afxContextMenuManager != nullptr )
          {
            v16 = GetParent(hWnd: this->m_hWnd);
            v17 = CWnd::FromHandle(hWnd: v16);
            afxContextMenuManager->ShowPopupMenu(
              this: afxContextMenuManager,
              a2: v8->m_hMenu,
              a3: point->x,
              a4: point->y,
              a5: v17,
              a6: 1,
              a7: 1,
              a8: 0);
          }
          else
          {
            Owner = CWnd::GetOwner(this);
            if ( Owner != nullptr )
              v19 = Owner->m_hWnd;
            else
              v19 = nullptr;
            TrackPopupMenu(
              hMenu: v8->m_hMenu,
              uFlags: 4u,
              x: point->x,
              y: point->y,
              nReserved: 0,
              hWnd: v19,
              prcRect: nullptr);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F1CBE
// Name: public: void CMFCRibbonBar::SetMaximizeMode(int,class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::SetMaximizeMode(CMFCRibbonBar *this, int bMax, CWnd *pWnd)
{
  int v4; // edi
  CMFCRibbonBaseElement *v5; // eax
  CObject *v7; // eax
  HMENU SystemMenu; // eax
  CMenu *v9; // eax
  CMenu *v10; // edi
  LONG WindowLongA; // eax
  CMFCRibbonCaptionButton *v12; // eax
  CMFCRibbonCaptionButton *v13; // eax
  CMFCRibbonCaptionButton *v14; // eax
  CMFCRibbonCaptionButton *v15; // eax
  CMFCRibbonCaptionButton *v16; // eax
  CMFCRibbonBar_vtbl *v17; // eax
  tagMENUITEMINFOA menuInfo; // [esp+10h] [ebp-44h] BYREF
  void *pData; // [esp+40h] [ebp-14h]
  int bIsOleContainer; // [esp+44h] [ebp-10h]
  int v21; // [esp+50h] [ebp-4h]
  HMENU__ *hSysMenu; // [esp+60h] [ebp+Ch]

  if ( this->m_bMaximizeMode != bMax )
  {
    for ( bIsOleContainer = 0; bIsOleContainer < this->m_nSystemButtonsNum; ++bIsOleContainer )
    {
      v4 = this->m_TabElements.m_arButtons.m_nSize - 1;
      if ( v4 < 0 || v4 >= this->m_TabElements.m_arButtons.m_nSize )
        AfxThrowInvalidArgException();
      v5 = this->m_TabElements.m_arButtons.m_pData[v4];
      if ( v5 != nullptr )
        ((void (__thiscall *)(CMFCRibbonBaseElement *, int))v5->dtr_CObject)(a1: v5, a2: 1);
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
        this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_TabElements.m_arButtons,
        nNewSize: v4,
        nGrowBy: -1);
    }
    this->m_nSystemButtonsNum = 0;
    if ( bMax != 0 )
    {
      v7 = AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: pWnd);
      if ( v7 == nullptr || (bIsOleContainer = 1, v7[40].__vftable == nullptr) )
        bIsOleContainer = 0;
      hSysMenu = nullptr;
      SystemMenu = GetSystemMenu(hWnd: pWnd->m_hWnd, bRevert: false);
      v9 = CMenu::FromHandle(hMenu: SystemMenu);
      v10 = v9;
      if ( v9 != nullptr && IsMenu(hMenu: v9->m_hMenu) )
      {
        hSysMenu = v10->m_hMenu;
        if ( !IsMenu(hMenu: hSysMenu) || (CWnd::GetStyle(this: pWnd) & 0x80000) == 0 && bIsOleContainer == 0 )
          hSysMenu = nullptr;
      }
      WindowLongA = GetWindowLongA(hWnd: pWnd->m_hWnd, nIndex: -16);
      bIsOleContainer = WindowLongA;
      if ( hSysMenu != nullptr )
      {
        if ( (WindowLongA & 0x20000) != 0 )
        {
          v12 = (CMFCRibbonCaptionButton *)operator new(nSize: 0x168u);
          pData = v12;
          v21 = 0;
          if ( v12 != nullptr )
            v13 = CMFCRibbonCaptionButton::CMFCRibbonCaptionButton(
                    this: v12,
                    uiCmd: 0xF020u,
                    hwndMDIChild: pWnd->m_hWnd);
          else
            v13 = nullptr;
          v21 = -1;
          CMFCRibbonButtonsGroup::AddButton(this: &this->m_TabElements, pButton: v13);
          ++this->m_nSystemButtonsNum;
        }
        if ( (bIsOleContainer & 0x10000) != 0 )
        {
          v14 = (CMFCRibbonCaptionButton *)operator new(nSize: 0x168u);
          pData = v14;
          v21 = 1;
          if ( v14 != nullptr )
            v15 = CMFCRibbonCaptionButton::CMFCRibbonCaptionButton(
                    this: v14,
                    uiCmd: 0xF120u,
                    hwndMDIChild: pWnd->m_hWnd);
          else
            v15 = nullptr;
          v21 = -1;
          CMFCRibbonButtonsGroup::AddButton(this: &this->m_TabElements, pButton: v15);
          ++this->m_nSystemButtonsNum;
        }
        v16 = (CMFCRibbonCaptionButton *)operator new(nSize: 0x168u);
        pData = v16;
        v21 = 2;
        if ( v16 != nullptr )
          bIsOleContainer = (int)CMFCRibbonCaptionButton::CMFCRibbonCaptionButton(
                                   this: v16,
                                   uiCmd: 0xF060u,
                                   hwndMDIChild: pWnd->m_hWnd);
        else
          bIsOleContainer = 0;
        v21 = -1;
        memset(dst: (unsigned __int8 *)&menuInfo, value: 0, count: sizeof(menuInfo));
        menuInfo.cbSize = 48;
        menuInfo.fMask = 1;
        if ( !GetMenuItemInfoA(hmenu: hSysMenu, item: 0xF060u, fByPosition: false, lpmii: &menuInfo)
          || (menuInfo.fState & 3) != 0 )
        {
          *(_DWORD *)(bIsOleContainer + 120) = 1;
        }
        CMFCRibbonButtonsGroup::AddButton(this: &this->m_TabElements, pButton: (CMFCRibbonBaseElement *)bIsOleContainer);
        ++this->m_nSystemButtonsNum;
      }
    }
    this->m_bMaximizeMode = bMax;
    v17 = this->__vftable;
    this->m_pHighlighted = nullptr;
    this->m_pPressed = nullptr;
    v17->RecalcLayout(this);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F1F21
// Name: public: void CMFCRibbonBar::SetActiveMDIChild(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::SetActiveMDIChild(CMFCRibbonBar *this, CWnd *pWnd)
{
  int i; // edi
  CObject *v4; // eax
  HWND__ *m_hWnd; // ecx

  for ( i = 0; i < this->m_TabElements.m_arButtons.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_TabElements.m_arButtons.m_nSize )
      AfxThrowInvalidArgException();
    v4 = AfxDynamicDownCast(
           pClass: &CMFCRibbonCaptionButton::classCMFCRibbonCaptionButton,
           pObject: this->m_TabElements.m_arButtons.m_pData[i]);
    if ( v4 != nullptr )
    {
      if ( pWnd != nullptr )
        m_hWnd = pWnd->m_hWnd;
      else
        m_hWnd = nullptr;
      v4[89].__vftable = (CObject_vtbl *)m_hWnd;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F1F86
// Name: protected: void CMFCRibbonBar::SetPrintPreviewMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CMFCRibbonBar::SetPrintPreviewMode(CMFCRibbonBar *this@<ecx>, int a2@<edi>, int bSet)
{
  CMFCRibbonBar_vtbl *v4; // edi
  CMFCRibbonPanel *v5; // eax
  int v6; // edi
  CMFCRibbonCategory *v7; // ebx
  CMFCRibbonCategory *m_pActiveCategory; // ecx
  CMFCRibbonCategory *m_pPrintPreviewCategory; // ecx
  int v10; // edx
  int v11; // edx
  CMFCRibbonCategory *m_pActiveCategorySaved; // ecx
  CMFCRibbonPanel *v13; // [esp-Ch] [ebp-14h]
  CMFCRibbonPanel *Panel; // [esp-8h] [ebp-10h]

  if ( this->m_bIsPrintPreview != 0 )
  {
    this->m_bPrintPreviewMode = bSet;
    if ( bSet != 0 )
    {
      v4 = this->__vftable;
      Panel = CMFCRibbonCategory::GetPanel(this: this->m_pPrintPreviewCategory, nIndex: 2);
      v13 = CMFCRibbonCategory::GetPanel(this: this->m_pPrintPreviewCategory, nIndex: 1);
      v5 = CMFCRibbonCategory::GetPanel(this: this->m_pPrintPreviewCategory, nIndex: 0);
      ((void (__thiscall *)(CMFCRibbonBar *, CMFCRibbonPanel *, CMFCRibbonPanel *, CMFCRibbonPanel *, int))v4->OnSetPrintPreviewKeys)(
        a1: this,
        a2: v5,
        a3: v13,
        a4: Panel,
        a5: a2);
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
        this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arVisibleCategoriesSaved,
        nNewSize: 0,
        nGrowBy: -1);
      v6 = 0;
      if ( this->m_arCategories.m_nSize > 0 )
      {
        while ( v6 >= 0 && v6 < this->m_arCategories.m_nSize )
        {
          v7 = this->m_arCategories.m_pData[v6];
          if ( v7->m_bIsVisible != 0 )
          {
            CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
              this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arVisibleCategoriesSaved,
              nIndex: this->m_arVisibleCategoriesSaved.m_nSize,
              newElement: (CMFCRibbonKeyTip *)v6);
            v7->m_bIsVisible = 0;
          }
          if ( ++v6 >= this->m_arCategories.m_nSize )
            goto LABEL_9;
        }
        goto LABEL_12;
      }
LABEL_9:
      this->m_pPrintPreviewCategory->m_bIsVisible = 1;
      m_pActiveCategory = this->m_pActiveCategory;
      if ( m_pActiveCategory != nullptr )
        CMFCRibbonCategory::SetActive(this: m_pActiveCategory, bIsActive: 0);
      m_pPrintPreviewCategory = this->m_pPrintPreviewCategory;
      this->m_pActiveCategorySaved = this->m_pActiveCategory;
      this->m_pActiveCategory = m_pPrintPreviewCategory;
      CMFCRibbonCategory::SetActive(this: m_pPrintPreviewCategory, bIsActive: 1);
    }
    else
    {
      v10 = 0;
      if ( this->m_arVisibleCategoriesSaved.m_nSize > 0 )
      {
        while ( v10 >= 0 && v10 < this->m_arVisibleCategoriesSaved.m_nSize )
        {
          CMFCRibbonBar::ShowCategory(this, nIndex: this->m_arVisibleCategoriesSaved.m_pData[v10], bShow: 1);
          v10 = v11 + 1;
          if ( v10 >= this->m_arVisibleCategoriesSaved.m_nSize )
            goto LABEL_17;
        }
LABEL_12:
        AfxThrowInvalidArgException();
      }
LABEL_17:
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
        this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arVisibleCategoriesSaved,
        nNewSize: 0,
        nGrowBy: -1);
      this->m_pPrintPreviewCategory->m_bIsVisible = 0;
      m_pActiveCategorySaved = this->m_pActiveCategorySaved;
      this->m_pActiveCategory = m_pActiveCategorySaved;
      if ( m_pActiveCategorySaved != nullptr )
        CMFCRibbonCategory::SetActive(this: m_pActiveCategorySaved, bIsActive: 1);
    }
    this->RecalcLayout(this);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F20F6
// Name: protected: void CMFCRibbonBar::RemoveAllKeys(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::RemoveAllKeys(CMFCRibbonBar *this)
{
  int i; // ebx
  CMFCRibbonKeyTip *v3; // edi

  for ( i = 0; i < this->m_arKeyElements.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arKeyElements.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arKeyElements.m_pData[i];
    if ( v3 != nullptr )
    {
      if ( v3->m_hWnd != nullptr )
        v3->DestroyWindow(this: v3);
      ((void (__thiscall *)(CMFCRibbonKeyTip *, int))v3->dtr_CObject)(a1: v3, a2: 1);
    }
  }
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
    this: &this->m_arKeyElements,
    nNewSize: 0,
    nGrowBy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x103F2158
// Name: public: void CMFCRibbonBar::HideKeyTips(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::HideKeyTips(CMFCRibbonBar *this)
{
  int i; // edi

  for ( i = 0; i < this->m_arKeyElements.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arKeyElements.m_nSize )
      AfxThrowInvalidArgException();
    CMFCRibbonKeyTip::Hide(this: this->m_arKeyElements.m_pData[i]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F2194
// Name: public: int CMFCRibbonBar::OnSysKeyDown(class CFrameWnd __near *,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBar::OnSysKeyDown(CMFCRibbonBar *this, CFrameWnd *pFrameWnd, unsigned int wParam, int lParam)
{
  int result; // eax
  int v6; // edi
  BOOL v7; // eax
  HWND Focus; // eax
  CMFCRibbonBar *y; // ecx
  CPoint point; // [esp+4h] [ebp-1Ch] BYREF
  CRect rectWindow; // [esp+Ch] [ebp-14h] BYREF

  point.y = (int)pFrameWnd;
  result = 0;
  if ( wParam == 32 )
  {
    memset(&rectWindow, 0, sizeof(rectWindow));
    GetWindowRect(hWnd: this->m_hWnd, lpRect: &rectWindow);
    point.x = rectWindow.left + 4;
    point.y = rectWindow.top + 23;
    CMFCRibbonBar::ShowSysMenu(this, &point);
    CMFCRibbonBar::RemoveAllKeys(this);
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
    return 0;
  }
  if ( this->m_bKeyTips != 0 )
  {
    v6 = (unsigned __int16)GetKeyState(nVirtKey: 17) >> 15;
    v7 = GetKeyState(nVirtKey: 16) < 0;
    if ( wParam != 18 && wParam != 121 )
    {
      KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
      return 0;
    }
    if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr
      || (this->m_dwHideFlags & 2) != 0
      || wParam != 18 && (v6 != 0 || v7) )
    {
      return 0;
    }
    Focus = GetFocus();
    if ( CWnd::FromHandle(hWnd: Focus) != this || (lParam & 0x40000000) != 0 )
    {
      if ( wParam == 121 )
      {
        y = this;
        goto LABEL_23;
      }
    }
    else if ( wParam == 121 )
    {
      y = (CMFCRibbonBar *)point.y;
LABEL_23:
      CWnd::SetFocus(this: y);
      return 1;
    }
    if ( this->m_nKeyboardNavLevel < 0 )
      SetTimer(hWnd: this->m_hWnd, nIDEvent: 2u, uElapse: 0xC8u, lpTimerFunc: nullptr);
    return 1;
  }
  if ( wParam == 121 || wParam == 18 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F22DE
// Name: protected: static class CMFCRibbonBaseElement __near * CMFCRibbonBar::FindNearest(class CPoint,class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__cdecl CMFCRibbonBar::FindNearest(
        CPoint pt,
        const CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arButtons)
{
  int m_nSize; // eax
  int v3; // edi
  CMFCRibbonBaseElement *v4; // ebx

  m_nSize = arButtons->m_nSize;
  v3 = 0;
  if ( m_nSize <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= m_nSize )
      AfxThrowInvalidArgException();
    v4 = arButtons->m_pData[v3];
    if ( PtInRect(lprc: &v4->m_rect, pt: pt.tagPOINT) )
      break;
    m_nSize = arButtons->m_nSize;
    if ( ++v3 >= m_nSize )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x103F232D
// Name: protected: static class CMFCRibbonBaseElement __near * CMFCRibbonBar::FindNextFocusedElement(int,class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> const __near &,class CRect,class CMFCRibbonBaseElement __near *,int,int,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__cdecl CMFCRibbonBar::FindNextFocusedElement(
        int nChar,
        const CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arElems,
        CRect rectElems,
        CMFCRibbonBaseElement *pFocused,
        int bIsScrollLeftAvailable,
        int bIsScrollRightAvailable,
        int *nScroll)
{
  const CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *v7; // esi
  int m_nSize; // eax
  int v9; // edi
  int v11; // ebx
  CMFCRibbonBaseElement *v12; // ecx
  CRect *p_m_rect; // esi
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  CMFCRibbonBaseElement *v17; // ecx
  CRect *v18; // esi
  int v19; // edx
  int v20; // ebx
  CPoint v21; // rdi
  int left; // esi
  int v23; // eax
  int v24; // ebx
  CMFCRibbonBaseElement *v25; // edi
  int yStep; // [esp+20h] [ebp-38h]
  int yStart; // [esp+24h] [ebp-34h]
  int yStarta; // [esp+24h] [ebp-34h]
  CMFCRibbonBaseElement *nNewIndex; // [esp+30h] [ebp-28h]
  int nNewIndexa; // [esp+30h] [ebp-28h]
  CRect rectArea; // [esp+34h] [ebp-24h] BYREF
  CRect rectInter; // [esp+44h] [ebp-14h] BYREF
  CRect rectCurr; // 0:^1C.16

  *nScroll = 0;
  v7 = arElems;
  m_nSize = arElems->m_nSize;
  v9 = 0;
  yStep = 0;
  if ( m_nSize <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v9 < 0 || v9 >= m_nSize )
      goto LABEL_7;
    if ( arElems->m_pData[v9] == pFocused )
      break;
    yStep = ++v9;
    if ( v9 >= m_nSize )
      return nullptr;
  }
  nNewIndex = nullptr;
  yStart = CObject::IsKindOf(this: pFocused, pClass: &CMFCRibbonTab::classCMFCRibbonTab);
  if ( nChar == 9 )
  {
    nNewIndexa = -1;
    if ( GetAsyncKeyState(vKey: 16) < 0 )
    {
      v11 = v9 - 1;
      do
      {
        if ( v11 < 0 )
        {
          if ( bIsScrollLeftAvailable != 0 )
            goto LABEL_30;
          if ( bIsScrollRightAvailable != 0 )
            goto LABEL_31;
          v11 = v7->m_nSize - 1;
        }
        if ( v11 == v9 )
          return nullptr;
        if ( yStart == 0 )
          goto LABEL_21;
        if ( v11 < 0 || v11 >= v7->m_nSize )
          goto LABEL_7;
        if ( CObject::IsKindOf(this: v7->m_pData[v11], pClass: &CMFCRibbonTab::classCMFCRibbonTab) == 0 )
        {
LABEL_21:
          if ( v11 < 0 || v11 >= v7->m_nSize )
            goto LABEL_7;
          v12 = v7->m_pData[v11];
          if ( v12->IsTabStop(this: v12) != 0 )
          {
            if ( v11 >= v7->m_nSize )
              goto LABEL_7;
            p_m_rect = &arElems->m_pData[v11]->m_rect;
            rectInter.left = p_m_rect->left;
            p_m_rect = (CRect *)((char *)p_m_rect + 4);
            rectInter.top = p_m_rect->left;
            p_m_rect = (CRect *)((char *)p_m_rect + 4);
            rectInter.right = p_m_rect->left;
            rectInter.bottom = p_m_rect->top;
            v7 = arElems;
            v9 = yStep;
            if ( !IsRectEmpty(lprc: &rectInter) )
              nNewIndexa = v11;
          }
        }
        --v11;
      }
      while ( nNewIndexa < 0 );
      v14 = nNewIndexa;
LABEL_28:
      if ( v14 >= v7->m_nSize )
LABEL_7:
        AfxThrowInvalidArgException();
      return v7->m_pData[v14];
    }
    v15 = v9 + 1;
    while ( 1 )
    {
      v16 = v7->m_nSize;
      if ( v15 >= v16 )
      {
        v15 = 0;
        if ( bIsScrollRightAvailable != 0 )
          goto LABEL_50;
        if ( bIsScrollLeftAvailable != 0 )
          break;
      }
      if ( v15 == v9 )
        return nullptr;
      if ( yStart == 0 )
        goto LABEL_43;
      if ( v15 < 0 || v15 >= v16 )
        goto LABEL_7;
      if ( CObject::IsKindOf(this: v7->m_pData[v15], pClass: &CMFCRibbonTab::classCMFCRibbonTab) == 0 )
      {
LABEL_43:
        if ( v15 < 0 || v15 >= v7->m_nSize )
          goto LABEL_7;
        v17 = v7->m_pData[v15];
        if ( v17->IsTabStop(this: v17) != 0 )
        {
          if ( v15 >= v7->m_nSize )
            goto LABEL_7;
          v18 = &arElems->m_pData[v15]->m_rect;
          rectInter.left = v18->left;
          v18 = (CRect *)((char *)v18 + 4);
          rectInter.top = v18->left;
          v18 = (CRect *)((char *)v18 + 4);
          rectInter.right = v18->left;
          rectInter.bottom = v18->top;
          if ( !IsRectEmpty(lprc: &rectInter) )
            nNewIndexa = v15;
        }
      }
      v14 = nNewIndexa;
      v7 = arElems;
      ++v15;
      if ( nNewIndexa >= 0 )
        goto LABEL_28;
      v9 = yStep;
    }
LABEL_51:
    *nScroll = -2;
    return nullptr;
  }
  if ( pFocused->HasFocus(this: pFocused) != 0 )
    return nullptr;
  rectCurr = pFocused->m_rect;
  if ( nChar != 37 )
  {
    if ( nChar == 38 )
      goto LABEL_57;
    if ( nChar != 39 )
    {
      if ( nChar == 40 )
      {
LABEL_57:
        if ( nChar == 40 )
          v19 = rectCurr.bottom + 1;
        else
          v19 = rectCurr.top - 1;
        yStarta = v19;
        v20 = (rectCurr.left + rectCurr.right) / 2;
        v21.x = v20;
        do
        {
          v21.y = yStarta;
          if ( v21.x < rectElems.left && v20 > rectElems.right )
            break;
          while ( nNewIndex == nullptr )
          {
            nNewIndex = CMFCRibbonBar::FindNearest(pt: v21, arButtons: arElems);
            if ( (nNewIndex != nullptr
               || (nNewIndex = CMFCRibbonBar::FindNearest(pt: (CPoint)__PAIR64__(v21.y, v20), arButtons: arElems)) != nullptr)
              && nNewIndex->IsTabStop(this: nNewIndex) == 0 )
            {
              nNewIndex = nullptr;
            }
            v21.y += nChar != 40 ? -5 : 5;
            if ( nChar == 40 )
            {
              if ( v21.y > rectElems.bottom )
                break;
            }
            else if ( v21.y < rectElems.top )
            {
              break;
            }
          }
          v21.x -= 5;
          v20 += 5;
        }
        while ( nNewIndex == nullptr );
      }
      return nNewIndex;
    }
  }
  if ( nChar == 39 )
    left = rectCurr.right + 1;
  else
    left = rectCurr.left - 6;
  while ( 1 )
  {
    if ( nChar == 39 )
    {
      if ( left > rectElems.right )
      {
        if ( bIsScrollRightAvailable != 0 )
        {
LABEL_50:
          *nScroll = 1;
          return nullptr;
        }
        if ( bIsScrollLeftAvailable != 0 )
          goto LABEL_51;
        left = rectElems.left;
      }
    }
    else if ( left < rectElems.left )
    {
      if ( bIsScrollLeftAvailable != 0 )
      {
LABEL_30:
        *nScroll = -1;
        return nullptr;
      }
      if ( bIsScrollRightAvailable != 0 )
      {
LABEL_31:
        *nScroll = 2;
        return nullptr;
      }
      left = rectElems.right;
    }
    if ( left < rectCurr.left || left > rectCurr.right )
    {
      rectArea.top = rectCurr.top;
      rectArea.right = left + 5;
      rectArea.left = left;
      rectArea.bottom = rectCurr.bottom;
      if ( pFocused->m_bCompactMode == 0 && pFocused->m_bIntermediateMode == 0
        || ((int (*)(void))pFocused->IsWholeRowHeight)() != 0 )
      {
        InflateRect(lprc: &rectArea, dx: 0, dy: (rectArea.bottom - rectArea.top) / -3);
      }
      v23 = arElems->m_nSize;
      v24 = 0;
      memset(&rectInter, 0, sizeof(rectInter));
      if ( v23 > 0 )
      {
        while ( 1 )
        {
          if ( v24 < 0 || v24 >= v23 )
            goto LABEL_7;
          v25 = arElems->m_pData[v24];
          if ( v25->IsTabStop(this: v25) != 0
            && IntersectRect(lprcDst: &rectInter, lprcSrc1: &v25->m_rect, lprcSrc2: &rectArea) )
          {
            break;
          }
          v23 = arElems->m_nSize;
          if ( ++v24 >= v23 )
            goto LABEL_101;
        }
        nNewIndex = v25;
      }
LABEL_101:
      left += nChar != 39 ? -5 : 5;
      if ( nNewIndex == nullptr )
        continue;
    }
    return nNewIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F278A
// Name: public: void CMFCRibbonBar::DeactivateKeyboardFocus(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::DeactivateKeyboardFocus(CMFCRibbonBar *this, int bSetFocus)
{
  CMFCRibbonBar_vtbl *v3; // eax
  CMFCRibbonBaseElement *v4; // eax
  CMFCRibbonBaseElement *v5; // edi
  CMFCRibbonBaseElement_vtbl *v6; // eax
  CFrameWnd *ParentFrame; // eax

  CMFCRibbonBar::RemoveAllKeys(this);
  v3 = this->__vftable;
  this->m_nCurrKeyChar = 0;
  v4 = v3->GetFocused(this);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v6 = v4->__vftable;
    v5->m_bIsFocused = 0;
    v6->OnSetFocus(this: v5, a2: 0);
    v5->Redraw(this: v5);
  }
  if ( this->m_nKeyboardNavLevel >= 0 )
  {
    this->m_nKeyboardNavLevel = -1;
    this->m_pKeyboardNavLevelParent = nullptr;
    this->m_pKeyboardNavLevelCurrent = nullptr;
    ParentFrame = CWnd::GetParentFrame(this);
    if ( bSetFocus != 0 )
      CWnd::SetFocus(this: ParentFrame);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F280E
// Name: protected: void CMFCRibbonBar::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::OnCancelMode(CMFCRibbonBar *this)
{
  CMFCRibbonCategory *m_pActiveCategory; // ecx
  CMFCRibbonBaseElement *m_pHighlighted; // eax
  CMFCRibbonBaseElement *m_pPressed; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-30h]
  HWND__ *v6; // [esp-10h] [ebp-30h]
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  CPane::OnCancelMode(this);
  CMFCRibbonBar::DeactivateKeyboardFocus(this, bSetFocus: 0);
  if ( this->m_bAutoCommandTimer != 0 )
  {
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
    this->m_bAutoCommandTimer = 0;
  }
  this->m_bTracked = 0;
  CMFCRibbonBar::PopTooltip(this);
  m_pActiveCategory = this->m_pActiveCategory;
  if ( m_pActiveCategory != nullptr )
    m_pActiveCategory->OnCancelMode(this: m_pActiveCategory);
  m_pHighlighted = this->m_pHighlighted;
  if ( m_pHighlighted != nullptr )
  {
    rect = m_pHighlighted->m_rect;
    m_pHighlighted->m_bIsHighlighted = 0;
    this->m_pHighlighted->OnHighlight(this: this->m_pHighlighted, a2: 0);
    this->m_pHighlighted->m_bIsPressed = 0;
    if ( this->m_pPressed == this->m_pHighlighted )
      this->m_pPressed = nullptr;
    m_hWnd = this->m_hWnd;
    this->m_pHighlighted = nullptr;
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: &rect, hrgnUpdate: nullptr, flags: 0x105u);
  }
  m_pPressed = this->m_pPressed;
  if ( m_pPressed != nullptr )
  {
    rect = m_pPressed->m_rect;
    m_pPressed->m_bIsHighlighted = 0;
    this->m_pPressed->m_bIsPressed = 0;
    v6 = this->m_hWnd;
    this->m_pPressed = nullptr;
    RedrawWindow(hWnd: v6, lprcUpdate: &rect, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F2911
// Name: public: void CMFCRibbonBar::ShowKeyTips(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::ShowKeyTips(CMFCRibbonBar *this, int bRepos)
{
  int i; // ebx
  CMFCRibbonKeyTip *v4; // edi
  CMFCRibbonBaseElement *m_pElement; // eax
  const char *m_pszData; // eax
  CToolTipCtrl *m_pToolTip; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strKeys; // [esp+10h] [ebp-10h] BYREF
  int v9; // [esp+1Ch] [ebp-4h]

  for ( i = 0; i < this->m_arKeyElements.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arKeyElements.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arKeyElements.m_pData[i];
    m_pElement = v4->m_pElement;
    if ( this->m_nCurrKeyChar != 0 )
    {
      if ( v4->m_bIsMenu != 0 )
        m_pszData = m_pElement->m_strMenuKeys.m_pszData;
      else
        m_pszData = m_pElement->m_strKeys.m_pszData;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &strKeys,
        pszSrc: m_pszData);
      v9 = 0;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: &strKeys);
      if ( *((int *)strKeys.m_pszData - 3) < 2 || *strKeys.m_pszData != this->m_nCurrKeyChar )
      {
        CMFCRibbonKeyTip::Hide(this: v4);
        v9 = -1;
        ATL::CStringData::Release(this: (ATL::CStringData *)strKeys.m_pszData - 1);
        continue;
      }
      v9 = -1;
      ATL::CStringData::Release(this: (ATL::CStringData *)strKeys.m_pszData - 1);
    }
    CMFCRibbonKeyTip::Show(this: v4, bRepos);
  }
  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr && IsWindowVisible(hWnd: m_pToolTip->m_hWnd) )
    CWnd::SetWindowPos(
      this: this->m_pToolTip,
      pWndInsertAfter: &CWnd::wndTopMost,
      x: -1,
      y: -1,
      cx: -1,
      cy: -1,
      nFlags: 0x13u);
}

//------------------------------------------------------------------------------
// Address: 0x103F2A27
// Name: public: void CMFCRibbonBar::SetKeyboardNavigationLevel(class CObject __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBar::SetKeyboardNavigationLevel(CMFCRibbonBar *this, CObject *pLevel, int bSetFocus)
{
  HWND Focus; // eax
  CWnd *v5; // eax
  CWnd *v6; // esi
  CMFCRibbonCategory *v7; // eax
  CMFCRibbonKeyTip *v8; // eax
  int v9; // edi
  CMFCRibbonCategory *m_pActiveCategory; // eax
  CMFCRibbonCategory **v11; // eax
  CMFCRibbonCategory *v12; // esi
  CMFCRibbonCategory *v13; // eax
  CMFCRibbonKeyTip *v14; // eax
  CMFCRibbonApplicationButton *m_pMainButton; // eax
  CMFCRibbonPanel *v16; // eax
  CMFCRibbonPanel *v17; // esi
  CMFCRibbonPanelMenuBar *m_pParentMenuBar; // esi
  HWND Parent; // eax
  CWnd *v20; // eax
  CMFCPopupMenu *v21; // esi
  CMFCPopupMenu *ParentPopupMenu; // eax
  CObject *v23; // eax
  CObject *v24; // ecx
  CMFCRibbonCategory *m_pParent; // eax
  CMFCRibbonBaseElement *m_pParentRibbonElement; // esi
  int v27; // esi
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> arElements; // [esp+10h] [ebp-38h] BYREF
  CMFCRibbonCategory *ParentFrame; // [esp+24h] [ebp-24h]
  RECT rc; // [esp+28h] [ebp-20h] BYREF
  int v31; // [esp+44h] [ebp-4h]

  if ( this->m_bKeyTips != 0 && (this->m_dwHideFlags & 2) == 0 )
  {
    if ( bSetFocus != 0 )
      CWnd::SetFocus(this);
    CMFCRibbonBar::RemoveAllKeys(this);
    this->m_nCurrKeyChar = 0;
    this->m_pKeyboardNavLevelParent = nullptr;
    this->m_pKeyboardNavLevelCurrent = pLevel;
    ParentFrame = (CMFCRibbonCategory *)CWnd::GetParentFrame(this);
    Focus = GetFocus();
    v5 = CWnd::FromHandle(hWnd: Focus);
    v6 = v5;
    if ( v5 != nullptr
      && v5->m_hWnd != nullptr
      && (IsChild(hWndParent: (HWND)ParentFrame->m_rect.left, hWnd: v5->m_hWnd)
       || v6->m_hWnd == (HWND__ *)ParentFrame->m_rect.left) )
    {
      if ( pLevel == nullptr )
      {
        this->m_nKeyboardNavLevel = 0;
        if ( this->m_pMainButton != nullptr )
        {
          v7 = (CMFCRibbonCategory *)operator new(nSize: 0x8Cu);
          ParentFrame = v7;
          v31 = 0;
          if ( v7 != nullptr )
            v8 = CMFCRibbonKeyTip::CMFCRibbonKeyTip(
                   this: (CMFCRibbonKeyTip *)v7,
                   pElement: this->m_pMainButton,
                   bIsMenu: 0);
          else
            v8 = nullptr;
          v31 = -1;
          CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
            this: &this->m_arKeyElements,
            nIndex: this->m_arKeyElements.m_nSize,
            newElement: v8);
        }
        v9 = 0;
        if ( this->m_arCategories.m_nSize <= 0 )
        {
LABEL_16:
          ((void (__stdcall *)(CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *))this->m_QAToolbar.AddToKeyList)(a1: &this->m_arKeyElements);
          ((void (__stdcall *)(CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *))this->m_TabElements.AddToKeyList)(a1: &this->m_arKeyElements);
          m_pActiveCategory = this->m_pActiveCategory;
          if ( m_pActiveCategory == nullptr || (this->m_dwHideFlags & 2) != 0 )
          {
            m_pMainButton = this->m_pMainButton;
            if ( m_pMainButton != nullptr )
              m_pMainButton->m_bIsFocused = 1;
          }
          else
          {
            m_pActiveCategory->m_Tab.m_bIsFocused = 1;
          }
          goto LABEL_55;
        }
        while ( v9 >= 0 && v9 < this->m_arCategories.m_nSize )
        {
          v11 = &this->m_arCategories.m_pData[v9];
          v12 = *v11;
          if ( (*v11)->m_bIsVisible != 0 )
          {
            v13 = (CMFCRibbonCategory *)operator new(nSize: 0x8Cu);
            ParentFrame = v13;
            v31 = 1;
            if ( v13 != nullptr )
              v14 = CMFCRibbonKeyTip::CMFCRibbonKeyTip(this: (CMFCRibbonKeyTip *)v13, pElement: &v12->m_Tab, bIsMenu: 0);
            else
              v14 = nullptr;
            v31 = -1;
            CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
              this: &this->m_arKeyElements,
              nIndex: this->m_arKeyElements.m_nSize,
              newElement: v14);
          }
          if ( ++v9 >= this->m_arCategories.m_nSize )
            goto LABEL_16;
        }
        goto LABEL_28;
      }
      arElements.__vftable = (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>_vtbl *)&CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::`vftable';
      memset(&arElements.m_pData, 0, 16);
      v31 = 2;
      ParentFrame = (CMFCRibbonCategory *)AfxDynamicDownCast(
                                            pClass: &CMFCRibbonCategory::classCMFCRibbonCategory,
                                            pObject: pLevel);
      v16 = (CMFCRibbonPanel *)AfxDynamicDownCast(pClass: &CMFCRibbonPanel::classCMFCRibbonPanel, pObject: pLevel);
      v17 = v16;
      if ( ParentFrame != nullptr )
      {
        if ( this->m_dwHideFlags == 0 || ParentFrame->m_pParentMenuBar != nullptr )
          CMFCRibbonCategory::GetElements(this: ParentFrame, &arElements);
        goto LABEL_50;
      }
      if ( v16 == nullptr || (CMFCRibbonPanel::GetElements(this: v16, &arElements), v17->IsMainPanel(this: v17) != 0) )
      {
LABEL_50:
        v27 = 0;
        if ( arElements.m_nSize <= 0 )
        {
LABEL_54:
          v31 = -1;
          this->m_nKeyboardNavLevel = 1;
          CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::~CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>(this: &arElements);
LABEL_55:
          CMFCRibbonBar::ShowKeyTips(this, bRepos: 0);
          RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
          return;
        }
        while ( v27 >= 0 && v27 < arElements.m_nSize )
        {
          arElements.m_pData[v27]->AddToKeyList(this: arElements.m_pData[v27], a2: &this->m_arKeyElements);
          if ( ++v27 >= arElements.m_nSize )
            goto LABEL_54;
        }
LABEL_28:
        AfxThrowInvalidArgException();
      }
      ParentFrame = nullptr;
      if ( CMFCRibbonPanel::GetParentButton(this: v17) == nullptr
        || CMFCRibbonPanel::GetParentButton(this: v17)->m_dwStyleMask == 0 )
      {
        ParentFrame = v17->m_pParent;
      }
      m_pParentMenuBar = v17->m_pParentMenuBar;
      if ( m_pParentMenuBar != nullptr )
      {
        Parent = GetParent(hWnd: m_pParentMenuBar->m_hWnd);
        v20 = CWnd::FromHandle(hWnd: Parent);
        v21 = (CMFCPopupMenu *)AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: v20);
        ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this: v21);
        v23 = AfxDynamicDownCast(pClass: &CMFCRibbonPanelMenu::classCMFCRibbonPanelMenu, pObject: ParentPopupMenu);
        if ( v23 != nullptr )
        {
          v24 = (CObject *)v23[1977].__vftable;
          this->m_pKeyboardNavLevelParent = v24;
          if ( v24 == nullptr )
          {
            m_pParent = (CMFCRibbonCategory *)v23[1981].__vftable;
LABEL_46:
            ParentFrame = m_pParent;
          }
        }
        else
        {
          m_pParentRibbonElement = v21->m_pParentRibbonElement;
          if ( m_pParentRibbonElement != nullptr )
          {
            m_pParent = m_pParentRibbonElement->m_pParent;
            goto LABEL_46;
          }
        }
      }
      if ( ParentFrame != nullptr )
      {
        rc = (RECT)ParentFrame->m_rect;
        if ( !IsRectEmpty(lprc: &rc) )
          this->m_pKeyboardNavLevelParent = ParentFrame;
      }
      goto LABEL_50;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10421C72
// Name: public: COleDropTarget::COleDropTarget(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleDropTarget *__thiscall COleDropTarget::COleDropTarget(COleDropTarget *this)
{
  CCmdTarget::CCmdTarget(this);
  this->__vftable = (COleDropTarget_vtbl *)&COleDropTarget::`vftable';
  this->m_xDropTarget.__vftable = (COleDropTarget::XDropTarget_vtbl *)&COleDropTarget::XDropTarget::`vftable';
  this->m_hWnd = nullptr;
  this->m_lpDataObject = nullptr;
  this->m_nTimerID = 0xFFFF;
  AfxLockGlobals(nLockType: 4);
  if ( bInitialized_1 == 0 )
  {
    COleDropTarget::nScrollInset = GetProfileIntA(lpAppName: "windows", lpKeyName: "DragScrollInset", nDefault: 11);
    COleDropTarget::nScrollDelay = GetProfileIntA(lpAppName: "windows", lpKeyName: "DragScrollDelay", nDefault: 50);
    COleDropTarget::nScrollInterval = GetProfileIntA(
                                        lpAppName: "windows",
                                        lpKeyName: "DragScrollInterval",
                                        nDefault: 50);
    bInitialized_1 = 1;
  }
  AfxUnlockGlobals(nLockType: 4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10421D07
// Name: public: virtual COleDropTarget::~COleDropTarget(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall COleDropTarget::~COleDropTarget(COleDropTarget *this)
{
  this->__vftable = (COleDropTarget_vtbl *)&COleDropTarget::`vftable';
  if ( this->m_hWnd != nullptr )
    COleDropTarget::Revoke(this);
  CCmdTarget::~CCmdTarget(this);
}

//------------------------------------------------------------------------------
// Address: 0x10421DFE
// Name: public: virtual struct CRuntimeClass __near * CMouseManager::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMouseManager::GetRuntimeClass(CMouseManager *this)
{
  return &CMouseManager::classCMouseManager;
}
