// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/sqstdlib/sqstdstring.cpp
// Functions: 16
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10034A10
// Name: validate_format
// Source: json
//------------------------------------------------------------------------------
int __usercall validate_format@<eax>(const char *src@<ecx>, int n@<eax>, SQVM *v, char *fmt, int *width)
{
  int v5; // esi
  int v7; // ebx
  int v8; // eax
  unsigned __int8 v9; // dl
  int v10; // eax
  int v12; // eax
  int v13; // ebx
  unsigned __int8 *v14; // [esp+10h] [ebp-Ch]
  char swidth[4]; // [esp+18h] [ebp-4h] BYREF

  v5 = n;
  *fmt = 37;
  v7 = 0;
  v14 = (unsigned __int8 *)&src[n];
  strchr(string: "-+ #0", chr: src[n]);
  if ( v8 != 0 )
  {
    do
    {
      v9 = src[++v5];
      strchr(string: "-+ #0", chr: v9);
    }
    while ( v10 != 0 );
  }
  if ( isdigit(c: src[v5]) == 0 )
  {
LABEL_6:
    swidth[v7] = 0;
    if ( v7 <= 0 )
      *width = 0;
    else
      *width = atoi(nptr: swidth);
    if ( src[v5] == 46 )
    {
      v12 = src[++v5];
      v13 = 0;
      if ( isdigit(c: v12) != 0 )
      {
        do
        {
          swidth[v13++] = src[v5++];
          if ( v13 >= 3 )
            return sq_throwerror(v, err: "precision format too long");
        }
        while ( isdigit(c: src[v5]) != 0 );
      }
      swidth[v13] = 0;
      if ( v13 > 0 )
        *width += atoi(nptr: swidth);
    }
    if ( v5 - n > 20 )
      return sq_throwerror(v, err: "format too long");
    memcpy(dst: (unsigned __int8 *)fmt + 1, src: v14, count: v5 - n + 1);
    fmt[v5 - n + 2] = 0;
    return v5;
  }
  while ( 1 )
  {
    swidth[v7++] = src[v5++];
    if ( v7 >= 3 )
      return sq_throwerror(v, err: "width format too long");
    if ( isdigit(c: src[v5]) == 0 )
      goto LABEL_6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034B80
// Name: _sqstd_format
// Source: json
//------------------------------------------------------------------------------
int __cdecl sqstd_format(SQVM *v, int *nformatstringidx, char **outlen)
{
  SQVM *v3; // ebx
  int v4; // eax
  SQSharedState *sharedstate; // esi
  SQSharedState *v6; // eax
  char *scratchpad; // eax
  int v8; // esi
  int v9; // eax
  int v10; // edx
  int v11; // edi
  char v12; // cl
  int v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // ebx
  SQObjectPtr *v17; // eax
  SQObjectPtr *v18; // eax
  float nInteger; // xmm0_4
  int v20; // ecx
  SQSharedState *v21; // esi
  int scratchpadsize; // eax
  unsigned int v23; // edi
  char *v24; // eax
  int v25; // ebx
  int v26; // eax
  int result; // eax
  int v28; // [esp+10h] [ebp-44h]
  char fmt[20]; // [esp+1Ch] [ebp-38h] BYREF
  int n; // [esp+30h] [ebp-24h]
  const char *ts; // [esp+34h] [ebp-20h] BYREF
  float v32; // [esp+38h] [ebp-1Ch]
  int ti; // [esp+3Ch] [ebp-18h]
  int nparam; // [esp+40h] [ebp-14h]
  int allocated; // [esp+44h] [ebp-10h]
  int w; // [esp+48h] [ebp-Ch] BYREF
  const char *format; // [esp+4Ch] [ebp-8h] BYREF
  int i; // [esp+50h] [ebp-4h]

  v3 = v;
  sq_getstring((const tagSQObject *)v, idx: 2, c: &format);
  v4 = sq_getsize(v, idx: 2);
  sharedstate = v->_sharedstate;
  v6 = (SQSharedState *)(v4 + 2);
  allocated = (int)v6;
  if ( (int)v6 <= 0 )
    scratchpad = sharedstate->_scratchpad;
  else
    scratchpad = SQSharedState::GetScratchPad(this: v6, size: v28);
  v8 = (int)scratchpad;
  v9 = 0;
  v10 = 0;
  v11 = 3;
  i = 0;
  nparam = 3;
  w = 0;
  if ( *format != 0 )
  {
    while ( 1 )
    {
      v12 = format[v9];
      if ( v12 == 37 )
        break;
      *(_BYTE *)(v10 + v8) = v12;
      i = ++v10;
      ++v9;
LABEL_43:
      if ( format[v9] == 0 )
        goto LABEL_44;
    }
    if ( format[v9 + 1] == 37 )
    {
      *(_BYTE *)(v10 + v8) = 37;
      i = ++v10;
      v9 += 2;
      goto LABEL_43;
    }
    if ( v11 > v3->_top - v3->_stackbase )
    {
      return sq_throwerror(v: v3, err: "not enough paramters for the given format string");
    }
    else
    {
      v13 = validate_format(src: format, n: v9 + 1, v: v3, fmt, width: &w);
      if ( v13 < 0 )
      {
        return -1;
      }
      else
      {
        switch ( format[v13] )
        {
          case 'E':
          case 'G':
          case 'e':
          case 'f':
          case 'g':
            if ( v11 < 0 )
              v18 = &v3->_stack._vals[v11 + v3->_top];
            else
              v18 = &v3->_stack._vals[v11 - 1 + v3->_stackbase];
            if ( (v18->_type & 0x4000000) != 0 )
            {
              if ( v18->_type == OT_INTEGER )
                nInteger = (float)v18->_unVal.nInteger;
              else
                nInteger = v18->_unVal.fFloat;
              v32 = nInteger;
              v16 = 102;
              goto LABEL_30;
            }
            return sq_throwerror(v: v3, err: "float expected for the specified format");
          case 'X':
          case 'c':
          case 'd':
          case 'i':
          case 'o':
          case 'u':
          case 'x':
            if ( v11 < 0 )
              v17 = &v3->_stack._vals[v11 + v3->_top];
            else
              v17 = &v3->_stack._vals[v11 - 1 + v3->_stackbase];
            if ( (v17->_type & 0x4000000) != 0 )
            {
              if ( v17->_type == OT_FLOAT )
                ti = (int)v17->_unVal.fFloat;
              else
                ti = v17->_unVal.nInteger;
              v16 = 105;
LABEL_30:
              v15 = w + 101;
              goto LABEL_31;
            }
            return sq_throwerror(v: v3, err: "integer expected for the specified format");
          case 's':
            if ( sq_getstring(v: (const tagSQObject *)v3, idx: v11, c: &ts) >= 0 )
            {
              v14 = sq_getsize(v: v3, idx: v11);
              v15 = v14 + w + 1;
              v16 = 115;
LABEL_31:
              v20 = allocated + v15 + 1;
              n = v13 + 1;
              v21 = v->_sharedstate;
              allocated = v20;
              if ( v20 <= 0 )
                goto LABEL_37;
              scratchpadsize = v21->_scratchpadsize;
              if ( scratchpadsize >= v20 )
              {
                if ( scratchpadsize < 32 * v20 )
                {
LABEL_37:
                  v8 = (int)v21->_scratchpad;
                  if ( v16 == 102 )
                  {
                    v25 = i;
                    v26 = sprintf(string: (char *)(i + v8), format: fmt, v32);
                  }
                  else if ( v16 == 105 )
                  {
                    v25 = i;
                    v26 = sprintf(string: (char *)(i + v8), format: fmt, ti);
                  }
                  else
                  {
                    v25 = i;
                    v26 = sprintf(string: (char *)(i + v8), format: fmt, ts);
                  }
                  i = v26 + v25;
                  v9 = n;
                  v3 = v;
                  v10 = i;
                  nparam = ++v11;
                  goto LABEL_43;
                }
                v23 = scratchpadsize >> 1;
              }
              else
              {
                v23 = v20 + (v20 >> 1);
              }
              v24 = (char *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v21->_scratchpad, a3: v23);
              v21->_scratchpadsize = v23;
              v11 = nparam;
              v21->_scratchpad = v24;
              goto LABEL_37;
            }
            result = sq_throwerror(v: v3, err: "string expected for the specified format");
            break;
          default:
            return sq_throwerror(v: v3, err: "invalid format");
        }
      }
    }
  }
  else
  {
LABEL_44:
    *nformatstringidx = v10;
    *(_BYTE *)(v10 + v8) = 0;
    *outlen = (char *)v8;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10035AB0
// Name: _sqstd_register_stringlib
// Source: json
//------------------------------------------------------------------------------
int __usercall sqstd_register_stringlib@<eax>(SQVM *v@<eax>)
{
  tagSQRegFunction *v2; // esi
  int top; // eax
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // esi
  SQSharedState *sharedstate; // ebx
  SQString *v7; // esi
  tagSQObjectType v8; // eax
  _DWORD *v9; // ecx
  int v10; // ecx
  SQObjectPtr *v11; // eax
  tagSQObjectType v12; // esi
  int v13; // esi
  tagSQRegFunction *v14; // ebx
  int v15; // eax
  SQObjectPtr *v16; // ecx
  tagSQObjectType v17; // esi
  SQSharedState *v18; // ebx
  SQString *v19; // esi
  tagSQObjectType v20; // eax
  _DWORD *v21; // ecx
  const char *v23; // [esp+0h] [ebp-10h]
  int i; // [esp+Ch] [ebp-4h]
  int ia; // [esp+Ch] [ebp-4h]

  sq_pushstring(v, s: "regexp", len: -1);
  sq_newclass(v, hasbase: 0);
  i = 0;
  if ( rexobj_funcs[0].name != nullptr )
  {
    v2 = rexobj_funcs;
    do
    {
      sq_pushstring(v, s: v2->name, len: -1);
      sq_newclosure(v, func: v2->f, nfreevars: 0);
      sq_setparamscheck(v, typemask: v2->typemask, nparamscheck: v2->nparamscheck);
      sq_setnativeclosurename(v, name: v2->name);
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
            v7 = StringTable::Add(this: sharedstate->_stringtable, news: "null is not a valid key", len: -1);
            v7->_sharedstate = sharedstate;
            ++v7->_uiRef;
            v8 = v->_lasterror._type;
            v9 = &v->_lasterror._unVal.pTable->__vftable;
            v->_lasterror._unVal.nInteger = (int)v7;
            v->_lasterror._type = OT_STRING;
            ++v7->_uiRef;
            if ( (v8 & 0x8000000) != 0 && (int)--v9[1] <= 0 )
              (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
            if ( --v7->_uiRef <= 0 )
              v7->Release(this: v7);
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
        SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v23);
      }
      v2 = &rexobj_funcs[++i];
    }
    while ( v2->name != nullptr );
  }
  v10 = v->_top;
  if ( v10 - v->_stackbase >= 3 )
  {
    v11 = v->_stack._vals;
    v12 = v11[v10 - 3]._type;
    if ( v12 == OT_TABLE || v12 == OT_CLASS )
    {
      if ( v11[v10 - 2]._type == OT_NULL )
      {
        sq_throwerror(v, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(this: (SQVM *)v10, self: &v11[v10 - 3], key: &v11[v10 - 2], val: &v11[v10 - 1], bstatic: false);
        SQVM::Pop(this: v, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v23);
  }
  ia = 0;
  if ( stringlib_funcs[0].name != nullptr )
  {
    v13 = 0;
    v14 = stringlib_funcs;
    do
    {
      sq_pushstring(v, s: v14->name, len: -1);
      sq_newclosure(v, func: stringlib_funcs[v13].f, nfreevars: 0);
      sq_setparamscheck(v, typemask: stringlib_funcs[v13].typemask, nparamscheck: stringlib_funcs[v13].nparamscheck);
      sq_setnativeclosurename(v, name: v14->name);
      v15 = v->_top;
      if ( v15 - v->_stackbase >= 3 )
      {
        v16 = v->_stack._vals;
        v17 = v16[v15 - 3]._type;
        if ( v17 == OT_TABLE || v17 == OT_CLASS )
        {
          if ( v16[v15 - 2]._type == OT_NULL )
          {
            v18 = v->_sharedstate;
            v19 = StringTable::Add(this: v18->_stringtable, news: "null is not a valid key", len: -1);
            v19->_sharedstate = v18;
            ++v19->_uiRef;
            v20 = v->_lasterror._type;
            v21 = &v->_lasterror._unVal.pTable->__vftable;
            v->_lasterror._unVal.nInteger = (int)v19;
            v->_lasterror._type = OT_STRING;
            ++v19->_uiRef;
            if ( (v20 & 0x8000000) != 0 && (int)--v21[1] <= 0 )
              (*(void (__thiscall **)(_DWORD *))(*v21 + 8))(a1: v21);
            if ( --v19->_uiRef <= 0 )
              v19->Release(this: v19);
          }
          else
          {
            SQVM::NewSlot(
              this: (SQVM *)&v16[v15 - 1],
              self: &v16[v15 - 3],
              key: &v16[v15 - 2],
              val: &v16[v15 - 1],
              bstatic: false);
            SQVM::Pop(this: v, n: 2);
          }
        }
      }
      else
      {
        SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v23);
      }
      v13 = ++ia;
      v14 = &stringlib_funcs[ia];
    }
    while ( v14->name != nullptr );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034EF0
// Name: _string_format
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl string_format(SQVM *v)
{
  int length; // [esp+8h] [ebp-8h] BYREF
  char *dest; // [esp+Ch] [ebp-4h] BYREF

  dest = nullptr;
  length = 0;
  if ( sqstd_format(v, nformatstringidx: &length, outlen: &dest) < 0 )
    return -1;
  sq_pushstring(v, s: dest, len: length);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034F50
// Name: _string_strip
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl string_strip(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  int v4; // eax
  SQString *v5; // esi
  const char *v6; // eax
  const char *v7; // edx
  SQObjectPtr *v8; // ecx
  tagSQObjectType type; // eax
  int v10; // esi
  int v11; // eax
  const char *v12; // edi
  char *v13; // eax
  const char *i; // esi
  const char *str; // [esp+Ch] [ebp-4h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = vals[stackbase + 1]._type == OT_STRING;
  v4 = (int)&vals[stackbase + 1];
  if ( v3 )
  {
    v7 = (const char *)(*(_DWORD *)(v4 + 4) + 28);
    str = v7;
  }
  else
  {
    v5 = SQVM::PrintObjVal(this: (SQVM *)vals, o: (const tagSQObject *)v);
    ++v5->_uiRef;
    v6 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v6, v5->_val);
    if ( --v5->_uiRef <= 0 )
      v5->Release(this: v5);
    v7 = str;
  }
  v8 = &v->_stack._vals[v->_stackbase + 1];
  type = v8->_type;
  if ( v8->_type <= OT_TABLE )
  {
    if ( v8->_type == OT_TABLE )
    {
      v10 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 40);
      goto LABEL_16;
    }
    if ( type == OT_STRING )
    {
      v10 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 20);
      goto LABEL_16;
    }
    if ( type == OT_ARRAY )
    {
      v10 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 28);
      goto LABEL_16;
    }
  }
  else if ( type == OT_USERDATA )
  {
    v10 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 28);
LABEL_16:
    v12 = v7;
    if ( *v7 != 0 )
    {
      do
      {
        if ( isspace(c: *v12) == 0 )
          break;
        ++v12;
      }
      while ( *v12 != 0 );
      v7 = str;
    }
    if ( v10 != 0 )
    {
      for ( i = &v7[v10 - 1]; i != str; --i )
      {
        if ( isspace(c: *i) == 0 )
          break;
      }
      v13 = (char *)(i + 1);
    }
    else
    {
      v13 = (char *)v7;
    }
    sq_pushstring(v, s: v12, len: v13 - v12);
    return 1;
  }
  v11 = sq_aux_invalidtype(v, type: v8->_type);
  v7 = str;
  v10 = v11;
  goto LABEL_16;
}

//------------------------------------------------------------------------------
// Address: 0x10035090
// Name: _string_lstrip
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl string_lstrip(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  int v4; // eax
  SQString *v5; // esi
  const char *v6; // eax
  int v7; // eax
  const char *i; // esi
  const char *str; // [esp+Ch] [ebp-4h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = vals[stackbase + 1]._type == OT_STRING;
  v4 = (int)&vals[stackbase + 1];
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
  for ( i = (const char *)v7; *i != 0; ++i )
  {
    if ( isspace(c: *i) == 0 )
      break;
  }
  sq_pushstring(v, s: i, len: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035130
// Name: _string_rstrip
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl string_rstrip(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  int v4; // eax
  SQString *v5; // esi
  const char *v6; // eax
  const char *v7; // ebx
  SQObjectPtr *v8; // ecx
  tagSQObjectType type; // eax
  int v10; // eax
  const char *v11; // eax
  const char *i; // esi
  const char *str; // [esp+Ch] [ebp-4h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = vals[stackbase + 1]._type == OT_STRING;
  v4 = (int)&vals[stackbase + 1];
  if ( v3 )
  {
    v7 = (const char *)(*(_DWORD *)(v4 + 4) + 28);
  }
  else
  {
    v5 = SQVM::PrintObjVal(this: (SQVM *)vals, o: (const tagSQObject *)v);
    ++v5->_uiRef;
    v6 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v6, v5->_val);
    if ( --v5->_uiRef <= 0 )
      v5->Release(this: v5);
    v7 = str;
  }
  v8 = &v->_stack._vals[v->_stackbase + 1];
  type = v8->_type;
  if ( v8->_type > OT_TABLE )
  {
    if ( type == OT_USERDATA )
      goto LABEL_9;
  }
  else
  {
    if ( v8->_type == OT_TABLE )
    {
      v10 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 40);
      goto LABEL_10;
    }
    if ( type == OT_STRING )
    {
      v10 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 20);
      goto LABEL_10;
    }
    if ( type == OT_ARRAY )
    {
LABEL_9:
      v10 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 28);
      goto LABEL_10;
    }
  }
  v10 = sq_aux_invalidtype(v, type: v8->_type);
LABEL_10:
  if ( v10 != 0 )
  {
    for ( i = &v7[v10 - 1]; i != v7; --i )
    {
      if ( isspace(c: *i) == 0 )
        break;
    }
    v11 = i + 1;
  }
  else
  {
    v11 = v7;
  }
  sq_pushstring(v, s: v7, len: v11 - v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035230
// Name: _string_split
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl string_split(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  int v4; // eax
  SQString *v5; // esi
  const char *v6; // eax
  int v7; // eax
  SQObjectPtr *v8; // ecx
  int v9; // eax
  SQString *v10; // esi
  const char *v11; // eax
  SQObjectPtr *v12; // ecx
  tagSQObjectType type; // eax
  int v14; // eax
  SQObjectPtr *v16; // ecx
  tagSQObjectType v17; // eax
  int v18; // eax
  unsigned int v19; // ebx
  char *scratchpad; // esi
  const char *v21; // esi
  int v22; // [esp+0h] [ebp-18h]
  unsigned __int8 *str; // [esp+10h] [ebp-8h]
  const char *seps; // [esp+14h] [ebp-4h]

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = vals[stackbase + 1]._type == OT_STRING;
  v4 = (int)&vals[stackbase + 1];
  if ( v3 )
  {
    str = (unsigned __int8 *)(*(_DWORD *)(v4 + 4) + 28);
  }
  else
  {
    v5 = SQVM::PrintObjVal(this: (SQVM *)vals, o: (const tagSQObject *)v);
    ++v5->_uiRef;
    v6 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v6, v5->_val);
    if ( --v5->_uiRef <= 0 )
      v5->Release(this: v5);
  }
  v7 = v->_stackbase;
  v8 = v->_stack._vals;
  v3 = v8[v7 + 2]._type == OT_STRING;
  v9 = (int)&v8[v7 + 2];
  if ( v3 )
  {
    seps = (const char *)(*(_DWORD *)(v9 + 4) + 28);
  }
  else
  {
    v10 = SQVM::PrintObjVal(this: (SQVM *)v8, o: (const tagSQObject *)v);
    ++v10->_uiRef;
    v11 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v11, v10->_val);
    if ( --v10->_uiRef <= 0 )
      v10->Release(this: v10);
  }
  v12 = &v->_stack._vals[v->_stackbase + 2];
  type = v12->_type;
  if ( v12->_type > OT_TABLE )
  {
    if ( type == OT_USERDATA )
      goto LABEL_13;
  }
  else
  {
    if ( v12->_type == OT_TABLE )
    {
      v14 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 2]._unVal.nInteger + 40);
      goto LABEL_14;
    }
    if ( type == OT_STRING )
    {
      v14 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 2]._unVal.nInteger + 20);
      goto LABEL_14;
    }
    if ( type == OT_ARRAY )
    {
LABEL_13:
      v14 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 2]._unVal.nInteger + 28);
      goto LABEL_14;
    }
  }
  v14 = sq_aux_invalidtype(v, type: v12->_type);
LABEL_14:
  if ( v14 == 0 )
    return sq_throwerror(v, err: "empty separators string");
  v16 = &v->_stack._vals[v->_stackbase + 1];
  v17 = v16->_type;
  if ( v16->_type > OT_TABLE )
  {
    if ( v17 == OT_USERDATA )
      goto LABEL_24;
LABEL_30:
    v18 = sq_aux_invalidtype(v, type: v16->_type);
    goto LABEL_25;
  }
  if ( v16->_type == OT_TABLE )
  {
    v18 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 40);
    goto LABEL_25;
  }
  if ( v17 == OT_STRING )
  {
    v18 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 20);
    goto LABEL_25;
  }
  if ( v17 != OT_ARRAY )
    goto LABEL_30;
LABEL_24:
  v18 = *(_DWORD *)(v->_stack._vals[v->_stackbase + 1]._unVal.nInteger + 28);
LABEL_25:
  v19 = v18 + 1;
  if ( v18 + 1 <= 0 )
    scratchpad = v->_sharedstate->_scratchpad;
  else
    scratchpad = SQSharedState::GetScratchPad(this: (SQSharedState *)(v18 + 1), size: v22);
  memcpy(dst: (unsigned __int8 *)scratchpad, src: str, count: v19);
  v21 = strtok(string: scratchpad, control: seps);
  sq_newarray(v);
  for ( ; v21 != nullptr; v21 = strtok(string: nullptr, control: seps) )
  {
    sq_pushstring(v, s: v21, len: -1);
    sq_arrayappend(v);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035420
// Name: _rexobj_releasehook
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl rexobj_releasehook(SQRex *p)
{
  sqstd_rex_free(exp: p);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035440
// Name: _regexp_match
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl regexp_match(SQVM *v)
{
  SQObjectPtr *v1; // eax
  SQRex *v2; // ebx
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v5; // zf
  int v6; // eax
  SQString *v7; // esi
  const char *v8; // eax
  const char *v9; // esi
  const char *v10; // eax
  int top; // eax
  int v12; // ecx
  SQObjectPtr *v13; // eax
  _DWORD *v14; // ecx
  int v15; // eax
  int v16; // ecx
  tagSQObjectType type; // edx
  int nodes; // [esp-Ch] [ebp-1Ch]
  const char *str; // [esp+Ch] [ebp-4h]

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = nullptr;
  if ( v1->_type == OT_INSTANCE )
    v2 = *(SQRex **)(v1->_unVal.nInteger + 32);
  else
    sq_throwerror(v, err: "the object is not a class instance");
  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v5 = vals[stackbase + 1]._type == OT_STRING;
  v6 = (int)&vals[stackbase + 1];
  if ( v5 )
  {
    v9 = (const char *)(*(_DWORD *)(v6 + 4) + 28);
  }
  else
  {
    v7 = SQVM::PrintObjVal(this: (SQVM *)vals, o: (const tagSQObject *)v);
    ++v7->_uiRef;
    v8 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v8, v7->_val);
    if ( --v7->_uiRef <= 0 )
      v7->Release(this: v7);
    v9 = str;
  }
  v2->_bol = v9;
  v2->_eol = &v9[strlen(v9)];
  nodes = (int)v2->_nodes;
  v2->_currsubexp = 0;
  v10 = sqstd_rex_matchnode(exp: v2, node: nodes, str: v9, next: nullptr);
  if ( v10 != nullptr && v10 == v2->_eol )
  {
    top = v->_top;
    v12 = top + 1;
    v13 = &v->_stack._vals[top];
    v->_top = v12;
    v14 = &v13->_unVal.pTable->__vftable;
    v13->_unVal.nInteger = 1;
  }
  else
  {
    v15 = v->_top;
    v16 = v15 + 1;
    v13 = &v->_stack._vals[v15];
    v->_top = v16;
    v14 = &v13->_unVal.pTable->__vftable;
    v13->_unVal.nInteger = 0;
  }
  type = v13->_type;
  v13->_type = OT_BOOL;
  if ( (type & 0x8000000) != 0 && (int)--v14[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035570
// Name: _addrexmatch
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall addrexmatch(SQVM *v@<esi>, const char *begin@<eax>, const char *str, const char *end)
{
  int top; // eax
  int v6; // ecx
  SQObjectPtr *v7; // eax
  tagSQObjectType type; // edx
  _DWORD *v9; // ecx
  int v10; // eax
  int v11; // ecx
  SQObjectPtr *v12; // eax
  tagSQObjectType v13; // edx
  _DWORD *v14; // ecx

  sq_newtable(v);
  sq_pushstring(v, s: "begin", len: -1);
  top = v->_top;
  v6 = top + 1;
  v7 = &v->_stack._vals[top];
  v->_top = v6;
  type = v7->_type;
  v9 = &v7->_unVal.pTable->__vftable;
  v7->_unVal.nInteger = begin - str;
  v7->_type = OT_INTEGER;
  if ( (type & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  sq_rawset(v);
  sq_pushstring(v, s: "end", len: -1);
  v10 = v->_top;
  v11 = v10 + 1;
  v12 = &v->_stack._vals[v10];
  v->_top = v11;
  v13 = v12->_type;
  v14 = &v12->_unVal.pTable->__vftable;
  v12->_unVal.nInteger = end - str;
  v12->_type = OT_INTEGER;
  if ( (v13 & 0x8000000) != 0 && (int)--v14[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
  sq_rawset(v);
}

//------------------------------------------------------------------------------
// Address: 0x10035630
// Name: _regexp_search
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl regexp_search(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  SQObjectPtr *v4; // eax
  int v5; // ecx
  SQObjectPtr *v6; // edx
  SQString *v7; // ebx
  const char *v8; // eax
  SQRex *v9; // ebx
  int v10; // eax
  SQObjectPtr *v11; // edx
  tagSQObjectType type; // ecx
  int v13; // eax
  const char *begin; // [esp+10h] [ebp-8h] BYREF
  SQRex *self; // [esp+14h] [ebp-4h] BYREF

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = vals[stackbase]._type == OT_INSTANCE;
  v4 = &vals[stackbase];
  self = nullptr;
  if ( v3 )
    self = *(SQRex **)(v4->_unVal.nInteger + 32);
  else
    sq_throwerror(v, err: "the object is not a class instance");
  v5 = v->_stackbase;
  v6 = v->_stack._vals;
  v3 = v6[v5 + 1]._type == OT_STRING;
  begin = nullptr;
  if ( v3 )
  {
    v9 = (SQRex *)(v6[v5 + 1]._unVal.nInteger + 28);
  }
  else
  {
    v7 = SQVM::PrintObjVal(this: (SQVM *)v5, o: (const tagSQObject *)v);
    ++v7->_uiRef;
    v8 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v8, v7->_val);
    if ( --v7->_uiRef <= 0 )
      v7->Release(this: v7);
    v9 = self;
  }
  v10 = v->_stackbase;
  if ( v->_top - v10 > 2 )
  {
    v11 = v->_stack._vals;
    type = v11[v10 + 2]._type;
    v13 = (int)&v11[v10 + 2];
    if ( (type & 0x4000000) != 0 )
    {
      if ( type == OT_FLOAT )
        begin = (const char *)(int)*(float *)(v13 + 4);
      else
        begin = *(const char **)(v13 + 4);
    }
  }
  if ( sqstd_rex_searchrange(
         exp: self,
         text_begin: &begin[(_DWORD)v9],
         text_end: &begin[(_DWORD)v9 + strlen(&begin[(_DWORD)v9])],
         out_begin: &begin,
         out_end: (const char **)&self) != 1 )
    return 0;
  addrexmatch(v, begin, str: (const char *)v9, end: (const char *)self);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035770
// Name: _regexp_capture
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl regexp_capture(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  SQRex *v3; // esi
  bool v4; // zf
  SQObjectPtr *v5; // eax
  int v6; // ecx
  SQObjectPtr *v7; // edx
  SQString *v8; // esi
  const char *v9; // eax
  int v10; // eax
  int v11; // ecx
  SQObjectPtr *v12; // ecx
  int v13; // edi
  SQRexMatch *matches; // ecx
  const char *begin; // eax
  int len; // ecx
  SQRex *self; // [esp+Ch] [ebp-14h]
  const char *str; // [esp+10h] [ebp-10h]
  int n; // [esp+14h] [ebp-Ch] BYREF
  SQRexMatch match; // [esp+18h] [ebp-8h] BYREF

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = nullptr;
  v4 = vals[stackbase]._type == OT_INSTANCE;
  v5 = &vals[stackbase];
  self = nullptr;
  if ( v4 )
  {
    self = *(SQRex **)(v5->_unVal.nInteger + 32);
    v3 = self;
  }
  else
  {
    sq_throwerror(v, err: "the object is not a class instance");
  }
  v6 = v->_stackbase;
  v7 = v->_stack._vals;
  v4 = v7[v6 + 1]._type == OT_STRING;
  n = 0;
  if ( v4 )
  {
    v10 = v7[v6 + 1]._unVal.nInteger + 28;
    str = (const char *)v10;
  }
  else
  {
    v8 = SQVM::PrintObjVal(this: (SQVM *)v6, o: (const tagSQObject *)v);
    ++v8->_uiRef;
    v9 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v9, v8->_val);
    if ( --v8->_uiRef <= 0 )
      v8->Release(this: v8);
    v10 = (int)str;
    v3 = self;
  }
  v11 = v->_stackbase;
  if ( v->_top - v11 > 2 )
  {
    v12 = &v->_stack._vals[v11 + 2];
    if ( (v12->_type & 0x4000000) != 0 )
    {
      if ( v12->_type == OT_FLOAT )
        n = (int)v12->_unVal.fFloat;
      else
        n = v12->_unVal.nInteger;
    }
  }
  if ( sqstd_rex_searchrange(
         exp: v3,
         text_begin: (const char *)(v10 + n),
         text_end: (const char *)(v10 + n + strlen((const char *)(v10 + n))),
         out_begin: &match.begin,
         out_end: (const char **)&n) != 1 )
    return 0;
  n = v3->_nsubexpr;
  sq_newarray(v);
  v13 = 0;
  if ( n > 0 )
  {
    while ( 1 )
    {
      if ( v13 < 0 || v13 >= v3->_nsubexpr )
      {
        begin = match.begin;
        len = match.len;
      }
      else
      {
        matches = v3->_matches;
        begin = matches[v13].begin;
        len = matches[v13].len;
        match.begin = begin;
        match.len = len;
      }
      if ( len <= 0 )
        addrexmatch(v, begin: str, str, end: str);
      else
        addrexmatch(v, begin, str, end: &begin[len]);
      sq_arrayappend(v);
      if ( ++v13 >= n )
        break;
      v3 = self;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035910
// Name: _regexp_subexpcount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl regexp_subexpcount(SQVM *v)
{
  SQObjectPtr *v1; // eax
  tagSQObjectValue *v2; // esi
  int top; // eax
  tagSQObjectValue v4; // edx
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // esi
  SQObjectPtr *v7; // eax
  _DWORD *v8; // ecx

  v1 = &v->_stack._vals[v->_stackbase];
  v2 = nullptr;
  if ( v1->_type == OT_INSTANCE )
    v2 = *(tagSQObjectValue **)(v1->_unVal.nInteger + 32);
  else
    sq_throwerror(v, err: "the object is not a class instance");
  top = v->_top;
  v4.pTable = v2[8].pTable;
  v->_top = top + 1;
  vals = v->_stack._vals;
  type = vals[top]._type;
  v7 = &vals[top];
  v8 = &v7->_unVal.pTable->__vftable;
  v7->_unVal = v4;
  v7->_type = OT_INTEGER;
  if ( (type & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035980
// Name: _regexp_constructor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl regexp_constructor(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  bool v3; // zf
  int v4; // eax
  SQString *v5; // esi
  const char *v6; // eax
  const char *v7; // eax
  SQRex *v8; // eax
  int v10; // edx
  SQObjectPtr *v11; // ecx
  SQObjectPtr *v12; // ecx
  int v13; // eax
  SQObjectPtr *v14; // ecx
  tagSQObjectType type; // eax
  const char *pattern; // [esp+Ch] [ebp-4h] BYREF

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  v3 = vals[stackbase + 1]._type == OT_STRING;
  v4 = (int)&vals[stackbase + 1];
  if ( v3 )
  {
    v7 = (const char *)(*(_DWORD *)(v4 + 4) + 28);
  }
  else
  {
    v5 = SQVM::PrintObjVal(this: (SQVM *)vals, o: (const tagSQObject *)v);
    ++v5->_uiRef;
    v6 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v6, v5->_val);
    if ( --v5->_uiRef <= 0 )
      v5->Release(this: v5);
    v7 = pattern;
  }
  v8 = sqstd_rex_compile(pattern: v7, error: &pattern);
  if ( v8 == nullptr )
    return sq_throwerror(v, err: pattern);
  v10 = v->_stackbase;
  v11 = v->_stack._vals;
  v3 = v11[v10]._type == OT_INSTANCE;
  v12 = &v11[v10];
  if ( v3 )
    *(_DWORD *)(v12->_unVal.nInteger + 32) = v8;
  else
    sq_throwerror(v, err: "the object is not a class instance");
  v13 = v->_stackbase;
  if ( v->_top - v13 >= 1 )
  {
    v14 = &v->_stack._vals[v13];
    type = v14->_type;
    if ( v14->_type == OT_CLASS )
    {
      *(_DWORD *)(v14->_unVal.nInteger + 80) = rexobj_releasehook;
    }
    else
    {
      if ( type == OT_USERDATA )
      {
        *(_DWORD *)(v14->_unVal.nInteger + 32) = rexobj_releasehook;
        return 0;
      }
      if ( type == OT_INSTANCE )
      {
        *(_DWORD *)(v14->_unVal.nInteger + 36) = rexobj_releasehook;
        return 0;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035A90
// Name: _regexp__typeof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl regexp__typeof(SQVM *v)
{
  sq_pushstring(v, s: "regexp", len: -1);
  return 1;
}
