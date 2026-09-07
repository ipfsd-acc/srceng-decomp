// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_min_hash.cxx
// Functions: 6
// ============================================================

#include "ivp\ivp_utility\ivu_min_hash.h"

//------------------------------------------------------------------------------
// Address: 0x1008D8B0
// Name: public: IVP_U_Min_Hash::IVP_U_Min_Hash(int)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Min_Hash *__thiscall IVP_U_Min_Hash::IVP_U_Min_Hash(IVP_U_Min_Hash *this, int sizei)
{
  int v3; // ecx
  int v4; // eax
  IVP_U_Min_Hash_Elem **v5; // eax
  IVP_U_Min_Hash_Elem **v6; // edx

  this->size = sizei;
  v3 = 0;
  v4 = 1;
  do
  {
    if ( v4 == sizei )
      break;
    ++v3;
    v4 = __ROL4__(v4, 1);
  }
  while ( v3 < 32 );
  this->elems = (IVP_U_Min_Hash_Elem **)_calloc_crt(nelem: 4, size: sizei);
  v5 = (IVP_U_Min_Hash_Elem **)_calloc_crt(nelem: 4, size: 2 * this->size);
  v6 = &v5[this->size];
  this->stadel = v5;
  this->min_per_array_pos = v6;
  this->counter = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008D910
// Name: public: IVP_U_Min_Hash::~IVP_U_Min_Hash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Min_Hash::~IVP_U_Min_Hash(IVP_U_Min_Hash *this)
{
  unsigned int i; // ebx
  IVP_U_Min_Hash_Elem **elems; // eax
  bool v4; // zf
  IVP_U_Min_Hash_Elem **v5; // eax
  IVP_U_Min_Hash_Elem *v6; // eax
  IVP_U_Min_Hash_Elem *next; // esi

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
  if ( this->stadel != nullptr )
  {
    free(data: this->stadel);
    this->stadel = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D980
// Name: private: void IVP_U_Min_Hash::min_removed_at_index(class IVP_U_Min_Hash_Elem __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Min_Hash::min_removed_at_index(IVP_U_Min_Hash *this, IVP_U_Min_Hash_Elem *elem, unsigned int i)
{
  IVP_U_Min_Hash_Elem *v3; // edi
  IVP_U_Min_Hash_Elem *j; // edx
  float value; // xmm0_4
  float v6; // xmm1_4
  int v7; // esi
  IVP_U_Min_Hash_Elem **stadel; // eax
  IVP_U_Min_Hash_Elem *v9; // edx
  bool v10; // zf
  unsigned int height; // [esp+14h] [ebp+Ch]

  v3 = this->elems[i];
  if ( v3 != nullptr )
  {
    for ( j = v3->next; j != nullptr; j = j->next )
    {
      value = j->value;
      v6 = v3->value;
      if ( v6 > value || value == v6 && j->cmp_index < v3->cmp_index )
        v3 = j;
    }
  }
  this->min_per_array_pos[i] = v3;
  v7 = this->size + i;
  height = this->size >> 1;
  if ( height != 0 )
  {
    do
    {
      stadel = this->stadel;
      v7 >>= 1;
      if ( elem != stadel[v7] )
        return;
      if ( stadel[2 * v7] != nullptr )
      {
        if ( stadel[2 * v7 + 1] == nullptr )
          goto LABEL_18;
        if ( stadel[2 * v7 + 1]->value > stadel[2 * v7]->value
          || this->stadel[2 * v7]->value == this->stadel[2 * v7 + 1]->value
          && this->stadel[2 * v7]->cmp_index < this->stadel[2 * v7 + 1]->cmp_index )
        {
          stadel = this->stadel;
LABEL_18:
          v9 = stadel[2 * v7];
          goto LABEL_19;
        }
        stadel = this->stadel;
        v9 = stadel[2 * v7 + 1];
      }
      else
      {
        v9 = stadel[2 * v7 + 1];
      }
LABEL_19:
      v10 = height >> 1 == 0;
      height >>= 1;
      stadel[v7] = v9;
    }
    while ( !v10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DA70
// Name: public: void IVP_U_Min_Hash::add(void __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Min_Hash::add(IVP_U_Min_Hash *this, void *elem, float val)
{
  unsigned int v4; // esi
  IVP_U_Min_Hash_Elem *v5; // eax
  int v6; // ecx
  IVP_U_Min_Hash_Elem **elems; // edx
  IVP_U_Min_Hash_Elem **min_per_array_pos; // ecx
  IVP_U_Min_Hash_Elem **v9; // ecx
  float value; // xmm0_4
  int v11; // ecx
  unsigned int i; // esi
  IVP_U_Min_Hash_Elem **stadel; // edx
  bool v14; // zf
  IVP_U_Min_Hash_Elem **v15; // edx

  v4 = (this->size - 1) & (1001 * (_DWORD)elem + ((unsigned int)(101 * (_DWORD)elem) >> 8));
  v5 = (IVP_U_Min_Hash_Elem *)p_malloc(size: 0x10u);
  v6 = sort_counter;
  v5->cmp_index = sort_counter;
  v5->elem = elem;
  elems = this->elems;
  sort_counter = v6 + 1;
  v5->next = elems[v4];
  this->elems[v4] = v5;
  v5->value = val;
  min_per_array_pos = this->min_per_array_pos;
  ++this->counter;
  v9 = &min_per_array_pos[v4];
  if ( *v9 == nullptr || (*v9)->value > val )
  {
    value = v5->value;
    v11 = v4 + this->size;
    this->stadel[v11] = v5;
    for ( i = this->size >> 1; i != 0; *v15 = v5 )
    {
      stadel = this->stadel;
      v11 >>= 1;
      v14 = stadel[v11] == nullptr;
      v15 = &stadel[v11];
      if ( !v14 && value >= (*v15)->value )
        break;
      i >>= 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DB20
// Name: public: void IVP_U_Min_Hash::remove(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Min_Hash::remove(IVP_U_Min_Hash *this, void *elem)
{
  unsigned int v3; // eax
  IVP_U_Min_Hash_Elem **v4; // ebx
  IVP_U_Min_Hash_Elem *v5; // esi
  IVP_U_Min_Hash_Elem *v6; // ecx

  v3 = (this->size - 1) & (1001 * (_DWORD)elem + ((unsigned int)(101 * (_DWORD)elem) >> 8));
  v4 = &this->elems[v3];
  v5 = *v4;
  v6 = nullptr;
  if ( *v4 != nullptr )
  {
    while ( v5->elem != elem )
    {
      v6 = v5;
      v5 = v5->next;
      if ( v5 == nullptr )
        return;
    }
    if ( v6 != nullptr )
      v6->next = v5->next;
    else
      *v4 = v5->next;
    if ( v5 == this->min_per_array_pos[v3] )
      IVP_U_Min_Hash::min_removed_at_index(this, elem: v5, i: v3);
    free(data: v5);
    --this->counter;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DBA0
// Name: public: void IVP_U_Min_Hash::remove_min(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Min_Hash::remove_min(IVP_U_Min_Hash *this)
{
  IVP_U_Min_Hash_Elem **stadel; // eax
  void *elem; // eax

  stadel = this->stadel;
  if ( stadel[1] != nullptr )
  {
    elem = stadel[1]->elem;
    if ( elem != nullptr )
      IVP_U_Min_Hash::remove(this, elem);
  }
}
