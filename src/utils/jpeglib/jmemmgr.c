// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jmemmgr.c
// Functions: 14
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x102512E0
// Name: alloc_small
// Source: json
//------------------------------------------------------------------------------
int __cdecl alloc_small(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  small_pool_struct *next; // eax
  unsigned int v6; // ebx
  unsigned int v7; // esi
  unsigned int bytes_used; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  small_pool_struct *prev_hdr_ptr; // [esp+18h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 1;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
  {
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
    sizeofobject = v3;
  }
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  next = mem->small_list[pool_id];
  prev_hdr_ptr = nullptr;
  if ( next != nullptr )
  {
    while ( next->hdr.bytes_left < v3 )
    {
      prev_hdr_ptr = next;
      next = next->hdr.next;
      if ( next == nullptr )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v6 = v3 + 16;
    if ( prev_hdr_ptr != nullptr )
      v7 = extra_pool_slop[pool_id];
    else
      v7 = first_pool_slop[pool_id];
    if ( v7 > 1000000000 - v6 )
      v7 = 1000000000 - v6;
    for ( next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6);
          next == nullptr;
          next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6) )
    {
      v7 >>= 1;
      if ( v7 < 0x32 )
      {
        cinfo->err->msg_code = 54;
        cinfo->err->msg_parm.i[0] = 2;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    mem->total_space_allocated += v7 + v6;
    v3 = sizeofobject;
    next->hdr.next = nullptr;
    next->hdr.bytes_used = 0;
    next->hdr.bytes_left = sizeofobject + v7;
    if ( prev_hdr_ptr != nullptr )
      prev_hdr_ptr->hdr.next = next;
    else
      mem->small_list[pool_id] = next;
  }
  bytes_used = next->hdr.bytes_used;
  next->hdr.bytes_left -= v3;
  next->hdr.bytes_used = v3 + bytes_used;
  return (int)&next[1] + bytes_used;
}

//------------------------------------------------------------------------------
// Address: 0x10251430
// Name: alloc_large
// Source: json
//------------------------------------------------------------------------------
large_pool_struct *__cdecl alloc_large(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  large_pool_struct *small; // esi
  large_pool_struct *v6; // edx
  my_memory_mgr *mem; // [esp+14h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  small = (large_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v3 + 16);
  if ( small == nullptr )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem->total_space_allocated += v3 + 16;
  v6 = mem->large_list[pool_id];
  small->hdr.bytes_used = v3;
  small->hdr.next = v6;
  small->hdr.bytes_left = 0;
  mem->large_list[pool_id] = small;
  return small + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10251500
// Name: alloc_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl alloc_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 **samplesperrow,
        signed int numrows)
{
  unsigned int v5; // edi
  unsigned __int8 **result; // eax
  unsigned int v7; // esi
  large_pool_struct *v8; // eax
  unsigned int i; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  unsigned __int8 **v11; // [esp+20h] [ebp+10h]

  mem = (my_memory_mgr *)cinfo->mem;
  v5 = 0x3B9AC9F0 / (unsigned int)samplesperrow;
  if ( 0x3B9AC9F0 / (unsigned int)samplesperrow == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v5 >= numrows )
    v5 = numrows;
  mem->last_rowsperchunk = v5;
  result = (unsigned __int8 **)alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v7 = 0;
  v11 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v5 >= numrows - v7 )
        v5 = numrows - v7;
      v8 = alloc_large(cinfo, pool_id, sizeofobject: (_DWORD)samplesperrow * v5);
      for ( i = v5; i != 0; --i )
      {
        v11[v7++] = (unsigned __int8 *)v8;
        v8 = (large_pool_struct *)((char *)v8 + (_DWORD)samplesperrow);
      }
    }
    while ( v7 < numrows );
    return v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102515B0
// Name: alloc_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl alloc_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned int blocksperrow,
        signed int numrows))[64]
{
  unsigned int v4; // edi
  __int16 (**result)[64]; // eax
  unsigned int v6; // esi
  large_pool_struct *v7; // eax
  unsigned int i; // ecx
  __int16 (**mem)[64]; // [esp+Ch] [ebp-4h]
  __int16 (**v10)[64]; // [esp+Ch] [ebp-4h]

  mem = (__int16 (**)[64])cinfo->mem;
  v4 = 0x3B9AC9F0 / (blocksperrow << 7);
  if ( v4 == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v4 >= numrows )
    v4 = numrows;
  mem[20] = (__int16 (*)[64])v4;
  result = (__int16 (**)[64])alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v6 = 0;
  v10 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v4 >= numrows - v6 )
        v4 = numrows - v6;
      v7 = alloc_large(cinfo, pool_id, sizeofobject: (blocksperrow * v4) << 7);
      for ( i = v4; i != 0; --i )
      {
        v10[v6++] = (__int16 (*)[64])v7;
        v7 += 8 * blocksperrow;
      }
    }
    while ( v6 < numrows );
    return v10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10251660
// Name: request_virt_sarray
// Source: json
//------------------------------------------------------------------------------
jvirt_sarray_control *__cdecl request_virt_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int samplesperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_sarray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_sarray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->samplesperrow = samplesperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_sarray_control *)mem[1].request_virt_sarray;
  mem[1].request_virt_sarray = (jvirt_sarray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102516D0
// Name: request_virt_barray
// Source: json
//------------------------------------------------------------------------------
jvirt_barray_control *__cdecl request_virt_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int blocksperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_barray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_barray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->blocksperrow = blocksperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_barray_control *)mem[1].request_virt_barray;
  mem[1].request_virt_barray = (jvirt_barray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10251740
// Name: realize_virt_arrays
// Source: json
//------------------------------------------------------------------------------
void __cdecl realize_virt_arrays(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *p_pub; // edi
  jvirt_sarray_control *(__cdecl *request_virt_sarray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  jvirt_barray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  jvirt_sarray_control *(__cdecl *j)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v11; // edi
  unsigned int v12; // ecx
  jvirt_barray_control *(__cdecl *k)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v14; // edi
  unsigned int v15; // ecx
  int v16; // [esp-4h] [ebp-14h]
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]

  p_pub = cinfo->mem;
  request_virt_sarray = p_pub[1].request_virt_sarray;
  v3 = 0;
  v4 = 0;
  for ( mem = (my_memory_mgr *)p_pub;
        request_virt_sarray != nullptr;
        request_virt_sarray = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_sarray
                              + 9) )
  {
    if ( *(_DWORD *)request_virt_sarray == 0 )
    {
      v5 = *((_DWORD *)request_virt_sarray + 2);
      v3 += v5 * *((_DWORD *)request_virt_sarray + 3);
      v4 += v5 * *((_DWORD *)request_virt_sarray + 1);
    }
  }
  for ( i = p_pub[1].request_virt_barray;
        i != nullptr;
        i = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
            + 9) )
  {
    if ( *(_DWORD *)i == 0 )
    {
      v7 = *((_DWORD *)i + 2);
      v3 += (v7 * *((_DWORD *)i + 3)) << 7;
      v4 += (v7 * *((_DWORD *)i + 1)) << 7;
    }
  }
  if ( v3 > 0 )
  {
    v8 = jpeg_mem_available(cinfo, min_bytes_needed: v3, max_bytes_needed: v4);
    if ( v8 < v4 )
    {
      v9 = v8 / v3;
      if ( v8 / v3 <= 0 )
        v9 = 1;
    }
    else
    {
      v9 = 1000000000;
    }
    for ( j = p_pub[1].request_virt_sarray;
          j != nullptr;
          j = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))j
              + 9) )
    {
      if ( *(_DWORD *)j == 0 )
      {
        v11 = *((_DWORD *)j + 1);
        v12 = *((_DWORD *)j + 3);
        if ( (int)((v11 - 1) / v12 + 1) > v9 )
        {
          v16 = v11 * *((_DWORD *)j + 2);
          *((_DWORD *)j + 4) = v9 * v12;
          jpeg_open_backing_store(cinfo, info: (backing_store_struct *)((char *)j + 40), total_bytes_needed: v16);
          *((_BYTE *)j + 34) = 1;
        }
        else
        {
          *((_DWORD *)j + 4) = v11;
        }
        *(_DWORD *)j = alloc_sarray(
                         cinfo,
                         pool_id: 1u,
                         samplesperrow: *((unsigned __int8 ***)j + 2),
                         numrows: *((_DWORD *)j + 4));
        *((_DWORD *)j + 5) = mem->last_rowsperchunk;
        *((_DWORD *)j + 6) = 0;
        *((_DWORD *)j + 7) = 0;
        *((_BYTE *)j + 33) = 0;
        p_pub = &mem->pub;
      }
    }
    for ( k = p_pub[1].request_virt_barray;
          k != nullptr;
          k = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))k
              + 9) )
    {
      if ( *(_DWORD *)k == 0 )
      {
        v14 = *((_DWORD *)k + 1);
        v15 = *((_DWORD *)k + 3);
        if ( (int)((v14 - 1) / v15 + 1) > v9 )
        {
          *((_DWORD *)k + 4) = v9 * v15;
          jpeg_open_backing_store(
            cinfo,
            info: (backing_store_struct *)((char *)k + 40),
            total_bytes_needed: (v14 * *((_DWORD *)k + 2)) << 7);
          *((_BYTE *)k + 34) = 1;
        }
        else
        {
          *((_DWORD *)k + 4) = v14;
        }
        *(_DWORD *)k = alloc_barray(cinfo, pool_id: 1u, blocksperrow: *((_DWORD *)k + 2), numrows: *((_DWORD *)k + 4));
        *((_DWORD *)k + 5) = mem->last_rowsperchunk;
        *((_DWORD *)k + 6) = 0;
        *((_DWORD *)k + 7) = 0;
        *((_BYTE *)k + 33) = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102518E0
// Name: do_sarray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_sarray_io(jvirt_sarray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  unsigned int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = ptr->samplesperrow * ptr->cur_start_row;
  bytesperrow = ptr->samplesperrow;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10251980
// Name: do_barray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_barray_io(jvirt_barray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = (ptr->blocksperrow << 7) * ptr->cur_start_row;
  bytesperrow = ptr->blocksperrow << 7;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10251A20
// Name: access_virt_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl access_virt_sarray(
        jpeg_common_struct *cinfo,
        jvirt_sarray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable)
{
  unsigned int v5; // ebx
  jpeg_common_struct *v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // eax
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned int i; // ebx
  unsigned int bytesperrow; // [esp+20h] [ebp+14h]

  v5 = num_rows + start_row;
  if ( num_rows + start_row <= ptr->rows_in_array && num_rows <= ptr->maxaccess && ptr->mem_buffer != nullptr )
  {
    v6 = cinfo;
  }
  else
  {
    v6 = cinfo;
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v5 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      v6->err->msg_code = 69;
      v6->err->error_exit(a1: v6);
    }
    if ( ptr->dirty != 0 )
    {
      do_sarray_io(ptr, cinfo: v6, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v5 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_sarray_io(ptr, cinfo: v6, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= v5 )
  {
LABEL_27:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_28:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row >= start_row )
  {
    v10 = ptr->first_undef_row;
  }
  else
  {
    if ( writable != 0 )
    {
      v6->err->msg_code = 22;
      v6->err->error_exit(a1: v6);
    }
    v10 = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = v5;
  if ( ptr->pre_zero != 0 )
  {
    bytesperrow = ptr->samplesperrow;
    v11 = ptr->cur_start_row;
    v12 = v10 - v11;
    for ( i = v5 - v11; v12 < i; ++v12 )
      jzero_far(target: ptr->mem_buffer[v12], bytestozero: bytesperrow);
    goto LABEL_27;
  }
  if ( writable != 0 )
    goto LABEL_28;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x10251B70
// Name: access_virt_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl access_virt_barray(
        jpeg_common_struct *cinfo,
        jvirt_barray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable))[64]
{
  unsigned int v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // edi
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned int end_row; // [esp+20h] [ebp+14h]
  unsigned int end_rowa; // [esp+20h] [ebp+14h]

  v6 = num_rows + start_row;
  end_row = v6;
  if ( v6 > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == nullptr )
  {
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v6 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      cinfo->err->msg_code = 69;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( ptr->dirty != 0 )
    {
      do_barray_io(ptr, cinfo, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v6 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_barray_io(ptr, cinfo, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= end_row )
  {
LABEL_25:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_26:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row < start_row )
  {
    if ( writable != 0 )
    {
      cinfo->err->msg_code = 22;
      cinfo->err->error_exit(a1: cinfo);
    }
    first_undef_row = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = end_row;
  if ( ptr->pre_zero != 0 )
  {
    v10 = ptr->cur_start_row;
    v11 = first_undef_row - v10;
    v12 = ptr->blocksperrow << 7;
    for ( end_rowa = end_row - v10; v11 < end_rowa; ++v11 )
      jzero_far(target: ptr->mem_buffer[v11], bytestozero: v12);
    goto LABEL_25;
  }
  if ( writable != 0 )
    goto LABEL_26;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x10251CC0
// Name: free_pool
// Source: json
//------------------------------------------------------------------------------
void __cdecl free_pool(jpeg_common_struct *cinfo, unsigned int pool_id)
{
  jpeg_memory_mgr *mem; // esi
  unsigned int v3; // edi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  unsigned int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  unsigned int v13; // ebx

  mem = cinfo->mem;
  v3 = pool_id;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( pool_id == 1 )
  {
    for ( i = mem[1].request_virt_sarray;
          i != nullptr;
          i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
              + 9) )
    {
      if ( *((_BYTE *)i + 34) != 0 )
      {
        v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
        *((_BYTE *)i + 34) = 0;
        v5(a1: cinfo, a2: (char *)i + 40);
      }
    }
    request_virt_barray = mem[1].request_virt_barray;
    for ( mem[1].request_virt_sarray = nullptr;
          request_virt_barray != nullptr;
          request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                + 9) )
    {
      if ( *((_BYTE *)request_virt_barray + 34) != 0 )
      {
        v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
        *((_BYTE *)request_virt_barray + 34) = 0;
        v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
      }
    }
    v3 = pool_id;
    mem[1].request_virt_barray = nullptr;
  }
  v8 = *((_DWORD **)&mem[1].alloc_sarray + v3);
  *((_DWORD *)&mem[1].alloc_sarray + v3) = 0;
  if ( v8 != nullptr )
  {
    do
    {
      v9 = (_DWORD *)*v8;
      v10 = v8[2] + v8[1] + 16;
      jpeg_free_small(cinfo, object: v8, sizeofobject: v10);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v10);
      v8 = v9;
    }
    while ( v9 != nullptr );
    v3 = pool_id;
  }
  v11 = *((_DWORD **)&mem[1].alloc_small + v3);
  *((_DWORD *)&mem[1].alloc_small + v3) = 0;
  if ( v11 != nullptr )
  {
    do
    {
      v12 = (_DWORD *)*v11;
      v13 = v11[2] + v11[1] + 16;
      jpeg_free_small(cinfo, object: v11, sizeofobject: v13);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v13);
      v11 = v12;
    }
    while ( v12 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10251DD0
// Name: self_destruct
// Source: json
//------------------------------------------------------------------------------
void __cdecl self_destruct(jpeg_common_struct *cinfo)
{
  int v2; // edi
  jpeg_memory_mgr *mem; // esi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  vgui::PropertyPage *v12; // ecx
  int pool; // [esp+Ch] [ebp-4h]
  unsigned int cinfoa; // [esp+18h] [ebp+8h]
  unsigned int cinfob; // [esp+18h] [ebp+8h]

  v2 = 1;
  pool = 1;
  do
  {
    mem = cinfo->mem;
    if ( v2 >= 2 )
    {
      cinfo->err->msg_code = 14;
      cinfo->err->msg_parm.i[0] = v2;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v2 == 1 )
    {
      for ( i = mem[1].request_virt_sarray;
            i != nullptr;
            i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
                + 9) )
      {
        if ( *((_BYTE *)i + 34) != 0 )
        {
          v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
          *((_BYTE *)i + 34) = 0;
          v5(a1: cinfo, a2: (char *)i + 40);
        }
      }
      request_virt_barray = mem[1].request_virt_barray;
      for ( mem[1].request_virt_sarray = nullptr;
            request_virt_barray != nullptr;
            request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                  + 9) )
      {
        if ( *((_BYTE *)request_virt_barray + 34) != 0 )
        {
          v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
          *((_BYTE *)request_virt_barray + 34) = 0;
          v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
        }
      }
      v2 = pool;
      mem[1].request_virt_barray = nullptr;
    }
    v8 = *((_DWORD **)&mem[1].alloc_sarray + v2);
    *((_DWORD *)&mem[1].alloc_sarray + v2) = 0;
    if ( v8 != nullptr )
    {
      do
      {
        v9 = (_DWORD *)*v8;
        cinfoa = v8[2] + v8[1] + 16;
        jpeg_free_small(cinfo, object: v8, sizeofobject: cinfoa);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - cinfoa);
        v8 = v9;
      }
      while ( v9 != nullptr );
      v2 = pool;
    }
    v10 = *((_DWORD **)&mem[1].alloc_small + v2);
    *((_DWORD *)&mem[1].alloc_small + v2) = 0;
    if ( v10 != nullptr )
    {
      do
      {
        v11 = (_DWORD *)*v10;
        cinfob = v10[2] + v10[1] + 16;
        jpeg_free_small(cinfo, object: v10, sizeofobject: cinfob);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - cinfob);
        v10 = v11;
      }
      while ( v11 != nullptr );
      v2 = pool;
    }
    pool = --v2;
  }
  while ( v2 >= 0 );
  jpeg_free_small(cinfo, object: cinfo->mem, sizeofobject: 0x54u);
  cinfo->mem = nullptr;
  CColorBalanceUIPanel::Init(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10251F10
// Name: _jinit_memory_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_memory_mgr(jpeg_common_struct *cinfo)
{
  vgui::CTreeViewListControl *v1; // ecx
  jpeg_common_struct *v2; // edi
  vgui::PropertyPage *v3; // ecx
  int (__cdecl **small)(jpeg_common_struct *, unsigned int, unsigned int); // esi
  const char *v5; // eax
  int max_to_use; // [esp+Ch] [ebp-4h] BYREF

  v2 = cinfo;
  cinfo->mem = nullptr;
  max_to_use = CTraceFilter::GetTraceType(this: v1);
  small = (int (__cdecl **)(jpeg_common_struct *, unsigned int, unsigned int))jpeg_get_small(
                                                                                cinfo: v2,
                                                                                sizeofobject: 0x54u);
  if ( small == nullptr )
  {
    CColorBalanceUIPanel::Init(this: v3);
    v2->err->msg_code = 54;
    v2->err->msg_parm.i[0] = 0;
    ((void (__cdecl *)(jpeg_common_struct *, jpeg_common_struct *))v2->err->error_exit)(a1: v2, a2: v2);
  }
  *small = alloc_small;
  small[1] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_large;
  small[2] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_sarray;
  small[3] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_barray;
  small[4] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_sarray;
  small[5] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_barray;
  small[6] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))realize_virt_arrays;
  small[7] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_sarray;
  small[8] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_barray;
  small[9] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))free_pool;
  small[10] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))self_destruct;
  small[12] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))1000000000;
  small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))max_to_use;
  small[14] = nullptr;
  small[16] = nullptr;
  small[13] = nullptr;
  small[15] = nullptr;
  small[17] = nullptr;
  small[18] = nullptr;
  small[19] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))84;
  v2->mem = (jpeg_memory_mgr *)small;
  v5 = getenv(option: "JPEGMEM");
  if ( v5 != nullptr )
  {
    HIBYTE(cinfo) = 120;
    if ( sscanf(string: v5, format: "%ld%c", &max_to_use, (char *)&cinfo + 3) > 0 )
    {
      if ( HIBYTE(cinfo) == 109 || HIBYTE(cinfo) == 77 )
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000000 * max_to_use);
      else
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000 * max_to_use);
    }
  }
}

// ============================================================
// Overlay from FileSystemOpenDialog (Missing functions)
// ============================================================
namespace FileSystemOpenDialog {

//------------------------------------------------------------------------------
// Address: 0x1000B900
// Name: alloc_small
// Source: json
//------------------------------------------------------------------------------
int __cdecl alloc_small(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  small_pool_struct *next; // eax
  unsigned int v6; // ebx
  unsigned int v7; // esi
  unsigned int bytes_used; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  small_pool_struct *prev_hdr_ptr; // [esp+18h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 1;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
  {
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
    sizeofobject = v3;
  }
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  next = mem->small_list[pool_id];
  prev_hdr_ptr = nullptr;
  if ( next != nullptr )
  {
    while ( next->hdr.bytes_left < v3 )
    {
      prev_hdr_ptr = next;
      next = next->hdr.next;
      if ( next == nullptr )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v6 = v3 + 16;
    if ( prev_hdr_ptr != nullptr )
      v7 = extra_pool_slop[pool_id];
    else
      v7 = first_pool_slop[pool_id];
    if ( v7 > 1000000000 - v6 )
      v7 = 1000000000 - v6;
    for ( next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6);
          next == nullptr;
          next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6) )
    {
      v7 >>= 1;
      if ( v7 < 0x32 )
      {
        cinfo->err->msg_code = 54;
        cinfo->err->msg_parm.i[0] = 2;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    mem->total_space_allocated += v7 + v6;
    v3 = sizeofobject;
    next->hdr.next = nullptr;
    next->hdr.bytes_used = 0;
    next->hdr.bytes_left = sizeofobject + v7;
    if ( prev_hdr_ptr != nullptr )
      prev_hdr_ptr->hdr.next = next;
    else
      mem->small_list[pool_id] = next;
  }
  bytes_used = next->hdr.bytes_used;
  next->hdr.bytes_left -= v3;
  next->hdr.bytes_used = v3 + bytes_used;
  return (int)&next[1] + bytes_used;
}

//------------------------------------------------------------------------------
// Address: 0x1000BA50
// Name: alloc_large
// Source: json
//------------------------------------------------------------------------------
large_pool_struct *__cdecl alloc_large(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  large_pool_struct *small; // esi
  large_pool_struct *v6; // edx
  my_memory_mgr *mem; // [esp+14h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  small = (large_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v3 + 16);
  if ( small == nullptr )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem->total_space_allocated += v3 + 16;
  v6 = mem->large_list[pool_id];
  small->hdr.bytes_used = v3;
  small->hdr.next = v6;
  small->hdr.bytes_left = 0;
  mem->large_list[pool_id] = small;
  return small + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000BB20
// Name: alloc_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl alloc_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 **samplesperrow,
        signed int numrows)
{
  unsigned int v5; // edi
  unsigned __int8 **result; // eax
  unsigned int v7; // esi
  large_pool_struct *v8; // eax
  unsigned int i; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  unsigned __int8 **v11; // [esp+20h] [ebp+10h]

  mem = (my_memory_mgr *)cinfo->mem;
  v5 = 0x3B9AC9F0 / (unsigned int)samplesperrow;
  if ( 0x3B9AC9F0 / (unsigned int)samplesperrow == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v5 >= numrows )
    v5 = numrows;
  mem->last_rowsperchunk = v5;
  result = (unsigned __int8 **)alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v7 = 0;
  v11 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v5 >= numrows - v7 )
        v5 = numrows - v7;
      v8 = alloc_large(cinfo, pool_id, sizeofobject: (_DWORD)samplesperrow * v5);
      for ( i = v5; i != 0; --i )
      {
        v11[v7++] = (unsigned __int8 *)v8;
        v8 = (large_pool_struct *)((char *)v8 + (_DWORD)samplesperrow);
      }
    }
    while ( v7 < numrows );
    return v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BBD0
// Name: alloc_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl alloc_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned int blocksperrow,
        signed int numrows))[64]
{
  unsigned int v4; // edi
  __int16 (**result)[64]; // eax
  unsigned int v6; // esi
  large_pool_struct *v7; // eax
  unsigned int i; // ecx
  __int16 (**mem)[64]; // [esp+Ch] [ebp-4h]
  __int16 (**v10)[64]; // [esp+Ch] [ebp-4h]

  mem = (__int16 (**)[64])cinfo->mem;
  v4 = 0x3B9AC9F0 / (blocksperrow << 7);
  if ( v4 == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v4 >= numrows )
    v4 = numrows;
  mem[20] = (__int16 (*)[64])v4;
  result = (__int16 (**)[64])alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v6 = 0;
  v10 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v4 >= numrows - v6 )
        v4 = numrows - v6;
      v7 = alloc_large(cinfo, pool_id, sizeofobject: (blocksperrow * v4) << 7);
      for ( i = v4; i != 0; --i )
      {
        v10[v6++] = (__int16 (*)[64])v7;
        v7 += 8 * blocksperrow;
      }
    }
    while ( v6 < numrows );
    return v10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BC80
// Name: request_virt_sarray
// Source: json
//------------------------------------------------------------------------------
jvirt_sarray_control *__cdecl request_virt_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int samplesperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_sarray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_sarray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->samplesperrow = samplesperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_sarray_control *)mem[1].request_virt_sarray;
  mem[1].request_virt_sarray = (jvirt_sarray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BCF0
// Name: request_virt_barray
// Source: json
//------------------------------------------------------------------------------
jvirt_barray_control *__cdecl request_virt_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int blocksperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_barray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_barray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->blocksperrow = blocksperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_barray_control *)mem[1].request_virt_barray;
  mem[1].request_virt_barray = (jvirt_barray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD60
// Name: realize_virt_arrays
// Source: json
//------------------------------------------------------------------------------
void __cdecl realize_virt_arrays(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *p_pub; // edi
  jvirt_sarray_control *(__cdecl *request_virt_sarray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  jvirt_barray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  jvirt_sarray_control *(__cdecl *j)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v11; // edi
  unsigned int v12; // ecx
  jvirt_barray_control *(__cdecl *k)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v14; // edi
  unsigned int v15; // ecx
  int v16; // [esp-4h] [ebp-14h]
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]

  p_pub = cinfo->mem;
  request_virt_sarray = p_pub[1].request_virt_sarray;
  v3 = 0;
  v4 = 0;
  for ( mem = (my_memory_mgr *)p_pub;
        request_virt_sarray != nullptr;
        request_virt_sarray = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_sarray
                              + 9) )
  {
    if ( *(_DWORD *)request_virt_sarray == 0 )
    {
      v5 = *((_DWORD *)request_virt_sarray + 2);
      v3 += v5 * *((_DWORD *)request_virt_sarray + 3);
      v4 += v5 * *((_DWORD *)request_virt_sarray + 1);
    }
  }
  for ( i = p_pub[1].request_virt_barray;
        i != nullptr;
        i = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
            + 9) )
  {
    if ( *(_DWORD *)i == 0 )
    {
      v7 = *((_DWORD *)i + 2);
      v3 += (v7 * *((_DWORD *)i + 3)) << 7;
      v4 += (v7 * *((_DWORD *)i + 1)) << 7;
    }
  }
  if ( v3 > 0 )
  {
    v8 = jpeg_mem_available(
           cinfo,
           min_bytes_needed: v3,
           max_bytes_needed: v4,
           already_allocated: (int)p_pub[1].realize_virt_arrays);
    if ( v8 < v4 )
    {
      v9 = v8 / v3;
      if ( v8 / v3 <= 0 )
        v9 = 1;
    }
    else
    {
      v9 = 1000000000;
    }
    for ( j = p_pub[1].request_virt_sarray;
          j != nullptr;
          j = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))j
              + 9) )
    {
      if ( *(_DWORD *)j == 0 )
      {
        v11 = *((_DWORD *)j + 1);
        v12 = *((_DWORD *)j + 3);
        if ( (int)((v11 - 1) / v12 + 1) > v9 )
        {
          v16 = v11 * *((_DWORD *)j + 2);
          *((_DWORD *)j + 4) = v9 * v12;
          jpeg_open_backing_store(cinfo, info: (backing_store_struct *)((char *)j + 40), total_bytes_needed: v16);
          *((_BYTE *)j + 34) = 1;
        }
        else
        {
          *((_DWORD *)j + 4) = v11;
        }
        *(_DWORD *)j = alloc_sarray(
                         cinfo,
                         pool_id: 1u,
                         samplesperrow: *((unsigned __int8 ***)j + 2),
                         numrows: *((_DWORD *)j + 4));
        *((_DWORD *)j + 5) = mem->last_rowsperchunk;
        *((_DWORD *)j + 6) = 0;
        *((_DWORD *)j + 7) = 0;
        *((_BYTE *)j + 33) = 0;
        p_pub = &mem->pub;
      }
    }
    for ( k = p_pub[1].request_virt_barray;
          k != nullptr;
          k = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))k
              + 9) )
    {
      if ( *(_DWORD *)k == 0 )
      {
        v14 = *((_DWORD *)k + 1);
        v15 = *((_DWORD *)k + 3);
        if ( (int)((v14 - 1) / v15 + 1) > v9 )
        {
          *((_DWORD *)k + 4) = v9 * v15;
          jpeg_open_backing_store(
            cinfo,
            info: (backing_store_struct *)((char *)k + 40),
            total_bytes_needed: (v14 * *((_DWORD *)k + 2)) << 7);
          *((_BYTE *)k + 34) = 1;
        }
        else
        {
          *((_DWORD *)k + 4) = v14;
        }
        *(_DWORD *)k = alloc_barray(cinfo, pool_id: 1u, blocksperrow: *((_DWORD *)k + 2), numrows: *((_DWORD *)k + 4));
        *((_DWORD *)k + 5) = mem->last_rowsperchunk;
        *((_DWORD *)k + 6) = 0;
        *((_DWORD *)k + 7) = 0;
        *((_BYTE *)k + 33) = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BF00
// Name: do_sarray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_sarray_io(jvirt_sarray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  unsigned int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = ptr->samplesperrow * ptr->cur_start_row;
  bytesperrow = ptr->samplesperrow;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BFA0
// Name: do_barray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_barray_io(jvirt_barray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = (ptr->blocksperrow << 7) * ptr->cur_start_row;
  bytesperrow = ptr->blocksperrow << 7;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C040
// Name: access_virt_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl access_virt_sarray(
        jpeg_common_struct *cinfo,
        jvirt_sarray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable)
{
  unsigned int v5; // ebx
  jpeg_common_struct *v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // eax
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned int i; // ebx
  unsigned int bytesperrow; // [esp+20h] [ebp+14h]

  v5 = num_rows + start_row;
  if ( num_rows + start_row <= ptr->rows_in_array && num_rows <= ptr->maxaccess && ptr->mem_buffer != nullptr )
  {
    v6 = cinfo;
  }
  else
  {
    v6 = cinfo;
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v5 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      v6->err->msg_code = 69;
      v6->err->error_exit(a1: v6);
    }
    if ( ptr->dirty != 0 )
    {
      do_sarray_io(ptr, cinfo: v6, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v5 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_sarray_io(ptr, cinfo: v6, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= v5 )
  {
LABEL_27:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_28:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row >= start_row )
  {
    v10 = ptr->first_undef_row;
  }
  else
  {
    if ( writable != 0 )
    {
      v6->err->msg_code = 22;
      v6->err->error_exit(a1: v6);
    }
    v10 = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = v5;
  if ( ptr->pre_zero != 0 )
  {
    bytesperrow = ptr->samplesperrow;
    v11 = ptr->cur_start_row;
    v12 = v10 - v11;
    for ( i = v5 - v11; v12 < i; ++v12 )
      jzero_far(target: ptr->mem_buffer[v12], bytestozero: bytesperrow);
    goto LABEL_27;
  }
  if ( writable != 0 )
    goto LABEL_28;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x1000C190
// Name: access_virt_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl access_virt_barray(
        jpeg_common_struct *cinfo,
        jvirt_barray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable))[64]
{
  unsigned int v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // edi
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned int end_row; // [esp+20h] [ebp+14h]
  unsigned int end_rowa; // [esp+20h] [ebp+14h]

  v6 = num_rows + start_row;
  end_row = v6;
  if ( v6 > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == nullptr )
  {
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v6 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      cinfo->err->msg_code = 69;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( ptr->dirty != 0 )
    {
      do_barray_io(ptr, cinfo, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v6 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_barray_io(ptr, cinfo, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= end_row )
  {
LABEL_25:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_26:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row < start_row )
  {
    if ( writable != 0 )
    {
      cinfo->err->msg_code = 22;
      cinfo->err->error_exit(a1: cinfo);
    }
    first_undef_row = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = end_row;
  if ( ptr->pre_zero != 0 )
  {
    v10 = ptr->cur_start_row;
    v11 = first_undef_row - v10;
    v12 = ptr->blocksperrow << 7;
    for ( end_rowa = end_row - v10; v11 < end_rowa; ++v11 )
      jzero_far(target: ptr->mem_buffer[v11], bytestozero: v12);
    goto LABEL_25;
  }
  if ( writable != 0 )
    goto LABEL_26;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x1000C2E0
// Name: free_pool
// Source: json
//------------------------------------------------------------------------------
void __cdecl free_pool(jpeg_common_struct *cinfo, unsigned int pool_id)
{
  jpeg_memory_mgr *mem; // esi
  unsigned int v3; // edi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  unsigned int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  unsigned int v13; // ebx

  mem = cinfo->mem;
  v3 = pool_id;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( pool_id == 1 )
  {
    for ( i = mem[1].request_virt_sarray;
          i != nullptr;
          i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
              + 9) )
    {
      if ( *((_BYTE *)i + 34) != 0 )
      {
        v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
        *((_BYTE *)i + 34) = 0;
        v5(a1: cinfo, a2: (char *)i + 40);
      }
    }
    request_virt_barray = mem[1].request_virt_barray;
    for ( mem[1].request_virt_sarray = nullptr;
          request_virt_barray != nullptr;
          request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                + 9) )
    {
      if ( *((_BYTE *)request_virt_barray + 34) != 0 )
      {
        v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
        *((_BYTE *)request_virt_barray + 34) = 0;
        v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
      }
    }
    v3 = pool_id;
    mem[1].request_virt_barray = nullptr;
  }
  v8 = *((_DWORD **)&mem[1].alloc_sarray + v3);
  *((_DWORD *)&mem[1].alloc_sarray + v3) = 0;
  if ( v8 != nullptr )
  {
    do
    {
      v9 = (_DWORD *)*v8;
      v10 = v8[2] + v8[1] + 16;
      jpeg_free_small(cinfo, object: v8, sizeofobject: v10);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v10);
      v8 = v9;
    }
    while ( v9 != nullptr );
    v3 = pool_id;
  }
  v11 = *((_DWORD **)&mem[1].alloc_small + v3);
  *((_DWORD *)&mem[1].alloc_small + v3) = 0;
  if ( v11 != nullptr )
  {
    do
    {
      v12 = (_DWORD *)*v11;
      v13 = v11[2] + v11[1] + 16;
      jpeg_free_small(cinfo, object: v11, sizeofobject: v13);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v13);
      v11 = v12;
    }
    while ( v12 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C3F0
// Name: self_destruct
// Source: json
//------------------------------------------------------------------------------
void __cdecl self_destruct(jpeg_common_struct *cinfo)
{
  int v2; // edi
  jpeg_memory_mgr *mem; // esi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  int pool; // [esp+Ch] [ebp-4h]
  unsigned int cinfoa; // [esp+18h] [ebp+8h]
  unsigned int cinfob; // [esp+18h] [ebp+8h]

  v2 = 1;
  pool = 1;
  do
  {
    mem = cinfo->mem;
    if ( v2 >= 2 )
    {
      cinfo->err->msg_code = 14;
      cinfo->err->msg_parm.i[0] = v2;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v2 == 1 )
    {
      for ( i = mem[1].request_virt_sarray;
            i != nullptr;
            i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
                + 9) )
      {
        if ( *((_BYTE *)i + 34) != 0 )
        {
          v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
          *((_BYTE *)i + 34) = 0;
          v5(a1: cinfo, a2: (char *)i + 40);
        }
      }
      request_virt_barray = mem[1].request_virt_barray;
      for ( mem[1].request_virt_sarray = nullptr;
            request_virt_barray != nullptr;
            request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                  + 9) )
      {
        if ( *((_BYTE *)request_virt_barray + 34) != 0 )
        {
          v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
          *((_BYTE *)request_virt_barray + 34) = 0;
          v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
        }
      }
      v2 = pool;
      mem[1].request_virt_barray = nullptr;
    }
    v8 = *((_DWORD **)&mem[1].alloc_sarray + v2);
    *((_DWORD *)&mem[1].alloc_sarray + v2) = 0;
    if ( v8 != nullptr )
    {
      do
      {
        v9 = (_DWORD *)*v8;
        cinfoa = v8[2] + v8[1] + 16;
        jpeg_free_small(cinfo, object: v8, sizeofobject: cinfoa);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - cinfoa);
        v8 = v9;
      }
      while ( v9 != nullptr );
      v2 = pool;
    }
    v10 = *((_DWORD **)&mem[1].alloc_small + v2);
    *((_DWORD *)&mem[1].alloc_small + v2) = 0;
    if ( v10 != nullptr )
    {
      do
      {
        v11 = (_DWORD *)*v10;
        cinfob = v10[2] + v10[1] + 16;
        jpeg_free_small(cinfo, object: v10, sizeofobject: cinfob);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - cinfob);
        v10 = v11;
      }
      while ( v11 != nullptr );
      v2 = pool;
    }
    pool = --v2;
  }
  while ( v2 >= 0 );
  jpeg_free_small(cinfo, object: cinfo->mem, sizeofobject: 0x54u);
  cinfo->mem = nullptr;
  jpeg_mem_term((jpeg_decompress_struct *)cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x1000C530
// Name: _jinit_memory_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_memory_mgr(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // edi
  int (__cdecl **small)(jpeg_common_struct *, unsigned int, unsigned int); // esi
  char *v3; // eax
  jpeg_common_struct *v4; // [esp-4h] [ebp-14h]
  int max_to_use; // [esp+Ch] [ebp-4h] BYREF

  v1 = cinfo;
  v4 = cinfo;
  cinfo->mem = nullptr;
  max_to_use = jpeg_mem_init(cinfo: v4);
  small = (int (__cdecl **)(jpeg_common_struct *, unsigned int, unsigned int))jpeg_get_small(
                                                                                cinfo: v1,
                                                                                sizeofobject: 0x54u);
  if ( small == nullptr )
  {
    jpeg_mem_term(cinfo: (jpeg_decompress_struct *)v1);
    v1->err->msg_code = 54;
    v1->err->msg_parm.i[0] = 0;
    v1->err->error_exit(a1: v1);
  }
  *small = alloc_small;
  small[1] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_large;
  small[2] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_sarray;
  small[3] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_barray;
  small[4] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_sarray;
  small[5] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_barray;
  small[6] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))realize_virt_arrays;
  small[7] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_sarray;
  small[8] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_barray;
  small[9] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))free_pool;
  small[10] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))self_destruct;
  small[12] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))1000000000;
  small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))max_to_use;
  small[14] = nullptr;
  small[16] = nullptr;
  small[13] = nullptr;
  small[15] = nullptr;
  small[17] = nullptr;
  small[18] = nullptr;
  small[19] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))84;
  v1->mem = (jpeg_memory_mgr *)small;
  v3 = getenv(option: "JPEGMEM");
  if ( v3 != nullptr )
  {
    HIBYTE(cinfo) = 120;
    if ( sscanf(string: v3, format: "%ld%c", &max_to_use, (char *)&cinfo + 3) > 0 )
    {
      if ( HIBYTE(cinfo) == 109 || HIBYTE(cinfo) == 77 )
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000000 * max_to_use);
      else
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000 * max_to_use);
    }
  }
}

} // namespace FileSystemOpenDialog

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10251300
// Name: alloc_small
// Source: json
//------------------------------------------------------------------------------
int __cdecl alloc_small(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  small_pool_struct *next; // eax
  unsigned int v6; // ebx
  unsigned int v7; // esi
  unsigned int bytes_used; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  small_pool_struct *prev_hdr_ptr; // [esp+18h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 1;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
  {
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
    sizeofobject = v3;
  }
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  next = mem->small_list[pool_id];
  prev_hdr_ptr = nullptr;
  if ( next != nullptr )
  {
    while ( next->hdr.bytes_left < v3 )
    {
      prev_hdr_ptr = next;
      next = next->hdr.next;
      if ( next == nullptr )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v6 = v3 + 16;
    if ( prev_hdr_ptr != nullptr )
      v7 = extra_pool_slop[pool_id];
    else
      v7 = first_pool_slop[pool_id];
    if ( v7 > 1000000000 - v6 )
      v7 = 1000000000 - v6;
    for ( next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6);
          next == nullptr;
          next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6) )
    {
      v7 >>= 1;
      if ( v7 < 0x32 )
      {
        cinfo->err->msg_code = 54;
        cinfo->err->msg_parm.i[0] = 2;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    mem->total_space_allocated += v7 + v6;
    v3 = sizeofobject;
    next->hdr.next = nullptr;
    next->hdr.bytes_used = 0;
    next->hdr.bytes_left = sizeofobject + v7;
    if ( prev_hdr_ptr != nullptr )
      prev_hdr_ptr->hdr.next = next;
    else
      mem->small_list[pool_id] = next;
  }
  bytes_used = next->hdr.bytes_used;
  next->hdr.bytes_left -= v3;
  next->hdr.bytes_used = v3 + bytes_used;
  return (int)&next[1] + bytes_used;
}

//------------------------------------------------------------------------------
// Address: 0x10251450
// Name: alloc_large
// Source: json
//------------------------------------------------------------------------------
large_pool_struct *__cdecl alloc_large(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  large_pool_struct *small; // esi
  large_pool_struct *v6; // edx
  my_memory_mgr *mem; // [esp+14h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  small = (large_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v3 + 16);
  if ( small == nullptr )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem->total_space_allocated += v3 + 16;
  v6 = mem->large_list[pool_id];
  small->hdr.bytes_used = v3;
  small->hdr.next = v6;
  small->hdr.bytes_left = 0;
  mem->large_list[pool_id] = small;
  return small + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10251520
// Name: alloc_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl alloc_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 **samplesperrow,
        signed int numrows)
{
  unsigned int v5; // edi
  unsigned __int8 **result; // eax
  unsigned int v7; // esi
  large_pool_struct *v8; // eax
  unsigned int i; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  unsigned __int8 **v11; // [esp+20h] [ebp+10h]

  mem = (my_memory_mgr *)cinfo->mem;
  v5 = 0x3B9AC9F0 / (unsigned int)samplesperrow;
  if ( 0x3B9AC9F0 / (unsigned int)samplesperrow == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v5 >= numrows )
    v5 = numrows;
  mem->last_rowsperchunk = v5;
  result = (unsigned __int8 **)alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v7 = 0;
  v11 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v5 >= numrows - v7 )
        v5 = numrows - v7;
      v8 = alloc_large(cinfo, pool_id, sizeofobject: (_DWORD)samplesperrow * v5);
      for ( i = v5; i != 0; --i )
      {
        v11[v7++] = (unsigned __int8 *)v8;
        v8 = (large_pool_struct *)((char *)v8 + (_DWORD)samplesperrow);
      }
    }
    while ( v7 < numrows );
    return v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102515D0
// Name: alloc_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl alloc_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned int blocksperrow,
        signed int numrows))[64]
{
  unsigned int v4; // edi
  __int16 (**result)[64]; // eax
  unsigned int v6; // esi
  large_pool_struct *v7; // eax
  unsigned int i; // ecx
  __int16 (**mem)[64]; // [esp+Ch] [ebp-4h]
  __int16 (**v10)[64]; // [esp+Ch] [ebp-4h]

  mem = (__int16 (**)[64])cinfo->mem;
  v4 = 0x3B9AC9F0 / (blocksperrow << 7);
  if ( v4 == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v4 >= numrows )
    v4 = numrows;
  mem[20] = (__int16 (*)[64])v4;
  result = (__int16 (**)[64])alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v6 = 0;
  v10 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v4 >= numrows - v6 )
        v4 = numrows - v6;
      v7 = alloc_large(cinfo, pool_id, sizeofobject: (blocksperrow * v4) << 7);
      for ( i = v4; i != 0; --i )
      {
        v10[v6++] = (__int16 (*)[64])v7;
        v7 += 8 * blocksperrow;
      }
    }
    while ( v6 < numrows );
    return v10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10251680
// Name: request_virt_sarray
// Source: json
//------------------------------------------------------------------------------
jvirt_sarray_control *__cdecl request_virt_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int samplesperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_sarray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_sarray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->samplesperrow = samplesperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_sarray_control *)mem[1].request_virt_sarray;
  mem[1].request_virt_sarray = (jvirt_sarray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102516F0
// Name: request_virt_barray
// Source: json
//------------------------------------------------------------------------------
jvirt_barray_control *__cdecl request_virt_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int blocksperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_barray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_barray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->blocksperrow = blocksperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_barray_control *)mem[1].request_virt_barray;
  mem[1].request_virt_barray = (jvirt_barray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10251760
// Name: realize_virt_arrays
// Source: json
//------------------------------------------------------------------------------
void __cdecl realize_virt_arrays(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *p_pub; // edi
  jvirt_sarray_control *(__cdecl *request_virt_sarray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  jvirt_barray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  jvirt_sarray_control *(__cdecl *j)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v11; // edi
  unsigned int v12; // ecx
  jvirt_barray_control *(__cdecl *k)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v14; // edi
  unsigned int v15; // ecx
  int v16; // [esp-4h] [ebp-14h]
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]

  p_pub = cinfo->mem;
  request_virt_sarray = p_pub[1].request_virt_sarray;
  v3 = 0;
  v4 = 0;
  for ( mem = (my_memory_mgr *)p_pub;
        request_virt_sarray != nullptr;
        request_virt_sarray = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_sarray
                              + 9) )
  {
    if ( *(_DWORD *)request_virt_sarray == 0 )
    {
      v5 = *((_DWORD *)request_virt_sarray + 2);
      v3 += v5 * *((_DWORD *)request_virt_sarray + 3);
      v4 += v5 * *((_DWORD *)request_virt_sarray + 1);
    }
  }
  for ( i = p_pub[1].request_virt_barray;
        i != nullptr;
        i = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
            + 9) )
  {
    if ( *(_DWORD *)i == 0 )
    {
      v7 = *((_DWORD *)i + 2);
      v3 += (v7 * *((_DWORD *)i + 3)) << 7;
      v4 += (v7 * *((_DWORD *)i + 1)) << 7;
    }
  }
  if ( v3 > 0 )
  {
    v8 = jpeg_mem_available(
           cinfo,
           min_bytes_needed: v3,
           max_bytes_needed: v4,
           already_allocated: (int)p_pub[1].realize_virt_arrays);
    if ( v8 < v4 )
    {
      v9 = v8 / v3;
      if ( v8 / v3 <= 0 )
        v9 = 1;
    }
    else
    {
      v9 = 1000000000;
    }
    for ( j = p_pub[1].request_virt_sarray;
          j != nullptr;
          j = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))j
              + 9) )
    {
      if ( *(_DWORD *)j == 0 )
      {
        v11 = *((_DWORD *)j + 1);
        v12 = *((_DWORD *)j + 3);
        if ( (int)((v11 - 1) / v12 + 1) > v9 )
        {
          v16 = v11 * *((_DWORD *)j + 2);
          *((_DWORD *)j + 4) = v9 * v12;
          jpeg_open_backing_store(cinfo, info: (backing_store_struct *)((char *)j + 40), total_bytes_needed: v16);
          *((_BYTE *)j + 34) = 1;
        }
        else
        {
          *((_DWORD *)j + 4) = v11;
        }
        *(_DWORD *)j = alloc_sarray(
                         cinfo,
                         pool_id: 1u,
                         samplesperrow: *((unsigned __int8 ***)j + 2),
                         numrows: *((_DWORD *)j + 4));
        *((_DWORD *)j + 5) = mem->last_rowsperchunk;
        *((_DWORD *)j + 6) = 0;
        *((_DWORD *)j + 7) = 0;
        *((_BYTE *)j + 33) = 0;
        p_pub = &mem->pub;
      }
    }
    for ( k = p_pub[1].request_virt_barray;
          k != nullptr;
          k = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))k
              + 9) )
    {
      if ( *(_DWORD *)k == 0 )
      {
        v14 = *((_DWORD *)k + 1);
        v15 = *((_DWORD *)k + 3);
        if ( (int)((v14 - 1) / v15 + 1) > v9 )
        {
          *((_DWORD *)k + 4) = v9 * v15;
          jpeg_open_backing_store(
            cinfo,
            info: (backing_store_struct *)((char *)k + 40),
            total_bytes_needed: (v14 * *((_DWORD *)k + 2)) << 7);
          *((_BYTE *)k + 34) = 1;
        }
        else
        {
          *((_DWORD *)k + 4) = v14;
        }
        *(_DWORD *)k = alloc_barray(cinfo, pool_id: 1u, blocksperrow: *((_DWORD *)k + 2), numrows: *((_DWORD *)k + 4));
        *((_DWORD *)k + 5) = mem->last_rowsperchunk;
        *((_DWORD *)k + 6) = 0;
        *((_DWORD *)k + 7) = 0;
        *((_BYTE *)k + 33) = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10251900
// Name: do_sarray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_sarray_io(jvirt_sarray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  unsigned int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = ptr->samplesperrow * ptr->cur_start_row;
  bytesperrow = ptr->samplesperrow;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102519A0
// Name: do_barray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_barray_io(jvirt_barray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = (ptr->blocksperrow << 7) * ptr->cur_start_row;
  bytesperrow = ptr->blocksperrow << 7;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10251A40
// Name: access_virt_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl access_virt_sarray(
        jpeg_common_struct *cinfo,
        jvirt_sarray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable)
{
  unsigned int v5; // ebx
  jpeg_common_struct *v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // eax
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned int i; // ebx
  unsigned int bytesperrow; // [esp+20h] [ebp+14h]

  v5 = num_rows + start_row;
  if ( num_rows + start_row <= ptr->rows_in_array && num_rows <= ptr->maxaccess && ptr->mem_buffer != nullptr )
  {
    v6 = cinfo;
  }
  else
  {
    v6 = cinfo;
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v5 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      v6->err->msg_code = 69;
      v6->err->error_exit(a1: v6);
    }
    if ( ptr->dirty != 0 )
    {
      do_sarray_io(ptr, cinfo: v6, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v5 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_sarray_io(ptr, cinfo: v6, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= v5 )
  {
LABEL_27:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_28:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row >= start_row )
  {
    v10 = ptr->first_undef_row;
  }
  else
  {
    if ( writable != 0 )
    {
      v6->err->msg_code = 22;
      v6->err->error_exit(a1: v6);
    }
    v10 = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = v5;
  if ( ptr->pre_zero != 0 )
  {
    bytesperrow = ptr->samplesperrow;
    v11 = ptr->cur_start_row;
    v12 = v10 - v11;
    for ( i = v5 - v11; v12 < i; ++v12 )
      jzero_far(target: ptr->mem_buffer[v12], bytestozero: bytesperrow);
    goto LABEL_27;
  }
  if ( writable != 0 )
    goto LABEL_28;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x10251B90
// Name: access_virt_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl access_virt_barray(
        jpeg_common_struct *cinfo,
        jvirt_barray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable))[64]
{
  unsigned int v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // edi
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned int end_row; // [esp+20h] [ebp+14h]
  unsigned int end_rowa; // [esp+20h] [ebp+14h]

  v6 = num_rows + start_row;
  end_row = v6;
  if ( v6 > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == nullptr )
  {
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v6 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      cinfo->err->msg_code = 69;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( ptr->dirty != 0 )
    {
      do_barray_io(ptr, cinfo, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v6 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_barray_io(ptr, cinfo, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= end_row )
  {
LABEL_25:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_26:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row < start_row )
  {
    if ( writable != 0 )
    {
      cinfo->err->msg_code = 22;
      cinfo->err->error_exit(a1: cinfo);
    }
    first_undef_row = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = end_row;
  if ( ptr->pre_zero != 0 )
  {
    v10 = ptr->cur_start_row;
    v11 = first_undef_row - v10;
    v12 = ptr->blocksperrow << 7;
    for ( end_rowa = end_row - v10; v11 < end_rowa; ++v11 )
      jzero_far(target: ptr->mem_buffer[v11], bytestozero: v12);
    goto LABEL_25;
  }
  if ( writable != 0 )
    goto LABEL_26;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x10251CE0
// Name: free_pool
// Source: json
//------------------------------------------------------------------------------
void __cdecl free_pool(jpeg_common_struct *cinfo, unsigned int pool_id)
{
  jpeg_memory_mgr *mem; // esi
  unsigned int v3; // edi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  unsigned int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  unsigned int v13; // ebx

  mem = cinfo->mem;
  v3 = pool_id;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( pool_id == 1 )
  {
    for ( i = mem[1].request_virt_sarray;
          i != nullptr;
          i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
              + 9) )
    {
      if ( *((_BYTE *)i + 34) != 0 )
      {
        v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
        *((_BYTE *)i + 34) = 0;
        v5(a1: cinfo, a2: (char *)i + 40);
      }
    }
    request_virt_barray = mem[1].request_virt_barray;
    for ( mem[1].request_virt_sarray = nullptr;
          request_virt_barray != nullptr;
          request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                + 9) )
    {
      if ( *((_BYTE *)request_virt_barray + 34) != 0 )
      {
        v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
        *((_BYTE *)request_virt_barray + 34) = 0;
        v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
      }
    }
    v3 = pool_id;
    mem[1].request_virt_barray = nullptr;
  }
  v8 = *((_DWORD **)&mem[1].alloc_sarray + v3);
  *((_DWORD *)&mem[1].alloc_sarray + v3) = 0;
  if ( v8 != nullptr )
  {
    do
    {
      v9 = (_DWORD *)*v8;
      v10 = v8[2] + v8[1] + 16;
      jpeg_free_small(cinfo, object: v8, sizeofobject: v10);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v10);
      v8 = v9;
    }
    while ( v9 != nullptr );
    v3 = pool_id;
  }
  v11 = *((_DWORD **)&mem[1].alloc_small + v3);
  *((_DWORD *)&mem[1].alloc_small + v3) = 0;
  if ( v11 != nullptr )
  {
    do
    {
      v12 = (_DWORD *)*v11;
      v13 = v11[2] + v11[1] + 16;
      jpeg_free_small(cinfo, object: v11, sizeofobject: v13);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v13);
      v11 = v12;
    }
    while ( v12 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10251DF0
// Name: self_destruct
// Source: json
//------------------------------------------------------------------------------
void __cdecl self_destruct(jpeg_common_struct *cinfo)
{
  int v2; // edi
  jpeg_memory_mgr *mem; // esi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  vgui::PropertyPage *v12; // ecx
  int pool; // [esp+Ch] [ebp-4h]
  unsigned int cinfoa; // [esp+18h] [ebp+8h]
  unsigned int cinfob; // [esp+18h] [ebp+8h]

  v2 = 1;
  pool = 1;
  do
  {
    mem = cinfo->mem;
    if ( v2 >= 2 )
    {
      cinfo->err->msg_code = 14;
      cinfo->err->msg_parm.i[0] = v2;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v2 == 1 )
    {
      for ( i = mem[1].request_virt_sarray;
            i != nullptr;
            i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
                + 9) )
      {
        if ( *((_BYTE *)i + 34) != 0 )
        {
          v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
          *((_BYTE *)i + 34) = 0;
          v5(a1: cinfo, a2: (char *)i + 40);
        }
      }
      request_virt_barray = mem[1].request_virt_barray;
      for ( mem[1].request_virt_sarray = nullptr;
            request_virt_barray != nullptr;
            request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                  + 9) )
      {
        if ( *((_BYTE *)request_virt_barray + 34) != 0 )
        {
          v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
          *((_BYTE *)request_virt_barray + 34) = 0;
          v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
        }
      }
      v2 = pool;
      mem[1].request_virt_barray = nullptr;
    }
    v8 = *((_DWORD **)&mem[1].alloc_sarray + v2);
    *((_DWORD *)&mem[1].alloc_sarray + v2) = 0;
    if ( v8 != nullptr )
    {
      do
      {
        v9 = (_DWORD *)*v8;
        cinfoa = v8[2] + v8[1] + 16;
        jpeg_free_small(cinfo, object: v8, sizeofobject: cinfoa);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - cinfoa);
        v8 = v9;
      }
      while ( v9 != nullptr );
      v2 = pool;
    }
    v10 = *((_DWORD **)&mem[1].alloc_small + v2);
    *((_DWORD *)&mem[1].alloc_small + v2) = 0;
    if ( v10 != nullptr )
    {
      do
      {
        v11 = (_DWORD *)*v10;
        cinfob = v10[2] + v10[1] + 16;
        jpeg_free_small(cinfo, object: v10, sizeofobject: cinfob);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - cinfob);
        v10 = v11;
      }
      while ( v11 != nullptr );
      v2 = pool;
    }
    pool = --v2;
  }
  while ( v2 >= 0 );
  jpeg_free_small(cinfo, object: cinfo->mem, sizeofobject: 0x54u);
  cinfo->mem = nullptr;
  CColorBalanceUIPanel::Init(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10251F30
// Name: _jinit_memory_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_memory_mgr(jpeg_common_struct *cinfo)
{
  vgui::CTreeViewListControl *v1; // ecx
  jpeg_common_struct *v2; // edi
  vgui::PropertyPage *v3; // ecx
  int (__cdecl **small)(jpeg_common_struct *, unsigned int, unsigned int); // esi
  char *v5; // eax
  int max_to_use; // [esp+Ch] [ebp-4h] BYREF

  v2 = cinfo;
  cinfo->mem = nullptr;
  max_to_use = CTraceFilter::GetTraceType(this: v1);
  small = (int (__cdecl **)(jpeg_common_struct *, unsigned int, unsigned int))jpeg_get_small(
                                                                                cinfo: v2,
                                                                                sizeofobject: 0x54u);
  if ( small == nullptr )
  {
    CColorBalanceUIPanel::Init(this: v3);
    v2->err->msg_code = 54;
    v2->err->msg_parm.i[0] = 0;
    ((void (__cdecl *)(jpeg_common_struct *, jpeg_common_struct *))v2->err->error_exit)(a1: v2, a2: v2);
  }
  *small = alloc_small;
  small[1] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_large;
  small[2] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_sarray;
  small[3] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_barray;
  small[4] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_sarray;
  small[5] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_barray;
  small[6] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))realize_virt_arrays;
  small[7] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_sarray;
  small[8] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_barray;
  small[9] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))free_pool;
  small[10] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))self_destruct;
  small[12] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))1000000000;
  small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))max_to_use;
  small[14] = nullptr;
  small[16] = nullptr;
  small[13] = nullptr;
  small[15] = nullptr;
  small[17] = nullptr;
  small[18] = nullptr;
  small[19] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))84;
  v2->mem = (jpeg_memory_mgr *)small;
  v5 = getenv(option: "JPEGMEM");
  if ( v5 != nullptr )
  {
    HIBYTE(cinfo) = 120;
    if ( sscanf(string: v5, format: "%ld%c", &max_to_use, (char *)&cinfo + 3) > 0 )
    {
      if ( HIBYTE(cinfo) == 109 || HIBYTE(cinfo) == 77 )
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000000 * max_to_use);
      else
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000 * max_to_use);
    }
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x00405810
// Name: alloc_small
// Source: json
//------------------------------------------------------------------------------
int __cdecl alloc_small(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  small_pool_struct *next; // eax
  unsigned int v6; // ebx
  unsigned int v7; // esi
  unsigned int bytes_used; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  small_pool_struct *prev_hdr_ptr; // [esp+18h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 1;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
  {
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
    sizeofobject = v3;
  }
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  next = mem->small_list[pool_id];
  prev_hdr_ptr = nullptr;
  if ( next != nullptr )
  {
    while ( next->hdr.bytes_left < v3 )
    {
      prev_hdr_ptr = next;
      next = next->hdr.next;
      if ( next == nullptr )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v6 = v3 + 16;
    if ( prev_hdr_ptr != nullptr )
      v7 = extra_pool_slop[pool_id];
    else
      v7 = first_pool_slop[pool_id];
    if ( v7 > 1000000000 - v6 )
      v7 = 1000000000 - v6;
    for ( next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6);
          next == nullptr;
          next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6) )
    {
      v7 >>= 1;
      if ( v7 < 0x32 )
      {
        cinfo->err->msg_code = 54;
        cinfo->err->msg_parm.i[0] = 2;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    mem->total_space_allocated += v7 + v6;
    v3 = sizeofobject;
    next->hdr.next = nullptr;
    next->hdr.bytes_used = 0;
    next->hdr.bytes_left = sizeofobject + v7;
    if ( prev_hdr_ptr != nullptr )
      prev_hdr_ptr->hdr.next = next;
    else
      mem->small_list[pool_id] = next;
  }
  bytes_used = next->hdr.bytes_used;
  next->hdr.bytes_left -= v3;
  next->hdr.bytes_used = v3 + bytes_used;
  return (int)&next[1] + bytes_used;
}

//------------------------------------------------------------------------------
// Address: 0x00405960
// Name: alloc_large
// Source: json
//------------------------------------------------------------------------------
large_pool_struct *__cdecl alloc_large(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  large_pool_struct *small; // esi
  large_pool_struct *v6; // edx
  my_memory_mgr *mem; // [esp+14h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  small = (large_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v3 + 16);
  if ( small == nullptr )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem->total_space_allocated += v3 + 16;
  v6 = mem->large_list[pool_id];
  small->hdr.bytes_used = v3;
  small->hdr.next = v6;
  small->hdr.bytes_left = 0;
  mem->large_list[pool_id] = small;
  return small + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405A30
// Name: alloc_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl alloc_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 **samplesperrow,
        signed int numrows)
{
  unsigned int v5; // edi
  unsigned __int8 **result; // eax
  unsigned int v7; // esi
  large_pool_struct *v8; // eax
  unsigned int i; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  unsigned __int8 **v11; // [esp+20h] [ebp+10h]

  mem = (my_memory_mgr *)cinfo->mem;
  v5 = 0x3B9AC9F0 / (unsigned int)samplesperrow;
  if ( 0x3B9AC9F0 / (unsigned int)samplesperrow == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v5 >= numrows )
    v5 = numrows;
  mem->last_rowsperchunk = v5;
  result = (unsigned __int8 **)alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v7 = 0;
  v11 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v5 >= numrows - v7 )
        v5 = numrows - v7;
      v8 = alloc_large(cinfo, pool_id, sizeofobject: (_DWORD)samplesperrow * v5);
      for ( i = v5; i != 0; --i )
      {
        v11[v7++] = (unsigned __int8 *)v8;
        v8 = (large_pool_struct *)((char *)v8 + (_DWORD)samplesperrow);
      }
    }
    while ( v7 < numrows );
    return v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405AE0
// Name: alloc_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl alloc_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned int blocksperrow,
        signed int numrows))[64]
{
  unsigned int v4; // edi
  __int16 (**result)[64]; // eax
  unsigned int v6; // esi
  large_pool_struct *v7; // eax
  unsigned int i; // ecx
  __int16 (**mem)[64]; // [esp+Ch] [ebp-4h]
  __int16 (**v10)[64]; // [esp+Ch] [ebp-4h]

  mem = (__int16 (**)[64])cinfo->mem;
  v4 = 0x3B9AC9F0 / (blocksperrow << 7);
  if ( v4 == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v4 >= numrows )
    v4 = numrows;
  mem[20] = (__int16 (*)[64])v4;
  result = (__int16 (**)[64])alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v6 = 0;
  v10 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v4 >= numrows - v6 )
        v4 = numrows - v6;
      v7 = alloc_large(cinfo, pool_id, sizeofobject: (blocksperrow * v4) << 7);
      for ( i = v4; i != 0; --i )
      {
        v10[v6++] = (__int16 (*)[64])v7;
        v7 += 8 * blocksperrow;
      }
    }
    while ( v6 < numrows );
    return v10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405B90
// Name: request_virt_sarray
// Source: json
//------------------------------------------------------------------------------
jvirt_sarray_control *__cdecl request_virt_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int samplesperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_sarray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_sarray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->samplesperrow = samplesperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_sarray_control *)mem[1].request_virt_sarray;
  mem[1].request_virt_sarray = (jvirt_sarray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405C00
// Name: request_virt_barray
// Source: json
//------------------------------------------------------------------------------
jvirt_barray_control *__cdecl request_virt_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int blocksperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_barray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_barray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->blocksperrow = blocksperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_barray_control *)mem[1].request_virt_barray;
  mem[1].request_virt_barray = (jvirt_barray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405C70
// Name: realize_virt_arrays
// Source: json
//------------------------------------------------------------------------------
void __cdecl realize_virt_arrays(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *p_pub; // edi
  jvirt_sarray_control *(__cdecl *request_virt_sarray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  jvirt_barray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  jvirt_sarray_control *(__cdecl *j)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v11; // edi
  unsigned int v12; // ecx
  jvirt_barray_control *(__cdecl *k)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v14; // edi
  unsigned int v15; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]

  p_pub = cinfo->mem;
  request_virt_sarray = p_pub[1].request_virt_sarray;
  v3 = 0;
  v4 = 0;
  for ( mem = (my_memory_mgr *)p_pub;
        request_virt_sarray != nullptr;
        request_virt_sarray = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_sarray
                              + 9) )
  {
    if ( *(_DWORD *)request_virt_sarray == 0 )
    {
      v5 = *((_DWORD *)request_virt_sarray + 2);
      v3 += v5 * *((_DWORD *)request_virt_sarray + 3);
      v4 += v5 * *((_DWORD *)request_virt_sarray + 1);
    }
  }
  for ( i = p_pub[1].request_virt_barray;
        i != nullptr;
        i = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
            + 9) )
  {
    if ( *(_DWORD *)i == 0 )
    {
      v7 = *((_DWORD *)i + 2);
      v3 += (v7 * *((_DWORD *)i + 3)) << 7;
      v4 += (v7 * *((_DWORD *)i + 1)) << 7;
    }
  }
  if ( v3 > 0 )
  {
    v8 = jpeg_mem_available(cinfo, min_bytes_needed: v3, max_bytes_needed: v4);
    if ( v8 < v4 )
    {
      v9 = v8 / v3;
      if ( v8 / v3 <= 0 )
        v9 = 1;
    }
    else
    {
      v9 = 1000000000;
    }
    for ( j = p_pub[1].request_virt_sarray;
          j != nullptr;
          j = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))j
              + 9) )
    {
      if ( *(_DWORD *)j == 0 )
      {
        v11 = *((_DWORD *)j + 1);
        v12 = *((_DWORD *)j + 3);
        if ( (int)((v11 - 1) / v12 + 1) > v9 )
        {
          *((_DWORD *)j + 4) = v9 * v12;
          jpeg_open_backing_store(cinfo);
          *((_BYTE *)j + 34) = 1;
        }
        else
        {
          *((_DWORD *)j + 4) = v11;
        }
        *(_DWORD *)j = alloc_sarray(
                         cinfo,
                         pool_id: 1u,
                         samplesperrow: *((unsigned __int8 ***)j + 2),
                         numrows: *((_DWORD *)j + 4));
        *((_DWORD *)j + 5) = mem->last_rowsperchunk;
        *((_DWORD *)j + 6) = 0;
        *((_DWORD *)j + 7) = 0;
        *((_BYTE *)j + 33) = 0;
        p_pub = &mem->pub;
      }
    }
    for ( k = p_pub[1].request_virt_barray;
          k != nullptr;
          k = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))k
              + 9) )
    {
      if ( *(_DWORD *)k == 0 )
      {
        v14 = *((_DWORD *)k + 1);
        v15 = *((_DWORD *)k + 3);
        if ( (int)((v14 - 1) / v15 + 1) > v9 )
        {
          *((_DWORD *)k + 4) = v9 * v15;
          jpeg_open_backing_store(cinfo);
          *((_BYTE *)k + 34) = 1;
        }
        else
        {
          *((_DWORD *)k + 4) = v14;
        }
        *(_DWORD *)k = alloc_barray(cinfo, pool_id: 1u, blocksperrow: *((_DWORD *)k + 2), numrows: *((_DWORD *)k + 4));
        *((_DWORD *)k + 5) = mem->last_rowsperchunk;
        *((_DWORD *)k + 6) = 0;
        *((_DWORD *)k + 7) = 0;
        *((_BYTE *)k + 33) = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405E10
// Name: do_sarray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_sarray_io(jvirt_sarray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  unsigned int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = ptr->samplesperrow * ptr->cur_start_row;
  bytesperrow = ptr->samplesperrow;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405EB0
// Name: do_barray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_barray_io(jvirt_barray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = (ptr->blocksperrow << 7) * ptr->cur_start_row;
  bytesperrow = ptr->blocksperrow << 7;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405F50
// Name: access_virt_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl access_virt_sarray(
        jpeg_common_struct *cinfo,
        jvirt_sarray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable)
{
  unsigned int v5; // ebx
  jpeg_common_struct *v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // eax
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned int i; // ebx
  unsigned int bytesperrow; // [esp+20h] [ebp+14h]

  v5 = num_rows + start_row;
  if ( num_rows + start_row <= ptr->rows_in_array && num_rows <= ptr->maxaccess && ptr->mem_buffer != nullptr )
  {
    v6 = cinfo;
  }
  else
  {
    v6 = cinfo;
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v5 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      v6->err->msg_code = 69;
      v6->err->error_exit(a1: v6);
    }
    if ( ptr->dirty != 0 )
    {
      do_sarray_io(ptr, cinfo: v6, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v5 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_sarray_io(ptr, cinfo: v6, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= v5 )
  {
LABEL_27:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_28:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row >= start_row )
  {
    v10 = ptr->first_undef_row;
  }
  else
  {
    if ( writable != 0 )
    {
      v6->err->msg_code = 22;
      v6->err->error_exit(a1: v6);
    }
    v10 = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = v5;
  if ( ptr->pre_zero != 0 )
  {
    bytesperrow = ptr->samplesperrow;
    v11 = ptr->cur_start_row;
    v12 = v10 - v11;
    for ( i = v5 - v11; v12 < i; ++v12 )
      jzero_far(target: ptr->mem_buffer[v12], bytestozero: bytesperrow);
    goto LABEL_27;
  }
  if ( writable != 0 )
    goto LABEL_28;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x004060A0
// Name: access_virt_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl access_virt_barray(
        jpeg_common_struct *cinfo,
        jvirt_barray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable))[64]
{
  unsigned int v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // edi
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned int end_row; // [esp+20h] [ebp+14h]
  unsigned int end_rowa; // [esp+20h] [ebp+14h]

  v6 = num_rows + start_row;
  end_row = v6;
  if ( v6 > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == nullptr )
  {
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v6 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      cinfo->err->msg_code = 69;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( ptr->dirty != 0 )
    {
      do_barray_io(ptr, cinfo, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v6 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_barray_io(ptr, cinfo, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= end_row )
  {
LABEL_25:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_26:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row < start_row )
  {
    if ( writable != 0 )
    {
      cinfo->err->msg_code = 22;
      cinfo->err->error_exit(a1: cinfo);
    }
    first_undef_row = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = end_row;
  if ( ptr->pre_zero != 0 )
  {
    v10 = ptr->cur_start_row;
    v11 = first_undef_row - v10;
    v12 = ptr->blocksperrow << 7;
    for ( end_rowa = end_row - v10; v11 < end_rowa; ++v11 )
      jzero_far(target: ptr->mem_buffer[v11], bytestozero: v12);
    goto LABEL_25;
  }
  if ( writable != 0 )
    goto LABEL_26;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x004061F0
// Name: free_pool
// Source: json
//------------------------------------------------------------------------------
void __cdecl free_pool(jpeg_common_struct *cinfo, unsigned int pool_id)
{
  jpeg_memory_mgr *mem; // esi
  unsigned int v3; // edi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  int v13; // ebx

  mem = cinfo->mem;
  v3 = pool_id;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( pool_id == 1 )
  {
    for ( i = mem[1].request_virt_sarray;
          i != nullptr;
          i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
              + 9) )
    {
      if ( *((_BYTE *)i + 34) != 0 )
      {
        v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
        *((_BYTE *)i + 34) = 0;
        v5(a1: cinfo, a2: (char *)i + 40);
      }
    }
    request_virt_barray = mem[1].request_virt_barray;
    for ( mem[1].request_virt_sarray = nullptr;
          request_virt_barray != nullptr;
          request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                + 9) )
    {
      if ( *((_BYTE *)request_virt_barray + 34) != 0 )
      {
        v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
        *((_BYTE *)request_virt_barray + 34) = 0;
        v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
      }
    }
    v3 = pool_id;
    mem[1].request_virt_barray = nullptr;
  }
  v8 = *((_DWORD **)&mem[1].alloc_sarray + v3);
  *((_DWORD *)&mem[1].alloc_sarray + v3) = 0;
  if ( v8 != nullptr )
  {
    do
    {
      v9 = (_DWORD *)*v8;
      v10 = v8[2] + v8[1] + 16;
      jpeg_free_small(cinfo, object: v8);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v10);
      v8 = v9;
    }
    while ( v9 != nullptr );
    v3 = pool_id;
  }
  v11 = *((_DWORD **)&mem[1].alloc_small + v3);
  *((_DWORD *)&mem[1].alloc_small + v3) = 0;
  if ( v11 != nullptr )
  {
    do
    {
      v12 = (_DWORD *)*v11;
      v13 = v11[2] + v11[1] + 16;
      jpeg_free_small(cinfo, object: v11);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v13);
      v11 = v12;
    }
    while ( v12 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406300
// Name: self_destruct
// Source: json
//------------------------------------------------------------------------------
void __cdecl self_destruct(jpeg_common_struct *cinfo)
{
  int v2; // edi
  jpeg_memory_mgr *mem; // esi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  int pool; // [esp+Ch] [ebp-4h]
  jpeg_common_struct *cinfoa; // [esp+18h] [ebp+8h]
  jpeg_common_struct *cinfob; // [esp+18h] [ebp+8h]

  v2 = 1;
  pool = 1;
  do
  {
    mem = cinfo->mem;
    if ( v2 >= 2 )
    {
      cinfo->err->msg_code = 14;
      cinfo->err->msg_parm.i[0] = v2;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v2 == 1 )
    {
      for ( i = mem[1].request_virt_sarray;
            i != nullptr;
            i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
                + 9) )
      {
        if ( *((_BYTE *)i + 34) != 0 )
        {
          v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
          *((_BYTE *)i + 34) = 0;
          v5(a1: cinfo, a2: (char *)i + 40);
        }
      }
      request_virt_barray = mem[1].request_virt_barray;
      for ( mem[1].request_virt_sarray = nullptr;
            request_virt_barray != nullptr;
            request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                  + 9) )
      {
        if ( *((_BYTE *)request_virt_barray + 34) != 0 )
        {
          v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
          *((_BYTE *)request_virt_barray + 34) = 0;
          v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
        }
      }
      v2 = pool;
      mem[1].request_virt_barray = nullptr;
    }
    v8 = *((_DWORD **)&mem[1].alloc_sarray + v2);
    *((_DWORD *)&mem[1].alloc_sarray + v2) = 0;
    if ( v8 != nullptr )
    {
      do
      {
        v9 = (_DWORD *)*v8;
        cinfoa = (jpeg_common_struct *)(v8[2] + v8[1] + 16);
        jpeg_free_small(cinfo, object: v8);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays
                                                                            - (unsigned int)cinfoa);
        v8 = v9;
      }
      while ( v9 != nullptr );
      v2 = pool;
    }
    v10 = *((_DWORD **)&mem[1].alloc_small + v2);
    *((_DWORD *)&mem[1].alloc_small + v2) = 0;
    if ( v10 != nullptr )
    {
      do
      {
        v11 = (_DWORD *)*v10;
        cinfob = (jpeg_common_struct *)(v10[2] + v10[1] + 16);
        jpeg_free_small(cinfo, object: v10);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays
                                                                            - (unsigned int)cinfob);
        v10 = v11;
      }
      while ( v11 != nullptr );
      v2 = pool;
    }
    pool = --v2;
  }
  while ( v2 >= 0 );
  jpeg_free_small(cinfo, object: cinfo->mem);
  cinfo->mem = nullptr;
  jpeg_mem_term();
}

//------------------------------------------------------------------------------
// Address: 0x00406440
// Name: _jinit_memory_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_memory_mgr(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // edi
  int (__cdecl **small)(jpeg_common_struct *, unsigned int, unsigned int); // esi
  const char *v3; // eax
  int max_to_use; // [esp+Ch] [ebp-4h] BYREF

  v1 = cinfo;
  cinfo->mem = nullptr;
  max_to_use = jpeg_mem_init();
  small = (int (__cdecl **)(jpeg_common_struct *, unsigned int, unsigned int))jpeg_get_small(
                                                                                cinfo: v1,
                                                                                sizeofobject: 0x54u);
  if ( small == nullptr )
  {
    jpeg_mem_term();
    v1->err->msg_code = 54;
    v1->err->msg_parm.i[0] = 0;
    ((void (__cdecl *)(jpeg_common_struct *, jpeg_common_struct *))v1->err->error_exit)(a1: v1, a2: v1);
  }
  *small = alloc_small;
  small[1] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_large;
  small[2] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_sarray;
  small[3] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_barray;
  small[4] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_sarray;
  small[5] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_barray;
  small[6] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))realize_virt_arrays;
  small[7] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_sarray;
  small[8] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_barray;
  small[9] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))free_pool;
  small[10] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))self_destruct;
  small[12] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))1000000000;
  small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))max_to_use;
  small[14] = nullptr;
  small[16] = nullptr;
  small[13] = nullptr;
  small[15] = nullptr;
  small[17] = nullptr;
  small[18] = nullptr;
  small[19] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))84;
  v1->mem = (jpeg_memory_mgr *)small;
  v3 = getenv(option: "JPEGMEM");
  if ( v3 != nullptr )
  {
    HIBYTE(cinfo) = 120;
    if ( sscanf(string: v3, format: "%ld%c", &max_to_use, (char *)&cinfo + 3) > 0 )
    {
      if ( HIBYTE(cinfo) == 109 || HIBYTE(cinfo) == 77 )
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000000 * max_to_use);
      else
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000 * max_to_use);
    }
  }
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x0042EB20
// Name: alloc_small
// Source: json
//------------------------------------------------------------------------------
int __cdecl alloc_small(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  small_pool_struct *next; // eax
  unsigned int v6; // ebx
  unsigned int v7; // esi
  unsigned int bytes_used; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  small_pool_struct *prev_hdr_ptr; // [esp+18h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 1;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
  {
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
    sizeofobject = v3;
  }
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  next = mem->small_list[pool_id];
  prev_hdr_ptr = nullptr;
  if ( next != nullptr )
  {
    while ( next->hdr.bytes_left < v3 )
    {
      prev_hdr_ptr = next;
      next = next->hdr.next;
      if ( next == nullptr )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v6 = v3 + 16;
    if ( prev_hdr_ptr != nullptr )
      v7 = extra_pool_slop[pool_id];
    else
      v7 = first_pool_slop[pool_id];
    if ( v7 > 1000000000 - v6 )
      v7 = 1000000000 - v6;
    for ( next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6);
          next == nullptr;
          next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6) )
    {
      v7 >>= 1;
      if ( v7 < 0x32 )
      {
        cinfo->err->msg_code = 54;
        cinfo->err->msg_parm.i[0] = 2;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    mem->total_space_allocated += v7 + v6;
    v3 = sizeofobject;
    next->hdr.next = nullptr;
    next->hdr.bytes_used = 0;
    next->hdr.bytes_left = sizeofobject + v7;
    if ( prev_hdr_ptr != nullptr )
      prev_hdr_ptr->hdr.next = next;
    else
      mem->small_list[pool_id] = next;
  }
  bytes_used = next->hdr.bytes_used;
  next->hdr.bytes_left -= v3;
  next->hdr.bytes_used = v3 + bytes_used;
  return (int)&next[1] + bytes_used;
}

//------------------------------------------------------------------------------
// Address: 0x0042EC70
// Name: alloc_large
// Source: json
//------------------------------------------------------------------------------
large_pool_struct *__cdecl alloc_large(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  large_pool_struct *small; // esi
  large_pool_struct *v6; // edx
  my_memory_mgr *mem; // [esp+14h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  small = (large_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v3 + 16);
  if ( small == nullptr )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem->total_space_allocated += v3 + 16;
  v6 = mem->large_list[pool_id];
  small->hdr.bytes_used = v3;
  small->hdr.next = v6;
  small->hdr.bytes_left = 0;
  mem->large_list[pool_id] = small;
  return small + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042ED40
// Name: alloc_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl alloc_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 **samplesperrow,
        signed int numrows)
{
  unsigned int v5; // edi
  unsigned __int8 **result; // eax
  unsigned int v7; // esi
  large_pool_struct *v8; // eax
  unsigned int i; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  unsigned __int8 **v11; // [esp+20h] [ebp+10h]

  mem = (my_memory_mgr *)cinfo->mem;
  v5 = 0x3B9AC9F0 / (unsigned int)samplesperrow;
  if ( 0x3B9AC9F0 / (unsigned int)samplesperrow == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v5 >= numrows )
    v5 = numrows;
  mem->last_rowsperchunk = v5;
  result = (unsigned __int8 **)alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v7 = 0;
  v11 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v5 >= numrows - v7 )
        v5 = numrows - v7;
      v8 = alloc_large(cinfo, pool_id, sizeofobject: (_DWORD)samplesperrow * v5);
      for ( i = v5; i != 0; --i )
      {
        v11[v7++] = (unsigned __int8 *)v8;
        v8 = (large_pool_struct *)((char *)v8 + (_DWORD)samplesperrow);
      }
    }
    while ( v7 < numrows );
    return v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042EDF0
// Name: alloc_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl alloc_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned int blocksperrow,
        signed int numrows))[64]
{
  unsigned int v4; // edi
  __int16 (**result)[64]; // eax
  unsigned int v6; // esi
  large_pool_struct *v7; // eax
  unsigned int i; // ecx
  __int16 (**mem)[64]; // [esp+Ch] [ebp-4h]
  __int16 (**v10)[64]; // [esp+Ch] [ebp-4h]

  mem = (__int16 (**)[64])cinfo->mem;
  v4 = 0x3B9AC9F0 / (blocksperrow << 7);
  if ( v4 == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v4 >= numrows )
    v4 = numrows;
  mem[20] = (__int16 (*)[64])v4;
  result = (__int16 (**)[64])alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v6 = 0;
  v10 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v4 >= numrows - v6 )
        v4 = numrows - v6;
      v7 = alloc_large(cinfo, pool_id, sizeofobject: (blocksperrow * v4) << 7);
      for ( i = v4; i != 0; --i )
      {
        v10[v6++] = (__int16 (*)[64])v7;
        v7 += 8 * blocksperrow;
      }
    }
    while ( v6 < numrows );
    return v10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042EEA0
// Name: request_virt_sarray
// Source: json
//------------------------------------------------------------------------------
jvirt_sarray_control *__cdecl request_virt_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int samplesperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_sarray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_sarray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->samplesperrow = samplesperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_sarray_control *)mem[1].request_virt_sarray;
  mem[1].request_virt_sarray = (jvirt_sarray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042EF10
// Name: request_virt_barray
// Source: json
//------------------------------------------------------------------------------
jvirt_barray_control *__cdecl request_virt_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int blocksperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_barray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_barray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->blocksperrow = blocksperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_barray_control *)mem[1].request_virt_barray;
  mem[1].request_virt_barray = (jvirt_barray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042EF80
// Name: realize_virt_arrays
// Source: json
//------------------------------------------------------------------------------
void __cdecl realize_virt_arrays(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *p_pub; // edi
  jvirt_sarray_control *(__cdecl *request_virt_sarray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  jvirt_barray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  jvirt_sarray_control *(__cdecl *j)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v11; // edi
  unsigned int v12; // ecx
  jvirt_barray_control *(__cdecl *k)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v14; // edi
  unsigned int v15; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]

  p_pub = cinfo->mem;
  request_virt_sarray = p_pub[1].request_virt_sarray;
  v3 = 0;
  v4 = 0;
  for ( mem = (my_memory_mgr *)p_pub;
        request_virt_sarray != nullptr;
        request_virt_sarray = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_sarray
                              + 9) )
  {
    if ( *(_DWORD *)request_virt_sarray == 0 )
    {
      v5 = *((_DWORD *)request_virt_sarray + 2);
      v3 += v5 * *((_DWORD *)request_virt_sarray + 3);
      v4 += v5 * *((_DWORD *)request_virt_sarray + 1);
    }
  }
  for ( i = p_pub[1].request_virt_barray;
        i != nullptr;
        i = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
            + 9) )
  {
    if ( *(_DWORD *)i == 0 )
    {
      v7 = *((_DWORD *)i + 2);
      v3 += (v7 * *((_DWORD *)i + 3)) << 7;
      v4 += (v7 * *((_DWORD *)i + 1)) << 7;
    }
  }
  if ( v3 > 0 )
  {
    v8 = jpeg_mem_available(cinfo, min_bytes_needed: v3, max_bytes_needed: v4);
    if ( v8 < v4 )
    {
      v9 = v8 / v3;
      if ( v8 / v3 <= 0 )
        v9 = 1;
    }
    else
    {
      v9 = 1000000000;
    }
    for ( j = p_pub[1].request_virt_sarray;
          j != nullptr;
          j = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))j
              + 9) )
    {
      if ( *(_DWORD *)j == 0 )
      {
        v11 = *((_DWORD *)j + 1);
        v12 = *((_DWORD *)j + 3);
        if ( (int)((v11 - 1) / v12 + 1) > v9 )
        {
          *((_DWORD *)j + 4) = v9 * v12;
          jpeg_open_backing_store(cinfo);
          *((_BYTE *)j + 34) = 1;
        }
        else
        {
          *((_DWORD *)j + 4) = v11;
        }
        *(_DWORD *)j = alloc_sarray(
                         cinfo,
                         pool_id: 1u,
                         samplesperrow: *((unsigned __int8 ***)j + 2),
                         numrows: *((_DWORD *)j + 4));
        *((_DWORD *)j + 5) = mem->last_rowsperchunk;
        *((_DWORD *)j + 6) = 0;
        *((_DWORD *)j + 7) = 0;
        *((_BYTE *)j + 33) = 0;
        p_pub = &mem->pub;
      }
    }
    for ( k = p_pub[1].request_virt_barray;
          k != nullptr;
          k = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))k
              + 9) )
    {
      if ( *(_DWORD *)k == 0 )
      {
        v14 = *((_DWORD *)k + 1);
        v15 = *((_DWORD *)k + 3);
        if ( (int)((v14 - 1) / v15 + 1) > v9 )
        {
          *((_DWORD *)k + 4) = v9 * v15;
          jpeg_open_backing_store(cinfo);
          *((_BYTE *)k + 34) = 1;
        }
        else
        {
          *((_DWORD *)k + 4) = v14;
        }
        *(_DWORD *)k = alloc_barray(cinfo, pool_id: 1u, blocksperrow: *((_DWORD *)k + 2), numrows: *((_DWORD *)k + 4));
        *((_DWORD *)k + 5) = mem->last_rowsperchunk;
        *((_DWORD *)k + 6) = 0;
        *((_DWORD *)k + 7) = 0;
        *((_BYTE *)k + 33) = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F120
// Name: do_sarray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_sarray_io(jvirt_sarray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  unsigned int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = ptr->samplesperrow * ptr->cur_start_row;
  bytesperrow = ptr->samplesperrow;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F1C0
// Name: do_barray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_barray_io(jvirt_barray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = (ptr->blocksperrow << 7) * ptr->cur_start_row;
  bytesperrow = ptr->blocksperrow << 7;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F260
// Name: access_virt_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl access_virt_sarray(
        jpeg_common_struct *cinfo,
        jvirt_sarray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable)
{
  unsigned int v5; // ebx
  jpeg_common_struct *v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // eax
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned int i; // ebx
  unsigned int bytesperrow; // [esp+20h] [ebp+14h]

  v5 = num_rows + start_row;
  if ( num_rows + start_row <= ptr->rows_in_array && num_rows <= ptr->maxaccess && ptr->mem_buffer != nullptr )
  {
    v6 = cinfo;
  }
  else
  {
    v6 = cinfo;
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v5 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      v6->err->msg_code = 69;
      v6->err->error_exit(a1: v6);
    }
    if ( ptr->dirty != 0 )
    {
      do_sarray_io(ptr, cinfo: v6, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v5 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_sarray_io(ptr, cinfo: v6, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= v5 )
  {
LABEL_27:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_28:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row >= start_row )
  {
    v10 = ptr->first_undef_row;
  }
  else
  {
    if ( writable != 0 )
    {
      v6->err->msg_code = 22;
      v6->err->error_exit(a1: v6);
    }
    v10 = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = v5;
  if ( ptr->pre_zero != 0 )
  {
    bytesperrow = ptr->samplesperrow;
    v11 = ptr->cur_start_row;
    v12 = v10 - v11;
    for ( i = v5 - v11; v12 < i; ++v12 )
      jzero_far(target: ptr->mem_buffer[v12], bytestozero: bytesperrow);
    goto LABEL_27;
  }
  if ( writable != 0 )
    goto LABEL_28;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x0042F3B0
// Name: access_virt_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl access_virt_barray(
        jpeg_common_struct *cinfo,
        jvirt_barray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable))[64]
{
  unsigned int v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // edi
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned int end_row; // [esp+20h] [ebp+14h]
  unsigned int end_rowa; // [esp+20h] [ebp+14h]

  v6 = num_rows + start_row;
  end_row = v6;
  if ( v6 > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == nullptr )
  {
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v6 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      cinfo->err->msg_code = 69;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( ptr->dirty != 0 )
    {
      do_barray_io(ptr, cinfo, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v6 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_barray_io(ptr, cinfo, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= end_row )
  {
LABEL_25:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_26:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row < start_row )
  {
    if ( writable != 0 )
    {
      cinfo->err->msg_code = 22;
      cinfo->err->error_exit(a1: cinfo);
    }
    first_undef_row = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = end_row;
  if ( ptr->pre_zero != 0 )
  {
    v10 = ptr->cur_start_row;
    v11 = first_undef_row - v10;
    v12 = ptr->blocksperrow << 7;
    for ( end_rowa = end_row - v10; v11 < end_rowa; ++v11 )
      jzero_far(target: ptr->mem_buffer[v11], bytestozero: v12);
    goto LABEL_25;
  }
  if ( writable != 0 )
    goto LABEL_26;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x0042F500
// Name: free_pool
// Source: json
//------------------------------------------------------------------------------
void __cdecl free_pool(jpeg_common_struct *cinfo, unsigned int pool_id)
{
  jpeg_memory_mgr *mem; // esi
  unsigned int v3; // edi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  int v13; // ebx

  mem = cinfo->mem;
  v3 = pool_id;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( pool_id == 1 )
  {
    for ( i = mem[1].request_virt_sarray;
          i != nullptr;
          i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
              + 9) )
    {
      if ( *((_BYTE *)i + 34) != 0 )
      {
        v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
        *((_BYTE *)i + 34) = 0;
        v5(a1: cinfo, a2: (char *)i + 40);
      }
    }
    request_virt_barray = mem[1].request_virt_barray;
    for ( mem[1].request_virt_sarray = nullptr;
          request_virt_barray != nullptr;
          request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                + 9) )
    {
      if ( *((_BYTE *)request_virt_barray + 34) != 0 )
      {
        v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
        *((_BYTE *)request_virt_barray + 34) = 0;
        v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
      }
    }
    v3 = pool_id;
    mem[1].request_virt_barray = nullptr;
  }
  v8 = *((_DWORD **)&mem[1].alloc_sarray + v3);
  *((_DWORD *)&mem[1].alloc_sarray + v3) = 0;
  if ( v8 != nullptr )
  {
    do
    {
      v9 = (_DWORD *)*v8;
      v10 = v8[2] + v8[1] + 16;
      jpeg_free_small(cinfo, object: v8);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v10);
      v8 = v9;
    }
    while ( v9 != nullptr );
    v3 = pool_id;
  }
  v11 = *((_DWORD **)&mem[1].alloc_small + v3);
  *((_DWORD *)&mem[1].alloc_small + v3) = 0;
  if ( v11 != nullptr )
  {
    do
    {
      v12 = (_DWORD *)*v11;
      v13 = v11[2] + v11[1] + 16;
      jpeg_free_small(cinfo, object: v11);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v13);
      v11 = v12;
    }
    while ( v12 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F610
// Name: self_destruct
// Source: json
//------------------------------------------------------------------------------
void __cdecl self_destruct(jpeg_common_struct *cinfo)
{
  int v2; // edi
  jpeg_memory_mgr *mem; // esi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  int pool; // [esp+Ch] [ebp-4h]
  jpeg_common_struct *cinfoa; // [esp+18h] [ebp+8h]
  jpeg_common_struct *cinfob; // [esp+18h] [ebp+8h]

  v2 = 1;
  pool = 1;
  do
  {
    mem = cinfo->mem;
    if ( v2 >= 2 )
    {
      cinfo->err->msg_code = 14;
      cinfo->err->msg_parm.i[0] = v2;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v2 == 1 )
    {
      for ( i = mem[1].request_virt_sarray;
            i != nullptr;
            i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
                + 9) )
      {
        if ( *((_BYTE *)i + 34) != 0 )
        {
          v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
          *((_BYTE *)i + 34) = 0;
          v5(a1: cinfo, a2: (char *)i + 40);
        }
      }
      request_virt_barray = mem[1].request_virt_barray;
      for ( mem[1].request_virt_sarray = nullptr;
            request_virt_barray != nullptr;
            request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                  + 9) )
      {
        if ( *((_BYTE *)request_virt_barray + 34) != 0 )
        {
          v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
          *((_BYTE *)request_virt_barray + 34) = 0;
          v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
        }
      }
      v2 = pool;
      mem[1].request_virt_barray = nullptr;
    }
    v8 = *((_DWORD **)&mem[1].alloc_sarray + v2);
    *((_DWORD *)&mem[1].alloc_sarray + v2) = 0;
    if ( v8 != nullptr )
    {
      do
      {
        v9 = (_DWORD *)*v8;
        cinfoa = (jpeg_common_struct *)(v8[2] + v8[1] + 16);
        jpeg_free_small(cinfo, object: v8);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays
                                                                            - (unsigned int)cinfoa);
        v8 = v9;
      }
      while ( v9 != nullptr );
      v2 = pool;
    }
    v10 = *((_DWORD **)&mem[1].alloc_small + v2);
    *((_DWORD *)&mem[1].alloc_small + v2) = 0;
    if ( v10 != nullptr )
    {
      do
      {
        v11 = (_DWORD *)*v10;
        cinfob = (jpeg_common_struct *)(v10[2] + v10[1] + 16);
        jpeg_free_small(cinfo, object: v10);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays
                                                                            - (unsigned int)cinfob);
        v10 = v11;
      }
      while ( v11 != nullptr );
      v2 = pool;
    }
    pool = --v2;
  }
  while ( v2 >= 0 );
  jpeg_free_small(cinfo, object: cinfo->mem);
  cinfo->mem = nullptr;
  jpeg_mem_term();
}

//------------------------------------------------------------------------------
// Address: 0x0042F750
// Name: _jinit_memory_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_memory_mgr(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // edi
  int (__cdecl **small)(jpeg_common_struct *, unsigned int, unsigned int); // esi
  const char *v3; // eax
  int max_to_use; // [esp+Ch] [ebp-4h] BYREF

  v1 = cinfo;
  cinfo->mem = nullptr;
  max_to_use = jpeg_mem_init();
  small = (int (__cdecl **)(jpeg_common_struct *, unsigned int, unsigned int))jpeg_get_small(
                                                                                cinfo: v1,
                                                                                sizeofobject: 0x54u);
  if ( small == nullptr )
  {
    jpeg_mem_term();
    v1->err->msg_code = 54;
    v1->err->msg_parm.i[0] = 0;
    ((void (__cdecl *)(jpeg_common_struct *, jpeg_common_struct *))v1->err->error_exit)(a1: v1, a2: v1);
  }
  *small = alloc_small;
  small[1] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_large;
  small[2] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_sarray;
  small[3] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_barray;
  small[4] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_sarray;
  small[5] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_barray;
  small[6] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))realize_virt_arrays;
  small[7] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_sarray;
  small[8] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_barray;
  small[9] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))free_pool;
  small[10] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))self_destruct;
  small[12] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))1000000000;
  small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))max_to_use;
  small[14] = nullptr;
  small[16] = nullptr;
  small[13] = nullptr;
  small[15] = nullptr;
  small[17] = nullptr;
  small[18] = nullptr;
  small[19] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))84;
  v1->mem = (jpeg_memory_mgr *)small;
  v3 = getenv(option: "JPEGMEM");
  if ( v3 != nullptr )
  {
    HIBYTE(cinfo) = 120;
    if ( sscanf(string: v3, format: "%ld%c", &max_to_use, (char *)&cinfo + 3) > 0 )
    {
      if ( HIBYTE(cinfo) == 109 || HIBYTE(cinfo) == 77 )
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000000 * max_to_use);
      else
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000 * max_to_use);
    }
  }
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041B920
// Name: alloc_small
// Source: json
//------------------------------------------------------------------------------
int __cdecl alloc_small(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  small_pool_struct *next; // eax
  unsigned int v6; // ebx
  unsigned int v7; // esi
  unsigned int bytes_used; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  small_pool_struct *prev_hdr_ptr; // [esp+18h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 1;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
  {
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
    sizeofobject = v3;
  }
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  next = mem->small_list[pool_id];
  prev_hdr_ptr = nullptr;
  if ( next != nullptr )
  {
    while ( next->hdr.bytes_left < v3 )
    {
      prev_hdr_ptr = next;
      next = next->hdr.next;
      if ( next == nullptr )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v6 = v3 + 16;
    if ( prev_hdr_ptr != nullptr )
      v7 = extra_pool_slop[pool_id];
    else
      v7 = first_pool_slop[pool_id];
    if ( v7 > 1000000000 - v6 )
      v7 = 1000000000 - v6;
    for ( next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6);
          next == nullptr;
          next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6) )
    {
      v7 >>= 1;
      if ( v7 < 0x32 )
      {
        cinfo->err->msg_code = 54;
        cinfo->err->msg_parm.i[0] = 2;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    mem->total_space_allocated += v7 + v6;
    v3 = sizeofobject;
    next->hdr.next = nullptr;
    next->hdr.bytes_used = 0;
    next->hdr.bytes_left = sizeofobject + v7;
    if ( prev_hdr_ptr != nullptr )
      prev_hdr_ptr->hdr.next = next;
    else
      mem->small_list[pool_id] = next;
  }
  bytes_used = next->hdr.bytes_used;
  next->hdr.bytes_left -= v3;
  next->hdr.bytes_used = v3 + bytes_used;
  return (int)&next[1] + bytes_used;
}

//------------------------------------------------------------------------------
// Address: 0x0041BA70
// Name: alloc_large
// Source: json
//------------------------------------------------------------------------------
large_pool_struct *__cdecl alloc_large(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  large_pool_struct *small; // esi
  large_pool_struct *v6; // edx
  my_memory_mgr *mem; // [esp+14h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  small = (large_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v3 + 16);
  if ( small == nullptr )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem->total_space_allocated += v3 + 16;
  v6 = mem->large_list[pool_id];
  small->hdr.bytes_used = v3;
  small->hdr.next = v6;
  small->hdr.bytes_left = 0;
  mem->large_list[pool_id] = small;
  return small + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041BB40
// Name: alloc_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl alloc_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 **samplesperrow,
        signed int numrows)
{
  unsigned int v5; // edi
  unsigned __int8 **result; // eax
  unsigned int v7; // esi
  large_pool_struct *v8; // eax
  unsigned int i; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  unsigned __int8 **v11; // [esp+20h] [ebp+10h]

  mem = (my_memory_mgr *)cinfo->mem;
  v5 = 0x3B9AC9F0 / (unsigned int)samplesperrow;
  if ( 0x3B9AC9F0 / (unsigned int)samplesperrow == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v5 >= numrows )
    v5 = numrows;
  mem->last_rowsperchunk = v5;
  result = (unsigned __int8 **)alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v7 = 0;
  v11 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v5 >= numrows - v7 )
        v5 = numrows - v7;
      v8 = alloc_large(cinfo, pool_id, sizeofobject: (_DWORD)samplesperrow * v5);
      for ( i = v5; i != 0; --i )
      {
        v11[v7++] = (unsigned __int8 *)v8;
        v8 = (large_pool_struct *)((char *)v8 + (_DWORD)samplesperrow);
      }
    }
    while ( v7 < numrows );
    return v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BBF0
// Name: alloc_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl alloc_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned int blocksperrow,
        signed int numrows))[64]
{
  unsigned int v4; // edi
  __int16 (**result)[64]; // eax
  unsigned int v6; // esi
  large_pool_struct *v7; // eax
  unsigned int i; // ecx
  __int16 (**mem)[64]; // [esp+Ch] [ebp-4h]
  __int16 (**v10)[64]; // [esp+Ch] [ebp-4h]

  mem = (__int16 (**)[64])cinfo->mem;
  v4 = 0x3B9AC9F0 / (blocksperrow << 7);
  if ( v4 == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v4 >= numrows )
    v4 = numrows;
  mem[20] = (__int16 (*)[64])v4;
  result = (__int16 (**)[64])alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v6 = 0;
  v10 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v4 >= numrows - v6 )
        v4 = numrows - v6;
      v7 = alloc_large(cinfo, pool_id, sizeofobject: (blocksperrow * v4) << 7);
      for ( i = v4; i != 0; --i )
      {
        v10[v6++] = (__int16 (*)[64])v7;
        v7 += 8 * blocksperrow;
      }
    }
    while ( v6 < numrows );
    return v10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BCA0
// Name: request_virt_sarray
// Source: json
//------------------------------------------------------------------------------
jvirt_sarray_control *__cdecl request_virt_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int samplesperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_sarray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_sarray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->samplesperrow = samplesperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_sarray_control *)mem[1].request_virt_sarray;
  mem[1].request_virt_sarray = (jvirt_sarray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BD10
// Name: request_virt_barray
// Source: json
//------------------------------------------------------------------------------
jvirt_barray_control *__cdecl request_virt_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int blocksperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_barray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_barray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->blocksperrow = blocksperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_barray_control *)mem[1].request_virt_barray;
  mem[1].request_virt_barray = (jvirt_barray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BD80
// Name: realize_virt_arrays
// Source: json
//------------------------------------------------------------------------------
void __cdecl realize_virt_arrays(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *p_pub; // edi
  jvirt_sarray_control *(__cdecl *request_virt_sarray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  jvirt_barray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  jvirt_sarray_control *(__cdecl *j)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v11; // edi
  unsigned int v12; // ecx
  jvirt_barray_control *(__cdecl *k)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v14; // edi
  unsigned int v15; // ecx
  int v16; // [esp-4h] [ebp-14h]
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]

  p_pub = cinfo->mem;
  request_virt_sarray = p_pub[1].request_virt_sarray;
  v3 = 0;
  v4 = 0;
  for ( mem = (my_memory_mgr *)p_pub;
        request_virt_sarray != nullptr;
        request_virt_sarray = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_sarray
                              + 9) )
  {
    if ( *(_DWORD *)request_virt_sarray == 0 )
    {
      v5 = *((_DWORD *)request_virt_sarray + 2);
      v3 += v5 * *((_DWORD *)request_virt_sarray + 3);
      v4 += v5 * *((_DWORD *)request_virt_sarray + 1);
    }
  }
  for ( i = p_pub[1].request_virt_barray;
        i != nullptr;
        i = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
            + 9) )
  {
    if ( *(_DWORD *)i == 0 )
    {
      v7 = *((_DWORD *)i + 2);
      v3 += (v7 * *((_DWORD *)i + 3)) << 7;
      v4 += (v7 * *((_DWORD *)i + 1)) << 7;
    }
  }
  if ( v3 > 0 )
  {
    v8 = jpeg_mem_available(
           cinfo,
           min_bytes_needed: v3,
           max_bytes_needed: v4,
           already_allocated: (int)p_pub[1].realize_virt_arrays);
    if ( v8 < v4 )
    {
      v9 = v8 / v3;
      if ( v8 / v3 <= 0 )
        v9 = 1;
    }
    else
    {
      v9 = 1000000000;
    }
    for ( j = p_pub[1].request_virt_sarray;
          j != nullptr;
          j = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))j
              + 9) )
    {
      if ( *(_DWORD *)j == 0 )
      {
        v11 = *((_DWORD *)j + 1);
        v12 = *((_DWORD *)j + 3);
        if ( (int)((v11 - 1) / v12 + 1) > v9 )
        {
          v16 = v11 * *((_DWORD *)j + 2);
          *((_DWORD *)j + 4) = v9 * v12;
          jpeg_open_backing_store(cinfo, info: (backing_store_struct *)((char *)j + 40), total_bytes_needed: v16);
          *((_BYTE *)j + 34) = 1;
        }
        else
        {
          *((_DWORD *)j + 4) = v11;
        }
        *(_DWORD *)j = alloc_sarray(
                         cinfo,
                         pool_id: 1u,
                         samplesperrow: *((unsigned __int8 ***)j + 2),
                         numrows: *((_DWORD *)j + 4));
        *((_DWORD *)j + 5) = mem->last_rowsperchunk;
        *((_DWORD *)j + 6) = 0;
        *((_DWORD *)j + 7) = 0;
        *((_BYTE *)j + 33) = 0;
        p_pub = &mem->pub;
      }
    }
    for ( k = p_pub[1].request_virt_barray;
          k != nullptr;
          k = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))k
              + 9) )
    {
      if ( *(_DWORD *)k == 0 )
      {
        v14 = *((_DWORD *)k + 1);
        v15 = *((_DWORD *)k + 3);
        if ( (int)((v14 - 1) / v15 + 1) > v9 )
        {
          *((_DWORD *)k + 4) = v9 * v15;
          jpeg_open_backing_store(
            cinfo,
            info: (backing_store_struct *)((char *)k + 40),
            total_bytes_needed: (v14 * *((_DWORD *)k + 2)) << 7);
          *((_BYTE *)k + 34) = 1;
        }
        else
        {
          *((_DWORD *)k + 4) = v14;
        }
        *(_DWORD *)k = alloc_barray(cinfo, pool_id: 1u, blocksperrow: *((_DWORD *)k + 2), numrows: *((_DWORD *)k + 4));
        *((_DWORD *)k + 5) = mem->last_rowsperchunk;
        *((_DWORD *)k + 6) = 0;
        *((_DWORD *)k + 7) = 0;
        *((_BYTE *)k + 33) = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BF20
// Name: do_sarray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_sarray_io(jvirt_sarray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  unsigned int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = ptr->samplesperrow * ptr->cur_start_row;
  bytesperrow = ptr->samplesperrow;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BFC0
// Name: do_barray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_barray_io(jvirt_barray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = (ptr->blocksperrow << 7) * ptr->cur_start_row;
  bytesperrow = ptr->blocksperrow << 7;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C060
// Name: access_virt_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl access_virt_sarray(
        jpeg_common_struct *cinfo,
        jvirt_sarray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable)
{
  unsigned int v5; // ebx
  jpeg_common_struct *v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // eax
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned int i; // ebx
  unsigned int bytesperrow; // [esp+20h] [ebp+14h]

  v5 = num_rows + start_row;
  if ( num_rows + start_row <= ptr->rows_in_array && num_rows <= ptr->maxaccess && ptr->mem_buffer != nullptr )
  {
    v6 = cinfo;
  }
  else
  {
    v6 = cinfo;
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v5 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      v6->err->msg_code = 69;
      v6->err->error_exit(a1: v6);
    }
    if ( ptr->dirty != 0 )
    {
      do_sarray_io(ptr, cinfo: v6, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v5 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_sarray_io(ptr, cinfo: v6, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= v5 )
  {
LABEL_27:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_28:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row >= start_row )
  {
    v10 = ptr->first_undef_row;
  }
  else
  {
    if ( writable != 0 )
    {
      v6->err->msg_code = 22;
      v6->err->error_exit(a1: v6);
    }
    v10 = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = v5;
  if ( ptr->pre_zero != 0 )
  {
    bytesperrow = ptr->samplesperrow;
    v11 = ptr->cur_start_row;
    v12 = v10 - v11;
    for ( i = v5 - v11; v12 < i; ++v12 )
      jzero_far(target: ptr->mem_buffer[v12], bytestozero: bytesperrow);
    goto LABEL_27;
  }
  if ( writable != 0 )
    goto LABEL_28;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x0041C1B0
// Name: access_virt_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl access_virt_barray(
        jpeg_common_struct *cinfo,
        jvirt_barray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable))[64]
{
  unsigned int v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // edi
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned int end_row; // [esp+20h] [ebp+14h]
  unsigned int end_rowa; // [esp+20h] [ebp+14h]

  v6 = num_rows + start_row;
  end_row = v6;
  if ( v6 > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == nullptr )
  {
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v6 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      cinfo->err->msg_code = 69;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( ptr->dirty != 0 )
    {
      do_barray_io(ptr, cinfo, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v6 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_barray_io(ptr, cinfo, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= end_row )
  {
LABEL_25:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_26:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row < start_row )
  {
    if ( writable != 0 )
    {
      cinfo->err->msg_code = 22;
      cinfo->err->error_exit(a1: cinfo);
    }
    first_undef_row = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = end_row;
  if ( ptr->pre_zero != 0 )
  {
    v10 = ptr->cur_start_row;
    v11 = first_undef_row - v10;
    v12 = ptr->blocksperrow << 7;
    for ( end_rowa = end_row - v10; v11 < end_rowa; ++v11 )
      jzero_far(target: ptr->mem_buffer[v11], bytestozero: v12);
    goto LABEL_25;
  }
  if ( writable != 0 )
    goto LABEL_26;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x0041C300
// Name: free_pool
// Source: json
//------------------------------------------------------------------------------
void __cdecl free_pool(jpeg_common_struct *cinfo, unsigned int pool_id)
{
  jpeg_memory_mgr *mem; // esi
  unsigned int v3; // edi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  unsigned int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  unsigned int v13; // ebx

  mem = cinfo->mem;
  v3 = pool_id;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( pool_id == 1 )
  {
    for ( i = mem[1].request_virt_sarray;
          i != nullptr;
          i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
              + 9) )
    {
      if ( *((_BYTE *)i + 34) != 0 )
      {
        v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
        *((_BYTE *)i + 34) = 0;
        v5(a1: cinfo, a2: (char *)i + 40);
      }
    }
    request_virt_barray = mem[1].request_virt_barray;
    for ( mem[1].request_virt_sarray = nullptr;
          request_virt_barray != nullptr;
          request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                + 9) )
    {
      if ( *((_BYTE *)request_virt_barray + 34) != 0 )
      {
        v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
        *((_BYTE *)request_virt_barray + 34) = 0;
        v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
      }
    }
    v3 = pool_id;
    mem[1].request_virt_barray = nullptr;
  }
  v8 = *((_DWORD **)&mem[1].alloc_sarray + v3);
  *((_DWORD *)&mem[1].alloc_sarray + v3) = 0;
  if ( v8 != nullptr )
  {
    do
    {
      v9 = (_DWORD *)*v8;
      v10 = v8[2] + v8[1] + 16;
      jpeg_free_small(cinfo, object: v8, sizeofobject: v10);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v10);
      v8 = v9;
    }
    while ( v9 != nullptr );
    v3 = pool_id;
  }
  v11 = *((_DWORD **)&mem[1].alloc_small + v3);
  *((_DWORD *)&mem[1].alloc_small + v3) = 0;
  if ( v11 != nullptr )
  {
    do
    {
      v12 = (_DWORD *)*v11;
      v13 = v11[2] + v11[1] + 16;
      jpeg_free_small(cinfo, object: v11, sizeofobject: v13);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v13);
      v11 = v12;
    }
    while ( v12 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C410
// Name: self_destruct
// Source: json
//------------------------------------------------------------------------------
void __cdecl self_destruct(jpeg_common_struct *cinfo)
{
  int v2; // edi
  jpeg_memory_mgr *mem; // esi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  int pool; // [esp+Ch] [ebp-4h]
  unsigned int cinfoa; // [esp+18h] [ebp+8h]
  unsigned int cinfob; // [esp+18h] [ebp+8h]

  v2 = 1;
  pool = 1;
  do
  {
    mem = cinfo->mem;
    if ( v2 >= 2 )
    {
      cinfo->err->msg_code = 14;
      cinfo->err->msg_parm.i[0] = v2;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v2 == 1 )
    {
      for ( i = mem[1].request_virt_sarray;
            i != nullptr;
            i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
                + 9) )
      {
        if ( *((_BYTE *)i + 34) != 0 )
        {
          v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
          *((_BYTE *)i + 34) = 0;
          v5(a1: cinfo, a2: (char *)i + 40);
        }
      }
      request_virt_barray = mem[1].request_virt_barray;
      for ( mem[1].request_virt_sarray = nullptr;
            request_virt_barray != nullptr;
            request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                  + 9) )
      {
        if ( *((_BYTE *)request_virt_barray + 34) != 0 )
        {
          v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
          *((_BYTE *)request_virt_barray + 34) = 0;
          v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
        }
      }
      v2 = pool;
      mem[1].request_virt_barray = nullptr;
    }
    v8 = *((_DWORD **)&mem[1].alloc_sarray + v2);
    *((_DWORD *)&mem[1].alloc_sarray + v2) = 0;
    if ( v8 != nullptr )
    {
      do
      {
        v9 = (_DWORD *)*v8;
        cinfoa = v8[2] + v8[1] + 16;
        jpeg_free_small(cinfo, object: v8, sizeofobject: cinfoa);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - cinfoa);
        v8 = v9;
      }
      while ( v9 != nullptr );
      v2 = pool;
    }
    v10 = *((_DWORD **)&mem[1].alloc_small + v2);
    *((_DWORD *)&mem[1].alloc_small + v2) = 0;
    if ( v10 != nullptr )
    {
      do
      {
        v11 = (_DWORD *)*v10;
        cinfob = v10[2] + v10[1] + 16;
        jpeg_free_small(cinfo, object: v10, sizeofobject: cinfob);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - cinfob);
        v10 = v11;
      }
      while ( v11 != nullptr );
      v2 = pool;
    }
    pool = --v2;
  }
  while ( v2 >= 0 );
  jpeg_free_small(cinfo, object: cinfo->mem, sizeofobject: 0x54u);
  cinfo->mem = nullptr;
  jpeg_mem_term(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041C550
// Name: _jinit_memory_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_memory_mgr(jpeg_common_struct *cinfo)
{
  jpeg_common_struct *v1; // edi
  int (__cdecl **small)(jpeg_common_struct *, unsigned int, unsigned int); // esi
  const char *v3; // eax
  jpeg_common_struct *v4; // [esp-4h] [ebp-14h]
  int max_to_use; // [esp+Ch] [ebp-4h] BYREF

  v1 = cinfo;
  v4 = cinfo;
  cinfo->mem = nullptr;
  max_to_use = jpeg_mem_init(cinfo: v4);
  small = (int (__cdecl **)(jpeg_common_struct *, unsigned int, unsigned int))jpeg_get_small(
                                                                                cinfo: v1,
                                                                                sizeofobject: 0x54u);
  if ( small == nullptr )
  {
    jpeg_mem_term(cinfo: v1);
    v1->err->msg_code = 54;
    v1->err->msg_parm.i[0] = 0;
    v1->err->error_exit(a1: v1);
  }
  *small = alloc_small;
  small[1] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_large;
  small[2] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_sarray;
  small[3] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_barray;
  small[4] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_sarray;
  small[5] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_barray;
  small[6] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))realize_virt_arrays;
  small[7] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_sarray;
  small[8] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_barray;
  small[9] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))free_pool;
  small[10] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))self_destruct;
  small[12] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))1000000000;
  small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))max_to_use;
  small[14] = nullptr;
  small[16] = nullptr;
  small[13] = nullptr;
  small[15] = nullptr;
  small[17] = nullptr;
  small[18] = nullptr;
  small[19] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))84;
  v1->mem = (jpeg_memory_mgr *)small;
  v3 = getenv(option: "JPEGMEM");
  if ( v3 != nullptr )
  {
    HIBYTE(cinfo) = 120;
    if ( sscanf(string: v3, format: "%ld%c", &max_to_use, (char *)&cinfo + 3) > 0 )
    {
      if ( HIBYTE(cinfo) == 109 || HIBYTE(cinfo) == 77 )
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000000 * max_to_use);
      else
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000 * max_to_use);
    }
  }
}

} // namespace vxconsole_ps3

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10274680
// Name: alloc_small
// Source: json
//------------------------------------------------------------------------------
int __cdecl alloc_small(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  small_pool_struct *next; // eax
  unsigned int v6; // ebx
  unsigned int v7; // esi
  unsigned int bytes_used; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  small_pool_struct *prev_hdr_ptr; // [esp+18h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 1;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
  {
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
    sizeofobject = v3;
  }
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  next = mem->small_list[pool_id];
  prev_hdr_ptr = nullptr;
  if ( next != nullptr )
  {
    while ( next->hdr.bytes_left < v3 )
    {
      prev_hdr_ptr = next;
      next = next->hdr.next;
      if ( next == nullptr )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v6 = v3 + 16;
    if ( prev_hdr_ptr != nullptr )
      v7 = extra_pool_slop[pool_id];
    else
      v7 = first_pool_slop[pool_id];
    if ( v7 > 1000000000 - v6 )
      v7 = 1000000000 - v6;
    for ( next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6);
          next == nullptr;
          next = (small_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v7 + v6) )
    {
      v7 >>= 1;
      if ( v7 < 0x32 )
      {
        cinfo->err->msg_code = 54;
        cinfo->err->msg_parm.i[0] = 2;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    mem->total_space_allocated += v7 + v6;
    v3 = sizeofobject;
    next->hdr.next = nullptr;
    next->hdr.bytes_used = 0;
    next->hdr.bytes_left = sizeofobject + v7;
    if ( prev_hdr_ptr != nullptr )
      prev_hdr_ptr->hdr.next = next;
    else
      mem->small_list[pool_id] = next;
  }
  bytes_used = next->hdr.bytes_used;
  next->hdr.bytes_left -= v3;
  next->hdr.bytes_used = v3 + bytes_used;
  return (int)&next[1] + bytes_used;
}

//------------------------------------------------------------------------------
// Address: 0x102747D0
// Name: alloc_large
// Source: json
//------------------------------------------------------------------------------
large_pool_struct *__cdecl alloc_large(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  unsigned int v3; // ebx
  large_pool_struct *small; // esi
  large_pool_struct *v6; // edx
  my_memory_mgr *mem; // [esp+14h] [ebp+8h]

  v3 = sizeofobject;
  mem = (my_memory_mgr *)cinfo->mem;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (sizeofobject & 7) != 0 )
    v3 = 8 - (sizeofobject & 7) + sizeofobject;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  small = (large_pool_struct *)jpeg_get_small(cinfo, sizeofobject: v3 + 16);
  if ( small == nullptr )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  mem->total_space_allocated += v3 + 16;
  v6 = mem->large_list[pool_id];
  small->hdr.bytes_used = v3;
  small->hdr.next = v6;
  small->hdr.bytes_left = 0;
  mem->large_list[pool_id] = small;
  return small + 1;
}

//------------------------------------------------------------------------------
// Address: 0x102748A0
// Name: alloc_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl alloc_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 **samplesperrow,
        signed int numrows)
{
  unsigned int v5; // edi
  unsigned __int8 **result; // eax
  unsigned int v7; // esi
  large_pool_struct *v8; // eax
  unsigned int i; // ecx
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]
  unsigned __int8 **v11; // [esp+20h] [ebp+10h]

  mem = (my_memory_mgr *)cinfo->mem;
  v5 = 0x3B9AC9F0 / (unsigned int)samplesperrow;
  if ( 0x3B9AC9F0 / (unsigned int)samplesperrow == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v5 >= numrows )
    v5 = numrows;
  mem->last_rowsperchunk = v5;
  result = (unsigned __int8 **)alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v7 = 0;
  v11 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v5 >= numrows - v7 )
        v5 = numrows - v7;
      v8 = alloc_large(cinfo, pool_id, sizeofobject: (_DWORD)samplesperrow * v5);
      for ( i = v5; i != 0; --i )
      {
        v11[v7++] = (unsigned __int8 *)v8;
        v8 = (large_pool_struct *)((char *)v8 + (_DWORD)samplesperrow);
      }
    }
    while ( v7 < numrows );
    return v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10274950
// Name: alloc_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl alloc_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned int blocksperrow,
        signed int numrows))[64]
{
  unsigned int v4; // edi
  __int16 (**result)[64]; // eax
  unsigned int v6; // esi
  large_pool_struct *v7; // eax
  unsigned int i; // ecx
  __int16 (**mem)[64]; // [esp+Ch] [ebp-4h]
  __int16 (**v10)[64]; // [esp+Ch] [ebp-4h]

  mem = (__int16 (**)[64])cinfo->mem;
  v4 = 0x3B9AC9F0 / (blocksperrow << 7);
  if ( v4 == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v4 >= numrows )
    v4 = numrows;
  mem[20] = (__int16 (*)[64])v4;
  result = (__int16 (**)[64])alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v6 = 0;
  v10 = result;
  if ( numrows != 0 )
  {
    do
    {
      if ( v4 >= numrows - v6 )
        v4 = numrows - v6;
      v7 = alloc_large(cinfo, pool_id, sizeofobject: (blocksperrow * v4) << 7);
      for ( i = v4; i != 0; --i )
      {
        v10[v6++] = (__int16 (*)[64])v7;
        v7 += 8 * blocksperrow;
      }
    }
    while ( v6 < numrows );
    return v10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10274A00
// Name: request_virt_sarray
// Source: json
//------------------------------------------------------------------------------
jvirt_sarray_control *__cdecl request_virt_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int samplesperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_sarray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_sarray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->samplesperrow = samplesperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_sarray_control *)mem[1].request_virt_sarray;
  mem[1].request_virt_sarray = (jvirt_sarray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10274A70
// Name: request_virt_barray
// Source: json
//------------------------------------------------------------------------------
jvirt_barray_control *__cdecl request_virt_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int blocksperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // edi
  jvirt_barray_control *result; // eax

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_barray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->blocksperrow = blocksperrow;
  result->mem_buffer = nullptr;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_barray_control *)mem[1].request_virt_barray;
  mem[1].request_virt_barray = (jvirt_barray_control *(__cdecl *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10274AE0
// Name: realize_virt_arrays
// Source: json
//------------------------------------------------------------------------------
void __cdecl realize_virt_arrays(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *p_pub; // edi
  jvirt_sarray_control *(__cdecl *request_virt_sarray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  jvirt_barray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  jvirt_sarray_control *(__cdecl *j)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v11; // edi
  unsigned int v12; // ecx
  jvirt_barray_control *(__cdecl *k)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // esi
  int v14; // edi
  unsigned int v15; // ecx
  int v16; // [esp-4h] [ebp-14h]
  my_memory_mgr *mem; // [esp+Ch] [ebp-4h]

  p_pub = cinfo->mem;
  request_virt_sarray = p_pub[1].request_virt_sarray;
  v3 = 0;
  v4 = 0;
  for ( mem = (my_memory_mgr *)p_pub;
        request_virt_sarray != nullptr;
        request_virt_sarray = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_sarray
                              + 9) )
  {
    if ( *(_DWORD *)request_virt_sarray == 0 )
    {
      v5 = *((_DWORD *)request_virt_sarray + 2);
      v3 += v5 * *((_DWORD *)request_virt_sarray + 3);
      v4 += v5 * *((_DWORD *)request_virt_sarray + 1);
    }
  }
  for ( i = p_pub[1].request_virt_barray;
        i != nullptr;
        i = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
            + 9) )
  {
    if ( *(_DWORD *)i == 0 )
    {
      v7 = *((_DWORD *)i + 2);
      v3 += (v7 * *((_DWORD *)i + 3)) << 7;
      v4 += (v7 * *((_DWORD *)i + 1)) << 7;
    }
  }
  if ( v3 > 0 )
  {
    v8 = jpeg_mem_available(
           cinfo,
           min_bytes_needed: v3,
           max_bytes_needed: v4,
           already_allocated: (int)p_pub[1].realize_virt_arrays);
    if ( v8 < v4 )
    {
      v9 = v8 / v3;
      if ( v8 / v3 <= 0 )
        v9 = 1;
    }
    else
    {
      v9 = 1000000000;
    }
    for ( j = p_pub[1].request_virt_sarray;
          j != nullptr;
          j = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))j
              + 9) )
    {
      if ( *(_DWORD *)j == 0 )
      {
        v11 = *((_DWORD *)j + 1);
        v12 = *((_DWORD *)j + 3);
        if ( (int)((v11 - 1) / v12 + 1) > v9 )
        {
          v16 = v11 * *((_DWORD *)j + 2);
          *((_DWORD *)j + 4) = v9 * v12;
          jpeg_open_backing_store(cinfo, info: (backing_store_struct *)((char *)j + 40), total_bytes_needed: v16);
          *((_BYTE *)j + 34) = 1;
        }
        else
        {
          *((_DWORD *)j + 4) = v11;
        }
        *(_DWORD *)j = alloc_sarray(
                         cinfo,
                         pool_id: 1u,
                         samplesperrow: *((unsigned __int8 ***)j + 2),
                         numrows: *((_DWORD *)j + 4));
        *((_DWORD *)j + 5) = mem->last_rowsperchunk;
        *((_DWORD *)j + 6) = 0;
        *((_DWORD *)j + 7) = 0;
        *((_BYTE *)j + 33) = 0;
        p_pub = &mem->pub;
      }
    }
    for ( k = p_pub[1].request_virt_barray;
          k != nullptr;
          k = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))k
              + 9) )
    {
      if ( *(_DWORD *)k == 0 )
      {
        v14 = *((_DWORD *)k + 1);
        v15 = *((_DWORD *)k + 3);
        if ( (int)((v14 - 1) / v15 + 1) > v9 )
        {
          *((_DWORD *)k + 4) = v9 * v15;
          jpeg_open_backing_store(
            cinfo,
            info: (backing_store_struct *)((char *)k + 40),
            total_bytes_needed: (v14 * *((_DWORD *)k + 2)) << 7);
          *((_BYTE *)k + 34) = 1;
        }
        else
        {
          *((_DWORD *)k + 4) = v14;
        }
        *(_DWORD *)k = alloc_barray(cinfo, pool_id: 1u, blocksperrow: *((_DWORD *)k + 2), numrows: *((_DWORD *)k + 4));
        *((_DWORD *)k + 5) = mem->last_rowsperchunk;
        *((_DWORD *)k + 6) = 0;
        *((_DWORD *)k + 7) = 0;
        *((_BYTE *)k + 33) = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10274C80
// Name: do_sarray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_sarray_io(jvirt_sarray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  unsigned int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = ptr->samplesperrow * ptr->cur_start_row;
  bytesperrow = ptr->samplesperrow;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10274D20
// Name: do_barray_io
// Source: json
//------------------------------------------------------------------------------
void __usercall do_barray_io(jvirt_barray_control *ptr@<esi>, jpeg_common_struct *cinfo, unsigned __int8 writing)
{
  int v3; // edx
  signed int rows_in_mem; // eax
  signed int v5; // edi
  signed int rowsperchunk; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  int v9; // [esp-8h] [ebp-14h]
  int bytesperrow; // [esp+4h] [ebp-8h]
  int file_offset; // [esp+8h] [ebp-4h]

  v3 = (ptr->blocksperrow << 7) * ptr->cur_start_row;
  bytesperrow = ptr->blocksperrow << 7;
  rows_in_mem = ptr->rows_in_mem;
  v5 = 0;
  file_offset = v3;
  if ( rows_in_mem > 0 )
  {
    while ( 1 )
    {
      rowsperchunk = rows_in_mem - v5;
      if ( (signed int)ptr->rowsperchunk < rowsperchunk )
        rowsperchunk = ptr->rowsperchunk;
      v7 = v5 + ptr->cur_start_row;
      if ( rowsperchunk >= (int)(ptr->first_undef_row - v7) )
        rowsperchunk = ptr->first_undef_row - v7;
      if ( rowsperchunk >= (int)(ptr->rows_in_array - v7) )
        rowsperchunk = ptr->rows_in_array - v7;
      if ( rowsperchunk <= 0 )
        break;
      v8 = bytesperrow * rowsperchunk;
      v9 = bytesperrow * rowsperchunk;
      if ( writing != 0 )
        ptr->b_s_info.write_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      else
        ptr->b_s_info.read_backing_store(a1: cinfo, a2: &ptr->b_s_info, a3: ptr->mem_buffer[v5], a4: v3, a5: v9);
      v5 += ptr->rowsperchunk;
      rows_in_mem = ptr->rows_in_mem;
      file_offset += v8;
      if ( v5 >= rows_in_mem )
        break;
      v3 = file_offset;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10274DC0
// Name: access_virt_sarray
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl access_virt_sarray(
        jpeg_common_struct *cinfo,
        jvirt_sarray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable)
{
  unsigned int v5; // ebx
  jpeg_common_struct *v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // eax
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned int i; // ebx
  unsigned int bytesperrow; // [esp+20h] [ebp+14h]

  v5 = num_rows + start_row;
  if ( num_rows + start_row <= ptr->rows_in_array && num_rows <= ptr->maxaccess && ptr->mem_buffer != nullptr )
  {
    v6 = cinfo;
  }
  else
  {
    v6 = cinfo;
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v5 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      v6->err->msg_code = 69;
      v6->err->error_exit(a1: v6);
    }
    if ( ptr->dirty != 0 )
    {
      do_sarray_io(cinfo: v6, ptr, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v5 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_sarray_io(cinfo: v6, ptr, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= v5 )
  {
LABEL_27:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_28:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row >= start_row )
  {
    v10 = ptr->first_undef_row;
  }
  else
  {
    if ( writable != 0 )
    {
      v6->err->msg_code = 22;
      v6->err->error_exit(a1: v6);
    }
    v10 = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = v5;
  if ( ptr->pre_zero != 0 )
  {
    bytesperrow = ptr->samplesperrow;
    v11 = ptr->cur_start_row;
    v12 = v10 - v11;
    for ( i = v5 - v11; v12 < i; ++v12 )
      jzero_far(target: ptr->mem_buffer[v12], bytestozero: bytesperrow);
    goto LABEL_27;
  }
  if ( writable != 0 )
    goto LABEL_28;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x10274F10
// Name: access_virt_barray
// Source: json
//------------------------------------------------------------------------------
__int16 (**__cdecl access_virt_barray(
        jpeg_common_struct *cinfo,
        jvirt_barray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable))[64]
{
  unsigned int v6; // edi
  unsigned int cur_start_row; // eax
  signed int v8; // eax
  unsigned int first_undef_row; // edi
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned int end_row; // [esp+20h] [ebp+14h]
  unsigned int end_rowa; // [esp+20h] [ebp+14h]

  v6 = num_rows + start_row;
  end_row = v6;
  if ( v6 > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == nullptr )
  {
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v6 > cur_start_row + ptr->rows_in_mem )
  {
    if ( ptr->b_s_open == 0 )
    {
      cinfo->err->msg_code = 69;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( ptr->dirty != 0 )
    {
      do_barray_io(cinfo, ptr, writing: 1u);
      ptr->dirty = 0;
    }
    v8 = start_row;
    if ( start_row <= ptr->cur_start_row )
    {
      v8 = v6 - ptr->rows_in_mem;
      if ( v8 < 0 )
        v8 = 0;
    }
    ptr->cur_start_row = v8;
    do_barray_io(cinfo, ptr, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row >= end_row )
  {
LABEL_25:
    if ( writable == 0 )
      return &ptr->mem_buffer[start_row - ptr->cur_start_row];
LABEL_26:
    ptr->dirty = 1;
    return &ptr->mem_buffer[start_row - ptr->cur_start_row];
  }
  if ( first_undef_row < start_row )
  {
    if ( writable != 0 )
    {
      cinfo->err->msg_code = 22;
      cinfo->err->error_exit(a1: cinfo);
    }
    first_undef_row = start_row;
  }
  if ( writable != 0 )
    ptr->first_undef_row = end_row;
  if ( ptr->pre_zero != 0 )
  {
    v10 = ptr->cur_start_row;
    v11 = first_undef_row - v10;
    v12 = ptr->blocksperrow << 7;
    for ( end_rowa = end_row - v10; v11 < end_rowa; ++v11 )
      jzero_far(target: ptr->mem_buffer[v11], bytestozero: v12);
    goto LABEL_25;
  }
  if ( writable != 0 )
    goto LABEL_26;
  cinfo->err->msg_code = 22;
  cinfo->err->error_exit(a1: cinfo);
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}

//------------------------------------------------------------------------------
// Address: 0x10275060
// Name: free_pool
// Source: json
//------------------------------------------------------------------------------
void __cdecl free_pool(jpeg_common_struct *cinfo, unsigned int pool_id)
{
  jpeg_memory_mgr *mem; // esi
  unsigned int v3; // edi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  unsigned int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  unsigned int v13; // ebx

  mem = cinfo->mem;
  v3 = pool_id;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( pool_id == 1 )
  {
    for ( i = mem[1].request_virt_sarray;
          i != nullptr;
          i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
              + 9) )
    {
      if ( *((_BYTE *)i + 34) != 0 )
      {
        v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
        *((_BYTE *)i + 34) = 0;
        v5(a1: cinfo, a2: (char *)i + 40);
      }
    }
    request_virt_barray = mem[1].request_virt_barray;
    for ( mem[1].request_virt_sarray = nullptr;
          request_virt_barray != nullptr;
          request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                + 9) )
    {
      if ( *((_BYTE *)request_virt_barray + 34) != 0 )
      {
        v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
        *((_BYTE *)request_virt_barray + 34) = 0;
        v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
      }
    }
    v3 = pool_id;
    mem[1].request_virt_barray = nullptr;
  }
  v8 = *((_DWORD **)&mem[1].alloc_sarray + v3);
  *((_DWORD *)&mem[1].alloc_sarray + v3) = 0;
  if ( v8 != nullptr )
  {
    do
    {
      v9 = (_DWORD *)*v8;
      v10 = v8[2] + v8[1] + 16;
      jpeg_free_small(cinfo, object: v8, sizeofobject: v10);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v10);
      v8 = v9;
    }
    while ( v9 != nullptr );
    v3 = pool_id;
  }
  v11 = *((_DWORD **)&mem[1].alloc_small + v3);
  *((_DWORD *)&mem[1].alloc_small + v3) = 0;
  if ( v11 != nullptr )
  {
    do
    {
      v12 = (_DWORD *)*v11;
      v13 = v11[2] + v11[1] + 16;
      jpeg_free_small(cinfo, object: v11, sizeofobject: v13);
      mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v13);
      v11 = v12;
    }
    while ( v12 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275170
// Name: self_destruct
// Source: json
//------------------------------------------------------------------------------
void __cdecl self_destruct(jpeg_common_struct *cinfo)
{
  int v2; // edi
  jpeg_memory_mgr *mem; // esi
  jvirt_sarray_control *(__cdecl *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v5)(jpeg_common_struct *, char *); // edx
  jvirt_barray_control *(__cdecl *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // edi
  void (__cdecl *v7)(jpeg_common_struct *, char *); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  vgui::PropertyPage *v12; // ecx
  int pool; // [esp+Ch] [ebp-4h]
  unsigned int cinfoa; // [esp+18h] [ebp+8h]
  unsigned int cinfob; // [esp+18h] [ebp+8h]

  v2 = 1;
  pool = 1;
  do
  {
    mem = cinfo->mem;
    if ( v2 >= 2 )
    {
      cinfo->err->msg_code = 14;
      cinfo->err->msg_parm.i[0] = v2;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v2 == 1 )
    {
      for ( i = mem[1].request_virt_sarray;
            i != nullptr;
            i = *((jvirt_sarray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
                + 9) )
      {
        if ( *((_BYTE *)i + 34) != 0 )
        {
          v5 = *((void (__cdecl **)(jpeg_common_struct *, char *))i + 12);
          *((_BYTE *)i + 34) = 0;
          v5(a1: cinfo, a2: (char *)i + 40);
        }
      }
      request_virt_barray = mem[1].request_virt_barray;
      for ( mem[1].request_virt_sarray = nullptr;
            request_virt_barray != nullptr;
            request_virt_barray = *((jvirt_barray_control *(__cdecl **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                  + 9) )
      {
        if ( *((_BYTE *)request_virt_barray + 34) != 0 )
        {
          v7 = *((void (__cdecl **)(jpeg_common_struct *, char *))request_virt_barray + 12);
          *((_BYTE *)request_virt_barray + 34) = 0;
          v7(a1: cinfo, a2: (char *)request_virt_barray + 40);
        }
      }
      v2 = pool;
      mem[1].request_virt_barray = nullptr;
    }
    v8 = *((_DWORD **)&mem[1].alloc_sarray + v2);
    *((_DWORD *)&mem[1].alloc_sarray + v2) = 0;
    if ( v8 != nullptr )
    {
      do
      {
        v9 = (_DWORD *)*v8;
        cinfoa = v8[2] + v8[1] + 16;
        jpeg_free_small(cinfo, object: v8, sizeofobject: cinfoa);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - cinfoa);
        v8 = v9;
      }
      while ( v9 != nullptr );
      v2 = pool;
    }
    v10 = *((_DWORD **)&mem[1].alloc_small + v2);
    *((_DWORD *)&mem[1].alloc_small + v2) = 0;
    if ( v10 != nullptr )
    {
      do
      {
        v11 = (_DWORD *)*v10;
        cinfob = v10[2] + v10[1] + 16;
        jpeg_free_small(cinfo, object: v10, sizeofobject: cinfob);
        mem[1].realize_virt_arrays = (void (__cdecl *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - cinfob);
        v10 = v11;
      }
      while ( v11 != nullptr );
      v2 = pool;
    }
    pool = --v2;
  }
  while ( v2 >= 0 );
  jpeg_free_small(cinfo, object: cinfo->mem, sizeofobject: 0x54u);
  cinfo->mem = nullptr;
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x102752B0
// Name: _jinit_memory_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_memory_mgr(jpeg_common_struct *cinfo)
{
  vgui::CTreeViewListControl *v1; // ecx
  jpeg_common_struct *v2; // edi
  vgui::PropertyPage *v3; // ecx
  int (__cdecl **small)(jpeg_common_struct *, unsigned int, unsigned int); // esi
  char *v5; // eax
  int max_to_use; // [esp+Ch] [ebp-4h] BYREF

  v2 = cinfo;
  cinfo->mem = nullptr;
  max_to_use = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v1);
  small = (int (__cdecl **)(jpeg_common_struct *, unsigned int, unsigned int))jpeg_get_small(
                                                                                cinfo: v2,
                                                                                sizeofobject: 0x54u);
  if ( small == nullptr )
  {
    C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v3);
    v2->err->msg_code = 54;
    v2->err->msg_parm.i[0] = 0;
    ((void (__cdecl *)(jpeg_common_struct *, jpeg_common_struct *))v2->err->error_exit)(a1: v2, a2: v2);
  }
  *small = alloc_small;
  small[1] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_large;
  small[2] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_sarray;
  small[3] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))alloc_barray;
  small[4] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_sarray;
  small[5] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))request_virt_barray;
  small[6] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))realize_virt_arrays;
  small[7] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_sarray;
  small[8] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))access_virt_barray;
  small[9] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))free_pool;
  small[10] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))self_destruct;
  small[12] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))1000000000;
  small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))max_to_use;
  small[14] = nullptr;
  small[16] = nullptr;
  small[13] = nullptr;
  small[15] = nullptr;
  small[17] = nullptr;
  small[18] = nullptr;
  small[19] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))84;
  v2->mem = (jpeg_memory_mgr *)small;
  v5 = getenv(option: "JPEGMEM");
  if ( v5 != nullptr )
  {
    HIBYTE(cinfo) = 120;
    if ( sscanf(string: v5, format: "%ld%c", &max_to_use, (char *)&cinfo + 3) > 0 )
    {
      if ( HIBYTE(cinfo) == 109 || HIBYTE(cinfo) == 77 )
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000000 * max_to_use);
      else
        small[11] = (int (__cdecl *)(jpeg_common_struct *, unsigned int, unsigned int))(1000 * max_to_use);
    }
  }
}

} // namespace client
