// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/squirrel/sqfuncstate.cpp
// Functions: 26
// ============================================================

#include "vscript\languages\squirrel\squirrel\sqfuncstate.h"

//------------------------------------------------------------------------------
// Address: 0x100482A0
// Name: public: SQOuterVar::SQOuterVar(struct SQObjectPtr const __near &,struct SQObjectPtr const __near &,enum SQOuterType)
// Source: json
//------------------------------------------------------------------------------
SQOuterVar *__userpurge SQOuterVar::SQOuterVar@<eax>(
        SQOuterVar *this@<esi>,
        const SQObjectPtr *name@<eax>,
        const SQObjectPtr *src@<edi>,
        SQOuterType t)
{
  _DWORD *v4; // ecx
  tagSQObjectType type; // edx
  tagSQObjectValue v6; // ebx
  tagSQObjectType v7; // eax
  _DWORD *v8; // ecx
  tagSQObjectType v9; // edx
  tagSQObjectType v10; // eax

  this->_name._unVal.nInteger = 0;
  this->_name._type = OT_NULL;
  this->_src._type = OT_NULL;
  this->_src._unVal.nInteger = 0;
  v4 = &this->_name._unVal.pTable->__vftable;
  type = this->_name._type;
  v6.pTable = (SQTable *)name->_unVal;
  this->_name._unVal = v6;
  v7 = name->_type;
  this->_name._type = v7;
  if ( (v7 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
  v8 = &this->_src._unVal.pTable->__vftable;
  v9 = this->_src._type;
  this->_src._unVal.nInteger = src->_unVal.nInteger;
  v10 = src->_type;
  this->_src._type = src->_type;
  if ( (v10 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_src._unVal.nInteger + 4);
  if ( (v9 & 0x8000000) != 0 )
  {
    if ( (int)--v8[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
    this->_type = t;
    return this;
  }
  else
  {
    this->_type = t;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048350
// Name: public: SQOuterVar::SQOuterVar(struct SQOuterVar const __near &)
// Source: json
//------------------------------------------------------------------------------
SQOuterVar *__usercall SQOuterVar::SQOuterVar@<eax>(SQOuterVar *this@<esi>, const SQOuterVar *ov@<eax>)
{
  _DWORD *v3; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v5; // eax
  tagSQObjectValue v6; // eax
  _DWORD *v7; // ecx
  tagSQObjectType v8; // edx
  tagSQObjectType v9; // edi

  this->_name._unVal.nInteger = 0;
  this->_name._type = OT_NULL;
  this->_src._type = OT_NULL;
  this->_src._unVal.nInteger = 0;
  this->_type = ov->_type;
  v3 = &this->_src._unVal.pTable->__vftable;
  type = this->_src._type;
  this->_src._unVal.nInteger = ov->_src._unVal.nInteger;
  v5 = ov->_src._type;
  this->_src._type = v5;
  if ( (v5 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_src._unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v3[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(a1: v3);
  v6.pTable = (SQTable *)ov->_name._unVal;
  v7 = &this->_name._unVal.pTable->__vftable;
  v8 = this->_name._type;
  this->_name._unVal = v6;
  v9 = ov->_name._type;
  this->_name._type = v9;
  if ( (v9 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6.nInteger + 4);
  if ( (v8 & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100483E0
// Name: public: static struct SQFunctionProto __near * SQFunctionProto::Create(int,int,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
SQFunctionProto *__usercall SQFunctionProto::Create@<eax>(
        int noutervalues@<ecx>,
        int nlocalvarinfos@<eax>,
        int ninstructions,
        int nliterals,
        int nparameters,
        int nfunctions,
        int nlineinfos,
        int ndefaultparams)
{
  SQFunctionProto *result; // eax
  SQObjectPtr *v11; // ecx
  SQObjectPtr *v12; // ecx
  SQObjectPtr *v13; // ecx
  SQOuterVar *v14; // ecx
  SQLineInfo *v15; // ecx
  SQLocalVarInfo *v16; // ecx
  int v17; // ecx
  SQObjectPtr *v18; // edx
  int i; // edx
  SQObjectPtr *v20; // ecx
  int j; // edx
  SQObjectPtr *v22; // ecx
  int v23; // edx
  int v24; // esi
  SQOuterVar *v25; // ecx
  int v26; // edx
  int v27; // esi
  SQLocalVarInfo *v28; // ecx

  result = (SQFunctionProto *)_g_pMemAlloc->Alloc_2(
                                this: _g_pMemAlloc,
                                a2: 4
                              * (noutervalues
                               + nlocalvarinfos
                               + ndefaultparams
                               + 4 * (noutervalues + nlocalvarinfos)
                               + 2 * (nlineinfos + nfunctions + nparameters + ninstructions + nliterals)
                               + 24));
  if ( result != nullptr )
  {
    result->_uiRef = 0;
    result->_weakref = nullptr;
    result->__vftable = (SQFunctionProto_vtbl *)&SQFunctionProto::`vftable';
    result->_sourcename._type = OT_NULL;
    result->_sourcename._unVal.nInteger = 0;
    result->_name._type = OT_NULL;
    result->_name._unVal.nInteger = 0;
    result->_stacksize = 0;
    result->_bgenerator = false;
  }
  result->_ninstructions = ninstructions;
  v11 = (SQObjectPtr *)&result->_instructions[ninstructions];
  result->_literals = v11;
  v12 = &v11[nliterals];
  result->_parameters = v12;
  v13 = &v12[nparameters];
  result->_functions = v13;
  result->_nparameters = nparameters;
  v14 = (SQOuterVar *)&v13[nfunctions];
  result->_outervalues = v14;
  result->_noutervalues = noutervalues;
  v15 = (SQLineInfo *)&v14[noutervalues];
  result->_lineinfos = v15;
  v16 = (SQLocalVarInfo *)&v15[nlineinfos];
  result->_localvarinfos = v16;
  result->_nlocalvarinfos = nlocalvarinfos;
  result->_defaultparams = (int *)&v16[nlocalvarinfos];
  result->_nlineinfos = nlineinfos;
  result->_ndefaultparams = ndefaultparams;
  v17 = 0;
  result->_nfunctions = nfunctions;
  for ( result->_nliterals = nliterals; v17 < result->_nliterals; ++v17 )
  {
    v18 = &result->_literals[v17];
    if ( v18 != nullptr )
    {
      v18->_type = OT_NULL;
      v18->_unVal.nInteger = 0;
    }
  }
  for ( i = 0; i < result->_nparameters; ++i )
  {
    v20 = &result->_parameters[i];
    if ( v20 != nullptr )
    {
      v20->_type = OT_NULL;
      v20->_unVal.nInteger = 0;
    }
  }
  for ( j = 0; j < result->_nfunctions; ++j )
  {
    v22 = &result->_functions[j];
    if ( v22 != nullptr )
    {
      v22->_type = OT_NULL;
      v22->_unVal.nInteger = 0;
    }
  }
  v23 = 0;
  if ( result->_noutervalues > 0 )
  {
    v24 = 0;
    do
    {
      v25 = &result->_outervalues[v24];
      if ( v25 != nullptr )
      {
        v25->_name._type = OT_NULL;
        v25->_name._unVal.nInteger = 0;
        v25->_src._type = OT_NULL;
        v25->_src._unVal.nInteger = 0;
      }
      ++v23;
      ++v24;
    }
    while ( v23 < result->_noutervalues );
  }
  v26 = 0;
  if ( result->_nlocalvarinfos > 0 )
  {
    v27 = 0;
    do
    {
      v28 = &result->_localvarinfos[v27];
      if ( v28 != nullptr )
      {
        v28->_name._type = OT_NULL;
        v28->_name._unVal.nInteger = 0;
        v28->_start_op = 0;
        v28->_end_op = 0;
      }
      ++v26;
      ++v27;
    }
    while ( v26 < result->_nlocalvarinfos );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048560
// Name: public: virtual void SQFunctionProto::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQFunctionProto::Release(SQFunctionProto *this)
{
  int i; // edi
  SQObjectPtr *v3; // ecx
  tagSQObjectValue v4; // eax
  int j; // edi
  SQObjectPtr *parameters; // ecx
  bool v7; // zf
  SQObjectPtr *v8; // ecx
  tagSQObjectValue v9; // eax
  int k; // edi
  SQObjectPtr *functions; // ecx
  SQObjectPtr *v12; // ecx
  tagSQObjectValue v13; // eax
  int v14; // ebx
  SQOuterVar *v15; // edi
  tagSQObjectValue v16; // eax
  tagSQObjectValue v17; // eax
  int v18; // ebx
  int v19; // edi
  SQLocalVarInfo *localvarinfos; // eax
  tagSQObjectValue v21; // ecx
  int nl; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < this->_nliterals; ++i )
  {
    v3 = &this->_literals[i];
    if ( (v3->_type & 0x8000000) != 0 )
    {
      v4.pTable = (SQTable *)v3->_unVal;
      if ( (int)--*(_DWORD *)(v4.nInteger + 4) <= 0 )
        v3->_unVal.pTable->Release(this: (struct SQTable *)v3->_unVal.nInteger);
    }
  }
  for ( j = 0; j < this->_nparameters; ++j )
  {
    parameters = this->_parameters;
    v7 = (parameters[j]._type & 0x8000000) == 0;
    v8 = &parameters[j];
    if ( !v7 )
    {
      v9.pTable = (SQTable *)v8->_unVal;
      if ( (int)--*(_DWORD *)(v9.nInteger + 4) <= 0 )
        v8->_unVal.pTable->Release(this: (struct SQTable *)v8->_unVal.nInteger);
    }
  }
  for ( k = 0; k < this->_nfunctions; ++k )
  {
    functions = this->_functions;
    v7 = (functions[k]._type & 0x8000000) == 0;
    v12 = &functions[k];
    if ( !v7 )
    {
      v13.pTable = (SQTable *)v12->_unVal;
      if ( (int)--*(_DWORD *)(v13.nInteger + 4) <= 0 )
        v12->_unVal.pTable->Release(this: (struct SQTable *)v12->_unVal.nInteger);
    }
  }
  v14 = 0;
  for ( nl = 0; nl < this->_noutervalues; ++nl )
  {
    v15 = &this->_outervalues[v14];
    if ( (v15->_src._type & 0x8000000) != 0 )
    {
      v16.pTable = (SQTable *)v15->_src._unVal;
      if ( (int)--*(_DWORD *)(v16.nInteger + 4) <= 0 )
        v15->_src._unVal.pTable->Release(this: (struct SQTable *)v15->_src._unVal.nInteger);
    }
    if ( (v15->_name._type & 0x8000000) != 0 )
    {
      v17.pTable = (SQTable *)v15->_name._unVal;
      if ( (int)--*(_DWORD *)(v17.nInteger + 4) <= 0 )
        v15->_name._unVal.pTable->Release(this: (struct SQTable *)v15->_name._unVal.nInteger);
    }
    ++v14;
  }
  v18 = 0;
  if ( this->_nlocalvarinfos > 0 )
  {
    v19 = 0;
    do
    {
      localvarinfos = this->_localvarinfos;
      if ( (localvarinfos[v19]._name._type & 0x8000000) != 0 )
      {
        v21.pTable = (SQTable *)localvarinfos[v19]._name._unVal;
        if ( (int)--*(_DWORD *)(v21.nInteger + 4) <= 0 )
          localvarinfos[v19]._name._unVal.pTable->Release(this: (struct SQTable *)localvarinfos[v19]._name._unVal.nInteger);
      }
      ++v18;
      ++v19;
    }
    while ( v18 < this->_nlocalvarinfos );
  }
  ((void (__thiscall *)(SQFunctionProto *, _DWORD))this->dtr_SQRefCounted)(a1: this, a2: 0);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10048700
// Name: public: virtual SQFunctionProto::~SQFunctionProto(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQFunctionProto::~SQFunctionProto(SQFunctionProto *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( (a2[5] & 0x8000000) != 0 )
  {
    v2 = a2[6];
    if ( (int)--*(_DWORD *)(v2 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)a2[6] + 8))(a1: a2[6]);
  }
  if ( (a2[3] & 0x8000000) != 0 )
  {
    v3 = a2[4];
    if ( (int)--*(_DWORD *)(v3 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)a2[4] + 8))(a1: a2[4]);
  }
  v4 = a2[2];
  *a2 = &SQRefCounted::`vftable';
  if ( v4 != 0 )
  {
    *(_DWORD *)(v4 + 12) = 16777217;
    *(_DWORD *)(a2[2] + 16) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048760
// Name: public: SQOuterVar::~SQOuterVar(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQOuterVar::~SQOuterVar(SQOuterVar *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // eax
  int v3; // eax

  if ( (a2[3] & 0x8000000) != 0 )
  {
    v2 = a2[4];
    if ( (int)--*(_DWORD *)(v2 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)a2[4] + 8))(a1: a2[4]);
  }
  if ( (a2[1] & 0x8000000) != 0 )
  {
    v3 = a2[2];
    if ( (int)--*(_DWORD *)(v3 + 4) <= 0 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)a2[2] + 8))(a1: a2[2]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100487A0
// Name: public: SQFuncState::SQFuncState(struct SQSharedState __near *,struct SQFuncState __near *,void (*)(void __near *,char const __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
SQFuncState *__userpurge SQFuncState::SQFuncState@<eax>(
        SQFuncState *this@<ecx>,
        int a2@<edi>,
        SQSharedState *ss,
        SQFuncState *parent,
        void (__cdecl *efunc)(void *, const char *),
        void *ed)
{
  SQTable *v6; // eax
  _DWORD *v7; // esi
  SQCollectable *gc_chain; // edx
  int v9; // eax
  _DWORD *v10; // ecx
  SQTable *v11; // eax
  _DWORD *v12; // esi
  SQCollectable *v13; // edx
  int v14; // eax
  _DWORD *v15; // ecx
  SQCollectable *v17; // [esp+8h] [ebp-4h]
  SQCollectable *v18; // [esp+8h] [ebp-4h]

  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = 0;
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 112) = 0;
  *(_DWORD *)(a2 + 116) = 0;
  *(_DWORD *)(a2 + 124) = 0;
  *(_DWORD *)(a2 + 120) = 16777217;
  *(_DWORD *)(a2 + 128) = 16777217;
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 136) = 16777217;
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 144) = 16777217;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 160) = 0;
  *(_DWORD *)(a2 + 164) = 0;
  *(_DWORD *)(a2 + 172) = 0;
  *(_DWORD *)(a2 + 176) = 0;
  *(_DWORD *)(a2 + 180) = 0;
  *(_DWORD *)(a2 + 184) = 0;
  *(_DWORD *)(a2 + 188) = 0;
  *(_DWORD *)(a2 + 192) = 0;
  *(_DWORD *)(a2 + 196) = 0;
  *(_DWORD *)(a2 + 200) = 0;
  *(_DWORD *)(a2 + 204) = 0;
  *(_DWORD *)(a2 + 224) = 0;
  *(_DWORD *)(a2 + 228) = 0;
  *(_DWORD *)(a2 + 232) = 0;
  *(_DWORD *)(a2 + 152) = 0;
  v6 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
  v7 = &v6->__vftable;
  v17 = v6;
  if ( v6 != nullptr )
  {
    v6->_uiRef = 0;
    v6->_weakref = nullptr;
    v6->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
    SQTable::AllocNodes(this: v6, nSize: 4);
    v17->_next = nullptr;
    v17[1]._prev = nullptr;
    v17[1].__vftable = nullptr;
    v17->_sharedstate = ss;
    v17->_prev = nullptr;
    v17->_next = ss->_gc_chain;
    gc_chain = ss->_gc_chain;
    if ( gc_chain != nullptr )
      gc_chain->_prev = v17;
    ss->_gc_chain = v17;
    v7 = &v17->__vftable;
  }
  v7[6] = 0;
  ++v7[1];
  v9 = *(_DWORD *)(a2 + 120);
  v10 = *(_DWORD **)(a2 + 124);
  *(_DWORD *)(a2 + 124) = v7;
  *(_DWORD *)(a2 + 120) = 167772192;
  ++v7[1];
  if ( (v9 & 0x8000000) != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  if ( (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  v11 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
  v12 = &v11->__vftable;
  v18 = v11;
  if ( v11 != nullptr )
  {
    v11->_uiRef = 0;
    v11->_weakref = nullptr;
    v11->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
    SQTable::AllocNodes(this: v11, nSize: 4);
    v18->_next = nullptr;
    v18[1]._prev = nullptr;
    v18[1].__vftable = nullptr;
    v18->_sharedstate = ss;
    v18->_prev = nullptr;
    v18->_next = ss->_gc_chain;
    v13 = ss->_gc_chain;
    if ( v13 != nullptr )
      v13->_prev = v18;
    v12 = &v18->__vftable;
    ss->_gc_chain = v18;
  }
  v12[6] = 0;
  ++v12[1];
  v14 = *(_DWORD *)(a2 + 128);
  v15 = *(_DWORD **)(a2 + 132);
  *(_DWORD *)(a2 + 132) = v12;
  *(_DWORD *)(a2 + 128) = 167772192;
  ++v12[1];
  if ( (v14 & 0x8000000) != 0 && (int)--v15[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15);
  if ( (int)--v12[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
  *(_DWORD *)(a2 + 220) = ss;
  *(_DWORD *)(a2 + 208) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 212) = 0;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 240) = ed;
  *(_WORD *)(a2 + 32) = 0;
  *(_BYTE *)(a2 + 216) = 1;
  *(_DWORD *)(a2 + 168) = parent;
  *(_DWORD *)(a2 + 236) = efunc;
  return (SQFuncState *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x10048A20
// Name: public: int SQFuncState::GetConstant(struct tagSQObject const __near &)
// Source: json
//------------------------------------------------------------------------------
tagSQObjectValue __thiscall SQFuncState::GetConstant(SQFuncState *this, SQFuncState *cons, const tagSQObject *consa)
{
  _DWORD *v3; // edi
  __int32 v4; // ebx
  tagSQObjectType nliterals; // edi
  tagSQObjectValue v6; // eax
  tagSQObjectType type; // eax
  tagSQObjectValue v8; // ecx
  tagSQObjectValue v9; // eax
  tagSQObjectValue result; // eax
  tagSQObjectValue v11; // edi
  SQObjectPtr key; // [esp+Ch] [ebp-14h] BYREF
  SQObjectPtr val; // [esp+14h] [ebp-Ch] BYREF
  bool v14; // [esp+1Fh] [ebp-1h]

  v3 = &consa->_unVal.pTable->__vftable;
  key._type = consa->_type;
  v4 = key._type & 0x8000000;
  val._type = OT_NULL;
  val._unVal.nInteger = 0;
  key._unVal.nInteger = (int)v3;
  if ( (key._type & 0x8000000) != 0 )
    ++v3[1];
  v14 = !SQTable::Get(this: cons->_literals._unVal.pTable, &key, &val);
  if ( v4 != 0 && (int)--v3[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(a1: v3);
  if ( v14 )
  {
    nliterals = cons->_nliterals;
    if ( (val._type & 0x8000000) != 0 )
    {
      v6.pTable = (SQTable *)val._unVal;
      --*(_DWORD *)(val._unVal.nInteger + 4);
      if ( *(int *)(v6.nInteger + 4) <= 0 )
        val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
    }
    type = consa->_type;
    v8.pTable = (SQTable *)consa->_unVal;
    val._unVal.nInteger = nliterals;
    val._type = OT_INTEGER;
    key._type = type;
    key._unVal = v8;
    if ( (type & 0x8000000) != 0 )
      ++*(_DWORD *)(v8.nInteger + 4);
    SQTable::NewSlot(this: cons->_literals._unVal.pTable, &key, &val);
    if ( (key._type & 0x8000000) != 0 )
    {
      v9.pTable = (SQTable *)key._unVal;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( *(int *)(v9.nInteger + 4) <= 0 )
        key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
    }
    ++cons->_nliterals;
  }
  result.pTable = (SQTable *)val._unVal;
  v11.pTable = (SQTable *)val._unVal;
  if ( (val._type & 0x8000000) != 0 )
  {
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(result.nInteger + 4) <= 0 )
    {
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
      return v11;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048B80
// Name: public: int SQFuncState::PushTarget(int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge SQFuncState::PushTarget@<eax>(SQFuncState *this@<ecx>, int a2@<edi>, int n)
{
  int v3; // edx
  unsigned int v4; // eax
  int v5; // esi
  void *v6; // eax
  int v7; // eax
  int *v8; // ecx
  int v10; // eax
  unsigned int v11; // eax
  int v12; // esi
  int v13; // eax
  int *v14; // ecx
  SQLocalVarInfo val; // [esp+4h] [ebp-14h] BYREF
  int na; // [esp+20h] [ebp+8h]

  v3 = n;
  if ( n == -1 )
  {
    na = *(_DWORD *)(a2 + 8);
    val._name._type = OT_NULL;
    memset(&val._name._unVal, 0, 12);
    sqvector<SQLocalVarInfo>::push_back((sqvector<SQLocalVarInfo> *)this, a2: a2 + 4, &val);
    v10 = *(_DWORD *)(a2 + 28);
    if ( *(_DWORD *)(a2 + 8) > (unsigned int)v10 )
    {
      if ( v10 > 255 )
        (*(void (__cdecl **)(_DWORD, const char *))(a2 + 236))(
          a1: *(_DWORD *)(a2 + 240),
          a2: "internal compiler error: too many locals");
      *(_DWORD *)(a2 + 28) = *(_DWORD *)(a2 + 8);
    }
    v11 = *(_DWORD *)(a2 + 20);
    if ( *(_DWORD *)(a2 + 24) <= v11 )
    {
      v12 = 2 * v11;
      if ( 2 * v11 == 0 )
        v12 = 4;
      *(_DWORD *)(a2 + 16) = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 16), a3: 4 * v12);
      *(_DWORD *)(a2 + 24) = v12;
    }
    v13 = *(_DWORD *)(a2 + 20);
    v14 = (int *)(*(_DWORD *)(a2 + 16) + 4 * v13);
    *(_DWORD *)(a2 + 20) = v13 + 1;
    if ( v14 != nullptr )
      *v14 = na;
    return na;
  }
  else
  {
    v4 = *(_DWORD *)(a2 + 20);
    if ( *(_DWORD *)(a2 + 24) <= v4 )
    {
      v5 = 2 * v4;
      if ( 2 * v4 == 0 )
        v5 = 4;
      v6 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 16), a3: 4 * v5);
      v3 = n;
      *(_DWORD *)(a2 + 16) = v6;
      *(_DWORD *)(a2 + 24) = v5;
    }
    v7 = *(_DWORD *)(a2 + 20);
    v8 = (int *)(*(_DWORD *)(a2 + 16) + 4 * v7);
    *(_DWORD *)(a2 + 20) = v7 + 1;
    if ( v8 != nullptr )
      *v8 = v3;
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048CA0
// Name: public: int SQFuncState::PopTarget(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall SQFuncState::PopTarget@<eax>(SQFuncState *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // ebx
  int *v3; // eax
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // edx
  _DWORD *v7; // ecx
  int v8; // eax
  int v10; // [esp+8h] [ebp-4h]

  v2 = *(_DWORD *)(a2[4] + 4 * a2[5] - 4);
  v3 = (int *)(a2[1] + 20 * v2);
  v4 = (_DWORD *)v3[1];
  v5 = *v3;
  v6 = v5 & 0x8000000;
  v10 = v5 & 0x8000000;
  if ( (v5 & 0x8000000) != 0 )
    ++v4[1];
  if ( v5 == 16777217 )
  {
    --a2[2];
    v7 = (_DWORD *)(a2[1] + 20 * a2[2]);
    if ( (*v7 & 0x8000000) != 0 )
    {
      v8 = v7[1];
      if ( (int)--*(_DWORD *)(v8 + 4) <= 0 )
      {
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v7[1] + 8))(a1: v7[1]);
        v6 = v10;
      }
    }
  }
  --a2[5];
  if ( v6 != 0 && (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10048D30
// Name: public: void SQFuncState::SetStackSize(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQFuncState::SetStackSize(SQFuncState *this@<ecx>, _DWORD *a2@<edi>)
{
  int v2; // eax
  int v3; // ecx
  _DWORD *v4; // ebx
  int v5; // eax
  tagSQObjectType v6; // ecx
  int v7; // esi
  unsigned int v8; // edx
  unsigned int v9; // eax
  int v10; // ecx
  bool v11; // zf
  int v12; // ecx
  int v13; // eax
  SQLocalVarInfo lvi; // [esp+0h] [ebp-1Ch] BYREF
  int v15; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]

  v2 = a2[2];
  if ( v2 > (int)this )
  {
    v16 = v2 - (_DWORD)this;
    do
    {
      v3 = a2[1];
      v4 = *(_DWORD **)(v3 + 20 * a2[2] - 16);
      v5 = v3 + 20 * a2[2] - 20;
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 & 0x8000000;
      lvi._name._unVal.nInteger = (int)v4;
      lvi._name._type = v6;
      v15 = v7;
      if ( v7 != 0 )
        ++v4[1];
      lvi._start_op = *(_DWORD *)(v5 + 8);
      v8 = *(_DWORD *)(v5 + 12);
      v9 = *(_DWORD *)(v5 + 16);
      lvi._end_op = v8;
      lvi._pos = v9;
      if ( v6 != OT_NULL )
      {
        lvi._end_op = a2[25] - 1;
        sqvector<SQLocalVarInfo>::push_back(
          this: (sqvector<SQLocalVarInfo> *)lvi._end_op,
          a2: (int)(a2 + 27),
          val: &lvi);
        v7 = v15;
      }
      v10 = a2[1];
      --a2[2];
      v11 = (*(_DWORD *)(v10 + 20 * a2[2]) & 0x8000000) == 0;
      v12 = v10 + 20 * a2[2];
      if ( !v11 )
      {
        v13 = *(_DWORD *)(v12 + 4);
        if ( (int)--*(_DWORD *)(v13 + 4) <= 0 )
          (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v12 + 4) + 8))(a1: *(_DWORD *)(v12 + 4));
      }
      if ( v7 != 0 && (int)--v4[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
      --v16;
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048E10
// Name: public: bool SQFuncState::IsConstant(struct tagSQObject const __near &,struct tagSQObject __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQFuncState::IsConstant@<al>(const tagSQObject *name@<eax>, SQFuncState *this, tagSQObject *e)
{
  _DWORD *v3; // edi
  __int32 v4; // ebx
  tagSQObjectType type; // eax
  _DWORD *v6; // ecx
  int *pTable; // ecx
  SQObjectPtr key; // [esp+10h] [ebp-10h] BYREF
  SQObjectPtr val; // [esp+18h] [ebp-8h] BYREF
  bool this_3; // [esp+2Bh] [ebp+Bh]

  v3 = &name->_unVal.pTable->__vftable;
  key._type = name->_type;
  v4 = key._type & 0x8000000;
  val._type = OT_NULL;
  val._unVal.nInteger = 0;
  key._unVal.nInteger = (int)v3;
  if ( (key._type & 0x8000000) != 0 )
    ++v3[1];
  this_3 = SQTable::Get(this: this->_sharedstate->_consts._unVal.pTable, &key, &val);
  if ( v4 != 0 && (int)--v3[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(a1: v3);
  if ( this_3 )
  {
    type = val._type;
    v6 = &val._unVal.pTable->__vftable;
    *e = val.tagSQObject;
    if ( (type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
    return 1;
  }
  else
  {
    if ( (val._type & 0x8000000) != 0 )
    {
      pTable = (int *)val._unVal.pTable;
      --*(_DWORD *)(val._unVal.nInteger + 4);
      if ( pTable[1] <= 0 )
        (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048ED0
// Name: public: bool SQFuncState::IsLocal(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __usercall SQFuncState::IsLocal@<al>(SQFuncState *this@<ecx>, unsigned int stkpos@<eax>)
{
  return stkpos < this->_vlocals._size && this->_vlocals._vals[stkpos]._name._type != OT_NULL;
}

//------------------------------------------------------------------------------
// Address: 0x10048EF0
// Name: public: int SQFuncState::PushLocalVariable(struct tagSQObject const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge SQFuncState::PushLocalVariable@<eax>(const tagSQObject *name@<eax>, SQFuncState *this)
{
  unsigned int size; // ecx
  _DWORD *v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // eax
  SQLocalVarInfo lvi; // [esp+8h] [ebp-18h] BYREF
  __int32 v9; // [esp+1Ch] [ebp-4h]
  int pos; // [esp+28h] [ebp+8h]

  size = this->_vlocals._size;
  v4 = &name->_unVal.pTable->__vftable;
  lvi._name._type = name->_type;
  pos = size;
  lvi._end_op = 0;
  lvi._name._unVal.nInteger = (int)v4;
  v9 = lvi._name._type & 0x8000000;
  if ( (lvi._name._type & 0x8000000) != 0 )
    ++v4[1];
  v5 = this->_vlocals._size;
  lvi._start_op = this->_instructions._size;
  lvi._pos = v5;
  sqvector<SQLocalVarInfo>::push_back(this: (sqvector<SQLocalVarInfo> *)&lvi, a2: (int)&this->_vlocals, val: &lvi);
  v6 = this->_vlocals._size;
  if ( v6 > this->_stacksize )
    this->_stacksize = v6;
  if ( v9 != 0 && (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
  return pos;
}

//------------------------------------------------------------------------------
// Address: 0x10048F70
// Name: public: int SQFuncState::GetLocalVariable(struct tagSQObject const __near &)
// Source: json
//------------------------------------------------------------------------------
int __usercall SQFuncState::GetLocalVariable@<eax>(SQFuncState *this@<ecx>, const tagSQObject *name@<esi>)
{
  signed int size; // eax
  tagSQObjectValue *i; // ecx

  size = this->_vlocals._size;
  if ( size < 1 )
    return -1;
  for ( i = &this->_vlocals._vals[size - 1]._name._unVal;
        i[-1].nInteger != 134217744 || i->nInteger != name->_unVal.nInteger;
        i -= 5 )
  {
    if ( --size < 1 )
      return -1;
  }
  return size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10048FB0
// Name: public: int SQFuncState::GetOuterVariable(struct tagSQObject const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SQFuncState::GetOuterVariable(SQFuncState *this, const tagSQObject *name)
{
  signed int size; // edx
  int result; // eax
  tagSQObjectValue *i; // ecx

  size = this->_outervalues._size;
  result = 0;
  if ( size <= 0 )
    return -1;
  for ( i = &this->_outervalues._vals->_name._unVal; i->nInteger != name->_unVal.nInteger; i += 5 )
  {
    if ( ++result >= size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048FF0
// Name: public: void SQFuncState::AddOuterValue(struct tagSQObject const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQFuncState::AddOuterValue(const tagSQObject *name@<eax>, SQFuncState *this)
{
  SQFuncState *parent; // edx
  int size; // eax
  tagSQObjectValue *p_unVal; // ecx
  tagSQObjectValue v6; // eax
  int v7; // edi
  tagSQObjectValue v8; // ecx
  SQTable *pTable; // ebx
  tagSQObjectValue *v10; // eax
  tagSQObjectType type; // eax
  tagSQObjectValue v12; // ecx
  _DWORD *nInteger; // ebx
  unsigned int v14; // eax
  unsigned int v15; // esi
  unsigned int v16; // eax
  SQOuterVar *v17; // esi
  tagSQObjectValue v18; // eax
  tagSQObjectValue v19; // eax
  int *v20; // ecx
  const SQOuterVar *v21; // eax
  sqvector<SQOuterVar> *v22; // ecx
  SQOuterVar *v23; // ecx
  const SQOuterVar *v24; // eax
  sqvector<SQOuterVar> *v25; // ecx
  tagSQObjectValue v26; // eax
  tagSQObjectValue v27; // eax
  SQOuterVar v28; // [esp+10h] [ebp-34h] BYREF
  SQObjectPtr src; // [esp+24h] [ebp-20h] BYREF
  SQObjectPtr v30; // [esp+2Ch] [ebp-18h] BYREF
  int v31; // [esp+34h] [ebp-10h]
  SQObjectPtr v32; // [esp+38h] [ebp-Ch] BYREF

  parent = this->_parent;
  if ( parent == nullptr )
    goto LABEL_13;
  size = parent->_vlocals._size;
  if ( size >= 1 )
  {
    p_unVal = &parent->_vlocals._vals[size - 1]._name._unVal;
    while ( p_unVal[-1].nInteger != 134217744 || p_unVal->nInteger != name->_unVal.nInteger )
    {
      --size;
      p_unVal -= 5;
      if ( size < 1 )
        goto LABEL_9;
    }
    v6.nInteger = size - 1;
    if ( v6.nInteger != -1 )
    {
      pTable = name->_unVal.pTable;
      v30._type = name->_type;
      v30._unVal.nInteger = (int)pTable;
      v32._unVal.nInteger = v30._type & 0x8000000;
      if ( (v30._type & 0x8000000) != 0 )
        ++pTable->_uiRef;
      src._unVal = v6;
      src._type = OT_INTEGER;
      v24 = SQOuterVar::SQOuterVar(this: &v28, name: &v30, &src, t: otLOCAL);
      sqvector<SQOuterVar>::push_back(this: v25, a2: (int)&this->_outervalues, val: v24);
      if ( (v28._src._type & 0x8000000) != 0 )
      {
        v26.pTable = (SQTable *)v28._src._unVal;
        --*(_DWORD *)(v28._src._unVal.nInteger + 4);
        if ( *(int *)(v26.nInteger + 4) <= 0 )
          v28._src._unVal.pTable->Release(this: (struct SQTable *)v28._src._unVal.nInteger);
      }
      if ( (v28._name._type & 0x8000000) != 0 )
      {
        v27.pTable = (SQTable *)v28._name._unVal;
        --*(_DWORD *)(v28._name._unVal.nInteger + 4);
        if ( *(int *)(v27.nInteger + 4) <= 0 )
          v28._name._unVal.pTable->Release(this: (struct SQTable *)v28._name._unVal.nInteger);
      }
      if ( v32._unVal.nInteger != 0 && --pTable->_uiRef <= 0 )
        goto LABEL_52;
      return;
    }
  }
LABEL_9:
  v7 = parent->_outervalues._size;
  v8.nInteger = 0;
  if ( v7 <= 0 )
    goto LABEL_13;
  pTable = name->_unVal.pTable;
  v10 = &parent->_outervalues._vals->_name._unVal;
  while ( v10->pTable != pTable )
  {
    ++v8.nInteger;
    v10 += 5;
    if ( v8.nInteger >= v7 )
      goto LABEL_13;
  }
  if ( v8.nInteger == -1 )
  {
LABEL_13:
    type = name->_type;
    v12.pTable = (SQTable *)name->_unVal;
    src._type = name->_type;
    src._unVal = v12;
    v30._unVal.nInteger = src._type & 0x8000000;
    if ( (src._type & 0x8000000) != 0 )
      ++*(_DWORD *)(v12.nInteger + 4);
    v32._type = type;
    nInteger = (_DWORD *)v12.nInteger;
    v32._unVal = v12;
    v31 = type & 0x8000000;
    if ( (type & 0x8000000) != 0 )
      ++*(_DWORD *)(v12.nInteger + 4);
    v32._unVal.nInteger = (int)SQOuterVar::SQOuterVar(this: &v28, name: &v32, &src, t: otSYMBOL);
    v14 = this->_outervalues._size;
    if ( this->_outervalues._allocated <= v14 )
    {
      v15 = 2 * v14;
      if ( 2 * v14 == 0 )
        v15 = 4;
      this->_outervalues._vals = (SQOuterVar *)_g_pMemAlloc->Realloc_2(
                                                 this: _g_pMemAlloc,
                                                 a2: this->_outervalues._vals,
                                                 a3: 20 * v15);
      this->_outervalues._allocated = v15;
    }
    v16 = this->_outervalues._size;
    v17 = &this->_outervalues._vals[v16];
    this->_outervalues._size = v16 + 1;
    if ( v17 != nullptr )
      SQOuterVar::SQOuterVar(this: v17, ov: (const SQOuterVar *)v32._unVal.pTable);
    if ( (v28._src._type & 0x8000000) != 0 )
    {
      v18.pTable = (SQTable *)v28._src._unVal;
      --*(_DWORD *)(v28._src._unVal.nInteger + 4);
      if ( *(int *)(v18.nInteger + 4) <= 0 )
        v28._src._unVal.pTable->Release(this: (struct SQTable *)v28._src._unVal.nInteger);
    }
    if ( (v28._name._type & 0x8000000) != 0 )
    {
      v19.pTable = (SQTable *)v28._name._unVal;
      --*(_DWORD *)(v28._name._unVal.nInteger + 4);
      if ( *(int *)(v19.nInteger + 4) <= 0 )
        v28._name._unVal.pTable->Release(this: (struct SQTable *)v28._name._unVal.nInteger);
    }
    if ( v31 != 0 && (int)--nInteger[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*nInteger + 8))(a1: nInteger);
    if ( v30._unVal.nInteger != 0 )
    {
      v20 = (int *)src._unVal.pTable;
      --*(_DWORD *)(src._unVal.nInteger + 4);
      if ( v20[1] <= 0 )
        (*(void (__thiscall **)(int *))(*v20 + 8))(a1: v20);
    }
    return;
  }
  v30._type = name->_type;
  v30._unVal.nInteger = (int)pTable;
  v32._unVal.nInteger = v30._type & 0x8000000;
  if ( (v30._type & 0x8000000) != 0 )
    ++pTable->_uiRef;
  src._type = OT_INTEGER;
  src._unVal = v8;
  v21 = SQOuterVar::SQOuterVar(this: &v28, name: &v30, &src, t: otOUTER);
  sqvector<SQOuterVar>::push_back(this: v22, a2: (int)&this->_outervalues, val: v21);
  SQOuterVar::~SQOuterVar(this: v23, a2: &v28);
  if ( v32._unVal.nInteger != 0 && --pTable->_uiRef <= 0 )
LABEL_52:
    pTable->Release(this: pTable);
}

//------------------------------------------------------------------------------
// Address: 0x10049290
// Name: public: void SQFuncState::AddLineInfos(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQFuncState::AddLineInfos(
        SQFuncState *this@<ecx>,
        SQFuncState *a2@<eax>,
        int line,
        bool lineop,
        bool force)
{
  unsigned int size; // eax
  int v7; // edi
  unsigned int v8; // ecx
  SQLineInfo *v9; // eax
  unsigned int li_4; // [esp+14h] [ebp-10h]
  SQInstruction i; // [esp+18h] [ebp-Ch] BYREF

  if ( a2->_lastline != line || force )
  {
    li_4 = a2->_instructions._size;
    if ( lineop )
    {
      i._arg1 = line;
      *(_DWORD *)&i.op = 0;
      SQFuncState::AddInstruction(this: a2, &i);
    }
    size = a2->_lineinfos._size;
    if ( a2->_lineinfos._allocated <= size )
    {
      v7 = 2 * size;
      if ( 2 * size == 0 )
        v7 = 4;
      a2->_lineinfos._vals = (SQLineInfo *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: a2->_lineinfos._vals,
                                             a3: 8 * v7);
      a2->_lineinfos._allocated = v7;
    }
    v8 = a2->_lineinfos._size;
    v9 = &a2->_lineinfos._vals[v8];
    a2->_lineinfos._size = v8 + 1;
    if ( v9 != nullptr )
    {
      v9->_line = line;
      v9->_op = li_4;
    }
    a2->_lastline = line;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049350
// Name: public: void SQFuncState::AddInstruction(struct SQInstruction __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQFuncState::AddInstruction(SQFuncState *this@<esi>, SQInstruction *i@<edi>)
{
  signed int size; // eax
  unsigned __int8 op; // bl
  SQInstruction *v4; // edx
  unsigned __int8 v5; // al
  _BYTE *v6; // edx
  unsigned int arg0; // eax
  _BYTE *v8; // edx
  unsigned int v9; // eax
  int v10; // edx
  unsigned __int8 v11; // al
  unsigned int v12; // eax
  _BYTE *v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  SQInstruction *v17; // ecx

  size = this->_instructions._size;
  if ( size > 0 && this->_optimization )
  {
    op = i->op;
    v4 = &this->_instructions._vals[size - 1];
    switch ( op )
    {
      case 0u:
        if ( v4->op == 0 )
        {
          --this->_instructions._size;
          --this->_lineinfos._size;
        }
        goto LABEL_40;
      case 1u:
        if ( v4->op != 1 || i->_arg1 >= 256 )
          goto LABEL_40;
        v4->op = 4;
        v4->_arg2 = i->_arg0;
        v4->_arg3 = i->_arg1;
        return;
      case 7u:
        if ( v4->op != 1 )
          goto LABEL_40;
        arg0 = v4->_arg0;
        if ( arg0 != i->_arg1 || SQFuncState::IsLocal(this, stkpos: arg0) )
          goto LABEL_40;
        v8[4] = 8;
        v8[5] = i->_arg0;
        v8[6] = i->_arg2;
        v8[7] = i->_arg3;
        return;
      case 0xAu:
        v11 = v4->op;
        if ( (v11 == 14 || v11 == 17 || v11 == 18) && v4->_arg0 == i->_arg1 )
        {
          v4->_arg0 = i->_arg0;
          this->_optimization = false;
          return;
        }
        if ( v11 != 10 )
          goto LABEL_40;
        v4->op = 23;
        v4->_arg2 = i->_arg0;
        v4->_arg3 = i->_arg1;
        break;
      case 0xEu:
        if ( v4->op != 1 )
          goto LABEL_40;
        v5 = v4->_arg0;
        if ( v5 != i->_arg2 || SQFuncState::IsLocal(this, stkpos: v5) )
          goto LABEL_40;
        v6[6] = i->_arg1;
        v6[4] = 9;
        v6[5] = i->_arg0;
        return;
      case 0xFu:
      case 0x10u:
        if ( v4->op != 1 )
          goto LABEL_40;
        v12 = v4->_arg0;
        if ( v12 != i->_arg1 || SQFuncState::IsLocal(this, stkpos: v12) )
          goto LABEL_40;
        v13[4] = op;
        v13[5] = i->_arg0;
        v13[6] = i->_arg2;
        v13[7] = -1;
        return;
      case 0x13u:
        if ( this->_parent != nullptr && i->_arg0 != 0xFF && v4->op == 6 && this->_returnexp < size - 1 )
          v4->op = 5;
        goto LABEL_40;
      case 0x14u:
        if ( v4->op != 20 || v4->_arg1 + v4->_arg0 != i->_arg0 )
          goto LABEL_40;
        ++v4->_arg1;
        v4->op = 20;
        return;
      case 0x20u:
        if ( v4->op != 1 )
          goto LABEL_40;
        v9 = v4->_arg0;
        if ( v9 != i->_arg1 || SQFuncState::IsLocal(this, stkpos: v9) )
          goto LABEL_40;
        *(_BYTE *)(v10 + 4) = 32;
        *(_BYTE *)(v10 + 5) = i->_arg0;
        *(_WORD *)(v10 + 6) = -1;
        return;
      default:
        goto LABEL_40;
    }
  }
  else
  {
LABEL_40:
    this->_optimization = true;
    v14 = this->_instructions._size;
    if ( this->_instructions._allocated <= v14 )
    {
      v15 = 2 * v14;
      if ( 2 * v14 == 0 )
        v15 = 4;
      this->_instructions._vals = (SQInstruction *)_g_pMemAlloc->Realloc_2(
                                                     this: _g_pMemAlloc,
                                                     a2: this->_instructions._vals,
                                                     a3: 8 * v15);
      this->_instructions._allocated = v15;
    }
    v16 = this->_instructions._size;
    v17 = &this->_instructions._vals[v16];
    this->_instructions._size = v16 + 1;
    if ( v17 != nullptr )
      *v17 = *i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100495E0
// Name: public: struct tagSQObject SQFuncState::CreateString(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
SQObjectPtr *__userpurge SQFuncState::CreateString@<eax>(
        SQFuncState *this@<edi>,
        const char *s@<eax>,
        SQObjectPtr *len,
        int lena)
{
  SQSharedState *sharedstate; // esi
  SQString *v5; // eax
  SQTable *pTable; // ecx
  tagSQObjectValue v7; // eax
  tagSQObjectType type; // ecx
  tagSQObjectValue v9; // eax
  SQObjectPtr ns; // [esp+8h] [ebp-10h] BYREF
  SQObjectPtr val; // [esp+10h] [ebp-8h] BYREF

  sharedstate = this->_sharedstate;
  v5 = StringTable::Add(this: sharedstate->_stringtable, news: s, len: lena);
  v5->_sharedstate = sharedstate;
  ns._unVal.nInteger = (int)v5;
  ns._type = OT_STRING;
  ++v5->_uiRef;
  val._unVal.nInteger = 1;
  pTable = this->_strings._unVal.pTable;
  val._type = OT_INTEGER;
  SQTable::NewSlot(this: pTable, key: &ns, &val);
  if ( (val._type & 0x8000000) != 0 )
  {
    v7.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v7.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  type = ns._type;
  v9.pTable = (SQTable *)ns._unVal;
  *len = ns;
  if ( (type & 0x8000000) != 0 && (int)--*(_DWORD *)(v9.nInteger + 4) <= 0 )
    ns._unVal.pTable->Release(this: (struct SQTable *)ns._unVal.nInteger);
  return len;
}

//------------------------------------------------------------------------------
// Address: 0x10049680
// Name: public: struct tagSQObject SQFuncState::CreateTable(void)
// Source: json
//------------------------------------------------------------------------------
SQObjectPtr *__thiscall SQFuncState::CreateTable(SQFuncState *this, SQFuncState *thisa, SQObjectPtr *a3)
{
  SQSharedState *sharedstate; // ebx
  SQTable *v4; // eax
  SQCollectable *v5; // edi
  SQCollectable *gc_chain; // eax
  SQTable *pTable; // ecx
  tagSQObjectValue v8; // eax
  tagSQObjectType type; // ecx
  tagSQObjectValue v10; // eax
  SQObjectPtr nt; // [esp+10h] [ebp-10h] BYREF
  SQObjectPtr val; // [esp+18h] [ebp-8h] BYREF

  sharedstate = thisa->_sharedstate;
  v4 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->_uiRef = 0;
    v4->_weakref = nullptr;
    v4->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
    SQTable::AllocNodes(this: v4, nSize: 4);
    v5->_next = nullptr;
    v5[1]._prev = nullptr;
    v5[1].__vftable = nullptr;
    v5->_sharedstate = sharedstate;
    v5->_prev = nullptr;
    v5->_next = sharedstate->_gc_chain;
    gc_chain = sharedstate->_gc_chain;
    if ( gc_chain != nullptr )
      gc_chain->_prev = v5;
    sharedstate->_gc_chain = v5;
  }
  v5[1].__vftable = nullptr;
  nt._type = OT_TABLE;
  nt._unVal.nInteger = (int)v5;
  ++v5->_uiRef;
  val._unVal.nInteger = 1;
  pTable = thisa->_strings._unVal.pTable;
  val._type = OT_INTEGER;
  SQTable::NewSlot(this: pTable, key: &nt, &val);
  if ( (val._type & 0x8000000) != 0 )
  {
    v8.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v8.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  type = nt._type;
  v10.pTable = (SQTable *)nt._unVal;
  *a3 = nt;
  if ( (type & 0x8000000) != 0 && (int)--*(_DWORD *)(v10.nInteger + 4) <= 0 )
    nt._unVal.pTable->Release(this: (struct SQTable *)nt._unVal.nInteger);
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x10049770
// Name: public: struct SQFunctionProto __near * SQFuncState::BuildProto(void)
// Source: json
//------------------------------------------------------------------------------
SQFunctionProto *__usercall SQFuncState::BuildProto@<eax>(SQFuncState *this@<ecx>, int a2@<eax>)
{
  SQFunctionProto *v3; // ebx
  _DWORD *v4; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v6; // eax
  _DWORD *v7; // ecx
  tagSQObjectType v8; // edx
  tagSQObjectType v9; // eax
  tagSQObjectValue v10; // edi
  SQObjectPtr *literals; // eax
  unsigned int v12; // edx
  tagSQObjectType *p_type; // eax
  _DWORD *v14; // ecx
  tagSQObjectType v15; // edx
  int *pTable; // ecx
  unsigned int v17; // eax
  int v18; // edx
  int v19; // ecx
  unsigned int v20; // edi
  unsigned int *v21; // eax
  unsigned int *v22; // edx
  _DWORD *v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // eax
  int v26; // edx
  int v27; // ecx
  unsigned int v28; // edi
  unsigned int *v29; // eax
  unsigned int *v30; // edx
  _DWORD *v31; // ecx
  unsigned int v32; // edx
  unsigned int v33; // ecx
  _DWORD *v34; // eax
  _DWORD *v35; // edi
  _DWORD *v36; // ecx
  int v37; // edx
  int v38; // edx
  _DWORD *v39; // ecx
  int v40; // eax
  unsigned int v41; // ecx
  SQLocalVarInfo *localvarinfos; // edi
  _DWORD *v43; // edx
  int v44; // eax
  _DWORD *v45; // edi
  _DWORD *v46; // eax
  int v47; // edx
  int *v48; // edx
  unsigned int i; // eax
  int v50; // ecx
  SQLineInfo *lineinfos; // edx
  unsigned int j; // eax
  int *v53; // ecx
  int *v54; // ecx
  int *v55; // ecx
  SQTable *v57; // [esp-Ch] [ebp-44h]
  SQObjectPtr val; // [esp+Ch] [ebp-2Ch] BYREF
  SQObjectPtr key; // [esp+14h] [ebp-24h] BYREF
  SQObjectPtr refidx; // [esp+1Ch] [ebp-1Ch] BYREF
  _DWORD *v61; // [esp+24h] [ebp-14h]
  unsigned int v62; // [esp+28h] [ebp-10h]
  int *v63; // [esp+2Ch] [ebp-Ch]
  unsigned int no; // [esp+30h] [ebp-8h]
  unsigned int np; // [esp+34h] [ebp-4h]

  v3 = SQFunctionProto::Create(
         noutervalues: *(_DWORD *)(a2 + 88),
         nlocalvarinfos: *(_DWORD *)(a2 + 112),
         ninstructions: *(_DWORD *)(a2 + 100),
         nliterals: *(_DWORD *)(a2 + 152),
         nparameters: *(_DWORD *)(a2 + 76),
         nfunctions: *(_DWORD *)(a2 + 64),
         nlineinfos: *(_DWORD *)(a2 + 160),
         ndefaultparams: *(_DWORD *)(a2 + 200));
  refidx._type = OT_NULL;
  key._type = OT_NULL;
  val._type = OT_NULL;
  v3->_stacksize = *(_DWORD *)(a2 + 28);
  v4 = &v3->_sourcename._unVal.pTable->__vftable;
  type = v3->_sourcename._type;
  v3->_sourcename._unVal.nInteger = *(_DWORD *)(a2 + 148);
  v6 = *(_DWORD *)(a2 + 144);
  refidx._unVal.nInteger = 0;
  key._unVal.nInteger = 0;
  val._unVal.nInteger = 0;
  v3->_sourcename._type = v6;
  if ( (v6 & 0x8000000) != 0 )
    ++*(_DWORD *)(v3->_sourcename._unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
  v3->_bgenerator = *(_BYTE *)(a2 + 33);
  v7 = &v3->_name._unVal.pTable->__vftable;
  v8 = v3->_name._type;
  v3->_name._unVal.nInteger = *(_DWORD *)(a2 + 140);
  v9 = *(_DWORD *)(a2 + 136);
  v3->_name._type = v9;
  if ( (v9 & 0x8000000) != 0 )
    ++*(_DWORD *)(v3->_name._unVal.nInteger + 4);
  if ( (v8 & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  for ( v10.nInteger = SQTable::Next(
                         this: *(SQTable **)(a2 + 124),
                         getweakrefs: false,
                         refpos: &refidx,
                         outkey: &key,
                         outval: &val);
        v10.nInteger != -1;
        v10.nInteger = SQTable::Next(this: v57, getweakrefs: false, refpos: &refidx, outkey: &key, outval: &val) )
  {
    literals = v3->_literals;
    v12 = literals[val._unVal.nInteger]._type;
    p_type = &literals[val._unVal.nInteger]._type;
    v14 = *((_DWORD **)p_type + 1);
    no = v12;
    p_type[1] = (tagSQObjectType)key._unVal.pTable;
    v15 = key._type;
    *p_type = key._type;
    if ( (v15 & 0x8000000) != 0 )
      ++*(_DWORD *)(key._unVal.nInteger + 4);
    if ( (no & 0x8000000) != 0 && (int)--v14[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
    if ( (refidx._type & 0x8000000) != 0 )
    {
      pTable = (int *)refidx._unVal.pTable;
      --*(_DWORD *)(refidx._unVal.nInteger + 4);
      if ( pTable[1] <= 0 )
        (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
    }
    v57 = *(SQTable **)(a2 + 124);
    refidx._unVal = v10;
    refidx._type = OT_INTEGER;
  }
  v17 = 0;
  for ( np = 0; v17 < *(_DWORD *)(a2 + 64); np = v17 )
  {
    v18 = *(_DWORD *)(a2 + 60);
    v19 = 8 * v17;
    v20 = *(_DWORD *)(v18 + 8 * v17 + 4);
    v21 = (unsigned int *)&v3->_functions[v17];
    v22 = (unsigned int *)(v19 + v18);
    no = *v21;
    v23 = (_DWORD *)v21[1];
    v21[1] = v20;
    v24 = *v22;
    *v21 = v24;
    if ( (v24 & 0x8000000) != 0 )
      ++*(_DWORD *)(v20 + 4);
    if ( (no & 0x8000000) != 0 && (int)--v23[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v23 + 8))(a1: v23);
    v17 = np + 1;
  }
  v25 = 0;
  for ( np = 0; v25 < *(_DWORD *)(a2 + 76); np = v25 )
  {
    v26 = *(_DWORD *)(a2 + 72);
    v27 = 8 * v25;
    v28 = *(_DWORD *)(v26 + 8 * v25 + 4);
    v29 = (unsigned int *)&v3->_parameters[v25];
    v30 = (unsigned int *)(v27 + v26);
    no = *v29;
    v31 = (_DWORD *)v29[1];
    v29[1] = v28;
    v32 = *v30;
    *v29 = v32;
    if ( (v32 & 0x8000000) != 0 )
      ++*(_DWORD *)(v28 + 4);
    if ( (no & 0x8000000) != 0 && (int)--v31[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v31 + 8))(a1: v31);
    v25 = np + 1;
  }
  v33 = 0;
  no = 0;
  if ( *(_DWORD *)(a2 + 88) != 0 )
  {
    for ( np = 0; ; v33 = np )
    {
      v34 = (_DWORD *)(v33 + *(_DWORD *)(a2 + 84));
      v35 = (_DWORD *)((char *)v3->_outervalues + v33);
      *v35 = *v34;
      v36 = (_DWORD *)v35[2];
      v63 = (int *)v35[1];
      v35[2] = v34[2];
      v37 = v34[1];
      v62 = (unsigned int)v34;
      v35[1] = v37;
      if ( (v37 & 0x8000000) != 0 )
        ++*(_DWORD *)(v35[2] + 4);
      if ( ((unsigned int)v63 & 0x8000000) != 0 && (int)--v36[1] <= 0 )
      {
        (*(void (__thiscall **)(_DWORD *))(*v36 + 8))(a1: v36);
        v34 = (_DWORD *)v62;
      }
      v38 = v34[4];
      v62 = v35[3];
      v39 = (_DWORD *)v35[4];
      v35[4] = v38;
      v40 = v34[3];
      v35[3] = v40;
      if ( (v40 & 0x8000000) != 0 )
        ++*(_DWORD *)(v38 + 4);
      if ( (v62 & 0x8000000) != 0 && (int)--v39[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v39 + 8))(a1: v39);
      np += 20;
      if ( ++no >= *(_DWORD *)(a2 + 88) )
        break;
    }
  }
  v41 = 0;
  no = 0;
  if ( *(_DWORD *)(a2 + 112) != 0 )
  {
    np = 0;
    do
    {
      localvarinfos = v3->_localvarinfos;
      v43 = *(_DWORD **)((char *)&localvarinfos->_name._type + v41);
      v44 = *(_DWORD *)(a2 + 108);
      v45 = (_DWORD *)((char *)localvarinfos + v41);
      v62 = (unsigned int)v43;
      v46 = (_DWORD *)(v41 + v44);
      v63 = (int *)v45[1];
      v45[1] = v46[1];
      v47 = *v46;
      v61 = v46;
      *v45 = v47;
      if ( (v47 & 0x8000000) != 0 )
        ++*(_DWORD *)(v45[1] + 4);
      if ( (v62 & 0x8000000) != 0 )
      {
        v48 = v63;
        --v63[1];
        if ( v48[1] <= 0 )
        {
          (*(void (__thiscall **)(int *))(*v48 + 8))(a1: v48);
          v41 = np;
          v46 = v61;
        }
      }
      v45[2] = v46[2];
      v45[3] = v46[3];
      v45[4] = v46[4];
      v41 += 20;
      ++no;
      np = v41;
    }
    while ( no < *(_DWORD *)(a2 + 112) );
  }
  for ( i = 0; i < *(_DWORD *)(a2 + 160); ++i )
  {
    v50 = *(_DWORD *)(a2 + 156);
    lineinfos = v3->_lineinfos;
    lineinfos[i]._line = *(_DWORD *)(v50 + 8 * i);
    lineinfos[i]._op = *(_DWORD *)(v50 + 8 * i + 4);
  }
  for ( j = 0; j < *(_DWORD *)(a2 + 200); ++j )
    v3->_defaultparams[j] = *(_DWORD *)(*(_DWORD *)(a2 + 196) + 4 * j);
  memcpy(
    dst: (unsigned __int8 *)v3->_instructions,
    src: *(unsigned __int8 **)(a2 + 96),
    count: 8 * *(_DWORD *)(a2 + 100));
  v3->_varparams = *(_BYTE *)(a2 + 32);
  if ( (val._type & 0x8000000) != 0 )
  {
    v53 = (int *)val._unVal.pTable;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( v53[1] <= 0 )
      (*(void (__thiscall **)(int *))(*v53 + 8))(a1: v53);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v54 = (int *)key._unVal.pTable;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( v54[1] <= 0 )
      (*(void (__thiscall **)(int *))(*v54 + 8))(a1: v54);
  }
  if ( (refidx._type & 0x8000000) != 0 )
  {
    v55 = (int *)refidx._unVal.pTable;
    --*(_DWORD *)(refidx._unVal.nInteger + 4);
    if ( v55[1] <= 0 )
      (*(void (__thiscall **)(int *))(*v55 + 8))(a1: v55);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10049BD0
// Name: public: struct SQOuterVar __near & SQOuterVar::operator=(struct SQOuterVar const __near &)
// Source: json
//------------------------------------------------------------------------------
SQOuterVar *__usercall SQOuterVar::operator=@<eax>(SQOuterVar *this@<esi>, const SQOuterVar *__that@<eax>)
{
  _DWORD *v3; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v5; // eax
  tagSQObjectValue v6; // eax
  _DWORD *v7; // ecx
  tagSQObjectType v8; // edx
  tagSQObjectType v9; // edi

  this->_type = __that->_type;
  v3 = &this->_name._unVal.pTable->__vftable;
  type = this->_name._type;
  this->_name._unVal.nInteger = __that->_name._unVal.nInteger;
  v5 = __that->_name._type;
  this->_name._type = v5;
  if ( (v5 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_name._unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v3[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(a1: v3);
  v6.pTable = (SQTable *)__that->_src._unVal;
  v7 = &this->_src._unVal.pTable->__vftable;
  v8 = this->_src._type;
  this->_src._unVal = v6;
  v9 = __that->_src._type;
  this->_src._type = v9;
  if ( (v9 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6.nInteger + 4);
  if ( (v8 & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10049C50
// Name: public: struct SQLocalVarInfo __near & SQLocalVarInfo::operator=(struct SQLocalVarInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
SQLocalVarInfo *__usercall SQLocalVarInfo::operator=@<eax>(
        SQLocalVarInfo *this@<esi>,
        const SQLocalVarInfo *__that@<edi>)
{
  _DWORD *v2; // ecx
  tagSQObjectType type; // edx
  tagSQObjectType v4; // eax

  v2 = &this->_name._unVal.pTable->__vftable;
  type = this->_name._type;
  this->_name._unVal.nInteger = __that->_name._unVal.nInteger;
  v4 = __that->_name._type;
  this->_name._type = __that->_name._type;
  if ( (v4 & 0x8000000) != 0 )
    ++*(_DWORD *)(this->_name._unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v2[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v2 + 8))(a1: v2);
  this->_start_op = __that->_start_op;
  this->_end_op = __that->_end_op;
  this->_pos = __that->_pos;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10049CA0
// Name: public: struct SQFuncState __near * SQFuncState::PushChildState(struct SQSharedState __near *)
// Source: json
//------------------------------------------------------------------------------
SQFuncState *__userpurge SQFuncState::PushChildState@<eax>(SQFuncState *this@<ecx>, int a2@<esi>, SQSharedState *ss)
{
  SQFuncState *v3; // edi
  unsigned int v4; // eax
  int v5; // ebx
  int v6; // eax
  SQFuncState **v7; // ecx
  SQFuncState *result; // eax

  v3 = (SQFuncState *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 244);
  if ( v3 != nullptr )
    SQFuncState::SQFuncState(
      this: *(SQFuncState **)(a2 + 240),
      a2: (int)v3,
      ss,
      parent: (SQFuncState *)a2,
      efunc: *(void (__cdecl **)(void *, const char *))(a2 + 236),
      ed: *(void **)(a2 + 240));
  v4 = *(_DWORD *)(a2 + 228);
  if ( *(_DWORD *)(a2 + 232) <= v4 )
  {
    v5 = 2 * v4;
    if ( 2 * v4 == 0 )
      v5 = 4;
    *(_DWORD *)(a2 + 224) = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)(a2 + 224), a3: 4 * v5);
    *(_DWORD *)(a2 + 232) = v5;
  }
  v6 = *(_DWORD *)(a2 + 228);
  v7 = (SQFuncState **)(*(_DWORD *)(a2 + 224) + 4 * v6);
  *(_DWORD *)(a2 + 228) = v6 + 1;
  result = v3;
  if ( v7 != nullptr )
    *v7 = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049D40
// Name: public: SQFuncState::~SQFuncState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQFuncState::~SQFuncState(SQFuncState *this)
{
  SQFuncState *v2; // esi
  tagSQObjectValue v3; // eax
  tagSQObjectValue v4; // eax
  tagSQObjectValue v5; // eax
  tagSQObjectValue v6; // eax
  sqvector<SQOuterVar> *v7; // ecx
  sqvector<SQObjectPtr> *v8; // ecx
  sqvector<SQObjectPtr> *v9; // ecx
  sqvector<SQLocalVarInfo> *v10; // ecx

  for ( ; this->_childstates._size != 0; --this->_childstates._size )
  {
    v2 = this->_childstates._vals[this->_childstates._size - 1];
    SQFuncState::~SQFuncState(this: v2);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
  }
  if ( this->_childstates._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_childstates._vals);
  if ( this->_defaultparams._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_defaultparams._vals);
  if ( this->_continuetargets._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_continuetargets._vals);
  if ( this->_breaktargets._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_breaktargets._vals);
  if ( this->_lineinfos._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_lineinfos._vals);
  if ( (this->_sourcename._type & 0x8000000) != 0 )
  {
    v3.pTable = (SQTable *)this->_sourcename._unVal;
    if ( (int)--*(_DWORD *)(v3.nInteger + 4) <= 0 )
      this->_sourcename._unVal.pTable->Release(this: (struct SQTable *)this->_sourcename._unVal.nInteger);
  }
  if ( (this->_name._type & 0x8000000) != 0 )
  {
    v4.pTable = (SQTable *)this->_name._unVal;
    if ( (int)--*(_DWORD *)(v4.nInteger + 4) <= 0 )
      this->_name._unVal.pTable->Release(this: (struct SQTable *)this->_name._unVal.nInteger);
  }
  if ( (this->_strings._type & 0x8000000) != 0 )
  {
    v5.pTable = (SQTable *)this->_strings._unVal;
    if ( (int)--*(_DWORD *)(v5.nInteger + 4) <= 0 )
      this->_strings._unVal.pTable->Release(this: (struct SQTable *)this->_strings._unVal.nInteger);
  }
  if ( (this->_literals._type & 0x8000000) != 0 )
  {
    v6.pTable = (SQTable *)this->_literals._unVal;
    if ( (int)--*(_DWORD *)(v6.nInteger + 4) <= 0 )
      this->_literals._unVal.pTable->Release(this: (struct SQTable *)this->_literals._unVal.nInteger);
  }
  sqvector<SQLocalVarInfo>::~sqvector<SQLocalVarInfo>(
    (sqvector<SQLocalVarInfo> *)this,
    a2: (void **)&this->_localvarinfos._vals);
  if ( this->_instructions._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_instructions._vals);
  sqvector<SQOuterVar>::~sqvector<SQOuterVar>(this: v7, a2: (int)&this->_outervalues);
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>(this: v8, a2: (int)&this->_parameters);
  sqvector<SQObjectPtr>::~sqvector<SQObjectPtr>(this: v9, a2: (int)&this->_functions);
  if ( this->_unresolvedcontinues._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_unresolvedcontinues._vals);
  if ( this->_unresolvedbreaks._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_unresolvedbreaks._vals);
  if ( this->_targetstack._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_targetstack._vals);
  sqvector<SQLocalVarInfo>::~sqvector<SQLocalVarInfo>(this: v10, a2: (void **)&this->_vlocals._vals);
}
