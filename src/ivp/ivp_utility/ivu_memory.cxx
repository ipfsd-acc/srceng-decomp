// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_memory.cxx
// Functions: 16
// ============================================================

#include "ivp\ivp_utility\ivu_memory.h"

//------------------------------------------------------------------------------
// Address: 0x100037D0
// Name: void __near * p_malloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl p_malloc(unsigned int size)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size);
}

//------------------------------------------------------------------------------
// Address: 0x1006E630
// Name: void ivp_byte_swap4(unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ivp_byte_swap4(unsigned int *fourbytes)
{
  int v2; // eax
  ivp_byte_swap4::__l2::FOURBYTES out; // [esp+8h] [ebp+8h]

  v2 = *fourbytes;
  out.b[0] = HIBYTE(*fourbytes);
  out.b[1] = BYTE2(v2);
  out.b[2] = BYTE1(v2);
  out.b[3] = v2;
  *fourbytes = out.v;
}

//------------------------------------------------------------------------------
// Address: 0x1006E660
// Name: void ivp_byte_swap2(unsigned short __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ivp_byte_swap2(ivp_byte_swap2::__l2::TWOBYTES *twobytes)
{
  ivp_byte_swap2::__l2::TWOBYTES in; // [esp+0h] [ebp-4h]
  ivp_byte_swap2::__l2::TWOBYTES out; // [esp+Ch] [ebp+8h]

  in = (ivp_byte_swap2::__l2::TWOBYTES)twobytes->v;
  out.b[0] = HIBYTE(twobytes->v);
  out.b[1] = in.b[0];
  *twobytes = out;
}

//------------------------------------------------------------------------------
// Address: 0x1006E6C0
// Name: void __near * ivp_malloc_aligned(int,int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl ivp_malloc_aligned(int size, int alignment)
{
  _DWORD *v2; // ecx
  _DWORD *result; // eax

  v2 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size + alignment + 8);
  result = (_DWORD *)(-alignment & ((unsigned int)v2 + alignment + 7));
  *v2 = 1704464948;
  *(result - 1) = v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006E700
// Name: void ivp_free_aligned(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ivp_free_aligned(void **data)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(data - 1));
}

//------------------------------------------------------------------------------
// Address: 0x1006E720
// Name: private: void IVP_U_Memory::free_mem_transaction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Memory::free_mem_transaction(IVP_U_Memory *this)
{
  p_Memory_Elem *last_elem; // eax
  p_Memory_Elem *next; // edi
  p_Memory_Elem *first_elem; // ecx
  unsigned int size_of_external_mem; // edx
  char *v6; // eax

  last_elem = this->last_elem;
  if ( last_elem != nullptr )
  {
    do
    {
      next = last_elem->next;
      if ( last_elem == this->first_elem )
        break;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: last_elem);
      last_elem = next;
    }
    while ( next != nullptr );
  }
  first_elem = this->first_elem;
  size_of_external_mem = this->size_of_external_mem;
  v6 = (char *)(((int)&this->first_elem[4].next + 3) & 0xFFFFFFE0);
  this->speicherbeginn = v6;
  if ( size_of_external_mem == 0 )
    size_of_external_mem = 32736;
  this->speicherende = &v6[size_of_external_mem];
  this->last_elem = first_elem;
}

//------------------------------------------------------------------------------
// Address: 0x1006E770
// Name: public: char __near * IVP_U_Memory::neuer_sp_block(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall IVP_U_Memory::neuer_sp_block(IVP_U_Memory *this, unsigned int groesse)
{
  unsigned int v2; // ebx
  unsigned int v3; // edi
  p_Memory_Elem *v5; // eax
  char *result; // eax

  v2 = 32728;
  v3 = (groesse + 31) & 0xFFFFFFE0;
  if ( v3 > 0x7FD8 )
    v2 = (groesse + 31) & 0xFFFFFFE0;
  v5 = (p_Memory_Elem *)((int (__stdcall *)(unsigned int))_g_pMemAlloc->Alloc_2)(a1: v2 + 40);
  v5->next = this->last_elem;
  this->last_elem = v5;
  result = (char *)(((unsigned int)&v5[4].next + 3) & 0xFFFFFFE0);
  this->speicherbeginn = &result[v3];
  this->speicherende = &result[v2];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006E7C0
// Name: public: void IVP_U_Memory::free_mem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Memory::free_mem(IVP_U_Memory *this)
{
  p_Memory_Elem *last_elem; // eax
  p_Memory_Elem *next; // esi

  last_elem = this->last_elem;
  if ( last_elem != nullptr )
  {
    do
    {
      next = last_elem->next;
      if ( this->size_of_external_mem != 0 && last_elem == this->first_elem )
        break;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: last_elem);
      last_elem = next;
    }
    while ( next != nullptr );
  }
  this->speicherbeginn = nullptr;
  this->speicherende = nullptr;
  this->last_elem = nullptr;
  this->first_elem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006E810
// Name: public: IVP_U_Memory::~IVP_U_Memory(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall IVP_U_Memory::~IVP_U_Memory(IVP_U_Memory *this)
{
  IVP_U_Memory::free_mem(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006E820
// Name: public: void IVP_U_Memory::init_mem_transaction_usage(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Memory::init_mem_transaction_usage(IVP_U_Memory *this, p_Memory_Elem *external_mem, int size)
{
  p_Memory_Elem *last_elem; // edx
  unsigned int size_of_external_mem; // ecx
  p_Memory_Elem *v6; // edx
  char *v7; // eax
  p_Memory_Elem *v8; // eax
  char *v9; // eax

  this->transaction_in_use = 0;
  if ( external_mem != nullptr )
  {
    last_elem = this->last_elem;
    this->size_of_external_mem = size - 32;
    external_mem->next = last_elem;
    size_of_external_mem = this->size_of_external_mem;
    this->last_elem = external_mem;
    v6 = this->last_elem;
    v7 = (char *)(((unsigned int)&external_mem[4].next + 3) & 0xFFFFFFE0);
    this->speicherbeginn = v7;
    this->speicherende = &v7[size_of_external_mem];
  }
  else
  {
    this->size_of_external_mem = 0;
    v8 = (p_Memory_Elem *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x8000);
    v8->next = this->last_elem;
    this->last_elem = v8;
    v6 = this->last_elem;
    v9 = (char *)(((unsigned int)&v8[4].next + 3) & 0xFFFFFFE0);
    this->speicherbeginn = v9;
    this->speicherende = v9 + 32728;
  }
  this->first_elem = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1006E8A0
// Name: public: IVP_U_Memory::IVP_U_Memory(void)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Memory *__thiscall IVP_U_Memory::IVP_U_Memory(IVP_U_Memory *this)
{
  this->transaction_in_use = 3;
  this->size_of_external_mem = 0;
  this->speicherbeginn = nullptr;
  this->speicherende = nullptr;
  this->last_elem = nullptr;
  this->first_elem = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100037F0
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10003810
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size * count);
  memset(dst: v3, value: 0, count: size * count);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10003850
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x10003870
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006E690
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _calloc_crt(int nelem, int size)
{
  unsigned __int8 *v2; // edi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * nelem);
  memset(dst: v2, value: 0, count: size * nelem);
  return (char *)v2;
}
