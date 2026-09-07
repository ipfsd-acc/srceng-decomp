// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/libmad/timer.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0051FFE0
// Name: scale_rational
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall scale_rational@<eax>(unsigned int denom@<eax>, unsigned int numer, unsigned int scale)
{
  unsigned int v3; // ecx
  unsigned int v4; // esi
  int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // edi
  unsigned int v8; // ecx
  int v9; // edx
  unsigned int v10; // ebx
  unsigned int v11; // ecx
  unsigned int numera; // [esp+14h] [ebp+8h]

  v3 = numer;
  v4 = denom;
  if ( denom != 0 )
  {
    do
    {
      v5 = v3 % v4;
      v3 = v4;
      v4 = v5;
    }
    while ( v5 != 0 );
  }
  v6 = scale;
  numera = numer / v3;
  v7 = denom / v3;
  v8 = v7;
  if ( v7 != 0 )
  {
    do
    {
      v9 = v6 % v8;
      v6 = v8;
      v8 = v9;
    }
    while ( v9 != 0 );
  }
  v10 = scale / v6;
  v11 = v7 / v6;
  if ( v7 / v6 < scale / v6 )
    return numera * (v10 / v11) + numera * (v10 % v11) / v11;
  if ( v11 >= numera )
    return v10 * numera / v11;
  return v10 * (v7 / v6 / v11) + v10 * (v7 / v6 % v11) / v11;
}

//------------------------------------------------------------------------------
// Address: 0x00520090
// Name: _mad_timer_set
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_timer_set(mad_timer_t *timer, unsigned int seconds, unsigned int numer, unsigned int denom)
{
  unsigned int v4; // eax
  unsigned int fraction; // eax

  v4 = numer;
  timer->seconds = seconds;
  if ( numer >= denom && denom != 0 )
  {
    timer->seconds = seconds + numer / denom;
    v4 = numer % denom;
  }
  if ( denom > 0x5622 )
  {
    if ( denom > 0xAC44 )
    {
      if ( denom == 48000 )
      {
        v4 *= 7350;
        goto LABEL_32;
      }
      if ( denom != 352800000 )
        goto LABEL_30;
      goto LABEL_32;
    }
    switch ( denom )
    {
      case 0xAC44u:
        v4 *= 8000;
        goto LABEL_32;
      case 0x5DC0u:
        v4 *= 14700;
        goto LABEL_32;
      case 0x7D00u:
        v4 *= 11025;
        goto LABEL_32;
      default:
        break;
    }
LABEL_30:
    v4 = scale_rational(denom, numer: v4, scale: 0x15074D00u);
    goto LABEL_32;
  }
  if ( denom == 22050 )
  {
    v4 *= 16000;
    goto LABEL_32;
  }
  if ( denom > 0x2B11 )
  {
    if ( denom == 12000 )
    {
      v4 *= 29400;
      goto LABEL_32;
    }
    if ( denom == 16000 )
    {
      v4 *= 22050;
      goto LABEL_32;
    }
    goto LABEL_30;
  }
  if ( denom == 11025 )
  {
    v4 *= 32000;
    goto LABEL_32;
  }
  if ( denom > 0x3E8 )
  {
    if ( denom == 8000 )
    {
      v4 *= 44100;
      goto LABEL_32;
    }
    goto LABEL_30;
  }
  if ( denom != 1000 )
  {
    if ( denom <= 1 )
    {
      timer->fraction = 0;
      goto LABEL_33;
    }
    goto LABEL_30;
  }
  v4 *= 352800;
LABEL_32:
  timer->fraction = v4;
LABEL_33:
  fraction = timer->fraction;
  if ( fraction >= 0x15074D00 )
  {
    timer->seconds += fraction / 0x15074D00;
    timer->fraction = fraction % 0x15074D00;
  }
}
