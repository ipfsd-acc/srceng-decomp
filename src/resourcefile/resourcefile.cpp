// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: resourcefile/resourcefile.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10010530
// Name: void const __near * Resource_GetBlock(struct ResourceFileHeader_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Resource_GetBlock(const ResourceFileHeader_t *pHeader, unsigned int id)
{
  signed int m_nCount; // ebx
  int v4; // ecx
  _DWORD *v5; // eax

  if ( pHeader->m_nVersion != 1 )
    return 0;
  m_nCount = pHeader->m_ResourceBlocks.m_nCount;
  v4 = 0;
  if ( m_nCount <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = (int *)((char *)&pHeader->m_ResourceBlocks.m_nOffset + 8 * v4 + pHeader->m_ResourceBlocks.m_nOffset);
    if ( *v5 == id )
      break;
    if ( ++v4 >= m_nCount )
      return 0;
  }
  return (int)v5 + v5[1] + 4;
}
