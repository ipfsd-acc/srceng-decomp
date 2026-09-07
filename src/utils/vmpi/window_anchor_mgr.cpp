// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/window_anchor_mgr.cpp
// Functions: 39
// ============================================================

#include "utils\vmpi\window_anchor_mgr.h"

//------------------------------------------------------------------------------
// Address: 0x00402690
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CServiceInfo __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CServiceInfo *,int> *m_pMemory; // ecx

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
        m_nAllocationCount = 3;
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
      this->m_pMemory = (UtlLinkedListElem_t<CServiceInfo *,int> *)realloc(
                                                                     pBlock: m_pMemory,
                                                                     newsize: 12 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CServiceInfo *,int> *)malloc(size: 12 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004027D0
// Name: public: void CUtlMemory<class CIPAddr,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CIPAddr,int>::Grow(CUtlMemory<CIPAddr,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CIPAddr *m_pMemory; // ecx

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
        m_nAllocationCount = 6;
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
      this->m_pMemory = (CIPAddr *)realloc(pBlock: m_pMemory, newsize: 6 * m_nAllocationCount);
    else
      this->m_pMemory = (CIPAddr *)malloc(size: 6 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004029C0
// Name: public: void CUtlLinkedList<class CServiceInfo __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CServiceInfo __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::RemoveAll(
        CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CServiceInfo *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402A20
// Name: protected: int CUtlLinkedList<class CServiceInfo __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CServiceInfo __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::AllocInternal(
        CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CServiceInfo *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00403010
// Name: public: CUtlLinkedList<class CServiceInfo __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CServiceInfo __near *,int>,int>>::~CUtlLinkedList<class CServiceInfo __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CServiceInfo __near *,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::~CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>(
        CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int> > *this)
{
  CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pBlock: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004030A0
// Name: public: void CUtlLinkedList<class CWindowAnchor,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CWindowAnchor,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int>>::RemoveAll(
        CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CWindowAnchor,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403170
// Name: public: void CUtlLinkedList<class CServiceInfo __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CServiceInfo __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::Unlink(
        CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CServiceInfo *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403790
// Name: public: void CUtlLinkedList<class CServiceInfo __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CServiceInfo __near *,int>,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::PurgeAndDeleteElements(
        CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int> > *this)
{
  int m_Head; // eax
  int v3; // eax
  CServiceInfo *m_Element; // edi
  int m_Next; // ebx
  UtlLinkedListElem_t<CServiceInfo *,int> *m_pMemory; // edx

  m_Head = this->m_Head;
  if ( m_Head != -1 )
  {
    do
    {
      v3 = m_Head;
      m_Element = this->m_Memory.m_pMemory[v3].m_Element;
      m_Next = this->m_Memory.m_pMemory[v3].m_Next;
      if ( m_Element != nullptr )
      {
        CServiceInfo::~CServiceInfo(this: m_Element);
        operator delete(p: m_Element);
      }
      m_Head = m_Next;
    }
    while ( m_Next != -1 );
  }
  CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pBlock: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_NumAlloced = 0;
  this->m_FirstFree = -1;
  this->m_LastAlloc.index = -1;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x00404610
// Name: public: int CUtlLinkedList<class CServiceInfo __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CServiceInfo __near *,int>,int>>::AddToTail(class CServiceInfo __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::AddToTail(
        CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int> > *this,
        CServiceInfo **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<CServiceInfo *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CServiceInfo *,int> *v8; // esi

  result = CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CServiceInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceInfo *,int>,int>>::Unlink(
      this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004060C0
// Name: void AnchorElement(long __near *,class CRect __near &,int,class CRect __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AnchorElement(int *pOut, CRect *rcParent, int startElement, CRect *rcParentStart, int flags)
{
  switch ( flags )
  {
    case 1:
      *pOut = startElement + rcParent->left - rcParentStart->left;
      break;
    case 3:
      *pOut = startElement + rcParent->top - rcParentStart->top;
      break;
    case 2:
      *pOut = startElement + rcParent->right - rcParentStart->right;
      break;
    case 4:
      *pOut = startElement + rcParent->bottom - rcParentStart->bottom;
      break;
    case 5:
      *pOut = rcParent->left
            + (startElement - rcParentStart->left)
            * (rcParent->right - rcParent->left)
            / (rcParentStart->right - rcParentStart->left);
      break;
    case 6:
      *pOut = rcParent->top
            + (startElement - rcParentStart->top)
            * (rcParent->bottom - rcParent->top)
            / (rcParentStart->bottom - rcParentStart->top);
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004061A0
// Name: public: void CWindowAnchor::Update(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWindowAnchor::Update(CWindowAnchor *this, CWnd *pParentWnd)
{
  HWND__ *m_hWnd; // edx
  int left; // [esp-10h] [ebp-38h]
  int m_aLeft; // [esp-8h] [ebp-30h]
  CRect rcParent; // [esp+8h] [ebp-20h] BYREF
  CRect rcNew; // [esp+18h] [ebp-10h] BYREF

  if ( this->m_pWnd != nullptr )
  {
    m_hWnd = pParentWnd->m_hWnd;
    memset(&rcParent, 0, sizeof(rcParent));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rcParent);
    m_aLeft = this->m_aLeft;
    left = this->m_Rect.left;
    memset(&rcNew, 0, sizeof(rcNew));
    AnchorElement(pOut: &rcNew.left, &rcParent, startElement: left, rcParentStart: &this->m_ParentRect, flags: m_aLeft);
    AnchorElement(
      pOut: &rcNew.top,
      &rcParent,
      startElement: this->m_Rect.top,
      rcParentStart: &this->m_ParentRect,
      flags: this->m_aTop);
    AnchorElement(
      pOut: &rcNew.right,
      &rcParent,
      startElement: this->m_Rect.right,
      rcParentStart: &this->m_ParentRect,
      flags: this->m_aRight);
    AnchorElement(
      pOut: &rcNew.bottom,
      &rcParent,
      startElement: this->m_Rect.bottom,
      rcParentStart: &this->m_ParentRect,
      flags: this->m_aBottom);
    CWnd::ScreenToClient(this: pParentWnd, lpRect: &rcNew);
    CWnd::SetWindowPos(
      this: this->m_pWnd,
      pWndInsertAfter: nullptr,
      x: rcNew.left,
      y: rcNew.top,
      cx: rcNew.right - rcNew.left,
      cy: rcNew.bottom - rcNew.top,
      nFlags: 4u);
    InvalidateRect(hWnd: this->m_pWnd->m_hWnd, lpRect: nullptr, bErase: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406280
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CWindowAnchor,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CWindowAnchor,int> *m_pMemory; // ecx

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
      this->m_pMemory = (UtlLinkedListElem_t<CWindowAnchor,int> *)realloc(
                                                                    pBlock: m_pMemory,
                                                                    newsize: 60 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CWindowAnchor,int> *)malloc(size: 60 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406320
// Name: protected: int CUtlLinkedList<class CWindowAnchor,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CWindowAnchor,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int>>::AllocInternal(
        CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CWindowAnchor,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00406450
// Name: public: void CWindowAnchorMgr::UpdateAnchors(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWindowAnchorMgr::UpdateAnchors(CWindowAnchorMgr *this, CWnd *pParentWnd)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CWindowAnchor,int> *m_pMemory; // ecx
  int v5; // esi

  m_Head = this->m_Anchors.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Anchors.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      CWindowAnchor::Update(this: &m_pMemory[m_Head].m_Element, pParentWnd);
      m_pMemory = this->m_Anchors.m_Memory.m_pMemory;
      m_Head = this->m_Anchors.m_Memory.m_pMemory[v5].m_Next;
    }
    while ( m_Head != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406490
// Name: public: void CUtlLinkedList<class CWindowAnchor,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CWindowAnchor,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int>>::Unlink(
        CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CWindowAnchor,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406520
// Name: public: int CUtlLinkedList<class CWindowAnchor,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CWindowAnchor,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int>>::AddToTail(
        CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<CWindowAnchor,int> *m_pMemory; // ecx
  unsigned int v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<CWindowAnchor,int> *v7; // esi

  result = CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int>>::Unlink(
      this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = v3;
    m_pMemory[v5].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = v3;
    if ( m_Tail == -1 )
      this->m_Head = v3;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v3;
    ++this->m_ElementCount;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( v7 != nullptr )
    {
      v7->m_Element.m_Rect.left = 0;
      v7->m_Element.m_Rect.top = 0;
      v7->m_Element.m_Rect.right = 0;
      v7->m_Element.m_Rect.bottom = 0;
      v7->m_Element.m_ParentRect.left = 0;
      v7->m_Element.m_ParentRect.top = 0;
      v7->m_Element.m_ParentRect.right = 0;
      v7->m_Element.m_ParentRect.bottom = 0;
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004065A0
// Name: public: bool CWindowAnchorMgr::AddAnchor(class CWnd __near *,class CWnd __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWindowAnchorMgr::AddAnchor(
        CWindowAnchorMgr *this,
        CWnd *pParentWnd,
        CWnd *pChildWnd,
        int aLeft,
        int aTop,
        int aRight,
        int aBottom)
{
  UtlLinkedListElem_t<CWindowAnchor,int> *v7; // esi

  v7 = &this->m_Anchors.m_Memory.m_pMemory[CUtlLinkedList<CWindowAnchor,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWindowAnchor,int>,int>>::AddToTail(this: &this->m_Anchors)];
  v7->m_Element.m_aLeft = aLeft;
  v7->m_Element.m_pWnd = pChildWnd;
  v7->m_Element.m_aTop = aTop;
  v7->m_Element.m_aRight = aRight;
  v7->m_Element.m_aBottom = aBottom;
  if ( pChildWnd == nullptr || pParentWnd == nullptr )
    return 0;
  GetWindowRect(hWnd: pParentWnd->m_hWnd, lpRect: &v7->m_Element.m_ParentRect);
  GetWindowRect(hWnd: pChildWnd->m_hWnd, lpRect: &v7->m_Element.m_Rect);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004F17F3
// Name: public: void CSmartDockingGroupGuidesWnd::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmartDockingGroupGuidesWnd::Update(CSmartDockingGroupGuidesWnd *this)
{
  HBITMAP v2; // eax
  HDC CompatibleDC; // eax
  CGdiObject *v4; // eax
  CSmartDockingGroupGuidesManager *m_pCentralGroup; // ecx
  void *m_hObject; // esi
  HWND__ *v7; // [esp-24h] [ebp-9Ch]
  HWND__ *m_hWnd; // [esp-8h] [ebp-80h]
  CClientDC v9; // [esp+10h] [ebp-68h] BYREF
  POINT pptSrc; // [esp+24h] [ebp-54h] BYREF
  CDC dc; // [esp+2Ch] [ebp-4Ch] BYREF
  CGdiObject *v12; // [esp+3Ch] [ebp-3Ch]
  void *pBits; // [esp+40h] [ebp-38h] BYREF
  CSize size; // [esp+44h] [ebp-34h] BYREF
  CGdiObject v15; // [esp+4Ch] [ebp-2Ch] BYREF
  BLENDFUNCTION pblend; // [esp+54h] [ebp-24h] BYREF
  tagRECT Rect; // [esp+58h] [ebp-20h] BYREF
  int v18; // [esp+74h] [ebp-4h]

  if ( CDockingManager::m_SDParams.m_bIsAlphaMarkers != 0 || GetVMTheme() == AFX_SDT_VS2008 )
  {
    m_hWnd = this->m_hWnd;
    memset((void *)&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
    size.cy = Rect.bottom - Rect.top;
    pptSrc.x = 0;
    pptSrc.y = 0;
    size.cx = Rect.right - Rect.left;
    pBits = nullptr;
    v2 = CDrawingManager::CreateBitmap_32(&size, &pBits);
    if ( v2 != nullptr )
    {
      v15.m_hObject = nullptr;
      v15.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
      v18 = 0;
      CGdiObject::Attach(this: &v15, hObject: v2);
      CClientDC::CClientDC(this: &v9, pWnd: this);
      LOBYTE(v18) = 1;
      CDC::CDC(this: &dc);
      LOBYTE(v18) = 2;
      CompatibleDC = CreateCompatibleDC(hdc: v9.m_hDC);
      CDC::Attach(this: &dc, hDC: CompatibleDC);
      v4 = CDC::SelectGdiObject(hDC: dc.m_hDC, h: v15.m_hObject);
      m_pCentralGroup = this->m_pCentralGroup;
      v12 = v4;
      CSmartDockingGroupGuidesManager::DrawCentralGroupGuides(
        this: m_pCentralGroup,
        &dc,
        brBaseBackground: &this->m_brBaseBackground,
        brBaseBorder: &this->m_brBaseBorder,
        rectClient: (CRect)Rect);
      m_hObject = nullptr;
      v7 = this->m_hWnd;
      pblend = (BLENDFUNCTION)33488896;
      UpdateLayeredWindow(
        hWnd: v7,
        hdcDst: nullptr,
        pptDst: nullptr,
        psize: &size,
        hdcSrc: dc.m_hDC,
        &pptSrc,
        crKey: 0,
        &pblend,
        dwFlags: 2u);
      if ( v12 != nullptr )
        m_hObject = v12->m_hObject;
      CDC::SelectGdiObject(hDC: dc.m_hDC, h: m_hObject);
      LOBYTE(v18) = 1;
      CDC::~CDC(this: &dc);
      LOBYTE(v18) = 0;
      CClientDC::~CClientDC(this: &v9);
      v18 = -1;
      v15.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
      CGdiObject::~CGdiObject(this: &v15);
    }
  }
  else
  {
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050024F
// Name: public: virtual void CMFCTasksPane::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::Update(CMFCTasksPane *this)
{
  CMFCTasksPane::UpdateCaption(this);
  CMFCTasksPane::AdjustScroll(this);
  this->ReposTasks(this, a2: 0);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x004F194F
// Name: public: void CSmartDockingGroupGuidesWnd::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingGroupGuidesWnd::OnPaint(CSmartDockingGroupGuidesWnd *this)
{
  CDC *p_m_dcMem; // eax
  HBRUSH SolidBrush; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-D4h]
  CGdiObject v5; // [esp+10h] [ebp-BCh] BYREF
  CDC *dc; // [esp+18h] [ebp-B4h]
  CPaintDC v7; // [esp+1Ch] [ebp-B0h] BYREF
  CMemDC v8; // [esp+70h] [ebp-5Ch] BYREF
  tagRECT Rect; // [esp+ACh] [ebp-20h] BYREF
  int v10; // [esp+C8h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v7, pWnd: this);
  v10 = 0;
  CMemDC::CMemDC(this: &v8, dc: &v7, pWnd: (HDC__ *)this);
  p_m_dcMem = &v8.m_dcMem;
  if ( v8.m_bMemDC == 0 )
    p_m_dcMem = v8.m_dc;
  dc = p_m_dcMem;
  m_hWnd = this->m_hWnd;
  memset((void *)&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  v5.m_hObject = nullptr;
  v5.__vftable = (CGdiObject_vtbl *)&CBrush::`vftable';
  LOBYTE(v10) = 2;
  SolidBrush = CreateSolidBrush(color: CDockingManager::m_SDParams.m_clrTransparent);
  CGdiObject::Attach(this: &v5, hObject: SolidBrush);
  FillRect(hDC: dc->m_hDC, lprc: &Rect, hbr: (HBRUSH)v5.m_hObject);
  CSmartDockingGroupGuidesManager::DrawCentralGroupGuides(
    this: this->m_pCentralGroup,
    dc,
    brBaseBackground: &this->m_brBaseBackground,
    brBaseBorder: &this->m_brBaseBorder,
    rectClient: (CRect)Rect);
  LOBYTE(v10) = 1;
  v5.__vftable = (CGdiObject_vtbl *)&CBrush::`vftable';
  CGdiObject::~CGdiObject(this: &v5);
  LOBYTE(v10) = 0;
  CMemDC::~CMemDC(this: &v8);
  v10 = -1;
  CPaintDC::~CPaintDC(this: &v7);
}

//------------------------------------------------------------------------------
// Address: 0x004F1A70
// Name: public: virtual void CSmartDockingGroupGuide::Highlight(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingGroupGuide::Highlight(CSmartDockingGroupGuide *this, int bHiLite)
{
  if ( this->m_bHiLited != bHiLite )
  {
    this->m_bHiLited = bHiLite;
    CSmartDockingGroupGuidesWnd::Update(this: &this->m_pCentralGroup->m_Wnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F1A98
// Name: public: void CSmartDockingGroupGuide::SetVisible(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingGroupGuide::SetVisible(CSmartDockingGroupGuide *this, int bVisible, int bRedraw)
{
  CSmartDockingGroupGuidesManager *m_pCentralGroup; // ecx

  this->m_bVisible = bVisible;
  if ( bRedraw != 0 )
  {
    m_pCentralGroup = this->m_pCentralGroup;
    if ( m_pCentralGroup != nullptr )
      CSmartDockingGroupGuidesWnd::Update(this: &m_pCentralGroup->m_Wnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F1AE3
// Name: public: virtual int CSmartDockingGroupGuidesManager::AdjustPos(class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSmartDockingGroupGuidesManager::AdjustPos(
        CSmartDockingGroupGuidesManager *this,
        CRect rcHost,
        int nMiddleIsOn)
{
  CSmartDockingGroupGuidesWnd *p_m_Wnd; // ecx
  int v5; // esi
  int v6; // edi
  CWnd *v8; // [esp+Ch] [ebp-28h]
  CRect rcCurrentPos; // [esp+10h] [ebp-24h] BYREF
  CRect rcWnd; // [esp+20h] [ebp-14h] BYREF

  p_m_Wnd = &this->m_Wnd;
  memset(&rcWnd, 0, sizeof(rcWnd));
  v8 = p_m_Wnd;
  if ( p_m_Wnd == nullptr || p_m_Wnd->m_hWnd == nullptr )
    return 0;
  if ( nMiddleIsOn != -1 )
  {
    if ( nMiddleIsOn != 0 )
    {
      if ( nMiddleIsOn == 1 && this->m_bMiddleIsOn == 0 )
      {
        this->m_bMiddleIsOn = 1;
        goto LABEL_10;
      }
    }
    else if ( this->m_bMiddleIsOn != 0 )
    {
      this->m_bMiddleIsOn = 0;
LABEL_10:
      CSmartDockingGroupGuidesWnd::Update(this: p_m_Wnd);
    }
  }
  GetClientRect(hWnd: this->m_Wnd.m_hWnd, lpRect: &rcWnd);
  memset(&rcCurrentPos, 0, sizeof(rcCurrentPos));
  v5 = (rcHost.right + rcHost.left + rcWnd.left - rcWnd.right) >> 1;
  v6 = (rcHost.bottom + rcHost.top + rcWnd.top - rcWnd.bottom) >> 1;
  GetWindowRect(hWnd: this->m_Wnd.m_hWnd, lpRect: &rcCurrentPos);
  if ( rcCurrentPos.left != v5 || rcCurrentPos.top != v6 )
  {
    CWnd::SetWindowPos(this: v8, pWndInsertAfter: &CWnd::wndTopMost, x: v5, y: v6, cx: -1, cy: -1, nFlags: 1u);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004F1BD0
// Name: public: void CSmartDockingGroupGuidesManager::ShowGuide(enum CSmartDockingStandaloneGuide::SDMarkerPlace,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingGroupGuidesManager::ShowGuide(
        CSmartDockingGroupGuidesManager *this,
        CSmartDockingStandaloneGuide::SDMarkerPlace nMarkerNo,
        int bShow,
        int bRedraw)
{
  CSmartDockingGroupGuide *v4; // eax

  v4 = this->GetGuide(this, a2: nMarkerNo);
  if ( v4 != nullptr && v4->m_bVisible != bShow )
    CSmartDockingGroupGuide::SetVisible(this: v4, bVisible: bShow, bRedraw);
}

//------------------------------------------------------------------------------
// Address: 0x004F1BFB
// Name: public: void CSmartDockingStandaloneGuideWnd::Highlight(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingStandaloneGuideWnd::Highlight(CSmartDockingStandaloneGuideWnd *this, int bSet)
{
  HWND__ *m_hWnd; // eax

  this->m_bIsHighlighted = bSet;
  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
  {
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
    CSmartDockingStandaloneGuideWnd::UpdateLayered(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F1C2F
// Name: char const __near * GetSmartDockingWndClassName<2080>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl GetSmartDockingWndClassName<2080>()
{
  CAfxStringMgr *StringManager; // eax
  char *v1; // eax

  if ( (`GetSmartDockingWndClassName<2080>'::`2'::`local static guard' & 1) == 0 )
  {
    `GetSmartDockingWndClassName<2080>'::`2'::`local static guard' |= 1u;
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
      this: &`GetSmartDockingWndClassName<2080>'::`2'::strSDWndClassName,
      pStringMgr: StringManager);
    atexit(func: GetSmartDockingWndClassName_2080__::_2_::_dynamic_atexit_destructor_for__strSDWndClassName__);
  }
  if ( *((_DWORD *)`GetSmartDockingWndClassName<2080>'::`2'::strSDWndClassName.m_pszData - 3) == 0 )
  {
    v1 = AfxRegisterWndClass(nClassStyle: 0x820u, hCursor: nullptr, hbrBackground: nullptr, hIcon: nullptr);
    ATL::CSimpleStringT<char,0>::SetString(
      this: &`GetSmartDockingWndClassName<2080>'::`2'::strSDWndClassName,
      pszSrc: v1);
  }
  return `GetSmartDockingWndClassName<2080>'::`2'::strSDWndClassName.m_pszData;
}

//------------------------------------------------------------------------------
// Address: 0x004F1C86
// Name: public: virtual void CSmartDockingStandaloneGuide::Highlight(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingStandaloneGuide::Highlight(CSmartDockingStandaloneGuide *this, int bHiLite)
{
  CSmartDockingStandaloneGuideWnd *p_m_wndBmp; // ecx
  HBITMAP__ *m_hbmImageLight; // eax

  p_m_wndBmp = &this->m_wndBmp;
  if ( this->m_bHiLited == bHiLite )
  {
    CSmartDockingStandaloneGuideWnd::UpdateLayered(this: p_m_wndBmp);
  }
  else
  {
    this->m_bHiLited = bHiLite;
    CSmartDockingStandaloneGuideWnd::Highlight(this: p_m_wndBmp, bSet: bHiLite);
    if ( this->m_bIsDefaultImage == 0 || GetVMTheme() == AFX_SDT_VS2008 )
    {
      m_hbmImageLight = this->m_Image.m_hbmImageLight;
      if ( m_hbmImageLight == nullptr )
        m_hbmImageLight = this->m_Image.m_hbmImageWell;
      if ( bHiLite != 0 )
      {
        m_hbmImageLight = this->m_ImageHot.m_hbmImageWell;
        if ( m_hbmImageLight == nullptr )
          m_hbmImageLight = this->m_Image.m_hbmImageWell;
      }
      CSmartDockingStandaloneGuideWnd::Assign(this: &this->m_wndBmp, hbmpFace: m_hbmImageLight, bRedraw: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00500280
// Name: public: CMFCTasksPanePropertyPage::CMFCTasksPanePropertyPage(char const __near *,class CMFCTasksPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTasksPanePropertyPage *__thiscall CMFCTasksPanePropertyPage::CMFCTasksPanePropertyPage(
        CMFCTasksPanePropertyPage *this,
        const char *lpszName,
        CMFCTasksPane *pTaskPane)
{
  CAfxStringMgr *StringManager; // eax

  this->__vftable = (CMFCTasksPanePropertyPage_vtbl *)&CMFCTasksPanePropertyPage::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strName, pStringMgr: StringManager);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strName, pszSrc: lpszName);
  this->m_pTaskPane = pTaskPane;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005002C4
// Name: public: virtual CMFCTasksPanePropertyPage::~CMFCTasksPanePropertyPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPanePropertyPage::~CMFCTasksPanePropertyPage(CMFCTasksPanePropertyPage *this)
{
  this->m_pTaskPane = nullptr;
  this->__vftable = (CMFCTasksPanePropertyPage_vtbl *)&CMFCTasksPanePropertyPage::`vftable';
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x005002FA
// Name: public: CTasksPaneHistoryButton::CTasksPaneHistoryButton(unsigned int,int,char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTasksPaneHistoryButton *__thiscall CTasksPaneHistoryButton::CTasksPaneHistoryButton(
        CTasksPaneHistoryButton *this,
        unsigned int uiID,
        int iImage,
        const char *lpszText,
        int bUserButton)
{
  const char *v6; // eax
  HMENU PopupMenu; // eax
  CMenu menu; // [esp+10h] [ebp-18h] BYREF
  CTasksPaneHistoryButton *v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+24h] [ebp-4h]

  v10 = this;
  CMFCToolBarMenuButton::CMFCToolBarMenuButton(this);
  v11 = 0;
  this->__vftable = (CTasksPaneHistoryButton_vtbl *)&CTasksPaneHistoryButton::`vftable';
  CStringList::CStringList(this: &this->m_lstPages, nBlockSize: 10);
  this->m_nID = uiID;
  LOBYTE(v11) = 1;
  this->m_bUserButton = bUserButton;
  CMFCToolBarButton::SetImage(this, iImage);
  v6 = lpszText;
  if ( lpszText == nullptr )
    v6 = szGroupName;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strText, pszSrc: v6);
  menu.m_hMenu = nullptr;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  LOBYTE(v11) = 2;
  PopupMenu = CreatePopupMenu();
  CMenu::Attach(this: &menu, hMenu: PopupMenu);
  CMFCToolBarMenuButton::CreateFromMenu(this, hMenu: menu.m_hMenu);
  this->m_pParentBar = nullptr;
  LOBYTE(v11) = 1;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050039F
// Name: public: static class CObject __near * CMFCTasksPane::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTasksPane *__stdcall CMFCTasksPane::CreateObject()
{
  CMFCTasksPane *v0; // ecx
  CMFCTasksPane *result; // eax

  v0 = (CMFCTasksPane *)operator new(nSize: 0x11F4u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCTasksPane::CMFCTasksPane(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005003F0
// Name: public: int CMFCTasksPane::AddPage(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPane::AddPage(CMFCTasksPane *this, const char *lpszPageLabel)
{
  CMFCTasksPanePropertyPage *v3; // ecx
  CMFCTasksPanePropertyPage *v4; // eax

  if ( lpszPageLabel == nullptr )
    AfxThrowInvalidArgException();
  v3 = (CMFCTasksPanePropertyPage *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = CMFCTasksPanePropertyPage::CMFCTasksPanePropertyPage(this: v3, lpszName: lpszPageLabel, pTaskPane: this);
  else
    v4 = nullptr;
  CPtrList::AddTail(this: &this->m_lstTasksPanes, newElement: v4);
  CMFCTasksPane::RebuildMenu(this);
  return this->m_lstTasksPanes.m_nCount - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00500457
// Name: protected: virtual int CMFCTasksPane::GetMRUFileName(class CRecentFileList __near *,int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPane::GetMRUFileName(
        CMFCTasksPane *this,
        CRecentFileList *pRecentFileList,
        int nIndex,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strName)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v4; // eax
  CHAR lpcszBuffer[516]; // [esp+Ch] [ebp-208h] BYREF

  if ( pRecentFileList == nullptr )
    AfxThrowInvalidArgException();
  if ( *((_DWORD *)CRecentFileList::operator[](this: pRecentFileList, nIndex)->m_pszData - 3) == 0 )
    return 0;
  memset(dst: (int)lpcszBuffer, value: nullptr, count: 0x200u);
  v4 = CRecentFileList::operator[](this: pRecentFileList, nIndex);
  if ( GetFileTitleA(a1: v4->m_pszData, Buf: lpcszBuffer, cchSize: 0x200u) != 0 )
    return 0;
  ATL::CSimpleStringT<char,0>::SetString(this: strName, pszSrc: lpcszBuffer);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005004F6
// Name: protected: void CMFCTasksPane::ChangeActivePage(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CMFCTasksPane::ChangeActivePage(
        CMFCTasksPane *this@<ecx>,
        int a2@<ebx>,
        CMFCTasksPanePropertyPage *nNewPageHistoryIdx,
        int nOldPageHistoryIdx)
{
  int m_nSize; // eax
  int *m_pData; // edi
  int v7; // ecx
  __POSITION *Index; // eax
  CObList::CNode *m_pNodeHead; // ebx
  CObject *data; // eax
  CObject_vtbl *v11; // edi
  HWND__ *v12; // eax
  CWnd *v13; // eax
  CMFCTasksPanePropertyPage *pOldPage; // [esp+10h] [ebp+8h]

  if ( (int)nNewPageHistoryIdx < 0 )
    goto LABEL_10;
  m_nSize = this->m_arrHistoryStack.m_nSize;
  if ( (int)nNewPageHistoryIdx >= m_nSize || nOldPageHistoryIdx < 0 || nOldPageHistoryIdx >= m_nSize )
    goto LABEL_10;
  m_pData = this->m_arrHistoryStack.m_pData;
  v7 = m_pData[nOldPageHistoryIdx];
  if ( m_pData[(_DWORD)nNewPageHistoryIdx] == v7 )
    return;
  if ( this == nullptr || this->m_hWnd == nullptr )
  {
    this->OnActivateTasksPanePage(this);
    CMFCTasksPane::RebuildMenu(this);
    return;
  }
  Index = CStringList::FindIndex(this: (CList<unsigned long,unsigned long> *)&this->m_lstTasksPanes, nIndex: v7);
  if ( Index == nullptr )
LABEL_10:
    AfxThrowInvalidArgException();
  m_pNodeHead = this->m_lstTaskGroups.m_pNodeHead;
  pOldPage = *(CMFCTasksPanePropertyPage **)&Index[8];
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( (CMFCTasksPanePropertyPage *)data[1].__vftable == pOldPage )
    {
      v11 = data[4].__vftable;
      while ( v11 != nullptr )
      {
        v12 = *((HWND__ **)v11->Serialize + 11);
        v11 = (CObject_vtbl *)v11->GetRuntimeClass;
        if ( v12 != nullptr )
        {
          v13 = CWnd::FromHandle(hWnd: v12);
          CWnd::ShowWindow(this: v13, nCmdShow: 0);
        }
      }
    }
  }
  CMFCTasksPane::UpdateCaption(this);
  ((void (__thiscall *)(CMFCTasksPane *, int))this->OnActivateTasksPanePage)(a1: this, a2);
  CMFCTasksPane::RebuildMenu(this);
  this->m_nVertScrollOffset = 0;
  CMFCTasksPane::AdjustScroll(this);
  ((void (__thiscall *)(CMFCTasksPane *))this->ReposTasks)(a1: this);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x005005FE
// Name: public: void CMFCTasksPane::SetActivePage(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CMFCTasksPane::SetActivePage(CMFCTasksPane *this@<ecx>, int a2@<ebx>, unsigned int nPageIdx)
{
  CMFCTasksPanePropertyPage *v4; // ecx
  int m_iActivePage; // [esp-4h] [ebp-8h]

  if ( CMFCTasksPane::GetActivePage(this) != nPageIdx )
  {
    CMFCTasksPane::SaveHistory(this, nPageIdx);
    v4 = (CMFCTasksPanePropertyPage *)(this->m_arrHistoryStack.m_nSize - 1);
    m_iActivePage = this->m_iActivePage;
    this->m_iActivePage = (int)v4;
    CMFCTasksPane::ChangeActivePage(this, a2, nNewPageHistoryIdx: v4, nOldPageHistoryIdx: m_iActivePage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050063B
// Name: public: virtual void CMFCTasksPane::OnPressBackButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CMFCTasksPane::OnPressBackButton(CMFCTasksPane *this@<ecx>, int a2@<ebx>)
{
  int m_iActivePage; // esi
  int v3; // [esp-4h] [ebp-8h]

  m_iActivePage = this->m_iActivePage;
  if ( m_iActivePage > 0 )
  {
    v3 = this->m_iActivePage;
    this->m_iActivePage = m_iActivePage - 1;
    CMFCTasksPane::ChangeActivePage(
      this,
      a2,
      nNewPageHistoryIdx: (CMFCTasksPanePropertyPage *)(m_iActivePage - 1),
      nOldPageHistoryIdx: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050065A
// Name: public: virtual void CMFCTasksPane::OnPressForwardButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CMFCTasksPane::OnPressForwardButton(CMFCTasksPane *this@<ecx>, int a2@<ebx>)
{
  int m_iActivePage; // esi
  int v3; // [esp-4h] [ebp-8h]

  m_iActivePage = this->m_iActivePage;
  if ( m_iActivePage < this->m_arrHistoryStack.m_nSize - 1 )
  {
    v3 = this->m_iActivePage;
    this->m_iActivePage = m_iActivePage + 1;
    CMFCTasksPane::ChangeActivePage(
      this,
      a2,
      nNewPageHistoryIdx: (CMFCTasksPanePropertyPage *)(m_iActivePage + 1),
      nOldPageHistoryIdx: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050067E
// Name: public: virtual void CMFCTasksPane::OnPressHomeButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CMFCTasksPane::OnPressHomeButton(CMFCTasksPane *this@<ecx>, int a2@<ebx>)
{
  if ( CMFCTasksPane::GetActivePage(this) != 0 )
    CMFCTasksPane::SetActivePage(this, a2, nPageIdx: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00500697
// Name: public: virtual void CMFCTasksPane::OnPressOtherButton(class CMFCCaptionMenuButton __near *,class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CMFCTasksPane::OnPressOtherButton(
        CMFCTasksPane *this@<ecx>,
        int a2@<ebx>,
        CMFCCaptionMenuButton *pbtn,
        CWnd *pWndOwner)
{
  HMENU__ *p_m_menuOther; // eax

  if ( pbtn != nullptr )
  {
    p_m_menuOther = (HMENU__ *)&this->m_menuOther;
    if ( this != (CMFCTasksPane *)-1084 )
      p_m_menuOther = this->m_menuOther.m_hMenu;
    CMFCCaptionMenuButton::ShowMenu(this: pbtn, hMenu: p_m_menuOther, pWndOwner);
    if ( pbtn->m_nMenuResult != 0 && CMFCPopupMenuBar::m_nLastCommandIndex >= 0 )
      CMFCTasksPane::SetActivePage(this, a2, nPageIdx: CMFCPopupMenuBar::m_nLastCommandIndex);
  }
}
