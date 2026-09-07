// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/mf_loadpath.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042F870
// Name: _my_load_path
// Source: json
//------------------------------------------------------------------------------
char *__cdecl my_load_path(char *a1, _LDBL12 *result, tagShutdownType src)
{
  ExprNode **v3; // ecx
  bool v4; // zf
  int v5; // eax
  int v6; // edi
  void *v7; // ecx
  unsigned __int8 *v8; // edx
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  char *v12; // esi
  char *v14; // [esp+8h] [ebp-208h] BYREF
  char dst[512]; // [esp+Ch] [ebp-204h] BYREF

  v4 = result->ld12[0] == 126;
  v14 = a1;
  if ( v4 && result->ld12[1] == 92 || (test_if_hard_path(dir_name: v3, dir_namea: (tagShutdownType)result), v5 != 0) )
  {
    strmov(dst, dsta: dst, src: (char *)result);
  }
  else
  {
    if ( result->ld12[0] == 46 && result->ld12[1] == 92 )
    {
      v6 = 2;
    }
    else
    {
      v6 = 0;
      if ( is_prefix(result, t: "..") == 0 && src != IdleShutdown )
      {
        strxmov(dst, src);
        goto LABEL_16;
      }
    }
    if ( my_getwd(pnbuf: dst, a2: v6 - strlen((const char *)result) + 512, a3: 0) != 0 )
    {
      strmov(dst: v7, dsta: dst, src: (char *)result);
    }
    else
    {
      v8 = &result->ld12[v6];
      v9 = strlen((const char *)&result->ld12[v6]) + 1;
      v10 = (char *)&v14 + 3;
      do
        v11 = *++v10;
      while ( v11 != 0 );
      qmemcpy(v10, v8, v9);
    }
  }
LABEL_16:
  v12 = v14;
  strmov(dst, dsta: v14, src: dst);
  return v12;
}
