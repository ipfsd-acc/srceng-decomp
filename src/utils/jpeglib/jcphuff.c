// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcphuff.c
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10254EE0
// Name: emit_buffered_bits
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_buffered_bits(phuff_entropy_encoder *entropy@<esi>, char *bufstart, unsigned int nbits)
{
  int v3; // eax
  int v4; // edi
  bool v5; // zf
  jpeg_destination_mgr *v6; // ebx
  int v7; // [esp+0h] [ebp-Ch]
  jpeg_destination_mgr *dest; // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  if ( entropy->gather_statistics == 0 && nbits != 0 )
  {
    do
    {
      if ( entropy->gather_statistics == 0 )
      {
        v3 = entropy->put_bits + 1;
        v4 = entropy->put_buffer | ((*bufstart & 1) << (24 - v3));
        if ( v3 >= 8 )
        {
          v9 = (unsigned int)v3 >> 3;
          v7 = v3 - 8 * ((unsigned int)v3 >> 3);
          do
          {
            *entropy->next_output_byte++ = BYTE2(v4);
            v5 = entropy->free_in_buffer-- == 1;
            if ( v5 )
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
            if ( BYTE2(v4) == 255 )
            {
              *entropy->next_output_byte++ = 0;
              v5 = entropy->free_in_buffer-- == 1;
              if ( v5 )
              {
                v6 = entropy->cinfo->dest;
                if ( v6->empty_output_buffer(a1: entropy->cinfo) == 0 )
                {
                  entropy->cinfo->err->msg_code = 24;
                  entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
                }
                entropy->next_output_byte = v6->next_output_byte;
                entropy->free_in_buffer = v6->free_in_buffer;
              }
            }
            v4 <<= 8;
            --v9;
          }
          while ( v9 != 0 );
          v3 = v7;
        }
        entropy->put_buffer = v4;
        entropy->put_bits = v3;
      }
      ++bufstart;
      --nbits;
    }
    while ( nbits != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10255020
// Name: emit_eobrun
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_eobrun(phuff_entropy_encoder *entropy@<eax>)
{
  signed int EOBRUN; // eax
  int v3; // edi
  int v4; // eax
  int ac_tbl_no; // ecx
  char *bit_buffer; // [esp-Ch] [ebp-10h]
  unsigned int BE; // [esp-8h] [ebp-Ch]

  EOBRUN = entropy->EOBRUN;
  if ( EOBRUN != 0 )
  {
    v3 = 0;
    v4 = EOBRUN >> 1;
    if ( v4 != 0 )
    {
      do
      {
        ++v3;
        v4 >>= 1;
      }
      while ( v4 != 0 );
      if ( v3 > 14 )
      {
        entropy->cinfo->err->msg_code = 40;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
    }
    ac_tbl_no = entropy->ac_tbl_no;
    if ( entropy->gather_statistics != 0 )
      ++entropy->count_ptrs[ac_tbl_no][16 * v3];
    else
      emit_bits_0(
        entropy,
        code: entropy->derived_tbls[ac_tbl_no]->ehufco[16 * v3],
        size: entropy->derived_tbls[ac_tbl_no]->ehufsi[16 * v3]);
    if ( v3 != 0 )
      emit_bits_0(entropy, code: entropy->EOBRUN, size: v3);
    BE = entropy->BE;
    bit_buffer = entropy->bit_buffer;
    entropy->EOBRUN = 0;
    emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BE);
    entropy->BE = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102551C0
// Name: encode_mcu_DC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_DC_first(jpeg_common_struct *cinfo, __int16 (**MCU_data)[64])
{
  phuff_entropy_encoder *client_data; // esi
  int err; // edi
  int v5; // eax
  int v6; // edi
  int dc_tbl_no; // eax
  unsigned int global_state; // ebx
  int v9; // eax
  jpeg_component_info *compptr; // [esp+Ch] [ebp-10h]
  char v12; // [esp+10h] [ebp-Ch]
  int *p_global_state; // [esp+14h] [ebp-8h]
  int blkn; // [esp+18h] [ebp-4h]
  unsigned int temp2; // [esp+24h] [ebp+8h]

  client_data = (phuff_entropy_encoder *)cinfo[14].client_data;
  err = (int)cinfo[13].err;
  client_data->next_output_byte = (unsigned __int8 *)cinfo[1].err->error_exit;
  client_data->free_in_buffer = (unsigned int)cinfo[1].err->emit_message;
  if ( cinfo[7].global_state != 0 && client_data->restarts_to_go == 0 )
    emit_restart_0(entropy: client_data, restart_num: client_data->next_restart_num);
  blkn = 0;
  if ( *(int *)&cinfo[10].is_decompressor > 0 )
  {
    v12 = err;
    p_global_state = &cinfo[10].global_state;
    do
    {
      compptr = *((jpeg_component_info **)&cinfo[9].is_decompressor + *p_global_state);
      v5 = ((*MCU_data[blkn])[0] >> v12) - client_data->last_dc_val[*p_global_state];
      client_data->last_dc_val[*p_global_state] = (*MCU_data[blkn])[0] >> v12;
      temp2 = v5;
      if ( v5 < 0 )
      {
        v5 = -v5;
        --temp2;
      }
      v6 = 0;
      if ( v5 != 0 )
      {
        do
        {
          ++v6;
          v5 >>= 1;
        }
        while ( v5 != 0 );
        if ( v6 > 11 )
        {
          cinfo->err->msg_code = 6;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      dc_tbl_no = compptr->dc_tbl_no;
      if ( client_data->gather_statistics != 0 )
        ++client_data->count_ptrs[dc_tbl_no][v6];
      else
        emit_bits_0(
          entropy: client_data,
          code: client_data->derived_tbls[dc_tbl_no]->ehufco[v6],
          size: client_data->derived_tbls[dc_tbl_no]->ehufsi[v6]);
      if ( v6 != 0 )
        emit_bits_0(entropy: client_data, code: temp2, size: v6);
      ++p_global_state;
      ++blkn;
    }
    while ( blkn < *(_DWORD *)&cinfo[10].is_decompressor );
  }
  cinfo[1].err->error_exit = (void (__cdecl *)(jpeg_common_struct *))client_data->next_output_byte;
  cinfo[1].err->emit_message = (void (__cdecl *)(jpeg_common_struct *, int))client_data->free_in_buffer;
  global_state = cinfo[7].global_state;
  if ( global_state != 0 )
  {
    if ( client_data->restarts_to_go == 0 )
    {
      v9 = ((unsigned __int8)client_data->next_restart_num + 1) & 7;
      client_data->restarts_to_go = global_state;
      client_data->next_restart_num = v9;
    }
    --client_data->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255320
// Name: encode_mcu_AC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_AC_first(jpeg_common_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_common_struct *v2; // ebx
  int err; // eax
  phuff_entropy_encoder *client_data; // esi
  int v5; // edi
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edi
  int v10; // edi
  unsigned int v11; // ebx
  int ac_tbl_no; // eax
  int v13; // edi
  int v14; // ebx
  int v15; // ecx
  int v16; // eax
  unsigned int global_state; // ebx
  int v18; // eax
  int Se; // [esp+Ch] [ebp-14h]
  __int16 *block; // [esp+10h] [ebp-10h]
  int k; // [esp+14h] [ebp-Ch]
  unsigned int temp2; // [esp+18h] [ebp-8h]
  char v24; // [esp+1Ch] [ebp-4h]
  int r; // [esp+2Ch] [ebp+Ch]

  v2 = cinfo;
  err = (int)cinfo[13].err;
  client_data = (phuff_entropy_encoder *)cinfo[14].client_data;
  v5 = *(_DWORD *)&cinfo[12].is_decompressor;
  client_data->next_output_byte = (unsigned __int8 *)cinfo[1].err->error_exit;
  v24 = err;
  client_data->free_in_buffer = (unsigned int)cinfo[1].err->emit_message;
  Se = v5;
  if ( cinfo[7].global_state != 0 && client_data->restarts_to_go == 0 )
    emit_restart_0(entropy: client_data, restart_num: client_data->next_restart_num);
  v6 = (int)cinfo[12].client_data;
  v7 = 0;
  block = (__int16 *)*MCU_data;
  r = 0;
  k = v6;
  if ( v6 <= v5 )
  {
    do
    {
      v8 = jpeg_natural_order[v6];
      v9 = block[v8];
      if ( block[v8] != 0 )
      {
        if ( v9 >= 0 )
        {
          v10 = v9 >> v24;
          temp2 = v10;
        }
        else
        {
          v10 = -v9 >> v24;
          temp2 = ~v10;
        }
        if ( v10 != 0 )
        {
          if ( client_data->EOBRUN != 0 )
          {
            emit_eobrun(entropy: client_data);
            v7 = r;
          }
          if ( v7 > 15 )
          {
            v11 = ((unsigned int)(v7 - 16) >> 4) + 1;
            r = -16 * v11 + v7;
            do
            {
              ac_tbl_no = client_data->ac_tbl_no;
              if ( client_data->gather_statistics != 0 )
                ++client_data->count_ptrs[ac_tbl_no][240];
              else
                emit_bits_0(
                  entropy: client_data,
                  code: client_data->derived_tbls[ac_tbl_no]->ehufco[240],
                  size: client_data->derived_tbls[ac_tbl_no]->ehufsi[240]);
              --v11;
            }
            while ( v11 != 0 );
          }
          v13 = v10 >> 1;
          v14 = 1;
          if ( v13 != 0 )
          {
            do
            {
              ++v14;
              v13 >>= 1;
            }
            while ( v13 != 0 );
            if ( v14 > 10 )
            {
              cinfo->err->msg_code = 6;
              cinfo->err->error_exit(a1: cinfo);
            }
          }
          v15 = client_data->ac_tbl_no;
          v16 = v14 + 16 * r;
          if ( client_data->gather_statistics != 0 )
            ++client_data->count_ptrs[v15][v16];
          else
            emit_bits_0(
              entropy: client_data,
              code: client_data->derived_tbls[v15]->ehufco[v16],
              size: client_data->derived_tbls[v15]->ehufsi[v16]);
          emit_bits_0(entropy: client_data, code: temp2, size: v14);
          v6 = k;
          v2 = cinfo;
          r = 0;
          v7 = 0;
        }
        else
        {
          r = ++v7;
        }
      }
      else
      {
        r = ++v7;
      }
      k = ++v6;
    }
    while ( v6 <= Se );
    if ( v7 > 0 && ++client_data->EOBRUN == 0x7FFF )
      emit_eobrun(entropy: client_data);
  }
  v2[1].err->error_exit = (void (__cdecl *)(jpeg_common_struct *))client_data->next_output_byte;
  v2[1].err->emit_message = (void (__cdecl *)(jpeg_common_struct *, int))client_data->free_in_buffer;
  global_state = v2[7].global_state;
  if ( global_state != 0 )
  {
    if ( client_data->restarts_to_go == 0 )
    {
      v18 = ((unsigned __int8)client_data->next_restart_num + 1) & 7;
      client_data->restarts_to_go = global_state;
      client_data->next_restart_num = v18;
    }
    --client_data->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255510
// Name: encode_mcu_DC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_DC_refine(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  int Al; // eax
  phuff_entropy_encoder *entropy; // esi
  int i; // ebx
  unsigned int restart_interval; // edi
  int v7; // edx
  char cinfoa; // [esp+10h] [ebp+8h]

  Al = cinfo->Al;
  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  entropy->next_output_byte = cinfo->dest->next_output_byte;
  cinfoa = Al;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  if ( cinfo->restart_interval != 0 && entropy->restarts_to_go == 0 )
    emit_restart_0(entropy, restart_num: entropy->next_restart_num);
  for ( i = 0; i < cinfo->blocks_in_MCU; ++i )
    emit_bits_0(entropy, code: (*MCU_data[i])[0] >> cinfoa, size: 1);
  cinfo->dest->next_output_byte = entropy->next_output_byte;
  cinfo->dest->free_in_buffer = entropy->free_in_buffer;
  restart_interval = cinfo->restart_interval;
  if ( restart_interval != 0 )
  {
    if ( entropy->restarts_to_go == 0 )
    {
      v7 = ((unsigned __int8)entropy->next_restart_num + 1) & 7;
      entropy->restarts_to_go = restart_interval;
      entropy->next_restart_num = v7;
    }
    --entropy->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102555C0
// Name: encode_mcu_AC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_AC_refine(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_compress_struct *v2; // edx
  jpeg_destination_mgr *dest; // ecx
  int v4; // ebx
  phuff_entropy_encoder *entropy; // esi
  bool v6; // zf
  int Ss; // eax
  int v8; // edi
  int v9; // edi
  int v10; // ecx
  char *bit_buffer; // ebx
  int v12; // edi
  int v13; // eax
  int ac_tbl_no; // eax
  int v15; // eax
  int v16; // edi
  unsigned int restart_interval; // edx
  int absvalues[64]; // [esp+Ch] [ebp-114h]
  __int16 (*block)[64]; // [esp+10Ch] [ebp-14h]
  int EOB; // [esp+110h] [ebp-10h]
  int Se; // [esp+114h] [ebp-Ch]
  int temp; // [esp+118h] [ebp-8h]
  int k; // [esp+11Ch] [ebp-4h]
  unsigned int BR; // [esp+12Ch] [ebp+Ch]

  v2 = cinfo;
  dest = cinfo->dest;
  v4 = cinfo->Se;
  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  temp = cinfo->Al;
  entropy->next_output_byte = dest->next_output_byte;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  v6 = cinfo->restart_interval == 0;
  Se = v4;
  if ( !v6 && entropy->restarts_to_go == 0 )
  {
    emit_restart_0(entropy, restart_num: entropy->next_restart_num);
    v2 = cinfo;
  }
  Ss = v2->Ss;
  block = *MCU_data;
  for ( EOB = 0; Ss <= v4; ++Ss )
  {
    v8 = (*block)[jpeg_natural_order[Ss]];
    if ( v8 < 0 )
      v8 = -v8;
    v9 = v8 >> temp;
    absvalues[Ss] = v9;
    if ( v9 == 1 )
      EOB = Ss;
  }
  v10 = v2->Ss;
  bit_buffer = &entropy->bit_buffer[entropy->BE];
  v12 = 0;
  BR = 0;
  k = v10;
  if ( v10 <= Se )
  {
    do
    {
      v13 = absvalues[v10];
      temp = v13;
      if ( v13 != 0 )
      {
        for ( ; v12 > 15; BR = 0 )
        {
          if ( v10 > EOB )
            break;
          emit_eobrun(entropy);
          ac_tbl_no = entropy->ac_tbl_no;
          if ( entropy->gather_statistics != 0 )
            ++entropy->count_ptrs[ac_tbl_no][240];
          else
            emit_bits_0(
              entropy,
              code: entropy->derived_tbls[ac_tbl_no]->ehufco[240],
              size: entropy->derived_tbls[ac_tbl_no]->ehufsi[240]);
          v12 -= 16;
          emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BR);
          bit_buffer = entropy->bit_buffer;
          v13 = temp;
          v10 = k;
        }
        if ( v13 <= 1 )
        {
          emit_eobrun(entropy);
          v15 = entropy->ac_tbl_no;
          v16 = 16 * v12;
          if ( entropy->gather_statistics != 0 )
            ++entropy->count_ptrs[v15][v16 + 1];
          else
            emit_bits_0(
              entropy,
              code: entropy->derived_tbls[v15]->ehufco[v16 + 1],
              size: entropy->derived_tbls[v15]->ehufsi[v16 + 1]);
          v12 = 0;
          emit_bits_0(entropy, code: (*block)[jpeg_natural_order[k]] >= 0, size: 1);
          emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BR);
          bit_buffer = entropy->bit_buffer;
          v10 = k;
          BR = 0;
        }
        else
        {
          bit_buffer[BR++] = v13 & 1;
        }
        v2 = cinfo;
      }
      else
      {
        ++v12;
      }
      k = ++v10;
    }
    while ( v10 <= Se );
    if ( v12 > 0 || BR != 0 )
    {
      entropy->BE += BR;
      if ( ++entropy->EOBRUN == 0x7FFF || entropy->BE > 0x3A9 )
      {
        emit_eobrun(entropy);
        v2 = cinfo;
      }
    }
  }
  v2->dest->next_output_byte = entropy->next_output_byte;
  v2->dest->free_in_buffer = entropy->free_in_buffer;
  restart_interval = v2->restart_interval;
  if ( restart_interval != 0 )
  {
    if ( entropy->restarts_to_go == 0 )
    {
      entropy->restarts_to_go = restart_interval;
      entropy->next_restart_num = ((unsigned __int8)entropy->next_restart_num + 1) & 7;
    }
    --entropy->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255800
// Name: finish_pass_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_phuff(jpeg_compress_struct *cinfo)
{
  phuff_entropy_encoder *entropy; // esi
  unsigned __int8 *next_output_byte; // edx

  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  entropy->next_output_byte = cinfo->dest->next_output_byte;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  emit_eobrun(entropy);
  emit_bits_0(entropy, code: 0x7Fu, size: 7);
  next_output_byte = entropy->next_output_byte;
  entropy->put_buffer = 0;
  entropy->put_bits = 0;
  cinfo->dest->next_output_byte = next_output_byte;
  cinfo->dest->free_in_buffer = entropy->free_in_buffer;
}

//------------------------------------------------------------------------------
// Address: 0x10255850
// Name: finish_pass_gather_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_gather_phuff(jpeg_common_struct *cinfo)
{
  bool v2; // zf
  bool v3; // cl
  jpeg_component_info *v4; // eax
  int dc_tbl_no; // ebx
  JHUFF_TBL **v6; // edi
  phuff_entropy_encoder *entropy; // [esp+8h] [ebp-10h]
  unsigned __int8 did[4]; // [esp+Ch] [ebp-Ch]
  int ci; // [esp+10h] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+14h] [ebp-4h]
  bool is_DC_band_3; // [esp+23h] [ebp+Bh]

  entropy = (phuff_entropy_encoder *)cinfo[14].client_data;
  emit_eobrun(entropy);
  v2 = cinfo[12].client_data == nullptr;
  *(_DWORD *)did = 0;
  v3 = v2;
  is_DC_band_3 = v2;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    while ( 1 )
    {
      v4 = *p_is_decompressor;
      if ( !v3 )
        break;
      if ( cinfo[12].global_state == 0 )
      {
        dc_tbl_no = v4->dc_tbl_no;
        goto LABEL_7;
      }
LABEL_13:
      ++p_is_decompressor;
      if ( ++ci >= (int)cinfo[9].client_data )
        return;
    }
    dc_tbl_no = v4->ac_tbl_no;
LABEL_7:
    if ( did[dc_tbl_no] == 0 )
    {
      v6 = (JHUFF_TBL **)(&cinfo[3].is_decompressor + 4 * dc_tbl_no);
      if ( !v3 )
        v6 = (JHUFF_TBL **)(&cinfo[4].progress + dc_tbl_no);
      if ( *v6 == nullptr )
        *v6 = jpeg_alloc_huff_table(cinfo);
      jpeg_gen_optimal_table(cinfo, htbl: *v6, freq: entropy->count_ptrs[dc_tbl_no]);
      v3 = is_DC_band_3;
      did[dc_tbl_no] = 1;
    }
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10255910
// Name: start_pass_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_phuff(jpeg_common_struct *cinfo, unsigned __int8 gather_statistics)
{
  jpeg_entropy_encoder *client_data; // ebx
  jpeg_component_info *v4; // eax
  unsigned int dc_tbl_no; // edi
  unsigned int global_state; // edx
  int ci; // [esp+Ch] [ebp-Ch]
  unsigned __int8 is_DC_band; // [esp+10h] [ebp-8h]
  jpeg_entropy_encoder *v9; // [esp+14h] [ebp-4h]
  jpeg_component_info **cinfoa; // [esp+20h] [ebp+8h]

  client_data = (jpeg_entropy_encoder *)cinfo[14].client_data;
  LOBYTE(client_data[1].start_pass) = gather_statistics;
  client_data[2].finish_pass = (void (__cdecl *)(jpeg_compress_struct *))cinfo;
  is_DC_band = cinfo[12].client_data == nullptr;
  if ( cinfo[12].global_state != 0 )
  {
    if ( cinfo[12].client_data != nullptr )
    {
      client_data->encode_mcu = encode_mcu_AC_refine;
      if ( client_data[5].encode_mcu == nullptr )
        client_data[5].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1000);
    }
    else
    {
      client_data->encode_mcu = encode_mcu_DC_refine;
    }
  }
  else if ( cinfo[12].client_data != nullptr )
  {
    client_data->encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))encode_mcu_AC_first;
  }
  else
  {
    client_data->encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))encode_mcu_DC_first;
  }
  if ( gather_statistics != 0 )
    client_data->finish_pass = (void (__cdecl *)(jpeg_compress_struct *))finish_pass_gather_phuff;
  else
    client_data->finish_pass = finish_pass_phuff;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    v9 = client_data + 3;
    cinfoa = (jpeg_component_info **)&cinfo[9].is_decompressor;
    while ( 1 )
    {
      v4 = *cinfoa;
      v9->start_pass = nullptr;
      if ( is_DC_band == 0 )
        break;
      if ( cinfo[12].global_state == 0 )
      {
        dc_tbl_no = v4->dc_tbl_no;
        goto LABEL_18;
      }
LABEL_25:
      ++cinfoa;
      v9 = (jpeg_entropy_encoder *)((char *)v9 + 4);
      if ( ++ci >= (int)cinfo[9].client_data )
        goto LABEL_26;
    }
    dc_tbl_no = v4->ac_tbl_no;
    client_data[4].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))dc_tbl_no;
LABEL_18:
    if ( gather_statistics != 0 )
    {
      if ( dc_tbl_no >= 4 )
      {
        cinfo->err->msg_code = 50;
        cinfo->err->msg_parm.i[0] = dc_tbl_no;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *((_DWORD *)&client_data[7].finish_pass + dc_tbl_no) == 0 )
        *((_DWORD *)&client_data[7].finish_pass + dc_tbl_no) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
      memset(dst: *((unsigned __int8 **)&client_data[7].finish_pass + dc_tbl_no), value: 0, count: 0x404u);
    }
    else
    {
      jpeg_make_c_derived_tbl(
        cinfo,
        isDC: is_DC_band,
        tblno: dc_tbl_no,
        pdtbl: (c_derived_tbl **)&client_data[6].encode_mcu + dc_tbl_no);
    }
    goto LABEL_25;
  }
LABEL_26:
  client_data[4].finish_pass = nullptr;
  client_data[5].start_pass = nullptr;
  client_data[2].start_pass = nullptr;
  client_data[2].encode_mcu = nullptr;
  global_state = cinfo[7].global_state;
  client_data[6].start_pass = nullptr;
  client_data[5].finish_pass = (void (__cdecl *)(jpeg_compress_struct *))global_state;
}

//------------------------------------------------------------------------------
// Address: 0x10255A90
// Name: _jinit_phuff_encoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_phuff_encoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_encoder *v1; // eax

  v1 = (jpeg_entropy_encoder *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 108);
  cinfo[14].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))start_pass_phuff;
  v1[6].encode_mcu = nullptr;
  v1[7].finish_pass = nullptr;
  v1[6].finish_pass = nullptr;
  v1[8].start_pass = nullptr;
  v1[7].start_pass = nullptr;
  v1[8].encode_mcu = nullptr;
  v1[7].encode_mcu = nullptr;
  v1[8].finish_pass = nullptr;
  v1[5].encode_mcu = nullptr;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10254F10
// Name: emit_buffered_bits
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_buffered_bits(phuff_entropy_encoder *entropy@<esi>, char *bufstart, unsigned int nbits)
{
  int v3; // eax
  int v4; // edi
  bool v5; // zf
  jpeg_destination_mgr *v6; // ebx
  int v7; // [esp+0h] [ebp-Ch]
  jpeg_destination_mgr *dest; // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  if ( entropy->gather_statistics == 0 && nbits != 0 )
  {
    do
    {
      if ( entropy->gather_statistics == 0 )
      {
        v3 = entropy->put_bits + 1;
        v4 = entropy->put_buffer | ((*bufstart & 1) << (24 - v3));
        if ( v3 >= 8 )
        {
          v9 = (unsigned int)v3 >> 3;
          v7 = v3 - 8 * ((unsigned int)v3 >> 3);
          do
          {
            *entropy->next_output_byte++ = BYTE2(v4);
            v5 = entropy->free_in_buffer-- == 1;
            if ( v5 )
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
            if ( BYTE2(v4) == 255 )
            {
              *entropy->next_output_byte++ = 0;
              v5 = entropy->free_in_buffer-- == 1;
              if ( v5 )
              {
                v6 = entropy->cinfo->dest;
                if ( v6->empty_output_buffer(a1: entropy->cinfo) == 0 )
                {
                  entropy->cinfo->err->msg_code = 24;
                  entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
                }
                entropy->next_output_byte = v6->next_output_byte;
                entropy->free_in_buffer = v6->free_in_buffer;
              }
            }
            v4 <<= 8;
            --v9;
          }
          while ( v9 != 0 );
          v3 = v7;
        }
        entropy->put_buffer = v4;
        entropy->put_bits = v3;
      }
      ++bufstart;
      --nbits;
    }
    while ( nbits != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10255050
// Name: emit_eobrun
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_eobrun(phuff_entropy_encoder *entropy@<eax>)
{
  signed int EOBRUN; // eax
  int v3; // edi
  int v4; // eax
  int ac_tbl_no; // ecx
  char *bit_buffer; // [esp-Ch] [ebp-10h]
  unsigned int BE; // [esp-8h] [ebp-Ch]

  EOBRUN = entropy->EOBRUN;
  if ( EOBRUN != 0 )
  {
    v3 = 0;
    v4 = EOBRUN >> 1;
    if ( v4 != 0 )
    {
      do
      {
        ++v3;
        v4 >>= 1;
      }
      while ( v4 != 0 );
      if ( v3 > 14 )
      {
        entropy->cinfo->err->msg_code = 40;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
    }
    ac_tbl_no = entropy->ac_tbl_no;
    if ( entropy->gather_statistics != 0 )
      ++entropy->count_ptrs[ac_tbl_no][16 * v3];
    else
      emit_bits_0(
        entropy,
        code: entropy->derived_tbls[ac_tbl_no]->ehufco[16 * v3],
        size: entropy->derived_tbls[ac_tbl_no]->ehufsi[16 * v3]);
    if ( v3 != 0 )
      emit_bits_0(entropy, code: entropy->EOBRUN, size: v3);
    BE = entropy->BE;
    bit_buffer = entropy->bit_buffer;
    entropy->EOBRUN = 0;
    emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BE);
    entropy->BE = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102551F0
// Name: encode_mcu_DC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_DC_first(jpeg_common_struct *cinfo, __int16 (**MCU_data)[64])
{
  phuff_entropy_encoder *client_data; // esi
  int err; // edi
  int v5; // eax
  int v6; // edi
  int dc_tbl_no; // eax
  unsigned int global_state; // ebx
  int v9; // eax
  jpeg_component_info *compptr; // [esp+Ch] [ebp-10h]
  char v12; // [esp+10h] [ebp-Ch]
  int *p_global_state; // [esp+14h] [ebp-8h]
  int blkn; // [esp+18h] [ebp-4h]
  unsigned int temp2; // [esp+24h] [ebp+8h]

  client_data = (phuff_entropy_encoder *)cinfo[14].client_data;
  err = (int)cinfo[13].err;
  client_data->next_output_byte = (unsigned __int8 *)cinfo[1].err->error_exit;
  client_data->free_in_buffer = (unsigned int)cinfo[1].err->emit_message;
  if ( cinfo[7].global_state != 0 && client_data->restarts_to_go == 0 )
    emit_restart_0(entropy: client_data, restart_num: client_data->next_restart_num);
  blkn = 0;
  if ( *(int *)&cinfo[10].is_decompressor > 0 )
  {
    v12 = err;
    p_global_state = &cinfo[10].global_state;
    do
    {
      compptr = *((jpeg_component_info **)&cinfo[9].is_decompressor + *p_global_state);
      v5 = ((*MCU_data[blkn])[0] >> v12) - client_data->last_dc_val[*p_global_state];
      client_data->last_dc_val[*p_global_state] = (*MCU_data[blkn])[0] >> v12;
      temp2 = v5;
      if ( v5 < 0 )
      {
        v5 = -v5;
        --temp2;
      }
      v6 = 0;
      if ( v5 != 0 )
      {
        do
        {
          ++v6;
          v5 >>= 1;
        }
        while ( v5 != 0 );
        if ( v6 > 11 )
        {
          cinfo->err->msg_code = 6;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      dc_tbl_no = compptr->dc_tbl_no;
      if ( client_data->gather_statistics != 0 )
        ++client_data->count_ptrs[dc_tbl_no][v6];
      else
        emit_bits_0(
          entropy: client_data,
          code: client_data->derived_tbls[dc_tbl_no]->ehufco[v6],
          size: client_data->derived_tbls[dc_tbl_no]->ehufsi[v6]);
      if ( v6 != 0 )
        emit_bits_0(entropy: client_data, code: temp2, size: v6);
      ++p_global_state;
      ++blkn;
    }
    while ( blkn < *(_DWORD *)&cinfo[10].is_decompressor );
  }
  cinfo[1].err->error_exit = (void (__cdecl *)(jpeg_common_struct *))client_data->next_output_byte;
  cinfo[1].err->emit_message = (void (__cdecl *)(jpeg_common_struct *, int))client_data->free_in_buffer;
  global_state = cinfo[7].global_state;
  if ( global_state != 0 )
  {
    if ( client_data->restarts_to_go == 0 )
    {
      v9 = ((unsigned __int8)client_data->next_restart_num + 1) & 7;
      client_data->restarts_to_go = global_state;
      client_data->next_restart_num = v9;
    }
    --client_data->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255350
// Name: encode_mcu_AC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_AC_first(jpeg_common_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_common_struct *v2; // ebx
  int err; // eax
  phuff_entropy_encoder *client_data; // esi
  int v5; // edi
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edi
  int v10; // edi
  unsigned int v11; // ebx
  int ac_tbl_no; // eax
  int v13; // edi
  int v14; // ebx
  int v15; // ecx
  int v16; // eax
  unsigned int global_state; // ebx
  int v18; // eax
  int Se; // [esp+Ch] [ebp-14h]
  __int16 *block; // [esp+10h] [ebp-10h]
  int k; // [esp+14h] [ebp-Ch]
  unsigned int temp2; // [esp+18h] [ebp-8h]
  char v24; // [esp+1Ch] [ebp-4h]
  int r; // [esp+2Ch] [ebp+Ch]

  v2 = cinfo;
  err = (int)cinfo[13].err;
  client_data = (phuff_entropy_encoder *)cinfo[14].client_data;
  v5 = *(_DWORD *)&cinfo[12].is_decompressor;
  client_data->next_output_byte = (unsigned __int8 *)cinfo[1].err->error_exit;
  v24 = err;
  client_data->free_in_buffer = (unsigned int)cinfo[1].err->emit_message;
  Se = v5;
  if ( cinfo[7].global_state != 0 && client_data->restarts_to_go == 0 )
    emit_restart_0(entropy: client_data, restart_num: client_data->next_restart_num);
  v6 = (int)cinfo[12].client_data;
  v7 = 0;
  block = (__int16 *)*MCU_data;
  r = 0;
  k = v6;
  if ( v6 <= v5 )
  {
    do
    {
      v8 = jpeg_natural_order[v6];
      v9 = block[v8];
      if ( block[v8] != 0 )
      {
        if ( v9 >= 0 )
        {
          v10 = v9 >> v24;
          temp2 = v10;
        }
        else
        {
          v10 = -v9 >> v24;
          temp2 = ~v10;
        }
        if ( v10 != 0 )
        {
          if ( client_data->EOBRUN != 0 )
          {
            emit_eobrun(entropy: client_data);
            v7 = r;
          }
          if ( v7 > 15 )
          {
            v11 = ((unsigned int)(v7 - 16) >> 4) + 1;
            r = -16 * v11 + v7;
            do
            {
              ac_tbl_no = client_data->ac_tbl_no;
              if ( client_data->gather_statistics != 0 )
                ++client_data->count_ptrs[ac_tbl_no][240];
              else
                emit_bits_0(
                  entropy: client_data,
                  code: client_data->derived_tbls[ac_tbl_no]->ehufco[240],
                  size: client_data->derived_tbls[ac_tbl_no]->ehufsi[240]);
              --v11;
            }
            while ( v11 != 0 );
          }
          v13 = v10 >> 1;
          v14 = 1;
          if ( v13 != 0 )
          {
            do
            {
              ++v14;
              v13 >>= 1;
            }
            while ( v13 != 0 );
            if ( v14 > 10 )
            {
              cinfo->err->msg_code = 6;
              cinfo->err->error_exit(a1: cinfo);
            }
          }
          v15 = client_data->ac_tbl_no;
          v16 = v14 + 16 * r;
          if ( client_data->gather_statistics != 0 )
            ++client_data->count_ptrs[v15][v16];
          else
            emit_bits_0(
              entropy: client_data,
              code: client_data->derived_tbls[v15]->ehufco[v16],
              size: client_data->derived_tbls[v15]->ehufsi[v16]);
          emit_bits_0(entropy: client_data, code: temp2, size: v14);
          v6 = k;
          v2 = cinfo;
          r = 0;
          v7 = 0;
        }
        else
        {
          r = ++v7;
        }
      }
      else
      {
        r = ++v7;
      }
      k = ++v6;
    }
    while ( v6 <= Se );
    if ( v7 > 0 && ++client_data->EOBRUN == 0x7FFF )
      emit_eobrun(entropy: client_data);
  }
  v2[1].err->error_exit = (void (__cdecl *)(jpeg_common_struct *))client_data->next_output_byte;
  v2[1].err->emit_message = (void (__cdecl *)(jpeg_common_struct *, int))client_data->free_in_buffer;
  global_state = v2[7].global_state;
  if ( global_state != 0 )
  {
    if ( client_data->restarts_to_go == 0 )
    {
      v18 = ((unsigned __int8)client_data->next_restart_num + 1) & 7;
      client_data->restarts_to_go = global_state;
      client_data->next_restart_num = v18;
    }
    --client_data->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255540
// Name: encode_mcu_DC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_DC_refine(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  int Al; // eax
  phuff_entropy_encoder *entropy; // esi
  int i; // ebx
  unsigned int restart_interval; // edi
  int v7; // edx
  char cinfoa; // [esp+10h] [ebp+8h]

  Al = cinfo->Al;
  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  entropy->next_output_byte = cinfo->dest->next_output_byte;
  cinfoa = Al;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  if ( cinfo->restart_interval != 0 && entropy->restarts_to_go == 0 )
    emit_restart_0(entropy, restart_num: entropy->next_restart_num);
  for ( i = 0; i < cinfo->blocks_in_MCU; ++i )
    emit_bits_0(entropy, code: (*MCU_data[i])[0] >> cinfoa, size: 1);
  cinfo->dest->next_output_byte = entropy->next_output_byte;
  cinfo->dest->free_in_buffer = entropy->free_in_buffer;
  restart_interval = cinfo->restart_interval;
  if ( restart_interval != 0 )
  {
    if ( entropy->restarts_to_go == 0 )
    {
      v7 = ((unsigned __int8)entropy->next_restart_num + 1) & 7;
      entropy->restarts_to_go = restart_interval;
      entropy->next_restart_num = v7;
    }
    --entropy->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102555F0
// Name: encode_mcu_AC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_AC_refine(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_compress_struct *v2; // edx
  jpeg_destination_mgr *dest; // ecx
  int v4; // ebx
  phuff_entropy_encoder *entropy; // esi
  bool v6; // zf
  int Ss; // eax
  int v8; // edi
  int v9; // edi
  int v10; // ecx
  char *bit_buffer; // ebx
  int v12; // edi
  int v13; // eax
  int ac_tbl_no; // eax
  int v15; // eax
  int v16; // edi
  unsigned int restart_interval; // edx
  int absvalues[64]; // [esp+Ch] [ebp-114h]
  __int16 (*block)[64]; // [esp+10Ch] [ebp-14h]
  int EOB; // [esp+110h] [ebp-10h]
  int Se; // [esp+114h] [ebp-Ch]
  int temp; // [esp+118h] [ebp-8h]
  int k; // [esp+11Ch] [ebp-4h]
  unsigned int BR; // [esp+12Ch] [ebp+Ch]

  v2 = cinfo;
  dest = cinfo->dest;
  v4 = cinfo->Se;
  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  temp = cinfo->Al;
  entropy->next_output_byte = dest->next_output_byte;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  v6 = cinfo->restart_interval == 0;
  Se = v4;
  if ( !v6 && entropy->restarts_to_go == 0 )
  {
    emit_restart_0(entropy, restart_num: entropy->next_restart_num);
    v2 = cinfo;
  }
  Ss = v2->Ss;
  block = *MCU_data;
  for ( EOB = 0; Ss <= v4; ++Ss )
  {
    v8 = (*block)[jpeg_natural_order[Ss]];
    if ( v8 < 0 )
      v8 = -v8;
    v9 = v8 >> temp;
    absvalues[Ss] = v9;
    if ( v9 == 1 )
      EOB = Ss;
  }
  v10 = v2->Ss;
  bit_buffer = &entropy->bit_buffer[entropy->BE];
  v12 = 0;
  BR = 0;
  k = v10;
  if ( v10 <= Se )
  {
    do
    {
      v13 = absvalues[v10];
      temp = v13;
      if ( v13 != 0 )
      {
        for ( ; v12 > 15; BR = 0 )
        {
          if ( v10 > EOB )
            break;
          emit_eobrun(entropy);
          ac_tbl_no = entropy->ac_tbl_no;
          if ( entropy->gather_statistics != 0 )
            ++entropy->count_ptrs[ac_tbl_no][240];
          else
            emit_bits_0(
              entropy,
              code: entropy->derived_tbls[ac_tbl_no]->ehufco[240],
              size: entropy->derived_tbls[ac_tbl_no]->ehufsi[240]);
          v12 -= 16;
          emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BR);
          bit_buffer = entropy->bit_buffer;
          v13 = temp;
          v10 = k;
        }
        if ( v13 <= 1 )
        {
          emit_eobrun(entropy);
          v15 = entropy->ac_tbl_no;
          v16 = 16 * v12;
          if ( entropy->gather_statistics != 0 )
            ++entropy->count_ptrs[v15][v16 + 1];
          else
            emit_bits_0(
              entropy,
              code: entropy->derived_tbls[v15]->ehufco[v16 + 1],
              size: entropy->derived_tbls[v15]->ehufsi[v16 + 1]);
          v12 = 0;
          emit_bits_0(entropy, code: (*block)[jpeg_natural_order[k]] >= 0, size: 1);
          emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BR);
          bit_buffer = entropy->bit_buffer;
          v10 = k;
          BR = 0;
        }
        else
        {
          bit_buffer[BR++] = v13 & 1;
        }
        v2 = cinfo;
      }
      else
      {
        ++v12;
      }
      k = ++v10;
    }
    while ( v10 <= Se );
    if ( v12 > 0 || BR != 0 )
    {
      entropy->BE += BR;
      if ( ++entropy->EOBRUN == 0x7FFF || entropy->BE > 0x3A9 )
      {
        emit_eobrun(entropy);
        v2 = cinfo;
      }
    }
  }
  v2->dest->next_output_byte = entropy->next_output_byte;
  v2->dest->free_in_buffer = entropy->free_in_buffer;
  restart_interval = v2->restart_interval;
  if ( restart_interval != 0 )
  {
    if ( entropy->restarts_to_go == 0 )
    {
      entropy->restarts_to_go = restart_interval;
      entropy->next_restart_num = ((unsigned __int8)entropy->next_restart_num + 1) & 7;
    }
    --entropy->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255830
// Name: finish_pass_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_phuff(jpeg_compress_struct *cinfo)
{
  phuff_entropy_encoder *entropy; // esi
  unsigned __int8 *next_output_byte; // edx

  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  entropy->next_output_byte = cinfo->dest->next_output_byte;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  emit_eobrun(entropy);
  emit_bits_0(entropy, code: 0x7Fu, size: 7);
  next_output_byte = entropy->next_output_byte;
  entropy->put_buffer = 0;
  entropy->put_bits = 0;
  cinfo->dest->next_output_byte = next_output_byte;
  cinfo->dest->free_in_buffer = entropy->free_in_buffer;
}

//------------------------------------------------------------------------------
// Address: 0x10255880
// Name: finish_pass_gather_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_gather_phuff(jpeg_common_struct *cinfo)
{
  bool v2; // zf
  bool v3; // cl
  jpeg_component_info *v4; // eax
  int dc_tbl_no; // ebx
  JHUFF_TBL **v6; // edi
  phuff_entropy_encoder *entropy; // [esp+8h] [ebp-10h]
  unsigned __int8 did[4]; // [esp+Ch] [ebp-Ch]
  int ci; // [esp+10h] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+14h] [ebp-4h]
  bool is_DC_band_3; // [esp+23h] [ebp+Bh]

  entropy = (phuff_entropy_encoder *)cinfo[14].client_data;
  emit_eobrun(entropy);
  v2 = cinfo[12].client_data == nullptr;
  *(_DWORD *)did = 0;
  v3 = v2;
  is_DC_band_3 = v2;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    while ( 1 )
    {
      v4 = *p_is_decompressor;
      if ( !v3 )
        break;
      if ( cinfo[12].global_state == 0 )
      {
        dc_tbl_no = v4->dc_tbl_no;
        goto LABEL_7;
      }
LABEL_13:
      ++p_is_decompressor;
      if ( ++ci >= (int)cinfo[9].client_data )
        return;
    }
    dc_tbl_no = v4->ac_tbl_no;
LABEL_7:
    if ( did[dc_tbl_no] == 0 )
    {
      v6 = (JHUFF_TBL **)(&cinfo[3].is_decompressor + 4 * dc_tbl_no);
      if ( !v3 )
        v6 = (JHUFF_TBL **)(&cinfo[4].progress + dc_tbl_no);
      if ( *v6 == nullptr )
        *v6 = jpeg_alloc_huff_table(cinfo);
      jpeg_gen_optimal_table(cinfo, htbl: *v6, freq: entropy->count_ptrs[dc_tbl_no]);
      v3 = is_DC_band_3;
      did[dc_tbl_no] = 1;
    }
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10255940
// Name: start_pass_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_phuff(jpeg_common_struct *cinfo, unsigned __int8 gather_statistics)
{
  jpeg_entropy_encoder *client_data; // ebx
  jpeg_component_info *v4; // eax
  unsigned int dc_tbl_no; // edi
  unsigned int global_state; // edx
  int ci; // [esp+Ch] [ebp-Ch]
  unsigned __int8 is_DC_band; // [esp+10h] [ebp-8h]
  jpeg_entropy_encoder *v9; // [esp+14h] [ebp-4h]
  jpeg_component_info **cinfoa; // [esp+20h] [ebp+8h]

  client_data = (jpeg_entropy_encoder *)cinfo[14].client_data;
  LOBYTE(client_data[1].start_pass) = gather_statistics;
  client_data[2].finish_pass = (void (__cdecl *)(jpeg_compress_struct *))cinfo;
  is_DC_band = cinfo[12].client_data == nullptr;
  if ( cinfo[12].global_state != 0 )
  {
    if ( cinfo[12].client_data != nullptr )
    {
      client_data->encode_mcu = encode_mcu_AC_refine;
      if ( client_data[5].encode_mcu == nullptr )
        client_data[5].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1000);
    }
    else
    {
      client_data->encode_mcu = encode_mcu_DC_refine;
    }
  }
  else if ( cinfo[12].client_data != nullptr )
  {
    client_data->encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))encode_mcu_AC_first;
  }
  else
  {
    client_data->encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))encode_mcu_DC_first;
  }
  if ( gather_statistics != 0 )
    client_data->finish_pass = (void (__cdecl *)(jpeg_compress_struct *))finish_pass_gather_phuff;
  else
    client_data->finish_pass = finish_pass_phuff;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    v9 = client_data + 3;
    cinfoa = (jpeg_component_info **)&cinfo[9].is_decompressor;
    while ( 1 )
    {
      v4 = *cinfoa;
      v9->start_pass = nullptr;
      if ( is_DC_band == 0 )
        break;
      if ( cinfo[12].global_state == 0 )
      {
        dc_tbl_no = v4->dc_tbl_no;
        goto LABEL_18;
      }
LABEL_25:
      ++cinfoa;
      v9 = (jpeg_entropy_encoder *)((char *)v9 + 4);
      if ( ++ci >= (int)cinfo[9].client_data )
        goto LABEL_26;
    }
    dc_tbl_no = v4->ac_tbl_no;
    client_data[4].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))dc_tbl_no;
LABEL_18:
    if ( gather_statistics != 0 )
    {
      if ( dc_tbl_no >= 4 )
      {
        cinfo->err->msg_code = 50;
        cinfo->err->msg_parm.i[0] = dc_tbl_no;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *((_DWORD *)&client_data[7].finish_pass + dc_tbl_no) == 0 )
        *((_DWORD *)&client_data[7].finish_pass + dc_tbl_no) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
      memset(dst: *((unsigned __int8 **)&client_data[7].finish_pass + dc_tbl_no), value: 0, count: 0x404u);
    }
    else
    {
      jpeg_make_c_derived_tbl(
        cinfo,
        isDC: is_DC_band,
        tblno: dc_tbl_no,
        pdtbl: (c_derived_tbl **)&client_data[6].encode_mcu + dc_tbl_no);
    }
    goto LABEL_25;
  }
LABEL_26:
  client_data[4].finish_pass = nullptr;
  client_data[5].start_pass = nullptr;
  client_data[2].start_pass = nullptr;
  client_data[2].encode_mcu = nullptr;
  global_state = cinfo[7].global_state;
  client_data[6].start_pass = nullptr;
  client_data[5].finish_pass = (void (__cdecl *)(jpeg_compress_struct *))global_state;
}

//------------------------------------------------------------------------------
// Address: 0x10255AC0
// Name: _jinit_phuff_encoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_phuff_encoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_encoder *v1; // eax

  v1 = (jpeg_entropy_encoder *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 108);
  cinfo[14].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))start_pass_phuff;
  v1[6].encode_mcu = nullptr;
  v1[7].finish_pass = nullptr;
  v1[6].finish_pass = nullptr;
  v1[8].start_pass = nullptr;
  v1[7].start_pass = nullptr;
  v1[8].encode_mcu = nullptr;
  v1[7].encode_mcu = nullptr;
  v1[8].finish_pass = nullptr;
  v1[5].encode_mcu = nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x00409430
// Name: emit_buffered_bits
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_buffered_bits(phuff_entropy_encoder *entropy@<esi>, char *bufstart, unsigned int nbits)
{
  int v3; // eax
  int v4; // edi
  bool v5; // zf
  jpeg_destination_mgr *v6; // ebx
  int v7; // [esp+0h] [ebp-Ch]
  jpeg_destination_mgr *dest; // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  if ( entropy->gather_statistics == 0 && nbits != 0 )
  {
    do
    {
      if ( entropy->gather_statistics == 0 )
      {
        v3 = entropy->put_bits + 1;
        v4 = entropy->put_buffer | ((*bufstart & 1) << (24 - v3));
        if ( v3 >= 8 )
        {
          v9 = (unsigned int)v3 >> 3;
          v7 = v3 - 8 * ((unsigned int)v3 >> 3);
          do
          {
            *entropy->next_output_byte++ = BYTE2(v4);
            v5 = entropy->free_in_buffer-- == 1;
            if ( v5 )
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
            if ( BYTE2(v4) == 255 )
            {
              *entropy->next_output_byte++ = 0;
              v5 = entropy->free_in_buffer-- == 1;
              if ( v5 )
              {
                v6 = entropy->cinfo->dest;
                if ( v6->empty_output_buffer(a1: entropy->cinfo) == 0 )
                {
                  entropy->cinfo->err->msg_code = 24;
                  entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
                }
                entropy->next_output_byte = v6->next_output_byte;
                entropy->free_in_buffer = v6->free_in_buffer;
              }
            }
            v4 <<= 8;
            --v9;
          }
          while ( v9 != 0 );
          v3 = v7;
        }
        entropy->put_buffer = v4;
        entropy->put_bits = v3;
      }
      ++bufstart;
      --nbits;
    }
    while ( nbits != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409570
// Name: emit_eobrun
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_eobrun(phuff_entropy_encoder *entropy@<eax>)
{
  signed int EOBRUN; // eax
  int v3; // edi
  int v4; // eax
  int ac_tbl_no; // ecx
  char *bit_buffer; // [esp-Ch] [ebp-10h]
  unsigned int BE; // [esp-8h] [ebp-Ch]

  EOBRUN = entropy->EOBRUN;
  if ( EOBRUN != 0 )
  {
    v3 = 0;
    v4 = EOBRUN >> 1;
    if ( v4 != 0 )
    {
      do
      {
        ++v3;
        v4 >>= 1;
      }
      while ( v4 != 0 );
      if ( v3 > 14 )
      {
        entropy->cinfo->err->msg_code = 40;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
    }
    ac_tbl_no = entropy->ac_tbl_no;
    if ( entropy->gather_statistics != 0 )
      ++entropy->count_ptrs[ac_tbl_no][16 * v3];
    else
      emit_bits_0(
        entropy,
        code: entropy->derived_tbls[ac_tbl_no]->ehufco[16 * v3],
        size: entropy->derived_tbls[ac_tbl_no]->ehufsi[16 * v3]);
    if ( v3 != 0 )
      emit_bits_0(entropy, code: entropy->EOBRUN, size: v3);
    BE = entropy->BE;
    bit_buffer = entropy->bit_buffer;
    entropy->EOBRUN = 0;
    emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BE);
    entropy->BE = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409710
// Name: encode_mcu_DC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_DC_first(jpeg_common_struct *cinfo, __int16 (**MCU_data)[64])
{
  phuff_entropy_encoder *client_data; // esi
  int err; // edi
  int v5; // eax
  int v6; // edi
  int dc_tbl_no; // eax
  unsigned int global_state; // ebx
  int v9; // eax
  jpeg_component_info *compptr; // [esp+Ch] [ebp-10h]
  char v12; // [esp+10h] [ebp-Ch]
  int *p_global_state; // [esp+14h] [ebp-8h]
  int blkn; // [esp+18h] [ebp-4h]
  unsigned int temp2; // [esp+24h] [ebp+8h]

  client_data = (phuff_entropy_encoder *)cinfo[14].client_data;
  err = (int)cinfo[13].err;
  client_data->next_output_byte = (unsigned __int8 *)cinfo[1].err->error_exit;
  client_data->free_in_buffer = (unsigned int)cinfo[1].err->emit_message;
  if ( cinfo[7].global_state != 0 && client_data->restarts_to_go == 0 )
    emit_restart_0(entropy: client_data, restart_num: client_data->next_restart_num);
  blkn = 0;
  if ( *(int *)&cinfo[10].is_decompressor > 0 )
  {
    v12 = err;
    p_global_state = &cinfo[10].global_state;
    do
    {
      compptr = *((jpeg_component_info **)&cinfo[9].is_decompressor + *p_global_state);
      v5 = ((*MCU_data[blkn])[0] >> v12) - client_data->last_dc_val[*p_global_state];
      client_data->last_dc_val[*p_global_state] = (*MCU_data[blkn])[0] >> v12;
      temp2 = v5;
      if ( v5 < 0 )
      {
        v5 = -v5;
        --temp2;
      }
      v6 = 0;
      if ( v5 != 0 )
      {
        do
        {
          ++v6;
          v5 >>= 1;
        }
        while ( v5 != 0 );
        if ( v6 > 11 )
        {
          cinfo->err->msg_code = 6;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      dc_tbl_no = compptr->dc_tbl_no;
      if ( client_data->gather_statistics != 0 )
        ++client_data->count_ptrs[dc_tbl_no][v6];
      else
        emit_bits_0(
          entropy: client_data,
          code: client_data->derived_tbls[dc_tbl_no]->ehufco[v6],
          size: client_data->derived_tbls[dc_tbl_no]->ehufsi[v6]);
      if ( v6 != 0 )
        emit_bits_0(entropy: client_data, code: temp2, size: v6);
      ++p_global_state;
      ++blkn;
    }
    while ( blkn < *(_DWORD *)&cinfo[10].is_decompressor );
  }
  cinfo[1].err->error_exit = (void (__cdecl *)(jpeg_common_struct *))client_data->next_output_byte;
  cinfo[1].err->emit_message = (void (__cdecl *)(jpeg_common_struct *, int))client_data->free_in_buffer;
  global_state = cinfo[7].global_state;
  if ( global_state != 0 )
  {
    if ( client_data->restarts_to_go == 0 )
    {
      v9 = ((unsigned __int8)client_data->next_restart_num + 1) & 7;
      client_data->restarts_to_go = global_state;
      client_data->next_restart_num = v9;
    }
    --client_data->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409870
// Name: encode_mcu_AC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_AC_first(jpeg_common_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_common_struct *v2; // ebx
  int err; // eax
  phuff_entropy_encoder *client_data; // esi
  int v5; // edi
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edi
  int v10; // edi
  unsigned int v11; // ebx
  int ac_tbl_no; // eax
  int v13; // edi
  int v14; // ebx
  int v15; // ecx
  int v16; // eax
  unsigned int global_state; // ebx
  int v18; // eax
  int Se; // [esp+Ch] [ebp-14h]
  __int16 *block; // [esp+10h] [ebp-10h]
  int k; // [esp+14h] [ebp-Ch]
  unsigned int temp2; // [esp+18h] [ebp-8h]
  char v24; // [esp+1Ch] [ebp-4h]
  int r; // [esp+2Ch] [ebp+Ch]

  v2 = cinfo;
  err = (int)cinfo[13].err;
  client_data = (phuff_entropy_encoder *)cinfo[14].client_data;
  v5 = *(_DWORD *)&cinfo[12].is_decompressor;
  client_data->next_output_byte = (unsigned __int8 *)cinfo[1].err->error_exit;
  v24 = err;
  client_data->free_in_buffer = (unsigned int)cinfo[1].err->emit_message;
  Se = v5;
  if ( cinfo[7].global_state != 0 && client_data->restarts_to_go == 0 )
    emit_restart_0(entropy: client_data, restart_num: client_data->next_restart_num);
  v6 = (int)cinfo[12].client_data;
  v7 = 0;
  block = (__int16 *)*MCU_data;
  r = 0;
  k = v6;
  if ( v6 <= v5 )
  {
    do
    {
      v8 = jpeg_natural_order[v6];
      v9 = block[v8];
      if ( block[v8] != 0 )
      {
        if ( v9 >= 0 )
        {
          v10 = v9 >> v24;
          temp2 = v10;
        }
        else
        {
          v10 = -v9 >> v24;
          temp2 = ~v10;
        }
        if ( v10 != 0 )
        {
          if ( client_data->EOBRUN != 0 )
          {
            emit_eobrun(entropy: client_data);
            v7 = r;
          }
          if ( v7 > 15 )
          {
            v11 = ((unsigned int)(v7 - 16) >> 4) + 1;
            r = -16 * v11 + v7;
            do
            {
              ac_tbl_no = client_data->ac_tbl_no;
              if ( client_data->gather_statistics != 0 )
                ++client_data->count_ptrs[ac_tbl_no][240];
              else
                emit_bits_0(
                  entropy: client_data,
                  code: client_data->derived_tbls[ac_tbl_no]->ehufco[240],
                  size: client_data->derived_tbls[ac_tbl_no]->ehufsi[240]);
              --v11;
            }
            while ( v11 != 0 );
          }
          v13 = v10 >> 1;
          v14 = 1;
          if ( v13 != 0 )
          {
            do
            {
              ++v14;
              v13 >>= 1;
            }
            while ( v13 != 0 );
            if ( v14 > 10 )
            {
              cinfo->err->msg_code = 6;
              cinfo->err->error_exit(a1: cinfo);
            }
          }
          v15 = client_data->ac_tbl_no;
          v16 = v14 + 16 * r;
          if ( client_data->gather_statistics != 0 )
            ++client_data->count_ptrs[v15][v16];
          else
            emit_bits_0(
              entropy: client_data,
              code: client_data->derived_tbls[v15]->ehufco[v16],
              size: client_data->derived_tbls[v15]->ehufsi[v16]);
          emit_bits_0(entropy: client_data, code: temp2, size: v14);
          v6 = k;
          v2 = cinfo;
          r = 0;
          v7 = 0;
        }
        else
        {
          r = ++v7;
        }
      }
      else
      {
        r = ++v7;
      }
      k = ++v6;
    }
    while ( v6 <= Se );
    if ( v7 > 0 && ++client_data->EOBRUN == 0x7FFF )
      emit_eobrun(entropy: client_data);
  }
  v2[1].err->error_exit = (void (__cdecl *)(jpeg_common_struct *))client_data->next_output_byte;
  v2[1].err->emit_message = (void (__cdecl *)(jpeg_common_struct *, int))client_data->free_in_buffer;
  global_state = v2[7].global_state;
  if ( global_state != 0 )
  {
    if ( client_data->restarts_to_go == 0 )
    {
      v18 = ((unsigned __int8)client_data->next_restart_num + 1) & 7;
      client_data->restarts_to_go = global_state;
      client_data->next_restart_num = v18;
    }
    --client_data->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409A60
// Name: encode_mcu_DC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_DC_refine(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  int Al; // eax
  phuff_entropy_encoder *entropy; // esi
  int i; // ebx
  unsigned int restart_interval; // edi
  int v7; // edx
  char cinfoa; // [esp+10h] [ebp+8h]

  Al = cinfo->Al;
  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  entropy->next_output_byte = cinfo->dest->next_output_byte;
  cinfoa = Al;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  if ( cinfo->restart_interval != 0 && entropy->restarts_to_go == 0 )
    emit_restart_0(entropy, restart_num: entropy->next_restart_num);
  for ( i = 0; i < cinfo->blocks_in_MCU; ++i )
    emit_bits_0(entropy, code: (*MCU_data[i])[0] >> cinfoa, size: 1);
  cinfo->dest->next_output_byte = entropy->next_output_byte;
  cinfo->dest->free_in_buffer = entropy->free_in_buffer;
  restart_interval = cinfo->restart_interval;
  if ( restart_interval != 0 )
  {
    if ( entropy->restarts_to_go == 0 )
    {
      v7 = ((unsigned __int8)entropy->next_restart_num + 1) & 7;
      entropy->restarts_to_go = restart_interval;
      entropy->next_restart_num = v7;
    }
    --entropy->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409B10
// Name: encode_mcu_AC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_AC_refine(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_compress_struct *v2; // edx
  jpeg_destination_mgr *dest; // ecx
  int v4; // ebx
  phuff_entropy_encoder *entropy; // esi
  bool v6; // zf
  int Ss; // eax
  int v8; // edi
  int v9; // edi
  int v10; // ecx
  char *bit_buffer; // ebx
  int v12; // edi
  int v13; // eax
  int ac_tbl_no; // eax
  int v15; // eax
  int v16; // edi
  unsigned int restart_interval; // edx
  int absvalues[64]; // [esp+Ch] [ebp-114h]
  __int16 (*block)[64]; // [esp+10Ch] [ebp-14h]
  int EOB; // [esp+110h] [ebp-10h]
  int Se; // [esp+114h] [ebp-Ch]
  int temp; // [esp+118h] [ebp-8h]
  int k; // [esp+11Ch] [ebp-4h]
  unsigned int BR; // [esp+12Ch] [ebp+Ch]

  v2 = cinfo;
  dest = cinfo->dest;
  v4 = cinfo->Se;
  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  temp = cinfo->Al;
  entropy->next_output_byte = dest->next_output_byte;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  v6 = cinfo->restart_interval == 0;
  Se = v4;
  if ( !v6 && entropy->restarts_to_go == 0 )
  {
    emit_restart_0(entropy, restart_num: entropy->next_restart_num);
    v2 = cinfo;
  }
  Ss = v2->Ss;
  block = *MCU_data;
  for ( EOB = 0; Ss <= v4; ++Ss )
  {
    v8 = (*block)[jpeg_natural_order[Ss]];
    if ( v8 < 0 )
      v8 = -v8;
    v9 = v8 >> temp;
    absvalues[Ss] = v9;
    if ( v9 == 1 )
      EOB = Ss;
  }
  v10 = v2->Ss;
  bit_buffer = &entropy->bit_buffer[entropy->BE];
  v12 = 0;
  BR = 0;
  k = v10;
  if ( v10 <= Se )
  {
    do
    {
      v13 = absvalues[v10];
      temp = v13;
      if ( v13 != 0 )
      {
        for ( ; v12 > 15; BR = 0 )
        {
          if ( v10 > EOB )
            break;
          emit_eobrun(entropy);
          ac_tbl_no = entropy->ac_tbl_no;
          if ( entropy->gather_statistics != 0 )
            ++entropy->count_ptrs[ac_tbl_no][240];
          else
            emit_bits_0(
              entropy,
              code: entropy->derived_tbls[ac_tbl_no]->ehufco[240],
              size: entropy->derived_tbls[ac_tbl_no]->ehufsi[240]);
          v12 -= 16;
          emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BR);
          bit_buffer = entropy->bit_buffer;
          v13 = temp;
          v10 = k;
        }
        if ( v13 <= 1 )
        {
          emit_eobrun(entropy);
          v15 = entropy->ac_tbl_no;
          v16 = 16 * v12;
          if ( entropy->gather_statistics != 0 )
            ++entropy->count_ptrs[v15][v16 + 1];
          else
            emit_bits_0(
              entropy,
              code: entropy->derived_tbls[v15]->ehufco[v16 + 1],
              size: entropy->derived_tbls[v15]->ehufsi[v16 + 1]);
          v12 = 0;
          emit_bits_0(entropy, code: (*block)[jpeg_natural_order[k]] >= 0, size: 1);
          emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BR);
          bit_buffer = entropy->bit_buffer;
          v10 = k;
          BR = 0;
        }
        else
        {
          bit_buffer[BR++] = v13 & 1;
        }
        v2 = cinfo;
      }
      else
      {
        ++v12;
      }
      k = ++v10;
    }
    while ( v10 <= Se );
    if ( v12 > 0 || BR != 0 )
    {
      entropy->BE += BR;
      if ( ++entropy->EOBRUN == 0x7FFF || entropy->BE > 0x3A9 )
      {
        emit_eobrun(entropy);
        v2 = cinfo;
      }
    }
  }
  v2->dest->next_output_byte = entropy->next_output_byte;
  v2->dest->free_in_buffer = entropy->free_in_buffer;
  restart_interval = v2->restart_interval;
  if ( restart_interval != 0 )
  {
    if ( entropy->restarts_to_go == 0 )
    {
      entropy->restarts_to_go = restart_interval;
      entropy->next_restart_num = ((unsigned __int8)entropy->next_restart_num + 1) & 7;
    }
    --entropy->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409D50
// Name: finish_pass_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_phuff(jpeg_compress_struct *cinfo)
{
  phuff_entropy_encoder *entropy; // esi
  unsigned __int8 *next_output_byte; // edx

  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  entropy->next_output_byte = cinfo->dest->next_output_byte;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  emit_eobrun(entropy);
  emit_bits_0(entropy, code: 0x7Fu, size: 7);
  next_output_byte = entropy->next_output_byte;
  entropy->put_buffer = 0;
  entropy->put_bits = 0;
  cinfo->dest->next_output_byte = next_output_byte;
  cinfo->dest->free_in_buffer = entropy->free_in_buffer;
}

//------------------------------------------------------------------------------
// Address: 0x00409DA0
// Name: finish_pass_gather_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_gather_phuff(jpeg_common_struct *cinfo)
{
  bool v2; // zf
  bool v3; // cl
  jpeg_component_info *v4; // eax
  int dc_tbl_no; // ebx
  JHUFF_TBL **v6; // edi
  phuff_entropy_encoder *entropy; // [esp+8h] [ebp-10h]
  unsigned __int8 did[4]; // [esp+Ch] [ebp-Ch]
  int ci; // [esp+10h] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+14h] [ebp-4h]
  bool is_DC_band_3; // [esp+23h] [ebp+Bh]

  entropy = (phuff_entropy_encoder *)cinfo[14].client_data;
  emit_eobrun(entropy);
  v2 = cinfo[12].client_data == nullptr;
  *(_DWORD *)did = 0;
  v3 = v2;
  is_DC_band_3 = v2;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    while ( 1 )
    {
      v4 = *p_is_decompressor;
      if ( !v3 )
        break;
      if ( cinfo[12].global_state == 0 )
      {
        dc_tbl_no = v4->dc_tbl_no;
        goto LABEL_7;
      }
LABEL_13:
      ++p_is_decompressor;
      if ( ++ci >= (int)cinfo[9].client_data )
        return;
    }
    dc_tbl_no = v4->ac_tbl_no;
LABEL_7:
    if ( did[dc_tbl_no] == 0 )
    {
      v6 = (JHUFF_TBL **)(&cinfo[3].is_decompressor + 4 * dc_tbl_no);
      if ( !v3 )
        v6 = (JHUFF_TBL **)(&cinfo[4].progress + dc_tbl_no);
      if ( *v6 == nullptr )
        *v6 = jpeg_alloc_huff_table(cinfo);
      jpeg_gen_optimal_table(cinfo, htbl: *v6, freq: entropy->count_ptrs[dc_tbl_no]);
      v3 = is_DC_band_3;
      did[dc_tbl_no] = 1;
    }
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409E60
// Name: start_pass_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_phuff(jpeg_common_struct *cinfo, unsigned __int8 gather_statistics)
{
  jpeg_entropy_encoder *client_data; // ebx
  jpeg_component_info *v4; // eax
  unsigned int dc_tbl_no; // edi
  unsigned int global_state; // edx
  int ci; // [esp+Ch] [ebp-Ch]
  unsigned __int8 is_DC_band; // [esp+10h] [ebp-8h]
  jpeg_entropy_encoder *v9; // [esp+14h] [ebp-4h]
  jpeg_component_info **cinfoa; // [esp+20h] [ebp+8h]

  client_data = (jpeg_entropy_encoder *)cinfo[14].client_data;
  LOBYTE(client_data[1].start_pass) = gather_statistics;
  client_data[2].finish_pass = (void (__cdecl *)(jpeg_compress_struct *))cinfo;
  is_DC_band = cinfo[12].client_data == nullptr;
  if ( cinfo[12].global_state != 0 )
  {
    if ( cinfo[12].client_data != nullptr )
    {
      client_data->encode_mcu = encode_mcu_AC_refine;
      if ( client_data[5].encode_mcu == nullptr )
        client_data[5].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1000);
    }
    else
    {
      client_data->encode_mcu = encode_mcu_DC_refine;
    }
  }
  else if ( cinfo[12].client_data != nullptr )
  {
    client_data->encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))encode_mcu_AC_first;
  }
  else
  {
    client_data->encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))encode_mcu_DC_first;
  }
  if ( gather_statistics != 0 )
    client_data->finish_pass = (void (__cdecl *)(jpeg_compress_struct *))finish_pass_gather_phuff;
  else
    client_data->finish_pass = finish_pass_phuff;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    v9 = client_data + 3;
    cinfoa = (jpeg_component_info **)&cinfo[9].is_decompressor;
    while ( 1 )
    {
      v4 = *cinfoa;
      v9->start_pass = nullptr;
      if ( is_DC_band == 0 )
        break;
      if ( cinfo[12].global_state == 0 )
      {
        dc_tbl_no = v4->dc_tbl_no;
        goto LABEL_18;
      }
LABEL_25:
      ++cinfoa;
      v9 = (jpeg_entropy_encoder *)((char *)v9 + 4);
      if ( ++ci >= (int)cinfo[9].client_data )
        goto LABEL_26;
    }
    dc_tbl_no = v4->ac_tbl_no;
    client_data[4].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))dc_tbl_no;
LABEL_18:
    if ( gather_statistics != 0 )
    {
      if ( dc_tbl_no >= 4 )
      {
        cinfo->err->msg_code = 50;
        cinfo->err->msg_parm.i[0] = dc_tbl_no;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *((_DWORD *)&client_data[7].finish_pass + dc_tbl_no) == 0 )
        *((_DWORD *)&client_data[7].finish_pass + dc_tbl_no) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
      memset(dst: *((unsigned __int8 **)&client_data[7].finish_pass + dc_tbl_no), value: 0, count: 0x404u);
    }
    else
    {
      jpeg_make_c_derived_tbl(
        cinfo,
        isDC: is_DC_band,
        tblno: dc_tbl_no,
        pdtbl: (c_derived_tbl **)&client_data[6].encode_mcu + dc_tbl_no);
    }
    goto LABEL_25;
  }
LABEL_26:
  client_data[4].finish_pass = nullptr;
  client_data[5].start_pass = nullptr;
  client_data[2].start_pass = nullptr;
  client_data[2].encode_mcu = nullptr;
  global_state = cinfo[7].global_state;
  client_data[6].start_pass = nullptr;
  client_data[5].finish_pass = (void (__cdecl *)(jpeg_compress_struct *))global_state;
}

//------------------------------------------------------------------------------
// Address: 0x00409FE0
// Name: _jinit_phuff_encoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_phuff_encoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_encoder *v1; // eax

  v1 = (jpeg_entropy_encoder *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 108);
  cinfo[14].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))start_pass_phuff;
  v1[6].encode_mcu = nullptr;
  v1[7].finish_pass = nullptr;
  v1[6].finish_pass = nullptr;
  v1[8].start_pass = nullptr;
  v1[7].start_pass = nullptr;
  v1[8].encode_mcu = nullptr;
  v1[7].encode_mcu = nullptr;
  v1[8].finish_pass = nullptr;
  v1[5].encode_mcu = nullptr;
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00432740
// Name: emit_buffered_bits
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_buffered_bits(phuff_entropy_encoder *entropy@<esi>, char *bufstart, unsigned int nbits)
{
  int v3; // eax
  int v4; // edi
  bool v5; // zf
  jpeg_destination_mgr *v6; // ebx
  int v7; // [esp+0h] [ebp-Ch]
  jpeg_destination_mgr *dest; // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  if ( entropy->gather_statistics == 0 && nbits != 0 )
  {
    do
    {
      if ( entropy->gather_statistics == 0 )
      {
        v3 = entropy->put_bits + 1;
        v4 = entropy->put_buffer | ((*bufstart & 1) << (24 - v3));
        if ( v3 >= 8 )
        {
          v9 = (unsigned int)v3 >> 3;
          v7 = v3 - 8 * ((unsigned int)v3 >> 3);
          do
          {
            *entropy->next_output_byte++ = BYTE2(v4);
            v5 = entropy->free_in_buffer-- == 1;
            if ( v5 )
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
            if ( BYTE2(v4) == 255 )
            {
              *entropy->next_output_byte++ = 0;
              v5 = entropy->free_in_buffer-- == 1;
              if ( v5 )
              {
                v6 = entropy->cinfo->dest;
                if ( v6->empty_output_buffer(a1: entropy->cinfo) == 0 )
                {
                  entropy->cinfo->err->msg_code = 24;
                  entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
                }
                entropy->next_output_byte = v6->next_output_byte;
                entropy->free_in_buffer = v6->free_in_buffer;
              }
            }
            v4 <<= 8;
            --v9;
          }
          while ( v9 != 0 );
          v3 = v7;
        }
        entropy->put_buffer = v4;
        entropy->put_bits = v3;
      }
      ++bufstart;
      --nbits;
    }
    while ( nbits != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432880
// Name: emit_eobrun
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_eobrun(phuff_entropy_encoder *entropy@<eax>)
{
  signed int EOBRUN; // eax
  int v3; // edi
  int v4; // eax
  int ac_tbl_no; // ecx
  char *bit_buffer; // [esp-Ch] [ebp-10h]
  unsigned int BE; // [esp-8h] [ebp-Ch]

  EOBRUN = entropy->EOBRUN;
  if ( EOBRUN != 0 )
  {
    v3 = 0;
    v4 = EOBRUN >> 1;
    if ( v4 != 0 )
    {
      do
      {
        ++v3;
        v4 >>= 1;
      }
      while ( v4 != 0 );
      if ( v3 > 14 )
      {
        entropy->cinfo->err->msg_code = 40;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
    }
    ac_tbl_no = entropy->ac_tbl_no;
    if ( entropy->gather_statistics != 0 )
      ++entropy->count_ptrs[ac_tbl_no][16 * v3];
    else
      emit_bits_0(
        entropy,
        code: entropy->derived_tbls[ac_tbl_no]->ehufco[16 * v3],
        size: entropy->derived_tbls[ac_tbl_no]->ehufsi[16 * v3]);
    if ( v3 != 0 )
      emit_bits_0(entropy, code: entropy->EOBRUN, size: v3);
    BE = entropy->BE;
    bit_buffer = entropy->bit_buffer;
    entropy->EOBRUN = 0;
    emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BE);
    entropy->BE = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432A20
// Name: encode_mcu_DC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_DC_first(jpeg_common_struct *cinfo, __int16 (**MCU_data)[64])
{
  phuff_entropy_encoder *client_data; // esi
  int err; // edi
  int v5; // eax
  int v6; // edi
  int dc_tbl_no; // eax
  unsigned int global_state; // ebx
  int v9; // eax
  jpeg_component_info *compptr; // [esp+Ch] [ebp-10h]
  char v12; // [esp+10h] [ebp-Ch]
  int *p_global_state; // [esp+14h] [ebp-8h]
  int blkn; // [esp+18h] [ebp-4h]
  unsigned int temp2; // [esp+24h] [ebp+8h]

  client_data = (phuff_entropy_encoder *)cinfo[14].client_data;
  err = (int)cinfo[13].err;
  client_data->next_output_byte = (unsigned __int8 *)cinfo[1].err->error_exit;
  client_data->free_in_buffer = (unsigned int)cinfo[1].err->emit_message;
  if ( cinfo[7].global_state != 0 && client_data->restarts_to_go == 0 )
    emit_restart_0(entropy: client_data, restart_num: client_data->next_restart_num);
  blkn = 0;
  if ( *(int *)&cinfo[10].is_decompressor > 0 )
  {
    v12 = err;
    p_global_state = &cinfo[10].global_state;
    do
    {
      compptr = *((jpeg_component_info **)&cinfo[9].is_decompressor + *p_global_state);
      v5 = ((*MCU_data[blkn])[0] >> v12) - client_data->last_dc_val[*p_global_state];
      client_data->last_dc_val[*p_global_state] = (*MCU_data[blkn])[0] >> v12;
      temp2 = v5;
      if ( v5 < 0 )
      {
        v5 = -v5;
        --temp2;
      }
      v6 = 0;
      if ( v5 != 0 )
      {
        do
        {
          ++v6;
          v5 >>= 1;
        }
        while ( v5 != 0 );
        if ( v6 > 11 )
        {
          cinfo->err->msg_code = 6;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      dc_tbl_no = compptr->dc_tbl_no;
      if ( client_data->gather_statistics != 0 )
        ++client_data->count_ptrs[dc_tbl_no][v6];
      else
        emit_bits_0(
          entropy: client_data,
          code: client_data->derived_tbls[dc_tbl_no]->ehufco[v6],
          size: client_data->derived_tbls[dc_tbl_no]->ehufsi[v6]);
      if ( v6 != 0 )
        emit_bits_0(entropy: client_data, code: temp2, size: v6);
      ++p_global_state;
      ++blkn;
    }
    while ( blkn < *(_DWORD *)&cinfo[10].is_decompressor );
  }
  cinfo[1].err->error_exit = (void (__cdecl *)(jpeg_common_struct *))client_data->next_output_byte;
  cinfo[1].err->emit_message = (void (__cdecl *)(jpeg_common_struct *, int))client_data->free_in_buffer;
  global_state = cinfo[7].global_state;
  if ( global_state != 0 )
  {
    if ( client_data->restarts_to_go == 0 )
    {
      v9 = ((unsigned __int8)client_data->next_restart_num + 1) & 7;
      client_data->restarts_to_go = global_state;
      client_data->next_restart_num = v9;
    }
    --client_data->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00432B80
// Name: encode_mcu_AC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_AC_first(jpeg_common_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_common_struct *v2; // ebx
  int err; // eax
  phuff_entropy_encoder *client_data; // esi
  int v5; // edi
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edi
  int v10; // edi
  unsigned int v11; // ebx
  int ac_tbl_no; // eax
  int v13; // edi
  int v14; // ebx
  int v15; // ecx
  int v16; // eax
  unsigned int global_state; // ebx
  int v18; // eax
  int Se; // [esp+Ch] [ebp-14h]
  __int16 *block; // [esp+10h] [ebp-10h]
  int k; // [esp+14h] [ebp-Ch]
  unsigned int temp2; // [esp+18h] [ebp-8h]
  char v24; // [esp+1Ch] [ebp-4h]
  int r; // [esp+2Ch] [ebp+Ch]

  v2 = cinfo;
  err = (int)cinfo[13].err;
  client_data = (phuff_entropy_encoder *)cinfo[14].client_data;
  v5 = *(_DWORD *)&cinfo[12].is_decompressor;
  client_data->next_output_byte = (unsigned __int8 *)cinfo[1].err->error_exit;
  v24 = err;
  client_data->free_in_buffer = (unsigned int)cinfo[1].err->emit_message;
  Se = v5;
  if ( cinfo[7].global_state != 0 && client_data->restarts_to_go == 0 )
    emit_restart_0(entropy: client_data, restart_num: client_data->next_restart_num);
  v6 = (int)cinfo[12].client_data;
  v7 = 0;
  block = (__int16 *)*MCU_data;
  r = 0;
  k = v6;
  if ( v6 <= v5 )
  {
    do
    {
      v8 = jpeg_natural_order[v6];
      v9 = block[v8];
      if ( block[v8] != 0 )
      {
        if ( v9 >= 0 )
        {
          v10 = v9 >> v24;
          temp2 = v10;
        }
        else
        {
          v10 = -v9 >> v24;
          temp2 = ~v10;
        }
        if ( v10 != 0 )
        {
          if ( client_data->EOBRUN != 0 )
          {
            emit_eobrun(entropy: client_data);
            v7 = r;
          }
          if ( v7 > 15 )
          {
            v11 = ((unsigned int)(v7 - 16) >> 4) + 1;
            r = -16 * v11 + v7;
            do
            {
              ac_tbl_no = client_data->ac_tbl_no;
              if ( client_data->gather_statistics != 0 )
                ++client_data->count_ptrs[ac_tbl_no][240];
              else
                emit_bits_0(
                  entropy: client_data,
                  code: client_data->derived_tbls[ac_tbl_no]->ehufco[240],
                  size: client_data->derived_tbls[ac_tbl_no]->ehufsi[240]);
              --v11;
            }
            while ( v11 != 0 );
          }
          v13 = v10 >> 1;
          v14 = 1;
          if ( v13 != 0 )
          {
            do
            {
              ++v14;
              v13 >>= 1;
            }
            while ( v13 != 0 );
            if ( v14 > 10 )
            {
              cinfo->err->msg_code = 6;
              cinfo->err->error_exit(a1: cinfo);
            }
          }
          v15 = client_data->ac_tbl_no;
          v16 = v14 + 16 * r;
          if ( client_data->gather_statistics != 0 )
            ++client_data->count_ptrs[v15][v16];
          else
            emit_bits_0(
              entropy: client_data,
              code: client_data->derived_tbls[v15]->ehufco[v16],
              size: client_data->derived_tbls[v15]->ehufsi[v16]);
          emit_bits_0(entropy: client_data, code: temp2, size: v14);
          v6 = k;
          v2 = cinfo;
          r = 0;
          v7 = 0;
        }
        else
        {
          r = ++v7;
        }
      }
      else
      {
        r = ++v7;
      }
      k = ++v6;
    }
    while ( v6 <= Se );
    if ( v7 > 0 && ++client_data->EOBRUN == 0x7FFF )
      emit_eobrun(entropy: client_data);
  }
  v2[1].err->error_exit = (void (__cdecl *)(jpeg_common_struct *))client_data->next_output_byte;
  v2[1].err->emit_message = (void (__cdecl *)(jpeg_common_struct *, int))client_data->free_in_buffer;
  global_state = v2[7].global_state;
  if ( global_state != 0 )
  {
    if ( client_data->restarts_to_go == 0 )
    {
      v18 = ((unsigned __int8)client_data->next_restart_num + 1) & 7;
      client_data->restarts_to_go = global_state;
      client_data->next_restart_num = v18;
    }
    --client_data->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00432D70
// Name: encode_mcu_DC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_DC_refine(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  int Al; // eax
  phuff_entropy_encoder *entropy; // esi
  int i; // ebx
  unsigned int restart_interval; // edi
  int v7; // edx
  char cinfoa; // [esp+10h] [ebp+8h]

  Al = cinfo->Al;
  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  entropy->next_output_byte = cinfo->dest->next_output_byte;
  cinfoa = Al;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  if ( cinfo->restart_interval != 0 && entropy->restarts_to_go == 0 )
    emit_restart_0(entropy, restart_num: entropy->next_restart_num);
  for ( i = 0; i < cinfo->blocks_in_MCU; ++i )
    emit_bits_0(entropy, code: (*MCU_data[i])[0] >> cinfoa, size: 1);
  cinfo->dest->next_output_byte = entropy->next_output_byte;
  cinfo->dest->free_in_buffer = entropy->free_in_buffer;
  restart_interval = cinfo->restart_interval;
  if ( restart_interval != 0 )
  {
    if ( entropy->restarts_to_go == 0 )
    {
      v7 = ((unsigned __int8)entropy->next_restart_num + 1) & 7;
      entropy->restarts_to_go = restart_interval;
      entropy->next_restart_num = v7;
    }
    --entropy->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00432E20
// Name: encode_mcu_AC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_AC_refine(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_compress_struct *v2; // edx
  jpeg_destination_mgr *dest; // ecx
  int v4; // ebx
  phuff_entropy_encoder *entropy; // esi
  bool v6; // zf
  int Ss; // eax
  int v8; // edi
  int v9; // edi
  int v10; // ecx
  char *bit_buffer; // ebx
  int v12; // edi
  int v13; // eax
  int ac_tbl_no; // eax
  int v15; // eax
  int v16; // edi
  unsigned int restart_interval; // edx
  int absvalues[64]; // [esp+Ch] [ebp-114h]
  __int16 (*block)[64]; // [esp+10Ch] [ebp-14h]
  int EOB; // [esp+110h] [ebp-10h]
  int Se; // [esp+114h] [ebp-Ch]
  int temp; // [esp+118h] [ebp-8h]
  int k; // [esp+11Ch] [ebp-4h]
  unsigned int BR; // [esp+12Ch] [ebp+Ch]

  v2 = cinfo;
  dest = cinfo->dest;
  v4 = cinfo->Se;
  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  temp = cinfo->Al;
  entropy->next_output_byte = dest->next_output_byte;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  v6 = cinfo->restart_interval == 0;
  Se = v4;
  if ( !v6 && entropy->restarts_to_go == 0 )
  {
    emit_restart_0(entropy, restart_num: entropy->next_restart_num);
    v2 = cinfo;
  }
  Ss = v2->Ss;
  block = *MCU_data;
  for ( EOB = 0; Ss <= v4; ++Ss )
  {
    v8 = (*block)[jpeg_natural_order[Ss]];
    if ( v8 < 0 )
      v8 = -v8;
    v9 = v8 >> temp;
    absvalues[Ss] = v9;
    if ( v9 == 1 )
      EOB = Ss;
  }
  v10 = v2->Ss;
  bit_buffer = &entropy->bit_buffer[entropy->BE];
  v12 = 0;
  BR = 0;
  k = v10;
  if ( v10 <= Se )
  {
    do
    {
      v13 = absvalues[v10];
      temp = v13;
      if ( v13 != 0 )
      {
        for ( ; v12 > 15; BR = 0 )
        {
          if ( v10 > EOB )
            break;
          emit_eobrun(entropy);
          ac_tbl_no = entropy->ac_tbl_no;
          if ( entropy->gather_statistics != 0 )
            ++entropy->count_ptrs[ac_tbl_no][240];
          else
            emit_bits_0(
              entropy,
              code: entropy->derived_tbls[ac_tbl_no]->ehufco[240],
              size: entropy->derived_tbls[ac_tbl_no]->ehufsi[240]);
          v12 -= 16;
          emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BR);
          bit_buffer = entropy->bit_buffer;
          v13 = temp;
          v10 = k;
        }
        if ( v13 <= 1 )
        {
          emit_eobrun(entropy);
          v15 = entropy->ac_tbl_no;
          v16 = 16 * v12;
          if ( entropy->gather_statistics != 0 )
            ++entropy->count_ptrs[v15][v16 + 1];
          else
            emit_bits_0(
              entropy,
              code: entropy->derived_tbls[v15]->ehufco[v16 + 1],
              size: entropy->derived_tbls[v15]->ehufsi[v16 + 1]);
          v12 = 0;
          emit_bits_0(entropy, code: (*block)[jpeg_natural_order[k]] >= 0, size: 1);
          emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BR);
          bit_buffer = entropy->bit_buffer;
          v10 = k;
          BR = 0;
        }
        else
        {
          bit_buffer[BR++] = v13 & 1;
        }
        v2 = cinfo;
      }
      else
      {
        ++v12;
      }
      k = ++v10;
    }
    while ( v10 <= Se );
    if ( v12 > 0 || BR != 0 )
    {
      entropy->BE += BR;
      if ( ++entropy->EOBRUN == 0x7FFF || entropy->BE > 0x3A9 )
      {
        emit_eobrun(entropy);
        v2 = cinfo;
      }
    }
  }
  v2->dest->next_output_byte = entropy->next_output_byte;
  v2->dest->free_in_buffer = entropy->free_in_buffer;
  restart_interval = v2->restart_interval;
  if ( restart_interval != 0 )
  {
    if ( entropy->restarts_to_go == 0 )
    {
      entropy->restarts_to_go = restart_interval;
      entropy->next_restart_num = ((unsigned __int8)entropy->next_restart_num + 1) & 7;
    }
    --entropy->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00433060
// Name: finish_pass_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_phuff(jpeg_compress_struct *cinfo)
{
  phuff_entropy_encoder *entropy; // esi
  unsigned __int8 *next_output_byte; // edx

  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  entropy->next_output_byte = cinfo->dest->next_output_byte;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  emit_eobrun(entropy);
  emit_bits_0(entropy, code: 0x7Fu, size: 7);
  next_output_byte = entropy->next_output_byte;
  entropy->put_buffer = 0;
  entropy->put_bits = 0;
  cinfo->dest->next_output_byte = next_output_byte;
  cinfo->dest->free_in_buffer = entropy->free_in_buffer;
}

//------------------------------------------------------------------------------
// Address: 0x004330B0
// Name: finish_pass_gather_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_gather_phuff(jpeg_common_struct *cinfo)
{
  bool v2; // zf
  bool v3; // cl
  jpeg_component_info *v4; // eax
  int dc_tbl_no; // ebx
  JHUFF_TBL **v6; // edi
  phuff_entropy_encoder *entropy; // [esp+8h] [ebp-10h]
  unsigned __int8 did[4]; // [esp+Ch] [ebp-Ch]
  int ci; // [esp+10h] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+14h] [ebp-4h]
  bool is_DC_band_3; // [esp+23h] [ebp+Bh]

  entropy = (phuff_entropy_encoder *)cinfo[14].client_data;
  emit_eobrun(entropy);
  v2 = cinfo[12].client_data == nullptr;
  *(_DWORD *)did = 0;
  v3 = v2;
  is_DC_band_3 = v2;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    while ( 1 )
    {
      v4 = *p_is_decompressor;
      if ( !v3 )
        break;
      if ( cinfo[12].global_state == 0 )
      {
        dc_tbl_no = v4->dc_tbl_no;
        goto LABEL_7;
      }
LABEL_13:
      ++p_is_decompressor;
      if ( ++ci >= (int)cinfo[9].client_data )
        return;
    }
    dc_tbl_no = v4->ac_tbl_no;
LABEL_7:
    if ( did[dc_tbl_no] == 0 )
    {
      v6 = (JHUFF_TBL **)(&cinfo[3].is_decompressor + 4 * dc_tbl_no);
      if ( !v3 )
        v6 = (JHUFF_TBL **)(&cinfo[4].progress + dc_tbl_no);
      if ( *v6 == nullptr )
        *v6 = jpeg_alloc_huff_table(cinfo);
      jpeg_gen_optimal_table(cinfo, htbl: *v6, freq: entropy->count_ptrs[dc_tbl_no]);
      v3 = is_DC_band_3;
      did[dc_tbl_no] = 1;
    }
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433170
// Name: start_pass_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_phuff(jpeg_common_struct *cinfo, unsigned __int8 gather_statistics)
{
  jpeg_entropy_encoder *client_data; // ebx
  jpeg_component_info *v4; // eax
  unsigned int dc_tbl_no; // edi
  unsigned int global_state; // edx
  int ci; // [esp+Ch] [ebp-Ch]
  unsigned __int8 is_DC_band; // [esp+10h] [ebp-8h]
  jpeg_entropy_encoder *v9; // [esp+14h] [ebp-4h]
  jpeg_component_info **cinfoa; // [esp+20h] [ebp+8h]

  client_data = (jpeg_entropy_encoder *)cinfo[14].client_data;
  LOBYTE(client_data[1].start_pass) = gather_statistics;
  client_data[2].finish_pass = (void (__cdecl *)(jpeg_compress_struct *))cinfo;
  is_DC_band = cinfo[12].client_data == nullptr;
  if ( cinfo[12].global_state != 0 )
  {
    if ( cinfo[12].client_data != nullptr )
    {
      client_data->encode_mcu = encode_mcu_AC_refine;
      if ( client_data[5].encode_mcu == nullptr )
        client_data[5].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1000);
    }
    else
    {
      client_data->encode_mcu = encode_mcu_DC_refine;
    }
  }
  else if ( cinfo[12].client_data != nullptr )
  {
    client_data->encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))encode_mcu_AC_first;
  }
  else
  {
    client_data->encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))encode_mcu_DC_first;
  }
  if ( gather_statistics != 0 )
    client_data->finish_pass = (void (__cdecl *)(jpeg_compress_struct *))finish_pass_gather_phuff;
  else
    client_data->finish_pass = finish_pass_phuff;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    v9 = client_data + 3;
    cinfoa = (jpeg_component_info **)&cinfo[9].is_decompressor;
    while ( 1 )
    {
      v4 = *cinfoa;
      v9->start_pass = nullptr;
      if ( is_DC_band == 0 )
        break;
      if ( cinfo[12].global_state == 0 )
      {
        dc_tbl_no = v4->dc_tbl_no;
        goto LABEL_18;
      }
LABEL_25:
      ++cinfoa;
      v9 = (jpeg_entropy_encoder *)((char *)v9 + 4);
      if ( ++ci >= (int)cinfo[9].client_data )
        goto LABEL_26;
    }
    dc_tbl_no = v4->ac_tbl_no;
    client_data[4].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))dc_tbl_no;
LABEL_18:
    if ( gather_statistics != 0 )
    {
      if ( dc_tbl_no >= 4 )
      {
        cinfo->err->msg_code = 50;
        cinfo->err->msg_parm.i[0] = dc_tbl_no;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *((_DWORD *)&client_data[7].finish_pass + dc_tbl_no) == 0 )
        *((_DWORD *)&client_data[7].finish_pass + dc_tbl_no) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
      memset(dst: *((unsigned __int8 **)&client_data[7].finish_pass + dc_tbl_no), value: 0, count: 0x404u);
    }
    else
    {
      jpeg_make_c_derived_tbl(
        cinfo,
        isDC: is_DC_band,
        tblno: dc_tbl_no,
        pdtbl: (c_derived_tbl **)&client_data[6].encode_mcu + dc_tbl_no);
    }
    goto LABEL_25;
  }
LABEL_26:
  client_data[4].finish_pass = nullptr;
  client_data[5].start_pass = nullptr;
  client_data[2].start_pass = nullptr;
  client_data[2].encode_mcu = nullptr;
  global_state = cinfo[7].global_state;
  client_data[6].start_pass = nullptr;
  client_data[5].finish_pass = (void (__cdecl *)(jpeg_compress_struct *))global_state;
}

//------------------------------------------------------------------------------
// Address: 0x004332F0
// Name: _jinit_phuff_encoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_phuff_encoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_encoder *v1; // eax

  v1 = (jpeg_entropy_encoder *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 108);
  cinfo[14].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))start_pass_phuff;
  v1[6].encode_mcu = nullptr;
  v1[7].finish_pass = nullptr;
  v1[6].finish_pass = nullptr;
  v1[8].start_pass = nullptr;
  v1[7].start_pass = nullptr;
  v1[8].encode_mcu = nullptr;
  v1[7].encode_mcu = nullptr;
  v1[8].finish_pass = nullptr;
  v1[5].encode_mcu = nullptr;
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041F540
// Name: emit_buffered_bits
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_buffered_bits(phuff_entropy_encoder *entropy@<esi>, char *bufstart, unsigned int nbits)
{
  int v3; // eax
  int v4; // edi
  bool v5; // zf
  jpeg_destination_mgr *v6; // ebx
  int v7; // [esp+0h] [ebp-Ch]
  jpeg_destination_mgr *dest; // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  if ( entropy->gather_statistics == 0 && nbits != 0 )
  {
    do
    {
      if ( entropy->gather_statistics == 0 )
      {
        v3 = entropy->put_bits + 1;
        v4 = entropy->put_buffer | ((*bufstart & 1) << (24 - v3));
        if ( v3 >= 8 )
        {
          v9 = (unsigned int)v3 >> 3;
          v7 = v3 - 8 * ((unsigned int)v3 >> 3);
          do
          {
            *entropy->next_output_byte++ = BYTE2(v4);
            v5 = entropy->free_in_buffer-- == 1;
            if ( v5 )
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
            if ( BYTE2(v4) == 255 )
            {
              *entropy->next_output_byte++ = 0;
              v5 = entropy->free_in_buffer-- == 1;
              if ( v5 )
              {
                v6 = entropy->cinfo->dest;
                if ( v6->empty_output_buffer(a1: entropy->cinfo) == 0 )
                {
                  entropy->cinfo->err->msg_code = 24;
                  entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
                }
                entropy->next_output_byte = v6->next_output_byte;
                entropy->free_in_buffer = v6->free_in_buffer;
              }
            }
            v4 <<= 8;
            --v9;
          }
          while ( v9 != 0 );
          v3 = v7;
        }
        entropy->put_buffer = v4;
        entropy->put_bits = v3;
      }
      ++bufstart;
      --nbits;
    }
    while ( nbits != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F680
// Name: emit_eobrun
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_eobrun(phuff_entropy_encoder *entropy@<eax>)
{
  signed int EOBRUN; // eax
  int v3; // edi
  int v4; // eax
  int ac_tbl_no; // ecx
  char *bit_buffer; // [esp-Ch] [ebp-10h]
  unsigned int BE; // [esp-8h] [ebp-Ch]

  EOBRUN = entropy->EOBRUN;
  if ( EOBRUN != 0 )
  {
    v3 = 0;
    v4 = EOBRUN >> 1;
    if ( v4 != 0 )
    {
      do
      {
        ++v3;
        v4 >>= 1;
      }
      while ( v4 != 0 );
      if ( v3 > 14 )
      {
        entropy->cinfo->err->msg_code = 40;
        entropy->cinfo->err->error_exit(a1: (jpeg_common_struct *)entropy->cinfo);
      }
    }
    ac_tbl_no = entropy->ac_tbl_no;
    if ( entropy->gather_statistics != 0 )
      ++entropy->count_ptrs[ac_tbl_no][16 * v3];
    else
      emit_bits_0(
        entropy,
        code: entropy->derived_tbls[ac_tbl_no]->ehufco[16 * v3],
        size: entropy->derived_tbls[ac_tbl_no]->ehufsi[16 * v3]);
    if ( v3 != 0 )
      emit_bits_0(entropy, code: entropy->EOBRUN, size: v3);
    BE = entropy->BE;
    bit_buffer = entropy->bit_buffer;
    entropy->EOBRUN = 0;
    emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BE);
    entropy->BE = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F820
// Name: encode_mcu_DC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_DC_first(jpeg_common_struct *cinfo, __int16 (**MCU_data)[64])
{
  phuff_entropy_encoder *client_data; // esi
  int err; // edi
  int v5; // eax
  int v6; // edi
  int dc_tbl_no; // eax
  unsigned int global_state; // ebx
  int v9; // eax
  jpeg_component_info *compptr; // [esp+Ch] [ebp-10h]
  char v12; // [esp+10h] [ebp-Ch]
  int *p_global_state; // [esp+14h] [ebp-8h]
  int blkn; // [esp+18h] [ebp-4h]
  unsigned int temp2; // [esp+24h] [ebp+8h]

  client_data = (phuff_entropy_encoder *)cinfo[14].client_data;
  err = (int)cinfo[13].err;
  client_data->next_output_byte = (unsigned __int8 *)cinfo[1].err->error_exit;
  client_data->free_in_buffer = (unsigned int)cinfo[1].err->emit_message;
  if ( cinfo[7].global_state != 0 && client_data->restarts_to_go == 0 )
    emit_restart_0(entropy: client_data, restart_num: client_data->next_restart_num);
  blkn = 0;
  if ( *(int *)&cinfo[10].is_decompressor > 0 )
  {
    v12 = err;
    p_global_state = &cinfo[10].global_state;
    do
    {
      compptr = *((jpeg_component_info **)&cinfo[9].is_decompressor + *p_global_state);
      v5 = ((*MCU_data[blkn])[0] >> v12) - client_data->last_dc_val[*p_global_state];
      client_data->last_dc_val[*p_global_state] = (*MCU_data[blkn])[0] >> v12;
      temp2 = v5;
      if ( v5 < 0 )
      {
        v5 = -v5;
        --temp2;
      }
      v6 = 0;
      if ( v5 != 0 )
      {
        do
        {
          ++v6;
          v5 >>= 1;
        }
        while ( v5 != 0 );
        if ( v6 > 11 )
        {
          cinfo->err->msg_code = 6;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      dc_tbl_no = compptr->dc_tbl_no;
      if ( client_data->gather_statistics != 0 )
        ++client_data->count_ptrs[dc_tbl_no][v6];
      else
        emit_bits_0(
          entropy: client_data,
          code: client_data->derived_tbls[dc_tbl_no]->ehufco[v6],
          size: client_data->derived_tbls[dc_tbl_no]->ehufsi[v6]);
      if ( v6 != 0 )
        emit_bits_0(entropy: client_data, code: temp2, size: v6);
      ++p_global_state;
      ++blkn;
    }
    while ( blkn < *(_DWORD *)&cinfo[10].is_decompressor );
  }
  cinfo[1].err->error_exit = (void (__cdecl *)(jpeg_common_struct *))client_data->next_output_byte;
  cinfo[1].err->emit_message = (void (__cdecl *)(jpeg_common_struct *, int))client_data->free_in_buffer;
  global_state = cinfo[7].global_state;
  if ( global_state != 0 )
  {
    if ( client_data->restarts_to_go == 0 )
    {
      v9 = ((unsigned __int8)client_data->next_restart_num + 1) & 7;
      client_data->restarts_to_go = global_state;
      client_data->next_restart_num = v9;
    }
    --client_data->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F980
// Name: encode_mcu_AC_first
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_AC_first(jpeg_common_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_common_struct *v2; // ebx
  int err; // eax
  phuff_entropy_encoder *client_data; // esi
  int v5; // edi
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edi
  int v10; // edi
  unsigned int v11; // ebx
  int ac_tbl_no; // eax
  int v13; // edi
  int v14; // ebx
  int v15; // ecx
  int v16; // eax
  unsigned int global_state; // ebx
  int v18; // eax
  int Se; // [esp+Ch] [ebp-14h]
  __int16 *block; // [esp+10h] [ebp-10h]
  int k; // [esp+14h] [ebp-Ch]
  unsigned int temp2; // [esp+18h] [ebp-8h]
  char v24; // [esp+1Ch] [ebp-4h]
  int r; // [esp+2Ch] [ebp+Ch]

  v2 = cinfo;
  err = (int)cinfo[13].err;
  client_data = (phuff_entropy_encoder *)cinfo[14].client_data;
  v5 = *(_DWORD *)&cinfo[12].is_decompressor;
  client_data->next_output_byte = (unsigned __int8 *)cinfo[1].err->error_exit;
  v24 = err;
  client_data->free_in_buffer = (unsigned int)cinfo[1].err->emit_message;
  Se = v5;
  if ( cinfo[7].global_state != 0 && client_data->restarts_to_go == 0 )
    emit_restart_0(entropy: client_data, restart_num: client_data->next_restart_num);
  v6 = (int)cinfo[12].client_data;
  v7 = 0;
  block = (__int16 *)*MCU_data;
  r = 0;
  k = v6;
  if ( v6 <= v5 )
  {
    do
    {
      v8 = jpeg_natural_order[v6];
      v9 = block[v8];
      if ( block[v8] != 0 )
      {
        if ( v9 >= 0 )
        {
          v10 = v9 >> v24;
          temp2 = v10;
        }
        else
        {
          v10 = -v9 >> v24;
          temp2 = ~v10;
        }
        if ( v10 != 0 )
        {
          if ( client_data->EOBRUN != 0 )
          {
            emit_eobrun(entropy: client_data);
            v7 = r;
          }
          if ( v7 > 15 )
          {
            v11 = ((unsigned int)(v7 - 16) >> 4) + 1;
            r = -16 * v11 + v7;
            do
            {
              ac_tbl_no = client_data->ac_tbl_no;
              if ( client_data->gather_statistics != 0 )
                ++client_data->count_ptrs[ac_tbl_no][240];
              else
                emit_bits_0(
                  entropy: client_data,
                  code: client_data->derived_tbls[ac_tbl_no]->ehufco[240],
                  size: client_data->derived_tbls[ac_tbl_no]->ehufsi[240]);
              --v11;
            }
            while ( v11 != 0 );
          }
          v13 = v10 >> 1;
          v14 = 1;
          if ( v13 != 0 )
          {
            do
            {
              ++v14;
              v13 >>= 1;
            }
            while ( v13 != 0 );
            if ( v14 > 10 )
            {
              cinfo->err->msg_code = 6;
              cinfo->err->error_exit(a1: cinfo);
            }
          }
          v15 = client_data->ac_tbl_no;
          v16 = v14 + 16 * r;
          if ( client_data->gather_statistics != 0 )
            ++client_data->count_ptrs[v15][v16];
          else
            emit_bits_0(
              entropy: client_data,
              code: client_data->derived_tbls[v15]->ehufco[v16],
              size: client_data->derived_tbls[v15]->ehufsi[v16]);
          emit_bits_0(entropy: client_data, code: temp2, size: v14);
          v6 = k;
          v2 = cinfo;
          r = 0;
          v7 = 0;
        }
        else
        {
          r = ++v7;
        }
      }
      else
      {
        r = ++v7;
      }
      k = ++v6;
    }
    while ( v6 <= Se );
    if ( v7 > 0 && ++client_data->EOBRUN == 0x7FFF )
      emit_eobrun(entropy: client_data);
  }
  v2[1].err->error_exit = (void (__cdecl *)(jpeg_common_struct *))client_data->next_output_byte;
  v2[1].err->emit_message = (void (__cdecl *)(jpeg_common_struct *, int))client_data->free_in_buffer;
  global_state = v2[7].global_state;
  if ( global_state != 0 )
  {
    if ( client_data->restarts_to_go == 0 )
    {
      v18 = ((unsigned __int8)client_data->next_restart_num + 1) & 7;
      client_data->restarts_to_go = global_state;
      client_data->next_restart_num = v18;
    }
    --client_data->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041FB70
// Name: encode_mcu_DC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_DC_refine(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  int Al; // eax
  phuff_entropy_encoder *entropy; // esi
  int i; // ebx
  unsigned int restart_interval; // edi
  int v7; // edx
  char cinfoa; // [esp+10h] [ebp+8h]

  Al = cinfo->Al;
  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  entropy->next_output_byte = cinfo->dest->next_output_byte;
  cinfoa = Al;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  if ( cinfo->restart_interval != 0 && entropy->restarts_to_go == 0 )
    emit_restart_0(entropy, restart_num: entropy->next_restart_num);
  for ( i = 0; i < cinfo->blocks_in_MCU; ++i )
    emit_bits_0(entropy, code: (*MCU_data[i])[0] >> cinfoa, size: 1);
  cinfo->dest->next_output_byte = entropy->next_output_byte;
  cinfo->dest->free_in_buffer = entropy->free_in_buffer;
  restart_interval = cinfo->restart_interval;
  if ( restart_interval != 0 )
  {
    if ( entropy->restarts_to_go == 0 )
    {
      v7 = ((unsigned __int8)entropy->next_restart_num + 1) & 7;
      entropy->restarts_to_go = restart_interval;
      entropy->next_restart_num = v7;
    }
    --entropy->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041FC20
// Name: encode_mcu_AC_refine
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl encode_mcu_AC_refine(jpeg_compress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_compress_struct *v2; // edx
  jpeg_destination_mgr *dest; // ecx
  int v4; // ebx
  phuff_entropy_encoder *entropy; // esi
  bool v6; // zf
  int Ss; // eax
  int v8; // edi
  int v9; // edi
  int v10; // ecx
  char *bit_buffer; // ebx
  int v12; // edi
  int v13; // eax
  int ac_tbl_no; // eax
  int v15; // eax
  int v16; // edi
  unsigned int restart_interval; // edx
  int absvalues[64]; // [esp+Ch] [ebp-114h]
  __int16 (*block)[64]; // [esp+10Ch] [ebp-14h]
  int EOB; // [esp+110h] [ebp-10h]
  int Se; // [esp+114h] [ebp-Ch]
  int temp; // [esp+118h] [ebp-8h]
  int k; // [esp+11Ch] [ebp-4h]
  unsigned int BR; // [esp+12Ch] [ebp+Ch]

  v2 = cinfo;
  dest = cinfo->dest;
  v4 = cinfo->Se;
  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  temp = cinfo->Al;
  entropy->next_output_byte = dest->next_output_byte;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  v6 = cinfo->restart_interval == 0;
  Se = v4;
  if ( !v6 && entropy->restarts_to_go == 0 )
  {
    emit_restart_0(entropy, restart_num: entropy->next_restart_num);
    v2 = cinfo;
  }
  Ss = v2->Ss;
  block = *MCU_data;
  for ( EOB = 0; Ss <= v4; ++Ss )
  {
    v8 = (*block)[jpeg_natural_order[Ss]];
    if ( v8 < 0 )
      v8 = -v8;
    v9 = v8 >> temp;
    absvalues[Ss] = v9;
    if ( v9 == 1 )
      EOB = Ss;
  }
  v10 = v2->Ss;
  bit_buffer = &entropy->bit_buffer[entropy->BE];
  v12 = 0;
  BR = 0;
  k = v10;
  if ( v10 <= Se )
  {
    do
    {
      v13 = absvalues[v10];
      temp = v13;
      if ( v13 != 0 )
      {
        for ( ; v12 > 15; BR = 0 )
        {
          if ( v10 > EOB )
            break;
          emit_eobrun(entropy);
          ac_tbl_no = entropy->ac_tbl_no;
          if ( entropy->gather_statistics != 0 )
            ++entropy->count_ptrs[ac_tbl_no][240];
          else
            emit_bits_0(
              entropy,
              code: entropy->derived_tbls[ac_tbl_no]->ehufco[240],
              size: entropy->derived_tbls[ac_tbl_no]->ehufsi[240]);
          v12 -= 16;
          emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BR);
          bit_buffer = entropy->bit_buffer;
          v13 = temp;
          v10 = k;
        }
        if ( v13 <= 1 )
        {
          emit_eobrun(entropy);
          v15 = entropy->ac_tbl_no;
          v16 = 16 * v12;
          if ( entropy->gather_statistics != 0 )
            ++entropy->count_ptrs[v15][v16 + 1];
          else
            emit_bits_0(
              entropy,
              code: entropy->derived_tbls[v15]->ehufco[v16 + 1],
              size: entropy->derived_tbls[v15]->ehufsi[v16 + 1]);
          v12 = 0;
          emit_bits_0(entropy, code: (*block)[jpeg_natural_order[k]] >= 0, size: 1);
          emit_buffered_bits(entropy, bufstart: bit_buffer, nbits: BR);
          bit_buffer = entropy->bit_buffer;
          v10 = k;
          BR = 0;
        }
        else
        {
          bit_buffer[BR++] = v13 & 1;
        }
        v2 = cinfo;
      }
      else
      {
        ++v12;
      }
      k = ++v10;
    }
    while ( v10 <= Se );
    if ( v12 > 0 || BR != 0 )
    {
      entropy->BE += BR;
      if ( ++entropy->EOBRUN == 0x7FFF || entropy->BE > 0x3A9 )
      {
        emit_eobrun(entropy);
        v2 = cinfo;
      }
    }
  }
  v2->dest->next_output_byte = entropy->next_output_byte;
  v2->dest->free_in_buffer = entropy->free_in_buffer;
  restart_interval = v2->restart_interval;
  if ( restart_interval != 0 )
  {
    if ( entropy->restarts_to_go == 0 )
    {
      entropy->restarts_to_go = restart_interval;
      entropy->next_restart_num = ((unsigned __int8)entropy->next_restart_num + 1) & 7;
    }
    --entropy->restarts_to_go;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041FE60
// Name: finish_pass_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_phuff(jpeg_compress_struct *cinfo)
{
  phuff_entropy_encoder *entropy; // esi
  unsigned __int8 *next_output_byte; // edx

  entropy = (phuff_entropy_encoder *)cinfo->entropy;
  entropy->next_output_byte = cinfo->dest->next_output_byte;
  entropy->free_in_buffer = cinfo->dest->free_in_buffer;
  emit_eobrun(entropy);
  emit_bits_0(entropy, code: 0x7Fu, size: 7);
  next_output_byte = entropy->next_output_byte;
  entropy->put_buffer = 0;
  entropy->put_bits = 0;
  cinfo->dest->next_output_byte = next_output_byte;
  cinfo->dest->free_in_buffer = entropy->free_in_buffer;
}

//------------------------------------------------------------------------------
// Address: 0x0041FEB0
// Name: finish_pass_gather_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_gather_phuff(jpeg_common_struct *cinfo)
{
  bool v2; // zf
  bool v3; // cl
  jpeg_component_info *v4; // eax
  int dc_tbl_no; // ebx
  JHUFF_TBL **v6; // edi
  phuff_entropy_encoder *entropy; // [esp+8h] [ebp-10h]
  unsigned __int8 did[4]; // [esp+Ch] [ebp-Ch]
  int ci; // [esp+10h] [ebp-8h]
  jpeg_component_info **p_is_decompressor; // [esp+14h] [ebp-4h]
  bool is_DC_band_3; // [esp+23h] [ebp+Bh]

  entropy = (phuff_entropy_encoder *)cinfo[14].client_data;
  emit_eobrun(entropy);
  v2 = cinfo[12].client_data == nullptr;
  *(_DWORD *)did = 0;
  v3 = v2;
  is_DC_band_3 = v2;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    while ( 1 )
    {
      v4 = *p_is_decompressor;
      if ( !v3 )
        break;
      if ( cinfo[12].global_state == 0 )
      {
        dc_tbl_no = v4->dc_tbl_no;
        goto LABEL_7;
      }
LABEL_13:
      ++p_is_decompressor;
      if ( ++ci >= (int)cinfo[9].client_data )
        return;
    }
    dc_tbl_no = v4->ac_tbl_no;
LABEL_7:
    if ( did[dc_tbl_no] == 0 )
    {
      v6 = (JHUFF_TBL **)(&cinfo[3].is_decompressor + 4 * dc_tbl_no);
      if ( !v3 )
        v6 = (JHUFF_TBL **)(&cinfo[4].progress + dc_tbl_no);
      if ( *v6 == nullptr )
        *v6 = jpeg_alloc_huff_table(cinfo);
      jpeg_gen_optimal_table(cinfo, htbl: *v6, freq: entropy->count_ptrs[dc_tbl_no]);
      v3 = is_DC_band_3;
      did[dc_tbl_no] = 1;
    }
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FF70
// Name: start_pass_phuff
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_phuff(jpeg_common_struct *cinfo, unsigned __int8 gather_statistics)
{
  jpeg_entropy_encoder *client_data; // ebx
  jpeg_component_info *v4; // eax
  unsigned int dc_tbl_no; // edi
  unsigned int global_state; // edx
  int ci; // [esp+Ch] [ebp-Ch]
  unsigned __int8 is_DC_band; // [esp+10h] [ebp-8h]
  jpeg_entropy_encoder *v9; // [esp+14h] [ebp-4h]
  jpeg_component_info **cinfoa; // [esp+20h] [ebp+8h]

  client_data = (jpeg_entropy_encoder *)cinfo[14].client_data;
  LOBYTE(client_data[1].start_pass) = gather_statistics;
  client_data[2].finish_pass = (void (__cdecl *)(jpeg_compress_struct *))cinfo;
  is_DC_band = cinfo[12].client_data == nullptr;
  if ( cinfo[12].global_state != 0 )
  {
    if ( cinfo[12].client_data != nullptr )
    {
      client_data->encode_mcu = encode_mcu_AC_refine;
      if ( client_data[5].encode_mcu == nullptr )
        client_data[5].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1000);
    }
    else
    {
      client_data->encode_mcu = encode_mcu_DC_refine;
    }
  }
  else if ( cinfo[12].client_data != nullptr )
  {
    client_data->encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))encode_mcu_AC_first;
  }
  else
  {
    client_data->encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))encode_mcu_DC_first;
  }
  if ( gather_statistics != 0 )
    client_data->finish_pass = (void (__cdecl *)(jpeg_compress_struct *))finish_pass_gather_phuff;
  else
    client_data->finish_pass = finish_pass_phuff;
  ci = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    v9 = client_data + 3;
    cinfoa = (jpeg_component_info **)&cinfo[9].is_decompressor;
    while ( 1 )
    {
      v4 = *cinfoa;
      v9->start_pass = nullptr;
      if ( is_DC_band == 0 )
        break;
      if ( cinfo[12].global_state == 0 )
      {
        dc_tbl_no = v4->dc_tbl_no;
        goto LABEL_18;
      }
LABEL_25:
      ++cinfoa;
      v9 = (jpeg_entropy_encoder *)((char *)v9 + 4);
      if ( ++ci >= (int)cinfo[9].client_data )
        goto LABEL_26;
    }
    dc_tbl_no = v4->ac_tbl_no;
    client_data[4].encode_mcu = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, __int16 (**)[64]))dc_tbl_no;
LABEL_18:
    if ( gather_statistics != 0 )
    {
      if ( dc_tbl_no >= 4 )
      {
        cinfo->err->msg_code = 50;
        cinfo->err->msg_parm.i[0] = dc_tbl_no;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *((_DWORD *)&client_data[7].finish_pass + dc_tbl_no) == 0 )
        *((_DWORD *)&client_data[7].finish_pass + dc_tbl_no) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1028);
      memset(dst: *((unsigned __int8 **)&client_data[7].finish_pass + dc_tbl_no), value: 0, count: 0x404u);
    }
    else
    {
      jpeg_make_c_derived_tbl(
        cinfo,
        isDC: is_DC_band,
        tblno: dc_tbl_no,
        pdtbl: (c_derived_tbl **)&client_data[6].encode_mcu + dc_tbl_no);
    }
    goto LABEL_25;
  }
LABEL_26:
  client_data[4].finish_pass = nullptr;
  client_data[5].start_pass = nullptr;
  client_data[2].start_pass = nullptr;
  client_data[2].encode_mcu = nullptr;
  global_state = cinfo[7].global_state;
  client_data[6].start_pass = nullptr;
  client_data[5].finish_pass = (void (__cdecl *)(jpeg_compress_struct *))global_state;
}

//------------------------------------------------------------------------------
// Address: 0x004200F0
// Name: _jinit_phuff_encoder
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_phuff_encoder(jpeg_common_struct *cinfo)
{
  jpeg_entropy_encoder *v1; // eax

  v1 = (jpeg_entropy_encoder *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 108);
  cinfo[14].client_data = v1;
  v1->start_pass = (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8))start_pass_phuff;
  v1[6].encode_mcu = nullptr;
  v1[7].finish_pass = nullptr;
  v1[6].finish_pass = nullptr;
  v1[8].start_pass = nullptr;
  v1[7].start_pass = nullptr;
  v1[8].encode_mcu = nullptr;
  v1[7].encode_mcu = nullptr;
  v1[8].finish_pass = nullptr;
  v1[5].encode_mcu = nullptr;
}

} // namespace vxconsole_ps3
