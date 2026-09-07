// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/sqstdlib/sqstdstream.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10033E10
// Name: int _stream_readblob(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _stream_readblob(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  SQStream *v3; // esi
  bool v4; // zf
  SQObjectPtr *v5; // eax
  int v6; // eax
  tagSQObjectValue v7; // eax
  SQStream *v8; // edx
  int v9; // eax
  tagSQObjectType type; // ecx
  SQSharedState *fFloat; // edi
  int v13; // eax
  unsigned int v14; // esi
  unsigned __int8 *v15; // eax
  int v16; // [esp+0h] [ebp-18h]
  SQStream *self; // [esp+10h] [ebp-8h]
  int size; // [esp+14h] [ebp-4h]
  char *sizea; // [esp+14h] [ebp-4h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = nullptr;
  v4 = vals[stackbase]._type == OT_INSTANCE;
  v5 = &vals[stackbase];
  self = nullptr;
  if ( v4 )
  {
    v7.pTable = (SQTable *)v5->_unVal;
    v8 = *(SQStream **)(v7.nInteger + 32);
    v9 = *(_DWORD *)(v7.nInteger + 28);
    self = v8;
    while ( *(_DWORD *)(v9 + 76) != 0x80000000 )
    {
      v9 = *(_DWORD *)(v9 + 28);
      if ( v9 == 0 )
      {
        v6 = sq_throwerror(v, err: "invalid type tag");
        v3 = self;
        goto LABEL_7;
      }
    }
    v3 = v8;
  }
  else
  {
    v6 = sq_throwerror(v, err: "the object is not a class instance");
LABEL_7:
    if ( v6 < 0 )
      return sq_throwerror(v, err: "invalid type tag");
  }
  if ( !v3->IsValid(this: v3) )
    return sq_throwerror(v, err: "the stream is invalid");
  type = v->_stack._vals[v->_stackbase + 1]._type;
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      fFloat = (SQSharedState *)(int)v->_stack._vals[v->_stackbase + 1]._unVal.fFloat;
    else
      fFloat = (SQSharedState *)v->_stack._vals[v->_stackbase + 1]._unVal.pTable;
  }
  else
  {
    fFloat = (SQSharedState *)size;
  }
  if ( (int)fFloat > v3->Len(this: v3) )
    fFloat = (SQSharedState *)v3->Len(this: v3);
  if ( (int)fFloat <= 0 )
  {
    sizea = v->_sharedstate->_scratchpad;
    v13 = v3->Read(this: v3, a2: sizea, a3: (int)fFloat);
  }
  else
  {
    sizea = SQSharedState::GetScratchPad(this: fFloat, size: v16);
    v13 = self->Read(this: self, a2: sizea, a3: (int)fFloat);
  }
  v14 = v13;
  if ( v13 <= 0 )
    return sq_throwerror(v, err: "no data left to read");
  v15 = (unsigned __int8 *)sqstd_createblob(v, size: v13);
  memcpy(dst: v15, src: (unsigned __int8 *)sizea, count: v14);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10033F70
// Name: int _stream_readn(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _stream_readn(SQVM *v)
{
  SQObjectPtr *v1; // eax
  int v2; // esi
  const char *v3; // eax
  tagSQObjectValue v4; // eax
  int v5; // eax
  int result; // eax
  SQObjectPtr *vals; // edx
  tagSQObjectType type; // ecx
  int fFloat; // eax
  int v10; // xmm0_4
  double d; // [esp+8h] [ebp-8h] BYREF

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = 0;
  if ( v1->_type == OT_INSTANCE )
  {
    v4.pTable = (SQTable *)v1->_unVal;
    v2 = *(_DWORD *)(v4.nInteger + 32);
    v5 = *(_DWORD *)(v4.nInteger + 28);
    while ( *(_DWORD *)(v5 + 76) != 0x80000000 )
    {
      v5 = *(_DWORD *)(v5 + 28);
      if ( v5 == 0 )
      {
        v3 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v3 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v3) < 0 )
      return sq_throwerror(v, err: "invalid type tag");
  }
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2) == 0 )
    return sq_throwerror(v, err: "the stream is invalid");
  vals = v->_stack._vals;
  type = vals[v->_stackbase + 1]._type;
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      fFloat = (int)vals[v->_stackbase + 1]._unVal.fFloat;
    else
      fFloat = vals[v->_stackbase + 1]._unVal.nInteger;
  }
  else
  {
    fFloat = LODWORD(d);
  }
  switch ( fFloat )
  {
    case 'b':
      if ( (*(int (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 4))(a1: v2, a2: &d, a3: 1) != 1 )
        goto LABEL_18;
      sq_pushinteger(v, n: (tagSQObjectValue)LOBYTE(d));
      result = 1;
      break;
    case 'c':
      if ( (*(int (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 4))(a1: v2, a2: &d, a3: 1) != 1 )
        goto LABEL_18;
      sq_pushinteger(v, n: (tagSQObjectValue)SLOBYTE(d));
      result = 1;
      break;
    case 'd':
      if ( (*(int (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 4))(a1: v2, a2: &d, a3: 8) != 8 )
        goto LABEL_18;
      *(float *)&v10 = d;
      sq_pushfloat(a1: (int)v, a2: v10);
      result = 1;
      break;
    case 'f':
      if ( (*(int (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 4))(a1: v2, a2: &d, a3: 4) != 4 )
        goto LABEL_18;
      sq_pushfloat(a1: (int)v, a2: SLODWORD(d));
      result = 1;
      break;
    case 'i':
    case 'l':
      if ( (*(int (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 4))(a1: v2, a2: &d, a3: 4) != 4 )
        goto LABEL_18;
      sq_pushinteger(v, n: LODWORD(d));
      result = 1;
      break;
    case 's':
      if ( (*(int (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 4))(a1: v2, a2: &d, a3: 2) != 2 )
        goto LABEL_18;
      sq_pushinteger(v, n: (tagSQObjectValue)SLOWORD(d));
      result = 1;
      break;
    case 'w':
      if ( (*(int (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 4))(a1: v2, a2: &d, a3: 2) == 2 )
      {
        sq_pushinteger(v, n: (tagSQObjectValue)LOWORD(d));
        result = 1;
      }
      else
      {
LABEL_18:
        result = sq_throwerror(v, err: "io error");
      }
      break;
    default:
      result = sq_throwerror(v, err: "invalid format");
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100341F0
// Name: int _stream_writeblob(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _stream_writeblob(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  const char *v5; // eax
  tagSQObjectValue v6; // eax
  SQStream *v7; // edx
  int v8; // eax
  int v10; // eax
  SQObjectPtr *v11; // ecx
  int v12; // eax
  int v13; // eax
  SQStream *v14; // esi
  int v15; // eax
  int v16; // eax
  SQStream_vtbl *v17; // ebx
  int v18; // esi
  SQStream *self; // [esp+Ch] [ebp-4h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  self = nullptr;
  if ( v3 )
  {
    v6.pTable = (SQTable *)v4->_unVal;
    v7 = *(SQStream **)(v6.nInteger + 32);
    v8 = *(_DWORD *)(v6.nInteger + 28);
    self = v7;
    while ( *(_DWORD *)(v8 + 76) != 0x80000000 )
    {
      v8 = *(_DWORD *)(v8 + 28);
      if ( v8 == 0 )
      {
        v5 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v5 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v5) < 0 )
      return sq_throwerror(v, err: "invalid type tag");
  }
  if ( !self->IsValid(this: self) )
    return sq_throwerror(v, err: "the stream is invalid");
  v10 = v->_stackbase;
  v11 = v->_stack._vals;
  v3 = v11[v10 + 1]._type == OT_INSTANCE;
  v12 = (int)&v11[v10 + 1];
  if ( v3 )
  {
    v15 = *(_DWORD *)(v12 + 4);
    v14 = *(SQStream **)(v15 + 32);
    v16 = *(_DWORD *)(v15 + 28);
    while ( *(_DWORD *)(v16 + 76) != -2147483646 )
    {
      v16 = *(_DWORD *)(v16 + 28);
      if ( v16 == 0 )
      {
        v13 = sq_throwerror(v, err: "invalid type tag");
        goto LABEL_17;
      }
    }
  }
  else
  {
    v13 = sq_throwerror(v, err: "the object is not a class instance");
    v14 = self;
LABEL_17:
    if ( v13 < 0 )
      return sq_throwerror(v, err: "invalid parameter");
  }
  v17 = v14[4].__vftable;
  v18 = sqstd_getblobsize(v);
  if ( self->Write(this: self, a2: v17, a3: v18) != v18 )
    return sq_throwerror(v, err: "io error");
  sq_pushinteger(v, n: (tagSQObjectValue)v18);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034320
// Name: int _stream_writen(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _stream_writen(SQVM *v)
{
  SQObjectPtr *v1; // eax
  int v2; // esi
  const char *v3; // eax
  tagSQObjectValue v4; // eax
  int v5; // eax
  int result; // eax
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // edx
  int fFloat; // edx
  void (__thiscall *v11)(int, double *, int); // edx
  void (__thiscall *v12)(int, double *, int); // edx
  void (__thiscall *v13)(int, unsigned __int8 *, int); // edx
  tagSQObjectType v14; // edx
  void (__thiscall *v15)(int, double *, int); // edx
  tagSQObjectType v16; // edx
  float nInteger; // xmm0_4
  void (__thiscall *v18)(int, double *, int); // edx
  unsigned __int8 b; // [esp+Bh] [ebp-Dh] BYREF
  int ti; // [esp+Ch] [ebp-Ch] BYREF
  double d; // [esp+10h] [ebp-8h] BYREF

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = 0;
  if ( v1->_type == OT_INSTANCE )
  {
    v4.pTable = (SQTable *)v1->_unVal;
    v2 = *(_DWORD *)(v4.nInteger + 32);
    v5 = *(_DWORD *)(v4.nInteger + 28);
    while ( *(_DWORD *)(v5 + 76) != 0x80000000 )
    {
      v5 = *(_DWORD *)(v5 + 28);
      if ( v5 == 0 )
      {
        v3 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v3 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v3) < 0 )
      return sq_throwerror(v, err: "invalid type tag");
  }
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2) == 0 )
    return sq_throwerror(v, err: "the stream is invalid");
  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  type = vals[stackbase + 2]._type;
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      fFloat = (int)vals[stackbase + 2]._unVal.fFloat;
    else
      fFloat = vals[stackbase + 2]._unVal.nInteger;
  }
  else
  {
    fFloat = LODWORD(d);
  }
  switch ( fFloat )
  {
    case 'b':
    case 'c':
      sq_getinteger(v, idx: 2, i: (tagSQObjectValue *)&ti);
      v13 = *(void (__thiscall **)(int, unsigned __int8 *, int))(*(_DWORD *)v2 + 8);
      b = ti;
      v13(a1: v2, a2: &b, a3: 1);
      result = 0;
      break;
    case 'd':
      v16 = vals[stackbase + 1]._type;
      if ( (v16 & 0x4000000) != 0 )
      {
        if ( v16 == OT_INTEGER )
          nInteger = (float)vals[stackbase + 1]._unVal.nInteger;
        else
          nInteger = vals[stackbase + 1]._unVal.fFloat;
      }
      else
      {
        nInteger = *(float *)&d;
      }
      v18 = *(void (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 8);
      d = nInteger;
      v18(a1: v2, a2: &d, a3: 8);
      result = 0;
      break;
    case 'f':
      v14 = vals[stackbase + 1]._type;
      if ( (v14 & 0x4000000) != 0 )
      {
        if ( v14 == OT_INTEGER )
        {
          v15 = *(void (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 8);
          *(float *)&d = (float)vals[stackbase + 1]._unVal.nInteger;
        }
        else
        {
          v15 = *(void (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 8);
          LODWORD(d) = vals[stackbase + 1]._unVal.pTable;
        }
        v15(a1: v2, a2: &d, a3: 4);
        result = 0;
      }
      else
      {
        (*(void (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 8))(a1: v2, a2: &d, a3: 4);
        result = 0;
      }
      break;
    case 'i':
    case 'l':
      sq_getinteger(v, idx: 2, i: (tagSQObjectValue *)&ti);
      v11 = *(void (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 8);
      LODWORD(d) = ti;
      v11(a1: v2, a2: &d, a3: 4);
      result = 0;
      break;
    case 's':
    case 'w':
      sq_getinteger(v, idx: 2, i: (tagSQObjectValue *)&ti);
      v12 = *(void (__thiscall **)(int, double *, int))(*(_DWORD *)v2 + 8);
      LODWORD(d) = (unsigned __int16)ti;
      v12(a1: v2, a2: &d, a3: 2);
      result = 0;
      break;
    default:
      result = sq_throwerror(v, err: "invalid format");
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100345A0
// Name: int _stream_seek(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _stream_seek(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  const char *v5; // eax
  tagSQObjectValue v6; // eax
  int v7; // edx
  int v8; // eax
  int v10; // eax
  SQObjectPtr *v11; // ecx
  tagSQObjectType type; // edx
  int v13; // esi
  int fFloat; // ebx
  tagSQObjectType v15; // edx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int top; // ecx
  SQObjectPtr *v21; // edx
  tagSQObjectType v22; // esi
  SQObjectPtr *v23; // edx
  _DWORD *v24; // ecx
  int t; // [esp+Ch] [ebp-4h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  t = 0;
  if ( v3 )
  {
    v6.pTable = (SQTable *)v4->_unVal;
    v7 = *(_DWORD *)(v6.nInteger + 32);
    v8 = *(_DWORD *)(v6.nInteger + 28);
    t = v7;
    while ( *(_DWORD *)(v8 + 76) != 0x80000000 )
    {
      v8 = *(_DWORD *)(v8 + 28);
      if ( v8 == 0 )
      {
        v5 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v5 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v5) < 0 )
      return sq_throwerror(v, err: "invalid type tag");
  }
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)t + 28))(a1: t) == 0 )
    return sq_throwerror(v, err: "the stream is invalid");
  v10 = v->_stackbase;
  v11 = v->_stack._vals;
  type = v11[v10 + 1]._type;
  v13 = 2;
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      fFloat = (int)v11[v10 + 1]._unVal.fFloat;
    else
      fFloat = v11[v10 + 1]._unVal.nInteger;
  }
  else
  {
    fFloat = t;
  }
  if ( v->_top - v10 > 2 )
  {
    v15 = v11[v10 + 2]._type;
    if ( (v15 & 0x4000000) != 0 )
      v16 = v15 == OT_FLOAT ? (int)v11[v10 + 2]._unVal.fFloat : v11[v10 + 2]._unVal.nInteger;
    else
      v16 = t;
    v17 = v16 - 98;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 2 )
          return sq_throwerror(v, err: "invalid origin");
        v13 = 1;
      }
      else
      {
        v13 = 0;
      }
    }
  }
  v19 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)t + 24))(a1: t, a2: fFloat, a3: v13);
  top = v->_top;
  v->_top = top + 1;
  v21 = v->_stack._vals;
  v22 = v21[top]._type;
  v23 = &v21[top];
  v24 = &v23->_unVal.pTable->__vftable;
  v23->_unVal.nInteger = v19;
  v23->_type = OT_INTEGER;
  if ( (v22 & 0x8000000) != 0 && (int)--v24[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v24 + 8))(a1: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034710
// Name: int _stream_tell(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _stream_tell(SQVM *v)
{
  SQObjectPtr *v1; // eax
  int v2; // esi
  const char *v3; // eax
  tagSQObjectValue v4; // eax
  int v5; // eax
  int v7; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectType type; // esi
  SQObjectPtr *v11; // edx
  _DWORD *v12; // ecx

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = 0;
  if ( v1->_type == OT_INSTANCE )
  {
    v4.pTable = (SQTable *)v1->_unVal;
    v2 = *(_DWORD *)(v4.nInteger + 32);
    v5 = *(_DWORD *)(v4.nInteger + 28);
    while ( *(_DWORD *)(v5 + 76) != 0x80000000 )
    {
      v5 = *(_DWORD *)(v5 + 28);
      if ( v5 == 0 )
      {
        v3 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v3 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v3) < 0 )
      return sq_throwerror(v, err: "invalid type tag");
  }
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2) == 0 )
    return sq_throwerror(v, err: "the stream is invalid");
  v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 16))(a1: v2);
  top = v->_top;
  v->_top = top + 1;
  vals = v->_stack._vals;
  type = vals[top]._type;
  v11 = &vals[top];
  v12 = &v11->_unVal.pTable->__vftable;
  v11->_unVal.nInteger = v7;
  v11->_type = OT_INTEGER;
  if ( (type & 0x8000000) != 0 && (int)--v12[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100347E0
// Name: int _stream_len(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _stream_len(SQVM *v)
{
  SQObjectPtr *v1; // eax
  int v2; // esi
  const char *v3; // eax
  tagSQObjectValue v4; // eax
  int v5; // eax
  int v7; // eax
  int top; // ecx
  SQObjectPtr *vals; // edx
  tagSQObjectType type; // esi
  SQObjectPtr *v11; // edx
  _DWORD *v12; // ecx

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = 0;
  if ( v1->_type == OT_INSTANCE )
  {
    v4.pTable = (SQTable *)v1->_unVal;
    v2 = *(_DWORD *)(v4.nInteger + 32);
    v5 = *(_DWORD *)(v4.nInteger + 28);
    while ( *(_DWORD *)(v5 + 76) != 0x80000000 )
    {
      v5 = *(_DWORD *)(v5 + 28);
      if ( v5 == 0 )
      {
        v3 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v3 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v3) < 0 )
      return sq_throwerror(v, err: "invalid type tag");
  }
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2) == 0 )
    return sq_throwerror(v, err: "the stream is invalid");
  v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 20))(a1: v2);
  top = v->_top;
  v->_top = top + 1;
  vals = v->_stack._vals;
  type = vals[top]._type;
  v11 = &vals[top];
  v12 = &v11->_unVal.pTable->__vftable;
  v11->_unVal.nInteger = v7;
  v11->_type = OT_INTEGER;
  if ( (type & 0x8000000) != 0 && (int)--v12[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100348B0
// Name: int _stream_flush(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _stream_flush(SQVM *v)
{
  SQObjectPtr *v1; // eax
  int v2; // esi
  const char *v3; // eax
  tagSQObjectValue v4; // eax
  int v5; // eax

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = 0;
  if ( v1->_type == OT_INSTANCE )
  {
    v4.pTable = (SQTable *)v1->_unVal;
    v2 = *(_DWORD *)(v4.nInteger + 32);
    v5 = *(_DWORD *)(v4.nInteger + 28);
    while ( *(_DWORD *)(v5 + 76) != 0x80000000 )
    {
      v5 = *(_DWORD *)(v5 + 28);
      if ( v5 == 0 )
      {
        v3 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v3 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v3) < 0 )
      return sq_throwerror(v, err: "invalid type tag");
  }
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2) == 0 )
    return sq_throwerror(v, err: "the stream is invalid");
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2) != 0 )
    sq_pushnull(v);
  else
    sq_pushinteger(v, n: (tagSQObjectValue)1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034960
// Name: int _stream_eos(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _stream_eos(SQVM *v)
{
  SQObjectPtr *v1; // eax
  int v2; // esi
  const char *v3; // eax
  tagSQObjectValue v4; // eax
  int v5; // eax

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = 0;
  if ( v1->_type == OT_INSTANCE )
  {
    v4.pTable = (SQTable *)v1->_unVal;
    v2 = *(_DWORD *)(v4.nInteger + 32);
    v5 = *(_DWORD *)(v4.nInteger + 28);
    while ( *(_DWORD *)(v5 + 76) != 0x80000000 )
    {
      v5 = *(_DWORD *)(v5 + 28);
      if ( v5 == 0 )
      {
        v3 = "invalid type tag";
        goto LABEL_7;
      }
    }
  }
  else
  {
    v3 = "the object is not a class instance";
LABEL_7:
    if ( sq_throwerror(v, err: v3) < 0 )
      return sq_throwerror(v, err: "invalid type tag");
  }
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2) == 0 )
    return sq_throwerror(v, err: "the stream is invalid");
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v2 + 32))(a1: v2) != 0 )
    sq_pushinteger(v, n: (tagSQObjectValue)1);
  else
    sq_pushnull(v);
  return 1;
}
