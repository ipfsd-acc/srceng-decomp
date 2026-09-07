// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dedicated/vgui/createmultiplayergameserverpage.cpp
// Functions: 85
// ============================================================

#include "dedicated\vgui\createmultiplayergameserverpage.h"

//------------------------------------------------------------------------------
// Address: 0x10001AE0
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::Purge(CUtlVector<char,CUtlMemory<char,int> > *this)
{
  bool v2; // sf
  char *m_pMemory; // ecx

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v2 )
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
// Address: 0x10008E40
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::Find(int const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::Find(CUtlVector<int,CUtlMemory<int,int> > *this, const int *src)
{
  int m_Size; // edx
  int result; // eax
  int *i; // ecx

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
// Address: 0x10008E70
// Name: public: void CUtlVector<class CBaseFileSystem::COpenedFile,class CUtlMemory<class CBaseFileSystem::COpenedFile,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int>>::Remove(
        CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int> > *this,
        int elem)
{
  int v3; // eax

  free(pMem: this->m_Memory.m_pMemory[elem].m_pName);
  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 8 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10008F50
// Name: public: void CUtlVector<class CBaseFileSystem::COpenedFile,class CUtlMemory<class CBaseFileSystem::COpenedFile,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int>>::Purge(
        CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int> > *this)
{
  int i; // edi
  CBaseFileSystem::COpenedFile *m_pMemory; // ecx

  for ( i = this->m_Size - 1; i >= 0; --i )
    free(pMem: this->m_Memory.m_pMemory[i].m_pName);
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
// Address: 0x100096C0
// Name: public: int CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::InsertMultipleBefore(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CBaseFileSystem::CSearchPath *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CBaseFileSystem::CSearchPath *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CBaseFileSystem::CSearchPath::CSearchPath(this: v12);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1000B3E0
// Name: public: void CUtlVector<class CZipPackFile::CPackFileEntry,class CUtlMemory<class CZipPackFile::CPackFileEntry,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::EnsureCapacity(
        CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int> > *this,
        int num)
{
  CZipPackFile::CPackFileEntry *m_pMemory; // edx
  unsigned int v4; // eax
  CZipPackFile::CPackFileEntry *v5; // eax

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
    v4 = 20 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CZipPackFile::CPackFileEntry *)_g_pMemAlloc->Realloc_2(
                                                                   this: _g_pMemAlloc,
                                                                   a2: m_pMemory,
                                                                   a3: v4);
      goto LABEL_5;
    }
    v5 = (CZipPackFile::CPackFileEntry *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B4E0
// Name: public: int CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::InsertBefore(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBaseFileSystem::CSearchPath *m_pMemory; // ecx
  int v6; // eax
  CBaseFileSystem::CSearchPath *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CBaseFileSystem::CSearchPath::CSearchPath(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000B550
// Name: public: void CUtlVector<class CBaseFileSystem::CPathIDInfo __near *,class CUtlMemory<class CBaseFileSystem::CPathIDInfo __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::CPathIDInfo *,CUtlMemory<CBaseFileSystem::CPathIDInfo *,int>>::PurgeAndDeleteElements(
        CUtlVector<CBaseFileSystem::CPathIDInfo *,CUtlMemory<CBaseFileSystem::CPathIDInfo *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CBaseFileSystem::CPathIDInfo **m_pMemory; // ecx

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
// Address: 0x1000B5C0
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::InsertBefore(int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPackedStore *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x1000B630
// Name: public: int CUtlVector<class CBaseFileSystem::COpenedFile,class CUtlMemory<class CBaseFileSystem::COpenedFile,int>>::InsertBefore(int,class CBaseFileSystem::COpenedFile const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int>>::InsertBefore(
        CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int> > *this,
        int elem,
        const CBaseFileSystem::COpenedFile *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBaseFileSystem::COpenedFile *m_pMemory; // ecx
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<__int64,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  CopyConstruct<CBaseFileSystem::COpenedFile>(pMemory: &this->m_Memory.m_pMemory[elem], src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000B6A0
// Name: public: int CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>>::InsertBefore(int,class CStoreIDEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>>::InsertBefore(
        CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *this,
        int elem,
        const CStoreIDEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CStoreIDEntry *m_pMemory; // ecx
  int v7; // eax
  CStoreIDEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<__int64,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
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
// Address: 0x1000B710
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  CUtlString *v8; // ecx

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
    CUtlString::CUtlString(this: v8, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000BE40
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
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
// Address: 0x1000BEB0
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
    CUtlMemory<CPackedStore *,int>::Grow(
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
// Address: 0x1000BF20
// Name: public: void CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::RemoveAll(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CPackFile *m_pPackFile; // esi
  CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *v4; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      m_pPackFile = this->m_Memory.m_pMemory[v2].m_pPackFile;
      if ( m_pPackFile != nullptr && _InterlockedDecrement(&m_pPackFile->m_iRefs) == 0 )
      {
        if ( m_pPackFile->OnFinalRelease(this: m_pPackFile) )
          ((void (__thiscall *)(CPackFile *, int))m_pPackFile->dtr_CRefCountServiceBase<1,CRefMT>)(
            a1: m_pPackFile,
            a2: 1);
        this = v4;
      }
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D040
// Name: public: void CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::FastRemove(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this,
        int elem)
{
  int v3; // esi
  CPackFile *m_pPackFile; // ebx
  int m_Size; // eax
  CBaseFileSystem::CSearchPath *m_pMemory; // ecx
  __int64 v7; // xmm0_8
  CBaseFileSystem::CSearchPath *v8; // eax

  v3 = elem;
  m_pPackFile = this->m_Memory.m_pMemory[elem].m_pPackFile;
  if ( m_pPackFile != nullptr
    && _InterlockedDecrement(&m_pPackFile->m_iRefs) == 0
    && m_pPackFile->OnFinalRelease(this: m_pPackFile) )
  {
    ((void (__thiscall *)(CPackFile *, int))m_pPackFile->dtr_CRefCountServiceBase<1,CRefMT>)(a1: m_pPackFile, a2: 1);
  }
  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v7 = *(_QWORD *)&this->m_Memory.m_pMemory[m_Size - 1].m_storeId;
      v8 = &this->m_Memory.m_pMemory[m_Size - 1];
      *(_QWORD *)&m_pMemory[elem].m_storeId = v7;
      *(_QWORD *)&m_pMemory[v3].m_bIsDvdDevPath = *(_QWORD *)&v8->m_bIsDvdDevPath;
      *(_QWORD *)&m_pMemory[v3].m_pPackFile = *(_QWORD *)&v8->m_pPackFile;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D0D0
// Name: public: void CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::Remove(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this,
        int elem)
{
  CPackFile *m_pPackFile; // ebx

  m_pPackFile = this->m_Memory.m_pMemory[elem].m_pPackFile;
  if ( m_pPackFile != nullptr
    && _InterlockedDecrement(&m_pPackFile->m_iRefs) == 0
    && m_pPackFile->OnFinalRelease(this: m_pPackFile) )
  {
    ((void (__thiscall *)(CPackFile *, int))m_pPackFile->dtr_CRefCountServiceBase<1,CRefMT>)(a1: m_pPackFile, a2: 1);
  }
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 24 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1000EED0
// Name: public: CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::~CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::~CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this)
{
  bool v2; // sf
  CBaseFileSystem::CSearchPath *m_pMemory; // eax

  CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::RemoveAll(this);
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
// Address: 0x1000F000
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
// Address: 0x1000F350
// Name: public: class CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>> __near & CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::operator=(class CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *__thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::operator=(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this,
        const CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *other)
{
  int m_Size; // ebx
  int v4; // esi
  int i; // edx
  CBaseFileSystem::CSearchPath *v6; // eax
  CBaseFileSystem::CSearchPath *v7; // ecx

  m_Size = other->m_Size;
  CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::RemoveAll(this);
  CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::InsertMultipleBefore(
    this,
    elem: this->m_Size,
    num: m_Size);
  if ( m_Size > 0 )
  {
    v4 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v6 = &other->m_Memory.m_pMemory[v4];
      v7 = &this->m_Memory.m_pMemory[v4];
      v7->m_storeId = v6->m_storeId;
      v7->m_pPathIDInfo = v6->m_pPathIDInfo;
      v7->m_bIsDvdDevPath = v6->m_bIsDvdDevPath;
      v7->m_Path.m_Id = v6->m_Path.m_Id;
      v7->m_pDebugPath = v6->m_pDebugPath;
      v7->m_pPackFile = v6->m_pPackFile;
      ++v4;
      v7->m_bIsLocalizedPath = v6->m_bIsLocalizedPath;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC20
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
// Address: 0x1001BDD0
// Name: public: void CUtlMemory<struct CDirectoryEntryInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDirectoryEntryInfo_t,int>::Grow(CUtlMemory<CDirectoryEntryInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDirectoryEntryInfo_t *m_pMemory; // edx
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
    v7 = 260 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDirectoryEntryInfo_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CDirectoryEntryInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C870
// Name: public: int CUtlVector<struct CDirectoryEntryInfo_t,class CUtlMemory<struct CDirectoryEntryInfo_t,int>>::InsertBefore(int,struct CDirectoryEntryInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDirectoryEntryInfo_t,CUtlMemory<CDirectoryEntryInfo_t,int>>::InsertBefore(
        CUtlVector<CDirectoryEntryInfo_t,CUtlMemory<CDirectoryEntryInfo_t,int> > *this,
        int elem,
        const CDirectoryEntryInfo_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDirectoryEntryInfo_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDirectoryEntryInfo_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 260 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020FF0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CFileInfo __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *m_pMemory; // edx
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
      this->m_pMemory = (UtlLinkedListElem_t<CFileInfo *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: m_pMemory,
                                                                             a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CFileInfo *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025460
// Name: public: static char const __near * CCreateMultiplayerGameServerPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCreateMultiplayerGameServerPage::GetPanelClassName()
{
  return "CCreateMultiplayerGameServerPage";
}

//------------------------------------------------------------------------------
// Address: 0x10025470
// Name: char const __near * GetLiblistFallbackDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetLiblistFallbackDir(const char *pszGameDir)
{
  void *v1; // ebx
  int v2; // eax
  int v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // esi
  char szTemp[512]; // [esp+4h] [ebp-400h] BYREF
  char szLine[512]; // [esp+204h] [ebp-200h] BYREF

  szFallback[0] = 0;
  _snprintf(string: szTemp, count: 0x1FFu, format: "%s\\liblist.gam", pszGameDir);
  g_pFullFileSystem->GetLocalCopy(this: g_pFullFileSystem, a2: szTemp);
  v1 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: szTemp, a3: "rt", a4: 0);
  if ( v1 != nullptr )
  {
    while ( !g_pFullFileSystem->EndOfFile(this: g_pFullFileSystem, a2: v1) )
    {
      szLine[0] = 0;
      g_pFullFileSystem->ReadLine(this: g_pFullFileSystem, a2: szLine, a3: 511, a4: v1);
      szLine[511] = 0;
      if ( V_strncasecmp(s1: szLine, s2: "fallback_dir", n: 12) == 0 )
      {
        strchr(string: (unsigned __int8 *)szLine, chr: 0x22u);
        v3 = v2;
        if ( v2 == 0 )
          break;
        v4 = (unsigned __int8 *)(v2 + 1);
        strchr(string: (unsigned __int8 *)(v2 + 1), chr: 0x22u);
        if ( v5 == 0 )
          break;
        v6 = v5 - v3;
        v7 = v6 - 1;
        if ( (unsigned int)(v6 - 1) >= 0x1FF )
          break;
        if ( v7 > 0 )
        {
          strncpy(dest: (unsigned __int8 *)szFallback, source: v4, count: v6 - 1);
          szFallback[v7] = 0;
        }
      }
    }
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v1);
  }
  return szFallback;
}

//------------------------------------------------------------------------------
// Address: 0x100255D0
// Name: public: virtual void CCreateMultiplayerGameServerPage::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::OnResetData(CCreateMultiplayerGameServerPage *this)
{
  this->m_pGameCombo->SetEnabled(this: this->m_pGameCombo, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100255F0
// Name: private: void CCreateMultiplayerGameServerPage::LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::LoadConfig(CCreateMultiplayerGameServerPage *this)
{
  KeyValues *m_pSavedData; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  IBaseFileSystem *v5; // ecx
  const char *String; // eax
  unsigned int v7; // eax
  const char *v8; // ebx
  char v9; // cl
  int v10; // edi
  KeyValues *ItemUserData; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  int Int; // eax
  CCreateMultiplayerGameServerPage_vtbl *v16; // edx
  bool secure; // [esp+4h] [ebp-4h]

  m_pSavedData = this->m_pSavedData;
  if ( m_pSavedData != nullptr )
    KeyValues::deleteThis(this: m_pSavedData);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Server");
  else
    v4 = nullptr;
  this->m_pSavedData = v4;
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: v5,
         resourceName: "Server.vdf",
         pathID: "CONFIG",
         pfnEvaluateSymbolProc: nullptr) )
  {
    if ( KeyValues::FindKey(this: this->m_pSavedData, keyName: "RconPassword", bCreate: false) != nullptr )
    {
      String = KeyValues::GetString(this: this->m_pSavedData, keyName: "RconPassword", defaultValue: defaultValue);
      if ( strlen(String) != 0 )
        this->SetControlString_2(this, a2: "RCONPasswordEdit", a3: String);
    }
    if ( KeyValues::FindKey(this: this->m_pSavedData, keyName: "MaxPlayers", bCreate: false) != nullptr )
    {
      v7 = KeyValues::GetInt(this: this->m_pSavedData, keyName: "MaxPlayers", defaultValue: -1) - 1;
      if ( v7 <= 0x1F )
        vgui::ComboBox::ActivateItemByRow(this: this->m_pNumPlayers, row: v7);
    }
    if ( KeyValues::FindKey(this: this->m_pSavedData, keyName: "MOD", bCreate: false) != nullptr )
    {
      v8 = KeyValues::GetString(this: this->m_pSavedData, keyName: "MOD", defaultValue: defaultValue);
      if ( strlen(v8) != 0 )
      {
        this->m_szMod[0] = v9;
        v10 = 0;
        if ( this->m_pGameCombo->GetItemCount(this: this->m_pGameCombo) > 0 )
        {
          while ( 1 )
          {
            if ( this->m_pGameCombo->IsItemIDValid(this: this->m_pGameCombo, a2: v10) )
            {
              ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pGameCombo, itemID: v10);
              v12 = KeyValues::GetString(this: ItemUserData, keyName: "gamedir", defaultValue: defaultValue);
              if ( _V_stricmp(s1: v12, s2: v8) == 0 )
                break;
            }
            if ( ++v10 >= this->m_pGameCombo->GetItemCount(this: this->m_pGameCombo) )
              goto LABEL_24;
          }
          this->m_pGameCombo->ActivateItem(this: this->m_pGameCombo, a2: v10);
        }
      }
    }
LABEL_24:
    if ( KeyValues::FindKey(this: this->m_pSavedData, keyName: "Map", bCreate: false) != nullptr )
    {
      v13 = KeyValues::GetString(this: this->m_pSavedData, keyName: "Map", defaultValue: defaultValue);
      if ( strlen(v13) != 0 )
        this->SetControlString_2(this, a2: "MapList", a3: v13);
    }
    if ( KeyValues::FindKey(this: this->m_pSavedData, keyName: "Network", bCreate: false) != nullptr
      && KeyValues::GetInt(this: this->m_pSavedData, keyName: "Network", defaultValue: 0) == 1 )
    {
      vgui::ComboBox::ActivateItemByRow(this: this->m_pNetworkCombo, row: 1);
    }
    if ( KeyValues::FindKey(this: this->m_pSavedData, keyName: "Secure", bCreate: false) != nullptr )
    {
      secure = KeyValues::GetInt(this: this->m_pSavedData, keyName: "Secure", defaultValue: 0) != 0;
      this->m_pSecureCheck->SetSelected(this: this->m_pSecureCheck, a2: secure);
    }
    if ( KeyValues::FindKey(this: this->m_pSavedData, keyName: "ServerName", bCreate: false) != nullptr )
    {
      v14 = KeyValues::GetString(this: this->m_pSavedData, keyName: "ServerName", defaultValue: defaultValue);
      if ( strlen(v14) != 0 )
        this->SetControlString_2(this, a2: "ServerNameEdit", a3: v14);
    }
    Int = KeyValues::GetInt(this: this->m_pSavedData, keyName: "Port", defaultValue: this->m_iPort);
    v16 = this->__vftable;
    this->m_iPort = Int;
    v16->SetControlInt(this, a2: "PortEdit", a3: Int);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025910
// Name: private: void CCreateMultiplayerGameServerPage::SetConfig(char const __near *,char const __near *,int,char const __near *,char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::SetConfig(
        CCreateMultiplayerGameServerPage *this,
        const char *serverName,
        const char *rconPassword,
        int maxPlayers,
        const char *mod,
        const char *map,
        int network,
        int secure,
        int port)
{
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "MaxPlayers", value: maxPlayers);
  KeyValues::SetString(this: this->m_pSavedData, keyName: "RconPassword", value: rconPassword);
  KeyValues::SetString(this: this->m_pSavedData, keyName: "ServerName", value: serverName);
  KeyValues::SetString(this: this->m_pSavedData, keyName: "MOD", value: mod);
  KeyValues::SetString(this: this->m_pSavedData, keyName: "Map", value: map);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "Secure", value: secure);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "Network", value: network);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "Port", value: port);
}

//------------------------------------------------------------------------------
// Address: 0x100259C0
// Name: private: bool CCreateMultiplayerGameServerPage::BadRconChars(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCreateMultiplayerGameServerPage::BadRconChars(
        CCreateMultiplayerGameServerPage *this,
        const char *pass)
{
  char v2; // bl
  unsigned int i; // esi

  v2 = 0;
  for ( i = 0; i < strlen(pass); ++i )
    v2 |= isalnum(c: pass[i]) == 0;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10025A20
// Name: private: void CCreateMultiplayerGameServerPage::AddMod(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::AddMod(
        CCreateMultiplayerGameServerPage *this,
        const char *pGameDirName,
        const char *pGameInfoFilename,
        KeyValues *pGameInfo)
{
  int v5; // esi
  KeyValues *ItemUserData; // eax
  const char *v7; // eax
  const char *String; // eax
  KeyValues *Key; // ebx
  int Int; // eax
  const char *v11; // ebx
  KeyValues *Copy; // esi

  v5 = 0;
  if ( this->m_pGameCombo->GetItemCount(this: this->m_pGameCombo) <= 0 )
  {
LABEL_5:
    String = KeyValues::GetString(this: pGameInfo, keyName: "type", defaultValue: "singleplayer_only");
    if ( _V_stricmp(s1: String, s2: "singleplayer_only") == 0 )
      return;
    Key = KeyValues::FindKey(this: pGameInfo, keyName: "FileSystem", bCreate: false);
    if ( Key == nullptr )
      _Error(a1: "%s missing FileSystem key.", pGameInfoFilename);
    Int = KeyValues::GetInt(this: Key, keyName: "SteamAppId", defaultValue: -1);
    if ( Int == -1 )
    {
      _Error(a1: "%s missing FileSystem\\SteamAppId key.", pGameInfoFilename);
    }
    else if ( Int == 211 || Int == 215 )
    {
      return;
    }
    v11 = KeyValues::GetString(this: pGameInfo, keyName: "game", defaultValue: nullptr);
    if ( v11 == nullptr )
      _Error(a1: "%s missing 'game' key.", pGameInfoFilename);
    Copy = KeyValues::MakeCopy(this: pGameInfo);
    KeyValues::SetString(this: Copy, keyName: "gamedir", value: pGameDirName);
    this->m_pGameCombo->AddItem_2(this: this->m_pGameCombo, a2: v11, a3: Copy);
    KeyValues::deleteThis(this: Copy);
  }
  else
  {
    while ( 1 )
    {
      if ( this->m_pGameCombo->IsItemIDValid(this: this->m_pGameCombo, a2: v5) )
      {
        ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pGameCombo, itemID: v5);
        v7 = KeyValues::GetString(this: ItemUserData, keyName: "gamedir", defaultValue: defaultValue);
        if ( _V_stricmp(s1: v7, s2: pGameDirName) == 0 )
          break;
      }
      if ( ++v5 >= this->m_pGameCombo->GetItemCount(this: this->m_pGameCombo) )
        goto LABEL_5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025B90
// Name: public: int CCreateMultiplayerGameServerPage::LoadMaps(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCreateMultiplayerGameServerPage::LoadMaps(CCreateMultiplayerGameServerPage *this, KeyValues *pszMod)
{
  int v3; // ebx
  const char *v4; // eax
  KeyValues *m_pGameInfo; // ecx
  unsigned __int8 *v6; // esi
  int v7; // eax
  _BYTE *v8; // eax
  char szSearch[256]; // [esp+Ch] [ebp-204h] BYREF
  char mapname[256]; // [esp+10Ch] [ebp-104h] BYREF
  int findHandle; // [esp+20Ch] [ebp-4h] BYREF
  KeyValues *hiddenMaps; // [esp+218h] [ebp+8h]

  v3 = 0;
  findHandle = 0;
  sprintf(string: szSearch, format: "%s/maps/*.bsp", (const char *)pszMod);
  v4 = g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: szSearch, a3: &findHandle);
  m_pGameInfo = this->m_pGameInfo;
  v6 = (unsigned __int8 *)v4;
  hiddenMaps = nullptr;
  if ( m_pGameInfo != nullptr )
    hiddenMaps = KeyValues::FindKey(this: m_pGameInfo, keyName: "hidden_maps", bCreate: false);
  for ( ; v6 != nullptr; v6 = (unsigned __int8 *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: findHandle) )
  {
    strstr(str1: v6, str2: "maps");
    if ( v7 != 0 )
      strncpy(dest: (unsigned __int8 *)mapname, source: (unsigned __int8 *)(v7 + 5), count: 0xFFu);
    else
      strncpy(dest: (unsigned __int8 *)mapname, source: v6, count: 0xFFu);
    strstr(str1: (unsigned __int8 *)mapname, str2: ".bsp");
    if ( v8 != nullptr )
      *v8 = 0;
    if ( (mapname[0] != 99 && mapname[0] != 116 || mapname[2] != 97 || mapname[1] < 48 || mapname[1] > 53)
      && (hiddenMaps == nullptr || KeyValues::GetInt(this: hiddenMaps, keyName: mapname, defaultValue: 0) == 0) )
    {
      ++v3;
      this->m_pMapList->AddItem_2(this: this->m_pMapList, a2: mapname, a3: nullptr);
    }
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: findHandle);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10025CF0
// Name: public: void CCreateMultiplayerGameServerPage::LoadMapList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::LoadMapList(CCreateMultiplayerGameServerPage *this)
{
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx
  int v3; // eax
  KeyValues *ActiveItemUserData; // eax
  KeyValues *v5; // edi
  vgui::ComboBox_vtbl *v6; // ebx
  const char *String; // eax
  int Maps; // edi
  char *LiblistFallbackDir; // eax

  vgui::ComboBox::RemoveAll(this: this->m_pMapList);
  SetEnabled = this->m_pMapList->SetEnabled;
  if ( &this->m_szMod[strlen(this->m_szMod) + 1] == &this->m_szMod[1] )
  {
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
  }
  else
  {
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
    this->m_pStartServerButton->SetEnabled(this: this->m_pStartServerButton, a2: true);
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-steam", a3: 0) != 0
      && (ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pGameCombo),
          v5 = ActiveItemUserData,
          ActiveItemUserData != nullptr)
      && KeyValues::GetString(this: ActiveItemUserData, keyName: "DedicatedServerStartMap", defaultValue: nullptr) != nullptr )
    {
      v6 = this->m_pMapList->__vftable;
      String = KeyValues::GetString(this: v5, keyName: "DedicatedServerStartMap", defaultValue: defaultValue);
      v6->AddItem_2(this: this->m_pMapList, a2: String, a3: nullptr);
      vgui::ComboBox::ActivateItemByRow(this: this->m_pMapList, row: 0);
      this->m_pMapList->SetEnabled(this: this->m_pMapList, a2: false);
    }
    else
    {
      Maps = CCreateMultiplayerGameServerPage::LoadMaps(this, pszMod: (KeyValues *)this->m_szMod);
      LiblistFallbackDir = GetLiblistFallbackDir(pszGameDir: this->m_szMod);
      if ( *LiblistFallbackDir != 0 )
        Maps += CCreateMultiplayerGameServerPage::LoadMaps(this, pszMod: (KeyValues *)LiblistFallbackDir);
      if ( Maps < 1 )
        this->m_pMapList->SetEnabled(this: this->m_pMapList, a2: false);
      vgui::ComboBox::ActivateItemByRow(this: this->m_pMapList, row: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025E20
// Name: public: void CCreateMultiplayerGameServerPage::GetServer(struct serveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::GetServer(CCreateMultiplayerGameServerPage *this, serveritem_t *s)
{
  char *name; // eax
  char v4; // cl
  char *rconPassword; // eax
  char v6; // cl
  char *gameDir; // eax
  int v8; // edx
  char v9; // cl
  char *map; // eax
  char v11; // cl
  char *gameDescription; // eax
  char v13; // cl

  *s = this->m_iServer;
  name = this->m_iServer.name;
  do
  {
    v4 = *name;
    name[s->name - this->m_iServer.name] = *name;
    ++name;
  }
  while ( v4 != 0 );
  rconPassword = this->m_iServer.rconPassword;
  do
  {
    v6 = *rconPassword;
    rconPassword[s->rconPassword - this->m_iServer.rconPassword] = *rconPassword;
    ++rconPassword;
  }
  while ( v6 != 0 );
  *(_DWORD *)s->ip = *(_DWORD *)this->m_iServer.ip;
  *(_QWORD *)s->pings = *(_QWORD *)this->m_iServer.pings;
  gameDir = this->m_iServer.gameDir;
  s->pings[2] = this->m_iServer.pings[2];
  v8 = s->gameDir - this->m_iServer.gameDir;
  do
  {
    v9 = *gameDir;
    gameDir[v8] = *gameDir;
    ++gameDir;
  }
  while ( v9 != 0 );
  map = this->m_iServer.map;
  do
  {
    v11 = *map;
    map[s->map - this->m_iServer.map] = *map;
    ++map;
  }
  while ( v11 != 0 );
  gameDescription = this->m_iServer.gameDescription;
  do
  {
    v13 = *gameDescription;
    gameDescription[s->gameDescription - this->m_iServer.gameDescription] = *gameDescription;
    ++gameDescription;
  }
  while ( v13 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10025EF0
// Name: private: virtual void CCreateMultiplayerGameServerPage::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCreateMultiplayerGameServerPage::OnTextChanged(
        CCreateMultiplayerGameServerPage *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        vgui::ComboBox *panel)
{
  KeyValues *ActiveItemUserData; // edi
  KeyValues *m_pGameInfo; // ecx
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  IBaseFileSystem *v9; // ecx
  char liblist[1024]; // [esp+4h] [ebp-504h] BYREF
  char hostname[256]; // [esp+404h] [ebp-104h] BYREF
  const char *pGameDir; // [esp+504h] [ebp-4h]
  bool updateHostname_3; // [esp+513h] [ebp+Bh]

  if ( panel == this->m_pGameCombo )
  {
    ((void (__stdcall *)(const char *, char *, int, const char *, int, int))this->GetControlString)(
      a1: "ServerNameEdit",
      a2: this->m_szHostName,
      a3: 64,
      a4: defaultValue,
      a5: a3,
      a6: a2);
    _snprintf(string: hostname, count: 0xFFu, format: "%s dedicated server", this->m_szGameName);
    updateHostname_3 = _V_stricmp(s1: this->m_szHostName, s2: hostname) == 0;
    this->m_pGameCombo->GetText_2(this: this->m_pGameCombo, a2: this->m_szGameName, a3: 64);
    ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pGameCombo);
    if ( ActiveItemUserData == nullptr )
      _Error(a1: "Missing gameData for active item.");
    pGameDir = KeyValues::GetString(this: ActiveItemUserData, keyName: "gamedir", defaultValue: nullptr);
    if ( pGameDir == nullptr )
      _Error(a1: "Game %s missing 'gamedir' key.", this->m_szGameName);
    V_strncpy(pDest: this->m_szMod, pSrc: pGameDir, maxLen: 64);
    m_pGameInfo = this->m_pGameInfo;
    if ( m_pGameInfo != nullptr )
      KeyValues::deleteThis(this: m_pGameInfo);
    V_snprintf(pDest: liblist, maxLen: 1023, pFormat: "%s\\gameinfo.txt", this->m_szMod);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "GameInfo");
    else
      v8 = nullptr;
    this->m_pGameInfo = v8;
    if ( g_pFullFileSystem != nullptr )
      v9 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v9 = nullptr;
    KeyValues::LoadFromFile(
      this: v8,
      filesystem: v9,
      resourceName: liblist,
      pathID: nullptr,
      pfnEvaluateSymbolProc: nullptr);
    if ( updateHostname_3 )
    {
      _snprintf(string: hostname, count: 0xFFu, format: "%s dedicated server", this->m_szGameName);
      this->SetControlString_2(this, a2: "ServerNameEdit", a3: hostname);
    }
    CCreateMultiplayerGameServerPage::LoadMapList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026090
// Name: public: virtual CCreateMultiplayerGameServerPage::~CCreateMultiplayerGameServerPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::~CCreateMultiplayerGameServerPage(
        CCreateMultiplayerGameServerPage *this)
{
  IBaseFileSystem *v2; // eax
  KeyValues *m_pSavedData; // ecx
  KeyValues *m_pGameInfo; // ecx

  this->__vftable = (CCreateMultiplayerGameServerPage_vtbl *)&CCreateMultiplayerGameServerPage::`vftable';
  if ( g_pFullFileSystem != nullptr )
    v2 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v2 = nullptr;
  KeyValues::SaveToFile(this: this->m_pSavedData, filesystem: v2, resourceName: "Server.vdf", pathID: "CONFIG");
  m_pSavedData = this->m_pSavedData;
  if ( m_pSavedData != nullptr )
  {
    KeyValues::deleteThis(this: m_pSavedData);
    this->m_pSavedData = nullptr;
  }
  m_pGameInfo = this->m_pGameInfo;
  if ( m_pGameInfo != nullptr )
  {
    KeyValues::deleteThis(this: m_pGameInfo);
    this->m_pGameInfo = nullptr;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10026120
// Name: public: virtual bool vgui::Panel::LookupElementBounds(char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Panel::LookupElementBounds(
        vgui::Panel *this,
        const char *elementName,
        const char *x,
        int *y,
        int *wide,
        int *tall)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10026130
// Name: public: virtual unsigned long vgui::Panel::GetDragFailCursor(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::Panel::GetDragFailCursor(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x10026150
// Name: public: virtual bool vgui::Panel::IsProportional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::Panel::IsProportional(vgui::Panel *this)
{
  return (this->_flags.m_nFlags & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10026160
// Name: public: virtual struct vgui::PanelMessageMap __near * CCreateMultiplayerGameServerPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCreateMultiplayerGameServerPage::GetMessageMap(
        CCreateMultiplayerGameServerPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCreateMultiplayerGameServerPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCreateMultiplayerGameServerPage::GetMessageMap'::`2'::s_pMap;
  `CCreateMultiplayerGameServerPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCreateMultiplayerGameServerPage");
  `CCreateMultiplayerGameServerPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026190
// Name: public: virtual struct PanelAnimationMap __near * CCreateMultiplayerGameServerPage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCreateMultiplayerGameServerPage::GetAnimMap(CCreateMultiplayerGameServerPage *this)
{
  return FindOrAddPanelAnimationMap(className: "CCreateMultiplayerGameServerPage");
}

//------------------------------------------------------------------------------
// Address: 0x100261A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCreateMultiplayerGameServerPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCreateMultiplayerGameServerPage::GetKBMap(CCreateMultiplayerGameServerPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCreateMultiplayerGameServerPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCreateMultiplayerGameServerPage::GetKBMap'::`2'::s_pMap;
  `CCreateMultiplayerGameServerPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCreateMultiplayerGameServerPage");
  `CCreateMultiplayerGameServerPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100261D0
// Name: public: void CUtlMemory<struct vgui::MessageMapItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::MessageMapItem_t,int>::Grow(CUtlMemory<vgui::MessageMapItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::MessageMapItem_t *m_pMemory; // edx
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
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026290
// Name: private: void CCreateMultiplayerGameServerPage::LoadModListInDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::LoadModListInDirectory(
        CCreateMultiplayerGameServerPage *this,
        const char *pDirectoryName)
{
  const char *v2; // edi
  const char *i; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  IBaseFileSystem *v7; // eax
  char pDest[1024]; // [esp+Ch] [ebp-70Ch] BYREF
  char searchString[520]; // [esp+40Ch] [ebp-30Ch] BYREF
  char fullFilename[260]; // [esp+614h] [ebp-104h] BYREF

  v2 = pDirectoryName;
  V_strncpy(pDest: searchString, pSrc: pDirectoryName, maxLen: 520);
  V_AppendSlash(pStr: searchString, strSize: 520);
  V_strncat(pDest: searchString, pSrc: "*.*", destBufferSize: 0x208u, max_chars_to_copy: -1);
  pDirectoryName = nullptr;
  for ( i = g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: searchString, a3: &pDirectoryName);
        i != nullptr;
        i = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: pDirectoryName) )
  {
    if ( *i != 46 && g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: (int)pDirectoryName) )
    {
      if ( _V_stricmp(s1: v2, s2: ".") != 0 )
      {
        V_strncpy(pDest: fullFilename, pSrc: v2, maxLen: 260);
        V_AppendSlash(pStr: fullFilename, strSize: 260);
        V_strncat(pDest: fullFilename, pSrc: i, destBufferSize: 0x104u, max_chars_to_copy: -1);
      }
      else
      {
        V_strncpy(pDest: fullFilename, pSrc: i, maxLen: 260);
      }
      V_snprintf(pDest, maxLen: 1023, pFormat: "%s\\gameinfo.txt", fullFilename);
      if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
      {
        v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v5 != nullptr )
          v6 = KeyValues::KeyValues(this: v5, setName: "GameInfo");
        else
          v6 = nullptr;
        if ( g_pFullFileSystem != nullptr )
          v7 = &g_pFullFileSystem->IBaseFileSystem;
        else
          v7 = nullptr;
        if ( KeyValues::LoadFromFile(
               this: v6,
               filesystem: v7,
               resourceName: pDest,
               pathID: nullptr,
               pfnEvaluateSymbolProc: nullptr) )
        {
          CCreateMultiplayerGameServerPage::AddMod(
            this,
            pGameDirName: fullFilename,
            pGameInfoFilename: pDest,
            pGameInfo: v6);
          KeyValues::deleteThis(this: v6);
        }
      }
    }
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)pDirectoryName);
}

//------------------------------------------------------------------------------
// Address: 0x10026470
// Name: private: void CCreateMultiplayerGameServerPage::LoadMODList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::LoadMODList(CCreateMultiplayerGameServerPage *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  IBaseFileSystem *v5; // eax
  KeyValues *FirstSubKey; // esi
  const char *String; // edi
  const char *Name; // eax
  char sourceModsDir[260]; // [esp+4h] [ebp-108h] BYREF
  KeyValues *gamesFile; // [esp+108h] [ebp-4h]

  vgui::ComboBox::RemoveAll(this: this->m_pGameCombo);
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-steam", a3: 0) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: "hlds_steamgames.vdf");
      gamesFile = v4;
    }
    else
    {
      gamesFile = nullptr;
      v4 = nullptr;
    }
    if ( g_pFullFileSystem != nullptr )
      v5 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v5 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v4,
           filesystem: v5,
           resourceName: "hlds_steamgames.vdf",
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      FirstSubKey = KeyValues::GetFirstSubKey(this: v4);
      if ( FirstSubKey != nullptr )
      {
        do
        {
          String = KeyValues::GetString(this: FirstSubKey, keyName: "gamedir", defaultValue: nullptr);
          if ( String == nullptr )
          {
            Name = KeyValues::GetName(this: FirstSubKey);
            _Error(a1: "Mod %s in %s missing 'gamedir'.", Name, "hlds_steamgames.vdf");
          }
          CCreateMultiplayerGameServerPage::AddMod(
            this,
            pGameDirName: String,
            pGameInfoFilename: "hlds_steamgames.vdf",
            pGameInfo: FirstSubKey);
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        }
        while ( FirstSubKey != nullptr );
        v4 = gamesFile;
      }
    }
    KeyValues::deleteThis(this: v4);
  }
  CCreateMultiplayerGameServerPage::LoadModListInDirectory(this, pDirectoryName: ".");
  if ( g_pVGuiSystem->GetRegistryString(
         this: g_pVGuiSystem,
         a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\SourceModInstallPath",
         a3: sourceModsDir,
         a4: 260) )
  {
    CCreateMultiplayerGameServerPage::LoadModListInDirectory(this, pDirectoryName: sourceModsDir);
  }
  this->m_pGameCombo->ActivateItem(this: this->m_pGameCombo, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100265B0
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
// Address: 0x10026620
// Name: public: virtual void CCreateMultiplayerGameServerPage::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::OnCommand(CCreateMultiplayerGameServerPage *this, const char *cmd)
{
  int v3; // eax
  vgui::ComboBox *m_pNumPlayers; // ecx
  int v5; // eax
  CCreateMultiplayerGameServerPage_vtbl *v6; // edx
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  vgui::IVGui *v11; // edi
  vgui::IVGui_vtbl *v12; // ebx
  int v13; // eax
  int ActiveItem; // eax
  IBaseFileSystem *v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  u_short v19; // ax
  unsigned __int8 v20; // dl
  char *m_szHostName; // eax
  char v22; // dl
  char *m_szMapName; // eax
  char v24; // cl
  char *m_szMod; // eax
  char v26; // cl
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  KeyValues *ActiveItemUserData; // esi
  int v29; // eax
  KeyValues *Key; // edi
  const char *String; // eax
  int Int; // eax
  CMainPanel *Instance; // eax
  vgui::MessageBox *v34; // eax
  vgui::MessageBox *v35; // eax
  int v36; // [esp+24h] [ebp-540h]
  int m_iPort; // [esp+28h] [ebp-53Ch]
  int m_iMaxPlayers; // [esp+28h] [ebp-53Ch]
  char cvars[1024]; // [esp+38h] [ebp-52Ch] BYREF
  char gameinfoFilename[260]; // [esp+438h] [ebp-12Ch] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > depList; // [esp+53Ch] [ebp-28h] BYREF
  int secure; // [esp+550h] [ebp-14h]
  netadr_s local; // [esp+554h] [ebp-10h] BYREF
  int v44; // [esp+560h] [ebp-4h]
  int isLanOnlya; // [esp+56Ch] [ebp+8h]
  int isLanOnlyb; // [esp+56Ch] [ebp+8h]
  char *isLanOnly; // [esp+56Ch] [ebp+8h]
  bool isLanOnly_3; // [esp+56Fh] [ebp+Bh]

  v3 = this->GetControlInt(this, a2: "SecureCheck", a3: 1);
  m_pNumPlayers = this->m_pNumPlayers;
  secure = v3;
  m_pNumPlayers->GetText_2(this: m_pNumPlayers, a2: cvars, a3: 1024);
  v5 = atoi(nptr: cvars);
  v6 = this->__vftable;
  this->m_iMaxPlayers = v5;
  v7 = (unsigned __int8 *)((int (__thiscall *)(CCreateMultiplayerGameServerPage *))v6->GetControlString_2)(a1: this);
  strncpy(dest: (unsigned __int8 *)this->m_szHostName, source: v7, count: (unsigned int)"ServerNameEdit");
  v8 = (unsigned __int8 *)((int (__thiscall *)(CCreateMultiplayerGameServerPage *))this->GetControlString_2)(a1: this);
  strncpy(dest: (unsigned __int8 *)this->m_szPassword, source: v8, count: (unsigned int)"RCONPasswordEdit");
  this->m_iPort = ((int (__thiscall *)(CCreateMultiplayerGameServerPage *, const char *, int, const char *, int, const char *, int))this->GetControlInt)(
                    a1: this,
                    a2: "PortEdit",
                    a3: 27015,
                    a4: defaultValue,
                    a5: 64,
                    a6: defaultValue,
                    a7: 64);
  if ( _V_stricmp(s1: cmd, s2: "cancel") != 0 )
  {
    if ( _V_stricmp(s1: cmd, s2: "start") == 0 )
    {
      this->m_pMapList->GetText_2(this: this->m_pMapList, a2: this->m_szMapName, a3: 64);
      m_iPort = this->m_iPort;
      v36 = secure;
      ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pNetworkCombo);
      CCreateMultiplayerGameServerPage::SetConfig(
        this,
        serverName: this->m_szHostName,
        rconPassword: this->m_szPassword,
        maxPlayers: this->m_iMaxPlayers,
        mod: this->m_szMod,
        map: this->m_szMapName,
        network: ActiveItem != 0,
        secure: v36,
        port: m_iPort);
      if ( g_pFullFileSystem != nullptr )
        v15 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v15 = nullptr;
      KeyValues::SaveToFile(this: this->m_pSavedData, filesystem: v15, resourceName: "Server.vdf", pathID: "CONFIG");
      isLanOnly_3 = vgui::ComboBox::GetActiveItem(this: this->m_pNetworkCombo) != 0;
      v16 = _CommandLine();
      (*(void (__thiscall **)(int, const char *, char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: "-game", a3: this->m_szMod);
      v17 = _CommandLine();
      m_iMaxPlayers = this->m_iMaxPlayers;
      v44 = v17;
      V_snprintf(pDest: pDest, maxLen: 256, pFormat: "%i", m_iMaxPlayers);
      (*(void (__thiscall **)(int, const char *, char *))(*(_DWORD *)v44 + 20))(a1: v44, a2: "-maxplayers", a3: pDest);
      v44 = _CommandLine();
      V_snprintf(pDest: pDest, maxLen: 256, pFormat: "%i", isLanOnly_3);
      (*(void (__thiscall **)(int, const char *, char *))(*(_DWORD *)v44 + 20))(a1: v44, a2: "+sv_lan", a3: pDest);
      isLanOnlya = _CommandLine();
      this->m_pMapList->GetText_2(this: this->m_pMapList, a2: this->m_szMapName, a3: 64);
      (*(void (__thiscall **)(int, const char *, char *))(*(_DWORD *)isLanOnlya + 20))(
        a1: isLanOnlya,
        a2: "+map",
        a3: this->m_szMapName);
      isLanOnlyb = _CommandLine();
      V_snprintf(pDest: pDest, maxLen: 256, pFormat: "%i", this->m_iPort);
      (*(void (__thiscall **)(int, const char *, char *))(*(_DWORD *)isLanOnlyb + 20))(
        a1: isLanOnlyb,
        a2: "-port",
        a3: pDest);
      if ( secure == 0 )
      {
        v18 = _CommandLine();
        (*(void (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v18 + 20))(
          a1: v18,
          a2: "-insecure",
          a3: defaultValue);
      }
      if ( strlen(this->m_szPassword) < 3
        || CCreateMultiplayerGameServerPage::BadRconChars(this, pass: this->m_szPassword) != 0 )
      {
        v34 = (vgui::MessageBox *)operator new(nSize: 0x234u);
        if ( v34 != nullptr )
          v35 = vgui::MessageBox::MessageBox(
                  this: v34,
                  title: "#Start_Server_RCON_Error_Title",
                  text: "#Start_Server_RCON_Error",
                  parent: nullptr);
        else
          v35 = nullptr;
        v35->DoModal_2(this: v35, a2: nullptr);
      }
      else
      {
        _snprintf(
          string: cvars,
          count: 0x400u,
          format: "rcon_password \"%s\"\nsetmaster enable\nhostname \"%s\"\n",
          this->m_szPassword,
          this->m_szHostName);
        this->m_pGameCombo->SetEnabled(this: this->m_pGameCombo, a2: false);
        this->m_pNumPlayers->SetEnabled(this: this->m_pNumPlayers, a2: false);
        netadr_s::SetIP(this: &local, unIP: 0);
        netadr_s::SetPort(this: &local, newport: 0);
        netadr_s::SetType(this: &local, newtype: NA_IP);
        net->GetLocalIP(this: net, a2: &local);
        v19 = htons(hostshort: this->m_iPort);
        v20 = local.ip[1];
        this->m_iServer.ip[0] = local.ip[0];
        local.port = v19;
        this->m_iServer.ip[2] = local.ip[2];
        this->m_iServer.ip[1] = v20;
        this->m_iServer.ip[3] = local.ip[3];
        this->m_iServer.port = HIBYTE(v19) | ((unsigned __int8)v19 << 8);
        m_szHostName = this->m_szHostName;
        do
        {
          v22 = *m_szHostName;
          *(m_szHostName - 154) = *m_szHostName;
          ++m_szHostName;
        }
        while ( v22 != 0 );
        this->m_pMapList->GetText_2(this: this->m_pMapList, a2: this->m_szMapName, a3: 64);
        m_szMapName = this->m_szMapName;
        do
        {
          v24 = *m_szMapName;
          *(m_szMapName - 378) = *m_szMapName;
          ++m_szMapName;
        }
        while ( v24 != 0 );
        m_szMod = this->m_szMod;
        isLanOnly = this->m_iServer.gameDir;
        do
        {
          v26 = *m_szMod;
          *(m_szMod - 474) = *m_szMod;
          ++m_szMod;
        }
        while ( v26 != 0 );
        SetVisible = this->SetVisible;
        this->m_iServer.maxPlayers = this->m_iMaxPlayers;
        SetVisible(this, a2: false);
        ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pGameCombo);
        v29 = _CommandLine();
        if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v29 + 12))(a1: v29, a2: "-steam", a3: 0) != 0
          && ActiveItemUserData != nullptr )
        {
          Key = KeyValues::FindKey(this: ActiveItemUserData, keyName: "FileSystem", bCreate: false);
          if ( Key == nullptr )
          {
            String = KeyValues::GetString(this: ActiveItemUserData, keyName: "game", defaultValue: defaultValue);
            _Error(a1: "Game %s missing FileSystem key.", String);
          }
          Int = KeyValues::GetInt(this: Key, keyName: "SteamAppId", defaultValue: 0);
          if ( Int != 0 )
          {
            memset(&depList, 0, sizeof(depList));
            MountDependencies(iAppId: Int, &depList);
            V_snprintf(pDest: gameinfoFilename, maxLen: 260, pFormat: "%s\\gameinfo.txt", isLanOnly);
            g_pFullFileSystem->GetLocalCopy(this: g_pFullFileSystem, a2: gameinfoFilename);
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&depList);
          }
        }
        Instance = CMainPanel::GetInstance();
        Instance->StartServer(this: Instance, a2: cvars);
      }
    }
  }
  else
  {
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "Quit");
    else
      v10 = nullptr;
    v11 = g_pVGui;
    v12 = g_pVGui->__vftable;
    v13 = ((int (__stdcall *)(KeyValues *, _DWORD, _DWORD))this->m_MainPanel->GetVPanel)(a1: v10, a2: 0, a3: 0);
    ((void (__thiscall *)(vgui::IVGui *, int))v12->PostMessage)(a1: v11, a2: v13);
    this->Close(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026BA0
// Name: public: static void CCreateMultiplayerGameServerPage::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CCreateMultiplayerGameServerPage::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CCreateMultiplayerGameServerPage::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CCreateMultiplayerGameServerPage::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CCreateMultiplayerGameServerPage");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "TextChanged";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026C50
// Name: public: CCreateMultiplayerGameServerPage::CCreateMultiplayerGameServerPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCreateMultiplayerGameServerPage *__thiscall CCreateMultiplayerGameServerPage::CCreateMultiplayerGameServerPage(
        CCreateMultiplayerGameServerPage *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::ComboBox *v10; // eax
  int v11; // edi
  int v12; // eax
  vgui::ComboBox *v13; // eax
  vgui::ComboBox *v14; // eax
  int i; // edi
  vgui::ComboBox *v16; // eax
  vgui::ComboBox *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax
  vgui::Button *v20; // eax
  vgui::Button *v21; // eax
  vgui::CheckButton *v22; // eax
  vgui::CheckButton *v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  vgui::MessageBox *v27; // eax
  vgui::MessageBox *v28; // eax
  int lanItem; // [esp+Ch] [ebp-8h]
  const char *portVal; // [esp+10h] [ebp-4h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CCreateMultiplayerGameServerPage_vtbl *)&CCreateMultiplayerGameServerPage::`vftable';
  if ( `CCreateMultiplayerGameServerPage::ChainToMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameServerPage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CCreateMultiplayerGameServerPage");
    v4->pfnClassName = CCreateMultiplayerGameServerPage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CCreateMultiplayerGameServerPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameServerPage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CCreateMultiplayerGameServerPage");
    v5->pfnClassName = CCreateMultiplayerGameServerPage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CCreateMultiplayerGameServerPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameServerPage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CCreateMultiplayerGameServerPage");
    v6->pfnClassName = CCreateMultiplayerGameServerPage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CCreateMultiplayerGameServerPage::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_iServer.pings[0] = 0;
  this->m_iServer.pings[1] = 0;
  this->m_iServer.pings[2] = 0;
  memset(dst: this->m_iServer.ip, value: 0, count: 0x13Cu);
  this->m_MainPanel = parent;
  this->m_pSavedData = nullptr;
  this->m_pGameInfo = nullptr;
  vgui::Panel::SetMinimumSize(this, wide: 310, tall: 350);
  vgui::Panel::SetSize(this, wide: 310, tall: 350);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetTitle(this, title: "#Start_Server_Title", surfaceTitle: true);
  v7 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "MapList", numLines: 10, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pMapList = v8;
  v8->SetEnabled(this: v8, a2: false);
  this->m_pMapList->SetEditable(this: this->m_pMapList, a2: false);
  v9 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v9 != nullptr )
    v10 = vgui::ComboBox::ComboBox(this: v9, parent: this, panelName: "NetworkCombo", numLines: 10, allowEdit: false);
  else
    v10 = nullptr;
  this->m_pNetworkCombo = v10;
  v11 = v10->AddItem_2(this: v10, a2: "#Internet", a3: nullptr);
  lanItem = this->m_pNetworkCombo->AddItem_2(this: this->m_pNetworkCombo, a2: "#LAN", a3: nullptr);
  v12 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v12 + 12))(a1: v12, a2: "-steam", a3: 0) != 0 )
  {
    parent = nullptr;
    g_pVGuiSystem->GetRegistryInteger(
      this: g_pVGuiSystem,
      a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Offline",
      a3: (int *)&parent);
    if ( parent == (vgui::Panel *)1 )
      v11 = lanItem;
  }
  this->m_pNetworkCombo->ActivateItem(this: this->m_pNetworkCombo, a2: v11);
  v13 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v13 != nullptr )
    v14 = vgui::ComboBox::ComboBox(this: v13, parent: this, panelName: "NumPlayers", numLines: 10, allowEdit: false);
  else
    v14 = nullptr;
  this->m_pNumPlayers = v14;
  for ( i = 1; i <= 32; ++i )
  {
    _snprintf(string: (char *)&name, count: 3u, format: "%i", i);
    this->m_pNumPlayers->AddItem_2(this: this->m_pNumPlayers, a2: (const char *)&name, a3: nullptr);
  }
  vgui::ComboBox::ActivateItemByRow(this: this->m_pNumPlayers, row: 23);
  v16 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v16 != nullptr )
    v17 = vgui::ComboBox::ComboBox(this: v16, parent: this, panelName: "MODCombo", numLines: 10, allowEdit: false);
  else
    v17 = nullptr;
  this->m_pGameCombo = v17;
  v18 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v18 != nullptr )
    v19 = vgui::Button::Button(
            this: v18,
            parent: this,
            panelName: "StartButton",
            text: "#Start_Server_Button",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v19 = nullptr;
  this->m_pStartServerButton = v19;
  v19->SetCommand(this: v19, a2: "start");
  v20 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v20 != nullptr )
    v21 = vgui::Button::Button(
            this: v20,
            parent: this,
            panelName: "CancelButton",
            text: "#Start_Server_Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v21 = nullptr;
  this->m_pCancelButton = v21;
  v21->SetCommand(this: v21, a2: "cancel");
  v22 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v22 != nullptr )
    v23 = vgui::CheckButton::CheckButton(
            this: v22,
            parent: this,
            panelName: "SecureCheck",
            text: "#Start_Server_Secure");
  else
    v23 = nullptr;
  this->m_pSecureCheck = v23;
  v23->SetSelected(this: v23, a2: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "Admin/CreateMultiplayerGameServerPage.res",
    dialogID: 0);
  vgui::EditablePanel::SetControlString(this, controlName: "ServerNameEdit", string: "Half-Life dedicated server");
  V_strncpy(pDest: this->m_szGameName, pSrc: "Half-Life", maxLen: 64);
  CCreateMultiplayerGameServerPage::LoadMODList(this);
  this->m_pGameCombo->RequestFocus(this: this->m_pGameCombo, a2: 0);
  this->m_iPort = 27015;
  portVal = nullptr;
  v24 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v24 + 12))(
         a1: v24,
         a2: "-port",
         a3: &portVal) != 0
    && portVal != nullptr
    && atoi(nptr: portVal) > 0 )
  {
    this->m_iPort = atoi(nptr: portVal);
  }
  vgui::EditablePanel::SetControlInt(this, controlName: "PortEdit", state: this->m_iPort);
  CCreateMultiplayerGameServerPage::LoadConfig(this);
  this->m_szMapName[0] = 0;
  this->m_szHostName[0] = 0;
  this->m_szPassword[0] = 0;
  this->m_iMaxPlayers = 24;
  v25 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v25 + 12))(a1: v25, a2: "-steam", a3: 0) != 0 )
  {
    parent = nullptr;
    g_pVGuiSystem->GetRegistryInteger(
      this: g_pVGuiSystem,
      a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Offline",
      a3: (int *)&parent);
    if ( parent == (vgui::Panel *)1 )
      this->m_pNetworkCombo->SetEnabled(this: this->m_pNetworkCombo, a2: false);
  }
  vgui::Panel::SetVisible(this, state: true);
  v26 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v26 + 12))(a1: v26, a2: "-steam", a3: 0) != 0 )
  {
    parent = nullptr;
    g_pVGuiSystem->GetRegistryInteger(
      this: g_pVGuiSystem,
      a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Offline",
      a3: (int *)&parent);
    if ( parent == (vgui::Panel *)1 )
    {
      v27 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v27 != nullptr )
        v28 = vgui::MessageBox::MessageBox(
                this: v27,
                title: "#Start_Server_Offline_Title",
                text: "#Start_Server_Offline_Warning",
                parent: nullptr);
      else
        v28 = nullptr;
      v28->DoModal_2(this: v28, a2: nullptr);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10027CE0
// Name: public: void CUtlMemory<class CUtlSymbolTable,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbolTable,int>::Grow(CUtlMemory<CUtlSymbolTable,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable *m_pMemory; // edx

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
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028410
// Name: public: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::Purge(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CUtlSymbolTable *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_Memory.m_pMemory[v3--]);
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
// Address: 0x10028580
// Name: public: int CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlSymbolTable *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlSymbolTable *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 56 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlSymbolTable::CUtlSymbolTable(this: v12, growSize: 0, initSize: 16, caseInsensitive: false);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10028C30
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::AddToTail(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CAppSystemGroup::Module_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1003EB10
// Name: public: void CUtlMemory<class CPackedStore __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPackedStore *,int>::Grow(CUtlMemory<vgui::TreeNode *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::TreeNode **m_pMemory; // edx
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
      this->m_pMemory = (vgui::TreeNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vgui::TreeNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040740
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
// Address: 0x10041B40
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
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
// Address: 0x10041CA0
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
// Address: 0x10041D10
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
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>::Grow(
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
// Address: 0x10041DA0
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
// Address: 0x1004A890
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
// Address: 0x1004BB30
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
// Address: 0x1004BE30
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
// Address: 0x1004E790
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
// Address: 0x1004F210
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
// Address: 0x1004F240
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x1004F250
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
// Address: 0x10060130
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
    CUtlMemory<CPackedStore *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1006D910
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
// Address: 0x1006E430
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
// Address: 0x1006E710
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
// Address: 0x10073480
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10076BC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10076BF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x10076C00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007C5D0
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
    CUtlMemory<CPackedStore *,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x1007EC90
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
    CUtlMemory<CZipPackFile::CPackFileEntry,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x10080090
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x10081660
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
    CUtlMemory<CPackedStore *,int>::Grow(
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
// Address: 0x10081C40
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
    CUtlMemory<__int64,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x10084E70
// Name: public: void CUtlMemory<struct PanelItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<PanelItem_t,int>::Grow(CUtlMemory<PanelItem_t,int> *this, int num)
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

//------------------------------------------------------------------------------
// Address: 0x1008B690
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
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
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
// Address: 0x1008B710
// Name: public: void CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::EnsureCapacity(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int num)
{
  unsigned __int8 *m_pMemory; // eax
  unsigned __int8 *v4; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      v4 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      v4 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    this->m_Memory.m_pMemory = v4;
    this->m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BC70
// Name: public: void CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::SetCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetCount(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int count)
{
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v5; // eax

  this->m_Size = 0;
  if ( count != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( count > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: count - m_nAllocationCount);
    this->m_Size += count;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - count;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && count > 0 )
      _V_memmove(dest: &m_pMemory[count], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BCC0
// Name: public: void CUtlVector<unsigned char,class CUtlBlockMemory<unsigned char,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned char,CUtlBlockMemory<unsigned char,int>>::EnsureCapacity(
        CUtlVector<unsigned char,CUtlBlockMemory<unsigned char,int> > *this,
        int num)
{
  int m_nBlocks; // edi
  int v4; // ecx

  m_nBlocks = this->m_Memory.m_nBlocks;
  v4 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( num - v4 * m_nBlocks > 0 )
    CUtlBlockMemory<unsigned char,int>::ChangeSize(
      this: &this->m_Memory,
      nBlocks: m_nBlocks + (v4 + num - v4 * m_nBlocks - 1) / v4);
  this->m_pElements = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008C0C0
// Name: public: int CUtlVector<unsigned char,class CUtlBlockMemory<unsigned char,int>>::InsertBefore(int,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned char,CUtlBlockMemory<unsigned char,int>>::InsertBefore(
        CUtlVector<unsigned char,CUtlBlockMemory<unsigned char,int> > *this,
        int elem,
        unsigned __int8 *src)
{
  int m_nBlocks; // ebx
  int m_Size; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax

  m_nBlocks = this->m_Memory.m_nBlocks;
  m_Size = this->m_Size;
  v6 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( m_Size + 1 > v6 * m_nBlocks )
  {
    v7 = m_Size - v6 * m_nBlocks + 1;
    if ( v7 > 0 )
      CUtlBlockMemory<unsigned char,int>::ChangeSize(this: &this->m_Memory, nBlocks: m_nBlocks + (v6 + v7 - 1) / v6);
  }
  v8 = ++this->m_Size - elem - 1;
  this->m_pElements = nullptr;
  if ( v8 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[(elem + 1) >> (*((int *)&this->m_Memory + 2) >> 27)][(elem + 1)
                                                                                   & ((32
                                                                                     * *((_DWORD *)&this->m_Memory + 2)) >> 5)],
      src: &this->m_Memory.m_pMemory[elem >> (*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                             & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)],
      count: v8);
  v9 = &this->m_Memory.m_pMemory[elem >> ((unsigned __int64)*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                                                & ((32
                                                                                                  * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}
