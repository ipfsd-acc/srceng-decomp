// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/op_input.cpp
// Functions: 82
// ============================================================

#include "hammer\op_input.h"

//------------------------------------------------------------------------------
// Address: 0x100E52E0
// Name: public: virtual struct CRuntimeClass __near * COP_Input::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COP_Input::GetRuntimeClass(COP_Input *this)
{
  return &COP_Input::classCOP_Input;
}

//------------------------------------------------------------------------------
// Address: 0x100E52F0
// Name: InputCompareDelays
// Source: json
//------------------------------------------------------------------------------
int __stdcall InputCompareDelays(
        CInputConnection *pInputConn1,
        CInputConnection *pInputConn2,
        SortDirection_t eDirection)
{
  return CEntityConnection::CompareDelays(
           pConn1: pInputConn1->m_pConnection,
           pConn2: pInputConn2->m_pConnection,
           eDirection);
}

//------------------------------------------------------------------------------
// Address: 0x100E5310
// Name: InputCompareOutputNames
// Source: json
//------------------------------------------------------------------------------
int __stdcall InputCompareOutputNames(
        CInputConnection *pInputConn1,
        CInputConnection *pInputConn2,
        SortDirection_t eDirection)
{
  return CEntityConnection::CompareOutputNames(
           pConn1: pInputConn1->m_pConnection,
           pConn2: pInputConn2->m_pConnection,
           eDirection);
}

//------------------------------------------------------------------------------
// Address: 0x100E5330
// Name: InputCompareInputNames
// Source: json
//------------------------------------------------------------------------------
int __stdcall InputCompareInputNames(
        CInputConnection *pInputConn1,
        CInputConnection *pInputConn2,
        SortDirection_t eDirection)
{
  return CEntityConnection::CompareInputNames(
           pConn1: pInputConn1->m_pConnection,
           pConn2: pInputConn2->m_pConnection,
           eDirection);
}

//------------------------------------------------------------------------------
// Address: 0x100E5350
// Name: InputCompareSourceNames
// Source: json
//------------------------------------------------------------------------------
int __stdcall InputCompareSourceNames(
        CInputConnection *pInputConn1,
        CInputConnection *pInputConn2,
        SortDirection_t eDirection)
{
  return CEntityConnection::CompareSourceNames(
           pConn1: pInputConn1->m_pConnection,
           pConn2: pInputConn2->m_pConnection,
           eDirection);
}

//------------------------------------------------------------------------------
// Address: 0x100E5380
// Name: public: class CImageList __near * CListCtrl::SetImageList(class CImageList __near *,int)
// Source: json
//------------------------------------------------------------------------------
CImageList *__thiscall CListCtrl::SetImageList(CListCtrl *this, CImageList *pImageList, WPARAM nImageList)
{
  struct _IMAGELIST *m_hImageList; // eax
  struct _IMAGELIST *v4; // eax

  m_hImageList = (struct _IMAGELIST *)pImageList;
  if ( pImageList != nullptr )
    m_hImageList = pImageList->m_hImageList;
  v4 = (struct _IMAGELIST *)SendMessageA(
                              hWnd: this->m_hWnd,
                              Msg: 0x1003u,
                              wParam: nImageList,
                              lParam: (LPARAM)m_hImageList);
  return CImageList::FromHandle(h: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100E53B0
// Name: public: struct CComCtlWrapper::ImageList_ReplaceIcon_Type CComCtlWrapper::GetProcAddress_ImageList_ReplaceIcon(void)
// Source: json
//------------------------------------------------------------------------------
CComCtlWrapper::ImageList_ReplaceIcon_Type *__thiscall CComCtlWrapper::GetProcAddress_ImageList_ReplaceIcon(
        CComCtlWrapper *this,
        CComCtlWrapper::ImageList_ReplaceIcon_Type *result)
{
  HINSTANCE__ *ModuleHandleA; // eax
  HINSTANCE__ *LibraryA; // eax

  if ( this->m__ImageList_ReplaceIcon.p == nullptr )
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
    this->m__ImageList_ReplaceIcon.p = (int (__stdcall *)(struct _IMAGELIST *, int, HICON__ *))GetProcAddress(
                                                                                                 hModule: this->m_hModule,
                                                                                                 lpProcName: "ImageList_ReplaceIcon");
  }
  result->p = (int (__stdcall *)(struct _IMAGELIST *, int, HICON__ *))this->m__ImageList_ReplaceIcon;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E5410
// Name: public: int CComCtlWrapper::_ImageList_ReplaceIcon(struct _IMAGELIST __near *,int,struct HICON__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComCtlWrapper::_ImageList_ReplaceIcon(
        CComCtlWrapper *this,
        struct _IMAGELIST *himl,
        int i,
        HICON__ *hicon)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v6; // eax
  int (__stdcall *p)(struct _IMAGELIST *, int, HICON__ *); // esi
  int v9; // edi
  DWORD LastError; // ebx
  int v11; // [esp+0h] [ebp-30h]
  CComCtlWrapper::ImageList_ReplaceIcon_Type v12; // [esp+Ch] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+10h] [ebp-20h] BYREF
  int v14; // [esp+14h] [ebp-1Ch]
  int v15; // [esp+2Ch] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v6 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v14 = -1;
  if ( !v6 )
    return -1;
  v15 = 0;
  CComCtlWrapper::GetProcAddress_ImageList_ReplaceIcon(this, result: &v12);
  p = this->m__ImageList_ReplaceIcon.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v9 = ((int (__stdcall *)(struct _IMAGELIST *, int, HICON__ *, int))p)(a1: himl, a2: i, a3: hicon, a4: v11);
  v14 = v9;
  v15 = -1;
  if ( v9 == -1 )
    LastError = GetLastError();
  else
    LastError = 0;
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v9 == -1 )
    SetLastError(dwErrCode: LastError);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x100E5500
// Name: protected: virtual void COP_Input::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::DoDataExchange(COP_Input *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x594, rControl: (HWND__ *)&this->m_ListCtrl);
}

//------------------------------------------------------------------------------
// Address: 0x100E5520
// Name: protected: void COP_Input::RemoveAllEntityConnections(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::RemoveAllEntityConnections(COP_Input *this)
{
  LRESULT v2; // eax
  int v3; // esi
  void *ItemData; // edi

  v2 = SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  if ( v2 > 0 )
  {
    v3 = v2 - 1;
    do
    {
      ItemData = (void *)CListCtrl::GetItemData(this: &this->m_ListCtrl, nItem: v3);
      SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1008u, wParam: v3, lParam: 0);
      operator delete(p: ItemData);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5590
// Name: protected: void COP_Input::SortListByColumn(int,enum SortDirection_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::SortListByColumn(COP_Input *this, int nColumn, WPARAM eDirection)
{
  int (__stdcall *v3)(CInputConnection *, CInputConnection *, SortDirection_t); // eax

  switch ( nColumn )
  {
    case 1:
      v3 = InputCompareSourceNames;
      goto LABEL_6;
    case 2:
      v3 = InputCompareOutputNames;
      goto LABEL_6;
    case 3:
      v3 = InputCompareInputNames;
      goto LABEL_6;
    case 5:
      v3 = InputCompareDelays;
LABEL_6:
      if ( v3 != nullptr )
        SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1030u, wParam: eDirection, lParam: (LPARAM)v3);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E55F0
// Name: protected: void COP_Input::UpdateColumnHeaderText(int,bool,enum SortDirection_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::UpdateColumnHeaderText(
        COP_Input *this,
        WPARAM nColumn,
        bool bIsSortColumn,
        SortDirection_t eDirection)
{
  unsigned int v5; // eax
  unsigned int v6; // kr00_4
  char v7; // cl
  HWND__ *m_hWnd; // [esp-10h] [ebp-14Ch]
  char szHeaderText[260]; // [esp+Ch] [ebp-130h] BYREF
  tagLVCOLUMNA Column; // [esp+110h] [ebp-2Ch] BYREF

  memset(dst: (unsigned __int8 *)&Column, value: 0, count: sizeof(Column));
  m_hWnd = this->m_ListCtrl.m_hWnd;
  Column.mask = 4;
  Column.pszText = szHeaderText;
  Column.cchTextMax = 260;
  SendMessageA(hWnd: m_hWnd, Msg: 0x1019u, wParam: nColumn, lParam: (LPARAM)&Column);
  v5 = 0;
  if ( szHeaderText[0] != 0 )
  {
    v6 = strlen(szHeaderText);
    v5 = v6;
    v7 = szHeaderText[v6 - 1];
    if ( v7 == 62 || v7 == 60 )
      v5 = v6 - 3;
  }
  if ( bIsSortColumn )
  {
    if ( v5 != 0 )
    {
      *(_WORD *)&szHeaderText[v5] = 8224;
      v5 += 2;
    }
    szHeaderText[v5++] = 2 * (eDirection == Sort_Ascending) + 60;
  }
  szHeaderText[v5] = 0;
  SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Au, wParam: nColumn, lParam: (LPARAM)&Column);
}

//------------------------------------------------------------------------------
// Address: 0x100E56D0
// Name: protected: virtual void COP_Input::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall COP_Input::OnDestroy(COP_Input *this)
{
  COP_Input::RemoveAllEntityConnections(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E56E0
// Name: public: void COP_Input::SetSelectedConnection(class CEntityConnection __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::SetSelectedConnection(COP_Input *this, CEntityConnection *pConnection)
{
  void (__stdcall *v2)(HWND, UINT, WPARAM, LPARAM); // edi
  int v4; // esi
  unsigned int ItemData; // eax
  CListCtrl *p_m_ListCtrl; // ecx
  LRESULT nItemCount; // [esp+Ch] [ebp-4h]

  v2 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  v4 = 0;
  nItemCount = SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  if ( nItemCount > 0 )
  {
    do
    {
      ItemData = CListCtrl::GetItemData(this: &this->m_ListCtrl, nItem: v4);
      p_m_ListCtrl = &this->m_ListCtrl;
      if ( *(CEntityConnection **)(ItemData + 4) == pConnection )
        CListCtrl::SetItemState(this: p_m_ListCtrl, nItem: v4, nState: 2u, nStateMask: 2u);
      else
        CListCtrl::SetItemState(this: p_m_ListCtrl, nItem: v4, nState: 0xFFFFFFFD, nStateMask: 2u);
      ++v4;
    }
    while ( v4 < nItemCount );
    v2 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  }
  v2(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100E5770
// Name: public: int CImageList::Add(struct HICON__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImageList::Add(CImageList *this, HICON__ *hIcon)
{
  AFX_MODULE_STATE *ModuleState; // eax
  struct _IMAGELIST *m_hImageList; // [esp-Ch] [ebp-Ch]

  m_hImageList = this->m_hImageList;
  ModuleState = AfxGetModuleState();
  return CComCtlWrapper::_ImageList_ReplaceIcon(
           this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
           himl: m_hImageList,
           i: -1,
           hicon: hIcon);
}

//------------------------------------------------------------------------------
// Address: 0x100E5790
// Name: protected: void COP_Input::AddEntityConnections(char const __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::AddEntityConnections(COP_Input *this, const char *pTargetName, CMapEntity *pTestEntity)
{
  int m_Size; // edi
  LRESULT v5; // ebx
  int v6; // esi
  CEntityConnection *v7; // edi
  char *Value; // eax
  CListCtrl *v9; // esi
  const char *v10; // eax
  _DWORD *v11; // eax
  char string[12]; // [esp+8h] [ebp-110h] BYREF
  char szTemp[260]; // [esp+14h] [ebp-104h]

  m_Size = pTestEntity->m_Connections.m_Size;
  *(_DWORD *)&szTemp[252] = this;
  *(_DWORD *)&szTemp[248] = m_Size;
  if ( m_Size != 0 )
  {
    v5 = SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x102Fu, wParam: v5 + m_Size, lParam: 0);
    v6 = 0;
    *(_DWORD *)&szTemp[256] = 0;
    if ( m_Size > 0 )
    {
      do
      {
        v7 = pTestEntity->m_Connections.m_Memory.m_pMemory[v6];
        if ( v7 != nullptr && CompareEntityNames(szName1: v7->m_szTargetEntity, szName2: pTargetName) == 0 )
        {
          Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                            this: &pTestEntity->m_KeyValues,
                            pszKey: "targetname",
                            piIndex: nullptr);
          if ( Value == nullptr )
            Value = pTestEntity->m_szClass;
          CEntityConnection::SetSourceName(this: v7, pszName: Value);
          v9 = (CListCtrl *)(*(_DWORD *)&szTemp[252] + 268);
          CListCtrl::InsertItem(
            this: (CListCtrl *)(*(_DWORD *)&szTemp[252] + 268),
            nMask: 2u,
            nItem: v5,
            lpszItem: &var,
            nState: 0,
            nStateMask: 0,
            nImage: 1,
            lParam: 0);
          CListCtrl::SetItemText(this: v9, nItem: v5, nSubItem: 2, lpszText: v7->m_szOutput);
          CListCtrl::SetItemText(this: v9, nItem: v5, nSubItem: 1, lpszText: v7->m_szSourceEntity);
          CListCtrl::SetItemText(this: v9, nItem: v5, nSubItem: 3, lpszText: v7->m_szInput);
          sprintf(string, format: "%.2f", v7->m_fDelay);
          CListCtrl::SetItemText(this: v9, nItem: v5, nSubItem: 5, lpszText: string);
          v10 = "No";
          if ( v7->m_nTimesToFire != -1 )
            v10 = "Yes";
          CListCtrl::SetItemText(this: v9, nItem: v5, nSubItem: 6, lpszText: v10);
          CListCtrl::SetItemText(this: v9, nItem: v5, nSubItem: 4, lpszText: v7->m_szParam);
          v11 = operator new(nSize: 0xCu);
          *v11 = pTestEntity;
          v11[1] = v7;
          CListCtrl::SetItem(
            this: v9,
            nItem: v5,
            nSubItem: 0,
            nMask: 4u,
            lpszItem: nullptr,
            nImage: 0,
            nState: 0,
            nStateMask: 0,
            lParam: (int)v11);
          v6 = *(_DWORD *)&szTemp[256];
          ++v5;
        }
        *(_DWORD *)&szTemp[256] = ++v6;
      }
      while ( v6 < *(int *)&szTemp[248] );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5940
// Name: protected: void COP_Input::SetSortColumn(int,enum SortDirection_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::SetSortColumn(COP_Input *this, int nColumn, SortDirection_t eDirection)
{
  WPARAM m_nSortColumn; // eax
  int v5; // eax
  int v6; // eax
  WPARAM v7; // ecx
  int (__stdcall *v8)(CInputConnection *, CInputConnection *, SortDirection_t); // eax

  m_nSortColumn = this->m_nSortColumn;
  if ( m_nSortColumn != nColumn )
    COP_Input::UpdateColumnHeaderText(this, nColumn: m_nSortColumn, bIsSortColumn: false, eDirection);
  v5 = this->m_nSortColumn;
  if ( v5 != nColumn || this->m_eSortDirection[v5] != eDirection )
    COP_Input::UpdateColumnHeaderText(this, nColumn, bIsSortColumn: true, eDirection);
  this->m_nSortColumn = nColumn;
  this->m_eSortDirection[nColumn] = eDirection;
  v6 = this->m_nSortColumn;
  v7 = this->m_eSortDirection[v6];
  switch ( v6 )
  {
    case 1:
      v8 = InputCompareSourceNames;
      goto LABEL_11;
    case 2:
      v8 = InputCompareOutputNames;
      goto LABEL_11;
    case 3:
      v8 = InputCompareInputNames;
      goto LABEL_11;
    case 5:
      v8 = InputCompareDelays;
LABEL_11:
      if ( v8 != nullptr )
        SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1030u, wParam: v7, lParam: (LPARAM)v8);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5A00
// Name: protected: void COP_Input::UpdateEntityList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::UpdateEntityList(COP_Input *this)
{
  CUtlReferenceVector<CMapEntity> *m_pEntityList; // ecx
  const CUtlReferenceVector<CMapClass> *m_pObjectList; // edx
  int i; // edi
  CMapEntity *m_pObject; // esi
  CUtlReference<CMapEntity> *m_pHead; // eax
  CUtlReference<CMapEntity> src; // [esp+8h] [ebp-1Ch] BYREF
  COP_Input *v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+20h] [ebp-4h]

  m_pEntityList = this->m_pEntityList;
  v8 = this;
  CUtlReferenceVector<CMapEntity>::RemoveAll(this: m_pEntityList);
  m_pObjectList = this->m_pObjectList;
  if ( m_pObjectList != nullptr )
  {
    for ( i = 0; i < m_pObjectList->m_Size; ++i )
    {
      m_pObject = (CMapEntity *)m_pObjectList->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&m_pObjectList->m_Memory
                                                                                          + 2) >> 27)][i & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr && m_pObject->IsMapClass(this: m_pObject, a2: CMapEntity::__Type) != 0 )
      {
        m_pHead = m_pObject->m_References.m_pHead;
        src.m_pPrev = nullptr;
        src.m_pObject = m_pObject;
        src.m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        m_pObject->m_References.m_pHead = &src;
        v9 = 0;
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
          this: v8->m_pEntityList,
          elem: v8->m_pEntityList->m_Size,
          &src);
        v9 = -1;
        if ( src.m_pObject != nullptr )
        {
          if ( src.m_pPrev != nullptr )
          {
            src.m_pPrev->m_pNext = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = src.m_pPrev;
          }
          else if ( src.m_pObject->m_References.m_pHead == &src )
          {
            src.m_pObject->m_References.m_pHead = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = nullptr;
          }
          memset(&src, 0, sizeof(src));
        }
      }
      m_pObjectList = v8->m_pObjectList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5B50
// Name: protected: void COP_Input::UpdateConnectionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::UpdateConnectionList(COP_Input *this)
{
  CUtlReferenceVector<CMapEntity> *m_pEntityList; // eax
  int v3; // edi
  int m_Size; // eax
  CMapEntity *m_pObject; // ecx
  const char *v6; // eax
  WCKeyValuesT<WCKVBase_Dict> *p_m_KeyValues; // esi
  const char *Value; // eax
  CMapWorld *m_pWorld; // edi
  int i; // esi
  CMapEntity *v11; // eax
  CUtlReference<CMapEntity> *v12; // ecx
  CMapEntity *v13; // ecx
  CUtlReferenceVector<CMapEntity> *v14; // eax
  LRESULT j; // esi
  unsigned int ItemData; // eax
  const CMapEntity **v17; // edi
  int v18; // eax
  int v19; // eax
  CUtlReference<CMapEntity> *m_pHead; // [esp+Ch] [ebp-24h] BYREF
  CUtlReference<CMapEntity> *v21; // [esp+10h] [ebp-20h]
  CMapEntity *v22; // [esp+14h] [ebp-1Ch]
  CMapEntity *pTestEntity; // [esp+18h] [ebp-18h]
  int pos; // [esp+1Ch] [ebp-14h]
  const char *pszTargetName; // [esp+20h] [ebp-10h]
  int v26; // [esp+2Ch] [ebp-4h]

  COP_Input::UpdateEntityList(this);
  COP_Input::RemoveAllEntityConnections(this);
  m_pEntityList = this->m_pEntityList;
  v3 = 0;
  this->m_bMultipleTargetNames = false;
  m_Size = m_pEntityList->m_Size;
  pszTargetName = nullptr;
  pos = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      m_pObject = this->m_pEntityList->m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_pEntityList->m_Memory
                                                                                   + 2) >> 27)][v3
                                                                                              & ((32
                                                                                                * *((_DWORD *)&this->m_pEntityList->m_Memory
                                                                                                  + 2)) >> 5)].m_pObject;
      if ( pszTargetName == nullptr )
        break;
      p_m_KeyValues = &m_pObject->m_KeyValues;
      Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                this: &m_pObject->m_KeyValues,
                pszKey: "targetname",
                piIndex: nullptr);
      if ( pszTargetName != Value )
      {
        v6 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "targetname", piIndex: nullptr);
        this->m_bMultipleTargetNames = true;
        goto LABEL_6;
      }
LABEL_7:
      if ( pszTargetName != nullptr )
      {
        m_pWorld = CMapDoc::m_pMapDoc->m_pWorld;
        for ( i = 0; i < m_pWorld->m_EntityList.m_Size; ++i )
        {
          v11 = m_pWorld->m_EntityList.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&m_pWorld->m_EntityList.m_Memory
                                                                                  + 2) >> 27)][i
                                                                                             & ((32
                                                                                               * *((_DWORD *)&m_pWorld->m_EntityList.m_Memory
                                                                                                 + 2)) >> 5)].m_pObject;
          if ( v11 != nullptr )
          {
            v22 = m_pWorld->m_EntityList.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&m_pWorld->m_EntityList.m_Memory
                                                                                    + 2) >> 27)][i
                                                                                               & ((32
                                                                                                 * *((_DWORD *)&m_pWorld->m_EntityList.m_Memory + 2)) >> 5)].m_pObject;
            m_pHead = v11->m_References.m_pHead;
            v12 = v11->m_References.m_pHead;
            if ( v12 != nullptr )
              v12->m_pPrev = (CUtlReference<CMapEntity> *)&m_pHead;
            v21 = nullptr;
            v11->m_References.m_pHead = (CUtlReference<CMapEntity> *)&m_pHead;
          }
          v13 = v22;
          pTestEntity = v22;
          v26 = -1;
          if ( v22 != nullptr )
          {
            if ( v21 != nullptr )
            {
              v21->m_pNext = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = v21;
            }
            else if ( (CUtlReference<CMapEntity> **)v22->m_References.m_pHead == &m_pHead )
            {
              v22->m_References.m_pHead = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = nullptr;
            }
            v13 = pTestEntity;
            v21 = nullptr;
            m_pHead = nullptr;
            v22 = nullptr;
          }
          if ( v13 != nullptr )
            COP_Input::AddEntityConnections(this, pTargetName: pszTargetName, pTestEntity: v13);
        }
        v3 = pos;
      }
      v14 = this->m_pEntityList;
      pos = ++v3;
      if ( v3 >= v14->m_Size )
        goto LABEL_26;
    }
    v6 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &m_pObject->m_KeyValues, pszKey: "targetname", piIndex: nullptr);
LABEL_6:
    pszTargetName = v6;
    goto LABEL_7;
  }
LABEL_26:
  for ( j = 0; j < SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0); ++j )
  {
    ItemData = CListCtrl::GetItemData(this: &this->m_ListCtrl, nItem: j);
    v17 = (const CMapEntity **)ItemData;
    if ( ItemData != 0
      && ((v18 = *(_DWORD *)(ItemData + 4), pTestEntity = (CMapEntity *)v18, v18 == 0)
       || MapEntityList_HasInput(pList: this->m_pEntityList, szInput: (const char *)(v18 + 776), eType: iotInvalid)
       && CEntityConnection::ValidateOutput(pEntity: *v17, pszOutput: &pTestEntity->m_szClass[8])) )
    {
      v19 = 2 * this->m_bMultipleTargetNames + 1;
    }
    else
    {
      v19 = this->m_bMultipleTargetNames ? 2 : 0;
    }
    CListCtrl::SetItem(
      this: &this->m_ListCtrl,
      nItem: j,
      nSubItem: 0,
      nMask: 2u,
      lpszItem: nullptr,
      nImage: v19,
      nState: 0,
      nStateMask: 0,
      lParam: 0);
  }
  CWnd::EnableWindow(this: &this->m_ListCtrl, bEnable: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100E5E10
// Name: protected: virtual int COP_Input::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Input::OnInitDialog(COP_Input *this)
{
  LPARAM v2; // eax
  CImageList *v3; // eax
  CImageList *v4; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v6; // eax
  AFX_MODULE_STATE *v7; // eax
  AFX_MODULE_STATE *v8; // eax
  AFX_MODULE_STATE *v9; // eax
  AFX_MODULE_STATE *v10; // eax
  AFX_MODULE_STATE *v11; // eax
  AFX_MODULE_STATE *v12; // eax
  struct _IMAGELIST *v13; // eax
  struct _IMAGELIST *v15; // [esp-Ch] [ebp-ACh]
  struct _IMAGELIST *v16; // [esp-Ch] [ebp-ACh]
  struct _IMAGELIST *v17; // [esp-Ch] [ebp-ACh]
  struct _IMAGELIST *v18; // [esp-Ch] [ebp-ACh]
  HICON IconW; // [esp-4h] [ebp-A4h]
  HICON v20; // [esp-4h] [ebp-A4h]
  HICON v21; // [esp-4h] [ebp-A4h]
  HICON v22; // [esp-4h] [ebp-A4h]
  CAnchorDef anchorDefs[3]; // [esp+Ch] [ebp-94h] BYREF
  CImageList *v24; // [esp+90h] [ebp-10h]
  int v25; // [esp+9Ch] [ebp-4h]

  CDialog::OnInitDialog(this);
  SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1036u, wParam: 0, lParam: 49);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 0,
    lpszColumnHeading: &var,
    nFormat: 2,
    nWidth: 20,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 1,
    lpszColumnHeading: "Source",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 2,
    lpszColumnHeading: "Output",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 3,
    lpszColumnHeading: "My Input",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 5,
    lpszColumnHeading: "Delay",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 6,
    lpszColumnHeading: "Once",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_ListCtrl,
    nCol: 4,
    lpszColumnHeading: "Parameter",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  COP_Input::UpdateConnectionList(this);
  COP_Input::SetSortColumn(this, nColumn: this->m_nSortColumn, eDirection: this->m_eSortDirection[this->m_nSortColumn]);
  COP_Input::UpdateColumnHeaderText(
    this,
    nColumn: this->m_nSortColumn,
    bIsSortColumn: true,
    eDirection: this->m_eSortDirection[this->m_nSortColumn]);
  if ( SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
  {
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 2u, lParam: 0xFFFF);
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 1u, lParam: 0xFFFF);
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 3u, lParam: 0xFFFF);
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 5u, lParam: 65534);
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 6u, lParam: 65534);
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x101Eu, wParam: 4u, lParam: 0xFFFF);
  }
  v2 = COP_Input::m_pImageList;
  if ( COP_Input::m_pImageList != 0 )
    goto LABEL_8;
  AfxGetModuleState();
  v3 = (CImageList *)operator new(nSize: 8u);
  v24 = v3;
  v25 = 0;
  v4 = v3 != nullptr ? CImageList::CImageList(this: v3) : nullptr;
  v25 = -1;
  COP_Input::m_pImageList = (LPARAM)v4;
  CImageList::Create(this: v4, cx: 16, cy: 16, nFlags: 1u, nInitial: 1, nGrow: 0);
  ModuleState = AfxGetModuleState();
  IconW = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x137);
  v15 = *(struct _IMAGELIST **)(COP_Input::m_pImageList + 4);
  v6 = AfxGetModuleState();
  CComCtlWrapper::_ImageList_ReplaceIcon(
    this: *(CComCtlWrapper **)v6->m_pDllIsolationWrappers,
    himl: v15,
    i: -1,
    hicon: IconW);
  v7 = AfxGetModuleState();
  v20 = LoadIconW(hInstance: v7->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x138);
  v16 = *(struct _IMAGELIST **)(COP_Input::m_pImageList + 4);
  v8 = AfxGetModuleState();
  CComCtlWrapper::_ImageList_ReplaceIcon(
    this: *(CComCtlWrapper **)v8->m_pDllIsolationWrappers,
    himl: v16,
    i: -1,
    hicon: v20);
  v9 = AfxGetModuleState();
  v21 = LoadIconW(hInstance: v9->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x7A06);
  v17 = *(struct _IMAGELIST **)(COP_Input::m_pImageList + 4);
  v10 = AfxGetModuleState();
  CComCtlWrapper::_ImageList_ReplaceIcon(
    this: *(CComCtlWrapper **)v10->m_pDllIsolationWrappers,
    himl: v17,
    i: -1,
    hicon: v21);
  v11 = AfxGetModuleState();
  v22 = LoadIconW(hInstance: v11->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x7A05);
  v18 = *(struct _IMAGELIST **)(COP_Input::m_pImageList + 4);
  v12 = AfxGetModuleState();
  CComCtlWrapper::_ImageList_ReplaceIcon(
    this: *(CComCtlWrapper **)v12->m_pDllIsolationWrappers,
    himl: v18,
    i: -1,
    hicon: v22);
  v2 = COP_Input::m_pImageList;
  if ( COP_Input::m_pImageList != 0 )
LABEL_8:
    v2 = *(_DWORD *)(v2 + 4);
  v13 = (struct _IMAGELIST *)SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1003u, wParam: 1u, lParam: v2);
  CImageList::FromHandle(h: v13);
  CAnchorDef::CAnchorDef(this: anchorDefs, dlgItemID: 1428, eSimpleAnchor: k_eSimpleAnchorAllSides);
  CAnchorDef::CAnchorDef(this: &anchorDefs[1], dlgItemID: 1303, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorDef::CAnchorDef(this: &anchorDefs[2], dlgItemID: 1676, eSimpleAnchor: k_eSimpleAnchorBottomSide);
  CAnchorMgr::Init(this: &this->m_AnchorMgr, hParentWnd: this->m_hWnd, pAnchors: anchorDefs, nAnchors: 3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E6150
// Name: public: virtual void COP_Input::UpdateData(int,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::UpdateData(COP_Input *this, int Mode, void *pData, bool bCanEdit)
{
  CObjectPage::UpdateData(this, Mode, pData, bCanEdit);
  if ( IsWindow(hWnd: this->m_hWnd) && Mode == 2 )
  {
    SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1009u, wParam: 0, lParam: 0);
    COP_Input::UpdateConnectionList(this);
    COP_Input::SortListByColumn(
      this,
      nColumn: this->m_nSortColumn,
      eDirection: this->m_eSortDirection[this->m_nSortColumn]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E61C0
// Name: public: COP_Input::COP_Input(void)
// Source: json
//------------------------------------------------------------------------------
COP_Input *__thiscall COP_Input::COP_Input(COP_Input *this)
{
  CUtlReferenceVector<CMapEntity> *v2; // eax
  CUtlReferenceVector<CMapEntity> *v3; // edi

  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x132u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (COP_Input_vtbl *)&CObjectPage::`vftable';
  this->m_bMultiEdit = false;
  this->m_bFirstTimeActive = false;
  this->__vftable = (COP_Input_vtbl *)&COP_Input::`vftable';
  CAnchorMgr::CAnchorMgr(this: &this->m_AnchorMgr);
  CWnd::CWnd(this: &this->m_ListCtrl);
  this->m_ListCtrl.__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
  this->m_pObjectList = nullptr;
  v2 = (CUtlReferenceVector<CMapEntity> *)operator new(nSize: 0x14u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v2->m_Memory.m_pMemory = nullptr;
    v2->m_Memory.m_nBlocks = 0;
    *((_DWORD *)&v2->m_Memory + 2) = 0;
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
      this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)v2,
      nGrowSize: 0,
      nInitSize: 0);
    v3->m_Size = 0;
    v3->m_pElements = nullptr;
  }
  else
  {
    v3 = nullptr;
  }
  this->m_pEntityList = v3;
  this->m_pEditObjectRuntimeClass = &editCMapClass::classeditCMapClass;
  this->m_nSortColumn = 2;
  this->m_eSortDirection[0] = Sort_Ascending;
  this->m_eSortDirection[1] = Sort_Ascending;
  this->m_eSortDirection[2] = Sort_Ascending;
  this->m_eSortDirection[3] = Sort_Ascending;
  this->m_eSortDirection[4] = Sort_Ascending;
  this->m_eSortDirection[5] = Sort_Ascending;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E62E0
// Name: public: virtual COP_Input::~COP_Input(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::~COP_Input(COP_Input *this)
{
  CUtlReferenceVector<CMapEntity> *m_pEntityList; // edi

  this->__vftable = (COP_Input_vtbl *)&COP_Input::`vftable';
  m_pEntityList = this->m_pEntityList;
  if ( m_pEntityList != nullptr )
  {
    CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: m_pEntityList);
    operator delete(p: m_pEntityList);
  }
  CListCtrl::~CListCtrl(this: &this->m_ListCtrl);
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&this->m_AnchorMgr);
  this->__vftable = (COP_Input_vtbl *)&CObjectPage::`vftable';
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E6380
// Name: public: static class CObject __near * COP_Input::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
COP_Input *__stdcall COP_Input::CreateObject()
{
  COP_Input *v0; // eax

  v0 = (COP_Input *)operator new(nSize: 0x180u);
  if ( v0 != nullptr )
    return COP_Input::COP_Input(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E6410
// Name: protected: void COP_Input::OnMark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Input::OnMark(COP_Input *this)
{
  LRESULT v2; // eax
  WPARAM v3; // esi
  unsigned int ItemData; // eax
  CMapClass *v5; // esi
  CEntityConnection *v6; // eax
  CMapDoc *v7; // edi
  CUtlReference<CMapClass> *m_pHead; // eax
  CMainFrame *MainWnd; // eax
  CEntityConnection *v10; // [esp-4h] [ebp-44h]
  CUtlReferenceVector<CMapClass> Select; // [esp+Ch] [ebp-34h] BYREF
  CUtlReference<CMapClass> src; // [esp+20h] [ebp-20h] BYREF
  CEntityConnection *pConnection; // [esp+2Ch] [ebp-14h]
  CMapDoc *pDoc; // [esp+30h] [ebp-10h]
  int v15; // [esp+3Ch] [ebp-4h]

  if ( SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1032u, wParam: 0, lParam: 0) == 1 )
  {
    v2 = SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
    pDoc = CMapDoc::m_pMapDoc;
    if ( v2 > 0 && CMapDoc::m_pMapDoc != nullptr )
    {
      v3 = v2 - 1;
      while ( (SendMessageA(hWnd: this->m_ListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v3, lParam: 2) & 2) == 0 )
      {
        if ( (--v3 & 0x80000000) != 0 )
          return;
      }
      ItemData = CListCtrl::GetItemData(this: &this->m_ListCtrl, nItem: v3);
      v5 = *(CMapClass **)ItemData;
      v6 = *(CEntityConnection **)(ItemData + 4);
      pConnection = v6;
      if ( v5 != nullptr && v6 != nullptr )
      {
        v7 = pDoc;
        CSelection::SetMode(this: pDoc->m_pSelection, eNewSelectMode: selectObjects);
        memset(&Select, 0, 12);
        CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &Select.m_Memory, nGrowSize: 0, nInitSize: 0);
        Select.m_Size = 0;
        Select.m_pElements = nullptr;
        v15 = 3;
        m_pHead = v5->m_References.m_pHead;
        src.m_pPrev = nullptr;
        src.m_pObject = v5;
        src.m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        v5->m_References.m_pHead = &src;
        LOBYTE(v15) = 4;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
          this: &Select,
          elem: Select.m_Size,
          &src);
        LOBYTE(v15) = 3;
        if ( src.m_pObject != nullptr )
        {
          if ( src.m_pPrev != nullptr )
          {
            src.m_pPrev->m_pNext = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = src.m_pPrev;
          }
          else if ( src.m_pObject->m_References.m_pHead == &src )
          {
            src.m_pObject->m_References.m_pHead = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = nullptr;
          }
          memset(&src, 0, sizeof(src));
        }
        CMapDoc::SelectObjectList(this: v7, pList: &Select, cmd: 1042);
        v10 = pConnection;
        MainWnd = GetMainWnd();
        CObjectProperties::SetPageToOutput(this: MainWnd->pObjectProperties, pConnection: v10);
        CMapDoc::Center2DViewsOnSelection(this: v7);
        v15 = -1;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &Select);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E65D0
// Name: protected: virtual int COP_Input::OnNotify(unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Input::OnNotify(COP_Input *this, unsigned int wParam, _DWORD *lParam, int *pResult)
{
  int v4; // edx
  int v6; // edi
  int m_nSortColumn; // edx
  SortDirection_t v8; // esi

  if ( lParam[1] != 1428 )
    return CPropertyPage::OnNotify(this, wParam, (int)lParam, pResult);
  v4 = lParam[2];
  if ( v4 != -108 )
  {
    if ( v4 == -3 )
    {
      COP_Input::OnMark(this);
      return 1;
    }
    return CPropertyPage::OnNotify(this, wParam, (int)lParam, pResult);
  }
  v6 = lParam[4];
  if ( v6 < 6 )
  {
    m_nSortColumn = this->m_nSortColumn;
    v8 = this->m_eSortDirection[v6];
    if ( v6 == m_nSortColumn )
      v8 = this->m_eSortDirection[m_nSortColumn] == Sort_Ascending;
    COP_Input::SetSortColumn(this, nColumn: v6, eDirection: v8);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E6650
// Name: protected: virtual struct AFX_MSGMAP const __near * COP_Input::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COP_Input::GetMessageMap(COP_Input *this)
{
  return (const AFX_MSGMAP *)&off_105EF3C4;
}

//------------------------------------------------------------------------------
// Address: 0x1034A575
// Name: public: virtual CListCtrl::~CListCtrl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CListCtrl::~CListCtrl(CListCtrl *this)
{
  this->__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034A5A6
// Name: public: int CListCtrl::GetItemRect(int,struct tagRECT __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::GetItemRect(CListCtrl *this, WPARAM nItem, tagRECT *lpRect, unsigned int nCode)
{
  lpRect->left = nCode;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x100Eu, wParam: nItem, lParam: (LPARAM)lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x1034A5C9
// Name: public: int CListCtrl::HitTest(class CPoint,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::HitTest(CListCtrl *this, tagPOINT pt, unsigned int *pFlags)
{
  LRESULT result; // eax
  tagLVHITTESTINFO hti; // [esp+4h] [ebp-1Ch] BYREF

  hti.pt = pt;
  result = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1012u, wParam: 0, lParam: (LPARAM)&hti);
  if ( pFlags != nullptr )
    *pFlags = hti.flags;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034A619
// Name: public: int CListCtrl::SetItem(int,int,unsigned int,char const __near *,int,unsigned int,unsigned int,long,int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::SetItem(
        CListCtrl *this,
        int nItem,
        int nSubItem,
        unsigned int nMask,
        char *lpszItem,
        int nImage,
        unsigned int nState,
        unsigned int nStateMask,
        int lParam,
        int nIndent)
{
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  lvi.mask = nMask;
  lvi.iItem = nItem;
  lvi.iSubItem = nSubItem;
  lvi.stateMask = nStateMask;
  lvi.state = nState;
  lvi.pszText = lpszItem;
  lvi.iImage = nImage;
  lvi.lParam = lParam;
  lvi.iIndent = nIndent;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&lvi);
}

//------------------------------------------------------------------------------
// Address: 0x1034A66F
// Name: public: int CListCtrl::SetItemState(int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::SetItemState(CListCtrl *this, WPARAM nItem, unsigned int nState, unsigned int nStateMask)
{
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  lvi.stateMask = nStateMask;
  lvi.state = nState;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x102Bu, wParam: nItem, lParam: (LPARAM)&lvi);
}

//------------------------------------------------------------------------------
// Address: 0x1034A69C
// Name: public: int CListCtrl::SetItemText(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::SetItemText(CListCtrl *this, WPARAM nItem, int nSubItem, char *lpszText)
{
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  lvi.iSubItem = nSubItem;
  lvi.pszText = lpszText;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x102Eu, wParam: nItem, lParam: (LPARAM)&lvi);
}

//------------------------------------------------------------------------------
// Address: 0x1034A6C9
// Name: public: unsigned long CListCtrl::GetItemData(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CListCtrl::GetItemData(CListCtrl *this, int nItem)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-50h]
  tagLVITEMA lvi; // [esp+4h] [ebp-3Ch] BYREF

  memset(dst: (unsigned __int8 *)&lvi, value: 0, count: sizeof(lvi));
  lvi.iItem = nItem;
  m_hWnd = this->m_hWnd;
  lvi.mask = 4;
  SendMessageA(hWnd: m_hWnd, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvi);
  return lvi.lParam;
}

//------------------------------------------------------------------------------
// Address: 0x1034A70D
// Name: protected: virtual int CListCtrl::OnChildNotify(unsigned int,unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::OnChildNotify(
        CListCtrl *this,
        unsigned int message,
        unsigned int wParam,
        tagNMHDR *lParam,
        int *pResult)
{
  if ( message != 43 )
    return CWnd::OnChildNotify(this, uMsg: message, wParam, lParam, pResult);
  this->DrawItem(this, a2: (tagDRAWITEMSTRUCT *)lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034ABF0
// Name: public: virtual struct CRuntimeClass __near * CListCtrl::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CListCtrl::GetRuntimeClass(CListCtrl *this)
{
  return &CListCtrl::classCListCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x1034ABF6
// Name: public: virtual struct CRuntimeClass __near * CImageList::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CImageList::GetRuntimeClass(CImageList *this)
{
  return &CImageList::classCImageList;
}

//------------------------------------------------------------------------------
// Address: 0x1034AC23
// Name: public: int CListCtrl::InsertColumn(int,char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::InsertColumn(
        CListCtrl *this,
        WPARAM nCol,
        char *lpszColumnHeading,
        int nFormat,
        int nWidth,
        int nSubItem)
{
  tagLVCOLUMNA column; // [esp+0h] [ebp-2Ch] BYREF

  column.pszText = lpszColumnHeading;
  column.fmt = nFormat;
  column.mask = 5;
  if ( nWidth != -1 )
  {
    column.mask = 7;
    column.cx = nWidth;
  }
  if ( nSubItem != -1 )
  {
    column.mask |= 8u;
    column.iSubItem = nSubItem;
  }
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x101Bu, wParam: nCol, lParam: (LPARAM)&column);
}

//------------------------------------------------------------------------------
// Address: 0x1034AC78
// Name: public: int CListCtrl::InsertItem(unsigned int,int,char const __near *,unsigned int,unsigned int,int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::InsertItem(
        CListCtrl *this,
        unsigned int nMask,
        int nItem,
        char *lpszItem,
        unsigned int nState,
        unsigned int nStateMask,
        int nImage,
        int lParam)
{
  tagLVITEMA item; // [esp+0h] [ebp-3Ch] BYREF

  item.mask = nMask;
  item.iItem = nItem;
  item.iSubItem = 0;
  item.pszText = lpszItem;
  item.state = nState;
  item.stateMask = nStateMask;
  item.iImage = nImage;
  item.lParam = lParam;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&item);
}

//------------------------------------------------------------------------------
// Address: 0x1034ACC6
// Name: public: int CListCtrl::SetItem(int,int,unsigned int,char const __near *,int,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::SetItem(
        CListCtrl *this,
        int nItem,
        int nSubItem,
        unsigned int nMask,
        char *lpszItem,
        int nImage,
        unsigned int nState,
        unsigned int nStateMask,
        int lParam)
{
  return CListCtrl::SetItem(this, nItem, nSubItem, nMask, lpszItem, nImage, nState, nStateMask, lParam, nIndent: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1034AD23
// Name: public: CImageList::CImageList(void)
// Source: json
//------------------------------------------------------------------------------
CImageList *__thiscall CImageList::CImageList(CImageList *this)
{
  this->m_hImageList = nullptr;
  this->__vftable = (CImageList_vtbl *)&CImageList::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034AD30
// Name: public: static class CObject __near * CImageList::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CObject *__stdcall CImageList::CreateObject()
{
  CObject *result; // eax

  result = (CObject *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (CObject_vtbl *)&CImageList::`vftable';
  result[1].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034B096
// Name: public: struct _IMAGELIST __near * CImageList::Detach(void)
// Source: json
//------------------------------------------------------------------------------
struct _IMAGELIST *__thiscall CImageList::Detach(CImageList *this)
{
  struct _IMAGELIST *m_hImageList; // edi
  CHandleMap *v3; // eax

  m_hImageList = this->m_hImageList;
  if ( m_hImageList != nullptr )
  {
    v3 = afxMapHIMAGELIST(bCreate: 0);
    if ( v3 != nullptr )
      CMapPtrToPtr::RemoveKey(this: &v3->m_permanentMap, key: (CDocument *)this->m_hImageList);
  }
  this->m_hImageList = nullptr;
  return m_hImageList;
}

//------------------------------------------------------------------------------
// Address: 0x1034B0C2
// Name: public: int CImageList::DeleteImageList(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImageList::DeleteImageList(CImageList *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  struct _IMAGELIST *v3; // [esp-4h] [ebp-4h]

  if ( this->m_hImageList == nullptr )
    return 0;
  v3 = CImageList::Detach(this);
  ModuleState = AfxGetModuleState();
  return CComCtlWrapper::_ImageList_Destroy(this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers, himl: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1034B0E1
// Name: public: static class CImageList __near * CImageList::FromHandle(struct _IMAGELIST __near *)
// Source: json
//------------------------------------------------------------------------------
CImageList *__stdcall CImageList::FromHandle(struct _IMAGELIST *h)
{
  CHandleMap *v1; // eax

  v1 = afxMapHIMAGELIST(bCreate: 1);
  return (CImageList *)CHandleMap::FromHandle(this: v1, h);
}

//------------------------------------------------------------------------------
// Address: 0x1034B0F5
// Name: public: static class CImageList __near * CImageList::FromHandlePermanent(struct _IMAGELIST __near *)
// Source: json
//------------------------------------------------------------------------------
CImageList *__stdcall CImageList::FromHandlePermanent(CDocument *h)
{
  CHandleMap *v1; // ecx
  CImageList *result; // eax

  v1 = afxMapHIMAGELIST(bCreate: 0);
  result = nullptr;
  if ( v1 != nullptr )
    return (CImageList *)CMapPtrToPtr::GetValueAt(this: &v1->m_permanentMap, key: h);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034B116
// Name: public: int CImageList::Attach(struct _IMAGELIST __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImageList::Attach(CImageList *this, struct _IMAGELIST *hImageList)
{
  CHandleMap *v4; // eax

  if ( hImageList == nullptr )
    return 0;
  v4 = afxMapHIMAGELIST(bCreate: 1);
  this->m_hImageList = hImageList;
  *CMapPtrToPtr::operator[](this: &v4->m_permanentMap, key: (CDocument *)hImageList) = this;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034B148
// Name: protected: void CListCtrl::RemoveImageList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CListCtrl::RemoveImageList(CListCtrl *this, WPARAM nImageList)
{
  CDocument *v3; // eax

  v3 = (CDocument *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1002u, wParam: nImageList, lParam: 0);
  if ( CImageList::FromHandlePermanent(h: v3) != nullptr )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x1003u, wParam: nImageList, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1034B185
// Name: protected: void CListCtrl::OnNcDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CListCtrl::OnNcDestroy(CListCtrl *this)
{
  CListCtrl::RemoveImageList(this, nImageList: 0);
  CListCtrl::RemoveImageList(this, nImageList: 1u);
  CListCtrl::RemoveImageList(this, nImageList: 2u);
  CWnd::OnNcDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034B28C
// Name: public: int CImageList::Create(int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImageList::Create(CImageList *this, int cx, int cy, unsigned int nFlags, int nInitial, int nGrow)
{
  struct _IMAGELIST *v7; // eax

  v7 = AfxImageList_Create(cx, cy, flags: nFlags, cInitial: nInitial, cGrow: nGrow);
  return CImageList::Attach(this, hImageList: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1034B2B5
// Name: public: int CImageList::Create(unsigned int,int,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImageList::Create(CImageList *this, const char *nBitmapID, int cx, int nGrow, unsigned int crMask)
{
  AFX_MODULE_STATE *ModuleState; // eax
  struct _IMAGELIST *ImageA; // eax
  HINSTANCE__ *m_hCurrentResourceHandle; // [esp-1Ch] [ebp-20h]

  m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
  ModuleState = AfxGetModuleState();
  ImageA = CComCtlWrapper::_ImageList_LoadImageA(
             this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
             hi: m_hCurrentResourceHandle,
             lpbmp: nBitmapID,
             cx,
             cGrow: nGrow,
             crMask,
             uType: 0,
             uFlags: 0);
  return CImageList::Attach(this, hImageList: ImageA);
}

//------------------------------------------------------------------------------
// Address: 0x1034B2F2
// Name: protected: virtual struct AFX_MSGMAP const __near * CListCtrl::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CListCtrl::GetMessageMap(CListCtrl *this)
{
  return &messageMap_16;
}

//------------------------------------------------------------------------------
// Address: 0x1034B38D
// Name: public: virtual CImageList::~CImageList(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CImageList::~CImageList(CImageList *this)
{
  this->__vftable = (CImageList_vtbl *)&CImageList::`vftable';
  CImageList::DeleteImageList(this);
}

//------------------------------------------------------------------------------
// Address: 0x10390591
// Name: public: struct HICON__ __near * CImageList::ExtractIconA(int)
// Source: json
//------------------------------------------------------------------------------
HICON__ *__thiscall CImageList::ExtractIconA(CImageList *this, int nImage)
{
  AFX_MODULE_STATE *ModuleState; // eax
  struct _IMAGELIST *m_hImageList; // [esp-Ch] [ebp-Ch]

  m_hImageList = this->m_hImageList;
  ModuleState = AfxGetModuleState();
  return CComCtlWrapper::_ImageList_GetIcon(
           this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
           himl: m_hImageList,
           i: nImage,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10398977
// Name: public: class CEdit __near * CListCtrl::EditLabel(int)
// Source: json
//------------------------------------------------------------------------------
CEdit *__thiscall CListCtrl::EditLabel(CListCtrl *this, WPARAM nItem)
{
  HWND__ *v2; // eax

  v2 = (HWND__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1017u, wParam: nItem, lParam: 0);
  return (CEdit *)CWnd::FromHandle(hWnd: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10398999
// Name: public: class CEdit __near * CListCtrl::GetEditControl(void)const
// Source: json
//------------------------------------------------------------------------------
CEdit *__thiscall CListCtrl::GetEditControl(CListCtrl *this)
{
  HWND__ *v1; // eax

  v1 = (HWND__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1018u, wParam: 0, lParam: 0);
  return (CEdit *)CWnd::FromHandle(hWnd: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1034AD4A
// Name: public: static void ConstructDestruct<class CImageList>::Construct(class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall ConstructDestruct<CImageList>::Construct(CObject *pObject)
{
  if ( pObject != nullptr )
  {
    pObject[1].__vftable = nullptr;
    pObject->__vftable = (CObject_vtbl *)&CImageList::`vftable';
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034B45E
// Name: public: virtual CRgn::~CRgn(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRgn::~CRgn(CRgn *this)
{
  this->__vftable = (CRgn_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034B4B1
// Name: public: virtual struct CRuntimeClass __near * CPtrArray::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPtrArray::GetRuntimeClass(CPtrArray *this)
{
  return &CPtrArray::classCPtrArray;
}

//------------------------------------------------------------------------------
// Address: 0x1034B4B7
// Name: public: CPtrArray::CPtrArray(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPtrArray *__thiscall CPtrArray::CPtrArray(CPtrArray *this)
{
  this->__vftable = (CPtrArray_vtbl *)&CPtrArray::`vftable';
  this->m_pData = nullptr;
  this->m_nGrowBy = 0;
  this->m_nMaxSize = 0;
  this->m_nSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034B4CE
// Name: public: virtual CPtrArray::~CPtrArray(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPtrArray::~CPtrArray(CPtrArray *this)
{
  void **m_pData; // [esp-4h] [ebp-4h]

  m_pData = this->m_pData;
  this->__vftable = (CPtrArray_vtbl *)&CPtrArray::`vftable';
  operator delete(p: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1034B4DE
// Name: public: void CPtrArray::InsertAt(int,void __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPtrArray::InsertAt(CPtrArray *this, int nIndex, void *newElement, int nCount)
{
  int v4; // edi
  int v6; // ebx
  int m_nSize; // edi
  int v8; // eax

  v4 = nIndex;
  if ( nIndex < 0 || (v6 = nCount, nCount <= 0) )
    AfxThrowInvalidArgException();
  if ( nIndex < this->m_nSize )
  {
    m_nSize = this->m_nSize;
    CUIntArray::SetSize(this, nNewSize: m_nSize + nCount, nGrowBy: -1);
    ATL::Checked::memmove_s(
      _S1: &this->m_pData[nCount] + nIndex,
      _S1max: 4 * (this->m_nSize - nIndex - nCount),
      _S2: &this->m_pData[nIndex],
      _N: 4 * (m_nSize - nIndex));
    memset(dst: (unsigned __int8 *)&this->m_pData[nIndex], value: 0, count: 4 * nCount);
    v4 = nIndex;
  }
  else
  {
    CUIntArray::SetSize(this, nNewSize: nIndex + nCount, nGrowBy: -1);
  }
  v8 = v4;
  do
  {
    this->m_pData[v8++] = newElement;
    --v6;
  }
  while ( v6 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1034B59F
// Name: void AfxWingdixTerm(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl AfxWingdixTerm()
{
  AfxDeleteObject(pObject: (void **)&_afxHalftoneBrush);
}

//------------------------------------------------------------------------------
// Address: 0x103905B2
// Name: public: int CGlobalUtils::CheckAlignment(class CPoint,class CBasePane __near *,int,class CDockingManager const __near *,int,unsigned long __near &,unsigned long,struct tagRECT const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CGlobalUtils::CheckAlignment(
        CGlobalUtils *this,
        CPoint point,
        CBasePane *pBar,
        int nSensitivity,
        CDockingManager *pDockManager,
        int bOuterEdge,
        unsigned int *dwAlignment,
        __int16 dwEnabledDockBars,
        const tagRECT *lpRectBounds)
{
  CDockingManager *DockingManager; // eax
  HWND Parent; // eax
  CWnd *v11; // eax
  _DWORD *v12; // eax
  CObject *v13; // esi
  CObject_vtbl *v14; // eax
  bool v15; // zf
  CSmartDockingStandaloneGuide::SDMarkerPlace v16; // eax
  __int32 v17; // eax
  __int32 v18; // eax
  int v20; // esi
  BOOL (__stdcall *v21)(const RECT *, POINT); // edi
  unsigned int v22; // eax
  int right; // eax
  int nTabAreaBottomHeight; // [esp+Ch] [ebp-44h]
  int bSmartDocking; // [esp+10h] [ebp-40h]
  CSmartDockingStandaloneGuide::SDMarkerPlace nHilitedSide; // [esp+14h] [ebp-3Ch]
  int nCaptionHeight; // [esp+18h] [ebp-38h]
  CRect rectTabAreaTop; // [esp+1Ch] [ebp-34h] BYREF
  CRect rectBounds; // [esp+2Ch] [ebp-24h] BYREF
  CRect rectToCheck; // [esp+3Ch] [ebp-14h] BYREF

  nHilitedSide = sdNONE;
  DockingManager = pDockManager;
  bSmartDocking = 0;
  if ( pDockManager != nullptr
    || pBar != nullptr
    && (Parent = GetParent(hWnd: pBar->m_hWnd),
        v11 = CWnd::FromHandle(hWnd: Parent),
        (DockingManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v11)) != nullptr) )
  {
    v12 = &DockingManager->m_pSDManager->__vftable;
    if ( v12 != nullptr && v12[2] != 0 && v12[1] != 0 )
    {
      bSmartDocking = 1;
      nHilitedSide = v12[64];
    }
  }
  memset(&rectBounds, 0, sizeof(rectBounds));
  if ( pBar != nullptr )
  {
    GetWindowRect(hWnd: pBar->m_hWnd, lpRect: &rectBounds);
  }
  else
  {
    if ( lpRectBounds == nullptr )
      return 0;
    CopyRect(lprcDst: &rectBounds, lprcSrc: lpRectBounds);
  }
  nCaptionHeight = 0;
  nTabAreaBottomHeight = 0;
  v13 = AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: pBar);
  if ( v13 != nullptr )
  {
    nCaptionHeight = ((int (__thiscall *)(CObject *))v13->__vftable[34].Serialize)(a1: v13);
    v14 = v13->__vftable;
    memset(&rectTabAreaTop, 0, sizeof(rectTabAreaTop));
    memset(&rectToCheck, 0, sizeof(rectToCheck));
    ((void (__thiscall *)(CObject *, CRect *, CRect *))v14[67].Serialize)(
      a1: v13,
      a2: &rectTabAreaTop,
      a3: &rectToCheck);
    nTabAreaBottomHeight = rectToCheck.bottom - rectToCheck.top;
  }
  if ( bOuterEdge == 0 )
  {
    if ( bSmartDocking != 0 )
    {
      v16 = nHilitedSide - 4;
      v15 = nHilitedSide == sdCLEFT;
      goto LABEL_17;
    }
    v20 = nSensitivity;
    v21 = PtInRect;
    rectToCheck.left = rectBounds.left - nSensitivity;
    rectToCheck.top = rectBounds.top - nSensitivity;
    rectToCheck.bottom = nSensitivity + nCaptionHeight + rectBounds.top;
    rectToCheck.right = nSensitivity + rectBounds.right;
    if ( PtInRect(lprc: &rectToCheck, pt: point.tagPOINT) )
    {
      v22 = 0x2000;
      if ( (dwEnabledDockBars & 0x2000) != 0 )
        goto LABEL_28;
    }
    rectToCheck.right = nSensitivity + rectBounds.left;
    rectToCheck.bottom = nSensitivity + rectBounds.bottom;
    if ( PtInRect(lprc: &rectToCheck, pt: point.tagPOINT) )
    {
      v22 = 4096;
      if ( (dwEnabledDockBars & 0x1000) != 0 )
        goto LABEL_28;
    }
    rectToCheck.left = rectBounds.left - nSensitivity;
    rectToCheck.top = rectBounds.bottom - nTabAreaBottomHeight - nSensitivity;
    rectToCheck.bottom = nSensitivity + rectBounds.bottom;
    rectToCheck.right = nSensitivity + rectBounds.right;
    if ( PtInRect(lprc: &rectToCheck, pt: point.tagPOINT) )
    {
      v22 = 0x8000;
      if ( dwEnabledDockBars < 0 )
      {
LABEL_28:
        *dwAlignment = v22;
        return 1;
      }
    }
    right = rectBounds.right - nSensitivity;
LABEL_34:
    rectToCheck.left = right;
    rectToCheck.top = rectBounds.top - v20;
    if ( !v21(lprc: &rectToCheck, pt: point.tagPOINT) )
      return 0;
    v22 = 0x4000;
    if ( (dwEnabledDockBars & 0x4000) == 0 )
      return 0;
    goto LABEL_28;
  }
  if ( bSmartDocking == 0 )
  {
    v20 = nSensitivity;
    v21 = PtInRect;
    rectToCheck.left = rectBounds.left - nSensitivity;
    rectToCheck.top = rectBounds.top - nSensitivity;
    rectToCheck.bottom = rectBounds.top;
    rectToCheck.right = nSensitivity + rectBounds.right;
    if ( PtInRect(lprc: &rectToCheck, pt: point.tagPOINT) )
    {
      v22 = 0x2000;
      if ( (dwEnabledDockBars & 0x2000) != 0 )
        goto LABEL_28;
    }
    rectToCheck.right = rectBounds.left;
    rectToCheck.bottom = nSensitivity + rectBounds.bottom;
    if ( PtInRect(lprc: &rectToCheck, pt: point.tagPOINT) )
    {
      v22 = 4096;
      if ( (dwEnabledDockBars & 0x1000) != 0 )
        goto LABEL_28;
    }
    rectToCheck.left = rectBounds.left - nSensitivity;
    rectToCheck.top = rectBounds.bottom;
    rectToCheck.bottom = nSensitivity + rectBounds.bottom;
    rectToCheck.right = nSensitivity + rectBounds.right;
    if ( PtInRect(lprc: &rectToCheck, pt: point.tagPOINT) )
    {
      v22 = 0x8000;
      if ( dwEnabledDockBars < 0 )
        goto LABEL_28;
    }
    right = rectBounds.right;
    goto LABEL_34;
  }
  v16 = nHilitedSide;
  v15 = nHilitedSide == sdLEFT;
LABEL_17:
  if ( v15 )
  {
    *dwAlignment = 4096;
    return 1;
  }
  v17 = v16 - 1;
  if ( v17 == 0 )
  {
    *dwAlignment = 0x4000;
    return 1;
  }
  v18 = v17 - 1;
  if ( v18 == 0 )
  {
    *dwAlignment = 0x2000;
    return 1;
  }
  if ( v18 == 1 )
  {
    *dwAlignment = 0x8000;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103908B0
// Name: public: int CGlobalUtils::GetPaneAndAlignFromPoint(class CPaneContainerManager __near &,class CPoint,class CDockablePane __near * __near *,unsigned long __near &,int __near &,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CGlobalUtils::GetPaneAndAlignFromPoint(
        CGlobalUtils *this,
        CPaneContainerManager *barContainerManager,
        CPoint pt,
        CDockablePane **ppTargetControlBar,
        unsigned int *dwAlignment,
        int *bTabArea,
        int *bCaption)
{
  int v7; // eax
  CDockablePane *v8; // eax

  if ( ppTargetControlBar == nullptr )
    AfxThrowInvalidArgException();
  *ppTargetControlBar = nullptr;
  v7 = ((int (__thiscall *)(CPaneContainerManager *, int, int, CDockablePane **))barContainerManager->CheckForMiniFrameAndCaption)(
         a1: barContainerManager,
         a2: pt.x,
         a3: pt.y,
         a4: ppTargetControlBar);
  *bCaption = v7;
  if ( v7 == 0 )
  {
    v8 = (CDockablePane *)((int (__thiscall *)(CPaneContainerManager *, int, int, int, int, int *, int *))barContainerManager->PaneFromPoint)(
                            a1: barContainerManager,
                            a2: pt.x,
                            a3: pt.y,
                            a4: CDockingManager::m_nDockSensitivity,
                            a5: 1,
                            a6: bTabArea,
                            a7: bCaption);
    *ppTargetControlBar = v8;
    if ( *bCaption != 0 || *bTabArea != 0 )
    {
      if ( v8 != nullptr )
        return 1;
      goto LABEL_9;
    }
    if ( v8 == nullptr )
    {
LABEL_9:
      ((void (__thiscall *)(CPaneContainerManager *, int, int, int, _DWORD, int *, int *))barContainerManager->PaneFromPoint)(
        a1: barContainerManager,
        a2: pt.x,
        a3: pt.y,
        a4: CDockingManager::m_nDockSensitivity,
        a5: 0,
        a6: bTabArea,
        a7: bCaption);
      return 1;
    }
    if ( CGlobalUtils::CheckAlignment(
           this: &afxGlobalUtils,
           point: pt,
           pBar: &v8->CPane,
           nSensitivity: CDockingManager::m_nDockSensitivity,
           pDockManager: nullptr,
           bOuterEdge: 0,
           dwAlignment,
           dwEnabledDockBars: 61440,
           lpRectBounds: nullptr) == 0 )
      *ppTargetControlBar = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1039095F
// Name: public: struct HICON__ __near * CGlobalUtils::GetWndIcon(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HICON__ *__thiscall CGlobalUtils::GetWndIcon(CGlobalUtils *this, CWnd *pWnd)
{
  HWND__ *m_hWnd; // eax
  HICON__ *Icon; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v6; // eax
  struct _IMAGELIST *v7; // [esp-Ch] [ebp-30h]
  struct _IMAGELIST *m_hImageList; // [esp-4h] [ebp-28h]
  CImageList il; // [esp+10h] [ebp-14h] BYREF
  int v10; // [esp+20h] [ebp-4h]

  if ( pWnd == nullptr )
    return nullptr;
  m_hWnd = pWnd->m_hWnd;
  if ( m_hWnd == nullptr )
    return nullptr;
  Icon = (HICON__ *)SendMessageA(hWnd: m_hWnd, Msg: 0x7Fu, wParam: 0, lParam: 0);
  if ( Icon == nullptr )
  {
    Icon = (HICON__ *)SendMessageA(hWnd: pWnd->m_hWnd, Msg: 0x7Fu, wParam: 1u, lParam: 0);
    if ( Icon == nullptr )
      goto LABEL_9;
    CImageList::CImageList(this: &il);
    v10 = 0;
    CImageList::Create(this: &il, cx: 16, cy: 16, nFlags: 0x21u, nInitial: 0, nGrow: 1);
    CImageList::Add(this: &il, hIcon: Icon);
    m_hImageList = il.m_hImageList;
    ModuleState = AfxGetModuleState();
    if ( CComCtlWrapper::_ImageList_GetImageCount(
           this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
           himl: m_hImageList) == 1 )
    {
      v7 = il.m_hImageList;
      v6 = AfxGetModuleState();
      Icon = CComCtlWrapper::_ImageList_GetIcon(
               this: *(CComCtlWrapper **)v6->m_pDllIsolationWrappers,
               himl: v7,
               i: 0,
               flags: 0);
    }
    v10 = -1;
    CImageList::~CImageList(this: &il);
    if ( Icon == nullptr )
    {
LABEL_9:
      Icon = (HICON__ *)GetClassLongA(hWnd: pWnd->m_hWnd, nIndex: -34);
      if ( Icon == nullptr )
        return (HICON__ *)GetClassLongA(hWnd: pWnd->m_hWnd, nIndex: -14);
    }
  }
  return Icon;
}

//------------------------------------------------------------------------------
// Address: 0x10390A35
// Name: public: void CGlobalUtils::CalcExpectedDockedRect(class CPaneContainerManager __near &,class CWnd __near *,class CPoint,class CRect __near &,int __near &,class CDockablePane __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CGlobalUtils::CalcExpectedDockedRect(
        CGlobalUtils *this,
        CPaneContainerManager *barContainerManager,
        CDockablePane *pWndToDock,
        CPoint ptMouse,
        CRect *rectResult,
        int *bDrawTab,
        CBasePane **ppTargetBar)
{
  CDockablePane *v7; // ebx
  int IsKindOf; // eax
  CObject *v9; // eax
  CPane *v10; // eax
  CBasePane *v11; // ecx
  unsigned int v12; // eax
  CBasePane *v13; // ecx
  unsigned int v14; // eax
  CBasePane *v15; // ecx
  BOOL v16; // ebx
  unsigned int v17; // eax
  BOOL v18; // eax
  CBasePane *v19; // ebx
  unsigned int v20; // eax
  CBasePane_vtbl *v21; // edx
  int v22; // eax
  BOOL v23; // eax
  CBasePane *v24; // eax
  unsigned int v25; // eax
  CRect *v26; // edi
  HWND m_hWnd; // [esp-8h] [ebp-78h]
  CWnd *v28; // [esp-4h] [ebp-74h]
  unsigned int dwSliderStyle; // [esp+Ch] [ebp-64h] BYREF
  CRect *v30; // [esp+10h] [ebp-60h]
  unsigned int dwTargetEnabledAlign; // [esp+14h] [ebp-5Ch]
  unsigned int dwAlignment; // [esp+18h] [ebp-58h] BYREF
  int bTabArea; // [esp+1Ch] [ebp-54h] BYREF
  int bCaption; // [esp+20h] [ebp-50h] BYREF
  CPaneContainerManager *v35; // [esp+24h] [ebp-4Ch]
  unsigned int dwTargetCurrentAlign; // [esp+28h] [ebp-48h]
  CWnd *v37; // [esp+2Ch] [ebp-44h]
  CGlobalUtils *v38; // [esp+30h] [ebp-40h]
  int *v39; // [esp+34h] [ebp-3Ch]
  CPane *pBar; // [esp+38h] [ebp-38h]
  CRect rectSlider; // [esp+3Ch] [ebp-34h] BYREF
  CRect rectOriginal; // [esp+4Ch] [ebp-24h] BYREF
  CRect rectInserted; // [esp+5Ch] [ebp-14h] BYREF

  v7 = pWndToDock;
  v38 = this;
  v35 = barContainerManager;
  v37 = &pWndToDock->CPane;
  v30 = rectResult;
  v39 = bDrawTab;
  if ( ppTargetBar == nullptr )
    AfxThrowInvalidArgException();
  *bDrawTab = 0;
  dwAlignment = 4096;
  bTabArea = 0;
  bCaption = 0;
  *ppTargetBar = nullptr;
  SetRectEmpty(lprc: rectResult);
  if ( GetKeyState(nVirtKey: 17) >= 0
    && CGlobalUtils::GetPaneAndAlignFromPoint(
         this: v38,
         barContainerManager: v35,
         pt: ptMouse,
         ppTargetControlBar: (CDockablePane **)ppTargetBar,
         &dwAlignment,
         &bTabArea,
         &bCaption) != 0
    && *ppTargetBar != nullptr )
  {
    IsKindOf = CObject::IsKindOf(this: &pWndToDock->CPane, pClass: &CPaneFrameWnd::classCPaneFrameWnd);
    v28 = &pWndToDock->CPane;
    if ( IsKindOf != 0 )
    {
      v9 = AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: &pWndToDock->CPane);
      v28 = (CWnd *)((int (__thiscall *)(CObject *))v9->__vftable[35].dtr_CObject)(a1: v9);
    }
    v10 = (CPane *)AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: v28);
    v11 = *ppTargetBar;
    pBar = v10;
    if ( v11 != nullptr )
    {
      v12 = v11->GetEnabledAlignment(this: v11);
      v13 = *ppTargetBar;
      dwTargetEnabledAlign = v12;
      v14 = v13->GetCurrentAlignment(this: v13);
      v15 = *ppTargetBar;
      dwTargetCurrentAlign = v14;
      v16 = v15->GetParentMiniFrame(this: v15, a2: 0) != nullptr;
      if ( pBar != nullptr )
      {
        if ( pBar->GetEnabledAlignment(this: pBar) != dwTargetEnabledAlign && v16 )
          return;
        v17 = pBar->GetEnabledAlignment(this: pBar);
        if ( (v17 & dwTargetCurrentAlign) == 0 && !v16 )
          return;
      }
      v7 = (CDockablePane *)v37;
    }
    if ( bTabArea == 0 && bCaption == 0 )
      goto LABEL_33;
    v18 = *ppTargetBar != nullptr;
    *v39 = v18;
    if ( v18 )
    {
      v23 = false;
      if ( (*ppTargetBar)->CanBeAttached(this: *ppTargetBar) != 0
        && CGlobalUtils::CanBeAttached(this: v38, pWnd: &v7->CPane) != nullptr
        && pBar != nullptr )
      {
        v19 = *ppTargetBar;
        v20 = pBar->GetEnabledAlignment(this: pBar);
        v21 = v19->__vftable;
        dwTargetCurrentAlign = v20;
        v22 = v21->GetEnabledAlignment(this: v19);
        v7 = (CDockablePane *)v37;
        if ( v22 == dwTargetCurrentAlign )
          v23 = true;
      }
      *v39 = v23;
      if ( v23 )
      {
LABEL_33:
        if ( *ppTargetBar != nullptr
          && ((*ppTargetBar)->GetParentMiniFrame(this: *ppTargetBar, a2: 0) != nullptr
           && CGlobalUtils::CanPaneBeInFloatingMultiPaneFrameWnd(this: v38, pWnd: &v7->CPane) == nullptr
           || *ppTargetBar != nullptr
           && CObject::IsKindOf(this: &v7->CPane, pClass: &CBasePane::classCBasePane) != 0
           && (*ppTargetBar)->CanAcceptPane(this: *ppTargetBar, a2: v7) == 0)
          || (v24 = *ppTargetBar,
              memset(&rectOriginal, 0, sizeof(rectOriginal)),
              GetWindowRect(hWnd: v24->m_hWnd, lpRect: &rectOriginal),
              *ppTargetBar == (CBasePane *)v7)
          || CObject::IsKindOf(this: &v7->CPane, pClass: &CPaneFrameWnd::classCPaneFrameWnd) != 0
          && (CDockablePane *)(*ppTargetBar)->GetParentMiniFrame(this: *ppTargetBar, a2: 0) == v7 )
        {
          *v39 = 0;
        }
        else
        {
          m_hWnd = v7->m_hWnd;
          memset(&rectInserted, 0, sizeof(rectInserted));
          memset(&rectSlider, 0, sizeof(rectSlider));
          GetWindowRect(hWnd: m_hWnd, lpRect: &rectInserted);
          if ( pBar != nullptr )
          {
            v25 = pBar->GetEnabledAlignment(this: pBar);
            if ( (v25 & dwAlignment) != 0 || CDockingManager::m_bIgnoreEnabledAlignment != 0 )
            {
              CPaneContainerManager::CalcRects(
                this: v35,
                &rectOriginal,
                &rectInserted,
                &rectSlider,
                &dwSliderStyle,
                dwAlignment,
                __formal: 0,
                sizeMinInserted: 0);
              v26 = v30;
              v30->left = rectInserted.left;
              v26 = (CRect *)((char *)v26 + 4);
              v26->left = rectInserted.top;
              v26 = (CRect *)((char *)v26 + 4);
              v26->left = rectInserted.right;
              v26->top = rectInserted.bottom;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10390CF2
// Name: protected: CDocItem::CDocItem(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDocItem *__thiscall CDocItem::CDocItem(CDocItem *this)
{
  CCmdTarget::CCmdTarget(this);
  this->m_pDocument = nullptr;
  this->__vftable = (CDocItem_vtbl *)&CDocItem::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10390D0A
// Name: public: virtual struct CRuntimeClass __near * CDocItem::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CDocItem::GetRuntimeClass(CDocItem *this)
{
  return &CDocItem::classCDocItem;
}

//------------------------------------------------------------------------------
// Address: 0x103989B2
// Name: protected: virtual void CVSListBoxEditCtrl::OnBrowse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxEditCtrl::OnBrowse(CVSListBoxEditCtrl *this)
{
  CVSListBoxBase *m_pParentList; // ecx
  HWND m_hWnd; // esi

  m_pParentList = this->m_pParentList;
  if ( m_pParentList != nullptr )
  {
    m_hWnd = m_pParentList->m_hWnd;
    m_pParentList->OnBrowse(this: m_pParentList);
    if ( IsWindow(hWnd: m_hWnd) )
      SetFocus(hWnd: m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10398A05
// Name: protected: void CVSListBoxEditCtrl::OnWindowPosChanging(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxEditCtrl::OnWindowPosChanging(CVSListBoxEditCtrl *this, tagWINDOWPOS *lpwndpos)
{
  if ( this->m_bLocked != 0 )
    lpwndpos->flags |= 1u;
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10398A23
// Name: protected: void CVSListBoxEditCtrl::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxEditCtrl::OnKeyDown(
        CVSListBoxEditCtrl *this,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  if ( nChar == 9
    && this->m_pParentList->GetCount(this: this->m_pParentList) == 1
    && this->m_pParentList->m_bNewItem != 0 )
  {
    CWnd::DefWindowProcA(this, nMsg: 0x100u, wParam: 0xDu, lParam: nRepCnt | (nFlags << 16));
  }
  else
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10398A7B
// Name: protected: void CVSListBoxBase::AdjustLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxBase::AdjustLayout(CVSListBoxBase *this)
{
  HWND__ *v2; // eax
  CFont *v3; // edi
  int cy; // ecx
  CList<CMFCButton *,CMFCButton *>::CNode *m_pNodeTail; // edi
  int v6; // eax
  int right; // ecx
  int cx; // eax
  int v9; // esi
  CWnd *data; // ecx
  HWND Parent; // eax
  CWnd *v12; // eax
  CFont *Font; // eax
  CFont *v14; // esi
  HWND__ *m_hWnd; // [esp-8h] [ebp-8Ch]
  CClientDC v16; // [esp+10h] [ebp-74h] BYREF
  CWnd *v17; // [esp+24h] [ebp-60h]
  CWnd *v18; // [esp+28h] [ebp-5Ch]
  tagTEXTMETRICA tm; // [esp+2Ch] [ebp-58h] BYREF
  tagRECT Rect; // [esp+64h] [ebp-20h] BYREF
  int v21; // [esp+80h] [ebp-4h]

  if ( this != nullptr && this->m_hWnd != nullptr )
  {
    v2 = this->GetListHwnd(this);
    v18 = CWnd::FromHandle(hWnd: v2);
    if ( v18 != nullptr )
    {
      m_hWnd = this->m_hWnd;
      memset(&Rect, 0, sizeof(Rect));
      GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
      this->m_rectCaption = (CRect)Rect;
      CClientDC::CClientDC(this: &v16, pWnd: this);
      v3 = nullptr;
      v21 = 0;
      if ( this == (CVSListBoxBase *)-248 || this->m_font.m_hObject == nullptr )
      {
        Parent = GetParent(hWnd: this->m_hWnd);
        v12 = CWnd::FromHandle(hWnd: Parent);
        Font = CWnd::GetFont(this: v12);
        v14 = Font;
        if ( Font != nullptr )
        {
          SendMessageA(hWnd: v18->m_hWnd, Msg: 0x30u, wParam: (WPARAM)Font->m_hObject, lParam: 0);
          v3 = CDC::SelectObject(this: &v16, pFont: v14);
          if ( v3 == nullptr )
LABEL_19:
            AfxThrowInvalidArgException();
        }
      }
      else
      {
        v3 = CDC::SelectObject(this: &v16, pFont: &this->m_font);
        SendMessageA(hWnd: v18->m_hWnd, Msg: 0x30u, wParam: (WPARAM)this->m_font.m_hObject, lParam: 0);
      }
      GetTextMetricsA(hdc: v16.m_hAttribDC, lptm: &tm);
      if ( v3 != nullptr )
        CDC::SelectObject(this: &v16, pFont: v3);
      cy = this->m_sizeButton.cy;
      if ( 4 * tm.tmHeight / 3 > cy )
        cy = 4 * tm.tmHeight / 3;
      m_pNodeTail = this->m_lstButtons.m_pNodeTail;
      v6 = cy + this->m_rectCaption.top;
      right = Rect.right;
      this->m_rectCaption.bottom = v6;
      cx = this->m_sizeButton.cx;
      v9 = right - cx - 1;
      if ( m_pNodeTail != nullptr )
      {
        do
        {
          data = m_pNodeTail->data;
          m_pNodeTail = m_pNodeTail->pPrev;
          v17 = data;
          if ( data == nullptr )
            goto LABEL_19;
          CWnd::MoveWindow(
            this: v17,
            x: v9,
            y: Rect.top + 1,
            nWidth: cx,
            nHeight: this->m_rectCaption.bottom - this->m_rectCaption.top - 2,
            bRepaint: true);
          cx = this->m_sizeButton.cx;
          v9 -= cx;
        }
        while ( m_pNodeTail != nullptr );
        right = Rect.right;
      }
      CWnd::MoveWindow(
        this: v18,
        x: Rect.left,
        y: Rect.top + this->m_rectCaption.bottom - this->m_rectCaption.top,
        nWidth: right - Rect.left,
        nHeight: Rect.bottom + this->m_rectCaption.top - this->m_rectCaption.bottom - Rect.top,
        bRepaint: true);
      this->OnSizeList(this);
      v21 = -1;
      CClientDC::~CClientDC(this: &v16);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10398C5C
// Name: protected: virtual int CVSListBoxBase::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CVSListBoxBase::OnCommand(CVSListBoxBase *this, unsigned int wParam, HWND__ *lParam)
{
  CList<CMFCButton *,CMFCButton *>::CNode *m_pNodeHead; // eax
  int i; // edi
  CMFCButton *data; // ecx
  HWND__ *v8; // eax
  CWnd *v9; // eax

  m_pNodeHead = this->m_lstButtons.m_pNodeHead;
  for ( i = 0; ; ++i )
  {
    if ( m_pNodeHead == nullptr )
      return CWnd::OnCommand(this, wParam, lParam);
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == nullptr )
      AfxThrowInvalidArgException();
    if ( data->m_hWnd == lParam )
      break;
  }
  v8 = this->GetListHwnd(this);
  v9 = CWnd::FromHandle(hWnd: v8);
  if ( v9 != nullptr )
    CWnd::SetFocus(this: v9);
  this->OnClickButton(this, a2: i);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10398CC5
// Name: protected: long CVSListBoxBase::OnGetFont(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFont *__thiscall CVSListBoxBase::OnGetFont(CVSListBoxBase *this, unsigned int __formal, unsigned int __formala)
{
  CFont *result; // eax

  result = &this->m_font;
  if ( this != (CVSListBoxBase *)-248 )
    return (CFont *)this->m_font.m_hObject;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10398CD5
// Name: protected: long CVSListBoxBase::OnSetFont(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CVSListBoxBase::OnSetFont(CVSListBoxBase *this, void *wParam, int lParam)
{
  int v4; // ebx
  CGdiObject *v5; // eax
  HFONT v6; // eax
  HWND__ *m_hWnd; // eax
  tagLOGFONTA lf; // [esp+Ch] [ebp-40h] BYREF

  v4 = CWnd::Default(this);
  v5 = CGdiObject::FromHandle(h: wParam);
  if ( v5 != nullptr )
  {
    GetObjectA(h: v5->m_hObject, c: 60, pv: &lf);
    CGdiObject::DeleteObject(this: &this->m_font);
    v6 = CreateFontIndirectA(lplf: &lf);
    CGdiObject::Attach(this: &this->m_font, hObject: v6);
  }
  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  if ( IsWindow(hWnd: m_hWnd) )
  {
    CVSListBoxBase::AdjustLayout(this);
    if ( lParam != 0 )
    {
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10398D7C
// Name: public: int CVSListBoxBase::GetButtonNum(unsigned int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CVSListBoxBase::GetButtonNum(CVSListBoxBase *this, unsigned int uiID)
{
  bool v2; // zf
  CMap<int,int,unsigned int,unsigned int> *p_m_mapButtonIDs; // esi
  int iNum; // [esp+4h] [ebp-Ch] BYREF
  __POSITION *pos; // [esp+8h] [ebp-8h] BYREF
  unsigned int uiButtonID; // [esp+Ch] [ebp-4h] BYREF

  v2 = this->m_mapButtonIDs.m_nCount == 0;
  pos = (__POSITION *)-(this->m_mapButtonIDs.m_nCount != 0);
  if ( v2 )
    return -1;
  p_m_mapButtonIDs = &this->m_mapButtonIDs;
  while ( 1 )
  {
    iNum = -1;
    uiButtonID = 0;
    CMap<unsigned int,unsigned int,HMENU__ *,HMENU__ *>::GetNextAssoc(
      this: (CMap<unsigned int,unsigned int,HMENU__ *,HMENU__ *> *)p_m_mapButtonIDs,
      rNextPosition: &pos,
      rKey: (unsigned int *)&iNum,
      rValue: (HMENU__ **)&uiButtonID);
    if ( uiButtonID == uiID )
      break;
    if ( pos == nullptr )
      return -1;
  }
  return iNum;
}

//------------------------------------------------------------------------------
// Address: 0x10398DD0
// Name: protected: void CVSListBoxBase::OnEnable(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxBase::OnEnable(CVSListBoxBase *this, int bEnable)
{
  CList<CMFCButton *,CMFCButton *>::CNode *m_pNodeTail; // esi
  CWnd *data; // ecx
  BOOL v5; // eax
  HWND__ *v6; // eax
  CWnd *v7; // eax

  CWnd::Default(this);
  m_pNodeTail = this->m_lstButtons.m_pNodeTail;
  while ( m_pNodeTail != nullptr )
  {
    data = m_pNodeTail->data;
    m_pNodeTail = m_pNodeTail->pPrev;
    v5 = bEnable == 0 || this->m_bGrayDisabledButtons != 0;
    data[1].m_pModuleState = (AFX_MODULE_STATE *)v5;
    CWnd::EnableWindow(this: data, bEnable);
  }
  v6 = this->GetListHwnd(this);
  v7 = CWnd::FromHandle(hWnd: v6);
  if ( v7 != nullptr )
    CWnd::EnableWindow(this: v7, bEnable);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x10398E47
// Name: protected: virtual class CWnd __near * CVSListBox::OnCreateList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CListCtrl *__thiscall CVSListBox::OnCreateList(CVSListBox *this)
{
  CWnd *v2; // eax
  CListCtrl *v3; // edi
  CListCtrl *v4; // ecx
  tagRECT rc; // [esp+14h] [ebp-20h] BYREF
  int v7; // [esp+30h] [ebp-4h]

  if ( this == nullptr || this->m_hWnd == nullptr || this->m_pWndList != nullptr )
    return nullptr;
  memset(&rc, 0, sizeof(rc));
  SetRectEmpty(lprc: &rc);
  v2 = (CWnd *)operator new(nSize: 0x74u);
  v3 = (CListCtrl *)v2;
  v7 = 0;
  if ( v2 != nullptr )
  {
    CWnd::CWnd(this: v2);
    v3->__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v7 = -1;
  this->m_pWndList = v4;
  CWnd::CreateEx(
    this: v4,
    dwExStyle: 0x200u,
    lpszClassName: "SysListView32",
    lpszWindowName: &var,
    dwStyle: 0x5000420Du,
    rect: &rc,
    pParentWnd: this,
    nID: (HMENU__ *)1,
    lpParam: nullptr);
  SendMessageA(hWnd: this->m_pWndList->m_hWnd, Msg: 0x1036u, wParam: 0, lParam: 32);
  CListCtrl::InsertColumn(
    this: this->m_pWndList,
    nCol: 0,
    lpszColumnHeading: (char *)&var,
    nFormat: 0,
    nWidth: -1,
    nSubItem: -1);
  return this->m_pWndList;
}

//------------------------------------------------------------------------------
// Address: 0x10398F16
// Name: public: virtual int CVSListBox::AddItem(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &,unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __thiscall CVSListBox::AddItem(
        CVSListBox *this,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strText,
        unsigned int dwData,
        LRESULT iIndex)
{
  CListCtrl *m_pWndList; // eax
  LRESULT inserted; // ebx

  if ( this == nullptr )
    return -1;
  if ( this->m_hWnd == nullptr )
    return -1;
  m_pWndList = this->m_pWndList;
  if ( m_pWndList == nullptr )
    return -1;
  if ( iIndex < 0 )
    iIndex = SendMessageA(hWnd: m_pWndList->m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  inserted = CListCtrl::InsertItem(
               this: this->m_pWndList,
               nMask: 3u,
               nItem: iIndex,
               lpszItem: strText->m_pszData,
               nState: 0,
               nStateMask: 0,
               nImage: -1,
               lParam: 0);
  CListCtrl::SetItem(
    this: this->m_pWndList,
    nItem: inserted,
    nSubItem: 0,
    nMask: 4u,
    lpszItem: nullptr,
    nImage: 0,
    nState: 0,
    nStateMask: 0,
    lParam: dwData);
  if ( inserted == 0 )
    this->SelectItem(this, a2: 0);
  return inserted;
}

//------------------------------------------------------------------------------
// Address: 0x10398F9D
// Name: public: virtual int CVSListBox::GetCount(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __thiscall CVSListBox::GetCount(CVSListBox *this)
{
  CListCtrl *m_pWndList; // ecx

  if ( this != nullptr && this->m_hWnd != nullptr && (m_pWndList = this->m_pWndList) != nullptr )
    return SendMessageA(hWnd: m_pWndList->m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10398FC8
// Name: public: virtual unsigned long CVSListBox::GetItemData(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CVSListBox::GetItemData(CVSListBox *this, int iIndex)
{
  CListCtrl *m_pWndList; // ecx

  if ( this != nullptr && this->m_hWnd != nullptr && (m_pWndList = this->m_pWndList) != nullptr )
    return CListCtrl::GetItemData(this: m_pWndList, nItem: iIndex);
  else
    return 0;
}
