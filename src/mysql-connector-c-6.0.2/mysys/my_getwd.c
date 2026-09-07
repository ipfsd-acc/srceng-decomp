// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_getwd.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00419EB0
// Name: _my_getwd
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_getwd(char *pnbuf, int a2, char a3)
{
  int *v4; // esi
  int *v5; // eax
  ioinfo *v6; // eax

  if ( (_BYTE)curr_dir != 0 )
  {
    strmake(dst: pnbuf, src: (char *)&curr_dir, length: a2 - 1);
    return 0;
  }
  else if ( _getcwd(pnbuf, maxlen: a2 - 2) != nullptr || (a3 & 0x10) == 0 )
  {
    v6 = strend(result: (ioinfo *)pnbuf);
    if ( *((_BYTE *)&v6[-1].dbcsBufferUsed + 7) != 92 )
    {
      LOBYTE(v6->osfhnd) = 92;
      BYTE1(v6->osfhnd) = 0;
    }
    strmake(dst: (char *)&curr_dir, src: pnbuf, length: 0x1FFu);
    return 0;
  }
  else
  {
    v4 = _errno();
    *(_DWORD *)_my_thread_var() = *v4;
    v5 = _errno();
    my_error(a1: 16, a2: 36, *v5);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419F50
// Name: _test_if_hard_path
// Source: json
//------------------------------------------------------------------------------
void __thiscall test_if_hard_path(ExprNode **dir_name, tagShutdownType dir_namea)
{
  if ( *(_BYTE *)dir_namea == 126 && *(_BYTE *)(dir_namea + 1) == 92 )
  {
    if ( home_dir != nullptr )
      test_if_hard_path(dir_name: (ExprNode **)dir_namea);
  }
  else if ( *(_BYTE *)dir_namea != 92 )
  {
    strchr(string: (unsigned __int8 *)dir_namea, chr: 0x3Au);
  }
}
