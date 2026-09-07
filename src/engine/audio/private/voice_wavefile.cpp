// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/voice_wavefile.cpp
// Functions: 117
// ============================================================

#include "engine\audio\private\voice_wavefile.h"

//------------------------------------------------------------------------------
// Address: 0x10057A50
// Name: bool ReadWaveFile(char const __near *,char __near * __near &,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ReadWaveFile(
        const char *pFilename,
        char **pData,
        int *nDataBytes,
        int *wBitsPerSample,
        int *nChannels,
        int *nSamplesPerSec)
{
  _iobuf *v6; // eax
  _iobuf *v7; // esi
  char *v9; // eax
  int buffer; // [esp+4h] [ebp-4h] BYREF

  v6 = fopen(file: pFilename, mode: "rb");
  v7 = v6;
  if ( v6 == nullptr )
    return 0;
  fseek(stream: v6, offset: 22, whence: 0);
  fread(&buffer, elementSize: 2u, count: 1u, stream: v7);
  *nChannels = (unsigned __int16)buffer;
  fread(&buffer, elementSize: 4u, count: 1u, stream: v7);
  *nSamplesPerSec = buffer;
  fseek(stream: v7, offset: 34, whence: 0);
  fread(&buffer, elementSize: 2u, count: 1u, stream: v7);
  *wBitsPerSample = (unsigned __int16)buffer;
  fseek(stream: v7, offset: 40, whence: 0);
  fread(&buffer, elementSize: 4u, count: 1u, stream: v7);
  *nDataBytes = buffer;
  fread(&buffer, elementSize: 4u, count: 1u, stream: v7);
  v9 = (char *)MemAlloc_Alloc(nSize: *nDataBytes);
  *pData = v9;
  if ( v9 != nullptr )
  {
    fread(buffer: v9, elementSize: *nDataBytes, count: 1u, stream: v7);
    fclose(stream: v7);
    return 1;
  }
  else
  {
    fclose(stream: v7);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057B40
// Name: bool WriteWaveFile(char const __near *,char const __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WriteWaveFile(
        const char *pFilename,
        const char *pData,
        unsigned int nBytes,
        int wBitsPerSample,
        int nChannels,
        int nSamplesPerSec)
{
  _iobuf *v6; // eax
  _iobuf *v7; // esi
  int v9; // edi
  int buffer; // [esp+4h] [ebp-4h] BYREF

  v6 = fopen(file: pFilename, mode: "wb");
  v7 = v6;
  if ( v6 == nullptr )
    return 0;
  fwrite(buffer: "RIFF", size: 4u, count: 1u, stream: v6);
  buffer = 0;
  fwrite(&buffer, size: 4u, count: 1u, stream: v7);
  fwrite(buffer: "WAVE", size: 4u, count: 1u, stream: v7);
  fwrite(buffer: "fmt ", size: 4u, count: 1u, stream: v7);
  buffer = 16;
  fwrite(&buffer, size: 4u, count: 1u, stream: v7);
  buffer = 1;
  fwrite(&buffer, size: 2u, count: 1u, stream: v7);
  buffer = (unsigned __int16)nChannels;
  fwrite(&buffer, size: 2u, count: 1u, stream: v7);
  buffer = nSamplesPerSec;
  fwrite(&buffer, size: 4u, count: 1u, stream: v7);
  buffer = nSamplesPerSec * nChannels * (wBitsPerSample / 8);
  fwrite(&buffer, size: 4u, count: 1u, stream: v7);
  buffer = (unsigned __int16)(nChannels * (wBitsPerSample / 8));
  fwrite(&buffer, size: 2u, count: 1u, stream: v7);
  buffer = (unsigned __int16)wBitsPerSample;
  fwrite(&buffer, size: 2u, count: 1u, stream: v7);
  fwrite(buffer: "data", size: 4u, count: 1u, stream: v7);
  buffer = nBytes;
  fwrite(&buffer, size: 4u, count: 1u, stream: v7);
  fwrite(buffer: pData, size: nBytes, count: 1u, stream: v7);
  v9 = ftell(stream: v7) - 8;
  fseek(stream: v7, offset: 4, whence: 0);
  buffer = v9;
  fwrite(&buffer, size: 4u, count: 1u, stream: v7);
  fclose(stream: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10310340
// Name: _dynamic_initializer_for__voice_steal__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_steal__()
{
  ConVar::ConVar(this: &voice_steal, pName: "voice_steal", pDefaultValue: "2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_steal__);
}

//------------------------------------------------------------------------------
// Address: 0x103106F0
// Name: _dynamic_initializer_for__voice_minimum_gain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_minimum_gain__()
{
  ConVar::ConVar(this: &voice_minimum_gain, pName: "voice_minimum_gain", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_minimum_gain__);
}

//------------------------------------------------------------------------------
// Address: 0x10312080
// Name: _dynamic_initializer_for__voice_avggain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_avggain__()
{
  ConVar::ConVar(this: &voice_avggain, pName: "voice_avggain", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_avggain__);
}

//------------------------------------------------------------------------------
// Address: 0x103120B0
// Name: _dynamic_initializer_for__voice_maxgain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_maxgain__()
{
  ConVar::ConVar(this: &voice_maxgain, pName: "voice_maxgain", pDefaultValue: "10", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_maxgain__);
}

//------------------------------------------------------------------------------
// Address: 0x103120E0
// Name: _dynamic_initializer_for__voice_scale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_scale__()
{
  ConVar::ConVar(this: &voice_scale, pName: "voice_scale", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_scale__);
}

//------------------------------------------------------------------------------
// Address: 0x10312110
// Name: _dynamic_initializer_for__voice_loopback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_loopback__()
{
  ConVar::ConVar(this: &voice_loopback, pName: "voice_loopback", pDefaultValue: "0", flags: 512);
  return atexit(func: dynamic_atexit_destructor_for__voice_loopback__);
}

//------------------------------------------------------------------------------
// Address: 0x10312140
// Name: _dynamic_initializer_for__voice_fadeouttime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_fadeouttime__()
{
  ConVar::ConVar(this: &voice_fadeouttime, pName: "voice_fadeouttime", pDefaultValue: "0.1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_fadeouttime__);
}

//------------------------------------------------------------------------------
// Address: 0x10312170
// Name: _dynamic_initializer_for__voice_threshold_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_threshold_delay__()
{
  ConVar::ConVar(this: &voice_threshold_delay, pName: "voice_thresold_delay", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_threshold_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x103121A0
// Name: _dynamic_initializer_for__voice_profile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_profile__()
{
  ConVar::ConVar(this: &voice_profile, pName: "voice_profile", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_profile__);
}

//------------------------------------------------------------------------------
// Address: 0x103121D0
// Name: _dynamic_initializer_for__voice_showchannels__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_showchannels__()
{
  ConVar::ConVar(this: &voice_showchannels, pName: "voice_showchannels", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_showchannels__);
}

//------------------------------------------------------------------------------
// Address: 0x10312200
// Name: _dynamic_initializer_for__voice_showincoming__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_showincoming__()
{
  ConVar::ConVar(this: &voice_showincoming, pName: "voice_showincoming", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_showincoming__);
}

//------------------------------------------------------------------------------
// Address: 0x10312230
// Name: _dynamic_initializer_for__voice_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_enable__()
{
  ConVar::ConVar(
    this: &voice_enable,
    pName: "voice_enable",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Toggle voice transmit and receive.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))VoiceEnableCallback);
  return atexit(func: dynamic_atexit_destructor_for__voice_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10312260
// Name: _dynamic_initializer_for__voice_threshold__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_threshold__()
{
  ConVar::ConVar(this: &voice_threshold, pName: "voice_threshold", pDefaultValue: "2000", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_threshold__);
}

//------------------------------------------------------------------------------
// Address: 0x10312290
// Name: _dynamic_initializer_for__voice_forcemicrecord__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_forcemicrecord__()
{
  ConVar::ConVar(this: &voice_forcemicrecord, pName: "voice_forcemicrecord", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_forcemicrecord__);
}

//------------------------------------------------------------------------------
// Address: 0x10312310
// Name: _dynamic_initializer_for__voice_writevoices__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_writevoices__()
{
  ConVar::ConVar(
    this: &voice_writevoices,
    pName: "voice_writevoices",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Saves each speaker's voice data into separate .wav files\n");
  return atexit(func: dynamic_atexit_destructor_for__voice_writevoices__);
}

//------------------------------------------------------------------------------
// Address: 0x10312350
// Name: _dynamic_initializer_for__voice_mixer_mute__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_mixer_mute__()
{
  ConVar::ConVar(this: &voice_mixer_mute, pName: "voice_mixer_mute", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_mixer_mute__);
}

//------------------------------------------------------------------------------
// Address: 0x10312380
// Name: _dynamic_initializer_for__voice_mixer_boost__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_mixer_boost__()
{
  ConVar::ConVar(this: &voice_mixer_boost, pName: "voice_mixer_boost", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_mixer_boost__);
}

//------------------------------------------------------------------------------
// Address: 0x103123B0
// Name: _dynamic_initializer_for__voice_mixer_volume__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_mixer_volume__()
{
  ConVar::ConVar(this: &voice_mixer_volume, pName: "voice_mixer_volume", pDefaultValue: "1.0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__voice_mixer_volume__);
}

//------------------------------------------------------------------------------
// Address: 0x10312410
// Name: _dynamic_initializer_for__voice_overdrive__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_overdrive__()
{
  ConVar::ConVar(this: &voice_overdrive, pName: "voice_overdrive", pDefaultValue: "2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_overdrive__);
}

//------------------------------------------------------------------------------
// Address: 0x10312440
// Name: _dynamic_initializer_for__voice_overdrivefadetime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_overdrivefadetime__()
{
  ConVar::ConVar(this: &voice_overdrivefadetime, pName: "voice_overdrivefadetime", pDefaultValue: "0.4", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_overdrivefadetime__);
}

//------------------------------------------------------------------------------
// Address: 0x103181C0
// Name: _dynamic_initializer_for__voice_debugfeedbackfrom__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_debugfeedbackfrom__()
{
  ConVar::ConVar(this: &voice_debugfeedbackfrom, pName: "voice_debugfeedbackfrom", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_debugfeedbackfrom__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AF10
// Name: _dynamic_initializer_for__voice_recordtofile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_recordtofile__()
{
  ConVar::ConVar(
    this: &voice_recordtofile,
    pName: "voice_recordtofile",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Record mic data and decompressed voice data into 'voice_micdata.wav' and 'voice_decompressed.wav'");
  return atexit(func: dynamic_atexit_destructor_for__voice_recordtofile__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AF40
// Name: _dynamic_initializer_for__voice_inputfromfile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_inputfromfile__()
{
  ConVar::ConVar(
    this: &voice_inputfromfile,
    pName: "voice_inputfromfile",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Get voice input from 'voice_input.wav' rather than from the microphone.");
  return atexit(func: dynamic_atexit_destructor_for__voice_inputfromfile__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B390
// Name: _dynamic_initializer_for__voice_vox__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_vox__()
{
  ConVar::ConVar(this: &voice_vox, pName: "voice_vox", pDefaultValue: "false", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__voice_vox__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CCC0
// Name: _dynamic_initializer_for__voice_verbose__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_verbose__()
{
  ConVar::ConVar(
    this: &voice_verbose,
    pName: "voice_verbose",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Turns on debug output with detailed spew about voice data processing.");
  return atexit(func: dynamic_atexit_destructor_for__voice_verbose__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CCF0
// Name: _dynamic_initializer_for__voice_xsend_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_xsend_debug__()
{
  ConVar::ConVar(this: &voice_xsend_debug, pName: "voice_xsend_debug", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_xsend_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D530
// Name: _dynamic_initializer_for__voice_debugfeedback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_debugfeedback__()
{
  ConVar::ConVar(this: &voice_debugfeedback, pName: "voice_debugfeedback", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__voice_debugfeedback__);
}

//------------------------------------------------------------------------------
// Address: 0x10320C80
// Name: _dynamic_atexit_destructor_for__voice_steal__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_steal__()
{
  ConVar::~ConVar(this: &voice_steal);
}

//------------------------------------------------------------------------------
// Address: 0x10320DA0
// Name: _dynamic_atexit_destructor_for__voice_minimum_gain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_minimum_gain__()
{
  ConVar::~ConVar(this: &voice_minimum_gain);
}

//------------------------------------------------------------------------------
// Address: 0x10321FD0
// Name: _dynamic_atexit_destructor_for__voice_avggain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_avggain__()
{
  ConVar::~ConVar(this: &voice_avggain);
}

//------------------------------------------------------------------------------
// Address: 0x10321FE0
// Name: _dynamic_atexit_destructor_for__voice_maxgain__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_maxgain__()
{
  ConVar::~ConVar(this: &voice_maxgain);
}

//------------------------------------------------------------------------------
// Address: 0x10321FF0
// Name: _dynamic_atexit_destructor_for__voice_scale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_scale__()
{
  ConVar::~ConVar(this: &voice_scale);
}

//------------------------------------------------------------------------------
// Address: 0x10322000
// Name: _dynamic_atexit_destructor_for__voice_loopback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_loopback__()
{
  ConVar::~ConVar(this: &voice_loopback);
}

//------------------------------------------------------------------------------
// Address: 0x10322010
// Name: _dynamic_atexit_destructor_for__voice_fadeouttime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_fadeouttime__()
{
  ConVar::~ConVar(this: &voice_fadeouttime);
}

//------------------------------------------------------------------------------
// Address: 0x10322020
// Name: _dynamic_atexit_destructor_for__voice_threshold_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_threshold_delay__()
{
  ConVar::~ConVar(this: &voice_threshold_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10322030
// Name: _dynamic_atexit_destructor_for__voice_profile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_profile__()
{
  ConVar::~ConVar(this: &voice_profile);
}

//------------------------------------------------------------------------------
// Address: 0x10322040
// Name: _dynamic_atexit_destructor_for__voice_showchannels__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_showchannels__()
{
  ConVar::~ConVar(this: &voice_showchannels);
}

//------------------------------------------------------------------------------
// Address: 0x10322050
// Name: _dynamic_atexit_destructor_for__voice_showincoming__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_showincoming__()
{
  ConVar::~ConVar(this: &voice_showincoming);
}

//------------------------------------------------------------------------------
// Address: 0x10322060
// Name: _dynamic_atexit_destructor_for__voice_enable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_enable__()
{
  ConVar::~ConVar(this: &voice_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10322070
// Name: _dynamic_atexit_destructor_for__voice_threshold__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_threshold__()
{
  ConVar::~ConVar(this: &voice_threshold);
}

//------------------------------------------------------------------------------
// Address: 0x10322080
// Name: _dynamic_atexit_destructor_for__voice_forcemicrecord__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_forcemicrecord__()
{
  ConVar::~ConVar(this: &voice_forcemicrecord);
}

//------------------------------------------------------------------------------
// Address: 0x10322090
// Name: _dynamic_atexit_destructor_for__voice_writevoices__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_writevoices__()
{
  ConVar::~ConVar(this: &voice_writevoices);
}

//------------------------------------------------------------------------------
// Address: 0x103220B0
// Name: _dynamic_atexit_destructor_for__voice_mixer_mute__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_mixer_mute__()
{
  ConVar::~ConVar(this: &voice_mixer_mute);
}

//------------------------------------------------------------------------------
// Address: 0x103220C0
// Name: _dynamic_atexit_destructor_for__voice_mixer_boost__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_mixer_boost__()
{
  ConVar::~ConVar(this: &voice_mixer_boost);
}

//------------------------------------------------------------------------------
// Address: 0x103220D0
// Name: _dynamic_atexit_destructor_for__voice_mixer_volume__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_mixer_volume__()
{
  ConVar::~ConVar(this: &voice_mixer_volume);
}

//------------------------------------------------------------------------------
// Address: 0x103220E0
// Name: _dynamic_atexit_destructor_for__voice_overdrive__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_overdrive__()
{
  ConVar::~ConVar(this: &voice_overdrive);
}

//------------------------------------------------------------------------------
// Address: 0x103220F0
// Name: _dynamic_atexit_destructor_for__voice_overdrivefadetime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_overdrivefadetime__()
{
  ConVar::~ConVar(this: &voice_overdrivefadetime);
}

//------------------------------------------------------------------------------
// Address: 0x103245F0
// Name: _dynamic_atexit_destructor_for__voice_debugfeedbackfrom__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_debugfeedbackfrom__()
{
  ConVar::~ConVar(this: &voice_debugfeedbackfrom);
}

//------------------------------------------------------------------------------
// Address: 0x103257D0
// Name: _dynamic_atexit_destructor_for__voice_recordtofile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_recordtofile__()
{
  ConVar::~ConVar(this: &voice_recordtofile);
}

//------------------------------------------------------------------------------
// Address: 0x103257E0
// Name: _dynamic_atexit_destructor_for__voice_inputfromfile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_inputfromfile__()
{
  ConVar::~ConVar(this: &voice_inputfromfile);
}

//------------------------------------------------------------------------------
// Address: 0x10325950
// Name: _dynamic_atexit_destructor_for__voice_vox__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_vox__()
{
  ConVar::~ConVar(this: &voice_vox);
}

//------------------------------------------------------------------------------
// Address: 0x10326320
// Name: _dynamic_atexit_destructor_for__voice_verbose__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_verbose__()
{
  ConVar::~ConVar(this: &voice_verbose);
}

//------------------------------------------------------------------------------
// Address: 0x10326330
// Name: _dynamic_atexit_destructor_for__voice_xsend_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_xsend_debug__()
{
  ConVar::~ConVar(this: &voice_xsend_debug);
}

//------------------------------------------------------------------------------
// Address: 0x103266B0
// Name: _dynamic_atexit_destructor_for__voice_debugfeedback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_debugfeedback__()
{
  ConVar::~ConVar(this: &voice_debugfeedback);
}

//------------------------------------------------------------------------------
// Address: 0x10310370
// Name: _dynamic_initializer_for__dsp_dist_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_dist_min__()
{
  ConVar::ConVar(this: &dsp_dist_min, pName: "dsp_dist_min", pDefaultValue: "0.0", flags: 81920);
  return atexit(func: dynamic_atexit_destructor_for__dsp_dist_min__);
}

//------------------------------------------------------------------------------
// Address: 0x103103A0
// Name: _dynamic_initializer_for__dsp_dist_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_dist_max__()
{
  ConVar::ConVar(this: &dsp_dist_max, pName: "dsp_dist_max", pDefaultValue: "1440.0", flags: 81920);
  return atexit(func: dynamic_atexit_destructor_for__dsp_dist_max__);
}

//------------------------------------------------------------------------------
// Address: 0x103103D0
// Name: _dynamic_initializer_for__dsp_mix_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_mix_min__()
{
  ConVar::ConVar(this: &dsp_mix_min, pName: "dsp_mix_min", pDefaultValue: "0.2", flags: 0x10000);
  return atexit(func: dynamic_atexit_destructor_for__dsp_mix_min__);
}

//------------------------------------------------------------------------------
// Address: 0x10310400
// Name: _dynamic_initializer_for__dsp_mix_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_mix_max__()
{
  ConVar::ConVar(this: &dsp_mix_max, pName: "dsp_mix_max", pDefaultValue: "0.8", flags: 0x10000);
  return atexit(func: dynamic_atexit_destructor_for__dsp_mix_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10310430
// Name: _dynamic_initializer_for__dsp_db_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_db_min__()
{
  ConVar::ConVar(this: &dsp_db_min, pName: "dsp_db_min", pDefaultValue: "80", flags: 0x10000);
  return atexit(func: dynamic_atexit_destructor_for__dsp_db_min__);
}

//------------------------------------------------------------------------------
// Address: 0x10310460
// Name: _dynamic_initializer_for__dsp_db_mixdrop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dsp_db_mixdrop__()
{
  ConVar::ConVar(this: &dsp_db_mixdrop, pName: "dsp_db_mixdrop", pDefaultValue: "0.5", flags: 0x10000);
  return atexit(func: dynamic_atexit_destructor_for__dsp_db_mixdrop__);
}

//------------------------------------------------------------------------------
// Address: 0x103122C0
// Name: _dynamic_initializer_for__g_VoiceChannels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAutoGain *dynamic_initializer_for__g_VoiceChannels__()
{
  int v0; // ebx
  CAutoGain *p_m_AutoGain; // esi
  CAutoGain *result; // eax

  v0 = 4;
  p_m_AutoGain = &g_VoiceChannels[0].m_AutoGain;
  do
  {
    CCircularBuffer::CCircularBuffer(this: (CCircularBuffer *)&p_m_AutoGain[-503].m_FixedCurrentGain, size: 22050);
    result = CAutoGain::CAutoGain(this: p_m_AutoGain);
    p_m_AutoGain[-503].m_NextGain = NAN;
    p_m_AutoGain[-1].m_GainMultiplier = 0;
    p_m_AutoGain[1].m_AvgToMaxVal = NAN;
    p_m_AutoGain[1].m_CurBlockOffset = -1;
    p_m_AutoGain = (CAutoGain *)((char *)p_m_AutoGain + 22160);
    --v0;
  }
  while ( v0 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10312340
// Name: _dynamic_initializer_for__g_VoiceWriter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VoiceWriter__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VoiceWriter__);
}

//------------------------------------------------------------------------------
// Address: 0x103123E0
// Name: _dynamic_initializer_for__g_CVoiceSfx__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSfxTable *dynamic_initializer_for__g_CVoiceSfx__()
{
  CSfxTable *v0; // esi
  int i; // edi
  CSfxTable *result; // eax

  v0 = &g_CVoiceSfx;
  for ( i = 4; i >= 0; --i )
  {
    result = CSfxTable::CSfxTable(this: v0);
    v0->__vftable = (CSfxTable_vtbl *)&CVoiceSfx::`vftable';
    ++v0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10312470
// Name: _dynamic_initializer_for__g_Sentences__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Sentences__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Sentences__);
}

//------------------------------------------------------------------------------
// Address: 0x10312480
// Name: _dynamic_initializer_for__vox_reload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vox_reload__()
{
  ConCommand::ConCommand(
    this: &vox_reload,
    pName: "vox_reload",
    callback: (void (__cdecl *)())VOX_Reload,
    pHelpString: "Reload sentences.txt file",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vox_reload__);
}

//------------------------------------------------------------------------------
// Address: 0x103124B0
// Name: _dynamic_initializer_for__g_GroupLRU__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GroupLRU__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_GroupLRU__);
}

//------------------------------------------------------------------------------
// Address: 0x103124C0
// Name: _dynamic_initializer_for__g_SentenceFile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SentenceFile__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SentenceFile__);
}

//------------------------------------------------------------------------------
// Address: 0x103124D0
// Name: _dynamic_initializer_for__g_SentenceGroups__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SentenceGroups__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SentenceGroups__);
}

//------------------------------------------------------------------------------
// Address: 0x103124E0
// Name: _dynamic_initializer_for__sentencegroup_t::s_SymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sentencegroup_t::s_SymbolTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &sentencegroup_t::s_SymbolTable,
    growSize: 0,
    initSize: 256,
    caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__sentencegroup_t::s_SymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103181F0
// Name: _dynamic_initializer_for__setmaster__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setmaster__()
{
  ConCommand::ConCommand(
    this: &setmaster,
    pName: "setmaster",
    callback: (void (__cdecl *)())SetMaster_f,
    pHelpString: "add/remove/enable/disable master servers",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setmaster__);
}

//------------------------------------------------------------------------------
// Address: 0x10318220
// Name: _dynamic_initializer_for__heartbeat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__heartbeat__()
{
  ConCommand::ConCommand(
    this: &heartbeat,
    pName: "heartbeat",
    callback: Heartbeat_f,
    pHelpString: "Force heartbeat of master servers",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__heartbeat__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AF70
// Name: _dynamic_initializer_for___restart_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___restart_command__()
{
  ConCommand::ConCommand(
    this: &restart_command,
    pName: "_restart",
    callback: restart,
    pHelpString: "Shutdown and restart the engine.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for___restart_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B3C0
// Name: _dynamic_initializer_for__listmodels_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__listmodels_command__()
{
  ConCommand::ConCommand(
    this: &listmodels_command,
    pName: "listmodels",
    callback: listmodels,
    pHelpString: "List loaded models.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__listmodels_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B3F0
// Name: _dynamic_initializer_for__incrementvar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__incrementvar_command__()
{
  ConCommand::ConCommand(
    this: &incrementvar_command,
    pName: "incrementvar",
    callback: (void (__cdecl *)())incrementvar,
    pHelpString: "Increment specified convar value.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__incrementvar_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B420
// Name: _dynamic_initializer_for__multvar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__multvar_command__()
{
  ConCommand::ConCommand(
    this: &multvar_command,
    pName: "multvar",
    callback: (void (__cdecl *)())multvar,
    pHelpString: "Multiply specified convar value.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__multvar_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B450
// Name: _dynamic_initializer_for__dumpstringtables_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dumpstringtables_command__()
{
  ConCommand::ConCommand(
    this: &dumpstringtables_command,
    pName: "dumpstringtables",
    callback: dumpstringtables,
    pHelpString: "Print string tables to console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dumpstringtables_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B480
// Name: _dynamic_initializer_for__stringtabledictionary_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__stringtabledictionary_command__()
{
  ConCommand::ConCommand(
    this: &stringtabledictionary_command,
    pName: "stringtabledictionary",
    callback: stringtabledictionary,
    pHelpString: "Create dictionary for current strings.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stringtabledictionary_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B4B0
// Name: _dynamic_initializer_for__quit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__quit__()
{
  ConCommand::ConCommand(
    this: &quit,
    pName: "quit",
    callback: Host_Quit_f,
    pHelpString: "Exit the engine.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__quit__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B4E0
// Name: _dynamic_initializer_for__cmd_exit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cmd_exit__()
{
  ConCommand::ConCommand(
    this: &cmd_exit,
    pName: "exit",
    callback: Host_Quit_f,
    pHelpString: "Exit the engine.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cmd_exit__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B510
// Name: _dynamic_initializer_for__startvoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startvoicerecord__()
{
  ConCommand::ConCommand(
    this: &startvoicerecord,
    pName: "+voicerecord",
    callback: Host_VoiceRecordStart_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startvoicerecord__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B540
// Name: _dynamic_initializer_for__endvoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endvoicerecord__()
{
  ConCommand::ConCommand(
    this: &endvoicerecord,
    pName: "-voicerecord",
    callback: (void (__cdecl *)())Host_VoiceRecordStop_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endvoicerecord__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B570
// Name: _dynamic_initializer_for__togglevoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__togglevoicerecord__()
{
  ConCommand::ConCommand(
    this: &togglevoicerecord,
    pName: "voicerecord_toggle",
    callback: (void (__cdecl *)())Host_VoiceToggle_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__togglevoicerecord__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B5A0
// Name: _dynamic_initializer_for__crash_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__crash_command__()
{
  ConCommand::ConCommand(
    this: &crash_command,
    pName: "crash",
    callback: crash,
    pHelpString: "Cause the engine to crash (Debug!!)",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__crash_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B5D0
// Name: _dynamic_initializer_for__flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__flush_command__()
{
  ConCommand::ConCommand(
    this: &flush_command,
    pName: "flush",
    callback: flush,
    pHelpString: "Flush unlocked cache memory.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__flush_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B600
// Name: _dynamic_initializer_for__flush_locked_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__flush_locked_command__()
{
  ConCommand::ConCommand(
    this: &flush_locked_command,
    pName: "flush_locked",
    callback: flush_locked,
    pHelpString: "Flush unlocked and locked cache memory.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__flush_locked_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CD20
// Name: _dynamic_initializer_for__loopback_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__loopback_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &loopback_t::s_Allocator,
    blockSize: 2056,
    numElements: 2,
    growMode: 2,
    pszAllocOwner: "loopback_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__loopback_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x10320C90
// Name: _dynamic_atexit_destructor_for__dsp_dist_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_dist_min__()
{
  ConVar::~ConVar(this: &dsp_dist_min);
}

//------------------------------------------------------------------------------
// Address: 0x10320CA0
// Name: _dynamic_atexit_destructor_for__dsp_dist_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_dist_max__()
{
  ConVar::~ConVar(this: &dsp_dist_max);
}

//------------------------------------------------------------------------------
// Address: 0x10320CB0
// Name: _dynamic_atexit_destructor_for__dsp_mix_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_mix_min__()
{
  ConVar::~ConVar(this: &dsp_mix_min);
}

//------------------------------------------------------------------------------
// Address: 0x10320CC0
// Name: _dynamic_atexit_destructor_for__dsp_mix_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_mix_max__()
{
  ConVar::~ConVar(this: &dsp_mix_max);
}

//------------------------------------------------------------------------------
// Address: 0x10320CD0
// Name: _dynamic_atexit_destructor_for__dsp_db_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_db_min__()
{
  ConVar::~ConVar(this: &dsp_db_min);
}

//------------------------------------------------------------------------------
// Address: 0x10320CE0
// Name: _dynamic_atexit_destructor_for__dsp_db_mixdrop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dsp_db_mixdrop__()
{
  ConVar::~ConVar(this: &dsp_db_mixdrop);
}

//------------------------------------------------------------------------------
// Address: 0x103220A0
// Name: _dynamic_atexit_destructor_for__g_VoiceWriter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VoiceWriter__()
{
  CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::~CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>(this: &g_VoiceWriter.m_VoiceWriter);
}

//------------------------------------------------------------------------------
// Address: 0x10322100
// Name: _dynamic_atexit_destructor_for__vox_reload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vox_reload__()
{
  ConCommand::~ConCommand(this: &vox_reload);
}

//------------------------------------------------------------------------------
// Address: 0x10322110
// Name: _dynamic_atexit_destructor_for__sentencegroup_t::s_SymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sentencegroup_t::s_SymbolTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &sentencegroup_t::s_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x10324600
// Name: _dynamic_atexit_destructor_for__g_AreasNetworked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AreasNetworked__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_AreasNetworked);
}

//------------------------------------------------------------------------------
// Address: 0x10324610
// Name: _dynamic_atexit_destructor_for__g_ClustersNetworked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ClustersNetworked__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_ClustersNetworked);
}

//------------------------------------------------------------------------------
// Address: 0x10324620
// Name: _dynamic_atexit_destructor_for__sv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv__()
{
  CGameServer::~CGameServer(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x10324630
// Name: _dynamic_atexit_destructor_for__setmaster__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__setmaster__()
{
  ConCommand::~ConCommand(this: &setmaster);
}

//------------------------------------------------------------------------------
// Address: 0x10324640
// Name: _dynamic_atexit_destructor_for__heartbeat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__heartbeat__()
{
  ConCommand::~ConCommand(this: &heartbeat);
}

//------------------------------------------------------------------------------
// Address: 0x103257F0
// Name: _dynamic_atexit_destructor_for___restart_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___restart_command__()
{
  ConCommand::~ConCommand(this: &restart_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325960
// Name: _dynamic_atexit_destructor_for__listmodels_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__listmodels_command__()
{
  ConCommand::~ConCommand(this: &listmodels_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325970
// Name: _dynamic_atexit_destructor_for__incrementvar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__incrementvar_command__()
{
  ConCommand::~ConCommand(this: &incrementvar_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325980
// Name: _dynamic_atexit_destructor_for__multvar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__multvar_command__()
{
  ConCommand::~ConCommand(this: &multvar_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325990
// Name: _dynamic_atexit_destructor_for__dumpstringtables_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dumpstringtables_command__()
{
  ConCommand::~ConCommand(this: &dumpstringtables_command);
}

//------------------------------------------------------------------------------
// Address: 0x103259A0
// Name: _dynamic_atexit_destructor_for__stringtabledictionary_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stringtabledictionary_command__()
{
  ConCommand::~ConCommand(this: &stringtabledictionary_command);
}

//------------------------------------------------------------------------------
// Address: 0x103259B0
// Name: _dynamic_atexit_destructor_for__quit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__quit__()
{
  ConCommand::~ConCommand(this: &quit);
}

//------------------------------------------------------------------------------
// Address: 0x103259C0
// Name: _dynamic_atexit_destructor_for__cmd_exit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cmd_exit__()
{
  ConCommand::~ConCommand(this: &cmd_exit);
}

//------------------------------------------------------------------------------
// Address: 0x103259D0
// Name: _dynamic_atexit_destructor_for__startvoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startvoicerecord__()
{
  ConCommand::~ConCommand(this: &startvoicerecord);
}

//------------------------------------------------------------------------------
// Address: 0x103259E0
// Name: _dynamic_atexit_destructor_for__endvoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endvoicerecord__()
{
  ConCommand::~ConCommand(this: &endvoicerecord);
}

//------------------------------------------------------------------------------
// Address: 0x103259F0
// Name: _dynamic_atexit_destructor_for__togglevoicerecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__togglevoicerecord__()
{
  ConCommand::~ConCommand(this: &togglevoicerecord);
}

//------------------------------------------------------------------------------
// Address: 0x10325A00
// Name: _dynamic_atexit_destructor_for__crash_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__crash_command__()
{
  ConCommand::~ConCommand(this: &crash_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A10
// Name: _dynamic_atexit_destructor_for__flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flush_command__()
{
  ConCommand::~ConCommand(this: &flush_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A20
// Name: _dynamic_atexit_destructor_for__flush_locked_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flush_locked_command__()
{
  ConCommand::~ConCommand(this: &flush_locked_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326340
// Name: _dynamic_atexit_destructor_for__loopback_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__loopback_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &loopback_t::s_Allocator);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10057830
// Name: bool ReadWaveFile(char const __near *,char __near * __near &,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ReadWaveFile(
        _iobuf *pFilename,
        char **pData,
        int *nDataBytes,
        int *wBitsPerSample,
        int *nChannels,
        int *nSamplesPerSec)
{
  _iobuf *v6; // eax
  _iobuf *v7; // esi
  char *v9; // eax
  int buffer; // [esp+4h] [ebp-4h] BYREF

  v6 = fopen(file: pFilename, mode: "rb");
  v7 = v6;
  if ( v6 == nullptr )
    return 0;
  fseek(stream: v6, offset: 22, whence: 0);
  fread((unsigned __int8 *)&buffer, elementSize: 2u, count: 1u, stream: v7);
  *nChannels = (unsigned __int16)buffer;
  fread((unsigned __int8 *)&buffer, elementSize: 4u, count: 1u, stream: v7);
  *nSamplesPerSec = buffer;
  fseek(stream: v7, offset: 34, whence: 0);
  fread((unsigned __int8 *)&buffer, elementSize: 2u, count: 1u, stream: v7);
  *wBitsPerSample = (unsigned __int16)buffer;
  fseek(stream: v7, offset: 40, whence: 0);
  fread((unsigned __int8 *)&buffer, elementSize: 4u, count: 1u, stream: v7);
  *nDataBytes = buffer;
  fread((unsigned __int8 *)&buffer, elementSize: 4u, count: 1u, stream: v7);
  v9 = (char *)MemAlloc_Alloc(nSize: *nDataBytes);
  *pData = v9;
  if ( v9 != nullptr )
  {
    fread(buffer: (unsigned __int8 *)v9, elementSize: *nDataBytes, count: 1u, stream: v7);
    fclose(stream: v7);
    return 1;
  }
  else
  {
    fclose(stream: v7);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057920
// Name: bool WriteWaveFile(char const __near *,char const __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WriteWaveFile(
        _iobuf *pFilename,
        char *pData,
        unsigned int nBytes,
        int wBitsPerSample,
        int nChannels,
        int nSamplesPerSec)
{
  _iobuf *v6; // eax
  _iobuf *v7; // esi
  int v9; // edi
  int buffer; // [esp+4h] [ebp-4h] BYREF

  v6 = fopen(file: pFilename, mode: "wb");
  v7 = v6;
  if ( v6 == nullptr )
    return 0;
  fwrite(buffer: "RIFF", size: 4u, count: 1u, stream: v6);
  buffer = 0;
  fwrite((unsigned __int8 *)&buffer, size: 4u, count: 1u, stream: v7);
  fwrite(buffer: "WAVE", size: 4u, count: 1u, stream: v7);
  fwrite(buffer: "fmt ", size: 4u, count: 1u, stream: v7);
  buffer = 16;
  fwrite((unsigned __int8 *)&buffer, size: 4u, count: 1u, stream: v7);
  buffer = 1;
  fwrite((unsigned __int8 *)&buffer, size: 2u, count: 1u, stream: v7);
  buffer = (unsigned __int16)nChannels;
  fwrite((unsigned __int8 *)&buffer, size: 2u, count: 1u, stream: v7);
  buffer = nSamplesPerSec;
  fwrite((unsigned __int8 *)&buffer, size: 4u, count: 1u, stream: v7);
  buffer = nSamplesPerSec * nChannels * (wBitsPerSample / 8);
  fwrite((unsigned __int8 *)&buffer, size: 4u, count: 1u, stream: v7);
  buffer = (unsigned __int16)(nChannels * (wBitsPerSample / 8));
  fwrite((unsigned __int8 *)&buffer, size: 2u, count: 1u, stream: v7);
  buffer = (unsigned __int16)wBitsPerSample;
  fwrite((unsigned __int8 *)&buffer, size: 2u, count: 1u, stream: v7);
  fwrite(buffer: "data", size: 4u, count: 1u, stream: v7);
  buffer = nBytes;
  fwrite((unsigned __int8 *)&buffer, size: 4u, count: 1u, stream: v7);
  fwrite(buffer: (unsigned __int8 *)pData, size: nBytes, count: 1u, stream: v7);
  v9 = ftell(stream: v7) - 8;
  fseek(stream: v7, offset: 4, whence: 0);
  buffer = v9;
  fwrite((unsigned __int8 *)&buffer, size: 4u, count: 1u, stream: v7);
  fclose(stream: v7);
  return 1;
}

} // namespace engine_xlsp
