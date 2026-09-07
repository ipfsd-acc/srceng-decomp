// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/foundrytool.cpp
// Functions: 285
// ============================================================

#include "hammer\foundrytool.h"

//------------------------------------------------------------------------------
// Address: 0x1000AB10
// Name: public: CCamera::CCamera(void)
// Source: json
//------------------------------------------------------------------------------
CCamera *__thiscall CCamera::CCamera(CCamera *this)
{
  this->__vftable = (CCamera_vtbl *)&CCamera::`vftable';
  this->m_ViewPoint.x = 0.0;
  this->m_ViewPoint.y = 0.0;
  this->m_ViewPoint.z = 0.0;
  this->m_fPitch = 0.0;
  this->m_fRoll = 0.0;
  this->m_fYaw = 0.0;
  this->m_fHorizontalFOV = 90.0;
  this->m_fNearClip = 1.0;
  this->m_fFarClip = 5000.0;
  this->m_fZoom = 1.0;
  this->m_bIsOrthographic = false;
  this->m_fScaleVert = 1.0;
  this->m_fScaleHorz = 1.0;
  this->m_nViewHeight = 100;
  this->m_nViewWidth = 100;
  CCamera::BuildViewMatrix(this);
  CCamera::BuildProjMatrix(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10040C40
// Name: public: CUtlMap<struct _FILETIME,struct _WIN32_FIND_DATAA,int>::~CUtlMap<struct _FILETIME,struct _WIN32_FIND_DATAA,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::~CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>(
        CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int> *this)
{
  CUtlRBTree<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int,CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int,CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int>,int>>(this: &this->m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10092930
// Name: public: void CUtlMemory<struct vgui::MessageMapItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::MessageMapItem_t,int>::Grow(CUtlMemory<VMatrix,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  VMatrix *m_pMemory; // ecx
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
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (VMatrix *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (VMatrix *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8020
// Name: public: void CUtlDict<class CSpriteDataCache __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CSpriteDataCache *,int>::RemoveAll(CUtlDict<CSpriteDataCache *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int,CUtlMap<char const *,CSpriteDataCache *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int,CUtlMap<char const *,CSpriteDataCache *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    free(pMem: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int,CUtlMap<char const *,CSpriteDataCache *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100A8060
// Name: public: CUtlMap<char const __near *,class CSpriteDataCache __near *,int>::~CUtlMap<char const __near *,class CSpriteDataCache __near *,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<char const *,CSpriteDataCache *,int>::~CUtlMap<char const *,CSpriteDataCache *,int>(
        CUtlMap<char const *,CSpriteDataCache *,int> *this)
{
  CUtlRBTree<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int,CUtlMap<char const *,CSpriteDataCache *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int,CUtlMap<char const *,CSpriteDataCache *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int>,int>>(this: &this->m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100B4760
// Name: public: void CUtlDict<class CUtlReferenceVector<class CMapEntity> __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CUtlReferenceVector<CMapEntity> *,int>::RemoveAll(
        CUtlDict<CUtlReferenceVector<CMapEntity> *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    free(pMem: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100B47A0
// Name: public: CUtlMap<char const __near *,class CUtlReferenceVector<class CMapEntity> __near *,int>::~CUtlMap<char const __near *,class CUtlReferenceVector<class CMapEntity> __near *,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::~CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>(
        CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int> *this)
{
  CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>(this: &this->m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100B49A0
// Name: public: CUtlDict<class CUtlReferenceVector<class CMapEntity> __near *,int>::~CUtlDict<class CUtlReferenceVector<class CMapEntity> __near *,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CUtlReferenceVector<CMapEntity> *,int>::~CUtlDict<CUtlReferenceVector<CMapEntity> *,int>(
        CUtlDict<CUtlReferenceVector<CMapEntity> *,int> *this)
{
  CUtlDict<CUtlReferenceVector<CMapEntity> *,int>::RemoveAll(this);
  CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100C2750
// Name: public: CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t::~Node_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t::~Node_t(
        CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int,unsigned short>::Node_t *this)
{
  volatile signed __int32 *v1; // eax

  v1 = (volatile signed __int32 *)(this->key.m_pszData - 16);
  if ( _InterlockedDecrement(v1 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v1 + 4))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100C36B0
// Name: struct CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t __near * CopyConstruct<struct CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t>(struct CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t __near *,struct CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int,unsigned short>::Node_t *__cdecl CopyConstruct<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t>(
        CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int,unsigned short>::Node_t *pMemory,
        const CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int,unsigned short>::Node_t *src)
{
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->key.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)src->key.m_pszData - 1)[1];
  pMemory->elem = src->elem;
  return pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x100C4510
// Name: public: unsigned short CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int,unsigned short>::Insert(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Insert(
        CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int,unsigned short> *this,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *key)
{
  ATL::IAtlStringMgr *StringManager; // eax
  unsigned __int16 v4; // ax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  char *v7; // eax
  CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int,unsigned short>::Node_t node; // [esp+8h] [ebp-18h] BYREF
  unsigned __int16 parent[2]; // [esp+10h] [ebp-10h] BYREF
  int v11; // [esp+1Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  node.key.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v11 = 2;
  ATL::CSimpleStringT<char,0>::operator=(this: &node.key, strSrc: key);
  *(_DWORD *)parent = 0xFFFF;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent,
    leftchild: (bool *)&key);
  v4 = CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &this->m_Tree);
  v5 = v4;
  CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this: &this->m_Tree,
    i: v4,
    parent: parent[0],
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  CopyConstruct<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t>(
    pMemory: &m_pMemory[v5].m_Data,
    src: &node);
  v11 = -1;
  v7 = node.key.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)node.key.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100C4770
// Name: public: CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int,unsigned short>::~CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::~CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>(
        CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int,unsigned short> *this)
{
  CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100D8FE0
// Name: public: CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::Node_t::~Node_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t::~Node_t(
        CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t *this)
{
  volatile signed __int32 *v2; // eax

  CInstanceParmData::~CInstanceParmData(this: (CBoolString *)&this->elem);
  v2 = (volatile signed __int32 *)(this->key.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100D9920
// Name: struct CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::Node_t __near * Construct<struct CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::Node_t>(struct CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t *__cdecl Construct<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t>(
        CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t *pMemory)
{
  ATL::IAtlStringMgr *StringManager; // eax

  if ( pMemory == nullptr )
    return nullptr;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  pMemory->key.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  CInstanceParmData::CInstanceParmData(this: &pMemory->elem);
  return pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x100DA190
// Name: public: CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::Node_t::Node_t(struct CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t *__thiscall CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t::Node_t(
        CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t *this,
        const CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t *from)
{
  this->key.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)from->key.m_pszData - 1)[1];
  this->elem.m_ParmVariable = from->elem.m_ParmVariable;
  this->elem.m_ParmKey.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)from->elem.m_ParmKey.m_pszData - 1)[1];
  this->elem.m_VariableName.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)from->elem.m_VariableName.m_pszData - 1)[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DD460
// Name: public: unsigned short CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::Find(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Find(
        CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short> *this,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *key)
{
  ATL::IAtlStringMgr *StringManager; // eax
  unsigned __int16 v4; // si
  char *v5; // eax
  CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t dummyNode; // [esp+4h] [ebp-1Ch] BYREF
  int v8; // [esp+1Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  dummyNode.key.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v8 = 1;
  CInstanceParmData::CInstanceParmData(this: &dummyNode.elem);
  v8 = 3;
  ATL::CSimpleStringT<char,0>::operator=(this: &dummyNode.key, strSrc: key);
  v4 = CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Tree,
         search: &dummyNode);
  v8 = 4;
  CInstanceParmData::~CInstanceParmData(this: (CBoolString *)&dummyNode.elem);
  v8 = -1;
  v5 = dummyNode.key.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)dummyNode.key.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100DD650
// Name: public: CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::~CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::~CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>(
        CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short> *this)
{
  CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100DDCB0
// Name: public: unsigned short CUtlMap<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CInstanceParmData,unsigned short>::Insert(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &,class CInstanceParmData const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Insert(
        CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short> *this,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *key,
        const CInstanceParmData *insert)
{
  ATL::IAtlStringMgr *StringManager; // eax
  unsigned __int16 v5; // si
  char *v6; // eax
  CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CInstanceParmData,unsigned short>::Node_t node; // [esp+8h] [ebp-1Ch] BYREF
  int v9; // [esp+20h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  node.key.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v9 = 1;
  CInstanceParmData::CInstanceParmData(this: &node.elem);
  v9 = 3;
  ATL::CSimpleStringT<char,0>::operator=(this: &node.key, strSrc: key);
  node.elem.m_ParmVariable = insert->m_ParmVariable;
  ATL::CSimpleStringT<char,0>::operator=(this: &node.elem.m_ParmKey, strSrc: &insert->m_ParmKey);
  ATL::CSimpleStringT<char,0>::operator=(this: &node.elem.m_VariableName, strSrc: &insert->m_VariableName);
  v5 = CUtlRBTree<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short,CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CInstanceParmData,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Tree,
         insert: &node);
  v9 = 4;
  CInstanceParmData::~CInstanceParmData(this: (CBoolString *)&node.elem);
  v9 = -1;
  v6 = node.key.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)node.key.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10105E70
// Name: public: virtual IBaseInterface::~IBaseInterface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBaseInterface::~IBaseInterface(IBaseInterface *this)
{
  this->__vftable = (IBaseInterface_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10105EB0
// Name: public: void CChangeUndoScopeGuard::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeUndoScopeGuard::Release(CChangeUndoScopeGuard *this)
{
  bool v2; // zf

  if ( !this->m_bReleased )
  {
    ((void (__stdcall *)(bool))g_pDataModel->SetUndoEnabled)(a1: this->m_bOldValue);
    v2 = !this->m_bNotify;
    this->m_bReleased = true;
    if ( !v2 )
    {
      g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      this->m_bNotify = false;
    }
    if ( this->m_pNotify != nullptr )
    {
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: this->m_pNotify);
      this->m_pNotify = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105F10
// Name: char const __near * GetVGuiControlsModuleName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GetVGuiControlsModuleName(CFoundryTool *this)
{
  return "FoundryTool";
}

//------------------------------------------------------------------------------
// Address: 0x10105F20
// Name: bool ConnectTools(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ConnectTools(void *(__cdecl *factory)(const char *, int *))
{
  g_MainFactory = factory;
  return materials != nullptr && g_pMatSystemSurface != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10105F50
// Name: public: static char const __near * CFoundryTool::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFoundryTool::GetPanelClassName()
{
  return "CFoundryTool";
}

//------------------------------------------------------------------------------
// Address: 0x10105F60
// Name: foundry_sync_engine_view
// Source: json
//------------------------------------------------------------------------------
void __cdecl foundry_sync_engine_view()
{
  CMapDoc *v0; // esi
  CView *v1; // eax
  void *v2; // eax
  CCamera *v3; // esi
  Vector vPos; // [esp+4h] [ebp-1Ch] BYREF
  QAngle vEngineAngles; // [esp+10h] [ebp-10h] BYREF
  __POSITION *p; // [esp+1Ch] [ebp-4h] BYREF

  v0 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    p = CMapDoc::m_pMapDoc->GetFirstViewPosition(this: CMapDoc::m_pMapDoc);
    if ( p != nullptr )
    {
      while ( 1 )
      {
        v1 = v0->GetNextView(this: v0, a2: &p);
        v2 = __RTDynamicCast(
               inptr: v1,
               VfDelta: 0,
               SrcType: &CView `RTTI Type Descriptor',
               TargetType: &CMapView3D `RTTI Type Descriptor',
               isReference: 0);
        if ( v2 != nullptr )
          break;
        if ( p == nullptr )
          return;
      }
      v3 = *((CCamera **)v2 + 35);
      CCamera::GetViewPoint(this: v3, ViewPoint: &vPos);
      CCamera::GetAngles(this: v3, result: &vEngineAngles);
      vEngineAngles.y = 90.0 - vEngineAngles.y;
      g_pFoundryTool->MoveEngineViewTo(this: g_pFoundryTool, a2: &vPos, a3: &vEngineAngles);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106000
// Name: foundry_move_focus_to_engine
// Source: json
//------------------------------------------------------------------------------
void __cdecl foundry_move_focus_to_engine()
{
  HWND v0; // esi
  tagRECT rcWindow; // [esp+4h] [ebp-10h] BYREF

  v0 = (HWND)enginetools->GetEngineHwnd(this: enginetools);
  GetWindowRect(hWnd: v0, lpRect: &rcWindow);
  SetCursorPos(X: (rcWindow.right + rcWindow.left) / 2, Y: (rcWindow.bottom + rcWindow.top) / 2);
  SetFocus(hWnd: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10106060
// Name: public: virtual IServerFoundry::~IServerFoundry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IServerFoundry::~IServerFoundry(IServerFoundry *this)
{
  this->__vftable = (IServerFoundry_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101060A0
// Name: public: virtual void CFoundryTool::OnToolActivate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFoundryTool::OnToolActivate(CFoundryTool *this)
{
  CBaseToolSystem::OnToolActivate(this);
}

//------------------------------------------------------------------------------
// Address: 0x101060B0
// Name: public: virtual void CFoundryTool::OnToolDeactivate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFoundryTool::OnToolDeactivate(CFoundryTool *this)
{
  CBaseToolSystem::OnToolDeactivate(this);
}

//------------------------------------------------------------------------------
// Address: 0x101060C0
// Name: public: virtual unsigned long CFoundryTool::GetToolScheme(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFoundryTool::GetToolScheme(CFoundryTool *this)
{
  return g_pVGuiSchemeManager->LoadSchemeFromFile(
           this: g_pVGuiSchemeManager,
           a2: "Resource/BoxRocket.res",
           a3: "BoxRocket");
}

//------------------------------------------------------------------------------
// Address: 0x101060E0
// Name: public: static char const __near * CFoundryViewMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFoundryViewMenuButton::GetPanelClassName()
{
  return "CFoundryViewMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x101060F0
// Name: public: virtual void CFoundryViewMenuButton::OnShowMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryViewMenuButton::OnShowMenu(CFoundryViewMenuButton *this, vgui::Menu *menu)
{
  CToolMenuButton::OnShowMenu(this, menu);
}

//------------------------------------------------------------------------------
// Address: 0x10106100
// Name: public: static char const __near * CFoundryToolMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFoundryToolMenuButton::GetPanelClassName()
{
  return "CFoundryToolMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x10106110
// Name: public: static char const __near * CFoundryViewport::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFoundryViewport::GetPanelClassName()
{
  return "CFoundryViewport";
}

//------------------------------------------------------------------------------
// Address: 0x10106120
// Name: public: virtual CMiniViewport::~CMiniViewport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMiniViewport::~CMiniViewport(CMiniViewport *this)
{
  vgui::ToolWindow::~ToolWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x10106160
// Name: public: virtual void CFoundryTool::OnDefaultLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnDefaultLayout(CFoundryTool *this)
{
  this->DestroyToolContainers(this);
}

//------------------------------------------------------------------------------
// Address: 0x10106170
// Name: public: virtual void CFoundryTool::OnSyncHammerView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnSyncHammerView(CFoundryTool *this)
{
  enginetools->Command(this: enginetools, a2: "foundry_sync_hammer_view\n");
}

//------------------------------------------------------------------------------
// Address: 0x10106190
// Name: private: void CFoundryTool::DestroyTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::DestroyTools(CFoundryTool *this)
{
  int i; // esi
  vgui::ToolWindow *ToolWindow; // eax

  for ( i = vgui::ToolWindow::GetToolWindowCount() - 1; i >= 0; --i )
  {
    ToolWindow = vgui::ToolWindow::GetToolWindow(index: i);
    if ( ToolWindow != nullptr )
      ((void (__thiscall *)(vgui::ToolWindow *, int))ToolWindow->dtr_Panel)(a1: ToolWindow, a2: 1);
  }
  CBaseToolSystem::UnregisterAllToolWindows(this);
}

//------------------------------------------------------------------------------
// Address: 0x101061D0
// Name: public: virtual class vgui::Menu __near * CFoundryTool::CreateActionMenu(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall CFoundryTool::CreateActionMenu(CFoundryTool *this, vgui::Panel *pParent)
{
  vgui::Menu *v2; // eax
  KeyValues *v3; // ebx
  vgui::Menu *v4; // edi
  KeyValues *v5; // eax
  vgui::Menu_vtbl *v6; // esi
  vgui::Panel *ActionTarget; // eax

  v2 = (vgui::Menu *)operator new(nSize: 0x420u);
  v3 = nullptr;
  if ( v2 != nullptr )
    v4 = vgui::Menu::Menu(this: v2, parent: pParent, panelName: "ActionMenu");
  else
    v4 = nullptr;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v3 = KeyValues::KeyValues(this: v5, setName: "Command", firstKey: "command", firstValue: "HideActionMenu");
  v6 = v4->__vftable;
  ActionTarget = CBaseToolSystem::GetActionTarget(this);
  v6->AddMenuItem(this: v4, a2: "#ToolHide", a3: v3, a4: ActionTarget, a5: nullptr);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10106290
// Name: public: virtual int CFoundryTool::GetFileMenuItemsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFoundryTool::GetFileMenuItemsEnabled(CFoundryTool *this)
{
  bool v1; // zf
  int result; // eax

  v1 = !CToolsRecentFileList::IsEmpty(this: (CToolsRecentFileList *)((char *)this - 92));
  result = -34;
  if ( v1 )
    return -2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101062B0
// Name: public: virtual void CFoundryTool::AddRecentFilesToMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::AddRecentFilesToMenu(CFoundryTool *this, vgui::Menu *pMenu)
{
  vgui::Panel *ActionTarget; // eax

  ActionTarget = CBaseToolSystem::GetActionTarget(this: (CFoundryTool *)((char *)this - 488));
  CToolsRecentFileList::AddToMenu(
    this: (CToolsRecentFileList *)((char *)this - 92),
    menu: pMenu,
    pActionTarget: ActionTarget,
    pCommandName: "OnRecent");
}

//------------------------------------------------------------------------------
// Address: 0x101062E0
// Name: public: virtual void CFoundryTool::OnExit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnExit(CFoundryTool *this)
{
  windowposmgr->SavePositions(this: windowposmgr, a2: "cfg/foundry.txt", a3: "Foundry");
  enginetools->Command(this: enginetools, a2: "quit\n");
}

//------------------------------------------------------------------------------
// Address: 0x10106310
// Name: public: virtual void CFoundryTool::OnSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnSave(CFoundryTool *this)
{
  if ( this->m_pMapDoc != nullptr )
    CBaseToolSystem::SaveFile(this, pFileName: nullptr, pFileType: "vmf", nFlags: 1, pContextKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10106330
// Name: public: virtual void CFoundryTool::OnFileOperationCompleted(char const __near *,bool,enum vgui::FileOpenStateMachine::CompletionState_t,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnFileOperationCompleted(
        CFoundryTool *this,
        const char *pFileType,
        bool bWroteFile,
        vgui::FileOpenStateMachine::CompletionState_t state,
        KeyValues *pContextKeyValues)
{
  const char *Name; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  vgui::IVGui *v11; // edi
  vgui::IVGui_vtbl *v12; // ebx
  int v13; // eax
  const char *v14; // eax

  if ( bWroteFile )
    this->OnMarkNotDirty(this);
  if ( pContextKeyValues != nullptr && state == SUCCESSFUL )
  {
    Name = KeyValues::GetName(this: pContextKeyValues);
    if ( _V_stricmp(s1: Name, s2: "OnNew") != 0 )
    {
      v7 = KeyValues::GetName(this: pContextKeyValues);
      if ( _V_stricmp(s1: v7, s2: "OnClose") != 0 )
      {
        v8 = KeyValues::GetName(this: pContextKeyValues);
        if ( _V_stricmp(s1: v8, s2: "OnQuit") != 0 )
        {
          v14 = KeyValues::GetName(this: pContextKeyValues);
          if ( _V_stricmp(s1: v14, s2: "OnUnload") == 0 )
            enginetools->Command(this: enginetools, a2: "toolunload foundry -nosave\n");
        }
        else
        {
          this->OnCloseNoSave(this);
          v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v9 != nullptr )
            v10 = KeyValues::KeyValues(this: v9, setName: "OnExit");
          else
            v10 = nullptr;
          v11 = g_pVGui;
          v12 = g_pVGui->__vftable;
          v13 = ((int (__thiscall *)(CFoundryTool *, KeyValues *, _DWORD, _DWORD))this->GetVPanel)(
                  a1: this,
                  a2: v10,
                  a3: 0,
                  a4: 0);
          ((void (__thiscall *)(vgui::IVGui *, int))v12->PostMessage)(a1: v11, a2: v13);
        }
      }
      else
      {
        this->OnCloseNoSave(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106490
// Name: public: virtual void CFoundryTool::SetupFileOpenDialog(class vgui::FileOpenDialog __near *,bool,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::SetupFileOpenDialog(
        CFoundryTool *this,
        vgui::FileOpenDialog *pDialog,
        bool bOpenFile,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  char pStartingDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( bOpenFile )
  {
    GetModSubdirectory(pSubDir: "maps", pBuf: pStartingDir, nBufLen: 260);
    pDialog->SetTitle_2(this: pDialog, a2: "Choose Valve BSP File", a3: true);
    vgui::FileOpenDialog::SetStartDirectoryContext(
      this: pDialog,
      pStartDirContext: "foundry_bsp_session",
      pDefaultDir: pStartingDir);
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.bsp",
      filterName: "Valve BSP File (*.bsp)",
      bActive: true,
      pFilterInfo: nullptr);
  }
  else
  {
    GetModContentSubdirectory(pSubDir: "maps", pBuf: pStartingDir, nBufLen: 260);
    pDialog->SetTitle_2(this: pDialog, a2: "Choose Valve VMF File", a3: true);
    vgui::FileOpenDialog::SetStartDirectoryContext(
      this: pDialog,
      pStartDirContext: "foundry_vmf_session",
      pDefaultDir: pStartingDir);
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.vmf",
      filterName: "Valve VMF File (*.vmf)",
      bActive: true,
      pFilterInfo: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106560
// Name: public: virtual void CFoundryTool::OnReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnReload(CFoundryTool *this)
{
  enginetools->Command(this: enginetools, a2: "respawn_entities\n");
}

//------------------------------------------------------------------------------
// Address: 0x10106580
// Name: public: virtual void CFoundryTool::OnReloadFromSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnReloadFromSave(CFoundryTool *this)
{
  enginetools->Command(this: enginetools, a2: "load quick\n");
}

//------------------------------------------------------------------------------
// Address: 0x101065A0
// Name: public: virtual void CFoundryTool::OnUpdateHammerEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnUpdateHammerEntity(CFoundryTool *this)
{
  enginetools->Command(this: enginetools, a2: "foundry_update_entity");
}

//------------------------------------------------------------------------------
// Address: 0x101065C0
// Name: private: bool CFoundryTool::LoadDocument(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFoundryTool::LoadDocument(CFoundryTool *this, const char *pFileName)
{
  const char *v3; // ebx
  const char *v5; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  char mapname[256]; // [esp+Ch] [ebp-304h] BYREF
  char cmd[256]; // [esp+10Ch] [ebp-204h] BYREF
  char vmfFilename[260]; // [esp+20Ch] [ebp-104h] BYREF

  CFoundryTool::DestroyTools(this);
  V_strncpy(pDest: this->m_pBSPFileName, pSrc: pFileName, maxLen: 260);
  v3 = V_stristr(pStr: pFileName, pSearch: "\\game\\");
  if ( v3 == nullptr )
    return 0;
  v5 = V_stristr(pStr: pFileName, pSearch: "\\maps\\");
  if ( v5 == nullptr )
    return 0;
  V_strncpy(pDest: mapname, pSrc: v5 + 6, maxLen: 256);
  V_strncpy(pDest: vmfFilename, pSrc: pFileName, maxLen: v3 - pFileName + 1);
  V_strncat(pDest: vmfFilename, pSrc: "\\content\\", destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_strncat(pDest: vmfFilename, pSrc: v3 + 6, destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_SetExtension(path: vmfFilename, extension: ".vmf", pathStringLength: 260);
  ModuleState = AfxGetModuleState();
  this->m_pMapDoc = (CMapDoc *)(*(int (__thiscall **)(unsigned int, char *, int))(*(_DWORD *)ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                                + 132))(
                                 a1: ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl,
                                 a2: vmfFilename,
                                 a3: 1);
  V_snprintf(pDest: cmd, maxLen: 256, pFormat: "disconnect; map %s\n", mapname);
  enginetools->Command(this: enginetools, a2: cmd);
  enginetools->Execute(this: enginetools);
  this->ShowMiniViewport(this, a2: true);
  this->OnDefaultLayout(this);
  windowposmgr->LoadPositions(
    this: windowposmgr,
    a2: "cfg/foundry.txt",
    a3: this,
    a4: &this->m_ToolWindowFactory,
    a5: "Foundry",
    a6: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10106740
// Name: public: virtual void __near * CFoundryTool::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CFoundryTool::QueryInterface(CFoundryTool *this, const char *pInterfaceName)
{
  if ( _V_stricmp(s1: pInterfaceName, s2: "VSERVERFOUNDRY001") != 0 || this == (CFoundryTool *)380 )
    return nullptr;
  else
    return &this->_actionSignalTargetDar.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x10106780
// Name: public: virtual void CFoundryTool::MoveEntityTo(int,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::MoveEntityTo(
        CFoundryTool *this,
        int nHammerID,
        const Vector *vPos,
        const QAngle *vAngles)
{
  CMapEntity *EntityByHammerID; // eax
  CMapEntity *v5; // esi
  __int64 v6; // xmm0_8
  Vector vTempPos; // [esp+0h] [ebp-Ch] BYREF

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    EntityByHammerID = CMapDoc::FindEntityByHammerID(this: CMapDoc::m_pMapDoc, nHammerID);
    v5 = EntityByHammerID;
    if ( EntityByHammerID != nullptr )
    {
      v6 = *(_QWORD *)&vPos->x;
      vTempPos.z = vPos->z;
      *(_QWORD *)&vTempPos.x = v6;
      EntityByHammerID->SetOrigin(this: EntityByHammerID, a2: &vTempPos);
      if ( v5 != (CMapEntity *)-216 )
        v5->SetAngles(this: &v5->CEditGameClass, a2: vAngles);
    }
    else
    {
      _Warning(a1: "CFoundryTool::MoveEntityTo - no entity with HammerID %d\n", nHammerID);
    }
  }
  else
  {
    _Warning(a1: "CFoundryTool::MoveEntityTo - no active CMapDoc\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106810
// Name: public: virtual bool CFoundryTool::SetupEngineView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFoundryTool::SetupEngineView(
        CFoundryTool *this,
        Vector *origin,
        vgui::Menu *angles,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *fov)
{
  *(Vector *)&this->m_RecentFiles.m_RecentFiles.m_Size = *origin;
  *(QAngle *)&this->m_pToolUI = *(QAngle *)&angles->__vftable;
  this->m_hMiniViewport.m_iPanelID = (unsigned int)fov->m_Memory.m_pMemory;
  return CBaseTool::OnRMouseUp3D((vgui::TreeView *)this, itemIndex: (int)origin, menu: angles, msglist: fov);
}

//------------------------------------------------------------------------------
// Address: 0x10106870
// Name: public: virtual bool CFoundryTool::TrapKey(enum ButtonCode_t,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFoundryTool::TrapKey(CFoundryTool *this, ButtonCode_t key, bool down)
{
  return CBaseToolSystem::TrapKey(this, key, down);
}

//------------------------------------------------------------------------------
// Address: 0x10106880
// Name: public: virtual void CFoundryTool::DestroyEntity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::DestroyEntity(CFoundryTool *this, int iHammerID)
{
  servertools->DestroyEntityByHammerId(this: servertools, a2: iHammerID);
}

//------------------------------------------------------------------------------
// Address: 0x101068A0
// Name: public: virtual void CFoundryTool::OnModeChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnModeChanged(CFoundryTool *this)
{
  CMainFrame *v2; // eax
  int v3; // eax
  CMainFrame *MainWnd; // eax
  int m_nValue; // eax

  if ( GetMainWnd() != nullptr )
  {
    if ( !this->m_bGameInputEnabled && this->m_bIsActive )
    {
      MainWnd = GetMainWnd();
      CWnd::EnableWindow(this: MainWnd, bEnable: 1);
      if ( foundry_auto_pause.m_pParent != nullptr )
      {
        m_nValue = foundry_auto_pause.m_pParent->m_Value.m_nValue;
        if ( m_nValue == 1 )
        {
          enginetools->Command(this: enginetools, a2: "setpause");
        }
        else if ( m_nValue == 2 )
        {
          enginetools->Command(this: enginetools, a2: "ai_setenabled 0");
        }
      }
    }
    else
    {
      v2 = GetMainWnd();
      CWnd::EnableWindow(this: v2, bEnable: 0);
      if ( foundry_auto_pause.m_pParent != nullptr )
      {
        v3 = foundry_auto_pause.m_pParent->m_Value.m_nValue;
        if ( v3 == 1 )
        {
          enginetools->Command(this: enginetools, a2: "unpause");
        }
        else if ( v3 == 2 )
        {
          enginetools->Command(this: enginetools, a2: "ai_setenabled 1");
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106960
// Name: public: virtual void CFoundryTool::SwitchToEngine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::SwitchToEngine(CFoundryTool *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 20))(a1: (char *)this - 8);
}

//------------------------------------------------------------------------------
// Address: 0x10106970
// Name: public: virtual void CFoundryTool::MoveEngineViewTo(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::MoveEngineViewTo(CFoundryTool *this, const Vector *vPos, const QAngle *vAngles)
{
  servertools->MoveEngineViewTo(this: servertools, a2: vPos, a3: vAngles);
}

//------------------------------------------------------------------------------
// Address: 0x10106990
// Name: public: virtual void CFoundryTool::MoveHammerViewTo(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::MoveHammerViewTo(CFoundryTool *this, __POSITION *vPos, const QAngle *vAngles)
{
  CMapDoc *v3; // esi
  CView *v4; // eax
  void *v5; // eax
  CCamera *v6; // esi
  __POSITION *fDegrees; // [esp+Ch] [ebp-4h] BYREF

  v3 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    fDegrees = CMapDoc::m_pMapDoc->GetFirstViewPosition(this: CMapDoc::m_pMapDoc);
    if ( fDegrees != nullptr )
    {
      while ( 1 )
      {
        v4 = v3->GetNextView(this: v3, a2: &fDegrees);
        v5 = __RTDynamicCast(
               inptr: v4,
               VfDelta: 0,
               SrcType: &CView `RTTI Type Descriptor',
               TargetType: &CMapView3D `RTTI Type Descriptor',
               isReference: 0);
        if ( v5 != nullptr )
          break;
        if ( fDegrees == nullptr )
          return;
      }
      v6 = *((CCamera **)v5 + 35);
      CCamera::SetViewPoint(this: v6, ViewPoint: (const Vector *)vPos);
      CCamera::SetPitch(this: v6, fDegrees: vAngles->x);
      CCamera::SetYaw(this: v6, fDegrees: 90.0 - vAngles->y);
      CCamera::SetRoll(this: v6, fDegrees: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106A50
// Name: public: virtual void CFoundryTool::EngineGetMouseControl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::EngineGetMouseControl(CFoundryTool *this)
{
  HWND v2; // eax

  v2 = (HWND)enginetools->GetEngineHwnd(this: enginetools);
  SetFocus(hWnd: v2);
  CBaseToolSystem::SetMode(this: (CFoundryTool *)((char *)this - 484), bGameInputEnabled: true, bFullscreen: false);
}

//------------------------------------------------------------------------------
// Address: 0x10106A80
// Name: public: virtual void CFoundryTool::EngineReleaseMouseControl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::EngineReleaseMouseControl(CFoundryTool *this)
{
  CBaseToolSystem::SetMode(this: (CFoundryTool *)((char *)this - 484), bGameInputEnabled: false, bFullscreen: false);
}

//------------------------------------------------------------------------------
// Address: 0x10106A90
// Name: public: virtual void CFoundryTool::SelectEntities(int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::SelectEntities(CFoundryTool *this, int *pHammerIDs, int nIDs)
{
  CMapDoc *v3; // edi
  int i; // esi
  CMapEntity *EntityByHammerID; // eax

  v3 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    CMapDoc::ClearEntitySelection(this: CMapDoc::m_pMapDoc);
    for ( i = 0; i < nIDs; ++i )
    {
      EntityByHammerID = CMapDoc::FindEntityByHammerID(this: v3, nHammerID: pHammerIDs[i]);
      CMapDoc::SelectObject(this: v3, pObj: EntityByHammerID, cmd: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106AE0
// Name: public: CCamera::CCamera(class CCamera const __near &)
// Source: json
//------------------------------------------------------------------------------
CCamera *__thiscall CCamera::CCamera(CCamera *this, const CCamera *__that)
{
  this->__vftable = (CCamera_vtbl *)&CCamera::`vftable';
  qmemcpy(&this->m_ViewMatrix, &__that->m_ViewMatrix, 0x58u);
  qmemcpy(&this->m_ProjMatrix, &__that->m_ProjMatrix, 0x41u);
  this->m_fHorizontalFOV = __that->m_fHorizontalFOV;
  this->m_fNearClip = __that->m_fNearClip;
  this->m_fFarClip = __that->m_fFarClip;
  this->m_fZoom = __that->m_fZoom;
  this->m_fScaleHorz = __that->m_fScaleHorz;
  this->m_fScaleVert = __that->m_fScaleVert;
  this->m_nViewWidth = __that->m_nViewWidth;
  this->m_nViewHeight = __that->m_nViewHeight;
  qmemcpy(&this->m_ViewProjMatrix, &__that->m_ViewProjMatrix, sizeof(this->m_ViewProjMatrix));
  qmemcpy(&this->m_InvViewProjMatrix, &__that->m_InvViewProjMatrix, sizeof(this->m_InvViewProjMatrix));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10106BD0
// Name: public: class CCamera __near & CCamera::operator=(class CCamera const __near &)
// Source: json
//------------------------------------------------------------------------------
CCamera *__thiscall CCamera::operator=(CCamera *this, const CCamera *__that)
{
  VMatrix::operator=(this: &this->m_ViewMatrix, mOther: &__that->m_ViewMatrix);
  this->m_ViewPoint = __that->m_ViewPoint;
  this->m_fYaw = __that->m_fYaw;
  this->m_fPitch = __that->m_fPitch;
  this->m_fRoll = __that->m_fRoll;
  VMatrix::operator=(this: &this->m_ProjMatrix, mOther: &__that->m_ProjMatrix);
  this->m_bIsOrthographic = __that->m_bIsOrthographic;
  this->m_fHorizontalFOV = __that->m_fHorizontalFOV;
  this->m_fNearClip = __that->m_fNearClip;
  this->m_fFarClip = __that->m_fFarClip;
  this->m_fZoom = __that->m_fZoom;
  this->m_fScaleHorz = __that->m_fScaleHorz;
  this->m_fScaleVert = __that->m_fScaleVert;
  this->m_nViewWidth = __that->m_nViewWidth;
  this->m_nViewHeight = __that->m_nViewHeight;
  VMatrix::operator=(this: &this->m_ViewProjMatrix, mOther: &__that->m_ViewProjMatrix);
  VMatrix::operator=(this: &this->m_InvViewProjMatrix, mOther: &__that->m_InvViewProjMatrix);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10106CB0
// Name: private: static bool CFoundryTool::StaticQuitHandler(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CFoundryTool::StaticQuitHandler()
{
  AFX_MODULE_STATE *StaticModuleState; // eax
  CMainFrame *MainWnd; // eax
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+0h] [ebp-14h] BYREF
  int v4; // [esp+10h] [ebp-4h]

  StaticModuleState = AfxGetStaticModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: StaticModuleState);
  v4 = 0;
  MainWnd = GetMainWnd();
  if ( MainWnd != nullptr )
    PostMessageA(hWnd: MainWnd->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
  v4 = -1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10106D20
// Name: public: virtual void CFoundryTool::OnMapDocDestroy(class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnMapDocDestroy(CFoundryTool *this, CMapDoc *pDoc)
{
  if ( *(CMapDoc **)&this->m_InternalMouseDoublePressed_register == pDoc )
    *(_DWORD *)&this->m_InternalMouseDoublePressed_register = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10106E10
// Name: public: CChangeUndoScopeGuard::~CChangeUndoScopeGuard(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CChangeUndoScopeGuard::~CChangeUndoScopeGuard(CChangeUndoScopeGuard *this)
{
  CChangeUndoScopeGuard::Release(this);
}

//------------------------------------------------------------------------------
// Address: 0x10106E20
// Name: public: CDisableUndoScopeGuard::CDisableUndoScopeGuard(void)
// Source: json
//------------------------------------------------------------------------------
CDisableUndoScopeGuard *__thiscall CDisableUndoScopeGuard::CDisableUndoScopeGuard(CDisableUndoScopeGuard *this)
{
  *(_WORD *)&this->m_bReleased = 0;
  this->m_pNotify = nullptr;
  this->m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10106E90
// Name: public: CDisableUndoScopeGuard::~CDisableUndoScopeGuard(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDisableUndoScopeGuard::~CDisableUndoScopeGuard(CDisableUndoScopeGuard *this)
{
  CChangeUndoScopeGuard::Release(this);
}

//------------------------------------------------------------------------------
// Address: 0x10106F20
// Name: public: virtual class vgui::ToolWindow __near * CToolWindowFactory<class vgui::ToolWindow>::InstanceToolWindow(class vgui::Panel __near *,bool,class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ToolWindow *__thiscall CToolWindowFactory<vgui::ToolWindow>::InstanceToolWindow(
        CToolWindowFactory<vgui::ToolWindow> *this,
        vgui::Panel *parent,
        bool contextLabel,
        vgui::Panel *firstPage,
        const char *title,
        bool contextMenu)
{
  vgui::Panel *v6; // esi
  vgui::ToolWindow *v9; // eax
  vgui::ToolWindow *v10; // esi
  int mx; // [esp+Ch] [ebp-10h] BYREF
  int v12; // [esp+18h] [ebp-4h]

  v6 = parent;
  if ( parent == nullptr )
    return nullptr;
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: (int *)&parent);
  vgui::Panel::ScreenToLocal(this: v6, x: &mx, y: (int *)&parent);
  v9 = (vgui::ToolWindow *)operator new(nSize: 0x220u);
  v12 = 0;
  if ( v9 != nullptr )
    v10 = vgui::ToolWindow::ToolWindow(
            this: v9,
            parent: v6,
            contextlabel: contextLabel,
            factory: this,
            page: firstPage,
            title,
            contextMenu,
            inGlobalList: true);
  else
    v10 = nullptr;
  v12 = -1;
  if ( v10 != nullptr )
  {
    vgui::Panel::SetBounds(this: v10, x: mx, y: (int)parent, wide: 640, tall: 480);
    vgui::Panel::SetMinimumSize(this: v10, wide: 120, tall: 80);
    vgui::ToolWindow::SetToolWindowFactory(this: v10, factory: this);
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10107010
// Name: public: virtual bool CFoundryTool::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFoundryTool::Init(CFoundryTool *this)
{
  int (__thiscall *v2)(char *); // edx
  char *v3; // edi
  const char *v4; // eax
  bool result; // al
  void *(__cdecl *FactoryThis)(const char *, int *); // eax
  int v7; // eax
  const char *v8; // [esp+0h] [ebp-10Ch]
  char gamedir[260]; // [esp+8h] [ebp-104h] BYREF

  v2 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 95) + 976);
  v3 = (char *)this - 380;
  this->_fgColor = 0;
  v4 = (const char *)v2(a1: (char *)this - 380);
  CToolsRecentFileList::LoadFromRegistry(
    this: (CToolsRecentFileList *)&this->m_OnNavigateFrom_register,
    pToolKeyName: v4);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/toolfoundry_%language%.txt", a3: nullptr, a4: false);
  result = CBaseToolSystem::Init(this);
  if ( result )
  {
    enginetools->InstallQuitHandler(
      this: enginetools,
      a2: v3,
      a3: (bool (__cdecl *)(void *))CFoundryTool::StaticQuitHandler);
    FactoryThis = Sys_GetFactoryThis();
    v7 = ((int (__stdcall *)(const char *, _DWORD))FactoryThis)(a1: "Hammer001", a2: 0);
    this->m_RecentFiles.m_RecentFiles.m_Memory.m_nGrowSize = v7;
    if ( v7 == 0 )
      _Error(this: (ISceneTokenProcessor *)&stru_105F5390, a2: v8);
    enginetools->GetGameDir(this: enginetools, a2: gamedir, a3: 260);
    (*(void (__thiscall **)(int, void *(__cdecl *)(const char *, int *), _DWORD, char *))(*(_DWORD *)this->m_RecentFiles.m_RecentFiles.m_Memory.m_nGrowSize
                                                                                        + 72))(
      a1: this->m_RecentFiles.m_RecentFiles.m_Memory.m_nGrowSize,
      a2: g_MainFactory,
      a3: 0,
      a4: gamedir);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101070F0
// Name: public: CFoundryViewport::CFoundryViewport(class CFoundryTool __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFoundryViewport *__thiscall CFoundryViewport::CFoundryViewport(
        CFoundryViewport *this,
        CFoundryTool *pFoundryTool,
        vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  CMiniViewport::CMiniViewport(
    this,
    parent: pParent,
    contextLabel: true,
    factory: nullptr,
    page: nullptr,
    title: nullptr,
    contextMenu: false);
  this->__vftable = (CFoundryViewport_vtbl *)&CFoundryViewport::`vftable';
  if ( `CFoundryViewport::ChainToMap'::`2'::chained == 0 )
  {
    `CFoundryViewport::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CFoundryViewport");
    v4->pfnClassName = CFoundryViewport::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CMiniViewport");
  }
  if ( `CFoundryViewport::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFoundryViewport::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CFoundryViewport");
    v5->pfnClassName = CFoundryViewport::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CMiniViewport");
  }
  if ( `CFoundryViewport::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFoundryViewport::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CFoundryViewport");
    v6->pfnClassName = CFoundryViewport::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CMiniViewport");
  }
  this->m_pFoundryTool = pFoundryTool;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101071F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CFoundryViewport::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFoundryViewport::GetMessageMap(CFoundryViewport *this)
{
  if ( (`CFoundryViewport::GetMessageMap'::`2'::`local static guard' & 1) == 0 )
  {
    `CFoundryViewport::GetMessageMap'::`2'::`local static guard' |= 1u;
    `CFoundryViewport::GetMessageMap'::`2'::s_pMap = vgui::FindOrAddPanelMessageMap(className: "CFoundryViewport");
  }
  return `CFoundryViewport::GetMessageMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x10107250
// Name: public: virtual struct PanelAnimationMap __near * CFoundryViewport::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFoundryViewport::GetAnimMap(CFoundryViewport *this)
{
  return FindOrAddPanelAnimationMap(className: "CFoundryViewport");
}

//------------------------------------------------------------------------------
// Address: 0x10107260
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFoundryViewport::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFoundryViewport::GetKBMap(CFoundryViewport *this)
{
  if ( (`CFoundryViewport::GetKBMap'::`2'::`local static guard' & 1) == 0 )
  {
    `CFoundryViewport::GetKBMap'::`2'::`local static guard' |= 1u;
    `CFoundryViewport::GetKBMap'::`2'::s_pMap = vgui::FindOrAddPanelKeyBindingMap(className: "CFoundryViewport");
  }
  return `CFoundryViewport::GetKBMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x101072C0
// Name: public: virtual void CFoundryViewport::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryViewport::OnMousePressed(CFoundryViewport *this, ButtonCode_t code)
{
  CFoundryTool *m_pFoundryTool; // esi
  CMapDoc *m_pMapDoc; // ecx
  CMapView3D *First3DView; // edi
  int x; // [esp+4h] [ebp-4h] BYREF

  m_pFoundryTool = this->m_pFoundryTool;
  m_pMapDoc = m_pFoundryTool->m_pMapDoc;
  if ( m_pMapDoc != nullptr )
  {
    First3DView = CMapDoc::GetFirst3DView(this: m_pMapDoc);
    if ( First3DView != nullptr && code == KEY_COUNT )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&code);
      vgui::Panel::ScreenToLocal(this: m_pFoundryTool, &x, y: (int *)&code);
      CMapView3D::Foundry_OnLButtonDown(this: First3DView, x, y: code);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107380
// Name: public: virtual class CMiniViewport __near * CFoundryTool::CreateMiniViewport(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFoundryViewport *__thiscall CFoundryTool::CreateMiniViewport(CFoundryTool *this, vgui::Panel *parent)
{
  CFoundryViewport *v3; // eax
  CFoundryViewport *v4; // esi
  int Tall; // ebx
  int w; // [esp+Ch] [ebp-18h] BYREF
  int h; // [esp+10h] [ebp-14h] BYREF
  int wide; // [esp+14h] [ebp-10h] BYREF
  int v10; // [esp+20h] [ebp-4h]

  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &w, a3: &h);
  v3 = (CFoundryViewport *)operator new(nSize: 0x230u);
  wide = (int)v3;
  v4 = nullptr;
  v10 = 0;
  if ( v3 != nullptr )
    v4 = CFoundryViewport::CFoundryViewport(this: v3, pFoundryTool: this, pParent: parent);
  v10 = -1;
  v4->SetVisible(this: v4, a2: true);
  Tall = vgui::Panel::GetTall(this: this->m_pMenuBar);
  vgui::Panel::GetSize(this, &wide, tall: (int *)&parent);
  vgui::Panel::SetBounds(this: v4, x: 3, y: Tall + 3, wide: wide - 6, tall: (int)parent + -Tall - Tall - 3);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10107450
// Name: public: virtual void CFoundryTool::OnDrawHammerEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnDrawHammerEntities(CFoundryTool *this)
{
  int m_nValue; // eax
  vgui::ToolWindow *m_pViewMenuButton; // ecx
  vgui::Menu *Menu; // eax
  int v5; // edx

  if ( foundry_draw_hammer_entities.m_pParent != nullptr )
    m_nValue = foundry_draw_hammer_entities.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  ConVar::SetValue(this: (ConVar *)&foundry_draw_hammer_entities.IConVar, value: m_nValue == 0);
  m_pViewMenuButton = (vgui::ToolWindow *)this->m_pViewMenuButton;
  if ( m_pViewMenuButton != nullptr )
  {
    Menu = (vgui::Menu *)CToolMenuButton::GetMenu(this: m_pViewMenuButton);
    if ( Menu != nullptr )
    {
      if ( foundry_draw_hammer_entities.m_pParent != nullptr )
        v5 = foundry_draw_hammer_entities.m_pParent->m_Value.m_nValue;
      else
        v5 = 0;
      vgui::Menu::SetMenuItemChecked(
        this: Menu,
        itemID: this->m_pViewMenuButton->m_menuitemidDrawHammerEntities,
        state: v5 != 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101074C0
// Name: public: virtual void CFoundryTool::OnDrawHammerModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnDrawHammerModels(CFoundryTool *this)
{
  int m_nValue; // eax
  vgui::ToolWindow *m_pViewMenuButton; // ecx
  vgui::Menu *Menu; // eax
  int v5; // edx

  if ( foundry_draw_hammer_models.m_pParent != nullptr )
    m_nValue = foundry_draw_hammer_models.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  ConVar::SetValue(this: (ConVar *)&foundry_draw_hammer_models.IConVar, value: m_nValue == 0);
  m_pViewMenuButton = (vgui::ToolWindow *)this->m_pViewMenuButton;
  if ( m_pViewMenuButton != nullptr )
  {
    Menu = (vgui::Menu *)CToolMenuButton::GetMenu(this: m_pViewMenuButton);
    if ( Menu != nullptr )
    {
      if ( foundry_draw_hammer_models.m_pParent != nullptr )
        v5 = foundry_draw_hammer_models.m_pParent->m_Value.m_nValue;
      else
        v5 = 0;
      vgui::Menu::SetMenuItemChecked(
        this: Menu,
        itemID: this->m_pViewMenuButton->m_menuitemidDrawHammerModels,
        state: v5 != 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107530
// Name: public: virtual void CFoundryTool::OnDrawGameEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnDrawGameEntities(CFoundryTool *this)
{
  vgui::ToolWindow *m_pViewMenuButton; // ecx
  vgui::Menu *Menu; // eax
  char szConCommand[52]; // [esp+4h] [ebp-44h] BYREF
  BOOL bDrawGameEntities; // [esp+38h] [ebp-10h]
  int v6; // [esp+44h] [ebp-4h]

  if ( (_S1_19 & 1) == 0 )
  {
    _S1_19 |= 1u;
    ConVarRef::ConVarRef(this: &stru_107B166C, pName: "r_drawentities");
    v6 = -1;
  }
  LOBYTE(bDrawGameEntities) = stru_107B166C.m_pConVarState->m_Value.m_nValue == 0;
  V_snprintf(pDest: szConCommand, maxLen: 50, pFormat: "r_drawentities %i\n", bDrawGameEntities);
  enginetools->Command(this: enginetools, a2: szConCommand);
  m_pViewMenuButton = (vgui::ToolWindow *)this->m_pViewMenuButton;
  if ( m_pViewMenuButton != nullptr )
  {
    Menu = (vgui::Menu *)CToolMenuButton::GetMenu(this: m_pViewMenuButton);
    if ( Menu != nullptr )
      vgui::Menu::SetMenuItemChecked(
        this: Menu,
        itemID: this->m_pViewMenuButton->m_menuitemidDrawGameEntities,
        state: bDrawGameEntities);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101075F0
// Name: public: virtual void CFoundryTool::OnDrawEntityHighlights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnDrawEntityHighlights(CFoundryTool *this)
{
  ConVar *v2; // eax
  ConVar *v3; // esi
  ConVar *m_pParent; // eax
  int v5; // eax
  vgui::ToolWindow *m_pViewMenuButton; // ecx
  vgui::Menu *Menu; // eax
  ConVar *v8; // esi
  int m_nValue; // edx

  v2 = cvar->FindVar_2(this: cvar, a2: "cl_foundry_ShowEntityHighlights");
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_pParent = v2->m_pParent;
    v5 = m_pParent != nullptr ? m_pParent->m_Value.m_nValue : 0;
    v3->SetValue_2(this: &v3->IConVar, a2: v5 == 0);
    m_pViewMenuButton = (vgui::ToolWindow *)this->m_pViewMenuButton;
    if ( m_pViewMenuButton != nullptr )
    {
      Menu = (vgui::Menu *)CToolMenuButton::GetMenu(this: m_pViewMenuButton);
      if ( Menu != nullptr )
      {
        v8 = v3->m_pParent;
        if ( v8 != nullptr )
          m_nValue = v8->m_Value.m_nValue;
        else
          m_nValue = 0;
        vgui::Menu::SetMenuItemChecked(
          this: Menu,
          itemID: this->m_pViewMenuButton->m_menuitemidDrawEntityHighlights,
          state: m_nValue != 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107670
// Name: public: virtual void CFoundryTool::OnUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnUndo(CFoundryTool *this)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CDisableUndoScopeGuard guard; // [esp+0h] [ebp-14h] BYREF
  int v3; // [esp+10h] [ebp-4h]

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  guard.m_bNotify = false;
  *(_WORD *)&guard.m_bOldValue = ((unsigned __int8 (__thiscall *)(IDataModel *, _DWORD))IsUndoEnabled)(
                                   a1: g_pDataModel,
                                   a2: 0);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  v3 = 1;
  g_pDataModel->Undo(this: g_pDataModel);
  v3 = -1;
  CChangeUndoScopeGuard::Release(this: &guard);
}

//------------------------------------------------------------------------------
// Address: 0x10107700
// Name: public: virtual void CFoundryTool::OnRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnRedo(CFoundryTool *this)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CDisableUndoScopeGuard guard; // [esp+0h] [ebp-14h] BYREF
  int v3; // [esp+10h] [ebp-4h]

  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  guard.m_bNotify = false;
  *(_WORD *)&guard.m_bOldValue = ((unsigned __int8 (__thiscall *)(IDataModel *, _DWORD))IsUndoEnabled)(
                                   a1: g_pDataModel,
                                   a2: 0);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  v3 = 1;
  g_pDataModel->Redo(this: g_pDataModel);
  v3 = -1;
  CChangeUndoScopeGuard::Release(this: &guard);
}

//------------------------------------------------------------------------------
// Address: 0x10107790
// Name: public: virtual void CFoundryTool::ClientPostRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::ClientPostRender(CFoundryTool *this)
{
  CMapDoc *fgColor; // ecx
  CMapView3D *First3DView; // eax
  CMapView3D *v4; // edi
  CCamera *m_pCamera; // esi
  float v6; // xmm3_4
  float v7; // xmm0_4
  Vector fNearClip; // [esp+4h] [ebp-38h] BYREF
  Vector v9; // [esp+10h] [ebp-2Ch] BYREF
  float v10[2]; // [esp+1Ch] [ebp-20h] BYREF
  Vector vecLookAt; // [esp+24h] [ebp-18h]
  Vector vForward; // [esp+30h] [ebp-Ch]

  fgColor = (CMapDoc *)this->_fgColor;
  if ( fgColor != nullptr
    && foundry_draw_hammer_entities.m_pParent != nullptr
    && foundry_draw_hammer_entities.m_pParent->m_Value.m_nValue != 0 )
  {
    First3DView = CMapDoc::GetFirst3DView(this: fgColor);
    v4 = First3DView;
    if ( First3DView != nullptr )
    {
      m_pCamera = First3DView->m_pCamera;
      vecLookAt.z = CCamera::GetPitch(this: m_pCamera);
      vecLookAt.y = CCamera::GetYaw(this: m_pCamera);
      CCamera::GetViewPoint(this: m_pCamera, ViewPoint: &fNearClip);
      vForward.x = CCamera::GetFOV(this: m_pCamera);
      vForward.y = CCamera::GetNearClip(this: m_pCamera);
      vForward.z = CCamera::GetFarClip(this: m_pCamera);
      AngleVectors(angles: (const QAngle *)&this->m_pToolUI, forward: (Vector *)v10);
      v6 = *(float *)&this->m_RecentFiles.m_RecentFiles.m_Size + (float)(v10[0] * 100.0);
      v9.y = *(float *)&this->m_RecentFiles.m_RecentFiles.m_pElements + (float)(v10[1] * 100.0);
      v7 = *(float *)&this->m_OnFileStateMachineFinished_register + (float)(vecLookAt.x * 100.0);
      v9.x = v6;
      v9.z = v7;
      CMapView3D::SetCamera(this: v4, vecPos: (const Vector *)&this->m_RecentFiles.m_RecentFiles.m_Size, vecLookAt: &v9);
      CMapView3D::RenderView2(this: v4, bRenderingOverEngine: true);
      CCamera::SetViewPoint(this: m_pCamera, ViewPoint: &fNearClip);
      CCamera::SetPerspective(this: m_pCamera, fHorizontalFOV: vForward.x, fNearClip: vForward.y, fFarClip: vForward.z);
      CCamera::SetPitch(this: m_pCamera, fDegrees: vecLookAt.z);
      CCamera::SetYaw(this: m_pCamera, fDegrees: vecLookAt.y);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101078F0
// Name: public: virtual bool CFoundryTool::ShouldRender3DModels(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFoundryTool::ShouldRender3DModels(CFoundryTool *this)
{
  return foundry_draw_hammer_models.m_pParent != nullptr && foundry_draw_hammer_models.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10107910
// Name: public: virtual void CFoundryTool::SelectionClickInCenterOfView(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::SelectionClickInCenterOfView(
        CFoundryTool *this,
        const Vector *vPos,
        const QAngle *vAngles)
{
  CMapDoc *v3; // edi
  CView *v4; // eax
  void *v5; // esi
  CToolManager *m_pToolManager; // edi
  int ActiveTool; // ebx
  CCamera *v8; // edi
  float fDegrees[4]; // [esp+10h] [ebp-168h] BYREF
  CCamera cameraBackup; // [esp+20h] [ebp-158h] BYREF
  tagRECT rc; // [esp+160h] [ebp-18h] BYREF
  Vector2D vPoint; // [esp+170h] [ebp-8h]

  v3 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    rc.right = (int)CMapDoc::m_pMapDoc->GetFirstViewPosition(this: CMapDoc::m_pMapDoc);
    if ( rc.right != 0 )
    {
      while ( 1 )
      {
        v4 = v3->GetNextView(this: v3, a2: (__POSITION **)&rc.right);
        v5 = __RTDynamicCast(
               inptr: v4,
               VfDelta: 0,
               SrcType: &CView `RTTI Type Descriptor',
               TargetType: &CMapView3D `RTTI Type Descriptor',
               isReference: 0);
        if ( v5 != nullptr )
          break;
        if ( rc.right == 0 )
          return;
      }
      m_pToolManager = v3->m_pToolManager;
      CToolManager::SetTool(this: m_pToolManager, eNewTool: TOOL_POINTER);
      ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
      if ( ActiveTool != 0 )
      {
        v8 = *((CCamera **)v5 + 35);
        CCamera::CCamera(this: (CCamera *)fDegrees, __that: v8);
        vPoint.y = 0.0;
        CCamera::SetViewPoint(this: v8, ViewPoint: vPos);
        CCamera::SetPitch(this: v8, fDegrees: vAngles->x);
        CCamera::SetYaw(this: v8, fDegrees: 90.0 - vAngles->y);
        CCamera::SetRoll(this: v8, fDegrees: 0.0);
        GetClientRect(hWnd: *((HWND *)v5 + 8), lpRect: (LPRECT)cameraBackup.m_InvViewProjMatrix.m[3]);
        *(float *)&rc.left = (float)((LODWORD(cameraBackup.m_InvViewProjMatrix.m[3][2])
                                    - LODWORD(cameraBackup.m_InvViewProjMatrix.m[3][0]))
                                   / 2);
        *(float *)&rc.top = (float)((LODWORD(cameraBackup.m_InvViewProjMatrix.m[3][3])
                                   - LODWORD(cameraBackup.m_InvViewProjMatrix.m[3][1]))
                                  / 2);
        (*(void (__thiscall **)(int, void *, _DWORD, tagRECT *))(*(_DWORD *)ActiveTool + 60))(
          a1: ActiveTool,
          a2: v5,
          a3: 0,
          a4: &rc);
        (*(void (__thiscall **)(int, void *, _DWORD, tagRECT *))(*(_DWORD *)ActiveTool + 64))(
          a1: ActiveTool,
          a2: v5,
          a3: 0,
          a4: &rc);
        CCamera::operator=(this: v8, __that: (const CCamera *)fDegrees);
        vPoint.y = NAN;
        CCamera::~CCamera(this: (CCamera *)fDegrees);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107AB0
// Name: public: void CUtlMemory<struct vgui::KeyBindingMap_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::KeyBindingMap_t,int>::Grow(CUtlMemory<vgui::KeyBindingMap_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::KeyBindingMap_t *m_pMemory; // ecx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::KeyBindingMap_t *)_realloc_crt(ptr: m_pMemory, size: 48 * m_nAllocationCount);
    else
      this->m_pMemory = (vgui::KeyBindingMap_t *)MemAlloc_Alloc(nSize: 48 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107C10
// Name: public: virtual void CFoundryTool::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::Shutdown(CFoundryTool *this)
{
  const char *v2; // eax
  int v3; // edi
  vgui::PHandle *m_pMemory; // ebx
  BOOL guard_4; // [esp+10h] [ebp-10h]

  v2 = (const char *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 95) + 976))(a1: (char *)this - 380);
  CToolsRecentFileList::SaveToRegistry(this: (CToolsRecentFileList *)&this->m_OnNavigateFrom_register, pToolKeyName: v2);
  v3 = 0;
  BYTE2(guard_4) = 0;
  LOWORD(guard_4) = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_pMemory = this->m_Tools.m_Memory.m_pMemory;
  if ( (int)m_pMemory > 0 )
  {
    do
      g_pDataModel->DestroyElement(this: g_pDataModel, a2: *(DmElementHandle_t *)(this->m_KeyBindingsHandle + 4 * v3++));
    while ( v3 < (int)m_pMemory );
  }
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: guard_4);
  this->_fgColor = 0;
  CBaseToolSystem::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x10107CF0
// Name: private: void CFoundryTool::UpdateMenuBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::UpdateMenuBar(CFoundryTool *this)
{
  CMapDoc *m_pMapDoc; // eax
  const char *m_pszData; // edi
  char *v4; // [esp-8h] [ebp-20Ch]
  char sz[512]; // [esp+4h] [ebp-200h] BYREF

  m_pMapDoc = this->m_pMapDoc;
  if ( m_pMapDoc != nullptr )
  {
    m_pszData = m_pMapDoc->m_strPathName.m_pszData;
    if ( *m_pszData != 0 )
    {
      v4 = m_pMapDoc->m_strPathName.m_pszData;
      if ( m_pMapDoc->IsModified(this: m_pMapDoc) != 0 )
      {
        V_snprintf(pDest: sz, maxLen: 512, pFormat: "* %s", m_pszData);
        v4 = sz;
      }
      CToolFileMenuBar::SetFileName(this: this->m_pMenuBar, name: v4);
    }
    else
    {
      CToolFileMenuBar::SetFileName(this: this->m_pMenuBar, name: "#FoundryNoFile");
    }
  }
  else
  {
    CToolFileMenuBar::SetFileName(this: this->m_pMenuBar, name: "#FoundryNoFile");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107D80
// Name: public: virtual bool CFoundryTool::GetPerforceFileName(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFoundryTool::GetPerforceFileName(CFoundryTool *this, char *pFileName, int nMaxLen)
{
  int v4; // eax
  const char *v5; // eax

  if ( *(_DWORD *)&this->m_InternalKeyCodePressed_register == 0 )
    return false;
  v4 = *(_DWORD *)&this->m_InternalKeyCodePressed_register;
  if ( v4 != 0 )
    v5 = *(const char **)(v4 + 36);
  else
    v5 = &var;
  V_strncpy(pDest: pFileName, pSrc: v5, maxLen: nMaxLen);
  return *pFileName != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10107DC0
// Name: public: virtual void CFoundryTool::OnNew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnNew(CFoundryTool *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CMapDoc *m_pMapDoc; // ecx
  const char *m_pszData; // ecx

  if ( this->m_pMapDoc != nullptr && this->m_pMapDoc->IsModified(this: this->m_pMapDoc) != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnNew");
    else
      v3 = nullptr;
    m_pMapDoc = this->m_pMapDoc;
    if ( m_pMapDoc != nullptr )
      m_pszData = m_pMapDoc->m_strPathName.m_pszData;
    else
      m_pszData = &var;
    CBaseToolSystem::SaveFile(this, pFileName: m_pszData, pFileType: "vmf", nFlags: 3, pContextKeyValues: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107E60
// Name: public: virtual void CFoundryTool::OnOpen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnOpen(CFoundryTool *this)
{
  int v2; // ebx
  const char *m_pszData; // edi
  CMapDoc *m_pMapDoc; // eax

  v2 = 0;
  m_pszData = nullptr;
  if ( this->m_pMapDoc != nullptr && this->m_pMapDoc->IsModified(this: this->m_pMapDoc) != 0 )
  {
    m_pMapDoc = this->m_pMapDoc;
    v2 = 3;
    if ( m_pMapDoc != nullptr )
      m_pszData = m_pMapDoc->m_strPathName.m_pszData;
    else
      m_pszData = &var;
  }
  CBaseToolSystem::OpenFile(
    this,
    pOpenFileType: "bsp",
    pSaveFileName: m_pszData,
    pSaveFileType: "vmf",
    nFlags: v2,
    pContextKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10107EC0
// Name: public: virtual bool CFoundryTool::OnReadFileFromDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFoundryTool::OnReadFileFromDisk(
        CFoundryTool *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  char result; // al
  const char *v6; // eax

  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 96) + 1052))(a1: (char *)this - 384);
  result = CFoundryTool::LoadDocument(this: (CFoundryTool *)((char *)this - 384), pFileName);
  if ( result != 0 )
  {
    CToolsRecentFileList::Add(this: (CToolsRecentFileList *)&this->m_OnDelete_register, pFileName, pFileFormat);
    v6 = (const char *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 96) + 976))(a1: (char *)this - 384);
    CToolsRecentFileList::SaveToRegistry(this: (CToolsRecentFileList *)&this->m_OnDelete_register, pToolKeyName: v6);
    CFoundryTool::UpdateMenuBar(this: (CFoundryTool *)((char *)this - 384));
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10107F40
// Name: public: virtual void CFoundryTool::OnSaveAs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnSaveAs(CFoundryTool *this)
{
  CMapDoc *m_pMapDoc; // eax

  m_pMapDoc = this->m_pMapDoc;
  if ( m_pMapDoc != nullptr )
    CBaseToolSystem::SaveFile(
      this,
      pFileName: m_pMapDoc->m_strPathName.m_pszData,
      pFileType: "vmf",
      nFlags: 1,
      pContextKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10107F60
// Name: public: virtual bool CFoundryTool::OnWriteFileToDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFoundryTool::OnWriteFileToDisk(
        CFoundryTool *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  const char *v5; // eax

  if ( this->m_OverridableColorEntries.m_pElements != nullptr )
  {
    (*((void (__thiscall **)(vgui::OverridableColorEntry *, const char *, int))this->m_OverridableColorEntries.m_pElements->m_pszScriptName
     + 22))(
      a1: this->m_OverridableColorEntries.m_pElements,
      a2: pFileName,
      a3: 1);
    CMapDoc::SaveVMF(this: (CMapDoc *)this->m_OverridableColorEntries.m_pElements, pszFileName: pFileName, saveFlags: 0);
    CToolsRecentFileList::Add(this: (CToolsRecentFileList *)&this->m_OnDelete_register, pFileName, pFileFormat);
    v5 = (const char *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 96) + 976))(a1: (char *)this - 384);
    CToolsRecentFileList::SaveToRegistry(this: (CToolsRecentFileList *)&this->m_OnDelete_register, pToolKeyName: v5);
    CFoundryTool::UpdateMenuBar(this: (CFoundryTool *)((char *)this - 384));
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10107FD0
// Name: public: virtual void CFoundryTool::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnClose(CFoundryTool *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CMapDoc *m_pMapDoc; // ecx
  const char *m_pszData; // ecx

  if ( this->m_pMapDoc != nullptr && this->m_pMapDoc->IsModified(this: this->m_pMapDoc) != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnClose");
    else
      v3 = nullptr;
    m_pMapDoc = this->m_pMapDoc;
    if ( m_pMapDoc != nullptr )
      m_pszData = m_pMapDoc->m_strPathName.m_pszData;
    else
      m_pszData = &var;
    CBaseToolSystem::SaveFile(this, pFileName: m_pszData, pFileType: "vmf", nFlags: 3, pContextKeyValues: v3);
  }
  else
  {
    this->OnCloseNoSave(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108090
// Name: public: virtual bool CFoundryTool::CanQuit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFoundryTool::CanQuit(CFoundryTool *this, const char *pExitMsg)
{
  CBaseToolSystem *v2; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  int v5; // ecx
  const char *v6; // ecx

  v2 = (CFoundryTool *)((char *)this - 380);
  if ( *(_DWORD *)&this->_fgColor == 0
    || (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&v2[1].m_InternalKeyFocusTicked_register + 96))(a1: *(_DWORD *)&v2[1].m_InternalKeyFocusTicked_register) == 0 )
  {
    return 1;
  }
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: pExitMsg);
  else
    v4 = nullptr;
  v5 = *(_DWORD *)&v2[1].m_InternalKeyFocusTicked_register;
  if ( v5 != 0 )
    v6 = *(const char **)(v5 + 36);
  else
    v6 = &var;
  CBaseToolSystem::SaveFile(this: v2, pFileName: v6, pFileType: "vmf", nFlags: 3, pContextKeyValues: v4);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10108150
// Name: public: virtual void CFoundryTool::OnDocChanged(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFoundryTool::OnDocChanged(
        CFoundryTool *this,
        const char *pReason,
        const char *nNotifySource,
        int nNotifyFlags)
{
  CFoundryTool::UpdateMenuBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x10108160
// Name: public: virtual bool CFoundryTool::UpdateEntity(int,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFoundryTool::UpdateEntity(
        CFoundryTool *this,
        int iHammerID,
        CUtlVector<char *,CUtlMemory<char *,int> > *keys,
        CUtlVector<char *,CUtlMemory<char *,int> > *values)
{
  void *v4; // ebx
  int i; // esi

  v4 = servertools->FindEntityByHammerID(this: servertools, a2: iHammerID);
  if ( v4 == nullptr )
    return 0;
  for ( i = 0; i < keys->m_Size; ++i )
    servertools->SetKeyValue_3(
      this: servertools,
      a2: v4,
      a3: keys->m_Memory.m_pMemory[i],
      a4: values->m_Memory.m_pMemory[i]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101081C0
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101083B0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108400
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108B50
// Name: public: void CFoundryTool::OnDescribeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnDescribeUndo(CFoundryTool *this)
{
  int v1; // edi
  int v2; // ebx
  UndoInfo_t *v3; // esi
  UndoInfo_t *m_pMemory; // eax
  CUtlVector<UndoInfo_t,CUtlMemory<UndoInfo_t,int> > list; // [esp+8h] [ebp-20h] BYREF
  int v6; // [esp+24h] [ebp-4h]

  memset(&list, 0, sizeof(list));
  v6 = 1;
  g_pDataModel->GetUndoInfo(this: g_pDataModel, a2: &list);
  _Msg(a1: "%i operations in stack\n", list.m_Size);
  v1 = list.m_Size - 1;
  if ( list.m_Size - 1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &list.m_Memory.m_pMemory[v2];
      if ( list.m_Memory.m_pMemory[v2].terminator )
        _Msg(a1: "[ '%s' ] - %i operations\n", v3->undo, v3->numoperations);
      _Msg(a1: "   +%s\n", v3->desc);
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  v6 = 2;
  m_pMemory = list.m_Memory.m_pMemory;
  list.m_Size = 0;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( list.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: list.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  list.m_pElements = m_pMemory;
  v6 = -1;
  if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
    free(pMem: list.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10108C60
// Name: public: virtual void CFoundryTool::OnReloadFromSaveSlamEnts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnReloadFromSaveSlamEnts(CFoundryTool *this)
{
  bool v2; // sf

  v2 = this->m_SavegameRestoredEnts.m_Memory.m_nGrowSize < 0;
  this->m_SavegameRestoredEnts.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_SavegameRestoredEnts.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_SavegameRestoredEnts.m_Memory.m_pMemory);
      this->m_SavegameRestoredEnts.m_Memory.m_pMemory = nullptr;
    }
    this->m_SavegameRestoredEnts.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SavegameRestoredEnts.m_pElements = this->m_SavegameRestoredEnts.m_Memory.m_pMemory;
  enginetools->Command(this: enginetools, a2: "load quick * LetToolsOverrideLoadGameEnts\n");
  enginetools->Execute(this: enginetools);
}

//------------------------------------------------------------------------------
// Address: 0x10108D30
// Name: public: static void CFoundryTool::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFoundryTool::KB_AddToMap(
        int a1@<ebp>,
        const char *bindingname,
        ButtonCode_t defaultcode,
        int default_modifiers,
        __int128 function,
        __int64 helpstring,
        bool passive)
{
  vgui::PanelKeyBindingMap *v7; // esi
  _DWORD v8[3]; // [esp-Ch] [ebp-5Ch] BYREF
  vgui::KeyBindingMap_t entry; // [esp+0h] [ebp-50h] BYREF
  vgui::BoundKey_t kb; // [esp+30h] [ebp-20h]
  int v11; // [esp+40h] [ebp-10h]
  int v12; // [esp+44h] [ebp-Ch]
  void *v13; // [esp+48h] [ebp-8h]
  int v14; // [esp+4Ch] [ebp-4h] BYREF
  void *retaddr; // [esp+50h] [ebp+0h]

  v12 = a1;
  v13 = retaddr;
  v11 = -1;
  kb.modifiers = (int)&_ehhandler__KB_AddToMap_CFoundryTool__SAXPBDW4ButtonCode_t__HP8Panel_vgui__AEXXZ00_N_Z;
  kb.keycode = (int)NtCurrentTeb()->NtTib.ExceptionList;
  kb.bindingname = (const char *)&v14;
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CFoundryTool");
  vgui::KeyBindingMap_t::KeyBindingMap_t(this: (vgui::KeyBindingMap_t *)v8);
  v11 = 0;
  *(_OWORD *)(&entry.bindingname + 1) = function;
  *(_QWORD *)((char *)&entry.func + 4) = helpstring;
  v8[0] = bindingname;
  BYTE12(entry.func) = passive;
  CUtlVector<vgui::KeyBindingMap_t,CUtlMemory<vgui::KeyBindingMap_t,int>>::InsertBefore(
    this: &v7->entries,
    elem: v7->entries.m_Size,
    src: (const vgui::KeyBindingMap_t *)v8);
  vgui::BoundKey_t::BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  LOBYTE(v11) = 1;
  LOBYTE(entry.docstring) = 1;
  *((_DWORD *)&entry.passive + 1) = defaultcode;
  *(_DWORD *)&entry.passive = bindingname;
  *(_DWORD *)&kb.isbuiltin = default_modifiers;
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->defaultkeys,
    elem: v7->defaultkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->boundkeys,
    elem: v7->boundkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  LOBYTE(v11) = 0;
  vgui::BoundKey_t::~BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  v11 = -1;
  CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x10108E30
// Name: public: static void CFoundryTool::PanelMessageFunc_OnNew::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnNew::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnNew::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnNew::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1036,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnNew";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108EC0
// Name: public: static void CFoundryTool::PanelMessageFunc_OnOpen::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnOpen::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnOpen::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnOpen::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertySheet::`vcall'{1040,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnOpen";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108F50
// Name: public: static void CFoundryTool::PanelMessageFunc_OnSave::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnSave::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnSave::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnSave::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1044,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnSave";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108FF0
// Name: public: static void CFoundryTool::PanelMessageFunc_OnSaveAs::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnSaveAs::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnSaveAs::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnSaveAs::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1048,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnSaveAs";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109080
// Name: public: static void CFoundryTool::PanelMessageFunc_OnClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnClose::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnClose::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFoundryTool::`vcall'{940,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109110
// Name: public: static void CFoundryTool::PanelMessageFunc_OnCloseNoSave::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnCloseNoSave::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnCloseNoSave::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnCloseNoSave::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertySheet::`vcall'{1052,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCloseNoSave";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101091A0
// Name: public: static void CFoundryTool::PanelMessageFunc_OnMarkNotDirty::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnMarkNotDirty::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1056,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnMarkNotDirty";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109230
// Name: public: static void CFoundryTool::PanelMessageFunc_OnExit::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnExit::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnExit::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnExit::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Menu::`vcall'{1060,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnExit";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101092C0
// Name: public: static void CFoundryTool::PanelMessageFunc_OnUpdateHammerEntity::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnUpdateHammerEntity::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnUpdateHammerEntity::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnUpdateHammerEntity::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Button::`vcall'{1072,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "UpdateHammerEntity";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109350
// Name: public: static void CFoundryTool::PanelMessageFunc_OnReload::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnReload::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnReload::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnReload::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TreeView::`vcall'{1076,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ReloadMap";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101093E0
// Name: public: static void CFoundryTool::PanelMessageFunc_OnReloadFromSave::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnReloadFromSave::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnReloadFromSave::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnReloadFromSave::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1080,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ReloadFromSave";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109470
// Name: public: static void CFoundryTool::PanelMessageFunc_OnReloadFromSaveSlamEnts::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnReloadFromSaveSlamEnts::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnReloadFromSaveSlamEnts::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnReloadFromSaveSlamEnts::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{1084,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ReloadFromSaveSlamEnts";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109500
// Name: public: static void CFoundryTool::PanelMessageFunc_OnDefaultLayout::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnDefaultLayout::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnDefaultLayout::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnDefaultLayout::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1088,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnDefaultLayout";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109590
// Name: public: static void CFoundryTool::PanelMessageFunc_OnDrawHammerEntities::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnDrawHammerEntities::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnDrawHammerEntities::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnDrawHammerEntities::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1092,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnDrawHammerEntities";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109620
// Name: public: static void CFoundryTool::PanelMessageFunc_OnDrawHammerModels::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnDrawHammerModels::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnDrawHammerModels::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnDrawHammerModels::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1096,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnDrawHammerModels";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101096B0
// Name: public: static void CFoundryTool::PanelMessageFunc_OnDrawEntityHighlights::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnDrawEntityHighlights::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnDrawEntityHighlights::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnDrawEntityHighlights::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1100,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnDrawEntityHighlights";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109740
// Name: public: static void CFoundryTool::PanelMessageFunc_OnDrawGameEntities::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnDrawGameEntities::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnDrawGameEntities::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnDrawGameEntities::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ListPanel::`vcall'{1104,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnDrawGameEntities";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101097D0
// Name: public: static void CFoundryTool::PanelMessageFunc_OnSyncHammerView::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFoundryTool::PanelMessageFunc_OnSyncHammerView::InitVar(int a1@<ebp>)
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
  if ( !`CFoundryTool::PanelMessageFunc_OnSyncHammerView::InitVar'::`2'::bAdded )
  {
    `CFoundryTool::PanelMessageFunc_OnSyncHammerView::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{1108,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnSyncHammerView";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109860
// Name: int FindEntitiesInVisGroupCallback(class CMapEntity __near *,class CVisGroupEntList __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindEntitiesInVisGroupCallback(CMapEntity *pObject, CUtlMemory<CCullTreeNode *,int> *pList)
{
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CMapClass **v4; // ecx
  int v5; // eax
  CMapClass **v6; // eax

  if ( pObject != nullptr && CMapClass::IsInVisGroup(this: pObject, pVisGroup: (CVisGroup *)pList[1].m_nGrowSize) != 0 )
  {
    m_nAllocationCount = pList->m_nAllocationCount;
    m_pMemory = (int)pList[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow(this: pList, num: m_pMemory - m_nAllocationCount + 1);
    ++pList[1].m_pMemory;
    v4 = (CMapClass **)pList->m_pMemory;
    v5 = (int)pList[1].m_pMemory - m_pMemory - 1;
    pList[1].m_nAllocationCount = (int)pList->m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &v4[m_pMemory + 1], src: &v4[m_pMemory], count: 4 * v5);
    v6 = (CMapClass **)&pList->m_pMemory[m_pMemory];
    if ( v6 != nullptr )
      *v6 = pObject;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101098E0
// Name: foundry_spawn_visgroup
// Source: json
//------------------------------------------------------------------------------
void __cdecl foundry_spawn_visgroup(const CCommand *args)
{
  CMapDoc *v1; // esi
  const char *v2; // edi
  CVisGroup *v3; // eax
  CVisGroupEntList theList; // [esp+8h] [ebp-24h] BYREF
  int v5; // [esp+28h] [ebp-4h]

  v1 = CMapDoc::m_pMapDoc;
  if ( g_pFoundryTool != nullptr && CMapDoc::m_pMapDoc != nullptr )
  {
    if ( args->m_nArgc >= 2 )
    {
      v2 = &var;
      if ( args->m_nArgc > 1 )
        v2 = args->m_ppArgv[1];
      v3 = CMapDoc::VisGroups_GroupForName(this: CMapDoc::m_pMapDoc, pszName: v2, bIsAuto: false);
      if ( v3 != nullptr || (v3 = CMapDoc::VisGroups_GroupForName(this: v1, pszName: v2, bIsAuto: true)) != nullptr )
      {
        memset(&theList, 0, 20);
        v5 = 2;
        theList.m_pGroup = v3;
        CMapClass::EnumChildren(
          this: v1->m_pWorld,
          pfn: (int (__cdecl *)(CMapClass *, unsigned int))FindEntitiesInVisGroupCallback,
          dwParam: (unsigned int)&theList,
          Type: CMapEntity::__Type);
        g_pFoundryTool->RespawnEntitiesWithEdits(
          this: g_pFoundryTool,
          a2: theList.m_Entities.m_Memory.m_pMemory,
          a3: theList.m_Entities.m_Size);
        v5 = -1;
        CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&theList);
      }
      else
      {
        _Warning(a1: "Can't find visgroup '%s'\n", v2);
      }
    }
    else
    {
      _Warning(a1: "Visgroup name required.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109A00
// Name: public: virtual void CFoundryTool::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnCommand(CFoundryTool *this, const char *cmd)
{
  vgui::Menu *ActionMenu; // eax
  const char *v4; // eax
  int v5; // eax
  const char *File; // eax
  const char *v7; // eax
  int v8; // eax

  if ( _V_stricmp(s1: cmd, s2: "HideActionMenu") != 0 )
  {
    v4 = StringAfterPrefix(str: cmd, prefix: "OnRecent");
    if ( v4 != nullptr )
    {
      v5 = V_atoi(str: v4);
      File = CToolsRecentFileList::GetFile(this: &this->m_RecentFiles, slot: v5);
      if ( File != nullptr )
      {
        if ( this->m_pMapDoc != nullptr )
          this->m_pMapDoc = nullptr;
        CBaseToolSystem::OpenFile(
          this,
          pOpenFileName: File,
          pOpenFileType: "bsp",
          pSaveFileName: nullptr,
          pSaveFileType: "vmf",
          nFlags: 0,
          pContextKeyValues: nullptr);
      }
    }
    else
    {
      v7 = StringAfterPrefix(str: cmd, prefix: "OnTool");
      if ( v7 != nullptr )
      {
        v8 = V_atoi(str: v7);
        enginetools->SwitchToTool(this: enginetools, a2: v8);
      }
      else if ( _V_stricmp(s1: cmd, s2: "OnUndo") != 0 )
      {
        if ( _V_stricmp(s1: cmd, s2: "OnRedo") != 0 )
        {
          if ( _V_stricmp(s1: cmd, s2: "OnDescribeUndo") != 0 )
            vgui::Panel::OnCommand(this, command: cmd);
          else
            CFoundryTool::OnDescribeUndo(this);
        }
        else
        {
          this->OnRedo(this);
        }
      }
      else
      {
        this->OnUndo(this);
      }
    }
  }
  else if ( CBaseToolSystem::GetActionMenu(this) != nullptr )
  {
    ActionMenu = CBaseToolSystem::GetActionMenu(this);
    ActionMenu->SetVisible(this: ActionMenu, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109B50
// Name: TransformEntityVMFToBSPFormat
// Source: json
//------------------------------------------------------------------------------
char __usercall TransformEntityVMFToBSPFormat@<al>(char *pIn@<eax>, CUtlVector<char,CUtlMemory<char,int> > *data@<edi>)
{
  int v3; // eax
  int v4; // esi
  char v5; // bl
  int v7; // eax
  char outStr[2064]; // [esp+4h] [ebp-C14h] BYREF
  char firstToken[1027]; // [esp+814h] [ebp-404h] BYREF
  char src; // [esp+C17h] [ebp-1h] BYREF

  v3 = std::char_traits<char>::length(str: pIn);
  ParseFromMemory(buffer: pIn, size: v3);
  if ( GetToken(crossline: 1) == 0
    || _V_stricmp(s1: token, s2: "entity") != 0
    || GetToken(crossline: 1) == 0
    || _V_stricmp(s1: token, s2: "{") != 0 )
  {
    _Warning(a1: "Unknown entity format.\n");
    return 0;
  }
  else
  {
    v4 = 1;
    while ( 2 )
    {
      v5 = 0;
      while ( 1 )
      {
        GetToken(crossline: 1);
        V_strncpy(pDest: firstToken, pSrc: token, maxLen: 1024);
        if ( firstToken[0] == 125 )
          break;
        if ( GetToken(crossline: 1) == 0 )
          goto LABEL_10;
        if ( token[0] == 123 )
        {
          ++v4;
          if ( _V_stricmp(s1: firstToken, s2: "editor") == 0 )
            v5 = 1;
        }
        else if ( v5 == 0 )
        {
          V_snprintf(pDest: outStr, maxLen: 2064, pFormat: "\"%s\" \"%s\"\n", firstToken, token);
          v7 = std::char_traits<char>::length(str: outStr);
          CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
            this: data,
            elem: data->m_Size,
            num: v7,
            pToInsert: outStr);
        }
      }
      if ( --v4 != 0 )
        continue;
      break;
    }
    if ( v5 != 0 )
    {
LABEL_10:
      _Warning(a1: "Invalid entity format.\n");
      return 0;
    }
    src = 125;
    CUtlVector<char,CUtlMemory<char,int>>::AddToTail(this: data, &src);
    src = 0;
    CUtlVector<char,CUtlMemory<char,int>>::AddToTail(this: data, &src);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109D70
// Name: public: void CUtlDict<struct CToolMenuButton::MenuItem_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CToolMenuButton::MenuItem_t,unsigned short>::RemoveAll(
        CUtlDict<CToolMenuButton::MenuItem_t,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    free(pMem: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10109DC0
// Name: foundry_send_ents_to_engine
// Source: json
//------------------------------------------------------------------------------
void __cdecl foundry_send_ents_to_engine()
{
  int v0; // edi
  CSelection *m_pSelection; // esi
  const CUtlReferenceVector<CMapClass> *List; // ebx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v4; // ecx
  int m_Size; // esi
  CMapClass **m_pMemory; // ecx
  int v7; // eax
  CMapClass **v8; // eax
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > toRespawn; // [esp+4h] [ebp-30h] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+18h] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v11; // [esp+1Ch] [ebp-18h]
  CMapClass *v12; // [esp+20h] [ebp-14h]
  CMapClass *pClass; // [esp+24h] [ebp-10h]
  int v14; // [esp+30h] [ebp-4h]

  v0 = 0;
  if ( g_pFoundryTool != nullptr && CMapDoc::m_pMapDoc != nullptr )
  {
    m_pSelection = CMapDoc::m_pMapDoc->m_pSelection;
    if ( m_pSelection != nullptr && !CSelection::IsEmpty(this: CMapDoc::m_pMapDoc->m_pSelection) )
    {
      memset(&toRespawn, 0, sizeof(toRespawn));
      v14 = 1;
      List = CSelection::GetList(this: m_pSelection);
      if ( List->m_Size > 0 )
      {
        do
        {
          m_pObject = List->m_Memory.m_pMemory[v0 >> (*((int *)&List->m_Memory + 2) >> 27)][v0
                                                                                          & ((32
                                                                                            * *((_DWORD *)&List->m_Memory
                                                                                              + 2)) >> 5)].m_pObject;
          if ( m_pObject != nullptr )
          {
            v12 = List->m_Memory.m_pMemory[v0 >> (*((int *)&List->m_Memory + 2) >> 27)][v0
                                                                                      & ((32
                                                                                        * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
            m_pHead = m_pObject->m_References.m_pHead;
            v4 = m_pObject->m_References.m_pHead;
            if ( v4 != nullptr )
              v4->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
            v11 = nullptr;
            m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
          }
          pClass = v12;
          LOBYTE(v14) = 1;
          if ( v12 != nullptr )
          {
            if ( v11 != nullptr )
            {
              v11->m_pNext = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = v11;
            }
            else if ( (CUtlReference<CMapClass> **)v12->m_References.m_pHead == &m_pHead )
            {
              v12->m_References.m_pHead = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = nullptr;
            }
            v11 = nullptr;
            m_pHead = nullptr;
            v12 = nullptr;
          }
          m_Size = toRespawn.m_Size;
          if ( toRespawn.m_Size + 1 > toRespawn.m_Memory.m_nAllocationCount )
            CUtlMemory<CVisGroup *,int>::Grow(
              this: (CUtlMemory<CCullTreeNode *,int> *)&toRespawn,
              num: toRespawn.m_Size - toRespawn.m_Memory.m_nAllocationCount + 1);
          ++toRespawn.m_Size;
          m_pMemory = toRespawn.m_Memory.m_pMemory;
          v7 = toRespawn.m_Size - m_Size - 1;
          toRespawn.m_pElements = toRespawn.m_Memory.m_pMemory;
          if ( v7 > 0 )
          {
            _V_memmove(
              dest: &toRespawn.m_Memory.m_pMemory[m_Size + 1],
              src: &toRespawn.m_Memory.m_pMemory[m_Size],
              count: 4 * v7);
            m_pMemory = toRespawn.m_Memory.m_pMemory;
          }
          v8 = &m_pMemory[m_Size];
          if ( v8 != nullptr )
            *v8 = pClass;
          ++v0;
        }
        while ( v0 < List->m_Size );
      }
      g_pFoundryTool->RespawnEntitiesWithEdits(
        this: g_pFoundryTool,
        a2: toRespawn.m_Memory.m_pMemory,
        a3: toRespawn.m_Size);
      v14 = -1;
      CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&toRespawn);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109F80
// Name: foundry_remove_selected
// Source: json
//------------------------------------------------------------------------------
void __cdecl foundry_remove_selected()
{
  CSelection *m_pSelection; // esi
  const CUtlReferenceVector<CMapClass> *List; // edi
  int i; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v4; // ecx
  CMapClass *v5; // edx
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v7; // [esp+8h] [ebp-14h]
  CMapClass *v8; // [esp+Ch] [ebp-10h]
  int v9; // [esp+18h] [ebp-4h]

  if ( g_pFoundryTool != nullptr && CMapDoc::m_pMapDoc != nullptr )
  {
    m_pSelection = CMapDoc::m_pMapDoc->m_pSelection;
    if ( m_pSelection != nullptr && !CSelection::IsEmpty(this: CMapDoc::m_pMapDoc->m_pSelection) )
    {
      List = CSelection::GetList(this: m_pSelection);
      for ( i = 0; i < List->m_Size; ++i )
      {
        m_pObject = List->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          v8 = List->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
          m_pHead = m_pObject->m_References.m_pHead;
          v4 = m_pObject->m_References.m_pHead;
          if ( v4 != nullptr )
            v4->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
          v7 = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
        }
        v5 = v8;
        v9 = -1;
        if ( v8 != nullptr )
        {
          if ( v7 != nullptr )
          {
            v7->m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = v7;
          }
          else if ( (CUtlReference<CMapClass> **)v8->m_References.m_pHead == &m_pHead )
          {
            v8->m_References.m_pHead = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = nullptr;
          }
          v7 = nullptr;
          m_pHead = nullptr;
          v8 = nullptr;
        }
        if ( g_pFoundryTool != nullptr && v5 != nullptr )
          servertools->RemoveEntity(this: servertools, a2: v5->m_nID);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A0C0
// Name: public: virtual void CFoundryToolMenuButton::OnShowMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryToolMenuButton::OnShowMenu(CFoundryToolMenuButton *this, vgui::Menu *menu)
{
  CMapDoc *m_pMapDoc; // ebx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // ax
  CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  CToolMenuButton::OnShowMenu(this, menu);
  m_pMapDoc = this->m_pTool->m_pMapDoc;
  search.elem = (CToolMenuButton::MenuItem_t)-65536;
  search.key = "reload";
  v4 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Items.m_Elements.m_Tree,
         &search);
  LOBYTE(m_pMapDoc) = m_pMapDoc != nullptr;
  this->CToolMenuButton::m_pMenu->SetItemEnabled(this: this->CToolMenuButton::m_pMenu, a2: v4, a3: (bool)m_pMapDoc);
  search.elem = (CToolMenuButton::MenuItem_t)-65536;
  search.key = "reloadsave";
  v5 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Items.m_Elements.m_Tree,
         &search);
  this->CToolMenuButton::m_pMenu->SetItemEnabled(this: this->CToolMenuButton::m_pMenu, a2: v5, a3: (bool)m_pMapDoc);
  search.elem = (CToolMenuButton::MenuItem_t)-65536;
  search.key = "reloadsaveslaments";
  v6 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Items.m_Elements.m_Tree,
         &search);
  this->CToolMenuButton::m_pMenu->SetItemEnabled(this: this->CToolMenuButton::m_pMenu, a2: v6, a3: (bool)m_pMapDoc);
}

//------------------------------------------------------------------------------
// Address: 0x1010A190
// Name: LoadFileDataIntoBuffer
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadFileDataIntoBuffer@<al>(
        const char *pFilename@<ecx>,
        const char *pFormat@<eax>,
        CUtlVector<char,CUtlMemory<char,int> > *tempData@<esi>)
{
  _iobuf *v3; // eax
  _iobuf *v4; // ebx
  int v6; // eax
  int v7; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v10; // eax

  v3 = fopen(file: pFilename, mode: pFormat);
  v4 = v3;
  if ( v3 == nullptr )
    return 0;
  fseek(stream: v3, offset: 0, whence: 2);
  v6 = ftell(stream: v4);
  v7 = v6 + 1;
  tempData->m_Size = 0;
  if ( v6 != -1 )
  {
    m_nAllocationCount = tempData->m_Memory.m_nAllocationCount;
    if ( v7 > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: &tempData->m_Memory, num: v7 - m_nAllocationCount);
    tempData->m_Size += v7;
    m_pMemory = tempData->m_Memory.m_pMemory;
    v10 = tempData->m_Size - v7;
    tempData->m_pElements = tempData->m_Memory.m_pMemory;
    if ( v10 > 0 && v7 > 0 )
      _V_memmove(dest: &m_pMemory[v7], src: m_pMemory, count: v10);
  }
  fseek(stream: v4, offset: 0, whence: 0);
  fread(buffer: tempData->m_Memory.m_pMemory, elementSize: 1u, count: tempData->m_Size - 1, stream: v4);
  fclose(stream: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010A230
// Name: private: bool CFoundryTool::GetEntityVMFText(class CMapClass __near *,class CUtlVector<char,class CUtlMemory<char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFoundryTool::GetEntityVMFText(
        CFoundryTool *this,
        CMapClass *pClass,
        CUtlVector<char,CUtlMemory<char,int> > *data)
{
  ChunkFileResult_t v3; // esi
  char baseDir[260]; // [esp+8h] [ebp-570h] BYREF
  CChunkFile chunkFile; // [esp+10Ch] [ebp-46Ch] BYREF
  char cheesyFilename[260]; // [esp+450h] [ebp-128h] BYREF
  CUtlVector<char,CUtlMemory<char,int> > tempData; // [esp+554h] [ebp-24h] BYREF
  CSaveInfo saveInfo; // [esp+56Bh] [ebp-Dh] BYREF
  int v10; // [esp+574h] [ebp-4h]
  char pClass_3; // [esp+583h] [ebp+Bh]

  _getcwd(pnbuf: baseDir, maxlen: 260);
  V_ComposeFileName(path: baseDir, filename: "__foundry_tempchunk.txt", dest: cheesyFilename, destSize: 260);
  saveInfo.m_bVisiblesOnly = false;
  CChunkFile::CChunkFile(this: &chunkFile);
  v10 = 0;
  CChunkFile::Open(this: &chunkFile, pszFileName: cheesyFilename, eMode: ChunkFile_Write);
  v3 = pClass->SaveVMF(this: pClass, a2: &chunkFile, a3: &saveInfo);
  CChunkFile::Close(this: &chunkFile);
  if ( v3 != ChunkFile_Ok )
    goto LABEL_4;
  memset(&tempData, 0, sizeof(tempData));
  LOBYTE(v10) = 2;
  if ( LoadFileDataIntoBuffer(pFilename: cheesyFilename, pFormat: "rt", &tempData) == 0 )
  {
    _Warning(a1: "Internal error in GetEntityVMFText\n");
    LOBYTE(v10) = 0;
    CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&tempData);
LABEL_4:
    v10 = -1;
    CChunkFile::~CChunkFile(this: &chunkFile);
    return 0;
  }
  DeleteFileA(lpFileName: cheesyFilename);
  pClass_3 = TransformEntityVMFToBSPFormat(pIn: tempData.m_Memory.m_pMemory, data);
  LOBYTE(v10) = 0;
  CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&tempData);
  v10 = -1;
  CChunkFile::~CChunkFile(this: &chunkFile);
  return pClass_3;
}

//------------------------------------------------------------------------------
// Address: 0x1010A390
// Name: public: virtual bool CFoundryTool::GetRestoredEntityReplacementData(int,class CUtlVector<char,class CUtlMemory<char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFoundryTool::GetRestoredEntityReplacementData(
        CFoundryTool *this,
        int iHammerID,
        CUtlVector<char,CUtlMemory<char,int> > *data)
{
  CSelection *m_pSelection; // esi
  const CUtlReferenceVector<CMapClass> *List; // eax
  int v5; // esi
  CMapClass *m_pObject; // ecx
  CUtlReference<CMapClass> *v7; // edx
  CMapClass *v8; // edi
  _DWORD *v10; // esi
  int m_nID; // ebx
  int m_iConfigID; // edi
  KeyValues *m_pDialogVariables; // eax
  int v14; // ecx
  int v15; // eax
  int *v16; // eax
  CUtlReference<CMapClass> *m_pHead; // [esp+8h] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v18; // [esp+Ch] [ebp-18h]
  CMapClass *pClass; // [esp+10h] [ebp-14h]
  CFoundryTool *v20; // [esp+14h] [ebp-10h]
  int v21; // [esp+20h] [ebp-4h]

  m_pSelection = g_pFoundryToolImp->m_pMapDoc->m_pSelection;
  v20 = this;
  if ( m_pSelection == nullptr || CSelection::IsEmpty(this: m_pSelection) )
    return 0;
  List = CSelection::GetList(this: m_pSelection);
  v5 = 0;
  if ( List->m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    m_pObject = List->m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      pClass = List->m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v7 = m_pObject->m_References.m_pHead;
      if ( v7 != nullptr )
        v7->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v18 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v8 = pClass;
    v21 = -1;
    if ( pClass != nullptr )
    {
      if ( v18 != nullptr )
      {
        v18->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v18;
      }
      else if ( (CUtlReference<CMapClass> **)pClass->m_References.m_pHead == &m_pHead )
      {
        pClass->m_References.m_pHead = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v18 = nullptr;
      m_pHead = nullptr;
      pClass = nullptr;
    }
    if ( v8->m_nID == iHammerID )
      break;
    if ( ++v5 >= List->m_Size )
      return 0;
  }
  if ( CFoundryTool::GetEntityVMFText(this: (CFoundryTool *)((char *)v20 - 484), pClass: v8, data) == 0 )
    return 0;
  v10 = &v20->CBaseToolSystem::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
  m_nID = v8->m_nID;
  m_iConfigID = v20->m_iConfigID;
  m_pDialogVariables = v20->m_pDialogVariables;
  if ( m_iConfigID + 1 > (int)m_pDialogVariables )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&v20->m_NavGroup._topLevelFocus,
      num: m_iConfigID - (_DWORD)m_pDialogVariables + 1);
  ++v10[94];
  v14 = v10[91];
  v15 = v10[94] - m_iConfigID - 1;
  v10[95] = v14;
  if ( v15 > 0 )
    _V_memmove(dest: (void *)(v14 + 4 * m_iConfigID + 4), src: (const void *)(v14 + 4 * m_iConfigID), count: 4 * v15);
  v16 = (int *)(v10[91] + 4 * m_iConfigID);
  if ( v16 != nullptr )
    *v16 = m_nID;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010A560
// Name: public: virtual void CFoundryTool::OnFinishedRestoreSavegame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::OnFinishedRestoreSavegame(CFoundryTool *this)
{
  int m_nGrowSize; // edi
  CMapDoc *m_pMapDoc; // eax
  CSelection *m_pSelection; // esi
  const CUtlReferenceVector<CMapClass> *List; // edx
  int v5; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v7; // ecx
  CMapClass *v8; // edx
  int m_nID; // esi
  int m_iConfigID; // ecx
  int v11; // eax
  _DWORD *v12; // edx
  int m_Size; // eax
  int v14; // esi
  CMapClass **m_pMemory; // edi
  int v16; // eax
  CMapClass **v17; // eax
  CFoundryTool *v18; // esi
  CMapClass **v19; // eax
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > toRespawn; // [esp+Ch] [ebp-3Ch] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+20h] [ebp-28h] BYREF
  CUtlReference<CMapClass> *v22; // [esp+24h] [ebp-24h]
  CMapClass *v23; // [esp+28h] [ebp-20h]
  CMapClass *pClass; // [esp+2Ch] [ebp-1Ch]
  const CUtlReferenceVector<CMapClass> *pObjectList; // [esp+30h] [ebp-18h]
  CFoundryTool *v26; // [esp+34h] [ebp-14h]
  int i; // [esp+38h] [ebp-10h]
  int v28; // [esp+44h] [ebp-4h]

  m_nGrowSize = 0;
  v26 = this;
  memset(&toRespawn, 0, sizeof(toRespawn));
  v28 = 1;
  m_pMapDoc = g_pFoundryToolImp->m_pMapDoc;
  m_pSelection = m_pMapDoc->m_pSelection;
  if ( m_pSelection != nullptr && !CSelection::IsEmpty(this: m_pMapDoc->m_pSelection) )
  {
    List = CSelection::GetList(this: m_pSelection);
    v5 = 0;
    pObjectList = List;
    i = 0;
    if ( List->m_Size > 0 )
    {
      while ( 1 )
      {
        m_pObject = List->m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          v23 = List->m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
          m_pHead = m_pObject->m_References.m_pHead;
          v7 = m_pObject->m_References.m_pHead;
          if ( v7 != nullptr )
            v7->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
          v22 = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
        }
        v8 = v23;
        pClass = v23;
        LOBYTE(v28) = 1;
        if ( v23 != nullptr )
        {
          if ( v22 != nullptr )
          {
            v22->m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = v22;
          }
          else if ( (CUtlReference<CMapClass> **)v23->m_References.m_pHead == &m_pHead )
          {
            v23->m_References.m_pHead = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = nullptr;
          }
          v22 = nullptr;
          m_pHead = nullptr;
          v23 = nullptr;
        }
        m_nID = v8->m_nID;
        m_iConfigID = v26->m_iConfigID;
        v11 = 0;
        if ( m_iConfigID <= 0 )
          goto LABEL_24;
        v12 = *(_DWORD **)&v26->m_NavGroup._topLevelFocus;
        while ( *v12 != m_nID )
        {
          ++v11;
          ++v12;
          if ( v11 >= m_iConfigID )
            goto LABEL_24;
        }
        if ( v11 == -1 )
        {
LABEL_24:
          m_Size = toRespawn.m_Size;
          v14 = toRespawn.m_Size;
          if ( toRespawn.m_Size + 1 > toRespawn.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CVisGroup *,int>::Grow(
              this: (CUtlMemory<CCullTreeNode *,int> *)&toRespawn,
              num: toRespawn.m_Size - toRespawn.m_Memory.m_nAllocationCount + 1);
            m_Size = toRespawn.m_Size;
          }
          toRespawn.m_Size = m_Size + 1;
          m_pMemory = toRespawn.m_Memory.m_pMemory;
          v16 = m_Size - v14;
          toRespawn.m_pElements = toRespawn.m_Memory.m_pMemory;
          if ( v16 > 0 )
            _V_memmove(
              dest: &toRespawn.m_Memory.m_pMemory[v14 + 1],
              src: &toRespawn.m_Memory.m_pMemory[v14],
              count: 4 * v16);
          v17 = &m_pMemory[v14];
          if ( v17 != nullptr )
            *v17 = pClass;
        }
        List = pObjectList;
        if ( ++i >= pObjectList->m_Size )
          break;
        v5 = i;
      }
      m_nGrowSize = toRespawn.m_Memory.m_nGrowSize;
    }
  }
  (*(void (__thiscall **)(vgui::Panel::PanelMessageFunc_OnCommand *, CMapClass **, int))(*(_DWORD *)&v26->m_OnCommand_register
                                                                                       + 12))(
    a1: &v26->m_OnCommand_register,
    a2: toRespawn.m_Memory.m_pMemory,
    a3: toRespawn.m_Size);
  v18 = v26;
  v26->m_iConfigID = 0;
  if ( (int)v18->m_pszConfigName >= 0 )
  {
    if ( *(_DWORD *)&v18->m_NavGroup._topLevelFocus != 0 )
    {
      free(pMem: *(void **)&v18->m_NavGroup._topLevelFocus);
      *(_DWORD *)&v18->m_NavGroup._topLevelFocus = 0;
    }
    v18->m_pDialogVariables = nullptr;
  }
  v18->CBaseToolSystem::IToolSystem::__vftable = *(IToolSystem_vtbl **)&v18->m_NavGroup._topLevelFocus;
  v28 = 3;
  v19 = toRespawn.m_Memory.m_pMemory;
  toRespawn.m_Size = 0;
  if ( m_nGrowSize >= 0 )
  {
    if ( toRespawn.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: toRespawn.m_Memory.m_pMemory);
      toRespawn.m_Memory.m_pMemory = nullptr;
      v19 = nullptr;
    }
    toRespawn.m_Memory.m_nAllocationCount = 0;
  }
  toRespawn.m_pElements = v19;
  v28 = -1;
  if ( m_nGrowSize >= 0 && v19 != nullptr )
    free(pMem: v19);
}

//------------------------------------------------------------------------------
// Address: 0x1010A7C0
// Name: public: virtual void CFoundryTool::RespawnEntitiesWithEdits(class CMapClass __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::RespawnEntitiesWithEdits(CFoundryTool *this, CMapClass **ppEntities, int nEntities)
{
  int v3; // ecx
  _DWORD *v4; // eax
  int v5; // edi
  CUtlVector<char,CUtlMemory<char,int> > *v6; // esi
  int v7; // esi
  CUtlVector<char,CUtlMemory<char,int> > *v8; // ebx
  CEntityRespawnInfo *m_pMemory; // eax
  CEntityRespawnInfo *v10; // esi
  char **p_m_pElements; // ebx
  int m_nGrowSize; // ebx
  int v13; // [esp-4h] [ebp-3Ch]
  CUtlVector<CEntityRespawnInfo,CUtlMemory<CEntityRespawnInfo,int> > respawnInfos; // [esp+Ch] [ebp-2Ch] BYREF
  void *p; // [esp+20h] [ebp-18h]
  CFoundryTool *v16; // [esp+24h] [ebp-14h]
  CUtlVector<char,CUtlMemory<char,int> > *data; // [esp+28h] [ebp-10h]
  int v18; // [esp+34h] [ebp-4h]

  v16 = this;
  v3 = (20 * (unsigned __int64)(unsigned int)nEntities) >> 32 != 0 ? -1 : 20 * nEntities;
  v4 = operator new[](nSize: __CFADD__(v3, 4) ? -1 : v3 + 4);
  p = v4;
  v5 = 0;
  v18 = 0;
  if ( v4 != nullptr )
  {
    v6 = (CUtlVector<char,CUtlMemory<char,int> > *)(v4 + 1);
    *v4 = nEntities;
    `eh vector constructor iterator'(
      ptr: v4 + 1,
      size: 0x14u,
      count: nEntities,
      pCtor: (void (__thiscall *)(void *))CUtlVector<char,CUtlMemory<char,int>>::`default constructor closure',
      pDtor: (void (__thiscall *)(void *))CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>);
    data = v6;
  }
  else
  {
    data = nullptr;
  }
  memset(&respawnInfos, 0, sizeof(respawnInfos));
  v18 = 2;
  CUtlVector<CEntityRespawnInfo,CUtlMemory<CEntityRespawnInfo,int>>::InsertMultipleBefore(
    this: &respawnInfos,
    elem: 0,
    num: nEntities);
  v7 = 0;
  if ( nEntities > 0 )
  {
    v8 = data;
    v16 = (CFoundryTool *)((char *)v16 - 492);
    do
    {
      if ( CFoundryTool::GetEntityVMFText(this: v16, pClass: ppEntities[v5], data: v8) != 0 )
      {
        m_pMemory = respawnInfos.m_Memory.m_pMemory;
        respawnInfos.m_Memory.m_pMemory[v7].m_nHammerID = ppEntities[v5]->m_nID;
        m_pMemory[v7++].m_pEntText = v8->m_Memory.m_pMemory;
        ++v8;
      }
      ++v5;
    }
    while ( v5 < nEntities );
  }
  v13 = v7;
  v10 = respawnInfos.m_Memory.m_pMemory;
  servertools->RespawnEntitiesWithEdits(this: servertools, a2: respawnInfos.m_Memory.m_pMemory, a3: v13);
  if ( data != nullptr )
  {
    p_m_pElements = &data[-1].m_pElements;
    `eh vector destructor iterator'(
      ptr: data,
      size: 0x14u,
      count: (int)data[-1].m_pElements,
      pDtor: (void (__thiscall *)(void *))CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>);
    operator delete(p: p_m_pElements);
  }
  v18 = 4;
  m_nGrowSize = respawnInfos.m_Memory.m_nGrowSize;
  respawnInfos.m_Size = 0;
  if ( respawnInfos.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10 != nullptr )
    {
      free(pMem: v10);
      respawnInfos.m_Memory.m_pMemory = nullptr;
      v10 = nullptr;
    }
    respawnInfos.m_Memory.m_nAllocationCount = 0;
  }
  respawnInfos.m_pElements = v10;
  v18 = -1;
  if ( m_nGrowSize >= 0 && v10 != nullptr )
    free(pMem: v10);
}

//------------------------------------------------------------------------------
// Address: 0x1010A950
// Name: public: CUtlMap<char const __near *,struct CToolMenuButton::MenuItem_t,unsigned short>::~CUtlMap<char const __near *,struct CToolMenuButton::MenuItem_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::~CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>(
        CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short> *this)
{
  CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1010AA70
// Name: public: CUtlDict<struct CToolMenuButton::MenuItem_t,unsigned short>::~CUtlDict<struct CToolMenuButton::MenuItem_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CToolMenuButton::MenuItem_t,unsigned short>::~CUtlDict<CToolMenuButton::MenuItem_t,unsigned short>(
        CUtlDict<CToolMenuButton::MenuItem_t,unsigned short> *this)
{
  CUtlDict<CToolMenuButton::MenuItem_t,unsigned short>::RemoveAll(this);
  CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1010AAC0
// Name: public: virtual CToolMenuButton::~CToolMenuButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuButton::~CToolMenuButton(CToolMenuButton *this)
{
  CUtlDict<CToolMenuButton::MenuItem_t,unsigned short> *p_m_Items; // edi

  p_m_Items = &this->m_Items;
  CUtlDict<CToolMenuButton::MenuItem_t,unsigned short>::RemoveAll(this: &this->m_Items);
  CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &p_m_Items->m_Elements.m_Tree);
  vgui::MenuButton::~MenuButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010AB30
// Name: public: CFoundryToolMenuButton::CFoundryToolMenuButton(class CFoundryTool __near *,char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFoundryToolMenuButton *__thiscall CFoundryToolMenuButton::CFoundryToolMenuButton(
        CFoundryToolMenuButton *this,
        CFoundryTool *parent,
        const char *panelName,
        const char *text,
        vgui::Panel *pActionSignalTarget)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax

  CToolMenuButton::CToolMenuButton(this, parent, panelName, text, actionTarget: pActionSignalTarget);
  this->__vftable = (CFoundryToolMenuButton_vtbl *)&CFoundryToolMenuButton::`vftable';
  if ( `CFoundryToolMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `CFoundryToolMenuButton::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CFoundryToolMenuButton");
    v6->pfnClassName = CFoundryToolMenuButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "CToolMenuButton");
  }
  if ( `CFoundryToolMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFoundryToolMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CFoundryToolMenuButton");
    v7->pfnClassName = CFoundryToolMenuButton::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "CToolMenuButton");
  }
  if ( `CFoundryToolMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFoundryToolMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CFoundryToolMenuButton");
    v8->pfnClassName = CFoundryToolMenuButton::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CToolMenuButton");
  }
  this->m_pTool = parent;
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "UpdateHammerEntity");
  else
    v10 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "updateentity",
    itemText: "#FoundryUpdateHammerEntity",
    message: v10,
    target: pActionSignalTarget,
    userData: nullptr,
    kbcommandname: nullptr);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "ReloadMap");
  else
    v12 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "reload",
    itemText: "#FoundryReload",
    message: v12,
    target: pActionSignalTarget,
    userData: nullptr,
    kbcommandname: nullptr);
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "ReloadFromSave");
  else
    v14 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "reloadsave",
    itemText: "#FoundryReloadFromSave",
    message: v14,
    target: pActionSignalTarget,
    userData: nullptr,
    kbcommandname: nullptr);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "ReloadFromSaveSlamEnts");
  else
    v16 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "reloadsaveslaments",
    itemText: "#FoundryReloadReplaceEnts",
    message: v16,
    target: pActionSignalTarget,
    userData: nullptr,
    kbcommandname: nullptr);
  vgui::MenuButton::SetMenu(this, menu: this->CToolMenuButton::m_pMenu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010AD60
// Name: public: virtual void vgui::Button::OnHotkey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Button::OnHotkey(vgui::Button *this)
{
  this->DoClick(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010AD70
// Name: public: virtual struct vgui::PanelMessageMap __near * CFoundryToolMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFoundryToolMenuButton::GetMessageMap(CFoundryToolMenuButton *this)
{
  if ( (`CFoundryToolMenuButton::GetMessageMap'::`2'::`local static guard' & 1) == 0 )
  {
    `CFoundryToolMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
    `CFoundryToolMenuButton::GetMessageMap'::`2'::s_pMap = vgui::FindOrAddPanelMessageMap(className: "CFoundryToolMenuButton");
  }
  return `CFoundryToolMenuButton::GetMessageMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010ADD0
// Name: public: virtual struct PanelAnimationMap __near * CFoundryToolMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFoundryToolMenuButton::GetAnimMap(CFoundryToolMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CFoundryToolMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x1010ADE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFoundryToolMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFoundryToolMenuButton::GetKBMap(CFoundryToolMenuButton *this)
{
  if ( (`CFoundryToolMenuButton::GetKBMap'::`2'::`local static guard' & 1) == 0 )
  {
    `CFoundryToolMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
    `CFoundryToolMenuButton::GetKBMap'::`2'::s_pMap = vgui::FindOrAddPanelKeyBindingMap(className: "CFoundryToolMenuButton");
  }
  return `CFoundryToolMenuButton::GetKBMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010AED0
// Name: public: CToolsRecentFileList::~CToolsRecentFileList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolsRecentFileList::~CToolsRecentFileList(CToolsRecentFileList *this)
{
  CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::~CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>(this: &this->m_RecentFiles);
}

//------------------------------------------------------------------------------
// Address: 0x1010AF10
// Name: public: CFoundryViewMenuButton::CFoundryViewMenuButton(class CFoundryTool __near *,char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFoundryViewMenuButton *__thiscall CFoundryViewMenuButton::CFoundryViewMenuButton(
        CFoundryViewMenuButton *this,
        CFoundryTool *parent,
        const char *panelName,
        const char *text,
        vgui::Panel *pActionSignalTarget)
{
  vgui::Panel *v5; // edi
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  int v14; // eax
  int m_nValue; // ecx
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  int v18; // eax
  int v19; // ecx
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  int v22; // eax
  vgui::Menu *m_pMenu; // ecx
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  int v26; // eax
  bool v27; // zf
  KeyValues *v28; // eax
  KeyValues *v29; // eax

  v5 = pActionSignalTarget;
  CToolMenuButton::CToolMenuButton(this, parent, panelName, text, actionTarget: pActionSignalTarget);
  this->__vftable = (CFoundryViewMenuButton_vtbl *)&CFoundryViewMenuButton::`vftable';
  if ( `CFoundryViewMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `CFoundryViewMenuButton::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CFoundryViewMenuButton");
    v7->pfnClassName = CFoundryViewMenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "CToolMenuButton");
    v5 = pActionSignalTarget;
  }
  if ( `CFoundryViewMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFoundryViewMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CFoundryViewMenuButton");
    v8->pfnClassName = CFoundryViewMenuButton::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "CToolMenuButton");
    v5 = pActionSignalTarget;
  }
  if ( `CFoundryViewMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFoundryViewMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CFoundryViewMenuButton");
    v9->pfnClassName = CFoundryViewMenuButton::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CToolMenuButton");
    v5 = pActionSignalTarget;
  }
  this->m_pTool = parent;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "OnDefaultLayout");
  else
    v11 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "defaultlayout",
    itemText: "#FoundryViewDefault",
    message: v11,
    target: v5,
    userData: nullptr,
    kbcommandname: nullptr);
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v13 = KeyValues::KeyValues(this: v12, setName: "OnDrawHammerEntities");
  else
    v13 = nullptr;
  v14 = CToolMenuButton::AddCheckableMenuItem(
          this,
          itemName: "drawhammerentities",
          itemText: "#FoundryViewDrawHammerEntities",
          message: v13,
          target: v5,
          userData: nullptr,
          kbcommandname: nullptr);
  this->m_menuitemidDrawHammerEntities = v14;
  if ( foundry_draw_hammer_entities.m_pParent != nullptr )
    m_nValue = foundry_draw_hammer_entities.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  vgui::Menu::SetMenuItemChecked(this: this->CToolMenuButton::m_pMenu, itemID: v14, state: m_nValue != 0);
  v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v16 != nullptr )
    v17 = KeyValues::KeyValues(this: v16, setName: "OnDrawHammerModels");
  else
    v17 = nullptr;
  v18 = CToolMenuButton::AddCheckableMenuItem(
          this,
          itemName: "drawhammermodels",
          itemText: "#FoundryViewDrawHammerModels",
          message: v17,
          target: v5,
          userData: nullptr,
          kbcommandname: nullptr);
  this->m_menuitemidDrawHammerModels = v18;
  if ( foundry_draw_hammer_models.m_pParent != nullptr )
    v19 = foundry_draw_hammer_models.m_pParent->m_Value.m_nValue;
  else
    v19 = 0;
  vgui::Menu::SetMenuItemChecked(this: this->CToolMenuButton::m_pMenu, itemID: v18, state: v19 != 0);
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "OnDrawEntityHighlights");
  else
    v21 = nullptr;
  v22 = CToolMenuButton::AddCheckableMenuItem(
          this,
          itemName: "DrawEntityHighlights",
          itemText: "#FoundryViewDrawEntityHighlights",
          message: v21,
          target: v5,
          userData: nullptr,
          kbcommandname: nullptr);
  m_pMenu = this->CToolMenuButton::m_pMenu;
  this->m_menuitemidDrawEntityHighlights = v22;
  vgui::Menu::SetMenuItemChecked(this: m_pMenu, itemID: v22, state: true);
  v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v24 != nullptr )
    v25 = KeyValues::KeyValues(this: v24, setName: "OnDrawGameEntities");
  else
    v25 = nullptr;
  v26 = CToolMenuButton::AddCheckableMenuItem(
          this,
          itemName: "drawgameentities",
          itemText: "#FoundryViewDrawGameEntities",
          message: v25,
          target: v5,
          userData: nullptr,
          kbcommandname: nullptr);
  v27 = (_S1_19 & 1) == 0;
  this->m_menuitemidDrawGameEntities = v26;
  if ( v27 )
  {
    _S1_19 |= 1u;
    ConVarRef::ConVarRef(this: &stru_107B166C, pName: "r_drawentities");
  }
  vgui::Menu::SetMenuItemChecked(
    this: this->CToolMenuButton::m_pMenu,
    itemID: this->m_menuitemidDrawGameEntities,
    state: stru_107B166C.m_pConVarState->m_Value.m_nValue != 0);
  v28 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v28 != nullptr )
    v29 = KeyValues::KeyValues(this: v28, setName: "OnSyncHammerView");
  else
    v29 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "synchammerview",
    itemText: "#FoundrySyncHammerView",
    message: v29,
    target: v5,
    userData: nullptr,
    kbcommandname: nullptr);
  vgui::MenuButton::SetMenu(this, menu: this->CToolMenuButton::m_pMenu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010B250
// Name: public: virtual struct vgui::PanelMessageMap __near * CFoundryViewMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFoundryViewMenuButton::GetMessageMap(CFoundryViewMenuButton *this)
{
  if ( (`CFoundryViewMenuButton::GetMessageMap'::`2'::`local static guard' & 1) == 0 )
  {
    `CFoundryViewMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
    `CFoundryViewMenuButton::GetMessageMap'::`2'::s_pMap = vgui::FindOrAddPanelMessageMap(className: "CFoundryViewMenuButton");
  }
  return `CFoundryViewMenuButton::GetMessageMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010B2B0
// Name: public: virtual struct PanelAnimationMap __near * CFoundryViewMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFoundryViewMenuButton::GetAnimMap(CFoundryViewMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CFoundryViewMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x1010B2C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFoundryViewMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFoundryViewMenuButton::GetKBMap(CFoundryViewMenuButton *this)
{
  if ( (`CFoundryViewMenuButton::GetKBMap'::`2'::`local static guard' & 1) == 0 )
  {
    `CFoundryViewMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
    `CFoundryViewMenuButton::GetKBMap'::`2'::s_pMap = vgui::FindOrAddPanelKeyBindingMap(className: "CFoundryViewMenuButton");
  }
  return `CFoundryViewMenuButton::GetKBMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010B3A0
// Name: public: virtual class vgui::MenuBar __near * CFoundryTool::CreateMenuBar(class CBaseToolSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CToolFileMenuBar *__thiscall CFoundryTool::CreateMenuBar(CFoundryTool *this, CBaseToolSystem *pParent)
{
  CToolMenuButton *v3; // eax
  CToolFileMenuBar *v4; // eax
  void (__thiscall *ComputeMenuBarTitle)(CBaseToolSystem *, char *, unsigned int); // edx
  const char *v6; // eax
  vgui::Panel *ActionTarget; // eax
  CToolMenuButton *ToolFileMenuButton; // ebx
  vgui::Panel *v9; // eax
  CFoundryToolMenuButton *v10; // edi
  vgui::Panel *v11; // eax
  CFoundryViewMenuButton *v12; // edi
  vgui::Panel *v13; // eax
  CFoundryViewMenuButton *v14; // eax
  vgui::Panel *v15; // eax
  CToolMenuButton *ToolSwitchMenuButton; // edi
  char title[64]; // [esp+Ch] [ebp-54h] BYREF
  void *p; // [esp+4Ch] [ebp-14h]
  CToolMenuButton *pEditButton; // [esp+50h] [ebp-10h]
  int v21; // [esp+5Ch] [ebp-4h]
  CFoundryToolMenuButton *pParenta; // [esp+68h] [ebp+8h]

  v3 = (CToolMenuButton *)operator new(nSize: 0x184u);
  pEditButton = v3;
  v21 = 0;
  if ( v3 != nullptr )
    v4 = CToolFileMenuBar::CToolFileMenuBar(this: (CToolFileMenuBar *)v3, parent: pParent, panelName: "Main Menu Bar");
  else
    v4 = nullptr;
  v21 = -1;
  ComputeMenuBarTitle = this->ComputeMenuBarTitle;
  this->m_pMenuBar = v4;
  ComputeMenuBarTitle(this, a2: title, a3: 64u);
  CToolMenuBar::SetInfo(this: this->m_pMenuBar, pInfo: title);
  v6 = (const char *)this->GetToolName(this: &this->IToolSystem);
  CToolMenuBar::SetToolName(this: this->m_pMenuBar, pName: v6);
  ActionTarget = CBaseToolSystem::GetActionTarget(this);
  ToolFileMenuButton = CreateToolFileMenuButton(
                         parent: this->m_pMenuBar,
                         panelName: "File",
                         text: "&File",
                         pActionTarget: ActionTarget,
                         pCallbacks: &this->IFileMenuCallbacks);
  v9 = CBaseToolSystem::GetActionTarget(this);
  pEditButton = CreateToolEditMenuButton(parent: this, panelName: "Edit", text: "&Edit", pActionTarget: v9);
  v10 = (CFoundryToolMenuButton *)operator new(nSize: 0x244u);
  p = v10;
  v21 = 1;
  if ( v10 != nullptr )
  {
    v11 = CBaseToolSystem::GetActionTarget(this);
    pParenta = CFoundryToolMenuButton::CFoundryToolMenuButton(
                 this: v10,
                 parent: this,
                 panelName: "Foundry",
                 text: "F&oundry",
                 pActionSignalTarget: v11);
  }
  else
  {
    pParenta = nullptr;
  }
  v21 = -1;
  v12 = (CFoundryViewMenuButton *)operator new(nSize: 0x254u);
  p = v12;
  v21 = 2;
  if ( v12 != nullptr )
  {
    v13 = CBaseToolSystem::GetActionTarget(this);
    v14 = CFoundryViewMenuButton::CFoundryViewMenuButton(
            this: v12,
            parent: this,
            panelName: "View",
            text: "&View",
            pActionSignalTarget: v13);
  }
  else
  {
    v14 = nullptr;
  }
  v21 = -1;
  this->m_pViewMenuButton = v14;
  v15 = CBaseToolSystem::GetActionTarget(this);
  ToolSwitchMenuButton = CreateToolSwitchMenuButton(
                           parent: this->m_pMenuBar,
                           panelName: "Switcher",
                           text: "&Tools",
                           pActionTarget: v15);
  this->m_pMenuBar->AddButton(this: this->m_pMenuBar, a2: ToolFileMenuButton);
  this->m_pMenuBar->AddButton(this: this->m_pMenuBar, a2: pEditButton);
  this->m_pMenuBar->AddButton(this: this->m_pMenuBar, a2: pParenta);
  this->m_pMenuBar->AddButton(this: this->m_pMenuBar, a2: this->m_pViewMenuButton);
  this->m_pMenuBar->AddButton(this: this->m_pMenuBar, a2: ToolSwitchMenuButton);
  return this->m_pMenuBar;
}

//------------------------------------------------------------------------------
// Address: 0x1010B5B0
// Name: public: virtual CBaseToolSystem::~CBaseToolSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::~CBaseToolSystem(CBaseToolSystem *this)
{
  CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *p_m_Tools; // esi

  p_m_Tools = &this->m_Tools;
  this->m_Tools.m_Size = 0;
  if ( this->m_Tools.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Tools->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Tools->m_Memory.m_pMemory);
      p_m_Tools->m_Memory.m_pMemory = nullptr;
    }
    p_m_Tools->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Tools->m_pElements = p_m_Tools->m_Memory.m_pMemory;
  if ( p_m_Tools->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Tools->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Tools->m_Memory.m_pMemory);
      p_m_Tools->m_Memory.m_pMemory = nullptr;
    }
    p_m_Tools->m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::~CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>(this: &this->m_RecentFiles.m_RecentFiles);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010B660
// Name: public: CFoundryTool::CFoundryTool(void)
// Source: json
//------------------------------------------------------------------------------
CFoundryTool *__thiscall CFoundryTool::CFoundryTool(CFoundryTool *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi
  DmElementHandle_t *m_pMemory; // ecx
  int *v6; // ecx
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  CBaseToolSystem::CBaseToolSystem(this, pToolName: "#ToolGeneral");
  this->IServerFoundry::IBaseInterface::__vftable = (IServerFoundry_vtbl *)&IBaseInterface::`vftable';
  this->IServerFoundry::IBaseInterface::__vftable = (IServerFoundry_vtbl *)&IServerFoundry::`vftable';
  this->IFileMenuCallbacks::__vftable = (IFileMenuCallbacks_vtbl *)&IFileMenuCallbacks::`vftable';
  this->IFoundryTool::__vftable = (IFoundryTool_vtbl *)&IFoundryTool::`vftable';
  this->CBaseToolSystem::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CFoundryTool_vtbl *)&CFoundryTool::`vftable'{for `vgui::EditablePanel'};
  this->CBaseToolSystem::IToolSystem::__vftable = (IToolSystem_vtbl *)&CFoundryTool::`vftable'{for `IToolSystem'};
  this->CBaseToolSystem::vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CFoundryTool::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  this->IServerFoundry::IBaseInterface::__vftable = (IServerFoundry_vtbl *)&CFoundryTool::`vftable'{for `IServerFoundry'};
  this->IFileMenuCallbacks::__vftable = (IFileMenuCallbacks_vtbl *)&CFoundryTool::`vftable'{for `IFileMenuCallbacks'};
  this->IFoundryTool::__vftable = (IFoundryTool_vtbl *)&CFoundryTool::`vftable'{for `IFoundryTool'};
  if ( `CFoundryTool::ChainToMap'::`2'::chained == 0 )
  {
    `CFoundryTool::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
    v2->pfnClassName = CFoundryTool::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseToolSystem");
  }
  if ( `CFoundryTool::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFoundryTool::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CFoundryTool");
    v3->pfnClassName = CFoundryTool::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "CBaseToolSystem");
  }
  if ( `CFoundryTool::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFoundryTool::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CFoundryTool");
    v4->pfnClassName = CFoundryTool::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseToolSystem");
  }
  CFoundryTool::PanelMessageFunc_OnNew::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnOpen::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnSave::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnSaveAs::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnClose::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnCloseNoSave::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnMarkNotDirty::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnExit::InitVar(a1: (int)&savedregs);
  if ( `CFoundryTool::PanelKBMapFunc_undo::InitVar'::`2'::bAdded == 0 )
  {
    `CFoundryTool::PanelKBMapFunc_undo::InitVar'::`2'::bAdded = 1;
    CFoundryTool::KB_AddToMap(
      a1: (int)&savedregs,
      bindingname: "undo",
      defaultcode: KEY_Z,
      default_modifiers: 2,
      function: (unsigned int) __thiscall CElementPropertiesTreeInternal::`vcall'{1064,{flat}},
      helpstring: (unsigned int)"#undo_help",
      passive: false);
  }
  if ( `CFoundryTool::PanelKBMapFunc_redo::InitVar'::`2'::bAdded == 0 )
  {
    `CFoundryTool::PanelKBMapFunc_redo::InitVar'::`2'::bAdded = 1;
    CFoundryTool::KB_AddToMap(
      a1: (int)&savedregs,
      bindingname: "redo",
      defaultcode: KEY_Z,
      default_modifiers: 3,
      function: (unsigned int) __thiscall CElementPropertiesTreeInternal::`vcall'{1068,{flat}},
      helpstring: (unsigned int)"#redo_help",
      passive: false);
  }
  CFoundryTool::PanelMessageFunc_OnUpdateHammerEntity::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnReload::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnReloadFromSave::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnReloadFromSaveSlamEnts::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnDefaultLayout::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnDrawHammerEntities::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnDrawHammerModels::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnDrawEntityHighlights::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnDrawGameEntities::InitVar(a1: (int)&savedregs);
  CFoundryTool::PanelMessageFunc_OnSyncHammerView::InitVar(a1: (int)&savedregs);
  this->m_ToolWindowFactory.__vftable = (CToolWindowFactory<vgui::ToolWindow>_vtbl *)&CToolWindowFactory<vgui::ToolWindow>::`vftable';
  this->m_toolElements.m_Memory.m_pMemory = nullptr;
  this->m_toolElements.m_Memory.m_nAllocationCount = 0;
  this->m_toolElements.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_toolElements.m_Memory.m_pMemory;
  this->m_toolElements.m_Size = 0;
  this->m_toolElements.m_pElements = m_pMemory;
  this->m_SavegameRestoredEnts.m_Memory.m_pMemory = nullptr;
  this->m_SavegameRestoredEnts.m_Memory.m_nAllocationCount = 0;
  this->m_SavegameRestoredEnts.m_Memory.m_nGrowSize = 0;
  v6 = this->m_SavegameRestoredEnts.m_Memory.m_pMemory;
  this->m_SavegameRestoredEnts.m_Size = 0;
  this->m_SavegameRestoredEnts.m_pElements = v6;
  this->m_pBSPFileName[0] = 0;
  this->m_pMenuBar = nullptr;
  this->m_pMapDoc = nullptr;
  this->m_pHammer = nullptr;
  this->m_v3dViewOrigin.x = 0.0;
  this->m_v3dViewOrigin.y = 0.0;
  this->m_v3dViewOrigin.z = 0.0;
  this->m_v3dViewAngles.x = 0.0;
  this->m_v3dViewAngles.y = 0.0;
  this->m_v3dViewAngles.z = 0.0;
  this->m_fl3dViewFOV = 90.0;
  this->m_pViewMenuButton = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010B950
// Name: public: virtual unsigned int CBaseToolSystem::GetClientWorkspaceArea(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseToolSystem::GetClientWorkspaceArea(CBaseToolSystem *this)
{
  CBaseToolSystem *v1; // esi
  vgui::Panel *ClientArea; // eax

  v1 = (CBaseToolSystem *)((char *)this - 380);
  if ( CBaseToolSystem::GetClientArea(this: (CBaseToolSystem *)((char *)this - 380)) == nullptr )
    return 0;
  ClientArea = CBaseToolSystem::GetClientArea(this: v1);
  return ClientArea->GetVPanel(this: ClientArea);
}

//------------------------------------------------------------------------------
// Address: 0x1010B980
// Name: public: virtual char const __near * CFoundryTool::GetToolName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFoundryTool::GetToolName(CFoundryTool *this)
{
  return "Foundry";
}

//------------------------------------------------------------------------------
// Address: 0x1010B990
// Name: public: virtual char const __near * CFoundryTool::GetBindingsContextFile(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFoundryTool::GetBindingsContextFile(CFoundryTool *this)
{
  return "cfg/Foundry.kb";
}

//------------------------------------------------------------------------------
// Address: 0x1010B9A0
// Name: public: virtual class vgui::Panel __near * CFoundryTool::GetRootPanel(void)
// Source: json
//------------------------------------------------------------------------------
CFoundryTool *__thiscall CFoundryTool::GetRootPanel(CFoundryTool *this)
{
  return (CFoundryTool *)((char *)this - 488);
}

//------------------------------------------------------------------------------
// Address: 0x1010B9E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CFoundryTool::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFoundryTool::GetMessageMap(CFoundryTool *this)
{
  if ( (`CFoundryTool::GetMessageMap'::`2'::`local static guard' & 1) == 0 )
  {
    `CFoundryTool::GetMessageMap'::`2'::`local static guard' |= 1u;
    `CFoundryTool::GetMessageMap'::`2'::s_pMap = vgui::FindOrAddPanelMessageMap(className: "CFoundryTool");
  }
  return `CFoundryTool::GetMessageMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010BA40
// Name: public: virtual struct PanelAnimationMap __near * CFoundryTool::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFoundryTool::GetAnimMap(CFoundryTool *this)
{
  return FindOrAddPanelAnimationMap(className: "CFoundryTool");
}

//------------------------------------------------------------------------------
// Address: 0x1010BA50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFoundryTool::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFoundryTool::GetKBMap(CFoundryTool *this)
{
  if ( (`CFoundryTool::GetKBMap'::`2'::`local static guard' & 1) == 0 )
  {
    `CFoundryTool::GetKBMap'::`2'::`local static guard' |= 1u;
    `CFoundryTool::GetKBMap'::`2'::s_pMap = vgui::FindOrAddPanelKeyBindingMap(className: "CFoundryTool");
  }
  return `CFoundryTool::GetKBMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010BAB0
// Name: public: virtual CFoundryTool::~CFoundryTool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::~CFoundryTool(CFoundryTool *this)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_SavegameRestoredEnts; // esi
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *p_m_toolElements; // esi

  p_m_SavegameRestoredEnts = &this->m_SavegameRestoredEnts;
  this->m_SavegameRestoredEnts.m_Size = 0;
  if ( this->m_SavegameRestoredEnts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SavegameRestoredEnts->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_SavegameRestoredEnts->m_Memory.m_pMemory);
      p_m_SavegameRestoredEnts->m_Memory.m_pMemory = nullptr;
    }
    p_m_SavegameRestoredEnts->m_Memory.m_nAllocationCount = 0;
  }
  p_m_SavegameRestoredEnts->m_pElements = p_m_SavegameRestoredEnts->m_Memory.m_pMemory;
  if ( p_m_SavegameRestoredEnts->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SavegameRestoredEnts->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_SavegameRestoredEnts->m_Memory.m_pMemory);
      p_m_SavegameRestoredEnts->m_Memory.m_pMemory = nullptr;
    }
    p_m_SavegameRestoredEnts->m_Memory.m_nAllocationCount = 0;
  }
  p_m_toolElements = &this->m_toolElements;
  this->m_toolElements.m_Size = 0;
  if ( this->m_toolElements.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_toolElements->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_toolElements->m_Memory.m_pMemory);
      p_m_toolElements->m_Memory.m_pMemory = nullptr;
    }
    this->m_toolElements.m_Memory.m_nAllocationCount = 0;
  }
  this->m_toolElements.m_pElements = this->m_toolElements.m_Memory.m_pMemory;
  if ( this->m_toolElements.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_toolElements->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_toolElements->m_Memory.m_pMemory);
      p_m_toolElements->m_Memory.m_pMemory = nullptr;
    }
    this->m_toolElements.m_Memory.m_nAllocationCount = 0;
  }
  this->IServerFoundry::IBaseInterface::__vftable = (IServerFoundry_vtbl *)&IBaseInterface::`vftable';
  CBaseToolSystem::~CBaseToolSystem(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010BBE0
// Name: void CreateTools(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateTools()
{
  CFoundryTool *v0; // eax
  CFoundryTool *v1; // eax

  v0 = (CFoundryTool *)operator new(nSize: 0x364u);
  if ( v0 != nullptr )
    v1 = CFoundryTool::CFoundryTool(this: v0);
  else
    v1 = nullptr;
  g_pFoundryToolImp = v1;
  if ( v1 != nullptr )
    g_pFoundryTool = &v1->IFoundryTool;
  else
    g_pFoundryTool = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A9A20
// Name: public: int CUtlDict<struct EventGroup,int>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Find(CUtlDict<EventGroup,int> *this, const char *pName)
{
  int v2; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t search; // [esp+0h] [ebp-20h] BYREF

  if ( pName == nullptr )
    return -1;
  search.elem.timeSortedEvents.m_Root = -1;
  memset(&search.elem.timeSortedEvents.m_Elements, 0, sizeof(search.elem.timeSortedEvents.m_Elements));
  search.elem.timeSortedEvents.m_pElements = nullptr;
  search.elem.timeSortedEvents.m_NumElements = 0;
  search.elem.timeSortedEvents.m_LessFunc = ChoreEventStartTimeLessFunc;
  search.elem.timeSortedEvents.m_FirstFree = -1;
  search.elem.timeSortedEvents.m_LastAlloc.index = -1;
  search.key = pName;
  v2 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &search.elem.timeSortedEvents);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101A9BD0
// Name: public: void CUtlDict<struct EventGroup,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<EventGroup,int>::RemoveAll(CUtlDict<EventGroup,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101A9C20
// Name: public: int CUtlDict<struct EventGroup,int>::Insert(char const __near *,struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Insert(
        CUtlDict<EventGroup,int> *this,
        const char *pName,
        const EventGroup *element)
{
  char *v3; // eax
  int v4; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t insert; // [esp+Ch] [ebp-24h] BYREF
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *p_m_Tree; // [esp+2Ch] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v3, pName);
  else
    v3 = nullptr;
  insert.key = v3;
  insert.elem.timeSortedEvents.m_LessFunc = ChoreEventStartTimeLessFunc;
  memset(&insert.elem.timeSortedEvents.m_Elements, 0, sizeof(insert.elem.timeSortedEvents.m_Elements));
  *(_DWORD *)&insert.elem.timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&insert.elem.timeSortedEvents.m_FirstFree = -1;
  insert.elem.timeSortedEvents.m_pElements = nullptr;
  EventGroup::operator=(this: &insert.elem, src: element);
  v4 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Insert(
         this: p_m_Tree,
         &insert);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &insert.elem.timeSortedEvents);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101B1980
// Name: public: void CUtlDict<class CDmElementFactoryHelper __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDmElementFactoryHelper *,int>::RemoveAll(CUtlDict<CDmElementFactoryHelper *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101B25F0
// Name: public: int CUtlMap<char const __near *,class CDmElementFactoryHelper __near *,int>::Insert(char const __near * const __near &,class CDmElementFactoryHelper __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CDmElementFactoryHelper *,int>::Insert(
        CUtlMap<char const *,CDmElementFactoryHelper *,int> *this,
        const char **key,
        int insert)
{
  CDmElementFactoryHelper *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CDmElementFactoryHelper **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int,CUtlMap<char const *,enum DmElementHandle_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101B33C0
// Name: public: int CUtlDict<class CDmElementFactoryHelper __near *,int>::Insert(char const __near *,class CDmElementFactoryHelper __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDmElementFactoryHelper *,int>::Insert(
        CUtlDict<CDmElementFactoryHelper *,int> *this,
        char *pName,
        CDmElementFactoryHelper *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CDmElementFactoryHelper *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x101F2920
// Name: public: void CUtlDict<class MDkeyvalue,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<MDkeyvalue,unsigned short>::RemoveAll(CUtlDict<MDkeyvalue,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101F2AD0
// Name: public: unsigned short CUtlMap<char const __near *,class MDkeyvalue,unsigned short>::Insert(char const __near * const __near &,class MDkeyvalue const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<char const *,MDkeyvalue,unsigned short>::Insert(
        CUtlMap<char const *,MDkeyvalue,unsigned short> *this,
        const char **key,
        const MDkeyvalue *insert)
{
  const char *v3; // edx
  char *szValue; // eax
  char v5; // dl
  CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t node; // [esp+8h] [ebp-254h] BYREF

  v3 = *key;
  node.elem.szKey[0] = 0;
  node.elem.szValue[0] = 0;
  node.key = v3;
  strcpy(node.elem.szKey, insert->szKey);
  szValue = insert->szValue;
  do
  {
    v5 = *szValue;
    szValue[node.elem.szValue - insert->szValue] = *szValue;
    ++szValue;
  }
  while ( v5 != 0 );
  return CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Tree,
           insert: &node);
}

//------------------------------------------------------------------------------
// Address: 0x101F2B40
// Name: public: unsigned short CUtlDict<class MDkeyvalue,unsigned short>::Insert(char const __near *,class MDkeyvalue const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<MDkeyvalue,unsigned short>::Insert(
        CUtlDict<MDkeyvalue,unsigned short> *this,
        char *pName,
        const MDkeyvalue *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,MDkeyvalue,unsigned short>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x102BBF30
// Name: private: virtual void CFoundryTool::DestroyToolContainers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::DestroyToolContainers(CBaseToolSystem *this)
{
  int i; // esi
  vgui::ToolWindow *ToolWindow; // eax

  for ( i = vgui::ToolWindow::GetToolWindowCount() - 1; i >= 0; --i )
  {
    ToolWindow = vgui::ToolWindow::GetToolWindow(index: i);
    if ( ToolWindow != nullptr )
      ((void (__thiscall *)(vgui::ToolWindow *, int))ToolWindow->dtr_Panel)(a1: ToolWindow, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BEAA0
// Name: public: unsigned short CUtlDict<struct CToolMenuButton::MenuItem_t,unsigned short>::Insert(char const __near *,struct CToolMenuButton::MenuItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CToolMenuButton::MenuItem_t,unsigned short>::Insert(
        CUtlDict<CToolMenuButton::MenuItem_t,unsigned short> *this,
        const char *pName,
        const CToolMenuButton::MenuItem_t *element)
{
  char *v4; // eax
  unsigned __int16 m_Id; // dx
  CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  insert.key = v4;
  m_Id = element->m_KeyBinding.m_Id;
  insert.elem.m_ItemID = element->m_ItemID;
  insert.elem.m_KeyBinding.m_Id = m_Id;
  return CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x102C3AE0
// Name: public: virtual void CFoundryTool::ConsoleCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoundryTool::ConsoleCommand(CConsolePage *this, const char *pCommand)
{
  enginetools->Command(this: enginetools, a2: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x102DEE10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Button::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Button::GetMessageMap(vgui::Button *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Button::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetMessageMap'::`2'::s_pMap;
  `vgui::Button::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Button");
  `vgui::Button::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DEE50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Button::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Button::GetKBMap(vgui::Button *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Button::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetKBMap'::`2'::s_pMap;
  `vgui::Button::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  `vgui::Button::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DF670
// Name: protected: virtual class vgui::IBorder __near * vgui::Button::GetBorder(bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Button::GetBorder(
        vgui::Button *this,
        bool depressed,
        bool armed,
        bool selected,
        bool keyfocus)
{
  if ( (this->_buttonFlags.m_nFlags & 8) != 0 )
  {
    if ( depressed )
      return this->_depressedBorder;
    if ( keyfocus || this->IsEnabled(this) && (this->_buttonFlags.m_nFlags & 0x40) != 0 )
      return this->_keyFocusBorder;
  }
  else if ( depressed )
  {
    return this->_depressedBorder;
  }
  return this->_defaultBorder;
}

//------------------------------------------------------------------------------
// Address: 0x102E7EE0
// Name: public: virtual class vgui::Panel __near * vgui::Label::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Label *__thiscall vgui::Label::HasHotkey(vgui::Label *this, wchar_t key)
{
  unsigned __int16 v2; // si

  v2 = key;
  if ( iswalnum(c: key) != 0 )
    v2 = towlower(c: key);
  return this->_hotkey != v2 ? nullptr : this;
}

//------------------------------------------------------------------------------
// Address: 0x102E94B0
// Name: public: virtual class vgui::IImage __near * vgui::Label::GetImageAtIndex(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::Label::GetImageAtIndex(vgui::Label *this, int index)
{
  if ( index < 0 || index >= this->_imageDar.m_Size )
    return nullptr;
  else
    return this->_imageDar.m_Memory.m_pMemory[index].image;
}

//------------------------------------------------------------------------------
// Address: 0x102E99E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Label::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Label::GetMessageMap(vgui::Label *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Label::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetMessageMap'::`2'::s_pMap;
  `vgui::Label::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Label");
  `vgui::Label::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E9A10
// Name: public: virtual struct PanelAnimationMap __near * vgui::Label::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Label::GetAnimMap(vgui::Label *this)
{
  return FindOrAddPanelAnimationMap(className: "Label");
}

//------------------------------------------------------------------------------
// Address: 0x102E9A20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Label::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Label::GetKBMap(vgui::Label *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Label::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetKBMap'::`2'::s_pMap;
  `vgui::Label::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  `vgui::Label::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F87C0
// Name: private: class vgui::MenuItem __near * vgui::Menu::GetParentMenuItem(void)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__thiscall vgui::Menu::GetParentMenuItem(vgui::Menu *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  return (vgui::MenuItem *)__RTDynamicCast(
                             inptr: v1,
                             VfDelta: 0,
                             SrcType: &vgui::Panel `RTTI Type Descriptor',
                             TargetType: &vgui::MenuItem `RTTI Type Descriptor',
                             isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102F90F0
// Name: public: class vgui::MenuItem __near * vgui::Menu::GetMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__thiscall vgui::Menu::GetMenuItem(vgui::Menu *this, int itemID)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_MenuItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_MenuItems.m_LastAlloc.index
    && ((m_pMemory = this->m_MenuItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FAEE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Menu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Menu::GetMessageMap(vgui::Menu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Menu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Menu::GetMessageMap'::`2'::s_pMap;
  `vgui::Menu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Menu");
  `vgui::Menu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FAF10
// Name: public: virtual struct PanelAnimationMap __near * vgui::Menu::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Menu::GetAnimMap(vgui::Menu *this)
{
  return FindOrAddPanelAnimationMap(className: "Menu");
}

//------------------------------------------------------------------------------
// Address: 0x102FAF20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Menu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Menu::GetKBMap(vgui::Menu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Menu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Menu::GetKBMap'::`2'::s_pMap;
  `vgui::Menu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Menu");
  `vgui::Menu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FCBA0
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

//------------------------------------------------------------------------------
// Address: 0x102FCBB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102FCBE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x102FCBF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103121F0
// Name: public: unsigned short CUtlDict<class CUtlString,unsigned short>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CUtlString,unsigned short>::Find(
        CUtlDict<CUtlString,unsigned short> *this,
        const char *pName)
{
  unsigned __int16 v3; // si
  CUtlMap<char const *,CUtlString,unsigned short>::Node_t search; // [esp+8h] [ebp-14h] BYREF

  if ( pName == nullptr )
    return -1;
  CUtlString::CUtlString(this: &search.elem);
  search.key = pName;
  v3 = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  search.elem.m_Storage.m_nActualLength = 0;
  if ( search.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && search.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Storage.m_Memory.m_pMemory);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103135D0
// Name: public: void CUtlDict<class CUtlString,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CUtlString,unsigned short>::RemoveAll(CUtlDict<CUtlString,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10313920
// Name: public: unsigned short CUtlDict<class CUtlString,unsigned short>::Insert(char const __near *,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CUtlString,unsigned short>::Insert(
        CUtlDict<CUtlString,unsigned short> *this,
        const char *pName,
        const CUtlString *element)
{
  char *v4; // eax
  const char *v5; // esi
  unsigned __int16 v6; // si
  CUtlMap<char const *,CUtlString,unsigned short>::Node_t insert; // [esp+Ch] [ebp-14h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v4, pName);
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  CUtlString::CUtlString(this: &insert.elem);
  insert.key = v5;
  CUtlString::operator=(this: &insert.elem, src: element);
  v6 = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Elements.m_Tree,
         &insert);
  insert.elem.m_Storage.m_nActualLength = 0;
  if ( insert.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && insert.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: insert.elem.m_Storage.m_Memory.m_pMemory);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10315EA0
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  bool v6; // al
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  bool v9; // al
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  bool v12; // al

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = this->_minimizeButton->IsVisible(this: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = this->_maximizeButton->IsVisible(this: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = this->_closeButton->IsVisible(this: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}

//------------------------------------------------------------------------------
// Address: 0x103168E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10316910
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x10316920
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1046B9D0
// Name: protected: void CElementPropertiesTreeInternal::CollectSelectedElements<class CDmrElementArray<class CDmElement>>(class CDmrElementArray<class CDmElement> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CElementPropertiesTreeInternal::CollectSelectedElements<CDmrElementArray<CDmElement>>(
        CElementPropertiesTreeInternal *this,
        CDmrElementArray<CDmElement> *container)
{
  CElementTreeViewListControl *m_pTree; // ecx
  int m_Size; // ebx
  int v4; // eax
  int v5; // ecx
  KeyValues *v6; // edi
  DmElementHandle_t Int; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  const char *String; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v12; // esi
  unsigned __int16 m_nFlags; // cx
  int v14; // eax
  DmElementHandle_t *v15; // eax
  CDmElement *v16; // eax
  CExpressionCalculator *v17; // esi
  int v18; // eax
  CDmElement *v19; // eax
  CExpressionCalculator *v20; // esi
  int j; // edi
  CDmElement *v22; // eax
  CExpressionCalculator *v23; // esi
  KeyValues **m_pMemory; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > selection; // [esp+Ch] [ebp-30h] BYREF
  CDmrElementArray<CDmElement> arrayAttr; // [esp+20h] [ebp-1Ch] BYREF
  int nSelected; // [esp+28h] [ebp-14h]
  int i; // [esp+2Ch] [ebp-10h]
  DmElementHandle_t BufferType; // [esp+30h] [ebp-Ch] BYREF
  DmElementHandle_t v30; // [esp+34h] [ebp-8h] BYREF
  DmElementHandle_t src; // [esp+38h] [ebp-4h] BYREF

  m_pTree = this->m_pTree;
  m_Size = 0;
  memset(&selection, 0, sizeof(selection));
  v4 = (int)m_pTree->GetTree(this: m_pTree);
  (*(void (__thiscall **)(int, CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *))(*(_DWORD *)v4 + 940))(
    a1: v4,
    a2: &selection);
  v5 = 0;
  nSelected = selection.m_Size;
  for ( i = 0; v5 < nSelected; i = v5 )
  {
    v6 = selection.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      Int = KeyValues::GetInt(this: v6, keyName: "ownerelement", defaultValue: -1);
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Int);
      v9 = v8;
      if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
      {
        String = KeyValues::GetString(this: v6, keyName: "attributeName", defaultValue: &var);
        Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: String);
        v12 = Attribute;
        if ( Attribute != nullptr )
        {
          m_nFlags = Attribute->m_nFlags;
          v14 = m_nFlags & 0x1F;
          if ( v14 == 1 )
          {
            if ( (m_nFlags & 0x1F) == 1
              && (v15 = (DmElementHandle_t *)CDmAttribute::GetValue<enum DmElementHandle_t>(this: v12),
                  v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: *v15),
                  v17 = (CExpressionCalculator *)v16,
                  v16 != nullptr)
              && v16->IsA(this: v16, a2: CDmElement::m_classType) )
            {
              src = CCodecBuffer_Block::GetBufferType(this: v17);
              CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                this: container,
                &src);
            }
            else
            {
              src = DMELEMENT_HANDLE_INVALID;
              CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                this: container,
                &src);
            }
          }
          else if ( v14 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&arrayAttr);
            if ( (v12->m_nFlags & 0x1F) == 0xF )
            {
              arrayAttr.m_pAttribute = v12;
              arrayAttr.m_pStorage = (DmElementArray_t *)v12->m_pData;
              m_Size = arrayAttr.m_pStorage->m_Size;
            }
            else
            {
              arrayAttr.m_pAttribute = nullptr;
              arrayAttr.m_pStorage = nullptr;
            }
            v18 = KeyValues::GetInt(this: v6, keyName: "arrayIndex", defaultValue: -1);
            if ( v18 < 0 )
            {
              for ( j = 0; j < m_Size; ++j )
              {
                v22 = g_pDataModel->GetElement(this: g_pDataModel, a2: arrayAttr.m_pStorage->m_Memory.m_pMemory[j]);
                v23 = (CExpressionCalculator *)v22;
                if ( v22 != nullptr && v22->IsA(this: v22, a2: CDmElement::m_classType) )
                  BufferType = CCodecBuffer_Block::GetBufferType(this: v23);
                else
                  BufferType = DMELEMENT_HANDLE_INVALID;
                CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                  this: container,
                  src: &BufferType);
              }
            }
            else
            {
              v19 = g_pDataModel->GetElement(this: g_pDataModel, a2: arrayAttr.m_pStorage->m_Memory.m_pMemory[v18]);
              v20 = (CExpressionCalculator *)v19;
              if ( v19 != nullptr && v19->IsA(this: v19, a2: CDmElement::m_classType) )
              {
                v30 = CCodecBuffer_Block::GetBufferType(this: v20);
                CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                  this: container,
                  src: &v30);
              }
              else
              {
                v30 = DMELEMENT_HANDLE_INVALID;
                CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                  this: container,
                  src: &v30);
              }
            }
            m_Size = 0;
          }
        }
      }
    }
    v5 = i + 1;
  }
  m_pMemory = selection.m_Memory.m_pMemory;
  selection.m_Size = 0;
  if ( selection.m_Memory.m_nGrowSize >= 0 )
  {
    if ( selection.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: selection.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      selection.m_Memory.m_pMemory = nullptr;
    }
    selection.m_Memory.m_nAllocationCount = 0;
  }
  selection.m_pElements = m_pMemory;
  if ( selection.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10485AA0
// Name: public: unsigned short CUtlDict<class IAttributeWidgetFactory __near *,unsigned short>::Insert(char const __near *,class IAttributeWidgetFactory __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
        CUtlDict<IAttributeWidgetFactory *,unsigned short> *this,
        const char *pName,
        IAttributeWidgetFactory **element)
{
  char *v4; // eax
  IAttributeWidgetFactory *v5; // edx
  CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  v5 = *element;
  insert.key = v4;
  insert.elem = v5;
  return CUtlRBTree<CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x10489240
// Name: public: unsigned short CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short>::Find(enum DmElementHandle_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Find(
        CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *this,
        DmElementHandle_t *key)
{
  DmElementHandle_t v2; // edx
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t dummyNode; // [esp+0h] [ebp-54h] BYREF

  memset(dummyNode.elem.m_pValueAttribute, 0, 40);
  v2 = *key;
  memset(&dummyNode.elem, 0, 24);
  dummyNode.elem.m_Quaternion = quat_identity;
  dummyNode.key = v2;
  return CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_Tree,
           search: &dummyNode);
}

//------------------------------------------------------------------------------
// Address: 0x1048B5E0
// Name: public: unsigned short CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short>::Insert(enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Insert(
        CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *this,
        DmElementHandle_t *key)
{
  DmElementHandle_t v2; // edx
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t node; // [esp+0h] [ebp-54h] BYREF

  memset(node.elem.m_pValueAttribute, 0, 40);
  v2 = *key;
  memset(&node.elem, 0, 24);
  node.elem.m_Quaternion = quat_identity;
  node.key = v2;
  return CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Tree,
           insert: &node);
}

//------------------------------------------------------------------------------
// Address: 0x104B4450
// Name: public: void CUtlDict<class CDmElement __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDmElement *,int>::RemoveAll(CUtlDict<CDmElement *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x104B50E0
// Name: public: int CUtlMap<char const __near *,class CDmElement __near *,int>::Insert(char const __near * const __near &,class CDmElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CDmElement *,int>::Insert(
        CUtlMap<char const *,CDmElement *,int> *this,
        const char **key,
        int insert)
{
  CDmElement *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CDmElement *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CDmElement **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int,CUtlMap<char const *,enum DmElementHandle_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x104B5B70
// Name: public: int CUtlDict<class CDmElement __near *,int>::Insert(char const __near *,class CDmElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDmElement *,int>::Insert(
        CUtlDict<CDmElement *,int> *this,
        char *pName,
        CDmElement *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CDmElement *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x105C12D0
// Name: _dynamic_initializer_for__foundry_draw_hammer_models__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_draw_hammer_models__()
{
  ConVar::ConVar(this: &foundry_draw_hammer_models, pName: "foundry_draw_hammer_models", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__foundry_draw_hammer_models__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1300
// Name: _dynamic_initializer_for__foundry_draw_hammer_entities__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_draw_hammer_entities__()
{
  ConVar::ConVar(
    this: &foundry_draw_hammer_entities,
    pName: "foundry_draw_hammer_entities",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__foundry_draw_hammer_entities__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1330
// Name: _dynamic_initializer_for__foundry_auto_pause__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_auto_pause__()
{
  ConVar::ConVar(
    this: &foundry_auto_pause,
    pName: "foundry_auto_pause",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "If 1, Foundry pauses the game when the engine window loses focus. If 2, Foundry disables AI when the engine window loses focus.");
  return atexit(func: dynamic_atexit_destructor_for__foundry_auto_pause__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1360
// Name: _dynamic_initializer_for__foundry_sync_engine_view_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_sync_engine_view_command__()
{
  ConCommand::ConCommand(
    this: &foundry_sync_engine_view_command,
    pName: "foundry_sync_engine_view",
    callback: (void (__cdecl *)(const CCommand *))foundry_sync_engine_view,
    pHelpString: "Move engine's 3D view to the same position as Hammer's 3D view.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__foundry_sync_engine_view_command__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1390
// Name: _dynamic_initializer_for__foundry_send_ents_to_engine_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_send_ents_to_engine_command__()
{
  ConCommand::ConCommand(
    this: &foundry_send_ents_to_engine_command,
    pName: "foundry_send_ents_to_engine",
    callback: (void (__cdecl *)(const CCommand *))foundry_send_ents_to_engine,
    pHelpString: "Send selected entities in Hammer into the engine.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__foundry_send_ents_to_engine_command__);
}

//------------------------------------------------------------------------------
// Address: 0x105C13C0
// Name: _dynamic_initializer_for__foundry_move_focus_to_engine_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_move_focus_to_engine_command__()
{
  ConCommand::ConCommand(
    this: &foundry_move_focus_to_engine_command,
    pName: "foundry_move_focus_to_engine",
    callback: (void (__cdecl *)(const CCommand *))foundry_move_focus_to_engine,
    pHelpString: "Send focus to the engine.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__foundry_move_focus_to_engine_command__);
}

//------------------------------------------------------------------------------
// Address: 0x105C13F0
// Name: _dynamic_initializer_for__foundry_spawn_visgroup_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_spawn_visgroup_command__()
{
  ConCommand::ConCommand(
    this: &foundry_spawn_visgroup_command,
    pName: "foundry_spawn_visgroup",
    callback: foundry_spawn_visgroup,
    pHelpString: "Spawn all the entities in the specified visgroup.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__foundry_spawn_visgroup_command__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1420
// Name: _dynamic_initializer_for__foundry_remove_selected_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_remove_selected_command__()
{
  ConCommand::ConCommand(
    this: &foundry_remove_selected_command,
    pName: "foundry_remove_selected",
    callback: (void (__cdecl *)(const CCommand *))foundry_remove_selected,
    pHelpString: "Remove selected entities.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__foundry_remove_selected_command__);
}

//------------------------------------------------------------------------------
// Address: 0x105CB260
// Name: _dynamic_atexit_destructor_for__foundry_draw_hammer_models__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_draw_hammer_models__()
{
  ConVar::~ConVar(this: &foundry_draw_hammer_models);
}

//------------------------------------------------------------------------------
// Address: 0x105CB270
// Name: _dynamic_atexit_destructor_for__foundry_draw_hammer_entities__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_draw_hammer_entities__()
{
  ConVar::~ConVar(this: &foundry_draw_hammer_entities);
}

//------------------------------------------------------------------------------
// Address: 0x105CB280
// Name: _dynamic_atexit_destructor_for__foundry_auto_pause__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_auto_pause__()
{
  ConVar::~ConVar(this: &foundry_auto_pause);
}

//------------------------------------------------------------------------------
// Address: 0x105CB290
// Name: _dynamic_atexit_destructor_for__foundry_sync_engine_view_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_sync_engine_view_command__()
{
  ConCommand::~ConCommand(this: &foundry_sync_engine_view_command);
}

//------------------------------------------------------------------------------
// Address: 0x105CB2A0
// Name: _dynamic_atexit_destructor_for__foundry_send_ents_to_engine_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_send_ents_to_engine_command__()
{
  ConCommand::~ConCommand(this: &foundry_send_ents_to_engine_command);
}

//------------------------------------------------------------------------------
// Address: 0x105CB2B0
// Name: _dynamic_atexit_destructor_for__foundry_move_focus_to_engine_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_move_focus_to_engine_command__()
{
  ConCommand::~ConCommand(this: &foundry_move_focus_to_engine_command);
}

//------------------------------------------------------------------------------
// Address: 0x105CB2C0
// Name: _dynamic_atexit_destructor_for__foundry_spawn_visgroup_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_spawn_visgroup_command__()
{
  ConCommand::~ConCommand(this: &foundry_spawn_visgroup_command);
}

//------------------------------------------------------------------------------
// Address: 0x105CB2D0
// Name: _dynamic_atexit_destructor_for__foundry_remove_selected_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_remove_selected_command__()
{
  ConCommand::~ConCommand(this: &foundry_remove_selected_command);
}

//------------------------------------------------------------------------------
// Address: 0x10107B50
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<char const __near *,struct CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,struct CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    *(_DWORD *)&`CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x105C1450
// Name: _dynamic_initializer_for__g_Registry__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Registry__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Registry__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1460
// Name: _dynamic_initializer_for__mcm_CMapAlignedBox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapAlignedBox__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapAlignedBox,
    Type: CMapAlignedBox::__Type,
    pfnNew: CMapAlignedBox_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapAlignedBox__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1490
// Name: _dynamic_initializer_for__mcm_CMapAnimator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapAnimator__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapAnimator,
    Type: CMapAnimator::__Type,
    pfnNew: (CMapClass *(__cdecl *)())CMapAnimator::CreateMapAnimator);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapAnimator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C14C0
// Name: _dynamic_initializer_for__mcm_CMapAxisHandle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapAxisHandle__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapAxisHandle,
    Type: CMapAxisHandle::__Type,
    pfnNew: CMapAxisHandle_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapAxisHandle__);
}

//------------------------------------------------------------------------------
// Address: 0x105C14F0
// Name: _dynamic_initializer_for__s_Classes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_Classes__()
{
  s_Classes.m_Size = 0;
  s_Classes.m_pElements = s_Classes.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_Classes__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1540
// Name: _dynamic_initializer_for__mcm_CMapCylinder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapCylinder__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapCylinder,
    Type: CMapCylinder::__Type,
    pfnNew: CMapCylinder_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapCylinder__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1570
// Name: _dynamic_initializer_for__mcm_CMapDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapDecal__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapDecal,
    Type: CMapDecal::__Type,
    pfnNew: (CMapClass *(__cdecl *)())CMapDecal_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapDecal__);
}

//------------------------------------------------------------------------------
// Address: 0x105C15A0
// Name: _dynamic_initializer_for__mcm_CMapEntity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapEntity__()
{
  CMapClassManager::CMapClassManager(this: &mcm_CMapEntity, Type: CMapEntity::__Type, pfnNew: CMapEntity_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapEntity__);
}

//------------------------------------------------------------------------------
// Address: 0x105C15D0
// Name: _dynamic_initializer_for__FoundEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__FoundEntities__()
{
  *((_DWORD *)&FoundEntities.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &FoundEntities.m_Memory, nGrowSize: 0, nInitSize: 0);
  FoundEntities.m_Size = 0;
  FoundEntities.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__FoundEntities__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1640
// Name: _dynamic_initializer_for__g_OpaqueFaces__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OpaqueFaces__()
{
  g_OpaqueFaces.m_NumElements = 0;
  g_OpaqueFaces.m_Root = -1;
  g_OpaqueFaces.m_FirstFree = -1;
  g_OpaqueFaces.m_LastAlloc.index = -1;
  g_OpaqueFaces.m_pElements = g_OpaqueFaces.m_Elements.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__g_OpaqueFaces__);
}

//------------------------------------------------------------------------------
// Address: 0x105C16A0
// Name: _dynamic_initializer_for__g_OpaqueInstanceFaces__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OpaqueInstanceFaces__()
{
  g_OpaqueInstanceFaces.m_Size = 0;
  g_OpaqueInstanceFaces.m_pElements = g_OpaqueInstanceFaces.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__g_OpaqueInstanceFaces__);
}

//------------------------------------------------------------------------------
// Address: 0x105C16F0
// Name: _dynamic_initializer_for__mcm_CMapFrustum__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapFrustum__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapFrustum,
    Type: CMapFrustum::__Type,
    pfnNew: CMapFrustum_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapFrustum__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1720
// Name: _dynamic_initializer_for__mcm_CMapGroup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapGroup__()
{
  CMapClassManager::CMapClassManager(this: &mcm_CMapGroup, Type: CMapGroup::__Type, pfnNew: CMapGroup_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapGroup__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1750
// Name: _dynamic_initializer_for__mcm_CMapInstance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapInstance__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapInstance,
    Type: CMapInstance::__Type,
    pfnNew: CMapInstance_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapInstance__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1780
// Name: _dynamic_initializer_for__mcm_CMapKeyFrame__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapKeyFrame__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapKeyFrame,
    Type: CMapKeyFrame::__Type,
    pfnNew: (CMapClass *(__cdecl *)())CMapKeyFrame::CreateMapKeyFrame);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapKeyFrame__);
}

//------------------------------------------------------------------------------
// Address: 0x105C17B0
// Name: _dynamic_initializer_for__mcm_CMapLight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapLight__()
{
  CMapClassManager::CMapClassManager(this: &mcm_CMapLight, Type: CMapLight::__Type, pfnNew: CMapLight::CreateMapLight);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapLight__);
}

//------------------------------------------------------------------------------
// Address: 0x105C17E0
// Name: _dynamic_initializer_for__mcm_CMapLightCone__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapLightCone__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapLightCone,
    Type: CMapLightCone::__Type,
    pfnNew: CMapLightCone_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapLightCone__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1810
// Name: _dynamic_initializer_for__mcm_CMapLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapLine__()
{
  CMapClassManager::CMapClassManager(this: &mcm_CMapLine, Type: CMapLine::__Type, pfnNew: CMapLine_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapLine__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1840
// Name: _dynamic_initializer_for__mcm_CMapLineOccluder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapLineOccluder__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapLineOccluder,
    Type: CMapLineOccluder::__Type,
    pfnNew: CMapLineOccluder_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapLineOccluder__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1870
// Name: _dynamic_initializer_for__mcm_CMapOccluder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapOccluder__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapOccluder,
    Type: CMapOccluder::__Type,
    pfnNew: CMapOccluder_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapOccluder__);
}

//------------------------------------------------------------------------------
// Address: 0x105C18A0
// Name: _dynamic_initializer_for__mcm_CMapOverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapOverlay__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapOverlay,
    Type: CMapOverlay::__Type,
    pfnNew: CMapOverlay::CreateMapOverlay);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapOverlay__);
}

//------------------------------------------------------------------------------
// Address: 0x105C18D0
// Name: _dynamic_initializer_for__mcm_CMapPlayerHullHandle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapPlayerHullHandle__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapPlayerHullHandle,
    Type: CMapPlayerHullHandle::__Type,
    pfnNew: CMapPlayerHullHandle_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapPlayerHullHandle__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1900
// Name: _dynamic_initializer_for__mcm_CMapPointHandle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapPointHandle__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapPointHandle,
    Type: CMapPointHandle::__Type,
    pfnNew: CMapPointHandle_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapPointHandle__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1930
// Name: _dynamic_initializer_for__mcm_CMapQuadBounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapQuadBounds__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapQuadBounds,
    Type: CMapQuadBounds::__Type,
    pfnNew: (CMapClass *(__cdecl *)())CMapQuadBounds::CreateQuadBounds);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapQuadBounds__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1960
// Name: _dynamic_initializer_for__mcm_CMapSideList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapSideList__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapSideList,
    Type: CMapSideList::__Type,
    pfnNew: CMapSideList_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapSideList__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1990
// Name: _dynamic_initializer_for__mcm_CMapSolid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapSolid__()
{
  CMapClassManager::CMapClassManager(this: &mcm_CMapSolid, Type: CMapSolid::__Type, pfnNew: CMapSolid_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapSolid__);
}

//------------------------------------------------------------------------------
// Address: 0x105C19C0
// Name: _dynamic_initializer_for__mcm_CMapSphere__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapSphere__()
{
  CMapClassManager::CMapClassManager(this: &mcm_CMapSphere, Type: CMapSphere::__Type, pfnNew: CMapSphere_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapSphere__);
}

//------------------------------------------------------------------------------
// Address: 0x105C19F0
// Name: _dynamic_initializer_for__mcm_CMapSprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapSprite__()
{
  CMapClassManager::CMapClassManager(this: &mcm_CMapSprite, Type: CMapSprite::__Type, pfnNew: CMapSprite_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapSprite__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1A20
// Name: _dynamic_initializer_for__mcm_CMapStudioModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapStudioModel__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapStudioModel,
    Type: CMapStudioModel::__Type,
    pfnNew: CMapStudioModel_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapStudioModel__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1A50
// Name: _dynamic_initializer_for__mcm_CMapSweptPlayerHull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapSweptPlayerHull__()
{
  CMapClassManager::CMapClassManager(
    this: &mcm_CMapSweptPlayerHull,
    Type: CMapSweptPlayerHull::__Type,
    pfnNew: CMapSweptPlayerHull_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapSweptPlayerHull__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1A80
// Name: _dynamic_initializer_for__mcm_CMapViewer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapViewer__()
{
  CMapClassManager::CMapClassManager(this: &mcm_CMapViewer, Type: CMapViewer::__Type, pfnNew: CMapViewer_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapViewer__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1AB0
// Name: _dynamic_initializer_for__mcm_CMapWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mcm_CMapWorld__()
{
  CMapClassManager::CMapClassManager(this: &mcm_CMapWorld, Type: CMapWorld::__Type, pfnNew: CMapWorld_CreateObject);
  return atexit(func: dynamic_atexit_destructor_for__mcm_CMapWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x105C1AE0
// Name: _dynamic_initializer_for__g_materialSystemConfig__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int dynamic_initializer_for__g_materialSystemConfig__()
{
  unsigned int result; // eax

  result = g_materialSystemConfig.m_Flags & 0xFFF91864 | 0x208;
  g_materialSystemConfig.m_Flags = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105CB2E0
// Name: _dynamic_atexit_destructor_for__g_Registry__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Registry__()
{
  g_Registry.__vftable = (CRegistry_vtbl *)&CRegistry::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x105CB2F0
// Name: _dynamic_atexit_destructor_for__mcm_CMapAlignedBox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapAlignedBox__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapAlignedBox);
}

//------------------------------------------------------------------------------
// Address: 0x105CB300
// Name: _dynamic_atexit_destructor_for__mcm_CMapAnimator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapAnimator__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapAnimator);
}

//------------------------------------------------------------------------------
// Address: 0x105CB310
// Name: _dynamic_atexit_destructor_for__mcm_CMapAxisHandle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapAxisHandle__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapAxisHandle);
}

//------------------------------------------------------------------------------
// Address: 0x105CB320
// Name: _dynamic_atexit_destructor_for__s_Classes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_Classes__()
{
  MCMSTRUCT *m_pMemory; // eax

  m_pMemory = s_Classes.m_Memory.m_pMemory;
  s_Classes.m_Size = 0;
  if ( s_Classes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_Classes.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: s_Classes.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      s_Classes.m_Memory.m_pMemory = nullptr;
    }
    s_Classes.m_Memory.m_nAllocationCount = 0;
  }
  s_Classes.m_pElements = m_pMemory;
  if ( s_Classes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_Classes.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: s_Classes.m_Memory.m_pMemory);
      s_Classes.m_Memory.m_pMemory = nullptr;
    }
    s_Classes.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CB3B0
// Name: _dynamic_atexit_destructor_for__mcm_CMapCylinder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapCylinder__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapCylinder);
}

//------------------------------------------------------------------------------
// Address: 0x105CB3C0
// Name: _dynamic_atexit_destructor_for__mcm_CMapDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapDecal__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapDecal);
}

//------------------------------------------------------------------------------
// Address: 0x105CB3D0
// Name: _dynamic_atexit_destructor_for__mcm_CMapEntity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapEntity__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapEntity);
}

//------------------------------------------------------------------------------
// Address: 0x105CB3E0
// Name: _dynamic_atexit_destructor_for__FoundEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__FoundEntities__()
{
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &FoundEntities);
}

//------------------------------------------------------------------------------
// Address: 0x105CB420
// Name: _dynamic_atexit_destructor_for__g_OpaqueInstanceFaces__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OpaqueInstanceFaces__()
{
  CUtlRBTree<MapFaceRender_t,int,bool (__cdecl*)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int> > **m_pMemory; // eax

  m_pMemory = g_OpaqueInstanceFaces.m_Memory.m_pMemory;
  g_OpaqueInstanceFaces.m_Size = 0;
  if ( g_OpaqueInstanceFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_OpaqueInstanceFaces.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: g_OpaqueInstanceFaces.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_OpaqueInstanceFaces.m_Memory.m_pMemory = nullptr;
    }
    g_OpaqueInstanceFaces.m_Memory.m_nAllocationCount = 0;
  }
  g_OpaqueInstanceFaces.m_pElements = m_pMemory;
  if ( g_OpaqueInstanceFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_OpaqueInstanceFaces.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: g_OpaqueInstanceFaces.m_Memory.m_pMemory);
      g_OpaqueInstanceFaces.m_Memory.m_pMemory = nullptr;
    }
    g_OpaqueInstanceFaces.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CB4B0
// Name: _dynamic_atexit_destructor_for__g_OpaqueFaces__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OpaqueFaces__()
{
  CUtlRBTree<MapFaceRender_t,int,bool (__cdecl *)(MapFaceRender_t const &,MapFaceRender_t const &),CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int>>::RemoveAll(this: &g_OpaqueFaces);
  g_OpaqueFaces.m_FirstFree = -1;
  if ( g_OpaqueFaces.m_Elements.m_nGrowSize >= 0 )
  {
    if ( g_OpaqueFaces.m_Elements.m_pMemory != nullptr )
    {
      free(pMem: g_OpaqueFaces.m_Elements.m_pMemory);
      g_OpaqueFaces.m_Elements.m_pMemory = nullptr;
    }
    g_OpaqueFaces.m_Elements.m_nAllocationCount = 0;
  }
  g_OpaqueFaces.m_LastAlloc.index = -1;
  if ( g_OpaqueFaces.m_Elements.m_nGrowSize >= 0 )
  {
    if ( g_OpaqueFaces.m_Elements.m_pMemory != nullptr )
    {
      free(pMem: g_OpaqueFaces.m_Elements.m_pMemory);
      g_OpaqueFaces.m_Elements.m_pMemory = nullptr;
    }
    g_OpaqueFaces.m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CB550
// Name: _dynamic_atexit_destructor_for__mcm_CMapFrustum__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapFrustum__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapFrustum);
}

//------------------------------------------------------------------------------
// Address: 0x105CB560
// Name: _dynamic_atexit_destructor_for__mcm_CMapGroup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapGroup__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapGroup);
}

//------------------------------------------------------------------------------
// Address: 0x105CB570
// Name: _dynamic_atexit_destructor_for__mcm_CMapInstance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapInstance__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapInstance);
}

//------------------------------------------------------------------------------
// Address: 0x105CB580
// Name: _dynamic_atexit_destructor_for__mcm_CMapKeyFrame__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapKeyFrame__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapKeyFrame);
}

//------------------------------------------------------------------------------
// Address: 0x105CB590
// Name: _dynamic_atexit_destructor_for__mcm_CMapLight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapLight__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapLight);
}

//------------------------------------------------------------------------------
// Address: 0x105CB5A0
// Name: _dynamic_atexit_destructor_for__mcm_CMapLightCone__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapLightCone__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapLightCone);
}

//------------------------------------------------------------------------------
// Address: 0x105CB5B0
// Name: _dynamic_atexit_destructor_for__mcm_CMapLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapLine__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapLine);
}

//------------------------------------------------------------------------------
// Address: 0x105CB5C0
// Name: _dynamic_atexit_destructor_for__mcm_CMapLineOccluder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapLineOccluder__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapLineOccluder);
}

//------------------------------------------------------------------------------
// Address: 0x105CB5D0
// Name: _dynamic_atexit_destructor_for__mcm_CMapOccluder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapOccluder__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapOccluder);
}

//------------------------------------------------------------------------------
// Address: 0x105CB5E0
// Name: _dynamic_atexit_destructor_for__mcm_CMapOverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapOverlay__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapOverlay);
}

//------------------------------------------------------------------------------
// Address: 0x105CB5F0
// Name: _dynamic_atexit_destructor_for__mcm_CMapPlayerHullHandle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapPlayerHullHandle__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapPlayerHullHandle);
}

//------------------------------------------------------------------------------
// Address: 0x105CB600
// Name: _dynamic_atexit_destructor_for__mcm_CMapPointHandle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapPointHandle__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapPointHandle);
}

//------------------------------------------------------------------------------
// Address: 0x105CB610
// Name: _dynamic_atexit_destructor_for__mcm_CMapQuadBounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapQuadBounds__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapQuadBounds);
}

//------------------------------------------------------------------------------
// Address: 0x105CB620
// Name: _dynamic_atexit_destructor_for__mcm_CMapSideList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapSideList__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapSideList);
}

//------------------------------------------------------------------------------
// Address: 0x105CB630
// Name: _dynamic_atexit_destructor_for__mcm_CMapSolid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapSolid__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapSolid);
}

//------------------------------------------------------------------------------
// Address: 0x105CB640
// Name: _dynamic_atexit_destructor_for__mcm_CMapSphere__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapSphere__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapSphere);
}

//------------------------------------------------------------------------------
// Address: 0x105CB650
// Name: _dynamic_atexit_destructor_for__mcm_CMapSprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapSprite__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapSprite);
}

//------------------------------------------------------------------------------
// Address: 0x105CB660
// Name: _dynamic_atexit_destructor_for__mcm_CMapStudioModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapStudioModel__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapStudioModel);
}

//------------------------------------------------------------------------------
// Address: 0x105CB670
// Name: _dynamic_atexit_destructor_for__mcm_CMapSweptPlayerHull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapSweptPlayerHull__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapSweptPlayerHull);
}

//------------------------------------------------------------------------------
// Address: 0x105CB680
// Name: _dynamic_atexit_destructor_for__mcm_CMapViewer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapViewer__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapViewer);
}

//------------------------------------------------------------------------------
// Address: 0x105CB690
// Name: _dynamic_atexit_destructor_for__mcm_CMapWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CMapWorld__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CMapWorld);
}

//------------------------------------------------------------------------------
// Address: 0x105CB6A0
// Name: _dynamic_atexit_destructor_for__sg_ExtraFP16Targets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sg_ExtraFP16Targets__()
{
  `eh vector destructor iterator'(
    ptr: sg_ExtraFP16Targets,
    size: 4u,
    count: 4,
    pDtor: (void (__thiscall *)(void *))CTextureReference::~CTextureReference);
}
