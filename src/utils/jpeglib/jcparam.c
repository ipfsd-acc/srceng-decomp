// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcparam.c
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10250800
// Name: _jpeg_add_quant_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_add_quant_table(
        jpeg_common_struct *cinfo,
        unsigned int which_tbl,
        const unsigned int *basic_table,
        int scale_factor,
        unsigned __int8 force_baseline)
{
  int v5; // esi
  const unsigned int *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( which_tbl >= 4 )
  {
    cinfo->err->msg_code = 31;
    cinfo->err->msg_parm.i[0] = which_tbl;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *((_DWORD *)&cinfo[3].err + which_tbl) == 0 )
    *((_DWORD *)&cinfo[3].err + which_tbl) = jpeg_alloc_quant_table(cinfo);
  v5 = 0;
  v6 = basic_table + 2;
  do
  {
    v7 = (signed int)(scale_factor * *(v6 - 2) + 50) / 100;
    if ( v7 > 0 )
    {
      if ( v7 > 0x7FFF )
        v7 = 0x7FFF;
    }
    else
    {
      v7 = 1;
    }
    if ( force_baseline != 0 && v7 > 255 )
      LOWORD(v7) = 255;
    *(_WORD *)(v5 + *((_DWORD *)&cinfo[3].err + which_tbl)) = v7;
    v8 = (signed int)(scale_factor * *(v6 - 1) + 50) / 100;
    if ( v8 > 0 )
    {
      if ( v8 > 0x7FFF )
        v8 = 0x7FFF;
    }
    else
    {
      v8 = 1;
    }
    if ( force_baseline != 0 && v8 > 255 )
      LOWORD(v8) = 255;
    *(_WORD *)(*((_DWORD *)&cinfo[3].err + which_tbl) + v5 + 2) = v8;
    v9 = (signed int)(scale_factor * *v6 + 50) / 100;
    if ( v9 > 0 )
    {
      if ( v9 > 0x7FFF )
        v9 = 0x7FFF;
    }
    else
    {
      v9 = 1;
    }
    if ( force_baseline != 0 && v9 > 255 )
      LOWORD(v9) = 255;
    *(_WORD *)(*((_DWORD *)&cinfo[3].err + which_tbl) + v5 + 4) = v9;
    v10 = (signed int)(scale_factor * v6[1] + 50) / 100;
    if ( v10 > 0 )
    {
      if ( v10 > 0x7FFF )
        v10 = 0x7FFF;
    }
    else
    {
      v10 = 1;
    }
    if ( force_baseline != 0 && v10 > 255 )
      LOWORD(v10) = 255;
    *(_WORD *)(v5 + *((_DWORD *)&cinfo[3].err + which_tbl) + 6) = v10;
    v5 += 8;
    v6 += 4;
  }
  while ( v5 < 128 );
  *(_BYTE *)(*((_DWORD *)&cinfo[3].err + which_tbl) + 128) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102509E0
// Name: _jpeg_set_quality
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_quality(jpeg_common_struct *cinfo, int quality, unsigned __int8 force_baseline)
{
  int v3; // ecx
  int v4; // esi

  v3 = quality;
  if ( quality > 0 )
  {
    if ( quality <= 100 )
    {
      if ( quality < 50 )
      {
        v4 = 5000 / quality;
        goto LABEL_6;
      }
    }
    else
    {
      v3 = 100;
    }
    v4 = 2 * (100 - v3);
  }
  else
  {
    v4 = 5000;
  }
LABEL_6:
  jpeg_add_quant_table(cinfo, which_tbl: 0, basic_table: &basic_table, scale_factor: v4, force_baseline);
  jpeg_add_quant_table(cinfo, which_tbl: 1u, basic_table: &dword_103C9318, scale_factor: v4, force_baseline);
}

//------------------------------------------------------------------------------
// Address: 0x10250A50
// Name: add_huff_table
// Source: json
//------------------------------------------------------------------------------
void __usercall add_huff_table(
        const unsigned __int8 *bits@<eax>,
        jpeg_common_struct *cinfo,
        JHUFF_TBL **htblptr,
        unsigned __int8 *val)
{
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // edx
  int v9; // ecx
  const unsigned __int8 *v10; // eax
  signed int v11; // edi
  int i; // [esp+8h] [ebp-4h]

  if ( *htblptr == nullptr )
    *htblptr = jpeg_alloc_huff_table(cinfo);
  v5 = (int)*htblptr;
  *(_QWORD *)v5 = *(_QWORD *)bits;
  *(_QWORD *)(v5 + 8) = *((_QWORD *)bits + 1);
  *(_BYTE *)(v5 + 16) = bits[16];
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = bits + 2;
  for ( i = 4; i != 0; --i )
  {
    v6 += *(v10 - 1);
    v9 += *v10;
    v8 += v10[1];
    v7 += v10[2];
    v10 += 4;
  }
  v11 = v9 + v8 + v7 + v6;
  if ( v11 < 1 || v11 > 256 )
  {
    cinfo->err->msg_code = 8;
    cinfo->err->error_exit(a1: cinfo);
  }
  memcpy(dst: (*htblptr)->huffval, src: val, count: v11);
  (*htblptr)->sent_table = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10250B10
// Name: std_huff_tables
// Source: json
//------------------------------------------------------------------------------
void __usercall std_huff_tables(jpeg_common_struct *cinfo@<esi>)
{
  add_huff_table(
    bits: bits_dc_luminance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[3].is_decompressor,
    val: (unsigned __int8 *)val_dc_luminance);
  add_huff_table(
    bits: bits_ac_luminance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[4].progress,
    val: (unsigned __int8 *)val_ac_luminance);
  add_huff_table(
    bits: bits_dc_chrominance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[3].global_state,
    val: (unsigned __int8 *)val_dc_chrominance);
  add_huff_table(
    bits: bits_ac_chrominance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[4].client_data,
    val: (unsigned __int8 *)val_ac_chrominance);
}

//------------------------------------------------------------------------------
// Address: 0x10250B70
// Name: _jpeg_set_colorspace
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_colorspace(jpeg_common_struct *cinfo, J_COLOR_SPACE colorspace)
{
  jpeg_component_info *global_state; // esi
  jpeg_component_info *v3; // eax
  jpeg_component_info *v4; // eax
  jpeg_component_info *v5; // esi
  jpeg_component_info *v6; // eax
  jpeg_component_info *v7; // eax
  jpeg_component_info *v8; // esi
  jpeg_component_info *v9; // eax
  jpeg_component_info *v10; // eax
  jpeg_component_info *v11; // eax
  jpeg_component_info *v12; // esi
  jpeg_component_info *v13; // eax
  jpeg_component_info *v14; // eax
  jpeg_component_info *v15; // eax
  int client_data; // eax
  int v17; // ecx
  int v18; // edx
  jpeg_component_info *v19; // eax

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  *(_DWORD *)&cinfo[2].is_decompressor = colorspace;
  LOBYTE(cinfo[8].mem) = 0;
  LOBYTE(cinfo[8].client_data) = 0;
  switch ( colorspace )
  {
    case JCS_UNKNOWN:
      client_data = (int)cinfo[1].client_data;
      cinfo[2].client_data = (void *)client_data;
      if ( client_data < 1 || client_data > 10 )
      {
        cinfo->err->msg_code = 26;
        cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
        cinfo->err->msg_parm.i[1] = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v17 = 0;
      if ( (int)cinfo[2].client_data > 0 )
      {
        v18 = 0;
        do
        {
          v19 = (jpeg_component_info *)(v18 + cinfo[2].global_state);
          v19->component_id = v17++;
          v19->h_samp_factor = 1;
          v19->v_samp_factor = 1;
          v19->quant_tbl_no = 0;
          v19->dc_tbl_no = 0;
          v19->ac_tbl_no = 0;
          v18 += 84;
        }
        while ( v17 < (int)cinfo[2].client_data );
      }
      break;
    case JCS_GRAYSCALE:
      LOBYTE(cinfo[8].mem) = 1;
      cinfo[2].client_data = (void *)1;
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      global_state->component_id = 1;
      global_state->h_samp_factor = 1;
      global_state->v_samp_factor = 1;
      global_state->quant_tbl_no = 0;
      global_state->dc_tbl_no = 0;
      global_state->ac_tbl_no = 0;
      break;
    case JCS_RGB:
      v3 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)3;
      LOBYTE(cinfo[8].client_data) = 1;
      v3->h_samp_factor = 1;
      v3->v_samp_factor = 1;
      v3->component_id = 82;
      v3->quant_tbl_no = 0;
      v3->dc_tbl_no = 0;
      v3->ac_tbl_no = 0;
      v4 = (jpeg_component_info *)cinfo[2].global_state;
      v4[1].h_samp_factor = 1;
      v4[1].v_samp_factor = 1;
      v4[1].component_id = 71;
      v4[1].quant_tbl_no = 0;
      v4[1].dc_tbl_no = 0;
      v4[1].ac_tbl_no = 0;
      v5 = (jpeg_component_info *)cinfo[2].global_state;
      v5[2].h_samp_factor = 1;
      v5[2].v_samp_factor = 1;
      v5[2].component_id = 66;
      v5[2].quant_tbl_no = 0;
      v5[2].dc_tbl_no = 0;
      v5[2].ac_tbl_no = 0;
      break;
    case JCS_YCbCr:
      v6 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)3;
      LOBYTE(cinfo[8].mem) = 1;
      v6->component_id = 1;
      v6->h_samp_factor = 2;
      v6->v_samp_factor = 2;
      v6->quant_tbl_no = 0;
      v6->dc_tbl_no = 0;
      v6->ac_tbl_no = 0;
      v7 = (jpeg_component_info *)cinfo[2].global_state;
      v7[1].h_samp_factor = 1;
      v7[1].v_samp_factor = 1;
      v7[1].quant_tbl_no = 1;
      v7[1].dc_tbl_no = 1;
      v7[1].ac_tbl_no = 1;
      v7[1].component_id = 2;
      v8 = (jpeg_component_info *)cinfo[2].global_state;
      v8[2].h_samp_factor = 1;
      v8[2].v_samp_factor = 1;
      v8[2].quant_tbl_no = 1;
      v8[2].dc_tbl_no = 1;
      v8[2].ac_tbl_no = 1;
      v8[2].component_id = 3;
      break;
    case JCS_CMYK:
      v9 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      v9->component_id = 67;
      v9->h_samp_factor = 1;
      v9->v_samp_factor = 1;
      v9->quant_tbl_no = 0;
      v9->dc_tbl_no = 0;
      v9->ac_tbl_no = 0;
      v10 = (jpeg_component_info *)cinfo[2].global_state;
      v10[1].component_id = 77;
      v10[1].h_samp_factor = 1;
      v10[1].v_samp_factor = 1;
      v10[1].quant_tbl_no = 0;
      v10[1].dc_tbl_no = 0;
      v10[1].ac_tbl_no = 0;
      v11 = (jpeg_component_info *)cinfo[2].global_state;
      v11[2].component_id = 89;
      v11[2].h_samp_factor = 1;
      v11[2].v_samp_factor = 1;
      v11[2].quant_tbl_no = 0;
      v11[2].dc_tbl_no = 0;
      v11[2].ac_tbl_no = 0;
      v12 = (jpeg_component_info *)cinfo[2].global_state;
      v12[3].component_id = 75;
      v12[3].h_samp_factor = 1;
      v12[3].v_samp_factor = 1;
      goto LABEL_8;
    case JCS_YCCK:
      v13 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      v13->component_id = 1;
      v13->h_samp_factor = 2;
      v13->v_samp_factor = 2;
      v13->quant_tbl_no = 0;
      v13->dc_tbl_no = 0;
      v13->ac_tbl_no = 0;
      v14 = (jpeg_component_info *)cinfo[2].global_state;
      v14[1].component_id = 2;
      v14[1].h_samp_factor = 1;
      v14[1].v_samp_factor = 1;
      v14[1].quant_tbl_no = 1;
      v14[1].dc_tbl_no = 1;
      v14[1].ac_tbl_no = 1;
      v15 = (jpeg_component_info *)cinfo[2].global_state;
      v15[2].component_id = 3;
      v15[2].h_samp_factor = 1;
      v15[2].v_samp_factor = 1;
      v15[2].quant_tbl_no = 1;
      v15[2].dc_tbl_no = 1;
      v15[2].ac_tbl_no = 1;
      v12 = (jpeg_component_info *)cinfo[2].global_state;
      v12[3].component_id = 4;
      v12[3].h_samp_factor = 2;
      v12[3].v_samp_factor = 2;
LABEL_8:
      v12[3].quant_tbl_no = 0;
      v12[3].dc_tbl_no = 0;
      v12[3].ac_tbl_no = 0;
      break;
    default:
      cinfo->err->msg_code = 10;
      cinfo->err->error_exit(a1: cinfo);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250E90
// Name: _jpeg_default_colorspace
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_default_colorspace(jpeg_common_struct *cinfo)
{
  jpeg_component_info *global_state; // esi
  jpeg_component_info *v2; // eax
  jpeg_component_info *v3; // eax
  jpeg_component_info *v4; // eax
  jpeg_component_info *v5; // esi

  switch ( *(_DWORD *)&cinfo[1].is_decompressor )
  {
    case 0:
      jpeg_set_colorspace(cinfo, colorspace: JCS_UNKNOWN);
      break;
    case 1:
      if ( cinfo->global_state != 100 )
      {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        cinfo->err->error_exit(a1: cinfo);
      }
      *(_DWORD *)&cinfo[2].is_decompressor = 1;
      LOBYTE(cinfo[8].mem) = 1;
      cinfo[2].client_data = (void *)1;
      LOBYTE(cinfo[8].client_data) = 0;
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      global_state->component_id = 1;
      global_state->h_samp_factor = 1;
      global_state->v_samp_factor = 1;
      global_state->quant_tbl_no = 0;
      global_state->dc_tbl_no = 0;
      global_state->ac_tbl_no = 0;
      break;
    case 2:
    case 3:
      jpeg_set_colorspace(cinfo, colorspace: JCS_YCbCr);
      break;
    case 4:
      jpeg_set_colorspace(cinfo, colorspace: JCS_CMYK);
      break;
    case 5:
      if ( cinfo->global_state != 100 )
      {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2 = (jpeg_component_info *)cinfo[2].global_state;
      *(_DWORD *)&cinfo[2].is_decompressor = 5;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      LOBYTE(cinfo[8].mem) = 0;
      v2->component_id = 1;
      v2->quant_tbl_no = 0;
      v2->dc_tbl_no = 0;
      v2->ac_tbl_no = 0;
      v2->h_samp_factor = 2;
      v2->v_samp_factor = 2;
      v3 = (jpeg_component_info *)cinfo[2].global_state;
      v3[1].component_id = 2;
      v3[1].h_samp_factor = 1;
      v3[1].v_samp_factor = 1;
      v3[1].quant_tbl_no = 1;
      v3[1].dc_tbl_no = 1;
      v3[1].ac_tbl_no = 1;
      v4 = (jpeg_component_info *)cinfo[2].global_state;
      v4[2].component_id = 3;
      v4[2].h_samp_factor = 1;
      v4[2].v_samp_factor = 1;
      v4[2].quant_tbl_no = 1;
      v4[2].dc_tbl_no = 1;
      v4[2].ac_tbl_no = 1;
      v5 = (jpeg_component_info *)cinfo[2].global_state;
      v5[3].h_samp_factor = 2;
      v5[3].v_samp_factor = 2;
      v5[3].component_id = 4;
      v5[3].quant_tbl_no = 0;
      v5[3].dc_tbl_no = 0;
      v5[3].ac_tbl_no = 0;
      break;
    default:
      cinfo->err->msg_code = 9;
      cinfo->err->error_exit(a1: cinfo);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10251020
// Name: _jpeg_set_defaults
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_defaults(jpeg_common_struct *cinfo)
{
  unsigned __int8 *p_is_decompressor; // eax
  int i; // ecx
  bool v3; // cc

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[2].global_state == 0 )
    cinfo[2].global_state = cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 840);
  cinfo[2].progress = (jpeg_progress_mgr *)8;
  jpeg_add_quant_table(cinfo, which_tbl: 0, basic_table: &basic_table, scale_factor: 50, force_baseline: 1u);
  jpeg_add_quant_table(cinfo, which_tbl: 1u, basic_table: &dword_103C9318, scale_factor: 50, force_baseline: 1u);
  std_huff_tables(cinfo);
  p_is_decompressor = &cinfo[5].is_decompressor;
  for ( i = 16; i != 0; --i )
  {
    *(p_is_decompressor - 16) = 0;
    *p_is_decompressor = 1;
    p_is_decompressor[16] = 5;
    ++p_is_decompressor;
  }
  v3 = (int)cinfo[2].progress <= 8;
  cinfo[7].mem = nullptr;
  cinfo[7].err = nullptr;
  LOWORD(cinfo[7].progress) = 0;
  BYTE2(cinfo[7].progress) = 0;
  if ( !v3 )
    BYTE2(cinfo[7].progress) = 1;
  HIBYTE(cinfo[7].progress) = 0;
  cinfo[7].client_data = nullptr;
  *(_DWORD *)&cinfo[7].is_decompressor = 0;
  cinfo[7].global_state = 0;
  cinfo[8].err = nullptr;
  *(_WORD *)((char *)&cinfo[8].mem + 1) = 257;
  HIBYTE(cinfo[8].mem) = 0;
  cinfo[8].progress = (jpeg_progress_mgr *)65537;
  jpeg_default_colorspace(cinfo);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10250820
// Name: _jpeg_add_quant_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_add_quant_table(
        jpeg_common_struct *cinfo,
        unsigned int which_tbl,
        const unsigned int *basic_table,
        int scale_factor,
        unsigned __int8 force_baseline)
{
  int v5; // esi
  const unsigned int *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( which_tbl >= 4 )
  {
    cinfo->err->msg_code = 31;
    cinfo->err->msg_parm.i[0] = which_tbl;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *((_DWORD *)&cinfo[3].err + which_tbl) == 0 )
    *((_DWORD *)&cinfo[3].err + which_tbl) = jpeg_alloc_quant_table(cinfo);
  v5 = 0;
  v6 = basic_table + 2;
  do
  {
    v7 = (signed int)(scale_factor * *(v6 - 2) + 50) / 100;
    if ( v7 > 0 )
    {
      if ( v7 > 0x7FFF )
        v7 = 0x7FFF;
    }
    else
    {
      v7 = 1;
    }
    if ( force_baseline != 0 && v7 > 255 )
      LOWORD(v7) = 255;
    *(_WORD *)(v5 + *((_DWORD *)&cinfo[3].err + which_tbl)) = v7;
    v8 = (signed int)(scale_factor * *(v6 - 1) + 50) / 100;
    if ( v8 > 0 )
    {
      if ( v8 > 0x7FFF )
        v8 = 0x7FFF;
    }
    else
    {
      v8 = 1;
    }
    if ( force_baseline != 0 && v8 > 255 )
      LOWORD(v8) = 255;
    *(_WORD *)(*((_DWORD *)&cinfo[3].err + which_tbl) + v5 + 2) = v8;
    v9 = (signed int)(scale_factor * *v6 + 50) / 100;
    if ( v9 > 0 )
    {
      if ( v9 > 0x7FFF )
        v9 = 0x7FFF;
    }
    else
    {
      v9 = 1;
    }
    if ( force_baseline != 0 && v9 > 255 )
      LOWORD(v9) = 255;
    *(_WORD *)(*((_DWORD *)&cinfo[3].err + which_tbl) + v5 + 4) = v9;
    v10 = (signed int)(scale_factor * v6[1] + 50) / 100;
    if ( v10 > 0 )
    {
      if ( v10 > 0x7FFF )
        v10 = 0x7FFF;
    }
    else
    {
      v10 = 1;
    }
    if ( force_baseline != 0 && v10 > 255 )
      LOWORD(v10) = 255;
    *(_WORD *)(v5 + *((_DWORD *)&cinfo[3].err + which_tbl) + 6) = v10;
    v5 += 8;
    v6 += 4;
  }
  while ( v5 < 128 );
  *(_BYTE *)(*((_DWORD *)&cinfo[3].err + which_tbl) + 128) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10250A00
// Name: _jpeg_set_quality
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_quality(jpeg_common_struct *cinfo, int quality, unsigned __int8 force_baseline)
{
  int v3; // ecx
  int v4; // esi

  v3 = quality;
  if ( quality > 0 )
  {
    if ( quality <= 100 )
    {
      if ( quality < 50 )
      {
        v4 = 5000 / quality;
        goto LABEL_6;
      }
    }
    else
    {
      v3 = 100;
    }
    v4 = 2 * (100 - v3);
  }
  else
  {
    v4 = 5000;
  }
LABEL_6:
  jpeg_add_quant_table(cinfo, which_tbl: 0, basic_table: &basic_table, scale_factor: v4, force_baseline);
  jpeg_add_quant_table(cinfo, which_tbl: 1u, basic_table: &dword_103C93E8, scale_factor: v4, force_baseline);
}

//------------------------------------------------------------------------------
// Address: 0x10250A70
// Name: add_huff_table
// Source: json
//------------------------------------------------------------------------------
void __usercall add_huff_table(
        const unsigned __int8 *bits@<eax>,
        jpeg_common_struct *cinfo,
        JHUFF_TBL **htblptr,
        unsigned __int8 *val)
{
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // edx
  int v9; // ecx
  const unsigned __int8 *v10; // eax
  signed int v11; // edi
  int i; // [esp+8h] [ebp-4h]

  if ( *htblptr == nullptr )
    *htblptr = jpeg_alloc_huff_table(cinfo);
  v5 = (int)*htblptr;
  *(_QWORD *)v5 = *(_QWORD *)bits;
  *(_QWORD *)(v5 + 8) = *((_QWORD *)bits + 1);
  *(_BYTE *)(v5 + 16) = bits[16];
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = bits + 2;
  for ( i = 4; i != 0; --i )
  {
    v6 += *(v10 - 1);
    v9 += *v10;
    v8 += v10[1];
    v7 += v10[2];
    v10 += 4;
  }
  v11 = v9 + v8 + v7 + v6;
  if ( v11 < 1 || v11 > 256 )
  {
    cinfo->err->msg_code = 8;
    cinfo->err->error_exit(a1: cinfo);
  }
  memcpy(dst: (*htblptr)->huffval, src: val, count: v11);
  (*htblptr)->sent_table = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10250B30
// Name: std_huff_tables
// Source: json
//------------------------------------------------------------------------------
void __usercall std_huff_tables(jpeg_common_struct *cinfo@<esi>)
{
  add_huff_table(
    bits: bits_dc_luminance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[3].is_decompressor,
    val: (unsigned __int8 *)val_dc_luminance);
  add_huff_table(
    bits: bits_ac_luminance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[4].progress,
    val: (unsigned __int8 *)val_ac_luminance);
  add_huff_table(
    bits: bits_dc_chrominance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[3].global_state,
    val: (unsigned __int8 *)val_dc_chrominance);
  add_huff_table(
    bits: bits_ac_chrominance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[4].client_data,
    val: (unsigned __int8 *)val_ac_chrominance);
}

//------------------------------------------------------------------------------
// Address: 0x10250B90
// Name: _jpeg_set_colorspace
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_colorspace(jpeg_common_struct *cinfo, J_COLOR_SPACE colorspace)
{
  jpeg_component_info *global_state; // esi
  jpeg_component_info *v3; // eax
  jpeg_component_info *v4; // eax
  jpeg_component_info *v5; // esi
  jpeg_component_info *v6; // eax
  jpeg_component_info *v7; // eax
  jpeg_component_info *v8; // esi
  jpeg_component_info *v9; // eax
  jpeg_component_info *v10; // eax
  jpeg_component_info *v11; // eax
  jpeg_component_info *v12; // esi
  jpeg_component_info *v13; // eax
  jpeg_component_info *v14; // eax
  jpeg_component_info *v15; // eax
  int client_data; // eax
  int v17; // ecx
  int v18; // edx
  jpeg_component_info *v19; // eax

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  *(_DWORD *)&cinfo[2].is_decompressor = colorspace;
  LOBYTE(cinfo[8].mem) = 0;
  LOBYTE(cinfo[8].client_data) = 0;
  switch ( colorspace )
  {
    case JCS_UNKNOWN:
      client_data = (int)cinfo[1].client_data;
      cinfo[2].client_data = (void *)client_data;
      if ( client_data < 1 || client_data > 10 )
      {
        cinfo->err->msg_code = 26;
        cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
        cinfo->err->msg_parm.i[1] = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v17 = 0;
      if ( (int)cinfo[2].client_data > 0 )
      {
        v18 = 0;
        do
        {
          v19 = (jpeg_component_info *)(v18 + cinfo[2].global_state);
          v19->component_id = v17++;
          v19->h_samp_factor = 1;
          v19->v_samp_factor = 1;
          v19->quant_tbl_no = 0;
          v19->dc_tbl_no = 0;
          v19->ac_tbl_no = 0;
          v18 += 84;
        }
        while ( v17 < (int)cinfo[2].client_data );
      }
      break;
    case JCS_GRAYSCALE:
      LOBYTE(cinfo[8].mem) = 1;
      cinfo[2].client_data = (void *)1;
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      global_state->component_id = 1;
      global_state->h_samp_factor = 1;
      global_state->v_samp_factor = 1;
      global_state->quant_tbl_no = 0;
      global_state->dc_tbl_no = 0;
      global_state->ac_tbl_no = 0;
      break;
    case JCS_RGB:
      v3 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)3;
      LOBYTE(cinfo[8].client_data) = 1;
      v3->h_samp_factor = 1;
      v3->v_samp_factor = 1;
      v3->component_id = 82;
      v3->quant_tbl_no = 0;
      v3->dc_tbl_no = 0;
      v3->ac_tbl_no = 0;
      v4 = (jpeg_component_info *)cinfo[2].global_state;
      v4[1].h_samp_factor = 1;
      v4[1].v_samp_factor = 1;
      v4[1].component_id = 71;
      v4[1].quant_tbl_no = 0;
      v4[1].dc_tbl_no = 0;
      v4[1].ac_tbl_no = 0;
      v5 = (jpeg_component_info *)cinfo[2].global_state;
      v5[2].h_samp_factor = 1;
      v5[2].v_samp_factor = 1;
      v5[2].component_id = 66;
      v5[2].quant_tbl_no = 0;
      v5[2].dc_tbl_no = 0;
      v5[2].ac_tbl_no = 0;
      break;
    case JCS_YCbCr:
      v6 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)3;
      LOBYTE(cinfo[8].mem) = 1;
      v6->component_id = 1;
      v6->h_samp_factor = 2;
      v6->v_samp_factor = 2;
      v6->quant_tbl_no = 0;
      v6->dc_tbl_no = 0;
      v6->ac_tbl_no = 0;
      v7 = (jpeg_component_info *)cinfo[2].global_state;
      v7[1].h_samp_factor = 1;
      v7[1].v_samp_factor = 1;
      v7[1].quant_tbl_no = 1;
      v7[1].dc_tbl_no = 1;
      v7[1].ac_tbl_no = 1;
      v7[1].component_id = 2;
      v8 = (jpeg_component_info *)cinfo[2].global_state;
      v8[2].h_samp_factor = 1;
      v8[2].v_samp_factor = 1;
      v8[2].quant_tbl_no = 1;
      v8[2].dc_tbl_no = 1;
      v8[2].ac_tbl_no = 1;
      v8[2].component_id = 3;
      break;
    case JCS_CMYK:
      v9 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      v9->component_id = 67;
      v9->h_samp_factor = 1;
      v9->v_samp_factor = 1;
      v9->quant_tbl_no = 0;
      v9->dc_tbl_no = 0;
      v9->ac_tbl_no = 0;
      v10 = (jpeg_component_info *)cinfo[2].global_state;
      v10[1].component_id = 77;
      v10[1].h_samp_factor = 1;
      v10[1].v_samp_factor = 1;
      v10[1].quant_tbl_no = 0;
      v10[1].dc_tbl_no = 0;
      v10[1].ac_tbl_no = 0;
      v11 = (jpeg_component_info *)cinfo[2].global_state;
      v11[2].component_id = 89;
      v11[2].h_samp_factor = 1;
      v11[2].v_samp_factor = 1;
      v11[2].quant_tbl_no = 0;
      v11[2].dc_tbl_no = 0;
      v11[2].ac_tbl_no = 0;
      v12 = (jpeg_component_info *)cinfo[2].global_state;
      v12[3].component_id = 75;
      v12[3].h_samp_factor = 1;
      v12[3].v_samp_factor = 1;
      goto LABEL_8;
    case JCS_YCCK:
      v13 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      v13->component_id = 1;
      v13->h_samp_factor = 2;
      v13->v_samp_factor = 2;
      v13->quant_tbl_no = 0;
      v13->dc_tbl_no = 0;
      v13->ac_tbl_no = 0;
      v14 = (jpeg_component_info *)cinfo[2].global_state;
      v14[1].component_id = 2;
      v14[1].h_samp_factor = 1;
      v14[1].v_samp_factor = 1;
      v14[1].quant_tbl_no = 1;
      v14[1].dc_tbl_no = 1;
      v14[1].ac_tbl_no = 1;
      v15 = (jpeg_component_info *)cinfo[2].global_state;
      v15[2].component_id = 3;
      v15[2].h_samp_factor = 1;
      v15[2].v_samp_factor = 1;
      v15[2].quant_tbl_no = 1;
      v15[2].dc_tbl_no = 1;
      v15[2].ac_tbl_no = 1;
      v12 = (jpeg_component_info *)cinfo[2].global_state;
      v12[3].component_id = 4;
      v12[3].h_samp_factor = 2;
      v12[3].v_samp_factor = 2;
LABEL_8:
      v12[3].quant_tbl_no = 0;
      v12[3].dc_tbl_no = 0;
      v12[3].ac_tbl_no = 0;
      break;
    default:
      cinfo->err->msg_code = 10;
      cinfo->err->error_exit(a1: cinfo);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250EB0
// Name: _jpeg_default_colorspace
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_default_colorspace(jpeg_common_struct *cinfo)
{
  jpeg_component_info *global_state; // esi
  jpeg_component_info *v2; // eax
  jpeg_component_info *v3; // eax
  jpeg_component_info *v4; // eax
  jpeg_component_info *v5; // esi

  switch ( *(_DWORD *)&cinfo[1].is_decompressor )
  {
    case 0:
      jpeg_set_colorspace(cinfo, colorspace: JCS_UNKNOWN);
      break;
    case 1:
      if ( cinfo->global_state != 100 )
      {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        cinfo->err->error_exit(a1: cinfo);
      }
      *(_DWORD *)&cinfo[2].is_decompressor = 1;
      LOBYTE(cinfo[8].mem) = 1;
      cinfo[2].client_data = (void *)1;
      LOBYTE(cinfo[8].client_data) = 0;
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      global_state->component_id = 1;
      global_state->h_samp_factor = 1;
      global_state->v_samp_factor = 1;
      global_state->quant_tbl_no = 0;
      global_state->dc_tbl_no = 0;
      global_state->ac_tbl_no = 0;
      break;
    case 2:
    case 3:
      jpeg_set_colorspace(cinfo, colorspace: JCS_YCbCr);
      break;
    case 4:
      jpeg_set_colorspace(cinfo, colorspace: JCS_CMYK);
      break;
    case 5:
      if ( cinfo->global_state != 100 )
      {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2 = (jpeg_component_info *)cinfo[2].global_state;
      *(_DWORD *)&cinfo[2].is_decompressor = 5;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      LOBYTE(cinfo[8].mem) = 0;
      v2->component_id = 1;
      v2->quant_tbl_no = 0;
      v2->dc_tbl_no = 0;
      v2->ac_tbl_no = 0;
      v2->h_samp_factor = 2;
      v2->v_samp_factor = 2;
      v3 = (jpeg_component_info *)cinfo[2].global_state;
      v3[1].component_id = 2;
      v3[1].h_samp_factor = 1;
      v3[1].v_samp_factor = 1;
      v3[1].quant_tbl_no = 1;
      v3[1].dc_tbl_no = 1;
      v3[1].ac_tbl_no = 1;
      v4 = (jpeg_component_info *)cinfo[2].global_state;
      v4[2].component_id = 3;
      v4[2].h_samp_factor = 1;
      v4[2].v_samp_factor = 1;
      v4[2].quant_tbl_no = 1;
      v4[2].dc_tbl_no = 1;
      v4[2].ac_tbl_no = 1;
      v5 = (jpeg_component_info *)cinfo[2].global_state;
      v5[3].h_samp_factor = 2;
      v5[3].v_samp_factor = 2;
      v5[3].component_id = 4;
      v5[3].quant_tbl_no = 0;
      v5[3].dc_tbl_no = 0;
      v5[3].ac_tbl_no = 0;
      break;
    default:
      cinfo->err->msg_code = 9;
      cinfo->err->error_exit(a1: cinfo);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10251040
// Name: _jpeg_set_defaults
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_defaults(jpeg_common_struct *cinfo)
{
  unsigned __int8 *p_is_decompressor; // eax
  int i; // ecx
  bool v3; // cc

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[2].global_state == 0 )
    cinfo[2].global_state = cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 840);
  cinfo[2].progress = (jpeg_progress_mgr *)8;
  jpeg_add_quant_table(cinfo, which_tbl: 0, basic_table: &basic_table, scale_factor: 50, force_baseline: 1u);
  jpeg_add_quant_table(cinfo, which_tbl: 1u, basic_table: &dword_103C93E8, scale_factor: 50, force_baseline: 1u);
  std_huff_tables(cinfo);
  p_is_decompressor = &cinfo[5].is_decompressor;
  for ( i = 16; i != 0; --i )
  {
    *(p_is_decompressor - 16) = 0;
    *p_is_decompressor = 1;
    p_is_decompressor[16] = 5;
    ++p_is_decompressor;
  }
  v3 = (int)cinfo[2].progress <= 8;
  cinfo[7].mem = nullptr;
  cinfo[7].err = nullptr;
  LOWORD(cinfo[7].progress) = 0;
  BYTE2(cinfo[7].progress) = 0;
  if ( !v3 )
    BYTE2(cinfo[7].progress) = 1;
  HIBYTE(cinfo[7].progress) = 0;
  cinfo[7].client_data = nullptr;
  *(_DWORD *)&cinfo[7].is_decompressor = 0;
  cinfo[7].global_state = 0;
  cinfo[8].err = nullptr;
  *(_WORD *)((char *)&cinfo[8].mem + 1) = 257;
  HIBYTE(cinfo[8].mem) = 0;
  cinfo[8].progress = (jpeg_progress_mgr *)65537;
  jpeg_default_colorspace(cinfo);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x00404D30
// Name: _jpeg_add_quant_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_add_quant_table(
        jpeg_common_struct *cinfo,
        unsigned int which_tbl,
        const unsigned int *basic_table,
        int scale_factor,
        unsigned __int8 force_baseline)
{
  int v5; // esi
  const unsigned int *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( which_tbl >= 4 )
  {
    cinfo->err->msg_code = 31;
    cinfo->err->msg_parm.i[0] = which_tbl;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *((_DWORD *)&cinfo[3].err + which_tbl) == 0 )
    *((_DWORD *)&cinfo[3].err + which_tbl) = jpeg_alloc_quant_table(cinfo);
  v5 = 0;
  v6 = basic_table + 2;
  do
  {
    v7 = (signed int)(scale_factor * *(v6 - 2) + 50) / 100;
    if ( v7 > 0 )
    {
      if ( v7 > 0x7FFF )
        v7 = 0x7FFF;
    }
    else
    {
      v7 = 1;
    }
    if ( force_baseline != 0 && v7 > 255 )
      LOWORD(v7) = 255;
    *(_WORD *)(v5 + *((_DWORD *)&cinfo[3].err + which_tbl)) = v7;
    v8 = (signed int)(scale_factor * *(v6 - 1) + 50) / 100;
    if ( v8 > 0 )
    {
      if ( v8 > 0x7FFF )
        v8 = 0x7FFF;
    }
    else
    {
      v8 = 1;
    }
    if ( force_baseline != 0 && v8 > 255 )
      LOWORD(v8) = 255;
    *(_WORD *)(*((_DWORD *)&cinfo[3].err + which_tbl) + v5 + 2) = v8;
    v9 = (signed int)(scale_factor * *v6 + 50) / 100;
    if ( v9 > 0 )
    {
      if ( v9 > 0x7FFF )
        v9 = 0x7FFF;
    }
    else
    {
      v9 = 1;
    }
    if ( force_baseline != 0 && v9 > 255 )
      LOWORD(v9) = 255;
    *(_WORD *)(*((_DWORD *)&cinfo[3].err + which_tbl) + v5 + 4) = v9;
    v10 = (signed int)(scale_factor * v6[1] + 50) / 100;
    if ( v10 > 0 )
    {
      if ( v10 > 0x7FFF )
        v10 = 0x7FFF;
    }
    else
    {
      v10 = 1;
    }
    if ( force_baseline != 0 && v10 > 255 )
      LOWORD(v10) = 255;
    *(_WORD *)(v5 + *((_DWORD *)&cinfo[3].err + which_tbl) + 6) = v10;
    v5 += 8;
    v6 += 4;
  }
  while ( v5 < 128 );
  *(_BYTE *)(*((_DWORD *)&cinfo[3].err + which_tbl) + 128) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404F10
// Name: _jpeg_set_quality
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_quality(jpeg_common_struct *cinfo, int quality, unsigned __int8 force_baseline)
{
  int v3; // ecx
  int v4; // esi

  v3 = quality;
  if ( quality > 0 )
  {
    if ( quality <= 100 )
    {
      if ( quality < 50 )
      {
        v4 = 5000 / quality;
        goto LABEL_6;
      }
    }
    else
    {
      v3 = 100;
    }
    v4 = 2 * (100 - v3);
  }
  else
  {
    v4 = 5000;
  }
LABEL_6:
  jpeg_add_quant_table(cinfo, which_tbl: 0, basic_table: &basic_table, scale_factor: v4, force_baseline);
  jpeg_add_quant_table(cinfo, which_tbl: 1u, basic_table: &dword_4200E8, scale_factor: v4, force_baseline);
}

//------------------------------------------------------------------------------
// Address: 0x00404F80
// Name: add_huff_table
// Source: json
//------------------------------------------------------------------------------
void __usercall add_huff_table(
        const unsigned __int8 *bits@<eax>,
        jpeg_common_struct *cinfo,
        JHUFF_TBL **htblptr,
        unsigned __int8 *val)
{
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // edx
  int v9; // ecx
  const unsigned __int8 *v10; // eax
  signed int v11; // edi
  int i; // [esp+8h] [ebp-4h]

  if ( *htblptr == nullptr )
    *htblptr = jpeg_alloc_huff_table(cinfo);
  v5 = (int)*htblptr;
  *(_QWORD *)v5 = *(_QWORD *)bits;
  *(_QWORD *)(v5 + 8) = *((_QWORD *)bits + 1);
  *(_BYTE *)(v5 + 16) = bits[16];
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = bits + 2;
  for ( i = 4; i != 0; --i )
  {
    v6 += *(v10 - 1);
    v9 += *v10;
    v8 += v10[1];
    v7 += v10[2];
    v10 += 4;
  }
  v11 = v9 + v8 + v7 + v6;
  if ( v11 < 1 || v11 > 256 )
  {
    cinfo->err->msg_code = 8;
    cinfo->err->error_exit(a1: cinfo);
  }
  memcpy(dst: (*htblptr)->huffval, src: val, count: v11);
  (*htblptr)->sent_table = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405040
// Name: std_huff_tables
// Source: json
//------------------------------------------------------------------------------
void __usercall std_huff_tables(jpeg_common_struct *cinfo@<esi>)
{
  add_huff_table(
    bits: bits_dc_luminance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[3].is_decompressor,
    val: (unsigned __int8 *)val_dc_luminance);
  add_huff_table(
    bits: bits_ac_luminance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[4].progress,
    val: (unsigned __int8 *)val_ac_luminance);
  add_huff_table(
    bits: bits_dc_chrominance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[3].global_state,
    val: (unsigned __int8 *)val_dc_chrominance);
  add_huff_table(
    bits: bits_ac_chrominance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[4].client_data,
    val: (unsigned __int8 *)val_ac_chrominance);
}

//------------------------------------------------------------------------------
// Address: 0x004050A0
// Name: _jpeg_set_colorspace
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_colorspace(jpeg_common_struct *cinfo, J_COLOR_SPACE colorspace)
{
  jpeg_component_info *global_state; // esi
  jpeg_component_info *v3; // eax
  jpeg_component_info *v4; // eax
  jpeg_component_info *v5; // esi
  jpeg_component_info *v6; // eax
  jpeg_component_info *v7; // eax
  jpeg_component_info *v8; // esi
  jpeg_component_info *v9; // eax
  jpeg_component_info *v10; // eax
  jpeg_component_info *v11; // eax
  jpeg_component_info *v12; // esi
  jpeg_component_info *v13; // eax
  jpeg_component_info *v14; // eax
  jpeg_component_info *v15; // eax
  int client_data; // eax
  int v17; // ecx
  int v18; // edx
  jpeg_component_info *v19; // eax

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  *(_DWORD *)&cinfo[2].is_decompressor = colorspace;
  LOBYTE(cinfo[8].mem) = 0;
  LOBYTE(cinfo[8].client_data) = 0;
  switch ( colorspace )
  {
    case JCS_UNKNOWN:
      client_data = (int)cinfo[1].client_data;
      cinfo[2].client_data = (void *)client_data;
      if ( client_data < 1 || client_data > 10 )
      {
        cinfo->err->msg_code = 26;
        cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
        cinfo->err->msg_parm.i[1] = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v17 = 0;
      if ( (int)cinfo[2].client_data > 0 )
      {
        v18 = 0;
        do
        {
          v19 = (jpeg_component_info *)(v18 + cinfo[2].global_state);
          v19->component_id = v17++;
          v19->h_samp_factor = 1;
          v19->v_samp_factor = 1;
          v19->quant_tbl_no = 0;
          v19->dc_tbl_no = 0;
          v19->ac_tbl_no = 0;
          v18 += 84;
        }
        while ( v17 < (int)cinfo[2].client_data );
      }
      break;
    case JCS_GRAYSCALE:
      LOBYTE(cinfo[8].mem) = 1;
      cinfo[2].client_data = (void *)1;
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      global_state->component_id = 1;
      global_state->h_samp_factor = 1;
      global_state->v_samp_factor = 1;
      global_state->quant_tbl_no = 0;
      global_state->dc_tbl_no = 0;
      global_state->ac_tbl_no = 0;
      break;
    case JCS_RGB:
      v3 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)3;
      LOBYTE(cinfo[8].client_data) = 1;
      v3->h_samp_factor = 1;
      v3->v_samp_factor = 1;
      v3->component_id = 82;
      v3->quant_tbl_no = 0;
      v3->dc_tbl_no = 0;
      v3->ac_tbl_no = 0;
      v4 = (jpeg_component_info *)cinfo[2].global_state;
      v4[1].h_samp_factor = 1;
      v4[1].v_samp_factor = 1;
      v4[1].component_id = 71;
      v4[1].quant_tbl_no = 0;
      v4[1].dc_tbl_no = 0;
      v4[1].ac_tbl_no = 0;
      v5 = (jpeg_component_info *)cinfo[2].global_state;
      v5[2].h_samp_factor = 1;
      v5[2].v_samp_factor = 1;
      v5[2].component_id = 66;
      v5[2].quant_tbl_no = 0;
      v5[2].dc_tbl_no = 0;
      v5[2].ac_tbl_no = 0;
      break;
    case JCS_YCbCr:
      v6 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)3;
      LOBYTE(cinfo[8].mem) = 1;
      v6->component_id = 1;
      v6->h_samp_factor = 2;
      v6->v_samp_factor = 2;
      v6->quant_tbl_no = 0;
      v6->dc_tbl_no = 0;
      v6->ac_tbl_no = 0;
      v7 = (jpeg_component_info *)cinfo[2].global_state;
      v7[1].h_samp_factor = 1;
      v7[1].v_samp_factor = 1;
      v7[1].quant_tbl_no = 1;
      v7[1].dc_tbl_no = 1;
      v7[1].ac_tbl_no = 1;
      v7[1].component_id = 2;
      v8 = (jpeg_component_info *)cinfo[2].global_state;
      v8[2].h_samp_factor = 1;
      v8[2].v_samp_factor = 1;
      v8[2].quant_tbl_no = 1;
      v8[2].dc_tbl_no = 1;
      v8[2].ac_tbl_no = 1;
      v8[2].component_id = 3;
      break;
    case JCS_CMYK:
      v9 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      v9->component_id = 67;
      v9->h_samp_factor = 1;
      v9->v_samp_factor = 1;
      v9->quant_tbl_no = 0;
      v9->dc_tbl_no = 0;
      v9->ac_tbl_no = 0;
      v10 = (jpeg_component_info *)cinfo[2].global_state;
      v10[1].component_id = 77;
      v10[1].h_samp_factor = 1;
      v10[1].v_samp_factor = 1;
      v10[1].quant_tbl_no = 0;
      v10[1].dc_tbl_no = 0;
      v10[1].ac_tbl_no = 0;
      v11 = (jpeg_component_info *)cinfo[2].global_state;
      v11[2].component_id = 89;
      v11[2].h_samp_factor = 1;
      v11[2].v_samp_factor = 1;
      v11[2].quant_tbl_no = 0;
      v11[2].dc_tbl_no = 0;
      v11[2].ac_tbl_no = 0;
      v12 = (jpeg_component_info *)cinfo[2].global_state;
      v12[3].component_id = 75;
      v12[3].h_samp_factor = 1;
      v12[3].v_samp_factor = 1;
      goto LABEL_8;
    case JCS_YCCK:
      v13 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      v13->component_id = 1;
      v13->h_samp_factor = 2;
      v13->v_samp_factor = 2;
      v13->quant_tbl_no = 0;
      v13->dc_tbl_no = 0;
      v13->ac_tbl_no = 0;
      v14 = (jpeg_component_info *)cinfo[2].global_state;
      v14[1].component_id = 2;
      v14[1].h_samp_factor = 1;
      v14[1].v_samp_factor = 1;
      v14[1].quant_tbl_no = 1;
      v14[1].dc_tbl_no = 1;
      v14[1].ac_tbl_no = 1;
      v15 = (jpeg_component_info *)cinfo[2].global_state;
      v15[2].component_id = 3;
      v15[2].h_samp_factor = 1;
      v15[2].v_samp_factor = 1;
      v15[2].quant_tbl_no = 1;
      v15[2].dc_tbl_no = 1;
      v15[2].ac_tbl_no = 1;
      v12 = (jpeg_component_info *)cinfo[2].global_state;
      v12[3].component_id = 4;
      v12[3].h_samp_factor = 2;
      v12[3].v_samp_factor = 2;
LABEL_8:
      v12[3].quant_tbl_no = 0;
      v12[3].dc_tbl_no = 0;
      v12[3].ac_tbl_no = 0;
      break;
    default:
      cinfo->err->msg_code = 10;
      cinfo->err->error_exit(a1: cinfo);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004053C0
// Name: _jpeg_default_colorspace
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_default_colorspace(jpeg_common_struct *cinfo)
{
  jpeg_component_info *global_state; // esi
  jpeg_component_info *v2; // eax
  jpeg_component_info *v3; // eax
  jpeg_component_info *v4; // eax
  jpeg_component_info *v5; // esi

  switch ( *(_DWORD *)&cinfo[1].is_decompressor )
  {
    case 0:
      jpeg_set_colorspace(cinfo, colorspace: JCS_UNKNOWN);
      break;
    case 1:
      if ( cinfo->global_state != 100 )
      {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        cinfo->err->error_exit(a1: cinfo);
      }
      *(_DWORD *)&cinfo[2].is_decompressor = 1;
      LOBYTE(cinfo[8].mem) = 1;
      cinfo[2].client_data = (void *)1;
      LOBYTE(cinfo[8].client_data) = 0;
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      global_state->component_id = 1;
      global_state->h_samp_factor = 1;
      global_state->v_samp_factor = 1;
      global_state->quant_tbl_no = 0;
      global_state->dc_tbl_no = 0;
      global_state->ac_tbl_no = 0;
      break;
    case 2:
    case 3:
      jpeg_set_colorspace(cinfo, colorspace: JCS_YCbCr);
      break;
    case 4:
      jpeg_set_colorspace(cinfo, colorspace: JCS_CMYK);
      break;
    case 5:
      if ( cinfo->global_state != 100 )
      {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2 = (jpeg_component_info *)cinfo[2].global_state;
      *(_DWORD *)&cinfo[2].is_decompressor = 5;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      LOBYTE(cinfo[8].mem) = 0;
      v2->component_id = 1;
      v2->quant_tbl_no = 0;
      v2->dc_tbl_no = 0;
      v2->ac_tbl_no = 0;
      v2->h_samp_factor = 2;
      v2->v_samp_factor = 2;
      v3 = (jpeg_component_info *)cinfo[2].global_state;
      v3[1].component_id = 2;
      v3[1].h_samp_factor = 1;
      v3[1].v_samp_factor = 1;
      v3[1].quant_tbl_no = 1;
      v3[1].dc_tbl_no = 1;
      v3[1].ac_tbl_no = 1;
      v4 = (jpeg_component_info *)cinfo[2].global_state;
      v4[2].component_id = 3;
      v4[2].h_samp_factor = 1;
      v4[2].v_samp_factor = 1;
      v4[2].quant_tbl_no = 1;
      v4[2].dc_tbl_no = 1;
      v4[2].ac_tbl_no = 1;
      v5 = (jpeg_component_info *)cinfo[2].global_state;
      v5[3].h_samp_factor = 2;
      v5[3].v_samp_factor = 2;
      v5[3].component_id = 4;
      v5[3].quant_tbl_no = 0;
      v5[3].dc_tbl_no = 0;
      v5[3].ac_tbl_no = 0;
      break;
    default:
      cinfo->err->msg_code = 9;
      cinfo->err->error_exit(a1: cinfo);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405550
// Name: _jpeg_set_defaults
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_defaults(jpeg_common_struct *cinfo)
{
  unsigned __int8 *p_is_decompressor; // eax
  int i; // ecx
  bool v3; // cc

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[2].global_state == 0 )
    cinfo[2].global_state = cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 840);
  cinfo[2].progress = (jpeg_progress_mgr *)8;
  jpeg_add_quant_table(cinfo, which_tbl: 0, basic_table: &basic_table, scale_factor: 50, force_baseline: 1u);
  jpeg_add_quant_table(cinfo, which_tbl: 1u, basic_table: &dword_4200E8, scale_factor: 50, force_baseline: 1u);
  std_huff_tables(cinfo);
  p_is_decompressor = &cinfo[5].is_decompressor;
  for ( i = 16; i != 0; --i )
  {
    *(p_is_decompressor - 16) = 0;
    *p_is_decompressor = 1;
    p_is_decompressor[16] = 5;
    ++p_is_decompressor;
  }
  v3 = (int)cinfo[2].progress <= 8;
  cinfo[7].mem = nullptr;
  cinfo[7].err = nullptr;
  LOWORD(cinfo[7].progress) = 0;
  BYTE2(cinfo[7].progress) = 0;
  if ( !v3 )
    BYTE2(cinfo[7].progress) = 1;
  HIBYTE(cinfo[7].progress) = 0;
  cinfo[7].client_data = nullptr;
  *(_DWORD *)&cinfo[7].is_decompressor = 0;
  cinfo[7].global_state = 0;
  cinfo[8].err = nullptr;
  *(_WORD *)((char *)&cinfo[8].mem + 1) = 257;
  HIBYTE(cinfo[8].mem) = 0;
  cinfo[8].progress = (jpeg_progress_mgr *)65537;
  jpeg_default_colorspace(cinfo);
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x0042E040
// Name: _jpeg_add_quant_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_add_quant_table(
        jpeg_common_struct *cinfo,
        unsigned int which_tbl,
        const unsigned int *basic_table,
        int scale_factor,
        unsigned __int8 force_baseline)
{
  int v5; // esi
  const unsigned int *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( which_tbl >= 4 )
  {
    cinfo->err->msg_code = 31;
    cinfo->err->msg_parm.i[0] = which_tbl;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *((_DWORD *)&cinfo[3].err + which_tbl) == 0 )
    *((_DWORD *)&cinfo[3].err + which_tbl) = jpeg_alloc_quant_table(cinfo);
  v5 = 0;
  v6 = basic_table + 2;
  do
  {
    v7 = (signed int)(scale_factor * *(v6 - 2) + 50) / 100;
    if ( v7 > 0 )
    {
      if ( v7 > 0x7FFF )
        v7 = 0x7FFF;
    }
    else
    {
      v7 = 1;
    }
    if ( force_baseline != 0 && v7 > 255 )
      LOWORD(v7) = 255;
    *(_WORD *)(v5 + *((_DWORD *)&cinfo[3].err + which_tbl)) = v7;
    v8 = (signed int)(scale_factor * *(v6 - 1) + 50) / 100;
    if ( v8 > 0 )
    {
      if ( v8 > 0x7FFF )
        v8 = 0x7FFF;
    }
    else
    {
      v8 = 1;
    }
    if ( force_baseline != 0 && v8 > 255 )
      LOWORD(v8) = 255;
    *(_WORD *)(*((_DWORD *)&cinfo[3].err + which_tbl) + v5 + 2) = v8;
    v9 = (signed int)(scale_factor * *v6 + 50) / 100;
    if ( v9 > 0 )
    {
      if ( v9 > 0x7FFF )
        v9 = 0x7FFF;
    }
    else
    {
      v9 = 1;
    }
    if ( force_baseline != 0 && v9 > 255 )
      LOWORD(v9) = 255;
    *(_WORD *)(*((_DWORD *)&cinfo[3].err + which_tbl) + v5 + 4) = v9;
    v10 = (signed int)(scale_factor * v6[1] + 50) / 100;
    if ( v10 > 0 )
    {
      if ( v10 > 0x7FFF )
        v10 = 0x7FFF;
    }
    else
    {
      v10 = 1;
    }
    if ( force_baseline != 0 && v10 > 255 )
      LOWORD(v10) = 255;
    *(_WORD *)(v5 + *((_DWORD *)&cinfo[3].err + which_tbl) + 6) = v10;
    v5 += 8;
    v6 += 4;
  }
  while ( v5 < 128 );
  *(_BYTE *)(*((_DWORD *)&cinfo[3].err + which_tbl) + 128) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042E220
// Name: _jpeg_set_quality
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_quality(jpeg_common_struct *cinfo, int quality, unsigned __int8 force_baseline)
{
  int v3; // ecx
  int v4; // esi

  v3 = quality;
  if ( quality > 0 )
  {
    if ( quality <= 100 )
    {
      if ( quality < 50 )
      {
        v4 = 5000 / quality;
        goto LABEL_6;
      }
    }
    else
    {
      v3 = 100;
    }
    v4 = 2 * (100 - v3);
  }
  else
  {
    v4 = 5000;
  }
LABEL_6:
  jpeg_add_quant_table(cinfo, which_tbl: 0, basic_table: &basic_table, scale_factor: v4, force_baseline);
  jpeg_add_quant_table(cinfo, which_tbl: 1u, basic_table: &dword_457400, scale_factor: v4, force_baseline);
}

//------------------------------------------------------------------------------
// Address: 0x0042E290
// Name: add_huff_table
// Source: json
//------------------------------------------------------------------------------
void __usercall add_huff_table(
        const unsigned __int8 *bits@<eax>,
        jpeg_common_struct *cinfo,
        JHUFF_TBL **htblptr,
        unsigned __int8 *val)
{
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // edx
  int v9; // ecx
  const unsigned __int8 *v10; // eax
  signed int v11; // edi
  int i; // [esp+8h] [ebp-4h]

  if ( *htblptr == nullptr )
    *htblptr = jpeg_alloc_huff_table(cinfo);
  v5 = (int)*htblptr;
  *(_QWORD *)v5 = *(_QWORD *)bits;
  *(_QWORD *)(v5 + 8) = *((_QWORD *)bits + 1);
  *(_BYTE *)(v5 + 16) = bits[16];
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = bits + 2;
  for ( i = 4; i != 0; --i )
  {
    v6 += *(v10 - 1);
    v9 += *v10;
    v8 += v10[1];
    v7 += v10[2];
    v10 += 4;
  }
  v11 = v9 + v8 + v7 + v6;
  if ( v11 < 1 || v11 > 256 )
  {
    cinfo->err->msg_code = 8;
    cinfo->err->error_exit(a1: cinfo);
  }
  memcpy(dst: (*htblptr)->huffval, src: val, count: v11);
  (*htblptr)->sent_table = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042E350
// Name: std_huff_tables
// Source: json
//------------------------------------------------------------------------------
void __usercall std_huff_tables(jpeg_common_struct *cinfo@<esi>)
{
  add_huff_table(
    bits: bits_dc_luminance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[3].is_decompressor,
    val: (unsigned __int8 *)val_dc_luminance);
  add_huff_table(
    bits: bits_ac_luminance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[4].progress,
    val: (unsigned __int8 *)val_ac_luminance);
  add_huff_table(
    bits: bits_dc_chrominance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[3].global_state,
    val: (unsigned __int8 *)val_dc_chrominance);
  add_huff_table(
    bits: bits_ac_chrominance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[4].client_data,
    val: (unsigned __int8 *)val_ac_chrominance);
}

//------------------------------------------------------------------------------
// Address: 0x0042E3B0
// Name: _jpeg_set_colorspace
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_colorspace(jpeg_common_struct *cinfo, J_COLOR_SPACE colorspace)
{
  jpeg_component_info *global_state; // esi
  jpeg_component_info *v3; // eax
  jpeg_component_info *v4; // eax
  jpeg_component_info *v5; // esi
  jpeg_component_info *v6; // eax
  jpeg_component_info *v7; // eax
  jpeg_component_info *v8; // esi
  jpeg_component_info *v9; // eax
  jpeg_component_info *v10; // eax
  jpeg_component_info *v11; // eax
  jpeg_component_info *v12; // esi
  jpeg_component_info *v13; // eax
  jpeg_component_info *v14; // eax
  jpeg_component_info *v15; // eax
  int client_data; // eax
  int v17; // ecx
  int v18; // edx
  jpeg_component_info *v19; // eax

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  *(_DWORD *)&cinfo[2].is_decompressor = colorspace;
  LOBYTE(cinfo[8].mem) = 0;
  LOBYTE(cinfo[8].client_data) = 0;
  switch ( colorspace )
  {
    case JCS_UNKNOWN:
      client_data = (int)cinfo[1].client_data;
      cinfo[2].client_data = (void *)client_data;
      if ( client_data < 1 || client_data > 10 )
      {
        cinfo->err->msg_code = 26;
        cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
        cinfo->err->msg_parm.i[1] = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v17 = 0;
      if ( (int)cinfo[2].client_data > 0 )
      {
        v18 = 0;
        do
        {
          v19 = (jpeg_component_info *)(v18 + cinfo[2].global_state);
          v19->component_id = v17++;
          v19->h_samp_factor = 1;
          v19->v_samp_factor = 1;
          v19->quant_tbl_no = 0;
          v19->dc_tbl_no = 0;
          v19->ac_tbl_no = 0;
          v18 += 84;
        }
        while ( v17 < (int)cinfo[2].client_data );
      }
      break;
    case JCS_GRAYSCALE:
      LOBYTE(cinfo[8].mem) = 1;
      cinfo[2].client_data = (void *)1;
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      global_state->component_id = 1;
      global_state->h_samp_factor = 1;
      global_state->v_samp_factor = 1;
      global_state->quant_tbl_no = 0;
      global_state->dc_tbl_no = 0;
      global_state->ac_tbl_no = 0;
      break;
    case JCS_RGB:
      v3 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)3;
      LOBYTE(cinfo[8].client_data) = 1;
      v3->h_samp_factor = 1;
      v3->v_samp_factor = 1;
      v3->component_id = 82;
      v3->quant_tbl_no = 0;
      v3->dc_tbl_no = 0;
      v3->ac_tbl_no = 0;
      v4 = (jpeg_component_info *)cinfo[2].global_state;
      v4[1].h_samp_factor = 1;
      v4[1].v_samp_factor = 1;
      v4[1].component_id = 71;
      v4[1].quant_tbl_no = 0;
      v4[1].dc_tbl_no = 0;
      v4[1].ac_tbl_no = 0;
      v5 = (jpeg_component_info *)cinfo[2].global_state;
      v5[2].h_samp_factor = 1;
      v5[2].v_samp_factor = 1;
      v5[2].component_id = 66;
      v5[2].quant_tbl_no = 0;
      v5[2].dc_tbl_no = 0;
      v5[2].ac_tbl_no = 0;
      break;
    case JCS_YCbCr:
      v6 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)3;
      LOBYTE(cinfo[8].mem) = 1;
      v6->component_id = 1;
      v6->h_samp_factor = 2;
      v6->v_samp_factor = 2;
      v6->quant_tbl_no = 0;
      v6->dc_tbl_no = 0;
      v6->ac_tbl_no = 0;
      v7 = (jpeg_component_info *)cinfo[2].global_state;
      v7[1].h_samp_factor = 1;
      v7[1].v_samp_factor = 1;
      v7[1].quant_tbl_no = 1;
      v7[1].dc_tbl_no = 1;
      v7[1].ac_tbl_no = 1;
      v7[1].component_id = 2;
      v8 = (jpeg_component_info *)cinfo[2].global_state;
      v8[2].h_samp_factor = 1;
      v8[2].v_samp_factor = 1;
      v8[2].quant_tbl_no = 1;
      v8[2].dc_tbl_no = 1;
      v8[2].ac_tbl_no = 1;
      v8[2].component_id = 3;
      break;
    case JCS_CMYK:
      v9 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      v9->component_id = 67;
      v9->h_samp_factor = 1;
      v9->v_samp_factor = 1;
      v9->quant_tbl_no = 0;
      v9->dc_tbl_no = 0;
      v9->ac_tbl_no = 0;
      v10 = (jpeg_component_info *)cinfo[2].global_state;
      v10[1].component_id = 77;
      v10[1].h_samp_factor = 1;
      v10[1].v_samp_factor = 1;
      v10[1].quant_tbl_no = 0;
      v10[1].dc_tbl_no = 0;
      v10[1].ac_tbl_no = 0;
      v11 = (jpeg_component_info *)cinfo[2].global_state;
      v11[2].component_id = 89;
      v11[2].h_samp_factor = 1;
      v11[2].v_samp_factor = 1;
      v11[2].quant_tbl_no = 0;
      v11[2].dc_tbl_no = 0;
      v11[2].ac_tbl_no = 0;
      v12 = (jpeg_component_info *)cinfo[2].global_state;
      v12[3].component_id = 75;
      v12[3].h_samp_factor = 1;
      v12[3].v_samp_factor = 1;
      goto LABEL_8;
    case JCS_YCCK:
      v13 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      v13->component_id = 1;
      v13->h_samp_factor = 2;
      v13->v_samp_factor = 2;
      v13->quant_tbl_no = 0;
      v13->dc_tbl_no = 0;
      v13->ac_tbl_no = 0;
      v14 = (jpeg_component_info *)cinfo[2].global_state;
      v14[1].component_id = 2;
      v14[1].h_samp_factor = 1;
      v14[1].v_samp_factor = 1;
      v14[1].quant_tbl_no = 1;
      v14[1].dc_tbl_no = 1;
      v14[1].ac_tbl_no = 1;
      v15 = (jpeg_component_info *)cinfo[2].global_state;
      v15[2].component_id = 3;
      v15[2].h_samp_factor = 1;
      v15[2].v_samp_factor = 1;
      v15[2].quant_tbl_no = 1;
      v15[2].dc_tbl_no = 1;
      v15[2].ac_tbl_no = 1;
      v12 = (jpeg_component_info *)cinfo[2].global_state;
      v12[3].component_id = 4;
      v12[3].h_samp_factor = 2;
      v12[3].v_samp_factor = 2;
LABEL_8:
      v12[3].quant_tbl_no = 0;
      v12[3].dc_tbl_no = 0;
      v12[3].ac_tbl_no = 0;
      break;
    default:
      cinfo->err->msg_code = 10;
      cinfo->err->error_exit(a1: cinfo);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E6D0
// Name: _jpeg_default_colorspace
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_default_colorspace(jpeg_common_struct *cinfo)
{
  jpeg_component_info *global_state; // esi
  jpeg_component_info *v2; // eax
  jpeg_component_info *v3; // eax
  jpeg_component_info *v4; // eax
  jpeg_component_info *v5; // esi

  switch ( *(_DWORD *)&cinfo[1].is_decompressor )
  {
    case 0:
      jpeg_set_colorspace(cinfo, colorspace: JCS_UNKNOWN);
      break;
    case 1:
      if ( cinfo->global_state != 100 )
      {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        cinfo->err->error_exit(a1: cinfo);
      }
      *(_DWORD *)&cinfo[2].is_decompressor = 1;
      LOBYTE(cinfo[8].mem) = 1;
      cinfo[2].client_data = (void *)1;
      LOBYTE(cinfo[8].client_data) = 0;
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      global_state->component_id = 1;
      global_state->h_samp_factor = 1;
      global_state->v_samp_factor = 1;
      global_state->quant_tbl_no = 0;
      global_state->dc_tbl_no = 0;
      global_state->ac_tbl_no = 0;
      break;
    case 2:
    case 3:
      jpeg_set_colorspace(cinfo, colorspace: JCS_YCbCr);
      break;
    case 4:
      jpeg_set_colorspace(cinfo, colorspace: JCS_CMYK);
      break;
    case 5:
      if ( cinfo->global_state != 100 )
      {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2 = (jpeg_component_info *)cinfo[2].global_state;
      *(_DWORD *)&cinfo[2].is_decompressor = 5;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      LOBYTE(cinfo[8].mem) = 0;
      v2->component_id = 1;
      v2->quant_tbl_no = 0;
      v2->dc_tbl_no = 0;
      v2->ac_tbl_no = 0;
      v2->h_samp_factor = 2;
      v2->v_samp_factor = 2;
      v3 = (jpeg_component_info *)cinfo[2].global_state;
      v3[1].component_id = 2;
      v3[1].h_samp_factor = 1;
      v3[1].v_samp_factor = 1;
      v3[1].quant_tbl_no = 1;
      v3[1].dc_tbl_no = 1;
      v3[1].ac_tbl_no = 1;
      v4 = (jpeg_component_info *)cinfo[2].global_state;
      v4[2].component_id = 3;
      v4[2].h_samp_factor = 1;
      v4[2].v_samp_factor = 1;
      v4[2].quant_tbl_no = 1;
      v4[2].dc_tbl_no = 1;
      v4[2].ac_tbl_no = 1;
      v5 = (jpeg_component_info *)cinfo[2].global_state;
      v5[3].h_samp_factor = 2;
      v5[3].v_samp_factor = 2;
      v5[3].component_id = 4;
      v5[3].quant_tbl_no = 0;
      v5[3].dc_tbl_no = 0;
      v5[3].ac_tbl_no = 0;
      break;
    default:
      cinfo->err->msg_code = 9;
      cinfo->err->error_exit(a1: cinfo);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E860
// Name: _jpeg_set_defaults
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_defaults(jpeg_common_struct *cinfo)
{
  unsigned __int8 *p_is_decompressor; // eax
  int i; // ecx
  bool v3; // cc

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[2].global_state == 0 )
    cinfo[2].global_state = cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 840);
  cinfo[2].progress = (jpeg_progress_mgr *)8;
  jpeg_add_quant_table(cinfo, which_tbl: 0, basic_table: &basic_table, scale_factor: 50, force_baseline: 1u);
  jpeg_add_quant_table(cinfo, which_tbl: 1u, basic_table: &dword_457400, scale_factor: 50, force_baseline: 1u);
  std_huff_tables(cinfo);
  p_is_decompressor = &cinfo[5].is_decompressor;
  for ( i = 16; i != 0; --i )
  {
    *(p_is_decompressor - 16) = 0;
    *p_is_decompressor = 1;
    p_is_decompressor[16] = 5;
    ++p_is_decompressor;
  }
  v3 = (int)cinfo[2].progress <= 8;
  cinfo[7].mem = nullptr;
  cinfo[7].err = nullptr;
  LOWORD(cinfo[7].progress) = 0;
  BYTE2(cinfo[7].progress) = 0;
  if ( !v3 )
    BYTE2(cinfo[7].progress) = 1;
  HIBYTE(cinfo[7].progress) = 0;
  cinfo[7].client_data = nullptr;
  *(_DWORD *)&cinfo[7].is_decompressor = 0;
  cinfo[7].global_state = 0;
  cinfo[8].err = nullptr;
  *(_WORD *)((char *)&cinfo[8].mem + 1) = 257;
  HIBYTE(cinfo[8].mem) = 0;
  cinfo[8].progress = (jpeg_progress_mgr *)65537;
  jpeg_default_colorspace(cinfo);
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041AE40
// Name: _jpeg_add_quant_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_add_quant_table(
        jpeg_common_struct *cinfo,
        unsigned int which_tbl,
        const unsigned int *basic_table,
        int scale_factor,
        unsigned __int8 force_baseline)
{
  int v5; // esi
  const unsigned int *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( which_tbl >= 4 )
  {
    cinfo->err->msg_code = 31;
    cinfo->err->msg_parm.i[0] = which_tbl;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *((_DWORD *)&cinfo[3].err + which_tbl) == 0 )
    *((_DWORD *)&cinfo[3].err + which_tbl) = jpeg_alloc_quant_table(cinfo);
  v5 = 0;
  v6 = basic_table + 2;
  do
  {
    v7 = (signed int)(scale_factor * *(v6 - 2) + 50) / 100;
    if ( v7 > 0 )
    {
      if ( v7 > 0x7FFF )
        v7 = 0x7FFF;
    }
    else
    {
      v7 = 1;
    }
    if ( force_baseline != 0 && v7 > 255 )
      LOWORD(v7) = 255;
    *(_WORD *)(v5 + *((_DWORD *)&cinfo[3].err + which_tbl)) = v7;
    v8 = (signed int)(scale_factor * *(v6 - 1) + 50) / 100;
    if ( v8 > 0 )
    {
      if ( v8 > 0x7FFF )
        v8 = 0x7FFF;
    }
    else
    {
      v8 = 1;
    }
    if ( force_baseline != 0 && v8 > 255 )
      LOWORD(v8) = 255;
    *(_WORD *)(*((_DWORD *)&cinfo[3].err + which_tbl) + v5 + 2) = v8;
    v9 = (signed int)(scale_factor * *v6 + 50) / 100;
    if ( v9 > 0 )
    {
      if ( v9 > 0x7FFF )
        v9 = 0x7FFF;
    }
    else
    {
      v9 = 1;
    }
    if ( force_baseline != 0 && v9 > 255 )
      LOWORD(v9) = 255;
    *(_WORD *)(*((_DWORD *)&cinfo[3].err + which_tbl) + v5 + 4) = v9;
    v10 = (signed int)(scale_factor * v6[1] + 50) / 100;
    if ( v10 > 0 )
    {
      if ( v10 > 0x7FFF )
        v10 = 0x7FFF;
    }
    else
    {
      v10 = 1;
    }
    if ( force_baseline != 0 && v10 > 255 )
      LOWORD(v10) = 255;
    *(_WORD *)(v5 + *((_DWORD *)&cinfo[3].err + which_tbl) + 6) = v10;
    v5 += 8;
    v6 += 4;
  }
  while ( v5 < 128 );
  *(_BYTE *)(*((_DWORD *)&cinfo[3].err + which_tbl) + 128) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041B020
// Name: _jpeg_set_quality
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_quality(jpeg_common_struct *cinfo, int quality, unsigned __int8 force_baseline)
{
  int v3; // ecx
  int v4; // esi

  v3 = quality;
  if ( quality > 0 )
  {
    if ( quality <= 100 )
    {
      if ( quality < 50 )
      {
        v4 = 5000 / quality;
        goto LABEL_6;
      }
    }
    else
    {
      v3 = 100;
    }
    v4 = 2 * (100 - v3);
  }
  else
  {
    v4 = 5000;
  }
LABEL_6:
  jpeg_add_quant_table(cinfo, which_tbl: 0, basic_table: &basic_table, scale_factor: v4, force_baseline);
  jpeg_add_quant_table(cinfo, which_tbl: 1u, basic_table: &dword_43DD30, scale_factor: v4, force_baseline);
}

//------------------------------------------------------------------------------
// Address: 0x0041B090
// Name: add_huff_table
// Source: json
//------------------------------------------------------------------------------
void __usercall add_huff_table(
        const unsigned __int8 *bits@<eax>,
        jpeg_common_struct *cinfo,
        JHUFF_TBL **htblptr,
        unsigned __int8 *val)
{
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // edx
  int v9; // ecx
  const unsigned __int8 *v10; // eax
  signed int v11; // edi
  int i; // [esp+8h] [ebp-4h]

  if ( *htblptr == nullptr )
    *htblptr = jpeg_alloc_huff_table(cinfo);
  v5 = (int)*htblptr;
  *(_QWORD *)v5 = *(_QWORD *)bits;
  *(_QWORD *)(v5 + 8) = *((_QWORD *)bits + 1);
  *(_BYTE *)(v5 + 16) = bits[16];
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = bits + 2;
  for ( i = 4; i != 0; --i )
  {
    v6 += *(v10 - 1);
    v9 += *v10;
    v8 += v10[1];
    v7 += v10[2];
    v10 += 4;
  }
  v11 = v9 + v8 + v7 + v6;
  if ( v11 < 1 || v11 > 256 )
  {
    cinfo->err->msg_code = 8;
    cinfo->err->error_exit(a1: cinfo);
  }
  memcpy(dst: (*htblptr)->huffval, src: val, count: v11);
  (*htblptr)->sent_table = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041B150
// Name: std_huff_tables
// Source: json
//------------------------------------------------------------------------------
void __usercall std_huff_tables(jpeg_common_struct *cinfo@<esi>)
{
  add_huff_table(
    bits: bits_dc_luminance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[3].is_decompressor,
    val: (unsigned __int8 *)val_dc_luminance);
  add_huff_table(
    bits: bits_ac_luminance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[4].progress,
    val: (unsigned __int8 *)val_ac_luminance);
  add_huff_table(
    bits: bits_dc_chrominance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[3].global_state,
    val: (unsigned __int8 *)val_dc_chrominance);
  add_huff_table(
    bits: bits_ac_chrominance,
    cinfo,
    htblptr: (JHUFF_TBL **)&cinfo[4].client_data,
    val: (unsigned __int8 *)val_ac_chrominance);
}

//------------------------------------------------------------------------------
// Address: 0x0041B1B0
// Name: _jpeg_set_colorspace
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_colorspace(jpeg_common_struct *cinfo, J_COLOR_SPACE colorspace)
{
  jpeg_component_info *global_state; // esi
  jpeg_component_info *v3; // eax
  jpeg_component_info *v4; // eax
  jpeg_component_info *v5; // esi
  jpeg_component_info *v6; // eax
  jpeg_component_info *v7; // eax
  jpeg_component_info *v8; // esi
  jpeg_component_info *v9; // eax
  jpeg_component_info *v10; // eax
  jpeg_component_info *v11; // eax
  jpeg_component_info *v12; // esi
  jpeg_component_info *v13; // eax
  jpeg_component_info *v14; // eax
  jpeg_component_info *v15; // eax
  int client_data; // eax
  int v17; // ecx
  int v18; // edx
  jpeg_component_info *v19; // eax

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  *(_DWORD *)&cinfo[2].is_decompressor = colorspace;
  LOBYTE(cinfo[8].mem) = 0;
  LOBYTE(cinfo[8].client_data) = 0;
  switch ( colorspace )
  {
    case JCS_UNKNOWN:
      client_data = (int)cinfo[1].client_data;
      cinfo[2].client_data = (void *)client_data;
      if ( client_data < 1 || client_data > 10 )
      {
        cinfo->err->msg_code = 26;
        cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
        cinfo->err->msg_parm.i[1] = 10;
        cinfo->err->error_exit(a1: cinfo);
      }
      v17 = 0;
      if ( (int)cinfo[2].client_data > 0 )
      {
        v18 = 0;
        do
        {
          v19 = (jpeg_component_info *)(v18 + cinfo[2].global_state);
          v19->component_id = v17++;
          v19->h_samp_factor = 1;
          v19->v_samp_factor = 1;
          v19->quant_tbl_no = 0;
          v19->dc_tbl_no = 0;
          v19->ac_tbl_no = 0;
          v18 += 84;
        }
        while ( v17 < (int)cinfo[2].client_data );
      }
      break;
    case JCS_GRAYSCALE:
      LOBYTE(cinfo[8].mem) = 1;
      cinfo[2].client_data = (void *)1;
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      global_state->component_id = 1;
      global_state->h_samp_factor = 1;
      global_state->v_samp_factor = 1;
      global_state->quant_tbl_no = 0;
      global_state->dc_tbl_no = 0;
      global_state->ac_tbl_no = 0;
      break;
    case JCS_RGB:
      v3 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)3;
      LOBYTE(cinfo[8].client_data) = 1;
      v3->h_samp_factor = 1;
      v3->v_samp_factor = 1;
      v3->component_id = 82;
      v3->quant_tbl_no = 0;
      v3->dc_tbl_no = 0;
      v3->ac_tbl_no = 0;
      v4 = (jpeg_component_info *)cinfo[2].global_state;
      v4[1].h_samp_factor = 1;
      v4[1].v_samp_factor = 1;
      v4[1].component_id = 71;
      v4[1].quant_tbl_no = 0;
      v4[1].dc_tbl_no = 0;
      v4[1].ac_tbl_no = 0;
      v5 = (jpeg_component_info *)cinfo[2].global_state;
      v5[2].h_samp_factor = 1;
      v5[2].v_samp_factor = 1;
      v5[2].component_id = 66;
      v5[2].quant_tbl_no = 0;
      v5[2].dc_tbl_no = 0;
      v5[2].ac_tbl_no = 0;
      break;
    case JCS_YCbCr:
      v6 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)3;
      LOBYTE(cinfo[8].mem) = 1;
      v6->component_id = 1;
      v6->h_samp_factor = 2;
      v6->v_samp_factor = 2;
      v6->quant_tbl_no = 0;
      v6->dc_tbl_no = 0;
      v6->ac_tbl_no = 0;
      v7 = (jpeg_component_info *)cinfo[2].global_state;
      v7[1].h_samp_factor = 1;
      v7[1].v_samp_factor = 1;
      v7[1].quant_tbl_no = 1;
      v7[1].dc_tbl_no = 1;
      v7[1].ac_tbl_no = 1;
      v7[1].component_id = 2;
      v8 = (jpeg_component_info *)cinfo[2].global_state;
      v8[2].h_samp_factor = 1;
      v8[2].v_samp_factor = 1;
      v8[2].quant_tbl_no = 1;
      v8[2].dc_tbl_no = 1;
      v8[2].ac_tbl_no = 1;
      v8[2].component_id = 3;
      break;
    case JCS_CMYK:
      v9 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      v9->component_id = 67;
      v9->h_samp_factor = 1;
      v9->v_samp_factor = 1;
      v9->quant_tbl_no = 0;
      v9->dc_tbl_no = 0;
      v9->ac_tbl_no = 0;
      v10 = (jpeg_component_info *)cinfo[2].global_state;
      v10[1].component_id = 77;
      v10[1].h_samp_factor = 1;
      v10[1].v_samp_factor = 1;
      v10[1].quant_tbl_no = 0;
      v10[1].dc_tbl_no = 0;
      v10[1].ac_tbl_no = 0;
      v11 = (jpeg_component_info *)cinfo[2].global_state;
      v11[2].component_id = 89;
      v11[2].h_samp_factor = 1;
      v11[2].v_samp_factor = 1;
      v11[2].quant_tbl_no = 0;
      v11[2].dc_tbl_no = 0;
      v11[2].ac_tbl_no = 0;
      v12 = (jpeg_component_info *)cinfo[2].global_state;
      v12[3].component_id = 75;
      v12[3].h_samp_factor = 1;
      v12[3].v_samp_factor = 1;
      goto LABEL_8;
    case JCS_YCCK:
      v13 = (jpeg_component_info *)cinfo[2].global_state;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      v13->component_id = 1;
      v13->h_samp_factor = 2;
      v13->v_samp_factor = 2;
      v13->quant_tbl_no = 0;
      v13->dc_tbl_no = 0;
      v13->ac_tbl_no = 0;
      v14 = (jpeg_component_info *)cinfo[2].global_state;
      v14[1].component_id = 2;
      v14[1].h_samp_factor = 1;
      v14[1].v_samp_factor = 1;
      v14[1].quant_tbl_no = 1;
      v14[1].dc_tbl_no = 1;
      v14[1].ac_tbl_no = 1;
      v15 = (jpeg_component_info *)cinfo[2].global_state;
      v15[2].component_id = 3;
      v15[2].h_samp_factor = 1;
      v15[2].v_samp_factor = 1;
      v15[2].quant_tbl_no = 1;
      v15[2].dc_tbl_no = 1;
      v15[2].ac_tbl_no = 1;
      v12 = (jpeg_component_info *)cinfo[2].global_state;
      v12[3].component_id = 4;
      v12[3].h_samp_factor = 2;
      v12[3].v_samp_factor = 2;
LABEL_8:
      v12[3].quant_tbl_no = 0;
      v12[3].dc_tbl_no = 0;
      v12[3].ac_tbl_no = 0;
      break;
    default:
      cinfo->err->msg_code = 10;
      cinfo->err->error_exit(a1: cinfo);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B4D0
// Name: _jpeg_default_colorspace
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_default_colorspace(jpeg_common_struct *cinfo)
{
  jpeg_component_info *global_state; // esi
  jpeg_component_info *v2; // eax
  jpeg_component_info *v3; // eax
  jpeg_component_info *v4; // eax
  jpeg_component_info *v5; // esi

  switch ( *(_DWORD *)&cinfo[1].is_decompressor )
  {
    case 0:
      jpeg_set_colorspace(cinfo, colorspace: JCS_UNKNOWN);
      break;
    case 1:
      if ( cinfo->global_state != 100 )
      {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        cinfo->err->error_exit(a1: cinfo);
      }
      *(_DWORD *)&cinfo[2].is_decompressor = 1;
      LOBYTE(cinfo[8].mem) = 1;
      cinfo[2].client_data = (void *)1;
      LOBYTE(cinfo[8].client_data) = 0;
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      global_state->component_id = 1;
      global_state->h_samp_factor = 1;
      global_state->v_samp_factor = 1;
      global_state->quant_tbl_no = 0;
      global_state->dc_tbl_no = 0;
      global_state->ac_tbl_no = 0;
      break;
    case 2:
    case 3:
      jpeg_set_colorspace(cinfo, colorspace: JCS_YCbCr);
      break;
    case 4:
      jpeg_set_colorspace(cinfo, colorspace: JCS_CMYK);
      break;
    case 5:
      if ( cinfo->global_state != 100 )
      {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm.i[0] = cinfo->global_state;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2 = (jpeg_component_info *)cinfo[2].global_state;
      *(_DWORD *)&cinfo[2].is_decompressor = 5;
      cinfo[2].client_data = (void *)4;
      LOBYTE(cinfo[8].client_data) = 1;
      LOBYTE(cinfo[8].mem) = 0;
      v2->component_id = 1;
      v2->quant_tbl_no = 0;
      v2->dc_tbl_no = 0;
      v2->ac_tbl_no = 0;
      v2->h_samp_factor = 2;
      v2->v_samp_factor = 2;
      v3 = (jpeg_component_info *)cinfo[2].global_state;
      v3[1].component_id = 2;
      v3[1].h_samp_factor = 1;
      v3[1].v_samp_factor = 1;
      v3[1].quant_tbl_no = 1;
      v3[1].dc_tbl_no = 1;
      v3[1].ac_tbl_no = 1;
      v4 = (jpeg_component_info *)cinfo[2].global_state;
      v4[2].component_id = 3;
      v4[2].h_samp_factor = 1;
      v4[2].v_samp_factor = 1;
      v4[2].quant_tbl_no = 1;
      v4[2].dc_tbl_no = 1;
      v4[2].ac_tbl_no = 1;
      v5 = (jpeg_component_info *)cinfo[2].global_state;
      v5[3].h_samp_factor = 2;
      v5[3].v_samp_factor = 2;
      v5[3].component_id = 4;
      v5[3].quant_tbl_no = 0;
      v5[3].dc_tbl_no = 0;
      v5[3].ac_tbl_no = 0;
      break;
    default:
      cinfo->err->msg_code = 9;
      cinfo->err->error_exit(a1: cinfo);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B660
// Name: _jpeg_set_defaults
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_set_defaults(jpeg_common_struct *cinfo)
{
  unsigned __int8 *p_is_decompressor; // eax
  int i; // ecx
  bool v3; // cc

  if ( cinfo->global_state != 100 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[2].global_state == 0 )
    cinfo[2].global_state = cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 840);
  cinfo[2].progress = (jpeg_progress_mgr *)8;
  jpeg_add_quant_table(cinfo, which_tbl: 0, basic_table: &basic_table, scale_factor: 50, force_baseline: 1u);
  jpeg_add_quant_table(cinfo, which_tbl: 1u, basic_table: &dword_43DD30, scale_factor: 50, force_baseline: 1u);
  std_huff_tables(cinfo);
  p_is_decompressor = &cinfo[5].is_decompressor;
  for ( i = 16; i != 0; --i )
  {
    *(p_is_decompressor - 16) = 0;
    *p_is_decompressor = 1;
    p_is_decompressor[16] = 5;
    ++p_is_decompressor;
  }
  v3 = (int)cinfo[2].progress <= 8;
  cinfo[7].mem = nullptr;
  cinfo[7].err = nullptr;
  LOWORD(cinfo[7].progress) = 0;
  BYTE2(cinfo[7].progress) = 0;
  if ( !v3 )
    BYTE2(cinfo[7].progress) = 1;
  HIBYTE(cinfo[7].progress) = 0;
  cinfo[7].client_data = nullptr;
  *(_DWORD *)&cinfo[7].is_decompressor = 0;
  cinfo[7].global_state = 0;
  cinfo[8].err = nullptr;
  *(_WORD *)((char *)&cinfo[8].mem + 1) = 257;
  HIBYTE(cinfo[8].mem) = 0;
  cinfo[8].progress = (jpeg_progress_mgr *)65537;
  jpeg_default_colorspace(cinfo);
}

} // namespace vxconsole_ps3
