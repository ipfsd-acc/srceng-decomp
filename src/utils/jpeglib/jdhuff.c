// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdhuff.c
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000E520
// Name: _jpeg_make_d_derived_tbl
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_make_d_derived_tbl(
        jpeg_common_struct *cinfo,
        unsigned __int8 isDC,
        unsigned int tblno,
        d_derived_tbl **pdtbl)
{
  JHUFF_TBL *v5; // esi
  int v7; // edi
  int v8; // ebx
  unsigned int v9; // esi
  int v10; // ebx
  signed int v11; // esi
  int v12; // edi
  signed int v13; // edx
  char *v14; // eax
  int v15; // eax
  bool v16; // zf
  int v17; // ecx
  int i; // eax
  int v19; // esi
  char v20; // cl
  int v21; // ebx
  int v22; // eax
  unsigned __int8 *v23; // edi
  unsigned int v24; // edx
  unsigned __int8 *v25; // esi
  int *v26; // edx
  int v27; // ecx
  int v28; // edi
  int k; // esi
  unsigned int huffcode[257]; // [esp+Ch] [ebp-51Ch]
  char huffsize[260]; // [esp+410h] [ebp-118h] BYREF
  int numsymbols; // [esp+514h] [ebp-14h]
  int v34; // [esp+518h] [ebp-10h]
  int v35; // [esp+51Ch] [ebp-Ch]
  int p; // [esp+520h] [ebp-8h]
  int j; // [esp+524h] [ebp-4h]
  JHUFF_TBL *htbl; // [esp+538h] [ebp+10h]
  d_derived_tbl *dtbl; // [esp+53Ch] [ebp+14h]

  if ( tblno >= 4 )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( isDC != 0 )
  {
    v5 = *((JHUFF_TBL **)&cinfo[6].is_decompressor + tblno);
    htbl = v5;
  }
  else
  {
    htbl = *((JHUFF_TBL **)&cinfo[7].progress + tblno);
    v5 = *((JHUFF_TBL **)&cinfo[7].progress + tblno);
  }
  if ( v5 == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *pdtbl == nullptr )
    *pdtbl = (d_derived_tbl *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1424);
  v7 = 0;
  dtbl = *pdtbl;
  (*pdtbl)->pub = v5;
  v8 = 1;
  while ( 1 )
  {
    v9 = v5->bits[v8];
    if ( (int)(v9 + v7) > 256 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v9 != 0 )
    {
      memset(dst: (int)&huffsize[v7], value: (unsigned __int8 *)v8, count: v9);
      v7 += v9;
    }
    if ( ++v8 > 16 )
      break;
    v5 = htbl;
  }
  huffsize[v7] = 0;
  v10 = huffsize[0];
  numsymbols = v7;
  v11 = 0;
  v12 = 0;
  v13 = __ROL4__(1, huffsize[0]);
  j = v13;
  if ( huffsize[0] != 0 )
  {
    v14 = huffsize;
    while ( 1 )
    {
      if ( *v14 == v10 )
      {
        do
        {
          v15 = huffsize[v12 + 1];
          huffcode[v12++] = v11++;
        }
        while ( v15 == v10 );
      }
      if ( v11 >= v13 )
      {
        cinfo->err->msg_code = 8;
        cinfo->err->error_exit(a1: cinfo);
        v13 = j;
      }
      v11 *= 2;
      ++v10;
      v16 = huffsize[v12] == 0;
      v14 = &huffsize[v12];
      j = __ROL4__(v13, 1);
      if ( v16 )
        break;
      v13 = j;
    }
  }
  v17 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    if ( htbl->bits[i] != 0 )
    {
      dtbl->valoffset[i] = v17 - huffcode[v17];
      v17 += htbl->bits[i];
      dtbl->maxcode[i] = huffcode[v17 - 1];
    }
    else
    {
      dtbl->maxcode[i] = -1;
    }
  }
  dtbl->maxcode[17] = 0xFFFFF;
  memset(dst: (int)dtbl->look_nbits, value: nullptr, count: sizeof(dtbl->look_nbits));
  v19 = 0;
  v20 = 7;
  p = 0;
  v21 = 1;
  for ( j = 7; j >= 0; --j )
  {
    if ( htbl->bits[v21] != 0 )
    {
      v22 = 1 << v20;
      v35 = 1;
      v23 = &htbl->huffval[v19];
      v34 = 1 << v20;
      do
      {
        v24 = huffcode[v19] << j;
        if ( v22 > 0 )
        {
          v25 = &dtbl->look_sym[v24];
          v26 = &dtbl->look_nbits[v24];
          do
          {
            *v26 = v21;
            *v25 = *v23;
            --v22;
            ++v26;
            ++v25;
          }
          while ( v22 > 0 );
          v19 = p;
          v22 = v34;
        }
        v27 = htbl->bits[v21];
        ++v19;
        ++v23;
        p = v19;
        ++v35;
      }
      while ( v35 <= v27 );
    }
    ++v21;
    v20 = j - 1;
  }
  if ( isDC != 0 )
  {
    v28 = numsymbols;
    for ( k = 0; k < v28; ++k )
    {
      if ( htbl->huffval[k] > 0xFu )
      {
        cinfo->err->msg_code = 8;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E7D0
// Name: _jpeg_fill_bit_buffer
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl jpeg_fill_bit_buffer(bitread_working_state *state, int get_buffer, int bits_left, int nbits)
{
  bitread_working_state *v4; // eax
  jpeg_decompress_struct *cinfo; // ebx
  const unsigned __int8 *next_input_byte; // esi
  unsigned int bytes_in_buffer; // edi
  jpeg_source_mgr *src; // eax
  int v9; // eax
  jpeg_source_mgr *v10; // eax
  int v11; // eax
  char v13; // cl

  v4 = state;
  cinfo = state->cinfo;
  next_input_byte = state->next_input_byte;
  bytes_in_buffer = state->bytes_in_buffer;
  if ( cinfo->unread_marker != 0 )
    goto no_more_bytes;
  if ( bits_left < 25 )
  {
    while ( 1 )
    {
      if ( bytes_in_buffer == 0 )
      {
        if ( cinfo->src->fill_input_buffer(a1: cinfo) == 0 )
          return 0;
        src = cinfo->src;
        next_input_byte = src->next_input_byte;
        bytes_in_buffer = src->bytes_in_buffer;
      }
      v9 = *next_input_byte;
      --bytes_in_buffer;
      ++next_input_byte;
      if ( v9 == 255 )
      {
        do
        {
          if ( bytes_in_buffer == 0 )
          {
            if ( cinfo->src->fill_input_buffer(a1: cinfo) == 0 )
              return 0;
            v10 = cinfo->src;
            next_input_byte = v10->next_input_byte;
            bytes_in_buffer = v10->bytes_in_buffer;
          }
          v11 = *next_input_byte;
          --bytes_in_buffer;
          ++next_input_byte;
        }
        while ( v11 == 255 );
        if ( v11 != 0 )
        {
          cinfo->unread_marker = v11;
          v4 = state;
no_more_bytes:
          if ( nbits > bits_left )
          {
            if ( cinfo->entropy->insufficient_data == 0 )
            {
              cinfo->err->msg_code = 117;
              cinfo->err->emit_message(a1: (jpeg_common_struct *)cinfo, a2: -1);
              cinfo->entropy->insufficient_data = 1;
            }
            v13 = 25 - bits_left;
            bits_left = 25;
            get_buffer <<= v13;
LABEL_21:
            v4 = state;
          }
          break;
        }
        v9 = 255;
      }
      get_buffer = v9 | (get_buffer << 8);
      bits_left += 8;
      if ( bits_left >= 25 )
        goto LABEL_21;
    }
  }
  v4->bytes_in_buffer = bytes_in_buffer;
  v4->next_input_byte = next_input_byte;
  v4->get_buffer = get_buffer;
  v4->bits_left = bits_left;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E8E0
// Name: _jpeg_huff_decode
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_huff_decode(
        bitread_working_state *state,
        int get_buffer,
        int bits_left,
        d_derived_tbl *htbl,
        int min_bits)
{
  int v5; // eax
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  int v10; // esi
  d_derived_tbl *v11; // ebx
  int v12; // esi
  int l; // [esp+8h] [ebp-4h]

  v5 = bits_left;
  l = min_bits;
  if ( bits_left >= min_bits )
  {
    v7 = get_buffer;
  }
  else
  {
    if ( jpeg_fill_bit_buffer(state, get_buffer, bits_left, nbits: min_bits) == 0 )
      return -1;
    v7 = state->get_buffer;
    v5 = state->bits_left;
  }
  v8 = v5 - min_bits;
  v9 = min_bits;
  v10 = ((1 << min_bits) - 1) & (v7 >> v8);
  v11 = htbl;
  if ( v10 > htbl->maxcode[min_bits] )
  {
    do
    {
      v12 = 2 * v10;
      if ( v8 < 1 )
      {
        if ( jpeg_fill_bit_buffer(state, get_buffer: v7, bits_left: v8, nbits: 1) == 0 )
          return -1;
        v7 = state->get_buffer;
        v8 = state->bits_left;
      }
      --v8;
      v9 = l + 1;
      l = v9;
      v10 = (v7 >> v8) & 1 | v12;
      v11 = htbl;
    }
    while ( v10 > htbl->maxcode[v9] );
  }
  state->get_buffer = v7;
  state->bits_left = v8;
  if ( v9 <= 16 )
    return v11->pub->huffval[v11->valoffset[v9] + v10];
  state->cinfo->err->msg_code = 118;
  state->cinfo->err->emit_message(a1: (jpeg_common_struct *)state->cinfo, a2: -1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E9D0
// Name: process_restart
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall process_restart@<al>(jpeg_decompress_struct *cinfo@<esi>)
{
  jpeg_entropy_decoder *entropy; // edi
  unsigned __int8 result; // al
  int v3; // eax
  unsigned __int8 *p_insufficient_data; // ecx

  entropy = cinfo->entropy;
  cinfo->marker->discarded_bytes += (int)entropy[1].decode_mcu / 8;
  entropy[1].decode_mcu = nullptr;
  result = ((int (*)(void))cinfo->marker->read_restart_marker)();
  if ( result != 0 )
  {
    v3 = 0;
    if ( cinfo->comps_in_scan > 0 )
    {
      p_insufficient_data = &entropy[1].insufficient_data;
      do
      {
        *(_DWORD *)p_insufficient_data = 0;
        ++v3;
        p_insufficient_data += 4;
      }
      while ( v3 < cinfo->comps_in_scan );
    }
    entropy[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->restart_interval;
    if ( cinfo->unread_marker == 0 )
      entropy->insufficient_data = 0;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000EA50
// Name: decode_mcu
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl decode_mcu(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_decompress_struct *v2; // ebx
  bool v3; // zf
  huff_entropy_decoder *v4; // edi
  bool v6; // cc
  jpeg_source_mgr *src; // eax
  const unsigned __int8 *next_input_byte; // ecx
  unsigned int bytes_in_buffer; // edx
  int get_buffer; // esi
  int bits_left; // eax
  d_derived_tbl **ac_cur_tbls; // ecx
  d_derived_tbl *v13; // ebx
  d_derived_tbl *v14; // edi
  int v15; // ecx
  int v16; // edx
  int v17; // ecx
  int v18; // edi
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  int v22; // ebx
  d_derived_tbl *v23; // edi
  int v24; // ecx
  int v25; // edx
  int v26; // ecx
  int v27; // edi
  int v28; // ecx
  int v29; // edi
  int v30; // edx
  int v31; // ebx
  int v32; // ecx
  int v33; // edx
  int v34; // ecx
  int v35; // edi
  int v36; // ecx
  int v37; // edi
  __int64 v38; // xmm0_8
  __int64 v39; // xmm0_8
  bitread_working_state br_state; // [esp+Ch] [ebp-40h] BYREF
  __int64 block; // [esp+20h] [ebp-2Ch]
  __int64 v42; // [esp+28h] [ebp-24h]
  __int16 *v43; // [esp+30h] [ebp-1Ch]
  huff_entropy_decoder *entropy; // [esp+34h] [ebp-18h]
  int *MCU_membership; // [esp+38h] [ebp-14h]
  d_derived_tbl **v46; // [esp+3Ch] [ebp-10h]
  int blkn; // [esp+40h] [ebp-Ch]
  d_derived_tbl *actbl; // [esp+44h] [ebp-8h]
  int k; // [esp+48h] [ebp-4h]

  v2 = cinfo;
  v3 = cinfo->restart_interval == 0;
  v4 = (huff_entropy_decoder *)cinfo->entropy;
  entropy = v4;
  if ( !v3 && v4->saved.last_dc_val[3] == 0 && process_restart(cinfo) == 0 )
    return 0;
  if ( v4->pub.insufficient_data != 0 )
    goto LABEL_71;
  v6 = cinfo->blocks_in_MCU <= 0;
  src = cinfo->src;
  next_input_byte = src->next_input_byte;
  bytes_in_buffer = src->bytes_in_buffer;
  get_buffer = v4->bitstate.get_buffer;
  bits_left = v4->bitstate.bits_left;
  block = *(_QWORD *)&v4->saved.EOBRUN;
  br_state.cinfo = cinfo;
  br_state.next_input_byte = next_input_byte;
  br_state.bytes_in_buffer = bytes_in_buffer;
  v42 = *(_QWORD *)&v4->gap0[8];
  blkn = 0;
  if ( v6 )
    goto LABEL_70;
  ac_cur_tbls = v4->ac_cur_tbls;
  MCU_membership = cinfo->MCU_membership;
  v46 = v4->ac_cur_tbls;
  while ( 2 )
  {
    v13 = *ac_cur_tbls;
    v14 = *(ac_cur_tbls - 10);
    v43 = (__int16 *)MCU_data[blkn];
    actbl = v13;
    if ( bits_left < 8 )
    {
      if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 0) == 0 )
        return 0;
      bits_left = br_state.bits_left;
      get_buffer = br_state.get_buffer;
      if ( br_state.bits_left < 8 )
      {
        v15 = 1;
label1:
        v18 = jpeg_huff_decode(state: &br_state, get_buffer, bits_left, htbl: v14, min_bits: v15);
        if ( v18 < 0 )
          return 0;
        get_buffer = br_state.get_buffer;
        bits_left = br_state.bits_left;
        goto LABEL_18;
      }
    }
    v16 = (unsigned __int8)(get_buffer >> (bits_left - 8));
    v17 = v14->look_nbits[v16];
    if ( v17 == 0 )
    {
      v15 = 9;
      goto label1;
    }
    v18 = v14->look_sym[v16];
    bits_left -= v17;
LABEL_18:
    if ( v18 != 0 )
    {
      if ( bits_left < v18 )
      {
        if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v18) == 0 )
          return 0;
        get_buffer = br_state.get_buffer;
        bits_left = br_state.bits_left;
      }
      bits_left -= v18;
      v19 = (get_buffer >> bits_left) & ((1 << v18) - 1);
      v13 = actbl;
      if ( v19 >= extend_test[v18] )
        v18 = (get_buffer >> bits_left) & ((1 << v18) - 1);
      else
        v18 = v19 + extend_offset[v18];
    }
    v20 = blkn;
    if ( entropy->dc_needed[blkn] != 0 )
    {
      v21 = *MCU_membership;
      *((_DWORD *)&block + v21) += v18;
      *v43 = *((_DWORD *)&block + v21);
    }
    if ( entropy->ac_needed[v20] != 0 )
    {
      v22 = 1;
      while ( 1 )
      {
        if ( bits_left < 8 )
        {
          if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 0) == 0 )
            return 0;
          bits_left = br_state.bits_left;
          get_buffer = br_state.get_buffer;
          if ( br_state.bits_left < 8 )
            break;
        }
        v23 = actbl;
        v25 = (unsigned __int8)(get_buffer >> (bits_left - 8));
        v26 = actbl->look_nbits[v25];
        if ( v26 == 0 )
        {
          v24 = 9;
          goto label2;
        }
        v27 = actbl->look_sym[v25];
        bits_left -= v26;
LABEL_38:
        v28 = v27 >> 4;
        v29 = v27 & 0xF;
        if ( v29 != 0 )
        {
          k = v28 + v22;
          if ( bits_left < v29 )
          {
            if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v29) == 0 )
              return 0;
            get_buffer = br_state.get_buffer;
            bits_left = br_state.bits_left;
          }
          bits_left -= v29;
          v30 = (get_buffer >> bits_left) & ((1 << v29) - 1);
          if ( v30 >= extend_test[v29] )
            v29 = (get_buffer >> bits_left) & ((1 << v29) - 1);
          else
            LOWORD(v29) = v30 + extend_offset[v29];
          v31 = k;
          v43[jpeg_natural_order[k]] = v29;
        }
        else
        {
          if ( v28 != 15 )
            goto LABEL_68;
          v31 = v22 + 15;
        }
        v22 = v31 + 1;
        if ( v22 >= 64 )
          goto LABEL_68;
      }
      v23 = actbl;
      v24 = 1;
label2:
      v27 = jpeg_huff_decode(state: &br_state, get_buffer, bits_left, htbl: v23, min_bits: v24);
      if ( v27 < 0 )
        return 0;
      get_buffer = br_state.get_buffer;
      bits_left = br_state.bits_left;
      goto LABEL_38;
    }
    for ( k = 1; k < 64; ++k )
    {
      if ( bits_left >= 8 )
        goto LABEL_55;
      if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 0) == 0 )
        return 0;
      bits_left = br_state.bits_left;
      get_buffer = br_state.get_buffer;
      if ( br_state.bits_left >= 8 )
      {
LABEL_55:
        v33 = (unsigned __int8)(get_buffer >> (bits_left - 8));
        v34 = v13->look_nbits[v33];
        if ( v34 != 0 )
        {
          v35 = v13->look_sym[v33];
          bits_left -= v34;
          goto LABEL_60;
        }
        v32 = 9;
      }
      else
      {
        v32 = 1;
      }
      v35 = jpeg_huff_decode(state: &br_state, get_buffer, bits_left, htbl: v13, min_bits: v32);
      if ( v35 < 0 )
        return 0;
      get_buffer = br_state.get_buffer;
      bits_left = br_state.bits_left;
LABEL_60:
      v36 = v35 >> 4;
      v37 = v35 & 0xF;
      if ( v37 != 0 )
      {
        k += v36;
        if ( bits_left < v37 )
        {
          if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v37) == 0 )
            return 0;
          get_buffer = br_state.get_buffer;
          bits_left = br_state.bits_left;
        }
        bits_left -= v37;
      }
      else
      {
        if ( v36 != 15 )
          break;
        k += 15;
      }
    }
LABEL_68:
    ++v46;
    ++MCU_membership;
    if ( ++blkn < cinfo->blocks_in_MCU )
    {
      ac_cur_tbls = v46;
      continue;
    }
    break;
  }
  v4 = entropy;
  v2 = cinfo;
LABEL_70:
  v38 = block;
  v2->src->next_input_byte = br_state.next_input_byte;
  v2->src->bytes_in_buffer = br_state.bytes_in_buffer;
  *(_QWORD *)&v4->saved.EOBRUN = v38;
  v39 = v42;
  v4->bitstate.get_buffer = get_buffer;
  v4->bitstate.bits_left = bits_left;
  *(_QWORD *)&v4->gap0[8] = v39;
LABEL_71:
  --v4->saved.last_dc_val[3];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000EE30
// Name: start_pass_huff_decoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_huff_decoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_decoder *err; // edi
  unsigned int ac_tbl_no; // ebx
  unsigned __int8 *v4; // ecx
  unsigned __int8 (__cdecl **p_decode_mcu)(jpeg_decompress_struct *, __int16 (**)[64]); // edx
  jpeg_component_info *v6; // eax
  unsigned __int8 *p_insufficient_data; // [esp+Ch] [ebp-8h]
  int ci; // [esp+10h] [ebp-4h]
  jpeg_component_info **cinfoa; // [esp+1Ch] [ebp+8h]
  int *cinfob; // [esp+1Ch] [ebp+8h]

  err = (jpeg_entropy_decoder *)cinfo[17].err;
  if ( cinfo[15].mem != nullptr
    || cinfo[15].progress != (jpeg_progress_mgr *)63
    || cinfo[15].client_data != nullptr
    || *(_DWORD *)&cinfo[15].is_decompressor != 0 )
  {
    cinfo->err->msg_code = 122;
    cinfo->err->emit_message(a1: cinfo, a2: -1);
  }
  ci = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    p_insufficient_data = &err[1].insufficient_data;
    cinfoa = (jpeg_component_info **)&cinfo[12].progress;
    do
    {
      ac_tbl_no = (*cinfoa)->ac_tbl_no;
      jpeg_make_d_derived_tbl(
        cinfo,
        isDC: 1u,
        tblno: (*cinfoa)->dc_tbl_no,
        pdtbl: (d_derived_tbl **)&err[3].decode_mcu + (*cinfoa)->dc_tbl_no);
      jpeg_make_d_derived_tbl(
        cinfo,
        isDC: 0,
        tblno: ac_tbl_no,
        pdtbl: (d_derived_tbl **)&err[4].insufficient_data + ac_tbl_no);
      ++cinfoa;
      *(_DWORD *)p_insufficient_data = 0;
      ++ci;
      p_insufficient_data += 4;
    }
    while ( ci < (int)cinfo[12].mem );
  }
  if ( (int)cinfo[13].progress > 0 )
  {
    cinfob = (int *)&cinfo[13].client_data;
    v4 = &err[12].insufficient_data;
    p_decode_mcu = &err[9].decode_mcu;
    do
    {
      v6 = *((jpeg_component_info **)&cinfo[12].progress + *cinfob);
      *(p_decode_mcu - 10) = *(&err[3].decode_mcu + v6->dc_tbl_no);
      *p_decode_mcu = *((unsigned __int8 (__cdecl **)(jpeg_decompress_struct *, __int16 (**)[64]))&err[4].insufficient_data
                      + v6->ac_tbl_no);
      if ( v6->component_needed != 0 )
      {
        *v4 = 1;
        v4[10] = v6->DCT_scaled_size > 1;
      }
      else
      {
        v4[10] = 0;
        *v4 = 0;
      }
      ++cinfob;
      ++v4;
      ++p_decode_mcu;
    }
    while ( (int)&v4[-152 - (_DWORD)err] < (int)cinfo[13].progress );
  }
  err[1].decode_mcu = nullptr;
  err[1].start_pass = nullptr;
  err->insufficient_data = 0;
  err[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo[10].client_data;
}

//------------------------------------------------------------------------------
// Address: 0x1000EF80
// Name: _jinit_huff_decoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_huff_decoder(jpeg_common_struct *cinfo)
{
  int v1; // eax

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 172);
  cinfo[17].err = (jpeg_error_mgr *)v1;
  *(_DWORD *)v1 = start_pass_huff_decoder;
  *(_DWORD *)(v1 + 4) = decode_mcu;
  *(_DWORD *)(v1 + 56) = 0;
  *(_DWORD *)(v1 + 40) = 0;
  *(_DWORD *)(v1 + 60) = 0;
  *(_DWORD *)(v1 + 44) = 0;
  *(_DWORD *)(v1 + 64) = 0;
  *(_DWORD *)(v1 + 48) = 0;
  *(_DWORD *)(v1 + 68) = 0;
  *(_DWORD *)(v1 + 52) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000EFD0
// Name: process_restart_0
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall process_restart_0@<al>(jpeg_decompress_struct *cinfo@<esi>)
{
  jpeg_entropy_decoder *entropy; // edi
  unsigned __int8 result; // al
  int v3; // eax
  jpeg_entropy_decoder *v4; // ecx

  entropy = cinfo->entropy;
  cinfo->marker->discarded_bytes += (int)entropy[1].decode_mcu / 8;
  entropy[1].decode_mcu = nullptr;
  result = ((int (*)(void))cinfo->marker->read_restart_marker)();
  if ( result != 0 )
  {
    v3 = 0;
    if ( cinfo->comps_in_scan > 0 )
    {
      v4 = entropy + 2;
      do
      {
        v4->start_pass = nullptr;
        ++v3;
        v4 = (jpeg_entropy_decoder *)((char *)v4 + 4);
      }
      while ( v3 < cinfo->comps_in_scan );
    }
    *(_DWORD *)&entropy[1].insufficient_data = 0;
    entropy[3].decode_mcu = (unsigned __int8 (__cdecl *)(jpeg_decompress_struct *, __int16 (**)[64]))cinfo->restart_interval;
    if ( cinfo->unread_marker == 0 )
      entropy->insufficient_data = 0;
    return 1;
  }
  return result;
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10277290
// Name: _jpeg_make_d_derived_tbl
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_make_d_derived_tbl(
        jpeg_common_struct *cinfo,
        unsigned __int8 isDC,
        unsigned int tblno,
        d_derived_tbl **pdtbl)
{
  JHUFF_TBL *v5; // esi
  int v7; // edi
  int v8; // ebx
  unsigned int v9; // esi
  int v10; // ebx
  signed int v11; // esi
  int v12; // edi
  signed int v13; // edx
  char *v14; // eax
  int v15; // eax
  bool v16; // zf
  int v17; // ecx
  int i; // eax
  int v19; // esi
  char v20; // cl
  int v21; // ebx
  int v22; // eax
  unsigned __int8 *v23; // edi
  unsigned int v24; // edx
  unsigned __int8 *v25; // esi
  int *v26; // edx
  int v27; // ecx
  int v28; // edi
  int k; // esi
  unsigned int huffcode[257]; // [esp+Ch] [ebp-51Ch]
  char huffsize[260]; // [esp+410h] [ebp-118h] BYREF
  int numsymbols; // [esp+514h] [ebp-14h]
  int v34; // [esp+518h] [ebp-10h]
  int v35; // [esp+51Ch] [ebp-Ch]
  int p; // [esp+520h] [ebp-8h]
  int j; // [esp+524h] [ebp-4h]
  JHUFF_TBL *htbl; // [esp+538h] [ebp+10h]
  d_derived_tbl *dtbl; // [esp+53Ch] [ebp+14h]

  if ( tblno >= 4 )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( isDC != 0 )
  {
    v5 = *((JHUFF_TBL **)&cinfo[6].is_decompressor + tblno);
    htbl = v5;
  }
  else
  {
    htbl = *((JHUFF_TBL **)&cinfo[7].progress + tblno);
    v5 = *((JHUFF_TBL **)&cinfo[7].progress + tblno);
  }
  if ( v5 == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *pdtbl == nullptr )
    *pdtbl = (d_derived_tbl *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1424);
  v7 = 0;
  dtbl = *pdtbl;
  (*pdtbl)->pub = v5;
  v8 = 1;
  while ( 1 )
  {
    v9 = v5->bits[v8];
    if ( (int)(v9 + v7) > 256 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v9 != 0 )
    {
      memset(dst: (int)&huffsize[v7], value: (unsigned __int8 *)v8, count: v9);
      v7 += v9;
    }
    if ( ++v8 > 16 )
      break;
    v5 = htbl;
  }
  huffsize[v7] = 0;
  v10 = huffsize[0];
  numsymbols = v7;
  v11 = 0;
  v12 = 0;
  v13 = __ROL4__(1, huffsize[0]);
  j = v13;
  if ( huffsize[0] != 0 )
  {
    v14 = huffsize;
    while ( 1 )
    {
      if ( *v14 == v10 )
      {
        do
        {
          v15 = huffsize[v12 + 1];
          huffcode[v12++] = v11++;
        }
        while ( v15 == v10 );
      }
      if ( v11 >= v13 )
      {
        cinfo->err->msg_code = 8;
        cinfo->err->error_exit(a1: cinfo);
        v13 = j;
      }
      v11 *= 2;
      ++v10;
      v16 = huffsize[v12] == 0;
      v14 = &huffsize[v12];
      j = __ROL4__(v13, 1);
      if ( v16 )
        break;
      v13 = j;
    }
  }
  v17 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    if ( htbl->bits[i] != 0 )
    {
      dtbl->valoffset[i] = v17 - huffcode[v17];
      v17 += htbl->bits[i];
      dtbl->maxcode[i] = huffcode[v17 - 1];
    }
    else
    {
      dtbl->maxcode[i] = -1;
    }
  }
  dtbl->maxcode[17] = 0xFFFFF;
  memset(dst: (int)dtbl->look_nbits, value: nullptr, count: sizeof(dtbl->look_nbits));
  v19 = 0;
  v20 = 7;
  p = 0;
  v21 = 1;
  for ( j = 7; j >= 0; --j )
  {
    if ( htbl->bits[v21] != 0 )
    {
      v22 = 1 << v20;
      v35 = 1;
      v23 = &htbl->huffval[v19];
      v34 = 1 << v20;
      do
      {
        v24 = huffcode[v19] << j;
        if ( v22 > 0 )
        {
          v25 = &dtbl->look_sym[v24];
          v26 = &dtbl->look_nbits[v24];
          do
          {
            *v26 = v21;
            *v25 = *v23;
            --v22;
            ++v26;
            ++v25;
          }
          while ( v22 > 0 );
          v19 = p;
          v22 = v34;
        }
        v27 = htbl->bits[v21];
        ++v19;
        ++v23;
        p = v19;
        ++v35;
      }
      while ( v35 <= v27 );
    }
    ++v21;
    v20 = j - 1;
  }
  if ( isDC != 0 )
  {
    v28 = numsymbols;
    for ( k = 0; k < v28; ++k )
    {
      if ( htbl->huffval[k] > 0xFu )
      {
        cinfo->err->msg_code = 8;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277540
// Name: _jpeg_fill_bit_buffer
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl jpeg_fill_bit_buffer(bitread_working_state *state, int get_buffer, int bits_left, int nbits)
{
  bitread_working_state *v4; // eax
  jpeg_decompress_struct *cinfo; // ebx
  const unsigned __int8 *next_input_byte; // esi
  unsigned int bytes_in_buffer; // edi
  jpeg_source_mgr *src; // eax
  int v9; // eax
  jpeg_source_mgr *v10; // eax
  int v11; // eax
  char v13; // cl

  v4 = state;
  cinfo = state->cinfo;
  next_input_byte = state->next_input_byte;
  bytes_in_buffer = state->bytes_in_buffer;
  if ( cinfo->unread_marker != 0 )
    goto no_more_bytes;
  if ( bits_left < 25 )
  {
    while ( 1 )
    {
      if ( bytes_in_buffer == 0 )
      {
        if ( cinfo->src->fill_input_buffer(a1: cinfo) == 0 )
          return 0;
        src = cinfo->src;
        next_input_byte = src->next_input_byte;
        bytes_in_buffer = src->bytes_in_buffer;
      }
      v9 = *next_input_byte;
      --bytes_in_buffer;
      ++next_input_byte;
      if ( v9 == 255 )
      {
        do
        {
          if ( bytes_in_buffer == 0 )
          {
            if ( cinfo->src->fill_input_buffer(a1: cinfo) == 0 )
              return 0;
            v10 = cinfo->src;
            next_input_byte = v10->next_input_byte;
            bytes_in_buffer = v10->bytes_in_buffer;
          }
          v11 = *next_input_byte;
          --bytes_in_buffer;
          ++next_input_byte;
        }
        while ( v11 == 255 );
        if ( v11 != 0 )
        {
          cinfo->unread_marker = v11;
          v4 = state;
no_more_bytes:
          if ( nbits > bits_left )
          {
            if ( cinfo->entropy->insufficient_data == 0 )
            {
              cinfo->err->msg_code = 117;
              cinfo->err->emit_message(a1: (jpeg_common_struct *)cinfo, a2: -1);
              cinfo->entropy->insufficient_data = 1;
            }
            v13 = 25 - bits_left;
            bits_left = 25;
            get_buffer <<= v13;
LABEL_21:
            v4 = state;
          }
          break;
        }
        v9 = 255;
      }
      get_buffer = v9 | (get_buffer << 8);
      bits_left += 8;
      if ( bits_left >= 25 )
        goto LABEL_21;
    }
  }
  v4->bytes_in_buffer = bytes_in_buffer;
  v4->next_input_byte = next_input_byte;
  v4->get_buffer = get_buffer;
  v4->bits_left = bits_left;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10277650
// Name: _jpeg_huff_decode
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_huff_decode(
        bitread_working_state *state,
        int get_buffer,
        int bits_left,
        d_derived_tbl *htbl,
        int min_bits)
{
  int v5; // eax
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  int v10; // esi
  d_derived_tbl *v11; // ebx
  int v12; // esi
  int l; // [esp+8h] [ebp-4h]

  v5 = bits_left;
  l = min_bits;
  if ( bits_left >= min_bits )
  {
    v7 = get_buffer;
  }
  else
  {
    if ( jpeg_fill_bit_buffer(state, get_buffer, bits_left, nbits: min_bits) == 0 )
      return -1;
    v7 = state->get_buffer;
    v5 = state->bits_left;
  }
  v8 = v5 - min_bits;
  v9 = min_bits;
  v10 = ((1 << min_bits) - 1) & (v7 >> v8);
  v11 = htbl;
  if ( v10 > htbl->maxcode[min_bits] )
  {
    do
    {
      v12 = 2 * v10;
      if ( v8 < 1 )
      {
        if ( jpeg_fill_bit_buffer(state, get_buffer: v7, bits_left: v8, nbits: 1) == 0 )
          return -1;
        v7 = state->get_buffer;
        v8 = state->bits_left;
      }
      --v8;
      v9 = l + 1;
      l = v9;
      v10 = (v7 >> v8) & 1 | v12;
      v11 = htbl;
    }
    while ( v10 > htbl->maxcode[v9] );
  }
  state->get_buffer = v7;
  state->bits_left = v8;
  if ( v9 <= 16 )
    return v11->pub->huffval[v11->valoffset[v9] + v10];
  state->cinfo->err->msg_code = 118;
  state->cinfo->err->emit_message(a1: (jpeg_common_struct *)state->cinfo, a2: -1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10277740
// Name: process_restart
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall process_restart@<al>(jpeg_decompress_struct *cinfo@<esi>)
{
  jpeg_entropy_decoder *entropy; // edi
  unsigned __int8 result; // al
  int v3; // eax
  unsigned __int8 *p_insufficient_data; // ecx

  entropy = cinfo->entropy;
  cinfo->marker->discarded_bytes += (int)entropy[1].decode_mcu / 8;
  entropy[1].decode_mcu = nullptr;
  result = ((int (*)(void))cinfo->marker->read_restart_marker)();
  if ( result != 0 )
  {
    v3 = 0;
    if ( cinfo->comps_in_scan > 0 )
    {
      p_insufficient_data = &entropy[1].insufficient_data;
      do
      {
        *(_DWORD *)p_insufficient_data = 0;
        ++v3;
        p_insufficient_data += 4;
      }
      while ( v3 < cinfo->comps_in_scan );
    }
    entropy[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo->restart_interval;
    if ( cinfo->unread_marker == 0 )
      entropy->insufficient_data = 0;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102777C0
// Name: decode_mcu
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl decode_mcu(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_decompress_struct *v2; // ebx
  bool v3; // zf
  huff_entropy_decoder *v4; // edi
  bool v6; // cc
  jpeg_source_mgr *src; // eax
  const unsigned __int8 *next_input_byte; // ecx
  unsigned int bytes_in_buffer; // edx
  int get_buffer; // esi
  int bits_left; // eax
  d_derived_tbl **ac_cur_tbls; // ecx
  d_derived_tbl *v13; // ebx
  d_derived_tbl *v14; // edi
  int v15; // ecx
  int v16; // edx
  int v17; // ecx
  int v18; // edi
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  int v22; // ebx
  d_derived_tbl *v23; // edi
  int v24; // ecx
  int v25; // edx
  int v26; // ecx
  int v27; // edi
  int v28; // ecx
  int v29; // edi
  int v30; // edx
  int v31; // ebx
  int v32; // ecx
  int v33; // edx
  int v34; // ecx
  int v35; // edi
  int v36; // ecx
  int v37; // edi
  __int64 v38; // xmm0_8
  __int64 v39; // xmm0_8
  bitread_working_state br_state; // [esp+Ch] [ebp-40h] BYREF
  __int64 block; // [esp+20h] [ebp-2Ch]
  __int64 v42; // [esp+28h] [ebp-24h]
  __int16 *v43; // [esp+30h] [ebp-1Ch]
  huff_entropy_decoder *entropy; // [esp+34h] [ebp-18h]
  int *MCU_membership; // [esp+38h] [ebp-14h]
  d_derived_tbl **v46; // [esp+3Ch] [ebp-10h]
  int blkn; // [esp+40h] [ebp-Ch]
  d_derived_tbl *actbl; // [esp+44h] [ebp-8h]
  int k; // [esp+48h] [ebp-4h]

  v2 = cinfo;
  v3 = cinfo->restart_interval == 0;
  v4 = (huff_entropy_decoder *)cinfo->entropy;
  entropy = v4;
  if ( !v3 && v4->saved.last_dc_val[3] == 0 && process_restart(cinfo) == 0 )
    return 0;
  if ( v4->pub.insufficient_data != 0 )
    goto LABEL_71;
  v6 = cinfo->blocks_in_MCU <= 0;
  src = cinfo->src;
  next_input_byte = src->next_input_byte;
  bytes_in_buffer = src->bytes_in_buffer;
  get_buffer = v4->bitstate.get_buffer;
  bits_left = v4->bitstate.bits_left;
  block = *(_QWORD *)&v4->saved.EOBRUN;
  br_state.cinfo = cinfo;
  br_state.next_input_byte = next_input_byte;
  br_state.bytes_in_buffer = bytes_in_buffer;
  v42 = *(_QWORD *)&v4->gap0[8];
  blkn = 0;
  if ( v6 )
    goto LABEL_70;
  ac_cur_tbls = v4->ac_cur_tbls;
  MCU_membership = cinfo->MCU_membership;
  v46 = v4->ac_cur_tbls;
  while ( 2 )
  {
    v13 = *ac_cur_tbls;
    v14 = *(ac_cur_tbls - 10);
    v43 = (__int16 *)MCU_data[blkn];
    actbl = v13;
    if ( bits_left < 8 )
    {
      if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 0) == 0 )
        return 0;
      bits_left = br_state.bits_left;
      get_buffer = br_state.get_buffer;
      if ( br_state.bits_left < 8 )
      {
        v15 = 1;
label1:
        v18 = jpeg_huff_decode(state: &br_state, get_buffer, bits_left, htbl: v14, min_bits: v15);
        if ( v18 < 0 )
          return 0;
        get_buffer = br_state.get_buffer;
        bits_left = br_state.bits_left;
        goto LABEL_18;
      }
    }
    v16 = (unsigned __int8)(get_buffer >> (bits_left - 8));
    v17 = v14->look_nbits[v16];
    if ( v17 == 0 )
    {
      v15 = 9;
      goto label1;
    }
    v18 = v14->look_sym[v16];
    bits_left -= v17;
LABEL_18:
    if ( v18 != 0 )
    {
      if ( bits_left < v18 )
      {
        if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v18) == 0 )
          return 0;
        get_buffer = br_state.get_buffer;
        bits_left = br_state.bits_left;
      }
      bits_left -= v18;
      v19 = (get_buffer >> bits_left) & ((1 << v18) - 1);
      v13 = actbl;
      if ( v19 >= extend_test[v18] )
        v18 = (get_buffer >> bits_left) & ((1 << v18) - 1);
      else
        v18 = v19 + extend_offset[v18];
    }
    v20 = blkn;
    if ( entropy->dc_needed[blkn] != 0 )
    {
      v21 = *MCU_membership;
      *((_DWORD *)&block + v21) += v18;
      *v43 = *((_DWORD *)&block + v21);
    }
    if ( entropy->ac_needed[v20] != 0 )
    {
      v22 = 1;
      while ( 1 )
      {
        if ( bits_left < 8 )
        {
          if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 0) == 0 )
            return 0;
          bits_left = br_state.bits_left;
          get_buffer = br_state.get_buffer;
          if ( br_state.bits_left < 8 )
            break;
        }
        v23 = actbl;
        v25 = (unsigned __int8)(get_buffer >> (bits_left - 8));
        v26 = actbl->look_nbits[v25];
        if ( v26 == 0 )
        {
          v24 = 9;
          goto label2;
        }
        v27 = actbl->look_sym[v25];
        bits_left -= v26;
LABEL_38:
        v28 = v27 >> 4;
        v29 = v27 & 0xF;
        if ( v29 != 0 )
        {
          k = v28 + v22;
          if ( bits_left < v29 )
          {
            if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v29) == 0 )
              return 0;
            get_buffer = br_state.get_buffer;
            bits_left = br_state.bits_left;
          }
          bits_left -= v29;
          v30 = (get_buffer >> bits_left) & ((1 << v29) - 1);
          if ( v30 >= extend_test[v29] )
            v29 = (get_buffer >> bits_left) & ((1 << v29) - 1);
          else
            LOWORD(v29) = v30 + extend_offset[v29];
          v31 = k;
          v43[jpeg_natural_order[k]] = v29;
        }
        else
        {
          if ( v28 != 15 )
            goto LABEL_68;
          v31 = v22 + 15;
        }
        v22 = v31 + 1;
        if ( v22 >= 64 )
          goto LABEL_68;
      }
      v23 = actbl;
      v24 = 1;
label2:
      v27 = jpeg_huff_decode(state: &br_state, get_buffer, bits_left, htbl: v23, min_bits: v24);
      if ( v27 < 0 )
        return 0;
      get_buffer = br_state.get_buffer;
      bits_left = br_state.bits_left;
      goto LABEL_38;
    }
    for ( k = 1; k < 64; ++k )
    {
      if ( bits_left >= 8 )
        goto LABEL_55;
      if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 0) == 0 )
        return 0;
      bits_left = br_state.bits_left;
      get_buffer = br_state.get_buffer;
      if ( br_state.bits_left >= 8 )
      {
LABEL_55:
        v33 = (unsigned __int8)(get_buffer >> (bits_left - 8));
        v34 = v13->look_nbits[v33];
        if ( v34 != 0 )
        {
          v35 = v13->look_sym[v33];
          bits_left -= v34;
          goto LABEL_60;
        }
        v32 = 9;
      }
      else
      {
        v32 = 1;
      }
      v35 = jpeg_huff_decode(state: &br_state, get_buffer, bits_left, htbl: v13, min_bits: v32);
      if ( v35 < 0 )
        return 0;
      get_buffer = br_state.get_buffer;
      bits_left = br_state.bits_left;
LABEL_60:
      v36 = v35 >> 4;
      v37 = v35 & 0xF;
      if ( v37 != 0 )
      {
        k += v36;
        if ( bits_left < v37 )
        {
          if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v37) == 0 )
            return 0;
          get_buffer = br_state.get_buffer;
          bits_left = br_state.bits_left;
        }
        bits_left -= v37;
      }
      else
      {
        if ( v36 != 15 )
          break;
        k += 15;
      }
    }
LABEL_68:
    ++v46;
    ++MCU_membership;
    if ( ++blkn < cinfo->blocks_in_MCU )
    {
      ac_cur_tbls = v46;
      continue;
    }
    break;
  }
  v4 = entropy;
  v2 = cinfo;
LABEL_70:
  v38 = block;
  v2->src->next_input_byte = br_state.next_input_byte;
  v2->src->bytes_in_buffer = br_state.bytes_in_buffer;
  *(_QWORD *)&v4->saved.EOBRUN = v38;
  v39 = v42;
  v4->bitstate.get_buffer = get_buffer;
  v4->bitstate.bits_left = bits_left;
  *(_QWORD *)&v4->gap0[8] = v39;
LABEL_71:
  --v4->saved.last_dc_val[3];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10277BA0
// Name: start_pass_huff_decoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_huff_decoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_decoder *err; // edi
  int ac_tbl_no; // ebx
  unsigned __int8 *v4; // ecx
  unsigned __int8 (__cdecl **p_decode_mcu)(jpeg_decompress_struct *, __int16 (**)[64]); // edx
  jpeg_component_info *v6; // eax
  unsigned __int8 *p_insufficient_data; // [esp+Ch] [ebp-8h]
  int ci; // [esp+10h] [ebp-4h]
  jpeg_component_info **cinfoa; // [esp+1Ch] [ebp+8h]
  int *cinfob; // [esp+1Ch] [ebp+8h]

  err = (jpeg_entropy_decoder *)cinfo[17].err;
  if ( cinfo[15].mem != nullptr
    || cinfo[15].progress != (jpeg_progress_mgr *)63
    || cinfo[15].client_data != nullptr
    || *(_DWORD *)&cinfo[15].is_decompressor != 0 )
  {
    cinfo->err->msg_code = 122;
    cinfo->err->emit_message(a1: cinfo, a2: -1);
  }
  ci = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    p_insufficient_data = &err[1].insufficient_data;
    cinfoa = (jpeg_component_info **)&cinfo[12].progress;
    do
    {
      ac_tbl_no = (*cinfoa)->ac_tbl_no;
      jpeg_make_d_derived_tbl(
        (jpeg_decompress_struct *)cinfo,
        isDC: 1u,
        tblno: (*cinfoa)->dc_tbl_no,
        pdtbl: (d_derived_tbl **)&err[3].decode_mcu + (*cinfoa)->dc_tbl_no);
      jpeg_make_d_derived_tbl(
        (jpeg_decompress_struct *)cinfo,
        isDC: 0,
        tblno: ac_tbl_no,
        pdtbl: (d_derived_tbl **)&err[4].insufficient_data + ac_tbl_no);
      ++cinfoa;
      *(_DWORD *)p_insufficient_data = 0;
      ++ci;
      p_insufficient_data += 4;
    }
    while ( ci < (int)cinfo[12].mem );
  }
  if ( (int)cinfo[13].progress > 0 )
  {
    cinfob = (int *)&cinfo[13].client_data;
    v4 = &err[12].insufficient_data;
    p_decode_mcu = &err[9].decode_mcu;
    do
    {
      v6 = *((jpeg_component_info **)&cinfo[12].progress + *cinfob);
      *(p_decode_mcu - 10) = *(&err[3].decode_mcu + v6->dc_tbl_no);
      *p_decode_mcu = *((unsigned __int8 (__cdecl **)(jpeg_decompress_struct *, __int16 (**)[64]))&err[4].insufficient_data
                      + v6->ac_tbl_no);
      if ( v6->component_needed != 0 )
      {
        *v4 = 1;
        v4[10] = v6->DCT_scaled_size > 1;
      }
      else
      {
        v4[10] = 0;
        *v4 = 0;
      }
      ++cinfob;
      ++v4;
      ++p_decode_mcu;
    }
    while ( (int)&v4[-152 - (_DWORD)err] < (int)cinfo[13].progress );
  }
  err[1].decode_mcu = nullptr;
  err[1].start_pass = nullptr;
  err->insufficient_data = 0;
  err[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))cinfo[10].client_data;
}

//------------------------------------------------------------------------------
// Address: 0x10277CF0
// Name: _jinit_huff_decoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_huff_decoder(jpeg_common_struct *cinfo)
{
  int v1; // eax

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 172);
  cinfo[17].err = (jpeg_error_mgr *)v1;
  *(_DWORD *)v1 = start_pass_huff_decoder;
  *(_DWORD *)(v1 + 4) = decode_mcu;
  *(_DWORD *)(v1 + 56) = 0;
  *(_DWORD *)(v1 + 40) = 0;
  *(_DWORD *)(v1 + 60) = 0;
  *(_DWORD *)(v1 + 44) = 0;
  *(_DWORD *)(v1 + 64) = 0;
  *(_DWORD *)(v1 + 48) = 0;
  *(_DWORD *)(v1 + 68) = 0;
  *(_DWORD *)(v1 + 52) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10277D40
// Name: process_restart_0
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall process_restart_0@<al>(jpeg_decompress_struct *cinfo@<esi>)
{
  jpeg_entropy_decoder *entropy; // edi
  unsigned __int8 result; // al
  int v3; // eax
  jpeg_entropy_decoder *v4; // ecx

  entropy = cinfo->entropy;
  cinfo->marker->discarded_bytes += (int)entropy[1].decode_mcu / 8;
  entropy[1].decode_mcu = nullptr;
  result = ((int (*)(void))cinfo->marker->read_restart_marker)();
  if ( result != 0 )
  {
    v3 = 0;
    if ( cinfo->comps_in_scan > 0 )
    {
      v4 = entropy + 2;
      do
      {
        v4->start_pass = nullptr;
        ++v3;
        v4 = (jpeg_entropy_decoder *)((char *)v4 + 4);
      }
      while ( v3 < cinfo->comps_in_scan );
    }
    *(_DWORD *)&entropy[1].insufficient_data = 0;
    entropy[3].decode_mcu = (unsigned __int8 (__cdecl *)(jpeg_decompress_struct *, __int16 (**)[64]))cinfo->restart_interval;
    if ( cinfo->unread_marker == 0 )
      entropy->insufficient_data = 0;
    return 1;
  }
  return result;
}

} // namespace client
