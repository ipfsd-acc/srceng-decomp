// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/lzma/c/7zip/common/streamutils.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1001E120
// Name: long WriteStream(struct ISequentialOutStream __near *,void const __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl WriteStream(ISequentialOutStream *stream, char *data, unsigned int size, unsigned int *processedSize)
{
  unsigned int v4; // esi
  HRESULT result; // eax
  unsigned int v7; // ecx

  if ( processedSize != nullptr )
    *processedSize = 0;
  v4 = size;
  if ( size == 0 )
    return 0;
  while ( 1 )
  {
    result = stream->Write(this: stream, a2: data, a3: v4, a4: &size);
    v7 = size;
    if ( processedSize != nullptr )
      *processedSize += size;
    data += v7;
    v4 -= v7;
    if ( result != 0 )
      break;
    if ( v7 == 0 || v4 == 0 )
      return 0;
  }
  return result;
}

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004BCC90
// Name: long WriteStream(struct ISequentialOutStream __near *,void const __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl WriteStream(ISequentialOutStream *stream, char *data, unsigned int size, unsigned int *processedSize)
{
  unsigned int v4; // esi
  HRESULT result; // eax
  unsigned int v7; // ecx

  if ( processedSize != nullptr )
    *processedSize = 0;
  v4 = size;
  if ( size == 0 )
    return 0;
  while ( 1 )
  {
    result = stream->Write(this: stream, a2: data, a3: v4, a4: &size);
    v7 = size;
    if ( processedSize != nullptr )
      *processedSize += size;
    data += v7;
    v4 -= v7;
    if ( result != 0 )
      break;
    if ( v7 == 0 || v4 == 0 )
      return 0;
  }
  return result;
}

} // namespace hlfaceposer

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00526800
// Name: long WriteStream(struct ISequentialOutStream __near *,void const __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl WriteStream(ISequentialOutStream *stream, char *data, unsigned int size, unsigned int *processedSize)
{
  unsigned int v4; // esi
  HRESULT result; // eax
  unsigned int v7; // ecx

  if ( processedSize != nullptr )
    *processedSize = 0;
  v4 = size;
  if ( size == 0 )
    return 0;
  while ( 1 )
  {
    result = stream->Write(this: stream, a2: data, a3: v4, a4: &size);
    v7 = size;
    if ( processedSize != nullptr )
      *processedSize += size;
    data += v7;
    v4 -= v7;
    if ( result != 0 )
      break;
    if ( v7 == 0 || v4 == 0 )
      return 0;
  }
  return result;
}

} // namespace makegamedata

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10017D20
// Name: long WriteStream(struct ISequentialOutStream __near *,void const __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl WriteStream(ISequentialOutStream *stream, char *data, unsigned int size, unsigned int *processedSize)
{
  unsigned int v4; // esi
  HRESULT result; // eax
  unsigned int v7; // ecx

  if ( processedSize != nullptr )
    *processedSize = 0;
  v4 = size;
  if ( size == 0 )
    return 0;
  while ( 1 )
  {
    result = stream->Write(this: stream, a2: data, a3: v4, a4: &size);
    v7 = size;
    if ( processedSize != nullptr )
      *processedSize += size;
    data += v7;
    v4 -= v7;
    if ( result != 0 )
      break;
    if ( v7 == 0 || v4 == 0 )
      return 0;
  }
  return result;
}

} // namespace shadercompile_dll
