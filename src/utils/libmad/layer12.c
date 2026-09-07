// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/libmad/layer12.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0051F5D0
// Name: _mad_layer_I
// Source: json
//------------------------------------------------------------------------------
int __cdecl mad_layer_I(mad_stream *stream, mad_frame *frame)
{
  mad_mode mode; // eax
  unsigned int v3; // edi
  unsigned int v4; // ebx
  int mode_extension; // eax
  unsigned __int16 v6; // ax
  unsigned int v8; // eax
  unsigned int v9; // edi
  unsigned __int8 *v10; // esi
  int v11; // eax
  unsigned __int8 v12; // al
  unsigned int v13; // esi
  int v14; // eax
  unsigned __int8 v15; // al
  unsigned int i; // ebx
  unsigned int v17; // edi
  unsigned int v18; // esi
  unsigned int v19; // edx
  unsigned int v20; // ecx
  int v21; // edi
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int *v25; // edx
  bool v26; // zf
  int v27; // edi
  int v28; // eax
  unsigned int v29; // edi
  unsigned __int8 *v30; // ecx
  int *v31; // esi
  int *v32; // eax
  unsigned int k; // ecx
  unsigned __int8 scalefactor[2][32]; // [esp+Ch] [ebp-A4h] BYREF
  unsigned __int8 allocation[2][32]; // [esp+4Ch] [ebp-64h] BYREF
  unsigned int v36; // [esp+8Ch] [ebp-24h]
  int *v37; // [esp+90h] [ebp-20h]
  unsigned int v38; // [esp+94h] [ebp-1Ch]
  unsigned int j; // [esp+98h] [ebp-18h]
  unsigned int bound; // [esp+9Ch] [ebp-14h]
  unsigned int nch; // [esp+A0h] [ebp-10h]
  int v42; // [esp+A4h] [ebp-Ch]
  int sample; // [esp+A8h] [ebp-8h]
  unsigned int sb; // [esp+ACh] [ebp-4h]

  mode = frame->header.mode;
  v3 = 32;
  bound = 32;
  v4 = (mode != MAD_MODE_SINGLE_CHANNEL) + 1;
  nch = v4;
  if ( mode == MAD_MODE_JOINT_STEREO )
  {
    mode_extension = frame->header.mode_extension;
    frame->header.flags |= 0x100u;
    bound = 4 * mode_extension + 4;
    v3 = bound;
  }
  if ( (frame->header.flags & 0x10) == 0
    || (v6 = mad_bit_crc(bitptr: stream->ptr, len: 4 * v3 * (v4 - 1) + 128, init: frame->header.crc_check),
        frame->header.crc_check = v6,
        v6 == frame->header.crc_target)
    || (frame->options & 1) != 0 )
  {
    v8 = 0;
    sb = 0;
    if ( v3 != 0 )
    {
      while ( 1 )
      {
        v9 = 0;
        if ( v4 != 0 )
          break;
LABEL_16:
        sb = ++v8;
        if ( v8 >= bound )
        {
          v3 = bound;
          goto LABEL_18;
        }
      }
      v10 = &allocation[0][v8];
      while ( 1 )
      {
        v11 = mad_bit_read(bitptr: &stream->ptr, len: 4u);
        if ( v11 == 15 )
          break;
        if ( v11 != 0 )
          v12 = v11 + 1;
        else
          v12 = 0;
        *v10 = v12;
        ++v9;
        v10 += 32;
        if ( v9 >= v4 )
        {
          v8 = sb;
          goto LABEL_16;
        }
      }
      stream->error = MAD_ERROR_BADBITALLOC;
      return -1;
    }
    else
    {
LABEL_18:
      v13 = v3;
      if ( v3 >= 0x20 )
      {
LABEL_25:
        for ( i = 0; i < 0x20; ++i )
        {
          v17 = nch;
          if ( nch != 0 )
          {
            v18 = i;
            do
            {
              if ( allocation[0][v18] != 0 )
                scalefactor[0][v18] = mad_bit_read(bitptr: &stream->ptr, len: 6u);
              v18 += 32;
              --v17;
            }
            while ( v17 != 0 );
          }
        }
        for ( j = 0; j < 0x180; j += 32 )
        {
          v19 = bound;
          v20 = 0;
          for ( sb = 0; v20 < v19; sb = v20 )
          {
            if ( nch != 0 )
            {
              v37 = &frame->sbsample[0][0][v20 + j];
              v38 = v20;
              v36 = nch;
              do
              {
                v21 = allocation[0][v38];
                if ( allocation[0][v38] != 0 )
                {
                  v22 = mad_bit_read(bitptr: &stream->ptr, len: allocation[0][v38]);
                  sample = sf_table[v21 + 62];
                  v42 = (0x10000000 >> (v21 - 1))
                      + (((1 << (v21 - 1)) ^ v22 | -(((1 << (v21 - 1)) ^ v22) & (1 << (v21 - 1)))) << (29 - v21));
                  v23 = scalefactor[0][v38];
                  sample = (unsigned __int64)(sample * (__int64)v42) >> 28;
                  v42 = sf_table[v23];
                  v24 = (unsigned __int64)(v42 * (__int64)sample) >> 28;
                  v20 = sb;
                }
                else
                {
                  v24 = 0;
                }
                v25 = v37;
                v38 += 32;
                *v37 = v24;
                v26 = v36-- == 1;
                v37 = v25 + 1152;
              }
              while ( !v26 );
              v19 = bound;
            }
            ++v20;
          }
          for ( sb = v19; v19 < 0x20; sb = v19 )
          {
            v27 = allocation[0][v19];
            if ( allocation[0][v19] != 0 )
            {
              v28 = mad_bit_read(bitptr: &stream->ptr, len: allocation[0][v19]);
              v42 = sf_table[v27 + 62];
              sample = (unsigned __int64)(v42
                                        * (__int64)((0x10000000 >> (v27 - 1))
                                                  + (((1 << (v27 - 1)) ^ v28
                                                    | -(((1 << (v27 - 1)) ^ v28) & (1 << (v27 - 1)))) << (29 - v27)))) >> 28;
              if ( nch != 0 )
              {
                v29 = nch;
                v30 = &scalefactor[0][sb];
                v31 = &frame->sbsample[0][0][sb + j];
                do
                {
                  v42 = sf_table[*v30];
                  *v31 = (unsigned __int64)(v42 * (__int64)sample) >> 28;
                  v30 += 32;
                  v31 += 1152;
                  --v29;
                }
                while ( v29 != 0 );
              }
              v19 = sb;
            }
            else if ( nch != 0 )
            {
              v32 = &frame->sbsample[0][0][v19 + j];
              for ( k = nch; k != 0; --k )
              {
                *v32 = 0;
                v32 += 1152;
              }
            }
            ++v19;
          }
        }
        return 0;
      }
      else
      {
        while ( 1 )
        {
          v14 = mad_bit_read(bitptr: &stream->ptr, len: 4u);
          if ( v14 == 15 )
            break;
          if ( v14 != 0 )
            v15 = v14 + 1;
          else
            v15 = 0;
          allocation[1][v13] = v15;
          allocation[0][v13++] = v15;
          if ( v13 >= 0x20 )
            goto LABEL_25;
        }
        stream->error = MAD_ERROR_BADBITALLOC;
        return -1;
      }
    }
  }
  else
  {
    stream->error = MAD_ERROR_BADCRC;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051F940
// Name: II_samples
// Source: json
//------------------------------------------------------------------------------
void __usercall II_samples(const quantclass *quantclass@<edi>, mad_bitptr *ptr, int *output)
{
  unsigned int bits; // esi
  unsigned int v4; // eax
  unsigned int nlevels; // ecx
  unsigned int v6; // eax
  int v7; // et2
  unsigned int i; // ebx
  int v9; // ebx
  char v10; // cl
  int *v11; // esi
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  unsigned int sample[3]; // [esp+8h] [ebp-1Ch] BYREF
  int v16; // [esp+14h] [ebp-10h]
  int C; // [esp+18h] [ebp-Ch]
  int v18; // [esp+1Ch] [ebp-8h]
  int v19; // [esp+20h] [ebp-4h]

  LOBYTE(bits) = quantclass->group;
  if ( (_BYTE)bits != 0 )
  {
    v4 = mad_bit_read(bitptr: ptr, len: quantclass->bits);
    nlevels = quantclass->nlevels;
    v7 = v4 % nlevels;
    v6 = v4 / nlevels;
    sample[0] = v7;
    sample[1] = v6 % nlevels;
    sample[2] = v6 / nlevels % nlevels;
  }
  else
  {
    bits = quantclass->bits;
    for ( i = 0; i < 3; ++i )
      sample[i] = mad_bit_read(bitptr: ptr, len: bits);
  }
  v9 = __ROL4__(1, bits);
  v10 = 29 - bits;
  v11 = output;
  v12 = __ROR4__(v9, 1);
  v13 = (char *)sample - (char *)output;
  v18 = (char *)sample - (char *)output;
  v19 = 3;
  while ( 1 )
  {
    v14 = *(int *)((char *)v11 + v13);
    C = quantclass->C;
    v16 = quantclass->D + ((v12 ^ v14 | -((v12 ^ v14) & v12)) << v10);
    *v11++ = (unsigned __int64)(C * (__int64)v16) >> 28;
    if ( --v19 == 0 )
      break;
    v13 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051FA00
// Name: _mad_layer_II
// Source: json
//------------------------------------------------------------------------------
int __cdecl mad_layer_II(mad_stream *stream, mad_frame *frame)
{
  int flags; // ebx
  mad_mode mode; // edi
  int v4; // eax
  unsigned int bitrate; // eax
  int v7; // eax
  unsigned int v8; // esi
  const unsigned __int8 *v9; // eax
  unsigned int v10; // edx
  mad_bitptr *p_ptr; // ebx
  int v12; // ecx
  unsigned __int8 *v13; // esi
  unsigned int i; // edi
  unsigned int v15; // edi
  unsigned __int8 *v16; // esi
  unsigned __int8 v17; // al
  unsigned int v18; // esi
  unsigned int v19; // edi
  unsigned int v20; // eax
  unsigned __int16 v21; // ax
  unsigned int v22; // edi
  unsigned __int8 v23; // al
  unsigned __int8 v24; // bl
  char *v25; // ebx
  _DWORD *v26; // esi
  unsigned int v27; // ecx
  int v28; // edi
  int v29; // edx
  _DWORD *v30; // eax
  unsigned int v31; // esi
  unsigned int v32; // ebx
  int v33; // ecx
  int v34; // ecx
  unsigned __int8 *v35; // ebx
  int v36; // edi
  _DWORD *v37; // esi
  unsigned int n; // ecx
  int v39; // eax
  unsigned int v40; // esi
  unsigned int ii; // edx
  unsigned int v42; // ecx
  int *v43; // eax
  unsigned __int16 crc_check; // [esp-8h] [ebp-1ACh]
  unsigned __int8 scfsi[2][32]; // [esp+8h] [ebp-19Ch]
  unsigned __int8 scalefactor[2][32][3]; // [esp+48h] [ebp-15Ch] BYREF
  unsigned __int8 allocation[2][32]; // [esp+108h] [ebp-9Ch] BYREF
  int samples[3]; // [esp+148h] [ebp-5Ch] BYREF
  const unsigned __int8 *v49; // [esp+154h] [ebp-50h]
  int v50; // [esp+158h] [ebp-4Ch]
  char *v51; // [esp+15Ch] [ebp-48h]
  int v52; // [esp+160h] [ebp-44h]
  const unsigned __int8 *v53; // [esp+164h] [ebp-40h]
  int m; // [esp+168h] [ebp-3Ch]
  mad_bitptr start; // [esp+16Ch] [ebp-38h] BYREF
  const unsigned __int8 *offsets; // [esp+174h] [ebp-30h]
  mad_bitptr *bitptr; // [esp+178h] [ebp-2Ch]
  unsigned int v58; // [esp+17Ch] [ebp-28h]
  unsigned int bound; // [esp+180h] [ebp-24h]
  char *v60; // [esp+184h] [ebp-20h]
  unsigned int nbal; // [esp+188h] [ebp-1Ch]
  unsigned int gr; // [esp+18Ch] [ebp-18h]
  unsigned int sblimit; // [esp+190h] [ebp-14h]
  unsigned int j; // [esp+194h] [ebp-10h]
  unsigned int nch; // [esp+198h] [ebp-Ch]
  unsigned int k; // [esp+19Ch] [ebp-8h]
  unsigned int sb; // [esp+1A0h] [ebp-4h]

  flags = frame->header.flags;
  mode = frame->header.mode;
  nch = (mode != MAD_MODE_SINGLE_CHANNEL) + 1;
  if ( (flags & 0x1000) == 0 )
  {
    if ( (flags & 0x400) == 0 )
    {
      bitrate = frame->header.bitrate;
      if ( mode != MAD_MODE_SINGLE_CHANNEL )
      {
        bitrate >>= 1;
      }
      else if ( bitrate > 0x2EE00 )
      {
        stream->error = 546;
        return -1;
      }
      if ( bitrate <= 0xBB80 )
      {
        v4 = (frame->header.samplerate == 32000) + 2;
        goto LABEL_13;
      }
      if ( bitrate <= 0x13880 )
      {
        v4 = 0;
        goto LABEL_13;
      }
    }
    v4 = frame->header.samplerate != 48000;
    goto LABEL_13;
  }
  v4 = 4;
LABEL_13:
  v7 = v4;
  v8 = sbquant_table[v7].sblimit;
  v9 = sbquant_table[v7].offsets;
  v10 = 32;
  sblimit = v8;
  offsets = v9;
  bound = 32;
  if ( mode == MAD_MODE_JOINT_STEREO )
  {
    v10 = 4 * frame->header.mode_extension + 4;
    frame->header.flags = flags | 0x100;
    bound = v10;
  }
  if ( v10 > v8 )
  {
    v10 = v8;
    bound = v8;
  }
  p_ptr = &stream->ptr;
  start.byte = stream->ptr.byte;
  v12 = *(_DWORD *)&stream->ptr.cache;
  bitptr = &stream->ptr;
  *(_DWORD *)&start.cache = v12;
  sb = 0;
  if ( v10 != 0 )
  {
    k = v9 - (const unsigned __int8 *)allocation;
    do
    {
      v13 = &allocation[0][sb];
      nbal = bitalloc_table[allocation[0][sb + k]].nbal;
      if ( nch != 0 )
      {
        for ( i = nch; i != 0; --i )
        {
          *v13 = mad_bit_read(bitptr: p_ptr, len: nbal);
          v13 += 32;
        }
      }
      ++sb;
    }
    while ( sb < bound );
  }
  v15 = bound;
  if ( bound < sblimit )
  {
    k = offsets - allocation[1];
    do
    {
      v16 = &allocation[1][v15];
      v17 = mad_bit_read(bitptr: p_ptr, len: bitalloc_table[allocation[1][v15++ + k]].nbal);
      *v16 = v17;
      *(v16 - 32) = v17;
    }
    while ( v15 < sblimit );
  }
  v18 = 0;
  for ( sb = 0; v18 < sblimit; sb = v18 )
  {
    v19 = nch;
    if ( nch != 0 )
    {
      do
      {
        if ( allocation[0][v18] != 0 )
          scfsi[0][v18] = mad_bit_read(bitptr: p_ptr, len: 2u);
        v18 += 32;
        --v19;
      }
      while ( v19 != 0 );
      v18 = sb;
    }
    ++v18;
  }
  if ( (frame->header.flags & 0x10) == 0
    || (crc_check = frame->header.crc_check,
        v20 = mad_bit_length(begin: &start, end: p_ptr),
        v21 = mad_bit_crc(bitptr: start, len: v20, init: crc_check),
        frame->header.crc_check = v21,
        v21 == frame->header.crc_target)
    || (frame->options & 1) != 0 )
  {
    sb = 0;
    if ( sblimit != 0 )
    {
      gr = 0;
      do
      {
        if ( nch != 0 )
        {
          v22 = gr;
          j = sb;
          for ( nbal = nch; nbal != 0; --nbal )
          {
            if ( allocation[0][j] != 0 )
            {
              v23 = mad_bit_read(bitptr, len: 6u);
              v24 = scfsi[0][j];
              scalefactor[0][0][v22] = v23;
              switch ( v24 )
              {
                case 0u:
                  scalefactor[0][0][v22 + 1] = mad_bit_read(bitptr, len: 6u);
                  goto $LN45_0;
                case 1u:
                case 3u:
$LN45_0:
                  v23 = mad_bit_read(bitptr, len: 6u);
                  goto LABEL_46;
                case 2u:
                  scalefactor[0][0][v22 + 1] = v23;
LABEL_46:
                  scalefactor[0][0][v22 + 2] = v23;
                  break;
                default:
                  break;
              }
              if ( (v24 & 1) != 0 )
                scalefactor[0][0][v22 + 1] = scfsi[1][v22 + 31 + v24];
            }
            j += 32;
            v22 += 96;
          }
        }
        gr += 3;
        ++sb;
      }
      while ( sb < sblimit );
    }
    gr = 0;
    nbal = 0;
    for ( j = 0; j < 0x480; j += 96 )
    {
      sb = 0;
      if ( bound != 0 )
      {
        v60 = nullptr;
        m = (char *)allocation - (char *)offsets;
        do
        {
          if ( nch != 0 )
          {
            v25 = v60;
            v49 = &offsets[sb];
            v53 = &offsets[sb + m];
            v51 = (char *)frame->sbsample + 4 * j + 4 * sb;
            v58 = (unsigned int)&frame->sbsample[0][1][j + sb];
            for ( k = nch; k != 0; --k )
            {
              if ( *v53 != 0 )
              {
                II_samples(
                  quantclass: &qc_table[(unsigned __int8)byte_5CBFCF[15 * bitalloc_table[*v49].offset + *v53]],
                  ptr: bitptr,
                  output: samples);
                v26 = v51;
                v27 = 0;
                v28 = scalefactor[0][0][(_DWORD)&v25[gr >> 2]];
                do
                {
                  v29 = samples[v27];
                  v52 = sf_table[v28];
                  v50 = v29;
                  *v26 = (unsigned __int64)(v52 * (__int64)v29) >> 28;
                  ++v27;
                  v26 += 32;
                }
                while ( v27 < 3 );
              }
              else
              {
                v30 = (_DWORD *)v58;
                *(_DWORD *)(v58 - 128) = 0;
                *v30 = 0;
                v30[32] = 0;
              }
              v53 += 32;
              v51 += 4608;
              v58 += 4608;
              v25 += 96;
            }
          }
          v60 += 3;
          ++sb;
        }
        while ( sb < bound );
      }
      v31 = bound;
      v32 = sblimit;
      sb = bound;
      if ( bound < sblimit )
      {
        v33 = (char *)allocation - (char *)offsets;
        v58 = 3 * bound;
        for ( m = (char *)allocation - (char *)offsets; ; v33 = m )
        {
          v34 = offsets[v31 + v33];
          if ( v34 != 0 )
          {
            II_samples(
              quantclass: &qc_table[(unsigned __int8)byte_5CBFCF[15 * bitalloc_table[offsets[v31]].offset + v34]],
              ptr: bitptr,
              output: samples);
            if ( nch != 0 )
            {
              v35 = &scalefactor[0][0][v58 + (gr >> 2)];
              v60 = (char *)frame->sbsample + 4 * v31 + 4 * j;
              for ( k = nch; k != 0; --k )
              {
                v36 = *v35;
                v37 = v60;
                for ( n = 0; n < 3; ++n )
                {
                  v39 = samples[n];
                  v50 = sf_table[v36];
                  v52 = v39;
                  *v37 = (unsigned __int64)(v50 * (__int64)v39) >> 28;
                  v37 += 32;
                }
                v60 += 4608;
                v35 += 96;
              }
              v32 = sblimit;
              v31 = sb;
            }
          }
          else
          {
            v42 = nch;
            if ( nch != 0 )
            {
              v43 = &frame->sbsample[0][1][v31 + j];
              do
              {
                *(v43 - 32) = 0;
                *v43 = 0;
                v43[32] = 0;
                v43 += 1152;
                --v42;
              }
              while ( v42 != 0 );
            }
          }
          v58 += 3;
          sb = ++v31;
          if ( v31 >= v32 )
            break;
        }
      }
      if ( nch != 0 )
      {
        v40 = nbal;
        for ( k = nch; k != 0; --k )
        {
          for ( ii = 0; ii < 3; ++ii )
          {
            if ( v32 < 0x20 )
              memset((char *)frame->sbsample + 128 * v40 + 128 * ii + 4 * v32, 0, 4 * (32 - v32));
          }
          v40 += 36;
        }
      }
      ++gr;
      nbal += 3;
    }
    return 0;
  }
  else
  {
    stream->error = MAD_ERROR_BADCRC;
    return -1;
  }
}
