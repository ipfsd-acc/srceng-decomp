// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/squirrel/sqbaselib.cpp
// Functions: 64
// ============================================================

#include "vscript\languages\squirrel\squirrel\sqbaselib.h"

//------------------------------------------------------------------------------
// Address: 0x10039590
// Name: public: bool SQArray::Get(int,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQArray::Get@<al>(signed int nidx@<ecx>, SQObjectPtr *val@<eax>, SQArray *this)
{
  SQObjectPtr *vals; // edx
  bool v4; // zf
  SQObjectPtr *v5; // ecx
  tagSQObjectType type; // edx
  tagSQObjectValue v7; // ecx
  tagSQObjectType *v8; // edx
  tagSQObjectValue v9; // edi
  _DWORD *v10; // ecx
  tagSQObjectType v11; // esi
  tagSQObjectType v12; // edx
  _DWORD v14[3]; // [esp+8h] [ebp-Ch] BYREF

  if ( nidx < 0 || nidx >= (signed int)this->_values._size )
    return 0;
  vals = this->_values._vals;
  v4 = vals[nidx]._type == OT_WEAKREF;
  v5 = &vals[nidx];
  if ( v4 )
  {
    v8 = (tagSQObjectType *)(v5->_unVal.nInteger + 12);
  }
  else
  {
    type = v5->_type;
    v7.pTable = (SQTable *)v5->_unVal;
    v14[0] = type;
    v14[1] = v7.pTable;
    v8 = (tagSQObjectType *)v14;
  }
  v9.pTable = (SQTable *)v8[1];
  v10 = &val->_unVal.pTable->__vftable;
  v11 = val->_type;
  val->_unVal = v9;
  v12 = *v8;
  val->_type = v12;
  if ( (v12 & 0x8000000) != 0 )
    ++*(_DWORD *)(v9.nInteger + 4);
  if ( (v11 & 0x8000000) != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10039620
// Name: public: bool SQArray::Set(int,struct SQObjectPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQArray::Set@<al>(signed int nidx@<eax>, const SQObjectPtr *val@<edx>, SQArray *this)
{
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // esi
  SQObjectPtr *v5; // eax
  _DWORD *v6; // ecx
  tagSQObjectValue v7; // edi
  tagSQObjectType v8; // edx

  if ( nidx < 0 || nidx >= (signed int)this->_values._size )
    return 0;
  vals = this->_values._vals;
  type = vals[nidx]._type;
  v5 = &vals[nidx];
  v6 = &v5->_unVal.pTable->__vftable;
  v7.pTable = (SQTable *)val->_unVal;
  v5->_unVal = v7;
  v8 = val->_type;
  v5->_type = v8;
  if ( (v8 & 0x8000000) != 0 )
    ++*(_DWORD *)(v7.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10039680
// Name: bool str2num(char const __near *,struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall str2num@<al>(char *s@<edi>, SQObjectPtr *res@<esi>)
{
  int v2; // eax
  tagSQObjectValue v4; // eax
  tagSQObjectValue v5; // ebx
  tagSQObjectValue v6; // eax
  float r; // [esp+0h] [ebp-8h]
  char *end; // [esp+4h] [ebp-4h] BYREF

  strstr(str1: (unsigned __int8 *)s, str2: ".");
  if ( v2 != 0 )
  {
    r = strtod(nptr: s, endptr: &end);
    if ( s == end )
    {
      return 0;
    }
    else
    {
      if ( (res->_type & 0x8000000) != 0 )
      {
        v4.pTable = (SQTable *)res->_unVal;
        if ( (int)--*(_DWORD *)(v4.nInteger + 4) <= 0 )
          res->_unVal.pTable->Release(this: (struct SQTable *)res->_unVal.nInteger);
      }
      res->_unVal.fFloat = r;
      res->_type = OT_FLOAT;
      return 1;
    }
  }
  else
  {
    v5.nInteger = strtol(nptr: s, endptr: &end, ibase: 10);
    if ( s == end )
    {
      return 0;
    }
    else
    {
      if ( (res->_type & 0x8000000) != 0 )
      {
        v6.pTable = (SQTable *)res->_unVal;
        if ( (int)--*(_DWORD *)(v6.nInteger + 4) <= 0 )
          res->_unVal.pTable->Release(this: (struct SQTable *)res->_unVal.nInteger);
      }
      res->_unVal = v5;
      res->_type = OT_INTEGER;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039750
// Name: base_collectgarbage
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_collectgarbage(SQVM *v)
{
  SQSharedState *v1; // ecx
  int v2; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectType type; // esi
  SQObjectPtr *v6; // edx
  _DWORD *v7; // ecx
  SQVM *v9; // [esp+0h] [ebp-8h]

  if ( v->_sharedstate->_gc_disableDepth <= 0 )
    v2 = SQSharedState::CollectGarbage(this: v1, tchain: v9);
  else
    v2 = 0;
  top = v->_top;
  v->_top = top + 1;
  vals = v->_stack._vals;
  type = vals[top]._type;
  v6 = &vals[top];
  v7 = &v6->_unVal.pTable->__vftable;
  v6->_unVal.nInteger = v2;
  v6->_type = OT_INTEGER;
  if ( (type & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100397B0
// Name: base_getroottable
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_getroottable(SQVM *v)
{
  int top; // eax
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // esi
  SQObjectPtr *v4; // eax
  _DWORD *v5; // ecx
  tagSQObjectValue v6; // edi
  tagSQObjectType v7; // edx

  top = v->_top;
  v->_top = top + 1;
  vals = v->_stack._vals;
  type = vals[top]._type;
  v4 = &vals[top];
  v5 = &v4->_unVal.pTable->__vftable;
  v6.pTable = (SQTable *)v->_roottable._unVal;
  v4->_unVal = v6;
  v7 = v->_roottable._type;
  v4->_type = v7;
  if ( (v7 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v5[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v5 + 8))(a1: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10039810
// Name: base_getconsttable
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_getconsttable(SQVM *v)
{
  int top; // ecx
  SQSharedState *sharedstate; // edx
  SQObjectPtr *vals; // eax
  tagSQObjectType type; // esi
  SQObjectPtr *v5; // eax
  _DWORD *v6; // ecx
  tagSQObjectValue v7; // edi
  tagSQObjectType v8; // edx

  top = v->_top;
  sharedstate = v->_sharedstate;
  v->_top = top + 1;
  vals = v->_stack._vals;
  type = vals[top]._type;
  v5 = &vals[top];
  v6 = &v5->_unVal.pTable->__vftable;
  v7.pTable = (SQTable *)sharedstate->_consts._unVal;
  v5->_unVal = v7;
  v8 = sharedstate->_consts._type;
  v5->_type = v8;
  if ( (v8 & 0x8000000) != 0 )
    ++*(_DWORD *)(v7.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10039870
// Name: base_setroottable
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_setroottable(SQVM *v)
{
  SQObjectPtr *v1; // edi
  int top; // eax
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // esi
  SQObjectPtr *v6; // eax
  _DWORD *v7; // ecx
  tagSQObjectType v8; // edx

  v1 = &v->_stack._vals[v->_stackbase + 1];
  if ( sq_setroottable(v) < 0 )
    return -1;
  top = v->_top;
  vals = v->_stack._vals;
  v->_top = top + 1;
  type = vals[top]._type;
  v6 = &vals[top];
  v7 = &v6->_unVal.pTable->__vftable;
  v6->_unVal.nInteger = v1->_unVal.nInteger;
  v8 = v1->_type;
  v6->_type = v1->_type;
  if ( (v8 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6->_unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100398F0
// Name: base_setconsttable
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_setconsttable(SQVM *v)
{
  SQObjectPtr *v1; // edi
  int top; // eax
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // esi
  SQObjectPtr *v6; // eax
  _DWORD *v7; // ecx
  tagSQObjectType v8; // edx

  v1 = &v->_stack._vals[v->_stackbase + 1];
  if ( sq_setconsttable(v) < 0 )
    return -1;
  top = v->_top;
  vals = v->_stack._vals;
  v->_top = top + 1;
  type = vals[top]._type;
  v6 = &vals[top];
  v7 = &v6->_unVal.pTable->__vftable;
  v6->_unVal.nInteger = v1->_unVal.nInteger;
  v8 = v1->_type;
  v6->_type = v1->_type;
  if ( (v8 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6->_unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10039970
// Name: base_seterrorhandler
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_seterrorhandler(SQVM *v)
{
  sq_seterrorhandler(v);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10039980
// Name: base_setdebughook
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_setdebughook(SQVM *v)
{
  sq_setdebughook(v);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10039990
// Name: base_enabledebuginfo
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_enabledebuginfo(SQVM *v)
{
  v->_sharedstate->_debuginfo = v->_stack._vals[v->_stackbase + 1]._type != OT_NULL;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100399C0
// Name: base_getstackinfos
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_getstackinfos(SQVM *v)
{
  SQObjectPtr *v1; // eax
  int v2; // eax
  const char *funcname; // esi
  const char *source; // ebx
  int top; // eax
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // esi
  int v8; // eax
  SQObjectPtr *v9; // ecx
  tagSQObjectType v10; // esi
  int v11; // eax
  int line; // esi
  int v13; // ecx
  SQObjectPtr *v14; // eax
  tagSQObjectType v15; // edx
  _DWORD *v16; // ecx
  int v17; // ecx
  SQObjectPtr *v18; // eax
  tagSQObjectType v19; // esi
  const char *i; // eax
  int v21; // eax
  SQObjectPtr *v22; // edx
  int p_unVal; // esi
  _DWORD *v24; // ecx
  tagSQObjectType v25; // ebx
  int v26; // ecx
  SQObjectPtr *v27; // eax
  tagSQObjectType v28; // esi
  SQSharedState *sharedstate; // ebx
  SQString *v30; // esi
  tagSQObjectType v31; // eax
  _DWORD *v32; // ecx
  int v33; // ecx
  SQObjectPtr *v35; // eax
  tagSQObjectType v36; // esi
  const char *v37; // [esp+0h] [ebp-28h]
  int level; // [esp+10h] [ebp-18h]
  signed int seq; // [esp+14h] [ebp-14h]
  tagSQObjectType v40; // [esp+18h] [ebp-10h]
  tagSQStackInfos v41; // [esp+1Ch] [ebp-Ch] BYREF

  v1 = &v->_stack._vals[v->_top - 1];
  if ( (v1->_type & 0x4000000) != 0 )
  {
    if ( v1->_type == OT_FLOAT )
    {
      level = (int)v1->_unVal.fFloat;
      v2 = sq_stackinfos(v, level, si: &v41);
      goto LABEL_6;
    }
    level = v1->_unVal.nInteger;
  }
  v2 = sq_stackinfos(v, level, si: &v41);
LABEL_6:
  if ( v2 < 0 )
    return 0;
  funcname = "unknown";
  source = "unknown";
  if ( v41.funcname != nullptr )
    funcname = v41.funcname;
  if ( v41.source != nullptr )
    source = v41.source;
  sq_newtable(v);
  sq_pushstring(v, s: "func", len: -1);
  sq_pushstring(v, s: funcname, len: -1);
  top = v->_top;
  if ( top - v->_stackbase >= 3 )
  {
    vals = v->_stack._vals;
    type = vals[top - 3]._type;
    if ( type == OT_TABLE || type == OT_CLASS )
    {
      if ( vals[top - 2]._type == OT_NULL )
      {
        sq_throwerror(v, err: "null is not a valid key");
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
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v37);
  }
  sq_pushstring(v, s: "src", len: -1);
  sq_pushstring(v, s: source, len: -1);
  v8 = v->_top;
  if ( v8 - v->_stackbase >= 3 )
  {
    v9 = v->_stack._vals;
    v10 = v9[v8 - 3]._type;
    if ( v10 == OT_TABLE || v10 == OT_CLASS )
    {
      if ( v9[v8 - 2]._type == OT_NULL )
      {
        sq_throwerror(v, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(this: (SQVM *)v9, self: &v9[v8 - 3], key: &v9[v8 - 2], val: &v9[v8 - 1], bstatic: false);
        SQVM::Pop(this: v, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v37);
  }
  sq_pushstring(v, s: "line", len: -1);
  v11 = v->_top;
  line = v41.line;
  v13 = v11 + 1;
  v14 = &v->_stack._vals[v11];
  v->_top = v13;
  v15 = v14->_type;
  v16 = &v14->_unVal.pTable->__vftable;
  v14->_unVal.nInteger = line;
  v14->_type = OT_INTEGER;
  if ( (v15 & 0x8000000) != 0 && (int)--v16[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v16 + 8))(a1: v16);
  v17 = v->_top;
  if ( v17 - v->_stackbase >= 3 )
  {
    v18 = v->_stack._vals;
    v19 = v18[v17 - 3]._type;
    if ( v19 == OT_TABLE || v19 == OT_CLASS )
    {
      if ( v18[v17 - 2]._type == OT_NULL )
      {
        sq_throwerror(v, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(
          this: (SQVM *)&v18[v17 - 1],
          self: &v18[v17 - 3],
          key: &v18[v17 - 2],
          val: &v18[v17 - 1],
          bstatic: false);
        SQVM::Pop(this: v, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v37);
  }
  sq_pushstring(v, s: "locals", len: -1);
  sq_newtable(v);
  seq = 0;
  for ( i = sq_getlocal(level, idx: 0); i != nullptr; i = sq_getlocal(level, idx: seq) )
  {
    sq_pushstring(v, s: i, len: -1);
    v21 = v->_top;
    v22 = v->_stack._vals;
    v->_top = v21 + 1;
    p_unVal = (int)&v22[v21]._unVal;
    v40 = v22[v21]._type;
    v24 = *(_DWORD **)p_unVal;
    *(_DWORD *)p_unVal = *((_DWORD *)&v22[v21 - 1] - 1);
    v25 = v22[v21 - 2]._type;
    v22[v21]._type = v25;
    if ( (v25 & 0x8000000) != 0 )
      ++*(_DWORD *)(*(_DWORD *)p_unVal + 4);
    if ( (v40 & 0x8000000) != 0 && (int)--v24[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v24 + 8))(a1: v24);
    v26 = v->_top;
    if ( v26 - v->_stackbase >= 3 )
    {
      v27 = v->_stack._vals;
      v28 = v27[v26 - 4]._type;
      if ( v28 == OT_TABLE || v28 == OT_CLASS )
      {
        if ( v27[v26 - 2]._type == OT_NULL )
        {
          sharedstate = v->_sharedstate;
          v30 = StringTable::Add(this: sharedstate->_stringtable, news: "null is not a valid key", len: -1);
          v30->_sharedstate = sharedstate;
          ++v30->_uiRef;
          v31 = v->_lasterror._type;
          v32 = &v->_lasterror._unVal.pTable->__vftable;
          v->_lasterror._unVal.nInteger = (int)v30;
          v->_lasterror._type = OT_STRING;
          ++v30->_uiRef;
          if ( (v31 & 0x8000000) != 0 && (int)--v32[1] <= 0 )
            (*(void (__thiscall **)(_DWORD *))(*v32 + 8))(a1: v32);
          if ( --v30->_uiRef <= 0 )
            v30->Release(this: v30);
        }
        else
        {
          SQVM::NewSlot(
            this: (SQVM *)&v27[v26 - 1],
            self: &v27[v26 - 4],
            key: &v27[v26 - 2],
            val: &v27[v26 - 1],
            bstatic: false);
          SQVM::Pop(this: v, n: 2);
        }
      }
    }
    else
    {
      SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v37);
    }
    SQVM::Pop(this: v, n: 1);
    ++seq;
  }
  v33 = v->_top;
  if ( v33 - v->_stackbase < 3 )
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v37);
    return 1;
  }
  v35 = v->_stack._vals;
  v36 = v35[v33 - 3]._type;
  if ( v36 == OT_TABLE || v36 == OT_CLASS )
  {
    if ( v35[v33 - 2]._type == OT_NULL )
    {
      sq_throwerror(v, err: "null is not a valid key");
      return 1;
    }
    SQVM::NewSlot(
      this: (SQVM *)&v35[v33 - 1],
      self: &v35[v33 - 3],
      key: &v35[v33 - 2],
      val: &v35[v33 - 1],
      bstatic: false);
    SQVM::Pop(this: v, n: 2);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10039E30
// Name: base_assert
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_assert(SQVM *v)
{
  tagSQObjectType type; // eax

  type = v->_stack._vals[v->_stackbase + 1]._type;
  if ( (type & 0x1000000) != 0 && type == OT_FLOAT && v->_stack._vals[v->_stackbase + 1]._unVal.fFloat == 0.0
    || v->_stack._vals[v->_stackbase + 1]._unVal.nInteger == 0 )
  {
    return sq_throwerror(v, err: "assertion failed");
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039E80
// Name: get_slice_params
// Source: json
//------------------------------------------------------------------------------
int __usercall get_slice_params@<eax>(SQVM *v@<ecx>, SQObjectPtr *o@<eax>, int *sidx, int *eidx)
{
  int stackbase; // ecx
  int top; // esi
  SQObjectPtr *vals; // edx
  tagSQObjectValue v8; // ebx
  tagSQObjectType *p_type; // edx
  int v10; // esi
  _DWORD *v11; // ecx
  tagSQObjectType v12; // edx
  int v13; // eax
  SQObjectPtr *v14; // ecx
  tagSQObjectType v15; // edx
  int fFloat; // edx
  tagSQObjectType v17; // edx
  int nInteger; // eax
  int v20; // edx
  tagSQObjectType type; // [esp+Ch] [ebp-4h]

  *sidx = 0;
  stackbase = v->_stackbase;
  top = v->_top;
  *eidx = 0;
  vals = v->_stack._vals;
  v8.pTable = (SQTable *)vals[stackbase]._unVal;
  p_type = &vals[stackbase]._type;
  v10 = top - stackbase;
  type = o->_type;
  v11 = &o->_unVal.pTable->__vftable;
  o->_unVal = v8;
  v12 = *p_type;
  o->_type = v12;
  if ( (v12 & 0x8000000) != 0 )
    ++*(_DWORD *)(v8.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v11[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
  v13 = v->_stackbase;
  v14 = v->_stack._vals;
  v15 = v14[v13 + 1]._type;
  if ( v15 != OT_NULL && (v15 & 0x4000000) != 0 )
  {
    if ( v15 == OT_FLOAT )
      fFloat = (int)v14[v13 + 1]._unVal.fFloat;
    else
      fFloat = v14[v13 + 1]._unVal.nInteger;
    *sidx = fFloat;
  }
  if ( v10 <= 2 )
  {
    v20 = v14[v13]._type;
    if ( v20 > 167772192 )
    {
      if ( v20 == 167772288 )
      {
LABEL_22:
        *eidx = *(_DWORD *)(v14[v13]._unVal.nInteger + 28);
        return 1;
      }
    }
    else
    {
      switch ( v20 )
      {
        case 167772192:
          *eidx = *(_DWORD *)(v14[v13]._unVal.nInteger + 40);
          return 1;
        case 134217744:
          *eidx = *(_DWORD *)(v14[v13]._unVal.nInteger + 20);
          return 1;
        case 134217792:
          goto LABEL_22;
        default:
          break;
      }
    }
    *eidx = sq_aux_invalidtype(v, type: v14[v13]._type);
    return 1;
  }
  v17 = v14[v13 + 2]._type;
  if ( (v17 & 0x4000000) == 0 )
    return 1;
  if ( v17 == OT_FLOAT )
    nInteger = (int)v14[v13 + 2]._unVal.fFloat;
  else
    nInteger = v14[v13 + 2]._unVal.nInteger;
  *eidx = nInteger;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10039FE0
// Name: base_print
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_print(SQVM *v)
{
  int top; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  int v4; // eax
  SQString *v5; // esi
  const char *v6; // eax
  int v7; // eax
  void (*printfunc)(SQVM *, const char *, ...); // ecx
  const char *str; // [esp+Ch] [ebp-4h]

  sq_tostring(v, idx: 2);
  top = v->_top;
  vals = v->_stack._vals;
  v3 = vals[top - 1]._type == OT_STRING;
  v4 = (int)&vals[top - 1];
  if ( v3 )
  {
    v7 = *(_DWORD *)(v4 + 4) + 28;
  }
  else
  {
    v5 = SQVM::PrintObjVal(this: (SQVM *)vals, o: (const tagSQObject *)v);
    ++v5->_uiRef;
    v6 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v6, v5->_val);
    if ( --v5->_uiRef <= 0 )
      v5->Release(this: v5);
    v7 = (int)str;
  }
  printfunc = v->_sharedstate->_printfunc;
  if ( printfunc != nullptr )
    printfunc(a1: v, a2: "%s", v7);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003A080
// Name: base_compilestring
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_compilestring(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  int v3; // ebx
  bool v4; // zf
  int v5; // eax
  SQString *v6; // esi
  const char *v7; // eax
  SQObjectPtr *v8; // ecx
  tagSQObjectType type; // eax
  int v10; // eax
  int v11; // ecx
  SQObjectPtr *v12; // edx
  SQString *v13; // esi
  const char *v14; // eax
  int size; // [esp+10h] [ebp-18h]
  const char *src; // [esp+14h] [ebp-14h]
  char *name; // [esp+18h] [ebp-10h]
  _DWORD v19[3]; // [esp+1Ch] [ebp-Ch] BYREF

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = v->_top - stackbase;
  v4 = vals[stackbase + 1]._type == OT_STRING;
  v5 = (int)&vals[stackbase + 1];
  src = nullptr;
  name = "unnamedbuffer";
  if ( v4 )
  {
    src = (const char *)(*(_DWORD *)(v5 + 4) + 28);
  }
  else
  {
    v6 = SQVM::PrintObjVal(this: (SQVM *)vals, o: (const tagSQObject *)v);
    ++v6->_uiRef;
    v7 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v7, v6->_val);
    if ( --v6->_uiRef <= 0 )
      v6->Release(this: v6);
  }
  v8 = &v->_stack._vals[v->_stackbase + 1];
  type = v8->_type;
  if ( v8->_type > OT_TABLE )
  {
    if ( type == OT_USERDATA )
      goto LABEL_9;
    goto LABEL_18;
  }
  if ( v8->_type == OT_TABLE )
  {
    size = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 40);
  }
  else
  {
    if ( type != OT_STRING )
    {
      if ( type == OT_ARRAY )
      {
LABEL_9:
        v10 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 28);
LABEL_10:
        size = v10;
        goto LABEL_11;
      }
LABEL_18:
      v10 = sq_aux_invalidtype(v, type: v8->_type);
      goto LABEL_10;
    }
    size = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 20);
  }
LABEL_11:
  if ( v3 > 2 )
  {
    v11 = v->_stackbase;
    v12 = v->_stack._vals;
    if ( v12[v11 + 2]._type == OT_STRING )
    {
      name = (char *)(v12[v11 + 2]._unVal.nInteger + 28);
    }
    else
    {
      v13 = SQVM::PrintObjVal(this: (SQVM *)v11, o: (const tagSQObject *)v);
      ++v13->_uiRef;
      v14 = IdType2Name(type: OT_STRING);
      SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v14, v13->_val);
      if ( --v13->_uiRef <= 0 )
        v13->Release(this: v13);
    }
  }
  v19[0] = src;
  v19[2] = size;
  v19[1] = 0;
  return 2 * (sq_compile(v, read: (int (__cdecl *)(void *))v19, p: name, sourcename: nullptr) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A210
// Name: base_newthread
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_newthread(SQVM *v)
{
  int v1; // eax
  SQVM *v2; // eax
  SQObjectPtr *v3; // edx
  int top; // ecx
  SQObjectPtr *vals; // eax
  tagSQObjectType type; // esi
  SQObjectPtr *v7; // eax
  _DWORD *v8; // ecx
  tagSQObjectType v9; // edx

  v1 = 2 * *(_DWORD *)(*(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 36) + 28) + 2;
  if ( v1 < 12 )
    v1 = 12;
  v2 = sq_newthread(friendvm: v, initialstacksize: v1);
  v3 = &v->_stack._vals[v->_top - 2];
  top = v2->_top;
  v2->_top = top + 1;
  vals = v2->_stack._vals;
  type = vals[top]._type;
  v7 = &vals[top];
  v8 = &v7->_unVal.pTable->__vftable;
  v7->_unVal.nInteger = v3->_unVal.nInteger;
  v9 = v3->_type;
  v7->_type = v9;
  if ( (v9 & 0x8000000) != 0 )
    ++*(_DWORD *)(v7->_unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A2A0
// Name: base_suspend
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_suspend(SQVM *v)
{
  if ( v->_suspended != 0 )
    return sq_throwerror(v, err: (const char *)&stru_1009D15C._debughook._unVal);
  if ( v->_nnativecalls == 2 )
    return -666;
  return sq_throwerror(v, err: (const char *)&stru_1009D15C._etraps._size);
}

//------------------------------------------------------------------------------
// Address: 0x1003A2E0
// Name: base_array
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_array(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  int v4; // esi
  SQArray *v5; // edi
  unsigned int v6; // eax
  unsigned int size; // eax
  unsigned int fFloat; // esi
  int top; // eax
  SQObjectPtr *v10; // ecx
  tagSQObjectType type; // edx
  SQObjectPtr *v12; // eax
  _DWORD *v13; // ecx
  sqvector<SQObjectPtr> *v15; // [esp-4h] [ebp-10h]
  SQVM *va; // [esp+14h] [ebp+8h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v4 = (int)&vals[stackbase + 1];
  if ( v->_top - stackbase <= 2 )
  {
    if ( *(_DWORD *)v4 == 83886084 )
      fFloat = (int)vals[stackbase + 1]._unVal.fFloat;
    else
      fFloat = vals[stackbase + 1]._unVal.raw;
    v5 = SQArray::Create(ss: v->_sharedstate, nInitialSize: fFloat);
  }
  else
  {
    v5 = SQArray::Create(ss: v->_sharedstate, nInitialSize: 0);
    if ( *(_DWORD *)v4 == 83886084 )
      v6 = (int)*(float *)(v4 + 4);
    else
      v6 = *(_DWORD *)(v4 + 4);
    v15 = (sqvector<SQObjectPtr> *)&v->_stack._vals[v->_stackbase + 2];
    sqvector<SQObjectPtr>::resize(this: v15, a2: (int)&v5->_values, newsize: v6, fill: (const SQObjectPtr *)v15);
    if ( v5->_values._size <= v5->_values._allocated >> 2 )
    {
      size = v5->_values._size;
      if ( size > 4 )
      {
        va = (SQVM *)v5->_values._size;
        v5->_values._vals = (SQObjectPtr *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: v5->_values._vals,
                                             a3: 8 * size);
        v5->_values._allocated = (unsigned int)va;
      }
    }
  }
  ++v5->_uiRef;
  top = v->_top;
  v10 = v->_stack._vals;
  v->_top = top + 1;
  type = v10[top]._type;
  v12 = &v10[top];
  v13 = &v12->_unVal.pTable->__vftable;
  v12->_unVal.nInteger = (int)v5;
  v12->_type = OT_ARRAY;
  ++v5->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v13[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
  if ( --v5->_uiRef <= 0 )
    v5->Release(this: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A410
// Name: base_type
// Source: json
//------------------------------------------------------------------------------
int __cdecl base_type(SQVM *v)
{
  const char *v1; // eax
  SQSharedState *sharedstate; // ebx
  SQString *v3; // esi
  int top; // eax
  SQObjectPtr *vals; // edx
  _DWORD *v6; // ecx
  SQObjectPtr *v7; // eax
  tagSQObjectType type; // edx

  v1 = IdType2Name(type: v->_stack._vals[v->_stackbase + 1]._type);
  sharedstate = v->_sharedstate;
  v3 = StringTable::Add(this: sharedstate->_stringtable, news: v1, len: -1);
  v3->_sharedstate = sharedstate;
  ++v3->_uiRef;
  top = v->_top;
  vals = v->_stack._vals;
  v->_top = top + 1;
  v6 = &vals[top]._unVal.pTable->__vftable;
  v7 = &vals[top];
  type = v7->_type;
  v7->_unVal.nInteger = (int)v3;
  v7->_type = OT_STRING;
  ++v3->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  if ( --v3->_uiRef <= 0 )
    v3->Release(this: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A4A0
// Name: void sq_base_register(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall sq_base_register(SQVM *v@<eax>)
{
  int top; // eax
  SQObjectPtr *vals; // edx
  _DWORD *v4; // ecx
  tagSQObjectType type; // esi
  SQObjectPtr *v6; // eax
  tagSQObjectType v7; // edx
  tagSQRegFunction *v8; // ebx
  int v9; // esi
  int v10; // eax
  SQObjectPtr *v11; // ecx
  tagSQObjectType v12; // esi
  SQSharedState *sharedstate; // ebx
  SQString *v14; // esi
  tagSQObjectType v15; // eax
  _DWORD *v16; // ecx
  int v17; // eax
  SQObjectPtr *v18; // ecx
  tagSQObjectType v19; // esi
  int v20; // eax
  int v21; // ecx
  SQObjectPtr *v22; // eax
  tagSQObjectType v23; // edx
  _DWORD *v24; // ecx
  int v25; // ecx
  SQObjectPtr *v26; // eax
  tagSQObjectType v27; // esi
  int v28; // eax
  int v29; // edx
  SQObjectPtr *v30; // eax
  tagSQObjectType v31; // edx
  _DWORD *v32; // ecx
  int v33; // ecx
  SQObjectPtr *v34; // eax
  tagSQObjectType v35; // esi
  int v36; // eax
  int v37; // ecx
  SQObjectPtr *v38; // eax
  tagSQObjectType v39; // edx
  _DWORD *v40; // ecx
  int v41; // ecx
  SQObjectPtr *v42; // eax
  tagSQObjectType v43; // esi
  const char *v44; // [esp+0h] [ebp-10h]
  int i; // [esp+Ch] [ebp-4h]

  top = v->_top;
  vals = v->_stack._vals;
  v->_top = top + 1;
  v4 = &vals[top]._unVal.pTable->__vftable;
  type = vals[top]._type;
  v6 = &vals[top];
  v6->_unVal.nInteger = v->_roottable._unVal.nInteger;
  v7 = v->_roottable._type;
  i = 0;
  v6->_type = v7;
  if ( (v7 & 0x8000000) != 0 )
    ++*(_DWORD *)(v6->_unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
  if ( base_funcs_0[0].name != nullptr )
  {
    v8 = base_funcs_0;
    v9 = 0;
    do
    {
      sq_pushstring(v, s: v8->name, len: -1);
      sq_newclosure(v, func: base_funcs_0[v9].f, nfreevars: 0);
      sq_setnativeclosurename(v, name: v8->name);
      sq_setparamscheck(v, typemask: base_funcs_0[v9].typemask, nparamscheck: base_funcs_0[v9].nparamscheck);
      v10 = v->_top;
      if ( v10 - v->_stackbase >= 3 )
      {
        v11 = v->_stack._vals;
        v12 = v11[v10 - 3]._type;
        if ( v12 == OT_TABLE || v12 == OT_CLASS )
        {
          if ( v11[v10 - 2]._type == OT_NULL )
          {
            sharedstate = v->_sharedstate;
            v14 = StringTable::Add(this: sharedstate->_stringtable, news: "null is not a valid key", len: -1);
            v14->_sharedstate = sharedstate;
            ++v14->_uiRef;
            v15 = v->_lasterror._type;
            v16 = &v->_lasterror._unVal.pTable->__vftable;
            v->_lasterror._unVal.nInteger = (int)v14;
            v->_lasterror._type = OT_STRING;
            ++v14->_uiRef;
            if ( (v15 & 0x8000000) != 0 && (int)--v16[1] <= 0 )
              (*(void (__thiscall **)(_DWORD *))(*v16 + 8))(a1: v16);
            if ( --v14->_uiRef <= 0 )
              v14->Release(this: v14);
          }
          else
          {
            SQVM::NewSlot(
              this: (SQVM *)v11,
              self: &v11[v10 - 3],
              key: &v11[v10 - 2],
              val: &v11[v10 - 1],
              bstatic: false);
            SQVM::Pop(this: v, n: 2);
          }
        }
      }
      else
      {
        SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v44);
      }
      v9 = ++i;
      v8 = &base_funcs_0[i];
    }
    while ( v8->name != nullptr );
  }
  sq_pushstring(v, s: "_version_", len: -1);
  sq_pushstring(v, s: "Squirrel 2.2.3 stable", len: -1);
  v17 = v->_top;
  if ( v17 - v->_stackbase >= 3 )
  {
    v18 = v->_stack._vals;
    v19 = v18[v17 - 3]._type;
    if ( v19 == OT_TABLE || v19 == OT_CLASS )
    {
      if ( v18[v17 - 2]._type == OT_NULL )
      {
        sq_throwerror(v, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(this: (SQVM *)v18, self: &v18[v17 - 3], key: &v18[v17 - 2], val: &v18[v17 - 1], bstatic: false);
        SQVM::Pop(this: v, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v44);
  }
  sq_pushstring(v, s: "_charsize_", len: -1);
  v20 = v->_top;
  v21 = v20 + 1;
  v22 = &v->_stack._vals[v20];
  v->_top = v21;
  v23 = v22->_type;
  v24 = &v22->_unVal.pTable->__vftable;
  v22->_unVal.nInteger = 1;
  v22->_type = OT_INTEGER;
  if ( (v23 & 0x8000000) != 0 && (int)--v24[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v24 + 8))(a1: v24);
  v25 = v->_top;
  if ( v25 - v->_stackbase >= 3 )
  {
    v26 = v->_stack._vals;
    v27 = v26[v25 - 3]._type;
    if ( v27 == OT_TABLE || v27 == OT_CLASS )
    {
      if ( v26[v25 - 2]._type == OT_NULL )
      {
        sq_throwerror(v, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(
          this: (SQVM *)&v26[v25 - 1],
          self: &v26[v25 - 3],
          key: &v26[v25 - 2],
          val: &v26[v25 - 1],
          bstatic: false);
        SQVM::Pop(this: v, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v44);
  }
  sq_pushstring(v, s: "_intsize_", len: -1);
  v28 = v->_top;
  v29 = v28 + 1;
  v30 = &v->_stack._vals[v28];
  v->_top = v29;
  v31 = v30->_type;
  v32 = &v30->_unVal.pTable->__vftable;
  v30->_unVal.nInteger = 4;
  v30->_type = OT_INTEGER;
  if ( (v31 & 0x8000000) != 0 && (int)--v32[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v32 + 8))(a1: v32);
  v33 = v->_top;
  if ( v33 - v->_stackbase >= 3 )
  {
    v34 = v->_stack._vals;
    v35 = v34[v33 - 3]._type;
    if ( v35 == OT_TABLE || v35 == OT_CLASS )
    {
      if ( v34[v33 - 2]._type == OT_NULL )
      {
        sq_throwerror(v, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(this: (SQVM *)v33, self: &v34[v33 - 3], key: &v34[v33 - 2], val: &v34[v33 - 1], bstatic: false);
        SQVM::Pop(this: v, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v44);
  }
  sq_pushstring(v, s: "_floatsize_", len: -1);
  v36 = v->_top;
  v37 = v36 + 1;
  v38 = &v->_stack._vals[v36];
  v->_top = v37;
  v39 = v38->_type;
  v40 = &v38->_unVal.pTable->__vftable;
  v38->_unVal.nInteger = 4;
  v38->_type = OT_INTEGER;
  if ( (v39 & 0x8000000) != 0 && (int)--v40[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v40 + 8))(a1: v40);
  v41 = v->_top;
  if ( v41 - v->_stackbase < 3 )
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v44);
    SQVM::Pop(this: v, n: 1);
    return;
  }
  v42 = v->_stack._vals;
  v43 = v42[v41 - 3]._type;
  if ( v43 == OT_TABLE || v43 == OT_CLASS )
  {
    if ( v42[v41 - 2]._type == OT_NULL )
    {
      sq_throwerror(v, err: "null is not a valid key");
      SQVM::Pop(this: v, n: 1);
      return;
    }
    SQVM::NewSlot(
      this: (SQVM *)&v42[v41 - 1],
      self: &v42[v41 - 3],
      key: &v42[v41 - 2],
      val: &v42[v41 - 1],
      bstatic: false);
    SQVM::Pop(this: v, n: 2);
  }
  SQVM::Pop(this: v, n: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1003A920
// Name: default_delegate_len
// Source: json
//------------------------------------------------------------------------------
int __cdecl default_delegate_len(SQVM *v)
{
  SQObjectPtr *v1; // ecx
  tagSQObjectType type; // eax
  int v3; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectType v6; // esi
  SQObjectPtr *v7; // edx
  _DWORD *v8; // ecx

  v1 = &v->_stack._vals[v->_stackbase];
  type = v1->_type;
  if ( v1->_type > OT_TABLE )
  {
    if ( type == OT_USERDATA )
      goto LABEL_5;
LABEL_13:
    v3 = sq_aux_invalidtype(v, type: v1->_type);
    goto LABEL_6;
  }
  if ( v1->_type == OT_TABLE )
  {
    v3 = *(_DWORD *)(v1->_unVal.nInteger + 40);
    goto LABEL_6;
  }
  if ( type == OT_STRING )
  {
    v3 = *(_DWORD *)(v1->_unVal.nInteger + 20);
    goto LABEL_6;
  }
  if ( type != OT_ARRAY )
    goto LABEL_13;
LABEL_5:
  v3 = *(_DWORD *)(v1->_unVal.nInteger + 28);
LABEL_6:
  top = v->_top;
  v->_top = top + 1;
  vals = v->_stack._vals;
  v6 = vals[top]._type;
  v7 = &vals[top];
  v8 = &v7->_unVal.pTable->__vftable;
  v7->_unVal.nInteger = v3;
  v7->_type = OT_INTEGER;
  if ( (v6 & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A9C0
// Name: default_delegate_tofloat
// Source: json
//------------------------------------------------------------------------------
int __cdecl default_delegate_tofloat(SQVM *v)
{
  SQObjectPtr *vals; // eax
  tagSQObjectValue *v2; // esi
  int nInteger; // ecx
  tagSQObjectValue v4; // xmm0_4
  int top; // edx
  tagSQObjectType type; // esi
  _DWORD *v7; // ecx
  bool v8; // zf
  int v10; // edx
  tagSQObjectType v11; // edi
  int p_unVal; // esi
  tagSQObjectType v13; // ebx
  char *v14; // edi
  tagSQObjectType v15; // edi
  _DWORD *v16; // esi
  tagSQObjectValue v17; // xmm0_4
  int v18; // eax
  SQObjectPtr *v19; // edx
  _DWORD *v20; // ecx
  SQObjectPtr *v21; // eax
  tagSQObjectType v22; // edx
  int *pTable; // ecx
  SQObjectPtr res; // [esp+10h] [ebp-8h] BYREF

  vals = v->_stack._vals;
  v2 = (tagSQObjectValue *)&vals[v->_stackbase];
  nInteger = v2->nInteger;
  if ( v2->nInteger <= 83886084 )
  {
    if ( v2->nInteger == 83886084 )
    {
      if ( nInteger != 83886082 )
      {
        v4.pTable = v2[1].pTable;
        goto LABEL_10;
      }
    }
    else
    {
      if ( nInteger == 16777224 )
      {
        v4.fFloat = (float)(v2[1].nInteger != 0);
LABEL_10:
        top = v->_top;
        v->_top = top + 1;
        type = vals[top]._type;
        v7 = &vals[top]._unVal.pTable->__vftable;
        res._unVal = v4;
        vals[top]._unVal.fFloat = v4.fFloat;
        vals[top]._type = OT_FLOAT;
        v8 = (type & 0x8000000) == 0;
        goto LABEL_11;
      }
      if ( nInteger != 83886082 )
        goto LABEL_15;
    }
    v4.fFloat = (float)v2[1].nInteger;
    goto LABEL_10;
  }
  if ( nInteger != 134217744 )
  {
LABEL_15:
    v10 = v->_top;
    v->_top = v10 + 1;
    v7 = &vals[v10]._unVal.pTable->__vftable;
    v11 = vals[v10]._type;
    p_unVal = (int)&vals[v10]._unVal;
    *(_DWORD *)p_unVal = _null_._unVal.pTable;
    v13 = _null_._type;
    vals[v10]._type = _null_._type;
    if ( (v13 & 0x8000000) != 0 )
      ++*(_DWORD *)(*(_DWORD *)p_unVal + 4);
    v8 = (v11 & 0x8000000) == 0;
LABEL_11:
    if ( !v8 && (int)--v7[1] <= 0 )
    {
      (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
      return 1;
    }
    return 1;
  }
  v14 = (char *)(v2[1].nInteger + 28);
  res._type = OT_NULL;
  res._unVal.nInteger = 0;
  if ( str2num(s: v14, &res) != 0 )
  {
    v15 = res._type;
    v16 = &res._unVal.pTable->__vftable;
    if ( res._type == OT_INTEGER )
      v17.fFloat = (float)res._unVal.nInteger;
    else
      v17.pTable = (SQTable *)res._unVal;
    v18 = v->_top;
    v19 = v->_stack._vals;
    v->_top = v18 + 1;
    v20 = &v19[v18]._unVal.pTable->__vftable;
    v21 = &v19[v18];
    v22 = v21->_type;
    res._unVal = v17;
    v21->_unVal.fFloat = v17.fFloat;
    v21->_type = OT_FLOAT;
    if ( (v22 & 0x8000000) != 0 && (int)--v20[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v20 + 8))(a1: v20);
    if ( (v15 & 0x8000000) != 0 && (int)--v16[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v16 + 8))(a1: v16);
    return 1;
  }
  if ( (res._type & 0x8000000) != 0 )
  {
    pTable = (int *)res._unVal.pTable;
    --*(_DWORD *)(res._unVal.nInteger + 4);
    if ( pTable[1] <= 0 )
      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
  return sq_throwerror(v, err: "cannot convert the string");
}

//------------------------------------------------------------------------------
// Address: 0x1003ABA0
// Name: default_delegate_tointeger
// Source: json
//------------------------------------------------------------------------------
int __cdecl default_delegate_tointeger(SQVM *v)
{
  SQObjectPtr *vals; // eax
  int *v2; // esi
  int v3; // ecx
  BOOL v4; // esi
  int v5; // edx
  tagSQObjectType v6; // edi
  _DWORD *v7; // ecx
  int v9; // esi
  int top; // edx
  tagSQObjectType type; // edi
  int v12; // edx
  int p_unVal; // esi
  tagSQObjectType v14; // ebx
  char *v15; // edi
  _DWORD *v16; // edi
  tagSQObjectValue v17; // esi
  int v18; // eax
  int v19; // ecx
  SQObjectPtr *v20; // eax
  tagSQObjectType v21; // edx
  _DWORD *v22; // ecx
  int *pTable; // ecx
  SQObjectPtr res; // [esp+10h] [ebp-8h] BYREF

  vals = v->_stack._vals;
  v2 = (int *)&vals[v->_stackbase];
  v3 = *v2;
  if ( *v2 <= 83886084 )
  {
    if ( *v2 == 83886084 )
    {
      v9 = (int)*((float *)v2 + 1);
      goto LABEL_10;
    }
    if ( v3 != 16777224 )
    {
      if ( v3 == 83886082 )
      {
        v9 = v2[1];
LABEL_10:
        top = v->_top;
        v->_top = top + 1;
        type = vals[top]._type;
        v7 = &vals[top]._unVal.pTable->__vftable;
        vals[top]._unVal.nInteger = v9;
        vals[top]._type = OT_INTEGER;
        goto LABEL_11;
      }
LABEL_15:
      v12 = v->_top;
      v->_top = v12 + 1;
      v7 = &vals[v12]._unVal.pTable->__vftable;
      type = vals[v12]._type;
      p_unVal = (int)&vals[v12]._unVal;
      *(_DWORD *)p_unVal = _null_._unVal.pTable;
      v14 = _null_._type;
      vals[v12]._type = _null_._type;
      if ( (v14 & 0x8000000) != 0 )
        ++*(_DWORD *)(*(_DWORD *)p_unVal + 4);
LABEL_11:
      if ( (type & 0x8000000) != 0 && (int)--v7[1] <= 0 )
      {
LABEL_9:
        (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
        return 1;
      }
      return 1;
    }
    v4 = v2[1] != 0;
    v5 = v->_top;
    v->_top = v5 + 1;
    v6 = vals[v5]._type;
    v7 = &vals[v5]._unVal.pTable->__vftable;
    vals[v5]._unVal.nInteger = v4;
    vals[v5]._type = OT_INTEGER;
    if ( (v6 & 0x8000000) != 0 && (int)--v7[1] <= 0 )
      goto LABEL_9;
    return 1;
  }
  if ( v3 != 134217744 )
    goto LABEL_15;
  v15 = (char *)(v2[1] + 28);
  res._type = OT_NULL;
  res._unVal.nInteger = 0;
  if ( str2num(s: v15, &res) != 0 )
  {
    v16 = &res._unVal.pTable->__vftable;
    v17.nInteger = (int)res._unVal.fFloat;
    if ( res._type != OT_FLOAT )
      v17.pTable = (SQTable *)res._unVal;
    v18 = v->_top;
    v19 = v18 + 1;
    v20 = &v->_stack._vals[v18];
    v->_top = v19;
    v21 = v20->_type;
    v22 = &v20->_unVal.pTable->__vftable;
    v20->_unVal = v17;
    v20->_type = OT_INTEGER;
    if ( (v21 & 0x8000000) != 0 && (int)--v22[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v22 + 8))(a1: v22);
    if ( (res._type & 0x8000000) != 0 && (int)--v16[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v16 + 8))(a1: v16);
    return 1;
  }
  if ( (res._type & 0x8000000) != 0 )
  {
    pTable = (int *)res._unVal.pTable;
    --*(_DWORD *)(res._unVal.nInteger + 4);
    if ( pTable[1] <= 0 )
      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
  return sq_throwerror(v, err: "cannot convert the string");
}

//------------------------------------------------------------------------------
// Address: 0x1003AD90
// Name: default_delegate_tostring
// Source: json
//------------------------------------------------------------------------------
int __cdecl default_delegate_tostring(SQVM *v)
{
  sq_tostring(v, idx: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003ADB0
// Name: obj_delegate_weakref
// Source: json
//------------------------------------------------------------------------------
int __cdecl obj_delegate_weakref(SQVM *v)
{
  sq_weakref(v);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003ADD0
// Name: obj_clear
// Source: json
//------------------------------------------------------------------------------
int __cdecl obj_clear(SQVM *v)
{
  return sq_clear(v);
}

//------------------------------------------------------------------------------
// Address: 0x1003ADE0
// Name: number_delegate_tochar
// Source: json
//------------------------------------------------------------------------------
int __cdecl number_delegate_tochar(SQVM *v)
{
  SQVM *v1; // edi
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v4; // zf
  SQObjectPtr *v5; // eax
  SQSharedState *sharedstate; // ebx
  SQString *v7; // esi
  int top; // eax
  SQObjectPtr *v9; // edx
  _DWORD *v10; // ecx
  SQObjectPtr *v11; // eax
  tagSQObjectType type; // edx

  v1 = v;
  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v4 = vals[stackbase]._type == OT_FLOAT;
  v5 = &vals[stackbase];
  if ( v4 )
    HIBYTE(v) = (int)v5->_unVal.fFloat;
  else
    HIBYTE(v) = LOBYTE(v5->_unVal.fFloat);
  sharedstate = v1->_sharedstate;
  v7 = StringTable::Add(this: sharedstate->_stringtable, news: (const char *)&v + 3, len: 1);
  v7->_sharedstate = sharedstate;
  ++v7->_uiRef;
  top = v1->_top;
  v9 = v1->_stack._vals;
  v1->_top = top + 1;
  v10 = &v9[top]._unVal.pTable->__vftable;
  v11 = &v9[top];
  type = v11->_type;
  v11->_unVal.nInteger = (int)v7;
  v11->_type = OT_STRING;
  ++v7->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  if ( --v7->_uiRef <= 0 )
    v7->Release(this: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003AE90
// Name: table_rawdelete
// Source: json
//------------------------------------------------------------------------------
int __cdecl table_rawdelete(SQVM *v)
{
  return 2 * (sq_rawdeleteslot((const tagSQObject *)v) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003AEB0
// Name: container_rawexists
// Source: json
//------------------------------------------------------------------------------
int __cdecl container_rawexists(SQVM *v)
{
  bool v1; // sf
  int top; // eax
  int v3; // ecx
  SQObjectPtr *v4; // eax
  tagSQObjectType type; // edx
  _DWORD *v6; // ecx

  v1 = sq_rawget(v) < 0;
  top = v->_top;
  v3 = top + 1;
  v4 = &v->_stack._vals[top];
  v->_top = v3;
  type = v4->_type;
  v6 = &v4->_unVal.pTable->__vftable;
  v4->_type = OT_BOOL;
  v4->_unVal.nInteger = !v1;
  if ( (type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003AF20
// Name: table_rawset
// Source: json
//------------------------------------------------------------------------------
int __cdecl table_rawset(SQVM *v)
{
  return sq_rawset(v);
}

//------------------------------------------------------------------------------
// Address: 0x1003AF30
// Name: table_rawget
// Source: json
//------------------------------------------------------------------------------
int __cdecl table_rawget(SQVM *v)
{
  return 2 * (sq_rawget(v) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003AF50
// Name: array_append
// Source: json
//------------------------------------------------------------------------------
int __cdecl array_append(SQVM *v)
{
  return sq_arrayappend(v);
}

//------------------------------------------------------------------------------
// Address: 0x1003AF60
// Name: array_extend
// Source: json
//------------------------------------------------------------------------------
int __cdecl array_extend(SQVM *v)
{
  SQObjectPtr *v1; // eax

  v1 = &v->_stack._vals[v->_stackbase];
  SQArray::Extend(this: v1[1]._unVal.pArray, a: v1->_unVal.pArray);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003AF80
// Name: array_reverse
// Source: json
//------------------------------------------------------------------------------
int __cdecl array_reverse(SQVM *v)
{
  return sq_arrayreverse(v);
}

//------------------------------------------------------------------------------
// Address: 0x1003AF90
// Name: array_pop
// Source: json
//------------------------------------------------------------------------------
int __cdecl array_pop(tagSQObject *v)
{
  return 2 * (sq_arraypop(v) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003AFB0
// Name: array_top
// Source: json
//------------------------------------------------------------------------------
int __cdecl array_top(SQVM *v)
{
  SQObjectPtr *vals; // edx
  tagSQObjectValue v2; // eax
  tagSQObjectType *v3; // ebx
  int top; // eax
  _DWORD *v5; // edi
  tagSQObjectValue *p_unVal; // esi
  _DWORD *nInteger; // ecx
  tagSQObjectType v8; // ebx
  tagSQObjectType va; // [esp+Ch] [ebp+8h]

  vals = v->_stack._vals;
  v2.pTable = (SQTable *)vals[v->_stackbase]._unVal;
  if ( *(int *)(v2.nInteger + 28) <= 0 )
    return sq_throwerror(v, err: "top() on a empty array");
  v3 = (tagSQObjectType *)(*(_DWORD *)(v2.nInteger + 24) + 8 * *(_DWORD *)(v2.nInteger + 28) - 8);
  top = v->_top;
  v->_top = top + 1;
  v5 = *((_DWORD **)v3 + 1);
  p_unVal = &vals[top]._unVal;
  va = vals[top]._type;
  nInteger = (_DWORD *)p_unVal->nInteger;
  p_unVal->nInteger = (int)v5;
  v8 = *v3;
  vals[top]._type = v8;
  if ( (v8 & 0x8000000) != 0 )
    ++v5[1];
  if ( (va & 0x8000000) != 0 && (int)--nInteger[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*nInteger + 8))(a1: nInteger);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003B040
// Name: array_insert
// Source: json
//------------------------------------------------------------------------------
int __cdecl array_insert(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  signed int fFloat; // edx
  tagSQObjectValue v4; // ebx
  _DWORD *v5; // esi
  __int32 v6; // edi
  SQObjectPtr val; // [esp+10h] [ebp-8h] BYREF

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  if ( vals[stackbase + 1]._type == OT_FLOAT )
    fFloat = (int)vals[stackbase + 1]._unVal.fFloat;
  else
    fFloat = vals[stackbase + 1]._unVal.nInteger;
  v4.pTable = (SQTable *)vals[stackbase]._unVal;
  if ( fFloat < 0 || fFloat > *(_DWORD *)(v4.nInteger + 28) )
    return sq_throwerror(v, err: "index out of range");
  v5 = &vals[stackbase + 2]._unVal.pTable->__vftable;
  val._type = vals[stackbase + 2]._type;
  v6 = val._type & 0x8000000;
  val._unVal.nInteger = (int)v5;
  if ( (val._type & 0x8000000) != 0 )
    ++v5[1];
  sqvector<SQObjectPtr>::insert(this: (sqvector<SQObjectPtr> *)vals, a2: (int *)(v4.nInteger + 24), idx: fFloat, &val);
  if ( v6 != 0 && (int)--v5[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v5 + 8))(a1: v5);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003B0E0
// Name: array_remove
// Source: json
//------------------------------------------------------------------------------
int __cdecl array_remove(SQVM *v)
{
  SQObjectPtr *v1; // esi
  tagSQObjectType type; // eax
  signed int fFloat; // ecx
  sqvector<SQObjectPtr> *v5; // ecx
  signed int nInteger; // eax
  int v7; // edi
  SQArray *v8; // ecx
  int top; // eax
  _DWORD *v10; // esi
  int v11; // ecx
  SQObjectPtr *v12; // eax
  tagSQObjectType v13; // edx
  tagSQObjectType v14; // ebx
  _DWORD *v15; // ecx
  int v16; // edi
  int v17; // esi
  int *pTable; // ecx
  SQObjectPtr val; // [esp+10h] [ebp-8h] BYREF

  v1 = &v->_stack._vals[v->_stackbase];
  type = v1[1]._type;
  if ( (type & 0x4000000) == 0 )
    return sq_throwerror(v, err: "wrong type");
  val._type = OT_NULL;
  val._unVal.nInteger = 0;
  if ( type == OT_FLOAT )
    fFloat = (int)v1[1]._unVal.fFloat;
  else
    fFloat = v1[1]._unVal.nInteger;
  if ( SQArray::Get(nidx: fFloat, &val, this: v1->_unVal.pArray) != 0 )
  {
    if ( v1[1]._type == OT_FLOAT )
      nInteger = (int)v1[1]._unVal.fFloat;
    else
      nInteger = v1[1]._unVal.nInteger;
    v7 = v1->_unVal.nInteger;
    if ( nInteger >= 0 && nInteger < *(_DWORD *)(v7 + 28) )
    {
      sqvector<SQObjectPtr>::remove(this: v5, a2: (int *)(v7 + 24), idx: nInteger);
      SQArray::ShrinkIfNeeded(this: v8, a2: v7);
    }
    top = v->_top;
    v10 = &val._unVal.pTable->__vftable;
    v11 = top + 1;
    v12 = &v->_stack._vals[top];
    v13 = val._type;
    v->_top = v11;
    v14 = v12->_type;
    v15 = &v12->_unVal.pTable->__vftable;
    v16 = v13 & 0x8000000;
    v12->_unVal.nInteger = (int)v10;
    v12->_type = v13;
    if ( (v13 & 0x8000000) != 0 )
      ++v10[1];
    if ( (v14 & 0x8000000) != 0 && (int)--v15[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15);
    if ( v16 != 0 && (int)--v10[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
    return 1;
  }
  else
  {
    v17 = sq_throwerror(v, err: "idx out of range");
    if ( (val._type & 0x8000000) != 0 )
    {
      pTable = (int *)val._unVal.pTable;
      --*(_DWORD *)(val._unVal.nInteger + 4);
      if ( pTable[1] <= 0 )
        (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
    }
    return v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B220
// Name: array_resize
// Source: json
//------------------------------------------------------------------------------
int __cdecl array_resize(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  _DWORD *v3; // ebx
  bool v4; // zf
  tagSQObjectType type; // edx
  unsigned int fFloat; // edx
  tagSQObjectValue v7; // edi
  int v8; // esi
  unsigned int v9; // edi
  SQObjectPtr fill; // [esp+10h] [ebp-8h] BYREF

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = nullptr;
  v4 = (vals[stackbase + 1]._type & 0x4000000) == 0;
  fill._type = OT_NULL;
  fill._unVal.nInteger = 0;
  if ( v4 )
    return sq_throwerror(v, err: "size must be a number");
  if ( v->_top - stackbase > 2 )
  {
    type = vals[stackbase + 2]._type;
    v3 = &vals[stackbase + 2]._unVal.pTable->__vftable;
    fill._unVal.nInteger = (int)v3;
    fill._type = type;
    if ( (type & 0x8000000) != 0 )
      ++v3[1];
  }
  if ( vals[stackbase + 1]._type == OT_FLOAT )
    fFloat = (int)vals[stackbase + 1]._unVal.fFloat;
  else
    fFloat = vals[stackbase + 1]._unVal.raw;
  v7.pTable = (SQTable *)vals[stackbase]._unVal;
  v8 = v7.nInteger + 24;
  sqvector<SQObjectPtr>::resize(this: (sqvector<SQObjectPtr> *)vals, a2: v7.nInteger + 24, newsize: fFloat, &fill);
  if ( *(_DWORD *)(v7.nInteger + 28) <= *(_DWORD *)(v7.nInteger + 32) >> 2 )
  {
    v9 = *(_DWORD *)(v7.nInteger + 28);
    if ( v9 > 4 )
    {
      *(_DWORD *)v8 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)v8, a3: 8 * v9);
      *(_DWORD *)(v8 + 8) = v9;
    }
  }
  if ( (fill._type & 0x8000000) != 0 && (int)--v3[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(a1: v3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003B310
// Name: bool _qsort_compare(struct SQVM __near *,struct SQObjectPtr __near &,struct SQObjectPtr __near &,struct SQObjectPtr __near &,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __usercall _qsort_compare@<al>(SQVM *v@<ecx>, int func@<eax>, SQObjectPtr *arr, SQObjectPtr *a, SQObjectPtr *b)
{
  int v7; // eax
  SQObjectPtr *vals; // edx
  _DWORD *v9; // ecx
  tagSQObjectType type; // esi
  SQObjectPtr *v11; // eax
  tagSQObjectType v12; // edx
  int v13; // eax
  SQObjectPtr *v14; // edx
  _DWORD *v15; // ecx
  tagSQObjectType v16; // esi
  SQObjectPtr *v17; // eax
  tagSQObjectType v18; // edx
  int v19; // eax
  int v20; // ecx
  SQObjectPtr *v21; // eax
  tagSQObjectValue v22; // esi
  _DWORD *v23; // ecx
  tagSQObjectType v24; // ebx
  tagSQObjectType v25; // edx
  SQObjectPtr *v26; // eax
  tagSQObjectType fFloat; // eax
  const char *v28; // [esp+0h] [ebp-14h]
  int top; // [esp+10h] [ebp-4h]

  if ( func < 0 )
    return SQVM::ObjCmp(this: v, o1: arr, o2: a, result: (int *)b);
  top = v->_top - v->_stackbase;
  sq_push(v, idx: func);
  v7 = v->_top;
  vals = v->_stack._vals;
  v->_top = v7 + 1;
  v9 = &vals[v7]._unVal.pTable->__vftable;
  type = vals[v7]._type;
  v11 = &vals[v7];
  v11->_unVal.nInteger = v->_roottable._unVal.nInteger;
  v12 = v->_roottable._type;
  v11->_type = v12;
  if ( (v12 & 0x8000000) != 0 )
    ++*(_DWORD *)(v11->_unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  v13 = v->_top;
  v14 = v->_stack._vals;
  v->_top = v13 + 1;
  v15 = &v14[v13]._unVal.pTable->__vftable;
  v16 = v14[v13]._type;
  v17 = &v14[v13];
  v17->_unVal.nInteger = arr->_unVal.nInteger;
  v18 = arr->_type;
  v17->_type = arr->_type;
  if ( (v18 & 0x8000000) != 0 )
    ++*(_DWORD *)(v17->_unVal.nInteger + 4);
  if ( (v16 & 0x8000000) != 0 && (int)--v15[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15);
  v19 = v->_top;
  v20 = v19 + 1;
  v21 = &v->_stack._vals[v19];
  v->_top = v20;
  v22.pTable = (SQTable *)a->_unVal;
  v23 = &v21->_unVal.pTable->__vftable;
  v24 = v21->_type;
  v21->_unVal = v22;
  v25 = a->_type;
  v21->_type = a->_type;
  if ( (v25 & 0x8000000) != 0 )
    ++*(_DWORD *)(v22.nInteger + 4);
  if ( (v24 & 0x8000000) != 0 && (int)--v23[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v23 + 8))(a1: v23);
  if ( sq_call(v, params: 3, retval: 1u, raiseerror: 0) >= 0 )
  {
    v26 = &v->_stack._vals[v->_top - 1];
    if ( (v26->_type & 0x4000000) != 0 )
    {
      if ( v26->_type == OT_FLOAT )
        fFloat = (int)v26->_unVal.fFloat;
      else
        fFloat = (tagSQObjectType)v26->_unVal.pTable;
      b->_type = fFloat;
    }
    sq_settop(v, newtop: top);
    return true;
  }
  else
  {
    if ( v->_lasterror._type != OT_STRING )
      SQVM::Raise_Error(this: (SQVM *)&stru_1009C130, s: v28);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B4A0
// Name: bool _qsort(struct SQVM __near *,struct SQObjectPtr __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl _qsort(SQVM *v, SQObjectPtr *arr, int l, int r, int func)
{
  tagSQObjectValue v5; // ebx
  _DWORD *v6; // edi
  _DWORD *v7; // esi
  SQObjectPtr *v8; // eax
  tagSQObjectValue v9; // edx
  int v10; // edi
  int v11; // eax
  tagSQObjectType type; // edx
  _DWORD *v13; // ecx
  int v14; // edi
  int v15; // eax
  int *v16; // ecx
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int *v20; // ecx
  int v21; // eax
  tagSQObjectType v22; // edi
  int v23; // edx
  tagSQObjectType *v24; // eax
  _DWORD *v25; // ecx
  bool v26; // zf
  int *pTable; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // edx
  int *v32; // ecx
  tagSQObjectType *v33; // ebx
  tagSQObjectType v34; // edx
  tagSQObjectType v35; // eax
  _DWORD *v36; // ecx
  const char *v37; // [esp+0h] [ebp-40h]
  int j; // [esp+10h] [ebp-30h]
  __int32 v39; // [esp+18h] [ebp-28h]
  __int32 v40; // [esp+18h] [ebp-28h]
  __int32 v41; // [esp+1Ch] [ebp-24h]
  int ret; // [esp+20h] [ebp-20h] BYREF
  int i; // [esp+24h] [ebp-1Ch]
  int *v44; // [esp+28h] [ebp-18h]
  int *v45; // [esp+2Ch] [ebp-14h]
  SQObjectPtr pivot; // [esp+30h] [ebp-10h] BYREF
  SQObjectPtr t; // [esp+38h] [ebp-8h]

  v5.pTable = (SQTable *)arr->_unVal;
  v6 = nullptr;
  v7 = nullptr;
  pivot._type = OT_NULL;
  t._type = OT_NULL;
  if ( l >= r )
  {
LABEL_57:
    if ( (t._type & 0x8000000) != 0 && (int)--v7[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
    if ( (pivot._type & 0x8000000) != 0 && (int)--v6[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
    return 1;
  }
  else
  {
    v8 = (SQObjectPtr *)(8 * l + *(_DWORD *)(v5.nInteger + 24));
    v9.pTable = (SQTable *)v8->_unVal;
    pivot = *v8;
    v41 = pivot._type & 0x8000000;
    if ( (pivot._type & 0x8000000) != 0 )
      ++*(_DWORD *)(v9.nInteger + 4);
    v10 = l;
    j = r + 1;
    while ( 1 )
    {
      do
      {
        i = ++v10;
        if ( v10 > r )
          goto LABEL_9;
        if ( !_qsort_compare(
                v,
                func,
                arr: (SQObjectPtr *)(*(_DWORD *)(v5.nInteger + 24) + 8 * v10),
                a: &pivot,
                b: (SQObjectPtr *)&ret) )
        {
LABEL_28:
          v26 = (t._type & 0x8000000) == 0;
          goto LABEL_29;
        }
      }
      while ( ret <= 0 );
      do
      {
LABEL_9:
        if ( --j < 0 )
        {
          SQVM::Raise_Error(this: (SQVM *)&stru_1009C130.SQCollectable::_sharedstate, s: v37);
          goto LABEL_28;
        }
        if ( !_qsort_compare(
                v,
                func,
                arr: (SQObjectPtr *)(*(_DWORD *)(v5.nInteger + 24) + 8 * j),
                a: &pivot,
                b: (SQObjectPtr *)&ret) )
          goto LABEL_28;
      }
      while ( ret > 0 );
      v11 = *(_DWORD *)(v5.nInteger + 24);
      type = t._type;
      v13 = v7;
      if ( v10 >= j )
        break;
      v14 = 8 * v10;
      v7 = *(_DWORD **)(v11 + v14 + 4);
      t._type = *(_DWORD *)(v11 + v14);
      v39 = t._type & 0x8000000;
      if ( (t._type & 0x8000000) != 0 )
        ++v7[1];
      if ( (type & 0x8000000) != 0 && (int)--v13[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
      v15 = *(_DWORD *)(v5.nInteger + 24);
      v16 = *(int **)(v15 + v14);
      v45 = *(int **)(v15 + v14 + 4);
      v17 = *(_DWORD *)(v15 + 8 * j + 4);
      v44 = v16;
      v18 = v15 + v14 + 4;
      *(_DWORD *)v18 = v17;
      v19 = *(_DWORD *)(v15 + 8 * j);
      *(_DWORD *)(v15 + v14) = v19;
      if ( (v19 & 0x8000000) != 0 )
        ++*(_DWORD *)(*(_DWORD *)v18 + 4);
      if ( ((unsigned int)v44 & 0x8000000) != 0 )
      {
        v20 = v45;
        --v45[1];
        if ( v20[1] <= 0 )
          (*(void (__thiscall **)(int *))(*v20 + 8))(a1: v20);
      }
      v21 = *(_DWORD *)(v5.nInteger + 24);
      v22 = t._type;
      v23 = *(_DWORD *)(v21 + 8 * j);
      v24 = (tagSQObjectType *)(8 * j + v21);
      v25 = *((_DWORD **)v24 + 1);
      *((_DWORD *)v24 + 1) = v7;
      *v24 = v22;
      if ( v39 != 0 )
        ++v7[1];
      if ( (v23 & 0x8000000) != 0 && (int)--v25[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v25 + 8))(a1: v25);
      v10 = i;
    }
    v7 = *(_DWORD **)(v11 + 8 * l + 4);
    t._type = *(_DWORD *)(v11 + 8 * l);
    v40 = t._type & 0x8000000;
    if ( (t._type & 0x8000000) != 0 )
      ++v7[1];
    if ( (type & 0x8000000) != 0 && (int)--v13[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
    v29 = *(_DWORD *)(v5.nInteger + 24);
    v45 = *(int **)(v29 + 8 * l);
    v30 = v29 + 8 * l + 4;
    v44 = *(int **)v30;
    *(_DWORD *)v30 = *(_DWORD *)(v29 + 8 * j + 4);
    v31 = *(_DWORD *)(v29 + 8 * j);
    *(_DWORD *)(v29 + 8 * l) = v31;
    if ( (v31 & 0x8000000) != 0 )
      ++*(_DWORD *)(*(_DWORD *)v30 + 4);
    if ( ((unsigned int)v45 & 0x8000000) != 0 )
    {
      v32 = v44;
      --v44[1];
      if ( v32[1] <= 0 )
        (*(void (__thiscall **)(int *))(*v32 + 8))(a1: v32);
    }
    v33 = (tagSQObjectType *)(8 * j + *(_DWORD *)(v5.nInteger + 24));
    v34 = t._type;
    v35 = *v33;
    v36 = *((_DWORD **)v33 + 1);
    *((_DWORD *)v33 + 1) = v7;
    *v33 = v34;
    if ( v40 != 0 )
      ++v7[1];
    if ( (v35 & 0x8000000) != 0 && (int)--v36[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v36 + 8))(a1: v36);
    if ( _qsort(v, arr, l, r: j - 1, func) )
    {
      if ( _qsort(v, arr, l: j + 1, r, func) )
      {
        v6 = &pivot._unVal.pTable->__vftable;
        goto LABEL_57;
      }
      v26 = v40 == 0;
    }
    else
    {
      v26 = v40 == 0;
    }
LABEL_29:
    if ( !v26 && (int)--v7[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
    if ( v41 != 0 )
    {
      pTable = (int *)pivot._unVal.pTable;
      --*(_DWORD *)(pivot._unVal.nInteger + 4);
      if ( pTable[1] <= 0 )
        (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B840
// Name: array_sort
// Source: json
//------------------------------------------------------------------------------
int __cdecl array_sort(SQVM *v)
{
  SQObjectPtr *v1; // eax
  int v2; // edx
  int v3; // esi
  tagSQObjectType type; // edi

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = *(_DWORD *)(v1->_unVal.nInteger + 28);
  v3 = -1;
  if ( v2 <= 1 )
    return 0;
  type = v1[1]._type;
  if ( type == OT_CLOSURE || type == OT_NATIVECLOSURE )
    v3 = 2;
  if ( _qsort(v, arr: v1, l: 0, r: v2 - 1, func: v3) != 0 )
    return 0;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003B8A0
// Name: array_slice
// Source: json
//------------------------------------------------------------------------------
int __cdecl array_slice(SQVM *v)
{
  int *pTable; // ecx
  int v3; // ebx
  _DWORD *v4; // esi
  int v5; // ecx
  int v6; // eax
  int v7; // edi
  SQArray *v8; // eax
  _DWORD *v9; // ecx
  int v10; // edi
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // ecx
  tagSQObjectType *v14; // eax
  _DWORD *v15; // ecx
  tagSQObjectType type; // edx
  int top; // eax
  SQObjectPtr *vals; // edx
  tagSQObjectType v19; // edi
  SQObjectPtr *v20; // eax
  _DWORD *v21; // edx
  int *v22; // ecx
  int eidx; // [esp+10h] [ebp-18h] BYREF
  int sidx; // [esp+14h] [ebp-14h] BYREF
  SQObjectPtr o; // [esp+18h] [ebp-10h] BYREF
  SQObjectPtr t; // [esp+20h] [ebp-8h] BYREF

  o._type = OT_NULL;
  o._unVal.nInteger = 0;
  if ( get_slice_params(v, &o, &sidx, &eidx) == -1 )
  {
    if ( (o._type & 0x8000000) != 0 )
    {
      pTable = (int *)o._unVal.pTable;
      --*(_DWORD *)(o._unVal.nInteger + 4);
      if ( pTable[1] <= 0 )
        (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
    }
    return -1;
  }
  v3 = sidx;
  v4 = &o._unVal.pTable->__vftable;
  v5 = *(_DWORD *)(o._unVal.nInteger + 28);
  if ( sidx < 0 )
    v3 = v5 + sidx;
  v6 = eidx;
  if ( eidx < 0 )
  {
    v6 = v5 + eidx;
    eidx += v5;
  }
  if ( v6 < v3 )
  {
    v7 = sq_throwerror(v, err: (const char *)&stru_1009C130._roottable._unVal);
    if ( (o._type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
    return v7;
  }
  if ( v6 > v5 )
  {
    v7 = sq_throwerror(v, err: (const char *)&stru_1009C130._errorhandler._unVal);
    if ( (o._type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
    {
      (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
      return v7;
    }
    return v7;
  }
  v8 = SQArray::Create(ss: v->_sharedstate, nInitialSize: v6 - v3);
  v9 = nullptr;
  v10 = 0;
  v11 = &v8->__vftable;
  t._type = OT_NULL;
  t._unVal.nInteger = 0;
  if ( v3 < eidx )
  {
    do
    {
      SQArray::Get(nidx: v10 + v3, val: &t, this: o._unVal.pArray);
      if ( v10 >= 0 && v10 < v11[7] )
      {
        v12 = v11[6];
        v13 = *(_DWORD *)(v12 + 8 * v10);
        v14 = (tagSQObjectType *)(v12 + 8 * v10);
        sidx = v13;
        v15 = *((_DWORD **)v14 + 1);
        v14[1] = (tagSQObjectType)t._unVal.pTable;
        type = t._type;
        *v14 = t._type;
        if ( (type & 0x8000000) != 0 )
          ++*(_DWORD *)(t._unVal.nInteger + 4);
        if ( (sidx & 0x8000000) != 0 && (int)--v15[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15);
      }
      ++v10;
    }
    while ( v10 + v3 < eidx );
    v9 = &t._unVal.pTable->__vftable;
  }
  ++v11[1];
  top = v->_top;
  v->_top = top + 1;
  vals = v->_stack._vals;
  v19 = vals[top]._type;
  v20 = &vals[top];
  v21 = &v20->_unVal.pTable->__vftable;
  v20->_unVal.nInteger = (int)v11;
  v20->_type = OT_ARRAY;
  ++v11[1];
  if ( (v19 & 0x8000000) != 0 && (int)--v21[1] <= 0 )
  {
    (*(void (__thiscall **)(_DWORD *))(*v21 + 8))(a1: v21);
    v9 = &t._unVal.pTable->__vftable;
  }
  if ( (int)--v11[1] <= 0 )
  {
    (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
    v9 = &t._unVal.pTable->__vftable;
  }
  if ( (t._type & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  if ( (o._type & 0x8000000) != 0 )
  {
    v22 = (int *)o._unVal.pTable;
    --*(_DWORD *)(o._unVal.nInteger + 4);
    if ( v22[1] <= 0 )
      (*(void (__thiscall **)(int *))(*v22 + 8))(a1: v22);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003BAD0
// Name: string_slice
// Source: json
//------------------------------------------------------------------------------
int __cdecl string_slice(SQVM *v)
{
  int *pTable; // ecx
  int v3; // ecx
  _DWORD *v4; // ebx
  int v5; // edx
  int v6; // eax
  int v7; // esi
  SQString *v8; // esi
  int top; // eax
  SQObjectPtr *vals; // edx
  _DWORD *v11; // ecx
  SQObjectPtr *v12; // eax
  tagSQObjectType type; // edx
  int sidx; // [esp+10h] [ebp-10h] BYREF
  int eidx; // [esp+14h] [ebp-Ch] BYREF
  SQObjectPtr o; // [esp+18h] [ebp-8h] BYREF

  o._type = OT_NULL;
  o._unVal.nInteger = 0;
  if ( get_slice_params(v, &o, &sidx, &eidx) < 0 )
  {
    if ( (o._type & 0x8000000) != 0 )
    {
      pTable = (int *)o._unVal.pTable;
      --*(_DWORD *)(o._unVal.nInteger + 4);
      if ( pTable[1] <= 0 )
        (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
    }
    return -1;
  }
  v3 = sidx;
  v4 = &o._unVal.pTable->__vftable;
  v5 = *(_DWORD *)(o._unVal.nInteger + 20);
  if ( sidx < 0 )
    v3 = v5 + sidx;
  v6 = eidx;
  if ( eidx < 0 )
    v6 = v5 + eidx;
  if ( v6 < v3 )
  {
    v7 = sq_throwerror(v, err: (const char *)&stru_1009C130._roottable._unVal);
    if ( (o._type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
    return v7;
  }
  if ( v6 > v5 )
  {
    v7 = sq_throwerror(v, err: (const char *)&stru_1009C130._errorhandler._unVal);
    if ( (o._type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
    {
      (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
      return v7;
    }
    return v7;
  }
  eidx = (int)v->_sharedstate;
  v8 = StringTable::Add(
         this: *(StringTable **)(eidx + 20),
         news: (const char *)(o._unVal.nInteger + v3 + 28),
         len: v6 - v3);
  v8->_sharedstate = (SQSharedState *)eidx;
  ++v8->_uiRef;
  top = v->_top;
  vals = v->_stack._vals;
  v->_top = top + 1;
  v11 = &vals[top]._unVal.pTable->__vftable;
  v12 = &vals[top];
  type = v12->_type;
  v12->_unVal.nInteger = (int)v8;
  v12->_type = OT_STRING;
  ++v8->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v11[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
  if ( --v8->_uiRef <= 0 )
    v8->Release(this: v8);
  if ( (o._type & 0x8000000) != 0 && (int)--v4[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(a1: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003BC60
// Name: string_find
// Source: json
//------------------------------------------------------------------------------
int __cdecl string_find(SQVM *v)
{
  int stackbase; // edx
  int v2; // eax
  SQObjectPtr *vals; // ebx
  SQVM *v4; // ecx
  SQString *v5; // esi
  const char *v6; // eax
  SQSharedState *sharedstate; // ebx
  SQString *v8; // esi
  tagSQObjectType v9; // eax
  _DWORD *v10; // ecx
  tagSQObjectType type; // eax
  int fFloat; // esi
  tagSQObjectType v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned __int8 *substr; // [esp+10h] [ebp-8h]
  const char *str; // [esp+14h] [ebp-4h]

  stackbase = v->_stackbase;
  v2 = v->_top - stackbase;
  if ( v2 > 1 )
  {
    vals = v->_stack._vals;
    v4 = (SQVM *)&vals[stackbase];
    if ( v4->__vftable == (SQVM_vtbl *)134217744 )
    {
      str = (const char *)(v4->_uiRef + 28);
      if ( v4->_weakref == (SQWeakRef *)134217744 )
      {
        substr = (unsigned __int8 *)&v4->_next[1]._uiRef;
        if ( v2 > 2 && ((type = vals[stackbase + 2]._type) & 0x4000000) != 0 )
        {
          if ( type == OT_FLOAT )
            fFloat = (int)vals[stackbase + 2]._unVal.fFloat;
          else
            fFloat = vals[stackbase + 2]._unVal.nInteger;
        }
        else
        {
          fFloat = 0;
        }
        v14 = (tagSQObjectType)v4->__vftable;
        if ( (int)v4->__vftable > 167772192 )
        {
          if ( v14 == OT_USERDATA )
            goto LABEL_22;
        }
        else
        {
          if ( v4->__vftable == (SQVM_vtbl *)167772192 )
          {
            v15 = *(_DWORD *)(v4->_uiRef + 40);
            goto LABEL_23;
          }
          if ( v14 == OT_STRING )
          {
            v15 = *(_DWORD *)(v4->_uiRef + 20);
            goto LABEL_23;
          }
          if ( v14 == OT_ARRAY )
          {
LABEL_22:
            v15 = *(_DWORD *)(v4->_uiRef + 28);
LABEL_23:
            if ( v15 <= fFloat )
              return 0;
            if ( fFloat < 0 )
              return 0;
            strstr(str1: (unsigned __int8 *)&str[fFloat], str2: substr);
            if ( v16 == 0 )
              return 0;
            sq_pushinteger(v, n: (tagSQObjectValue)(v16 - (_DWORD)str));
            return 1;
          }
        }
        v15 = sq_aux_invalidtype(v, type: (tagSQObjectType)v4->__vftable);
        goto LABEL_23;
      }
    }
    v5 = SQVM::PrintObjVal(this: v4, o: (const tagSQObject *)v);
    ++v5->_uiRef;
    v6 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v6, v5->_val);
    if ( --v5->_uiRef <= 0 )
      v5->Release(this: v5);
  }
  sharedstate = v->_sharedstate;
  v8 = StringTable::Add(this: sharedstate->_stringtable, news: "invalid param", len: -1);
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
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003BE20
// Name: string_tolower
// Source: json
//------------------------------------------------------------------------------
int __cdecl string_tolower(SQVM *v)
{
  tagSQObjectValue v2; // eax
  SQSharedState *v3; // ebx
  char *scratchpad; // eax
  const char *v5; // ecx
  char *v6; // esi
  SQSharedState *sharedstate; // ebx
  SQString *v8; // esi
  int top; // eax
  SQObjectPtr *vals; // edx
  _DWORD *v11; // ecx
  SQObjectPtr *v12; // eax
  tagSQObjectType type; // edx
  int v15; // [esp+0h] [ebp-18h]
  int v16; // [esp+10h] [ebp-8h]
  const char *sThis; // [esp+14h] [ebp-4h]
  const char *sThisa; // [esp+14h] [ebp-4h]
  char *sNew; // [esp+20h] [ebp+8h]

  v2.pTable = (SQTable *)v->_stack._vals[v->_stackbase]._unVal;
  v3 = *(SQSharedState **)(v2.nInteger + 20);
  v16 = (int)v3;
  sThis = (const char *)(v2.nInteger + 28);
  if ( (int)v3 <= 0 )
    scratchpad = v->_sharedstate->_scratchpad;
  else
    scratchpad = SQSharedState::GetScratchPad(this: v3, size: v15);
  sNew = scratchpad;
  if ( (int)v3 > 0 )
  {
    v5 = (const char *)(sThis - scratchpad);
    v6 = scratchpad;
    for ( sThisa = (const char *)(sThis - scratchpad); ; v5 = sThisa )
    {
      *v6 = tolower(c: v6[(_DWORD)v5]);
      ++v6;
      v3 = (SQSharedState *)((char *)v3 - 1);
      if ( v3 == nullptr )
        break;
    }
    scratchpad = sNew;
  }
  sharedstate = v->_sharedstate;
  v8 = StringTable::Add(this: sharedstate->_stringtable, news: scratchpad, len: v16);
  v8->_sharedstate = sharedstate;
  ++v8->_uiRef;
  top = v->_top;
  vals = v->_stack._vals;
  v->_top = top + 1;
  v11 = &vals[top]._unVal.pTable->__vftable;
  v12 = &vals[top];
  type = v12->_type;
  v12->_unVal.nInteger = (int)v8;
  v12->_type = OT_STRING;
  ++v8->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v11[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
  if ( --v8->_uiRef <= 0 )
    v8->Release(this: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003BF10
// Name: string_toupper
// Source: json
//------------------------------------------------------------------------------
int __cdecl string_toupper(SQVM *v)
{
  tagSQObjectValue v2; // eax
  SQSharedState *v3; // ebx
  char *scratchpad; // eax
  const char *v5; // ecx
  char *v6; // esi
  SQSharedState *sharedstate; // ebx
  SQString *v8; // esi
  int top; // eax
  SQObjectPtr *vals; // edx
  _DWORD *v11; // ecx
  SQObjectPtr *v12; // eax
  tagSQObjectType type; // edx
  int v15; // [esp+0h] [ebp-18h]
  int v16; // [esp+10h] [ebp-8h]
  const char *sThis; // [esp+14h] [ebp-4h]
  const char *sThisa; // [esp+14h] [ebp-4h]
  char *sNew; // [esp+20h] [ebp+8h]

  v2.pTable = (SQTable *)v->_stack._vals[v->_stackbase]._unVal;
  v3 = *(SQSharedState **)(v2.nInteger + 20);
  v16 = (int)v3;
  sThis = (const char *)(v2.nInteger + 28);
  if ( (int)v3 <= 0 )
    scratchpad = v->_sharedstate->_scratchpad;
  else
    scratchpad = SQSharedState::GetScratchPad(this: v3, size: v15);
  sNew = scratchpad;
  if ( (int)v3 > 0 )
  {
    v5 = (const char *)(sThis - scratchpad);
    v6 = scratchpad;
    for ( sThisa = (const char *)(sThis - scratchpad); ; v5 = sThisa )
    {
      *v6 = toupper(c: v6[(_DWORD)v5]);
      ++v6;
      v3 = (SQSharedState *)((char *)v3 - 1);
      if ( v3 == nullptr )
        break;
    }
    scratchpad = sNew;
  }
  sharedstate = v->_sharedstate;
  v8 = StringTable::Add(this: sharedstate->_stringtable, news: scratchpad, len: v16);
  v8->_sharedstate = sharedstate;
  ++v8->_uiRef;
  top = v->_top;
  vals = v->_stack._vals;
  v->_top = top + 1;
  v11 = &vals[top]._unVal.pTable->__vftable;
  v12 = &vals[top];
  type = v12->_type;
  v12->_unVal.nInteger = (int)v8;
  v12->_type = OT_STRING;
  ++v8->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v11[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
  if ( --v8->_uiRef <= 0 )
    v8->Release(this: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003C000
// Name: closure_pcall
// Source: json
//------------------------------------------------------------------------------
int __cdecl closure_pcall(SQVM *v)
{
  return 2 * (sq_call(v, params: v->_top - v->_stackbase - 1, retval: 1u, raiseerror: 0) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003C030
// Name: closure_call
// Source: json
//------------------------------------------------------------------------------
int __cdecl closure_call(SQVM *v)
{
  return 2 * (sq_call(v, params: v->_top - v->_stackbase - 1, retval: 1u, raiseerror: 1u) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003C060
// Name: _closure_acall
// Source: json
//------------------------------------------------------------------------------
int __usercall closure_acall@<eax>(SQVM *v@<esi>, unsigned int raiseerror)
{
  SQObjectPtr *vals; // eax
  SQObjectPtr *v3; // edi
  int top; // edx
  tagSQObjectValue v5; // ebx
  tagSQObjectType v6; // edi
  int v7; // eax
  int i; // edi
  int v9; // eax
  SQObjectPtr *v10; // edx
  tagSQObjectValue v11; // ebx
  SQObjectPtr *v12; // eax
  _DWORD *v13; // ecx
  tagSQObjectType v14; // edx
  SQArray *aparams; // [esp+8h] [ebp-10h]
  _DWORD *v17; // [esp+Ch] [ebp-Ch]
  tagSQObjectType v18; // [esp+Ch] [ebp-Ch]
  tagSQObjectType type; // [esp+10h] [ebp-8h]
  int nparams; // [esp+14h] [ebp-4h]

  vals = v->_stack._vals;
  v3 = &vals[v->_stackbase];
  aparams = v3[1]._unVal.pArray;
  nparams = aparams->_values._size;
  top = v->_top;
  v->_top = top + 1;
  type = vals[top]._type;
  v17 = &vals[top]._unVal.pTable->__vftable;
  v5.pTable = (SQTable *)v3->_unVal;
  vals[top]._unVal = v5;
  v6 = v3->_type;
  vals[top]._type = v6;
  if ( (v6 & 0x8000000) != 0 )
    ++*(_DWORD *)(v5.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v17[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v17 + 8))(a1: v17);
  v7 = nparams;
  for ( i = 0; i < nparams; ++i )
  {
    v9 = v->_top;
    v10 = aparams->_values._vals;
    v->_top = v9 + 1;
    v11.pTable = (SQTable *)v10[i]._unVal;
    v12 = &v->_stack._vals[v9];
    v18 = v12->_type;
    v13 = &v12->_unVal.pTable->__vftable;
    v12->_unVal = v11;
    v14 = v10[i]._type;
    v12->_type = v14;
    if ( (v14 & 0x8000000) != 0 )
      ++*(_DWORD *)(v11.nInteger + 4);
    if ( (v18 & 0x8000000) != 0 && (int)--v13[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
    v7 = nparams;
  }
  return 2 * (sq_call(v, params: v7, retval: 1u, raiseerror) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003C150
// Name: closure_acall
// Source: json
//------------------------------------------------------------------------------
int __cdecl closure_acall(SQVM *v)
{
  return closure_acall(v, raiseerror: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x1003C170
// Name: closure_pacall
// Source: json
//------------------------------------------------------------------------------
int __cdecl closure_pacall(SQVM *v)
{
  return closure_acall(v, raiseerror: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003C190
// Name: closure_bindenv
// Source: json
//------------------------------------------------------------------------------
int __cdecl closure_bindenv(SQVM *v)
{
  return 2 * (sq_bindenv(v) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003C1B0
// Name: closure_getinfos
// Source: json
//------------------------------------------------------------------------------
int __cdecl closure_getinfos(SQVM *v)
{
  SQVM *v1; // ebx
  SQObjectPtr *vals; // ecx
  int stackbase; // eax
  tagSQObjectType type; // edx
  SQObjectPtr *v5; // eax
  SQSharedState *sharedstate; // ecx
  tagSQObjectValue v7; // eax
  SQTable *v8; // edi
  int v9; // eax
  int v10; // ecx
  bool v11; // zf
  SQFunctionProto *v12; // esi
  int v13; // eax
  SQObjectPtr *v14; // edx
  tagSQObjectValue v15; // esi
  int v16; // eax
  _DWORD *v17; // ecx
  tagSQObjectType v18; // edx
  StringTable *stringtable; // ecx
  SQString *v20; // esi
  tagSQObjectType v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  _DWORD *v25; // eax
  _DWORD *v26; // ecx
  SQSharedState *v27; // eax
  StringTable *v28; // ecx
  SQString *v29; // eax
  tagSQObjectValue v30; // eax
  int v31; // eax
  StringTable *v32; // ecx
  SQString *v33; // eax
  tagSQObjectValue v34; // eax
  StringTable *v35; // ecx
  SQString *v36; // eax
  tagSQObjectValue v37; // eax
  StringTable *v38; // ecx
  SQString *v39; // eax
  tagSQObjectValue v40; // eax
  SQSharedState *v41; // esi
  SQString *v42; // eax
  tagSQObjectValue v43; // eax
  tagSQObjectValue v44; // eax
  tagSQObjectValue v45; // eax
  SQSharedState *v46; // esi
  SQString *v47; // eax
  tagSQObjectValue v48; // eax
  int v49; // eax
  SQSharedState *v50; // esi
  SQString *v51; // eax
  tagSQObjectValue v52; // esi
  tagSQObjectValue v53; // eax
  int v54; // ecx
  SQSharedState *v55; // esi
  SQString *v56; // eax
  tagSQObjectValue v57; // eax
  int v58; // eax
  unsigned int v59; // eax
  SQArray *v60; // esi
  tagSQObjectType v61; // eax
  _DWORD *v62; // ecx
  tagSQObjectValue v63; // eax
  int i; // esi
  int v65; // edx
  _DWORD *v66; // ecx
  int *v67; // eax
  int v68; // edx
  SQSharedState *v69; // esi
  SQString *v70; // eax
  tagSQObjectValue v71; // eax
  tagSQObjectValue v72; // eax
  int top; // eax
  SQObjectPtr *v74; // edx
  _DWORD *v75; // ecx
  SQObjectPtr *v76; // eax
  tagSQObjectType v77; // edx
  SQFunctionProto *f; // [esp+Ch] [ebp-24h]
  int n; // [esp+10h] [ebp-20h] BYREF
  int v81; // [esp+14h] [ebp-1Ch]
  SQObjectPtr key; // [esp+18h] [ebp-18h] BYREF
  SQObjectPtr typecheck; // [esp+20h] [ebp-10h] BYREF
  SQObjectPtr params; // [esp+28h] [ebp-8h] BYREF

  v1 = v;
  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  type = vals[stackbase]._type;
  v5 = &vals[stackbase];
  sharedstate = v->_sharedstate;
  v7.pTable = (SQTable *)v5->_unVal;
  params._type = type;
  n = (int)sharedstate;
  params._unVal = v7;
  v8 = (SQTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 44);
  if ( v8 != nullptr )
  {
    v8->_uiRef = 0;
    v8->_weakref = nullptr;
    v8->__vftable = (SQTable_vtbl *)&SQTable::`vftable';
    SQTable::AllocNodes(this: v8, nSize: 4);
    v9 = n;
    v8->_next = nullptr;
    v8->_usednodes = 0;
    v8->_delegate = nullptr;
    v8->_sharedstate = (SQSharedState *)v9;
    v8->_prev = nullptr;
    v8->_next = *(SQCollectable **)(v9 + 68);
    v10 = *(_DWORD *)(v9 + 68);
    if ( v10 != 0 )
      *(_DWORD *)(v10 + 16) = v8;
    *(_DWORD *)(v9 + 68) = v8;
  }
  v11 = params._type == OT_CLOSURE;
  v8->_delegate = nullptr;
  if ( v11 )
  {
    v12 = *(SQFunctionProto **)(params._unVal.nInteger + 36);
    f = v12;
    typecheck._type = v12->_nparameters + v12->_varparams;
    params._unVal.nInteger = (int)SQArray::Create(ss: v->_sharedstate, nInitialSize: typecheck._type);
    params._type = OT_ARRAY;
    ++*(_DWORD *)(params._unVal.nInteger + 4);
    v13 = 0;
    for ( n = 0; v13 < v12->_nparameters; n = v13 )
    {
      v14 = &v12->_parameters[v13];
      if ( v13 >= 0 )
      {
        if ( v13 < *(_DWORD *)(params._unVal.nInteger + 28) )
        {
          v15.pTable = (SQTable *)v14->_unVal;
          v16 = 8 * v13 + *(_DWORD *)(params._unVal.nInteger + 24);
          key._type = *(_DWORD *)v16;
          v17 = *(_DWORD **)(v16 + 4);
          *(tagSQObjectValue *)(v16 + 4) = v15;
          v18 = v14->_type;
          *(_DWORD *)v16 = v18;
          if ( (v18 & 0x8000000) != 0 )
            ++*(_DWORD *)(v15.nInteger + 4);
          if ( (key._type & 0x8000000) != 0 && (int)--v17[1] <= 0 )
            (*(void (__thiscall **)(_DWORD *))(*v17 + 8))(a1: v17);
          v13 = n;
        }
        v12 = f;
      }
      ++v13;
    }
    if ( v12->_varparams )
    {
      stringtable = v->_sharedstate->_stringtable;
      key._type = (tagSQObjectType)v->_sharedstate;
      v20 = StringTable::Add(this: stringtable, news: "...", len: -1);
      v21 = typecheck._type;
      v20->_sharedstate = (SQSharedState *)key._type;
      ++v20->_uiRef;
      v22 = v21 - 1;
      if ( v22 >= 0 && v22 < *(_DWORD *)(params._unVal.nInteger + 28) )
      {
        v23 = *(_DWORD *)(params._unVal.nInteger + 24);
        v24 = *(_DWORD *)(v23 + 8 * v22);
        v25 = (_DWORD *)(v23 + 8 * v22);
        v26 = (_DWORD *)v25[1];
        v25[1] = v20;
        *v25 = 134217744;
        ++v20->_uiRef;
        if ( (v24 & 0x8000000) != 0 && (int)--v26[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v26 + 8))(a1: v26);
      }
      if ( --v20->_uiRef <= 0 )
        v20->Release(this: v20);
      v12 = f;
    }
    v27 = v->_sharedstate;
    n = 16777224;
    v81 = 0;
    v28 = v27->_stringtable;
    typecheck._type = (tagSQObjectType)v27;
    v29 = StringTable::Add(this: v28, news: (const char *)&stru_1009C130._callsstack, len: -1);
    v29->_sharedstate = (SQSharedState *)typecheck._type;
    key._unVal.nInteger = (int)v29;
    key._type = OT_STRING;
    ++v29->_uiRef;
    SQTable::NewSlot(this: v8, &key, val: (const SQObjectPtr *)&n);
    if ( (key._type & 0x8000000) != 0 )
    {
      v30.pTable = (SQTable *)key._unVal;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( *(int *)(v30.nInteger + 4) <= 0 )
        key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
    }
    if ( (n & 0x8000000) != 0 )
    {
      v31 = v81;
      --*(_DWORD *)(v81 + 4);
      if ( *(int *)(v31 + 4) <= 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v81 + 8))(a1: v81);
    }
    v32 = v->_sharedstate->_stringtable;
    typecheck._type = (tagSQObjectType)v->_sharedstate;
    v33 = StringTable::Add(this: v32, news: "name", len: -1);
    v33->_sharedstate = (SQSharedState *)typecheck._type;
    key._unVal.nInteger = (int)v33;
    key._type = OT_STRING;
    ++v33->_uiRef;
    SQTable::NewSlot(this: v8, &key, val: &v12->_name);
    if ( (key._type & 0x8000000) != 0 )
    {
      v34.pTable = (SQTable *)key._unVal;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( *(int *)(v34.nInteger + 4) <= 0 )
        key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
    }
    v35 = v->_sharedstate->_stringtable;
    typecheck._type = (tagSQObjectType)v->_sharedstate;
    v36 = StringTable::Add(this: v35, news: "src", len: -1);
    v36->_sharedstate = (SQSharedState *)typecheck._type;
    key._unVal.nInteger = (int)v36;
    key._type = OT_STRING;
    ++v36->_uiRef;
    SQTable::NewSlot(this: v8, &key, val: &v12->_sourcename);
    if ( (key._type & 0x8000000) != 0 )
    {
      v37.pTable = (SQTable *)key._unVal;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( *(int *)(v37.nInteger + 4) <= 0 )
        key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
    }
    v38 = v->_sharedstate->_stringtable;
    typecheck._type = (tagSQObjectType)v->_sharedstate;
    v39 = StringTable::Add(this: v38, news: (const char *)&stru_1009C130._alloccallsstacksize, len: -1);
    v39->_sharedstate = (SQSharedState *)typecheck._type;
    key._unVal.nInteger = (int)v39;
    key._type = OT_STRING;
    ++v39->_uiRef;
    SQTable::NewSlot(this: v8, &key, val: &params);
    if ( (key._type & 0x8000000) != 0 )
    {
      v40.pTable = (SQTable *)key._unVal;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( *(int *)(v40.nInteger + 4) <= 0 )
        key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
    }
    v11 = !v12->_varparams;
    v41 = v->_sharedstate;
    key._type = OT_BOOL;
    key._unVal.nInteger = !v11;
    v42 = StringTable::Add(
            this: v41->_stringtable,
            news: (const char *)&stru_1009C130._callstackdata._allocated,
            len: -1);
    v42->_sharedstate = v41;
    typecheck._unVal.nInteger = (int)v42;
    typecheck._type = OT_STRING;
    ++v42->_uiRef;
    SQTable::NewSlot(this: v8, key: &typecheck, val: &key);
    if ( (typecheck._type & 0x8000000) != 0 )
    {
      v43.pTable = (SQTable *)typecheck._unVal;
      --*(_DWORD *)(typecheck._unVal.nInteger + 4);
      if ( *(int *)(v43.nInteger + 4) <= 0 )
        typecheck._unVal.pTable->Release(this: (struct SQTable *)typecheck._unVal.nInteger);
    }
    if ( (key._type & 0x8000000) != 0 )
    {
      v44.pTable = (SQTable *)key._unVal;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( *(int *)(v44.nInteger + 4) <= 0 )
        key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
    }
    if ( (params._type & 0x8000000) != 0 )
    {
      v45.pTable = (SQTable *)params._unVal;
      --*(_DWORD *)(params._unVal.nInteger + 4);
      if ( *(int *)(v45.nInteger + 4) <= 0 )
        params._unVal.pTable->Release(this: (struct SQTable *)params._unVal.nInteger);
    }
  }
  else
  {
    v46 = v->_sharedstate;
    n = 16777224;
    v81 = 1;
    v47 = StringTable::Add(this: v46->_stringtable, news: (const char *)&stru_1009C130._callsstack, len: -1);
    v47->_sharedstate = v46;
    key._unVal.nInteger = (int)v47;
    key._type = OT_STRING;
    ++v47->_uiRef;
    SQTable::NewSlot(this: v8, &key, val: (const SQObjectPtr *)&n);
    if ( (key._type & 0x8000000) != 0 )
    {
      v48.pTable = (SQTable *)key._unVal;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( *(int *)(v48.nInteger + 4) <= 0 )
        key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
    }
    if ( (n & 0x8000000) != 0 )
    {
      v49 = v81;
      --*(_DWORD *)(v81 + 4);
      if ( *(int *)(v49 + 4) <= 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v81 + 8))(a1: v81);
    }
    v50 = v->_sharedstate;
    v51 = StringTable::Add(this: v50->_stringtable, news: "name", len: -1);
    v51->_sharedstate = v50;
    v52.pTable = (SQTable *)params._unVal;
    key._unVal.nInteger = (int)v51;
    key._type = OT_STRING;
    ++v51->_uiRef;
    SQTable::NewSlot(this: v8, &key, val: (const SQObjectPtr *)(v52.nInteger + 64));
    if ( (key._type & 0x8000000) != 0 )
    {
      v53.pTable = (SQTable *)key._unVal;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( *(int *)(v53.nInteger + 4) <= 0 )
        key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
    }
    v54 = *(_DWORD *)(v52.nInteger + 24);
    v55 = v->_sharedstate;
    n = 83886082;
    v81 = v54;
    v56 = StringTable::Add(this: v55->_stringtable, news: (const char *)&stru_1009C130._etraps._size, len: -1);
    v56->_sharedstate = v55;
    key._unVal.nInteger = (int)v56;
    key._type = OT_STRING;
    ++v56->_uiRef;
    SQTable::NewSlot(this: v8, &key, val: (const SQObjectPtr *)&n);
    if ( (key._type & 0x8000000) != 0 )
    {
      v57.pTable = (SQTable *)key._unVal;
      --*(_DWORD *)(key._unVal.nInteger + 4);
      if ( *(int *)(v57.nInteger + 4) <= 0 )
        key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
    }
    if ( (n & 0x8000000) != 0 )
    {
      v58 = v81;
      --*(_DWORD *)(v81 + 4);
      if ( *(int *)(v58 + 4) <= 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v81 + 8))(a1: v81);
    }
    v59 = *(_DWORD *)(params._unVal.nInteger + 32);
    typecheck._type = OT_NULL;
    typecheck._unVal.nInteger = 0;
    if ( v59 != 0 )
    {
      v60 = SQArray::Create(ss: v->_sharedstate, nInitialSize: v59);
      ++v60->_uiRef;
      v61 = typecheck._type;
      v62 = &typecheck._unVal.pTable->__vftable;
      typecheck._unVal.nInteger = (int)v60;
      typecheck._type = OT_ARRAY;
      ++v60->_uiRef;
      if ( (v61 & 0x8000000) != 0 && (int)--v62[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v62 + 8))(a1: v62);
      if ( --v60->_uiRef <= 0 )
        v60->Release(this: v60);
      v63.pTable = (SQTable *)params._unVal;
      for ( i = 0; (unsigned int)i < *(_DWORD *)(params._unVal.nInteger + 32); ++i )
      {
        key._unVal.nInteger = *(_DWORD *)(*(_DWORD *)(v63.nInteger + 28) + 4 * i);
        if ( i >= 0 && i < *(_DWORD *)(typecheck._unVal.nInteger + 28) )
        {
          v65 = *(_DWORD *)(typecheck._unVal.nInteger + 24);
          v66 = *(_DWORD **)(v65 + 8 * i + 4);
          v67 = (int *)(v65 + 8 * i);
          v68 = *v67;
          v67[1] = key._unVal.nInteger;
          *v67 = 83886082;
          if ( (v68 & 0x8000000) != 0 && (int)--v66[1] <= 0 )
            (*(void (__thiscall **)(_DWORD *))(*v66 + 8))(a1: v66);
          v1 = v;
        }
        v63.pTable = (SQTable *)params._unVal;
      }
    }
    v69 = v1->_sharedstate;
    v70 = StringTable::Add(this: v69->_stringtable, news: (const char *)&stru_1009C130._foreignptr, len: -1);
    v70->_sharedstate = v69;
    params._type = OT_STRING;
    params._unVal.nInteger = (int)v70;
    ++v70->_uiRef;
    SQTable::NewSlot(this: v8, key: &params, val: &typecheck);
    if ( (params._type & 0x8000000) != 0 )
    {
      v71.pTable = (SQTable *)params._unVal;
      --*(_DWORD *)(params._unVal.nInteger + 4);
      if ( *(int *)(v71.nInteger + 4) <= 0 )
        params._unVal.pTable->Release(this: (struct SQTable *)params._unVal.nInteger);
    }
    if ( (typecheck._type & 0x8000000) != 0 )
    {
      v72.pTable = (SQTable *)typecheck._unVal;
      --*(_DWORD *)(typecheck._unVal.nInteger + 4);
      if ( *(int *)(v72.nInteger + 4) <= 0 )
        typecheck._unVal.pTable->Release(this: (struct SQTable *)typecheck._unVal.nInteger);
    }
  }
  ++v8->_uiRef;
  top = v1->_top;
  v74 = v1->_stack._vals;
  v1->_top = top + 1;
  v75 = &v74[top]._unVal.pTable->__vftable;
  v76 = &v74[top];
  v77 = v76->_type;
  v76->_unVal.nInteger = (int)v8;
  v76->_type = OT_TABLE;
  ++v8->_uiRef;
  if ( (v77 & 0x8000000) != 0 && (int)--v75[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v75 + 8))(a1: v75);
  if ( --v8->_uiRef <= 0 )
    v8->Release(this: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003C920
// Name: generator_getstatus
// Source: json
//------------------------------------------------------------------------------
int __cdecl generator_getstatus(SQVM *v)
{
  int v1; // eax
  int v2; // eax
  SQSharedState *sharedstate; // ebx
  SQString *v4; // edi
  int top; // eax
  SQObjectPtr *vals; // edx
  _DWORD *v7; // ecx
  SQObjectPtr *v8; // eax
  tagSQObjectType type; // edx
  const char *v11; // [esp-4h] [ebp-14h]

  v1 = *(_DWORD *)(v->_stack._vals[v->_stackbase]._unVal.nInteger + 116);
  if ( v1 != 0 )
  {
    v2 = v1 - 1;
    if ( v2 != 0 )
    {
      if ( v2 != 1 )
        return 1;
      v11 = "dead";
    }
    else
    {
      v11 = "suspended";
    }
  }
  else
  {
    v11 = "running";
  }
  sharedstate = v->_sharedstate;
  v4 = StringTable::Add(this: sharedstate->_stringtable, news: v11, len: -1);
  v4->_sharedstate = sharedstate;
  ++v4->_uiRef;
  top = v->_top;
  vals = v->_stack._vals;
  v->_top = top + 1;
  v7 = &vals[top]._unVal.pTable->__vftable;
  v8 = &vals[top];
  type = v8->_type;
  v8->_unVal.nInteger = (int)v4;
  v8->_type = OT_STRING;
  ++v4->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  if ( --v4->_uiRef <= 0 )
    v4->Release(this: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003C9F0
// Name: thread_call
// Source: json
//------------------------------------------------------------------------------
int __cdecl thread_call(SQVM *v)
{
  SQObjectPtr *vals; // ecx
  int stackbase; // eax
  tagSQObjectValue *pTable; // esi
  tagSQObjectType type; // ecx
  int v5; // ebx
  tagSQObjectValue v6; // eax
  tagSQObjectValue v7; // ecx
  int v8; // ebx
  int v9; // edx
  tagSQObjectValue *v10; // eax
  _DWORD *v11; // ecx
  tagSQObjectValue v12; // edx
  int v13; // eax
  SQObjectPtr *v14; // edx
  SQObjectPtr *v15; // edx
  tagSQObjectValue v16; // eax
  tagSQObjectValue v17; // ebx
  tagSQObjectType *v18; // eax
  _DWORD *v19; // ecx
  tagSQObjectType v20; // edx
  int top; // eax
  tagSQObjectType *v22; // edx
  SQObjectPtr *v23; // ecx
  tagSQObjectValue v24; // ebx
  tagSQObjectType v25; // edi
  SQObjectPtr *v26; // eax
  _DWORD *v27; // ecx
  tagSQObjectType v28; // edx
  _DWORD *v30; // ecx
  tagSQObjectType v31; // edx
  tagSQObjectType v32; // eax
  int v33; // edi
  int i; // [esp+Ch] [ebp-Ch]
  int ia; // [esp+Ch] [ebp-Ch]
  tagSQObjectType v36; // [esp+10h] [ebp-8h]
  int nparams; // [esp+14h] [ebp-4h]

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  pTable = (tagSQObjectValue *)vals[stackbase]._unVal.pTable;
  type = vals[stackbase]._type;
  v5 = type & 0x8000000;
  if ( (type & 0x8000000) != 0 )
    ++pTable[1].nInteger;
  if ( type == OT_THREAD )
  {
    v6.pTable = pTable[14].pTable;
    v7.pTable = pTable[8].pTable;
    v8 = v->_top - v->_stackbase;
    pTable[14].nInteger = v6.nInteger + 1;
    v9 = *(_DWORD *)(v7.nInteger + 8 * v6.nInteger);
    v10 = (tagSQObjectValue *)(v7.nInteger + 8 * v6.nInteger);
    v11 = &v10[1].pTable->__vftable;
    i = v9;
    v10[1].pTable = pTable[17].pTable;
    v12.pTable = pTable[16].pTable;
    nparams = v8;
    v10->pTable = v12.pTable;
    if ( (v12.nInteger & 0x8000000) != 0 )
      ++*(_DWORD *)(v10[1].nInteger + 4);
    if ( (i & 0x8000000) != 0 && (int)--v11[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v11 + 8))(a1: v11);
    v13 = 2;
    ia = 2;
    if ( v8 + 1 > 2 )
    {
      do
      {
        v14 = v->_stack._vals;
        if ( v13 < 0 )
          v15 = &v14[v13 + v->_top];
        else
          v15 = &v14[v13 - 1 + v->_stackbase];
        v16.pTable = pTable[14].pTable;
        pTable[14].nInteger = v16.nInteger + 1;
        v17.pTable = (SQTable *)v15->_unVal;
        v18 = (tagSQObjectType *)(pTable[8].nInteger + 8 * v16.nInteger);
        v36 = *v18;
        v19 = *((_DWORD **)v18 + 1);
        v18[1] = (tagSQObjectType)v17.pTable;
        v20 = v15->_type;
        *v18 = v20;
        if ( (v20 & 0x8000000) != 0 )
          ++*(_DWORD *)(v17.nInteger + 4);
        if ( (v36 & 0x8000000) != 0 && (int)--v19[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v19 + 8))(a1: v19);
        v8 = nparams;
        v13 = ia + 1;
        ia = v13;
      }
      while ( v13 < nparams + 1 );
    }
    if ( sq_call(v: (SQVM *)pTable, params: v8, retval: 1u, raiseerror: 0) < 0 )
    {
      v30 = &v->_lasterror._unVal.pTable->__vftable;
      v31 = v->_lasterror._type;
      v->_lasterror._unVal = pTable[19];
      v32 = (tagSQObjectType)pTable[18].pTable;
      v->_lasterror._type = v32;
      if ( (v32 & 0x8000000) != 0 )
        ++*(_DWORD *)(v->_lasterror._unVal.nInteger + 4);
      if ( (v31 & 0x8000000) != 0 && (int)--v30[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v30 + 8))(a1: v30);
      if ( --pTable[1].nInteger <= 0 )
        (*(void (__thiscall **)(tagSQObjectValue *))(pTable->nInteger + 8))(a1: pTable);
      return -1;
    }
    else
    {
      top = v->_top;
      v22 = (tagSQObjectType *)(pTable[8].nInteger + 8 * pTable[14].nInteger - 8);
      v->_top = top + 1;
      v23 = v->_stack._vals;
      v24.pTable = (SQTable *)v22[1];
      v25 = v23[top]._type;
      v26 = &v23[top];
      v27 = &v26->_unVal.pTable->__vftable;
      v26->_unVal = v24;
      v28 = *v22;
      v26->_type = v28;
      if ( (v28 & 0x8000000) != 0 )
        ++*(_DWORD *)(v24.nInteger + 4);
      if ( (v25 & 0x8000000) != 0 && (int)--v27[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v27 + 8))(a1: v27);
      SQVM::Pop(this: (SQVM *)pTable, n: 1);
      if ( --pTable[1].nInteger <= 0 )
        (*(void (__thiscall **)(tagSQObjectValue *))(pTable->nInteger + 8))(a1: pTable);
      return 1;
    }
  }
  else
  {
    v33 = sq_throwerror(v, err: (const char *)&stru_1009C130._suspended);
    if ( v5 != 0 && --pTable[1].nInteger <= 0 )
      (*(void (__thiscall **)(tagSQObjectValue *))(pTable->nInteger + 8))(a1: pTable);
    return v33;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CC10
// Name: thread_wakeup
// Source: json
//------------------------------------------------------------------------------
int __cdecl thread_wakeup(SQVM *v)
{
  SQObjectPtr *vals; // ecx
  int stackbase; // eax
  SQVM *pThread; // esi
  tagSQObjectType type; // ecx
  int v5; // ebx
  int v6; // edi
  int v7; // eax
  SQObjectPtr *v8; // edx
  int top; // eax
  tagSQObjectValue v10; // ebx
  SQObjectPtr *v11; // eax
  _DWORD *v12; // ecx
  tagSQObjectType v13; // edx
  SQObjectPtr *v14; // edx
  int v15; // eax
  SQObjectPtr *v16; // ecx
  tagSQObjectValue v17; // ebx
  tagSQObjectType v18; // edi
  SQObjectPtr *v19; // eax
  _DWORD *v20; // ecx
  tagSQObjectType v21; // edx
  _DWORD *v23; // ecx
  tagSQObjectType v24; // edx
  tagSQObjectType v25; // eax
  tagSQObjectType v26; // [esp+10h] [ebp-8h]
  unsigned int wakeupret; // [esp+14h] [ebp-4h]

  vals = v->_stack._vals;
  stackbase = v->_stackbase;
  pThread = vals[stackbase]._unVal.pThread;
  type = vals[stackbase]._type;
  v5 = type & 0x8000000;
  if ( (type & 0x8000000) != 0 )
    ++pThread->_uiRef;
  if ( type != OT_THREAD )
  {
    v6 = sq_throwerror(v, err: (const char *)&stru_1009C130._suspended);
    if ( v5 == 0 )
      return v6;
LABEL_36:
    if ( --pThread->_uiRef <= 0 )
      pThread->Release(this: pThread);
    return v6;
  }
  if ( pThread->_suspended == 0 )
  {
    if ( pThread->_callsstacksize == 0 )
    {
      v6 = sq_throwerror(v, err: (const char *)&stru_1009C130._suspend_varargs);
      goto LABEL_36;
    }
    if ( pThread->_callsstacksize != 0 )
    {
      v6 = sq_throwerror(v, err: "cannot wakeup a running thread");
      goto LABEL_36;
    }
  }
  v7 = v->_stackbase;
  wakeupret = v->_top - v7 > 1;
  if ( v->_top - v7 > 1 )
  {
    v8 = &v->_stack._vals[v7 + 1];
    top = pThread->_top;
    pThread->_top = top + 1;
    v10.pTable = (SQTable *)v8->_unVal;
    v11 = &pThread->_stack._vals[top];
    v26 = v11->_type;
    v12 = &v11->_unVal.pTable->__vftable;
    v11->_unVal = v10;
    v13 = v8->_type;
    v11->_type = v13;
    if ( (v13 & 0x8000000) != 0 )
      ++*(_DWORD *)(v10.nInteger + 4);
    if ( (v26 & 0x8000000) != 0 && (int)--v12[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
  }
  if ( sq_wakeupvm(v: pThread, wakeupret) < 0 )
  {
    sq_settop(v: pThread, newtop: 1);
    v23 = &v->_lasterror._unVal.pTable->__vftable;
    v24 = v->_lasterror._type;
    v->_lasterror._unVal.nInteger = pThread->_lasterror._unVal.nInteger;
    v25 = pThread->_lasterror._type;
    v->_lasterror._type = v25;
    if ( (v25 & 0x8000000) != 0 )
      ++*(_DWORD *)(v->_lasterror._unVal.nInteger + 4);
    if ( (v24 & 0x8000000) != 0 && (int)--v23[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v23 + 8))(a1: v23);
    if ( --pThread->_uiRef <= 0 )
      pThread->Release(this: pThread);
    return -1;
  }
  else
  {
    v14 = &pThread->_stack._vals[pThread->_top - 1];
    v15 = v->_top;
    v->_top = v15 + 1;
    v16 = v->_stack._vals;
    v17.pTable = (SQTable *)v14->_unVal;
    v18 = v16[v15]._type;
    v19 = &v16[v15];
    v20 = &v19->_unVal.pTable->__vftable;
    v19->_unVal = v17;
    v21 = v14->_type;
    v19->_type = v21;
    if ( (v21 & 0x8000000) != 0 )
      ++*(_DWORD *)(v17.nInteger + 4);
    if ( (v18 & 0x8000000) != 0 && (int)--v20[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v20 + 8))(a1: v20);
    SQVM::Pop(this: pThread, n: 1);
    if ( pThread->_suspended == 0 && pThread->_callsstacksize == 0 )
      sq_settop(v: pThread, newtop: 1);
    if ( --pThread->_uiRef <= 0 )
      pThread->Release(this: pThread);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CE20
// Name: thread_getstatus
// Source: json
//------------------------------------------------------------------------------
int __cdecl thread_getstatus(SQVM *v)
{
  tagSQObjectValue v1; // eax
  int v2; // eax
  int v3; // eax

  v1.pTable = (SQTable *)v->_stack._vals[v->_stackbase]._unVal;
  if ( *(_DWORD *)(v1.nInteger + 156) != 0 )
    v2 = 2;
  else
    v2 = *(_DWORD *)(v1.nInteger + 108) != 0;
  if ( v2 != 0 )
  {
    v3 = v2 - 1;
    if ( v3 != 0 )
    {
      if ( v3 == 1 )
      {
        sq_pushstring(v, s: "suspended", len: -1);
        return 1;
      }
      else
      {
        return sq_throwerror(v, err: "internal VM error");
      }
    }
    else
    {
      sq_pushstring(v, s: "running", len: -1);
      return 1;
    }
  }
  else
  {
    sq_pushstring(v, s: "idle", len: -1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CEC0
// Name: class_getattributes
// Source: json
//------------------------------------------------------------------------------
int __cdecl class_getattributes(tagSQObject *v)
{
  return 2 * (sq_getattributes(v) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003CEE0
// Name: class_setattributes
// Source: json
//------------------------------------------------------------------------------
int __cdecl class_setattributes(tagSQObject *v)
{
  SQVM *v1; // ecx

  return 2 * (sq_setattributes(v, a2: v1) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003CF00
// Name: class_instance
// Source: json
//------------------------------------------------------------------------------
int __cdecl class_instance(SQVM *v)
{
  return 2 * (sq_createinstance((const tagSQObject *)v) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003CF20
// Name: instance_getclass
// Source: json
//------------------------------------------------------------------------------
int __cdecl instance_getclass(SQVM *v)
{
  return 2 * (sq_getclass((const tagSQObject *)v, idx: 1) >= 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003CF40
// Name: weakref_ref
// Source: json
//------------------------------------------------------------------------------
int __cdecl weakref_ref(SQVM *v)
{
  return 2 * (sq_getweakrefval(v) >= 0) - 1;
}
