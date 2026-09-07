// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/searchreplacedlg.cpp
// Functions: 17
// ============================================================

#include "hammer\searchreplacedlg.h"

//------------------------------------------------------------------------------
// Address: 0x100FEFF0
// Name: protected: virtual void CSearchReplaceDlg::OnCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSearchReplaceDlg::OnCancel(CMessageWnd *this)
{
  CWnd::ShowWindow(this, nCmdShow: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100FF000
// Name: bool MatchString(char const __near *,struct FindObject_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl MatchString(char *pszString, FindObject_t *FindObject)
{
  int v3; // eax
  unsigned __int8 *m_pszData; // [esp-4h] [ebp-4h]

  if ( FindObject->bWholeWord )
  {
    if ( FindObject->bCaseSensitive )
      return strcmp(pszString, FindObject->strFindText.m_pszData) == 0;
    else
      return _V_stricmp(s1: pszString, s2: FindObject->strFindText.m_pszData) == 0;
  }
  else
  {
    m_pszData = (unsigned __int8 *)FindObject->strFindText.m_pszData;
    if ( FindObject->bCaseSensitive )
    {
      strstr(str1: (unsigned __int8 *)pszString, str2: m_pszData);
      return v3 != 0;
    }
    else
    {
      return V_stristr(pStr: pszString, pSearch: (const char *)m_pszData) != nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF0B0
// Name: bool ReplaceString(char __near *,char const __near *,struct FindObject_t __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ReplaceString(char *pszOut, char *pszIn, FindObject_t *FindObject, const char *pszReplace)
{
  const char *v5; // eax
  int v6; // esi
  unsigned int v7; // kr00_4
  unsigned int v8; // kr04_4
  const char *v9; // ecx
  char v10; // al
  unsigned __int8 *m_pszData; // [esp-4h] [ebp-Ch]

  if ( !FindObject->bWholeWord )
    goto LABEL_7;
  if ( FindObject->bCaseSensitive && strcmp(pszIn, FindObject->strFindText.m_pszData) == 0 )
  {
    strcpy(pszOut, pszReplace);
    return 1;
  }
  if ( _V_stricmp(s1: pszIn, s2: FindObject->strFindText.m_pszData) != 0 )
  {
LABEL_7:
    m_pszData = (unsigned __int8 *)FindObject->strFindText.m_pszData;
    if ( FindObject->bCaseSensitive )
      strstr(str1: (unsigned __int8 *)pszIn, str2: m_pszData);
    else
      v5 = V_stristr(pStr: pszIn, pSearch: (const char *)m_pszData);
    if ( v5 != nullptr )
    {
      v6 = v5 - pszIn;
      strncpy(dest: (unsigned __int8 *)pszOut, source: (unsigned __int8 *)pszIn, count: v5 - pszIn);
      v7 = strlen(FindObject->strFindText.m_pszData);
      strcpy(&pszOut[v6], pszReplace);
      v8 = strlen(pszReplace);
      v9 = &pszIn[v6 + v7];
      do
      {
        v10 = *v9;
        v9[&pszOut[v8] - &pszIn[v7]] = *v9;
        ++v9;
      }
      while ( v10 != 0 );
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    strcpy(pszOut, pszReplace);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF1E0
// Name: public: int CSearchReplaceDlg::Create(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSearchReplaceDlg::Create(CSearchReplaceDlg *this, CWnd *pwndParent)
{
  return CDialog::Create(this, lpszTemplateName: (const char *)0x13A, pParentWnd: pwndParent);
}

//------------------------------------------------------------------------------
// Address: 0x100FF200
// Name: protected: virtual void CSearchReplaceDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSearchReplaceDlg::DoDataExchange(CSearchReplaceDlg *this, CDataExchange *pDX)
{
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x61D, value: &this->m_bVisiblesOnly);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x625, value: &this->m_bWholeWord);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x626, value: &this->m_bCaseSensitive);
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F1, value: &this->m_strFindText);
  DDX_Text(pDX, nIDC: (HWND__ *)0x620, value: &this->m_strReplaceText);
  DDX_Radio((HWND__ *)pDX, nIDC: (HWND__ *)0x622, value: (HWND__ **)&this->m_nFindIn);
}

//------------------------------------------------------------------------------
// Address: 0x100FF280
// Name: protected: virtual void CSearchReplaceDlg::OnShowWindow(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSearchReplaceDlg::OnShowWindow(CSearchReplaceDlg *this, int bShow, unsigned int nStatus)
{
  CWnd *DlgItem; // eax

  if ( bShow != 0 )
  {
    this->m_bNewSearch = true;
    DlgItem = CWnd::GetDlgItem(this, nID: 2);
    CWnd::SetWindowTextA(this: DlgItem, lpszString: "Cancel");
    this->m_nFindIn = 1;
    if ( CMapDoc::m_pMapDoc != nullptr && !CSelection::IsEmpty(this: CMapDoc::m_pMapDoc->m_pSelection) )
      this->m_nFindIn = 0;
    CWnd::UpdateData(this, bSaveAndValidate: 0);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FF2F0
// Name: public: CSearchReplaceDlg::CSearchReplaceDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CSearchReplaceDlg *__thiscall CSearchReplaceDlg::CSearchReplaceDlg(CSearchReplaceDlg *this, CWnd *pParent)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v4; // eax

  CDialog::CDialog(this, nIDTemplate: 0x13Au, pParentWnd: pParent);
  this->__vftable = (CSearchReplaceDlg_vtbl *)&CSearchReplaceDlg::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strFindText.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v4 = AfxGetStringManager();
  if ( v4 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strReplaceText.m_pszData = (char *)&v4->GetNilString(this: v4)[1];
  this->m_bNewSearch = true;
  this->m_bVisiblesOnly = 0;
  this->m_nFindIn = 1;
  this->m_bWholeWord = 0;
  this->m_bCaseSensitive = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FF3E0
// Name: public: virtual CSearchReplaceDlg::~CSearchReplaceDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSearchReplaceDlg::~CSearchReplaceDlg(CNewKeyValue *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax

  v2 = (volatile signed __int32 *)(this->m_Value.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->m_Key.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FF4B0
// Name: bool FindCheck(class CMapClass __near *,struct FindObject_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindCheck(CMapClass *pObject, FindObject_t *FindObject)
{
  char *v2; // ebx
  unsigned __int16 Inorder; // si
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // esi
  int nConnCount; // [esp+8h] [ebp-4h]

  v2 = (char *)__RTDynamicCast(
                 inptr: pObject,
                 VfDelta: 0,
                 SrcType: &CMapClass `RTTI Type Descriptor',
                 TargetType: &CMapEntity `RTTI Type Descriptor',
                 isReference: 0);
  if ( v2 == nullptr || FindObject->bVisiblesOnly && (*((_BYTE *)pObject + 180) & 2) == 0 )
    return 0;
  Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v2 + 220));
  if ( Inorder == 0xFFFF )
  {
LABEL_9:
    v7 = *((_DWORD *)v2 + 83);
    v8 = 0;
    for ( nConnCount = v7; v8 < v7; ++v8 )
    {
      v9 = *(_DWORD *)(*((_DWORD *)v2 + 80) + 4 * v8);
      if ( v9 != 0 )
      {
        if ( MatchString(pszString: (char *)(v9 + 516), FindObject)
          || MatchString(pszString: (char *)(v9 + 1032), FindObject) )
        {
          return 1;
        }
        v7 = nConnCount;
      }
    }
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v5 = *((_DWORD *)v2 + 56);
      v6 = 604 * Inorder;
      if ( v6 + v5 != -92 && MatchString(pszString: (char *)(v6 + v5 + 92), FindObject) )
        return 1;
      Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                  this: (CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v2 + 220),
                  i: Inorder);
      if ( Inorder == 0xFFFF )
        goto LABEL_9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF5C0
// Name: int FindReplace(class CMapEntity __near *,struct FindObject_t __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindReplace(CMapEntity *pEntity, FindObject_t *FindObject, const char *pszReplace)
{
  int j; // edi
  int v5; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  int v7; // eax
  CEntityConnection *v8; // esi
  CHAR *m_szParam; // esi
  char szNewValue[260]; // [esp+Ch] [ebp-10Ch] BYREF
  int nConnCount; // [esp+110h] [ebp-8h]
  int nReplacedCount; // [esp+114h] [ebp-4h]
  int i; // [esp+120h] [ebp+8h]

  nReplacedCount = 0;
  for ( j = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
        j != 0xFFFF;
        j = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                                i: j) )
  {
    v5 = (unsigned __int16)j;
    if ( &pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short> *)-92
      && ReplaceString(
           pszOut: szNewValue,
           pszIn: pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem.szValue,
           FindObject,
           pszReplace) != 0 )
    {
      m_pMemory = pEntity->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory;
      if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short> *)-12 )
      {
        pEntity->SetKeyValue(
          this: &pEntity->CEditGameClass,
          a2: (const char *)&m_pMemory[v5].m_Data.elem,
          a3: szNewValue);
        ++nReplacedCount;
      }
    }
  }
  v7 = 0;
  nConnCount = pEntity->m_Connections.m_Size;
  i = 0;
  if ( nConnCount > 0 )
  {
    do
    {
      v8 = pEntity->m_Connections.m_Memory.m_pMemory[v7];
      if ( v8 != nullptr )
      {
        if ( ReplaceString(pszOut: szNewValue, pszIn: v8->m_szTargetEntity, FindObject, pszReplace) != 0 )
        {
          CEntityConnection::SetTargetName(this: v8, pszName: szNewValue);
          ++nReplacedCount;
        }
        m_szParam = v8->m_szParam;
        if ( ReplaceString(pszOut: szNewValue, pszIn: m_szParam, FindObject, pszReplace) != 0 )
        {
          lstrcpynA(lpString1: m_szParam, lpString2: szNewValue, iMaxLength: 256);
          ++nReplacedCount;
        }
      }
      v7 = i + 1;
      i = v7;
    }
    while ( v7 < nConnCount );
  }
  return nReplacedCount;
}

//------------------------------------------------------------------------------
// Address: 0x100FF710
// Name: class CMapClass __near * FindNextObject(struct FindObject_t __near &)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl FindNextObject(FindObject_t *FindObject)
{
  CMapClass *result; // eax
  CMapClass *NextDescendent; // edi
  int nSelectionIndex; // edx

  do
  {
    result = nullptr;
    if ( FindObject->eFindIn == FindInWorld )
    {
      NextDescendent = CMapClass::GetNextDescendent(this: FindObject->pWorld, pos: (CMapClass *)&FindObject->WorldPos);
    }
    else
    {
      nSelectionIndex = FindObject->nSelectionIndex;
      if ( nSelectionIndex >= FindObject->SelectionList.m_Size )
        return result;
      NextDescendent = FindObject->SelectionList.m_Memory.m_pMemory[nSelectionIndex >> ((unsigned __int64)*((int *)&FindObject->SelectionList.m_Memory + 2) >> 27)][nSelectionIndex & ((32 * *((_DWORD *)&FindObject->SelectionList.m_Memory + 2)) >> 5)].m_pObject;
      FindObject->nSelectionIndex = nSelectionIndex + 1;
    }
  }
  while ( NextDescendent != nullptr && FindCheck(pObject: NextDescendent, FindObject) == 0 );
  return NextDescendent;
}

//------------------------------------------------------------------------------
// Address: 0x100FF790
// Name: private: void CSearchReplaceDlg::GetFindCriteria(struct FindObject_t __near &,class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSearchReplaceDlg::GetFindCriteria(CSearchReplaceDlg *this, FindObject_t *FindObject, CMapDoc *pDoc)
{
  FindObject_t *v3; // ebx
  CSearchReplaceDlg *v4; // esi
  bool v5; // zf
  const CUtlReferenceVector<CMapClass> *List; // edi
  int v7; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  CMapClass *v10; // edi
  int j; // esi
  const char *m_pszData; // edx
  volatile signed __int32 *v13; // edi
  CUtlReference<CMapClass> object; // [esp+Ch] [ebp-20h] BYREF
  CSearchReplaceDlg *v15; // [esp+18h] [ebp-14h]
  const CUtlReferenceVector<CMapClass> *pSelection; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+28h] [ebp-4h]
  FindObject_t *FindObjecta; // [esp+34h] [ebp+8h]
  int i; // [esp+38h] [ebp+Ch]

  v3 = FindObject;
  v4 = this;
  FindObject->pWorld = pDoc->m_pWorld;
  v5 = this->m_nFindIn == 0;
  v15 = this;
  if ( v5 )
  {
    FindObject->eFindIn = FindInSelection;
    CUtlReferenceVector<CMapClass>::RemoveAll(this: &FindObject->SelectionList);
    List = CSelection::GetList(this: pDoc->m_pSelection);
    v7 = 0;
    pSelection = List;
    for ( i = 0; v7 < List->m_Size; i = v7 )
    {
      m_pObject = List->m_Memory.m_pMemory[v7 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v7 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        object.m_pObject = List->m_Memory.m_pMemory[v7 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v7 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
        object.m_pNext = m_pObject->m_References.m_pHead;
        m_pHead = m_pObject->m_References.m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &object;
        object.m_pPrev = nullptr;
        m_pObject->m_References.m_pHead = &object;
      }
      v17 = 0;
      if ( object.m_pObject->IsGroup(this: object.m_pObject) )
      {
        v10 = object.m_pObject;
        for ( j = 0; j < v10->m_Children.m_Size; ++j )
          CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
            this: &FindObject->SelectionList,
            elem: FindObject->SelectionList.m_Size,
            src: &v10->m_Children.m_Memory.m_pMemory[j >> ((unsigned __int64)*((int *)&v10->m_Children.m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&v10->m_Children.m_Memory + 2)) >> 5)]);
        v7 = i;
        List = pSelection;
      }
      else
      {
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
          this: &FindObject->SelectionList,
          elem: FindObject->SelectionList.m_Size,
          src: &object);
      }
      v17 = -1;
      if ( object.m_pObject != nullptr )
      {
        if ( object.m_pPrev != nullptr )
        {
          object.m_pPrev->m_pNext = object.m_pNext;
          if ( object.m_pNext != nullptr )
            object.m_pNext->m_pPrev = object.m_pPrev;
        }
        else if ( object.m_pObject->m_References.m_pHead == &object )
        {
          object.m_pObject->m_References.m_pHead = object.m_pNext;
          if ( object.m_pNext != nullptr )
            object.m_pNext->m_pPrev = nullptr;
        }
        memset(&object, 0, sizeof(object));
      }
      ++v7;
    }
    v3 = FindObject;
    v4 = v15;
  }
  else
  {
    FindObject->eFindIn = FindInWorld;
  }
  m_pszData = v4->m_strFindText.m_pszData;
  v13 = (volatile signed __int32 *)(v3->strFindText.m_pszData - 16);
  if ( m_pszData - 16 != (const char *)v13 )
  {
    if ( *((int *)v13 + 3) >= 0 && *((_DWORD *)m_pszData - 4) == *v13 )
    {
      FindObjecta = (FindObject_t *)ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)m_pszData - 1);
      if ( _InterlockedDecrement(v13 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v13 + 4))(a1: v13);
      v3->strFindText.m_pszData = (char *)&FindObjecta->WorldPos.Stack[1];
    }
    else
    {
      ATL::CSimpleStringT<char,0>::SetString(
        this: &v3->strFindText,
        pszSrc: m_pszData,
        nLength: *((_DWORD *)m_pszData - 3));
    }
  }
  v3->bVisiblesOnly = v4->m_bVisiblesOnly == 1;
  v3->bWholeWord = v4->m_bWholeWord == 1;
  v3->bCaseSensitive = v4->m_bCaseSensitive == 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FF9E0
// Name: public: FindObject_t::FindObject_t(void)
// Source: json
//------------------------------------------------------------------------------
FindObject_t *__thiscall FindObject_t::FindObject_t(FindObject_t *this)
{
  CUtlReferenceVector<CMapClass> *p_SelectionList; // esi
  CAfxStringMgr *StringManager; // eax

  p_SelectionList = &this->SelectionList;
  this->SelectionList.m_Memory.m_pMemory = nullptr;
  this->SelectionList.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->SelectionList.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->SelectionList.m_Memory, nGrowSize: 0, nInitSize: 0);
  p_SelectionList->m_Size = 0;
  p_SelectionList->m_pElements = nullptr;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->strFindText.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FFA80
// Name: public: FindObject_t::~FindObject_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FindObject_t::~FindObject_t(FindObject_t *this)
{
  volatile signed __int32 *v2; // eax

  v2 = (volatile signed __int32 *)(this->strFindText.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &this->SelectionList);
}

//------------------------------------------------------------------------------
// Address: 0x100FFB00
// Name: protected: int CSearchReplaceDlg::OnFindReplace(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSearchReplaceDlg::OnFindReplace(CSearchReplaceDlg *this, const char *uCmd)
{
  CMapDoc *v2; // edi
  const char *v4; // ebx
  CMapClass *NextObject; // edi
  CHistory *History; // eax
  CHistory *v7; // eax
  CHistory *v8; // eax
  CWnd *DlgItem; // eax
  bool v10; // zf
  CAfxStringMgr *v11; // eax
  const char *v12; // edi
  const char *v13; // eax
  bool v14; // cc
  CAfxStringMgr *StringManager; // eax
  const char *v16; // edi
  char *v17; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-10h] [ebp-D8h]
  CMapClass *v20; // [esp-8h] [ebp-D0h]
  FindObject_t TempFindObject; // [esp+8h] [ebp-C0h] BYREF
  CMapDoc *pDoc; // [esp+B4h] [ebp-14h]
  bool bDone; // [esp+BBh] [ebp-Dh]
  int v24; // [esp+C4h] [ebp-4h]

  v2 = CMapDoc::m_pMapDoc;
  pDoc = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc == nullptr )
    return 1;
  if ( (_S1_18 & 1) == 0 )
  {
    _S1_18 |= 1u;
    FindObject_t::FindObject_t(this: &FindObject);
    atexit(func: CSearchReplaceDlg::OnFindReplace_::_5_::_dynamic_atexit_destructor_for__FindObject__);
    v24 = -1;
  }
  FindObject_t::FindObject_t(this: &TempFindObject);
  v24 = 1;
  bDone = false;
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  CSearchReplaceDlg::GetFindCriteria(this, FindObject: &TempFindObject, pDoc: v2);
  if ( strcmp(TempFindObject.strFindText.m_pszData, FindObject.strFindText.m_pszData) != 0 )
    this->m_bNewSearch = true;
  v4 = uCmd;
  while ( 1 )
  {
    if ( !this->m_bNewSearch )
    {
LABEL_15:
      NextObject = FindNextObject(FindObject: &FindObject);
      goto LABEL_16;
    }
    CWnd::UpdateData(this, bSaveAndValidate: 1);
    CSearchReplaceDlg::GetFindCriteria(this, FindObject: &FindObject, pDoc: v2);
    pLastFound = nullptr;
    nReplaceCount = 0;
    if ( FindObject.eFindIn == FindInWorld )
    {
      NextObject = CMapClass::GetFirstDescendent(this: FindObject.pWorld, pos: (CMapClass *)&FindObject.WorldPos);
    }
    else
    {
      if ( FindObject.SelectionList.m_Size == 0 )
        goto LABEL_13;
      NextObject = (*FindObject.SelectionList.m_Memory.m_pMemory)->m_pObject;
      FindObject.nSelectionIndex = 1;
    }
    if ( NextObject == nullptr )
    {
LABEL_13:
      NextObject = nullptr;
      goto LABEL_16;
    }
    if ( FindCheck(pObject: NextObject, FindObject: &FindObject) == 0 )
      goto LABEL_15;
LABEL_16:
    if ( this->m_bNewSearch && v4 == (const char *)1567 && NextObject != nullptr )
    {
      List = CSelection::GetList(this: pDoc->m_pSelection);
      History = GetHistory();
      CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Replace Text", bFromOpposite: 0);
    }
    if ( pLastFound != nullptr )
    {
      if ( v4 == (const char *)1257 )
      {
        v7 = GetHistory();
        CHistory::MarkUndoPosition(this: v7, pSelection: nullptr, pszName: "Replace Text", bFromOpposite: 0);
      }
      else if ( v4 != (const char *)1567 )
      {
        goto LABEL_26;
      }
      v20 = pLastFound;
      v8 = GetHistory();
      CHistory::Keep(this: v8, pObject: v20);
      nReplaceCount += FindReplace(
                         pEntity: (CMapEntity *)pLastFound,
                         FindObject: &FindObject,
                         pszReplace: this->m_strReplaceText.m_pszData);
      DlgItem = CWnd::GetDlgItem(this, nID: 2);
      CWnd::SetWindowTextA(this: DlgItem, lpszString: "Close");
    }
LABEL_26:
    if ( NextObject == nullptr )
      break;
    if ( v4 == (const char *)1566 || v4 == (const char *)1257 )
    {
      CMapDoc::SelectObject(this: pDoc, pObj: NextObject, cmd: 18);
      CMapDoc::CenterViewsOnSelection(this: pDoc);
    }
    if ( v4 != (const char *)1567 )
      bDone = true;
    v10 = !bDone;
    this->m_bNewSearch = false;
    pLastFound = NextObject;
    if ( !v10 )
      goto LABEL_43;
    v2 = pDoc;
  }
  if ( this->m_bNewSearch || v4 != (const char *)1567 )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager != nullptr )
    {
      uCmd = (const char *)&StringManager->GetNilString(this: StringManager)[1];
      LOBYTE(v24) = 3;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&uCmd,
        pszFormat: "Finished searching for '%s'.",
        this->m_strFindText.m_pszData);
      v16 = uCmd;
      CWnd::MessageBoxA(this, lpszText: uCmd, lpszCaption: "Find/Replace Text", nType: 0);
      LOBYTE(v24) = 1;
      v13 = v16 - 16;
      v14 = _InterlockedDecrement((volatile signed __int32 *)v16 - 1) <= 0;
      goto LABEL_40;
    }
LABEL_47:
    ATL::AtlThrowImpl(hr: -2147467259);
  }
  v11 = AfxGetStringManager();
  if ( v11 == nullptr )
    goto LABEL_47;
  uCmd = (const char *)&v11->GetNilString(this: v11)[1];
  LOBYTE(v24) = 6;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&uCmd,
    pszFormat: "Replaced %d occurrences of the string '%s' with '%s'.",
    nReplaceCount,
    this->m_strFindText.m_pszData,
    this->m_strReplaceText.m_pszData);
  v12 = uCmd;
  CWnd::MessageBoxA(this, lpszText: uCmd, lpszCaption: "Find/Replace Text", nType: 0);
  LOBYTE(v24) = 1;
  v13 = v12 - 16;
  v14 = _InterlockedDecrement((volatile signed __int32 *)v12 - 1) <= 0;
LABEL_40:
  if ( v14 )
    (*(void (__stdcall **)(const char *))(**(_DWORD **)v13 + 4))(a1: v13);
  this->m_bNewSearch = true;
LABEL_43:
  v24 = 8;
  uCmd = (const char *)&TempFindObject.strFindText;
  v17 = TempFindObject.strFindText.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)TempFindObject.strFindText.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v17 + 4))(a1: v17);
  uCmd = (const char *)&TempFindObject.SelectionList;
  v24 = -1;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &TempFindObject.SelectionList);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FFEF0
// Name: protected: virtual struct AFX_MSGMAP const __near * CSearchReplaceDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSearchReplaceDlg::GetMessageMap(CSearchReplaceDlg *this)
{
  return (const AFX_MSGMAP *)&off_105F387C;
}

//------------------------------------------------------------------------------
// Address: 0x105CB1D0
// Name: _CSearchReplaceDlg::OnFindReplace_::_5_::_dynamic_atexit_destructor_for__FindObject__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSearchReplaceDlg::OnFindReplace_::_5_::_dynamic_atexit_destructor_for__FindObject__()
{
  char *v0; // eax

  v0 = FindObject.strFindText.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)FindObject.strFindText.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v0 + 4))(a1: v0);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &FindObject.SelectionList);
}
