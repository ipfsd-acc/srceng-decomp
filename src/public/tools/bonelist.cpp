// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/tools/bonelist.cpp
// Functions: 4
// ============================================================

#include "public\tools\bonelist.h"

//------------------------------------------------------------------------------
// Address: 0x1026DE30
// Name: public: void CBoneList::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneList::Release(CBoneList *this)
{
  if ( (*(_BYTE *)this & 1) != 0 )
    C_BaseEntity::operator delete(pMem: this);
  else
    _Warning(a1: "Called Release() on CBoneList not allocated via Alloc() method\n");
}

//------------------------------------------------------------------------------
// Address: 0x1026DE50
// Name: public: CBoneList::CBoneList(void)
// Source: json
//------------------------------------------------------------------------------
CBoneList *__thiscall CBoneList::CBoneList(CBoneList *this)
{
  *(_BYTE *)this &= ~1u;
  *((_WORD *)this + 1) &= 0x8000u;
  _V_memset(dest: (int)this->m_vecPos, fill: nullptr, count: 0xC00u);
  _V_memset(dest: (int)this->m_quatRot, fill: nullptr, count: 0x1000u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1026DE90
// Name: public: static class CBoneList __near * CBoneList::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
CBoneList *__cdecl CBoneList::Alloc()
{
  _BYTE *v0; // eax
  _BYTE *v1; // esi

  v0 = MemAlloc_Alloc(nSize: 0x1C04u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *v0 &= ~1u;
  *((_WORD *)v0 + 1) &= 0x8000u;
  _V_memset(dest: (int)(v0 + 4), fill: nullptr, count: 0xC00u);
  _V_memset(dest: (int)(v1 + 3076), fill: nullptr, count: 0x1000u);
  *v1 |= 1u;
  return (CBoneList *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1026DEF0
// Name: __CreateCClientToolsIClientTools_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientTools *__cdecl _CreateCClientToolsIClientTools_interface()
{
  return &s_ClientTools;
}
