// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_wave_temp.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10044B90
// Name: void WaveCreateTmpFile(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WaveCreateTmpFile(const char *filename, unsigned int rate, int bits, int channels)
{
  void *v4; // eax
  void *v5; // esi
  char tmpfilename[260]; // [esp+4h] [ebp-11Ch] BYREF
  pcmwaveformat_tag fmt; // [esp+108h] [ebp-18h] BYREF
  int chunksize; // [esp+118h] [ebp-8h] BYREF
  int chunkid; // [esp+11Ch] [ebp-4h] BYREF

  V_StripExtension(in: filename, out: tmpfilename, outSize: 260);
  V_DefaultExtension(path: tmpfilename, extension: ".WAV", pathStringLength: 260);
  v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: tmpfilename, a3: "wb", a4: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    chunkid = 1179011410;
    chunksize = 0;
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunkid, a3: 4, a4: v4);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunksize, a3: 4, a4: v5);
    chunkid = 1163280727;
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunkid, a3: 4, a4: v5);
    fmt.wf.wFormatTag = 1;
    fmt.wf.nSamplesPerSec = rate;
    fmt.wf.nChannels = channels;
    fmt.wf.nBlockAlign = 2 * channels;
    fmt.wf.nAvgBytesPerSec = (int)(channels * bits * rate) / 8;
    fmt.wBitsPerSample = bits;
    chunkid = 544501094;
    chunksize = 16;
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunkid, a3: 4, a4: v5);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunksize, a3: 4, a4: v5);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &fmt, a3: 16, a4: v5);
    chunkid = 1635017060;
    chunksize = 0;
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunkid, a3: 4, a4: v5);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunksize, a3: 4, a4: v5);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044D40
// Name: void WaveAppendTmpFile(char const __near *,void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WaveAppendTmpFile(const char *filename, void *pBuffer, int sampleBits, int numSamples)
{
  void *v4; // esi
  char tmpfilename[260]; // [esp+4h] [ebp-104h] BYREF

  V_StripExtension(in: filename, out: tmpfilename, outSize: 260);
  V_DefaultExtension(path: tmpfilename, extension: ".WAV", pathStringLength: 260);
  v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: tmpfilename, a3: "r+b", a4: 0);
  if ( v4 != nullptr )
  {
    g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v4, a3: 0, a4: FILESYSTEM_SEEK_TAIL);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pBuffer, a3: numSamples * sampleBits / 8, a4: v4);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044E00
// Name: void WaveFixupTmpFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WaveFixupTmpFile(const char *filename)
{
  void *v1; // esi
  unsigned int v2; // eax
  char tmpfilename[260]; // [esp+4h] [ebp-10Ch] BYREF
  int size; // [esp+108h] [ebp-8h] BYREF
  int dataSize; // [esp+10Ch] [ebp-4h] BYREF

  V_StripExtension(in: filename, out: tmpfilename, outSize: 260);
  V_DefaultExtension(path: tmpfilename, extension: ".WAV", pathStringLength: 260);
  v1 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: tmpfilename, a3: "r+b", a4: 0);
  if ( v1 != nullptr )
  {
    v2 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v1);
    size = v2 - 8;
    dataSize = v2 - 44;
    g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v1, a3: 4, a4: FILESYSTEM_SEEK_HEAD);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &size, a3: 4, a4: v1);
    g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v1, a3: 40, a4: FILESYSTEM_SEEK_HEAD);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &dataSize, a3: 4, a4: v1);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v1);
  }
  else
  {
    _Warning(a1: "WaveFixupTmpFile( '%s' ) failed to open file for editing\n", tmpfilename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044F10
// Name: movie_fixwave
// Source: json
//------------------------------------------------------------------------------
void __usercall movie_fixwave(int a1@<esi>, const CCommand *args)
{
  const char *v2; // esi
  char tmpfilename[256]; // [esp+0h] [ebp-100h] BYREF

  if ( args->m_nArgc == 2 )
  {
    v2 = args->m_ppArgv[1];
    if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, const char *, _DWORD, int))g_pFileSystem->FileExists)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: v2,
           a3: 0,
           a4: a1) != 0 )
    {
      V_StripExtension(in: v2, out: tmpfilename, outSize: 256);
      V_strncat(pDest: tmpfilename, pSrc: "_fixed", destBufferSize: 0x100u, max_chars_to_copy: -1);
      V_DefaultExtension(path: tmpfilename, extension: ".wav", pathStringLength: 256);
      _Msg(a1: "Copying '%s' to '%s'\n", v2, tmpfilename);
      COM_CopyFile(netpath: v2, cachepath: tmpfilename);
      _Msg(a1: "Performing fixup on '%s'\n", tmpfilename);
      WaveFixupTmpFile(filename: tmpfilename);
    }
    else
    {
      _Warning(a1: "movie_fixwave: File '%s' does not exist\n", v2);
    }
  }
  else
  {
    _Msg(a1: "Usage: movie_fixwave wavname\n");
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100448A0
// Name: void WaveCreateTmpFile(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WaveCreateTmpFile(const char *filename, unsigned int rate, int bits, int channels)
{
  void *v4; // eax
  void *v5; // esi
  char tmpfilename[260]; // [esp+4h] [ebp-11Ch] BYREF
  pcmwaveformat_tag fmt; // [esp+108h] [ebp-18h] BYREF
  int chunksize; // [esp+118h] [ebp-8h] BYREF
  int chunkid; // [esp+11Ch] [ebp-4h] BYREF

  V_StripExtension(in: filename, out: tmpfilename, outSize: 260);
  V_DefaultExtension(path: tmpfilename, extension: ".WAV", pathStringLength: 260);
  v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: tmpfilename, a3: "wb", a4: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    chunkid = 1179011410;
    chunksize = 0;
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunkid, a3: 4, a4: v4);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunksize, a3: 4, a4: v5);
    chunkid = 1163280727;
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunkid, a3: 4, a4: v5);
    fmt.wf.wFormatTag = 1;
    fmt.wf.nSamplesPerSec = rate;
    fmt.wf.nChannels = channels;
    fmt.wf.nBlockAlign = 2 * channels;
    fmt.wf.nAvgBytesPerSec = (int)(channels * bits * rate) / 8;
    fmt.wBitsPerSample = bits;
    chunkid = 544501094;
    chunksize = 16;
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunkid, a3: 4, a4: v5);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunksize, a3: 4, a4: v5);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &fmt, a3: 16, a4: v5);
    chunkid = 1635017060;
    chunksize = 0;
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunkid, a3: 4, a4: v5);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &chunksize, a3: 4, a4: v5);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044A50
// Name: void WaveAppendTmpFile(char const __near *,void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WaveAppendTmpFile(const char *filename, void *pBuffer, int sampleBits, int numSamples)
{
  void *v4; // esi
  char tmpfilename[260]; // [esp+4h] [ebp-104h] BYREF

  V_StripExtension(in: filename, out: tmpfilename, outSize: 260);
  V_DefaultExtension(path: tmpfilename, extension: ".WAV", pathStringLength: 260);
  v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: tmpfilename, a3: "r+b", a4: 0);
  if ( v4 != nullptr )
  {
    g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v4, a3: 0, a4: FILESYSTEM_SEEK_TAIL);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pBuffer, a3: numSamples * sampleBits / 8, a4: v4);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044B10
// Name: void WaveFixupTmpFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WaveFixupTmpFile(const char *filename)
{
  void *v1; // esi
  unsigned int v2; // eax
  char tmpfilename[260]; // [esp+4h] [ebp-10Ch] BYREF
  int size; // [esp+108h] [ebp-8h] BYREF
  int dataSize; // [esp+10Ch] [ebp-4h] BYREF

  V_StripExtension(in: filename, out: tmpfilename, outSize: 260);
  V_DefaultExtension(path: tmpfilename, extension: ".WAV", pathStringLength: 260);
  v1 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: tmpfilename, a3: "r+b", a4: 0);
  if ( v1 != nullptr )
  {
    v2 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v1);
    size = v2 - 8;
    dataSize = v2 - 44;
    g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v1, a3: 4, a4: FILESYSTEM_SEEK_HEAD);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &size, a3: 4, a4: v1);
    g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: v1, a3: 40, a4: FILESYSTEM_SEEK_HEAD);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &dataSize, a3: 4, a4: v1);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v1);
  }
  else
  {
    _Warning(a1: "WaveFixupTmpFile( '%s' ) failed to open file for editing\n", tmpfilename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044C20
// Name: movie_fixwave
// Source: json
//------------------------------------------------------------------------------
void __usercall movie_fixwave(int a1@<esi>, const CCommand *args)
{
  const char *v2; // esi
  char tmpfilename[256]; // [esp+0h] [ebp-100h] BYREF

  if ( args->m_nArgc == 2 )
  {
    v2 = args->m_ppArgv[1];
    if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, const char *, _DWORD, int))g_pFileSystem->FileExists)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: v2,
           a3: 0,
           a4: a1) != 0 )
    {
      V_StripExtension(in: v2, out: tmpfilename, outSize: 256);
      V_strncat(pDest: tmpfilename, pSrc: "_fixed", destBufferSize: 0x100u, max_chars_to_copy: -1);
      V_DefaultExtension(path: tmpfilename, extension: ".wav", pathStringLength: 256);
      _Msg(a1: "Copying '%s' to '%s'\n", v2, tmpfilename);
      COM_CopyFile(netpath: v2, cachepath: tmpfilename);
      _Msg(a1: "Performing fixup on '%s'\n", tmpfilename);
      WaveFixupTmpFile(filename: tmpfilename);
    }
    else
    {
      _Warning(a1: "movie_fixwave: File '%s' does not exist\n", v2);
    }
  }
  else
  {
    _Msg(a1: "Usage: movie_fixwave wavname\n");
  }
}

} // namespace engine_xlsp
