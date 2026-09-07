// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/serverbrowserdialog.cpp
// Functions: 92
// ============================================================

#include "serverbrowser\serverbrowserdialog.h"

//------------------------------------------------------------------------------
// Address: 0x10002D30
// Name: public: void CUtlMemory<struct MatchMakingKeyValuePair_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<MatchMakingKeyValuePair_t,int>::Grow(
        CUtlMemory<MatchMakingKeyValuePair_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MatchMakingKeyValuePair_t *m_pMemory; // edx
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
    v7 = m_nAllocationCount << 9;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MatchMakingKeyValuePair_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MatchMakingKeyValuePair_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F90
// Name: public: void CUtlVector<struct servermaps_t,class CUtlMemory<struct servermaps_t,int>>::Sort(int (*)(struct servermaps_t const __near *,struct servermaps_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<servermaps_t,CUtlMemory<servermaps_t,int>>::Sort(
        CUtlVector<servermaps_t,CUtlMemory<servermaps_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // eax
  char *m_pMemory; // ecx
  int v5; // eax
  int v6; // esi
  int j; // ebx
  __int64 v8; // xmm0_8
  __int64 v9; // xmm1_8
  servermaps_t *v10; // eax
  int i; // [esp+4h] [ebp-4h]

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    m_pMemory = (char *)this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: m_pMemory, num: m_Size, width: 0x10u, comp: pfnCompare);
    }
    else
    {
      v5 = m_Size - 1;
      for ( i = v5; v5 >= 0; i = v5 )
      {
        if ( v5 >= 1 )
        {
          v6 = 1;
          for ( j = v5; j != 0; --j )
          {
            if ( pfnCompare(a1: &this->m_Memory.m_pMemory[v6 - 1], a2: &this->m_Memory.m_pMemory[v6]) < 0 )
            {
              v8 = *(_QWORD *)&this->m_Memory.m_pMemory[v6 - 1].pOriginalName;
              v9 = *(_QWORD *)&this->m_Memory.m_pMemory[v6 - 1].iPanelIndex;
              v10 = &this->m_Memory.m_pMemory[v6];
              *(_QWORD *)&v10[-1].pOriginalName = *(_QWORD *)&v10->pOriginalName;
              *(_QWORD *)&v10[-1].iPanelIndex = *(_QWORD *)&v10->iPanelIndex;
              *(_QWORD *)&v10->pOriginalName = v8;
              *(_QWORD *)&v10->iPanelIndex = v9;
            }
            ++v6;
          }
          v5 = i;
        }
        --v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003030
// Name: public: void CUtlVector<struct serverqualitysort_t,class CUtlMemory<struct serverqualitysort_t,int>>::Sort(int (*)(struct serverqualitysort_t const __near *,struct serverqualitysort_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<serverqualitysort_t,CUtlMemory<serverqualitysort_t,int>>::Sort(
        CUtlVector<serverqualitysort_t,CUtlMemory<serverqualitysort_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // eax
  char *m_pMemory; // ecx
  int v5; // eax
  int v6; // esi
  int j; // ebx
  __int64 v8; // xmm0_8
  serverqualitysort_t *v9; // eax
  int iPlayerCount; // ecx
  int i; // [esp+4h] [ebp-4h]

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    m_pMemory = (char *)this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: m_pMemory, num: m_Size, width: 0xCu, comp: pfnCompare);
    }
    else
    {
      v5 = m_Size - 1;
      for ( i = v5; v5 >= 0; i = v5 )
      {
        if ( v5 >= 1 )
        {
          v6 = 1;
          for ( j = v5; j != 0; --j )
          {
            if ( pfnCompare(a1: &this->m_Memory.m_pMemory[v6 - 1], a2: &this->m_Memory.m_pMemory[v6]) < 0 )
            {
              v8 = *(_QWORD *)&this->m_Memory.m_pMemory[v6 - 1].iIndex;
              v9 = &this->m_Memory.m_pMemory[v6];
              iPlayerCount = v9[-1].iPlayerCount;
              *(_QWORD *)&v9[-1].iIndex = *(_QWORD *)&v9->iIndex;
              v9[-1].iPlayerCount = v9->iPlayerCount;
              *(_QWORD *)&v9->iIndex = v8;
              v9->iPlayerCount = iPlayerCount;
            }
            ++v6;
          }
          v5 = i;
        }
        --v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003E00
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::InsertMultipleBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
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
// Address: 0x100047C0
// Name: public: CUtlVector<struct blacklisted_server_t,class CUtlMemory<struct blacklisted_server_t,int>>::~CUtlVector<struct blacklisted_server_t,class CUtlMemory<struct blacklisted_server_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::~CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this)
{
  bool v2; // sf
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // eax

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
// Address: 0x10004830
// Name: public: int CUtlVector<struct vgui::MessageMapItem_t,class CUtlMemory<struct vgui::MessageMapItem_t,int>>::InsertBefore(int,struct vgui::MessageMapItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *this,
        int elem,
        const vgui::MessageMapItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::MessageMapItem_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004990
// Name: public: int CUtlVector<struct MatchMakingKeyValuePair_t,class CUtlMemory<struct MatchMakingKeyValuePair_t,int>>::InsertBefore(int,struct MatchMakingKeyValuePair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int>>::InsertBefore(
        CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int> > *this,
        int elem,
        const MatchMakingKeyValuePair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  MatchMakingKeyValuePair_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MatchMakingKeyValuePair_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 9);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004A00
// Name: public: int CUtlVector<struct servermaps_t,class CUtlMemory<struct servermaps_t,int>>::InsertBefore(int,struct servermaps_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<servermaps_t,CUtlMemory<servermaps_t,int>>::InsertBefore(
        CUtlVector<servermaps_t,CUtlMemory<servermaps_t,int> > *this,
        int elem,
        const servermaps_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  servermaps_t *m_pMemory; // ecx
  int v7; // eax
  servermaps_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000C850
// Name: public: int CUtlVector<struct blacklisted_server_t,class CUtlMemory<struct blacklisted_server_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::InsertBefore(
        CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  blacklisted_server_t *m_pMemory; // ecx
  int v6; // eax
  blacklisted_server_t *v7; // eax
  netadr_s *p_m_NetAdr; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<blacklisted_server_t,int>::Grow(
      (CUtlMemory<PanelItem_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 84 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    p_m_NetAdr = &v7->m_NetAdr;
    netadr_s::SetIP(this: &v7->m_NetAdr, unIP: 0);
    netadr_s::SetPort(this: p_m_NetAdr, newport: 0);
    netadr_s::SetType(this: p_m_NetAdr, newtype: NA_IP);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000DBA0
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::Sort(int (*)(char __near * const __near *,char __near * const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::Sort(
        CUtlVector<char *,CUtlMemory<char *,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  char *v6; // ecx
  char **v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: (char *)this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6 = this->m_Memory.m_pMemory[j - 1];
            v7 = &this->m_Memory.m_pMemory[j];
            *(v7 - 1) = *v7;
            *v7 = v6;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DC20
// Name: public: void CUtlVector<struct tagentry_t,class CUtlMemory<struct tagentry_t,int>>::Sort(int (*)(struct tagentry_t const __near *,struct tagentry_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<tagentry_t,CUtlMemory<tagentry_t,int>>::Sort(
        CUtlVector<tagentry_t,CUtlMemory<tagentry_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int v4; // ebx
  int j; // esi
  const char *pszTag; // ecx
  int iCount; // edx
  tagentry_t *v8; // eax
  int i; // [esp+8h] [ebp-4h]

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: (char *)this->m_Memory.m_pMemory, num: m_Size, width: 8u, comp: pfnCompare);
    }
    else
    {
      v4 = m_Size - 1;
      for ( i = v4; v4 >= 0; i = v4 )
      {
        for ( j = 1; j <= v4; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            pszTag = this->m_Memory.m_pMemory[j - 1].pszTag;
            iCount = this->m_Memory.m_pMemory[j - 1].iCount;
            v8 = &this->m_Memory.m_pMemory[j];
            v8[-1].pszTag = v8->pszTag;
            v8[-1].iCount = v8->iCount;
            v4 = i;
            v8->pszTag = pszTag;
            v8->iCount = iCount;
          }
        }
        --v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DCB0
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
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
// Address: 0x1000EEC0
// Name: public: void CUtlMemory<class gameserveritem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<gameserveritem_t,int>::Grow(CUtlMemory<gameserveritem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  gameserveritem_t *m_pMemory; // edx
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
    v7 = 372 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (gameserveritem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (gameserveritem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EF60
// Name: public: int CUtlVector<class gameserveritem_t,class CUtlMemory<class gameserveritem_t,int>>::InsertBefore(int,class gameserveritem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<gameserveritem_t,CUtlMemory<gameserveritem_t,int>>::InsertBefore(
        CUtlVector<gameserveritem_t,CUtlMemory<gameserveritem_t,int> > *this,
        int elem,
        const gameserveritem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  gameserveritem_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<gameserveritem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 372 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000EFE0
// Name: public: int CUtlVector<struct netadr_s,class CUtlMemory<struct netadr_s,int>>::InsertBefore(int,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<netadr_s,CUtlMemory<netadr_s,int>>::InsertBefore(
        CUtlVector<netadr_s,CUtlMemory<netadr_s,int> > *this,
        int elem,
        const netadr_s *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  netadr_s *m_pMemory; // ecx
  int v7; // eax
  netadr_s *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10015290
// Name: public: static char const __near * CServerBrowserDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CServerBrowserDialog::GetPanelClassName()
{
  return "CServerBrowserDialog";
}

//------------------------------------------------------------------------------
// Address: 0x100152A0
// Name: public: void CServerBrowserDialog::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::Initialize(CServerBrowserDialog *this)
{
  this->SetTitle_2(this, a2: "#ServerBrowser_Servers", a3: true);
  this->SetVisible(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100152D0
// Name: public: class gameserveritem_t __near * CServerBrowserDialog::GetServer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
gameserveritem_t *__thiscall CServerBrowserDialog::GetServer(CServerBrowserDialog *this, unsigned int serverID)
{
  if ( this->m_pGameList != nullptr )
    return this->m_pGameList->GetServer(this: this->m_pGameList, a2: serverID);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100152F0
// Name: public: void CServerBrowserDialog::Open(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::Open(CServerBrowserDialog *this)
{
  vgui::Frame::Activate(this);
  this->m_pTabPanel->RequestFocus(this: this->m_pTabPanel, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10015310
// Name: public: virtual void CServerBrowserDialog::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::OnTick(CServerBrowserDialog *this)
{
  vgui::AnimationController *AnimationController; // eax
  float currentTime; // [esp+0h] [ebp-4h]

  vgui::PropertyPage::OnPageHide((vgui::PropertyPage *)this);
  currentTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
  AnimationController = vgui::GetAnimationController();
  vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime);
}

//------------------------------------------------------------------------------
// Address: 0x10015340
// Name: public: void CServerBrowserDialog::SaveUserData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::SaveUserData(CServerBrowserDialog *this)
{
  IBaseFileSystem *v2; // eax
  CSpectateGames *m_pSpectateGames; // eax
  IGameList *v4; // eax
  IGameList *m_pGameList; // ecx
  CFavoriteGames *m_pFavorites; // eax
  IGameList *v7; // eax
  CLanGames *m_pLanGames; // eax
  IGameList *v9; // eax
  CFriendsGames *m_pFriendsGames; // eax
  IGameList *v11; // eax
  CHistoryGames *m_pHistory; // eax
  IGameList *v13; // eax
  KeyValues *Key; // eax
  KeyValues *Copy; // eax
  IBaseFileSystem *v16; // eax
  CBlacklistedServers *m_pBlacklist; // ecx

  KeyValues::Clear(this: this->m_pSavedData);
  if ( g_pFullFileSystem != nullptr )
    v2 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v2 = nullptr;
  KeyValues::LoadFromFile(
    this: this->m_pSavedData,
    filesystem: v2,
    resourceName: "ServerBrowser.vdf",
    pathID: "CONFIG",
    pfnEvaluateSymbolProc: nullptr);
  m_pSpectateGames = this->m_pSpectateGames;
  if ( m_pSpectateGames != nullptr )
    v4 = &m_pSpectateGames->IGameList;
  else
    v4 = nullptr;
  m_pGameList = this->m_pGameList;
  if ( m_pGameList == v4 )
  {
    KeyValues::SetString(this: this->m_pSavedData, keyName: "GameList", value: "spectate");
  }
  else
  {
    m_pFavorites = this->m_pFavorites;
    if ( m_pFavorites != nullptr )
      v7 = &m_pFavorites->IGameList;
    else
      v7 = nullptr;
    if ( m_pGameList == v7 )
    {
      KeyValues::SetString(this: this->m_pSavedData, keyName: "GameList", value: "favorites");
    }
    else
    {
      m_pLanGames = this->m_pLanGames;
      if ( m_pLanGames != nullptr )
        v9 = &m_pLanGames->IGameList;
      else
        v9 = nullptr;
      if ( m_pGameList == v9 )
      {
        KeyValues::SetString(this: this->m_pSavedData, keyName: "GameList", value: "lan");
      }
      else
      {
        m_pFriendsGames = this->m_pFriendsGames;
        if ( m_pFriendsGames != nullptr )
          v11 = &m_pFriendsGames->IGameList;
        else
          v11 = nullptr;
        if ( m_pGameList == v11 )
        {
          KeyValues::SetString(this: this->m_pSavedData, keyName: "GameList", value: "friends");
        }
        else
        {
          m_pHistory = this->m_pHistory;
          if ( m_pHistory != nullptr )
            v13 = &m_pHistory->IGameList;
          else
            v13 = nullptr;
          if ( m_pGameList == v13 )
            KeyValues::SetString(this: this->m_pSavedData, keyName: "GameList", value: "history");
          else
            KeyValues::SetString(this: this->m_pSavedData, keyName: "GameList", value: "internet");
        }
      }
    }
  }
  Key = KeyValues::FindKey(this: this->m_pSavedData, keyName: "Filters", bCreate: false);
  KeyValues::RemoveSubKey(this: this->m_pSavedData, subKey: Key);
  Copy = KeyValues::MakeCopy(this: this->m_pFilterData);
  KeyValues::AddSubKey(this: this->m_pSavedData, pSubkey: Copy);
  if ( g_pFullFileSystem != nullptr )
    v16 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v16 = nullptr;
  KeyValues::SaveToFile(this: this->m_pSavedData, filesystem: v16, resourceName: "ServerBrowser.vdf", pathID: "CONFIG");
  m_pBlacklist = this->m_pBlacklist;
  if ( m_pBlacklist != nullptr )
    CBlacklistedServers::SaveBlacklistedList(this: m_pBlacklist);
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x100154A0
// Name: public: void CServerBrowserDialog::RefreshCurrentPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::RefreshCurrentPage(CServerBrowserDialog *this)
{
  if ( this->m_pGameList != nullptr )
    this->m_pGameList->StartRefresh(this: this->m_pGameList);
}

//------------------------------------------------------------------------------
// Address: 0x100154C0
// Name: public: void CServerBrowserDialog::BlacklistsChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CServerBrowserDialog::BlacklistsChanged(CServerBrowserDialog *this@<ecx>, serverdisplay_t *a2@<edi>)
{
  CBaseGamesPage::ApplyGameFilters(this: this->m_pInternetGames, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100154D0
// Name: public: void CServerBrowserDialog::UpdateStatusText(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CServerBrowserDialog::UpdateStatusText(CServerBrowserDialog *this, const char *fmt, ...)
{
  vgui::Label *m_pStatusLabel; // ecx
  char str[1024]; // [esp+4h] [ebp-400h] BYREF
  va_list ap; // [esp+414h] [ebp+10h] BYREF

  va_start(ap, fmt);
  m_pStatusLabel = this->m_pStatusLabel;
  if ( m_pStatusLabel != nullptr )
  {
    if ( fmt != nullptr && strlen(fmt) != 0 )
    {
      _vsnprintf(string: str, count: 0x400u, format: fmt, ap);
      this->m_pStatusLabel->SetText_2(this: this->m_pStatusLabel, a2: str);
    }
    else
    {
      m_pStatusLabel->SetText_2(this: m_pStatusLabel, a2: defaultValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015550
// Name: private: virtual void CServerBrowserDialog::OnGameListChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::OnGameListChanged(CServerBrowserDialog *this)
{
  vgui::Panel *v2; // eax

  v2 = this->m_pTabPanel->GetActivePage(this: this->m_pTabPanel);
  this->m_pGameList = (IGameList *)__RTDynamicCast(
                                     inptr: v2,
                                     VfDelta: 0,
                                     SrcType: &vgui::Panel `RTTI Type Descriptor',
                                     TargetType: &IGameList `RTTI Type Descriptor',
                                     isReference: 0);
  CServerBrowserDialog::UpdateStatusText(this, fmt: defaultValue);
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100155B0
// Name: public: void CServerBrowserDialog::AddServerToFavorites(class gameserveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::AddServerToFavorites(CServerBrowserDialog *this, gameserveritem_t *server)
{
  ISteamMatchmaking *m_pSteamMatchmaking; // esi
  int v3; // eax

  m_pSteamMatchmaking = steamapicontext->m_pSteamMatchmaking;
  if ( m_pSteamMatchmaking != nullptr )
  {
    v3 = _time32(timeptr: nullptr);
    m_pSteamMatchmaking->AddFavoriteGame(
      this: m_pSteamMatchmaking,
      a2: server->m_nAppID,
      a3: server->m_NetAdr.m_unIP,
      a4: server->m_NetAdr.m_usConnectionPort,
      a5: server->m_NetAdr.m_usQueryPort,
      a6: 1u,
      a7: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015600
// Name: public: void CServerBrowserDialog::AddServerToBlacklist(class gameserveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::AddServerToBlacklist(CServerBrowserDialog *this, gameserveritem_t *server)
{
  CBlacklistedServers *m_pBlacklist; // ecx

  m_pBlacklist = this->m_pBlacklist;
  if ( m_pBlacklist != nullptr )
    CBlacklistedServers::AddServer(this: m_pBlacklist, server);
}

//------------------------------------------------------------------------------
// Address: 0x10015620
// Name: public: bool CServerBrowserDialog::IsServerBlacklisted(class gameserveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerBrowserDialog::IsServerBlacklisted(CServerBrowserDialog *this, gameserveritem_t *server)
{
  CBlacklistedServers *m_pBlacklist; // ecx

  m_pBlacklist = this->m_pBlacklist;
  return m_pBlacklist != nullptr && CBlacklistedServers::IsServerBlacklisted(this: m_pBlacklist, server);
}

//------------------------------------------------------------------------------
// Address: 0x10015640
// Name: public: class CServerContextMenu __near * CServerBrowserDialog::GetContextMenu(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CServerContextMenu *__thiscall CServerBrowserDialog::GetContextMenu(CServerBrowserDialog *this, vgui::Panel *pPanel)
{
  CServerContextMenu *m_pContextMenu; // ecx
  CServerContextMenu *v4; // eax
  CServerContextMenu *v5; // eax
  CServerContextMenu_vtbl *v6; // edx

  m_pContextMenu = this->m_pContextMenu;
  if ( m_pContextMenu != nullptr )
    ((void (__thiscall *)(CServerContextMenu *, int))m_pContextMenu->dtr_Panel)(a1: m_pContextMenu, a2: 1);
  v4 = (CServerContextMenu *)operator new(nSize: 0x420u);
  if ( v4 != nullptr )
    v5 = CServerContextMenu::CServerContextMenu(this: v4, parent: this);
  else
    v5 = nullptr;
  this->m_pContextMenu = v5;
  v5->SetAutoDelete(this: v5, a2: false);
  v6 = this->m_pContextMenu->__vftable;
  if ( pPanel != nullptr )
    ((void (__stdcall *)(vgui::Panel *))v6->SetParent_2)(a1: pPanel);
  else
    ((void (__stdcall *)(CServerBrowserDialog *))v6->SetParent_2)(a1: this);
  this->m_pContextMenu->SetVisible(this: this->m_pContextMenu, a2: false);
  return this->m_pContextMenu;
}

//------------------------------------------------------------------------------
// Address: 0x100156D0
// Name: public: class KeyValues __near * CServerBrowserDialog::GetFilterSaveData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CServerBrowserDialog::GetFilterSaveData(CServerBrowserDialog *this, const char *filterSet)
{
  return KeyValues::FindKey(this: this->m_pFilterData, keyName: filterSet, bCreate: true);
}

//------------------------------------------------------------------------------
// Address: 0x100156F0
// Name: public: char const __near * CServerBrowserDialog::GetActiveModName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CServerBrowserDialog::GetActiveModName(CServerBrowserDialog *this)
{
  return this->m_szModDir[0] != 0 ? this->m_szModDir : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10015710
// Name: public: char const __near * CServerBrowserDialog::GetActiveGameName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CServerBrowserDialog::GetActiveGameName(CServerBrowserDialog *this)
{
  return this->m_szGameName[0] != 0 ? this->m_szGameName : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10015730
// Name: public: class CGameID __near & CServerBrowserDialog::GetActiveAppID(void)
// Source: json
//------------------------------------------------------------------------------
CGameID *__thiscall CServerBrowserDialog::GetActiveAppID(CServerBrowserDialog *this)
{
  return &this->m_iLimitAppID;
}

//------------------------------------------------------------------------------
// Address: 0x10015740
// Name: private: void CServerBrowserDialog::ReloadFilterSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::ReloadFilterSettings(CServerBrowserDialog *this)
{
  this->m_pInternetGames->LoadFilterSettings(this: this->m_pInternetGames);
  this->m_pSpectateGames->LoadFilterSettings(this: this->m_pSpectateGames);
  this->m_pFavorites->LoadFilterSettings(this: this->m_pFavorites);
  this->m_pLanGames->LoadFilterSettings(this: this->m_pLanGames);
  this->m_pFriendsGames->LoadFilterSettings(this: this->m_pFriendsGames);
  this->m_pHistory->LoadFilterSettings(this: this->m_pHistory);
}

//------------------------------------------------------------------------------
// Address: 0x100157B0
// Name: private: virtual void CServerBrowserDialog::OnDisconnectFromGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::OnDisconnectFromGame(CServerBrowserDialog *this)
{
  CBlacklistedServers *m_pBlacklist; // ecx

  this->m_bCurrentlyConnected = false;
  memset(dst: (int)&this->m_CurrentConnection, value: nullptr, count: sizeof(this->m_CurrentConnection));
  CFavoriteGames::OnDisconnectFromGame(this: this->m_pFavorites);
  m_pBlacklist = this->m_pBlacklist;
  if ( m_pBlacklist != nullptr )
    CBlacklistedServers::OnDisconnectFromGame(this: m_pBlacklist);
}

//------------------------------------------------------------------------------
// Address: 0x100157F0
// Name: private: virtual void CServerBrowserDialog::ShowServerBrowserPage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::ShowServerBrowserPage(CServerBrowserDialog *this, KeyValues *pMessageValues)
{
  int Int; // edi
  vgui::PropertySheet *m_pTabPanel; // ecx
  vgui::PropertySheet_vtbl *v5; // ebx
  int v6; // eax

  Int = KeyValues::GetInt(this: pMessageValues, keyName: "page", defaultValue: 0);
  if ( Int < 0 || Int >= this->m_pTabPanel->GetNumPages(this: this->m_pTabPanel) )
  {
    DevMsg(a1: "Tried to activate invalid server browser tab %d\n", Int);
  }
  else
  {
    m_pTabPanel = this->m_pTabPanel;
    v5 = m_pTabPanel->__vftable;
    v6 = (int)m_pTabPanel->GetPage(this: m_pTabPanel, a2: Int);
    v5->SetActivePage(this: this->m_pTabPanel, a2: (vgui::Panel *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015870
// Name: private: virtual void CServerBrowserDialog::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::ActivateBuildMode(CServerBrowserDialog *this)
{
  vgui::Panel *v1; // eax
  void *v2; // eax

  v1 = this->m_pTabPanel->GetActivePage(this: this->m_pTabPanel);
  v2 = __RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::EditablePanel `RTTI Type Descriptor',
         isReference: 0);
  if ( v2 != nullptr )
    (*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 860))(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100158B0
// Name: private: virtual bool CServerBrowserDialog::GetDefaultScreenPosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerBrowserDialog::GetDefaultScreenPosition(
        CServerBrowserDialog *this,
        int *x,
        int *y,
        int *wide,
        int *tall)
{
  double v5; // xmm0_8
  __m128i v6; // xmm1
  int wy; // [esp+0h] [ebp-10h] BYREF
  int wt; // [esp+4h] [ebp-Ch] BYREF
  int wx; // [esp+8h] [ebp-8h] BYREF
  int ww; // [esp+Ch] [ebp-4h] BYREF

  g_pVGuiSurface->GetWorkspaceBounds(this: g_pVGuiSurface, a2: &wx, a3: &wy, a4: &ww, a5: &wt);
  v5 = (double)ww;
  v6 = _mm_cvtsi32_si128(wt);
  *x = wx - (int)((double)ww * -0.05);
  *(double *)v6.m128i_i64 = _mm_cvtepi32_pd(v6).m128d_f64[0];
  *y = wy - (int)(*(double *)v6.m128i_i64 * -0.4);
  *wide = (int)(v5 * 0.5);
  *tall = (int)(*(double *)v6.m128i_i64 * 0.55);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015950
// Name: private: virtual void CServerBrowserDialog::SetCustomScheme(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::SetCustomScheme(CServerBrowserDialog *this, KeyValues *pMessageValues)
{
  const char *String; // eax
  const char *v4; // edi
  CServerBrowserDialog_vtbl *v5; // ebx
  unsigned int v6; // eax
  char buffer[260]; // [esp+8h] [ebp-104h] BYREF

  String = KeyValues::GetString(this: pMessageValues, keyName: "SchemeName", defaultValue: nullptr);
  v4 = String;
  if ( String != nullptr )
  {
    V_snprintf(pDest: buffer, maxLen: 260, pFormat: "resource/%s.res", String);
    v5 = this->__vftable;
    v6 = g_pVGuiSchemeManager->LoadSchemeFromFile(this: g_pVGuiSchemeManager, a2: buffer, a3: v4);
    v5->SetScheme(this, a2: v6);
    this->InvalidateLayout(this, a2: true, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100159D0
// Name: class CServerBrowserDialog __near & ServerBrowserDialog(void)
// Source: json
//------------------------------------------------------------------------------
CServerBrowserDialog *__cdecl ServerBrowserDialog()
{
  return s_InternetDlg;
}

//------------------------------------------------------------------------------
// Address: 0x100159E0
// Name: public: void CServerBrowserDialog::LoadUserData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::LoadUserData(CServerBrowserDialog *this)
{
  KeyValues *m_pSavedData; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  IBaseFileSystem *v5; // ecx
  KeyValues *Key; // eax
  KeyValues *v7; // edi
  KeyValues *Copy; // eax
  KeyValues *v9; // ecx
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  CHistoryGames *m_pHistory; // ecx
  CFavoriteGames *m_pFavorites; // ecx
  CBlacklistedServers *m_pBlacklist; // ecx

  m_pSavedData = this->m_pSavedData;
  if ( m_pSavedData != nullptr )
    KeyValues::deleteThis(this: m_pSavedData);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Filters");
  else
    v4 = nullptr;
  this->m_pSavedData = v4;
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  KeyValues::LoadFromFile(
    this: v4,
    filesystem: v5,
    resourceName: "ServerBrowser.vdf",
    pathID: "CONFIG",
    pfnEvaluateSymbolProc: nullptr);
  Key = KeyValues::FindKey(this: this->m_pSavedData, keyName: "Filters", bCreate: false);
  v7 = Key;
  if ( Key != nullptr )
  {
    Copy = KeyValues::MakeCopy(this: Key);
    v9 = this->m_pSavedData;
    this->m_pFilterData = Copy;
    KeyValues::RemoveSubKey(this: v9, subKey: v7);
  }
  else
  {
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "Filters");
    else
      v11 = nullptr;
    this->m_pFilterData = v11;
  }
  m_pHistory = this->m_pHistory;
  if ( m_pHistory != nullptr )
  {
    CHistoryGames::LoadHistoryList(this: m_pHistory);
    if ( this->IsVisible(this) && this->m_pHistory->IsVisible(this: this->m_pHistory) )
      this->m_pHistory->StartRefresh(this: &this->m_pHistory->IGameList);
  }
  m_pFavorites = this->m_pFavorites;
  if ( m_pFavorites != nullptr )
  {
    CFavoriteGames::LoadFavoritesList(this: m_pFavorites);
    CServerBrowserDialog::ReloadFilterSettings(this);
    if ( this->IsVisible(this) && this->m_pFavorites->IsVisible(this: this->m_pFavorites) )
      this->m_pFavorites->StartRefresh(this: &this->m_pFavorites->IGameList);
  }
  m_pBlacklist = this->m_pBlacklist;
  if ( m_pBlacklist != nullptr )
    CBlacklistedServers::LoadBlacklistedList(this: m_pBlacklist);
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10015B60
// Name: private: virtual void CServerBrowserDialog::OnActiveGameName(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::OnActiveGameName(CServerBrowserDialog *this, KeyValues *pKV)
{
  const char *String; // eax
  const char *v4; // eax

  String = KeyValues::GetString(this: pKV, keyName: "name", defaultValue: defaultValue);
  V_strncpy(pDest: this->m_szModDir, pSrc: String, maxLen: 128);
  v4 = KeyValues::GetString(this: pKV, keyName: "game", defaultValue: defaultValue);
  V_strncpy(pDest: this->m_szGameName, pSrc: v4, maxLen: 128);
  this->m_iLimitAppID.m_ulGameID = KeyValues::GetUint64(this: pKV, keyName: "appid", defaultValue: 0);
  CServerBrowserDialog::ReloadFilterSettings(this);
}

//------------------------------------------------------------------------------
// Address: 0x10015BE0
// Name: public: void CServerBrowserDialog::CloseAllGameInfoDialogs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::CloseAllGameInfoDialogs(CServerBrowserDialog *this)
{
  CServerBrowserDialog *v1; // edi
  int v2; // esi
  vgui::Panel *v3; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  vgui::IVGui *v6; // edi
  vgui::IVGui_vtbl *v7; // esi
  int v8; // eax
  int i; // [esp+14h] [ebp-4h]

  v1 = this;
  v2 = 0;
  for ( i = 0; v2 < v1->m_GameInfoDialogs.m_Size; i = v2 )
  {
    v3 = vgui::PHandle::Get(this: &v1->m_GameInfoDialogs.m_Memory.m_pMemory[v2]);
    if ( v3 != nullptr )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "Close");
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = g_pVGui->__vftable;
      v8 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))v3->GetVPanel)(a1: v3, a2: v5, a3: 0, a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v7->PostMessage)(a1: v6, a2: v8);
      v2 = i;
      v1 = this;
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015C70
// Name: public: class CDialogGameInfo __near * CServerBrowserDialog::GetDialogGameInfoForFriend(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CDialogGameInfo *__thiscall CServerBrowserDialog::GetDialogGameInfoForFriend(
        CServerBrowserDialog *this,
        unsigned __int64 ulSteamIDFriend)
{
  int v3; // edi
  CDialogGameInfo *v4; // eax
  CDialogGameInfo *v5; // esi

  v3 = 0;
  if ( this->m_GameInfoDialogs.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (CDialogGameInfo *)vgui::PHandle::Get(this: &this->m_GameInfoDialogs.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && CDialogGameInfo::GetAssociatedFriend(this: v4) == ulSteamIDFriend )
      break;
    if ( ++v3 >= this->m_GameInfoDialogs.m_Size )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10015CD0
// Name: private: virtual void CServerBrowserDialog::OnConnectToGame(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowserDialog::OnConnectToGame(CServerBrowserDialog *this, KeyValues *pMessageValues)
{
  u_long Int; // ebx
  int v5; // eax
  int v6; // edi
  bool v7; // zf
  ISteamMatchmaking *m_pSteamMatchmaking; // ebx
  int v9; // eax
  int v10; // ebx
  KeyValues *v11; // eax
  KeyValues *v12; // ebx
  vgui::IVGui_vtbl *v13; // edi
  int v14; // eax
  CBlacklistedServers *m_pBlacklist; // ecx
  CFriendsGames *m_pFriendsGames; // ecx
  int v17; // edi
  CLanGames *m_pLanGames; // ecx
  CSpectateGames *m_pSpectateGames; // ecx
  CHistoryGames *m_pHistory; // ecx
  CFavoriteGames *m_pFavorites; // ecx
  CInternetGames *m_pInternetGames; // esi
  int queryPort; // [esp+28h] [ebp-14h]
  vgui::IVGui *v24; // [esp+2Ch] [ebp-10h]
  vgui::Panel *dlg; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  u_long unIP; // [esp+38h] [ebp-4h]
  int connectionPort; // [esp+44h] [ebp+8h]

  Int = KeyValues::GetInt(this: pMessageValues, keyName: "ip", defaultValue: 0);
  connectionPort = KeyValues::GetInt(this: pMessageValues, keyName: "connectionport", defaultValue: 0);
  v5 = KeyValues::GetInt(this: pMessageValues, keyName: "queryport", defaultValue: 0);
  v6 = v5;
  queryPort = v5;
  if ( Int != 0 && v5 != 0 )
  {
    unIP = htonl(hostlong: Int);
    memset(dst: (int)&this->m_CurrentConnection, value: nullptr, count: sizeof(this->m_CurrentConnection));
    v7 = this->m_pHistory == nullptr;
    this->m_CurrentConnection.m_NetAdr.m_unIP = unIP;
    this->m_CurrentConnection.m_NetAdr.m_usQueryPort = v6;
    this->m_CurrentConnection.m_NetAdr.m_usConnectionPort = connectionPort;
    if ( !v7 )
    {
      m_pSteamMatchmaking = steamapicontext->m_pSteamMatchmaking;
      if ( m_pSteamMatchmaking != nullptr )
      {
        v9 = _time32(timeptr: nullptr);
        m_pSteamMatchmaking->AddFavoriteGame(
          this: m_pSteamMatchmaking,
          a2: 0,
          a3: unIP,
          a4: connectionPort,
          a5: v6,
          a6: 2u,
          a7: v9);
        this->m_pHistory->m_bRefreshOnListReload = true;
      }
    }
    v10 = 0;
    for ( i = 0; v10 < this->m_GameInfoDialogs.m_Size; i = v10 )
    {
      dlg = vgui::PHandle::Get(this: &this->m_GameInfoDialogs.m_Memory.m_pMemory[v10]);
      if ( dlg != nullptr )
      {
        v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v11 != nullptr )
          v12 = KeyValues::KeyValues(
                  this: v11,
                  setName: "ConnectedToGame",
                  firstKey: "ip",
                  firstValue: unIP,
                  secondKey: "connectionport",
                  secondValue: connectionPort);
        else
          v12 = nullptr;
        KeyValues::SetInt(this: v12, keyName: "queryport", value: v6);
        v13 = g_pVGui->__vftable;
        v24 = g_pVGui;
        v14 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))dlg->GetVPanel)(
                a1: dlg,
                a2: v12,
                a3: 0,
                a4: 0);
        ((void (__thiscall *)(vgui::IVGui *, int))v13->PostMessage)(a1: v24, a2: v14);
        v10 = i;
        v6 = queryPort;
      }
      ++v10;
    }
    CFavoriteGames::OnConnectToGame(this: this->m_pFavorites);
    m_pBlacklist = this->m_pBlacklist;
    if ( m_pBlacklist != nullptr )
      CBlacklistedServers::OnConnectToGame(this: m_pBlacklist);
    m_pFriendsGames = this->m_pFriendsGames;
    v17 = 0;
    this->m_bCurrentlyConnected = true;
    if ( m_pFriendsGames != nullptr )
      v17 = m_pFriendsGames->IsQuickListButtonChecked(this: m_pFriendsGames);
    m_pLanGames = this->m_pLanGames;
    if ( m_pLanGames != nullptr && m_pLanGames->IsQuickListButtonChecked(this: m_pLanGames) )
      v17 |= 2u;
    m_pSpectateGames = this->m_pSpectateGames;
    if ( m_pSpectateGames != nullptr && m_pSpectateGames->IsQuickListButtonChecked(this: m_pSpectateGames) )
      v17 |= 4u;
    m_pHistory = this->m_pHistory;
    if ( m_pHistory != nullptr && m_pHistory->IsQuickListButtonChecked(this: m_pHistory) )
      v17 |= 8u;
    m_pFavorites = this->m_pFavorites;
    if ( m_pFavorites != nullptr && m_pFavorites->IsQuickListButtonChecked(this: m_pFavorites) )
      v17 |= 0x10u;
    m_pInternetGames = this->m_pInternetGames;
    if ( m_pInternetGames != nullptr && m_pInternetGames->IsQuickListButtonChecked(this: m_pInternetGames) )
      v17 |= 0x20u;
    ConVar::SetValue(this: (ConVar *)&sb_quick_list_bit_field.IConVar, value: v17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015F20
// Name: public: int CUtlVector<class vgui::DHANDLE<class CDialogGameInfo>,class CUtlMemory<class vgui::DHANDLE<class CDialogGameInfo>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::DHANDLE<CDialogGameInfo>,CUtlMemory<vgui::DHANDLE<CDialogGameInfo>,int>>::InsertBefore(
        CUtlVector<vgui::DHANDLE<CDialogGameInfo>,CUtlMemory<vgui::DHANDLE<CDialogGameInfo>,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::DHANDLE<CDialogGameInfo> *m_pMemory; // ecx
  int v6; // eax
  vgui::DHANDLE<CDialogGameInfo> *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10015F80
// Name: public: virtual class gameserveritem_t __near * CServerBrowserDialog::GetCurrentConnectedServer(void)
// Source: json
//------------------------------------------------------------------------------
gameserveritem_t *__thiscall CServerBrowserDialog::GetCurrentConnectedServer(CServerBrowserDialog *this)
{
  return &this->m_CurrentConnection;
}

//------------------------------------------------------------------------------
// Address: 0x10015F90
// Name: public: virtual struct vgui::PanelMessageMap __near * CServerBrowserDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CServerBrowserDialog::GetMessageMap(CServerBrowserDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CServerBrowserDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CServerBrowserDialog::GetMessageMap'::`2'::s_pMap;
  `CServerBrowserDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CServerBrowserDialog");
  `CServerBrowserDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015FC0
// Name: public: virtual struct PanelAnimationMap __near * CServerBrowserDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CServerBrowserDialog::GetAnimMap(CServerBrowserDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CServerBrowserDialog");
}

//------------------------------------------------------------------------------
// Address: 0x10015FD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CServerBrowserDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CServerBrowserDialog::GetKBMap(CServerBrowserDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CServerBrowserDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CServerBrowserDialog::GetKBMap'::`2'::s_pMap;
  `CServerBrowserDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CServerBrowserDialog");
  `CServerBrowserDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016000
// Name: public: static void CServerBrowserDialog::PanelMessageFunc_OnGameListChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CServerBrowserDialog::PanelMessageFunc_OnGameListChanged::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CServerBrowserDialog::PanelMessageFunc_OnGameListChanged::InitVar'::`2'::bAdded )
  {
    `CServerBrowserDialog::PanelMessageFunc_OnGameListChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CServerBrowserDialog");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "PageChanged";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016090
// Name: public: static void CServerBrowserDialog::PanelMessageFunc_OnActiveGameName::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CServerBrowserDialog::PanelMessageFunc_OnActiveGameName::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CServerBrowserDialog::PanelMessageFunc_OnActiveGameName::InitVar'::`2'::bAdded )
  {
    `CServerBrowserDialog::PanelMessageFunc_OnActiveGameName::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CServerBrowserDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "ActiveGameName";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016120
// Name: public: static void CServerBrowserDialog::PanelMessageFunc_OnConnectToGame::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CServerBrowserDialog::PanelMessageFunc_OnConnectToGame::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CServerBrowserDialog::PanelMessageFunc_OnConnectToGame::InitVar'::`2'::bAdded )
  {
    `CServerBrowserDialog::PanelMessageFunc_OnConnectToGame::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CServerBrowserDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "ConnectedToGame";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100161B0
// Name: public: static void CServerBrowserDialog::PanelMessageFunc_OnDisconnectFromGame::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CServerBrowserDialog::PanelMessageFunc_OnDisconnectFromGame::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CServerBrowserDialog::PanelMessageFunc_OnDisconnectFromGame::InitVar'::`2'::bAdded )
  {
    `CServerBrowserDialog::PanelMessageFunc_OnDisconnectFromGame::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CServerBrowserDialog");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DisconnectedFromGame";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016240
// Name: public: static void CServerBrowserDialog::PanelMessageFunc_ShowServerBrowserPage::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CServerBrowserDialog::PanelMessageFunc_ShowServerBrowserPage::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CServerBrowserDialog::PanelMessageFunc_ShowServerBrowserPage::InitVar'::`2'::bAdded )
  {
    `CServerBrowserDialog::PanelMessageFunc_ShowServerBrowserPage::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TextEntry::`vcall'{1136,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CServerBrowserDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "ShowServerBrowserPage";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100162D0
// Name: public: static void CServerBrowserDialog::PanelMessageFunc_SetCustomScheme::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CServerBrowserDialog::PanelMessageFunc_SetCustomScheme::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CServerBrowserDialog::PanelMessageFunc_SetCustomScheme::InitVar'::`2'::bAdded )
  {
    `CServerBrowserDialog::PanelMessageFunc_SetCustomScheme::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Button::`vcall'{1140,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CServerBrowserDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "SetCustomScheme";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016360
// Name: public: CServerBrowserDialog::CServerBrowserDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CServerBrowserDialog *__thiscall CServerBrowserDialog::CServerBrowserDialog(
        CServerBrowserDialog *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CBlacklistedServers *v6; // eax
  CBlacklistedServers *v7; // eax
  CCustomGames *v8; // eax
  CCustomGames *v9; // eax
  CFavoriteGames *v10; // eax
  CFavoriteGames *v11; // eax
  CHistoryGames *v12; // eax
  CHistoryGames *v13; // eax
  CSpectateGames *v14; // eax
  CSpectateGames *v15; // eax
  CLanGames *v16; // eax
  CLanGames *v17; // eax
  CFriendsGames *v18; // eax
  CFriendsGames *v19; // eax
  CInternetGames *m_pInternetGames; // eax
  IGameList *v21; // eax
  CServerContextMenu *v22; // eax
  CServerContextMenu *v23; // eax
  vgui::PropertySheet *v24; // eax
  vgui::PropertySheet *v25; // eax
  CBlacklistedServers *m_pBlacklist; // eax
  vgui::Label *v27; // eax
  vgui::Label *v28; // eax
  const char *String; // edi
  vgui::Panel *m_pSpectateGames; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "CServerBrowserDialog", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CServerBrowserDialog_vtbl *)&CServerBrowserDialog::`vftable';
  if ( `CServerBrowserDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CServerBrowserDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CServerBrowserDialog");
    v3->pfnClassName = CServerBrowserDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CServerBrowserDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CServerBrowserDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CServerBrowserDialog");
    v4->pfnClassName = CServerBrowserDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CServerBrowserDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CServerBrowserDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CServerBrowserDialog");
    v5->pfnClassName = CServerBrowserDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CServerBrowserDialog::PanelMessageFunc_OnGameListChanged::InitVar(a1: (int)&savedregs);
  CServerBrowserDialog::PanelMessageFunc_OnActiveGameName::InitVar(a1: (int)&savedregs);
  CServerBrowserDialog::PanelMessageFunc_OnConnectToGame::InitVar(a1: (int)&savedregs);
  CServerBrowserDialog::PanelMessageFunc_OnDisconnectFromGame::InitVar(a1: (int)&savedregs);
  CServerBrowserDialog::PanelMessageFunc_ShowServerBrowserPage::InitVar(a1: (int)&savedregs);
  CServerBrowserDialog::PanelMessageFunc_SetCustomScheme::InitVar(a1: (int)&savedregs);
  this->m_GameInfoDialogs.m_Memory.m_pMemory = nullptr;
  this->m_GameInfoDialogs.m_Memory.m_nAllocationCount = 0;
  this->m_GameInfoDialogs.m_Memory.m_nGrowSize = 0;
  this->m_GameInfoDialogs.m_Size = 0;
  this->m_GameInfoDialogs.m_pElements = nullptr;
  *((_BYTE *)&this->m_iLimitAppID.m_gameID + 3) = 0;
  LODWORD(this->m_iLimitAppID.m_ulGameID) &= 0xFF000000;
  *((_DWORD *)&this->m_iLimitAppID.m_gameID + 1) = 0;
  gameserveritem_t::gameserveritem_t(this: &this->m_CurrentConnection);
  s_InternetDlg = this;
  this->m_szGameName[0] = 0;
  this->m_szModDir[0] = 0;
  this->m_pSavedData = nullptr;
  this->m_pFilterData = nullptr;
  this->m_pFavorites = nullptr;
  this->m_pBlacklist = nullptr;
  this->m_pHistory = nullptr;
  v6 = (CBlacklistedServers *)operator new(nSize: 0x1B8u);
  if ( v6 != nullptr )
    v7 = CBlacklistedServers::CBlacklistedServers(this: v6, parent: this);
  else
    v7 = nullptr;
  this->m_pBlacklist = v7;
  CServerBrowserDialog::LoadUserData(this);
  v8 = (CCustomGames *)operator new(nSize: 0x430u);
  if ( v8 != nullptr )
    v9 = CCustomGames::CCustomGames(this: v8, parent: this);
  else
    v9 = nullptr;
  this->m_pInternetGames = v9;
  v10 = (CFavoriteGames *)operator new(nSize: 0x378u);
  if ( v10 != nullptr )
    v11 = CFavoriteGames::CFavoriteGames(this: v10, parent: this);
  else
    v11 = nullptr;
  this->m_pFavorites = v11;
  v12 = (CHistoryGames *)operator new(nSize: 0x378u);
  if ( v12 != nullptr )
    v13 = CHistoryGames::CHistoryGames(this: v12, parent: this);
  else
    v13 = nullptr;
  this->m_pHistory = v13;
  v14 = (CSpectateGames *)operator new(nSize: 0x398u);
  if ( v14 != nullptr )
    v15 = CSpectateGames::CSpectateGames(this: v14, parent: this);
  else
    v15 = nullptr;
  this->m_pSpectateGames = v15;
  v16 = (CLanGames *)operator new(nSize: 0x390u);
  if ( v16 != nullptr )
    v17 = CLanGames::CLanGames(this: v16, parent: this, bAutoRefresh: true, pCustomResFilename: nullptr);
  else
    v17 = nullptr;
  this->m_pLanGames = v17;
  v18 = (CFriendsGames *)operator new(nSize: 0x378u);
  if ( v18 != nullptr )
    v19 = CFriendsGames::CFriendsGames(this: v18, parent: this);
  else
    v19 = nullptr;
  this->m_pFriendsGames = v19;
  vgui::Panel::SetMinimumSize(this, wide: 640, tall: 384);
  vgui::Panel::SetSize(this, wide: 640, tall: 384);
  m_pInternetGames = this->m_pInternetGames;
  if ( m_pInternetGames != nullptr )
    v21 = &m_pInternetGames->IGameList;
  else
    v21 = nullptr;
  this->m_pGameList = v21;
  v22 = (CServerContextMenu *)operator new(nSize: 0x420u);
  if ( v22 != nullptr )
    v23 = CServerContextMenu::CServerContextMenu(this: v22, parent: this);
  else
    v23 = nullptr;
  this->m_pContextMenu = v23;
  v24 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v24 != nullptr )
    v25 = vgui::PropertySheet::PropertySheet(this: v24, parent: this, panelName: "GameTabs", draggableTabs: false);
  else
    v25 = nullptr;
  this->m_pTabPanel = v25;
  v25->SetTabWidth(this: v25, a2: 72);
  this->m_pTabPanel->AddPage(
    this: this->m_pTabPanel,
    a2: this->m_pInternetGames,
    a3: "#ServerBrowser_InternetTab",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pTabPanel->AddPage(
    this: this->m_pTabPanel,
    a2: this->m_pFavorites,
    a3: "#ServerBrowser_FavoritesTab",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pTabPanel->AddPage(
    this: this->m_pTabPanel,
    a2: this->m_pHistory,
    a3: "#ServerBrowser_HistoryTab",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pTabPanel->AddPage(
    this: this->m_pTabPanel,
    a2: this->m_pSpectateGames,
    a3: "#ServerBrowser_SpectateTab",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pTabPanel->AddPage(
    this: this->m_pTabPanel,
    a2: this->m_pLanGames,
    a3: "#ServerBrowser_LanTab",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pTabPanel->AddPage(
    this: this->m_pTabPanel,
    a2: this->m_pFriendsGames,
    a3: "#ServerBrowser_FriendsTab",
    a4: nullptr,
    a5: false,
    a6: -1);
  m_pBlacklist = this->m_pBlacklist;
  if ( m_pBlacklist != nullptr )
    this->m_pTabPanel->AddPage(
      this: this->m_pTabPanel,
      a2: m_pBlacklist,
      a3: "#ServerBrowser_BlacklistTab",
      a4: nullptr,
      a5: false,
      a6: -1);
  this->m_pTabPanel->AddActionSignalTarget_2(this: this->m_pTabPanel, a2: this);
  v27 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v27 != nullptr )
    v28 = vgui::Label::Label(this: v27, parent: this, panelName: "StatusLabel", text: defaultValue);
  else
    v28 = nullptr;
  this->m_pStatusLabel = v28;
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "Servers/DialogServerBrowser.res",
    dialogID: 0);
  this->m_pStatusLabel->SetText_2(this: this->m_pStatusLabel, a2: defaultValue);
  String = KeyValues::GetString(this: this->m_pSavedData, keyName: "GameList", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: "spectate") == 0 )
  {
    m_pSpectateGames = this->m_pSpectateGames;
LABEL_55:
    this->m_pTabPanel->SetActivePage(this: this->m_pTabPanel, a2: m_pSpectateGames);
    goto LABEL_56;
  }
  if ( _V_stricmp(s1: String, s2: "favorites") != 0 )
  {
    if ( _V_stricmp(s1: String, s2: "history") == 0 )
    {
      m_pSpectateGames = this->m_pHistory;
      goto LABEL_55;
    }
    if ( _V_stricmp(s1: String, s2: "lan") != 0 )
    {
      if ( _V_stricmp(s1: String, s2: "friends") == 0 )
      {
        m_pSpectateGames = this->m_pFriendsGames;
        goto LABEL_55;
      }
      if ( _V_stricmp(s1: String, s2: "blacklist") != 0 )
      {
        m_pSpectateGames = this->m_pInternetGames;
        goto LABEL_55;
      }
      this->m_pTabPanel->SetActivePage(this: this->m_pTabPanel, a2: this->m_pBlacklist);
    }
    else
    {
      this->m_pTabPanel->SetActivePage(this: this->m_pTabPanel, a2: this->m_pLanGames);
    }
  }
  else
  {
    this->m_pTabPanel->SetActivePage(this: this->m_pTabPanel, a2: this->m_pFavorites);
  }
LABEL_56:
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016900
// Name: public: class CDialogGameInfo __near * CServerBrowserDialog::OpenGameInfoDialog(class IGameList __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
gameserveritem_t *__thiscall CServerBrowserDialog::OpenGameInfoDialog(
        CServerBrowserDialog *this,
        IGameList *gameList,
        unsigned int serverIndex)
{
  gameserveritem_t *result; // eax
  CDialogGameInfo *v5; // edi
  CDialogGameInfo *v6; // eax
  CDialogGameInfo *v7; // esi
  unsigned int v8; // eax
  char *ConnectionAddressString; // eax
  int v10; // eax
  IGameList *gameLista; // [esp+10h] [ebp+8h]

  result = gameList->GetServer(this: gameList, a2: serverIndex);
  v5 = (CDialogGameInfo *)result;
  if ( result != nullptr )
  {
    v6 = (CDialogGameInfo *)operator new(nSize: 0x440u);
    if ( v6 != nullptr )
      v7 = CDialogGameInfo::CDialogGameInfo(
             this: v6,
             parent: nullptr,
             serverIP: *(_DWORD *)&v5->vgui::Frame::vgui::EditablePanel::vgui::Panel::m_RegisterClass,
             queryPort: HIWORD(v5->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable),
             connectionPort: (unsigned __int16)v5->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable);
    else
      v7 = nullptr;
    gameLista = (IGameList *)v7->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
    v8 = this->GetVParent(this);
    ((void (__thiscall *)(CDialogGameInfo *, unsigned int))gameLista[41].__vftable)(a1: v7, a2: v8);
    v7->AddActionSignalTarget_2(this: v7, a2: this);
    ConnectionAddressString = (char *)&v5->vgui::Panel + 172;
    if ( *((_BYTE *)&v5->vgui::Panel + 172) == 0 )
      ConnectionAddressString = servernetadr_t::GetConnectionAddressString(this: (servernetadr_t *)v5);
    CDialogGameInfo::Run(this: v7, titleName: ConnectionAddressString);
    v10 = CUtlVector<vgui::DHANDLE<CDialogGameInfo>,CUtlMemory<vgui::DHANDLE<CDialogGameInfo>,int>>::InsertBefore(
            this: &this->m_GameInfoDialogs,
            elem: this->m_GameInfoDialogs.m_Size);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_GameInfoDialogs.m_Memory.m_pMemory[v10],
      pPanel: (CDragDropHelperPanel *)v7);
    return (gameserveritem_t *)v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100169D0
// Name: public: class CDialogGameInfo __near * CServerBrowserDialog::OpenGameInfoDialog(int,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
CDialogGameInfo *__thiscall CServerBrowserDialog::OpenGameInfoDialog(
        CServerBrowserDialog *this,
        unsigned int serverIP,
        unsigned __int16 connPort,
        unsigned __int16 queryPort)
{
  CDialogGameInfo *v5; // eax
  CDialogGameInfo *v6; // esi
  CDialogGameInfo_vtbl *v7; // ebx
  unsigned int v8; // eax
  int v9; // eax

  v5 = (CDialogGameInfo *)operator new(nSize: 0x440u);
  if ( v5 != nullptr )
    v6 = CDialogGameInfo::CDialogGameInfo(this: v5, parent: nullptr, serverIP, queryPort, connectionPort: connPort);
  else
    v6 = nullptr;
  v6->AddActionSignalTarget_2(this: v6, a2: this);
  v7 = v6->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
  v8 = this->GetVParent(this);
  v7->SetParent(this: v6, a2: v8);
  CDialogGameInfo::Run(this: v6, titleName: defaultValue);
  v9 = CUtlVector<vgui::DHANDLE<CDialogGameInfo>,CUtlMemory<vgui::DHANDLE<CDialogGameInfo>,int>>::InsertBefore(
         this: &this->m_GameInfoDialogs,
         elem: this->m_GameInfoDialogs.m_Size);
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_GameInfoDialogs.m_Memory.m_pMemory[v9],
    pPanel: (CDragDropHelperPanel *)v6);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10016A70
// Name: void GetMostCommonQueryPorts(class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetMostCommonQueryPorts(CUtlMemory<wchar_t,int> *ports)
{
  int v2; // eax
  int m_pMemory; // edi
  __int16 v4; // bx
  unsigned __int16 v5; // cx
  int m_nAllocationCount; // eax
  unsigned __int16 *v7; // ecx
  int v8; // eax
  unsigned __int16 *v9; // eax
  int v10; // edi
  int v11; // eax
  unsigned __int16 v12; // bx
  unsigned __int16 *v13; // ecx
  int v14; // eax
  unsigned __int16 *v15; // eax
  int v16; // edi
  int v17; // eax
  unsigned __int16 *v18; // ecx
  int v19; // eax
  unsigned __int16 *v20; // edi
  int v21; // edi
  int v22; // eax
  unsigned __int16 *v23; // ecx
  int v24; // eax
  unsigned __int16 *v25; // edi
  int i; // [esp+Ch] [ebp-4h]
  unsigned __int16 portsa; // [esp+18h] [ebp+8h]

  LOWORD(v2) = 0;
  i = 0;
  do
  {
    m_pMemory = (int)ports[1].m_pMemory;
    v4 = v2;
    v5 = v2 + 27015;
    m_nAllocationCount = ports->m_nAllocationCount;
    portsa = v5;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<wchar_t,int>::Grow(this: ports, num: m_pMemory - m_nAllocationCount + 1);
    ++ports[1].m_pMemory;
    v7 = ports->m_pMemory;
    v8 = (int)ports[1].m_pMemory - m_pMemory - 1;
    ports[1].m_nAllocationCount = (int)ports->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 2 * v8);
    v9 = &ports->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
      *v9 = portsa;
    v10 = (int)ports[1].m_pMemory;
    v11 = ports->m_nAllocationCount;
    v12 = v4 + 26900;
    if ( v10 + 1 > v11 )
      CUtlMemory<wchar_t,int>::Grow(this: ports, num: v10 - v11 + 1);
    ++ports[1].m_pMemory;
    v13 = ports->m_pMemory;
    v14 = (int)ports[1].m_pMemory - v10 - 1;
    ports[1].m_nAllocationCount = (int)ports->m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 2 * v14);
    v15 = &ports->m_pMemory[v10];
    if ( v15 != nullptr )
      *v15 = v12;
    v2 = i + 1;
    i = v2;
  }
  while ( v2 <= 5 );
  v16 = (int)ports[1].m_pMemory;
  v17 = ports->m_nAllocationCount;
  if ( v16 + 1 > v17 )
    CUtlMemory<wchar_t,int>::Grow(this: ports, num: v16 - v17 + 1);
  v18 = ports->m_pMemory;
  v19 = (int)++ports[1].m_pMemory - v16 - 1;
  ports[1].m_nAllocationCount = (int)v18;
  if ( v19 > 0 )
    _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 2 * v19);
  v20 = &ports->m_pMemory[v16];
  if ( v20 != nullptr )
    *v20 = 4242;
  v21 = (int)ports[1].m_pMemory;
  v22 = ports->m_nAllocationCount;
  if ( v21 + 1 > v22 )
    CUtlMemory<wchar_t,int>::Grow(this: ports, num: v21 - v22 + 1);
  ++ports[1].m_pMemory;
  v23 = ports->m_pMemory;
  v24 = (int)ports[1].m_pMemory - v21 - 1;
  ports[1].m_nAllocationCount = (int)ports->m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: 2 * v24);
  v25 = &ports->m_pMemory[v21];
  if ( v25 != nullptr )
    *v25 = 27215;
}

//------------------------------------------------------------------------------
// Address: 0x10016C00
// Name: public: class CDialogGameInfo __near * CServerBrowserDialog::JoinGame(class IGameList __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
gameserveritem_t *__thiscall CServerBrowserDialog::JoinGame(
        CServerBrowserDialog *this,
        IGameList *gameList,
        unsigned int serverIndex)
{
  gameserveritem_t *v3; // esi

  v3 = CServerBrowserDialog::OpenGameInfoDialog(this, gameList, serverIndex);
  CDialogGameInfo::Connect(this: (CDialogGameInfo *)v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10016C30
// Name: public: class CDialogGameInfo __near * CServerBrowserDialog::JoinGame(int,int)
// Source: json
//------------------------------------------------------------------------------
CDialogGameInfo *__thiscall CServerBrowserDialog::JoinGame(
        CServerBrowserDialog *this,
        unsigned int serverIP,
        unsigned __int16 serverPort)
{
  CDialogGameInfo *v3; // esi

  v3 = CServerBrowserDialog::OpenGameInfoDialog(this, serverIP, connPort: serverPort, queryPort: serverPort);
  CDialogGameInfo::Connect(this: v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10024E10
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::AddToTail(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10030C20
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertBefore(int,struct vgui::BoundKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        const vgui::BoundKey_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v7; // eax
  vgui::BoundKey_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    vgui::BoundKey_t::BoundKey_t(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10030C90
// Name: public: int CUtlVector<struct PanelAnimationMapEntry,class CUtlMemory<struct PanelAnimationMapEntry,int>>::InsertBefore(int,struct PanelAnimationMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
        CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *this,
        int elem,
        const PanelAnimationMapEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelAnimationMapEntry *m_pMemory; // ecx
  int v7; // eax
  PanelAnimationMapEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10030D20
// Name: public: int CUtlVector<struct vgui::OverridableColorEntry,class CUtlMemory<struct vgui::OverridableColorEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
        CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::OverridableColorEntry *m_pMemory; // ecx
  int v6; // eax
  vgui::OverridableColorEntry *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_colFromScript = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1003D500
// Name: public: int CUtlVector<struct vgui::AnimationController::ActiveAnimation_t,class CUtlMemory<struct vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::ActiveAnimation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->panel.m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1003D580
// Name: public: int CUtlVector<struct vgui::AnimationController::RanEvent_t,class CUtlMemory<struct vgui::AnimationController::RanEvent_t,int>>::InsertBefore(int,struct vgui::AnimationController::RanEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *this,
        int elem,
        const vgui::PropertySheet::Page_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PropertySheet::Page_t *m_pMemory; // ecx
  int v7; // eax
  vgui::PropertySheet::Page_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::RanEvent_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1003E800
// Name: public: int CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::AnimSequence_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::AnimSequence_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::AnimSequence_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->cmdList.m_Memory.m_pMemory = nullptr;
    v7->cmdList.m_Memory.m_nAllocationCount = 0;
    v7->cmdList.m_Memory.m_nGrowSize = 0;
    v7->cmdList.m_Size = 0;
    v7->cmdList.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1003E890
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::Remove(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this,
        int elem)
{
  int v3; // eax

  CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::~CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Memory.m_pMemory[elem].cmdList);
  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 28 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1003E8F0
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 28 * v1;
    v6 = 28 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 5) = 0;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( *((_DWORD *)v3 + 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 2));
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      v4 = *((void **)v3 + 2);
      *((_DWORD *)v3 + 6) = v4;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      --v1;
      v2 -= 28;
      v6 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F7D0
// Name: public: CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  bool v2; // sf
  vgui::AnimationController::AnimSequence_t *m_pMemory; // eax

  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
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
// Address: 0x10044A40
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::RemoveMultiple(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 2 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x100464A0
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::EnsureCapacity(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int num)
{
  wchar_t *m_pMemory; // edx
  unsigned int v4; // eax
  wchar_t *v5; // eax

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
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046B00
// Name: public: int CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10054CC0
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054D30
// Name: public: int CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::InsertBefore(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::FileData_t *m_pMemory; // ecx
  int v6; // eax
  vgui::FileData_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::FileData_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 288 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_FileAttributes);
    CUtlString::CUtlString(this: &v7->m_CreationTime);
    CUtlString::CUtlString(this: &v7->m_LastAccessTime);
    CUtlString::CUtlString(this: &v7->m_LastWriteTime);
    CUtlString::CUtlString(this: &v7->m_FileName);
    CUtlString::CUtlString(this: &v7->m_FullPath);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10055C90
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
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
// Address: 0x10055CF0
// Name: public: void CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::Purge(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  vgui::FileData_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      vgui::FileData_t::~FileData_t(this: &this->m_Memory.m_pMemory[v3--]);
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
// Address: 0x1005DFB0
// Name: public: void CUtlVector<struct vgui::PropertySheet::Page_t,class CUtlMemory<struct vgui::PropertySheet::Page_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int>>::Remove(
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 8 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1005DFF0
// Name: public: int CUtlVector<class vgui::PageTab __near *,class CUtlMemory<class vgui::PageTab __near *,int>>::Find(class vgui::PageTab __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int>>::Find(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        vgui::PageTab **src)
{
  int m_Size; // edx
  int result; // eax
  vgui::PageTab **i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005E020
// Name: public: void CUtlVector<class vgui::PageTab __near *,class CUtlMemory<class vgui::PageTab __near *,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int>>::Remove(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 4 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1005E4E0
// Name: public: int CUtlVector<class vgui::PageTab __near *,class CUtlMemory<class vgui::PageTab __near *,int>>::InsertBefore(int,class vgui::PageTab __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int>>::InsertBefore(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        int elem,
        vgui::PageTab **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PageTab **m_pMemory; // ecx
  int v7; // eax
  vgui::PageTab **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1006A0E0
// Name: public: int CUtlVector<struct vgui::RichText::TFormatStream,class CUtlMemory<struct vgui::RichText::TFormatStream,int>>::InsertBefore(int,struct vgui::RichText::TFormatStream const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int>>::InsertBefore(
        CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int> > *this,
        int elem,
        const vgui::RichText::TFormatStream *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // ecx
  int v7; // eax
  vgui::RichText::TFormatStream *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1006FF80
// Name: public: bool CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::FindAndRemove(class vgui::PHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // ebx
  vgui::TreeNode **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10071270
// Name: public: int CUtlVector<class vgui::TreeNode __near *,class CUtlMemory<class vgui::TreeNode __near *,int>>::AddToHead(class vgui::TreeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::AddToHead(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::TreeNode **m_pMemory; // eax
  int v6; // ecx
  vgui::TreeNode **v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v6);
  v7 = this->m_Memory.m_pMemory;
  if ( v7 != nullptr )
    *v7 = *src;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10073350
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // edx
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073910
// Name: public: int CUtlVector<class vgui::CTreeViewListControl::CColumnInfo,class CUtlMemory<class vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Title.m_Id = -1;
          v11->m_ciFlags = 0;
          v11->m_Right = 0;
          v11->m_Left = 0;
          v11->m_Width = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100757D0
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x10076DB0
// Name: public: int CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::InsertMultipleBefore(
        CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PHandle *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::PHandle *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_iPanelID = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10077390
// Name: public: int CUtlVector<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::RanEvent_t,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100796F0
// Name: public: void CUtlMemory<struct blacklisted_server_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<blacklisted_server_t,int>::Grow(CUtlMemory<PanelItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  PanelItem_t *m_pMemory; // edx
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
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
