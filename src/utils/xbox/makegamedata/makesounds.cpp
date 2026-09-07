// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makesounds.cpp
// Functions: 25
// ============================================================

#include "utils\xbox\makegamedata\makesounds.h"

//------------------------------------------------------------------------------
// Address: 0x00415980
// Name: public: void xwvHeader_t::SetSampleRate(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall xwvHeader_t::SetSampleRate(xwvHeader_t *this, int sampleRateIn)
{
  if ( sampleRateIn == 11025 )
    this->sampleRate = 0;
  else
    this->sampleRate = (sampleRateIn != 22050) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x004159B0
// Name: bool ReadChunks(char const __near *,int __near &,struct chunk_t __near * const)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ReadChunks(const char *pFileName, int *numChunks, chunk_t *chunks)
{
  unsigned int size; // ebx
  IterateRIFF walk; // [esp+4h] [ebp-28h] BYREF
  InFileRIFF riff; // [esp+1Ch] [ebp-10h] BYREF

  *numChunks = 0;
  InFileRIFF::InFileRIFF(this: &riff, pFileName, io: g_pSndIO);
  if ( riff.m_riffName == 1163280727 )
  {
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    if ( IterateRIFF::ChunkAvailable(this: &walk) )
    {
      while ( 1 )
      {
        chunks[*numChunks].id = CCurveData::GetCount(this: (CVTFTexture *)&walk);
        chunks[*numChunks].size = CChoreoScene::GetNumEvents(this: (CVTFTexture *)&walk);
        size = chunks[*numChunks].size;
        if ( CCurveData::GetCount(this: (CVTFTexture *)&walk) == 544501094 && size < 0x28 )
          size = 40;
        chunks[*numChunks].pData = (unsigned __int8 *)MemAlloc_Alloc(nSize: size);
        memset(dst: chunks[*numChunks].pData, value: 0, count: size);
        IterateRIFF::ChunkRead(this: &walk, pOutput: chunks[*numChunks].pData);
        if ( ++*numChunks >= 256 )
          break;
        IterateRIFF::ChunkNext(this: &walk);
        if ( !IterateRIFF::ChunkAvailable(this: &walk) )
          goto LABEL_9;
      }
      InFileRIFF::~InFileRIFF(this: &riff);
      return 0;
    }
    else
    {
LABEL_9:
      InFileRIFF::~InFileRIFF(this: &riff);
      return 1;
    }
  }
  else
  {
    InFileRIFF::~InFileRIFF(this: &riff);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415AD0
// Name: void ConvertPCMDataChunk8To16(struct chunk_t __near *,struct chunk_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertPCMDataChunk8To16(chunk_t *pFormatChunk, chunk_t *pDataChunk)
{
  unsigned __int8 *pData; // esi
  int v4; // edi
  int v5; // eax
  int v6; // edi
  int v7; // eax
  __int16 v8; // cx
  int v9; // eax
  int sampleCount; // [esp+14h] [ebp+8h]
  __int16 *pOut; // [esp+18h] [ebp+Ch]

  pData = pFormatChunk->pData;
  v4 = *((unsigned __int16 *)pData + 1);
  v5 = pDataChunk->size / ((v4 * *((unsigned __int16 *)pData + 7)) >> 3);
  v6 = 2 * v5 * v4;
  sampleCount = v5;
  pOut = (__int16 *)MemAlloc_Alloc(nSize: v6);
  Convert8To16(
    pInputBuffer: pDataChunk->pData,
    pOutputBuffer: pOut,
    sampleCount,
    channelCount: *((unsigned __int16 *)pData + 1));
  free(pMem: pDataChunk->pData);
  pDataChunk->pData = (unsigned __int8 *)pOut;
  pDataChunk->size = v6;
  *(_WORD *)pData = 1;
  v7 = *((unsigned __int16 *)pData + 1);
  v8 = 2 * v7;
  v9 = 2 * *((_DWORD *)pData + 1) * v7;
  *((_WORD *)pData + 6) = v8;
  *((_WORD *)pData + 7) = 16;
  *((_DWORD *)pData + 2) = v9;
}

//------------------------------------------------------------------------------
// Address: 0x00415B60
// Name: void ConvertADPCMDataChunkTo16(struct chunk_t __near *,struct chunk_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertADPCMDataChunkTo16(chunk_t *pFormatChunk, chunk_t *pDataChunk)
{
  unsigned __int8 *pData; // esi
  int v4; // ebx
  int v5; // eax
  __int16 v6; // dx
  int v7; // eax
  __int16 *pOut; // [esp+18h] [ebp+Ch]

  pData = pFormatChunk->pData;
  v4 = 2
     * ADPCMSampleCount(pFormatChunk: pData, pDataChunk: pDataChunk->pData, dataSize: pDataChunk->size)
     * *((unsigned __int16 *)pData + 1);
  pOut = (__int16 *)MemAlloc_Alloc(nSize: v4);
  DecompressADPCMSamples(
    pFormatChunk: pData,
    pDataChunk: pDataChunk->pData,
    dataSize: pDataChunk->size,
    pOutputBuffer: pOut);
  free(pMem: pDataChunk->pData);
  pDataChunk->pData = (unsigned __int8 *)pOut;
  pDataChunk->size = v4;
  v5 = *((unsigned __int16 *)pData + 1);
  v6 = 2 * v5;
  v7 = *((_DWORD *)pData + 1) * v5;
  *(_WORD *)pData = 1;
  *((_DWORD *)pData + 2) = 2 * v7;
  *((_WORD *)pData + 6) = v6;
  *((_WORD *)pData + 7) = 16;
  pFormatChunk->size = 16;
}

//------------------------------------------------------------------------------
// Address: 0x00415BF0
// Name: void ConvertPCMDataChunk16To22K(struct chunk_t __near *,struct chunk_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertPCMDataChunk16To22K(chunk_t *pFormatChunk, chunk_t *pDataChunk)
{
  unsigned __int8 *pData; // esi
  int v3; // ebx
  __int16 v4; // dx
  int v5; // eax
  __int16 *pOut; // [esp+4h] [ebp-4h]
  int sampleCount; // [esp+10h] [ebp+8h]

  pData = pFormatChunk->pData;
  if ( *((_DWORD *)pData + 1) == 44100 && *((_WORD *)pData + 7) == 16 && *(_WORD *)pData == 1 )
  {
    v3 = *((unsigned __int16 *)pData + 1);
    sampleCount = pDataChunk->size / ((16 * v3) >> 3);
    pOut = (__int16 *)MemAlloc_Alloc(nSize: 2 * sampleCount * v3);
    DecimateSampleRateBy2_16(
      pInputBuffer: (const __int16 *)pDataChunk->pData,
      pOutputBuffer: pOut,
      sampleCount,
      channelCount: v3);
    free(pMem: pDataChunk->pData);
    pDataChunk->pData = (unsigned __int8 *)pOut;
    pDataChunk->size = 2 * *((unsigned __int16 *)pData + 1) * (sampleCount / 2);
    v4 = 2 * *((_WORD *)pData + 1);
    v5 = 44100 * *((unsigned __int16 *)pData + 1);
    *((_DWORD *)pData + 1) = 22050;
    *((_WORD *)pData + 6) = v4;
    *((_DWORD *)pData + 2) = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415CA0
// Name: int FindLoopStart(int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindLoopStart(int samplerChunk, int cueChunk)
{
  int v2; // edx
  int result; // eax
  int *v4; // ecx
  _DWORD *v5; // ecx

  v2 = -1;
  result = -1;
  if ( cueChunk != -1 )
  {
    v4 = (int *)dword_66B2F8[3 * cueChunk];
    if ( *v4 > 0 )
      v2 = v4[6];
  }
  if ( samplerChunk != -1 )
  {
    v5 = (_DWORD *)dword_66B2F8[3 * samplerChunk];
    if ( v5[7] != 0 && v5[10] == 0 )
      result = v5[11];
  }
  if ( v2 > result )
    return v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415CF0
// Name: int FindChunk(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindChunk(unsigned int id)
{
  int result; // eax
  chunk_t *i; // ecx

  result = 0;
  if ( g_numChunks <= 0 )
    return -1;
  for ( i = g_chunks; i->id != id; ++i )
  {
    if ( ++result >= g_numChunks )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415D20
// Name: void PurgeChunks(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PurgeChunks()
{
  int v0; // esi
  void **v1; // edi

  v0 = 0;
  if ( g_numChunks <= 0 )
  {
    g_numChunks = 0;
  }
  else
  {
    v1 = (void **)dword_66B2F8;
    do
    {
      free(pMem: *v1);
      ++v0;
      v1 += 3;
    }
    while ( v0 < g_numChunks );
    g_numChunks = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415D60
// Name: bool CreateMp3EncodedFile(struct AudioConversion_t __near *,char const __near *,char const __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateMp3EncodedFile(
        AudioConversion_t *pAudioConversion,
        const char *pSourceFileName,
        const char *pDestinationFileName,
        int nBitRate,
        bool bLoop,
        unsigned int bStereo)
{
  const char *v6; // ecx
  const char *v7; // eax
  const char *v8; // eax
  DWORD LastError; // esi
  char Buffer[2048]; // [esp+0h] [ebp-1054h] BYREF
  char string[2048]; // [esp+800h] [ebp-854h] BYREF
  _STARTUPINFOA dst; // [esp+1000h] [ebp-54h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+1044h] [ebp-10h] BYREF

  v6 = "-mp3stereo 0";
  if ( (_BYTE)bStereo == 0 )
    v6 = pDefaultValue;
  v7 = "-loop";
  if ( !bLoop )
    v7 = pDefaultValue;
  sprintf_s(
    string,
    sizeInBytes: 0x800u,
    format: " -v 0 -in %s -out %s -mp3 %d %s %s -nomsf -x",
    pSourceFileName,
    pDestinationFileName,
    nBitRate,
    v7,
    v6);
  memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
  memset(&ProcessInformation, 0, sizeof(ProcessInformation));
  dst.cb = 68;
  dst.dwFlags = 256;
  v8 = CUtlString::operator char const *(this: &pAudioConversion->mp3Encoder);
  if ( CreateProcessA(
         lpApplicationName: v8,
         lpCommandLine: string,
         lpProcessAttributes: nullptr,
         lpThreadAttributes: nullptr,
         bInheritHandles: false,
         dwCreationFlags: 0x4000000u,
         lpEnvironment: nullptr,
         lpCurrentDirectory: nullptr,
         lpStartupInfo: &dst,
         lpProcessInformation: &ProcessInformation) )
  {
    WaitForSingleObject(hHandle: ProcessInformation.hProcess, dwMilliseconds: 0xFFFFFFFF);
    GetExitCodeProcess(hProcess: ProcessInformation.hProcess, lpExitCode: &bStereo);
    CloseHandle(hObject: ProcessInformation.hProcess);
    CloseHandle(hObject: ProcessInformation.hThread);
    return bStereo == 0;
  }
  else
  {
    LastError = GetLastError();
    FormatMessageA(
      dwFlags: 0x1200u,
      lpSource: nullptr,
      dwMessageId: LastError,
      dwLanguageId: 0x400u,
      lpBuffer: Buffer,
      nSize: 0x800u,
      Arguments: nullptr);
    _Warning(a1: " Encoding process failed with error: (%d) - %s\n", LastError, Buffer);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415EA0
// Name: bool DownsampleIfNecessary(char const __near *,struct tWAVEFORMATEX __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DownsampleIfNecessary(
        const char *pSourceName,
        tWAVEFORMATEX *pFormat,
        int nFormatChunk,
        int nDataChunk,
        bool bForceTo22K)
{
  if ( pFormat->nSamplesPerSec != 44100 || !bForceTo22K )
    return 0;
  _Msg(a1: "Converting to 22K '%s'\n", pSourceName);
  ConvertPCMDataChunk16To22K(pFormatChunk: &g_chunks[nFormatChunk], pDataChunk: &g_chunks[nDataChunk]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00415EF0
// Name: enum mad_flow MAD_InputCallback(void __near *,struct mad_stream __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MAD_InputCallback(const unsigned __int8 **pData, mad_stream *pStream)
{
  if ( pData[1] == nullptr )
    return 16;
  mad_stream_buffer(stream: pStream, buffer: *pData, length: (unsigned int)pData[1]);
  pData[1] = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00415F30
// Name: enum mad_flow MAD_ErrorCallback(void __near *,struct mad_stream __near *,struct mad_frame __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MAD_ErrorCallback(const unsigned __int8 **pData, mad_stream *pStream)
{
  const char *v3; // eax
  const unsigned __int8 *v4; // [esp-4h] [ebp-Ch]

  if ( pStream->error == MAD_ERROR_LOSTSYNC
    && (pStream->this_frame == *pData || V_strncmp(s1: (const char *)pStream->this_frame, s2: "TAG", count: 3) == 0) )
  {
    return 0;
  }
  v4 = (const unsigned __int8 *)(pStream->this_frame - *pData);
  v3 = mad_stream_errorstr(stream: pStream);
  _Warning(a1: "MAD decoding error 0x%04x (%s) at byte offset %u\n", pStream->error, v3, v4);
  return 17;
}

//------------------------------------------------------------------------------
// Address: 0x00415FA0
// Name: int AlignToBoundary(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AlignToBoundary(CUtlBuffer *buf, int alignment)
{
  int m_Put; // ebx
  int v4; // esi
  int v5; // ebx
  unsigned __int8 padByte; // [esp+Bh] [ebp-1h] BYREF

  padByte = 0;
  CUtlBuffer::SeekPut(this: buf, type: SEEK_TAIL, offset: 0);
  m_Put = buf->m_Put;
  if ( alignment <= 1 )
    return buf->m_Put;
  v4 = ~(alignment - 1) & (m_Put + alignment - 1);
  CUtlBuffer::EnsureCapacity(this: buf, num: v4);
  if ( v4 - m_Put > 0 )
  {
    v5 = v4 - m_Put;
    do
    {
      CUtlBuffer::Put(this: buf, pMem: &padByte, size: 1);
      --v5;
    }
    while ( v5 != 0 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00416000
// Name: bool SampleToXMABlockOffset(unsigned long,unsigned long const __near *,unsigned long,unsigned long __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SampleToXMABlockOffset(
        unsigned int dwSampleIndex,
        const unsigned int *pdwSeekTable,
        unsigned int nEntries,
        unsigned int *out_pBlockIndex,
        unsigned int *out_pOffset)
{
  char v5; // dl
  unsigned int i; // ecx

  v5 = 0;
  for ( i = 0; i < nEntries; ++i )
  {
    if ( dwSampleIndex < _byteswap_ulong(pdwSeekTable[i]) )
    {
      *out_pBlockIndex = i;
      v5 = 1;
    }
    if ( v5 != 0 )
    {
      if ( *out_pBlockIndex == 0 )
      {
        *out_pOffset = dwSampleIndex;
        return v5;
      }
      *out_pOffset = dwSampleIndex - _byteswap_ulong(pdwSeekTable[*out_pBlockIndex - 1]);
      return v5;
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00416070
// Name: bool EncodeAsXMA(char const __near *,class CUtlBuffer __near &,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EncodeAsXMA(
        const char *pDebugName,
        CUtlBuffer *targetBuff,
        int quality,
        bool bXmaSeekTable,
        bool bDownsampled)
{
  int v5; // ecx
  chunk_t *v6; // edx
  int v7; // esi
  signed int v8; // ecx
  chunk_t *v9; // edx
  int v10; // ecx
  chunk_t *v11; // edx
  int v12; // ecx
  chunk_t *v13; // edx
  int v14; // edi
  int v15; // ecx
  chunk_t *v16; // edx
  int v17; // eax
  int v18; // esi
  int v19; // edi
  __int16 v20; // dx
  unsigned int v21; // ebx
  const void *v22; // edx
  unsigned int v23; // ebx
  signed int v24; // ecx
  int v26; // esi
  int v28; // esi
  unsigned int v29; // esi
  unsigned int v30; // ecx
  unsigned int v31; // edx
  unsigned int v32; // eax
  int v33; // esi
  int v34; // eax
  unsigned __int16 v35; // ax
  unsigned __int8 v36; // dl
  WAVEFORMATEXTENSIBLE wfx; // [esp+8h] [ebp-D0h] BYREF
  XMAENCODERSTREAM inputStream; // [esp+30h] [ebp-A8h] BYREF
  unsigned int loopBlock; // [esp+6Ch] [ebp-6Ch]
  int vdatChunk; // [esp+70h] [ebp-68h]
  xwvHeader_t header; // [esp+74h] [ebp-64h] BYREF
  unsigned int loopBlockStartOffset; // [esp+A4h] [ebp-34h] BYREF
  unsigned int numLeadingSamples; // [esp+A8h] [ebp-30h]
  int vdatSize; // [esp+ACh] [ebp-2Ch]
  int loopStart; // [esp+B0h] [ebp-28h]
  unsigned int loopBlockStartIndex; // [esp+B4h] [ebp-24h] BYREF
  unsigned int loopBlockEndIndex; // [esp+B8h] [ebp-20h] BYREF
  unsigned int loopBlockEndOffset; // [esp+BCh] [ebp-1Ch] BYREF
  unsigned int XMA2FormatSize; // [esp+C0h] [ebp-18h] BYREF
  unsigned int XMADataSize; // [esp+C4h] [ebp-14h] BYREF
  unsigned int XMASeekTableSize; // [esp+C8h] [ebp-10h] BYREF
  void *pXMAData; // [esp+CCh] [ebp-Ch] BYREF
  unsigned int *pXMASeekTable; // [esp+D0h] [ebp-8h] BYREF
  XMA2WAVEFORMATEX *pXMA2Format; // [esp+D4h] [ebp-4h] BYREF

  v5 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_5:
    v7 = -1;
  }
  else
  {
    v6 = g_chunks;
    while ( v6->id != 544501094 )
    {
      ++v5;
      ++v6;
      if ( v5 >= g_numChunks )
        goto LABEL_5;
    }
    v7 = v5;
  }
  v8 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_10:
    loopBlockStartIndex = -1;
  }
  else
  {
    v9 = g_chunks;
    while ( v9->id != 1635017060 )
    {
      ++v8;
      ++v9;
      if ( v8 >= g_numChunks )
        goto LABEL_10;
    }
    loopBlockStartIndex = v8;
  }
  if ( v7 == -1 || loopBlockStartIndex == -1 )
    return 0;
  v10 = 0;
  vdatSize = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_17:
    vdatChunk = -1;
  }
  else
  {
    v11 = g_chunks;
    while ( v11->id != 1413563478 )
    {
      ++v10;
      ++v11;
      if ( v10 >= g_numChunks )
        goto LABEL_17;
    }
    vdatChunk = v10;
    if ( v10 != -1 )
      vdatSize = dword_66B2F4[3 * v10];
  }
  v12 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_26:
    v14 = -1;
  }
  else
  {
    v13 = g_chunks;
    while ( v13->id != 543520099 )
    {
      ++v12;
      ++v13;
      if ( v12 >= g_numChunks )
        goto LABEL_26;
    }
    v14 = v12;
  }
  v15 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_31:
    v15 = -1;
  }
  else
  {
    v16 = g_chunks;
    while ( v16->id != 1819307379 )
    {
      ++v15;
      ++v16;
      if ( v15 >= g_numChunks )
        goto LABEL_31;
    }
  }
  v17 = FindLoopStart(samplerChunk: v15, cueChunk: v14);
  v18 = 6 * v7;
  v19 = *(int *)((char *)dword_66B2F8 + 2 * v18);
  v18 *= 2;
  loopStart = v17;
  v20 = 2 * *(_WORD *)(v19 + 2);
  *(_DWORD *)(v19 + 8) = 2 * *(_DWORD *)(v19 + 4) * *(unsigned __int16 *)(v19 + 2);
  *(_WORD *)(v19 + 12) = v20;
  *(_WORD *)(v19 + 16) = 0;
  memset(&inputStream, 0, sizeof(inputStream));
  v21 = *(int *)((char *)dword_66B2F4 + v18);
  memcpy(dst: (unsigned __int8 *)&wfx, src: *(unsigned __int8 **)((char *)dword_66B2F8 + v18), count: v21);
  if ( v21 < 0x28 )
    memset(dst: (unsigned __int8 *)&wfx + v21, value: 0, count: 40 - v21);
  v22 = (const void *)dword_66B2F8[3 * loopBlockStartIndex];
  v23 = dword_66B2F4[3 * loopBlockStartIndex];
  inputStream.Format.Format = wfx.Format;
  v24 = loopStart;
  inputStream.pBuffer = v22;
  inputStream.BufferSize = v23;
  if ( loopStart != -1 )
  {
    if ( bDownsampled )
    {
      loopStart /= 2;
      v24 /= 2;
    }
    inputStream.LoopStart = v24;
    numLeadingSamples = 2 * *(unsigned __int16 *)(v19 + 2);
    inputStream.LoopLength = v23 / numLeadingSamples - v24;
  }
  pXMAData = nullptr;
  XMADataSize = 0;
  pXMA2Format = nullptr;
  XMA2FormatSize = 0;
  pXMASeekTable = nullptr;
  XMASeekTableSize = 0;
  loopBlockEndIndex = 2;
  if ( v24 != -1 )
    loopBlockEndIndex = 3;
  v26 = 1;
  while ( XAudio2XMAEncoder(
            InputStreamCount: 1u,
            pStreams: &inputStream,
            Compression: quality,
            Flags: loopBlockEndIndex,
            BlockSizeInKbytes: 2u,
            ppEncodedBuffer: &pXMAData,
            pEncodedBufferSize: &XMADataSize,
            ppEncodedBufferFormat: &pXMA2Format,
            pEncodedBufferFormatSize: &XMA2FormatSize,
            ppSeekTable: &pXMASeekTable,
            pSeekTableSize: &XMASeekTableSize) < 0 )
  {
    if ( quality != 100 )
    {
      quality += 5;
      if ( quality > 100 )
        quality = 100;
      _Warning(a1: "XMA Encoding Error on '%s', Attempting increasing quality to %d\n", pDebugName, quality);
      ++v26;
      pXMAData = nullptr;
      XMADataSize = 0;
      pXMA2Format = nullptr;
      XMA2FormatSize = 0;
      pXMASeekTable = nullptr;
      XMASeekTableSize = 0;
      if ( v26 < 10 )
        continue;
    }
    free(pMem: pXMAData);
    free(pMem: pXMA2Format);
    free(pMem: pXMASeekTable);
    return 0;
  }
  if ( v26 <= 1 )
    _Msg(a1: "XMA Encoding Success on '%s' at quality %d\n", pDebugName, quality);
  else
    _Warning(a1: "XMA Encoding Success on '%s' at quality %d\n", pDebugName, quality);
  v28 = loopStart;
  loopBlock = 0;
  numLeadingSamples = 0;
  loopBlockEndIndex = 0;
  if ( loopStart == -1 )
    goto LABEL_68;
  loopBlockStartIndex = 0;
  loopBlockStartOffset = 0;
  if ( SampleToXMABlockOffset(
         dwSampleIndex: pXMA2Format->LoopBegin,
         pdwSeekTable: pXMASeekTable,
         nEntries: XMASeekTableSize >> 2,
         out_pBlockIndex: &loopBlockStartIndex,
         out_pOffset: &loopBlockStartOffset) == 0 )
  {
    _Warning(a1: "XMA Loop Encoding Error on '%s', loop %d\n", pDebugName, v28);
LABEL_63:
    free(pMem: pXMAData);
    free(pMem: pXMA2Format);
    free(pMem: pXMASeekTable);
    return 0;
  }
  v29 = pXMA2Format->LoopBegin + pXMA2Format->LoopLength;
  v30 = loopBlockStartIndex;
  v31 = loopBlockStartOffset;
  loopBlock = loopBlockStartIndex;
  numLeadingSamples = loopBlockStartOffset;
  if ( v29 >= pXMA2Format->SamplesEncoded )
  {
    v32 = loopBlockEndIndex;
  }
  else
  {
    loopBlockEndIndex = 0;
    loopBlockEndOffset = 0;
    if ( SampleToXMABlockOffset(
           dwSampleIndex: v29,
           pdwSeekTable: pXMASeekTable,
           nEntries: XMASeekTableSize >> 2,
           out_pBlockIndex: &loopBlockEndIndex,
           out_pOffset: &loopBlockEndOffset) == 0 )
    {
      _Warning(a1: "XMA Loop Encoding Error on '%s', loop %d\n", pDebugName, loopStart);
      goto LABEL_63;
    }
    if ( loopBlockEndIndex != pXMA2Format->BlockCount - 1 )
    {
      _Warning(
        a1: "XMA Loop Encoding Error on '%s', block end is %d/%d\n",
        pDebugName,
        loopBlockEndOffset,
        pXMA2Format->BlockCount);
      free(pMem: pXMAData);
      free(pMem: pXMA2Format);
      free(pMem: pXMASeekTable);
      return 0;
    }
    v30 = loopBlockStartIndex;
    v31 = loopBlockStartOffset;
    v32 = pXMA2Format->SamplesEncoded - v29;
    loopBlockEndIndex = v32;
  }
  if ( v30 > 0x7FFF )
  {
    _Warning(a1: "XMA Loop Encoding Error on '%s', loop block exceeds 16 bits %d\n", pDebugName, v30);
    goto LABEL_63;
  }
  if ( v31 > 0x7FFF )
  {
    _Warning(a1: "XMA Loop Encoding Error on '%s', leading samples exceeds 16 bits %d\n", pDebugName, v31);
    free(pMem: pXMAData);
    free(pMem: pXMA2Format);
    free(pMem: pXMASeekTable);
    return 0;
  }
  if ( v32 <= 0x7FFF )
  {
LABEL_68:
    memset(dst: (unsigned __int8 *)&header, value: 0, count: sizeof(header));
    v33 = 4 * (XMADataSize >> 11);
    if ( v33 == XMASeekTableSize )
    {
      if ( loopStart != -1 && vdatSize != 0 )
        _Warning(a1: "XMA Warning: Unexpected loop in vo data '%s'!\n", pDebugName);
      if ( !bXmaSeekTable )
        v33 = 0;
      header.id = 542529368;
      header.version = 0x4000000;
      header.headerSize = 805306368;
      header.staticDataSize = _byteswap_ulong(v33 + vdatSize);
      loopBlockEndOffset = (v33 + vdatSize + 2095) & 0xFFFFF800;
      header.dataOffset = _byteswap_ulong(loopBlockEndOffset);
      header.dataSize = _byteswap_ulong(XMADataSize);
      loopBlockEndOffset = pXMA2Format->SamplesEncoded;
      header.numDecodedSamples = _byteswap_ulong(loopBlockEndOffset);
      if ( loopStart == -1 )
      {
        v34 = -1;
      }
      else
      {
        loopBlockEndOffset = pXMA2Format->LoopBegin;
        v34 = _byteswap_ulong(loopBlockEndOffset);
      }
      header.loopStart = v34;
      LOBYTE(v35) = BYTE1(loopBlock);
      HIBYTE(v35) = loopBlock;
      header.loopBlock = v35;
      LOBYTE(v35) = BYTE1(numLeadingSamples);
      HIBYTE(v35) = numLeadingSamples;
      header.numLeadingSamples = v35;
      LOBYTE(v35) = BYTE1(loopBlockEndIndex);
      HIBYTE(v35) = loopBlockEndIndex;
      header.numTrailingSamples = v35;
      LOBYTE(v35) = BYTE1(vdatSize);
      HIBYTE(v35) = vdatSize;
      header.vdatSize = v35;
      *(_WORD *)&header.format = 4097;
      xwvHeader_t::SetSampleRate(this: &header, sampleRateIn: *(_DWORD *)(v19 + 4));
      v36 = *(_BYTE *)(v19 + 2);
      header.quality = quality;
      header.channels = v36;
      header.bHasSeekTable = v33 != 0;
      CUtlBuffer::Put(this: targetBuff, pMem: &header, size: 48);
      if ( v33 != 0 )
        CUtlBuffer::Put(this: targetBuff, pMem: pXMASeekTable, size: v33);
      if ( vdatSize != 0 )
        CUtlBuffer::Put(
          this: targetBuff,
          pMem: (const void *)dword_66B2F8[3 * vdatChunk],
          size: dword_66B2F4[3 * vdatChunk]);
      AlignToBoundary(buf: targetBuff, alignment: 2048);
      CUtlBuffer::Put(this: targetBuff, pMem: pXMAData, size: XMADataSize);
      AlignToBoundary(buf: targetBuff, alignment: 2048);
      free(pMem: pXMAData);
      free(pMem: pXMA2Format);
      free(pMem: pXMASeekTable);
      DeleteTemporaryFiles(pFileMask: "LoopStrm*");
      DeleteTemporaryFiles(pFileMask: "EncStrm*");
      return 1;
    }
    else
    {
      _Warning(a1: "XMA Error: Unexpected seek table calculation in '%s'!\n", pDebugName);
      free(pMem: pXMAData);
      free(pMem: pXMA2Format);
      free(pMem: pXMASeekTable);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "XMA Loop Encoding Error on '%s', trailing samples exceeds 16 bits %d\n", pDebugName, v32);
    free(pMem: pXMAData);
    free(pMem: pXMA2Format);
    free(pMem: pXMASeekTable);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416720
// Name: bool EncodeAsPCM(char const __near *,class CUtlBuffer __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EncodeAsPCM(const char *pTargetName, CUtlBuffer *targetBuff, bool bDownsampled)
{
  int v3; // eax
  chunk_t *v4; // edx
  int v5; // edx
  chunk_t *v6; // esi
  int v7; // ebx
  int v9; // eax
  chunk_t *v10; // esi
  chunk_t *v11; // esi
  int v12; // eax
  chunk_t *v13; // edx
  int v14; // edx
  chunk_t *v15; // edi
  int v16; // eax
  unsigned __int16 v17; // ax
  int v18; // eax
  unsigned __int8 v19; // al
  int i; // ecx
  __int16 v21; // ax
  int m_Put; // ebx
  int v23; // esi
  xwvHeader_t header; // [esp+0h] [ebp-44h] BYREF
  int vdatChunk; // [esp+30h] [ebp-14h]
  int loopStart; // [esp+34h] [ebp-10h]
  int sampleCount; // [esp+38h] [ebp-Ch]
  int vdatSize; // [esp+3Ch] [ebp-8h]
  char pMem; // [esp+43h] [ebp-1h] BYREF

  v3 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v4 = g_chunks;
    while ( v4->id != 544501094 )
    {
      ++v3;
      ++v4;
      if ( v3 >= g_numChunks )
        goto LABEL_5;
    }
  }
  v5 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_10:
    v5 = -1;
  }
  else
  {
    v6 = g_chunks;
    while ( v6->id != 1635017060 )
    {
      ++v5;
      ++v6;
      if ( v5 >= g_numChunks )
        goto LABEL_10;
    }
  }
  if ( v3 == -1 || v5 == -1 )
    return 0;
  v7 = dword_66B2F8[3 * v3];
  if ( *(_WORD *)(v7 + 14) != 16 )
    return 0;
  v9 = 0;
  vdatSize = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_19:
    vdatChunk = -1;
  }
  else
  {
    v10 = g_chunks;
    while ( v10->id != 1413563478 )
    {
      ++v9;
      ++v10;
      if ( v9 >= g_numChunks )
        goto LABEL_19;
    }
    vdatChunk = v9;
    if ( v9 != -1 )
      vdatSize = dword_66B2F4[3 * v9];
  }
  v11 = &g_chunks[v5];
  memset(dst: (unsigned __int8 *)&header, value: 0, count: sizeof(header));
  sampleCount = v11->size / (2 * *(unsigned __int16 *)(v7 + 2));
  header.id = 542529368;
  header.version = 0x4000000;
  header.headerSize = 805306368;
  header.staticDataSize = _byteswap_ulong(vdatSize);
  loopStart = (vdatSize + 2095) & 0xFFFFF800;
  header.dataOffset = _byteswap_ulong(loopStart);
  loopStart = v11->size;
  header.dataSize = _byteswap_ulong(loopStart);
  header.numDecodedSamples = _byteswap_ulong(sampleCount);
  v12 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_26:
    v12 = -1;
  }
  else
  {
    v13 = g_chunks;
    while ( v13->id != 543520099 )
    {
      ++v12;
      ++v13;
      if ( v12 >= g_numChunks )
        goto LABEL_26;
    }
  }
  v14 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_31:
    v14 = -1;
  }
  else
  {
    v15 = g_chunks;
    while ( v15->id != 1819307379 )
    {
      ++v14;
      ++v15;
      if ( v14 >= g_numChunks )
        goto LABEL_31;
    }
  }
  v16 = FindLoopStart(samplerChunk: v14, cueChunk: v12);
  loopStart = v16;
  if ( bDownsampled && v16 > 0 )
    loopStart = v16 / 2;
  header.loopStart = _byteswap_ulong(loopStart);
  *(_DWORD *)&header.loopBlock = 0;
  header.numTrailingSamples = 0;
  LOBYTE(v17) = BYTE1(vdatSize);
  HIBYTE(v17) = vdatSize;
  header.vdatSize = v17;
  *(_WORD *)&header.format = 4096;
  v18 = *(_DWORD *)(v7 + 4);
  if ( v18 == 11025 )
    v19 = 0;
  else
    v19 = (v18 != 22050) + 1;
  header.sampleRate = v19;
  header.channels = *(_BYTE *)(v7 + 2);
  header.quality = 100;
  CUtlBuffer::Put(this: targetBuff, pMem: &header, size: 48);
  if ( vdatSize != 0 )
    CUtlBuffer::Put(
      this: targetBuff,
      pMem: (const void *)dword_66B2F8[3 * vdatChunk],
      size: dword_66B2F4[3 * vdatChunk]);
  AlignToBoundary(buf: targetBuff, alignment: 2048);
  for ( i = 0; i < sampleCount * *(unsigned __int16 *)(v7 + 2); ++i )
  {
    vdatChunk = *(unsigned __int16 *)&v11->pData[2 * i];
    LOBYTE(v21) = BYTE1(vdatChunk);
    HIBYTE(v21) = vdatChunk;
    *(_WORD *)&v11->pData[2 * i] = v21;
  }
  CUtlBuffer::Put(this: targetBuff, pMem: v11->pData, size: v11->size);
  pMem = 0;
  CUtlBuffer::SeekPut(this: targetBuff, type: SEEK_TAIL, offset: 0);
  m_Put = targetBuff->m_Put;
  CUtlBuffer::EnsureCapacity(this: targetBuff, num: (m_Put + 2047) & 0xFFFFF800);
  v23 = ((m_Put + 2047) & 0xFFFFF800) - m_Put;
  if ( v23 > 0 )
  {
    do
    {
      CUtlBuffer::Put(this: targetBuff, &pMem, size: 1);
      --v23;
    }
    while ( v23 != 0 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004169D0
// Name: bool EncodeAsMp3(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EncodeAsMp3(const char *pTargetName, CUtlBuffer *targetBuff, CUtlBuffer *mp3Buffer)
{
  int v3; // eax
  chunk_t *v4; // edx
  int v5; // edx
  chunk_t *v6; // esi
  int v7; // edi
  int v8; // ebx
  int v10; // eax
  chunk_t *v11; // edx
  int v12; // esi
  int v13; // ecx
  int v14; // edi
  int v15; // eax
  chunk_t *v16; // edx
  int v17; // edx
  chunk_t *v18; // esi
  unsigned __int16 v19; // ax
  int v20; // eax
  unsigned __int8 v21; // al
  xwvHeader_t header; // [esp+0h] [ebp-40h] BYREF
  int nNumberOfDecodedSamplesInBytes; // [esp+30h] [ebp-10h]
  unsigned int m_nAllocationCount; // [esp+34h] [ebp-Ch]
  int vdatChunk; // [esp+38h] [ebp-8h]
  int vdatSize; // [esp+3Ch] [ebp-4h]

  v3 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v4 = g_chunks;
    while ( v4->id != 544501094 )
    {
      ++v3;
      ++v4;
      if ( v3 >= g_numChunks )
        goto LABEL_5;
    }
  }
  v5 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_10:
    v7 = -1;
  }
  else
  {
    v6 = g_chunks;
    while ( v6->id != 1635017060 )
    {
      ++v5;
      ++v6;
      if ( v5 >= g_numChunks )
        goto LABEL_10;
    }
    v7 = v5;
  }
  if ( v3 == -1 || v7 == -1 )
    return 0;
  v8 = dword_66B2F8[3 * v3];
  if ( *(_WORD *)(v8 + 14) != 16 )
    return 0;
  v10 = 0;
  vdatSize = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_20:
    vdatChunk = -1;
  }
  else
  {
    v11 = g_chunks;
    while ( v11->id != 1413563478 )
    {
      ++v10;
      ++v11;
      if ( v10 >= g_numChunks )
        goto LABEL_20;
    }
    vdatChunk = v10;
    if ( v10 != -1 )
      vdatSize = dword_66B2F4[3 * v10];
  }
  memset(dst: (unsigned __int8 *)&header, value: 0, count: sizeof(header));
  v12 = 2 * *(unsigned __int16 *)(v8 + 2);
  v13 = dword_66B2F4[3 * v7] / v12;
  header.id = 542529368;
  header.version = 0x4000000;
  header.headerSize = 805306368;
  v14 = vdatSize;
  header.staticDataSize = _byteswap_ulong(vdatSize);
  m_nAllocationCount = (vdatSize + 2095) & 0xFFFFF800;
  header.dataOffset = _byteswap_ulong(m_nAllocationCount);
  if ( v13 % 1152 != 0 )
    v13 = v13 - v13 % 1152 + 1152;
  nNumberOfDecodedSamplesInBytes = v12 * v13;
  m_nAllocationCount = mp3Buffer->m_Memory.m_nAllocationCount;
  header.dataSize = _byteswap_ulong(m_nAllocationCount);
  header.numDecodedSamples = _byteswap_ulong(v12 * v13);
  v15 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_29:
    v15 = -1;
  }
  else
  {
    v16 = g_chunks;
    while ( v16->id != 543520099 )
    {
      ++v15;
      ++v16;
      if ( v15 >= g_numChunks )
        goto LABEL_29;
    }
  }
  v17 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_34:
    v17 = -1;
  }
  else
  {
    v18 = g_chunks;
    while ( v18->id != 1819307379 )
    {
      ++v17;
      ++v18;
      if ( v17 >= g_numChunks )
        goto LABEL_34;
    }
  }
  header.loopStart = FindLoopStart(samplerChunk: v17, cueChunk: v15);
  *(_DWORD *)&header.loopBlock = 0;
  header.numTrailingSamples = 0;
  LOBYTE(v19) = BYTE1(vdatSize);
  HIBYTE(v19) = vdatSize;
  header.vdatSize = v19;
  *(_WORD *)&header.format = 4099;
  v20 = *(_DWORD *)(v8 + 4);
  if ( v20 == 11025 )
    v21 = 0;
  else
    v21 = (v20 != 22050) + 1;
  header.sampleRate = v21;
  header.channels = *(_BYTE *)(v8 + 2);
  header.quality = 100;
  CUtlBuffer::Put(this: targetBuff, pMem: &header, size: 48);
  if ( v14 != 0 )
    CUtlBuffer::Put(
      this: targetBuff,
      pMem: (const void *)dword_66B2F8[3 * vdatChunk],
      size: dword_66B2F4[3 * vdatChunk]);
  AlignToBoundary(buf: targetBuff, alignment: 2048);
  CUtlBuffer::Put(this: targetBuff, pMem: mp3Buffer->m_Memory.m_pMemory, size: mp3Buffer->m_Memory.m_nAllocationCount);
  AlignToBoundary(buf: targetBuff, alignment: 2048);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00416C40
// Name: bool GetPreloadData_WAV(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetPreloadData_WAV(const char *pFilename, CUtlBuffer *fileBufferIn, CUtlBuffer *preloadBufferOut)
{
  unsigned __int8 *m_pMemory; // esi

  m_pMemory = fileBufferIn->m_Memory.m_pMemory;
  if ( *(_DWORD *)fileBufferIn->m_Memory.m_pMemory == 542529368
    && *((_DWORD *)m_pMemory + 1) == 0x4000000
    && *((_DWORD *)m_pMemory + 2) == 805306368 )
  {
    CUtlBuffer::Purge(this: preloadBufferOut);
    CUtlBuffer::Put(
      this: preloadBufferOut,
      pMem: fileBufferIn->m_Memory.m_pMemory,
      size: _byteswap_ulong(*((_DWORD *)m_pMemory + 2)) + _byteswap_ulong(*((_DWORD *)m_pMemory + 3)));
    return 1;
  }
  else
  {
    _Warning(a1: "Can't preload: '%s', has bad version\n", pFilename);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416CC0
// Name: bool CompressVDAT(struct chunk_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CompressVDAT(chunk_t *pChunk)
{
  CSentence *v1; // eax
  CSentence *v2; // edi
  unsigned __int8 *v3; // edi
  unsigned int m_Put; // edi
  unsigned __int8 *v5; // eax
  unsigned __int8 *m_pMemory; // [esp-10h] [ebp-7Ch]
  unsigned int v8; // [esp-8h] [ebp-74h]
  CUtlBuffer buf; // [esp+8h] [ebp-64h] BYREF
  CUtlBuffer binaryBuffer; // [esp+38h] [ebp-34h] BYREF
  unsigned int compressedSize; // [esp+68h] [ebp-4h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::EnsureCapacity(this: &buf, num: pChunk->size);
  memcpy(dst: buf.m_Memory.m_pMemory, src: pChunk->pData, count: pChunk->size);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: pChunk->size);
  v1 = (CSentence *)MemAlloc_Alloc(nSize: 0x4Cu);
  if ( v1 != nullptr )
    v2 = CSentence::CSentence(this: v1);
  else
    v2 = nullptr;
  CSentence::InitFromDataChunk(this: v2, data: buf.m_Memory.m_pMemory, size: buf.m_Put);
  CSentence::MakeRuntimeOnly(this: v2);
  CUtlBuffer::CUtlBuffer(this: &binaryBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::SetBigEndian(this: &binaryBuffer, bigEndian: true);
  CSentence::CacheSaveToBuffer(this: v2, buf: &binaryBuffer, version: 5);
  if ( v2 != nullptr )
  {
    CSentence::~CSentence(this: v2);
    free(pMem: v2);
  }
  compressedSize = 0;
  v3 = LZMA_Compress(
         pInput: binaryBuffer.m_Memory.m_pMemory,
         inputSize: binaryBuffer.m_Put,
         pOutputSize: &compressedSize,
         dictionarySize: 0x12u);
  if ( v3 != nullptr )
  {
    _Msg(a1: "CompressVDAT: Compressed %d to %d\n", binaryBuffer.m_Put, compressedSize);
    free(pMem: pChunk->pData);
    pChunk->size = compressedSize;
    pChunk->pData = v3;
  }
  else
  {
    free(pMem: pChunk->pData);
    m_Put = binaryBuffer.m_Put;
    v8 = binaryBuffer.m_Put;
    pChunk->size = binaryBuffer.m_Put;
    v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v8);
    m_pMemory = binaryBuffer.m_Memory.m_pMemory;
    pChunk->pData = v5;
    memcpy(dst: v5, src: m_pMemory, count: m_Put);
  }
  if ( binaryBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( binaryBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: binaryBuffer.m_Memory.m_pMemory);
      binaryBuffer.m_Memory.m_pMemory = nullptr;
    }
    binaryBuffer.m_Memory.m_nAllocationCount = 0;
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00416E40
// Name: bool EncodeAsFakeMp3(char const __near *,class CUtlBuffer __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EncodeAsFakeMp3(const char *pTargetName, CUtlBuffer *targetBuff, bool bDownsampled)
{
  int v3; // eax
  chunk_t *v4; // edx
  int v5; // edx
  chunk_t *v6; // esi
  tWAVEFORMATEX *v7; // edi
  bool v8; // zf
  int v10; // eax
  chunk_t *v11; // esi
  chunk_t *v12; // esi
  int nChannels; // ecx
  int v14; // ecx
  int v15; // ebx
  int v16; // esi
  int v17; // edi
  int v18; // eax
  chunk_t *v19; // edx
  int v20; // edx
  chunk_t *v21; // edi
  int LoopStart; // eax
  tWAVEFORMATEX *v23; // edi
  int v24; // edx
  int v25; // ecx
  int v26; // edx
  unsigned __int16 v27; // ax
  signed int i; // edi
  __int16 v29; // ax
  tWAVEFORMATEX *v30; // edx
  unsigned int v31; // edi
  int m_Put; // ebx
  int v33; // edi
  xwvHeader_t header; // [esp+0h] [ebp-54h] BYREF
  int nSizeInBytesOfAllValidSamples; // [esp+30h] [ebp-24h]
  int nNumberOfDecodedSamplesInBytes; // [esp+34h] [ebp-20h]
  chunk_t *pDataChunk; // [esp+38h] [ebp-1Ch]
  int vdatChunk; // [esp+3Ch] [ebp-18h]
  int nLoopStartInBytes; // [esp+40h] [ebp-14h]
  int nNumLeadingBytes; // [esp+44h] [ebp-10h]
  tWAVEFORMATEX *pFormat; // [esp+48h] [ebp-Ch]
  int vdatSize; // [esp+4Ch] [ebp-8h]
  char pMem; // [esp+53h] [ebp-1h] BYREF

  v3 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v4 = g_chunks;
    while ( v4->id != 544501094 )
    {
      ++v3;
      ++v4;
      if ( v3 >= g_numChunks )
        goto LABEL_5;
    }
  }
  v5 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_10:
    v5 = -1;
  }
  else
  {
    v6 = g_chunks;
    while ( v6->id != 1635017060 )
    {
      ++v5;
      ++v6;
      if ( v5 >= g_numChunks )
        goto LABEL_10;
    }
  }
  if ( v3 == -1 || v5 == -1 )
    return 0;
  v7 = (tWAVEFORMATEX *)dword_66B2F8[3 * v3];
  v8 = v7->wBitsPerSample == 16;
  pFormat = v7;
  if ( !v8 )
    return 0;
  v10 = 0;
  vdatSize = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_19:
    vdatChunk = -1;
  }
  else
  {
    v11 = g_chunks;
    while ( v11->id != 1413563478 )
    {
      ++v10;
      ++v11;
      if ( v10 >= g_numChunks )
        goto LABEL_19;
    }
    vdatChunk = v10;
    if ( v10 != -1 )
      vdatSize = dword_66B2F4[3 * v10];
  }
  v12 = &g_chunks[v5];
  pDataChunk = v12;
  memset(dst: (unsigned __int8 *)&header, value: 0, count: sizeof(header));
  nChannels = v7->nChannels;
  nSizeInBytesOfAllValidSamples = v12->size;
  v14 = 2 * nChannels;
  v15 = nSizeInBytesOfAllValidSamples / v14;
  header.id = 542529368;
  header.version = 0x4000000;
  header.headerSize = 805306368;
  header.staticDataSize = _byteswap_ulong(vdatSize);
  nNumberOfDecodedSamplesInBytes = (vdatSize + 2095) & 0xFFFFF800;
  header.dataOffset = _byteswap_ulong(nNumberOfDecodedSamplesInBytes);
  v16 = 1152 * v14;
  v17 = nSizeInBytesOfAllValidSamples / v14;
  if ( nSizeInBytesOfAllValidSamples / v14 % 1152 != 0 )
    v17 = v17 - nSizeInBytesOfAllValidSamples / v14 % 1152 + 1152;
  nNumberOfDecodedSamplesInBytes = v14 * v17;
  nLoopStartInBytes = nNumberOfDecodedSamplesInBytes + 4 * (nNumberOfDecodedSamplesInBytes / v16);
  header.dataSize = _byteswap_ulong(nLoopStartInBytes);
  header.numDecodedSamples = _byteswap_ulong(v14 * v17);
  v18 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_28:
    v18 = -1;
  }
  else
  {
    v19 = g_chunks;
    while ( v19->id != 543520099 )
    {
      ++v18;
      ++v19;
      if ( v18 >= g_numChunks )
        goto LABEL_28;
    }
  }
  v20 = 0;
  if ( g_numChunks <= 0 )
  {
LABEL_33:
    v20 = -1;
  }
  else
  {
    v21 = g_chunks;
    while ( v21->id != 1819307379 )
    {
      ++v20;
      ++v21;
      if ( v20 >= g_numChunks )
        goto LABEL_33;
    }
  }
  LoopStart = FindLoopStart(samplerChunk: v20, cueChunk: v18);
  if ( bDownsampled && LoopStart > 0 )
    LoopStart /= 2;
  v23 = pFormat;
  nLoopStartInBytes = 2 * LoopStart * pFormat->nChannels;
  header.loopStart = _byteswap_ulong(nLoopStartInBytes);
  header.loopBlock = 0;
  v24 = nLoopStartInBytes % v16;
  v25 = 0;
  nLoopStartInBytes = 0;
  nNumLeadingBytes = v24;
  v26 = nSizeInBytesOfAllValidSamples % v16;
  if ( nSizeInBytesOfAllValidSamples % v16 != 0 )
  {
    v25 = v16 - v26;
    nLoopStartInBytes = v16 - v26;
  }
  if ( nNumLeadingBytes <= 0x7FFF )
  {
    if ( v25 <= 0x7FFF )
    {
      LOBYTE(v27) = BYTE1(nNumLeadingBytes);
      HIBYTE(v27) = nNumLeadingBytes;
      header.numLeadingSamples = v27;
      LOBYTE(v27) = BYTE1(nLoopStartInBytes);
      HIBYTE(v27) = nLoopStartInBytes;
      header.numTrailingSamples = v27;
      LOBYTE(v27) = BYTE1(vdatSize);
      HIBYTE(v27) = vdatSize;
      header.vdatSize = v27;
      *(_WORD *)&header.format = 4219;
      xwvHeader_t::SetSampleRate(this: &header, sampleRateIn: pFormat->nSamplesPerSec);
      header.channels = v23->nChannels;
      header.quality = 100;
      CUtlBuffer::Put(this: targetBuff, pMem: &header, size: 48);
      if ( vdatSize != 0 )
        CUtlBuffer::Put(
          this: targetBuff,
          pMem: (const void *)dword_66B2F8[3 * vdatChunk],
          size: dword_66B2F4[3 * vdatChunk]);
      AlignToBoundary(buf: targetBuff, alignment: 2048);
      for ( i = 0; i < v15 * pFormat->nChannels; ++i )
      {
        nSizeInBytesOfAllValidSamples = *(unsigned __int16 *)&pDataChunk->pData[2 * i];
        LOBYTE(v29) = BYTE1(nSizeInBytesOfAllValidSamples);
        HIBYTE(v29) = nSizeInBytesOfAllValidSamples;
        v30 = pFormat;
        *(_WORD *)&pDataChunk->pData[2 * i] = v29;
        if ( i % (1152 * v30->nChannels) == 0 )
        {
          if ( (targetBuff->m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: targetBuff, pFmt: "%d", 305419896);
          else
            CUtlBuffer::PutTypeBin<int>(this: targetBuff, src: 305419896);
        }
        if ( (targetBuff->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: targetBuff, pFmt: "%hd", *(__int16 *)&pDataChunk->pData[2 * i]);
        else
          CUtlBuffer::PutTypeBin<short>(this: targetBuff, src: *(_WORD *)&pDataChunk->pData[2 * i]);
      }
      if ( i < (unsigned int)nNumberOfDecodedSamplesInBytes >> 1 )
      {
        v31 = ((unsigned int)nNumberOfDecodedSamplesInBytes >> 1) - i;
        do
        {
          if ( (targetBuff->m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: targetBuff, pFmt: "%hd", 0);
          else
            CUtlBuffer::PutTypeBin<short>(this: targetBuff, src: 0);
          --v31;
        }
        while ( v31 != 0 );
      }
      pMem = 0;
      CUtlBuffer::SeekPut(this: targetBuff, type: SEEK_TAIL, offset: 0);
      m_Put = targetBuff->m_Put;
      CUtlBuffer::EnsureCapacity(this: targetBuff, num: (m_Put + 2047) & 0xFFFFF800);
      v33 = ((m_Put + 2047) & 0xFFFFF800) - m_Put;
      if ( v33 > 0 )
      {
        do
        {
          CUtlBuffer::Put(this: targetBuff, &pMem, size: 1);
          --v33;
        }
        while ( v33 != 0 );
      }
      return 1;
    }
    else
    {
      _Warning(a1: "Fake-MP3 Loop Encoding Error on '%s', trailing samples exceeds 16 bits %d\n", pTargetName, v25);
      return 0;
    }
  }
  else
  {
    _Warning(
      a1: "Fake-MP3 Loop Encoding Error on '%s', leading samples exceeds 16 bits %d\n",
      pTargetName,
      nNumLeadingBytes);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417240
// Name: enum mad_flow MAD_OutputCallback(void __near *,struct mad_header const __near *,struct mad_pcm __near *)
// Source: json
//------------------------------------------------------------------------------
mad_flow __cdecl MAD_OutputCallback(const int *pData, const mad_header *pHeader, mad_pcm *pPCM)
{
  unsigned int channels; // ecx
  unsigned int length; // edi
  int v7; // eax
  int v8; // ecx
  CUtlBuffer *v9; // esi
  int v10; // eax
  int v11; // eax
  __int16 v12; // di
  int v13; // eax
  int v14; // eax
  __int16 v15; // di
  unsigned int nChannels; // [esp+8h] [ebp-Ch]
  unsigned __int16 inputBuffer[2]; // [esp+Ch] [ebp-8h] BYREF
  unsigned int nSamples; // [esp+10h] [ebp-4h]
  int *left_ch; // [esp+1Ch] [ebp+8h]
  const int *right_ch; // [esp+24h] [ebp+10h]

  if ( pData[14] == 0 )
  {
    *((_DWORD *)pData + 14) = pPCM->samplerate;
    *((_DWORD *)pData + 15) = pPCM->channels;
  }
  channels = pPCM->channels;
  length = pPCM->length;
  right_ch = pPCM->samples[1];
  left_ch = pPCM->samples[0];
  v7 = 2 * channels * length;
  nChannels = channels;
  v8 = pData[3];
  if ( v7 + pData[6] > v8 )
    CUtlBuffer::EnsureCapacity(this: (CUtlBuffer *)(pData + 2), num: (v8 + v7 + 0x7FFF) & 0xFFFF8000);
  if ( length != 0 )
  {
    v9 = (CUtlBuffer *)(pData + 2);
    while ( 1 )
    {
      v10 = *left_ch + 4096;
      nSamples = length - 1;
      if ( v10 < 0x10000000 )
      {
        if ( v10 < -268435456 )
          v10 = -268435456;
      }
      else
      {
        v10 = 0xFFFFFFF;
      }
      ++left_ch;
      v11 = v10 >> 13;
      v12 = v11;
      if ( (v9->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v9, pFmt: "%hd", (__int16)v11);
      }
      else
      {
        *(_DWORD *)inputBuffer = (unsigned __int16)v11;
        if ( CUtlBuffer::CheckPut(this: v9, nSize: 2) )
        {
          if ( (*(_BYTE *)&v9->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned short>(
              this: &v9->m_Byteswap,
              outputBuffer: &v9->m_Memory.m_pMemory[v9->m_Put - v9->m_nOffset],
              (unsigned __int8 *)inputBuffer,
              count: 1);
          else
            *(_WORD *)&v9->m_Memory.m_pMemory[v9->m_Put - v9->m_nOffset] = v12;
          v9->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: v9, nPut: v9->m_Put);
        }
      }
      if ( nChannels == 2 )
      {
        v13 = *right_ch + 4096;
        if ( v13 < 0x10000000 )
        {
          if ( v13 < -268435456 )
            v13 = -268435456;
        }
        else
        {
          v13 = 0xFFFFFFF;
        }
        ++right_ch;
        v14 = v13 >> 13;
        v15 = v14;
        if ( (v9->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v9, pFmt: "%hd", (__int16)v14);
        }
        else
        {
          *(_DWORD *)inputBuffer = (unsigned __int16)v14;
          if ( CUtlBuffer::CheckPut(this: v9, nSize: 2) )
          {
            if ( (*(_BYTE *)&v9->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned short>(
                this: &v9->m_Byteswap,
                outputBuffer: &v9->m_Memory.m_pMemory[v9->m_Put - v9->m_nOffset],
                (unsigned __int8 *)inputBuffer,
                count: 1);
            else
              *(_WORD *)&v9->m_Memory.m_pMemory[v9->m_Put - v9->m_nOffset] = v15;
            v9->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v9, nPut: v9->m_Put);
          }
        }
      }
      if ( nSamples == 0 )
        break;
      length = nSamples;
    }
  }
  return MAD_FLOW_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x004174E0
// Name: BuildAudioConversionRules
// Source: json
//------------------------------------------------------------------------------
void BuildAudioConversionRules()
{
  int v0; // eax
  const char *v1; // eax
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  KeyValues *FirstSubKey; // ebx
  int v5; // edi
  const char *Name; // eax
  int v7; // esi
  KeyValues *NextKey; // edi
  const char *v9; // ebx
  AudioConversion_t *v10; // ebx
  AudioConversion_t *v11; // ebx
  AudioConversion_t *v12; // ebx
  AudioConversion_t *v13; // ebx
  AudioConversion_t *v14; // ebx
  AudioConversion_t *v15; // ebx
  AudioConversion_t *v16; // ebx
  AudioConversion_t *v17; // ebx
  AudioConversion_t *v18; // ebx
  AudioConversion_t *v19; // ebx
  const char *String; // eax
  char szCleanName[260]; // [esp+0h] [ebp-240h] BYREF
  char szScriptPath[260]; // [esp+104h] [ebp-13Ch] BYREF
  CUtlBuffer sourceBuf; // [esp+208h] [ebp-38h] BYREF
  KeyValues *pKV; // [esp+238h] [ebp-8h]
  KeyValues *pSubKey; // [esp+23Ch] [ebp-4h]

  if ( g_AudioRules.m_Size == 0 )
  {
    v0 = CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int>>::InsertBefore(this: &g_AudioRules, elem: 0);
    CUtlString::operator=(this: &g_AudioRules.m_Memory.m_pMemory[v0].audioPath, src: pDefaultValue);
    v1 = "scripts/audiorules_ps3.xsc";
    if ( !g_bSonyPS3 )
      v1 = "scripts/audiorules_xbox.xsc";
    FindScriptFile(pFilename: v1, pOutBuff: szScriptPath, nOutBuffSize: 260, bCanFallback: true);
    CUtlBuffer::CUtlBuffer(this: &sourceBuf, growSize: 0, initSize: 0, nFlags: 1);
    if ( g_pFullFileSystem->ReadFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: szScriptPath,
           a3: nullptr,
           a4: &sourceBuf,
           a5: 0,
           a6: 0,
           a7: nullptr) )
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
      {
        v3 = KeyValues::KeyValues(this: v2, setName: pDefaultValue);
        pKV = v3;
      }
      else
      {
        pKV = nullptr;
        v3 = nullptr;
      }
      if ( KeyValues::LoadFromBuffer(
             this: v3,
             resourceName: "audiorules",
             buf: &sourceBuf,
             pFileSystem: nullptr,
             pPathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
        pSubKey = FirstSubKey;
        if ( FirstSubKey != nullptr )
        {
          while ( 1 )
          {
            v5 = CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int>>::InsertBefore(
                   this: &g_AudioRules,
                   elem: g_AudioRules.m_Size);
            Name = KeyValues::GetName(this: FirstSubKey);
            V_ComposeFileName(path: g_szModPath, filename: Name, dest: szCleanName, destSize: 260);
            V_FixSlashes(pname: szCleanName, separator: 92);
            v7 = v5;
            CUtlString::operator=(this: &g_AudioRules.m_Memory.m_pMemory[v5].audioPath, src: szCleanName);
            NextKey = KeyValues::GetFirstSubKey(this: FirstSubKey);
            if ( NextKey != nullptr )
            {
              do
              {
                v9 = KeyValues::GetName(this: NextKey);
                if ( _V_stricmp(s1: v9, s2: "XmaQuality") != 0 )
                {
                  if ( _V_stricmp(s1: v9, s2: "forceTo22K") != 0 )
                  {
                    if ( _V_stricmp(s1: v9, s2: "xmaSeekTable") != 0 )
                    {
                      if ( _V_stricmp(s1: v9, s2: "convertToMp3") != 0 )
                      {
                        if ( _V_stricmp(s1: v9, s2: "skipMp3ConversionIfSizeIsLessThan") != 0 )
                        {
                          if ( _V_stricmp(s1: v9, s2: "skipMp3ConversionIfLoopedSound") != 0 )
                          {
                            if ( _V_stricmp(s1: v9, s2: "skipMp3ConversionIfSoundNotLoopingFromBeginning") != 0 )
                            {
                              if ( _V_stricmp(s1: v9, s2: "mp3BitRate") != 0 )
                              {
                                if ( _V_stricmp(s1: v9, s2: "useFakeMp3") != 0 )
                                {
                                  if ( _V_stricmp(s1: v9, s2: "mp3Encoder") != 0 )
                                  {
                                    _Error(this: (ISceneTokenProcessor *)&stru_58EDAC, a2: v9, szScriptPath);
                                  }
                                  else
                                  {
                                    v19 = &g_AudioRules.m_Memory.m_pMemory[v7];
                                    String = KeyValues::GetString(
                                               this: NextKey,
                                               keyName: nullptr,
                                               defaultValue: pDefaultValue);
                                    CUtlString::operator=(this: &v19->mp3Encoder, src: String);
                                  }
                                }
                                else
                                {
                                  v18 = &g_AudioRules.m_Memory.m_pMemory[v7];
                                  v18->bFakeMp3 = KeyValues::GetInt(this: NextKey, keyName: nullptr, defaultValue: 0) != 0;
                                }
                              }
                              else
                              {
                                v17 = &g_AudioRules.m_Memory.m_pMemory[v7];
                                v17->nMp3BitRate = KeyValues::GetInt(this: NextKey, keyName: nullptr, defaultValue: 0);
                              }
                            }
                            else
                            {
                              v16 = &g_AudioRules.m_Memory.m_pMemory[v7];
                              v16->bSkipMp3ConversionIfSoundNotLoopingFromBeginning = KeyValues::GetInt(
                                                                                        this: NextKey,
                                                                                        keyName: nullptr,
                                                                                        defaultValue: 0) != 0;
                            }
                          }
                          else
                          {
                            v15 = &g_AudioRules.m_Memory.m_pMemory[v7];
                            v15->bSkipMp3ConversionIfLoopedSound = KeyValues::GetInt(
                                                                     this: NextKey,
                                                                     keyName: nullptr,
                                                                     defaultValue: 0) != 0;
                          }
                        }
                        else
                        {
                          v14 = &g_AudioRules.m_Memory.m_pMemory[v7];
                          v14->nSkipMp3ConversionIfSizeIsLessThan = KeyValues::GetInt(
                                                                      this: NextKey,
                                                                      keyName: nullptr,
                                                                      defaultValue: 0);
                        }
                      }
                      else
                      {
                        v13 = &g_AudioRules.m_Memory.m_pMemory[v7];
                        v13->bConvertToMp3 = KeyValues::GetInt(this: NextKey, keyName: nullptr, defaultValue: 0) != 0;
                      }
                    }
                    else
                    {
                      v12 = &g_AudioRules.m_Memory.m_pMemory[v7];
                      v12->bXmaSeekTable = KeyValues::GetInt(this: NextKey, keyName: nullptr, defaultValue: 0) != 0;
                    }
                  }
                  else
                  {
                    v11 = &g_AudioRules.m_Memory.m_pMemory[v7];
                    v11->bForceTo22K = KeyValues::GetInt(this: NextKey, keyName: nullptr, defaultValue: 0) != 0;
                  }
                }
                else
                {
                  v10 = &g_AudioRules.m_Memory.m_pMemory[v7];
                  v10->iXmaQuality = KeyValues::GetInt(this: NextKey, keyName: nullptr, defaultValue: 0);
                }
                NextKey = KeyValues::GetNextKey(this: NextKey);
              }
              while ( NextKey != nullptr );
              FirstSubKey = pSubKey;
            }
            pSubKey = KeyValues::GetNextKey(this: FirstSubKey);
            if ( pSubKey == nullptr )
              break;
            FirstSubKey = pSubKey;
          }
          v3 = pKV;
        }
        if ( v3 != nullptr )
          KeyValues::deleteThis(this: v3);
        if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
      }
      else
      {
        _Error(this: (ISceneTokenProcessor *)&stru_58DCE4, a2: szScriptPath);
        if ( v3 != nullptr )
          KeyValues::deleteThis(this: v3);
        if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
      }
    }
    else
    {
      _Warning(a1: "Missing audiorules script file '%s'\n", szScriptPath);
      if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417940
// Name: struct AudioConversion_t __near * GetAudioConversion(char const __near *)
// Source: json
//------------------------------------------------------------------------------
AudioConversion_t *__cdecl GetAudioConversion(const char *pSourceName)
{
  AudioConversion_t *result; // eax
  int v2; // esi
  int i; // edi
  const char *v4; // eax
  AudioConversion_t *pConversion; // [esp+4h] [ebp-4h]

  BuildAudioConversionRules();
  result = g_AudioRules.m_Memory.m_pMemory;
  v2 = 1;
  pConversion = g_AudioRules.m_Memory.m_pMemory;
  if ( g_AudioRules.m_Size > 1 )
  {
    for ( i = 1; ; ++i )
    {
      v4 = CUtlString::operator char const *(this: &g_AudioRules.m_Memory.m_pMemory[i].audioPath);
      if ( V_stristr(pStr: pSourceName, pSearch: v4) != nullptr )
        break;
      if ( ++v2 >= g_AudioRules.m_Size )
        return pConversion;
    }
    return &pConversion[v2];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004179C0
// Name: bool CreateTargetFile_WAV(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_WAV(char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  char *v3; // esi
  AudioConversion_t *AudioConversion; // edi
  int v5; // ebx
  int v7; // edx
  chunk_t *v8; // eax
  chunk_t *v9; // eax
  int iXmaQuality; // edx
  bool v11; // al
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  chunk_t *v16; // ecx
  tWAVEFORMATEX *v17; // edi
  int wFormatTag; // ecx
  int v19; // eax
  AudioConversion_t *v20; // ebx
  int Chunk; // ecx
  int v22; // eax
  char v23; // al
  int v24; // eax
  int LoopStart; // eax
  bool v26; // zf
  int nMp3BitRate; // eax
  int v28; // [esp-4h] [ebp-294h]
  char fullSourcePath[260]; // [esp+Ch] [ebp-284h] BYREF
  char mp3FullSourcePath[260]; // [esp+110h] [ebp-180h] BYREF
  CUtlBuffer mp3Buffer; // [esp+214h] [ebp-7Ch] BYREF
  CUtlBuffer targetBuff; // [esp+244h] [ebp-4Ch] BYREF
  BOOL bXmaSeekTable; // [esp+274h] [ebp-1Ch]
  BOOL bForceTo22K; // [esp+278h] [ebp-18h]
  AudioConversion_t *bDownsampled; // [esp+27Ch] [ebp-14h]
  int nFormatChunk; // [esp+280h] [ebp-10h]
  unsigned int bStereo; // [esp+284h] [ebp-Ch]
  int dataChunk; // [esp+288h] [ebp-8h]
  bool bSuccess; // [esp+28Fh] [ebp-1h]

  v3 = pSourceName;
  if ( _fullpath(UserBuf: fullSourcePath, path: pSourceName, maxlen: 0x104u) != nullptr )
    v3 = fullSourcePath;
  AudioConversion = GetAudioConversion(pSourceName: v3);
  v5 = 0;
  bDownsampled = AudioConversion;
  g_numChunks = 0;
  if ( ReadChunks(pFileName: v3, numChunks: &g_numChunks, chunks: g_chunks) == 0 )
  {
    _Warning(a1: "No RIFF Chunks on '%s'\n", v3);
    return false;
  }
  v7 = 0;
  if ( g_numChunks <= 0 )
    goto LABEL_9;
  v8 = g_chunks;
  while ( v8->id != 544501094 )
  {
    ++v7;
    ++v8;
    if ( v7 >= g_numChunks )
      goto LABEL_9;
  }
  nFormatChunk = v7;
  if ( v7 == -1 )
  {
LABEL_9:
    _Warning(a1: "RIFF Format Chunk not found on '%s'\n", v3);
    return false;
  }
  v9 = g_chunks;
  while ( v9->id != 1635017060 )
  {
    ++v5;
    ++v9;
    if ( v5 >= g_numChunks )
      goto LABEL_15;
  }
  if ( v5 == -1 )
  {
LABEL_15:
    _Warning(a1: "RIFF Data Chunk not found on '%s'\n", v3);
    return false;
  }
  iXmaQuality = AudioConversion->iXmaQuality;
  v11 = AudioConversion->bXmaSeekTable;
  LOBYTE(bForceTo22K) = AudioConversion->bForceTo22K;
  dataChunk = iXmaQuality;
  LOBYTE(bXmaSeekTable) = v11;
  if ( IsLocalizedPath(pFileName: v3) != 0 )
    LOBYTE(bForceTo22K) = 1;
  v12 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 40))(a1: v12, a2: "-forceto22k") != 0 )
    LOBYTE(bForceTo22K) = 1;
  v13 = _CommandLine();
  v14 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v13 + 28))(a1: v13, a2: "-xmaquality", a3: dataChunk);
  dataChunk = v14;
  if ( v14 >= 0 )
  {
    if ( v14 > 100 )
      dataChunk = 100;
  }
  else
  {
    dataChunk = 0;
  }
  v15 = 0;
  if ( g_numChunks > 0 )
  {
    v16 = g_chunks;
    while ( v16->id != 1413563478 )
    {
      ++v15;
      ++v16;
      if ( v15 >= g_numChunks )
        goto LABEL_29;
    }
    if ( v15 != -1 && CompressVDAT(pChunk: &g_chunks[v15]) == 0 )
    {
      _Warning(a1: "Compress VDAT Error on '%s'\n", v3);
      return false;
    }
  }
LABEL_29:
  v17 = (tWAVEFORMATEX *)dword_66B2F8[3 * nFormatChunk];
  wFormatTag = v17->wFormatTag;
  v19 = nFormatChunk;
  if ( wFormatTag == 1 )
  {
    if ( v17->wBitsPerSample == 8 )
      ConvertPCMDataChunk8To16(pFormatChunk: &g_chunks[v19], pDataChunk: &g_chunks[v5]);
LABEL_37:
    CUtlBuffer::CUtlBuffer(this: &targetBuff, growSize: 0, initSize: 0, nFlags: 0);
    bSuccess = false;
    if ( g_bSonyPS3 )
    {
      v20 = bDownsampled;
      Chunk = FindChunk(id: 0x61746164u);
      v22 = 0;
      dataChunk = Chunk;
      if ( Chunk >= 0 )
        v22 = dword_66B2F4[3 * Chunk];
      LOBYTE(bDownsampled) = 0;
      if ( (signed int)(((v22 + 2047) & 0xFFFFF800) + 2048) <= v20->nSkipMp3ConversionIfSizeIsLessThan )
      {
        _Msg(a1: "File '%s' too small (%d bytes). Don't encode in MP3.\n", v3, v22);
LABEL_42:
        LOBYTE(bStereo) = DownsampleIfNecessary(
                            pSourceName: v3,
                            pFormat: v17,
                            nFormatChunk,
                            nDataChunk: dataChunk,
                            bForceTo22K);
        v23 = EncodeAsPCM(pTargetName: v3, &targetBuff, bDownsampled: bStereo);
        goto LABEL_62;
      }
      v28 = FindChunk(id: 0x20657563u);
      v24 = FindChunk(id: 0x6C706D73u);
      LoopStart = FindLoopStart(samplerChunk: v24, cueChunk: v28);
      if ( LoopStart >= 0 )
      {
        v26 = !v20->bSkipMp3ConversionIfLoopedSound;
        LOBYTE(bDownsampled) = 1;
        if ( !v26 )
        {
          _Msg(a1: "File '%s' is looping. Don't encode in MP3.\n", v3);
          goto LABEL_42;
        }
        if ( LoopStart != 0 && v20->bSkipMp3ConversionIfSoundNotLoopingFromBeginning )
        {
          _Msg(a1: "File '%s' is looping at the position %d. Don't encode in MP3.\n", v3, LoopStart);
          goto LABEL_42;
        }
      }
      if ( !v20->bConvertToMp3 )
        goto LABEL_42;
      if ( v20->bFakeMp3 )
      {
        _Msg(a1: "Encode file '%s' as Fake MP3.\n", v3);
        LOBYTE(bDownsampled) = DownsampleIfNecessary(
                                 pSourceName: v3,
                                 pFormat: v17,
                                 nFormatChunk,
                                 nDataChunk: dataChunk,
                                 bForceTo22K);
        v23 = EncodeAsFakeMp3(pTargetName: v3, &targetBuff, (bool)bDownsampled);
      }
      else
      {
        strcpy(mp3FullSourcePath, v3);
        V_SetExtension(path: mp3FullSourcePath, extension: ".msf", pathStringLength: 260);
        nMp3BitRate = v20->nMp3BitRate;
        LOBYTE(bStereo) = v17->nChannels == 2;
        if ( (_BYTE)bStereo == 0 )
          nMp3BitRate /= 2;
        if ( v17->nSamplesPerSec <= 0x5622 )
          nMp3BitRate /= 2;
        if ( CreateMp3EncodedFile(
               pAudioConversion: v20,
               pSourceFileName: v3,
               pDestinationFileName: mp3FullSourcePath,
               nBitRate: nMp3BitRate,
               bLoop: (bool)bDownsampled,
               bStereo) )
        {
          CUtlBuffer::CUtlBuffer(this: &mp3Buffer, growSize: 0, initSize: 0, nFlags: 0);
          if ( ReadFileToBuffer(
                 pSourceName: mp3FullSourcePath,
                 buffer: &mp3Buffer,
                 bText: false,
                 bNoOpenFailureWarning: false) )
          {
            bSuccess = EncodeAsMp3(pTargetName: v3, &targetBuff, &mp3Buffer);
          }
          CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &mp3Buffer);
          if ( bSuccess )
            goto LABEL_63;
        }
        _Warning(a1: "ERROR: Could not encode the file '%s' in MP3. Trying encoding with no compression.\n", v3);
        LOBYTE(bStereo) = DownsampleIfNecessary(
                            pSourceName: v3,
                            pFormat: v17,
                            nFormatChunk,
                            nDataChunk: dataChunk,
                            bForceTo22K);
        v23 = EncodeAsPCM(pTargetName: v3, &targetBuff, bDownsampled: bStereo);
      }
    }
    else
    {
      LOBYTE(bStereo) = DownsampleIfNecessary(pSourceName: v3, pFormat: v17, nFormatChunk, nDataChunk: v5, bForceTo22K);
      v23 = EncodeAsXMA(pDebugName: v3, &targetBuff, quality: dataChunk, bXmaSeekTable, bDownsampled: bStereo);
    }
LABEL_62:
    bSuccess = v23;
    if ( v23 == 0 )
    {
LABEL_64:
      PurgeChunks();
      CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &targetBuff);
      return bSuccess;
    }
LABEL_63:
    WriteBufferToFile(pTargetName, buffer: &targetBuff, bWriteToZip, writeMode: g_WriteModeForConversions);
    goto LABEL_64;
  }
  if ( wFormatTag == 2 )
  {
    ConvertADPCMDataChunkTo16(pFormatChunk: &g_chunks[v19], pDataChunk: &g_chunks[v5]);
    goto LABEL_37;
  }
  _Warning(a1: "Unknown RIFF Format on '%s'\n", v3);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00417EA0
// Name: bool CreateTargetFile_MP3(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_MP3(char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  char *v3; // esi
  int v5; // edi
  ConVar *v6; // ecx
  AudioConversion_t *AudioConversion; // edi
  char fullSourcePath[260]; // [esp+4h] [ebp-2F4h] BYREF
  char wavFilename[260]; // [esp+108h] [ebp-1F0h] BYREF
  mad_decoder madDecoder; // [esp+20Ch] [ebp-ECh] BYREF
  CUtlBuffer targetBuffer; // [esp+240h] [ebp-B8h] BYREF
  CUtlBuffer sourceBuffer; // [esp+270h] [ebp-88h] BYREF
  mad_buffer madBuffer; // [esp+2A0h] [ebp-58h] BYREF
  tWAVEFORMATEX waveFormat; // [esp+2E0h] [ebp-18h] BYREF
  bool bSuccess; // [esp+2F7h] [ebp-1h]

  v3 = pSourceName;
  V_StripExtension(in: pSourceName, out: wavFilename, outSize: 260);
  V_SetExtension(path: wavFilename, extension: ".wav", pathStringLength: 260);
  if ( DoesFileExist(pFilename: wavFilename) != 0
    && CreateTargetFile_WAV(pSourceName: wavFilename, pTargetName, bWriteToZip) )
  {
    return true;
  }
  CUtlBuffer::CUtlBuffer(this: &sourceBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(pSourceName, buffer: &sourceBuffer, bText: false, bNoOpenFailureWarning: false) )
  {
    CUtlBuffer::CUtlBuffer(this: &madBuffer.pcmBuffer, growSize: 0, initSize: 0, nFlags: 0);
    madBuffer.pData = sourceBuffer.m_Memory.m_pMemory;
    madBuffer.nSampleRate = 0;
    madBuffer.nChannels = 0;
    madBuffer.nLength = sourceBuffer.m_Put;
    CUtlBuffer::EnsureCapacity(this: &madBuffer.pcmBuffer, num: (4 * sourceBuffer.m_Put + 0x7FFF) & 0xFFFF8000);
    mad_decoder_init(
      decoder: &madDecoder,
      data: &madBuffer,
      input_func: (mad_flow (__cdecl *)(void *, mad_stream *))MAD_InputCallback,
      header_func: nullptr,
      filter_func: nullptr,
      output_func: (mad_flow (__cdecl *)(void *, const mad_header *, mad_pcm *))MAD_OutputCallback,
      error_func: (mad_flow (__cdecl *)(void *, mad_stream *, mad_frame *))MAD_ErrorCallback,
      message_func: nullptr);
    v5 = mad_decoder_run(decoder: &madDecoder, mode: MAD_DECODER_MODE_SYNC);
    CImportTex::GetCurrentVersion(this: v6);
    if ( v5 != 0 )
    {
      if ( madBuffer.pcmBuffer.m_Memory.m_nGrowSize >= 0 )
      {
        if ( madBuffer.pcmBuffer.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: madBuffer.pcmBuffer.m_Memory.m_pMemory);
          madBuffer.pcmBuffer.m_Memory.m_pMemory = nullptr;
        }
        madBuffer.pcmBuffer.m_Memory.m_nAllocationCount = 0;
      }
      if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
      return false;
    }
    else
    {
      waveFormat.nChannels = madBuffer.nChannels;
      waveFormat.wFormatTag = 1;
      waveFormat.cbSize = 0;
      waveFormat.nSamplesPerSec = madBuffer.nSampleRate;
      waveFormat.nBlockAlign = 2 * LOWORD(madBuffer.nChannels);
      dword_66B2F8[0] = (int)&waveFormat;
      waveFormat.wBitsPerSample = 16;
      waveFormat.nAvgBytesPerSec = 2 * madBuffer.nSampleRate * LOWORD(madBuffer.nChannels);
      g_chunks[0].id = 544501094;
      dword_66B2F4[0] = 18;
      dword_66B2FC = 1635017060;
      dword_66B304 = (int)madBuffer.pcmBuffer.m_Memory.m_pMemory;
      dword_66B300 = madBuffer.pcmBuffer.m_Put;
      g_numChunks = 2;
      if ( _fullpath(UserBuf: fullSourcePath, path: pSourceName, maxlen: 0x104u) != nullptr )
        v3 = fullSourcePath;
      AudioConversion = GetAudioConversion(pSourceName: v3);
      CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
      bSuccess = EncodeAsXMA(
                   pDebugName: v3,
                   targetBuff: &targetBuffer,
                   quality: AudioConversion->iXmaQuality,
                   bXmaSeekTable: AudioConversion->bXmaSeekTable,
                   bDownsampled: false);
      if ( bSuccess )
        WriteBufferToFile(pTargetName, buffer: &targetBuffer, bWriteToZip, writeMode: g_WriteModeForConversions);
      if ( targetBuffer.m_Memory.m_nGrowSize >= 0 )
      {
        if ( targetBuffer.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
          targetBuffer.m_Memory.m_pMemory = nullptr;
        }
        targetBuffer.m_Memory.m_nAllocationCount = 0;
      }
      if ( madBuffer.pcmBuffer.m_Memory.m_nGrowSize >= 0 )
      {
        if ( madBuffer.pcmBuffer.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: madBuffer.pcmBuffer.m_Memory.m_pMemory);
          madBuffer.pcmBuffer.m_Memory.m_pMemory = nullptr;
        }
        madBuffer.pcmBuffer.m_Memory.m_nAllocationCount = 0;
      }
      if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
      return bSuccess;
    }
  }
  else
  {
    if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
    return false;
  }
}
