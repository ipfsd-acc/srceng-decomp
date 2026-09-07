// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/libmysql/pack.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040FE30
// Name: net_field_length(x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall net_field_length(unsigned __int16 *packet)
{
  unsigned __int8 *v1; // eax
  unsigned __int8 v2; // dl

  v1 = *(unsigned __int8 **)packet;
  v2 = **(_BYTE **)packet;
  if ( v2 >= 0xFBu )
  {
    switch ( v2 )
    {
      case 0xFB:
        *(_DWORD *)packet = v1 + 1;
        return -1;
      case 0xFC:
        *(_DWORD *)packet = v1 + 3;
        return *(unsigned __int16 *)(v1 + 1);
      case 0xFD:
        *(_DWORD *)packet = v1 + 4;
        return *(_DWORD *)(v1 + 1) & 0xFFFFFF;
      default:
        *(_DWORD *)packet = v1 + 9;
        return *(_DWORD *)(v1 + 1);
    }
  }
  else
  {
    *(_DWORD *)packet = v1 + 1;
    return *v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FE90
// Name: _net_field_length_ll
// Source: json
//------------------------------------------------------------------------------
__int64 __stdcall net_field_length_ll(char *packet)
{
  unsigned __int8 *v1; // ecx
  unsigned __int8 v2; // dl

  v1 = *(unsigned __int8 **)packet;
  v2 = **(_BYTE **)packet;
  if ( v2 >= 0xFBu )
  {
    switch ( v2 )
    {
      case 0xFB:
        *(_DWORD *)packet = v1 + 1;
        return 0xFFFFFFFFLL;
      case 0xFC:
        *(_DWORD *)packet = v1 + 3;
        return *(unsigned __int16 *)(v1 + 1);
      case 0xFD:
        *(_DWORD *)packet = v1 + 4;
        return *(_DWORD *)(v1 + 1) & 0xFFFFFF;
      default:
        *(_DWORD *)packet = v1 + 9;
        return *(_QWORD *)(v1 + 1);
    }
  }
  else
  {
    *(_DWORD *)packet = v1 + 1;
    return *v1;
  }
}
