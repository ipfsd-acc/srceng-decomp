// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makeshaders.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004101C0
// Name: bool GetPreloadData_VCS(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetPreloadData_VCS(const char *pFilename, CUtlBuffer *fileBufferIn, CUtlBuffer *preloadBufferOut)
{
  CUtlBuffer *v3; // edx
  unsigned __int8 *m_pMemory; // ecx
  unsigned __int32 v5; // edi
  int v7; // ecx
  unsigned __int8 *pHeader; // [esp+Ch] [ebp-8h]

  v3 = fileBufferIn;
  m_pMemory = fileBufferIn->m_Memory.m_pMemory;
  pHeader = fileBufferIn->m_Memory.m_pMemory;
  v5 = _byteswap_ulong(*(_DWORD *)fileBufferIn->m_Memory.m_pMemory);
  preloadBufferOut->m_Get = 0;
  preloadBufferOut->m_Put = 0;
  preloadBufferOut->m_nOffset = 0;
  preloadBufferOut->m_nMaxPut = 0;
  preloadBufferOut->m_Error = 0;
  if ( preloadBufferOut->m_Memory.m_nGrowSize >= 0 )
  {
    if ( preloadBufferOut->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: preloadBufferOut->m_Memory.m_pMemory);
      m_pMemory = pHeader;
      v3 = fileBufferIn;
      preloadBufferOut->m_Memory.m_pMemory = nullptr;
    }
    preloadBufferOut->m_Memory.m_nAllocationCount = 0;
  }
  if ( v3->m_nMaxPut <= 0x8000 )
  {
    CUtlBuffer::Put(this: preloadBufferOut, pMem: v3->m_Memory.m_pMemory, size: v3->m_nMaxPut);
    return 1;
  }
  if ( v5 < 5 )
    return 0;
  if ( v5 != 5 && v5 != 6 )
  {
    _Warning(a1: "Can't preload: '%s', expecting version %d got version %d\n", pFilename, 6, v5);
    return 0;
  }
  v7 = 8 * _byteswap_ulong(*((_DWORD *)m_pMemory + 5)) + 28;
  if ( v5 == 6 )
    v7 += 8 * _byteswap_ulong(*(_DWORD *)&v3->m_Memory.m_pMemory[v7]) + 4;
  CUtlBuffer::Put(this: preloadBufferOut, pMem: v3->m_Memory.m_pMemory, size: v7);
  return 1;
}
