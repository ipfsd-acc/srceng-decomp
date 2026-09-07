// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/libmad/frame.c
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0051A620
// Name: _mad_frame_finish
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_frame_finish(mad_frame *frame)
{
  if ( frame->overlap != nullptr )
  {
    free(pMem: frame->overlap);
    frame->overlap = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051A650
// Name: decode_header
// Source: json
//------------------------------------------------------------------------------
int __usercall decode_header@<eax>(mad_header *header@<esi>, mad_stream *stream)
{
  mad_bitptr *p_ptr; // edi
  int v3; // eax
  int v5; // eax
  mad_layer layer; // ecx
  unsigned int v7; // eax
  int v8; // eax
  int flags; // ecx
  unsigned int v10; // eax
  unsigned int v11; // eax
  mad_emphasis v12; // eax
  bool v13; // zf

  p_ptr = &stream->ptr;
  header->flags = 0;
  header->private_bits = 0;
  mad_bit_skip(bitptr: &stream->ptr, len: 0xBu);
  if ( mad_bit_read(bitptr: &stream->ptr, len: 1u) == 0 )
    header->flags |= 0x4000u;
  if ( mad_bit_read(bitptr: p_ptr, len: 1u) != 0 )
  {
    if ( (header->flags & 0x4000) != 0 )
    {
      stream->error = MAD_ERROR_LOSTSYNC;
      return -1;
    }
  }
  else
  {
    header->flags |= 0x1000u;
  }
  v3 = mad_bit_read(bitptr: p_ptr, len: 2u);
  header->layer = 4 - v3;
  if ( v3 == 0 )
  {
    stream->error = MAD_ERROR_BADLAYER;
    return -1;
  }
  else
  {
    if ( mad_bit_read(bitptr: p_ptr, len: 1u) == 0 )
    {
      header->flags |= 0x10u;
      header->crc_check = mad_bit_crc(bitptr: *p_ptr, len: 0x10u, init: 0xFFFFu);
    }
    v5 = mad_bit_read(bitptr: p_ptr, len: 4u);
    if ( v5 == 15 )
    {
      stream->error = MAD_ERROR_BADBITRATE;
      return -1;
    }
    else
    {
      layer = header->layer;
      if ( (header->flags & 0x1000) != 0 )
        v7 = bitrate_table[(layer >> 1) + 3][v5];
      else
        v7 = *(_DWORD *)&crc_table[30 * layer + 226 + 2 * v5];
      header->bitrate = v7;
      v8 = mad_bit_read(bitptr: p_ptr, len: 2u);
      if ( v8 == 3 )
      {
        stream->error = MAD_ERROR_BADSAMPLERATE;
        return -1;
      }
      else
      {
        flags = header->flags;
        v10 = samplerate_table[v8];
        header->samplerate = v10;
        if ( (flags & 0x1000) != 0 )
        {
          v11 = v10 >> 1;
          header->samplerate = v11;
          if ( (flags & 0x4000) != 0 )
            header->samplerate = v11 >> 1;
        }
        if ( mad_bit_read(bitptr: p_ptr, len: 1u) != 0 )
          header->flags |= 0x80u;
        if ( mad_bit_read(bitptr: p_ptr, len: 1u) != 0 )
          header->private_bits |= 0x100u;
        header->mode = 3 - mad_bit_read(bitptr: p_ptr, len: 2u);
        header->mode_extension = mad_bit_read(bitptr: p_ptr, len: 2u);
        if ( mad_bit_read(bitptr: p_ptr, len: 1u) != 0 )
          header->flags |= 0x20u;
        if ( mad_bit_read(bitptr: p_ptr, len: 1u) != 0 )
          header->flags |= 0x40u;
        v12 = mad_bit_read(bitptr: p_ptr, len: 2u);
        v13 = (header->flags & 0x10) == 0;
        header->emphasis = v12;
        if ( !v13 )
          header->crc_target = mad_bit_read(bitptr: p_ptr, len: 0x10u);
        return 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051A830
// Name: free_bitrate
// Source: json
//------------------------------------------------------------------------------
int __cdecl free_bitrate(mad_stream *stream, const mad_header *header)
{
  mad_stream *v2; // esi
  int v3; // ecx
  int flags; // ecx
  unsigned int v5; // ebx
  bool v6; // zf
  unsigned int fraction; // edx
  int v8; // eax
  unsigned int v9; // edx
  mad_stream peek_stream; // [esp+8h] [ebp-7Ch] BYREF
  mad_header peek_header; // [esp+48h] [ebp-3Ch] BYREF
  mad_bitptr keep_ptr; // [esp+74h] [ebp-10h]
  unsigned int slots_per_frame; // [esp+7Ch] [ebp-8h]
  unsigned int pad_slot; // [esp+80h] [ebp-4h]

  v2 = stream;
  v3 = *(_DWORD *)&stream->ptr.cache;
  keep_ptr.byte = stream->ptr.byte;
  *(_DWORD *)&keep_ptr.cache = v3;
  flags = header->flags;
  v5 = 0;
  v6 = header->layer == MAD_LAYER_III;
  pad_slot = (flags & 0x80) != 0;
  if ( !v6 || (slots_per_frame = 72, (flags & 0x1000) == 0) )
    slots_per_frame = 144;
  if ( mad_stream_sync(stream) == 0 )
  {
    while ( 1 )
    {
      peek_stream = *v2;
      fraction = header->duration.fraction;
      *(_QWORD *)&peek_header.layer = *(_QWORD *)&header->layer;
      *(_QWORD *)&peek_header.mode_extension = *(_QWORD *)&header->mode_extension;
      *(_QWORD *)&peek_header.bitrate = *(_QWORD *)&header->bitrate;
      *(_QWORD *)&peek_header.crc_check = *(_QWORD *)&header->crc_check;
      *(_QWORD *)&peek_header.private_bits = *(_QWORD *)&header->private_bits;
      peek_header.duration.fraction = fraction;
      if ( decode_header(header: &peek_header, stream: &peek_stream) == 0
        && peek_header.layer == header->layer
        && peek_header.samplerate == header->samplerate )
      {
        v8 = mad_bit_nextbyte(bitptr: &stream->ptr) - stream->this_frame;
        v9 = header->layer == MAD_LAYER_I
           ? header->samplerate * (v8 + 4 * (1 - pad_slot)) / 0x30
           : header->samplerate * (v8 - pad_slot + 1) / slots_per_frame;
        v5 = v9 / 0x3E8;
        if ( v9 / 0x3E8 >= 8 )
          break;
      }
      mad_bit_skip(bitptr: &stream->ptr, len: 8u);
      if ( mad_stream_sync(stream) != 0 )
        break;
      v2 = stream;
    }
    v2 = stream;
  }
  v2->ptr = keep_ptr;
  if ( v5 < 8 || header->layer == MAD_LAYER_III && v5 > 0x280 )
  {
    v2->error = MAD_ERROR_LOSTSYNC;
    return -1;
  }
  else
  {
    v2->freerate = 1000 * v5;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051A9C0
// Name: _mad_header_decode
// Source: json
//------------------------------------------------------------------------------
int __cdecl mad_header_decode(mad_header *header, mad_stream *stream)
{
  const unsigned __int8 *next_frame; // eax
  const unsigned __int8 *bufend; // ebx
  unsigned int skiplen; // ecx
  int v7; // eax
  unsigned int freerate; // eax
  unsigned int v9; // eax
  int flags; // edx
  BOOL v11; // ecx
  unsigned int v12; // eax
  bool v13; // zf
  int v14; // edx
  const unsigned __int8 *this_frame; // ecx
  const unsigned __int8 *v16; // eax
  const unsigned __int8 *end; // [esp+18h] [ebp+Ch]

  next_frame = stream->next_frame;
  bufend = stream->bufend;
  end = bufend;
  if ( next_frame != nullptr )
  {
    skiplen = stream->skiplen;
    if ( skiplen == 0 )
      goto sync;
    if ( stream->sync == 0 )
      next_frame = stream->this_frame;
    if ( bufend - next_frame >= skiplen )
    {
      next_frame += skiplen;
      stream->skiplen = 0;
      stream->sync = 1;
      while ( 1 )
      {
sync:
        if ( stream->sync != 0 )
        {
          if ( bufend - next_frame < 8 )
            goto LABEL_42;
          if ( *next_frame != 0xFF || (next_frame[1] & 0xE0) != 0xE0 )
          {
            stream->this_frame = next_frame;
            stream->next_frame = next_frame + 1;
            stream->error = MAD_ERROR_LOSTSYNC;
            stream->sync = 0;
            return -1;
          }
        }
        else
        {
          mad_bit_init(bitptr: &stream->ptr, byte: next_frame);
          if ( mad_stream_sync(stream) == -1 )
          {
            if ( end - stream->next_frame < 8 )
              goto LABEL_44;
            next_frame = end - 8;
LABEL_42:
            stream->next_frame = next_frame;
            goto LABEL_44;
          }
          next_frame = mad_bit_nextbyte(bitptr: &stream->ptr);
          bufend = end;
        }
        stream->this_frame = next_frame;
        stream->next_frame = next_frame + 1;
        mad_bit_init(bitptr: &stream->ptr, byte: next_frame);
        if ( decode_header(header, stream) == -1 )
          goto fail_0;
        if ( header->layer == MAD_LAYER_I )
        {
          v7 = 12;
        }
        else if ( header->layer != MAD_LAYER_III || (v7 = 18, (header->flags & 0x1000) == 0) )
        {
          v7 = 36;
        }
        mad_timer_set(timer: &header->duration, seconds: 0, numer: 32 * v7, denom: header->samplerate);
        if ( header->bitrate == 0 )
        {
          freerate = stream->freerate;
          if ( (freerate == 0 || stream->sync == 0 || header->layer == MAD_LAYER_III && freerate > 0x9C400)
            && free_bitrate(stream, header) == -1 )
          {
            goto fail_0;
          }
          v9 = stream->freerate;
          header->flags |= 0x400u;
          header->bitrate = v9;
        }
        flags = header->flags;
        v11 = (flags & 0x80) != 0;
        if ( header->layer == MAD_LAYER_I )
        {
          v12 = 4 * (v11 + 12 * header->bitrate / header->samplerate);
        }
        else
        {
          if ( header->layer != MAD_LAYER_III || (v13 = (flags & 0x1000) == 0, v14 = 72, v13) )
            v14 = 144;
          v12 = v11 + v14 * header->bitrate / header->samplerate;
        }
        this_frame = stream->this_frame;
        if ( v12 + 8 > bufend - this_frame )
        {
          stream->next_frame = this_frame;
          goto LABEL_44;
        }
        v16 = &this_frame[v12];
        v13 = stream->sync == 0;
        stream->next_frame = v16;
        if ( !v13 )
          break;
        if ( *v16 == 0xFF && (v16[1] & 0xE0) == 0xE0 )
        {
          stream->sync = 1;
          break;
        }
        bufend = end;
        next_frame = this_frame + 1;
        stream->next_frame = this_frame + 1;
      }
      header->flags |= 8u;
      return 0;
    }
    else
    {
      stream->skiplen = (unsigned int)&next_frame[skiplen - (_DWORD)bufend];
      stream->next_frame = bufend;
LABEL_44:
      stream->error = MAD_ERROR_BUFLEN;
fail_0:
      stream->sync = 0;
      return -1;
    }
  }
  else
  {
    stream->sync = 0;
    stream->error = MAD_ERROR_BUFPTR;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051ABF0
// Name: _mad_frame_decode
// Source: json
//------------------------------------------------------------------------------
int __cdecl mad_frame_decode(mad_frame *frame, mad_stream *stream)
{
  bool v2; // zf
  mad_layer layer; // ecx
  int v5; // edx
  mad_bitptr next_frame; // [esp+8h] [ebp-8h] BYREF

  v2 = (frame->header.flags & 8) == 0;
  frame->options = stream->options;
  if ( v2 && mad_header_decode(header: &frame->header, stream) == -1 )
    goto fail_1;
  layer = frame->header.layer;
  frame->header.flags &= ~8u;
  if ( ((int (__cdecl *)(mad_stream *, mad_frame *))samplerate_table[layer + 2])(a1: stream, a2: frame) == -1 )
  {
    if ( (stream->error & 0xFF00) == 0 )
      stream->next_frame = stream->this_frame;
fail_1:
    stream->anc_bitlen = 0;
    return -1;
  }
  if ( frame->header.layer != MAD_LAYER_III )
  {
    mad_bit_init(bitptr: &next_frame, byte: stream->next_frame);
    v5 = *(_DWORD *)&stream->ptr.cache;
    stream->anc_ptr.byte = stream->ptr.byte;
    *(_DWORD *)&stream->anc_ptr.cache = v5;
    stream->anc_bitlen = mad_bit_length(begin: &stream->ptr, end: &next_frame);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0051AC90
// Name: _mad_frame_mute
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_frame_mute(mad_frame *frame)
{
  int *v1; // eax
  unsigned int i; // esi
  int j; // ecx
  unsigned int v4; // eax
  int k; // ecx

  v1 = frame->sbsample[0][0];
  for ( i = 36; i != 0; --i )
  {
    for ( j = 32; j != 0; --j )
    {
      v1[1152] = 0;
      *v1++ = 0;
    }
  }
  if ( frame->overlap != nullptr )
  {
    do
    {
      v4 = i;
      for ( k = 32; k != 0; --k )
      {
        *(int *)((char *)(*frame->overlap)[1][0] + v4) = 0;
        *(int *)((char *)(*frame->overlap)[0][0] + v4) = 0;
        v4 += 72;
      }
      i += 4;
    }
    while ( i < 0x48 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051AD10
// Name: _mad_frame_init
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_frame_init(mad_frame *frame)
{
  frame->header.layer = 0;
  frame->header.mode = MAD_MODE_SINGLE_CHANNEL;
  frame->header.mode_extension = 0;
  frame->header.emphasis = MAD_EMPHASIS_NONE;
  frame->header.bitrate = 0;
  frame->header.samplerate = 0;
  frame->header.crc_check = 0;
  frame->header.crc_target = 0;
  frame->header.flags = 0;
  frame->header.private_bits = 0;
  frame->header.duration.seconds = 0;
  frame->header.duration.fraction = 0;
  frame->options = 0;
  frame->overlap = nullptr;
  mad_frame_mute(frame);
}
