// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_min_list.cxx
// Functions: 4
// ============================================================

#include "ivp\ivp_utility\ivu_min_list.h"

//------------------------------------------------------------------------------
// Address: 0x100A03E0
// Name: public: IVP_U_Min_List::IVP_U_Min_List(int)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Min_List *__thiscall IVP_U_Min_List::IVP_U_Min_List(IVP_U_Min_List *this, int start_size)
{
  unsigned __int16 v2; // ax
  int v4; // ecx
  unsigned int v5; // eax

  v2 = start_size;
  if ( start_size > 65532 )
    v2 = -4;
  this->malloced_size = v2;
  this->counter = 0;
  this->elems = (IVP_U_Min_List_Element *)p_malloc(size: 16 * v2);
  v4 = 0;
  v5 = 0;
  for ( this->free_list = 0; v5 < this->malloced_size; ++v4 )
    this->elems[v4].next = ++v5;
  this->elems[this->malloced_size - 1].next = -1;
  this->first_element = 0xFFFF;
  this->first_long = 0xFFFF;
  this->min_value = 1.0e10;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A0470
// Name: public: IVP_U_Min_List::~IVP_U_Min_List(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Min_List::~IVP_U_Min_List(IVP_U_Min_List *this)
{
  if ( this->elems != nullptr )
  {
    free(data: this->elems);
    this->elems = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0490
// Name: public: unsigned int IVP_U_Min_List::add(void __near *,float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IVP_U_Min_List::add(IVP_U_Min_List *this, int elem, float value)
{
  unsigned int free_list; // eax
  unsigned int v5; // edx
  IVP_U_Min_List_Element *v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // edi
  IVP_U_Min_List_Element *v9; // ebx
  int v10; // ecx
  IVP_U_Min_List_Element *elems; // eax
  IVP_U_Min_List_Element *v12; // eax
  unsigned int malloced_size; // edx
  int v14; // eax
  unsigned int v15; // edi
  unsigned int v16; // ecx
  unsigned __int16 first_element; // cx
  unsigned int v19; // ecx
  unsigned int first_long; // ecx
  unsigned int v22; // edi
  IVP_U_Min_List_Element *v23; // ebx
  IVP_U_Min_List_Element *v24; // ecx
  int v25; // ebx
  unsigned int next; // edx
  IVP_U_Min_List_Element *v27; // ecx
  unsigned int v28; // edi
  int v29; // eax
  IVP_U_Min_List_Element *v30; // ecx
  int v31; // edx
  IVP_U_Min_List_Element *v32; // eax
  unsigned int v33; // eax
  IVP_U_Min_List_Element *l; // [esp+Ch] [ebp-10h]
  int firstj_after; // [esp+10h] [ebp-Ch]
  int v36; // [esp+14h] [ebp-8h]
  int nNewMallocSize; // [esp+18h] [ebp-4h]
  unsigned __int16 nNewMallocSizea; // [esp+18h] [ebp-4h]
  int max_cmp_len; // [esp+24h] [ebp+8h]
  int count_cmp; // [esp+28h] [ebp+Ch]

  free_list = this->free_list;
  ++this->counter;
  if ( (_WORD)free_list == 0xFFFF )
  {
    v7 = 2 * this->malloced_size + 1;
    nNewMallocSizea = 2 * this->malloced_size + 1;
    if ( v7 > 0xFFFC )
    {
      nNewMallocSizea = -4;
      v7 = 65532;
    }
    v8 = 0;
    v9 = (IVP_U_Min_List_Element *)p_malloc(size: 16 * (v7 + 1));
    if ( this->malloced_size != 0 )
    {
      v10 = 0;
      do
      {
        elems = this->elems;
        *(_QWORD *)&v9[v10].long_next = *(_QWORD *)&elems[v10].long_next;
        *(_QWORD *)&v9[v10].value = *(_QWORD *)&elems[v10].value;
        ++v8;
        ++v10;
      }
      while ( v8 < this->malloced_size );
    }
    v12 = this->elems;
    this->malloced_size = nNewMallocSizea;
    if ( v12 != nullptr )
    {
      free(data: v12);
      this->elems = nullptr;
    }
    malloced_size = this->malloced_size;
    v14 = v8;
    nNewMallocSize = v8;
    v15 = v8 + 1;
    v6 = &v9[v14];
    this->elems = v9;
    this->free_list = v15;
    if ( v15 < malloced_size )
    {
      v16 = v15;
      do
        this->elems[v16++].next = ++v15;
      while ( v15 < this->malloced_size );
    }
    this->elems[this->malloced_size - 1].next = -1;
    v5 = nNewMallocSize;
  }
  else
  {
    v5 = free_list;
    v6 = &this->elems[free_list];
    nNewMallocSize = v5;
    this->free_list = v6->next;
  }
  v6->element = (void *)elem;
  v6->value = value;
  v6->long_next = -2;
  if ( this->min_value >= value )
  {
    first_element = this->first_element;
    this->min_value = value;
    v6->next = first_element;
    v19 = this->first_element;
    if ( v19 != 0xFFFF )
      this->elems[v19].prev = v5;
    this->first_element = v5;
    v6->prev = -1;
    return v5;
  }
  first_long = this->first_long;
  v22 = this->first_element;
  max_cmp_len = 3;
  if ( first_long != 0xFFFF )
  {
    v23 = this->elems;
    do
    {
      if ( v23[first_long].value >= value )
        break;
      ++max_cmp_len;
      v22 = first_long;
      first_long = v23[first_long].long_next;
    }
    while ( first_long != 0xFFFF );
  }
  v24 = this->elems;
  v25 = 16 * v22;
  next = v24[v22].next;
  v27 = &v24[v22];
  firstj_after = v22;
  count_cmp = 0;
  v36 = 16 * v22;
  if ( next == 0xFFFF )
  {
LABEL_26:
    v6->next = next;
    v6->prev = v22;
    v27->next = nNewMallocSize;
  }
  else
  {
    while ( 1 )
    {
      ++count_cmp;
      v27 = &this->elems[next];
      if ( value <= v27->value )
        break;
      v22 = next;
      next = v27->next;
      if ( next == 0xFFFF )
      {
        v25 = v36;
        goto LABEL_26;
      }
    }
    l = &this->elems[v22];
    v6->next = l->next;
    this->elems[next].prev = nNewMallocSize;
    v25 = v36;
    v6->prev = v22;
    l->next = nNewMallocSize;
  }
  if ( count_cmp <= max_cmp_len )
    return nNewMallocSize;
  v28 = firstj_after;
  if ( max_cmp_len > 2 )
  {
    v29 = max_cmp_len - 2;
    do
    {
      --v29;
      v28 = this->elems[v28].next;
    }
    while ( v29 != 0 );
  }
  v30 = this->elems;
  v31 = *(unsigned __int16 *)((char *)&v30->long_next + v25);
  v32 = &v30[v28];
  if ( v31 == 65534 )
  {
    v32->long_next = this->first_long;
    v32->long_prev = -1;
    v33 = this->first_long;
    if ( v33 != 0xFFFF )
      this->elems[v33].long_prev = v28;
    this->first_long = v28;
    return nNewMallocSize;
  }
  v32->long_next = v31;
  v32->long_prev = firstj_after;
  if ( v31 != 0xFFFF )
    this->elems[v31].long_prev = v28;
  *(unsigned __int16 *)((char *)&this->elems->long_next + v25) = v28;
  return nNewMallocSize;
}

//------------------------------------------------------------------------------
// Address: 0x100A0750
// Name: public: void IVP_U_Min_List::remove_minlist_elem(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Min_List::remove_minlist_elem(IVP_U_Min_List *this, unsigned int index)
{
  IVP_U_Min_List_Element *elems; // esi
  unsigned int next; // eax
  unsigned __int16 *p_long_next; // edx
  int v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // esi
  int v8; // eax
  unsigned __int16 free_list; // ax

  elems = this->elems;
  next = elems[index].next;
  p_long_next = &elems[index].long_next;
  v5 = p_long_next[3];
  if ( v5 == 0xFFFF )
  {
    this->first_element = next;
    if ( next == 0xFFFF )
    {
      this->min_value = 1.0e10;
    }
    else
    {
      v6 = next;
      elems[v6].prev = -1;
      this->min_value = this->elems[v6].value;
    }
  }
  else
  {
    elems[v5].next = next;
    if ( next != 0xFFFF )
      this->elems[next].prev = v5;
  }
  v7 = *p_long_next;
  if ( v7 != 65534 )
  {
    v8 = p_long_next[1];
    if ( v7 != 0xFFFF )
      this->elems[v7].long_prev = v8;
    if ( v8 == 0xFFFF )
      this->first_long = v7;
    else
      this->elems[v8].long_next = v7;
  }
  free_list = this->free_list;
  --this->counter;
  p_long_next[2] = free_list;
  this->free_list = index;
}
