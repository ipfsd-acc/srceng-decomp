// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/splitstring.cpp
// Functions: 3
// ============================================================

#include "tier1\splitstring.h"

//------------------------------------------------------------------------------
// Address: 0x10276790
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    free(pMem: this->m_szBuffer);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x102767B0
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: &v19[v16 + 1], src: &v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276960
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

// ============================================================
// Overlay from classcheck (Missing functions)
// ============================================================
namespace classcheck {

//------------------------------------------------------------------------------
// Address: 0x0040B760
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    free(pMem: this->m_szBuffer);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>((CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0040B780
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(a1: pCurPos, a2: (const char *)v8, pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<char *,int>::Grow(
          (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<char *,int>::Grow(
        (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)this,
        num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B930
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

} // namespace classcheck

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10276810
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    free(pMem: this->m_szBuffer);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10276830
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: &v19[v16 + 1], src: &v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102769E0
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102B3CD0
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    operator delete(p: this->m_szBuffer);
  CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>((CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x102B3CF0
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = std::char_traits<char>::length(str: pString) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(a1: pCurPos, a2: (const char *)v8, pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3EA0
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1001CB10
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    free(pMem: this->m_szBuffer);
  CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::~CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1001CB30
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(a1: pCurPos, a2: (const char *)v8, pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<unsigned long,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CCE0
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x1004D4F0
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    free(pMem: this->m_szBuffer);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>((CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1004D510
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(a1: pCurPos, a2: (const char *)v8, pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow((CUtlMemory<CTCPPacket *,int> *)this, num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<int,int>::Grow((CUtlMemory<CTCPPacket *,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D6C0
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

} // namespace shadercompile_dll

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x100352D0
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    free(pMem: this->m_szBuffer);
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>((CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100352F0
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(a1: pCurPos, a2: (const char *)v8, pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow((CUtlMemory<CTCPPacket *,int> *)this, num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<int,int>::Grow((CUtlMemory<CTCPPacket *,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100354A0
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00466BE0
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    free(pMem: this->m_szBuffer);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00466C00
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  char *v4; // ebx
  unsigned int v6; // edi
  char *v7; // eax
  bool v8; // sf
  const char *v9; // ebp
  int v10; // edi
  const char *v11; // eax
  char *v12; // ebp
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v16; // eax
  bool v17; // zf
  char **v18; // edi
  int v19; // edi
  int v20; // eax
  char *v21; // ebp
  char **v22; // ecx
  int v23; // eax
  char **v24; // edi
  int separatorLen; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  unsigned int v27; // [esp+14h] [ebp-4h]

  v4 = pString;
  v6 = _V_strlen(str: pString) + 1;
  v7 = (char *)MemAlloc_Alloc(nSize: v6);
  this->m_szBuffer = v7;
  memcpy(dst: (unsigned __int8 *)v7, src: (unsigned __int8 *)pString, count: v6);
  v8 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v8 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  while ( 1 )
  {
    v9 = nullptr;
    v10 = 0;
    v26 = -1;
    separatorLen = 0;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v11 = V_stristr(pStr: v4, pSearch: pSeparators[v10]);
      if ( v11 != nullptr && (v9 == nullptr || v11 < v9) )
      {
        v26 = v10;
        separatorLen = (int)v11;
        v9 = v11;
      }
      ++v10;
    }
    while ( v10 < nSeparators );
    if ( v9 == nullptr )
      break;
    v27 = strlen(pSeparators[v26]);
    if ( v9 > v4 )
    {
      v12 = &v4[this->m_szBuffer - pString];
      *(_BYTE *)(this->m_szBuffer - pString + separatorLen) = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v16 = this->m_Size - m_Size - 1;
      v17 = this->m_Size - m_Size == 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v16 >= 0 && !v17 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v16);
      v18 = &this->m_Memory.m_pMemory[m_Size];
      if ( v18 != nullptr )
        *v18 = v12;
      v9 = (const char *)separatorLen;
    }
    v4 = (char *)&v9[v27];
  }
  if ( strlen(v4) != 0 )
  {
    v19 = this->m_Size;
    v20 = this->m_Memory.m_nAllocationCount;
    v21 = &v4[this->m_szBuffer - pString];
    if ( v19 + 1 > v20 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v19 - v20 + 1);
    ++this->m_Size;
    v22 = this->m_Memory.m_pMemory;
    v23 = this->m_Size - v19 - 1;
    v17 = this->m_Size - v19 == 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v23 >= 0 && !v17 )
      _V_memmove(dest: (unsigned __int8 *)&v22[v19 + 1], src: (unsigned __int8 *)&v22[v19], count: 4 * v23);
    v24 = &this->m_Memory.m_pMemory[v19];
    if ( v24 != nullptr )
      *v24 = v21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466DC0
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x100BEA80
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    free(pMem: this->m_szBuffer);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100BEAA0
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(a1: pCurPos, a2: (const char *)v8, pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<int,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BEC50
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BEC7E
// Name: __getextendedkeycode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const NormKeyVals *__cdecl _getextendedkeycode(_KEY_EVENT_RECORD *pKE)
{
  unsigned int dwControlKeyState; // ebx
  const NormKeyVals *result; // eax
  int v3; // ecx
  unsigned int v4; // esi
  int v5; // ecx
  int wVirtualScanCode; // eax

  dwControlKeyState = pKE->dwControlKeyState;
  if ( (dwControlKeyState & 0x100) != 0 )
  {
    result = nullptr;
    v3 = 0;
    v4 = 0;
    while ( EnhancedKeys[v4].ScanCode != pKE->wVirtualScanCode )
    {
      ++v4;
      ++v3;
      if ( v4 >= 12 )
        return result;
    }
    v5 = v3;
    if ( (dwControlKeyState & 3) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].AltChars;
    if ( (dwControlKeyState & 0xC) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].CtrlChars;
    if ( (dwControlKeyState & 0x10) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].ShiftChars;
    return (const NormKeyVals *)&EnhancedKeys[v5].RegChars;
  }
  else
  {
    wVirtualScanCode = pKE->wVirtualScanCode;
    if ( (dwControlKeyState & 3) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].AltChars;
    }
    else if ( (dwControlKeyState & 0xC) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].CtrlChars;
    }
    else if ( (dwControlKeyState & 0x10) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].ShiftChars;
    }
    else
    {
      result = &NormalKeys[wVirtualScanCode];
    }
    if ( result->RegChars.LeadChar != 0 && result->RegChars.LeadChar != 0xE0 || result->RegChars.SecondChar == 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BED31
// Name: __getch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _getch_nolock()
{
  int result; // eax
  int AsciiChar; // edi
  const NormKeyVals *v2; // eax
  unsigned int oldstate; // [esp+4h] [ebp-20h] BYREF
  unsigned int NumRead; // [esp+8h] [ebp-1Ch] BYREF
  _INPUT_RECORD ConInpRec; // [esp+Ch] [ebp-18h] BYREF

  if ( chbuf == -1 )
  {
    if ( _coninpfh == (HANDLE)-2 )
      __initconin();
    if ( _coninpfh == (HANDLE)-1 )
    {
      return -1;
    }
    else
    {
      GetConsoleMode(hConsoleHandle: _coninpfh, lpMode: &oldstate);
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: 0);
      while ( 1 )
      {
        if ( !ReadConsoleInputA(
                hConsoleInput: _coninpfh,
                lpBuffer: &ConInpRec,
                nLength: 1u,
                lpNumberOfEventsRead: &NumRead)
          || NumRead == 0 )
        {
          AsciiChar = -1;
          goto LABEL_15;
        }
        if ( ConInpRec.EventType == 1 && ConInpRec.Event.KeyEvent.bKeyDown != 0 )
        {
          AsciiChar = (unsigned __int8)ConInpRec.Event.KeyEvent.uChar.AsciiChar;
          if ( ConInpRec.Event.KeyEvent.uChar.AsciiChar != 0 )
            goto LABEL_15;
          v2 = _getextendedkeycode(pKE: &ConInpRec.Event.KeyEvent);
          if ( v2 != nullptr )
            break;
        }
      }
      AsciiChar = v2->RegChars.LeadChar;
      chbuf = v2->RegChars.SecondChar;
LABEL_15:
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: oldstate);
      return AsciiChar;
    }
  }
  else
  {
    result = (unsigned __int8)chbuf;
    chbuf = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BEE0A
// Name: __kbhit_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _kbhit_nolock()
{
  void *v1; // esp
  _INPUT_RECORD *v2; // eax
  _INPUT_RECORD *v3; // ebx
  unsigned int v4; // edi
  _KEY_EVENT_RECORD *p_KeyEvent; // esi
  _DWORD v6[3]; // [esp+0h] [ebp-1Ch] BYREF
  int ret; // [esp+Ch] [ebp-10h]
  unsigned int NumPeeked; // [esp+10h] [ebp-Ch] BYREF
  unsigned int NumPending; // [esp+14h] [ebp-8h] BYREF

  ret = 0;
  if ( chbuf != -1 )
    return 1;
  if ( _coninpfh == (HANDLE)-2 )
    __initconin();
  if ( _coninpfh == (HANDLE)-1
    || !GetNumberOfConsoleInputEvents(hConsoleInput: _coninpfh, lpNumberOfEvents: &NumPending)
    || NumPending == 0 )
  {
    return 0;
  }
  if ( 0xFFFFFFE0 / NumPending >= 0x14 )
  {
    if ( 20 * NumPending + 8 > 0x400 )
    {
      v2 = (_INPUT_RECORD *)MemAlloc_Alloc(nSize: 20 * NumPending + 8);
      if ( v2 != nullptr )
      {
        *(_DWORD *)&v2->EventType = 56797;
        goto LABEL_14;
      }
    }
    else
    {
      v1 = alloca(20 * NumPending + 8);
      v2 = (_INPUT_RECORD *)v6;
      if ( v6 != nullptr )
      {
        v6[0] = 52428;
LABEL_14:
        v2 = (_INPUT_RECORD *)((char *)v2 + 8);
      }
    }
    v3 = v2;
    goto LABEL_17;
  }
  v3 = nullptr;
LABEL_17:
  if ( v3 == nullptr )
    return 0;
  if ( PeekConsoleInputA(hConsoleInput: _coninpfh, lpBuffer: v3, nLength: NumPending, lpNumberOfEventsRead: &NumPeeked) )
  {
    v4 = NumPeeked;
    if ( NumPeeked != 0 && NumPeeked <= NumPending )
    {
      p_KeyEvent = &v3->Event.KeyEvent;
      do
      {
        if ( LOWORD(p_KeyEvent[-1].dwControlKeyState) == 1
          && p_KeyEvent->bKeyDown != 0
          && (p_KeyEvent->uChar.AsciiChar != 0 || _getextendedkeycode(pKE: p_KeyEvent) != nullptr) )
        {
          ret = 1;
        }
        --v4;
        p_KeyEvent = (_KEY_EVENT_RECORD *)((char *)p_KeyEvent + 20);
        NumPeeked = v4;
      }
      while ( v4 != 0 );
    }
  }
  _freea(_Memory: v3);
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x100BEF32
// Name: _getch
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl getch()
{
  int v1; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 3);
  v1 = _getch_nolock();
  _unlock(locknum: 3);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100BEF70
// Name: _kbhit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl kbhit()
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 3);
  retval = _kbhit_nolock();
  _unlock(locknum: 3);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x100BEFAE
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BF12C
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BF160
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BF1BD
// Name: ___initconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconin()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONIN$",
             dwDesiredAccess: 0xC0000000,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _coninpfh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BF1DC
// Name: ___termconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconin()
{
  HANDLE result; // eax

  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _coninpfh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BF390
// Name: _dynamic_initializer_for__g_TesselateVerts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TesselateVerts__()
{
  g_TesselateVerts[0].m_Index = (CVertIndex)-65535;
  dword_1012C2E2 = -65536;
  dword_1012C2E8 = -1;
  dword_1012C2EE = 0xFFFF;
  dword_1012C2F4 = 0x1FFFF;
  dword_1012C2FA = 0x10000;
  dword_1012C300 = 65537;
  dword_1012C306 = 1;
  dword_1012C30C = -65535;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BF450
// Name: _dynamic_initializer_for__g_VertInfo_5x5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_5x5__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_5x5;
  for ( i = 24; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BF470
// Name: _dynamic_initializer_for__g_VertInfo_9x9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_9x9__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_9x9;
  for ( i = 80; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BF490
// Name: _dynamic_initializer_for__g_VertInfo_17x17__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_17x17__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_17x17;
  for ( i = 288; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BF4B0
// Name: _dynamic_initializer_for__g_PowerInfoInitializer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_PowerInfoInitializer__()
{
  int i; // esi
  CPowerInfo *v1; // eax

  for ( i = 0; i <= 4; ++i )
  {
    v1 = g_PowerInfos[i];
    if ( v1 != nullptr )
      InitPowerInfo(pInfo: v1, iMaxPower: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF4D0
// Name: _dynamic_initializer_for__g_LeafAmbientSamples__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_LeafAmbientSamples__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_LeafAmbientSamples__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF4E0
// Name: _dynamic_initializer_for__g_MacroTextureLookup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MacroTextureLookup__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MacroTextureLookup__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF4F0
// Name: _dynamic_initializer_for__g_FaceMacroTextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FaceMacroTextures__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FaceMacroTextures__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF500
// Name: _dynamic_initializer_for__g_SpewTextCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SpewTextCS__()
{
  CCriticalSection::CCriticalSection(this: &g_SpewTextCS);
  return atexit(func: dynamic_atexit_destructor_for__g_SpewTextCS__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF520
// Name: _dynamic_initializer_for__g_SpewText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SpewText__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SpewText__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF530
// Name: _dynamic_initializer_for__g_LightResultsFilename__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_LightResultsFilename__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_LightResultsFilename__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF540
// Name: _dynamic_initializer_for__g_VRADDispatchReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDispatchReg *dynamic_initializer_for__g_VRADDispatchReg__()
{
  return CDispatchReg::CDispatchReg(this: &g_VRADDispatchReg, iPacketID: 1, fn: VRAD_DispatchFn);
}

//------------------------------------------------------------------------------
// Address: 0x100BF560
// Name: _dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_VRAD_PACKET_ID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_VRAD_PACKET_ID__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPIPacketIDReg_VMPI_VRAD_PACKET_ID,
           nPacketID: 1,
           nSubPacketID: -1,
           pName: "VMPI_VRAD_PACKET_ID");
}

//------------------------------------------------------------------------------
// Address: 0x100BF580
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_VIS_LEAFS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_VIS_LEAFS__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_SUBPACKETID_VIS_LEAFS,
           nPacketID: 1,
           nSubPacketID: 0,
           pName: "VMPI_SUBPACKETID_VIS_LEAFS");
}

//------------------------------------------------------------------------------
// Address: 0x100BF5A0
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_BUILDFACELIGHTS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_BUILDFACELIGHTS__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_SUBPACKETID_BUILDFACELIGHTS,
           nPacketID: 1,
           nSubPacketID: 1,
           pName: "VMPI_SUBPACKETID_BUILDFACELIGHTS");
}

//------------------------------------------------------------------------------
// Address: 0x100BF5C0
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_PLIGHTDATA_RESULTS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_PLIGHTDATA_RESULTS__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_SUBPACKETID_PLIGHTDATA_RESULTS,
           nPacketID: 1,
           nSubPacketID: 2,
           pName: "VMPI_SUBPACKETID_PLIGHTDATA_RESULTS");
}

//------------------------------------------------------------------------------
// Address: 0x100BF5E0
// Name: _dynamic_initializer_for__g_SampleHashTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SampleHashTable__()
{
  int i; // esi

  CUtlVector<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,CUtlMemory<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> >,CUtlMemory<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> >,int> > *)&g_SampleHashTable);
  CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > *)&g_SampleHashTable,
    elem: g_SampleHashTable.m_Buckets.m_Size,
    num: 0x10000);
  for ( i = 0; i < 0x10000; ++i )
  {
    CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>::RemoveAll(this: (CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *)&g_SampleHashTable.m_Buckets.m_Memory.m_pMemory[i]);
    g_SampleHashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  g_SampleHashTable.m_bPowerOfTwo = true;
  g_SampleHashTable.m_ModMask = 0xFFFF;
  return atexit(func: dynamic_atexit_destructor_for__g_SampleHashTable__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF650
// Name: _dynamic_initializer_for__g_PatchSampleHashTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PatchSampleHashTable__()
{
  int i; // esi

  CUtlVector<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,CUtlMemory<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,int>>::RemoveAll(this: &g_PatchSampleHashTable.m_Buckets);
  CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > *)&g_PatchSampleHashTable,
    elem: g_PatchSampleHashTable.m_Buckets.m_Size,
    num: 0x10000);
  for ( i = 0; i < 0x10000; ++i )
  {
    CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>::RemoveAll(this: &g_PatchSampleHashTable.m_Buckets.m_Memory.m_pMemory[i]);
    g_PatchSampleHashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  g_PatchSampleHashTable.m_bPowerOfTwo = true;
  g_PatchSampleHashTable.m_ModMask = 0xFFFF;
  return atexit(func: dynamic_atexit_destructor_for__g_PatchSampleHashTable__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF6C0
// Name: _dynamic_initializer_for__mb__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mb__()
{
  MessageBuffer::MessageBuffer(this: &mb);
  return atexit(func: dynamic_atexit_destructor_for__mb__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF6E0
// Name: _dynamic_initializer_for__g_ClusterDispFaces__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ClusterDispFaces__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ClusterDispFaces__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF6F0
// Name: _dynamic_initializer_for__g_SharedDispatchReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDispatchReg *dynamic_initializer_for__g_SharedDispatchReg__()
{
  return CDispatchReg::CDispatchReg(this: &g_SharedDispatchReg, iPacketID: 10, fn: SharedDispatch);
}

//------------------------------------------------------------------------------
// Address: 0x100BF710
// Name: _dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_SHARED_PACKET_ID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPIPacketIDReg_VMPI_SHARED_PACKET_ID__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPIPacketIDReg_VMPI_SHARED_PACKET_ID,
           nPacketID: 10,
           nSubPacketID: -1,
           pName: "VMPI_SHARED_PACKET_ID");
}

//------------------------------------------------------------------------------
// Address: 0x100BF730
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DIRECTORIES__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DIRECTORIES__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DIRECTORIES,
           nPacketID: 10,
           nSubPacketID: 0,
           pName: "VMPI_SUBPACKETID_DIRECTORIES");
}

//------------------------------------------------------------------------------
// Address: 0x100BF750
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DBINFO__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DBINFO__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_SUBPACKETID_DBINFO,
           nPacketID: 10,
           nSubPacketID: 1,
           pName: "VMPI_SUBPACKETID_DBINFO");
}

//------------------------------------------------------------------------------
// Address: 0x100BF770
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_CRASH__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_CRASH__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_SUBPACKETID_CRASH,
           nPacketID: 10,
           nSubPacketID: 3,
           pName: "VMPI_SUBPACKETID_CRASH");
}

//------------------------------------------------------------------------------
// Address: 0x100BF790
// Name: _dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_MULTICAST_ADDR__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVMPIPacketIDReg *dynamic_initializer_for__g_VMPISubPacketIDReg_VMPI_SUBPACKETID_MULTICAST_ADDR__()
{
  return CVMPIPacketIDReg::CVMPIPacketIDReg(
           this: &g_VMPISubPacketIDReg_VMPI_SUBPACKETID_MULTICAST_ADDR,
           nPacketID: 10,
           nSubPacketID: 4,
           pName: "VMPI_SUBPACKETID_MULTICAST_ADDR");
}

//------------------------------------------------------------------------------
// Address: 0x100BF7B0
// Name: _dynamic_initializer_for__g_Patches__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Patches__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Patches__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF7C0
// Name: _dynamic_initializer_for__g_FacePatches__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FacePatches__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FacePatches__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF7D0
// Name: _dynamic_initializer_for__faceParents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__faceParents__()
{
  return atexit(func: dynamic_atexit_destructor_for__faceParents__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF7E0
// Name: _dynamic_initializer_for__clusterChildren__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__clusterChildren__()
{
  return atexit(func: dynamic_atexit_destructor_for__clusterChildren__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF7F0
// Name: _dynamic_initializer_for__emitlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__emitlight__()
{
  return atexit(func: dynamic_atexit_destructor_for__emitlight__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF800
// Name: _dynamic_initializer_for__addlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__addlight__()
{
  return atexit(func: dynamic_atexit_destructor_for__addlight__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF810
// Name: _dynamic_initializer_for__g_FacesVisibleToLights__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FacesVisibleToLights__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FacesVisibleToLights__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF820
// Name: _dynamic_initializer_for__g_RtEnv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RtEnv__()
{
  RayTracingEnvironment::RayTracingEnvironment(this: &g_RtEnv);
  return atexit(func: dynamic_atexit_destructor_for__g_RtEnv__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF840
// Name: _dynamic_initializer_for__g_NonShadowCastingMaterialStrings__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_NonShadowCastingMaterialStrings__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_NonShadowCastingMaterialStrings__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF850
// Name: _dynamic_initializer_for__s_DetailPropLightStyleLumpLDR__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DetailPropLightStyleLumpLDR__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DetailPropLightStyleLumpLDR__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF860
// Name: _dynamic_initializer_for__s_DetailPropLightStyleLumpHDR__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DetailPropLightStyleLumpHDR__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DetailPropLightStyleLumpHDR__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF870
// Name: _dynamic_initializer_for__g_ModelCenterOffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ModelCenterOffset__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ModelCenterOffset__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF880
// Name: _dynamic_initializer_for__g_SpriteCenterOffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SpriteCenterOffset__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SpriteCenterOffset__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF890
// Name: _dynamic_initializer_for__s_DispMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DispMgr__()
{
  CVRadDispMgr::CVRadDispMgr(this: &s_DispMgr);
  return atexit(func: dynamic_atexit_destructor_for__s_DispMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF8B0
// Name: _dynamic_initializer_for__g_LastGoodLightData__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_LastGoodLightData__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_LastGoodLightData__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF8C0
// Name: _dynamic_initializer_for__g_FacesTouched__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FacesTouched__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FacesTouched__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF8D0
// Name: _dynamic_initializer_for____g_CreateCVRadDLLIVRadDLL_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCVRadDLLIVRadDLL_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCVRadDLLIVRadDLL_reg,
           fn: _CreateCVRadDLLIVRadDLL_interface,
           pName: "vraddll_1");
}

//------------------------------------------------------------------------------
// Address: 0x100BF8F0
// Name: _dynamic_initializer_for____g_CreateCVRadDLLILaunchableDLL_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCVRadDLLILaunchableDLL_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCVRadDLLILaunchableDLL_reg,
           fn: _CreateCVRadDLLILaunchableDLL_interface,
           pName: "launchable_dll_1");
}

//------------------------------------------------------------------------------
// Address: 0x100BF910
// Name: _dynamic_initializer_for__g_TotalDatSize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TotalDatSize__()
{
  int result; // eax

  result = CalcDatSize();
  g_TotalDatSize = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BF920
// Name: _dynamic_initializer_for__g_ForcedTextureShadowsModels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ForcedTextureShadowsModels__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_ForcedTextureShadowsModels,
    growSize: 0,
    initSize: 16,
    caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ForcedTextureShadowsModels__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF940
// Name: _dynamic_initializer_for__g_StaticPropMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StaticPropMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StaticPropMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x100BF950
// Name: _dynamic_initializer_for__g_ShadowTextureList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ShadowTextureList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ShadowTextureList__);
}

} // namespace vrad_dll

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0040DE20
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    free(pMem: this->m_szBuffer);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0040DE40
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(a1: pCurPos, a2: (const char *)v8, pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<unsigned long,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DFF0
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

} // namespace vtex_gui

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x10057070
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    operator delete(p: this->m_szBuffer);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>((CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10057090
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)operator new(size: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(a1: pCurPos, a2: (const char *)v8, pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow((CUtlMemory<CTCPPacket *,int> *)this, num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<int,int>::Grow((CUtlMemory<CTCPPacket *,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057240
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005726E
// Name: __getextendedkeycode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const NormKeyVals *__cdecl _getextendedkeycode(_KEY_EVENT_RECORD *pKE)
{
  unsigned int dwControlKeyState; // ebx
  const NormKeyVals *result; // eax
  int v3; // ecx
  unsigned int v4; // esi
  int v5; // ecx
  int wVirtualScanCode; // eax

  dwControlKeyState = pKE->dwControlKeyState;
  if ( (dwControlKeyState & 0x100) != 0 )
  {
    result = nullptr;
    v3 = 0;
    v4 = 0;
    while ( EnhancedKeys[v4].ScanCode != pKE->wVirtualScanCode )
    {
      ++v4;
      ++v3;
      if ( v4 >= 12 )
        return result;
    }
    v5 = v3;
    if ( (dwControlKeyState & 3) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].AltChars;
    if ( (dwControlKeyState & 0xC) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].CtrlChars;
    if ( (dwControlKeyState & 0x10) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].ShiftChars;
    return (const NormKeyVals *)&EnhancedKeys[v5].RegChars;
  }
  else
  {
    wVirtualScanCode = pKE->wVirtualScanCode;
    if ( (dwControlKeyState & 3) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].AltChars;
    }
    else if ( (dwControlKeyState & 0xC) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].CtrlChars;
    }
    else if ( (dwControlKeyState & 0x10) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].ShiftChars;
    }
    else
    {
      result = &NormalKeys[wVirtualScanCode];
    }
    if ( result->RegChars.LeadChar != 0 && result->RegChars.LeadChar != 0xE0 || result->RegChars.SecondChar == 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057321
// Name: __getch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _getch_nolock()
{
  int result; // eax
  int AsciiChar; // edi
  const NormKeyVals *v2; // eax
  unsigned int oldstate; // [esp+4h] [ebp-20h] BYREF
  unsigned int NumRead; // [esp+8h] [ebp-1Ch] BYREF
  _INPUT_RECORD ConInpRec; // [esp+Ch] [ebp-18h] BYREF

  if ( chbuf == -1 )
  {
    if ( _coninpfh == (HANDLE)-2 )
      __initconin();
    if ( _coninpfh == (HANDLE)-1 )
    {
      return -1;
    }
    else
    {
      GetConsoleMode(hConsoleHandle: _coninpfh, lpMode: &oldstate);
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: 0);
      while ( 1 )
      {
        if ( !ReadConsoleInputA(
                hConsoleInput: _coninpfh,
                lpBuffer: &ConInpRec,
                nLength: 1u,
                lpNumberOfEventsRead: &NumRead)
          || NumRead == 0 )
        {
          AsciiChar = -1;
          goto LABEL_15;
        }
        if ( ConInpRec.EventType == 1 && ConInpRec.Event.KeyEvent.bKeyDown != 0 )
        {
          AsciiChar = (unsigned __int8)ConInpRec.Event.KeyEvent.uChar.AsciiChar;
          if ( ConInpRec.Event.KeyEvent.uChar.AsciiChar != 0 )
            goto LABEL_15;
          v2 = _getextendedkeycode(pKE: &ConInpRec.Event.KeyEvent);
          if ( v2 != nullptr )
            break;
        }
      }
      AsciiChar = v2->RegChars.LeadChar;
      chbuf = v2->RegChars.SecondChar;
LABEL_15:
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: oldstate);
      return AsciiChar;
    }
  }
  else
  {
    result = (unsigned __int8)chbuf;
    chbuf = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100573FA
// Name: __kbhit_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _kbhit_nolock()
{
  void *v1; // esp
  _INPUT_RECORD *v2; // eax
  _INPUT_RECORD *v3; // ebx
  unsigned int v4; // edi
  _KEY_EVENT_RECORD *p_KeyEvent; // esi
  _DWORD v6[3]; // [esp+0h] [ebp-1Ch] BYREF
  int ret; // [esp+Ch] [ebp-10h]
  unsigned int NumPeeked; // [esp+10h] [ebp-Ch] BYREF
  unsigned int NumPending; // [esp+14h] [ebp-8h] BYREF

  ret = 0;
  if ( chbuf != -1 )
    return 1;
  if ( _coninpfh == (HANDLE)-2 )
    __initconin();
  if ( _coninpfh == (HANDLE)-1
    || !GetNumberOfConsoleInputEvents(hConsoleInput: _coninpfh, lpNumberOfEvents: &NumPending)
    || NumPending == 0 )
  {
    return 0;
  }
  if ( 0xFFFFFFE0 / NumPending >= 0x14 )
  {
    if ( 20 * NumPending + 8 > 0x400 )
    {
      v2 = (_INPUT_RECORD *)malloc(size: 20 * NumPending + 8);
      if ( v2 != nullptr )
      {
        *(_DWORD *)&v2->EventType = 56797;
        goto LABEL_14;
      }
    }
    else
    {
      v1 = alloca(20 * NumPending + 8);
      v2 = (_INPUT_RECORD *)v6;
      if ( v6 != nullptr )
      {
        v6[0] = 52428;
LABEL_14:
        v2 = (_INPUT_RECORD *)((char *)v2 + 8);
      }
    }
    v3 = v2;
    goto LABEL_17;
  }
  v3 = nullptr;
LABEL_17:
  if ( v3 == nullptr )
    return 0;
  if ( PeekConsoleInputA(hConsoleInput: _coninpfh, lpBuffer: v3, nLength: NumPending, lpNumberOfEventsRead: &NumPeeked) )
  {
    v4 = NumPeeked;
    if ( NumPeeked != 0 && NumPeeked <= NumPending )
    {
      p_KeyEvent = &v3->Event.KeyEvent;
      do
      {
        if ( LOWORD(p_KeyEvent[-1].dwControlKeyState) == 1
          && p_KeyEvent->bKeyDown != 0
          && (p_KeyEvent->uChar.AsciiChar != 0 || _getextendedkeycode(pKE: p_KeyEvent) != nullptr) )
        {
          ret = 1;
        }
        --v4;
        p_KeyEvent = (_KEY_EVENT_RECORD *)((char *)p_KeyEvent + 20);
        NumPeeked = v4;
      }
      while ( v4 != 0 );
    }
  }
  _freea(_Memory: v3);
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x10057522
// Name: _getch
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl getch()
{
  int v1; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 3);
  v1 = _getch_nolock();
  _unlock(locknum: 3);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10057560
// Name: _kbhit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl kbhit()
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 3);
  retval = _kbhit_nolock();
  _unlock(locknum: 3);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1005759E
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)malloc(size: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005771C
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057750
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100577AD
// Name: ___initconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconin()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONIN$",
             dwDesiredAccess: 0xC0000000,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _coninpfh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100577CC
// Name: ___termconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconin()
{
  HANDLE result; // eax

  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _coninpfh);
  return result;
}

} // namespace vvis_dll

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1036CEC0
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    C_BaseEntity::operator delete(pMem: this->m_szBuffer);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1036CEE0
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(a1: pCurPos, a2: (const char *)v8, pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036D090
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1037D470
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    free(pMem: this->m_szBuffer);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1037D490
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(a1: pCurPos, a2: (const char *)v8, pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037D640
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

} // namespace server

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x1003C2D0
// Name: public: CSplitString::~CSplitString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::~CSplitString(CSplitString *this)
{
  if ( this->m_szBuffer != nullptr )
    free(pMem: this->m_szBuffer);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>((CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1003C2F0
// Name: private: void CSplitString::Construct(char const __near *,char const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitString::Construct(CSplitString *this, char *pString, const char **pSeparators, int nSeparators)
{
  unsigned int v5; // edi
  char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  const char *v9; // eax
  char *v10; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v14; // eax
  char **v15; // edi
  int v16; // edi
  int v17; // eax
  char *v18; // ebx
  char **v19; // ecx
  int v20; // eax
  char **v21; // eax
  int separatorLen; // [esp+Ch] [ebp-Ch]
  int separatorLena; // [esp+Ch] [ebp-Ch]
  const char *pFirstSeparator; // [esp+10h] [ebp-8h]
  const char *pCurPos; // [esp+14h] [ebp-4h]

  v5 = _V_strlen(str: pString) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_szBuffer = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pString, count: v5);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  for ( pCurPos = pString; ; pCurPos = &v7[separatorLena] )
  {
    v7 = nullptr;
    v8 = 0;
    separatorLen = -1;
    pFirstSeparator = nullptr;
    if ( nSeparators <= 0 )
      break;
    do
    {
      v9 = V_stristr(a1: pCurPos, a2: (const char *)v8, pStr: pCurPos, pSearch: pSeparators[v8]);
      if ( v9 != nullptr && (v7 == nullptr || v9 < v7) )
      {
        separatorLen = v8;
        pFirstSeparator = v9;
        v7 = v9;
      }
      ++v8;
    }
    while ( v8 < nSeparators );
    if ( v7 == nullptr )
      break;
    separatorLena = strlen(pSeparators[separatorLen]);
    if ( v7 > pCurPos )
    {
      v10 = (char *)&pCurPos[this->m_szBuffer - pString];
      v7[this->m_szBuffer - pString] = 0;
      m_Size = this->m_Size;
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<GCSDK::CLock *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Size;
      m_pMemory = this->m_Memory.m_pMemory;
      v14 = this->m_Size - m_Size - 1;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &this->m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v10;
      v7 = pFirstSeparator;
    }
  }
  if ( strlen(pCurPos) != 0 )
  {
    v16 = this->m_Size;
    v17 = this->m_Memory.m_nAllocationCount;
    v18 = (char *)&pCurPos[this->m_szBuffer - pString];
    if ( v16 + 1 > v17 )
      CUtlMemory<GCSDK::CLock *,int>::Grow((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, num: v16 - v17 + 1);
    ++this->m_Size;
    v19 = this->m_Memory.m_pMemory;
    v20 = this->m_Size - v16 - 1;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
    v21 = &this->m_Memory.m_pMemory[v16];
    if ( v21 != nullptr )
      *v21 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C4A0
// Name: public: CSplitString::CSplitString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitString *__thiscall CSplitString::CSplitString(CSplitString *this, char *pString, const char *pSeparator)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  CSplitString::Construct(this, pString, pSeparators: &pSeparator, nSeparators: 1);
  return this;
}

} // namespace matchmaking
