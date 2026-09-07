// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/libmad/stream.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00519DF0
// Name: _mad_stream_init
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_stream_init(mad_stream *stream)
{
  stream->buffer = nullptr;
  stream->bufend = nullptr;
  stream->skiplen = 0;
  stream->sync = 0;
  stream->freerate = 0;
  stream->this_frame = nullptr;
  stream->next_frame = nullptr;
  mad_bit_init(bitptr: &stream->ptr, byte: nullptr);
  mad_bit_init(bitptr: &stream->anc_ptr, byte: nullptr);
  stream->anc_bitlen = 0;
  stream->main_data = nullptr;
  stream->md_len = 0;
  stream->options = 0;
  stream->error = MAD_ERROR_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x00519E40
// Name: _mad_stream_finish
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_stream_finish(mad_stream *stream)
{
  if ( stream->main_data != nullptr )
  {
    free(pMem: stream->main_data);
    stream->main_data = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00519E70
// Name: _mad_stream_buffer
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_stream_buffer(mad_stream *stream, const unsigned __int8 *buffer, unsigned int length)
{
  stream->buffer = buffer;
  stream->bufend = &buffer[length];
  stream->this_frame = buffer;
  stream->next_frame = buffer;
  stream->sync = 1;
  mad_bit_init(bitptr: &stream->ptr, byte: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x00519EA0
// Name: _mad_stream_sync
// Source: json
//------------------------------------------------------------------------------
int __cdecl mad_stream_sync(mad_stream *stream)
{
  const unsigned __int8 *v1; // eax
  const unsigned __int8 *i; // esi

  v1 = mad_bit_nextbyte(bitptr: &stream->ptr);
  for ( i = stream->bufend; v1 < i - 1; ++v1 )
  {
    if ( *v1 == 0xFF && (v1[1] & 0xE0) == 0xE0 )
      break;
  }
  if ( i - v1 < 8 )
    return -1;
  mad_bit_init(bitptr: &stream->ptr, byte: v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00519F00
// Name: _mad_stream_errorstr
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl mad_stream_errorstr(const mad_stream *stream)
{
  mad_error error; // eax
  const char *result; // eax

  error = stream->error;
  if ( error > MAD_ERROR_BADCRC )
  {
    switch ( error )
    {
      case 529:
        result = "forbidden bit allocation value";
        break;
      case 545:
        result = "bad scalefactor index";
        break;
      case 546:
        result = "bad bitrate/mode combination";
        break;
      case 561:
        result = "bad frame length";
        break;
      case 562:
        result = "bad big_values count";
        break;
      case 563:
        result = "reserved block_type";
        break;
      case 564:
        result = "bad scalefactor selection info";
        break;
      case 565:
        result = "bad main_data_begin pointer";
        break;
      case 566:
        result = "bad audio data length";
        break;
      case 567:
        result = "bad Huffman table select";
        break;
      case 568:
        result = "Huffman data overrun";
        break;
      case 569:
        result = "incompatible block_type for JS";
        break;
      default:
LABEL_30:
        result = nullptr;
        break;
    }
  }
  else if ( error == MAD_ERROR_BADCRC )
  {
    return "CRC check failed";
  }
  else if ( error > MAD_ERROR_LOSTSYNC )
  {
    switch ( error )
    {
      case MAD_ERROR_BADLAYER:
        result = "reserved header layer value";
        break;
      case MAD_ERROR_BADBITRATE:
        result = "forbidden bitrate value";
        break;
      case MAD_ERROR_BADSAMPLERATE:
        result = "reserved sample frequency value";
        break;
      case MAD_ERROR_BADEMPHASIS:
        result = "reserved emphasis value";
        break;
      default:
        goto LABEL_30;
    }
  }
  else if ( error == MAD_ERROR_LOSTSYNC )
  {
    return "lost synchronization";
  }
  else
  {
    switch ( error )
    {
      case MAD_ERROR_NONE:
        result = "no error";
        break;
      case MAD_ERROR_BUFLEN:
        result = "input buffer too small (or EOF)";
        break;
      case MAD_ERROR_BUFPTR:
        result = "invalid (null) buffer pointer";
        break;
      case MAD_ERROR_NOMEM:
        result = "not enough memory";
        break;
      default:
        goto LABEL_30;
    }
  }
  return result;
}
