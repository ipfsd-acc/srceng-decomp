// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/sqstdlib/sqstdaux.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10030870
// Name: _sqstd_printcallstack
// Source: json
//------------------------------------------------------------------------------
void __usercall sqstd_printcallstack(SQVM *v@<eax>)
{
  void (*printfunc)(SQVM *, const char *, ...); // ebx
  int v3; // edi
  const char *funcname; // ecx
  const char *source; // eax
  const char *v6; // edi
  tagSQObjectType v7; // eax
  int v8; // edx
  SQObjectPtr *v9; // eax
  bool v10; // zf
  int v11; // eax
  const char *v12; // eax
  int v13; // edx
  SQObjectPtr *v14; // eax
  tagSQObjectType v15; // ecx
  int v16; // eax
  int v17; // ecx
  SQObjectPtr *v18; // edx
  tagSQObjectType type; // eax
  int v20; // ecx
  float v21; // xmm0_4
  __int32 v22; // eax
  __int32 v23; // eax
  int top; // eax
  SQObjectPtr *vals; // ecx
  int v26; // eax
  SQString *v27; // ebx
  const char *v28; // eax
  __int32 v29; // eax
  __int32 v30; // eax
  const char *name; // [esp+1Ch] [ebp-2Ch]
  signed int level; // [esp+20h] [ebp-28h]
  signed int seq; // [esp+24h] [ebp-24h]
  int i; // [esp+28h] [ebp-20h]
  float f; // [esp+2Ch] [ebp-1Ch]
  const char *s; // [esp+30h] [ebp-18h]
  void (*v37)(SQVM *, const char *, ...); // [esp+34h] [ebp-14h]
  unsigned int b; // [esp+38h] [ebp-10h]
  tagSQStackInfos v39; // [esp+3Ch] [ebp-Ch] BYREF

  printfunc = v->_sharedstate->_printfunc;
  v37 = printfunc;
  if ( printfunc != nullptr )
  {
    v3 = 1;
    printfunc(a1: v, a2: "\nCALLSTACK\n");
    if ( sq_stackinfos(v, level: 1, si: &v39) >= 0 )
    {
      do
      {
        funcname = "unknown";
        source = "unknown";
        if ( v39.funcname != nullptr )
          funcname = v39.funcname;
        if ( v39.source != nullptr )
          source = v39.source;
        printfunc(a1: v, a2: "*FUNCTION [%s()] %s line [%d]\n", funcname, source, v39.line);
        ++v3;
      }
      while ( sq_stackinfos(v, level: v3, si: &v39) >= 0 );
    }
    printfunc(a1: v, a2: "\nLOCALS\n");
    level = 0;
    while ( 1 )
    {
      seq = 0;
      v6 = sq_getlocal(level, idx: 0);
      name = v6;
      if ( v6 != nullptr )
        break;
LABEL_67:
      if ( ++level >= 10 )
        return;
    }
    while ( 1 )
    {
      ++seq;
      v7 = sq_gettype(v, idx: -1);
      if ( v7 > OT_NATIVECLOSURE )
      {
        if ( v7 > OT_WEAKREF )
        {
          v29 = v7 - 167772192;
          if ( v29 != 0 )
          {
            v30 = v29 - 96;
            if ( v30 != 0 )
            {
              if ( v30 == 32640 )
                printfunc(a1: v, a2: "[%s] INSTANCE\n", v6);
            }
            else
            {
              printfunc(a1: v, a2: "[%s] USERDATA\n", v6);
            }
          }
          else
          {
            printfunc(a1: v, a2: "[%s] TABLE\n", v6);
          }
        }
        else
        {
          switch ( v7 )
          {
            case OT_WEAKREF:
              printfunc(a1: v, a2: "[%s] WEAKREF\n", v6);
              break;
            case OT_GENERATOR:
              printfunc(a1: v, a2: "[%s] GENERATOR\n", v6);
              break;
            case OT_THREAD:
              printfunc(a1: v, a2: "[%s] THREAD\n", v6);
              break;
            case OT_CLASS:
              printfunc(a1: v, a2: "[%s] CLASS\n", v6);
              break;
            default:
              break;
          }
        }
      }
      else if ( v7 == OT_NATIVECLOSURE )
      {
        printfunc(a1: v, a2: "[%s] NATIVECLOSURE\n", v6);
      }
      else if ( v7 > OT_FLOAT )
      {
        v22 = v7 - 134217744;
        if ( v22 != 0 )
        {
          v23 = v22 - 48;
          if ( v23 != 0 )
          {
            if ( v23 == 192 )
              printfunc(a1: v, a2: "[%s] CLOSURE\n", v6);
          }
          else
          {
            printfunc(a1: v, a2: "[%s] ARRAY\n", v6);
          }
        }
        else
        {
          top = v->_top;
          vals = v->_stack._vals;
          v10 = vals[top - 1]._type == OT_STRING;
          v26 = (int)&vals[top - 1];
          if ( v10 )
          {
            s = (const char *)(*(_DWORD *)(v26 + 4) + 28);
            printfunc(a1: v, a2: "[%s] \"%s\"\n", v6, s);
          }
          else
          {
            v27 = SQVM::PrintObjVal(this: (SQVM *)vals, o: (const tagSQObject *)v);
            ++v27->_uiRef;
            v28 = IdType2Name(type: OT_STRING);
            SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v28, v27->_val);
            if ( --v27->_uiRef <= 0 )
              v27->Release(this: v27);
            printfunc = v37;
            v37(a1: v, a2: "[%s] \"%s\"\n", name, s);
          }
        }
      }
      else if ( v7 == OT_FLOAT )
      {
        v17 = v->_top;
        v18 = v->_stack._vals;
        type = v18[v17 - 1]._type;
        v20 = (int)&v18[v17 - 1];
        if ( (type & 0x4000000) != 0 )
        {
          if ( type == OT_INTEGER )
            v21 = (float)*(int *)(v20 + 4);
          else
            v21 = *(float *)(v20 + 4);
          f = v21;
        }
        printfunc(a1: v, a2: "[%s] %.14g\n", v6, f);
      }
      else if ( v7 > OT_BOOL )
      {
        if ( v7 != OT_INTEGER )
          goto LABEL_66;
        v13 = v->_top;
        v14 = v->_stack._vals;
        v15 = v14[v13 - 1]._type;
        v16 = (int)&v14[v13 - 1];
        if ( (v15 & 0x4000000) != 0 )
        {
          if ( v15 == OT_FLOAT )
          {
            i = (int)*(float *)(v16 + 4);
            printfunc(a1: v, a2: "[%s] %d\n", v6, i);
            goto LABEL_66;
          }
          i = *(_DWORD *)(v16 + 4);
        }
        printfunc(a1: v, a2: "[%s] %d\n", v6, i);
      }
      else
      {
        switch ( v7 )
        {
          case OT_BOOL:
            v8 = v->_top;
            v9 = v->_stack._vals;
            v10 = v9[v8 - 1]._type == OT_BOOL;
            v11 = (int)&v9[v8 - 1];
            if ( v10 )
              b = *(_DWORD *)(v11 + 4);
            v12 = "true";
            if ( b == 0 )
              v12 = "false";
            printfunc(a1: v, a2: "[%s] %s\n", v6, v12);
            break;
          case OT_USERPOINTER:
            printfunc(a1: v, a2: "[%s] USERPOINTER\n", v6);
            break;
          case OT_NULL:
            printfunc(a1: v, a2: "[%s] NULL\n", v6);
            break;
          default:
            break;
        }
      }
LABEL_66:
      SQVM::Pop(this: v, n: 1);
      name = sq_getlocal(level, idx: seq);
      if ( name == nullptr )
        goto LABEL_67;
      v6 = name;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030CC0
// Name: void _sqstd_compiler_error(struct SQVM __near *,char const __near *,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _sqstd_compiler_error(SQVM *v, const char *sErr, const char *sSource, int line, int column)
{
  void (*printfunc)(SQVM *, const char *, ...); // eax

  printfunc = v->_sharedstate->_printfunc;
  if ( printfunc != nullptr )
    printfunc(a1: v, a2: "%s line = (%d) column = (%d) : error %s\n", sSource, line, column, sErr);
}

//------------------------------------------------------------------------------
// Address: 0x10030C00
// Name: _sqstd_aux_printerror
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sqstd_aux_printerror(SQVM *v)
{
  void (*printfunc)(SQVM *, const char *, ...); // ebx
  int stackbase; // eax
  int v3; // ecx
  SQObjectPtr *vals; // edx
  bool v5; // zf
  int v6; // eax
  SQString *v7; // esi
  const char *v8; // eax

  printfunc = v->_sharedstate->_printfunc;
  if ( printfunc == nullptr )
    return 0;
  stackbase = v->_stackbase;
  v3 = v->_top - stackbase;
  if ( v3 < 1 )
    return 0;
  vals = v->_stack._vals;
  v5 = vals[stackbase + 1]._type == OT_STRING;
  v6 = (int)&vals[stackbase + 1];
  if ( !v5 )
  {
    v7 = SQVM::PrintObjVal(this: (SQVM *)v3, o: (const tagSQObject *)v);
    ++v7->_uiRef;
    v8 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v8, v7->_val);
    if ( --v7->_uiRef <= 0 )
      v7->Release(this: v7);
    printfunc(a1: v, a2: "\nAN ERROR HAS OCCURED [unknown]\n");
    sqstd_printcallstack(v);
    return 0;
  }
  printfunc(a1: v, a2: "\nAN ERROR HAS OCCURED [%s]\n", *(_DWORD *)(v6 + 4) + 28);
  sqstd_printcallstack(v);
  return 0;
}
