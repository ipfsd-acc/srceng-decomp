// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_collision_filter.cxx
// Functions: 10
// ============================================================

#include "ivp\ivp_collision\ivp_collision_filter.h"

//------------------------------------------------------------------------------
// Address: 0x1007F4F0
// Name: public: virtual IVP_Collision_Filter::~IVP_Collision_Filter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Collision_Filter::~IVP_Collision_Filter(IVP_Collision_Filter *this)
{
  this->__vftable = (IVP_Collision_Filter_vtbl *)&IVP_Collision_Filter::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1007F500
// Name: protected: virtual enum IVP_BOOL IVP_CFEP_Hash::compare(void __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_CFEP_Hash::compare(IVP_CFEP_Hash *this, _DWORD *elem0, _DWORD *elem1)
{
  return *elem0 == *elem1 && elem0[1] == elem1[1];
}

//------------------------------------------------------------------------------
// Address: 0x1007F530
// Name: protected: int IVP_CFEP_Hash::pair_to_index(class IVP_CFEP_Objectpair __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IVP_CFEP_Hash::pair_to_index(IVP_CFEP_Hash *this, IVP_CFEP_Objectpair *pair)
{
  unsigned int v2; // eax
  unsigned int v3; // eax

  v2 = IVP_Hash_crctab[(unsigned __int8)(~LOBYTE(IVP_Hash_crctab[(unsigned __int8)~LOBYTE(pair->object0)])
                                       ^ BYTE1(pair->object0))]
     ^ ((IVP_Hash_crctab[(unsigned __int8)~LOBYTE(pair->object0)] ^ 0xFFFFFF) >> 8);
  v3 = IVP_Hash_crctab[(unsigned __int8)(v2 ^ BYTE2(pair->object0))] ^ (v2 >> 8);
  return IVP_Hash_crctab[(unsigned __int8)(v3 ^ HIBYTE(pair->object0))] ^ (v3 >> 8) | 0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x1007F5A0
// Name: public: void IVP_Collision_Filter_Exclusive_Pair::disable_collision_between_objects(class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Collision_Filter_Exclusive_Pair::disable_collision_between_objects(
        IVP_Collision_Filter_Exclusive_Pair *this,
        IVP_Real_Object *obj0,
        IVP_Real_Object *obj1)
{
  IVP_CFEP_Objectpair *v4; // esi
  IVP_CFEP_Hash *hash_table; // edi
  unsigned int v6; // eax
  IVP_CFEP_Hash *v7; // edi
  unsigned int v8; // eax

  v4 = (IVP_CFEP_Objectpair *)p_malloc(size: 8u);
  if ( obj1 <= obj0 )
  {
    v4->object0 = obj1;
    v4->object1 = obj0;
  }
  else
  {
    v4->object0 = obj0;
    v4->object1 = obj1;
  }
  hash_table = this->hash_table;
  v6 = IVP_CFEP_Hash::pair_to_index(this: hash_table, pair: v4);
  if ( IVP_VHash::find_elem(this: hash_table, elem: v4, hash_index: v6) != nullptr )
  {
    free(data: v4);
  }
  else
  {
    v7 = this->hash_table;
    v8 = IVP_CFEP_Hash::pair_to_index(this: v7, pair: v4);
    IVP_VHash::add_elem(this: v7, elem: v4, hash_index: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F610
// Name: public: void IVP_Collision_Filter_Exclusive_Pair::enable_collision_between_objects(class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Collision_Filter_Exclusive_Pair::enable_collision_between_objects(
        IVP_Collision_Filter_Exclusive_Pair *this,
        IVP_Real_Object *obj0,
        IVP_Real_Object *obj1)
{
  IVP_Real_Object *v4; // edx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  void *v10; // eax
  IVP_CFEP_Objectpair old_pair; // [esp+4h] [ebp-8h] BYREF

  if ( obj1 <= obj0 )
  {
    v4 = obj1;
    old_pair.object1 = obj0;
  }
  else
  {
    v4 = obj0;
    old_pair.object1 = obj1;
  }
  v5 = IVP_Hash_crctab[(unsigned __int8)~(_BYTE)v4];
  old_pair.object0 = v4;
  v6 = IVP_Hash_crctab[(unsigned __int8)(~(_BYTE)v5 ^ BYTE1(v4))] ^ ((v5 ^ 0xFFFFFF) >> 8);
  v7 = IVP_Hash_crctab[(unsigned __int8)(v6 ^ BYTE2(v4))] ^ (v6 >> 8);
  if ( IVP_VHash::find_elem(
         this: this->hash_table,
         elem: &old_pair,
         hash_index: IVP_Hash_crctab[(unsigned __int8)(v7 ^ HIBYTE(v4))] ^ (v7 >> 8) | 0x80000000) != nullptr )
  {
    v8 = IVP_Hash_crctab[(unsigned __int8)(~LOBYTE(IVP_Hash_crctab[(unsigned __int8)~LOBYTE(old_pair.object0)])
                                         ^ BYTE1(old_pair.object0))]
       ^ ((IVP_Hash_crctab[(unsigned __int8)~LOBYTE(old_pair.object0)] ^ 0xFFFFFF) >> 8);
    v9 = IVP_Hash_crctab[(unsigned __int8)(v8 ^ BYTE2(old_pair.object0))] ^ (v8 >> 8);
    v10 = IVP_VHash::remove_elem(
            this: this->hash_table,
            elem: &old_pair,
            hash_index: IVP_Hash_crctab[(unsigned __int8)(v9 ^ HIBYTE(old_pair.object0))] ^ (v9 >> 8) | 0x80000000);
    free(data: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F720
// Name: public: virtual enum IVP_BOOL IVP_Collision_Filter_Exclusive_Pair::check_objects_for_collision_detection(class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_Collision_Filter_Exclusive_Pair::check_objects_for_collision_detection(
        IVP_Collision_Filter_Exclusive_Pair *this,
        IVP_Real_Object *obj0,
        IVP_Real_Object *obj1)
{
  IVP_Real_Object *v3; // edx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  IVP_CFEP_Objectpair pair; // [esp+4h] [ebp-8h] BYREF

  if ( obj1 <= obj0 )
  {
    v3 = obj1;
    pair.object1 = obj0;
  }
  else
  {
    v3 = obj0;
    pair.object1 = obj1;
  }
  v4 = IVP_Hash_crctab[(unsigned __int8)~(_BYTE)v3];
  pair.object0 = v3;
  v5 = IVP_Hash_crctab[(unsigned __int8)(~(_BYTE)v4 ^ BYTE1(v3))] ^ ((v4 ^ 0xFFFFFF) >> 8);
  v6 = IVP_Hash_crctab[(unsigned __int8)(v5 ^ BYTE2(v3))] ^ (v5 >> 8);
  return IVP_VHash::find_elem(
           this: this->hash_table,
           elem: &pair,
           hash_index: IVP_Hash_crctab[(unsigned __int8)(v6 ^ HIBYTE(v3))] ^ (v6 >> 8) | 0x80000000) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007F7C0
// Name: public: virtual void IVP_Collision_Filter_Exclusive_Pair::environment_will_be_deleted(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Collision_Filter_Exclusive_Pair::environment_will_be_deleted(
        IVP_Collision_Filter_Exclusive_Pair *this,
        IVP_Environment *__formal)
{
  if ( this != nullptr )
    ((void (__thiscall *)(IVP_Collision_Filter_Exclusive_Pair *, int))this->dtr_IVP_Collision_Filter)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1007F7D0
// Name: public: virtual IVP_Collision_Filter_Exclusive_Pair::~IVP_Collision_Filter_Exclusive_Pair(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Collision_Filter_Exclusive_Pair::~IVP_Collision_Filter_Exclusive_Pair(
        IVP_Collision_Filter_Exclusive_Pair *this)
{
  IVP_CFEP_Hash *hash_table; // ecx

  hash_table = this->hash_table;
  this->__vftable = (IVP_Collision_Filter_Exclusive_Pair_vtbl *)&IVP_Collision_Filter_Exclusive_Pair::`vftable';
  if ( hash_table != nullptr )
    ((void (__thiscall *)(IVP_CFEP_Hash *, int))hash_table->dtr_IVP_VHash)(a1: hash_table, a2: 1);
  this->__vftable = (IVP_Collision_Filter_Exclusive_Pair_vtbl *)&IVP_Collision_Filter::`vftable';
  this->hash_table = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007F800
// Name: public: virtual IVP_CFEP_Hash::~IVP_CFEP_Hash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_CFEP_Hash::~IVP_CFEP_Hash(IVP_CFEP_Hash *this)
{
  int size_mm; // esi
  int v3; // ebx
  bool v4; // zf
  void *elem; // eax

  size_mm = this->size_mm;
  v3 = 0;
  v4 = (*((_DWORD *)&this->IVP_VHash + 2) & 0xFFFFFF) == 0;
  this->__vftable = (IVP_CFEP_Hash_vtbl *)&IVP_CFEP_Hash::`vftable';
  if ( !v4 )
  {
    do
    {
      if ( size_mm < 0 )
      {
LABEL_5:
        elem = nullptr;
      }
      else
      {
        while ( 1 )
        {
          elem = (void *)this->elems[size_mm--].elem;
          if ( elem != nullptr )
            break;
          if ( size_mm < 0 )
            goto LABEL_5;
        }
      }
      free(data: elem);
      ++v3;
    }
    while ( v3 < (*((_DWORD *)&this->IVP_VHash + 2) & 0xFFFFFF) );
  }
  IVP_VHash::~IVP_VHash(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007F860
// Name: public: IVP_Collision_Filter_Exclusive_Pair::IVP_Collision_Filter_Exclusive_Pair(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Collision_Filter_Exclusive_Pair *__thiscall IVP_Collision_Filter_Exclusive_Pair::IVP_Collision_Filter_Exclusive_Pair(
        IVP_Collision_Filter_Exclusive_Pair *this)
{
  IVP_VHash *v2; // eax
  IVP_CFEP_Hash *v3; // edi

  this->__vftable = (IVP_Collision_Filter_Exclusive_Pair_vtbl *)&IVP_Collision_Filter_Exclusive_Pair::`vftable';
  v2 = (IVP_VHash *)p_malloc(size: 0x10u);
  v3 = (IVP_CFEP_Hash *)v2;
  if ( v2 != nullptr )
  {
    IVP_VHash::IVP_VHash(this: v2, size_i: 1024);
    v3->__vftable = (IVP_CFEP_Hash_vtbl *)&IVP_CFEP_Hash::`vftable';
    this->hash_table = v3;
  }
  else
  {
    this->hash_table = nullptr;
  }
  return this;
}
