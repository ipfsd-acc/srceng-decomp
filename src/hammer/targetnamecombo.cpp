// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/targetnamecombo.cpp
// Functions: 11
// ============================================================

#include "hammer\targetnamecombo.h"

//------------------------------------------------------------------------------
// Address: 0x1003E8B0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct _FILETIME,struct _WIN32_FIND_DATAA,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int> *m_pMemory; // ecx
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
    v7 = 344 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int> *)_realloc_crt(
                                                                                                   ptr: m_pMemory,
                                                                                                   size: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int> *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100609C0
// Name: public: virtual CTypedPtrList<class CPtrList,class CUtlReferenceVector<class CMapEntity> __near *>::~CTypedPtrList<class CPtrList,class CUtlReferenceVector<class CMapEntity> __near *>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTypedPtrList<CPtrList,CUtlReferenceVector<CMapEntity> *>::~CTypedPtrList<CPtrList,CUtlReferenceVector<CMapEntity> *>(
        CTypedPtrList<CPtrList,CView *> *this)
{
  CPtrList::~CPtrList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B3490
// Name: public: virtual _CTypedPtrList<class CPtrList,class CView __near *>::~_CTypedPtrList<class CPtrList,class CView __near *>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall _CTypedPtrList<CPtrList,CView *>::~_CTypedPtrList<CPtrList,CView *>(
        _CTypedPtrList<CPtrList,CView *> *this)
{
  CPtrList::~CPtrList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B3520
// Name: protected: virtual struct AFX_MSGMAP const __near * CTargetNameComboBox::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CTargetNameComboBox::GetMessageMap(CTargetNameComboBox *this)
{
  return (const AFX_MSGMAP *)&off_105E6CB0;
}

//------------------------------------------------------------------------------
// Address: 0x100B4830
// Name: protected: virtual void CTargetNameComboBox::OnTextChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTargetNameComboBox::OnTextChanged(CTargetNameComboBox *this, char *pText)
{
  bool v3; // zf
  char *v4; // edi
  void *m_hObject; // eax
  HFONT v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  unsigned int v10; // ebx
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v12; // eax
  void *v13; // eax
  CMapWorld **v14; // eax
  CUtlReferenceVector<CMapEntity> *elem; // eax
  LOGFONTA pv; // [esp+8h] [ebp-4Ch] BYREF
  CTargetNameComboBox *v17; // [esp+44h] [ebp-10h]
  CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t search; // [esp+48h] [ebp-Ch] BYREF
  __POSITION *pos; // [esp+50h] [ebp-4h] BYREF

  v3 = this->m_pCurrentGestureInfo == nullptr;
  v4 = (char *)this - 180;
  v17 = this;
  if ( v3 )
  {
    m_hObject = CFilteredComboBox::GetNormalFont(this: (CTargetNameComboBox *)((char *)this - 180))->m_hObject;
    if ( m_hObject != nullptr )
    {
      GetObjectA(h: m_hObject, c: 60, &pv);
      pv.lfWeight = 700;
      v6 = CreateFontIndirectA(lplf: &pv);
      CGdiObject::Attach(this: (CGdiObject *)v4 + 32, hObject: v6);
    }
  }
  v7 = 0;
  if ( pText != nullptr )
  {
    search.key = pText;
    v8 = CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::Find(
           this: (CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int> > *)(v4 + 184),
           &search);
    if ( v8 != -1 )
    {
      v9 = *(_DWORD *)(*((_DWORD *)v4 + 47) + 24 * v8 + 20);
      if ( v9 != 0 )
        v7 = *(_DWORD *)(v9 + 12);
    }
  }
  search.elem = (CUtlReferenceVector<CMapEntity> *)&this->m_bGestureInited;
  if ( (unsigned int)v7 <= 1 )
    search.elem = (CUtlReferenceVector<CMapEntity> *)CFilteredComboBox::GetNormalFont(this: (CFilteredComboBox *)v4);
  v10 = 255;
  if ( v7 <= 0 )
  {
    ModuleState = AfxGetModuleState();
    pos = (__POSITION *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                            + 84))(a1: ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl);
    if ( pos != nullptr )
    {
      while ( 1 )
      {
        v12 = AfxGetModuleState();
        v13 = (void *)(*(int (__thiscall **)(unsigned int, __POSITION **))(*(_DWORD *)v12->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                         + 88))(
                        a1: v12->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl,
                        a2: &pos);
        v14 = (CMapWorld **)__RTDynamicCast(
                              inptr: v13,
                              VfDelta: 0,
                              SrcType: &CDocument `RTTI Type Descriptor',
                              TargetType: &CMapDoc `RTTI Type Descriptor',
                              isReference: 0);
        if ( v14 != nullptr
          && CMapWorld::FindEntityByName(
               this: v14[97],
               pszName: pText,
               bVisiblesOnly: false,
               bSearchInstanceParms: false) != nullptr )
        {
          break;
        }
        if ( pos == nullptr )
          goto LABEL_18;
      }
      v10 = 12632064;
    }
  }
  else
  {
    v10 = 0;
  }
LABEL_18:
  elem = search.elem;
  if ( search.elem != nullptr )
    elem = (CUtlReferenceVector<CMapEntity> *)search.elem->m_Memory.m_nBlocks;
  CFilteredComboBox::SetEditControlFont(this: (CFilteredComboBox *)v4, hFont: (HFONT__ *)elem);
  vgui::Panel::SetCursor(this: (vgui::Panel *)v4, cursor: v10);
  if ( HIDWORD(v17->m_ulGestureArg) != 0 )
    (**(void (__thiscall ***)(_DWORD, char *))HIDWORD(v17->m_ulGestureArg))(a1: HIDWORD(v17->m_ulGestureArg), a2: pText);
}

//------------------------------------------------------------------------------
// Address: 0x100B4A90
// Name: public: CTargetNameComboBox::CTargetNameComboBox(class CFilteredComboBox::ICallbacks __near *)
// Source: json
//------------------------------------------------------------------------------
CTargetNameComboBox *__thiscall CTargetNameComboBox::CTargetNameComboBox(
        CTargetNameComboBox *this,
        CFilteredComboBox::ICallbacks *pPassThru)
{
  CFilteredComboBox::ICallbacks *v3; // eax

  if ( this != nullptr )
    v3 = &this->CFilteredComboBox::ICallbacks;
  else
    v3 = nullptr;
  CFilteredComboBox::CFilteredComboBox(this, pCallbacks: v3);
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&CFilteredComboBox::ICallbacks::`vftable';
  this->CFilteredComboBox::CComboBox::CWnd::CCmdTarget::CObject::__vftable = (CTargetNameComboBox_vtbl *)&CTargetNameComboBox::`vftable'{for `CFilteredComboBox'};
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&CTargetNameComboBox::`vftable'{for `CFilteredComboBox::ICallbacks'};
  this->m_EntityLists.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_EntityLists.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_EntityLists.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_EntityLists.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_EntityLists.m_Elements.m_Tree.m_Root = -1;
  this->m_EntityLists.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_EntityLists.m_Elements.m_Tree.m_NumElements = 0;
  this->m_EntityLists.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_EntityLists.m_Elements.m_Tree.m_pElements = this->m_EntityLists.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_EntityLists.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_EntityLists.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  CPtrList::CPtrList(this: &this->m_SubLists, nBlockSize: 10);
  this->m_SubLists.__vftable = (CTypedPtrList<CPtrList,CUtlReferenceVector<CMapEntity> *>_vtbl *)&_CTypedPtrList<CPtrList,CUtlReferenceVector<CMapEntity> *>::`vftable';
  this->m_SubLists.__vftable = (CTypedPtrList<CPtrList,CUtlReferenceVector<CMapEntity> *>_vtbl *)&CTypedPtrList<CPtrList,CUtlReferenceVector<CMapEntity> *>::`vftable';
  this->m_BoldFont.__vftable = (CFont_vtbl *)&CGdiObject::`vftable';
  this->m_BoldFont.m_hObject = nullptr;
  this->m_BoldFont.__vftable = (CFont_vtbl *)&CFont::`vftable';
  this->m_pEntityList = nullptr;
  this->m_pPassThru = pPassThru;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B4BA0
// Name: public: static class CTargetNameComboBox __near * CTargetNameComboBox::Create(class CFilteredComboBox::ICallbacks __near *,unsigned long,struct tagRECT,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CTargetNameComboBox *__cdecl CTargetNameComboBox::Create(
        CFilteredComboBox::ICallbacks *pCallbacks,
        unsigned int dwStyle,
        tagRECT rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  CTargetNameComboBox *v5; // eax
  CTargetNameComboBox *v6; // esi

  v5 = (CTargetNameComboBox *)operator new(nSize: 0x108u);
  v6 = nullptr;
  if ( v5 != nullptr )
    v6 = CTargetNameComboBox::CTargetNameComboBox(this: v5, pPassThru: pCallbacks);
  CComboBox::Create(this: v6, dwStyle, &rect, pParentWnd, nID);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100B4C10
// Name: protected: void CTargetNameComboBox::FreeSubLists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTargetNameComboBox::FreeSubLists(CTargetNameComboBox *this)
{
  CPtrList::CNode *m_pNodeHead; // ebx
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *data; // esi
  int i; // edi
  int v4; // edi
  CUtlReference<CMapEntity> **m_pMemory; // [esp-Ch] [ebp-24h]
  CUtlReference<CMapEntity> **v6; // [esp-Ch] [ebp-24h]
  CTargetNameComboBox *v7; // [esp+8h] [ebp-10h]

  m_pNodeHead = this->m_SubLists.m_pNodeHead;
  v7 = this;
  if ( m_pNodeHead != nullptr )
  {
    do
    {
      data = (CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *)m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( data != nullptr )
      {
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::RemoveAll(this: data);
        if ( data->m_Memory.m_pMemory != nullptr )
        {
          for ( i = 0; i < data->m_Memory.m_nBlocks; ++i )
            free(pMem: data->m_Memory.m_pMemory[i]);
          m_pMemory = data->m_Memory.m_pMemory;
          data->m_Memory.m_nBlocks = 0;
          free(pMem: m_pMemory);
          data->m_Memory.m_pMemory = nullptr;
        }
        v4 = 0;
        data->m_pElements = nullptr;
        if ( data->m_Memory.m_pMemory != nullptr )
        {
          if ( data->m_Memory.m_nBlocks > 0 )
          {
            do
              free(pMem: data->m_Memory.m_pMemory[v4++]);
            while ( v4 < data->m_Memory.m_nBlocks );
          }
          v6 = data->m_Memory.m_pMemory;
          data->m_Memory.m_nBlocks = 0;
          free(pMem: v6);
          data->m_Memory.m_pMemory = nullptr;
        }
        operator delete(p: data);
      }
    }
    while ( m_pNodeHead != nullptr );
    this = v7;
  }
  CObList::RemoveAll(this: (CObList *)&this->m_SubLists);
}

//------------------------------------------------------------------------------
// Address: 0x100B4D20
// Name: public: void CTargetNameComboBox::SetEntityList(class CUtlReferenceVector<class CMapEntity> const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTargetNameComboBox::SetEntityList(
        CTargetNameComboBox *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *pEntityList)
{
  CTargetNameComboBox *v2; // edi
  const CUtlReferenceVector<CMapEntity> *m_pEntityList; // eax
  int v4; // esi
  CMapEntity *m_pObject; // eax
  CUtlReference<CMapEntity> *v6; // ecx
  CMapEntity *v7; // edi
  const char *Value; // eax
  int v9; // eax
  CUtlReferenceVector<CMapEntity> *v10; // eax
  CUtlReferenceVector<CMapEntity> *v11; // esi
  CUtlReference<CMapEntity> *v12; // eax
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *elem; // ecx
  CUtlReference<CMapEntity> *v14; // eax
  const CUtlReferenceVector<CMapEntity> *v15; // eax
  int Inorder; // eax
  int j; // esi
  volatile signed __int32 *v18; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v19; // eax
  const char *key; // esi
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  int v23; // eax
  int m_Size; // eax
  int v25; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pMemory; // ecx
  int v27; // eax
  CUtlReferenceVector<CMapEntity> *v28; // ebx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v29; // esi
  int (__thiscall ***v30)(_DWORD, char *, int); // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v31; // edi
  int v32; // eax
  int v33; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v34; // eax
  int v35; // eax
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > suggestions; // [esp+Ch] [ebp-60h] BYREF
  CUtlReference<CMapEntity> *m_pHead; // [esp+20h] [ebp-4Ch] BYREF
  CUtlReference<CMapEntity> *v38; // [esp+24h] [ebp-48h]
  CMapEntity *v39; // [esp+28h] [ebp-44h]
  CUtlReference<CMapEntity> v40; // [esp+2Ch] [ebp-40h] BYREF
  CUtlReference<CMapEntity> src; // [esp+38h] [ebp-34h] BYREF
  CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t search; // [esp+44h] [ebp-28h] BYREF
  CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t insert; // [esp+4Ch] [ebp-20h] BYREF
  void *p; // [esp+54h] [ebp-18h]
  int i; // [esp+58h] [ebp-14h]
  CTargetNameComboBox *v46; // [esp+5Ch] [ebp-10h]
  int v47; // [esp+68h] [ebp-4h]

  v2 = this;
  v46 = this;
  CFilteredComboBox::SetOnlyProvideSuggestions(this, bOnlyProvideSuggestions: false);
  v2->m_pEntityList = (const CUtlReferenceVector<CMapEntity> *)pEntityList;
  CTargetNameComboBox::FreeSubLists(this: v2);
  CUtlDict<CUtlReferenceVector<CMapEntity> *,int>::RemoveAll(this: &v2->m_EntityLists);
  m_pEntityList = v2->m_pEntityList;
  if ( m_pEntityList != nullptr )
  {
    v4 = 0;
    pEntityList = nullptr;
    if ( m_pEntityList->m_Size > 0 )
    {
      do
      {
        m_pObject = v2->m_pEntityList->m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&v2->m_pEntityList->m_Memory
                                                                                   + 2) >> 27)][v4
                                                                                              & ((32
                                                                                                * *((_DWORD *)&v2->m_pEntityList->m_Memory
                                                                                                  + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          v39 = v2->m_pEntityList->m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&v2->m_pEntityList->m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&v2->m_pEntityList->m_Memory + 2)) >> 5)].m_pObject;
          m_pHead = m_pObject->m_References.m_pHead;
          v6 = m_pObject->m_References.m_pHead;
          if ( v6 != nullptr )
            v6->m_pPrev = (CUtlReference<CMapEntity> *)&m_pHead;
          v38 = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapEntity> *)&m_pHead;
        }
        v7 = v39;
        v47 = -1;
        if ( v39 != nullptr )
        {
          if ( v38 != nullptr )
          {
            v38->m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = v38;
          }
          else if ( (CUtlReference<CMapEntity> **)v39->m_References.m_pHead == &m_pHead )
          {
            v39->m_References.m_pHead = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = nullptr;
          }
          v38 = nullptr;
          m_pHead = nullptr;
          v39 = nullptr;
        }
        if ( v7 != nullptr )
        {
          Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &v7->m_KeyValues, pszKey: "targetname", piIndex: nullptr);
          i = (int)Value;
          if ( Value != nullptr )
          {
            search.key = Value;
            v9 = CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::Find(
                   this: &v46->m_EntityLists.m_Elements.m_Tree,
                   &search);
            if ( v9 == -1 )
            {
              v10 = (CUtlReferenceVector<CMapEntity> *)operator new(nSize: 0x14u);
              v11 = v10;
              p = v10;
              v47 = 1;
              if ( v10 != nullptr )
              {
                v10->m_Memory.m_pMemory = nullptr;
                v10->m_Memory.m_nBlocks = 0;
                *((_DWORD *)&v10->m_Memory + 2) = 0;
                CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
                  this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)v10,
                  nGrowSize: 0,
                  nInitSize: 0);
                v11->m_Size = 0;
                v11->m_pElements = nullptr;
                LOBYTE(v47) = 1;
              }
              else
              {
                v11 = nullptr;
              }
              v47 = -1;
              v12 = v7->m_References.m_pHead;
              src.m_pPrev = nullptr;
              src.m_pObject = v7;
              src.m_pNext = v12;
              if ( v12 != nullptr )
                v12->m_pPrev = &src;
              src.m_pPrev = nullptr;
              v7->m_References.m_pHead = &src;
              v47 = 5;
              CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
                this: v11,
                elem: v11->m_Size,
                &src);
              v47 = -1;
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
              insert.key = _strdup(string: (const char *)i);
              insert.elem = v11;
              CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::Insert(
                this: &v46->m_EntityLists.m_Elements.m_Tree,
                a2: (const char *)v7,
                &insert);
              CPtrList::AddTail(this: (CObList *)&v46->m_SubLists, newElement: (CObject *)v11);
              v4 = (int)pEntityList;
            }
            else
            {
              elem = v46->m_EntityLists.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
              v14 = v7->m_References.m_pHead;
              v40.m_pPrev = nullptr;
              v40.m_pObject = v7;
              v40.m_pNext = v14;
              if ( v14 != nullptr )
                v14->m_pPrev = &v40;
              v40.m_pPrev = nullptr;
              v7->m_References.m_pHead = &v40;
              v47 = 6;
              CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
                this: elem,
                elem: elem->m_Size,
                src: &v40);
              v47 = -1;
              if ( v40.m_pObject != nullptr )
              {
                if ( v40.m_pPrev != nullptr )
                {
                  v40.m_pPrev->m_pNext = v40.m_pNext;
                  if ( v40.m_pNext != nullptr )
                    v40.m_pNext->m_pPrev = v40.m_pPrev;
                }
                else if ( v40.m_pObject->m_References.m_pHead == &v40 )
                {
                  v40.m_pObject->m_References.m_pHead = v40.m_pNext;
                  if ( v40.m_pNext != nullptr )
                    v40.m_pNext->m_pPrev = nullptr;
                }
                memset(&v40, 0, sizeof(v40));
              }
            }
          }
        }
        v15 = v46->m_pEntityList;
        pEntityList = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)++v4;
        v2 = v46;
      }
      while ( v4 < v15->m_Size );
    }
  }
  memset(&suggestions, 0, sizeof(suggestions));
  v47 = 8;
  Inorder = CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::FirstInorder(this: &v2->m_EntityLists.m_Elements.m_Tree);
  i = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      key = v2->m_EntityLists.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key;
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      pEntityList = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&StringManager->GetNilString(this: StringManager)[1];
      LOBYTE(v47) = 9;
      if ( key == nullptr )
        break;
      if ( ((unsigned int)key & 0xFFFF0000) != 0 )
      {
        v23 = strlen(key);
        goto LABEL_65;
      }
      StringResourceHandle = AfxFindStringResourceHandle(__formal: (unsigned __int16)key);
      if ( StringResourceHandle != nullptr )
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
          this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pEntityList,
          hInstance: StringResourceHandle,
          nID: (unsigned __int16)key);
LABEL_66:
      LOBYTE(v47) = 10;
      m_Size = suggestions.m_Size;
      v25 = suggestions.m_Size;
      if ( suggestions.m_Size + 1 > suggestions.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&suggestions,
          num: suggestions.m_Size - suggestions.m_Memory.m_nAllocationCount + 1);
        m_Size = suggestions.m_Size;
      }
      suggestions.m_Size = m_Size + 1;
      m_pMemory = suggestions.m_Memory.m_pMemory;
      v27 = m_Size - v25;
      suggestions.m_pElements = suggestions.m_Memory.m_pMemory;
      if ( v27 > 0 )
      {
        _V_memmove(
          dest: &suggestions.m_Memory.m_pMemory[v25 + 1],
          src: &suggestions.m_Memory.m_pMemory[v25],
          count: 4 * v27);
        m_pMemory = suggestions.m_Memory.m_pMemory;
      }
      v28 = (CUtlReferenceVector<CMapEntity> *)&m_pMemory[v25];
      p = v28;
      insert.elem = v28;
      LOBYTE(v47) = 11;
      if ( v28 != nullptr )
      {
        v29 = pEntityList;
        v30 = (int (__thiscall ***)(_DWORD, char *, int))(*(int (__thiscall **)(char *))(*(_DWORD *)pEntityList[-4].m_pszData
                                                                                       + 16))(a1: pEntityList[-4].m_pszData);
        if ( (int)v29[-1].m_pszData >= 0 && v30 == (int (__thiscall ***)(_DWORD, char *, int))v29[-4].m_pszData )
        {
          v31 = v29 - 4;
          _InterlockedExchangeAdd((volatile signed __int32 *)&v29[-1], 1u);
        }
        else
        {
          v32 = (**v30)(a1: v30, a2: v29[-3].m_pszData, a3: 1);
          v31 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)v32;
          if ( v32 == 0 )
            ATL::CSimpleStringT<char,0>::ThrowMemoryException(a1: v33);
          *(ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)(v32 + 4) = v29[-3];
          memcpy_s(
            dst: (void *)(v32 + 16),
            sizeInBytes: (unsigned int)(v29[-3].m_pszData + 1),
            src: v29,
            count: (unsigned int)(v29[-3].m_pszData + 1));
        }
        v28->m_Memory.m_pMemory = (CUtlReference<CMapEntity> **)&v31[4];
        LOBYTE(v47) = 11;
      }
      LOBYTE(v47) = 8;
      v34 = pEntityList - 4;
      if ( _InterlockedDecrement((volatile signed __int32 *)&pEntityList[-1]) <= 0 )
        (*(void (__stdcall **)(ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *))(*(_DWORD *)v34->m_pszData
                                                                                                + 4))(a1: v34);
      v35 = CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::NextInorder(
              this: &v46->m_EntityLists.m_Elements.m_Tree,
              i);
      v2 = v46;
      i = v35;
      if ( v35 == -1 )
        goto LABEL_44;
      Inorder = i;
    }
    v23 = 0;
LABEL_65:
    ATL::CSimpleStringT<char,0>::SetString(this: (ATL::CSimpleStringT<char,0> *)&pEntityList, pszSrc: key, nLength: v23);
    goto LABEL_66;
  }
LABEL_44:
  CFilteredComboBox::SetSuggestions(this: v2, &suggestions, flags: 3);
  v47 = 14;
  for ( j = suggestions.m_Size - 1; j >= 0; --j )
  {
    pEntityList = &suggestions.m_Memory.m_pMemory[j];
    LOBYTE(v47) = 14;
    v18 = (volatile signed __int32 *)(pEntityList->m_pszData - 16);
    if ( _InterlockedDecrement(v18 + 3) <= 0 )
      (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v18 + 4))(a1: v18);
  }
  v19 = suggestions.m_Memory.m_pMemory;
  suggestions.m_Size = 0;
  if ( suggestions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( suggestions.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: suggestions.m_Memory.m_pMemory);
      v19 = nullptr;
      suggestions.m_Memory.m_pMemory = nullptr;
    }
    suggestions.m_Memory.m_nAllocationCount = 0;
  }
  suggestions.m_pElements = v19;
  v47 = -1;
  if ( suggestions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( suggestions.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: suggestions.m_Memory.m_pMemory);
      suggestions.m_Memory.m_pMemory = nullptr;
    }
    suggestions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B52A0
// Name: public: virtual CTargetNameComboBox::~CTargetNameComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTargetNameComboBox::~CTargetNameComboBox(CTargetNameComboBox *this)
{
  this->CFilteredComboBox::CComboBox::CWnd::CCmdTarget::CObject::__vftable = (CTargetNameComboBox_vtbl *)&CTargetNameComboBox::`vftable'{for `CFilteredComboBox'};
  this->CFilteredComboBox::ICallbacks::__vftable = (CFilteredComboBox::ICallbacks_vtbl *)&CTargetNameComboBox::`vftable'{for `CFilteredComboBox::ICallbacks'};
  CTargetNameComboBox::FreeSubLists(this);
  this->m_BoldFont.__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_BoldFont);
  CPtrList::~CPtrList(this: &this->m_SubLists);
  CUtlDict<CUtlReferenceVector<CMapEntity> *,int>::RemoveAll(this: &this->m_EntityLists);
  CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>(this: &this->m_EntityLists.m_Elements.m_Tree);
  CFilteredComboBox::~CFilteredComboBox(this);
}

//------------------------------------------------------------------------------
// Address: 0x10206FD0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CDmElementFactoryHelper __near *,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
