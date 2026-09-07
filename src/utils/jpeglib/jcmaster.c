// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcmaster.c
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10257DF0
// Name: initial_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall initial_setup(jpeg_common_struct *cinfo@<esi>)
{
  int v1; // ebx
  int *v2; // edi
  int v3; // eax
  int err; // eax
  int mem; // eax
  int v6; // ebx
  int *v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ecx

  if ( cinfo[1].progress == nullptr
    || cinfo[1].mem == nullptr
    || (int)cinfo[2].client_data <= 0
    || (int)cinfo[1].client_data <= 0 )
  {
    cinfo->err->msg_code = 32;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[1].progress > 65500 || (int)cinfo[1].mem > 65500 )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 65500;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[2].progress != (jpeg_progress_mgr *)8 )
  {
    cinfo->err->msg_code = 15;
    cinfo->err->msg_parm.i[0] = (int)cinfo[2].progress;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[2].client_data > 10 )
  {
    cinfo->err->msg_code = 26;
    cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
    cinfo->err->msg_parm.i[1] = 10;
    cinfo->err->error_exit(a1: cinfo);
  }
  v1 = 0;
  cinfo[9].err = (jpeg_error_mgr *)1;
  cinfo[9].mem = (jpeg_memory_mgr *)1;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v2 = (int *)(cinfo[2].global_state + 12);
    do
    {
      v3 = *(v2 - 1);
      if ( v3 <= 0 || v3 > 4 || *v2 <= 0 || *v2 > 4 )
      {
        cinfo->err->msg_code = 18;
        cinfo->err->error_exit(a1: cinfo);
      }
      err = (int)cinfo[9].err;
      if ( err <= *(v2 - 1) )
        err = *(v2 - 1);
      cinfo[9].err = (jpeg_error_mgr *)err;
      mem = (int)cinfo[9].mem;
      if ( mem <= *v2 )
        mem = *v2;
      ++v1;
      cinfo[9].mem = (jpeg_memory_mgr *)mem;
      v2 += 21;
    }
    while ( v1 < (int)cinfo[2].client_data );
  }
  v6 = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v7 = (int *)(cinfo[2].global_state + 36);
    do
    {
      v8 = *(v7 - 7);
      *(v7 - 8) = v6;
      *v7 = 8;
      v9 = jdiv_round_up(a: (int)cinfo[1].mem * v8, b: 8 * (int)cinfo[9].err);
      v10 = *(v7 - 6);
      *(v7 - 2) = v9;
      v11 = jdiv_round_up(a: (int)cinfo[1].progress * v10, b: 8 * (int)cinfo[9].mem);
      v12 = *(v7 - 7);
      *(v7 - 1) = v11;
      v7[1] = jdiv_round_up(a: (int)cinfo[1].mem * v12, b: (int)cinfo[9].err);
      v7[2] = jdiv_round_up(a: (int)cinfo[1].progress * *(v7 - 6), b: (int)cinfo[9].mem);
      *((_BYTE *)v7 + 12) = 1;
      ++v6;
      v7 += 21;
    }
    while ( v6 < (int)cinfo[2].client_data );
  }
  cinfo[9].progress = (jpeg_progress_mgr *)jdiv_round_up(a: (int)cinfo[1].progress, b: 8 * (int)cinfo[9].mem);
}

//------------------------------------------------------------------------------
// Address: 0x10257FD0
// Name: validate_script
// Source: json
//------------------------------------------------------------------------------
void __usercall validate_script(jpeg_common_struct *cinfo@<esi>)
{
  const jpeg_scan_info *mem; // ebx
  bool v2; // zf
  bool v3; // cc
  int comps_in_scan; // eax
  int i; // edi
  int v6; // ebx
  int v7; // edx
  int v8; // edx
  signed int Ss; // edi
  int v10; // eax
  unsigned int Ah; // ecx
  unsigned int Al; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int *v17; // ebx
  int *v18; // ebx
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  int *component_index; // ebx
  unsigned __int8 *v25; // edi
  int v26; // eax
  int v27; // edi
  int *v28; // ebx
  int last_bitpos[10][64]; // [esp+0h] [ebp-A2Ch] BYREF
  unsigned __int8 component_sent[12]; // [esp+A00h] [ebp-2Ch] BYREF
  int v31; // [esp+A0Ch] [ebp-20h]
  int v32; // [esp+A10h] [ebp-1Ch]
  int v33; // [esp+A14h] [ebp-18h]
  int Se; // [esp+A18h] [ebp-14h]
  int v35; // [esp+A1Ch] [ebp-10h]
  const jpeg_scan_info *scanptr; // [esp+A20h] [ebp-Ch]
  int ncomps; // [esp+A24h] [ebp-8h]
  int scanno; // [esp+A28h] [ebp-4h]

  if ( (int)cinfo[7].err <= 0 )
  {
    cinfo->err->msg_code = 19;
    cinfo->err->msg_parm.i[0] = 0;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem = (const jpeg_scan_info *)cinfo[7].mem;
  v2 = mem->Ss == 0;
  scanptr = mem;
  if ( v2 && mem->Se == 63 )
  {
    v3 = (int)cinfo[2].client_data <= 0;
    LOBYTE(cinfo[8].global_state) = 0;
    if ( !v3 )
      memset(dst: component_sent, value: 0, count: (unsigned int)cinfo[2].client_data);
  }
  else
  {
    v3 = (int)cinfo[2].client_data <= 0;
    LOBYTE(cinfo[8].global_state) = 1;
    if ( !v3 )
      memset(last_bitpos, 0xFFu, (int)cinfo[2].client_data << 8);
  }
  for ( scanno = 1; scanno <= (int)cinfo[7].err; ++scanno )
  {
    comps_in_scan = mem->comps_in_scan;
    ncomps = comps_in_scan;
    if ( comps_in_scan <= 0 || comps_in_scan > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = comps_in_scan;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    for ( i = 0; i < ncomps; ++i )
    {
      v6 = mem->component_index[i];
      if ( v6 < 0 || v6 >= (int)cinfo[2].client_data )
      {
        v7 = scanno;
        cinfo->err->msg_code = 19;
        cinfo->err->msg_parm.i[0] = v7;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( i > 0 && v6 <= *(&scanptr->comps_in_scan + i) )
      {
        v8 = scanno;
        cinfo->err->msg_code = 19;
        cinfo->err->msg_parm.i[0] = v8;
        cinfo->err->error_exit(a1: cinfo);
      }
      mem = scanptr;
    }
    v2 = LOBYTE(cinfo[8].global_state) == 0;
    Ss = mem->Ss;
    v10 = mem->Se;
    Ah = mem->Ah;
    Al = mem->Al;
    v33 = Ss;
    Se = v10;
    v32 = Ah;
    v31 = Al;
    if ( v2 )
    {
      if ( Ss != 0 || v10 != 63 || Ah != 0 || Al != 0 )
      {
        v23 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v23;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( ncomps <= 0 )
        goto LABEL_60;
      component_index = mem->component_index;
      v35 = ncomps;
      do
      {
        v25 = &component_sent[*component_index];
        if ( *v25 != 0 )
        {
          v26 = scanno;
          cinfo->err->msg_code = 19;
          cinfo->err->msg_parm.i[0] = v26;
          cinfo->err->error_exit(a1: cinfo);
        }
        ++component_index;
        v2 = v35-- == 1;
        *v25 = 1;
      }
      while ( !v2 );
    }
    else
    {
      if ( (unsigned int)Ss > 0x3F || v10 < Ss || v10 >= 64 || Ah > 0xA || Al > 0xA )
      {
        v13 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v13;
        cinfo->err->error_exit(a1: cinfo);
        v10 = Se;
      }
      if ( Ss != 0 )
      {
        if ( ncomps != 1 )
        {
          v15 = scanno;
          cinfo->err->msg_code = 17;
          cinfo->err->msg_parm.i[0] = v15;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      else if ( v10 != 0 )
      {
        v14 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v14;
        cinfo->err->error_exit(a1: cinfo);
      }
      v16 = ncomps;
      if ( ncomps <= 0 )
        goto LABEL_60;
      v17 = mem->component_index;
      ncomps = (int)v17;
      v35 = v16;
      while ( 1 )
      {
        v18 = last_bitpos[*v17];
        if ( Ss != 0 && *v18 < 0 )
        {
          v19 = scanno;
          cinfo->err->msg_code = 17;
          cinfo->err->msg_parm.i[0] = v19;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v33 <= Se )
        {
          do
          {
            v20 = v18[Ss];
            if ( v20 >= 0 )
            {
              if ( v32 != v20 || v31 != v32 - 1 )
              {
                v22 = scanno;
                cinfo->err->msg_code = 17;
                cinfo->err->msg_parm.i[0] = v22;
                cinfo->err->error_exit(a1: cinfo);
              }
            }
            else if ( v32 != 0 )
            {
              v21 = scanno;
              cinfo->err->msg_code = 17;
              cinfo->err->msg_parm.i[0] = v21;
              cinfo->err->error_exit(a1: cinfo);
            }
            v18[Ss++] = v31;
          }
          while ( Ss <= Se );
        }
        v17 = (int *)(ncomps + 4);
        v2 = v35-- == 1;
        ncomps += 4;
        if ( v2 )
          break;
        Ss = v33;
      }
    }
    mem = scanptr;
LABEL_60:
    scanptr = ++mem;
  }
  v27 = 0;
  if ( LOBYTE(cinfo[8].global_state) != 0 )
  {
    if ( (int)cinfo[2].client_data > 0 )
    {
      v28 = last_bitpos[0];
      do
      {
        if ( *v28 < 0 )
        {
          cinfo->err->msg_code = 45;
          cinfo->err->error_exit(a1: cinfo);
        }
        ++v27;
        v28 += 64;
      }
      while ( v27 < (int)cinfo[2].client_data );
    }
  }
  else if ( (int)cinfo[2].client_data > 0 )
  {
    do
    {
      if ( component_sent[v27] == 0 )
      {
        cinfo->err->msg_code = 45;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++v27;
    }
    while ( v27 < (int)cinfo[2].client_data );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258360
// Name: select_scan_parameters
// Source: json
//------------------------------------------------------------------------------
void __usercall select_scan_parameters(jpeg_common_struct *cinfo@<esi>)
{
  const jpeg_scan_info *mem; // ecx
  int *p_comps_in_scan; // eax
  int v3; // ecx
  jpeg_component_info **p_is_decompressor; // edi
  _DWORD *v5; // edx
  int client_data; // eax
  int v7; // edx
  int v8; // ecx
  jpeg_component_info **v9; // eax

  mem = (const jpeg_scan_info *)cinfo[7].mem;
  if ( mem != nullptr )
  {
    p_comps_in_scan = &mem[(int)cinfo[13].mem->access_virt_sarray].comps_in_scan;
    cinfo[9].client_data = (void *)*p_comps_in_scan;
    v3 = 0;
    if ( *p_comps_in_scan > 0 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      v5 = p_comps_in_scan + 1;
      do
      {
        ++v3;
        *p_is_decompressor++ = (jpeg_component_info *)(cinfo[2].global_state + 84 * *v5++);
      }
      while ( v3 < *p_comps_in_scan );
    }
    cinfo[12].client_data = (void *)p_comps_in_scan[5];
    *(_DWORD *)&cinfo[12].is_decompressor = p_comps_in_scan[6];
    cinfo[12].global_state = p_comps_in_scan[7];
    cinfo[13].err = (jpeg_error_mgr *)p_comps_in_scan[8];
  }
  else
  {
    if ( (int)cinfo[2].client_data > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    client_data = (int)cinfo[2].client_data;
    v7 = 0;
    cinfo[9].client_data = (void *)client_data;
    if ( client_data > 0 )
    {
      v8 = 0;
      v9 = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        *v9 = (jpeg_component_info *)(v8 + cinfo[2].global_state);
        ++v7;
        ++v9;
        v8 += 84;
      }
      while ( v7 < (int)cinfo[2].client_data );
    }
    cinfo[12].client_data = nullptr;
    cinfo[12].global_state = 0;
    cinfo[13].err = nullptr;
    *(_DWORD *)&cinfo[12].is_decompressor = 63;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258450
// Name: per_scan_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall per_scan_setup(jpeg_common_struct *cinfo@<esi>)
{
  int client_data; // eax
  jpeg_component_info *v2; // ecx
  unsigned int v_samp_factor; // edi
  int v4; // edx
  unsigned int v5; // eax
  int v6; // edx
  jpeg_component_info *v7; // ecx
  unsigned int h_samp_factor; // edi
  int v9; // edx
  int v10; // ebx
  unsigned int height_in_blocks; // eax
  int v12; // ebx
  unsigned int v13; // edi
  int v14; // edx
  int v15; // edi
  int err; // ecx
  signed int v17; // eax
  jpeg_component_info **p_is_decompressor; // [esp+8h] [ebp-8h]
  int ci; // [esp+Ch] [ebp-4h]

  client_data = (int)cinfo[9].client_data;
  if ( client_data == 1 )
  {
    v2 = *(jpeg_component_info **)&cinfo[9].is_decompressor;
    cinfo[10].progress = (jpeg_progress_mgr *)v2->width_in_blocks;
    cinfo[10].client_data = (void *)v2->height_in_blocks;
    v_samp_factor = v2->v_samp_factor;
    v4 = v2->height_in_blocks % v_samp_factor;
    v2->MCU_width = 1;
    v2->MCU_height = 1;
    v2->MCU_blocks = 1;
    v2->MCU_sample_width = 8;
    v2->last_col_width = 1;
    if ( v4 == 0 )
      v4 = v_samp_factor;
    v2->last_row_height = v4;
    *(_DWORD *)&cinfo[10].is_decompressor = 1;
    cinfo[10].global_state = 0;
  }
  else
  {
    if ( client_data <= 0 || client_data > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[9].client_data;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v5 = jdiv_round_up(a: (int)cinfo[1].mem, b: 8 * (int)cinfo[9].err);
    v6 = 8 * (int)cinfo[9].mem;
    cinfo[10].progress = (jpeg_progress_mgr *)v5;
    cinfo[10].client_data = (void *)jdiv_round_up(a: (int)cinfo[1].progress, b: v6);
    *(_DWORD *)&cinfo[10].is_decompressor = 0;
    ci = 0;
    if ( (int)cinfo[9].client_data > 0 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        v7 = *p_is_decompressor;
        h_samp_factor = (*p_is_decompressor)->h_samp_factor;
        v7->MCU_sample_width = 8 * h_samp_factor;
        v9 = v7->width_in_blocks % h_samp_factor;
        v10 = v7->v_samp_factor;
        height_in_blocks = v7->height_in_blocks;
        v7->MCU_height = v10;
        v12 = h_samp_factor * v10;
        v7->MCU_width = h_samp_factor;
        v7->MCU_blocks = v12;
        if ( v9 == 0 )
          v9 = h_samp_factor;
        v13 = v7->v_samp_factor;
        v7->last_col_width = v9;
        v14 = height_in_blocks % v13;
        if ( height_in_blocks % v13 == 0 )
          v14 = v13;
        v7->last_row_height = v14;
        v15 = v12;
        if ( v12 + *(_DWORD *)&cinfo[10].is_decompressor > 10 )
        {
          cinfo->err->msg_code = 13;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v12 > 0 )
        {
          do
          {
            --v15;
            *(&cinfo[10].global_state + (*(_DWORD *)&cinfo[10].is_decompressor)++) = ci;
          }
          while ( v15 > 0 );
        }
        ++p_is_decompressor;
        ++ci;
      }
      while ( ci < (int)cinfo[9].client_data );
    }
  }
  err = (int)cinfo[8].err;
  if ( err > 0 )
  {
    v17 = err * (int)cinfo[10].progress;
    if ( v17 >= 0xFFFF )
      v17 = 0xFFFF;
    cinfo[7].global_state = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258610
// Name: prepare_for_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl prepare_for_pass(jpeg_common_struct *cinfo)
{
  jpeg_comp_master *mem; // edi
  void (__cdecl *v2)(jpeg_compress_struct *); // eax
  char *v3; // eax
  int pass_startup; // eax

  mem = (jpeg_comp_master *)cinfo[13].mem;
  v2 = mem[1].prepare_for_pass;
  if ( v2 != nullptr )
  {
    v3 = (char *)v2 - 1;
    if ( v3 != nullptr )
    {
      if ( v3 != (char *)1 )
      {
        cinfo->err->msg_code = 48;
        cinfo->err->error_exit(a1: cinfo);
        goto LABEL_18;
      }
    }
    else
    {
      select_scan_parameters(cinfo);
      per_scan_setup(cinfo);
      if ( cinfo[12].client_data != nullptr || cinfo[12].global_state == 0 || BYTE1(cinfo[7].progress) != 0 )
      {
        (*(void (__cdecl **)(jpeg_common_struct *, int))cinfo[14].client_data)(a1: cinfo, a2: 1);
        (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(a1: cinfo, a2: 2);
        mem->call_pass_startup = 0;
        goto LABEL_18;
      }
      ++mem[1].pass_startup;
      mem[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
    }
    if ( BYTE2(cinfo[7].progress) == 0 )
    {
      select_scan_parameters(cinfo);
      per_scan_setup(cinfo);
    }
    (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[14].client_data)(a1: cinfo, a2: 0);
    (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(a1: cinfo, a2: 2);
    if ( *(_DWORD *)&mem[1].call_pass_startup == 0 )
      (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 4))(a1: cinfo);
    (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 8))(a1: cinfo);
    mem->call_pass_startup = 0;
  }
  else
  {
    select_scan_parameters(cinfo);
    per_scan_setup(cinfo);
    if ( LOBYTE(cinfo[7].progress) == 0 )
    {
      cinfo[14].err->error_exit(a1: cinfo);
      ((void (__cdecl *)(jpeg_common_struct *))cinfo[14].mem->alloc_small)(a1: cinfo);
      (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[13].client_data)(a1: cinfo, a2: 0);
    }
    cinfo[14].progress->progress_monitor(a1: cinfo);
    (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[14].client_data)(a1: cinfo, a2: BYTE2(cinfo[7].progress));
    (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(
      a1: cinfo,
      a2: (int)mem[1].finish_pass <= 1 ? 0 : 3);
    ((void (__cdecl *)(jpeg_common_struct *, _DWORD))cinfo[13].progress->progress_monitor)(a1: cinfo, a2: 0);
    mem->call_pass_startup = BYTE2(cinfo[7].progress) == 0;
  }
LABEL_18:
  pass_startup = (int)mem[1].pass_startup;
  mem->is_last_pass = (void (__cdecl *)(jpeg_compress_struct *))pass_startup == (void (__cdecl *)(jpeg_compress_struct *))((char *)mem[1].finish_pass - 1);
  if ( cinfo->progress != nullptr )
  {
    cinfo->progress->completed_passes = pass_startup;
    cinfo->progress->total_passes = (int)mem[1].finish_pass;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102587B0
// Name: pass_startup
// Source: json
//------------------------------------------------------------------------------
void __cdecl pass_startup(jpeg_compress_struct *cinfo)
{
  cinfo->master->call_pass_startup = 0;
  cinfo->marker->write_frame_header(a1: cinfo);
  cinfo->marker->write_scan_header(a1: cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x102587E0
// Name: finish_pass_master
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_master(jpeg_compress_struct *cinfo)
{
  jpeg_comp_master *master; // esi
  void (__cdecl *prepare_for_pass)(jpeg_compress_struct *); // eax
  char *v3; // eax

  master = cinfo->master;
  cinfo->entropy->finish_pass(a1: cinfo);
  prepare_for_pass = master[1].prepare_for_pass;
  if ( prepare_for_pass != nullptr )
  {
    v3 = (char *)prepare_for_pass - 1;
    if ( v3 == nullptr )
    {
      ++master[1].pass_startup;
      master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
      return;
    }
    if ( v3 == (char *)1 )
    {
      if ( cinfo->optimize_coding != 0 )
      {
        ++*(_DWORD *)&master[1].call_pass_startup;
        ++master[1].pass_startup;
        master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))1;
        return;
      }
      goto LABEL_8;
    }
  }
  else
  {
    master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
    if ( cinfo->optimize_coding == 0 )
LABEL_8:
      ++*(_DWORD *)&master[1].call_pass_startup;
  }
  ++master[1].pass_startup;
}

//------------------------------------------------------------------------------
// Address: 0x10258850
// Name: _jinit_c_master_control
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_master_control(jpeg_common_struct *cinfo, unsigned __int8 transcode_only)
{
  int v2; // edi

  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32);
  cinfo[13].mem = (jpeg_memory_mgr *)v2;
  *(_DWORD *)v2 = prepare_for_pass;
  *(_DWORD *)(v2 + 4) = pass_startup;
  *(_DWORD *)(v2 + 8) = finish_pass_master;
  *(_BYTE *)(v2 + 13) = 0;
  initial_setup(cinfo);
  if ( cinfo[7].mem != nullptr )
  {
    validate_script(cinfo);
  }
  else
  {
    LOBYTE(cinfo[8].global_state) = 0;
    cinfo[7].err = (jpeg_error_mgr *)1;
  }
  if ( LOBYTE(cinfo[8].global_state) != 0 )
    BYTE2(cinfo[7].progress) = 1;
  if ( transcode_only != 0 )
    *(_DWORD *)(v2 + 16) = (BYTE2(cinfo[7].progress) == 0) + 1;
  else
    *(_DWORD *)(v2 + 16) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 20) = 0;
  if ( BYTE2(cinfo[7].progress) != 0 )
    *(_DWORD *)(v2 + 24) = 2 * (int)cinfo[7].err;
  else
    *(_DWORD *)(v2 + 24) = cinfo[7].err;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10257E20
// Name: initial_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall initial_setup(jpeg_common_struct *cinfo@<esi>)
{
  int v1; // ebx
  int *v2; // edi
  int v3; // eax
  int err; // eax
  int mem; // eax
  int v6; // ebx
  int *v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ecx

  if ( cinfo[1].progress == nullptr
    || cinfo[1].mem == nullptr
    || (int)cinfo[2].client_data <= 0
    || (int)cinfo[1].client_data <= 0 )
  {
    cinfo->err->msg_code = 32;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[1].progress > 65500 || (int)cinfo[1].mem > 65500 )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 65500;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[2].progress != (jpeg_progress_mgr *)8 )
  {
    cinfo->err->msg_code = 15;
    cinfo->err->msg_parm.i[0] = (int)cinfo[2].progress;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[2].client_data > 10 )
  {
    cinfo->err->msg_code = 26;
    cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
    cinfo->err->msg_parm.i[1] = 10;
    cinfo->err->error_exit(a1: cinfo);
  }
  v1 = 0;
  cinfo[9].err = (jpeg_error_mgr *)1;
  cinfo[9].mem = (jpeg_memory_mgr *)1;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v2 = (int *)(cinfo[2].global_state + 12);
    do
    {
      v3 = *(v2 - 1);
      if ( v3 <= 0 || v3 > 4 || *v2 <= 0 || *v2 > 4 )
      {
        cinfo->err->msg_code = 18;
        cinfo->err->error_exit(a1: cinfo);
      }
      err = (int)cinfo[9].err;
      if ( err <= *(v2 - 1) )
        err = *(v2 - 1);
      cinfo[9].err = (jpeg_error_mgr *)err;
      mem = (int)cinfo[9].mem;
      if ( mem <= *v2 )
        mem = *v2;
      ++v1;
      cinfo[9].mem = (jpeg_memory_mgr *)mem;
      v2 += 21;
    }
    while ( v1 < (int)cinfo[2].client_data );
  }
  v6 = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v7 = (int *)(cinfo[2].global_state + 36);
    do
    {
      v8 = *(v7 - 7);
      *(v7 - 8) = v6;
      *v7 = 8;
      v9 = jdiv_round_up(a: (int)cinfo[1].mem * v8, b: 8 * (int)cinfo[9].err);
      v10 = *(v7 - 6);
      *(v7 - 2) = v9;
      v11 = jdiv_round_up(a: (int)cinfo[1].progress * v10, b: 8 * (int)cinfo[9].mem);
      v12 = *(v7 - 7);
      *(v7 - 1) = v11;
      v7[1] = jdiv_round_up(a: (int)cinfo[1].mem * v12, b: (int)cinfo[9].err);
      v7[2] = jdiv_round_up(a: (int)cinfo[1].progress * *(v7 - 6), b: (int)cinfo[9].mem);
      *((_BYTE *)v7 + 12) = 1;
      ++v6;
      v7 += 21;
    }
    while ( v6 < (int)cinfo[2].client_data );
  }
  cinfo[9].progress = (jpeg_progress_mgr *)jdiv_round_up(a: (int)cinfo[1].progress, b: 8 * (int)cinfo[9].mem);
}

//------------------------------------------------------------------------------
// Address: 0x10258000
// Name: validate_script
// Source: json
//------------------------------------------------------------------------------
void __usercall validate_script(jpeg_common_struct *cinfo@<esi>)
{
  const jpeg_scan_info *mem; // ebx
  bool v2; // zf
  bool v3; // cc
  int comps_in_scan; // eax
  int i; // edi
  int v6; // ebx
  int v7; // edx
  int v8; // edx
  signed int Ss; // edi
  int v10; // eax
  unsigned int Ah; // ecx
  unsigned int Al; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int *v17; // ebx
  int *v18; // ebx
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  int *component_index; // ebx
  unsigned __int8 *v25; // edi
  int v26; // eax
  int v27; // edi
  int *v28; // ebx
  int last_bitpos[10][64]; // [esp+0h] [ebp-A2Ch] BYREF
  unsigned __int8 component_sent[12]; // [esp+A00h] [ebp-2Ch] BYREF
  int v31; // [esp+A0Ch] [ebp-20h]
  int v32; // [esp+A10h] [ebp-1Ch]
  int v33; // [esp+A14h] [ebp-18h]
  int Se; // [esp+A18h] [ebp-14h]
  int v35; // [esp+A1Ch] [ebp-10h]
  const jpeg_scan_info *scanptr; // [esp+A20h] [ebp-Ch]
  int ncomps; // [esp+A24h] [ebp-8h]
  int scanno; // [esp+A28h] [ebp-4h]

  if ( (int)cinfo[7].err <= 0 )
  {
    cinfo->err->msg_code = 19;
    cinfo->err->msg_parm.i[0] = 0;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem = (const jpeg_scan_info *)cinfo[7].mem;
  v2 = mem->Ss == 0;
  scanptr = mem;
  if ( v2 && mem->Se == 63 )
  {
    v3 = (int)cinfo[2].client_data <= 0;
    LOBYTE(cinfo[8].global_state) = 0;
    if ( !v3 )
      memset(dst: component_sent, value: 0, count: (unsigned int)cinfo[2].client_data);
  }
  else
  {
    v3 = (int)cinfo[2].client_data <= 0;
    LOBYTE(cinfo[8].global_state) = 1;
    if ( !v3 )
      memset(last_bitpos, 0xFFu, (int)cinfo[2].client_data << 8);
  }
  for ( scanno = 1; scanno <= (int)cinfo[7].err; ++scanno )
  {
    comps_in_scan = mem->comps_in_scan;
    ncomps = comps_in_scan;
    if ( comps_in_scan <= 0 || comps_in_scan > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = comps_in_scan;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    for ( i = 0; i < ncomps; ++i )
    {
      v6 = mem->component_index[i];
      if ( v6 < 0 || v6 >= (int)cinfo[2].client_data )
      {
        v7 = scanno;
        cinfo->err->msg_code = 19;
        cinfo->err->msg_parm.i[0] = v7;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( i > 0 && v6 <= *(&scanptr->comps_in_scan + i) )
      {
        v8 = scanno;
        cinfo->err->msg_code = 19;
        cinfo->err->msg_parm.i[0] = v8;
        cinfo->err->error_exit(a1: cinfo);
      }
      mem = scanptr;
    }
    v2 = LOBYTE(cinfo[8].global_state) == 0;
    Ss = mem->Ss;
    v10 = mem->Se;
    Ah = mem->Ah;
    Al = mem->Al;
    v33 = Ss;
    Se = v10;
    v32 = Ah;
    v31 = Al;
    if ( v2 )
    {
      if ( Ss != 0 || v10 != 63 || Ah != 0 || Al != 0 )
      {
        v23 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v23;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( ncomps <= 0 )
        goto LABEL_60;
      component_index = mem->component_index;
      v35 = ncomps;
      do
      {
        v25 = &component_sent[*component_index];
        if ( *v25 != 0 )
        {
          v26 = scanno;
          cinfo->err->msg_code = 19;
          cinfo->err->msg_parm.i[0] = v26;
          cinfo->err->error_exit(a1: cinfo);
        }
        ++component_index;
        v2 = v35-- == 1;
        *v25 = 1;
      }
      while ( !v2 );
    }
    else
    {
      if ( (unsigned int)Ss > 0x3F || v10 < Ss || v10 >= 64 || Ah > 0xA || Al > 0xA )
      {
        v13 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v13;
        cinfo->err->error_exit(a1: cinfo);
        v10 = Se;
      }
      if ( Ss != 0 )
      {
        if ( ncomps != 1 )
        {
          v15 = scanno;
          cinfo->err->msg_code = 17;
          cinfo->err->msg_parm.i[0] = v15;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      else if ( v10 != 0 )
      {
        v14 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v14;
        cinfo->err->error_exit(a1: cinfo);
      }
      v16 = ncomps;
      if ( ncomps <= 0 )
        goto LABEL_60;
      v17 = mem->component_index;
      ncomps = (int)v17;
      v35 = v16;
      while ( 1 )
      {
        v18 = last_bitpos[*v17];
        if ( Ss != 0 && *v18 < 0 )
        {
          v19 = scanno;
          cinfo->err->msg_code = 17;
          cinfo->err->msg_parm.i[0] = v19;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v33 <= Se )
        {
          do
          {
            v20 = v18[Ss];
            if ( v20 >= 0 )
            {
              if ( v32 != v20 || v31 != v32 - 1 )
              {
                v22 = scanno;
                cinfo->err->msg_code = 17;
                cinfo->err->msg_parm.i[0] = v22;
                cinfo->err->error_exit(a1: cinfo);
              }
            }
            else if ( v32 != 0 )
            {
              v21 = scanno;
              cinfo->err->msg_code = 17;
              cinfo->err->msg_parm.i[0] = v21;
              cinfo->err->error_exit(a1: cinfo);
            }
            v18[Ss++] = v31;
          }
          while ( Ss <= Se );
        }
        v17 = (int *)(ncomps + 4);
        v2 = v35-- == 1;
        ncomps += 4;
        if ( v2 )
          break;
        Ss = v33;
      }
    }
    mem = scanptr;
LABEL_60:
    scanptr = ++mem;
  }
  v27 = 0;
  if ( LOBYTE(cinfo[8].global_state) != 0 )
  {
    if ( (int)cinfo[2].client_data > 0 )
    {
      v28 = last_bitpos[0];
      do
      {
        if ( *v28 < 0 )
        {
          cinfo->err->msg_code = 45;
          cinfo->err->error_exit(a1: cinfo);
        }
        ++v27;
        v28 += 64;
      }
      while ( v27 < (int)cinfo[2].client_data );
    }
  }
  else if ( (int)cinfo[2].client_data > 0 )
  {
    do
    {
      if ( component_sent[v27] == 0 )
      {
        cinfo->err->msg_code = 45;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++v27;
    }
    while ( v27 < (int)cinfo[2].client_data );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258390
// Name: select_scan_parameters
// Source: json
//------------------------------------------------------------------------------
void __usercall select_scan_parameters(jpeg_common_struct *cinfo@<esi>)
{
  const jpeg_scan_info *mem; // ecx
  int *p_comps_in_scan; // eax
  int v3; // ecx
  jpeg_component_info **p_is_decompressor; // edi
  _DWORD *v5; // edx
  int client_data; // eax
  int v7; // edx
  int v8; // ecx
  jpeg_component_info **v9; // eax

  mem = (const jpeg_scan_info *)cinfo[7].mem;
  if ( mem != nullptr )
  {
    p_comps_in_scan = &mem[(int)cinfo[13].mem->access_virt_sarray].comps_in_scan;
    cinfo[9].client_data = (void *)*p_comps_in_scan;
    v3 = 0;
    if ( *p_comps_in_scan > 0 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      v5 = p_comps_in_scan + 1;
      do
      {
        ++v3;
        *p_is_decompressor++ = (jpeg_component_info *)(cinfo[2].global_state + 84 * *v5++);
      }
      while ( v3 < *p_comps_in_scan );
    }
    cinfo[12].client_data = (void *)p_comps_in_scan[5];
    *(_DWORD *)&cinfo[12].is_decompressor = p_comps_in_scan[6];
    cinfo[12].global_state = p_comps_in_scan[7];
    cinfo[13].err = (jpeg_error_mgr *)p_comps_in_scan[8];
  }
  else
  {
    if ( (int)cinfo[2].client_data > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    client_data = (int)cinfo[2].client_data;
    v7 = 0;
    cinfo[9].client_data = (void *)client_data;
    if ( client_data > 0 )
    {
      v8 = 0;
      v9 = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        *v9 = (jpeg_component_info *)(v8 + cinfo[2].global_state);
        ++v7;
        ++v9;
        v8 += 84;
      }
      while ( v7 < (int)cinfo[2].client_data );
    }
    cinfo[12].client_data = nullptr;
    cinfo[12].global_state = 0;
    cinfo[13].err = nullptr;
    *(_DWORD *)&cinfo[12].is_decompressor = 63;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258480
// Name: per_scan_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall per_scan_setup(jpeg_common_struct *cinfo@<esi>)
{
  int client_data; // eax
  jpeg_component_info *v2; // ecx
  unsigned int v_samp_factor; // edi
  int v4; // edx
  unsigned int v5; // eax
  int v6; // edx
  jpeg_component_info *v7; // ecx
  unsigned int h_samp_factor; // edi
  int v9; // edx
  int v10; // ebx
  unsigned int height_in_blocks; // eax
  int v12; // ebx
  unsigned int v13; // edi
  int v14; // edx
  int v15; // edi
  int err; // ecx
  signed int v17; // eax
  jpeg_component_info **p_is_decompressor; // [esp+8h] [ebp-8h]
  int ci; // [esp+Ch] [ebp-4h]

  client_data = (int)cinfo[9].client_data;
  if ( client_data == 1 )
  {
    v2 = *(jpeg_component_info **)&cinfo[9].is_decompressor;
    cinfo[10].progress = (jpeg_progress_mgr *)v2->width_in_blocks;
    cinfo[10].client_data = (void *)v2->height_in_blocks;
    v_samp_factor = v2->v_samp_factor;
    v4 = v2->height_in_blocks % v_samp_factor;
    v2->MCU_width = 1;
    v2->MCU_height = 1;
    v2->MCU_blocks = 1;
    v2->MCU_sample_width = 8;
    v2->last_col_width = 1;
    if ( v4 == 0 )
      v4 = v_samp_factor;
    v2->last_row_height = v4;
    *(_DWORD *)&cinfo[10].is_decompressor = 1;
    cinfo[10].global_state = 0;
  }
  else
  {
    if ( client_data <= 0 || client_data > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[9].client_data;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v5 = jdiv_round_up(a: (int)cinfo[1].mem, b: 8 * (int)cinfo[9].err);
    v6 = 8 * (int)cinfo[9].mem;
    cinfo[10].progress = (jpeg_progress_mgr *)v5;
    cinfo[10].client_data = (void *)jdiv_round_up(a: (int)cinfo[1].progress, b: v6);
    *(_DWORD *)&cinfo[10].is_decompressor = 0;
    ci = 0;
    if ( (int)cinfo[9].client_data > 0 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        v7 = *p_is_decompressor;
        h_samp_factor = (*p_is_decompressor)->h_samp_factor;
        v7->MCU_sample_width = 8 * h_samp_factor;
        v9 = v7->width_in_blocks % h_samp_factor;
        v10 = v7->v_samp_factor;
        height_in_blocks = v7->height_in_blocks;
        v7->MCU_height = v10;
        v12 = h_samp_factor * v10;
        v7->MCU_width = h_samp_factor;
        v7->MCU_blocks = v12;
        if ( v9 == 0 )
          v9 = h_samp_factor;
        v13 = v7->v_samp_factor;
        v7->last_col_width = v9;
        v14 = height_in_blocks % v13;
        if ( height_in_blocks % v13 == 0 )
          v14 = v13;
        v7->last_row_height = v14;
        v15 = v12;
        if ( v12 + *(_DWORD *)&cinfo[10].is_decompressor > 10 )
        {
          cinfo->err->msg_code = 13;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v12 > 0 )
        {
          do
          {
            --v15;
            *(&cinfo[10].global_state + (*(_DWORD *)&cinfo[10].is_decompressor)++) = ci;
          }
          while ( v15 > 0 );
        }
        ++p_is_decompressor;
        ++ci;
      }
      while ( ci < (int)cinfo[9].client_data );
    }
  }
  err = (int)cinfo[8].err;
  if ( err > 0 )
  {
    v17 = err * (int)cinfo[10].progress;
    if ( v17 >= 0xFFFF )
      v17 = 0xFFFF;
    cinfo[7].global_state = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258640
// Name: prepare_for_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl prepare_for_pass(jpeg_common_struct *cinfo)
{
  jpeg_comp_master *mem; // edi
  void (__cdecl *v2)(jpeg_compress_struct *); // eax
  char *v3; // eax
  int pass_startup; // eax

  mem = (jpeg_comp_master *)cinfo[13].mem;
  v2 = mem[1].prepare_for_pass;
  if ( v2 != nullptr )
  {
    v3 = (char *)v2 - 1;
    if ( v3 != nullptr )
    {
      if ( v3 != (char *)1 )
      {
        cinfo->err->msg_code = 48;
        cinfo->err->error_exit(a1: cinfo);
        goto LABEL_18;
      }
    }
    else
    {
      select_scan_parameters(cinfo);
      per_scan_setup(cinfo);
      if ( cinfo[12].client_data != nullptr || cinfo[12].global_state == 0 || BYTE1(cinfo[7].progress) != 0 )
      {
        (*(void (__cdecl **)(jpeg_common_struct *, int))cinfo[14].client_data)(a1: cinfo, a2: 1);
        (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(a1: cinfo, a2: 2);
        mem->call_pass_startup = 0;
        goto LABEL_18;
      }
      ++mem[1].pass_startup;
      mem[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
    }
    if ( BYTE2(cinfo[7].progress) == 0 )
    {
      select_scan_parameters(cinfo);
      per_scan_setup(cinfo);
    }
    (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[14].client_data)(a1: cinfo, a2: 0);
    (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(a1: cinfo, a2: 2);
    if ( *(_DWORD *)&mem[1].call_pass_startup == 0 )
      (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 4))(a1: cinfo);
    (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 8))(a1: cinfo);
    mem->call_pass_startup = 0;
  }
  else
  {
    select_scan_parameters(cinfo);
    per_scan_setup(cinfo);
    if ( LOBYTE(cinfo[7].progress) == 0 )
    {
      cinfo[14].err->error_exit(a1: cinfo);
      ((void (__cdecl *)(jpeg_common_struct *))cinfo[14].mem->alloc_small)(a1: cinfo);
      (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[13].client_data)(a1: cinfo, a2: 0);
    }
    cinfo[14].progress->progress_monitor(a1: cinfo);
    (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[14].client_data)(a1: cinfo, a2: BYTE2(cinfo[7].progress));
    (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(
      a1: cinfo,
      a2: (int)mem[1].finish_pass <= 1 ? 0 : 3);
    ((void (__cdecl *)(jpeg_common_struct *, _DWORD))cinfo[13].progress->progress_monitor)(a1: cinfo, a2: 0);
    mem->call_pass_startup = BYTE2(cinfo[7].progress) == 0;
  }
LABEL_18:
  pass_startup = (int)mem[1].pass_startup;
  mem->is_last_pass = (void (__cdecl *)(jpeg_compress_struct *))pass_startup == (void (__cdecl *)(jpeg_compress_struct *))((char *)mem[1].finish_pass - 1);
  if ( cinfo->progress != nullptr )
  {
    cinfo->progress->completed_passes = pass_startup;
    cinfo->progress->total_passes = (int)mem[1].finish_pass;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258810
// Name: finish_pass_master
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_master(jpeg_compress_struct *cinfo)
{
  jpeg_comp_master *master; // esi
  void (__cdecl *prepare_for_pass)(jpeg_compress_struct *); // eax
  char *v3; // eax

  master = cinfo->master;
  cinfo->entropy->finish_pass(a1: cinfo);
  prepare_for_pass = master[1].prepare_for_pass;
  if ( prepare_for_pass != nullptr )
  {
    v3 = (char *)prepare_for_pass - 1;
    if ( v3 == nullptr )
    {
      ++master[1].pass_startup;
      master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
      return;
    }
    if ( v3 == (char *)1 )
    {
      if ( cinfo->optimize_coding != 0 )
      {
        ++*(_DWORD *)&master[1].call_pass_startup;
        ++master[1].pass_startup;
        master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))1;
        return;
      }
      goto LABEL_8;
    }
  }
  else
  {
    master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
    if ( cinfo->optimize_coding == 0 )
LABEL_8:
      ++*(_DWORD *)&master[1].call_pass_startup;
  }
  ++master[1].pass_startup;
}

//------------------------------------------------------------------------------
// Address: 0x10258880
// Name: _jinit_c_master_control
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_master_control(jpeg_common_struct *cinfo, unsigned __int8 transcode_only)
{
  int v2; // edi

  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32);
  cinfo[13].mem = (jpeg_memory_mgr *)v2;
  *(_DWORD *)v2 = prepare_for_pass;
  *(_DWORD *)(v2 + 4) = pass_startup;
  *(_DWORD *)(v2 + 8) = finish_pass_master;
  *(_BYTE *)(v2 + 13) = 0;
  initial_setup(cinfo);
  if ( cinfo[7].mem != nullptr )
  {
    validate_script(cinfo);
  }
  else
  {
    LOBYTE(cinfo[8].global_state) = 0;
    cinfo[7].err = (jpeg_error_mgr *)1;
  }
  if ( LOBYTE(cinfo[8].global_state) != 0 )
    BYTE2(cinfo[7].progress) = 1;
  if ( transcode_only != 0 )
    *(_DWORD *)(v2 + 16) = (BYTE2(cinfo[7].progress) == 0) + 1;
  else
    *(_DWORD *)(v2 + 16) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 20) = 0;
  if ( BYTE2(cinfo[7].progress) != 0 )
    *(_DWORD *)(v2 + 24) = 2 * (int)cinfo[7].err;
  else
    *(_DWORD *)(v2 + 24) = cinfo[7].err;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x0040C340
// Name: initial_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall initial_setup(jpeg_common_struct *cinfo@<esi>)
{
  int v1; // ebx
  int *v2; // edi
  int v3; // eax
  int err; // eax
  int mem; // eax
  int v6; // ebx
  int *v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ecx

  if ( cinfo[1].progress == nullptr
    || cinfo[1].mem == nullptr
    || (int)cinfo[2].client_data <= 0
    || (int)cinfo[1].client_data <= 0 )
  {
    cinfo->err->msg_code = 32;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[1].progress > 65500 || (int)cinfo[1].mem > 65500 )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 65500;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[2].progress != (jpeg_progress_mgr *)8 )
  {
    cinfo->err->msg_code = 15;
    cinfo->err->msg_parm.i[0] = (int)cinfo[2].progress;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[2].client_data > 10 )
  {
    cinfo->err->msg_code = 26;
    cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
    cinfo->err->msg_parm.i[1] = 10;
    cinfo->err->error_exit(a1: cinfo);
  }
  v1 = 0;
  cinfo[9].err = (jpeg_error_mgr *)1;
  cinfo[9].mem = (jpeg_memory_mgr *)1;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v2 = (int *)(cinfo[2].global_state + 12);
    do
    {
      v3 = *(v2 - 1);
      if ( v3 <= 0 || v3 > 4 || *v2 <= 0 || *v2 > 4 )
      {
        cinfo->err->msg_code = 18;
        cinfo->err->error_exit(a1: cinfo);
      }
      err = (int)cinfo[9].err;
      if ( err <= *(v2 - 1) )
        err = *(v2 - 1);
      cinfo[9].err = (jpeg_error_mgr *)err;
      mem = (int)cinfo[9].mem;
      if ( mem <= *v2 )
        mem = *v2;
      ++v1;
      cinfo[9].mem = (jpeg_memory_mgr *)mem;
      v2 += 21;
    }
    while ( v1 < (int)cinfo[2].client_data );
  }
  v6 = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v7 = (int *)(cinfo[2].global_state + 36);
    do
    {
      v8 = *(v7 - 7);
      *(v7 - 8) = v6;
      *v7 = 8;
      v9 = jdiv_round_up(a: (int)cinfo[1].mem * v8, b: 8 * (int)cinfo[9].err);
      v10 = *(v7 - 6);
      *(v7 - 2) = v9;
      v11 = jdiv_round_up(a: (int)cinfo[1].progress * v10, b: 8 * (int)cinfo[9].mem);
      v12 = *(v7 - 7);
      *(v7 - 1) = v11;
      v7[1] = jdiv_round_up(a: (int)cinfo[1].mem * v12, b: (int)cinfo[9].err);
      v7[2] = jdiv_round_up(a: (int)cinfo[1].progress * *(v7 - 6), b: (int)cinfo[9].mem);
      *((_BYTE *)v7 + 12) = 1;
      ++v6;
      v7 += 21;
    }
    while ( v6 < (int)cinfo[2].client_data );
  }
  cinfo[9].progress = (jpeg_progress_mgr *)jdiv_round_up(a: (int)cinfo[1].progress, b: 8 * (int)cinfo[9].mem);
}

//------------------------------------------------------------------------------
// Address: 0x0040C520
// Name: validate_script
// Source: json
//------------------------------------------------------------------------------
void __usercall validate_script(jpeg_common_struct *cinfo@<esi>)
{
  const jpeg_scan_info *mem; // ebx
  bool v2; // zf
  bool v3; // cc
  int comps_in_scan; // eax
  int i; // edi
  int v6; // ebx
  int v7; // edx
  int v8; // edx
  signed int Ss; // edi
  int v10; // eax
  unsigned int Ah; // ecx
  unsigned int Al; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int *v17; // ebx
  int *v18; // ebx
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  int *component_index; // ebx
  unsigned __int8 *v25; // edi
  int v26; // eax
  int v27; // edi
  int *v28; // ebx
  int last_bitpos[10][64]; // [esp+0h] [ebp-A2Ch] BYREF
  unsigned __int8 component_sent[12]; // [esp+A00h] [ebp-2Ch] BYREF
  int v31; // [esp+A0Ch] [ebp-20h]
  int v32; // [esp+A10h] [ebp-1Ch]
  int v33; // [esp+A14h] [ebp-18h]
  int Se; // [esp+A18h] [ebp-14h]
  int v35; // [esp+A1Ch] [ebp-10h]
  const jpeg_scan_info *scanptr; // [esp+A20h] [ebp-Ch]
  int ncomps; // [esp+A24h] [ebp-8h]
  int scanno; // [esp+A28h] [ebp-4h]

  if ( (int)cinfo[7].err <= 0 )
  {
    cinfo->err->msg_code = 19;
    cinfo->err->msg_parm.i[0] = 0;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem = (const jpeg_scan_info *)cinfo[7].mem;
  v2 = mem->Ss == 0;
  scanptr = mem;
  if ( v2 && mem->Se == 63 )
  {
    v3 = (int)cinfo[2].client_data <= 0;
    LOBYTE(cinfo[8].global_state) = 0;
    if ( !v3 )
      memset(dst: component_sent, value: 0, count: (unsigned int)cinfo[2].client_data);
  }
  else
  {
    v3 = (int)cinfo[2].client_data <= 0;
    LOBYTE(cinfo[8].global_state) = 1;
    if ( !v3 )
      memset(last_bitpos, 0xFFu, (int)cinfo[2].client_data << 8);
  }
  for ( scanno = 1; scanno <= (int)cinfo[7].err; ++scanno )
  {
    comps_in_scan = mem->comps_in_scan;
    ncomps = comps_in_scan;
    if ( comps_in_scan <= 0 || comps_in_scan > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = comps_in_scan;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    for ( i = 0; i < ncomps; ++i )
    {
      v6 = mem->component_index[i];
      if ( v6 < 0 || v6 >= (int)cinfo[2].client_data )
      {
        v7 = scanno;
        cinfo->err->msg_code = 19;
        cinfo->err->msg_parm.i[0] = v7;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( i > 0 && v6 <= *(&scanptr->comps_in_scan + i) )
      {
        v8 = scanno;
        cinfo->err->msg_code = 19;
        cinfo->err->msg_parm.i[0] = v8;
        cinfo->err->error_exit(a1: cinfo);
      }
      mem = scanptr;
    }
    v2 = LOBYTE(cinfo[8].global_state) == 0;
    Ss = mem->Ss;
    v10 = mem->Se;
    Ah = mem->Ah;
    Al = mem->Al;
    v33 = Ss;
    Se = v10;
    v32 = Ah;
    v31 = Al;
    if ( v2 )
    {
      if ( Ss != 0 || v10 != 63 || Ah != 0 || Al != 0 )
      {
        v23 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v23;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( ncomps <= 0 )
        goto LABEL_60;
      component_index = mem->component_index;
      v35 = ncomps;
      do
      {
        v25 = &component_sent[*component_index];
        if ( *v25 != 0 )
        {
          v26 = scanno;
          cinfo->err->msg_code = 19;
          cinfo->err->msg_parm.i[0] = v26;
          cinfo->err->error_exit(a1: cinfo);
        }
        ++component_index;
        v2 = v35-- == 1;
        *v25 = 1;
      }
      while ( !v2 );
    }
    else
    {
      if ( (unsigned int)Ss > 0x3F || v10 < Ss || v10 >= 64 || Ah > 0xA || Al > 0xA )
      {
        v13 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v13;
        cinfo->err->error_exit(a1: cinfo);
        v10 = Se;
      }
      if ( Ss != 0 )
      {
        if ( ncomps != 1 )
        {
          v15 = scanno;
          cinfo->err->msg_code = 17;
          cinfo->err->msg_parm.i[0] = v15;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      else if ( v10 != 0 )
      {
        v14 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v14;
        cinfo->err->error_exit(a1: cinfo);
      }
      v16 = ncomps;
      if ( ncomps <= 0 )
        goto LABEL_60;
      v17 = mem->component_index;
      ncomps = (int)v17;
      v35 = v16;
      while ( 1 )
      {
        v18 = last_bitpos[*v17];
        if ( Ss != 0 && *v18 < 0 )
        {
          v19 = scanno;
          cinfo->err->msg_code = 17;
          cinfo->err->msg_parm.i[0] = v19;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v33 <= Se )
        {
          do
          {
            v20 = v18[Ss];
            if ( v20 >= 0 )
            {
              if ( v32 != v20 || v31 != v32 - 1 )
              {
                v22 = scanno;
                cinfo->err->msg_code = 17;
                cinfo->err->msg_parm.i[0] = v22;
                cinfo->err->error_exit(a1: cinfo);
              }
            }
            else if ( v32 != 0 )
            {
              v21 = scanno;
              cinfo->err->msg_code = 17;
              cinfo->err->msg_parm.i[0] = v21;
              cinfo->err->error_exit(a1: cinfo);
            }
            v18[Ss++] = v31;
          }
          while ( Ss <= Se );
        }
        v17 = (int *)(ncomps + 4);
        v2 = v35-- == 1;
        ncomps += 4;
        if ( v2 )
          break;
        Ss = v33;
      }
    }
    mem = scanptr;
LABEL_60:
    scanptr = ++mem;
  }
  v27 = 0;
  if ( LOBYTE(cinfo[8].global_state) != 0 )
  {
    if ( (int)cinfo[2].client_data > 0 )
    {
      v28 = last_bitpos[0];
      do
      {
        if ( *v28 < 0 )
        {
          cinfo->err->msg_code = 45;
          cinfo->err->error_exit(a1: cinfo);
        }
        ++v27;
        v28 += 64;
      }
      while ( v27 < (int)cinfo[2].client_data );
    }
  }
  else if ( (int)cinfo[2].client_data > 0 )
  {
    do
    {
      if ( component_sent[v27] == 0 )
      {
        cinfo->err->msg_code = 45;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++v27;
    }
    while ( v27 < (int)cinfo[2].client_data );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C8B0
// Name: select_scan_parameters
// Source: json
//------------------------------------------------------------------------------
void __usercall select_scan_parameters(jpeg_common_struct *cinfo@<esi>)
{
  const jpeg_scan_info *mem; // ecx
  int *p_comps_in_scan; // eax
  int v3; // ecx
  jpeg_component_info **p_is_decompressor; // edi
  _DWORD *v5; // edx
  int client_data; // eax
  int v7; // edx
  int v8; // ecx
  jpeg_component_info **v9; // eax

  mem = (const jpeg_scan_info *)cinfo[7].mem;
  if ( mem != nullptr )
  {
    p_comps_in_scan = &mem[(int)cinfo[13].mem->access_virt_sarray].comps_in_scan;
    cinfo[9].client_data = (void *)*p_comps_in_scan;
    v3 = 0;
    if ( *p_comps_in_scan > 0 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      v5 = p_comps_in_scan + 1;
      do
      {
        ++v3;
        *p_is_decompressor++ = (jpeg_component_info *)(cinfo[2].global_state + 84 * *v5++);
      }
      while ( v3 < *p_comps_in_scan );
    }
    cinfo[12].client_data = (void *)p_comps_in_scan[5];
    *(_DWORD *)&cinfo[12].is_decompressor = p_comps_in_scan[6];
    cinfo[12].global_state = p_comps_in_scan[7];
    cinfo[13].err = (jpeg_error_mgr *)p_comps_in_scan[8];
  }
  else
  {
    if ( (int)cinfo[2].client_data > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    client_data = (int)cinfo[2].client_data;
    v7 = 0;
    cinfo[9].client_data = (void *)client_data;
    if ( client_data > 0 )
    {
      v8 = 0;
      v9 = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        *v9 = (jpeg_component_info *)(v8 + cinfo[2].global_state);
        ++v7;
        ++v9;
        v8 += 84;
      }
      while ( v7 < (int)cinfo[2].client_data );
    }
    cinfo[12].client_data = nullptr;
    cinfo[12].global_state = 0;
    cinfo[13].err = nullptr;
    *(_DWORD *)&cinfo[12].is_decompressor = 63;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C9A0
// Name: per_scan_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall per_scan_setup(jpeg_common_struct *cinfo@<esi>)
{
  int client_data; // eax
  jpeg_component_info *v2; // ecx
  unsigned int v_samp_factor; // edi
  int v4; // edx
  unsigned int v5; // eax
  int v6; // edx
  jpeg_component_info *v7; // ecx
  unsigned int h_samp_factor; // edi
  int v9; // edx
  int v10; // ebx
  unsigned int height_in_blocks; // eax
  int v12; // ebx
  unsigned int v13; // edi
  int v14; // edx
  int v15; // edi
  int err; // ecx
  signed int v17; // eax
  jpeg_component_info **p_is_decompressor; // [esp+8h] [ebp-8h]
  int ci; // [esp+Ch] [ebp-4h]

  client_data = (int)cinfo[9].client_data;
  if ( client_data == 1 )
  {
    v2 = *(jpeg_component_info **)&cinfo[9].is_decompressor;
    cinfo[10].progress = (jpeg_progress_mgr *)v2->width_in_blocks;
    cinfo[10].client_data = (void *)v2->height_in_blocks;
    v_samp_factor = v2->v_samp_factor;
    v4 = v2->height_in_blocks % v_samp_factor;
    v2->MCU_width = 1;
    v2->MCU_height = 1;
    v2->MCU_blocks = 1;
    v2->MCU_sample_width = 8;
    v2->last_col_width = 1;
    if ( v4 == 0 )
      v4 = v_samp_factor;
    v2->last_row_height = v4;
    *(_DWORD *)&cinfo[10].is_decompressor = 1;
    cinfo[10].global_state = 0;
  }
  else
  {
    if ( client_data <= 0 || client_data > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[9].client_data;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v5 = jdiv_round_up(a: (int)cinfo[1].mem, b: 8 * (int)cinfo[9].err);
    v6 = 8 * (int)cinfo[9].mem;
    cinfo[10].progress = (jpeg_progress_mgr *)v5;
    cinfo[10].client_data = (void *)jdiv_round_up(a: (int)cinfo[1].progress, b: v6);
    *(_DWORD *)&cinfo[10].is_decompressor = 0;
    ci = 0;
    if ( (int)cinfo[9].client_data > 0 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        v7 = *p_is_decompressor;
        h_samp_factor = (*p_is_decompressor)->h_samp_factor;
        v7->MCU_sample_width = 8 * h_samp_factor;
        v9 = v7->width_in_blocks % h_samp_factor;
        v10 = v7->v_samp_factor;
        height_in_blocks = v7->height_in_blocks;
        v7->MCU_height = v10;
        v12 = h_samp_factor * v10;
        v7->MCU_width = h_samp_factor;
        v7->MCU_blocks = v12;
        if ( v9 == 0 )
          v9 = h_samp_factor;
        v13 = v7->v_samp_factor;
        v7->last_col_width = v9;
        v14 = height_in_blocks % v13;
        if ( height_in_blocks % v13 == 0 )
          v14 = v13;
        v7->last_row_height = v14;
        v15 = v12;
        if ( v12 + *(_DWORD *)&cinfo[10].is_decompressor > 10 )
        {
          cinfo->err->msg_code = 13;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v12 > 0 )
        {
          do
          {
            --v15;
            *(&cinfo[10].global_state + (*(_DWORD *)&cinfo[10].is_decompressor)++) = ci;
          }
          while ( v15 > 0 );
        }
        ++p_is_decompressor;
        ++ci;
      }
      while ( ci < (int)cinfo[9].client_data );
    }
  }
  err = (int)cinfo[8].err;
  if ( err > 0 )
  {
    v17 = err * (int)cinfo[10].progress;
    if ( v17 >= 0xFFFF )
      v17 = 0xFFFF;
    cinfo[7].global_state = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CB60
// Name: prepare_for_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl prepare_for_pass(jpeg_common_struct *cinfo)
{
  jpeg_comp_master *mem; // edi
  void (__cdecl *v2)(jpeg_compress_struct *); // eax
  char *v3; // eax
  int pass_startup; // eax

  mem = (jpeg_comp_master *)cinfo[13].mem;
  v2 = mem[1].prepare_for_pass;
  if ( v2 != nullptr )
  {
    v3 = (char *)v2 - 1;
    if ( v3 != nullptr )
    {
      if ( v3 != (char *)1 )
      {
        cinfo->err->msg_code = 48;
        cinfo->err->error_exit(a1: cinfo);
        goto LABEL_18;
      }
    }
    else
    {
      select_scan_parameters(cinfo);
      per_scan_setup(cinfo);
      if ( cinfo[12].client_data != nullptr || cinfo[12].global_state == 0 || BYTE1(cinfo[7].progress) != 0 )
      {
        (*(void (__cdecl **)(jpeg_common_struct *, int))cinfo[14].client_data)(a1: cinfo, a2: 1);
        (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(a1: cinfo, a2: 2);
        mem->call_pass_startup = 0;
        goto LABEL_18;
      }
      ++mem[1].pass_startup;
      mem[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
    }
    if ( BYTE2(cinfo[7].progress) == 0 )
    {
      select_scan_parameters(cinfo);
      per_scan_setup(cinfo);
    }
    (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[14].client_data)(a1: cinfo, a2: 0);
    (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(a1: cinfo, a2: 2);
    if ( *(_DWORD *)&mem[1].call_pass_startup == 0 )
      (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 4))(a1: cinfo);
    (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 8))(a1: cinfo);
    mem->call_pass_startup = 0;
  }
  else
  {
    select_scan_parameters(cinfo);
    per_scan_setup(cinfo);
    if ( LOBYTE(cinfo[7].progress) == 0 )
    {
      cinfo[14].err->error_exit(a1: cinfo);
      ((void (__cdecl *)(jpeg_common_struct *))cinfo[14].mem->alloc_small)(a1: cinfo);
      (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[13].client_data)(a1: cinfo, a2: 0);
    }
    cinfo[14].progress->progress_monitor(a1: cinfo);
    (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[14].client_data)(a1: cinfo, a2: BYTE2(cinfo[7].progress));
    (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(
      a1: cinfo,
      a2: (int)mem[1].finish_pass <= 1 ? 0 : 3);
    ((void (__cdecl *)(jpeg_common_struct *, _DWORD))cinfo[13].progress->progress_monitor)(a1: cinfo, a2: 0);
    mem->call_pass_startup = BYTE2(cinfo[7].progress) == 0;
  }
LABEL_18:
  pass_startup = (int)mem[1].pass_startup;
  mem->is_last_pass = (void (__cdecl *)(jpeg_compress_struct *))pass_startup == (void (__cdecl *)(jpeg_compress_struct *))((char *)mem[1].finish_pass - 1);
  if ( cinfo->progress != nullptr )
  {
    cinfo->progress->completed_passes = pass_startup;
    cinfo->progress->total_passes = (int)mem[1].finish_pass;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CD00
// Name: pass_startup
// Source: json
//------------------------------------------------------------------------------
void __cdecl pass_startup(jpeg_compress_struct *cinfo)
{
  cinfo->master->call_pass_startup = 0;
  cinfo->marker->write_frame_header(a1: cinfo);
  cinfo->marker->write_scan_header(a1: cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x0040CD30
// Name: finish_pass_master
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_master(jpeg_compress_struct *cinfo)
{
  jpeg_comp_master *master; // esi
  void (__cdecl *prepare_for_pass)(jpeg_compress_struct *); // eax
  char *v3; // eax

  master = cinfo->master;
  cinfo->entropy->finish_pass(a1: cinfo);
  prepare_for_pass = master[1].prepare_for_pass;
  if ( prepare_for_pass != nullptr )
  {
    v3 = (char *)prepare_for_pass - 1;
    if ( v3 == nullptr )
    {
      ++master[1].pass_startup;
      master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
      return;
    }
    if ( v3 == (char *)1 )
    {
      if ( cinfo->optimize_coding != 0 )
      {
        ++*(_DWORD *)&master[1].call_pass_startup;
        ++master[1].pass_startup;
        master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))1;
        return;
      }
      goto LABEL_8;
    }
  }
  else
  {
    master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
    if ( cinfo->optimize_coding == 0 )
LABEL_8:
      ++*(_DWORD *)&master[1].call_pass_startup;
  }
  ++master[1].pass_startup;
}

//------------------------------------------------------------------------------
// Address: 0x0040CDA0
// Name: _jinit_c_master_control
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_master_control(jpeg_common_struct *cinfo, unsigned __int8 transcode_only)
{
  int v2; // edi

  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32);
  cinfo[13].mem = (jpeg_memory_mgr *)v2;
  *(_DWORD *)v2 = prepare_for_pass;
  *(_DWORD *)(v2 + 4) = pass_startup;
  *(_DWORD *)(v2 + 8) = finish_pass_master;
  *(_BYTE *)(v2 + 13) = 0;
  initial_setup(cinfo);
  if ( cinfo[7].mem != nullptr )
  {
    validate_script(cinfo);
  }
  else
  {
    LOBYTE(cinfo[8].global_state) = 0;
    cinfo[7].err = (jpeg_error_mgr *)1;
  }
  if ( LOBYTE(cinfo[8].global_state) != 0 )
    BYTE2(cinfo[7].progress) = 1;
  if ( transcode_only != 0 )
    *(_DWORD *)(v2 + 16) = (BYTE2(cinfo[7].progress) == 0) + 1;
  else
    *(_DWORD *)(v2 + 16) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 20) = 0;
  if ( BYTE2(cinfo[7].progress) != 0 )
    *(_DWORD *)(v2 + 24) = 2 * (int)cinfo[7].err;
  else
    *(_DWORD *)(v2 + 24) = cinfo[7].err;
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00435650
// Name: initial_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall initial_setup(jpeg_common_struct *cinfo@<esi>)
{
  int v1; // ebx
  int *v2; // edi
  int v3; // eax
  int err; // eax
  int mem; // eax
  int v6; // ebx
  int *v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ecx

  if ( cinfo[1].progress == nullptr
    || cinfo[1].mem == nullptr
    || (int)cinfo[2].client_data <= 0
    || (int)cinfo[1].client_data <= 0 )
  {
    cinfo->err->msg_code = 32;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[1].progress > 65500 || (int)cinfo[1].mem > 65500 )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 65500;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[2].progress != (jpeg_progress_mgr *)8 )
  {
    cinfo->err->msg_code = 15;
    cinfo->err->msg_parm.i[0] = (int)cinfo[2].progress;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[2].client_data > 10 )
  {
    cinfo->err->msg_code = 26;
    cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
    cinfo->err->msg_parm.i[1] = 10;
    cinfo->err->error_exit(a1: cinfo);
  }
  v1 = 0;
  cinfo[9].err = (jpeg_error_mgr *)1;
  cinfo[9].mem = (jpeg_memory_mgr *)1;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v2 = (int *)(cinfo[2].global_state + 12);
    do
    {
      v3 = *(v2 - 1);
      if ( v3 <= 0 || v3 > 4 || *v2 <= 0 || *v2 > 4 )
      {
        cinfo->err->msg_code = 18;
        cinfo->err->error_exit(a1: cinfo);
      }
      err = (int)cinfo[9].err;
      if ( err <= *(v2 - 1) )
        err = *(v2 - 1);
      cinfo[9].err = (jpeg_error_mgr *)err;
      mem = (int)cinfo[9].mem;
      if ( mem <= *v2 )
        mem = *v2;
      ++v1;
      cinfo[9].mem = (jpeg_memory_mgr *)mem;
      v2 += 21;
    }
    while ( v1 < (int)cinfo[2].client_data );
  }
  v6 = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v7 = (int *)(cinfo[2].global_state + 36);
    do
    {
      v8 = *(v7 - 7);
      *(v7 - 8) = v6;
      *v7 = 8;
      v9 = jdiv_round_up(a: (int)cinfo[1].mem * v8, b: 8 * (int)cinfo[9].err);
      v10 = *(v7 - 6);
      *(v7 - 2) = v9;
      v11 = jdiv_round_up(a: (int)cinfo[1].progress * v10, b: 8 * (int)cinfo[9].mem);
      v12 = *(v7 - 7);
      *(v7 - 1) = v11;
      v7[1] = jdiv_round_up(a: (int)cinfo[1].mem * v12, b: (int)cinfo[9].err);
      v7[2] = jdiv_round_up(a: (int)cinfo[1].progress * *(v7 - 6), b: (int)cinfo[9].mem);
      *((_BYTE *)v7 + 12) = 1;
      ++v6;
      v7 += 21;
    }
    while ( v6 < (int)cinfo[2].client_data );
  }
  cinfo[9].progress = (jpeg_progress_mgr *)jdiv_round_up(a: (int)cinfo[1].progress, b: 8 * (int)cinfo[9].mem);
}

//------------------------------------------------------------------------------
// Address: 0x00435830
// Name: validate_script
// Source: json
//------------------------------------------------------------------------------
void __usercall validate_script(jpeg_common_struct *cinfo@<esi>)
{
  const jpeg_scan_info *mem; // ebx
  bool v2; // zf
  bool v3; // cc
  int comps_in_scan; // eax
  int i; // edi
  int v6; // ebx
  int v7; // edx
  int v8; // edx
  signed int Ss; // edi
  int v10; // eax
  unsigned int Ah; // ecx
  unsigned int Al; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int *v17; // ebx
  int *v18; // ebx
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  int *component_index; // ebx
  unsigned __int8 *v25; // edi
  int v26; // eax
  int v27; // edi
  int *v28; // ebx
  int last_bitpos[10][64]; // [esp+0h] [ebp-A2Ch] BYREF
  unsigned __int8 component_sent[12]; // [esp+A00h] [ebp-2Ch] BYREF
  int v31; // [esp+A0Ch] [ebp-20h]
  int v32; // [esp+A10h] [ebp-1Ch]
  int v33; // [esp+A14h] [ebp-18h]
  int Se; // [esp+A18h] [ebp-14h]
  int v35; // [esp+A1Ch] [ebp-10h]
  const jpeg_scan_info *scanptr; // [esp+A20h] [ebp-Ch]
  int ncomps; // [esp+A24h] [ebp-8h]
  int scanno; // [esp+A28h] [ebp-4h]

  if ( (int)cinfo[7].err <= 0 )
  {
    cinfo->err->msg_code = 19;
    cinfo->err->msg_parm.i[0] = 0;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem = (const jpeg_scan_info *)cinfo[7].mem;
  v2 = mem->Ss == 0;
  scanptr = mem;
  if ( v2 && mem->Se == 63 )
  {
    v3 = (int)cinfo[2].client_data <= 0;
    LOBYTE(cinfo[8].global_state) = 0;
    if ( !v3 )
      memset(dst: component_sent, value: 0, count: (unsigned int)cinfo[2].client_data);
  }
  else
  {
    v3 = (int)cinfo[2].client_data <= 0;
    LOBYTE(cinfo[8].global_state) = 1;
    if ( !v3 )
      memset(last_bitpos, 0xFFu, (int)cinfo[2].client_data << 8);
  }
  for ( scanno = 1; scanno <= (int)cinfo[7].err; ++scanno )
  {
    comps_in_scan = mem->comps_in_scan;
    ncomps = comps_in_scan;
    if ( comps_in_scan <= 0 || comps_in_scan > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = comps_in_scan;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    for ( i = 0; i < ncomps; ++i )
    {
      v6 = mem->component_index[i];
      if ( v6 < 0 || v6 >= (int)cinfo[2].client_data )
      {
        v7 = scanno;
        cinfo->err->msg_code = 19;
        cinfo->err->msg_parm.i[0] = v7;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( i > 0 && v6 <= *(&scanptr->comps_in_scan + i) )
      {
        v8 = scanno;
        cinfo->err->msg_code = 19;
        cinfo->err->msg_parm.i[0] = v8;
        cinfo->err->error_exit(a1: cinfo);
      }
      mem = scanptr;
    }
    v2 = LOBYTE(cinfo[8].global_state) == 0;
    Ss = mem->Ss;
    v10 = mem->Se;
    Ah = mem->Ah;
    Al = mem->Al;
    v33 = Ss;
    Se = v10;
    v32 = Ah;
    v31 = Al;
    if ( v2 )
    {
      if ( Ss != 0 || v10 != 63 || Ah != 0 || Al != 0 )
      {
        v23 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v23;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( ncomps <= 0 )
        goto LABEL_60;
      component_index = mem->component_index;
      v35 = ncomps;
      do
      {
        v25 = &component_sent[*component_index];
        if ( *v25 != 0 )
        {
          v26 = scanno;
          cinfo->err->msg_code = 19;
          cinfo->err->msg_parm.i[0] = v26;
          cinfo->err->error_exit(a1: cinfo);
        }
        ++component_index;
        v2 = v35-- == 1;
        *v25 = 1;
      }
      while ( !v2 );
    }
    else
    {
      if ( (unsigned int)Ss > 0x3F || v10 < Ss || v10 >= 64 || Ah > 0xA || Al > 0xA )
      {
        v13 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v13;
        cinfo->err->error_exit(a1: cinfo);
        v10 = Se;
      }
      if ( Ss != 0 )
      {
        if ( ncomps != 1 )
        {
          v15 = scanno;
          cinfo->err->msg_code = 17;
          cinfo->err->msg_parm.i[0] = v15;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      else if ( v10 != 0 )
      {
        v14 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v14;
        cinfo->err->error_exit(a1: cinfo);
      }
      v16 = ncomps;
      if ( ncomps <= 0 )
        goto LABEL_60;
      v17 = mem->component_index;
      ncomps = (int)v17;
      v35 = v16;
      while ( 1 )
      {
        v18 = last_bitpos[*v17];
        if ( Ss != 0 && *v18 < 0 )
        {
          v19 = scanno;
          cinfo->err->msg_code = 17;
          cinfo->err->msg_parm.i[0] = v19;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v33 <= Se )
        {
          do
          {
            v20 = v18[Ss];
            if ( v20 >= 0 )
            {
              if ( v32 != v20 || v31 != v32 - 1 )
              {
                v22 = scanno;
                cinfo->err->msg_code = 17;
                cinfo->err->msg_parm.i[0] = v22;
                cinfo->err->error_exit(a1: cinfo);
              }
            }
            else if ( v32 != 0 )
            {
              v21 = scanno;
              cinfo->err->msg_code = 17;
              cinfo->err->msg_parm.i[0] = v21;
              cinfo->err->error_exit(a1: cinfo);
            }
            v18[Ss++] = v31;
          }
          while ( Ss <= Se );
        }
        v17 = (int *)(ncomps + 4);
        v2 = v35-- == 1;
        ncomps += 4;
        if ( v2 )
          break;
        Ss = v33;
      }
    }
    mem = scanptr;
LABEL_60:
    scanptr = ++mem;
  }
  v27 = 0;
  if ( LOBYTE(cinfo[8].global_state) != 0 )
  {
    if ( (int)cinfo[2].client_data > 0 )
    {
      v28 = last_bitpos[0];
      do
      {
        if ( *v28 < 0 )
        {
          cinfo->err->msg_code = 45;
          cinfo->err->error_exit(a1: cinfo);
        }
        ++v27;
        v28 += 64;
      }
      while ( v27 < (int)cinfo[2].client_data );
    }
  }
  else if ( (int)cinfo[2].client_data > 0 )
  {
    do
    {
      if ( component_sent[v27] == 0 )
      {
        cinfo->err->msg_code = 45;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++v27;
    }
    while ( v27 < (int)cinfo[2].client_data );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435BC0
// Name: select_scan_parameters
// Source: json
//------------------------------------------------------------------------------
void __usercall select_scan_parameters(jpeg_common_struct *cinfo@<esi>)
{
  const jpeg_scan_info *mem; // ecx
  int *p_comps_in_scan; // eax
  int v3; // ecx
  jpeg_component_info **p_is_decompressor; // edi
  _DWORD *v5; // edx
  int client_data; // eax
  int v7; // edx
  int v8; // ecx
  jpeg_component_info **v9; // eax

  mem = (const jpeg_scan_info *)cinfo[7].mem;
  if ( mem != nullptr )
  {
    p_comps_in_scan = &mem[(int)cinfo[13].mem->access_virt_sarray].comps_in_scan;
    cinfo[9].client_data = (void *)*p_comps_in_scan;
    v3 = 0;
    if ( *p_comps_in_scan > 0 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      v5 = p_comps_in_scan + 1;
      do
      {
        ++v3;
        *p_is_decompressor++ = (jpeg_component_info *)(cinfo[2].global_state + 84 * *v5++);
      }
      while ( v3 < *p_comps_in_scan );
    }
    cinfo[12].client_data = (void *)p_comps_in_scan[5];
    *(_DWORD *)&cinfo[12].is_decompressor = p_comps_in_scan[6];
    cinfo[12].global_state = p_comps_in_scan[7];
    cinfo[13].err = (jpeg_error_mgr *)p_comps_in_scan[8];
  }
  else
  {
    if ( (int)cinfo[2].client_data > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    client_data = (int)cinfo[2].client_data;
    v7 = 0;
    cinfo[9].client_data = (void *)client_data;
    if ( client_data > 0 )
    {
      v8 = 0;
      v9 = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        *v9 = (jpeg_component_info *)(v8 + cinfo[2].global_state);
        ++v7;
        ++v9;
        v8 += 84;
      }
      while ( v7 < (int)cinfo[2].client_data );
    }
    cinfo[12].client_data = nullptr;
    cinfo[12].global_state = 0;
    cinfo[13].err = nullptr;
    *(_DWORD *)&cinfo[12].is_decompressor = 63;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435CB0
// Name: per_scan_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall per_scan_setup(jpeg_common_struct *cinfo@<esi>)
{
  int client_data; // eax
  jpeg_component_info *v2; // ecx
  unsigned int v_samp_factor; // edi
  int v4; // edx
  unsigned int v5; // eax
  int v6; // edx
  jpeg_component_info *v7; // ecx
  unsigned int h_samp_factor; // edi
  int v9; // edx
  int v10; // ebx
  unsigned int height_in_blocks; // eax
  int v12; // ebx
  unsigned int v13; // edi
  int v14; // edx
  int v15; // edi
  int err; // ecx
  signed int v17; // eax
  jpeg_component_info **p_is_decompressor; // [esp+8h] [ebp-8h]
  int ci; // [esp+Ch] [ebp-4h]

  client_data = (int)cinfo[9].client_data;
  if ( client_data == 1 )
  {
    v2 = *(jpeg_component_info **)&cinfo[9].is_decompressor;
    cinfo[10].progress = (jpeg_progress_mgr *)v2->width_in_blocks;
    cinfo[10].client_data = (void *)v2->height_in_blocks;
    v_samp_factor = v2->v_samp_factor;
    v4 = v2->height_in_blocks % v_samp_factor;
    v2->MCU_width = 1;
    v2->MCU_height = 1;
    v2->MCU_blocks = 1;
    v2->MCU_sample_width = 8;
    v2->last_col_width = 1;
    if ( v4 == 0 )
      v4 = v_samp_factor;
    v2->last_row_height = v4;
    *(_DWORD *)&cinfo[10].is_decompressor = 1;
    cinfo[10].global_state = 0;
  }
  else
  {
    if ( client_data <= 0 || client_data > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[9].client_data;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v5 = jdiv_round_up(a: (int)cinfo[1].mem, b: 8 * (int)cinfo[9].err);
    v6 = 8 * (int)cinfo[9].mem;
    cinfo[10].progress = (jpeg_progress_mgr *)v5;
    cinfo[10].client_data = (void *)jdiv_round_up(a: (int)cinfo[1].progress, b: v6);
    *(_DWORD *)&cinfo[10].is_decompressor = 0;
    ci = 0;
    if ( (int)cinfo[9].client_data > 0 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        v7 = *p_is_decompressor;
        h_samp_factor = (*p_is_decompressor)->h_samp_factor;
        v7->MCU_sample_width = 8 * h_samp_factor;
        v9 = v7->width_in_blocks % h_samp_factor;
        v10 = v7->v_samp_factor;
        height_in_blocks = v7->height_in_blocks;
        v7->MCU_height = v10;
        v12 = h_samp_factor * v10;
        v7->MCU_width = h_samp_factor;
        v7->MCU_blocks = v12;
        if ( v9 == 0 )
          v9 = h_samp_factor;
        v13 = v7->v_samp_factor;
        v7->last_col_width = v9;
        v14 = height_in_blocks % v13;
        if ( height_in_blocks % v13 == 0 )
          v14 = v13;
        v7->last_row_height = v14;
        v15 = v12;
        if ( v12 + *(_DWORD *)&cinfo[10].is_decompressor > 10 )
        {
          cinfo->err->msg_code = 13;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v12 > 0 )
        {
          do
          {
            --v15;
            *(&cinfo[10].global_state + (*(_DWORD *)&cinfo[10].is_decompressor)++) = ci;
          }
          while ( v15 > 0 );
        }
        ++p_is_decompressor;
        ++ci;
      }
      while ( ci < (int)cinfo[9].client_data );
    }
  }
  err = (int)cinfo[8].err;
  if ( err > 0 )
  {
    v17 = err * (int)cinfo[10].progress;
    if ( v17 >= 0xFFFF )
      v17 = 0xFFFF;
    cinfo[7].global_state = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435E70
// Name: prepare_for_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl prepare_for_pass(jpeg_common_struct *cinfo)
{
  jpeg_comp_master *mem; // edi
  void (__cdecl *v2)(jpeg_compress_struct *); // eax
  char *v3; // eax
  int pass_startup; // eax

  mem = (jpeg_comp_master *)cinfo[13].mem;
  v2 = mem[1].prepare_for_pass;
  if ( v2 != nullptr )
  {
    v3 = (char *)v2 - 1;
    if ( v3 != nullptr )
    {
      if ( v3 != (char *)1 )
      {
        cinfo->err->msg_code = 48;
        cinfo->err->error_exit(a1: cinfo);
        goto LABEL_18;
      }
    }
    else
    {
      select_scan_parameters(cinfo);
      per_scan_setup(cinfo);
      if ( cinfo[12].client_data != nullptr || cinfo[12].global_state == 0 || BYTE1(cinfo[7].progress) != 0 )
      {
        (*(void (__cdecl **)(jpeg_common_struct *, int))cinfo[14].client_data)(a1: cinfo, a2: 1);
        (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(a1: cinfo, a2: 2);
        mem->call_pass_startup = 0;
        goto LABEL_18;
      }
      ++mem[1].pass_startup;
      mem[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
    }
    if ( BYTE2(cinfo[7].progress) == 0 )
    {
      select_scan_parameters(cinfo);
      per_scan_setup(cinfo);
    }
    (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[14].client_data)(a1: cinfo, a2: 0);
    (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(a1: cinfo, a2: 2);
    if ( *(_DWORD *)&mem[1].call_pass_startup == 0 )
      (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 4))(a1: cinfo);
    (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 8))(a1: cinfo);
    mem->call_pass_startup = 0;
  }
  else
  {
    select_scan_parameters(cinfo);
    per_scan_setup(cinfo);
    if ( LOBYTE(cinfo[7].progress) == 0 )
    {
      cinfo[14].err->error_exit(a1: cinfo);
      ((void (__cdecl *)(jpeg_common_struct *))cinfo[14].mem->alloc_small)(a1: cinfo);
      (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[13].client_data)(a1: cinfo, a2: 0);
    }
    cinfo[14].progress->progress_monitor(a1: cinfo);
    (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[14].client_data)(a1: cinfo, a2: BYTE2(cinfo[7].progress));
    (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(
      a1: cinfo,
      a2: (int)mem[1].finish_pass <= 1 ? 0 : 3);
    ((void (__cdecl *)(jpeg_common_struct *, _DWORD))cinfo[13].progress->progress_monitor)(a1: cinfo, a2: 0);
    mem->call_pass_startup = BYTE2(cinfo[7].progress) == 0;
  }
LABEL_18:
  pass_startup = (int)mem[1].pass_startup;
  mem->is_last_pass = (void (__cdecl *)(jpeg_compress_struct *))pass_startup == (void (__cdecl *)(jpeg_compress_struct *))((char *)mem[1].finish_pass - 1);
  if ( cinfo->progress != nullptr )
  {
    cinfo->progress->completed_passes = pass_startup;
    cinfo->progress->total_passes = (int)mem[1].finish_pass;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436010
// Name: pass_startup
// Source: json
//------------------------------------------------------------------------------
void __cdecl pass_startup(jpeg_compress_struct *cinfo)
{
  cinfo->master->call_pass_startup = 0;
  cinfo->marker->write_frame_header(a1: cinfo);
  cinfo->marker->write_scan_header(a1: cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x00436040
// Name: finish_pass_master
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_master(jpeg_compress_struct *cinfo)
{
  jpeg_comp_master *master; // esi
  void (__cdecl *prepare_for_pass)(jpeg_compress_struct *); // eax
  char *v3; // eax

  master = cinfo->master;
  cinfo->entropy->finish_pass(a1: cinfo);
  prepare_for_pass = master[1].prepare_for_pass;
  if ( prepare_for_pass != nullptr )
  {
    v3 = (char *)prepare_for_pass - 1;
    if ( v3 == nullptr )
    {
      ++master[1].pass_startup;
      master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
      return;
    }
    if ( v3 == (char *)1 )
    {
      if ( cinfo->optimize_coding != 0 )
      {
        ++*(_DWORD *)&master[1].call_pass_startup;
        ++master[1].pass_startup;
        master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))1;
        return;
      }
      goto LABEL_8;
    }
  }
  else
  {
    master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
    if ( cinfo->optimize_coding == 0 )
LABEL_8:
      ++*(_DWORD *)&master[1].call_pass_startup;
  }
  ++master[1].pass_startup;
}

//------------------------------------------------------------------------------
// Address: 0x004360B0
// Name: _jinit_c_master_control
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_master_control(jpeg_common_struct *cinfo, unsigned __int8 transcode_only)
{
  int v2; // edi

  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32);
  cinfo[13].mem = (jpeg_memory_mgr *)v2;
  *(_DWORD *)v2 = prepare_for_pass;
  *(_DWORD *)(v2 + 4) = pass_startup;
  *(_DWORD *)(v2 + 8) = finish_pass_master;
  *(_BYTE *)(v2 + 13) = 0;
  initial_setup(cinfo);
  if ( cinfo[7].mem != nullptr )
  {
    validate_script(cinfo);
  }
  else
  {
    LOBYTE(cinfo[8].global_state) = 0;
    cinfo[7].err = (jpeg_error_mgr *)1;
  }
  if ( LOBYTE(cinfo[8].global_state) != 0 )
    BYTE2(cinfo[7].progress) = 1;
  if ( transcode_only != 0 )
    *(_DWORD *)(v2 + 16) = (BYTE2(cinfo[7].progress) == 0) + 1;
  else
    *(_DWORD *)(v2 + 16) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 20) = 0;
  if ( BYTE2(cinfo[7].progress) != 0 )
    *(_DWORD *)(v2 + 24) = 2 * (int)cinfo[7].err;
  else
    *(_DWORD *)(v2 + 24) = cinfo[7].err;
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x00422460
// Name: initial_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall initial_setup(jpeg_common_struct *cinfo@<esi>)
{
  int v1; // ebx
  int *v2; // edi
  int v3; // eax
  int err; // eax
  int mem; // eax
  int v6; // ebx
  int *v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ecx

  if ( cinfo[1].progress == nullptr
    || cinfo[1].mem == nullptr
    || (int)cinfo[2].client_data <= 0
    || (int)cinfo[1].client_data <= 0 )
  {
    cinfo->err->msg_code = 32;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[1].progress > 65500 || (int)cinfo[1].mem > 65500 )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 65500;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[2].progress != (jpeg_progress_mgr *)8 )
  {
    cinfo->err->msg_code = 15;
    cinfo->err->msg_parm.i[0] = (int)cinfo[2].progress;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[2].client_data > 10 )
  {
    cinfo->err->msg_code = 26;
    cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
    cinfo->err->msg_parm.i[1] = 10;
    cinfo->err->error_exit(a1: cinfo);
  }
  v1 = 0;
  cinfo[9].err = (jpeg_error_mgr *)1;
  cinfo[9].mem = (jpeg_memory_mgr *)1;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v2 = (int *)(cinfo[2].global_state + 12);
    do
    {
      v3 = *(v2 - 1);
      if ( v3 <= 0 || v3 > 4 || *v2 <= 0 || *v2 > 4 )
      {
        cinfo->err->msg_code = 18;
        cinfo->err->error_exit(a1: cinfo);
      }
      err = (int)cinfo[9].err;
      if ( err <= *(v2 - 1) )
        err = *(v2 - 1);
      cinfo[9].err = (jpeg_error_mgr *)err;
      mem = (int)cinfo[9].mem;
      if ( mem <= *v2 )
        mem = *v2;
      ++v1;
      cinfo[9].mem = (jpeg_memory_mgr *)mem;
      v2 += 21;
    }
    while ( v1 < (int)cinfo[2].client_data );
  }
  v6 = 0;
  if ( (int)cinfo[2].client_data > 0 )
  {
    v7 = (int *)(cinfo[2].global_state + 36);
    do
    {
      v8 = *(v7 - 7);
      *(v7 - 8) = v6;
      *v7 = 8;
      v9 = jdiv_round_up(a: (int)cinfo[1].mem * v8, b: 8 * (int)cinfo[9].err);
      v10 = *(v7 - 6);
      *(v7 - 2) = v9;
      v11 = jdiv_round_up(a: (int)cinfo[1].progress * v10, b: 8 * (int)cinfo[9].mem);
      v12 = *(v7 - 7);
      *(v7 - 1) = v11;
      v7[1] = jdiv_round_up(a: (int)cinfo[1].mem * v12, b: (int)cinfo[9].err);
      v7[2] = jdiv_round_up(a: (int)cinfo[1].progress * *(v7 - 6), b: (int)cinfo[9].mem);
      *((_BYTE *)v7 + 12) = 1;
      ++v6;
      v7 += 21;
    }
    while ( v6 < (int)cinfo[2].client_data );
  }
  cinfo[9].progress = (jpeg_progress_mgr *)jdiv_round_up(a: (int)cinfo[1].progress, b: 8 * (int)cinfo[9].mem);
}

//------------------------------------------------------------------------------
// Address: 0x00422640
// Name: validate_script
// Source: json
//------------------------------------------------------------------------------
void __usercall validate_script(jpeg_common_struct *cinfo@<esi>)
{
  const jpeg_scan_info *mem; // ebx
  bool v2; // zf
  bool v3; // cc
  int comps_in_scan; // eax
  int i; // edi
  int v6; // ebx
  int v7; // edx
  int v8; // edx
  signed int Ss; // edi
  int v10; // eax
  unsigned int Ah; // ecx
  unsigned int Al; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int *v17; // ebx
  int *v18; // ebx
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  int *component_index; // ebx
  unsigned __int8 *v25; // edi
  int v26; // eax
  int v27; // edi
  int *v28; // ebx
  int last_bitpos[10][64]; // [esp+0h] [ebp-A2Ch] BYREF
  unsigned __int8 component_sent[12]; // [esp+A00h] [ebp-2Ch] BYREF
  int v31; // [esp+A0Ch] [ebp-20h]
  int v32; // [esp+A10h] [ebp-1Ch]
  int v33; // [esp+A14h] [ebp-18h]
  int Se; // [esp+A18h] [ebp-14h]
  int v35; // [esp+A1Ch] [ebp-10h]
  const jpeg_scan_info *scanptr; // [esp+A20h] [ebp-Ch]
  int ncomps; // [esp+A24h] [ebp-8h]
  int scanno; // [esp+A28h] [ebp-4h]

  if ( (int)cinfo[7].err <= 0 )
  {
    cinfo->err->msg_code = 19;
    cinfo->err->msg_parm.i[0] = 0;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem = (const jpeg_scan_info *)cinfo[7].mem;
  v2 = mem->Ss == 0;
  scanptr = mem;
  if ( v2 && mem->Se == 63 )
  {
    v3 = (int)cinfo[2].client_data <= 0;
    LOBYTE(cinfo[8].global_state) = 0;
    if ( !v3 )
      memset(dst: component_sent, value: 0, count: (unsigned int)cinfo[2].client_data);
  }
  else
  {
    v3 = (int)cinfo[2].client_data <= 0;
    LOBYTE(cinfo[8].global_state) = 1;
    if ( !v3 )
      memset(last_bitpos, 0xFFu, (int)cinfo[2].client_data << 8);
  }
  for ( scanno = 1; scanno <= (int)cinfo[7].err; ++scanno )
  {
    comps_in_scan = mem->comps_in_scan;
    ncomps = comps_in_scan;
    if ( comps_in_scan <= 0 || comps_in_scan > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = comps_in_scan;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    for ( i = 0; i < ncomps; ++i )
    {
      v6 = mem->component_index[i];
      if ( v6 < 0 || v6 >= (int)cinfo[2].client_data )
      {
        v7 = scanno;
        cinfo->err->msg_code = 19;
        cinfo->err->msg_parm.i[0] = v7;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( i > 0 && v6 <= *(&scanptr->comps_in_scan + i) )
      {
        v8 = scanno;
        cinfo->err->msg_code = 19;
        cinfo->err->msg_parm.i[0] = v8;
        cinfo->err->error_exit(a1: cinfo);
      }
      mem = scanptr;
    }
    v2 = LOBYTE(cinfo[8].global_state) == 0;
    Ss = mem->Ss;
    v10 = mem->Se;
    Ah = mem->Ah;
    Al = mem->Al;
    v33 = Ss;
    Se = v10;
    v32 = Ah;
    v31 = Al;
    if ( v2 )
    {
      if ( Ss != 0 || v10 != 63 || Ah != 0 || Al != 0 )
      {
        v23 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v23;
        cinfo->err->error_exit(a1: cinfo);
      }
      if ( ncomps <= 0 )
        goto LABEL_60;
      component_index = mem->component_index;
      v35 = ncomps;
      do
      {
        v25 = &component_sent[*component_index];
        if ( *v25 != 0 )
        {
          v26 = scanno;
          cinfo->err->msg_code = 19;
          cinfo->err->msg_parm.i[0] = v26;
          cinfo->err->error_exit(a1: cinfo);
        }
        ++component_index;
        v2 = v35-- == 1;
        *v25 = 1;
      }
      while ( !v2 );
    }
    else
    {
      if ( (unsigned int)Ss > 0x3F || v10 < Ss || v10 >= 64 || Ah > 0xA || Al > 0xA )
      {
        v13 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v13;
        cinfo->err->error_exit(a1: cinfo);
        v10 = Se;
      }
      if ( Ss != 0 )
      {
        if ( ncomps != 1 )
        {
          v15 = scanno;
          cinfo->err->msg_code = 17;
          cinfo->err->msg_parm.i[0] = v15;
          cinfo->err->error_exit(a1: cinfo);
        }
      }
      else if ( v10 != 0 )
      {
        v14 = scanno;
        cinfo->err->msg_code = 17;
        cinfo->err->msg_parm.i[0] = v14;
        cinfo->err->error_exit(a1: cinfo);
      }
      v16 = ncomps;
      if ( ncomps <= 0 )
        goto LABEL_60;
      v17 = mem->component_index;
      ncomps = (int)v17;
      v35 = v16;
      while ( 1 )
      {
        v18 = last_bitpos[*v17];
        if ( Ss != 0 && *v18 < 0 )
        {
          v19 = scanno;
          cinfo->err->msg_code = 17;
          cinfo->err->msg_parm.i[0] = v19;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v33 <= Se )
        {
          do
          {
            v20 = v18[Ss];
            if ( v20 >= 0 )
            {
              if ( v32 != v20 || v31 != v32 - 1 )
              {
                v22 = scanno;
                cinfo->err->msg_code = 17;
                cinfo->err->msg_parm.i[0] = v22;
                cinfo->err->error_exit(a1: cinfo);
              }
            }
            else if ( v32 != 0 )
            {
              v21 = scanno;
              cinfo->err->msg_code = 17;
              cinfo->err->msg_parm.i[0] = v21;
              cinfo->err->error_exit(a1: cinfo);
            }
            v18[Ss++] = v31;
          }
          while ( Ss <= Se );
        }
        v17 = (int *)(ncomps + 4);
        v2 = v35-- == 1;
        ncomps += 4;
        if ( v2 )
          break;
        Ss = v33;
      }
    }
    mem = scanptr;
LABEL_60:
    scanptr = ++mem;
  }
  v27 = 0;
  if ( LOBYTE(cinfo[8].global_state) != 0 )
  {
    if ( (int)cinfo[2].client_data > 0 )
    {
      v28 = last_bitpos[0];
      do
      {
        if ( *v28 < 0 )
        {
          cinfo->err->msg_code = 45;
          cinfo->err->error_exit(a1: cinfo);
        }
        ++v27;
        v28 += 64;
      }
      while ( v27 < (int)cinfo[2].client_data );
    }
  }
  else if ( (int)cinfo[2].client_data > 0 )
  {
    do
    {
      if ( component_sent[v27] == 0 )
      {
        cinfo->err->msg_code = 45;
        cinfo->err->error_exit(a1: cinfo);
      }
      ++v27;
    }
    while ( v27 < (int)cinfo[2].client_data );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004229D0
// Name: select_scan_parameters
// Source: json
//------------------------------------------------------------------------------
void __usercall select_scan_parameters(jpeg_common_struct *cinfo@<esi>)
{
  const jpeg_scan_info *mem; // ecx
  int *p_comps_in_scan; // eax
  int v3; // ecx
  jpeg_component_info **p_is_decompressor; // edi
  _DWORD *v5; // edx
  int client_data; // eax
  int v7; // edx
  int v8; // ecx
  jpeg_component_info **v9; // eax

  mem = (const jpeg_scan_info *)cinfo[7].mem;
  if ( mem != nullptr )
  {
    p_comps_in_scan = &mem[(int)cinfo[13].mem->access_virt_sarray].comps_in_scan;
    cinfo[9].client_data = (void *)*p_comps_in_scan;
    v3 = 0;
    if ( *p_comps_in_scan > 0 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      v5 = p_comps_in_scan + 1;
      do
      {
        ++v3;
        *p_is_decompressor++ = (jpeg_component_info *)(cinfo[2].global_state + 84 * *v5++);
      }
      while ( v3 < *p_comps_in_scan );
    }
    cinfo[12].client_data = (void *)p_comps_in_scan[5];
    *(_DWORD *)&cinfo[12].is_decompressor = p_comps_in_scan[6];
    cinfo[12].global_state = p_comps_in_scan[7];
    cinfo[13].err = (jpeg_error_mgr *)p_comps_in_scan[8];
  }
  else
  {
    if ( (int)cinfo[2].client_data > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[2].client_data;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    client_data = (int)cinfo[2].client_data;
    v7 = 0;
    cinfo[9].client_data = (void *)client_data;
    if ( client_data > 0 )
    {
      v8 = 0;
      v9 = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        *v9 = (jpeg_component_info *)(v8 + cinfo[2].global_state);
        ++v7;
        ++v9;
        v8 += 84;
      }
      while ( v7 < (int)cinfo[2].client_data );
    }
    cinfo[12].client_data = nullptr;
    cinfo[12].global_state = 0;
    cinfo[13].err = nullptr;
    *(_DWORD *)&cinfo[12].is_decompressor = 63;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422AC0
// Name: per_scan_setup
// Source: json
//------------------------------------------------------------------------------
void __usercall per_scan_setup(jpeg_common_struct *cinfo@<esi>)
{
  int client_data; // eax
  jpeg_component_info *v2; // ecx
  unsigned int v_samp_factor; // edi
  int v4; // edx
  unsigned int v5; // eax
  int v6; // edx
  jpeg_component_info *v7; // ecx
  unsigned int h_samp_factor; // edi
  int v9; // edx
  int v10; // ebx
  unsigned int height_in_blocks; // eax
  int v12; // ebx
  unsigned int v13; // edi
  int v14; // edx
  int v15; // edi
  int err; // ecx
  signed int v17; // eax
  jpeg_component_info **p_is_decompressor; // [esp+8h] [ebp-8h]
  int ci; // [esp+Ch] [ebp-4h]

  client_data = (int)cinfo[9].client_data;
  if ( client_data == 1 )
  {
    v2 = *(jpeg_component_info **)&cinfo[9].is_decompressor;
    cinfo[10].progress = (jpeg_progress_mgr *)v2->width_in_blocks;
    cinfo[10].client_data = (void *)v2->height_in_blocks;
    v_samp_factor = v2->v_samp_factor;
    v4 = v2->height_in_blocks % v_samp_factor;
    v2->MCU_width = 1;
    v2->MCU_height = 1;
    v2->MCU_blocks = 1;
    v2->MCU_sample_width = 8;
    v2->last_col_width = 1;
    if ( v4 == 0 )
      v4 = v_samp_factor;
    v2->last_row_height = v4;
    *(_DWORD *)&cinfo[10].is_decompressor = 1;
    cinfo[10].global_state = 0;
  }
  else
  {
    if ( client_data <= 0 || client_data > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[9].client_data;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v5 = jdiv_round_up(a: (int)cinfo[1].mem, b: 8 * (int)cinfo[9].err);
    v6 = 8 * (int)cinfo[9].mem;
    cinfo[10].progress = (jpeg_progress_mgr *)v5;
    cinfo[10].client_data = (void *)jdiv_round_up(a: (int)cinfo[1].progress, b: v6);
    *(_DWORD *)&cinfo[10].is_decompressor = 0;
    ci = 0;
    if ( (int)cinfo[9].client_data > 0 )
    {
      p_is_decompressor = (jpeg_component_info **)&cinfo[9].is_decompressor;
      do
      {
        v7 = *p_is_decompressor;
        h_samp_factor = (*p_is_decompressor)->h_samp_factor;
        v7->MCU_sample_width = 8 * h_samp_factor;
        v9 = v7->width_in_blocks % h_samp_factor;
        v10 = v7->v_samp_factor;
        height_in_blocks = v7->height_in_blocks;
        v7->MCU_height = v10;
        v12 = h_samp_factor * v10;
        v7->MCU_width = h_samp_factor;
        v7->MCU_blocks = v12;
        if ( v9 == 0 )
          v9 = h_samp_factor;
        v13 = v7->v_samp_factor;
        v7->last_col_width = v9;
        v14 = height_in_blocks % v13;
        if ( height_in_blocks % v13 == 0 )
          v14 = v13;
        v7->last_row_height = v14;
        v15 = v12;
        if ( v12 + *(_DWORD *)&cinfo[10].is_decompressor > 10 )
        {
          cinfo->err->msg_code = 13;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v12 > 0 )
        {
          do
          {
            --v15;
            *(&cinfo[10].global_state + (*(_DWORD *)&cinfo[10].is_decompressor)++) = ci;
          }
          while ( v15 > 0 );
        }
        ++p_is_decompressor;
        ++ci;
      }
      while ( ci < (int)cinfo[9].client_data );
    }
  }
  err = (int)cinfo[8].err;
  if ( err > 0 )
  {
    v17 = err * (int)cinfo[10].progress;
    if ( v17 >= 0xFFFF )
      v17 = 0xFFFF;
    cinfo[7].global_state = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422C80
// Name: prepare_for_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl prepare_for_pass(jpeg_common_struct *cinfo)
{
  jpeg_comp_master *mem; // edi
  void (__cdecl *v2)(jpeg_compress_struct *); // eax
  char *v3; // eax
  int pass_startup; // eax

  mem = (jpeg_comp_master *)cinfo[13].mem;
  v2 = mem[1].prepare_for_pass;
  if ( v2 != nullptr )
  {
    v3 = (char *)v2 - 1;
    if ( v3 != nullptr )
    {
      if ( v3 != (char *)1 )
      {
        cinfo->err->msg_code = 48;
        cinfo->err->error_exit(a1: cinfo);
        goto LABEL_18;
      }
    }
    else
    {
      select_scan_parameters(cinfo);
      per_scan_setup(cinfo);
      if ( cinfo[12].client_data != nullptr || cinfo[12].global_state == 0 || BYTE1(cinfo[7].progress) != 0 )
      {
        (*(void (__cdecl **)(jpeg_common_struct *, int))cinfo[14].client_data)(a1: cinfo, a2: 1);
        (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(a1: cinfo, a2: 2);
        mem->call_pass_startup = 0;
        goto LABEL_18;
      }
      ++mem[1].pass_startup;
      mem[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
    }
    if ( BYTE2(cinfo[7].progress) == 0 )
    {
      select_scan_parameters(cinfo);
      per_scan_setup(cinfo);
    }
    (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[14].client_data)(a1: cinfo, a2: 0);
    (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(a1: cinfo, a2: 2);
    if ( *(_DWORD *)&mem[1].call_pass_startup == 0 )
      (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 4))(a1: cinfo);
    (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 8))(a1: cinfo);
    mem->call_pass_startup = 0;
  }
  else
  {
    select_scan_parameters(cinfo);
    per_scan_setup(cinfo);
    if ( LOBYTE(cinfo[7].progress) == 0 )
    {
      cinfo[14].err->error_exit(a1: cinfo);
      ((void (__cdecl *)(jpeg_common_struct *))cinfo[14].mem->alloc_small)(a1: cinfo);
      (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[13].client_data)(a1: cinfo, a2: 0);
    }
    cinfo[14].progress->progress_monitor(a1: cinfo);
    (*(void (__cdecl **)(jpeg_common_struct *, _DWORD))cinfo[14].client_data)(a1: cinfo, a2: BYTE2(cinfo[7].progress));
    (**(void (__cdecl ***)(jpeg_common_struct *, int))&cinfo[13].is_decompressor)(
      a1: cinfo,
      a2: (int)mem[1].finish_pass <= 1 ? 0 : 3);
    ((void (__cdecl *)(jpeg_common_struct *, _DWORD))cinfo[13].progress->progress_monitor)(a1: cinfo, a2: 0);
    mem->call_pass_startup = BYTE2(cinfo[7].progress) == 0;
  }
LABEL_18:
  pass_startup = (int)mem[1].pass_startup;
  mem->is_last_pass = (void (__cdecl *)(jpeg_compress_struct *))pass_startup == (void (__cdecl *)(jpeg_compress_struct *))((char *)mem[1].finish_pass - 1);
  if ( cinfo->progress != nullptr )
  {
    cinfo->progress->completed_passes = pass_startup;
    cinfo->progress->total_passes = (int)mem[1].finish_pass;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422E20
// Name: pass_startup
// Source: json
//------------------------------------------------------------------------------
void __cdecl pass_startup(jpeg_compress_struct *cinfo)
{
  cinfo->master->call_pass_startup = 0;
  cinfo->marker->write_frame_header(a1: cinfo);
  cinfo->marker->write_scan_header(a1: cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x00422E50
// Name: finish_pass_master
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass_master(jpeg_compress_struct *cinfo)
{
  jpeg_comp_master *master; // esi
  void (__cdecl *prepare_for_pass)(jpeg_compress_struct *); // eax
  char *v3; // eax

  master = cinfo->master;
  cinfo->entropy->finish_pass(a1: cinfo);
  prepare_for_pass = master[1].prepare_for_pass;
  if ( prepare_for_pass != nullptr )
  {
    v3 = (char *)prepare_for_pass - 1;
    if ( v3 == nullptr )
    {
      ++master[1].pass_startup;
      master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
      return;
    }
    if ( v3 == (char *)1 )
    {
      if ( cinfo->optimize_coding != 0 )
      {
        ++*(_DWORD *)&master[1].call_pass_startup;
        ++master[1].pass_startup;
        master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))1;
        return;
      }
      goto LABEL_8;
    }
  }
  else
  {
    master[1].prepare_for_pass = (void (__cdecl *)(jpeg_compress_struct *))2;
    if ( cinfo->optimize_coding == 0 )
LABEL_8:
      ++*(_DWORD *)&master[1].call_pass_startup;
  }
  ++master[1].pass_startup;
}

//------------------------------------------------------------------------------
// Address: 0x00422EC0
// Name: _jinit_c_master_control
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_master_control(jpeg_common_struct *cinfo, unsigned __int8 transcode_only)
{
  int v2; // edi

  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32);
  cinfo[13].mem = (jpeg_memory_mgr *)v2;
  *(_DWORD *)v2 = prepare_for_pass;
  *(_DWORD *)(v2 + 4) = pass_startup;
  *(_DWORD *)(v2 + 8) = finish_pass_master;
  *(_BYTE *)(v2 + 13) = 0;
  initial_setup(cinfo);
  if ( cinfo[7].mem != nullptr )
  {
    validate_script(cinfo);
  }
  else
  {
    LOBYTE(cinfo[8].global_state) = 0;
    cinfo[7].err = (jpeg_error_mgr *)1;
  }
  if ( LOBYTE(cinfo[8].global_state) != 0 )
    BYTE2(cinfo[7].progress) = 1;
  if ( transcode_only != 0 )
    *(_DWORD *)(v2 + 16) = (BYTE2(cinfo[7].progress) == 0) + 1;
  else
    *(_DWORD *)(v2 + 16) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 20) = 0;
  if ( BYTE2(cinfo[7].progress) != 0 )
    *(_DWORD *)(v2 + 24) = 2 * (int)cinfo[7].err;
  else
    *(_DWORD *)(v2 + 24) = cinfo[7].err;
}

} // namespace vxconsole_ps3
