// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/my_strtoll10.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00411380
// Name: _my_strtoll10
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strtoll10(_BYTE *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v4; // edi
  _BYTE *v5; // esi
  unsigned int v6; // ebx
  unsigned __int64 v7; // rax
  _BYTE *v8; // ecx
  unsigned __int8 v9; // al
  _BYTE *v10; // ebp
  unsigned int v11; // ecx
  _BYTE *v12; // edi
  unsigned __int8 v13; // al
  unsigned __int8 v14; // al
  _BYTE *v15; // esi
  unsigned int v16; // edi
  unsigned __int8 v17; // al
  _BYTE *v18; // esi
  unsigned int v19; // edi
  unsigned int v21; // [esp+Ch] [ebp-10h]
  unsigned int v22; // [esp+10h] [ebp-Ch]
  unsigned int v23; // [esp+14h] [ebp-8h]
  _BYTE *v24; // [esp+18h] [ebp-4h]
  int v25; // [esp+20h] [ebp+4h]

  v4 = a2;
  v5 = a1;
  if ( a2 != nullptr )
  {
    v6 = *a2;
    if ( a1 == (_BYTE *)*a2 )
      goto LABEL_27;
    while ( *v5 == 32 || *v5 == 9 )
    {
      if ( ++v5 == (_BYTE *)v6 )
      {
        *a3 = 33;
        *v4 = a1;
        LODWORD(v7) = 0;
        return v7;
      }
    }
    if ( v5 == (_BYTE *)v6 )
      goto LABEL_27;
  }
  else
  {
    a2 = &a2;
    while ( *v5 == 32 || *v5 == 9 )
      ++v5;
    v4 = a2;
    if ( *v5 == 0 )
      goto LABEL_27;
    v6 = (unsigned int)(v5 + 0xFFFF);
  }
  v25 = 0;
  if ( *v5 == 45 )
  {
    ++v5;
    *a3 = -1;
    v25 = 1;
    if ( v5 == (_BYTE *)v6 )
      goto LABEL_27;
    v21 = 92233720;
    v22 = 368547758;
    v23 = 8;
  }
  else
  {
    *a3 = 0;
    if ( *v5 == 43 && ++v5 == (_BYTE *)v6 )
      goto LABEL_27;
    v21 = 184467440;
    v22 = 737095516;
    v23 = 15;
  }
  if ( *v5 != 48 )
  {
    v9 = *v5 - 48;
    if ( v9 <= 9u )
    {
      ++v5;
      HIDWORD(v7) = v9;
      v8 = v5 + 8;
      goto LABEL_30;
    }
LABEL_27:
    *a3 = 33;
    *v4 = a1;
    LODWORD(v7) = 0;
    return v7;
  }
  HIDWORD(v7) = 0;
  do
  {
    if ( ++v5 == (_BYTE *)v6 )
      goto LABEL_36;
  }
  while ( *v5 == 48 );
  v8 = v5 + 9;
LABEL_30:
  if ( (unsigned int)v8 > v6 )
    v8 = (_BYTE *)v6;
  for ( ; v5 != v8; HIDWORD(v7) = (unsigned __int8)v7 + 10 * HIDWORD(v7) )
  {
    LOBYTE(v7) = *v5 - 48;
    if ( (unsigned __int8)v7 > 9u )
      goto LABEL_36;
    ++v5;
  }
  if ( v5 != (_BYTE *)v6 )
  {
    v10 = v5 + 9;
    v11 = 0;
    v24 = v5;
    v12 = v5 + 9;
    if ( (unsigned int)(v5 + 9) > v6 )
      v12 = (_BYTE *)v6;
    do
    {
      v13 = *v5 - 48;
      if ( v13 > 9u )
        goto LABEL_44;
      ++v5;
      v11 = v13 + 10 * v11;
    }
    while ( v5 != v12 );
    if ( v5 == (_BYTE *)v6 )
    {
      if ( v5 != v10 )
      {
LABEL_44:
        LODWORD(v7) = lfactor[v5 - v24];
        goto LABEL_47;
      }
    }
    else
    {
      v14 = *v5 - 48;
      if ( v14 <= 9u )
      {
        v15 = v5 + 1;
        v16 = v14;
        if ( v15 == (_BYTE *)v6 || (v17 = *v15 - 48) > 9u )
        {
          v7 = v16 + 10 * (v11 + 1000000000LL * HIDWORD(v7));
          *a2 = v15;
          if ( v25 == 0 )
            return v7;
          if ( v7 <= 0x8000000000000000uLL )
            return -(__int64)v7;
        }
        else
        {
          v18 = v15 + 1;
          v19 = v17 + 10 * v16;
          *a2 = v18;
          if ( (v18 == (_BYTE *)v6 || (unsigned __int8)(*v18 - 48) > 9u)
            && HIDWORD(v7) <= v21
            && (HIDWORD(v7) != v21 || v11 < v22 || v19 <= v23) )
          {
            LODWORD(v7) = v19 + 100 * (v11 + 1000000000 * HIDWORD(v7));
            return v7;
          }
        }
        *a3 = 34;
        if ( v25 != 0 )
          LODWORD(v7) = 0;
        else
          LODWORD(v7) = -1;
        return v7;
      }
    }
    v7 = HIDWORD(v7) | 0x3B9ACA0000000000LL;
LABEL_47:
    v7 = v11 + HIDWORD(v7) * (unsigned __int64)(unsigned int)v7;
    *a2 = v5;
    if ( v25 == 0 )
      return v7;
    return -(__int64)v7;
  }
LABEL_36:
  *v4 = v5;
  LODWORD(v7) = HIDWORD(v7);
  if ( v25 != 0 )
    LODWORD(v7) = -HIDWORD(v7);
  return v7;
}
