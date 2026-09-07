// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_hash.cxx
// Functions: 4
// ============================================================

#include "ivp\ivp_utility\ivu_hash.h"

//------------------------------------------------------------------------------
// Address: 0x1008D500
// Name: public: IVP_Hash::IVP_Hash(int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Hash *__thiscall IVP_Hash::IVP_Hash(IVP_Hash *this, int sizei, int key_sizei, void *not_found_valuei)
{
  this->size = sizei;
  this->key_size = key_sizei;
  this->not_found_value = not_found_valuei;
  this->elems = (IVP_Hash_Elem **)_calloc_crt(nelem: 4, size: sizei);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008D530
// Name: public: IVP_Hash::~IVP_Hash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Hash::~IVP_Hash(IVP_Hash *this)
{
  int i; // ebx
  IVP_Hash_Elem **elems; // eax
  bool v4; // zf
  IVP_Hash_Elem **v5; // eax
  IVP_Hash_Elem *v6; // eax
  IVP_Hash_Elem *next; // esi

  for ( i = 0; i < this->size; ++i )
  {
    elems = this->elems;
    v4 = elems[i] == nullptr;
    v5 = &elems[i];
    if ( !v4 )
    {
      v6 = *v5;
      if ( v6 != nullptr )
      {
        do
        {
          next = v6->next;
          free(data: v6);
          v6 = next;
        }
        while ( next != nullptr );
      }
    }
  }
  if ( this->elems != nullptr )
  {
    free(data: this->elems);
    this->elems = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D590
// Name: public: void __near * IVP_Hash::find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall IVP_Hash::find(IVP_Hash *this, const char *key)
{
  const char *v2; // esi
  int v3; // edi
  unsigned int i; // eax
  IVP_Hash_Elem *v5; // edx
  const char *v6; // esi
  unsigned int key_size; // eax
  char *v8; // edi

  v2 = key;
  v3 = this->key_size - 1;
  for ( i = -1; v3 >= 0; --v3 )
    i = IVP_Hash_crctab[(unsigned __int8)(i ^ *v2++)] ^ (i >> 8);
  v5 = this->elems[i % this->size];
  if ( v5 == nullptr )
    return this->not_found_value;
  while ( 1 )
  {
    v6 = key;
    key_size = this->key_size;
    v8 = v5->key;
    if ( this->key_size >= 4u )
    {
      while ( *(_DWORD *)v8 == *(_DWORD *)v6 )
      {
        key_size -= 4;
        v6 += 4;
        v8 += 4;
        if ( key_size < 4 )
          goto LABEL_7;
      }
      goto LABEL_13;
    }
LABEL_7:
    if ( key_size == 0 || *v6 == *v8 && (key_size <= 1 || v6[1] == v8[1] && (key_size <= 2 || v6[2] == v8[2])) )
      return v5->value;
LABEL_13:
    v5 = v5->next;
    if ( v5 == nullptr )
      return this->not_found_value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D650
// Name: public: void IVP_Hash::add(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Hash::add(IVP_Hash *this, char *key, void *val)
{
  char *v3; // edx
  unsigned int v5; // eax
  int i; // esi
  int v7; // ebx
  IVP_Hash_Elem *v8; // esi

  v3 = key;
  v5 = -1;
  for ( i = this->key_size - 1; i >= 0; --i )
    v5 = IVP_Hash_crctab[(unsigned __int8)(v5 ^ *v3++)] ^ (v5 >> 8);
  v7 = v5 % this->size;
  v8 = (IVP_Hash_Elem *)p_malloc(size: this->key_size + 12);
  memcpy(dst: (unsigned __int8 *)v8->key, src: (unsigned __int8 *)key, count: this->key_size);
  v8->next = this->elems[v7];
  this->elems[v7] = v8;
  v8->value = val;
}
