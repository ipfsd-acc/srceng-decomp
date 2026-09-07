// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/libmad/layer3.c
// Functions: 18
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0051CCF0
// Name: III_sideinfo
// Source: json
//------------------------------------------------------------------------------
mad_error __usercall III_sideinfo@<eax>(
        mad_bitptr *ptr@<edi>,
        unsigned int nch,
        int lsf,
        sideinfo *si,
        unsigned int *data_bitlen,
        unsigned int *priv_bitlen)
{
  int v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned int i; // ebx
  unsigned __int16 *p_big_values; // esi
  unsigned int j; // ebx
  unsigned __int16 v13; // ax
  int v14; // edx
  char v15; // al
  unsigned int k; // ebx
  unsigned int m; // ebx
  unsigned int n; // ebx
  bool v19; // zf
  int v21; // [esp+10h] [ebp-Ch]
  unsigned __int16 *v22; // [esp+14h] [ebp-8h]
  unsigned int ngr; // [esp+18h] [ebp-4h]
  mad_error v24; // [esp+34h] [ebp+18h]

  *data_bitlen = 0;
  v7 = 0;
  v24 = MAD_ERROR_NONE;
  if ( lsf != 0 )
  {
    LOBYTE(v7) = nch != 1;
    v8 = v7 + 1;
  }
  else
  {
    LOBYTE(v7) = nch == 1;
    v8 = 2 * v7 + 3;
  }
  *priv_bitlen = v8;
  si->main_data_begin = mad_bit_read(bitptr: ptr, len: 9 - (lsf != 0));
  si->private_bits = mad_bit_read(bitptr: ptr, len: *priv_bitlen);
  v9 = 1;
  if ( lsf == 0 )
  {
    for ( i = 0; i < nch; ++i )
      si->scfsi[i] = mad_bit_read(bitptr: ptr, len: 4u);
    v9 = 2;
  }
  p_big_values = &si->gr[0].ch[0].big_values;
  v22 = &si->gr[0].ch[0].big_values;
  v21 = v9;
  do
  {
    ngr = 0;
    if ( nch != 0 )
    {
      for ( j = lsf != 0 ? 9 : 4; ; j = lsf != 0 ? 9 : 4 )
      {
        *(p_big_values - 1) = mad_bit_read(bitptr: ptr, len: 0xCu);
        *p_big_values = mad_bit_read(bitptr: ptr, len: 9u);
        p_big_values[1] = mad_bit_read(bitptr: ptr, len: 8u);
        v13 = mad_bit_read(bitptr: ptr, len: j);
        v14 = *(p_big_values - 1);
        p_big_values[2] = v13;
        *data_bitlen += v14;
        if ( *p_big_values > 0x120u && v24 == MAD_ERROR_NONE )
          v24 = MAD_ERROR_BADBIGVALUES;
        *((_BYTE *)p_big_values + 6) = 0;
        if ( mad_bit_read(bitptr: ptr, len: 1u) != 0 )
        {
          v15 = mad_bit_read(bitptr: ptr, len: 2u);
          *((_BYTE *)p_big_values + 7) = v15;
          if ( v15 == 0 && v24 == MAD_ERROR_NONE )
            v24 = MAD_ERROR_BADBLOCKTYPE;
          if ( lsf == 0 && v15 == 2 && si->scfsi[ngr] != 0 && v24 == MAD_ERROR_NONE )
            v24 = MAD_ERROR_BADSCFSI;
          p_big_values[7] = 9223;
          if ( mad_bit_read(bitptr: ptr, len: 1u) != 0 )
          {
            *((_BYTE *)p_big_values + 6) |= 8u;
          }
          else if ( *((_BYTE *)p_big_values + 7) == 2 )
          {
            *((_BYTE *)p_big_values + 14) = 8;
          }
          for ( k = 0; k < 2; ++k )
            *((_BYTE *)p_big_values + k + 8) = mad_bit_read(bitptr: ptr, len: 5u);
          for ( m = 0; m < 3; ++m )
            *((_BYTE *)p_big_values + m + 11) = mad_bit_read(bitptr: ptr, len: 3u);
        }
        else
        {
          *((_BYTE *)p_big_values + 7) = 0;
          for ( n = 0; n < 3; ++n )
            *((_BYTE *)p_big_values + n + 8) = mad_bit_read(bitptr: ptr, len: 5u);
          *((_BYTE *)p_big_values + 14) = mad_bit_read(bitptr: ptr, len: 4u);
          *((_BYTE *)p_big_values + 15) = mad_bit_read(bitptr: ptr, len: 3u);
        }
        *((_BYTE *)p_big_values + 6) |= mad_bit_read(bitptr: ptr, len: 3 - (lsf != 0));
        p_big_values += 29;
        if ( ++ngr >= nch )
          break;
      }
    }
    p_big_values = v22 + 58;
    v19 = v21-- == 1;
    v22 += 58;
  }
  while ( !v19 );
  return v24;
}

//------------------------------------------------------------------------------
// Address: 0x0051CF40
// Name: III_scalefactors_lsf
// Source: json
//------------------------------------------------------------------------------
int __cdecl III_scalefactors_lsf(mad_bitptr *ptr, channel *channel, channel *gr1ch, char mode_extension)
{
  int v4; // edx
  bool v5; // zf
  unsigned int scalefac_compress; // ecx
  int v7; // ebx
  unsigned int v8; // esi
  unsigned int v9; // ecx
  unsigned int v10; // ecx
  const unsigned __int8 *v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // edi
  int v16; // ebx
  unsigned __int8 *v17; // esi
  int v18; // eax
  unsigned int v19; // ecx
  unsigned __int8 *v20; // eax
  unsigned int v21; // ecx
  const unsigned __int8 *v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // ecx
  unsigned int v25; // ebx
  unsigned int i; // edi
  unsigned int slen[4]; // [esp+Ch] [ebp-28h]
  mad_bitptr start; // [esp+1Ch] [ebp-18h] BYREF
  int v30; // [esp+24h] [ebp-10h]
  unsigned int v31; // [esp+28h] [ebp-Ch]
  unsigned int part; // [esp+2Ch] [ebp-8h]
  unsigned int n; // [esp+30h] [ebp-4h]
  const unsigned __int8 *nsfb; // [esp+48h] [ebp+14h]
  const unsigned __int8 *nsfba; // [esp+48h] [ebp+14h]

  v4 = *(_DWORD *)&ptr->cache;
  v5 = channel->block_type == 2;
  start.byte = ptr->byte;
  scalefac_compress = channel->scalefac_compress;
  *(_DWORD *)&start.cache = v4;
  if ( v5 )
  {
    v7 = ((channel->flags & 8) != 0) + 1;
    v8 = 0;
  }
  else
  {
    v8 = 0;
    v7 = 0;
  }
  if ( (mode_extension & 1) != 0 && gr1ch != nullptr )
  {
    v9 = scalefac_compress >> 1;
    if ( v9 >= 0xB4 )
    {
      if ( v9 >= 0xF4 )
      {
        v12 = v9 - 244;
        slen[0] = v12 / 3;
        slen[1] = v12 % 3;
        slen[2] = 0;
        v11 = nsfb_table[5][v7];
      }
      else
      {
        v10 = v9 - 180;
        slen[0] = (v10 >> 4) & 3;
        slen[1] = (v10 >> 2) & 3;
        slen[2] = v10 & 3;
        v11 = nsfb_table[4][v7];
      }
      nsfb = v11;
    }
    else
    {
      slen[0] = v9 / 0x24;
      slen[2] = v9 % 0x24 % 6;
      slen[1] = v9 % 0x24 / 6;
      nsfb = nsfb_table[3][v7];
    }
    v13 = 0;
    slen[3] = 0;
    n = 0;
    part = 0;
    do
    {
      v15 = 0;
      v31 = slen[v13];
      v14 = v31;
      v16 = (1 << v31) - 1;
      if ( nsfb[v13] != 0 )
      {
        v17 = &gr1ch->scalefac[v8];
        v30 = (char *)channel - (char *)gr1ch;
        while ( 1 )
        {
          v18 = mad_bit_read(bitptr: ptr, len: v14);
          v19 = part;
          v17[v30] = v18;
          ++n;
          *v17 = v18 == v16;
          ++v15;
          ++v17;
          if ( v15 >= nsfb[v19] )
            break;
          v14 = v31;
        }
        v8 = n;
        v13 = v19;
      }
      part = ++v13;
    }
    while ( v13 < 4 );
    if ( v8 < 0x27 )
    {
      v20 = &gr1ch->scalefac[v8];
      v21 = 39 - v8;
      do
      {
        v20[(char *)channel - (char *)gr1ch] = 0;
        *v20++ = 0;
        --v21;
      }
      while ( v21 != 0 );
    }
    return mad_bit_length(begin: &start, end: ptr);
  }
  if ( scalefac_compress >= 0x190 )
  {
    slen[3] = 0;
    if ( scalefac_compress < 0x1F4 )
    {
      v23 = scalefac_compress - 400;
      slen[2] = v23 & 3;
      nsfba = nsfb_table[1][v7];
      slen[0] = v23 / 0x14;
      slen[1] = (v23 >> 2) % 5;
      goto LABEL_29;
    }
    v24 = scalefac_compress - 500;
    slen[0] = v24 / 3;
    channel->flags |= 4u;
    slen[1] = v24 % 3;
    slen[2] = 0;
    v22 = nsfb_table[2][v7];
  }
  else
  {
    slen[1] = (scalefac_compress >> 4) % 5;
    slen[0] = scalefac_compress / 0x50;
    slen[2] = (scalefac_compress >> 2) & 3;
    slen[3] = scalefac_compress & 3;
    v22 = nsfb_table[0][v7];
  }
  nsfba = v22;
LABEL_29:
  v25 = 0;
  do
  {
    for ( i = 0; i < nsfba[v8]; ++v25 )
    {
      channel->scalefac[v25] = mad_bit_read(bitptr: ptr, len: slen[v8]);
      ++i;
    }
    ++v8;
  }
  while ( v8 < 4 );
  if ( v25 < 0x27 )
    memset(dst: &channel->scalefac[v25], value: 0, count: 39 - v25);
  return mad_bit_length(begin: &start, end: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x0051D1F0
// Name: III_scalefactors
// Source: json
//------------------------------------------------------------------------------
int __usercall III_scalefactors@<eax>(mad_bitptr *ptr@<edi>, channel *channel@<esi>, const channel *gr0ch, char scfsi)
{
  int v4; // ecx
  int scalefac_compress; // eax
  unsigned int v6; // edx
  bool v7; // zf
  unsigned int v8; // eax
  int v9; // ebx
  unsigned int v10; // eax
  const channel *v12; // eax
  unsigned int i; // ebx
  unsigned int j; // ebx
  unsigned int k; // ebx
  unsigned int m; // ebx
  mad_bitptr start; // [esp+4h] [ebp-14h] BYREF
  unsigned int slen2; // [esp+Ch] [ebp-Ch]
  unsigned int slen1; // [esp+10h] [ebp-8h]
  unsigned int nsfb; // [esp+14h] [ebp-4h]

  v4 = *(_DWORD *)&ptr->cache;
  start.byte = ptr->byte;
  scalefac_compress = channel->scalefac_compress;
  v6 = sflen_table[scalefac_compress].slen1;
  v7 = channel->block_type == 2;
  v8 = sflen_table[scalefac_compress].slen2;
  *(_DWORD *)&start.cache = v4;
  slen1 = v6;
  slen2 = v8;
  if ( v7 )
  {
    v9 = 0;
    v10 = 18 - ((channel->flags & 8) != 0);
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        nsfb = v10 - 1;
        channel->scalefac[v9++] = mad_bit_read(bitptr: ptr, len: slen1);
        if ( nsfb == 0 )
          break;
        v10 = nsfb;
      }
    }
    nsfb = 18;
    do
    {
      --nsfb;
      channel->scalefac[v9++] = mad_bit_read(bitptr: ptr, len: slen2);
    }
    while ( nsfb != 0 );
    *(_WORD *)&channel->scalefac[v9] = 0;
    channel->scalefac[v9 + 2] = 0;
    return mad_bit_length(begin: &start, end: ptr);
  }
  else
  {
    if ( (scfsi & 8) != 0 )
    {
      v12 = gr0ch;
      channel->scalefac[0] = gr0ch->scalefac[0];
      channel->scalefac[1] = gr0ch->scalefac[1];
      channel->scalefac[2] = gr0ch->scalefac[2];
      channel->scalefac[3] = gr0ch->scalefac[3];
      channel->scalefac[4] = gr0ch->scalefac[4];
      channel->scalefac[5] = gr0ch->scalefac[5];
    }
    else
    {
      for ( i = 0; i < 6; ++i )
        channel->scalefac[i] = mad_bit_read(bitptr: ptr, len: slen1);
      v12 = gr0ch;
    }
    if ( (scfsi & 4) != 0 )
    {
      channel->scalefac[6] = v12->scalefac[6];
      channel->scalefac[7] = v12->scalefac[7];
      channel->scalefac[8] = v12->scalefac[8];
      channel->scalefac[9] = v12->scalefac[9];
      channel->scalefac[10] = v12->scalefac[10];
    }
    else
    {
      for ( j = 6; j < 0xB; ++j )
        channel->scalefac[j] = mad_bit_read(bitptr: ptr, len: slen1);
      v12 = gr0ch;
    }
    if ( (scfsi & 2) != 0 )
    {
      channel->scalefac[11] = v12->scalefac[11];
      channel->scalefac[12] = v12->scalefac[12];
      channel->scalefac[13] = v12->scalefac[13];
      channel->scalefac[14] = v12->scalefac[14];
      channel->scalefac[15] = v12->scalefac[15];
    }
    else
    {
      for ( k = 11; k < 0x10; ++k )
        channel->scalefac[k] = mad_bit_read(bitptr: ptr, len: slen2);
      v12 = gr0ch;
    }
    if ( (scfsi & 1) != 0 )
    {
      channel->scalefac[16] = v12->scalefac[16];
      channel->scalefac[17] = v12->scalefac[17];
      channel->scalefac[18] = v12->scalefac[18];
      channel->scalefac[19] = v12->scalefac[19];
      channel->scalefac[20] = v12->scalefac[20];
    }
    else
    {
      for ( m = 16; m < 0x15; ++m )
        channel->scalefac[m] = mad_bit_read(bitptr: ptr, len: slen2);
    }
    channel->scalefac[21] = 0;
    return mad_bit_length(begin: &start, end: ptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051D3F0
// Name: III_exponents
// Source: json
//------------------------------------------------------------------------------
void __cdecl III_exponents(const channel *channel, const unsigned __int8 *sfbwidth, int *exponents)
{
  const channel *v3; // ebx
  unsigned __int8 flags; // dl
  int v5; // esi
  char v6; // cl
  unsigned int v7; // eax
  int v8; // edi
  const unsigned __int8 *v9; // edx
  int v10; // ebx
  int v11; // edx
  unsigned __int8 *v13; // edx
  int *v14; // edi
  int v15; // esi
  const unsigned __int8 *v16; // edx
  unsigned __int8 *v17; // eax
  int v18; // edi
  bool v19; // zf
  unsigned int i; // eax
  int v21; // edx
  unsigned int premask; // [esp+Ch] [ebp-Ch]
  unsigned int premaska; // [esp+Ch] [ebp-Ch]
  int gain1; // [esp+10h] [ebp-8h]
  const unsigned __int8 *gain2; // [esp+14h] [ebp-4h]
  int gain2a; // [esp+14h] [ebp-4h]
  int gain2b; // [esp+14h] [ebp-4h]
  const channel *channela; // [esp+20h] [ebp+8h]
  channel *channelb; // [esp+20h] [ebp+8h]

  v3 = channel;
  flags = channel->flags;
  v5 = channel->global_gain - 210;
  v6 = ((flags & 2) != 0) + 1;
  if ( channel->block_type == 2 )
  {
    v7 = 0;
    v8 = 0;
    if ( (flags & 8) != 0 )
    {
      premask = -((flags & 4) != 0);
      v9 = sfbwidth;
      v10 = pretab - sfbwidth;
      gain2 = sfbwidth;
      while ( 1 )
      {
        v11 = (channel->scalefac[v8++] + (premask & v9[v10])) << v6;
        exponents[v8 - 1] = v5 - v11;
        v7 += *gain2;
        v9 = ++gain2;
        if ( v7 >= 0x24 )
          break;
        v10 = pretab - sfbwidth;
      }
      v3 = channel;
    }
    premaska = v5 - 8 * v3->subblock_gain[0];
    gain1 = v5 - 8 * channel->subblock_gain[1];
    gain2a = v5 - 8 * channel->subblock_gain[2];
    if ( v7 < 0x240 )
    {
      channela = (const channel *)&sfbwidth[v8];
      v13 = &channel->scalefac[v8 + 1];
      v14 = &exponents[v8 + 2];
      do
      {
        v15 = *(v13 - 1) << v6;
        v13 += 3;
        v14 += 3;
        *(v14 - 5) = premaska - v15;
        *(v14 - 4) = gain1 - (*(v13 - 3) << v6);
        *(v14 - 3) = gain2a - (*(v13 - 2) << v6);
        v7 += LOBYTE(channela->part2_3_length) + 2 * LOBYTE(channela->part2_3_length);
        channela = (const channel *)((char *)channela + 3);
      }
      while ( v7 < 0x240 );
    }
  }
  else if ( (flags & 4) != 0 )
  {
    v16 = &pretab[1];
    v17 = &channel->scalefac[1];
    channelb = (channel *)exponents;
    gain2b = 11;
    do
    {
      v18 = (*(v16 - 1) + *(v17 - 1)) << v6;
      v17 += 2;
      v16 += 2;
      *(_DWORD *)&channelb->part2_3_length = v5 - v18;
      *(_DWORD *)&channelb->global_gain = v5 - ((*(v16 - 2) + *(v17 - 2)) << v6);
      v19 = gain2b-- == 1;
      channelb = (channel *)((char *)channelb + 8);
    }
    while ( !v19 );
  }
  else
  {
    for ( i = 0; i < 0x16; exponents[i - 1] = v5 - v21 )
      v21 = channel->scalefac[i++] << v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051D5C0
// Name: III_requantize
// Source: json
//------------------------------------------------------------------------------
int __usercall III_requantize@<eax>(unsigned int value@<ecx>, int exp@<eax>)
{
  int v2; // ebx
  int v3; // edi
  int v4; // esi
  int v5; // edi

  v2 = exp % 4;
  v3 = *(_DWORD *)&rq_table[value] & 0x7FFFFFF;
  v4 = exp / 4 + (*((_WORD *)&rq_table[value] + 2) & 0x1F);
  if ( v4 >= 0 )
  {
    if ( v4 < 5 )
      v5 = v3 << v4;
    else
      v5 = 0x7FFFFFFF;
  }
  else if ( (unsigned int)-v4 < 0x20 )
  {
    v5 = ((1 << (-1 - v4)) + v3) >> -(char)v4;
  }
  else
  {
    v5 = 0;
  }
  if ( v2 != 0 )
    return (unsigned __int64)(root_table[v2 + 3] * (__int64)v5) >> 28;
  else
    return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0051D660
// Name: III_huffdecode
// Source: json
//------------------------------------------------------------------------------
int __usercall III_huffdecode@<eax>(
        mad_bitptr *ptr@<eax>,
        int *xr,
        channel *channel,
        const unsigned __int8 *sfbwidth,
        unsigned int part2_length)
{
  channel *v5; // edi
  int v8; // ebx
  int v9; // eax
  signed int v10; // esi
  int v11; // ecx
  int v12; // eax
  int *v13; // ebx
  unsigned int v14; // edx
  const hufftable *v15; // eax
  const huffpair *v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // eax
  int v19; // edi
  bool v20; // zf
  unsigned int v21; // eax
  int v22; // eax
  const huffpair *v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // eax
  unsigned int v26; // edi
  int v27; // eax
  signed int v28; // edi
  const huffpair *v29; // ebx
  huffpair v30; // ax
  unsigned int v31; // edx
  int v32; // eax
  int v33; // ebx
  unsigned int v34; // ecx
  int v35; // eax
  unsigned int v36; // edi
  int v37; // eax
  int v38; // eax
  unsigned int v39; // edi
  int *v40; // edx
  unsigned int v41; // ebx
  int v42; // eax
  int v43; // eax
  unsigned int v44; // edi
  int v45; // eax
  int v46; // edi
  int v47; // eax
  unsigned int v48; // ebx
  int v49; // ebx
  int v50; // eax
  int v51; // eax
  char *v52; // edi
  unsigned int v53; // eax
  const int *v54; // edx
  int v55; // ecx
  int v56; // eax
  int v57; // eax
  int v58; // eax
  int v59; // eax
  int *v60; // ebx
  int v61; // ecx
  int v62; // eax
  int v63; // edx
  int v64; // eax
  int v65; // eax
  int v66; // edx
  int exponents[39]; // [esp+8h] [ebp-118h] BYREF
  int reqcache[16]; // [esp+A4h] [ebp-7Ch]
  unsigned int region; // [esp+E4h] [ebp-3Ch]
  const huffpair *table; // [esp+E8h] [ebp-38h]
  mad_bitptr peek; // [esp+ECh] [ebp-34h] BYREF
  unsigned int big_values; // [esp+F4h] [ebp-2Ch]
  unsigned int rcount; // [esp+F8h] [ebp-28h]
  unsigned int startbits; // [esp+FCh] [ebp-24h]
  unsigned int linbits; // [esp+104h] [ebp-1Ch]
  const int *sfbound; // [esp+108h] [ebp-18h]
  const int *expptr; // [esp+10Ch] [ebp-14h]
  int *xrptr; // [esp+110h] [ebp-10h]
  int exp; // [esp+114h] [ebp-Ch]
  unsigned int reqhits; // [esp+118h] [ebp-8h]
  int bits_left; // [esp+11Ch] [ebp-4h]
  int requantized; // [esp+12Ch] [ebp+Ch]
  const unsigned __int8 *sfbwidtha; // [esp+130h] [ebp+10h]
  unsigned int bitcache; // [esp+134h] [ebp+14h]

  v5 = channel;
  bits_left = channel->part2_3_length - part2_length;
  if ( bits_left < 0 )
    return 566;
  III_exponents(channel, sfbwidth, exponents);
  v8 = bits_left;
  v9 = *(_DWORD *)&ptr->cache;
  peek.byte = ptr->byte;
  *(_DWORD *)&peek.cache = v9;
  mad_bit_skip(bitptr: ptr, len: bits_left);
  v10 = ((31 - peek.left) & 0xFFFFFFF8) + peek.left;
  bitcache = mad_bit_read(bitptr: &peek, len: v10);
  v11 = *sfbwidth;
  sfbwidtha = sfbwidth + 1;
  rcount = channel->region0_count + 1;
  v12 = channel->table_select[0];
  bits_left = v8 - v10;
  v13 = xr;
  v14 = (unsigned __int16)word_5CD24C[4 * v12];
  v15 = &mad_huff_pair_table[v12];
  sfbound = &xr[v11];
  v16 = v15->table;
  v17 = v15->startbits;
  xrptr = xr;
  region = 0;
  table = v16;
  linbits = v14;
  startbits = v17;
  if ( v16 == nullptr )
    return 567;
  v18 = channel->big_values;
  exp = exponents[0];
  expptr = &exponents[1];
  reqhits = 0;
  big_values = v18;
  if ( v18 != 0 )
  {
    while ( 1 )
    {
      --big_values;
      if ( v10 + bits_left <= 0 )
      {
LABEL_63:
        v5 = channel;
        v13 = xrptr;
        break;
      }
      if ( xrptr == sfbound )
      {
        v19 = *sfbwidtha;
        v20 = rcount-- == 1;
        sfbound += v19;
        ++sfbwidtha;
        if ( v20 )
        {
          v21 = region;
          rcount = region++ != 0 ? 0 : channel->region1_count + 1;
          v22 = channel->table_select[v21 + 1];
          v23 = mad_huff_pair_table[v22].table;
          v24 = (unsigned __int16)word_5CD24C[4 * v22];
          v25 = mad_huff_pair_table[v22].startbits;
          table = v23;
          linbits = v24;
          startbits = v25;
          if ( v23 == nullptr )
            return 567;
        }
        if ( exp != *expptr )
        {
          exp = *expptr;
          reqhits = 0;
        }
        ++expptr;
      }
      if ( v10 < 21 )
      {
        v26 = (31 - v10) & 0xFFFFFFF8;
        v27 = mad_bit_read(bitptr: &peek, len: v26);
        v10 += v26;
        bits_left -= v26;
        bitcache = (bitcache << v26) | v27;
      }
      v28 = v10 - startbits;
      v29 = &table[((1 << startbits) - 1) & (bitcache >> (v10 - startbits))];
      for ( v30.ptr = v29->ptr; (*(_BYTE *)&v30.ptr & 1) == 0; v29 = &table[v33] )
      {
        v31 = (unsigned __int16)v30.ptr;
        v32 = (*(_WORD *)&v30.ptr >> 1) & 7;
        v10 = v28;
        v28 -= v32;
        v33 = (v31 >> 4) + (((1 << v32) - 1) & (bitcache >> v28));
        v30.ptr = ($780F973CBC0CEA06E19480612A63D150)table[v33];
      }
      v34 = linbits;
      v10 -= (*(_WORD *)&v29->ptr >> 1) & 7;
      if ( linbits != 0 )
      {
        v35 = (*(_WORD *)&v29->ptr >> 4) & 0xF;
        v36 = v35;
        if ( v35 != 0 )
        {
          if ( v35 == 15 )
          {
            if ( v10 >= linbits + 2 )
            {
              v39 = bitcache;
            }
            else
            {
              v39 = mad_bit_read(bitptr: &peek, len: 0x10u) | (bitcache << 16);
              v10 += 16;
              bits_left -= 16;
              bitcache = v39;
            }
            v10 -= linbits;
            v38 = III_requantize(value: ((v39 >> v10) & ((1 << linbits) - 1)) + 15, exp);
          }
          else
          {
            v37 = 1 << v35;
            if ( ((1 << v36) & reqhits) != 0 )
            {
              v38 = reqcache[v36];
            }
            else
            {
              reqhits |= v37;
              v38 = III_requantize(value: v36, exp);
              reqcache[v36] = v38;
            }
            v39 = bitcache;
          }
          if ( ((1 << --v10) & v39) != 0 )
            v38 = -v38;
          v40 = xrptr;
          v34 = linbits;
          *xrptr = v38;
        }
        else
        {
          v40 = xrptr;
          v39 = bitcache;
          *xrptr = 0;
        }
        v41 = HIBYTE(*(_WORD *)&v29->ptr) & 0xF;
        if ( v41 != 0 )
        {
          if ( v41 == 15 )
          {
            if ( v10 < v34 + 1 )
            {
              v39 = mad_bit_read(bitptr: &peek, len: 0x10u) | (v39 << 16);
              v10 += 16;
              bits_left -= 16;
              bitcache = v39;
            }
            v10 -= linbits;
            v42 = III_requantize(value: ((v39 >> v10) & ((1 << linbits) - 1)) + 15, exp);
          }
          else
          {
            if ( ((1 << v41) & reqhits) != 0 )
            {
              v42 = reqcache[v41];
y_final:
              if ( ((1 << --v10) & v39) != 0 )
                v42 = -v42;
              v40[1] = v42;
              goto LABEL_62;
            }
            reqhits |= 1 << v41;
            v42 = III_requantize(value: v41, exp);
            reqcache[v41] = v42;
          }
          v40 = xrptr;
          goto y_final;
        }
      }
      else
      {
        v43 = (*(_WORD *)&v29->ptr >> 4) & 0xF;
        v44 = v43;
        if ( v43 != 0 )
        {
          v45 = 1 << v43;
          if ( ((1 << v44) & reqhits) != 0 )
          {
            v46 = reqcache[v44];
          }
          else
          {
            reqhits |= v45;
            v47 = III_requantize(value: v44, exp);
            reqcache[v44] = v47;
            v46 = v47;
          }
          if ( ((1 << --v10) & bitcache) != 0 )
            v46 = -v46;
          v40 = xrptr;
          *xrptr = v46;
        }
        else
        {
          v40 = xrptr;
          *xrptr = 0;
        }
        v48 = HIBYTE(*(_WORD *)&v29->ptr) & 0xF;
        if ( v48 != 0 )
        {
          if ( ((1 << v48) & reqhits) != 0 )
          {
            v49 = reqcache[v48];
          }
          else
          {
            reqhits |= 1 << v48;
            v50 = III_requantize(value: v48, exp);
            v40 = xrptr;
            reqcache[v48] = v50;
            v49 = v50;
          }
          if ( ((1 << --v10) & bitcache) != 0 )
            v49 = -v49;
          v40[1] = v49;
          goto LABEL_62;
        }
      }
      v40[1] = 0;
LABEL_62:
      xrptr = v40 + 2;
      if ( big_values == 0 )
        goto LABEL_63;
    }
  }
  if ( v10 + bits_left < 0 )
    return 568;
  startbits = (unsigned int)mad_huff_quad_table[v5->flags & 1];
  requantized = III_requantize(value: 1u, exp);
  if ( v10 + bits_left > 0 )
  {
    do
    {
      if ( v13 > xr + 572 )
        break;
      if ( v10 < 10 )
      {
        v51 = mad_bit_read(bitptr: &peek, len: 0x10u);
        v10 += 16;
        bits_left -= 16;
        bitcache = (bitcache << 16) | v51;
      }
      v52 = (char *)(startbits + 2 * ((bitcache >> (v10 - 4)) & 0xF));
      v53 = *(unsigned __int16 *)v52;
      if ( (v53 & 1) == 0 )
      {
        v10 -= 4;
        v52 = (char *)(startbits
                     + 2
                     * ((*(unsigned __int16 *)v52 >> 4)
                      + (((1 << ((v53 >> 1) & 7)) - 1) & (bitcache >> (v10 - ((v53 >> 1) & 7))))));
      }
      v10 -= (*(unsigned __int16 *)v52 >> 1) & 7;
      v54 = sfbound;
      if ( v13 == sfbound )
      {
        v55 = *sfbwidtha++;
        v56 = *expptr;
        v54 = &sfbound[v55];
        sfbound = v54;
        if ( exp != v56 )
        {
          exp = v56;
          v57 = III_requantize(value: 1u, exp: v56);
          v54 = sfbound;
          requantized = v57;
        }
        ++expptr;
      }
      if ( (*v52 & 0x10) != 0 )
      {
        --v10;
        v58 = requantized;
        if ( ((1 << v10) & bitcache) != 0 )
          v58 = -requantized;
      }
      else
      {
        v58 = 0;
      }
      *v13 = v58;
      if ( (*v52 & 0x20) != 0 )
      {
        --v10;
        v59 = requantized;
        if ( ((1 << v10) & bitcache) != 0 )
          v59 = -requantized;
      }
      else
      {
        v59 = 0;
      }
      v13[1] = v59;
      v60 = v13 + 2;
      if ( v60 == v54 )
      {
        v61 = *sfbwidtha++;
        v62 = *expptr;
        sfbound = &v54[v61];
        if ( exp != v62 )
        {
          exp = v62;
          requantized = III_requantize(value: 1u, exp: v62);
        }
        ++expptr;
      }
      if ( (*v52 & 0x40) != 0 )
      {
        --v10;
        v63 = requantized;
        v64 = requantized;
        if ( ((1 << v10) & bitcache) != 0 )
          v64 = -requantized;
      }
      else
      {
        v63 = requantized;
        v64 = 0;
      }
      *v60 = v64;
      if ( *v52 >= 0 )
      {
        v65 = 0;
      }
      else
      {
        --v10;
        v65 = v63;
        if ( ((1 << v10) & bitcache) != 0 )
          v65 = -v63;
      }
      v66 = bits_left;
      v60[1] = v65;
      v13 = v60 + 2;
    }
    while ( v10 + v66 > 0 );
  }
  if ( bits_left + v10 < 0 )
    v13 -= 4;
  for ( ; v13 < xr + 576; v13 += 2 )
  {
    *v13 = 0;
    v13[1] = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0051DCA0
// Name: III_reorder
// Source: json
//------------------------------------------------------------------------------
void __cdecl III_reorder(int *xr, const channel *channel, const unsigned __int8 *sfbwidth)
{
  unsigned int v4; // eax
  unsigned int v5; // edx
  bool v6; // zf
  unsigned int i; // esi
  unsigned int v8; // esi
  const unsigned __int8 *v9; // ecx
  int v10; // edi
  unsigned int v11; // ecx
  unsigned int v12; // esi
  unsigned int v13; // eax
  int tmp[32][3][6]; // [esp+8h] [ebp-91Ch] BYREF
  unsigned int sbw[3]; // [esp+908h] [ebp-1Ch]
  unsigned int sw[3]; // [esp+914h] [ebp-10h] BYREF
  unsigned int sb; // [esp+920h] [ebp-4h]
  unsigned int f; // [esp+930h] [ebp+Ch]
  const unsigned __int8 *sfbwidtha; // [esp+934h] [ebp+10h]

  v4 = 0;
  v5 = 0;
  v6 = (channel->flags & 8) == 0;
  sb = 0;
  if ( !v6 )
  {
    v4 = 2;
    sb = 2;
    for ( i = 0; i < 0x24; i += *sfbwidth++ )
      ;
  }
  v8 = *sfbwidth;
  v9 = sfbwidth + 1;
  v10 = 18 * v4;
  sbw[0] = v4;
  memset(sw, 0, sizeof(sw));
  sbw[1] = v4;
  sbw[2] = v4;
  sfbwidtha = v9;
  if ( 18 * v4 < 0x240 )
  {
    while ( 1 )
    {
      f = v8 - 1;
      if ( v8 == 0 )
      {
        f = *v9 - 1;
        sfbwidtha = v9 + 1;
        v5 = (v5 + 1) % 3;
      }
      v11 = sbw[v5];
      v12 = sw[v5];
      v13 = v12 + 6 * (v11 + v5 + 2 * v11);
      ++v12;
      tmp[0][0][v13] = xr[v10];
      sw[v5] = v12;
      if ( v12 == 6 )
      {
        sw[v5] = 0;
        sbw[v5] = v11 + 1;
      }
      if ( (unsigned int)++v10 >= 0x240 )
        break;
      v8 = f;
      v9 = sfbwidtha;
    }
    v4 = sb;
  }
  memcpy(dst: (unsigned __int8 *)&xr[18 * v4], src: (unsigned __int8 *)tmp[v4], count: 72 * (32 - v4));
}

//------------------------------------------------------------------------------
// Address: 0x0051DDA0
// Name: III_stereo
// Source: json
//------------------------------------------------------------------------------
int __cdecl III_stereo(int (*xr)[576], const granule *granule, mad_header *header, const unsigned __int8 *sfbwidth)
{
  mad_header *v4; // edx
  int v5; // eax
  bool v6; // zf
  int *v7; // edi
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // eax
  int v14; // esi
  __int16 v15; // ax
  char v16; // cf
  unsigned int v17; // ecx
  __int16 *v18; // edi
  int i; // ecx
  unsigned int v20; // ecx
  unsigned int j; // edx
  unsigned int v22; // esi
  unsigned int v23; // edx
  int v24; // eax
  __int16 v25; // ax
  unsigned int v26; // ecx
  __int16 *v27; // edi
  int k; // ecx
  const granule *v29; // ebx
  unsigned int v30; // edx
  int v31; // eax
  unsigned __int8 *scalefac; // esi
  unsigned int v33; // edi
  __int16 v34; // ax
  int v35; // ebx
  int *v36; // ecx
  int v37; // esi
  int v38; // eax
  unsigned int v39; // ebx
  unsigned int v40; // eax
  unsigned int v41; // edx
  int v42; // ecx
  unsigned int v43; // ecx
  unsigned int v44; // esi
  int *v45; // ecx
  unsigned int n; // ebx
  int v47; // eax
  unsigned int v48; // eax
  unsigned int part2_3_length_low; // edx
  int *v50; // ecx
  unsigned int ii; // ebx
  int v52; // esi
  int v53; // edi
  __int16 modes[40]; // [esp+4h] [ebp-7Ch] BYREF
  unsigned int bound[3]; // [esp+54h] [ebp-2Ch] BYREF
  int left; // [esp+60h] [ebp-20h]
  int v58; // [esp+64h] [ebp-1Ch]
  const int *lsf_scale; // [esp+68h] [ebp-18h]
  int m; // [esp+6Ch] [ebp-14h]
  int invsqrt2; // [esp+70h] [ebp-10h]
  unsigned int start; // [esp+74h] [ebp-Ch]
  unsigned int max; // [esp+78h] [ebp-8h]
  unsigned int lower; // [esp+7Ch] [ebp-4h]
  const granule *granulea; // [esp+8Ch] [ebp+Ch]

  if ( granule->ch[0].block_type != granule->ch[1].block_type
    || ((granule->ch[0].flags ^ granule->ch[1].flags) & 8) != 0 )
  {
    return 569;
  }
  v4 = header;
  v5 = (LOWORD(header->mode_extension) << 16) | LOWORD(header->mode_extension);
  v6 = (header->mode_extension & 1) == 0;
  memset32(modes, v5, 0x13u);
  modes[38] = v5;
  if ( !v6 )
  {
    header->flags |= 0x100u;
    v7 = &(*xr)[576];
    v8 = 0;
    v9 = 0;
    if ( granule->ch[1].block_type == 2 )
    {
      v6 = (granule->ch[1].flags & 8) == 0;
      memset(bound, 0, sizeof(bound));
      max = 0;
      start = 0;
      lower = 0;
      if ( !v6 )
      {
        do
        {
          v10 = sfbwidth[v8++];
          v11 = 0;
          if ( v10 != 0 )
          {
            while ( v7[v11] == 0 )
            {
              if ( ++v11 >= v10 )
                goto LABEL_11;
            }
            lower = v8;
          }
LABEL_11:
          v9 += v10;
          v7 += v10;
        }
        while ( v9 < 0x24 );
        start = v8;
      }
      v12 = 0;
      if ( v9 < 0x240 )
      {
        do
        {
          v13 = sfbwidth[v8++];
          v14 = 0;
          if ( v13 != 0 )
          {
            while ( v7[v14] == 0 )
            {
              if ( ++v14 >= v13 )
                goto LABEL_19;
            }
            bound[v12] = v8;
            max = v8;
          }
LABEL_19:
          v9 += v13;
          v7 += v13;
          v12 = (v12 + 1) % 3;
        }
        while ( v9 < 0x240 );
        if ( max != 0 )
          lower = start;
      }
      if ( lower != 0 )
      {
        v15 = header->mode_extension & 0xFFFE;
        v16 = lower & 1;
        v17 = lower >> 1;
        memset32(modes, __PAIR32__(header->mode_extension, header->mode_extension) & 0xFFFEFFFE, lower >> 1);
        v18 = &modes[2 * v17];
        for ( i = v16; i != 0; --i )
          *v18++ = v15;
      }
      v20 = start;
      for ( j = 0; v20 < max; j = (j + 1) % 3 )
      {
        if ( v20 < bound[j] )
          modes[v20] = header->mode_extension & 0xFFFE;
        ++v20;
      }
    }
    else
    {
      v22 = 0;
      do
      {
        v23 = sfbwidth[v22++];
        v24 = 0;
        if ( v23 != 0 )
        {
          while ( v7[v24] == 0 )
          {
            if ( ++v24 >= v23 )
              goto LABEL_37;
          }
          v8 = v22;
        }
LABEL_37:
        v9 += v23;
        v7 += v23;
      }
      while ( v9 < 0x240 );
      if ( v8 != 0 )
      {
        v25 = header->mode_extension & 0xFFFE;
        v16 = v8 & 1;
        v26 = v8 >> 1;
        memset32(modes, __PAIR32__(header->mode_extension, header->mode_extension) & 0xFFFEFFFE, v26);
        v27 = &modes[2 * v26];
        for ( k = v16; k != 0; --k )
          *v27++ = v25;
      }
    }
    if ( (header->flags & 0x1000) != 0 )
    {
      v29 = granule;
      lsf_scale = is_lsf_table[granule->ch[1].scalefac_compress & 1];
      v30 = 0;
      v31 = sfbwidth - granule[1].ch[1].scalefac;
      lower = 0;
      max = 0;
      scalefac = granule[1].ch[1].scalefac;
      invsqrt2 = (int)granule[1].ch[1].scalefac;
      for ( m = v31; ; v31 = m )
      {
        v33 = scalefac[v31];
        v34 = modes[v30];
        if ( (v34 & 1) != 0 )
        {
          if ( *scalefac != 0 )
          {
            modes[v30] = v34 & 0xFFFE;
          }
          else
          {
            v35 = v29->ch[1].scalefac[v30];
            if ( v33 != 0 )
            {
              v36 = &(*xr)[lower + 576];
              for ( start = v33; start != 0; --start )
              {
                v37 = *(v36 - 576);
                left = v37;
                if ( v35 != 0 )
                {
                  v58 = lsf_scale[(unsigned int)(v35 - 1) >> 1];
                  v38 = (unsigned __int64)(v58 * (__int64)left) >> 28;
                  if ( (v35 & 1) != 0 )
                  {
                    *(v36 - 576) = v38;
                    *v36 = v37;
                  }
                  else
                  {
                    *v36 = v38;
                  }
                }
                else
                {
                  *v36 = v37;
                }
                ++v36;
              }
              v30 = max;
              scalefac = (unsigned __int8 *)invsqrt2;
            }
          }
        }
        ++v30;
        ++scalefac;
        max = v30;
        invsqrt2 = (int)scalefac;
        lower += v33;
        if ( lower >= 0x240 )
          break;
        v29 = granule;
      }
    }
    else
    {
      v39 = 0;
      v40 = 0;
      lower = 0;
      max = 0;
      do
      {
        v41 = sfbwidth[v40];
        v42 = (unsigned __int16)modes[v40];
        start = v41;
        left = v42;
        if ( (v42 & 1) != 0 )
        {
          v43 = granule->ch[1].scalefac[v40];
          if ( v43 < 7 )
          {
            if ( v41 != 0 )
            {
              v44 = 4 * v43;
              v45 = &(*xr)[v39];
              for ( n = v41; n != 0; --n )
              {
                v47 = is_table[v44 / 4];
                invsqrt2 = *v45;
                left = v47;
                *v45 = (unsigned __int64)(v47 * (__int64)invsqrt2) >> 28;
                left = is_table[v44 / 0xFFFFFFFC + 6];
                v45[576] = (unsigned __int64)(left * (__int64)invsqrt2) >> 28;
                ++v45;
              }
              v40 = max;
              v39 = lower;
              v41 = start;
            }
          }
          else
          {
            modes[v40] = left & 0xFFFE;
          }
        }
        v39 += v41;
        max = ++v40;
        lower = v39;
      }
      while ( v39 < 0x240 );
    }
    v4 = header;
  }
  if ( (v4->mode_extension & 2) != 0 )
  {
    v4->flags |= 0x200u;
    v48 = 0;
    invsqrt2 = 189812531;
    lower = 0;
    granulea = (const granule *)sfbwidth;
    max = (unsigned int)modes;
    do
    {
      part2_3_length_low = LOBYTE(granulea->ch[0].part2_3_length);
      v6 = *(_WORD *)max == 2;
      start = part2_3_length_low;
      if ( v6 && part2_3_length_low != 0 )
      {
        v50 = &(*xr)[v48 + 576];
        for ( ii = part2_3_length_low; ii != 0; --ii )
        {
          v52 = *(v50 - 576);
          v53 = *v50;
          left = *v50 + v52;
          *(v50 - 576) = (unsigned __int64)(invsqrt2 * (__int64)left) >> 28;
          left = v52 - v53;
          *v50++ = (unsigned __int64)(invsqrt2 * (__int64)(v52 - v53)) >> 28;
        }
        part2_3_length_low = start;
        v48 = lower;
      }
      granulea = (const granule *)((char *)granulea + 1);
      max += 2;
      v48 += part2_3_length_low;
      lower = v48;
    }
    while ( v48 < 0x240 );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0051E1B0
// Name: III_aliasreduce
// Source: json
//------------------------------------------------------------------------------
void __usercall III_aliasreduce(int lines@<eax>, int *xr)
{
  int *v2; // ebx
  int *v3; // edi
  int i; // ecx
  const int *bound; // [esp+4h] [ebp-14h]
  int b; // [esp+8h] [ebp-10h]
  int a; // [esp+20h] [ebp+8h]

  v2 = xr + 18;
  bound = &xr[lines];
  if ( xr + 18 < bound )
  {
    do
    {
      v3 = v2 - 1;
      for ( i = 0; i < 8; ++i )
      {
        a = *v3;
        b = v2[i];
        if ( (*v3 | b) != 0 )
        {
          *v3 = ((unsigned __int64)(dword_5CBB24[i] * (__int64)a) >> 28)
              + ((unsigned __int64)(ca[i] * (__int64)-v2[i]) >> 28);
          v2[i] = ((unsigned __int64)(dword_5CBB24[i] * (__int64)b) >> 28)
                + ((unsigned __int64)(ca[i] * (__int64)a) >> 28);
        }
        --v3;
      }
      v2 += 18;
    }
    while ( v2 < bound );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051E270
// Name: fastsdct
// Source: json
//------------------------------------------------------------------------------
void __usercall fastsdct(const int *x@<eax>, int *y@<ecx>)
{
  int v3; // edx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // edx
  int v8; // edi
  int v9; // edi
  int v10; // edx
  int v11; // edi
  int v12; // ebx
  int v13; // esi
  int v14; // edx
  int a4; // [esp+10h] [ebp-34h]
  int a9; // [esp+14h] [ebp-30h]
  int a10; // [esp+18h] [ebp-2Ch]
  int a11; // [esp+1Ch] [ebp-28h]
  int a5; // [esp+20h] [ebp-24h]
  int a14; // [esp+24h] [ebp-20h]
  int m6; // [esp+28h] [ebp-1Ch]
  int m7; // [esp+2Ch] [ebp-18h]
  int m0; // [esp+30h] [ebp-14h]
  int a16; // [esp+34h] [ebp-10h]
  int m5; // [esp+38h] [ebp-Ch]
  int m5a; // [esp+38h] [ebp-Ch]
  int m1; // [esp+3Ch] [ebp-8h]
  int m1a; // [esp+3Ch] [ebp-8h]
  int a18; // [esp+40h] [ebp-4h]
  int a18a; // [esp+40h] [ebp-4h]

  v3 = x[5];
  v4 = x[3];
  v5 = v4 + v3;
  v6 = v4 - v3;
  v7 = x[6];
  a18 = v7 + x[2];
  v8 = x[1];
  m5 = v7 - x[2];
  a4 = v8 + x[7];
  a5 = v8 - x[7];
  v9 = x[8];
  v10 = v9 + *x;
  m1 = v9 - *x;
  a9 = v5 - a18;
  a10 = v5 - v10;
  a11 = a18 - v10;
  v11 = v5 + a18 + v10;
  a14 = v6 + m1 - m5;
  a18a = m5 + m1;
  m0 = (unsigned __int64)(-345093970LL * (v6 + m5)) >> 28;
  m1a = (unsigned __int64)(-528714637LL * (v6 - m1)) >> 28;
  a16 = (unsigned __int64)(-183620666LL * a18a) >> 28;
  v12 = (unsigned __int64)(-464943848LL * a5) >> 28;
  m5a = (unsigned __int64)(504493634LL * a11) >> 28;
  m6 = (unsigned __int64)(-93226656LL * a10) >> 28;
  v13 = x[4];
  m7 = (unsigned __int64)(-411266979LL * a9) >> 28;
  v14 = 2 * v13 - a4;
  *y = v11 + v13 + a4;
  y[2] = m0 - v12 - m1a;
  y[4] = m7 - v14 - m5a;
  y[6] = (unsigned __int64)(-464943848LL * a14) >> 28;
  y[8] = v14 - m6 - m5a;
  y[10] = v12 - a16 - m1a;
  y[12] = v11 - 2 * (v13 + a4);
  y[14] = m0 + a16 + v12;
  y[16] = m6 + m7 + v14;
}

//------------------------------------------------------------------------------
// Address: 0x0051E410
// Name: sdctII
// Source: json
//------------------------------------------------------------------------------
void __cdecl sdctII(char *x, int *X)
{
  const int *v2; // edx
  int v3; // ecx
  const int *v4; // eax
  int v5; // ebx
  int v6; // esi
  int v7; // esi
  const int *v8; // esi
  _DWORD *v9; // edi
  int i; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int *v15; // eax
  int j; // edx
  _DWORD v17[3]; // [esp+0h] [ebp-3Ch]
  int tmp[9]; // [esp+Ch] [ebp-30h] BYREF
  int v19; // [esp+30h] [ebp-Ch]
  int v20; // [esp+34h] [ebp-8h]
  int v21; // [esp+38h] [ebp-4h]

  v2 = (const int *)(x + 64);
  v3 = 0;
  v4 = (const int *)(x + 8);
  v21 = (int)(x + 64);
  v5 = (char *)tmp - x;
  do
  {
    v3 += 3;
    v17[v3] = *(v4 - 2) + v2[1];
    v6 = *v2 + *(v4 - 1);
    v2 -= 3;
    v17[v3 + 1] = v6;
    v7 = *v4 + v2[2];
    v4 += 3;
    *(const int *)((char *)v4 + v5 - 12) = v7;
  }
  while ( v3 < 9 );
  fastsdct(x: tmp, y: X);
  v8 = (const int *)(x + 8);
  v9 = (_DWORD *)v21;
  v19 = (char *)scale - x;
  for ( i = 0; i < 9; i += 3 )
  {
    v11 = *(v8 - 2) - v9[1];
    v21 = scale[i];
    v20 = v11;
    v12 = (unsigned __int64)(v21 * (__int64)v11) >> 28;
    v13 = *(v8 - 1) - *v9;
    tmp[i] = v12;
    v20 = dword_5CBD54[i];
    v21 = v13;
    tmp[i + 1] = (unsigned __int64)(v20 * (__int64)v13) >> 28;
    v14 = *v8 - *(v9 - 1);
    v20 = *(const int *)((char *)v8 + v19);
    v21 = v14;
    *(const int *)((char *)v8 + v5) = (unsigned __int64)(v20 * (__int64)v14) >> 28;
    v9 -= 3;
    v8 += 3;
  }
  fastsdct(x: tmp, y: X + 1);
  v15 = X + 5;
  for ( j = 2; j != 0; --j )
  {
    *(v15 - 2) -= *(v15 - 4);
    *v15 -= *(v15 - 2);
    v15[2] -= *v15;
    v15[4] -= v15[2];
    v15 += 8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051E530
// Name: dctIV
// Source: json
//------------------------------------------------------------------------------
void __usercall dctIV(char *y@<eax>, int *X)
{
  int v2; // edi
  int v3; // ebx
  const int *v4; // esi
  int i; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int *v11; // ecx
  int j; // ebx
  int v13; // kr0C_4
  int v14; // esi
  int v15; // kr04_4
  int v16; // edi
  int v17; // esi
  int v18; // eax
  int tmp[18]; // [esp+Ch] [ebp-50h] BYREF
  int v20; // [esp+54h] [ebp-8h]
  int v21; // [esp+58h] [ebp-4h]

  v2 = (char *)scale_0 - y;
  v3 = (char *)tmp - y;
  v4 = (const int *)(y + 8);
  for ( i = 0; i < 18; i += 3 )
  {
    v6 = *(v4 - 2);
    v21 = scale_0[i];
    v20 = v6;
    v7 = (unsigned __int64)(v21 * (__int64)v6) >> 28;
    v8 = *(v4 - 1);
    tmp[i] = v7;
    v20 = dword_5CBD7C[i];
    v21 = v8;
    v9 = (unsigned __int64)(v20 * (__int64)v8) >> 28;
    v10 = *v4;
    tmp[i + 1] = v9;
    v20 = *(const int *)((char *)v4 + v2);
    v21 = v10;
    *(const int *)((char *)v4 + v3) = (unsigned __int64)(v20 * (__int64)v10) >> 28;
    v4 += 3;
  }
  sdctII(x: (char *)tmp, X);
  *X /= 2;
  v11 = X + 2;
  for ( j = 4; j != 0; --j )
  {
    v13 = *v11;
    v14 = *(v11 - 1) / 2 - *(v11 - 2);
    v15 = v11[1];
    *(v11 - 1) = v14;
    v16 = v13 / 2 - v14;
    v17 = v15 / 2 - v16;
    v18 = v11[2] / 2 - v17;
    *v11 = v16;
    v11[1] = v17;
    v11[2] = v18;
    v11 += 4;
  }
  X[17] = X[17] / 2 - X[16];
}

//------------------------------------------------------------------------------
// Address: 0x0051E630
// Name: imdct36
// Source: json
//------------------------------------------------------------------------------
void __usercall imdct36(char *y@<edi>, char *x)
{
  int *v2; // eax
  int *v3; // ecx
  int *v4; // eax
  int j; // edx
  int *v6; // ecx
  int *v7; // eax
  int k; // edx
  int tmp[18]; // [esp+4h] [ebp-4Ch] BYREF
  int i; // [esp+4Ch] [ebp-4h]

  dctIV(y: x, X: tmp);
  v2 = (int *)(y + 8);
  for ( i = 3; i != 0; --i )
  {
    *(v2 - 2) = *(int *)((char *)v2 + (char *)&tmp[7] - y);
    *(v2 - 1) = *(int *)((char *)v2 + (char *)&tmp[8] - y);
    *v2 = *(int *)((char *)v2 + (char *)&tmp[9] - y);
    v2 += 3;
  }
  v3 = (int *)(y + 44);
  v4 = &tmp[16];
  for ( j = 6; j != 0; --j )
  {
    *(v3 - 2) = -v4[1];
    *(v3 - 1) = -*v4;
    *v3 = -*(v4 - 1);
    v4 -= 3;
    v3 += 3;
  }
  v6 = (int *)(y + 116);
  v7 = &tmp[1];
  for ( k = 3; k != 0; --k )
  {
    *(v6 - 2) = -*(v7 - 1);
    *(v6 - 1) = -*v7;
    *v6 = -v7[1];
    v7 += 3;
    v6 += 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051E6E0
// Name: III_imdct_l
// Source: json
//------------------------------------------------------------------------------
void __usercall III_imdct_l(char *X@<eax>, char *z@<ecx>, unsigned int block_type)
{
  const int *v4; // esi
  unsigned int k; // ecx
  int *v6; // ecx
  unsigned int m; // esi
  int *v8; // ecx
  unsigned int i; // ebx
  const int *v10; // ebx
  unsigned int j; // ecx
  int *v12; // ecx
  unsigned int n; // esi

  imdct36(y: z, x: X);
  if ( block_type != 0 )
  {
    if ( block_type == 1 )
    {
      v8 = (int *)(z + 8);
      for ( i = 0; i < 18; i += 3 )
      {
        *(v8 - 2) = (unsigned __int64)(window_l[i] * (__int64)*(v8 - 2)) >> 28;
        *(v8 - 1) = (unsigned __int64)(window_l[i + 1] * (__int64)*(v8 - 1)) >> 28;
        *v8 = (unsigned __int64)(*(int *)((char *)v8 + (char *)window_l - z) * (__int64)*v8) >> 28;
        v8 += 3;
      }
      v10 = &window_s[6];
      for ( j = 96; j < 0x78; j += 4 )
        *(_DWORD *)&z[j] = (unsigned __int64)(*v10++ * (__int64)*(int *)&z[j]) >> 28;
      *((_DWORD *)z + 30) = 0;
      *((_DWORD *)z + 31) = 0;
      *((_DWORD *)z + 32) = 0;
      *((_DWORD *)z + 33) = 0;
      *((_DWORD *)z + 34) = 0;
      *((_DWORD *)z + 35) = 0;
    }
    else if ( block_type == 3 )
    {
      *(_DWORD *)z = 0;
      *((_DWORD *)z + 1) = 0;
      *((_DWORD *)z + 2) = 0;
      *((_DWORD *)z + 3) = 0;
      *((_DWORD *)z + 4) = 0;
      *((_DWORD *)z + 5) = 0;
      v4 = window_s;
      for ( k = 24; k < 0x30; k += 4 )
        *(_DWORD *)&z[k] = (unsigned __int64)(*v4++ * (__int64)*(int *)&z[k]) >> 28;
      v6 = (int *)(z + 80);
      for ( m = 18; m < 36; m += 3 )
      {
        *(v6 - 2) = (unsigned __int64)(window_l[m] * (__int64)*(v6 - 2)) >> 28;
        *(v6 - 1) = (unsigned __int64)(window_l[m + 1] * (__int64)*(v6 - 1)) >> 28;
        *v6 = (unsigned __int64)(*(int *)((char *)v6 + (char *)window_l - z) * (__int64)*v6) >> 28;
        v6 += 3;
      }
    }
  }
  else
  {
    v12 = (int *)(z + 8);
    for ( n = 0; n < 36; n += 4 )
    {
      *(v12 - 2) = (unsigned __int64)(window_l[n] * (__int64)*(v12 - 2)) >> 28;
      *(v12 - 1) = (unsigned __int64)(window_l[n + 1] * (__int64)*(v12 - 1)) >> 28;
      *v12 = (unsigned __int64)(*(int *)((char *)v12 + (char *)window_l - z) * (__int64)*v12) >> 28;
      v12[1] = (unsigned __int64)(*(int *)((char *)v12 + (char *)&window_l[1] - z) * (__int64)v12[1]) >> 28;
      v12 += 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051E920
// Name: III_imdct_s
// Source: json
//------------------------------------------------------------------------------
void __cdecl III_imdct_s(int *z)
{
  const int *X; // ecx
  const int *v2; // esi
  int v3; // edi
  const int *v4; // ecx
  int *v5; // ebx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // edx
  int v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // edx
  int v29; // eax
  int v30; // edx
  int v31; // eax
  int v32; // edx
  int v33; // eax
  const int *v34; // esi
  int *v35; // ecx
  int *v36; // edi
  int v37; // edx
  int v38; // eax
  int v39; // edx
  int v40; // eax
  int v41; // edx
  int v42; // ebx
  int v43; // eax
  int v44; // edx
  int v45; // eax
  int v46; // edx
  int v47; // ebx
  int v48; // eax
  int v49; // edx
  int y[36]; // [esp+Ch] [ebp-B4h] BYREF
  int v51; // [esp+9Ch] [ebp-24h]
  int v52; // [esp+A0h] [ebp-20h]
  int v53; // [esp+A4h] [ebp-1Ch]
  int i; // [esp+A8h] [ebp-18h]
  int *v55; // [esp+ACh] [ebp-14h]
  int v56; // [esp+B0h] [ebp-10h]
  int v57; // [esp+B4h] [ebp-Ch]
  int v58; // [esp+B8h] [ebp-8h]
  int v59; // [esp+BCh] [ebp-4h]

  v55 = &y[6];
  v2 = X + 2;
  for ( i = 3; i != 0; --i )
  {
    v3 = 0;
    v4 = imdct_s[0];
    v5 = v55 + 5;
    do
    {
      v6 = *(v2 - 2);
      v57 = *v4;
      v56 = v6;
      v7 = v4[1];
      v58 = (unsigned __int64)(v57 * (__int64)v6) >> 28;
      v8 = *(v2 - 1);
      v56 = v7;
      v57 = v8;
      v9 = (unsigned __int64)(v7 * (__int64)v8) >> 28;
      v10 = v4[2];
      v59 = v9;
      v11 = *v2;
      v56 = v10;
      v57 = v11;
      v12 = (unsigned __int64)(v10 * (__int64)v11) >> 28;
      v13 = v4[3];
      v52 = v12;
      v14 = v2[1];
      v56 = v13;
      v57 = v14;
      v15 = (unsigned __int64)(v13 * (__int64)v14) >> 28;
      v16 = v4[4];
      v51 = v15;
      v17 = v2[2];
      v56 = v16;
      v57 = v17;
      v18 = (unsigned __int64)(v16 * (__int64)v17) >> 28;
      v19 = v4[5];
      v53 = v18;
      v20 = v2[3];
      v56 = v19;
      v57 = v20;
      v21 = v58 + v59 + v52 + v51 + v53 + ((unsigned __int64)(v19 * (__int64)v20) >> 28);
      v55[v3 - 6] = v21;
      v22 = *(v2 - 2);
      *(v5 - 6) = -v21;
      v58 = v4[6];
      v59 = v22;
      v23 = (unsigned __int64)(v58 * (__int64)v22) >> 28;
      v24 = *(v2 - 1);
      v57 = v23;
      v58 = v4[7];
      v59 = v24;
      v25 = (unsigned __int64)(v58 * (__int64)v24) >> 28;
      v26 = *v2;
      v56 = v25;
      v58 = v4[8];
      v59 = v26;
      v27 = (unsigned __int64)(v58 * (__int64)v26) >> 28;
      v28 = v2[1];
      v53 = v27;
      v58 = v4[9];
      v59 = v28;
      v29 = (unsigned __int64)(v58 * (__int64)v28) >> 28;
      v30 = v2[2];
      v51 = v29;
      v58 = v4[10];
      v59 = v30;
      v31 = (unsigned __int64)(v58 * (__int64)v30) >> 28;
      v32 = v2[3];
      v52 = v31;
      v58 = v4[11];
      v59 = v32;
      ++v3;
      v33 = v57 + v56 + v53 + v51 + v31 + ((unsigned __int64)(v58 * (__int64)v32) >> 28);
      v4 += 12;
      v55[v3 - 1] = v33;
      *v5-- = v33;
    }
    while ( v3 < 3 );
    v55 += 12;
    v2 += 6;
  }
  v34 = window_s;
  v35 = &y[12];
  v36 = z + 12;
  for ( i = 6; i != 0; --i )
  {
    v37 = *(v35 - 12);
    *(v36 - 12) = 0;
    v58 = *v34;
    v59 = v37;
    v38 = (unsigned __int64)(v58 * (__int64)v37) >> 28;
    v39 = *(v35 - 6);
    *(v36 - 6) = v38;
    v58 = v34[6];
    v59 = v39;
    v40 = (unsigned __int64)(v58 * (__int64)v39) >> 28;
    v41 = *v35;
    v42 = v40;
    v58 = *v34;
    v59 = v41;
    v43 = (unsigned __int64)(v58 * (__int64)v41) >> 28;
    v44 = v35[6];
    *v36 = v42 + v43;
    v58 = v34[6];
    v59 = v44;
    v45 = (unsigned __int64)(v58 * (__int64)v44) >> 28;
    v46 = v35[12];
    v47 = v45;
    v58 = *v34;
    v59 = v46;
    v48 = (unsigned __int64)(v58 * (__int64)v46) >> 28;
    v49 = v35[18];
    v36[6] = v47 + v48;
    v58 = v34[6];
    v59 = v49;
    v36[12] = (unsigned __int64)(v58 * (__int64)v49) >> 28;
    v36[18] = 0;
    ++v35;
    ++v34;
    ++v36;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051EBA0
// Name: III_overlap
// Source: json
//------------------------------------------------------------------------------
void __usercall III_overlap(char *overlap@<eax>, unsigned int sb@<edx>, char *output, int (*sample)[32])
{
  int *v5; // ecx
  const int *v6; // eax
  int v7; // esi
  int *v8; // edx
  int i; // edi
  int v10; // ebx
  int v11; // ebx

  v5 = (int *)(overlap + 12);
  v6 = (const int *)(output + 4);
  v7 = overlap - output;
  v8 = &(*sample)[sb + 64];
  for ( i = 3; i != 0; --i )
  {
    v8 += 192;
    *(v8 - 256) = *(v5 - 3) + *(v6 - 1);
    *(v5 - 3) = v6[17];
    v10 = *v6 + *(const int *)((char *)v6 + v7);
    v6 += 6;
    *(v8 - 224) = v10;
    *(const int *)((char *)v6 + v7 - 24) = v6[12];
    v11 = *(v5 - 1) + *(v6 - 5);
    v5 += 6;
    *(v8 - 192) = v11;
    *(v5 - 7) = v6[13];
    *(v8 - 160) = *(v5 - 6) + *(v6 - 4);
    *(v5 - 6) = v6[14];
    *(v8 - 128) = *(v5 - 5) + *(v6 - 3);
    *(v5 - 5) = v6[15];
    *(v8 - 96) = *(v5 - 4) + *(v6 - 2);
    *(v5 - 4) = v6[16];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051EC50
// Name: III_decode
// Source: json
//------------------------------------------------------------------------------
mad_error __cdecl III_decode(mad_bitptr *ptr, mad_frame *frame, sideinfo *si, unsigned int nch)
{
  unsigned int samplerate; // ecx
  int flags; // eax
  int v6; // ecx
  int v7; // eax
  sideinfo *v8; // edx
  int v9; // ebx
  int v10; // edi
  bool v11; // zf
  channel *v12; // esi
  unsigned __int8 *v13; // ecx
  channel *v14; // eax
  unsigned int v15; // eax
  char v16; // cl
  mad_error result; // eax
  unsigned __int8 *v18; // esi
  unsigned int v19; // edi
  int *v20; // ebx
  int v21; // eax
  unsigned __int8 v22; // al
  unsigned int i; // esi
  unsigned int v24; // edi
  unsigned int v25; // esi
  char *v26; // ebx
  int *v27; // esi
  int v28; // ecx
  int v29; // edx
  int *v30; // eax
  int j; // edi
  unsigned int v32; // ecx
  unsigned int v33; // eax
  _DWORD *v34; // ecx
  unsigned int v35; // edi
  unsigned int v36; // ebx
  int *v37; // esi
  int v38; // ecx
  int v39; // edx
  int *v40; // eax
  int m; // edi
  int v42; // edx
  int *v43; // esi
  int v44; // ecx
  int v45; // edx
  int *v46; // eax
  int k; // edi
  int v48; // edx
  int v49; // ebx
  int *v50; // esi
  char *v51; // ecx
  unsigned int v52; // eax
  int *v53; // edx
  int v54; // ecx
  int v55; // edx
  int *v56; // eax
  int n; // edi
  int v58; // eax
  int xr[1152]; // [esp+0h] [ebp-12CCh] BYREF
  int z[36]; // [esp+1200h] [ebp-CCh] BYREF
  unsigned int v61; // [esp+1290h] [ebp-3Ch]
  unsigned __int8 *sfbwidth[2]; // [esp+1294h] [ebp-38h]
  int v63; // [esp+129Ch] [ebp-30h]
  int v64; // [esp+12A0h] [ebp-2Ch]
  int v65; // [esp+12A4h] [ebp-28h]
  unsigned int v66; // [esp+12A8h] [ebp-24h]
  int v67; // [esp+12ACh] [ebp-20h]
  unsigned __int8 *p_flags; // [esp+12B0h] [ebp-1Ch]
  int v69; // [esp+12B4h] [ebp-18h]
  int *X; // [esp+12B8h] [ebp-14h]
  unsigned int v71; // [esp+12BCh] [ebp-10h]
  granule *granule; // [esp+12C0h] [ebp-Ch]
  int (*sample)[32]; // [esp+12C4h] [ebp-8h]
  unsigned int block_type; // [esp+12C8h] [ebp-4h]

  samplerate = frame->header.samplerate;
  flags = frame->header.flags;
  if ( (flags & 0x4000) != 0 )
    samplerate *= 2;
  v6 = ((samplerate >> 7) & 0xF) + ((samplerate & 0x8000) != 0) - 8;
  v63 = v6;
  if ( (flags & 0x4000) != 0 )
  {
    v6 += 3;
    v63 = v6;
  }
  v7 = -((flags & 0x1000) != 0);
  v61 = v7 + 2;
  v69 = 0;
  if ( v7 == -2 )
    return MAD_ERROR_NONE;
  while ( 1 )
  {
    v8 = si;
    v9 = 0;
    granule = &si->gr[v69];
    if ( nch != 0 )
      break;
LABEL_27:
    if ( frame->header.mode == MAD_MODE_JOINT_STEREO && frame->header.mode_extension != 0 )
    {
      result = III_stereo((int (*)[576])xr, granule, header: &frame->header, sfbwidth: sfbwidth[0]);
      if ( result != MAD_ERROR_NONE )
        return result;
    }
    v66 = 0;
    if ( nch != 0 )
    {
      v65 = 0;
      v71 = 0;
      p_flags = &granule->ch[0].flags;
      granule = (granule *)&xr[36];
      sample = (int (*)[32])frame->sbsample[0][18 * v69];
      v64 = 144 - (_DWORD)xr;
      while ( 1 )
      {
        v18 = p_flags;
        v19 = v71;
        v20 = &xr[v71 / 4];
        if ( p_flags[1] != 2 )
          break;
        III_reorder(xr: &xr[v71 / 4], channel: (const channel *)(p_flags - 8), sfbwidth: sfbwidth[v66]);
        if ( (*v18 & 8) != 0 )
        {
          v21 = 36;
LABEL_36:
          III_aliasreduce(lines: v21, xr: v20);
        }
        v22 = v18[1];
        if ( v22 != 2 || (*v18 & 8) != 0 )
        {
          v11 = (*v18 & 8) == 0;
          block_type = v22;
          if ( !v11 )
            block_type = 0;
          v24 = v71;
          v25 = 0;
          v26 = (char *)&xr[v71 / 4];
          do
          {
            III_imdct_l(X: v26, (char *)z, block_type);
            III_overlap(overlap: (char *)frame->overlap + v24, sb: v25++, output: (char *)z, sample);
            v24 += 72;
            v26 += 72;
          }
          while ( v25 < 2 );
        }
        else
        {
          for ( i = 0; i < 2; ++i )
          {
            III_imdct_s(z);
            III_overlap(overlap: (char *)frame->overlap + v19, sb: i, output: (char *)z, sample);
            v19 += 72;
            v20 += 18;
          }
        }
        v27 = (int *)sample;
        v28 = (*sample)[33];
        v29 = (*sample)[97];
        v30 = &(*sample)[161];
        for ( j = 3; j != 0; --j )
        {
          *(v30 - 128) = -v28;
          v28 = *v30;
          *(v30 - 64) = -v29;
          v29 = v30[64];
          v30 += 128;
        }
        v27[417] = -v28;
        v32 = v71;
        v27[481] = -v29;
        v27[545] = -v27[545];
        v33 = 576;
        v34 = (int *)((char *)&xr[575] + v32);
        do
        {
          if ( *v34 != 0 )
            break;
          --v33;
          --v34;
        }
        while ( v33 > 0x24 );
        v35 = 32 - (576 - v33) / 0x12;
        v36 = 2;
        v67 = v35;
        if ( p_flags[1] == 2 )
        {
          if ( v35 > 2 )
          {
            block_type = (unsigned int)&xr[v71 / 4] + v64;
            v43 = &(*sample)[98];
            X = (int *)granule;
            do
            {
              III_imdct_s(z);
              III_overlap(overlap: (char *)frame->overlap + block_type, sb: v36, output: (char *)z, sample);
              if ( (v36 & 1) != 0 )
              {
                v44 = *(v43 - 64);
                v45 = *v43;
                v46 = v43;
                for ( k = 3; k != 0; --k )
                {
                  *(v46 - 64) = -v44;
                  v44 = v46[64];
                  *v46 = -v45;
                  v45 = v46[128];
                  v46 += 128;
                }
                v35 = v67;
                v43[384] = -v45;
                v48 = -v43[448];
                v43[320] = -v44;
                v43[448] = v48;
              }
              block_type += 72;
              X += 18;
              ++v36;
              ++v43;
            }
            while ( v36 < v35 );
            goto LABEL_67;
          }
        }
        else if ( v35 > 2 )
        {
          X = (int *)((char *)&xr[v71 / 4] + v64);
          v37 = &(*sample)[98];
          block_type = (unsigned int)granule;
          do
          {
            III_imdct_l(X: (char *)block_type, (char *)z, block_type: p_flags[1]);
            III_overlap(overlap: (char *)X + (unsigned int)frame->overlap, sb: v36, output: (char *)z, sample);
            if ( (v36 & 1) != 0 )
            {
              v38 = *(v37 - 64);
              v39 = *v37;
              v40 = v37;
              for ( m = 3; m != 0; --m )
              {
                *(v40 - 64) = -v38;
                v38 = v40[64];
                *v40 = -v39;
                v39 = v40[128];
                v40 += 128;
              }
              v35 = v67;
              v37[384] = -v39;
              v42 = -v37[448];
              v37[320] = -v38;
              v37[448] = v42;
            }
            X += 18;
            block_type += 72;
            ++v36;
            ++v37;
          }
          while ( v36 < v35 );
LABEL_67:
          v27 = (int *)sample;
        }
        block_type = v35;
        if ( v35 < 0x20 )
        {
          v49 = 72 * (v35 + v65);
          v50 = &(*sample)[v35 + 96];
          do
          {
            v51 = (char *)frame->overlap + v49;
            v52 = 0;
            v53 = v50 - 96;
            do
            {
              *v53 = *(_DWORD *)&v51[4 * v52];
              *(_DWORD *)&v51[4 * v52++] = 0;
              v53 += 32;
            }
            while ( v52 < 0x12 );
            if ( (block_type & 1) != 0 )
            {
              v54 = *(v50 - 64);
              v55 = *v50;
              v56 = v50;
              for ( n = 3; n != 0; --n )
              {
                *(v56 - 64) = -v54;
                v54 = v56[64];
                *v56 = -v55;
                v55 = v56[128];
                v56 += 128;
              }
              v58 = -v50[448];
              v50[320] = -v54;
              v50[384] = -v55;
              v50[448] = v58;
            }
            v49 += 72;
            ++v50;
            ++block_type;
          }
          while ( block_type < 0x20 );
          v27 = (int *)sample;
        }
        p_flags += 58;
        v65 += 32;
        v71 += 2304;
        granule = (granule *)((char *)granule + 2304);
        ++v66;
        sample = (int (*)[32])(v27 + 1152);
        if ( v66 >= nch )
          goto LABEL_79;
      }
      v21 = 576;
      goto LABEL_36;
    }
LABEL_79:
    if ( ++v69 >= v61 )
      return MAD_ERROR_NONE;
    v6 = v63;
  }
  v10 = 12 * v6;
  v67 = 12 * v6;
  while ( 1 )
  {
    v11 = granule->ch[v9].block_type == 2;
    v12 = &granule->ch[v9];
    sfbwidth[v9] = *(unsigned __int8 **)((char *)&sfbwidth_table[0].l + v10);
    if ( v11 )
    {
      if ( (v12->flags & 8) != 0 )
        v13 = *(unsigned __int8 **)((char *)&sfbwidth_table[0].m + v10);
      else
        v13 = *(unsigned __int8 **)((char *)&sfbwidth_table[0].s + v10);
      sfbwidth[v9] = v13;
    }
    if ( (frame->header.flags & 0x1000) != 0 )
    {
      v14 = v9 != 0 ? &v8->gr[1].ch[1] : nullptr;
      v15 = III_scalefactors_lsf(ptr, channel: v12, gr1ch: v14, mode_extension: frame->header.mode_extension);
    }
    else
    {
      v16 = v69 != 0 ? v8->scfsi[v9] : 0;
      v15 = III_scalefactors(ptr, channel: v12, gr0ch: &si->gr[0].ch[v9], scfsi: v16);
      v10 = v67;
    }
    result = III_huffdecode(ptr, xr: &xr[576 * v9], channel: v12, sfbwidth: sfbwidth[v9], part2_length: v15);
    if ( result != MAD_ERROR_NONE )
      return result;
    if ( ++v9 >= nch )
      goto LABEL_27;
    v8 = si;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051F270
// Name: _mad_layer_III
// Source: json
//------------------------------------------------------------------------------
int __cdecl mad_layer_III(unsigned int stream, mad_frame *frame)
{
  mad_stream *v2; // esi
  unsigned __int8 *v3; // eax
  int result; // eax
  mad_frame *v5; // ebx
  unsigned __int8 *v6; // eax
  bool v7; // zf
  unsigned int v8; // edi
  int v9; // edi
  unsigned __int16 v10; // ax
  mad_error v11; // eax
  unsigned int private_bits; // ecx
  int v13; // edi
  const unsigned __int8 *v14; // eax
  unsigned int main_data_begin; // edi
  unsigned int v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // ebx
  unsigned int md_len; // eax
  unsigned __int8 *v20; // eax
  mad_stream *v21; // ecx
  mad_error v22; // eax
  int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // edi
  unsigned int v26; // eax
  sideinfo v27; // [esp+8h] [ebp-118h] BYREF
  unsigned int data_bitlen; // [esp+FCh] [ebp-24h] BYREF
  mad_bitptr peek; // [esp+100h] [ebp-20h] BYREF
  unsigned int frame_space; // [esp+108h] [ebp-18h]
  mad_bitptr ptr; // [esp+10Ch] [ebp-14h] BYREF
  unsigned int nch; // [esp+114h] [ebp-Ch]
  int v33; // [esp+118h] [ebp-8h]
  unsigned int next_md_begin; // [esp+11Ch] [ebp-4h]

  v2 = (mad_stream *)stream;
  next_md_begin = 0;
  v33 = 0;
  if ( *(_DWORD *)(stream + 48) != 0
    || (v3 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0xA07u),
        v2->main_data = (unsigned __int8 (*)[2567])v3,
        v3 != nullptr) )
  {
    v5 = frame;
    if ( frame->overlap != nullptr
      || (v6 = calloc(count: 0x480u, size: 4u), v5->overlap = (int (*)[2][32][18])v6, v6 != nullptr) )
    {
      v7 = (v5->header.flags & 0x1000) == 0;
      v8 = (v5->header.mode != MAD_MODE_SINGLE_CHANNEL) + 1;
      nch = v8;
      if ( v7 )
        v9 = v8 != 1 ? 32 : 17;
      else
        v9 = 8 * (v8 != 1) + 9;
      if ( v2->next_frame - mad_bit_nextbyte(bitptr: &v2->ptr) >= v9 )
      {
        if ( (v5->header.flags & 0x10) != 0 )
        {
          v10 = mad_bit_crc(bitptr: v2->ptr, len: 8 * v9, init: v5->header.crc_check);
          v5->header.crc_check = v10;
          if ( v10 != v5->header.crc_target && (v5->options & 1) == 0 )
          {
            v2->error = MAD_ERROR_BADCRC;
            v33 = -1;
          }
        }
        v11 = III_sideinfo(
                ptr: &v2->ptr,
                nch,
                lsf: v5->header.flags & 0x1000,
                si: &v27,
                &data_bitlen,
                priv_bitlen: &stream);
        if ( v11 != MAD_ERROR_NONE && v33 == 0 )
        {
          v2->error = v11;
          v33 = -1;
        }
        private_bits = v27.private_bits;
        v5->header.flags |= stream;
        v5->header.private_bits |= private_bits;
        mad_bit_init(bitptr: &peek, byte: v2->next_frame);
        v13 = mad_bit_read(bitptr: &peek, len: 0x20u);
        if ( (v13 & 0xFFE60000) == 0xFFE20000 )
        {
          if ( (v13 & 0x10000) == 0 )
            mad_bit_skip(bitptr: &peek, len: 0x10u);
          next_md_begin = mad_bit_read(bitptr: &peek, len: (v13 & 0x80000 | 0x400000u) >> 19);
        }
        v14 = mad_bit_nextbyte(bitptr: &v2->ptr);
        main_data_begin = v27.main_data_begin;
        frame_space = v2->next_frame - v14;
        v16 = frame_space;
        if ( next_md_begin > v27.main_data_begin + frame_space )
          next_md_begin = 0;
        v17 = next_md_begin;
        v18 = frame_space + v27.main_data_begin - next_md_begin;
        stream = 0;
        if ( v27.main_data_begin != 0 )
        {
          md_len = v2->md_len;
          if ( v27.main_data_begin <= md_len )
          {
            mad_bit_init(bitptr: &ptr, byte: &(*v2->main_data)[md_len - v27.main_data_begin]);
            if ( v18 > main_data_begin )
            {
              stream = v18 - main_data_begin;
              v20 = (unsigned __int8 *)mad_bit_nextbyte(bitptr: &v2->ptr);
              memcpy(dst: &(*v2->main_data)[v2->md_len], src: v20, count: v18 - main_data_begin);
              v2->md_len += stream;
            }
            v16 = frame_space;
            v17 = next_md_begin;
          }
          else if ( v33 == 0 )
          {
            v2->error = MAD_ERROR_BADDATAPTR;
            v33 = -1;
          }
        }
        else
        {
          ptr = v2->ptr;
          v2->md_len = 0;
          stream = v18;
        }
        v21 = (mad_stream *)(v16 - stream);
        stream = (unsigned int)v21;
        if ( v33 == 0 )
        {
          v22 = III_decode(&ptr, frame, si: &v27, nch);
          if ( v22 != MAD_ERROR_NONE )
          {
            v2->error = v22;
            v33 = -1;
          }
          v23 = *(_DWORD *)&ptr.cache;
          main_data_begin = v27.main_data_begin;
          v24 = 8 * v18 - data_bitlen;
          v2->anc_ptr.byte = ptr.byte;
          v17 = next_md_begin;
          v2->anc_bitlen = v24;
          v21 = (mad_stream *)stream;
          *(_DWORD *)&v2->anc_ptr.cache = v23;
        }
        if ( (unsigned int)v21 < v17 )
        {
          if ( v18 >= main_data_begin )
          {
            v2->md_len = 0;
          }
          else
          {
            v25 = main_data_begin - v18;
            if ( (unsigned int)v21 + v25 > v17 )
              v25 = v17 - (_DWORD)v21;
            v26 = v2->md_len;
            if ( v25 < v26 )
            {
              memmove(dst: (unsigned __int8 *)v2->main_data, src: &(*v2->main_data)[v26 - v25], count: v25);
              v21 = (mad_stream *)stream;
              v2->md_len = v25;
            }
          }
          memcpy(
            dst: &(*v2->main_data)[v2->md_len],
            src: (unsigned __int8 *)(v2->next_frame - (const unsigned __int8 *)v21),
            count: (unsigned int)v21);
          result = v33;
          v2->md_len += stream;
        }
        else
        {
          memcpy(dst: (unsigned __int8 *)v2->main_data, src: (unsigned __int8 *)&v2->next_frame[-v17], count: v17);
          result = v33;
          v2->md_len = next_md_begin;
        }
      }
      else
      {
        v2->error = MAD_ERROR_BADFRAMELEN;
        v2->md_len = 0;
        return -1;
      }
    }
    else
    {
      v2->error = MAD_ERROR_NOMEM;
      return -1;
    }
  }
  else
  {
    v2->error = MAD_ERROR_NOMEM;
    return -1;
  }
  return result;
}
