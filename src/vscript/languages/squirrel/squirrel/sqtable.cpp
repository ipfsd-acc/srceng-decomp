// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/squirrel/sqtable.cpp
// Functions: 12
// ============================================================

#include "vscript\languages\squirrel\squirrel\sqtable.h"

//------------------------------------------------------------------------------
// Address: 0x10054B20
// Name: public: virtual SQTable::~SQTable(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQTable::~SQTable(SQTable *this@<ecx>, int a2@<edi>)
{
  int v2; // eax
  int v3; // ebx
  bool v4; // zf
  int v5; // ecx
  int v6; // eax
  _DWORD *v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int i; // [esp+4h] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 24);
  v3 = 0;
  *(_DWORD *)a2 = &SQTable::`vftable';
  if ( v2 != 0 )
  {
    if ( (int)--*(_DWORD *)(v2 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 24) + 8))(a1: *(_DWORD *)(a2 + 24));
    *(_DWORD *)(a2 + 24) = 0;
  }
  v4 = (*(_DWORD *)(a2 + 4) & 0x40000000) == 0;
  *(_DWORD *)(a2 + 24) = 0;
  if ( v4 )
  {
    v5 = *(_DWORD *)(a2 + 16);
    if ( v5 != 0 )
      *(_DWORD *)(v5 + 12) = *(_DWORD *)(a2 + 12);
    else
      *(_DWORD *)(*(_DWORD *)(a2 + 20) + 68) = *(_DWORD *)(a2 + 12);
    v6 = *(_DWORD *)(a2 + 12);
    if ( v6 != 0 )
      *(_DWORD *)(v6 + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 16) = 0;
  }
  for ( i = 0; i < *(_DWORD *)(a2 + 36); ++i )
  {
    v7 = (_DWORD *)(v3 + *(_DWORD *)(a2 + 32));
    if ( (v7[2] & 0x8000000) != 0 )
    {
      v8 = v7[3];
      if ( (int)--*(_DWORD *)(v8 + 4) <= 0 )
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v7[3] + 8))(a1: v7[3]);
    }
    if ( (*v7 & 0x8000000) != 0 )
    {
      v9 = v7[1];
      if ( (int)--*(_DWORD *)(v9 + 4) <= 0 )
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v7[1] + 8))(a1: v7[1]);
    }
    v3 += 20;
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(a2 + 32));
  v10 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)a2 = &SQRefCounted::`vftable';
  if ( v10 != 0 )
  {
    *(_DWORD *)(v10 + 12) = 16777217;
    *(_DWORD *)(*(_DWORD *)(a2 + 8) + 16) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054C50
// Name: private: SQTable::SQTable(struct SQSharedState __near *,int)
// Source: json
//------------------------------------------------------------------------------
SQTable *__userpurge SQTable::SQTable@<eax>(SQTable *this@<edi>, int nInitialSize@<eax>, SQSharedState *ss)
{
  int v3; // esi
  SQCollectable *gc_chain; // eax

  v3 = 4;
  this->_uiRef = 0;
  this->_weakref = nullptr;
  for ( this->__vftable = (SQTable_vtbl *)&SQTable::`vftable'; nInitialSize > v3; v3 *= 2 )
    ;
  SQTable::AllocNodes(this, nSize: v3);
  this->_next = nullptr;
  this->_usednodes = 0;
  this->_delegate = nullptr;
  this->_sharedstate = ss;
  this->_prev = nullptr;
  this->_next = ss->_gc_chain;
  gc_chain = ss->_gc_chain;
  if ( gc_chain != nullptr )
    gc_chain->_prev = this;
  ss->_gc_chain = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10054CB0
// Name: public: void SQTable::Remove(struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQTable::Remove(const SQObjectPtr *key@<eax>, SQTable *this)
{
  tagSQObjectType type; // edi
  int fFloat; // edx
  tagSQObjectValue *p_unVal; // ecx
  int nInteger; // ecx
  SQTable::_HashNode *v6; // esi
  _DWORD *v7; // ecx
  tagSQObjectType v8; // edx
  tagSQObjectType v9; // eax
  SQTable *pTable; // ecx
  tagSQObjectType v11; // edx
  tagSQObjectType v12; // eax

  type = key->_type;
  if ( key->_type > OT_FLOAT )
  {
    if ( type == OT_STRING )
    {
      p_unVal = &key->_unVal;
      fFloat = *(_DWORD *)(key->_unVal.nInteger + 24);
      goto LABEL_10;
    }
    goto LABEL_8;
  }
  if ( key->_type == OT_FLOAT )
  {
    p_unVal = &key->_unVal;
    fFloat = (__int64)key->_unVal.fFloat;
    goto LABEL_10;
  }
  if ( type != OT_BOOL && type != OT_INTEGER )
  {
LABEL_8:
    p_unVal = &key->_unVal;
    fFloat = key->_unVal.nInteger >> 3;
    goto LABEL_10;
  }
  fFloat = key->_unVal.nInteger;
  p_unVal = &key->_unVal;
LABEL_10:
  nInteger = p_unVal->nInteger;
  v6 = &this->_nodes[fFloat & (this->_numofnodes - 1)];
  while ( v6->key._unVal.nInteger != nInteger || v6->key._type != type )
  {
    v6 = v6->next;
    if ( v6 == nullptr )
      return;
  }
  v7 = &v6->key._unVal.pTable->__vftable;
  v8 = v6->key._type;
  v6->key._unVal.nInteger = _null_._unVal.nInteger;
  v9 = _null_._type;
  v6->key._type = _null_._type;
  if ( (v9 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6->key._unVal.nInteger + 4);
  if ( (v8 & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  pTable = v6->val._unVal.pTable;
  v11 = v6->val._type;
  v6->val._unVal.nInteger = v6->key._unVal.nInteger;
  v12 = v6->key._type;
  v6->val._type = v12;
  if ( (v12 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6->val._unVal.nInteger + 4);
  if ( (v11 & 0x8000000) != 0 && --pTable->_uiRef <= 0 )
    pTable->Release(this: pTable);
  --this->_usednodes;
  SQTable::Rehash(this: pTable, force: false);
}

//------------------------------------------------------------------------------
// Address: 0x10054DE0
// Name: private: void SQTable::AllocNodes(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQTable::AllocNodes(int nSize@<esi>, SQTable *this)
{
  SQTable *v2; // ebx
  SQTable::_HashNode *v3; // eax
  tagSQObjectValue *p_unVal; // ecx
  int i; // edx

  v2 = this;
  v3 = (SQTable::_HashNode *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 20 * nSize);
  if ( nSize > 0 )
  {
    p_unVal = &v3->val._unVal;
    for ( i = nSize; i != 0; --i )
    {
      if ( p_unVal != (tagSQObjectValue *)4 )
      {
        p_unVal[-1].nInteger = 16777217;
        p_unVal->nInteger = 0;
        p_unVal[1].nInteger = 16777217;
        p_unVal[2].nInteger = 0;
        p_unVal[3].nInteger = 0;
      }
      p_unVal[3].nInteger = 0;
      p_unVal += 5;
    }
    v2 = this;
  }
  v2->_numofnodes = nSize;
  v2->_nodes = v3;
  v2->_firstfree = &v3[nSize - 1];
}

//------------------------------------------------------------------------------
// Address: 0x10054E50
// Name: private: void SQTable::Rehash(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQTable::Rehash(SQTable *this@<ecx>, SQTable *a2@<eax>, bool force)
{
  int numofnodes; // ebx
  int v5; // esi
  int usednodes; // ecx
  const SQObjectPtr *p_key; // esi
  int v8; // ebx
  tagSQObjectValue *p_unVal; // esi
  int nInteger; // eax
  tagSQObjectValue v11; // eax
  int realoldsize; // [esp+Ch] [ebp-8h]
  SQTable::_HashNode *nold; // [esp+10h] [ebp-4h]

  numofnodes = a2->_numofnodes;
  realoldsize = numofnodes;
  v5 = 4;
  if ( numofnodes >= 4 )
    v5 = a2->_numofnodes;
  usednodes = a2->_usednodes;
  nold = a2->_nodes;
  if ( usednodes < v5 - v5 / 4 )
  {
    if ( usednodes > v5 / 4 || v5 <= 4 )
    {
      if ( !force )
        return;
    }
    else
    {
      v5 /= 2;
    }
  }
  else
  {
    v5 *= 2;
  }
  SQTable::AllocNodes(nSize: v5, this: a2);
  a2->_usednodes = 0;
  if ( numofnodes > 0 )
  {
    p_key = &nold->key;
    do
    {
      if ( p_key->_type != OT_NULL )
        SQTable::NewSlot(this: a2, key: p_key, val: p_key - 1);
      p_key = (const SQObjectPtr *)((char *)p_key + 20);
      --numofnodes;
    }
    while ( numofnodes != 0 );
    v8 = realoldsize;
    if ( realoldsize > 0 )
    {
      p_unVal = &nold->key._unVal;
      do
      {
        if ( (p_unVal[-1].nInteger & 0x8000000) != 0 )
        {
          nInteger = p_unVal->nInteger;
          if ( (int)--*(_DWORD *)(nInteger + 4) <= 0 )
            p_unVal->pTable->Release(this: (struct SQTable *)p_unVal->nInteger);
        }
        if ( (p_unVal[-3].nInteger & 0x8000000) != 0 )
        {
          v11.pTable = p_unVal[-2].pTable;
          if ( (int)--*(_DWORD *)(v11.nInteger + 4) <= 0 )
            p_unVal[-2].pTable->Release(this: (struct SQTable *)p_unVal[-2].nInteger);
        }
        p_unVal += 5;
        --v8;
      }
      while ( v8 != 0 );
    }
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: nold);
}

//------------------------------------------------------------------------------
// Address: 0x10054F50
// Name: public: struct SQTable __near * SQTable::Clone(void)
// Source: json
//------------------------------------------------------------------------------
SQTable *__thiscall SQTable::Clone(SQTable *this, SQTable *thisa)
{
  int numofnodes; // esi
  SQTable *v4; // edi
  tagSQObjectValue v5; // esi
  SQTable *delegate; // ebx
  SQTable *v7; // eax
  SQTable *v8; // eax
  tagSQObjectValue v9; // eax
  tagSQObjectValue v10; // eax
  SQObjectPtr refpos; // [esp+10h] [ebp-1Ch] BYREF
  SQObjectPtr key; // [esp+18h] [ebp-14h] BYREF
  SQObjectPtr val; // [esp+20h] [ebp-Ch] BYREF
  SQSharedState *thisb; // [esp+34h] [ebp+8h]

  numofnodes = thisa->_numofnodes;
  thisb = thisa->_sharedstate;
  v4 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
  if ( v4 != nullptr )
    SQTable::SQTable(this: v4, nInitialSize: numofnodes, ss: thisb);
  v5.nInteger = 0;
  v4->_delegate = nullptr;
  key._type = OT_NULL;
  key._unVal.nInteger = 0;
  val._type = OT_NULL;
  val._unVal.nInteger = 0;
  refpos._type = OT_INTEGER;
  while ( 1 )
  {
    refpos._unVal = v5;
    v5.nInteger = SQTable::Next(this: thisa, getweakrefs: true, &refpos, outkey: &key, outval: &val);
    if ( v5.nInteger == -1 )
      break;
    SQTable::NewSlot(this: v4, &key, &val);
  }
  delegate = thisa->_delegate;
  v7 = delegate;
  if ( delegate != v4 )
  {
    if ( delegate != nullptr )
    {
      while ( 1 )
      {
        v7 = v7->_delegate;
        if ( v7 == v4 )
          break;
        if ( v7 == nullptr )
        {
          ++delegate->_uiRef;
          goto LABEL_11;
        }
      }
    }
    else
    {
LABEL_11:
      v8 = v4->_delegate;
      if ( v8 != nullptr )
      {
        if ( --v8->_uiRef <= 0 )
          v4->_delegate->Release(this: v4->_delegate);
        v4->_delegate = nullptr;
      }
      v4->_delegate = delegate;
    }
  }
  if ( (val._type & 0x8000000) != 0 )
  {
    v9.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v9.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v10.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v10.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10055060
// Name: public: bool SQTable::Get(struct SQObjectPtr const __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQTable::Get@<al>(const SQObjectPtr *key@<eax>, SQObjectPtr *val@<esi>, SQTable *this)
{
  tagSQObjectType type; // edi
  int nInteger; // edx
  tagSQObjectValue *p_unVal; // ecx
  int v6; // ecx
  SQTable::_HashNode *v7; // eax
  __int64 *p_fFloat; // eax
  tagSQObjectValue v10; // edi
  _DWORD *v11; // ecx
  tagSQObjectType v12; // edx
  tagSQObjectType v13; // eax
  __int64 fFloat; // [esp+8h] [ebp-Ch] BYREF

  type = key->_type;
  if ( key->_type == OT_NULL )
    return 0;
  if ( type <= OT_FLOAT )
  {
    if ( type == OT_FLOAT )
    {
      p_unVal = &key->_unVal;
      fFloat = (__int64)key->_unVal.fFloat;
      nInteger = fFloat;
      goto LABEL_11;
    }
    if ( type == OT_BOOL || type == OT_INTEGER )
    {
      nInteger = key->_unVal.nInteger;
      p_unVal = &key->_unVal;
      goto LABEL_11;
    }
  }
  else if ( type == OT_STRING )
  {
    p_unVal = &key->_unVal;
    nInteger = *(_DWORD *)(key->_unVal.nInteger + 24);
LABEL_11:
    v6 = p_unVal->nInteger;
    v7 = &this->_nodes[nInteger & (this->_numofnodes - 1)];
    while ( v7->key._unVal.nInteger != v6 || v7->key._type != type )
    {
      v7 = v7->next;
      if ( v7 == nullptr )
        return 0;
    }
    if ( v7->val._type == OT_WEAKREF )
    {
      p_fFloat = (__int64 *)(v7->val._unVal.nInteger + 12);
    }
    else
    {
      fFloat = (__int64)v7->val;
      p_fFloat = &fFloat;
    }
    v10.pTable = *(SQTable **)((char *)p_fFloat + 4);
    v11 = &val->_unVal.pTable->__vftable;
    v12 = val->_type;
    val->_unVal = v10;
    v13 = *(_DWORD *)p_fFloat;
    val->_type = v13;
    if ( (v13 & 0x8000000) != 0 )
      ++*(_DWORD *)(v10.nInteger + 4);
    if ( (v12 & 0x8000000) != 0 && (int)--v11[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
    return 1;
  }
  p_unVal = &key->_unVal;
  nInteger = key->_unVal.nInteger >> 3;
  goto LABEL_11;
}

//------------------------------------------------------------------------------
// Address: 0x10055170
// Name: public: bool SQTable::NewSlot(struct SQObjectPtr const __near &,struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQTable::NewSlot(SQTable *this, const SQObjectPtr *key, const SQObjectPtr *val)
{
  SQTable *v3; // edx
  const SQObjectPtr *v4; // esi
  tagSQObjectType type; // ebx
  int fFloat; // ecx
  unsigned int v7; // edi
  int *v8; // eax
  int v9; // eax
  SQTable::_HashNode *firstfree; // edx
  int v11; // ecx
  SQTable::_HashNode *v12; // eax
  SQTable *v13; // ecx
  int v14; // ebx
  tagSQObjectType v15; // eax
  SQTable::_HashNode *v16; // eax
  tagSQObjectValue v17; // edi
  _DWORD *v18; // ecx
  int v19; // esi
  tagSQObjectType v20; // edx
  tagSQObjectValue v22; // ebx
  _DWORD *v23; // ecx
  int v24; // esi
  tagSQObjectType v25; // eax
  SQTable::_HashNode *n; // [esp+14h] [ebp-Ch]

  v3 = this;
LABEL_2:
  v4 = key;
  type = key->_type;
  if ( key->_type > OT_FLOAT )
  {
    if ( type == OT_STRING )
    {
      fFloat = *(_DWORD *)(key->_unVal.nInteger + 24);
      goto LABEL_11;
    }
    goto LABEL_9;
  }
  if ( key->_type == OT_FLOAT )
  {
    fFloat = (__int64)key->_unVal.fFloat;
    goto LABEL_11;
  }
  if ( type != OT_BOOL && type != OT_INTEGER )
  {
LABEL_9:
    fFloat = key->_unVal.nInteger >> 3;
    goto LABEL_11;
  }
  fFloat = key->_unVal.nInteger;
LABEL_11:
  v7 = (unsigned int)&v3->_nodes[fFloat & (v3->_numofnodes - 1)];
  v8 = (int *)v7;
  do
  {
    if ( v8[3] == key->_unVal.nInteger && v8[2] == type )
    {
      v17.pTable = (SQTable *)val->_unVal;
      v18 = (_DWORD *)v8[1];
      v19 = *v8;
      v8[1] = v17.nInteger;
      v20 = val->_type;
      *v8 = val->_type;
      if ( (v20 & 0x8000000) != 0 )
        ++*(_DWORD *)(v17.nInteger + 4);
      if ( (v19 & 0x8000000) != 0 && (int)--v18[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v18 + 8))(a1: v18);
      return 0;
    }
    v8 = (int *)v8[4];
  }
  while ( v8 != nullptr );
  if ( *(_DWORD *)(v7 + 8) != 16777217 )
  {
    v9 = *(_DWORD *)(v7 + 8);
    firstfree = v3->_firstfree;
    n = firstfree;
    if ( v9 > 83886084 )
    {
      if ( v9 == 134217744 )
      {
        v11 = *(_DWORD *)(*(_DWORD *)(v7 + 12) + 24);
LABEL_25:
        if ( v7 <= (unsigned int)firstfree
          || (v12 = &this->_nodes[v11 & (this->_numofnodes - 1)]) == (SQTable::_HashNode *)v7 )
        {
          firstfree->next = *(SQTable::_HashNode **)(v7 + 16);
          *(_DWORD *)(v7 + 16) = firstfree;
          v7 = (unsigned int)firstfree;
        }
        else
        {
          for ( ; v12->next != (SQTable::_HashNode *)v7; v12 = v12->next )
            ;
          v12->next = firstfree;
          SQObjectPtr::operator=(this: &firstfree->key, obj: (const SQObjectPtr *)(v7 + 8));
          SQObjectPtr::operator=(this: &n->val, obj: (const SQObjectPtr *)v7);
          n->next = *(SQTable::_HashNode **)(v7 + 16);
          SQObjectPtr::operator=(this: (SQObjectPtr *)(v7 + 8), obj: &_null_);
          SQObjectPtr::operator=(this: (SQObjectPtr *)v7, obj: &_null_);
          v4 = key;
          *(_DWORD *)(v7 + 16) = 0;
        }
        v3 = this;
        goto LABEL_32;
      }
    }
    else
    {
      if ( v9 == 83886084 )
      {
        v11 = (__int64)*(float *)(v7 + 12);
        goto LABEL_25;
      }
      if ( v9 == 16777224 || v9 == 83886082 )
      {
        v11 = *(_DWORD *)(v7 + 12);
        goto LABEL_25;
      }
    }
    v11 = *(int *)(v7 + 12) >> 3;
    goto LABEL_25;
  }
LABEL_32:
  v13 = *(SQTable **)(v7 + 12);
  v14 = *(_DWORD *)(v7 + 8);
  *(_DWORD *)(v7 + 12) = v4->_unVal.pTable;
  v15 = v4->_type;
  *(_DWORD *)(v7 + 8) = v4->_type;
  if ( (v15 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(v7 + 12) + 4);
  if ( (v14 & 0x8000000) != 0 && --v13->_uiRef <= 0 )
  {
    v13->Release(this: v13);
    v3 = this;
  }
  while ( 1 )
  {
    v16 = v3->_firstfree;
    if ( v16->key._type == OT_NULL && v16->next == nullptr )
      break;
    if ( v16 == v3->_nodes )
    {
      SQTable::Rehash(this: v13, a2: v3, force: true);
      v3 = this;
      goto LABEL_2;
    }
    v3->_firstfree = v16 - 1;
  }
  v22.pTable = (SQTable *)val->_unVal;
  v23 = *(_DWORD **)(v7 + 4);
  v24 = *(_DWORD *)v7;
  *(tagSQObjectValue *)(v7 + 4) = v22;
  v25 = val->_type;
  *(_DWORD *)v7 = val->_type;
  if ( (v25 & 0x8000000) != 0 )
    ++*(_DWORD *)(v22.nInteger + 4);
  if ( (v24 & 0x8000000) != 0 && (int)--v23[1] <= 0 )
  {
    (*(void (__thiscall **)(_DWORD *))(*v23 + 8))(a1: v23);
    v3 = this;
  }
  ++v3->_usednodes;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100553E0
// Name: public: int SQTable::Next(bool,struct SQObjectPtr const __near &,struct SQObjectPtr __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
int __fastcall SQTable::Next(
        const SQObjectPtr *refpos,
        SQObjectPtr *outkey,
        SQTable *this,
        bool getweakrefs,
        SQObjectPtr *outval)
{
  tagSQObjectValue v5; // eax
  int numofnodes; // ecx
  tagSQObjectValue v7; // edi
  SQTable::_HashNode *nodes; // esi
  SQObjectPtr *i; // eax
  tagSQObjectType type; // ebx
  tagSQObjectValue v12; // eax
  SQTable::_HashNode *v13; // esi
  _DWORD *v14; // ecx
  tagSQObjectType v15; // eax
  tagSQObjectValue v16; // edx
  tagSQObjectType *v17; // eax
  tagSQObjectValue v18; // ecx
  tagSQObjectValue v19; // ebx
  _DWORD *v20; // ecx
  tagSQObjectType v21; // esi
  tagSQObjectType v22; // eax
  tagSQObjectType v23; // [esp+10h] [ebp-Ch] BYREF
  tagSQObjectValue v24; // [esp+14h] [ebp-8h]

  if ( refpos->_type == OT_INTEGER )
    v5.pTable = (SQTable *)refpos->_unVal;
  else
    v5.nInteger = 0;
  numofnodes = this->_numofnodes;
  v7.pTable = v5.pTable;
  if ( v5.nInteger >= numofnodes )
    return -1;
  nodes = this->_nodes;
  for ( i = &nodes[v5.nInteger].key; i->_type == OT_NULL; i = (SQObjectPtr *)((char *)i + 20) )
  {
    if ( ++v7.nInteger >= numofnodes )
      return -1;
  }
  type = outkey->_type;
  v12.pTable = (SQTable *)nodes[v7.nInteger].key._unVal;
  v13 = &nodes[v7.nInteger];
  v14 = &outkey->_unVal.pTable->__vftable;
  outkey->_unVal = v12;
  v15 = v13->key._type;
  outkey->_type = v15;
  if ( (v15 & 0x8000000) != 0 )
    ++*(_DWORD *)(outkey->_unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v14[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
  if ( getweakrefs )
  {
    v16.pTable = (SQTable *)v13->val._unVal;
    v23 = v13->val._type;
    v24.pTable = v16.pTable;
    v17 = &v23;
  }
  else if ( v13->val._type == OT_WEAKREF )
  {
    v17 = (tagSQObjectType *)(v13->val._unVal.nInteger + 12);
  }
  else
  {
    v18.pTable = (SQTable *)v13->val._unVal;
    v23 = v13->val._type;
    v24.pTable = v18.pTable;
    v17 = &v23;
  }
  v19.pTable = (SQTable *)v17[1];
  v20 = &outval->_unVal.pTable->__vftable;
  v21 = outval->_type;
  outval->_unVal = v19;
  v22 = *v17;
  outval->_type = v22;
  if ( (v22 & 0x8000000) != 0 )
    ++*(_DWORD *)(v19.nInteger + 4);
  if ( (v21 & 0x8000000) != 0 && (int)--v20[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v20 + 8))(a1: v20);
  return v7.nInteger + 1;
}

//------------------------------------------------------------------------------
// Address: 0x100554F0
// Name: public: bool SQTable::Set(struct SQObjectPtr const __near &,struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQTable::Set@<al>(SQTable *this@<ecx>, const SQObjectPtr *key@<eax>, const SQObjectPtr *val)
{
  tagSQObjectType type; // edi
  int fFloat; // edx
  tagSQObjectValue *p_unVal; // ecx
  int nInteger; // ecx
  SQTable::_HashNode *v8; // eax
  _DWORD *v10; // ecx
  tagSQObjectType v11; // esi
  tagSQObjectType v12; // edx

  type = key->_type;
  if ( key->_type > OT_FLOAT )
  {
    if ( type == OT_STRING )
    {
      p_unVal = &key->_unVal;
      fFloat = *(_DWORD *)(key->_unVal.nInteger + 24);
      goto LABEL_10;
    }
    goto LABEL_8;
  }
  if ( key->_type == OT_FLOAT )
  {
    p_unVal = &key->_unVal;
    fFloat = (__int64)key->_unVal.fFloat;
    goto LABEL_10;
  }
  if ( type != OT_BOOL && type != OT_INTEGER )
  {
LABEL_8:
    p_unVal = &key->_unVal;
    fFloat = key->_unVal.nInteger >> 3;
    goto LABEL_10;
  }
  fFloat = key->_unVal.nInteger;
  p_unVal = &key->_unVal;
LABEL_10:
  nInteger = p_unVal->nInteger;
  v8 = &this->_nodes[fFloat & (this->_numofnodes - 1)];
  while ( v8->key._unVal.nInteger != nInteger || v8->key._type != type )
  {
    v8 = v8->next;
    if ( v8 == nullptr )
      return 0;
  }
  v10 = &v8->val._unVal.pTable->__vftable;
  v11 = v8->val._type;
  v8->val._unVal.nInteger = val->_unVal.nInteger;
  v12 = val->_type;
  v8->val._type = val->_type;
  if ( (v12 & 0x8000000) != 0 )
    ++*(_DWORD *)(v8->val._unVal.nInteger + 4);
  if ( (v11 & 0x8000000) != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100555D0
// Name: private: void SQTable::_ClearNodes(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQTable::_ClearNodes(SQTable *this@<ecx>, int a2@<edi>)
{
  int v2; // esi
  int v3; // eax
  _DWORD *v4; // ecx
  int v5; // edx
  tagSQObjectType *v6; // eax
  tagSQObjectType type; // ebx
  int v8; // eax
  _DWORD *v9; // ecx
  int v10; // edx
  tagSQObjectType *v11; // eax
  tagSQObjectType v12; // ebx
  int i; // [esp+4h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < *(_DWORD *)(a2 + 36); ++i )
  {
    v3 = *(_DWORD *)(a2 + 32);
    v4 = *(_DWORD **)(v2 + v3 + 12);
    v5 = *(_DWORD *)(v2 + v3 + 8);
    v6 = (tagSQObjectType *)(v2 + v3 + 8);
    v6[1] = (tagSQObjectType)_null_._unVal.pTable;
    type = _null_._type;
    *v6 = _null_._type;
    if ( (type & 0x8000000) != 0 )
      ++*(_DWORD *)(*((_DWORD *)v6 + 1) + 4);
    if ( (v5 & 0x8000000) != 0 && (int)--v4[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
    v8 = *(_DWORD *)(a2 + 32);
    v9 = *(_DWORD **)(v8 + v2 + 4);
    v10 = *(_DWORD *)(v8 + v2);
    v11 = (tagSQObjectType *)(v2 + v8);
    v11[1] = (tagSQObjectType)_null_._unVal.pTable;
    v12 = _null_._type;
    *v11 = _null_._type;
    if ( (v12 & 0x8000000) != 0 )
      ++*(_DWORD *)(*((_DWORD *)v11 + 1) + 4);
    if ( (v10 & 0x8000000) != 0 && (int)--v9[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
    v2 += 20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100556A0
// Name: public: virtual void SQTable::Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQTable::Finalize(SQTable *this)
{
  SQTable *delegate; // eax

  SQTable::_ClearNodes(this, a2: (int)this);
  if ( this != nullptr )
  {
    delegate = this->_delegate;
    if ( delegate != nullptr )
    {
      if ( --delegate->_uiRef <= 0 )
        this->_delegate->Release(this: this->_delegate);
      this->_delegate = nullptr;
    }
    this->_delegate = nullptr;
  }
}
