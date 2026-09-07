// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdphuff.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000F050
// Name: decode_mcu_DC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl decode_mcu_DC_first(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_decompress_struct *v2; // esi
  bool v3; // zf
  jpeg_entropy_decoder *entropy; // ebx
  unsigned __int8 result; // al
  bool v6; // cc
  jpeg_source_mgr *src; // eax
  int start_pass; // eax
  int v9; // ecx
  int decode_mcu; // eax
  d_derived_tbl *v11; // edi
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // edi
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  __int64 v19; // xmm0_8
  int v20; // edx
  __int64 v21; // xmm0_8
  int v22; // eax
  savable_state state; // [esp+8h] [ebp-40h]
  bitread_working_state br_state; // [esp+1Ch] [ebp-2Ch] BYREF
  __int16 (*block)[64]; // [esp+30h] [ebp-18h]
  int Al; // [esp+34h] [ebp-14h]
  int ci; // [esp+38h] [ebp-10h]
  int *MCU_membership; // [esp+3Ch] [ebp-Ch]
  int blkn; // [esp+40h] [ebp-8h]
  int get_buffer; // [esp+44h] [ebp-4h]

  v2 = cinfo;
  v3 = cinfo->restart_interval == 0;
  entropy = cinfo->entropy;
  Al = cinfo->Al;
  if ( v3 || entropy[3].decode_mcu != nullptr || (result = process_restart_0(cinfo)) != 0 )
  {
    if ( entropy->insufficient_data == 0 )
    {
      v6 = cinfo->blocks_in_MCU <= 0;
      src = cinfo->src;
      br_state.cinfo = cinfo;
      br_state.next_input_byte = src->next_input_byte;
      br_state.bytes_in_buffer = src->bytes_in_buffer;
      start_pass = (int)entropy[1].start_pass;
      v9 = (int)entropy[3].start_pass;
      *(_QWORD *)&state.EOBRUN = *(_QWORD *)&entropy[1].insufficient_data;
      get_buffer = start_pass;
      decode_mcu = (int)entropy[1].decode_mcu;
      *(_QWORD *)&state.last_dc_val[1] = *(_QWORD *)&entropy[2].decode_mcu;
      state.last_dc_val[3] = v9;
      blkn = 0;
      if ( !v6 )
      {
        MCU_membership = cinfo->MCU_membership;
        do
        {
          block = MCU_data[blkn];
          ci = *MCU_membership;
          v11 = *((d_derived_tbl **)&entropy[3].insufficient_data + v2->cur_comp_info[ci]->dc_tbl_no);
          if ( decode_mcu >= 8 )
            goto LABEL_11;
          if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left: decode_mcu, nbits: 0) == 0 )
            return 0;
          decode_mcu = br_state.bits_left;
          get_buffer = br_state.get_buffer;
          if ( br_state.bits_left >= 8 )
          {
LABEL_11:
            v13 = (unsigned __int8)(get_buffer >> (decode_mcu - 8));
            v14 = v11->look_nbits[v13];
            if ( v14 != 0 )
            {
              v15 = v11->look_sym[v13];
              decode_mcu -= v14;
              goto LABEL_16;
            }
            v12 = 9;
          }
          else
          {
            v12 = 1;
          }
          v15 = jpeg_huff_decode(state: &br_state, get_buffer, bits_left: decode_mcu, htbl: v11, min_bits: v12);
          if ( v15 < 0 )
            return 0;
          decode_mcu = br_state.bits_left;
          get_buffer = br_state.get_buffer;
LABEL_16:
          if ( v15 != 0 )
          {
            if ( decode_mcu < v15 )
            {
              if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left: decode_mcu, nbits: v15) == 0 )
                return 0;
              decode_mcu = br_state.bits_left;
              get_buffer = br_state.get_buffer;
            }
            decode_mcu -= v15;
            v16 = (get_buffer >> decode_mcu) & ((1 << v15) - 1);
            v2 = cinfo;
            if ( v16 >= extend_test_0[v15] )
              v15 = (get_buffer >> decode_mcu) & ((1 << v15) - 1);
            else
              v15 = v16 + extend_offset_0[v15];
          }
          v17 = ci;
          state.last_dc_val[ci] += v15;
          v18 = state.last_dc_val[v17];
          ++MCU_membership;
          *(_WORD *)block = (_WORD)v18 << Al;
          ++blkn;
        }
        while ( blkn < v2->blocks_in_MCU );
      }
      v19 = *(_QWORD *)&state.EOBRUN;
      v2->src->next_input_byte = br_state.next_input_byte;
      v2->src->bytes_in_buffer = br_state.bytes_in_buffer;
      v20 = get_buffer;
      *(_QWORD *)&entropy[1].insufficient_data = v19;
      v21 = *(_QWORD *)&state.last_dc_val[1];
      entropy[1].decode_mcu = (unsigned __int8 (__cdecl *)(jpeg_decompress_struct *, __int16 (**)[64]))decode_mcu;
      v22 = state.last_dc_val[3];
      *(_QWORD *)&entropy[2].decode_mcu = v21;
      entropy[1].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))v20;
      entropy[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))v22;
    }
    --entropy[3].decode_mcu;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F260
// Name: decode_mcu_AC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl decode_mcu_AC_first(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_decompress_struct *v2; // esi
  bool v3; // zf
  int v4; // eax
  int Al; // ecx
  phuff_entropy_decoder *v6; // edi
  unsigned __int8 result; // al
  unsigned int v8; // eax
  jpeg_source_mgr *src; // eax
  __int16 *v10; // edx
  int get_buffer; // ebx
  int bits_left; // eax
  int Ss; // ecx
  d_derived_tbl *v14; // esi
  int v15; // ecx
  int v16; // edx
  int v17; // ecx
  int v18; // edi
  int v19; // esi
  int v20; // edi
  int v21; // edx
  int v22; // edi
  unsigned int v23; // eax
  bitread_working_state br_state; // [esp+8h] [ebp-30h] BYREF
  __int16 (*block)[64]; // [esp+1Ch] [ebp-1Ch]
  int v26; // [esp+20h] [ebp-18h]
  unsigned int EOBRUN; // [esp+24h] [ebp-14h]
  phuff_entropy_decoder *entropy; // [esp+28h] [ebp-10h]
  int Se; // [esp+2Ch] [ebp-Ch]
  d_derived_tbl *tbl; // [esp+30h] [ebp-8h]
  int k; // [esp+34h] [ebp-4h]

  v2 = cinfo;
  v3 = cinfo->restart_interval == 0;
  v4 = cinfo->Se;
  Al = cinfo->Al;
  v6 = (phuff_entropy_decoder *)cinfo->entropy;
  entropy = v6;
  Se = v4;
  v26 = Al;
  if ( !v3 && v6->restarts_to_go == 0 )
  {
    result = process_restart_0(cinfo);
    if ( result == 0 )
      return result;
  }
  if ( v6->pub.insufficient_data != 0 )
    goto LABEL_38;
  v8 = v6->saved.EOBRUN;
  EOBRUN = v8;
  if ( v8 != 0 )
  {
    --v6->restarts_to_go;
    v6->saved.EOBRUN = v8 - 1;
    return 1;
  }
  src = cinfo->src;
  br_state.cinfo = cinfo;
  br_state.next_input_byte = src->next_input_byte;
  v10 = (__int16 *)*MCU_data;
  br_state.bytes_in_buffer = src->bytes_in_buffer;
  get_buffer = v6->bitstate.get_buffer;
  bits_left = v6->bitstate.bits_left;
  tbl = v6->ac_derived_tbl;
  Ss = cinfo->Ss;
  block = (__int16 (*)[64])v10;
  k = Ss;
  if ( Ss > Se )
    goto LABEL_37;
  while ( 1 )
  {
    if ( bits_left >= 8 )
      goto LABEL_12;
    if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 0) == 0 )
      return 0;
    bits_left = br_state.bits_left;
    get_buffer = br_state.get_buffer;
    if ( br_state.bits_left >= 8 )
    {
LABEL_12:
      v14 = tbl;
      v16 = (unsigned __int8)(get_buffer >> (bits_left - 8));
      v17 = tbl->look_nbits[v16];
      if ( v17 != 0 )
      {
        v18 = tbl->look_sym[v16];
        bits_left -= v17;
        goto LABEL_17;
      }
      v15 = 9;
    }
    else
    {
      v14 = tbl;
      v15 = 1;
    }
    v18 = jpeg_huff_decode(state: &br_state, get_buffer, bits_left, htbl: v14, min_bits: v15);
    if ( v18 < 0 )
      return 0;
    get_buffer = br_state.get_buffer;
    bits_left = br_state.bits_left;
LABEL_17:
    v19 = v18 >> 4;
    v20 = v18 & 0xF;
    if ( v20 != 0 )
    {
      k += v19;
      if ( bits_left < v20 )
      {
        if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v20) == 0 )
          return 0;
        get_buffer = br_state.get_buffer;
        bits_left = br_state.bits_left;
      }
      bits_left -= v20;
      v21 = (get_buffer >> bits_left) & ((1 << v20) - 1);
      if ( v21 >= extend_test_0[v20] )
        v20 = (get_buffer >> bits_left) & ((1 << v20) - 1);
      else
        LOWORD(v20) = v21 + extend_offset_0[v20];
      (*block)[jpeg_natural_order[k]] = (_WORD)v20 << v26;
      goto LABEL_27;
    }
    if ( v19 != 15 )
      break;
    k += 15;
LABEL_27:
    if ( ++k > Se )
      goto LABEL_36;
  }
  v22 = 1 << v19;
  if ( v19 != 0 )
  {
    if ( bits_left < v19 )
    {
      if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v19) == 0 )
        return 0;
      get_buffer = br_state.get_buffer;
      bits_left = br_state.bits_left;
    }
    bits_left -= v19;
    v22 += (v22 - 1) & (get_buffer >> bits_left);
  }
  EOBRUN = v22 - 1;
LABEL_36:
  v2 = cinfo;
  v6 = entropy;
LABEL_37:
  v2->src->next_input_byte = br_state.next_input_byte;
  v2->src->bytes_in_buffer = br_state.bytes_in_buffer;
  v6->bitstate.bits_left = bits_left;
  v23 = EOBRUN;
  v6->bitstate.get_buffer = get_buffer;
  v6->saved.EOBRUN = v23;
LABEL_38:
  --v6->restarts_to_go;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000F480
// Name: decode_mcu_DC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl decode_mcu_DC_refine(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  bool v3; // zf
  jpeg_entropy_decoder *entropy; // edi
  unsigned __int8 result; // al
  jpeg_source_mgr *src; // eax
  int start_pass; // eax
  int decode_mcu; // ecx
  int v9; // ebx
  bitread_working_state br_state; // [esp+8h] [ebp-1Ch] BYREF
  __int16 (*block)[64]; // [esp+1Ch] [ebp-8h]
  int p1; // [esp+20h] [ebp-4h]
  int get_buffer; // [esp+2Ch] [ebp+8h]

  v3 = cinfo->restart_interval == 0;
  entropy = cinfo->entropy;
  p1 = 1 << cinfo->Al;
  if ( v3 || entropy[3].decode_mcu != nullptr || (result = process_restart_0(cinfo)) != 0 )
  {
    src = cinfo->src;
    br_state.cinfo = cinfo;
    br_state.next_input_byte = src->next_input_byte;
    br_state.bytes_in_buffer = src->bytes_in_buffer;
    start_pass = (int)entropy[1].start_pass;
    decode_mcu = (int)entropy[1].decode_mcu;
    v9 = 0;
    get_buffer = start_pass;
    if ( cinfo->blocks_in_MCU <= 0 )
    {
LABEL_11:
      cinfo->src->next_input_byte = br_state.next_input_byte;
      cinfo->src->bytes_in_buffer = br_state.bytes_in_buffer;
      --entropy[3].decode_mcu;
      entropy[1].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))start_pass;
      entropy[1].decode_mcu = (unsigned __int8 (__cdecl *)(jpeg_decompress_struct *, __int16 (**)[64]))decode_mcu;
      return 1;
    }
    while ( 1 )
    {
      block = MCU_data[v9];
      if ( decode_mcu < 1 )
      {
        if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer: start_pass, bits_left: decode_mcu, nbits: 1) == 0 )
          return 0;
        start_pass = br_state.get_buffer;
        decode_mcu = br_state.bits_left;
        get_buffer = br_state.get_buffer;
      }
      if ( ((start_pass >> --decode_mcu) & 1) != 0 )
      {
        *(_WORD *)block |= p1;
        start_pass = get_buffer;
      }
      if ( ++v9 >= cinfo->blocks_in_MCU )
        goto LABEL_11;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F560
// Name: decode_mcu_AC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl decode_mcu_AC_refine(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_decompress_struct *v2; // esi
  int Al; // ecx
  phuff_entropy_decoder *v4; // edx
  bool v5; // zf
  unsigned __int8 result; // al
  phuff_entropy_decoder *v7; // ecx
  jpeg_source_mgr *src; // eax
  __int16 *v9; // edx
  unsigned int v10; // eax
  int get_buffer; // ebx
  int bits_left; // edi
  int Ss; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // eax
  __int16 *v19; // esi
  __int16 v20; // ax
  __int16 v21; // ax
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int i; // eax
  int v26; // eax
  __int16 *v27; // eax
  __int16 v28; // ax
  __int16 v29; // ax
  unsigned int v30; // eax
  int j; // eax
  int v32; // edx
  int newnz_pos[64]; // [esp+4h] [ebp-140h]
  d_derived_tbl *tbl; // [esp+104h] [ebp-40h]
  phuff_entropy_decoder *entropy; // [esp+108h] [ebp-3Ch]
  int p1; // [esp+10Ch] [ebp-38h]
  int num_newnz; // [esp+110h] [ebp-34h]
  int m1; // [esp+114h] [ebp-30h]
  bitread_working_state br_state; // [esp+118h] [ebp-2Ch] BYREF
  __int16 (*block)[64]; // [esp+12Ch] [ebp-18h]
  int r; // [esp+130h] [ebp-14h]
  int Se; // [esp+134h] [ebp-10h]
  int s; // [esp+138h] [ebp-Ch]
  unsigned int EOBRUN; // [esp+13Ch] [ebp-8h]
  int k; // [esp+140h] [ebp-4h]
  __int16 *thiscoef; // [esp+14Ch] [ebp+8h]

  v2 = cinfo;
  Al = cinfo->Al;
  v4 = (phuff_entropy_decoder *)cinfo->entropy;
  Se = cinfo->Se;
  entropy = v4;
  p1 = 1 << Al;
  v5 = cinfo->restart_interval == 0;
  m1 = -1 << Al;
  if ( !v5 && v4->restarts_to_go == 0 )
  {
    result = process_restart_0(cinfo);
    if ( result == 0 )
      return result;
  }
  v7 = entropy;
  if ( entropy->pub.insufficient_data != 0 )
  {
LABEL_63:
    --v7->restarts_to_go;
    return 1;
  }
  src = cinfo->src;
  br_state.cinfo = cinfo;
  br_state.next_input_byte = src->next_input_byte;
  v9 = (__int16 *)*MCU_data;
  br_state.bytes_in_buffer = src->bytes_in_buffer;
  v10 = entropy->saved.EOBRUN;
  get_buffer = entropy->bitstate.get_buffer;
  bits_left = entropy->bitstate.bits_left;
  tbl = entropy->ac_derived_tbl;
  Ss = cinfo->Ss;
  EOBRUN = v10;
  block = (__int16 (*)[64])v9;
  num_newnz = 0;
  k = Ss;
  if ( v10 != 0 )
  {
LABEL_48:
    if ( EOBRUN != 0 )
    {
      for ( i = k; i <= Se; k = i )
      {
        v26 = jpeg_natural_order[i];
        v5 = (*block)[v26] == 0;
        v27 = &(*block)[v26];
        thiscoef = v27;
        if ( !v5 )
        {
          if ( bits_left < 1 )
          {
            if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 1) == 0 )
              goto undoit;
            get_buffer = br_state.get_buffer;
            bits_left = br_state.bits_left;
            v27 = thiscoef;
          }
          if ( ((get_buffer >> --bits_left) & 1) != 0 )
          {
            v28 = *v27;
            if ( (v28 & p1) == 0 )
            {
              if ( v28 < 0 )
                v29 = m1 + v28;
              else
                v29 = p1 + v28;
              *thiscoef = v29;
            }
          }
        }
        i = k + 1;
      }
      --EOBRUN;
    }
    goto LABEL_62;
  }
  if ( Ss > Se )
  {
LABEL_62:
    v2->src->next_input_byte = br_state.next_input_byte;
    v30 = EOBRUN;
    v2->src->bytes_in_buffer = br_state.bytes_in_buffer;
    v7 = entropy;
    entropy->bitstate.get_buffer = get_buffer;
    v7->bitstate.bits_left = bits_left;
    v7->saved.EOBRUN = v30;
    goto LABEL_63;
  }
  while ( 1 )
  {
    if ( bits_left >= 8 )
      goto LABEL_11;
    if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 0) == 0 )
      goto undoit;
    bits_left = br_state.bits_left;
    get_buffer = br_state.get_buffer;
    if ( br_state.bits_left >= 8 )
    {
LABEL_11:
      v15 = (unsigned __int8)(get_buffer >> (bits_left - 8));
      v16 = tbl->look_nbits[v15];
      if ( v16 != 0 )
      {
        bits_left -= v16;
        s = tbl->look_sym[v15];
        goto LABEL_16;
      }
      v14 = 9;
    }
    else
    {
      v14 = 1;
    }
    s = jpeg_huff_decode(state: &br_state, get_buffer, bits_left, htbl: tbl, min_bits: v14);
    if ( s < 0 )
      goto undoit;
    get_buffer = br_state.get_buffer;
    bits_left = br_state.bits_left;
LABEL_16:
    v17 = s >> 4;
    v18 = s & 0xF;
    r = s >> 4;
    s = v18;
    if ( v18 == 0 )
      break;
    if ( v18 != 1 )
    {
      cinfo->err->msg_code = 118;
      cinfo->err->emit_message(a1: (jpeg_common_struct *)cinfo, a2: -1);
    }
    if ( bits_left < 1 )
    {
      if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 1) == 0 )
        goto undoit;
      get_buffer = br_state.get_buffer;
      bits_left = br_state.bits_left;
    }
    if ( ((get_buffer >> --bits_left) & 1) != 0 )
      s = p1;
    else
      s = m1;
    do
    {
LABEL_26:
      v19 = &(*block)[jpeg_natural_order[k]];
      if ( *v19 != 0 )
      {
        if ( bits_left < 1 )
        {
          if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 1) == 0 )
            goto undoit;
          get_buffer = br_state.get_buffer;
          bits_left = br_state.bits_left;
        }
        if ( ((get_buffer >> --bits_left) & 1) != 0 )
        {
          v20 = *v19;
          if ( (*v19 & p1) == 0 )
          {
            if ( v20 < 0 )
              v21 = m1 + v20;
            else
              v21 = p1 + v20;
            *v19 = v21;
          }
        }
      }
      else if ( --r < 0 )
      {
        break;
      }
      ++k;
    }
    while ( k <= Se );
    if ( s != 0 )
    {
      v22 = jpeg_natural_order[k];
      (*block)[v22] = s;
      v23 = num_newnz;
      newnz_pos[num_newnz] = v22;
      num_newnz = v23 + 1;
    }
    if ( ++k > Se )
    {
      v2 = cinfo;
      goto LABEL_62;
    }
  }
  if ( v17 == 15 )
    goto LABEL_26;
  v24 = 1 << v17;
  r = 1 << v17;
  EOBRUN = 1 << v17;
  if ( v17 == 0 )
    goto LABEL_47;
  if ( bits_left >= v17 )
    goto LABEL_46;
  if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v17) != 0 )
  {
    get_buffer = br_state.get_buffer;
    bits_left = br_state.bits_left;
    v24 = r;
LABEL_46:
    bits_left -= v17;
    EOBRUN += (v24 - 1) & (get_buffer >> bits_left);
LABEL_47:
    v2 = cinfo;
    goto LABEL_48;
  }
undoit:
  for ( j = num_newnz; j > 0; (*block)[v32] = 0 )
    v32 = newnz_pos[--j];
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F8F0
// Name: start_pass_phuff_decoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_phuff_decoder(jpeg_common_struct *cinfo)
{
  int mem; // eax
  jpeg_entropy_decoder *err; // ebx
  char v4; // cl
  bool v5; // zf
  int progress; // edx
  int client_data; // eax
  int component_index; // ecx
  int *v9; // ebx
  int i; // edi
  jpeg_component_info *v11; // eax
  unsigned int ac_tbl_no; // eax
  d_derived_tbl **v13; // edi
  phuff_entropy_decoder *entropy; // [esp+Ch] [ebp-10h]
  int cindex; // [esp+10h] [ebp-Ch]
  jpeg_entropy_decoder *cindexa; // [esp+10h] [ebp-Ch]
  jpeg_component_info **p_progress; // [esp+14h] [ebp-8h]
  jpeg_component_info **v18; // [esp+14h] [ebp-8h]
  int ci; // [esp+18h] [ebp-4h]
  int cia; // [esp+18h] [ebp-4h]
  bool is_DC_band_3; // [esp+27h] [ebp+Bh]

  mem = (int)cinfo[15].mem;
  err = (jpeg_entropy_decoder *)cinfo[17].err;
  v4 = 0;
  entropy = (phuff_entropy_decoder *)err;
  is_DC_band_3 = mem == 0;
  if ( mem != 0 )
  {
    progress = (int)cinfo[15].progress;
    if ( mem > progress || progress >= 64 )
      v4 = 1;
    v5 = cinfo[12].mem == (jpeg_memory_mgr *)1;
  }
  else
  {
    v5 = cinfo[15].progress == nullptr;
  }
  if ( !v5 )
    v4 = 1;
  client_data = (int)cinfo[15].client_data;
  if ( client_data != 0 && *(_DWORD *)&cinfo[15].is_decompressor != client_data - 1 )
    v4 = 1;
  if ( *(int *)&cinfo[15].is_decompressor > 13 || v4 != 0 )
  {
    cinfo->err->msg_code = 16;
    cinfo->err->msg_parm.i[0] = (int)cinfo[15].mem;
    cinfo->err->msg_parm.i[1] = (int)cinfo[15].progress;
    cinfo->err->msg_parm.i[2] = (int)cinfo[15].client_data;
    cinfo->err->msg_parm.i[3] = *(_DWORD *)&cinfo[15].is_decompressor;
    cinfo->err->error_exit(a1: cinfo);
  }
  ci = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    p_progress = (jpeg_component_info **)&cinfo[12].progress;
    do
    {
      component_index = (*p_progress)->component_index;
      v9 = (int *)(cinfo[5].global_state + (component_index << 8));
      cindex = component_index;
      if ( !is_DC_band_3 && *v9 < 0 )
      {
        cinfo->err->msg_code = 115;
        cinfo->err->msg_parm.i[0] = component_index;
        cinfo->err->msg_parm.i[1] = 0;
        cinfo->err->emit_message(a1: cinfo, a2: -1);
        component_index = cindex;
      }
      for ( i = (int)cinfo[15].mem; i <= (int)cinfo[15].progress; ++i )
      {
        if ( cinfo[15].client_data != (void *)(v9[i] < 0 ? 0 : v9[i]) )
        {
          cinfo->err->msg_code = 115;
          cinfo->err->msg_parm.i[0] = component_index;
          cinfo->err->msg_parm.i[1] = i;
          cinfo->err->emit_message(a1: cinfo, a2: -1);
          component_index = cindex;
        }
        v9[i] = *(_DWORD *)&cinfo[15].is_decompressor;
      }
      ++p_progress;
      ++ci;
    }
    while ( ci < (int)cinfo[12].mem );
    err = &entropy->pub;
  }
  if ( cinfo[15].client_data != nullptr )
  {
    if ( is_DC_band_3 )
      err->decode_mcu = decode_mcu_DC_refine;
    else
      err->decode_mcu = decode_mcu_AC_refine;
  }
  else if ( is_DC_band_3 )
  {
    err->decode_mcu = decode_mcu_DC_first;
  }
  else
  {
    err->decode_mcu = decode_mcu_AC_first;
  }
  cia = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    cindexa = err + 2;
    v18 = (jpeg_component_info **)&cinfo[12].progress;
    do
    {
      v11 = *v18;
      if ( is_DC_band_3 )
      {
        if ( cinfo[15].client_data == nullptr )
          jpeg_make_d_derived_tbl(
            cinfo,
            isDC: 1u,
            tblno: v11->dc_tbl_no,
            pdtbl: (d_derived_tbl **)&err[3].insufficient_data + v11->dc_tbl_no);
      }
      else
      {
        ac_tbl_no = v11->ac_tbl_no;
        v13 = (d_derived_tbl **)(&err[3].insufficient_data + 4 * ac_tbl_no);
        jpeg_make_d_derived_tbl(cinfo, isDC: 0, tblno: ac_tbl_no, pdtbl: v13);
        err[5].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))*v13;
      }
      ++v18;
      cindexa->start_pass = nullptr;
      ++cia;
      cindexa = (jpeg_entropy_decoder *)((char *)cindexa + 4);
    }
    while ( cia < (int)cinfo[12].mem );
  }
  err[1].decode_mcu = nullptr;
  err[1].start_pass = nullptr;
  *(_DWORD *)&err[1].insufficient_data = 0;
  err->insufficient_data = 0;
  err[3].decode_mcu = (unsigned __int8 (__cdecl *)(jpeg_decompress_struct *, __int16 (**)[64]))cinfo[10].client_data;
}

//------------------------------------------------------------------------------
// Address: 0x1000FB50
// Name: _jinit_phuff_decoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_phuff_decoder(jpeg_common_struct *cinfo)
{
  int v1; // eax
  int v2; // ebx
  int *v3; // eax
  int *i; // edx

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[17].err = (jpeg_error_mgr *)v1;
  *(_DWORD *)v1 = start_pass_phuff_decoder;
  v2 = 0;
  *(_DWORD *)(v1 + 44) = 0;
  *(_DWORD *)(v1 + 48) = 0;
  *(_DWORD *)(v1 + 52) = 0;
  *(_DWORD *)(v1 + 56) = 0;
  v3 = (int *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: (int)cinfo[1].client_data << 8);
  cinfo[5].global_state = (int)v3;
  for ( i = v3; v2 < (int)cinfo[1].client_data; i += 64 )
  {
    ++v2;
    memset(i, 0xFFu, 0x100u);
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10277DC0
// Name: decode_mcu_DC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl decode_mcu_DC_first(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_decompress_struct *v2; // esi
  bool v3; // zf
  jpeg_entropy_decoder *entropy; // ebx
  unsigned __int8 result; // al
  bool v6; // cc
  jpeg_source_mgr *src; // eax
  int start_pass; // eax
  int v9; // ecx
  int decode_mcu; // eax
  d_derived_tbl *v11; // edi
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // edi
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  __int64 v19; // xmm0_8
  int v20; // edx
  __int64 v21; // xmm0_8
  int v22; // eax
  savable_state state; // [esp+8h] [ebp-40h]
  bitread_working_state br_state; // [esp+1Ch] [ebp-2Ch] BYREF
  __int16 (*block)[64]; // [esp+30h] [ebp-18h]
  int Al; // [esp+34h] [ebp-14h]
  int ci; // [esp+38h] [ebp-10h]
  int *MCU_membership; // [esp+3Ch] [ebp-Ch]
  int blkn; // [esp+40h] [ebp-8h]
  int get_buffer; // [esp+44h] [ebp-4h]

  v2 = cinfo;
  v3 = cinfo->restart_interval == 0;
  entropy = cinfo->entropy;
  Al = cinfo->Al;
  if ( v3 || entropy[3].decode_mcu != nullptr || (result = process_restart_0(cinfo)) != 0 )
  {
    if ( entropy->insufficient_data == 0 )
    {
      v6 = cinfo->blocks_in_MCU <= 0;
      src = cinfo->src;
      br_state.cinfo = cinfo;
      br_state.next_input_byte = src->next_input_byte;
      br_state.bytes_in_buffer = src->bytes_in_buffer;
      start_pass = (int)entropy[1].start_pass;
      v9 = (int)entropy[3].start_pass;
      *(_QWORD *)&state.EOBRUN = *(_QWORD *)&entropy[1].insufficient_data;
      get_buffer = start_pass;
      decode_mcu = (int)entropy[1].decode_mcu;
      *(_QWORD *)&state.last_dc_val[1] = *(_QWORD *)&entropy[2].decode_mcu;
      state.last_dc_val[3] = v9;
      blkn = 0;
      if ( !v6 )
      {
        MCU_membership = cinfo->MCU_membership;
        do
        {
          block = MCU_data[blkn];
          ci = *MCU_membership;
          v11 = *((d_derived_tbl **)&entropy[3].insufficient_data + v2->cur_comp_info[ci]->dc_tbl_no);
          if ( decode_mcu >= 8 )
            goto LABEL_11;
          if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left: decode_mcu, nbits: 0) == 0 )
            return 0;
          decode_mcu = br_state.bits_left;
          get_buffer = br_state.get_buffer;
          if ( br_state.bits_left >= 8 )
          {
LABEL_11:
            v13 = (unsigned __int8)(get_buffer >> (decode_mcu - 8));
            v14 = v11->look_nbits[v13];
            if ( v14 != 0 )
            {
              v15 = v11->look_sym[v13];
              decode_mcu -= v14;
              goto LABEL_16;
            }
            v12 = 9;
          }
          else
          {
            v12 = 1;
          }
          v15 = jpeg_huff_decode(state: &br_state, get_buffer, bits_left: decode_mcu, htbl: v11, min_bits: v12);
          if ( v15 < 0 )
            return 0;
          decode_mcu = br_state.bits_left;
          get_buffer = br_state.get_buffer;
LABEL_16:
          if ( v15 != 0 )
          {
            if ( decode_mcu < v15 )
            {
              if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left: decode_mcu, nbits: v15) == 0 )
                return 0;
              decode_mcu = br_state.bits_left;
              get_buffer = br_state.get_buffer;
            }
            decode_mcu -= v15;
            v16 = (get_buffer >> decode_mcu) & ((1 << v15) - 1);
            v2 = cinfo;
            if ( v16 >= extend_test_0[v15] )
              v15 = (get_buffer >> decode_mcu) & ((1 << v15) - 1);
            else
              v15 = v16 + extend_offset_0[v15];
          }
          v17 = ci;
          state.last_dc_val[ci] += v15;
          v18 = state.last_dc_val[v17];
          ++MCU_membership;
          *(_WORD *)block = (_WORD)v18 << Al;
          ++blkn;
        }
        while ( blkn < v2->blocks_in_MCU );
      }
      v19 = *(_QWORD *)&state.EOBRUN;
      v2->src->next_input_byte = br_state.next_input_byte;
      v2->src->bytes_in_buffer = br_state.bytes_in_buffer;
      v20 = get_buffer;
      *(_QWORD *)&entropy[1].insufficient_data = v19;
      v21 = *(_QWORD *)&state.last_dc_val[1];
      entropy[1].decode_mcu = (unsigned __int8 (__cdecl *)(jpeg_decompress_struct *, __int16 (**)[64]))decode_mcu;
      v22 = state.last_dc_val[3];
      *(_QWORD *)&entropy[2].decode_mcu = v21;
      entropy[1].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))v20;
      entropy[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))v22;
    }
    --entropy[3].decode_mcu;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10277FD0
// Name: decode_mcu_AC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl decode_mcu_AC_first(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_decompress_struct *v2; // esi
  bool v3; // zf
  int v4; // eax
  int Al; // ecx
  phuff_entropy_decoder *v6; // edi
  unsigned __int8 result; // al
  unsigned int v8; // eax
  jpeg_source_mgr *src; // eax
  __int16 *v10; // edx
  int get_buffer; // ebx
  int bits_left; // eax
  int Ss; // ecx
  d_derived_tbl *v14; // esi
  int v15; // ecx
  int v16; // edx
  int v17; // ecx
  int v18; // edi
  int v19; // esi
  int v20; // edi
  int v21; // edx
  int v22; // edi
  unsigned int v23; // eax
  bitread_working_state br_state; // [esp+8h] [ebp-30h] BYREF
  __int16 (*block)[64]; // [esp+1Ch] [ebp-1Ch]
  int v26; // [esp+20h] [ebp-18h]
  unsigned int EOBRUN; // [esp+24h] [ebp-14h]
  phuff_entropy_decoder *entropy; // [esp+28h] [ebp-10h]
  int Se; // [esp+2Ch] [ebp-Ch]
  d_derived_tbl *tbl; // [esp+30h] [ebp-8h]
  int k; // [esp+34h] [ebp-4h]

  v2 = cinfo;
  v3 = cinfo->restart_interval == 0;
  v4 = cinfo->Se;
  Al = cinfo->Al;
  v6 = (phuff_entropy_decoder *)cinfo->entropy;
  entropy = v6;
  Se = v4;
  v26 = Al;
  if ( !v3 && v6->restarts_to_go == 0 )
  {
    result = process_restart_0(cinfo);
    if ( result == 0 )
      return result;
  }
  if ( v6->pub.insufficient_data != 0 )
    goto LABEL_38;
  v8 = v6->saved.EOBRUN;
  EOBRUN = v8;
  if ( v8 != 0 )
  {
    --v6->restarts_to_go;
    v6->saved.EOBRUN = v8 - 1;
    return 1;
  }
  src = cinfo->src;
  br_state.cinfo = cinfo;
  br_state.next_input_byte = src->next_input_byte;
  v10 = (__int16 *)*MCU_data;
  br_state.bytes_in_buffer = src->bytes_in_buffer;
  get_buffer = v6->bitstate.get_buffer;
  bits_left = v6->bitstate.bits_left;
  tbl = v6->ac_derived_tbl;
  Ss = cinfo->Ss;
  block = (__int16 (*)[64])v10;
  k = Ss;
  if ( Ss > Se )
    goto LABEL_37;
  while ( 1 )
  {
    if ( bits_left >= 8 )
      goto LABEL_12;
    if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 0) == 0 )
      return 0;
    bits_left = br_state.bits_left;
    get_buffer = br_state.get_buffer;
    if ( br_state.bits_left >= 8 )
    {
LABEL_12:
      v14 = tbl;
      v16 = (unsigned __int8)(get_buffer >> (bits_left - 8));
      v17 = tbl->look_nbits[v16];
      if ( v17 != 0 )
      {
        v18 = tbl->look_sym[v16];
        bits_left -= v17;
        goto LABEL_17;
      }
      v15 = 9;
    }
    else
    {
      v14 = tbl;
      v15 = 1;
    }
    v18 = jpeg_huff_decode(state: &br_state, get_buffer, bits_left, htbl: v14, min_bits: v15);
    if ( v18 < 0 )
      return 0;
    get_buffer = br_state.get_buffer;
    bits_left = br_state.bits_left;
LABEL_17:
    v19 = v18 >> 4;
    v20 = v18 & 0xF;
    if ( v20 != 0 )
    {
      k += v19;
      if ( bits_left < v20 )
      {
        if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v20) == 0 )
          return 0;
        get_buffer = br_state.get_buffer;
        bits_left = br_state.bits_left;
      }
      bits_left -= v20;
      v21 = (get_buffer >> bits_left) & ((1 << v20) - 1);
      if ( v21 >= extend_test_0[v20] )
        v20 = (get_buffer >> bits_left) & ((1 << v20) - 1);
      else
        LOWORD(v20) = v21 + extend_offset_0[v20];
      (*block)[jpeg_natural_order[k]] = (_WORD)v20 << v26;
      goto LABEL_27;
    }
    if ( v19 != 15 )
      break;
    k += 15;
LABEL_27:
    if ( ++k > Se )
      goto LABEL_36;
  }
  v22 = 1 << v19;
  if ( v19 != 0 )
  {
    if ( bits_left < v19 )
    {
      if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v19) == 0 )
        return 0;
      get_buffer = br_state.get_buffer;
      bits_left = br_state.bits_left;
    }
    bits_left -= v19;
    v22 += (v22 - 1) & (get_buffer >> bits_left);
  }
  EOBRUN = v22 - 1;
LABEL_36:
  v2 = cinfo;
  v6 = entropy;
LABEL_37:
  v2->src->next_input_byte = br_state.next_input_byte;
  v2->src->bytes_in_buffer = br_state.bytes_in_buffer;
  v6->bitstate.bits_left = bits_left;
  v23 = EOBRUN;
  v6->bitstate.get_buffer = get_buffer;
  v6->saved.EOBRUN = v23;
LABEL_38:
  --v6->restarts_to_go;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102781F0
// Name: decode_mcu_DC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl decode_mcu_DC_refine(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  bool v3; // zf
  jpeg_entropy_decoder *entropy; // edi
  unsigned __int8 result; // al
  jpeg_source_mgr *src; // eax
  int start_pass; // eax
  int decode_mcu; // ecx
  int v9; // ebx
  bitread_working_state br_state; // [esp+8h] [ebp-1Ch] BYREF
  __int16 (*block)[64]; // [esp+1Ch] [ebp-8h]
  int p1; // [esp+20h] [ebp-4h]
  int get_buffer; // [esp+2Ch] [ebp+8h]

  v3 = cinfo->restart_interval == 0;
  entropy = cinfo->entropy;
  p1 = 1 << cinfo->Al;
  if ( v3 || entropy[3].decode_mcu != nullptr || (result = process_restart_0(cinfo)) != 0 )
  {
    src = cinfo->src;
    br_state.cinfo = cinfo;
    br_state.next_input_byte = src->next_input_byte;
    br_state.bytes_in_buffer = src->bytes_in_buffer;
    start_pass = (int)entropy[1].start_pass;
    decode_mcu = (int)entropy[1].decode_mcu;
    v9 = 0;
    get_buffer = start_pass;
    if ( cinfo->blocks_in_MCU <= 0 )
    {
LABEL_11:
      cinfo->src->next_input_byte = br_state.next_input_byte;
      cinfo->src->bytes_in_buffer = br_state.bytes_in_buffer;
      --entropy[3].decode_mcu;
      entropy[1].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))start_pass;
      entropy[1].decode_mcu = (unsigned __int8 (__cdecl *)(jpeg_decompress_struct *, __int16 (**)[64]))decode_mcu;
      return 1;
    }
    while ( 1 )
    {
      block = MCU_data[v9];
      if ( decode_mcu < 1 )
      {
        if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer: start_pass, bits_left: decode_mcu, nbits: 1) == 0 )
          return 0;
        start_pass = br_state.get_buffer;
        decode_mcu = br_state.bits_left;
        get_buffer = br_state.get_buffer;
      }
      if ( ((start_pass >> --decode_mcu) & 1) != 0 )
      {
        *(_WORD *)block |= p1;
        start_pass = get_buffer;
      }
      if ( ++v9 >= cinfo->blocks_in_MCU )
        goto LABEL_11;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102782D0
// Name: decode_mcu_AC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl decode_mcu_AC_refine(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_decompress_struct *v2; // esi
  int Al; // ecx
  phuff_entropy_decoder *v4; // edx
  bool v5; // zf
  unsigned __int8 result; // al
  phuff_entropy_decoder *v7; // ecx
  jpeg_source_mgr *src; // eax
  __int16 *v9; // edx
  unsigned int v10; // eax
  int get_buffer; // ebx
  int bits_left; // edi
  int Ss; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // eax
  __int16 *v19; // esi
  __int16 v20; // ax
  __int16 v21; // ax
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int i; // eax
  int v26; // eax
  __int16 *v27; // eax
  __int16 v28; // ax
  __int16 v29; // ax
  unsigned int v30; // eax
  int j; // eax
  int v32; // edx
  int newnz_pos[64]; // [esp+4h] [ebp-140h]
  d_derived_tbl *tbl; // [esp+104h] [ebp-40h]
  phuff_entropy_decoder *entropy; // [esp+108h] [ebp-3Ch]
  int p1; // [esp+10Ch] [ebp-38h]
  int num_newnz; // [esp+110h] [ebp-34h]
  int m1; // [esp+114h] [ebp-30h]
  bitread_working_state br_state; // [esp+118h] [ebp-2Ch] BYREF
  __int16 (*block)[64]; // [esp+12Ch] [ebp-18h]
  int r; // [esp+130h] [ebp-14h]
  int Se; // [esp+134h] [ebp-10h]
  int s; // [esp+138h] [ebp-Ch]
  unsigned int EOBRUN; // [esp+13Ch] [ebp-8h]
  int k; // [esp+140h] [ebp-4h]
  __int16 *thiscoef; // [esp+14Ch] [ebp+8h]

  v2 = cinfo;
  Al = cinfo->Al;
  v4 = (phuff_entropy_decoder *)cinfo->entropy;
  Se = cinfo->Se;
  entropy = v4;
  p1 = 1 << Al;
  v5 = cinfo->restart_interval == 0;
  m1 = -1 << Al;
  if ( !v5 && v4->restarts_to_go == 0 )
  {
    result = process_restart_0(cinfo);
    if ( result == 0 )
      return result;
  }
  v7 = entropy;
  if ( entropy->pub.insufficient_data != 0 )
  {
LABEL_63:
    --v7->restarts_to_go;
    return 1;
  }
  src = cinfo->src;
  br_state.cinfo = cinfo;
  br_state.next_input_byte = src->next_input_byte;
  v9 = (__int16 *)*MCU_data;
  br_state.bytes_in_buffer = src->bytes_in_buffer;
  v10 = entropy->saved.EOBRUN;
  get_buffer = entropy->bitstate.get_buffer;
  bits_left = entropy->bitstate.bits_left;
  tbl = entropy->ac_derived_tbl;
  Ss = cinfo->Ss;
  EOBRUN = v10;
  block = (__int16 (*)[64])v9;
  num_newnz = 0;
  k = Ss;
  if ( v10 != 0 )
  {
LABEL_48:
    if ( EOBRUN != 0 )
    {
      for ( i = k; i <= Se; k = i )
      {
        v26 = jpeg_natural_order[i];
        v5 = (*block)[v26] == 0;
        v27 = &(*block)[v26];
        thiscoef = v27;
        if ( !v5 )
        {
          if ( bits_left < 1 )
          {
            if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 1) == 0 )
              goto undoit;
            get_buffer = br_state.get_buffer;
            bits_left = br_state.bits_left;
            v27 = thiscoef;
          }
          if ( ((get_buffer >> --bits_left) & 1) != 0 )
          {
            v28 = *v27;
            if ( (v28 & p1) == 0 )
            {
              if ( v28 < 0 )
                v29 = m1 + v28;
              else
                v29 = p1 + v28;
              *thiscoef = v29;
            }
          }
        }
        i = k + 1;
      }
      --EOBRUN;
    }
    goto LABEL_62;
  }
  if ( Ss > Se )
  {
LABEL_62:
    v2->src->next_input_byte = br_state.next_input_byte;
    v30 = EOBRUN;
    v2->src->bytes_in_buffer = br_state.bytes_in_buffer;
    v7 = entropy;
    entropy->bitstate.get_buffer = get_buffer;
    v7->bitstate.bits_left = bits_left;
    v7->saved.EOBRUN = v30;
    goto LABEL_63;
  }
  while ( 1 )
  {
    if ( bits_left >= 8 )
      goto LABEL_11;
    if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 0) == 0 )
      goto undoit;
    bits_left = br_state.bits_left;
    get_buffer = br_state.get_buffer;
    if ( br_state.bits_left >= 8 )
    {
LABEL_11:
      v15 = (unsigned __int8)(get_buffer >> (bits_left - 8));
      v16 = tbl->look_nbits[v15];
      if ( v16 != 0 )
      {
        bits_left -= v16;
        s = tbl->look_sym[v15];
        goto LABEL_16;
      }
      v14 = 9;
    }
    else
    {
      v14 = 1;
    }
    s = jpeg_huff_decode(state: &br_state, get_buffer, bits_left, htbl: tbl, min_bits: v14);
    if ( s < 0 )
      goto undoit;
    get_buffer = br_state.get_buffer;
    bits_left = br_state.bits_left;
LABEL_16:
    v17 = s >> 4;
    v18 = s & 0xF;
    r = s >> 4;
    s = v18;
    if ( v18 == 0 )
      break;
    if ( v18 != 1 )
    {
      cinfo->err->msg_code = 118;
      cinfo->err->emit_message(a1: (jpeg_common_struct *)cinfo, a2: -1);
    }
    if ( bits_left < 1 )
    {
      if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 1) == 0 )
        goto undoit;
      get_buffer = br_state.get_buffer;
      bits_left = br_state.bits_left;
    }
    if ( ((get_buffer >> --bits_left) & 1) != 0 )
      s = p1;
    else
      s = m1;
    do
    {
LABEL_26:
      v19 = &(*block)[jpeg_natural_order[k]];
      if ( *v19 != 0 )
      {
        if ( bits_left < 1 )
        {
          if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: 1) == 0 )
            goto undoit;
          get_buffer = br_state.get_buffer;
          bits_left = br_state.bits_left;
        }
        if ( ((get_buffer >> --bits_left) & 1) != 0 )
        {
          v20 = *v19;
          if ( (*v19 & p1) == 0 )
          {
            if ( v20 < 0 )
              v21 = m1 + v20;
            else
              v21 = p1 + v20;
            *v19 = v21;
          }
        }
      }
      else if ( --r < 0 )
      {
        break;
      }
      ++k;
    }
    while ( k <= Se );
    if ( s != 0 )
    {
      v22 = jpeg_natural_order[k];
      (*block)[v22] = s;
      v23 = num_newnz;
      newnz_pos[num_newnz] = v22;
      num_newnz = v23 + 1;
    }
    if ( ++k > Se )
    {
      v2 = cinfo;
      goto LABEL_62;
    }
  }
  if ( v17 == 15 )
    goto LABEL_26;
  v24 = 1 << v17;
  r = 1 << v17;
  EOBRUN = 1 << v17;
  if ( v17 == 0 )
    goto LABEL_47;
  if ( bits_left >= v17 )
    goto LABEL_46;
  if ( jpeg_fill_bit_buffer(state: &br_state, get_buffer, bits_left, nbits: v17) != 0 )
  {
    get_buffer = br_state.get_buffer;
    bits_left = br_state.bits_left;
    v24 = r;
LABEL_46:
    bits_left -= v17;
    EOBRUN += (v24 - 1) & (get_buffer >> bits_left);
LABEL_47:
    v2 = cinfo;
    goto LABEL_48;
  }
undoit:
  for ( j = num_newnz; j > 0; (*block)[v32] = 0 )
    v32 = newnz_pos[--j];
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10278660
// Name: start_pass_phuff_decoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_phuff_decoder(jpeg_common_struct *cinfo)
{
  int mem; // eax
  jpeg_entropy_decoder *err; // ebx
  char v4; // cl
  bool v5; // zf
  int progress; // edx
  int client_data; // eax
  int component_index; // ecx
  int *v9; // ebx
  int i; // edi
  jpeg_component_info *v11; // eax
  int ac_tbl_no; // eax
  d_derived_tbl **v13; // edi
  phuff_entropy_decoder *entropy; // [esp+Ch] [ebp-10h]
  int cindex; // [esp+10h] [ebp-Ch]
  jpeg_entropy_decoder *cindexa; // [esp+10h] [ebp-Ch]
  jpeg_component_info **p_progress; // [esp+14h] [ebp-8h]
  jpeg_component_info **v18; // [esp+14h] [ebp-8h]
  int ci; // [esp+18h] [ebp-4h]
  int cia; // [esp+18h] [ebp-4h]
  bool is_DC_band_3; // [esp+27h] [ebp+Bh]

  mem = (int)cinfo[15].mem;
  err = (jpeg_entropy_decoder *)cinfo[17].err;
  v4 = 0;
  entropy = (phuff_entropy_decoder *)err;
  is_DC_band_3 = mem == 0;
  if ( mem != 0 )
  {
    progress = (int)cinfo[15].progress;
    if ( mem > progress || progress >= 64 )
      v4 = 1;
    v5 = cinfo[12].mem == (jpeg_memory_mgr *)1;
  }
  else
  {
    v5 = cinfo[15].progress == nullptr;
  }
  if ( !v5 )
    v4 = 1;
  client_data = (int)cinfo[15].client_data;
  if ( client_data != 0 && *(_DWORD *)&cinfo[15].is_decompressor != client_data - 1 )
    v4 = 1;
  if ( *(int *)&cinfo[15].is_decompressor > 13 || v4 != 0 )
  {
    cinfo->err->msg_code = 16;
    cinfo->err->msg_parm.i[0] = (int)cinfo[15].mem;
    cinfo->err->msg_parm.i[1] = (int)cinfo[15].progress;
    cinfo->err->msg_parm.i[2] = (int)cinfo[15].client_data;
    cinfo->err->msg_parm.i[3] = *(_DWORD *)&cinfo[15].is_decompressor;
    cinfo->err->error_exit(a1: cinfo);
  }
  ci = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    p_progress = (jpeg_component_info **)&cinfo[12].progress;
    do
    {
      component_index = (*p_progress)->component_index;
      v9 = (int *)(cinfo[5].global_state + (component_index << 8));
      cindex = component_index;
      if ( !is_DC_band_3 && *v9 < 0 )
      {
        cinfo->err->msg_code = 115;
        cinfo->err->msg_parm.i[0] = component_index;
        cinfo->err->msg_parm.i[1] = 0;
        cinfo->err->emit_message(a1: cinfo, a2: -1);
        component_index = cindex;
      }
      for ( i = (int)cinfo[15].mem; i <= (int)cinfo[15].progress; ++i )
      {
        if ( cinfo[15].client_data != (void *)(v9[i] < 0 ? 0 : v9[i]) )
        {
          cinfo->err->msg_code = 115;
          cinfo->err->msg_parm.i[0] = component_index;
          cinfo->err->msg_parm.i[1] = i;
          cinfo->err->emit_message(a1: cinfo, a2: -1);
          component_index = cindex;
        }
        v9[i] = *(_DWORD *)&cinfo[15].is_decompressor;
      }
      ++p_progress;
      ++ci;
    }
    while ( ci < (int)cinfo[12].mem );
    err = &entropy->pub;
  }
  if ( cinfo[15].client_data != nullptr )
  {
    if ( is_DC_band_3 )
      err->decode_mcu = decode_mcu_DC_refine;
    else
      err->decode_mcu = decode_mcu_AC_refine;
  }
  else if ( is_DC_band_3 )
  {
    err->decode_mcu = decode_mcu_DC_first;
  }
  else
  {
    err->decode_mcu = decode_mcu_AC_first;
  }
  cia = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    cindexa = err + 2;
    v18 = (jpeg_component_info **)&cinfo[12].progress;
    do
    {
      v11 = *v18;
      if ( is_DC_band_3 )
      {
        if ( cinfo[15].client_data == nullptr )
          jpeg_make_d_derived_tbl(
            (jpeg_decompress_struct *)cinfo,
            isDC: 1u,
            tblno: v11->dc_tbl_no,
            pdtbl: (d_derived_tbl **)&err[3].insufficient_data + v11->dc_tbl_no);
      }
      else
      {
        ac_tbl_no = v11->ac_tbl_no;
        v13 = (d_derived_tbl **)(&err[3].insufficient_data + 4 * ac_tbl_no);
        jpeg_make_d_derived_tbl((jpeg_decompress_struct *)cinfo, isDC: 0, tblno: ac_tbl_no, pdtbl: v13);
        err[5].start_pass = (void (__cdecl *)(jpeg_decompress_struct *))*v13;
      }
      ++v18;
      cindexa->start_pass = nullptr;
      ++cia;
      cindexa = (jpeg_entropy_decoder *)((char *)cindexa + 4);
    }
    while ( cia < (int)cinfo[12].mem );
  }
  err[1].decode_mcu = nullptr;
  err[1].start_pass = nullptr;
  *(_DWORD *)&err[1].insufficient_data = 0;
  err->insufficient_data = 0;
  err[3].decode_mcu = (unsigned __int8 (__cdecl *)(jpeg_decompress_struct *, __int16 (**)[64]))cinfo[10].client_data;
}

//------------------------------------------------------------------------------
// Address: 0x102788C0
// Name: _jinit_phuff_decoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_phuff_decoder(jpeg_common_struct *cinfo)
{
  int v1; // eax
  int v2; // ebx
  int *v3; // eax
  int *i; // edx

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[17].err = (jpeg_error_mgr *)v1;
  *(_DWORD *)v1 = start_pass_phuff_decoder;
  v2 = 0;
  *(_DWORD *)(v1 + 44) = 0;
  *(_DWORD *)(v1 + 48) = 0;
  *(_DWORD *)(v1 + 52) = 0;
  *(_DWORD *)(v1 + 56) = 0;
  v3 = (int *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: (int)cinfo[1].client_data << 8);
  cinfo[5].global_state = (int)v3;
  for ( i = v3; v2 < (int)cinfo[1].client_data; i += 64 )
  {
    ++v2;
    memset(i, 0xFFu, 0x100u);
  }
}

} // namespace client
