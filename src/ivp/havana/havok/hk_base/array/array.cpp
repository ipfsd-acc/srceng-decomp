// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_base/array/array.cpp
// Functions: 1
// ============================================================

#include "ivp\havana\havok\hk_base\array\array.h"

//------------------------------------------------------------------------------
// Address: 0x10043F10
// Name: protected: void hk_Array_Base::grow_mem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Array_Base::grow_mem(hk_Array_Base *this, int size)
{
  int v3; // edi
  hk_Memory *instance; // eax
  unsigned __int8 *v5; // ebx
  char *m_elems; // eax
  hk_Memory *v7; // eax
  char *v8; // [esp-Ch] [ebp-18h]
  int v9; // [esp-8h] [ebp-14h]

  v3 = 2 * this->m_memsize;
  if ( v3 == 0 )
    v3 = 2;
  instance = hk_Memory::get_instance();
  v5 = (unsigned __int8 *)hk_Memory::allocate(this: instance, size: size * v3, cl: HK_MEMORY_CLASS_ARRAY);
  memcpy(dst: v5, src: (unsigned __int8 *)this->m_elems, count: size * this->m_memsize);
  m_elems = this->m_elems;
  if ( m_elems != nullptr && m_elems != (char *)(this + 1) )
  {
    v9 = size * this->m_memsize;
    v8 = this->m_elems;
    v7 = hk_Memory::get_instance();
    hk_Memory::deallocate(this: v7, p: v8, size: v9, cl: HK_MEMORY_CLASS_ARRAY);
  }
  this->m_memsize = v3;
  this->m_elems = (char *)v5;
}
