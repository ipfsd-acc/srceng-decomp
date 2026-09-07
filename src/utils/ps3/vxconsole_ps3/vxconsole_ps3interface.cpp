// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/vxconsole_ps3interface.cpp
// Functions: 158
// ============================================================

#include "utils\ps3\vxconsole_ps3\vxconsole_ps3interface.h"

//------------------------------------------------------------------------------
// Address: 0x00403010
// Name: bool ExcludePathsDlg_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExcludePathsDlg_Init()
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406140
// Name: public: void CUtlMemory<struct xrProfile_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<xrProfile_t,int>::Grow(CUtlMemory<xrProfile_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  xrProfile_t *m_pMemory; // edx

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
      this->m_pMemory = (xrProfile_t *)_g_pMemAlloc->Realloc_2(
                                         this: _g_pMemAlloc,
                                         a2: m_pMemory,
                                         a3: 68 * m_nAllocationCount);
    else
      this->m_pMemory = (xrProfile_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 68 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406340
// Name: public: int CUtlVector<struct xrProfile_t,class CUtlMemory<struct xrProfile_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<xrProfile_t,CUtlMemory<xrProfile_t,int>>::InsertMultipleBefore(
        CUtlVector<xrProfile_t,CUtlMemory<xrProfile_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  xrProfile_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<xrProfile_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 68 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004066F0
// Name: public: void CUtlLinkedList<struct ps3FileInfo_t,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::RemoveAll(
        CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int> > *this)
{
  unsigned int m_Head; // edx
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *v2; // esi
  unsigned int m_Next; // eax
  unsigned int m_FirstFree; // edx
  unsigned int v5; // eax

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
// Address: 0x00406C00
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct ps3FileInfo_t,unsigned int>,unsigned int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *m_pMemory; // edx
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
    v7 = 400 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *)_g_pMemAlloc->Realloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: m_pMemory,
                                                                             a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *)_g_pMemAlloc->Alloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406CA0
// Name: protected: unsigned int CUtlLinkedList<struct ps3FileInfo_t,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct ps3FileInfo_t,unsigned int>,unsigned int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
signed int __thiscall CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::AllocInternal(
        CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int> > *this,
        bool multilist)
{
  unsigned int m_FirstFree; // ecx
  signed int index; // eax
  int m_nAllocationCount; // ecx
  signed int result; // eax
  signed int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *m_pMemory; // ecx
  unsigned int v10; // edx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = result;
    if ( multilist )
    {
      m_pMemory[v10].m_Next = -1;
      m_pMemory[v10].m_Previous = -1;
    }
    else
    {
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
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
    CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x00406DE0
// Name: public: CUtlVector<struct CUtlSymbolTable::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTable::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTable::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTable::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406E50
// Name: public: void CUtlLinkedList<struct ps3FileInfo_t,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct ps3FileInfo_t,unsigned int>,unsigned int>>::Unlink(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::Unlink(
        CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int> > *this,
        int elem)
{
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *v2; // eax
  unsigned int m_Next; // edx
  unsigned int m_Previous; // ebx

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
        this->m_Tail = v2->m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
      --this->m_ElementCount;
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406EE0
// Name: public: unsigned int CUtlLinkedList<struct ps3FileInfo_t,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct ps3FileInfo_t,unsigned int>,unsigned int>>::AddToTail(struct ps3FileInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
signed int __thiscall CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::AddToTail(
        CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int> > *this,
        const ps3FileInfo_t *src)
{
  signed int result; // eax
  unsigned int v4; // ebx
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *m_pMemory; // eax
  unsigned int v6; // edx
  unsigned int m_Tail; // ecx
  UtlLinkedListElem_t<ps3FileInfo_t,unsigned int> *v8; // edi

  result = CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<ps3FileInfo_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<ps3FileInfo_t,unsigned int>,unsigned int>>::Unlink(
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
      qmemcpy(v8, src, 0x188u);
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407690
// Name: public: long CPS3TargetConnection::ConnectTo(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::ConnectTo(CPS3TargetConnection *this, int idx)
{
  int InternalTargetIndexForHandle; // eax
  int targ; // [esp+4h] [ebp-4h] BYREF

  if ( CPS3TargetList::GetInternalTargetIndexForHandle(this: &g_PS3TargetList, targ: &idx) == -1 )
    return -21;
  targ = idx;
  InternalTargetIndexForHandle = CPS3TargetList::GetInternalTargetIndexForHandle(this: &g_PS3TargetList, &targ);
  if ( InternalTargetIndexForHandle == -1 )
    return CPS3TargetConnection::ConnectTo(this, target: &CPS3TargetList::s_theInvalidTargetInfo);
  else
    return CPS3TargetConnection::ConnectTo(
             this,
             target: &g_PS3TargetList.m_Targets.m_Memory.m_pMemory[InternalTargetIndexForHandle]);
}

//------------------------------------------------------------------------------
// Address: 0x00407BA0
// Name: public: void CUtlLinkedList<unsigned long (*)(class CUtlString const __near &),unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned long (*)(class CUtlString const __near &),unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<unsigned long (__stdcall*)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B1F0
// Name: public: void CUtlMemory<struct xrMaterial_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<xrMaterial_t,int>::Grow(CUtlMemory<xrMaterial_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  xrMaterial_t *m_pMemory; // edx
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
    v7 = 516 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (xrMaterial_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (xrMaterial_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B290
// Name: public: void CUtlVector<struct xrMaterial_t,class CUtlMemory<struct xrMaterial_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<xrMaterial_t,CUtlMemory<xrMaterial_t,int>>::EnsureCapacity(
        CUtlVector<xrMaterial_t,CUtlMemory<xrMaterial_t,int> > *this,
        int num)
{
  xrMaterial_t *m_pMemory; // edx
  unsigned int v4; // eax
  xrMaterial_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 516 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (xrMaterial_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (xrMaterial_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B2F0
// Name: public: int CUtlVector<struct xrMaterial_t,class CUtlMemory<struct xrMaterial_t,int>>::InsertMultipleBefore(int,int,struct xrMaterial_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<xrMaterial_t,CUtlMemory<xrMaterial_t,int>>::InsertMultipleBefore(
        CUtlVector<xrMaterial_t,CUtlMemory<xrMaterial_t,int> > *this,
        int elem,
        int num,
        const xrMaterial_t *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  xrMaterial_t *m_pMemory; // ecx
  int v9; // edi
  int v10; // eax
  const xrMaterial_t *v11; // edx
  int v12; // eax
  xrMaterial_t *v13; // edi

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<xrMaterial_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 516 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v12 = elem;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
        qmemcpy(v13, v11, sizeof(xrMaterial_t));
      ++v12;
      ++v11;
      --num;
    }
    while ( num != 0 );
    return elem;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x0040E060
// Name: public: void CUtlMemory<struct xrModel_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<xrModel_t,int>::Grow(CUtlMemory<xrModel_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  xrModel_t *m_pMemory; // edx
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
    v7 = 296 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (xrModel_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (xrModel_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E100
// Name: public: void CUtlVector<struct xrModel_t,class CUtlMemory<struct xrModel_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int>>::EnsureCapacity(
        CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int> > *this,
        int num)
{
  xrModel_t *m_pMemory; // edx
  unsigned int v4; // eax
  xrModel_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 296 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (xrModel_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (xrModel_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E160
// Name: public: int CUtlVector<struct xrModel_t,class CUtlMemory<struct xrModel_t,int>>::InsertMultipleBefore(int,int,struct xrModel_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int>>::InsertMultipleBefore(
        CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int> > *this,
        int elem,
        int num,
        const xrModel_t *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  xrModel_t *m_pMemory; // ecx
  int v9; // edi
  int v10; // eax
  const xrModel_t *v11; // edx
  int v12; // eax
  xrModel_t *v13; // edi

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<xrModel_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 296 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v12 = elem;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
        qmemcpy(v13, v11, sizeof(xrModel_t));
      ++v12;
      ++v11;
      --num;
    }
    while ( num != 0 );
    return elem;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x0040F180
// Name: public: void CUtlMemory<struct xrSound_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<xrSound_t,int>::Grow(CUtlMemory<xrSound_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  xrSound_t *m_pMemory; // edx
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
    v7 = 352 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (xrSound_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (xrSound_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F220
// Name: public: void CUtlVector<struct xrSound_t,class CUtlMemory<struct xrSound_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int>>::EnsureCapacity(
        CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int> > *this,
        int num)
{
  xrSound_t *m_pMemory; // edx
  unsigned int v4; // eax
  xrSound_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 352 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (xrSound_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (xrSound_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F280
// Name: public: int CUtlVector<struct xrSound_t,class CUtlMemory<struct xrSound_t,int>>::InsertMultipleBefore(int,int,struct xrSound_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int>>::InsertMultipleBefore(
        CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int> > *this,
        int elem,
        int num,
        const xrSound_t *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  xrSound_t *m_pMemory; // ecx
  int v9; // edi
  int v10; // eax
  const xrSound_t *v11; // edx
  int v12; // eax
  xrSound_t *v13; // edi

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<xrSound_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 352 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v12 = elem;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
        qmemcpy(v13, v11, sizeof(xrSound_t));
      ++v12;
      ++v11;
      --num;
    }
    while ( num != 0 );
    return elem;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00410EF0
// Name: public: void CUtlMemory<struct dvdimage_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<dvdimage_t,int>::Grow(CUtlMemory<dvdimage_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  dvdimage_t *m_pMemory; // edx
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
    v7 = 308 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (dvdimage_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (dvdimage_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410F90
// Name: public: void CUtlMemory<struct SNPS3Transfer,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SNPS3Transfer,int>::Grow(CUtlMemory<SNPS3Transfer,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SNPS3Transfer *m_pMemory; // edx
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
    v7 = 1344 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (SNPS3Transfer *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (SNPS3Transfer *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004111C0
// Name: public: void CUtlMemory<struct _WIN32_FIND_DATAA,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<_WIN32_FIND_DATAA,int>::Grow(CUtlMemory<_WIN32_FIND_DATAA,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  _WIN32_FIND_DATAA *m_pMemory; // edx
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
    v7 = 320 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (_WIN32_FIND_DATAA *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (_WIN32_FIND_DATAA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411260
// Name: public: int CUtlVector<struct SNPS3Transfer,class CUtlMemory<struct SNPS3Transfer,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<SNPS3Transfer,CUtlMemory<SNPS3Transfer,int>>::InsertMultipleBefore(
        CUtlVector<SNPS3Transfer,CUtlMemory<SNPS3Transfer,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  SNPS3Transfer *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<SNPS3Transfer,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 1344 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004113F0
// Name: public: int CUtlVector<struct _WIN32_FIND_DATAA,class CUtlMemory<struct _WIN32_FIND_DATAA,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<_WIN32_FIND_DATAA,CUtlMemory<_WIN32_FIND_DATAA,int>>::InsertMultipleBefore(
        CUtlVector<_WIN32_FIND_DATAA,CUtlMemory<_WIN32_FIND_DATAA,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  _WIN32_FIND_DATAA *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<_WIN32_FIND_DATAA,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 320 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00411470
// Name: public: int CUtlVector<struct dvdimage_t,class CUtlMemory<struct dvdimage_t,int>>::InsertBefore(int,struct dvdimage_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::InsertBefore(
        CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *this,
        int elem,
        const dvdimage_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dvdimage_t *m_pMemory; // ecx
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<dvdimage_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 308 * v7);
  CopyConstruct<dvdimage_t>(pMemory: &this->m_Memory.m_pMemory[elem], src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004118C0
// Name: public: void CUtlVector<struct dvdimage_t,class CUtlMemory<struct dvdimage_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::RemoveAll(
        CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *this)
{
  int v2; // esi
  int v3; // edi

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      dvdimage_t::~dvdimage_t(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004118F0
// Name: public: void CUtlVector<struct dvdimage_t,class CUtlMemory<struct dvdimage_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Purge(
        CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  dvdimage_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      dvdimage_t::~dvdimage_t(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411950
// Name: public: void CUtlVector<struct dvdimage_t,class CUtlMemory<struct dvdimage_t,int>>::Sort(int (*)(struct dvdimage_t const __near *,struct dvdimage_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Sort(
        CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *v2; // edi
  signed int m_Size; // eax
  dvdimage_t *m_pMemory; // ecx
  int v5; // ebx
  int v6; // esi
  unsigned __int8 *v7; // ebx
  CUtlString *v8; // edi
  unsigned __int8 *v9; // esi
  unsigned __int8 *v10; // eax
  int j; // ecx
  bool v12; // zf
  dvdimage_t src; // [esp+4h] [ebp-150h] BYREF
  CUtlString *v14; // [esp+138h] [ebp-1Ch]
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *v15; // [esp+13Ch] [ebp-18h]
  unsigned __int8 *dst; // [esp+140h] [ebp-14h]
  int v17; // [esp+144h] [ebp-10h]
  int i; // [esp+148h] [ebp-Ch]
  int v19; // [esp+14Ch] [ebp-8h]
  CUtlString *v20; // [esp+150h] [ebp-4h]

  v2 = this;
  m_Size = this->m_Size;
  v15 = this;
  if ( m_Size > 1 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( v2->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: m_pMemory, num: m_Size, width: 0x134u, comp: pfnCompare);
    }
    else
    {
      v5 = m_Size - 1;
      i = m_Size - 1;
      do
      {
        if ( v5 >= 1 )
        {
          v6 = 308;
          v17 = 308;
          v19 = v5;
          do
          {
            if ( pfnCompare(a1: &v2->m_Memory.m_pMemory[-1].szString[v6], a2: &v2->m_Memory.m_pMemory->szString[v6]) < 0 )
            {
              dst = (unsigned __int8 *)&v2->m_Memory.m_pMemory->szString[v6];
              v7 = dst - 308;
              qmemcpy(&src, dst - 308, 0x104u);
              v8 = (CUtlString *)(dst - 48);
              CUtlString::CUtlString(this: &src.installPath, string: v8);
              v20 = (CUtlString *)(v7 + 276);
              CUtlString::CUtlString(this: &src.versionDetailString, string: (const CUtlString *)(v7 + 276));
              v14 = (CUtlString *)(v7 + 292);
              CUtlString::CUtlString(this: &src.notesString, string: (const CUtlString *)(v7 + 292));
              v9 = dst;
              v10 = (unsigned __int8 *)(dst - v7);
              for ( j = 260; j != 0; --j )
              {
                *v7 = v7[(_DWORD)v10];
                ++v7;
              }
              CUtlString::operator=(this: v8, src: (const CUtlString *)(v9 + 260));
              CUtlString::operator=(this: v20, src: (const CUtlString *)(v9 + 276));
              v20 = (CUtlString *)(v9 + 292);
              CUtlString::operator=(this: v14, src: (const CUtlString *)(v9 + 292));
              memcpy(dst: v9, (unsigned __int8 *)&src, count: 0x104u);
              CUtlString::operator=(this: (CUtlString *)(v9 + 260), src: &src.installPath);
              CUtlString::operator=(this: (CUtlString *)(v9 + 276), src: &src.versionDetailString);
              CUtlString::operator=(this: v20, src: &src.notesString);
              dvdimage_t::~dvdimage_t(this: &src);
              v2 = v15;
              v5 = i;
              v6 = v17;
            }
            v6 += 308;
            v12 = v19-- == 1;
            v17 = v6;
          }
          while ( !v12 );
        }
        i = --v5;
      }
      while ( v5 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415760
// Name: public: void CUtlMemory<unsigned int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned int,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417E80
// Name: void ExcludePathsDlg_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExcludePathsDlg_Open()
{
  MessageBoxA(hWnd: g_hDlgMain, lpText: "Exclude paths not yet implemented.", lpCaption: "Oops!", uType: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00417EA0
// Name: public: long CPS3TargetConnection::RebootCold(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::RebootCold(CPS3TargetConnection *this)
{
  return SNPS3Reset(a1: this->m_nSNHandle, a2: 1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00417EC0
// Name: public: void CPS3TargetConnection::BlabberAboutConnectedTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPS3TargetConnection::BlabberAboutConnectedTarget(CPS3TargetConnection *this)
{
  const char *v2; // eax
  unsigned int v3; // edi
  _BYTE *v4; // esi
  int m_nSNHandle; // [esp-Ch] [ebp-881Ch]
  _BYTE v6[34816]; // [esp+8h] [ebp-8808h] BYREF
  int v7; // [esp+8808h] [ebp-8h] BYREF
  unsigned int v8; // [esp+880Ch] [ebp-4h] BYREF

  if ( SNPS3GetConnectStatus(a1: this->m_nSNHandle, a2: &v7, a3: &v8) < 0 )
  {
    __debugbreak();
  }
  else
  {
    v2 = (const char *)v8;
    if ( v8 == 0 )
      v2 = "{0}";
    ConsoleWindowPrintf(rgb: 0, strFormat: "SNPS3GetConnectStatus: %x .. %s\n", v7, v2);
  }
  m_nSNHandle = this->m_nSNHandle;
  v8 = 512;
  SNPS3ListTTYStreams(a1: m_nSNHandle, a2: &v8, a3: v6);
  ConsoleWindowPrintf(rgb: 0, strFormat: "SNPS3ListTTYStreams: \n");
  v3 = 0;
  if ( v8 != 0 )
  {
    v4 = v6;
    do
    {
      ConsoleWindowPrintf(rgb: 0, strFormat: "\t%d %s\n", *(_DWORD *)v4, v4 + 4);
      ++v3;
      v4 += 68;
    }
    while ( v3 < v8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417F70
// Name: public: unsigned int CPS3TargetConnection::GetDebugIPAddr(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPS3TargetConnection::GetDebugIPAddr(CPS3TargetConnection *this)
{
  int GamePortDebugIPAddrData; // eax
  SNPS3GamePortIPAddressData data; // [esp+0h] [ebp-10h] BYREF

  GamePortDebugIPAddrData = SNPS3GetGamePortDebugIPAddrData(a1: this->m_nSNHandle, a2: 0, a3: &data);
  return GamePortDebugIPAddrData == 0 ? data.uIPAddress : 0;
}

//------------------------------------------------------------------------------
// Address: 0x00417FA0
// Name: public: long CPS3TargetConnection::DeleteFileA(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::DeleteFileA(
        CPS3TargetConnection *this,
        const char *pszFileName,
        bool fIsDirectory)
{
  return SNPS3Delete(a1: this->m_nSNHandle, a2: pszFileName);
}

//------------------------------------------------------------------------------
// Address: 0x00417FC0
// Name: private: long CPS3TargetConnection::UnregisterInternalEventHandlers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::UnregisterInternalEventHandlers(CPS3TargetConnection *this)
{
  int result; // eax

  this->m_nResultOfRegisteringTTYHandler = SNPS3CancelTTYEvents(a1: this->m_nSNHandle, a2: -1);
  if ( this->m_pTTYEventMultiplexer != nullptr )
  {
    free(pMem: this->m_pTTYEventMultiplexer);
    this->m_pTTYEventMultiplexer = nullptr;
  }
  result = this->m_nResultOfRegisteringTTYHandler;
  if ( result >= 0 )
    return SNPS3UnRegisterCustomProtocol(a1: this->m_nSNHandle, a2: &this->m_nVXProtocol);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418020
// Name: public: void CPS3TargetConnection::CallThisFunctionEveryTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPS3TargetConnection::CallThisFunctionEveryTick(CPS3TargetConnection *this)
{
  if ( this->m_nSNHandle >= 0 )
    SNPS3Kick();
}

//------------------------------------------------------------------------------
// Address: 0x00418030
// Name: public: long CPS3TargetConnection::SendDMProtocolData(unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::SendDMProtocolData(
        CPS3TargetConnection *this,
        unsigned __int8 *pData,
        unsigned int uLength)
{
  return SNPS3SendCustomProtocolData(a1: this->m_nSNHandle, a2: &this->m_nVXProtocol, a3: pData, a4: uLength);
}

//------------------------------------------------------------------------------
// Address: 0x00418060
// Name: public: long CPS3TargetConnection::RebootELF(char const __near *,int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::RebootELF(
        CPS3TargetConnection *this,
        const char *pszFileName,
        int argc,
        const char **argv)
{
  const char *v5; // edi
  int v6; // eax
  int result; // eax
  SNPS3DirEntry fileInfo; // [esp+8h] [ebp-380h] BYREF
  char szSpeculativeFilename[512]; // [esp+188h] [ebp-200h] BYREF

  memset(szSpeculativeFilename, 0, sizeof(szSpeculativeFilename));
  v5 = pszFileName;
  V_snprintf(pDest: szSpeculativeFilename, maxLen: 512, pFormat: "/app_home/%s", pszFileName);
  v6 = SNPS3StatTargetFile(a1: this->m_nSNHandle, a2: szSpeculativeFilename, a3: &fileInfo);
  if ( v6 < 0 )
  {
    if ( v6 == -21 )
      ConsoleWindowPrintf(rgb: 0x80u, strFormat: "%s isn't a valid path\n", szSpeculativeFilename);
    else
      ConsoleWindowPrintf(rgb: 0x80u, strFormat: "%s doesn't exist\n", szSpeculativeFilename);
    V_snprintf(pDest: szSpeculativeFilename, maxLen: 512, pFormat: "/app_home/PS3_GAME/USRDIR/%s", v5);
    if ( SNPS3StatTargetFile(a1: this->m_nSNHandle, a2: szSpeculativeFilename, a3: &fileInfo) < 0 )
      return -29;
    ConsoleWindowPrintf(rgb: 0x80u, strFormat: "but %s does; loading that.\n", szSpeculativeFilename);
    v5 = &szSpeculativeFilename[10];
  }
  pszFileName = nullptr;
  ConsoleWindowPrintf(rgb: 0, strFormat: "Rebooting (VxConsole may seem to hang)\n");
  ProcessPrintQueue();
  result = SNPS3Reset(a1: this->m_nSNHandle, a2: 0, a3: 0);
  if ( result >= 0 )
  {
    ConsoleWindowPrintf(rgb: 0, strFormat: "Reboot complete. Launching /app_home/%s\n", v5);
    return SNPS3ProcessLoad(
             a1: this->m_nSNHandle,
             a2: 999,
             a3: v5,
             a4: argc,
             a5: argv,
             a6: 0,
             a7: &pszFileName,
             a8: &this->m_nGamePID,
             a9: &this->m_nGameThreadID,
             a10: 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004181D0
// Name: public: int ps3FileInfo_t::GetWindowsAttribs(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ps3FileInfo_t::GetWindowsAttribs(ps3FileInfo_t *this)
{
  int result; // eax

  switch ( this->Type )
  {
    case 1u:
      result = 16;
      break;
    case 2u:
      result = 128;
      break;
    case 3u:
      result = 1024;
      break;
    default:
      result = 0;
      break;
  }
  if ( (this->Mode & 0x92) == 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418200
// Name: void FileTimeToSystemTime(struct tm const __near *,struct _SYSTEMTIME __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileTimeToSystemTime(const tm *lpFileTime, _SYSTEMTIME *lpSystemTime)
{
  lpSystemTime->wYear = LOWORD(lpFileTime->tm_year) + 1900;
  lpSystemTime->wMonth = LOWORD(lpFileTime->tm_mon) + 1;
  lpSystemTime->wDayOfWeek = lpFileTime->tm_wday;
  lpSystemTime->wDay = lpFileTime->tm_mday;
  lpSystemTime->wHour = lpFileTime->tm_hour;
  lpSystemTime->wMinute = lpFileTime->tm_min;
  lpSystemTime->wSecond = lpFileTime->tm_sec;
  lpSystemTime->wMilliseconds = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418250
// Name: public: void CUtlMemory<struct SNPS3DirEntry,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SNPS3DirEntry,int>::Grow(CUtlMemory<SNPS3DirEntry,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SNPS3DirEntry *m_pMemory; // edx
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
    v7 = 384 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (SNPS3DirEntry *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (SNPS3DirEntry *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004182F0
// Name: public: int CPS3TargetList::ShowTargetSelectionDialog(long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetList::ShowTargetSelectionDialog(CPS3TargetList *this, int *errorValue)
{
  int target; // [esp+0h] [ebp-4h] BYREF

  target = -1;
  *errorValue = SNPS3PickTarget(a1: g_hDlgMain, a2: &target);
  return target;
}

//------------------------------------------------------------------------------
// Address: 0x00418320
// Name: public: bool CPS3TargetConnection::Disconnect(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPS3TargetConnection::Disconnect(CPS3TargetConnection *this, bool bDisconnectTargetManagerToo)
{
  if ( this->m_nSNHandle < 0 )
    return 0;
  AbandonImageInstallationDialog();
  CPS3TargetConnection::UnregisterInternalEventHandlers(this);
  if ( bDisconnectTargetManagerToo )
    SNPS3Disconnect(a1: this->m_nSNHandle);
  this->m_nSNHandle = -1;
  this->m_nGamePID = -1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00418370
// Name: public: long CPS3TargetManagerRAII::Reset(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetManagerRAII::Reset(CPS3TargetManagerRAII *this)
{
  int result; // eax
  char pDest[1024]; // [esp+4h] [ebp-404h] BYREF
  const char *v4; // [esp+404h] [ebp-4h] BYREF

  SNPS3CloseTargetComms();
  while ( SNPS3Kick() != 3 )
    ;
  result = SNPS3InitTargetComms() < 0;
  this->m_nInitResult = result;
  if ( result != 0 )
  {
    v4 = "<unknown>";
    SNPS3TranslateError(a1: result, a2: &v4);
    V_snprintf(pDest, maxLen: 1024, pFormat: "Could not connect to target manager: %s", v4);
    MessageBoxA(hWnd: nullptr, lpText: pDest, lpCaption: "Connection Failure", uType: 0x10u);
    return this->m_nInitResult;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004183F0
// Name: public: void CUtlMemory<unsigned char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

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
        m_nAllocationCount = 32;
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
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418480
// Name: public: void CUtlMemory<struct SNPS3Transfer,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SNPS3Transfer,int>::ConvertToGrowableMemory(
        CUtlMemory<SNPS3Transfer,int> *this,
        int nGrowSize)
{
  int m_nAllocationCount; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    this->m_nGrowSize = nGrowSize;
    m_nAllocationCount = this->m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v4 = 1344 * m_nAllocationCount;
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1344 * m_nAllocationCount);
      memcpy(dst: v5, src: (unsigned __int8 *)this->m_pMemory, count: v4);
      this->m_pMemory = (SNPS3Transfer *)v5;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004184E0
// Name: public: void CUtlMemory<struct CPS3TargetList::TargetInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPS3TargetList::TargetInfo_t,int>::Grow(
        CUtlMemory<CPS3TargetList::TargetInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CPS3TargetList::TargetInfo_t *m_pMemory; // edx
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
    v7 = 96 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CPS3TargetList::TargetInfo_t *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: m_pMemory,
                                                          a3: v7);
    else
      this->m_pMemory = (CPS3TargetList::TargetInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418580
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 3;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418630
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int> *m_pMemory; // edx
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
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: m_pMemory,
                                                                                                     a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004186D0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<unsigned long (*)(class CUtlString const __near &),unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 4;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418780
// Name: protected: int CPS3TargetList::GetInternalTargetIndexForHandle(int const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetList::GetInternalTargetIndexForHandle(CPS3TargetList *this, const int *targ)
{
  int m_Size; // edx
  int result; // eax
  CPS3TargetList::TargetInfo_t *i; // ecx

  m_Size = this->m_Targets.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Targets.m_Memory.m_pMemory; i->hTarget != *targ; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004187B0
// Name: public: void CUtlMemoryFixedGrowable<struct SNPS3Transfer,256,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryFixedGrowable<SNPS3Transfer,256,int>::EnsureCapacity(
        CUtlMemoryFixedGrowable<SNPS3Transfer,256,int> *this,
        int num)
{
  SNPS3Transfer *m_pMemory; // eax
  IMemAlloc_vtbl *v4; // edx
  int v5; // [esp-4h] [ebp-Ch]

  if ( this->m_nAllocationCount < num )
  {
    if ( this->m_nGrowSize < 0 )
      CUtlMemory<SNPS3Transfer,int>::ConvertToGrowableMemory(this, nGrowSize: this->m_nMallocGrowSize);
    if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
    {
      m_pMemory = this->m_pMemory;
      this->m_nAllocationCount = num;
      v4 = _g_pMemAlloc->__vftable;
      v5 = 1344 * num;
      if ( m_pMemory != nullptr )
        this->m_pMemory = (SNPS3Transfer *)((int (__stdcall *)(SNPS3Transfer *, int))v4->Realloc_2)(
                                             a1: m_pMemory,
                                             a2: v5);
      else
        this->m_pMemory = (SNPS3Transfer *)((int (__stdcall *)(int))v4->Alloc_2)(a1: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418810
// Name: public: int CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::InsertMultipleBefore(int,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int elem,
        int num,
        const unsigned __int8 *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 *m_pMemory; // ecx
  int v9; // eax
  int i; // ecx
  unsigned __int8 *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned char,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; ++i )
    {
      v11 = &this->m_Memory.m_pMemory[i + elem];
      if ( v11 != nullptr )
        *v11 = pToInsert[i];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004188A0
// Name: protected: unsigned short CUtlLinkedList<struct CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x00418A20
// Name: protected: int CUtlLinkedList<struct CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>::Grow(
      this: &this->m_Memory,
      num: 1);
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
      if ( `CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x00418B50
// Name: protected: unsigned short CUtlLinkedList<unsigned long (*)(class CUtlString const __near &),unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned long (*)(class CUtlString const __near &),unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<unsigned long (__stdcall*)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x00418CD0
// Name: public: int CUtlVector<struct SNPS3DirEntry,class CUtlMemory<struct SNPS3DirEntry,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<SNPS3DirEntry,CUtlMemory<SNPS3DirEntry,int>>::InsertMultipleBefore(
        CUtlVector<SNPS3DirEntry,CUtlMemory<SNPS3DirEntry,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  SNPS3DirEntry *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<SNPS3DirEntry,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 384 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00418D50
// Name: public: int CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned int,CUtlMemory<unsigned int,int>>::InsertMultipleBefore(
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned int *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned int,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00418DC0
// Name: public: CPS3TargetList::TargetInfo_t::~TargetInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPS3TargetList::TargetInfo_t::~TargetInfo_t(CPS3TargetList::TargetInfo_t *this)
{
  this->szFSDir.m_Storage.m_nActualLength = 0;
  if ( this->szFSDir.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->szFSDir.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->szFSDir.m_Storage.m_Memory.m_pMemory);
      this->szFSDir.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->szFSDir.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->szHomeDir.m_Storage.m_nActualLength = 0;
  if ( this->szHomeDir.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->szHomeDir.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->szHomeDir.m_Storage.m_Memory.m_pMemory);
      this->szHomeDir.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->szHomeDir.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->szInfo.m_Storage.m_nActualLength = 0;
  if ( this->szInfo.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->szInfo.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->szInfo.m_Storage.m_Memory.m_pMemory);
      this->szInfo.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->szInfo.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->szType.m_Storage.m_nActualLength = 0;
  if ( this->szType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->szType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->szType.m_Storage.m_Memory.m_pMemory);
      this->szType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->szType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->szName.m_Storage.m_nActualLength = 0;
  if ( this->szName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->szName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->szName.m_Storage.m_Memory.m_pMemory);
      this->szName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->szName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418E90
// Name: public: CPS3TargetList::TargetInfo_t::TargetInfo_t(struct CPS3TargetList::TargetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPS3TargetList::TargetInfo_t *__thiscall CPS3TargetList::TargetInfo_t::TargetInfo_t(
        CPS3TargetList::TargetInfo_t *this,
        const CPS3TargetList::TargetInfo_t *__that)
{
  this->hTarget = __that->hTarget;
  CUtlString::CUtlString(this: &this->szName, string: &__that->szName);
  CUtlString::CUtlString(this: &this->szType, string: &__that->szType);
  CUtlString::CUtlString(this: &this->szInfo, string: &__that->szInfo);
  CUtlString::CUtlString(this: &this->szHomeDir, string: &__that->szHomeDir);
  CUtlString::CUtlString(this: &this->szFSDir, string: &__that->szFSDir);
  this->boot = __that->boot;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00418EF0
// Name: public: void CPS3TargetConnection::DispatchToAllDebugStringNotificationHandlers(class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPS3TargetConnection::DispatchToAllDebugStringNotificationHandlers(
        CPS3TargetConnection *this,
        const CUtlString *str)
{
  unsigned __int16 i; // ax
  int v4; // esi
  UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *m_pMemory; // ecx
  bool v6; // zf
  UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *v7; // ecx

  for ( i = this->m_TTYHandlerFuncs.m_Head; ; i = this->m_TTYHandlerFuncs.m_Memory.m_pMemory[v4].m_Next )
  {
    v4 = i;
    if ( i >= this->m_TTYHandlerFuncs.m_Memory.m_nAllocationCount )
      break;
    if ( i > this->m_TTYHandlerFuncs.m_LastAlloc.index )
      break;
    m_pMemory = this->m_TTYHandlerFuncs.m_Memory.m_pMemory;
    v6 = m_pMemory[i].m_Previous == i;
    v7 = &m_pMemory[i];
    if ( v6 && v7->m_Next != i )
      break;
    v7->m_Element(a1: str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418F50
// Name: private: unsigned short CPS3TargetConnection::FindHandlerForPrefix(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::FindHandlerForPrefix(CPS3TargetConnection *this, const char *pszPrefix)
{
  int result; // eax
  UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short> *v4; // ecx

  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pszPrefix, pStr: pszPrefix);
  for ( result = this->m_DMNotificationHandlers.m_Head;
        (unsigned __int16)result < this->m_DMNotificationHandlers.m_Memory.m_nAllocationCount;
        result = v4->m_Next )
  {
    if ( (unsigned __int16)result > this->m_DMNotificationHandlers.m_LastAlloc.index )
      break;
    v4 = &this->m_DMNotificationHandlers.m_Memory.m_pMemory[(unsigned __int16)result];
    if ( v4->m_Previous == (_WORD)result && v4->m_Next != (_WORD)result )
      break;
    if ( v4->m_Element.m_sPrefix.m_Id == (_WORD)pszPrefix )
      return result;
  }
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x00418FC0
// Name: private: int CPS3TargetConnection::FindBCMByMsgNum(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::FindBCMByMsgNum(CPS3TargetConnection *this, unsigned int nMsgn)
{
  int result; // eax
  UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int> *v3; // edx

  for ( result = this->m_lIncomingBCMs.m_Head; result >= 0; result = v3->m_Next )
  {
    if ( result >= this->m_lIncomingBCMs.m_Memory.m_nAllocationCount )
      break;
    if ( result > this->m_lIncomingBCMs.m_LastAlloc.index )
      break;
    v3 = &this->m_lIncomingBCMs.m_Memory.m_pMemory[result];
    if ( v3->m_Previous == result && v3->m_Next != result )
      break;
    if ( v3->m_Element.m_nMessageID == nMsgn )
      return result;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00419010
// Name: public: long CPS3TargetConnection::WaitForAsyncFileTransfers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::WaitForAsyncFileTransfers(CPS3TargetConnection *this)
{
  CPS3TargetConnection *v1; // esi
  SNPS3Transfer *m_pMemory; // edi
  unsigned int *p_Status; // ecx
  int v5; // esi
  char v6; // bl
  bool v7; // al
  int m_nSNHandle; // [esp-Ch] [ebp-5402Ch]
  CUtlMemoryFixedGrowable<SNPS3Transfer,256,int> v9; // [esp+8h] [ebp-54018h] BYREF
  CPS3TargetConnection *v10; // [esp+54018h] [ebp-8h]
  int num; // [esp+5401Ch] [ebp-4h] BYREF

  v1 = this;
  m_nSNHandle = this->m_nSNHandle;
  v10 = this;
  num = 0;
  if ( SNPS3GetFileTransferList(a1: m_nSNHandle, a2: &num, a3: 0) >= 0 )
  {
    v9.m_pMemory = v9.m_pFixedMemory;
    v9.m_nAllocationCount = 256;
    v9.m_nGrowSize = -1;
    v9.m_nMallocGrowSize = 0;
    CUtlMemoryFixedGrowable<SNPS3Transfer,256,int>::EnsureCapacity(this: &v9, num);
    m_pMemory = v9.m_pMemory;
    while ( SNPS3GetFileTransferList(a1: v1->m_nSNHandle, a2: &num, a3: m_pMemory) >= 0 )
    {
      v5 = num;
      v6 = 0;
      if ( num != 0 )
      {
        p_Status = &m_pMemory->Status;
        do
        {
          v7 = *p_Status == 16 || *p_Status == 1;
          v6 |= v7;
          p_Status += 336;
          --v5;
        }
        while ( v5 != 0 );
      }
      SNPS3Kick(a1: p_Status);
      if ( v6 == 0 )
      {
        if ( v9.m_nGrowSize >= 0 && v9.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9.m_pMemory);
        return 0;
      }
      v1 = v10;
    }
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Failed to poll file transfer list.\n");
    if ( v9.m_nGrowSize >= 0 && v9.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9.m_pMemory);
    return -29;
  }
  else
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Failed to poll file transfer list.\n");
    return -29;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419160
// Name: public: void CUtlLinkedList<struct CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004191D0
// Name: public: void CUtlLinkedList<struct CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::Unlink(
        CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int> *v2; // eax
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
// Address: 0x00419250
// Name: public: void CUtlLinkedList<struct CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004192E0
// Name: public: void CUtlLinkedList<unsigned long (*)(class CUtlString const __near &),unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned long (*)(class CUtlString const __near &),unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<unsigned long (__stdcall*)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *m_pMemory; // eax
  int m_Previous; // edi
  unsigned __int16 *p_m_Next; // edx
  unsigned __int16 v7; // cx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      m_Previous = m_pMemory[elem].m_Previous;
      p_m_Next = &m_pMemory[elem].m_Next;
      v7 = *p_m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = v7;
      }
      else
      {
        m_pMemory[m_Previous].m_Next = v7;
        v2 = elem;
      }
      if ( v7 == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[v7].m_Previous = m_Previous;
      *p_m_Next = v2;
      --this->m_ElementCount;
      m_pMemory[elem].m_Previous = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419370
// Name: public: void CPS3ttyEventHandler::OnEvent(int,unsigned int,long,unsigned int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPS3ttyEventHandler::OnEvent(
        CPS3ttyEventHandler *this,
        int hTarget,
        unsigned int Param,
        int eResult,
        unsigned int Length,
        unsigned __int8 *Data)
{
  unsigned __int8 *v7; // eax
  CUtlString str; // [esp+Ch] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &str);
  CUtlString::SetDirect(this: &str, pValue: (const char *)Data, nChars: Length);
  if ( Length != 0 )
  {
    strstr(str1: Data, str2: "GAME BOOT:");
    if ( v7 == Data )
      CPS3TargetConnection::ResetInternalEventHandlers(this: this->m_pOwningConnection);
  }
  CPS3TargetConnection::DispatchToAllDebugStringNotificationHandlers(this: this->m_pOwningConnection, &str);
  str.m_Storage.m_nActualLength = 0;
  if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004193F0
// Name: public: void CPS3TargetConnection::PurgeDMEmulatingNotifications(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPS3TargetConnection::PurgeDMEmulatingNotifications(CPS3TargetConnection *this)
{
  CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_DMNotificationHandlers);
}

//------------------------------------------------------------------------------
// Address: 0x00419400
// Name: private: void CPS3TargetConnection::HandleCustomVXMessage(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPS3TargetConnection::HandleCustomVXMessage(
        CPS3TargetConnection *this,
        char *pDataStr,
        unsigned int uLength)
{
  unsigned int v4; // edi
  const char *v5; // esi
  char *v6; // esi
  unsigned __int16 HandlerForPrefix; // ax
  int v8; // eax
  unsigned int prefixlen; // [esp+18h] [ebp+8h]

  v4 = uLength;
  if ( g_debugCommands != 0 )
    Remote_NotifyPrintFunc(pStrNotification: pDataStr, nDataLength: uLength, bTerminalNewline: true);
  v5 = V_strnchr(pStr: pDataStr, c: 33, n: v4);
  if ( v5 == nullptr )
  {
    _Warning(a1: "Custom vxprotocol lacked a '!' prefix\n");
    return;
  }
  uLength = 0;
  CUtlMemoryConservative<char>::EnsureCapacity(this: (CUtlMemoryConservative<char> *)&uLength, num: v4 + 1);
  prefixlen = v5 - pDataStr;
  v6 = (char *)uLength;
  memcpy(dst: (unsigned __int8 *)uLength, src: (unsigned __int8 *)pDataStr, count: prefixlen);
  v6[prefixlen] = 0;
  HandlerForPrefix = CPS3TargetConnection::FindHandlerForPrefix(this, pszPrefix: v6);
  uLength = HandlerForPrefix;
  if ( HandlerForPrefix == 0xFFFF )
  {
    _Warning(a1: "Had no handler for a \"%s\" message!\n", v6);
    if ( v6 == nullptr )
      return;
  }
  else
  {
    memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pDataStr, count: v4);
    v8 = (unsigned __int16)uLength;
    v6[v4] = 0;
    this->m_DMNotificationHandlers.m_Memory.m_pMemory[v8].m_Element.m_func(a1: v6, a2: v4);
    if ( v6 == nullptr )
      return;
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00419510
// Name: public: bool CPS3TargetConnection::BinaryContinuedMessage_t::AddBytes(char const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPS3TargetConnection::BinaryContinuedMessage_t::AddBytes(
        CPS3TargetConnection::BinaryContinuedMessage_t *this,
        const char *pData,
        unsigned int nDataLength,
        unsigned int nPacketNum)
{
  if ( nPacketNum != this->m_NextExpectedPacketNumber )
    return 0;
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
    this: &this->m_vBytes,
    elem: this->m_vBytes.m_Size,
    num: nDataLength,
    pToInsert: (const unsigned __int8 *)pData);
  ++this->m_NextExpectedPacketNumber;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419550
// Name: public: long CPS3TargetConnection::DownloadFileAsync(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::DownloadFileAsync(
        CPS3TargetConnection *this,
        const char *pszSource,
        const char *pszDest)
{
  int v4; // edi

  CPS3TargetConnection::WaitForAsyncFileTransfers(this);
  v4 = SNPS3DownloadFile(a1: this->m_nSNHandle, a2: pszSource, a3: pszDest, a4: 0);
  CPS3TargetConnection::WaitForAsyncFileTransfers(this);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00419590
// Name: public: int CUtlVector<struct CPS3TargetList::TargetInfo_t,class CUtlMemory<struct CPS3TargetList::TargetInfo_t,int>>::InsertBefore(int,struct CPS3TargetList::TargetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPS3TargetList::TargetInfo_t,CUtlMemory<CPS3TargetList::TargetInfo_t,int>>::InsertBefore(
        CUtlVector<CPS3TargetList::TargetInfo_t,CUtlMemory<CPS3TargetList::TargetInfo_t,int> > *this,
        int elem,
        const CPS3TargetList::TargetInfo_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CPS3TargetList::TargetInfo_t *m_pMemory; // ecx
  int v7; // eax
  CPS3TargetList::TargetInfo_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPS3TargetList::TargetInfo_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 96 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CPS3TargetList::TargetInfo_t::TargetInfo_t(this: v8, __that: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00419600
// Name: public: void CUtlLinkedList<struct CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419690
// Name: struct CPS3TargetConnection::BinaryContinuedMessage_t __near * Construct<struct CPS3TargetConnection::BinaryContinuedMessage_t>(struct CPS3TargetConnection::BinaryContinuedMessage_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPS3TargetConnection::BinaryContinuedMessage_t *__cdecl Construct<CPS3TargetConnection::BinaryContinuedMessage_t>(
        CPS3TargetConnection::BinaryContinuedMessage_t *pMemory)
{
  unsigned __int8 *v1; // eax

  if ( pMemory == nullptr )
    return nullptr;
  pMemory->m_vBytes.m_Memory.m_nAllocationCount = 0x10000;
  pMemory->m_vBytes.m_Memory.m_nGrowSize = 0x10000;
  pMemory->m_vBytes.m_Memory.m_pMemory = nullptr;
  v1 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x10000);
  pMemory->m_vBytes.m_Memory.m_pMemory = v1;
  pMemory->m_vBytes.m_pElements = v1;
  pMemory->m_vBytes.m_Size = 0;
  pMemory->m_NextExpectedPacketNumber = 0;
  pMemory->m_nMessageID = -1;
  return pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x004196E0
// Name: public: void CUtlLinkedList<unsigned long (*)(class CUtlString const __near &),unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<unsigned long (*)(class CUtlString const __near &),unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<unsigned long (__stdcall*)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *v7; // ebx

  CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419760
// Name: public: static void CPS3ttyEventHandler::SNEventCallback(int,unsigned int,unsigned int,long,unsigned int,unsigned char __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CPS3ttyEventHandler::SNEventCallback(
        int hTarget,
        unsigned int Type,
        unsigned int Param,
        int eResult,
        unsigned int Length,
        unsigned __int8 *Data,
        CPS3ttyEventHandler *UserData)
{
  CPS3ttyEventHandler::OnEvent(this: UserData, hTarget, Param, eResult, Length, Data);
}

//------------------------------------------------------------------------------
// Address: 0x00419790
// Name: public: long CPS3TargetConnection::GetDirectoryListing(char const __near *,class CUtlVector<struct SNPS3DirEntry,class CUtlMemory<struct SNPS3DirEntry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::GetDirectoryListing(
        CPS3TargetConnection *this,
        const char *pszTargetDirectory,
        CUtlVector<SNPS3DirEntry,CUtlMemory<SNPS3DirEntry,int> > *aDirEntries)
{
  CUtlVector<SNPS3DirEntry,CUtlMemory<SNPS3DirEntry,int> > *v3; // esi
  CUtlVector<SNPS3DirEntry,CUtlMemory<SNPS3DirEntry,int> > *v5; // ecx
  int i; // edi
  int m_nAllocationCount; // eax
  int m_Size; // ecx
  int v9; // edi
  int v10; // ebx
  char *v11; // edx
  SNPS3DirEntry *m_pMemory; // ecx
  int v13; // eax
  int v14; // ecx
  CPS3TargetConnection *v16; // [esp+Ch] [ebp-8h]
  char *v17; // [esp+10h] [ebp-4h]

  v3 = aDirEntries;
  v5 = aDirEntries;
  v16 = this;
  aDirEntries->m_Size = 0;
  CUtlVector<SNPS3DirEntry,CUtlMemory<SNPS3DirEntry,int>>::InsertMultipleBefore(this: v5, elem: 0, num: 16);
  aDirEntries = (CUtlVector<SNPS3DirEntry,CUtlMemory<SNPS3DirEntry,int> > *)v3->m_Memory.m_nAllocationCount;
  for ( i = SNPS3GetDirectoryList(
              a1: this->m_nSNHandle,
              a2: pszTargetDirectory,
              a3: &aDirEntries,
              a4: v3->m_Memory.m_pMemory);
        i == -12;
        i = SNPS3GetDirectoryList(
              a1: v16->m_nSNHandle,
              a2: pszTargetDirectory,
              a3: &aDirEntries,
              a4: v3->m_Memory.m_pMemory) )
  {
    m_nAllocationCount = v3->m_Memory.m_nAllocationCount;
    m_Size = v3->m_Size;
    if ( m_Size < (int)aDirEntries + m_nAllocationCount )
    {
      v9 = (int)aDirEntries + m_nAllocationCount - m_Size;
      v10 = v3->m_Size;
      if ( v9 != 0 )
      {
        v11 = (char *)aDirEntries + m_nAllocationCount;
        v17 = (char *)aDirEntries + m_nAllocationCount;
        if ( (int)aDirEntries + m_nAllocationCount > m_nAllocationCount )
        {
          CUtlMemory<SNPS3DirEntry,int>::Grow(this: &v3->m_Memory, num: (int)aDirEntries);
          v11 = v17;
        }
        v3->m_Size += v9;
        m_pMemory = v3->m_Memory.m_pMemory;
        v13 = v3->m_Size - v10 - v9;
        v3->m_pElements = v3->m_Memory.m_pMemory;
        if ( v13 > 0 && v9 > 0 )
          _V_memmove(dest: &m_pMemory[(_DWORD)v11], src: &m_pMemory[v10], count: 384 * v13);
      }
    }
    aDirEntries = (CUtlVector<SNPS3DirEntry,CUtlMemory<SNPS3DirEntry,int> > *)v3->m_Memory.m_nAllocationCount;
  }
  if ( i != 0 )
  {
    v3->m_Size = 0;
    if ( v3->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v3->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
        v3->m_Memory.m_pMemory = nullptr;
      }
      v3->m_Memory.m_nAllocationCount = 0;
    }
    v3->m_pElements = v3->m_Memory.m_pMemory;
  }
  else
  {
    v14 = v3->m_Size;
    if ( (int)aDirEntries - v14 > 0 )
    {
      CUtlVector<SNPS3DirEntry,CUtlMemory<SNPS3DirEntry,int>>::InsertMultipleBefore(
        this: v3,
        elem: v14,
        num: (int)aDirEntries - v14);
      return 0;
    }
    if ( (int)aDirEntries - v14 < 0 )
    {
      v3->m_Size = (int)aDirEntries;
      return 0;
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x004198F0
// Name: private: static void CPS3TargetConnection::CustomVXProtocolCallback(int,unsigned char __near *,unsigned int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CPS3TargetConnection::CustomVXProtocolCallback(
        int hTarget,
        unsigned __int8 *pData,
        unsigned int uLength,
        CPS3TargetConnection *pUser)
{
  int m_nSNHandle; // eax

  if ( pUser != nullptr )
  {
    m_nSNHandle = pUser->m_nSNHandle;
    if ( m_nSNHandle == hTarget )
    {
      if ( uLength > 1 )
        CPS3TargetConnection::HandleCustomVXMessage(this: pUser, pDataStr: (char *)pData, uLength);
    }
    else
    {
      _Warning(
        a1: "Invalid target handle to connection callback -- expected %d got signal from %d\n",
        m_nSNHandle,
        hTarget);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419930
// Name: private: unsigned int CPS3TargetConnection::GetGameProcessID(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPS3TargetConnection::GetGameProcessID(CPS3TargetConnection *this)
{
  CPS3TargetConnection *v1; // ebx
  bool v2; // sf
  unsigned int result; // eax
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int v5; // esi
  unsigned int *m_pMemory; // edi
  HRESULT v7; // eax
  int m_Size; // ebx
  signed int v9; // esi
  unsigned int v10; // edi
  void *(__thiscall *v11)(IMemAlloc *, unsigned int); // eax
  unsigned __int8 *v12; // ebx
  unsigned int v13; // esi
  int ModuleList; // eax
  unsigned int *v15; // edi
  unsigned int v16; // edx
  int ModuleInfo; // eax
  int m_nSNHandle; // [esp-14h] [ebp-254h]
  int v19; // [esp-14h] [ebp-254h]
  unsigned int moduleIds[128]; // [esp+4h] [ebp-23Ch] BYREF
  unsigned __int64 moduleInfoSize; // [esp+204h] [ebp-3Ch] BYREF
  CUtlMemory<unsigned char,int> mem; // [esp+20Ch] [ebp-34h] BYREF
  unsigned int i; // [esp+218h] [ebp-28h]
  int piditer; // [esp+21Ch] [ebp-24h]
  unsigned int moduleCt; // [esp+220h] [ebp-20h] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > pids; // [esp+224h] [ebp-1Ch] BYREF
  unsigned int pidcount; // [esp+238h] [ebp-8h] BYREF
  CPS3TargetConnection *v28; // [esp+23Ch] [ebp-4h]

  v1 = this;
  v2 = this->m_nSNHandle < 0;
  v28 = this;
  if ( v2 )
  {
    this->m_nGamePID = -1;
    return -1;
  }
  result = this->m_nGamePID;
  if ( result == -1 )
  {
    Alloc_2 = _g_pMemAlloc->Alloc_2;
    v5 = 64;
    pids.m_Memory.m_nAllocationCount = 64;
    pids.m_Memory.m_nGrowSize = 32;
    m_pMemory = (unsigned int *)Alloc_2(this: _g_pMemAlloc, a2: 256u);
    m_nSNHandle = v1->m_nSNHandle;
    pids.m_Memory.m_pMemory = m_pMemory;
    pids.m_Size = 64;
    pids.m_pElements = m_pMemory;
    pidcount = 64;
    v7 = SNPS3ProcessList(a1: m_nSNHandle, a2: &pidcount, a3: m_pMemory);
    if ( v7 == -12 )
    {
      do
      {
        m_Size = 0;
        v9 = 2 * pidcount;
        pids.m_Size = 0;
        if ( 2 * pidcount != 0 )
        {
          if ( v9 > pids.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<unsigned int,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&pids,
              num: v9 - pids.m_Memory.m_nAllocationCount);
            m_pMemory = pids.m_Memory.m_pMemory;
            m_Size = pids.m_Size;
          }
          m_Size += v9;
          pids.m_Size = m_Size;
          pids.m_pElements = m_pMemory;
          if ( m_Size - v9 > 0 && v9 > 0 )
            _V_memmove(dest: &m_pMemory[v9], src: m_pMemory, count: 4 * (m_Size - v9));
        }
        v19 = v28->m_nSNHandle;
        pidcount = m_Size;
        v7 = SNPS3ProcessList(a1: v19, a2: &pidcount, a3: m_pMemory);
      }
      while ( v7 == -12 );
      v5 = pids.m_Size;
      v1 = v28;
    }
    if ( v7 < 0 )
    {
      DmAPI_DisplayError(message: "Could not get process list for target: ", hr: v7);
      v1->m_nGamePID = -1;
      CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&pids);
      return -1;
    }
    if ( (int)(pidcount - v5) <= 0 )
    {
      if ( (int)(pidcount - v5) < 0 )
      {
        v5 = pidcount;
        pids.m_Size = pidcount;
      }
    }
    else
    {
      CUtlVector<unsigned int,CUtlMemory<unsigned int,int>>::InsertMultipleBefore(
        this: &pids,
        elem: v5,
        num: pidcount - v5);
      v5 = pids.m_Size;
      m_pMemory = pids.m_Memory.m_pMemory;
    }
    if ( pidcount == 1 )
    {
      v10 = *m_pMemory;
      v1->m_nGamePID = v10;
      CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&pids);
      return v10;
    }
    v11 = _g_pMemAlloc->Alloc_2;
    mem.m_nAllocationCount = 1024;
    mem.m_nGrowSize = 0;
    v12 = (unsigned __int8 *)v11(this: _g_pMemAlloc, a2: 1024u);
    mem.m_pMemory = v12;
    piditer = 0;
    if ( v5 <= 0 )
      goto LABEL_35;
    do
    {
      moduleCt = 128;
      v13 = m_pMemory[piditer];
      ModuleList = SNPS3GetModuleList(a1: v28->m_nSNHandle, a2: v13, a3: &moduleCt, a4: moduleIds);
      if ( ModuleList >= 0 )
      {
        i = 0;
        if ( moduleCt != 0 )
        {
          v15 = moduleIds;
          while ( 1 )
          {
            moduleInfoSize = 0;
            do
            {
              CUtlMemory<unsigned char,int>::Grow(this: &mem, num: moduleInfoSize);
              v12 = mem.m_pMemory;
              v16 = *v15;
              moduleInfoSize = mem.m_nAllocationCount;
              ModuleInfo = SNPS3GetModuleInfo(
                             a1: v28->m_nSNHandle,
                             a2: v13,
                             a3: v16,
                             a4: &moduleInfoSize,
                             a5: mem.m_pMemory);
            }
            while ( ModuleInfo == -12 );
            if ( ModuleInfo >= 0 )
            {
              if ( V_stristr(pStr: (char *)v12 + 44, pSearch: "engine") != nullptr )
              {
                v2 = mem.m_nGrowSize < 0;
                v28->m_nGamePID = v13;
                if ( !v2 && v12 != nullptr )
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
                CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&pids);
                return v13;
              }
            }
            else
            {
              _Warning(a1: "Couldn't get info for pid %d module %d because %d\n", v13, *v15, ModuleInfo);
            }
            ++v15;
            if ( ++i >= moduleCt )
            {
              m_pMemory = pids.m_Memory.m_pMemory;
              break;
            }
          }
        }
      }
      else
      {
        _Warning(a1: "Couldn't get module info for pid#%d because %d\n", v13, ModuleList);
      }
      ++piditer;
    }
    while ( piditer < pids.m_Size );
    if ( mem.m_nGrowSize >= 0 )
    {
LABEL_35:
      if ( v12 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
    }
    v28->m_nGamePID = -1;
    CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&pids);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419C40
// Name: public: long CPS3TargetConnection::GetProcessMemoryStatistics(struct SNPS3UserMemoryStats __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::GetProcessMemoryStatistics(
        CPS3TargetConnection *this,
        SNPS3UserMemoryStats *pMemStats)
{
  unsigned int GameProcessID; // eax

  GameProcessID = CPS3TargetConnection::GetGameProcessID(this);
  if ( GameProcessID != -1 )
    return SNPS3GetUserMemoryStats(a1: this->m_nSNHandle, a2: GameProcessID, a3: pMemStats);
  *(_QWORD *)&pMemStats->uCreatedSharedMemorySize = 0;
  *(_QWORD *)&pMemStats->uProcessLocalMemorySize = 0;
  *(_QWORD *)&pMemStats->uPRXTextSize = 0;
  pMemStats->uMiscMemorySize = 0;
  return -4;
}

//------------------------------------------------------------------------------
// Address: 0x00419C90
// Name: public: long CPS3TargetConnection::HaltGameProcess(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::HaltGameProcess(CPS3TargetConnection *this, bool bStop)
{
  unsigned int GameProcessID; // [esp-4h] [ebp-8h]

  GameProcessID = CPS3TargetConnection::GetGameProcessID(this);
  if ( bStop )
    return SNPS3ProcessStop(a1: this->m_nSNHandle, a2: GameProcessID);
  else
    return SNPS3ProcessContinue(a1: this->m_nSNHandle, a2: GameProcessID);
}

//------------------------------------------------------------------------------
// Address: 0x00419CD0
// Name: public: void CUtlVector<struct CPS3TargetList::TargetInfo_t,class CUtlMemory<struct CPS3TargetList::TargetInfo_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CPS3TargetList::TargetInfo_t,CUtlMemory<CPS3TargetList::TargetInfo_t,int>>::Purge(
        CUtlVector<CPS3TargetList::TargetInfo_t,CUtlMemory<CPS3TargetList::TargetInfo_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CPS3TargetList::TargetInfo_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CPS3TargetList::TargetInfo_t::~TargetInfo_t(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419D30
// Name: protected: void CPS3TargetList::ProcessOneTargetFromEnumeration(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPS3TargetList::ProcessOneTargetFromEnumeration(CPS3TargetList *this, int target)
{
  CPS3TargetList::TargetInfo_t src; // [esp+4h] [ebp-88h] BYREF
  SNPS3TargetInfo info; // [esp+64h] [ebp-28h] BYREF

  info.nFlags = 1;
  info.hTarget = target;
  if ( SNPS3GetTargetInfo(a1: &info) == 0 )
  {
    src.hTarget = info.hTarget;
    CUtlString::CUtlString(this: &src.szName, pString: info.pszName);
    CUtlString::CUtlString(this: &src.szType, pString: info.pszType);
    CUtlString::CUtlString(this: &src.szInfo, pString: info.pszInfo);
    CUtlString::CUtlString(this: &src.szHomeDir, pString: info.pszHomeDir);
    CUtlString::CUtlString(this: &src.szFSDir, pString: info.pszFSDir);
    src.boot = info.boot;
    CUtlVector<CPS3TargetList::TargetInfo_t,CUtlMemory<CPS3TargetList::TargetInfo_t,int>>::InsertBefore(
      this: &this->m_Targets,
      elem: this->m_Targets.m_Size,
      &src);
    CPS3TargetList::TargetInfo_t::~TargetInfo_t(this: &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419DE0
// Name: public: int CPS3TargetList::FindTargetByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetList::FindTargetByName(CPS3TargetList *this, const char *name)
{
  int m_Size; // edx
  int result; // eax
  int v5; // ecx
  CPS3TargetList::TargetInfo_t *i; // esi

  if ( SNPS3GetTargetFromName(a1: name, a2: &name) != 0 )
    return -1;
  m_Size = this->m_Targets.m_Size;
  result = (int)name;
  v5 = 0;
  if ( m_Size <= 0 )
    goto LABEL_8;
  for ( i = this->m_Targets.m_Memory.m_pMemory; (const char *)i->hTarget != name; ++i )
  {
    if ( ++v5 >= m_Size )
    {
      CPS3TargetList::ProcessOneTargetFromEnumeration(this, target: (int)name);
      return (int)name;
    }
  }
  if ( v5 == -1 )
  {
LABEL_8:
    CPS3TargetList::ProcessOneTargetFromEnumeration(this, target: (int)name);
    return (int)name;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419E50
// Name: public: long CPS3TargetConnection::DmGetMemory(unsigned __int64,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::DmGetMemory(
        CPS3TargetConnection *this,
        unsigned __int64 pAddressOnConsoleToReadFrom,
        int nBytesToRead,
        void *pLocalDestinationBuffer)
{
  unsigned int GameProcessID; // eax

  GameProcessID = CPS3TargetConnection::GetGameProcessID(this);
  return SNPS3ProcessGetMemory(
           a1: this->m_nSNHandle,
           a2: 0,
           a3: GameProcessID,
           a4: 0,
           a5: 0,
           a6: pAddressOnConsoleToReadFrom,
           a7: HIDWORD(pAddressOnConsoleToReadFrom),
           a8: nBytesToRead,
           a9: pLocalDestinationBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x00419E90
// Name: public: long CPS3TargetConnection::DmSetMemory(unsigned __int64,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::DmSetMemory(
        CPS3TargetConnection *this,
        unsigned __int64 pAddressOnConsoleToWriteTo,
        int nBytesToWrite,
        void *pLocalSourceBuffer)
{
  unsigned int GameProcessID; // eax

  GameProcessID = CPS3TargetConnection::GetGameProcessID(this);
  return SNPS3ProcessSetMemory(
           a1: this->m_nSNHandle,
           a2: 0,
           a3: GameProcessID,
           a4: 0,
           a5: 0,
           a6: pAddressOnConsoleToWriteTo,
           a7: HIDWORD(pAddressOnConsoleToWriteTo),
           a8: nBytesToWrite,
           a9: pLocalSourceBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x00419ED0
// Name: public: long CPS3TargetConnection::CrashDump(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::CrashDump(CPS3TargetConnection *this)
{
  unsigned int GameProcessID; // eax

  GameProcessID = CPS3TargetConnection::GetGameProcessID(this);
  return SNPS3TriggerCoreDump(a1: this->m_nSNHandle, a2: GameProcessID, a3: 0, a4: 0, a5: 0, a6: 0, a7: 0, a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00419F00
// Name: private: long CPS3TargetConnection::RegisterInternalEventHandlers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::RegisterInternalEventHandlers(CPS3TargetConnection *this)
{
  CPS3ttyEventHandler *v2; // eax
  int result; // eax

  if ( this->m_pTTYEventMultiplexer == nullptr )
  {
    v2 = (CPS3ttyEventHandler *)operator new(nSize: 4u);
    if ( v2 != nullptr )
      v2->m_pOwningConnection = this;
    else
      v2 = nullptr;
    this->m_pTTYEventMultiplexer = v2;
  }
  result = SNPS3RegisterTTYEventHandler(
             a1: this->m_nSNHandle,
             a2: -1,
             a3: CPS3ttyEventHandler::SNEventCallback,
             a4: this->m_pTTYEventMultiplexer);
  this->m_nResultOfRegisteringTTYHandler = result;
  if ( result >= 0 )
    return SNPS3RegisterCustomProtocol(
             a1: this->m_nSNHandle,
             a2: 4097,
             a3: 0,
             a4: "PS3_LPAR",
             a5: 128,
             a6: &this->m_nVXProtocol,
             a7: CPS3TargetConnection::CustomVXProtocolCallback,
             a8: this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419F80
// Name: public: long CPS3TargetConnection::ResetInternalEventHandlers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::ResetInternalEventHandlers(CPS3TargetConnection *this)
{
  this->m_nResultOfRegisteringTTYHandler = SNPS3CancelTTYEvents(a1: this->m_nSNHandle, a2: -1);
  if ( this->m_pTTYEventMultiplexer != nullptr )
  {
    free(pMem: this->m_pTTYEventMultiplexer);
    this->m_pTTYEventMultiplexer = nullptr;
  }
  if ( this->m_nResultOfRegisteringTTYHandler >= 0 )
    SNPS3UnRegisterCustomProtocol(a1: this->m_nSNHandle, a2: &this->m_nVXProtocol);
  return CPS3TargetConnection::RegisterInternalEventHandlers(this);
}

//------------------------------------------------------------------------------
// Address: 0x00419FE0
// Name: public: int CUtlLinkedList<struct CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::AddToTail(
        CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int> *m_pMemory; // eax
  int v5; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int> *v7; // eax

  result = CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::Unlink(
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
    v7 = this->m_Memory.m_pMemory;
    ++this->m_ElementCount;
    Construct<CPS3TargetConnection::BinaryContinuedMessage_t>(pMemory: &v7[v5].m_Element);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041A050
// Name: public: void CUtlLinkedList<struct CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int> > *this)
{
  int m_Head; // edi
  bool v2; // sf
  int m_Next; // ebx
  UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int> *v4; // esi
  unsigned __int8 *m_pMemory; // eax
  int m_FirstFree; // eax
  int v7; // eax
  CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int> > *v8; // [esp+0h] [ebp-4h]

  v8 = this;
  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = this->m_Memory.m_pMemory[m_Head].m_Element.m_vBytes.m_Memory.m_nGrowSize < 0;
        m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
        v4 = &this->m_Memory.m_pMemory[m_Head];
        v4->m_Element.m_vBytes.m_Size = 0;
        if ( !v2 )
        {
          if ( v4->m_Element.m_vBytes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Element.m_vBytes.m_Memory.m_pMemory);
            this = v8;
            v4->m_Element.m_vBytes.m_Memory.m_pMemory = nullptr;
          }
          v4->m_Element.m_vBytes.m_Memory.m_nAllocationCount = 0;
        }
        v2 = v4->m_Element.m_vBytes.m_Memory.m_nGrowSize < 0;
        m_pMemory = v4->m_Element.m_vBytes.m_Memory.m_pMemory;
        v4->m_Element.m_vBytes.m_pElements = v4->m_Element.m_vBytes.m_Memory.m_pMemory;
        if ( !v2 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            this = v8;
            v4->m_Element.m_vBytes.m_Memory.m_pMemory = nullptr;
          }
          v4->m_Element.m_vBytes.m_Memory.m_nAllocationCount = 0;
        }
        v4->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v4->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v7 = this->m_Head;
    if ( v7 != -1 )
      this->m_FirstFree = v7;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A130
// Name: protected: static int CPS3TargetList::SNAPI_EnumTargetsCallback(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CPS3TargetList::SNAPI_EnumTargetsCallback(int target, CPS3TargetList *userinfo)
{
  CPS3TargetList::ProcessOneTargetFromEnumeration(this: userinfo, target);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A150
// Name: public: bool CPS3TargetList::EnumerateTargets(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPS3TargetList::EnumerateTargets(CPS3TargetList *this)
{
  int v2; // esi
  int v3; // edi

  v2 = this->m_Targets.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CPS3TargetList::TargetInfo_t::~TargetInfo_t(this: &this->m_Targets.m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Targets.m_Size = 0;
  return SNPS3EnumerateTargetsEx(a1: CPS3TargetList::SNAPI_EnumTargetsCallback, a2: this) == 0
      && this->m_Targets.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A1A0
// Name: public: long CPS3TargetConnection::ConnectTo(struct CPS3TargetList::TargetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::ConnectTo(CPS3TargetConnection *this, const CPS3TargetList::TargetInfo_t *target)
{
  int v3; // eax
  int v4; // ebx

  v3 = SNPS3Connect(a1: target->hTarget, a2: 0);
  v4 = v3;
  if ( v3 == 0 || v3 == 2 )
  {
    this->m_nSNHandle = target->hTarget;
    this->m_nGamePID = -1;
    this->m_targetInfo.hTarget = target->hTarget;
    CUtlString::operator=(this: &this->m_targetInfo.szName, src: &target->szName);
    CUtlString::operator=(this: &this->m_targetInfo.szType, src: &target->szType);
    CUtlString::operator=(this: &this->m_targetInfo.szInfo, src: &target->szInfo);
    CUtlString::operator=(this: &this->m_targetInfo.szHomeDir, src: &target->szHomeDir);
    CUtlString::operator=(this: &this->m_targetInfo.szFSDir, src: &target->szFSDir);
    this->m_targetInfo.boot = target->boot;
    SNPS3SetExtraLoadFlags(a1: this->m_nSNHandle, a2: 16, a3: 0, a4: 16, a5: 0);
    CPS3TargetConnection::BlabberAboutConnectedTarget(this);
    v4 = CPS3TargetConnection::RegisterInternalEventHandlers(this);
  }
  if ( v4 < 0 )
    CPS3TargetConnection::UnregisterInternalEventHandlers(this);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0041A270
// Name: public: void CPS3TargetConnection::EmergencyReset(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPS3TargetConnection::EmergencyReset(CPS3TargetConnection *this, bool bReconnectAfter)
{
  bool v3; // sf
  int boot_high; // ecx
  CPS3TargetList::TargetInfo_t targetInfo; // [esp+4h] [ebp-60h] BYREF

  targetInfo.hTarget = this->m_targetInfo.hTarget;
  CUtlString::CUtlString(this: &targetInfo.szName, string: &this->m_targetInfo.szName);
  CUtlString::CUtlString(this: &targetInfo.szType, string: &this->m_targetInfo.szType);
  CUtlString::CUtlString(this: &targetInfo.szInfo, string: &this->m_targetInfo.szInfo);
  CUtlString::CUtlString(this: &targetInfo.szHomeDir, string: &this->m_targetInfo.szHomeDir);
  CUtlString::CUtlString(this: &targetInfo.szFSDir, string: &this->m_targetInfo.szFSDir);
  v3 = this->m_nSNHandle < 0;
  boot_high = HIDWORD(this->m_targetInfo.boot);
  LODWORD(targetInfo.boot) = this->m_targetInfo.boot;
  HIDWORD(targetInfo.boot) = boot_high;
  if ( !v3 )
  {
    AbandonImageInstallationDialog();
    CPS3TargetConnection::UnregisterInternalEventHandlers(this);
    SNPS3Disconnect(a1: this->m_nSNHandle);
    this->m_nSNHandle = -1;
    this->m_nGamePID = -1;
  }
  CPS3TargetManagerRAII::Reset(this: &this->m_TargetManagerAPIInitializer);
  if ( bReconnectAfter )
    CPS3TargetConnection::ConnectTo(this, target: &targetInfo);
  CPS3TargetList::TargetInfo_t::~TargetInfo_t(this: &targetInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A330
// Name: public: long CPS3TargetConnection::RegisterNotifyDebugStrings(unsigned long (*)(class CUtlString const __near &))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::RegisterNotifyDebugStrings(
        CPS3TargetConnection *this,
        unsigned int (__stdcall *func)(const CUtlString *))
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *v5; // eax

  v3 = CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_TTYHandlerFuncs,
         multilist: false);
  v4 = v3;
  if ( v3 != 0xFFFF )
  {
    CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_TTYHandlerFuncs,
      before: 0xFFFFu,
      elem: v3);
    v5 = &this->m_TTYHandlerFuncs.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
      v5->m_Element = func;
  }
  return this->m_nResultOfRegisteringTTYHandler;
}

//------------------------------------------------------------------------------
// Address: 0x0041A380
// Name: public: bool CPS3TargetConnection::RegisterDMEmulatingNotificationProcessor(char const __near *,unsigned long (*)(char const __near *,unsigned int))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPS3TargetConnection::RegisterDMEmulatingNotificationProcessor(
        CPS3TargetConnection *this,
        const char *pszPrefix,
        unsigned int (__stdcall *func)(const char *, unsigned int))
{
  unsigned __int16 HandlerForPrefix; // ax
  unsigned __int16 v5; // cx
  int v6; // edi
  UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short> *v7; // eax
  int v8; // edi
  UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short> *m_pMemory; // esi
  unsigned __int16 v11; // ax
  int v12; // edi
  __int16 v13; // ax
  UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short> *v14; // eax
  CUtlSymbol v15; // [esp+Ch] [ebp-8h] BYREF
  unsigned int (__stdcall *v16)(const char *, unsigned int); // [esp+10h] [ebp-4h]

  HandlerForPrefix = CPS3TargetConnection::FindHandlerForPrefix(this, pszPrefix);
  v5 = HandlerForPrefix;
  if ( HandlerForPrefix >= this->m_DMNotificationHandlers.m_Memory.m_nAllocationCount
    || HandlerForPrefix > this->m_DMNotificationHandlers.m_LastAlloc.index
    || (v6 = 3 * HandlerForPrefix,
        v7 = this->m_DMNotificationHandlers.m_Memory.m_pMemory,
        v8 = 4 * v6,
        *(unsigned __int16 *)((char *)&v7->m_Previous + v8) == v5)
    && *(unsigned __int16 *)((char *)&v7->m_Next + v8) != v5 )
  {
    CUtlSymbol::CUtlSymbol(this: &v15, pStr: pszPrefix);
    v16 = func;
    v11 = CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::AllocInternal(
            this: &this->m_DMNotificationHandlers,
            multilist: false);
    v12 = v11;
    if ( v11 == 0xFFFF )
    {
      v13 = -1;
    }
    else
    {
      CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::LinkBefore(
        this: &this->m_DMNotificationHandlers,
        before: 0xFFFFu,
        elem: v11);
      v14 = &this->m_DMNotificationHandlers.m_Memory.m_pMemory[v12];
      if ( v14 != nullptr )
      {
        v14->m_Element.m_sPrefix = v15;
        v14->m_Element.m_func = v16;
      }
      v13 = v12;
    }
    return v13 != -1;
  }
  else
  {
    _Warning(a1: "Tried to register two notification handlers for %s\n", pszPrefix);
    CUtlSymbol::CUtlSymbol(this: &v15, pStr: pszPrefix);
    m_pMemory = this->m_DMNotificationHandlers.m_Memory.m_pMemory;
    v16 = func;
    *(CUtlSymbol *)((char *)&m_pMemory->m_Element.m_sPrefix + v8) = v15;
    *(unsigned int (__stdcall **)(const char *, unsigned int))((char *)&m_pMemory->m_Element.m_func + v8) = v16;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A480
// Name: public: void CUtlLinkedList<struct CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::Remove(
        CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int> > *this,
        int elem)
{
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *v3; // ebx

  CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::Unlink(
    this,
    elem);
  v3 = (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Memory.m_pMemory[elem];
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: v3);
  v3[1].m_Size = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041A4B0
// Name: public: CPS3TargetConnection::CPS3TargetConnection(void)
// Source: json
//------------------------------------------------------------------------------
CPS3TargetConnection *__thiscall CPS3TargetConnection::CPS3TargetConnection(CPS3TargetConnection *this)
{
  int inited; // eax
  UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short> *m_pMemory; // edx
  char pDest[1024]; // [esp+Ch] [ebp-404h] BYREF
  const char *v6; // [esp+40Ch] [ebp-4h] BYREF

  this->m_lIncomingBCMs.m_Memory.m_pMemory = nullptr;
  this->m_lIncomingBCMs.m_Memory.m_nAllocationCount = 2;
  this->m_lIncomingBCMs.m_Memory.m_nGrowSize = 0;
  this->m_lIncomingBCMs.m_Memory.m_pMemory = (UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 72);
  this->m_lIncomingBCMs.m_LastAlloc.index = -1;
  this->m_lIncomingBCMs.m_pElements = this->m_lIncomingBCMs.m_Memory.m_pMemory;
  this->m_lIncomingBCMs.m_Head = -1;
  this->m_lIncomingBCMs.m_Tail = -1;
  this->m_lIncomingBCMs.m_FirstFree = -1;
  this->m_lIncomingBCMs.m_ElementCount = 0;
  this->m_lIncomingBCMs.m_NumAlloced = 0;
  this->m_nSNHandle = -1;
  this->m_targetInfo.hTarget = -1;
  CUtlString::CUtlString(this: &this->m_targetInfo.szName);
  CUtlString::CUtlString(this: &this->m_targetInfo.szType);
  CUtlString::CUtlString(this: &this->m_targetInfo.szInfo);
  CUtlString::CUtlString(this: &this->m_targetInfo.szHomeDir);
  CUtlString::CUtlString(this: &this->m_targetInfo.szFSDir);
  inited = SNPS3InitTargetComms();
  this->m_TargetManagerAPIInitializer.m_nInitResult = inited;
  if ( inited != 0 )
  {
    v6 = "<unknown>";
    SNPS3TranslateError(a1: inited, a2: &v6);
    V_snprintf(pDest, maxLen: 1024, pFormat: "Could not connect to target manager: %s", v6);
    MessageBoxA(hWnd: nullptr, lpText: pDest, lpCaption: "Connection Failure", uType: 0x10u);
  }
  this->m_nGamePID = -1;
  this->m_TTYHandlerFuncs.m_Memory.m_nAllocationCount = 4;
  this->m_TTYHandlerFuncs.m_Memory.m_nGrowSize = 4;
  this->m_TTYHandlerFuncs.m_Memory.m_pMemory = nullptr;
  this->m_TTYHandlerFuncs.m_Memory.m_pMemory = (UtlLinkedListElem_t<unsigned long (__stdcall*)(CUtlString const &),unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  this->m_TTYHandlerFuncs.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_TTYHandlerFuncs.m_FirstFree = 0xFFFF;
  this->m_TTYHandlerFuncs.m_pElements = this->m_TTYHandlerFuncs.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_TTYHandlerFuncs.m_Head = -1;
  this->m_TTYHandlerFuncs.m_NumAlloced = 0;
  this->m_DMNotificationHandlers.m_Memory.m_pMemory = nullptr;
  this->m_DMNotificationHandlers.m_Memory.m_nAllocationCount = 0;
  this->m_DMNotificationHandlers.m_Memory.m_nGrowSize = 0;
  this->m_DMNotificationHandlers.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DMNotificationHandlers.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_DMNotificationHandlers.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_DMNotificationHandlers.m_Head = -1;
  this->m_DMNotificationHandlers.m_NumAlloced = 0;
  this->m_DMNotificationHandlers.m_pElements = m_pMemory;
  this->m_pTTYEventMultiplexer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041A630
// Name: public: CPS3TargetConnection::~CPS3TargetConnection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPS3TargetConnection::~CPS3TargetConnection(CPS3TargetConnection *this)
{
  this->m_nResultOfRegisteringTTYHandler = SNPS3CancelTTYEvents(a1: this->m_nSNHandle, a2: -1);
  if ( this->m_pTTYEventMultiplexer != nullptr )
  {
    free(pMem: this->m_pTTYEventMultiplexer);
    this->m_pTTYEventMultiplexer = nullptr;
  }
  if ( this->m_nResultOfRegisteringTTYHandler >= 0 )
    SNPS3UnRegisterCustomProtocol(a1: this->m_nSNHandle, a2: &this->m_nVXProtocol);
  if ( this->m_nSNHandle >= 0 )
  {
    AbandonImageInstallationDialog();
    CPS3TargetConnection::UnregisterInternalEventHandlers(this);
    this->m_nSNHandle = -1;
    this->m_nGamePID = -1;
  }
  CUtlLinkedList<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::DMNotificationEmulator_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_DMNotificationHandlers);
  if ( this->m_DMNotificationHandlers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DMNotificationHandlers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DMNotificationHandlers.m_Memory.m_pMemory);
      this->m_DMNotificationHandlers.m_Memory.m_pMemory = nullptr;
    }
    this->m_DMNotificationHandlers.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<unsigned long (__stdcall *)(CUtlString const &),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned long (__stdcall *)(CUtlString const &),unsigned short>,unsigned short>>::RemoveAll(this: &this->m_TTYHandlerFuncs);
  if ( this->m_TTYHandlerFuncs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_TTYHandlerFuncs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TTYHandlerFuncs.m_Memory.m_pMemory);
      this->m_TTYHandlerFuncs.m_Memory.m_pMemory = nullptr;
    }
    this->m_TTYHandlerFuncs.m_Memory.m_nAllocationCount = 0;
  }
  SNPS3CloseTargetComms();
  CPS3TargetList::TargetInfo_t::~TargetInfo_t(this: &this->m_targetInfo);
  CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::RemoveAll(this: &this->m_lIncomingBCMs);
  if ( this->m_lIncomingBCMs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_lIncomingBCMs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_lIncomingBCMs.m_Memory.m_pMemory);
      this->m_lIncomingBCMs.m_Memory.m_pMemory = nullptr;
    }
    this->m_lIncomingBCMs.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A750
// Name: private: unsigned long CPS3TargetConnection::OnReceivedBinaryContinuationPacket(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPS3TargetConnection::OnReceivedBinaryContinuationPacket(
        CPS3TargetConnection *this,
        const char *pData,
        unsigned int nDataLength)
{
  unsigned int v4; // edi
  int BCMByMsgNum; // ebx
  unsigned int v7; // edi
  unsigned int v8; // ebx
  CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int> > *v9; // ecx
  int v10; // edi
  int v11; // ebx
  int v12; // eax
  int nPrefixLen; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int nPacketNum; // [esp+10h] [ebp-8h] BYREF
  unsigned int nMsgNum; // [esp+14h] [ebp-4h] BYREF
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *pDataa; // [esp+20h] [ebp+8h]

  nPrefixLen = 0;
  if ( sscanf(string: pData, format: "XBCT!FIN%u|%u%n", &nMsgNum, &nPacketNum, &nPrefixLen) > 0 )
  {
    v4 = nMsgNum;
    BCMByMsgNum = CPS3TargetConnection::FindBCMByMsgNum(this, nMsgn: nMsgNum);
    if ( BCMByMsgNum == -1 )
    {
      ConsoleWindowPrintf(rgb: 0x80u, strFormat: "Received FIN for absent message %d, ignoring\n", v4);
      return 1;
    }
    if ( this->m_lIncomingBCMs.m_Memory.m_pMemory[BCMByMsgNum].m_Element.m_NextExpectedPacketNumber != nPacketNum )
    {
      ConsoleWindowPrintf(
        rgb: 0x80u,
        strFormat: "Received out of order FIN %d for message %d(%d), aborting\n",
        nPacketNum,
        nMsgNum,
        this->m_lIncomingBCMs.m_Memory.m_pMemory[BCMByMsgNum].m_Element.m_NextExpectedPacketNumber);
      return 1;
    }
    CPS3TargetConnection::HandleCustomVXMessage(
      this,
      pDataStr: (char *)this->m_lIncomingBCMs.m_Memory.m_pMemory[BCMByMsgNum].m_Element.m_vBytes.m_Memory.m_pMemory,
      uLength: this->m_lIncomingBCMs.m_Memory.m_pMemory[BCMByMsgNum].m_Element.m_vBytes.m_Size);
    CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::Unlink(
      this: &this->m_lIncomingBCMs,
      elem: BCMByMsgNum);
    pDataa = (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_lIncomingBCMs.m_Memory.m_pMemory[BCMByMsgNum];
    CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: pDataa);
    pDataa[1].m_Size = this->m_lIncomingBCMs.m_FirstFree;
    this->m_lIncomingBCMs.m_FirstFree = BCMByMsgNum;
    return 0;
  }
  if ( sscanf(string: pData, format: "XBCT!%d|%d%n", &nMsgNum, &nPacketNum, &nPrefixLen) <= 0 )
  {
    ConsoleWindowPrintf(rgb: 0x80u, strFormat: "Faulty XBCT message %s!\n", pData);
    return 1;
  }
  v7 = nPacketNum;
  if ( nPacketNum == 0 )
  {
    v8 = nMsgNum;
    v10 = CPS3TargetConnection::FindBCMByMsgNum(this, nMsgn: nMsgNum);
    if ( v10 != -1 )
    {
      ConsoleWindowPrintf(
        rgb: 0x80u,
        strFormat: "Received out of order packet %d for message %d(%d), aborting it\n",
        0,
        v8,
        this->m_lIncomingBCMs.m_Memory.m_pMemory[v10].m_Element.m_NextExpectedPacketNumber);
      CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::Remove(
        this: &this->m_lIncomingBCMs,
        elem: v10);
      return 1;
    }
    v11 = CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::AddToTail(this: v9);
    this->m_lIncomingBCMs.m_Memory.m_pMemory[v11].m_Element.m_nMessageID = nMsgNum;
    if ( CPS3TargetConnection::BinaryContinuedMessage_t::AddBytes(
           this: &this->m_lIncomingBCMs.m_Memory.m_pMemory[v11].m_Element,
           pData: &pData[nPrefixLen + 1],
           nDataLength: nDataLength - nPrefixLen - 1,
           nPacketNum) == 0 )
    {
      ConsoleWindowPrintf(
        rgb: 0x80u,
        strFormat: "Received out of order packet %d for message %d(%d), aborting it\n",
        nPacketNum,
        nMsgNum,
        this->m_lIncomingBCMs.m_Memory.m_pMemory[v11].m_Element.m_NextExpectedPacketNumber);
      CUtlLinkedList<CPS3TargetConnection::BinaryContinuedMessage_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPS3TargetConnection::BinaryContinuedMessage_t,int>,int>>::Remove(
        this: &this->m_lIncomingBCMs,
        elem: v11);
      return 1;
    }
    return 0;
  }
  v12 = CPS3TargetConnection::FindBCMByMsgNum(this, nMsgn: nMsgNum);
  if ( v12 != -1 )
    return (CPS3TargetConnection::BinaryContinuedMessage_t::AddBytes(
              this: &this->m_lIncomingBCMs.m_Memory.m_pMemory[v12].m_Element,
              pData: &pData[nPrefixLen + 1],
              nDataLength: nDataLength - nPrefixLen - 1,
              nPacketNum: v7) != 0)
         - 1;
  ConsoleWindowPrintf(
    rgb: 0x80u,
    strFormat: "Received out of order packet %d for absent message %d, aborting it\n",
    v7,
    nMsgNum);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A990
// Name: unsigned long Remote_NotifyBinaryContinuedMessage(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall Remote_NotifyBinaryContinuedMessage(const char *pData, unsigned int nDataLength)
{
  return CPS3TargetConnection::OnReceivedBinaryContinuationPacket(this: &g_PS3CurrentTargetConn, pData, nDataLength);
}

//------------------------------------------------------------------------------
// Address: 0x00439A30
// Name: _dynamic_initializer_for__CPS3TargetList::s_theInvalidTargetInfo__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CPS3TargetList::s_theInvalidTargetInfo__()
{
  CUtlString::CUtlString(this: &CPS3TargetList::s_theInvalidTargetInfo.szName);
  CUtlString::CUtlString(this: &CPS3TargetList::s_theInvalidTargetInfo.szType);
  CUtlString::CUtlString(this: &CPS3TargetList::s_theInvalidTargetInfo.szInfo);
  CUtlString::CUtlString(this: &CPS3TargetList::s_theInvalidTargetInfo.szHomeDir);
  CUtlString::CUtlString(this: &CPS3TargetList::s_theInvalidTargetInfo.szFSDir);
  return atexit(func: dynamic_atexit_destructor_for__CPS3TargetList::s_theInvalidTargetInfo__);
}

//------------------------------------------------------------------------------
// Address: 0x00439BE0
// Name: _dynamic_atexit_destructor_for__CPS3TargetList::s_theInvalidTargetInfo__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CPS3TargetList::s_theInvalidTargetInfo__()
{
  CPS3TargetList::TargetInfo_t::~TargetInfo_t(this: &CPS3TargetList::s_theInvalidTargetInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0040B3B0
// Name: void rc_Helper_UnpackListOfThings<struct xrMaterial_t>(class CUtlVector<struct xrMaterial_t,class CUtlMemory<struct xrMaterial_t,int>> __near &,char __near * const,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl rc_Helper_UnpackListOfThings<xrMaterial_t>(
        CUtlVector<xrMaterial_t,CUtlMemory<xrMaterial_t,int> > *vOutList,
        int pStringIn,
        unsigned int nDataLength)
{
  CUtlVector<xrMaterial_t,CUtlMemory<xrMaterial_t,int> > *v3; // esi
  CUtlVector<xrMaterial_t,CUtlMemory<xrMaterial_t,int> > *v4; // edi
  const char *Token; // eax
  unsigned int v6; // edx
  int v7; // esi
  unsigned int v8; // ecx

  v3 = (CUtlVector<xrMaterial_t,CUtlMemory<xrMaterial_t,int> > *)pStringIn;
  v4 = vOutList;
  vOutList->m_Size = 0;
  vOutList = v3;
  Token = GetToken(ppTokenStream: (char **)&vOutList);
  if ( *Token != 0 )
  {
    sscanf(string: Token, format: "%d", &pStringIn);
    v6 = pStringIn;
    v7 = (char *)v3 - ((char *)&vOutList->m_Memory.m_pMemory + 1);
    vOutList = (CUtlVector<xrMaterial_t,CUtlMemory<xrMaterial_t,int> > *)((char *)vOutList + 1);
    v8 = v7 + nDataLength;
    if ( v7 + nDataLength < 516 * pStringIn )
    {
      v6 = v8 / 0x204;
      pStringIn = v8 / 0x204;
    }
    CUtlVector<xrMaterial_t,CUtlMemory<xrMaterial_t,int>>::EnsureCapacity(this: v4, num: v6);
    CUtlVector<xrMaterial_t,CUtlMemory<xrMaterial_t,int>>::InsertMultipleBefore(
      this: v4,
      elem: v4->m_Size,
      num: pStringIn,
      pToInsert: (const xrMaterial_t *)vOutList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E220
// Name: void rc_Helper_UnpackListOfThings<struct xrModel_t>(class CUtlVector<struct xrModel_t,class CUtlMemory<struct xrModel_t,int>> __near &,char __near * const,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl rc_Helper_UnpackListOfThings<xrModel_t>(
        CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int> > *vOutList,
        int pStringIn,
        unsigned int nDataLength)
{
  CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int> > *v3; // esi
  CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int> > *v4; // edi
  const char *Token; // eax
  int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // ecx

  v3 = (CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int> > *)pStringIn;
  v4 = vOutList;
  vOutList->m_Size = 0;
  vOutList = v3;
  Token = GetToken(ppTokenStream: (char **)&vOutList);
  if ( *Token != 0 )
  {
    sscanf(string: Token, format: "%d", &pStringIn);
    v6 = (char *)v3 - ((char *)&vOutList->m_Memory.m_pMemory + 1);
    vOutList = (CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int> > *)((char *)vOutList + 1);
    v7 = pStringIn;
    v8 = v6 + nDataLength;
    if ( v6 + nDataLength < 296 * pStringIn )
    {
      v7 = v8 / 0x128;
      pStringIn = v8 / 0x128;
    }
    CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int>>::EnsureCapacity(this: v4, num: v7);
    CUtlVector<xrModel_t,CUtlMemory<xrModel_t,int>>::InsertMultipleBefore(
      this: v4,
      elem: v4->m_Size,
      num: pStringIn,
      pToInsert: (const xrModel_t *)vOutList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F340
// Name: void rc_Helper_UnpackListOfThings<struct xrSound_t>(class CUtlVector<struct xrSound_t,class CUtlMemory<struct xrSound_t,int>> __near &,char __near * const,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl rc_Helper_UnpackListOfThings<xrSound_t>(
        CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int> > *vOutList,
        int pStringIn,
        unsigned int nDataLength)
{
  CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int> > *v3; // esi
  CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int> > *v4; // edi
  const char *Token; // eax
  unsigned int v6; // edx
  int v7; // esi
  unsigned int v8; // ecx

  v3 = (CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int> > *)pStringIn;
  v4 = vOutList;
  vOutList->m_Size = 0;
  vOutList = v3;
  Token = GetToken(ppTokenStream: (char **)&vOutList);
  if ( *Token != 0 )
  {
    sscanf(string: Token, format: "%d", &pStringIn);
    v6 = pStringIn;
    v7 = (char *)v3 - ((char *)&vOutList->m_Memory.m_pMemory + 1);
    vOutList = (CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int> > *)((char *)vOutList + 1);
    v8 = v7 + nDataLength;
    if ( v7 + nDataLength < 352 * pStringIn )
    {
      v6 = v8 / 0x160;
      pStringIn = v8 / 0x160;
    }
    CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int>>::EnsureCapacity(this: v4, num: v6);
    CUtlVector<xrSound_t,CUtlMemory<xrSound_t,int>>::InsertMultipleBefore(
      this: v4,
      elem: v4->m_Size,
      num: pStringIn,
      pToInsert: (const xrSound_t *)vOutList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A99E
// Name: _SNPS3TranslateError
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3TranslateError(int a1, int a2)
{
  return _SNPS3TranslateError(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9A4
// Name: _SNPS3CancelFTPEvents
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int SNPS3CancelFTPEvents()
{
  return _SNPS3CancelFTPEvents();
}

//------------------------------------------------------------------------------
// Address: 0x0041A9AA
// Name: _SNPS3GetFileTransferList
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3GetFileTransferList(int a1, int a2, int a3)
{
  return _SNPS3GetFileTransferList(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9B0
// Name: _SNPS3RetryFileTransfer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int SNPS3RetryFileTransfer()
{
  return _SNPS3RetryFileTransfer();
}

//------------------------------------------------------------------------------
// Address: 0x0041A9B6
// Name: _SNPS3RegisterFTPEventHandler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int SNPS3RegisterFTPEventHandler()
{
  return _SNPS3RegisterFTPEventHandler();
}

//------------------------------------------------------------------------------
// Address: 0x0041A9BC
// Name: _SNPS3UploadDirectory
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int SNPS3UploadDirectory()
{
  return _SNPS3UploadDirectory();
}

//------------------------------------------------------------------------------
// Address: 0x0041A9C2
// Name: _SNPS3CloseTargetComms
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int SNPS3CloseTargetComms(void)
{
  return _SNPS3CloseTargetComms();
}

//------------------------------------------------------------------------------
// Address: 0x0041A9C8
// Name: _SNPS3Reset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3Reset(int a1, int a2, int a3)
{
  return _SNPS3Reset(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9CE
// Name: _SNPS3ListTTYStreams
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3ListTTYStreams(int a1, int a2, int a3)
{
  return _SNPS3ListTTYStreams(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9D4
// Name: _SNPS3GetConnectStatus
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3GetConnectStatus(int a1, int a2, int a3)
{
  return _SNPS3GetConnectStatus(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9DA
// Name: _SNPS3GetGamePortDebugIPAddrData
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3GetGamePortDebugIPAddrData(int a1, int a2, int a3)
{
  return _SNPS3GetGamePortDebugIPAddrData(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9E0
// Name: _SNPS3Delete
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3Delete(int a1, int a2)
{
  return _SNPS3Delete(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9E6
// Name: _SNPS3UnRegisterCustomProtocol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3UnRegisterCustomProtocol(int a1, int a2)
{
  return _SNPS3UnRegisterCustomProtocol(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9EC
// Name: _SNPS3CancelTTYEvents
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3CancelTTYEvents(int a1, int a2)
{
  return _SNPS3CancelTTYEvents(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9F2
// Name: _SNPS3Kick
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __fastcall SNPS3Kick(int a1)
{
  return _SNPS3Kick(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9F8
// Name: _SNPS3SendCustomProtocolData
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3SendCustomProtocolData(int a1, int a2, int a3, int a4)
{
  return _SNPS3SendCustomProtocolData(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9FE
// Name: _SNPS3ProcessLoad
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3ProcessLoad(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  return _SNPS3ProcessLoad(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA04
// Name: _SNPS3StatTargetFile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3StatTargetFile(int a1, int a2, int a3)
{
  return _SNPS3StatTargetFile(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA0A
// Name: _SNPS3SetExtraLoadFlags
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3SetExtraLoadFlags(int a1, int a2, int a3, int a4, int a5)
{
  return _SNPS3SetExtraLoadFlags(a1, a2, a3, a4, a5);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA10
// Name: _SNPS3InitTargetComms
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int SNPS3InitTargetComms(void)
{
  return _SNPS3InitTargetComms();
}

//------------------------------------------------------------------------------
// Address: 0x0041AA16
// Name: _SNPS3PickTarget
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3PickTarget(int a1, int a2)
{
  return _SNPS3PickTarget(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA1C
// Name: _SNPS3Disconnect
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3Disconnect(int a1)
{
  return _SNPS3Disconnect(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA22
// Name: _SNPS3DownloadFile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3DownloadFile(int a1, int a2, int a3, int a4)
{
  return _SNPS3DownloadFile(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA28
// Name: _SNPS3GetDirectoryList
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3GetDirectoryList(int a1, int a2, int a3, int a4)
{
  return _SNPS3GetDirectoryList(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA2E
// Name: _SNPS3GetModuleInfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3GetModuleInfo(int a1, int a2, int a3, int a4, int a5)
{
  return _SNPS3GetModuleInfo(a1, a2, a3, a4, a5);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA34
// Name: _SNPS3GetModuleList
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3GetModuleList(int a1, int a2, int a3, int a4)
{
  return _SNPS3GetModuleList(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA3A
// Name: _SNPS3ProcessList
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3ProcessList(int a1, int a2, int a3)
{
  return _SNPS3ProcessList(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA40
// Name: _SNPS3GetUserMemoryStats
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3GetUserMemoryStats(int a1, int a2, int a3)
{
  return _SNPS3GetUserMemoryStats(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA46
// Name: _SNPS3ProcessContinue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3ProcessContinue(int a1, int a2)
{
  return _SNPS3ProcessContinue(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA4C
// Name: _SNPS3ProcessStop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3ProcessStop(int a1, int a2)
{
  return _SNPS3ProcessStop(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA52
// Name: _SNPS3RegisterTTYEventHandler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3RegisterTTYEventHandler(int a1, int a2, int a3, int a4)
{
  return _SNPS3RegisterTTYEventHandler(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA58
// Name: _SNPS3GetTargetInfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3GetTargetInfo(int a1)
{
  return _SNPS3GetTargetInfo(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA5E
// Name: _SNPS3GetTargetFromName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3GetTargetFromName(int a1, int a2)
{
  return _SNPS3GetTargetFromName(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA64
// Name: _SNPS3ProcessGetMemory
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3ProcessGetMemory(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  return _SNPS3ProcessGetMemory(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA6A
// Name: _SNPS3ProcessSetMemory
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3ProcessSetMemory(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  return _SNPS3ProcessSetMemory(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA70
// Name: _SNPS3TriggerCoreDump
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3TriggerCoreDump(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  return _SNPS3TriggerCoreDump(a1, a2, a3, a4, a5, a6, a7, a8);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA76
// Name: _SNPS3RegisterCustomProtocol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3RegisterCustomProtocol(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  return _SNPS3RegisterCustomProtocol(a1, a2, a3, a4, a5, a6, a7, a8);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA7C
// Name: _SNPS3EnumerateTargetsEx
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3EnumerateTargetsEx(int a1, int a2)
{
  return _SNPS3EnumerateTargetsEx(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041AA82
// Name: _SNPS3Connect
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl SNPS3Connect(int a1, int a2)
{
  return _SNPS3Connect(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00439A70
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439AD0
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439B00
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00439B10
// Name: _dynamic_atexit_destructor_for__g_mostRecentlyReceivedScreenshot__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_mostRecentlyReceivedScreenshot__()
{
  if ( g_mostRecentlyReceivedScreenshot.m_Data.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_mostRecentlyReceivedScreenshot.m_Data.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00439B30
// Name: _dynamic_atexit_destructor_for__g_install_FTP__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_install_FTP__()
{
  CProgress *m_pProgressBar; // esi

  if ( g_install_FTP.m_pProgressBar != nullptr )
  {
    if ( g_install_FTP.m_nNumFailures != 0 )
      ConsoleWindowPrintf(
        rgb: 0xFFu,
        strFormat: "UPLOAD ERROR: %d files failed, see target manager for details.\n",
        g_install_FTP.m_nNumFailures);
    SNPS3CancelFTPEvents();
    m_pProgressBar = g_install_FTP.m_pProgressBar;
    if ( g_install_FTP.m_pProgressBar != nullptr )
    {
      CProgress::~CProgress(this: g_install_FTP.m_pProgressBar);
      free(pMem: m_pProgressBar);
    }
    g_install_FTP.m_pProgressBar = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439B90
// Name: _dynamic_atexit_destructor_for__g_install_dvdImages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_install_dvdImages__()
{
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Purge(this: &g_install_dvdImages);
  if ( g_install_dvdImages.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_install_dvdImages.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_install_dvdImages.m_Memory.m_pMemory);
      g_install_dvdImages.m_Memory.m_pMemory = nullptr;
    }
    g_install_dvdImages.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439BF0
// Name: _dynamic_atexit_destructor_for__g_PS3TargetList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PS3TargetList__()
{
  CUtlVector<CPS3TargetList::TargetInfo_t,CUtlMemory<CPS3TargetList::TargetInfo_t,int>>::Purge(this: &g_PS3TargetList.m_Targets);
  if ( g_PS3TargetList.m_Targets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_PS3TargetList.m_Targets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_PS3TargetList.m_Targets.m_Memory.m_pMemory);
      g_PS3TargetList.m_Targets.m_Memory.m_pMemory = nullptr;
    }
    g_PS3TargetList.m_Targets.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439C40
// Name: _dynamic_atexit_destructor_for__g_PS3CurrentTargetConn__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PS3CurrentTargetConn__()
{
  CPS3TargetConnection::~CPS3TargetConnection(this: &g_PS3CurrentTargetConn);
}

//------------------------------------------------------------------------------
// Address: 0x00439C50
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}
