// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/squirrel/sqvm.cpp
// Functions: 46
// ============================================================

#include "vscript\languages\squirrel\squirrel\sqvm.h"

//------------------------------------------------------------------------------
// Address: 0x100556E0
// Name: public: void SQGenerator::Kill(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQGenerator::Kill(SQGenerator *this@<ecx>, _DWORD *a2@<eax>)
{
  _DWORD *v3; // ecx
  int v4; // eax
  tagSQObjectType type; // edx
  SQObjectPtr fill; // [esp+8h] [ebp-8h] BYREF

  a2[29] = 2;
  fill._type = OT_NULL;
  fill._unVal.nInteger = 0;
  sqvector<SQObjectPtr>::resize((sqvector<SQObjectPtr> *)this, a2: (int)(a2 + 8), newsize: 0, &fill);
  v3 = (_DWORD *)a2[7];
  v4 = a2[6];
  a2[7] = _null_._unVal.pTable;
  type = _null_._type;
  a2[6] = _null_._type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(a2[7] + 4);
  if ( (v4 & 0x8000000) != 0 && (int)--v3[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10055750
// Name: public: int SQArray::Next(struct SQObjectPtr const __near &,struct SQObjectPtr __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge SQArray::Next@<eax>(
        const SQObjectPtr *refpos@<ecx>,
        SQObjectPtr *outval@<eax>,
        SQArray *this,
        SQObjectPtr *outkey)
{
  unsigned int raw; // ebx
  tagSQObjectValue v6; // eax
  SQObjectPtr *v7; // eax
  SQObjectPtr *v8; // eax
  tagSQObjectValue v9; // esi
  _DWORD *v10; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v12; // eax
  SQObjectPtr v14; // [esp+10h] [ebp-8h] BYREF

  if ( refpos->_type == OT_INTEGER )
    raw = refpos->_unVal.raw;
  else
    raw = 0;
  if ( raw >= this->_values._size )
    return -1;
  if ( (outkey->_type & 0x8000000) != 0 )
  {
    v6.pTable = (SQTable *)outkey->_unVal;
    if ( (int)--*(_DWORD *)(v6.nInteger + 4) <= 0 )
      outkey->_unVal.pTable->Release(this: (struct SQTable *)outkey->_unVal.nInteger);
  }
  outkey->_unVal.nInteger = raw;
  outkey->_type = OT_INTEGER;
  v7 = &this->_values._vals[raw];
  if ( v7->_type == OT_WEAKREF )
  {
    v8 = (SQObjectPtr *)(v7->_unVal.nInteger + 12);
  }
  else
  {
    v14 = *v7;
    v8 = &v14;
  }
  v9.pTable = (SQTable *)v8->_unVal;
  v10 = &outval->_unVal.pTable->__vftable;
  type = outval->_type;
  outval->_unVal = v9;
  v12 = v8->_type;
  outval->_type = v12;
  if ( (v12 & 0x8000000) != 0 )
    ++*(_DWORD *)(v9.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  return raw + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10055820
// Name: public: struct SQInstance __near * SQInstance::Clone(struct SQSharedState __near *)
// Source: json
//------------------------------------------------------------------------------
SQInstance *__userpurge SQInstance::Clone@<eax>(SQInstance *this@<ecx>, SQInstance *a2@<edi>, SQSharedState *ss)
{
  SQClass *v3; // eax
  unsigned int size; // ecx
  unsigned int v5; // ecx
  int v6; // esi
  SQInstance *result; // eax
  int udsize; // ecx

  v3 = a2->_class;
  size = v3->_defaultvalues._size;
  if ( size != 0 )
    v5 = size - 1;
  else
    v5 = 0;
  v6 = v3->_udsize + 8 * v5 + 52;
  result = (SQInstance *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v6);
  if ( result != nullptr )
    result = SQInstance::SQInstance(this: result, memsize: v6, ss, i: a2);
  udsize = a2->_class->_udsize;
  if ( udsize != 0 )
    result->_userpointer = (char *)result + v6 - udsize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10055880
// Name: public: void SQVM::ClearStack(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQVM::ClearStack(SQVM *this@<edi>, int last_top@<eax>)
{
  int v2; // esi
  SQObjectPtr *vals; // eax
  tagSQObjectType type; // edx
  _DWORD *v5; // ecx
  SQObjectPtr *v6; // eax

  v2 = last_top;
  while ( v2 >= this->_top )
  {
    vals = this->_stack._vals;
    type = vals[v2]._type;
    v5 = &vals[v2]._unVal.pTable->__vftable;
    v6 = &vals[v2--];
    v6->_type = OT_NULL;
    v6->_unVal.nInteger = 0;
    if ( (type & 0x8000000) != 0 && (int)--v5[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v5 + 8))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100558D0
// Name: public: bool SQVM::BW_OP(unsigned int,struct SQObjectPtr __near &,struct SQObjectPtr const __near &,struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge SQVM::BW_OP@<al>(
        const SQObjectPtr *o1@<edx>,
        const SQObjectPtr *o2@<eax>,
        SQVM *this,
        unsigned int op,
        SQObjectPtr *trg)
{
  tagSQObjectValue v6; // eax
  tagSQObjectValue v7; // ecx
  bool result; // al
  tagSQObjectType v9; // edx
  const char *v10; // eax
  const char *v11; // [esp-4h] [ebp-10h]
  const char *v12; // [esp+0h] [ebp-Ch]

  v6.pTable = (SQTable *)o1->_unVal;
  v7.pTable = (SQTable *)o2->_unVal;
  if ( o1->_type == OT_INTEGER && o2->_type == OT_INTEGER )
  {
    switch ( op )
    {
      case 0u:
        SQObjectPtr::operator=(this: (SQObjectPtr *)v7.pTable, a2: trg, i: v7.nInteger & v6.nInteger);
        result = true;
        break;
      case 2u:
        SQObjectPtr::operator=(this: (SQObjectPtr *)v7.pTable, a2: trg, i: v7.nInteger | v6.nInteger);
        result = true;
        break;
      case 3u:
        SQObjectPtr::operator=(this: (SQObjectPtr *)v7.pTable, a2: trg, i: v7.nInteger ^ v6.nInteger);
        result = true;
        break;
      case 4u:
        SQObjectPtr::operator=(this: (SQObjectPtr *)v7.pTable, a2: trg, i: v6.nInteger << SLOBYTE(v7.nInteger));
        result = true;
        break;
      case 5u:
        SQObjectPtr::operator=(this: (SQObjectPtr *)v7.pTable, a2: trg, i: v6.nInteger >> SLOBYTE(v7.nInteger));
        result = true;
        break;
      case 6u:
        SQObjectPtr::operator=(
          this: (SQObjectPtr *)v7.pTable,
          a2: trg,
          i: (unsigned int)v6.nInteger >> SLOBYTE(v7.nInteger));
        result = true;
        break;
      default:
        SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D09C, s: v12);
        result = false;
        break;
    }
  }
  else
  {
    v11 = IdType2Name(type: o2->_type);
    v10 = IdType2Name(type: v9);
    SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D09C._stack._size, s: v10, v11);
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100559E0
// Name: public: bool SQVM::ARITH_OP(unsigned int,struct SQObjectPtr __near &,struct SQObjectPtr const __near &,struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge SQVM::ARITH_OP@<al>(
        SQVM *this@<ecx>,
        SQObjectPtr *o2@<eax>,
        const char *op,
        SQObjectPtr *trg,
        const SQObjectPtr *o1)
{
  tagSQObjectType type; // ecx
  tagSQObjectType v8; // eax
  tagSQObjectValue v9; // eax
  tagSQObjectValue v10; // ecx
  bool result; // al
  float nInteger; // xmm1_4
  float fFloat; // xmm0_4
  float v14; // xmm0_4
  tagSQObjectValue v15; // eax
  tagSQObjectValue v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // [esp-8h] [ebp-1Ch]
  int v20; // [esp-4h] [ebp-18h]
  const char *v21; // [esp-4h] [ebp-18h]
  const char *v22; // [esp+0h] [ebp-14h]
  float res; // [esp+1Ch] [ebp+8h]

  type = o1->_type;
  if ( (o1->_type & 0x4000000) == 0 || (v8 = o2->_type, (o2->_type & 0x4000000) == 0) )
  {
    if ( op == (const char *)43 && (type == OT_STRING || o2->_type == OT_STRING) )
    {
      result = SQVM::StringCat(this: (SQVM *)trg, str: (const SQObjectPtr *)this, obj: o1, dest: o2);
      if ( !result )
        return result;
    }
    else if ( !SQVM::ArithMetaMethod(this, (int)op, o1, o2, dest: trg) )
    {
      v16.pTable = (SQTable *)this->_lasterror._unVal;
      if ( v16.nInteger != 0 )
      {
        v20 = v16.nInteger + 28;
        v19 = IdType2Name(type: o2->_type);
        v17 = IdType2Name(type: o1->_type);
        SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D09C._callsstacksize, s: op, v17, v19, v20);
      }
      else
      {
        v21 = IdType2Name(type: o2->_type);
        v18 = IdType2Name(type: o1->_type);
        SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D09C._nnativecalls, s: op, v18, v21);
      }
      return false;
    }
    return true;
  }
  if ( type == OT_INTEGER )
  {
    if ( v8 == OT_INTEGER )
    {
      v9.pTable = (SQTable *)o1->_unVal;
      v10.pTable = (SQTable *)o2->_unVal;
      switch ( (unsigned int)op )
      {
        case '%':
          if ( v10.nInteger != 0 )
          {
            SQObjectPtr::operator=(this: (SQObjectPtr *)v10.pTable, a2: trg, i: v9.nInteger % v10.nInteger);
            result = true;
          }
          else
          {
            SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D09C._debughook._unVal, s: v22);
            result = false;
          }
          break;
        case '*':
          SQObjectPtr::operator=(this: (SQObjectPtr *)v10.pTable, a2: trg, i: v10.nInteger * v9.nInteger);
          result = true;
          break;
        case '+':
          SQObjectPtr::operator=(this: (SQObjectPtr *)v10.pTable, a2: trg, i: v10.nInteger + v9.nInteger);
          result = true;
          break;
        case '-':
          SQObjectPtr::operator=(this: (SQObjectPtr *)v10.pTable, a2: trg, i: v9.nInteger - v10.nInteger);
          result = true;
          break;
        case '/':
          if ( v10.nInteger != 0 )
          {
            SQObjectPtr::operator=(this: (SQObjectPtr *)v10.pTable, a2: trg, i: v9.nInteger / v10.nInteger);
            result = true;
          }
          else
          {
            SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D09C._lasterror, s: v22);
            result = false;
          }
          break;
        default:
          SQObjectPtr::operator=(this: (SQObjectPtr *)v10.pTable, a2: trg, i: -559038737);
          return true;
      }
      return result;
    }
    nInteger = (float)o1->_unVal.nInteger;
  }
  else
  {
    nInteger = o1->_unVal.fFloat;
  }
  if ( v8 == OT_INTEGER )
    fFloat = (float)o2->_unVal.nInteger;
  else
    fFloat = o2->_unVal.fFloat;
  switch ( (unsigned int)op )
  {
    case '%':
      res = fmod(nInteger, fFloat);
      goto LABEL_30;
    case '*':
      v14 = fFloat * nInteger;
      goto LABEL_29;
    case '+':
      v14 = fFloat + nInteger;
      goto LABEL_29;
    case '-':
      res = nInteger - fFloat;
      goto LABEL_30;
    case '/':
      res = nInteger / fFloat;
      goto LABEL_30;
    default:
      v14 = 15.0;
LABEL_29:
      res = v14;
LABEL_30:
      if ( (trg->_type & 0x8000000) != 0 )
      {
        v15.pTable = (SQTable *)trg->_unVal;
        if ( (int)--*(_DWORD *)(v15.nInteger + 4) <= 0 )
          trg->_unVal.pTable->Release(this: (struct SQTable *)trg->_unVal.nInteger);
      }
      trg->_unVal.fFloat = res;
      trg->_type = OT_FLOAT;
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10055CD0
// Name: public: SQVM::SQVM(struct SQSharedState __near *)
// Source: json
//------------------------------------------------------------------------------
SQVM *__userpurge SQVM::SQVM@<eax>(SQVM *this@<ecx>, int a2@<esi>, SQSharedState *ss)
{
  _DWORD *v3; // ecx
  int v4; // eax
  tagSQObjectType type; // edx
  _DWORD *v6; // ecx
  int v7; // edx
  tagSQObjectType v8; // eax
  _DWORD *v9; // ecx
  int v10; // edx
  tagSQObjectType v11; // eax
  SQCollectable *gc_chain; // eax

  *(_DWORD *)a2 = &stru_1009D538._callsstacksize;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 64) = 16777217;
  *(_DWORD *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 72) = 16777217;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = 16777217;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 16777217;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 96) = 16777217;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 116) = 0;
  *(_DWORD *)(a2 + 120) = 0;
  *(_DWORD *)(a2 + 124) = 0;
  *(_DWORD *)(a2 + 128) = 0;
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 136) = 0;
  *(_DWORD *)(a2 + 172) = 0;
  *(_DWORD *)(a2 + 148) = ss;
  *(_DWORD *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 164) = -1;
  *(_DWORD *)(a2 + 160) = 0;
  *(_DWORD *)(a2 + 168) = -1;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 152) = 0;
  v3 = *(_DWORD **)(a2 + 76);
  v4 = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(a2 + 76) = _null_._unVal.pTable;
  type = _null_._type;
  *(_DWORD *)(a2 + 72) = _null_._type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a2 + 76) + 4);
  if ( (v4 & 0x8000000) != 0 && (int)--v3[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(a1: v3);
  v6 = *(_DWORD **)(a2 + 84);
  v7 = *(_DWORD *)(a2 + 80);
  *(_DWORD *)(a2 + 84) = _null_._unVal.pTable;
  v8 = _null_._type;
  *(_DWORD *)(a2 + 80) = _null_._type;
  if ( (v8 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a2 + 84) + 4);
  if ( (v7 & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  v9 = *(_DWORD **)(a2 + 92);
  v10 = *(_DWORD *)(a2 + 88);
  *(_DWORD *)(a2 + 92) = _null_._unVal.pTable;
  v11 = _null_._type;
  *(_DWORD *)(a2 + 88) = _null_._type;
  if ( (v11 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(a2 + 92) + 4);
  if ( (v10 & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 148) = ss;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 12) = ss->_gc_chain;
  gc_chain = ss->_gc_chain;
  if ( gc_chain != nullptr )
    gc_chain->_prev = (SQCollectable *)a2;
  ss->_gc_chain = (SQCollectable *)a2;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  return (SQVM *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x10055E80
// Name: public: virtual void SQVM::Finalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQVM::Finalize(SQVM *this)
{
  _DWORD *v2; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v4; // eax
  _DWORD *v5; // ecx
  tagSQObjectType v6; // edx
  tagSQObjectType v7; // eax
  _DWORD *v8; // ecx
  tagSQObjectType v9; // edx
  tagSQObjectType v10; // eax
  _DWORD *v11; // ecx
  tagSQObjectType v12; // edx
  tagSQObjectType v13; // eax
  _DWORD *v14; // ecx
  tagSQObjectType v15; // edx
  tagSQObjectType v16; // eax
  int *pTable; // ecx
  signed int v18; // edi
  SQObjectPtr *vals; // eax
  _DWORD *v20; // ecx
  tagSQObjectType v21; // edx
  SQObjectPtr *v22; // eax
  tagSQObjectType v23; // ebx
  signed int size; // [esp+Ch] [ebp-34h]
  SQVM::CallInfo fill; // [esp+10h] [ebp-30h] BYREF

  v2 = &this->_roottable._unVal.pTable->__vftable;
  type = this->_roottable._type;
  this->_roottable._unVal.nInteger = _null_._unVal.nInteger;
  v4 = _null_._type;
  this->_roottable._type = _null_._type;
  if ( (v4 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_roottable._unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v2[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v2 + 8))(a1: v2);
  v5 = &this->_lasterror._unVal.pTable->__vftable;
  v6 = this->_lasterror._type;
  this->_lasterror._unVal.nInteger = _null_._unVal.nInteger;
  v7 = _null_._type;
  this->_lasterror._type = _null_._type;
  if ( (v7 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_lasterror._unVal.nInteger + 4);
  if ( (v6 & 0x8000000) != 0 && (int)--v5[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v5 + 8))(a1: v5);
  v8 = &this->_errorhandler._unVal.pTable->__vftable;
  v9 = this->_errorhandler._type;
  this->_errorhandler._unVal.nInteger = _null_._unVal.nInteger;
  v10 = _null_._type;
  this->_errorhandler._type = _null_._type;
  if ( (v10 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_errorhandler._unVal.nInteger + 4);
  if ( (v9 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  v11 = &this->_debughook._unVal.pTable->__vftable;
  v12 = this->_debughook._type;
  this->_debughook._unVal.nInteger = _null_._unVal.nInteger;
  v13 = _null_._type;
  this->_debughook._type = _null_._type;
  if ( (v13 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_debughook._unVal.nInteger + 4);
  if ( (v12 & 0x8000000) != 0 && (int)--v11[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
  v14 = &this->temp_reg._unVal.pTable->__vftable;
  v15 = this->temp_reg._type;
  this->temp_reg._unVal.nInteger = _null_._unVal.nInteger;
  v16 = _null_._type;
  this->temp_reg._type = _null_._type;
  if ( (v16 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->temp_reg._unVal.nInteger + 4);
  if ( (v15 & 0x8000000) != 0 && (int)--v14[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
  fill._closure._type = OT_NULL;
  fill._closure._unVal.nInteger = 0;
  fill._vargs = 0;
  sqvector<SQVM::CallInfo>::resize(this: &this->_callstackdata, &fill, newsize: 0);
  if ( (fill._closure._type & 0x8000000) != 0 )
  {
    pTable = (int *)fill._closure._unVal.pTable;
    --*(_DWORD *)(fill._closure._unVal.nInteger + 4);
    if ( pTable[1] <= 0 )
      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
  v18 = 0;
  size = this->_stack._size;
  if ( size > 0 )
  {
    do
    {
      vals = this->_stack._vals;
      v20 = &vals[v18]._unVal.pTable->__vftable;
      v21 = vals[v18]._type;
      v22 = &vals[v18];
      v22->_unVal.nInteger = _null_._unVal.nInteger;
      v23 = _null_._type;
      v22->_type = _null_._type;
      if ( (v23 & 0x8000000) != 0 )
        ++*(_DWORD *)(v22->_unVal.nInteger + 4);
      if ( (v21 & 0x8000000) != 0 && (int)--v20[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v20 + 8))(a1: v20);
      ++v18;
    }
    while ( v18 < size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056050
// Name: public: virtual SQVM::~SQVM(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQVM::~SQVM(SQVM *this, SQVM *thisa)
{
  sqvector<SQVM::CallInfo> *prev; // ecx
  SQCollectable *next; // eax
  sqvector<SQObjectPtr> *v4; // ecx
  tagSQObjectValue v5; // eax
  tagSQObjectValue v6; // eax
  tagSQObjectValue v7; // eax
  tagSQObjectValue v8; // eax
  tagSQObjectValue v9; // eax
  sqvector<SQObjectPtr> *v10; // ecx
  SQWeakRef *weakref; // eax

  thisa->__vftable = (SQVM_vtbl *)&stru_1009D538._callsstacksize;
  SQVM::Finalize(this: thisa);
  if ( (thisa->_uiRef & 0x40000000) == 0 )
  {
    prev = (sqvector<SQVM::CallInfo> *)thisa->_prev;
    if ( prev != nullptr )
    {
      prev[1]._vals = (SQVM::CallInfo *)thisa->_next;
    }
    else
    {
      prev = (sqvector<SQVM::CallInfo> *)thisa->_next;
      thisa->_sharedstate->_gc_chain = (SQCollectable *)prev;
    }
    next = thisa->_next;
    if ( next != nullptr )
    {
      prev = (sqvector<SQVM::CallInfo> *)thisa->_prev;
      next->_prev = (SQCollectable *)prev;
    }
    thisa->_next = nullptr;
    thisa->_prev = nullptr;
  }
  if ( thisa->_etraps._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: thisa->_etraps._vals);
  sqvector<SQVM::CallInfo>::~sqvector<SQVM::CallInfo>(this: prev, a2: (void **)&thisa->_callstackdata._vals);
  if ( (thisa->temp_reg._type & 0x8000000) != 0 )
  {
    v5.pTable = (SQTable *)thisa->temp_reg._unVal;
    if ( (int)--*(_DWORD *)(v5.nInteger + 4) <= 0 )
      thisa->temp_reg._unVal.pTable->Release(this: (struct SQTable *)thisa->temp_reg._unVal.nInteger);
  }
  if ( (thisa->_debughook._type & 0x8000000) != 0 )
  {
    v6.pTable = (SQTable *)thisa->_debughook._unVal;
    if ( (int)--*(_DWORD *)(v6.nInteger + 4) <= 0 )
      thisa->_debughook._unVal.pTable->Release(this: (struct SQTable *)thisa->_debughook._unVal.nInteger);
  }
  if ( (thisa->_errorhandler._type & 0x8000000) != 0 )
  {
    v7.pTable = (SQTable *)thisa->_errorhandler._unVal;
    if ( (int)--*(_DWORD *)(v7.nInteger + 4) <= 0 )
      thisa->_errorhandler._unVal.pTable->Release(this: (struct SQTable *)thisa->_errorhandler._unVal.nInteger);
  }
  if ( (thisa->_lasterror._type & 0x8000000) != 0 )
  {
    v8.pTable = (SQTable *)thisa->_lasterror._unVal;
    if ( (int)--*(_DWORD *)(v8.nInteger + 4) <= 0 )
      thisa->_lasterror._unVal.pTable->Release(this: (struct SQTable *)thisa->_lasterror._unVal.nInteger);
  }
  if ( (thisa->_roottable._type & 0x8000000) != 0 )
  {
    v9.pTable = (SQTable *)thisa->_roottable._unVal;
    if ( (int)--*(_DWORD *)(v9.nInteger + 4) <= 0 )
      thisa->_roottable._unVal.pTable->Release(this: (struct SQTable *)thisa->_roottable._unVal.nInteger);
  }
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>(this: v4, a2: (int)&thisa->_vargsstack);
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>(this: v10, a2: (int)&thisa->_stack);
  weakref = thisa->_weakref;
  thisa->__vftable = (SQVM_vtbl *)&SQRefCounted::`vftable';
  if ( weakref != nullptr )
  {
    weakref->_obj._type = OT_NULL;
    thisa->_weakref->_obj._unVal.nInteger = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056190
// Name: public: bool SQVM::ArithMetaMethod(int,struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge SQVM::ArithMetaMethod@<al>(
        SQVM *this@<esi>,
        int op@<eax>,
        const SQObjectPtr *o1,
        const SQObjectPtr *o2,
        SQObjectPtr *dest)
{
  int top; // eax
  SQObjectPtr *vals; // ecx
  SQObjectPtr *v8; // eax
  _DWORD *v9; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v11; // edi
  int v12; // eax
  int v13; // ecx
  SQObjectPtr *v14; // eax
  _DWORD *v15; // ecx
  tagSQObjectType v16; // edi
  tagSQObjectType v17; // edx
  SQMetaMethod mm; // [esp+Ch] [ebp+8h]

  switch ( op )
  {
    case '%':
      mm = MT_MODULO;
      break;
    case '*':
      mm = MT_MUL;
      break;
    case '-':
      mm = MT_SUB;
      break;
    case '/':
      mm = MT_DIV;
      break;
    default:
      mm = MT_ADD;
      break;
  }
  if ( (o1->_type & 0x2000000) == 0 || *(_DWORD *)(o1->_unVal.nInteger + 24) == 0 )
    return false;
  top = this->_top;
  vals = this->_stack._vals;
  this->_top = top + 1;
  v8 = &vals[top];
  v9 = &v8->_unVal.pTable->__vftable;
  v8->_unVal.nInteger = o1->_unVal.nInteger;
  type = o1->_type;
  v11 = v8->_type;
  v8->_type = o1->_type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(v8->_unVal.nInteger + 4);
  if ( (v11 & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  v12 = this->_top;
  v13 = v12 + 1;
  v14 = &this->_stack._vals[v12];
  this->_top = v13;
  v15 = &v14->_unVal.pTable->__vftable;
  v16 = v14->_type;
  v14->_unVal.nInteger = o2->_unVal.nInteger;
  v17 = o2->_type;
  v14->_type = o2->_type;
  if ( (v17 & 0x8000000) != 0 )
    ++*(_DWORD *)(v14->_unVal.nInteger + 4);
  if ( (v16 & 0x8000000) != 0 && (int)--v15[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15);
  return SQVM::CallMetaMethod(this, del: o1->_unVal.pTable, mm, nparams: 2, outres: dest);
}

//------------------------------------------------------------------------------
// Address: 0x100562D0
// Name: public: bool SQVM::NEG_OP(struct SQObjectPtr __near &,struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::NEG_OP@<al>(SQVM *this@<ecx>, const SQObjectPtr *o@<eax>, SQObjectPtr *trg)
{
  tagSQObjectType type; // eax
  __int32 v6; // eax
  int top; // eax
  SQObjectPtr *vals; // ecx
  tagSQObjectType v10; // ebx
  SQObjectPtr *v11; // eax
  _DWORD *v12; // ecx
  tagSQObjectType v13; // edx
  tagSQObjectValue v14; // esi
  _DWORD *v15; // ecx
  tagSQObjectType v16; // edx
  tagSQObjectType v17; // ebx
  const char *v18; // eax

  type = o->_type;
  if ( type > OT_TABLE )
  {
    if ( type != OT_USERDATA && type != OT_INSTANCE )
    {
LABEL_22:
      v18 = IdType2Name(type: o->_type);
      SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D15C, s: v18);
      return 0;
    }
  }
  else if ( type != OT_TABLE )
  {
    v6 = type - 83886082;
    if ( v6 == 0 )
    {
      SQObjectPtr::operator=((SQObjectPtr *)this, a2: trg, i: -o->_unVal.nInteger);
      return 1;
    }
    if ( v6 == 2 )
    {
      SQObjectPtr::operator=(
        (SQObjectPtr *)this,
        a2: (float *)trg,
        f: COERCE_FLOAT(o->_unVal.nInteger ^ _mask__NegFloat_));
      return 1;
    }
    goto LABEL_22;
  }
  if ( *(_DWORD *)(o->_unVal.nInteger + 24) == 0 )
    goto LABEL_22;
  top = this->_top;
  vals = this->_stack._vals;
  this->_top = top + 1;
  v10 = vals[top]._type;
  v11 = &vals[top];
  v12 = &v11->_unVal.pTable->__vftable;
  v11->_unVal.nInteger = o->_unVal.nInteger;
  v13 = o->_type;
  v11->_type = o->_type;
  if ( (v13 & 0x8000000) != 0 )
    ++*(_DWORD *)(v11->_unVal.nInteger + 4);
  if ( (v10 & 0x8000000) != 0 && (int)--v12[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
  if ( !SQVM::CallMetaMethod(this, del: o->_unVal.pTable, mm: MT_UNM, nparams: 1, outres: &this->temp_reg) )
    goto LABEL_22;
  v14.pTable = (SQTable *)this->temp_reg._unVal;
  v15 = &trg->_unVal.pTable->__vftable;
  v16 = trg->_type;
  trg->_unVal = v14;
  v17 = this->temp_reg._type;
  trg->_type = v17;
  if ( (v17 & 0x8000000) != 0 )
    ++*(_DWORD *)(v14.nInteger + 4);
  if ( (v16 & 0x8000000) != 0 && (int)--v15[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10056410
// Name: public: bool SQVM::ObjCmp(struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge SQVM::ObjCmp@<al>(
        const SQObjectPtr *o1@<esi>,
        SQObjectPtr *o2@<edi>,
        SQVM *this,
        tagSQObjectValue *result)
{
  tagSQObjectType type; // eax
  tagSQObjectType v5; // ecx
  tagSQObjectValue v6; // edx
  tagSQObjectValue v7; // ecx
  bool v8; // al
  __int32 v9; // eax
  __int32 v10; // eax
  int v11; // kr00_4
  bool v12; // zf
  tagSQObjectValue v13; // eax
  float fFloat; // xmm1_4
  float nInteger; // xmm0_4
  bool v16; // cc
  float v17; // xmm1_4
  float v18; // xmm0_4
  SQObjectPtr res; // [esp+8h] [ebp-8h] BYREF

  type = o1->_type;
  v5 = o2->_type;
  if ( o1->_type == o2->_type )
  {
    v6.pTable = (SQTable *)o1->_unVal;
    v7.pTable = (SQTable *)o2->_unVal;
    if ( v6.nInteger == v7.nInteger )
    {
LABEL_3:
      result->nInteger = 0;
      return true;
    }
    res._type = OT_NULL;
    res._unVal.nInteger = 0;
    if ( type > OT_TABLE )
    {
      if ( type != OT_USERDATA && type != OT_INSTANCE )
      {
LABEL_24:
        v12 = (res._type & 0x8000000) == 0;
        result->nInteger = o1->_unVal.nInteger < (unsigned int)o2->_unVal.nInteger ? -1 : 1;
        if ( !v12 )
        {
          v13.pTable = (SQTable *)res._unVal;
          --*(_DWORD *)(res._unVal.nInteger + 4);
          if ( *(int *)(v13.nInteger + 4) <= 0 )
            res._unVal.pTable->Release(this: (struct SQTable *)res._unVal.nInteger);
        }
        return true;
      }
    }
    else if ( type != OT_TABLE )
    {
      v9 = type - 83886082;
      if ( v9 == 0 )
      {
        result->nInteger = v6.nInteger - v7.nInteger;
        SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&res);
        return true;
      }
      v10 = v9 - 2;
      if ( v10 == 0 )
      {
        if ( o2->_unVal.fFloat <= o1->_unVal.fFloat )
          result->nInteger = 1;
        else
          result->nInteger = -1;
        goto LABEL_11;
      }
      if ( v10 == 50331660 )
      {
        v11 = strcmp((const char *)(v6.nInteger + 28), (const char *)(v7.nInteger + 28));
        if ( v11 != 0 )
          result->nInteger = -(v11 < 0) - ((v11 < 0) - 1);
        else
          result->nInteger = 0;
LABEL_11:
        SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&res);
        return true;
      }
      goto LABEL_24;
    }
    if ( *(_DWORD *)(v6.nInteger + 24) != 0 )
    {
      SQVM::Push(this, o: o1);
      SQVM::Push(this, o: o2);
      if ( SQVM::CallMetaMethod(this, del: o1->_unVal.pTable, mm: MT_CMP, nparams: 2, outres: &res) )
      {
        if ( res._type == OT_INTEGER )
        {
          result->pTable = (SQTable *)res._unVal;
          SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&res);
          return true;
        }
        else
        {
          SQVM::Raise_CompareError(this, o1, (SQVM *)o2);
          SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&res);
          return false;
        }
      }
    }
    goto LABEL_24;
  }
  if ( (type & 0x4000000) != 0 && (v5 & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER && v5 == OT_FLOAT )
    {
      fFloat = o2->_unVal.fFloat;
      nInteger = (float)o1->_unVal.nInteger;
      if ( nInteger == fFloat )
        goto LABEL_3;
      v16 = fFloat <= nInteger;
    }
    else
    {
      v17 = o1->_unVal.fFloat;
      v18 = (float)o2->_unVal.nInteger;
      if ( v17 == v18 )
        goto LABEL_3;
      v16 = v18 <= v17;
    }
    v8 = true;
    if ( v16 )
      result->nInteger = 1;
    else
      result->nInteger = -1;
  }
  else if ( type == OT_NULL )
  {
    result->nInteger = -1;
    return true;
  }
  else if ( v5 == OT_NULL )
  {
    result->nInteger = 1;
    return true;
  }
  else
  {
    SQVM::Raise_CompareError(this, o1, (SQVM *)o2);
    return false;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10056690
// Name: public: bool SQVM::CMP_OP(enum CmpOP,struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::CMP_OP@<al>(
        SQVM *this@<ecx>,
        const SQObjectPtr *o1@<edx>,
        SQObjectPtr *o2@<edi>,
        CmpOP op,
        SQObjectPtr *res)
{
  SQObjectPtr *v5; // ebx
  const SQObjectPtr *v6; // eax

  v5 = res;
  if ( !SQVM::ObjCmp(o1, o2, this, result: (tagSQObjectValue *)&res) )
    return 0;
  switch ( op )
  {
    case CMP_G:
      v6 = &_true_;
      if ( (int)res <= 0 )
        v6 = &_false_;
      break;
    case CMP_GE:
      v6 = &_true_;
      if ( (int)res < 0 )
        v6 = &_false_;
      break;
    case CMP_L:
      v6 = &_true_;
      if ( (int)res >= 0 )
        v6 = &_false_;
      break;
    case CMP_LE:
      v6 = &_true_;
      if ( (int)res > 0 )
        v6 = &_false_;
      break;
    default:
      return 0;
  }
  SQObjectPtr::operator=(this: v5, obj: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10056760
// Name: public: void SQVM::ToString(struct SQObjectPtr const __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQVM::ToString(SQVM *this, const SQObjectPtr *o, SQObjectPtr *res)
{
  tagSQObjectType type; // eax
  char *v6; // eax
  const char *v7; // edi
  char *v8; // eax
  char *v9; // eax
  tagSQObjectValue v10; // edx
  tagSQObjectValue v11; // eax
  tagSQObjectValue v12; // eax
  SQObjectPtr *v13; // esi
  tagSQObjectValue v14; // eax
  tagSQObjectValue v15; // ecx
  SQSharedState *v16; // ecx
  char *scratchpad; // eax
  __int32 v18; // eax
  __int32 v19; // eax
  int top; // eax
  SQObjectPtr *vals; // edx
  _DWORD *v22; // ecx
  tagSQObjectType v23; // esi
  SQObjectPtr *v24; // eax
  tagSQObjectType v25; // edx
  const char *v26; // eax
  SQSharedState *v27; // esi
  int scratchpadsize; // eax
  SQSharedState *sharedstate; // edi
  SQString *v30; // esi
  tagSQObjectType v31; // edx
  _DWORD *v32; // ecx
  SQObjectPtr v33; // [esp+14h] [ebp-Ch] BYREF
  const char *v34; // [esp+1Ch] [ebp-4h]
  int oa; // [esp+28h] [ebp+8h]

  type = o->_type;
  if ( o->_type <= OT_WEAKREF )
  {
    if ( o->_type == OT_WEAKREF )
    {
      v10.pTable = (SQTable *)o->_unVal;
      if ( (*(_DWORD *)(v10.nInteger + 12) & 0x8000000) != 0 )
        ++*(_DWORD *)(*(_DWORD *)(v10.nInteger + 16) + 4);
      v11.pTable = (SQTable *)o->_unVal;
      v33._type = *(_DWORD *)(v11.nInteger + 12);
      v12.pTable = *(SQTable **)(v11.nInteger + 16);
      v33._unVal = v12;
      if ( (v33._type & 0x8000000) != 0 )
        ++*(_DWORD *)(v12.nInteger + 4);
      v13 = res;
      SQVM::ToString(this, o: &v33, res);
      if ( (v33._type & 0x8000000) != 0 )
      {
        v14.pTable = (SQTable *)v33._unVal;
        --*(_DWORD *)(v33._unVal.nInteger + 4);
        if ( *(int *)(v14.nInteger + 4) <= 0 )
          v33._unVal.pTable->Release(this: (struct SQTable *)v33._unVal.nInteger);
      }
      v15.pTable = (SQTable *)o->_unVal;
      if ( (*(_DWORD *)(v15.nInteger + 12) & 0x8000000) != 0 )
        --*(_DWORD *)(*(_DWORD *)(v15.nInteger + 16) + 4);
      v16 = (SQSharedState *)(res->_unVal.nInteger
                            + 28
                            + strlen((const char *)(res->_unVal.nInteger + 28))
                            + 1
                            - (res->_unVal.nInteger
                             + 29)
                            + 28);
      if ( (int)v16 <= 0 )
      {
        scratchpad = this->_sharedstate->_scratchpad;
      }
      else
      {
        scratchpad = SQSharedState::GetScratchPad(this: v16, a2: (int)this->_sharedstate);
        v13 = res;
      }
      sprintf(
        string: scratchpad,
        format: (const char *)&stru_1009D15C._qs_fn,
        __PAIR64__(v13->_unVal.nInteger + 28, o->_unVal.nInteger));
      goto LABEL_43;
    }
    if ( type > OT_FLOAT )
    {
      if ( type == OT_STRING )
      {
        SQObjectPtr::operator=(this: res, obj: o);
        return;
      }
    }
    else
    {
      switch ( type )
      {
        case OT_FLOAT:
          v9 = SQSharedState::GetScratchPad(this: (SQSharedState *)0x33, a2: (int)this->_sharedstate);
          sprintf(string: v9, format: (const char *)&stru_1009D15C._qs_cnt, o->_unVal.fFloat);
LABEL_43:
          sharedstate = this->_sharedstate;
          v30 = StringTable::Add(len: -1, this: sharedstate->_stringtable, news: sharedstate->_scratchpad);
          v30->_sharedstate = sharedstate;
          ++v30->_uiRef;
          v31 = res->_type;
          v32 = &res->_unVal.pTable->__vftable;
          res->_unVal.nInteger = (int)v30;
          res->_type = OT_STRING;
          ++v30->_uiRef;
          if ( (v31 & 0x8000000) != 0 && (int)--v32[1] <= 0 )
            (*(void (__thiscall **)(_DWORD *))(*v32 + 8))(a1: v32);
          if ( --v30->_uiRef <= 0 )
            v30->Release(this: v30);
          return;
        case OT_BOOL:
          v7 = "true";
          if ( o->_unVal.nInteger == 0 )
            v7 = "false";
          v8 = SQSharedState::GetScratchPad(this: (SQSharedState *)6, a2: (int)this->_sharedstate);
          sprintf(string: v8, format: v7);
          goto LABEL_43;
        case OT_INTEGER:
          v6 = SQSharedState::GetScratchPad(this: (SQSharedState *)0x33, a2: (int)this->_sharedstate);
          sprintf(string: v6, format: "%d", o->_unVal.nInteger);
          goto LABEL_43;
        default:
          break;
      }
    }
LABEL_38:
    v26 = IdType2Name(type: o->_type);
    v27 = this->_sharedstate;
    v34 = v26;
    scratchpadsize = v27->_scratchpadsize;
    if ( scratchpadsize >= 24 )
    {
      if ( scratchpadsize >= 768 )
      {
        oa = scratchpadsize >> 1;
        v27->_scratchpad = (char *)_g_pMemAlloc->Realloc_2(
                                     this: _g_pMemAlloc,
                                     a2: v27->_scratchpad,
                                     a3: scratchpadsize >> 1);
        v27->_scratchpadsize = oa;
      }
    }
    else
    {
      v27->_scratchpad = (char *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v27->_scratchpad, a3: 36);
      v27->_scratchpadsize = 36;
    }
    sprintf(
      string: v27->_scratchpad,
      format: (const char *)&stru_1009D15C._vargsstack._allocated,
      v34,
      o->_unVal.nInteger);
    goto LABEL_43;
  }
  v18 = type - 167772192;
  if ( v18 != 0 )
  {
    v19 = v18 - 96;
    if ( v19 != 0 && v19 != 32640 )
      goto LABEL_38;
  }
  if ( *(_DWORD *)(o->_unVal.nInteger + 24) == 0 )
    goto LABEL_38;
  top = this->_top;
  vals = this->_stack._vals;
  this->_top = top + 1;
  v22 = &vals[top]._unVal.pTable->__vftable;
  v23 = vals[top]._type;
  v24 = &vals[top];
  v24->_unVal.nInteger = o->_unVal.nInteger;
  v25 = o->_type;
  v24->_type = o->_type;
  if ( (v25 & 0x8000000) != 0 )
    ++*(_DWORD *)(v24->_unVal.nInteger + 4);
  if ( (v23 & 0x8000000) != 0 && (int)--v22[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v22 + 8))(a1: v22);
  if ( !SQVM::CallMetaMethod(this, del: o->_unVal.pTable, mm: MT_TOSTRING, nparams: 1, outres: res)
    || res->_type != OT_STRING )
  {
    goto LABEL_38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056A80
// Name: public: bool SQVM::StringCat(struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQVM::StringCat(SQVM *this, SQVM *str, const SQObjectPtr *obj, SQObjectPtr *dest, char *s)
{
  SQVM *v6; // esi
  unsigned int v7; // edi
  SQSharedState *v8; // ecx
  unsigned __int8 *scratchpad; // eax
  SQSharedState *sharedstate; // edi
  SQString *v11; // esi
  int v12; // eax
  _DWORD *v13; // ecx
  tagSQObjectValue v14; // eax
  tagSQObjectValue v15; // eax
  SQObjectPtr a; // [esp+10h] [ebp-10h] BYREF
  SQObjectPtr b; // [esp+18h] [ebp-8h] BYREF
  unsigned int ol; // [esp+2Ch] [ebp+Ch]
  const SQObjectPtr *obja; // [esp+30h] [ebp+10h]
  char *sa; // [esp+34h] [ebp+14h]

  v6 = str;
  a._type = OT_NULL;
  b._type = OT_NULL;
  a._unVal.nInteger = 0;
  b._unVal.nInteger = 0;
  SQVM::ToString(this: str, o: obj, res: &a);
  SQVM::ToString(this: str, o: dest, res: &b);
  v7 = *(_DWORD *)(a._unVal.nInteger + 20);
  ol = *(_DWORD *)(b._unVal.nInteger + 20);
  v8 = (SQSharedState *)(v7 + ol + 1);
  obja = (const SQObjectPtr *)(v7 + ol);
  if ( (int)v8 <= 0 )
  {
    scratchpad = (unsigned __int8 *)str->_sharedstate->_scratchpad;
  }
  else
  {
    scratchpad = (unsigned __int8 *)SQSharedState::GetScratchPad(this: v8, a2: (int)str->_sharedstate);
    v6 = str;
  }
  sa = (char *)scratchpad;
  memcpy(dst: scratchpad, src: (unsigned __int8 *)(a._unVal.nInteger + 28), count: v7);
  memcpy(dst: (unsigned __int8 *)&sa[v7], src: (unsigned __int8 *)(b._unVal.nInteger + 28), count: ol);
  sharedstate = v6->_sharedstate;
  v11 = StringTable::Add(len: (int)obja, this: sharedstate->_stringtable, news: sharedstate->_scratchpad);
  v11->_sharedstate = sharedstate;
  ++v11->_uiRef;
  v12 = *(_DWORD *)s;
  v13 = *((_DWORD **)s + 1);
  *((_DWORD *)s + 1) = v11;
  *(_DWORD *)s = 134217744;
  ++v11->_uiRef;
  if ( (v12 & 0x8000000) != 0 && (int)--v13[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
  if ( --v11->_uiRef <= 0 )
    v11->Release(this: v11);
  if ( (b._type & 0x8000000) != 0 )
  {
    v14.pTable = (SQTable *)b._unVal;
    --*(_DWORD *)(b._unVal.nInteger + 4);
    if ( *(int *)(v14.nInteger + 4) <= 0 )
      b._unVal.pTable->Release(this: (struct SQTable *)b._unVal.nInteger);
  }
  if ( (a._type & 0x8000000) != 0 )
  {
    v15.pTable = (SQTable *)a._unVal;
    --*(_DWORD *)(a._unVal.nInteger + 4);
    if ( *(int *)(v15.nInteger + 4) <= 0 )
      a._unVal.pTable->Release(this: (struct SQTable *)a._unVal.nInteger);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10056BD0
// Name: public: void SQVM::TypeOf(struct SQObjectPtr const __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQVM::TypeOf(const SQObjectPtr *obj1@<eax>, SQObjectPtr *dest@<edi>, SQVM *this)
{
  int top; // eax
  int v6; // ecx
  SQObjectPtr *v7; // eax
  _DWORD *v8; // ecx
  tagSQObjectType type; // edx
  char *v10; // eax
  SQSharedState *sharedstate; // ebx
  SQString *v12; // esi
  tagSQObjectType v13; // eax
  _DWORD *v14; // ecx
  tagSQObjectType thisa; // [esp+10h] [ebp+8h]

  if ( (obj1->_type & 0x2000000) == 0 || *(_DWORD *)(obj1->_unVal.nInteger + 24) == 0 )
    goto LABEL_9;
  top = this->_top;
  v6 = top + 1;
  v7 = &this->_stack._vals[top];
  this->_top = v6;
  thisa = v7->_type;
  v8 = &v7->_unVal.pTable->__vftable;
  v7->_unVal.nInteger = obj1->_unVal.nInteger;
  type = obj1->_type;
  v7->_type = obj1->_type;
  if ( (type & 0x8000000) != 0 )
    ++*(_DWORD *)(v7->_unVal.nInteger + 4);
  if ( (thisa & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  if ( !SQVM::CallMetaMethod(this, del: obj1->_unVal.pTable, mm: MT_TYPEOF, nparams: 1, outres: dest) )
  {
LABEL_9:
    v10 = (char *)IdType2Name(type: obj1->_type);
    sharedstate = this->_sharedstate;
    v12 = StringTable::Add(len: -1, this: sharedstate->_stringtable, news: v10);
    v12->_sharedstate = sharedstate;
    ++v12->_uiRef;
    v13 = dest->_type;
    v14 = &dest->_unVal.pTable->__vftable;
    dest->_unVal.nInteger = (int)v12;
    dest->_type = OT_STRING;
    ++v12->_uiRef;
    if ( (v13 & 0x8000000) != 0 && (int)--v14[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
    if ( --v12->_uiRef <= 0 )
      v12->Release(this: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056CB0
// Name: public: bool SQVM::Init(struct SQVM __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQVM::Init(sqvector<SQObjectPtr> *stacksize, SQVM *this, SQVM *friendvm)
{
  int *pTable; // ecx
  SQVM::CallInfo *vals; // ecx
  SQTable *v6; // edi
  SQCollectable *gc_chain; // ecx
  tagSQObjectType v8; // eax
  _DWORD *v9; // ecx
  SQTable_vtbl *v10; // edx
  SQTable_vtbl **v11; // ecx
  _DWORD *v12; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v14; // eax
  _DWORD *v15; // ecx
  tagSQObjectType v16; // edx
  tagSQObjectType v17; // eax
  tagSQObjectValue v18; // eax
  tagSQObjectType v19; // edx
  tagSQObjectType v20; // edi
  SQVM::CallInfo v22; // [esp+10h] [ebp-38h] BYREF
  SQObjectPtr fill; // [esp+40h] [ebp-8h] BYREF
  SQSharedState *thisa; // [esp+50h] [ebp+8h]

  fill._type = OT_NULL;
  fill._unVal.nInteger = 0;
  sqvector<SQObjectPtr>::resize(this: stacksize, a2: (int)&this->_stack, newsize: (unsigned int)stacksize, &fill);
  v22._closure._type = OT_NULL;
  this->_alloccallsstacksize = 4;
  v22._closure._unVal.nInteger = 0;
  v22._vargs = 0;
  sqvector<SQVM::CallInfo>::resize(this: &this->_callstackdata, fill: &v22, newsize: 4u);
  if ( (v22._closure._type & 0x8000000) != 0 )
  {
    pTable = (int *)v22._closure._unVal.pTable;
    --*(_DWORD *)(v22._closure._unVal.nInteger + 4);
    if ( pTable[1] <= 0 )
      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
  vals = this->_callstackdata._vals;
  this->_callsstacksize = 0;
  this->_callsstack = vals;
  this->_stackbase = 0;
  this->_top = 0;
  if ( friendvm != nullptr )
  {
    v12 = &this->_roottable._unVal.pTable->__vftable;
    type = this->_roottable._type;
    this->_roottable._unVal.nInteger = friendvm->_roottable._unVal.nInteger;
    v14 = friendvm->_roottable._type;
    this->_roottable._type = v14;
    if ( (v14 & 0x8000000) != 0 )
      ++*(_DWORD *)(this->_roottable._unVal.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v12[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
    v15 = &this->_errorhandler._unVal.pTable->__vftable;
    v16 = this->_errorhandler._type;
    this->_errorhandler._unVal.nInteger = friendvm->_errorhandler._unVal.nInteger;
    v17 = friendvm->_errorhandler._type;
    this->_errorhandler._type = v17;
    if ( (v17 & 0x8000000) != 0 )
      ++*(_DWORD *)(this->_errorhandler._unVal.nInteger + 4);
    if ( (v16 & 0x8000000) != 0 && (int)--v15[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15);
    v18.pTable = (SQTable *)friendvm->_debughook._unVal;
    v11 = (SQTable_vtbl **)this->_debughook._unVal.pTable;
    v19 = this->_debughook._type;
    this->_debughook._unVal = v18;
    v20 = friendvm->_debughook._type;
    this->_debughook._type = v20;
    if ( (v20 & 0x8000000) != 0 )
      ++*(_DWORD *)(v18.nInteger + 4);
    if ( (v19 & 0x8000000) != 0 )
    {
      v11[1] = (SQTable_vtbl *)((char *)v11[1] - 1);
      if ( (int)v11[1] <= 0 )
      {
        v10 = *v11;
        goto LABEL_29;
      }
    }
  }
  else
  {
    thisa = this->_sharedstate;
    v6 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
    if ( v6 != nullptr )
    {
      v6->_uiRef = 0;
      v6->_weakref = nullptr;
      v6->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
      SQTable::AllocNodes(nSize: 4, this: v6);
      v6->_next = nullptr;
      v6->_usednodes = 0;
      v6->_delegate = nullptr;
      v6->_sharedstate = thisa;
      v6->_prev = nullptr;
      v6->_next = thisa->_gc_chain;
      gc_chain = thisa->_gc_chain;
      if ( gc_chain != nullptr )
        gc_chain->_prev = v6;
      thisa->_gc_chain = v6;
    }
    v6->_delegate = nullptr;
    ++v6->_uiRef;
    v8 = this->_roottable._type;
    v9 = &this->_roottable._unVal.pTable->__vftable;
    this->_roottable._unVal.nInteger = (int)v6;
    this->_roottable._type = OT_TABLE;
    ++v6->_uiRef;
    if ( (v8 & 0x8000000) != 0 && (int)--v9[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
    if ( --v6->_uiRef <= 0 )
    {
      v10 = v6->__vftable;
      v11 = (SQTable_vtbl **)v6;
LABEL_29:
      ((void (__fastcall *)(SQTable_vtbl **))v10->Release)(a1: v11);
    }
  }
  sq_base_register(v: this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10056EA0
// Name: public: bool SQVM::StartCall(struct SQClosure __near *,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::StartCall@<al>(
        sqvector<SQObjectPtr> *args@<eax>,
        SQVM *this,
        SQClosure *closure,
        int target,
        int stackbase,
        bool tailcall)
{
  SQClosure *v7; // esi
  SQFunctionProto *pFunctionProto; // edx
  sqvector<SQObjectPtr> *nparameters; // ecx
  int ndefaultparams; // edx
  int v11; // edi
  char *v12; // edx
  int v13; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectType *v15; // eax
  SQObjectPtr *v16; // edx
  tagSQObjectValue v17; // ecx
  tagSQObjectType type; // edx
  int *v19; // ecx
  int v21; // eax
  unsigned int v22; // edi
  SQObjectPtr *v23; // eax
  tagSQObjectType v24; // edx
  SQObjectPtr *v25; // eax
  tagSQObjectType v26; // esi
  tagSQObjectValue v27; // edx
  tagSQObjectValue *v28; // eax
  tagSQObjectValue v29; // edi
  int v30; // edx
  int *v31; // eax
  int v32; // eax
  int v33; // esi
  int alloccallsstacksize; // eax
  int v35; // esi
  int *v36; // ecx
  SQVM::CallInfo *v37; // esi
  int *v38; // ecx
  SQVM::CallInfo *ci; // eax
  tagSQObjectType v40; // edx
  _DWORD *v41; // ecx
  SQFunctionProto *v42; // eax
  unsigned int size; // ecx
  int v44; // eax
  bool v45; // zf
  const char *v46; // [esp+0h] [ebp-94h]
  SQVM::CallInfo fill; // [esp+10h] [ebp-84h] BYREF
  SQVM::CallInfo lc; // [esp+40h] [ebp-54h] BYREF
  SQObjectPtr v49; // [esp+70h] [ebp-24h] BYREF
  int *pTable; // [esp+78h] [ebp-1Ch]
  tagSQObjectType v51; // [esp+7Ch] [ebp-18h]
  int newtop; // [esp+80h] [ebp-14h]
  int nargs; // [esp+84h] [ebp-10h]
  int i; // [esp+88h] [ebp-Ch]
  SQFunctionProto *func; // [esp+8Ch] [ebp-8h]
  __int16 paramssize; // [esp+9Ch] [ebp+8h]

  v7 = closure;
  pFunctionProto = closure->_function._unVal.pFunctionProto;
  nparameters = (sqvector<SQObjectPtr> *)pFunctionProto->_nparameters;
  func = pFunctionProto;
  paramssize = (__int16)nparameters;
  newtop = stackbase + pFunctionProto->_stacksize;
  nargs = (int)args;
  if ( nparameters == args )
    goto LABEL_27;
  ndefaultparams = func->_ndefaultparams;
  v49._unVal.nInteger = ndefaultparams;
  if ( ndefaultparams != 0 && (int)args < (int)nparameters )
  {
    v11 = (int)args + ndefaultparams - (_DWORD)nparameters;
    if ( v11 < ndefaultparams )
    {
      v12 = (char *)((char *)nparameters - (char *)args);
      v13 = 8 * ((_DWORD)args + stackbase);
      nargs = (int)&v12[(_DWORD)args];
      while ( 1 )
      {
        vals = closure->_defaultparams._vals;
        v15 = (tagSQObjectType *)((char *)&this->_stack._vals->_type + v13);
        i = v13 + 8;
        v51 = *v15;
        v16 = &vals[v11];
        pTable = *((int **)v15 + 1);
        v17.pTable = (SQTable *)v16->_unVal;
        v15[1] = (tagSQObjectType)v17.pTable;
        type = v16->_type;
        *v15 = type;
        if ( (type & 0x8000000) != 0 )
          ++*(_DWORD *)(v17.nInteger + 4);
        if ( (v51 & 0x8000000) != 0 )
        {
          v19 = pTable;
          --pTable[1];
          if ( v19[1] <= 0 )
            (*(void (__thiscall **)(int *))(*v19 + 8))(a1: v19);
        }
        if ( ++v11 >= v49._unVal.nInteger )
          break;
        v13 = i;
      }
LABEL_26:
      LOWORD(nparameters) = paramssize;
    }
  }
  else
  {
    if ( !func->_varparams || (int)args < (int)nparameters )
    {
      SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D15C._roottable, s: v46);
      return 0;
    }
    v21 = (char *)args - (char *)nparameters;
    if ( v21 > 0 )
    {
      v22 = (unsigned int)nparameters + stackbase;
      for ( i = v21; i != 0; --i )
      {
        sqvector<SQObjectPtr>::push_back(this: nparameters, a2: (int)&this->_vargsstack, val: &this->_stack._vals[v22]);
        v23 = this->_stack._vals;
        nparameters = (sqvector<SQObjectPtr> *)v23[v22]._unVal.pTable;
        v24 = v23[v22]._type;
        v25 = &v23[v22];
        v25->_unVal.nInteger = _null_._unVal.nInteger;
        v26 = _null_._type;
        v25->_type = _null_._type;
        if ( (v26 & 0x8000000) != 0 )
          ++*(_DWORD *)(v25->_unVal.nInteger + 4);
        if ( (v24 & 0x8000000) != 0 && (int)--nparameters->_size <= 0 )
          ((void (__thiscall *)(sqvector<SQObjectPtr> *))nparameters->_vals[1]._type)(a1: nparameters);
        ++v22;
      }
      v7 = closure;
      goto LABEL_26;
    }
  }
LABEL_27:
  if ( v7->_env._type == OT_WEAKREF )
  {
    v27.pTable = (SQTable *)v7->_env._unVal;
    v28 = (tagSQObjectValue *)&this->_stack._vals[stackbase];
    v49._unVal = (tagSQObjectValue)v28->pTable;
    pTable = (int *)v28[1].pTable;
    v29.pTable = *(SQTable **)(v27.nInteger + 16);
    v28[1].pTable = v29.pTable;
    v30 = *(_DWORD *)(v27.nInteger + 12);
    v28->nInteger = v30;
    if ( (v30 & 0x8000000) != 0 )
      ++*(_DWORD *)(v29.nInteger + 4);
    if ( (v49._unVal.nInteger & 0x8000000) != 0 )
    {
      v31 = pTable;
      --pTable[1];
      if ( v31[1] <= 0 )
      {
        (*(void (__thiscall **)(int *))(*v31 + 8))(a1: v31);
        LOWORD(nparameters) = paramssize;
      }
    }
  }
  if ( tailcall )
  {
    ++this->ci->_ncalls;
  }
  else
  {
    lc._vargs.size = 0;
    lc._vargs.base = 0;
    v32 = this->_stackbase;
    lc._prevstkbase = stackbase - v32;
    lc._target = target;
    v33 = this->_top - v32;
    alloccallsstacksize = this->_alloccallsstacksize;
    lc._closure._type = OT_NULL;
    memset(&lc._closure._unVal, 0, 12);
    lc._prevtop = v33;
    lc._ncalls = 1;
    lc._root = 0;
    if ( this->_callsstacksize == alloccallsstacksize )
    {
      v35 = 2 * alloccallsstacksize;
      fill._closure._type = OT_NULL;
      fill._closure._unVal.nInteger = 0;
      fill._vargs = 0;
      sqvector<SQVM::CallInfo>::resize(this: &this->_callstackdata, &fill, newsize: 2 * alloccallsstacksize);
      if ( (fill._closure._type & 0x8000000) != 0 )
      {
        v36 = (int *)fill._closure._unVal.pTable;
        --*(_DWORD *)(fill._closure._unVal.nInteger + 4);
        if ( v36[1] <= 0 )
          (*(void (__thiscall **)(int *))(*v36 + 8))(a1: v36);
      }
      this->_callsstack = this->_callstackdata._vals;
      this->_alloccallsstacksize = v35;
    }
    v37 = &this->_callsstack[this->_callsstacksize];
    this->ci = v37;
    SQVM::CallInfo::operator=(this: v37, __that: &lc);
    ++this->_callsstacksize;
    if ( (lc._closure._type & 0x8000000) != 0 )
    {
      v38 = (int *)lc._closure._unVal.pTable;
      --*(_DWORD *)(lc._closure._unVal.nInteger + 4);
      if ( v38[1] <= 0 )
        (*(void (__thiscall **)(int *))(*v38 + 8))(a1: v38);
    }
    LOWORD(nparameters) = paramssize;
    v7 = closure;
  }
  this->ci->_vargs.size = nargs - (_WORD)nparameters;
  this->ci->_vargs.base = LOWORD(this->_vargsstack._size) - this->ci->_vargs.size;
  ++v7->_uiRef;
  ci = this->ci;
  v40 = ci->_closure._type;
  v41 = &ci->_closure._unVal.pTable->__vftable;
  ci->_closure._unVal.nInteger = (int)v7;
  ci->_closure._type = OT_CLOSURE;
  ++v7->_uiRef;
  if ( (v40 & 0x8000000) != 0 && (int)--v41[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v41 + 8))(a1: v41);
  if ( --v7->_uiRef <= 0 )
    v7->Release(this: v7);
  v42 = func;
  this->ci->_literals = func->_literals;
  this->ci->_ip = v42->_instructions;
  size = this->_stack._size;
  v44 = 2 * v42->_stacksize;
  if ( v44 + newtop > size )
  {
    v49._type = OT_NULL;
    v49._unVal.nInteger = 0;
    sqvector<SQObjectPtr>::resize(
      this: (sqvector<SQObjectPtr> *)(v44 + size),
      a2: (int)&this->_stack,
      newsize: v44 + size,
      fill: &v49);
  }
  v45 = this->_debughook._type == OT_NULL;
  this->_top = newtop;
  this->_stackbase = stackbase;
  if ( !v45 && this->_debughook._unVal.nInteger != this->ci->_closure._unVal.nInteger )
    SQVM::CallDebugHook(this: (SQVM *)stackbase, type: 99, forcedline: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10057230
// Name: public: bool SQVM::Return(int,int,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge SQVM::Return@<al>(SQVM *this@<ecx>, SQObjectPtr *retval@<eax>, int _arg0, int _arg1)
{
  SQVM::CallInfo *ci; // eax
  SQVM *pThread; // ecx
  int v8; // ebx
  SQVM::CallInfo *v9; // eax
  int stackbase; // ebx
  SQVM *v11; // ecx
  int v12; // edx
  SQVM::VarArgs *p_vargs; // eax
  SQVM::CallInfo *v14; // eax
  tagSQObjectType type; // ecx
  _DWORD *v16; // edx
  int callsstacksize; // eax
  _DWORD *v18; // edx
  SQObjectPtr *v19; // eax
  tagSQObjectValue v20; // ecx
  tagSQObjectType v21; // ebx
  tagSQObjectType v22; // eax
  bool v23; // zf
  _DWORD *v24; // eax
  tagSQObjectType v25; // ecx
  tagSQObjectType v26; // edx
  int v27; // ecx
  SQObjectPtr *vals; // eax
  _DWORD *v29; // edi
  SQObjectPtr *v30; // edx
  tagSQObjectType v31; // ebx
  SQObjectPtr *v32; // eax
  tagSQObjectValue v33; // ecx
  tagSQObjectType v34; // edx
  SQObjectPtr *v35; // eax
  tagSQObjectType v36; // ecx
  tagSQObjectType v37; // edi
  int last_top; // [esp+Ch] [ebp-Ch]
  int target; // [esp+10h] [ebp-8h]
  unsigned int broot; // [esp+14h] [ebp-4h]

  if ( this->_debughook._type != OT_NULL )
  {
    ci = this->ci;
    pThread = this->_debughook._unVal.pThread;
    if ( pThread != ci->_closure._unVal.pThread )
    {
      v8 = 0;
      if ( ci->_ncalls > 0 )
      {
        do
        {
          SQVM::CallDebugHook(this: pThread, type: 114, forcedline: 0);
          ++v8;
        }
        while ( v8 < this->ci->_ncalls );
      }
    }
  }
  v9 = this->ci;
  stackbase = this->_stackbase;
  broot = v9->_root;
  target = v9->_target;
  v11 = (SQVM *)(stackbase - v9->_prevstkbase);
  last_top = this->_top;
  this->_stackbase = (int)v11;
  v12 = (int)v11 + v9->_prevtop;
  p_vargs = &v9->_vargs;
  this->_top = v12;
  if ( p_vargs->size != 0 )
    SQVM::PopVarArgs(this: v11, vargs: p_vargs);
  --this->_callsstacksize;
  v14 = this->ci;
  type = v14->_closure._type;
  v16 = &v14->_closure._unVal.pTable->__vftable;
  v14->_closure._type = OT_NULL;
  v14->_closure._unVal.nInteger = 0;
  if ( (type & 0x8000000) != 0 && (int)--v16[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v16 + 8))(a1: v16);
  callsstacksize = this->_callsstacksize;
  if ( callsstacksize != 0 )
    this->ci = &this->_callsstack[callsstacksize - 1];
  else
    this->ci = nullptr;
  if ( broot != 0 )
  {
    if ( _arg0 != 255 )
    {
      v18 = &retval->_unVal.pTable->__vftable;
      v19 = &this->_stack._vals[_arg1 + stackbase];
      v20.pTable = (SQTable *)v19->_unVal;
      v21 = retval->_type;
      retval->_unVal = v20;
      v22 = v19->_type;
      retval->_type = v22;
      if ( (v22 & 0x8000000) != 0 )
        ++*(_DWORD *)(v20.nInteger + 4);
      v23 = (v21 & 0x8000000) == 0;
LABEL_33:
      if ( !v23 && (int)--v18[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v18 + 8))(a1: v18);
      goto LABEL_36;
    }
    v24 = &retval->_unVal.pTable->__vftable;
    v25 = retval->_type;
    retval->_unVal.nInteger = _null_._unVal.nInteger;
    v26 = _null_._type;
    retval->_type = _null_._type;
    if ( (v26 & 0x8000000) != 0 )
      ++*(_DWORD *)(retval->_unVal.nInteger + 4);
    if ( (v25 & 0x8000000) != 0 && (int)--v24[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v24 + 8))(a1: v24);
  }
  else
  {
    if ( target == -1 )
      goto LABEL_36;
    v27 = target + this->_stackbase;
    if ( _arg0 == 255 )
    {
      v35 = &this->_stack._vals[v27];
      v18 = &v35->_unVal.pTable->__vftable;
      v36 = v35->_type;
      v35->_unVal.nInteger = _null_._unVal.nInteger;
      v37 = _null_._type;
      v35->_type = _null_._type;
      if ( (v37 & 0x8000000) != 0 )
        ++*(_DWORD *)(v35->_unVal.nInteger + 4);
      v23 = (v36 & 0x8000000) == 0;
      goto LABEL_33;
    }
    vals = this->_stack._vals;
    v29 = &vals[v27]._unVal.pTable->__vftable;
    v30 = &vals[_arg1 + stackbase];
    v31 = vals[v27]._type;
    v32 = &vals[v27];
    v33.pTable = (SQTable *)v30->_unVal;
    v32->_unVal = v33;
    v34 = v30->_type;
    v32->_type = v34;
    if ( (v34 & 0x8000000) != 0 )
      ++*(_DWORD *)(v33.nInteger + 4);
    if ( (v31 & 0x8000000) != 0 && (int)--v29[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v29 + 8))(a1: v29);
  }
LABEL_36:
  if ( last_top >= this->_top )
    SQVM::ClearStack(this, last_top);
  return broot != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10057460
// Name: public: bool SQVM::PLOCAL_INC(int,struct SQObjectPtr __near &,struct SQObjectPtr __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::PLOCAL_INC@<al>(
        SQVM *this@<ecx>,
        SQObjectPtr *target@<eax>,
        SQObjectPtr *a@<esi>,
        SQObjectPtr *op,
        SQObjectPtr *incr)
{
  tagSQObjectValue v6; // eax
  _DWORD *v8; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v10; // eax
  _DWORD *v11; // ecx
  tagSQObjectType v12; // eax
  tagSQObjectType v13; // edx
  tagSQObjectValue v14; // eax
  SQObjectPtr trg; // [esp+8h] [ebp-Ch] BYREF

  trg._type = OT_NULL;
  trg._unVal.nInteger = 0;
  if ( SQVM::ARITH_OP(this, o2: op, op: (const char *)0x2B, &trg, o1: a) )
  {
    v8 = &target->_unVal.pTable->__vftable;
    type = target->_type;
    target->_unVal.nInteger = a->_unVal.nInteger;
    v10 = a->_type;
    target->_type = a->_type;
    if ( (v10 & 0x8000000) != 0 )
      ++*(_DWORD *)(target->_unVal.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v8[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
    v11 = &a->_unVal.pTable->__vftable;
    v12 = a->_type;
    a->_unVal.nInteger = trg._unVal.nInteger;
    v13 = trg._type;
    a->_type = trg._type;
    if ( (v13 & 0x8000000) != 0 )
      ++*(_DWORD *)(trg._unVal.nInteger + 4);
    if ( (v12 & 0x8000000) != 0 && (int)--v11[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
    if ( (trg._type & 0x8000000) != 0 )
    {
      v14.pTable = (SQTable *)trg._unVal;
      --*(_DWORD *)(trg._unVal.nInteger + 4);
      if ( *(int *)(v14.nInteger + 4) <= 0 )
        trg._unVal.pTable->Release(this: (struct SQTable *)trg._unVal.nInteger);
    }
    return 1;
  }
  else
  {
    if ( (trg._type & 0x8000000) != 0 )
    {
      v6.pTable = (SQTable *)trg._unVal;
      --*(_DWORD *)(trg._unVal.nInteger + 4);
      if ( *(int *)(v6.nInteger + 4) <= 0 )
        trg._unVal.pTable->Release(this: (struct SQTable *)trg._unVal.nInteger);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057550
// Name: public: bool SQVM::DerefInc(int,struct SQObjectPtr __near &,struct SQObjectPtr __near &,struct SQObjectPtr __near &,struct SQObjectPtr __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::DerefInc@<al>(
        SQObjectPtr *self@<eax>,
        SQObjectPtr *key@<edx>,
        SQVM *this,
        const char *op,
        SQObjectPtr *target,
        SQObjectPtr *incr,
        bool postfix)
{
  _DWORD *v7; // ebx
  tagSQObjectValue v9; // ecx
  SQVM *v10; // ecx
  SQString *v11; // esi
  tagSQObjectValue v12; // eax
  tagSQObjectValue v13; // eax
  tagSQObjectValue v15; // eax
  tagSQObjectValue v16; // eax
  _DWORD *v17; // ecx
  tagSQObjectType type; // eax
  tagSQObjectType v19; // edx
  tagSQObjectValue v20; // eax
  tagSQObjectValue v21; // eax
  SQObjectPtr tself; // [esp+10h] [ebp-1Ch] BYREF
  SQObjectPtr tkey; // [esp+18h] [ebp-14h] BYREF
  SQObjectPtr tmp; // [esp+20h] [ebp-Ch] BYREF
  SQObjectPtr *targeta; // [esp+3Ch] [ebp+10h]

  v7 = &self->_unVal.pTable->__vftable;
  tself._type = self->_type;
  tmp._type = OT_NULL;
  tmp._unVal.nInteger = 0;
  tself._unVal.nInteger = (int)v7;
  targeta = (SQObjectPtr *)(tself._type & 0x8000000);
  if ( (tself._type & 0x8000000) != 0 )
    ++v7[1];
  v9.pTable = (SQTable *)key->_unVal;
  tkey._type = key->_type;
  tkey._unVal = v9;
  if ( (tkey._type & 0x8000000) != 0 )
    ++*(_DWORD *)(v9.nInteger + 4);
  if ( SQVM::Get(this, self: &tself, key: &tkey, dest: &tmp, raw: false, fetchroot: true) )
  {
    if ( SQVM::ARITH_OP(this, o2: incr, op, trg: target, o1: &tmp) )
    {
      SQVM::Set(this, self: &tself, key: &tkey, val: target, fetchroot: true);
      if ( postfix )
      {
        v17 = &target->_unVal.pTable->__vftable;
        type = target->_type;
        target->_unVal.nInteger = tmp._unVal.nInteger;
        v19 = tmp._type;
        target->_type = tmp._type;
        if ( (v19 & 0x8000000) != 0 )
          ++*(_DWORD *)(tmp._unVal.nInteger + 4);
        if ( (type & 0x8000000) != 0 && (int)--v17[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v17 + 8))(a1: v17);
      }
      if ( (tkey._type & 0x8000000) != 0 )
      {
        v20.pTable = (SQTable *)tkey._unVal;
        --*(_DWORD *)(tkey._unVal.nInteger + 4);
        if ( *(int *)(v20.nInteger + 4) <= 0 )
          tkey._unVal.pTable->Release(this: (struct SQTable *)tkey._unVal.nInteger);
      }
      if ( targeta != nullptr && (int)--v7[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
      if ( (tmp._type & 0x8000000) != 0 )
      {
        v21.pTable = (SQTable *)tmp._unVal;
        --*(_DWORD *)(tmp._unVal.nInteger + 4);
        if ( *(int *)(v21.nInteger + 4) <= 0 )
          tmp._unVal.pTable->Release(this: (struct SQTable *)tmp._unVal.nInteger);
      }
      return 1;
    }
    else
    {
      if ( (tkey._type & 0x8000000) != 0 )
      {
        v15.pTable = (SQTable *)tkey._unVal;
        --*(_DWORD *)(tkey._unVal.nInteger + 4);
        if ( *(int *)(v15.nInteger + 4) <= 0 )
          tkey._unVal.pTable->Release(this: (struct SQTable *)tkey._unVal.nInteger);
      }
      if ( targeta != nullptr && (int)--v7[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
      if ( (tmp._type & 0x8000000) != 0 )
      {
        v16.pTable = (SQTable *)tmp._unVal;
        --*(_DWORD *)(tmp._unVal.nInteger + 4);
        if ( *(int *)(v16.nInteger + 4) <= 0 )
          tmp._unVal.pTable->Release(this: (struct SQTable *)tmp._unVal.nInteger);
      }
      return 0;
    }
  }
  else
  {
    v11 = SQVM::PrintObjVal(this: v10, o: this, oa: &tkey);
    ++v11->_uiRef;
    SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009C8A0, s: v11->_val);
    if ( --v11->_uiRef <= 0 )
      v11->Release(this: v11);
    if ( (tkey._type & 0x8000000) != 0 )
    {
      v12.pTable = (SQTable *)tkey._unVal;
      --*(_DWORD *)(tkey._unVal.nInteger + 4);
      if ( *(int *)(v12.nInteger + 4) <= 0 )
        tkey._unVal.pTable->Release(this: (struct SQTable *)tkey._unVal.nInteger);
    }
    if ( targeta != nullptr && (int)--v7[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
    if ( (tmp._type & 0x8000000) != 0 )
    {
      v13.pTable = (SQTable *)tmp._unVal;
      --*(_DWORD *)(tmp._unVal.nInteger + 4);
      if ( *(int *)(v13.nInteger + 4) <= 0 )
        tmp._unVal.pTable->Release(this: (struct SQTable *)tmp._unVal.nInteger);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057780
// Name: public: void SQVM::PopVarArgs(struct SQVM::VarArgs __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQVM::PopVarArgs(SQVM *this@<ecx>, int a2@<esi>, SQVM::VarArgs *vargs)
{
  int v3; // ebx
  _DWORD *v4; // ecx
  int v5; // eax

  v3 = 0;
  if ( vargs->size != 0 )
  {
    do
    {
      --*(_DWORD *)(a2 + 48);
      v4 = (_DWORD *)(*(_DWORD *)(a2 + 44) + 8 * *(_DWORD *)(a2 + 48));
      if ( (*v4 & 0x8000000) != 0 )
      {
        v5 = v4[1];
        if ( (int)--*(_DWORD *)(v5 + 4) <= 0 )
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v4[1] + 8))(a1: v4[1]);
      }
      ++v3;
    }
    while ( v3 < vargs->size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100577D0
// Name: public: bool SQVM::FOREACH_OP(struct SQObjectPtr __near &,struct SQObjectPtr __near &,struct SQObjectPtr __near &,struct SQObjectPtr __near &,int,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::FOREACH_OP@<al>(
        SQObjectPtr *o1@<ecx>,
        SQObjectPtr *o2@<eax>,
        SQVM *this,
        SQObjectPtr *o3,
        SQObjectPtr *o4,
        int arg_2,
        int exitpos,
        int *jump)
{
  tagSQObjectType type; // eax
  int v11; // ecx
  SQObjectPtr *v13; // ecx
  unsigned int v14; // eax
  SQObjectPtr *v15; // ecx
  int v16; // eax
  SQObjectPtr *v17; // ecx
  int v18; // esi
  tagSQObjectValue v19; // eax
  const char *v20; // eax
  SQObjectPtr *v21; // eax
  tagSQObjectValue v22; // eax
  int v23; // eax
  SQObjectPtr *v24; // ecx
  const char *v25; // [esp+0h] [ebp-18h]
  SQObjectPtr itr; // [esp+10h] [ebp-8h] BYREF
  SQObjectPtr *idx; // [esp+30h] [ebp+18h]

  type = o1->_type;
  if ( o1->_type > OT_CLASS )
  {
    if ( type == OT_TABLE )
    {
      v23 = SQTable::Next(refpos: o4, outkey: o2, this: o1->_unVal.pTable, getweakrefs: false, outval: o3);
      if ( v23 == -1 )
      {
        *jump = exitpos;
      }
      else
      {
        SQObjectPtr::operator=(this: v24, a2: o4, i: v23);
        *jump = 1;
      }
      return 1;
    }
    if ( type != OT_USERDATA && type != OT_INSTANCE )
      goto LABEL_26;
    if ( *(_DWORD *)(o1->_unVal.nInteger + 24) != 0 )
    {
      itr._type = OT_NULL;
      itr._unVal.nInteger = 0;
      SQVM::Push(this, o: o1);
      SQVM::Push(this, o: o4);
      if ( !SQVM::CallMetaMethod(this, del: o1->_unVal.pTable, mm: MT_NEXTI, nparams: 2, outres: &itr) )
      {
        SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D210._stack, s: v25);
        if ( (itr._type & 0x8000000) != 0 )
        {
          v22.pTable = (SQTable *)itr._unVal;
          --*(_DWORD *)(itr._unVal.nInteger + 4);
          if ( *(int *)(v22.nInteger + 4) <= 0 )
            itr._unVal.pTable->Release(this: (struct SQTable *)itr._unVal.nInteger);
        }
        return 0;
      }
      v21 = SQObjectPtr::operator=(this: o2, obj: &itr);
      SQObjectPtr::operator=(this: o4, obj: v21);
      if ( itr._type == OT_NULL )
      {
        *jump = exitpos;
        SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&itr);
        return 1;
      }
      if ( SQVM::Get(this, self: o1, key: &itr, dest: o3, raw: false, fetchroot: false) )
      {
        *jump = 1;
        SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&itr);
        return 1;
      }
      SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D210, s: v25);
      SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&itr);
    }
    return 0;
  }
  if ( o1->_type == OT_CLASS )
  {
    v18 = SQClass::Next(outkey: o2, outval: o3, this: o1->_unVal.pClass, refpos: o4);
    if ( v18 == -1 )
      goto LABEL_7;
    if ( (o4->_type & 0x8000000) != 0 )
    {
      v19.pTable = (SQTable *)o4->_unVal;
      if ( (int)--*(_DWORD *)(v19.nInteger + 4) <= 0 )
        o4->_unVal.pTable->Release(this: (struct SQTable *)o4->_unVal.nInteger);
    }
    o4->_unVal.nInteger = v18;
    o4->_type = OT_INTEGER;
    *jump = 1;
    return 1;
  }
  else if ( type == OT_STRING )
  {
    v16 = SQString::Next(refpos: o4, outkey: o2, this: o1->_unVal.pString, outval: o3);
    if ( v16 == -1 )
    {
      *jump = exitpos;
    }
    else
    {
      SQObjectPtr::operator=(this: v17, a2: o4, i: v16);
      *jump = 1;
    }
    return 1;
  }
  else
  {
    if ( type != OT_ARRAY )
    {
      if ( type == OT_GENERATOR )
      {
        v11 = *(_DWORD *)(o1->_unVal.nInteger + 116);
        if ( v11 == 2 )
        {
LABEL_7:
          *jump = exitpos;
          return 1;
        }
        if ( v11 == 1 )
        {
          idx = nullptr;
          if ( o4->_type == OT_INTEGER )
            idx = (SQObjectPtr *)(o4->_unVal.nInteger + 1);
          SQObjectPtr::operator=(this: idx, a2: o2, i: (int)idx);
          SQObjectPtr::operator=(this: v13, a2: o4, i: (int)idx);
          SQGenerator::Resume((SQGenerator *)this, v: o1->_unVal.pThread, target: (int)this, targeta: arg_2 + 1);
          *jump = 0;
          return 1;
        }
      }
LABEL_26:
      v20 = IdType2Name(type);
      SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D210._vargsstack._size, s: v20);
      return 0;
    }
    v14 = SQArray::Next(refpos: o4, outval: o3, this: o1->_unVal.pArray, outkey: o2);
    if ( v14 == -1 )
      goto LABEL_7;
    SQObjectPtr::operator=(this: v15, a2: o4, i: v14);
    *jump = 1;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057AF0
// Name: public: bool SQVM::DELEGATE_OP(struct SQObjectPtr __near &,struct SQObjectPtr __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQVM::DELEGATE_OP(SQObjectPtr *o2, SQVM *this, SQObjectPtr *trg, SQObjectPtr *o1)
{
  SQObjectPtr *v4; // esi
  const char *v5; // eax
  tagSQObjectType type; // eax
  const char *v8; // eax
  tagSQObjectValue v9; // edi
  int v10; // eax
  _DWORD *v11; // ecx
  tagSQObjectType v12; // edx
  tagSQObjectType v13; // eax
  const char *v14; // [esp+0h] [ebp-Ch]

  v4 = o1;
  if ( o1->_type != OT_TABLE )
  {
    v5 = IdType2Name(type: o1->_type);
    SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D210._roottable._unVal, s: v5);
    return 0;
  }
  type = o2->_type;
  if ( o2->_type == OT_NULL )
  {
    v9.pTable = (SQTable *)o1->_unVal;
    if ( v9.nInteger != 0 )
    {
      v10 = *(_DWORD *)(v9.nInteger + 24);
      if ( v10 != 0 )
      {
        if ( (int)--*(_DWORD *)(v10 + 4) <= 0 )
          (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v9.nInteger + 24) + 8))(a1: *(_DWORD *)(v9.nInteger + 24));
        *(_DWORD *)(v9.nInteger + 24) = 0;
      }
      *(_DWORD *)(v9.nInteger + 24) = 0;
    }
  }
  else
  {
    if ( type != OT_TABLE )
    {
      v8 = IdType2Name(type);
      SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D210._alloccallsstacksize, s: v8);
      return 0;
    }
    if ( SQDelegable::SetDelegate(this: o1->_unVal.pTable, mt: o2->_unVal.pTable) == 0 )
    {
      SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D210._debughook, s: v14);
      return 0;
    }
    v4 = o1;
  }
  v11 = &trg->_unVal.pTable->__vftable;
  v12 = trg->_type;
  trg->_unVal.nInteger = v4->_unVal.nInteger;
  v13 = v4->_type;
  trg->_type = v4->_type;
  if ( (v13 & 0x8000000) != 0 )
    ++*(_DWORD *)(trg->_unVal.nInteger + 4);
  if ( (v12 & 0x8000000) != 0 && (int)--v11[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10057BF0
// Name: public: bool SQVM::CLOSURE_OP(struct SQObjectPtr __near &,struct SQFunctionProto __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQVM::CLOSURE_OP(SQVM *this, SQVM *target, SQObjectPtr *func, SQFunctionProto *funca)
{
  SQSharedState *sharedstate; // esi
  SQClosure *v5; // eax
  int v6; // ebx
  int noutervalues; // edi
  _DWORD *v8; // esi
  void *v9; // eax
  sqvector<SQObjectPtr> *v10; // ecx
  SQOuterVar *v11; // edi
  sqvector<SQObjectPtr> *v12; // ecx
  SQString *v13; // esi
  sqvector<SQObjectPtr> *v15; // ecx
  int ndefaultparams; // edi
  void *v17; // eax
  int v18; // edx
  SQObjectPtr *v19; // edi
  unsigned int v20; // eax
  int v21; // esi
  void *v22; // eax
  int v23; // ecx
  tagSQObjectType *v24; // eax
  bool v25; // zf
  tagSQObjectValue v26; // ecx
  tagSQObjectType type; // edx
  _DWORD *v28; // ecx
  int nouters; // [esp+10h] [ebp-Ch]
  int noutersa; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int ia; // [esp+14h] [ebp-8h]
  int v33; // [esp+18h] [ebp-4h]

  sharedstate = target->_sharedstate;
  v5 = (SQClosure *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 64);
  v6 = (int)v5;
  if ( v5 != nullptr )
    SQClosure::SQClosure(this: v5, func: funca, ss: sharedstate);
  noutervalues = funca->_noutervalues;
  nouters = noutervalues;
  if ( noutervalues == 0
    || (v8 = (_DWORD *)(v6 + 40),
        v9 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(v6 + 40), a3: 8 * noutervalues),
        v10 = (sqvector<SQObjectPtr> *)noutervalues,
        *(_DWORD *)(v6 + 40) = v9,
        *(_DWORD *)(v6 + 48) = noutervalues,
        i = 0,
        noutervalues <= 0) )
  {
LABEL_16:
    ndefaultparams = funca->_ndefaultparams;
    noutersa = ndefaultparams;
    if ( ndefaultparams != 0 )
    {
      v17 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(v6 + 52), a3: 8 * ndefaultparams);
      v18 = 0;
      *(_DWORD *)(v6 + 52) = v17;
      *(_DWORD *)(v6 + 60) = ndefaultparams;
      ia = 0;
      if ( ndefaultparams > 0 )
      {
        do
        {
          v19 = &target->_stack._vals[target->_stackbase + funca->_defaultparams[v18]];
          v20 = *(_DWORD *)(v6 + 56);
          if ( *(_DWORD *)(v6 + 60) <= v20 )
          {
            v21 = 2 * v20;
            if ( 2 * v20 == 0 )
              v21 = 4;
            v22 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(v6 + 52), a3: 8 * v21);
            v18 = ia;
            *(_DWORD *)(v6 + 52) = v22;
            *(_DWORD *)(v6 + 60) = v21;
          }
          v23 = *(_DWORD *)(v6 + 56);
          v24 = (tagSQObjectType *)(*(_DWORD *)(v6 + 52) + 8 * v23);
          *(_DWORD *)(v6 + 56) = v23 + 1;
          if ( v24 != nullptr )
          {
            *v24 = v19->_type;
            v25 = (*v24 & 0x8000000) == 0;
            v26.pTable = (SQTable *)v19->_unVal;
            v24[1] = (tagSQObjectType)v26.pTable;
            if ( !v25 )
              ++*(_DWORD *)(v26.nInteger + 4);
          }
          ia = ++v18;
        }
        while ( v18 < noutersa );
      }
    }
    ++*(_DWORD *)(v6 + 4);
    type = func->_type;
    v28 = &func->_unVal.pTable->__vftable;
    func->_unVal.nInteger = v6;
    func->_type = OT_CLOSURE;
    ++*(_DWORD *)(v6 + 4);
    if ( (type & 0x8000000) != 0 && (int)--v28[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v28 + 8))(a1: v28);
    if ( (int)--*(_DWORD *)(v6 + 4) <= 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    return 1;
  }
  v33 = 0;
  while ( 1 )
  {
    v11 = &funca->_outervalues[v33];
    if ( v11->_type == otLOCAL )
    {
      v15 = (sqvector<SQObjectPtr> *)(target->_stackbase + v11->_src._unVal.nInteger);
      sqvector<SQObjectPtr>::push_back(this: v15, a2: (int)v8, val: &target->_stack._vals[(_DWORD)v15]);
      goto LABEL_15;
    }
    if ( v11->_type != otSYMBOL )
    {
      if ( v11->_type == otOUTER )
      {
        v12 = *(sqvector<SQObjectPtr> **)(target->ci->_closure._unVal.nInteger + 40);
        sqvector<SQObjectPtr>::push_back(
          this: v12,
          a2: (int)v8,
          val: (const SQObjectPtr *)v12 + v11->_src._unVal.nInteger);
      }
      goto LABEL_15;
    }
    sqvector<SQObjectPtr>::push_back(this: v10, a2: (int)v8, val: &_null_);
    if ( !SQVM::Get(
            this: target,
            self: &target->_stack._vals[target->_stackbase],
            key: &v11->_src,
            dest: (SQObjectPtr *)(*v8 + 8 * *(_DWORD *)(v6 + 44) - 8),
            raw: false,
            fetchroot: true) )
      break;
LABEL_15:
    ++v33;
    if ( ++i >= nouters )
      goto LABEL_16;
  }
  v13 = SQVM::PrintObjVal(this: (SQVM *)v10, o: target, oa: &v11->_src);
  ++v13->_uiRef;
  SQVM::Raise_Error(a1: target, this: (SQVM *)&stru_1009C8A0, s: v13->_val);
  if ( --v13->_uiRef <= 0 )
    v13->Release(this: v13);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10057E60
// Name: public: bool SQVM::GETVARGV_OP(struct SQObjectPtr __near &,struct SQObjectPtr __near &,struct SQVM::CallInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::GETVARGV_OP@<al>(
        SQObjectPtr *index@<edx>,
        SQVM::CallInfo *ci@<eax>,
        SQVM *this,
        SQObjectPtr *target)
{
  tagSQObjectValue v5; // ecx
  tagSQObjectType type; // eax
  const char *v8; // eax
  tagSQObjectValue v9; // eax
  const char *v10; // [esp+0h] [ebp-8h]

  v5.nInteger = ci->_vargs.size;
  if ( LOWORD(v5.fFloat) != 0 )
  {
    type = index->_type;
    if ( (index->_type & 0x4000000) != 0 )
    {
      if ( type == OT_FLOAT )
        v9.nInteger = (int)index->_unVal.fFloat;
      else
        v9.pTable = (SQTable *)index->_unVal;
      if ( v9.nInteger < 0 || v9.nInteger >= v5.nInteger )
      {
        SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D2D8, s: v10);
        return 0;
      }
      else
      {
        SQObjectPtr::operator=(this: target, obj: &this->_vargsstack._vals[v9.nInteger + ci->_vargs.base]);
        return 1;
      }
    }
    else
    {
      v8 = IdType2Name(type);
      SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D210._suspend_varargs, s: v8);
      return 0;
    }
  }
  else
  {
    SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D210._etraps._allocated, s: v10);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057F00
// Name: public: bool SQVM::CLASS_OP(struct SQObjectPtr __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::CLASS_OP@<al>(int baseclass@<eax>, int attributes@<edx>, SQVM *this, SQClass *target)
{
  SQObjectPtr *v6; // ecx
  const char *v7; // eax
  SQObjectPtr *vals; // ecx
  int v10; // eax
  tagSQObjectValue v11; // edx
  tagSQObjectType type; // eax
  SQClass *v13; // eax
  _DWORD *v14; // edi
  tagSQObjectType v15; // eax
  _DWORD *uiRef; // ecx
  SQObjectPtr *v17; // ecx
  int top; // eax
  tagSQObjectValue v19; // edx
  SQClass_vtbl **v20; // eax
  SQClass_vtbl *v21; // ecx
  SQClass_vtbl *v22; // edi
  tagSQObjectType v23; // edx
  int v24; // eax
  tagSQObjectType v25; // edi
  int v26; // ecx
  SQObjectPtr *v27; // eax
  tagSQObjectValue v28; // edx
  _DWORD *v29; // ecx
  tagSQObjectValue v30; // eax
  tagSQObjectValue v31; // eax
  int v32; // edx
  _DWORD *v33; // esi
  _DWORD *v34; // ecx
  int v35; // edi
  SQObjectPtr ret; // [esp+10h] [ebp-10h] BYREF
  SQObjectPtr attrs; // [esp+18h] [ebp-8h]
  SQSharedState *thisa; // [esp+28h] [ebp+8h]
  SQClass *base; // [esp+2Ch] [ebp+Ch]
  tagSQObjectType basea; // [esp+2Ch] [ebp+Ch]

  base = nullptr;
  attrs._type = OT_NULL;
  attrs._unVal.nInteger = 0;
  if ( baseclass != -1 )
  {
    v6 = &this->_stack._vals[baseclass + this->_stackbase];
    if ( v6->_type != OT_CLASS )
    {
      v7 = IdType2Name(type: v6->_type);
      SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D2D8._qs_fn, s: v7);
      return 0;
    }
    base = v6->_unVal.pClass;
  }
  if ( attributes != 255 )
  {
    vals = this->_stack._vals;
    v10 = attributes + this->_stackbase;
    v11.pTable = (SQTable *)vals[v10]._unVal;
    type = vals[v10]._type;
    attrs._unVal = v11;
    attrs._type = type;
    if ( (type & 0x8000000) != 0 )
      ++*(_DWORD *)(v11.nInteger + 4);
  }
  thisa = this->_sharedstate;
  v13 = (SQClass *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 92);
  v14 = &v13->__vftable;
  if ( v13 != nullptr )
    SQClass::SQClass(this: base, ss: v13, base: thisa, basea: base);
  ++v14[1];
  v15 = (tagSQObjectType)target->__vftable;
  uiRef = (_DWORD *)target->_uiRef;
  target->_uiRef = (int)v14;
  target->__vftable = (SQClass_vtbl *)134234112;
  ++v14[1];
  if ( (v15 & 0x8000000) != 0 && (int)--uiRef[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*uiRef + 8))(a1: uiRef);
  if ( (int)--v14[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
  if ( *(_DWORD *)(*(_DWORD *)(target->_uiRef + 56) + 136) == 16777217 )
  {
    v25 = attrs._type;
  }
  else
  {
    v17 = this->_stack._vals;
    ret._type = OT_NULL;
    top = this->_top;
    this->_top = top + 1;
    v19.pTable = (SQTable *)target->_uiRef;
    v20 = (SQClass_vtbl **)&v17[top];
    ret._unVal.nInteger = 0;
    v21 = v20[1];
    v22 = *v20;
    v20[1] = (SQClass_vtbl *)v19.nInteger;
    v23 = (tagSQObjectType)target->__vftable;
    *v20 = target->__vftable;
    if ( (v23 & 0x8000000) != 0 )
      ++v20[1]->Iterate;
    if ( ((unsigned int)v22 & 0x8000000) != 0 && (int)--v21->Iterate <= 0 )
      (*((void (__thiscall **)(SQClass_vtbl *))v21->dtr_SQRefCounted + 2))(a1: v21);
    v24 = this->_top;
    v25 = attrs._type;
    v26 = v24 + 1;
    v27 = &this->_stack._vals[v24];
    v28.pTable = (SQTable *)attrs._unVal;
    this->_top = v26;
    basea = v27->_type;
    v29 = &v27->_unVal.pTable->__vftable;
    v27->_unVal = v28;
    v27->_type = v25;
    if ( (v25 & 0x8000000) != 0 )
      ++*(_DWORD *)(v28.nInteger + 4);
    if ( (basea & 0x8000000) != 0 && (int)--v29[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v29 + 8))(a1: v29);
    SQVM::Call(
      this,
      closure: (SQObjectPtr *)(*(_DWORD *)(target->_uiRef + 56) + 136),
      nparams: 2,
      stackbase: this->_top - 2,
      outres: &ret,
      raiseerror: 0);
    SQVM::Pop(this, n: 2);
    if ( (ret._type & 0x8000000) != 0 )
    {
      v30.pTable = (SQTable *)ret._unVal;
      --*(_DWORD *)(ret._unVal.nInteger + 4);
      if ( *(int *)(v30.nInteger + 4) <= 0 )
        ret._unVal.pTable->Release(this: (struct SQTable *)ret._unVal.nInteger);
    }
  }
  v31.pTable = (SQTable *)target->_uiRef;
  v32 = *(_DWORD *)(v31.nInteger + 68);
  v33 = &attrs._unVal.pTable->__vftable;
  v34 = *(_DWORD **)(v31.nInteger + 72);
  *(_DWORD *)(v31.nInteger + 68) = v25;
  v35 = v25 & 0x8000000;
  *(_DWORD *)(v31.nInteger + 72) = v33;
  if ( v35 != 0 )
    ++v33[1];
  if ( (v32 & 0x8000000) != 0 && (int)--v34[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v34 + 8))(a1: v34);
  if ( v35 != 0 && (int)--v33[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v33 + 8))(a1: v33);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10058150
// Name: public: bool SQVM::IsEqual(struct SQObjectPtr __near &,struct SQObjectPtr __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge SQVM::IsEqual@<al>(SQObjectPtr *o1@<ecx>, SQObjectPtr *o2@<eax>, SQVM *this, bool *res)
{
  bool *v4; // ebx
  bool result; // al

  v4 = res;
  if ( o1->_type == o2->_type )
  {
    *res = o1->_unVal.nInteger == o2->_unVal.nInteger;
    return true;
  }
  else if ( (o1->_type & 0x4000000) != 0 && (o2->_type & 0x4000000) != 0 )
  {
    result = SQVM::ObjCmp(o1, o2, this, result: (tagSQObjectValue *)&res);
    if ( result )
    {
      *v4 = res == nullptr;
      return true;
    }
  }
  else
  {
    *res = false;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100581D0
// Name: public: bool SQVM::GETPARENT_OP(struct SQObjectPtr __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __fastcall SQVM::GETPARENT_OP(SQObjectPtr *o, SQObjectPtr *target, SQVM *this)
{
  tagSQObjectType type; // eax
  const char *v4; // eax
  _DWORD *v6; // esi
  char v7; // bl
  _DWORD *v8; // ecx
  bool v9; // zf
  char v10; // bl
  _DWORD *v11; // ecx
  tagSQObjectType thisa; // [esp+24h] [ebp+8h]
  tagSQObjectType thisb; // [esp+24h] [ebp+8h]
  SQObjectPtr v16; // 0:^18.8

  type = o->_type;
  if ( o->_type == OT_CLASS )
  {
    v6 = *(_DWORD **)(o->_unVal.nInteger + 28);
    if ( v6 != nullptr )
    {
      ++v6[1];
      v10 = 4;
      v16._type = OT_CLASS;
      v16._unVal.nInteger = (int)v6;
    }
    else
    {
      v10 = 8;
      v16 = _null_;
      if ( (_null_._type & 0x8000000) != 0 )
        ++*(_DWORD *)(_null_._unVal.nInteger + 4);
      v6 = &v16._unVal.pTable->__vftable;
    }
    thisb = target->_type;
    v11 = &target->_unVal.pTable->__vftable;
    *target = v16;
    if ( (v16._type & 0x8000000) != 0 )
      ++*(_DWORD *)(v16._unVal.nInteger + 4);
    if ( (thisb & 0x8000000) != 0 && (int)--v11[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
    if ( (v10 & 8) != 0 )
    {
      v10 &= ~8u;
      if ( (v16._type & 0x8000000) != 0 && (int)--*(_DWORD *)(v16._unVal.nInteger + 4) <= 0 )
        v16._unVal.pTable->Release(this: (struct SQTable *)v16._unVal.nInteger);
    }
    v9 = (v10 & 4) == 0;
  }
  else
  {
    if ( type != OT_TABLE )
    {
      v4 = IdType2Name(type);
      SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D2D8._top, s: v4);
      return 0;
    }
    v6 = *(_DWORD **)(o->_unVal.nInteger + 24);
    if ( v6 != nullptr )
    {
      v7 = 1;
      ++v6[1];
      v16._type = OT_TABLE;
      v16._unVal.nInteger = (int)v6;
    }
    else
    {
      v7 = 2;
      v16 = _null_;
      if ( (_null_._type & 0x8000000) != 0 )
        ++*(_DWORD *)(_null_._unVal.nInteger + 4);
      v6 = &v16._unVal.pTable->__vftable;
    }
    thisa = target->_type;
    v8 = &target->_unVal.pTable->__vftable;
    *target = v16;
    if ( (v16._type & 0x8000000) != 0 )
      ++*(_DWORD *)(v16._unVal.nInteger + 4);
    if ( (thisa & 0x8000000) != 0 && (int)--v8[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
    if ( (v7 & 2) != 0 )
    {
      v7 &= ~2u;
      if ( (v16._type & 0x8000000) != 0 && (int)--*(_DWORD *)(v16._unVal.nInteger + 4) <= 0 )
        v16._unVal.pTable->Release(this: (struct SQTable *)v16._unVal.nInteger);
    }
    v9 = (v7 & 1) == 0;
  }
  if ( !v9 && (v16._type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10058390
// Name: public: bool SQVM::Execute(struct SQObjectPtr __near &,int,int,int,struct SQObjectPtr __near &,unsigned int,enum SQVM::ExecutionType)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::Execute@<al>(
        SQObjectPtr *closure@<eax>,
        SQVM::ExecutionType et@<edx>,
        SQVM *this,
        SQGenerator *target,
        sqvector<SQObjectPtr> *nargs,
        int stackbase,
        SQObjectPtr *outres,
        unsigned int raiseerror)
{
  SQVM *v8; // ebx
  int v9; // ecx
  SQVM *v11; // ecx
  SQVM *v12; // esi
  SQGenerator *v13; // ecx
  SQVM::CallInfo *ci; // ecx
  SQVM::CallInfo *v15; // eax
  int v16; // esi
  unsigned int v17; // eax
  SQVM *v18; // ecx
  SQVM::CallInfo *v19; // eax
  SQObjectPtr *literals; // edx
  int v21; // eax
  tagSQObjectValue v22; // edi
  SQObjectPtr *v23; // edx
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // esi
  SQObjectPtr *v26; // eax
  _DWORD *v27; // ecx
  tagSQObjectType v28; // edx
  SQVM *v29; // edi
  SQObjectPtr *v30; // esi
  tagSQObjectValue v31; // eax
  int v32; // eax
  SQVM *v33; // xmm0_4
  SQObjectPtr *v34; // ecx
  SQObjectPtr *v35; // esi
  tagSQObjectValue v36; // eax
  SQObjectPtr *v37; // eax
  tagSQObjectValue v38; // edi
  int *v39; // edx
  int *v40; // eax
  _DWORD *v41; // ecx
  int v42; // edx
  int v43; // ecx
  SQObjectPtr *v44; // eax
  tagSQObjectValue v45; // edi
  SQObjectPtr *v46; // edx
  int v47; // ecx
  SQObjectPtr *v48; // eax
  tagSQObjectType v49; // esi
  SQObjectPtr *v50; // eax
  tagSQObjectType v51; // edx
  int v52; // ecx
  SQObjectPtr *v53; // edx
  tagSQObjectValue v54; // edi
  tagSQObjectType *p_type; // eax
  _DWORD *v56; // ecx
  tagSQObjectType v57; // edx
  tagSQObjectType v58; // eax
  int v59; // ecx
  SQVM::VarArgs *p_vargs; // eax
  int v61; // edi
  int v62; // ecx
  SQObjectPtr *v63; // eax
  int *v64; // edx
  int *v65; // eax
  int v66; // ecx
  int v67; // edx
  int *v68; // ecx
  int v69; // ecx
  int v70; // eax
  SQObjectPtr *v71; // ecx
  int v72; // edx
  tagSQObjectValue v73; // edi
  tagSQObjectType *v74; // eax
  _DWORD *v75; // ecx
  tagSQObjectType v76; // eax
  tagSQObjectType v77; // edx
  tagSQObjectType v78; // eax
  SQClosure *pClosure; // edx
  int *pTable; // edi
  int v81; // eax
  tagSQObjectType v82; // edx
  _DWORD *v83; // ecx
  int v84; // eax
  _DWORD *v85; // ecx
  tagSQObjectValue v86; // eax
  _DWORD *v87; // ecx
  tagSQObjectType v88; // edx
  int *v89; // ecx
  bool v90; // zf
  tagSQObjectValue v91; // eax
  SQString_vtbl **v92; // ecx
  int v93; // edx
  int *v94; // ecx
  SQClosure *v95; // edi
  SQGenerator *v96; // ecx
  SQVM *v97; // esi
  int v98; // edi
  SQObjectPtr *v99; // eax
  int v100; // edx
  const char *v101; // eax
  int top; // eax
  SQObjectPtr *v103; // ecx
  tagSQObjectType v104; // edi
  tagSQObjectType *v105; // eax
  _DWORD *v106; // ecx
  int v107; // ecx
  SQObjectPtr *v108; // eax
  int v109; // edx
  int nInteger; // edi
  int p_unVal; // ecx
  tagSQObjectType v112; // edi
  int *v113; // ecx
  int v114; // edx
  SQObjectPtr *v115; // ecx
  int v116; // eax
  tagSQObjectType v117; // edx
  SQObjectPtr *v118; // eax
  tagSQObjectValue v119; // eax
  int v120; // edx
  SQObjectPtr *v121; // eax
  SQObjectPtr *v122; // ecx
  const SQObjectPtr *v123; // eax
  bool v124; // al
  SQVM *v125; // ecx
  SQObjectPtr *v126; // edx
  SQString *v127; // eax
  SQString *v128; // esi
  SQString_vtbl *v129; // edx
  int *v130; // eax
  tagSQObjectValue v131; // ecx
  tagSQObjectType v132; // edx
  int *v133; // ecx
  SQObjectPtr *v134; // eax
  tagSQObjectType v135; // edx
  SQObjectPtr *p_temp_reg; // edi
  SQVM *v137; // edx
  int v138; // esi
  unsigned __int8 v139; // al
  unsigned __int8 v140; // cl
  SQVM *v141; // ecx
  bool v142; // al
  SQObjectPtr *v143; // edx
  SQVM *v144; // ecx
  SQObjectPtr *v145; // eax
  SQObjectPtr *v146; // edx
  int v147; // ecx
  SQObjectPtr *v148; // eax
  tagSQObjectValue v149; // edi
  tagSQObjectType v150; // esi
  SQObjectPtr *v151; // eax
  tagSQObjectType v152; // edx
  SQObjectPtr *v153; // eax
  SQObjectPtr *v154; // edx
  int v155; // ecx
  SQObjectPtr *v156; // eax
  tagSQObjectValue v157; // edi
  tagSQObjectType v158; // esi
  SQObjectPtr *v159; // eax
  tagSQObjectType v160; // edx
  int v161; // ecx
  tagSQObjectValue v162; // esi
  SQObjectPtr *v163; // eax
  tagSQObjectType v164; // edx
  tagSQObjectType v165; // edi
  bool v166; // zf
  SQGenerator *v167; // ecx
  _DWORD *v168; // eax
  SQObjectPtr *v169; // eax
  _DWORD *v170; // ecx
  tagSQObjectType v171; // esi
  tagSQObjectType v172; // edx
  int i; // edi
  SQObjectPtr *v174; // eax
  int v175; // edx
  int v176; // ecx
  tagSQObjectType *v177; // eax
  _DWORD *v178; // ecx
  tagSQObjectType v179; // edx
  tagSQObjectType v180; // esi
  tagSQObjectValue v181; // eax
  SQObjectPtr *v182; // edx
  int v183; // eax
  SQObjectPtr *v184; // ecx
  tagSQObjectValue v185; // edi
  tagSQObjectType v186; // esi
  SQObjectPtr *v187; // eax
  tagSQObjectType v188; // edx
  int v189; // eax
  SQObjectPtr *v190; // ecx
  int v191; // edx
  int *v192; // eax
  tagSQObjectValue v193; // edi
  int *v194; // edx
  _DWORD *v195; // ecx
  int v196; // edx
  int v197; // eax
  SQObjectPtr *v198; // ecx
  char *v199; // edx
  tagSQObjectValue v200; // edi
  SQObjectPtr *v201; // eax
  SQObjectPtr *v202; // edx
  tagSQObjectType v203; // edx
  int v204; // ecx
  int v205; // ecx
  int (__cdecl *qs_fn)(SQVM *); // eax
  int v208; // eax
  int v209; // edx
  SQVM::CallInfo *v210; // eax
  int v211; // edx
  int v212; // eax
  tagSQObjectValue v213; // edi
  tagSQObjectType *v214; // edx
  SQObjectPtr *v215; // ecx
  tagSQObjectType v216; // esi
  SQObjectPtr *v217; // eax
  tagSQObjectType v218; // edx
  tagSQObjectValue v219; // edi
  SQObjectPtr *v220; // esi
  tagSQObjectValue v221; // eax
  SQSharedState *v222; // edx
  SQTable *v223; // edi
  int v224; // eax
  SQObjectPtr *v225; // ecx
  tagSQObjectType v226; // esi
  SQObjectPtr *v227; // eax
  _DWORD *v228; // ecx
  SQArray *v229; // edi
  int v230; // edx
  SQObjectPtr *v231; // eax
  _DWORD *v232; // ecx
  SQObjectPtr *v233; // eax
  tagSQObjectType v234; // edx
  int v235; // ecx
  int v236; // esi
  tagSQObjectValue v237; // edi
  int v238; // eax
  tagSQObjectValue v239; // edx
  sqvector<SQObjectPtr> *v240; // ecx
  int v241; // ecx
  int v242; // ecx
  SQObjectPtr *v243; // edx
  SQObjectPtr *v244; // edi
  int v245; // eax
  const char *v246; // ecx
  tagSQObjectType *v247; // eax
  tagSQObjectValue v248; // esi
  tagSQObjectType v249; // edx
  tagSQObjectType v250; // eax
  bool v251; // zf
  tagSQObjectValue v252; // ecx
  char v253; // al
  int v254; // eax
  int v255; // edx
  SQObjectPtr *v256; // ecx
  SQObjectPtr *v257; // edi
  SQObjectPtr *v258; // esi
  tagSQObjectValue v259; // edx
  tagSQObjectType v260; // eax
  tagSQObjectType v261; // esi
  tagSQObjectValue v262; // ecx
  int v263; // eax
  int v264; // esi
  int v265; // edx
  SQObjectPtr *v266; // ecx
  bool v267; // al
  SQObjectPtr *v268; // edx
  int v269; // ecx
  SQObjectPtr *v270; // eax
  tagSQObjectValue v271; // edi
  tagSQObjectType v272; // esi
  SQObjectPtr *v273; // eax
  tagSQObjectType v274; // edx
  int v275; // ecx
  SQObjectPtr *v276; // edx
  int v277; // eax
  tagSQObjectType v278; // edi
  int v279; // eax
  SQObjectPtr *v280; // eax
  int v281; // eax
  const SQObjectPtr *v282; // eax
  const char *v283; // eax
  int v284; // ecx
  SQObjectPtr *v285; // edi
  int v286; // edx
  tagSQObjectType v287; // eax
  SQObjectPtr *v288; // edx
  int v289; // edx
  tagSQObjectType v290; // eax
  int v291; // eax
  int v292; // ecx
  SQObjectPtr *v293; // eax
  tagSQObjectValue v294; // edi
  _DWORD *v295; // ecx
  tagSQObjectType v296; // edx
  int v297; // ecx
  SQObjectPtr *v298; // edi
  int v299; // edx
  tagSQObjectType v300; // eax
  SQObjectPtr *v301; // edx
  SQObjectPtr *v302; // edx
  int v303; // eax
  tagSQObjectType v304; // esi
  SQObjectPtr *v305; // eax
  tagSQObjectValue v306; // edi
  tagSQObjectType v307; // edx
  int v308; // ecx
  SQObjectPtr *v309; // edx
  SQObjectPtr *v310; // edi
  tagSQObjectValue v311; // edi
  SQObjectPtr *v312; // esi
  tagSQObjectValue v313; // eax
  const char *v314; // eax
  SQVM *v315; // ecx
  const char *v316; // eax
  int v317; // ecx
  SQObjectPtr *v318; // edx
  tagSQObjectType v319; // eax
  SQObjectPtr *v320; // ecx
  const char *v321; // eax
  int v322; // edx
  int v323; // edi
  SQObjectPtr *v324; // ecx
  const char *v325; // eax
  SQVM::CallInfo *v326; // ecx
  int v327; // eax
  int v328; // edx
  int v329; // ecx
  SQVM::CallInfo *v330; // eax
  int v331; // ecx
  int v332; // edx
  int v333; // ecx
  SQObjectPtr *v334; // edx
  tagSQObjectValue v335; // esi
  tagSQObjectType *v336; // eax
  _DWORD *v337; // ecx
  tagSQObjectType v338; // edx
  tagSQObjectType v339; // eax
  int v340; // edx
  SQObjectPtr *v341; // eax
  const SQObjectPtr *v342; // edx
  const SQObjectPtr *v343; // edx
  tagSQObjectType v344; // edx
  tagSQObjectType v345; // esi
  _DWORD *v346; // edi
  SQVM *v347; // ecx
  int v348; // ecx
  SQVM::CallInfo *v349; // eax
  _DWORD *v350; // eax
  SQVM::CallInfo *v351; // eax
  SQObjectPtr *v352; // ecx
  int callsstacksize; // eax
  SQExceptionTrap *v354; // eax
  int v355; // ecx
  SQVM::CallInfo *v356; // eax
  SQVM::CallInfo *v357; // eax
  SQObjectPtr *v358; // esi
  int v359; // edx
  SQSharedState *sharedstate; // ecx
  SQGenerator *v361; // ecx
  _DWORD *v362; // eax
  unsigned int allocated; // edi
  SQVM::CallInfo *v364; // eax
  int prevstkbase; // ecx
  SQVM::CallInfo *v366; // eax
  SQObjectPtr *v367; // ecx
  int v368; // eax
  SQVM::CallInfo *callsstack; // edx
  tagSQObjectType v370; // eax
  _DWORD *v371; // ecx
  int v372; // esi
  int v373; // [esp-4h] [ebp-8Ch]
  const char *v374; // [esp-4h] [ebp-8Ch]
  const char *v375; // [esp-4h] [ebp-8Ch]
  char *v376; // [esp+0h] [ebp-88h]
  SQExceptionTrap v377; // [esp+Ch] [ebp-7Ch] BYREF
  SQObjectPtr op; // [esp+1Ch] [ebp-6Ch] BYREF
  SQObjectPtr v379; // [esp+24h] [ebp-64h] BYREF
  SQObjectPtr o2; // [esp+2Ch] [ebp-5Ch] BYREF
  SQObjectPtr incr; // [esp+34h] [ebp-54h] BYREF
  SQObjectPtr val; // [esp+3Ch] [ebp-4Ch] BYREF
  SQObjectPtr obj; // [esp+44h] [ebp-44h] BYREF
  SQObjectPtr inst; // [esp+4Ch] [ebp-3Ch] BYREF
  SQObjectPtr currerror; // [esp+54h] [ebp-34h] BYREF
  SQObjectPtr clo; // [esp+5Ch] [ebp-2Ch] BYREF
  BOOL bstatic; // [esp+64h] [ebp-24h]
  int tojump; // [esp+68h] [ebp-20h] BYREF
  int nInitialSize; // [esp+6Ch] [ebp-1Ch]
  SQVM *v390; // [esp+70h] [ebp-18h]
  BOOL ct_tailcall; // [esp+74h] [ebp-14h]
  int n; // [esp+78h] [ebp-10h]
  SQObjectPtr *key; // [esp+7Ch] [ebp-Ch]
  int ct_target; // [esp+80h] [ebp-8h]
  int traps; // [esp+84h] [ebp-4h]
  int last_top; // [esp+94h] [ebp+Ch]
  int last_topa; // [esp+94h] [ebp+Ch]
  int last_topb; // [esp+94h] [ebp+Ch]
  int last_topc; // [esp+94h] [ebp+Ch]
  SQGenerator *last_topd; // [esp+94h] [ebp+Ch]
  SQObjectPtr *last_topl; // [esp+94h] [ebp+Ch]
  int last_tope; // [esp+94h] [ebp+Ch]
  int last_topf; // [esp+94h] [ebp+Ch]
  int last_topg; // [esp+94h] [ebp+Ch]
  SQSharedState *last_toph; // [esp+94h] [ebp+Ch]
  int last_topi; // [esp+94h] [ebp+Ch]
  SQObjectPtr *last_topm; // [esp+94h] [ebp+Ch]
  int last_topj; // [esp+94h] [ebp+Ch]
  int last_topk; // [esp+94h] [ebp+Ch]

  v8 = this;
  v9 = this->_nnativecalls + 1;
  if ( v9 > 100 )
  {
    SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D2D8.temp_reg, s: v376);
    return 0;
  }
  this->_nnativecalls = v9;
  traps = 0;
  ct_target = 0;
  switch ( et )
  {
    case ET_CALL:
      this = (SQVM *)this->_top;
      SQObjectPtr::operator=(this: &v8->temp_reg, obj: closure);
      if ( SQVM::StartCall(
             args: nargs,
             this: v8,
             closure: v8->temp_reg._unVal.pClosure,
             target: v8->_top - (_DWORD)nargs,
             stackbase,
             tailcall: false) == 0 )
      {
        if ( v8->ci != nullptr )
          goto LABEL_460;
        SQVM::CallErrorHandler(this: v11, error: &v8->_lasterror);
        --v8->_nnativecalls;
        return 0;
      }
      if ( *(_BYTE *)(*(_DWORD *)(v8->temp_reg._unVal.nInteger + 36) + 32) != 0 )
      {
        v12 = (SQVM *)SQGenerator::Create(ss: v8->_sharedstate, closure: v8->temp_reg._unVal.pGenerator);
        if ( SQGenerator::Yield(this: v13, v: v12, i: (int)v8) == 0 )
        {
          SQVM::Raise_Error(this: v8, desc: &v8->_lasterror);
          goto exception_trap;
        }
        SQVM::Return(this: v8, retval: &v8->temp_reg, _arg0: 1, _arg1: v8->ci->_target);
        ++v12->_uiRef;
        inst._unVal.nInteger = (int)v12;
        inst._type = OT_GENERATOR;
        SQObjectPtr::operator=(this: outres, obj: &inst);
        SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&inst);
        if ( (int)this >= v8->_top )
          SQVM::ClearStack(this: v8, last_top: (int)this);
        --v8->_nnativecalls;
        return 1;
      }
      v8->ci->_root = 1;
      break;
    case ET_RESUME_GENERATOR:
      SQGenerator::Resume(this: target, v: closure->_unVal.pThread, target: (int)this, targeta: (int)target);
      this->ci->_root = 1;
      traps = this->ci->_etraps;
      break;
    case ET_RESUME_VM:
    case ET_RESUME_THROW_VM:
      ci = this->ci;
      traps = this->_suspended_traps;
      ci->_root = this->_suspended_root;
      this->ci->_vargs = this->_suspend_varargs;
      this->_suspended = 0;
      if ( et != ET_RESUME_THROW_VM )
        break;
      goto exception_trap;
    default:
      break;
  }
exception_restore:
  while ( 2 )
  {
    v15 = v8->ci;
    v16 = (int)v15->_ip++;
    v17 = *(unsigned __int8 *)(v16 + 4);
    last_top = v16;
LABEL_17:
    switch ( v17 )
    {
      case 0u:
        if ( v8->_debughook._type != OT_NULL && v8->_debughook._unVal.nInteger != v8->ci->_closure._unVal.nInteger )
        {
          v18 = *(SQVM **)v16;
          v373 = *(_DWORD *)v16;
          g_bSqDbgTerminateScript = false;
          SQVM::CallDebugHook(this: v18, type: 108, forcedline: v373);
          if ( g_bSqDbgTerminateScript )
          {
            sq_throwerror(v: v8, err: (const char *)&stru_1009D2D8._callstackdata._size);
            goto exception_trap;
          }
        }
        v19 = v8->ci;
        v16 = (int)v19->_ip++;
        v17 = *(unsigned __int8 *)(v16 + 4);
        last_top = v16;
        if ( v17 > 0x3C )
          continue;
        goto LABEL_17;
      case 1u:
        literals = v8->ci->_literals;
        v21 = v8->_stackbase + *(unsigned __int8 *)(v16 + 5);
        v22.pTable = (SQTable *)literals[*(_DWORD *)v16]._unVal;
        v23 = &literals[*(_DWORD *)v16];
        vals = v8->_stack._vals;
        type = vals[v21]._type;
        v26 = &vals[v21];
        v27 = &v26->_unVal.pTable->__vftable;
        v26->_unVal = v22;
        v28 = v23->_type;
        v26->_type = v28;
        if ( (v28 & 0x8000000) != 0 )
          ++*(_DWORD *)(v22.nInteger + 4);
        if ( (type & 0x8000000) == 0 )
          continue;
        if ( (int)--v27[1] > 0 )
          continue;
        goto LABEL_361;
      case 2u:
        v29 = *(SQVM **)v16;
        v30 = &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)];
        if ( (v30->_type & 0x8000000) != 0 )
        {
          v31.pTable = (SQTable *)v30->_unVal;
          if ( (int)--*(_DWORD *)(v31.nInteger + 4) <= 0 )
            v30->_unVal.pTable->Release(this: (struct SQTable *)v30->_unVal.nInteger);
        }
        v30->_unVal.nInteger = (int)v29;
        v30->_type = OT_INTEGER;
        continue;
      case 3u:
        v32 = v8->_stackbase + *(unsigned __int8 *)(v16 + 5);
        v33 = *(SQVM **)v16;
        v34 = v8->_stack._vals;
        v90 = (v34[v32]._type & 0x8000000) == 0;
        v35 = &v34[v32];
        v390 = v33;
        if ( !v90 )
        {
          v36.pTable = (SQTable *)v35->_unVal;
          if ( (int)--*(_DWORD *)(v36.nInteger + 4) <= 0 )
            v35->_unVal.pTable->Release(this: (struct SQTable *)v35->_unVal.nInteger);
        }
        v35->_unVal.nInteger = (int)v390;
        v35->_type = OT_FLOAT;
        continue;
      case 4u:
        v37 = v8->ci->_literals;
        v38.pTable = (SQTable *)v37[*(_DWORD *)v16]._unVal;
        v39 = (int *)&v37[*(_DWORD *)v16];
        v40 = (int *)&v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)];
        last_topa = *v40;
        v41 = (_DWORD *)v40[1];
        v40[1] = v38.nInteger;
        v42 = *v39;
        *v40 = v42;
        if ( (v42 & 0x8000000) != 0 )
          ++*(_DWORD *)(v38.nInteger + 4);
        if ( (last_topa & 0x8000000) != 0 && (int)--v41[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v41 + 8))(a1: v41);
        v43 = *(unsigned __int8 *)(v16 + 7);
        v44 = v8->ci->_literals;
        v45.pTable = (SQTable *)v44[v43]._unVal;
        v46 = &v44[v43];
        v47 = v8->_stackbase + *(unsigned __int8 *)(v16 + 6);
        v48 = v8->_stack._vals;
        v49 = v48[v47]._type;
        v50 = &v48[v47];
        v27 = &v50->_unVal.pTable->__vftable;
        v50->_unVal = v45;
        v51 = v46->_type;
        v50->_type = v51;
        if ( (v51 & 0x8000000) != 0 )
          ++*(_DWORD *)(v45.nInteger + 4);
        if ( (v49 & 0x8000000) == 0 )
          continue;
        if ( (int)--v27[1] > 0 )
          continue;
        goto LABEL_361;
      case 5u:
        v52 = *(_DWORD *)v16 + v8->_stackbase;
        v53 = v8->_stack._vals;
        v54.pTable = (SQTable *)v53[v52]._unVal;
        p_type = &v53[v52]._type;
        v56 = &v8->temp_reg._unVal.pTable->__vftable;
        v57 = v8->temp_reg._type;
        v8->temp_reg._unVal = v54;
        v58 = *p_type;
        v8->temp_reg._type = v58;
        if ( (v58 & 0x8000000) != 0 )
          ++*(_DWORD *)(v54.nInteger + 4);
        if ( (v57 & 0x8000000) != 0 && (int)--v56[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v56 + 8))(a1: v56);
        if ( v8->temp_reg._type != OT_CLOSURE )
          goto $LN210;
        v59 = *(_DWORD *)(v8->temp_reg._unVal.nInteger + 36);
        if ( *(_BYTE *)(v59 + 32) != 0 )
          goto $LN210;
        p_vargs = &v8->ci->_vargs;
        v90 = p_vargs->size == 0;
        LOBYTE(ct_tailcall) = 1;
        if ( !v90 )
        {
          SQVM::PopVarArgs(this: (SQVM *)v59, a2: (int)v8, vargs: p_vargs);
          v16 = last_top;
        }
        v61 = 0;
        if ( *(_BYTE *)(v16 + 7) != 0 )
        {
          do
          {
            v62 = v8->_stackbase;
            v63 = v8->_stack._vals;
            v64 = (int *)&v63[v61 + v62 + *(unsigned __int8 *)(v16 + 6)];
            v65 = (int *)&v63[v61 + v62];
            last_topb = *v65;
            n = v65[1];
            v66 = v64[1];
            v65[1] = v66;
            v67 = *v64;
            *v65 = v67;
            if ( (v67 & 0x8000000) != 0 )
              ++*(_DWORD *)(v66 + 4);
            if ( (last_topb & 0x8000000) != 0 )
            {
              v68 = (int *)n;
              --*(_DWORD *)(n + 4);
              if ( v68[1] <= 0 )
                (*(void (__thiscall **)(int *))(*v68 + 8))(a1: v68);
            }
            ++v61;
          }
          while ( v61 < *(unsigned __int8 *)(v16 + 7) );
        }
        v69 = v8->_stackbase;
        ct_target = v8->ci->_target;
        last_topc = v69;
        goto common_call;
      case 6u:
$LN210:
        v70 = *(_DWORD *)v16 + v8->_stackbase;
        v71 = v8->_stack._vals;
        v72 = *(unsigned __int8 *)(v16 + 5);
        v73.pTable = (SQTable *)v71[v70]._unVal;
        v74 = &v71[v70]._type;
        v75 = &v8->temp_reg._unVal.pTable->__vftable;
        v8->temp_reg._unVal = v73;
        v76 = *v74;
        ct_target = v72;
        v77 = v8->temp_reg._type;
        LOBYTE(ct_tailcall) = 0;
        v8->temp_reg._type = v76;
        if ( (v76 & 0x8000000) != 0 )
          ++*(_DWORD *)(v73.nInteger + 4);
        if ( (v77 & 0x8000000) != 0 && (int)--v75[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v75 + 8))(a1: v75);
        last_topc = v8->_stackbase + *(unsigned __int8 *)(v16 + 6);
common_call:
        while ( 2 )
        {
          v78 = v8->temp_reg._type;
          pClosure = v8->temp_reg._unVal.pClosure;
          clo._type = v78;
          clo._unVal.nInteger = (int)pClosure;
          if ( (v78 & 0x8000000) != 0 )
          {
            ++pClosure->_uiRef;
            pClosure = clo._unVal.pClosure;
            v78 = clo._type;
          }
          n = v8->_top;
          if ( v78 > OT_TABLE )
          {
            if ( v78 != OT_USERDATA && v78 != OT_INSTANCE )
              goto LABEL_125;
          }
          else if ( v78 != OT_TABLE )
          {
            switch ( v78 )
            {
              case OT_CLOSURE:
                if ( SQVM::StartCall(
                       args: (sqvector<SQObjectPtr> *)*(unsigned __int8 *)(v16 + 7),
                       this: v8,
                       closure: pClosure,
                       target: ct_target,
                       stackbase: last_topc,
                       tailcall: ct_tailcall) == 0 )
                {
LABEL_109:
                  SQVM::Raise_Error(this: v8, desc: &v8->_lasterror);
                  v90 = (clo._type & 0x8000000) == 0;
                  goto LABEL_102;
                }
                v95 = clo._unVal.pClosure;
                if ( *(_BYTE *)(*(_DWORD *)(clo._unVal.nInteger + 36) + 32) != 0 )
                {
                  last_topd = (SQGenerator *)v8->_sharedstate;
                  v97 = (SQVM *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 120);
                  if ( v97 != nullptr )
                    SQGenerator::SQGenerator(
                      this: last_topd,
                      a2: (int)v97,
                      ss: (SQSharedState *)last_topd,
                      closure: v95);
                  if ( SQGenerator::Yield(this: v96, v: v97, i: (int)v8) == 0 )
                  {
                    SQVM::Raise_Error(this: v8, desc: &v8->_lasterror);
                    SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&clo);
                    goto exception_trap;
                  }
                  v98 = ct_target;
                  SQVM::Return(this: v8, retval: &clo, _arg0: 1, _arg1: ct_target);
                  ++v97->_uiRef;
                  v99 = v8->_stack._vals;
                  v100 = v98 + v8->_stackbase;
                  obj._unVal.nInteger = (int)v97;
                  obj._type = OT_GENERATOR;
                  SQObjectPtr::operator=(this: &v99[v100], &obj);
                  SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&obj);
                  if ( n >= v8->_top )
                    SQVM::ClearStack(this: v8, last_top: n);
                }
                break;
              case OT_NATIVECLOSURE:
                if ( !SQVM::CallNative(
                        this: (SQVM *)last_topc,
                        nclosure: (SQNativeClosure *)v8,
                        nargs: (int)pClosure,
                        stackbase: *(unsigned __int8 *)(v16 + 7),
                        retval: (SQObjectPtr *)last_topc,
                        suspend: (bool *)&clo) )
                  goto LABEL_109;
                if ( HIBYTE(this) != 0 )
                {
                  v357 = v8->ci;
                  v358 = outres;
                  v8->_suspended_target = ct_target;
                  v359 = traps;
                  v8->_suspended = 1;
                  v8->_suspended_root = v357->_root;
                  v8->_suspended_traps = v359;
                  v8->_suspend_varargs = v357->_vargs;
                  SQObjectPtr::operator=(this: v358, obj: &clo);
                  SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&clo);
                  --v8->_nnativecalls;
                  return 1;
                }
                if ( ct_target != -1 )
                  SQObjectPtr::operator=(this: &v8->_stack._vals[ct_target + v8->_stackbase], obj: &clo);
                break;
              case OT_CLASS:
                inst._type = OT_NULL;
                inst._unVal.nInteger = 0;
                if ( SQVM::CreateClassInstance(
                       this: v8,
                       theclass: (SQClass *)pClosure,
                       &inst,
                       constructor: &v8->temp_reg) )
                {
                  pTable = (int *)inst._unVal.pTable;
                  v81 = (int)&v8->_stack._vals[ct_target + v8->_stackbase];
                  v82 = inst._type;
                  key = *(SQObjectPtr **)v81;
                  v83 = *(_DWORD **)(v81 + 4);
                  *(_DWORD *)(v81 + 4) = inst._unVal.pTable;
                  *(_DWORD *)v81 = v82;
                  n = v82 & 0x8000000;
                  if ( (v82 & 0x8000000) != 0 )
                    ++pTable[1];
                  if ( ((unsigned int)key & 0x8000000) != 0 && (int)--v83[1] <= 0 )
                  {
                    (*(void (__thiscall **)(_DWORD *))(*v83 + 8))(a1: v83);
                    v82 = inst._type;
                  }
                  v90 = v8->temp_reg._type == OT_NULL;
                  ct_target = -1;
                  if ( !v90 )
                  {
                    v90 = n == 0;
                    v84 = (int)&v8->_stack._vals[last_topc];
                    key = *(SQObjectPtr **)v84;
                    v85 = *(_DWORD **)(v84 + 4);
                    *(_DWORD *)(v84 + 4) = pTable;
                    *(_DWORD *)v84 = v82;
                    if ( !v90 )
                      ++pTable[1];
                    if ( ((unsigned int)key & 0x8000000) != 0 && (int)--v85[1] <= 0 )
                      (*(void (__thiscall **)(_DWORD *))(*v85 + 8))(a1: v85);
                    if ( n != 0 && --pTable[1] <= 0 )
                      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
                    if ( (clo._type & 0x8000000) != 0 )
                    {
                      v86.pTable = (SQTable *)clo._unVal;
                      --*(_DWORD *)(clo._unVal.nInteger + 4);
                      if ( *(int *)(v86.nInteger + 4) <= 0 )
                        clo._unVal.pTable->Release(this: (struct SQTable *)clo._unVal.nInteger);
                    }
                    continue;
                  }
                  if ( (v82 & 0x8000000) != 0 && --pTable[1] <= 0 )
                  {
                    v93 = *pTable;
                    v94 = pTable;
LABEL_145:
                    (*(void (__fastcall **)(int *))(v93 + 8))(a1: v94);
                    goto LABEL_146;
                  }
                  goto LABEL_146;
                }
                v87 = &v8->_lasterror._unVal.pTable->__vftable;
                v88 = v8->_lasterror._type;
                v8->_lasterror._unVal.nInteger = (int)v87;
                v8->_lasterror._type = v88;
                if ( (v88 & 0x8000000) != 0 )
                {
                  ++v87[1];
                  if ( (int)--v87[1] <= 0 )
                    (*(void (__thiscall **)(_DWORD *))(*v87 + 8))(a1: v87);
                }
                if ( (inst._type & 0x8000000) != 0 )
                {
                  v89 = (int *)inst._unVal.pTable;
                  --*(_DWORD *)(inst._unVal.nInteger + 4);
                  if ( v89[1] <= 0 )
                    (*(void (__thiscall **)(int *))(*v89 + 8))(a1: v89);
                }
                v90 = (clo._type & 0x8000000) == 0;
LABEL_102:
                if ( !v90 )
                {
                  v91.pTable = (SQTable *)clo._unVal;
                  --*(_DWORD *)(clo._unVal.nInteger + 4);
                  if ( *(int *)(v91.nInteger + 4) <= 0 )
                  {
                    v92 = (SQString_vtbl **)clo._unVal.pTable;
LABEL_414:
                    v129 = *v92;
LABEL_415:
                    ((void (__fastcall *)(SQString_vtbl **))v129->Release)(a1: v92);
                    goto exception_trap;
                  }
                }
                goto exception_trap;
              default:
LABEL_125:
                v101 = IdType2Name(type: v78);
                SQVM::Raise_Error(a1: v8, this: (SQVM *)&stru_1009D2D8._foreignptr, s: v101);
                v90 = (clo._type & 0x8000000) == 0;
                goto LABEL_102;
            }
            SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&clo);
            goto exception_restore;
          }
          break;
        }
        top = v8->_top;
        v8->_top = top + 1;
        v103 = v8->_stack._vals;
        v104 = v103[top]._type;
        v105 = &v103[top]._type;
        v106 = *((_DWORD **)v105 + 1);
        *((_DWORD *)v105 + 1) = pClosure;
        *v105 = clo._type;
        if ( (clo._type & 0x8000000) != 0 )
          ++*(_DWORD *)(*((_DWORD *)v105 + 1) + 4);
        if ( (v104 & 0x8000000) != 0 && (int)--v106[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v106 + 8))(a1: v106);
        v107 = 0;
        n = 0;
        if ( *(_BYTE *)(v16 + 7) != 0 )
        {
          do
          {
            v108 = v8->_stack._vals;
            v109 = v8->_top;
            last_topl = &v108[v107 + v8->_stackbase + *(unsigned __int8 *)(v16 + 6)];
            v8->_top = v109 + 1;
            nInteger = v108[v109]._unVal.nInteger;
            key = (SQObjectPtr *)v108[v109]._type;
            p_unVal = (int)&v108[v109]._unVal;
            nInitialSize = nInteger;
            *(_DWORD *)p_unVal = last_topl->_unVal.pTable;
            v112 = last_topl->_type;
            v108[v109]._type = last_topl->_type;
            if ( (v112 & 0x8000000) != 0 )
              ++*(_DWORD *)(*(_DWORD *)p_unVal + 4);
            if ( ((unsigned int)key & 0x8000000) != 0 )
            {
              v113 = (int *)nInitialSize;
              --*(_DWORD *)(nInitialSize + 4);
              if ( v113[1] <= 0 )
                (*(void (__thiscall **)(int *))(*v113 + 8))(a1: v113);
            }
            v114 = *(unsigned __int8 *)(v16 + 7);
            v107 = n + 1;
            n = v107;
          }
          while ( v107 < v114 );
        }
        if ( clo._unVal.nInteger == 0
          || !SQVM::CallMetaMethod(
                this: v8,
                del: clo._unVal.pTable,
                mm: MT_CALL,
                nparams: *(unsigned __int8 *)(v16 + 7) + 1,
                outres: &clo) )
        {
          v78 = clo._type;
          goto LABEL_125;
        }
        v115 = v8->_stack._vals;
        v116 = ct_target + v8->_stackbase;
        v117 = v115[v116]._type;
        v118 = &v115[v116];
        v94 = (int *)v118->_unVal.pTable;
        *v118 = clo;
        if ( (clo._type & 0x8000000) != 0 )
          ++*(_DWORD *)(v118->_unVal.nInteger + 4);
        if ( (v117 & 0x8000000) != 0 && --v94[1] <= 0 )
        {
          v93 = *v94;
          goto LABEL_145;
        }
LABEL_146:
        if ( (clo._type & 0x8000000) != 0 )
        {
          v119.pTable = (SQTable *)clo._unVal;
          --*(_DWORD *)(clo._unVal.nInteger + 4);
          if ( *(int *)(v119.nInteger + 4) <= 0 )
            clo._unVal.pTable->Release(this: (struct SQTable *)clo._unVal.nInteger);
        }
        continue;
      case 7u:
      case 8u:
        if ( *(_BYTE *)(v16 + 4) == 8 )
        {
          v120 = *(_DWORD *)v16;
          v121 = v8->ci->_literals;
        }
        else
        {
          v120 = *(_DWORD *)v16 + v8->_stackbase;
          v121 = v8->_stack._vals;
        }
        v122 = &v121[v120];
        v123 = &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)];
        key = v122;
        n = (int)v123;
        v124 = SQVM::Get(this: v8, self: v123, key: v122, dest: &v8->temp_reg, raw: false, fetchroot: true);
        v126 = (SQObjectPtr *)n;
        if ( v124 )
        {
          if ( *(_DWORD *)n == 134234112 )
            v126 = &v8->_stack._vals[v8->_stackbase];
          v130 = (int *)&v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 7)];
          last_tope = *v130;
          nInitialSize = v130[1];
          v131.pTable = (SQTable *)v126->_unVal;
          v130[1] = v131.nInteger;
          v132 = v126->_type;
          *v130 = v132;
          if ( (v132 & 0x8000000) != 0 )
            ++*(_DWORD *)(v131.nInteger + 4);
          if ( (last_tope & 0x8000000) != 0 )
          {
            v133 = (int *)nInitialSize;
            --*(_DWORD *)(nInitialSize + 4);
            if ( v133[1] <= 0 )
              (*(void (__thiscall **)(int *))(*v133 + 8))(a1: v133);
          }
          v134 = &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)];
          v27 = &v134->_unVal.pTable->__vftable;
          v134->_unVal.nInteger = v8->temp_reg._unVal.nInteger;
          v135 = v8->temp_reg._type;
LABEL_228:
          v180 = v134->_type;
          v134->_type = v135;
          if ( (v135 & 0x8000000) != 0 )
          {
            v181.pTable = (SQTable *)v134->_unVal;
LABEL_245:
            ++*(_DWORD *)(v181.nInteger + 4);
          }
LABEL_246:
          v166 = (v180 & 0x8000000) == 0;
LABEL_247:
          if ( !v166 && (int)--v27[1] <= 0 )
LABEL_361:
            (*(void (__thiscall **)(_DWORD *))(*v27 + 8))(a1: v27);
          continue;
        }
        if ( *(_DWORD *)n == 134234112
          && SQTable::Get(key, val: &v8->temp_reg, this: v8->_sharedstate->_class_default_delegate._unVal.pTable) != 0 )
        {
          SQObjectPtr::operator=(
            this: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(last_top + 7)],
            obj: (const SQObjectPtr *)n);
          SQObjectPtr::operator=(
            this: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(last_top + 5)],
            obj: &v8->temp_reg);
          continue;
        }
        v127 = SQVM::PrintObjVal(this: v125, o: v8, oa: key);
LABEL_158:
        v128 = v127;
        v374 = v127->_val;
LABEL_159:
        ++v128->_uiRef;
        SQVM::Raise_Error(a1: v8, this: (SQVM *)&stru_1009C8A0, s: v374);
        if ( --v128->_uiRef <= 0 )
        {
          v129 = v128->__vftable;
          v92 = (SQString_vtbl **)v128;
          goto LABEL_415;
        }
exception_trap:
        v345 = v8->_lasterror._type;
        v346 = &v8->_lasterror._unVal.pTable->__vftable;
        currerror._type = v345;
        currerror._unVal.nInteger = (int)v346;
        if ( (v345 & 0x8000000) != 0 )
          ++v346[1];
        v90 = v8->ci == nullptr;
        v347 = (SQVM *)v8->_top;
        n = 0;
        last_topk = (int)v347;
        if ( v90 )
          goto LABEL_452;
        if ( v8->_sharedstate->_notifyallexceptions )
          SQVM::CallErrorHandler(this: v347, error: &currerror);
        if ( traps != 0 )
        {
          v348 = (int)v8->ci;
          if ( *(int *)(v348 + 20) <= 0 )
          {
            do
            {
              v349 = v8->ci;
              if ( v349->_closure._type != OT_CLOSURE && n != 0 )
                goto LABEL_441;
              v350 = &v349->_generator->__vftable;
              if ( v350 != nullptr )
                SQGenerator::Kill(this: (SQGenerator *)v348, a2: v350);
              SQVM::PopVarArgs(this: (SQVM *)v348, a2: (int)v8, vargs: &v8->ci->_vargs);
              v351 = v8->ci;
              --v8->_callsstacksize;
              SQObjectPtr::Null(this: v352, a2: (int *)&v351->_closure);
              callsstacksize = v8->_callsstacksize;
              if ( callsstacksize != 0 )
              {
                v348 = (int)&v8->_callsstack[callsstacksize - 1];
                v8->ci = (SQVM::CallInfo *)v348;
              }
              else
              {
                v8->ci = nullptr;
              }
              ++n;
              if ( callsstacksize == 0 )
                goto LABEL_441;
            }
            while ( v8->ci->_etraps <= 0 );
          }
          v354 = &v8->_etraps._vals[v8->_etraps._size - 1];
          v8->ci->_ip = v354->_ip;
          v8->_top = v354->_stacksize;
          v355 = v354->_stackbase;
          v8->_stackbase = v354->_stackbase;
          SQObjectPtr::operator=(this: &v8->_stack._vals[v355 + v354->_extarget], obj: &currerror);
          --v8->_etraps._size;
          v356 = v8->ci;
          --traps;
          --v356->_etraps;
          if ( last_topk >= v8->_top )
            SQVM::ClearStack(this: v8, last_top: last_topk);
          SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&currerror);
          continue;
        }
        if ( raiseerror != 0 )
        {
          sharedstate = v8->_sharedstate;
          if ( !sharedstate->_notifyallexceptions )
            SQVM::CallErrorHandler(this: (SQVM *)sharedstate, error: &currerror);
        }
LABEL_441:
        v361 = (SQGenerator *)v8->ci;
        if ( v361 != nullptr )
        {
          do
          {
            v362 = &v361->_prev->SQCollectable::__vftable;
            allocated = v361->_stack._allocated;
            if ( v362 != nullptr )
              SQGenerator::Kill(this: v361, a2: v362);
            v364 = v8->ci;
            prevstkbase = v364->_prevstkbase;
            v8->_stackbase -= prevstkbase;
            v8->_top = v8->_stackbase + v364->_prevtop;
            SQVM::PopVarArgs(this: (SQVM *)prevstkbase, a2: (int)v8, vargs: &v364->_vargs);
            v366 = v8->ci;
            --v8->_callsstacksize;
            SQObjectPtr::Null(this: v367, a2: (int *)&v366->_closure);
            v368 = v8->_callsstacksize;
            if ( v368 != 0 )
            {
              callsstack = v8->_callsstack;
              v361 = (SQGenerator *)&callsstack[v368 - 1];
              v8->ci = (SQVM::CallInfo *)v361;
              if ( &callsstack[v368] != (SQVM::CallInfo *)48 && v361->_weakref != (SQWeakRef *)134217984 )
                break;
            }
            else
            {
              v8->ci = nullptr;
              v361 = (SQGenerator *)v8->ci;
            }
          }
          while ( allocated == 0 && v368 != 0 );
        }
        if ( last_topk >= v8->_top )
          SQVM::ClearStack(this: v8, last_top: last_topk);
        v346 = &currerror._unVal.pTable->__vftable;
        v345 = currerror._type;
LABEL_452:
        v370 = v8->_lasterror._type;
        v371 = &v8->_lasterror._unVal.pTable->__vftable;
        v8->_lasterror._type = v345;
        v372 = v345 & 0x8000000;
        v8->_lasterror._unVal.nInteger = (int)v346;
        if ( v372 != 0 )
          ++v346[1];
        if ( (v370 & 0x8000000) != 0 && (int)--v371[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v371 + 8))(a1: v371);
        if ( v372 != 0 && (int)--v346[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v346 + 8))(a1: v346);
LABEL_460:
        --v8->_nnativecalls;
        return 0;
      case 9u:
        p_temp_reg = &v8->temp_reg;
        if ( SQVM::Get(
               this: v8,
               self: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
               key: &v8->ci->_literals[*(_DWORD *)v16],
               dest: &v8->temp_reg,
               raw: false,
               fetchroot: true) )
        {
          goto LABEL_204;
        }
        v128 = SQVM::PrintObjVal(this: (SQVM *)v8->ci, o: v8, oa: &v8->ci->_literals[*(_DWORD *)v16]);
        v374 = v128->_val;
        goto LABEL_159;
      case 0xAu:
        v137 = *(SQVM **)v16;
        v138 = *(unsigned __int8 *)(v16 + 5);
        goto LABEL_243;
      case 0xBu:
        if ( SQVM::NewSlot(
               this: (SQVM *)v8->_stack._vals,
               self: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
               key: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
               val: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 7)],
               bstatic: false) )
        {
          goto LABEL_173;
        }
        goto LABEL_412;
      case 0xCu:
        if ( SQVM::DeleteSlot(
               this: (SQVM *)v8->_stack._vals,
               self: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
               key: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
               res: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)]) )
        {
          continue;
        }
        goto LABEL_412;
      case 0xDu:
        if ( !SQVM::Set(
                this: v8,
                self: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
                key: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
                val: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 7)],
                fetchroot: true) )
        {
          v141 = (SQVM *)(v8->_stackbase + *(unsigned __int8 *)(v16 + 6));
          v127 = SQVM::PrintObjVal(this: v141, o: v8, oa: &v8->_stack._vals[(_DWORD)v141]);
          goto LABEL_158;
        }
LABEL_173:
        v139 = *(_BYTE *)(v16 + 7);
        v140 = *(_BYTE *)(v16 + 5);
        if ( v140 != v139 )
          SQObjectPtr::operator=(
            this: &v8->_stack._vals[v8->_stackbase + v140],
            obj: &v8->_stack._vals[v8->_stackbase + v139]);
        continue;
      case 0xEu:
        p_temp_reg = &v8->temp_reg;
        v142 = SQVM::Get(
                 this: v8,
                 self: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
                 key: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
                 dest: &v8->temp_reg,
                 raw: false,
                 fetchroot: true);
        v143 = v8->_stack._vals;
        if ( v142 )
          goto LABEL_205;
        v144 = (SQVM *)(v8->_stackbase + *(unsigned __int8 *)(v16 + 6));
        v127 = SQVM::PrintObjVal(this: v144, o: v8, oa: &v143[(_DWORD)v144]);
        goto LABEL_158;
      case 0xFu:
        if ( *(_BYTE *)(v16 + 7) != 0 )
          v145 = &v8->ci->_literals[*(_DWORD *)v16];
        else
          v145 = &v8->_stack._vals[*(_DWORD *)v16 + v8->_stackbase];
        if ( !SQVM::IsEqual(
                o1: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
                o2: v145,
                this: v8,
                res: (bool *)&stackbase + 3) )
          goto exception_trap;
        v146 = &_true_;
        if ( HIBYTE(stackbase) == 0 )
          v146 = &_false_;
        v147 = v8->_stackbase + *(unsigned __int8 *)(last_top + 5);
        v148 = v8->_stack._vals;
        v149.pTable = (SQTable *)v146->_unVal;
        v150 = v148[v147]._type;
        v151 = &v148[v147];
        v27 = &v151->_unVal.pTable->__vftable;
        v151->_unVal = v149;
        v152 = v146->_type;
        v151->_type = v152;
        if ( (v152 & 0x8000000) != 0 )
          ++*(_DWORD *)(v149.nInteger + 4);
        if ( (v150 & 0x8000000) != 0 && (int)--v27[1] <= 0 )
          goto LABEL_361;
        continue;
      case 0x10u:
        if ( *(_BYTE *)(v16 + 7) != 0 )
          v153 = &v8->ci->_literals[*(_DWORD *)v16];
        else
          v153 = &v8->_stack._vals[*(_DWORD *)v16 + v8->_stackbase];
        if ( !SQVM::IsEqual(
                o1: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
                o2: v153,
                this: v8,
                res: (bool *)&nargs + 3) )
          goto exception_trap;
        v154 = &_true_;
        if ( HIBYTE(nargs) != 0 )
          v154 = &_false_;
        v155 = v8->_stackbase + *(unsigned __int8 *)(last_top + 5);
        v156 = v8->_stack._vals;
        v157.pTable = (SQTable *)v154->_unVal;
        v158 = v156[v155]._type;
        v159 = &v156[v155];
        v27 = &v159->_unVal.pTable->__vftable;
        v159->_unVal = v157;
        v160 = v154->_type;
        v159->_type = v160;
        if ( (v160 & 0x8000000) != 0 )
          ++*(_DWORD *)(v157.nInteger + 4);
        if ( (v158 & 0x8000000) != 0 && (int)--v27[1] <= 0 )
          goto LABEL_361;
        continue;
      case 0x11u:
        p_temp_reg = &v8->temp_reg;
        if ( !SQVM::ARITH_OP(
                this: v8,
                o2: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
                op: (const char *)*(unsigned __int8 *)(v16 + 7),
                trg: &v8->temp_reg,
                o1: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)]) )
          goto LABEL_412;
LABEL_204:
        v143 = v8->_stack._vals;
LABEL_205:
        v161 = v8->_stackbase + *(unsigned __int8 *)(v16 + 5);
        v162.pTable = (SQTable *)p_temp_reg->_unVal;
        v163 = &v143[v161];
        v164 = v163->_type;
        v27 = &v163->_unVal.pTable->__vftable;
        v163->_unVal = v162;
        v165 = p_temp_reg->_type;
        v163->_type = v165;
        if ( (v165 & 0x8000000) != 0 )
          ++*(_DWORD *)(v162.nInteger + 4);
        v166 = (v164 & 0x8000000) == 0;
        goto LABEL_247;
      case 0x12u:
        if ( SQVM::BW_OP(
               o1: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
               o2: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
               this: v8,
               op: *(unsigned __int8 *)(v16 + 7),
               trg: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)]) )
        {
          continue;
        }
        goto LABEL_412;
      case 0x13u:
        v167 = (SQGenerator *)v8->ci;
        v168 = &v167->_prev->SQCollectable::__vftable;
        if ( v168 != nullptr )
          SQGenerator::Kill(this: v167, a2: v168);
        if ( !SQVM::Return(this: v8, retval: &v8->temp_reg, _arg0: *(unsigned __int8 *)(v16 + 5), _arg1: *(_DWORD *)v16) )
          goto LABEL_260;
        v169 = outres;
        v170 = &outres->_unVal.pTable->__vftable;
        v171 = outres->_type;
        outres->_unVal.nInteger = v8->temp_reg._unVal.nInteger;
        v172 = v8->temp_reg._type;
        v169->_type = v172;
        if ( (v172 & 0x8000000) != 0 )
          ++*(_DWORD *)(v169->_unVal.nInteger + 4);
        if ( (v171 & 0x8000000) != 0 && (int)--v170[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v170 + 8))(a1: v170);
        --v8->_nnativecalls;
        return 1;
      case 0x14u:
        for ( i = 0; i < *(_DWORD *)v16; ++i )
        {
          v174 = v8->_stack._vals;
          v175 = i + v8->_stackbase + *(unsigned __int8 *)(v16 + 5);
          v176 = v174[v175]._type;
          v177 = &v174[v175]._type;
          last_topf = v176;
          v178 = *((_DWORD **)v177 + 1);
          v177[1] = (tagSQObjectType)_null_._unVal.pTable;
          v179 = _null_._type;
          *v177 = _null_._type;
          if ( (v179 & 0x8000000) != 0 )
            ++*(_DWORD *)(*((_DWORD *)v177 + 1) + 4);
          if ( (last_topf & 0x8000000) != 0 && (int)--v178[1] <= 0 )
            (*(void (__thiscall **)(_DWORD *))(*v178 + 8))(a1: v178);
        }
        continue;
      case 0x15u:
        v134 = &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)];
        v27 = &v134->_unVal.pTable->__vftable;
        v134->_unVal.nInteger = v8->_roottable._unVal.nInteger;
        v135 = v8->_roottable._type;
        goto LABEL_228;
      case 0x16u:
        v182 = &_true_;
        if ( *(_DWORD *)v16 == 0 )
          v182 = &_false_;
        v183 = v8->_stackbase + *(unsigned __int8 *)(v16 + 5);
        v184 = v8->_stack._vals;
        v185.pTable = (SQTable *)v182->_unVal;
        v186 = v184[v183]._type;
        v187 = &v184[v183];
        v27 = &v187->_unVal.pTable->__vftable;
        v187->_unVal = v185;
        v188 = v182->_type;
        v187->_type = v188;
        if ( (v188 & 0x8000000) != 0 )
          ++*(_DWORD *)(v185.nInteger + 4);
        if ( (v186 & 0x8000000) == 0 )
          continue;
        if ( (int)--v27[1] > 0 )
          continue;
        goto LABEL_361;
      case 0x17u:
        v189 = v8->_stackbase;
        v190 = v8->_stack._vals;
        v191 = v189 + *(_DWORD *)v16;
        v192 = (int *)&v190[v189 + *(unsigned __int8 *)(v16 + 5)];
        v193.pTable = (SQTable *)v190[v191]._unVal;
        v194 = (int *)&v190[v191];
        last_topg = *v192;
        v195 = (_DWORD *)v192[1];
        v192[1] = v193.nInteger;
        v196 = *v194;
        *v192 = v196;
        if ( (v196 & 0x8000000) != 0 )
          ++*(_DWORD *)(v193.nInteger + 4);
        if ( (last_topg & 0x8000000) != 0 && (int)--v195[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v195 + 8))(a1: v195);
        v137 = (SQVM *)*(unsigned __int8 *)(v16 + 7);
        v138 = *(unsigned __int8 *)(v16 + 6);
LABEL_243:
        v197 = v8->_stackbase;
        v198 = v8->_stack._vals;
        v199 = (char *)v137 + v197;
        v200.pTable = (SQTable *)v198[(_DWORD)v199]._unVal;
        v201 = &v198[v197 + v138];
        v202 = &v198[(_DWORD)v199];
        v27 = &v201->_unVal.pTable->__vftable;
        v201->_unVal = v200;
        v203 = v202->_type;
        v180 = v201->_type;
        v201->_type = v203;
        if ( (v203 & 0x8000000) == 0 )
          goto LABEL_246;
        v181.pTable = v200.pTable;
        goto LABEL_245;
      case 0x18u:
        goto $LN939;
      case 0x19u:
        v204 = (int)&v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)];
        if ( ((*(_DWORD *)v204 & 0x1000000) == 0 || *(_DWORD *)v204 != 83886084 || *(float *)(v204 + 4) != 0.0)
          && *(_DWORD *)(v204 + 4) != 0 )
        {
          goto $LN939;
        }
        goto LABEL_260;
      case 0x1Au:
        v205 = (int)&v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)];
        if ( (*(_DWORD *)v205 & 0x1000000) != 0 && *(_DWORD *)v205 == 83886084 && *(float *)(v205 + 4) == 0.0
          || *(_DWORD *)(v205 + 4) == 0 )
        {
$LN939:
          v8->ci->_ip += *(_DWORD *)v16;
        }
LABEL_260:
        qs_fn = v8->_qs_fn;
        if ( qs_fn == nullptr )
          continue;
        if ( --v8->_qs_cnt >= 0 )
          continue;
        v8->_qs_cnt = 100000;
        v208 = qs_fn(a1: v8);
        if ( v208 == 1 )
        {
          SQVM::Raise_Error(a1: v8, this: (SQVM *)&stru_1009D2D8._suspended_traps, s: nullptr);
          goto exception_trap;
        }
        if ( v208 == 2 )
        {
          v209 = traps;
          v8->_suspended_target = ct_target;
          v210 = v8->ci;
          v8->_suspended = 1;
          v8->_suspended_root = v210->_root;
          v8->_suspended_traps = v209;
          v8->_suspend_varargs = v210->_vargs;
          --v8->_nnativecalls;
          return 1;
        }
        continue;
      case 0x1Bu:
        v211 = *(_DWORD *)(v8->ci->_closure._unVal.nInteger + 40);
        v212 = v8->_stackbase + *(unsigned __int8 *)(v16 + 5);
        v213.pTable = *(SQTable **)(v211 + 8 * *(_DWORD *)v16 + 4);
        v214 = (tagSQObjectType *)(v211 + 8 * *(_DWORD *)v16);
        v215 = v8->_stack._vals;
        v216 = v215[v212]._type;
        v217 = &v215[v212];
        v27 = &v217->_unVal.pTable->__vftable;
        v217->_unVal = v213;
        v218 = *v214;
        v217->_type = v218;
        if ( (v218 & 0x8000000) != 0 )
          ++*(_DWORD *)(v213.nInteger + 4);
        if ( (v216 & 0x8000000) == 0 )
          continue;
        if ( (int)--v27[1] > 0 )
          continue;
        goto LABEL_361;
      case 0x1Cu:
        v219.nInteger = v8->ci->_vargs.size;
        v220 = &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)];
        if ( (v220->_type & 0x8000000) != 0 )
        {
          v221.pTable = (SQTable *)v220->_unVal;
          if ( (int)--*(_DWORD *)(v221.nInteger + 4) <= 0 )
            v220->_unVal.pTable->Release(this: (struct SQTable *)v220->_unVal.nInteger);
        }
        v220->_unVal = v219;
        v220->_type = OT_INTEGER;
        continue;
      case 0x1Du:
        if ( SQVM::GETVARGV_OP(
               index: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
               ci: v8->ci,
               this: v8,
               target: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)]) == 0 )
          goto exception_trap;
        continue;
      case 0x1Eu:
        v222 = v8->_sharedstate;
        nInitialSize = *(_DWORD *)v16;
        last_toph = v222;
        v223 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
        if ( v223 != nullptr )
          SQTable::SQTable(this: v223, nInitialSize, ss: last_toph);
        v223->_delegate = nullptr;
        ++v223->_uiRef;
        v224 = v8->_stackbase + *(unsigned __int8 *)(v16 + 5);
        v225 = v8->_stack._vals;
        v226 = v225[v224]._type;
        v227 = &v225[v224];
        v228 = &v227->_unVal.pTable->__vftable;
        v227->_unVal.nInteger = (int)v223;
        v227->_type = OT_TABLE;
        ++v223->_uiRef;
        if ( (v226 & 0x8000000) != 0 && (int)--v228[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v228 + 8))(a1: v228);
        if ( --v223->_uiRef > 0 )
          continue;
        goto LABEL_283;
      case 0x1Fu:
        v229 = SQArray::Create(ss: v8->_sharedstate, nInitialSize: 0);
        ++v229->_uiRef;
        v230 = v8->_stackbase + *(unsigned __int8 *)(v16 + 5);
        v231 = v8->_stack._vals;
        v232 = &v231[v230]._unVal.pTable->__vftable;
        v233 = &v231[v230];
        v234 = v233->_type;
        v233->_unVal.nInteger = (int)v229;
        v233->_type = OT_ARRAY;
        ++v229->_uiRef;
        if ( (v234 & 0x8000000) != 0 && (int)--v232[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v232 + 8))(a1: v232);
        if ( --v229->_uiRef <= 0 )
          v229->Release(this: v229);
        v235 = v8->_stackbase + *(unsigned __int8 *)(v16 + 5);
        v236 = *(_DWORD *)v16;
        v237.pTable = (SQTable *)v8->_stack._vals[v235]._unVal;
        if ( v236 == 0 )
          v236 = 4;
        *(_DWORD *)(v237.nInteger + 24) = _g_pMemAlloc->Realloc_2(
                                            this: _g_pMemAlloc,
                                            a2: *(_DWORD *)(v237.nInteger + 24),
                                            a3: 8 * v236);
        *(_DWORD *)(v237.nInteger + 32) = v236;
        continue;
      case 0x20u:
        if ( *(_BYTE *)(v16 + 7) != 0 )
          v238 = (int)&v8->ci->_literals[*(_DWORD *)v16];
        else
          v238 = (int)&v8->_stack._vals[*(_DWORD *)v16 + v8->_stackbase];
        v239.pTable = (SQTable *)v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)]._unVal;
        v223 = *(SQTable **)(v238 + 4);
        val._type = *(_DWORD *)v238;
        v240 = (sqvector<SQObjectPtr> *)(val._type & 0x8000000);
        val._unVal.nInteger = (int)v223;
        last_topi = val._type & 0x8000000;
        if ( (val._type & 0x8000000) != 0 )
          ++v223->_uiRef;
        sqvector<SQObjectPtr>::push_back(this: v240, a2: v239.nInteger + 24, &val);
        if ( last_topi == 0 )
          continue;
        if ( --v223->_uiRef > 0 )
          continue;
LABEL_283:
        v223->Release(this: v223);
        continue;
      case 0x21u:
        if ( SQVM::GETPARENT_OP(
               o: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
               target: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)],
               this: v8) != 0 )
          continue;
        goto LABEL_412;
      case 0x22u:
        v241 = v8->_stackbase;
        if ( SQVM::DerefInc(
               self: &v8->_stack._vals[v241 + *(unsigned __int16 *)(v16 + 2)],
               key: &v8->_stack._vals[v241 + *(unsigned __int8 *)(v16 + 6)],
               this: v8,
               op: (const char *)*(unsigned __int8 *)(v16 + 7),
               target: &v8->_stack._vals[v241 + *(unsigned __int8 *)(v16 + 5)],
               incr: &v8->_stack._vals[v241 + (unsigned __int16)*(_DWORD *)v16],
               postfix: false) != 0 )
          continue;
        goto LABEL_412;
      case 0x23u:
        v242 = v8->_stackbase;
        v243 = v8->_stack._vals;
        last_topm = &v243[v242 + *(unsigned __int8 *)(v16 + 6)];
        v244 = &v243[v242 + *(_DWORD *)v16];
        v245 = v242 + *(unsigned __int8 *)(v16 + 5);
        v246 = (const char *)*(unsigned __int8 *)(v16 + 7);
        nInitialSize = (int)&v243[v245];
        if ( !SQVM::ARITH_OP(this: v8, o2: last_topm, op: v246, trg: (SQObjectPtr *)nInitialSize, o1: v244) )
          goto LABEL_412;
        v247 = (tagSQObjectType *)nInitialSize;
        v248.pTable = *(SQTable **)(nInitialSize + 4);
        v27 = &v244->_unVal.pTable->__vftable;
        v249 = v244->_type;
        v244->_unVal = v248;
        v250 = *v247;
        v244->_type = v250;
        if ( (v250 & 0x8000000) != 0 )
          ++*(_DWORD *)(v248.nInteger + 4);
        v251 = (v249 & 0x8000000) == 0;
        goto LABEL_359;
      case 0x24u:
        v252.nInteger = *(char *)(v16 + 7);
        incr._type = OT_INTEGER;
        incr._unVal = v252;
        v253 = SQVM::DerefInc(
                 self: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
                 key: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
                 this: v8,
                 op: (const char *)0x2B,
                 target: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)],
                 &incr,
                 postfix: false);
        goto LABEL_309;
      case 0x25u:
        v254 = v8->_stackbase;
        v255 = v254 + *(_DWORD *)v16;
        o2._unVal.nInteger = *(char *)(v16 + 7);
        v256 = v8->_stack._vals;
        v257 = &v256[v255];
        v258 = &v256[v254 + *(unsigned __int8 *)(v16 + 5)];
        o2._type = OT_INTEGER;
        if ( !SQVM::ARITH_OP(this: v8, &o2, op: (const char *)0x2B, trg: v258, o1: v257) )
          goto LABEL_412;
        v259.pTable = (SQTable *)v258->_unVal;
        v27 = &v257->_unVal.pTable->__vftable;
        v260 = v257->_type;
        v257->_unVal = v259;
        v261 = v258->_type;
        v257->_type = v261;
        if ( (v261 & 0x8000000) != 0 )
          ++*(_DWORD *)(v259.nInteger + 4);
        v166 = (v260 & 0x8000000) == 0;
        goto LABEL_247;
      case 0x26u:
        v262.nInteger = *(char *)(v16 + 7);
        v379._type = OT_INTEGER;
        v379._unVal = v262;
        v253 = SQVM::DerefInc(
                 self: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
                 key: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
                 this: v8,
                 op: (const char *)0x2B,
                 target: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)],
                 incr: &v379,
                 postfix: true);
        goto LABEL_309;
      case 0x27u:
        v263 = v8->_stackbase;
        v264 = *(_DWORD *)last_top;
        v265 = *(unsigned __int8 *)(last_top + 5);
        op._unVal.nInteger = *(char *)(last_top + 7);
        v266 = v8->_stack._vals;
        op._type = OT_INTEGER;
        v253 = SQVM::PLOCAL_INC(
                 this: v8,
                 target: &v266[v263 + v265],
                 a: &v266[v263 + v264],
                 &op,
                 incr: (SQObjectPtr *)v376);
        goto LABEL_309;
      case 0x28u:
        v253 = SQVM::CMP_OP(
                 this: v8,
                 o1: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
                 o2: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
                 op: (CmpOP)*(unsigned __int8 *)(v16 + 7),
                 res: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)]);
        goto LABEL_309;
      case 0x29u:
        v267 = SQVM::Get(
                 this: v8,
                 self: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
                 key: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
                 dest: &v8->temp_reg,
                 raw: true,
                 fetchroot: false);
        v268 = &_true_;
        if ( !v267 )
          v268 = &_false_;
        v269 = v8->_stackbase + *(unsigned __int8 *)(v16 + 5);
        v270 = v8->_stack._vals;
        v271.pTable = (SQTable *)v268->_unVal;
        v272 = v270[v269]._type;
        v273 = &v270[v269];
        v27 = &v273->_unVal.pTable->__vftable;
        v273->_unVal = v271;
        v274 = v268->_type;
        v273->_type = v274;
        if ( (v274 & 0x8000000) != 0 )
          ++*(_DWORD *)(v271.nInteger + 4);
        if ( (v272 & 0x8000000) == 0 )
          continue;
        if ( (int)--v27[1] > 0 )
          continue;
        goto LABEL_361;
      case 0x2Au:
        v275 = v8->_stackbase;
        v276 = v8->_stack._vals;
        v277 = v275 + *(_DWORD *)v16;
        v278 = v276[v277]._type;
        nInitialSize = (int)&v276[v277];
        if ( v278 != OT_CLASS
          || (v279 = v275 + *(unsigned __int8 *)(v16 + 6),
              v90 = v276[v279]._type == OT_INSTANCE,
              v280 = &v276[v279],
              !v90) )
        {
          v375 = IdType2Name(type: v276[v275 + *(unsigned __int8 *)(v16 + 6)]._type);
          v283 = IdType2Name(type: v278);
          SQVM::Raise_Error(a1: v8, this: (SQVM *)&stru_1009D3A4, s: v283, v375);
          goto exception_trap;
        }
        v281 = *(_DWORD *)(v280->_unVal.nInteger + 28);
        if ( v281 != 0 )
        {
          while ( v281 != *(_DWORD *)(nInitialSize + 4) )
          {
            v281 = *(_DWORD *)(v281 + 28);
            if ( v281 == 0 )
              goto LABEL_330;
          }
          v282 = &_true_;
        }
        else
        {
LABEL_330:
          v282 = &_false_;
        }
        SQObjectPtr::operator=(this: &v276[v275 + *(unsigned __int8 *)(last_top + 5)], obj: v282);
        continue;
      case 0x2Bu:
        v284 = v8->_stackbase;
        v285 = v8->_stack._vals;
        v286 = v284 + *(unsigned __int8 *)(v16 + 6);
        v287 = v285[v286]._type;
        v288 = &v285[v286];
        if ( ((v287 & 0x1000000) == 0 || v287 != OT_FLOAT || v288->_unVal.fFloat != 0.0) && v288->_unVal.nInteger != 0 )
          continue;
        goto LABEL_343;
      case 0x2Cu:
        v284 = v8->_stackbase;
        v285 = v8->_stack._vals;
        v289 = v284 + *(unsigned __int8 *)(v16 + 6);
        v290 = v285[v289]._type;
        v288 = &v285[v289];
        if ( (v290 & 0x1000000) != 0 && v290 == OT_FLOAT && v288->_unVal.fFloat == 0.0 || v288->_unVal.nInteger == 0 )
          continue;
LABEL_343:
        v291 = v284 + *(unsigned __int8 *)(v16 + 5);
        v292 = v285[v291]._type;
        v293 = &v285[v291];
        v294.pTable = (SQTable *)v288->_unVal;
        last_topj = v292;
        v295 = &v293->_unVal.pTable->__vftable;
        v293->_unVal = v294;
        v296 = v288->_type;
        v293->_type = v296;
        if ( (v296 & 0x8000000) != 0 )
          ++*(_DWORD *)(v294.nInteger + 4);
        if ( (last_topj & 0x8000000) != 0 && (int)--v295[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v295 + 8))(a1: v295);
        v8->ci->_ip += *(_DWORD *)v16;
        continue;
      case 0x2Du:
        v253 = SQVM::NEG_OP(
                 this: v8,
                 o: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
                 trg: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)]);
        goto LABEL_309;
      case 0x2Eu:
        v297 = v8->_stackbase;
        v298 = v8->_stack._vals;
        v299 = v297 + *(_DWORD *)v16;
        v300 = v298[v299]._type;
        v301 = &v298[v299];
        if ( (v300 & 0x1000000) != 0 && v300 == OT_FLOAT && v301->_unVal.fFloat == 0.0 || v301->_unVal.nInteger == 0 )
          v302 = &_true_;
        else
          v302 = &_false_;
        v303 = v297 + *(unsigned __int8 *)(v16 + 5);
        v27 = &v298[v303]._unVal.pTable->__vftable;
        v304 = v298[v303]._type;
        v305 = &v298[v303];
        v306.pTable = (SQTable *)v302->_unVal;
        v305->_unVal = v306;
        v307 = v302->_type;
        v305->_type = v307;
        if ( (v307 & 0x8000000) != 0 )
          ++*(_DWORD *)(v306.nInteger + 4);
        v251 = (v304 & 0x8000000) == 0;
LABEL_359:
        if ( !v251 && (int)--v27[1] <= 0 )
          goto LABEL_361;
        continue;
      case 0x2Fu:
        v308 = v8->_stackbase;
        v309 = v8->_stack._vals;
        v310 = &v309[v308 + *(_DWORD *)v16];
        if ( v310->_type != OT_INTEGER )
        {
          v314 = IdType2Name(type: v310->_type);
          SQVM::Raise_Error(a1: v8, this: (SQVM *)&stru_1009D3A4._vargsstack._size, s: v314);
          goto exception_trap;
        }
        v311.pTable = (SQTable *)v310->_unVal;
        v312 = &v309[v308 + *(unsigned __int8 *)(v16 + 5)];
        if ( (v312->_type & 0x8000000) != 0 )
        {
          v313.pTable = (SQTable *)v312->_unVal;
          if ( (int)--*(_DWORD *)(v313.nInteger + 4) <= 0 )
            v312->_unVal.pTable->Release(this: (struct SQTable *)v312->_unVal.nInteger);
        }
        v312->_unVal.nInteger = ~v311.nInteger;
        v312->_type = OT_INTEGER;
        continue;
      case 0x30u:
        v315 = (SQVM *)(v8->_stackbase + *(unsigned __int8 *)(v16 + 5));
        if ( SQVM::CLOSURE_OP(
               this: v315,
               target: v8,
               func: &v8->_stack._vals[(_DWORD)v315],
               funca: *(SQFunctionProto **)(*(_DWORD *)(*(_DWORD *)(v8->ci->_closure._unVal.nInteger + 36) + 72)
                                   + 8 * *(_DWORD *)v16
                                   + 4)) == 0 )
          goto exception_trap;
        continue;
      case 0x31u:
        if ( v8->ci->_generator == nullptr )
        {
          ++MEMORY[4];
          v316 = IdType2Name(type: OT_GENERATOR);
          SQVM::Raise_Error(a1: v8, this: (SQVM *)&stru_1009D3A4._debughook, s: v316);
          --MEMORY[4];
          if ( MEMORY[4] > 0 )
            goto exception_trap;
          v129 = (SQString_vtbl *)MEMORY[0];
          v92 = nullptr;
          goto LABEL_415;
        }
        if ( *(_DWORD *)v16 != 255 )
        {
          SQObjectPtr::operator=(this: &v8->temp_reg, obj: &v8->_stack._vals[*(_DWORD *)v16 + v8->_stackbase]);
          v16 = last_top;
        }
        if ( SQGenerator::Yield(this: (SQGenerator *)v8->ci, v: (SQVM *)v8->ci->_generator, i: (int)v8) == 0 )
        {
LABEL_374:
          SQVM::Raise_Error(this: v8, desc: &v8->_lasterror);
          goto exception_trap;
        }
        traps -= v8->ci->_etraps;
        if ( *(_DWORD *)v16 != 255 )
        {
          SQObjectPtr::operator=(this: &v8->_stack._vals[*(_DWORD *)v16 + v8->_stackbase], obj: &v8->temp_reg);
          v16 = last_top;
        }
        if ( SQVM::Return(this: v8, retval: &v8->temp_reg, _arg0: *(unsigned __int8 *)(v16 + 5), _arg1: *(_DWORD *)v16) )
        {
          SQObjectPtr::operator=(this: outres, obj: &v8->temp_reg);
          --v8->_nnativecalls;
          return 1;
        }
        continue;
      case 0x32u:
        v317 = *(_DWORD *)v16 + v8->_stackbase;
        v318 = v8->_stack._vals;
        v319 = v318[v317]._type;
        v320 = &v318[v317];
        if ( v319 != OT_GENERATOR )
        {
          v321 = IdType2Name(type: v319);
          SQVM::Raise_Error(a1: v8, this: (SQVM *)&stru_1009D3A4._foreignptr, s: v321);
          goto exception_trap;
        }
        if ( SQGenerator::Resume(
               this: v320->_unVal.pGenerator,
               v: v320->_unVal.pThread,
               target: (int)v8,
               targeta: *(unsigned __int8 *)(v16 + 5)) == 0 )
          goto LABEL_374;
        traps += v8->ci->_etraps;
        continue;
      case 0x33u:
        v322 = *(unsigned __int8 *)(v16 + 6);
        v323 = v8->_stackbase;
        v324 = v8->_stack._vals;
        nInitialSize = (int)&v324[v323 + v322];
        if ( SQVM::FOREACH_OP(
               o1: &v324[v323 + *(unsigned __int8 *)(v16 + 5)],
               o2: (SQObjectPtr *)nInitialSize,
               this: v8,
               o3: (SQObjectPtr *)(nInitialSize + 8),
               o4: (SQObjectPtr *)(nInitialSize + 16),
               arg_2: v322,
               exitpos: *(_DWORD *)v16,
               jump: &tojump) == 0 )
          goto LABEL_412;
        v8->ci->_ip += tojump;
        continue;
      case 0x34u:
        if ( *(_DWORD *)(v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)]._unVal.nInteger + 116) == 2 )
          v8->ci->_ip += *(_DWORD *)v16 - 1;
        continue;
      case 0x35u:
        v253 = SQVM::DELEGATE_OP(
                 o2: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
                 this: v8,
                 trg: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)],
                 o1: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16]);
        goto LABEL_309;
      case 0x36u:
        if ( SQVM::Clone(
               this: (SQVM *)v8->_stack._vals,
               self: (const SQObjectPtr *)v8,
               target: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16]) )
        {
          continue;
        }
        v325 = IdType2Name(type: v8->_stack._vals[*(_DWORD *)v16 + v8->_stackbase]._type);
        SQVM::Raise_Error(a1: v8, this: (SQVM *)&stru_1009D46C, s: v325);
        goto exception_trap;
      case 0x37u:
        SQVM::TypeOf(
          obj1: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
          dest: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)],
          this: v8);
        continue;
      case 0x38u:
        v326 = v8->ci;
        v327 = *(_DWORD *)(v326->_closure._unVal.nInteger + 36);
        v377._stacksize = v8->_top;
        v377._stackbase = v8->_stackbase;
        v327 += 96;
        v328 = ((int)v326->_ip - v327) >> 3;
        v329 = *(unsigned __int8 *)(last_top + 5);
        v377._ip = (SQInstruction *)(v327 + 8 * (*(_DWORD *)last_top + v328));
        v377._extarget = v329;
        sqvector<SQExceptionTrap>::push_back(this: (sqvector<SQExceptionTrap> *)v329, a2: (int)&v8->_etraps, val: &v377);
        v330 = v8->ci;
        ++traps;
        ++v330->_etraps;
        continue;
      case 0x39u:
        v331 = 0;
        if ( *(_BYTE *)(v16 + 5) != 0 )
        {
          v332 = traps;
          do
          {
            --v8->_etraps._size;
            --v8->ci->_etraps;
            ++v331;
            --v332;
          }
          while ( v331 < *(unsigned __int8 *)(v16 + 5) );
          traps = v332;
        }
        continue;
      case 0x3Au:
        v333 = v8->_stackbase + *(unsigned __int8 *)(v16 + 5);
        v334 = v8->_stack._vals;
        v335.pTable = (SQTable *)v334[v333]._unVal;
        v336 = &v334[v333]._type;
        v337 = &v8->_lasterror._unVal.pTable->__vftable;
        v338 = v8->_lasterror._type;
        v8->_lasterror._unVal = v335;
        v339 = *v336;
        v8->_lasterror._type = v339;
        if ( (v339 & 0x8000000) != 0 )
          ++*(_DWORD *)(v335.nInteger + 4);
        if ( (v338 & 0x8000000) != 0 && (int)--v337[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v337 + 8))(a1: v337);
        goto exception_trap;
      case 0x3Bu:
        v253 = SQVM::CLASS_OP(
                 baseclass: *(_DWORD *)v16,
                 attributes: *(unsigned __int8 *)(v16 + 6),
                 this: v8,
                 target: (SQClass *)&v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 5)]);
LABEL_309:
        if ( v253 == 0 )
          goto LABEL_412;
        continue;
      case 0x3Cu:
        v340 = *(_DWORD *)v16 + v8->_stackbase;
        v341 = v8->_stack._vals;
        v90 = v341[v340]._type == OT_CLASS;
        v342 = &v341[v340];
        LOBYTE(bstatic) = (*(_BYTE *)(v16 + 5) & 2) != 0;
        if ( v90
          && *(_DWORD *)(*(_DWORD *)(v342->_unVal.nInteger + 56) + 128) != 16777217
          && ((SQVM::Push(this: v8, o: v342),
               SQVM::Push(this: v8, o: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)]),
               SQVM::Push(this: v8, o: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 7)]),
               (*(_BYTE *)(v16 + 5) & 1) == 0)
            ? (v343 = &_null_)
            : (v343 = &v8->_stack._vals[v8->_stackbase - 1 + *(unsigned __int8 *)(v16 + 6)]),
              SQVM::Push(this: v8, o: v343),
              SQVM::Call(
                this: v8,
                closure: (SQObjectPtr *)(*(_DWORD *)(v8->_stack._vals[*(_DWORD *)v16 + v8->_stackbase]._unVal.nInteger + 56) + 128),
                nparams: 4,
                stackbase: v8->_top - 4,
                outres: &v8->temp_reg,
                raiseerror: 0)) )
        {
          SQVM::Pop(this: v8, n: 4);
        }
        else
        {
          if ( !SQVM::NewSlot(
                  this: (SQVM *)v8->_stack._vals,
                  self: &v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16],
                  key: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)],
                  val: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 7)],
                  bstatic) )
          {
LABEL_412:
            v92 = (SQString_vtbl **)v8->_lasterror._unVal.pTable;
            v8->_lasterror._unVal.nInteger = (int)v92;
            v344 = v8->_lasterror._type;
            v8->_lasterror._type = v344;
            if ( (v344 & 0x8000000) != 0 )
            {
              ++*(_DWORD *)(v8->_lasterror._unVal.nInteger + 4);
              v92[1] = (SQString_vtbl *)((char *)v92[1] - 1);
              if ( (int)v92[1] <= 0 )
                goto LABEL_414;
            }
            goto exception_trap;
          }
          if ( (*(_BYTE *)(v16 + 5) & 1) != 0 )
            SQClass::SetAttributes(
              val: &v8->_stack._vals[v8->_stackbase - 1 + *(unsigned __int8 *)(v16 + 6)],
              this: v8->_stack._vals[v8->_stackbase + *(_DWORD *)v16]._unVal.pClass,
              key: &v8->_stack._vals[v8->_stackbase + *(unsigned __int8 *)(v16 + 6)]);
        }
        continue;
      default:
        continue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A580
// Name: public: bool SQVM::CreateClassInstance(struct SQClass __near *,struct SQObjectPtr __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::CreateClassInstance@<al>(
        SQObjectPtr *inst@<eax>,
        SQClass *a2@<ecx>,
        SQVM *this,
        SQClass *theclass,
        SQObjectPtr *constructor)
{
  SQInstance *Instance; // esi
  tagSQObjectType type; // eax
  _DWORD *v8; // ecx
  _DWORD *v9; // ecx
  tagSQObjectType v10; // eax
  tagSQObjectType v11; // edx

  Instance = SQClass::CreateInstance(this: a2, a2: theclass);
  ++Instance->_uiRef;
  type = inst->_type;
  v8 = &inst->_unVal.pTable->__vftable;
  inst->_unVal.nInteger = (int)Instance;
  inst->_type = OT_INSTANCE;
  ++Instance->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  if ( --Instance->_uiRef <= 0 )
    Instance->Release(this: Instance);
  if ( SQClass::Get(this: theclass, val: constructor, key: &this->_sharedstate->_constructoridx) == 0 )
  {
    v9 = &constructor->_unVal.pTable->__vftable;
    v10 = constructor->_type;
    constructor->_unVal.nInteger = _null_._unVal.nInteger;
    v11 = _null_._type;
    constructor->_type = _null_._type;
    if ( (v11 & 0x8000000) != 0 )
      ++*(_DWORD *)(constructor->_unVal.nInteger + 4);
    if ( (v10 & 0x8000000) != 0 && (int)--v9[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005A640
// Name: public: void SQVM::CallErrorHandler(struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQVM::CallErrorHandler(SQVM *this@<ecx>, int a2@<eax>, SQObjectPtr *error)
{
  int v4; // eax
  int v5; // edx
  int *v6; // eax
  int v7; // edx
  _DWORD *v8; // ecx
  int v9; // edi
  int v10; // edx
  int v11; // eax
  int v12; // edx
  _DWORD *v13; // ecx
  int v14; // edi
  tagSQObjectType *v15; // eax
  tagSQObjectType type; // edx
  tagSQObjectValue v17; // eax
  SQObjectPtr out; // [esp+10h] [ebp-Ch] BYREF

  if ( *(_DWORD *)(a2 + 80) != 16777217 )
  {
    v4 = *(_DWORD *)(a2 + 56);
    v5 = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(a2 + 56) = v4 + 1;
    v6 = (int *)(v5 + 8 * v4);
    v7 = *(_DWORD *)(a2 + 68);
    out._type = OT_NULL;
    out._unVal.nInteger = 0;
    v8 = (_DWORD *)v6[1];
    v9 = *v6;
    v6[1] = v7;
    v10 = *(_DWORD *)(a2 + 64);
    *v6 = v10;
    if ( (v10 & 0x8000000) != 0 )
      ++*(_DWORD *)(v6[1] + 4);
    if ( (v9 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
    v11 = *(_DWORD *)(a2 + 56);
    v12 = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(a2 + 56) = v11 + 1;
    v13 = *(_DWORD **)(v12 + 8 * v11 + 4);
    v14 = *(_DWORD *)(v12 + 8 * v11);
    v15 = (tagSQObjectType *)(v12 + 8 * v11);
    v15[1] = (tagSQObjectType)error->_unVal.pTable;
    type = error->_type;
    *v15 = error->_type;
    if ( (type & 0x8000000) != 0 )
      ++*(_DWORD *)(*((_DWORD *)v15 + 1) + 4);
    if ( (v14 & 0x8000000) != 0 && (int)--v13[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
    SQVM::Call(
      this: (SQVM *)a2,
      closure: (SQObjectPtr *)(a2 + 80),
      nparams: 2,
      stackbase: *(_DWORD *)(a2 + 56) - 2,
      outres: &out,
      raiseerror: 0);
    SQVM::Pop(this: (SQVM *)a2, n: 2);
    if ( (out._type & 0x8000000) != 0 )
    {
      v17.pTable = (SQTable *)out._unVal;
      --*(_DWORD *)(out._unVal.nInteger + 4);
      if ( *(int *)(v17.nInteger + 4) <= 0 )
        out._unVal.pTable->Release(this: (struct SQTable *)out._unVal.nInteger);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A740
// Name: public: void SQVM::CallDebugHook(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQVM::CallDebugHook(SQVM *this@<ecx>, int a2@<eax>, int type, int forcedline)
{
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  _DWORD *v8; // edi
  int v9; // ecx
  int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // ecx
  int v13; // edx
  int v14; // eax
  int v15; // ecx
  int *v16; // eax
  int v17; // edx
  _DWORD *v18; // ecx
  int v19; // eax
  int v20; // edx
  _DWORD *v21; // ecx
  int v22; // ebx
  _DWORD *v23; // eax
  int v24; // edx
  int v25; // ebx
  int *v26; // ecx
  int v27; // edx
  int *v28; // ecx
  int v29; // ebx
  int v30; // eax
  int v31; // ecx
  int *v32; // eax
  int v33; // edx
  _DWORD *v34; // ecx
  int v35; // eax
  int v36; // edx
  int v37; // ebx
  _DWORD *v38; // ecx
  int *v39; // eax
  int v40; // edx
  int v41; // edi
  tagSQObjectValue v42; // eax
  SQObjectPtr temp_reg; // [esp+10h] [ebp-8h] BYREF
  int typea; // [esp+20h] [ebp+8h]
  int forcedlinea; // [esp+24h] [ebp+Ch]

  v5 = *(_DWORD *)(a2 + 140);
  temp_reg._type = OT_NULL;
  temp_reg._unVal.nInteger = 0;
  v6 = *(_DWORD *)(v5 + 12);
  v7 = *(_DWORD *)(a2 + 56);
  v8 = *(_DWORD **)(v6 + 36);
  v9 = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(a2 + 56) = v7 + 1;
  v10 = *(_DWORD *)(v9 + 8 * v7);
  v11 = (_DWORD *)(v9 + 8 * v7);
  v12 = (_DWORD *)v11[1];
  v11[1] = *(_DWORD *)(a2 + 68);
  v13 = *(_DWORD *)(a2 + 64);
  *v11 = v13;
  if ( (v13 & 0x8000000) != 0 )
    ++*(_DWORD *)(v11[1] + 4);
  if ( (v10 & 0x8000000) != 0 && (int)--v12[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
  v14 = *(_DWORD *)(a2 + 56);
  v15 = v14 + 1;
  v16 = (int *)(*(_DWORD *)(a2 + 32) + 8 * v14);
  *(_DWORD *)(a2 + 56) = v15;
  v17 = *v16;
  v18 = (_DWORD *)v16[1];
  v16[1] = type;
  *v16 = 83886082;
  if ( (v17 & 0x8000000) != 0 && (int)--v18[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v18 + 8))(a1: v18);
  v19 = *(_DWORD *)(a2 + 56);
  v20 = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(a2 + 56) = v19 + 1;
  v21 = *(_DWORD **)(v20 + 8 * v19 + 4);
  v22 = *(_DWORD *)(v20 + 8 * v19);
  v23 = (_DWORD *)(v20 + 8 * v19);
  v23[1] = v8[4];
  v24 = v8[3];
  *v23 = v24;
  if ( (v24 & 0x8000000) != 0 )
    ++*(_DWORD *)(v23[1] + 4);
  if ( (v22 & 0x8000000) != 0 && (int)--v21[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v21 + 8))(a1: v21);
  v25 = forcedline;
  if ( forcedline == 0 )
  {
    v26 = (int *)v8[12];
    forcedlinea = *v26;
    v27 = v8[11];
    typea = 1;
    if ( v27 > 1 )
    {
      v28 = v26 + 2;
      do
      {
        if ( v28[1] >= (**(_DWORD **)(a2 + 140) - (int)v8 - 96) >> 3 )
          break;
        v29 = *v28;
        ++typea;
        v28 += 2;
        forcedlinea = v29;
      }
      while ( typea < v27 );
    }
    v25 = forcedlinea;
  }
  v30 = *(_DWORD *)(a2 + 56);
  v31 = v30 + 1;
  v32 = (int *)(*(_DWORD *)(a2 + 32) + 8 * v30);
  *(_DWORD *)(a2 + 56) = v31;
  v33 = *v32;
  v34 = (_DWORD *)v32[1];
  v32[1] = v25;
  *v32 = 83886082;
  if ( (v33 & 0x8000000) != 0 && (int)--v34[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v34 + 8))(a1: v34);
  v35 = *(_DWORD *)(a2 + 56);
  v36 = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(a2 + 56) = v35 + 1;
  v37 = v8[6];
  v38 = *(_DWORD **)(v36 + 8 * v35 + 4);
  v39 = (int *)(v36 + 8 * v35);
  v40 = *v39;
  v39[1] = v37;
  v41 = v8[5];
  *v39 = v41;
  if ( (v41 & 0x8000000) != 0 )
    ++*(_DWORD *)(v37 + 4);
  if ( (v40 & 0x8000000) != 0 && (int)--v38[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v38 + 8))(a1: v38);
  SQVM::Call(
    this: (SQVM *)a2,
    closure: (SQObjectPtr *)(a2 + 88),
    nparams: 5,
    stackbase: *(_DWORD *)(a2 + 56) - 5,
    outres: &temp_reg,
    raiseerror: 0);
  SQVM::Pop(this: (SQVM *)a2, n: 5);
  if ( (temp_reg._type & 0x8000000) != 0 )
  {
    v42.pTable = (SQTable *)temp_reg._unVal;
    --*(_DWORD *)(temp_reg._unVal.nInteger + 4);
    if ( *(int *)(v42.nInteger + 4) <= 0 )
      temp_reg._unVal.pTable->Release(this: (struct SQTable *)temp_reg._unVal.nInteger);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005A940
// Name: public: bool SQVM::CallNative(struct SQNativeClosure __near *,int,int,struct SQObjectPtr __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQVM::CallNative(
        SQVM *this,
        SQObjectPtr *nclosure,
        tagSQObjectValue *nargs,
        int stackbase,
        int retval,
        SQObjectPtr *suspend,
        bool *suspenda)
{
  int nInteger; // eax
  int v10; // edx
  bool v11; // sf
  const char *v12; // eax
  int v13; // esi
  int v14; // ecx
  tagSQObjectValue v15; // ecx
  signed int v16; // eax
  sqvector<SQObjectPtr> *v17; // ecx
  tagSQObjectValue v18; // esi
  int v19; // edx
  tagSQObjectType type; // eax
  SQObjectPtr *v21; // esi
  int *pTable; // ecx
  SQVM::CallInfo *v23; // esi
  tagSQObjectValue *v24; // edi
  tagSQObjectValue v25; // esi
  tagSQObjectValue v26; // eax
  tagSQObjectValue v27; // edx
  int v28; // edi
  int *v29; // eax
  _DWORD *v30; // ecx
  int v31; // edx
  tagSQObjectValue v32; // edx
  int v33; // esi
  int *v34; // eax
  _DWORD *v35; // ecx
  int v36; // edx
  int v37; // eax
  tagSQObjectValue v38; // eax
  int v39; // edx
  _DWORD *v40; // ecx
  unsigned int v41; // eax
  _DWORD *v42; // ecx
  tagSQObjectType v43; // edx
  int *v44; // ecx
  tagSQObjectValue v45; // ecx
  unsigned int v46; // edx
  tagSQObjectValue v47; // esi
  tagSQObjectType v48; // edi
  tagSQObjectType *v49; // edx
  _DWORD *v50; // ecx
  tagSQObjectType v51; // edx
  unsigned int v52; // ecx
  tagSQObjectValue v53; // eax
  tagSQObjectType v54; // edx
  _DWORD *v55; // eax
  _DWORD *v56; // ecx
  tagSQObjectType v57; // esi
  tagSQObjectValue v58; // eax
  int v59; // edx
  _DWORD *v60; // ecx
  unsigned int raw; // eax
  int *v62; // ecx
  const char *v63; // [esp+0h] [ebp-78h]
  SQVM::CallInfo v64; // [esp+Ch] [ebp-6Ch] BYREF
  SQVM::CallInfo lci; // [esp+3Ch] [ebp-3Ch] BYREF
  SQObjectPtr fill; // [esp+6Ch] [ebp-Ch] BYREF
  int v67; // [esp+74h] [ebp-4h]
  int oldtop; // [esp+80h] [ebp+8h]
  int oldtopa; // [esp+80h] [ebp+8h]
  int (__cdecl *oldstackbase)(SQVM *); // [esp+88h] [ebp+10h]
  int stackbasea; // [esp+8Ch] [ebp+14h]

  oldtop = nclosure[19]._type + 1;
  if ( oldtop > 100 )
  {
    SQVM::Raise_Error(a1: nclosure, this: (SQVM *)&stru_1009D2D8.temp_reg, s: v63);
    return 0;
  }
  nInteger = nargs[6].nInteger;
  v10 = stackbase;
  v11 = nInteger < 0;
  if ( nInteger > 0 )
  {
    if ( nInteger != stackbase )
    {
LABEL_8:
      SQVM::Raise_Error(a1: nclosure, this: (SQVM *)&stru_1009D15C._roottable, s: v63);
      return 0;
    }
    v11 = nInteger < 0;
  }
  if ( v11 && stackbase < -nInteger )
    goto LABEL_8;
  if ( nargs[8].nInteger != 0 )
  {
    v12 = nullptr;
    if ( stackbase > 0 )
    {
      v13 = 8 * retval;
      while ( (int)v12 < nargs[8].nInteger )
      {
        v14 = *(_DWORD *)(nargs[7].nInteger + 4 * (_DWORD)v12);
        if ( v14 != -1 )
        {
          if ( (v14 & *(_DWORD *)(v13 + nclosure[4]._type)) == 0 )
          {
            SQVM::Raise_ParamTypeError(
              this: nargs[7].pThread,
              a2: nclosure,
              nparam: v12,
              typemask: *(_DWORD *)(nargs[7].nInteger + 4 * (_DWORD)v12),
              type: *(tagSQObjectType *)(nclosure[4]._type + 8 * (_DWORD)&v12[retval]));
            return 0;
          }
          v10 = stackbase;
        }
        ++v12;
        v13 += 8;
        if ( (int)v12 >= v10 )
          break;
      }
    }
  }
  v15.pTable = (SQTable *)nclosure[7]._type;
  nclosure[19]._type = oldtop;
  v16 = nclosure[4]._unVal.nInteger;
  v17 = (sqvector<SQObjectPtr> *)(v15.nInteger + 10);
  if ( (int)v17 > v16 )
  {
    fill._type = OT_NULL;
    fill._unVal.nInteger = 0;
    sqvector<SQObjectPtr>::resize(this: v17, a2: (int)&nclosure[4], newsize: v16 + 20, &fill);
    v10 = stackbase;
  }
  v18.pTable = (SQTable *)nclosure[7]._type;
  oldstackbase = (int (__cdecl *)(SQVM *))nclosure[7]._unVal.pTable;
  nclosure[7]._type = retval + v10;
  ++nargs[1].nInteger;
  ++nargs[1].nInteger;
  --nargs[1].nInteger;
  oldtopa = v18.nInteger;
  lci._vargs = 0;
  lci._closure._unVal.nInteger = (int)nargs;
  lci._closure._type = OT_NATIVECLOSURE;
  if ( nargs[1].nInteger <= 0 )
    (*(void (__thiscall **)(tagSQObjectValue *))(nargs->nInteger + 8))(a1: nargs);
  v19 = retval - nclosure[7]._unVal.nInteger;
  lci._ncalls = 1;
  type = nclosure[14]._type;
  lci._generator = nullptr;
  lci._etraps = 0;
  lci._prevstkbase = v19;
  lci._prevtop = v18.nInteger - (_DWORD)oldstackbase;
  if ( nclosure[13]._unVal.nInteger == type )
  {
    v21 = (SQObjectPtr *)(2 * type);
    v64._vargs = 0;
    v64._closure._type = OT_NULL;
    v64._closure._unVal.nInteger = 0;
    sqvector<SQVM::CallInfo>::resize(
      this: (sqvector<SQVM::CallInfo> *)&nclosure[14]._unVal,
      fill: &v64,
      newsize: 2 * type);
    if ( (v64._closure._type & 0x8000000) != 0 )
    {
      pTable = (int *)v64._closure._unVal.pTable;
      --*(_DWORD *)(v64._closure._unVal.nInteger + 4);
      if ( pTable[1] <= 0 )
        (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
    }
    nclosure[13]._type = (tagSQObjectType)nclosure[14]._unVal.pTable;
    nclosure[14]._type = (tagSQObjectType)v21;
  }
  v23 = (SQVM::CallInfo *)(nclosure[13]._type + 48 * nclosure[13]._unVal.nInteger);
  nclosure[17]._unVal.nInteger = (int)v23;
  SQVM::CallInfo::operator=(this: v23, __that: &lci);
  ++nclosure[13]._unVal.nInteger;
  v24 = nargs;
  nclosure[7]._unVal.nInteger = retval;
  v25.nInteger = 0;
  fill._unVal = nargs[11];
  if ( fill._unVal.nInteger > 0 )
  {
    do
    {
      v26.pTable = (SQTable *)nclosure[7]._type;
      v27.pTable = v24[10].pTable;
      nclosure[7]._type = v26.nInteger + 1;
      v28 = *(_DWORD *)(v27.nInteger + 8 * v25.nInteger + 4);
      v29 = (int *)(nclosure[4]._type + 8 * v26.nInteger);
      v67 = *v29;
      v30 = (_DWORD *)v29[1];
      v29[1] = v28;
      v31 = *(_DWORD *)(v27.nInteger + 8 * v25.nInteger);
      *v29 = v31;
      if ( (v31 & 0x8000000) != 0 )
        ++*(_DWORD *)(v28 + 4);
      if ( (v67 & 0x8000000) != 0 && (int)--v30[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v30 + 8))(a1: v30);
      v24 = nargs;
      ++v25.nInteger;
    }
    while ( v25.nInteger < fill._unVal.nInteger );
  }
  if ( v24[13].nInteger == 134283264 )
  {
    v32.pTable = v24[14].pTable;
    v33 = *(_DWORD *)(v32.nInteger + 16);
    v34 = (int *)(nclosure[4]._type + 8 * retval);
    stackbasea = *v34;
    v35 = (_DWORD *)v34[1];
    v34[1] = v33;
    v36 = *(_DWORD *)(v32.nInteger + 12);
    *v34 = v36;
    if ( (v36 & 0x8000000) != 0 )
      ++*(_DWORD *)(v33 + 4);
    if ( (stackbasea & 0x8000000) != 0 && (int)--v35[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v35 + 8))(a1: v35);
  }
  v37 = ((int (__cdecl *)(SQObjectPtr *))v24[15].pTable)(a1: nclosure);
  --nclosure[19]._type;
  *suspenda = false;
  if ( v37 == -666 )
  {
    *suspenda = true;
    goto LABEL_57;
  }
  if ( v37 >= 0 )
  {
    if ( v37 == 0 )
    {
      v56 = &suspend->_unVal.pTable->__vftable;
      v54 = suspend->_type;
      suspend->_unVal.nInteger = _null_._unVal.nInteger;
      v57 = _null_._type;
      suspend->_type = _null_._type;
      if ( (v57 & 0x8000000) != 0 )
        ++*(_DWORD *)(suspend->_unVal.nInteger + 4);
      goto LABEL_65;
    }
LABEL_57:
    v45.pTable = (SQTable *)nclosure[7]._type;
    v46 = nclosure[4]._type;
    v47.pTable = *(SQTable **)(v46 + 8 * v45.nInteger - 4);
    v48 = suspend->_type;
    v49 = (tagSQObjectType *)(v46 + 8 * v45.nInteger - 8);
    v50 = &suspend->_unVal.pTable->__vftable;
    suspend->_unVal = v47;
    v51 = *v49;
    suspend->_type = v51;
    if ( (v51 & 0x8000000) != 0 )
      ++*(_DWORD *)(v47.nInteger + 4);
    if ( (v48 & 0x8000000) != 0 && (int)--v50[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v50 + 8))(a1: v50);
    v52 = nclosure[4]._type;
    v53.pTable = (SQTable *)nclosure[7]._type;
    v54 = *(_DWORD *)(v52 + 8 * v53.nInteger - 8);
    v55 = (_DWORD *)(v52 + 8 * v53.nInteger - 8);
    v56 = (_DWORD *)v55[1];
    *v55 = 16777217;
    v55[1] = 0;
LABEL_65:
    if ( (v54 & 0x8000000) != 0 && (int)--v56[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v56 + 8))(a1: v56);
    --nclosure[13]._unVal.nInteger;
    v58.pTable = (SQTable *)nclosure[17]._unVal;
    nclosure[7]._unVal.nInteger = (int)oldstackbase;
    nclosure[7]._type = oldtopa;
    v59 = *(_DWORD *)(v58.nInteger + 8);
    v60 = *(_DWORD **)(v58.nInteger + 12);
    *(_DWORD *)(v58.nInteger + 8) = 16777217;
    *(_DWORD *)(v58.nInteger + 12) = 0;
    if ( (v59 & 0x8000000) != 0 && (int)--v60[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v60 + 8))(a1: v60);
    raw = nclosure[13]._unVal.raw;
    if ( raw != 0 )
      nclosure[17]._unVal.nInteger = nclosure[13]._type + 48 * raw - 48;
    else
      nclosure[17]._unVal.nInteger = 0;
    if ( (lci._closure._type & 0x8000000) != 0 )
    {
      v62 = (int *)lci._closure._unVal.pTable;
      --*(_DWORD *)(lci._closure._unVal.nInteger + 4);
      if ( v62[1] <= 0 )
        (*(void (__thiscall **)(int *))(*v62 + 8))(a1: v62);
    }
    return 1;
  }
  --nclosure[13]._unVal.nInteger;
  nclosure[7]._type = oldtopa;
  v38.pTable = (SQTable *)nclosure[17]._unVal;
  nclosure[7]._unVal.nInteger = (int)oldstackbase;
  v39 = *(_DWORD *)(v38.nInteger + 8);
  v40 = *(_DWORD **)(v38.nInteger + 12);
  *(_DWORD *)(v38.nInteger + 8) = 16777217;
  *(_DWORD *)(v38.nInteger + 12) = 0;
  if ( (v39 & 0x8000000) != 0 && (int)--v40[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v40 + 8))(a1: v40);
  v41 = nclosure[13]._unVal.raw;
  if ( v41 != 0 )
    nclosure[17]._unVal.nInteger = nclosure[13]._type + 48 * v41 - 48;
  else
    nclosure[17]._unVal.nInteger = 0;
  v42 = &nclosure[9]._unVal.pTable->__vftable;
  v43 = nclosure[9]._type;
  nclosure[9]._unVal.nInteger = (int)v42;
  nclosure[9]._type = v43;
  if ( (v43 & 0x8000000) != 0 )
  {
    ++v42[1];
    if ( (int)--v42[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v42 + 8))(a1: v42);
  }
  if ( (lci._closure._type & 0x8000000) != 0 )
  {
    v44 = (int *)lci._closure._unVal.pTable;
    --*(_DWORD *)(lci._closure._unVal.nInteger + 4);
    if ( v44[1] <= 0 )
      (*(void (__thiscall **)(int *))(*v44 + 8))(a1: v44);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005ADE0
// Name: public: bool SQVM::Get(struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,struct SQObjectPtr __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQVM::Get(
        SQVM *this,
        const SQObjectPtr *self,
        const SQObjectPtr *key,
        SQObjectPtr *dest,
        bool raw,
        bool fetchroot)
{
  tagSQObjectType type; // eax
  SQVM *v7; // esi
  SQObjectPtr *v9; // eax

  type = self->_type;
  v7 = this;
  if ( self->_type == OT_ARRAY )
  {
    if ( (key->_type & 0x4000000) != 0 )
    {
      if ( key->_type == OT_FLOAT )
        return SQArray::Get(nidx: (int)key->_unVal.fFloat, val: dest, this: self->_unVal.pArray);
      else
        return SQArray::Get(nidx: key->_unVal.nInteger, val: dest, this: self->_unVal.pArray);
    }
  }
  else if ( type == OT_TABLE )
  {
    if ( SQTable::Get(key, val: dest, this: self->_unVal.pTable) != 0 )
      return 1;
    v7 = this;
  }
  else if ( type == OT_INSTANCE && SQInstance::Get(this: self->_unVal.pInstance, val: dest, key) != 0 )
  {
    return 1;
  }
  if ( SQVM::FallBackGet(this: v7, self, key, dest, raw) )
    return 1;
  if ( fetchroot
    && (v9 = &v7->_stack._vals[v7->_stackbase])->_unVal.nInteger == self->_unVal.nInteger
    && v9->_type == self->_type )
  {
    return SQTable::Get(key, val: dest, this: v7->_roottable._unVal.pTable);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005AEE0
// Name: public: bool SQVM::FallBackGet(struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,struct SQObjectPtr __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::FallBackGet@<al>(
        SQVM *this@<ecx>,
        SQObjectPtr *dest@<eax>,
        const SQObjectPtr *self,
        const SQObjectPtr *key,
        bool raw)
{
  const SQObjectPtr *v5; // edx
  tagSQObjectType type; // eax
  __int32 v10; // eax
  __int32 v11; // eax
  int fFloat; // ebx
  tagSQObjectValue v14; // edi
  SQObjectPtr *v15; // ecx
  int v16; // eax
  tagSQObjectValue v17; // eax
  SQObjectPtr v18; // [esp+10h] [ebp-Ch] BYREF
  char key_3; // [esp+2Bh] [ebp+Fh]

  v5 = self;
  type = self->_type;
  if ( self->_type > OT_GENERATOR )
  {
    if ( type > OT_TABLE )
    {
      if ( type != OT_USERDATA )
      {
        if ( type != OT_INSTANCE || raw )
          return 0;
        SQVM::Push(this, o: self);
        SQVM::Push(this, o: key);
        if ( !SQVM::CallMetaMethod(this, del: self->_unVal.pTable, mm: MT_GET, nparams: 2, outres: dest) )
          return SQTable::Get(key, val: dest, this: this->_sharedstate->_instance_default_delegate._unVal.pTable);
        return 1;
      }
    }
    else if ( type != OT_TABLE )
    {
      if ( type == OT_THREAD )
      {
        if ( !raw )
          return SQTable::Get(key, val: dest, this: this->_sharedstate->_thread_default_delegate._unVal.pTable);
      }
      else
      {
        if ( type == OT_CLASS )
          return SQClass::Get(this: self->_unVal.pClass, val: dest, key);
        if ( type == OT_WEAKREF && !raw )
          return SQTable::Get(key, val: dest, this: this->_sharedstate->_weakref_default_delegate._unVal.pTable);
      }
      return 0;
    }
    v16 = *(_DWORD *)(self->_unVal.nInteger + 24);
    if ( v16 == 0 )
    {
LABEL_53:
      if ( v5->_type == OT_TABLE && !raw )
        return SQTable::Get(key, val: dest, this: this->_sharedstate->_table_default_delegate._unVal.pTable);
      return 0;
    }
    v18._unVal.nInteger = *(_DWORD *)(self->_unVal.nInteger + 24);
    v18._type = OT_TABLE;
    ++*(_DWORD *)(v16 + 4);
    key_3 = SQVM::Get(this, self: &v18, key, dest, raw, fetchroot: false);
    if ( (v18._type & 0x8000000) != 0 )
    {
      v17.pTable = (SQTable *)v18._unVal;
      --*(_DWORD *)(v18._unVal.nInteger + 4);
      if ( *(int *)(v17.nInteger + 4) <= 0 )
        v18._unVal.pTable->Release(this: (struct SQTable *)v18._unVal.nInteger);
    }
    if ( key_3 != 0 )
      return 1;
    if ( raw )
      return 0;
    SQVM::Push(this, o: self);
    SQVM::Push(this, o: key);
    if ( !SQVM::CallMetaMethod(this, del: self->_unVal.pTable, mm: MT_GET, nparams: 2, outres: dest) )
    {
      v5 = self;
      goto LABEL_53;
    }
    return 1;
  }
  if ( self->_type == OT_GENERATOR )
  {
    if ( !raw )
      return SQTable::Get(key, val: dest, this: this->_sharedstate->_generator_default_delegate._unVal.pTable);
    return 0;
  }
  if ( type > OT_STRING )
  {
    if ( type == OT_ARRAY )
    {
      if ( !raw )
        return SQTable::Get(key, val: dest, this: this->_sharedstate->_array_default_delegate._unVal.pTable);
    }
    else if ( (type == OT_CLOSURE || type == OT_NATIVECLOSURE) && !raw )
    {
      return SQTable::Get(key, val: dest, this: this->_sharedstate->_closure_default_delegate._unVal.pTable);
    }
    return 0;
  }
  if ( type != OT_STRING )
  {
    v10 = type - 16777224;
    if ( (v10 == 0 || (v11 = v10 - 67108858) == 0 || v11 == 2) && !raw )
      return SQTable::Get(key, val: dest, this: this->_sharedstate->_number_default_delegate._unVal.pTable);
    return 0;
  }
  if ( (key->_type & 0x4000000) == 0 )
  {
    if ( !raw )
      return SQTable::Get(key, val: dest, this: this->_sharedstate->_string_default_delegate._unVal.pTable);
    return 0;
  }
  if ( key->_type == OT_FLOAT )
    fFloat = (int)key->_unVal.fFloat;
  else
    fFloat = key->_unVal.nInteger;
  v14.pTable = (SQTable *)self->_unVal;
  v15 = *(SQObjectPtr **)(v14.nInteger + 20);
  if ( (int)abs32(fFloat) < (int)v15 )
  {
    if ( fFloat < 0 )
    {
      v15 = (SQObjectPtr *)((char *)v15 - fFloat);
      fFloat = (int)v15;
    }
    SQObjectPtr::operator=(this: v15, a2: dest, i: *(char *)(v14.nInteger + fFloat + 28));
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005B200
// Name: public: bool SQVM::Set(struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQVM::Set(
        SQVM *this,
        const SQObjectPtr *self,
        const SQObjectPtr *key,
        const SQObjectPtr *val,
        bool fetchroot)
{
  tagSQObjectType type; // ecx
  int v8; // eax
  bool v9; // bl
  tagSQObjectType v11; // eax
  tagSQObjectType v12; // ecx
  const char *v13; // eax
  int top; // eax
  SQObjectPtr *vals; // edx
  SQObjectPtr *v16; // eax
  tagSQObjectValue v17; // edx
  _DWORD *v18; // ecx
  tagSQObjectType v19; // ebx
  tagSQObjectType v20; // edx
  int v21; // eax
  int v22; // ecx
  SQObjectPtr *v23; // eax
  tagSQObjectValue v24; // ebx
  _DWORD *v25; // ecx
  tagSQObjectType v26; // edx
  int v27; // eax
  int v28; // ecx
  SQObjectPtr *v29; // eax
  _DWORD *v30; // ecx
  tagSQObjectType v31; // edx
  bool v32; // zf
  tagSQObjectValue v33; // eax
  bool v34; // zf
  const char *v35; // eax
  tagSQObjectValue v36; // eax
  int stackbase; // eax
  SQObjectPtr *v38; // ecx
  tagSQObjectValue v39; // edx
  SQObjectPtr *v40; // eax
  const char *v41; // [esp-4h] [ebp-24h]
  SQObjectPtr v42; // [esp+10h] [ebp-10h] BYREF
  SQObjectPtr t; // [esp+18h] [ebp-8h] BYREF
  tagSQObjectType selfa; // [esp+28h] [ebp+8h]
  tagSQObjectType selfb; // [esp+28h] [ebp+8h]

  type = self->_type;
  if ( self->_type > OT_USERDATA )
  {
    if ( type == OT_INSTANCE )
    {
      if ( SQInstance::Set(val, this: self->_unVal.pInstance, key) != 0 )
        return 1;
      t._type = OT_NULL;
      t._unVal.nInteger = 0;
      SQVM::Push(this, o: self);
      SQVM::Push(this, o: key);
      SQVM::Push(this, o: val);
      if ( SQVM::CallMetaMethod(this, del: self->_unVal.pTable, mm: MT_SET, nparams: 3, outres: &t) )
      {
        v32 = (t._type & 0x8000000) == 0;
        goto LABEL_33;
      }
      v34 = (t._type & 0x8000000) == 0;
      goto LABEL_44;
    }
    goto LABEL_39;
  }
  if ( self->_type == OT_USERDATA )
    goto LABEL_15;
  if ( type == OT_ARRAY )
  {
    v11 = key->_type;
    if ( (key->_type & 0x4000000) != 0 )
    {
      if ( v11 == OT_FLOAT )
        return SQArray::Set(nidx: (int)key->_unVal.fFloat, val, this: self->_unVal.pArray);
      else
        return SQArray::Set(nidx: key->_unVal.nInteger, val, this: self->_unVal.pArray);
    }
    v41 = IdType2Name(type: v11);
    v13 = IdType2Name(type: v12);
    SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D46C._prev, s: v13, v41);
    return 0;
  }
  if ( type != OT_TABLE )
  {
LABEL_39:
    v35 = IdType2Name(type: self->_type);
    SQVM::Raise_Error(a1: this, this: (SQVM *)&stru_1009D46C._stack._size, s: v35);
    return 0;
  }
  if ( SQTable::Set(this: self->_unVal.pTable, key, val) != 0 )
    return 1;
  v8 = *(_DWORD *)(self->_unVal.nInteger + 24);
  if ( v8 != 0 )
  {
    v42._unVal.nInteger = *(_DWORD *)(self->_unVal.nInteger + 24);
    v42._type = OT_TABLE;
    ++*(_DWORD *)(v8 + 4);
    v9 = SQVM::Set(this, self: &v42, key, val, fetchroot: false);
    SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&v42);
    if ( v9 )
      return 1;
  }
LABEL_15:
  if ( *(_DWORD *)(self->_unVal.nInteger + 24) == 0 )
    goto LABEL_47;
  top = this->_top;
  vals = this->_stack._vals;
  this->_top = top + 1;
  v16 = &vals[top];
  v17.pTable = (SQTable *)self->_unVal;
  t._type = OT_NULL;
  t._unVal.nInteger = 0;
  v18 = &v16->_unVal.pTable->__vftable;
  v19 = v16->_type;
  v16->_unVal = v17;
  v20 = self->_type;
  v16->_type = self->_type;
  if ( (v20 & 0x8000000) != 0 )
    ++*(_DWORD *)(v16->_unVal.nInteger + 4);
  if ( (v19 & 0x8000000) != 0 && (int)--v18[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v18 + 8))(a1: v18);
  v21 = this->_top;
  v22 = v21 + 1;
  v23 = &this->_stack._vals[v21];
  this->_top = v22;
  v24.pTable = (SQTable *)key->_unVal;
  selfa = v23->_type;
  v25 = &v23->_unVal.pTable->__vftable;
  v23->_unVal = v24;
  v26 = key->_type;
  v23->_type = key->_type;
  if ( (v26 & 0x8000000) != 0 )
    ++*(_DWORD *)(v24.nInteger + 4);
  if ( (selfa & 0x8000000) != 0 && (int)--v25[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v25 + 8))(a1: v25);
  v27 = this->_top;
  v28 = v27 + 1;
  v29 = &this->_stack._vals[v27];
  this->_top = v28;
  selfb = v29->_type;
  v30 = &v29->_unVal.pTable->__vftable;
  v29->_unVal.nInteger = val->_unVal.nInteger;
  v31 = val->_type;
  v29->_type = val->_type;
  if ( (v31 & 0x8000000) != 0 )
    ++*(_DWORD *)(v29->_unVal.nInteger + 4);
  if ( (selfb & 0x8000000) != 0 && (int)--v30[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v30 + 8))(a1: v30);
  if ( !SQVM::CallMetaMethod(this, del: self->_unVal.pTable, mm: MT_SET, nparams: 3, outres: &t) )
  {
    v34 = (t._type & 0x8000000) == 0;
LABEL_44:
    if ( !v34 )
    {
      v36.pTable = (SQTable *)t._unVal;
      --*(_DWORD *)(t._unVal.nInteger + 4);
      if ( *(int *)(v36.nInteger + 4) <= 0 )
        t._unVal.pTable->Release(this: (struct SQTable *)t._unVal.nInteger);
    }
LABEL_47:
    if ( fetchroot )
    {
      stackbase = this->_stackbase;
      v38 = this->_stack._vals;
      v39.pTable = (SQTable *)v38[stackbase]._unVal;
      v40 = &v38[stackbase];
      if ( v39.nInteger == self->_unVal.nInteger && v40->_type == self->_type )
        return SQTable::Set(this: this->_roottable._unVal.pTable, key, val);
    }
    return 0;
  }
  v32 = (t._type & 0x8000000) == 0;
LABEL_33:
  if ( !v32 )
  {
    v33.pTable = (SQTable *)t._unVal;
    --*(_DWORD *)(t._unVal.nInteger + 4);
    if ( *(int *)(v33.nInteger + 4) <= 0 )
      t._unVal.pTable->Release(this: (struct SQTable *)t._unVal.nInteger);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005B530
// Name: public: bool SQVM::Clone(struct SQObjectPtr const __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQVM::Clone(SQVM *this, SQVM *self, SQObjectPtr *target, SQObjectPtr *targeta)
{
  SQObjectPtr *v4; // edi
  tagSQObjectType type; // eax
  SQInstance *v7; // eax
  SQArray *v8; // esi
  tagSQObjectType top; // eax
  tagSQObjectType v10; // ecx
  int *v11; // eax
  _DWORD *v12; // ecx
  tagSQObjectType v13; // eax
  tagSQObjectType vals; // edx
  const SQObjectPtr *v15; // ecx
  tagSQObjectType *v16; // eax
  tagSQObjectValue v17; // edx
  _DWORD *v18; // ecx
  tagSQObjectType v19; // edi
  tagSQObjectType v20; // edx
  _DWORD *v21; // ecx
  SQTable *v22; // eax
  tagSQObjectValue v23; // edi
  tagSQObjectType v24; // edx
  _DWORD *v25; // ecx
  tagSQObjectValue v26; // eax
  int newobj; // [esp+10h] [ebp-14h]
  SQObjectPtr temp_reg; // [esp+18h] [ebp-Ch] BYREF
  int selfb; // [esp+30h] [ebp+Ch]
  const SQObjectPtr *selfa; // [esp+30h] [ebp+Ch]

  v4 = target;
  type = target->_type;
  temp_reg._type = OT_NULL;
  temp_reg._unVal.nInteger = 0;
  if ( type == OT_ARRAY )
  {
    v23.pTable = (SQTable *)target->_unVal;
    v8 = SQArray::Create(ss: *(SQSharedState **)(v23.nInteger + 20), nInitialSize: *(_DWORD *)(v23.nInteger + 28));
    sqvector<SQObjectPtr>::copy(this: &v8->_values, v: (const sqvector<SQObjectPtr> *)(v23.nInteger + 24));
    ++v8->_uiRef;
    v24 = targeta->_type;
    v25 = &targeta->_unVal.pTable->__vftable;
    targeta->_unVal.nInteger = (int)v8;
    targeta->_type = OT_ARRAY;
    ++v8->_uiRef;
    if ( (v24 & 0x8000000) != 0 && (int)--v25[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v25 + 8))(a1: v25);
  }
  else
  {
    if ( type == OT_TABLE )
    {
      v22 = SQTable::Clone(this: target->_unVal.pTable, thisa: target->_unVal.pTable);
      ++v22->_uiRef;
      ++v22->_uiRef;
      --v22->_uiRef;
      v8 = (SQArray *)v22;
      newobj = 167772192;
      if ( v22->_uiRef <= 0 )
        v22->Release(this: v22);
    }
    else
    {
      if ( type != OT_INSTANCE )
        return 0;
      v7 = SQInstance::Clone((SQInstance *)this, a2: target->_unVal.pInstance, ss: self->_sharedstate);
      ++v7->_uiRef;
      ++v7->_uiRef;
      --v7->_uiRef;
      v8 = (SQArray *)v7;
      newobj = 167804928;
      if ( v7->_uiRef <= 0 )
        v7->Release(this: v7);
      v4 = target;
    }
    if ( v8->_values._vals != nullptr )
    {
      top = self->_top;
      v10 = top + 1;
      v11 = (int *)&self->_stack._vals[top];
      self->_top = v10;
      selfb = *v11;
      v12 = (_DWORD *)v11[1];
      v11[1] = (int)v8;
      *v11 = newobj;
      ++v8->_uiRef;
      if ( (selfb & 0x8000000) != 0 && (int)--v12[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
      v13 = self->_top;
      vals = (tagSQObjectType)self->_stack._vals;
      self->_top = v13 + 1;
      v15 = *(const SQObjectPtr **)(vals + 8 * v13);
      v16 = (tagSQObjectType *)(vals + 8 * v13);
      v17.pTable = (SQTable *)v4->_unVal;
      selfa = v15;
      v18 = *((_DWORD **)v16 + 1);
      v16[1] = (tagSQObjectType)v17.pTable;
      v19 = v4->_type;
      *v16 = v19;
      if ( (v19 & 0x8000000) != 0 )
        ++*(_DWORD *)(v17.nInteger + 4);
      if ( ((unsigned int)selfa & 0x8000000) != 0 && (int)--v18[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v18 + 8))(a1: v18);
      SQVM::CallMetaMethod(this: self, del: (SQDelegable *)v8, mm: MT_CLONED, nparams: 2, outres: &temp_reg);
    }
    v20 = targeta->_type;
    v21 = &targeta->_unVal.pTable->__vftable;
    targeta->_type = newobj;
    targeta->_unVal.nInteger = (int)v8;
    ++v8->_uiRef;
    if ( (v20 & 0x8000000) != 0 && (int)--v21[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v21 + 8))(a1: v21);
  }
  if ( --v8->_uiRef <= 0 )
    v8->Release(this: v8);
  if ( (temp_reg._type & 0x8000000) != 0 )
  {
    v26.pTable = (SQTable *)temp_reg._unVal;
    --*(_DWORD *)(temp_reg._unVal.nInteger + 4);
    if ( *(int *)(v26.nInteger + 4) <= 0 )
      temp_reg._unVal.pTable->Release(this: (struct SQTable *)temp_reg._unVal.nInteger);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005B760
// Name: public: bool SQVM::NewSlot(struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::NewSlot@<al>(
        SQVM *this@<ecx>,
        int a2@<eax>,
        const SQObjectPtr *self,
        const SQObjectPtr *key,
        const SQObjectPtr *val,
        bool bstatic)
{
  const SQObjectPtr *v7; // esi
  tagSQObjectType type; // ecx
  tagSQObjectType v11; // ecx
  const char *v12; // eax
  SQTable *pTable; // eax
  tagSQObjectValue v14; // eax
  SQVM *v15; // ecx
  SQString *v16; // esi
  const char *v17; // [esp-4h] [ebp-1Ch]
  const char *v18; // [esp+0h] [ebp-18h]
  SQObjectPtr res; // [esp+10h] [ebp-8h] BYREF
  bool rawcall_3; // [esp+23h] [ebp+Bh]

  v7 = key;
  if ( key->_type == OT_NULL )
  {
    SQVM::Raise_Error(a1: (_DWORD *)a2, this: (SQVM *)&stru_1009D46C._top, s: v18);
    return 0;
  }
  type = self->_type;
  if ( self->_type != OT_CLASS )
  {
    if ( type != OT_TABLE )
    {
      if ( type != OT_INSTANCE )
      {
        v17 = IdType2Name(type: key->_type);
        v12 = IdType2Name(type: v11);
        SQVM::Raise_Error(a1: (_DWORD *)a2, this: (SQVM *)&stru_1009D46C._prev, s: v12, v17);
        return 0;
      }
      res._type = OT_NULL;
      res._unVal.nInteger = 0;
      SQVM::Push(this: (SQVM *)a2, o: self);
      SQVM::Push(this: (SQVM *)a2, o: key);
      SQVM::Push(this: (SQVM *)a2, o: val);
      if ( !SQVM::CallMetaMethod(this: (SQVM *)a2, del: self->_unVal.pTable, mm: MT_NEWSLOT, nparams: 3, outres: &res) )
      {
        SQVM::Raise_Error(a1: (_DWORD *)a2, this: (SQVM *)&stru_1009D46C._debughook, s: v18);
        SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&res);
        return 0;
      }
      SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&res);
      return 1;
    }
    pTable = self->_unVal.pTable;
    rawcall_3 = true;
    if ( pTable->_delegate == nullptr )
      goto LABEL_19;
    res._type = OT_NULL;
    res._unVal.nInteger = 0;
    if ( SQTable::Get(key, val: &res, this: pTable) == 0 )
    {
      SQVM::Push(this: (SQVM *)a2, o: self);
      SQVM::Push(this: (SQVM *)a2, o: key);
      SQVM::Push(this: (SQVM *)a2, o: val);
      rawcall_3 = !SQVM::CallMetaMethod(
                     this: (SQVM *)a2,
                     del: self->_unVal.pTable,
                     mm: MT_NEWSLOT,
                     nparams: 3,
                     outres: &res);
    }
    if ( (res._type & 0x8000000) != 0 )
    {
      v14.pTable = (SQTable *)res._unVal;
      --*(_DWORD *)(res._unVal.nInteger + 4);
      if ( *(int *)(v14.nInteger + 4) <= 0 )
        res._unVal.pTable->Release(this: (struct SQTable *)res._unVal.nInteger);
    }
    if ( rawcall_3 )
    {
      v7 = key;
LABEL_19:
      SQTable::NewSlot(this: self->_unVal.pTable, key: v7, val);
      return 1;
    }
    return 1;
  }
  if ( SQClass::NewSlot(
         this: *(SQClass **)(a2 + 148),
         a2: self->_unVal.nInteger,
         ss: *(SQSharedState **)(a2 + 148),
         key,
         val,
         bstatic) != 0 )
    return 1;
  if ( *(_BYTE *)(self->_unVal.nInteger + 84) != 0 )
  {
    SQVM::Raise_Error(a1: (_DWORD *)a2, this: (SQVM *)&stru_1009D46C._foreignptr, s: v18);
    return 0;
  }
  else
  {
    v16 = SQVM::PrintObjVal(this: v15, o: (SQVM *)a2, oa: key);
    ++v16->_uiRef;
    SQVM::Raise_Error(a1: (_DWORD *)a2, this: (SQVM *)&stru_1009D538, s: v16->_val);
    if ( --v16->_uiRef <= 0 )
      v16->Release(this: v16);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B970
// Name: public: bool SQVM::DeleteSlot(struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQVM::DeleteSlot@<al>(
        SQVM *this@<ecx>,
        SQVM *a2@<eax>,
        const SQObjectPtr *self,
        const SQObjectPtr *key,
        SQObjectPtr *res)
{
  const char *v7; // eax
  tagSQObjectValue v9; // eax
  int top; // eax
  SQObjectPtr *vals; // edx
  _DWORD *v12; // ecx
  tagSQObjectType type; // esi
  tagSQObjectType *p_type; // eax
  tagSQObjectType v15; // edx
  int v16; // eax
  int v17; // ecx
  SQObjectPtr *v18; // eax
  tagSQObjectValue v19; // esi
  _DWORD *v20; // ecx
  tagSQObjectType v21; // edx
  tagSQObjectType v22; // esi
  tagSQObjectValue v23; // edi
  tagSQObjectType v24; // edx
  _DWORD *v25; // ecx
  tagSQObjectValue v26; // eax
  tagSQObjectValue v27; // eax
  const char *v28; // eax
  SQObjectPtr t; // [esp+10h] [ebp-Ch] BYREF
  tagSQObjectType selfa; // [esp+24h] [ebp+8h]

  if ( self->_type != OT_TABLE && self->_type != OT_USERDATA && self->_type != OT_INSTANCE )
  {
    v7 = IdType2Name(type: self->_type);
    SQVM::Raise_Error(a1: a2, this: (SQVM *)&stru_1009D538._roottable._unVal, s: v7);
    return 0;
  }
  v9.pTable = (SQTable *)self->_unVal;
  t._type = OT_NULL;
  t._unVal.nInteger = 0;
  if ( *(_DWORD *)(v9.nInteger + 24) != 0 )
  {
    top = a2->_top;
    vals = a2->_stack._vals;
    a2->_top = top + 1;
    v12 = &vals[top]._unVal.pTable->__vftable;
    type = vals[top]._type;
    p_type = &vals[top]._type;
    p_type[1] = (tagSQObjectType)self->_unVal.pTable;
    v15 = self->_type;
    *p_type = self->_type;
    if ( (v15 & 0x8000000) != 0 )
      ++*(_DWORD *)(*((_DWORD *)p_type + 1) + 4);
    if ( (type & 0x8000000) != 0 && (int)--v12[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
    v16 = a2->_top;
    v17 = v16 + 1;
    v18 = &a2->_stack._vals[v16];
    a2->_top = v17;
    v19.pTable = (SQTable *)key->_unVal;
    selfa = v18->_type;
    v20 = &v18->_unVal.pTable->__vftable;
    v18->_unVal = v19;
    v21 = key->_type;
    v18->_type = key->_type;
    if ( (v21 & 0x8000000) != 0 )
      ++*(_DWORD *)(v19.nInteger + 4);
    if ( (selfa & 0x8000000) != 0 && (int)--v20[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v20 + 8))(a1: v20);
    if ( SQVM::CallMetaMethod(this: a2, del: self->_unVal.pTable, mm: MT_DELSLOT, nparams: 2, outres: &t) )
      goto LABEL_20;
  }
  if ( self->_type == OT_TABLE )
  {
    if ( SQTable::Get(key, val: &t, this: self->_unVal.pTable) != 0 )
    {
      SQTable::Remove(key, this: self->_unVal.pTable);
LABEL_20:
      v22 = t._type;
      v23.pTable = (SQTable *)t._unVal;
      v24 = res->_type;
      v25 = &res->_unVal.pTable->__vftable;
      res->_unVal.nInteger = t._unVal.nInteger;
      res->_type = v22;
      if ( (v22 & 0x8000000) != 0 )
        ++*(_DWORD *)(v23.nInteger + 4);
      if ( (v24 & 0x8000000) != 0 && (int)--v25[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v25 + 8))(a1: v25);
      if ( (t._type & 0x8000000) != 0 )
      {
        v26.pTable = (SQTable *)t._unVal;
        --*(_DWORD *)(t._unVal.nInteger + 4);
        if ( *(int *)(v26.nInteger + 4) <= 0 )
          t._unVal.pTable->Release(this: (struct SQTable *)t._unVal.nInteger);
      }
      return 1;
    }
    SQVM::Raise_IdxError(this: a2, o: &key->tagSQObject);
  }
  else
  {
    v28 = IdType2Name(type: self->_type);
    SQVM::Raise_Error(a1: a2, this: (SQVM *)&stru_1009D538._stack._size, s: v28);
  }
  if ( (t._type & 0x8000000) != 0 )
  {
    v27.pTable = (SQTable *)t._unVal;
    --*(_DWORD *)(t._unVal.nInteger + 4);
    if ( *(int *)(v27.nInteger + 4) <= 0 )
      t._unVal.pTable->Release(this: (struct SQTable *)t._unVal.nInteger);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005BB50
// Name: public: bool SQVM::Call(struct SQObjectPtr __near &,int,int,struct SQObjectPtr __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQVM::Call(
        SQVM *this,
        SQObjectPtr *closure,
        sqvector<SQObjectPtr> *nparams,
        int stackbase,
        SQObjectPtr *outres,
        unsigned int raiseerror)
{
  tagSQObjectType type; // ecx
  bool v9; // bl
  tagSQObjectValue v10; // eax
  tagSQObjectValue v11; // eax
  tagSQObjectValue v12; // eax
  tagSQObjectValue v13; // eax
  SQClass *pClass; // [esp-8h] [ebp-28h]
  bool suspend; // [esp+Fh] [ebp-11h] BYREF
  SQObjectPtr constr; // [esp+10h] [ebp-10h] BYREF
  SQObjectPtr temp; // [esp+18h] [ebp-8h] BYREF

  type = closure->_type;
  if ( closure->_type == OT_CLOSURE )
    return SQVM::Execute(
             closure,
             et: ET_CALL,
             this,
             target: (SQGenerator *)(this->_top - (_DWORD)nparams),
             nargs: nparams,
             stackbase,
             outres,
             raiseerror);
  if ( type == OT_NATIVECLOSURE )
    return SQVM::CallNative(
             this: (SQVM *)stackbase,
             nclosure: (SQObjectPtr *)this,
             nargs: (tagSQObjectValue *)closure->_unVal.pTable,
             stackbase: (int)nparams,
             retval: stackbase,
             suspend: outres,
             suspenda: &suspend);
  if ( type != OT_CLASS )
    return 0;
  pClass = closure->_unVal.pClass;
  constr._type = OT_NULL;
  constr._unVal.nInteger = 0;
  temp._type = OT_NULL;
  temp._unVal.nInteger = 0;
  SQVM::CreateClassInstance(inst: outres, a2: (SQClass *)&constr, this, theclass: pClass, constructor: &constr);
  if ( constr._type == OT_NULL )
  {
    if ( (temp._type & 0x8000000) != 0 )
    {
      v12.pTable = (SQTable *)temp._unVal;
      --*(_DWORD *)(temp._unVal.nInteger + 4);
      if ( *(int *)(v12.nInteger + 4) <= 0 )
        temp._unVal.pTable->Release(this: (struct SQTable *)temp._unVal.nInteger);
    }
    if ( (constr._type & 0x8000000) != 0 )
    {
      v13.pTable = (SQTable *)constr._unVal;
      --*(_DWORD *)(constr._unVal.nInteger + 4);
      if ( *(int *)(v13.nInteger + 4) <= 0 )
        constr._unVal.pTable->Release(this: (struct SQTable *)constr._unVal.nInteger);
    }
    return 1;
  }
  else
  {
    SQObjectPtr::operator=(this: &this->_stack._vals[stackbase], obj: outres);
    v9 = SQVM::Call(this, closure: &constr, (int)nparams, stackbase, outres: &temp, raiseerror);
    if ( (temp._type & 0x8000000) != 0 )
    {
      v10.pTable = (SQTable *)temp._unVal;
      --*(_DWORD *)(temp._unVal.nInteger + 4);
      if ( *(int *)(v10.nInteger + 4) <= 0 )
        temp._unVal.pTable->Release(this: (struct SQTable *)temp._unVal.nInteger);
    }
    if ( (constr._type & 0x8000000) != 0 )
    {
      v11.pTable = (SQTable *)constr._unVal;
      --*(_DWORD *)(constr._unVal.nInteger + 4);
      if ( *(int *)(v11.nInteger + 4) <= 0 )
        constr._unVal.pTable->Release(this: (struct SQTable *)constr._unVal.nInteger);
    }
    return v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BCD0
// Name: public: bool SQVM::CallMetaMethod(struct SQDelegable __near *,enum SQMetaMethod,int,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQVM::CallMetaMethod(
        SQVM *this,
        SQDelegable *del,
        SQMetaMethod mm,
        sqvector<SQObjectPtr> *nparams,
        SQObjectPtr *outres)
{
  bool (__thiscall *GetMetaMethod)(SQDelegable *, SQVM *, SQMetaMethod, SQObjectPtr *); // eax
  tagSQObjectValue v7; // eax
  tagSQObjectValue v9; // eax
  SQObjectPtr closure; // [esp+8h] [ebp-8h] BYREF

  GetMetaMethod = del->GetMetaMethod;
  closure._type = OT_NULL;
  closure._unVal.nInteger = 0;
  if ( GetMetaMethod(this: del, a2: this, a3: mm, a4: &closure)
    && SQVM::Call(this, &closure, nparams, stackbase: this->_top - (_DWORD)nparams, outres, raiseerror: 0) != 0 )
  {
    SQVM::Pop(this, n: (int)nparams);
    if ( (closure._type & 0x8000000) != 0 )
    {
      v7.pTable = (SQTable *)closure._unVal;
      --*(_DWORD *)(closure._unVal.nInteger + 4);
      if ( *(int *)(v7.nInteger + 4) <= 0 )
        closure._unVal.pTable->Release(this: (struct SQTable *)closure._unVal.nInteger);
    }
    return 1;
  }
  else
  {
    SQVM::Pop(this, n: (int)nparams);
    if ( (closure._type & 0x8000000) != 0 )
    {
      v9.pTable = (SQTable *)closure._unVal;
      --*(_DWORD *)(closure._unVal.nInteger + 4);
      if ( *(int *)(v9.nInteger + 4) <= 0 )
        closure._unVal.pTable->Release(this: (struct SQTable *)closure._unVal.nInteger);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BD80
// Name: public: void SQVM::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQVM::Remove(SQVM *this@<esi>, int n@<eax>)
{
  int v2; // eax
  int i; // edi
  SQObjectPtr *vals; // edx
  _DWORD *v5; // ecx
  tagSQObjectType type; // ebx
  SQObjectPtr *v7; // eax
  tagSQObjectType v8; // edx
  SQObjectPtr *v9; // ecx
  int top; // eax
  tagSQObjectType v11; // edx
  SQObjectPtr *v12; // eax
  _DWORD *v13; // ecx
  tagSQObjectType v14; // edi

  if ( n < 0 )
    v2 = this->_top + n;
  else
    v2 = n + this->_stackbase - 1;
  for ( i = v2; i < this->_top; ++i )
  {
    vals = this->_stack._vals;
    v5 = &vals[i]._unVal.pTable->__vftable;
    type = vals[i]._type;
    v7 = &vals[i];
    v7->_unVal.nInteger = v7[1]._unVal.nInteger;
    v8 = v7[1]._type;
    v7->_type = v8;
    if ( (v8 & 0x8000000) != 0 )
      ++*(_DWORD *)(v7->_unVal.nInteger + 4);
    if ( (type & 0x8000000) != 0 && (int)--v5[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v5 + 8))(a1: v5);
  }
  v9 = this->_stack._vals;
  top = this->_top;
  v11 = v9[top]._type;
  v12 = &v9[top];
  v13 = &v12->_unVal.pTable->__vftable;
  v12->_unVal.nInteger = _null_._unVal.nInteger;
  v14 = _null_._type;
  v12->_type = _null_._type;
  if ( (v14 & 0x8000000) != 0 )
    ++*(_DWORD *)(v12->_unVal.nInteger + 4);
  if ( (v11 & 0x8000000) != 0 )
  {
    if ( (int)--v13[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
    --this->_top;
  }
  else
  {
    --this->_top;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BE40
// Name: public: void SQVM::Pop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQVM::Pop(SQVM *this)
{
  int v1; // eax
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // edx
  SQObjectPtr *v4; // eax
  _DWORD *v5; // ecx

  v1 = this->_top - 1;
  this->_top = v1;
  vals = this->_stack._vals;
  type = vals[v1]._type;
  v4 = &vals[v1];
  v5 = &v4->_unVal.pTable->__vftable;
  *v4 = _null_;
  if ( (v4->_type & 0x8000000) != 0 )
    ++*(_DWORD *)(v4->_unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v5[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v5 + 8))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1005BE90
// Name: public: void SQVM::Pop(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQVM::Pop(SQVM *this@<esi>, int n@<eax>)
{
  SQObjectPtr *vals; // ecx
  int v3; // eax
  tagSQObjectType type; // edx
  SQObjectPtr *v5; // eax
  _DWORD *v6; // ecx
  tagSQObjectType v7; // ebx
  int i; // [esp+0h] [ebp-4h]

  if ( n > 0 )
  {
    for ( i = n; i != 0; --i )
    {
      vals = this->_stack._vals;
      v3 = this->_top - 1;
      this->_top = v3;
      type = vals[v3]._type;
      v5 = &vals[v3];
      v6 = &v5->_unVal.pTable->__vftable;
      v5->_unVal.nInteger = _null_._unVal.nInteger;
      v7 = _null_._type;
      v5->_type = _null_._type;
      if ( (v7 & 0x8000000) != 0 )
        ++*(_DWORD *)(v5->_unVal.nInteger + 4);
      if ( (type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BF00
// Name: public: void SQVM::Push(struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQVM::Push(SQVM *this@<eax>, const SQObjectPtr *o@<edx>)
{
  int top; // ecx
  SQObjectPtr *vals; // eax
  tagSQObjectType type; // esi
  SQObjectPtr *v5; // eax
  _DWORD *v6; // ecx
  tagSQObjectValue v7; // edi
  tagSQObjectType v8; // edx

  top = this->_top;
  this->_top = top + 1;
  vals = this->_stack._vals;
  type = vals[top]._type;
  v5 = &vals[top];
  v6 = &v5->_unVal.pTable->__vftable;
  v7.pTable = (SQTable *)o->_unVal;
  v5->_unVal = v7;
  v8 = o->_type;
  v5->_type = v8;
  if ( (v8 & 0x8000000) != 0 )
    ++*(_DWORD *)(v7.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
}
