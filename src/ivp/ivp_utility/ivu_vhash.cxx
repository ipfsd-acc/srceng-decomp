// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_vhash.cxx
// Functions: 17
// ============================================================

#include "ivp\ivp_utility\ivu_vhash.h"

//------------------------------------------------------------------------------
// Address: 0x1006E8C0
// Name: protected: static int IVP_VHash_Store::void_pointer_to_index(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl IVP_VHash_Store::void_pointer_to_index(void *p)
{
  unsigned int v1; // eax
  unsigned int v2; // eax

  v1 = IVP_Hash_crctab[(unsigned __int8)(~LOBYTE(IVP_Hash_crctab[(unsigned __int8)~(_BYTE)p]) ^ BYTE1(p))]
     ^ ((IVP_Hash_crctab[(unsigned __int8)~(_BYTE)p] ^ 0xFFFFFF) >> 8);
  v2 = IVP_Hash_crctab[(unsigned __int8)(v1 ^ BYTE2(p))] ^ (v1 >> 8);
  return IVP_Hash_crctab[(unsigned __int8)(v2 ^ HIBYTE(p))] ^ (v2 >> 8) | 0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x1006E930
// Name: protected: IVP_VHash::IVP_VHash(int)
// Source: json
//------------------------------------------------------------------------------
IVP_VHash *__thiscall IVP_VHash::IVP_VHash(IVP_VHash *this, int size_i)
{
  *((_DWORD *)this + 2) &= 0xFF000000;
  this->__vftable = (IVP_VHash_vtbl *)&IVP_VHash::`vftable';
  this->size_mm = size_i - 1;
  *((_BYTE *)this + 11) = 0;
  this->elems = (IVP_VHash_Elem *)_calloc_crt(nelem: size_i, size: 8);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006E970
// Name: public: virtual IVP_VHash::~IVP_VHash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_VHash::~IVP_VHash(IVP_VHash *this)
{
  bool v2; // zf

  v2 = (*((_DWORD *)this + 2) & 0xFF000000) == 0;
  this->__vftable = (IVP_VHash_vtbl *)&IVP_VHash::`vftable';
  if ( v2 && this->elems != nullptr )
  {
    free(data: this->elems);
    this->elems = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E9A0
// Name: private: void IVP_VHash::rehash(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_VHash::rehash(IVP_VHash *this, int new_size)
{
  int v3; // edi
  IVP_VHash_Elem *v4; // eax
  int v5; // ebx
  const void **p_elem; // edi
  IVP_VHash_Elem *old_elems; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  old_elems = this->elems;
  v3 = this->size_mm + 1;
  this->size_mm = new_size - 1;
  v4 = (IVP_VHash_Elem *)_calloc_crt(nelem: new_size, size: 8);
  v5 = *((_DWORD *)this + 2) & 0xFFFFFF;
  this->elems = v4;
  i = v3 - 1;
  if ( v3 - 1 >= 0 )
  {
    p_elem = &old_elems->elem;
    do
    {
      if ( *p_elem != nullptr )
        IVP_VHash::add_elem(this, elem: *p_elem, hash_index: (int)*(p_elem - 1));
      p_elem += 2;
      --i;
    }
    while ( i >= 0 );
  }
  *((_DWORD *)this + 2) ^= (v5 ^ *((_DWORD *)this + 2)) & 0xFFFFFF;
  if ( (*((_DWORD *)this + 2) & 0xFF000000) == 0 && old_elems != nullptr )
    free(data: old_elems);
  *((_BYTE *)this + 11) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006EA30
// Name: public: void __near * IVP_VHash::find_elem(void const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall IVP_VHash::find_elem(IVP_VHash *this, void *elem, unsigned int hash_index)
{
  unsigned int v4; // esi
  IVP_VHash_Elem *v5; // ebx
  void *v6; // eax

  v4 = this->size_mm & hash_index;
  v5 = &this->elems[v4];
  v6 = (void *)v5->elem;
  if ( v6 == nullptr )
    return nullptr;
  while ( (v5->hash_index | 0x80000000) != hash_index || this->compare(this, a2: v6, a3: elem) == 0 )
  {
    v4 = this->size_mm & (v4 + 1);
    v5 = &this->elems[v4];
    v6 = (void *)v5->elem;
    if ( v6 == nullptr )
      return nullptr;
  }
  return (void *)v5->elem;
}

//------------------------------------------------------------------------------
// Address: 0x1006EAA0
// Name: public: IVP_VHash_Store::IVP_VHash_Store(int)
// Source: json
//------------------------------------------------------------------------------
IVP_VHash_Store *__thiscall IVP_VHash_Store::IVP_VHash_Store(IVP_VHash_Store *this, int size_i)
{
  this->size_mm = size_i - 1;
  this->size = size_i;
  this->nelems = 0;
  this->dont_free = nullptr;
  this->elems_store = (IVP_VHash_Store_Elem *)_calloc_crt(nelem: size_i, size: 12);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006EAD0
// Name: public: IVP_VHash_Store::~IVP_VHash_Store(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_VHash_Store::~IVP_VHash_Store(IVP_VHash_Store *this)
{
  IVP_VHash_Store_Elem *elems_store; // eax

  elems_store = this->elems_store;
  if ( elems_store != this->dont_free && elems_store != nullptr )
  {
    free(data: this->elems_store);
    this->elems_store = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006EB00
// Name: private: void IVP_VHash_Store::rehash(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_VHash_Store::rehash(IVP_VHash_Store *this, int new_size)
{
  int size; // ebx
  IVP_VHash_Store_Elem *elems_store; // edi
  IVP_VHash_Store_Elem *v5; // eax
  int nelems; // edx
  int v7; // ebx
  void **p_elem; // edi
  IVP_VHash_Store_Elem *old_elems; // [esp+Ch] [ebp-4h]
  int old_nelems; // [esp+18h] [ebp+8h]

  size = this->size;
  elems_store = this->elems_store;
  old_elems = elems_store;
  this->size = new_size;
  this->size_mm = new_size - 1;
  v5 = (IVP_VHash_Store_Elem *)_calloc_crt(nelem: new_size, size: 12);
  nelems = this->nelems;
  v7 = size - 1;
  this->elems_store = v5;
  old_nelems = nelems;
  if ( v7 >= 0 )
  {
    p_elem = &elems_store->elem;
    do
    {
      if ( *p_elem != nullptr )
        IVP_VHash_Store::add_elem(this, key_elem: *(p_elem - 1), elem: *p_elem, hash_index: (int)*(p_elem - 2));
      p_elem += 3;
      --v7;
    }
    while ( v7 >= 0 );
    elems_store = old_elems;
  }
  this->nelems = old_nelems;
  if ( elems_store != this->dont_free && elems_store != nullptr )
    free(data: elems_store);
}

//------------------------------------------------------------------------------
// Address: 0x1006EB80
// Name: public: void __near * IVP_VHash_Store::find_elem(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall IVP_VHash_Store::find_elem(IVP_VHash_Store *this, void *key_elem, unsigned int hash_index)
{
  int size_mm; // esi
  int size; // edi
  unsigned int v5; // eax
  int v6; // edx
  IVP_VHash_Store_Elem *v7; // ecx
  IVP_VHash_Store_Elem *elems_store; // [esp+Ch] [ebp-4h]

  size_mm = this->size_mm;
  size = this->size;
  v5 = hash_index & size_mm;
  v6 = 0;
  if ( this->size > 0 )
  {
    elems_store = this->elems_store;
    do
    {
      v7 = &elems_store[v5];
      ++v6;
      if ( v7->elem == nullptr )
        break;
      if ( (v7->hash_index | 0x80000000) == hash_index && v7->key_elem == key_elem )
        return v7->elem;
      v5 = size_mm & (v5 + 1);
    }
    while ( v6 < size );
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006EBF0
// Name: public: void IVP_VHash_Store::change_elem(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_VHash_Store::change_elem(IVP_VHash_Store *this, void *key_elem, void *new_value)
{
  unsigned int v4; // eax
  int v5; // ecx
  int i; // edi
  IVP_VHash_Store_Elem *v7; // edx

  v4 = IVP_VHash_Store::void_pointer_to_index(p: key_elem);
  v5 = v4 & this->size_mm;
  for ( i = 0; i < this->size; v5 = this->size_mm & (v5 + 1) )
  {
    v7 = &this->elems_store[v5];
    ++i;
    if ( v7->elem == nullptr )
      break;
    if ( (v7->hash_index | 0x80000000) == v4 && v7->key_elem == key_elem )
    {
      v7->elem = new_value;
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006ECC0
// Name: public: void IVP_VHash::add_elem(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_VHash::add_elem(IVP_VHash *this, const void *elem, unsigned int hash_index)
{
  int size_mm; // eax
  int v5; // edi
  IVP_VHash_Elem *elems; // eax
  int v7; // ecx
  bool v8; // zf
  IVP_VHash_Elem *v9; // eax
  int v10; // ebx
  int v11; // edx
  const void *v12; // edi
  unsigned int v13; // edi
  unsigned int v14; // [esp+Ch] [ebp-4h]

  size_mm = this->size_mm;
  if ( 2 * (*((_DWORD *)this + 2) & 0xFFFFFF) > size_mm )
    IVP_VHash::rehash(this, new_size: 2 * size_mm + 2);
  v5 = this->size_mm;
  elems = this->elems;
  v7 = hash_index & v5;
  *((_DWORD *)this + 2) ^= (*((_DWORD *)this + 2) ^ (*((_DWORD *)this + 2) + 1)) & 0xFFFFFF;
  v8 = elems[hash_index & v5].elem == nullptr;
  v9 = &elems[hash_index & v5];
  v10 = hash_index & v5;
  if ( !v8 )
  {
    do
    {
      v14 = v9->hash_index;
      v11 = v5 & v9->hash_index;
      if ( v7 < v11 )
      {
        v12 = elem;
        elem = v9->elem;
        v9->elem = v12;
        v13 = hash_index;
        hash_index = v14;
        v9->hash_index = v13;
        v7 = v11;
      }
      v5 = this->size_mm;
      v10 = v5 & (v10 + 1);
      v9 = &this->elems[v10];
    }
    while ( v9->elem != nullptr );
  }
  this->elems[v10].elem = elem;
  this->elems[v10].hash_index = hash_index;
}

//------------------------------------------------------------------------------
// Address: 0x1006ED70
// Name: public: void __near * IVP_VHash::remove_elem(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall IVP_VHash::remove_elem(IVP_VHash *this, void *elem, int hash_index)
{
  unsigned int i; // edi
  int v5; // edi
  IVP_VHash_Elem *v6; // ebx
  const void *v7; // eax
  IVP_VHash_Elem *elems; // ebx
  int size_mm; // ecx
  int v10; // edx
  bool v11; // zf
  IVP_VHash_Elem *v12; // ebx
  int v13; // eax
  IVP_VHash_Elem *v14; // eax
  const void *elema; // [esp+14h] [ebp+8h]
  int ideal_pos_of_last_element; // [esp+18h] [ebp+Ch]

  for ( i = hash_index; ; i = v5 + 1 )
  {
    v5 = this->size_mm & i;
    v6 = &this->elems[v5];
    if ( v6->elem == nullptr )
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_utility\\ivu_vhash.cxx", 157);
    if ( (v6->hash_index | 0x80000000) == hash_index && this->compare(this, a2: (void *)v6->elem, a3: elem) == 1 )
      break;
  }
  v7 = v6->elem;
  elems = this->elems;
  elema = v7;
  *((_DWORD *)this + 2) ^= (*((_DWORD *)this + 2) ^ (*((_DWORD *)this + 2) - 1)) & 0xFFFFFF;
  size_mm = this->size_mm;
  ideal_pos_of_last_element = size_mm;
  if ( elems[size_mm].elem != nullptr )
    ideal_pos_of_last_element = elems[size_mm].hash_index & size_mm;
  v10 = size_mm & (v5 + 1);
  v11 = elems[v10].elem == nullptr;
  v12 = &elems[v10];
  if ( !v11 )
  {
    while ( 1 )
    {
      v13 = v12->hash_index & size_mm;
      if ( v10 <= v5 )
        break;
      if ( v13 >= ideal_pos_of_last_element )
      {
        if ( v13 == ideal_pos_of_last_element && v13 <= v10 && v13 > v5 )
          goto LABEL_21;
        goto LABEL_20;
      }
      if ( v13 <= v5 )
        goto LABEL_20;
LABEL_21:
      size_mm = this->size_mm;
      v10 = size_mm & (v10 + 1);
      v12 = &this->elems[v10];
      if ( v12->elem == nullptr )
        goto LABEL_22;
    }
    if ( v5 != size_mm )
      goto LABEL_22;
    if ( v13 < ideal_pos_of_last_element )
      goto LABEL_21;
LABEL_20:
    v14 = this->elems;
    v14[v5].hash_index = v12->hash_index;
    v14[v5].elem = v12->elem;
    v5 = v10;
    goto LABEL_21;
  }
LABEL_22:
  this->elems[v5].elem = nullptr;
  this->elems[v5].hash_index = 0;
  return (void *)elema;
}

//------------------------------------------------------------------------------
// Address: 0x1006EE80
// Name: public: void IVP_VHash_Store::add_elem(void __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_VHash_Store::add_elem(IVP_VHash_Store *this, void *key_elem, void *elem, unsigned int hash_index)
{
  int size_mm; // edi
  IVP_VHash_Store_Elem *elems_store; // edx
  int v7; // ecx
  IVP_VHash_Store_Elem *v8; // eax
  int v9; // ebx
  int v10; // edx
  void *v11; // ecx
  IVP_VHash_Store_Elem *v12; // eax
  bool v13; // zf
  int v14; // eax
  unsigned int v15; // [esp+Ch] [ebp-8h]
  void *h_e; // [esp+10h] [ebp-4h]

  if ( 2 * this->nelems >= this->size )
    IVP_VHash_Store::rehash(this, new_size: 2 * this->size);
  size_mm = this->size_mm;
  elems_store = this->elems_store;
  ++this->nelems;
  v7 = hash_index & size_mm;
  v8 = &elems_store[hash_index & size_mm];
  v9 = hash_index & size_mm;
  if ( v8->key_elem != nullptr )
  {
    do
    {
      v15 = v8->hash_index;
      v10 = size_mm & v8->hash_index;
      if ( v7 < v10 )
      {
        v11 = v8->key_elem;
        h_e = v8->elem;
        v8->key_elem = key_elem;
        v8->elem = elem;
        key_elem = v11;
        v8->hash_index = hash_index;
        hash_index = v15;
        elem = h_e;
        v7 = v10;
      }
      size_mm = this->size_mm;
      v12 = this->elems_store;
      v9 = size_mm & (v9 + 1);
      v13 = v12[v9].key_elem == nullptr;
      v8 = &v12[v9];
    }
    while ( !v13 );
  }
  v14 = v9;
  this->elems_store[v14].key_elem = key_elem;
  this->elems_store[v14].elem = elem;
  this->elems_store[v14].hash_index = hash_index;
}

//------------------------------------------------------------------------------
// Address: 0x1006EF40
// Name: public: void __near * IVP_VHash_Store::remove_elem(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall IVP_VHash_Store::remove_elem(IVP_VHash_Store *this, void *key_elem, int hash_index)
{
  IVP_VHash_Store_Elem *elems_store; // eax
  int size_mm; // esi
  signed int i; // edi
  IVP_VHash_Store_Elem *v6; // edx
  void *v7; // edx
  int v8; // edx
  bool v9; // zf
  IVP_VHash_Store_Elem *v10; // eax
  int v11; // ebx
  IVP_VHash_Store_Elem *v12; // esi
  signed int v13; // edi
  void *elem; // [esp+14h] [ebp+8h]
  int ideal_pos_of_last_element; // [esp+18h] [ebp+Ch]

  elems_store = this->elems_store;
  size_mm = this->size_mm;
  for ( i = hash_index & size_mm; ; i = size_mm & (i + 1) )
  {
    v6 = &elems_store[i];
    if ( (v6->hash_index | 0x80000000) == hash_index && v6->key_elem == key_elem )
      break;
  }
  v7 = v6->elem;
  --this->nelems;
  elem = v7;
  ideal_pos_of_last_element = size_mm;
  if ( elems_store[size_mm].key_elem != nullptr )
    ideal_pos_of_last_element = size_mm & elems_store[size_mm].hash_index;
  v8 = size_mm & (i + 1);
  v9 = elems_store[v8].key_elem == nullptr;
  v10 = &elems_store[v8];
  if ( !v9 )
  {
    while ( 1 )
    {
      v11 = size_mm & v10->hash_index;
      if ( v8 <= i )
        break;
      if ( v11 >= ideal_pos_of_last_element )
      {
        if ( v11 == ideal_pos_of_last_element && v11 <= v8 && v11 > i )
          goto LABEL_19;
        goto LABEL_18;
      }
      if ( v11 <= i )
        goto LABEL_18;
LABEL_19:
      size_mm = this->size_mm;
      v8 = size_mm & (v8 + 1);
      v10 = &this->elems_store[v8];
      if ( v10->key_elem == nullptr )
        goto LABEL_20;
    }
    if ( i != size_mm )
      goto LABEL_20;
    if ( v11 < ideal_pos_of_last_element )
      goto LABEL_19;
LABEL_18:
    v12 = &this->elems_store[i];
    *(_QWORD *)&v12->hash_index = *(_QWORD *)&v10->hash_index;
    v12->elem = v10->elem;
    i = v8;
    goto LABEL_19;
  }
LABEL_20:
  v13 = i;
  this->elems_store[v13].key_elem = nullptr;
  this->elems_store[v13].hash_index = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1006F030
// Name: public: void __near * IVP_VHash_Store::find_elem(void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall IVP_VHash_Store::find_elem(IVP_VHash_Store *this, void *key_elem)
{
  unsigned int v3; // eax

  v3 = IVP_VHash_Store::void_pointer_to_index(p: key_elem);
  return IVP_VHash_Store::find_elem(this, key_elem, hash_index: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1006F060
// Name: public: void IVP_VHash_Store::add_elem(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_VHash_Store::add_elem(IVP_VHash_Store *this, void *key_elem, void *elem)
{
  unsigned int v4; // eax

  v4 = IVP_VHash_Store::void_pointer_to_index(p: key_elem);
  IVP_VHash_Store::add_elem(this, key_elem, elem, hash_index: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1006F090
// Name: public: void __near * IVP_VHash_Store::remove_elem(void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall IVP_VHash_Store::remove_elem(IVP_VHash_Store *this, void *key_elem)
{
  unsigned int v3; // eax

  v3 = IVP_VHash_Store::void_pointer_to_index(p: key_elem);
  return IVP_VHash_Store::remove_elem(this, key_elem, hash_index: v3);
}
