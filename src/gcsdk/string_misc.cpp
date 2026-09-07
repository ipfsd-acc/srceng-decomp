// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/string_misc.cpp
// Functions: 3
// ============================================================

#include "gcsdk\string_misc.h"

//------------------------------------------------------------------------------
// Address: 0x10009780
// Name: unsigned int GCSDK::GetCchTempTextBuffer(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GCSDK::GetCchTempTextBuffer()
{
  return 1024;
}

//------------------------------------------------------------------------------
// Address: 0x10009790
// Name: void GCSDK::UninitTempTextBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::UninitTempTextBuffers()
{
  int i; // esi
  char **m_pMemory; // eax

  CThreadMutex::Lock(this: &GCSDK::g_mutexTempTextBuffer);
  for ( i = 0; i < GCSDK::g_vecTempTextBuffer.m_Size; ++i )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: GCSDK::g_vecTempTextBuffer.m_Memory.m_pMemory[i]);
  m_pMemory = GCSDK::g_vecTempTextBuffer.m_Memory.m_pMemory;
  GCSDK::g_vecTempTextBuffer.m_Size = 0;
  if ( GCSDK::g_vecTempTextBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( GCSDK::g_vecTempTextBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: GCSDK::g_vecTempTextBuffer.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      GCSDK::g_vecTempTextBuffer.m_Memory.m_pMemory = nullptr;
    }
    GCSDK::g_vecTempTextBuffer.m_Memory.m_nAllocationCount = 0;
  }
  GCSDK::g_vecTempTextBuffer.m_pElements = m_pMemory;
  CThreadMutex::Unlock(this: &GCSDK::g_mutexTempTextBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10009820
// Name: char __near * GCSDK::GetPchTempTextBuffer(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GCSDK::GetPchTempTextBuffer()
{
  GenericThreadLocals::CThreadLocalPtr<char> *v0; // esi
  int i; // edi
  void *v2; // eax
  GenericThreadLocals::CThreadLocalPtr<char> *v3; // esi
  void *v4; // eax
  int m_Size; // eax
  int v6; // ebx
  char **m_pMemory; // ecx
  int v8; // eax
  char **v9; // ebx
  char *v11; // [esp+Ch] [ebp-4h]

  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &s_irgchBuffer);
    atexit(func: GCSDK::GetPchTempTextBuffer_::_2_::_dynamic_atexit_destructor_for__s_irgchBuffer__);
  }
  if ( (_S1_2 & 2) == 0 )
  {
    _S1_2 |= 2u;
    v0 = s_rgtlsBuffers;
    for ( i = 4; i >= 0; --i )
      GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: v0++);
    atexit(func: GCSDK::GetPchTempTextBuffer_::_2_::_dynamic_atexit_destructor_for__s_rgtlsBuffers__);
  }
  v2 = GenericThreadLocals::CThreadLocalBase::Get(this: &s_irgchBuffer);
  GenericThreadLocals::CThreadLocalBase::Set(this: &s_irgchBuffer, a2: (void *)(((int)v2 + 1) % 5));
  v3 = &s_rgtlsBuffers[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: &s_irgchBuffer)];
  if ( GenericThreadLocals::CThreadLocalBase::Get(this: v3) == nullptr )
  {
    CThreadMutex::Lock(this: &GCSDK::g_mutexTempTextBuffer);
    v4 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1024);
    GenericThreadLocals::CThreadLocalBase::Set(this: v3, a2: v4);
    v11 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: v3);
    m_Size = GCSDK::g_vecTempTextBuffer.m_Size;
    v6 = GCSDK::g_vecTempTextBuffer.m_Size;
    if ( GCSDK::g_vecTempTextBuffer.m_Size + 1 > GCSDK::g_vecTempTextBuffer.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<GCSDK::CLock *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&GCSDK::g_vecTempTextBuffer,
        num: GCSDK::g_vecTempTextBuffer.m_Size - GCSDK::g_vecTempTextBuffer.m_Memory.m_nAllocationCount + 1);
      m_Size = GCSDK::g_vecTempTextBuffer.m_Size;
    }
    m_pMemory = GCSDK::g_vecTempTextBuffer.m_Memory.m_pMemory;
    GCSDK::g_vecTempTextBuffer.m_Size = m_Size + 1;
    v8 = m_Size - v6;
    GCSDK::g_vecTempTextBuffer.m_pElements = GCSDK::g_vecTempTextBuffer.m_Memory.m_pMemory;
    if ( v8 > 0 )
    {
      _V_memmove(
        dest: &GCSDK::g_vecTempTextBuffer.m_Memory.m_pMemory[v6 + 1],
        src: &GCSDK::g_vecTempTextBuffer.m_Memory.m_pMemory[v6],
        count: 4 * v8);
      m_pMemory = GCSDK::g_vecTempTextBuffer.m_Memory.m_pMemory;
    }
    v9 = &m_pMemory[v6];
    if ( v9 != nullptr )
      *v9 = v11;
    CThreadMutex::Unlock(this: &GCSDK::g_mutexTempTextBuffer);
  }
  return (char *)GenericThreadLocals::CThreadLocalBase::Get(this: v3);
}
