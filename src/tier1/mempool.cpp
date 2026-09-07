// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/mempool.cpp
// Functions: 7
// ============================================================

#include "tier1\mempool.h"

//------------------------------------------------------------------------------
// Address: 0x1026CA50
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1026CA90
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026CAB0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x1026CAE0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x1026CB70
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1026CBC0
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1026CC40
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

// ============================================================
// Overlay from vstdlib (Missing functions)
// ============================================================
namespace vstdlib {

//------------------------------------------------------------------------------
// Address: 0x10012470
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100124B0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x100124E0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x10012570
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100125C0
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012640
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace vstdlib

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x10258F00
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10258F40
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258F60
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x10258F90
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x10259020
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10259070
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

} // namespace MaterialSystem

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1008FDC0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008FE00
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008FE30
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x1008FEC0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008FF10
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008FF90
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0047EA40
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047EA80
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047EAB0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x0047EB40
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047EB90
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047EC10
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace avitest

// ============================================================
// Overlay from datacache (Missing functions)
// ============================================================
namespace datacache {

//------------------------------------------------------------------------------
// Address: 0x10018770
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100187B0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100187D0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x10018800
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x10018890
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100188E0
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

} // namespace datacache

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x100B1CF0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B1D30
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B1D60
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x100B1DF0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B1E40
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B1EC0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace dedicated

// ============================================================
// Overlay from dmxconvert (Missing functions)
// ============================================================
namespace dmxconvert {

//------------------------------------------------------------------------------
// Address: 0x004640E0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00464120
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464140
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00464170
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00464200
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00464250
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004642D0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace dmxconvert

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00571320
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00571360
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00571380
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x005713B0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00571440
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00571490
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00571510
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005D4020
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005D4060
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D4080
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x005D40B0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x005D4140
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005D4190
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005D4210
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1026CAC0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1026CB00
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026CB20
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x1026CB50
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x1026CBE0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1026CC30
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1026CCB0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102B49A0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102B49E0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B4A00
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x102B4A30
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x102B4AC0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102B4B10
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102B4B90
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103744A3
// Name: public: void __near * CFixedAllocNoSync::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
CFixedAllocNoSync::CNode *__thiscall CFixedAllocNoSync::Alloc(CFixedAllocNoSync *this)
{
  CPlex *v2; // eax
  signed int v3; // ecx
  CFixedAllocNoSync::CNode *i; // eax
  CFixedAllocNoSync::CNode *result; // eax

  if ( this->m_pNodeFree == nullptr )
  {
    v2 = CPlex::Create(pHead: &this->m_pBlocks, nMax: this->m_nBlockSize, cbElement: this->m_nAllocSize);
    v3 = this->m_nBlockSize - 1;
    for ( i = (CFixedAllocNoSync::CNode *)((char *)&v2[1] + v3 * this->m_nAllocSize); v3 >= 0; --v3 )
    {
      i->pNext = this->m_pNodeFree;
      this->m_pNodeFree = i;
      i = (CFixedAllocNoSync::CNode *)((char *)i - this->m_nAllocSize);
    }
  }
  result = this->m_pNodeFree;
  this->m_pNodeFree = result->pNext;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400E16
// Name: protected: virtual unsigned char __near * CMemFile::Alloc(unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CMemFile::Alloc(CMemFile *this, unsigned int nBytes)
{
  return (unsigned __int8 *)MemAlloc_Alloc(nSize: nBytes);
}

//------------------------------------------------------------------------------
// Address: 0x10400E3E
// Name: public: virtual void CAfxStringMgr::Free(struct ATL::CStringData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAfxStringMgr::Free(CMemFile *this, unsigned __int8 *lpMem)
{
  free(pMem: lpMem);
}

//------------------------------------------------------------------------------
// Address: 0x1041E84C
// Name: protected: virtual unsigned char __near * CSharedFile::Alloc(unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CSharedFile::Alloc(CSharedFile *this, SIZE_T nBytes)
{
  unsigned __int8 *result; // eax

  result = (unsigned __int8 *)GlobalAlloc(uFlags: this->m_nAllocFlags, dwBytes: nBytes);
  this->m_hGlobalMemory = result;
  if ( result != nullptr )
    return (unsigned __int8 *)GlobalLock(hMem: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E8B0
// Name: protected: virtual void CSharedFile::Free(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSharedFile::Free(CSharedFile *this, unsigned __int8 *__formal)
{
  GlobalUnlock(hMem: this->m_hGlobalMemory);
  GlobalFree(hMem: this->m_hGlobalMemory);
}

//------------------------------------------------------------------------------
// Address: 0x103744E5
// Name: public: int CMFCButton::IsPressed(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCButton::IsPressed(CMFCButton *this)
{
  BOOL result; // eax

  result = false;
  if ( this->m_bPushed != 0 )
    return this->m_bHighlighted != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103744F9
// Name: public: CMFCToolTipInfo::CMFCToolTipInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolTipInfo *__thiscall CMFCToolTipInfo::CMFCToolTipInfo(CMFCToolTipInfo *this)
{
  this->m_bDrawIcon = 1;
  this->m_bDrawDescription = 1;
  this->m_bBoldLabel = 1;
  this->m_bDrawSeparator = 1;
  this->m_bBalloonTooltip = 0;
  this->m_bRoundedCorners = 0;
  this->m_bVislManagerTheme = 0;
  this->m_nMaxDescrWidth = 200;
  this->m_nGradientAngle = -1;
  this->m_clrFill = -1;
  this->m_clrFillGradient = -1;
  this->m_clrText = -1;
  this->m_clrBorder = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1037452E
// Name: public: class CMFCToolTipInfo __near & CMFCToolTipInfo::operator=(class CMFCToolTipInfo __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolTipInfo *__thiscall CMFCToolTipInfo::operator=(CMFCToolTipInfo *this, CMFCToolTipInfo *src)
{
  *this = *src;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10374588
// Name: public: virtual struct CRuntimeClass __near * CMFCVisualManager::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCVisualManager::GetRuntimeClass(CMFCVisualManager *this)
{
  return &CMFCVisualManager::classCMFCVisualManager;
}

//------------------------------------------------------------------------------
// Address: 0x1037458E
// Name: public: static void CMFCVisualManager::AdjustToolbars(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __stdcall CMFCVisualManager::AdjustToolbars()
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *v1; // eax
  CObject *v2; // edi
  CObject *data; // [esp-8h] [ebp-Ch]

  m_pNodeHead = afxAllToolBars.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    if ( m_pNodeHead == nullptr )
      AfxThrowInvalidArgException();
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v1 = AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: data);
    v2 = v1;
    if ( v1 != nullptr && CWnd::FromHandlePermanent(hWnd: (CDocument *)v1[8].__vftable) != nullptr )
      v2->__vftable[79].GetRuntimeClass(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103745DC
// Name: public: virtual void CMFCVisualManager::OnDrawBarGripper(class CDC __near *,class CRect,int,class CBasePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawBarGripper(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rectGripper,
        int bHorz,
        CBasePane *pBar)
{
  COLORREF clrBarHilite; // edi
  COLORREF clrBarShadow; // esi

  if ( pBar == nullptr || (clrBarHilite = afxGlobalData.clrBtnHilite, pBar->m_bIsDlgControl == 0) )
    clrBarHilite = afxGlobalData.clrBarHilite;
  if ( pBar == nullptr || (clrBarShadow = afxGlobalData.clrBtnShadow, pBar->m_bIsDlgControl == 0) )
    clrBarShadow = afxGlobalData.clrBarShadow;
  if ( bHorz != 0 )
  {
    InflateRect(lprc: &rectGripper, dx: 0, dy: -3);
    rectGripper.left = (rectGripper.right + rectGripper.left) / 2 - 1;
    rectGripper.right = rectGripper.left + 3;
  }
  else
  {
    InflateRect(lprc: &rectGripper, dx: -3, dy: 0);
    rectGripper.top = (rectGripper.bottom + rectGripper.top) / 2 - 1;
    rectGripper.bottom = rectGripper.top + 3;
  }
  CDC::Draw3dRect(this: pDC, lpRect: &rectGripper, clrTopLeft: clrBarHilite, clrBottomRight: clrBarShadow);
}

//------------------------------------------------------------------------------
// Address: 0x10374678
// Name: public: virtual void CMFCVisualManager::OnDrawMenuBorder(class CDC __near *,class CMFCPopupMenu __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawMenuBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCPopupMenu *__formal,
        CRect rect)
{
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarLight,
    clrBottomRight: afxGlobalData.clrBarDkShadow);
  InflateRect(lprc: &rect, dx: -1, dy: -1);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarHilite,
    clrBottomRight: afxGlobalData.clrBarShadow);
}

//------------------------------------------------------------------------------
// Address: 0x103746C2
// Name: public: virtual void CMFCVisualManager::OnDrawMenuShadow(class CDC __near *,class CRect const __near &,class CRect const __near &,int,int,int,class CBitmap __near *,class CBitmap __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawMenuShadow(
        CMFCVisualManager *this,
        CDC *pPaintDC,
        const CRect *rectClient,
        const CRect *__formal,
        int nDepth,
        int iMinBrightness,
        int iMaxBrightness,
        CBitmap *pBmpSaveBottom,
        CBitmap *pBmpSaveRight,
        int bRTL)
{
  CDrawingManager dm; // [esp+10h] [ebp-14h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  CDrawingManager::CDrawingManager(this: &dm, m_dc: pPaintDC);
  v11 = 0;
  CDrawingManager::DrawShadow(
    this: &dm,
    rect: *rectClient,
    nDepth,
    iMinBrightness,
    iMaxBrightness,
    pBmpSaveBottom,
    pBmpSaveRight,
    clrBase: 0xFFFFFFFF,
    bRightShadow: bRTL == 0);
  v11 = -1;
  CDrawingManager::~CDrawingManager(this: &dm);
}

//------------------------------------------------------------------------------
// Address: 0x1037471F
// Name: public: virtual void CMFCVisualManager::OnFillButtonInterior(class CDC __near *,class CMFCToolBarButton __near *,class CRect,enum CMFCVisualManager::AFX_BUTTON_STATE)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillButtonInterior(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCToolBarButton *pButton,
        tagRECT rect,
        CMFCVisualManager::AFX_BUTTON_STATE state)
{
  CObject *v6; // eax
  CObject *v7; // eax
  CDrawingManager v8; // [esp+10h] [ebp-28h] BYREF
  tagRECT rc; // [esp+18h] [ebp-20h] BYREF
  int v10; // [esp+34h] [ebp-4h]

  if ( CObject::IsKindOf(this: pButton, pClass: &CMFCShowAllButton::classCMFCShowAllButton) != 0 )
  {
    if ( state == ButtonsIsHighlighted )
    {
      CDrawingManager::CDrawingManager(this: &v8, m_dc: pDC);
      v10 = 0;
      CDrawingManager::HighlightRect(
        this: &v8,
        (CRect)rect,
        nPercentage: -1,
        clrTransparent: -1,
        nTolerance: 0,
        clrBlend: 0xFFFFFFFF);
      v10 = -1;
      CDrawingManager::~CDrawingManager(this: &v8);
    }
  }
  else if ( (this->m_bEnableToolbarButtonFill != 0
          || (v6 = AfxDynamicDownCast(pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton, pObject: pButton)) != nullptr
          && (v7 = (CObject *)v6[27].__vftable) != nullptr
          && CObject::IsKindOf(this: v7, pClass: &CMFCPopupMenuBar::classCMFCPopupMenuBar) != 0)
         && CObject::IsKindOf(this: pButton, pClass: &CMFCOutlookBarPaneButton::classCMFCOutlookBarPaneButton) == 0
         && CMFCToolBar::m_bCustomizeMode == 0
         && state != ButtonsIsHighlighted
         && (pButton->m_nStyle & 0x110000) != 0 )
  {
    rc = rect;
    InflateRect(lprc: &rc, dx: -afxData.cxBorder2, dy: -afxData.cyBorder2);
    CMFCToolBarImages::FillDitheredRect(pDC, rect: (const CRect *)&rc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10374811
// Name: public: virtual unsigned long CMFCVisualManager::GetToolbarHighlightColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetToolbarHighlightColor(CMFCVisualManager *this)
{
  return afxGlobalData.clrBarFace;
}

//------------------------------------------------------------------------------
// Address: 0x10374817
// Name: public: virtual unsigned long CMFCVisualManager::GetToolbarDisabledTextColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetToolbarDisabledTextColor(CMFCVisualManager *this)
{
  return afxGlobalData.clrGrayedText;
}

//------------------------------------------------------------------------------
// Address: 0x1037481D
// Name: public: virtual unsigned long CMFCVisualManager::GetHighlightedMenuItemTextColor(class CMFCToolBarMenuButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetHighlightedMenuItemTextColor(
        CMFCVisualManager *this,
        CMFCToolBarMenuButton *pButton)
{
  unsigned int result; // eax

  result = afxGlobalData.clrGrayedText;
  if ( (pButton->m_nStyle & 0x40000) == 0 )
    return afxGlobalData.clrTextHilite;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1037483C
// Name: public: virtual void CMFCVisualManager::OnHighlightRarelyUsedMenuItems(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnHighlightRarelyUsedMenuItems(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rectRarelyUsed)
{
  CDrawingManager dm; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  CDrawingManager::CDrawingManager(this: &dm, m_dc: pDC);
  v4 = 0;
  CDrawingManager::HighlightRect(
    this: &dm,
    rect: rectRarelyUsed,
    nPercentage: -1,
    clrTransparent: -1,
    nTolerance: 0,
    clrBlend: 0xFFFFFFFF);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectRarelyUsed,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarHilite);
  v4 = -1;
  CDrawingManager::~CDrawingManager(this: &dm);
}

//------------------------------------------------------------------------------
// Address: 0x1037489F
// Name: public: virtual void CMFCVisualManager::OnDrawMenuCheck(class CDC __near *,class CMFCToolBarMenuButton __near *,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawMenuCheck(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCToolBarMenuButton *pButton,
        CRect rectCheck,
        int __formal,
        int bIsRadio)
{
  unsigned int m_nStyle; // eax
  CSize sizeImageDest; // [esp+0h] [ebp-8h] BYREF

  m_nStyle = pButton->m_nStyle;
  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(
    pDC,
    id: (CMenuImages::IMAGES_IDS)(bIsRadio != 0 ? IdRadio : IdCheck),
    rectImage: &rectCheck,
    state: (CMenuImages::IMAGE_STATE)((m_nStyle & 0x40000) != 0),
    &sizeImageDest);
}

//------------------------------------------------------------------------------
// Address: 0x103748DE
// Name: public: virtual void CMFCVisualManager::OnDrawMenuItemButton(class CDC __near *,class CMFCToolBarMenuButton __near *,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawMenuItemButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCToolBarMenuButton *__formal,
        CRect rectButton,
        int bHighlight,
        int a6)
{
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  rect.top = rectButton.top;
  rect.bottom = rectButton.bottom;
  rect.left = rectButton.left - 1;
  rect.right = rectButton.left + 1;
  InflateRect(lprc: &rect, dx: 0, dy: -(bHighlight != 0 ? 1 : 4));
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarHilite);
}

//------------------------------------------------------------------------------
// Address: 0x1037494E
// Name: public: virtual void CMFCVisualManager::OnDrawButtonBorder(class CDC __near *,class CMFCToolBarButton __near *,class CRect,enum CMFCVisualManager::AFX_BUTTON_STATE)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawButtonBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCToolBarButton *pButton,
        CRect rect,
        CMFCVisualManager::AFX_BUTTON_STATE state)
{
  int IsKindOf; // eax
  COLORREF clrBarDkShadow; // ecx

  IsKindOf = CObject::IsKindOf(this: pButton, pClass: &CMFCOutlookBarPaneButton::classCMFCOutlookBarPaneButton);
  clrBarDkShadow = afxGlobalData.clrBarDkShadow;
  if ( IsKindOf == 0 )
    clrBarDkShadow = afxGlobalData.clrBarShadow;
  if ( state == ButtonsIsPressed )
  {
    CDC::Draw3dRect(this: pDC, lpRect: &rect, clrTopLeft: clrBarDkShadow, clrBottomRight: afxGlobalData.clrBarHilite);
  }
  else if ( state == ButtonsIsHighlighted )
  {
    CDC::Draw3dRect(this: pDC, lpRect: &rect, clrTopLeft: afxGlobalData.clrBarHilite, clrBottomRight: clrBarDkShadow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037499D
// Name: public: virtual void CMFCVisualManager::OnDrawButtonSeparator(class CDC __near *,class CMFCToolBarButton __near *,class CRect,enum CMFCVisualManager::AFX_BUTTON_STATE,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawButtonSeparator(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCToolBarButton *pButton,
        CRect rect,
        CMFCVisualManager::AFX_BUTTON_STATE state,
        int __formal)
{
  if ( this->m_bMenuFlatLook == 0 || pButton->IsDroppedDown(this: pButton) == 0 )
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCToolBarButton *, int, int, int, int, CMFCVisualManager::AFX_BUTTON_STATE))this->OnDrawButtonBorder)(
      a1: this,
      a2: pDC,
      a3: pButton,
      a4: rect.left,
      a5: rect.top,
      a6: rect.right,
      a7: rect.bottom,
      a8: state);
}

//------------------------------------------------------------------------------
// Address: 0x103749DF
// Name: public: virtual void CMFCVisualManager::OnDrawSeparator(class CDC __near *,class CBasePane __near *,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawSeparator(
        CMFCVisualManager *this,
        CDC *pDC,
        CBasePane *pBar,
        CRect rect,
        int bHorz)
{
  COLORREF clrBtnHilite; // edx
  COLORREF clrBtnShadow; // eax
  CRect rectSeparator; // [esp+8h] [ebp-14h] BYREF

  rectSeparator = rect;
  if ( bHorz != 0 )
  {
    rectSeparator.left = (rect.right - rect.left) / 2 + rect.left - 1;
    rectSeparator.right = rectSeparator.left + 2;
  }
  else
  {
    rectSeparator.top = (rect.bottom - rect.top) / 2 + rect.top - 1;
    rectSeparator.bottom = rectSeparator.top + 2;
  }
  clrBtnHilite = afxGlobalData.clrBtnHilite;
  if ( pBar->m_bIsDlgControl != 0 )
  {
    clrBtnShadow = afxGlobalData.clrBtnShadow;
  }
  else
  {
    clrBtnHilite = afxGlobalData.clrBarHilite;
    clrBtnShadow = afxGlobalData.clrBarShadow;
  }
  CDC::Draw3dRect(this: pDC, lpRect: &rectSeparator, clrTopLeft: clrBtnShadow, clrBottomRight: clrBtnHilite);
}

//------------------------------------------------------------------------------
// Address: 0x10374A7C
// Name: public: virtual void CMFCVisualManager::OnDrawCaptionButton(class CDC __near *,class CMFCCaptionButton __near *,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawCaptionButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCCaptionButton *pButton,
        int bActive,
        int bHorz,
        int bMaximized,
        int bDisabled,
        CMenuImages::IMAGES_IDS nImageID)
{
  CMenuImages::IMAGES_IDS v8; // eax
  CMenuImages::IMAGE_STATE v9; // eax
  CDC *v10; // edi
  int m_bPushed; // eax
  CSize sizeImageDest; // [esp+Ch] [ebp-34h] BYREF
  CDC *v13; // [esp+14h] [ebp-2Ch]
  CMenuImages::IMAGES_IDS id; // [esp+18h] [ebp-28h]
  CRect rectImage; // [esp+1Ch] [ebp-24h] BYREF
  CRect rc; // [esp+2Ch] [ebp-14h] BYREF

  v13 = pDC;
  pButton->GetRect(this: pButton, result: &rc);
  v8 = nImageID;
  if ( nImageID == -1 )
    v8 = pButton->GetIconID(this: pButton, a2: bHorz, a3: bMaximized);
  rectImage = rc;
  id = v8;
  if ( pButton->m_bPushed != 0 && (pButton->m_bFocused != 0 || pButton->m_bDroppedDown != 0) )
    OffsetRect(lprc: &rectImage, dx: 1, dy: 1);
  if ( bDisabled != 0 )
  {
    v9 = ImageGray;
  }
  else if ( pButton->m_clrForeground == -1 )
  {
    v9 = bActive != 0 ? ImageWhite : ImageBlack;
  }
  else if ( LOBYTE(pButton->m_clrForeground) <= 0xC0u
         || BYTE1(pButton->m_clrForeground) <= 0xC0u
         || BYTE2(pButton->m_clrForeground) <= 0xC0u )
  {
    v9 = ImageBlack;
  }
  else
  {
    v9 = ImageWhite;
  }
  v10 = v13;
  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(pDC: v13, id, &rectImage, state: v9, &sizeImageDest);
  if ( bDisabled == 0 )
  {
    m_bPushed = pButton->m_bPushed;
    if ( m_bPushed != 0 && (pButton->m_bFocused != 0 || pButton->m_bDroppedDown != 0) )
    {
      CDC::Draw3dRect(
        this: v10,
        lpRect: &rc,
        clrTopLeft: afxGlobalData.clrBarDkShadow,
        clrBottomRight: afxGlobalData.clrBarLight);
      InflateRect(lprc: &rc, dx: -1, dy: -1);
      CDC::Draw3dRect(
        this: v10,
        lpRect: &rc,
        clrTopLeft: afxGlobalData.clrBarDkShadow,
        clrBottomRight: afxGlobalData.clrBarHilite);
    }
    else if ( pButton->m_bFocused != 0 || m_bPushed != 0 || pButton->m_bDroppedDown != 0 )
    {
      CDC::Draw3dRect(
        this: v10,
        lpRect: &rc,
        clrTopLeft: afxGlobalData.clrBarHilite,
        clrBottomRight: afxGlobalData.clrBarShadow);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10374BB5
// Name: public: virtual int CMFCVisualManager::OnEraseTabsFrame(class CDC __near *,class CRect,class CMFCBaseTabCtrl const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCVisualManager::OnEraseTabsFrame(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        CMFCBaseTabCtrl *pTabWnd)
{
  CMFCBaseTabCtrl *v4; // edi
  CMFCBaseTabCtrl_vtbl *v5; // esi
  int v6; // eax
  COLORREF v7; // eax

  v4 = pTabWnd;
  v5 = pTabWnd->__vftable;
  v6 = pTabWnd->GetActiveTab(this: pTabWnd);
  v7 = v5->GetTabBkColor(this: v4, a2: v6);
  if ( v7 == -1 )
    return 0;
  CDC::FillSolidRect(this: pDC, lpRect: &rect, clr: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10374BF5
// Name: public: virtual void CMFCVisualManager::OnDrawTabsButtonBorder(class CDC __near *,class CRect __near &,class CMFCButton __near *,unsigned int,class CMFCBaseTabCtrl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawTabsButtonBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect *rect,
        CMFCButton *pButton,
        char uiState,
        CMFCBaseTabCtrl *__formal)
{
  CRect *v6; // esi

  if ( CMFCButton::IsPressed(this: pButton) || (uiState & 1) != 0 )
  {
    v6 = rect;
    CDC::Draw3dRect(
      this: pDC,
      lpRect: rect,
      clrTopLeft: afxGlobalData.clrBarDkShadow,
      clrBottomRight: afxGlobalData.clrBarHilite);
    rect->left += 2;
    rect->top += 2;
  }
  else
  {
    v6 = rect;
    CDC::Draw3dRect(
      this: pDC,
      lpRect: rect,
      clrTopLeft: afxGlobalData.clrBarHilite,
      clrBottomRight: afxGlobalData.clrBarDkShadow);
  }
  InflateRect(lprc: v6, dx: -2, dy: -2);
}

//------------------------------------------------------------------------------
// Address: 0x10374C56
// Name: public: virtual void CMFCVisualManager::OnDrawMenuArrowOnCustomizeList(class CDC __near *,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawMenuArrowOnCustomizeList(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rectCommand,
        int bSelected)
{
  CSize *v4; // eax
  int v5; // ecx
  CSize result; // [esp+Ch] [ebp-2Ch] BYREF
  CRect rectLine; // [esp+14h] [ebp-24h] BYREF
  CRect rectTriangle; // [esp+24h] [ebp-14h] BYREF

  rectTriangle = rectCommand;
  v4 = CMenuImages::Size(&result);
  v5 = rectTriangle.right - v4->cx;
  result.cx = 0;
  result.cy = 0;
  rectTriangle.left = v5;
  CMenuImages::Draw(
    pDC,
    id: IdArrowRightLarge,
    rectImage: &rectTriangle,
    state: bSelected != 0 ? ImageWhite : ImageBlack,
    sizeImageDest: &result);
  rectLine.top = rectCommand.top;
  rectLine.bottom = rectCommand.bottom;
  rectLine.right = rectTriangle.left - 1;
  rectLine.left = rectTriangle.left - 3;
  InflateRect(lprc: &rectLine, dx: 0, dy: -2);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectLine,
    clrTopLeft: afxGlobalData.clrBtnShadow,
    clrBottomRight: afxGlobalData.clrBtnHilite);
}

//------------------------------------------------------------------------------
// Address: 0x10374CF9
// Name: public: virtual void CMFCVisualManager::OnDrawMenuResizeBar(class CDC __near *,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawMenuResizeBar(CMFCVisualManager *this, CDC *pDC, CRect rect, int __formal)
{
  CDC::FillSolidRect(this: pDC, lpRect: &rect, clr: afxGlobalData.clrInactiveCaption);
}

//------------------------------------------------------------------------------
// Address: 0x10374D14
// Name: public: virtual void CMFCVisualManager::OnDrawComboBorder(class CDC __near *,class CRect,int,int,int,class CMFCToolBarComboBoxButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawComboBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        int __formal,
        int bIsDropped,
        int bIsHighlighted,
        CMFCToolBarComboBoxButton *a7)
{
  CRect rectBorder; // [esp+4h] [ebp-14h] BYREF

  if ( bIsHighlighted != 0 || bIsDropped != 0 )
  {
    if ( this->m_bMenuFlatLook != 0 )
    {
      rectBorder = rect;
      InflateRect(lprc: &rectBorder, dx: -1, dy: -1);
      CDC::Draw3dRect(
        this: pDC,
        lpRect: &rectBorder,
        clrTopLeft: afxGlobalData.clrBarDkShadow,
        clrBottomRight: afxGlobalData.clrBarDkShadow);
    }
    else
    {
      CDC::Draw3dRect(
        this: pDC,
        lpRect: &rect,
        clrTopLeft: afxGlobalData.clrBarShadow,
        clrBottomRight: afxGlobalData.clrBarHilite);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10374D91
// Name: public: virtual void CMFCVisualManager::OnDrawStatusBarPaneBorder(class CDC __near *,class CMFCStatusBar __near *,class CRect,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawStatusBarPaneBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCStatusBar *__formal,
        CRect rectPane,
        unsigned int a5,
        __int16 nStyle)
{
  COLORREF clrBarShadow; // eax
  COLORREF clrBarHilite; // edx

  if ( (nStyle & 0x100) == 0 )
  {
    if ( (nStyle & 0x200) != 0 )
    {
      clrBarShadow = afxGlobalData.clrBarShadow;
      clrBarHilite = afxGlobalData.clrBarHilite;
    }
    else
    {
      clrBarShadow = afxGlobalData.clrBarHilite;
      clrBarHilite = afxGlobalData.clrBarShadow;
    }
    CDC::Draw3dRect(this: pDC, lpRect: &rectPane, clrTopLeft: clrBarHilite, clrBottomRight: clrBarShadow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10374DD2
// Name: public: virtual void CMFCVisualManager::OnDrawMiniFrameBorder(class CDC __near *,class CPaneFrameWnd __near *,class CRect,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawMiniFrameBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CPaneFrameWnd *pFrameWnd,
        CRect rectBorder,
        CRect rectBorderSize)
{
  AFX_PREDOCK_STATE m_preDockStateCurr; // eax
  void (__stdcall *v6)(LPRECT, int, int); // esi

  m_preDockStateCurr = pFrameWnd->m_preDockStateCurr;
  if ( m_preDockStateCurr == PDS_DOCK_REGULAR )
  {
    CDC::Draw3dRect(this: pDC, lpRect: &rectBorder, clrTopLeft: 0x7Fu, clrBottomRight: afxGlobalData.clrBarDkShadow);
    v6 = (void (__stdcall *)(LPRECT, int, int))InflateRect;
    InflateRect(lprc: &rectBorder, dx: -1, dy: -1);
    CDC::Draw3dRect(this: pDC, lpRect: &rectBorder, clrTopLeft: afxGlobalData.clrBarHilite, clrBottomRight: 0x7Fu);
  }
  else if ( m_preDockStateCurr == PDS_DOCK_TO_TAB )
  {
    CDC::Draw3dRect(this: pDC, lpRect: &rectBorder, clrTopLeft: 0x7F0000u, clrBottomRight: afxGlobalData.clrBarDkShadow);
    v6 = (void (__stdcall *)(LPRECT, int, int))InflateRect;
    InflateRect(lprc: &rectBorder, dx: -1, dy: -1);
    CDC::Draw3dRect(this: pDC, lpRect: &rectBorder, clrTopLeft: afxGlobalData.clrBarHilite, clrBottomRight: 0x7F0000u);
  }
  else
  {
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rectBorder,
      clrTopLeft: afxGlobalData.clrBarFace,
      clrBottomRight: afxGlobalData.clrBarDkShadow);
    v6 = (void (__stdcall *)(LPRECT, int, int))InflateRect;
    InflateRect(lprc: &rectBorder, dx: -1, dy: -1);
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rectBorder,
      clrTopLeft: afxGlobalData.clrBarHilite,
      clrBottomRight: afxGlobalData.clrBarShadow);
  }
  v6(lprc: &rectBorder, dx: 2 - rectBorderSize.right, dy: 2 - rectBorderSize.top);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectBorder,
    clrTopLeft: afxGlobalData.clrBarFace,
    clrBottomRight: afxGlobalData.clrBarFace);
  v6(lprc: &rectBorder, dx: 1, dy: 1);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectBorder,
    clrTopLeft: afxGlobalData.clrBarFace,
    clrBottomRight: afxGlobalData.clrBarFace);
}

//------------------------------------------------------------------------------
// Address: 0x10374ED2
// Name: public: virtual void CMFCVisualManager::OnDrawFloatingToolbarBorder(class CDC __near *,class CMFCBaseToolBar __near *,class CRect,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawFloatingToolbarBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCBaseToolBar *__formal,
        CRect rectBorder,
        CRect a5)
{
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectBorder,
    clrTopLeft: afxGlobalData.clrBarFace,
    clrBottomRight: afxGlobalData.clrBarDkShadow);
  InflateRect(lprc: &rectBorder, dx: -1, dy: -1);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectBorder,
    clrTopLeft: afxGlobalData.clrBarHilite,
    clrBottomRight: afxGlobalData.clrBarShadow);
  InflateRect(lprc: &rectBorder, dx: -1, dy: -1);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectBorder,
    clrTopLeft: afxGlobalData.clrBarFace,
    clrBottomRight: afxGlobalData.clrBarFace);
}

//------------------------------------------------------------------------------
// Address: 0x10374F3C
// Name: public: virtual unsigned long CMFCVisualManager::GetToolbarButtonTextColor(class CMFCToolBarButton __near *,enum CMFCVisualManager::AFX_BUTTON_STATE)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetToolbarButtonTextColor(
        CMFCVisualManager *this,
        CMFCToolBarButton *pButton,
        CMFCVisualManager::AFX_BUTTON_STATE state)
{
  int v3; // esi
  unsigned int result; // eax

  if ( CMFCToolBar::m_bCustomizeMode == 0 )
    goto LABEL_4;
  if ( pButton->IsEditable(this: pButton) == 0 )
  {
LABEL_5:
    v3 = 1;
    goto LABEL_7;
  }
  if ( CMFCToolBar::m_bCustomizeMode == 0 )
  {
LABEL_4:
    if ( (pButton->m_nStyle & 0x40000) != 0 )
      goto LABEL_5;
  }
  v3 = 0;
LABEL_7:
  if ( CObject::IsKindOf(this: pButton, pClass: &CMFCOutlookBarPaneButton::classCMFCOutlookBarPaneButton) != 0 )
  {
    if ( afxGlobalData.m_bIsWhiteHighContrast != 0 || afxGlobalData.m_bIsBlackHighContrast != 0 )
    {
      result = afxGlobalData.clrGrayedText;
      if ( v3 == 0 )
        return afxGlobalData.clrWindowText;
    }
    else
    {
      result = afxGlobalData.clrBtnFace;
      if ( v3 == 0 )
        return afxGlobalData.clrWindow;
    }
  }
  else if ( v3 != 0 )
  {
    return afxGlobalData.clrGrayedText;
  }
  else if ( state == ButtonsIsHighlighted )
  {
    return CMFCToolBar::GetHotTextColor();
  }
  else
  {
    return afxGlobalData.clrBarText;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10374FD8
// Name: public: virtual void CMFCVisualManager::OnDrawOutlookPageButtonBorder(class CDC __near *,class CRect __near &,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawOutlookPageButtonBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect *rectBtn,
        int bIsHighlighted,
        int bIsPressed)
{
  if ( bIsHighlighted == 0 )
  {
    if ( bIsPressed == 0 )
    {
LABEL_6:
      CDC::Draw3dRect(
        this: pDC,
        lpRect: rectBtn,
        clrTopLeft: afxGlobalData.clrBarHilite,
        clrBottomRight: afxGlobalData.clrBarShadow);
      goto LABEL_7;
    }
LABEL_5:
    CDC::Draw3dRect(
      this: pDC,
      lpRect: rectBtn,
      clrTopLeft: afxGlobalData.clrBarFace,
      clrBottomRight: afxGlobalData.clrBarDkShadow);
    InflateRect(lprc: rectBtn, dx: -1, dy: -1);
    goto LABEL_6;
  }
  if ( bIsPressed == 0 )
    goto LABEL_5;
  CDC::Draw3dRect(
    this: pDC,
    lpRect: rectBtn,
    clrTopLeft: afxGlobalData.clrBarDkShadow,
    clrBottomRight: afxGlobalData.clrBarFace);
  InflateRect(lprc: rectBtn, dx: -1, dy: -1);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: rectBtn,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarHilite);
LABEL_7:
  InflateRect(lprc: rectBtn, dx: -1, dy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10375065
// Name: public: virtual unsigned long CMFCVisualManager::GetCaptionBarTextColor(class CMFCCaptionBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __thiscall CMFCVisualManager::GetCaptionBarTextColor(CMFCVisualManager *this, CMFCCaptionBar *pBar)
{
  if ( pBar->m_bIsMessageBarMode != 0 )
    return GetSysColor(nIndex: 23);
  else
    return afxGlobalData.clrWindow;
}

//------------------------------------------------------------------------------
// Address: 0x10375089
// Name: public: virtual void CMFCVisualManager::OnDrawCaptionBarButtonBorder(class CDC __near *,class CMFCCaptionBar __near *,class CRect,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawCaptionBarButtonBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCCaptionBar *pBar,
        CRect rect,
        int bIsPressed,
        int bIsHighlighted,
        int bIsDisabled,
        int bHasDropDownArrow,
        int bIsSysButton)
{
  if ( bIsPressed != 0 )
  {
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rect,
      clrTopLeft: afxGlobalData.clrBarDkShadow,
      clrBottomRight: afxGlobalData.clrBarHilite);
  }
  else if ( bIsHighlighted != 0 || pBar->m_bIsMessageBarMode != 0 )
  {
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rect,
      clrTopLeft: afxGlobalData.clrBarHilite,
      clrBottomRight: afxGlobalData.clrBarDkShadow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103750CF
// Name: public: virtual void CMFCVisualManager::OnDrawHeaderCtrlBorder(class CMFCHeaderCtrl __near *,class CDC __near *,class CRect __near &,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawHeaderCtrlBorder(
        CMFCVisualManager *this,
        CMFCHeaderCtrl *pCtrl,
        CDC *pDC,
        CRect *rect,
        int bIsPressed,
        int __formal)
{
  COLORREF clrBtnShadow; // eax

  if ( bIsPressed != 0 )
  {
    clrBtnShadow = afxGlobalData.clrBtnShadow;
    if ( pCtrl->m_bIsDlgControl == 0 )
      clrBtnShadow = afxGlobalData.clrBarShadow;
    CDC::Draw3dRect(this: pDC, lpRect: rect, clrTopLeft: clrBtnShadow, clrBottomRight: clrBtnShadow);
    ++rect->left;
    ++rect->top;
  }
  else if ( pCtrl->m_bIsDlgControl != 0 )
  {
    CDC::Draw3dRect(
      this: pDC,
      lpRect: rect,
      clrTopLeft: afxGlobalData.clrBtnHilite,
      clrBottomRight: afxGlobalData.clrBtnShadow);
  }
  else
  {
    CDC::Draw3dRect(
      this: pDC,
      lpRect: rect,
      clrTopLeft: afxGlobalData.clrBarHilite,
      clrBottomRight: afxGlobalData.clrBarShadow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10375138
// Name: public: virtual void CMFCVisualManager::OnDrawTasksGroupAreaBorder(class CDC __near *,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawTasksGroupAreaBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        int bSpecial,
        int bNoTitle)
{
  CFont *p_penHilite; // eax
  CFont *v6; // edi
  CPoint result; // [esp+0h] [ebp-8h] BYREF

  p_penHilite = (CFont *)&afxGlobalData.penHilite;
  if ( bSpecial == 0 )
    p_penHilite = (CFont *)&afxGlobalData.penBarFace;
  v6 = CDC::SelectObject(this: pDC, pFont: p_penHilite);
  CDC::MoveTo(this: pDC, &result, x: rect.left, y: rect.top);
  CDC::LineTo(this: pDC, x: rect.left, y: rect.bottom - 1);
  CDC::LineTo(this: pDC, x: rect.right - 1, y: rect.bottom - 1);
  CDC::LineTo(this: pDC, x: rect.right - 1, y: rect.top);
  if ( bNoTitle != 0 )
    CDC::LineTo(this: pDC, x: rect.left, y: rect.top);
  else
    CDC::LineTo(this: pDC, x: rect.right - 1, y: rect.top - 1);
  CDC::SelectObject(this: pDC, pFont: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103751CB
// Name: public: virtual void CMFCVisualManager::OnDrawToolBoxFrame(class CDC __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawToolBoxFrame(CMFCVisualManager *this, CDC *pDC, const CRect *rect)
{
  CDC::Draw3dRect(
    this: pDC,
    lpRect: rect,
    clrTopLeft: afxGlobalData.clrBarFace,
    clrBottomRight: afxGlobalData.clrBarFace);
}

//------------------------------------------------------------------------------
// Address: 0x103751E6
// Name: public: virtual void CMFCVisualManager::OnDrawPaneDivider(class CDC __near *,class CPaneDivider __near *,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawPaneDivider(
        CMFCVisualManager *this,
        CDC *pDC,
        CPaneDivider *pSlider,
        CRect rect,
        int bAutoHideMode)
{
  __int16 v5; // ax
  COLORREF clrBarDkShadow; // ecx
  CRect rectScreen; // [esp+14h] [ebp-24h] BYREF
  CRect rectBorder; // [esp+24h] [ebp-14h] BYREF

  rectScreen = afxGlobalData.m_rectVirtual;
  CWnd::ScreenToClient(this: pSlider, lpRect: (tagPOINT *)&rectScreen);
  rectBorder = rect;
  if ( rect.left >= rectScreen.left )
    rectBorder.left = rectScreen.left;
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, CPaneDivider *, int, int, int, int, int, int, int, int, _DWORD))this->OnFillBarBackground)(
    a1: this,
    a2: pDC,
    a3: pSlider,
    a4: rectBorder.left,
    a5: rectBorder.top,
    a6: rectBorder.right,
    a7: rectBorder.bottom,
    a8: rect.left,
    a9: rect.top,
    a10: rect.right,
    a11: rect.bottom,
    a12: 0);
  if ( bAutoHideMode != 0 )
  {
    v5 = pSlider->GetCurrentAlignment(this: pSlider);
    clrBarDkShadow = afxGlobalData.clrBarDkShadow;
    rectBorder = rect;
    if ( (v5 & 0x1000) != 0 )
    {
      rectBorder.left = rect.right;
LABEL_13:
      CDC::Draw3dRect(this: pDC, lpRect: &rectBorder, clrTopLeft: clrBarDkShadow, clrBottomRight: clrBarDkShadow);
      return;
    }
    if ( (v5 & 0x4000) != 0 )
    {
      rectBorder.right = rect.left;
    }
    else
    {
      if ( (v5 & 0x2000) != 0 )
      {
        rectBorder.top = rect.bottom;
        goto LABEL_13;
      }
      if ( (v5 & 0x8000) == 0 )
        return;
      rectBorder.bottom = rect.top;
    }
    clrBarDkShadow = afxGlobalData.clrBarHilite;
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103752D8
// Name: public: virtual void CMFCVisualManager::OnDrawSplitterBorder(class CDC __near *,class CSplitterWndEx __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawSplitterBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        struct CSplitterWndEx *__formal,
        CRect rect)
{
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarHilite);
  InflateRect(lprc: &rect, dx: -1, dy: -1);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarFace,
    clrBottomRight: afxGlobalData.clrBarFace);
}

//------------------------------------------------------------------------------
// Address: 0x1037531D
// Name: public: virtual void CMFCVisualManager::OnDrawSplitterBox(class CDC __near *,class CSplitterWndEx __near *,class CRect __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawSplitterBox(
        CMFCVisualManager *this,
        CDC *pDC,
        struct CSplitterWndEx *__formal,
        CRect *rect)
{
  CDC::Draw3dRect(
    this: pDC,
    lpRect: rect,
    clrTopLeft: afxGlobalData.clrBarFace,
    clrBottomRight: afxGlobalData.clrBarShadow);
}

//------------------------------------------------------------------------------
// Address: 0x1037533D
// Name: public: virtual void CMFCVisualManager::OnFillSplitterBackground(class CDC __near *,class CSplitterWndEx __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillSplitterBackground(
        CMFCVisualManager *this,
        CDC *pDC,
        struct CSplitterWndEx *__formal,
        CRect rect)
{
  CDC::FillSolidRect(this: pDC, lpRect: &rect, clr: afxGlobalData.clrBarFace);
}

//------------------------------------------------------------------------------
// Address: 0x10375358
// Name: public: virtual void CMFCVisualManager::OnDrawCheckBox(class CDC __near *,class CRect,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawCheckBox(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        int bHighlighted,
        int bChecked,
        int bEnabled)
{
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, bool, int, _DWORD, int))this->OnDrawCheckBoxEx)(
    a1: this,
    a2: pDC,
    a3: rect.left,
    a4: rect.top,
    a5: rect.right,
    a6: rect.bottom,
    a7: bChecked != 0,
    a8: bHighlighted,
    a9: 0,
    a10: bEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1037538D
// Name: public: virtual void CMFCVisualManager::OnDrawShowAllMenuItems(class CDC __near *,class CRect,enum CMFCVisualManager::AFX_BUTTON_STATE)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawShowAllMenuItems(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        CMFCVisualManager::AFX_BUTTON_STATE __formal)
{
  CSize sizeImageDest; // [esp+0h] [ebp-8h] BYREF

  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(pDC, id: IdArrowShowAll, rectImage: &rect, state: ImageBlack, &sizeImageDest);
}

//------------------------------------------------------------------------------
// Address: 0x103753B4
// Name: public: virtual int CMFCVisualManager::GetShowAllMenuItemsHeight(class CDC __near *,class CSize const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCVisualManager::GetShowAllMenuItemsHeight(CMFCVisualManager *this, CDC *__formal, const CSize *a3)
{
  CSize v4; // [esp+0h] [ebp-8h] BYREF

  return CMenuImages::Size(result: &v4)->cy + 6;
}

//------------------------------------------------------------------------------
// Address: 0x103753CE
// Name: public: virtual void CMFCVisualManager::GetTabFrameColors(class CMFCBaseTabCtrl const __near *,unsigned long __near &,unsigned long __near &,unsigned long __near &,unsigned long __near &,unsigned long __near &,unsigned long __near &,class CBrush __near * __near &,class CBrush __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::GetTabFrameColors(
        CMFCVisualManager *this,
        CMFCBaseTabCtrl *pTabWnd,
        unsigned int *clrDark,
        unsigned int *clrBlack,
        unsigned int *clrHighlight,
        unsigned int *clrFace,
        unsigned int *clrDarkShadow,
        unsigned int *clrLight,
        CBrush **pbrFace,
        CBrush **pbrBlack)
{
  CMFCBaseTabCtrl_vtbl *v10; // edi
  int v11; // eax
  unsigned int v12; // edi
  unsigned int clrBtnFace; // ecx
  bool v14; // zf
  unsigned int clrBtnShadow; // eax
  unsigned int clrBarShadow; // eax

  v10 = pTabWnd->__vftable;
  v11 = pTabWnd->GetActiveTab(this: pTabWnd);
  v12 = v10->GetTabBkColor(this: pTabWnd, a2: v11);
  if ( pTabWnd->IsOneNoteStyle(this: pTabWnd) == 0 || v12 == -1 )
  {
    clrBtnFace = afxGlobalData.clrBtnFace;
    if ( pTabWnd->m_bIsDlgControl == 0 )
      clrBtnFace = afxGlobalData.clrBarFace;
    *clrFace = clrBtnFace;
  }
  else
  {
    *clrFace = v12;
  }
  if ( pTabWnd->m_bIsDlgControl != 0 )
  {
    *clrDark = afxGlobalData.clrBtnShadow;
    *clrBlack = afxGlobalData.clrBtnText;
    v14 = pTabWnd->IsVS2005Style(this: pTabWnd) == 0;
    clrBtnShadow = afxGlobalData.clrBtnShadow;
    if ( v14 )
      clrBtnShadow = afxGlobalData.clrBtnHilite;
    *clrHighlight = clrBtnShadow;
    *clrDarkShadow = afxGlobalData.clrBtnDkShadow;
    *clrLight = afxGlobalData.clrBtnLight;
    *pbrFace = &afxGlobalData.brBtnFace;
  }
  else
  {
    *clrDark = afxGlobalData.clrBarShadow;
    *clrBlack = afxGlobalData.clrBarText;
    v14 = pTabWnd->IsVS2005Style(this: pTabWnd) == 0;
    clrBarShadow = afxGlobalData.clrBarShadow;
    if ( v14 )
      clrBarShadow = afxGlobalData.clrBarHilite;
    *clrHighlight = clrBarShadow;
    *clrDarkShadow = afxGlobalData.clrBarDkShadow;
    *clrLight = afxGlobalData.clrBarLight;
    *pbrFace = &afxGlobalData.brBarFace;
  }
  *pbrBlack = &afxGlobalData.brBlack;
}

//------------------------------------------------------------------------------
// Address: 0x103754DC
// Name: public: virtual void CMFCVisualManager::OnFillOutlookBarCaption(class CDC __near *,class CRect,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnFillOutlookBarCaption(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rectCaption,
        unsigned int *clrText)
{
  unsigned int *v4; // esi

  v4 = clrText;
  CDC::FillSolidRect(this: pDC, lpRect: &rectCaption, clr: afxGlobalData.clrBarShadow);
  *v4 = afxGlobalData.clrBarHilite;
}

//------------------------------------------------------------------------------
// Address: 0x10375503
// Name: public: virtual void CMFCVisualManager::GetSmartDockingBaseGuideColors(unsigned long __near &,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::GetSmartDockingBaseGuideColors(
        CMFCVisualManager *this,
        unsigned int *clrBaseGroupBackground,
        unsigned int *clrBaseGroupBorder)
{
  *clrBaseGroupBackground = afxGlobalData.clrBarFace;
  *clrBaseGroupBorder = afxGlobalData.clrBarShadow;
}

//------------------------------------------------------------------------------
// Address: 0x10375522
// Name: public: virtual unsigned long CMFCVisualManager::GetSmartDockingHighlightToneColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetSmartDockingHighlightToneColor(CMFCVisualManager *this)
{
  return afxGlobalData.clrActiveCaption;
}

//------------------------------------------------------------------------------
// Address: 0x10375528
// Name: public: virtual void CMFCVisualManager::OnDrawPopupWindowBorder(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawPopupWindowBorder(CMFCVisualManager *this, CDC *pDC, CRect rect)
{
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarLight,
    clrBottomRight: afxGlobalData.clrBarDkShadow);
  InflateRect(lprc: &rect, dx: -1, dy: -1);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarHilite,
    clrBottomRight: afxGlobalData.clrBarShadow);
}

//------------------------------------------------------------------------------
// Address: 0x10375572
// Name: public: virtual void CMFCVisualManager::OnDrawPopupWindowButtonBorder(class CDC __near *,class CRect,class CMFCDesktopAlertWndButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawPopupWindowButtonBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CRect rect,
        CMFCDesktopAlertWndButton *pButton)
{
  if ( CMFCButton::IsPressed(this: pButton) )
  {
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rect,
      clrTopLeft: afxGlobalData.clrBarDkShadow,
      clrBottomRight: afxGlobalData.clrBarLight);
    InflateRect(lprc: &rect, dx: -1, dy: -1);
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rect,
      clrTopLeft: afxGlobalData.clrBarShadow,
      clrBottomRight: afxGlobalData.clrBarHilite);
  }
  else
  {
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rect,
      clrTopLeft: afxGlobalData.clrBarLight,
      clrBottomRight: afxGlobalData.clrBarDkShadow);
    InflateRect(lprc: &rect, dx: -1, dy: -1);
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rect,
      clrTopLeft: afxGlobalData.clrBarHilite,
      clrBottomRight: afxGlobalData.clrBarShadow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103755F6
// Name: public: virtual unsigned long CMFCVisualManager::GetPropertyGridGroupColor(class CMFCPropertyGridCtrl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetPropertyGridGroupColor(
        CMFCVisualManager *this,
        CMFCPropertyGridCtrl *pPropList)
{
  unsigned int result; // eax

  result = afxGlobalData.clrBarFace;
  if ( pPropList->m_bControlBarColors == 0 )
    return afxGlobalData.clrBtnFace;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10375615
// Name: public: virtual unsigned long CMFCVisualManager::GetPropertyGridGroupTextColor(class CMFCPropertyGridCtrl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetPropertyGridGroupTextColor(
        CMFCVisualManager *this,
        CMFCPropertyGridCtrl *pPropList)
{
  unsigned int result; // eax

  result = afxGlobalData.clrBarDkShadow;
  if ( pPropList->m_bControlBarColors == 0 )
    return afxGlobalData.clrBtnDkShadow;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10375634
// Name: public: virtual unsigned long CMFCVisualManager::GetMenuItemTextColor(class CMFCToolBarMenuButton __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetMenuItemTextColor(
        CMFCVisualManager *this,
        CMFCToolBarMenuButton *__formal,
        int bHighlighted,
        int bDisabled)
{
  unsigned int result; // eax

  if ( bHighlighted != 0 )
  {
    result = afxGlobalData.clrBtnFace;
    if ( bDisabled == 0 )
      return afxGlobalData.clrTextHilite;
  }
  else
  {
    result = afxGlobalData.clrGrayedText;
    if ( bDisabled == 0 )
      return afxGlobalData.clrWindowText;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10375664
// Name: public: virtual unsigned long CMFCVisualManager::GetStatusBarPaneTextColor(class CMFCStatusBar __near *,class CMFCStatusBarPaneInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetStatusBarPaneTextColor(
        CMFCVisualManager *this,
        CMFCStatusBar *__formal,
        CMFCStatusBarPaneInfo *pPane)
{
  unsigned int result; // eax

  if ( pPane == nullptr )
    AfxThrowInvalidArgException();
  if ( (pPane->nStyle & 0x4000000) != 0 )
    return afxGlobalData.clrGrayedText;
  result = pPane->clrText;
  if ( result == -1 )
    return afxGlobalData.clrBtnText;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10375696
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonCaptionButton(class CDC __near *,class CMFCRibbonCaptionButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CMFCVisualManager::OnDrawRibbonCaptionButton(
        CMFCVisualManager *this@<ecx>,
        const CSize *a2@<edi>,
        CDC *pDC,
        CMFCRibbonCaptionButton *pButton)
{
  CMFCVisualManager_vtbl *v4; // edx
  CMFCRibbonCaptionButton_vtbl *v5; // eax
  int v6; // eax
  _DWORD v7[2]; // [esp+4h] [ebp-28h] BYREF
  CMFCVisualManager *v8; // [esp+Ch] [ebp-20h]
  CDC *v9; // [esp+10h] [ebp-1Ch]
  CMenuImages::IMAGES_IDS imageID; // [esp+14h] [ebp-18h]
  CRect rectImage; // [esp+18h] [ebp-14h] BYREF

  v4 = this->__vftable;
  v8 = this;
  v9 = pDC;
  ((void (__stdcall *)(CDC *, CMFCRibbonCaptionButton *))v4->OnFillRibbonButton)(a1: pDC, a2: pButton);
  switch ( pButton->m_nID )
  {
    case 0xF020u:
      imageID = IdMinimize;
      break;
    case 0xF030u:
      imageID = IdMaximize;
      break;
    case 0xF060u:
      imageID = IdClose;
      break;
    case 0xF120u:
      imageID = IdRestore;
      break;
    default:
      return;
  }
  v7[0] = 0;
  v7[1] = 0;
  rectImage.left = pButton->m_rect.left;
  rectImage.top = pButton->m_rect.top;
  rectImage.right = pButton->m_rect.right;
  v5 = pButton->__vftable;
  rectImage.bottom = pButton->m_rect.bottom;
  v6 = ((int (__thiscall *)(CMFCRibbonCaptionButton *, _DWORD *))v5->IsDisabled)(a1: pButton, a2: v7);
  CMenuImages::Draw(pDC: v9, id: imageID, &rectImage, state: (CMenuImages::IMAGE_STATE)(v6 != 0), sizeImageDest: a2);
  ((void (__thiscall *)(CMFCVisualManager *, CDC *))v8->OnDrawRibbonButtonBorder)(a1: v8, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10375751
// Name: public: virtual unsigned long CMFCVisualManager::OnDrawRibbonButtonsGroup(class CDC __near *,class CMFCRibbonButtonsGroup __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::OnDrawRibbonButtonsGroup(
        CMFCVisualManager *this,
        CDC *__formal,
        CDC *__formala,
        CRect a4)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10375757
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonApplicationButton(class CDC __near *,class CMFCRibbonButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonApplicationButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonButton *pButton)
{
  unsigned int clrBarDkShadow; // ecx
  unsigned int clrBarLight; // eax
  CDrawingManager v5; // [esp+10h] [ebp-30h] BYREF
  BOOL v6; // [esp+18h] [ebp-28h]
  BOOL v7; // [esp+1Ch] [ebp-24h]
  tagRECT rc; // [esp+20h] [ebp-20h] BYREF
  int v9; // [esp+3Ch] [ebp-4h]

  v6 = pButton->IsHighlighted(this: pButton) != 0 || pButton->IsFocused(this: pButton) != 0;
  v7 = pButton->IsPressed(this: pButton) != 0 || pButton->IsDroppedDown(this: pButton) != 0;
  rc = (tagRECT)pButton->m_rect;
  InflateRect(lprc: &rc, dx: -2, dy: -2);
  CDrawingManager::CDrawingManager(this: &v5, m_dc: pDC);
  clrBarDkShadow = afxGlobalData.clrBarDkShadow;
  v9 = 0;
  if ( !v6 )
    clrBarDkShadow = afxGlobalData.clrBarShadow;
  clrBarLight = afxGlobalData.clrBarLight;
  if ( !v7 )
    clrBarLight = afxGlobalData.clrBarFace;
  CDrawingManager::DrawEllipse(this: &v5, rect: (const CRect *)&rc, clrFill: clrBarLight, clrLine: clrBarDkShadow);
  v9 = -1;
  CDrawingManager::~CDrawingManager(this: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x10375810
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonDefaultPaneButton(class CDC __near *,class CMFCRibbonButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonDefaultPaneButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonButton *pButton)
{
  CMFCVisualManager_vtbl *v4; // eax

  v4 = this->__vftable;
  if ( pButton->m_bQuickAccessMode != 0 )
  {
    ((void (__stdcall *)(CDC *, CMFCRibbonButton *))v4->OnFillRibbonButton)(a1: pDC, a2: pButton);
    this->OnDrawRibbonDefaultPaneButtonContext(this, a2: pDC, a3: pButton);
    this->OnDrawRibbonButtonBorder(this, a2: pDC, a3: pButton);
  }
  else
  {
    ((void (__stdcall *)(CDC *, CMFCRibbonButton *))v4->OnDrawRibbonDefaultPaneButtonContext)(a1: pDC, a2: pButton);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10375858
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonDefaultPaneButtonContext(class CDC __near *,class CMFCRibbonButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonDefaultPaneButtonContext(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonButton *pButton)
{
  CMFCRibbonButton_vtbl *v3; // eax
  CRect *p_m_rect; // esi
  int rectImage; // [esp+Ch] [ebp-18h]
  int rectImage_4; // [esp+10h] [ebp-14h]
  int rectImage_8; // [esp+14h] [ebp-10h]
  int rectImage_12; // [esp+18h] [ebp-Ch]
  CSize result; // [esp+1Ch] [ebp-8h] BYREF

  v3 = pButton->__vftable;
  p_m_rect = &pButton->m_rect;
  if ( pButton->m_bQuickAccessMode != 0 )
  {
    ((void (__thiscall *)(CMFCRibbonButton *, CDC *, int, int, int, int, int))v3->DrawImage)(
      a1: pButton,
      a2: pDC,
      a3: 1,
      a4: p_m_rect->left,
      a5: pButton->m_rect.top,
      a6: pButton->m_rect.right,
      a7: pButton->m_rect.bottom);
  }
  else
  {
    rectImage = p_m_rect->left;
    rectImage_8 = pButton->m_rect.right;
    rectImage_4 = pButton->m_rect.top + 10;
    rectImage_12 = rectImage_4 + v3->GetImageSize(this: pButton, &result, a3: RibbonImageSmall)->cy;
    ((void (__thiscall *)(CMFCRibbonButton *, CDC *, int, int, int, int, int))pButton->DrawImage)(
      a1: pButton,
      a2: pDC,
      a3: 1,
      a4: rectImage,
      a5: rectImage_4,
      a6: rectImage_8,
      a7: rectImage_12);
    CMFCRibbonButton::DrawBottomText(this: pButton, &result, pDC, bCalcOnly: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103758D4
// Name: public: virtual unsigned long CMFCVisualManager::OnFillRibbonMainPanelButton(class CDC __near *,class CMFCRibbonButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::OnFillRibbonMainPanelButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonButton *pButton)
{
  return this->OnFillRibbonButton(this, a2: pDC, a3: pButton);
}

//------------------------------------------------------------------------------
// Address: 0x103758E2
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonMainPanelButtonBorder(class CDC __near *,class CMFCRibbonButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonMainPanelButtonBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonButton *pButton)
{
  this->OnDrawRibbonButtonBorder(this, a2: pDC, a3: pButton);
}

//------------------------------------------------------------------------------
// Address: 0x103758F0
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonButtonBorder(class CDC __near *,class CMFCRibbonButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonButtonBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonButton *pButton)
{
  CDC *m_dc; // esi
  CPoint result; // [esp+10h] [ebp-48h] BYREF
  CDrawingManager v5; // [esp+18h] [ebp-40h] BYREF
  CDrawingManager v6; // [esp+20h] [ebp-38h] BYREF
  CRect rect; // [esp+28h] [ebp-30h] BYREF
  RECT rc; // [esp+38h] [ebp-20h] BYREF
  int v9; // [esp+54h] [ebp-4h]

  v6.m_dc = pDC;
  if ( CObject::IsKindOf(this: pButton, pClass: &CMFCRibbonEdit::classCMFCRibbonEdit) == 0 )
  {
    rect = pButton->m_rect;
    if ( (CMFCRibbonBaseElement::IsMenuMode(this: pButton) == 0
       || pButton->IsChecked(this: pButton) == 0
       || pButton->IsHighlighted(this: pButton) != 0)
      && (pButton->IsHighlighted(this: pButton) != 0
       || pButton->IsChecked(this: pButton) != 0
       || pButton->IsDroppedDown(this: pButton) != 0
       || pButton->IsFocused(this: pButton) != 0) )
    {
      if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
      {
        CDrawingManager::CDrawingManager(this: &v5, m_dc: v6.m_dc);
        v9 = 0;
        CDrawingManager::DrawRect(this: &v5, (int)&rect, clrFill: 0xFFFFFFFF, clrLine: afxGlobalData.clrBarShadow);
        v9 = -1;
        CDrawingManager::~CDrawingManager(this: &v5);
      }
      else if ( pButton->IsPressed(this: pButton) != 0
             || pButton->IsChecked(this: pButton) != 0
             || pButton->IsDroppedDown(this: pButton) != 0 )
      {
        CDC::Draw3dRect(
          this: v6.m_dc,
          lpRect: &rect,
          clrTopLeft: afxGlobalData.clrBarShadow,
          clrBottomRight: afxGlobalData.clrBarHilite);
      }
      else
      {
        CDC::Draw3dRect(
          this: v6.m_dc,
          lpRect: &rect,
          clrTopLeft: afxGlobalData.clrBarHilite,
          clrBottomRight: afxGlobalData.clrBarShadow);
      }
      rc = (RECT)pButton->m_rectMenu;
      if ( !IsRectEmpty(lprc: &rc) )
      {
        if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
        {
          CDrawingManager::CDrawingManager(this: &v6, m_dc: v6.m_dc);
          v9 = 1;
          if ( pButton->m_bMenuOnBottom != 0 )
            CDrawingManager::DrawLine(
              this: &v6,
              x1: rc.left,
              y1: rc.top,
              x2: rc.right,
              y2: rc.top,
              clrLine: afxGlobalData.clrBarShadow);
          else
            CDrawingManager::DrawLine(
              this: &v6,
              x1: rc.left,
              y1: rc.top,
              x2: rc.left,
              y2: rc.bottom,
              clrLine: afxGlobalData.clrBarShadow);
          v9 = -1;
          CDrawingManager::~CDrawingManager(this: &v6);
        }
        else
        {
          m_dc = v6.m_dc;
          v6.m_dc = (CDC *)CDC::SelectObject(this: v6.m_dc, pFont: (CFont *)&afxGlobalData.penBarShadow);
          if ( v6.m_dc == nullptr )
            AfxThrowInvalidArgException();
          if ( pButton->m_bMenuOnBottom != 0 )
          {
            CDC::MoveTo(this: m_dc, result: (CPoint *)&v5, x: rc.left, y: rc.top);
            CDC::LineTo(this: m_dc, x: rc.right, y: rc.top);
          }
          else
          {
            CDC::MoveTo(this: m_dc, &result, x: rc.left, y: rc.top);
            CDC::LineTo(this: m_dc, x: rc.left, y: rc.bottom);
          }
          CDC::SelectObject(this: m_dc, pFont: (CFont *)v6.m_dc);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10375AD0
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonMainPanelFrame(class CDC __near *,class CMFCRibbonMainPanel __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonMainPanelFrame(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonMainPanel *__formal,
        CRect rect)
{
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarShadow);
  InflateRect(lprc: &rect, dx: 1, dy: 1);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rect,
    clrTopLeft: afxGlobalData.clrBarHilite,
    clrBottomRight: afxGlobalData.clrBarHilite);
}

//------------------------------------------------------------------------------
// Address: 0x10375B10
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonLabel(class CDC __near *,class CMFCRibbonLabel __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonLabel(
        CMFCRibbonBaseElement *this,
        CDC *__formal,
        CMFCRibbonBaseElement::RibbonImageType __formala,
        CRect a4)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10375B13
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonGalleryButton(class CDC __near *,class CMFCRibbonGalleryIcon __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonGalleryButton(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonGalleryIcon *pButton)
{
  this->OnFillRibbonButton(this, a2: pDC, a3: pButton);
  this->OnDrawRibbonButtonBorder(this, a2: pDC, a3: pButton);
}

//------------------------------------------------------------------------------
// Address: 0x10375B3E
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonGalleryBorder(class CDC __near *,class CMFCRibbonGallery __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonGalleryBorder(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonGallery *__formal,
        CRect rectBorder)
{
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectBorder,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarShadow);
}

//------------------------------------------------------------------------------
// Address: 0x10375B5A
// Name: public: virtual unsigned long CMFCVisualManager::RibbonCategoryColorToRGB(enum AFX_RibbonCategoryColor)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::RibbonCategoryColorToRGB(
        CMFCVisualManager *this,
        AFX_RibbonCategoryColor color)
{
  if ( afxGlobalData.m_nBitsPerPixel > 8
    && afxGlobalData.m_bIsWhiteHighContrast == 0
    && afxGlobalData.m_bIsBlackHighContrast == 0 )
  {
    switch ( color )
    {
      case AFX_CategoryColor_Red:
        return 10526975;
      case AFX_CategoryColor_Orange:
        return 3653103;
      case AFX_CategoryColor_Yellow:
        return 1828349;
      case AFX_CategoryColor_Green:
        return 5881457;
      case AFX_CategoryColor_Blue:
        return 12891520;
      case AFX_CategoryColor_Indigo:
        return 14721906;
      case AFX_CategoryColor_Violet:
        return 13742806;
      default:
        break;
    }
    return -1;
  }
  switch ( color )
  {
    case AFX_CategoryColor_Red:
      return 255;
    case AFX_CategoryColor_Orange:
      return 33023;
    case AFX_CategoryColor_Yellow:
      return 0xFFFF;
    case AFX_CategoryColor_Green:
      return 65280;
    case AFX_CategoryColor_Blue:
      return 16711680;
    case AFX_CategoryColor_Indigo:
      return 0x800000;
    default:
      break;
  }
  if ( color != AFX_CategoryColor_Violet )
    return -1;
  return 16711935;
}

//------------------------------------------------------------------------------
// Address: 0x10375C13
// Name: public: virtual unsigned long CMFCVisualManager::OnDrawRibbonStatusBarPane(class CDC __near *,class CMFCRibbonStatusBar __near *,class CMFCRibbonStatusBarPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::OnDrawRibbonStatusBarPane(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonStatusBar *__formal,
        CMFCRibbonStatusBarPane *pPane)
{
  int v4; // eax
  COLORREF clrBarHilite; // esi
  bool v6; // zf
  COLORREF clrBarShadow; // eax
  CRect rectButton; // [esp+20h] [ebp-14h] BYREF
  CRect rect; // 0:^18.16

  rect = pPane->m_rect;
  if ( pPane->IsHighlighted(this: pPane) != 0 )
  {
    rectButton = rect;
    InflateRect(lprc: &rectButton, dx: -1, dy: -1);
    v4 = pPane->IsPressed(this: pPane);
    clrBarHilite = afxGlobalData.clrBarHilite;
    if ( v4 == 0 )
      clrBarHilite = afxGlobalData.clrBarShadow;
    v6 = pPane->IsPressed(this: pPane) == 0;
    clrBarShadow = afxGlobalData.clrBarShadow;
    if ( v6 )
      clrBarShadow = afxGlobalData.clrBarHilite;
    CDC::Draw3dRect(this: pDC, lpRect: &rectButton, clrTopLeft: clrBarShadow, clrBottomRight: clrBarHilite);
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10375CAC
// Name: public: virtual void CMFCVisualManager::GetRibbonSliderColors(class CMFCRibbonSlider __near *,int,int,int,unsigned long __near &,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::GetRibbonSliderColors(
        CMFCVisualManager *this,
        CMFCRibbonSlider *__formal,
        int bIsHighlighted,
        int bIsPressed,
        int bIsDisabled,
        unsigned int *clrLine,
        unsigned int *clrFill)
{
  unsigned int clrBarShadow; // eax
  unsigned int clrBarHilite; // eax

  clrBarShadow = afxGlobalData.clrBarShadow;
  if ( bIsDisabled == 0 )
    clrBarShadow = afxGlobalData.clrBarDkShadow;
  *clrLine = clrBarShadow;
  if ( bIsPressed == 0 )
  {
    clrBarHilite = afxGlobalData.clrBarHilite;
    if ( bIsHighlighted != 0 )
      goto LABEL_8;
LABEL_7:
    clrBarHilite = afxGlobalData.clrBarFace;
    goto LABEL_8;
  }
  if ( bIsHighlighted == 0 )
    goto LABEL_7;
  clrBarHilite = afxGlobalData.clrBarShadow;
LABEL_8:
  *clrFill = clrBarHilite;
}

//------------------------------------------------------------------------------
// Address: 0x10375CF0
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonSliderChannel(class CDC __near *,class CMFCRibbonSlider __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonSliderChannel(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonSlider *__formal,
        CRect rect)
{
  CDrawingManager dm; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  InflateRect(lprc: &rect, dx: 0, dy: 1);
  if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
  {
    CDrawingManager::CDrawingManager(this: &dm, m_dc: pDC);
    v5 = 0;
    CDrawingManager::DrawRect(this: &dm, (int)&rect, clrFill: 0xFFFFFFFF, clrLine: afxGlobalData.clrBarShadow);
    v5 = -1;
    CDrawingManager::~CDrawingManager(this: &dm);
  }
  else
  {
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rect,
      clrTopLeft: afxGlobalData.clrBarShadow,
      clrBottomRight: afxGlobalData.clrBarHilite);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10375D64
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonQuickAccessToolBarSeparator(class CDC __near *,class CMFCRibbonSeparator __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonQuickAccessToolBarSeparator(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonSeparator *__formal,
        CRect rect)
{
  CDrawingManager dm; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
  {
    CDrawingManager::CDrawingManager(this: &dm, m_dc: pDC);
    v5 = 0;
    CDrawingManager::DrawRect(this: &dm, (int)&rect, clrFill: 0xFFFFFFFF, clrLine: afxGlobalData.clrBtnShadow);
    v5 = -1;
    CDrawingManager::~CDrawingManager(this: &dm);
  }
  else
  {
    CDC::Draw3dRect(
      this: pDC,
      lpRect: &rect,
      clrTopLeft: afxGlobalData.clrBarShadow,
      clrBottomRight: afxGlobalData.clrBarHilite);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10375DC8
// Name: public: virtual void CMFCVisualManager::OnDrawRibbonCheckBoxOnList(class CDC __near *,class CMFCRibbonCheckBox __near *,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCVisualManager::OnDrawRibbonCheckBoxOnList(
        CMFCVisualManager *this,
        CDC *pDC,
        CMFCRibbonCheckBox *__formal,
        CRect rect,
        int a5,
        int a6)
{
  CSize sizeImageDest; // [esp+Ch] [ebp-8h] BYREF

  OffsetRect(lprc: &rect, dx: 1, dy: 1);
  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(pDC, id: IdCheck, rectImage: &rect, state: ImageWhite, &sizeImageDest);
  OffsetRect(lprc: &rect, dx: -1, dy: -1);
  sizeImageDest.cx = 0;
  sizeImageDest.cy = 0;
  CMenuImages::Draw(pDC, id: IdCheck, rectImage: &rect, state: ImageBlack, &sizeImageDest);
}

//------------------------------------------------------------------------------
// Address: 0x10375E27
// Name: public: virtual unsigned long CMFCVisualManager::GetRibbonHyperlinkTextColor(class CMFCRibbonLinkCtrl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetRibbonHyperlinkTextColor(
        CMFCVisualManager *this,
        CMFCRibbonLinkCtrl *pHyperLink)
{
  unsigned int result; // eax
  bool v4; // zf

  if ( pHyperLink->IsDisabled(this: pHyperLink) != 0 )
    return this->GetToolbarDisabledTextColor(this);
  v4 = pHyperLink->IsHighlighted(this: pHyperLink) == 0;
  result = afxGlobalData.clrHotLinkHoveredText;
  if ( v4 )
    return afxGlobalData.clrHotLinkNormalText;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10375E65
// Name: public: virtual unsigned long CMFCVisualManager::GetAutoHideButtonTextColor(class CMFCAutoHideButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetAutoHideButtonTextColor(
        CMFCVisualManager *this,
        CMFCRibbonStatusBar *__formal)
{
  return afxGlobalData.clrBarText;
}

//------------------------------------------------------------------------------
// Address: 0x10375E6D
// Name: public: virtual unsigned long CMFCVisualManager::GetRibbonEditBackgroundColor(class CMFCRibbonRichEditCtrl __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCVisualManager::GetRibbonEditBackgroundColor(
        CMFCVisualManager *this,
        CMFCRibbonRichEditCtrl *__formal,
        int bIsHighlighted,
        int a4,
        int bIsDisabled)
{
  unsigned int result; // eax

  if ( bIsHighlighted == 0 )
    return afxGlobalData.clrBarFace;
  result = afxGlobalData.clrWindow;
  if ( bIsDisabled != 0 )
    return afxGlobalData.clrBarFace;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10375E8C
// Name: public: virtual void CBasePane::OnBeforeChangeParent(class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBasePane::OnBeforeChangeParent(CMFCCaptionBar *this, CFrameWnd *__formal, CFrameWnd *__formala)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10375E8F
// Name: protected: long CMDIFrameWndEx::OnPostPreviewFrame(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnPostPreviewFrame(CMFCAutoHideBar *this, CPoint __formal)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10375E94
// Name: public: virtual int CMFCVisualManager::GetToolTipInfo(class CMFCToolTipInfo __near &,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCVisualManager::GetToolTipInfo(
        CMFCVisualManager *this,
        CMFCToolTipInfo *params,
        unsigned int __formal)
{
  CMFCToolTipInfo dummy; // [esp+0h] [ebp-34h] BYREF

  CMFCToolTipInfo::CMFCToolTipInfo(this: &dummy);
  CMFCToolTipInfo::operator=(this: params, src: &dummy);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10375EB7
// Name: protected: void CMFCBaseVisualManager::CleanUpThemes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCBaseVisualManager::CleanUpThemes(CMFCBaseVisualManager *this)
{
  HRESULT (__stdcall *m_pfCloseThemeData)(void *); // ecx

  m_pfCloseThemeData = this->m_pfCloseThemeData;
  if ( m_pfCloseThemeData != nullptr )
  {
    if ( this->m_hThemeWindow != nullptr )
      m_pfCloseThemeData(a1: this->m_hThemeWindow);
    if ( this->m_hThemeToolBar != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeToolBar);
    if ( this->m_hThemeRebar != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeRebar);
    if ( this->m_hThemeStatusBar != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeStatusBar);
    if ( this->m_hThemeButton != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeButton);
    if ( this->m_hThemeComboBox != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeComboBox);
    if ( this->m_hThemeProgress != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeProgress);
    if ( this->m_hThemeHeader != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeHeader);
    if ( this->m_hThemeScrollBar != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeScrollBar);
    if ( this->m_hThemeExplorerBar != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeExplorerBar);
    if ( this->m_hThemeTree != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeTree);
    if ( this->m_hThemeStartPanel != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeStartPanel);
    if ( this->m_hThemeTaskBand != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeTaskBand);
    if ( this->m_hThemeTaskBar != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeTaskBar);
    if ( this->m_hThemeSpin != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeSpin);
    if ( this->m_hThemeTab != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeTab);
    if ( this->m_hThemeTrack != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeTrack);
    if ( this->m_hThemeMenu != nullptr )
      this->m_pfCloseThemeData(a1: this->m_hThemeMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10375F8E
// Name: public: virtual int CMFCBaseVisualManager::DrawComboBorder(class CDC __near *,class CRect,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCBaseVisualManager::DrawComboBorder(
        CMFCBaseVisualManager *this,
        CDC *pDC,
        CRect rect,
        int __formal,
        int bIsDropped,
        int bIsHighlighted)
{
  int result; // eax

  result = 0;
  if ( this->m_hThemeWindow != nullptr )
  {
    if ( bIsHighlighted != 0 || bIsDropped != 0 )
    {
      InflateRect(lprc: &rect, dx: -1, dy: -1);
      CDC::Draw3dRect(
        this: pDC,
        lpRect: &rect,
        clrTopLeft: afxGlobalData.clrHilite,
        clrBottomRight: afxGlobalData.clrHilite);
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400E28
// Name: protected: virtual unsigned char __near * CMemFile::Realloc(unsigned char __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CMemFile::Realloc(CMemFile *this, unsigned __int8 *lpMem, unsigned int nBytes)
{
  return (unsigned __int8 *)_realloc_crt(ptr: lpMem, size: nBytes);
}

//------------------------------------------------------------------------------
// Address: 0x10400E50
// Name: public: virtual unsigned __int64 CMemFile::GetPosition(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMemFile::GetPosition(CMemFile *this)
{
  return this->m_nPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10400E56
// Name: protected: virtual void CMemFile::GrowFile(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMemFile::GrowFile(CMemFile *this, unsigned int dwNewLen)
{
  unsigned int m_nBufferSize; // edi
  unsigned int m_nGrowBytes; // eax
  unsigned __int8 *m_lpBuffer; // eax
  unsigned __int8 *v6; // eax

  m_nBufferSize = this->m_nBufferSize;
  if ( dwNewLen > m_nBufferSize )
  {
    m_nGrowBytes = this->m_nGrowBytes;
    if ( m_nGrowBytes == 0 )
      goto LABEL_3;
    while ( m_nBufferSize < dwNewLen )
      m_nBufferSize += m_nGrowBytes;
    m_lpBuffer = this->m_lpBuffer;
    v6 = m_lpBuffer != nullptr
       ? this->Realloc(this, a2: m_lpBuffer, a3: m_nBufferSize)
       : this->Alloc(this, a2: m_nBufferSize);
    if ( v6 == nullptr )
LABEL_3:
      AfxThrowMemoryException();
    this->m_lpBuffer = v6;
    this->m_nBufferSize = m_nBufferSize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10400E9F
// Name: public: virtual unsigned __int64 CMemFile::GetLength(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMemFile::GetLength(CMemFile *this)
{
  return this->m_nFileSize;
}

//------------------------------------------------------------------------------
// Address: 0x10400EA5
// Name: public: virtual void CMemFile::SetLength(unsigned __int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMemFile::SetLength(CMemFile *this, unsigned __int64 dwNewLen)
{
  if ( HIDWORD(dwNewLen) != 0 )
    AfxThrowMemoryException();
  if ( (unsigned int)dwNewLen > this->m_nBufferSize )
    this->GrowFile(this, a2: dwNewLen);
  if ( (unsigned int)dwNewLen < this->m_nPosition )
    this->m_nPosition = dwNewLen;
  this->m_nFileSize = dwNewLen;
}

//------------------------------------------------------------------------------
// Address: 0x10400EF5
// Name: public: virtual unsigned int CMemFile::Read(void __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMemFile::Read(CMemFile *this, unsigned __int8 *lpBuf, unsigned int nCount)
{
  unsigned int v3; // edi
  unsigned int m_nPosition; // ecx
  unsigned int m_nFileSize; // eax

  v3 = nCount;
  if ( nCount == 0 )
    return 0;
  if ( lpBuf == nullptr )
    AfxThrowInvalidArgException();
  m_nPosition = this->m_nPosition;
  m_nFileSize = this->m_nFileSize;
  if ( m_nPosition > m_nFileSize )
    return 0;
  if ( m_nPosition + nCount > m_nFileSize || m_nPosition + nCount < m_nPosition )
    v3 = m_nFileSize - m_nPosition;
  this->Memcpy(this, a2: lpBuf, a3: &this->m_lpBuffer[m_nPosition], a4: v3);
  this->m_nPosition += v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1041E873
// Name: protected: virtual unsigned char __near * CSharedFile::Realloc(unsigned char __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CSharedFile::Realloc(CSharedFile *this, unsigned __int8 *__formal, SIZE_T nBytes)
{
  HGLOBAL v5; // eax

  if ( this->m_bAllowGrow == 0 )
    return nullptr;
  GlobalUnlock(hMem: this->m_hGlobalMemory);
  v5 = GlobalReAlloc(hMem: this->m_hGlobalMemory, dwBytes: nBytes, uFlags: this->m_nAllocFlags);
  if ( v5 == nullptr )
    return nullptr;
  this->m_hGlobalMemory = v5;
  return (unsigned __int8 *)GlobalLock(hMem: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1041E8CB
// Name: public: void __near * CSharedFile::Detach(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__thiscall CSharedFile::Detach(CSharedFile *this)
{
  void *m_hGlobalMemory; // edi

  m_hGlobalMemory = this->m_hGlobalMemory;
  GlobalUnlock(hMem: m_hGlobalMemory);
  this->m_hGlobalMemory = nullptr;
  this->m_lpBuffer = nullptr;
  this->m_nBufferSize = 0;
  return m_hGlobalMemory;
}

//------------------------------------------------------------------------------
// Address: 0x1041E8EB
// Name: public: virtual struct CRuntimeClass __near * CSharedFile::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSharedFile::GetRuntimeClass(CSharedFile *this)
{
  return &CSharedFile::classCSharedFile;
}

//------------------------------------------------------------------------------
// Address: 0x1041E912
// Name: public: virtual int CSyncObject::Lock(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CSyncObject::Lock(CSyncObject *this, DWORD dwTimeout)
{
  DWORD v2; // eax

  v2 = WaitForSingleObject(hHandle: this->m_hObject, dwMilliseconds: dwTimeout);
  return v2 == 0 || v2 == 128;
}

//------------------------------------------------------------------------------
// Address: 0x1041E939
// Name: public: virtual struct CRuntimeClass __near * CCriticalSection::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CCriticalSection::GetRuntimeClass(CCriticalSection *this)
{
  return &CCriticalSection::classCCriticalSection;
}

//------------------------------------------------------------------------------
// Address: 0x1041E93F
// Name: public: virtual struct CRuntimeClass __near * CSyncObject::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSyncObject::GetRuntimeClass(CSyncObject *this)
{
  return &CSyncObject::classCSyncObject;
}

//------------------------------------------------------------------------------
// Address: 0x1041E945
// Name: public: CSyncObject::CSyncObject(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSyncObject *__thiscall CSyncObject::CSyncObject(CSyncObject *this, const char *pstrName)
{
  this->m_hObject = nullptr;
  this->__vftable = (CSyncObject_vtbl *)&CSyncObject::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041E954
// Name: public: virtual CSyncObject::~CSyncObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSyncObject::~CSyncObject(CSyncObject *this)
{
  void *m_hObject; // eax

  m_hObject = this->m_hObject;
  this->__vftable = (CSyncObject_vtbl *)&CSyncObject::`vftable';
  if ( m_hObject != nullptr )
  {
    CloseHandle(hObject: m_hObject);
    this->m_hObject = nullptr;
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00578660
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005786A0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005786C0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x005786F0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00578780
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005787D0
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00578850
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x005316F0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00531730
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00531750
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00531780
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00531810
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00531860
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005318E0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C5D20
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005C5D60
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C5D80
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x005C5DB0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x005C5E40
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C5E90
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005C5F10
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace mdlcompile

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100FC000
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100FC040
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FC070
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x100FC100
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FC150
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FC1D0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace missionchooser

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00496AC0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00496B00
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496B20
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00496B50
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00496BE0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00496C30
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00496CB0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace mksheet

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004B4DD0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B4E10
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B4E40
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x004B4ED0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B4F20
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B4FA0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace modelbrowser

// ============================================================
// Overlay from networksystem (Missing functions)
// ============================================================
namespace networksystem {

//------------------------------------------------------------------------------
// Address: 0x1001ACF0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001AD30
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AD50
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001AD80
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edx
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  this->m_pHeadOfFreeList = v8;
  if ( v4 - 1 > 0 )
  {
    v9 = v4 - 1;
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x1001AE20
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001AE70
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = ".\\mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

} // namespace networksystem

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00538450
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00538490
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005384B0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x005384E0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00538570
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005385C0
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00538640
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x004499A0
// Name: public: void CMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryPool::Clear(CMemoryPool *this)
{
  CMemoryPool *m_pNext; // eax
  CMemoryPool::CBlob *p_m_BlobHead; // edi
  CMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004499E0
// Name: protected: void CMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryPool::AddNewBlob(CMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CMemoryPool::CBlob **v6; // eax
  CMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edx
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CMemoryPool::CBlob **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v5 + 15);
  v6[2] = (CMemoryPool::CBlob *)v5;
  v6[1] = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  *v6 = m_pPrev;
  m_pPrev->m_pNext = (CMemoryPool::CBlob *)v6;
  v6[1]->m_pPrev = (CMemoryPool::CBlob *)v6;
  v8 = v6 + 3;
  this->m_pHeadOfFreeList = v8;
  if ( v4 - 1 > 0 )
  {
    v9 = v4 - 1;
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00449A70
// Name: public: void __near * CMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CMemoryPool::Alloc(CMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 )
      return nullptr;
    CMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449AC0
// Name: public: void CMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryPool::Free(CMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449AE0
// Name: public: CMemoryPool::CMemoryPool(int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMemoryPool *__thiscall CMemoryPool::CMemoryPool(
        CMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner)
{
  int v5; // eax
  const char *v7; // eax

  v5 = blockSize;
  if ( blockSize < 4 )
    v5 = 4;
  this->m_BlockSize = v5;
  this->m_BlocksPerBlob = numElements;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  v7 = pszAllocOwner;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  if ( pszAllocOwner == nullptr )
    v7 = "U:\\dev\\main\\src\\tier1\\mempool.cpp";
  this->m_pszAllocOwner = v7;
  CMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00449B40
// Name: public: CMemoryPool::~CMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryPool::~CMemoryPool(CMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CMemoryPool::g_ReportFunc != nullptr )
    CMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00449B70
// Name: public: void __near * CMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CMemoryPool::Alloc(CMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 )
      return nullptr;
    CMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00466460
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004664A0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004664C0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x004664F0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00466580
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004665D0
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00466650
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0054CAB0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0054CAF0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054CB10
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x0054CB40
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x0054CBD0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0054CC20
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0054CCA0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace phogen

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x004848A0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004848E0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00484910
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edx
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  this->m_pHeadOfFreeList = v8;
  if ( v4 - 1 > 0 )
  {
    v9 = v4 - 1;
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x004849B0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00484A00
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "u:\\buildbot\\portal2_staging_win32\\build\\src\\tier1\\mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00484A80
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace QCGenerator

// ============================================================
// Overlay from resourcesystem (Missing functions)
// ============================================================
namespace resourcesystem {

//------------------------------------------------------------------------------
// Address: 0x1000BB80
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000BBC0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BBE0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC10
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edx
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  this->m_pHeadOfFreeList = v8;
  if ( v4 - 1 > 0 )
  {
    v9 = v4 - 1;
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x1000BCB0
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = ".\\mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD30
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace resourcesystem

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00600D20
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00600D60
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00600D80
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00600DB0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00600E40
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00600E90
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00600F10
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1009A790
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1009A7D0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009A800
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x1009A890
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009A8E0
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009A960
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0054AEB0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0054AEF0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054AF10
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x0054AF40
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x0054AFD0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0054B020
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0054B0A0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005BE920
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005BE960
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BE980
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x005BE9B0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x005BEA40
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005BEA90
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005BEB10
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x005444F0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00544530
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00544550
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00544580
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00544610
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00544660
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005446E0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x100B9E10
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B9E50
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B9E80
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x100B9F10
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B9F60
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B9FE0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00492200
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00492240
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00492270
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00492300
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00492350
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004923D0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004681B0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004681F0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468210
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00468240
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edx
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  this->m_pHeadOfFreeList = v8;
  if ( v4 - 1 > 0 )
  {
    v9 = v4 - 1;
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x004682E0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468330
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "u:\\buildbot\\portal2_staging_win32\\build\\src\\tier1\\mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004683B0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0049A1F6
// Name: public: unsigned char __near * D3DXCore::CAlloc::Alloc(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall D3DXCore::CAlloc::Alloc(D3DXCore::CAlloc *this, unsigned int a2, SIZE_T dwSize)
{
  int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  bool v7; // cc
  SIZE_T v8; // ebx
  int v9; // eax
  unsigned int v11; // ecx
  _DWORD *lpAddress; // [esp+Ch] [ebp-4h]
  SIZE_T dwSizea; // [esp+1Ch] [ebp+Ch]

  v4 = *((_DWORD *)this + 2);
  v5 = ~(dwSize - 1);
  v6 = a2 + (v5 & (dwSize + v4 - 1));
  if ( v6 <= *((_DWORD *)this + 4) )
  {
    v11 = *((_DWORD *)this + 3);
    if ( v6 > v11 )
    {
      v8 = ~(*((_DWORD *)this + 1) - 1) & (*((_DWORD *)this + 1) + v6 - 1);
      if ( VirtualAlloc(
             lpAddress: (LPVOID)(v11 + *(_DWORD *)this),
             dwSize: v8 - v11,
             flAllocationType: 0x1000u,
             flProtect: 4u) == nullptr )
        return nullptr;
LABEL_8:
      *((_DWORD *)this + 3) = v8;
    }
    v9 = *(_DWORD *)this - a2;
    *((_DWORD *)this + 2) = v6;
    return (unsigned __int8 *)(v6 + v9);
  }
  v6 = a2 + (v5 & (dwSize + 3));
  dwSizea = *((_DWORD *)this + 5);
  if ( v6 > dwSizea )
  {
    do
    {
      v7 = v6 <= 2 * dwSizea;
      dwSizea *= 2;
    }
    while ( !v7 );
  }
  lpAddress = VirtualAlloc(lpAddress: nullptr, dwSize: dwSizea, flAllocationType: 0x2000u, flProtect: 4u);
  if ( lpAddress == nullptr )
    return nullptr;
  v8 = ~(*((_DWORD *)this + 1) - 1) & (*((_DWORD *)this + 1) + v6 - 1);
  if ( VirtualAlloc(lpAddress, dwSize: v8, flAllocationType: 0x1000u, flProtect: 4u) != nullptr )
  {
    *lpAddress = *(_DWORD *)this;
    *(_DWORD *)this = lpAddress;
    *((_DWORD *)this + 4) = dwSizea;
    goto LABEL_8;
  }
  VirtualFree(lpAddress, dwSize: 0, dwFreeType: 0x8000u);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049C7E2
// Name: public: static unsigned int __near * D3DXShader::CInstruction::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
static unsigned __int8 *__stdcall D3DXShader::CInstruction::Alloc(unsigned int a1)
{
  return D3DXCore::CAlloc::Alloc(this: D3DXShader::CInstruction::s_pAlloc, a2: 4 * a1, dwSize: 0x10u);
}

//------------------------------------------------------------------------------
// Address: 0x0064C190
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0064C1D0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064C1F0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x0064C220
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x0064C2B0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0064C300
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0064C380
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A2E0
// Name: public: D3DXShader::CNode::CNode(enum D3DXShader::_D3DXNODE_TYPE)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNode::CNode(_DWORD *this, int a2)
{
  *(this + 2) = 0;
  *(this + 3) = 0;
  *this = &D3DXShader::CNode::`vftable';
  *(this + 1) = a2;
  return this;
}

} // namespace vmap

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00482DB0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00482DF0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00482E20
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00482EB0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482F00
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00482F80
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace vp4

// ============================================================
// Overlay from vstdlib_s (Missing functions)
// ============================================================
namespace vstdlib_s {

//------------------------------------------------------------------------------
// Address: 0x3F612780
// Name: public: static void CMemoryPool::SetErrorReportFunc(void (*)(char const __near *,...))
// Source: json
//------------------------------------------------------------------------------
void CMemoryPool::SetErrorReportFunc()
{
  __asm { int     8Bh; used by BASIC while in interpreter }
  JUMPOUT(0x3F612784);
}

//------------------------------------------------------------------------------
// Address: 0x3F612790
// Name: public: CMemoryPool::CMemoryPool(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMemoryPool::CMemoryPool(
        CMemoryPool *this@<ecx>,
        int a2@<eax>,
        char a3@<dh>,
        int a4@<ebp>,
        int blockSize,
        int numElements,
        int growMode)
{
  LOBYTE(this) = *(_BYTE *)(a4 - 341759572) + (_BYTE)this;
  *(_BYTE *)(2 * a2 + 0x7C890000) = a3;
  this->m_BlobHead.m_NumBytes = __ROL4__(
                                  this->m_BlobHead.m_NumBytes
                                ^ this->m_GrowMode
                                ^ (int)this->m_pHeadOfFreeList
                                ^ *((_DWORD *)this + 13),
                                  1);
  JUMPOUT(0x3F6127CC);
}

//------------------------------------------------------------------------------
// Address: 0x3F6127D0
// Name: public: CMemoryPool::~CMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMemoryPool::~CMemoryPool(CMemoryPool *this@<ecx>, char a2@<cf>, char a3@<al>, int a4@<edi>)
{
  if ( (char)(a2 + a3 - 117) < 0 )
  {
    *(_DWORD *)this->m_BlobHead.m_Data = __ROL4__(
                                           *(_DWORD *)this->m_BlobHead.m_Data
                                         ^ (int)this->m_BlobHead.m_pPrev
                                         ^ this->m_BlocksAllocated
                                         ^ a4,
                                           1);
    JUMPOUT(0x3F6127F8);
  }
  JUMPOUT(0x3F61280C);
}

//------------------------------------------------------------------------------
// Address: 0x3F612800
// Name: private: void CMemoryPool::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryPool::Init(CMemoryPool *this)
{
  JUMPOUT(0x3F612818);
}

//------------------------------------------------------------------------------
// Address: 0x3F612820
// Name: public: void CMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMemoryPool::Clear(CMemoryPool *this@<ecx>, char a2@<cf>)
{
  *((_BYTE *)this + 856695900) += (_BYTE)this + a2;
  *((_BYTE *)this - 1960303492) += (_BYTE)this;
  _enable();
  JUMPOUT(0x3F61285F);
}

//------------------------------------------------------------------------------
// Address: 0x3F612860
// Name: private: void CMemoryPool::ReportLeaks(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMemoryPool::ReportLeaks(CMemoryPool *this@<ecx>, int a2@<ebp>)
{
  this->m_BlocksAllocated = __ROL4__(this->m_BlockSize ^ a2, 1);
  JUMPOUT(0x3F612879);
}

//------------------------------------------------------------------------------
// Address: 0x3F612880
// Name: public: void CMemoryPool::EnumAllBlocks(void (*)(void __near *,void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryPool::EnumAllBlocks(
        CMemoryPool *this,
        void (__cdecl *enumfunc)(void *, void *),
        void *pvContext)
{
  __asm { iret }
  JUMPOUT(0x3F612884);
}

//------------------------------------------------------------------------------
// Address: 0x3F612960
// Name: public: void CMemoryPool::PrintStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryPool::PrintStats(CMemoryPool *this)
{
  JUMPOUT(0x3F612962);
}

//------------------------------------------------------------------------------
// Address: 0x3F6129C0
// Name: private: void CMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMemoryPool::AddNewBlob(
        CMemoryPool *this@<ecx>,
        int a2@<eax>,
        int a3@<ebp>,
        _DWORD *a4@<edi>,
        int _ESI@<esi>)
{
  __asm { outsd }
  LOBYTE(a2) = a2 ^ 0x8B;
  if ( (a2 & 0x80u) == 0 )
  {
    LOBYTE(a2) = a2 + 35;
    _enable();
    a4 = *(_DWORD **)(a2 + 180);
    a3 = a4[6] ^ a4[11];
  }
  a4[14] = __ROL4__(*a4 ^ a4[14] ^ a3, 1);
  *(_DWORD *)(*(_DWORD *)(a2 + 180) + 60) = __ROL4__(
                                              *(_DWORD *)(*(_DWORD *)(a2 + 180) + 60)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 4)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 28)
                                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 48),
                                              1);
  **(_DWORD **)(a2 + 180) = __ROL4__(
                              **(_DWORD **)(a2 + 180)
                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 8)
                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 32)
                            ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 52),
                              1);
  *(_DWORD *)(*(_DWORD *)(a2 + 180) + 4) = __ROL4__(
                                             *(_DWORD *)(*(_DWORD *)(a2 + 180) + 4)
                                           ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 12)
                                           ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 36)
                                           ^ *(_DWORD *)(*(_DWORD *)(a2 + 180) + 56),
                                             1);
  JUMPOUT(0x3F612ACA);
}

//------------------------------------------------------------------------------
// Address: 0x3F612B30
// Name: public: void CMemoryPool::Free(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMemoryPool::Free(CMemoryPool *this@<ecx>, _DWORD *a2@<ebx>, int a3@<ebp>, void *pMem, int cubAlloc)
{
  a2[3] = __ROL4__(*a2 ^ a3, 1);
  JUMPOUT(0x3F612B41);
}

//------------------------------------------------------------------------------
// Address: 0x3F612B50
// Name: public: void CMemoryPool::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMemoryPool::Validate(CMemoryPool *this@<eax>)
{
  ;
}

} // namespace vstdlib_s

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1009E970
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1009E9B0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E9D0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009EA00
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x1009EA90
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009EAE0
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009EB60
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace vtex_dll

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x004868F0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00486930
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00486960
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x004869F0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00486A40
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00486AC0
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace vtex_gui

// ============================================================
// Overlay from XLSPMaster (Missing functions)
// ============================================================
namespace XLSPMaster {

//------------------------------------------------------------------------------
// Address: 0x00458760
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004587A0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004587C0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x004587F0
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x00458880
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004588D0
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

} // namespace XLSPMaster

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1036BEE0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1036BF20
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036BF40
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x1036BF70
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x1036C000
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036C050
// Name: public: void __near * CUtlMemoryPool::AllocZero(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::AllocZero(CUtlMemoryPool *this, unsigned int amount)
{
  void **m_pHeadOfFreeList; // edi
  int m_PeakAlloc; // eax

  if ( amount > this->m_BlockSize )
    return nullptr;
  m_pHeadOfFreeList = (void **)this->m_pHeadOfFreeList;
  if ( m_pHeadOfFreeList == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    m_pHeadOfFreeList = (void **)this->m_pHeadOfFreeList;
    if ( m_pHeadOfFreeList == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *m_pHeadOfFreeList;
  _V_memset(dest: (int)m_pHeadOfFreeList, fill: nullptr, count: amount);
  return m_pHeadOfFreeList;
}

//------------------------------------------------------------------------------
// Address: 0x1036C0C0
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1036C140
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036C180
// Name: public: void __near * CUtlMemoryPool::AllocZero(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::AllocZero(CUtlMemoryPool *this)
{
  return CUtlMemoryPool::AllocZero(this, amount: this->m_BlockSize);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10379D90
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10379DD0
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10379DF0
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x10379E20
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x10379EB0
// Name: public: void __near * CUtlMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this, unsigned int amount)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  if ( amount > this->m_BlockSize )
    return nullptr;
  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10379F00
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10379F80
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace server

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x1003A7E0
// Name: public: void CUtlMemoryPool::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Clear(CUtlMemoryPool *this)
{
  CUtlMemoryPool *m_pNext; // eax
  CUtlMemoryPool::CBlob *p_m_BlobHead; // edi
  CUtlMemoryPool *m_BlocksPerBlob; // esi

  m_pNext = (CUtlMemoryPool *)this->m_BlobHead.m_pNext;
  p_m_BlobHead = &this->m_BlobHead;
  if ( m_pNext != (CUtlMemoryPool *)&this->m_BlobHead )
  {
    do
    {
      m_BlocksPerBlob = (CUtlMemoryPool *)m_pNext->m_BlocksPerBlob;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pNext);
      m_pNext = m_BlocksPerBlob;
    }
    while ( m_BlocksPerBlob != (CUtlMemoryPool *)p_m_BlobHead );
  }
  this->m_BlobHead.m_pNext = p_m_BlobHead;
  p_m_BlobHead->m_pPrev = p_m_BlobHead;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003A820
// Name: public: void CUtlMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::Free(CUtlMemoryPool *this, _DWORD *memBlock)
{
  void *m_pHeadOfFreeList; // edx

  if ( memBlock != nullptr )
  {
    m_pHeadOfFreeList = this->m_pHeadOfFreeList;
    --this->m_BlocksAllocated;
    *memBlock = m_pHeadOfFreeList;
    this->m_pHeadOfFreeList = memBlock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A840
// Name: public: CUtlMemoryPool::~CUtlMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::~CUtlMemoryPool(CUtlMemoryPool *this)
{
  int m_BlocksAllocated; // eax

  m_BlocksAllocated = this->m_BlocksAllocated;
  if ( m_BlocksAllocated > 0 && CUtlMemoryPool::g_ReportFunc != nullptr )
    CUtlMemoryPool::g_ReportFunc(a1: "Memory leak: mempool blocks left in memory: %d\n", m_BlocksAllocated);
  CUtlMemoryPool::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003A870
// Name: protected: void CUtlMemoryPool::AddNewBlob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryPool::AddNewBlob(CUtlMemoryPool *this)
{
  int m_GrowMode; // eax
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  CUtlMemoryPool::CBlob *v6; // eax
  CUtlMemoryPool::CBlob *m_pPrev; // ecx
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx

  m_GrowMode = this->m_GrowMode;
  if ( m_GrowMode == 2 )
  {
    v3 = 1;
  }
  else
  {
    if ( m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return;
    v3 = this->m_NumBlobs + 1;
  }
  v4 = v3 * this->m_BlocksPerBlob;
  v5 = v4 * this->m_BlockSize;
  v6 = (CUtlMemoryPool::CBlob *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAlignment + v5 + 14);
  v6->m_NumBytes = v5;
  v6->m_pNext = &this->m_BlobHead;
  m_pPrev = this->m_BlobHead.m_pPrev;
  v6->m_pPrev = m_pPrev;
  m_pPrev->m_pNext = v6;
  v6->m_pNext->m_pPrev = v6;
  v8 = (_DWORD *)(~(this->m_nAlignment - 1) & ((unsigned int)&v6->m_NumBytes + this->m_nAlignment + 3));
  v9 = v4 - 1;
  this->m_pHeadOfFreeList = v8;
  if ( v9 > 0 )
  {
    do
    {
      v10 = (_DWORD *)((char *)v8 + this->m_BlockSize);
      --v9;
      *v8 = v10;
      v8 = v10;
    }
    while ( v9 != 0 );
  }
  *v8 = 0;
  ++this->m_NumBlobs;
}

//------------------------------------------------------------------------------
// Address: 0x1003A900
// Name: public: CUtlMemoryPool::CUtlMemoryPool(int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryPool *__thiscall CUtlMemoryPool::CUtlMemoryPool(
        CUtlMemoryPool *this,
        unsigned int blockSize,
        int numElements,
        int growMode,
        const char *pszAllocOwner,
        int nAlignment)
{
  unsigned __int16 v6; // ax
  unsigned int v8; // ecx
  int v9; // ecx
  const char *v10; // eax

  v6 = nAlignment;
  if ( nAlignment == 0 )
    v6 = 1;
  v8 = blockSize;
  this->m_nAlignment = v6;
  if ( blockSize < 4 )
    v8 = 4;
  v9 = ~(v6 - 1) & (v8 + v6 - 1);
  this->m_BlocksPerBlob = numElements;
  v10 = pszAllocOwner;
  this->m_BlockSize = v9;
  this->m_PeakAlloc = 0;
  this->m_GrowMode = growMode;
  if ( pszAllocOwner == nullptr )
    v10 = "mempool.cpp";
  this->m_pszAllocOwner = v10;
  this->m_NumBlobs = 0;
  this->m_BlocksAllocated = 0;
  this->m_pHeadOfFreeList = nullptr;
  this->m_BlobHead.m_pPrev = &this->m_BlobHead;
  this->m_BlobHead.m_pNext = &this->m_BlobHead;
  CUtlMemoryPool::AddNewBlob(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003A980
// Name: public: void __near * CUtlMemoryPool::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall CUtlMemoryPool::Alloc(CUtlMemoryPool *this)
{
  void **result; // eax
  int m_PeakAlloc; // ecx

  result = (void **)this->m_pHeadOfFreeList;
  if ( result == nullptr )
  {
    if ( this->m_GrowMode == 0 && this->m_NumBlobs != 0 )
      return nullptr;
    CUtlMemoryPool::AddNewBlob(this);
    result = (void **)this->m_pHeadOfFreeList;
    if ( result == nullptr )
      return nullptr;
  }
  m_PeakAlloc = ++this->m_BlocksAllocated;
  if ( this->m_PeakAlloc > m_PeakAlloc )
    m_PeakAlloc = this->m_PeakAlloc;
  this->m_PeakAlloc = m_PeakAlloc;
  this->m_pHeadOfFreeList = *result;
  return result;
}

} // namespace matchmaking
