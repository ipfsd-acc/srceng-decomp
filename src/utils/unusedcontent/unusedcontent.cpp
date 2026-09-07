// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/unusedcontent/unusedcontent.cpp
// Functions: 138
// ============================================================

#include "utils\unusedcontent\unusedcontent.h"

//------------------------------------------------------------------------------
// Address: 0x00403B00
// Name: public: void CUtlMemory<struct fileList_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<fileList_t,int>::Grow(CUtlMemory<fileList_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  fileList_t *m_pMemory; // edx
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
      this->m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403BA0
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403C30
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v6; // eax
  CUtlString *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlString,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00403CA0
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  fileList_t *m_pMemory; // ecx
  int v6; // eax
  fileList_t *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<fileList_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: &v7->fileName);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00403D10
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  fileList_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  fileList_t *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<fileList_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
          CUtlString::CUtlString(this: &v12->fileName);
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
// Address: 0x00403DB0
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
// Address: 0x00403E20
// Name: public: void CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  fileList_t *v3; // esi
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->fileName.m_Storage.m_nActualLength = 0;
      if ( v3->fileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->fileName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->fileName.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->fileName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004040F0
// Name: public: CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::~CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
  bool v2; // sf
  fileList_t *m_pMemory; // eax

  CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this);
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
// Address: 0x00404660
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00404690
// Name: void vprint(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void vprint(int depth, char *fmt, ...)
{
  _iobuf *v2; // edi
  int v3; // esi
  char *i; // esi
  char string[8192]; // [esp+Ch] [ebp-2000h] BYREF
  va_list ap; // [esp+201Ch] [ebp+10h] BYREF

  va_start(ap, fmt);
  vsprintf(string, format: fmt, ap);
  v2 = nullptr;
  if ( uselogfile )
    v2 = fopen(file: "log.txt", mode: "ab");
  v3 = depth;
  while ( v3 > 0 )
  {
    --v3;
    printf(format: "  ");
    OutputDebugStringA(lpOutputString: "  ");
    if ( v2 != nullptr )
      fprintf(str: v2, format: "  ");
  }
  printf(format: string);
  OutputDebugStringA(lpOutputString: string);
  if ( v2 != nullptr )
  {
    for ( i = string; *i != 0; fputc(ch: *i++, str: v2) )
    {
      if ( *i == 10 )
        fputc(ch: 13, str: v2);
    }
    fclose(stream: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404780
// Name: void printusage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn printusage()
{
  vprint(
    depth: 0,
    fmt: "usage:  unusedcontent maplistfile\n"
    "\t\t\t Note that you must have generated the reslistsfile output via the engine first!!!\n"
    "\t\t\t-d = spew command prompt deletion instructions to deletions.bat\n"
    "\t\t\t-v = verbose output\n"
    "\t\t\t-l = log to file log.txt\n"
    "\t\t\t-r = print out all referenced files\n"
    "\t\t\t-m = generate referenced.csv with map counts\n"
    "\t\t\t-w = print out whitelist\n"
    "\t\t\t-i = delete unused files immediately\n"
    "\t\t\t-f <reslistdir> :  specify reslists folder, 'reslists' assumed by default\n"
    "\t\t\t\tmaps/\n"
    "\t\t\t\tmaterials/\n"
    "\t\t\t\tmodels/\n"
    "\t\t\t\tsounds/\n"
    "\t\t\n"
    "e.g.:  unusedcontent -r maplist.txt\n");
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004047A0
// Name: public: static bool CDefOps<class UnusedContent::CUtlSymbol>::LessFunc(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<UnusedContent::CUtlSymbol>::LessFunc(
        const UnusedContent::CUtlSymbol *lhs,
        const UnusedContent::CUtlSymbol *rhs)
{
  return lhs->m_Id < rhs->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004047C0
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x004047D0
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00404840
// Name: protected: enum CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::NodeColor_t CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::Color(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Color(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( i == -1 )
    return dword_4470B0;
  else
    return this->m_Elements.m_pMemory[i].m_Tag;
}

//------------------------------------------------------------------------------
// Address: 0x004048A0
// Name: public: void CUtlMemory<class UnusedContent::CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UnusedContent::CUtlSymbol,int>::Grow(CUtlMemory<KeyValues *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  KeyValues **m_pMemory; // edx
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
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404930
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)_g_pMemAlloc->Realloc_2(
                                                                            this: _g_pMemAlloc,
                                                                            a2: m_pMemory,
                                                                            a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)_g_pMemAlloc->Alloc_2(
                                                                            this: _g_pMemAlloc,
                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004049D0
// Name: public: void CUtlMemory<struct FileEntry,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<FileEntry,int>::Grow(CUtlMemory<FileEntry,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  FileEntry *m_pMemory; // edx
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (FileEntry *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (FileEntry *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404A70
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<ReferencedFile,int> *m_pMemory; // edx
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
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<ReferencedFile,int> *)_g_pMemAlloc->Realloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: m_pMemory,
                                                                 a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<ReferencedFile,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404B10
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<FileEntry,int> *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<FileEntry,int> *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<FileEntry,int> *)_g_pMemAlloc->Alloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404BC0
// Name: public: unsigned int CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Parent(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Parent(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this,
        unsigned int i)
{
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( i == -1 )
    return dword_447098;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00404C20
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                             this: _g_pMemAlloc,
                                                                                             a2: m_pMemory,
                                                                                             a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                             this: _g_pMemAlloc,
                                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404CC0
// Name: private: static bool UnusedContent::CUtlSymbolTable::SymLess(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UnusedContent::CUtlSymbolTable::SymLess(
        const UnusedContent::CUtlSymbolTable::CStringPoolIndex *i1,
        const UnusedContent::CUtlSymbolTable::CStringPoolIndex *i2)
{
  char *m_pUserString; // eax
  char *v3; // ecx
  int v4; // kr00_4

  if ( i1->m_iPool == 0xFFFF && i1->m_iOffset == 0xFFFF )
    m_pUserString = (char *)g_LessCtx.m_pUserString;
  else
    m_pUserString = &g_LessCtx.m_pTable->m_StringPools.m_Memory.m_pMemory[i1->m_iPool]->m_Data[i1->m_iOffset];
  if ( i2->m_iPool == 0xFFFF && i2->m_iOffset == 0xFFFF )
    v3 = (char *)g_LessCtx.m_pUserString;
  else
    v3 = &g_LessCtx.m_pTable->m_StringPools.m_Memory.m_pMemory[i2->m_iPool]->m_Data[i2->m_iOffset];
  v4 = strcmp(m_pUserString, v3);
  return v4 != 0 && -(v4 < 0) - ((v4 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404D60
// Name: public: int CUtlVector<class UnusedContent::CUtlSymbol,class CUtlMemory<class UnusedContent::CUtlSymbol,int>>::Find(class UnusedContent::CUtlSymbol const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<UnusedContent::CUtlSymbol,CUtlMemory<UnusedContent::CUtlSymbol,int>>::Find(
        CUtlVector<UnusedContent::CUtlSymbol,CUtlMemory<UnusedContent::CUtlSymbol,int> > *this,
        const UnusedContent::CUtlSymbol *src)
{
  int m_Size; // edx
  int result; // eax
  UnusedContent::CUtlSymbol *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; i->m_Id != src->m_Id; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404D90
// Name: public: unsigned int CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RightChild(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RightChild(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this,
        unsigned int i)
{
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( i == -1 )
    return dword_447094;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00404DF0
// Name: protected: void CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::FindInsertionPosition(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,unsigned int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::FindInsertionPosition(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this,
        const UnusedContent::CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned int *parent,
        bool *leftchild)
{
  unsigned int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_447094 = -1;
        dword_447098 = -1;
        dword_44709C = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_447094 = -1;
        dword_447098 = -1;
        dword_44709C = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404EE0
// Name: public: int CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( i == -1 )
    return dword_4470AC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00404F40
// Name: public: int CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::LeftChild(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00404FA0
// Name: public: int CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RightChild(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( i == -1 )
    return dword_4470A8;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00405000
// Name: public: bool CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::IsRightChild(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4470A8 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x004050B0
// Name: protected: void CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::FindInsertionPosition(class UnusedContent::CUtlSymbol const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::FindInsertionPosition(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        const UnusedContent::CUtlSymbol *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004051A0
// Name: public: int CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Parent(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( i == -1 )
    return dword_4470C0;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00405200
// Name: public: int CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RightChild(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( i == -1 )
    return dword_4470BC;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00405260
// Name: public: bool CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::IsRightChild(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<ReferencedFile,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4470BC == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00405310
// Name: protected: void CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::FindInsertionPosition(struct ReferencedFile const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::FindInsertionPosition(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        const ReferencedFile *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470BC = -1;
        dword_4470C0 = -1;
        dword_4470C4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470BC = -1;
        dword_4470C0 = -1;
        dword_4470C4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405400
// Name: public: int CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Parent(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( i == -1 )
    return dword_4470D4;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00405460
// Name: public: int CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::LeftChild(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004054C0
// Name: public: int CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::RightChild(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( i == -1 )
    return dword_4470D0;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00405520
// Name: public: bool CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::IsRightChild(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<FileEntry,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4470D0 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x004055E0
// Name: protected: void CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::FindInsertionPosition(struct FileEntry const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::FindInsertionPosition(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this,
        const FileEntry *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // edi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470D0 = -1;
        dword_4470D4 = -1;
        dword_4470D8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470D0 = -1;
        dword_4470D4 = -1;
        dword_4470D8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004056E0
// Name: public: unsigned int CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::NewNode(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this)
{
  unsigned int result; // eax
  signed int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned int v6; // edi
  signed int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *m_pMemory; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<fileList_t,int>::Grow(this: (CUtlMemory<fileList_t,int> *)&this->m_Elements, num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004057A0
// Name: public: bool CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::IsLeftChild(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00405850
// Name: public: int CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::NewNode(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>::Grow(this: &this->m_Elements, num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    this->m_LastAlloc.index = v6;
    result = v6;
  }
  else
  {
    this->m_FirstFree = this->m_Elements.m_pMemory[result].m_Right;
  }
  if ( &this->m_Elements.m_pMemory[result] != (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)-16 )
    this->m_Elements.m_pMemory[result].m_Data.m_Id = -1;
  this->m_pElements = this->m_Elements.m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405920
// Name: public: int CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::NewNode(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  FileEntry *p_m_Data; // ecx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>::Grow(this: &this->m_Elements, num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    this->m_LastAlloc.index = v6;
    result = v6;
  }
  else
  {
    this->m_FirstFree = this->m_Elements.m_pMemory[result].m_Right;
  }
  p_m_Data = &this->m_Elements.m_pMemory[result].m_Data;
  if ( &this->m_Elements.m_pMemory[result] != (UtlRBTreeNode_t<FileEntry,int> *)-16 )
  {
    p_m_Data->sym.m_Id = -1;
    p_m_Data->size = 0;
    p_m_Data->referenced = 0;
  }
  this->m_pElements = this->m_Elements.m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405A10
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00405A70
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *__thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory;
  else
    return (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00405AD0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory == (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00405B80
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,DirEntry,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405C70
// Name: protected: void CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateLeft(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v8; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v9; // eax

  v2 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4470A8 = -1;
      dword_4470AC = -1;
      dword_4470B0 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00405E20
// Name: protected: void CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateRight(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v6; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v7; // eax

  v2 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00405FB0
// Name: protected: void CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::InsertRebalance(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v7; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v18; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v19; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v20; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v23; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406410
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  CUtlMap<char const *,DirEntry,int>::Node_t *p_m_Data; // ecx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    this->m_LastAlloc.index = v6;
    result = v6;
  }
  else
  {
    this->m_FirstFree = this->m_Elements.m_pMemory[result].m_Right;
  }
  p_m_Data = &this->m_Elements.m_pMemory[result].m_Data;
  if ( &this->m_Elements.m_pMemory[result] != (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-16 )
  {
    this->m_Elements.m_pMemory[result].m_Data.elem.total = 0.0;
    p_m_Data->elem.unreferenced = 0.0;
    p_m_Data->elem.whitelist = 0.0;
  }
  this->m_pElements = this->m_Elements.m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004064F0
// Name: public: bool CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::IsLeftChild(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::IsLeftChild(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this,
        unsigned int i)
{
  int v2; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v3; // eax
  unsigned int m_Parent; // eax

  v2 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x004065A0
// Name: public: bool CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::IsRightChild(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::IsRightChild(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this,
        unsigned int i)
{
  int v2; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v3; // eax
  unsigned int m_Parent; // eax

  v2 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( m_Parent == -1 )
    return dword_447094 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00406650
// Name: protected: void CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RotateLeft(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RotateLeft(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this,
        unsigned int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v4; // ecx
  unsigned int m_Right; // edi
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v8; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v9; // eax

  v2 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
      dword_447094 = -1;
      dword_447098 = -1;
      dword_44709C = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00406800
// Name: protected: void CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RotateRight(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RotateRight(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this,
        unsigned int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v4; // ecx
  unsigned int m_Left; // edi
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v6; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v7; // eax

  v2 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_447094 = -1;
    dword_447098 = -1;
    dword_44709C = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00406970
// Name: public: bool CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::IsLeftChild(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<ReferencedFile,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00406A20
// Name: protected: void CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RotateLeft(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<ReferencedFile,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *v8; // ecx
  UtlRBTreeNode_t<ReferencedFile,int> *v9; // eax

  v2 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4470BC = -1;
      dword_4470C0 = -1;
      dword_4470C4 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00406BD0
// Name: protected: void CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RotateRight(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<ReferencedFile,int> *v6; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *v7; // eax

  v2 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00406D40
// Name: public: bool CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::IsLeftChild(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<FileEntry,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00406E00
// Name: protected: void CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::RotateLeft(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<FileEntry,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<FileEntry,int> *v6; // ecx
  int v7; // eax
  UtlRBTreeNode_t<FileEntry,int> *v8; // ecx
  int v9; // ecx
  int v10; // ecx

  v2 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::LeftChild(
                                 this,
                                 i: m_Right)].m_Parent = elem;
    v7 = elem;
  }
  if ( m_Right != -1 )
  {
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v9 = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Parent(
           this,
           i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v9].m_Left = m_Right;
  }
  else
  {
    v10 = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v10].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00406FB0
// Name: protected: void CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::RotateRight(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<FileEntry,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<FileEntry,int> *v6; // ecx
  int v7; // eax
  UtlRBTreeNode_t<FileEntry,int> *v8; // ecx
  int v9; // ecx
  int v10; // ecx

  v2 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( m_Left == -1 )
    v8 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Left];
  if ( v8->m_Right != -1 )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
    v7 = elem;
  }
  if ( m_Left != -1 )
  {
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    v9 = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Parent(
           this,
           i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v9].m_Right = m_Left;
  }
  else
  {
    v10 = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v10].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00407160
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00407210
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v4; // eax
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v6; // eax
  int v7; // edx
  int v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v9; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v10; // eax
  int v11; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v8 = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    v8 = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
       | 1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v9 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v9 = &this->m_Elements.m_pMemory[m_Right];
  if ( v9->m_Left != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v8 | 1;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    if ( m_Right == -1 )
      v10 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v10 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v10->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
  {
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v11 = CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v11].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
    v7 = elem;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004073E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v4; // eax
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v7; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[(_DWORD)CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RightChild(
                                         this,
                                         i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00407560
// Name: bool ShouldCheckDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldCheckDir(const char *dirname)
{
  int v1; // esi
  int m_Size; // edi
  unsigned int m_Id; // eax
  const char *v4; // eax

  v1 = 0;
  m_Size = g_DirList.m_Size;
  if ( g_DirList.m_Size <= 0 )
  {
LABEL_7:
    vprint(depth: 1, fmt: "Skipping dir %s\n", dirname);
    return 0;
  }
  else
  {
    while ( 1 )
    {
      m_Id = g_DirList.m_Memory.m_pMemory[v1].m_Id;
      v4 = m_Id == -1
         ? dir
         : &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[m_Id].m_Data.m_iOffset];
      if ( _V_stricmp(s1: dirname, s2: v4) == 0 )
        return 1;
      if ( ++v1 >= m_Size )
        goto LABEL_7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004075F0
// Name: bool ShouldIgnoreDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldIgnoreDir(const char *dirname)
{
  int v1; // edi
  unsigned int m_Id; // eax
  const char *v3; // esi
  int c; // [esp+Ch] [ebp-4h]

  v1 = 0;
  c = g_IgnoreDir.m_Size;
  if ( g_IgnoreDir.m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    m_Id = g_IgnoreDir.m_Memory.m_pMemory[v1].m_Id;
    v3 = m_Id == -1
       ? dir
       : &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[m_Id].m_Data.m_iOffset];
    if ( V_stristr(pStr: dirname, pSearch: "reslists") != nullptr || _V_stricmp(s1: dirname, s2: v3) == 0 )
      break;
    if ( ++v1 >= c )
      return 0;
  }
  vprint(depth: 1, fmt: "Ignoring dir %s\n", dirname);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407690
// Name: RefFileLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RefFileLessFunc(const ReferencedFile *lhs, const ReferencedFile *rhs)
{
  const char *v2; // esi

  if ( lhs->sym.m_Id == -1 )
    v2 = dir;
  else
    v2 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[lhs->sym.m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[lhs->sym.m_Id].m_Data.m_iOffset];
  if ( rhs->sym.m_Id == -1 )
    return _V_stricmp(s1: v2, s2: dir) < 0;
  else
    return _V_stricmp(
             s1: v2,
             s2: &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[rhs->sym.m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[rhs->sym.m_Id].m_Data.m_iOffset]) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407710
// Name: public: unsigned int CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Find(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Find(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this,
        const UnusedContent::CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned int m_Root; // edi
  unsigned int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_447094 = -1;
        dword_447098 = -1;
        dword_44709C = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_447094 = -1;
        dword_447098 = -1;
        dword_44709C = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00407800
// Name: public: void CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RemoveAll(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this)
{
  unsigned int index; // edx
  signed int v2; // eax
  signed int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
            dword_447094 = -1;
            dword_447098 = -1;
            dword_44709C = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004078C0
// Name: public: int CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::Find(class UnusedContent::CUtlSymbol const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Find(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        const UnusedContent::CUtlSymbol *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x004079B0
// Name: public: int CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::FirstInorder(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4470A8 = -1;
      dword_4470AC = -1;
      dword_4470B0 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4470A8 = -1;
      dword_4470AC = -1;
      dword_4470B0 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407A50
// Name: public: int CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::NextInorder(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470A8 = -1;
    dword_4470AC = -1;
    dword_4470B0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407BC0
// Name: public: int CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::Find(struct ReferencedFile const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Find(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        const ReferencedFile *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470BC = -1;
        dword_4470C0 = -1;
        dword_4470C4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470BC = -1;
        dword_4470C0 = -1;
        dword_4470C4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00407CB0
// Name: public: int CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::FirstInorder(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4470BC = -1;
      dword_4470C0 = -1;
      dword_4470C4 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4470BC = -1;
      dword_4470C0 = -1;
      dword_4470C4 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407D50
// Name: public: int CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::NextInorder(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<ReferencedFile,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470BC = -1;
    dword_4470C0 = -1;
    dword_4470C4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470BC = -1;
          dword_4470C0 = -1;
          dword_4470C4 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470BC = -1;
        dword_4470C0 = -1;
        dword_4470C4 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470BC = -1;
        dword_4470C0 = -1;
        dword_4470C4 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407EC0
// Name: public: int CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::FirstInorder(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4470D0 = -1;
      dword_4470D4 = -1;
      dword_4470D8 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4470D0 = -1;
      dword_4470D4 = -1;
      dword_4470D8 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407F70
// Name: public: int CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::NextInorder(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<FileEntry,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4470D0 = -1;
    dword_4470D4 = -1;
    dword_4470D8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470D0 = -1;
          dword_4470D4 = -1;
          dword_4470D8 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470D0 = -1;
        dword_4470D4 = -1;
        dword_4470D8 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470D0 = -1;
        dword_4470D4 = -1;
        dword_4470D8 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004080F0
// Name: public: int CUtlVector<class UnusedContent::CUtlSymbol,class CUtlMemory<class UnusedContent::CUtlSymbol,int>>::InsertBefore(int,class UnusedContent::CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<UnusedContent::CUtlSymbol,CUtlMemory<UnusedContent::CUtlSymbol,int>>::InsertBefore(
        CUtlVector<UnusedContent::CUtlSymbol,CUtlMemory<UnusedContent::CUtlSymbol,int> > *this,
        int elem,
        const UnusedContent::CUtlSymbol *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  UnusedContent::CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  UnusedContent::CUtlSymbol *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UnusedContent::CUtlSymbol,int>::Grow(
      (CUtlMemory<KeyValues *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->m_Id = src->m_Id;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00408160
// Name: public: int CUtlVector<struct FileEntry,class CUtlMemory<struct FileEntry,int>>::InsertBefore(int,struct FileEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<FileEntry,CUtlMemory<FileEntry,int>>::InsertBefore(
        CUtlVector<FileEntry,CUtlMemory<FileEntry,int> > *this,
        int elem,
        const FileEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  FileEntry *m_pMemory; // ecx
  int v7; // eax
  FileEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<FileEntry,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x004081E0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,DirEntry,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x004082D0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
bool (__cdecl *__thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this))(const char *const *, const char *const *)
{
  int m_Root; // ebx
  bool (__cdecl *result)(const char *const *, const char *const *); // eax
  CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *v3; // edx

  m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  result = (bool (__cdecl *)(const char *const *, const char *const *))this->m_Root;
  while ( 1 )
  {
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    v3 = result == (bool (__cdecl *)(const char *const *, const char *const *))-1
       ? &`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
    if ( v3->m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
      break;
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    if ( result == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
      result = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc;
    else
      result = (bool (__cdecl *)(const char *const *, const char *const *))this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408370
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *__thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v3; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *result; // eax
  int m_Root; // edx
  CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *v6; // ecx
  int m_Parent; // esi
  int v8; // [esp-4h] [ebp-10h]

  if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v8 = m_Parent;
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
    while ( 1 )
    {
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v6 = result == (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1
         ? &`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
      if ( v6->m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( result == (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1 )
        result = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc;
      else
        result = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004084E0
// Name: public: void CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RemoveAll(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004085A0
// Name: protected: void CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::RemoveRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RemoveRebalance(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v5; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v6; // ecx
  int m_Parent; // edi
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v8; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v9; // ecx
  int m_Right; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v11; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v12; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v13; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v14; // edx
  int m_Left; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v16; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v17; // edx
  int v18; // edx
  int *v19; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v20; // edx
  int v21; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v22; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v23; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v24; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v25; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v26; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v27; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v28; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v29; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v30; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v31; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v32; // edx
  int v33; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v34; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v35; // edx
  int v36; // edx
  int *v37; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v38; // edx
  int v39; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v40; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v41; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v42; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v43; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v44; // edx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v45; // ecx

  v2 = elem;
  if ( elem != this->m_Root )
  {
    v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
    do
    {
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      if ( v5->m_Tag != 1 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      if ( v2 == -1 )
        v6 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v6 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v6->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470A8 = -1;
        dword_4470AC = -1;
        dword_4470B0 = 1;
      }
      if ( m_Parent == -1 )
      {
        v8 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
      }
      else
      {
        v8 = &this->m_Elements.m_pMemory[m_Parent];
        v2 = elem;
      }
      if ( v2 == v8->m_Left )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Parent == -1 )
          v9 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v9 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v9->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Right == -1 )
          v11 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v11 = &this->m_Elements.m_pMemory[m_Right];
        if ( v11->m_Tag == 0 )
        {
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
          CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateLeft(
            this,
            elem: m_Parent);
          v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( elem == -1 )
            v12 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v12 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v12->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( m_Parent == -1 )
            v13 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v13 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v13->m_Right;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Right == -1 )
          v14 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[m_Right];
        m_Left = v14->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Left == -1 )
          v16 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Left];
        if ( v16->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( m_Right == -1 )
            v17 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v17 = &this->m_Elements.m_pMemory[m_Right];
          v18 = v17->m_Right;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          v19 = v18 == -1
              ? &`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v18];
          if ( v19[3] == 1 )
            goto LABEL_146;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Right == -1 )
          v20 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[m_Right];
        v21 = v20->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( v21 == -1 )
          v22 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v22 = &this->m_Elements.m_pMemory[v21];
        if ( v22->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( m_Right == -1 )
            v23 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[m_Right];
          this->m_Elements.m_pMemory[v23->m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
          CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateRight(
            this,
            elem: m_Right);
          v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( elem == -1 )
            v24 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( m_Parent == -1 )
            v25 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v25 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v25->m_Right;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Parent == -1 )
          v26 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[m_Parent];
        this->m_Elements.m_pMemory[m_Right].m_Tag = v26->m_Tag;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
        if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Right == -1 )
          v27 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v27 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v27->m_Right].m_Tag = 1;
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateLeft(
          this,
          elem: m_Parent);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Parent == -1 )
          v28 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v28->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Right == -1 )
          v29 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v29 = &this->m_Elements.m_pMemory[m_Right];
        if ( v29->m_Tag == 0 )
        {
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
          CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateRight(
            this,
            elem: m_Parent);
          v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( elem == -1 )
            v30 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v30->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( m_Parent == -1 )
            v31 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v31->m_Left;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Right == -1 )
          v32 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v32 = &this->m_Elements.m_pMemory[m_Right];
        v33 = v32->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( v33 == -1 )
          v34 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v34 = &this->m_Elements.m_pMemory[v33];
        if ( v34->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( m_Right == -1 )
            v35 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v35 = &this->m_Elements.m_pMemory[m_Right];
          v36 = v35->m_Left;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          v37 = v36 == -1
              ? &`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v36];
          if ( v37[3] == 1 )
          {
LABEL_146:
            if ( m_Right != -1 )
            {
              this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
              v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
            }
            elem = m_Parent;
            goto LABEL_188;
          }
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Right == -1 )
          v38 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v38 = &this->m_Elements.m_pMemory[m_Right];
        v39 = v38->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( v39 == -1 )
          v40 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v40 = &this->m_Elements.m_pMemory[v39];
        if ( v40->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( m_Right == -1 )
            v41 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v41 = &this->m_Elements.m_pMemory[m_Right];
          this->m_Elements.m_pMemory[v41->m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
          CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateLeft(
            this,
            elem: m_Right);
          v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( elem == -1 )
            v42 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v42 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v42->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( m_Parent == -1 )
            v43 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v43 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v43->m_Left;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Parent == -1 )
          v44 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v44 = &this->m_Elements.m_pMemory[m_Parent];
        this->m_Elements.m_pMemory[m_Right].m_Tag = v44->m_Tag;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
        if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470A8 = -1;
          dword_4470AC = -1;
          dword_4470B0 = 1;
        }
        if ( m_Right == -1 )
          v45 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v45 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v45->m_Left].m_Tag = 1;
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RotateRight(
          this,
          elem: m_Parent);
      }
      v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
      elem = this->m_Root;
LABEL_188:
      v2 = elem;
    }
    while ( elem != this->m_Root );
  }
  this->m_Elements.m_pMemory[v2].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408FC0
// Name: public: void CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::RemoveAll(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this)
{
  int index; // eax
  BOOL v3; // ecx
  int v4; // esi
  int v5; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = this->m_Elements.m_nAllocationCount > 0;
    v4 = v3 - 1;
    if ( v3 )
    {
      do
      {
        if ( v4 >= 0
          && v4 < this->m_Elements.m_nAllocationCount
          && v4 <= index
          && CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::LeftChild(
               this,
               i: v4) != v4 )
        {
          v5 = v4;
          this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v5].m_Left = v4;
          this->m_FirstFree = v4;
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        if ( ++v4 < 0 || v4 >= this->m_Elements.m_nAllocationCount )
          v4 = -1;
      }
      while ( v4 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409050
// Name: protected: void CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::InsertRebalance(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::InsertRebalance(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this,
        unsigned int elem)
{
  unsigned int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v5; // ecx
  unsigned int m_Parent; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v7; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v8; // ecx
  unsigned int v9; // esi
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v10; // eax
  unsigned int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v14; // eax
  unsigned int m_Right; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v18; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v19; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v20; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v23; // ecx
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_447094 = -1;
        dword_447098 = -1;
        dword_44709C = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_447094 = -1;
        dword_447098 = -1;
        dword_44709C = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_447094 = -1;
        dword_447098 = -1;
        dword_44709C = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_447094 = -1;
        dword_447098 = -1;
        dword_44709C = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
          dword_447094 = -1;
          dword_447098 = -1;
          dword_44709C = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
          dword_447094 = -1;
          dword_447098 = -1;
          dword_44709C = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
            dword_447094 = -1;
            dword_447098 = -1;
            dword_44709C = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
            dword_447094 = -1;
            dword_447098 = -1;
            dword_44709C = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
          dword_447094 = -1;
          dword_447098 = -1;
          dword_44709C = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
          dword_447094 = -1;
          dword_447098 = -1;
          dword_44709C = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
            dword_447094 = -1;
            dword_447098 = -1;
            dword_44709C = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
            dword_447094 = -1;
            dword_447098 = -1;
            dword_44709C = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)&`CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004094B0
// Name: protected: void CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::InsertRebalance(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<ReferencedFile,int> *v7; // ecx
  UtlRBTreeNode_t<ReferencedFile,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<ReferencedFile,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<ReferencedFile,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *v18; // ecx
  UtlRBTreeNode_t<ReferencedFile,int> *v19; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *v20; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *v23; // ecx
  UtlRBTreeNode_t<ReferencedFile,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470BC = -1;
        dword_4470C0 = -1;
        dword_4470C4 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470BC = -1;
        dword_4470C0 = -1;
        dword_4470C4 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470BC = -1;
        dword_4470C0 = -1;
        dword_4470C4 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470BC = -1;
        dword_4470C0 = -1;
        dword_4470C4 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470BC = -1;
          dword_4470C0 = -1;
          dword_4470C4 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470BC = -1;
          dword_4470C0 = -1;
          dword_4470C4 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470BC = -1;
            dword_4470C0 = -1;
            dword_4470C4 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470BC = -1;
            dword_4470C0 = -1;
            dword_4470C4 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470BC = -1;
          dword_4470C0 = -1;
          dword_4470C4 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470BC = -1;
          dword_4470C0 = -1;
          dword_4470C4 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470BC = -1;
            dword_4470C0 = -1;
            dword_4470C4 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470BC = -1;
            dword_4470C0 = -1;
            dword_4470C4 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<ReferencedFile,int> *)&`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409910
// Name: protected: void CUtlRBTree<struct FileEntry,int,bool (*)(struct FileEntry const __near &,struct FileEntry const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct FileEntry,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::InsertRebalance(
        CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<FileEntry,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<FileEntry,int> *v7; // ecx
  UtlRBTreeNode_t<FileEntry,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<FileEntry,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<FileEntry,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<FileEntry,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<FileEntry,int> *v18; // ecx
  UtlRBTreeNode_t<FileEntry,int> *v19; // eax
  UtlRBTreeNode_t<FileEntry,int> *v20; // eax
  UtlRBTreeNode_t<FileEntry,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<FileEntry,int> *v23; // ecx
  UtlRBTreeNode_t<FileEntry,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470D0 = -1;
        dword_4470D4 = -1;
        dword_4470D8 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470D0 = -1;
        dword_4470D4 = -1;
        dword_4470D8 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470D0 = -1;
        dword_4470D4 = -1;
        dword_4470D8 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4470D0 = -1;
        dword_4470D4 = -1;
        dword_4470D8 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470D0 = -1;
          dword_4470D4 = -1;
          dword_4470D8 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470D0 = -1;
          dword_4470D4 = -1;
          dword_4470D8 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470D0 = -1;
            dword_4470D4 = -1;
            dword_4470D8 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470D0 = -1;
            dword_4470D4 = -1;
            dword_4470D8 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470D0 = -1;
          dword_4470D4 = -1;
          dword_4470D8 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4470D0 = -1;
          dword_4470D4 = -1;
          dword_4470D8 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470D0 = -1;
            dword_4470D4 = -1;
            dword_4470D8 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470D0 = -1;
            dword_4470D4 = -1;
            dword_4470D8 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<FileEntry,int> *)&`CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409DE0
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
            `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
            `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
            `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409EA0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct DirEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct DirEntry,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int m_Root; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v5; // eax
  int m_Parent; // eax
  CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v8; // eax
  int v9; // esi
  CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *v10; // eax
  int m_nAllocationCount; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v18; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v20; // eax
  int m_Left; // eax
  CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *v22; // ecx
  int v23; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v24; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v25; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        m_Root = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
               | 1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Elements.m_nGrowSize != 0 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v10 = v9 == -1
          ? &`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[v9];
      m_nAllocationCount = v10->m_Elements.m_nAllocationCount;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_nAllocationCount == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[m_nAllocationCount];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v16 = m_Right == -1
            ? &`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Elements.m_nGrowSize != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::IsRightChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RotateLeft(
              this,
              elem: v9);
            v17 = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
            if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                & 1) == 0 )
            {
              v17 = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v18 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v18 = &this->m_Elements.m_pMemory[v9];
            v9 = v18->m_Parent;
            if ( (v17 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v17 | 1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v19 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v19 = &this->m_Elements.m_pMemory[v9];
            m_nAllocationCount = v19->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: m_nAllocationCount);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          elem = m_nAllocationCount;
        }
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_nAllocationCount == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[m_nAllocationCount];
        m_Left = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v22 = m_Left == -1
            ? &`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Left];
        if ( v22->m_Elements.m_nGrowSize != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RotateRight(
              this,
              elem: v9);
            v23 = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
            if ( (`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                & 1) == 0 )
            {
              v23 = `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v9 = v24->m_Parent;
            if ( (v23 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v23 | 1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v25 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v25 = &this->m_Elements.m_pMemory[v9];
            m_nAllocationCount = v25->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: m_nAllocationCount);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          elem = m_nAllocationCount;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040A340
// Name: public: CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::~CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::~CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this)
{
  CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A3A0
// Name: protected: void CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Unlink(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this,
        int elem)
{
  int m_Left; // edi
  int v4; // ecx
  int v5; // eax
  int *v6; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v7; // eax
  int v8; // ebx
  int v9; // ebx
  CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> >::NodeColor_t ycolor; // [esp+Ch] [ebp-8h]
  int x; // [esp+10h] [ebp-4h]

  m_Left = elem;
  if ( elem != -1 )
  {
    v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4470A8 = -1;
      dword_4470AC = -1;
      dword_4470B0 = 1;
    }
    if ( this->m_Elements.m_pMemory[elem].m_Left != -1 )
    {
      if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RightChild(
             this,
             i: elem) == -1 )
      {
        v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
      }
      else
      {
        v5 = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RightChild(
               this,
               i: elem);
        v4 = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard';
        m_Left = v5;
        while ( 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          v6 = m_Left == -1
             ? &`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel
             : (int *)&this->m_Elements.m_pMemory[m_Left];
          if ( *v6 == -1 )
            break;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470A8 = -1;
            dword_4470AC = -1;
            dword_4470B0 = 1;
          }
          if ( m_Left == -1 )
            m_Left = `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
          else
            m_Left = this->m_Elements.m_pMemory[m_Left].m_Left;
        }
      }
    }
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
      `CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4470A8 = -1;
      dword_4470AC = -1;
      dword_4470B0 = 1;
    }
    if ( m_Left == -1 )
      v7 = (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)&`CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v7 = &this->m_Elements.m_pMemory[m_Left];
    if ( v7->m_Left == -1 )
    {
      x = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RightChild(
            this,
            i: m_Left);
      v8 = x;
    }
    else
    {
      v8 = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::LeftChild(
             this,
             i: m_Left);
      x = v8;
    }
    if ( v8 != -1 )
      this->m_Elements.m_pMemory[v8].m_Parent = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                                  this,
                                                  i: m_Left);
    if ( m_Left == this->m_Root )
    {
      this->m_Root = v8;
    }
    else if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::IsLeftChild(
                this,
                i: m_Left) )
    {
      this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                   this,
                                   i: m_Left)].m_Left = v8;
    }
    else
    {
      this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                   this,
                                   i: m_Left)].m_Right = v8;
    }
    ycolor = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Color(
               this,
               i: m_Left);
    if ( m_Left != elem )
    {
      v9 = m_Left;
      this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                                      this,
                                                      i: elem);
      this->m_Elements.m_pMemory[v9].m_Right = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RightChild(
                                                 this,
                                                 i: elem);
      this->m_Elements.m_pMemory[v9].m_Left = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::LeftChild(
                                                this,
                                                i: elem);
      if ( elem == this->m_Root )
      {
        this->m_Root = m_Left;
      }
      else if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::IsLeftChild(
                  this,
                  i: elem) )
      {
        this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                     this,
                                     i: elem)].m_Left = m_Left;
      }
      else
      {
        this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Parent(
                                     this,
                                     i: elem)].m_Right = m_Left;
      }
      if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::LeftChild(
             this,
             i: m_Left) != -1 )
        this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::LeftChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RightChild(
             this,
             i: m_Left) != -1 )
        this->m_Elements.m_pMemory[CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RightChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      this->m_Elements.m_pMemory[v9].m_Tag = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Color(
                                               this,
                                               i: elem);
      v8 = x;
    }
    if ( v8 != -1 && ycolor == BLACK )
      CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RemoveRebalance(
        this,
        elem: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A660
// Name: protected: void CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::LinkToParent(unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::LinkToParent(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this,
        unsigned int i,
        unsigned int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *v4; // eax
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A6D0
// Name: protected: void CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::LinkToParent(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<ReferencedFile,int> *v4; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A740
// Name: public: ReferencedFile::ReferencedFile(struct ReferencedFile const __near &)
// Source: json
//------------------------------------------------------------------------------
ReferencedFile *__thiscall ReferencedFile::ReferencedFile(ReferencedFile *this, const ReferencedFile *src)
{
  const ReferencedFile *v2; // eax
  ReferencedFile *v3; // edx
  int v4; // ebx
  CUtlMemory<KeyValues *,int> *p_maplist; // esi
  KeyValues **m_pMemory; // edi
  int v7; // ecx
  int m_nAllocationCount; // eax
  KeyValues **v9; // ecx
  int v10; // eax
  KeyValues **v11; // eax
  int c; // [esp+8h] [ebp-Ch]
  KeyValues **v14; // [esp+Ch] [ebp-8h]

  v2 = src;
  v3 = this;
  this->sym.m_Id = -1;
  v4 = 0;
  p_maplist = (CUtlMemory<KeyValues *,int> *)&this->maplist;
  this->maplist.m_Memory.m_pMemory = nullptr;
  this->maplist.m_Memory.m_nAllocationCount = 0;
  this->maplist.m_Memory.m_nGrowSize = 0;
  this->maplist.m_Size = 0;
  this->maplist.m_pElements = nullptr;
  this->sym.m_Id = src->sym.m_Id;
  this->maplist.m_Size = 0;
  c = src->maplist.m_Size;
  if ( c > 0 )
  {
    while ( 1 )
    {
      m_pMemory = p_maplist[1].m_pMemory;
      v7 = (int)&v2->maplist.m_Memory.m_pMemory[v4];
      m_nAllocationCount = p_maplist->m_nAllocationCount;
      v14 = (KeyValues **)v7;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
      {
        CUtlMemory<UnusedContent::CUtlSymbol,int>::Grow(this: p_maplist, num: (int)m_pMemory - m_nAllocationCount + 1);
        v3 = this;
      }
      ++p_maplist[1].m_pMemory;
      v9 = p_maplist->m_pMemory;
      v10 = (char *)p_maplist[1].m_pMemory - (char *)m_pMemory - 1;
      p_maplist[1].m_nAllocationCount = (int)p_maplist->m_pMemory;
      if ( v10 > 0 )
      {
        _V_memmove(dest: &v9[(_DWORD)m_pMemory + 1], src: &v9[(_DWORD)m_pMemory], count: 4 * v10);
        v3 = this;
      }
      v11 = &p_maplist->m_pMemory[(_DWORD)m_pMemory];
      if ( v11 != nullptr )
        *v11 = *v14;
      if ( ++v4 >= c )
        break;
      v2 = src;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040A800
// Name: public: CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>::~CUtlRBTree<class UnusedContent::CUtlSymbol,int,bool (*)(class UnusedContent::CUtlSymbol const __near &,class UnusedContent::CUtlSymbol const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbol,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::~CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>(
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *this)
{
  CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A860
// Name: public: int CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::NewNode(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  ReferencedFile *p_m_Data; // ecx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>::Grow(this: &this->m_Elements, num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    this->m_LastAlloc.index = v6;
    result = v6;
  }
  else
  {
    this->m_FirstFree = this->m_Elements.m_pMemory[result].m_Right;
  }
  p_m_Data = &this->m_Elements.m_pMemory[result].m_Data;
  if ( &this->m_Elements.m_pMemory[result] != (UtlRBTreeNode_t<ReferencedFile,int> *)-16 )
  {
    this->m_Elements.m_pMemory[result].m_Data.maplist.m_Memory.m_pMemory = nullptr;
    p_m_Data->maplist.m_Memory.m_nAllocationCount = 0;
    p_m_Data->maplist.m_Memory.m_nGrowSize = 0;
    p_m_Data->maplist.m_Size = 0;
    p_m_Data->maplist.m_pElements = nullptr;
    p_m_Data->sym.m_Id = -1;
  }
  this->m_pElements = this->m_Elements.m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A950
// Name: public: unsigned int CUtlRBTree<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (*)(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &,class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Insert(class UnusedContent::CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Insert(
        CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *this,
        const UnusedContent::CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned int v3; // edi
  UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *m_pMemory; // edx
  unsigned int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::NewNode(this);
  CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)-16 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040A9C0
// Name: public: void CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RemoveAll(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this)
{
  int index; // eax
  BOOL v3; // ecx
  int v4; // esi
  int v5; // edi

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = this->m_Elements.m_nAllocationCount > 0;
    v4 = v3 - 1;
    if ( v3 )
    {
      do
      {
        if ( v4 >= 0 && v4 < this->m_Elements.m_nAllocationCount && v4 <= index )
        {
          if ( (`CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4470BC = -1;
            dword_4470C0 = -1;
            dword_4470C4 = 1;
          }
          if ( this->m_Elements.m_pMemory[v4].m_Left != v4 )
          {
            v5 = v4;
            CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_Elements.m_pMemory[v4].m_Data.maplist);
            this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v5].m_Left = v4;
            this->m_FirstFree = v4;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        if ( ++v4 < 0 || v4 >= this->m_Elements.m_nAllocationCount )
          v4 = -1;
      }
      while ( v4 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AAA0
// Name: public: class UnusedContent::CUtlSymbol UnusedContent::CUtlSymbolTable::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
UnusedContent::CUtlSymbol *__thiscall UnusedContent::CUtlSymbolTable::AddString(
        UnusedContent::CUtlSymbolTable *this,
        UnusedContent::CUtlSymbol *result,
        char *pString)
{
  UnusedContent::CUtlSymbolTable *v3; // esi
  unsigned int v5; // eax
  signed int m_iOffset; // edi
  int m_Size; // ecx
  signed int v8; // eax
  UnusedContent::CUtlSymbolTable::StringPool_t **m_pMemory; // edx
  CUtlMemory<KeyValues *,int> *p_m_StringPools; // esi
  unsigned int v11; // ebx
  signed int *v12; // ebx
  unsigned int v13; // edi
  int m_nAllocationCount; // eax
  KeyValues **v15; // ecx
  int v16; // eax
  KeyValues **v17; // eax
  KeyValues *v18; // esi
  unsigned int m_sValue; // edi
  UnusedContent::CUtlSymbolTable::CStringPoolIndex index; // [esp+8h] [ebp-14h] BYREF
  CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl*)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int> > *p_m_Lookup; // [esp+10h] [ebp-Ch]
  UnusedContent::CUtlSymbolTable::CStringPoolIndex search; // [esp+14h] [ebp-8h] BYREF

  v3 = this;
  p_m_Lookup = &this->m_Lookup;
  if ( pString != nullptr )
  {
    search.m_iPool = 0xFFFF;
    search.m_iOffset = 0xFFFF;
    g_LessCtx.m_pUserString = pString;
    g_LessCtx.m_pTable = this;
    v5 = CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Find(
           this: &this->m_Lookup,
           &search);
    if ( v5 == -1 )
    {
      m_iOffset = strlen(pString) + 1;
      m_Size = v3->m_StringPools.m_Size;
      v8 = 0;
      search.m_iOffset = m_iOffset;
      if ( m_Size > 0 )
      {
        m_pMemory = v3->m_StringPools.m_Memory.m_pMemory;
        p_m_StringPools = (CUtlMemory<KeyValues *,int> *)&v3->m_StringPools;
        while ( 1 )
        {
          m_iOffset = search.m_iOffset;
          if ( (*m_pMemory)->m_TotalLen - (*m_pMemory)->m_SpaceUsed >= (int)search.m_iOffset )
            break;
          ++v8;
          ++m_pMemory;
          if ( v8 >= m_Size )
            goto LABEL_11;
        }
        v11 = v8;
        if ( v8 != -1 )
          goto LABEL_21;
        m_iOffset = search.m_iOffset;
LABEL_11:
        v3 = (UnusedContent::CUtlSymbolTable *)p_m_Lookup;
      }
      if ( m_iOffset <= 2048 )
        m_iOffset = 2048;
      v12 = (signed int *)operator new(nSize: m_iOffset + 11);
      p_m_StringPools = (CUtlMemory<KeyValues *,int> *)&v3->m_StringPools;
      *v12 = m_iOffset;
      v12[1] = 0;
      v13 = (unsigned int)p_m_StringPools[1].m_pMemory;
      m_nAllocationCount = p_m_StringPools->m_nAllocationCount;
      if ( (int)(v13 + 1) > m_nAllocationCount )
        CUtlMemory<UnusedContent::CUtlSymbol,int>::Grow(this: p_m_StringPools, num: v13 - m_nAllocationCount + 1);
      ++p_m_StringPools[1].m_pMemory;
      v15 = p_m_StringPools->m_pMemory;
      v16 = (int)p_m_StringPools[1].m_pMemory - v13 - 1;
      p_m_StringPools[1].m_nAllocationCount = (int)p_m_StringPools->m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &v15[v13 + 1], src: &v15[v13], count: 4 * v16);
      v17 = &p_m_StringPools->m_pMemory[v13];
      if ( v17 != nullptr )
        *v17 = (KeyValues *)v12;
      v11 = v13;
LABEL_21:
      v18 = p_m_StringPools->m_pMemory[v11];
      m_sValue = (unsigned int)v18->m_sValue;
      memcpy(
        dst: (unsigned __int8 *)&v18->m_wsValue + m_sValue,
        src: (unsigned __int8 *)pString,
        count: search.m_iOffset);
      v18->m_sValue += search.m_iOffset;
      index.m_iPool = v11;
      index.m_iOffset = m_sValue;
      v5 = CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Insert(
             this: p_m_Lookup,
             insert: &index);
    }
    result->m_Id = v5;
    return result;
  }
  else
  {
    result->m_Id = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AC00
// Name: void logprint(char const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void logprint(char *logfile, char *fmt, ...)
{
  int v2; // eax
  int v3; // esi
  _DWORD *v4; // ecx
  unsigned int m_iOffset; // edx
  _iobuf *v6; // eax
  _iobuf *v7; // edi
  char *i; // esi
  char string[8192]; // [esp+Ch] [ebp-2010h] BYREF
  UnusedContent::CUtlSymbolTable::CStringPoolIndex search; // [esp+200Ch] [ebp-10h] BYREF
  UnusedContent::CUtlSymbol insert; // [esp+2014h] [ebp-8h] BYREF
  bool leftchild; // [esp+201Bh] [ebp-1h] BYREF
  va_list ap; // [esp+202Ch] [ebp+10h] BYREF

  va_start(ap, fmt);
  vsprintf(string, format: fmt, ap);
  if ( logfile != nullptr )
  {
    search.m_iPool = 0xFFFF;
    search.m_iOffset = 0xFFFF;
    g_LessCtx.m_pUserString = logfile;
    g_LessCtx.m_pTable = (UnusedContent::CUtlSymbolTable *)&g_Analysis;
    insert.m_Id = CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::Find(
                    this: &g_Analysis.symbols.m_Lookup,
                    &search);
  }
  else
  {
    insert.m_Id = -1;
  }
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = (int)CDefOps<UnusedContent::CUtlSymbol>::LessFunc;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = 0;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = 0;
    `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = nullptr;
    unk_447104 = -1;
    unk_447108 = 0;
    unk_44710C = -1;
    unk_447110 = -1;
    unk_447114 = 0;
    atexit(func: logprint_::_2_::_dynamic_atexit_destructor_for__previousfiles__);
  }
  if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Find(
         this: (CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements,
         search: &insert) == -1 )
  {
    search.m_iOffset = -1;
    leftchild = false;
    CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::FindInsertionPosition(
      this: (CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements,
      &insert,
      parent: (int *)&search.m_iOffset,
      &leftchild);
    v2 = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::NewNode(this: (CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements);
    v3 = 20 * v2;
    v4 = (_DWORD *)(20 * v2
                  + `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree);
    m_iOffset = search.m_iOffset;
    v4[2] = search.m_iOffset;
    v4[1] = -1;
    *v4 = -1;
    v4[3] = 0;
    if ( m_iOffset == -1 )
    {
      unk_447104 = v2;
    }
    else if ( leftchild )
    {
      *(_DWORD *)(`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree
                + 20 * m_iOffset) = v2;
    }
    else
    {
      *(_DWORD *)(`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree
                + 20 * m_iOffset
                + 4) = v2;
    }
    CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::InsertRebalance(
      this: (CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements,
      elem: v2);
    ++unk_447108;
    if ( v3
       + `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree != -16 )
      *(UnusedContent::CUtlSymbol *)(v3
                                   + `CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree
                                   + 16) = insert;
    v6 = fopen(file: logfile, mode: "wb");
  }
  else
  {
    v6 = fopen(file: logfile, mode: "ab");
  }
  v7 = v6;
  if ( v6 != nullptr )
  {
    for ( i = string; *i != 0; fputc(ch: *i++, str: v7) )
    {
      if ( *i == 10 )
        fputc(ch: 13, str: v7);
    }
    fclose(stream: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040ADC0
// Name: void BuildFileList_R(int,class CUtlVector<struct FileEntry,class CUtlMemory<struct FileEntry,int>> __near &,class CUtlVector<struct FileEntry,class CUtlMemory<struct FileEntry,int>> __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildFileList_R(
        int depth,
        CUtlVector<FileEntry,CUtlMemory<FileEntry,int> > *files,
        CUtlVector<FileEntry,CUtlMemory<FileEntry,int> > *otherfiles,
        const char *dir,
        const char *wild,
        int skipchars)
{
  const char *v6; // ecx
  const char *v7; // eax
  const char *v8; // eax
  bool v9; // bl
  CUtlVector<FileEntry,CUtlMemory<FileEntry,int> > *v10; // eax
  unsigned int (__thiscall *Size)(IBaseFileSystem *, const char *, const char *); // edx
  int v12; // eax
  unsigned int v13; // ecx
  int m_Size; // eax
  char directory[256]; // [esp+4h] [ebp-45Ch] BYREF
  char filename[256]; // [esp+104h] [ebp-35Ch] BYREF
  char pDest[260]; // [esp+204h] [ebp-25Ch] BYREF
  _WIN32_FIND_DATAA wfd; // [esp+308h] [ebp-158h] BYREF
  FileEntry entry; // [esp+448h] [ebp-18h] BYREF
  void *ff; // [esp+454h] [ebp-Ch]
  int dirlen; // [esp+458h] [ebp-8h]
  UnusedContent::CUtlSymbol sym; // [esp+45Ch] [ebp-4h] BYREF

  if ( _V_stricmp(s1: wild, s2: "...") != 0 )
  {
    v8 = "\\";
    if ( *dir == 0 )
      v8 = ::dir;
    sprintf(string: directory, format: "%s%s%s", dir, v8, wild);
  }
  else
  {
    v6 = "\\";
    if ( *dir == 0 )
      v6 = ::dir;
    v7 = dir + 1;
    if ( *dir != 92 )
      v7 = dir;
    sprintf(string: directory, format: "%s%s%s", v7, v6, "*.*");
  }
  dirlen = _V_strlen(str: dir);
  ff = FindFirstFileA(lpFileName: directory, lpFindFileData: &wfd);
  if ( ff != (void *)-1 )
  {
    do
    {
      if ( (wfd.dwFileAttributes & 0x10) != 0 )
      {
        v9 = false;
        if ( wfd.cFileName[0] != 46 )
        {
          if ( depth == 0 && ShouldCheckDir(dirname: wfd.cFileName) == 0 && otherfiles != nullptr )
            v9 = ShouldIgnoreDir(dirname: wfd.cFileName) == 0;
          if ( *dir != 0 )
            sprintf(string: filename, format: "%s\\%s", dir, wfd.cFileName);
          else
            sprintf(string: filename, format: "%s", wfd.cFileName);
          v10 = otherfiles;
          if ( !v9 )
            v10 = files;
          BuildFileList_R(depth: depth + 1, files: v10, otherfiles: nullptr, dir: filename, wild, skipchars);
        }
      }
      else if ( _V_stricmp(s1: wfd.cFileName, s2: "vssver.scc") != 0 )
      {
        if ( dirlen > skipchars )
          V_snprintf(pDest, maxLen: 260, pFormat: "%s\\%s", &dir[skipchars], wfd.cFileName);
        else
          V_snprintf(pDest, maxLen: 260, pFormat: "%s", wfd.cFileName);
        strlwr(string: pDest);
        V_FixSlashes(pname: pDest, separator: 92);
        UnusedContent::CUtlSymbolTable::AddString(this: &g_Analysis.symbols, result: &sym, pString: pDest);
        entry.sym = sym;
        Size = g_pFileSystem->Size;
        entry.referenced = 0;
        v12 = Size(this: g_pFileSystem, a2: pDest, a3: nullptr);
        v13 = v12 < 0 ? 0 : v12;
        m_Size = files->m_Size;
        entry.size = v13;
        CUtlVector<FileEntry,CUtlMemory<FileEntry,int>>::InsertBefore(this: files, elem: m_Size, src: &entry);
        if ( files->m_Size % 3000 == 0 )
          vprint(depth: 0, fmt: "...found %i files\n", files->m_Size);
      }
    }
    while ( FindNextFileA(hFindFile: ff, lpFindFileData: &wfd) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B050
// Name: void AddCheckdir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddCheckdir(char *dirname)
{
  int m_Size; // eax
  int v2; // esi
  UnusedContent::CUtlSymbol *m_pMemory; // ecx
  int v4; // eax
  UnusedContent::CUtlSymbol *v5; // eax
  UnusedContent::CUtlSymbol sym; // [esp+8h] [ebp-4h] BYREF

  UnusedContent::CUtlSymbolTable::AddString(this: &g_Analysis.symbols, result: &sym, pString: dirname);
  m_Size = g_DirList.m_Size;
  v2 = g_DirList.m_Size;
  if ( g_DirList.m_Size + 1 > g_DirList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<UnusedContent::CUtlSymbol,int>::Grow(
      this: (CUtlMemory<KeyValues *,int> *)&g_DirList,
      num: g_DirList.m_Size - g_DirList.m_Memory.m_nAllocationCount + 1);
    m_Size = g_DirList.m_Size;
  }
  m_pMemory = g_DirList.m_Memory.m_pMemory;
  g_DirList.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  g_DirList.m_pElements = g_DirList.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(dest: &g_DirList.m_Memory.m_pMemory[v2 + 1], src: &g_DirList.m_Memory.m_pMemory[v2], count: 4 * v4);
    m_pMemory = g_DirList.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    v5->m_Id = sym.m_Id;
  vprint(depth: 1, fmt: "AddCheckdir[ \"%s\" ]\n", dirname);
}

//------------------------------------------------------------------------------
// Address: 0x0040B0F0
// Name: void AddIgnoredir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddIgnoredir(char *dirname)
{
  int m_Size; // eax
  int v2; // esi
  UnusedContent::CUtlSymbol *m_pMemory; // ecx
  int v4; // eax
  UnusedContent::CUtlSymbol *v5; // eax
  UnusedContent::CUtlSymbol sym; // [esp+8h] [ebp-4h] BYREF

  UnusedContent::CUtlSymbolTable::AddString(this: &g_Analysis.symbols, result: &sym, pString: dirname);
  m_Size = g_IgnoreDir.m_Size;
  v2 = g_IgnoreDir.m_Size;
  if ( g_IgnoreDir.m_Size + 1 > g_IgnoreDir.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<UnusedContent::CUtlSymbol,int>::Grow(
      this: (CUtlMemory<KeyValues *,int> *)&g_IgnoreDir,
      num: g_IgnoreDir.m_Size - g_IgnoreDir.m_Memory.m_nAllocationCount + 1);
    m_Size = g_IgnoreDir.m_Size;
  }
  m_pMemory = g_IgnoreDir.m_Memory.m_pMemory;
  g_IgnoreDir.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  g_IgnoreDir.m_pElements = g_IgnoreDir.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(dest: &g_IgnoreDir.m_Memory.m_pMemory[v2 + 1], src: &g_IgnoreDir.m_Memory.m_pMemory[v2], count: 4 * v4);
    m_pMemory = g_IgnoreDir.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    v5->m_Id = sym.m_Id;
  vprint(depth: 1, fmt: "AddIgnoredir[ \"%s\" ]\n", dirname);
}

//------------------------------------------------------------------------------
// Address: 0x0040B190
// Name: void BuildCheckdirList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildCheckdirList()
{
  KeyValues *v0; // eax
  KeyValues *v1; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  char *v4; // eax
  const char *v5; // eax
  char *String; // eax
  const char *v7; // eax
  char **v8; // esi
  char **v9; // esi

  vprint(depth: 0, fmt: "Checking for dirlist\n");
  if ( g_pFileSystem->FileExists(this: g_pFileSystem, a2: "unusedcontent.cfg", a3: "GAME") )
  {
    v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v0 != nullptr )
    {
      v1 = KeyValues::KeyValues(this: v0, setName: "unusedcontent.cfg");
      if ( v1 != nullptr )
      {
        if ( KeyValues::LoadFromFile(
               this: v1,
               filesystem: g_pFileSystem,
               resourceName: "unusedcontent.cfg",
               pathID: "GAME",
               pfnEvaluateSymbolProc: nullptr) )
        {
          for ( i = KeyValues::GetFirstSubKey(this: v1); i != nullptr; i = KeyValues::GetNextKey(this: i) )
          {
            Name = KeyValues::GetName(this: i);
            if ( _V_stricmp(s1: Name, s2: "dir") != 0 )
            {
              v5 = KeyValues::GetName(this: i);
              if ( _V_stricmp(s1: v5, s2: "ignore") != 0 )
              {
                v7 = KeyValues::GetName(this: i);
                vprint(depth: 1, fmt: "Unknown subkey '%s' in %s\n", v7, "unusedcontent.cfg");
              }
              else
              {
                String = (char *)KeyValues::GetString(this: i, keyName: nullptr, defaultValue: dir);
                AddIgnoredir(dirname: String);
              }
            }
            else
            {
              v4 = (char *)KeyValues::GetString(this: i, keyName: nullptr, defaultValue: dir);
              AddCheckdir(dirname: v4);
            }
          }
        }
        KeyValues::deleteThis(this: v1);
      }
    }
  }
  else
  {
    v8 = directories_to_check;
    do
      AddCheckdir(dirname: *v8++);
    while ( (int)v8 < (int)directories_to_ignore );
    v9 = directories_to_ignore;
    do
      AddIgnoredir(dirname: *v9++);
    while ( (int)v9 < (int)&random );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B300
// Name: void AddToWhiteList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddToWhiteList(const char *path)
{
  _BYTE *v1; // eax
  int v2; // eax
  int v3; // edx
  int v4; // esi
  UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *v5; // ecx
  int v6; // edx
  FileEntry *m_pMemory; // eax
  char *v8; // [esp-Ch] [ebp-23Ch]
  char *v9; // [esp-8h] [ebp-238h]
  char dir[512]; // [esp+8h] [ebp-228h] BYREF
  int i; // [esp+208h] [ebp-28h]
  int parent; // [esp+20Ch] [ebp-24h] BYREF
  CUtlVector<FileEntry,CUtlMemory<FileEntry,int> > files; // [esp+210h] [ebp-20h] BYREF
  unsigned int v14; // [esp+224h] [ebp-Ch]
  UnusedContent::CUtlSymbol sym; // [esp+228h] [ebp-8h] BYREF
  bool leftchild; // [esp+22Fh] [ebp-1h] BYREF

  vprint(depth: 2, fmt: "+\t'%s'\n", path);
  V_strncpy(pDest: dir, pSrc: path, maxLen: 512);
  strlwr(string: dir);
  V_FixSlashes(pname: dir, separator: 92);
  memset(&files, 0, sizeof(files));
  strrchr(string: (unsigned __int8 *)dir, chr: 0x5Cu);
  if ( v1 != nullptr )
  {
    v9 = v1 + 1;
    *v1 = 0;
    v8 = dir;
  }
  else
  {
    v9 = dir;
    v8 = (char *)::dir;
  }
  files.m_Size = 0;
  BuildFileList_R(depth: 1, &files, otherfiles: nullptr, dir: v8, wild: v9, skipchars: 0);
  if ( files.m_Size > 0 )
  {
    v14 = 0;
    for ( i = files.m_Size; i != 0; --i )
    {
      sym.m_Id = files.m_Memory.m_pMemory[v14 / 0xC].sym.m_Id;
      if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Find(
             this: &g_WhiteList,
             search: &sym) == -1 )
      {
        parent = -1;
        leftchild = false;
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::FindInsertionPosition(
          this: &g_WhiteList,
          insert: &sym,
          &parent,
          &leftchild);
        v2 = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::NewNode(this: &g_WhiteList);
        v3 = parent;
        v4 = v2;
        v5 = &g_WhiteList.m_Elements.m_pMemory[v2];
        v5->m_Parent = parent;
        v5->m_Right = -1;
        v5->m_Left = -1;
        v5->m_Tag = 0;
        if ( v3 == -1 )
        {
          g_WhiteList.m_Root = v2;
        }
        else
        {
          v6 = v3;
          if ( leftchild )
            g_WhiteList.m_Elements.m_pMemory[v6].m_Left = v2;
          else
            g_WhiteList.m_Elements.m_pMemory[v6].m_Right = v2;
        }
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::InsertRebalance(
          this: &g_WhiteList,
          elem: v2);
        ++g_WhiteList.m_NumElements;
        if ( &g_WhiteList.m_Elements.m_pMemory[v4] != (UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int> *)-16 )
          g_WhiteList.m_Elements.m_pMemory[v4].m_Data = sym;
        ++wl_added;
      }
      v14 += 12;
    }
  }
  m_pMemory = files.m_Memory.m_pMemory;
  files.m_Size = 0;
  if ( files.m_Memory.m_nGrowSize >= 0 )
  {
    if ( files.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: files.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      files.m_Memory.m_pMemory = nullptr;
    }
    files.m_Memory.m_nAllocationCount = 0;
  }
  files.m_pElements = m_pMemory;
  if ( files.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040B4D0
// Name: void RemoveFromWhiteList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveFromWhiteList(const char *path)
{
  int v1; // edi
  _BYTE *v2; // eax
  int i; // ebx
  int v4; // eax
  int v5; // esi
  int v6; // eax
  FileEntry *m_pMemory; // eax
  char *v8; // [esp-Ch] [ebp-22Ch]
  char *v9; // [esp-8h] [ebp-228h]
  char dir[512]; // [esp+8h] [ebp-218h] BYREF
  UnusedContent::CUtlSymbol sym; // [esp+208h] [ebp-18h] BYREF
  CUtlVector<FileEntry,CUtlMemory<FileEntry,int> > files; // [esp+20Ch] [ebp-14h] BYREF

  vprint(depth: 2, fmt: "-\t'%s'\n", path);
  V_strncpy(pDest: dir, pSrc: path, maxLen: 512);
  strlwr(string: dir);
  V_FixSlashes(pname: dir, separator: 92);
  v1 = 0;
  memset(&files, 0, sizeof(files));
  strrchr(string: (unsigned __int8 *)dir, chr: 0x5Cu);
  if ( v2 != nullptr )
  {
    v9 = v2 + 1;
    *v2 = 0;
    v8 = dir;
  }
  else
  {
    v9 = dir;
    v8 = (char *)::dir;
  }
  files.m_Size = 0;
  BuildFileList_R(depth: 1, &files, otherfiles: nullptr, dir: v8, wild: v9, skipchars: 0);
  if ( files.m_Size > 0 )
  {
    for ( i = files.m_Size; i != 0; --i )
    {
      sym.m_Id = files.m_Memory.m_pMemory[v1].sym.m_Id;
      v4 = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Find(
             this: &g_WhiteList,
             search: &sym);
      v5 = v4;
      if ( v4 != -1 )
      {
        CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Unlink(
          this: &g_WhiteList,
          elem: v4);
        v6 = v5;
        g_WhiteList.m_Elements.m_pMemory[v6].m_Left = v5;
        g_WhiteList.m_Elements.m_pMemory[v6].m_Right = g_WhiteList.m_FirstFree;
        --g_WhiteList.m_NumElements;
        ++wl_removed;
        g_WhiteList.m_FirstFree = v5;
      }
      ++v1;
    }
  }
  m_pMemory = files.m_Memory.m_pMemory;
  files.m_Size = 0;
  if ( files.m_Memory.m_nGrowSize >= 0 )
  {
    if ( files.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: files.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      files.m_Memory.m_pMemory = nullptr;
    }
    files.m_Memory.m_nAllocationCount = 0;
  }
  files.m_pElements = m_pMemory;
  if ( files.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040B640
// Name: void BuildWhiteList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildWhiteList()
{
  KeyValues *v0; // eax
  KeyValues *v1; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *String; // eax
  const char *v7; // eax
  int j; // esi
  unsigned int m_Id; // eax
  const char *v10; // eax
  int k; // esi
  unsigned int v12; // eax
  const char *v13; // eax

  if ( g_pFileSystem->FileExists(this: g_pFileSystem, a2: "whitelist.cfg", a3: nullptr) )
  {
    vprint(depth: 1, fmt: "\nBuilding whitelist\n");
    v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v0 != nullptr )
    {
      v1 = KeyValues::KeyValues(this: v0, setName: "whitelist.cfg");
      if ( v1 != nullptr )
      {
        if ( KeyValues::LoadFromFile(
               this: v1,
               filesystem: g_pFileSystem,
               resourceName: "whitelist.cfg",
               pathID: nullptr,
               pfnEvaluateSymbolProc: nullptr) )
        {
          for ( i = KeyValues::GetFirstSubKey(this: v1); i != nullptr; i = KeyValues::GetNextKey(this: i) )
          {
            Name = KeyValues::GetName(this: i);
            if ( _V_stricmp(s1: Name, s2: "add") != 0 )
            {
              v5 = KeyValues::GetName(this: i);
              if ( _V_stricmp(s1: v5, s2: "remove") != 0 )
              {
                v7 = KeyValues::GetName(this: i);
                vprint(depth: 1, fmt: "Unknown subkey '%s' in %s\n", v7, "whitelist.cfg");
              }
              else
              {
                String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: dir);
                RemoveFromWhiteList(path: String);
              }
            }
            else
            {
              v4 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: dir);
              AddToWhiteList(path: v4);
            }
          }
        }
        KeyValues::deleteThis(this: v1);
      }
    }
    if ( verbose != 0 || printwhitelist )
    {
      vprint(depth: 1, fmt: "Whitelist:\n\n");
      for ( j = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::FirstInorder(this: &g_WhiteList);
            j != -1;
            j = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::NextInorder(
                  this: &g_WhiteList,
                  i: j) )
      {
        m_Id = g_WhiteList.m_Elements.m_pMemory[j].m_Data.m_Id;
        if ( m_Id == -1 )
          v10 = dir;
        else
          v10 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[m_Id].m_Data.m_iOffset];
        vprint(depth: 2, fmt: "  %s\n", v10);
      }
    }
    filesystem->RemoveFile(this: filesystem, a2: "whitelist_files.txt", a3: "GAME");
    for ( k = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::FirstInorder(this: &g_WhiteList);
          k != -1;
          k = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::NextInorder(
                this: &g_WhiteList,
                i: k) )
    {
      v12 = g_WhiteList.m_Elements.m_pMemory[k].m_Data.m_Id;
      if ( v12 == -1 )
        v13 = dir;
      else
        v13 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v12].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v12].m_Data.m_iOffset];
      logprint(logfile: "whitelist_files.txt", fmt: "\"%s\"\n", v13);
    }
    vprint(
      depth: 1,
      fmt: "Whitelist resolves to %d files (added %i/removed %i)\n\n",
      g_WhiteList.m_NumElements,
      wl_added,
      wl_removed);
  }
  else
  {
    vprint(depth: 1, fmt: "Running with no whitelist.cfg file!!!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B8C0
// Name: public: int CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>>::Insert(struct ReferencedFile const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Insert(
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *this,
        const ReferencedFile *insert)
{
  int v3; // edi
  UtlRBTreeNode_t<ReferencedFile,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::NewNode(this);
  CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<ReferencedFile,int> *)-16 )
    ReferencedFile::ReferencedFile(this: &m_pMemory[v3].m_Data, src: insert);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040B930
// Name: void ParseFilesFromResList(class UnusedContent::CUtlSymbol __near &,class CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall ParseFilesFromResList(
        int a1@<esi>,
        UnusedContent::CUtlSymbol *resfilesymbol,
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *files,
        const char *resfile)
{
  void *v4; // edi
  int v5; // esi
  char *v6; // edi
  unsigned int v7; // kr04_4
  int v8; // esi
  int v9; // eax
  int m_Size; // eax
  int v11; // esi
  UnusedContent::CUtlSymbol *m_pMemory; // ecx
  int v13; // eax
  UnusedContent::CUtlSymbol *v14; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *v15; // edx
  int p_m_Data; // esi
  char token[512]; // [esp+8h] [ebp-43Ch] BYREF
  char basedir[260]; // [esp+208h] [ebp-23Ch] BYREF
  char szFileName[260]; // [esp+30Ch] [ebp-138h] BYREF
  UnusedContent::CUtlSymbol result; // [esp+410h] [ebp-34h] BYREF
  int offset; // [esp+414h] [ebp-30h]
  char *pStart; // [esp+418h] [ebp-2Ch]
  ReferencedFile rf; // [esp+41Ch] [ebp-28h] BYREF
  void *resfilehandle; // [esp+434h] [ebp-10h]
  char *pFileList; // [esp+438h] [ebp-Ch]
  int addedStrings; // [esp+43Ch] [ebp-8h]
  int resourcesConsidered; // [esp+440h] [ebp-4h]

  addedStrings = 0;
  resourcesConsidered = 0;
  offset = _V_strlen(str: gamedir);
  V_strncpy(pDest: basedir, pSrc: gamedir, maxLen: 260);
  if ( !V_StripLastDir(dirName: basedir, maxlen: 260) )
    _Error(a1: "Can't get basedir from %s.", gamedir);
  v4 = g_pFileSystem->Open(this: g_pFileSystem, a2: resfile, a3: "rb", a4: 0);
  resfilehandle = v4;
  if ( v4 != nullptr )
  {
    v5 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(a1: g_pFileSystem, a2: v4, a3: a1);
    if ( v5 > 0 )
    {
      v6 = (char *)operator new(nSize: v5 + 1);
      pStart = v6;
      if ( v6 != nullptr && v5 == g_pFileSystem->Read(this: g_pFileSystem, a2: v6, a3: v5, a4: resfilehandle) )
      {
        v6[v5] = 0;
        pFileList = ParseFile(pFileBytes: v6, pToken: token, pWasQuoted: nullptr);
        if ( pFileList != nullptr )
        {
          do
          {
            if ( strlen(token) != 0 )
            {
              V_snprintf(pDest: szFileName, maxLen: 256, pFormat: "%s%s", basedir, token);
              strlwr(string: szFileName);
              V_FixSlashes(pname: szFileName, separator: 92);
              while ( 1 )
              {
                v7 = strlen(szFileName);
                if ( szFileName[v7 - 1] != 10 && szFileName[v7 - 1] != 13 )
                  break;
                szFileName[v7 - 1] = 0;
              }
              v8 = offset;
              if ( V_strnicmp(s1: szFileName, s2: gamedir, n: offset) == 0 )
              {
                ++resourcesConsidered;
                memset(&rf.maplist, 0, sizeof(rf.maplist));
                rf.sym.m_Id = -1;
                rf.sym = (UnusedContent::CUtlSymbol)UnusedContent::CUtlSymbolTable::AddString(
                                                      this: &g_Analysis.symbols,
                                                      &result,
                                                      pString: &szFileName[v8])->m_Id;
                v9 = CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Find(
                       this: files,
                       search: &rf);
                if ( v9 == -1 )
                {
                  m_Size = rf.maplist.m_Size;
                  ++addedStrings;
                  v11 = rf.maplist.m_Size;
                  if ( rf.maplist.m_Size + 1 > rf.maplist.m_Memory.m_nAllocationCount )
                  {
                    CUtlMemory<UnusedContent::CUtlSymbol,int>::Grow(
                      this: (CUtlMemory<KeyValues *,int> *)&rf.maplist,
                      num: rf.maplist.m_Size - rf.maplist.m_Memory.m_nAllocationCount + 1);
                    m_Size = rf.maplist.m_Size;
                  }
                  m_pMemory = rf.maplist.m_Memory.m_pMemory;
                  rf.maplist.m_Size = m_Size + 1;
                  v13 = m_Size - v11;
                  rf.maplist.m_pElements = rf.maplist.m_Memory.m_pMemory;
                  if ( v13 > 0 )
                  {
                    _V_memmove(
                      dest: &rf.maplist.m_Memory.m_pMemory[v11 + 1],
                      src: &rf.maplist.m_Memory.m_pMemory[v11],
                      count: 4 * v13);
                    m_pMemory = rf.maplist.m_Memory.m_pMemory;
                  }
                  v14 = &m_pMemory[v11];
                  if ( v14 != nullptr )
                    v14->m_Id = resfilesymbol->m_Id;
                  CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Insert(
                    this: files,
                    insert: &rf);
                }
                else
                {
                  v15 = files->m_Elements.m_pMemory;
                  p_m_Data = (int)&v15[v9].m_Data;
                  if ( CUtlVector<UnusedContent::CUtlSymbol,CUtlMemory<UnusedContent::CUtlSymbol,int>>::Find(
                         this: &v15[v9].m_Data.maplist,
                         src: resfilesymbol) == -1 )
                    CUtlVector<UnusedContent::CUtlSymbol,CUtlMemory<UnusedContent::CUtlSymbol,int>>::InsertBefore(
                      this: (CUtlVector<UnusedContent::CUtlSymbol,CUtlMemory<UnusedContent::CUtlSymbol,int> > *)(p_m_Data + 4),
                      elem: *(_DWORD *)(p_m_Data + 16),
                      src: resfilesymbol);
                }
                CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&rf.maplist);
              }
            }
            pFileList = ParseFile(pFileBytes: pFileList, pToken: token, pWasQuoted: nullptr);
          }
          while ( pFileList != nullptr );
          v6 = pStart;
        }
      }
      free(pMem: v6);
      v4 = resfilehandle;
    }
    g_pFileSystem->Close(this: g_pFileSystem, a2: v4);
  }
  vprint(depth: 1, fmt: "Found %i new resources (%i total) in %s\n", addedStrings, resourcesConsidered, resfile);
}

//------------------------------------------------------------------------------
// Address: 0x0040BC20
// Name: bool BuildReferencedFileList(class CUtlVector<class UnusedContent::CUtlSymbol,class CUtlMemory<class UnusedContent::CUtlSymbol,int>> __near &,class CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BuildReferencedFileList(
        CUtlVector<UnusedContent::CUtlSymbol,CUtlMemory<UnusedContent::CUtlSymbol,int> > *resfiles,
        CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > *files,
        const char *resfile)
{
  void *v3; // ebx
  int v4; // edi
  char *v5; // ebx
  char *i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  UnusedContent::CUtlSymbol *m_pMemory; // ecx
  int v10; // eax
  UnusedContent::CUtlSymbol *v11; // eax
  CFmtStrN<256> *v12; // eax
  CFmtStrN<256> *v13; // eax
  int v14; // edi
  int v15; // eax
  UnusedContent::CUtlSymbol *v16; // ecx
  int v17; // eax
  UnusedContent::CUtlSymbol *v18; // edi
  CFmtStrN<256> *v19; // eax
  CFmtStrN<256> *v20; // eax
  int v21; // edi
  int v22; // eax
  UnusedContent::CUtlSymbol *v23; // ecx
  int v24; // eax
  UnusedContent::CUtlSymbol *v25; // eax
  int v27; // edi
  unsigned int m_Id; // eax
  UnusedContent::CUtlSymbol *v29; // ebx
  const char *v30; // eax
  CFmtStrN<256> v31; // [esp+Ch] [ebp-11Ch] BYREF
  UnusedContent::CUtlSymbol sym; // [esp+118h] [ebp-10h] BYREF
  char *pStart; // [esp+11Ch] [ebp-Ch]
  void *resfilehandle; // [esp+120h] [ebp-8h]
  int c; // [esp+124h] [ebp-4h] BYREF

  v3 = g_pFileSystem->Open(this: g_pFileSystem, a2: resfile, a3: "rb", a4: 0);
  resfilehandle = v3;
  if ( v3 == nullptr )
  {
    _Error(a1: "Unable to open reslist file %s\n", resfile);
    exit(code: -1);
  }
  v4 = g_pFileSystem->Size_2(this: g_pFileSystem, a2: v3);
  if ( v4 > 0 )
  {
    v5 = (char *)operator new(nSize: v4 + 1);
    pStart = v5;
    if ( v5 != nullptr && v4 == g_pFileSystem->Read(this: g_pFileSystem, a2: v5, a3: v4, a4: resfilehandle) )
    {
      v5[v4] = 0;
      for ( i = COM_Parse(data: v5); strlen(com_token) != 0; i = COM_Parse(data: i) )
      {
        V_snprintf(pDest: &v31.m_szBuf[7], maxLen: 256, pFormat: "%s%s.lst", g_szReslistDir, com_token);
        strlwr(string: &v31.m_szBuf[7]);
        V_FixSlashes(pname: &v31.m_szBuf[7], separator: 92);
        if ( g_pFileSystem->FileExists(this: g_pFileSystem, a2: &v31.m_szBuf[7], a3: nullptr) )
        {
          UnusedContent::CUtlSymbolTable::AddString(this: &g_Analysis.symbols, result: &sym, pString: &v31.m_szBuf[7]);
          m_Size = resfiles->m_Size;
          m_nAllocationCount = resfiles->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<UnusedContent::CUtlSymbol,int>::Grow(
              this: (CUtlMemory<KeyValues *,int> *)resfiles,
              num: m_Size - m_nAllocationCount + 1);
          ++resfiles->m_Size;
          m_pMemory = resfiles->m_Memory.m_pMemory;
          v10 = resfiles->m_Size - m_Size - 1;
          resfiles->m_pElements = resfiles->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
          v11 = &resfiles->m_Memory.m_pMemory[m_Size];
          if ( v11 != nullptr )
            v11->m_Id = sym.m_Id;
        }
        else
        {
          vprint(depth: 0, fmt: "Couldn't find %s\n", &v31.m_szBuf[7]);
        }
      }
      v5 = pStart;
    }
    free(pMem: v5);
    v3 = resfilehandle;
  }
  g_pFileSystem->Close(this: g_pFileSystem, a2: v3);
  v12 = CFmtStrN<256>::CFmtStrN<256>(this: &v31, pszFormat: "%sall.lst", g_szReslistDir);
  if ( g_pFileSystem->FileExists(this: g_pFileSystem, a2: v12->m_szBuf, a3: nullptr) )
  {
    v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v31, pszFormat: "%sall.lst", g_szReslistDir);
    UnusedContent::CUtlSymbolTable::AddString(
      this: &g_Analysis.symbols,
      result: (UnusedContent::CUtlSymbol *)&c,
      pString: v13->m_szBuf);
    v14 = resfiles->m_Size;
    v15 = resfiles->m_Memory.m_nAllocationCount;
    if ( v14 + 1 > v15 )
      CUtlMemory<UnusedContent::CUtlSymbol,int>::Grow(this: (CUtlMemory<KeyValues *,int> *)resfiles, num: v14 - v15 + 1);
    ++resfiles->m_Size;
    v16 = resfiles->m_Memory.m_pMemory;
    v17 = resfiles->m_Size - v14 - 1;
    resfiles->m_pElements = resfiles->m_Memory.m_pMemory;
    if ( v17 > 0 )
      _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
    v18 = &resfiles->m_Memory.m_pMemory[v14];
    if ( v18 != nullptr )
      v18->m_Id = c;
  }
  v19 = CFmtStrN<256>::CFmtStrN<256>(this: &v31, pszFormat: "%sengine.lst", g_szReslistDir);
  if ( g_pFileSystem->FileExists(this: g_pFileSystem, a2: v19->m_szBuf, a3: nullptr) )
  {
    v20 = CFmtStrN<256>::CFmtStrN<256>(this: &v31, pszFormat: "%sengine.lst", g_szReslistDir);
    UnusedContent::CUtlSymbolTable::AddString(
      this: &g_Analysis.symbols,
      result: (UnusedContent::CUtlSymbol *)&c,
      pString: v20->m_szBuf);
    v21 = resfiles->m_Size;
    v22 = resfiles->m_Memory.m_nAllocationCount;
    if ( v21 + 1 > v22 )
      CUtlMemory<UnusedContent::CUtlSymbol,int>::Grow(this: (CUtlMemory<KeyValues *,int> *)resfiles, num: v21 - v22 + 1);
    ++resfiles->m_Size;
    v23 = resfiles->m_Memory.m_pMemory;
    v24 = resfiles->m_Size - v21 - 1;
    resfiles->m_pElements = resfiles->m_Memory.m_pMemory;
    if ( v24 > 0 )
      _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: 4 * v24);
    v25 = &resfiles->m_Memory.m_pMemory[v21];
    if ( v25 != nullptr )
      v25->m_Id = c;
  }
  if ( resfiles->m_Size > 0 )
  {
    vprint(depth: 0, fmt: "Parsed %i reslist files\n", resfiles->m_Size);
    v27 = 0;
    c = resfiles->m_Size;
    if ( c > 0 )
    {
      do
      {
        m_Id = resfiles->m_Memory.m_pMemory[v27].m_Id;
        v29 = &resfiles->m_Memory.m_pMemory[v27];
        if ( m_Id == -1 )
          v30 = dir;
        else
          v30 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[m_Id].m_Data.m_iOffset];
        V_strncpy(pDest: &v31.m_szBuf[7], pSrc: v30, maxLen: 256);
        ParseFilesFromResList(a1: (int)resfiles, resfilesymbol: v29, files, resfile: &v31.m_szBuf[7]);
        ++v27;
      }
      while ( v27 < c );
    }
    return 1;
  }
  else
  {
    vprint(
      depth: 0,
      fmt: "%s didn't have any actual .lst files in the reslists folder, have you run the engine with %s\n",
      resfile,
      "-makereslists -usereslistfile maplist.txt");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C000
// Name: void Correlate(class CUtlRBTree<struct ReferencedFile,int,bool (*)(struct ReferencedFile const __near &,struct ReferencedFile const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct ReferencedFile,int>,int>> __near &,class CUtlVector<struct FileEntry,class CUtlMemory<struct FileEntry,int>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Correlate(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        float referencedfiles,
        float contentfiles,
        const char *modname)
{
  CUtlVector<FileEntry,CUtlMemory<FileEntry,int> > *v6; // ebx
  int v7; // edx
  long double v8; // st7
  int v9; // edi
  int v10; // esi
  unsigned int *v11; // eax
  unsigned int v12; // ecx
  long double v13; // st7
  double v14; // st6
  unsigned int *v15; // eax
  int v16; // edx
  double v17; // st6
  const char *v18; // eax
  signed int v19; // eax
  ReferencedFile *v20; // ebx
  int v21; // eax
  UtlRBTreeNode_t<ReferencedFile,int> *m_pMemory; // ecx
  unsigned int v23; // edx
  int v24; // esi
  int v25; // edx
  int v26; // esi
  CFmtStrN<256> *v27; // eax
  const UnusedContent::CUtlSymbol *v28; // esi
  bool v29; // bl
  const char *v30; // edi
  bool v31; // al
  double m_Id; // st7
  CFmtStrN<256> *v33; // eax
  void *total_high; // eax
  const char *v35; // eax
  const char *v36; // eax
  const FileEntry *v37; // edi
  int v38; // eax
  UtlRBTreeNode_t<FileEntry,int> *v39; // ecx
  int v40; // edx
  unsigned int v41; // esi
  FileEntry *p_m_Data; // esi
  int v43; // esi
  int i; // edi
  FileEntry *v45; // ecx
  char *v46; // eax
  const char *v47; // eax
  ReferencedFile *v48; // edi
  const char *v49; // eax
  const char *v50; // eax
  int m_Size; // ebx
  int j; // esi
  unsigned int v53; // eax
  const char *v54; // eax
  float *v55; // ebx
  char *v56; // esi
  int v57; // eax
  int v58; // eax
  char *v59; // eax
  int v60; // eax
  int v61; // ecx
  int v62; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v63; // eax
  unsigned int v64; // esi
  DirEntry *p_elem; // eax
  int v66; // ebx
  int v67; // edi
  FileEntry *v68; // esi
  unsigned int v69; // esi
  const char *v70; // eax
  const char *v71; // eax
  const char *v72; // eax
  unsigned int v73; // esi
  const char *v74; // eax
  unsigned int v75; // esi
  const char *v76; // eax
  const char *v77; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *Inorder; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v79; // ebx
  double total; // xmm0_8
  double unreferenced; // xmm1_8
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v82; // esi
  float v83; // xmm1_4
  float v84; // xmm2_4
  const char *v85; // eax
  const char *v86; // eax
  const char *v87; // eax
  const char *v88; // eax
  const char *v89; // eax
  const char *v90; // eax
  const char *v91; // eax
  const char *v92; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v93; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *v94; // edi
  float v95; // [esp+38h] [ebp-260h]
  float v96; // [esp+38h] [ebp-260h]
  float v97; // [esp+38h] [ebp-260h]
  float v98; // [esp+38h] [ebp-260h]
  float whitelist; // [esp+38h] [ebp-260h]
  float v100; // [esp+38h] [ebp-260h]
  float v101; // [esp+38h] [ebp-260h]
  float v102; // [esp+38h] [ebp-260h]
  float v103; // [esp+38h] [ebp-260h]
  const char *v107; // [esp+44h] [ebp-254h]
  CFmtStrN<256> v108; // [esp+48h] [ebp-250h] BYREF
  char totalstring[20]; // [esp+154h] [ebp-144h] BYREF
  char refstring[20]; // [esp+168h] [ebp-130h] BYREF
  char whiteliststring[20]; // [esp+17Ch] [ebp-11Ch] BYREF
  char unrefstring[20]; // [esp+190h] [ebp-108h] BYREF
  char ext[32]; // [esp+1A4h] [ebp-F4h] BYREF
  CUtlMap<char const *,DirEntry,int>::Node_t insert; // [esp+1C4h] [ebp-D4h] BYREF
  CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > tree; // [esp+1E4h] [ebp-B4h] BYREF
  CUtlRBTree<FileEntry,int,bool (__cdecl*)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int> > unreftree; // [esp+208h] [ebp-90h] BYREF
  CUtlDict<DirEntry,int> directories; // [esp+22Ch] [ebp-6Ch] BYREF
  long double grand_total_unref; // [esp+250h] [ebp-48h]
  DirEntry foo; // [esp+258h] [ebp-40h] BYREF
  double totalReferencedDiskSize; // [esp+270h] [ebp-28h]
  double v121; // [esp+278h] [ebp-20h] OVERLAPPED BYREF
  long double grand_total; // [esp+280h] [ebp-18h]
  int parent; // [esp+288h] [ebp-10h] BYREF
  unsigned int whitelisted; // [esp+28Ch] [ebp-Ch]
  bool leftchild; // [esp+293h] [ebp-5h] BYREF
  unsigned int refcounted; // [esp+294h] [ebp-4h] BYREF

  v6 = (CUtlVector<FileEntry,CUtlMemory<FileEntry,int> > *)LODWORD(contentfiles);
  v7 = *(_DWORD *)(LODWORD(contentfiles) + 12);
  grand_total = 0.0;
  v8 = 0.0;
  v9 = 0;
  v10 = 0;
  totalReferencedDiskSize = 0.0;
  if ( v7 >= 4 )
  {
    v11 = (unsigned int *)(*(_DWORD *)LODWORD(contentfiles) + 16);
    v12 = ((unsigned int)(v7 - 4) >> 2) + 1;
    v10 = 4 * v12;
    do
    {
      v13 = v8 + (double)*(v11 - 3) + (double)*v11 + (double)v11[3];
      v14 = (double)v11[6];
      v11 += 12;
      v8 = v13 + v14;
      --v12;
    }
    while ( v12 != 0 );
    grand_total = v8;
    v9 = 0;
  }
  if ( v10 < v7 )
  {
    v15 = (unsigned int *)(*(_DWORD *)LODWORD(contentfiles) + 12 * v10 + 4);
    v16 = v7 - v10;
    do
    {
      v17 = (double)*v15;
      v15 += 3;
      v8 = v8 + v17;
      --v16;
    }
    while ( v16 != 0 );
    grand_total = v8;
  }
  v18 = V_pretifymem(value: grand_total, digitsafterdecimal: 3, usebinaryonek: false);
  vprint(depth: 0, fmt: "Content tree size on disk %s\n", v18);
  tree.m_Root = -1;
  tree.m_FirstFree = -1;
  tree.m_LastAlloc.index = -1;
  v19 = *(_DWORD *)(LODWORD(referencedfiles) + 20);
  tree.m_LessFunc = RefFileLessFunc;
  memset(&tree.m_Elements, 0, sizeof(tree.m_Elements));
  tree.m_NumElements = 0;
  tree.m_pElements = nullptr;
  if ( v19 > 0 )
  {
    for ( whitelisted = v19; whitelisted != 0; --whitelisted )
    {
      v20 = (ReferencedFile *)(v9 + *(_DWORD *)(LODWORD(referencedfiles) + 4) + 16);
      refcounted = -1;
      leftchild = false;
      CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::FindInsertionPosition(
        this: &tree,
        insert: v20,
        parent: (int *)&refcounted,
        &leftchild);
      v21 = CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::NewNode(this: &tree);
      m_pMemory = tree.m_Elements.m_pMemory;
      v23 = refcounted;
      v24 = v21;
      tree.m_Elements.m_pMemory[v24].m_Parent = refcounted;
      m_pMemory[v24].m_Right = -1;
      m_pMemory[v24].m_Left = -1;
      m_pMemory[v24].m_Tag = 0;
      if ( v23 == -1 )
      {
        tree.m_Root = v21;
      }
      else
      {
        v25 = v23;
        if ( leftchild )
          m_pMemory[v25].m_Left = v21;
        else
          m_pMemory[v25].m_Right = v21;
      }
      CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::InsertRebalance(
        this: &tree,
        elem: v21);
      ++tree.m_NumElements;
      if ( &tree.m_Elements.m_pMemory[v24] != (UtlRBTreeNode_t<ReferencedFile,int> *)-16 )
        ReferencedFile::ReferencedFile(this: &tree.m_Elements.m_pMemory[v24].m_Data, src: v20);
      v9 += 40;
    }
    v6 = (CUtlVector<FileEntry,CUtlMemory<FileEntry,int> > *)LODWORD(contentfiles);
  }
  HIDWORD(v121) = v6->m_Size;
  v26 = HIDWORD(v121);
  refcounted = 0;
  whitelisted = 0;
  v27 = CFmtStrN<256>::CFmtStrN<256>(this: &v108, pszFormat: "%swhitelist.lst", g_szReslistDir);
  ((void (__thiscall *)(IFileSystem *, char *, const char *, int, int, int))filesystem->RemoveFile)(
    a1: filesystem,
    a2: v27->m_szBuf,
    a3: "GAME",
    a4: a2,
    a5: a3,
    a6: a1);
  if ( v26 > 0 )
  {
    referencedfiles = 0.0;
    for ( parent = v26; parent != 0; --parent )
    {
      v28 = (const UnusedContent::CUtlSymbol *)(LODWORD(referencedfiles) + *(_DWORD *)LODWORD(contentfiles));
      memset(&foo.unreferenced, 0, 16);
      *(_QWORD *)&foo.total = 0xFFFFFFFFLL;
      LODWORD(foo.total) = (UnusedContent::CUtlSymbol)v28->m_Id;
      v29 = CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::Find(
              this: &tree,
              search: (const ReferencedFile *)&foo) != -1;
      if ( v28->m_Id == -1 )
        v30 = dir;
      else
        v30 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v28->m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v28->m_Id].m_Data.m_iOffset];
      v31 = CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Find(
              this: &g_WhiteList,
              search: v28) != -1;
      if ( v29 || v31 )
      {
        m_Id = (double)v28[1].m_Id;
        v28[2].m_Id = v29 + 1;
        totalReferencedDiskSize = m_Id + totalReferencedDiskSize;
        if ( !v29 )
        {
          v33 = CFmtStrN<256>::CFmtStrN<256>(this: &v108, pszFormat: "%swhitelist.lst", g_szReslistDir);
          logprint(logfile: v33->m_szBuf, fmt: "\"%s\\%s\"\n", modname, v30);
          ++whitelisted;
        }
        ++refcounted;
      }
      total_high = (void *)HIDWORD(foo.total);
      LODWORD(foo.whitelist) = 0;
      if ( foo.unreferenced >= 0.0 )
      {
        if ( HIDWORD(foo.total) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)HIDWORD(foo.total));
          total_high = nullptr;
          HIDWORD(foo.total) = 0;
        }
        LODWORD(foo.unreferenced) = 0;
      }
      HIDWORD(foo.whitelist) = total_high;
      if ( foo.unreferenced >= 0.0 && total_high != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: total_high);
      LODWORD(referencedfiles) += 12;
    }
    v26 = HIDWORD(v121);
  }
  v35 = V_pretifymem(value: totalReferencedDiskSize, digitsafterdecimal: 2, usebinaryonek: false);
  vprint(depth: 0, fmt: "Found %i referenced (%i whitelist) files in tree, %s\n", refcounted, whitelisted, v35);
  v36 = V_pretifymem(value: grand_total - totalReferencedDiskSize, digitsafterdecimal: 2, usebinaryonek: false);
  vprint(depth: 0, fmt: "%s appear unused\n", v36);
  vprint(depth: 0, fmt: "Sorting unreferenced files list...\n");
  unreftree.m_LessFunc = (bool (__cdecl *)(const FileEntry *, const FileEntry *))RefFileLessFunc;
  memset(&unreftree.m_Elements, 0, sizeof(unreftree.m_Elements));
  unreftree.m_Root = -1;
  unreftree.m_NumElements = 0;
  unreftree.m_FirstFree = -1;
  unreftree.m_LastAlloc.index = -1;
  unreftree.m_pElements = nullptr;
  if ( v26 > 0 )
  {
    refcounted = 0;
    for ( whitelisted = v26; whitelisted != 0; --whitelisted )
    {
      v37 = (const FileEntry *)(refcounted + *(_DWORD *)LODWORD(contentfiles));
      if ( v37->referenced == 0 )
      {
        parent = -1;
        HIBYTE(referencedfiles) = 0;
        CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::FindInsertionPosition(
          this: &unreftree,
          insert: v37,
          &parent,
          leftchild: (bool *)&referencedfiles + 3);
        v38 = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::NewNode(this: &unreftree);
        v39 = unreftree.m_Elements.m_pMemory;
        v40 = parent;
        v41 = v38;
        unreftree.m_Elements.m_pMemory[v41].m_Parent = parent;
        v39[v41].m_Right = -1;
        v39[v41].m_Left = -1;
        v39[v41].m_Tag = 0;
        if ( v40 == -1 )
        {
          unreftree.m_Root = v38;
        }
        else if ( HIBYTE(referencedfiles) != 0 )
        {
          v39[v40].m_Left = v38;
        }
        else
        {
          v39[v40].m_Right = v38;
        }
        CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::InsertRebalance(
          this: &unreftree,
          elem: v38);
        ++unreftree.m_NumElements;
        p_m_Data = &unreftree.m_Elements.m_pMemory[v41].m_Data;
        if ( p_m_Data != nullptr )
        {
          p_m_Data->sym.m_Id = v37->sym.m_Id;
          p_m_Data->size = v37->size;
          p_m_Data->referenced = v37->referenced;
        }
      }
      refcounted += 12;
    }
  }
  v43 = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::FirstInorder(this: &unreftree);
  for ( i = 0;
        v43 != -1;
        v43 = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::NextInorder(
                this: &unreftree,
                i: v43) )
  {
    v45 = &unreftree.m_Elements.m_pMemory[v43].m_Data;
    if ( showreferencedfiles )
    {
      ++i;
      if ( v45->sym.m_Id == -1 )
        v46 = (char *)dir;
      else
        v46 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v45->sym.m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v45->sym.m_Id].m_Data.m_iOffset];
      v107 = v46;
      referencedfiles = *(float *)&unreftree.m_Elements.m_pMemory[v43].m_Data.size;
      v95 = (float)LODWORD(referencedfiles);
      v47 = V_pretifymem(value: v95, digitsafterdecimal: 2, usebinaryonek: false);
      vprint(depth: 1, fmt: "%6i %12s: %s\n", i, v47, v107);
    }
  }
  if ( showmapfileusage )
  {
    vprint(depth: 0, fmt: "Writing referenced.csv...\n");
    for ( referencedfiles = COERCE_FLOAT(CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::FirstInorder(this: &tree));
          referencedfiles != NAN;
          referencedfiles = COERCE_FLOAT(
                              CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::NextInorder(
                                this: &tree,
                                i: SLODWORD(referencedfiles))) )
    {
      v48 = &tree.m_Elements.m_pMemory[LODWORD(referencedfiles)].m_Data;
      if ( v48->sym.m_Id == -1 )
        v49 = dir;
      else
        v49 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v48->sym.m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v48->sym.m_Id].m_Data.m_iOffset];
      V_ExtractFileExtension(path: v49, dest: ext, destSize: 32);
      if ( v48->sym.m_Id == -1 )
        v50 = dir;
      else
        v50 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v48->sym.m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v48->sym.m_Id].m_Data.m_iOffset];
      logprint(logfile: "referenced.csv", fmt: "\"%s\",\"%s\",%d", v50, ext, v48->maplist.m_Size);
      m_Size = v48->maplist.m_Size;
      for ( j = 0; j < m_Size; ++j )
      {
        v53 = v48->maplist.m_Memory.m_pMemory[j].m_Id;
        if ( v53 == -1 )
          v54 = dir;
        else
          v54 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v53].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v53].m_Data.m_iOffset];
        V_FileBase(in: v54, out: &v108.m_szBuf[135], maxlen: 128);
        logprint(logfile: "referenced.csv", fmt: ",\"%s\"", &v108.m_szBuf[135]);
      }
      logprint(logfile: "referenced.csv", fmt: "\n");
    }
  }
  vprint(depth: 0, fmt: "\nBuilding directory summary list...\n");
  directories.m_Elements.m_Tree.m_Root = -1;
  directories.m_Elements.m_Tree.m_FirstFree = -1;
  directories.m_Elements.m_Tree.m_LastAlloc.index = -1;
  memset(&directories.m_Elements.m_Tree.m_Elements, 0, sizeof(directories.m_Elements.m_Tree.m_Elements));
  directories.m_Elements.m_Tree.m_NumElements = 0;
  directories.m_Elements.m_Tree.m_pElements = nullptr;
  directories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  if ( SHIDWORD(v121) > 0 )
  {
    refcounted = 0;
    for ( parent = HIDWORD(v121); parent != 0; --parent )
    {
      v55 = (float *)(refcounted + *(_DWORD *)LODWORD(contentfiles));
      if ( *(_DWORD *)v55 == -1 )
        v56 = (char *)dir;
      else
        v56 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[*(_DWORD *)v55].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[*(_DWORD *)v55].m_Data.m_iOffset];
      strstr(str1: (unsigned __int8 *)v56, str2: "\\");
      if ( v57 != 0 )
        V_strncpy(pDest: &v108.m_szBuf[7], pSrc: v56, maxLen: v57 - (_DWORD)v56 + 1);
      else
        v108.m_szBuf[7] = 0;
      memset(&ext[8], 0, 24);
      *(_DWORD *)ext = &v108.m_szBuf[7];
      v58 = CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Find(
              this: &directories.m_Elements.m_Tree,
              search: (const CUtlMap<char const *,DirEntry,int>::Node_t *)ext);
      if ( v58 == -1 )
      {
        memset(&foo, 0, sizeof(foo));
        v59 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(&v108.m_szBuf[7]) + 1);
        if ( v59 != nullptr )
          strcpy(v59, &v108.m_szBuf[7]);
        else
          v59 = nullptr;
        insert.key = v59;
        insert.elem = foo;
        HIDWORD(v121) = -1;
        HIBYTE(referencedfiles) = 0;
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::FindInsertionPosition(
          this: &directories.m_Elements.m_Tree,
          &insert,
          parent: (int *)&v121 + 1,
          leftchild: (bool *)&referencedfiles + 3);
        v60 = CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::NewNode(this: &directories.m_Elements.m_Tree);
        v61 = HIDWORD(v121);
        v62 = v60;
        v63 = directories.m_Elements.m_Tree.m_Elements.m_pMemory;
        v64 = v62;
        directories.m_Elements.m_Tree.m_Elements.m_pMemory[v64].m_Parent = HIDWORD(v121);
        v63[v64].m_Right = -1;
        v63[v64].m_Left = -1;
        v63[v64].m_Tag = 0;
        if ( v61 == -1 )
        {
          directories.m_Elements.m_Tree.m_Root = v62;
        }
        else if ( HIBYTE(referencedfiles) != 0 )
        {
          v63[v61].m_Left = v62;
        }
        else
        {
          v63[v61].m_Right = v62;
        }
        CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::InsertRebalance(
          this: &directories.m_Elements.m_Tree,
          elem: v62);
        ++directories.m_Elements.m_Tree.m_NumElements;
        if ( &directories.m_Elements.m_Tree.m_Elements.m_pMemory[v62] != (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-16 )
          directories.m_Elements.m_Tree.m_Elements.m_pMemory[v62].m_Data = insert;
        v58 = v62;
      }
      p_elem = &directories.m_Elements.m_Tree.m_Elements.m_pMemory[v58].m_Data.elem;
      p_elem->total = (double)*((unsigned int *)v55 + 1) + p_elem->total;
      if ( *((_DWORD *)v55 + 2) == 0 )
        p_elem->unreferenced = (double)*((unsigned int *)v55 + 1) + p_elem->unreferenced;
      if ( *((_DWORD *)v55 + 2) == 1 )
      {
        referencedfiles = v55[1];
        p_elem->whitelist = (double)LODWORD(referencedfiles) + p_elem->whitelist;
      }
      refcounted += 12;
    }
  }
  if ( spewdeletions )
  {
    if ( immediatedelete )
      vprint(depth: 0, fmt: "\n\nDeleting files...\n");
    else
      vprint(depth: 0, fmt: "\n\nGenerating deletions.bat\n");
    v66 = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::FirstInorder(this: &unreftree);
    v67 = 0;
    contentfiles = 0.0;
    while ( v66 != -1 )
    {
      v68 = &unreftree.m_Elements.m_pMemory[v66].m_Data;
      v66 = CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::NextInorder(
              this: &unreftree,
              i: v66);
      if ( CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::Find(
             this: &g_WhiteList,
             search: &v68->sym) == -1 )
      {
        ++v67;
        contentfiles = (double)v68->size + contentfiles;
        if ( immediatedelete )
        {
          if ( v68->sym.m_Id == -1 )
            v70 = dir;
          else
            v70 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v68->sym.m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v68->sym.m_Id].m_Data.m_iOffset];
          if ( _chmod(path: v70, mode: 128) == -1 )
          {
            if ( v68->sym.m_Id == -1 )
              v71 = dir;
            else
              v71 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v68->sym.m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v68->sym.m_Id].m_Data.m_iOffset];
            vprint(depth: 0, fmt: "Could not find file %s\n", v71);
          }
          if ( v68->sym.m_Id == -1 )
            v72 = dir;
          else
            v72 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v68->sym.m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v68->sym.m_Id].m_Data.m_iOffset];
          if ( _unlink(path: v72) == -1 )
          {
            v73 = v68->sym.m_Id;
            if ( v73 == -1 )
              v74 = dir;
            else
              v74 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v73].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v73].m_Data.m_iOffset];
            vprint(depth: 0, fmt: "Could not delete file %s\n", v74);
          }
          if ( v67 % 1000 == 0 )
            vprint(depth: 0, fmt: "...deleted %i files\n", v67);
        }
        else
        {
          v75 = v68->sym.m_Id;
          if ( v75 == -1 )
            v76 = dir;
          else
            v76 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v75].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v75].m_Data.m_iOffset];
          logprint(logfile: "deletions.bat", fmt: "del \"%s\" /f\n", v76);
        }
      }
      else if ( verbose != 0 )
      {
        v69 = v68->sym.m_Id;
        if ( v69 == -1 )
          vprint(depth: 0, fmt: "whitelist blocked deletion of %s\n", dir);
        else
          vprint(
            depth: 0,
            fmt: "whitelist blocked deletion of %s\n",
            &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v69].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v69].m_Data.m_iOffset]);
      }
    }
    v77 = V_pretifymem(value: contentfiles, digitsafterdecimal: 2, usebinaryonek: false);
    vprint(depth: 0, fmt: "\nFile deletion (%d files, %s)\n\n", v67, v77);
  }
  grand_total = 0.0;
  grand_total_unref = 0.0;
  totalReferencedDiskSize = 0.0;
  vprint(depth: 0, fmt: "---------------------------------------- Summary ----------------------------------------\n");
  vprint(
    depth: 0,
    fmt: "% 15s               % 15s               % 15s               % 15s %12s\n",
    "Referenced",
    "WhiteListed",
    "Unreferenced",
    "Total",
    "Directory");
  Inorder = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::FirstInorder(this: &directories.m_Elements.m_Tree);
  if ( Inorder != (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1 )
  {
    v79 = directories.m_Elements.m_Tree.m_Elements.m_pMemory;
    do
    {
      total = v79[(_DWORD)Inorder].m_Data.elem.total;
      unreferenced = v79[(_DWORD)Inorder].m_Data.elem.unreferenced;
      v82 = &v79[(_DWORD)Inorder];
      v121 = total - unreferenced;
      contentfiles = 0.0;
      referencedfiles = 0.0;
      if ( total > 0.0 )
      {
        v83 = unreferenced;
        v84 = total;
        contentfiles = (float)(v83 * 100.0) / v84;
        referencedfiles = (float)((float)v82->m_Data.elem.whitelist * 100.0) / v84;
      }
      v96 = total;
      v85 = V_pretifymem(value: v96, digitsafterdecimal: 2, usebinaryonek: false);
      V_strncpy(pDest: totalstring, pSrc: v85, maxLen: 20);
      v97 = v82->m_Data.elem.unreferenced;
      v86 = V_pretifymem(value: v97, digitsafterdecimal: 2, usebinaryonek: false);
      V_strncpy(pDest: unrefstring, pSrc: v86, maxLen: 20);
      v98 = v121;
      v87 = V_pretifymem(value: v98, digitsafterdecimal: 2, usebinaryonek: false);
      V_strncpy(pDest: refstring, pSrc: v87, maxLen: 20);
      whitelist = v82->m_Data.elem.whitelist;
      v88 = V_pretifymem(value: whitelist, digitsafterdecimal: 2, usebinaryonek: false);
      V_strncpy(pDest: whiteliststring, pSrc: v88, maxLen: 20);
      vprint(
        depth: 0,
        fmt: "%15s (%8.3f%%)   %15s (%8.3f%%)   %15s (%8.3f%%)   %15s => dir: %s\n",
        refstring,
        (float)(100.0 - contentfiles),
        whiteliststring,
        referencedfiles,
        unrefstring,
        contentfiles,
        totalstring,
        v82->m_Data.key);
      grand_total = v82->m_Data.elem.total + grand_total;
      grand_total_unref = v82->m_Data.elem.unreferenced + grand_total_unref;
      totalReferencedDiskSize = v82->m_Data.elem.whitelist + totalReferencedDiskSize;
      Inorder = CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::NextInorder(
                  this: &directories.m_Elements.m_Tree,
                  i: (int)Inorder);
    }
    while ( Inorder != (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1 );
  }
  v100 = grand_total;
  v89 = V_pretifymem(value: v100, digitsafterdecimal: 2, usebinaryonek: false);
  V_strncpy(pDest: totalstring, pSrc: v89, maxLen: 20);
  v101 = grand_total_unref;
  v90 = V_pretifymem(value: v101, digitsafterdecimal: 2, usebinaryonek: false);
  V_strncpy(pDest: unrefstring, pSrc: v90, maxLen: 20);
  v102 = grand_total - grand_total_unref;
  v91 = V_pretifymem(value: v102, digitsafterdecimal: 2, usebinaryonek: false);
  V_strncpy(pDest: refstring, pSrc: v91, maxLen: 20);
  v103 = totalReferencedDiskSize;
  v92 = V_pretifymem(value: v103, digitsafterdecimal: 2, usebinaryonek: false);
  V_strncpy(pDest: whiteliststring, pSrc: v92, maxLen: 20);
  v121 = 1.0 / grand_total;
  grand_total = grand_total_unref * 100.0 * (1.0 / grand_total);
  vprint(depth: 0, fmt: "-----------------------------------------------------------------------------------------\n");
  vprint(
    depth: 0,
    fmt: "%15s (%8.3f%%)   %15s (%8.3f%%)   %15s (%8.3f%%)   %15s\n",
    refstring,
    (double)(100.0 - grand_total),
    whiteliststring,
    totalReferencedDiskSize * 100.0 * v121,
    unrefstring,
    (double)grand_total,
    totalstring);
  v93 = (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::FirstInorder(this: &directories.m_Elements.m_Tree);
  if ( v93 != (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1 )
  {
    v94 = directories.m_Elements.m_Tree.m_Elements.m_pMemory;
    do
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v94[(_DWORD)v93].m_Data.key);
      v93 = CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::NextInorder(
              this: &directories.m_Elements.m_Tree,
              i: (int)v93);
    }
    while ( v93 != (UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int> *)-1 );
  }
  CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RemoveAll(this: &directories.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::RemoveAll(this: &directories.m_Elements.m_Tree);
  if ( directories.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && directories.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: directories.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
  CUtlRBTree<FileEntry,int,bool (__cdecl *)(FileEntry const &,FileEntry const &),CUtlMemory<UtlRBTreeNode_t<FileEntry,int>,int>>::RemoveAll(this: &unreftree);
  if ( unreftree.m_Elements.m_nGrowSize >= 0 && unreftree.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: unreftree.m_Elements.m_pMemory);
  CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RemoveAll(this: &tree);
  if ( tree.m_Elements.m_nGrowSize >= 0 && tree.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tree.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040D0A0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  void (__thiscall ***v3)(_DWORD, int, const char **); // eax
  int i; // esi
  const char *v5; // eax
  const char *v6; // edx
  char *v7; // esi
  char *v8; // ecx
  char v9; // al
  void *(__cdecl *FileSystemFactory)(const char *, int *); // eax
  int v12; // eax
  int v13; // eax
  CFmtStrN<256> *v14; // eax
  int v15; // edi
  unsigned int m_Id; // eax
  const char *v17; // esi
  CFmtStrN<256> *v18; // eax
  FileEntry *m_pMemory; // eax
  int v20; // edi
  unsigned int v21; // eax
  const char *v22; // esi
  CFmtStrN<256> *v23; // eax
  FileEntry *v24; // eax
  FileEntry *v25; // eax
  CFmtStrN<256> v26; // [esp+Ch] [ebp-36Ch] BYREF
  char resfile[256]; // [esp+118h] [ebp-260h] BYREF
  char workingdir[256]; // [esp+218h] [ebp-160h] BYREF
  CUtlVector<UnusedContent::CUtlSymbol,CUtlMemory<UnusedContent::CUtlSymbol,int> > resfiles; // [esp+318h] [ebp-60h] BYREF
  CUtlRBTree<ReferencedFile,int,bool (__cdecl*)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int> > referencedfiles; // [esp+32Ch] [ebp-4Ch] BYREF
  CUtlVector<FileEntry,CUtlMemory<FileEntry,int> > otherfiles; // [esp+350h] [ebp-28h] BYREF
  CUtlVector<FileEntry,CUtlMemory<FileEntry,int> > contentfiles; // [esp+364h] [ebp-14h] BYREF
  int argca; // [esp+380h] [ebp+8h]
  int argcb; // [esp+380h] [ebp+8h]

  v3 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  for ( i = 1; i < argc; ++i )
  {
    v5 = argv[i];
    if ( *v5 == 45 )
    {
      switch ( v5[1] )
      {
        case 'd':
          spewdeletions = true;
          continue;
        case 'f':
          v6 = argv[++i];
          V_strncpy(pDest: g_szReslistDir, pSrc: v6, maxLen: 260);
          _V_strlower(start: g_szReslistDir);
          V_FixSlashes(pname: g_szReslistDir, separator: 92);
          V_AppendSlash(pStr: g_szReslistDir, strSize: 260);
          continue;
        case 'g':
          ++i;
          continue;
        case 'i':
          immediatedelete = true;
          continue;
        case 'l':
          uselogfile = true;
          continue;
        case 'm':
          showmapfileusage = true;
          continue;
        case 'r':
          showreferencedfiles = true;
          continue;
        case 'v':
          verbose = 1;
          continue;
        case 'w':
          printwhitelist = true;
          continue;
        default:
          goto LABEL_63;
      }
    }
  }
  if ( argc < 3 || i != argc )
  {
    vprint(depth: 0, fmt: "Valve Software - unusedcontent.exe (%s)\n", "Dec 28 2010");
    vprint(
      depth: 0,
      fmt: "--- Compares reslists with actual game content tree to show unreferenced content and stats ---\n");
LABEL_63:
    printusage();
  }
  if ( uselogfile )
  {
    _unlink(path: "log.txt");
    vprint(depth: 0, fmt: "    Outputting to log.txt\n");
  }
  vprint(depth: 0, fmt: "Valve Software - unusedcontent.exe (%s)\n", "Dec 28 2010");
  vprint(
    depth: 0,
    fmt: "--- Compares reslists with actual game content tree to show unreferenced content and stats ---\n");
  vprint(depth: 0, fmt: "    Using reslist dir '%s'\n", g_szReslistDir);
  vprint(depth: 0, fmt: "    Looking for extraneous content...\n");
  v7 = (char *)argv[i - 1];
  v8 = (char *)(resfile - v7);
  do
  {
    v9 = *v7;
    v7[(_DWORD)v8] = *v7;
    ++v7;
  }
  while ( v9 != 0 );
  vprint(depth: 0, fmt: "    Comparing results of resfile (%s) with files under current directory...\n", resfile);
  workingdir[0] = 0;
  Q_getwd(out: workingdir, outSize: 256);
  CmdLib_InitFileSystem(pFilename: workingdir, maxMemoryUsage: 0);
  FileSystemFactory = CmdLib_GetFileSystemFactory();
  filesystem = (IFileSystem *)FileSystemFactory(a1: "VFileSystem017", a2: nullptr);
  if ( filesystem == nullptr )
    return 1;
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: gamedir, a3: "GAME", a4: PATH_ADD_TO_TAIL);
  _V_strlower(start: gamedir);
  V_FixSlashes(pname: gamedir, separator: 92);
  V_strncpy(pDest: modname, pSrc: gamedir, maxLen: 260);
  UNSPECIFIED_LOGGING_COLOR_5._color[strlen(modname) + 3] = 0;
  strrchr(string: (unsigned __int8 *)modname, chr: 0x5Cu);
  if ( v12 != 0 )
  {
    strrchr(string: (unsigned __int8 *)modname, chr: 0x5Cu);
    V_strncpy(pDest: modname, pSrc: (const char *)(v13 + 1), maxLen: 260);
  }
  else
  {
    V_strncpy(pDest: modname, pSrc: dir, maxLen: 260);
  }
  vprint(depth: 1, fmt: "Mod Name:%s\n", modname);
  BuildCheckdirList();
  BuildWhiteList();
  vprint(depth: 0, fmt: "Building aggregate file list from resfile output\n");
  referencedfiles.m_Root = -1;
  referencedfiles.m_FirstFree = -1;
  referencedfiles.m_LastAlloc.index = -1;
  referencedfiles.m_LessFunc = RefFileLessFunc;
  memset(&referencedfiles.m_Elements, 0, sizeof(referencedfiles.m_Elements));
  referencedfiles.m_NumElements = 0;
  referencedfiles.m_pElements = nullptr;
  memset(&resfiles, 0, sizeof(resfiles));
  BuildReferencedFileList(&resfiles, files: &referencedfiles, resfile);
  vprint(depth: 0, fmt: "found %i files\n\n", referencedfiles.m_NumElements);
  vprint(depth: 0, fmt: "Building list of all game content files\n");
  memset(&contentfiles, 0, sizeof(contentfiles));
  memset(&otherfiles, 0, sizeof(otherfiles));
  BuildFileList_R(depth: 0, files: &contentfiles, &otherfiles, dir: dir, wild: "...", skipchars: 0);
  vprint(depth: 0, fmt: "found %i files in content tree\n\n", contentfiles.m_Size);
  Correlate(
    a1: 0,
    a2: (int)argv,
    a3: (int)&modname[1],
    referencedfiles: COERCE_FLOAT(&referencedfiles),
    contentfiles: COERCE_FLOAT(&contentfiles),
    modname: modname);
  v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v26, pszFormat: "%sunreferenced_files.lst", g_szReslistDir);
  filesystem->RemoveFile(this: filesystem, a2: v14->m_szBuf, a3: "GAME");
  if ( otherfiles.m_Size > 0 )
  {
    v15 = 0;
    for ( argca = otherfiles.m_Size; argca != 0; --argca )
    {
      m_Id = otherfiles.m_Memory.m_pMemory[v15].sym.m_Id;
      if ( m_Id == -1 )
        v17 = dir;
      else
        v17 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[m_Id].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[m_Id].m_Data.m_iOffset];
      v18 = CFmtStrN<256>::CFmtStrN<256>(this: &v26, pszFormat: "%sunreferenced_files.lst", g_szReslistDir);
      logprint(logfile: v18->m_szBuf, fmt: "\"%s\\%s\"\n", modname, v17);
      ++v15;
    }
  }
  if ( contentfiles.m_Size > 0 )
  {
    argcb = contentfiles.m_Size;
    m_pMemory = contentfiles.m_Memory.m_pMemory;
    v20 = 0;
    do
    {
      if ( m_pMemory[v20].referenced == 0 )
      {
        v21 = m_pMemory[v20].sym.m_Id;
        if ( v21 == -1 )
          v22 = dir;
        else
          v22 = &g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v21].m_Data.m_iPool]->m_Data[g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory[v21].m_Data.m_iOffset];
        v23 = CFmtStrN<256>::CFmtStrN<256>(this: &v26, pszFormat: "%sunreferenced_files.lst", g_szReslistDir);
        logprint(logfile: v23->m_szBuf, fmt: "\"%s\\%s\"\n", modname, v22);
        m_pMemory = contentfiles.m_Memory.m_pMemory;
      }
      ++v20;
      --argcb;
    }
    while ( argcb != 0 );
  }
  FileSystem_Term();
  v24 = otherfiles.m_Memory.m_pMemory;
  otherfiles.m_Size = 0;
  if ( otherfiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( otherfiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: otherfiles.m_Memory.m_pMemory);
      v24 = nullptr;
      otherfiles.m_Memory.m_pMemory = nullptr;
    }
    otherfiles.m_Memory.m_nAllocationCount = 0;
  }
  otherfiles.m_pElements = v24;
  if ( otherfiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v24 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
      otherfiles.m_Memory.m_pMemory = nullptr;
    }
    otherfiles.m_Memory.m_nAllocationCount = 0;
  }
  v25 = contentfiles.m_Memory.m_pMemory;
  contentfiles.m_Size = 0;
  if ( contentfiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( contentfiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: contentfiles.m_Memory.m_pMemory);
      v25 = nullptr;
      contentfiles.m_Memory.m_pMemory = nullptr;
    }
    contentfiles.m_Memory.m_nAllocationCount = 0;
  }
  contentfiles.m_pElements = v25;
  if ( contentfiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v25 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
      contentfiles.m_Memory.m_pMemory = nullptr;
    }
    contentfiles.m_Memory.m_nAllocationCount = 0;
  }
  if ( resfiles.m_Memory.m_nGrowSize >= 0 && resfiles.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: resfiles.m_Memory.m_pMemory);
  CUtlRBTree<ReferencedFile,int,bool (__cdecl *)(ReferencedFile const &,ReferencedFile const &),CUtlMemory<UtlRBTreeNode_t<ReferencedFile,int>,int>>::RemoveAll(this: &referencedfiles);
  if ( referencedfiles.m_Elements.m_nGrowSize >= 0 && referencedfiles.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: referencedfiles.m_Elements.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00411F70
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this)
{
  bool v2; // sf
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // eax

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
// Address: 0x00424C30
// Name: UnusedContent::_dynamic_initializer_for__g_CleanupSymbolTable__
// Source: json
//------------------------------------------------------------------------------
int UnusedContent::_dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: UnusedContent::_dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00424EC0
// Name: UnusedContent::_dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnusedContent::_dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  UnusedContent::CUtlSymbolTable *v0; // esi

  v0 = UnusedContent::CUtlSymbol::s_pSymbolTable;
  if ( UnusedContent::CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&UnusedContent::CUtlSymbol::s_pSymbolTable->m_StringPools);
    CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::~CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  UnusedContent::CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00424C40
// Name: _dynamic_initializer_for__g_Analysis__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Analysis__()
{
  g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 768);
  g_Analysis.symbols.m_Lookup.m_Root = -1;
  g_Analysis.symbols.m_Lookup.m_NumElements = 0;
  g_Analysis.symbols.m_Lookup.m_FirstFree = -1;
  g_Analysis.symbols.m_Lookup.m_LastAlloc.index = -1;
  g_Analysis.symbols.m_Lookup.m_pElements = g_Analysis.symbols.m_Lookup.m_Elements.m_pMemory;
  g_Analysis.symbols.m_StringPools.m_Memory.m_pMemory = nullptr;
  g_Analysis.symbols.m_StringPools.m_Memory.m_nAllocationCount = 0;
  g_Analysis.symbols.m_StringPools.m_Memory.m_nGrowSize = 8;
  g_Analysis.symbols.m_StringPools.m_Size = 0;
  g_Analysis.symbols.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_Analysis__);
}

//------------------------------------------------------------------------------
// Address: 0x00424CB0
// Name: _dynamic_initializer_for__g_Random__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUniformRandomStream *dynamic_initializer_for__g_Random__()
{
  return CUniformRandomStream::CUniformRandomStream(this: &g_Random);
}

//------------------------------------------------------------------------------
// Address: 0x00424CC0
// Name: _dynamic_initializer_for__g_DirList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DirList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DirList__);
}

//------------------------------------------------------------------------------
// Address: 0x00424CD0
// Name: _dynamic_initializer_for__g_IgnoreDir__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_IgnoreDir__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_IgnoreDir__);
}

//------------------------------------------------------------------------------
// Address: 0x00424CE0
// Name: _dynamic_initializer_for__g_WhiteList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WhiteList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_WhiteList__);
}

//------------------------------------------------------------------------------
// Address: 0x00424CF0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x00424D10
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424D20
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
// Address: 0x00424D80
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
// Address: 0x00424DB0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x00424DD0
// Name: _dynamic_atexit_destructor_for__g_ExitStopper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExitStopper__()
{
  if ( g_bStopOnExit )
  {
    _Warning(a1: "\nPress any key to quit.\n");
    getch();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424DF0
// Name: _dynamic_atexit_destructor_for__g_CleanupFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupFunctions__()
{
  CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::RemoveAll(this: &g_CleanupFunctions);
  if ( g_CleanupFunctions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_CleanupFunctions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_CleanupFunctions.m_Memory.m_pMemory);
      g_CleanupFunctions.m_Memory.m_pMemory = nullptr;
    }
    g_CleanupFunctions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424E40
// Name: _CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__()
{
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&buf);
}

//------------------------------------------------------------------------------
// Address: 0x00424E50
// Name: _dynamic_atexit_destructor_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_definevariable__()
{
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&g_definevariable);
}

//------------------------------------------------------------------------------
// Address: 0x00424E60
// Name: _dynamic_atexit_destructor_for__g_DirList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DirList__()
{
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&g_DirList);
}

//------------------------------------------------------------------------------
// Address: 0x00424E70
// Name: _dynamic_atexit_destructor_for__g_IgnoreDir__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_IgnoreDir__()
{
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&g_IgnoreDir);
}

//------------------------------------------------------------------------------
// Address: 0x00424E80
// Name: _dynamic_atexit_destructor_for__g_Analysis__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Analysis__()
{
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&g_Analysis.symbols.m_StringPools);
  CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>::~CUtlRBTree<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int,bool (__cdecl *)(UnusedContent::CUtlSymbolTable::CStringPoolIndex const &,UnusedContent::CUtlSymbolTable::CStringPoolIndex const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbolTable::CStringPoolIndex,unsigned int>,unsigned int>>(this: &g_Analysis.symbols.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x00424EA0
// Name: _logprint_::_2_::_dynamic_atexit_destructor_for__previousfiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl logprint_::_2_::_dynamic_atexit_destructor_for__previousfiles__()
{
  CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::~CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>(this: (CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl*)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int> > *)&`CUtlRBTree<CUtlMap<char const *,DirEntry,int>::Node_t,int,CUtlMap<char const *,DirEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,DirEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements);
}

//------------------------------------------------------------------------------
// Address: 0x00424EB0
// Name: _dynamic_atexit_destructor_for__g_WhiteList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WhiteList__()
{
  CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>::~CUtlRBTree<UnusedContent::CUtlSymbol,int,bool (__cdecl *)(UnusedContent::CUtlSymbol const &,UnusedContent::CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<UnusedContent::CUtlSymbol,int>,int>>(this: &g_WhiteList);
}

//------------------------------------------------------------------------------
// Address: 0x00424EF0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x00424F00
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: &s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}
