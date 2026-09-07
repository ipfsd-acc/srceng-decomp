// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/mf_fn_ext.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004245C0
// Name: _fn_ext
// Source: json
//------------------------------------------------------------------------------
void __cdecl fn_ext(ioinfo *result)
{
  unsigned __int8 *v1; // esi
  int v2; // eax
  unsigned int res_length; // [esp+8h] [ebp-208h] BYREF
  IRecordInfo *buff; // [esp+Ch] [ebp-204h] BYREF

  v1 = (unsigned __int8 *)result
     + dirname_part(dst: (unsigned __int8 *)&buff, string: (unsigned __int8 *)result, a3: &res_length);
  strchr(string: v1, chr: 0x2Eu);
  if ( v2 == 0 )
    strend(result: (ioinfo *)v1);
}
