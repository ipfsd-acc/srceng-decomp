// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdmarker.c
// Functions: 16
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000A050
// Name: get_soi
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall get_soi@<al>(jpeg_common_struct *cinfo@<esi>)
{
  unsigned __int8 *v1; // eax
  int i; // ecx
  jpeg_marker_reader *global_state; // eax

  cinfo->err->msg_code = 102;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  if ( *(_BYTE *)(cinfo[16].global_state + 12) != 0 )
  {
    cinfo->err->msg_code = 61;
    cinfo->err->error_exit(a1: cinfo);
  }
  v1 = (unsigned __int8 *)&cinfo[9].err + 2;
  for ( i = 16; i != 0; --i )
  {
    *(v1 - 16) = 0;
    *v1 = 1;
    v1[16] = 5;
    ++v1;
  }
  global_state = (jpeg_marker_reader *)cinfo[16].global_state;
  cinfo[10].client_data = nullptr;
  *(_DWORD *)&cinfo[1].is_decompressor = 0;
  BYTE2(cinfo[11].err) = 0;
  LOWORD(cinfo[11].err) = 0;
  *(_DWORD *)&cinfo[10].is_decompressor = 65792;
  cinfo[10].global_state = 65537;
  global_state->saw_SOI = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A0E0
// Name: get_sof
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall get_sof@<al>(
        jpeg_common_struct *cinfo@<esi>,
        unsigned __int8 is_prog@<cl>,
        unsigned __int8 is_arith@<dl>)
{
  jpeg_source_mgr *err; // eax
  unsigned int bytes_in_buffer; // ebx
  const unsigned __int8 *next_input_byte; // edi
  int v7; // ecx
  const unsigned __int8 *v8; // edi
  unsigned int v9; // ebx
  const unsigned __int8 *v10; // edi
  unsigned int v11; // ebx
  int v12; // ecx
  const unsigned __int8 *v13; // edi
  unsigned int v14; // ebx
  unsigned int v15; // ecx
  const unsigned __int8 *v16; // edi
  unsigned int v17; // ebx
  const unsigned __int8 *v18; // edi
  unsigned int v19; // ebx
  unsigned int v20; // ecx
  const unsigned __int8 *v21; // edi
  unsigned int v22; // ebx
  const unsigned __int8 *v23; // edi
  unsigned int v24; // ebx
  int global_state; // ecx
  jpeg_error_mgr *v26; // eax
  unsigned int v27; // ebx
  const unsigned __int8 *v28; // edi
  jpeg_component_info *mem; // ecx
  int v30; // edx
  const unsigned __int8 *v31; // edi
  unsigned int v32; // ebx
  int v33; // edx
  int v34; // eax
  const unsigned __int8 *v35; // edi
  unsigned int v36; // ebx
  jpeg_error_mgr *v37; // eax
  int ci; // [esp+8h] [ebp-Ch]
  int length; // [esp+Ch] [ebp-8h]
  int lengtha; // [esp+Ch] [ebp-8h]
  int lengthb; // [esp+Ch] [ebp-8h]
  int lengthc; // [esp+Ch] [ebp-8h]
  jpeg_source_mgr *datasrc; // [esp+10h] [ebp-4h]

  err = (jpeg_source_mgr *)cinfo[1].err;
  bytes_in_buffer = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  datasrc = err;
  LOBYTE(cinfo[8].progress) = is_prog;
  BYTE1(cinfo[8].progress) = is_arith;
  if ( bytes_in_buffer == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    next_input_byte = datasrc->next_input_byte;
    bytes_in_buffer = datasrc->bytes_in_buffer;
  }
  v7 = *next_input_byte << 8;
  v8 = next_input_byte + 1;
  v9 = bytes_in_buffer - 1;
  length = v7;
  if ( v9 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v8 = datasrc->next_input_byte;
    v9 = datasrc->bytes_in_buffer;
  }
  lengtha = *v8 + length;
  v10 = v8 + 1;
  v11 = v9 - 1;
  if ( v11 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v10 = datasrc->next_input_byte;
    v11 = datasrc->bytes_in_buffer;
  }
  v12 = *v10;
  v13 = v10 + 1;
  v14 = v11 - 1;
  cinfo[8].err = (jpeg_error_mgr *)v12;
  if ( v14 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v13 = datasrc->next_input_byte;
    v14 = datasrc->bytes_in_buffer;
  }
  v15 = *v13 << 8;
  v16 = v13 + 1;
  v17 = v14 - 1;
  cinfo[1].progress = (jpeg_progress_mgr *)v15;
  if ( v17 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v16 = datasrc->next_input_byte;
    v17 = datasrc->bytes_in_buffer;
  }
  cinfo[1].progress = (jpeg_progress_mgr *)((char *)cinfo[1].progress + *v16);
  v18 = v16 + 1;
  v19 = v17 - 1;
  if ( v19 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v18 = datasrc->next_input_byte;
    v19 = datasrc->bytes_in_buffer;
  }
  v20 = *v18 << 8;
  v21 = v18 + 1;
  v22 = v19 - 1;
  cinfo[1].mem = (jpeg_memory_mgr *)v20;
  if ( v22 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v21 = datasrc->next_input_byte;
    v22 = datasrc->bytes_in_buffer;
  }
  cinfo[1].mem = (jpeg_memory_mgr *)((char *)cinfo[1].mem + *v21);
  v23 = v21 + 1;
  v24 = v22 - 1;
  if ( v24 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v23 = datasrc->next_input_byte;
    v24 = datasrc->bytes_in_buffer;
  }
  global_state = cinfo[15].global_state;
  lengthb = lengtha - 8;
  cinfo[1].client_data = (void *)*v23;
  v26 = cinfo->err;
  v26->msg_parm.i[0] = global_state;
  v26->msg_parm.i[1] = (int)cinfo[1].mem;
  v26->msg_parm.i[2] = (int)cinfo[1].progress;
  v26->msg_parm.i[3] = (int)cinfo[1].client_data;
  cinfo->err->msg_code = 100;
  v27 = v24 - 1;
  v28 = v23 + 1;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  if ( *(_BYTE *)(cinfo[16].global_state + 13) != 0 )
  {
    cinfo->err->msg_code = 58;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[1].progress == nullptr || cinfo[1].mem == nullptr || (int)cinfo[1].client_data <= 0 )
  {
    cinfo->err->msg_code = 32;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( lengthb != 3 * (int)cinfo[1].client_data )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[8].mem == nullptr )
    cinfo[8].mem = (jpeg_memory_mgr *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 84 * (int)cinfo[1].client_data);
  mem = (jpeg_component_info *)cinfo[8].mem;
  ci = 0;
  lengthc = (int)mem;
  if ( (int)cinfo[1].client_data > 0 )
  {
    while ( 1 )
    {
      mem->component_index = ci;
      if ( v27 == 0 )
      {
        if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v28 = datasrc->next_input_byte;
        v27 = datasrc->bytes_in_buffer;
        mem = (jpeg_component_info *)lengthc;
      }
      v30 = *v28;
      v31 = v28 + 1;
      v32 = v27 - 1;
      mem->component_id = v30;
      if ( v32 == 0 )
      {
        if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v31 = datasrc->next_input_byte;
        v32 = datasrc->bytes_in_buffer;
        mem = (jpeg_component_info *)lengthc;
      }
      v33 = (int)*v31 >> 4;
      v34 = *v31 & 0xF;
      v35 = v31 + 1;
      v36 = v32 - 1;
      mem->h_samp_factor = v33;
      mem->v_samp_factor = v34;
      if ( v36 == 0 )
      {
        if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v35 = datasrc->next_input_byte;
        v36 = datasrc->bytes_in_buffer;
        mem = (jpeg_component_info *)lengthc;
      }
      mem->quant_tbl_no = *v35;
      v37 = cinfo->err;
      v37->msg_parm.i[0] = mem->component_id;
      v37->msg_parm.i[1] = mem->h_samp_factor;
      v37->msg_parm.i[2] = mem->v_samp_factor;
      v37->msg_parm.i[3] = mem->quant_tbl_no;
      cinfo->err->msg_code = 101;
      v27 = v36 - 1;
      v28 = v35 + 1;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      lengthc += 84;
      if ( ++ci >= (int)cinfo[1].client_data )
        break;
      mem = (jpeg_component_info *)lengthc;
    }
  }
  *(_BYTE *)(cinfo[16].global_state + 13) = 1;
  datasrc->next_input_byte = v28;
  datasrc->bytes_in_buffer = v27;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A3E0
// Name: get_sos
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall get_sos@<al>(jpeg_common_struct *cinfo@<esi>)
{
  jpeg_source_mgr *err; // ecx
  const unsigned __int8 *next_input_byte; // ebx
  unsigned int v3; // edi
  int v5; // eax
  const unsigned __int8 *v6; // ebx
  unsigned int v7; // edi
  int v8; // edx
  const unsigned __int8 *v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  unsigned int v12; // edi
  const unsigned __int8 *v13; // ebx
  int v14; // eax
  int v15; // edx
  const unsigned __int8 *v16; // ebx
  unsigned int v17; // edi
  int v18; // eax
  int v19; // ecx
  jpeg_component_info *mem; // edi
  jpeg_error_mgr *v21; // eax
  int v22; // eax
  const unsigned __int8 *v23; // ebx
  unsigned int v24; // edi
  int v25; // eax
  const unsigned __int8 *v26; // ebx
  unsigned int v27; // edi
  int v28; // edx
  int v29; // ecx
  jpeg_error_mgr *v30; // eax
  int c; // [esp+8h] [ebp-1Ch]
  int i; // [esp+Ch] [ebp-18h]
  int n; // [esp+10h] [ebp-14h]
  jpeg_component_info **p_progress; // [esp+14h] [ebp-10h]
  int cc; // [esp+18h] [ebp-Ch]
  int cca; // [esp+18h] [ebp-Ch]
  int ccb; // [esp+18h] [ebp-Ch]
  jpeg_source_mgr *datasrc; // [esp+1Ch] [ebp-8h]
  unsigned int bytes_in_buffer; // [esp+20h] [ebp-4h]

  err = (jpeg_source_mgr *)cinfo[1].err;
  next_input_byte = err->next_input_byte;
  v3 = err->bytes_in_buffer;
  datasrc = err;
  if ( *(_BYTE *)(cinfo[16].global_state + 13) == 0 )
  {
    cinfo->err->msg_code = 62;
    cinfo->err->error_exit(a1: cinfo);
    err = datasrc;
  }
  if ( v3 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    next_input_byte = datasrc->next_input_byte;
    v3 = datasrc->bytes_in_buffer;
    err = datasrc;
  }
  v5 = *next_input_byte << 8;
  v6 = next_input_byte + 1;
  v7 = v3 - 1;
  cc = v5;
  if ( v7 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v6 = datasrc->next_input_byte;
    v7 = datasrc->bytes_in_buffer;
    err = datasrc;
    v5 = cc;
  }
  v8 = *v6;
  v9 = v6 + 1;
  v10 = v7 - 1;
  cca = v8 + v5;
  if ( v10 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v9 = datasrc->next_input_byte;
    v10 = datasrc->bytes_in_buffer;
  }
  v11 = *v9;
  cinfo->err->msg_code = 103;
  cinfo->err->msg_parm.i[0] = v11;
  n = v11;
  v12 = v10 - 1;
  v13 = v9 + 1;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  v14 = n;
  if ( cca != 2 * n + 6 || n < 1 || n > 4 )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
    v14 = n;
  }
  cinfo[12].mem = (jpeg_memory_mgr *)v14;
  i = 0;
  if ( v14 > 0 )
  {
    p_progress = (jpeg_component_info **)&cinfo[12].progress;
    do
    {
      if ( v12 == 0 )
      {
        if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v13 = datasrc->next_input_byte;
        v12 = datasrc->bytes_in_buffer;
      }
      v15 = *v13;
      v16 = v13 + 1;
      v17 = v12 - 1;
      ccb = v15;
      if ( v17 == 0 )
      {
        if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v16 = datasrc->next_input_byte;
        v17 = datasrc->bytes_in_buffer;
      }
      v18 = *v16;
      v19 = 0;
      v13 = v16 + 1;
      bytes_in_buffer = v17 - 1;
      mem = (jpeg_component_info *)cinfo[8].mem;
      c = v18;
      if ( (int)cinfo[1].client_data <= 0 )
      {
LABEL_28:
        cinfo->err->msg_code = 5;
        cinfo->err->msg_parm.i[0] = ccb;
        cinfo->err->error_exit(a1: cinfo);
        v18 = c;
      }
      else
      {
        while ( ccb != mem->component_id )
        {
          ++v19;
          ++mem;
          if ( v19 >= (int)cinfo[1].client_data )
            goto LABEL_28;
        }
      }
      *p_progress = mem;
      mem->dc_tbl_no = (v18 >> 4) & 0xF;
      mem->ac_tbl_no = v18 & 0xF;
      v21 = cinfo->err;
      v21->msg_parm.i[0] = ccb;
      v21->msg_parm.i[1] = mem->dc_tbl_no;
      v21->msg_parm.i[2] = mem->ac_tbl_no;
      cinfo->err->msg_code = 104;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      ++p_progress;
      v12 = bytes_in_buffer;
      ++i;
    }
    while ( i < n );
  }
  if ( v12 == 0 )
  {
    if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v13 = datasrc->next_input_byte;
    v12 = datasrc->bytes_in_buffer;
  }
  v22 = *v13;
  v23 = v13 + 1;
  v24 = v12 - 1;
  cinfo[15].mem = (jpeg_memory_mgr *)v22;
  if ( v24 == 0 )
  {
    if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v23 = datasrc->next_input_byte;
    v24 = datasrc->bytes_in_buffer;
  }
  v25 = *v23;
  v26 = v23 + 1;
  v27 = v24 - 1;
  cinfo[15].progress = (jpeg_progress_mgr *)v25;
  if ( v27 == 0 )
  {
    if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v26 = datasrc->next_input_byte;
    v27 = datasrc->bytes_in_buffer;
  }
  v28 = (int)cinfo[15].mem;
  v29 = (int)*v26 >> 4;
  *(_DWORD *)&cinfo[15].is_decompressor = *v26 & 0xF;
  v30 = cinfo->err;
  cinfo[15].client_data = (void *)v29;
  v30->msg_parm.i[0] = v28;
  v30->msg_parm.i[1] = (int)cinfo[15].progress;
  v30->msg_parm.i[2] = (int)cinfo[15].client_data;
  v30->msg_parm.i[3] = *(_DWORD *)&cinfo[15].is_decompressor;
  cinfo->err->msg_code = 105;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  *(_DWORD *)(cinfo[16].global_state + 16) = 0;
  ++cinfo[5].mem;
  datasrc->bytes_in_buffer = v27 - 1;
  datasrc->next_input_byte = v26 + 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A6C0
// Name: get_dht
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl get_dht(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // ecx
  const unsigned __int8 *v3; // esi
  unsigned int v4; // edi
  int v6; // eax
  const unsigned __int8 *v7; // esi
  unsigned int v8; // edi
  int v9; // eax
  unsigned int v10; // edi
  const unsigned __int8 *v11; // esi
  int v12; // eax
  unsigned int v13; // edi
  unsigned __int8 *v14; // esi
  int v15; // eax
  jpeg_source_mgr *v16; // esi
  unsigned int v17; // ecx
  unsigned __int8 v18; // dl
  jpeg_error_mgr *v19; // eax
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  int v24; // ecx
  int v25; // edx
  int v26; // ecx
  jpeg_error_mgr *v27; // eax
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  int v31; // edx
  int v32; // ecx
  int v33; // edx
  int v34; // ecx
  int v35; // ecx
  int v36; // eax
  jpeg_source_mgr *v37; // esi
  unsigned int v38; // ecx
  unsigned int v39; // eax
  void **v40; // esi
  bool v41; // cc
  unsigned __int8 huffval[256]; // [esp+Ch] [ebp-12Ch]
  int index; // [esp+10Ch] [ebp-2Ch]
  unsigned __int8 bits[20]; // [esp+110h] [ebp-28h]
  int i; // [esp+124h] [ebp-14h]
  int count; // [esp+128h] [ebp-10h]
  int length; // [esp+12Ch] [ebp-Ch]
  jpeg_source_mgr *datasrc; // [esp+130h] [ebp-8h]
  unsigned int bytes_in_buffer; // [esp+134h] [ebp-4h]
  const unsigned __int8 *next_input_byte; // [esp+140h] [ebp+8h]

  err = (jpeg_source_mgr *)cinfo[1].err;
  v3 = err->next_input_byte;
  v4 = err->bytes_in_buffer;
  datasrc = err;
  if ( v4 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v3 = datasrc->next_input_byte;
    v4 = datasrc->bytes_in_buffer;
    err = datasrc;
  }
  v6 = *v3 << 8;
  v7 = v3 + 1;
  v8 = v4 - 1;
  length = v6;
  if ( v8 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v6 = length;
    v7 = datasrc->next_input_byte;
    err = datasrc;
    v8 = datasrc->bytes_in_buffer;
  }
  v9 = *v7 + v6 - 2;
  v10 = v8 - 1;
  v11 = v7 + 1;
  length = v9;
  if ( v9 > 16 )
  {
    do
    {
      if ( v10 == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v11 = datasrc->next_input_byte;
        v10 = datasrc->bytes_in_buffer;
      }
      v12 = *v11;
      cinfo->err->msg_code = 80;
      cinfo->err->msg_parm.i[0] = v12;
      index = v12;
      v13 = v10 - 1;
      v14 = (unsigned __int8 *)(v11 + 1);
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      v15 = 1;
      bits[0] = 0;
      count = 0;
      i = 1;
      do
      {
        if ( v13 == 0 )
        {
          v16 = datasrc;
          if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
            return 0;
          v17 = v16->bytes_in_buffer;
          v14 = (unsigned __int8 *)v16->next_input_byte;
          v15 = i;
          v13 = v17;
        }
        v18 = *v14;
        count += *v14;
        bits[v15++] = v18;
        --v13;
        ++v14;
        bytes_in_buffer = v13;
        next_input_byte = v14;
        i = v15;
      }
      while ( v15 <= 16 );
      v19 = cinfo->err;
      v20 = bits[2];
      length -= 17;
      v19->msg_parm.i[0] = bits[1];
      v21 = bits[3];
      v19->msg_parm.i[1] = v20;
      v22 = bits[4];
      v19->msg_parm.i[2] = v21;
      v23 = bits[5];
      v19->msg_parm.i[3] = v22;
      v24 = bits[6];
      v19->msg_parm.i[4] = v23;
      v25 = bits[7];
      v19->msg_parm.i[5] = v24;
      v26 = bits[8];
      v19->msg_parm.i[6] = v25;
      v19->msg_parm.i[7] = v26;
      cinfo->err->msg_code = 86;
      cinfo->err->emit_message(a1: cinfo, a2: 2);
      v27 = cinfo->err;
      v28 = bits[10];
      v27->msg_parm.i[0] = bits[9];
      v29 = bits[11];
      v27->msg_parm.i[1] = v28;
      v30 = bits[12];
      v27->msg_parm.i[2] = v29;
      v31 = bits[13];
      v27->msg_parm.i[3] = v30;
      v32 = bits[14];
      v27->msg_parm.i[4] = v31;
      v33 = bits[15];
      v27->msg_parm.i[5] = v32;
      v34 = bits[16];
      v27->msg_parm.i[6] = v33;
      v27->msg_parm.i[7] = v34;
      cinfo->err->msg_code = 86;
      cinfo->err->emit_message(a1: cinfo, a2: 2);
      v35 = count;
      if ( count > 256 || count > length )
      {
        cinfo->err->msg_code = 8;
        cinfo->err->error_exit(a1: cinfo);
        v35 = count;
      }
      v36 = 0;
      for ( i = 0; v36 < v35; i = v36 )
      {
        if ( v13 == 0 )
        {
          v37 = datasrc;
          if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
            return 0;
          v38 = v37->bytes_in_buffer;
          v14 = (unsigned __int8 *)v37->next_input_byte;
          v36 = i;
          v13 = v38;
          v35 = count;
        }
        huffval[v36++] = *v14;
        --v13;
        ++v14;
        bytes_in_buffer = v13;
        next_input_byte = v14;
      }
      v39 = index;
      length -= v35;
      if ( (index & 0x10) != 0 )
      {
        v39 = index - 16;
        v40 = (void **)(&cinfo[4].is_decompressor + 4 * index);
      }
      else
      {
        v40 = (void **)(&cinfo[6].is_decompressor + 4 * index);
      }
      if ( v39 >= 4 )
      {
        cinfo->err->msg_code = 30;
        cinfo->err->msg_parm.i[0] = v39;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *v40 == nullptr )
        *v40 = jpeg_alloc_huff_table(cinfo);
      qmemcpy(*v40, bits, 17);
      v41 = length <= 16;
      qmemcpy((char *)*v40 + 17, huffval, 256);
      v11 = next_input_byte;
      v10 = bytes_in_buffer;
      err = datasrc;
    }
    while ( !v41 );
    v9 = length;
  }
  if ( v9 != 0 )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
    err = datasrc;
  }
  err->bytes_in_buffer = v10;
  err->next_input_byte = v11;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A9B0
// Name: get_dqt
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall get_dqt@<al>(jpeg_common_struct *cinfo@<edi>)
{
  jpeg_source_mgr *err; // ecx
  const unsigned __int8 *next_input_byte; // ebx
  unsigned int v3; // esi
  int v5; // eax
  const unsigned __int8 *v6; // ebx
  unsigned int v7; // esi
  int v8; // eax
  unsigned int v9; // esi
  const unsigned __int8 *v10; // ebx
  bool v11; // zf
  int v12; // esi
  int v13; // eax
  int v14; // esi
  __int16 v15; // si
  unsigned __int16 v16; // si
  unsigned __int16 *v17; // esi
  jpeg_error_mgr *v18; // eax
  int prec; // [esp+8h] [ebp-18h]
  JQUANT_TBL *quant_ptr; // [esp+Ch] [ebp-14h]
  int quant_ptra; // [esp+Ch] [ebp-14h]
  const int *v22; // [esp+10h] [ebp-10h]
  int length; // [esp+14h] [ebp-Ch]
  int lengtha; // [esp+14h] [ebp-Ch]
  jpeg_source_mgr *datasrc; // [esp+18h] [ebp-8h]
  unsigned int bytes_in_buffer; // [esp+1Ch] [ebp-4h]

  err = (jpeg_source_mgr *)cinfo[1].err;
  next_input_byte = err->next_input_byte;
  v3 = err->bytes_in_buffer;
  datasrc = err;
  if ( v3 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    next_input_byte = datasrc->next_input_byte;
    v3 = datasrc->bytes_in_buffer;
    err = datasrc;
  }
  v5 = *next_input_byte << 8;
  v6 = next_input_byte + 1;
  v7 = v3 - 1;
  length = v5;
  if ( v7 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v6 = datasrc->next_input_byte;
    err = datasrc;
    v7 = datasrc->bytes_in_buffer;
    v5 = length;
  }
  v8 = *v6 + v5 - 2;
  v9 = v7 - 1;
  v10 = v6 + 1;
  lengtha = v8;
  v11 = v8 == 0;
  if ( v8 > 0 )
  {
    do
    {
      if ( v9 == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v10 = datasrc->next_input_byte;
        v9 = datasrc->bytes_in_buffer;
      }
      bytes_in_buffer = v9 - 1;
      v12 = *v10;
      cinfo->err->msg_code = 81;
      v13 = v12 >> 4;
      v14 = v12 & 0xF;
      cinfo->err->msg_parm.i[0] = v14;
      cinfo->err->msg_parm.i[1] = v13;
      prec = v13;
      ++v10;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      if ( v14 >= 4 )
      {
        cinfo->err->msg_code = 31;
        cinfo->err->msg_parm.i[0] = v14;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *((_DWORD *)&cinfo[6].err + v14) == 0 )
        *((_DWORD *)&cinfo[6].err + v14) = jpeg_alloc_quant_table(cinfo);
      quant_ptr = *((JQUANT_TBL **)&cinfo[6].err + v14);
      v22 = jpeg_natural_order;
      do
      {
        if ( prec != 0 )
        {
          if ( bytes_in_buffer == 0 )
          {
            if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
              return 0;
            v10 = datasrc->next_input_byte;
            bytes_in_buffer = datasrc->bytes_in_buffer;
          }
          v15 = *v10++ << 8;
          if ( --bytes_in_buffer == 0 )
          {
            if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
              return 0;
            v10 = datasrc->next_input_byte;
            bytes_in_buffer = datasrc->bytes_in_buffer;
          }
          v16 = *v10 + v15;
        }
        else
        {
          if ( bytes_in_buffer == 0 )
          {
            if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
              return 0;
            v10 = datasrc->next_input_byte;
            bytes_in_buffer = datasrc->bytes_in_buffer;
          }
          v16 = *v10;
        }
        --bytes_in_buffer;
        ++v10;
        quant_ptr->quantval[*v22++] = v16;
      }
      while ( (int)v22 < (int)dword_1012FB08 );
      if ( cinfo->err->trace_level >= 2 )
      {
        v17 = &quant_ptr->quantval[2];
        for ( quant_ptra = 8; quant_ptra != 0; --quant_ptra )
        {
          v18 = cinfo->err;
          v18->msg_parm.i[0] = *(v17 - 2);
          v18->msg_parm.i[1] = *(v17 - 1);
          v18->msg_parm.i[2] = *v17;
          v18->msg_parm.i[3] = v17[1];
          v18->msg_parm.i[4] = v17[2];
          v18->msg_parm.i[5] = v17[3];
          v18->msg_parm.i[6] = v17[4];
          v18->msg_parm.i[7] = v17[5];
          cinfo->err->msg_code = 93;
          cinfo->err->emit_message(a1: cinfo, a2: 2);
          v17 += 8;
        }
      }
      lengtha -= 65;
      if ( prec != 0 )
        lengtha -= 64;
      v9 = bytes_in_buffer;
      err = datasrc;
    }
    while ( lengtha > 0 );
    v11 = lengtha == 0;
  }
  if ( !v11 )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
    err = datasrc;
  }
  err->bytes_in_buffer = v9;
  err->next_input_byte = v10;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000AC20
// Name: get_dri
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl get_dri(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // eax
  jpeg_source_mgr *src; // ebx
  const unsigned __int8 *next_input_byte; // esi
  unsigned int bytes_in_buffer; // edi
  int v6; // ecx
  const unsigned __int8 *v7; // esi
  unsigned int v8; // edi
  int v9; // ecx
  unsigned int v10; // edi
  const unsigned __int8 *v11; // esi
  int v12; // ecx
  const unsigned __int8 *v13; // esi
  unsigned int v14; // edi
  unsigned int v15; // ecx
  int length; // [esp+Ch] [ebp-4h]
  int lengtha; // [esp+Ch] [ebp-4h]
  unsigned int lengthb; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  src = cinfo->src;
  next_input_byte = src->next_input_byte;
  bytes_in_buffer = src->bytes_in_buffer;
  if ( bytes_in_buffer == 0 )
  {
    if ( src->fill_input_buffer(a1: cinfo) == 0 )
      return 0;
    next_input_byte = src->next_input_byte;
    bytes_in_buffer = src->bytes_in_buffer;
    v1 = cinfo;
  }
  v6 = *next_input_byte << 8;
  v7 = next_input_byte + 1;
  v8 = bytes_in_buffer - 1;
  length = v6;
  if ( v8 == 0 )
  {
    if ( src->fill_input_buffer(a1: v1) == 0 )
      return 0;
    v7 = src->next_input_byte;
    v8 = src->bytes_in_buffer;
    v1 = cinfo;
    v6 = length;
  }
  v9 = *v7 + v6;
  v10 = v8 - 1;
  v11 = v7 + 1;
  if ( v9 != 4 )
  {
    v1->err->msg_code = 11;
    v1->err->error_exit(a1: (jpeg_common_struct *)v1);
    v1 = cinfo;
  }
  if ( v10 == 0 )
  {
    if ( src->fill_input_buffer(a1: v1) == 0 )
      return 0;
    v11 = src->next_input_byte;
    v10 = src->bytes_in_buffer;
    v1 = cinfo;
  }
  v12 = *v11 << 8;
  v13 = v11 + 1;
  v14 = v10 - 1;
  lengtha = v12;
  if ( v14 == 0 )
  {
    if ( src->fill_input_buffer(a1: v1) == 0 )
      return 0;
    v13 = src->next_input_byte;
    v14 = src->bytes_in_buffer;
    v1 = cinfo;
    v12 = lengtha;
  }
  v15 = *v13 + v12;
  v1->err->msg_code = 82;
  v1->err->msg_parm.i[0] = v15;
  lengthb = v15;
  v1->err->emit_message(a1: (jpeg_common_struct *)v1, a2: 1);
  cinfo->restart_interval = lengthb;
  src->bytes_in_buffer = v14 - 1;
  src->next_input_byte = v13 + 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000AD20
// Name: examine_app0
// Source: json
//------------------------------------------------------------------------------
void __usercall examine_app0(
        jpeg_common_struct *cinfo@<esi>,
        unsigned __int8 *data@<edi>,
        unsigned int datalen@<eax>,
        int remaining@<ecx>)
{
  int v4; // ebx
  bool v5; // zf
  jpeg_error_mgr *err; // eax
  int v7; // ebx
  jpeg_error_mgr *v8; // ecx

  v4 = datalen + remaining;
  if ( datalen >= 0xE && *data == 74 && data[1] == 70 && data[2] == 73 && data[3] == 70 && data[4] == 0 )
  {
    cinfo[10].is_decompressor = 1;
    *(&cinfo[10].is_decompressor + 1) = data[5];
    *(&cinfo[10].is_decompressor + 2) = data[6];
    *(&cinfo[10].is_decompressor + 3) = data[7];
    LOWORD(cinfo[10].global_state) = data[9] + (data[8] << 8);
    v5 = *(&cinfo[10].is_decompressor + 1) == 1;
    HIWORD(cinfo[10].global_state) = data[11] + (data[10] << 8);
    if ( !v5 )
    {
      cinfo->err->msg_code = 119;
      cinfo->err->msg_parm.i[0] = *(&cinfo[10].is_decompressor + 1);
      cinfo->err->msg_parm.i[1] = *(&cinfo[10].is_decompressor + 2);
      cinfo->err->emit_message(a1: cinfo, a2: -1);
    }
    err = cinfo->err;
    err->msg_parm.i[0] = *(&cinfo[10].is_decompressor + 1);
    err->msg_parm.i[1] = *(&cinfo[10].is_decompressor + 2);
    err->msg_parm.i[2] = LOWORD(cinfo[10].global_state);
    err->msg_parm.i[3] = HIWORD(cinfo[10].global_state);
    err->msg_parm.i[4] = *(&cinfo[10].is_decompressor + 3);
    cinfo->err->msg_code = 87;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
    if ( *((_WORD *)data + 6) != 0 )
    {
      cinfo->err->msg_code = 90;
      cinfo->err->msg_parm.i[0] = data[12];
      cinfo->err->msg_parm.i[1] = data[13];
      cinfo->err->emit_message(a1: cinfo, a2: 1);
    }
    v7 = v4 - 14;
    if ( v7 != 3 * data[13] * data[12] )
    {
      cinfo->err->msg_code = 88;
      cinfo->err->msg_parm.i[0] = v7;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
    }
  }
  else if ( datalen >= 6 && *data == 74 && data[1] == 70 && data[2] == 88 && data[3] == 88 && data[4] == 0 )
  {
    if ( data[5] == 16 )
    {
      cinfo->err->msg_code = 108;
      cinfo->err->msg_parm.i[0] = v4;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
    }
    else if ( data[5] == 17 )
    {
      cinfo->err->msg_code = 109;
      cinfo->err->msg_parm.i[0] = v4;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
    }
    else
    {
      v8 = cinfo->err;
      if ( data[5] == 19 )
      {
        v8->msg_code = 110;
        cinfo->err->msg_parm.i[0] = v4;
      }
      else
      {
        v8->msg_code = 89;
        cinfo->err->msg_parm.i[0] = data[5];
        cinfo->err->msg_parm.i[1] = v4;
      }
      cinfo->err->emit_message(a1: cinfo, a2: 1);
    }
  }
  else
  {
    cinfo->err->msg_code = 77;
    cinfo->err->msg_parm.i[0] = v4;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AF80
// Name: examine_app14
// Source: json
//------------------------------------------------------------------------------
void __usercall examine_app14(
        jpeg_common_struct *cinfo@<esi>,
        unsigned __int8 *data@<eax>,
        unsigned int datalen@<ecx>,
        int remaining)
{
  int v4; // edx
  int v5; // edi
  jpeg_error_mgr *err; // ecx
  unsigned int transform; // [esp+0h] [ebp-4h]

  if ( datalen >= 0xC && *data == 65 && data[1] == 100 && data[2] == 111 && data[3] == 98 && data[4] == 101 )
  {
    v4 = data[8] + (data[7] << 8);
    v5 = data[10] + (data[9] << 8);
    transform = data[11];
    err = cinfo->err;
    err->msg_parm.i[0] = data[6] + (data[5] << 8);
    err->msg_parm.i[1] = v4;
    err->msg_parm.i[2] = v5;
    err->msg_parm.i[3] = transform;
    cinfo->err->msg_code = 76;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
    BYTE1(cinfo[11].err) = transform;
    LOBYTE(cinfo[11].err) = 1;
  }
  else
  {
    cinfo->err->msg_code = 78;
    cinfo->err->msg_parm.i[0] = remaining + datalen;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B040
// Name: get_interesting_appn
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl get_interesting_appn(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // esi
  unsigned int v2; // ecx
  const unsigned __int8 *next_input_byte; // ebx
  unsigned __int8 result; // al
  int v5; // edi
  const unsigned __int8 *v6; // ebx
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  int v9; // edi
  unsigned __int8 *v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  int v14; // ecx
  unsigned int v15; // edx
  unsigned __int8 b[16]; // [esp+8h] [ebp-20h] BYREF
  jpeg_source_mgr *datasrc; // [esp+18h] [ebp-10h]
  int length; // [esp+1Ch] [ebp-Ch]
  unsigned int numtoread; // [esp+20h] [ebp-8h]
  unsigned int bytes_in_buffer; // [esp+24h] [ebp-4h]

  err = (jpeg_source_mgr *)cinfo[1].err;
  v2 = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  datasrc = err;
  if ( v2 == 0 )
  {
    result = err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo);
    if ( result == 0 )
      return result;
    next_input_byte = err->next_input_byte;
    v2 = err->bytes_in_buffer;
  }
  v5 = *next_input_byte << 8;
  v6 = next_input_byte + 1;
  v7 = v2 - 1;
  if ( v7 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v6 = err->next_input_byte;
    v7 = err->bytes_in_buffer;
  }
  v8 = v7 - 1;
  v9 = *v6 + v5 - 2;
  v10 = (unsigned __int8 *)(v6 + 1);
  bytes_in_buffer = v8;
  if ( v9 < 14 )
  {
    v11 = v9 <= 0 ? 0 : v9;
    numtoread = v11;
  }
  else
  {
    v11 = 14;
    numtoread = 14;
  }
  v12 = 0;
  length = 0;
  if ( v11 != 0 )
  {
    do
    {
      if ( v8 == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v10 = (unsigned __int8 *)err->next_input_byte;
        v12 = length;
        v8 = err->bytes_in_buffer;
      }
      b[v12] = *v10;
      v11 = numtoread;
      ++v12;
      --v8;
      ++v10;
      bytes_in_buffer = v8;
      length = v12;
    }
    while ( v12 < numtoread );
  }
  v13 = v9 - v11;
  v14 = cinfo[15].global_state - 224;
  length = v13;
  if ( v14 == 0 )
  {
    examine_app0(cinfo, data: b, datalen: v11, remaining: v13);
    v13 = length;
    goto LABEL_21;
  }
  if ( v14 == 14 )
  {
    examine_app14(cinfo, data: b, datalen: v11, remaining: v13);
LABEL_21:
    err = datasrc;
    goto LABEL_22;
  }
  cinfo->err->msg_code = 68;
  cinfo->err->msg_parm.i[0] = cinfo[15].global_state;
  cinfo->err->error_exit(a1: cinfo);
LABEL_22:
  v15 = bytes_in_buffer;
  err->next_input_byte = v10;
  err->bytes_in_buffer = v15;
  if ( v13 > 0 )
    ((void (__cdecl *)(jpeg_common_struct *, int))cinfo[1].err->reset_error_mgr)(a1: cinfo, a2: v13);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B190
// Name: skip_variable
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl skip_variable(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // edi
  unsigned int v3; // ecx
  const unsigned __int8 *next_input_byte; // ebx
  int v6; // eax
  const unsigned __int8 *v7; // ebx
  int v8; // ecx
  int v9; // eax
  int length; // [esp+Ch] [ebp-4h]
  int lengtha; // [esp+Ch] [ebp-4h]
  unsigned int bytes_in_buffer; // [esp+18h] [ebp+8h]

  err = (jpeg_source_mgr *)cinfo[1].err;
  v3 = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  if ( v3 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    next_input_byte = err->next_input_byte;
    v3 = err->bytes_in_buffer;
  }
  v6 = *next_input_byte << 8;
  v7 = next_input_byte + 1;
  bytes_in_buffer = v3 - 1;
  length = v6;
  if ( v3 == 1 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v7 = err->next_input_byte;
    bytes_in_buffer = err->bytes_in_buffer;
    v6 = length;
  }
  v8 = *v7;
  cinfo->err->msg_code = 91;
  v9 = v6 + v8 - 2;
  cinfo->err->msg_parm.i[0] = cinfo[15].global_state;
  cinfo->err->msg_parm.i[1] = v9;
  lengtha = v9;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  err->next_input_byte = v7 + 1;
  err->bytes_in_buffer = bytes_in_buffer - 1;
  if ( lengtha > 0 )
    ((void (__cdecl *)(jpeg_common_struct *, int))cinfo[1].err->reset_error_mgr)(a1: cinfo, a2: lengtha);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B250
// Name: next_marker
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl next_marker(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // ecx
  jpeg_source_mgr *err; // ebx
  const unsigned __int8 *next_input_byte; // esi
  unsigned int i; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int c; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  err = (jpeg_source_mgr *)cinfo[1].err;
  next_input_byte = err->next_input_byte;
  for ( i = err->bytes_in_buffer; ; err->bytes_in_buffer = i )
  {
    if ( i == 0 )
    {
      if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)v1) == 0 )
        return 0;
      next_input_byte = err->next_input_byte;
      i = err->bytes_in_buffer;
      v1 = cinfo;
    }
    v5 = *next_input_byte;
    --i;
    ++next_input_byte;
    if ( v5 == 255 )
      goto LABEL_10;
    do
    {
      ++*(_DWORD *)(v1[16].global_state + 20);
      err->next_input_byte = next_input_byte;
      err->bytes_in_buffer = i;
      if ( i == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)v1) == 0 )
          return 0;
        next_input_byte = err->next_input_byte;
        i = err->bytes_in_buffer;
        v1 = cinfo;
      }
      v6 = *next_input_byte;
      --i;
      ++next_input_byte;
    }
    while ( v6 != 255 );
    do
    {
LABEL_10:
      if ( i == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)v1) == 0 )
          return 0;
        next_input_byte = err->next_input_byte;
        i = err->bytes_in_buffer;
        v1 = cinfo;
      }
      v7 = *next_input_byte;
      --i;
      ++next_input_byte;
      c = v7;
    }
    while ( v7 == 255 );
    if ( v7 != 0 )
      break;
    *(_DWORD *)(v1[16].global_state + 20) += 2;
    err->next_input_byte = next_input_byte;
  }
  if ( *(_DWORD *)(v1[16].global_state + 20) != 0 )
  {
    v1->err->msg_code = 116;
    v1->err->msg_parm.i[0] = *(_DWORD *)(v1[16].global_state + 20);
    cinfo->err->msg_parm.i[1] = v7;
    cinfo->err->emit_message(a1: cinfo, a2: -1);
    *(_DWORD *)(cinfo[16].global_state + 20) = 0;
    v7 = c;
    v1 = cinfo;
  }
  v1[15].global_state = v7;
  err->bytes_in_buffer = i;
  err->next_input_byte = next_input_byte;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B370
// Name: first_marker
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl first_marker(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // eax
  jpeg_source_mgr *src; // esi
  const unsigned __int8 *next_input_byte; // ebx
  unsigned int bytes_in_buffer; // edi
  int v6; // ecx
  const unsigned __int8 *v7; // ebx
  unsigned int v8; // edi
  int v9; // edx
  unsigned int v10; // edi
  const unsigned __int8 *v11; // ebx
  int c2; // [esp+Ch] [ebp-4h]
  int c2a; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  src = cinfo->src;
  next_input_byte = src->next_input_byte;
  bytes_in_buffer = src->bytes_in_buffer;
  if ( bytes_in_buffer == 0 )
  {
    if ( src->fill_input_buffer(a1: cinfo) == 0 )
      return 0;
    next_input_byte = src->next_input_byte;
    bytes_in_buffer = src->bytes_in_buffer;
    v1 = cinfo;
  }
  v6 = *next_input_byte;
  v7 = next_input_byte + 1;
  v8 = bytes_in_buffer - 1;
  c2 = v6;
  if ( v8 == 0 )
  {
    if ( src->fill_input_buffer(a1: v1) == 0 )
      return 0;
    v7 = src->next_input_byte;
    v8 = src->bytes_in_buffer;
    v1 = cinfo;
    v6 = c2;
  }
  v9 = *v7;
  v10 = v8 - 1;
  v11 = v7 + 1;
  c2a = v9;
  if ( v6 != 255 || v9 != 216 )
  {
    v1->err->msg_code = 53;
    v1->err->msg_parm.i[0] = v6;
    v1->err->msg_parm.i[1] = v9;
    v1->err->error_exit(a1: (jpeg_common_struct *)v1);
    v1 = cinfo;
    v9 = c2a;
  }
  v1->unread_marker = v9;
  src->bytes_in_buffer = v10;
  src->next_input_byte = v11;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B420
// Name: read_markers
// Source: json
//------------------------------------------------------------------------------
int __cdecl read_markers(jpeg_common_struct *cinfo)
{
  unsigned __int8 v1; // al
  int global_state; // eax

  while ( 1 )
  {
    if ( cinfo[15].global_state == 0 )
    {
      v1 = *(_BYTE *)(cinfo[16].global_state + 12) != 0
         ? next_marker(cinfo)
         : first_marker((jpeg_decompress_struct *)cinfo);
      if ( v1 == 0 )
        return 0;
    }
    global_state = cinfo[15].global_state;
    switch ( global_state )
    {
      case 1:
      case 208:
      case 209:
      case 210:
      case 211:
      case 212:
      case 213:
      case 214:
      case 215:
        cinfo->err->msg_code = 92;
        cinfo->err->msg_parm.i[0] = cinfo[15].global_state;
        cinfo->err->emit_message(a1: cinfo, a2: 1);
        cinfo[15].global_state = 0;
        continue;
      case 192:
      case 193:
        if ( get_sof(cinfo, is_prog: 0, is_arith: 0) == 0 )
          return 0;
        cinfo[15].global_state = 0;
        continue;
      case 194:
        if ( get_sof(cinfo, is_prog: 1u, is_arith: 0) == 0 )
          return 0;
        cinfo[15].global_state = 0;
        continue;
      case 195:
      case 197:
      case 198:
      case 199:
      case 200:
      case 203:
      case 205:
      case 206:
      case 207:
        cinfo->err->msg_code = 60;
        cinfo->err->msg_parm.i[0] = cinfo[15].global_state;
        cinfo->err->error_exit(a1: cinfo);
        cinfo[15].global_state = 0;
        continue;
      case 196:
        if ( get_dht(cinfo) == 0 )
          return 0;
        cinfo[15].global_state = 0;
        continue;
      case 201:
        if ( get_sof(cinfo, is_prog: 0, is_arith: 1u) == 0 )
          return 0;
        cinfo[15].global_state = 0;
        continue;
      case 202:
        if ( get_sof(cinfo, is_prog: 1u, is_arith: 1u) == 0 )
          return 0;
        cinfo[15].global_state = 0;
        continue;
      case 204:
      case 220:
        if ( skip_variable(cinfo) == 0 )
          return 0;
        cinfo[15].global_state = 0;
        continue;
      case 216:
        if ( get_soi(cinfo) == 0 )
          return 0;
        goto LABEL_32;
      case 217:
        cinfo->err->msg_code = 85;
        cinfo->err->emit_message(a1: cinfo, a2: 1);
        cinfo[15].global_state = 0;
        return 2;
      case 218:
        if ( get_sos(cinfo) == 0 )
          return 0;
        cinfo[15].global_state = 0;
        return 1;
      case 219:
        if ( get_dqt(cinfo) == 0 )
          return 0;
        cinfo[15].global_state = 0;
        continue;
      case 221:
        if ( get_dri((jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        cinfo[15].global_state = 0;
        continue;
      case 224:
      case 226:
      case 227:
      case 228:
      case 229:
      case 230:
      case 231:
      case 232:
      case 233:
      case 234:
      case 235:
      case 236:
      case 237:
      case 238:
      case 239:
        if ( (*(unsigned __int8 (__cdecl **)(jpeg_common_struct *))(cinfo[16].global_state + 4 * global_state - 868))(a1: cinfo) == 0 )
          return 0;
        cinfo[15].global_state = 0;
        continue;
      case 225:
        return 0;
      case 254:
        if ( (*(unsigned __int8 (__cdecl **)(jpeg_common_struct *))(cinfo[16].global_state + 24))(a1: cinfo) == 0 )
          return 0;
        cinfo[15].global_state = 0;
        continue;
      default:
        cinfo->err->msg_code = 68;
        cinfo->err->msg_parm.i[0] = cinfo[15].global_state;
        cinfo->err->error_exit(a1: cinfo);
LABEL_32:
        cinfo[15].global_state = 0;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B7B0
// Name: read_restart_marker
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl read_restart_marker(jpeg_common_struct *cinfo)
{
  if ( cinfo[15].global_state == 0 && next_marker(cinfo) == 0 )
    return 0;
  if ( cinfo[15].global_state == *(_DWORD *)(cinfo[16].global_state + 16) + 208 )
  {
    cinfo->err->msg_code = 98;
    cinfo->err->msg_parm.i[0] = *(_DWORD *)(cinfo[16].global_state + 16);
    cinfo->err->emit_message(a1: cinfo, a2: 3);
    cinfo[15].global_state = 0;
  }
  else if ( ((unsigned __int8 (__cdecl *)(jpeg_common_struct *, _DWORD))cinfo[1].err->msg_code)(
              a1: cinfo,
              a2: *(_DWORD *)(cinfo[16].global_state + 16)) == 0 )
  {
    return 0;
  }
  *(_DWORD *)(cinfo[16].global_state + 16) = ((unsigned __int8)*(_DWORD *)(cinfo[16].global_state + 16) + 1) & 7;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B840
// Name: reset_marker_reader
// Source: json
//------------------------------------------------------------------------------
void __cdecl reset_marker_reader(jpeg_decompress_struct *cinfo)
{
  jpeg_marker_reader *marker; // eax

  marker = cinfo->marker;
  cinfo->comp_info = nullptr;
  cinfo->input_scan_number = 0;
  cinfo->unread_marker = 0;
  *(_WORD *)&marker->saw_SOI = 0;
  marker->discarded_bytes = 0;
  marker[6].next_restart_num = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000B870
// Name: _jinit_marker_reader
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_marker_reader(jpeg_common_struct *cinfo)
{
  int v1; // eax
  _DWORD *v2; // ecx
  int i; // edx
  jpeg_marker_reader *global_state; // eax

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 168);
  cinfo[16].global_state = v1;
  *(_DWORD *)v1 = reset_marker_reader;
  *(_DWORD *)(v1 + 4) = read_markers;
  *(_DWORD *)(v1 + 8) = read_restart_marker;
  *(_DWORD *)(v1 + 24) = skip_variable;
  *(_DWORD *)(v1 + 92) = 0;
  v2 = (_DWORD *)(v1 + 96);
  for ( i = 16; i != 0; --i )
  {
    *(v2 - 17) = skip_variable;
    *v2++ = 0;
  }
  *(_DWORD *)(v1 + 28) = get_interesting_appn;
  *(_DWORD *)(v1 + 84) = get_interesting_appn;
  global_state = (jpeg_marker_reader *)cinfo[16].global_state;
  cinfo[8].mem = nullptr;
  cinfo[5].mem = nullptr;
  cinfo[15].global_state = 0;
  *(_WORD *)&global_state->saw_SOI = 0;
  global_state->discarded_bytes = 0;
  global_state[6].next_restart_num = 0;
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10272BB0
// Name: get_soi
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall get_soi@<al>(jpeg_common_struct *cinfo@<esi>)
{
  unsigned __int8 *v1; // eax
  int i; // ecx
  jpeg_marker_reader *global_state; // eax

  cinfo->err->msg_code = 102;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  if ( *(_BYTE *)(cinfo[16].global_state + 12) != 0 )
  {
    cinfo->err->msg_code = 61;
    cinfo->err->error_exit(a1: cinfo);
  }
  v1 = (unsigned __int8 *)&cinfo[9].err + 2;
  for ( i = 16; i != 0; --i )
  {
    *(v1 - 16) = 0;
    *v1 = 1;
    v1[16] = 5;
    ++v1;
  }
  global_state = (jpeg_marker_reader *)cinfo[16].global_state;
  cinfo[10].client_data = nullptr;
  *(_DWORD *)&cinfo[1].is_decompressor = 0;
  BYTE2(cinfo[11].err) = 0;
  LOWORD(cinfo[11].err) = 0;
  *(_DWORD *)&cinfo[10].is_decompressor = 65792;
  cinfo[10].global_state = 65537;
  global_state->saw_SOI = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10272C40
// Name: get_sof
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall get_sof@<al>(
        jpeg_common_struct *cinfo@<esi>,
        unsigned __int8 is_prog@<cl>,
        unsigned __int8 is_arith@<dl>)
{
  jpeg_source_mgr *err; // eax
  unsigned int bytes_in_buffer; // ebx
  const unsigned __int8 *next_input_byte; // edi
  int v7; // ecx
  const unsigned __int8 *v8; // edi
  unsigned int v9; // ebx
  const unsigned __int8 *v10; // edi
  unsigned int v11; // ebx
  int v12; // ecx
  const unsigned __int8 *v13; // edi
  unsigned int v14; // ebx
  unsigned int v15; // ecx
  const unsigned __int8 *v16; // edi
  unsigned int v17; // ebx
  const unsigned __int8 *v18; // edi
  unsigned int v19; // ebx
  unsigned int v20; // ecx
  const unsigned __int8 *v21; // edi
  unsigned int v22; // ebx
  const unsigned __int8 *v23; // edi
  unsigned int v24; // ebx
  int global_state; // ecx
  jpeg_error_mgr *v26; // eax
  unsigned int v27; // ebx
  const unsigned __int8 *v28; // edi
  jpeg_component_info *mem; // ecx
  int v30; // edx
  const unsigned __int8 *v31; // edi
  unsigned int v32; // ebx
  int v33; // edx
  int v34; // eax
  const unsigned __int8 *v35; // edi
  unsigned int v36; // ebx
  jpeg_error_mgr *v37; // eax
  int ci; // [esp+8h] [ebp-Ch]
  int length; // [esp+Ch] [ebp-8h]
  int lengtha; // [esp+Ch] [ebp-8h]
  int lengthb; // [esp+Ch] [ebp-8h]
  int lengthc; // [esp+Ch] [ebp-8h]
  jpeg_source_mgr *datasrc; // [esp+10h] [ebp-4h]

  err = (jpeg_source_mgr *)cinfo[1].err;
  bytes_in_buffer = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  datasrc = err;
  LOBYTE(cinfo[8].progress) = is_prog;
  BYTE1(cinfo[8].progress) = is_arith;
  if ( bytes_in_buffer == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    next_input_byte = datasrc->next_input_byte;
    bytes_in_buffer = datasrc->bytes_in_buffer;
  }
  v7 = *next_input_byte << 8;
  v8 = next_input_byte + 1;
  v9 = bytes_in_buffer - 1;
  length = v7;
  if ( v9 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v8 = datasrc->next_input_byte;
    v9 = datasrc->bytes_in_buffer;
  }
  lengtha = *v8 + length;
  v10 = v8 + 1;
  v11 = v9 - 1;
  if ( v11 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v10 = datasrc->next_input_byte;
    v11 = datasrc->bytes_in_buffer;
  }
  v12 = *v10;
  v13 = v10 + 1;
  v14 = v11 - 1;
  cinfo[8].err = (jpeg_error_mgr *)v12;
  if ( v14 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v13 = datasrc->next_input_byte;
    v14 = datasrc->bytes_in_buffer;
  }
  v15 = *v13 << 8;
  v16 = v13 + 1;
  v17 = v14 - 1;
  cinfo[1].progress = (jpeg_progress_mgr *)v15;
  if ( v17 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v16 = datasrc->next_input_byte;
    v17 = datasrc->bytes_in_buffer;
  }
  cinfo[1].progress = (jpeg_progress_mgr *)((char *)cinfo[1].progress + *v16);
  v18 = v16 + 1;
  v19 = v17 - 1;
  if ( v19 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v18 = datasrc->next_input_byte;
    v19 = datasrc->bytes_in_buffer;
  }
  v20 = *v18 << 8;
  v21 = v18 + 1;
  v22 = v19 - 1;
  cinfo[1].mem = (jpeg_memory_mgr *)v20;
  if ( v22 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    err = datasrc;
    v21 = datasrc->next_input_byte;
    v22 = datasrc->bytes_in_buffer;
  }
  cinfo[1].mem = (jpeg_memory_mgr *)((char *)cinfo[1].mem + *v21);
  v23 = v21 + 1;
  v24 = v22 - 1;
  if ( v24 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v23 = datasrc->next_input_byte;
    v24 = datasrc->bytes_in_buffer;
  }
  global_state = cinfo[15].global_state;
  lengthb = lengtha - 8;
  cinfo[1].client_data = (void *)*v23;
  v26 = cinfo->err;
  v26->msg_parm.i[0] = global_state;
  v26->msg_parm.i[1] = (int)cinfo[1].mem;
  v26->msg_parm.i[2] = (int)cinfo[1].progress;
  v26->msg_parm.i[3] = (int)cinfo[1].client_data;
  cinfo->err->msg_code = 100;
  v27 = v24 - 1;
  v28 = v23 + 1;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  if ( *(_BYTE *)(cinfo[16].global_state + 13) != 0 )
  {
    cinfo->err->msg_code = 58;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[1].progress == nullptr || cinfo[1].mem == nullptr || (int)cinfo[1].client_data <= 0 )
  {
    cinfo->err->msg_code = 32;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( lengthb != 3 * (int)cinfo[1].client_data )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[8].mem == nullptr )
    cinfo[8].mem = (jpeg_memory_mgr *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 84 * (int)cinfo[1].client_data);
  mem = (jpeg_component_info *)cinfo[8].mem;
  ci = 0;
  lengthc = (int)mem;
  if ( (int)cinfo[1].client_data > 0 )
  {
    while ( 1 )
    {
      mem->component_index = ci;
      if ( v27 == 0 )
      {
        if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v28 = datasrc->next_input_byte;
        v27 = datasrc->bytes_in_buffer;
        mem = (jpeg_component_info *)lengthc;
      }
      v30 = *v28;
      v31 = v28 + 1;
      v32 = v27 - 1;
      mem->component_id = v30;
      if ( v32 == 0 )
      {
        if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v31 = datasrc->next_input_byte;
        v32 = datasrc->bytes_in_buffer;
        mem = (jpeg_component_info *)lengthc;
      }
      v33 = (int)*v31 >> 4;
      v34 = *v31 & 0xF;
      v35 = v31 + 1;
      v36 = v32 - 1;
      mem->h_samp_factor = v33;
      mem->v_samp_factor = v34;
      if ( v36 == 0 )
      {
        if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v35 = datasrc->next_input_byte;
        v36 = datasrc->bytes_in_buffer;
        mem = (jpeg_component_info *)lengthc;
      }
      mem->quant_tbl_no = *v35;
      v37 = cinfo->err;
      v37->msg_parm.i[0] = mem->component_id;
      v37->msg_parm.i[1] = mem->h_samp_factor;
      v37->msg_parm.i[2] = mem->v_samp_factor;
      v37->msg_parm.i[3] = mem->quant_tbl_no;
      cinfo->err->msg_code = 101;
      v27 = v36 - 1;
      v28 = v35 + 1;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      lengthc += 84;
      if ( ++ci >= (int)cinfo[1].client_data )
        break;
      mem = (jpeg_component_info *)lengthc;
    }
  }
  *(_BYTE *)(cinfo[16].global_state + 13) = 1;
  datasrc->next_input_byte = v28;
  datasrc->bytes_in_buffer = v27;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10272F40
// Name: get_sos
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall get_sos@<al>(jpeg_common_struct *cinfo@<esi>)
{
  jpeg_source_mgr *err; // ecx
  const unsigned __int8 *next_input_byte; // ebx
  unsigned int v3; // edi
  int v5; // eax
  const unsigned __int8 *v6; // ebx
  unsigned int v7; // edi
  int v8; // edx
  const unsigned __int8 *v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  unsigned int v12; // edi
  const unsigned __int8 *v13; // ebx
  int v14; // eax
  int v15; // edx
  const unsigned __int8 *v16; // ebx
  unsigned int v17; // edi
  int v18; // eax
  int v19; // ecx
  jpeg_component_info *mem; // edi
  jpeg_error_mgr *v21; // eax
  int v22; // eax
  const unsigned __int8 *v23; // ebx
  unsigned int v24; // edi
  int v25; // eax
  const unsigned __int8 *v26; // ebx
  unsigned int v27; // edi
  int v28; // edx
  int v29; // ecx
  jpeg_error_mgr *v30; // eax
  int c; // [esp+8h] [ebp-1Ch]
  int i; // [esp+Ch] [ebp-18h]
  int n; // [esp+10h] [ebp-14h]
  jpeg_component_info **p_progress; // [esp+14h] [ebp-10h]
  int cc; // [esp+18h] [ebp-Ch]
  int cca; // [esp+18h] [ebp-Ch]
  int ccb; // [esp+18h] [ebp-Ch]
  jpeg_source_mgr *datasrc; // [esp+1Ch] [ebp-8h]
  unsigned int bytes_in_buffer; // [esp+20h] [ebp-4h]

  err = (jpeg_source_mgr *)cinfo[1].err;
  next_input_byte = err->next_input_byte;
  v3 = err->bytes_in_buffer;
  datasrc = err;
  if ( *(_BYTE *)(cinfo[16].global_state + 13) == 0 )
  {
    cinfo->err->msg_code = 62;
    cinfo->err->error_exit(a1: cinfo);
    err = datasrc;
  }
  if ( v3 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    next_input_byte = datasrc->next_input_byte;
    v3 = datasrc->bytes_in_buffer;
    err = datasrc;
  }
  v5 = *next_input_byte << 8;
  v6 = next_input_byte + 1;
  v7 = v3 - 1;
  cc = v5;
  if ( v7 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v6 = datasrc->next_input_byte;
    v7 = datasrc->bytes_in_buffer;
    err = datasrc;
    v5 = cc;
  }
  v8 = *v6;
  v9 = v6 + 1;
  v10 = v7 - 1;
  cca = v8 + v5;
  if ( v10 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v9 = datasrc->next_input_byte;
    v10 = datasrc->bytes_in_buffer;
  }
  v11 = *v9;
  cinfo->err->msg_code = 103;
  cinfo->err->msg_parm.i[0] = v11;
  n = v11;
  v12 = v10 - 1;
  v13 = v9 + 1;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  v14 = n;
  if ( cca != 2 * n + 6 || n < 1 || n > 4 )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
    v14 = n;
  }
  cinfo[12].mem = (jpeg_memory_mgr *)v14;
  i = 0;
  if ( v14 > 0 )
  {
    p_progress = (jpeg_component_info **)&cinfo[12].progress;
    do
    {
      if ( v12 == 0 )
      {
        if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v13 = datasrc->next_input_byte;
        v12 = datasrc->bytes_in_buffer;
      }
      v15 = *v13;
      v16 = v13 + 1;
      v17 = v12 - 1;
      ccb = v15;
      if ( v17 == 0 )
      {
        if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v16 = datasrc->next_input_byte;
        v17 = datasrc->bytes_in_buffer;
      }
      v18 = *v16;
      v19 = 0;
      v13 = v16 + 1;
      bytes_in_buffer = v17 - 1;
      mem = (jpeg_component_info *)cinfo[8].mem;
      c = v18;
      if ( (int)cinfo[1].client_data <= 0 )
      {
LABEL_28:
        cinfo->err->msg_code = 5;
        cinfo->err->msg_parm.i[0] = ccb;
        cinfo->err->error_exit(a1: cinfo);
        v18 = c;
      }
      else
      {
        while ( ccb != mem->component_id )
        {
          ++v19;
          ++mem;
          if ( v19 >= (int)cinfo[1].client_data )
            goto LABEL_28;
        }
      }
      *p_progress = mem;
      mem->dc_tbl_no = (v18 >> 4) & 0xF;
      mem->ac_tbl_no = v18 & 0xF;
      v21 = cinfo->err;
      v21->msg_parm.i[0] = ccb;
      v21->msg_parm.i[1] = mem->dc_tbl_no;
      v21->msg_parm.i[2] = mem->ac_tbl_no;
      cinfo->err->msg_code = 104;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      ++p_progress;
      v12 = bytes_in_buffer;
      ++i;
    }
    while ( i < n );
  }
  if ( v12 == 0 )
  {
    if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v13 = datasrc->next_input_byte;
    v12 = datasrc->bytes_in_buffer;
  }
  v22 = *v13;
  v23 = v13 + 1;
  v24 = v12 - 1;
  cinfo[15].mem = (jpeg_memory_mgr *)v22;
  if ( v24 == 0 )
  {
    if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v23 = datasrc->next_input_byte;
    v24 = datasrc->bytes_in_buffer;
  }
  v25 = *v23;
  v26 = v23 + 1;
  v27 = v24 - 1;
  cinfo[15].progress = (jpeg_progress_mgr *)v25;
  if ( v27 == 0 )
  {
    if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v26 = datasrc->next_input_byte;
    v27 = datasrc->bytes_in_buffer;
  }
  v28 = (int)cinfo[15].mem;
  v29 = (int)*v26 >> 4;
  *(_DWORD *)&cinfo[15].is_decompressor = *v26 & 0xF;
  v30 = cinfo->err;
  cinfo[15].client_data = (void *)v29;
  v30->msg_parm.i[0] = v28;
  v30->msg_parm.i[1] = (int)cinfo[15].progress;
  v30->msg_parm.i[2] = (int)cinfo[15].client_data;
  v30->msg_parm.i[3] = *(_DWORD *)&cinfo[15].is_decompressor;
  cinfo->err->msg_code = 105;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  *(_DWORD *)(cinfo[16].global_state + 16) = 0;
  ++cinfo[5].mem;
  datasrc->bytes_in_buffer = v27 - 1;
  datasrc->next_input_byte = v26 + 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10273220
// Name: get_dht
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl get_dht(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // ecx
  const unsigned __int8 *v3; // esi
  unsigned int v4; // edi
  int v6; // eax
  const unsigned __int8 *v7; // esi
  unsigned int v8; // edi
  int v9; // eax
  unsigned int v10; // edi
  const unsigned __int8 *v11; // esi
  int v12; // eax
  unsigned int v13; // edi
  unsigned __int8 *v14; // esi
  int v15; // eax
  jpeg_source_mgr *v16; // esi
  unsigned int v17; // ecx
  unsigned __int8 v18; // dl
  jpeg_error_mgr *v19; // eax
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  int v24; // ecx
  int v25; // edx
  int v26; // ecx
  jpeg_error_mgr *v27; // eax
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  int v31; // edx
  int v32; // ecx
  int v33; // edx
  int v34; // ecx
  int v35; // ecx
  int v36; // eax
  jpeg_source_mgr *v37; // esi
  unsigned int v38; // ecx
  unsigned int v39; // eax
  void **v40; // esi
  bool v41; // cc
  unsigned __int8 huffval[256]; // [esp+Ch] [ebp-12Ch]
  int index; // [esp+10Ch] [ebp-2Ch]
  unsigned __int8 bits[20]; // [esp+110h] [ebp-28h]
  int i; // [esp+124h] [ebp-14h]
  int count; // [esp+128h] [ebp-10h]
  int length; // [esp+12Ch] [ebp-Ch]
  jpeg_source_mgr *datasrc; // [esp+130h] [ebp-8h]
  unsigned int bytes_in_buffer; // [esp+134h] [ebp-4h]
  const unsigned __int8 *next_input_byte; // [esp+140h] [ebp+8h]

  err = (jpeg_source_mgr *)cinfo[1].err;
  v3 = err->next_input_byte;
  v4 = err->bytes_in_buffer;
  datasrc = err;
  if ( v4 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v3 = datasrc->next_input_byte;
    v4 = datasrc->bytes_in_buffer;
    err = datasrc;
  }
  v6 = *v3 << 8;
  v7 = v3 + 1;
  v8 = v4 - 1;
  length = v6;
  if ( v8 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v6 = length;
    v7 = datasrc->next_input_byte;
    err = datasrc;
    v8 = datasrc->bytes_in_buffer;
  }
  v9 = *v7 + v6 - 2;
  v10 = v8 - 1;
  v11 = v7 + 1;
  length = v9;
  if ( v9 > 16 )
  {
    do
    {
      if ( v10 == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v11 = datasrc->next_input_byte;
        v10 = datasrc->bytes_in_buffer;
      }
      v12 = *v11;
      cinfo->err->msg_code = 80;
      cinfo->err->msg_parm.i[0] = v12;
      index = v12;
      v13 = v10 - 1;
      v14 = (unsigned __int8 *)(v11 + 1);
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      v15 = 1;
      bits[0] = 0;
      count = 0;
      i = 1;
      do
      {
        if ( v13 == 0 )
        {
          v16 = datasrc;
          if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
            return 0;
          v17 = v16->bytes_in_buffer;
          v14 = (unsigned __int8 *)v16->next_input_byte;
          v15 = i;
          v13 = v17;
        }
        v18 = *v14;
        count += *v14;
        bits[v15++] = v18;
        --v13;
        ++v14;
        bytes_in_buffer = v13;
        next_input_byte = v14;
        i = v15;
      }
      while ( v15 <= 16 );
      v19 = cinfo->err;
      v20 = bits[2];
      length -= 17;
      v19->msg_parm.i[0] = bits[1];
      v21 = bits[3];
      v19->msg_parm.i[1] = v20;
      v22 = bits[4];
      v19->msg_parm.i[2] = v21;
      v23 = bits[5];
      v19->msg_parm.i[3] = v22;
      v24 = bits[6];
      v19->msg_parm.i[4] = v23;
      v25 = bits[7];
      v19->msg_parm.i[5] = v24;
      v26 = bits[8];
      v19->msg_parm.i[6] = v25;
      v19->msg_parm.i[7] = v26;
      cinfo->err->msg_code = 86;
      cinfo->err->emit_message(a1: cinfo, a2: 2);
      v27 = cinfo->err;
      v28 = bits[10];
      v27->msg_parm.i[0] = bits[9];
      v29 = bits[11];
      v27->msg_parm.i[1] = v28;
      v30 = bits[12];
      v27->msg_parm.i[2] = v29;
      v31 = bits[13];
      v27->msg_parm.i[3] = v30;
      v32 = bits[14];
      v27->msg_parm.i[4] = v31;
      v33 = bits[15];
      v27->msg_parm.i[5] = v32;
      v34 = bits[16];
      v27->msg_parm.i[6] = v33;
      v27->msg_parm.i[7] = v34;
      cinfo->err->msg_code = 86;
      cinfo->err->emit_message(a1: cinfo, a2: 2);
      v35 = count;
      if ( count > 256 || count > length )
      {
        cinfo->err->msg_code = 8;
        cinfo->err->error_exit(a1: cinfo);
        v35 = count;
      }
      v36 = 0;
      for ( i = 0; v36 < v35; i = v36 )
      {
        if ( v13 == 0 )
        {
          v37 = datasrc;
          if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
            return 0;
          v38 = v37->bytes_in_buffer;
          v14 = (unsigned __int8 *)v37->next_input_byte;
          v36 = i;
          v13 = v38;
          v35 = count;
        }
        huffval[v36++] = *v14;
        --v13;
        ++v14;
        bytes_in_buffer = v13;
        next_input_byte = v14;
      }
      v39 = index;
      length -= v35;
      if ( (index & 0x10) != 0 )
      {
        v39 = index - 16;
        v40 = (void **)(&cinfo[4].is_decompressor + 4 * index);
      }
      else
      {
        v40 = (void **)(&cinfo[6].is_decompressor + 4 * index);
      }
      if ( v39 >= 4 )
      {
        cinfo->err->msg_code = 30;
        cinfo->err->msg_parm.i[0] = v39;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *v40 == nullptr )
        *v40 = jpeg_alloc_huff_table(cinfo);
      qmemcpy(*v40, bits, 17);
      v41 = length <= 16;
      qmemcpy((char *)*v40 + 17, huffval, 256);
      v11 = next_input_byte;
      v10 = bytes_in_buffer;
      err = datasrc;
    }
    while ( !v41 );
    v9 = length;
  }
  if ( v9 != 0 )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
    err = datasrc;
  }
  err->bytes_in_buffer = v10;
  err->next_input_byte = v11;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10273510
// Name: get_dqt
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall get_dqt@<al>(jpeg_common_struct *cinfo@<edi>)
{
  jpeg_source_mgr *err; // ecx
  const unsigned __int8 *next_input_byte; // ebx
  unsigned int v3; // esi
  int v5; // eax
  const unsigned __int8 *v6; // ebx
  unsigned int v7; // esi
  int v8; // eax
  unsigned int v9; // esi
  const unsigned __int8 *v10; // ebx
  bool v11; // zf
  int v12; // esi
  int v13; // eax
  int v14; // esi
  __int16 v15; // si
  unsigned __int16 v16; // si
  unsigned __int16 *v17; // esi
  jpeg_error_mgr *v18; // eax
  int prec; // [esp+8h] [ebp-18h]
  JQUANT_TBL *quant_ptr; // [esp+Ch] [ebp-14h]
  int quant_ptra; // [esp+Ch] [ebp-14h]
  const int *v22; // [esp+10h] [ebp-10h]
  int length; // [esp+14h] [ebp-Ch]
  int lengtha; // [esp+14h] [ebp-Ch]
  jpeg_source_mgr *datasrc; // [esp+18h] [ebp-8h]
  unsigned int bytes_in_buffer; // [esp+1Ch] [ebp-4h]

  err = (jpeg_source_mgr *)cinfo[1].err;
  next_input_byte = err->next_input_byte;
  v3 = err->bytes_in_buffer;
  datasrc = err;
  if ( v3 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    next_input_byte = datasrc->next_input_byte;
    v3 = datasrc->bytes_in_buffer;
    err = datasrc;
  }
  v5 = *next_input_byte << 8;
  v6 = next_input_byte + 1;
  v7 = v3 - 1;
  length = v5;
  if ( v7 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v6 = datasrc->next_input_byte;
    err = datasrc;
    v7 = datasrc->bytes_in_buffer;
    v5 = length;
  }
  v8 = *v6 + v5 - 2;
  v9 = v7 - 1;
  v10 = v6 + 1;
  lengtha = v8;
  v11 = v8 == 0;
  if ( v8 > 0 )
  {
    do
    {
      if ( v9 == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v10 = datasrc->next_input_byte;
        v9 = datasrc->bytes_in_buffer;
      }
      bytes_in_buffer = v9 - 1;
      v12 = *v10;
      cinfo->err->msg_code = 81;
      v13 = v12 >> 4;
      v14 = v12 & 0xF;
      cinfo->err->msg_parm.i[0] = v14;
      cinfo->err->msg_parm.i[1] = v13;
      prec = v13;
      ++v10;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      if ( v14 >= 4 )
      {
        cinfo->err->msg_code = 31;
        cinfo->err->msg_parm.i[0] = v14;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( *((_DWORD *)&cinfo[6].err + v14) == 0 )
        *((_DWORD *)&cinfo[6].err + v14) = jpeg_alloc_quant_table(cinfo);
      quant_ptr = *((JQUANT_TBL **)&cinfo[6].err + v14);
      v22 = jpeg_natural_order;
      do
      {
        if ( prec != 0 )
        {
          if ( bytes_in_buffer == 0 )
          {
            if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
              return 0;
            v10 = datasrc->next_input_byte;
            bytes_in_buffer = datasrc->bytes_in_buffer;
          }
          v15 = *v10++ << 8;
          if ( --bytes_in_buffer == 0 )
          {
            if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
              return 0;
            v10 = datasrc->next_input_byte;
            bytes_in_buffer = datasrc->bytes_in_buffer;
          }
          v16 = *v10 + v15;
        }
        else
        {
          if ( bytes_in_buffer == 0 )
          {
            if ( datasrc->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
              return 0;
            v10 = datasrc->next_input_byte;
            bytes_in_buffer = datasrc->bytes_in_buffer;
          }
          v16 = *v10;
        }
        --bytes_in_buffer;
        ++v10;
        quant_ptr->quantval[*v22++] = v16;
      }
      while ( (int)v22 < (int)dword_104EAAB8 );
      if ( cinfo->err->trace_level >= 2 )
      {
        v17 = &quant_ptr->quantval[2];
        for ( quant_ptra = 8; quant_ptra != 0; --quant_ptra )
        {
          v18 = cinfo->err;
          v18->msg_parm.i[0] = *(v17 - 2);
          v18->msg_parm.i[1] = *(v17 - 1);
          v18->msg_parm.i[2] = *v17;
          v18->msg_parm.i[3] = v17[1];
          v18->msg_parm.i[4] = v17[2];
          v18->msg_parm.i[5] = v17[3];
          v18->msg_parm.i[6] = v17[4];
          v18->msg_parm.i[7] = v17[5];
          cinfo->err->msg_code = 93;
          cinfo->err->emit_message(a1: cinfo, a2: 2);
          v17 += 8;
        }
      }
      lengtha -= 65;
      if ( prec != 0 )
        lengtha -= 64;
      v9 = bytes_in_buffer;
      err = datasrc;
    }
    while ( lengtha > 0 );
    v11 = lengtha == 0;
  }
  if ( !v11 )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
    err = datasrc;
  }
  err->bytes_in_buffer = v9;
  err->next_input_byte = v10;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10273780
// Name: get_dri
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl get_dri(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // eax
  jpeg_source_mgr *src; // ebx
  const unsigned __int8 *next_input_byte; // esi
  unsigned int bytes_in_buffer; // edi
  int v6; // ecx
  const unsigned __int8 *v7; // esi
  unsigned int v8; // edi
  int v9; // ecx
  unsigned int v10; // edi
  const unsigned __int8 *v11; // esi
  int v12; // ecx
  const unsigned __int8 *v13; // esi
  unsigned int v14; // edi
  unsigned int v15; // ecx
  int length; // [esp+Ch] [ebp-4h]
  int lengtha; // [esp+Ch] [ebp-4h]
  unsigned int lengthb; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  src = cinfo->src;
  next_input_byte = src->next_input_byte;
  bytes_in_buffer = src->bytes_in_buffer;
  if ( bytes_in_buffer == 0 )
  {
    if ( src->fill_input_buffer(a1: cinfo) == 0 )
      return 0;
    next_input_byte = src->next_input_byte;
    bytes_in_buffer = src->bytes_in_buffer;
    v1 = cinfo;
  }
  v6 = *next_input_byte << 8;
  v7 = next_input_byte + 1;
  v8 = bytes_in_buffer - 1;
  length = v6;
  if ( v8 == 0 )
  {
    if ( src->fill_input_buffer(a1: v1) == 0 )
      return 0;
    v7 = src->next_input_byte;
    v8 = src->bytes_in_buffer;
    v1 = cinfo;
    v6 = length;
  }
  v9 = *v7 + v6;
  v10 = v8 - 1;
  v11 = v7 + 1;
  if ( v9 != 4 )
  {
    v1->err->msg_code = 11;
    v1->err->error_exit(a1: (jpeg_common_struct *)v1);
    v1 = cinfo;
  }
  if ( v10 == 0 )
  {
    if ( src->fill_input_buffer(a1: v1) == 0 )
      return 0;
    v11 = src->next_input_byte;
    v10 = src->bytes_in_buffer;
    v1 = cinfo;
  }
  v12 = *v11 << 8;
  v13 = v11 + 1;
  v14 = v10 - 1;
  lengtha = v12;
  if ( v14 == 0 )
  {
    if ( src->fill_input_buffer(a1: v1) == 0 )
      return 0;
    v13 = src->next_input_byte;
    v14 = src->bytes_in_buffer;
    v1 = cinfo;
    v12 = lengtha;
  }
  v15 = *v13 + v12;
  v1->err->msg_code = 82;
  v1->err->msg_parm.i[0] = v15;
  lengthb = v15;
  v1->err->emit_message(a1: (jpeg_common_struct *)v1, a2: 1);
  cinfo->restart_interval = lengthb;
  src->bytes_in_buffer = v14 - 1;
  src->next_input_byte = v13 + 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10273880
// Name: examine_app0
// Source: json
//------------------------------------------------------------------------------
void __usercall examine_app0(
        jpeg_common_struct *cinfo@<esi>,
        unsigned __int8 *data@<edi>,
        unsigned int datalen@<eax>,
        int remaining@<ecx>)
{
  int v4; // ebx
  bool v5; // zf
  jpeg_error_mgr *err; // eax
  int v7; // ebx
  jpeg_error_mgr *v8; // ecx

  v4 = datalen + remaining;
  if ( datalen >= 0xE && *data == 74 && data[1] == 70 && data[2] == 73 && data[3] == 70 && data[4] == 0 )
  {
    cinfo[10].is_decompressor = 1;
    *(&cinfo[10].is_decompressor + 1) = data[5];
    *(&cinfo[10].is_decompressor + 2) = data[6];
    *(&cinfo[10].is_decompressor + 3) = data[7];
    LOWORD(cinfo[10].global_state) = data[9] + (data[8] << 8);
    v5 = *(&cinfo[10].is_decompressor + 1) == 1;
    HIWORD(cinfo[10].global_state) = data[11] + (data[10] << 8);
    if ( !v5 )
    {
      cinfo->err->msg_code = 119;
      cinfo->err->msg_parm.i[0] = *(&cinfo[10].is_decompressor + 1);
      cinfo->err->msg_parm.i[1] = *(&cinfo[10].is_decompressor + 2);
      cinfo->err->emit_message(a1: cinfo, a2: -1);
    }
    err = cinfo->err;
    err->msg_parm.i[0] = *(&cinfo[10].is_decompressor + 1);
    err->msg_parm.i[1] = *(&cinfo[10].is_decompressor + 2);
    err->msg_parm.i[2] = LOWORD(cinfo[10].global_state);
    err->msg_parm.i[3] = HIWORD(cinfo[10].global_state);
    err->msg_parm.i[4] = *(&cinfo[10].is_decompressor + 3);
    cinfo->err->msg_code = 87;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
    if ( *((_WORD *)data + 6) != 0 )
    {
      cinfo->err->msg_code = 90;
      cinfo->err->msg_parm.i[0] = data[12];
      cinfo->err->msg_parm.i[1] = data[13];
      cinfo->err->emit_message(a1: cinfo, a2: 1);
    }
    v7 = v4 - 14;
    if ( v7 != 3 * data[13] * data[12] )
    {
      cinfo->err->msg_code = 88;
      cinfo->err->msg_parm.i[0] = v7;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
    }
  }
  else if ( datalen >= 6 && *data == 74 && data[1] == 70 && data[2] == 88 && data[3] == 88 && data[4] == 0 )
  {
    if ( data[5] == 16 )
    {
      cinfo->err->msg_code = 108;
      cinfo->err->msg_parm.i[0] = v4;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
    }
    else if ( data[5] == 17 )
    {
      cinfo->err->msg_code = 109;
      cinfo->err->msg_parm.i[0] = v4;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
    }
    else
    {
      v8 = cinfo->err;
      if ( data[5] == 19 )
      {
        v8->msg_code = 110;
        cinfo->err->msg_parm.i[0] = v4;
      }
      else
      {
        v8->msg_code = 89;
        cinfo->err->msg_parm.i[0] = data[5];
        cinfo->err->msg_parm.i[1] = v4;
      }
      cinfo->err->emit_message(a1: cinfo, a2: 1);
    }
  }
  else
  {
    cinfo->err->msg_code = 77;
    cinfo->err->msg_parm.i[0] = v4;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10273AE0
// Name: examine_app14
// Source: json
//------------------------------------------------------------------------------
void __usercall examine_app14(
        jpeg_common_struct *cinfo@<esi>,
        unsigned __int8 *data@<eax>,
        unsigned int datalen@<ecx>,
        int remaining)
{
  int v4; // edx
  int v5; // edi
  jpeg_error_mgr *err; // ecx
  unsigned int transform; // [esp+0h] [ebp-4h]

  if ( datalen >= 0xC && *data == 65 && data[1] == 100 && data[2] == 111 && data[3] == 98 && data[4] == 101 )
  {
    v4 = data[8] + (data[7] << 8);
    v5 = data[10] + (data[9] << 8);
    transform = data[11];
    err = cinfo->err;
    err->msg_parm.i[0] = data[6] + (data[5] << 8);
    err->msg_parm.i[1] = v4;
    err->msg_parm.i[2] = v5;
    err->msg_parm.i[3] = transform;
    cinfo->err->msg_code = 76;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
    BYTE1(cinfo[11].err) = transform;
    LOBYTE(cinfo[11].err) = 1;
  }
  else
  {
    cinfo->err->msg_code = 78;
    cinfo->err->msg_parm.i[0] = remaining + datalen;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10273BA0
// Name: get_interesting_appn
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl get_interesting_appn(jpeg_decompress_struct *cinfo)
{
  jpeg_source_mgr *src; // esi
  unsigned int v2; // ecx
  const unsigned __int8 *next_input_byte; // ebx
  unsigned __int8 result; // al
  int v5; // edi
  const unsigned __int8 *v6; // ebx
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  int v9; // edi
  unsigned __int8 *v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // edx
  int v13; // edi
  int v14; // ecx
  unsigned int v15; // edx
  unsigned __int8 b[16]; // [esp+8h] [ebp-20h] BYREF
  jpeg_source_mgr *datasrc; // [esp+18h] [ebp-10h]
  int length; // [esp+1Ch] [ebp-Ch]
  unsigned int numtoread; // [esp+20h] [ebp-8h]
  unsigned int bytes_in_buffer; // [esp+24h] [ebp-4h]

  src = cinfo->src;
  v2 = src->bytes_in_buffer;
  next_input_byte = src->next_input_byte;
  datasrc = src;
  if ( v2 == 0 )
  {
    result = src->fill_input_buffer(a1: cinfo);
    if ( result == 0 )
      return result;
    next_input_byte = src->next_input_byte;
    v2 = src->bytes_in_buffer;
  }
  v5 = *next_input_byte << 8;
  v6 = next_input_byte + 1;
  v7 = v2 - 1;
  if ( v7 == 0 )
  {
    if ( src->fill_input_buffer(a1: cinfo) == 0 )
      return 0;
    v6 = src->next_input_byte;
    v7 = src->bytes_in_buffer;
  }
  v8 = v7 - 1;
  v9 = *v6 + v5 - 2;
  v10 = (unsigned __int8 *)(v6 + 1);
  bytes_in_buffer = v8;
  if ( v9 < 14 )
  {
    v11 = v9 <= 0 ? 0 : v9;
    numtoread = v11;
  }
  else
  {
    v11 = 14;
    numtoread = 14;
  }
  v12 = 0;
  length = 0;
  if ( v11 != 0 )
  {
    do
    {
      if ( v8 == 0 )
      {
        if ( src->fill_input_buffer(a1: cinfo) == 0 )
          return 0;
        v10 = (unsigned __int8 *)src->next_input_byte;
        v12 = length;
        v8 = src->bytes_in_buffer;
      }
      b[v12] = *v10;
      v11 = numtoread;
      ++v12;
      --v8;
      ++v10;
      bytes_in_buffer = v8;
      length = v12;
    }
    while ( v12 < numtoread );
  }
  v13 = v9 - v11;
  v14 = cinfo->unread_marker - 224;
  length = v13;
  if ( v14 == 0 )
  {
    examine_app0(cinfo, data: b, datalen: v11, remaining: v13);
    v13 = length;
    goto LABEL_21;
  }
  if ( v14 == 14 )
  {
    examine_app14(cinfo, data: b, datalen: v11, remaining: v13);
LABEL_21:
    src = datasrc;
    goto LABEL_22;
  }
  cinfo->err->msg_code = 68;
  cinfo->err->msg_parm.i[0] = cinfo->unread_marker;
  cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
LABEL_22:
  v15 = bytes_in_buffer;
  src->next_input_byte = v10;
  src->bytes_in_buffer = v15;
  if ( v13 > 0 )
    cinfo->src->skip_input_data(a1: cinfo, a2: v13);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10273CF0
// Name: skip_variable
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl skip_variable(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // edi
  unsigned int v3; // ecx
  const unsigned __int8 *next_input_byte; // ebx
  int v6; // eax
  const unsigned __int8 *v7; // ebx
  int v8; // ecx
  int v9; // eax
  int length; // [esp+Ch] [ebp-4h]
  int lengtha; // [esp+Ch] [ebp-4h]
  unsigned int bytes_in_buffer; // [esp+18h] [ebp+8h]

  err = (jpeg_source_mgr *)cinfo[1].err;
  v3 = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  if ( v3 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    next_input_byte = err->next_input_byte;
    v3 = err->bytes_in_buffer;
  }
  v6 = *next_input_byte << 8;
  v7 = next_input_byte + 1;
  bytes_in_buffer = v3 - 1;
  length = v6;
  if ( v3 == 1 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v7 = err->next_input_byte;
    bytes_in_buffer = err->bytes_in_buffer;
    v6 = length;
  }
  v8 = *v7;
  cinfo->err->msg_code = 91;
  v9 = v6 + v8 - 2;
  cinfo->err->msg_parm.i[0] = cinfo[15].global_state;
  cinfo->err->msg_parm.i[1] = v9;
  lengtha = v9;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  err->next_input_byte = v7 + 1;
  err->bytes_in_buffer = bytes_in_buffer - 1;
  if ( lengtha > 0 )
    ((void (__cdecl *)(jpeg_common_struct *, int))cinfo[1].err->reset_error_mgr)(a1: cinfo, a2: lengtha);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10273DB0
// Name: next_marker
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl next_marker(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // ecx
  jpeg_source_mgr *err; // ebx
  const unsigned __int8 *next_input_byte; // esi
  unsigned int i; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int c; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  err = (jpeg_source_mgr *)cinfo[1].err;
  next_input_byte = err->next_input_byte;
  for ( i = err->bytes_in_buffer; ; err->bytes_in_buffer = i )
  {
    if ( i == 0 )
    {
      if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)v1) == 0 )
        return 0;
      next_input_byte = err->next_input_byte;
      i = err->bytes_in_buffer;
      v1 = cinfo;
    }
    v5 = *next_input_byte;
    --i;
    ++next_input_byte;
    if ( v5 == 255 )
      goto LABEL_10;
    do
    {
      ++*(_DWORD *)(v1[16].global_state + 20);
      err->next_input_byte = next_input_byte;
      err->bytes_in_buffer = i;
      if ( i == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)v1) == 0 )
          return 0;
        next_input_byte = err->next_input_byte;
        i = err->bytes_in_buffer;
        v1 = cinfo;
      }
      v6 = *next_input_byte;
      --i;
      ++next_input_byte;
    }
    while ( v6 != 255 );
    do
    {
LABEL_10:
      if ( i == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)v1) == 0 )
          return 0;
        next_input_byte = err->next_input_byte;
        i = err->bytes_in_buffer;
        v1 = cinfo;
      }
      v7 = *next_input_byte;
      --i;
      ++next_input_byte;
      c = v7;
    }
    while ( v7 == 255 );
    if ( v7 != 0 )
      break;
    *(_DWORD *)(v1[16].global_state + 20) += 2;
    err->next_input_byte = next_input_byte;
  }
  if ( *(_DWORD *)(v1[16].global_state + 20) != 0 )
  {
    v1->err->msg_code = 116;
    v1->err->msg_parm.i[0] = *(_DWORD *)(v1[16].global_state + 20);
    cinfo->err->msg_parm.i[1] = v7;
    cinfo->err->emit_message(a1: cinfo, a2: -1);
    *(_DWORD *)(cinfo[16].global_state + 20) = 0;
    v7 = c;
    v1 = cinfo;
  }
  v1[15].global_state = v7;
  err->bytes_in_buffer = i;
  err->next_input_byte = next_input_byte;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10273ED0
// Name: first_marker
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl first_marker(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // eax
  jpeg_source_mgr *src; // esi
  const unsigned __int8 *next_input_byte; // ebx
  unsigned int bytes_in_buffer; // edi
  int v6; // ecx
  const unsigned __int8 *v7; // ebx
  unsigned int v8; // edi
  int v9; // edx
  unsigned int v10; // edi
  const unsigned __int8 *v11; // ebx
  int c2; // [esp+Ch] [ebp-4h]
  int c2a; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  src = cinfo->src;
  next_input_byte = src->next_input_byte;
  bytes_in_buffer = src->bytes_in_buffer;
  if ( bytes_in_buffer == 0 )
  {
    if ( src->fill_input_buffer(a1: cinfo) == 0 )
      return 0;
    next_input_byte = src->next_input_byte;
    bytes_in_buffer = src->bytes_in_buffer;
    v1 = cinfo;
  }
  v6 = *next_input_byte;
  v7 = next_input_byte + 1;
  v8 = bytes_in_buffer - 1;
  c2 = v6;
  if ( v8 == 0 )
  {
    if ( src->fill_input_buffer(a1: v1) == 0 )
      return 0;
    v7 = src->next_input_byte;
    v8 = src->bytes_in_buffer;
    v1 = cinfo;
    v6 = c2;
  }
  v9 = *v7;
  v10 = v8 - 1;
  v11 = v7 + 1;
  c2a = v9;
  if ( v6 != 255 || v9 != 216 )
  {
    v1->err->msg_code = 53;
    v1->err->msg_parm.i[0] = v6;
    v1->err->msg_parm.i[1] = v9;
    v1->err->error_exit(a1: (jpeg_common_struct *)v1);
    v1 = cinfo;
    v9 = c2a;
  }
  v1->unread_marker = v9;
  src->bytes_in_buffer = v10;
  src->next_input_byte = v11;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10273F80
// Name: read_markers
// Source: json
//------------------------------------------------------------------------------
int __cdecl read_markers(jpeg_decompress_struct *cinfo)
{
  unsigned __int8 v1; // al
  int unread_marker; // eax

  while ( 1 )
  {
    if ( cinfo->unread_marker == 0 )
    {
      v1 = cinfo->marker->saw_SOI != 0 ? next_marker(cinfo) : first_marker(cinfo);
      if ( v1 == 0 )
        return 0;
    }
    unread_marker = cinfo->unread_marker;
    switch ( unread_marker )
    {
      case 1:
      case 208:
      case 209:
      case 210:
      case 211:
      case 212:
      case 213:
      case 214:
      case 215:
        cinfo->err->msg_code = 92;
        cinfo->err->msg_parm.i[0] = cinfo->unread_marker;
        cinfo->err->emit_message(a1: (jpeg_common_struct *)cinfo, a2: 1);
        cinfo->unread_marker = 0;
        continue;
      case 192:
      case 193:
        if ( get_sof((jpeg_common_struct *)cinfo, is_prog: 0, is_arith: 0) == 0 )
          return 0;
        cinfo->unread_marker = 0;
        continue;
      case 194:
        if ( get_sof((jpeg_common_struct *)cinfo, is_prog: 1u, is_arith: 0) == 0 )
          return 0;
        cinfo->unread_marker = 0;
        continue;
      case 195:
      case 197:
      case 198:
      case 199:
      case 200:
      case 203:
      case 205:
      case 206:
      case 207:
        cinfo->err->msg_code = 60;
        cinfo->err->msg_parm.i[0] = cinfo->unread_marker;
        cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
        cinfo->unread_marker = 0;
        continue;
      case 196:
        if ( get_dht((jpeg_common_struct *)cinfo) == 0 )
          return 0;
        cinfo->unread_marker = 0;
        continue;
      case 201:
        if ( get_sof((jpeg_common_struct *)cinfo, is_prog: 0, is_arith: 1u) == 0 )
          return 0;
        cinfo->unread_marker = 0;
        continue;
      case 202:
        if ( get_sof((jpeg_common_struct *)cinfo, is_prog: 1u, is_arith: 1u) == 0 )
          return 0;
        cinfo->unread_marker = 0;
        continue;
      case 204:
      case 220:
        if ( skip_variable((jpeg_common_struct *)cinfo) == 0 )
          return 0;
        cinfo->unread_marker = 0;
        continue;
      case 216:
        if ( get_soi((jpeg_common_struct *)cinfo) == 0 )
          return 0;
        goto LABEL_32;
      case 217:
        cinfo->err->msg_code = 85;
        cinfo->err->emit_message(a1: (jpeg_common_struct *)cinfo, a2: 1);
        cinfo->unread_marker = 0;
        return 2;
      case 218:
        if ( get_sos((jpeg_common_struct *)cinfo) == 0 )
          return 0;
        cinfo->unread_marker = 0;
        return 1;
      case 219:
        if ( get_dqt((jpeg_common_struct *)cinfo) == 0 )
          return 0;
        cinfo->unread_marker = 0;
        continue;
      case 221:
        if ( get_dri(cinfo) == 0 )
          return 0;
        cinfo->unread_marker = 0;
        continue;
      case 224:
      case 226:
      case 227:
      case 228:
      case 229:
      case 230:
      case 231:
      case 232:
      case 233:
      case 234:
      case 235:
      case 236:
      case 237:
      case 238:
      case 239:
        if ( (*((unsigned __int8 (__cdecl **)(jpeg_decompress_struct *))&cinfo->marker[-36] + unread_marker - 1))(a1: cinfo) == 0 )
          return 0;
        cinfo->unread_marker = 0;
        continue;
      case 225:
        return 0;
      case 254:
        if ( ((unsigned __int8 (__cdecl *)(jpeg_decompress_struct *))cinfo->marker[1].reset_marker_reader)(a1: cinfo) == 0 )
          return 0;
        cinfo->unread_marker = 0;
        continue;
      default:
        cinfo->err->msg_code = 68;
        cinfo->err->msg_parm.i[0] = cinfo->unread_marker;
        cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
LABEL_32:
        cinfo->unread_marker = 0;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10274310
// Name: read_restart_marker
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl read_restart_marker(jpeg_decompress_struct *cinfo)
{
  if ( cinfo->unread_marker == 0 && next_marker(cinfo) == 0 )
    return 0;
  if ( cinfo->unread_marker == cinfo->marker->next_restart_num + 208 )
  {
    cinfo->err->msg_code = 98;
    cinfo->err->msg_parm.i[0] = cinfo->marker->next_restart_num;
    cinfo->err->emit_message(a1: (jpeg_common_struct *)cinfo, a2: 3);
    cinfo->unread_marker = 0;
  }
  else if ( cinfo->src->resync_to_restart(a1: cinfo, a2: cinfo->marker->next_restart_num) == 0 )
  {
    return 0;
  }
  cinfo->marker->next_restart_num = ((unsigned __int8)cinfo->marker->next_restart_num + 1) & 7;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102743A0
// Name: _jpeg_resync_to_restart
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl jpeg_resync_to_restart(jpeg_common_struct *cinfo, int desired)
{
  jpeg_common_struct *v2; // ebx
  int global_state; // esi
  char v4; // di
  int v5; // edi
  int v6; // edi
  int v7; // edi
  jpeg_error_mgr *err; // ebx
  void (__cdecl *error_exit)(jpeg_common_struct *); // esi
  void (__cdecl *i)(jpeg_common_struct *, int); // edi
  int v11; // eax
  jpeg_common_struct *v12; // ecx
  int v13; // eax
  int v14; // eax
  int v16; // [esp+Ch] [ebp-4h]

  v2 = cinfo;
  global_state = cinfo[15].global_state;
  cinfo->err->msg_code = 121;
  cinfo->err->msg_parm.i[0] = global_state;
  v4 = desired;
  cinfo->err->msg_parm.i[1] = desired;
  cinfo->err->emit_message(a1: cinfo, a2: -1);
  while ( 1 )
  {
    if ( global_state < 192 )
    {
LABEL_3:
      v5 = 2;
      goto LABEL_11;
    }
    if ( (unsigned int)(global_state - 208) > 7
      || global_state == ((v4 + 1) & 7) + 208
      || global_state == ((v4 + 2) & 7) + 208 )
    {
      v5 = 3;
    }
    else
    {
      if ( global_state == ((v4 - 1) & 7) + 208 || global_state == ((v4 - 2) & 7) + 208 )
        goto LABEL_3;
      v5 = 1;
    }
LABEL_11:
    v2->err->msg_code = 97;
    v2->err->msg_parm.i[0] = global_state;
    v2->err->msg_parm.i[1] = v5;
    v2->err->emit_message(a1: v2, a2: 4);
    v6 = v5 - 1;
    if ( v6 == 0 )
      break;
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
        return 1;
      v4 = desired;
    }
    else
    {
      err = v2[1].err;
      error_exit = err->error_exit;
      for ( i = err->emit_message; ; err->emit_message = i )
      {
        if ( i == nullptr )
        {
          if ( ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))err->format_message)(a1: cinfo) == 0 )
            return 0;
          error_exit = err->error_exit;
          i = err->emit_message;
        }
        v11 = *(unsigned __int8 *)error_exit;
        i = (void (__cdecl *)(jpeg_common_struct *, int))((char *)i - 1);
        error_exit = (void (__cdecl *)(jpeg_common_struct *))((char *)error_exit + 1);
        if ( v11 == 255 )
        {
          v12 = cinfo;
          goto LABEL_26;
        }
        do
        {
          v12 = cinfo;
          ++*(_DWORD *)(cinfo[16].global_state + 20);
          err->error_exit = error_exit;
          err->emit_message = i;
          if ( i == nullptr )
          {
            if ( ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))err->format_message)(a1: cinfo) == 0 )
              return 0;
            error_exit = err->error_exit;
            i = err->emit_message;
            v12 = cinfo;
          }
          v13 = *(unsigned __int8 *)error_exit;
          i = (void (__cdecl *)(jpeg_common_struct *, int))((char *)i - 1);
          error_exit = (void (__cdecl *)(jpeg_common_struct *))((char *)error_exit + 1);
        }
        while ( v13 != 255 );
        do
        {
LABEL_26:
          if ( i == nullptr )
          {
            if ( ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))err->format_message)(a1: v12) == 0 )
              return 0;
            error_exit = err->error_exit;
            i = err->emit_message;
            v12 = cinfo;
          }
          v14 = *(unsigned __int8 *)error_exit;
          i = (void (__cdecl *)(jpeg_common_struct *, int))((char *)i - 1);
          error_exit = (void (__cdecl *)(jpeg_common_struct *))((char *)error_exit + 1);
          v16 = v14;
        }
        while ( v14 == 255 );
        if ( v14 != 0 )
          break;
        *(_DWORD *)(v12[16].global_state + 20) += 2;
        err->error_exit = error_exit;
      }
      if ( *(_DWORD *)(v12[16].global_state + 20) != 0 )
      {
        v12->err->msg_code = 116;
        v12->err->msg_parm.i[0] = *(_DWORD *)(v12[16].global_state + 20);
        v12->err->msg_parm.i[1] = v14;
        v12->err->emit_message(a1: v12, a2: -1);
        *(_DWORD *)(cinfo[16].global_state + 20) = 0;
        v14 = v16;
        v12 = cinfo;
      }
      v12[15].global_state = v14;
      err->emit_message = i;
      v4 = desired;
      err->error_exit = error_exit;
      global_state = v12[15].global_state;
      v2 = cinfo;
    }
  }
  v2[15].global_state = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102745C0
// Name: reset_marker_reader
// Source: json
//------------------------------------------------------------------------------
void __cdecl reset_marker_reader(jpeg_decompress_struct *cinfo)
{
  jpeg_marker_reader *marker; // eax

  marker = cinfo->marker;
  cinfo->comp_info = nullptr;
  cinfo->input_scan_number = 0;
  cinfo->unread_marker = 0;
  *(_WORD *)&marker->saw_SOI = 0;
  marker->discarded_bytes = 0;
  marker[6].next_restart_num = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102745F0
// Name: _jinit_marker_reader
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_marker_reader(jpeg_common_struct *cinfo)
{
  int v1; // eax
  _DWORD *v2; // ecx
  int i; // edx
  jpeg_marker_reader *global_state; // eax

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 168);
  cinfo[16].global_state = v1;
  *(_DWORD *)v1 = reset_marker_reader;
  *(_DWORD *)(v1 + 4) = read_markers;
  *(_DWORD *)(v1 + 8) = read_restart_marker;
  *(_DWORD *)(v1 + 24) = skip_variable;
  *(_DWORD *)(v1 + 92) = 0;
  v2 = (_DWORD *)(v1 + 96);
  for ( i = 16; i != 0; --i )
  {
    *(v2 - 17) = skip_variable;
    *v2++ = 0;
  }
  *(_DWORD *)(v1 + 28) = get_interesting_appn;
  *(_DWORD *)(v1 + 84) = get_interesting_appn;
  global_state = (jpeg_marker_reader *)cinfo[16].global_state;
  cinfo[8].mem = nullptr;
  cinfo[5].mem = nullptr;
  cinfo[15].global_state = 0;
  *(_WORD *)&global_state->saw_SOI = 0;
  global_state->discarded_bytes = 0;
  global_state[6].next_restart_num = 0;
}

} // namespace client
