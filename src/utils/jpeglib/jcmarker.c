// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcmarker.c
// Functions: 16
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10252110
// Name: emit_marker
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_marker(jpeg_common_struct *cinfo@<esi>, JPEG_MARKER mark)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = -1;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = mark;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252180
// Name: emit_2bytes
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_2bytes(jpeg_common_struct *cinfo@<esi>, __int16 value)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = HIBYTE(value);
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = value;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102521F0
// Name: emit_dqt
// Source: json
//------------------------------------------------------------------------------
int __usercall emit_dqt@<eax>(jpeg_common_struct *cinfo@<esi>, int index)
{
  JQUANT_TBL *v2; // edi
  unsigned __int16 *v3; // eax
  int i; // edx
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  const int *v11; // edi
  unsigned __int16 v12; // bx
  jpeg_destination_mgr *v13; // eax
  jpeg_destination_mgr *v14; // eax
  JQUANT_TBL *qtbl; // [esp+8h] [ebp-8h]
  int prec; // [esp+Ch] [ebp-4h]

  v2 = *((JQUANT_TBL **)&cinfo[3].err + index);
  qtbl = v2;
  if ( v2 == nullptr )
  {
    cinfo->err->msg_code = 52;
    cinfo->err->msg_parm.i[0] = index;
    cinfo->err->error_exit(a1: cinfo);
  }
  prec = 0;
  v3 = &v2->quantval[2];
  for ( i = 16; i != 0; --i )
  {
    if ( *(v3 - 2) > 0xFFu )
      prec = 1;
    if ( *(v3 - 1) > 0xFFu )
      prec = 1;
    if ( *v3 > 0xFFu )
      prec = 1;
    if ( v3[1] > 0xFFu )
      prec = 1;
    v3 += 4;
  }
  if ( v2->sent_table == 0 )
  {
    err = (jpeg_destination_mgr *)cinfo[1].err;
    *err->next_output_byte++ = -1;
    v6 = err->free_in_buffer-- == 1;
    if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v7 = (jpeg_destination_mgr *)cinfo[1].err;
    *v7->next_output_byte++ = -37;
    v6 = v7->free_in_buffer-- == 1;
    if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = 0;
    v6 = v8->free_in_buffer-- == 1;
    if ( v6 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = prec != 0 ? -125 : 67;
    v6 = v9->free_in_buffer-- == 1;
    if ( v6 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v10 = (jpeg_destination_mgr *)cinfo[1].err;
    *v10->next_output_byte++ = index + 16 * prec;
    v6 = v10->free_in_buffer-- == 1;
    if ( v6 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v11 = jpeg_natural_order;
    do
    {
      v12 = qtbl->quantval[*v11];
      if ( prec != 0 )
      {
        v13 = (jpeg_destination_mgr *)cinfo[1].err;
        *v13->next_output_byte++ = HIBYTE(v12);
        v6 = v13->free_in_buffer-- == 1;
        if ( v6 && v13->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
        {
          cinfo->err->msg_code = 24;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      v14 = (jpeg_destination_mgr *)cinfo[1].err;
      *v14->next_output_byte++ = v12;
      v6 = v14->free_in_buffer-- == 1;
      if ( v6 && v14->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++v11;
    }
    while ( (int)v11 < (int)dword_103CAB78 );
    qtbl->sent_table = 1;
  }
  return prec;
}

//------------------------------------------------------------------------------
// Address: 0x10252410
// Name: emit_dht
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_dht(int index, unsigned __int8 is_ac)
{
  jpeg_common_struct *cinfo; // ecx
  int v3; // eax
  jpeg_common_struct *v4; // esi
  JHUFF_TBL *v5; // edi
  int v6; // edx
  int v7; // ecx
  unsigned __int8 *v8; // eax
  jpeg_error_mgr *err; // eax
  bool v10; // zf
  jpeg_error_mgr *v11; // eax
  jpeg_error_mgr *v12; // eax
  int j; // edi
  jpeg_error_mgr *v14; // eax
  int k; // edi
  jpeg_error_mgr *v16; // eax
  JHUFF_TBL *htbl; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]
  int length; // [esp+24h] [ebp+Ch]
  int lengtha; // [esp+24h] [ebp+Ch]

  v3 = index;
  v4 = cinfo;
  if ( is_ac != 0 )
  {
    v5 = *((JHUFF_TBL **)&cinfo[4].progress + index);
    v3 = index + 16;
    LOBYTE(index) = index + 16;
  }
  else
  {
    v5 = *((JHUFF_TBL **)&cinfo[3].is_decompressor + index);
  }
  htbl = v5;
  if ( v5 == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = v3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( v5->sent_table == 0 )
  {
    emit_marker(cinfo: v4, mark: M_DHT);
    v6 = 0;
    length = 0;
    v19 = 0;
    v7 = 0;
    v8 = &v5->bits[2];
    for ( i = 4; i != 0; --i )
    {
      length += *(v8 - 1);
      v7 += *v8;
      v6 += v8[1];
      v19 += v8[2];
      v8 += 4;
    }
    err = v4[1].err;
    lengtha = v7 + v6 + v19 + length;
    *(_BYTE *)err->error_exit++ = (unsigned __int16)(lengtha + 19) >> 8;
    v10 = err->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))err->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    v11 = v4[1].err;
    *(_BYTE *)v11->error_exit++ = lengtha + 19;
    v10 = v11->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v11->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    v12 = v4[1].err;
    *(_BYTE *)v12->error_exit++ = index;
    v10 = v12->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v12->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    for ( j = 1; j <= 16; ++j )
    {
      v14 = v4[1].err;
      *(_BYTE *)v14->error_exit++ = htbl->bits[j];
      v10 = v14->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
      if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v14->format_message)(a1: v4) == 0 )
      {
        v4->err->msg_code = 24;
        v4->err->error_exit(a1: v4);
      }
    }
    for ( k = 0; k < lengtha; ++k )
    {
      v16 = v4[1].err;
      *(_BYTE *)v16->error_exit++ = htbl->huffval[k];
      v10 = v16->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
      if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v16->format_message)(a1: v4) == 0 )
      {
        v4->err->msg_code = 24;
        v4->err->error_exit(a1: v4);
      }
    }
    htbl->sent_table = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102525E0
// Name: emit_sof
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_sof(jpeg_common_struct *cinfo@<ecx>, JPEG_MARKER code@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v4; // zf
  jpeg_destination_mgr *v5; // eax
  jpeg_component_info *global_state; // edi
  int i; // ebx
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax

  emit_marker(cinfo, mark: code);
  emit_2bytes(cinfo, value: 3 * (int)cinfo[2].client_data + 8);
  if ( (int)cinfo[1].progress > 0xFFFF || (int)cinfo[1].mem > 0xFFFF )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 0xFFFF;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = (unsigned __int8)cinfo[2].progress;
  v4 = err->free_in_buffer-- == 1;
  if ( v4 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: (__int16)cinfo[1].progress);
  emit_2bytes(cinfo, value: (__int16)cinfo[1].mem);
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = (unsigned __int8)cinfo[2].client_data;
  v4 = v5->free_in_buffer-- == 1;
  if ( v4 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  global_state = (jpeg_component_info *)cinfo[2].global_state;
  for ( i = 0; i < (int)cinfo[2].client_data; ++global_state )
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = global_state->component_id;
    v4 = v8->free_in_buffer-- == 1;
    if ( v4 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = LOBYTE(global_state->v_samp_factor) + 16 * LOBYTE(global_state->h_samp_factor);
    v4 = v9->free_in_buffer-- == 1;
    if ( v4 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v10 = (jpeg_destination_mgr *)cinfo[1].err;
    *v10->next_output_byte++ = global_state->quant_tbl_no;
    v4 = v10->free_in_buffer-- == 1;
    if ( v4 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252760
// Name: emit_sos
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_sos(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_component_info **p_is_decompressor; // ebx
  jpeg_component_info *v5; // edi
  jpeg_destination_mgr *v6; // eax
  int dc_tbl_no; // ecx
  int ac_tbl_no; // edx
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax
  int i; // [esp+Ch] [ebp-4h]

  emit_marker(cinfo, mark: M_SOS);
  emit_2bytes(cinfo, value: 2 * (int)cinfo[9].client_data + 6);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = (unsigned __int8)cinfo[9].client_data;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  i = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      v5 = *p_is_decompressor;
      v6 = (jpeg_destination_mgr *)cinfo[1].err;
      *v6->next_output_byte++ = (*p_is_decompressor)->component_id;
      v3 = v6->free_in_buffer-- == 1;
      if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      dc_tbl_no = v5->dc_tbl_no;
      ac_tbl_no = v5->ac_tbl_no;
      if ( LOBYTE(cinfo[8].global_state) != 0 )
      {
        if ( cinfo[12].client_data != nullptr
          || (LOBYTE(ac_tbl_no) = 0, cinfo[12].global_state != 0) && BYTE1(cinfo[7].progress) == 0 )
        {
          LOBYTE(dc_tbl_no) = 0;
        }
      }
      v9 = (jpeg_destination_mgr *)cinfo[1].err;
      *v9->next_output_byte++ = ac_tbl_no + 16 * dc_tbl_no;
      v3 = v9->free_in_buffer-- == 1;
      if ( v3 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++p_is_decompressor;
      ++i;
    }
    while ( i < (int)cinfo[9].client_data );
  }
  v10 = (jpeg_destination_mgr *)cinfo[1].err;
  *v10->next_output_byte++ = (unsigned __int8)cinfo[12].client_data;
  v3 = v10->free_in_buffer-- == 1;
  if ( v3 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v11 = (jpeg_destination_mgr *)cinfo[1].err;
  *v11->next_output_byte++ = cinfo[12].is_decompressor;
  v3 = v11->free_in_buffer-- == 1;
  if ( v3 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v12 = (jpeg_destination_mgr *)cinfo[1].err;
  *v12->next_output_byte++ = LOBYTE(cinfo[13].err) + 16 * LOBYTE(cinfo[12].global_state);
  v3 = v12->free_in_buffer-- == 1;
  if ( v3 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252930
// Name: emit_jfif_app0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_jfif_app0(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax
  jpeg_destination_mgr *v5; // eax
  jpeg_destination_mgr *v6; // eax
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax

  emit_marker(cinfo, mark: M_APP0);
  emit_2bytes(cinfo, value: 16);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = 74;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = 70;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = 73;
  v3 = v5->free_in_buffer-- == 1;
  if ( v3 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v6 = (jpeg_destination_mgr *)cinfo[1].err;
  *v6->next_output_byte++ = 70;
  v3 = v6->free_in_buffer-- == 1;
  if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = 0;
  v3 = v7->free_in_buffer-- == 1;
  if ( v3 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v8 = (jpeg_destination_mgr *)cinfo[1].err;
  *v8->next_output_byte++ = BYTE1(cinfo[8].mem);
  v3 = v8->free_in_buffer-- == 1;
  if ( v3 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v9 = (jpeg_destination_mgr *)cinfo[1].err;
  *v9->next_output_byte++ = BYTE2(cinfo[8].mem);
  v3 = v9->free_in_buffer-- == 1;
  if ( v3 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v10 = (jpeg_destination_mgr *)cinfo[1].err;
  *v10->next_output_byte++ = HIBYTE(cinfo[8].mem);
  v3 = v10->free_in_buffer-- == 1;
  if ( v3 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: (__int16)cinfo[8].progress);
  emit_2bytes(cinfo, value: HIWORD(cinfo[8].progress));
  v11 = (jpeg_destination_mgr *)cinfo[1].err;
  *v11->next_output_byte++ = 0;
  v3 = v11->free_in_buffer-- == 1;
  if ( v3 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v12 = (jpeg_destination_mgr *)cinfo[1].err;
  *v12->next_output_byte++ = 0;
  v3 = v12->free_in_buffer-- == 1;
  if ( v3 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252B30
// Name: emit_adobe_app14
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_adobe_app14(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax
  jpeg_destination_mgr *v5; // eax
  jpeg_destination_mgr *v6; // eax
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  unsigned __int8 *next_output_byte; // ecx

  emit_marker(cinfo, mark: M_APP14);
  emit_2bytes(cinfo, value: 14);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = 65;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = 100;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = 111;
  v3 = v5->free_in_buffer-- == 1;
  if ( v3 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v6 = (jpeg_destination_mgr *)cinfo[1].err;
  *v6->next_output_byte++ = 98;
  v3 = v6->free_in_buffer-- == 1;
  if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = 101;
  v3 = v7->free_in_buffer-- == 1;
  if ( v3 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: 100);
  emit_2bytes(cinfo, value: 0);
  emit_2bytes(cinfo, value: 0);
  if ( *(_DWORD *)&cinfo[2].is_decompressor == 3 )
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte = 1;
  }
  else
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    next_output_byte = v8->next_output_byte;
    if ( *(_DWORD *)&cinfo[2].is_decompressor == 5 )
      *next_output_byte = 2;
    else
      *next_output_byte = 0;
  }
  ++v8->next_output_byte;
  v3 = v8->free_in_buffer-- == 1;
  if ( v3 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252C90
// Name: write_marker_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_marker_header(jpeg_common_struct *cinfo, JPEG_MARKER marker, unsigned int datalen)
{
  if ( datalen > 0xFFFD )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_marker(cinfo, mark: marker);
  emit_2bytes(cinfo, value: datalen + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10252CD0
// Name: write_marker_byte
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_marker_byte(jpeg_common_struct *cinfo, unsigned __int8 val)
{
  jpeg_destination_mgr *err; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = val;
  if ( err->free_in_buffer-- == 1 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252D10
// Name: write_file_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_file_header(jpeg_common_struct *cinfo)
{
  jpeg_marker_writer *global_state; // edi

  global_state = (jpeg_marker_writer *)cinfo[13].global_state;
  emit_marker(cinfo, mark: M_SOI);
  global_state[1].write_file_header = nullptr;
  if ( LOBYTE(cinfo[8].mem) != 0 )
    emit_jfif_app0(cinfo);
  if ( LOBYTE(cinfo[8].client_data) != 0 )
    emit_adobe_app14(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10252D60
// Name: write_frame_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_frame_header(jpeg_common_struct *cinfo)
{
  int v1; // edi
  int *v2; // ebx
  int client_data; // ecx
  char v4; // bl
  int *v5; // eax
  JPEG_MARKER v6; // eax
  int prec; // [esp+Ch] [ebp-4h]

  v1 = 0;
  prec = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v2 = (int *)(cinfo[2].global_state + 16);
    do
    {
      prec += emit_dqt(cinfo, index: *v2);
      ++v1;
      v2 += 21;
    }
    while ( v1 < (int)cinfo[2].client_data );
  }
  if ( BYTE1(cinfo[7].progress) != 0
    || LOBYTE(cinfo[8].global_state) != 0
    || cinfo[2].progress != (jpeg_progress_mgr *)8 )
  {
    v4 = 0;
  }
  else
  {
    client_data = (int)cinfo[2].client_data;
    v4 = 1;
    if ( client_data > 0 )
    {
      v5 = (int *)(cinfo[2].global_state + 24);
      do
      {
        if ( *(v5 - 1) > 1 || *v5 > 1 )
          v4 = 0;
        v5 += 21;
        --client_data;
      }
      while ( client_data != 0 );
    }
    if ( prec != 0 && v4 != 0 )
    {
      cinfo->err->msg_code = 75;
      v4 = 0;
      cinfo->err->emit_message(a1: cinfo, a2: 0);
    }
  }
  if ( BYTE1(cinfo[7].progress) != 0 )
  {
    emit_sof(cinfo, code: M_SOF9);
  }
  else if ( LOBYTE(cinfo[8].global_state) != 0 )
  {
    emit_sof(cinfo, code: M_SOF2);
  }
  else
  {
    v6 = M_SOF0;
    if ( v4 == 0 )
      v6 = M_SOF1;
    emit_sof(cinfo, code: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252E50
// Name: write_scan_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_scan_header(jpeg_common_struct *cinfo)
{
  bool v2; // cc
  jpeg_component_info **p_is_decompressor; // ebx
  jpeg_component_info *v4; // edi
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  unsigned int global_state; // ebx
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax
  my_marker_writer *marker; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  marker = (my_marker_writer *)cinfo[13].global_state;
  if ( BYTE1(cinfo[7].progress) == 0 )
  {
    v2 = (int)cinfo[9].client_data <= 0;
    i = 0;
    if ( !v2 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        v4 = *p_is_decompressor;
        if ( LOBYTE(cinfo[8].global_state) != 0 )
        {
          if ( cinfo[12].client_data != nullptr )
          {
            emit_dht(index: v4->ac_tbl_no, is_ac: 1u);
          }
          else if ( cinfo[12].global_state == 0 )
          {
            emit_dht(index: v4->dc_tbl_no, is_ac: 0);
          }
        }
        else
        {
          emit_dht(index: v4->dc_tbl_no, is_ac: 0);
          emit_dht(index: v4->ac_tbl_no, is_ac: 1u);
        }
        ++p_is_decompressor;
        ++i;
      }
      while ( i < (int)cinfo[9].client_data );
    }
  }
  if ( cinfo[7].global_state != marker->last_restart_interval )
  {
    err = (jpeg_destination_mgr *)cinfo[1].err;
    *err->next_output_byte++ = -1;
    v6 = err->free_in_buffer-- == 1;
    if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v7 = (jpeg_destination_mgr *)cinfo[1].err;
    *v7->next_output_byte++ = -35;
    v6 = v7->free_in_buffer-- == 1;
    if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = 0;
    v6 = v8->free_in_buffer-- == 1;
    if ( v6 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = 4;
    v6 = v9->free_in_buffer-- == 1;
    if ( v6 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    global_state = cinfo[7].global_state;
    v11 = (jpeg_destination_mgr *)cinfo[1].err;
    *v11->next_output_byte++ = BYTE1(global_state);
    v6 = v11->free_in_buffer-- == 1;
    if ( v6 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v12 = (jpeg_destination_mgr *)cinfo[1].err;
    *v12->next_output_byte++ = global_state;
    v6 = v12->free_in_buffer-- == 1;
    if ( v6 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    marker->last_restart_interval = cinfo[7].global_state;
  }
  emit_sos(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10253050
// Name: write_file_trailer
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_file_trailer(jpeg_common_struct *cinfo)
{
  emit_marker(cinfo, mark: M_EOI);
}

//------------------------------------------------------------------------------
// Address: 0x10253070
// Name: write_tables_only
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_tables_only(jpeg_common_struct *cinfo)
{
  int v1; // edi
  JQUANT_TBL **v2; // ebx
  int v3; // edi
  JHUFF_TBL **p_progress; // ebx
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax

  emit_marker(cinfo, mark: M_SOI);
  v1 = 0;
  v2 = (JQUANT_TBL **)&cinfo[3];
  do
  {
    if ( *v2 != nullptr )
      emit_dqt(cinfo, index: v1);
    ++v1;
    ++v2;
  }
  while ( v1 < 4 );
  if ( BYTE1(cinfo[7].progress) == 0 )
  {
    v3 = 0;
    p_progress = (JHUFF_TBL **)&cinfo[4].progress;
    do
    {
      if ( *(p_progress - 4) != nullptr )
        emit_dht(index: v3, is_ac: 0);
      if ( *p_progress != nullptr )
        emit_dht(index: v3, is_ac: 1u);
      ++v3;
      ++p_progress;
    }
    while ( v3 < 4 );
  }
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = -1;
  v6 = err->free_in_buffer-- == 1;
  if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = -39;
  v6 = v7->free_in_buffer-- == 1;
  if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253150
// Name: _jinit_marker_writer
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_marker_writer(jpeg_common_struct *cinfo)
{
  jpeg_marker_writer *v1; // eax

  v1 = (jpeg_marker_writer *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32);
  cinfo[13].global_state = (int)v1;
  v1->write_file_header = (void (__cdecl *)(jpeg_compress_struct *))write_file_header;
  v1->write_frame_header = (void (__cdecl *)(jpeg_compress_struct *))write_frame_header;
  v1->write_scan_header = (void (__cdecl *)(jpeg_compress_struct *))write_scan_header;
  v1->write_file_trailer = (void (__cdecl *)(jpeg_compress_struct *))write_file_trailer;
  v1->write_tables_only = (void (__cdecl *)(jpeg_compress_struct *))write_tables_only;
  v1->write_marker_header = (void (__cdecl *)(jpeg_compress_struct *, int, unsigned int))write_marker_header;
  v1->write_marker_byte = (void (__cdecl *)(jpeg_compress_struct *, int))write_marker_byte;
  v1[1].write_file_header = nullptr;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10252130
// Name: emit_marker
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_marker(jpeg_common_struct *cinfo@<esi>, JPEG_MARKER mark)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = -1;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = mark;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102521A0
// Name: emit_2bytes
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_2bytes(jpeg_common_struct *cinfo@<esi>, __int16 value)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = HIBYTE(value);
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = value;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252210
// Name: emit_dqt
// Source: json
//------------------------------------------------------------------------------
int __usercall emit_dqt@<eax>(jpeg_common_struct *cinfo@<esi>, int index)
{
  JQUANT_TBL *v2; // edi
  unsigned __int16 *v3; // eax
  int i; // edx
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  const int *v11; // edi
  unsigned __int16 v12; // bx
  jpeg_destination_mgr *v13; // eax
  jpeg_destination_mgr *v14; // eax
  JQUANT_TBL *qtbl; // [esp+8h] [ebp-8h]
  int prec; // [esp+Ch] [ebp-4h]

  v2 = *((JQUANT_TBL **)&cinfo[3].err + index);
  qtbl = v2;
  if ( v2 == nullptr )
  {
    cinfo->err->msg_code = 52;
    cinfo->err->msg_parm.i[0] = index;
    cinfo->err->error_exit(a1: cinfo);
  }
  prec = 0;
  v3 = &v2->quantval[2];
  for ( i = 16; i != 0; --i )
  {
    if ( *(v3 - 2) > 0xFFu )
      prec = 1;
    if ( *(v3 - 1) > 0xFFu )
      prec = 1;
    if ( *v3 > 0xFFu )
      prec = 1;
    if ( v3[1] > 0xFFu )
      prec = 1;
    v3 += 4;
  }
  if ( v2->sent_table == 0 )
  {
    err = (jpeg_destination_mgr *)cinfo[1].err;
    *err->next_output_byte++ = -1;
    v6 = err->free_in_buffer-- == 1;
    if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v7 = (jpeg_destination_mgr *)cinfo[1].err;
    *v7->next_output_byte++ = -37;
    v6 = v7->free_in_buffer-- == 1;
    if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = 0;
    v6 = v8->free_in_buffer-- == 1;
    if ( v6 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = prec != 0 ? -125 : 67;
    v6 = v9->free_in_buffer-- == 1;
    if ( v6 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v10 = (jpeg_destination_mgr *)cinfo[1].err;
    *v10->next_output_byte++ = index + 16 * prec;
    v6 = v10->free_in_buffer-- == 1;
    if ( v6 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v11 = jpeg_natural_order;
    do
    {
      v12 = qtbl->quantval[*v11];
      if ( prec != 0 )
      {
        v13 = (jpeg_destination_mgr *)cinfo[1].err;
        *v13->next_output_byte++ = HIBYTE(v12);
        v6 = v13->free_in_buffer-- == 1;
        if ( v6 && v13->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
        {
          cinfo->err->msg_code = 24;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      v14 = (jpeg_destination_mgr *)cinfo[1].err;
      *v14->next_output_byte++ = v12;
      v6 = v14->free_in_buffer-- == 1;
      if ( v6 && v14->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++v11;
    }
    while ( (int)v11 < (int)dword_103CAC48 );
    qtbl->sent_table = 1;
  }
  return prec;
}

//------------------------------------------------------------------------------
// Address: 0x10252430
// Name: emit_dht
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_dht(int index, unsigned __int8 is_ac)
{
  jpeg_common_struct *cinfo; // ecx
  int v3; // eax
  jpeg_common_struct *v4; // esi
  JHUFF_TBL *v5; // edi
  int v6; // edx
  int v7; // ecx
  unsigned __int8 *v8; // eax
  jpeg_error_mgr *err; // eax
  bool v10; // zf
  jpeg_error_mgr *v11; // eax
  jpeg_error_mgr *v12; // eax
  int j; // edi
  jpeg_error_mgr *v14; // eax
  int k; // edi
  jpeg_error_mgr *v16; // eax
  JHUFF_TBL *htbl; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]
  int length; // [esp+24h] [ebp+Ch]
  int lengtha; // [esp+24h] [ebp+Ch]

  v3 = index;
  v4 = cinfo;
  if ( is_ac != 0 )
  {
    v5 = *((JHUFF_TBL **)&cinfo[4].progress + index);
    v3 = index + 16;
    LOBYTE(index) = index + 16;
  }
  else
  {
    v5 = *((JHUFF_TBL **)&cinfo[3].is_decompressor + index);
  }
  htbl = v5;
  if ( v5 == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = v3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( v5->sent_table == 0 )
  {
    emit_marker(cinfo: v4, mark: M_DHT);
    v6 = 0;
    length = 0;
    v19 = 0;
    v7 = 0;
    v8 = &v5->bits[2];
    for ( i = 4; i != 0; --i )
    {
      length += *(v8 - 1);
      v7 += *v8;
      v6 += v8[1];
      v19 += v8[2];
      v8 += 4;
    }
    err = v4[1].err;
    lengtha = v7 + v6 + v19 + length;
    *(_BYTE *)err->error_exit++ = (unsigned __int16)(lengtha + 19) >> 8;
    v10 = err->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))err->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    v11 = v4[1].err;
    *(_BYTE *)v11->error_exit++ = lengtha + 19;
    v10 = v11->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v11->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    v12 = v4[1].err;
    *(_BYTE *)v12->error_exit++ = index;
    v10 = v12->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v12->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    for ( j = 1; j <= 16; ++j )
    {
      v14 = v4[1].err;
      *(_BYTE *)v14->error_exit++ = htbl->bits[j];
      v10 = v14->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
      if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v14->format_message)(a1: v4) == 0 )
      {
        v4->err->msg_code = 24;
        v4->err->error_exit(a1: v4);
      }
    }
    for ( k = 0; k < lengtha; ++k )
    {
      v16 = v4[1].err;
      *(_BYTE *)v16->error_exit++ = htbl->huffval[k];
      v10 = v16->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
      if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v16->format_message)(a1: v4) == 0 )
      {
        v4->err->msg_code = 24;
        v4->err->error_exit(a1: v4);
      }
    }
    htbl->sent_table = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252600
// Name: emit_sof
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_sof(jpeg_common_struct *cinfo@<ecx>, JPEG_MARKER code@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v4; // zf
  jpeg_destination_mgr *v5; // eax
  jpeg_component_info *global_state; // edi
  int i; // ebx
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax

  emit_marker(cinfo, mark: code);
  emit_2bytes(cinfo, value: 3 * (int)cinfo[2].client_data + 8);
  if ( (int)cinfo[1].progress > 0xFFFF || (int)cinfo[1].mem > 0xFFFF )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 0xFFFF;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = (unsigned __int8)cinfo[2].progress;
  v4 = err->free_in_buffer-- == 1;
  if ( v4 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: (__int16)cinfo[1].progress);
  emit_2bytes(cinfo, value: (__int16)cinfo[1].mem);
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = (unsigned __int8)cinfo[2].client_data;
  v4 = v5->free_in_buffer-- == 1;
  if ( v4 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  global_state = (jpeg_component_info *)cinfo[2].global_state;
  for ( i = 0; i < (int)cinfo[2].client_data; ++global_state )
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = global_state->component_id;
    v4 = v8->free_in_buffer-- == 1;
    if ( v4 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = LOBYTE(global_state->v_samp_factor) + 16 * LOBYTE(global_state->h_samp_factor);
    v4 = v9->free_in_buffer-- == 1;
    if ( v4 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v10 = (jpeg_destination_mgr *)cinfo[1].err;
    *v10->next_output_byte++ = global_state->quant_tbl_no;
    v4 = v10->free_in_buffer-- == 1;
    if ( v4 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252780
// Name: emit_sos
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_sos(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_component_info **p_is_decompressor; // ebx
  jpeg_component_info *v5; // edi
  jpeg_destination_mgr *v6; // eax
  int dc_tbl_no; // ecx
  int ac_tbl_no; // edx
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax
  int i; // [esp+Ch] [ebp-4h]

  emit_marker(cinfo, mark: M_SOS);
  emit_2bytes(cinfo, value: 2 * (int)cinfo[9].client_data + 6);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = (unsigned __int8)cinfo[9].client_data;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  i = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      v5 = *p_is_decompressor;
      v6 = (jpeg_destination_mgr *)cinfo[1].err;
      *v6->next_output_byte++ = (*p_is_decompressor)->component_id;
      v3 = v6->free_in_buffer-- == 1;
      if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      dc_tbl_no = v5->dc_tbl_no;
      ac_tbl_no = v5->ac_tbl_no;
      if ( LOBYTE(cinfo[8].global_state) != 0 )
      {
        if ( cinfo[12].client_data != nullptr
          || (LOBYTE(ac_tbl_no) = 0, cinfo[12].global_state != 0) && BYTE1(cinfo[7].progress) == 0 )
        {
          LOBYTE(dc_tbl_no) = 0;
        }
      }
      v9 = (jpeg_destination_mgr *)cinfo[1].err;
      *v9->next_output_byte++ = ac_tbl_no + 16 * dc_tbl_no;
      v3 = v9->free_in_buffer-- == 1;
      if ( v3 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++p_is_decompressor;
      ++i;
    }
    while ( i < (int)cinfo[9].client_data );
  }
  v10 = (jpeg_destination_mgr *)cinfo[1].err;
  *v10->next_output_byte++ = (unsigned __int8)cinfo[12].client_data;
  v3 = v10->free_in_buffer-- == 1;
  if ( v3 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v11 = (jpeg_destination_mgr *)cinfo[1].err;
  *v11->next_output_byte++ = cinfo[12].is_decompressor;
  v3 = v11->free_in_buffer-- == 1;
  if ( v3 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v12 = (jpeg_destination_mgr *)cinfo[1].err;
  *v12->next_output_byte++ = LOBYTE(cinfo[13].err) + 16 * LOBYTE(cinfo[12].global_state);
  v3 = v12->free_in_buffer-- == 1;
  if ( v3 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252950
// Name: emit_jfif_app0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_jfif_app0(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax
  jpeg_destination_mgr *v5; // eax
  jpeg_destination_mgr *v6; // eax
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax

  emit_marker(cinfo, mark: M_APP0);
  emit_2bytes(cinfo, value: 16);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = 74;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = 70;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = 73;
  v3 = v5->free_in_buffer-- == 1;
  if ( v3 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v6 = (jpeg_destination_mgr *)cinfo[1].err;
  *v6->next_output_byte++ = 70;
  v3 = v6->free_in_buffer-- == 1;
  if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = 0;
  v3 = v7->free_in_buffer-- == 1;
  if ( v3 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v8 = (jpeg_destination_mgr *)cinfo[1].err;
  *v8->next_output_byte++ = BYTE1(cinfo[8].mem);
  v3 = v8->free_in_buffer-- == 1;
  if ( v3 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v9 = (jpeg_destination_mgr *)cinfo[1].err;
  *v9->next_output_byte++ = BYTE2(cinfo[8].mem);
  v3 = v9->free_in_buffer-- == 1;
  if ( v3 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v10 = (jpeg_destination_mgr *)cinfo[1].err;
  *v10->next_output_byte++ = HIBYTE(cinfo[8].mem);
  v3 = v10->free_in_buffer-- == 1;
  if ( v3 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: (__int16)cinfo[8].progress);
  emit_2bytes(cinfo, value: HIWORD(cinfo[8].progress));
  v11 = (jpeg_destination_mgr *)cinfo[1].err;
  *v11->next_output_byte++ = 0;
  v3 = v11->free_in_buffer-- == 1;
  if ( v3 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v12 = (jpeg_destination_mgr *)cinfo[1].err;
  *v12->next_output_byte++ = 0;
  v3 = v12->free_in_buffer-- == 1;
  if ( v3 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252B50
// Name: emit_adobe_app14
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_adobe_app14(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax
  jpeg_destination_mgr *v5; // eax
  jpeg_destination_mgr *v6; // eax
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  unsigned __int8 *next_output_byte; // ecx

  emit_marker(cinfo, mark: M_APP14);
  emit_2bytes(cinfo, value: 14);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = 65;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = 100;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = 111;
  v3 = v5->free_in_buffer-- == 1;
  if ( v3 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v6 = (jpeg_destination_mgr *)cinfo[1].err;
  *v6->next_output_byte++ = 98;
  v3 = v6->free_in_buffer-- == 1;
  if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = 101;
  v3 = v7->free_in_buffer-- == 1;
  if ( v3 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: 100);
  emit_2bytes(cinfo, value: 0);
  emit_2bytes(cinfo, value: 0);
  if ( *(_DWORD *)&cinfo[2].is_decompressor == 3 )
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte = 1;
  }
  else
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    next_output_byte = v8->next_output_byte;
    if ( *(_DWORD *)&cinfo[2].is_decompressor == 5 )
      *next_output_byte = 2;
    else
      *next_output_byte = 0;
  }
  ++v8->next_output_byte;
  v3 = v8->free_in_buffer-- == 1;
  if ( v3 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252CB0
// Name: write_marker_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_marker_header(jpeg_common_struct *cinfo, JPEG_MARKER marker, unsigned int datalen)
{
  if ( datalen > 0xFFFD )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_marker(cinfo, mark: marker);
  emit_2bytes(cinfo, value: datalen + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10252CF0
// Name: write_marker_byte
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_marker_byte(jpeg_common_struct *cinfo, unsigned __int8 val)
{
  jpeg_destination_mgr *err; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = val;
  if ( err->free_in_buffer-- == 1 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252D30
// Name: write_file_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_file_header(jpeg_common_struct *cinfo)
{
  jpeg_marker_writer *global_state; // edi

  global_state = (jpeg_marker_writer *)cinfo[13].global_state;
  emit_marker(cinfo, mark: M_SOI);
  global_state[1].write_file_header = nullptr;
  if ( LOBYTE(cinfo[8].mem) != 0 )
    emit_jfif_app0(cinfo);
  if ( LOBYTE(cinfo[8].client_data) != 0 )
    emit_adobe_app14(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10252D80
// Name: write_frame_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_frame_header(jpeg_common_struct *cinfo)
{
  int v1; // edi
  int *v2; // ebx
  int client_data; // ecx
  char v4; // bl
  int *v5; // eax
  JPEG_MARKER v6; // eax
  int prec; // [esp+Ch] [ebp-4h]

  v1 = 0;
  prec = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v2 = (int *)(cinfo[2].global_state + 16);
    do
    {
      prec += emit_dqt(cinfo, index: *v2);
      ++v1;
      v2 += 21;
    }
    while ( v1 < (int)cinfo[2].client_data );
  }
  if ( BYTE1(cinfo[7].progress) != 0
    || LOBYTE(cinfo[8].global_state) != 0
    || cinfo[2].progress != (jpeg_progress_mgr *)8 )
  {
    v4 = 0;
  }
  else
  {
    client_data = (int)cinfo[2].client_data;
    v4 = 1;
    if ( client_data > 0 )
    {
      v5 = (int *)(cinfo[2].global_state + 24);
      do
      {
        if ( *(v5 - 1) > 1 || *v5 > 1 )
          v4 = 0;
        v5 += 21;
        --client_data;
      }
      while ( client_data != 0 );
    }
    if ( prec != 0 && v4 != 0 )
    {
      cinfo->err->msg_code = 75;
      v4 = 0;
      cinfo->err->emit_message(a1: cinfo, a2: 0);
    }
  }
  if ( BYTE1(cinfo[7].progress) != 0 )
  {
    emit_sof(cinfo, code: M_SOF9);
  }
  else if ( LOBYTE(cinfo[8].global_state) != 0 )
  {
    emit_sof(cinfo, code: M_SOF2);
  }
  else
  {
    v6 = M_SOF0;
    if ( v4 == 0 )
      v6 = M_SOF1;
    emit_sof(cinfo, code: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252E70
// Name: write_scan_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_scan_header(jpeg_common_struct *cinfo)
{
  bool v2; // cc
  jpeg_component_info **p_is_decompressor; // ebx
  jpeg_component_info *v4; // edi
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  unsigned int global_state; // ebx
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax
  my_marker_writer *marker; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  marker = (my_marker_writer *)cinfo[13].global_state;
  if ( BYTE1(cinfo[7].progress) == 0 )
  {
    v2 = (int)cinfo[9].client_data <= 0;
    i = 0;
    if ( !v2 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        v4 = *p_is_decompressor;
        if ( LOBYTE(cinfo[8].global_state) != 0 )
        {
          if ( cinfo[12].client_data != nullptr )
          {
            emit_dht(index: v4->ac_tbl_no, is_ac: 1u);
          }
          else if ( cinfo[12].global_state == 0 )
          {
            emit_dht(index: v4->dc_tbl_no, is_ac: 0);
          }
        }
        else
        {
          emit_dht(index: v4->dc_tbl_no, is_ac: 0);
          emit_dht(index: v4->ac_tbl_no, is_ac: 1u);
        }
        ++p_is_decompressor;
        ++i;
      }
      while ( i < (int)cinfo[9].client_data );
    }
  }
  if ( cinfo[7].global_state != marker->last_restart_interval )
  {
    err = (jpeg_destination_mgr *)cinfo[1].err;
    *err->next_output_byte++ = -1;
    v6 = err->free_in_buffer-- == 1;
    if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v7 = (jpeg_destination_mgr *)cinfo[1].err;
    *v7->next_output_byte++ = -35;
    v6 = v7->free_in_buffer-- == 1;
    if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = 0;
    v6 = v8->free_in_buffer-- == 1;
    if ( v6 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = 4;
    v6 = v9->free_in_buffer-- == 1;
    if ( v6 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    global_state = cinfo[7].global_state;
    v11 = (jpeg_destination_mgr *)cinfo[1].err;
    *v11->next_output_byte++ = BYTE1(global_state);
    v6 = v11->free_in_buffer-- == 1;
    if ( v6 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v12 = (jpeg_destination_mgr *)cinfo[1].err;
    *v12->next_output_byte++ = global_state;
    v6 = v12->free_in_buffer-- == 1;
    if ( v6 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    marker->last_restart_interval = cinfo[7].global_state;
  }
  emit_sos(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10253090
// Name: write_tables_only
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_tables_only(jpeg_common_struct *cinfo)
{
  int v1; // edi
  JQUANT_TBL **v2; // ebx
  int v3; // edi
  JHUFF_TBL **p_progress; // ebx
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax

  emit_marker(cinfo, mark: M_SOI);
  v1 = 0;
  v2 = (JQUANT_TBL **)&cinfo[3];
  do
  {
    if ( *v2 != nullptr )
      emit_dqt(cinfo, index: v1);
    ++v1;
    ++v2;
  }
  while ( v1 < 4 );
  if ( BYTE1(cinfo[7].progress) == 0 )
  {
    v3 = 0;
    p_progress = (JHUFF_TBL **)&cinfo[4].progress;
    do
    {
      if ( *(p_progress - 4) != nullptr )
        emit_dht(index: v3, is_ac: 0);
      if ( *p_progress != nullptr )
        emit_dht(index: v3, is_ac: 1u);
      ++v3;
      ++p_progress;
    }
    while ( v3 < 4 );
  }
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = -1;
  v6 = err->free_in_buffer-- == 1;
  if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = -39;
  v6 = v7->free_in_buffer-- == 1;
  if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253170
// Name: _jinit_marker_writer
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_marker_writer(jpeg_common_struct *cinfo)
{
  jpeg_marker_writer *v1; // eax

  v1 = (jpeg_marker_writer *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32);
  cinfo[13].global_state = (int)v1;
  v1->write_file_header = (void (__cdecl *)(jpeg_compress_struct *))write_file_header;
  v1->write_frame_header = (void (__cdecl *)(jpeg_compress_struct *))write_frame_header;
  v1->write_scan_header = (void (__cdecl *)(jpeg_compress_struct *))write_scan_header;
  v1->write_file_trailer = write_file_trailer;
  v1->write_tables_only = (void (__cdecl *)(jpeg_compress_struct *))write_tables_only;
  v1->write_marker_header = (void (__cdecl *)(jpeg_compress_struct *, int, unsigned int))write_marker_header;
  v1->write_marker_byte = (void (__cdecl *)(jpeg_compress_struct *, int))write_marker_byte;
  v1[1].write_file_header = nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x00406640
// Name: emit_marker
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_marker(jpeg_common_struct *cinfo@<esi>, JPEG_MARKER mark)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = -1;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = mark;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004066B0
// Name: emit_2bytes
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_2bytes(jpeg_common_struct *cinfo@<esi>, __int16 value)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = HIBYTE(value);
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = value;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406720
// Name: emit_dqt
// Source: json
//------------------------------------------------------------------------------
int __usercall emit_dqt@<eax>(jpeg_common_struct *cinfo@<esi>, int index)
{
  JQUANT_TBL *v2; // edi
  unsigned __int16 *v3; // eax
  int i; // edx
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  const int *v11; // edi
  unsigned __int16 v12; // bx
  jpeg_destination_mgr *v13; // eax
  jpeg_destination_mgr *v14; // eax
  JQUANT_TBL *qtbl; // [esp+8h] [ebp-8h]
  int prec; // [esp+Ch] [ebp-4h]

  v2 = *((JQUANT_TBL **)&cinfo[3].err + index);
  qtbl = v2;
  if ( v2 == nullptr )
  {
    cinfo->err->msg_code = 52;
    cinfo->err->msg_parm.i[0] = index;
    cinfo->err->error_exit(a1: cinfo);
  }
  prec = 0;
  v3 = &v2->quantval[2];
  for ( i = 16; i != 0; --i )
  {
    if ( *(v3 - 2) > 0xFFu )
      prec = 1;
    if ( *(v3 - 1) > 0xFFu )
      prec = 1;
    if ( *v3 > 0xFFu )
      prec = 1;
    if ( v3[1] > 0xFFu )
      prec = 1;
    v3 += 4;
  }
  if ( v2->sent_table == 0 )
  {
    err = (jpeg_destination_mgr *)cinfo[1].err;
    *err->next_output_byte++ = -1;
    v6 = err->free_in_buffer-- == 1;
    if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v7 = (jpeg_destination_mgr *)cinfo[1].err;
    *v7->next_output_byte++ = -37;
    v6 = v7->free_in_buffer-- == 1;
    if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = 0;
    v6 = v8->free_in_buffer-- == 1;
    if ( v6 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = prec != 0 ? -125 : 67;
    v6 = v9->free_in_buffer-- == 1;
    if ( v6 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v10 = (jpeg_destination_mgr *)cinfo[1].err;
    *v10->next_output_byte++ = index + 16 * prec;
    v6 = v10->free_in_buffer-- == 1;
    if ( v6 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v11 = jpeg_natural_order;
    do
    {
      v12 = qtbl->quantval[*v11];
      if ( prec != 0 )
      {
        v13 = (jpeg_destination_mgr *)cinfo[1].err;
        *v13->next_output_byte++ = HIBYTE(v12);
        v6 = v13->free_in_buffer-- == 1;
        if ( v6 && v13->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
        {
          cinfo->err->msg_code = 24;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      v14 = (jpeg_destination_mgr *)cinfo[1].err;
      *v14->next_output_byte++ = v12;
      v6 = v14->free_in_buffer-- == 1;
      if ( v6 && v14->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++v11;
    }
    while ( (int)v11 < (int)dword_421948 );
    qtbl->sent_table = 1;
  }
  return prec;
}

//------------------------------------------------------------------------------
// Address: 0x00406940
// Name: emit_dht
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_dht(int index, unsigned __int8 is_ac)
{
  jpeg_common_struct *cinfo; // ecx
  int v3; // eax
  jpeg_common_struct *v4; // esi
  JHUFF_TBL *v5; // edi
  int v6; // edx
  int v7; // ecx
  unsigned __int8 *v8; // eax
  jpeg_error_mgr *err; // eax
  bool v10; // zf
  jpeg_error_mgr *v11; // eax
  jpeg_error_mgr *v12; // eax
  int j; // edi
  jpeg_error_mgr *v14; // eax
  int k; // edi
  jpeg_error_mgr *v16; // eax
  JHUFF_TBL *htbl; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]
  int length; // [esp+24h] [ebp+Ch]
  int lengtha; // [esp+24h] [ebp+Ch]

  v3 = index;
  v4 = cinfo;
  if ( is_ac != 0 )
  {
    v5 = *((JHUFF_TBL **)&cinfo[4].progress + index);
    v3 = index + 16;
    LOBYTE(index) = index + 16;
  }
  else
  {
    v5 = *((JHUFF_TBL **)&cinfo[3].is_decompressor + index);
  }
  htbl = v5;
  if ( v5 == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = v3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( v5->sent_table == 0 )
  {
    emit_marker(cinfo: v4, mark: M_DHT);
    v6 = 0;
    length = 0;
    v19 = 0;
    v7 = 0;
    v8 = &v5->bits[2];
    for ( i = 4; i != 0; --i )
    {
      length += *(v8 - 1);
      v7 += *v8;
      v6 += v8[1];
      v19 += v8[2];
      v8 += 4;
    }
    err = v4[1].err;
    lengtha = v7 + v6 + v19 + length;
    *(_BYTE *)err->error_exit++ = (unsigned __int16)(lengtha + 19) >> 8;
    v10 = err->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))err->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    v11 = v4[1].err;
    *(_BYTE *)v11->error_exit++ = lengtha + 19;
    v10 = v11->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v11->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    v12 = v4[1].err;
    *(_BYTE *)v12->error_exit++ = index;
    v10 = v12->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v12->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    for ( j = 1; j <= 16; ++j )
    {
      v14 = v4[1].err;
      *(_BYTE *)v14->error_exit++ = htbl->bits[j];
      v10 = v14->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
      if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v14->format_message)(a1: v4) == 0 )
      {
        v4->err->msg_code = 24;
        v4->err->error_exit(a1: v4);
      }
    }
    for ( k = 0; k < lengtha; ++k )
    {
      v16 = v4[1].err;
      *(_BYTE *)v16->error_exit++ = htbl->huffval[k];
      v10 = v16->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
      if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v16->format_message)(a1: v4) == 0 )
      {
        v4->err->msg_code = 24;
        v4->err->error_exit(a1: v4);
      }
    }
    htbl->sent_table = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406B10
// Name: emit_sof
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_sof(jpeg_common_struct *cinfo@<ecx>, JPEG_MARKER code@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v4; // zf
  jpeg_destination_mgr *v5; // eax
  jpeg_component_info *global_state; // edi
  int i; // ebx
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax

  emit_marker(cinfo, mark: code);
  emit_2bytes(cinfo, value: 3 * (int)cinfo[2].client_data + 8);
  if ( (int)cinfo[1].progress > 0xFFFF || (int)cinfo[1].mem > 0xFFFF )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 0xFFFF;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = (unsigned __int8)cinfo[2].progress;
  v4 = err->free_in_buffer-- == 1;
  if ( v4 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: (__int16)cinfo[1].progress);
  emit_2bytes(cinfo, value: (__int16)cinfo[1].mem);
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = (unsigned __int8)cinfo[2].client_data;
  v4 = v5->free_in_buffer-- == 1;
  if ( v4 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  global_state = (jpeg_component_info *)cinfo[2].global_state;
  for ( i = 0; i < (int)cinfo[2].client_data; ++global_state )
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = global_state->component_id;
    v4 = v8->free_in_buffer-- == 1;
    if ( v4 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = LOBYTE(global_state->v_samp_factor) + 16 * LOBYTE(global_state->h_samp_factor);
    v4 = v9->free_in_buffer-- == 1;
    if ( v4 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v10 = (jpeg_destination_mgr *)cinfo[1].err;
    *v10->next_output_byte++ = global_state->quant_tbl_no;
    v4 = v10->free_in_buffer-- == 1;
    if ( v4 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406C90
// Name: emit_sos
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_sos(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_component_info **p_is_decompressor; // ebx
  jpeg_component_info *v5; // edi
  jpeg_destination_mgr *v6; // eax
  int dc_tbl_no; // ecx
  int ac_tbl_no; // edx
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax
  int i; // [esp+Ch] [ebp-4h]

  emit_marker(cinfo, mark: M_SOS);
  emit_2bytes(cinfo, value: 2 * (int)cinfo[9].client_data + 6);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = (unsigned __int8)cinfo[9].client_data;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  i = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      v5 = *p_is_decompressor;
      v6 = (jpeg_destination_mgr *)cinfo[1].err;
      *v6->next_output_byte++ = (*p_is_decompressor)->component_id;
      v3 = v6->free_in_buffer-- == 1;
      if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      dc_tbl_no = v5->dc_tbl_no;
      ac_tbl_no = v5->ac_tbl_no;
      if ( LOBYTE(cinfo[8].global_state) != 0 )
      {
        if ( cinfo[12].client_data != nullptr
          || (LOBYTE(ac_tbl_no) = 0, cinfo[12].global_state != 0) && BYTE1(cinfo[7].progress) == 0 )
        {
          LOBYTE(dc_tbl_no) = 0;
        }
      }
      v9 = (jpeg_destination_mgr *)cinfo[1].err;
      *v9->next_output_byte++ = ac_tbl_no + 16 * dc_tbl_no;
      v3 = v9->free_in_buffer-- == 1;
      if ( v3 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++p_is_decompressor;
      ++i;
    }
    while ( i < (int)cinfo[9].client_data );
  }
  v10 = (jpeg_destination_mgr *)cinfo[1].err;
  *v10->next_output_byte++ = (unsigned __int8)cinfo[12].client_data;
  v3 = v10->free_in_buffer-- == 1;
  if ( v3 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v11 = (jpeg_destination_mgr *)cinfo[1].err;
  *v11->next_output_byte++ = cinfo[12].is_decompressor;
  v3 = v11->free_in_buffer-- == 1;
  if ( v3 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v12 = (jpeg_destination_mgr *)cinfo[1].err;
  *v12->next_output_byte++ = LOBYTE(cinfo[13].err) + 16 * LOBYTE(cinfo[12].global_state);
  v3 = v12->free_in_buffer-- == 1;
  if ( v3 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406E60
// Name: emit_jfif_app0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_jfif_app0(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax
  jpeg_destination_mgr *v5; // eax
  jpeg_destination_mgr *v6; // eax
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax

  emit_marker(cinfo, mark: M_APP0);
  emit_2bytes(cinfo, value: 16);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = 74;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = 70;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = 73;
  v3 = v5->free_in_buffer-- == 1;
  if ( v3 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v6 = (jpeg_destination_mgr *)cinfo[1].err;
  *v6->next_output_byte++ = 70;
  v3 = v6->free_in_buffer-- == 1;
  if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = 0;
  v3 = v7->free_in_buffer-- == 1;
  if ( v3 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v8 = (jpeg_destination_mgr *)cinfo[1].err;
  *v8->next_output_byte++ = BYTE1(cinfo[8].mem);
  v3 = v8->free_in_buffer-- == 1;
  if ( v3 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v9 = (jpeg_destination_mgr *)cinfo[1].err;
  *v9->next_output_byte++ = BYTE2(cinfo[8].mem);
  v3 = v9->free_in_buffer-- == 1;
  if ( v3 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v10 = (jpeg_destination_mgr *)cinfo[1].err;
  *v10->next_output_byte++ = HIBYTE(cinfo[8].mem);
  v3 = v10->free_in_buffer-- == 1;
  if ( v3 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: (__int16)cinfo[8].progress);
  emit_2bytes(cinfo, value: HIWORD(cinfo[8].progress));
  v11 = (jpeg_destination_mgr *)cinfo[1].err;
  *v11->next_output_byte++ = 0;
  v3 = v11->free_in_buffer-- == 1;
  if ( v3 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v12 = (jpeg_destination_mgr *)cinfo[1].err;
  *v12->next_output_byte++ = 0;
  v3 = v12->free_in_buffer-- == 1;
  if ( v3 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407060
// Name: emit_adobe_app14
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_adobe_app14(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax
  jpeg_destination_mgr *v5; // eax
  jpeg_destination_mgr *v6; // eax
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  unsigned __int8 *next_output_byte; // ecx

  emit_marker(cinfo, mark: M_APP14);
  emit_2bytes(cinfo, value: 14);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = 65;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = 100;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = 111;
  v3 = v5->free_in_buffer-- == 1;
  if ( v3 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v6 = (jpeg_destination_mgr *)cinfo[1].err;
  *v6->next_output_byte++ = 98;
  v3 = v6->free_in_buffer-- == 1;
  if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = 101;
  v3 = v7->free_in_buffer-- == 1;
  if ( v3 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: 100);
  emit_2bytes(cinfo, value: 0);
  emit_2bytes(cinfo, value: 0);
  if ( *(_DWORD *)&cinfo[2].is_decompressor == 3 )
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte = 1;
  }
  else
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    next_output_byte = v8->next_output_byte;
    if ( *(_DWORD *)&cinfo[2].is_decompressor == 5 )
      *next_output_byte = 2;
    else
      *next_output_byte = 0;
  }
  ++v8->next_output_byte;
  v3 = v8->free_in_buffer-- == 1;
  if ( v3 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004071C0
// Name: write_marker_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_marker_header(jpeg_common_struct *cinfo, JPEG_MARKER marker, unsigned int datalen)
{
  if ( datalen > 0xFFFD )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_marker(cinfo, mark: marker);
  emit_2bytes(cinfo, value: datalen + 2);
}

//------------------------------------------------------------------------------
// Address: 0x00407200
// Name: write_marker_byte
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_marker_byte(jpeg_common_struct *cinfo, unsigned __int8 val)
{
  jpeg_destination_mgr *err; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = val;
  if ( err->free_in_buffer-- == 1 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407240
// Name: write_file_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_file_header(jpeg_common_struct *cinfo)
{
  jpeg_marker_writer *global_state; // edi

  global_state = (jpeg_marker_writer *)cinfo[13].global_state;
  emit_marker(cinfo, mark: M_SOI);
  global_state[1].write_file_header = nullptr;
  if ( LOBYTE(cinfo[8].mem) != 0 )
    emit_jfif_app0(cinfo);
  if ( LOBYTE(cinfo[8].client_data) != 0 )
    emit_adobe_app14(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x00407290
// Name: write_frame_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_frame_header(jpeg_common_struct *cinfo)
{
  int v1; // edi
  int *v2; // ebx
  int client_data; // ecx
  char v4; // bl
  int *v5; // eax
  JPEG_MARKER v6; // eax
  int prec; // [esp+Ch] [ebp-4h]

  v1 = 0;
  prec = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v2 = (int *)(cinfo[2].global_state + 16);
    do
    {
      prec += emit_dqt(cinfo, index: *v2);
      ++v1;
      v2 += 21;
    }
    while ( v1 < (int)cinfo[2].client_data );
  }
  if ( BYTE1(cinfo[7].progress) != 0
    || LOBYTE(cinfo[8].global_state) != 0
    || cinfo[2].progress != (jpeg_progress_mgr *)8 )
  {
    v4 = 0;
  }
  else
  {
    client_data = (int)cinfo[2].client_data;
    v4 = 1;
    if ( client_data > 0 )
    {
      v5 = (int *)(cinfo[2].global_state + 24);
      do
      {
        if ( *(v5 - 1) > 1 || *v5 > 1 )
          v4 = 0;
        v5 += 21;
        --client_data;
      }
      while ( client_data != 0 );
    }
    if ( prec != 0 && v4 != 0 )
    {
      cinfo->err->msg_code = 75;
      v4 = 0;
      cinfo->err->emit_message(a1: cinfo, a2: 0);
    }
  }
  if ( BYTE1(cinfo[7].progress) != 0 )
  {
    emit_sof(cinfo, code: M_SOF9);
  }
  else if ( LOBYTE(cinfo[8].global_state) != 0 )
  {
    emit_sof(cinfo, code: M_SOF2);
  }
  else
  {
    v6 = M_SOF0;
    if ( v4 == 0 )
      v6 = M_SOF1;
    emit_sof(cinfo, code: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407380
// Name: write_scan_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_scan_header(jpeg_common_struct *cinfo)
{
  bool v2; // cc
  jpeg_component_info **p_is_decompressor; // ebx
  jpeg_component_info *v4; // edi
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  unsigned int global_state; // ebx
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax
  my_marker_writer *marker; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  marker = (my_marker_writer *)cinfo[13].global_state;
  if ( BYTE1(cinfo[7].progress) == 0 )
  {
    v2 = (int)cinfo[9].client_data <= 0;
    i = 0;
    if ( !v2 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        v4 = *p_is_decompressor;
        if ( LOBYTE(cinfo[8].global_state) != 0 )
        {
          if ( cinfo[12].client_data != nullptr )
          {
            emit_dht(index: v4->ac_tbl_no, is_ac: 1u);
          }
          else if ( cinfo[12].global_state == 0 )
          {
            emit_dht(index: v4->dc_tbl_no, is_ac: 0);
          }
        }
        else
        {
          emit_dht(index: v4->dc_tbl_no, is_ac: 0);
          emit_dht(index: v4->ac_tbl_no, is_ac: 1u);
        }
        ++p_is_decompressor;
        ++i;
      }
      while ( i < (int)cinfo[9].client_data );
    }
  }
  if ( cinfo[7].global_state != marker->last_restart_interval )
  {
    err = (jpeg_destination_mgr *)cinfo[1].err;
    *err->next_output_byte++ = -1;
    v6 = err->free_in_buffer-- == 1;
    if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v7 = (jpeg_destination_mgr *)cinfo[1].err;
    *v7->next_output_byte++ = -35;
    v6 = v7->free_in_buffer-- == 1;
    if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = 0;
    v6 = v8->free_in_buffer-- == 1;
    if ( v6 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = 4;
    v6 = v9->free_in_buffer-- == 1;
    if ( v6 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    global_state = cinfo[7].global_state;
    v11 = (jpeg_destination_mgr *)cinfo[1].err;
    *v11->next_output_byte++ = BYTE1(global_state);
    v6 = v11->free_in_buffer-- == 1;
    if ( v6 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v12 = (jpeg_destination_mgr *)cinfo[1].err;
    *v12->next_output_byte++ = global_state;
    v6 = v12->free_in_buffer-- == 1;
    if ( v6 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    marker->last_restart_interval = cinfo[7].global_state;
  }
  emit_sos(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x00407580
// Name: write_file_trailer
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_file_trailer(jpeg_common_struct *cinfo)
{
  emit_marker(cinfo, mark: M_EOI);
}

//------------------------------------------------------------------------------
// Address: 0x004075A0
// Name: write_tables_only
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_tables_only(jpeg_common_struct *cinfo)
{
  int v1; // edi
  JQUANT_TBL **v2; // ebx
  int v3; // edi
  JHUFF_TBL **p_progress; // ebx
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax

  emit_marker(cinfo, mark: M_SOI);
  v1 = 0;
  v2 = (JQUANT_TBL **)&cinfo[3];
  do
  {
    if ( *v2 != nullptr )
      emit_dqt(cinfo, index: v1);
    ++v1;
    ++v2;
  }
  while ( v1 < 4 );
  if ( BYTE1(cinfo[7].progress) == 0 )
  {
    v3 = 0;
    p_progress = (JHUFF_TBL **)&cinfo[4].progress;
    do
    {
      if ( *(p_progress - 4) != nullptr )
        emit_dht(index: v3, is_ac: 0);
      if ( *p_progress != nullptr )
        emit_dht(index: v3, is_ac: 1u);
      ++v3;
      ++p_progress;
    }
    while ( v3 < 4 );
  }
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = -1;
  v6 = err->free_in_buffer-- == 1;
  if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = -39;
  v6 = v7->free_in_buffer-- == 1;
  if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407680
// Name: _jinit_marker_writer
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_marker_writer(jpeg_common_struct *cinfo)
{
  jpeg_marker_writer *v1; // eax

  v1 = (jpeg_marker_writer *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32);
  cinfo[13].global_state = (int)v1;
  v1->write_file_header = (void (__cdecl *)(jpeg_compress_struct *))write_file_header;
  v1->write_frame_header = (void (__cdecl *)(jpeg_compress_struct *))write_frame_header;
  v1->write_scan_header = (void (__cdecl *)(jpeg_compress_struct *))write_scan_header;
  v1->write_file_trailer = (void (__cdecl *)(jpeg_compress_struct *))write_file_trailer;
  v1->write_tables_only = (void (__cdecl *)(jpeg_compress_struct *))write_tables_only;
  v1->write_marker_header = (void (__cdecl *)(jpeg_compress_struct *, int, unsigned int))write_marker_header;
  v1->write_marker_byte = (void (__cdecl *)(jpeg_compress_struct *, int))write_marker_byte;
  v1[1].write_file_header = nullptr;
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x0042F950
// Name: emit_marker
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_marker(jpeg_common_struct *cinfo@<esi>, JPEG_MARKER mark)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = -1;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = mark;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F9C0
// Name: emit_2bytes
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_2bytes(jpeg_common_struct *cinfo@<esi>, __int16 value)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = HIBYTE(value);
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = value;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FA30
// Name: emit_dqt
// Source: json
//------------------------------------------------------------------------------
int __usercall emit_dqt@<eax>(jpeg_common_struct *cinfo@<esi>, int index)
{
  JQUANT_TBL *v2; // edi
  unsigned __int16 *v3; // eax
  int i; // edx
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  const int *v11; // edi
  unsigned __int16 v12; // bx
  jpeg_destination_mgr *v13; // eax
  jpeg_destination_mgr *v14; // eax
  JQUANT_TBL *qtbl; // [esp+8h] [ebp-8h]
  int prec; // [esp+Ch] [ebp-4h]

  v2 = *((JQUANT_TBL **)&cinfo[3].err + index);
  qtbl = v2;
  if ( v2 == nullptr )
  {
    cinfo->err->msg_code = 52;
    cinfo->err->msg_parm.i[0] = index;
    cinfo->err->error_exit(a1: cinfo);
  }
  prec = 0;
  v3 = &v2->quantval[2];
  for ( i = 16; i != 0; --i )
  {
    if ( *(v3 - 2) > 0xFFu )
      prec = 1;
    if ( *(v3 - 1) > 0xFFu )
      prec = 1;
    if ( *v3 > 0xFFu )
      prec = 1;
    if ( v3[1] > 0xFFu )
      prec = 1;
    v3 += 4;
  }
  if ( v2->sent_table == 0 )
  {
    err = (jpeg_destination_mgr *)cinfo[1].err;
    *err->next_output_byte++ = -1;
    v6 = err->free_in_buffer-- == 1;
    if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v7 = (jpeg_destination_mgr *)cinfo[1].err;
    *v7->next_output_byte++ = -37;
    v6 = v7->free_in_buffer-- == 1;
    if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = 0;
    v6 = v8->free_in_buffer-- == 1;
    if ( v6 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = prec != 0 ? -125 : 67;
    v6 = v9->free_in_buffer-- == 1;
    if ( v6 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v10 = (jpeg_destination_mgr *)cinfo[1].err;
    *v10->next_output_byte++ = index + 16 * prec;
    v6 = v10->free_in_buffer-- == 1;
    if ( v6 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v11 = jpeg_natural_order;
    do
    {
      v12 = qtbl->quantval[*v11];
      if ( prec != 0 )
      {
        v13 = (jpeg_destination_mgr *)cinfo[1].err;
        *v13->next_output_byte++ = HIBYTE(v12);
        v6 = v13->free_in_buffer-- == 1;
        if ( v6 && v13->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
        {
          cinfo->err->msg_code = 24;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      v14 = (jpeg_destination_mgr *)cinfo[1].err;
      *v14->next_output_byte++ = v12;
      v6 = v14->free_in_buffer-- == 1;
      if ( v6 && v14->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++v11;
    }
    while ( (int)v11 < (int)dword_458C60 );
    qtbl->sent_table = 1;
  }
  return prec;
}

//------------------------------------------------------------------------------
// Address: 0x0042FC50
// Name: emit_dht
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_dht(int index, unsigned __int8 is_ac)
{
  jpeg_common_struct *cinfo; // ecx
  int v3; // eax
  jpeg_common_struct *v4; // esi
  JHUFF_TBL *v5; // edi
  int v6; // edx
  int v7; // ecx
  unsigned __int8 *v8; // eax
  jpeg_error_mgr *err; // eax
  bool v10; // zf
  jpeg_error_mgr *v11; // eax
  jpeg_error_mgr *v12; // eax
  int j; // edi
  jpeg_error_mgr *v14; // eax
  int k; // edi
  jpeg_error_mgr *v16; // eax
  JHUFF_TBL *htbl; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]
  int length; // [esp+24h] [ebp+Ch]
  int lengtha; // [esp+24h] [ebp+Ch]

  v3 = index;
  v4 = cinfo;
  if ( is_ac != 0 )
  {
    v5 = *((JHUFF_TBL **)&cinfo[4].progress + index);
    v3 = index + 16;
    LOBYTE(index) = index + 16;
  }
  else
  {
    v5 = *((JHUFF_TBL **)&cinfo[3].is_decompressor + index);
  }
  htbl = v5;
  if ( v5 == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = v3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( v5->sent_table == 0 )
  {
    emit_marker(cinfo: v4, mark: M_DHT);
    v6 = 0;
    length = 0;
    v19 = 0;
    v7 = 0;
    v8 = &v5->bits[2];
    for ( i = 4; i != 0; --i )
    {
      length += *(v8 - 1);
      v7 += *v8;
      v6 += v8[1];
      v19 += v8[2];
      v8 += 4;
    }
    err = v4[1].err;
    lengtha = v7 + v6 + v19 + length;
    *(_BYTE *)err->error_exit++ = (unsigned __int16)(lengtha + 19) >> 8;
    v10 = err->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))err->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    v11 = v4[1].err;
    *(_BYTE *)v11->error_exit++ = lengtha + 19;
    v10 = v11->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v11->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    v12 = v4[1].err;
    *(_BYTE *)v12->error_exit++ = index;
    v10 = v12->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v12->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    for ( j = 1; j <= 16; ++j )
    {
      v14 = v4[1].err;
      *(_BYTE *)v14->error_exit++ = htbl->bits[j];
      v10 = v14->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
      if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v14->format_message)(a1: v4) == 0 )
      {
        v4->err->msg_code = 24;
        v4->err->error_exit(a1: v4);
      }
    }
    for ( k = 0; k < lengtha; ++k )
    {
      v16 = v4[1].err;
      *(_BYTE *)v16->error_exit++ = htbl->huffval[k];
      v10 = v16->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
      if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v16->format_message)(a1: v4) == 0 )
      {
        v4->err->msg_code = 24;
        v4->err->error_exit(a1: v4);
      }
    }
    htbl->sent_table = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FE20
// Name: emit_sof
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_sof(jpeg_common_struct *cinfo@<ecx>, JPEG_MARKER code@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v4; // zf
  jpeg_destination_mgr *v5; // eax
  jpeg_component_info *global_state; // edi
  int i; // ebx
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax

  emit_marker(cinfo, mark: code);
  emit_2bytes(cinfo, value: 3 * (int)cinfo[2].client_data + 8);
  if ( (int)cinfo[1].progress > 0xFFFF || (int)cinfo[1].mem > 0xFFFF )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 0xFFFF;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = (unsigned __int8)cinfo[2].progress;
  v4 = err->free_in_buffer-- == 1;
  if ( v4 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: (__int16)cinfo[1].progress);
  emit_2bytes(cinfo, value: (__int16)cinfo[1].mem);
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = (unsigned __int8)cinfo[2].client_data;
  v4 = v5->free_in_buffer-- == 1;
  if ( v4 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  global_state = (jpeg_component_info *)cinfo[2].global_state;
  for ( i = 0; i < (int)cinfo[2].client_data; ++global_state )
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = global_state->component_id;
    v4 = v8->free_in_buffer-- == 1;
    if ( v4 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = LOBYTE(global_state->v_samp_factor) + 16 * LOBYTE(global_state->h_samp_factor);
    v4 = v9->free_in_buffer-- == 1;
    if ( v4 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v10 = (jpeg_destination_mgr *)cinfo[1].err;
    *v10->next_output_byte++ = global_state->quant_tbl_no;
    v4 = v10->free_in_buffer-- == 1;
    if ( v4 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FFA0
// Name: emit_sos
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_sos(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_component_info **p_is_decompressor; // ebx
  jpeg_component_info *v5; // edi
  jpeg_destination_mgr *v6; // eax
  int dc_tbl_no; // ecx
  int ac_tbl_no; // edx
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax
  int i; // [esp+Ch] [ebp-4h]

  emit_marker(cinfo, mark: M_SOS);
  emit_2bytes(cinfo, value: 2 * (int)cinfo[9].client_data + 6);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = (unsigned __int8)cinfo[9].client_data;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  i = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      v5 = *p_is_decompressor;
      v6 = (jpeg_destination_mgr *)cinfo[1].err;
      *v6->next_output_byte++ = (*p_is_decompressor)->component_id;
      v3 = v6->free_in_buffer-- == 1;
      if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      dc_tbl_no = v5->dc_tbl_no;
      ac_tbl_no = v5->ac_tbl_no;
      if ( LOBYTE(cinfo[8].global_state) != 0 )
      {
        if ( cinfo[12].client_data != nullptr
          || (LOBYTE(ac_tbl_no) = 0, cinfo[12].global_state != 0) && BYTE1(cinfo[7].progress) == 0 )
        {
          LOBYTE(dc_tbl_no) = 0;
        }
      }
      v9 = (jpeg_destination_mgr *)cinfo[1].err;
      *v9->next_output_byte++ = ac_tbl_no + 16 * dc_tbl_no;
      v3 = v9->free_in_buffer-- == 1;
      if ( v3 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++p_is_decompressor;
      ++i;
    }
    while ( i < (int)cinfo[9].client_data );
  }
  v10 = (jpeg_destination_mgr *)cinfo[1].err;
  *v10->next_output_byte++ = (unsigned __int8)cinfo[12].client_data;
  v3 = v10->free_in_buffer-- == 1;
  if ( v3 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v11 = (jpeg_destination_mgr *)cinfo[1].err;
  *v11->next_output_byte++ = cinfo[12].is_decompressor;
  v3 = v11->free_in_buffer-- == 1;
  if ( v3 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v12 = (jpeg_destination_mgr *)cinfo[1].err;
  *v12->next_output_byte++ = LOBYTE(cinfo[13].err) + 16 * LOBYTE(cinfo[12].global_state);
  v3 = v12->free_in_buffer-- == 1;
  if ( v3 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430170
// Name: emit_jfif_app0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_jfif_app0(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax
  jpeg_destination_mgr *v5; // eax
  jpeg_destination_mgr *v6; // eax
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax

  emit_marker(cinfo, mark: M_APP0);
  emit_2bytes(cinfo, value: 16);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = 74;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = 70;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = 73;
  v3 = v5->free_in_buffer-- == 1;
  if ( v3 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v6 = (jpeg_destination_mgr *)cinfo[1].err;
  *v6->next_output_byte++ = 70;
  v3 = v6->free_in_buffer-- == 1;
  if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = 0;
  v3 = v7->free_in_buffer-- == 1;
  if ( v3 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v8 = (jpeg_destination_mgr *)cinfo[1].err;
  *v8->next_output_byte++ = BYTE1(cinfo[8].mem);
  v3 = v8->free_in_buffer-- == 1;
  if ( v3 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v9 = (jpeg_destination_mgr *)cinfo[1].err;
  *v9->next_output_byte++ = BYTE2(cinfo[8].mem);
  v3 = v9->free_in_buffer-- == 1;
  if ( v3 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v10 = (jpeg_destination_mgr *)cinfo[1].err;
  *v10->next_output_byte++ = HIBYTE(cinfo[8].mem);
  v3 = v10->free_in_buffer-- == 1;
  if ( v3 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: (__int16)cinfo[8].progress);
  emit_2bytes(cinfo, value: HIWORD(cinfo[8].progress));
  v11 = (jpeg_destination_mgr *)cinfo[1].err;
  *v11->next_output_byte++ = 0;
  v3 = v11->free_in_buffer-- == 1;
  if ( v3 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v12 = (jpeg_destination_mgr *)cinfo[1].err;
  *v12->next_output_byte++ = 0;
  v3 = v12->free_in_buffer-- == 1;
  if ( v3 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430370
// Name: emit_adobe_app14
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_adobe_app14(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax
  jpeg_destination_mgr *v5; // eax
  jpeg_destination_mgr *v6; // eax
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  unsigned __int8 *next_output_byte; // ecx

  emit_marker(cinfo, mark: M_APP14);
  emit_2bytes(cinfo, value: 14);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = 65;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = 100;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = 111;
  v3 = v5->free_in_buffer-- == 1;
  if ( v3 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v6 = (jpeg_destination_mgr *)cinfo[1].err;
  *v6->next_output_byte++ = 98;
  v3 = v6->free_in_buffer-- == 1;
  if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = 101;
  v3 = v7->free_in_buffer-- == 1;
  if ( v3 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: 100);
  emit_2bytes(cinfo, value: 0);
  emit_2bytes(cinfo, value: 0);
  if ( *(_DWORD *)&cinfo[2].is_decompressor == 3 )
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte = 1;
  }
  else
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    next_output_byte = v8->next_output_byte;
    if ( *(_DWORD *)&cinfo[2].is_decompressor == 5 )
      *next_output_byte = 2;
    else
      *next_output_byte = 0;
  }
  ++v8->next_output_byte;
  v3 = v8->free_in_buffer-- == 1;
  if ( v3 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004304D0
// Name: write_marker_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_marker_header(jpeg_common_struct *cinfo, JPEG_MARKER marker, unsigned int datalen)
{
  if ( datalen > 0xFFFD )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_marker(cinfo, mark: marker);
  emit_2bytes(cinfo, value: datalen + 2);
}

//------------------------------------------------------------------------------
// Address: 0x00430510
// Name: write_marker_byte
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_marker_byte(jpeg_common_struct *cinfo, unsigned __int8 val)
{
  jpeg_destination_mgr *err; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = val;
  if ( err->free_in_buffer-- == 1 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430550
// Name: write_file_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_file_header(jpeg_common_struct *cinfo)
{
  jpeg_marker_writer *global_state; // edi

  global_state = (jpeg_marker_writer *)cinfo[13].global_state;
  emit_marker(cinfo, mark: M_SOI);
  global_state[1].write_file_header = nullptr;
  if ( LOBYTE(cinfo[8].mem) != 0 )
    emit_jfif_app0(cinfo);
  if ( LOBYTE(cinfo[8].client_data) != 0 )
    emit_adobe_app14(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x004305A0
// Name: write_frame_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_frame_header(jpeg_common_struct *cinfo)
{
  int v1; // edi
  int *v2; // ebx
  int client_data; // ecx
  char v4; // bl
  int *v5; // eax
  JPEG_MARKER v6; // eax
  int prec; // [esp+Ch] [ebp-4h]

  v1 = 0;
  prec = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v2 = (int *)(cinfo[2].global_state + 16);
    do
    {
      prec += emit_dqt(cinfo, index: *v2);
      ++v1;
      v2 += 21;
    }
    while ( v1 < (int)cinfo[2].client_data );
  }
  if ( BYTE1(cinfo[7].progress) != 0
    || LOBYTE(cinfo[8].global_state) != 0
    || cinfo[2].progress != (jpeg_progress_mgr *)8 )
  {
    v4 = 0;
  }
  else
  {
    client_data = (int)cinfo[2].client_data;
    v4 = 1;
    if ( client_data > 0 )
    {
      v5 = (int *)(cinfo[2].global_state + 24);
      do
      {
        if ( *(v5 - 1) > 1 || *v5 > 1 )
          v4 = 0;
        v5 += 21;
        --client_data;
      }
      while ( client_data != 0 );
    }
    if ( prec != 0 && v4 != 0 )
    {
      cinfo->err->msg_code = 75;
      v4 = 0;
      cinfo->err->emit_message(a1: cinfo, a2: 0);
    }
  }
  if ( BYTE1(cinfo[7].progress) != 0 )
  {
    emit_sof(cinfo, code: M_SOF9);
  }
  else if ( LOBYTE(cinfo[8].global_state) != 0 )
  {
    emit_sof(cinfo, code: M_SOF2);
  }
  else
  {
    v6 = M_SOF0;
    if ( v4 == 0 )
      v6 = M_SOF1;
    emit_sof(cinfo, code: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430690
// Name: write_scan_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_scan_header(jpeg_common_struct *cinfo)
{
  bool v2; // cc
  jpeg_component_info **p_is_decompressor; // ebx
  jpeg_component_info *v4; // edi
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  unsigned int global_state; // ebx
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax
  my_marker_writer *marker; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  marker = (my_marker_writer *)cinfo[13].global_state;
  if ( BYTE1(cinfo[7].progress) == 0 )
  {
    v2 = (int)cinfo[9].client_data <= 0;
    i = 0;
    if ( !v2 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        v4 = *p_is_decompressor;
        if ( LOBYTE(cinfo[8].global_state) != 0 )
        {
          if ( cinfo[12].client_data != nullptr )
          {
            emit_dht(index: v4->ac_tbl_no, is_ac: 1u);
          }
          else if ( cinfo[12].global_state == 0 )
          {
            emit_dht(index: v4->dc_tbl_no, is_ac: 0);
          }
        }
        else
        {
          emit_dht(index: v4->dc_tbl_no, is_ac: 0);
          emit_dht(index: v4->ac_tbl_no, is_ac: 1u);
        }
        ++p_is_decompressor;
        ++i;
      }
      while ( i < (int)cinfo[9].client_data );
    }
  }
  if ( cinfo[7].global_state != marker->last_restart_interval )
  {
    err = (jpeg_destination_mgr *)cinfo[1].err;
    *err->next_output_byte++ = -1;
    v6 = err->free_in_buffer-- == 1;
    if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v7 = (jpeg_destination_mgr *)cinfo[1].err;
    *v7->next_output_byte++ = -35;
    v6 = v7->free_in_buffer-- == 1;
    if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = 0;
    v6 = v8->free_in_buffer-- == 1;
    if ( v6 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = 4;
    v6 = v9->free_in_buffer-- == 1;
    if ( v6 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    global_state = cinfo[7].global_state;
    v11 = (jpeg_destination_mgr *)cinfo[1].err;
    *v11->next_output_byte++ = BYTE1(global_state);
    v6 = v11->free_in_buffer-- == 1;
    if ( v6 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v12 = (jpeg_destination_mgr *)cinfo[1].err;
    *v12->next_output_byte++ = global_state;
    v6 = v12->free_in_buffer-- == 1;
    if ( v6 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    marker->last_restart_interval = cinfo[7].global_state;
  }
  emit_sos(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x00430890
// Name: write_file_trailer
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_file_trailer(jpeg_common_struct *cinfo)
{
  emit_marker(cinfo, mark: M_EOI);
}

//------------------------------------------------------------------------------
// Address: 0x004308B0
// Name: write_tables_only
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_tables_only(jpeg_common_struct *cinfo)
{
  int v1; // edi
  JQUANT_TBL **v2; // ebx
  int v3; // edi
  JHUFF_TBL **p_progress; // ebx
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax

  emit_marker(cinfo, mark: M_SOI);
  v1 = 0;
  v2 = (JQUANT_TBL **)&cinfo[3];
  do
  {
    if ( *v2 != nullptr )
      emit_dqt(cinfo, index: v1);
    ++v1;
    ++v2;
  }
  while ( v1 < 4 );
  if ( BYTE1(cinfo[7].progress) == 0 )
  {
    v3 = 0;
    p_progress = (JHUFF_TBL **)&cinfo[4].progress;
    do
    {
      if ( *(p_progress - 4) != nullptr )
        emit_dht(index: v3, is_ac: 0);
      if ( *p_progress != nullptr )
        emit_dht(index: v3, is_ac: 1u);
      ++v3;
      ++p_progress;
    }
    while ( v3 < 4 );
  }
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = -1;
  v6 = err->free_in_buffer-- == 1;
  if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = -39;
  v6 = v7->free_in_buffer-- == 1;
  if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430990
// Name: _jinit_marker_writer
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_marker_writer(jpeg_common_struct *cinfo)
{
  jpeg_marker_writer *v1; // eax

  v1 = (jpeg_marker_writer *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32);
  cinfo[13].global_state = (int)v1;
  v1->write_file_header = (void (__cdecl *)(jpeg_compress_struct *))write_file_header;
  v1->write_frame_header = (void (__cdecl *)(jpeg_compress_struct *))write_frame_header;
  v1->write_scan_header = (void (__cdecl *)(jpeg_compress_struct *))write_scan_header;
  v1->write_file_trailer = (void (__cdecl *)(jpeg_compress_struct *))write_file_trailer;
  v1->write_tables_only = (void (__cdecl *)(jpeg_compress_struct *))write_tables_only;
  v1->write_marker_header = (void (__cdecl *)(jpeg_compress_struct *, int, unsigned int))write_marker_header;
  v1->write_marker_byte = (void (__cdecl *)(jpeg_compress_struct *, int))write_marker_byte;
  v1[1].write_file_header = nullptr;
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041C750
// Name: emit_marker
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_marker(jpeg_common_struct *cinfo@<esi>, JPEG_MARKER mark)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = -1;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = mark;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C7C0
// Name: emit_2bytes
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_2bytes(jpeg_common_struct *cinfo@<esi>, __int16 value)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = HIBYTE(value);
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = value;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C830
// Name: emit_dqt
// Source: json
//------------------------------------------------------------------------------
int __usercall emit_dqt@<eax>(jpeg_common_struct *cinfo@<esi>, int index)
{
  JQUANT_TBL *v2; // edi
  unsigned __int16 *v3; // eax
  int i; // edx
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  const int *v11; // edi
  unsigned __int16 v12; // bx
  jpeg_destination_mgr *v13; // eax
  jpeg_destination_mgr *v14; // eax
  JQUANT_TBL *qtbl; // [esp+8h] [ebp-8h]
  int prec; // [esp+Ch] [ebp-4h]

  v2 = *((JQUANT_TBL **)&cinfo[3].err + index);
  qtbl = v2;
  if ( v2 == nullptr )
  {
    cinfo->err->msg_code = 52;
    cinfo->err->msg_parm.i[0] = index;
    cinfo->err->error_exit(a1: cinfo);
  }
  prec = 0;
  v3 = &v2->quantval[2];
  for ( i = 16; i != 0; --i )
  {
    if ( *(v3 - 2) > 0xFFu )
      prec = 1;
    if ( *(v3 - 1) > 0xFFu )
      prec = 1;
    if ( *v3 > 0xFFu )
      prec = 1;
    if ( v3[1] > 0xFFu )
      prec = 1;
    v3 += 4;
  }
  if ( v2->sent_table == 0 )
  {
    err = (jpeg_destination_mgr *)cinfo[1].err;
    *err->next_output_byte++ = -1;
    v6 = err->free_in_buffer-- == 1;
    if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v7 = (jpeg_destination_mgr *)cinfo[1].err;
    *v7->next_output_byte++ = -37;
    v6 = v7->free_in_buffer-- == 1;
    if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = 0;
    v6 = v8->free_in_buffer-- == 1;
    if ( v6 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = prec != 0 ? -125 : 67;
    v6 = v9->free_in_buffer-- == 1;
    if ( v6 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v10 = (jpeg_destination_mgr *)cinfo[1].err;
    *v10->next_output_byte++ = index + 16 * prec;
    v6 = v10->free_in_buffer-- == 1;
    if ( v6 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v11 = jpeg_natural_order;
    do
    {
      v12 = qtbl->quantval[*v11];
      if ( prec != 0 )
      {
        v13 = (jpeg_destination_mgr *)cinfo[1].err;
        *v13->next_output_byte++ = HIBYTE(v12);
        v6 = v13->free_in_buffer-- == 1;
        if ( v6 && v13->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
        {
          cinfo->err->msg_code = 24;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      v14 = (jpeg_destination_mgr *)cinfo[1].err;
      *v14->next_output_byte++ = v12;
      v6 = v14->free_in_buffer-- == 1;
      if ( v6 && v14->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++v11;
    }
    while ( (int)v11 < (int)dword_43F590 );
    qtbl->sent_table = 1;
  }
  return prec;
}

//------------------------------------------------------------------------------
// Address: 0x0041CA50
// Name: emit_dht
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_dht(int index, unsigned __int8 is_ac)
{
  jpeg_common_struct *cinfo; // ecx
  int v3; // eax
  jpeg_common_struct *v4; // esi
  JHUFF_TBL *v5; // edi
  int v6; // edx
  int v7; // ecx
  unsigned __int8 *v8; // eax
  jpeg_error_mgr *err; // eax
  bool v10; // zf
  jpeg_error_mgr *v11; // eax
  jpeg_error_mgr *v12; // eax
  int j; // edi
  jpeg_error_mgr *v14; // eax
  int k; // edi
  jpeg_error_mgr *v16; // eax
  JHUFF_TBL *htbl; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]
  int length; // [esp+24h] [ebp+Ch]
  int lengtha; // [esp+24h] [ebp+Ch]

  v3 = index;
  v4 = cinfo;
  if ( is_ac != 0 )
  {
    v5 = *((JHUFF_TBL **)&cinfo[4].progress + index);
    v3 = index + 16;
    LOBYTE(index) = index + 16;
  }
  else
  {
    v5 = *((JHUFF_TBL **)&cinfo[3].is_decompressor + index);
  }
  htbl = v5;
  if ( v5 == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = v3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( v5->sent_table == 0 )
  {
    emit_marker(cinfo: v4, mark: M_DHT);
    v6 = 0;
    length = 0;
    v19 = 0;
    v7 = 0;
    v8 = &v5->bits[2];
    for ( i = 4; i != 0; --i )
    {
      length += *(v8 - 1);
      v7 += *v8;
      v6 += v8[1];
      v19 += v8[2];
      v8 += 4;
    }
    err = v4[1].err;
    lengtha = v7 + v6 + v19 + length;
    *(_BYTE *)err->error_exit++ = (unsigned __int16)(lengtha + 19) >> 8;
    v10 = err->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))err->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    v11 = v4[1].err;
    *(_BYTE *)v11->error_exit++ = lengtha + 19;
    v10 = v11->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v11->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    v12 = v4[1].err;
    *(_BYTE *)v12->error_exit++ = index;
    v10 = v12->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
    if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v12->format_message)(a1: v4) == 0 )
    {
      v4->err->msg_code = 24;
      v4->err->error_exit(a1: v4);
    }
    for ( j = 1; j <= 16; ++j )
    {
      v14 = v4[1].err;
      *(_BYTE *)v14->error_exit++ = htbl->bits[j];
      v10 = v14->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
      if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v14->format_message)(a1: v4) == 0 )
      {
        v4->err->msg_code = 24;
        v4->err->error_exit(a1: v4);
      }
    }
    for ( k = 0; k < lengtha; ++k )
    {
      v16 = v4[1].err;
      *(_BYTE *)v16->error_exit++ = htbl->huffval[k];
      v10 = v16->emit_message-- == (void (__cdecl *)(jpeg_common_struct *, int))1;
      if ( v10 && ((unsigned __int8 (__cdecl *)(jpeg_common_struct *))v16->format_message)(a1: v4) == 0 )
      {
        v4->err->msg_code = 24;
        v4->err->error_exit(a1: v4);
      }
    }
    htbl->sent_table = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CC20
// Name: emit_sof
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_sof(jpeg_common_struct *cinfo@<ecx>, JPEG_MARKER code@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v4; // zf
  jpeg_destination_mgr *v5; // eax
  jpeg_component_info *global_state; // edi
  int i; // ebx
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax

  emit_marker(cinfo, mark: code);
  emit_2bytes(cinfo, value: 3 * (int)cinfo[2].client_data + 8);
  if ( (int)cinfo[1].progress > 0xFFFF || (int)cinfo[1].mem > 0xFFFF )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 0xFFFF;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = (unsigned __int8)cinfo[2].progress;
  v4 = err->free_in_buffer-- == 1;
  if ( v4 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: (__int16)cinfo[1].progress);
  emit_2bytes(cinfo, value: (__int16)cinfo[1].mem);
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = (unsigned __int8)cinfo[2].client_data;
  v4 = v5->free_in_buffer-- == 1;
  if ( v4 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  global_state = (jpeg_component_info *)cinfo[2].global_state;
  for ( i = 0; i < (int)cinfo[2].client_data; ++global_state )
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = global_state->component_id;
    v4 = v8->free_in_buffer-- == 1;
    if ( v4 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = LOBYTE(global_state->v_samp_factor) + 16 * LOBYTE(global_state->h_samp_factor);
    v4 = v9->free_in_buffer-- == 1;
    if ( v4 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v10 = (jpeg_destination_mgr *)cinfo[1].err;
    *v10->next_output_byte++ = global_state->quant_tbl_no;
    v4 = v10->free_in_buffer-- == 1;
    if ( v4 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CDA0
// Name: emit_sos
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_sos(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_component_info **p_is_decompressor; // ebx
  jpeg_component_info *v5; // edi
  jpeg_destination_mgr *v6; // eax
  int dc_tbl_no; // ecx
  int ac_tbl_no; // edx
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax
  int i; // [esp+Ch] [ebp-4h]

  emit_marker(cinfo, mark: M_SOS);
  emit_2bytes(cinfo, value: 2 * (int)cinfo[9].client_data + 6);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = (unsigned __int8)cinfo[9].client_data;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  i = 0;
  if ( (int)cinfo[9].client_data > 0 )
  {
    p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
    do
    {
      v5 = *p_is_decompressor;
      v6 = (jpeg_destination_mgr *)cinfo[1].err;
      *v6->next_output_byte++ = (*p_is_decompressor)->component_id;
      v3 = v6->free_in_buffer-- == 1;
      if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      dc_tbl_no = v5->dc_tbl_no;
      ac_tbl_no = v5->ac_tbl_no;
      if ( LOBYTE(cinfo[8].global_state) != 0 )
      {
        if ( cinfo[12].client_data != nullptr
          || (LOBYTE(ac_tbl_no) = 0, cinfo[12].global_state != 0) && BYTE1(cinfo[7].progress) == 0 )
        {
          LOBYTE(dc_tbl_no) = 0;
        }
      }
      v9 = (jpeg_destination_mgr *)cinfo[1].err;
      *v9->next_output_byte++ = ac_tbl_no + 16 * dc_tbl_no;
      v3 = v9->free_in_buffer-- == 1;
      if ( v3 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++p_is_decompressor;
      ++i;
    }
    while ( i < (int)cinfo[9].client_data );
  }
  v10 = (jpeg_destination_mgr *)cinfo[1].err;
  *v10->next_output_byte++ = (unsigned __int8)cinfo[12].client_data;
  v3 = v10->free_in_buffer-- == 1;
  if ( v3 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v11 = (jpeg_destination_mgr *)cinfo[1].err;
  *v11->next_output_byte++ = cinfo[12].is_decompressor;
  v3 = v11->free_in_buffer-- == 1;
  if ( v3 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v12 = (jpeg_destination_mgr *)cinfo[1].err;
  *v12->next_output_byte++ = LOBYTE(cinfo[13].err) + 16 * LOBYTE(cinfo[12].global_state);
  v3 = v12->free_in_buffer-- == 1;
  if ( v3 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CF70
// Name: emit_jfif_app0
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_jfif_app0(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax
  jpeg_destination_mgr *v5; // eax
  jpeg_destination_mgr *v6; // eax
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  jpeg_destination_mgr *v10; // eax
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax

  emit_marker(cinfo, mark: M_APP0);
  emit_2bytes(cinfo, value: 16);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = 74;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = 70;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = 73;
  v3 = v5->free_in_buffer-- == 1;
  if ( v3 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v6 = (jpeg_destination_mgr *)cinfo[1].err;
  *v6->next_output_byte++ = 70;
  v3 = v6->free_in_buffer-- == 1;
  if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = 0;
  v3 = v7->free_in_buffer-- == 1;
  if ( v3 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v8 = (jpeg_destination_mgr *)cinfo[1].err;
  *v8->next_output_byte++ = BYTE1(cinfo[8].mem);
  v3 = v8->free_in_buffer-- == 1;
  if ( v3 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v9 = (jpeg_destination_mgr *)cinfo[1].err;
  *v9->next_output_byte++ = BYTE2(cinfo[8].mem);
  v3 = v9->free_in_buffer-- == 1;
  if ( v3 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v10 = (jpeg_destination_mgr *)cinfo[1].err;
  *v10->next_output_byte++ = HIBYTE(cinfo[8].mem);
  v3 = v10->free_in_buffer-- == 1;
  if ( v3 && v10->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: (__int16)cinfo[8].progress);
  emit_2bytes(cinfo, value: HIWORD(cinfo[8].progress));
  v11 = (jpeg_destination_mgr *)cinfo[1].err;
  *v11->next_output_byte++ = 0;
  v3 = v11->free_in_buffer-- == 1;
  if ( v3 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v12 = (jpeg_destination_mgr *)cinfo[1].err;
  *v12->next_output_byte++ = 0;
  v3 = v12->free_in_buffer-- == 1;
  if ( v3 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D170
// Name: emit_adobe_app14
// Source: json
//------------------------------------------------------------------------------
void __usercall emit_adobe_app14(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_destination_mgr *err; // eax
  bool v3; // zf
  jpeg_destination_mgr *v4; // eax
  jpeg_destination_mgr *v5; // eax
  jpeg_destination_mgr *v6; // eax
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  unsigned __int8 *next_output_byte; // ecx

  emit_marker(cinfo, mark: M_APP14);
  emit_2bytes(cinfo, value: 14);
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = 65;
  v3 = err->free_in_buffer-- == 1;
  if ( v3 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v4 = (jpeg_destination_mgr *)cinfo[1].err;
  *v4->next_output_byte++ = 100;
  v3 = v4->free_in_buffer-- == 1;
  if ( v3 && v4->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v5 = (jpeg_destination_mgr *)cinfo[1].err;
  *v5->next_output_byte++ = 111;
  v3 = v5->free_in_buffer-- == 1;
  if ( v3 && v5->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v6 = (jpeg_destination_mgr *)cinfo[1].err;
  *v6->next_output_byte++ = 98;
  v3 = v6->free_in_buffer-- == 1;
  if ( v3 && v6->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = 101;
  v3 = v7->free_in_buffer-- == 1;
  if ( v3 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_2bytes(cinfo, value: 100);
  emit_2bytes(cinfo, value: 0);
  emit_2bytes(cinfo, value: 0);
  if ( *(_DWORD *)&cinfo[2].is_decompressor == 3 )
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte = 1;
  }
  else
  {
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    next_output_byte = v8->next_output_byte;
    if ( *(_DWORD *)&cinfo[2].is_decompressor == 5 )
      *next_output_byte = 2;
    else
      *next_output_byte = 0;
  }
  ++v8->next_output_byte;
  v3 = v8->free_in_buffer-- == 1;
  if ( v3 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D2D0
// Name: write_marker_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_marker_header(jpeg_common_struct *cinfo, JPEG_MARKER marker, unsigned int datalen)
{
  if ( datalen > 0xFFFD )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  emit_marker(cinfo, mark: marker);
  emit_2bytes(cinfo, value: datalen + 2);
}

//------------------------------------------------------------------------------
// Address: 0x0041D310
// Name: write_marker_byte
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_marker_byte(jpeg_common_struct *cinfo, unsigned __int8 val)
{
  jpeg_destination_mgr *err; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = val;
  if ( err->free_in_buffer-- == 1 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D350
// Name: write_file_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_file_header(jpeg_common_struct *cinfo)
{
  jpeg_marker_writer *global_state; // edi

  global_state = (jpeg_marker_writer *)cinfo[13].global_state;
  emit_marker(cinfo, mark: M_SOI);
  global_state[1].write_file_header = nullptr;
  if ( LOBYTE(cinfo[8].mem) != 0 )
    emit_jfif_app0(cinfo);
  if ( LOBYTE(cinfo[8].client_data) != 0 )
    emit_adobe_app14(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041D3A0
// Name: write_frame_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_frame_header(jpeg_common_struct *cinfo)
{
  int v1; // edi
  int *v2; // ebx
  int client_data; // ecx
  char v4; // bl
  int *v5; // eax
  JPEG_MARKER v6; // eax
  int prec; // [esp+Ch] [ebp-4h]

  v1 = 0;
  prec = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v2 = (int *)(cinfo[2].global_state + 16);
    do
    {
      prec += emit_dqt(cinfo, index: *v2);
      ++v1;
      v2 += 21;
    }
    while ( v1 < (int)cinfo[2].client_data );
  }
  if ( BYTE1(cinfo[7].progress) != 0
    || LOBYTE(cinfo[8].global_state) != 0
    || cinfo[2].progress != (jpeg_progress_mgr *)8 )
  {
    v4 = 0;
  }
  else
  {
    client_data = (int)cinfo[2].client_data;
    v4 = 1;
    if ( client_data > 0 )
    {
      v5 = (int *)(cinfo[2].global_state + 24);
      do
      {
        if ( *(v5 - 1) > 1 || *v5 > 1 )
          v4 = 0;
        v5 += 21;
        --client_data;
      }
      while ( client_data != 0 );
    }
    if ( prec != 0 && v4 != 0 )
    {
      cinfo->err->msg_code = 75;
      v4 = 0;
      cinfo->err->emit_message(a1: cinfo, a2: 0);
    }
  }
  if ( BYTE1(cinfo[7].progress) != 0 )
  {
    emit_sof(cinfo, code: M_SOF9);
  }
  else if ( LOBYTE(cinfo[8].global_state) != 0 )
  {
    emit_sof(cinfo, code: M_SOF2);
  }
  else
  {
    v6 = M_SOF0;
    if ( v4 == 0 )
      v6 = M_SOF1;
    emit_sof(cinfo, code: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D490
// Name: write_scan_header
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_scan_header(jpeg_common_struct *cinfo)
{
  bool v2; // cc
  jpeg_component_info **p_is_decompressor; // ebx
  jpeg_component_info *v4; // edi
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax
  jpeg_destination_mgr *v8; // eax
  jpeg_destination_mgr *v9; // eax
  unsigned int global_state; // ebx
  jpeg_destination_mgr *v11; // eax
  jpeg_destination_mgr *v12; // eax
  my_marker_writer *marker; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  marker = (my_marker_writer *)cinfo[13].global_state;
  if ( BYTE1(cinfo[7].progress) == 0 )
  {
    v2 = (int)cinfo[9].client_data <= 0;
    i = 0;
    if ( !v2 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        v4 = *p_is_decompressor;
        if ( LOBYTE(cinfo[8].global_state) != 0 )
        {
          if ( cinfo[12].client_data != nullptr )
          {
            emit_dht(index: v4->ac_tbl_no, is_ac: 1u);
          }
          else if ( cinfo[12].global_state == 0 )
          {
            emit_dht(index: v4->dc_tbl_no, is_ac: 0);
          }
        }
        else
        {
          emit_dht(index: v4->dc_tbl_no, is_ac: 0);
          emit_dht(index: v4->ac_tbl_no, is_ac: 1u);
        }
        ++p_is_decompressor;
        ++i;
      }
      while ( i < (int)cinfo[9].client_data );
    }
  }
  if ( cinfo[7].global_state != marker->last_restart_interval )
  {
    err = (jpeg_destination_mgr *)cinfo[1].err;
    *err->next_output_byte++ = -1;
    v6 = err->free_in_buffer-- == 1;
    if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v7 = (jpeg_destination_mgr *)cinfo[1].err;
    *v7->next_output_byte++ = -35;
    v6 = v7->free_in_buffer-- == 1;
    if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v8 = (jpeg_destination_mgr *)cinfo[1].err;
    *v8->next_output_byte++ = 0;
    v6 = v8->free_in_buffer-- == 1;
    if ( v6 && v8->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v9 = (jpeg_destination_mgr *)cinfo[1].err;
    *v9->next_output_byte++ = 4;
    v6 = v9->free_in_buffer-- == 1;
    if ( v6 && v9->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    global_state = cinfo[7].global_state;
    v11 = (jpeg_destination_mgr *)cinfo[1].err;
    *v11->next_output_byte++ = BYTE1(global_state);
    v6 = v11->free_in_buffer-- == 1;
    if ( v6 && v11->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    v12 = (jpeg_destination_mgr *)cinfo[1].err;
    *v12->next_output_byte++ = global_state;
    v6 = v12->free_in_buffer-- == 1;
    if ( v6 && v12->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
    {
      cinfo->err->msg_code = 24;
      cinfo->err->error_exit(a1: cinfo);
    }
    marker->last_restart_interval = cinfo[7].global_state;
  }
  emit_sos(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041D690
// Name: write_file_trailer
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_file_trailer(jpeg_common_struct *cinfo)
{
  emit_marker(cinfo, mark: M_EOI);
}

//------------------------------------------------------------------------------
// Address: 0x0041D6B0
// Name: write_tables_only
// Source: json
//------------------------------------------------------------------------------
void __cdecl write_tables_only(jpeg_common_struct *cinfo)
{
  int v1; // edi
  JQUANT_TBL **v2; // ebx
  int v3; // edi
  JHUFF_TBL **p_progress; // ebx
  jpeg_destination_mgr *err; // eax
  bool v6; // zf
  jpeg_destination_mgr *v7; // eax

  emit_marker(cinfo, mark: M_SOI);
  v1 = 0;
  v2 = (JQUANT_TBL **)&cinfo[3];
  do
  {
    if ( *v2 != nullptr )
      emit_dqt(cinfo, index: v1);
    ++v1;
    ++v2;
  }
  while ( v1 < 4 );
  if ( BYTE1(cinfo[7].progress) == 0 )
  {
    v3 = 0;
    p_progress = (JHUFF_TBL **)&cinfo[4].progress;
    do
    {
      if ( *(p_progress - 4) != nullptr )
        emit_dht(index: v3, is_ac: 0);
      if ( *p_progress != nullptr )
        emit_dht(index: v3, is_ac: 1u);
      ++v3;
      ++p_progress;
    }
    while ( v3 < 4 );
  }
  err = (jpeg_destination_mgr *)cinfo[1].err;
  *err->next_output_byte++ = -1;
  v6 = err->free_in_buffer-- == 1;
  if ( v6 && err->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = (jpeg_destination_mgr *)cinfo[1].err;
  *v7->next_output_byte++ = -39;
  v6 = v7->free_in_buffer-- == 1;
  if ( v6 && v7->empty_output_buffer(a1: (jpeg_compress_struct *)cinfo) == 0 )
  {
    cinfo->err->msg_code = 24;
    cinfo->err->error_exit(a1: cinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D790
// Name: _jinit_marker_writer
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_marker_writer(jpeg_common_struct *cinfo)
{
  jpeg_marker_writer *v1; // eax

  v1 = (jpeg_marker_writer *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32);
  cinfo[13].global_state = (int)v1;
  v1->write_file_header = (void (__cdecl *)(jpeg_compress_struct *))write_file_header;
  v1->write_frame_header = (void (__cdecl *)(jpeg_compress_struct *))write_frame_header;
  v1->write_scan_header = (void (__cdecl *)(jpeg_compress_struct *))write_scan_header;
  v1->write_file_trailer = (void (__cdecl *)(jpeg_compress_struct *))write_file_trailer;
  v1->write_tables_only = (void (__cdecl *)(jpeg_compress_struct *))write_tables_only;
  v1->write_marker_header = (void (__cdecl *)(jpeg_compress_struct *, int, unsigned int))write_marker_header;
  v1->write_marker_byte = (void (__cdecl *)(jpeg_compress_struct *, int))write_marker_byte;
  v1[1].write_file_header = nullptr;
}

} // namespace vxconsole_ps3
