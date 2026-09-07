// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_access.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042F770
// Name: _my_access
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_access(LPCSTR lpFileName, char a2)
{
  _BYTE FileInformation[36]; // [esp+0h] [ebp-24h] BYREF

  if ( GetFileAttributesExA(lpFileName, fInfoLevelId: GetFileExInfoStandard, lpFileInformation: FileInformation)
    && ((FileInformation[0] & 1) == 0 || (a2 & 2) == 0) )
  {
    return 0;
  }
  *_errno() = 13;
  *(_DWORD *)_my_thread_var() = 13;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042F7C0
// Name: _check_if_legal_filename
// Source: json
//------------------------------------------------------------------------------
void __thiscall check_if_legal_filename(ExprNode **path, unsigned __int8 *patha)
{
  char *v2; // edi
  ioinfo *v3; // eax
  char *v4; // edx
  char v5; // cl
  char *v6; // esi
  char **pathb; // [esp+8h] [ebp+4h]

  v2 = (char *)&patha[dirname_length(string: patha)];
  strchr(string: v2, chr: 0x2Eu);
  if ( v3 == nullptr )
    v3 = strend(result: (ioinfo *)v2);
  if ( v2 != (char *)v3 && (unsigned int)((char *)v3 - v2) <= 6 )
  {
    v4 = reserved_names[0];
    for ( pathb = reserved_names; v4 != nullptr; ++pathb )
    {
      v5 = *v4;
      v6 = v2;
      do
      {
        if ( v5 != *((_BYTE *)off_4904B0 + (unsigned __int8)*v6) )
          break;
        if ( ++v6 == (char *)v3 && v4[1] == 0 )
          return;
        v5 = *++v4;
      }
      while ( v5 != 0 );
      v4 = pathb[1];
    }
  }
}
