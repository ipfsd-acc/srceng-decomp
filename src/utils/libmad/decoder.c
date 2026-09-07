// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/libmad/decoder.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0051A0C0
// Name: _mad_decoder_init
// Source: json
//------------------------------------------------------------------------------
void __cdecl mad_decoder_init(
        mad_decoder *decoder,
        void *data,
        mad_flow (__cdecl *input_func)(void *, mad_stream *),
        mad_flow (__cdecl *header_func)(void *, const mad_header *),
        mad_flow (__cdecl *filter_func)(void *, const mad_stream *, mad_frame *),
        mad_flow (__cdecl *output_func)(void *, const mad_header *, mad_pcm *),
        mad_flow (__cdecl *error_func)(void *, mad_stream *, mad_frame *),
        mad_flow (__cdecl *message_func)(void *, void *, unsigned int *))
{
  decoder->options = 0;
  decoder->async.pid = 0;
  decoder->sync = nullptr;
  decoder->mode = -1;
  decoder->async.in = -1;
  decoder->async.out = -1;
  decoder->cb_data = data;
  decoder->input_func = input_func;
  decoder->header_func = header_func;
  decoder->filter_func = filter_func;
  decoder->output_func = output_func;
  decoder->error_func = error_func;
  decoder->message_func = message_func;
}

//------------------------------------------------------------------------------
// Address: 0x0051A110
// Name: error_default
// Source: json
//------------------------------------------------------------------------------
int __cdecl error_default(_DWORD *data, mad_stream *stream, mad_frame *frame)
{
  if ( stream->error != MAD_ERROR_BADCRC )
    return 0;
  if ( *data != 0 )
    mad_frame_mute(frame);
  else
    *data = 1;
  return 32;
}

//------------------------------------------------------------------------------
// Address: 0x0051A150
// Name: run_sync
// Source: json
//------------------------------------------------------------------------------
int __cdecl run_sync(mad_decoder *decoder)
{
  mad_decoder::<unnamed_type_sync> *sync; // ebx
  __int32 v4; // eax
  __int32 v5; // eax
  mad_flow v6; // eax
  __int32 v7; // eax
  int v8; // edi
  __int32 v9; // eax
  __int32 v10; // eax
  __int32 v11; // eax
  __int32 v12; // eax
  mad_flow (__cdecl *filter_func)(void *, const mad_stream *, mad_frame *); // eax
  int v14; // eax
  int v15; // eax
  mad_flow (__cdecl *output_func)(void *, const mad_header *, mad_pcm *); // eax
  int bad_last_frame; // [esp+8h] [ebp-8h] BYREF
  mad_flow (__cdecl *error_func)(void *, mad_stream *, mad_frame *); // [esp+Ch] [ebp-4h]
  void *error_data; // [esp+18h] [ebp+8h]

  bad_last_frame = 0;
  if ( decoder->input_func == nullptr )
    return 0;
  if ( decoder->error_func != nullptr )
  {
    error_func = decoder->error_func;
    error_data = decoder->cb_data;
  }
  else
  {
    error_func = (mad_flow (__cdecl *)(void *, mad_stream *, mad_frame *))error_default;
    error_data = &bad_last_frame;
  }
  sync = decoder->sync;
  mad_stream_init(stream: &sync->stream);
  mad_frame_init(frame: &sync->frame);
  mad_synth_init(synth: &sync->synth);
  sync->stream.options = decoder->options;
  while ( 1 )
  {
    v4 = decoder->input_func(a1: decoder->cb_data, a2: (mad_stream *)sync) - 16;
    if ( v4 == 0 )
      break;
    v5 = v4 - 1;
    if ( v5 == 0 )
      goto fail;
    if ( v5 != 15 )
    {
      while ( 1 )
      {
        do
        {
          if ( decoder->header_func == nullptr )
            break;
          if ( mad_header_decode(header: &sync->frame.header, stream: &sync->stream) == -1 )
          {
            if ( (sync->stream.error & 0xFF00) == 0 )
              goto LABEL_33;
            v6 = error_func(a1: error_data, a2: &sync->stream, a3: &sync->frame);
            goto LABEL_14;
          }
          v9 = decoder->header_func(a1: decoder->cb_data, a2: (const mad_header *)&sync->frame) - 16;
          if ( v9 == 0 )
            goto LABEL_35;
          v10 = v9 - 1;
          if ( v10 == 0 )
            goto fail;
        }
        while ( v10 == 15 );
        if ( mad_frame_decode(frame: &sync->frame, stream: &sync->stream) == -1 )
        {
          if ( (sync->stream.error & 0xFF00) == 0 )
            break;
          v11 = error_func(a1: error_data, a2: &sync->stream, a3: &sync->frame) - 16;
          if ( v11 == 0 )
            goto LABEL_35;
          v12 = v11 - 1;
          if ( v12 == 0 )
            goto fail;
          if ( v12 == 15 )
            goto LABEL_27;
        }
        else
        {
          bad_last_frame = 0;
LABEL_27:
          filter_func = decoder->filter_func;
          if ( filter_func == nullptr )
            goto LABEL_39;
          v14 = filter_func(a1: decoder->cb_data, a2: &sync->stream, a3: &sync->frame) - 16;
          if ( v14 == 0 )
            goto LABEL_35;
          v15 = v14 - 1;
          if ( v15 == 0 )
            goto fail;
          if ( v15 != 15 )
          {
LABEL_39:
            mad_synth_frame(synth: &sync->synth, frame: &sync->frame);
            output_func = decoder->output_func;
            if ( output_func != nullptr )
            {
              v6 = output_func(a1: decoder->cb_data, a2: &sync->frame.header, a3: &sync->synth.pcm);
LABEL_14:
              v7 = v6 - 16;
              if ( v7 == 0 )
                goto LABEL_35;
              if ( v7 == 1 )
              {
                v8 = -1;
                goto done_1;
              }
            }
          }
        }
      }
    }
LABEL_33:
    if ( sync->stream.error != MAD_ERROR_BUFLEN )
    {
fail:
      v8 = -1;
      goto done_1;
    }
  }
LABEL_35:
  v8 = 0;
done_1:
  mad_frame_finish(frame: &sync->frame);
  mad_stream_finish(stream: &sync->stream);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0051A300
// Name: _mad_decoder_run
// Source: json
//------------------------------------------------------------------------------
int __cdecl mad_decoder_run(mad_decoder *decoder, mad_decoder_mode mode)
{
  mad_decoder::<unnamed_type_sync> *v3; // eax
  int v4; // edi

  decoder->mode = mode;
  if ( mode != MAD_DECODER_MODE_SYNC )
    return -1;
  if ( run_sync == nullptr )
    return -1;
  v3 = (mad_decoder::<unnamed_type_sync> *)MemAlloc_Alloc(nSize: 0x5880u);
  decoder->sync = v3;
  if ( v3 == nullptr )
    return -1;
  v4 = run_sync(decoder);
  free(pMem: decoder->sync);
  decoder->sync = nullptr;
  return v4;
}
