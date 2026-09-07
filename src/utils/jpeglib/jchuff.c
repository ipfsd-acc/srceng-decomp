// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jchuff.c
// Functions: 13
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10253D90
// Name: _jpeg_make_c_derived_tbl
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_make_c_derived_tbl(
        jpeg_common_struct *cinfo,
        unsigned __int8 isDC,
        unsigned int tblno,
        c_derived_tbl **pdtbl)
{
  int v5; // edi
  int i; // ebx
  unsigned int v7; // esi
  int v8; // ebx
  signed int v9; // edi
  int v10; // esi
  c_derived_tbl **v11; // edx
  char *v12; // eax
  int v13; // eax
  int j; // esi
  int v15; // edi
  unsigned int v16; // ecx
  char v17; // dl
  c_derived_tbl *v18; // eax
  unsigned int huffcode[257]; // [esp+Ch] [ebp-510h]
  char huffsize[260]; // [esp+410h] [ebp-10Ch] BYREF
  int lastp; // [esp+514h] [ebp-8h]
  c_derived_tbl *dtbl; // [esp+518h] [ebp-4h]
  JHUFF_TBL *htbl; // [esp+52Ch] [ebp+10h]
  c_derived_tbl **pdtbla; // [esp+530h] [ebp+14h]

  if ( tblno >= 4 )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( isDC != 0 )
    htbl = *((JHUFF_TBL **)&cinfo[3].is_decompressor + tblno);
  else
    htbl = *((JHUFF_TBL **)&cinfo[4].progress + tblno);
  if ( htbl == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *pdtbl == nullptr )
    *pdtbl = (c_derived_tbl *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1280);
  dtbl = *pdtbl;
  v5 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    v7 = htbl->bits[i];
    if ( (int)(v7 + v5) > 256 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v7 != 0 )
    {
      memset(dst: (unsigned __int8 *)&huffsize[v5], value: i, count: v7);
      v5 += v7;
    }
  }
  huffsize[v5] = 0;
  v8 = huffsize[0];
  lastp = v5;
  v9 = 0;
  v10 = 0;
  v11 = (c_derived_tbl **)__ROL4__(1, huffsize[0]);
  pdtbla = v11;
  if ( huffsize[0] != 0 )
  {
    v12 = huffsize;
    while ( 1 )
    {
      if ( *v12 == v8 )
      {
        do
        {
          v13 = huffsize[v10 + 1];
          huffcode[v10++] = v9++;
        }
        while ( v13 == v8 );
      }
      if ( v9 >= (int)v11 )
      {
        cinfo->err->msg_code = 8;
        cinfo->err->error_exit(a1: cinfo);
        v11 = pdtbla;
      }
      v9 *= 2;
      ++v8;
      v12 = &huffsize[v10];
      pdtbla = (c_derived_tbl **)__ROL4__(v11, 1);
      if ( huffsize[v10] == 0 )
        break;
      v11 = pdtbla;
    }
  }
  memset(dst: (unsigned __int8 *)dtbl->ehufsi, value: 0, count: sizeof(dtbl->ehufsi));
  for ( j = 0; j < lastp; v18->ehufsi[v15] = v17 )
  {
    v15 = htbl->huffval[j];
    if ( v15 > (isDC != 0 ? 15 : 255) || dtbl->ehufsi[v15] != 0 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    v16 = huffcode[j];
    v17 = huffsize[j];
    v18 = dtbl;
    ++j;
    dtbl->ehufco[v15] = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253F90
// Name: emit_bits
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall emit_bits@<al>(working_state *state@<esi>, unsigned int code, int size)
{
  int v3; // ebx
  int v4; // ebx
  unsigned int v5; // edi
  bool v6; // zf
  jpeg_destination_mgr *dest; // ebx
  int v8; // eax
  int put_bits; // [esp+8h] [ebp-4h]
  jpeg_destination_mgr *sizea; // [esp+18h] [ebp+Ch]

  v3 = state->cur.put_bits;
  if ( size == 0 )
  {
    state->cinfo->err->msg_code = 40;
    state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
  }
  v4 = size + v3;
  put_bits = v4;
  v5 = state->cur.put_buffer | ((code & ((1 << size) - 1)) << (24 - v4));
  if ( v4 < 8 )
  {
LABEL_13:
    state->cur.put_buffer = v5;
    state->cur.put_bits = v4;
    return 1;
  }
  while ( 1 )
  {
    *state->next_output_byte++ = BYTE2(v5);
    v6 = state->free_in_buffer-- == 1;
    if ( v6 )
    {
      sizea = state->cinfo->dest;
      if ( sizea->empty_output_buffer(a1: state->cinfo) == 0 )
        return 0;
      state->next_output_byte = sizea->next_output_byte;
      state->free_in_buffer = sizea->free_in_buffer;
    }
    if ( BYTE2(v5) == 255 )
    {
      *state->next_output_byte++ = 0;
      v6 = state->free_in_buffer-- == 1;
      if ( v6 )
        break;
    }
LABEL_11:
    v8 = put_bits - 8;
    v5 <<= 8;
    put_bits = v8;
    if ( v8 < 8 )
    {
      v4 = v8;
      goto LABEL_13;
    }
  }
  dest = state->cinfo->dest;
  if ( dest->empty_output_buffer(a1: state->cinfo) != 0 )
  {
    state->next_output_byte = dest->next_output_byte;
    state->free_in_buffer = dest->free_in_buffer;
    goto LABEL_11;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10254080
// Name: encode_one_block
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_one_block(
        working_state *state,
        __int16 *block,
        int last_dc_val,
        c_derived_tbl *dctbl,
        c_derived_tbl *actbl)
{
  signed int v5; // edi
  int v6; // eax
  int v7; // ebx
  working_state *v8; // esi
  int *v10; // eax
  int v11; // edi
  int v12; // ebx
  int v13; // ebx
  int v14; // esi
  working_state *v15; // ebx
  int *v16; // [esp+Ch] [ebp-4h]
  unsigned int temp2; // [esp+20h] [ebp+10h]
  int nbits; // [esp+24h] [ebp+14h]

  v5 = *block - last_dc_val;
  v6 = v5;
  if ( v5 < 0 )
  {
    v6 = last_dc_val - *block;
    --v5;
  }
  v7 = 0;
  if ( v6 == 0 )
    goto LABEL_7;
  do
  {
    ++v7;
    v6 >>= 1;
  }
  while ( v6 != 0 );
  if ( v7 > 11 )
  {
    v8 = state;
    state->cinfo->err->msg_code = 6;
    state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
  }
  else
  {
LABEL_7:
    v8 = state;
  }
  if ( emit_bits(state: v8, code: dctbl->ehufco[v7], size: dctbl->ehufsi[v7]) != 0
    && (v7 == 0 || emit_bits(state: v8, code: v5, size: v7) != 0) )
  {
    v10 = (int *)&unk_103CAA7C;
    v11 = 0;
    v16 = (int *)&unk_103CAA7C;
    do
    {
      v12 = block[*v10];
      if ( block[*v10] != 0 )
      {
        if ( v11 > 15 )
        {
          while ( emit_bits(state, code: actbl->ehufco[240], size: actbl->ehufsi[240]) != 0 )
          {
            v11 -= 16;
            if ( v11 <= 15 )
              goto LABEL_18;
          }
          return 0;
        }
LABEL_18:
        temp2 = v12;
        if ( v12 < 0 )
        {
          v12 = -v12;
          --temp2;
        }
        v13 = v12 >> 1;
        v14 = 1;
        nbits = 1;
        if ( v13 == 0 )
          goto LABEL_24;
        do
        {
          ++v14;
          v13 >>= 1;
        }
        while ( v13 != 0 );
        nbits = v14;
        if ( v14 > 10 )
        {
          v15 = state;
          state->cinfo->err->msg_code = 6;
          state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
        }
        else
        {
LABEL_24:
          v15 = state;
        }
        if ( emit_bits(state: v15, code: actbl->ehufco[16 * v11 + v14], size: actbl->ehufsi[16 * v11 + v14]) == 0
          || emit_bits(state: v15, code: temp2, size: nbits) == 0 )
        {
          return 0;
        }
        v10 = v16;
        v11 = 0;
      }
      else
      {
        ++v11;
      }
      v16 = ++v10;
    }
    while ( (int)v10 < (int)dword_103CAB78 );
    if ( v11 <= 0 || emit_bits(state, code: actbl->ehufco[0], size: actbl->ehufsi[0]) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10254230
// Name: emit_restart
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall emit_restart@<al>(working_state *state@<eax>, char restart_num)
{
  bool v3; // zf
  jpeg_destination_mgr *dest; // edi
  jpeg_destination_mgr *v5; // edi
  int v6; // eax
  int *last_dc_val; // ecx

  if ( emit_bits(state, code: 0x7Fu, size: 7) == 0 )
    return 0;
  state->cur.put_buffer = 0;
  state->cur.put_bits = 0;
  *state->next_output_byte++ = -1;
  v3 = state->free_in_buffer-- == 1;
  if ( v3 )
  {
    dest = state->cinfo->dest;
    if ( dest->empty_output_buffer(a1: state->cinfo) == 0 )
      return 0;
    state->next_output_byte = dest->next_output_byte;
    state->free_in_buffer = dest->free_in_buffer;
  }
  *state->next_output_byte++ = restart_num - 48;
  v3 = state->free_in_buffer-- == 1;
  if ( v3 )
  {
    v5 = state->cinfo->dest;
    if ( v5->empty_output_buffer(a1: state->cinfo) != 0 )
    {
      state->next_output_byte = v5->next_output_byte;
      state->free_in_buffer = v5->free_in_buffer;
      goto LABEL_8;
    }
    return 0;
  }
LABEL_8:
  v6 = 0;
  if ( state->cinfo->comps_in_scan > 0 )
  {
    last_dc_val = state->cur.last_dc_val;
    do
    {
      *last_dc_val = 0;
      ++v6;
      ++last_dc_val;
    }
    while ( v6 < state->cinfo->comps_in_scan );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102542F0
// Name: encode_mcu_huff
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_huff(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  bool v3; // zf
  jpeg_entropy_encoder *entropy; // esi
  jpeg_destination_mgr *dest; // eax
  unsigned __int8 *next_output_byte; // ecx
  unsigned int free_in_buffer; // edx
  unsigned __int8 result; // al
  int v9; // ebx
  jpeg_component_info *v10; // ecx
  __int16 *v11; // edx
  int v12; // eax
  __int64 v13; // xmm0_8
  unsigned int restart_interval; // edi
  int v15; // eax
  c_derived_tbl *v16; // [esp-Ch] [ebp-3Ch]
  c_derived_tbl *v17; // [esp-8h] [ebp-38h]
  working_state state; // [esp+8h] [ebp-28h] BYREF
  int *v19; // [esp+2Ch] [ebp-4h]
  int *cinfoa; // [esp+38h] [ebp+8h]

  v3 = cinfo->restart_interval == 0;
  entropy = cinfo->entropy;
  dest = cinfo->dest;
  next_output_byte = dest->next_output_byte;
  free_in_buffer = dest->free_in_buffer;
  *(_QWORD *)&state.cur.put_buffer = *(_QWORD *)&entropy[1].start_pass;
  *(_QWORD *)state.cur.last_dc_val = *(_QWORD *)&entropy[1].finish_pass;
  state.next_output_byte = next_output_byte;
  state.free_in_buffer = free_in_buffer;
  *(_QWORD *)&state.cur.last_dc_val[2] = *(_QWORD *)&entropy[2].encode_mcu;
  state.cinfo = cinfo;
  if ( v3
    || entropy[3].start_pass != nullptr
    || (result = emit_restart(&state, restart_num: (char)entropy[3].encode_mcu)) != 0 )
  {
    v9 = 0;
    if ( cinfo->blocks_in_MCU <= 0 )
    {
LABEL_8:
      v13 = *(_QWORD *)&state.cur.put_buffer;
      cinfo->dest->next_output_byte = state.next_output_byte;
      cinfo->dest->free_in_buffer = state.free_in_buffer;
      *(_QWORD *)&entropy[1].start_pass = v13;
      *(_OWORD *)&entropy[1].finish_pass = *(_OWORD *)state.cur.last_dc_val;
      restart_interval = cinfo->restart_interval;
      if ( restart_interval != 0 )
      {
        if ( entropy[3].start_pass == nullptr )
        {
          v15 = ((unsigned __int8)entropy[3].encode_mcu + 1) & 7;
          entropy[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))restart_interval;
          entropy[3].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))v15;
        }
        --entropy[3].start_pass;
      }
      return 1;
    }
    else
    {
      cinfoa = cinfo->MCU_membership;
      while ( 1 )
      {
        v10 = cinfo->cur_comp_info[*cinfoa];
        v17 = *((c_derived_tbl **)&entropy[5].start_pass + v10->ac_tbl_no);
        v16 = *((c_derived_tbl **)&entropy[3].finish_pass + v10->dc_tbl_no);
        v11 = (__int16 *)MCU_data[v9];
        v19 = &state.cur.last_dc_val[*cinfoa];
        if ( encode_one_block(&state, block: v11, last_dc_val: *v19, dctbl: v16, actbl: v17) == 0 )
          return 0;
        v12 = (*MCU_data[v9])[0];
        ++cinfoa;
        ++v9;
        *v19 = v12;
        if ( v9 >= cinfo->blocks_in_MCU )
          goto LABEL_8;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10254430
// Name: finish_pass_huff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_huff(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // eax
  unsigned __int8 *next_output_byte; // ecx
  unsigned int free_in_buffer; // edx
  jpeg_entropy_encoder *entropy; // edi
  __int64 v5; // xmm0_8
  __int64 v6; // xmm0_8
  working_state state; // [esp+Ch] [ebp-24h] BYREF

  dest = cinfo->dest;
  next_output_byte = dest->next_output_byte;
  free_in_buffer = dest->free_in_buffer;
  entropy = cinfo->entropy;
  *(_QWORD *)&state.cur.put_buffer = *(_QWORD *)&entropy[1].start_pass;
  *(_QWORD *)state.cur.last_dc_val = *(_QWORD *)&entropy[1].finish_pass;
  v5 = *(_QWORD *)&entropy[2].encode_mcu;
  state.next_output_byte = next_output_byte;
  state.free_in_buffer = free_in_buffer;
  *(_QWORD *)&state.cur.last_dc_val[2] = v5;
  state.cinfo = cinfo;
  if ( emit_bits(&state, code: 0x7Fu, size: 7) != 0 )
  {
    state.cur.put_buffer = 0;
    state.cur.put_bits = 0;
  }
  else
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
  }
  v6 = *(_QWORD *)&state.cur.put_buffer;
  cinfo->dest->next_output_byte = state.next_output_byte;
  cinfo->dest->free_in_buffer = state.free_in_buffer;
  *(_QWORD *)&entropy[1].start_pass = v6;
  *(_OWORD *)&entropy[1].finish_pass = *(_OWORD *)state.cur.last_dc_val;
}

//------------------------------------------------------------------------------
// Address: 0x102544E0
// Name: encode_mcu_gather
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_gather(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_compress_struct *v2; // edx
  jpeg_entropy_encoder *p_pub; // esi
  int v4; // eax
  void (__cdecl **p_finish_pass)(jpeg_compress_struct *); // ecx
  jpeg_component_info *v6; // eax
  int v7; // edi
  _DWORD *v8; // ebx
  int v9; // eax
  int v10; // esi
  int *v11; // eax
  int v12; // esi
  int v13; // ecx
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // edi
  __int16 *v18; // [esp+4h] [ebp-18h]
  int ci; // [esp+8h] [ebp-14h]
  huff_entropy_encoder *entropy; // [esp+Ch] [ebp-10h]
  int *v21; // [esp+10h] [ebp-Ch]
  int *MCU_membership; // [esp+14h] [ebp-8h]
  int blkn; // [esp+18h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->entropy;
  entropy = (huff_entropy_encoder *)p_pub;
  if ( cinfo->restart_interval != 0 )
  {
    if ( p_pub[3].start_pass == nullptr )
    {
      v4 = 0;
      if ( cinfo->comps_in_scan > 0 )
      {
        p_finish_pass = &p_pub[1].finish_pass;
        do
        {
          *p_finish_pass = nullptr;
          ++v4;
          ++p_finish_pass;
        }
        while ( v4 < cinfo->comps_in_scan );
      }
      p_pub[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))cinfo->restart_interval;
    }
    --p_pub[3].start_pass;
  }
  blkn = 0;
  if ( cinfo->blocks_in_MCU > 0 )
  {
    MCU_membership = cinfo->MCU_membership;
    do
    {
      ci = *MCU_membership;
      v6 = v2->cur_comp_info[*MCU_membership];
      v7 = *((_DWORD *)&p_pub[6].encode_mcu + v6->dc_tbl_no);
      v8 = *((_DWORD **)&p_pub[7].finish_pass + v6->ac_tbl_no);
      v18 = (__int16 *)MCU_data[blkn];
      v9 = *v18 - *((_DWORD *)&p_pub[1].finish_pass + *MCU_membership);
      if ( v9 < 0 )
        v9 = *((_DWORD *)&p_pub[1].finish_pass + *MCU_membership) - *v18;
      v10 = 0;
      if ( v9 != 0 )
      {
        do
        {
          ++v10;
          v9 >>= 1;
        }
        while ( v9 != 0 );
        if ( v10 > 11 )
        {
          v2->err->msg_code = 6;
          v2->err->error_exit(a1: (jpeg_common_struct *)v2);
          v2 = cinfo;
        }
      }
      ++*(_DWORD *)(v7 + 4 * v10);
      v11 = (int *)&unk_103CAA7C;
      v12 = 0;
      v21 = (int *)&unk_103CAA7C;
      do
      {
        v13 = v18[*v11];
        if ( v18[*v11] != 0 )
        {
          if ( v12 > 15 )
          {
            v14 = ((unsigned int)(v12 - 16) >> 4) + 1;
            v12 += -16 * v14;
            v8[240] += v14;
            v2 = cinfo;
          }
          if ( v13 < 0 )
            v13 = -v13;
          v15 = v13 >> 1;
          v16 = 1;
          if ( v15 != 0 )
          {
            do
            {
              ++v16;
              v15 >>= 1;
            }
            while ( v15 != 0 );
            if ( v16 > 10 )
            {
              v2->err->msg_code = 6;
              v2->err->error_exit(a1: (jpeg_common_struct *)v2);
              v2 = cinfo;
            }
          }
          ++v8[16 * v12 + v16];
          v11 = v21;
          v12 = 0;
        }
        else
        {
          ++v12;
        }
        v21 = ++v11;
      }
      while ( (int)v11 < (int)dword_103CAB78 );
      if ( v12 > 0 )
        ++*v8;
      p_pub = &entropy->pub;
      ++MCU_membership;
      entropy->saved.last_dc_val[ci] = (*MCU_data[blkn++])[0];
    }
    while ( blkn < v2->blocks_in_MCU );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10254680
// Name: _jpeg_gen_optimal_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_gen_optimal_table(jpeg_common_struct *cinfo, JHUFF_TBL *htbl, int *freq)
{
  int v3; // eax
  int v4; // esi
  int i; // ecx
  int v6; // edx
  int v7; // edx
  int v8; // edi
  int j; // ecx
  int v10; // esi
  bool v11; // sf
  int *v12; // ecx
  int *v13; // eax
  int v14; // eax
  int k; // edi
  int v16; // esi
  int v17; // esi
  int v18; // ecx
  int v19; // edx
  int m; // eax
  unsigned __int8 v21; // dl
  int v22; // edx
  int n; // esi
  int ii; // eax
  int others[257]; // [esp+Ch] [ebp-82Ch] BYREF
  int codesize[257]; // [esp+410h] [ebp-428h] BYREF
  unsigned __int8 bits[33]; // [esp+814h] [ebp-24h] BYREF

  memset(bits, 0, sizeof(bits));
  memset(dst: (unsigned __int8 *)codesize, value: 0, count: sizeof(codesize));
  memset(others, 0xFFu, sizeof(others));
  freq[256] = 1;
  while ( 1 )
  {
    v3 = -1;
    v4 = 1000000000;
    for ( i = 0; i <= 256; ++i )
    {
      v6 = freq[i];
      if ( v6 != 0 && v6 <= v4 )
      {
        v4 = freq[i];
        v3 = i;
      }
    }
    v7 = -1;
    v8 = 1000000000;
    for ( j = 0; j <= 256; ++j )
    {
      v10 = freq[j];
      if ( v10 != 0 && v10 <= v8 && j != v3 )
      {
        v8 = freq[j];
        v7 = j;
      }
    }
    if ( v7 < 0 )
      break;
    freq[v3] += freq[v7];
    ++codesize[v3];
    v11 = others[v3] < 0;
    v12 = &others[v3];
    freq[v7] = 0;
    if ( !v11 )
    {
      do
      {
        v3 = *v12;
        ++codesize[v3];
        v12 = &others[v3];
      }
      while ( *v12 >= 0 );
    }
    ++codesize[v7];
    others[v3] = v7;
    v13 = &others[v7];
    if ( *v13 >= 0 )
    {
      do
      {
        v14 = *v13;
        ++codesize[v14];
        v11 = others[v14] < 0;
        v13 = &others[v14];
      }
      while ( !v11 );
    }
  }
  for ( k = 0; k <= 256; ++k )
  {
    v16 = codesize[k];
    if ( v16 != 0 )
    {
      if ( v16 > 32 )
      {
        cinfo->err->msg_code = 39;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++bits[v16];
    }
  }
  v17 = 16;
  v18 = 30;
  v19 = 16;
  do
  {
    for ( ; bits[v18 + 2] != 0; --bits[m] )
    {
      for ( m = v18; bits[m] == 0; --m )
        ;
      bits[v18 + 2] -= 2;
      ++bits[v18 + 1];
      bits[m + 1] += 2;
    }
    --v18;
    --v17;
  }
  while ( v17 != 0 );
  if ( bits[16] == 0 )
  {
    do
      --v19;
    while ( bits[v19] == 0 );
  }
  --bits[v19];
  v21 = bits[16];
  *(_QWORD *)htbl->bits = *(_QWORD *)bits;
  *(_QWORD *)&htbl->bits[8] = *(_QWORD *)&bits[8];
  htbl->bits[16] = v21;
  v22 = 0;
  for ( n = 1; n <= 32; ++n )
  {
    for ( ii = 0; ii <= 255; ++ii )
    {
      if ( codesize[ii] == n )
        htbl->huffval[v22++] = ii;
    }
  }
  htbl->sent_table = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102548B0
// Name: finish_pass_gather
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_gather(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // edi
  int dc_tbl_no; // esi
  bool v3; // zf
  int ac_tbl_no; // ebx
  int *v5; // ebx
  int v6; // eax
  int v7; // esi
  int i; // ecx
  int v9; // edx
  int v10; // edx
  int j; // ecx
  int v12; // esi
  bool v13; // sf
  int *v14; // ecx
  int *v15; // eax
  int v16; // eax
  int k; // ebx
  int v18; // esi
  int m; // ecx
  int n; // eax
  _QWORD *v21; // ecx
  char v22; // al
  int v23; // edx
  int ii; // esi
  int jj; // eax
  _DWORD v26[257]; // [esp+4h] [ebp-850h] BYREF
  _DWORD dst[257]; // [esp+408h] [ebp-44Ch] BYREF
  unsigned __int8 *v28; // [esp+80Ch] [ebp-48h]
  int actbl; // [esp+810h] [ebp-44h]
  unsigned __int8 did_dc[4]; // [esp+814h] [ebp-40h] BYREF
  unsigned __int8 did_ac[4]; // [esp+818h] [ebp-3Ch]
  _QWORD *v32; // [esp+81Ch] [ebp-38h]
  __int64 v33; // [esp+820h] [ebp-34h]
  __int64 v34; // [esp+828h] [ebp-2Ch]
  __int64 v35; // [esp+830h] [ebp-24h]
  __int64 v36; // [esp+838h] [ebp-1Ch]
  char v37; // [esp+840h] [ebp-14h]
  int v38; // [esp+844h] [ebp-10h]
  int ci; // [esp+848h] [ebp-Ch]
  huff_entropy_encoder *entropy; // [esp+84Ch] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+850h] [ebp-4h]

  v1 = cinfo;
  entropy = (huff_entropy_encoder *)cinfo[14].client_data;
  *(_DWORD *)did_dc = 0;
  *(_DWORD *)did_ac = 0;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      dc_tbl_no = (*p_is_decompressor)->dc_tbl_no;
      v3 = did_dc[dc_tbl_no] == 0;
      ac_tbl_no = (*p_is_decompressor)->ac_tbl_no;
      actbl = ac_tbl_no;
      v28 = &did_dc[dc_tbl_no];
      if ( v3 )
      {
        if ( *((_DWORD *)&v1[3].is_decompressor + dc_tbl_no) == 0 )
          *((_DWORD *)&v1[3].is_decompressor + dc_tbl_no) = jpeg_alloc_huff_table(cinfo: v1);
        v5 = entropy->dc_count_ptrs[dc_tbl_no];
        v32 = *((_QWORD **)&v1[3].is_decompressor + dc_tbl_no);
        v33 = 0;
        v34 = 0;
        v35 = 0;
        v36 = 0;
        v37 = 0;
        memset((unsigned __int8 *)dst, value: 0, count: sizeof(dst));
        memset(v26, 0xFFu, sizeof(v26));
        v5[256] = 1;
        while ( 1 )
        {
          v6 = -1;
          v7 = 1000000000;
          for ( i = 0; i <= 256; ++i )
          {
            v9 = v5[i];
            if ( v9 != 0 && v9 <= v7 )
            {
              v7 = v5[i];
              v6 = i;
            }
          }
          v10 = -1;
          v38 = 1000000000;
          for ( j = 0; j <= 256; ++j )
          {
            v12 = v5[j];
            if ( v12 != 0 && v12 <= v38 && j != v6 )
            {
              v38 = v5[j];
              v10 = j;
            }
          }
          if ( v10 < 0 )
            break;
          v5[v6] += v5[v10];
          ++dst[v6];
          v13 = (int)v26[v6] < 0;
          v14 = &v26[v6];
          v5[v10] = 0;
          if ( !v13 )
          {
            do
            {
              v6 = *v14;
              ++dst[v6];
              v14 = &v26[v6];
            }
            while ( *v14 >= 0 );
          }
          ++dst[v10];
          v26[v6] = v10;
          v15 = &v26[v10];
          if ( *v15 >= 0 )
          {
            do
            {
              v16 = *v15;
              ++dst[v16];
              v13 = (int)v26[v16] < 0;
              v15 = &v26[v16];
            }
            while ( !v13 );
          }
        }
        for ( k = 0; k <= 256; ++k )
        {
          v18 = dst[k];
          if ( v18 != 0 )
          {
            if ( v18 > 32 )
            {
              cinfo->err->msg_code = 39;
              cinfo->err->error_exit(a1: cinfo);
            }
            ++*((_BYTE *)&v33 + v18);
          }
        }
        for ( m = 32; m > 16; --m )
        {
          for ( ; *((_BYTE *)&v33 + m) != 0; --*((_BYTE *)&v33 + n) )
          {
            for ( n = m - 2; *((_BYTE *)&v33 + n) == 0; --n )
              ;
            *((_BYTE *)&v33 + m) -= 2;
            ++*((_BYTE *)&v32 + m + 3);
            *((_BYTE *)&v33 + n + 1) += 2;
          }
        }
        for ( ; *((_BYTE *)&v33 + m) == 0; --m )
          ;
        --*((_BYTE *)&v33 + m);
        v21 = v32;
        v22 = v35;
        *v32 = v33;
        v21[1] = v34;
        *((_BYTE *)v21 + 16) = v22;
        v23 = 0;
        for ( ii = 1; ii <= 32; ++ii )
        {
          for ( jj = 0; jj <= 255; ++jj )
          {
            if ( dst[jj] == ii )
            {
              *((_BYTE *)v21 + v23 + 17) = jj;
              ++v23;
            }
          }
        }
        ac_tbl_no = actbl;
        v1 = cinfo;
        *((_BYTE *)v21 + 273) = 0;
        *v28 = 1;
      }
      if ( did_ac[ac_tbl_no] == 0 )
      {
        if ( *((_DWORD *)&v1[4].progress + ac_tbl_no) == 0 )
          *((_DWORD *)&v1[4].progress + ac_tbl_no) = jpeg_alloc_huff_table(cinfo: v1);
        jpeg_gen_optimal_table(
          cinfo: v1,
          htbl: *((JHUFF_TBL **)&v1[4].progress + ac_tbl_no),
          freq: entropy->ac_count_ptrs[ac_tbl_no]);
        did_ac[ac_tbl_no] = 1;
      }
      ++p_is_decompressor;
      ++ci;
    }
    while ( ci < (int)v1[9].client_data );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10254BB0
// Name: start_pass_huff
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_huff(jpeg_common_struct *cinfo, unsigned __int8 gather_statistics)
{
  jpeg_entropy_encoder *client_data; // edi
  unsigned int dc_tbl_no; // ebx
  unsigned int ac_tbl_no; // eax
  void (__cdecl **p_finish_pass)(jpeg_compress_struct *); // [esp+8h] [ebp-Ch]
  int ci; // [esp+Ch] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+10h] [ebp-4h]
  unsigned int actbl; // [esp+1Ch] [ebp+8h]

  client_data = (jpeg_entropy_encoder *)cinfo[14].client_data;
  if ( gather_statistics != 0 )
  {
    client_data->encode_mcu = encode_mcu_gather;
    client_data->finish_pass = (void (__cdecl *)(jpeg_compress_struct *))finish_pass_gather;
  }
  else
  {
    client_data->encode_mcu = encode_mcu_huff;
    client_data->finish_pass = finish_pass_huff;
  }
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_finish_pass = &client_data[1].finish_pass;
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      dc_tbl_no = (*p_is_decompressor)->dc_tbl_no;
      ac_tbl_no = (*p_is_decompressor)->ac_tbl_no;
      actbl = ac_tbl_no;
      if ( gather_statistics != 0 )
      {
        if ( dc_tbl_no >= 4 )
        {
          cinfo->err->msg_code = 50;
          cinfo->err->msg_parm.i[0] = dc_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
          ac_tbl_no = actbl;
        }
        if ( ac_tbl_no >= 4 )
        {
          cinfo->err->msg_code = 50;
          cinfo->err->msg_parm.i[0] = ac_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( *((_DWORD *)&client_data[6].encode_mcu + dc_tbl_no) == 0 )
          *((_DWORD *)&client_data[6].encode_mcu + dc_tbl_no) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
        memset(dst: *((unsigned __int8 **)&client_data[6].encode_mcu + dc_tbl_no), value: 0, count: 0x404u);
        if ( *((_DWORD *)&client_data[7].finish_pass + actbl) == 0 )
          *((_DWORD *)&client_data[7].finish_pass + actbl) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
        memset(dst: *((unsigned __int8 **)&client_data[7].finish_pass + actbl), value: 0, count: 0x404u);
      }
      else
      {
        jpeg_make_c_derived_tbl(
          cinfo,
          isDC: 1u,
          tblno: dc_tbl_no,
          pdtbl: (c_derived_tbl **)&client_data[3].finish_pass + dc_tbl_no);
        jpeg_make_c_derived_tbl(
          cinfo,
          isDC: 0,
          tblno: actbl,
          pdtbl: (c_derived_tbl **)&client_data[5].start_pass + actbl);
      }
      ++p_is_decompressor;
      *p_finish_pass = nullptr;
      ++ci;
      ++p_finish_pass;
    }
    while ( ci < (int)cinfo[9].client_data );
  }
  client_data[1].start_pass = nullptr;
  client_data[1].encode_mcu = nullptr;
  client_data[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))cinfo[7].global_state;
  client_data[3].encode_mcu = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10254D40
// Name: _jinit_huff_encoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_huff_encoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_encoder *v1; // eax

  v1 = (jpeg_entropy_encoder *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 108);
  cinfo[14].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))start_pass_huff;
  v1[5].start_pass = nullptr;
  v1[3].finish_pass = nullptr;
  v1[7].finish_pass = nullptr;
  v1[6].encode_mcu = nullptr;
  v1[5].encode_mcu = nullptr;
  v1[4].start_pass = nullptr;
  v1[8].start_pass = nullptr;
  v1[6].finish_pass = nullptr;
  v1[5].finish_pass = nullptr;
  v1[4].encode_mcu = nullptr;
  v1[8].encode_mcu = nullptr;
  v1[7].start_pass = nullptr;
  v1[6].start_pass = nullptr;
  v1[4].finish_pass = nullptr;
  v1[8].finish_pass = nullptr;
  v1[7].encode_mcu = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10254DA0
// Name: emit_bits_0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_bits_0(phuff_entropy_encoder *entropy@<esi>, unsigned int code, int size)
{
  int v3; // ebx
  int v4; // ebx
  unsigned int v5; // edi
  bool v6; // zf
  jpeg_destination_mgr *dest; // ebx
  int put_bits; // [esp+8h] [ebp-4h]
  jpeg_destination_mgr *codea; // [esp+14h] [ebp+8h]
  int sizea; // [esp+18h] [ebp+Ch]

  v3 = entropy->put_bits;
  if ( size == 0 )
  {
    entropy->cinfo->err->msg_code = 40;
    entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
  }
  if ( entropy->gather_statistics == 0 )
  {
    v4 = size + v3;
    v5 = entropy->put_buffer | ((code & ((1 << size) - 1)) << (24 - v4));
    if ( v4 >= 8 )
    {
      sizea = (unsigned int)v4 >> 3;
      put_bits = v4 - 8 * ((unsigned int)v4 >> 3);
      do
      {
        *entropy->next_output_byte++ = BYTE2(v5);
        v6 = entropy->free_in_buffer-- == 1;
        if ( v6 )
        {
          codea = entropy->cinfo->dest;
          if ( codea->empty_output_buffer(a1: entropy->cinfo) == 0 )
          {
            entropy->cinfo->err->msg_code = 24;
            entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
          }
          entropy->next_output_byte = codea->next_output_byte;
          entropy->free_in_buffer = codea->free_in_buffer;
        }
        if ( BYTE2(v5) == 255 )
        {
          *entropy->next_output_byte++ = 0;
          v6 = entropy->free_in_buffer-- == 1;
          if ( v6 )
          {
            dest = entropy->cinfo->dest;
            if ( dest->empty_output_buffer(a1: entropy->cinfo) == 0 )
            {
              entropy->cinfo->err->msg_code = 24;
              entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
            }
            entropy->next_output_byte = dest->next_output_byte;
            entropy->free_in_buffer = dest->free_in_buffer;
          }
        }
        v5 <<= 8;
        --sizea;
      }
      while ( sizea != 0 );
      v4 = put_bits;
    }
    entropy->put_buffer = v5;
    entropy->put_bits = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102550C0
// Name: emit_restart_0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_restart_0(phuff_entropy_encoder *entropy@<eax>, char restart_num)
{
  bool v3; // zf
  jpeg_destination_mgr *dest; // edi
  jpeg_destination_mgr *v5; // edi
  jpeg_compress_struct *cinfo; // ecx
  int v7; // eax
  int *last_dc_val; // ecx

  emit_eobrun(entropy);
  if ( entropy->gather_statistics == 0 )
  {
    emit_bits_0(entropy, code: 0x7Fu, size: 7);
    entropy->put_buffer = 0;
    entropy->put_bits = 0;
    *entropy->next_output_byte++ = -1;
    v3 = entropy->free_in_buffer-- == 1;
    if ( v3 )
    {
      dest = entropy->cinfo->dest;
      if ( dest->empty_output_buffer(a1: entropy->cinfo) == 0 )
      {
        entropy->cinfo->err->msg_code = 24;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
      entropy->next_output_byte = dest->next_output_byte;
      entropy->free_in_buffer = dest->free_in_buffer;
    }
    *entropy->next_output_byte++ = restart_num - 48;
    v3 = entropy->free_in_buffer-- == 1;
    if ( v3 )
    {
      v5 = entropy->cinfo->dest;
      if ( v5->empty_output_buffer(a1: entropy->cinfo) == 0 )
      {
        entropy->cinfo->err->msg_code = 24;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
      entropy->next_output_byte = v5->next_output_byte;
      entropy->free_in_buffer = v5->free_in_buffer;
    }
  }
  cinfo = entropy->cinfo;
  if ( cinfo->Ss != 0 )
  {
    entropy->EOBRUN = 0;
    entropy->BE = 0;
  }
  else
  {
    v7 = 0;
    if ( cinfo->comps_in_scan > 0 )
    {
      last_dc_val = entropy->last_dc_val;
      do
      {
        *last_dc_val = 0;
        ++v7;
        ++last_dc_val;
      }
      while ( v7 < entropy->cinfo->comps_in_scan );
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10253DC0
// Name: _jpeg_make_c_derived_tbl
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_make_c_derived_tbl(
        jpeg_common_struct *cinfo,
        unsigned __int8 isDC,
        unsigned int tblno,
        c_derived_tbl **pdtbl)
{
  int v5; // edi
  int i; // ebx
  unsigned int v7; // esi
  int v8; // ebx
  signed int v9; // edi
  int v10; // esi
  c_derived_tbl **v11; // edx
  char *v12; // eax
  int v13; // eax
  int j; // esi
  int v15; // edi
  unsigned int v16; // ecx
  char v17; // dl
  c_derived_tbl *v18; // eax
  unsigned int huffcode[257]; // [esp+Ch] [ebp-510h]
  char huffsize[260]; // [esp+410h] [ebp-10Ch] BYREF
  int lastp; // [esp+514h] [ebp-8h]
  c_derived_tbl *dtbl; // [esp+518h] [ebp-4h]
  JHUFF_TBL *htbl; // [esp+52Ch] [ebp+10h]
  c_derived_tbl **pdtbla; // [esp+530h] [ebp+14h]

  if ( tblno >= 4 )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( isDC != 0 )
    htbl = *((JHUFF_TBL **)&cinfo[3].is_decompressor + tblno);
  else
    htbl = *((JHUFF_TBL **)&cinfo[4].progress + tblno);
  if ( htbl == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *pdtbl == nullptr )
    *pdtbl = (c_derived_tbl *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1280);
  dtbl = *pdtbl;
  v5 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    v7 = htbl->bits[i];
    if ( (int)(v7 + v5) > 256 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v7 != 0 )
    {
      memset(dst: (unsigned __int8 *)&huffsize[v5], value: i, count: v7);
      v5 += v7;
    }
  }
  huffsize[v5] = 0;
  v8 = huffsize[0];
  lastp = v5;
  v9 = 0;
  v10 = 0;
  v11 = (c_derived_tbl **)__ROL4__(1, huffsize[0]);
  pdtbla = v11;
  if ( huffsize[0] != 0 )
  {
    v12 = huffsize;
    while ( 1 )
    {
      if ( *v12 == v8 )
      {
        do
        {
          v13 = huffsize[v10 + 1];
          huffcode[v10++] = v9++;
        }
        while ( v13 == v8 );
      }
      if ( v9 >= (int)v11 )
      {
        cinfo->err->msg_code = 8;
        cinfo->err->error_exit(a1: cinfo);
        v11 = pdtbla;
      }
      v9 *= 2;
      ++v8;
      v12 = &huffsize[v10];
      pdtbla = (c_derived_tbl **)__ROL4__(v11, 1);
      if ( huffsize[v10] == 0 )
        break;
      v11 = pdtbla;
    }
  }
  memset(dst: (unsigned __int8 *)dtbl->ehufsi, value: 0, count: sizeof(dtbl->ehufsi));
  for ( j = 0; j < lastp; v18->ehufsi[v15] = v17 )
  {
    v15 = htbl->huffval[j];
    if ( v15 > (isDC != 0 ? 15 : 255) || dtbl->ehufsi[v15] != 0 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    v16 = huffcode[j];
    v17 = huffsize[j];
    v18 = dtbl;
    ++j;
    dtbl->ehufco[v15] = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253FC0
// Name: emit_bits
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall emit_bits@<al>(working_state *state@<esi>, unsigned int code, int size)
{
  int v3; // ebx
  int v4; // ebx
  unsigned int v5; // edi
  bool v6; // zf
  jpeg_destination_mgr *dest; // ebx
  int v8; // eax
  int put_bits; // [esp+8h] [ebp-4h]
  jpeg_destination_mgr *sizea; // [esp+18h] [ebp+Ch]

  v3 = state->cur.put_bits;
  if ( size == 0 )
  {
    state->cinfo->err->msg_code = 40;
    state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
  }
  v4 = size + v3;
  put_bits = v4;
  v5 = state->cur.put_buffer | ((code & ((1 << size) - 1)) << (24 - v4));
  if ( v4 < 8 )
  {
LABEL_13:
    state->cur.put_buffer = v5;
    state->cur.put_bits = v4;
    return 1;
  }
  while ( 1 )
  {
    *state->next_output_byte++ = BYTE2(v5);
    v6 = state->free_in_buffer-- == 1;
    if ( v6 )
    {
      sizea = state->cinfo->dest;
      if ( sizea->empty_output_buffer(a1: state->cinfo) == 0 )
        return 0;
      state->next_output_byte = sizea->next_output_byte;
      state->free_in_buffer = sizea->free_in_buffer;
    }
    if ( BYTE2(v5) == 255 )
    {
      *state->next_output_byte++ = 0;
      v6 = state->free_in_buffer-- == 1;
      if ( v6 )
        break;
    }
LABEL_11:
    v8 = put_bits - 8;
    v5 <<= 8;
    put_bits = v8;
    if ( v8 < 8 )
    {
      v4 = v8;
      goto LABEL_13;
    }
  }
  dest = state->cinfo->dest;
  if ( dest->empty_output_buffer(a1: state->cinfo) != 0 )
  {
    state->next_output_byte = dest->next_output_byte;
    state->free_in_buffer = dest->free_in_buffer;
    goto LABEL_11;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102540B0
// Name: encode_one_block
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_one_block(
        working_state *state,
        __int16 *block,
        int last_dc_val,
        c_derived_tbl *dctbl,
        c_derived_tbl *actbl)
{
  signed int v5; // edi
  int v6; // eax
  int v7; // ebx
  working_state *v8; // esi
  int *v10; // eax
  int v11; // edi
  int v12; // ebx
  int v13; // ebx
  int v14; // esi
  working_state *v15; // ebx
  int *v16; // [esp+Ch] [ebp-4h]
  unsigned int temp2; // [esp+20h] [ebp+10h]
  int nbits; // [esp+24h] [ebp+14h]

  v5 = *block - last_dc_val;
  v6 = v5;
  if ( v5 < 0 )
  {
    v6 = last_dc_val - *block;
    --v5;
  }
  v7 = 0;
  if ( v6 == 0 )
    goto LABEL_7;
  do
  {
    ++v7;
    v6 >>= 1;
  }
  while ( v6 != 0 );
  if ( v7 > 11 )
  {
    v8 = state;
    state->cinfo->err->msg_code = 6;
    state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
  }
  else
  {
LABEL_7:
    v8 = state;
  }
  if ( emit_bits(state: v8, code: dctbl->ehufco[v7], size: dctbl->ehufsi[v7]) != 0
    && (v7 == 0 || emit_bits(state: v8, code: v5, size: v7) != 0) )
  {
    v10 = (int *)&unk_103CAB4C;
    v11 = 0;
    v16 = (int *)&unk_103CAB4C;
    do
    {
      v12 = block[*v10];
      if ( block[*v10] != 0 )
      {
        if ( v11 > 15 )
        {
          while ( emit_bits(state, code: actbl->ehufco[240], size: actbl->ehufsi[240]) != 0 )
          {
            v11 -= 16;
            if ( v11 <= 15 )
              goto LABEL_18;
          }
          return 0;
        }
LABEL_18:
        temp2 = v12;
        if ( v12 < 0 )
        {
          v12 = -v12;
          --temp2;
        }
        v13 = v12 >> 1;
        v14 = 1;
        nbits = 1;
        if ( v13 == 0 )
          goto LABEL_24;
        do
        {
          ++v14;
          v13 >>= 1;
        }
        while ( v13 != 0 );
        nbits = v14;
        if ( v14 > 10 )
        {
          v15 = state;
          state->cinfo->err->msg_code = 6;
          state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
        }
        else
        {
LABEL_24:
          v15 = state;
        }
        if ( emit_bits(state: v15, code: actbl->ehufco[16 * v11 + v14], size: actbl->ehufsi[16 * v11 + v14]) == 0
          || emit_bits(state: v15, code: temp2, size: nbits) == 0 )
        {
          return 0;
        }
        v10 = v16;
        v11 = 0;
      }
      else
      {
        ++v11;
      }
      v16 = ++v10;
    }
    while ( (int)v10 < (int)dword_103CAC48 );
    if ( v11 <= 0 || emit_bits(state, code: actbl->ehufco[0], size: actbl->ehufsi[0]) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10254260
// Name: emit_restart
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall emit_restart@<al>(working_state *state@<eax>, char restart_num)
{
  bool v3; // zf
  jpeg_destination_mgr *dest; // edi
  jpeg_destination_mgr *v5; // edi
  int v6; // eax
  int *last_dc_val; // ecx

  if ( emit_bits(state, code: 0x7Fu, size: 7) == 0 )
    return 0;
  state->cur.put_buffer = 0;
  state->cur.put_bits = 0;
  *state->next_output_byte++ = -1;
  v3 = state->free_in_buffer-- == 1;
  if ( v3 )
  {
    dest = state->cinfo->dest;
    if ( dest->empty_output_buffer(a1: state->cinfo) == 0 )
      return 0;
    state->next_output_byte = dest->next_output_byte;
    state->free_in_buffer = dest->free_in_buffer;
  }
  *state->next_output_byte++ = restart_num - 48;
  v3 = state->free_in_buffer-- == 1;
  if ( v3 )
  {
    v5 = state->cinfo->dest;
    if ( v5->empty_output_buffer(a1: state->cinfo) != 0 )
    {
      state->next_output_byte = v5->next_output_byte;
      state->free_in_buffer = v5->free_in_buffer;
      goto LABEL_8;
    }
    return 0;
  }
LABEL_8:
  v6 = 0;
  if ( state->cinfo->comps_in_scan > 0 )
  {
    last_dc_val = state->cur.last_dc_val;
    do
    {
      *last_dc_val = 0;
      ++v6;
      ++last_dc_val;
    }
    while ( v6 < state->cinfo->comps_in_scan );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10254320
// Name: encode_mcu_huff
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_huff(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  bool v3; // zf
  jpeg_entropy_encoder *entropy; // esi
  jpeg_destination_mgr *dest; // eax
  unsigned __int8 *next_output_byte; // ecx
  unsigned int free_in_buffer; // edx
  unsigned __int8 result; // al
  int v9; // ebx
  jpeg_component_info *v10; // ecx
  __int16 *v11; // edx
  int v12; // eax
  __int64 v13; // xmm0_8
  unsigned int restart_interval; // edi
  int v15; // eax
  c_derived_tbl *v16; // [esp-Ch] [ebp-3Ch]
  c_derived_tbl *v17; // [esp-8h] [ebp-38h]
  working_state state; // [esp+8h] [ebp-28h] BYREF
  int *v19; // [esp+2Ch] [ebp-4h]
  int *cinfoa; // [esp+38h] [ebp+8h]

  v3 = cinfo->restart_interval == 0;
  entropy = cinfo->entropy;
  dest = cinfo->dest;
  next_output_byte = dest->next_output_byte;
  free_in_buffer = dest->free_in_buffer;
  *(_QWORD *)&state.cur.put_buffer = *(_QWORD *)&entropy[1].start_pass;
  *(_QWORD *)state.cur.last_dc_val = *(_QWORD *)&entropy[1].finish_pass;
  state.next_output_byte = next_output_byte;
  state.free_in_buffer = free_in_buffer;
  *(_QWORD *)&state.cur.last_dc_val[2] = *(_QWORD *)&entropy[2].encode_mcu;
  state.cinfo = cinfo;
  if ( v3
    || entropy[3].start_pass != nullptr
    || (result = emit_restart(&state, restart_num: (char)entropy[3].encode_mcu)) != 0 )
  {
    v9 = 0;
    if ( cinfo->blocks_in_MCU <= 0 )
    {
LABEL_8:
      v13 = *(_QWORD *)&state.cur.put_buffer;
      cinfo->dest->next_output_byte = state.next_output_byte;
      cinfo->dest->free_in_buffer = state.free_in_buffer;
      *(_QWORD *)&entropy[1].start_pass = v13;
      *(_OWORD *)&entropy[1].finish_pass = *(_OWORD *)state.cur.last_dc_val;
      restart_interval = cinfo->restart_interval;
      if ( restart_interval != 0 )
      {
        if ( entropy[3].start_pass == nullptr )
        {
          v15 = ((unsigned __int8)entropy[3].encode_mcu + 1) & 7;
          entropy[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))restart_interval;
          entropy[3].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))v15;
        }
        --entropy[3].start_pass;
      }
      return 1;
    }
    else
    {
      cinfoa = cinfo->MCU_membership;
      while ( 1 )
      {
        v10 = cinfo->cur_comp_info[*cinfoa];
        v17 = *((c_derived_tbl **)&entropy[5].start_pass + v10->ac_tbl_no);
        v16 = *((c_derived_tbl **)&entropy[3].finish_pass + v10->dc_tbl_no);
        v11 = (__int16 *)MCU_data[v9];
        v19 = &state.cur.last_dc_val[*cinfoa];
        if ( encode_one_block(&state, block: v11, last_dc_val: *v19, dctbl: v16, actbl: v17) == 0 )
          return 0;
        v12 = (*MCU_data[v9])[0];
        ++cinfoa;
        ++v9;
        *v19 = v12;
        if ( v9 >= cinfo->blocks_in_MCU )
          goto LABEL_8;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10254460
// Name: finish_pass_huff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_huff(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // eax
  unsigned __int8 *next_output_byte; // ecx
  unsigned int free_in_buffer; // edx
  jpeg_entropy_encoder *entropy; // edi
  __int64 v5; // xmm0_8
  __int64 v6; // xmm0_8
  working_state state; // [esp+Ch] [ebp-24h] BYREF

  dest = cinfo->dest;
  next_output_byte = dest->next_output_byte;
  free_in_buffer = dest->free_in_buffer;
  entropy = cinfo->entropy;
  *(_QWORD *)&state.cur.put_buffer = *(_QWORD *)&entropy[1].start_pass;
  *(_QWORD *)state.cur.last_dc_val = *(_QWORD *)&entropy[1].finish_pass;
  v5 = *(_QWORD *)&entropy[2].encode_mcu;
  state.next_output_byte = next_output_byte;
  state.free_in_buffer = free_in_buffer;
  *(_QWORD *)&state.cur.last_dc_val[2] = v5;
  state.cinfo = cinfo;
  if ( emit_bits(&state, code: 0x7Fu, size: 7) != 0 )
  {
    state.cur.put_buffer = 0;
    state.cur.put_bits = 0;
  }
  else
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
  }
  v6 = *(_QWORD *)&state.cur.put_buffer;
  cinfo->dest->next_output_byte = state.next_output_byte;
  cinfo->dest->free_in_buffer = state.free_in_buffer;
  *(_QWORD *)&entropy[1].start_pass = v6;
  *(_OWORD *)&entropy[1].finish_pass = *(_OWORD *)state.cur.last_dc_val;
}

//------------------------------------------------------------------------------
// Address: 0x10254510
// Name: encode_mcu_gather
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_gather(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_compress_struct *v2; // edx
  jpeg_entropy_encoder *p_pub; // esi
  int v4; // eax
  void (__cdecl **p_finish_pass)(jpeg_compress_struct *); // ecx
  jpeg_component_info *v6; // eax
  int v7; // edi
  _DWORD *v8; // ebx
  int v9; // eax
  int v10; // esi
  int *v11; // eax
  int v12; // esi
  int v13; // ecx
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // edi
  __int16 *v18; // [esp+4h] [ebp-18h]
  int ci; // [esp+8h] [ebp-14h]
  huff_entropy_encoder *entropy; // [esp+Ch] [ebp-10h]
  int *v21; // [esp+10h] [ebp-Ch]
  int *MCU_membership; // [esp+14h] [ebp-8h]
  int blkn; // [esp+18h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->entropy;
  entropy = (huff_entropy_encoder *)p_pub;
  if ( cinfo->restart_interval != 0 )
  {
    if ( p_pub[3].start_pass == nullptr )
    {
      v4 = 0;
      if ( cinfo->comps_in_scan > 0 )
      {
        p_finish_pass = &p_pub[1].finish_pass;
        do
        {
          *p_finish_pass = nullptr;
          ++v4;
          ++p_finish_pass;
        }
        while ( v4 < cinfo->comps_in_scan );
      }
      p_pub[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))cinfo->restart_interval;
    }
    --p_pub[3].start_pass;
  }
  blkn = 0;
  if ( cinfo->blocks_in_MCU > 0 )
  {
    MCU_membership = cinfo->MCU_membership;
    do
    {
      ci = *MCU_membership;
      v6 = v2->cur_comp_info[*MCU_membership];
      v7 = *((_DWORD *)&p_pub[6].encode_mcu + v6->dc_tbl_no);
      v8 = *((_DWORD **)&p_pub[7].finish_pass + v6->ac_tbl_no);
      v18 = (__int16 *)MCU_data[blkn];
      v9 = *v18 - *((_DWORD *)&p_pub[1].finish_pass + *MCU_membership);
      if ( v9 < 0 )
        v9 = *((_DWORD *)&p_pub[1].finish_pass + *MCU_membership) - *v18;
      v10 = 0;
      if ( v9 != 0 )
      {
        do
        {
          ++v10;
          v9 >>= 1;
        }
        while ( v9 != 0 );
        if ( v10 > 11 )
        {
          v2->err->msg_code = 6;
          v2->err->error_exit(a1: (jpeg_common_struct *)v2);
          v2 = cinfo;
        }
      }
      ++*(_DWORD *)(v7 + 4 * v10);
      v11 = (int *)&unk_103CAB4C;
      v12 = 0;
      v21 = (int *)&unk_103CAB4C;
      do
      {
        v13 = v18[*v11];
        if ( v18[*v11] != 0 )
        {
          if ( v12 > 15 )
          {
            v14 = ((unsigned int)(v12 - 16) >> 4) + 1;
            v12 += -16 * v14;
            v8[240] += v14;
            v2 = cinfo;
          }
          if ( v13 < 0 )
            v13 = -v13;
          v15 = v13 >> 1;
          v16 = 1;
          if ( v15 != 0 )
          {
            do
            {
              ++v16;
              v15 >>= 1;
            }
            while ( v15 != 0 );
            if ( v16 > 10 )
            {
              v2->err->msg_code = 6;
              v2->err->error_exit(a1: (jpeg_common_struct *)v2);
              v2 = cinfo;
            }
          }
          ++v8[16 * v12 + v16];
          v11 = v21;
          v12 = 0;
        }
        else
        {
          ++v12;
        }
        v21 = ++v11;
      }
      while ( (int)v11 < (int)dword_103CAC48 );
      if ( v12 > 0 )
        ++*v8;
      p_pub = &entropy->pub;
      ++MCU_membership;
      entropy->saved.last_dc_val[ci] = (*MCU_data[blkn++])[0];
    }
    while ( blkn < v2->blocks_in_MCU );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102546B0
// Name: _jpeg_gen_optimal_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_gen_optimal_table(jpeg_common_struct *cinfo, JHUFF_TBL *htbl, int *freq)
{
  int v3; // eax
  int v4; // esi
  int i; // ecx
  int v6; // edx
  int v7; // edx
  int v8; // edi
  int j; // ecx
  int v10; // esi
  bool v11; // sf
  int *v12; // ecx
  int *v13; // eax
  int v14; // eax
  int k; // edi
  int v16; // esi
  int v17; // esi
  int v18; // ecx
  int v19; // edx
  int m; // eax
  unsigned __int8 v21; // dl
  int v22; // edx
  int n; // esi
  int ii; // eax
  int others[257]; // [esp+Ch] [ebp-82Ch] BYREF
  int codesize[257]; // [esp+410h] [ebp-428h] BYREF
  unsigned __int8 bits[33]; // [esp+814h] [ebp-24h] BYREF

  memset(bits, 0, sizeof(bits));
  memset(dst: (unsigned __int8 *)codesize, value: 0, count: sizeof(codesize));
  memset(others, 0xFFu, sizeof(others));
  freq[256] = 1;
  while ( 1 )
  {
    v3 = -1;
    v4 = 1000000000;
    for ( i = 0; i <= 256; ++i )
    {
      v6 = freq[i];
      if ( v6 != 0 && v6 <= v4 )
      {
        v4 = freq[i];
        v3 = i;
      }
    }
    v7 = -1;
    v8 = 1000000000;
    for ( j = 0; j <= 256; ++j )
    {
      v10 = freq[j];
      if ( v10 != 0 && v10 <= v8 && j != v3 )
      {
        v8 = freq[j];
        v7 = j;
      }
    }
    if ( v7 < 0 )
      break;
    freq[v3] += freq[v7];
    ++codesize[v3];
    v11 = others[v3] < 0;
    v12 = &others[v3];
    freq[v7] = 0;
    if ( !v11 )
    {
      do
      {
        v3 = *v12;
        ++codesize[v3];
        v12 = &others[v3];
      }
      while ( *v12 >= 0 );
    }
    ++codesize[v7];
    others[v3] = v7;
    v13 = &others[v7];
    if ( *v13 >= 0 )
    {
      do
      {
        v14 = *v13;
        ++codesize[v14];
        v11 = others[v14] < 0;
        v13 = &others[v14];
      }
      while ( !v11 );
    }
  }
  for ( k = 0; k <= 256; ++k )
  {
    v16 = codesize[k];
    if ( v16 != 0 )
    {
      if ( v16 > 32 )
      {
        cinfo->err->msg_code = 39;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++bits[v16];
    }
  }
  v17 = 16;
  v18 = 30;
  v19 = 16;
  do
  {
    for ( ; bits[v18 + 2] != 0; --bits[m] )
    {
      for ( m = v18; bits[m] == 0; --m )
        ;
      bits[v18 + 2] -= 2;
      ++bits[v18 + 1];
      bits[m + 1] += 2;
    }
    --v18;
    --v17;
  }
  while ( v17 != 0 );
  if ( bits[16] == 0 )
  {
    do
      --v19;
    while ( bits[v19] == 0 );
  }
  --bits[v19];
  v21 = bits[16];
  *(_QWORD *)htbl->bits = *(_QWORD *)bits;
  *(_QWORD *)&htbl->bits[8] = *(_QWORD *)&bits[8];
  htbl->bits[16] = v21;
  v22 = 0;
  for ( n = 1; n <= 32; ++n )
  {
    for ( ii = 0; ii <= 255; ++ii )
    {
      if ( codesize[ii] == n )
        htbl->huffval[v22++] = ii;
    }
  }
  htbl->sent_table = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102548E0
// Name: finish_pass_gather
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_gather(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // edi
  int dc_tbl_no; // esi
  bool v3; // zf
  int ac_tbl_no; // ebx
  int *v5; // ebx
  int v6; // eax
  int v7; // esi
  int i; // ecx
  int v9; // edx
  int v10; // edx
  int j; // ecx
  int v12; // esi
  bool v13; // sf
  int *v14; // ecx
  int *v15; // eax
  int v16; // eax
  int k; // ebx
  int v18; // esi
  int m; // ecx
  int n; // eax
  _QWORD *v21; // ecx
  char v22; // al
  int v23; // edx
  int ii; // esi
  int jj; // eax
  _DWORD v26[257]; // [esp+4h] [ebp-850h] BYREF
  _DWORD dst[257]; // [esp+408h] [ebp-44Ch] BYREF
  unsigned __int8 *v28; // [esp+80Ch] [ebp-48h]
  int actbl; // [esp+810h] [ebp-44h]
  unsigned __int8 did_dc[4]; // [esp+814h] [ebp-40h] BYREF
  unsigned __int8 did_ac[4]; // [esp+818h] [ebp-3Ch]
  _QWORD *v32; // [esp+81Ch] [ebp-38h]
  __int64 v33; // [esp+820h] [ebp-34h]
  __int64 v34; // [esp+828h] [ebp-2Ch]
  __int64 v35; // [esp+830h] [ebp-24h]
  __int64 v36; // [esp+838h] [ebp-1Ch]
  char v37; // [esp+840h] [ebp-14h]
  int v38; // [esp+844h] [ebp-10h]
  int ci; // [esp+848h] [ebp-Ch]
  huff_entropy_encoder *entropy; // [esp+84Ch] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+850h] [ebp-4h]

  v1 = cinfo;
  entropy = (huff_entropy_encoder *)cinfo[14].client_data;
  *(_DWORD *)did_dc = 0;
  *(_DWORD *)did_ac = 0;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      dc_tbl_no = (*p_is_decompressor)->dc_tbl_no;
      v3 = did_dc[dc_tbl_no] == 0;
      ac_tbl_no = (*p_is_decompressor)->ac_tbl_no;
      actbl = ac_tbl_no;
      v28 = &did_dc[dc_tbl_no];
      if ( v3 )
      {
        if ( *((_DWORD *)&v1[3].is_decompressor + dc_tbl_no) == 0 )
          *((_DWORD *)&v1[3].is_decompressor + dc_tbl_no) = jpeg_alloc_huff_table(cinfo: v1);
        v5 = entropy->dc_count_ptrs[dc_tbl_no];
        v32 = *((_QWORD **)&v1[3].is_decompressor + dc_tbl_no);
        v33 = 0;
        v34 = 0;
        v35 = 0;
        v36 = 0;
        v37 = 0;
        memset((unsigned __int8 *)dst, value: 0, count: sizeof(dst));
        memset(v26, 0xFFu, sizeof(v26));
        v5[256] = 1;
        while ( 1 )
        {
          v6 = -1;
          v7 = 1000000000;
          for ( i = 0; i <= 256; ++i )
          {
            v9 = v5[i];
            if ( v9 != 0 && v9 <= v7 )
            {
              v7 = v5[i];
              v6 = i;
            }
          }
          v10 = -1;
          v38 = 1000000000;
          for ( j = 0; j <= 256; ++j )
          {
            v12 = v5[j];
            if ( v12 != 0 && v12 <= v38 && j != v6 )
            {
              v38 = v5[j];
              v10 = j;
            }
          }
          if ( v10 < 0 )
            break;
          v5[v6] += v5[v10];
          ++dst[v6];
          v13 = (int)v26[v6] < 0;
          v14 = &v26[v6];
          v5[v10] = 0;
          if ( !v13 )
          {
            do
            {
              v6 = *v14;
              ++dst[v6];
              v14 = &v26[v6];
            }
            while ( *v14 >= 0 );
          }
          ++dst[v10];
          v26[v6] = v10;
          v15 = &v26[v10];
          if ( *v15 >= 0 )
          {
            do
            {
              v16 = *v15;
              ++dst[v16];
              v13 = (int)v26[v16] < 0;
              v15 = &v26[v16];
            }
            while ( !v13 );
          }
        }
        for ( k = 0; k <= 256; ++k )
        {
          v18 = dst[k];
          if ( v18 != 0 )
          {
            if ( v18 > 32 )
            {
              cinfo->err->msg_code = 39;
              cinfo->err->error_exit(a1: cinfo);
            }
            ++*((_BYTE *)&v33 + v18);
          }
        }
        for ( m = 32; m > 16; --m )
        {
          for ( ; *((_BYTE *)&v33 + m) != 0; --*((_BYTE *)&v33 + n) )
          {
            for ( n = m - 2; *((_BYTE *)&v33 + n) == 0; --n )
              ;
            *((_BYTE *)&v33 + m) -= 2;
            ++*((_BYTE *)&v32 + m + 3);
            *((_BYTE *)&v33 + n + 1) += 2;
          }
        }
        for ( ; *((_BYTE *)&v33 + m) == 0; --m )
          ;
        --*((_BYTE *)&v33 + m);
        v21 = v32;
        v22 = v35;
        *v32 = v33;
        v21[1] = v34;
        *((_BYTE *)v21 + 16) = v22;
        v23 = 0;
        for ( ii = 1; ii <= 32; ++ii )
        {
          for ( jj = 0; jj <= 255; ++jj )
          {
            if ( dst[jj] == ii )
            {
              *((_BYTE *)v21 + v23 + 17) = jj;
              ++v23;
            }
          }
        }
        ac_tbl_no = actbl;
        v1 = cinfo;
        *((_BYTE *)v21 + 273) = 0;
        *v28 = 1;
      }
      if ( did_ac[ac_tbl_no] == 0 )
      {
        if ( *((_DWORD *)&v1[4].progress + ac_tbl_no) == 0 )
          *((_DWORD *)&v1[4].progress + ac_tbl_no) = jpeg_alloc_huff_table(cinfo: v1);
        jpeg_gen_optimal_table(
          cinfo: v1,
          htbl: *((JHUFF_TBL **)&v1[4].progress + ac_tbl_no),
          freq: entropy->ac_count_ptrs[ac_tbl_no]);
        did_ac[ac_tbl_no] = 1;
      }
      ++p_is_decompressor;
      ++ci;
    }
    while ( ci < (int)v1[9].client_data );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10254BE0
// Name: start_pass_huff
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_huff(jpeg_common_struct *cinfo, unsigned __int8 gather_statistics)
{
  jpeg_entropy_encoder *client_data; // edi
  unsigned int dc_tbl_no; // ebx
  unsigned int ac_tbl_no; // eax
  void (__cdecl **p_finish_pass)(jpeg_compress_struct *); // [esp+8h] [ebp-Ch]
  int ci; // [esp+Ch] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+10h] [ebp-4h]
  unsigned int actbl; // [esp+1Ch] [ebp+8h]

  client_data = (jpeg_entropy_encoder *)cinfo[14].client_data;
  if ( gather_statistics != 0 )
  {
    client_data->encode_mcu = encode_mcu_gather;
    client_data->finish_pass = (void (__cdecl *)(jpeg_compress_struct *))finish_pass_gather;
  }
  else
  {
    client_data->encode_mcu = encode_mcu_huff;
    client_data->finish_pass = finish_pass_huff;
  }
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_finish_pass = &client_data[1].finish_pass;
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      dc_tbl_no = (*p_is_decompressor)->dc_tbl_no;
      ac_tbl_no = (*p_is_decompressor)->ac_tbl_no;
      actbl = ac_tbl_no;
      if ( gather_statistics != 0 )
      {
        if ( dc_tbl_no >= 4 )
        {
          cinfo->err->msg_code = 50;
          cinfo->err->msg_parm.i[0] = dc_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
          ac_tbl_no = actbl;
        }
        if ( ac_tbl_no >= 4 )
        {
          cinfo->err->msg_code = 50;
          cinfo->err->msg_parm.i[0] = ac_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( *((_DWORD *)&client_data[6].encode_mcu + dc_tbl_no) == 0 )
          *((_DWORD *)&client_data[6].encode_mcu + dc_tbl_no) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
        memset(dst: *((unsigned __int8 **)&client_data[6].encode_mcu + dc_tbl_no), value: 0, count: 0x404u);
        if ( *((_DWORD *)&client_data[7].finish_pass + actbl) == 0 )
          *((_DWORD *)&client_data[7].finish_pass + actbl) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
        memset(dst: *((unsigned __int8 **)&client_data[7].finish_pass + actbl), value: 0, count: 0x404u);
      }
      else
      {
        jpeg_make_c_derived_tbl(
          cinfo,
          isDC: 1u,
          tblno: dc_tbl_no,
          pdtbl: (c_derived_tbl **)&client_data[3].finish_pass + dc_tbl_no);
        jpeg_make_c_derived_tbl(
          cinfo,
          isDC: 0,
          tblno: actbl,
          pdtbl: (c_derived_tbl **)&client_data[5].start_pass + actbl);
      }
      ++p_is_decompressor;
      *p_finish_pass = nullptr;
      ++ci;
      ++p_finish_pass;
    }
    while ( ci < (int)cinfo[9].client_data );
  }
  client_data[1].start_pass = nullptr;
  client_data[1].encode_mcu = nullptr;
  client_data[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))cinfo[7].global_state;
  client_data[3].encode_mcu = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10254D70
// Name: _jinit_huff_encoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_huff_encoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_encoder *v1; // eax

  v1 = (jpeg_entropy_encoder *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 108);
  cinfo[14].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))start_pass_huff;
  v1[5].start_pass = nullptr;
  v1[3].finish_pass = nullptr;
  v1[7].finish_pass = nullptr;
  v1[6].encode_mcu = nullptr;
  v1[5].encode_mcu = nullptr;
  v1[4].start_pass = nullptr;
  v1[8].start_pass = nullptr;
  v1[6].finish_pass = nullptr;
  v1[5].finish_pass = nullptr;
  v1[4].encode_mcu = nullptr;
  v1[8].encode_mcu = nullptr;
  v1[7].start_pass = nullptr;
  v1[6].start_pass = nullptr;
  v1[4].finish_pass = nullptr;
  v1[8].finish_pass = nullptr;
  v1[7].encode_mcu = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10254DD0
// Name: emit_bits_0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_bits_0(phuff_entropy_encoder *entropy@<esi>, unsigned int code, int size)
{
  int v3; // ebx
  int v4; // ebx
  unsigned int v5; // edi
  bool v6; // zf
  jpeg_destination_mgr *dest; // ebx
  int put_bits; // [esp+8h] [ebp-4h]
  jpeg_destination_mgr *codea; // [esp+14h] [ebp+8h]
  int sizea; // [esp+18h] [ebp+Ch]

  v3 = entropy->put_bits;
  if ( size == 0 )
  {
    entropy->cinfo->err->msg_code = 40;
    entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
  }
  if ( entropy->gather_statistics == 0 )
  {
    v4 = size + v3;
    v5 = entropy->put_buffer | ((code & ((1 << size) - 1)) << (24 - v4));
    if ( v4 >= 8 )
    {
      sizea = (unsigned int)v4 >> 3;
      put_bits = v4 - 8 * ((unsigned int)v4 >> 3);
      do
      {
        *entropy->next_output_byte++ = BYTE2(v5);
        v6 = entropy->free_in_buffer-- == 1;
        if ( v6 )
        {
          codea = entropy->cinfo->dest;
          if ( codea->empty_output_buffer(a1: entropy->cinfo) == 0 )
          {
            entropy->cinfo->err->msg_code = 24;
            entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
          }
          entropy->next_output_byte = codea->next_output_byte;
          entropy->free_in_buffer = codea->free_in_buffer;
        }
        if ( BYTE2(v5) == 255 )
        {
          *entropy->next_output_byte++ = 0;
          v6 = entropy->free_in_buffer-- == 1;
          if ( v6 )
          {
            dest = entropy->cinfo->dest;
            if ( dest->empty_output_buffer(a1: entropy->cinfo) == 0 )
            {
              entropy->cinfo->err->msg_code = 24;
              entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
            }
            entropy->next_output_byte = dest->next_output_byte;
            entropy->free_in_buffer = dest->free_in_buffer;
          }
        }
        v5 <<= 8;
        --sizea;
      }
      while ( sizea != 0 );
      v4 = put_bits;
    }
    entropy->put_buffer = v5;
    entropy->put_bits = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102550F0
// Name: emit_restart_0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_restart_0(phuff_entropy_encoder *entropy@<eax>, char restart_num)
{
  bool v3; // zf
  jpeg_destination_mgr *dest; // edi
  jpeg_destination_mgr *v5; // edi
  jpeg_compress_struct *cinfo; // ecx
  int v7; // eax
  int *last_dc_val; // ecx

  emit_eobrun(entropy);
  if ( entropy->gather_statistics == 0 )
  {
    emit_bits_0(entropy, code: 0x7Fu, size: 7);
    entropy->put_buffer = 0;
    entropy->put_bits = 0;
    *entropy->next_output_byte++ = -1;
    v3 = entropy->free_in_buffer-- == 1;
    if ( v3 )
    {
      dest = entropy->cinfo->dest;
      if ( dest->empty_output_buffer(a1: entropy->cinfo) == 0 )
      {
        entropy->cinfo->err->msg_code = 24;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
      entropy->next_output_byte = dest->next_output_byte;
      entropy->free_in_buffer = dest->free_in_buffer;
    }
    *entropy->next_output_byte++ = restart_num - 48;
    v3 = entropy->free_in_buffer-- == 1;
    if ( v3 )
    {
      v5 = entropy->cinfo->dest;
      if ( v5->empty_output_buffer(a1: entropy->cinfo) == 0 )
      {
        entropy->cinfo->err->msg_code = 24;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
      entropy->next_output_byte = v5->next_output_byte;
      entropy->free_in_buffer = v5->free_in_buffer;
    }
  }
  cinfo = entropy->cinfo;
  if ( cinfo->Ss != 0 )
  {
    entropy->EOBRUN = 0;
    entropy->BE = 0;
  }
  else
  {
    v7 = 0;
    if ( cinfo->comps_in_scan > 0 )
    {
      last_dc_val = entropy->last_dc_val;
      do
      {
        *last_dc_val = 0;
        ++v7;
        ++last_dc_val;
      }
      while ( v7 < entropy->cinfo->comps_in_scan );
    }
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x004082E0
// Name: _jpeg_make_c_derived_tbl
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_make_c_derived_tbl(
        jpeg_common_struct *cinfo,
        unsigned __int8 isDC,
        unsigned int tblno,
        c_derived_tbl **pdtbl)
{
  int v5; // edi
  int i; // ebx
  unsigned int v7; // esi
  int v8; // ebx
  signed int v9; // edi
  int v10; // esi
  c_derived_tbl **v11; // edx
  char *v12; // eax
  int v13; // eax
  int j; // esi
  int v15; // edi
  unsigned int v16; // ecx
  char v17; // dl
  c_derived_tbl *v18; // eax
  unsigned int huffcode[257]; // [esp+Ch] [ebp-510h]
  char huffsize[260]; // [esp+410h] [ebp-10Ch] BYREF
  int lastp; // [esp+514h] [ebp-8h]
  c_derived_tbl *dtbl; // [esp+518h] [ebp-4h]
  JHUFF_TBL *htbl; // [esp+52Ch] [ebp+10h]
  c_derived_tbl **pdtbla; // [esp+530h] [ebp+14h]

  if ( tblno >= 4 )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( isDC != 0 )
    htbl = *((JHUFF_TBL **)&cinfo[3].is_decompressor + tblno);
  else
    htbl = *((JHUFF_TBL **)&cinfo[4].progress + tblno);
  if ( htbl == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *pdtbl == nullptr )
    *pdtbl = (c_derived_tbl *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1280);
  dtbl = *pdtbl;
  v5 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    v7 = htbl->bits[i];
    if ( (int)(v7 + v5) > 256 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v7 != 0 )
    {
      memset(dst: (unsigned __int8 *)&huffsize[v5], value: i, count: v7);
      v5 += v7;
    }
  }
  huffsize[v5] = 0;
  v8 = huffsize[0];
  lastp = v5;
  v9 = 0;
  v10 = 0;
  v11 = (c_derived_tbl **)__ROL4__(1, huffsize[0]);
  pdtbla = v11;
  if ( huffsize[0] != 0 )
  {
    v12 = huffsize;
    while ( 1 )
    {
      if ( *v12 == v8 )
      {
        do
        {
          v13 = huffsize[v10 + 1];
          huffcode[v10++] = v9++;
        }
        while ( v13 == v8 );
      }
      if ( v9 >= (int)v11 )
      {
        cinfo->err->msg_code = 8;
        cinfo->err->error_exit(a1: cinfo);
        v11 = pdtbla;
      }
      v9 *= 2;
      ++v8;
      v12 = &huffsize[v10];
      pdtbla = (c_derived_tbl **)__ROL4__(v11, 1);
      if ( huffsize[v10] == 0 )
        break;
      v11 = pdtbla;
    }
  }
  memset(dst: (unsigned __int8 *)dtbl->ehufsi, value: 0, count: sizeof(dtbl->ehufsi));
  for ( j = 0; j < lastp; v18->ehufsi[v15] = v17 )
  {
    v15 = htbl->huffval[j];
    if ( v15 > (isDC != 0 ? 15 : 255) || dtbl->ehufsi[v15] != 0 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    v16 = huffcode[j];
    v17 = huffsize[j];
    v18 = dtbl;
    ++j;
    dtbl->ehufco[v15] = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004084E0
// Name: emit_bits
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall emit_bits@<al>(working_state *state@<esi>, unsigned int code, int size)
{
  int v3; // ebx
  int v4; // ebx
  unsigned int v5; // edi
  bool v6; // zf
  jpeg_destination_mgr *dest; // ebx
  int v8; // eax
  int put_bits; // [esp+8h] [ebp-4h]
  jpeg_destination_mgr *sizea; // [esp+18h] [ebp+Ch]

  v3 = state->cur.put_bits;
  if ( size == 0 )
  {
    state->cinfo->err->msg_code = 40;
    state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
  }
  v4 = size + v3;
  put_bits = v4;
  v5 = state->cur.put_buffer | ((code & ((1 << size) - 1)) << (24 - v4));
  if ( v4 < 8 )
  {
LABEL_13:
    state->cur.put_buffer = v5;
    state->cur.put_bits = v4;
    return 1;
  }
  while ( 1 )
  {
    *state->next_output_byte++ = BYTE2(v5);
    v6 = state->free_in_buffer-- == 1;
    if ( v6 )
    {
      sizea = state->cinfo->dest;
      if ( sizea->empty_output_buffer(a1: state->cinfo) == 0 )
        return 0;
      state->next_output_byte = sizea->next_output_byte;
      state->free_in_buffer = sizea->free_in_buffer;
    }
    if ( BYTE2(v5) == 255 )
    {
      *state->next_output_byte++ = 0;
      v6 = state->free_in_buffer-- == 1;
      if ( v6 )
        break;
    }
LABEL_11:
    v8 = put_bits - 8;
    v5 <<= 8;
    put_bits = v8;
    if ( v8 < 8 )
    {
      v4 = v8;
      goto LABEL_13;
    }
  }
  dest = state->cinfo->dest;
  if ( dest->empty_output_buffer(a1: state->cinfo) != 0 )
  {
    state->next_output_byte = dest->next_output_byte;
    state->free_in_buffer = dest->free_in_buffer;
    goto LABEL_11;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004085D0
// Name: encode_one_block
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_one_block(
        working_state *state,
        __int16 *block,
        int last_dc_val,
        c_derived_tbl *dctbl,
        c_derived_tbl *actbl)
{
  signed int v5; // edi
  int v6; // eax
  int v7; // ebx
  working_state *v8; // esi
  int *v10; // eax
  int v11; // edi
  int v12; // ebx
  int v13; // ebx
  int v14; // esi
  working_state *v15; // ebx
  int *v16; // [esp+Ch] [ebp-4h]
  unsigned int temp2; // [esp+20h] [ebp+10h]
  int nbits; // [esp+24h] [ebp+14h]

  v5 = *block - last_dc_val;
  v6 = v5;
  if ( v5 < 0 )
  {
    v6 = last_dc_val - *block;
    --v5;
  }
  v7 = 0;
  if ( v6 == 0 )
    goto LABEL_7;
  do
  {
    ++v7;
    v6 >>= 1;
  }
  while ( v6 != 0 );
  if ( v7 > 11 )
  {
    v8 = state;
    state->cinfo->err->msg_code = 6;
    state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
  }
  else
  {
LABEL_7:
    v8 = state;
  }
  if ( emit_bits(state: v8, code: dctbl->ehufco[v7], size: dctbl->ehufsi[v7]) != 0
    && (v7 == 0 || emit_bits(state: v8, code: v5, size: v7) != 0) )
  {
    v10 = (int *)&unk_42184C;
    v11 = 0;
    v16 = (int *)&unk_42184C;
    do
    {
      v12 = block[*v10];
      if ( block[*v10] != 0 )
      {
        if ( v11 > 15 )
        {
          while ( emit_bits(state, code: actbl->ehufco[240], size: actbl->ehufsi[240]) != 0 )
          {
            v11 -= 16;
            if ( v11 <= 15 )
              goto LABEL_18;
          }
          return 0;
        }
LABEL_18:
        temp2 = v12;
        if ( v12 < 0 )
        {
          v12 = -v12;
          --temp2;
        }
        v13 = v12 >> 1;
        v14 = 1;
        nbits = 1;
        if ( v13 == 0 )
          goto LABEL_24;
        do
        {
          ++v14;
          v13 >>= 1;
        }
        while ( v13 != 0 );
        nbits = v14;
        if ( v14 > 10 )
        {
          v15 = state;
          state->cinfo->err->msg_code = 6;
          state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
        }
        else
        {
LABEL_24:
          v15 = state;
        }
        if ( emit_bits(state: v15, code: actbl->ehufco[16 * v11 + v14], size: actbl->ehufsi[16 * v11 + v14]) == 0
          || emit_bits(state: v15, code: temp2, size: nbits) == 0 )
        {
          return 0;
        }
        v10 = v16;
        v11 = 0;
      }
      else
      {
        ++v11;
      }
      v16 = ++v10;
    }
    while ( (int)v10 < (int)dword_421948 );
    if ( v11 <= 0 || emit_bits(state, code: actbl->ehufco[0], size: actbl->ehufsi[0]) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408780
// Name: emit_restart
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall emit_restart@<al>(working_state *state@<eax>, char restart_num)
{
  bool v3; // zf
  jpeg_destination_mgr *dest; // edi
  jpeg_destination_mgr *v5; // edi
  int v6; // eax
  int *last_dc_val; // ecx

  if ( emit_bits(state, code: 0x7Fu, size: 7) == 0 )
    return 0;
  state->cur.put_buffer = 0;
  state->cur.put_bits = 0;
  *state->next_output_byte++ = -1;
  v3 = state->free_in_buffer-- == 1;
  if ( v3 )
  {
    dest = state->cinfo->dest;
    if ( dest->empty_output_buffer(a1: state->cinfo) == 0 )
      return 0;
    state->next_output_byte = dest->next_output_byte;
    state->free_in_buffer = dest->free_in_buffer;
  }
  *state->next_output_byte++ = restart_num - 48;
  v3 = state->free_in_buffer-- == 1;
  if ( v3 )
  {
    v5 = state->cinfo->dest;
    if ( v5->empty_output_buffer(a1: state->cinfo) != 0 )
    {
      state->next_output_byte = v5->next_output_byte;
      state->free_in_buffer = v5->free_in_buffer;
      goto LABEL_8;
    }
    return 0;
  }
LABEL_8:
  v6 = 0;
  if ( state->cinfo->comps_in_scan > 0 )
  {
    last_dc_val = state->cur.last_dc_val;
    do
    {
      *last_dc_val = 0;
      ++v6;
      ++last_dc_val;
    }
    while ( v6 < state->cinfo->comps_in_scan );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408840
// Name: encode_mcu_huff
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_huff(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  bool v3; // zf
  jpeg_entropy_encoder *entropy; // esi
  jpeg_destination_mgr *dest; // eax
  unsigned __int8 *next_output_byte; // ecx
  unsigned int free_in_buffer; // edx
  unsigned __int8 result; // al
  int v9; // ebx
  jpeg_component_info *v10; // ecx
  __int16 *v11; // edx
  int v12; // eax
  __int64 v13; // xmm0_8
  unsigned int restart_interval; // edi
  int v15; // eax
  c_derived_tbl *v16; // [esp-Ch] [ebp-3Ch]
  c_derived_tbl *v17; // [esp-8h] [ebp-38h]
  working_state state; // [esp+8h] [ebp-28h] BYREF
  int *v19; // [esp+2Ch] [ebp-4h]
  int *cinfoa; // [esp+38h] [ebp+8h]

  v3 = cinfo->restart_interval == 0;
  entropy = cinfo->entropy;
  dest = cinfo->dest;
  next_output_byte = dest->next_output_byte;
  free_in_buffer = dest->free_in_buffer;
  *(_QWORD *)&state.cur.put_buffer = *(_QWORD *)&entropy[1].start_pass;
  *(_QWORD *)state.cur.last_dc_val = *(_QWORD *)&entropy[1].finish_pass;
  state.next_output_byte = next_output_byte;
  state.free_in_buffer = free_in_buffer;
  *(_QWORD *)&state.cur.last_dc_val[2] = *(_QWORD *)&entropy[2].encode_mcu;
  state.cinfo = cinfo;
  if ( v3
    || entropy[3].start_pass != nullptr
    || (result = emit_restart(&state, restart_num: (char)entropy[3].encode_mcu)) != 0 )
  {
    v9 = 0;
    if ( cinfo->blocks_in_MCU <= 0 )
    {
LABEL_8:
      v13 = *(_QWORD *)&state.cur.put_buffer;
      cinfo->dest->next_output_byte = state.next_output_byte;
      cinfo->dest->free_in_buffer = state.free_in_buffer;
      *(_QWORD *)&entropy[1].start_pass = v13;
      *(_OWORD *)&entropy[1].finish_pass = *(_OWORD *)state.cur.last_dc_val;
      restart_interval = cinfo->restart_interval;
      if ( restart_interval != 0 )
      {
        if ( entropy[3].start_pass == nullptr )
        {
          v15 = ((unsigned __int8)entropy[3].encode_mcu + 1) & 7;
          entropy[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))restart_interval;
          entropy[3].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))v15;
        }
        --entropy[3].start_pass;
      }
      return 1;
    }
    else
    {
      cinfoa = cinfo->MCU_membership;
      while ( 1 )
      {
        v10 = cinfo->cur_comp_info[*cinfoa];
        v17 = *((c_derived_tbl **)&entropy[5].start_pass + v10->ac_tbl_no);
        v16 = *((c_derived_tbl **)&entropy[3].finish_pass + v10->dc_tbl_no);
        v11 = (__int16 *)MCU_data[v9];
        v19 = &state.cur.last_dc_val[*cinfoa];
        if ( encode_one_block(&state, block: v11, last_dc_val: *v19, dctbl: v16, actbl: v17) == 0 )
          return 0;
        v12 = (*MCU_data[v9])[0];
        ++cinfoa;
        ++v9;
        *v19 = v12;
        if ( v9 >= cinfo->blocks_in_MCU )
          goto LABEL_8;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408980
// Name: finish_pass_huff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_huff(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // eax
  unsigned __int8 *next_output_byte; // ecx
  unsigned int free_in_buffer; // edx
  jpeg_entropy_encoder *entropy; // edi
  __int64 v5; // xmm0_8
  __int64 v6; // xmm0_8
  working_state state; // [esp+Ch] [ebp-24h] BYREF

  dest = cinfo->dest;
  next_output_byte = dest->next_output_byte;
  free_in_buffer = dest->free_in_buffer;
  entropy = cinfo->entropy;
  *(_QWORD *)&state.cur.put_buffer = *(_QWORD *)&entropy[1].start_pass;
  *(_QWORD *)state.cur.last_dc_val = *(_QWORD *)&entropy[1].finish_pass;
  v5 = *(_QWORD *)&entropy[2].encode_mcu;
  state.next_output_byte = next_output_byte;
  state.free_in_buffer = free_in_buffer;
  *(_QWORD *)&state.cur.last_dc_val[2] = v5;
  state.cinfo = cinfo;
  if ( emit_bits(&state, code: 0x7Fu, size: 7) != 0 )
  {
    state.cur.put_buffer = 0;
    state.cur.put_bits = 0;
  }
  else
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
  }
  v6 = *(_QWORD *)&state.cur.put_buffer;
  cinfo->dest->next_output_byte = state.next_output_byte;
  cinfo->dest->free_in_buffer = state.free_in_buffer;
  *(_QWORD *)&entropy[1].start_pass = v6;
  *(_OWORD *)&entropy[1].finish_pass = *(_OWORD *)state.cur.last_dc_val;
}

//------------------------------------------------------------------------------
// Address: 0x00408A30
// Name: encode_mcu_gather
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_gather(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_compress_struct *v2; // edx
  jpeg_entropy_encoder *p_pub; // esi
  int v4; // eax
  void (__cdecl **p_finish_pass)(jpeg_compress_struct *); // ecx
  jpeg_component_info *v6; // eax
  int v7; // edi
  _DWORD *v8; // ebx
  int v9; // eax
  int v10; // esi
  int *v11; // eax
  int v12; // esi
  int v13; // ecx
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // edi
  __int16 *v18; // [esp+4h] [ebp-18h]
  int ci; // [esp+8h] [ebp-14h]
  huff_entropy_encoder *entropy; // [esp+Ch] [ebp-10h]
  int *v21; // [esp+10h] [ebp-Ch]
  int *MCU_membership; // [esp+14h] [ebp-8h]
  int blkn; // [esp+18h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->entropy;
  entropy = (huff_entropy_encoder *)p_pub;
  if ( cinfo->restart_interval != 0 )
  {
    if ( p_pub[3].start_pass == nullptr )
    {
      v4 = 0;
      if ( cinfo->comps_in_scan > 0 )
      {
        p_finish_pass = &p_pub[1].finish_pass;
        do
        {
          *p_finish_pass = nullptr;
          ++v4;
          ++p_finish_pass;
        }
        while ( v4 < cinfo->comps_in_scan );
      }
      p_pub[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))cinfo->restart_interval;
    }
    --p_pub[3].start_pass;
  }
  blkn = 0;
  if ( cinfo->blocks_in_MCU > 0 )
  {
    MCU_membership = cinfo->MCU_membership;
    do
    {
      ci = *MCU_membership;
      v6 = v2->cur_comp_info[*MCU_membership];
      v7 = *((_DWORD *)&p_pub[6].encode_mcu + v6->dc_tbl_no);
      v8 = *((_DWORD **)&p_pub[7].finish_pass + v6->ac_tbl_no);
      v18 = (__int16 *)MCU_data[blkn];
      v9 = *v18 - *((_DWORD *)&p_pub[1].finish_pass + *MCU_membership);
      if ( v9 < 0 )
        v9 = *((_DWORD *)&p_pub[1].finish_pass + *MCU_membership) - *v18;
      v10 = 0;
      if ( v9 != 0 )
      {
        do
        {
          ++v10;
          v9 >>= 1;
        }
        while ( v9 != 0 );
        if ( v10 > 11 )
        {
          v2->err->msg_code = 6;
          v2->err->error_exit(a1: (jpeg_common_struct *)v2);
          v2 = cinfo;
        }
      }
      ++*(_DWORD *)(v7 + 4 * v10);
      v11 = (int *)&unk_42184C;
      v12 = 0;
      v21 = (int *)&unk_42184C;
      do
      {
        v13 = v18[*v11];
        if ( v18[*v11] != 0 )
        {
          if ( v12 > 15 )
          {
            v14 = ((unsigned int)(v12 - 16) >> 4) + 1;
            v12 += -16 * v14;
            v8[240] += v14;
            v2 = cinfo;
          }
          if ( v13 < 0 )
            v13 = -v13;
          v15 = v13 >> 1;
          v16 = 1;
          if ( v15 != 0 )
          {
            do
            {
              ++v16;
              v15 >>= 1;
            }
            while ( v15 != 0 );
            if ( v16 > 10 )
            {
              v2->err->msg_code = 6;
              v2->err->error_exit(a1: (jpeg_common_struct *)v2);
              v2 = cinfo;
            }
          }
          ++v8[16 * v12 + v16];
          v11 = v21;
          v12 = 0;
        }
        else
        {
          ++v12;
        }
        v21 = ++v11;
      }
      while ( (int)v11 < (int)dword_421948 );
      if ( v12 > 0 )
        ++*v8;
      p_pub = &entropy->pub;
      ++MCU_membership;
      entropy->saved.last_dc_val[ci] = (*MCU_data[blkn++])[0];
    }
    while ( blkn < v2->blocks_in_MCU );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408BD0
// Name: _jpeg_gen_optimal_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_gen_optimal_table(jpeg_common_struct *cinfo, JHUFF_TBL *htbl, int *freq)
{
  int v3; // eax
  int v4; // esi
  int i; // ecx
  int v6; // edx
  int v7; // edx
  int v8; // edi
  int j; // ecx
  int v10; // esi
  bool v11; // sf
  int *v12; // ecx
  int *v13; // eax
  int v14; // eax
  int k; // edi
  int v16; // esi
  int v17; // esi
  int v18; // ecx
  int v19; // edx
  int m; // eax
  unsigned __int8 v21; // dl
  int v22; // edx
  int n; // esi
  int ii; // eax
  int others[257]; // [esp+Ch] [ebp-82Ch] BYREF
  int codesize[257]; // [esp+410h] [ebp-428h] BYREF
  unsigned __int8 bits[33]; // [esp+814h] [ebp-24h] BYREF

  memset(bits, 0, sizeof(bits));
  memset(dst: (unsigned __int8 *)codesize, value: 0, count: sizeof(codesize));
  memset(others, 0xFFu, sizeof(others));
  freq[256] = 1;
  while ( 1 )
  {
    v3 = -1;
    v4 = 1000000000;
    for ( i = 0; i <= 256; ++i )
    {
      v6 = freq[i];
      if ( v6 != 0 && v6 <= v4 )
      {
        v4 = freq[i];
        v3 = i;
      }
    }
    v7 = -1;
    v8 = 1000000000;
    for ( j = 0; j <= 256; ++j )
    {
      v10 = freq[j];
      if ( v10 != 0 && v10 <= v8 && j != v3 )
      {
        v8 = freq[j];
        v7 = j;
      }
    }
    if ( v7 < 0 )
      break;
    freq[v3] += freq[v7];
    ++codesize[v3];
    v11 = others[v3] < 0;
    v12 = &others[v3];
    freq[v7] = 0;
    if ( !v11 )
    {
      do
      {
        v3 = *v12;
        ++codesize[v3];
        v12 = &others[v3];
      }
      while ( *v12 >= 0 );
    }
    ++codesize[v7];
    others[v3] = v7;
    v13 = &others[v7];
    if ( *v13 >= 0 )
    {
      do
      {
        v14 = *v13;
        ++codesize[v14];
        v11 = others[v14] < 0;
        v13 = &others[v14];
      }
      while ( !v11 );
    }
  }
  for ( k = 0; k <= 256; ++k )
  {
    v16 = codesize[k];
    if ( v16 != 0 )
    {
      if ( v16 > 32 )
      {
        cinfo->err->msg_code = 39;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++bits[v16];
    }
  }
  v17 = 16;
  v18 = 30;
  v19 = 16;
  do
  {
    for ( ; bits[v18 + 2] != 0; --bits[m] )
    {
      for ( m = v18; bits[m] == 0; --m )
        ;
      bits[v18 + 2] -= 2;
      ++bits[v18 + 1];
      bits[m + 1] += 2;
    }
    --v18;
    --v17;
  }
  while ( v17 != 0 );
  if ( bits[16] == 0 )
  {
    do
      --v19;
    while ( bits[v19] == 0 );
  }
  --bits[v19];
  v21 = bits[16];
  *(_QWORD *)htbl->bits = *(_QWORD *)bits;
  *(_QWORD *)&htbl->bits[8] = *(_QWORD *)&bits[8];
  htbl->bits[16] = v21;
  v22 = 0;
  for ( n = 1; n <= 32; ++n )
  {
    for ( ii = 0; ii <= 255; ++ii )
    {
      if ( codesize[ii] == n )
        htbl->huffval[v22++] = ii;
    }
  }
  htbl->sent_table = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408E00
// Name: finish_pass_gather
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_gather(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // edi
  int dc_tbl_no; // esi
  bool v3; // zf
  int ac_tbl_no; // ebx
  int *v5; // ebx
  int v6; // eax
  int v7; // esi
  int i; // ecx
  int v9; // edx
  int v10; // edx
  int j; // ecx
  int v12; // esi
  bool v13; // sf
  int *v14; // ecx
  int *v15; // eax
  int v16; // eax
  int k; // ebx
  int v18; // esi
  int m; // ecx
  int n; // eax
  _QWORD *v21; // ecx
  char v22; // al
  int v23; // edx
  int ii; // esi
  int jj; // eax
  _DWORD v26[257]; // [esp+4h] [ebp-850h] BYREF
  _DWORD dst[257]; // [esp+408h] [ebp-44Ch] BYREF
  unsigned __int8 *v28; // [esp+80Ch] [ebp-48h]
  int actbl; // [esp+810h] [ebp-44h]
  unsigned __int8 did_dc[4]; // [esp+814h] [ebp-40h] BYREF
  unsigned __int8 did_ac[4]; // [esp+818h] [ebp-3Ch]
  _QWORD *v32; // [esp+81Ch] [ebp-38h]
  __int64 v33; // [esp+820h] [ebp-34h]
  __int64 v34; // [esp+828h] [ebp-2Ch]
  __int64 v35; // [esp+830h] [ebp-24h]
  __int64 v36; // [esp+838h] [ebp-1Ch]
  char v37; // [esp+840h] [ebp-14h]
  int v38; // [esp+844h] [ebp-10h]
  int ci; // [esp+848h] [ebp-Ch]
  huff_entropy_encoder *entropy; // [esp+84Ch] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+850h] [ebp-4h]

  v1 = cinfo;
  entropy = (huff_entropy_encoder *)cinfo[14].client_data;
  *(_DWORD *)did_dc = 0;
  *(_DWORD *)did_ac = 0;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      dc_tbl_no = (*p_is_decompressor)->dc_tbl_no;
      v3 = did_dc[dc_tbl_no] == 0;
      ac_tbl_no = (*p_is_decompressor)->ac_tbl_no;
      actbl = ac_tbl_no;
      v28 = &did_dc[dc_tbl_no];
      if ( v3 )
      {
        if ( *((_DWORD *)&v1[3].is_decompressor + dc_tbl_no) == 0 )
          *((_DWORD *)&v1[3].is_decompressor + dc_tbl_no) = jpeg_alloc_huff_table(cinfo: v1);
        v5 = entropy->dc_count_ptrs[dc_tbl_no];
        v32 = *((_QWORD **)&v1[3].is_decompressor + dc_tbl_no);
        v33 = 0;
        v34 = 0;
        v35 = 0;
        v36 = 0;
        v37 = 0;
        memset((unsigned __int8 *)dst, value: 0, count: sizeof(dst));
        memset(v26, 0xFFu, sizeof(v26));
        v5[256] = 1;
        while ( 1 )
        {
          v6 = -1;
          v7 = 1000000000;
          for ( i = 0; i <= 256; ++i )
          {
            v9 = v5[i];
            if ( v9 != 0 && v9 <= v7 )
            {
              v7 = v5[i];
              v6 = i;
            }
          }
          v10 = -1;
          v38 = 1000000000;
          for ( j = 0; j <= 256; ++j )
          {
            v12 = v5[j];
            if ( v12 != 0 && v12 <= v38 && j != v6 )
            {
              v38 = v5[j];
              v10 = j;
            }
          }
          if ( v10 < 0 )
            break;
          v5[v6] += v5[v10];
          ++dst[v6];
          v13 = (int)v26[v6] < 0;
          v14 = &v26[v6];
          v5[v10] = 0;
          if ( !v13 )
          {
            do
            {
              v6 = *v14;
              ++dst[v6];
              v14 = &v26[v6];
            }
            while ( *v14 >= 0 );
          }
          ++dst[v10];
          v26[v6] = v10;
          v15 = &v26[v10];
          if ( *v15 >= 0 )
          {
            do
            {
              v16 = *v15;
              ++dst[v16];
              v13 = (int)v26[v16] < 0;
              v15 = &v26[v16];
            }
            while ( !v13 );
          }
        }
        for ( k = 0; k <= 256; ++k )
        {
          v18 = dst[k];
          if ( v18 != 0 )
          {
            if ( v18 > 32 )
            {
              cinfo->err->msg_code = 39;
              cinfo->err->error_exit(a1: cinfo);
            }
            ++*((_BYTE *)&v33 + v18);
          }
        }
        for ( m = 32; m > 16; --m )
        {
          for ( ; *((_BYTE *)&v33 + m) != 0; --*((_BYTE *)&v33 + n) )
          {
            for ( n = m - 2; *((_BYTE *)&v33 + n) == 0; --n )
              ;
            *((_BYTE *)&v33 + m) -= 2;
            ++*((_BYTE *)&v32 + m + 3);
            *((_BYTE *)&v33 + n + 1) += 2;
          }
        }
        for ( ; *((_BYTE *)&v33 + m) == 0; --m )
          ;
        --*((_BYTE *)&v33 + m);
        v21 = v32;
        v22 = v35;
        *v32 = v33;
        v21[1] = v34;
        *((_BYTE *)v21 + 16) = v22;
        v23 = 0;
        for ( ii = 1; ii <= 32; ++ii )
        {
          for ( jj = 0; jj <= 255; ++jj )
          {
            if ( dst[jj] == ii )
            {
              *((_BYTE *)v21 + v23 + 17) = jj;
              ++v23;
            }
          }
        }
        ac_tbl_no = actbl;
        v1 = cinfo;
        *((_BYTE *)v21 + 273) = 0;
        *v28 = 1;
      }
      if ( did_ac[ac_tbl_no] == 0 )
      {
        if ( *((_DWORD *)&v1[4].progress + ac_tbl_no) == 0 )
          *((_DWORD *)&v1[4].progress + ac_tbl_no) = jpeg_alloc_huff_table(cinfo: v1);
        jpeg_gen_optimal_table(
          cinfo: v1,
          htbl: *((JHUFF_TBL **)&v1[4].progress + ac_tbl_no),
          freq: entropy->ac_count_ptrs[ac_tbl_no]);
        did_ac[ac_tbl_no] = 1;
      }
      ++p_is_decompressor;
      ++ci;
    }
    while ( ci < (int)v1[9].client_data );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409100
// Name: start_pass_huff
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_huff(jpeg_common_struct *cinfo, unsigned __int8 gather_statistics)
{
  jpeg_entropy_encoder *client_data; // edi
  unsigned int dc_tbl_no; // ebx
  unsigned int ac_tbl_no; // eax
  void (__cdecl **p_finish_pass)(jpeg_compress_struct *); // [esp+8h] [ebp-Ch]
  int ci; // [esp+Ch] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+10h] [ebp-4h]
  unsigned int actbl; // [esp+1Ch] [ebp+8h]

  client_data = (jpeg_entropy_encoder *)cinfo[14].client_data;
  if ( gather_statistics != 0 )
  {
    client_data->encode_mcu = encode_mcu_gather;
    client_data->finish_pass = (void (__cdecl *)(jpeg_compress_struct *))finish_pass_gather;
  }
  else
  {
    client_data->encode_mcu = encode_mcu_huff;
    client_data->finish_pass = finish_pass_huff;
  }
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_finish_pass = &client_data[1].finish_pass;
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      dc_tbl_no = (*p_is_decompressor)->dc_tbl_no;
      ac_tbl_no = (*p_is_decompressor)->ac_tbl_no;
      actbl = ac_tbl_no;
      if ( gather_statistics != 0 )
      {
        if ( dc_tbl_no >= 4 )
        {
          cinfo->err->msg_code = 50;
          cinfo->err->msg_parm.i[0] = dc_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
          ac_tbl_no = actbl;
        }
        if ( ac_tbl_no >= 4 )
        {
          cinfo->err->msg_code = 50;
          cinfo->err->msg_parm.i[0] = ac_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( *((_DWORD *)&client_data[6].encode_mcu + dc_tbl_no) == 0 )
          *((_DWORD *)&client_data[6].encode_mcu + dc_tbl_no) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
        memset(dst: *((unsigned __int8 **)&client_data[6].encode_mcu + dc_tbl_no), value: 0, count: 0x404u);
        if ( *((_DWORD *)&client_data[7].finish_pass + actbl) == 0 )
          *((_DWORD *)&client_data[7].finish_pass + actbl) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
        memset(dst: *((unsigned __int8 **)&client_data[7].finish_pass + actbl), value: 0, count: 0x404u);
      }
      else
      {
        jpeg_make_c_derived_tbl(
          cinfo,
          isDC: 1u,
          tblno: dc_tbl_no,
          pdtbl: (c_derived_tbl **)&client_data[3].finish_pass + dc_tbl_no);
        jpeg_make_c_derived_tbl(
          cinfo,
          isDC: 0,
          tblno: actbl,
          pdtbl: (c_derived_tbl **)&client_data[5].start_pass + actbl);
      }
      ++p_is_decompressor;
      *p_finish_pass = nullptr;
      ++ci;
      ++p_finish_pass;
    }
    while ( ci < (int)cinfo[9].client_data );
  }
  client_data[1].start_pass = nullptr;
  client_data[1].encode_mcu = nullptr;
  client_data[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))cinfo[7].global_state;
  client_data[3].encode_mcu = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00409290
// Name: _jinit_huff_encoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_huff_encoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_encoder *v1; // eax

  v1 = (jpeg_entropy_encoder *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 108);
  cinfo[14].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))start_pass_huff;
  v1[5].start_pass = nullptr;
  v1[3].finish_pass = nullptr;
  v1[7].finish_pass = nullptr;
  v1[6].encode_mcu = nullptr;
  v1[5].encode_mcu = nullptr;
  v1[4].start_pass = nullptr;
  v1[8].start_pass = nullptr;
  v1[6].finish_pass = nullptr;
  v1[5].finish_pass = nullptr;
  v1[4].encode_mcu = nullptr;
  v1[8].encode_mcu = nullptr;
  v1[7].start_pass = nullptr;
  v1[6].start_pass = nullptr;
  v1[4].finish_pass = nullptr;
  v1[8].finish_pass = nullptr;
  v1[7].encode_mcu = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004092F0
// Name: emit_bits_0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_bits_0(phuff_entropy_encoder *entropy@<esi>, unsigned int code, int size)
{
  int v3; // ebx
  int v4; // ebx
  unsigned int v5; // edi
  bool v6; // zf
  jpeg_destination_mgr *dest; // ebx
  int put_bits; // [esp+8h] [ebp-4h]
  jpeg_destination_mgr *codea; // [esp+14h] [ebp+8h]
  int sizea; // [esp+18h] [ebp+Ch]

  v3 = entropy->put_bits;
  if ( size == 0 )
  {
    entropy->cinfo->err->msg_code = 40;
    entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
  }
  if ( entropy->gather_statistics == 0 )
  {
    v4 = size + v3;
    v5 = entropy->put_buffer | ((code & ((1 << size) - 1)) << (24 - v4));
    if ( v4 >= 8 )
    {
      sizea = (unsigned int)v4 >> 3;
      put_bits = v4 - 8 * ((unsigned int)v4 >> 3);
      do
      {
        *entropy->next_output_byte++ = BYTE2(v5);
        v6 = entropy->free_in_buffer-- == 1;
        if ( v6 )
        {
          codea = entropy->cinfo->dest;
          if ( codea->empty_output_buffer(a1: entropy->cinfo) == 0 )
          {
            entropy->cinfo->err->msg_code = 24;
            entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
          }
          entropy->next_output_byte = codea->next_output_byte;
          entropy->free_in_buffer = codea->free_in_buffer;
        }
        if ( BYTE2(v5) == 255 )
        {
          *entropy->next_output_byte++ = 0;
          v6 = entropy->free_in_buffer-- == 1;
          if ( v6 )
          {
            dest = entropy->cinfo->dest;
            if ( dest->empty_output_buffer(a1: entropy->cinfo) == 0 )
            {
              entropy->cinfo->err->msg_code = 24;
              entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
            }
            entropy->next_output_byte = dest->next_output_byte;
            entropy->free_in_buffer = dest->free_in_buffer;
          }
        }
        v5 <<= 8;
        --sizea;
      }
      while ( sizea != 0 );
      v4 = put_bits;
    }
    entropy->put_buffer = v5;
    entropy->put_bits = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409610
// Name: emit_restart_0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_restart_0(phuff_entropy_encoder *entropy@<eax>, char restart_num)
{
  bool v3; // zf
  jpeg_destination_mgr *dest; // edi
  jpeg_destination_mgr *v5; // edi
  jpeg_compress_struct *cinfo; // ecx
  int v7; // eax
  int *last_dc_val; // ecx

  emit_eobrun(entropy);
  if ( entropy->gather_statistics == 0 )
  {
    emit_bits_0(entropy, code: 0x7Fu, size: 7);
    entropy->put_buffer = 0;
    entropy->put_bits = 0;
    *entropy->next_output_byte++ = -1;
    v3 = entropy->free_in_buffer-- == 1;
    if ( v3 )
    {
      dest = entropy->cinfo->dest;
      if ( dest->empty_output_buffer(a1: entropy->cinfo) == 0 )
      {
        entropy->cinfo->err->msg_code = 24;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
      entropy->next_output_byte = dest->next_output_byte;
      entropy->free_in_buffer = dest->free_in_buffer;
    }
    *entropy->next_output_byte++ = restart_num - 48;
    v3 = entropy->free_in_buffer-- == 1;
    if ( v3 )
    {
      v5 = entropy->cinfo->dest;
      if ( v5->empty_output_buffer(a1: entropy->cinfo) == 0 )
      {
        entropy->cinfo->err->msg_code = 24;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
      entropy->next_output_byte = v5->next_output_byte;
      entropy->free_in_buffer = v5->free_in_buffer;
    }
  }
  cinfo = entropy->cinfo;
  if ( cinfo->Ss != 0 )
  {
    entropy->EOBRUN = 0;
    entropy->BE = 0;
  }
  else
  {
    v7 = 0;
    if ( cinfo->comps_in_scan > 0 )
    {
      last_dc_val = entropy->last_dc_val;
      do
      {
        *last_dc_val = 0;
        ++v7;
        ++last_dc_val;
      }
      while ( v7 < entropy->cinfo->comps_in_scan );
    }
  }
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x004315F0
// Name: _jpeg_make_c_derived_tbl
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_make_c_derived_tbl(
        jpeg_common_struct *cinfo,
        unsigned __int8 isDC,
        unsigned int tblno,
        c_derived_tbl **pdtbl)
{
  int v5; // edi
  int i; // ebx
  unsigned int v7; // esi
  int v8; // ebx
  signed int v9; // edi
  int v10; // esi
  c_derived_tbl **v11; // edx
  char *v12; // eax
  int v13; // eax
  int j; // esi
  int v15; // edi
  unsigned int v16; // ecx
  char v17; // dl
  c_derived_tbl *v18; // eax
  unsigned int huffcode[257]; // [esp+Ch] [ebp-510h]
  char huffsize[260]; // [esp+410h] [ebp-10Ch] BYREF
  int lastp; // [esp+514h] [ebp-8h]
  c_derived_tbl *dtbl; // [esp+518h] [ebp-4h]
  JHUFF_TBL *htbl; // [esp+52Ch] [ebp+10h]
  c_derived_tbl **pdtbla; // [esp+530h] [ebp+14h]

  if ( tblno >= 4 )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( isDC != 0 )
    htbl = *((JHUFF_TBL **)&cinfo[3].is_decompressor + tblno);
  else
    htbl = *((JHUFF_TBL **)&cinfo[4].progress + tblno);
  if ( htbl == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *pdtbl == nullptr )
    *pdtbl = (c_derived_tbl *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1280);
  dtbl = *pdtbl;
  v5 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    v7 = htbl->bits[i];
    if ( (int)(v7 + v5) > 256 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v7 != 0 )
    {
      memset(dst: (unsigned __int8 *)&huffsize[v5], value: i, count: v7);
      v5 += v7;
    }
  }
  huffsize[v5] = 0;
  v8 = huffsize[0];
  lastp = v5;
  v9 = 0;
  v10 = 0;
  v11 = (c_derived_tbl **)__ROL4__(1, huffsize[0]);
  pdtbla = v11;
  if ( huffsize[0] != 0 )
  {
    v12 = huffsize;
    while ( 1 )
    {
      if ( *v12 == v8 )
      {
        do
        {
          v13 = huffsize[v10 + 1];
          huffcode[v10++] = v9++;
        }
        while ( v13 == v8 );
      }
      if ( v9 >= (int)v11 )
      {
        cinfo->err->msg_code = 8;
        cinfo->err->error_exit(a1: cinfo);
        v11 = pdtbla;
      }
      v9 *= 2;
      ++v8;
      v12 = &huffsize[v10];
      pdtbla = (c_derived_tbl **)__ROL4__(v11, 1);
      if ( huffsize[v10] == 0 )
        break;
      v11 = pdtbla;
    }
  }
  memset(dst: (unsigned __int8 *)dtbl->ehufsi, value: 0, count: sizeof(dtbl->ehufsi));
  for ( j = 0; j < lastp; v18->ehufsi[v15] = v17 )
  {
    v15 = htbl->huffval[j];
    if ( v15 > (isDC != 0 ? 15 : 255) || dtbl->ehufsi[v15] != 0 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    v16 = huffcode[j];
    v17 = huffsize[j];
    v18 = dtbl;
    ++j;
    dtbl->ehufco[v15] = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004317F0
// Name: emit_bits
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall emit_bits@<al>(working_state *state@<esi>, unsigned int code, int size)
{
  int v3; // ebx
  int v4; // ebx
  unsigned int v5; // edi
  bool v6; // zf
  jpeg_destination_mgr *dest; // ebx
  int v8; // eax
  int put_bits; // [esp+8h] [ebp-4h]
  jpeg_destination_mgr *sizea; // [esp+18h] [ebp+Ch]

  v3 = state->cur.put_bits;
  if ( size == 0 )
  {
    state->cinfo->err->msg_code = 40;
    state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
  }
  v4 = size + v3;
  put_bits = v4;
  v5 = state->cur.put_buffer | ((code & ((1 << size) - 1)) << (24 - v4));
  if ( v4 < 8 )
  {
LABEL_13:
    state->cur.put_buffer = v5;
    state->cur.put_bits = v4;
    return 1;
  }
  while ( 1 )
  {
    *state->next_output_byte++ = BYTE2(v5);
    v6 = state->free_in_buffer-- == 1;
    if ( v6 )
    {
      sizea = state->cinfo->dest;
      if ( sizea->empty_output_buffer(a1: state->cinfo) == 0 )
        return 0;
      state->next_output_byte = sizea->next_output_byte;
      state->free_in_buffer = sizea->free_in_buffer;
    }
    if ( BYTE2(v5) == 255 )
    {
      *state->next_output_byte++ = 0;
      v6 = state->free_in_buffer-- == 1;
      if ( v6 )
        break;
    }
LABEL_11:
    v8 = put_bits - 8;
    v5 <<= 8;
    put_bits = v8;
    if ( v8 < 8 )
    {
      v4 = v8;
      goto LABEL_13;
    }
  }
  dest = state->cinfo->dest;
  if ( dest->empty_output_buffer(a1: state->cinfo) != 0 )
  {
    state->next_output_byte = dest->next_output_byte;
    state->free_in_buffer = dest->free_in_buffer;
    goto LABEL_11;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004318E0
// Name: encode_one_block
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_one_block(
        working_state *state,
        __int16 *block,
        int last_dc_val,
        c_derived_tbl *dctbl,
        c_derived_tbl *actbl)
{
  signed int v5; // edi
  int v6; // eax
  int v7; // ebx
  working_state *v8; // esi
  int *v10; // eax
  int v11; // edi
  int v12; // ebx
  int v13; // ebx
  int v14; // esi
  working_state *v15; // ebx
  int *v16; // [esp+Ch] [ebp-4h]
  unsigned int temp2; // [esp+20h] [ebp+10h]
  int nbits; // [esp+24h] [ebp+14h]

  v5 = *block - last_dc_val;
  v6 = v5;
  if ( v5 < 0 )
  {
    v6 = last_dc_val - *block;
    --v5;
  }
  v7 = 0;
  if ( v6 == 0 )
    goto LABEL_7;
  do
  {
    ++v7;
    v6 >>= 1;
  }
  while ( v6 != 0 );
  if ( v7 > 11 )
  {
    v8 = state;
    state->cinfo->err->msg_code = 6;
    state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
  }
  else
  {
LABEL_7:
    v8 = state;
  }
  if ( emit_bits(state: v8, code: dctbl->ehufco[v7], size: dctbl->ehufsi[v7]) != 0
    && (v7 == 0 || emit_bits(state: v8, code: v5, size: v7) != 0) )
  {
    v10 = (int *)&unk_458B64;
    v11 = 0;
    v16 = (int *)&unk_458B64;
    do
    {
      v12 = block[*v10];
      if ( block[*v10] != 0 )
      {
        if ( v11 > 15 )
        {
          while ( emit_bits(state, code: actbl->ehufco[240], size: actbl->ehufsi[240]) != 0 )
          {
            v11 -= 16;
            if ( v11 <= 15 )
              goto LABEL_18;
          }
          return 0;
        }
LABEL_18:
        temp2 = v12;
        if ( v12 < 0 )
        {
          v12 = -v12;
          --temp2;
        }
        v13 = v12 >> 1;
        v14 = 1;
        nbits = 1;
        if ( v13 == 0 )
          goto LABEL_24;
        do
        {
          ++v14;
          v13 >>= 1;
        }
        while ( v13 != 0 );
        nbits = v14;
        if ( v14 > 10 )
        {
          v15 = state;
          state->cinfo->err->msg_code = 6;
          state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
        }
        else
        {
LABEL_24:
          v15 = state;
        }
        if ( emit_bits(state: v15, code: actbl->ehufco[16 * v11 + v14], size: actbl->ehufsi[16 * v11 + v14]) == 0
          || emit_bits(state: v15, code: temp2, size: nbits) == 0 )
        {
          return 0;
        }
        v10 = v16;
        v11 = 0;
      }
      else
      {
        ++v11;
      }
      v16 = ++v10;
    }
    while ( (int)v10 < (int)dword_458C60 );
    if ( v11 <= 0 || emit_bits(state, code: actbl->ehufco[0], size: actbl->ehufsi[0]) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00431A90
// Name: emit_restart
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall emit_restart@<al>(working_state *state@<eax>, char restart_num)
{
  bool v3; // zf
  jpeg_destination_mgr *dest; // edi
  jpeg_destination_mgr *v5; // edi
  int v6; // eax
  int *last_dc_val; // ecx

  if ( emit_bits(state, code: 0x7Fu, size: 7) == 0 )
    return 0;
  state->cur.put_buffer = 0;
  state->cur.put_bits = 0;
  *state->next_output_byte++ = -1;
  v3 = state->free_in_buffer-- == 1;
  if ( v3 )
  {
    dest = state->cinfo->dest;
    if ( dest->empty_output_buffer(a1: state->cinfo) == 0 )
      return 0;
    state->next_output_byte = dest->next_output_byte;
    state->free_in_buffer = dest->free_in_buffer;
  }
  *state->next_output_byte++ = restart_num - 48;
  v3 = state->free_in_buffer-- == 1;
  if ( v3 )
  {
    v5 = state->cinfo->dest;
    if ( v5->empty_output_buffer(a1: state->cinfo) != 0 )
    {
      state->next_output_byte = v5->next_output_byte;
      state->free_in_buffer = v5->free_in_buffer;
      goto LABEL_8;
    }
    return 0;
  }
LABEL_8:
  v6 = 0;
  if ( state->cinfo->comps_in_scan > 0 )
  {
    last_dc_val = state->cur.last_dc_val;
    do
    {
      *last_dc_val = 0;
      ++v6;
      ++last_dc_val;
    }
    while ( v6 < state->cinfo->comps_in_scan );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00431B50
// Name: encode_mcu_huff
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_huff(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  bool v3; // zf
  jpeg_entropy_encoder *entropy; // esi
  jpeg_destination_mgr *dest; // eax
  unsigned __int8 *next_output_byte; // ecx
  unsigned int free_in_buffer; // edx
  unsigned __int8 result; // al
  int v9; // ebx
  jpeg_component_info *v10; // ecx
  __int16 *v11; // edx
  int v12; // eax
  __int64 v13; // xmm0_8
  unsigned int restart_interval; // edi
  int v15; // eax
  c_derived_tbl *v16; // [esp-Ch] [ebp-3Ch]
  c_derived_tbl *v17; // [esp-8h] [ebp-38h]
  working_state state; // [esp+8h] [ebp-28h] BYREF
  int *v19; // [esp+2Ch] [ebp-4h]
  int *cinfoa; // [esp+38h] [ebp+8h]

  v3 = cinfo->restart_interval == 0;
  entropy = cinfo->entropy;
  dest = cinfo->dest;
  next_output_byte = dest->next_output_byte;
  free_in_buffer = dest->free_in_buffer;
  *(_QWORD *)&state.cur.put_buffer = *(_QWORD *)&entropy[1].start_pass;
  *(_QWORD *)state.cur.last_dc_val = *(_QWORD *)&entropy[1].finish_pass;
  state.next_output_byte = next_output_byte;
  state.free_in_buffer = free_in_buffer;
  *(_QWORD *)&state.cur.last_dc_val[2] = *(_QWORD *)&entropy[2].encode_mcu;
  state.cinfo = cinfo;
  if ( v3
    || entropy[3].start_pass != nullptr
    || (result = emit_restart(&state, restart_num: (char)entropy[3].encode_mcu)) != 0 )
  {
    v9 = 0;
    if ( cinfo->blocks_in_MCU <= 0 )
    {
LABEL_8:
      v13 = *(_QWORD *)&state.cur.put_buffer;
      cinfo->dest->next_output_byte = state.next_output_byte;
      cinfo->dest->free_in_buffer = state.free_in_buffer;
      *(_QWORD *)&entropy[1].start_pass = v13;
      *(_OWORD *)&entropy[1].finish_pass = *(_OWORD *)state.cur.last_dc_val;
      restart_interval = cinfo->restart_interval;
      if ( restart_interval != 0 )
      {
        if ( entropy[3].start_pass == nullptr )
        {
          v15 = ((unsigned __int8)entropy[3].encode_mcu + 1) & 7;
          entropy[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))restart_interval;
          entropy[3].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))v15;
        }
        --entropy[3].start_pass;
      }
      return 1;
    }
    else
    {
      cinfoa = cinfo->MCU_membership;
      while ( 1 )
      {
        v10 = cinfo->cur_comp_info[*cinfoa];
        v17 = *((c_derived_tbl **)&entropy[5].start_pass + v10->ac_tbl_no);
        v16 = *((c_derived_tbl **)&entropy[3].finish_pass + v10->dc_tbl_no);
        v11 = (__int16 *)MCU_data[v9];
        v19 = &state.cur.last_dc_val[*cinfoa];
        if ( encode_one_block(&state, block: v11, last_dc_val: *v19, dctbl: v16, actbl: v17) == 0 )
          return 0;
        v12 = (*MCU_data[v9])[0];
        ++cinfoa;
        ++v9;
        *v19 = v12;
        if ( v9 >= cinfo->blocks_in_MCU )
          goto LABEL_8;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431C90
// Name: finish_pass_huff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_huff(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // eax
  unsigned __int8 *next_output_byte; // ecx
  unsigned int free_in_buffer; // edx
  jpeg_entropy_encoder *entropy; // edi
  __int64 v5; // xmm0_8
  __int64 v6; // xmm0_8
  working_state state; // [esp+Ch] [ebp-24h] BYREF

  dest = cinfo->dest;
  next_output_byte = dest->next_output_byte;
  free_in_buffer = dest->free_in_buffer;
  entropy = cinfo->entropy;
  *(_QWORD *)&state.cur.put_buffer = *(_QWORD *)&entropy[1].start_pass;
  *(_QWORD *)state.cur.last_dc_val = *(_QWORD *)&entropy[1].finish_pass;
  v5 = *(_QWORD *)&entropy[2].encode_mcu;
  state.next_output_byte = next_output_byte;
  state.free_in_buffer = free_in_buffer;
  *(_QWORD *)&state.cur.last_dc_val[2] = v5;
  state.cinfo = cinfo;
  if ( emit_bits(&state, code: 0x7Fu, size: 7) != 0 )
  {
    state.cur.put_buffer = 0;
    state.cur.put_bits = 0;
  }
  else
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
  }
  v6 = *(_QWORD *)&state.cur.put_buffer;
  cinfo->dest->next_output_byte = state.next_output_byte;
  cinfo->dest->free_in_buffer = state.free_in_buffer;
  *(_QWORD *)&entropy[1].start_pass = v6;
  *(_OWORD *)&entropy[1].finish_pass = *(_OWORD *)state.cur.last_dc_val;
}

//------------------------------------------------------------------------------
// Address: 0x00431D40
// Name: encode_mcu_gather
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_gather(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_compress_struct *v2; // edx
  jpeg_entropy_encoder *p_pub; // esi
  int v4; // eax
  void (__cdecl **p_finish_pass)(jpeg_compress_struct *); // ecx
  jpeg_component_info *v6; // eax
  int v7; // edi
  _DWORD *v8; // ebx
  int v9; // eax
  int v10; // esi
  int *v11; // eax
  int v12; // esi
  int v13; // ecx
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // edi
  __int16 *v18; // [esp+4h] [ebp-18h]
  int ci; // [esp+8h] [ebp-14h]
  huff_entropy_encoder *entropy; // [esp+Ch] [ebp-10h]
  int *v21; // [esp+10h] [ebp-Ch]
  int *MCU_membership; // [esp+14h] [ebp-8h]
  int blkn; // [esp+18h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->entropy;
  entropy = (huff_entropy_encoder *)p_pub;
  if ( cinfo->restart_interval != 0 )
  {
    if ( p_pub[3].start_pass == nullptr )
    {
      v4 = 0;
      if ( cinfo->comps_in_scan > 0 )
      {
        p_finish_pass = &p_pub[1].finish_pass;
        do
        {
          *p_finish_pass = nullptr;
          ++v4;
          ++p_finish_pass;
        }
        while ( v4 < cinfo->comps_in_scan );
      }
      p_pub[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))cinfo->restart_interval;
    }
    --p_pub[3].start_pass;
  }
  blkn = 0;
  if ( cinfo->blocks_in_MCU > 0 )
  {
    MCU_membership = cinfo->MCU_membership;
    do
    {
      ci = *MCU_membership;
      v6 = v2->cur_comp_info[*MCU_membership];
      v7 = *((_DWORD *)&p_pub[6].encode_mcu + v6->dc_tbl_no);
      v8 = *((_DWORD **)&p_pub[7].finish_pass + v6->ac_tbl_no);
      v18 = (__int16 *)MCU_data[blkn];
      v9 = *v18 - *((_DWORD *)&p_pub[1].finish_pass + *MCU_membership);
      if ( v9 < 0 )
        v9 = *((_DWORD *)&p_pub[1].finish_pass + *MCU_membership) - *v18;
      v10 = 0;
      if ( v9 != 0 )
      {
        do
        {
          ++v10;
          v9 >>= 1;
        }
        while ( v9 != 0 );
        if ( v10 > 11 )
        {
          v2->err->msg_code = 6;
          v2->err->error_exit(a1: (jpeg_common_struct *)v2);
          v2 = cinfo;
        }
      }
      ++*(_DWORD *)(v7 + 4 * v10);
      v11 = (int *)&unk_458B64;
      v12 = 0;
      v21 = (int *)&unk_458B64;
      do
      {
        v13 = v18[*v11];
        if ( v18[*v11] != 0 )
        {
          if ( v12 > 15 )
          {
            v14 = ((unsigned int)(v12 - 16) >> 4) + 1;
            v12 += -16 * v14;
            v8[240] += v14;
            v2 = cinfo;
          }
          if ( v13 < 0 )
            v13 = -v13;
          v15 = v13 >> 1;
          v16 = 1;
          if ( v15 != 0 )
          {
            do
            {
              ++v16;
              v15 >>= 1;
            }
            while ( v15 != 0 );
            if ( v16 > 10 )
            {
              v2->err->msg_code = 6;
              v2->err->error_exit(a1: (jpeg_common_struct *)v2);
              v2 = cinfo;
            }
          }
          ++v8[16 * v12 + v16];
          v11 = v21;
          v12 = 0;
        }
        else
        {
          ++v12;
        }
        v21 = ++v11;
      }
      while ( (int)v11 < (int)dword_458C60 );
      if ( v12 > 0 )
        ++*v8;
      p_pub = &entropy->pub;
      ++MCU_membership;
      entropy->saved.last_dc_val[ci] = (*MCU_data[blkn++])[0];
    }
    while ( blkn < v2->blocks_in_MCU );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00431EE0
// Name: _jpeg_gen_optimal_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_gen_optimal_table(jpeg_common_struct *cinfo, JHUFF_TBL *htbl, int *freq)
{
  int v3; // eax
  int v4; // esi
  int i; // ecx
  int v6; // edx
  int v7; // edx
  int v8; // edi
  int j; // ecx
  int v10; // esi
  bool v11; // sf
  int *v12; // ecx
  int *v13; // eax
  int v14; // eax
  int k; // edi
  int v16; // esi
  int v17; // esi
  int v18; // ecx
  int v19; // edx
  int m; // eax
  unsigned __int8 v21; // dl
  int v22; // edx
  int n; // esi
  int ii; // eax
  int others[257]; // [esp+Ch] [ebp-82Ch] BYREF
  int codesize[257]; // [esp+410h] [ebp-428h] BYREF
  unsigned __int8 bits[33]; // [esp+814h] [ebp-24h] BYREF

  memset(bits, 0, sizeof(bits));
  memset(dst: (unsigned __int8 *)codesize, value: 0, count: sizeof(codesize));
  memset(others, 0xFFu, sizeof(others));
  freq[256] = 1;
  while ( 1 )
  {
    v3 = -1;
    v4 = 1000000000;
    for ( i = 0; i <= 256; ++i )
    {
      v6 = freq[i];
      if ( v6 != 0 && v6 <= v4 )
      {
        v4 = freq[i];
        v3 = i;
      }
    }
    v7 = -1;
    v8 = 1000000000;
    for ( j = 0; j <= 256; ++j )
    {
      v10 = freq[j];
      if ( v10 != 0 && v10 <= v8 && j != v3 )
      {
        v8 = freq[j];
        v7 = j;
      }
    }
    if ( v7 < 0 )
      break;
    freq[v3] += freq[v7];
    ++codesize[v3];
    v11 = others[v3] < 0;
    v12 = &others[v3];
    freq[v7] = 0;
    if ( !v11 )
    {
      do
      {
        v3 = *v12;
        ++codesize[v3];
        v12 = &others[v3];
      }
      while ( *v12 >= 0 );
    }
    ++codesize[v7];
    others[v3] = v7;
    v13 = &others[v7];
    if ( *v13 >= 0 )
    {
      do
      {
        v14 = *v13;
        ++codesize[v14];
        v11 = others[v14] < 0;
        v13 = &others[v14];
      }
      while ( !v11 );
    }
  }
  for ( k = 0; k <= 256; ++k )
  {
    v16 = codesize[k];
    if ( v16 != 0 )
    {
      if ( v16 > 32 )
      {
        cinfo->err->msg_code = 39;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++bits[v16];
    }
  }
  v17 = 16;
  v18 = 30;
  v19 = 16;
  do
  {
    for ( ; bits[v18 + 2] != 0; --bits[m] )
    {
      for ( m = v18; bits[m] == 0; --m )
        ;
      bits[v18 + 2] -= 2;
      ++bits[v18 + 1];
      bits[m + 1] += 2;
    }
    --v18;
    --v17;
  }
  while ( v17 != 0 );
  if ( bits[16] == 0 )
  {
    do
      --v19;
    while ( bits[v19] == 0 );
  }
  --bits[v19];
  v21 = bits[16];
  *(_QWORD *)htbl->bits = *(_QWORD *)bits;
  *(_QWORD *)&htbl->bits[8] = *(_QWORD *)&bits[8];
  htbl->bits[16] = v21;
  v22 = 0;
  for ( n = 1; n <= 32; ++n )
  {
    for ( ii = 0; ii <= 255; ++ii )
    {
      if ( codesize[ii] == n )
        htbl->huffval[v22++] = ii;
    }
  }
  htbl->sent_table = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00432110
// Name: finish_pass_gather
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_gather(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // edi
  int dc_tbl_no; // esi
  bool v3; // zf
  int ac_tbl_no; // ebx
  int *v5; // ebx
  int v6; // eax
  int v7; // esi
  int i; // ecx
  int v9; // edx
  int v10; // edx
  int j; // ecx
  int v12; // esi
  bool v13; // sf
  int *v14; // ecx
  int *v15; // eax
  int v16; // eax
  int k; // ebx
  int v18; // esi
  int m; // ecx
  int n; // eax
  _QWORD *v21; // ecx
  char v22; // al
  int v23; // edx
  int ii; // esi
  int jj; // eax
  _DWORD v26[257]; // [esp+4h] [ebp-850h] BYREF
  _DWORD dst[257]; // [esp+408h] [ebp-44Ch] BYREF
  unsigned __int8 *v28; // [esp+80Ch] [ebp-48h]
  int actbl; // [esp+810h] [ebp-44h]
  unsigned __int8 did_dc[4]; // [esp+814h] [ebp-40h] BYREF
  unsigned __int8 did_ac[4]; // [esp+818h] [ebp-3Ch]
  _QWORD *v32; // [esp+81Ch] [ebp-38h]
  __int64 v33; // [esp+820h] [ebp-34h]
  __int64 v34; // [esp+828h] [ebp-2Ch]
  __int64 v35; // [esp+830h] [ebp-24h]
  __int64 v36; // [esp+838h] [ebp-1Ch]
  char v37; // [esp+840h] [ebp-14h]
  int v38; // [esp+844h] [ebp-10h]
  int ci; // [esp+848h] [ebp-Ch]
  huff_entropy_encoder *entropy; // [esp+84Ch] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+850h] [ebp-4h]

  v1 = cinfo;
  entropy = (huff_entropy_encoder *)cinfo[14].client_data;
  *(_DWORD *)did_dc = 0;
  *(_DWORD *)did_ac = 0;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      dc_tbl_no = (*p_is_decompressor)->dc_tbl_no;
      v3 = did_dc[dc_tbl_no] == 0;
      ac_tbl_no = (*p_is_decompressor)->ac_tbl_no;
      actbl = ac_tbl_no;
      v28 = &did_dc[dc_tbl_no];
      if ( v3 )
      {
        if ( *((_DWORD *)&v1[3].is_decompressor + dc_tbl_no) == 0 )
          *((_DWORD *)&v1[3].is_decompressor + dc_tbl_no) = jpeg_alloc_huff_table(cinfo: v1);
        v5 = entropy->dc_count_ptrs[dc_tbl_no];
        v32 = *((_QWORD **)&v1[3].is_decompressor + dc_tbl_no);
        v33 = 0;
        v34 = 0;
        v35 = 0;
        v36 = 0;
        v37 = 0;
        memset((unsigned __int8 *)dst, value: 0, count: sizeof(dst));
        memset(v26, 0xFFu, sizeof(v26));
        v5[256] = 1;
        while ( 1 )
        {
          v6 = -1;
          v7 = 1000000000;
          for ( i = 0; i <= 256; ++i )
          {
            v9 = v5[i];
            if ( v9 != 0 && v9 <= v7 )
            {
              v7 = v5[i];
              v6 = i;
            }
          }
          v10 = -1;
          v38 = 1000000000;
          for ( j = 0; j <= 256; ++j )
          {
            v12 = v5[j];
            if ( v12 != 0 && v12 <= v38 && j != v6 )
            {
              v38 = v5[j];
              v10 = j;
            }
          }
          if ( v10 < 0 )
            break;
          v5[v6] += v5[v10];
          ++dst[v6];
          v13 = (int)v26[v6] < 0;
          v14 = &v26[v6];
          v5[v10] = 0;
          if ( !v13 )
          {
            do
            {
              v6 = *v14;
              ++dst[v6];
              v14 = &v26[v6];
            }
            while ( *v14 >= 0 );
          }
          ++dst[v10];
          v26[v6] = v10;
          v15 = &v26[v10];
          if ( *v15 >= 0 )
          {
            do
            {
              v16 = *v15;
              ++dst[v16];
              v13 = (int)v26[v16] < 0;
              v15 = &v26[v16];
            }
            while ( !v13 );
          }
        }
        for ( k = 0; k <= 256; ++k )
        {
          v18 = dst[k];
          if ( v18 != 0 )
          {
            if ( v18 > 32 )
            {
              cinfo->err->msg_code = 39;
              cinfo->err->error_exit(a1: cinfo);
            }
            ++*((_BYTE *)&v33 + v18);
          }
        }
        for ( m = 32; m > 16; --m )
        {
          for ( ; *((_BYTE *)&v33 + m) != 0; --*((_BYTE *)&v33 + n) )
          {
            for ( n = m - 2; *((_BYTE *)&v33 + n) == 0; --n )
              ;
            *((_BYTE *)&v33 + m) -= 2;
            ++*((_BYTE *)&v32 + m + 3);
            *((_BYTE *)&v33 + n + 1) += 2;
          }
        }
        for ( ; *((_BYTE *)&v33 + m) == 0; --m )
          ;
        --*((_BYTE *)&v33 + m);
        v21 = v32;
        v22 = v35;
        *v32 = v33;
        v21[1] = v34;
        *((_BYTE *)v21 + 16) = v22;
        v23 = 0;
        for ( ii = 1; ii <= 32; ++ii )
        {
          for ( jj = 0; jj <= 255; ++jj )
          {
            if ( dst[jj] == ii )
            {
              *((_BYTE *)v21 + v23 + 17) = jj;
              ++v23;
            }
          }
        }
        ac_tbl_no = actbl;
        v1 = cinfo;
        *((_BYTE *)v21 + 273) = 0;
        *v28 = 1;
      }
      if ( did_ac[ac_tbl_no] == 0 )
      {
        if ( *((_DWORD *)&v1[4].progress + ac_tbl_no) == 0 )
          *((_DWORD *)&v1[4].progress + ac_tbl_no) = jpeg_alloc_huff_table(cinfo: v1);
        jpeg_gen_optimal_table(
          cinfo: v1,
          htbl: *((JHUFF_TBL **)&v1[4].progress + ac_tbl_no),
          freq: entropy->ac_count_ptrs[ac_tbl_no]);
        did_ac[ac_tbl_no] = 1;
      }
      ++p_is_decompressor;
      ++ci;
    }
    while ( ci < (int)v1[9].client_data );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432410
// Name: start_pass_huff
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_huff(jpeg_common_struct *cinfo, unsigned __int8 gather_statistics)
{
  jpeg_entropy_encoder *client_data; // edi
  unsigned int dc_tbl_no; // ebx
  unsigned int ac_tbl_no; // eax
  void (__cdecl **p_finish_pass)(jpeg_compress_struct *); // [esp+8h] [ebp-Ch]
  int ci; // [esp+Ch] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+10h] [ebp-4h]
  unsigned int actbl; // [esp+1Ch] [ebp+8h]

  client_data = (jpeg_entropy_encoder *)cinfo[14].client_data;
  if ( gather_statistics != 0 )
  {
    client_data->encode_mcu = encode_mcu_gather;
    client_data->finish_pass = (void (__cdecl *)(jpeg_compress_struct *))finish_pass_gather;
  }
  else
  {
    client_data->encode_mcu = encode_mcu_huff;
    client_data->finish_pass = finish_pass_huff;
  }
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_finish_pass = &client_data[1].finish_pass;
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      dc_tbl_no = (*p_is_decompressor)->dc_tbl_no;
      ac_tbl_no = (*p_is_decompressor)->ac_tbl_no;
      actbl = ac_tbl_no;
      if ( gather_statistics != 0 )
      {
        if ( dc_tbl_no >= 4 )
        {
          cinfo->err->msg_code = 50;
          cinfo->err->msg_parm.i[0] = dc_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
          ac_tbl_no = actbl;
        }
        if ( ac_tbl_no >= 4 )
        {
          cinfo->err->msg_code = 50;
          cinfo->err->msg_parm.i[0] = ac_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( *((_DWORD *)&client_data[6].encode_mcu + dc_tbl_no) == 0 )
          *((_DWORD *)&client_data[6].encode_mcu + dc_tbl_no) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
        memset(dst: *((unsigned __int8 **)&client_data[6].encode_mcu + dc_tbl_no), value: 0, count: 0x404u);
        if ( *((_DWORD *)&client_data[7].finish_pass + actbl) == 0 )
          *((_DWORD *)&client_data[7].finish_pass + actbl) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
        memset(dst: *((unsigned __int8 **)&client_data[7].finish_pass + actbl), value: 0, count: 0x404u);
      }
      else
      {
        jpeg_make_c_derived_tbl(
          cinfo,
          isDC: 1u,
          tblno: dc_tbl_no,
          pdtbl: (c_derived_tbl **)&client_data[3].finish_pass + dc_tbl_no);
        jpeg_make_c_derived_tbl(
          cinfo,
          isDC: 0,
          tblno: actbl,
          pdtbl: (c_derived_tbl **)&client_data[5].start_pass + actbl);
      }
      ++p_is_decompressor;
      *p_finish_pass = nullptr;
      ++ci;
      ++p_finish_pass;
    }
    while ( ci < (int)cinfo[9].client_data );
  }
  client_data[1].start_pass = nullptr;
  client_data[1].encode_mcu = nullptr;
  client_data[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))cinfo[7].global_state;
  client_data[3].encode_mcu = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004325A0
// Name: _jinit_huff_encoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_huff_encoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_encoder *v1; // eax

  v1 = (jpeg_entropy_encoder *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 108);
  cinfo[14].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))start_pass_huff;
  v1[5].start_pass = nullptr;
  v1[3].finish_pass = nullptr;
  v1[7].finish_pass = nullptr;
  v1[6].encode_mcu = nullptr;
  v1[5].encode_mcu = nullptr;
  v1[4].start_pass = nullptr;
  v1[8].start_pass = nullptr;
  v1[6].finish_pass = nullptr;
  v1[5].finish_pass = nullptr;
  v1[4].encode_mcu = nullptr;
  v1[8].encode_mcu = nullptr;
  v1[7].start_pass = nullptr;
  v1[6].start_pass = nullptr;
  v1[4].finish_pass = nullptr;
  v1[8].finish_pass = nullptr;
  v1[7].encode_mcu = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00432600
// Name: emit_bits_0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_bits_0(phuff_entropy_encoder *entropy@<esi>, unsigned int code, int size)
{
  int v3; // ebx
  int v4; // ebx
  unsigned int v5; // edi
  bool v6; // zf
  jpeg_destination_mgr *dest; // ebx
  int put_bits; // [esp+8h] [ebp-4h]
  jpeg_destination_mgr *codea; // [esp+14h] [ebp+8h]
  int sizea; // [esp+18h] [ebp+Ch]

  v3 = entropy->put_bits;
  if ( size == 0 )
  {
    entropy->cinfo->err->msg_code = 40;
    entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
  }
  if ( entropy->gather_statistics == 0 )
  {
    v4 = size + v3;
    v5 = entropy->put_buffer | ((code & ((1 << size) - 1)) << (24 - v4));
    if ( v4 >= 8 )
    {
      sizea = (unsigned int)v4 >> 3;
      put_bits = v4 - 8 * ((unsigned int)v4 >> 3);
      do
      {
        *entropy->next_output_byte++ = BYTE2(v5);
        v6 = entropy->free_in_buffer-- == 1;
        if ( v6 )
        {
          codea = entropy->cinfo->dest;
          if ( codea->empty_output_buffer(a1: entropy->cinfo) == 0 )
          {
            entropy->cinfo->err->msg_code = 24;
            entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
          }
          entropy->next_output_byte = codea->next_output_byte;
          entropy->free_in_buffer = codea->free_in_buffer;
        }
        if ( BYTE2(v5) == 255 )
        {
          *entropy->next_output_byte++ = 0;
          v6 = entropy->free_in_buffer-- == 1;
          if ( v6 )
          {
            dest = entropy->cinfo->dest;
            if ( dest->empty_output_buffer(a1: entropy->cinfo) == 0 )
            {
              entropy->cinfo->err->msg_code = 24;
              entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
            }
            entropy->next_output_byte = dest->next_output_byte;
            entropy->free_in_buffer = dest->free_in_buffer;
          }
        }
        v5 <<= 8;
        --sizea;
      }
      while ( sizea != 0 );
      v4 = put_bits;
    }
    entropy->put_buffer = v5;
    entropy->put_bits = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432920
// Name: emit_restart_0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_restart_0(phuff_entropy_encoder *entropy@<eax>, char restart_num)
{
  bool v3; // zf
  jpeg_destination_mgr *dest; // edi
  jpeg_destination_mgr *v5; // edi
  jpeg_compress_struct *cinfo; // ecx
  int v7; // eax
  int *last_dc_val; // ecx

  emit_eobrun(entropy);
  if ( entropy->gather_statistics == 0 )
  {
    emit_bits_0(entropy, code: 0x7Fu, size: 7);
    entropy->put_buffer = 0;
    entropy->put_bits = 0;
    *entropy->next_output_byte++ = -1;
    v3 = entropy->free_in_buffer-- == 1;
    if ( v3 )
    {
      dest = entropy->cinfo->dest;
      if ( dest->empty_output_buffer(a1: entropy->cinfo) == 0 )
      {
        entropy->cinfo->err->msg_code = 24;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
      entropy->next_output_byte = dest->next_output_byte;
      entropy->free_in_buffer = dest->free_in_buffer;
    }
    *entropy->next_output_byte++ = restart_num - 48;
    v3 = entropy->free_in_buffer-- == 1;
    if ( v3 )
    {
      v5 = entropy->cinfo->dest;
      if ( v5->empty_output_buffer(a1: entropy->cinfo) == 0 )
      {
        entropy->cinfo->err->msg_code = 24;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
      entropy->next_output_byte = v5->next_output_byte;
      entropy->free_in_buffer = v5->free_in_buffer;
    }
  }
  cinfo = entropy->cinfo;
  if ( cinfo->Ss != 0 )
  {
    entropy->EOBRUN = 0;
    entropy->BE = 0;
  }
  else
  {
    v7 = 0;
    if ( cinfo->comps_in_scan > 0 )
    {
      last_dc_val = entropy->last_dc_val;
      do
      {
        *last_dc_val = 0;
        ++v7;
        ++last_dc_val;
      }
      while ( v7 < entropy->cinfo->comps_in_scan );
    }
  }
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041E3F0
// Name: _jpeg_make_c_derived_tbl
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_make_c_derived_tbl(
        jpeg_common_struct *cinfo,
        unsigned __int8 isDC,
        unsigned int tblno,
        c_derived_tbl **pdtbl)
{
  int v5; // edi
  int i; // ebx
  unsigned int v7; // esi
  int v8; // ebx
  signed int v9; // edi
  int v10; // esi
  c_derived_tbl **v11; // edx
  char *v12; // eax
  int v13; // eax
  int j; // esi
  int v15; // edi
  unsigned int v16; // ecx
  char v17; // dl
  c_derived_tbl *v18; // eax
  unsigned int huffcode[257]; // [esp+Ch] [ebp-510h]
  char huffsize[260]; // [esp+410h] [ebp-10Ch] BYREF
  int lastp; // [esp+514h] [ebp-8h]
  c_derived_tbl *dtbl; // [esp+518h] [ebp-4h]
  JHUFF_TBL *htbl; // [esp+52Ch] [ebp+10h]
  c_derived_tbl **pdtbla; // [esp+530h] [ebp+14h]

  if ( tblno >= 4 )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( isDC != 0 )
    htbl = *((JHUFF_TBL **)&cinfo[3].is_decompressor + tblno);
  else
    htbl = *((JHUFF_TBL **)&cinfo[4].progress + tblno);
  if ( htbl == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *pdtbl == nullptr )
    *pdtbl = (c_derived_tbl *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1280);
  dtbl = *pdtbl;
  v5 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    v7 = htbl->bits[i];
    if ( (int)(v7 + v5) > 256 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v7 != 0 )
    {
      memset(dst: (unsigned __int8 *)&huffsize[v5], value: i, count: v7);
      v5 += v7;
    }
  }
  huffsize[v5] = 0;
  v8 = huffsize[0];
  lastp = v5;
  v9 = 0;
  v10 = 0;
  v11 = (c_derived_tbl **)__ROL4__(1, huffsize[0]);
  pdtbla = v11;
  if ( huffsize[0] != 0 )
  {
    v12 = huffsize;
    while ( 1 )
    {
      if ( *v12 == v8 )
      {
        do
        {
          v13 = huffsize[v10 + 1];
          huffcode[v10++] = v9++;
        }
        while ( v13 == v8 );
      }
      if ( v9 >= (int)v11 )
      {
        cinfo->err->msg_code = 8;
        cinfo->err->error_exit(a1: cinfo);
        v11 = pdtbla;
      }
      v9 *= 2;
      ++v8;
      v12 = &huffsize[v10];
      pdtbla = (c_derived_tbl **)__ROL4__(v11, 1);
      if ( huffsize[v10] == 0 )
        break;
      v11 = pdtbla;
    }
  }
  memset(dst: (unsigned __int8 *)dtbl->ehufsi, value: 0, count: sizeof(dtbl->ehufsi));
  for ( j = 0; j < lastp; v18->ehufsi[v15] = v17 )
  {
    v15 = htbl->huffval[j];
    if ( v15 > (isDC != 0 ? 15 : 255) || dtbl->ehufsi[v15] != 0 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    v16 = huffcode[j];
    v17 = huffsize[j];
    v18 = dtbl;
    ++j;
    dtbl->ehufco[v15] = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E5F0
// Name: emit_bits
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall emit_bits@<al>(working_state *state@<esi>, unsigned int code, int size)
{
  int v3; // ebx
  int v4; // ebx
  unsigned int v5; // edi
  bool v6; // zf
  jpeg_destination_mgr *dest; // ebx
  int v8; // eax
  int put_bits; // [esp+8h] [ebp-4h]
  jpeg_destination_mgr *sizea; // [esp+18h] [ebp+Ch]

  v3 = state->cur.put_bits;
  if ( size == 0 )
  {
    state->cinfo->err->msg_code = 40;
    state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
  }
  v4 = size + v3;
  put_bits = v4;
  v5 = state->cur.put_buffer | ((code & ((1 << size) - 1)) << (24 - v4));
  if ( v4 < 8 )
  {
LABEL_13:
    state->cur.put_buffer = v5;
    state->cur.put_bits = v4;
    return 1;
  }
  while ( 1 )
  {
    *state->next_output_byte++ = BYTE2(v5);
    v6 = state->free_in_buffer-- == 1;
    if ( v6 )
    {
      sizea = state->cinfo->dest;
      if ( sizea->empty_output_buffer(a1: state->cinfo) == 0 )
        return 0;
      state->next_output_byte = sizea->next_output_byte;
      state->free_in_buffer = sizea->free_in_buffer;
    }
    if ( BYTE2(v5) == 255 )
    {
      *state->next_output_byte++ = 0;
      v6 = state->free_in_buffer-- == 1;
      if ( v6 )
        break;
    }
LABEL_11:
    v8 = put_bits - 8;
    v5 <<= 8;
    put_bits = v8;
    if ( v8 < 8 )
    {
      v4 = v8;
      goto LABEL_13;
    }
  }
  dest = state->cinfo->dest;
  if ( dest->empty_output_buffer(a1: state->cinfo) != 0 )
  {
    state->next_output_byte = dest->next_output_byte;
    state->free_in_buffer = dest->free_in_buffer;
    goto LABEL_11;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E6E0
// Name: encode_one_block
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_one_block(
        working_state *state,
        __int16 *block,
        int last_dc_val,
        c_derived_tbl *dctbl,
        c_derived_tbl *actbl)
{
  signed int v5; // edi
  int v6; // eax
  int v7; // ebx
  working_state *v8; // esi
  int *v10; // eax
  int v11; // edi
  int v12; // ebx
  int v13; // ebx
  int v14; // esi
  working_state *v15; // ebx
  int *v16; // [esp+Ch] [ebp-4h]
  unsigned int temp2; // [esp+20h] [ebp+10h]
  int nbits; // [esp+24h] [ebp+14h]

  v5 = *block - last_dc_val;
  v6 = v5;
  if ( v5 < 0 )
  {
    v6 = last_dc_val - *block;
    --v5;
  }
  v7 = 0;
  if ( v6 == 0 )
    goto LABEL_7;
  do
  {
    ++v7;
    v6 >>= 1;
  }
  while ( v6 != 0 );
  if ( v7 > 11 )
  {
    v8 = state;
    state->cinfo->err->msg_code = 6;
    state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
  }
  else
  {
LABEL_7:
    v8 = state;
  }
  if ( emit_bits(state: v8, code: dctbl->ehufco[v7], size: dctbl->ehufsi[v7]) != 0
    && (v7 == 0 || emit_bits(state: v8, code: v5, size: v7) != 0) )
  {
    v10 = (int *)&unk_43F494;
    v11 = 0;
    v16 = (int *)&unk_43F494;
    do
    {
      v12 = block[*v10];
      if ( block[*v10] != 0 )
      {
        if ( v11 > 15 )
        {
          while ( emit_bits(state, code: actbl->ehufco[240], size: actbl->ehufsi[240]) != 0 )
          {
            v11 -= 16;
            if ( v11 <= 15 )
              goto LABEL_18;
          }
          return 0;
        }
LABEL_18:
        temp2 = v12;
        if ( v12 < 0 )
        {
          v12 = -v12;
          --temp2;
        }
        v13 = v12 >> 1;
        v14 = 1;
        nbits = 1;
        if ( v13 == 0 )
          goto LABEL_24;
        do
        {
          ++v14;
          v13 >>= 1;
        }
        while ( v13 != 0 );
        nbits = v14;
        if ( v14 > 10 )
        {
          v15 = state;
          state->cinfo->err->msg_code = 6;
          state->cinfo->err->error_exit(a1: (jpeg_common_struct *)state->cinfo);
        }
        else
        {
LABEL_24:
          v15 = state;
        }
        if ( emit_bits(state: v15, code: actbl->ehufco[16 * v11 + v14], size: actbl->ehufsi[16 * v11 + v14]) == 0
          || emit_bits(state: v15, code: temp2, size: nbits) == 0 )
        {
          return 0;
        }
        v10 = v16;
        v11 = 0;
      }
      else
      {
        ++v11;
      }
      v16 = ++v10;
    }
    while ( (int)v10 < (int)dword_43F590 );
    if ( v11 <= 0 || emit_bits(state, code: actbl->ehufco[0], size: actbl->ehufsi[0]) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E890
// Name: emit_restart
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall emit_restart@<al>(working_state *state@<eax>, char restart_num)
{
  bool v3; // zf
  jpeg_destination_mgr *dest; // edi
  jpeg_destination_mgr *v5; // edi
  int v6; // eax
  int *last_dc_val; // ecx

  if ( emit_bits(state, code: 0x7Fu, size: 7) == 0 )
    return 0;
  state->cur.put_buffer = 0;
  state->cur.put_bits = 0;
  *state->next_output_byte++ = -1;
  v3 = state->free_in_buffer-- == 1;
  if ( v3 )
  {
    dest = state->cinfo->dest;
    if ( dest->empty_output_buffer(a1: state->cinfo) == 0 )
      return 0;
    state->next_output_byte = dest->next_output_byte;
    state->free_in_buffer = dest->free_in_buffer;
  }
  *state->next_output_byte++ = restart_num - 48;
  v3 = state->free_in_buffer-- == 1;
  if ( v3 )
  {
    v5 = state->cinfo->dest;
    if ( v5->empty_output_buffer(a1: state->cinfo) != 0 )
    {
      state->next_output_byte = v5->next_output_byte;
      state->free_in_buffer = v5->free_in_buffer;
      goto LABEL_8;
    }
    return 0;
  }
LABEL_8:
  v6 = 0;
  if ( state->cinfo->comps_in_scan > 0 )
  {
    last_dc_val = state->cur.last_dc_val;
    do
    {
      *last_dc_val = 0;
      ++v6;
      ++last_dc_val;
    }
    while ( v6 < state->cinfo->comps_in_scan );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041E950
// Name: encode_mcu_huff
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_huff(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  bool v3; // zf
  jpeg_entropy_encoder *entropy; // esi
  jpeg_destination_mgr *dest; // eax
  unsigned __int8 *next_output_byte; // ecx
  unsigned int free_in_buffer; // edx
  unsigned __int8 result; // al
  int v9; // ebx
  jpeg_component_info *v10; // ecx
  __int16 *v11; // edx
  int v12; // eax
  __int64 v13; // xmm0_8
  unsigned int restart_interval; // edi
  int v15; // eax
  c_derived_tbl *v16; // [esp-Ch] [ebp-3Ch]
  c_derived_tbl *v17; // [esp-8h] [ebp-38h]
  working_state state; // [esp+8h] [ebp-28h] BYREF
  int *v19; // [esp+2Ch] [ebp-4h]
  int *cinfoa; // [esp+38h] [ebp+8h]

  v3 = cinfo->restart_interval == 0;
  entropy = cinfo->entropy;
  dest = cinfo->dest;
  next_output_byte = dest->next_output_byte;
  free_in_buffer = dest->free_in_buffer;
  *(_QWORD *)&state.cur.put_buffer = *(_QWORD *)&entropy[1].start_pass;
  *(_QWORD *)state.cur.last_dc_val = *(_QWORD *)&entropy[1].finish_pass;
  state.next_output_byte = next_output_byte;
  state.free_in_buffer = free_in_buffer;
  *(_QWORD *)&state.cur.last_dc_val[2] = *(_QWORD *)&entropy[2].encode_mcu;
  state.cinfo = cinfo;
  if ( v3
    || entropy[3].start_pass != nullptr
    || (result = emit_restart(&state, restart_num: (char)entropy[3].encode_mcu)) != 0 )
  {
    v9 = 0;
    if ( cinfo->blocks_in_MCU <= 0 )
    {
LABEL_8:
      v13 = *(_QWORD *)&state.cur.put_buffer;
      cinfo->dest->next_output_byte = state.next_output_byte;
      cinfo->dest->free_in_buffer = state.free_in_buffer;
      *(_QWORD *)&entropy[1].start_pass = v13;
      *(_OWORD *)&entropy[1].finish_pass = *(_OWORD *)state.cur.last_dc_val;
      restart_interval = cinfo->restart_interval;
      if ( restart_interval != 0 )
      {
        if ( entropy[3].start_pass == nullptr )
        {
          v15 = ((unsigned __int8)entropy[3].encode_mcu + 1) & 7;
          entropy[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))restart_interval;
          entropy[3].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))v15;
        }
        --entropy[3].start_pass;
      }
      return 1;
    }
    else
    {
      cinfoa = cinfo->MCU_membership;
      while ( 1 )
      {
        v10 = cinfo->cur_comp_info[*cinfoa];
        v17 = *((c_derived_tbl **)&entropy[5].start_pass + v10->ac_tbl_no);
        v16 = *((c_derived_tbl **)&entropy[3].finish_pass + v10->dc_tbl_no);
        v11 = (__int16 *)MCU_data[v9];
        v19 = &state.cur.last_dc_val[*cinfoa];
        if ( encode_one_block(&state, block: v11, last_dc_val: *v19, dctbl: v16, actbl: v17) == 0 )
          return 0;
        v12 = (*MCU_data[v9])[0];
        ++cinfoa;
        ++v9;
        *v19 = v12;
        if ( v9 >= cinfo->blocks_in_MCU )
          goto LABEL_8;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041EA90
// Name: finish_pass_huff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_huff(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // eax
  unsigned __int8 *next_output_byte; // ecx
  unsigned int free_in_buffer; // edx
  jpeg_entropy_encoder *entropy; // edi
  __int64 v5; // xmm0_8
  __int64 v6; // xmm0_8
  working_state state; // [esp+Ch] [ebp-24h] BYREF

  dest = cinfo->dest;
  next_output_byte = dest->next_output_byte;
  free_in_buffer = dest->free_in_buffer;
  entropy = cinfo->entropy;
  *(_QWORD *)&state.cur.put_buffer = *(_QWORD *)&entropy[1].start_pass;
  *(_QWORD *)state.cur.last_dc_val = *(_QWORD *)&entropy[1].finish_pass;
  v5 = *(_QWORD *)&entropy[2].encode_mcu;
  state.next_output_byte = next_output_byte;
  state.free_in_buffer = free_in_buffer;
  *(_QWORD *)&state.cur.last_dc_val[2] = v5;
  state.cinfo = cinfo;
  if ( emit_bits(&state, code: 0x7Fu, size: 7) != 0 )
  {
    state.cur.put_buffer = 0;
    state.cur.put_bits = 0;
  }
  else
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
  }
  v6 = *(_QWORD *)&state.cur.put_buffer;
  cinfo->dest->next_output_byte = state.next_output_byte;
  cinfo->dest->free_in_buffer = state.free_in_buffer;
  *(_QWORD *)&entropy[1].start_pass = v6;
  *(_OWORD *)&entropy[1].finish_pass = *(_OWORD *)state.cur.last_dc_val;
}

//------------------------------------------------------------------------------
// Address: 0x0041EB40
// Name: encode_mcu_gather
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_gather(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_compress_struct *v2; // edx
  jpeg_entropy_encoder *p_pub; // esi
  int v4; // eax
  void (__cdecl **p_finish_pass)(jpeg_compress_struct *); // ecx
  jpeg_component_info *v6; // eax
  int v7; // edi
  _DWORD *v8; // ebx
  int v9; // eax
  int v10; // esi
  int *v11; // eax
  int v12; // esi
  int v13; // ecx
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // edi
  __int16 *v18; // [esp+4h] [ebp-18h]
  int ci; // [esp+8h] [ebp-14h]
  huff_entropy_encoder *entropy; // [esp+Ch] [ebp-10h]
  int *v21; // [esp+10h] [ebp-Ch]
  int *MCU_membership; // [esp+14h] [ebp-8h]
  int blkn; // [esp+18h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->entropy;
  entropy = (huff_entropy_encoder *)p_pub;
  if ( cinfo->restart_interval != 0 )
  {
    if ( p_pub[3].start_pass == nullptr )
    {
      v4 = 0;
      if ( cinfo->comps_in_scan > 0 )
      {
        p_finish_pass = &p_pub[1].finish_pass;
        do
        {
          *p_finish_pass = nullptr;
          ++v4;
          ++p_finish_pass;
        }
        while ( v4 < cinfo->comps_in_scan );
      }
      p_pub[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))cinfo->restart_interval;
    }
    --p_pub[3].start_pass;
  }
  blkn = 0;
  if ( cinfo->blocks_in_MCU > 0 )
  {
    MCU_membership = cinfo->MCU_membership;
    do
    {
      ci = *MCU_membership;
      v6 = v2->cur_comp_info[*MCU_membership];
      v7 = *((_DWORD *)&p_pub[6].encode_mcu + v6->dc_tbl_no);
      v8 = *((_DWORD **)&p_pub[7].finish_pass + v6->ac_tbl_no);
      v18 = (__int16 *)MCU_data[blkn];
      v9 = *v18 - *((_DWORD *)&p_pub[1].finish_pass + *MCU_membership);
      if ( v9 < 0 )
        v9 = *((_DWORD *)&p_pub[1].finish_pass + *MCU_membership) - *v18;
      v10 = 0;
      if ( v9 != 0 )
      {
        do
        {
          ++v10;
          v9 >>= 1;
        }
        while ( v9 != 0 );
        if ( v10 > 11 )
        {
          v2->err->msg_code = 6;
          v2->err->error_exit(a1: (jpeg_common_struct *)v2);
          v2 = cinfo;
        }
      }
      ++*(_DWORD *)(v7 + 4 * v10);
      v11 = (int *)&unk_43F494;
      v12 = 0;
      v21 = (int *)&unk_43F494;
      do
      {
        v13 = v18[*v11];
        if ( v18[*v11] != 0 )
        {
          if ( v12 > 15 )
          {
            v14 = ((unsigned int)(v12 - 16) >> 4) + 1;
            v12 += -16 * v14;
            v8[240] += v14;
            v2 = cinfo;
          }
          if ( v13 < 0 )
            v13 = -v13;
          v15 = v13 >> 1;
          v16 = 1;
          if ( v15 != 0 )
          {
            do
            {
              ++v16;
              v15 >>= 1;
            }
            while ( v15 != 0 );
            if ( v16 > 10 )
            {
              v2->err->msg_code = 6;
              v2->err->error_exit(a1: (jpeg_common_struct *)v2);
              v2 = cinfo;
            }
          }
          ++v8[16 * v12 + v16];
          v11 = v21;
          v12 = 0;
        }
        else
        {
          ++v12;
        }
        v21 = ++v11;
      }
      while ( (int)v11 < (int)dword_43F590 );
      if ( v12 > 0 )
        ++*v8;
      p_pub = &entropy->pub;
      ++MCU_membership;
      entropy->saved.last_dc_val[ci] = (*MCU_data[blkn++])[0];
    }
    while ( blkn < v2->blocks_in_MCU );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041ECE0
// Name: _jpeg_gen_optimal_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_gen_optimal_table(jpeg_common_struct *cinfo, JHUFF_TBL *htbl, int *freq)
{
  int v3; // eax
  int v4; // esi
  int i; // ecx
  int v6; // edx
  int v7; // edx
  int v8; // edi
  int j; // ecx
  int v10; // esi
  bool v11; // sf
  int *v12; // ecx
  int *v13; // eax
  int v14; // eax
  int k; // edi
  int v16; // esi
  int v17; // esi
  int v18; // ecx
  int v19; // edx
  int m; // eax
  unsigned __int8 v21; // dl
  int v22; // edx
  int n; // esi
  int ii; // eax
  int others[257]; // [esp+Ch] [ebp-82Ch] BYREF
  int codesize[257]; // [esp+410h] [ebp-428h] BYREF
  unsigned __int8 bits[33]; // [esp+814h] [ebp-24h] BYREF

  memset(bits, 0, sizeof(bits));
  memset(dst: (unsigned __int8 *)codesize, value: 0, count: sizeof(codesize));
  memset(others, 0xFFu, sizeof(others));
  freq[256] = 1;
  while ( 1 )
  {
    v3 = -1;
    v4 = 1000000000;
    for ( i = 0; i <= 256; ++i )
    {
      v6 = freq[i];
      if ( v6 != 0 && v6 <= v4 )
      {
        v4 = freq[i];
        v3 = i;
      }
    }
    v7 = -1;
    v8 = 1000000000;
    for ( j = 0; j <= 256; ++j )
    {
      v10 = freq[j];
      if ( v10 != 0 && v10 <= v8 && j != v3 )
      {
        v8 = freq[j];
        v7 = j;
      }
    }
    if ( v7 < 0 )
      break;
    freq[v3] += freq[v7];
    ++codesize[v3];
    v11 = others[v3] < 0;
    v12 = &others[v3];
    freq[v7] = 0;
    if ( !v11 )
    {
      do
      {
        v3 = *v12;
        ++codesize[v3];
        v12 = &others[v3];
      }
      while ( *v12 >= 0 );
    }
    ++codesize[v7];
    others[v3] = v7;
    v13 = &others[v7];
    if ( *v13 >= 0 )
    {
      do
      {
        v14 = *v13;
        ++codesize[v14];
        v11 = others[v14] < 0;
        v13 = &others[v14];
      }
      while ( !v11 );
    }
  }
  for ( k = 0; k <= 256; ++k )
  {
    v16 = codesize[k];
    if ( v16 != 0 )
    {
      if ( v16 > 32 )
      {
        cinfo->err->msg_code = 39;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++bits[v16];
    }
  }
  v17 = 16;
  v18 = 30;
  v19 = 16;
  do
  {
    for ( ; bits[v18 + 2] != 0; --bits[m] )
    {
      for ( m = v18; bits[m] == 0; --m )
        ;
      bits[v18 + 2] -= 2;
      ++bits[v18 + 1];
      bits[m + 1] += 2;
    }
    --v18;
    --v17;
  }
  while ( v17 != 0 );
  if ( bits[16] == 0 )
  {
    do
      --v19;
    while ( bits[v19] == 0 );
  }
  --bits[v19];
  v21 = bits[16];
  *(_QWORD *)htbl->bits = *(_QWORD *)bits;
  *(_QWORD *)&htbl->bits[8] = *(_QWORD *)&bits[8];
  htbl->bits[16] = v21;
  v22 = 0;
  for ( n = 1; n <= 32; ++n )
  {
    for ( ii = 0; ii <= 255; ++ii )
    {
      if ( codesize[ii] == n )
        htbl->huffval[v22++] = ii;
    }
  }
  htbl->sent_table = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041EF10
// Name: finish_pass_gather
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_gather(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // edi
  int dc_tbl_no; // esi
  bool v3; // zf
  int ac_tbl_no; // ebx
  int *v5; // ebx
  int v6; // eax
  int v7; // esi
  int i; // ecx
  int v9; // edx
  int v10; // edx
  int j; // ecx
  int v12; // esi
  bool v13; // sf
  int *v14; // ecx
  int *v15; // eax
  int v16; // eax
  int k; // ebx
  int v18; // esi
  int m; // ecx
  int n; // eax
  _QWORD *v21; // ecx
  char v22; // al
  int v23; // edx
  int ii; // esi
  int jj; // eax
  _DWORD v26[257]; // [esp+4h] [ebp-850h] BYREF
  _DWORD dst[257]; // [esp+408h] [ebp-44Ch] BYREF
  unsigned __int8 *v28; // [esp+80Ch] [ebp-48h]
  int actbl; // [esp+810h] [ebp-44h]
  unsigned __int8 did_dc[4]; // [esp+814h] [ebp-40h] BYREF
  unsigned __int8 did_ac[4]; // [esp+818h] [ebp-3Ch]
  _QWORD *v32; // [esp+81Ch] [ebp-38h]
  __int64 v33; // [esp+820h] [ebp-34h]
  __int64 v34; // [esp+828h] [ebp-2Ch]
  __int64 v35; // [esp+830h] [ebp-24h]
  __int64 v36; // [esp+838h] [ebp-1Ch]
  char v37; // [esp+840h] [ebp-14h]
  int v38; // [esp+844h] [ebp-10h]
  int ci; // [esp+848h] [ebp-Ch]
  huff_entropy_encoder *entropy; // [esp+84Ch] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+850h] [ebp-4h]

  v1 = cinfo;
  entropy = (huff_entropy_encoder *)cinfo[14].client_data;
  *(_DWORD *)did_dc = 0;
  *(_DWORD *)did_ac = 0;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      dc_tbl_no = (*p_is_decompressor)->dc_tbl_no;
      v3 = did_dc[dc_tbl_no] == 0;
      ac_tbl_no = (*p_is_decompressor)->ac_tbl_no;
      actbl = ac_tbl_no;
      v28 = &did_dc[dc_tbl_no];
      if ( v3 )
      {
        if ( *((_DWORD *)&v1[3].is_decompressor + dc_tbl_no) == 0 )
          *((_DWORD *)&v1[3].is_decompressor + dc_tbl_no) = jpeg_alloc_huff_table(cinfo: v1);
        v5 = entropy->dc_count_ptrs[dc_tbl_no];
        v32 = *((_QWORD **)&v1[3].is_decompressor + dc_tbl_no);
        v33 = 0;
        v34 = 0;
        v35 = 0;
        v36 = 0;
        v37 = 0;
        memset((unsigned __int8 *)dst, value: 0, count: sizeof(dst));
        memset(v26, 0xFFu, sizeof(v26));
        v5[256] = 1;
        while ( 1 )
        {
          v6 = -1;
          v7 = 1000000000;
          for ( i = 0; i <= 256; ++i )
          {
            v9 = v5[i];
            if ( v9 != 0 && v9 <= v7 )
            {
              v7 = v5[i];
              v6 = i;
            }
          }
          v10 = -1;
          v38 = 1000000000;
          for ( j = 0; j <= 256; ++j )
          {
            v12 = v5[j];
            if ( v12 != 0 && v12 <= v38 && j != v6 )
            {
              v38 = v5[j];
              v10 = j;
            }
          }
          if ( v10 < 0 )
            break;
          v5[v6] += v5[v10];
          ++dst[v6];
          v13 = (int)v26[v6] < 0;
          v14 = &v26[v6];
          v5[v10] = 0;
          if ( !v13 )
          {
            do
            {
              v6 = *v14;
              ++dst[v6];
              v14 = &v26[v6];
            }
            while ( *v14 >= 0 );
          }
          ++dst[v10];
          v26[v6] = v10;
          v15 = &v26[v10];
          if ( *v15 >= 0 )
          {
            do
            {
              v16 = *v15;
              ++dst[v16];
              v13 = (int)v26[v16] < 0;
              v15 = &v26[v16];
            }
            while ( !v13 );
          }
        }
        for ( k = 0; k <= 256; ++k )
        {
          v18 = dst[k];
          if ( v18 != 0 )
          {
            if ( v18 > 32 )
            {
              cinfo->err->msg_code = 39;
              cinfo->err->error_exit(a1: cinfo);
            }
            ++*((_BYTE *)&v33 + v18);
          }
        }
        for ( m = 32; m > 16; --m )
        {
          for ( ; *((_BYTE *)&v33 + m) != 0; --*((_BYTE *)&v33 + n) )
          {
            for ( n = m - 2; *((_BYTE *)&v33 + n) == 0; --n )
              ;
            *((_BYTE *)&v33 + m) -= 2;
            ++*((_BYTE *)&v32 + m + 3);
            *((_BYTE *)&v33 + n + 1) += 2;
          }
        }
        for ( ; *((_BYTE *)&v33 + m) == 0; --m )
          ;
        --*((_BYTE *)&v33 + m);
        v21 = v32;
        v22 = v35;
        *v32 = v33;
        v21[1] = v34;
        *((_BYTE *)v21 + 16) = v22;
        v23 = 0;
        for ( ii = 1; ii <= 32; ++ii )
        {
          for ( jj = 0; jj <= 255; ++jj )
          {
            if ( dst[jj] == ii )
            {
              *((_BYTE *)v21 + v23 + 17) = jj;
              ++v23;
            }
          }
        }
        ac_tbl_no = actbl;
        v1 = cinfo;
        *((_BYTE *)v21 + 273) = 0;
        *v28 = 1;
      }
      if ( did_ac[ac_tbl_no] == 0 )
      {
        if ( *((_DWORD *)&v1[4].progress + ac_tbl_no) == 0 )
          *((_DWORD *)&v1[4].progress + ac_tbl_no) = jpeg_alloc_huff_table(cinfo: v1);
        jpeg_gen_optimal_table(
          cinfo: v1,
          htbl: *((JHUFF_TBL **)&v1[4].progress + ac_tbl_no),
          freq: entropy->ac_count_ptrs[ac_tbl_no]);
        did_ac[ac_tbl_no] = 1;
      }
      ++p_is_decompressor;
      ++ci;
    }
    while ( ci < (int)v1[9].client_data );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F210
// Name: start_pass_huff
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_huff(jpeg_common_struct *cinfo, unsigned __int8 gather_statistics)
{
  jpeg_entropy_encoder *client_data; // edi
  unsigned int dc_tbl_no; // ebx
  unsigned int ac_tbl_no; // eax
  void (__cdecl **p_finish_pass)(jpeg_compress_struct *); // [esp+8h] [ebp-Ch]
  int ci; // [esp+Ch] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+10h] [ebp-4h]
  unsigned int actbl; // [esp+1Ch] [ebp+8h]

  client_data = (jpeg_entropy_encoder *)cinfo[14].client_data;
  if ( gather_statistics != 0 )
  {
    client_data->encode_mcu = encode_mcu_gather;
    client_data->finish_pass = (void (__cdecl *)(jpeg_compress_struct *))finish_pass_gather;
  }
  else
  {
    client_data->encode_mcu = encode_mcu_huff;
    client_data->finish_pass = finish_pass_huff;
  }
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_finish_pass = &client_data[1].finish_pass;
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      dc_tbl_no = (*p_is_decompressor)->dc_tbl_no;
      ac_tbl_no = (*p_is_decompressor)->ac_tbl_no;
      actbl = ac_tbl_no;
      if ( gather_statistics != 0 )
      {
        if ( dc_tbl_no >= 4 )
        {
          cinfo->err->msg_code = 50;
          cinfo->err->msg_parm.i[0] = dc_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
          ac_tbl_no = actbl;
        }
        if ( ac_tbl_no >= 4 )
        {
          cinfo->err->msg_code = 50;
          cinfo->err->msg_parm.i[0] = ac_tbl_no;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( *((_DWORD *)&client_data[6].encode_mcu + dc_tbl_no) == 0 )
          *((_DWORD *)&client_data[6].encode_mcu + dc_tbl_no) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
        memset(dst: *((unsigned __int8 **)&client_data[6].encode_mcu + dc_tbl_no), value: 0, count: 0x404u);
        if ( *((_DWORD *)&client_data[7].finish_pass + actbl) == 0 )
          *((_DWORD *)&client_data[7].finish_pass + actbl) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
        memset(dst: *((unsigned __int8 **)&client_data[7].finish_pass + actbl), value: 0, count: 0x404u);
      }
      else
      {
        jpeg_make_c_derived_tbl(
          cinfo,
          isDC: 1u,
          tblno: dc_tbl_no,
          pdtbl: (c_derived_tbl **)&client_data[3].finish_pass + dc_tbl_no);
        jpeg_make_c_derived_tbl(
          cinfo,
          isDC: 0,
          tblno: actbl,
          pdtbl: (c_derived_tbl **)&client_data[5].start_pass + actbl);
      }
      ++p_is_decompressor;
      *p_finish_pass = nullptr;
      ++ci;
      ++p_finish_pass;
    }
    while ( ci < (int)cinfo[9].client_data );
  }
  client_data[1].start_pass = nullptr;
  client_data[1].encode_mcu = nullptr;
  client_data[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))cinfo[7].global_state;
  client_data[3].encode_mcu = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041F3A0
// Name: _jinit_huff_encoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_huff_encoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_encoder *v1; // eax

  v1 = (jpeg_entropy_encoder *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 108);
  cinfo[14].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))start_pass_huff;
  v1[5].start_pass = nullptr;
  v1[3].finish_pass = nullptr;
  v1[7].finish_pass = nullptr;
  v1[6].encode_mcu = nullptr;
  v1[5].encode_mcu = nullptr;
  v1[4].start_pass = nullptr;
  v1[8].start_pass = nullptr;
  v1[6].finish_pass = nullptr;
  v1[5].finish_pass = nullptr;
  v1[4].encode_mcu = nullptr;
  v1[8].encode_mcu = nullptr;
  v1[7].start_pass = nullptr;
  v1[6].start_pass = nullptr;
  v1[4].finish_pass = nullptr;
  v1[8].finish_pass = nullptr;
  v1[7].encode_mcu = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041F400
// Name: emit_bits_0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_bits_0(phuff_entropy_encoder *entropy@<esi>, unsigned int code, int size)
{
  int v3; // ebx
  int v4; // ebx
  unsigned int v5; // edi
  bool v6; // zf
  jpeg_destination_mgr *dest; // ebx
  int put_bits; // [esp+8h] [ebp-4h]
  jpeg_destination_mgr *codea; // [esp+14h] [ebp+8h]
  int sizea; // [esp+18h] [ebp+Ch]

  v3 = entropy->put_bits;
  if ( size == 0 )
  {
    entropy->cinfo->err->msg_code = 40;
    entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
  }
  if ( entropy->gather_statistics == 0 )
  {
    v4 = size + v3;
    v5 = entropy->put_buffer | ((code & ((1 << size) - 1)) << (24 - v4));
    if ( v4 >= 8 )
    {
      sizea = (unsigned int)v4 >> 3;
      put_bits = v4 - 8 * ((unsigned int)v4 >> 3);
      do
      {
        *entropy->next_output_byte++ = BYTE2(v5);
        v6 = entropy->free_in_buffer-- == 1;
        if ( v6 )
        {
          codea = entropy->cinfo->dest;
          if ( codea->empty_output_buffer(a1: entropy->cinfo) == 0 )
          {
            entropy->cinfo->err->msg_code = 24;
            entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
          }
          entropy->next_output_byte = codea->next_output_byte;
          entropy->free_in_buffer = codea->free_in_buffer;
        }
        if ( BYTE2(v5) == 255 )
        {
          *entropy->next_output_byte++ = 0;
          v6 = entropy->free_in_buffer-- == 1;
          if ( v6 )
          {
            dest = entropy->cinfo->dest;
            if ( dest->empty_output_buffer(a1: entropy->cinfo) == 0 )
            {
              entropy->cinfo->err->msg_code = 24;
              entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
            }
            entropy->next_output_byte = dest->next_output_byte;
            entropy->free_in_buffer = dest->free_in_buffer;
          }
        }
        v5 <<= 8;
        --sizea;
      }
      while ( sizea != 0 );
      v4 = put_bits;
    }
    entropy->put_buffer = v5;
    entropy->put_bits = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F720
// Name: emit_restart_0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_restart_0(phuff_entropy_encoder *entropy@<eax>, char restart_num)
{
  bool v3; // zf
  jpeg_destination_mgr *dest; // edi
  jpeg_destination_mgr *v5; // edi
  jpeg_compress_struct *cinfo; // ecx
  int v7; // eax
  int *last_dc_val; // ecx

  emit_eobrun(entropy);
  if ( entropy->gather_statistics == 0 )
  {
    emit_bits_0(entropy, code: 0x7Fu, size: 7);
    entropy->put_buffer = 0;
    entropy->put_bits = 0;
    *entropy->next_output_byte++ = -1;
    v3 = entropy->free_in_buffer-- == 1;
    if ( v3 )
    {
      dest = entropy->cinfo->dest;
      if ( dest->empty_output_buffer(a1: entropy->cinfo) == 0 )
      {
        entropy->cinfo->err->msg_code = 24;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
      entropy->next_output_byte = dest->next_output_byte;
      entropy->free_in_buffer = dest->free_in_buffer;
    }
    *entropy->next_output_byte++ = restart_num - 48;
    v3 = entropy->free_in_buffer-- == 1;
    if ( v3 )
    {
      v5 = entropy->cinfo->dest;
      if ( v5->empty_output_buffer(a1: entropy->cinfo) == 0 )
      {
        entropy->cinfo->err->msg_code = 24;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
      entropy->next_output_byte = v5->next_output_byte;
      entropy->free_in_buffer = v5->free_in_buffer;
    }
  }
  cinfo = entropy->cinfo;
  if ( cinfo->Ss != 0 )
  {
    entropy->EOBRUN = 0;
    entropy->BE = 0;
  }
  else
  {
    v7 = 0;
    if ( cinfo->comps_in_scan > 0 )
    {
      last_dc_val = entropy->last_dc_val;
      do
      {
        *last_dc_val = 0;
        ++v7;
        ++last_dc_val;
      }
      while ( v7 < entropy->cinfo->comps_in_scan );
    }
  }
}

} // namespace vxconsole_ps3
