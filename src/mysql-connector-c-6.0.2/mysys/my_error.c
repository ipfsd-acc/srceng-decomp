// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_error.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00417400
// Name: _my_error
// Source: json
//------------------------------------------------------------------------------
int my_error(int a1, char a2, ...)
{
  _DWORD *v2; // eax
  int v4; // ecx
  _CONTEXT *v5; // eax
  _EXCEPTION_RECORD v6[6]; // [esp+4h] [ebp-204h] BYREF
  va_list va; // [esp+214h] [ebp+Ch] BYREF

  va_start(va, a2);
  v2 = my_errmsgs_list;
  if ( my_errmsgs_list == nullptr )
    goto LABEL_4;
  while ( a1 > v2[3] )
  {
    v2 = (_DWORD *)*v2;
    if ( v2 == nullptr )
      goto LABEL_4;
  }
  v4 = v2[2];
  if ( a1 >= v4 && (v5 = *(_CONTEXT **)(v2[1] + 4 * (a1 - v4))) != nullptr && LOBYTE(v5->ContextFlags) != 0 )
    my_vsnprintf(to: v6, n: (_EXCEPTION_REGISTRATION_RECORD *)0x200, fmt: v5, ap: va);
  else
LABEL_4:
    my_snprintf(
      result: (_cpinfo *)v6,
      n: (_EXCEPTION_REGISTRATION_RECORD *)0x200,
      fmt: (_CONTEXT *)"Unknown error %d",
      a1);
  return error_handler_hook[0](a1, string: (char *)v6, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x004174B0
// Name: _my_printf_error
// Source: json
//------------------------------------------------------------------------------
int my_printf_error(unsigned int error, _CONTEXT *format, char MyFlags, ...)
{
  IRecordInfo *ebuff; // [esp+0h] [ebp-204h] BYREF
  va_list va; // [esp+214h] [ebp+10h] BYREF

  va_start(va, MyFlags);
  my_vsnprintf(to: (_EXCEPTION_RECORD *)&ebuff, n: (_EXCEPTION_REGISTRATION_RECORD *)0x200, fmt: format, ap: va);
  return error_handler_hook[0](a1: error, string: (char *)&ebuff, a3: MyFlags);
}

//------------------------------------------------------------------------------
// Address: 0x00417520
// Name: _my_error_register
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_error_register(int a1, int a2, int a3)
{
  unsigned __int8 *v3; // eax
  unsigned __int8 *v5; // ecx
  unsigned __int8 **v6; // edx

  v3 = my_malloc(size: 0x10u, my_flags: 16);
  if ( v3 == nullptr )
    return 1;
  *((_DWORD *)v3 + 1) = a1;
  *((_DWORD *)v3 + 2) = a2;
  *((_DWORD *)v3 + 3) = a3;
  v5 = (unsigned __int8 *)my_errmsgs_list;
  v6 = (unsigned __int8 **)&my_errmsgs_list;
  if ( my_errmsgs_list == nullptr )
    goto LABEL_9;
  do
  {
    if ( *((_DWORD *)v5 + 3) > a2 )
      break;
    v6 = (unsigned __int8 **)v5;
    v5 = *(unsigned __int8 **)v5;
  }
  while ( v5 != nullptr );
  if ( *v6 != nullptr && *((_DWORD *)*v6 + 2) <= a3 )
  {
    my_no_flags_free(ptr: v3);
    return 1;
  }
  else
  {
LABEL_9:
    *(_DWORD *)v3 = *v6;
    *v6 = v3;
    return 0;
  }
}
