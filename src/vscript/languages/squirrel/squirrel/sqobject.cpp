// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/squirrel/sqobject.cpp
// Functions: 40
// ============================================================

#include "vscript\languages\squirrel\squirrel\sqobject.h"

//------------------------------------------------------------------------------
// Address: 0x1004D260
// Name: public: void SQVM::GrowCallStack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQVM::GrowCallStack(SQVM *this, SQVM *thisa)
{
  unsigned int v2; // esi
  int *pTable; // ecx
  SQVM::CallInfo *vals; // ecx
  SQVM::CallInfo fill; // [esp+10h] [ebp-34h] BYREF

  v2 = 2 * thisa->_alloccallsstacksize;
  fill._vargs = 0;
  fill._closure._type = OT_NULL;
  fill._closure._unVal.nInteger = 0;
  sqvector<SQVM::CallInfo>::resize(this: &thisa->_callstackdata, newsize: v2, &fill);
  if ( (fill._closure._type & 0x8000000) != 0 )
  {
    pTable = (int *)fill._closure._unVal.pTable;
    --*(_DWORD *)(fill._closure._unVal.nInteger + 4);
    if ( pTable[1] <= 0 )
      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
  vals = thisa->_callstackdata._vals;
  thisa->_alloccallsstacksize = v2;
  thisa->_callsstack = vals;
}

//------------------------------------------------------------------------------
// Address: 0x1004D2C0
// Name: char const __near * IdType2Name(enum tagSQObjectType)
// Source: json
//------------------------------------------------------------------------------
const char *__usercall IdType2Name@<eax>(tagSQObjectType type@<eax>)
{
  __int32 v1; // eax
  const char *result; // eax

  v1 = type & 0xFFFFFF;
  if ( (unsigned int)v1 > 0x100 )
  {
    if ( v1 > 0x2000 )
    {
      switch ( v1 )
      {
        case 0x4000:
          return "class";
        case 0x8000:
          return "instance";
        case 0x10000:
          return "weakref";
        default:
          break;
      }
    }
    else
    {
      if ( v1 == 0x2000 )
        return "function";
      if ( v1 > 2048 )
      {
        if ( v1 == 4096 )
          return "thread";
      }
      else
      {
        switch ( v1 )
        {
          case 2048:
            return "userdata";
          case 512:
            return "native function";
          case 1024:
            return "generator";
          default:
            break;
        }
      }
    }
    return nullptr;
  }
  if ( v1 == 256 )
    return "function";
  switch ( v1 )
  {
    case 1:
      result = "null";
      break;
    case 2:
      result = "integer";
      break;
    case 4:
      result = "float";
      break;
    case 8:
      result = "bool";
      break;
    case 16:
      result = "string";
      break;
    case 32:
      result = "table";
      break;
    case 64:
      result = "array";
      break;
    case 128:
      return "userdata";
    default:
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004D430
// Name: public: virtual void SQString::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQString::Release(SQString *this)
{
  StringTable *stringtable; // edx
  SQString **v2; // eax
  SQString *v3; // esi
  SQString *v4; // edi
  SQString *next; // ecx

  stringtable = this->_sharedstate->_stringtable;
  v2 = &stringtable->_strings[this->_hash & (stringtable->_numofslots - 1)];
  v3 = *v2;
  v4 = nullptr;
  if ( *v2 != nullptr )
  {
    while ( v3 != this )
    {
      v4 = v3;
      v3 = v3->_next;
      if ( v3 == nullptr )
        return;
    }
    next = v3->_next;
    if ( v4 != nullptr )
      v4->_next = next;
    else
      *v2 = next;
    --stringtable->_slotused;
    ((void (__thiscall *)(SQString *, _DWORD))v3->dtr_SQRefCounted)(a1: v3, a2: 0);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D490
// Name: public: int SQString::Next(struct SQObjectPtr const __near &,struct SQObjectPtr __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge SQString::Next@<eax>(
        const SQObjectPtr *refpos@<ecx>,
        SQObjectPtr *outkey@<eax>,
        SQString *this,
        SQObjectPtr *outval)
{
  int nInteger; // edi
  tagSQObjectValue v6; // eax
  tagSQObjectValue v7; // esi
  tagSQObjectValue v8; // eax

  if ( refpos->_type == OT_INTEGER )
    nInteger = refpos->_unVal.nInteger;
  else
    nInteger = 0;
  if ( nInteger >= this->_len )
    return -1;
  if ( (outkey->_type & 0x8000000) != 0 )
  {
    v6.pTable = (SQTable *)outkey->_unVal;
    if ( (int)--*(_DWORD *)(v6.nInteger + 4) <= 0 )
      outkey->_unVal.pTable->Release(this: (struct SQTable *)outkey->_unVal.nInteger);
  }
  outkey->_unVal.nInteger = nInteger;
  outkey->_type = OT_INTEGER;
  v7.nInteger = this->_val[nInteger];
  if ( (outval->_type & 0x8000000) != 0 )
  {
    v8.pTable = (SQTable *)outval->_unVal;
    if ( (int)--*(_DWORD *)(v8.nInteger + 4) <= 0 )
      outval->_unVal.pTable->Release(this: (struct SQTable *)outval->_unVal.nInteger);
  }
  outval->_unVal = v7;
  outval->_type = OT_INTEGER;
  return nInteger + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004D580
// Name: public: virtual void SQWeakRef::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQWeakRef::Release(SQWeakRef *this)
{
  if ( (this->_obj._type & 0x8000000) != 0 )
    *(_DWORD *)(this->_obj._unVal.nInteger + 8) = 0;
  ((void (__thiscall *)(SQWeakRef *, _DWORD))this->dtr_SQRefCounted)(a1: this, a2: 0);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1004D5B0
// Name: public: virtual bool SQDelegable::GetMetaMethod(struct SQVM __near *,enum SQMetaMethod,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SQDelegable::GetMetaMethod(SQDelegable *this, SQVM *v, SQMetaMethod mm, SQObjectPtr *res)
{
  SQTable *delegate; // ecx

  delegate = this->_delegate;
  return delegate != nullptr && SQTable::Get(this: delegate, key: &v->_sharedstate->_metamethods->_vals[mm], val: res);
}

//------------------------------------------------------------------------------
// Address: 0x1004D5F0
// Name: public: bool SQDelegable::SetDelegate(struct SQTable __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall SQDelegable::SetDelegate@<al>(SQDelegable *this@<esi>, SQTable *mt@<edi>)
{
  SQTable *delegate; // eax
  SQTable *v4; // eax

  delegate = mt;
  if ( mt == this )
    return 0;
  if ( mt != nullptr )
  {
    while ( 1 )
    {
      delegate = delegate->_delegate;
      if ( delegate == this )
        return 0;
      if ( delegate == nullptr )
      {
        ++mt->_uiRef;
        break;
      }
    }
  }
  v4 = this->_delegate;
  if ( v4 != nullptr )
  {
    if ( --v4->_uiRef <= 0 )
      this->_delegate->Release(this: this->_delegate);
    this->_delegate = nullptr;
  }
  this->_delegate = mt;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004D640
// Name: public: bool SQGenerator::Yield(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQGenerator::Yield(SQGenerator *this, SQVM *v, int i)
{
  SQVM::CallInfo *vals; // eax
  int *p_top; // esi
  int v7; // edi
  _DWORD *v8; // esi
  int *v9; // edx
  tagSQObjectValue *v10; // eax
  tagSQObjectValue v11; // ecx
  int v12; // edx
  int *pTable; // ecx
  tagSQObjectValue *v14; // eax
  _DWORD *v15; // ecx
  tagSQObjectType type; // edx
  int v17; // eax
  int v18; // ecx
  bool v19; // sf
  int v20; // edx
  int v21; // eax
  tagSQObjectType *v22; // edi
  unsigned int v23; // eax
  bool v24; // zf
  int v25; // eax
  SQObjectPtr *v26; // eax
  unsigned int v27; // ecx
  SQObjectPtr *v28; // eax
  tagSQObjectType v29; // ecx
  tagSQObjectValue v30; // edi
  _QWORD *v31; // edx
  unsigned int callsstacksize; // eax
  int v33; // edi
  SQVM::CallInfo *v34; // eax
  int v35; // eax
  _QWORD *v36; // eax
  const char *v37; // [esp+0h] [ebp-18h]
  SQObjectPtr fill; // [esp+Ch] [ebp-Ch] BYREF
  int j; // [esp+14h] [ebp-4h]
  sqvector<SQObjectPtr> *size; // [esp+20h] [ebp+8h]
  int sizea; // [esp+20h] [ebp+8h]
  int sizeb; // [esp+20h] [ebp+8h]
  unsigned int ia; // [esp+24h] [ebp+Ch]
  int ib; // [esp+24h] [ebp+Ch]

  vals = v->_callstackdata._vals;
  if ( vals == (SQVM::CallInfo *)1 )
  {
    SQVM::Raise_Error(a1: (_DWORD *)i, this: (SQVM *)&stru_1009CBCC, s: v37);
    return 0;
  }
  else if ( vals == (SQVM::CallInfo *)2 )
  {
    SQVM::Raise_Error(a1: (_DWORD *)i, this: (SQVM *)&stru_1009CBCC._vargsstack, s: v37);
    return 0;
  }
  else
  {
    p_top = &v->_top;
    size = (sqvector<SQObjectPtr> *)(*(_DWORD *)(i + 56) - *(_DWORD *)(i + 60));
    SQVM::CallInfo::operator=(this: (SQVM::CallInfo *)p_top, __that: *(const SQVM::CallInfo **)(i + 140));
    v7 = 0;
    fill._type = OT_NULL;
    fill._unVal.nInteger = 0;
    sqvector<SQObjectPtr>::resize(this: size, a2: (int)&v->_stack, newsize: (unsigned int)size, &fill);
    if ( (int)size <= 0 )
    {
      v8 = (_DWORD *)i;
    }
    else
    {
      do
      {
        v8 = (_DWORD *)i;
        v9 = (int *)(*(_DWORD *)(i + 32) + 8 * (v7 + *(_DWORD *)(i + 60)));
        v10 = (tagSQObjectValue *)&v->_stack._vals[v7];
        j = v10->nInteger;
        fill._unVal = v10[1];
        v11.nInteger = v9[1];
        v10[1].pTable = v11.pTable;
        v12 = *v9;
        v10->nInteger = v12;
        if ( (v12 & 0x8000000) != 0 )
          ++*(_DWORD *)(v11.nInteger + 4);
        if ( (j & 0x8000000) != 0 )
        {
          pTable = (int *)fill._unVal.pTable;
          --*(_DWORD *)(fill._unVal.nInteger + 4);
          if ( pTable[1] <= 0 )
            (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
        }
        v14 = (tagSQObjectValue *)(*(_DWORD *)(i + 32) + 8 * (v7 + *(_DWORD *)(i + 60)));
        fill._unVal = (tagSQObjectValue)v14->pTable;
        v15 = &v14[1].pTable->__vftable;
        v14[1].pTable = (SQTable *)_null_._unVal;
        type = _null_._type;
        v14->pTable = (SQTable *)_null_._type;
        if ( (type & 0x8000000) != 0 )
          ++*(_DWORD *)(v14[1].nInteger + 4);
        if ( (fill._unVal.nInteger & 0x8000000) != 0 && (int)--v15[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15);
        ++v7;
      }
      while ( v7 < (int)size );
    }
    v17 = v8[35];
    v18 = *(unsigned __int16 *)(v17 + 46);
    v20 = *(unsigned __int16 *)(v17 + 44) - 1;
    v19 = *(unsigned __int16 *)(v17 + 44) == 0;
    j = v20;
    if ( !v19 )
    {
      v21 = 8 * (v20 + v18);
      for ( sizea = v21; ; v21 = sizea )
      {
        v22 = (tagSQObjectType *)(v21 + v8[11]);
        v23 = v->_vargsstack._size;
        if ( v->_vargsstack._allocated <= v23 )
        {
          v24 = 2 * v23 == 0;
          v25 = 2 * v23;
          ia = v25;
          if ( v24 )
          {
            ia = 4;
            v25 = 4;
          }
          v26 = (SQObjectPtr *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v->_vargsstack._vals, a3: 8 * v25);
          v20 = j;
          v->_vargsstack._vals = v26;
          v->_vargsstack._allocated = ia;
        }
        v27 = v->_vargsstack._size;
        v28 = &v->_vargsstack._vals[v27];
        v->_vargsstack._size = v27 + 1;
        if ( v28 != nullptr )
        {
          v29 = *v22;
          v28->_type = *v22;
          v30.pTable = (SQTable *)v22[1];
          v28->_unVal = v30;
          if ( (v29 & 0x8000000) != 0 )
            ++*(_DWORD *)(v30.nInteger + 4);
        }
        sizea -= 8;
        j = --v20;
        if ( v20 < 0 )
          break;
      }
    }
    v->_lasterror._type = 0;
    for ( ib = 0; ib < v->_lasterror._unVal.nInteger; ++ib )
    {
      v31 = (_QWORD *)(v8[32] + 16 * v8[33] - 16);
      callsstacksize = v->_callsstacksize;
      sizeb = (int)v31;
      if ( v->_alloccallsstacksize <= callsstacksize )
      {
        v33 = 2 * callsstacksize;
        if ( 2 * callsstacksize == 0 )
          v33 = 4;
        v34 = (SQVM::CallInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v->_callsstack, a3: 16 * v33);
        v31 = (_QWORD *)sizeb;
        v->_callsstack = v34;
        v->_alloccallsstacksize = v33;
      }
      v35 = 16 * v->_callsstacksize;
      v24 = (SQVM::CallInfo *)((char *)v->_callsstack + v35) == nullptr;
      v36 = (_QWORD *)((char *)v->_callsstack + v35);
      ++v->_callsstacksize;
      if ( !v24 )
      {
        *v36 = *v31;
        v36[1] = v31[1];
      }
      --v8[33];
    }
    v->_callstackdata._vals = (SQVM::CallInfo *)1;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D8D0
// Name: public: struct SQVM::CallInfo __near & SQVM::CallInfo::operator=(struct SQVM::CallInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
SQVM::CallInfo *__usercall SQVM::CallInfo::operator=@<eax>(
        SQVM::CallInfo *this@<esi>,
        const SQVM::CallInfo *__that@<edi>)
{
  _DWORD *v2; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v4; // eax

  this->_ip = __that->_ip;
  this->_literals = __that->_literals;
  v2 = &this->_closure._unVal.pTable->__vftable;
  type = this->_closure._type;
  this->_closure._unVal.nInteger = __that->_closure._unVal.nInteger;
  v4 = __that->_closure._type;
  this->_closure._type = v4;
  if ( (v4 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_closure._unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v2[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v2 + 8))(a1: v2);
  this->_generator = __that->_generator;
  this->_etraps = __that->_etraps;
  this->_prevstkbase = __that->_prevstkbase;
  this->_prevtop = __that->_prevtop;
  this->_target = __that->_target;
  this->_ncalls = __that->_ncalls;
  this->_root = __that->_root;
  this->_vargs = __that->_vargs;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004D950
// Name: public: bool SQGenerator::Resume(struct SQVM __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQGenerator::Resume(SQGenerator *this, SQVM *v, int target, int targeta)
{
  SQVM::CallInfo *vals; // eax
  SQVM *v7; // ecx
  SQVM::CallInfo *v8; // esi
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  bool v13; // cc
  _QWORD *v14; // edx
  unsigned int v15; // eax
  int v16; // edi
  void *v17; // eax
  int v18; // eax
  bool v19; // zf
  _QWORD *v20; // eax
  signed int v21; // eax
  SQObjectPtr *v22; // ecx
  tagSQObjectValue v23; // edi
  SQObjectPtr *v24; // edx
  int *v25; // eax
  _DWORD *v26; // ecx
  tagSQObjectType type; // edx
  SQObjectPtr *v28; // eax
  _DWORD *v29; // ecx
  tagSQObjectType v30; // edx
  tagSQObjectType v31; // edi
  unsigned int v32; // eax
  SQObjectPtr *v33; // edx
  int v34; // edi
  void *v35; // eax
  int v36; // ecx
  tagSQObjectType *v37; // eax
  tagSQObjectValue v38; // ecx
  SQObjectPtr *v39; // ecx
  unsigned int v40; // eax
  SQObjectPtr *v41; // ecx
  tagSQObjectValue v42; // eax
  int v43; // eax
  SQVM *v44; // ecx
  const char *v45; // [esp+0h] [ebp-14h]
  int oldstackbase; // [esp+Ch] [ebp-8h]
  int prevtop; // [esp+10h] [ebp-4h]
  int n; // [esp+1Ch] [ebp+8h]
  int na; // [esp+1Ch] [ebp+8h]
  int nb; // [esp+1Ch] [ebp+8h]
  signed int size; // [esp+20h] [ebp+Ch]
  int targetb; // [esp+24h] [ebp+10h]
  int targetc; // [esp+24h] [ebp+10h]

  size = v->_stack._size;
  vals = v->_callstackdata._vals;
  if ( vals == (SQVM::CallInfo *)2 )
  {
    SQVM::Raise_Error(a1: (_DWORD *)target, this: (SQVM *)&stru_1009CBCC._debughook._unVal, s: v45);
    return 0;
  }
  else if ( vals != nullptr )
  {
    v7 = *(SQVM **)(target + 108);
    prevtop = *(_DWORD *)(target + 56) - *(_DWORD *)(target + 60);
    if ( v7 == *(SQVM **)(target + 112) )
      SQVM::GrowCallStack(this: v7, thisa: (SQVM *)target);
    v8 = (SQVM::CallInfo *)(48 * *(_DWORD *)(target + 108) + *(_DWORD *)(target + 104));
    *(_DWORD *)(target + 140) = v8;
    SQVM::CallInfo::operator=(this: v8, __that: (const SQVM::CallInfo *)&v->_top);
    v9 = *(_DWORD *)(target + 60);
    v10 = *(_DWORD *)(target + 56);
    ++*(_DWORD *)(target + 108);
    v11 = *(_DWORD *)(target + 140);
    *(_DWORD *)(target + 60) = v10;
    oldstackbase = v9;
    *(_DWORD *)(v11 + 32) = targeta;
    *(_DWORD *)(*(_DWORD *)(target + 140) + 16) = v;
    *(_WORD *)(*(_DWORD *)(target + 140) + 44) = v->_vargsstack._size;
    v13 = v->_lasterror._unVal.nInteger <= 0;
    n = 0;
    if ( !v13 )
    {
      do
      {
        v14 = (_QWORD *)((char *)v->_callsstack + 16 * v->_callsstacksize - 16);
        v15 = *(_DWORD *)(target + 132);
        targetb = (int)v14;
        if ( *(_DWORD *)(target + 136) <= v15 )
        {
          v16 = 2 * v15;
          if ( 2 * v15 == 0 )
            v16 = 4;
          v17 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(target + 128), a3: 16 * v16);
          v14 = (_QWORD *)targetb;
          *(_DWORD *)(target + 128) = v17;
          *(_DWORD *)(target + 136) = v16;
        }
        v18 = 16 * *(_DWORD *)(target + 132);
        v19 = *(_DWORD *)(target + 128) + v18 == 0;
        v20 = (_QWORD *)(*(_DWORD *)(target + 128) + v18);
        ++*(_DWORD *)(target + 132);
        if ( !v19 )
        {
          *v20 = *v14;
          v20[1] = v14[1];
        }
        --v->_callsstacksize;
        ++n;
      }
      while ( n < v->_lasterror._unVal.nInteger );
    }
    v21 = 0;
    for ( na = 0; v21 < size; na = v21 )
    {
      v22 = v->_stack._vals;
      v23.pTable = (SQTable *)v22[v21]._unVal;
      v24 = &v22[v21];
      v25 = (int *)(*(_DWORD *)(target + 32) + 8 * (v21 + *(_DWORD *)(target + 60)));
      targetc = *v25;
      v26 = (_DWORD *)v25[1];
      v25[1] = v23.nInteger;
      type = v24->_type;
      *v25 = type;
      if ( (type & 0x8000000) != 0 )
        ++*(_DWORD *)(v23.nInteger + 4);
      if ( (targetc & 0x8000000) != 0 && (int)--v26[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v26 + 8))(a1: v26);
      v28 = v->_stack._vals;
      v29 = &v28->_unVal.pTable->__vftable;
      v30 = v28->_type;
      v28->_unVal.nInteger = _null_._unVal.nInteger;
      v31 = _null_._type;
      v28->_type = _null_._type;
      if ( (v31 & 0x8000000) != 0 )
        ++*(_DWORD *)(v28->_unVal.nInteger + 4);
      if ( (v30 & 0x8000000) != 0 && (int)--v29[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v29 + 8))(a1: v29);
      v21 = na + 1;
    }
    while ( v->_vargsstack._size != 0 )
    {
      v32 = *(_DWORD *)(target + 48);
      v33 = &v->_vargsstack._vals[v->_vargsstack._size - 1];
      nb = (int)v33;
      if ( *(_DWORD *)(target + 52) <= v32 )
      {
        v34 = 2 * v32;
        if ( 2 * v32 == 0 )
          v34 = 4;
        v35 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(target + 44), a3: 8 * v34);
        v33 = (SQObjectPtr *)nb;
        *(_DWORD *)(target + 44) = v35;
        *(_DWORD *)(target + 52) = v34;
      }
      v36 = *(_DWORD *)(target + 48);
      v37 = (tagSQObjectType *)(*(_DWORD *)(target + 44) + 8 * v36);
      *(_DWORD *)(target + 48) = v36 + 1;
      if ( v37 != nullptr )
      {
        *v37 = v33->_type;
        v19 = (*v37 & 0x8000000) == 0;
        v38.pTable = (SQTable *)v33->_unVal;
        v37[1] = (tagSQObjectType)v38.pTable;
        if ( !v19 )
          ++*(_DWORD *)(v38.nInteger + 4);
      }
      v39 = v->_vargsstack._vals;
      v40 = --v->_vargsstack._size;
      v19 = (v39[v40]._type & 0x8000000) == 0;
      v41 = &v39[v40];
      if ( !v19 )
      {
        v42.pTable = (SQTable *)v41->_unVal;
        if ( (int)--*(_DWORD *)(v42.nInteger + 4) <= 0 )
          v41->_unVal.pTable->Release(this: (struct SQTable *)v41->_unVal.nInteger);
      }
    }
    *(_WORD *)(*(_DWORD *)(target + 140) + 46) = *(_WORD *)(target + 48) - *(_WORD *)(*(_DWORD *)(target + 140) + 44);
    v43 = *(_DWORD *)(target + 140);
    *(_DWORD *)(target + 56) = size + *(_DWORD *)(target + 60);
    *(_DWORD *)(v43 + 28) = prevtop;
    *(_DWORD *)(*(_DWORD *)(target + 140) + 24) = *(_DWORD *)(target + 60) - oldstackbase;
    v->_callstackdata._vals = nullptr;
    if ( *(_DWORD *)(target + 88) != 16777217 )
    {
      v44 = *(SQVM **)(target + 140);
      if ( *(SQCollectable **)(target + 92) != v44->_next )
        SQVM::CallDebugHook(this: v44, type: 99, forcedline: 0);
    }
    return 1;
  }
  else
  {
    SQVM::Raise_Error(a1: (_DWORD *)target, this: (SQVM *)&stru_1009CBCC._callstackdata, s: v45);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DC70
// Name: public: void SQArray::Extend(struct SQArray const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQArray::Extend(SQArray *this, const SQArray *a, const SQArray *aa)
{
  int size; // eax
  SQObjectPtr *vals; // edx
  tagSQObjectType type; // edi
  _DWORD *v6; // esi
  int v7; // ebx
  const SQArray *v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // edi
  SQObjectPtr *v11; // eax
  unsigned int v12; // ecx
  SQObjectPtr *v13; // eax
  int i; // [esp+Ch] [ebp-14h]
  int xlen; // [esp+14h] [ebp-Ch]
  tagSQObjectType v16; // [esp+18h] [ebp-8h]

  size = aa->_values._size;
  xlen = size;
  if ( size != 0 )
  {
    i = 0;
    if ( size > 0 )
    {
      while ( 1 )
      {
        vals = aa->_values._vals;
        type = vals[i]._type;
        v6 = &vals[i]._unVal.pTable->__vftable;
        v7 = type & 0x8000000;
        v16 = type;
        if ( (type & 0x8000000) != 0 )
          ++v6[1];
        v8 = a;
        v9 = a->_values._size;
        if ( a->_values._allocated <= v9 )
        {
          v10 = 2 * v9;
          if ( 2 * v9 == 0 )
            v10 = 4;
          v11 = (SQObjectPtr *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: a->_values._vals, a3: 8 * v10);
          a->_values._allocated = v10;
          type = v16;
          a->_values._vals = v11;
          v8 = a;
        }
        v12 = v8->_values._size;
        v13 = &v8->_values._vals[v12];
        v8->_values._size = v12 + 1;
        if ( v13 == nullptr )
          goto LABEL_12;
        v13->_type = type;
        v13->_unVal.nInteger = (int)v6;
        if ( v7 != 0 )
          break;
LABEL_15:
        if ( ++i >= xlen )
          return;
      }
      ++v6[1];
LABEL_12:
      if ( v7 != 0 && (int)--v6[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
      goto LABEL_15;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DD60
// Name: public: char const __near * SQFunctionProto::GetLocal(struct SQVM __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SQFunctionProto::GetLocal(
        SQFunctionProto *this,
        SQFunctionProto *vm,
        unsigned int stackbase,
        unsigned int nseq,
        unsigned int nop)
{
  unsigned int v5; // eax
  unsigned int nlocalvarinfos; // edx
  int v8; // ecx
  unsigned int localvarinfos; // ebx
  unsigned int *i; // esi
  SQObjectPtr *literals; // edx
  int v13; // eax
  int v14; // esi
  int v15; // ecx
  int *v16; // ecx
  int v17; // ebx
  int v18; // ecx
  unsigned int nseqa; // [esp+1Ch] [ebp+10h]
  _DWORD *nopa; // [esp+20h] [ebp+14h]

  v5 = nop;
  nlocalvarinfos = vm->_nlocalvarinfos;
  if ( nlocalvarinfos < nseq )
    return nullptr;
  v8 = 0;
  if ( nlocalvarinfos == 0 )
    return nullptr;
  localvarinfos = (unsigned int)vm->_localvarinfos;
  for ( i = (unsigned int *)(localvarinfos + 12); ; i += 5 )
  {
    if ( *(i - 1) <= v5 && *i >= v5 )
    {
      if ( nseq == 0 )
        break;
      --nseq;
      v5 = nop;
    }
    if ( ++v8 >= nlocalvarinfos )
      return nullptr;
  }
  literals = this->_literals;
  v13 = *(_DWORD *)&this->_bgenerator;
  v14 = v8;
  v15 = stackbase + *(_DWORD *)(localvarinfos + 20 * v8 + 16);
  this->_literals = (SQObjectPtr *)((char *)&literals->_type + 1);
  nseqa = *(_DWORD *)(v13 + 8 * (_DWORD)literals);
  v16 = (int *)(v13 + 8 * v15);
  nopa = *(_DWORD **)(v13 + 8 * (_DWORD)literals + 4);
  v17 = v16[1];
  *(_DWORD *)(v13 + 8 * (_DWORD)literals + 4) = v17;
  v18 = *v16;
  *(_DWORD *)(v13 + 8 * (_DWORD)literals) = v18;
  if ( (v18 & 0x8000000) != 0 )
    ++*(_DWORD *)(v17 + 4);
  if ( (nseqa & 0x8000000) != 0 && (int)--nopa[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*nopa + 8))(a1: nopa);
  return (const char *)(vm->_localvarinfos[v14]._name._unVal.nInteger + 28);
}

//------------------------------------------------------------------------------
// Address: 0x1004DE40
// Name: bool SafeWrite(struct SQVM __near *,int (*)(void __near *,void __near *,int),void __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __usercall SafeWrite@<al>(
        SQVM *v@<edi>,
        void *up@<ecx>,
        void *dest@<eax>,
        int size@<esi>,
        int (__cdecl *write)(void *, void *))
{
  const char *savedregs; // [esp+4h] [ebp+0h]

  if ( write(a1: up, a2: dest) == size )
    return 1;
  SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CBCC._foreignptr, s: savedregs);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004DE70
// Name: bool SafeRead(struct SQVM __near *,int (*)(void __near *,void __near *,int),void __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __usercall SafeRead@<al>(
        SQVM *v@<edi>,
        void *up@<ecx>,
        void *dest@<eax>,
        int size@<esi>,
        int (__cdecl *read)(void *, void *))
{
  const char *v6; // [esp+4h] [ebp-4h]

  if ( read(a1: up, a2: dest) == size )
    return 1;
  SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80, s: v6);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004DEA0
// Name: bool WriteTag(struct SQVM __near *,int (*)(void __near *,void __near *,int),void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __usercall WriteTag@<al>(SQVM *v@<edi>, void *up@<ecx>, int (__stdcall *write)(void *))
{
  const char *savedregs; // [esp+4h] [ebp+0h]

  if ( write(a1: up) == 4 )
    return 1;
  SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CBCC._foreignptr, s: savedregs);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004DEE0
// Name: bool CheckTag(struct SQVM __near *,int (*)(void __near *,void __near *,int),void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __usercall CheckTag@<al>(SQVM *v@<eax>, void *up@<ecx>, int (__cdecl *read)(void *, void *, int))
{
  const char *v5; // [esp+0h] [ebp-Ch]
  int t; // [esp+8h] [ebp-4h] BYREF

  if ( read(a1: up, a2: &t, a3: 4) == 4 )
  {
    if ( t == 1346458196 )
    {
      return 1;
    }
    else
    {
      SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80._errorhandler, s: v5);
      return 0;
    }
  }
  else
  {
    SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80, s: v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DF40
// Name: bool WriteObject(struct SQVM __near *,void __near *,int (*)(void __near *,void __near *,int),struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall WriteObject@<al>(void *up@<ecx>, SQObjectPtr *o@<eax>, SQVM *v, int (__cdecl *write)(void *, void *))
{
  tagSQObjectType type; // eax
  char result; // al
  const char *v8; // eax
  tagSQObjectValue v9; // eax
  int v10; // esi
  const char *v11; // [esp+0h] [ebp-Ch]

  if ( ((int (__cdecl *)(void *, SQObjectPtr *, int))write)(a1: up, a2: o, a3: 4) != 4 )
    goto LABEL_9;
  type = o->_type;
  if ( o->_type > OT_FLOAT )
  {
    if ( type != OT_STRING )
      goto LABEL_11;
    if ( ((int (__cdecl *)(void *, int, int))write)(a1: up, a2: o->_unVal.nInteger + 20, a3: 4) == 4 )
    {
      v9.pTable = (SQTable *)o->_unVal;
      v10 = *(_DWORD *)(v9.nInteger + 20);
      if ( ((int (__cdecl *)(void *, int, int))write)(a1: up, a2: v9.nInteger + 28, a3: v10) == v10 )
        return 1;
    }
LABEL_9:
    SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CBCC._foreignptr, s: v11);
    return 0;
  }
  if ( o->_type == OT_FLOAT )
  {
    if ( ((int (__cdecl *)(void *, tagSQObjectValue *, int))write)(a1: up, a2: &o->_unVal, a3: 4) == 4 )
      return 1;
    goto LABEL_9;
  }
  if ( type == OT_NULL )
    return 1;
  if ( type != OT_INTEGER )
  {
LABEL_11:
    v8 = IdType2Name(type);
    SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80._callstackdata, s: v8);
    return 0;
  }
  result = SafeWrite(v, up, dest: &o->_unVal, size: 4, write);
  if ( result != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004E020
// Name: bool ReadObject(struct SQVM __near *,void __near *,int (*)(void __near *,void __near *,int),struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ReadObject@<al>(void *up@<eax>, SQVM *v, SQSharedState *read, SQObjectPtr *o)
{
  int (__cdecl *v4)(void *, void *, int); // ebx
  SQObjectPtr *v7; // ecx
  SQObjectPtr *v8; // ecx
  const char *v9; // eax
  int (__cdecl *v10)(void *, void *, int); // ecx
  char *scratchpad; // eax
  SQSharedState *sharedstate; // esi
  SQString *v13; // eax
  const char *v14; // [esp+4h] [ebp-1Ch]
  SQObjectPtr obj; // [esp+10h] [ebp-10h] BYREF
  tagSQObjectType t[2]; // [esp+18h] [ebp-8h] BYREF

  v4 = (int (__cdecl *)(void *, void *, int))read;
  if ( ((int (__cdecl *)(void *, tagSQObjectType *, int))read)(a1: up, a2: t, a3: 4) != 4 )
    goto LABEL_2;
  if ( t[0] > OT_FLOAT )
  {
    if ( t[0] != OT_STRING )
    {
LABEL_13:
      v9 = IdType2Name(type: t[0]);
      SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80._callstackdata, s: v9);
      return 0;
    }
    if ( v4(a1: up, a2: &read, a3: 4) != 4 )
      goto LABEL_2;
    v10 = (int (__cdecl *)(void *, void *, int))read;
    if ( (int)read <= 0 )
    {
      scratchpad = v->_sharedstate->_scratchpad;
    }
    else
    {
      scratchpad = SQSharedState::GetScratchPad(this: read, size: (int)v14);
      v10 = (int (__cdecl *)(void *, void *, int))read;
    }
    if ( v10 != nullptr )
    {
      if ( (int (__cdecl *)(void *, void *, int))v4(a1: up, a2: scratchpad, a3: (int)v10) != v10 )
        goto LABEL_2;
      v10 = (int (__cdecl *)(void *, void *, int))read;
    }
    sharedstate = v->_sharedstate;
    v13 = StringTable::Add(this: sharedstate->_stringtable, news: sharedstate->_scratchpad, len: (int)v10);
    v13->_sharedstate = sharedstate;
    ++v13->_uiRef;
    obj._unVal.nInteger = (int)v13;
    obj._type = OT_STRING;
    SQObjectPtr::operator=(this: o, &obj);
    SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&obj);
    return 1;
  }
  else
  {
    if ( t[0] != OT_FLOAT )
    {
      if ( t[0] == OT_NULL )
      {
        SQObjectPtr::operator=(this: o, obj: &_null_);
        return 1;
      }
      if ( t[0] == OT_INTEGER )
      {
        if ( v4(a1: up, a2: &read, a3: 4) == 4 )
        {
          SQObjectPtr::operator=(this: v7, a2: o, i: (int)read);
          return 1;
        }
LABEL_2:
        SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80, s: v14);
        return 0;
      }
      goto LABEL_13;
    }
    if ( v4(a1: up, a2: &read, a3: 4) != 4 )
      goto LABEL_2;
    SQObjectPtr::operator=(this: v8, a2: (float *)o, f: *(float *)&read);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E1A0
// Name: public: bool SQFunctionProto::Save(struct SQVM __near *,void __near *,int (*)(void __near *,void __near *,int))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SQFunctionProto::Save(
        SQFunctionProto *this,
        int v,
        SQLocalVarInfo *up,
        int (__cdecl *write)(void *, void *))
{
  SQLocalVarInfo *v4; // ebx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int (__cdecl *v10)(void *, void *); // edi
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  SQVM *v16; // edi
  SQObjectPtr *p_name; // eax
  int (__cdecl *v18)(void *, void *); // esi
  int (__cdecl *v19)(void *, void *); // esi
  SQLocalVarInfo *v20; // esi
  int v21; // esi
  int (__cdecl *v22)(void *, void *); // [esp-4h] [ebp-38h]
  const char *v23; // [esp+0h] [ebp-34h]
  int ninstructions; // [esp+Ch] [ebp-28h] BYREF
  int ndefaultparams; // [esp+10h] [ebp-24h] BYREF
  int nlineinfos; // [esp+14h] [ebp-20h] BYREF
  int nfunctions; // [esp+18h] [ebp-1Ch] BYREF
  int nlocalvarinfos; // [esp+1Ch] [ebp-18h] BYREF
  int v29; // [esp+20h] [ebp-14h] BYREF
  int noutervalues; // [esp+24h] [ebp-10h] BYREF
  int nparameters; // [esp+28h] [ebp-Ch] BYREF
  int nliterals; // [esp+2Ch] [ebp-8h] BYREF
  SQFunctionProto *v33; // [esp+30h] [ebp-4h]

  v4 = up;
  v6 = this->_noutervalues;
  v7 = this->_nliterals;
  v8 = this->_nparameters;
  noutervalues = v6;
  v9 = this->_ninstructions;
  v10 = write;
  nliterals = v7;
  v11 = this->_nlocalvarinfos;
  nparameters = v8;
  v12 = this->_nlineinfos;
  ninstructions = v9;
  nlocalvarinfos = v11;
  v13 = this->_nfunctions;
  nlineinfos = v12;
  v14 = this->_ndefaultparams;
  v33 = this;
  nfunctions = v13;
  ndefaultparams = v14;
  v29 = 1346458196;
  if ( ((int (__cdecl *)(SQLocalVarInfo *, int *, int))write)(a1: up, a2: &v29, a3: 4) != 4 )
  {
    SQVM::Raise_Error(a1: (_DWORD *)v, this: (SQVM *)&stru_1009CBCC._foreignptr, s: v23);
    return false;
  }
  v22 = v10;
  v16 = (SQVM *)v;
  if ( WriteObject(up: v4, o: &this->_sourcename, (SQVM *)v, write: v22) == 0 )
    return false;
  p_name = &this->_name;
  v18 = write;
  if ( WriteObject(up: v4, o: p_name, v: v16, write) == 0 )
    return false;
  v = 1346458196;
  if ( ((int (__cdecl *)(SQLocalVarInfo *, int *, int))v18)(a1: v4, a2: &v, a3: 4) == 4
    && ((int (__cdecl *)(SQLocalVarInfo *, int *, int))v18)(a1: v4, a2: &nliterals, a3: 4) == 4
    && ((int (__cdecl *)(SQLocalVarInfo *, int *, int))v18)(a1: v4, a2: &nparameters, a3: 4) == 4 )
  {
    if ( SafeWrite(v: v16, up: v4, dest: &noutervalues, size: 4, write: v18) == 0 )
      return false;
    if ( SafeWrite(v: v16, up: v4, dest: &nlocalvarinfos, size: 4, write) == 0 )
      return false;
    if ( SafeWrite(v: v16, up: v4, dest: &nlineinfos, size: 4, write) == 0 )
      return false;
    if ( SafeWrite(v: v16, up: v4, dest: &ndefaultparams, size: 4, write) == 0 )
      return false;
    if ( SafeWrite(v: v16, up: v4, dest: &ninstructions, size: 4, write) == 0 )
      return false;
    if ( SafeWrite(v: v16, up: v4, dest: &nfunctions, size: 4, write) == 0 )
      return false;
    v19 = write;
    if ( WriteTag(v: v16, up: v4, (int (__stdcall *)(void *))write) == 0 )
      return false;
    v = 0;
    if ( nliterals > 0 )
    {
      while ( WriteObject(up: v4, o: &v33->_literals[v], v: v16, write: v19) != 0 )
      {
        if ( ++v >= nliterals )
          goto LABEL_20;
      }
      return false;
    }
LABEL_20:
    if ( WriteTag(v: v16, up: v4, write: (int (__stdcall *)(void *))v19) == 0 )
      return false;
    v = 0;
    if ( nparameters > 0 )
    {
      while ( WriteObject(up: v4, o: &v33->_parameters[v], v: v16, write: v19) != 0 )
      {
        if ( ++v >= nparameters )
          goto LABEL_24;
      }
      return false;
    }
LABEL_24:
    if ( WriteTag(v: v16, up: v4, write: (int (__stdcall *)(void *))v19) == 0 )
      return false;
    v = 0;
    if ( noutervalues > 0 )
    {
      up = nullptr;
      while ( SafeWrite(v: v16, up: v4, dest: (char *)up + (unsigned int)v33->_outervalues, size: 4, write: v19) != 0 )
      {
        v20 = up;
        if ( WriteObject(up: v4, o: (SQObjectPtr *)((char *)&v33->_outervalues->_src + (unsigned int)up), v: v16, write) == 0
          || WriteObject(
               up: v4,
               o: (SQObjectPtr *)((char *)&v33->_outervalues->_name + (unsigned int)v20),
               v: v16,
               write) == 0 )
        {
          break;
        }
        up = v20 + 1;
        v19 = write;
        if ( ++v >= noutervalues )
          goto LABEL_31;
      }
      return false;
    }
LABEL_31:
    if ( WriteTag(v: v16, up: v4, write: (int (__stdcall *)(void *))v19) == 0 )
      return false;
    v = 0;
    if ( nlocalvarinfos > 0 )
    {
      v29 = 0;
      do
      {
        up = (SQLocalVarInfo *)((char *)v33->_localvarinfos + v29);
        if ( WriteObject(up: v4, o: &up->_name, v: v16, write: v19) == 0
          || SafeWrite(v: v16, up: v4, dest: &up->_pos, size: 4, write: v19) == 0
          || SafeWrite(v: v16, up: v4, dest: &up->_start_op, size: 4, write) == 0
          || SafeWrite(v: v16, up: v4, dest: &up->_end_op, size: 4, write) == 0 )
        {
          return false;
        }
        v29 += 20;
        v19 = write;
      }
      while ( ++v < nlocalvarinfos );
    }
    if ( WriteTag(v: v16, up: v4, write: (int (__stdcall *)(void *))v19) == 0
      || SafeWrite(v: v16, up: v4, dest: v33->_lineinfos, size: 8 * nlineinfos, write) == 0
      || WriteTag(v: v16, up: v4, (int (__stdcall *)(void *))write) == 0
      || SafeWrite(v: v16, up: v4, dest: v33->_defaultparams, size: 4 * ndefaultparams, write) == 0
      || WriteTag(v: v16, up: v4, (int (__stdcall *)(void *))write) == 0
      || SafeWrite(v: v16, up: v4, dest: v33->_instructions, size: 8 * ninstructions, write) == 0
      || WriteTag(v: v16, up: v4, (int (__stdcall *)(void *))write) == 0 )
    {
      return false;
    }
    v21 = 0;
    if ( nfunctions > 0 )
    {
      while ( SQFunctionProto::Save(
                this: v33->_functions[v21]._unVal.pFunctionProto,
                v: v16,
                up: v4,
                (int (__cdecl *)(void *, void *, int))write) )
      {
        if ( ++v21 >= nfunctions )
          goto LABEL_49;
      }
      return false;
    }
LABEL_49:
    if ( SafeWrite(v: v16, up: v4, dest: &v33->_stacksize, size: 4, write) == 0
      || SafeWrite(v: v16, up: v4, dest: &v33->_bgenerator, size: 1, write) == 0 )
    {
      return false;
    }
    return SafeWrite(v: v16, up: v4, dest: &v33->_varparams, size: 1, write) != 0;
  }
  else
  {
    SQVM::Raise_Error(a1: v16, this: (SQVM *)&stru_1009CBCC._foreignptr, s: v23);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E670
// Name: public: static bool SQFunctionProto::Load(struct SQVM __near *,void __near *,int (*)(void __near *,void __near *,int),struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SQFunctionProto::Load(SQVM *v, void *up, int (__cdecl *read)(void *, void *, int), SQObjectPtr *ret)
{
  tagSQObjectValue v5; // eax
  int *pTable; // ecx
  int *v7; // ecx
  tagSQObjectValue v8; // eax
  SQFunctionProto *v9; // edi
  int (__cdecl *v10)(void *, void *, int); // edi
  const SQOuterVar *v11; // eax
  int v12; // edi
  SQOuterVar *v13; // ecx
  SQFunctionProto *v14; // esi
  SQFunctionProto *v15; // eax
  const char *v16; // [esp+0h] [ebp-78h]
  SQLocalVarInfo lvi; // [esp+Ch] [ebp-6Ch] BYREF
  SQObjectPtr obj; // [esp+20h] [ebp-58h] BYREF
  SQObjectPtr proto; // [esp+28h] [ebp-50h] BYREF
  SQObjectPtr name; // [esp+30h] [ebp-48h] BYREF
  SQObjectPtr sourcename; // [esp+38h] [ebp-40h] BYREF
  SQObjectPtr o; // [esp+40h] [ebp-38h] BYREF
  unsigned int type; // [esp+48h] [ebp-30h] BYREF
  int ninstructions; // [esp+4Ch] [ebp-2Ch] BYREF
  int ndefaultparams; // [esp+50h] [ebp-28h] BYREF
  int nlineinfos; // [esp+54h] [ebp-24h] BYREF
  int nfunctions; // [esp+58h] [ebp-20h] BYREF
  int nlocalvarinfos; // [esp+5Ch] [ebp-1Ch] BYREF
  int v29; // [esp+60h] [ebp-18h] BYREF
  int noutervalues; // [esp+64h] [ebp-14h] BYREF
  int nparameters; // [esp+68h] [ebp-10h] BYREF
  int nliterals; // [esp+6Ch] [ebp-Ch] BYREF
  SQFunctionProto *f; // [esp+70h] [ebp-8h]
  int i; // [esp+74h] [ebp-4h]

  sourcename._type = OT_NULL;
  name._type = OT_NULL;
  o._type = OT_NULL;
  sourcename._unVal.nInteger = 0;
  name._unVal.nInteger = 0;
  o._unVal.nInteger = 0;
  if ( read(a1: up, a2: &v29, a3: 4) != 4 )
  {
    SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80, s: v16);
    return 0;
  }
  if ( v29 != 1346458196 )
  {
    SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80._errorhandler, s: v16);
    return 0;
  }
  if ( ReadObject(up, v, (SQSharedState *)read, o: &sourcename) != 0 )
  {
    if ( ReadObject(up, v, (SQSharedState *)read, o: &name) == 0 || CheckTag(v, up, read) == 0 )
    {
      if ( (o._type & 0x8000000) != 0 )
      {
        v8.pTable = (SQTable *)o._unVal;
        --*(_DWORD *)(o._unVal.nInteger + 4);
        if ( *(int *)(v8.nInteger + 4) <= 0 )
          o._unVal.pTable->Release(this: (struct SQTable *)o._unVal.nInteger);
      }
      if ( (name._type & 0x8000000) == 0 )
        goto LABEL_11;
      pTable = (int *)name._unVal.pTable;
      --*(_DWORD *)(name._unVal.nInteger + 4);
      if ( pTable[1] > 0 )
        goto LABEL_11;
      goto LABEL_10;
    }
    if ( read(a1: up, a2: &nliterals, a3: 4) != 4
      || read(a1: up, a2: &nparameters, a3: 4) != 4
      || read(a1: up, a2: &noutervalues, a3: 4) != 4
      || read(a1: up, a2: &nlocalvarinfos, a3: 4) != 4
      || read(a1: up, a2: &nlineinfos, a3: 4) != 4
      || read(a1: up, a2: &ndefaultparams, a3: 4) != 4
      || read(a1: up, a2: &ninstructions, a3: 4) != 4
      || read(a1: up, a2: &nfunctions, a3: 4) != 4 )
    {
      SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80, s: v16);
      goto LABEL_24;
    }
    v9 = SQFunctionProto::Create(
           noutervalues,
           nlocalvarinfos,
           ninstructions,
           nliterals,
           nparameters,
           nfunctions,
           nlineinfos,
           ndefaultparams);
    ++v9->_uiRef;
    f = v9;
    proto._type = OT_FUNCPROTO;
    proto._unVal.nInteger = (int)v9;
    SQObjectPtr::operator=(this: &v9->_sourcename, obj: &sourcename);
    SQObjectPtr::operator=(this: &v9->_name, obj: &name);
    v10 = read;
    if ( CheckTag(v, up, read) != 0 )
    {
      i = 0;
      if ( nliterals > 0 )
      {
        while ( ReadObject(up, v, (SQSharedState *)read, &o) != 0 )
        {
          SQObjectPtr::operator=(this: &f->_literals[i++], obj: &o);
          if ( i >= nliterals )
            goto LABEL_36;
        }
        goto LABEL_58;
      }
LABEL_36:
      if ( CheckTag(v, up, read) != 0 )
      {
        i = 0;
        if ( nparameters > 0 )
        {
          while ( ReadObject(up, v, (SQSharedState *)read, &o) != 0 )
          {
            SQObjectPtr::operator=(this: &f->_parameters[i++], obj: &o);
            if ( i >= nparameters )
              goto LABEL_40;
          }
          goto LABEL_58;
        }
LABEL_40:
        if ( CheckTag(v, up, read) != 0 )
        {
          i = 0;
          if ( noutervalues > 0 )
          {
            v29 = 0;
            while ( 1 )
            {
              obj._type = OT_NULL;
              obj._unVal.nInteger = 0;
              if ( v10(a1: up, a2: &type, a3: 4) != 4 )
                break;
              if ( ReadObject(up, v, read: (SQSharedState *)v10, &o) == 0
                || ReadObject(up, v, read: (SQSharedState *)v10, o: &obj) == 0 )
              {
                goto LABEL_57;
              }
              v11 = SQOuterVar::SQOuterVar(this: (SQOuterVar *)&lvi, name: &obj, src: &o, t: (SQOuterType)type);
              v12 = v29;
              SQOuterVar::operator=(this: (SQOuterVar *)((char *)f->_outervalues + v29), __that: v11);
              SQOuterVar::~SQOuterVar(this: v13, a2: &lvi);
              SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&obj);
              v29 = v12 + 20;
              v10 = read;
              if ( ++i >= noutervalues )
                goto LABEL_47;
            }
            SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80, s: v16);
LABEL_57:
            SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&obj);
            goto LABEL_58;
          }
LABEL_47:
          if ( CheckTag(v, up, read: v10) == 0 )
            goto LABEL_58;
          i = 0;
          if ( nlocalvarinfos > 0 )
          {
            v29 = 0;
            while ( 1 )
            {
              memset(&lvi._name._unVal, 0, 12);
              lvi._name._type = OT_NULL;
              if ( ReadObject(up, v, read: (SQSharedState *)v10, o: &lvi._name) == 0 )
                break;
              if ( v10(a1: up, a2: &lvi._pos, a3: 4) != 4
                || v10(a1: up, a2: &lvi._start_op, a3: 4) != 4
                || v10(a1: up, a2: &lvi._end_op, a3: 4) != 4 )
              {
                SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80, s: v16);
                break;
              }
              SQLocalVarInfo::operator=(this: (SQLocalVarInfo *)((char *)f->_localvarinfos + v29), __that: &lvi);
              SQObjectPtr::~SQObjectPtr(this: &lvi);
              v29 += 20;
              v10 = read;
              if ( ++i >= nlocalvarinfos )
                goto LABEL_61;
            }
            SQObjectPtr::~SQObjectPtr(this: &lvi);
            SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&proto);
            goto LABEL_24;
          }
LABEL_61:
          if ( CheckTag(v, up, read: v10) == 0 )
            goto LABEL_58;
          if ( 8 * nlineinfos != 0 )
          {
            if ( SafeRead(v, up, dest: f->_lineinfos, size: 8 * nlineinfos, (int (__cdecl *)(void *, void *))read) == 0 )
              goto LABEL_58;
            v10 = read;
          }
          if ( CheckTag(v, up, read: v10) != 0 )
          {
            if ( 4 * ndefaultparams != 0 )
            {
              if ( SafeRead(
                     v,
                     up,
                     dest: f->_defaultparams,
                     size: 4 * ndefaultparams,
                     (int (__cdecl *)(void *, void *))read) == 0 )
                goto LABEL_58;
              v10 = read;
            }
            if ( CheckTag(v, up, read: v10) != 0 )
            {
              if ( 8 * ninstructions != 0 )
              {
                if ( SafeRead(
                       v,
                       up,
                       dest: f->_instructions,
                       size: 8 * ninstructions,
                       (int (__cdecl *)(void *, void *))read) == 0 )
                  goto LABEL_58;
                v10 = read;
              }
              if ( CheckTag(v, up, read: v10) != 0 )
              {
                i = 0;
                if ( nfunctions > 0 )
                {
                  while ( SQFunctionProto::Load(v, up, read: v10, ret: &o) )
                  {
                    SQObjectPtr::operator=(this: &f->_functions[i++], obj: &o);
                    if ( i >= nfunctions )
                      goto LABEL_77;
                  }
                  goto LABEL_58;
                }
LABEL_77:
                v14 = f;
                if ( v10(a1: up, a2: &f->_stacksize, a3: 4) == 4
                  && v10(a1: up, a2: &v14->_bgenerator, a3: 1) == 1
                  && v10(a1: up, a2: &v14->_varparams, a3: 1) == 1 )
                {
                  v15 = f;
                  ++f->_uiRef;
                  obj._unVal.nInteger = (int)v15;
                  obj._type = OT_FUNCPROTO;
                  SQObjectPtr::operator=(this: ret, &obj);
                  SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&obj);
                  SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&proto);
                  SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&o);
                  SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&name);
                  SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&sourcename);
                  return 1;
                }
                SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009CC80, s: v16);
                SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&proto);
LABEL_24:
                SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&o);
                SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&name);
                SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&sourcename);
                return 0;
              }
            }
          }
        }
      }
    }
LABEL_58:
    SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&proto);
    goto LABEL_24;
  }
  if ( (o._type & 0x8000000) != 0 )
  {
    v5.pTable = (SQTable *)o._unVal;
    --*(_DWORD *)(o._unVal.nInteger + 4);
    if ( *(int *)(v5.nInteger + 4) > 0 )
      goto LABEL_11;
    pTable = (int *)o._unVal.pTable;
LABEL_10:
    (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
LABEL_11:
  if ( (sourcename._type & 0x8000000) == 0 )
    return 0;
  v7 = (int *)sourcename._unVal.pTable;
  --*(_DWORD *)(sourcename._unVal.nInteger + 4);
  if ( v7[1] > 0 )
    return 0;
  (*(void (__thiscall **)(int *))(*v7 + 8))(a1: v7);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004ED10
// Name: public: virtual void SQVM::Mark(struct SQCollectable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQVM::Mark(SQVM *this, SQCollectable **chain)
{
  int uiRef; // eax
  unsigned int i; // ebx
  SQObjectPtr *v6; // ecx
  int type; // eax
  bool v8; // zf
  unsigned int j; // ebx
  SQObjectPtr *vals; // ecx
  int v11; // eax
  SQObjectPtr *v12; // ecx
  bool v13; // zf
  int v14; // ebx
  SQVM::CallInfo *callsstack; // ecx
  int v16; // eax
  int p_closure; // ecx
  bool v18; // zf
  SQCollectable *prev; // ecx
  SQCollectable *next; // eax
  int k; // [esp+Ch] [ebp+8h]

  uiRef = this->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    this->_uiRef = uiRef | 0x40000000;
    SQSharedState::MarkObject(o: &this->_lasterror, chain);
    SQSharedState::MarkObject(o: &this->_errorhandler, chain);
    SQSharedState::MarkObject(o: &this->_debughook, chain);
    SQSharedState::MarkObject(o: &this->_roottable, chain);
    SQSharedState::MarkObject(o: &this->temp_reg, chain);
    for ( i = 0; i < this->_stack._size; ++i )
    {
      v6 = &this->_stack._vals[i];
      type = v6->_type;
      if ( v6->_type > OT_THREAD )
      {
        if ( type > 167772288 )
        {
          v8 = type == 167804928;
        }
        else
        {
          if ( type == 167772288 || type == 134234112 )
          {
LABEL_16:
            v6->_unVal.pTable->Mark(this: v6->_unVal.pTable, a2: chain);
            continue;
          }
          v8 = type == 167772192;
        }
      }
      else
      {
        if ( v6->_type == OT_THREAD )
          goto LABEL_16;
        if ( type > 134218240 )
        {
          v8 = type == 134218752;
        }
        else
        {
          if ( type == 134218240 || type == 134217792 )
            goto LABEL_16;
          v8 = type == 134217984;
        }
      }
      if ( v8 )
        goto LABEL_16;
    }
    for ( j = 0; j < this->_vargsstack._size; ++j )
    {
      vals = this->_vargsstack._vals;
      v11 = vals[j]._type;
      v12 = &vals[j];
      if ( v11 > 134221824 )
      {
        if ( v11 > 167772288 )
        {
          v13 = v11 == 167804928;
        }
        else
        {
          if ( v11 == 167772288 || v11 == 134234112 )
          {
LABEL_32:
            v12->_unVal.pTable->Mark(this: v12->_unVal.pTable, a2: chain);
            continue;
          }
          v13 = v11 == 167772192;
        }
      }
      else
      {
        if ( v11 == 134221824 )
          goto LABEL_32;
        if ( v11 > 134218240 )
        {
          v13 = v11 == 134218752;
        }
        else
        {
          if ( v11 == 134218240 || v11 == 134217792 )
            goto LABEL_32;
          v13 = v11 == 134217984;
        }
      }
      if ( v13 )
        goto LABEL_32;
    }
    v14 = 0;
    for ( k = 0; k < this->_callsstacksize; ++k )
    {
      callsstack = this->_callsstack;
      v16 = callsstack[v14]._closure._type;
      p_closure = (int)&callsstack[v14]._closure;
      if ( v16 > 134221824 )
      {
        if ( v16 > 167772288 )
        {
          v18 = v16 == 167804928;
        }
        else
        {
          if ( v16 == 167772288 || v16 == 134234112 )
          {
LABEL_48:
            (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(p_closure + 4) + 12))(
              a1: *(_DWORD *)(p_closure + 4),
              a2: chain);
            goto LABEL_49;
          }
          v18 = v16 == 167772192;
        }
      }
      else
      {
        if ( v16 == 134221824 )
          goto LABEL_48;
        if ( v16 > 134218240 )
        {
          v18 = v16 == 134218752;
        }
        else
        {
          if ( v16 == 134218240 || v16 == 134217792 )
            goto LABEL_48;
          v18 = v16 == 134217984;
        }
      }
      if ( v18 )
        goto LABEL_48;
LABEL_49:
      ++v14;
    }
    prev = this->_prev;
    if ( prev != nullptr )
      prev->_next = this->_next;
    else
      this->_sharedstate->_gc_chain = this->_next;
    next = this->_next;
    if ( next != nullptr )
      next->_prev = this->_prev;
    this->_next = nullptr;
    this->_prev = nullptr;
    this->_next = *chain;
    if ( *chain != nullptr )
      (*chain)->_prev = this;
    *chain = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004EF00
// Name: public: virtual void SQArray::Mark(struct SQCollectable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQArray::Mark(SQArray *this, SQArray **chain)
{
  int uiRef; // eax
  signed int v4; // ebx
  SQObjectPtr *v5; // ecx
  int type; // eax
  bool v7; // zf
  SQCollectable *prev; // ecx
  SQCollectable *next; // eax
  signed int len; // [esp+4h] [ebp-4h]

  uiRef = this->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    this->_uiRef = uiRef | 0x40000000;
    v4 = 0;
    len = this->_values._size;
    if ( len > 0 )
    {
      do
      {
        v5 = &this->_values._vals[v4];
        type = v5->_type;
        if ( v5->_type > OT_THREAD )
        {
          if ( type > 167772288 )
          {
            v7 = type == 167804928;
          }
          else
          {
            if ( type == 167772288 || type == 134234112 )
            {
LABEL_16:
              v5->_unVal.pTable->Mark(this: v5->_unVal.pTable, a2: chain);
              goto LABEL_17;
            }
            v7 = type == 167772192;
          }
        }
        else
        {
          if ( v5->_type == OT_THREAD )
            goto LABEL_16;
          if ( type > 134218240 )
          {
            v7 = type == 134218752;
          }
          else
          {
            if ( type == 134218240 || type == 134217792 )
              goto LABEL_16;
            v7 = type == 134217984;
          }
        }
        if ( v7 )
          goto LABEL_16;
LABEL_17:
        ++v4;
      }
      while ( v4 < len );
    }
    prev = this->_prev;
    if ( prev != nullptr )
      prev->_next = this->_next;
    else
      this->_sharedstate->_gc_chain = this->_next;
    next = this->_next;
    if ( next != nullptr )
      next->_prev = this->_prev;
    this->_next = nullptr;
    this->_prev = nullptr;
    this->_next = *chain;
    if ( *chain != nullptr )
      (*chain)->_prev = this;
    *chain = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004EFE0
// Name: public: virtual void SQTable::Mark(struct SQCollectable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQTable::Mark(SQTable *this, SQTable **chain)
{
  int uiRef; // eax
  SQTable *delegate; // ecx
  int v6; // ebx
  SQObjectPtr *p_key; // ecx
  int type; // eax
  bool v9; // zf
  tagSQObjectValue v10; // ecx
  SQTable::_HashNode *nodes; // eax
  int v12; // ecx
  SQTable::_HashNode *v13; // eax
  bool v14; // zf
  SQCollectable *prev; // ecx
  SQCollectable *next; // eax
  SQCollectable **chaina; // [esp+Ch] [ebp+8h]

  uiRef = this->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    delegate = this->_delegate;
    this->_uiRef = uiRef | 0x40000000;
    if ( delegate != nullptr )
      delegate->Mark(this: delegate, a2: chain);
    if ( this->_numofnodes > 0 )
    {
      v6 = 0;
      for ( chaina = (SQCollectable **)this->_numofnodes; chaina != nullptr; chaina = (SQCollectable **)((char *)chaina - 1) )
      {
        p_key = &this->_nodes[v6].key;
        type = p_key->_type;
        if ( p_key->_type > OT_THREAD )
        {
          if ( type > 167772288 )
          {
            v9 = type == 167804928;
LABEL_18:
            if ( !v9 )
              goto LABEL_20;
            goto LABEL_19;
          }
          if ( type != 167772288 && type != 134234112 )
          {
            v9 = type == 167772192;
            goto LABEL_18;
          }
        }
        else if ( p_key->_type != OT_THREAD )
        {
          if ( type > 134218240 )
          {
            v9 = type == 134218752;
            goto LABEL_18;
          }
          if ( type != 134218240 && type != 134217792 )
          {
            v9 = type == 134217984;
            goto LABEL_18;
          }
        }
LABEL_19:
        v10.pTable = (SQTable *)this->_nodes[v6].key._unVal;
        ((void (__thiscall *)(tagSQObjectValue, SQTable **))v10.pTable->Mark)(a1: v10, a2: chain);
LABEL_20:
        nodes = this->_nodes;
        v12 = nodes[v6].val._type;
        v13 = &nodes[v6];
        if ( v12 > 134221824 )
        {
          if ( v12 > 167772288 )
          {
            v14 = v12 == 167804928;
          }
          else
          {
            if ( v12 == 167772288 || v12 == 134234112 )
            {
LABEL_33:
              v13->val._unVal.pTable->Mark(this: v13->val._unVal.pTable, a2: chain);
              goto LABEL_34;
            }
            v14 = v12 == 167772192;
          }
        }
        else
        {
          if ( v12 == 134221824 )
            goto LABEL_33;
          if ( v12 > 134218240 )
          {
            v14 = v12 == 134218752;
          }
          else
          {
            if ( v12 == 134218240 || v12 == 134217792 )
              goto LABEL_33;
            v14 = v12 == 134217984;
          }
        }
        if ( v14 )
          goto LABEL_33;
LABEL_34:
        ++v6;
      }
    }
    prev = this->_prev;
    if ( prev != nullptr )
      prev->_next = this->_next;
    else
      this->_sharedstate->_gc_chain = this->_next;
    next = this->_next;
    if ( next != nullptr )
      next->_prev = this->_prev;
    this->_next = nullptr;
    this->_prev = nullptr;
    this->_next = *chain;
    if ( *chain != nullptr )
      (*chain)->_prev = this;
    *chain = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F130
// Name: public: virtual void SQClass::Mark(struct SQCollectable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQClass::Mark(SQClass *this, SQCollectable **chain)
{
  int uiRef; // eax
  SQTable *members; // ecx
  SQClass *base; // ecx
  unsigned int v7; // ebx
  int v8; // edi
  SQClassMember *vals; // eax
  int type; // ecx
  SQClassMember *v11; // eax
  bool v12; // zf
  SQClassMember *v13; // edx
  int v14; // eax
  bool v15; // zf
  int v16; // edi
  SQClassMember *v17; // eax
  int v18; // ecx
  SQClassMember *v19; // eax
  bool v20; // zf
  SQClassMember *v21; // ecx
  int v22; // eax
  int p_attrs; // ecx
  bool v24; // zf
  unsigned int i; // edi
  SQObjectPtr *v26; // ecx
  int v27; // eax
  SQObjectPtr *v28; // ecx
  bool v29; // zf
  SQCollectable *prev; // ecx
  SQCollectable *next; // eax
  unsigned int j; // [esp+10h] [ebp+8h]

  uiRef = this->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    members = this->_members;
    this->_uiRef = uiRef | 0x40000000;
    members->Mark(this: members, a2: chain);
    base = this->_base;
    if ( base != nullptr )
      base->Mark(this: base, a2: chain);
    SQSharedState::MarkObject(o: &this->_attributes, chain);
    v7 = 0;
    if ( this->_defaultvalues._size != 0 )
    {
      v8 = 0;
      do
      {
        vals = this->_defaultvalues._vals;
        type = vals[v8].val._type;
        v11 = &vals[v8];
        if ( type > 134221824 )
        {
          if ( type > 167772288 )
          {
            v12 = type == 167804928;
LABEL_18:
            if ( !v12 )
              goto LABEL_20;
            goto LABEL_19;
          }
          if ( type != 167772288 && type != 134234112 )
          {
            v12 = type == 167772192;
            goto LABEL_18;
          }
        }
        else if ( type != 134221824 )
        {
          if ( type > 134218240 )
          {
            v12 = type == 134218752;
            goto LABEL_18;
          }
          if ( type != 134218240 && type != 134217792 )
          {
            v12 = type == 134217984;
            goto LABEL_18;
          }
        }
LABEL_19:
        v11->val._unVal.pTable->Mark(this: v11->val._unVal.pTable, a2: chain);
LABEL_20:
        v13 = this->_defaultvalues._vals;
        v14 = v13[v8].attrs._type;
        if ( v14 > 134221824 )
        {
          if ( v14 > 167772288 )
          {
            v15 = v14 == 167804928;
          }
          else
          {
            if ( v14 == 167772288 || v14 == 134234112 )
            {
LABEL_33:
              v13[v8].attrs._unVal.pTable->Mark(this: v13[v8].attrs._unVal.pTable, a2: chain);
              goto LABEL_34;
            }
            v15 = v14 == 167772192;
          }
        }
        else
        {
          if ( v14 == 134221824 )
            goto LABEL_33;
          if ( v14 > 134218240 )
          {
            v15 = v14 == 134218752;
          }
          else
          {
            if ( v14 == 134218240 || v14 == 134217792 )
              goto LABEL_33;
            v15 = v14 == 134217984;
          }
        }
        if ( v15 )
          goto LABEL_33;
LABEL_34:
        ++v7;
        ++v8;
      }
      while ( v7 < this->_defaultvalues._size );
    }
    j = 0;
    if ( this->_methods._size != 0 )
    {
      v16 = 0;
      do
      {
        v17 = this->_methods._vals;
        v18 = v17[v16].val._type;
        v19 = &v17[v16];
        if ( v18 > 134221824 )
        {
          if ( v18 > 167772288 )
          {
            v20 = v18 == 167804928;
LABEL_49:
            if ( !v20 )
              goto LABEL_51;
            goto LABEL_50;
          }
          if ( v18 != 167772288 && v18 != 134234112 )
          {
            v20 = v18 == 167772192;
            goto LABEL_49;
          }
        }
        else if ( v18 != 134221824 )
        {
          if ( v18 > 134218240 )
          {
            v20 = v18 == 134218752;
            goto LABEL_49;
          }
          if ( v18 != 134218240 && v18 != 134217792 )
          {
            v20 = v18 == 134217984;
            goto LABEL_49;
          }
        }
LABEL_50:
        v19->val._unVal.pTable->Mark(this: v19->val._unVal.pTable, a2: chain);
LABEL_51:
        v21 = this->_methods._vals;
        v22 = v21[v16].attrs._type;
        p_attrs = (int)&v21[v16].attrs;
        if ( v22 > 134221824 )
        {
          if ( v22 > 167772288 )
          {
            v24 = v22 == 167804928;
          }
          else
          {
            if ( v22 == 167772288 || v22 == 134234112 )
            {
LABEL_64:
              (*(void (__thiscall **)(_DWORD, SQCollectable **))(**(_DWORD **)(p_attrs + 4) + 12))(
                a1: *(_DWORD *)(p_attrs + 4),
                a2: chain);
              goto LABEL_65;
            }
            v24 = v22 == 167772192;
          }
        }
        else
        {
          if ( v22 == 134221824 )
            goto LABEL_64;
          if ( v22 > 134218240 )
          {
            v24 = v22 == 134218752;
          }
          else
          {
            if ( v22 == 134218240 || v22 == 134217792 )
              goto LABEL_64;
            v24 = v22 == 134217984;
          }
        }
        if ( v24 )
          goto LABEL_64;
LABEL_65:
        ++v16;
        ++j;
      }
      while ( j < this->_methods._size );
    }
    for ( i = 0; i < this->_metamethods._size; ++i )
    {
      v26 = this->_metamethods._vals;
      v27 = v26[i]._type;
      v28 = &v26[i];
      if ( v27 > 134221824 )
      {
        if ( v27 > 167772288 )
        {
          v29 = v27 == 167804928;
        }
        else
        {
          if ( v27 == 167772288 || v27 == 134234112 )
          {
LABEL_80:
            v28->_unVal.pTable->Mark(this: v28->_unVal.pTable, a2: chain);
            continue;
          }
          v29 = v27 == 167772192;
        }
      }
      else
      {
        if ( v27 == 134221824 )
          goto LABEL_80;
        if ( v27 > 134218240 )
        {
          v29 = v27 == 134218752;
        }
        else
        {
          if ( v27 == 134218240 || v27 == 134217792 )
            goto LABEL_80;
          v29 = v27 == 134217984;
        }
      }
      if ( v29 )
        goto LABEL_80;
    }
    prev = this->_prev;
    if ( prev != nullptr )
      prev->_next = this->_next;
    else
      this->_sharedstate->_gc_chain = this->_next;
    next = this->_next;
    if ( next != nullptr )
      next->_prev = this->_prev;
    this->_next = nullptr;
    this->_prev = nullptr;
    this->_next = *chain;
    if ( *chain != nullptr )
      (*chain)->_prev = this;
    *chain = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F400
// Name: public: virtual void SQInstance::Mark(struct SQCollectable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQInstance::Mark(SQInstance *this, SQInstance **chain)
{
  int uiRef; // eax
  SQClass *v4; // ecx
  tagSQObjectValue *p_unVal; // esi
  int nInteger; // eax
  bool v8; // zf
  SQCollectable *prev; // ecx
  SQCollectable *next; // eax
  SQCollectable **chaina; // [esp+Ch] [ebp+8h]

  uiRef = this->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    v4 = this->_class;
    this->_uiRef = uiRef | 0x40000000;
    v4->Mark(this: v4, a2: chain);
    if ( this->_class->_defaultvalues._size != 0 )
    {
      p_unVal = &this->_values[0]._unVal;
      for ( chaina = (SQCollectable **)this->_class->_defaultvalues._size;
            chaina != nullptr;
            chaina = (SQCollectable **)((char *)chaina - 1) )
      {
        nInteger = p_unVal[-1].nInteger;
        if ( nInteger > 134221824 )
        {
          if ( nInteger > 167772288 )
          {
            v8 = nInteger == 167804928;
          }
          else
          {
            if ( nInteger == 167772288 || nInteger == 134234112 )
            {
LABEL_17:
              p_unVal->pTable->Mark(this: p_unVal->pTable, a2: chain);
              goto LABEL_18;
            }
            v8 = nInteger == 167772192;
          }
        }
        else
        {
          if ( nInteger == 134221824 )
            goto LABEL_17;
          if ( nInteger > 134218240 )
          {
            v8 = nInteger == 134218752;
          }
          else
          {
            if ( nInteger == 134218240 || nInteger == 134217792 )
              goto LABEL_17;
            v8 = nInteger == 134217984;
          }
        }
        if ( v8 )
          goto LABEL_17;
LABEL_18:
        p_unVal += 2;
      }
    }
    prev = this->_prev;
    if ( prev != nullptr )
      prev->_next = this->_next;
    else
      this->_sharedstate->_gc_chain = this->_next;
    next = this->_next;
    if ( next != nullptr )
      next->_prev = this->_prev;
    this->_next = nullptr;
    this->_prev = nullptr;
    this->_next = *chain;
    if ( *chain != nullptr )
      (*chain)->_prev = this;
    *chain = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F4E0
// Name: public: virtual void SQGenerator::Mark(struct SQCollectable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQGenerator::Mark(SQGenerator *this, SQGenerator **chain)
{
  int uiRef; // eax
  unsigned int v4; // ebx
  SQObjectPtr *v5; // ecx
  int type; // eax
  bool v7; // zf
  unsigned int i; // ebx
  SQObjectPtr *vals; // ecx
  int v10; // eax
  SQObjectPtr *v11; // ecx
  bool v12; // zf
  tagSQObjectType v13; // eax
  bool v14; // zf
  SQCollectable *prev; // ecx
  SQCollectable *next; // eax

  uiRef = this->_uiRef;
  if ( (uiRef & 0x40000000) != 0 )
    return;
  v4 = 0;
  for ( this->_uiRef = uiRef | 0x40000000; v4 < this->_stack._size; ++v4 )
  {
    v5 = &this->_stack._vals[v4];
    type = v5->_type;
    if ( v5->_type > OT_THREAD )
    {
      if ( type > 167772288 )
      {
        v7 = type == 167804928;
      }
      else
      {
        if ( type == 167772288 || type == 134234112 )
        {
LABEL_16:
          v5->_unVal.pTable->Mark(this: v5->_unVal.pTable, a2: chain);
          continue;
        }
        v7 = type == 167772192;
      }
    }
    else
    {
      if ( v5->_type == OT_THREAD )
        goto LABEL_16;
      if ( type > 134218240 )
      {
        v7 = type == 134218752;
      }
      else
      {
        if ( type == 134218240 || type == 134217792 )
          goto LABEL_16;
        v7 = type == 134217984;
      }
    }
    if ( v7 )
      goto LABEL_16;
  }
  for ( i = 0; i < this->_vargsstack._size; ++i )
  {
    vals = this->_vargsstack._vals;
    v10 = vals[i]._type;
    v11 = &vals[i];
    if ( v10 > 134221824 )
    {
      if ( v10 > 167772288 )
      {
        v12 = v10 == 167804928;
      }
      else
      {
        if ( v10 == 167772288 || v10 == 134234112 )
        {
LABEL_32:
          v11->_unVal.pTable->Mark(this: v11->_unVal.pTable, a2: chain);
          continue;
        }
        v12 = v10 == 167772192;
      }
    }
    else
    {
      if ( v10 == 134221824 )
        goto LABEL_32;
      if ( v10 > 134218240 )
      {
        v12 = v10 == 134218752;
      }
      else
      {
        if ( v10 == 134218240 || v10 == 134217792 )
          goto LABEL_32;
        v12 = v10 == 134217984;
      }
    }
    if ( v12 )
      goto LABEL_32;
  }
  v13 = this->_closure._type;
  if ( v13 > OT_THREAD )
  {
    if ( v13 > OT_USERDATA )
    {
      v14 = v13 == OT_INSTANCE;
    }
    else
    {
      if ( v13 == OT_USERDATA || v13 == OT_CLASS )
        goto LABEL_47;
      v14 = v13 == OT_TABLE;
    }
  }
  else
  {
    if ( v13 == OT_THREAD )
    {
LABEL_47:
      this->_closure._unVal.pTable->Mark(this: (struct SQTable *)this->_closure._unVal.nInteger, a2: chain);
      goto LABEL_48;
    }
    if ( v13 > OT_NATIVECLOSURE )
    {
      v14 = v13 == OT_GENERATOR;
    }
    else
    {
      if ( v13 == OT_NATIVECLOSURE || v13 == OT_ARRAY )
        goto LABEL_47;
      v14 = v13 == OT_CLOSURE;
    }
  }
  if ( v14 )
    goto LABEL_47;
LABEL_48:
  prev = this->_prev;
  if ( prev != nullptr )
    prev->_next = this->_next;
  else
    this->_sharedstate->_gc_chain = this->_next;
  next = this->_next;
  if ( next != nullptr )
    next->_prev = this->_prev;
  this->_next = nullptr;
  this->_prev = nullptr;
  this->_next = *chain;
  if ( *chain != nullptr )
    (*chain)->_prev = this;
  *chain = this;
}

//------------------------------------------------------------------------------
// Address: 0x1004F670
// Name: public: virtual void SQClosure::Mark(struct SQCollectable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQClosure::Mark(SQClosure *this, SQClosure **chain)
{
  int uiRef; // eax
  unsigned int v4; // ebx
  SQObjectPtr *v5; // ecx
  int type; // eax
  bool v7; // zf
  unsigned int i; // ebx
  SQObjectPtr *vals; // ecx
  int v10; // eax
  SQObjectPtr *v11; // ecx
  bool v12; // zf
  SQCollectable *prev; // ecx
  SQCollectable *next; // eax

  uiRef = this->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    v4 = 0;
    for ( this->_uiRef = uiRef | 0x40000000; v4 < this->_outervalues._size; ++v4 )
    {
      v5 = &this->_outervalues._vals[v4];
      type = v5->_type;
      if ( v5->_type > OT_THREAD )
      {
        if ( type > 167772288 )
        {
          v7 = type == 167804928;
        }
        else
        {
          if ( type == 167772288 || type == 134234112 )
          {
LABEL_16:
            v5->_unVal.pTable->Mark(this: v5->_unVal.pTable, a2: chain);
            continue;
          }
          v7 = type == 167772192;
        }
      }
      else
      {
        if ( v5->_type == OT_THREAD )
          goto LABEL_16;
        if ( type > 134218240 )
        {
          v7 = type == 134218752;
        }
        else
        {
          if ( type == 134218240 || type == 134217792 )
            goto LABEL_16;
          v7 = type == 134217984;
        }
      }
      if ( v7 )
        goto LABEL_16;
    }
    for ( i = 0; i < this->_defaultparams._size; ++i )
    {
      vals = this->_defaultparams._vals;
      v10 = vals[i]._type;
      v11 = &vals[i];
      if ( v10 > 134221824 )
      {
        if ( v10 > 167772288 )
        {
          v12 = v10 == 167804928;
        }
        else
        {
          if ( v10 == 167772288 || v10 == 134234112 )
          {
LABEL_32:
            v11->_unVal.pTable->Mark(this: v11->_unVal.pTable, a2: chain);
            continue;
          }
          v12 = v10 == 167772192;
        }
      }
      else
      {
        if ( v10 == 134221824 )
          goto LABEL_32;
        if ( v10 > 134218240 )
        {
          v12 = v10 == 134218752;
        }
        else
        {
          if ( v10 == 134218240 || v10 == 134217792 )
            goto LABEL_32;
          v12 = v10 == 134217984;
        }
      }
      if ( v12 )
        goto LABEL_32;
    }
    prev = this->_prev;
    if ( prev != nullptr )
      prev->_next = this->_next;
    else
      this->_sharedstate->_gc_chain = this->_next;
    next = this->_next;
    if ( next != nullptr )
      next->_prev = this->_prev;
    this->_next = nullptr;
    this->_prev = nullptr;
    this->_next = *chain;
    if ( *chain != nullptr )
      (*chain)->_prev = this;
    *chain = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F7B0
// Name: public: virtual void SQNativeClosure::Mark(struct SQCollectable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQNativeClosure::Mark(SQNativeClosure *this, SQNativeClosure **chain)
{
  int uiRef; // eax
  unsigned int v4; // ebx
  SQObjectPtr *v5; // ecx
  int type; // eax
  bool v7; // zf
  SQCollectable *prev; // ecx
  SQCollectable *next; // eax

  uiRef = this->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    v4 = 0;
    for ( this->_uiRef = uiRef | 0x40000000; v4 < this->_outervalues._size; ++v4 )
    {
      v5 = &this->_outervalues._vals[v4];
      type = v5->_type;
      if ( v5->_type > OT_THREAD )
      {
        if ( type > 167772288 )
        {
          v7 = type == 167804928;
        }
        else
        {
          if ( type == 167772288 || type == 134234112 )
          {
LABEL_16:
            v5->_unVal.pTable->Mark(this: v5->_unVal.pTable, a2: chain);
            continue;
          }
          v7 = type == 167772192;
        }
      }
      else
      {
        if ( v5->_type == OT_THREAD )
          goto LABEL_16;
        if ( type > 134218240 )
        {
          v7 = type == 134218752;
        }
        else
        {
          if ( type == 134218240 || type == 134217792 )
            goto LABEL_16;
          v7 = type == 134217984;
        }
      }
      if ( v7 )
        goto LABEL_16;
    }
    prev = this->_prev;
    if ( prev != nullptr )
      prev->_next = this->_next;
    else
      this->_sharedstate->_gc_chain = this->_next;
    next = this->_next;
    if ( next != nullptr )
      next->_prev = this->_prev;
    this->_next = nullptr;
    this->_prev = nullptr;
    this->_next = *chain;
    if ( *chain != nullptr )
      (*chain)->_prev = this;
    *chain = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F880
// Name: public: virtual void SQUserData::Mark(struct SQCollectable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQUserData::Mark(SQUserData *this, SQUserData **chain)
{
  int uiRef; // eax
  SQTable *delegate; // ecx
  SQCollectable *prev; // ecx
  SQCollectable *next; // eax

  uiRef = this->_uiRef;
  if ( (uiRef & 0x40000000) == 0 )
  {
    delegate = this->_delegate;
    this->_uiRef = uiRef | 0x40000000;
    if ( delegate != nullptr )
      delegate->Mark(this: delegate, a2: chain);
    prev = this->_prev;
    if ( prev != nullptr )
      prev->_next = this->_next;
    else
      this->_sharedstate->_gc_chain = this->_next;
    next = this->_next;
    if ( next != nullptr )
      next->_prev = this->_prev;
    this->_next = nullptr;
    this->_prev = nullptr;
    this->_next = *chain;
    if ( *chain != nullptr )
      (*chain)->_prev = this;
    *chain = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F900
// Name: public: virtual void SQVM::Iterate(class CSQStateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQVM::Iterate(SQVM *this, CSQStateIterator *pIterator)
{
  SQObjectPtr *p_lasterror; // edi
  int type; // eax
  tagSQObjectType v5; // eax
  tagSQObjectType v6; // eax
  tagSQObjectType v7; // eax
  tagSQObjectType v8; // eax
  unsigned int i; // ebx
  SQObjectPtr *v10; // edi
  int v11; // eax
  unsigned int j; // ebx
  SQObjectPtr *v13; // edi
  int v14; // eax

  p_lasterror = &this->_lasterror;
  pIterator->PsuedoKey(this: pIterator, a2: (const char *)&stru_1009CC80.ci);
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &this->_lasterror);
  type = p_lasterror->_type;
  if ( p_lasterror->_type > OT_THREAD )
  {
    if ( type > 167772288 )
    {
      if ( type != 167804928 )
        goto LABEL_19;
    }
    else if ( type != 167772288 && type != 134234112 && type != 167772192 )
    {
      goto LABEL_19;
    }
  }
  else if ( p_lasterror->_type != OT_THREAD )
  {
    if ( type > 134218240 )
    {
      if ( type != 134218752 )
        goto LABEL_19;
    }
    else if ( type != 134218240 && type != 134217792 && type != 134217984 )
    {
      goto LABEL_19;
    }
  }
  if ( (*(_DWORD *)(this->_lasterror._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_lasterror._unVal.nInteger + 4) |= 0x40000000u;
    this->_lasterror._unVal.pTable->Iterate(this: (struct SQTable *)this->_lasterror._unVal.nInteger, a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_19:
  pIterator->PsuedoKey(this: pIterator, a2: (const char *)&stru_1009CC80._nnativecalls);
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &this->_errorhandler);
  v5 = this->_errorhandler._type;
  if ( v5 > OT_THREAD )
  {
    if ( v5 > OT_USERDATA )
    {
      if ( v5 != OT_INSTANCE )
        goto LABEL_37;
    }
    else if ( v5 != OT_USERDATA && v5 != OT_CLASS && v5 != OT_TABLE )
    {
      goto LABEL_37;
    }
  }
  else if ( this->_errorhandler._type != OT_THREAD )
  {
    if ( v5 > OT_NATIVECLOSURE )
    {
      if ( v5 != OT_GENERATOR )
        goto LABEL_37;
    }
    else if ( v5 != OT_NATIVECLOSURE && v5 != OT_ARRAY && v5 != OT_CLOSURE )
    {
      goto LABEL_37;
    }
  }
  if ( (*(_DWORD *)(this->_errorhandler._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_errorhandler._unVal.nInteger + 4) |= 0x40000000u;
    this->_errorhandler._unVal.pTable->Iterate(
      this: (struct SQTable *)this->_errorhandler._unVal.nInteger,
      a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_37:
  pIterator->PsuedoKey(this: pIterator, a2: (const char *)&stru_1009CC80._suspended_traps);
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &this->_debughook);
  v6 = this->_debughook._type;
  if ( v6 > OT_THREAD )
  {
    if ( v6 > OT_USERDATA )
    {
      if ( v6 != OT_INSTANCE )
        goto LABEL_55;
    }
    else if ( v6 != OT_USERDATA && v6 != OT_CLASS && v6 != OT_TABLE )
    {
      goto LABEL_55;
    }
  }
  else if ( this->_debughook._type != OT_THREAD )
  {
    if ( v6 > OT_NATIVECLOSURE )
    {
      if ( v6 != OT_GENERATOR )
        goto LABEL_55;
    }
    else if ( v6 != OT_NATIVECLOSURE && v6 != OT_ARRAY && v6 != OT_CLOSURE )
    {
      goto LABEL_55;
    }
  }
  if ( (*(_DWORD *)(this->_debughook._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_debughook._unVal.nInteger + 4) |= 0x40000000u;
    this->_debughook._unVal.pTable->Iterate(this: (struct SQTable *)this->_debughook._unVal.nInteger, a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_55:
  pIterator->PsuedoKey(this: pIterator, a2: "_roottable");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &this->_roottable);
  v7 = this->_roottable._type;
  if ( v7 > OT_THREAD )
  {
    if ( v7 > OT_USERDATA )
    {
      if ( v7 != OT_INSTANCE )
        goto LABEL_73;
    }
    else if ( v7 != OT_USERDATA && v7 != OT_CLASS && v7 != OT_TABLE )
    {
      goto LABEL_73;
    }
  }
  else if ( this->_roottable._type != OT_THREAD )
  {
    if ( v7 > OT_NATIVECLOSURE )
    {
      if ( v7 != OT_GENERATOR )
        goto LABEL_73;
    }
    else if ( v7 != OT_NATIVECLOSURE && v7 != OT_ARRAY && v7 != OT_CLOSURE )
    {
      goto LABEL_73;
    }
  }
  if ( (*(_DWORD *)(this->_roottable._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_roottable._unVal.nInteger + 4) |= 0x40000000u;
    this->_roottable._unVal.pTable->Iterate(this: (struct SQTable *)this->_roottable._unVal.nInteger, a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_73:
  pIterator->PsuedoKey(this: pIterator, a2: "temp_reg");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &this->temp_reg);
  v8 = this->temp_reg._type;
  if ( v8 > OT_THREAD )
  {
    if ( v8 > OT_USERDATA )
    {
      if ( v8 != OT_INSTANCE )
        goto LABEL_91;
    }
    else if ( v8 != OT_USERDATA && v8 != OT_CLASS && v8 != OT_TABLE )
    {
      goto LABEL_91;
    }
  }
  else if ( this->temp_reg._type != OT_THREAD )
  {
    if ( v8 > OT_NATIVECLOSURE )
    {
      if ( v8 != OT_GENERATOR )
        goto LABEL_91;
    }
    else if ( v8 != OT_NATIVECLOSURE && v8 != OT_ARRAY && v8 != OT_CLOSURE )
    {
      goto LABEL_91;
    }
  }
  if ( (*(_DWORD *)(this->temp_reg._unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->temp_reg._unVal.nInteger + 4) |= 0x40000000u;
    this->temp_reg._unVal.pTable->Iterate(this: (struct SQTable *)this->temp_reg._unVal.nInteger, a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_91:
  pIterator->PsuedoKey(this: pIterator, a2: "_stack");
  if ( pIterator->BeginContained(this: pIterator) )
  {
    for ( i = 0; i < this->_stack._size; ++i )
    {
      v10 = &this->_stack._vals[i];
      ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: v10);
      v11 = v10->_type;
      if ( v10->_type > OT_THREAD )
      {
        if ( v11 > 167772288 )
        {
          if ( v11 == 167804928 )
            goto LABEL_108;
        }
        else if ( v11 == 167772288 || v11 == 134234112 || v11 == 167772192 )
        {
LABEL_108:
          if ( (*(_DWORD *)(v10->_unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
          {
            *(_DWORD *)(v10->_unVal.nInteger + 4) |= 0x40000000u;
            v10->_unVal.pTable->Iterate(this: v10->_unVal.pTable, a2: pIterator);
            pIterator->EndContained(this: pIterator);
          }
        }
      }
      else
      {
        if ( v10->_type == OT_THREAD )
          goto LABEL_108;
        if ( v11 > 134218240 )
        {
          if ( v11 == 134218752 )
            goto LABEL_108;
        }
        else if ( v11 == 134218240 || v11 == 134217792 || v11 == 134217984 )
        {
          goto LABEL_108;
        }
      }
    }
    pIterator->EndContained(this: pIterator);
  }
  pIterator->PsuedoKey(this: pIterator, a2: "_vargsstack");
  if ( pIterator->BeginContained(this: pIterator) )
  {
    for ( j = 0; j < this->_vargsstack._size; ++j )
    {
      v13 = &this->_vargsstack._vals[j];
      ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: v13);
      v14 = v13->_type;
      if ( v13->_type > OT_THREAD )
      {
        if ( v14 > 167772288 )
        {
          if ( v14 == 167804928 )
            goto LABEL_130;
        }
        else if ( v14 == 167772288 || v14 == 134234112 || v14 == 167772192 )
        {
LABEL_130:
          if ( (*(_DWORD *)(v13->_unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
          {
            *(_DWORD *)(v13->_unVal.nInteger + 4) |= 0x40000000u;
            v13->_unVal.pTable->Iterate(this: v13->_unVal.pTable, a2: pIterator);
            pIterator->EndContained(this: pIterator);
          }
        }
      }
      else
      {
        if ( v13->_type == OT_THREAD )
          goto LABEL_130;
        if ( v14 > 134218240 )
        {
          if ( v14 == 134218752 )
            goto LABEL_130;
        }
        else if ( v14 == 134218240 || v14 == 134217792 || v14 == 134217984 )
        {
          goto LABEL_130;
        }
      }
    }
    pIterator->EndContained(this: pIterator);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FDF0
// Name: public: virtual void SQArray::Iterate(class CSQStateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQArray::Iterate(SQArray *this, CSQStateIterator *pIterator)
{
  int v2; // ebx
  SQObjectPtr *v3; // esi
  int type; // eax
  signed int len; // [esp+4h] [ebp-8h]
  SQArray *v6; // [esp+8h] [ebp-4h]

  v2 = 0;
  v6 = this;
  len = this->_values._size;
  if ( len > 0 )
  {
    while ( 1 )
    {
      v3 = &this->_values._vals[v2];
      ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: v3);
      type = v3->_type;
      if ( v3->_type > OT_THREAD )
      {
        if ( type > 167772288 )
        {
          if ( type != 167804928 )
            goto LABEL_22;
        }
        else if ( type != 167772288 && type != 134234112 && type != 167772192 )
        {
          goto LABEL_22;
        }
      }
      else if ( v3->_type != OT_THREAD )
      {
        if ( type > 134218240 )
        {
          if ( type != 134218752 )
            goto LABEL_22;
        }
        else if ( type != 134218240 && type != 134217792 && type != 134217984 )
        {
          goto LABEL_22;
        }
      }
      if ( (*(_DWORD *)(v3->_unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
      {
        *(_DWORD *)(v3->_unVal.nInteger + 4) |= 0x40000000u;
        v3->_unVal.pTable->Iterate(this: v3->_unVal.pTable, a2: pIterator);
        pIterator->EndContained(this: pIterator);
      }
LABEL_22:
      if ( ++v2 >= len )
        return;
      this = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FEC0
// Name: public: virtual void SQTable::Iterate(class CSQStateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQTable::Iterate(SQTable *this, CSQStateIterator *pIterator)
{
  SQTable *delegate; // esi
  tagSQObjectValue v5; // eax
  int numofnodes; // eax
  int v7; // ebx
  SQTable *v8; // esi
  int *v9; // esi
  int v10; // eax
  SQObjectPtr tmp; // [esp+Ch] [ebp-Ch] BYREF
  SQTable *v12; // [esp+14h] [ebp-4h]
  CSQStateIterator *pIteratora; // [esp+20h] [ebp+8h]

  delegate = this->_delegate;
  v12 = this;
  if ( delegate != nullptr )
  {
    pIterator->PsuedoKey(this: pIterator, a2: "_delegate ");
    tmp._type = OT_TABLE;
    tmp._unVal.nInteger = (int)delegate;
    ++delegate->_uiRef;
    ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &tmp);
    if ( (tmp._type & 0x8000000) != 0 )
    {
      v5.pTable = (SQTable *)tmp._unVal;
      --*(_DWORD *)(tmp._unVal.nInteger + 4);
      if ( *(int *)(v5.nInteger + 4) <= 0 )
        tmp._unVal.pTable->Release(this: (struct SQTable *)tmp._unVal.nInteger);
    }
  }
  numofnodes = this->_numofnodes;
  if ( numofnodes > 0 )
  {
    v7 = 0;
    for ( pIteratora = (CSQStateIterator *)numofnodes;
          pIteratora != nullptr;
          pIteratora = (CSQStateIterator *)((char *)pIteratora - 1) )
    {
      v8 = v12;
      pIterator->Key(this: pIterator, a2: &v12->_nodes[v7].key);
      v9 = (int *)&v8->_nodes[v7];
      ((void (__thiscall *)(CSQStateIterator *, int *))pIterator->Value)(a1: pIterator, a2: v9);
      v10 = *v9;
      if ( *v9 > 134221824 )
      {
        if ( v10 > 167772288 )
        {
          if ( v10 == 167804928 )
            goto LABEL_22;
        }
        else if ( v10 == 167772288 || v10 == 134234112 || v10 == 167772192 )
        {
LABEL_22:
          if ( (*(_DWORD *)(v9[1] + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
          {
            *(_DWORD *)(v9[1] + 4) |= 0x40000000u;
            (*(void (__thiscall **)(int, CSQStateIterator *))(*(_DWORD *)v9[1] + 4))(a1: v9[1], a2: pIterator);
            pIterator->EndContained(this: pIterator);
          }
        }
      }
      else
      {
        if ( *v9 == 134221824 )
          goto LABEL_22;
        if ( v10 > 134218240 )
        {
          if ( v10 == 134218752 )
            goto LABEL_22;
        }
        else if ( v10 == 134218240 || v10 == 134217792 || v10 == 134217984 )
        {
          goto LABEL_22;
        }
      }
      ++v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FFF0
// Name: public: virtual void SQClass::Iterate(class CSQStateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQClass::Iterate(SQClass *this, CSQStateIterator *pIterator)
{
  SQClass *base; // edi
  _DWORD *v4; // eax
  tagSQObjectType type; // eax
  SQClassMember *v6; // edi
  int v7; // eax
  SQObjectPtr *p_attrs; // edi
  int v9; // eax
  int v10; // ebx
  SQClassMember *v11; // edi
  int v12; // eax
  SQObjectPtr *v13; // edi
  int v14; // eax
  unsigned int i; // ebx
  SQObjectPtr *v16; // edi
  int v17; // eax
  tagSQObjectValue v18; // eax
  int v20; // [esp+58h] [ebp-14h]
  unsigned int j; // [esp+5Ch] [ebp-10h] BYREF
  _DWORD *v22; // [esp+60h] [ebp-Ch]
  SQObjectPtr tmpObjectPtr_m; // [esp+64h] [ebp-8h] BYREF

  tmpObjectPtr_m._unVal.nInteger = (int)this->_members;
  tmpObjectPtr_m._type = OT_TABLE;
  ++*(_DWORD *)(tmpObjectPtr_m._unVal.nInteger + 4);
  pIterator->PsuedoKey(this: pIterator, a2: "_members");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &tmpObjectPtr_m);
  if ( tmpObjectPtr_m._type > OT_THREAD )
  {
    if ( tmpObjectPtr_m._type > OT_USERDATA )
    {
      if ( tmpObjectPtr_m._type != OT_INSTANCE )
        goto LABEL_19;
    }
    else if ( tmpObjectPtr_m._type != OT_USERDATA
           && tmpObjectPtr_m._type != OT_CLASS
           && tmpObjectPtr_m._type != OT_TABLE )
    {
      goto LABEL_19;
    }
  }
  else if ( tmpObjectPtr_m._type != OT_THREAD )
  {
    if ( tmpObjectPtr_m._type > OT_NATIVECLOSURE )
    {
      if ( tmpObjectPtr_m._type != OT_GENERATOR )
        goto LABEL_19;
    }
    else if ( tmpObjectPtr_m._type != OT_NATIVECLOSURE
           && tmpObjectPtr_m._type != OT_ARRAY
           && tmpObjectPtr_m._type != OT_CLOSURE )
    {
      goto LABEL_19;
    }
  }
  if ( (*(_DWORD *)(tmpObjectPtr_m._unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(tmpObjectPtr_m._unVal.nInteger + 4) |= 0x40000000u;
    tmpObjectPtr_m._unVal.pTable->Iterate(this: (struct SQTable *)tmpObjectPtr_m._unVal.nInteger, a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_19:
  base = this->_base;
  if ( base != nullptr )
  {
    pIterator->PsuedoKey(this: pIterator, a2: "_base ");
    j = 134234112;
    v22 = &base->__vftable;
    ++base->_uiRef;
    ((void (__thiscall *)(CSQStateIterator *, unsigned int *))pIterator->Value)(a1: pIterator, a2: &j);
    if ( (j & 0x8000000) != 0 )
    {
      v4 = v22;
      --v22[1];
      if ( (int)v4[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v22 + 8))(a1: v22);
    }
  }
  pIterator->PsuedoKey(this: pIterator, a2: "_attributes");
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &this->_attributes);
  type = this->_attributes._type;
  if ( type > OT_THREAD )
  {
    if ( type > OT_USERDATA )
    {
      if ( type != OT_INSTANCE )
        goto LABEL_41;
    }
    else if ( type != OT_USERDATA && type != OT_CLASS && type != OT_TABLE )
    {
      goto LABEL_41;
    }
  }
  else if ( this->_attributes._type != OT_THREAD )
  {
    if ( type > OT_NATIVECLOSURE )
    {
      if ( type != OT_GENERATOR )
        goto LABEL_41;
    }
    else if ( type != OT_NATIVECLOSURE && type != OT_ARRAY && type != OT_CLOSURE )
    {
      goto LABEL_41;
    }
  }
  if ( (*(_DWORD *)(this->_attributes._unVal.nInteger + 4) & 0x40000000) == 0
    && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_attributes._unVal.nInteger + 4) |= 0x40000000u;
    this->_attributes._unVal.pTable->Iterate(this: (struct SQTable *)this->_attributes._unVal.nInteger, a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
LABEL_41:
  pIterator->PsuedoKey(this: pIterator, a2: "_defaultvalues");
  pIterator->BeginContained(this: pIterator);
  j = 0;
  if ( this->_defaultvalues._size != 0 )
  {
    v20 = 0;
    do
    {
      v6 = &this->_defaultvalues._vals[v20];
      ((void (__thiscall *)(CSQStateIterator *, SQClassMember *))pIterator->Value)(a1: pIterator, a2: v6);
      v7 = v6->val._type;
      if ( v6->val._type > OT_THREAD )
      {
        if ( v7 > 167772288 )
        {
          if ( v7 != 167804928 )
            goto LABEL_61;
        }
        else if ( v7 != 167772288 && v7 != 134234112 && v7 != 167772192 )
        {
          goto LABEL_61;
        }
      }
      else if ( v6->val._type != OT_THREAD )
      {
        if ( v7 > 134218240 )
        {
          if ( v7 != 134218752 )
            goto LABEL_61;
        }
        else if ( v7 != 134218240 && v7 != 134217792 && v7 != 134217984 )
        {
          goto LABEL_61;
        }
      }
      if ( (*(_DWORD *)(v6->val._unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
      {
        *(_DWORD *)(v6->val._unVal.nInteger + 4) |= 0x40000000u;
        v6->val._unVal.pTable->Iterate(this: v6->val._unVal.pTable, a2: pIterator);
        pIterator->EndContained(this: pIterator);
      }
LABEL_61:
      p_attrs = &this->_defaultvalues._vals[v20].attrs;
      ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: p_attrs);
      v9 = p_attrs->_type;
      if ( p_attrs->_type > OT_THREAD )
      {
        if ( v9 > 167772288 )
        {
          if ( v9 == 167804928 )
            goto LABEL_76;
        }
        else if ( v9 == 167772288 || v9 == 134234112 || v9 == 167772192 )
        {
LABEL_76:
          if ( (*(_DWORD *)(p_attrs->_unVal.nInteger + 4) & 0x40000000) == 0
            && pIterator->BeginContained(this: pIterator) )
          {
            *(_DWORD *)(p_attrs->_unVal.nInteger + 4) |= 0x40000000u;
            p_attrs->_unVal.pTable->Iterate(this: p_attrs->_unVal.pTable, a2: pIterator);
            pIterator->EndContained(this: pIterator);
          }
        }
      }
      else
      {
        if ( p_attrs->_type == OT_THREAD )
          goto LABEL_76;
        if ( v9 > 134218240 )
        {
          if ( v9 == 134218752 )
            goto LABEL_76;
        }
        else if ( v9 == 134218240 || v9 == 134217792 || v9 == 134217984 )
        {
          goto LABEL_76;
        }
      }
      ++v20;
      ++j;
    }
    while ( j < this->_defaultvalues._size );
  }
  pIterator->EndContained(this: pIterator);
  pIterator->PsuedoKey(this: pIterator, a2: "_methods");
  pIterator->BeginContained(this: pIterator);
  j = 0;
  if ( this->_methods._size != 0 )
  {
    v10 = 0;
    do
    {
      v11 = &this->_methods._vals[v10];
      ((void (__thiscall *)(CSQStateIterator *, SQClassMember *))pIterator->Value)(a1: pIterator, a2: v11);
      v12 = v11->val._type;
      if ( v11->val._type > OT_THREAD )
      {
        if ( v12 > 167772288 )
        {
          if ( v12 != 167804928 )
            goto LABEL_100;
        }
        else if ( v12 != 167772288 && v12 != 134234112 && v12 != 167772192 )
        {
          goto LABEL_100;
        }
      }
      else if ( v11->val._type != OT_THREAD )
      {
        if ( v12 > 134218240 )
        {
          if ( v12 != 134218752 )
            goto LABEL_100;
        }
        else if ( v12 != 134218240 && v12 != 134217792 && v12 != 134217984 )
        {
          goto LABEL_100;
        }
      }
      if ( (*(_DWORD *)(v11->val._unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
      {
        *(_DWORD *)(v11->val._unVal.nInteger + 4) |= 0x40000000u;
        v11->val._unVal.pTable->Iterate(this: v11->val._unVal.pTable, a2: pIterator);
        pIterator->EndContained(this: pIterator);
      }
LABEL_100:
      v13 = &this->_methods._vals[v10].attrs;
      ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: v13);
      v14 = v13->_type;
      if ( v13->_type > OT_THREAD )
      {
        if ( v14 > 167772288 )
        {
          if ( v14 == 167804928 )
            goto LABEL_115;
        }
        else if ( v14 == 167772288 || v14 == 134234112 || v14 == 167772192 )
        {
LABEL_115:
          if ( (*(_DWORD *)(v13->_unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
          {
            *(_DWORD *)(v13->_unVal.nInteger + 4) |= 0x40000000u;
            v13->_unVal.pTable->Iterate(this: v13->_unVal.pTable, a2: pIterator);
            pIterator->EndContained(this: pIterator);
          }
        }
      }
      else
      {
        if ( v13->_type == OT_THREAD )
          goto LABEL_115;
        if ( v14 > 134218240 )
        {
          if ( v14 == 134218752 )
            goto LABEL_115;
        }
        else if ( v14 == 134218240 || v14 == 134217792 || v14 == 134217984 )
        {
          goto LABEL_115;
        }
      }
      ++v10;
      ++j;
    }
    while ( j < this->_methods._size );
  }
  pIterator->EndContained(this: pIterator);
  pIterator->PsuedoKey(this: pIterator, a2: "_metamethods");
  pIterator->BeginContained(this: pIterator);
  for ( i = 0; i < this->_metamethods._size; ++i )
  {
    v16 = &this->_metamethods._vals[i];
    ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: v16);
    v17 = v16->_type;
    if ( v16->_type > OT_THREAD )
    {
      if ( v17 > 167772288 )
      {
        if ( v17 == 167804928 )
          goto LABEL_135;
      }
      else if ( v17 == 167772288 || v17 == 134234112 || v17 == 167772192 )
      {
LABEL_135:
        if ( (*(_DWORD *)(v16->_unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
        {
          *(_DWORD *)(v16->_unVal.nInteger + 4) |= 0x40000000u;
          v16->_unVal.pTable->Iterate(this: v16->_unVal.pTable, a2: pIterator);
          pIterator->EndContained(this: pIterator);
        }
      }
    }
    else
    {
      if ( v16->_type == OT_THREAD )
        goto LABEL_135;
      if ( v17 > 134218240 )
      {
        if ( v17 == 134218752 )
          goto LABEL_135;
      }
      else if ( v17 == 134218240 || v17 == 134217792 || v17 == 134217984 )
      {
        goto LABEL_135;
      }
    }
  }
  pIterator->EndContained(this: pIterator);
  if ( (tmpObjectPtr_m._type & 0x8000000) != 0 )
  {
    v18.pTable = (SQTable *)tmpObjectPtr_m._unVal;
    --*(_DWORD *)(tmpObjectPtr_m._unVal.nInteger + 4);
    if ( *(int *)(v18.nInteger + 4) <= 0 )
      tmpObjectPtr_m._unVal.pTable->Release(this: (struct SQTable *)tmpObjectPtr_m._unVal.nInteger);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100505A0
// Name: public: virtual void SQInstance::Iterate(class CSQStateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQInstance::Iterate(SQInstance *this, CSQStateIterator *pIterator)
{
  SQClass *v4; // edi
  unsigned int size; // eax
  tagSQObjectValue *p_unVal; // ebx
  int nInteger; // eax
  tagSQObjectValue v8; // eax
  SQObjectPtr tmpObjectPtr_c; // [esp+Ch] [ebp-8h] BYREF
  CSQStateIterator *pIteratora; // [esp+1Ch] [ebp+8h]

  v4 = this->_class;
  pIterator->PsuedoKey(this: pIterator, a2: "_class ");
  tmpObjectPtr_c._type = OT_CLASS;
  tmpObjectPtr_c._unVal.nInteger = (int)v4;
  ++v4->_uiRef;
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &tmpObjectPtr_c);
  size = this->_class->_defaultvalues._size;
  if ( size != 0 )
  {
    p_unVal = &this->_values[0]._unVal;
    for ( pIteratora = (CSQStateIterator *)size;
          pIteratora != nullptr;
          pIteratora = (CSQStateIterator *)((char *)pIteratora - 1) )
    {
      ((void (__thiscall *)(CSQStateIterator *, tagSQObjectValue *))pIterator->Value)(a1: pIterator, a2: &p_unVal[-1]);
      nInteger = p_unVal[-1].nInteger;
      if ( nInteger > 134221824 )
      {
        if ( nInteger > 167772288 )
        {
          if ( nInteger == 167804928 )
            goto LABEL_18;
        }
        else if ( nInteger == 167772288 || nInteger == 134234112 || nInteger == 167772192 )
        {
LABEL_18:
          if ( (*(_DWORD *)(p_unVal->nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
          {
            *(_DWORD *)(p_unVal->nInteger + 4) |= 0x40000000u;
            p_unVal->pTable->Iterate(this: p_unVal->pTable, a2: pIterator);
            pIterator->EndContained(this: pIterator);
          }
        }
      }
      else
      {
        if ( p_unVal[-1].nInteger == 134221824 )
          goto LABEL_18;
        if ( nInteger > 134218240 )
        {
          if ( nInteger == 134218752 )
            goto LABEL_18;
        }
        else if ( nInteger == 134218240 || nInteger == 134217792 || nInteger == 134217984 )
        {
          goto LABEL_18;
        }
      }
      p_unVal += 2;
    }
  }
  if ( (tmpObjectPtr_c._type & 0x8000000) != 0 )
  {
    v8.pTable = (SQTable *)tmpObjectPtr_c._unVal;
    --*(_DWORD *)(tmpObjectPtr_c._unVal.nInteger + 4);
    if ( *(int *)(v8.nInteger + 4) <= 0 )
      tmpObjectPtr_c._unVal.pTable->Release(this: (struct SQTable *)tmpObjectPtr_c._unVal.nInteger);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100506B0
// Name: public: virtual void SQGenerator::Iterate(class CSQStateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQGenerator::Iterate(SQGenerator *this, CSQStateIterator *pIterator)
{
  SQObjectPtr *v4; // edi
  int type; // eax
  SQObjectPtr *v6; // edi
  int v7; // eax
  tagSQObjectType v8; // eax
  unsigned int i; // [esp+Ch] [ebp-4h]
  unsigned int j; // [esp+18h] [ebp+8h]

  for ( i = 0; i < this->_stack._size; ++i )
  {
    v4 = &this->_stack._vals[i];
    ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: v4);
    type = v4->_type;
    if ( v4->_type > OT_THREAD )
    {
      if ( type > 167772288 )
      {
        if ( type == 167804928 )
          goto LABEL_17;
      }
      else if ( type == 167772288 || type == 134234112 || type == 167772192 )
      {
LABEL_17:
        if ( (*(_DWORD *)(v4->_unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
        {
          *(_DWORD *)(v4->_unVal.nInteger + 4) |= 0x40000000u;
          v4->_unVal.pTable->Iterate(this: v4->_unVal.pTable, a2: pIterator);
          pIterator->EndContained(this: pIterator);
        }
      }
    }
    else
    {
      if ( v4->_type == OT_THREAD )
        goto LABEL_17;
      if ( type > 134218240 )
      {
        if ( type == 134218752 )
          goto LABEL_17;
      }
      else if ( type == 134218240 || type == 134217792 || type == 134217984 )
      {
        goto LABEL_17;
      }
    }
  }
  for ( j = 0; j < this->_vargsstack._size; ++j )
  {
    v6 = &this->_vargsstack._vals[j];
    ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: v6);
    v7 = v6->_type;
    if ( v6->_type > OT_THREAD )
    {
      if ( v7 > 167772288 )
      {
        if ( v7 == 167804928 )
          goto LABEL_37;
      }
      else if ( v7 == 167772288 || v7 == 134234112 || v7 == 167772192 )
      {
LABEL_37:
        if ( (*(_DWORD *)(v6->_unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
        {
          *(_DWORD *)(v6->_unVal.nInteger + 4) |= 0x40000000u;
          v6->_unVal.pTable->Iterate(this: v6->_unVal.pTable, a2: pIterator);
          pIterator->EndContained(this: pIterator);
        }
      }
    }
    else
    {
      if ( v6->_type == OT_THREAD )
        goto LABEL_37;
      if ( v7 > 134218240 )
      {
        if ( v7 == 134218752 )
          goto LABEL_37;
      }
      else if ( v7 == 134218240 || v7 == 134217792 || v7 == 134217984 )
      {
        goto LABEL_37;
      }
    }
  }
  ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &this->_closure);
  v8 = this->_closure._type;
  if ( v8 > OT_THREAD )
  {
    if ( v8 > OT_USERDATA )
    {
      if ( v8 != OT_INSTANCE )
        return;
    }
    else if ( v8 != OT_USERDATA && v8 != OT_CLASS && v8 != OT_TABLE )
    {
      return;
    }
  }
  else if ( this->_closure._type != OT_THREAD )
  {
    if ( v8 > OT_NATIVECLOSURE )
    {
      if ( v8 != OT_GENERATOR )
        return;
    }
    else if ( v8 != OT_NATIVECLOSURE && v8 != OT_ARRAY && v8 != OT_CLOSURE )
    {
      return;
    }
  }
  if ( (*(_DWORD *)(this->_closure._unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
  {
    *(_DWORD *)(this->_closure._unVal.nInteger + 4) |= 0x40000000u;
    this->_closure._unVal.pTable->Iterate(this: (struct SQTable *)this->_closure._unVal.nInteger, a2: pIterator);
    pIterator->EndContained(this: pIterator);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100508E0
// Name: public: virtual void SQClosure::Iterate(class CSQStateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQClosure::Iterate(SQClosure *this, CSQStateIterator *pIterator)
{
  unsigned int v3; // ebx
  SQObjectPtr *v4; // edi
  int type; // eax
  unsigned int v6; // eax
  SQObjectPtr *v7; // edi
  int v8; // eax
  SQClosure *v9; // [esp+Ch] [ebp-4h]
  unsigned int i; // [esp+18h] [ebp+8h]

  v3 = 0;
  v9 = this;
  while ( v3 < v9->_outervalues._size )
  {
    v4 = &this->_outervalues._vals[v3];
    ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: v4);
    type = v4->_type;
    if ( v4->_type > OT_THREAD )
    {
      if ( type > 167772288 )
      {
        if ( type == 167804928 )
          goto LABEL_17;
      }
      else if ( type == 167772288 || type == 134234112 || type == 167772192 )
      {
LABEL_17:
        if ( (*(_DWORD *)(v4->_unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
        {
          *(_DWORD *)(v4->_unVal.nInteger + 4) |= 0x40000000u;
          v4->_unVal.pTable->Iterate(this: v4->_unVal.pTable, a2: pIterator);
          pIterator->EndContained(this: pIterator);
        }
      }
    }
    else
    {
      if ( v4->_type == OT_THREAD )
        goto LABEL_17;
      if ( type > 134218240 )
      {
        if ( type == 134218752 )
          goto LABEL_17;
      }
      else if ( type == 134218240 || type == 134217792 || type == 134217984 )
      {
        goto LABEL_17;
      }
    }
    this = v9;
    ++v3;
  }
  v6 = 0;
  i = 0;
  if ( this->_defaultparams._size != 0 )
  {
    do
    {
      v7 = &this->_defaultparams._vals[v6];
      ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: v7);
      v8 = v7->_type;
      if ( v7->_type > OT_THREAD )
      {
        if ( v8 > 167772288 )
        {
          if ( v8 == 167804928 )
            goto LABEL_37;
        }
        else if ( v8 == 167772288 || v8 == 134234112 || v8 == 167772192 )
        {
LABEL_37:
          if ( (*(_DWORD *)(v7->_unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
          {
            *(_DWORD *)(v7->_unVal.nInteger + 4) |= 0x40000000u;
            v7->_unVal.pTable->Iterate(this: v7->_unVal.pTable, a2: pIterator);
            pIterator->EndContained(this: pIterator);
          }
        }
      }
      else
      {
        if ( v7->_type == OT_THREAD )
          goto LABEL_37;
        if ( v8 > 134218240 )
        {
          if ( v8 == 134218752 )
            goto LABEL_37;
        }
        else if ( v8 == 134218240 || v8 == 134217792 || v8 == 134217984 )
        {
          goto LABEL_37;
        }
      }
      this = v9;
      v6 = i + 1;
      i = v6;
    }
    while ( v6 < v9->_defaultparams._size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050A60
// Name: public: virtual void SQNativeClosure::Iterate(class CSQStateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQNativeClosure::Iterate(SQNativeClosure *this, CSQStateIterator *pIterator)
{
  unsigned int v2; // ebx
  SQObjectPtr *v3; // esi
  int type; // eax
  SQNativeClosure *v5; // [esp+4h] [ebp-4h]

  v2 = 0;
  v5 = this;
  while ( v2 < v5->_outervalues._size )
  {
    v3 = &this->_outervalues._vals[v2];
    ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: v3);
    type = v3->_type;
    if ( v3->_type > OT_THREAD )
    {
      if ( type > 167772288 )
      {
        if ( type == 167804928 )
          goto LABEL_17;
      }
      else if ( type == 167772288 || type == 134234112 || type == 167772192 )
      {
LABEL_17:
        if ( (*(_DWORD *)(v3->_unVal.nInteger + 4) & 0x40000000) == 0 && pIterator->BeginContained(this: pIterator) )
        {
          *(_DWORD *)(v3->_unVal.nInteger + 4) |= 0x40000000u;
          v3->_unVal.pTable->Iterate(this: v3->_unVal.pTable, a2: pIterator);
          pIterator->EndContained(this: pIterator);
        }
      }
    }
    else
    {
      if ( v3->_type == OT_THREAD )
        goto LABEL_17;
      if ( type > 134218240 )
      {
        if ( type == 134218752 )
          goto LABEL_17;
      }
      else if ( type == 134218240 || type == 134217792 || type == 134217984 )
      {
        goto LABEL_17;
      }
    }
    this = v5;
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050B30
// Name: public: virtual void SQUserData::Iterate(class CSQStateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQUserData::Iterate(SQUserData *this, CSQStateIterator *pIterator)
{
  SQTable *delegate; // esi
  tagSQObjectValue v3; // eax
  SQObjectPtr tmpObjectPtr_d; // [esp+4h] [ebp-8h] BYREF

  delegate = this->_delegate;
  if ( delegate != nullptr )
  {
    pIterator->PsuedoKey(this: pIterator, a2: "_delegate ");
    tmpObjectPtr_d._type = OT_TABLE;
    tmpObjectPtr_d._unVal.nInteger = (int)delegate;
    ++delegate->_uiRef;
    ((void (__thiscall *)(CSQStateIterator *, SQObjectPtr *))pIterator->Value)(a1: pIterator, a2: &tmpObjectPtr_d);
    if ( (tmpObjectPtr_d._type & 0x8000000) != 0 )
    {
      v3.pTable = (SQTable *)tmpObjectPtr_d._unVal;
      --*(_DWORD *)(tmpObjectPtr_d._unVal.nInteger + 4);
      if ( *(int *)(v3.nInteger + 4) <= 0 )
        tmpObjectPtr_d._unVal.pTable->Release(this: (struct SQTable *)tmpObjectPtr_d._unVal.nInteger);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050B90
// Name: public: void sqvector<struct SQVM::CallInfo>::resize(unsigned int,struct SQVM::CallInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge sqvector<SQVM::CallInfo>::resize(
        sqvector<SQVM::CallInfo> *this@<edi>,
        const SQVM::CallInfo *fill@<eax>,
        unsigned int newsize)
{
  unsigned int v3; // edx
  unsigned int v5; // ebx
  SQVM::CallInfo *v6; // eax
  unsigned int size; // eax
  SQVM::CallInfo *v8; // eax
  bool v9; // zf
  tagSQObjectValue v10; // ecx
  unsigned int v11; // ebx
  unsigned int v12; // esi
  SQVM::CallInfo *vals; // eax
  tagSQObjectValue v14; // ecx

  v3 = newsize;
  if ( newsize > this->_allocated )
  {
    v5 = newsize;
    if ( newsize == 0 )
      v5 = 4;
    v6 = (SQVM::CallInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: this->_vals, a3: 48 * v5);
    v3 = newsize;
    this->_vals = v6;
    this->_allocated = v5;
  }
  size = this->_size;
  if ( size >= v3 )
  {
    v11 = v3;
    if ( v3 < size )
    {
      v12 = v3;
      do
      {
        vals = this->_vals;
        if ( (this->_vals[v12]._closure._type & 0x8000000) != 0 )
        {
          v14.pTable = (SQTable *)vals[v12]._closure._unVal;
          if ( (int)--*(_DWORD *)(v14.nInteger + 4) <= 0 )
          {
            vals[v12]._closure._unVal.pTable->Release(this: (struct SQTable *)vals[v12]._closure._unVal.nInteger);
            v3 = newsize;
          }
        }
        ++v11;
        ++v12;
      }
      while ( v11 < this->_size );
    }
    this->_size = v3;
  }
  else
  {
    do
    {
      v8 = &this->_vals[this->_size];
      if ( v8 != nullptr )
      {
        v8->_ip = fill->_ip;
        v8->_literals = fill->_literals;
        v8->_closure._type = fill->_closure._type;
        v9 = (v8->_closure._type & 0x8000000) == 0;
        v10.pTable = (SQTable *)fill->_closure._unVal;
        v8->_closure._unVal = v10;
        if ( !v9 )
          ++*(_DWORD *)(v10.nInteger + 4);
        v8->_generator = fill->_generator;
        v8->_etraps = fill->_etraps;
        v8->_prevstkbase = fill->_prevstkbase;
        v8->_prevtop = fill->_prevtop;
        v8->_target = fill->_target;
        v8->_ncalls = fill->_ncalls;
        v8->_root = fill->_root;
        v8->_vargs = fill->_vargs;
      }
      ++this->_size;
    }
    while ( this->_size < v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BF50
// Name: public: sqvector<struct SQVM::CallInfo>::~sqvector<struct SQVM::CallInfo>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall sqvector<SQVM::CallInfo>::~sqvector<SQVM::CallInfo>(
        sqvector<SQVM::CallInfo> *this@<ecx>,
        void **a2@<esi>)
{
  unsigned int v2; // ebx
  int v3; // edi
  char *v4; // eax
  int v5; // ecx

  if ( a2[2] != nullptr )
  {
    v2 = 0;
    if ( a2[1] != nullptr )
    {
      v3 = 0;
      do
      {
        v4 = (char *)*a2;
        if ( (*(_DWORD *)((_BYTE *)*a2 + v3 + 8) & 0x8000000) != 0 )
        {
          v5 = *(_DWORD *)&v4[v3 + 12];
          if ( (int)--*(_DWORD *)(v5 + 4) <= 0 )
            (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&v4[v3 + 12] + 8))(a1: *(_DWORD *)&v4[v3 + 12]);
        }
        ++v2;
        v3 += 48;
      }
      while ( v2 < (unsigned int)a2[1] );
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *a2);
  }
}
