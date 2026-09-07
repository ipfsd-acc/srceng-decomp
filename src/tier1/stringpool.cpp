// Original: tier1/stringpool.cpp
// Functions: stubbed / inlined in this build
// ============================================================

#include "tier1\stringpool.h"

// Stub: CUtlVector<unsigned short,CUtlMemory<unsigned short,int> >::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int> >
void ~CUtlVector<unsigned short,CUtlMemory<unsigned short,int> >() {}

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x10058900
// Name: bool StrLessInsensitive(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StrLessInsensitive(const char **pszLeft, const char **pszRight)
{
  return _V_stricmp(s1: *pszLeft, s2: *pszRight) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10058920
// Name: bool StrLessSensitive(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StrLessSensitive(const char **pszLeft, const char **pszRight)
{
  return _V_strcmp(s1: *pszLeft, s2: *pszRight) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x100598B0
// Name: public: void CStringPool::FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringPool::FreeAll(CStringPool *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Strings);
        i != 0xFFFF;
        i = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Strings,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Strings.m_Elements.m_pMemory[i].m_Data);
  }
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Strings);
}

//------------------------------------------------------------------------------
// Address: 0x10059A00
// Name: public: CStringPool::CStringPool(enum StringPoolCase_t)
// Source: json
//------------------------------------------------------------------------------
CStringPool *__thiscall CStringPool::CStringPool(CStringPool *this, StringPoolCase_t caseSensitivity)
{
  bool (__cdecl *v3)(const char **, const char **); // eax
  UtlRBTreeNode_t<char const *,unsigned short> *m_pMemory; // edx

  v3 = StrLessInsensitive;
  if ( caseSensitivity != StringPoolCaseInsensitive )
    v3 = StrLessSensitive;
  this->m_Strings.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))v3;
  this->m_Strings.m_Elements.m_pMemory = nullptr;
  this->m_Strings.m_Elements.m_nAllocationCount = 256;
  this->m_Strings.m_Elements.m_nGrowSize = 32;
  this->m_Strings.m_Elements.m_pMemory = (UtlRBTreeNode_t<char const *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: 3072);
  m_pMemory = this->m_Strings.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Strings.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Strings.m_FirstFree = -1;
  this->m_Strings.m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10059A60
// Name: public: CStringPool::~CStringPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringPool::~CStringPool(CStringPool *this)
{
  CStringPool::FreeAll(this);
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::~CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>(this: &this->m_Strings);
}

//------------------------------------------------------------------------------
// Address: 0x10059AE0
// Name: public: char const __near * CStringPool::Allocate(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStringPool::Allocate(CStringPool *this, const char *pszValue)
{
  unsigned __int16 v3; // ax
  char *pszNew; // [esp+4h] [ebp-4h] BYREF

  v3 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Find(
         this: &this->m_Strings,
         search: &pszValue);
  if ( v3 != 0xFFFF )
    return (char *)this->m_Strings.m_Elements.m_pMemory[v3].m_Data;
  pszNew = MemAlloc_StrDup(pString: pszValue);
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Insert(
    this: &this->m_Strings,
    insert: (const char *const *)&pszNew);
  return pszNew;
}

} // namespace missionchooser

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x100061A0
// Name: public: void CUtlMemory<unsigned short,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned short,int>::Grow(CUtlMemory<unsigned short,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int16 *m_pMemory; // edx
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
        m_nAllocationCount = 16;
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
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x00407000
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407050
// Name: bool StrLessInsensitive(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StrLessInsensitive(const char **pszLeft, const char **pszRight)
{
  return _V_stricmp(s1: *pszLeft, s2: *pszRight) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407070
// Name: bool StrLessSensitive(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StrLessSensitive(const char **pszLeft, const char **pszRight)
{
  return _V_strcmp(s1: *pszLeft, s2: *pszRight) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407090
// Name: public: void CUtlMemory<unsigned short,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned short,int>::Grow(CUtlMemory<StaticPropLeafLump_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  StaticPropLeafLump_t *m_pMemory; // edx
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
        m_nAllocationCount = 16;
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
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (StaticPropLeafLump_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (StaticPropLeafLump_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407120
// Name: public: void CByteswap::SwapBufferToTargetEndian<int>(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = (unsigned __int8 *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *(_DWORD *)v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5, src: (unsigned __int8 *)&count, count: 4u);
          v5 += 4;
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407260
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<int>(
        this: &this->m_Byteswap,
        outputBuffer: (int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408240
// Name: public: void CStringPool::FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringPool::FreeAll(CStringPool *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Strings);
        i != 0xFFFF;
        i = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Strings,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Strings.m_Elements.m_pMemory[i].m_Data);
  }
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Strings);
}

//------------------------------------------------------------------------------
// Address: 0x00408390
// Name: public: CStringPool::CStringPool(enum StringPoolCase_t)
// Source: json
//------------------------------------------------------------------------------
CStringPool *__thiscall CStringPool::CStringPool(CStringPool *this, StringPoolCase_t caseSensitivity)
{
  bool (__cdecl *v3)(const char **, const char **); // eax
  UtlRBTreeNode_t<char const *,unsigned short> *m_pMemory; // edx

  v3 = StrLessInsensitive;
  if ( caseSensitivity != StringPoolCaseInsensitive )
    v3 = StrLessSensitive;
  this->m_Strings.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))v3;
  this->m_Strings.m_Elements.m_pMemory = nullptr;
  this->m_Strings.m_Elements.m_nAllocationCount = 256;
  this->m_Strings.m_Elements.m_nGrowSize = 32;
  this->m_Strings.m_Elements.m_pMemory = (UtlRBTreeNode_t<char const *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: 3072);
  m_pMemory = this->m_Strings.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Strings.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Strings.m_FirstFree = -1;
  this->m_Strings.m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004083F0
// Name: public: CStringPool::~CStringPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringPool::~CStringPool(CStringPool *this)
{
  CStringPool::FreeAll(this);
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::~CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>(this: &this->m_Strings);
}

//------------------------------------------------------------------------------
// Address: 0x00408470
// Name: public: char const __near * CStringPool::Allocate(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStringPool::Allocate(CStringPool *this, const char *pszValue)
{
  unsigned __int16 v3; // ax
  char *pszNew; // [esp+4h] [ebp-4h] BYREF

  v3 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Find(
         this: &this->m_Strings,
         search: &pszValue);
  if ( v3 != 0xFFFF )
    return (char *)this->m_Strings.m_Elements.m_pMemory[v3].m_Data;
  pszNew = MemAlloc_StrDup(pString: pszValue);
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Insert(
    this: &this->m_Strings,
    insert: (const char *const *)&pszNew);
  return pszNew;
}

} // namespace vbsp2

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1021C660
// Name: bool StrLessSensitive(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StrLessSensitive(const char **pszLeft, const char **pszRight)
{
  return _V_strcmp(s1: *pszLeft, s2: *pszRight) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x1036C1E0
// Name: bool StrLessInsensitive(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StrLessInsensitive(const char **pszLeft, const char **pszRight)
{
  return _V_stricmp(s1: *pszLeft, s2: *pszRight) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x1036CC30
// Name: public: void CStringPool::FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringPool::FreeAll(CStringPool *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Strings);
        i != 0xFFFF;
        i = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Strings,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Strings.m_Elements.m_pMemory[i].m_Data);
  }
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Strings);
}

//------------------------------------------------------------------------------
// Address: 0x1036CD80
// Name: public: CStringPool::CStringPool(enum StringPoolCase_t)
// Source: json
//------------------------------------------------------------------------------
CStringPool *__thiscall CStringPool::CStringPool(CStringPool *this, StringPoolCase_t caseSensitivity)
{
  bool (__cdecl *v3)(const char **, const char **); // eax
  UtlRBTreeNode_t<char const *,unsigned short> *m_pMemory; // edx

  v3 = StrLessInsensitive;
  if ( caseSensitivity != StringPoolCaseInsensitive )
    v3 = StrLessSensitive;
  this->m_Strings.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))v3;
  this->m_Strings.m_Elements.m_pMemory = nullptr;
  this->m_Strings.m_Elements.m_nAllocationCount = 256;
  this->m_Strings.m_Elements.m_nGrowSize = 32;
  this->m_Strings.m_Elements.m_pMemory = (UtlRBTreeNode_t<char const *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: 3072);
  m_pMemory = this->m_Strings.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Strings.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Strings.m_FirstFree = -1;
  this->m_Strings.m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1036CDE0
// Name: public: CStringPool::~CStringPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringPool::~CStringPool(CStringPool *this)
{
  CStringPool::FreeAll(this);
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::~CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>(this: &this->m_Strings);
}

//------------------------------------------------------------------------------
// Address: 0x1036CE60
// Name: public: char const __near * CStringPool::Allocate(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__userpurge CStringPool::Allocate@<eax>(CStringPool *this@<ecx>, const char *a2@<edi>, const char *pszValue)
{
  unsigned __int16 v4; // ax
  char *pszNew; // [esp+4h] [ebp-4h] BYREF

  v4 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Find(
         this: &this->m_Strings,
         search: &pszValue);
  if ( v4 != 0xFFFF )
    return (char *)this->m_Strings.m_Elements.m_pMemory[v4].m_Data;
  pszNew = MemAlloc_StrDup(pString: pszValue);
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Insert(
    this: &this->m_Strings,
    a2,
    insert: (const char *const *)&pszNew);
  return pszNew;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1037C470
// Name: bool StrLessInsensitive(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StrLessInsensitive(const char **pszLeft, const char **pszRight)
{
  return _V_stricmp(s1: *pszLeft, s2: *pszRight) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037C490
// Name: bool StrLessSensitive(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StrLessSensitive(const char **pszLeft, const char **pszRight)
{
  return _V_strcmp(s1: *pszLeft, s2: *pszRight) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037C4B0
// Name: public: char const __near * CStringPool::Find(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CStringPool::Find(CStringPool *this, const char *pszValue)
{
  unsigned __int16 v3; // ax
  int v4; // ebx

  v3 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Find(
         this: &this->m_Strings,
         search: &pszValue);
  v4 = v3;
  if ( v3 >= this->m_Strings.m_Elements.m_nAllocationCount
    || v3 > this->m_Strings.m_LastAlloc.index
    || CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::LeftChild(
         this: &this->m_Strings,
         i: v3) == v3 )
  {
    return nullptr;
  }
  else
  {
    return this->m_Strings.m_Elements.m_pMemory[v4].m_Data;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037C510
// Name: public: void CStringPool::FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringPool::FreeAll(CStringPool *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Strings);
        i != 0xFFFF;
        i = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Strings,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Strings.m_Elements.m_pMemory[i].m_Data);
  }
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Strings);
}

//------------------------------------------------------------------------------
// Address: 0x1037C570
// Name: public: CStringPool::CStringPool(enum StringPoolCase_t)
// Source: json
//------------------------------------------------------------------------------
CStringPool *__thiscall CStringPool::CStringPool(CStringPool *this, StringPoolCase_t caseSensitivity)
{
  bool (__cdecl *v3)(const char **, const char **); // eax
  UtlRBTreeNode_t<char const *,unsigned short> *m_pMemory; // edx

  v3 = StrLessInsensitive;
  if ( caseSensitivity != StringPoolCaseInsensitive )
    v3 = StrLessSensitive;
  this->m_Strings.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))v3;
  this->m_Strings.m_Elements.m_pMemory = nullptr;
  this->m_Strings.m_Elements.m_nAllocationCount = 256;
  this->m_Strings.m_Elements.m_nGrowSize = 32;
  this->m_Strings.m_Elements.m_pMemory = (UtlRBTreeNode_t<char const *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: 3072);
  m_pMemory = this->m_Strings.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Strings.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Strings.m_FirstFree = -1;
  this->m_Strings.m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1037C5D0
// Name: public: CStringPool::~CStringPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringPool::~CStringPool(CStringPool *this)
{
  CStringPool::FreeAll(this);
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::~CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>(this: &this->m_Strings);
}

//------------------------------------------------------------------------------
// Address: 0x1037C5E0
// Name: public: char const __near * CStringPool::Allocate(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CStringPool::Allocate(CStringPool *this, const char *pszValue)
{
  unsigned __int16 v3; // ax
  char *pszNew; // [esp+4h] [ebp-4h] BYREF

  v3 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Find(
         this: &this->m_Strings,
         search: &pszValue);
  if ( v3 != 0xFFFF )
    return (char *)this->m_Strings.m_Elements.m_pMemory[v3].m_Data;
  pszNew = MemAlloc_StrDup(pString: pszValue);
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Insert(
    this: &this->m_Strings,
    insert: (const char *const *)&pszNew);
  return pszNew;
}

} // namespace server
