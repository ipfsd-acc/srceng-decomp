// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/squirrel/sqclass.cpp
// Functions: 16
// ============================================================

#include "vscript\languages\squirrel\squirrel\sqclass.h"

//------------------------------------------------------------------------------
// Address: 0x1003CF60
// Name: public: void SQClass::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQClass::Lock(SQClass *this@<ecx>, int a2@<eax>)
{
  int *i; // eax
  int v3; // eax

  *(_BYTE *)(a2 + 84) = 1;
  for ( i = (int *)(a2 + 28); *i != 0; i = (int *)(v3 + 28) )
  {
    v3 = *i;
    *(_BYTE *)(v3 + 84) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CF80
// Name: public: virtual void SQClass::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQClass::Release(SQClass *this)
{
  int (__cdecl *hook)(void *, int); // eax

  hook = this->_hook;
  if ( hook != nullptr )
    hook(a1: this->_typetag, a2: 0);
  ((void (__thiscall *)(SQClass *, _DWORD))this->dtr_SQRefCounted)(a1: this, a2: 0);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1003CFC0
// Name: public: virtual void SQInstance::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQInstance::Release(SQInstance *this)
{
  int (__cdecl *hook)(void *, int); // eax

  hook = this->_hook;
  ++this->_uiRef;
  if ( hook != nullptr )
    hook(a1: this->_userpointer, a2: 0);
  if ( --this->_uiRef <= 0 )
  {
    ((void (__thiscall *)(SQInstance *, _DWORD))this->dtr_SQRefCounted)(a1: this, a2: 0);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D000
// Name: public: SQClass::SQClass(struct SQSharedState __near *,struct SQClass __near *)
// Source: json
//------------------------------------------------------------------------------
SQClass *__thiscall SQClass::SQClass(SQClass *this, SQClass *ss, SQSharedState *base, SQClass *basea)
{
  sqvector<SQClassMember> *v4; // ecx
  SQTable *v5; // eax
  SQClass *v6; // ecx
  SQCollectable *type; // eax
  tagSQObjectType gc_chain; // edx
  tagSQObjectType v9; // eax
  SQObjectPtr fill; // [esp+10h] [ebp-8h] BYREF

  ss->__vftable = (SQClass_vtbl *)&SQClass::`vftable';
  ss->_uiRef = 0;
  ss->_weakref = nullptr;
  ss->_defaultvalues._vals = nullptr;
  ss->_defaultvalues._size = 0;
  ss->_defaultvalues._allocated = 0;
  ss->_methods._vals = nullptr;
  ss->_methods._size = 0;
  ss->_methods._allocated = 0;
  ss->_metamethods._vals = nullptr;
  ss->_metamethods._size = 0;
  ss->_metamethods._allocated = 0;
  ss->_attributes._type = OT_NULL;
  ss->_attributes._unVal.nInteger = 0;
  ss->_base = basea;
  ss->_typetag = nullptr;
  ss->_hook = nullptr;
  ss->_udsize = 0;
  fill._type = OT_NULL;
  fill._unVal.nInteger = 0;
  sqvector<SQObjectPtr>::resize(this: (sqvector<SQObjectPtr> *)basea, a2: (int)&ss->_metamethods, newsize: 0x12u, &fill);
  if ( ss->_base != nullptr )
  {
    sqvector<SQClassMember>::copy(this: v4, v: &ss->_defaultvalues, va: &basea->_defaultvalues);
    sqvector<SQClassMember>::copy(this: &basea->_methods, v: &ss->_methods, va: &basea->_methods);
    sqvector<SQObjectPtr>::copy(this: &ss->_metamethods, v: &basea->_metamethods);
    ++ss->_base->_uiRef;
  }
  if ( basea != nullptr )
  {
    v5 = SQTable::Clone(this: (SQTable *)v4);
    v6 = (SQClass *)base;
  }
  else
  {
    v5 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
    fill._type = (tagSQObjectType)v5;
    if ( v5 != nullptr )
    {
      v5->_uiRef = 0;
      v5->_weakref = nullptr;
      v5->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
      SQTable::AllocNodes(this: v5, nSize: 4);
      type = (SQCollectable *)fill._type;
      v6 = (SQClass *)base;
      *(_DWORD *)(fill._type + 12) = 0;
      type[1]._prev = nullptr;
      type[1].__vftable = nullptr;
      type->_sharedstate = base;
      type->_prev = nullptr;
      type->_next = base->_gc_chain;
      gc_chain = (tagSQObjectType)base->_gc_chain;
      if ( gc_chain != 0 )
        *(_DWORD *)(gc_chain + 16) = type;
      base->_gc_chain = type;
      v5 = (SQTable *)fill._type;
    }
    else
    {
      v6 = (SQClass *)base;
    }
    v5->_delegate = nullptr;
  }
  ss->_members = v5;
  ++v5->_uiRef;
  ss->_next = nullptr;
  ss->_locked = false;
  ss->_sharedstate = (SQSharedState *)v6;
  ss->_prev = nullptr;
  ss->_next = (SQCollectable *)v6->_attributes._type;
  v9 = v6->_attributes._type;
  if ( v9 != 0 )
    *(_DWORD *)(v9 + 16) = ss;
  v6->_attributes._type = (tagSQObjectType)ss;
  return ss;
}

//------------------------------------------------------------------------------
// Address: 0x1003D180
// Name: public: virtual void SQClass::Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQClass::Finalize(SQClass *this)
{
  _DWORD *v2; // ecx
  tagSQObjectType type; // eax
  tagSQObjectType v4; // edx
  int *pTable; // ecx
  int *v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  SQTable *members; // eax
  SQClass *base; // eax
  SQClassMember fill; // [esp+10h] [ebp-10h] BYREF

  v2 = &this->_attributes._unVal.pTable->__vftable;
  type = this->_attributes._type;
  this->_attributes._unVal.nInteger = _null_._unVal.nInteger;
  v4 = _null_._type;
  this->_attributes._type = _null_._type;
  if ( (v4 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_attributes._unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v2[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v2 + 8))(a1: v2);
  fill.val._type = OT_NULL;
  fill.attrs._type = OT_NULL;
  fill.val._unVal.nInteger = 0;
  fill.attrs._unVal.nInteger = 0;
  sqvector<SQClassMember>::resize(&fill, this: &this->_defaultvalues, newsize: 0);
  if ( (fill.attrs._type & 0x8000000) != 0 )
  {
    pTable = (int *)fill.attrs._unVal.pTable;
    --*(_DWORD *)(fill.attrs._unVal.nInteger + 4);
    if ( pTable[1] <= 0 )
      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
  if ( (fill.val._type & 0x8000000) != 0 )
  {
    v6 = (int *)fill.val._unVal.pTable;
    --*(_DWORD *)(fill.val._unVal.nInteger + 4);
    if ( v6[1] <= 0 )
      (*(void (__thiscall **)(int *))(*v6 + 8))(a1: v6);
  }
  fill.val._type = OT_NULL;
  fill.attrs._type = OT_NULL;
  fill.val._unVal.nInteger = 0;
  fill.attrs._unVal.nInteger = 0;
  sqvector<SQClassMember>::resize(&fill, this: &this->_methods, newsize: 0);
  if ( (fill.attrs._type & 0x8000000) != 0 )
  {
    v7 = (int *)fill.attrs._unVal.pTable;
    --*(_DWORD *)(fill.attrs._unVal.nInteger + 4);
    if ( v7[1] <= 0 )
      (*(void (__thiscall **)(int *))(*v7 + 8))(a1: v7);
  }
  if ( (fill.val._type & 0x8000000) != 0 )
  {
    v8 = (int *)fill.val._unVal.pTable;
    --*(_DWORD *)(fill.val._unVal.nInteger + 4);
    if ( v8[1] <= 0 )
      (*(void (__thiscall **)(int *))(*v8 + 8))(a1: v8);
  }
  fill.val._type = OT_NULL;
  fill.val._unVal.nInteger = 0;
  sqvector<SQObjectPtr>::resize(
    this: (sqvector<SQObjectPtr> *)&fill,
    a2: (int)&this->_metamethods,
    newsize: 0,
    fill: &fill.val);
  members = this->_members;
  if ( members != nullptr )
  {
    if ( --members->_uiRef <= 0 )
      this->_members->Release(this: this->_members);
    this->_members = nullptr;
  }
  base = this->_base;
  if ( base != nullptr )
  {
    if ( --base->_uiRef <= 0 )
      this->_base->Release(this: this->_base);
    this->_base = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D2F0
// Name: public: virtual SQClass::~SQClass(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQClass::~SQClass(SQClass *this@<ecx>, int a2@<esi>)
{
  bool v2; // zf
  int v3; // ecx
  int v4; // eax
  sqvector<SQObjectPtr> *v5; // ecx
  int v6; // eax
  sqvector<SQClassMember> *v7; // ecx
  sqvector<SQClassMember> *v8; // ecx
  int v9; // eax

  v2 = (*(_DWORD *)(a2 + 4) & 0x40000000) == 0;
  *(_DWORD *)a2 = &SQClass::`vftable';
  if ( v2 )
  {
    v3 = *(_DWORD *)(a2 + 16);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 12) = *(_DWORD *)(a2 + 12);
    else
      *(_DWORD *)(*(_DWORD *)(a2 + 20) + 68) = *(_DWORD *)(a2 + 12);
    v4 = *(_DWORD *)(a2 + 12);
    if ( v4 != 0 )
      *(_DWORD *)(v4 + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 16) = 0;
  }
  SQClass::Finalize(this: (SQClass *)a2);
  if ( (*(_DWORD *)(a2 + 68) & 0x8000000) != 0 )
  {
    v6 = *(_DWORD *)(a2 + 72);
    if ( (int)--*(_DWORD *)(v6 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 72) + 8))(a1: *(_DWORD *)(a2 + 72));
  }
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>(this: v5, a2: a2 + 56);
  sqvector<SQClassMember>::~sqvector<SQClassMember>(this: v7, a2: a2 + 44);
  sqvector<SQClassMember>::~sqvector<SQClassMember>(this: v8, a2: a2 + 32);
  v9 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)a2 = &SQRefCounted::`vftable';
  if ( v9 != 0 )
  {
    *(_DWORD *)(v9 + 12) = 16777217;
    *(_DWORD *)(*(_DWORD *)(a2 + 8) + 16) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D3A0
// Name: public: bool SQClass::NewSlot(struct SQSharedState __near *,struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQClass::NewSlot@<al>(
        SQClass *this@<ecx>,
        int a2@<eax>,
        SQSharedState *ss,
        const SQObjectPtr *key,
        const SQObjectPtr *val,
        bool bstatic)
{
  bool v7; // zf
  bool v9; // al
  tagSQObjectValue v10; // esi
  SQObjectPtr *v11; // esi
  SQTable *v12; // ecx
  SQClassMember *v13; // ecx
  int MetaMethodIdxByName; // eax
  SQTable *v15; // ecx
  int v16; // eax
  sqvector<SQClassMember> *v17; // ecx
  _DWORD *v18; // eax
  SQClassMember *v19; // ecx
  int *pTable; // ecx
  SQClassMember m; // [esp+10h] [ebp-20h] BYREF
  int v22; // [esp+20h] [ebp-10h] BYREF
  _DWORD *v23; // [esp+24h] [ebp-Ch]
  SQObjectPtr temp; // [esp+28h] [ebp-8h] BYREF

  v7 = *(_BYTE *)(a2 + 84) == 0;
  temp._type = OT_NULL;
  temp._unVal.nInteger = 0;
  if ( !v7 )
    return 0;
  v9 = SQTable::Get(this: *(SQTable **)(a2 + 24), key, val: &temp);
  v10.pTable = (SQTable *)temp._unVal;
  if ( v9 && (temp._unVal.nInteger & 0x2000000) != 0 )
  {
    v11 = (SQObjectPtr *)(*(_DWORD *)(a2 + 32) + 16 * (temp._unVal.nInteger & 0xFFFFFF));
  }
  else
  {
    if ( val->_type == OT_CLOSURE || val->_type == OT_NATIVECLOSURE )
    {
      MetaMethodIdxByName = SQSharedState::GetMetaMethodIdxByName(this: ss, name: key);
      if ( MetaMethodIdxByName != -1 )
      {
        v11 = (SQObjectPtr *)(*(_DWORD *)(a2 + 56) + 8 * MetaMethodIdxByName);
        goto LABEL_19;
      }
    }
    else if ( !bstatic )
    {
      m.val._type = OT_NULL;
      m.attrs._type = OT_NULL;
      m.val._unVal.nInteger = 0;
      m.attrs._unVal.nInteger = 0;
      SQObjectPtr::operator=(this: &m.val, obj: val);
      v23 = (_DWORD *)(*(_DWORD *)(a2 + 36) | 0x2000000);
      v12 = *(SQTable **)(a2 + 24);
      v22 = 83886082;
      SQTable::NewSlot(this: v12, key, val: (const SQObjectPtr *)&v22);
      SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&v22);
      sqvector<SQClassMember>::push_back(this: (sqvector<SQClassMember> *)&m, a2: a2 + 32, val: &m);
      SQClassMember::~SQClassMember(this: v13, a2: &m);
      SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&temp);
      return 1;
    }
    if ( temp._type == OT_NULL )
    {
      m.val._type = OT_NULL;
      m.attrs._type = OT_NULL;
      m.val._unVal.nInteger = 0;
      m.attrs._unVal.nInteger = 0;
      SQObjectPtr::operator=(this: &m.val, obj: val);
      v15 = *(SQTable **)(a2 + 24);
      v16 = *(_DWORD *)(a2 + 48) | 0x1000000;
      v22 = 83886082;
      v23 = (_DWORD *)v16;
      SQTable::NewSlot(this: v15, key, val: (const SQObjectPtr *)&v22);
      if ( (v22 & 0x8000000) != 0 )
      {
        v18 = v23;
        --v23[1];
        if ( (int)v18[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v23 + 8))(a1: v23);
      }
      sqvector<SQClassMember>::push_back(this: v17, a2: a2 + 44, val: &m);
      SQClassMember::~SQClassMember(this: v19, a2: &m);
      goto LABEL_20;
    }
    v11 = (SQObjectPtr *)(*(_DWORD *)(a2 + 44) + 16 * (v10.nInteger & 0xFFFFFF));
  }
LABEL_19:
  SQObjectPtr::operator=(this: v11, obj: val);
LABEL_20:
  if ( (temp._type & 0x8000000) != 0 )
  {
    pTable = (int *)temp._unVal.pTable;
    --*(_DWORD *)(temp._unVal.nInteger + 4);
    if ( pTable[1] <= 0 )
      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003D560
// Name: public: struct SQInstance __near * SQClass::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
SQInstance *__usercall SQClass::CreateInstance@<eax>(SQClass *this@<ecx>, SQClass *a2@<eax>)
{
  int base; // eax
  unsigned int size; // eax
  SQSharedState *sharedstate; // ebx
  unsigned int v6; // eax
  int v7; // edi
  SQInstance *result; // eax
  int udsize; // esi

  if ( !a2->_locked )
  {
    base = (int)a2->_base;
    a2->_locked = true;
    if ( base != 0 )
      SQClass::Lock(this, a2: base);
  }
  size = a2->_defaultvalues._size;
  sharedstate = a2->_sharedstate;
  if ( size != 0 )
    v6 = size - 1;
  else
    v6 = 0;
  v7 = a2->_udsize + 8 * v6 + 52;
  result = (SQInstance *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  if ( result != nullptr )
    result = SQInstance::SQInstance(this: result, ss: sharedstate, c: a2, memsize: v7);
  udsize = a2->_udsize;
  if ( udsize != 0 )
    result->_userpointer = (char *)result + v7 - udsize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003D5D0
// Name: public: int SQClass::Next(struct SQObjectPtr const __near &,struct SQObjectPtr __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge SQClass::Next@<eax>(
        SQObjectPtr *outkey@<edx>,
        SQObjectPtr *outval@<eax>,
        SQClass *this,
        const SQObjectPtr *refpos)
{
  int v6; // eax
  _DWORD *v7; // ebx
  int v8; // eax
  SQClassMember *v9; // eax
  _DWORD *v10; // ecx
  tagSQObjectValue v11; // edx
  tagSQObjectType type; // edi
  tagSQObjectType v13; // eax
  bool v14; // zf
  SQClassMember *v15; // eax
  SQObjectPtr *p_val; // eax
  tagSQObjectValue v17; // edi
  tagSQObjectType v18; // edx
  tagSQObjectType v19; // eax
  SQTable *members; // [esp-Ch] [ebp-2Ch]
  SQObjectPtr val; // [esp+10h] [ebp-10h] BYREF
  SQObjectPtr oval; // [esp+18h] [ebp-8h] BYREF
  int idx; // [esp+28h] [ebp+8h]

  members = this->_members;
  oval._type = OT_NULL;
  oval._unVal.nInteger = 0;
  v6 = SQTable::Next(this: members, getweakrefs: false, refpos, outkey, outval: &oval);
  v7 = &oval._unVal.pTable->__vftable;
  idx = v6;
  if ( v6 != -1 )
  {
    v8 = oval._unVal.nInteger & 0xFFFFFF;
    if ( (oval._unVal.nInteger & 0x1000000) != 0 )
    {
      v9 = &this->_methods._vals[v8];
      v10 = &outval->_unVal.pTable->__vftable;
      v11.pTable = (SQTable *)v9->val._unVal;
      type = outval->_type;
      outval->_unVal = v11;
      v13 = v9->val._type;
      outval->_type = v13;
      if ( (v13 & 0x8000000) != 0 )
        ++*(_DWORD *)(v11.nInteger + 4);
      v14 = (type & 0x8000000) == 0;
    }
    else
    {
      v15 = &this->_defaultvalues._vals[v8];
      if ( v15->val._type == OT_WEAKREF )
      {
        p_val = (SQObjectPtr *)(v15->val._unVal.nInteger + 12);
      }
      else
      {
        val = v15->val;
        p_val = &val;
      }
      v17.pTable = (SQTable *)p_val->_unVal;
      v10 = &outval->_unVal.pTable->__vftable;
      v18 = outval->_type;
      outval->_unVal = v17;
      v19 = p_val->_type;
      outval->_type = v19;
      if ( (v19 & 0x8000000) != 0 )
        ++*(_DWORD *)(v17.nInteger + 4);
      v14 = (v18 & 0x8000000) == 0;
    }
    if ( !v14 && (int)--v10[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  }
  if ( (oval._type & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return idx;
}

//------------------------------------------------------------------------------
// Address: 0x1003D6C0
// Name: public: bool SQClass::SetAttributes(struct SQObjectPtr const __near &,struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQClass::SetAttributes@<al>(const SQObjectPtr *val@<eax>, SQClass *this, const SQObjectPtr *key)
{
  _DWORD *v4; // esi
  SQClassMember *vals; // edx
  tagSQObjectValue v6; // ebx
  SQObjectPtr *p_attrs; // eax
  _DWORD *v8; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v10; // edi
  SQClassMember *v11; // ecx
  tagSQObjectValue v12; // ebx
  tagSQObjectType v13; // edx
  SQObjectPtr *v14; // eax
  tagSQObjectType v15; // edi
  int *pTable; // ecx
  SQTable *members; // [esp-4h] [ebp-1Ch]
  SQObjectPtr idx; // [esp+10h] [ebp-8h] BYREF

  members = this->_members;
  idx._type = OT_NULL;
  idx._unVal.nInteger = 0;
  if ( SQTable::Get(this: members, key, val: &idx) )
  {
    v4 = &idx._unVal.pTable->__vftable;
    if ( (idx._unVal.nInteger & 0x2000000) != 0 )
    {
      vals = this->_defaultvalues._vals;
      v6.pTable = (SQTable *)val->_unVal;
      p_attrs = &vals[idx._unVal.nInteger & 0xFFFFFF].attrs;
      v8 = &vals[idx._unVal.nInteger & 0xFFFFFF].attrs._unVal.pTable->__vftable;
      type = p_attrs->_type;
      p_attrs->_unVal = v6;
      v10 = val->_type;
      p_attrs->_type = v10;
      if ( (v10 & 0x8000000) != 0 )
        ++*(_DWORD *)(v6.nInteger + 4);
      if ( (type & 0x8000000) == 0 )
        goto LABEL_13;
      if ( (int)--v8[1] > 0 )
        goto LABEL_13;
    }
    else
    {
      v11 = this->_methods._vals;
      v12.pTable = (SQTable *)val->_unVal;
      v13 = v11[idx._unVal.nInteger & 0xFFFFFF].attrs._type;
      v14 = &v11[idx._unVal.nInteger & 0xFFFFFF].attrs;
      v8 = &v11[idx._unVal.nInteger & 0xFFFFFF].attrs._unVal.pTable->__vftable;
      v14->_unVal = v12;
      v15 = val->_type;
      v14->_type = v15;
      if ( (v15 & 0x8000000) != 0 )
        ++*(_DWORD *)(v12.nInteger + 4);
      if ( (v13 & 0x8000000) == 0 )
        goto LABEL_13;
      if ( (int)--v8[1] > 0 )
        goto LABEL_13;
    }
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
LABEL_13:
    if ( (idx._type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
    return 1;
  }
  if ( (idx._type & 0x8000000) != 0 )
  {
    pTable = (int *)idx._unVal.pTable;
    --*(_DWORD *)(idx._unVal.nInteger + 4);
    if ( pTable[1] <= 0 )
      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003D7E0
// Name: public: bool SQClass::GetAttributes(struct SQObjectPtr const __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQClass::GetAttributes@<al>(SQObjectPtr *outval@<eax>, SQClass *this, const SQObjectPtr *key)
{
  _DWORD *v4; // esi
  SQObjectPtr *p_attrs; // eax
  tagSQObjectValue v6; // ebx
  _DWORD *v7; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v9; // eax
  int *pTable; // ecx
  SQTable *members; // [esp-4h] [ebp-1Ch]
  SQObjectPtr idx; // [esp+10h] [ebp-8h] BYREF

  members = this->_members;
  idx._type = OT_NULL;
  idx._unVal.nInteger = 0;
  if ( SQTable::Get(this: members, key, val: &idx) )
  {
    v4 = &idx._unVal.pTable->__vftable;
    if ( (idx._unVal.nInteger & 0x2000000) != 0 )
      p_attrs = &this->_defaultvalues._vals[idx._unVal.nInteger & 0xFFFFFF].attrs;
    else
      p_attrs = &this->_methods._vals[idx._unVal.nInteger & 0xFFFFFF].attrs;
    v6.pTable = (SQTable *)p_attrs->_unVal;
    v7 = &outval->_unVal.pTable->__vftable;
    type = outval->_type;
    outval->_unVal = v6;
    v9 = p_attrs->_type;
    outval->_type = v9;
    if ( (v9 & 0x8000000) != 0 )
      ++*(_DWORD *)(v6.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v7[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
    if ( (idx._type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
    return 1;
  }
  else
  {
    if ( (idx._type & 0x8000000) != 0 )
    {
      pTable = (int *)idx._unVal.pTable;
      --*(_DWORD *)(idx._unVal.nInteger + 4);
      if ( pTable[1] <= 0 )
        (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D8D0
// Name: public: SQInstance::SQInstance(struct SQSharedState __near *,struct SQClass __near *,int)
// Source: json
//------------------------------------------------------------------------------
SQInstance *__userpurge SQInstance::SQInstance@<eax>(
        SQInstance *this@<eax>,
        SQClass *c@<ecx>,
        SQSharedState *ss,
        int memsize)
{
  SQSharedState *v4; // esi
  SQObjectPtr *values; // edx
  unsigned int size; // ecx
  int v7; // esi
  SQClassMember *vals; // ecx
  tagSQObjectType type; // ebx
  tagSQObjectValue v10; // ecx
  SQClass *v11; // ecx
  SQTable *members; // ecx
  SQCollectable *gc_chain; // ecx
  int memsizea; // [esp+18h] [ebp+Ch]

  v4 = ss;
  this->_uiRef = 0;
  this->_weakref = nullptr;
  this->__vftable = (SQInstance_vtbl *)&SQInstance::`vftable';
  values = this->_values;
  this->_values[0]._type = OT_NULL;
  this->_values[0]._unVal.nInteger = 0;
  this->_memsize = memsize;
  this->_class = c;
  size = c->_defaultvalues._size;
  if ( size != 0 )
  {
    v7 = 0;
    for ( memsizea = size; memsizea != 0; --memsizea )
    {
      if ( values != nullptr )
      {
        vals = this->_class->_defaultvalues._vals;
        type = vals[v7].val._type;
        values->_type = type;
        v10.pTable = (SQTable *)vals[v7].val._unVal;
        values->_unVal = v10;
        if ( (type & 0x8000000) != 0 )
          ++*(_DWORD *)(v10.nInteger + 4);
      }
      ++values;
      ++v7;
    }
    v4 = ss;
  }
  v11 = this->_class;
  this->_userpointer = nullptr;
  this->_hook = nullptr;
  ++v11->_uiRef;
  members = this->_class->_members;
  this->_next = nullptr;
  this->_delegate = members;
  this->_sharedstate = v4;
  this->_prev = nullptr;
  this->_next = v4->_gc_chain;
  gc_chain = v4->_gc_chain;
  if ( gc_chain != nullptr )
    gc_chain->_prev = this;
  v4->_gc_chain = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D9A0
// Name: public: SQInstance::SQInstance(struct SQSharedState __near *,struct SQInstance __near *,int)
// Source: json
//------------------------------------------------------------------------------
SQInstance *__userpurge SQInstance::SQInstance@<eax>(
        SQInstance *this@<eax>,
        int memsize@<edx>,
        SQSharedState *ss,
        SQInstance *i)
{
  SQObjectPtr *values; // ecx
  SQClass *v5; // edx
  unsigned int size; // edx
  int v7; // edi
  bool v8; // zf
  tagSQObjectValue v9; // esi
  SQClass *v10; // ecx
  SQCollectable *gc_chain; // ecx

  this->_uiRef = 0;
  this->_weakref = nullptr;
  this->__vftable = (SQInstance_vtbl *)&SQInstance::`vftable';
  values = this->_values;
  this->_values[0]._type = OT_NULL;
  this->_values[0]._unVal.nInteger = 0;
  this->_memsize = memsize;
  v5 = i->_class;
  this->_class = v5;
  size = v5->_defaultvalues._size;
  if ( size != 0 )
  {
    v7 = (char *)i - (char *)this;
    do
    {
      if ( values != nullptr )
      {
        values->_type = *(tagSQObjectType *)((char *)&values->_type + v7);
        v8 = (values->_type & 0x8000000) == 0;
        v9.pTable = *(SQTable **)((char *)&values->_unVal + v7);
        values->_unVal = v9;
        if ( !v8 )
          ++*(_DWORD *)(v9.nInteger + 4);
      }
      ++values;
      --size;
    }
    while ( size != 0 );
  }
  v10 = this->_class;
  this->_userpointer = nullptr;
  this->_hook = nullptr;
  ++v10->_uiRef;
  this->_delegate = this->_class->_members;
  this->_next = nullptr;
  this->_prev = nullptr;
  this->_sharedstate = ss;
  this->_next = ss->_gc_chain;
  gc_chain = ss->_gc_chain;
  if ( gc_chain != nullptr )
    gc_chain->_prev = this;
  ss->_gc_chain = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003DA40
// Name: public: virtual void SQInstance::Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQInstance::Finalize(SQInstance *this)
{
  SQClass *v2; // eax
  unsigned int size; // edi
  tagSQObjectValue *p_unVal; // esi
  _DWORD *nInteger; // ecx
  tagSQObjectValue v6; // edx
  tagSQObjectType type; // eax

  v2 = this->_class;
  size = v2->_defaultvalues._size;
  if ( v2 != nullptr )
  {
    if ( --v2->_uiRef <= 0 )
      this->_class->Release(this: this->_class);
    this->_class = nullptr;
  }
  if ( size != 0 )
  {
    p_unVal = &this->_values[0]._unVal;
    do
    {
      nInteger = (_DWORD *)p_unVal->nInteger;
      v6.pTable = p_unVal[-1].pTable;
      p_unVal->pTable = (SQTable *)_null_._unVal;
      type = _null_._type;
      p_unVal[-1].pTable = (SQTable *)_null_._type;
      if ( (type & 0x8000000) != 0 )
        ++*(_DWORD *)(p_unVal->nInteger + 4);
      if ( (v6.nInteger & 0x8000000) != 0 && (int)--nInteger[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*nInteger + 8))(a1: nInteger);
      p_unVal += 2;
      --size;
    }
    while ( size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DAC0
// Name: public: virtual SQInstance::~SQInstance(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQInstance::~SQInstance(SQInstance *this@<ecx>, int a2@<esi>)
{
  bool v2; // zf
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = (*(_DWORD *)(a2 + 4) & 0x40000000) == 0;
  *(_DWORD *)a2 = &SQInstance::`vftable';
  if ( v2 )
  {
    v3 = *(_DWORD *)(a2 + 16);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 12) = *(_DWORD *)(a2 + 12);
    else
      *(_DWORD *)(*(_DWORD *)(a2 + 20) + 68) = *(_DWORD *)(a2 + 12);
    v4 = *(_DWORD *)(a2 + 12);
    if ( v4 != 0 )
      *(_DWORD *)(v4 + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 16) = 0;
  }
  if ( *(_DWORD *)(a2 + 28) != 0 )
    SQInstance::Finalize(this: (SQInstance *)a2);
  if ( (*(_DWORD *)(a2 + 44) & 0x8000000) != 0 )
  {
    v5 = *(_DWORD *)(a2 + 48);
    if ( (int)--*(_DWORD *)(v5 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 48) + 8))(a1: *(_DWORD *)(a2 + 48));
  }
  v6 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)a2 = &SQRefCounted::`vftable';
  if ( v6 != 0 )
  {
    *(_DWORD *)(v6 + 12) = 16777217;
    *(_DWORD *)(*(_DWORD *)(a2 + 8) + 16) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DB50
// Name: public: virtual bool SQInstance::GetMetaMethod(struct SQVM __near *,enum SQMetaMethod,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQInstance::GetMetaMethod(SQInstance *this, SQVM *v, SQMetaMethod mm, SQObjectPtr *res)
{
  SQObjectPtr *v4; // edx
  _DWORD *v5; // ecx
  tagSQObjectType type; // esi
  tagSQObjectValue v7; // edi
  tagSQObjectType v8; // edx

  v4 = &this->_class->_metamethods._vals[mm];
  if ( v4->_type == OT_NULL )
    return 0;
  v5 = &res->_unVal.pTable->__vftable;
  type = res->_type;
  v7.pTable = (SQTable *)v4->_unVal;
  res->_unVal = v7;
  v8 = v4->_type;
  res->_type = v8;
  if ( (v8 & 0x8000000) != 0 )
    ++*(_DWORD *)(v7.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v5[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v5 + 8))(a1: v5);
  return 1;
}
