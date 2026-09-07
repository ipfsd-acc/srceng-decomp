// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jutils.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x102532D0
// Name: _jdiv_round_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jdiv_round_up(int a, int b)
{
  return (a + b - 1) / b;
}

//------------------------------------------------------------------------------
// Address: 0x102532F0
// Name: _jround_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jround_up(int a, int b)
{
  return a + b - 1 - (a + b - 1) % b;
}

//------------------------------------------------------------------------------
// Address: 0x10253310
// Name: _jcopy_sample_rows
// Source: json
//------------------------------------------------------------------------------
void __cdecl jcopy_sample_rows(
        unsigned __int8 **input_array,
        int source_row,
        unsigned __int8 **output_array,
        int dest_row,
        int num_rows,
        unsigned int num_cols)
{
  int v6; // ebx
  unsigned __int8 **v7; // esi
  unsigned __int8 **i; // edi
  unsigned __int8 *v9; // [esp-Ch] [ebp-18h]
  unsigned __int8 *v10; // [esp-8h] [ebp-14h]

  v6 = num_rows;
  v7 = &input_array[source_row];
  for ( i = &output_array[dest_row]; v6 > 0; --v6 )
  {
    v10 = *v7;
    v9 = *i;
    ++v7;
    ++i;
    memcpy(dst: v9, src: v10, count: num_cols);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253360
// Name: _jzero_far
// Source: json
//------------------------------------------------------------------------------
void __cdecl jzero_far(unsigned __int8 *target, unsigned int bytestozero)
{
  memset(dst: target, value: 0, count: bytestozero);
}

// ============================================================
// Overlay from FileSystemOpenDialog (Missing functions)
// ============================================================
namespace FileSystemOpenDialog {

//------------------------------------------------------------------------------
// Address: 0x1000CE80
// Name: _jdiv_round_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jdiv_round_up(int a, int b)
{
  return (a + b - 1) / b;
}

//------------------------------------------------------------------------------
// Address: 0x1000CEA0
// Name: _jround_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jround_up(int a, int b)
{
  return a + b - 1 - (a + b - 1) % b;
}

//------------------------------------------------------------------------------
// Address: 0x1000CEC0
// Name: _jcopy_sample_rows
// Source: json
//------------------------------------------------------------------------------
void __cdecl jcopy_sample_rows(
        unsigned __int8 **input_array,
        int source_row,
        unsigned __int8 **output_array,
        int dest_row,
        int num_rows,
        unsigned int num_cols)
{
  int v6; // ebx
  unsigned __int8 **v7; // esi
  unsigned __int8 **i; // edi
  unsigned __int8 *v9; // [esp-Ch] [ebp-18h]
  unsigned __int8 *v10; // [esp-8h] [ebp-14h]

  v6 = num_rows;
  v7 = &input_array[source_row];
  for ( i = &output_array[dest_row]; v6 > 0; --v6 )
  {
    v10 = *v7;
    v9 = *i;
    ++v7;
    ++i;
    memcpy(dst: v9, src: v10, count: num_cols);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CF10
// Name: _jcopy_block_row
// Source: json
//------------------------------------------------------------------------------
void __cdecl jcopy_block_row(__int16 (*input_row)[64], __int16 (*output_row)[64], unsigned int num_blocks)
{
  memcpy(dst: (unsigned __int8 *)output_row, src: (unsigned __int8 *)input_row, count: num_blocks << 7);
}

//------------------------------------------------------------------------------
// Address: 0x1000CF30
// Name: _jzero_far
// Source: json
//------------------------------------------------------------------------------
void __cdecl jzero_far(void *target, unsigned int bytestozero)
{
  memset(dst: (int)target, value: nullptr, count: bytestozero);
}

} // namespace FileSystemOpenDialog

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10253300
// Name: _jdiv_round_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jdiv_round_up(int a, int b)
{
  return (a + b - 1) / b;
}

//------------------------------------------------------------------------------
// Address: 0x10253320
// Name: _jround_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jround_up(int a, int b)
{
  return a + b - 1 - (a + b - 1) % b;
}

//------------------------------------------------------------------------------
// Address: 0x10253340
// Name: _jcopy_sample_rows
// Source: json
//------------------------------------------------------------------------------
void __cdecl jcopy_sample_rows(
        unsigned __int8 **input_array,
        int source_row,
        unsigned __int8 **output_array,
        int dest_row,
        int num_rows,
        unsigned int num_cols)
{
  int v6; // ebx
  unsigned __int8 **v7; // esi
  unsigned __int8 **i; // edi
  unsigned __int8 *v9; // [esp-Ch] [ebp-18h]
  unsigned __int8 *v10; // [esp-8h] [ebp-14h]

  v6 = num_rows;
  v7 = &input_array[source_row];
  for ( i = &output_array[dest_row]; v6 > 0; --v6 )
  {
    v10 = *v7;
    v9 = *i;
    ++v7;
    ++i;
    memcpy(dst: v9, src: v10, count: num_cols);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253390
// Name: _jzero_far
// Source: json
//------------------------------------------------------------------------------
void __cdecl jzero_far(unsigned __int8 *target, unsigned int bytestozero)
{
  memset(dst: target, value: 0, count: bytestozero);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x00407820
// Name: _jdiv_round_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jdiv_round_up(int a, int b)
{
  return (a + b - 1) / b;
}

//------------------------------------------------------------------------------
// Address: 0x00407840
// Name: _jround_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jround_up(int a, int b)
{
  return a + b - 1 - (a + b - 1) % b;
}

//------------------------------------------------------------------------------
// Address: 0x00407860
// Name: _jcopy_sample_rows
// Source: json
//------------------------------------------------------------------------------
void __cdecl jcopy_sample_rows(
        unsigned __int8 **input_array,
        int source_row,
        unsigned __int8 **output_array,
        int dest_row,
        int num_rows,
        unsigned int num_cols)
{
  int v6; // ebx
  unsigned __int8 **v7; // esi
  unsigned __int8 **i; // edi
  unsigned __int8 *v9; // [esp-Ch] [ebp-18h]
  unsigned __int8 *v10; // [esp-8h] [ebp-14h]

  v6 = num_rows;
  v7 = &input_array[source_row];
  for ( i = &output_array[dest_row]; v6 > 0; --v6 )
  {
    v10 = *v7;
    v9 = *i;
    ++v7;
    ++i;
    memcpy(dst: v9, src: v10, count: num_cols);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004078B0
// Name: _jzero_far
// Source: json
//------------------------------------------------------------------------------
void __cdecl jzero_far(unsigned __int8 *target, unsigned int bytestozero)
{
  memset(dst: target, value: 0, count: bytestozero);
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00430B30
// Name: _jdiv_round_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jdiv_round_up(int a, int b)
{
  return (a + b - 1) / b;
}

//------------------------------------------------------------------------------
// Address: 0x00430B50
// Name: _jround_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jround_up(int a, int b)
{
  return a + b - 1 - (a + b - 1) % b;
}

//------------------------------------------------------------------------------
// Address: 0x00430B70
// Name: _jcopy_sample_rows
// Source: json
//------------------------------------------------------------------------------
void __cdecl jcopy_sample_rows(
        unsigned __int8 **input_array,
        int source_row,
        unsigned __int8 **output_array,
        int dest_row,
        int num_rows,
        unsigned int num_cols)
{
  int v6; // ebx
  unsigned __int8 **v7; // esi
  unsigned __int8 **i; // edi
  unsigned __int8 *v9; // [esp-Ch] [ebp-18h]
  unsigned __int8 *v10; // [esp-8h] [ebp-14h]

  v6 = num_rows;
  v7 = &input_array[source_row];
  for ( i = &output_array[dest_row]; v6 > 0; --v6 )
  {
    v10 = *v7;
    v9 = *i;
    ++v7;
    ++i;
    memcpy(dst: v9, src: v10, count: num_cols);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430BC0
// Name: _jzero_far
// Source: json
//------------------------------------------------------------------------------
void __cdecl jzero_far(unsigned __int8 *target, unsigned int bytestozero)
{
  memset(dst: target, value: 0, count: bytestozero);
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041D930
// Name: _jdiv_round_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jdiv_round_up(int a, int b)
{
  return (a + b - 1) / b;
}

//------------------------------------------------------------------------------
// Address: 0x0041D950
// Name: _jround_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jround_up(int a, int b)
{
  return a + b - 1 - (a + b - 1) % b;
}

//------------------------------------------------------------------------------
// Address: 0x0041D970
// Name: _jcopy_sample_rows
// Source: json
//------------------------------------------------------------------------------
void __cdecl jcopy_sample_rows(
        unsigned __int8 **input_array,
        int source_row,
        unsigned __int8 **output_array,
        int dest_row,
        int num_rows,
        unsigned int num_cols)
{
  int v6; // ebx
  unsigned __int8 **v7; // esi
  unsigned __int8 **i; // edi
  unsigned __int8 *v9; // [esp-Ch] [ebp-18h]
  unsigned __int8 *v10; // [esp-8h] [ebp-14h]

  v6 = num_rows;
  v7 = &input_array[source_row];
  for ( i = &output_array[dest_row]; v6 > 0; --v6 )
  {
    v10 = *v7;
    v9 = *i;
    ++v7;
    ++i;
    memcpy(dst: v9, src: v10, count: num_cols);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D9C0
// Name: _jzero_far
// Source: json
//------------------------------------------------------------------------------
void __cdecl jzero_far(unsigned __int8 *target, unsigned int bytestozero)
{
  memset(dst: target, value: 0, count: bytestozero);
}

} // namespace vxconsole_ps3

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10275C00
// Name: _jdiv_round_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jdiv_round_up(int a, int b)
{
  return (a + b - 1) / b;
}

//------------------------------------------------------------------------------
// Address: 0x10275C20
// Name: _jround_up
// Source: json
//------------------------------------------------------------------------------
int __cdecl jround_up(int a, int b)
{
  return a + b - 1 - (a + b - 1) % b;
}

//------------------------------------------------------------------------------
// Address: 0x10275C40
// Name: _jcopy_sample_rows
// Source: json
//------------------------------------------------------------------------------
void __cdecl jcopy_sample_rows(
        unsigned __int8 **input_array,
        int source_row,
        unsigned __int8 **output_array,
        int dest_row,
        int num_rows,
        unsigned int num_cols)
{
  int v6; // ebx
  unsigned __int8 **v7; // esi
  unsigned __int8 **i; // edi
  unsigned __int8 *v9; // [esp-Ch] [ebp-18h]
  unsigned __int8 *v10; // [esp-8h] [ebp-14h]

  v6 = num_rows;
  v7 = &input_array[source_row];
  for ( i = &output_array[dest_row]; v6 > 0; --v6 )
  {
    v10 = *v7;
    v9 = *i;
    ++v7;
    ++i;
    memcpy(dst: v9, src: v10, count: num_cols);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275C90
// Name: _jcopy_block_row
// Source: json
//------------------------------------------------------------------------------
void __cdecl jcopy_block_row(__int16 (*input_row)[64], __int16 (*output_row)[64], unsigned int num_blocks)
{
  memcpy(dst: (unsigned __int8 *)output_row, src: (unsigned __int8 *)input_row, count: num_blocks << 7);
}

//------------------------------------------------------------------------------
// Address: 0x10275CB0
// Name: _jzero_far
// Source: json
//------------------------------------------------------------------------------
void __cdecl jzero_far(void *target, unsigned int bytestozero)
{
  memset(dst: (int)target, value: nullptr, count: bytestozero);
}

} // namespace client
