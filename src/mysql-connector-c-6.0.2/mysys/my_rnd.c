// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_rnd.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004185B0
// Name: _my_rnd_init
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_rnd_init(int a1, unsigned int a2, unsigned int a3)
{
  *(_DWORD *)(a1 + 8) = 0x3FFFFFFF;
  *(double *)(a1 + 16) = 1073741823.0;
  *(_DWORD *)a1 = a2 % 0x3FFFFFFF;
  *(_DWORD *)(a1 + 4) = a3 % 0x3FFFFFFF;
  return a3 / 0x3FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x004185F0
// Name: _my_rnd
// Source: json
//------------------------------------------------------------------------------
double __cdecl my_rnd(int a1)
{
  int v1; // esi
  unsigned int v2; // edi
  unsigned int v3; // edx
  double v4; // st7

  v1 = *(_DWORD *)(a1 + 4);
  v2 = *(_DWORD *)(a1 + 8);
  v3 = (*(_DWORD *)a1 + v1 + 2 * *(_DWORD *)a1) % v2;
  *(_DWORD *)a1 = v3;
  v4 = (double)*(unsigned int *)a1;
  *(_DWORD *)(a1 + 4) = (v3 + v1 + 33) % v2;
  return v4 / *(double *)(a1 + 16);
}
