// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_perftest/amalg_texture_parser.cpp
// Functions: 3
// ============================================================

#include "vgui2\vgui_perftest\amalg_texture_parser.h"

//------------------------------------------------------------------------------
// Address: 0x00401040
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401150
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x00401170
// Name: __strdup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _strdup(char *string)
{
  unsigned int v1; // kr00_4
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // esi

  v1 = strlen(string);
  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v1 + 1);
  v3 = v2;
  if ( v2 != nullptr )
    memcpy(dst: v2, src: (unsigned __int8 *)string, count: v1 + 1);
  return (char *)v3;
}
