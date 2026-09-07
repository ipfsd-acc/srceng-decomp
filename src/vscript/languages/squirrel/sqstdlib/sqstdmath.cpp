// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/sqstdlib/sqstdmath.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10031AE0
// Name: math_srand
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_srand(SQVM *v)
{
  tagSQObjectType type; // ecx

  type = v->_stack._vals[v->_stackbase + 1]._type;
  if ( (type & 0x4000000) == 0 )
    return sq_throwerror(v, err: "invalid param");
  if ( type == OT_FLOAT )
    srand(seed: (int)v->_stack._vals[v->_stackbase + 1]._unVal.fFloat);
  else
    srand(seed: v->_stack._vals[v->_stackbase + 1]._unVal.raw);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10031B40
// Name: math_rand
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_rand(SQVM *v)
{
  int v1; // eax
  int top; // edx
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // esi
  SQObjectPtr *v5; // edx
  _DWORD *v6; // ecx

  v1 = rand();
  top = v->_top;
  v->_top = top + 1;
  vals = v->_stack._vals;
  type = vals[top]._type;
  v5 = &vals[top];
  v6 = &v5->_unVal.pTable->__vftable;
  v5->_unVal.nInteger = v1;
  v5->_type = OT_INTEGER;
  if ( (type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031CA0
// Name: math_fabs
// Source: json
//------------------------------------------------------------------------------
int __cdecl math_fabs(SQVM *v)
{
  SQObjectPtr *vals; // edx
  int stackbase; // eax
  tagSQObjectType type; // esi
  int v4; // eax
  float v5; // xmm0_4
  int top; // eax
  tagSQObjectType v7; // esi
  _DWORD *v8; // ecx

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase + 1]._type;
  v4 = (int)&vals[stackbase + 1];
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_INTEGER )
      v5 = (float)*(int *)(v4 + 4);
    else
      v5 = *(float *)(v4 + 4);
  }
  else
  {
    v5 = *(float *)&v;
  }
  top = v->_top;
  v->_top = top + 1;
  v7 = vals[top]._type;
  v8 = &vals[top]._unVal.pTable->__vftable;
  vals[top]._unVal.nInteger = LODWORD(v5) & _mask__AbsFloat_;
  vals[top]._type = OT_FLOAT;
  if ( (v7 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100325D0
// Name: _sqstd_register_mathlib
// Source: json
//------------------------------------------------------------------------------
int __usercall sqstd_register_mathlib@<eax>(SQVM *v@<eax>)
{
  int v1; // esi
  tagSQRegFunction *v3; // ebx
  int top; // eax
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // esi
  SQSharedState *sharedstate; // ebx
  SQString *v8; // esi
  tagSQObjectType v9; // eax
  _DWORD *v10; // ecx
  int v11; // eax
  int v12; // ecx
  SQObjectPtr *v13; // eax
  tagSQObjectType v14; // edx
  _DWORD *v15; // ecx
  int v16; // ecx
  SQObjectPtr *v17; // eax
  tagSQObjectType v18; // esi
  int v19; // eax
  int v20; // edx
  SQObjectPtr *v21; // eax
  tagSQObjectType v22; // edx
  _DWORD *v23; // ecx
  int v24; // ecx
  SQObjectPtr *v26; // eax
  tagSQObjectType v27; // esi
  const char *v28; // [esp+0h] [ebp-18h]
  int i; // [esp+14h] [ebp-4h]

  v1 = 0;
  i = 0;
  if ( mathlib_funcs[0].name != nullptr )
  {
    v3 = mathlib_funcs;
    do
    {
      sq_pushstring(v, s: v3->name, len: -1);
      sq_newclosure(v, func: mathlib_funcs[v1].f, nfreevars: 0);
      sq_setparamscheck(v, typemask: mathlib_funcs[v1].typemask, nparamscheck: mathlib_funcs[v1].nparamscheck);
      sq_setnativeclosurename(v, name: v3->name);
      top = v->_top;
      if ( top - v->_stackbase >= 3 )
      {
        vals = v->_stack._vals;
        type = vals[top - 3]._type;
        if ( type == OT_TABLE || type == OT_CLASS )
        {
          if ( vals[top - 2]._type == OT_NULL )
          {
            sharedstate = v->_sharedstate;
            v8 = StringTable::Add(this: sharedstate->_stringtable, news: "null is not a valid key", len: -1);
            v8->_sharedstate = sharedstate;
            ++v8->_uiRef;
            v9 = v->_lasterror._type;
            v10 = &v->_lasterror._unVal.pTable->__vftable;
            v->_lasterror._unVal.nInteger = (int)v8;
            v->_lasterror._type = OT_STRING;
            ++v8->_uiRef;
            if ( (v9 & 0x8000000) != 0 && (int)--v10[1] <= 0 )
              (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
            if ( --v8->_uiRef <= 0 )
              v8->Release(this: v8);
          }
          else
          {
            SQVM::NewSlot(
              this: (SQVM *)vals,
              self: &vals[top - 3],
              key: &vals[top - 2],
              val: &vals[top - 1],
              bstatic: false);
            SQVM::Pop(this: v, n: 2);
          }
        }
      }
      else
      {
        SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v28);
      }
      v1 = ++i;
      v3 = &mathlib_funcs[i];
    }
    while ( v3->name != nullptr );
  }
  sq_pushstring(v, s: "RAND_MAX", len: -1);
  v11 = v->_top;
  v12 = v11 + 1;
  v13 = &v->_stack._vals[v11];
  v->_top = v12;
  v14 = v13->_type;
  v15 = &v13->_unVal.pTable->__vftable;
  v13->_unVal.nInteger = 0x7FFF;
  v13->_type = OT_INTEGER;
  if ( (v14 & 0x8000000) != 0 && (int)--v15[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15);
  v16 = v->_top;
  if ( v16 - v->_stackbase >= 3 )
  {
    v17 = v->_stack._vals;
    v18 = v17[v16 - 3]._type;
    if ( v18 == OT_TABLE || v18 == OT_CLASS )
    {
      if ( v17[v16 - 2]._type == OT_NULL )
      {
        sq_throwerror(v, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(
          this: (SQVM *)&v17[v16 - 1],
          self: &v17[v16 - 3],
          key: &v17[v16 - 2],
          val: &v17[v16 - 1],
          bstatic: false);
        SQVM::Pop(this: v, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v28);
  }
  sq_pushstring(v, s: "PI", len: -1);
  v19 = v->_top;
  v20 = v19 + 1;
  v21 = &v->_stack._vals[v19];
  v->_top = v20;
  v22 = v21->_type;
  v23 = &v21->_unVal.pTable->__vftable;
  v21->_unVal.nInteger = 1078530011;
  v21->_type = OT_FLOAT;
  if ( (v22 & 0x8000000) != 0 && (int)--v23[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v23 + 8))(a1: v23);
  v24 = v->_top;
  if ( v24 - v->_stackbase < 3 )
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v28);
    return 0;
  }
  v26 = v->_stack._vals;
  v27 = v26[v24 - 3]._type;
  if ( v27 == OT_TABLE || v27 == OT_CLASS )
  {
    if ( v26[v24 - 2]._type == OT_NULL )
    {
      sq_throwerror(v, err: "null is not a valid key");
      return 0;
    }
    SQVM::NewSlot(this: (SQVM *)v24, self: &v26[v24 - 3], key: &v26[v24 - 2], val: &v26[v24 - 1], bstatic: false);
    SQVM::Pop(this: v, n: 2);
  }
  return 0;
}
