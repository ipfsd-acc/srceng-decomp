// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_wave_source.cpp
// Functions: 115
// ============================================================

#include "engine\audio\private\snd_wave_source.h"

//------------------------------------------------------------------------------
// Address: 0x100359F0
// Name: public: virtual int CAudioSourceWave::ZeroCrossingBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceWave::ZeroCrossingBefore(CAudioSourceMP3 *this, int sample)
{
  return sample;
}

//------------------------------------------------------------------------------
// Address: 0x1003E5D0
// Name: public: virtual char const __near * CAudioSourceWave::GetFileName(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAudioSourceWave::GetFileName(CAudioSourceWave *this, char *pOutBuf, unsigned int bufLen)
{
  CSfxTable *m_pSfx; // ecx

  m_pSfx = this->m_pSfx;
  if ( m_pSfx != nullptr )
    return CSfxTable::GetFileName(this: m_pSfx, pOutBuf, bufLen);
  else
    return "NULL m_pSfx";
}

//------------------------------------------------------------------------------
// Address: 0x1003E5F0
// Name: protected: void CAudioSourceWave::Init(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::Init(CAudioSourceWave *this, char *pHeaderBuffer, int headerSize)
{
  int m_bits; // eax
  int v5; // ecx
  int v6; // eax
  char *v7; // eax

  this->m_format = *(unsigned __int16 *)pHeaderBuffer;
  this->m_bits = *((unsigned __int16 *)pHeaderBuffer + 7);
  m_bits = this->m_bits;
  this->m_rate = *((_DWORD *)pHeaderBuffer + 1);
  v5 = *((unsigned __int16 *)pHeaderBuffer + 1);
  v6 = v5 * m_bits / 8;
  this->m_channels = v5;
  this->m_sampleSize = v6;
  if ( v6 <= 0 )
    this->m_sampleSize = 1;
  if ( this->m_format == 2 )
  {
    v7 = (char *)MemAlloc_Alloc(nSize: headerSize);
    this->m_pHeader = v7;
    memcpy(dst: (unsigned __int8 *)v7, src: (unsigned __int8 *)pHeaderBuffer, count: headerSize);
    this->m_nHeaderSize = headerSize;
    this->m_sampleSize = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E660
// Name: public: virtual int CAudioSourceWave::SampleCount(void)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall CAudioSourceWave::SampleCount(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x1003E670
// Name: public: void CAudioSourceWave::ConvertSamples(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ConvertSamples(CAudioSourceWave *this, char *pData, int sampleCount)
{
  int i; // edx

  if ( this->m_format == 1 && this->m_bits == 8 )
  {
    for ( i = 0; i < sampleCount * this->m_channels; ++pData )
    {
      *pData += 0x80;
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E6B0
// Name: public: virtual bool CAudioSourceWave::IsLooped(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceWave::IsLooped(CAudioSourceWave *this)
{
  return this->m_loopStart >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E6C0
// Name: public: virtual bool CAudioSourceWave::IsStereoWav(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceWave::IsStereoWav(CAudioSourceWave *this)
{
  return this->m_channels == 2;
}

//------------------------------------------------------------------------------
// Address: 0x1003E6D0
// Name: public: virtual int CAudioSourceWave::GetQuality(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceWave::GetQuality(CAudioSourceWave *this)
{
  if ( this->m_format == 357 )
    return this->m_quality;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E6F0
// Name: public: void CAudioSourceWave::Setup(char const __near *,int,class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::Setup(CAudioSourceWave *this, char *pFormatBuffer, int formatSize, IterateRIFF *walk)
{
  CAudioSourceWave_vtbl *v5; // edi
  int Wide; // eax

  CAudioSourceWave::Init(this, pHeaderBuffer: pFormatBuffer, headerSize: formatSize);
  while ( IterateRIFF::ChunkAvailable(this: walk) )
  {
    v5 = this->__vftable;
    Wide = vgui::Image::GetWide(this: (CVTFTexture *)walk);
    v5->ParseChunk(this, a2: walk, a3: Wide);
    IterateRIFF::ChunkNext(this: walk);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E750
// Name: public: __int64 CAudioSourceWave::ConvertLoopedPosition(__int64)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceWave::ConvertLoopedPosition(CAudioSourceWave *this, __int64 samplePosition)
{
  int m_format; // eax
  int m_loopStart; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi

  m_format = this->m_format;
  if ( m_format >= 3 && (m_format <= 4 || m_format == 357) )
    return samplePosition;
  m_loopStart = this->m_loopStart;
  v6 = samplePosition;
  if ( m_loopStart >= 0 && samplePosition >= this->m_sampleCount )
  {
    v7 = this->m_loopStart;
    v8 = this->m_sampleCount - v7;
    v6 = samplePosition - v7;
    if ( v8 != 0 )
      return this->m_loopStart + (samplePosition - v7) % v8;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1003E7D0
// Name: public: virtual void CAudioSourceWave::ReferenceRemove(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ReferenceRemove(CAudioSourceWave *this, CAudioMixer *pMixer)
{
  if ( this->m_refCount-- == 1 && this->IsPlayOnce(this) )
  {
    this->SetPlayOnce(this, a2: false);
    this->CacheUnload(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E800
// Name: public: virtual void CAudioSourceWave::ReferenceAdd(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ReferenceAdd(CAudioSourceWave *this, CAudioMixer *pMixer)
{
  ++this->m_refCount;
}

//------------------------------------------------------------------------------
// Address: 0x1003E810
// Name: public: virtual bool CAudioSourceWave::CanDelete(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceWave::CanDelete(CAudioSourceWave *this)
{
  return this->m_refCount <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E820
// Name: public: virtual class CAudioMixer __near * CAudioSourceMemWave::CreateMixer(int,int,bool,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CAudioMixer *__thiscall CAudioSourceMemWave::CreateMixer(
        CAudioSourceMemWave *this,
        int initialStreamPosition,
        int skipInitialSamples,
        bool bUpdateDelayForChoreo,
        SoundError *soundError)
{
  IWaveData *WaveDataMemory; // eax
  CAudioMixer *result; // eax
  CAudioMixer *v8; // edi
  int m_format; // [esp-18h] [ebp-20h]
  int m_channels; // [esp-14h] [ebp-1Ch]
  int m_bits; // [esp-10h] [ebp-18h]

  m_bits = this->m_bits;
  m_channels = this->m_channels;
  m_format = this->m_format;
  WaveDataMemory = CreateWaveDataMemory(source: this);
  result = CreateWaveMixer(
             data: WaveDataMemory,
             format: m_format,
             channels: m_channels,
             bits: m_bits,
             initialStreamPosition,
             skipInitialSamples,
             bUpdateDelayForChoreo);
  v8 = result;
  if ( result != nullptr )
  {
    this->ReferenceAdd(this, a2: result);
    *soundError = SE_OK;
    return v8;
  }
  else
  {
    *soundError = SE_CANT_CREATE_MIXER;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003E890
// Name: public: virtual int CAudioSourceMemWave::ZeroCrossingBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMemWave::ZeroCrossingBefore(CAudioSourceMemWave *this, int sample)
{
  char *v3; // edx
  int result; // eax
  char v5; // bl
  char *v6; // ecx
  char v7; // dl
  __int16 v8; // dx

  v3 = this->GetDataPointer(this);
  result = sample;
  if ( this->m_format == 1 )
  {
    v5 = 0;
    v6 = &v3[sample * this->m_sampleSize];
    if ( this->m_bits == 8 )
    {
      if ( this->m_channels == 1 )
      {
        if ( sample > 0 )
        {
          do
          {
            if ( v5 != 0 )
              break;
            if ( *v6 >= 8 || *v6 <= -8 )
            {
              --result;
              --v6;
            }
            else
            {
              v5 = 1;
            }
          }
          while ( result > 0 );
        }
      }
      else if ( sample > 0 )
      {
        do
        {
          if ( v5 != 0 )
            break;
          if ( *v6 >= 8 || *v6 <= -8 || (v7 = v6[1]) >= 8 || v7 <= -8 )
          {
            --result;
            --v6;
          }
          else
          {
            v5 = 1;
          }
        }
        while ( result > 0 );
      }
    }
    else if ( this->m_channels == 1 )
    {
      if ( sample > 0 )
      {
        do
        {
          if ( v5 != 0 )
            break;
          if ( *(__int16 *)v6 >= 2048 || *(__int16 *)v6 <= -2048 )
          {
            v6 -= 2;
            --result;
          }
          else
          {
            v5 = 1;
          }
        }
        while ( result > 0 );
      }
    }
    else if ( sample > 0 )
    {
      do
      {
        if ( v5 != 0 )
          break;
        if ( *(__int16 *)v6 >= 2048 || *(__int16 *)v6 <= -2048 || (v8 = *((_WORD *)v6 + 1)) >= 2048 || v8 <= -2048 )
        {
          --result;
          v6 -= 2;
        }
        else
        {
          v5 = 1;
        }
      }
      while ( result > 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003E9C0
// Name: public: virtual int CAudioSourceMemWave::ZeroCrossingAfter(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMemWave::ZeroCrossingAfter(CAudioSourceMemWave *this, int sample)
{
  char *v3; // eax
  int v5; // ebx
  char *v6; // esi
  int (__thiscall *SampleCount)(struct CAudioSourceMemWave *); // edx
  char v8; // al
  __int16 *v9; // ecx
  char v10; // dl
  __int16 v11; // ax
  char zero_3; // [esp+Fh] [ebp+Bh]

  v3 = this->GetDataPointer(this);
  if ( v3 == nullptr )
    return sample;
  v5 = sample;
  if ( this->m_format == 1 )
  {
    if ( this->m_bits == 8 )
    {
      v6 = &v3[sample * this->m_sampleSize];
      SampleCount = this->SampleCount;
      zero_3 = 0;
      if ( this->m_channels == 1 )
      {
        if ( v5 < SampleCount(this) )
        {
          while ( zero_3 == 0 )
          {
            if ( *v6 >= 8 || *v6 <= -8 )
            {
              ++v5;
              ++v6;
            }
            else
            {
              zero_3 = 1;
            }
            if ( v5 >= this->SampleCount(this) )
              return v5;
          }
        }
      }
      else if ( v5 < SampleCount(this) )
      {
        while ( zero_3 == 0 )
        {
          if ( *v6 >= 8 || *v6 <= -8 || (v8 = v6[1]) >= 8 || v8 <= -8 )
          {
            ++v5;
            ++v6;
          }
          else
          {
            zero_3 = 1;
          }
          if ( v5 >= this->SampleCount(this) )
            return v5;
        }
      }
    }
    else
    {
      v9 = (__int16 *)&v3[sample * this->m_sampleSize];
      v10 = 0;
      if ( this->m_channels == 1 )
      {
        if ( sample > 0 )
        {
          while ( v10 == 0 )
          {
            if ( *v9 >= 2048 || *v9 <= -2048 )
            {
              ++v9;
              ++v5;
            }
            else
            {
              v10 = 1;
            }
            if ( v5 <= 0 )
              return v5;
          }
        }
      }
      else if ( sample > 0 )
      {
        do
        {
          if ( v10 != 0 )
            break;
          if ( *v9 >= 2048 || *v9 <= -2048 || (v11 = v9[1]) >= 2048 || v11 <= -2048 )
          {
            ++v5;
            ++v9;
          }
          else
          {
            v10 = 1;
          }
        }
        while ( v5 > 0 );
      }
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1003EB30
// Name: public: virtual int CAudioSourceMemWave::GetCacheStatus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMemWave::GetCacheStatus(CAudioSourceMemWave *this)
{
  unsigned int *p_m_hCache; // edi
  IAsyncWavDataCache_vtbl *v3; // ebx
  const char *FileName; // eax
  int m_dataSize; // [esp-Ch] [ebp-11Ch]
  int m_dataStart; // [esp-8h] [ebp-118h]
  char nameBuf[261]; // [esp+8h] [ebp-108h] BYREF
  bool bCacheValid; // [esp+10Dh] [ebp-3h] BYREF
  bool bIsMissing; // [esp+10Eh] [ebp-2h] BYREF
  bool bCompleted; // [esp+10Fh] [ebp-1h]

  p_m_hCache = &this->m_hCache;
  bCompleted = wavedatacache->IsDataLoadCompleted(
                 this: wavedatacache,
                 a2: this->m_hCache,
                 a3: &bCacheValid,
                 a4: &bIsMissing);
  if ( !bCacheValid )
  {
    v3 = wavedatacache->__vftable;
    m_dataStart = this->m_dataStart;
    m_dataSize = this->m_dataSize;
    FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
    v3->RestartDataLoad(this: wavedatacache, a2: &this->m_hCache, a3: FileName, a4: m_dataSize, a5: m_dataStart);
  }
  if ( bCompleted )
    return 1;
  if ( bIsMissing )
    return 3;
  return wavedatacache->IsDataLoadInProgress(this: wavedatacache, a2: *p_m_hCache) ? 2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003EBE0
// Name: public: virtual void CAudioSourceMemWave::CacheLoad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMemWave::CacheLoad(CAudioSourceMemWave *this)
{
  unsigned int m_hCache; // eax
  unsigned int *p_m_hCache; // edi
  IAsyncWavDataCache_vtbl *v4; // ebx
  const char *FileName; // eax
  IAsyncWavDataCache_vtbl *v6; // ebx
  const char *v7; // eax
  int v8; // [esp-Ch] [ebp-120h]
  int m_dataSize; // [esp-8h] [ebp-11Ch]
  int v10; // [esp-8h] [ebp-11Ch]
  int m_dataStart; // [esp-4h] [ebp-118h]
  char nameBuf[263]; // [esp+Ch] [ebp-108h] BYREF
  bool bCacheValid; // [esp+113h] [ebp-1h] BYREF

  m_hCache = this->m_hCache;
  p_m_hCache = &this->m_hCache;
  if ( m_hCache != 0 )
  {
    wavedatacache->IsDataLoadCompleted(this: wavedatacache, a2: m_hCache, a3: &bCacheValid, a4: nullptr);
    if ( !bCacheValid )
    {
      v4 = wavedatacache->__vftable;
      m_dataStart = this->m_dataStart;
      m_dataSize = this->m_dataSize;
      FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
      v4->RestartDataLoad(this: wavedatacache, a2: p_m_hCache, a3: FileName, a4: m_dataSize, a5: m_dataStart);
    }
  }
  else
  {
    v6 = wavedatacache->__vftable;
    v10 = this->m_dataStart;
    v8 = this->m_dataSize;
    v7 = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
    *p_m_hCache = v6->AsyncLoadCache(this: wavedatacache, a2: v7, a3: v8, a4: v10, a5: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EC90
// Name: public: virtual void CAudioSourceMemWave::CacheUnload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMemWave::CacheUnload(CAudioSourceMemWave *this)
{
  unsigned int m_hCache; // eax

  m_hCache = this->m_hCache;
  if ( m_hCache != 0 )
    wavedatacache->Unload(this: wavedatacache, a2: m_hCache);
}

//------------------------------------------------------------------------------
// Address: 0x1003ECB0
// Name: protected: virtual char __near * CAudioSourceMemWave::GetDataPointer(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAudioSourceMemWave::GetDataPointer(CAudioSourceMemWave *this)
{
  bool v2; // zf
  int m_dataSize; // ebx
  const char *FileName; // eax
  IAsyncWavDataCache_vtbl *v5; // edi
  const char *v6; // eax
  int m_dataStart; // [esp-14h] [ebp-128h]
  char nameBuf[260]; // [esp+8h] [ebp-10Ch] BYREF
  char *pWaveData; // [esp+10Ch] [ebp-8h] BYREF
  bool bSamplesConverted; // [esp+113h] [ebp-1h] BYREF

  v2 = this->m_hCache == 0;
  pWaveData = nullptr;
  bSamplesConverted = false;
  if ( v2 )
    this->CacheLoad(this);
  m_dataSize = this->m_dataSize;
  if ( (*((_BYTE *)&this->CAudioSourceWave + 80) & 8) != 0 )
  {
    FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
    if ( V_stristr(pStr: FileName, pSearch: "music") != nullptr && m_dataSize >= 0x8000 )
      m_dataSize = 0x8000;
  }
  v5 = wavedatacache->__vftable;
  m_dataStart = this->m_dataStart;
  v6 = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  v5->GetDataPointer(
    this: wavedatacache,
    a2: &this->m_hCache,
    a3: v6,
    a4: m_dataSize,
    a5: m_dataStart,
    a6: (void **)&pWaveData,
    a7: 0,
    a8: &bSamplesConverted);
  if ( pWaveData == nullptr || bSamplesConverted )
    return pWaveData;
  CAudioSourceWave::ConvertSamples(this, pData: pWaveData, sampleCount: this->m_dataSize / this->m_sampleSize);
  wavedatacache->SetPostProcessed(this: wavedatacache, a2: this->m_hCache, a3: true);
  return pWaveData;
}

//------------------------------------------------------------------------------
// Address: 0x1003ED90
// Name: public: virtual class CAudioMixer __near * CAudioSourceStreamWave::CreateMixer(int,int,bool,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CAudioMixer *__thiscall CAudioSourceStreamWave::CreateMixer(
        CAudioSourceStreamWave *this,
        int initialStreamPosition,
        int skipInitialSamples,
        bool bUpdateDelayForChoreo,
        SoundError *soundError)
{
  const char *v6; // eax
  IWaveData *WaveDataStream; // edi
  CAudioMixer *WaveMixer; // ebx
  char fileName[260]; // [esp+Ch] [ebp-104h] BYREF

  v6 = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: fileName, bufLen: 0x104u);
  WaveDataStream = CreateWaveDataStream(
                     source: this,
                     pStreamSource: &this->IWaveStreamSource,
                     pFileName: v6,
                     dataStart: this->m_dataStart,
                     dataSize: this->m_dataSize,
                     pSfx: this->m_pSfx,
                     startOffset: initialStreamPosition,
                     skipInitialSamples,
                     soundError);
  if ( WaveDataStream != nullptr )
  {
    WaveMixer = CreateWaveMixer(
                  data: WaveDataStream,
                  format: this->m_format,
                  channels: this->m_channels,
                  bits: this->m_bits,
                  initialStreamPosition,
                  skipInitialSamples,
                  bUpdateDelayForChoreo);
    if ( WaveMixer != nullptr )
    {
      this->ReferenceAdd(this, a2: WaveMixer);
      return WaveMixer;
    }
    ((void (__thiscall *)(IWaveData *, int))WaveDataStream->dtr_IWaveData)(a1: WaveDataStream, a2: 1);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003EE30
// Name: public: virtual void CAudioSourceStreamWave::Prefetch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceStreamWave::Prefetch(CAudioSourceStreamWave *this)
{
  const char *FileName; // eax
  int m_dataStart; // [esp-8h] [ebp-10Ch]
  int m_dataSize; // [esp-4h] [ebp-108h]
  char nameBuf[260]; // [esp+0h] [ebp-104h] BYREF

  m_dataSize = this->m_dataSize;
  m_dataStart = this->m_dataStart;
  FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  PrefetchDataStream(pFileName: FileName, dataOffset: m_dataStart, dataSize: m_dataSize);
}

//------------------------------------------------------------------------------
// Address: 0x1003EE70
// Name: public: virtual int CAudioSourceStreamWave::SampleToStreamPosition(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceStreamWave::SampleToStreamPosition(CAudioSourceStreamWave *this, int samplePosition)
{
  int m_nHeaderSize; // eax
  char *m_pHeader; // esi
  int v4; // eax
  int v5; // ecx
  const char *v7; // eax
  char fileName[260]; // [esp+0h] [ebp-104h] BYREF

  if ( this->m_format == 1 )
    return samplePosition * this->m_sampleSize;
  if ( this->m_format == 357 && (m_nHeaderSize = this->m_nHeaderSize) != 0 )
  {
    m_pHeader = this->m_pHeader;
    v4 = m_nHeaderSize / 4;
    v5 = 0;
    if ( v4 <= 0 )
      return 0;
    while ( samplePosition >= *(_DWORD *)&m_pHeader[4 * v5] )
    {
      if ( ++v5 >= v4 )
        return 0;
    }
    if ( v5 != 0 )
      return (v5 << 11) - 2048;
    else
      return 0;
  }
  else
  {
    v7 = this->GetFileName(this, a2: fileName, a3: 260);
    _Warning(a1: "SampleToStreamPosition( %d ) is not supported for sound '%s'.\n", samplePosition, v7);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EF20
// Name: public: virtual int CAudioSourceStreamWave::StreamToSamplePosition(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceStreamWave::StreamToSamplePosition(CAudioSourceStreamWave *this, int streamPosition)
{
  int m_nHeaderSize; // edi
  int v3; // esi
  const char *v5; // eax
  char fileName[260]; // [esp+0h] [ebp-104h] BYREF

  if ( this->m_format == 1 )
    return streamPosition / this->m_sampleSize;
  if ( this->m_format == 357 && (m_nHeaderSize = this->m_nHeaderSize) != 0 )
  {
    v3 = streamPosition / 2048;
    if ( streamPosition / 2048 > 0 )
    {
      if ( v3 <= m_nHeaderSize / 4 )
        return *(_DWORD *)&this->m_pHeader[4 * v3 - 4];
      else
        return this->m_numDecodedSamples;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v5 = this->GetFileName(this, a2: fileName, a3: 260);
    _Warning(a1: "StreamToSamplePosition( %d ) is not supported for sound '%s'.\n", streamPosition, v5);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EFD0
// Name: public: virtual int CAudioSourceStreamWave::GetCacheStatus(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioSourceStreamWave::GetCacheStatus(CAudioSourceStreamWave *this)
{
  return this->m_dataSize != 0 && this->m_dataStart != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003EFF0
// Name: float AudioSource_GetSoundDuration(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl AudioSource_GetSoundDuration(CSfxTable *pSfx)
{
  float v2; // [esp+4h] [ebp-4h]

  if ( pSfx == nullptr || pSfx->pSource == nullptr )
    return 0.0;
  v2 = (float)pSfx->pSource->SampleCount(this: pSfx->pSource);
  return v2 / (double)pSfx->pSource->SampleRate(this: pSfx->pSource);
}

//------------------------------------------------------------------------------
// Address: 0x1003F040
// Name: public: void CAudioSourceCachedInfo::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Clear(CAudioSourceCachedInfo *this)
{
  CSentence *m_pSentence; // edi
  unsigned __int8 *m_pHeader; // [esp-8h] [ebp-14h]
  unsigned __int8 *m_pCachedData; // [esp-4h] [ebp-10h]

  m_pSentence = this->m_pSentence;
  this->infolong = 0;
  this->flagsbyte = 0;
  this->m_dataStart = 0;
  this->m_dataSize = 0;
  this->m_loopStart = 0;
  this->m_sampleCount = 0;
  if ( m_pSentence != nullptr )
  {
    CSentence::~CSentence(this: m_pSentence);
    free(pMem: m_pSentence);
  }
  m_pCachedData = this->m_pCachedData;
  this->m_pSentence = nullptr;
  free(pMem: m_pCachedData);
  m_pHeader = this->m_pHeader;
  this->m_pCachedData = nullptr;
  this->m_usCachedDataSize = 0;
  free(pMem: m_pHeader);
  this->m_pHeader = nullptr;
  this->m_usHeaderSize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F0A0
// Name: private: void CAudioSourceCache::RemoveCache(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::RemoveCache(CAudioSourceCache *this, const char *cachename)
{
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: cachename, a3: "MOD") )
  {
    if ( !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: cachename, a3: "MOD") )
      g_pFullFileSystem->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: cachename, a3: true, a4: "MOD");
    g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: cachename, a3: "MOD");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F110
// Name: protected: unsigned char __near * CAudioSourceWave::GetCachedDataPointer(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CAudioSourceWave::GetCachedDataPointer(CAudioSourceWave *this)
{
  CSfxTable *m_pSfx; // edi
  int *p_m_nCachedDataSize; // ebx
  CAudioSourceCachedInfo *v4; // eax
  CAudioSourceCachedInfo *info; // esi
  bool IsPrecachedSound; // [esp+Ch] [ebp-4h]

  m_pSfx = this->m_pSfx;
  p_m_nCachedDataSize = &this->m_nCachedDataSize;
  IsPrecachedSound = CSfxTable::IsPrecachedSound(this: m_pSfx);
  if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
  {
    v4 = audiosourcecache->GetInfo(this: audiosourcecache, a2: 1, a3: IsPrecachedSound, a4: m_pSfx);
    this->m_AudioCacheHandle.info = v4;
    if ( this != (CAudioSourceWave *)-64 && v4 != nullptr )
      *p_m_nCachedDataSize = v4->m_usCachedDataSize;
    this->m_AudioCacheHandle.m_FlushCount = CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
  }
  info = this->m_AudioCacheHandle.info;
  if ( info != nullptr )
    return info->m_pCachedData;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003F180
// Name: public: CAudioSourceWave::CAudioSourceWave(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceWave *__thiscall CAudioSourceWave::CAudioSourceWave(CAudioSourceWave *this, CSfxTable *pSfx)
{
  this->__vftable = (CAudioSourceWave_vtbl *)&CAudioSourceWave::`vftable';
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  *((_DWORD *)this + 20) &= 0xFFFFFFF0;
  this->m_format = 0;
  this->m_pHeader = nullptr;
  this->m_nHeaderSize = 0;
  this->m_loopStart = -1;
  this->m_sampleSize = 1;
  this->m_sampleCount = 0;
  this->m_bits = 0;
  this->m_channels = 0;
  this->m_dataStart = 0;
  this->m_dataSize = 0;
  this->m_rate = 0;
  this->m_refCount = 0;
  this->m_pSfx = pSfx;
  this->m_pTempSentence = nullptr;
  this->m_nCachedDataSize = 0;
  this->m_numDecodedSamples = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003F1E0
// Name: public: virtual void CAudioSourceWave::SetPlayOnce(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::SetPlayOnce(CAudioSourceWave *this, bool bIsPlayOnce)
{
  *((_DWORD *)this + 20) ^= (*((_DWORD *)this + 20) ^ (2 * bIsPlayOnce)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x1003F200
// Name: public: virtual bool CAudioSourceWave::IsPlayOnce(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioSourceWave::IsPlayOnce(CAudioSourceWave *this)
{
  return (*((_DWORD *)this + 20) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F210
// Name: public: virtual void CAudioSourceWave::SetSentenceWord(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::SetSentenceWord(CAudioSourceWave *this, bool bIsWord)
{
  *((_DWORD *)this + 20) ^= (*((_DWORD *)this + 20) ^ (4 * bIsWord)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x1003F230
// Name: public: virtual bool CAudioSourceWave::IsSentenceWord(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioSourceWave::IsSentenceWord(CAudioSourceWave *this)
{
  return (*((_DWORD *)this + 20) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F240
// Name: public: CAudioSourceWave::CAudioSourceWave(class CSfxTable __near *,class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceWave *__thiscall CAudioSourceWave::CAudioSourceWave(
        CAudioSourceWave *this,
        CSfxTable *pSfx,
        CAudioSourceCachedInfo *info)
{
  char *v4; // eax
  bool v5; // zf
  int m_sampleCount; // edi
  char *m_pHeader; // eax
  int v8; // ebx
  int v9; // edi
  int v10; // ecx
  int v11; // edx
  int pSfxa; // [esp+14h] [ebp+8h]

  this->__vftable = (CAudioSourceWave_vtbl *)&CAudioSourceWave::`vftable';
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  this->m_pSfx = pSfx;
  this->m_refCount = 0;
  this->m_pHeader = nullptr;
  this->m_nHeaderSize = 0;
  if ( info->m_pHeader != nullptr )
  {
    v4 = (char *)MemAlloc_Alloc(nSize: info->m_usHeaderSize);
    this->m_pHeader = v4;
    _V_memcpy(dest: v4, src: info->m_pHeader, count: info->m_usHeaderSize);
    this->m_nHeaderSize = info->m_usHeaderSize;
  }
  this->m_bits = (info->infolong >> 2) & 0x1F;
  this->m_channels = (info->infolong >> 7) & 3;
  this->m_sampleSize = (info->infolong >> 9) & 7;
  this->m_format = (info->infolong >> 12) & 3;
  this->m_dataStart = info->m_dataStart;
  this->m_dataSize = info->m_dataSize;
  v5 = this->m_format == 2;
  this->m_rate = (info->infolong >> 14) & 0x1FFFF;
  this->m_loopStart = info->m_loopStart;
  m_sampleCount = info->m_sampleCount;
  this->m_sampleCount = m_sampleCount;
  this->m_numDecodedSamples = m_sampleCount;
  if ( v5 )
  {
    m_pHeader = this->m_pHeader;
    if ( m_pHeader != nullptr )
    {
      v8 = *((unsigned __int16 *)m_pHeader + 9);
      v9 = *((unsigned __int16 *)m_pHeader + 1);
      v10 = 7 * v9 + v9 * (v8 - 2) / 2;
      v11 = this->m_sampleCount % v10;
      pSfxa = v8 * (this->m_sampleCount / v10);
      if ( v11 != 0 )
        pSfxa += v8 + 2 * (v11 - v10) / v9;
      this->m_numDecodedSamples = pSfxa;
    }
  }
  *((_DWORD *)this + 20) &= 0xFFFFFFF0;
  this->m_pTempSentence = nullptr;
  this->m_nCachedDataSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003F360
// Name: public: virtual CAudioSourceWave::~CAudioSourceWave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::~CAudioSourceWave(CAudioSourceWave *this)
{
  CSentence *m_pTempSentence; // edi
  char *m_pHeader; // [esp-4h] [ebp-Ch]

  m_pHeader = this->m_pHeader;
  this->__vftable = (CAudioSourceWave_vtbl *)&CAudioSourceWave::`vftable';
  free(pMem: m_pHeader);
  m_pTempSentence = this->m_pTempSentence;
  if ( m_pTempSentence != nullptr )
  {
    CSentence::~CSentence(this: this->m_pTempSentence);
    free(pMem: m_pTempSentence);
  }
  this->__vftable = (CAudioSourceWave_vtbl *)&CAudioSource::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1003F3A0
// Name: public: virtual bool CAudioSourceWave::IsAsyncLoad(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceWave::IsAsyncLoad(CAudioSourceWave *this)
{
  int v2; // eax
  int m_nValue; // eax
  BOOL IsPrecachedSound; // [esp-Ch] [ebp-10h]
  CSfxTable *m_pSfx; // [esp-8h] [ebp-Ch]

  if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
  {
    m_pSfx = this->m_pSfx;
    IsPrecachedSound = CSfxTable::IsPrecachedSound(this: m_pSfx);
    v2 = this->GetType(this);
    CAudioSourceCachedInfoHandle_t::Get(
      this: &this->m_AudioCacheHandle,
      audiosourcetype: v2,
      soundisprecached: IsPrecachedSound,
      sfx: m_pSfx,
      pcacheddatasize: &this->m_nCachedDataSize);
  }
  if ( snd_async_minsize.m_pParent != nullptr )
    m_nValue = snd_async_minsize.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  return this->m_dataSize > m_nValue || this->m_nCachedDataSize <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F400
// Name: public: virtual void CAudioSourceWave::CheckAudioSourceCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::CheckAudioSourceCache(CAudioSourceWave *this)
{
  CSfxTable *m_pSfx; // ebx
  int v3; // eax
  CAudioSourceCachedInfo *v4; // eax

  if ( CSfxTable::IsPrecachedSound(this: this->m_pSfx) )
  {
    m_pSfx = this->m_pSfx;
    v3 = this->GetType(this);
    if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
    {
      v4 = audiosourcecache->GetInfo(this: audiosourcecache, a2: v3, a3: 1, a4: m_pSfx);
      this->m_AudioCacheHandle.info = v4;
      if ( this != (CAudioSourceWave *)-64 && v4 != nullptr )
        this->m_nCachedDataSize = v4->m_usCachedDataSize;
      this->m_AudioCacheHandle.m_FlushCount = CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F460
// Name: public: virtual bool CAudioSourceWave::IsVoiceSource(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceWave::IsVoiceSource(CAudioSourceWave *this)
{
  return this->GetSentence(this) != nullptr && *((_BYTE *)this->GetSentence(this) + 74) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F490
// Name: public: virtual void CAudioSourceWave::ParseChunk(class IterateRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ParseChunk(CAudioSourceWave *this, IterateRIFF *walk, int chunkName)
{
  _BYTE pOutput[28]; // [esp+4h] [ebp-54h] BYREF
  int v5; // [esp+20h] [ebp-38h]
  int v6; // [esp+2Ch] [ebp-2Ch]
  int v7; // [esp+30h] [ebp-28h]
  _BYTE v8[20]; // [esp+40h] [ebp-18h] BYREF
  int v9; // [esp+54h] [ebp-4h]

  switch ( chunkName )
  {
    case 543520099:
      if ( IterateRIFF::ChunkReadInt(this: walk) > 0 )
      {
        IterateRIFF::ChunkReadPartial(this: walk, pOutput: v8, dataSize: 24);
        this->m_loopStart = v9;
      }
      break;
    case 1413563478:
      this->ParseSentence(this, a2: walk);
      break;
    case 1819307379:
      IterateRIFF::ChunkReadPartial(this: walk, pOutput, dataSize: 60);
      if ( v5 != 0 && v6 == 0 )
        this->m_loopStart = v7;
      break;
    default:
      vgui::Image::GetWide(this: (CVTFTexture *)walk);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F530
// Name: public: virtual class CSentence __near * CAudioSourceWave::GetSentence(void)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CAudioSourceWave::GetSentence(CAudioSourceWave *this)
{
  CSentence *result; // eax
  CAudioSourceCachedInfo *info; // eax
  bool IsPrecachedSound; // al
  CSfxTable *m_pSfx; // [esp-Ch] [ebp-14h]

  if ( (*((_BYTE *)this + 80) & 1) != 0 )
    return nullptr;
  if ( (this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount
     || (info = this->m_AudioCacheHandle.info) == nullptr)
    && (m_pSfx = this->m_pSfx,
        IsPrecachedSound = CSfxTable::IsPrecachedSound(this: m_pSfx),
        (info = CAudioSourceCachedInfoHandle_t::Get(
                  this: &this->m_AudioCacheHandle,
                  audiosourcetype: 1,
                  soundisprecached: IsPrecachedSound,
                  sfx: m_pSfx,
                  pcacheddatasize: &this->m_nCachedDataSize)) == nullptr)
    || (result = info->m_pSentence) == nullptr
    || *((_BYTE *)result + 72) == 0 )
  {
    *((_DWORD *)this + 20) |= 1u;
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003F590
// Name: protected: bool CAudioSourceWave::GetStartupData(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioSourceWave::GetStartupData(CAudioSourceWave *this)
{
  int v2; // esi
  int v3; // edi
  int SamplePosition; // eax
  CAudioSourceWave *v5; // esi
  char formatBuffer[1024]; // [esp+0h] [ebp-534h] BYREF
  char nameBuf[260]; // [esp+400h] [ebp-134h] BYREF
  IterateRIFF walk; // [esp+504h] [ebp-30h] BYREF
  const char *pName; // [esp+51Ch] [ebp-18h]
  CAudioSourceWave *v10; // [esp+520h] [ebp-14h]
  InFileRIFF riff; // [esp+524h] [ebp-10h] BYREF

  v10 = this;
  pName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  InFileRIFF::InFileRIFF(this: &riff, pFileName: pName, io: g_pSndIO);
  if ( riff.m_riffName == 1163280727 )
  {
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    v2 = 0;
    v3 = 0;
    if ( !IterateRIFF::ChunkAvailable(this: &walk) )
      goto LABEL_15;
    while ( v2 == 0 )
    {
      if ( vgui::Image::GetWide(this: (CVTFTexture *)&walk) == 544501094 )
      {
        if ( (unsigned int)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&walk) <= 0x400 )
        {
          IterateRIFF::ChunkRead(this: &walk, pOutput: formatBuffer);
          SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&walk);
          v2 = *(unsigned __int16 *)formatBuffer;
          v3 = SamplePosition;
          if ( *(_WORD *)&formatBuffer[14] > 0x10u )
            _Warning(a1: "Unsupported %d-bit wave file %s\n", *(unsigned __int16 *)&formatBuffer[14], pName);
        }
      }
      else
      {
        vgui::Image::GetWide(this: (CVTFTexture *)&walk);
      }
      IterateRIFF::ChunkNext(this: &walk);
      if ( !IterateRIFF::ChunkAvailable(this: &walk) )
      {
        if ( v2 == 0 )
          goto LABEL_15;
        break;
      }
    }
    v5 = v10;
    CAudioSourceWave::Setup(this: v10, pFormatBuffer: formatBuffer, formatSize: v3, &walk);
    if ( v5->m_dataStart != 0 && v5->m_dataSize != 0 )
    {
      InFileRIFF::~InFileRIFF(this: &riff);
      return 1;
    }
    else
    {
LABEL_15:
      InFileRIFF::~InFileRIFF(this: &riff);
      return 0;
    }
  }
  else
  {
    InFileRIFF::~InFileRIFF(this: &riff);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F6D0
// Name: public: CAudioSourceMemWave::CAudioSourceMemWave(class CSfxTable __near *,class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMemWave *__thiscall CAudioSourceMemWave::CAudioSourceMemWave(
        CAudioSourceMemWave *this,
        CSfxTable *pSfx,
        CAudioSourceCachedInfo *info)
{
  CAudioSourceWave::CAudioSourceWave(this, pSfx, info);
  this->__vftable = (CAudioSourceMemWave_vtbl *)&CAudioSourceMemWave::`vftable';
  this->m_hCache = 0;
  this->m_hStream = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003F700
// Name: public: virtual int CAudioSourceMemWave::GetOutputData(void __near * __near *,__int64,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMemWave::GetOutputData(
        CAudioSourceMemWave *this,
        void **pData,
        __int64 samplePosition,
        int sampleCount,
        char *copyBuf)
{
  unsigned int v6; // ecx
  __int64 v7; // rax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // edi
  int v11; // kr00_4
  unsigned __int8 *CachedDataPointer; // eax
  __int64 samplePositiona; // [esp+18h] [ebp+Ch]

  v7 = CAudioSourceWave::ConvertLoopedPosition(this, samplePosition);
  v6 = v7;
  LODWORD(v7) = this->m_sampleCount - v7;
  if ( (int)v7 < 0 )
    LODWORD(v7) = 0;
  v8 = sampleCount;
  if ( sampleCount > (int)v7 )
    v8 = v7;
  v11 = this->m_sampleSize * v6;
  v9 = (this->m_sampleSize * __PAIR64__(HIDWORD(v7), v6)) >> 32;
  v10 = v11;
  samplePositiona = __PAIR64__(v9, v11);
  if ( v8 == 0 )
    return v8;
  if ( __SPAIR64__(v9, v11) < this->m_nCachedDataSize )
  {
    this->CacheLoad(this);
    if ( samplePositiona + v8 * this->m_sampleSize >= this->m_nCachedDataSize )
      v8 = (this->m_nCachedDataSize - samplePositiona) / this->m_sampleSize;
    CachedDataPointer = CAudioSourceWave::GetCachedDataPointer(this);
    v10 = samplePositiona;
  }
  else
  {
    CachedDataPointer = (unsigned __int8 *)this->GetDataPointer(this);
  }
  *pData = CachedDataPointer;
  if ( CachedDataPointer != nullptr )
  {
    *pData = &CachedDataPointer[v10];
    return v8;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F7D0
// Name: public: void CAudioSourceMemWave::ParseDataChunk(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMemWave::ParseDataChunk(CAudioSourceMemWave *this, IterateRIFF *walk)
{
  int SamplePosition; // eax
  CAudioSourceMemWave_vtbl *v4; // edx
  char *v5; // edi
  CSfxTable *m_pSfx; // ecx
  const char *FileName; // eax
  int m_format; // eax
  int v9; // eax
  char *m_pHeader; // eax
  int v11; // ebx
  int v12; // edi
  int v13; // ecx
  int v14; // edx
  int m_sampleCount; // edx
  char *v16; // eax
  int i; // ecx
  char nameBuf[260]; // [esp+Ch] [ebp-108h] BYREF
  char *pData; // [esp+110h] [ebp-4h]
  int walka; // [esp+11Ch] [ebp+8h]

  this->m_dataStart = walk->m_chunkPosition + 8;
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)walk);
  v4 = this->__vftable;
  this->m_dataSize = SamplePosition;
  v5 = v4->GetDataPointer(this);
  pData = v5;
  if ( v5 == nullptr )
  {
    m_pSfx = this->m_pSfx;
    if ( m_pSfx != nullptr )
      FileName = CSfxTable::GetFileName(this: m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
    else
      FileName = "m_pSfx = NULL";
    _Error(a1: "CAudioSourceMemWave (%s): GetDataPointer() failed.", FileName);
  }
  IterateRIFF::ChunkRead(this: walk, pOutput: v5);
  m_format = this->m_format;
  if ( m_format == 1 )
  {
    v9 = this->m_dataSize / this->m_sampleSize;
    this->m_sampleCount = v9;
    this->m_numDecodedSamples = v9;
  }
  else if ( m_format == 2 )
  {
    this->m_sampleCount = this->m_dataSize;
    m_pHeader = this->m_pHeader;
    this->m_sampleSize = 1;
    this->m_bits = 16;
    v11 = *((unsigned __int16 *)m_pHeader + 9);
    v12 = *((unsigned __int16 *)m_pHeader + 1);
    v13 = 7 * v12 + v12 * (v11 - 2) / 2;
    v14 = this->m_dataSize % v13;
    walka = v11 * (this->m_dataSize / v13);
    if ( v14 != 0 )
      walka += v11 + 2 * (v14 - v13) / v12;
    v5 = pData;
    this->m_numDecodedSamples = walka;
  }
  if ( v5 != nullptr )
  {
    m_sampleCount = this->m_sampleCount;
    v16 = v5;
    if ( this->m_format == 1 && this->m_bits == 8 )
    {
      for ( i = 0; i < m_sampleCount * this->m_channels; ++v16 )
      {
        *v16 += 0x80;
        ++i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F900
// Name: public: CAudioSourceStreamWave::CAudioSourceStreamWave(class CSfxTable __near *,class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceStreamWave *__thiscall CAudioSourceStreamWave::CAudioSourceStreamWave(
        CAudioSourceStreamWave *this,
        CSfxTable *pSfx,
        CAudioSourceCachedInfo *info)
{
  CAudioSourceWave::CAudioSourceWave(this, pSfx, info);
  this->IWaveStreamSource::__vftable = (IWaveStreamSource_vtbl *)&IWaveStreamSource::`vftable';
  this->m_pSfx = pSfx;
  this->CAudioSourceWave::CAudioSource::__vftable = (CAudioSourceStreamWave_vtbl *)&CAudioSourceStreamWave::`vftable'{for `CAudioSourceWave'};
  this->IWaveStreamSource::__vftable = (IWaveStreamSource_vtbl *)&CAudioSourceStreamWave::`vftable'{for `IWaveStreamSource'};
  this->m_hWaveFileAccess = nullptr;
  this->m_dataStart = info->m_dataStart;
  this->m_dataSize = info->m_dataSize;
  this->m_sampleCount = info->m_sampleCount;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003F950
// Name: public: virtual __int64 CAudioSourceStreamWave::UpdateLoopingSamplePosition(__int64)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall CAudioSourceStreamWave::UpdateLoopingSamplePosition(
        CAudioSourceStreamWave *this,
        __int64 samplePosition)
{
  return CAudioSourceWave::ConvertLoopedPosition(this: (CAudioSourceStreamWave *)((char *)this - 88), samplePosition);
}

//------------------------------------------------------------------------------
// Address: 0x1003F970
// Name: public: virtual void CAudioSourceStreamWave::UpdateSamples(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceStreamWave::UpdateSamples(CAudioSourceStreamWave *this, char *pData, int sampleCount)
{
  int i; // edx

  if ( *((_DWORD *)this - 18) == 1 && *((_DWORD *)this - 21) == 8 )
  {
    for ( i = 0; i < sampleCount * *((_DWORD *)this - 19); ++pData )
    {
      *pData += 0x80;
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F9B0
// Name: public: virtual int CAudioSourceStreamWave::GetLoopingInfo(int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceStreamWave::GetLoopingInfo(
        CAudioSourceStreamWave *this,
        int *pLoopBlock,
        int *pNumLeadingSamples,
        int *pNumTrailingSamples)
{
  if ( pLoopBlock != nullptr )
    *pLoopBlock = *((unsigned __int16 *)this - 8);
  if ( pNumLeadingSamples != nullptr )
    *pNumLeadingSamples = *((unsigned __int16 *)this - 7);
  if ( pNumTrailingSamples != nullptr )
    *pNumTrailingSamples = *((unsigned __int16 *)this - 6);
  return *((_DWORD *)this - 16);
}

//------------------------------------------------------------------------------
// Address: 0x1003F9F0
// Name: public: virtual CAudioSourceStreamWave::~CAudioSourceStreamWave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceStreamWave::~CAudioSourceStreamWave(CAudioSourceStreamWave *this)
{
  void *m_hWaveFileAccess; // eax
  CSentence *m_pTempSentence; // edi
  char *m_pHeader; // [esp-4h] [ebp-Ch]

  m_hWaveFileAccess = this->m_hWaveFileAccess;
  this->CAudioSourceWave::CAudioSource::__vftable = (CAudioSourceStreamWave_vtbl *)&CAudioSourceStreamWave::`vftable'{for `CAudioSourceWave'};
  this->IWaveStreamSource::__vftable = (IWaveStreamSource_vtbl *)&CAudioSourceStreamWave::`vftable'{for `IWaveStreamSource'};
  if ( m_hWaveFileAccess != nullptr )
  {
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: m_hWaveFileAccess);
    this->m_hWaveFileAccess = nullptr;
  }
  m_pHeader = this->m_pHeader;
  this->CAudioSourceWave::CAudioSource::__vftable = (CAudioSourceStreamWave_vtbl *)&CAudioSourceWave::`vftable';
  free(pMem: m_pHeader);
  m_pTempSentence = this->m_pTempSentence;
  if ( m_pTempSentence != nullptr )
  {
    CSentence::~CSentence(this: this->m_pTempSentence);
    free(pMem: m_pTempSentence);
  }
  this->CAudioSourceWave::CAudioSource::__vftable = (CAudioSourceStreamWave_vtbl *)&CAudioSource::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1003FA60
// Name: public: virtual void CAudioSourceStreamWave::ParseChunk(class IterateRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceStreamWave::ParseChunk(CAudioSourceStreamWave *this, IterateRIFF *walk, int chunkName)
{
  int SamplePosition; // eax

  if ( chunkName == 1635017060 )
  {
    this->m_dataStart = walk->m_chunkPosition + 8;
    SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)walk);
    this->m_dataSize = SamplePosition;
    this->m_sampleCount = SamplePosition / this->m_sampleSize;
  }
  else
  {
    CAudioSourceWave::ParseChunk(this, walk, chunkName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FAA0
// Name: void MaybeReportMissingWav(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaybeReportMissingWav(char *wav)
{
  CUtlSymbol v1; // [esp+2h] [ebp-2h] BYREF

  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &wavErrors, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: MaybeReportMissingWav_::_2_::_dynamic_atexit_destructor_for__wavErrors__);
  }
  if ( CUtlSymbolTable::Find(this: &wavErrors, result: &v1, pString: wav)->m_Id == 0xFFFF )
  {
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: wav, a3: nullptr) )
      DevWarning(a1: "Bad Audio file '%s'\n", wav);
    else
      DevWarning(a1: "Missing wav file '%s'\n", wav);
    CUtlSymbolTable::AddString(this: &wavErrors, result: &v1, pString: wav);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FB40
// Name: Audio_GetADPCMWaveDuration
// Source: json
//------------------------------------------------------------------------------
float __usercall Audio_GetADPCMWaveDuration@<xmm0>(char *pName@<eax>)
{
  int v3; // esi
  int v4; // ebx
  int Wide; // eax
  int SamplePosition; // eax
  __int64 v7; // rax
  int v8; // ecx
  int v9; // edx
  int v10; // ebx
  char formatBuffer[1024]; // [esp+4h] [ebp-42Ch] BYREF
  InFileRIFF riff; // [esp+404h] [ebp-2Ch] BYREF
  IterateRIFF walk; // [esp+414h] [ebp-1Ch] BYREF
  float sampleRate; // [esp+42Ch] [ebp-4h]

  InFileRIFF::InFileRIFF(this: &riff, pFileName: pName, io: g_pSndIO);
  if ( riff.m_riffName == 1163280727 )
  {
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    v3 = 0;
    v4 = 0;
    while ( IterateRIFF::ChunkAvailable(this: &walk) )
    {
      if ( v3 != 0 && v4 != 0 )
        break;
      Wide = vgui::Image::GetWide(this: (CVTFTexture *)&walk);
      if ( Wide == 544501094 )
      {
        if ( (unsigned int)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&walk) <= 0x400 )
        {
          IterateRIFF::ChunkRead(this: &walk, pOutput: formatBuffer);
          CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&walk);
          v3 = *(unsigned __int16 *)formatBuffer;
        }
      }
      else if ( Wide == 1635017060 )
      {
        if ( v3 != 0 )
        {
          SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&walk);
          if ( v3 != 2 )
            SamplePosition /= *(unsigned __int16 *)&formatBuffer[14] >> 3;
          v4 = SamplePosition;
        }
      }
      else
      {
        vgui::Image::GetWide(this: (CVTFTexture *)&walk);
      }
      IterateRIFF::ChunkNext(this: &walk);
    }
    sampleRate = (float)*(unsigned int *)&formatBuffer[4];
    v7 = *(unsigned __int16 *)&formatBuffer[2] * (*(unsigned __int16 *)&formatBuffer[18] - 2);
    v8 = 7 * *(unsigned __int16 *)&formatBuffer[2] + (((int)v7 - HIDWORD(v7)) >> 1);
    v9 = v4 % v8;
    v10 = *(unsigned __int16 *)&formatBuffer[18] * (v4 / v8);
    if ( v9 != 0 )
      v10 += *(unsigned __int16 *)&formatBuffer[18] + 2 * (v9 - v8) / *(unsigned __int16 *)&formatBuffer[2];
    InFileRIFF::~InFileRIFF(this: &riff);
    return (float)v10 / sampleRate;
  }
  else
  {
    MaybeReportMissingWav(wav: pName);
    InFileRIFF::~InFileRIFF(this: &riff);
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FCB0
// Name: public: bool CUtlCachedFileData<class CAudioSourceCachedInfo>::ManifestExists(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::ManifestExists(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  const char *v1; // eax
  char manifest_name[512]; // [esp+0h] [ebp-200h] BYREF

  v1 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  V_strncpy(pDest: manifest_name, pSrc: v1, maxLen: 512);
  V_SetExtension(path: manifest_name, extension: ".manifest", pathStringLength: 512);
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD");
}

//------------------------------------------------------------------------------
// Address: 0x1003FDE0
// Name: protected: bool CUtlBuffer::GetTypeText<short>(short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<short>(CUtlBuffer *this, __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003FE50
// Name: protected: bool CUtlBuffer::GetTypeText<int>(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<int>(CUtlBuffer *this, int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003FFA0
// Name: public: virtual void CAudioSourceWave::GetCacheData(class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::GetCacheData(CAudioSourceWave *this, CAudioSourceCachedInfo *info)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  CSentence *v5; // eax
  CSentence *v6; // ebx
  char v7; // al
  CSentence *m_pTempSentence; // ebx
  void *v9; // ebx
  char v10; // cl

  CAudioSourceWave::GetStartupData(this);
  info->infolong ^= (info->infolong ^ (4 * this->m_bits)) & 0x7C;
  v3 = info->infolong
     ^ ((unsigned __int16)info->infolong
      ^ (unsigned __int16)((unsigned __int16)this->m_channels << 7))
     & 0x180;
  info->infolong = v3;
  v4 = v3 ^ ((unsigned __int16)v3 ^ (unsigned __int16)((unsigned __int16)this->m_sampleSize << 9)) & 0xE00;
  info->infolong = v4;
  info->infolong = v4 ^ ((unsigned __int16)v4 ^ (unsigned __int16)((unsigned __int16)this->m_format << 12)) & 0x3000;
  info->m_dataStart = this->m_dataStart;
  info->m_dataSize = this->m_dataSize;
  info->infolong ^= (info->infolong ^ (this->m_rate << 14)) & 0x7FFFC000;
  info->m_loopStart = this->m_loopStart;
  info->m_sampleCount = this->m_sampleCount;
  if ( this->m_pTempSentence != nullptr )
  {
    v5 = (CSentence *)MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v5 != nullptr )
      v6 = CSentence::CSentence(this: v5);
    else
      v6 = nullptr;
    CSentence::operator=(this: v6, src: this->m_pTempSentence);
    v7 = info->flagsbyte ^ (v6 != nullptr);
    info->m_pSentence = v6;
    info->flagsbyte ^= v7 & 1;
    m_pTempSentence = this->m_pTempSentence;
    if ( m_pTempSentence != nullptr )
    {
      CSentence::~CSentence(this: this->m_pTempSentence);
      free(pMem: m_pTempSentence);
    }
    this->m_pTempSentence = nullptr;
  }
  if ( this->m_pHeader != nullptr && this->m_nHeaderSize > 0 )
  {
    v9 = MemAlloc_Alloc(nSize: this->m_nHeaderSize);
    _V_memcpy(dest: v9, src: this->m_pHeader, count: this->m_nHeaderSize);
    v10 = info->flagsbyte ^ (4 * (v9 != nullptr));
    info->m_usHeaderSize = this->m_nHeaderSize;
    info->flagsbyte ^= v10 & 4;
    info->m_pHeader = (unsigned __int8 *)v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100400D0
// Name: public: virtual void CAudioSourceMemWave::ParseChunk(class IterateRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMemWave::ParseChunk(CAudioSourceMemWave *this, IterateRIFF *walk, int chunkName)
{
  if ( chunkName == 1635017060 )
    CAudioSourceMemWave::ParseDataChunk(this, walk);
  else
    CAudioSourceWave::ParseChunk(this, walk, chunkName);
}

//------------------------------------------------------------------------------
// Address: 0x10040130
// Name: public: virtual int CAudioSourceStreamWave::GetOutputData(void __near * __near *,__int64,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceStreamWave::GetOutputData(
        CAudioSourceStreamWave *this,
        void **pData,
        __int64 samplePosition,
        int sampleCount,
        char *copyBuf)
{
  const char *v6; // eax
  CFmtStrN<256> *v7; // eax
  void *v8; // eax
  IBaseFileSystem_vtbl *v9; // edi
  int v10; // eax
  IBaseFileSystem_vtbl *v11; // ebx
  int v12; // eax
  CFmtStrN<256> v14; // [esp+4h] [ebp-210h] BYREF
  char buf[260]; // [esp+110h] [ebp-104h] BYREF

  if ( this->GetType(this) != 1 )
    return 0;
  if ( this->m_hWaveFileAccess == nullptr )
  {
    v6 = this->GetFileName(this, a2: buf, a3: 260);
    v7 = CFmtStrN<256>::CFmtStrN<256>(this: &v14, pszFormat: "sound\\%s", v6);
    v8 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v7->m_szBuf, a3: "rb", a4: "GAME");
    this->m_hWaveFileAccess = v8;
    if ( v8 == nullptr )
      return 0;
  }
  v9 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v10 = ((int (__thiscall *)(CAudioSourceStreamWave *, _DWORD))this->SampleSize)(a1: this, a2: 0);
  ((void (__thiscall *)(IBaseFileSystem *, void *, _DWORD))v9->Seek)(
    a1: &g_pFullFileSystem->IBaseFileSystem,
    a2: this->m_hWaveFileAccess,
    a3: this->m_dataStart + samplePosition * v10);
  if ( copyBuf != nullptr )
  {
    v11 = g_pFullFileSystem->IBaseFileSystem::__vftable;
    v12 = ((int (__thiscall *)(CAudioSourceStreamWave *, void *))this->SampleSize)(
            a1: this,
            a2: this->m_hWaveFileAccess);
    ((void (__thiscall *)(IBaseFileSystem *, char *, int))v11->Read)(
      a1: &g_pFullFileSystem->IBaseFileSystem,
      a2: copyBuf,
      a3: sampleCount * v12);
  }
  *pData = copyBuf;
  return sampleCount;
}

//------------------------------------------------------------------------------
// Address: 0x10040220
// Name: Audio_GetWaveDuration
// Source: json
//------------------------------------------------------------------------------
__int64 __usercall Audio_GetWaveDuration@<xmm0>(char *pName@<esi>)
{
  char *v1; // eax
  CFmtStrN<256> *v2; // eax
  CAudioSourceCachedInfo *v3; // eax
  unsigned int infolong; // ecx
  int m_sampleCount; // eax
  unsigned int v6; // edx
  int v7; // ecx
  int v8; // edx
  __int64 result; // xmm0_8
  char *v10; // [esp+0h] [ebp-110h]
  CFmtStrN<256> v11; // [esp+4h] [ebp-10Ch] BYREF

  v1 = PSkipSoundChars(pch: v10);
  v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "sound/%s", v1);
  v3 = audiosourcecache->GetInfoByName(this: audiosourcecache, a2: v2->m_szBuf);
  if ( v3 == nullptr )
    return 0;
  infolong = v3->infolong;
  m_sampleCount = v3->m_sampleCount;
  v6 = infolong;
  v7 = (infolong >> 14) & 0x1FFFF;
  v8 = (v6 >> 12) & 3;
  if ( v8 == 0 || m_sampleCount == 0 )
    return 0;
  if ( v8 == 2 )
  {
    *(float *)&result = Audio_GetADPCMWaveDuration(pName);
  }
  else
  {
    HIDWORD(result) = 0;
    *(float *)&result = (float)m_sampleCount / (float)v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100402B0
// Name: float AudioSource_GetSoundDuration(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl AudioSource_GetSoundDuration(char *pName)
{
  if ( Audio_IsMP3(pName) )
    return GetMP3Duration_Helper(filename: pName);
  else
    return COERCE_FLOAT(Audio_GetWaveDuration(pName));
}

//------------------------------------------------------------------------------
// Address: 0x10040320
// Name: public: virtual void CAudioSourceCache::LevelInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::LevelInit(CAudioSourceCache *this, const char *mapname)
{
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+4h] [ebp-10Ch] BYREF

  v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, pszFormat: "%s/%s", "maps/soundcache", mapname);
  CUtlString::operator=(this: &this->m_szMapCacheBase, src: v3->m_szBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10040360
// Name: private: void CAudioSourceCache::GetAudioCacheLanguageSuffix(class CUtlString __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::GetAudioCacheLanguageSuffix(CAudioSourceCache *this, CUtlString *sLanguage)
{
  const char *v2; // eax
  const char *v3; // edi
  void *v4; // esi
  CFmtStrN<256> *v5; // eax
  char szCacheLanguage[1024]; // [esp+4h] [ebp-610h] BYREF
  char szLanguageList[260]; // [esp+404h] [ebp-210h] BYREF
  CFmtStrN<256> v8; // [esp+508h] [ebp-10Ch] BYREF

  v2 = g_pSoundServices->GetUILanguage(this: g_pSoundServices);
  v3 = v2;
  if ( v2 != nullptr && *v2 != 0 && _V_stricmp(s1: v2, s2: "english") != 0 )
  {
    V_snprintf(pDest: szLanguageList, maxLen: 260, pFormat: "%s/localization_cache_list.txt", "maps/soundcache");
    v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: szLanguageList, a3: "r", a4: 0);
    if ( v4 == nullptr )
    {
      v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "_%s", v3);
      goto LABEL_7;
    }
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: szCacheLanguage, a3: 1024, a4: v4);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
    if ( V_stristr(pStr: szCacheLanguage, pSearch: v3) != nullptr )
    {
      v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "_%s", v3);
LABEL_7:
      CUtlString::operator=(this: sLanguage, src: v5->m_szBuf);
      return;
    }
    CUtlString::operator=(this: sLanguage, src: defaultValue);
  }
  else
  {
    CUtlString::operator=(this: sLanguage, src: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040AC0
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040B00
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040B40
// Name: protected: void CUtlBuffer::PutTypeBin<short>(short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<short>(CUtlBuffer *this, __int16 src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 2) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned short>(
        this: &this->m_Byteswap,
        outputBuffer: &this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_WORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 2;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040BB0
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned int>(
        this: &this->m_Byteswap,
        outputBuffer: (int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040C20
// Name: public: CAudioSourceMemWave::CAudioSourceMemWave(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMemWave *__thiscall CAudioSourceMemWave::CAudioSourceMemWave(CAudioSourceMemWave *this, CSfxTable *pSfx)
{
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  *((_DWORD *)&this->CAudioSourceWave + 20) &= 0xFFFFFFF0;
  this->m_pSfx = pSfx;
  this->m_format = 0;
  this->m_pHeader = nullptr;
  this->m_nHeaderSize = 0;
  this->m_loopStart = -1;
  this->m_sampleSize = 1;
  this->m_sampleCount = 0;
  this->m_bits = 0;
  this->m_channels = 0;
  this->m_dataStart = 0;
  this->m_dataSize = 0;
  this->m_rate = 0;
  this->m_refCount = 0;
  this->m_pTempSentence = nullptr;
  this->m_nCachedDataSize = 0;
  this->m_numDecodedSamples = 0;
  this->__vftable = (CAudioSourceMemWave_vtbl *)&CAudioSourceMemWave::`vftable';
  this->m_hCache = 0;
  this->m_hStream = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10040C80
// Name: class CAudioSource __near * Audio_CreateStreamedWave(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceStreamMP3 *__cdecl Audio_CreateStreamedWave(CSfxTable *pSfx)
{
  char *FileName; // eax
  CAudioSourceStreamWave *v3; // esi
  bool IsPrecachedSound; // al
  CAudioSourceCachedInfo *(__thiscall *GetInfo)(IAudioSourceCache *, int, bool, CSfxTable *); // edx
  int v6; // eax
  CAudioSourceCachedInfo *v7; // ebx
  CAudioSourceStreamWave *v8; // eax
  char nameBuf[260]; // [esp+4h] [ebp-108h] BYREF
  BOOL v10; // [esp+108h] [ebp-4h]

  FileName = CSfxTable::GetFileName(this: pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  if ( Audio_IsMP3(pName: FileName) )
    return Audio_CreateStreamedMP3(pSfx);
  v3 = nullptr;
  IsPrecachedSound = CSfxTable::IsPrecachedSound(this: pSfx);
  GetInfo = audiosourcecache->GetInfo;
  LOBYTE(v10) = IsPrecachedSound;
  v6 = (int)GetInfo(this: audiosourcecache, a2: 1, a3: v10, a4: pSfx);
  v7 = (CAudioSourceCachedInfo *)v6;
  if ( v6 != 0 && (*(_BYTE *)(v6 + 4) & 3) != 0 )
  {
    v8 = (CAudioSourceStreamWave *)MemAlloc_Alloc(nSize: 0x60u);
    if ( v8 != nullptr )
    {
      v3 = CAudioSourceStreamWave::CAudioSourceStreamWave(this: v8, pSfx, info: v7);
      if ( v3 == nullptr || v3->Format(this: v3) != 0 )
        return (CAudioSourceStreamMP3 *)v3;
      ((void (__thiscall *)(CAudioSourceStreamWave *, int))v3->dtr_CAudioSource)(a1: v3, a2: 1);
    }
    return nullptr;
  }
  return (CAudioSourceStreamMP3 *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10040D30
// Name: class CAudioSource __near * Audio_CreateMemoryWave(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMP3Cache *__cdecl Audio_CreateMemoryWave(CSfxTable *pSfx)
{
  char *FileName; // eax
  CAudioSourceMemWave *v3; // esi
  bool IsPrecachedSound; // al
  CAudioSourceCachedInfo *(__thiscall *GetInfo)(IAudioSourceCache *, int, bool, CSfxTable *); // edx
  int v6; // eax
  CAudioSourceCachedInfo *v7; // ebx
  CAudioSourceMemWave *v8; // eax
  char nameBuf[260]; // [esp+4h] [ebp-108h] BYREF
  BOOL v10; // [esp+108h] [ebp-4h]

  FileName = CSfxTable::GetFileName(this: pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  if ( Audio_IsMP3(pName: FileName) )
    return Audio_CreateMemoryMP3(pSfx);
  v3 = nullptr;
  IsPrecachedSound = CSfxTable::IsPrecachedSound(this: pSfx);
  GetInfo = audiosourcecache->GetInfo;
  LOBYTE(v10) = IsPrecachedSound;
  v6 = (int)GetInfo(this: audiosourcecache, a2: 1, a3: v10, a4: pSfx);
  v7 = (CAudioSourceCachedInfo *)v6;
  if ( v6 != 0 && (*(_BYTE *)(v6 + 4) & 3) != 0 )
  {
    v8 = (CAudioSourceMemWave *)MemAlloc_Alloc(nSize: 0x60u);
    if ( v8 != nullptr )
    {
      v3 = CAudioSourceMemWave::CAudioSourceMemWave(this: v8, pSfx, info: v7);
      if ( v3 == nullptr || v3->Format(this: v3) != 0 )
        return (CAudioSourceMP3Cache *)v3;
      ((void (__thiscall *)(CAudioSourceMemWave *, int))v3->dtr_CAudioSource)(a1: v3, a2: 1);
    }
    return nullptr;
  }
  return (CAudioSourceMP3Cache *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10040DE0
// Name: public: virtual void CAudioSourceCachedInfo::Rebuild(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Rebuild(CAudioSourceCachedInfo *this, const char *filename)
{
  CAudioSourceMP3Cache *v3; // eax
  CAudioSourceMP3Cache *v4; // eax
  CAudioSourceMemWave *v5; // eax
  CAudioSourceMP3Cache *v6; // esi

  g_bSoundRebuilt = true;
  CAudioSourceCachedInfo::Clear(this);
  this->infolong ^= ((unsigned __int8)CAudioSourceCachedInfo::s_CurrentType ^ (unsigned __int8)this->infolong) & 3;
  if ( CAudioSourceCachedInfo::s_CurrentType == 1 )
  {
    v5 = (CAudioSourceMemWave *)MemAlloc_Alloc(nSize: 0x60u);
    if ( v5 != nullptr )
      v4 = (CAudioSourceMP3Cache *)CAudioSourceMemWave::CAudioSourceMemWave(
                                     this: v5,
                                     pSfx: CAudioSourceCachedInfo::s_pSfx);
    else
      v4 = nullptr;
    *((_DWORD *)&v4[1].CAudioSourceMP3 + 9) |= 8u;
    goto LABEL_9;
  }
  if ( CAudioSourceCachedInfo::s_CurrentType == 2 )
  {
    v3 = (CAudioSourceMP3Cache *)MemAlloc_Alloc(nSize: 0x2Cu);
    if ( v3 != nullptr )
    {
      v4 = CAudioSourceMP3Cache::CAudioSourceMP3Cache(this: v3, pSfx: CAudioSourceCachedInfo::s_pSfx);
LABEL_9:
      v6 = v4;
      if ( v4 != nullptr )
      {
        v4->GetCacheData(this: v4, a2: this);
        ((void (__thiscall *)(CAudioSourceMP3Cache *, int))v6->dtr_CAudioSource)(a1: v6, a2: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040E70
// Name: public: void CAudioSourceCache::WriteManifest(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAudioSourceCache::WriteManifest(CAudioSourceCache *this@<ecx>, int a2@<esi>)
{
  int v3; // edi
  int i; // esi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  void *v8; // eax
  void *v9; // esi
  char full[512]; // [esp+8h] [ebp-430h] BYREF
  char manifest_name[512]; // [esp+208h] [ebp-230h] BYREF
  CUtlBuffer buf; // [esp+408h] [ebp-30h] BYREF

  v3 = g_pSoundServices->GetPrecachedSoundCount(this: g_pSoundServices);
  if ( v3 != 0 )
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
    for ( i = 0; i < v3; ++i )
    {
      v5 = g_pSoundServices->GetPrecachedSound(this: g_pSoundServices, a2: i);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = PSkipSoundChars(pch: v5);
        V_snprintf(pDest: full, maxLen: 512, pFormat: "sound\\%s", v6);
        _V_strlower(start: full);
        V_FixSlashes(pname: full, separator: 92);
        CUtlBuffer::Printf(this: &buf, pFmt: "\"%s\"\r\n", full);
      }
    }
    ((void (__thiscall *)(IFileSystem *, const char *, const char *, int))g_pFullFileSystem->CreateDirHierarchy)(
      a1: g_pFullFileSystem,
      a2: "maps/soundcache",
      a3: "MOD",
      a4: a2);
    v7 = CUtlString::operator char const *(this: &this->m_szMapCacheBase);
    V_snprintf(pDest: manifest_name, maxLen: 512, pFormat: "%s.manifest", v7);
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD")
      && !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD") )
    {
      g_pFullFileSystem->SetFileWritable(
        this: &g_pFullFileSystem->IBaseFileSystem,
        a2: manifest_name,
        a3: true,
        a4: "MOD");
    }
    v8 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *))g_pFullFileSystem->Open)(
                   a1: &g_pFullFileSystem->IBaseFileSystem,
                   a2: manifest_name,
                   a3: "wb");
    v9 = v8;
    if ( v8 != nullptr )
    {
      g_pFullFileSystem->Write(
        this: &g_pFullFileSystem->IBaseFileSystem,
        a2: buf.m_Memory.m_pMemory,
        a3: buf.m_Put,
        a4: v8);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v9);
      DevMsg(a1: "WriteManifest:  Persisting cache manifest '%s' (%d entries)\n", manifest_name, v3);
    }
    else
    {
      _Warning(a1: "WriteManifest:  Unable to persist cache manifest '%s', check file permissions\n", manifest_name);
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
  else
  {
    DevMsg(a1: "Skipping WriteManifest, no entries in sound precache string table\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041070
// Name: snd_writemanifest
// Source: json
//------------------------------------------------------------------------------
void __usercall snd_writemanifest(int a1@<esi>)
{
  CAudioSourceCache::WriteManifest(this: &g_ASCache, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10041C70
// Name: public: char CUtlBuffer::GetChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al

  if ( !CUtlBuffer::CheckGet(this, nSize: 1) )
    return 0;
  result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  ++this->m_Get;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10041CA0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041CF0
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041D50
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041D90
// Name: public: virtual void CAudioSourceWave::ParseSentence(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ParseSentence(CAudioSourceWave *this, IterateRIFF *walk)
{
  int SamplePosition; // eax
  int v4; // eax
  CSentence *v5; // eax
  CSentence *v6; // eax
  unsigned __int8 *m_pMemory; // [esp-8h] [ebp-40h]
  int m_Put; // [esp-4h] [ebp-3Ch]
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)walk);
  CUtlBuffer::EnsureCapacity(this: &buf, num: SamplePosition);
  IterateRIFF::ChunkRead(this: walk, pOutput: buf.m_Memory.m_pMemory);
  v4 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)walk);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v4);
  v5 = (CSentence *)MemAlloc_Alloc(nSize: 0x4Cu);
  if ( v5 != nullptr )
    v6 = CSentence::CSentence(this: v5);
  else
    v6 = nullptr;
  m_Put = buf.m_Put;
  m_pMemory = buf.m_Memory.m_pMemory;
  this->m_pTempSentence = v6;
  CSentence::InitFromDataChunk(this: v6, data: m_pMemory, size: m_Put);
  CSentence::MakeRuntimeOnly(this: this->m_pTempSentence);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10041E30
// Name: public: CAudioSourceCache::~CAudioSourceCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::~CAudioSourceCache(CAudioSourceCache *this)
{
  this->m_szCurrentLanguage.m_Storage.m_nActualLength = 0;
  if ( this->m_szCurrentLanguage.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory);
      this->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szCurrentLanguage.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_szMasterCache.m_Storage.m_nActualLength = 0;
  if ( this->m_szMasterCache.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szMasterCache.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szMasterCache.m_Storage.m_Memory.m_pMemory);
      this->m_szMasterCache.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szMasterCache.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_szMapCacheBase.m_Storage.m_nActualLength = 0;
  if ( this->m_szMapCacheBase.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szMapCacheBase.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szMapCacheBase.m_Storage.m_Memory.m_pMemory);
      this->m_szMapCacheBase.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szMapCacheBase.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_szMODPath.m_Storage.m_nActualLength = 0;
  if ( this->m_szMODPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szMODPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szMODPath.m_Storage.m_Memory.m_pMemory);
      this->m_szMODPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szMODPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041ED0
// Name: public: virtual void CAudioSourceCache::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::LevelShutdown(CAudioSourceCache *this)
{
  int v2; // eax

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-makereslists") != 0
    && g_pSoundServices->GetPrecachedSoundCount(this: g_pSoundServices) != 0
    && g_pSoundServices->GetServerCount(this: g_pSoundServices) != this->m_nServerCount )
  {
    this->m_nServerCount = g_pSoundServices->GetServerCount(this: g_pSoundServices);
    CAudioSourceCache::WriteManifest(this, a2: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041F30
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::ForceRecheckDiskInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::ForceRecheckDiskInfo(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  unsigned __int16 i; // ax

  for ( i = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements,
              i) )
  {
    this->m_Elements.m_Elements.m_pMemory[i].m_Data.diskfileinfo = -2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041FF0
// Name: public: short CUtlBuffer::GetShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: (__int16 *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10042090
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10042130
// Name: public: void CUtlBuffer::PutInt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutInt(CUtlBuffer *this, int i)
{
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this, pFmt: "%d", i);
  else
    CUtlBuffer::PutTypeBin<int>(this, src: i);
}

//------------------------------------------------------------------------------
// Address: 0x10042160
// Name: public: virtual void CAudioSourceCachedInfo::Save(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Save(CAudioSourceCachedInfo *this, CUtlBuffer *buf)
{
  unsigned __int8 flagsbyte; // bl
  int m_Put; // eax
  unsigned int infolong; // [esp-4h] [ebp-Ch]
  int m_dataStart; // [esp-4h] [ebp-Ch]
  int m_dataSize; // [esp-4h] [ebp-Ch]
  int m_loopStart; // [esp-4h] [ebp-Ch]
  int m_sampleCount; // [esp-4h] [ebp-Ch]
  int m_usCachedDataSize; // [esp-4h] [ebp-Ch]

  infolong = this->infolong;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", infolong);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: infolong);
  flagsbyte = this->flagsbyte;
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = flagsbyte;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
  m_dataStart = this->m_dataStart;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_dataStart);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_dataStart);
  m_dataSize = this->m_dataSize;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_dataSize);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_dataSize);
  m_loopStart = this->m_loopStart;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_loopStart);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_loopStart);
  m_sampleCount = this->m_sampleCount;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_sampleCount);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_sampleCount);
  if ( (this->flagsbyte & 1) != 0 )
    CSentence::CacheSaveToBuffer(this: this->m_pSentence, buf, version: 1);
  if ( (this->flagsbyte & 2) != 0 && this->m_pCachedData != nullptr )
  {
    m_usCachedDataSize = this->m_usCachedDataSize;
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%d", m_usCachedDataSize);
    else
      CUtlBuffer::PutTypeBin<int>(this: buf, src: m_usCachedDataSize);
    CUtlBuffer::Put(this: buf, pMem: this->m_pCachedData, size: this->m_usCachedDataSize);
  }
  if ( (this->flagsbyte & 4) != 0 )
  {
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%hd", (__int16)this->m_usHeaderSize);
    else
      CUtlBuffer::PutTypeBin<short>(this: buf, src: this->m_usHeaderSize);
    CUtlBuffer::Put(this: buf, pMem: this->m_pHeader, size: this->m_usHeaderSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100422F0
// Name: public: virtual void CAudioSourceCachedInfo::Restore(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Restore(CAudioSourceCachedInfo *this, CUtlBuffer *buf)
{
  unsigned __int8 v3; // al
  int Int; // eax
  bool v5; // zf
  CSentence *v6; // eax
  CSentence *v7; // eax
  unsigned __int16 v8; // ax
  void *v9; // ebx
  char v10; // dl
  unsigned __int16 Short; // ax
  void *v12; // ebx
  char v13; // dl

  CAudioSourceCachedInfo::Clear(this);
  this->infolong = CUtlBuffer::GetInt(this: buf);
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
    ++buf->m_Get;
  }
  else
  {
    v3 = 0;
  }
  this->flagsbyte = v3;
  this->m_dataStart = CUtlBuffer::GetInt(this: buf);
  this->m_dataSize = CUtlBuffer::GetInt(this: buf);
  this->m_loopStart = CUtlBuffer::GetInt(this: buf);
  Int = CUtlBuffer::GetInt(this: buf);
  v5 = (this->flagsbyte & 1) == 0;
  this->m_sampleCount = Int;
  if ( !v5 )
  {
    v6 = (CSentence *)MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v6 != nullptr )
      v7 = CSentence::CSentence(this: v6);
    else
      v7 = nullptr;
    this->m_pSentence = v7;
    CSentence::CacheRestoreFromBuffer(this: v7, buf);
  }
  if ( (this->flagsbyte & 2) != 0 )
  {
    v8 = CUtlBuffer::GetInt(this: buf);
    this->m_usCachedDataSize = v8;
    if ( v8 != 0 )
    {
      v9 = MemAlloc_Alloc(nSize: v8);
      CUtlBuffer::Get(this: buf, pMem: v9, size: this->m_usCachedDataSize);
      v10 = this->flagsbyte ^ (2 * (v9 != nullptr));
      this->m_pCachedData = (unsigned __int8 *)v9;
      this->flagsbyte ^= v10 & 2;
    }
  }
  if ( (this->flagsbyte & 4) != 0 )
  {
    Short = CUtlBuffer::GetShort(this: buf);
    this->m_usHeaderSize = Short;
    if ( Short != 0 )
    {
      v12 = MemAlloc_Alloc(nSize: Short);
      CUtlBuffer::Get(this: buf, pMem: v12, size: this->m_usHeaderSize);
      v13 = this->flagsbyte ^ (4 * (v12 != nullptr));
      this->m_pHeader = (unsigned __int8 *)v12;
      this->flagsbyte ^= v13 & 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042420
// Name: public: CUtlCachedFileData<class CAudioSourceCachedInfo>::CUtlCachedFileData<class CAudioSourceCachedInfo>(char const __near *,int,unsigned int (*)(void),enum UtlCachedFileDataType_t,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CUtlCachedFileData<CAudioSourceCachedInfo> *__thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::CUtlCachedFileData<CAudioSourceCachedInfo>(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        char *repositoryFileName,
        int version,
        unsigned int (__cdecl *checksumfunc)(),
        UtlCachedFileDataType_t fileCheckType,
        bool nevercheckdisk,
        bool readonly,
        bool savemanifest)
{
  char v9; // dl

  this->__vftable = (CUtlCachedFileData<CAudioSourceCachedInfo>_vtbl *)&CUtlCachedFileData<CAudioSourceCachedInfo>::`vftable';
  this->m_Elements.m_LessFunc = (bool (__cdecl *)(const CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *, const CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *))CDmxSerializationDictionary::LessFunc;
  this->m_Elements.m_Elements.m_pMemory = nullptr;
  this->m_Elements.m_Elements.m_nAllocationCount = 0;
  this->m_Elements.m_Elements.m_nGrowSize = 0;
  this->m_Elements.m_pElements = this->m_Elements.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Elements.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Elements.m_FirstFree = -1;
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_sRepositoryFileName, pString: repositoryFileName);
  this->m_nVersion = version;
  this->m_pfnMetaChecksum = checksumfunc;
  this->m_fileCheckType = fileCheckType;
  v9 = *((_BYTE *)this + 84) & 0xE0;
  this->m_uCurrentMetaChecksum = 0;
  *((_BYTE *)this + 84) = nevercheckdisk | v9 | (2 * (readonly | (2 * savemanifest)));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100424B0
// Name: public: virtual CUtlCachedFileData<class CAudioSourceCachedInfo>::~CUtlCachedFileData<class CAudioSourceCachedInfo>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::~CUtlCachedFileData<CAudioSourceCachedInfo>(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl*)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short> > *p_m_Elements; // ebx
  int m_Size; // eax
  int v4; // edi
  CAudioSourceCachedInfo *v5; // ecx
  CAudioSourceCachedInfo **m_pMemory; // eax
  int c; // [esp+Ch] [ebp-4h]

  p_m_Elements = &this->m_Elements;
  this->__vftable = (CUtlCachedFileData<CAudioSourceCachedInfo>_vtbl *)&CUtlCachedFileData<CAudioSourceCachedInfo>::`vftable';
  CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements);
  m_Size = this->m_Data.m_Size;
  v4 = 0;
  for ( c = m_Size; v4 < m_Size; ++v4 )
  {
    v5 = this->m_Data.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      ((void (__thiscall *)(CAudioSourceCachedInfo *, int))v5->dtr_CAudioSourceCachedInfo)(a1: v5, a2: 1);
      m_Size = c;
    }
  }
  this->m_Data.m_Size = 0;
  this->m_sRepositoryFileName.m_Storage.m_nActualLength = 0;
  if ( this->m_sRepositoryFileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sRepositoryFileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sRepositoryFileName.m_Storage.m_Memory.m_pMemory);
      this->m_sRepositoryFileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sRepositoryFileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Data.m_Size = 0;
  if ( this->m_Data.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Data.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Data.m_Memory.m_pMemory);
      this->m_Data.m_Memory.m_pMemory = nullptr;
    }
    this->m_Data.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  this->m_Data.m_pElements = m_pMemory;
  if ( this->m_Data.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Data.m_Memory.m_pMemory = nullptr;
    }
    this->m_Data.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: p_m_Elements);
  p_m_Elements->m_FirstFree = -1;
  if ( p_m_Elements->m_Elements.m_nGrowSize >= 0 )
  {
    if ( p_m_Elements->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Elements->m_Elements.m_pMemory);
      p_m_Elements->m_Elements.m_pMemory = nullptr;
    }
    p_m_Elements->m_Elements.m_nAllocationCount = 0;
  }
  p_m_Elements->m_LastAlloc.index = -1;
  if ( p_m_Elements->m_Elements.m_nGrowSize >= 0 )
  {
    if ( p_m_Elements->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Elements->m_Elements.m_pMemory);
      p_m_Elements->m_Elements.m_pMemory = nullptr;
    }
    p_m_Elements->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042670
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::SaveManifest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::SaveManifest(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  signed int m_Size; // esi
  CUtlCachedFileData<CAudioSourceCachedInfo> *v2; // ebx
  int Inorder; // edi
  signed int v4; // ebx
  CSortedCacheFile *m_pMemory; // ecx
  CSortedCacheFile *v6; // ebx
  int *p_index; // edi
  const char *v8; // eax
  const char *v9; // eax
  void *v10; // eax
  void *v11; // esi
  char fn[512]; // [esp+Ch] [ebp-660h] BYREF
  char path[512]; // [esp+20Ch] [ebp-460h] BYREF
  char manifest_name[512]; // [esp+40Ch] [ebp-260h] BYREF
  char v15; // [esp+60Ch] [ebp-60h] BYREF
  CUtlBuffer buf; // [esp+614h] [ebp-58h] BYREF
  CSortedCacheFile insert; // [esp+644h] [ebp-28h] BYREF
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+64Ch] [ebp-20h] BYREF
  CUtlCachedFileData<CAudioSourceCachedInfo> *i; // [esp+668h] [ebp-4h]

  m_Size = 0;
  v2 = this;
  i = this;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1u);
  memset(&list, 0, 25);
  Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: &v2->m_Elements);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      insert.handle = v2->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
      list.m_bNeedsSort = true;
      v4 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)&list,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
      }
      m_pMemory = list.m_Memory.m_pMemory;
      list.m_Size = ++m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( m_Size - v4 - 1 > 0 )
      {
        _V_memmove(
          dest: &list.m_Memory.m_pMemory[v4 + 1],
          src: &list.m_Memory.m_pMemory[v4],
          count: 8 * (m_Size - v4 - 1));
        m_pMemory = list.m_Memory.m_pMemory;
      }
      v6 = &m_pMemory[v4];
      if ( v6 != nullptr )
      {
        v6->handle = insert.handle;
        v6->index = Inorder;
      }
      Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                    this: &i->m_Elements,
                                    i: Inorder);
      if ( Inorder == 0xFFFF )
        break;
      v2 = i;
    }
    if ( list.m_bNeedsSort && m_Size > 1 )
    {
      insert.handle = list.m_pLessContext;
      insert.index = (int)&v15;
      qsort_s(
        base: list.m_Memory.m_pMemory,
        num: m_Size,
        width: 8u,
        comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper,
        context: &insert);
    }
    v2 = i;
  }
  if ( m_Size > 0 )
  {
    p_index = &list.m_Memory.m_pMemory->index;
    for ( i = (CUtlCachedFileData<CAudioSourceCachedInfo> *)m_Size;
          i != nullptr;
          i = (CUtlCachedFileData<CAudioSourceCachedInfo> *)((char *)i - 1) )
    {
      ((void (__stdcall *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *, char *, int))g_pFullFileSystem->String)(
        a1: &v2->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)p_index].m_Data,
        a2: fn,
        a3: 512);
      CUtlBuffer::Printf(this: &buf, pFmt: "\"%s\"\r\n", fn);
      p_index += 2;
    }
  }
  v8 = CUtlString::operator char const *(this: &v2->m_sRepositoryFileName);
  V_strncpy(pDest: path, pSrc: v8, maxLen: 512);
  V_StripFilename(path);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: path, a3: "MOD");
  v9 = CUtlString::operator char const *(this: &v2->m_sRepositoryFileName);
  V_strncpy(pDest: manifest_name, pSrc: v9, maxLen: 512);
  V_SetExtension(path: manifest_name, extension: ".manifest", pathStringLength: 512);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD")
    && !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD") )
  {
    g_pFullFileSystem->SetFileWritable(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: manifest_name,
      a3: true,
      a4: "MOD");
  }
  v10 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "wb", a4: 0);
  v11 = v10;
  if ( v10 != nullptr )
  {
    g_pFullFileSystem->Write(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: buf.m_Memory.m_pMemory,
      a3: buf.m_Put,
      a4: v10);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v11);
  }
  else
  {
    _Warning(a1: "Unable to persist cache manifest '%s', check file permissions\n", manifest_name);
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10042960
// Name: private: class CUtlCachedFileData<class CAudioSourceCachedInfo> __near * CAudioSourceCache::AllocAudioCache(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CUtlCachedFileData<CAudioSourceCachedInfo> *__thiscall CAudioSourceCache::AllocAudioCache(
        CAudioSourceCache *this,
        const char *cachename,
        bool bNeverCheckDisk)
{
  CUtlCachedFileData<CAudioSourceCachedInfo> *v4; // esi
  const char *v5; // eax
  CFmtStrN<256> *v6; // eax
  CFmtStrN<256> v8; // [esp+8h] [ebp-10Ch] BYREF

  v4 = (CUtlCachedFileData<CAudioSourceCachedInfo> *)MemAlloc_Alloc(nSize: 0x58u);
  if ( v4 == nullptr )
    return nullptr;
  v5 = CUtlString::operator char const *(this: &this->m_szMODPath);
  v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "%s%s", v5, cachename);
  return CUtlCachedFileData<CAudioSourceCachedInfo>::CUtlCachedFileData<CAudioSourceCachedInfo>(
           this: v4,
           repositoryFileName: v6->m_szBuf,
           version: 3,
           checksumfunc: nullptr,
           fileCheckType: UTL_CACHED_FILE_USE_FILESIZE,
           nevercheckdisk: bNeverCheckDisk,
           readonly: false,
           savemanifest: false);
}

//------------------------------------------------------------------------------
// Address: 0x100429D0
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::Save(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::Save(CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  void *v7; // eax
  void *v8; // edi
  const char *v9; // eax
  int m_Size; // ebx
  int Inorder; // ecx
  CSortedCacheFile *v12; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // ebx
  int fileinfo; // eax
  CAudioSourceCachedInfo *v15; // ecx
  char fn[512]; // [esp+Ch] [ebp-470h] BYREF
  char path[512]; // [esp+20Ch] [ebp-270h] BYREF
  char v18; // [esp+40Ch] [ebp-70h] BYREF
  int inputBuffer; // [esp+410h] [ebp-6Ch] BYREF
  CUtlBuffer buf; // [esp+414h] [ebp-68h] BYREF
  int c; // [esp+444h] [ebp-38h] BYREF
  int j; // [esp+448h] [ebp-34h]
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+44Ch] [ebp-30h] BYREF
  CSortedCacheFile insert; // [esp+468h] [ebp-14h] BYREF
  int v; // [esp+470h] [ebp-Ch] BYREF
  int bufsize; // [esp+474h] [ebp-8h] BYREF
  int i; // [esp+478h] [ebp-4h]

  v2 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  V_strncpy(pDest: path, pSrc: v2, maxLen: 512);
  V_StripFilename(path);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: path, a3: "MOD");
  v3 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: "MOD") )
  {
    v4 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    if ( !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4, a3: "MOD") )
    {
      v5 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      g_pFullFileSystem->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: true, a4: "MOD");
    }
  }
  v6 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  v7 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6, a3: "wb", a4: 0);
  v8 = v7;
  if ( v7 != nullptr )
  {
    *((_BYTE *)this + 84) &= ~8u;
    v = 2;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v7);
    v = this->m_nVersion;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v8);
    v = this->m_uCurrentMetaChecksum;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v8);
    c = this->m_Elements.m_NumElements;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &c, a3: 4, a4: v8);
    m_Size = 0;
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    memset(&list, 0, 25);
    Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements);
    i = Inorder;
    if ( Inorder != 0xFFFF )
    {
      while ( 1 )
      {
        insert.handle = this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
        list.m_bNeedsSort = true;
        bufsize = m_Size;
        if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
            this: (CUtlMemory<ResourceEntryInfo,int> *)&list,
            num: m_Size - list.m_Memory.m_nAllocationCount + 1);
          m_Size = list.m_Size;
          Inorder = i;
        }
        ++m_Size;
        list.m_pElements = list.m_Memory.m_pMemory;
        list.m_Size = m_Size;
        if ( m_Size - bufsize - 1 > 0 )
        {
          _V_memmove(
            dest: &list.m_Memory.m_pMemory[bufsize + 1],
            src: &list.m_Memory.m_pMemory[bufsize],
            count: 8 * (m_Size - bufsize - 1));
          Inorder = i;
        }
        v12 = &list.m_Memory.m_pMemory[bufsize];
        if ( v12 != nullptr )
        {
          v12->handle = insert.handle;
          v12->index = Inorder;
        }
        i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_Elements,
                                i: Inorder);
        if ( i == 0xFFFF )
          break;
        Inorder = i;
      }
      if ( list.m_bNeedsSort && m_Size > 1 )
      {
        insert.handle = list.m_pLessContext;
        insert.index = (int)&v18;
        qsort_s(
          base: list.m_Memory.m_pMemory,
          num: m_Size,
          width: 8u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper,
          context: &insert);
      }
    }
    if ( m_Size > 0 )
    {
      i = (int)&list.m_Memory.m_pMemory->index;
      for ( j = m_Size; j != 0; --j )
      {
        p_m_Data = &this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)i].m_Data;
        CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: 0);
        g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)p_m_Data, a3: fn, a4: 512);
        CUtlBuffer::PutString(this: &buf, pString: fn);
        fileinfo = p_m_Data->fileinfo;
        insert.index = fileinfo;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%d", fileinfo);
        }
        else
        {
          inputBuffer = fileinfo;
          if ( CUtlBuffer::CheckPut(this: &buf, nSize: 4) != 0 )
          {
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &buf.m_Byteswap,
                outputBuffer: (int *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = insert.index;
            buf.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
          }
        }
        v15 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
        v15->Save(this: v15, a2: &buf);
        bufsize = buf.m_Put;
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &bufsize, a3: 4, a4: v8);
        g_pFullFileSystem->Write(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: buf.m_Memory.m_pMemory,
          a3: bufsize,
          a4: v8);
        i += 8;
      }
    }
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8);
    if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
  else
  {
    v9 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Warning(a1: "Unable to persist cache '%s', check file permissions\n", v9);
  }
  if ( (*((_BYTE *)this + 84) & 4) != 0 )
    CUtlCachedFileData<CAudioSourceCachedInfo>::SaveManifest(this);
}

//------------------------------------------------------------------------------
// Address: 0x10042E60
// Name: private: void CAudioSourceCache::RecursiveBuildSoundList(class CUtlRBTree<void __near *,int,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,int>,int>> __near &,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::RecursiveBuildSoundList(
        CAudioSourceCache *this,
        CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *root,
        const char *pLanguage,
        const char *pCurrentDir,
        const char *pathID)
{
  const char *v5; // ebx
  const char *v6; // esi
  char path[512]; // [esp+8h] [ebp-414h] BYREF
  char relative[512]; // [esp+208h] [ebp-214h] BYREF
  char ext[12]; // [esp+408h] [ebp-14h] BYREF
  CAudioSourceCache *v10; // [esp+414h] [ebp-8h]
  void *handle; // [esp+418h] [ebp-4h] BYREF

  v5 = pCurrentDir;
  v10 = this;
  V_snprintf(pDest: path, maxLen: 512, pFormat: "%s/*.*", pCurrentDir);
  V_FixSlashes(pname: path, separator: 92);
  v6 = g_pFullFileSystem->FindFirstEx(this: g_pFullFileSystem, a2: path, a3: pathID, a4: &pCurrentDir);
  if ( v6 != nullptr )
  {
    do
    {
      if ( *v6 != 46 )
      {
        if ( g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: (int)pCurrentDir) )
        {
          V_snprintf(pDest: relative, maxLen: 512, pFormat: "%s/%s", v5, v6);
          CAudioSourceCache::RecursiveBuildSoundList(this: v10, root, pLanguage, pCurrentDir: relative, pathID);
        }
        else
        {
          V_ExtractFileExtension(path: v6, dest: ext, destSize: 10);
          if ( (_V_stricmp(s1: ext, s2: "wav") == 0 || _V_stricmp(s1: ext, s2: "mp3") == 0)
            && V_stristr(pStr: v6, pSearch: ".360.") == nullptr
            && V_stristr(pStr: v6, pSearch: ".ps3.") == nullptr )
          {
            V_snprintf(pDest: relative, maxLen: 512, pFormat: "%s/%s", v5, v6);
            V_FixSlashes(pname: relative, separator: 92);
            handle = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: relative);
            if ( CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Find(
                   this: root,
                   search: &handle) == -1 )
              CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Insert(
                this: root,
                insert: &handle);
          }
        }
      }
      v6 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: pCurrentDir);
    }
    while ( v6 != nullptr );
    g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)pCurrentDir);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043020
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::Shutdown(CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  char v2; // al
  char v3; // al

  v2 = *((_BYTE *)this + 84);
  if ( (v2 & 0x10) != 0 )
  {
    v3 = v2 & 0xEF;
    *((_BYTE *)this + 84) = v3;
    if ( (v3 & 8) != 0 )
    {
      CUtlCachedFileData<CAudioSourceCachedInfo>::Save(this);
      CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements);
    }
    else
    {
      if ( (v3 & 4) != 0 && !CUtlCachedFileData<CAudioSourceCachedInfo>::ManifestExists(this) )
        CUtlCachedFileData<CAudioSourceCachedInfo>::SaveManifest(this);
      CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043060
// Name: private: int CUtlCachedFileData<class CAudioSourceCachedInfo>::GetIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        CAudioSourceCachedInfo *filename)
{
  int result; // eax
  CAudioSourceCachedInfo *v4; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CAudioSourceCachedInfo **m_pMemory; // ecx
  int v8; // eax
  CAudioSourceCachedInfo **v9; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t element; // [esp+8h] [ebp-14h] BYREF
  CAudioSourceCachedInfo *data; // [esp+24h] [ebp+8h]

  element.handle = nullptr;
  element.fileinfo = 0;
  element.diskfileinfo = -2;
  element.dataIndex = -1;
  element.handle = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: filename);
  result = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::Find(
             this: &this->m_Elements,
             search: &element);
  if ( (unsigned __int16)result == 0xFFFF )
  {
    v4 = (CAudioSourceCachedInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
    if ( v4 != nullptr )
    {
      v4->__vftable = (CAudioSourceCachedInfo_vtbl *)&CAudioSourceCachedInfo::`vftable';
      v4->infolong = 0;
      v4->flagsbyte = 0;
      v4->m_loopStart = 0;
      v4->m_sampleCount = 0;
      v4->m_dataStart = 0;
      v4->m_dataSize = 0;
      *(_DWORD *)&v4->m_usCachedDataSize = 0;
      v4->m_pSentence = nullptr;
      v4->m_pCachedData = nullptr;
      v4->m_pHeader = nullptr;
      data = v4;
    }
    else
    {
      data = nullptr;
    }
    m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
    m_Size = this->m_Data.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_Data,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Data.m_Size;
    m_pMemory = this->m_Data.m_Memory.m_pMemory;
    v8 = this->m_Data.m_Size - m_Size - 1;
    this->m_Data.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_Data.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = data;
    result = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::Insert(
               this: &this->m_Elements,
               insert: &element);
    this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)result].m_Data.dataIndex = m_Size;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10043170
// Name: private: void CUtlCachedFileData<class CAudioSourceCachedInfo>::InitSmallBuffer(void __near * __near &,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::InitSmallBuffer(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        void **fh,
        int fileSize,
        bool *deleteFile)
{
  int Int; // eax
  const char *v6; // eax
  int v7; // esi
  int v8; // esi
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // esi
  int v10; // eax
  CAudioSourceCachedInfo *v11; // ecx
  const char *v12; // eax
  const char *v13; // eax
  char elementFileName[512]; // [esp+Ch] [ebp-264h] BYREF
  CUtlBuffer loadBuf; // [esp+20Ch] [ebp-64h] BYREF
  CUtlBuffer buf; // [esp+23Ch] [ebp-34h] BYREF
  int cacheversion; // [esp+26Ch] [ebp-4h] BYREF
  bool *deleteFilea; // [esp+280h] [ebp+10h]

  *deleteFile = false;
  CUtlBuffer::CUtlBuffer(this: &loadBuf, growSize: 0, initSize: 0, nFlags: 0);
  g_pFullFileSystem->ReadToBuffer(this: g_pFullFileSystem, a2: *fh, a3: &loadBuf, a4: 0, a5: nullptr);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: *fh);
  cacheversion = 0;
  CUtlBuffer::Get(this: &loadBuf, pMem: (unsigned __int8 *)&cacheversion, size: 4);
  if ( cacheversion != 2 )
  {
    v13 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    DevMsg(a1: "Discarding repository '%s' due to cache system version change\n", v13);
    goto LABEL_17;
  }
  if ( CUtlBuffer::GetInt(this: &loadBuf) != this->m_nVersion )
  {
    v12 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Msg(a1: "Discarding repository '%s' due to version change\n", v12);
    *deleteFile = true;
    goto LABEL_18;
  }
  Int = CUtlBuffer::GetInt(this: &loadBuf);
  if ( this->m_pfnMetaChecksum != nullptr && Int != this->m_uCurrentMetaChecksum )
  {
    v6 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Msg(a1: "Discarding repository '%s' due to meta checksum change\n", v6);
LABEL_17:
    *deleteFile = true;
    goto LABEL_18;
  }
  v7 = CUtlBuffer::GetInt(this: &loadBuf);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( v7 > 0 )
  {
    for ( deleteFilea = (bool *)v7; deleteFilea != nullptr; --deleteFilea )
    {
      v8 = CUtlBuffer::GetInt(this: &loadBuf);
      memset(&buf.m_Get, 0, 9);
      buf.m_nOffset = 0;
      buf.m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
      CUtlBuffer::EnsureCapacity(this: &buf, num: v8);
      CUtlBuffer::Get(this: &loadBuf, pMem: buf.m_Memory.m_pMemory, size: v8);
      CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v8);
      CUtlBuffer::GetString(this: &buf, pString: elementFileName, nMaxChars: 512);
      p_m_Data = &this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(
                                                                            this,
                                                                            filename: (CAudioSourceCachedInfo *)elementFileName)].m_Data;
      v10 = CUtlBuffer::GetInt(this: &buf);
      p_m_Data->fileinfo = v10;
      if ( v10 == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
        p_m_Data->fileinfo = 0;
      v11 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
      v11->Restore(this: v11, a2: &buf);
    }
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
LABEL_18:
  if ( loadBuf.m_Memory.m_nGrowSize >= 0 && loadBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: loadBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10043370
// Name: private: void CUtlCachedFileData<class CAudioSourceCachedInfo>::InitLargeBuffer(void __near * __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::InitLargeBuffer(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        void **fh,
        bool *deleteFile)
{
  void **v3; // edi
  const char *v5; // eax
  int v6; // edi
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // edi
  int Int; // eax
  CAudioSourceCachedInfo *v9; // ecx
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  void *v13; // [esp-4h] [ebp-258h]
  void *v14; // [esp-4h] [ebp-258h]
  void *v15; // [esp-4h] [ebp-258h]
  void *v16; // [esp-4h] [ebp-258h]
  void *v17; // [esp-4h] [ebp-258h]
  char elementFileName[512]; // [esp+Ch] [ebp-248h] BYREF
  CUtlBuffer buf; // [esp+20Ch] [ebp-48h] BYREF
  unsigned int cache_meta_checksum; // [esp+23Ch] [ebp-18h] BYREF
  int cacheversion; // [esp+240h] [ebp-14h] BYREF
  int i; // [esp+244h] [ebp-10h]
  int version; // [esp+248h] [ebp-Ch] BYREF
  int count; // [esp+24Ch] [ebp-8h] BYREF
  int bufsize; // [esp+250h] [ebp-4h] BYREF

  v3 = fh;
  *deleteFile = false;
  v13 = *fh;
  cacheversion = 0;
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &cacheversion, a3: 4, a4: v13);
  if ( cacheversion == 2 )
  {
    v14 = *fh;
    version = 0;
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &version, a3: 4, a4: v14);
    if ( version == this->m_nVersion )
    {
      v15 = *fh;
      cache_meta_checksum = 0;
      g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &cache_meta_checksum, a3: 4, a4: v15);
      if ( this->m_pfnMetaChecksum == nullptr || cache_meta_checksum == this->m_uCurrentMetaChecksum )
      {
        v16 = *fh;
        count = 0;
        g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &count, a3: 4, a4: v16);
        CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
        i = 0;
        if ( count > 0 )
        {
          while ( 1 )
          {
            v17 = *v3;
            bufsize = 0;
            g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &bufsize, a3: 4, a4: v17);
            if ( bufsize > 1000000 )
              break;
            memset(&buf.m_Get, 0, 9);
            buf.m_nOffset = 0;
            buf.m_nMaxPut = -1;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
            CUtlBuffer::EnsureCapacity(this: &buf, num: bufsize);
            v6 = g_pFullFileSystem->Read(
                   this: &g_pFullFileSystem->IBaseFileSystem,
                   a2: buf.m_Memory.m_pMemory,
                   a3: bufsize,
                   a4: *v3);
            CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
            CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v6);
            CUtlBuffer::GetString(this: &buf, pString: elementFileName, nMaxChars: 512);
            p_m_Data = &this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(
                                                                                  this,
                                                                                  filename: (CAudioSourceCachedInfo *)elementFileName)].m_Data;
            Int = CUtlBuffer::GetInt(this: &buf);
            p_m_Data->fileinfo = Int;
            if ( Int == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
              p_m_Data->fileinfo = 0;
            v9 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
            v9->Restore(this: v9, a2: &buf);
            v3 = fh;
            if ( ++i >= count )
              goto LABEL_14;
          }
          v10 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
          _Msg(a1: "Discarding repository '%s' due to corruption\n", v10);
          *deleteFile = true;
        }
LABEL_14:
        if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      }
      else
      {
        v5 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
        _Msg(a1: "Discarding repository '%s' due to meta checksum change\n", v5);
        *deleteFile = true;
      }
    }
    else
    {
      v11 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      _Msg(a1: "Discarding repository '%s' due to version change\n", v11);
      *deleteFile = true;
    }
  }
  else
  {
    v12 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    DevMsg(a1: "Discarding repository '%s' due to cache system version change\n", v12);
    *deleteFile = true;
  }
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: *v3);
}

//------------------------------------------------------------------------------
// Address: 0x100435E0
// Name: public: virtual void CAudioSourceCache::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::Shutdown(CAudioSourceCache *this)
{
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // ecx
  CUtlCachedFileData<CAudioSourceCachedInfo> *v3; // ecx

  m_pMasterSoundCache = this->m_pMasterSoundCache;
  if ( m_pMasterSoundCache != nullptr )
  {
    CUtlCachedFileData<CAudioSourceCachedInfo>::Shutdown(this: m_pMasterSoundCache);
    v3 = this->m_pMasterSoundCache;
    if ( v3 != nullptr )
      ((void (__thiscall *)(CUtlCachedFileData<CAudioSourceCachedInfo> *, int))v3->dtr_CUtlCachedFileData<CAudioSourceCachedInfo>)(
        a1: v3,
        a2: 1);
  }
  if ( this->m_pMasterSoundCache != nullptr )
  {
    this->m_pMasterSoundCache = nullptr;
    ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
  }
  wavedatacache->Shutdown(this: wavedatacache);
}

//------------------------------------------------------------------------------
// Address: 0x10043620
// Name: public: class CAudioSourceCachedInfo __near * CUtlCachedFileData<class CAudioSourceCachedInfo>::Get(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceCachedInfo *__thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::Get(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        CAudioSourceCachedInfo *filename)
{
  unsigned __int16 Index; // ax
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *m_pMemory; // ecx
  int v5; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // esi
  IBaseFileSystem_vtbl *v7; // edx
  IBaseFileSystem *v8; // ecx
  int v9; // eax
  CAudioSourceCachedInfo *v10; // ebx
  char v11; // al
  int cachefileinfo; // [esp+Ch] [ebp-4h]

  Index = CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(this, filename);
  m_pMemory = this->m_Elements.m_Elements.m_pMemory;
  v5 = Index;
  p_m_Data = &m_pMemory[v5].m_Data;
  if ( m_pMemory[v5].m_Data.fileinfo == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
    m_pMemory[v5].m_Data.fileinfo = 0;
  cachefileinfo = m_pMemory[v5].m_Data.fileinfo;
  if ( m_pMemory[v5].m_Data.diskfileinfo == -2 )
  {
    if ( (*((_BYTE *)this + 84) & 1) != 0 )
    {
      m_pMemory[v5].m_Data.diskfileinfo = m_pMemory[v5].m_Data.fileinfo;
    }
    else
    {
      v7 = g_pFullFileSystem->IBaseFileSystem::__vftable;
      v8 = &g_pFullFileSystem->IBaseFileSystem;
      if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
      {
        v9 = v7->Size(this: v8, a2: (const char *)filename, a3: "GAME");
        p_m_Data->diskfileinfo = v9;
        if ( v9 == -1 )
          p_m_Data->diskfileinfo = 0;
      }
      else
      {
        p_m_Data->diskfileinfo = v7->GetFileTime(this: v8, a2: (const char *)filename, a3: "GAME");
      }
    }
  }
  v10 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
  if ( cachefileinfo != p_m_Data->diskfileinfo )
  {
    v11 = *((_BYTE *)this + 84);
    if ( (v11 & 2) == 0 )
    {
      *((_BYTE *)this + 84) = v11 | 8;
      v10->Rebuild(this: v10, a2: (const char *)filename);
    }
    p_m_Data->fileinfo = p_m_Data->diskfileinfo;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x100436E0
// Name: public: class CAudioSourceCachedInfo __near * CUtlCachedFileData<class CAudioSourceCachedInfo>::RebuildItem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceCachedInfo *__thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::RebuildItem(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        CAudioSourceCachedInfo *filename)
{
  unsigned __int16 Index; // ax
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // edi
  IBaseFileSystem_vtbl *v6; // eax
  int v7; // eax
  CAudioSourceCachedInfo *v8; // ecx
  char v9; // al
  CAudioSourceCachedInfo *data; // [esp+14h] [ebp+8h]

  Index = CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(this, filename);
  p_m_Data = &this->m_Elements.m_Elements.m_pMemory[Index].m_Data;
  this->m_Elements.m_Elements.m_pMemory[Index].m_Data.diskfileinfo = -2;
  if ( (*((_BYTE *)this + 84) & 1) != 0 )
  {
    p_m_Data->diskfileinfo = p_m_Data->fileinfo;
  }
  else
  {
    v6 = g_pFullFileSystem->IBaseFileSystem::__vftable;
    if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
    {
      v7 = ((int (__stdcall *)(CAudioSourceCachedInfo *, const char *))v6->Size)(a1: filename, a2: "GAME");
      p_m_Data->diskfileinfo = v7;
      if ( v7 == -1 )
        p_m_Data->diskfileinfo = 0;
    }
    else
    {
      p_m_Data->diskfileinfo = ((int (__stdcall *)(CAudioSourceCachedInfo *, const char *))v6->GetFileTime)(
                                 a1: filename,
                                 a2: "GAME");
    }
  }
  v8 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
  v9 = *((_BYTE *)this + 84);
  data = v8;
  if ( (v9 & 2) == 0 )
  {
    *((_BYTE *)this + 84) = v9 | 8;
    v8->Rebuild(this: v8, a2: (const char *)filename);
    v8 = data;
  }
  p_m_Data->fileinfo = p_m_Data->diskfileinfo;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10043780
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::RecheckItem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::RecheckItem(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        CAudioSourceCachedInfo *filename)
{
  unsigned __int16 Index; // ax
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *m_pMemory; // ecx
  int v6; // eax
  int fileinfo; // edx
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // esi
  IBaseFileSystem_vtbl *v9; // eax
  IBaseFileSystem *v10; // ecx
  int v11; // eax
  CAudioSourceCachedInfo *v12; // ecx
  char v13; // al
  int cachefileinfo; // [esp+14h] [ebp+8h]

  Index = CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(this, filename);
  m_pMemory = this->m_Elements.m_Elements.m_pMemory;
  v6 = Index;
  fileinfo = m_pMemory[v6].m_Data.fileinfo;
  p_m_Data = &m_pMemory[v6].m_Data;
  m_pMemory[v6].m_Data.diskfileinfo = -2;
  v9 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v10 = &g_pFullFileSystem->IBaseFileSystem;
  cachefileinfo = fileinfo;
  if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
  {
    v11 = v9->Size(this: v10, a2: (const char *)filename, a3: "GAME");
    p_m_Data->diskfileinfo = v11;
    if ( v11 == -1 )
      p_m_Data->diskfileinfo = 0;
  }
  else
  {
    p_m_Data->diskfileinfo = v9->GetFileTime(this: v10, a2: (const char *)filename, a3: "GAME");
  }
  v12 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
  if ( cachefileinfo == p_m_Data->diskfileinfo )
  {
    p_m_Data->fileinfo = p_m_Data->diskfileinfo;
  }
  else
  {
    v13 = *((_BYTE *)this + 84);
    if ( (v13 & 2) == 0 )
    {
      *((_BYTE *)this + 84) = v13 | 8;
      v12->Rebuild(this: v12, a2: (const char *)filename);
    }
    p_m_Data->fileinfo = p_m_Data->diskfileinfo;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043830
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::CheckDiskInfo(bool,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::CheckDiskInfo(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        bool forcerebuild,
        int cacheFileTime)
{
  CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl*)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short> > *p_m_Elements; // ecx
  int i; // esi
  CSortedCacheFile *v6; // esi
  int m_Size; // ebx
  int Inorder; // edx
  void *handle; // ecx
  int v10; // esi
  CSortedCacheFile *m_pMemory; // ecx
  _DWORD *p_handle; // esi
  int v13; // esi
  int *v14; // ebx
  int v15; // eax
  int *p_index; // ebx
  int v17; // eax
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *v18; // ecx
  int p_m_Data; // esi
  IBaseFileSystem *v20; // ecx
  int v21; // eax
  const char *v22; // [esp+0h] [ebp-238h]
  char fn[512]; // [esp+Ch] [ebp-22Ch] BYREF
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+20Ch] [ebp-2Ch] BYREF
  int listEnd; // [esp+228h] [ebp-10h]
  int v26; // [esp+22Ch] [ebp-Ch]
  int pathIndex; // [esp+230h] [ebp-8h]
  bool bSteam; // [esp+237h] [ebp-1h]
  int bCheck; // [esp+240h] [ebp+8h]
  int *bChecka; // [esp+240h] [ebp+8h]
  bool bCheck_3; // [esp+243h] [ebp+Bh]

  p_m_Elements = &this->m_Elements;
  if ( forcerebuild )
  {
    for ( i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: p_m_Elements);
          i != 0xFFFF;
          i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                  this: &this->m_Elements,
                                  i) )
    {
      g_pFullFileSystem->String(
        this: g_pFullFileSystem,
        a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)i].m_Data,
        a3: fn,
        a4: 512);
      CUtlCachedFileData<CAudioSourceCachedInfo>::Get(this, filename: (CAudioSourceCachedInfo *)fn);
    }
    return;
  }
  v6 = nullptr;
  m_Size = 0;
  memset(&list, 0, 25);
  Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: p_m_Elements);
  bCheck = Inorder;
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      handle = this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
      pathIndex = (int)&this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data;
      listEnd = (int)handle;
      list.m_bNeedsSort = true;
      v10 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)&list,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
        Inorder = bCheck;
      }
      m_pMemory = list.m_Memory.m_pMemory;
      list.m_Size = ++m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( m_Size - v10 - 1 > 0 )
      {
        _V_memmove(
          dest: &list.m_Memory.m_pMemory[v10 + 1],
          src: &list.m_Memory.m_pMemory[v10],
          count: 8 * (m_Size - v10 - 1));
        Inorder = bCheck;
        m_pMemory = list.m_Memory.m_pMemory;
      }
      p_handle = &m_pMemory[v10].handle;
      if ( p_handle != nullptr )
      {
        *p_handle = listEnd;
        p_handle[1] = Inorder;
      }
      if ( (*((_BYTE *)this + 84) & 1) != 0 && *(_DWORD *)(pathIndex + 8) == -2 )
        *(_DWORD *)(pathIndex + 8) = *(_DWORD *)(pathIndex + 4);
      bCheck = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                   this: &this->m_Elements,
                                   i: Inorder);
      if ( bCheck == 0xFFFF )
        break;
      Inorder = bCheck;
    }
    if ( m_Size != 0 && (*((_BYTE *)this + 84) & 1) == 0 )
    {
      v13 = 0;
      bSteam = g_pFullFileSystem->IsSteam(this: g_pFullFileSystem);
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          bChecka = &list.m_Memory.m_pMemory[v13].index;
          pathIndex = g_pFullFileSystem->GetPathIndex(
                        this: g_pFullFileSystem,
                        a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)bChecka].m_Data);
          v26 = v13;
          if ( v13 < m_Size )
          {
            v14 = bChecka;
            do
            {
              v15 = g_pFullFileSystem->GetPathIndex(
                      this: g_pFullFileSystem,
                      a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)v14].m_Data);
              if ( v15 != pathIndex )
                break;
              v14 += 2;
              ++v26;
            }
            while ( v26 < list.m_Size );
          }
          p_index = &list.m_Memory.m_pMemory[v13].index;
          g_pFullFileSystem->String(
            this: g_pFullFileSystem,
            a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)p_index].m_Data,
            a3: fn,
            a4: 512);
          V_StripFilename(path: fn);
          bCheck_3 = true;
          if ( !bSteam )
            bCheck_3 = g_pFullFileSystem->GetPathTime(this: g_pFullFileSystem, a2: fn, a3: "GAME") > cacheFileTime;
          v17 = v26;
          if ( v13 < v26 )
          {
            pathIndex = v26 - v13;
            do
            {
              v18 = this->m_Elements.m_Elements.m_pMemory;
              p_m_Data = (int)&v18[*(unsigned __int16 *)p_index].m_Data;
              if ( v18[*(unsigned __int16 *)p_index].m_Data.diskfileinfo == -2 )
              {
                if ( bCheck_3 )
                {
                  ((void (__thiscall *)(IFileSystem *, int, char *, int, const char *))g_pFullFileSystem->String)(
                    a1: g_pFullFileSystem,
                    a2: p_m_Data,
                    a3: fn,
                    a4: 512,
                    a5: v22);
                  v20 = &g_pFullFileSystem->IBaseFileSystem;
                  v22 = "GAME";
                  if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
                  {
                    v21 = ((int (__thiscall *)(IBaseFileSystem *, char *))v20->Size)(a1: v20, a2: fn);
                    *(_DWORD *)(p_m_Data + 8) = v21;
                    if ( v21 == -1 )
                      *(_DWORD *)(p_m_Data + 8) = 0;
                  }
                  else
                  {
                    *(_DWORD *)(p_m_Data + 8) = ((int (__thiscall *)(IBaseFileSystem *, char *))v20->GetFileTime)(
                                                  a1: v20,
                                                  a2: fn);
                  }
                }
                else
                {
                  *(_DWORD *)(p_m_Data + 8) = *(_DWORD *)(p_m_Data + 4);
                }
              }
              p_index += 2;
              --pathIndex;
            }
            while ( pathIndex != 0 );
            v17 = v26;
          }
          v13 = v17 + 1;
          if ( v17 + 1 >= list.m_Size )
            break;
          m_Size = list.m_Size;
        }
      }
      if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      return;
    }
    v6 = list.m_Memory.m_pMemory;
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && v6 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10043B90
// Name: public: virtual class CAudioSourceCachedInfo __near * CAudioSourceCache::GetInfoByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceCachedInfo *__thiscall CAudioSourceCache::GetInfoByName(CAudioSourceCache *this, const char *soundName)
{
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // ecx

  m_pMasterSoundCache = this->m_pMasterSoundCache;
  if ( m_pMasterSoundCache != nullptr )
    return CUtlCachedFileData<CAudioSourceCachedInfo>::Get(this: m_pMasterSoundCache, filename: soundName);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10043BB0
// Name: public: virtual class CAudioSourceCachedInfo __near * CAudioSourceCache::GetInfo(int,bool,class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceCachedInfo *__thiscall CAudioSourceCache::GetInfo(
        CAudioSourceCache *this,
        int audiosourcetype,
        bool soundisprecached,
        CSfxTable *sfx)
{
  const char *FileName; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pBuildingCache; // esi
  CAudioSourceCachedInfo *v8; // eax
  CAudioSourceCachedInfo *v9; // edi
  char nameBuf[260]; // [esp+8h] [ebp-304h] BYREF
  char fn[512]; // [esp+10Ch] [ebp-200h] BYREF

  FileName = CSfxTable::GetFileName(this: sfx, pOutBuf: nameBuf, bufLen: 0x104u);
  V_snprintf(pDest: fn, maxLen: 512, pFormat: "sound/%s", FileName);
  CAudioSourceCachedInfo::s_CurrentType = audiosourcetype;
  CAudioSourceCachedInfo::s_pSfx = sfx;
  CAudioSourceCachedInfo::s_bIsPrecacheSound = false;
  if ( this->m_pBuildingCache != nullptr )
    m_pBuildingCache = this->m_pBuildingCache;
  else
    m_pBuildingCache = this->m_pMasterSoundCache;
  if ( m_pBuildingCache == nullptr )
    return nullptr;
  v8 = CUtlCachedFileData<CAudioSourceCachedInfo>::Get(this: m_pBuildingCache, filename: fn);
  v9 = v8;
  if ( v8 != nullptr
    && (v8->infolong & 0x3000) == 0
    && g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: fn, a3: "BSP") )
  {
    _DevMsg(a1: 1, a2: "Forced rebuild of bsp cache sound '%s'\n", fn);
    return CUtlCachedFileData<CAudioSourceCachedInfo>::RebuildItem(this: m_pBuildingCache, filename: fn);
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10043C90
// Name: public: virtual void CAudioSourceCache::RebuildCacheEntry(int,bool,class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::RebuildCacheEntry(
        CAudioSourceCache *this,
        int audiosourcetype,
        bool soundisprecached,
        CSfxTable *sfx)
{
  const char *FileName; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pBuildingCache; // eax
  char fn[512]; // [esp+8h] [ebp-304h] BYREF
  char nameBuf[260]; // [esp+208h] [ebp-104h] BYREF

  FileName = CSfxTable::GetFileName(this: sfx, pOutBuf: nameBuf, bufLen: 0x104u);
  V_snprintf(pDest: fn, maxLen: 512, pFormat: "sound/%s", FileName);
  CAudioSourceCachedInfo::s_CurrentType = audiosourcetype;
  CAudioSourceCachedInfo::s_pSfx = sfx;
  CAudioSourceCachedInfo::s_bIsPrecacheSound = false;
  m_pBuildingCache = this->m_pBuildingCache;
  if ( m_pBuildingCache == nullptr )
    m_pBuildingCache = this->m_pMasterSoundCache;
  if ( m_pBuildingCache != nullptr )
    CUtlCachedFileData<CAudioSourceCachedInfo>::RebuildItem(this: m_pBuildingCache, filename: fn);
}

//------------------------------------------------------------------------------
// Address: 0x10043D10
// Name: public: void CAudioSourceCache::ValidateSoundCache(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::ValidateSoundCache(CAudioSourceCache *this, const char *pchWavFile)
{
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // eax
  CSfxTable *v5; // eax
  CSfxTable *v6; // esi
  CUtlCachedFileData<CAudioSourceCachedInfo> *v7; // ecx
  CUtlCachedFileData<CAudioSourceCachedInfo> *v8; // ecx
  const char *pchWavFilea; // [esp+Ch] [ebp+8h]

  m_pMasterSoundCache = this->m_pMasterSoundCache;
  if ( m_pMasterSoundCache != nullptr )
  {
    *((_BYTE *)m_pMasterSoundCache + 84) &= ~1u;
    pchWavFilea = pchWavFile + 6;
    v5 = S_PrecacheSound(name: pchWavFilea);
    v6 = v5;
    if ( v5 != nullptr && v5->pSource != nullptr )
    {
      CAudioSourceCachedInfo::s_CurrentType = v5->pSource->GetType(this: v5->pSource);
      CAudioSourceCachedInfo::s_pSfx = v6;
      CAudioSourceCachedInfo::s_bIsPrecacheSound = false;
      v7 = this->m_pMasterSoundCache;
      g_bSoundRebuilt = false;
      CUtlCachedFileData<CAudioSourceCachedInfo>::RecheckItem(this: v7, filename: pchWavFile);
      if ( g_bSoundRebuilt )
        _Msg(a1: " updated '%s'\n", pchWavFilea);
    }
    *((_BYTE *)this->m_pMasterSoundCache + 84) |= 1u;
    v8 = this->m_pMasterSoundCache;
    if ( (*((_BYTE *)v8 + 84) & 8) != 0 )
      CUtlCachedFileData<CAudioSourceCachedInfo>::Save(this: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043DB0
// Name: public: bool CAudioSourceCache::UpdateMasterPrecachedSoundsCache(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CAudioSourceCache::UpdateMasterPrecachedSoundsCache(CAudioSourceCache *this)
{
  void (*v2)(const char *, ...); // edi
  const char *v3; // eax
  int Inorder; // ebx
  CSfxTable *v5; // eax
  CSfxTable *v6; // edi
  double v7; // st7
  void *v8; // eax
  char filename[4]; // [esp+14h] [ebp-22Ch] BYREF
  char name[20]; // [esp+18h] [ebp-228h] BYREF
  char soundname[512]; // [esp+2Ch] [ebp-214h] BYREF
  int flStart; // [esp+22Ch] [ebp-14h]
  __int128 soundsOnDisk; // [esp+230h] [ebp-10h] OVERLAPPED

  if ( this->m_pMasterSoundCache != nullptr )
  {
    *(float *)&soundname[488] = _Plat_FloatTime();
    v2 = (void (*)(const char *, ...))_Msg;
    _Msg(a1: "Updating sound cache [%d entries]\n", this->m_pMasterSoundCache->m_Elements.m_NumElements);
    *(_DWORD *)&soundname[492] = CDmxSerializationDictionary::LessFunc;
    memset(&soundname[496], 0, 12);
    *(_DWORD *)&soundname[508] = -1;
    flStart = 0;
    *(_QWORD *)&soundsOnDisk = -1;
    DWORD2(soundsOnDisk) = 0;
    v3 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
    CAudioSourceCache::RecursiveBuildSoundList(
      this,
      root: (CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *)&soundname[492],
      pLanguage: v3,
      pCurrentDir: "sound",
      pathID: "GAME");
    _Msg(a1: "Found %d sound files on disk\n", flStart);
    *((_BYTE *)this->m_pMasterSoundCache + 84) &= ~1u;
    CUtlCachedFileData<CAudioSourceCachedInfo>::ForceRecheckDiskInfo(this: this->m_pMasterSoundCache);
    HIDWORD(soundsOnDisk) = 0;
    Inorder = CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::FirstInorder(this: (CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *)&soundname[492]);
    if ( Inorder != -1 )
    {
      do
      {
        filename[0] = 0;
        g_pFullFileSystem->String(
          this: g_pFullFileSystem,
          a2: (void *const *)(*(_DWORD *)&soundname[496] + 20 * Inorder + 16),
          a3: filename,
          a4: 512);
        g_bSoundRebuilt = false;
        v5 = S_PrecacheSound(name: &name[2]);
        v6 = v5;
        if ( v5 != nullptr && v5->pSource != nullptr )
        {
          CAudioSourceCachedInfo::s_CurrentType = v5->pSource->GetType(this: v5->pSource);
          CAudioSourceCachedInfo::s_pSfx = v6;
          CAudioSourceCachedInfo::s_bIsPrecacheSound = false;
          CUtlCachedFileData<CAudioSourceCachedInfo>::Get(this: this->m_pMasterSoundCache, filename);
        }
        if ( g_bSoundRebuilt )
        {
          ++HIDWORD(soundsOnDisk);
          _Msg(a1: " updated '%s'\n", &name[2]);
        }
        Inorder = CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::NextInorder(
                    this: (CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *)&soundname[492],
                    i: Inorder);
      }
      while ( Inorder != -1 );
      v2 = (void (*)(const char *, ...))_Msg;
    }
    *((_BYTE *)this->m_pMasterSoundCache + 84) |= 1u;
    CUtlCachedFileData<CAudioSourceCachedInfo>::Save(this: this->m_pMasterSoundCache);
    v7 = _Plat_FloatTime();
    v2(
      a1: "Updated %i out of %i cached files [%.3f msec]\n",
      HIDWORD(soundsOnDisk),
      flStart,
      (v7 - *(float *)&soundname[488]) * 1000.0);
    ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::RemoveAll(this: (CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *)&soundname[492]);
    v8 = *(void **)&soundname[496];
    LODWORD(soundsOnDisk) = -1;
    if ( *(int *)&soundname[504] >= 0 )
    {
      if ( *(_DWORD *)&soundname[496] != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&soundname[496]);
        v8 = nullptr;
        *(_DWORD *)&soundname[496] = 0;
      }
      *(_DWORD *)&soundname[500] = 0;
    }
    DWORD1(soundsOnDisk) = -1;
    if ( *(int *)&soundname[504] >= 0 && v8 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10043FC0
// Name: private: void CAudioSourceCache::PrefetchCommandSounds(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CAudioSourceCache::PrefetchCommandSounds(CAudioSourceCache *this)
{
  int v1; // edi
  int v2; // ebx
  int v3; // esi
  CUtlString *v4; // esi
  int v5; // edi
  __int16 v6; // bx
  int v7; // esi
  int v8; // edi
  CUtlString *v9; // ebx
  const char *v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  unsigned int v15; // kr00_4
  const char *v16; // eax
  float value; // [esp+0h] [ebp-28Ch]
  double v18; // [esp+Ch] [ebp-280h]
  characterset_t pSetBuffer; // [esp+20h] [ebp-26Ch] BYREF
  char pTokenBuf[68]; // [esp+120h] [ebp-16Ch] BYREF
  char szFile[260]; // [esp+164h] [ebp-128h] BYREF
  _BYTE buf[36]; // [esp+268h] [ebp-24h] OVERLAPPED BYREF

  v1 = 0;
  *(_DWORD *)&buf[28] = this;
  if ( this->m_pMasterSoundCache == nullptr )
    return;
  v2 = 0;
  memset(&szFile[248], 0, 12);
  *(_DWORD *)buf = 0;
  *(_DWORD *)&buf[4] = 0;
  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&szFile[192], growSize: 0, initSize: 0, nFlags: 1);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: "scripts/sound_prefetch.txt",
         a3: "GAME",
         a4: (CUtlBuffer *)&szFile[192],
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    CharacterSetBuild(&pSetBuffer, pszSetString: defaultValue);
    if ( CUtlBuffer::ParseToken(
           this: (CUtlBuffer *)&szFile[192],
           pBreaks: &pSetBuffer,
           pTokenBuf,
           nMaxLen: 260,
           bParseComments: true) > 0 )
    {
      do
      {
        V_FixSlashes(pname: pTokenBuf, separator: 92);
        _V_strlower(start: pTokenBuf);
        *(_DWORD *)&buf[32] = CUtlString::CUtlString(this: (CUtlString *)&buf[12], pString: pTokenBuf);
        v3 = v1;
        if ( v1 + 1 > *(int *)&szFile[252] )
        {
          CUtlMemory<CPortalRect,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&szFile[248],
            num: v1 - *(_DWORD *)&szFile[252] + 1);
          v1 = *(_DWORD *)buf;
          v2 = *(_DWORD *)&szFile[248];
        }
        *(_DWORD *)buf = ++v1;
        *(_DWORD *)&buf[4] = v2;
        if ( v1 - v3 - 1 > 0 )
          _V_memmove(dest: (void *)(v2 + 16 * v3 + 16), src: (const void *)(v2 + 16 * v3), count: 16 * (v1 - v3 - 1));
        v4 = (CUtlString *)(v2 + 16 * v3);
        if ( v4 != nullptr )
          CUtlString::CUtlString(this: v4, string: *(const CUtlString **)&buf[32]);
        *(_DWORD *)&buf[24] = 0;
        if ( *(int *)&buf[20] >= 0 )
        {
          if ( *(_DWORD *)&buf[12] != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&buf[12]);
            *(_DWORD *)&buf[12] = 0;
          }
          *(_DWORD *)&buf[16] = 0;
        }
        _Msg(a1: "Prefetching data for subdir:  %s\n", pTokenBuf);
      }
      while ( CUtlBuffer::ParseToken(
                this: (CUtlBuffer *)&szFile[192],
                pBreaks: &pSetBuffer,
                pTokenBuf,
                nMaxLen: 260,
                bParseComments: true) > 0 );
      if ( v1 != 0 )
      {
        _COM_TimestampedLog(a1: "PrefetchSounds Start");
        *(float *)&szFile[244] = _Plat_FloatTime();
        v5 = *(_DWORD *)(*(_DWORD *)&buf[28] + 68);
        *(_DWORD *)&buf[20] = 0;
        *(_DWORD *)&buf[24] = 0;
        *(_DWORD *)&buf[32] = 0;
        *(_DWORD *)&buf[8] = 0;
        if ( *(_WORD *)(v5 + 22) != 0 )
        {
          do
          {
            v6 = *(_WORD *)&buf[8];
            v7 = *(unsigned __int16 *)&buf[8];
            pTokenBuf[0] = 0;
            if ( *(unsigned __int16 *)&buf[8] < *(int *)(v5 + 12)
              && *(_WORD *)&buf[8] <= *(_WORD *)(v5 + 26)
              && CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::LeftChild(
                   this: (CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl*)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short> > *)(v5 + 4),
                   i: *(unsigned __int16 *)&buf[8]) != v6 )
            {
              g_pFullFileSystem->String(
                this: g_pFullFileSystem,
                a2: (void *const *)(*(_DWORD *)(v5 + 8) + 24 * v7 + 8),
                a3: pTokenBuf,
                a4: 260);
            }
            V_FixSlashes(pname: pTokenBuf, separator: 92);
            _V_strlower(start: pTokenBuf);
            v8 = 0;
            if ( *(int *)buf > 0 )
            {
              v9 = *(CUtlString **)&szFile[248];
              while ( 1 )
              {
                v10 = CUtlString::operator char const *(this: v9);
                if ( V_stristr(pStr: pTokenBuf, pSearch: v10) != nullptr )
                  break;
                ++v8;
                ++v9;
                if ( v8 >= *(int *)buf )
                  goto LABEL_31;
              }
              v11 = *(_DWORD *)(*(_DWORD *)&buf[28] + 68);
              v12 = *(_DWORD *)(v11 + 8);
              v13 = *(_DWORD *)(v11 + 32);
              ++*(_DWORD *)&buf[32];
              *(_QWORD *)&buf[20] += *(int *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(v12 + 24 * v7 + 20)) + 24);
              S_PrefetchSound(name: pTokenBuf, bPlayOnce: false);
            }
LABEL_31:
            v5 = *(_DWORD *)(*(_DWORD *)&buf[28] + 68);
            v14 = *(unsigned __int16 *)(v5 + 22);
            ++*(_DWORD *)&buf[8];
          }
          while ( *(int *)&buf[8] < v14 );
        }
        *(float *)&buf[28] = _Plat_FloatTime();
        _COM_TimestampedLog(a1: "PrefetchSounds Finish");
        *(_DWORD *)&szFile[240] = *(_DWORD *)&buf[20];
        v18 = (*(float *)&buf[28] - *(float *)&szFile[244]) * 1000.0;
        v15 = *(_DWORD *)&buf[24];
        *(_DWORD *)&szFile[244] = *(_DWORD *)&buf[24] & 0x7FFFFFFF;
        *(_QWORD *)&buf[20] &= 0x8000000000000000uLL;
        value = (float)__PAIR64__(v15, *(unsigned int *)&szFile[240]);
        v16 = V_pretifymem(value, digitsafterdecimal: 2, usebinaryonek: false);
        _Msg(a1: "Prefetched %u sounds, %s [%.3f msec]\n", *(_DWORD *)&buf[32], v16, v18);
        if ( *(int *)&szFile[200] >= 0 )
        {
          if ( *(_DWORD *)&szFile[192] != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&szFile[192]);
            *(_DWORD *)&szFile[192] = 0;
          }
          *(_DWORD *)&szFile[196] = 0;
        }
        goto LABEL_36;
      }
    }
  }
  if ( *(int *)&szFile[200] < v1 )
  {
LABEL_36:
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&szFile[248]);
    return;
  }
  if ( *(_DWORD *)&szFile[192] != v1 )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)&szFile[192]);
    *(_DWORD *)&szFile[192] = v1;
  }
  *(_DWORD *)&szFile[196] = v1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&szFile[248]);
}

//------------------------------------------------------------------------------
// Address: 0x10044360
// Name: snd_updateaudiocache
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_updateaudiocache()
{
  CAudioSourceCache::UpdateMasterPrecachedSoundsCache(this: &g_ASCache);
}

//------------------------------------------------------------------------------
// Address: 0x10044370
// Name: void S_ValidateSoundCache(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_ValidateSoundCache(const char *pchWavFile)
{
  CAudioSourceCache::ValidateSoundCache(this: &g_ASCache, pchWavFile);
}

//------------------------------------------------------------------------------
// Address: 0x10044390
// Name: public: bool CUtlCachedFileData<class CAudioSourceCachedInfo>::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::Init(CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  char v2; // al
  int (*m_pfnMetaChecksum)(void); // eax
  unsigned int v5; // eax
  const char *v6; // eax
  void *v7; // edi
  char v8; // al
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  int fileTime; // [esp+4h] [ebp-Ch]
  void *fh; // [esp+8h] [ebp-8h] BYREF
  bool deletefile; // [esp+Fh] [ebp-1h] BYREF

  v2 = *((_BYTE *)this + 84);
  if ( (v2 & 0x10) != 0 )
    return 1;
  *((_BYTE *)this + 84) = v2 | 0x10;
  if ( CUtlString::Length(this: &this->m_sRepositoryFileName) == 0 )
  {
    _Error(a1: "CUtlCachedFileData:  Can't Init, no repository file specified.");
    return 0;
  }
  m_pfnMetaChecksum = (int (*)(void))this->m_pfnMetaChecksum;
  if ( m_pfnMetaChecksum != nullptr )
    v5 = m_pfnMetaChecksum();
  else
    v5 = 0;
  this->m_uCurrentMetaChecksum = v5;
  v6 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  v7 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6, a3: "rb", a4: "MOD");
  fh = v7;
  if ( v7 != nullptr )
  {
    v9 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    fileTime = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: v9, a3: "MOD");
    v10 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v7);
    deletefile = false;
    if ( v10 <= 0x100000 )
      CUtlCachedFileData<CAudioSourceCachedInfo>::InitSmallBuffer(this, &fh, fileSize: v10, deleteFile: &deletefile);
    else
      CUtlCachedFileData<CAudioSourceCachedInfo>::InitLargeBuffer(this, &fh, deleteFile: &deletefile);
    if ( deletefile && (*((_BYTE *)this + 84) & 2) == 0 )
    {
      v11 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: v11, a3: "MOD");
      *((_BYTE *)this + 84) |= 8u;
    }
    CUtlCachedFileData<CAudioSourceCachedInfo>::CheckDiskInfo(this, forcerebuild: false, cacheFileTime: fileTime);
  }
  else
  {
    v8 = *((_BYTE *)this + 84);
    if ( (v8 & 2) == 0 )
    {
      *((_BYTE *)this + 84) = v8 | 8;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100444C0
// Name: private: bool CAudioSourceCache::LoadMasterCache(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioSourceCache::LoadMasterCache(CAudioSourceCache *this, const char *pchLanguage, bool bAllowEmpty)
{
  CFmtStrN<256> *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  CFmtStrN<256> *v7; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *v8; // ebx
  const char *v10; // eax
  const char *v11; // [esp-4h] [ebp-224h]
  CFmtStrN<256> v12; // [esp+Ch] [ebp-214h] BYREF
  char fullpath[260]; // [esp+118h] [ebp-108h] BYREF
  CUtlCachedFileData<CAudioSourceCachedInfo> *v14; // [esp+21Ch] [ebp-4h]
  const char *pchLanguagea; // [esp+228h] [ebp+8h]

  v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v12, pszFormat: "%s/_master%s.cache", "maps/soundcache", pchLanguage);
  CUtlString::operator=(this: &this->m_szMasterCache, src: v4->m_szBuf);
  v11 = CUtlString::operator char const *(this: &this->m_szMasterCache);
  v5 = CUtlString::operator char const *(this: &this->m_szMODPath);
  V_snprintf(pDest: fullpath, maxLen: 260, pFormat: "%s%s", v5, v11);
  V_FixSlashes(pname: fullpath, separator: 47);
  _V_strlower(start: fullpath);
  _DevMsg(a1: 1, a2: "Trying cache :  '%s'\n", fullpath);
  pchLanguagea = CUtlString::operator char const *(this: &this->m_szMasterCache);
  v14 = (CUtlCachedFileData<CAudioSourceCachedInfo> *)MemAlloc_Alloc(nSize: 0x58u);
  if ( v14 != nullptr )
  {
    v6 = CUtlString::operator char const *(this: &this->m_szMODPath);
    v7 = CFmtStrN<256>::CFmtStrN<256>(this: &v12, pszFormat: "%s%s", v6, pchLanguagea);
    v8 = CUtlCachedFileData<CAudioSourceCachedInfo>::CUtlCachedFileData<CAudioSourceCachedInfo>(
           this: v14,
           repositoryFileName: v7->m_szBuf,
           version: 3,
           checksumfunc: nullptr,
           fileCheckType: UTL_CACHED_FILE_USE_FILESIZE,
           nevercheckdisk: true,
           readonly: false,
           savemanifest: false);
  }
  else
  {
    v8 = nullptr;
  }
  if ( CUtlCachedFileData<CAudioSourceCachedInfo>::Init(this: v8) && (bAllowEmpty || v8->m_Elements.m_NumElements != 0) )
  {
    _DevMsg(a1: 1, a2: "Successfully loaded audio cache file\n");
    if ( this->m_pMasterSoundCache != v8 )
    {
      this->m_pMasterSoundCache = v8;
      ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
    return 1;
  }
  else
  {
    v10 = CUtlString::operator char const *(this: &this->m_szMasterCache);
    _Warning(a1: "Failed to init '%s'\n", v10);
    CUtlString::operator=(this: &this->m_szMasterCache, src: (char *)defaultValue);
    if ( v8 != nullptr )
      ((void (__thiscall *)(CUtlCachedFileData<CAudioSourceCachedInfo> *, int))v8->dtr_CUtlCachedFileData<CAudioSourceCachedInfo>)(
        a1: v8,
        a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044630
// Name: private: class CUtlCachedFileData<class CAudioSourceCachedInfo> __near * CAudioSourceCache::BuildCacheFromList(char const __near *,class CUtlRBTree<void __near *,int,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,int>,int>> __near &,bool,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CUtlCachedFileData<CAudioSourceCachedInfo> *__thiscall CAudioSourceCache::BuildCacheFromList(
        CAudioSourceCache *this,
        const char *cachename,
        CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *soundlist,
        bool showprogress,
        float flProgressStart,
        float flProgressEnd)
{
  CAudioSourceCache *v6; // esi
  int v7; // ebx
  CUtlCachedFileData<CAudioSourceCachedInfo> *v8; // edi
  int Inorder; // eax
  void **p_m_Data; // eax
  CSfxTable *v11; // eax
  int v12; // esi
  int v13; // eax
  int m_NumElements; // esi
  double v15; // st7
  float v17; // [esp+0h] [ebp-320h]
  char in[6]; // [esp+14h] [ebp-30Ch] BYREF
  char name[26]; // [esp+1Ah] [ebp-306h] BYREF
  char soundname[512]; // [esp+34h] [ebp-2ECh] BYREF
  _BYTE base_224[12]; // [esp+314h] [ebp-Ch] OVERLAPPED
  int base_244; // [esp+328h] [ebp+8h]

  v6 = this;
  *(_DWORD *)&base_224[8] = this;
  *(float *)base_224 = _Plat_FloatTime();
  v7 = 0;
  v8 = CAudioSourceCache::AllocAudioCache(this: v6, cachename, bNeverCheckDisk: false);
  *(_DWORD *)&base_224[4] = v8;
  if ( CUtlCachedFileData<CAudioSourceCachedInfo>::Init(this: v8) )
  {
    if ( v6->m_pBuildingCache != v8 )
    {
      v6->m_pBuildingCache = v8;
      ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
    Inorder = CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::FirstInorder(this: soundlist);
    base_244 = Inorder;
    if ( Inorder != -1 )
    {
      while ( 1 )
      {
        p_m_Data = &soundlist->m_Elements.m_pMemory[Inorder].m_Data;
        in[0] = 0;
        if ( g_pFullFileSystem->String(this: g_pFullFileSystem, a2: p_m_Data, a3: in, a4: 512) )
        {
          v11 = S_PrecacheSound(name);
          if ( v11 != nullptr && v11->pSource != nullptr )
          {
            v12 = **(_DWORD **)&base_224[8];
            v13 = ((int (__thiscall *)(CAudioSource *, _DWORD, CSfxTable *))v11->pSource->GetType)(
                    a1: v11->pSource,
                    a2: 0,
                    a3: v11);
            (*(void (__thiscall **)(_DWORD, int))(v12 + 16))(a1: *(_DWORD *)&base_224[8], a2: v13);
          }
        }
        if ( ++v7 % 100 == 0 )
          _Msg(
            a1: "  progress %i/%i (%i %%)\n",
            v7,
            soundlist->m_NumElements,
            (int)((double)v7 * 100.0 / (double)(unsigned int)soundlist->m_NumElements));
        if ( showprogress )
        {
          m_NumElements = soundlist->m_NumElements;
          V_FileBase(in, out: &soundname[480], maxlen: 256);
          _V_strlower(start: &soundname[480]);
          v17 = flProgressStart
              + (flProgressEnd - flProgressStart) * ((double)(v7 - 1) / (double)(unsigned int)m_NumElements);
          ((void (__stdcall *)(_DWORD, char *))g_pSoundServices->CacheBuildingUpdateProgress)(
            a1: LODWORD(v17),
            a2: &soundname[480]);
        }
        base_244 = CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::NextInorder(
                     this: soundlist,
                     i: base_244);
        if ( base_244 == -1 )
          break;
        Inorder = base_244;
      }
      v6 = *(CAudioSourceCache **)&base_224[8];
    }
    _Msg(a1: "Touched %i cached files\n", soundlist->m_NumElements);
    if ( v6->m_pBuildingCache != nullptr )
    {
      v6->m_pBuildingCache = nullptr;
      ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
    CUtlCachedFileData<CAudioSourceCachedInfo>::Save(this: *(CUtlCachedFileData<CAudioSourceCachedInfo> **)&base_224[4]);
  }
  else
  {
    if ( v8 != nullptr )
      ((void (__thiscall *)(CUtlCachedFileData<CAudioSourceCachedInfo> *, int))v8->dtr_CUtlCachedFileData<CAudioSourceCachedInfo>)(
        a1: v8,
        a2: 1);
    *(_DWORD *)&base_224[4] = 0;
  }
  v15 = _Plat_FloatTime();
  _Msg(a1: "Elapsed time:  %.2f seconds\n", v15 - *(float *)base_224);
  return *(CUtlCachedFileData<CAudioSourceCachedInfo> **)&base_224[4];
}

//------------------------------------------------------------------------------
// Address: 0x10044850
// Name: public: bool CAudioSourceCache::BuildMasterPrecachedSoundsCache(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CAudioSourceCache::BuildMasterPrecachedSoundsCache(CAudioSourceCache *this)
{
  const char *v2; // eax
  const char *v3; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *v4; // edi
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // ecx
  char pDest[8]; // [esp+14h] [ebp-224h] BYREF
  char fn[512]; // [esp+1Ch] [ebp-21Ch] BYREF
  _BYTE other[28]; // [esp+21Ch] [ebp-1Ch] OVERLAPPED

  v2 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
  V_snprintf(pDest, maxLen: 512, pFormat: "%s/%s%s.cache", "maps/soundcache", "_master", v2);
  _DevMsg(a1: 1, a2: "Fast Build Temp Cache:  '%s'\n", pDest);
  CAudioSourceCache::RemoveCache(this, cachename: pDest);
  g_pSoundServices->CacheBuildingStart(this: g_pSoundServices);
  *(_DWORD *)&fn[504] = CDmxSerializationDictionary::LessFunc;
  *(_DWORD *)&fn[508] = 0;
  *(_DWORD *)other = 0;
  *(_DWORD *)&other[4] = 0;
  *(_DWORD *)&other[8] = -1;
  *(_DWORD *)&other[12] = 0;
  *(_DWORD *)&other[16] = -1;
  *(_DWORD *)&other[20] = -1;
  *(_DWORD *)&other[24] = 0;
  v3 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
  CAudioSourceCache::RecursiveBuildSoundList(
    this,
    root: (CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *)&fn[504],
    pLanguage: v3,
    pCurrentDir: "sound",
    pathID: "GAME");
  v4 = CAudioSourceCache::BuildCacheFromList(
         this,
         cachename: pDest,
         soundlist: (CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *)&fn[504],
         showprogress: true,
         flProgressStart: 0.0,
         flProgressEnd: 1.0);
  if ( v4 != nullptr )
  {
    m_pMasterSoundCache = this->m_pMasterSoundCache;
    if ( m_pMasterSoundCache != nullptr )
      ((void (__thiscall *)(CUtlCachedFileData<CAudioSourceCachedInfo> *, int))m_pMasterSoundCache->dtr_CUtlCachedFileData<CAudioSourceCachedInfo>)(
        a1: m_pMasterSoundCache,
        a2: 1);
    if ( this->m_pMasterSoundCache != v4 )
    {
      this->m_pMasterSoundCache = v4;
      ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
  }
  g_pSoundServices->CacheBuildingFinish(this: g_pSoundServices);
  CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::~CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>(this: (CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *)&fn[504]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10044960
// Name: snd_rebuildaudiocache
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_rebuildaudiocache()
{
  CAudioSourceCache::BuildMasterPrecachedSoundsCache(this: &g_ASCache);
}

//------------------------------------------------------------------------------
// Address: 0x10044970
// Name: public: virtual bool CAudioSourceCache::Init(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CAudioSourceCache::Init@<al>(
        CAudioSourceCache *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        unsigned int memSize)
{
  const char *v6; // eax
  const char *v7; // eax
  int v8; // eax
  CFmtStrN<256> *v9; // eax
  const char *v10; // eax
  CFmtStrN<256> *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // [esp-8h] [ebp-21Ch]
  int v18; // [esp-8h] [ebp-21Ch]
  int v19; // [esp-4h] [ebp-218h]
  int v20; // [esp-4h] [ebp-218h]
  CFmtStrN<256> v21; // [esp+4h] [ebp-210h] BYREF
  char sz[260]; // [esp+110h] [ebp-104h] BYREF

  if ( wavedatacache->Init(this: wavedatacache, a2: memSize) != 0 )
  {
    CAudioSourceCache::GetAudioCacheLanguageSuffix(this, sLanguage: &this->m_szCurrentLanguage);
    if ( CUtlString::Length(this: &this->m_szCurrentLanguage) > 0 )
    {
      v6 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
      _DevMsg(a1: 1, a2: "Audio Caches using '%s' as suffix\n", v6);
    }
    v7 = g_pSoundServices->GetGameDir(this: g_pSoundServices);
    V_strncpy(pDest: sz, pSrc: v7, maxLen: 260);
    V_StripTrailingSlash(ppath: sz);
    v8 = _CommandLine(a1: a3, a2);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-tempcontent") != 0 )
      V_strncat(pDest: sz, pSrc: "_tempcontent", destBufferSize: 0x104u, max_chars_to_copy: -1);
    V_FixSlashes(pname: sz, separator: 92);
    _V_strlower(start: sz);
    CUtlString::operator=(this: &this->m_szMODPath, src: sz);
    v9 = CFmtStrN<256>::CFmtStrN<256>(this: &v21, pszFormat: "%c", 92);
    CUtlString::operator+=(this: &this->m_szMODPath, rhs: v9->m_szBuf);
    v10 = CUtlString::operator char const *(this: &this->m_szMODPath);
    v11 = CFmtStrN<256>::CFmtStrN<256>(this: &v21, pszFormat: "%s%s", v10, "maps/soundcache");
    g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: v11->m_szBuf, a3: "GAME");
    if ( this->m_pMasterSoundCache != nullptr )
    {
      this->m_pMasterSoundCache = nullptr;
      ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
    v12 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
    if ( CAudioSourceCache::LoadMasterCache(this, pchLanguage: v12, bAllowEmpty: false)
      || (v13 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage),
          _V_stricmp(s1: v13, s2: defaultValue) != 0)
      && CAudioSourceCache::LoadMasterCache(this, pchLanguage: defaultValue, bAllowEmpty: true) )
    {
      v15 = _CommandLine(a1: v17, a2: v19);
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v15 + 40))(a1: v15, a2: "-tools") != 0 )
      {
        v16 = _CommandLine(a1: v18, a2: v20);
        if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 40))(a1: v16, a2: "-norebuildaudiocache") == 0 )
          CAudioSourceCache::UpdateMasterPrecachedSoundsCache(this);
      }
    }
    else
    {
      v14 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
      _Warning(a1: "  .cache load failed, forcing rebuild [lang:%s]!\n", v14);
      CAudioSourceCache::BuildMasterPrecachedSoundsCache(this);
    }
    if ( snd_prefetch_common.m_pParent != nullptr && snd_prefetch_common.m_pParent->m_Value.m_nValue != 0 )
      CAudioSourceCache::PrefetchCommandSounds(this);
    return 1;
  }
  else
  {
    _Error(a1: "Unable to init wavedatacache system\n");
    return 0;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1003E270
// Name: public: virtual char const __near * CAudioSourceWave::GetFileName(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAudioSourceWave::GetFileName(CAudioSourceWave *this, char *pOutBuf, unsigned int bufLen)
{
  CSfxTable *m_pSfx; // ecx

  m_pSfx = this->m_pSfx;
  if ( m_pSfx != nullptr )
    return CSfxTable::GetFileName(this: m_pSfx, pOutBuf, bufLen);
  else
    return "NULL m_pSfx";
}

//------------------------------------------------------------------------------
// Address: 0x1003E290
// Name: protected: void CAudioSourceWave::Init(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::Init(CAudioSourceWave *this, char *pHeaderBuffer, int headerSize)
{
  int m_bits; // eax
  int v5; // ecx
  int v6; // eax
  char *v7; // eax

  this->m_format = *(unsigned __int16 *)pHeaderBuffer;
  this->m_bits = *((unsigned __int16 *)pHeaderBuffer + 7);
  m_bits = this->m_bits;
  this->m_rate = *((_DWORD *)pHeaderBuffer + 1);
  v5 = *((unsigned __int16 *)pHeaderBuffer + 1);
  v6 = v5 * m_bits / 8;
  this->m_channels = v5;
  this->m_sampleSize = v6;
  if ( v6 <= 0 )
    this->m_sampleSize = 1;
  if ( this->m_format == 2 )
  {
    v7 = (char *)MemAlloc_Alloc(nSize: headerSize);
    this->m_pHeader = v7;
    memcpy(dst: (unsigned __int8 *)v7, src: (unsigned __int8 *)pHeaderBuffer, count: headerSize);
    this->m_nHeaderSize = headerSize;
    this->m_sampleSize = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E320
// Name: public: void CAudioSourceWave::ConvertSamples(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ConvertSamples(CAudioSourceWave *this, char *pData, int sampleCount)
{
  int i; // edx

  if ( this->m_format == 1 && this->m_bits == 8 )
  {
    for ( i = 0; i < sampleCount * this->m_channels; ++pData )
    {
      *pData += 0x80;
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E360
// Name: public: virtual bool CAudioSourceWave::IsLooped(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceWave::IsLooped(CAudioSourceWave *this)
{
  return this->m_loopStart >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E370
// Name: public: virtual bool CAudioSourceWave::IsStereoWav(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceWave::IsStereoWav(CAudioSourceWave *this)
{
  return this->m_channels == 2;
}

//------------------------------------------------------------------------------
// Address: 0x1003E380
// Name: public: virtual int CAudioSourceWave::GetQuality(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceWave::GetQuality(CAudioSourceWave *this)
{
  if ( this->m_format == 357 )
    return this->m_quality;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E3A0
// Name: public: void CAudioSourceWave::Setup(char const __near *,int,class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::Setup(CAudioSourceWave *this, char *pFormatBuffer, int formatSize, IterateRIFF *walk)
{
  CAudioSourceWave_vtbl *v5; // edi
  int Wide; // eax

  CAudioSourceWave::Init(this, pHeaderBuffer: pFormatBuffer, headerSize: formatSize);
  while ( IterateRIFF::ChunkAvailable(this: walk) )
  {
    v5 = this->__vftable;
    Wide = vgui::Image::GetWide(this: (CVTFTexture *)walk);
    v5->ParseChunk(this, a2: walk, a3: Wide);
    IterateRIFF::ChunkNext(this: walk);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E400
// Name: public: __int64 CAudioSourceWave::ConvertLoopedPosition(__int64)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceWave::ConvertLoopedPosition(CAudioSourceWave *this, __int64 samplePosition)
{
  int m_format; // eax
  int m_loopStart; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi

  m_format = this->m_format;
  if ( m_format >= 3 && (m_format <= 4 || m_format == 357) )
    return samplePosition;
  m_loopStart = this->m_loopStart;
  v6 = samplePosition;
  if ( m_loopStart >= 0 && samplePosition >= this->m_sampleCount )
  {
    v7 = this->m_loopStart;
    v8 = this->m_sampleCount - v7;
    v6 = samplePosition - v7;
    if ( v8 != 0 )
      return this->m_loopStart + (samplePosition - v7) % v8;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1003E480
// Name: public: virtual void CAudioSourceWave::ReferenceRemove(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ReferenceRemove(CAudioSourceWave *this, CAudioMixer *pMixer)
{
  if ( this->m_refCount-- == 1 && this->IsPlayOnce(this) )
  {
    this->SetPlayOnce(this, a2: false);
    this->CacheUnload(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E4B0
// Name: public: virtual void CAudioSourceWave::ReferenceAdd(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ReferenceAdd(CAudioSourceWave *this, CAudioMixer *pMixer)
{
  ++this->m_refCount;
}

//------------------------------------------------------------------------------
// Address: 0x1003E4C0
// Name: public: virtual bool CAudioSourceWave::CanDelete(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceWave::CanDelete(CAudioSourceWave *this)
{
  return this->m_refCount <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E4D0
// Name: public: virtual class CAudioMixer __near * CAudioSourceMemWave::CreateMixer(int,int,bool,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Mono *__thiscall CAudioSourceMemWave::CreateMixer(
        CAudioSourceMemWave *this,
        int initialStreamPosition,
        int skipInitialSamples,
        bool bUpdateDelayForChoreo,
        SoundError *soundError)
{
  IWaveData *WaveDataMemory; // eax
  CAudioMixerWave8Mono *result; // eax
  CAudioMixerWave8Mono *v8; // edi
  int m_format; // [esp-18h] [ebp-20h]
  int m_channels; // [esp-14h] [ebp-1Ch]
  int m_bits; // [esp-10h] [ebp-18h]

  m_bits = this->m_bits;
  m_channels = this->m_channels;
  m_format = this->m_format;
  WaveDataMemory = CreateWaveDataMemory(source: this);
  result = CreateWaveMixer(data: WaveDataMemory, format: m_format, channels: m_channels, bits: m_bits);
  v8 = result;
  if ( result != nullptr )
  {
    this->ReferenceAdd(this, a2: result);
    *soundError = SE_OK;
    return v8;
  }
  else
  {
    *soundError = SE_CANT_CREATE_MIXER;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003E540
// Name: public: virtual int CAudioSourceMemWave::ZeroCrossingBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMemWave::ZeroCrossingBefore(CAudioSourceMemWave *this, int sample)
{
  char *v3; // edx
  int result; // eax
  char v5; // bl
  char *v6; // ecx
  char v7; // dl
  __int16 v8; // dx

  v3 = this->GetDataPointer(this);
  result = sample;
  if ( this->m_format == 1 )
  {
    v5 = 0;
    v6 = &v3[sample * this->m_sampleSize];
    if ( this->m_bits == 8 )
    {
      if ( this->m_channels == 1 )
      {
        if ( sample > 0 )
        {
          do
          {
            if ( v5 != 0 )
              break;
            if ( *v6 >= 8 || *v6 <= -8 )
            {
              --result;
              --v6;
            }
            else
            {
              v5 = 1;
            }
          }
          while ( result > 0 );
        }
      }
      else if ( sample > 0 )
      {
        do
        {
          if ( v5 != 0 )
            break;
          if ( *v6 >= 8 || *v6 <= -8 || (v7 = v6[1]) >= 8 || v7 <= -8 )
          {
            --result;
            --v6;
          }
          else
          {
            v5 = 1;
          }
        }
        while ( result > 0 );
      }
    }
    else if ( this->m_channels == 1 )
    {
      if ( sample > 0 )
      {
        do
        {
          if ( v5 != 0 )
            break;
          if ( *(__int16 *)v6 >= 2048 || *(__int16 *)v6 <= -2048 )
          {
            v6 -= 2;
            --result;
          }
          else
          {
            v5 = 1;
          }
        }
        while ( result > 0 );
      }
    }
    else if ( sample > 0 )
    {
      do
      {
        if ( v5 != 0 )
          break;
        if ( *(__int16 *)v6 >= 2048 || *(__int16 *)v6 <= -2048 || (v8 = *((_WORD *)v6 + 1)) >= 2048 || v8 <= -2048 )
        {
          --result;
          v6 -= 2;
        }
        else
        {
          v5 = 1;
        }
      }
      while ( result > 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003E7E0
// Name: public: virtual int CAudioSourceMemWave::GetCacheStatus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMemWave::GetCacheStatus(CAudioSourceMemWave *this)
{
  unsigned int *p_m_hCache; // edi
  IAsyncWavDataCache_vtbl *v3; // ebx
  char *FileName; // eax
  int m_dataSize; // [esp-Ch] [ebp-11Ch]
  int m_dataStart; // [esp-8h] [ebp-118h]
  char nameBuf[261]; // [esp+8h] [ebp-108h] BYREF
  bool bCacheValid; // [esp+10Dh] [ebp-3h] BYREF
  bool bIsMissing; // [esp+10Eh] [ebp-2h] BYREF
  bool bCompleted; // [esp+10Fh] [ebp-1h]

  p_m_hCache = &this->m_hCache;
  bCompleted = wavedatacache->IsDataLoadCompleted(
                 this: wavedatacache,
                 a2: this->m_hCache,
                 a3: &bCacheValid,
                 a4: &bIsMissing);
  if ( !bCacheValid )
  {
    v3 = wavedatacache->__vftable;
    m_dataStart = this->m_dataStart;
    m_dataSize = this->m_dataSize;
    FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
    v3->RestartDataLoad(this: wavedatacache, a2: &this->m_hCache, a3: FileName, a4: m_dataSize, a5: m_dataStart);
  }
  if ( bCompleted )
    return 1;
  if ( bIsMissing )
    return 3;
  return wavedatacache->IsDataLoadInProgress(this: wavedatacache, a2: *p_m_hCache) ? 2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E940
// Name: public: virtual void CAudioSourceMemWave::CacheUnload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMemWave::CacheUnload(CAudioSourceMemWave *this)
{
  unsigned int m_hCache; // eax

  m_hCache = this->m_hCache;
  if ( m_hCache != 0 )
    wavedatacache->Unload(this: wavedatacache, a2: m_hCache);
}

//------------------------------------------------------------------------------
// Address: 0x1003E960
// Name: protected: virtual char __near * CAudioSourceMemWave::GetDataPointer(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAudioSourceMemWave::GetDataPointer(CAudioSourceMemWave *this)
{
  bool v2; // zf
  int m_dataSize; // ebx
  char *FileName; // eax
  IAsyncWavDataCache_vtbl *v5; // edi
  char *v6; // eax
  int m_dataStart; // [esp-14h] [ebp-128h]
  char nameBuf[260]; // [esp+8h] [ebp-10Ch] BYREF
  char *pWaveData; // [esp+10Ch] [ebp-8h] BYREF
  bool bSamplesConverted; // [esp+113h] [ebp-1h] BYREF

  v2 = this->m_hCache == 0;
  pWaveData = nullptr;
  bSamplesConverted = false;
  if ( v2 )
    this->CacheLoad(this);
  m_dataSize = this->m_dataSize;
  if ( (*((_BYTE *)&this->CAudioSourceWave + 80) & 8) != 0 )
  {
    FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
    if ( V_stristr(pStr: FileName, pSearch: "music") != nullptr && m_dataSize >= 0x8000 )
      m_dataSize = 0x8000;
  }
  v5 = wavedatacache->__vftable;
  m_dataStart = this->m_dataStart;
  v6 = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  v5->GetDataPointer(
    this: wavedatacache,
    a2: &this->m_hCache,
    a3: v6,
    a4: m_dataSize,
    a5: m_dataStart,
    a6: (void **)&pWaveData,
    a7: 0,
    a8: &bSamplesConverted);
  if ( pWaveData == nullptr || bSamplesConverted )
    return pWaveData;
  CAudioSourceWave::ConvertSamples(this, pData: pWaveData, sampleCount: this->m_dataSize / this->m_sampleSize);
  wavedatacache->SetPostProcessed(this: wavedatacache, a2: this->m_hCache, a3: true);
  return pWaveData;
}

//------------------------------------------------------------------------------
// Address: 0x1003EA40
// Name: public: virtual class CAudioMixer __near * CAudioSourceStreamWave::CreateMixer(int,int,bool,enum SoundError __near &)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Mono *__thiscall CAudioSourceStreamWave::CreateMixer(
        CAudioSourceStreamWave *this,
        int initialStreamPosition,
        int skipInitialSamples,
        bool bUpdateDelayForChoreo,
        SoundError *soundError)
{
  char *v6; // eax
  CWaveDataStreamAsync *WaveDataStream; // edi
  CAudioMixerWave8Mono *WaveMixer; // ebx
  char fileName[260]; // [esp+Ch] [ebp-104h] BYREF

  v6 = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: fileName, bufLen: 0x104u);
  WaveDataStream = CreateWaveDataStream(
                     source: this,
                     pStreamSource: &this->IWaveStreamSource,
                     pFileName: v6,
                     dataStart: this->m_dataStart,
                     dataSize: this->m_dataSize,
                     pSfx: this->m_pSfx,
                     startOffset: initialStreamPosition,
                     skipInitialSamples,
                     soundError);
  if ( WaveDataStream != nullptr )
  {
    WaveMixer = CreateWaveMixer(
                  data: WaveDataStream,
                  format: this->m_format,
                  channels: this->m_channels,
                  bits: this->m_bits);
    if ( WaveMixer != nullptr )
    {
      this->ReferenceAdd(this, a2: WaveMixer);
      return WaveMixer;
    }
    ((void (__thiscall *)(CWaveDataStreamAsync *, int))WaveDataStream->dtr_IWaveData)(a1: WaveDataStream, a2: 1);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003EAE0
// Name: public: virtual void CAudioSourceStreamWave::Prefetch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceStreamWave::Prefetch(CAudioSourceStreamWave *this)
{
  char *FileName; // eax
  int m_dataStart; // [esp-8h] [ebp-10Ch]
  int m_dataSize; // [esp-4h] [ebp-108h]
  char nameBuf[260]; // [esp+0h] [ebp-104h] BYREF

  m_dataSize = this->m_dataSize;
  m_dataStart = this->m_dataStart;
  FileName = CSfxTable::GetFileName(this: this->m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  PrefetchDataStream(pFileName: FileName, dataOffset: m_dataStart, dataSize: m_dataSize);
}

//------------------------------------------------------------------------------
// Address: 0x1003EB20
// Name: public: virtual int CAudioSourceStreamWave::SampleToStreamPosition(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceStreamWave::SampleToStreamPosition(CAudioSourceStreamWave *this, int samplePosition)
{
  int m_nHeaderSize; // eax
  char *m_pHeader; // esi
  int v4; // eax
  int v5; // ecx
  const char *v7; // eax
  char fileName[260]; // [esp+0h] [ebp-104h] BYREF

  if ( this->m_format == 1 )
    return samplePosition * this->m_sampleSize;
  if ( this->m_format == 357 && (m_nHeaderSize = this->m_nHeaderSize) != 0 )
  {
    m_pHeader = this->m_pHeader;
    v4 = m_nHeaderSize / 4;
    v5 = 0;
    if ( v4 <= 0 )
      return 0;
    while ( samplePosition >= *(_DWORD *)&m_pHeader[4 * v5] )
    {
      if ( ++v5 >= v4 )
        return 0;
    }
    if ( v5 != 0 )
      return (v5 << 11) - 2048;
    else
      return 0;
  }
  else
  {
    v7 = this->GetFileName(this, a2: fileName, a3: 260);
    _Warning(a1: "SampleToStreamPosition( %d ) is not supported for sound '%s'.\n", samplePosition, v7);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EBD0
// Name: public: virtual int CAudioSourceStreamWave::StreamToSamplePosition(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceStreamWave::StreamToSamplePosition(CAudioSourceStreamWave *this, int streamPosition)
{
  int m_nHeaderSize; // edi
  int v3; // esi
  const char *v5; // eax
  char fileName[260]; // [esp+0h] [ebp-104h] BYREF

  if ( this->m_format == 1 )
    return streamPosition / this->m_sampleSize;
  if ( this->m_format == 357 && (m_nHeaderSize = this->m_nHeaderSize) != 0 )
  {
    v3 = streamPosition / 2048;
    if ( streamPosition / 2048 > 0 )
    {
      if ( v3 <= m_nHeaderSize / 4 )
        return *(_DWORD *)&this->m_pHeader[4 * v3 - 4];
      else
        return this->m_numDecodedSamples;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v5 = this->GetFileName(this, a2: fileName, a3: 260);
    _Warning(a1: "StreamToSamplePosition( %d ) is not supported for sound '%s'.\n", streamPosition, v5);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EC80
// Name: public: virtual int CAudioSourceStreamWave::GetCacheStatus(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioSourceStreamWave::GetCacheStatus(CAudioSourceStreamWave *this)
{
  return this->m_dataSize != 0 && this->m_dataStart != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003ECA0
// Name: float AudioSource_GetSoundDuration(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl AudioSource_GetSoundDuration(CSfxTable *pSfx)
{
  float v2; // [esp+4h] [ebp-4h]

  if ( pSfx == nullptr || pSfx->pSource == nullptr )
    return 0.0;
  v2 = (float)pSfx->pSource->SampleCount(this: pSfx->pSource);
  return v2 / (double)pSfx->pSource->SampleRate(this: pSfx->pSource);
}

//------------------------------------------------------------------------------
// Address: 0x1003ECF0
// Name: public: void CAudioSourceCachedInfo::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Clear(CAudioSourceCachedInfo *this)
{
  CSentence *m_pSentence; // edi
  unsigned __int8 *m_pHeader; // [esp-8h] [ebp-14h]
  unsigned __int8 *m_pCachedData; // [esp-4h] [ebp-10h]

  m_pSentence = this->m_pSentence;
  this->infolong = 0;
  this->flagsbyte = 0;
  this->m_dataStart = 0;
  this->m_dataSize = 0;
  this->m_loopStart = 0;
  this->m_sampleCount = 0;
  if ( m_pSentence != nullptr )
  {
    CSentence::~CSentence(this: m_pSentence);
    free(pMem: m_pSentence);
  }
  m_pCachedData = this->m_pCachedData;
  this->m_pSentence = nullptr;
  free(pMem: m_pCachedData);
  m_pHeader = this->m_pHeader;
  this->m_pCachedData = nullptr;
  this->m_usCachedDataSize = 0;
  free(pMem: m_pHeader);
  this->m_pHeader = nullptr;
  this->m_usHeaderSize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003ED50
// Name: private: void CAudioSourceCache::RemoveCache(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::RemoveCache(CAudioSourceCache *this, const char *cachename)
{
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: cachename, a3: "MOD") )
  {
    if ( !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: cachename, a3: "MOD") )
      g_pFullFileSystem->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: cachename, a3: true, a4: "MOD");
    g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: cachename, a3: "MOD");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EDC0
// Name: protected: unsigned char __near * CAudioSourceWave::GetCachedDataPointer(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CAudioSourceWave::GetCachedDataPointer(CAudioSourceWave *this)
{
  CSfxTable *m_pSfx; // edi
  int *p_m_nCachedDataSize; // ebx
  CAudioSourceCachedInfo *v4; // eax
  CAudioSourceCachedInfo *info; // esi
  bool IsPrecachedSound; // [esp+Ch] [ebp-4h]

  m_pSfx = this->m_pSfx;
  p_m_nCachedDataSize = &this->m_nCachedDataSize;
  IsPrecachedSound = CSfxTable::IsPrecachedSound(this: m_pSfx);
  if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
  {
    v4 = audiosourcecache->GetInfo(this: audiosourcecache, a2: 1, a3: IsPrecachedSound, a4: m_pSfx);
    this->m_AudioCacheHandle.info = v4;
    if ( this != (CAudioSourceWave *)-64 && v4 != nullptr )
      *p_m_nCachedDataSize = v4->m_usCachedDataSize;
    this->m_AudioCacheHandle.m_FlushCount = CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
  }
  info = this->m_AudioCacheHandle.info;
  if ( info != nullptr )
    return info->m_pCachedData;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003EE90
// Name: public: virtual void CAudioSourceWave::SetPlayOnce(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::SetPlayOnce(CAudioSourceWave *this, bool bIsPlayOnce)
{
  *((_DWORD *)this + 20) ^= (*((_DWORD *)this + 20) ^ (2 * bIsPlayOnce)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x1003EEB0
// Name: public: virtual bool CAudioSourceWave::IsPlayOnce(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioSourceWave::IsPlayOnce(CAudioSourceWave *this)
{
  return (*((_DWORD *)this + 20) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003EEC0
// Name: public: virtual void CAudioSourceWave::SetSentenceWord(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::SetSentenceWord(CAudioSourceWave *this, bool bIsWord)
{
  *((_DWORD *)this + 20) ^= (*((_DWORD *)this + 20) ^ (4 * bIsWord)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x1003EEE0
// Name: public: virtual bool CAudioSourceWave::IsSentenceWord(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioSourceWave::IsSentenceWord(CAudioSourceWave *this)
{
  return (*((_DWORD *)this + 20) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003EEF0
// Name: public: CAudioSourceWave::CAudioSourceWave(class CSfxTable __near *,class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceWave *__thiscall CAudioSourceWave::CAudioSourceWave(
        CAudioSourceWave *this,
        CSfxTable *pSfx,
        CAudioSourceCachedInfo *info)
{
  char *v4; // eax
  bool v5; // zf
  int m_sampleCount; // edi
  char *m_pHeader; // eax
  int v8; // ebx
  int v9; // edi
  int v10; // ecx
  int v11; // edx
  int pSfxa; // [esp+14h] [ebp+8h]

  this->__vftable = (CAudioSourceWave_vtbl *)&CAudioSourceWave::`vftable';
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  this->m_pSfx = pSfx;
  this->m_refCount = 0;
  this->m_pHeader = nullptr;
  this->m_nHeaderSize = 0;
  if ( info->m_pHeader != nullptr )
  {
    v4 = (char *)MemAlloc_Alloc(nSize: info->m_usHeaderSize);
    this->m_pHeader = v4;
    _V_memcpy(dest: v4, src: info->m_pHeader, count: info->m_usHeaderSize);
    this->m_nHeaderSize = info->m_usHeaderSize;
  }
  this->m_bits = (info->infolong >> 2) & 0x1F;
  this->m_channels = (info->infolong >> 7) & 3;
  this->m_sampleSize = (info->infolong >> 9) & 7;
  this->m_format = (info->infolong >> 12) & 3;
  this->m_dataStart = info->m_dataStart;
  this->m_dataSize = info->m_dataSize;
  v5 = this->m_format == 2;
  this->m_rate = (info->infolong >> 14) & 0x1FFFF;
  this->m_loopStart = info->m_loopStart;
  m_sampleCount = info->m_sampleCount;
  this->m_sampleCount = m_sampleCount;
  this->m_numDecodedSamples = m_sampleCount;
  if ( v5 )
  {
    m_pHeader = this->m_pHeader;
    if ( m_pHeader != nullptr )
    {
      v8 = *((unsigned __int16 *)m_pHeader + 9);
      v9 = *((unsigned __int16 *)m_pHeader + 1);
      v10 = 7 * v9 + v9 * (v8 - 2) / 2;
      v11 = this->m_sampleCount % v10;
      pSfxa = v8 * (this->m_sampleCount / v10);
      if ( v11 != 0 )
        pSfxa += v8 + 2 * (v11 - v10) / v9;
      this->m_numDecodedSamples = pSfxa;
    }
  }
  *((_DWORD *)this + 20) &= 0xFFFFFFF0;
  this->m_pTempSentence = nullptr;
  this->m_nCachedDataSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003F010
// Name: public: virtual CAudioSourceWave::~CAudioSourceWave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::~CAudioSourceWave(CAudioSourceWave *this)
{
  CSentence *m_pTempSentence; // edi
  char *m_pHeader; // [esp-4h] [ebp-Ch]

  m_pHeader = this->m_pHeader;
  this->__vftable = (CAudioSourceWave_vtbl *)&CAudioSourceWave::`vftable';
  free(pMem: m_pHeader);
  m_pTempSentence = this->m_pTempSentence;
  if ( m_pTempSentence != nullptr )
  {
    CSentence::~CSentence(this: this->m_pTempSentence);
    free(pMem: m_pTempSentence);
  }
  this->__vftable = (CAudioSourceWave_vtbl *)&CAudioSource::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1003F050
// Name: public: virtual bool CAudioSourceWave::IsAsyncLoad(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceWave::IsAsyncLoad(CAudioSourceWave *this)
{
  int v2; // eax
  int m_nValue; // eax
  bool IsPrecachedSound; // [esp-Ch] [ebp-10h]
  CSfxTable *m_pSfx; // [esp-8h] [ebp-Ch]

  if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
  {
    m_pSfx = this->m_pSfx;
    IsPrecachedSound = CSfxTable::IsPrecachedSound(this: m_pSfx);
    v2 = this->GetType(this);
    CAudioSourceCachedInfoHandle_t::Get(
      this: &this->m_AudioCacheHandle,
      audiosourcetype: v2,
      soundisprecached: IsPrecachedSound,
      sfx: m_pSfx,
      pcacheddatasize: &this->m_nCachedDataSize);
  }
  if ( snd_async_minsize.m_pParent != nullptr )
    m_nValue = snd_async_minsize.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  return this->m_dataSize > m_nValue || this->m_nCachedDataSize <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F0B0
// Name: public: virtual void CAudioSourceWave::CheckAudioSourceCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::CheckAudioSourceCache(CAudioSourceWave *this)
{
  CSfxTable *m_pSfx; // ebx
  int v3; // eax
  CAudioSourceCachedInfo *v4; // eax

  if ( CSfxTable::IsPrecachedSound(this: this->m_pSfx) )
  {
    m_pSfx = this->m_pSfx;
    v3 = this->GetType(this);
    if ( this->m_AudioCacheHandle.m_FlushCount != CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount )
    {
      v4 = audiosourcecache->GetInfo(this: audiosourcecache, a2: v3, a3: 1, a4: m_pSfx);
      this->m_AudioCacheHandle.info = v4;
      if ( this != (CAudioSourceWave *)-64 && v4 != nullptr )
        this->m_nCachedDataSize = v4->m_usCachedDataSize;
      this->m_AudioCacheHandle.m_FlushCount = CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F140
// Name: public: virtual void CAudioSourceWave::ParseChunk(class IterateRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ParseChunk(CAudioSourceWave *this, IterateRIFF *walk, int chunkName)
{
  _BYTE pOutput[28]; // [esp+4h] [ebp-54h] BYREF
  int v5; // [esp+20h] [ebp-38h]
  int v6; // [esp+2Ch] [ebp-2Ch]
  int v7; // [esp+30h] [ebp-28h]
  _BYTE v8[20]; // [esp+40h] [ebp-18h] BYREF
  int v9; // [esp+54h] [ebp-4h]

  switch ( chunkName )
  {
    case 543520099:
      if ( IterateRIFF::ChunkReadInt(this: walk) > 0 )
      {
        IterateRIFF::ChunkReadPartial(this: walk, pOutput: v8, dataSize: 24);
        this->m_loopStart = v9;
      }
      break;
    case 1413563478:
      this->ParseSentence(this, a2: walk);
      break;
    case 1819307379:
      IterateRIFF::ChunkReadPartial(this: walk, pOutput, dataSize: 60);
      if ( v5 != 0 && v6 == 0 )
        this->m_loopStart = v7;
      break;
    default:
      vgui::Image::GetWide(this: (CVTFTexture *)walk);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F380
// Name: public: CAudioSourceMemWave::CAudioSourceMemWave(class CSfxTable __near *,class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMemWave *__thiscall CAudioSourceMemWave::CAudioSourceMemWave(
        CAudioSourceMemWave *this,
        CSfxTable *pSfx,
        CAudioSourceCachedInfo *info)
{
  CAudioSourceWave::CAudioSourceWave(this, pSfx, info);
  this->__vftable = (CAudioSourceMemWave_vtbl *)&CAudioSourceMemWave::`vftable';
  this->m_hCache = 0;
  this->m_hStream = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003F3B0
// Name: public: virtual int CAudioSourceMemWave::GetOutputData(void __near * __near *,__int64,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMemWave::GetOutputData(
        CAudioSourceMemWave *this,
        void **pData,
        __int64 samplePosition,
        int sampleCount,
        char *copyBuf)
{
  unsigned int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  int v11; // edi
  int v12; // kr00_4
  unsigned __int8 *CachedDataPointer; // eax
  __int64 samplePositiona; // [esp+18h] [ebp+Ch]

  v7 = CAudioSourceWave::ConvertLoopedPosition(this, samplePosition);
  v8 = this->m_sampleCount - v7;
  if ( v8 < 0 )
    v8 = 0;
  v9 = sampleCount;
  if ( sampleCount > v8 )
    v9 = v8;
  v12 = this->m_sampleSize * v7;
  v10 = (this->m_sampleSize * __PAIR64__(v6, v7)) >> 32;
  v11 = v12;
  samplePositiona = __PAIR64__(v10, v12);
  if ( v9 == 0 )
    return v9;
  if ( __SPAIR64__(v10, v12) < this->m_nCachedDataSize )
  {
    this->CacheLoad(this);
    if ( samplePositiona + v9 * this->m_sampleSize >= this->m_nCachedDataSize )
      v9 = (this->m_nCachedDataSize - samplePositiona) / this->m_sampleSize;
    CachedDataPointer = CAudioSourceWave::GetCachedDataPointer(this);
    v11 = samplePositiona;
  }
  else
  {
    CachedDataPointer = (unsigned __int8 *)this->GetDataPointer(this);
  }
  *pData = CachedDataPointer;
  if ( CachedDataPointer != nullptr )
  {
    *pData = &CachedDataPointer[v11];
    return v9;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F480
// Name: public: void CAudioSourceMemWave::ParseDataChunk(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMemWave::ParseDataChunk(CAudioSourceMemWave *this, IterateRIFF *walk)
{
  int SamplePosition; // eax
  CAudioSourceMemWave_vtbl *v4; // edx
  char *v5; // edi
  CSfxTable *m_pSfx; // ecx
  char *FileName; // eax
  int m_format; // eax
  int v9; // eax
  char *m_pHeader; // eax
  int v11; // ebx
  int v12; // edi
  int v13; // ecx
  int v14; // edx
  int m_sampleCount; // edx
  char *v16; // eax
  int i; // ecx
  char nameBuf[260]; // [esp+Ch] [ebp-108h] BYREF
  char *pData; // [esp+110h] [ebp-4h]
  int walka; // [esp+11Ch] [ebp+8h]

  this->m_dataStart = walk->m_chunkPosition + 8;
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)walk);
  v4 = this->__vftable;
  this->m_dataSize = SamplePosition;
  v5 = v4->GetDataPointer(this);
  pData = v5;
  if ( v5 == nullptr )
  {
    m_pSfx = this->m_pSfx;
    if ( m_pSfx != nullptr )
      FileName = CSfxTable::GetFileName(this: m_pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
    else
      FileName = "m_pSfx = NULL";
    _Error(a1: "CAudioSourceMemWave (%s): GetDataPointer() failed.", FileName);
  }
  IterateRIFF::ChunkRead(this: walk, pOutput: v5);
  m_format = this->m_format;
  if ( m_format == 1 )
  {
    v9 = this->m_dataSize / this->m_sampleSize;
    this->m_sampleCount = v9;
    this->m_numDecodedSamples = v9;
  }
  else if ( m_format == 2 )
  {
    this->m_sampleCount = this->m_dataSize;
    m_pHeader = this->m_pHeader;
    this->m_sampleSize = 1;
    this->m_bits = 16;
    v11 = *((unsigned __int16 *)m_pHeader + 9);
    v12 = *((unsigned __int16 *)m_pHeader + 1);
    v13 = 7 * v12 + v12 * (v11 - 2) / 2;
    v14 = this->m_dataSize % v13;
    walka = v11 * (this->m_dataSize / v13);
    if ( v14 != 0 )
      walka += v11 + 2 * (v14 - v13) / v12;
    v5 = pData;
    this->m_numDecodedSamples = walka;
  }
  if ( v5 != nullptr )
  {
    m_sampleCount = this->m_sampleCount;
    v16 = v5;
    if ( this->m_format == 1 && this->m_bits == 8 )
    {
      for ( i = 0; i < m_sampleCount * this->m_channels; ++v16 )
      {
        *v16 += 0x80;
        ++i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F5B0
// Name: public: CAudioSourceStreamWave::CAudioSourceStreamWave(class CSfxTable __near *,class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceStreamWave *__thiscall CAudioSourceStreamWave::CAudioSourceStreamWave(
        CAudioSourceStreamWave *this,
        CSfxTable *pSfx,
        CAudioSourceCachedInfo *info)
{
  CAudioSourceWave::CAudioSourceWave(this, pSfx, info);
  this->IWaveStreamSource::__vftable = (IWaveStreamSource_vtbl *)&IWaveStreamSource::`vftable';
  this->m_pSfx = pSfx;
  this->CAudioSourceWave::CAudioSource::__vftable = (CAudioSourceStreamWave_vtbl *)&CAudioSourceStreamWave::`vftable'{for `CAudioSourceWave'};
  this->IWaveStreamSource::__vftable = (IWaveStreamSource_vtbl *)&CAudioSourceStreamWave::`vftable'{for `IWaveStreamSource'};
  this->m_hWaveFileAccess = nullptr;
  this->m_dataStart = info->m_dataStart;
  this->m_dataSize = info->m_dataSize;
  this->m_sampleCount = info->m_sampleCount;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003F600
// Name: public: virtual __int64 CAudioSourceStreamWave::UpdateLoopingSamplePosition(__int64)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceStreamWave::UpdateLoopingSamplePosition(
        CAudioSourceStreamWave *this,
        __int64 samplePosition)
{
  return CAudioSourceWave::ConvertLoopedPosition(this: (CAudioSourceStreamWave *)((char *)this - 88), samplePosition);
}

//------------------------------------------------------------------------------
// Address: 0x1003F620
// Name: public: virtual void CAudioSourceStreamWave::UpdateSamples(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceStreamWave::UpdateSamples(CAudioSourceStreamWave *this, char *pData, int sampleCount)
{
  int i; // edx

  if ( *((_DWORD *)this - 18) == 1 && *((_DWORD *)this - 21) == 8 )
  {
    for ( i = 0; i < sampleCount * *((_DWORD *)this - 19); ++pData )
    {
      *pData += 0x80;
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F660
// Name: public: virtual int CAudioSourceStreamWave::GetLoopingInfo(int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceStreamWave::GetLoopingInfo(
        CAudioSourceStreamWave *this,
        int *pLoopBlock,
        int *pNumLeadingSamples,
        int *pNumTrailingSamples)
{
  if ( pLoopBlock != nullptr )
    *pLoopBlock = *((unsigned __int16 *)this - 8);
  if ( pNumLeadingSamples != nullptr )
    *pNumLeadingSamples = *((unsigned __int16 *)this - 7);
  if ( pNumTrailingSamples != nullptr )
    *pNumTrailingSamples = *((unsigned __int16 *)this - 6);
  return *((_DWORD *)this - 16);
}

//------------------------------------------------------------------------------
// Address: 0x1003F6A0
// Name: public: virtual CAudioSourceStreamWave::~CAudioSourceStreamWave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceStreamWave::~CAudioSourceStreamWave(CAudioSourceStreamWave *this)
{
  void *m_hWaveFileAccess; // eax
  CSentence *m_pTempSentence; // edi
  char *m_pHeader; // [esp-4h] [ebp-Ch]

  m_hWaveFileAccess = this->m_hWaveFileAccess;
  this->CAudioSourceWave::CAudioSource::__vftable = (CAudioSourceStreamWave_vtbl *)&CAudioSourceStreamWave::`vftable'{for `CAudioSourceWave'};
  this->IWaveStreamSource::__vftable = (IWaveStreamSource_vtbl *)&CAudioSourceStreamWave::`vftable'{for `IWaveStreamSource'};
  if ( m_hWaveFileAccess != nullptr )
  {
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: m_hWaveFileAccess);
    this->m_hWaveFileAccess = nullptr;
  }
  m_pHeader = this->m_pHeader;
  this->CAudioSourceWave::CAudioSource::__vftable = (CAudioSourceStreamWave_vtbl *)&CAudioSourceWave::`vftable';
  free(pMem: m_pHeader);
  m_pTempSentence = this->m_pTempSentence;
  if ( m_pTempSentence != nullptr )
  {
    CSentence::~CSentence(this: this->m_pTempSentence);
    free(pMem: m_pTempSentence);
  }
  this->CAudioSourceWave::CAudioSource::__vftable = (CAudioSourceStreamWave_vtbl *)&CAudioSource::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1003F710
// Name: public: virtual void CAudioSourceStreamWave::ParseChunk(class IterateRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceStreamWave::ParseChunk(CAudioSourceStreamWave *this, IterateRIFF *walk, int chunkName)
{
  int SamplePosition; // eax

  if ( chunkName == 1635017060 )
  {
    this->m_dataStart = walk->m_chunkPosition + 8;
    SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)walk);
    this->m_dataSize = SamplePosition;
    this->m_sampleCount = SamplePosition / this->m_sampleSize;
  }
  else
  {
    CAudioSourceWave::ParseChunk(this, walk, chunkName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F750
// Name: void MaybeReportMissingWav(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaybeReportMissingWav(const char *wav)
{
  CUtlSymbol result; // [esp+2h] [ebp-2h] BYREF

  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &wavErrors, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: MaybeReportMissingWav_::_2_::_dynamic_atexit_destructor_for__wavErrors__);
  }
  if ( CUtlSymbolTable::Find(this: &wavErrors, &result, pString: wav)->m_Id == 0xFFFF )
  {
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: wav, a3: nullptr) )
      DevWarning(a1: "Bad Audio file '%s'\n", wav);
    else
      DevWarning(a1: "Missing wav file '%s'\n", wav);
    CUtlSymbolTable::AddString(this: &wavErrors, &result, pString: wav);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F7F0
// Name: Audio_GetADPCMWaveDuration
// Source: json
//------------------------------------------------------------------------------
float __usercall Audio_GetADPCMWaveDuration@<xmm0>(const char *pName@<eax>)
{
  int v3; // esi
  int v4; // ebx
  int Wide; // eax
  int SamplePosition; // eax
  __int64 v7; // rax
  int v8; // ecx
  int v9; // edx
  int v10; // ebx
  char formatBuffer[1024]; // [esp+4h] [ebp-42Ch] BYREF
  InFileRIFF riff; // [esp+404h] [ebp-2Ch] BYREF
  IterateRIFF walk; // [esp+414h] [ebp-1Ch] BYREF
  float sampleRate; // [esp+42Ch] [ebp-4h]

  InFileRIFF::InFileRIFF(this: &riff, pFileName: pName, io: g_pSndIO);
  if ( riff.m_riffName == 1163280727 )
  {
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    v3 = 0;
    v4 = 0;
    while ( IterateRIFF::ChunkAvailable(this: &walk) )
    {
      if ( v3 != 0 && v4 != 0 )
        break;
      Wide = vgui::Image::GetWide(this: (CVTFTexture *)&walk);
      if ( Wide == 544501094 )
      {
        if ( (unsigned int)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&walk) <= 0x400 )
        {
          IterateRIFF::ChunkRead(this: &walk, pOutput: formatBuffer);
          CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&walk);
          v3 = *(unsigned __int16 *)formatBuffer;
        }
      }
      else if ( Wide == 1635017060 )
      {
        if ( v3 != 0 )
        {
          SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&walk);
          if ( v3 != 2 )
            SamplePosition /= *(unsigned __int16 *)&formatBuffer[14] >> 3;
          v4 = SamplePosition;
        }
      }
      else
      {
        vgui::Image::GetWide(this: (CVTFTexture *)&walk);
      }
      IterateRIFF::ChunkNext(this: &walk);
    }
    sampleRate = (float)*(unsigned int *)&formatBuffer[4];
    v7 = *(unsigned __int16 *)&formatBuffer[2] * (*(unsigned __int16 *)&formatBuffer[18] - 2);
    v8 = 7 * *(unsigned __int16 *)&formatBuffer[2] + (((int)v7 - HIDWORD(v7)) >> 1);
    v9 = v4 % v8;
    v10 = *(unsigned __int16 *)&formatBuffer[18] * (v4 / v8);
    if ( v9 != 0 )
      v10 += *(unsigned __int16 *)&formatBuffer[18] + 2 * (v9 - v8) / *(unsigned __int16 *)&formatBuffer[2];
    InFileRIFF::~InFileRIFF(this: &riff);
    return (float)v10 / sampleRate;
  }
  else
  {
    MaybeReportMissingWav(wav: pName);
    InFileRIFF::~InFileRIFF(this: &riff);
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F960
// Name: public: bool CUtlCachedFileData<class CAudioSourceCachedInfo>::ManifestExists(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::ManifestExists(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  const char *v1; // eax
  char manifest_name[512]; // [esp+0h] [ebp-200h] BYREF

  v1 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  V_strncpy(pDest: manifest_name, pSrc: v1, maxLen: 512);
  V_SetExtension(path: manifest_name, extension: ".manifest", pathStringLength: 512);
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD");
}

//------------------------------------------------------------------------------
// Address: 0x1003FA90
// Name: protected: bool CUtlBuffer::GetTypeText<short>(short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<short>(CUtlBuffer *this, __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003FB00
// Name: protected: bool CUtlBuffer::GetTypeText<int>(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<int>(CUtlBuffer *this, int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003FC00
// Name: public: virtual void CAudioSourceWave::GetCacheData(class CAudioSourceCachedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::GetCacheData(CAudioSourceWave *this, CAudioSourceCachedInfo *info)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  CSentence *v5; // eax
  CSentence *v6; // ebx
  char v7; // al
  CSentence *m_pTempSentence; // ebx
  void *v9; // ebx
  char v10; // cl

  CAudioSourceWave::GetStartupData(this);
  info->infolong ^= (info->infolong ^ (4 * this->m_bits)) & 0x7C;
  v3 = info->infolong
     ^ ((unsigned __int16)info->infolong
      ^ (unsigned __int16)((unsigned __int16)this->m_channels << 7))
     & 0x180;
  info->infolong = v3;
  v4 = v3 ^ ((unsigned __int16)v3 ^ (unsigned __int16)((unsigned __int16)this->m_sampleSize << 9)) & 0xE00;
  info->infolong = v4;
  info->infolong = v4 ^ ((unsigned __int16)v4 ^ (unsigned __int16)((unsigned __int16)this->m_format << 12)) & 0x3000;
  info->m_dataStart = this->m_dataStart;
  info->m_dataSize = this->m_dataSize;
  info->infolong ^= (info->infolong ^ (this->m_rate << 14)) & 0x7FFFC000;
  info->m_loopStart = this->m_loopStart;
  info->m_sampleCount = this->m_sampleCount;
  if ( this->m_pTempSentence != nullptr )
  {
    v5 = (CSentence *)MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v5 != nullptr )
      v6 = CSentence::CSentence(this: v5);
    else
      v6 = nullptr;
    CSentence::operator=(this: v6, src: this->m_pTempSentence);
    v7 = info->flagsbyte ^ (v6 != nullptr);
    info->m_pSentence = v6;
    info->flagsbyte ^= v7 & 1;
    m_pTempSentence = this->m_pTempSentence;
    if ( m_pTempSentence != nullptr )
    {
      CSentence::~CSentence(this: this->m_pTempSentence);
      free(pMem: m_pTempSentence);
    }
    this->m_pTempSentence = nullptr;
  }
  if ( this->m_pHeader != nullptr && this->m_nHeaderSize > 0 )
  {
    v9 = MemAlloc_Alloc(nSize: this->m_nHeaderSize);
    _V_memcpy(dest: v9, src: this->m_pHeader, count: this->m_nHeaderSize);
    v10 = info->flagsbyte ^ (4 * (v9 != nullptr));
    info->m_usHeaderSize = this->m_nHeaderSize;
    info->flagsbyte ^= v10 & 4;
    info->m_pHeader = (unsigned __int8 *)v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FD80
// Name: public: virtual void CAudioSourceMemWave::ParseChunk(class IterateRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMemWave::ParseChunk(CAudioSourceMemWave *this, IterateRIFF *walk, int chunkName)
{
  if ( chunkName == 1635017060 )
    CAudioSourceMemWave::ParseDataChunk(this, walk);
  else
    CAudioSourceWave::ParseChunk(this, walk, chunkName);
}

//------------------------------------------------------------------------------
// Address: 0x1003FED0
// Name: Audio_GetWaveDuration
// Source: json
//------------------------------------------------------------------------------
__int64 __usercall Audio_GetWaveDuration@<xmm0>(const char *pName@<esi>)
{
  const char *v1; // eax
  CFmtStrN<256> *v2; // eax
  CAudioSourceCachedInfo *v3; // eax
  unsigned int infolong; // ecx
  int m_sampleCount; // eax
  unsigned int v6; // edx
  int v7; // ecx
  int v8; // edx
  __int64 result; // xmm0_8
  const char *v10; // [esp+0h] [ebp-110h]
  CFmtStrN<256> v11; // [esp+4h] [ebp-10Ch] BYREF

  v1 = PSkipSoundChars(pch: v10);
  v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "sound/%s", v1);
  v3 = audiosourcecache->GetInfoByName(this: audiosourcecache, a2: v2->m_szBuf);
  if ( v3 == nullptr )
    return 0;
  infolong = v3->infolong;
  m_sampleCount = v3->m_sampleCount;
  v6 = infolong;
  v7 = (infolong >> 14) & 0x1FFFF;
  v8 = (v6 >> 12) & 3;
  if ( v8 == 0 || m_sampleCount == 0 )
    return 0;
  if ( v8 == 2 )
  {
    *(float *)&result = Audio_GetADPCMWaveDuration(pName);
  }
  else
  {
    HIDWORD(result) = 0;
    *(float *)&result = (float)m_sampleCount / (float)v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003FF60
// Name: float AudioSource_GetSoundDuration(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl AudioSource_GetSoundDuration(const char *pName)
{
  if ( Audio_IsMP3(pName) )
    return GetMP3Duration_Helper(filename: pName);
  else
    return COERCE_FLOAT(Audio_GetWaveDuration(pName));
}

//------------------------------------------------------------------------------
// Address: 0x1003FFD0
// Name: public: virtual void CAudioSourceCache::LevelInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::LevelInit(CAudioSourceCache *this, const char *mapname)
{
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+4h] [ebp-10Ch] BYREF

  v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, pszFormat: "%s/%s", "maps/soundcache", mapname);
  CUtlString::operator=(this: &this->m_szMapCacheBase, src: v3->m_szBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10040010
// Name: private: void CAudioSourceCache::GetAudioCacheLanguageSuffix(class CUtlString __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::GetAudioCacheLanguageSuffix(CAudioSourceCache *this, CUtlString *sLanguage)
{
  const char *v2; // eax
  const char *v3; // edi
  void *v4; // esi
  CFmtStrN<256> *v5; // eax
  char szCacheLanguage[1024]; // [esp+4h] [ebp-610h] BYREF
  char szLanguageList[260]; // [esp+404h] [ebp-210h] BYREF
  CFmtStrN<256> v8; // [esp+508h] [ebp-10Ch] BYREF

  v2 = g_pSoundServices->GetUILanguage(this: g_pSoundServices);
  v3 = v2;
  if ( v2 != nullptr && *v2 != 0 && _V_stricmp(s1: v2, s2: "english") != 0 )
  {
    V_snprintf(pDest: szLanguageList, maxLen: 260, pFormat: "%s/localization_cache_list.txt", "maps/soundcache");
    v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: szLanguageList, a3: "r", a4: 0);
    if ( v4 == nullptr )
    {
      v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "_%s", v3);
      goto LABEL_7;
    }
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: szCacheLanguage, a3: 1024, a4: v4);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
    if ( V_stristr(pStr: szCacheLanguage, pSearch: v3) != nullptr )
    {
      v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "_%s", v3);
LABEL_7:
      CUtlString::operator=(this: sLanguage, src: v5->m_szBuf);
      return;
    }
    CUtlString::operator=(this: sLanguage, src: defaultValue);
  }
  else
  {
    CUtlString::operator=(this: sLanguage, src: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040770
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100407B0
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100407F0
// Name: protected: void CUtlBuffer::PutTypeBin<short>(short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<short>(CUtlBuffer *this, __int16 src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 2) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned short>(
        this: &this->m_Byteswap,
        outputBuffer: (__int16 *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_WORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 2;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040860
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned int>(
        this: &this->m_Byteswap,
        outputBuffer: (int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100408D0
// Name: public: CAudioSourceMemWave::CAudioSourceMemWave(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMemWave *__thiscall CAudioSourceMemWave::CAudioSourceMemWave(CAudioSourceMemWave *this, CSfxTable *pSfx)
{
  this->m_AudioCacheHandle.info = nullptr;
  this->m_AudioCacheHandle.m_FlushCount = 0;
  *((_DWORD *)&this->CAudioSourceWave + 20) &= 0xFFFFFFF0;
  this->m_pSfx = pSfx;
  this->m_format = 0;
  this->m_pHeader = nullptr;
  this->m_nHeaderSize = 0;
  this->m_loopStart = -1;
  this->m_sampleSize = 1;
  this->m_sampleCount = 0;
  this->m_bits = 0;
  this->m_channels = 0;
  this->m_dataStart = 0;
  this->m_dataSize = 0;
  this->m_rate = 0;
  this->m_refCount = 0;
  this->m_pTempSentence = nullptr;
  this->m_nCachedDataSize = 0;
  this->m_numDecodedSamples = 0;
  this->__vftable = (CAudioSourceMemWave_vtbl *)&CAudioSourceMemWave::`vftable';
  this->m_hCache = 0;
  this->m_hStream = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10040930
// Name: class CAudioSource __near * Audio_CreateStreamedWave(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceStreamWave *__cdecl Audio_CreateStreamedWave(CSfxTable *pSfx)
{
  char *FileName; // eax
  CAudioSourceStreamWave *v3; // esi
  bool IsPrecachedSound; // al
  CAudioSourceCachedInfo *(__thiscall *GetInfo)(IAudioSourceCache *, int, bool, CSfxTable *); // edx
  int v6; // eax
  CAudioSourceCachedInfo *v7; // ebx
  CAudioSourceStreamWave *v8; // eax
  char nameBuf[260]; // [esp+4h] [ebp-108h] BYREF
  BOOL v10; // [esp+108h] [ebp-4h]

  FileName = CSfxTable::GetFileName(this: pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  if ( Audio_IsMP3(pName: FileName) )
    return (CAudioSourceStreamWave *)Audio_CreateStreamedMP3(pSfx);
  v3 = nullptr;
  IsPrecachedSound = CSfxTable::IsPrecachedSound(this: pSfx);
  GetInfo = audiosourcecache->GetInfo;
  LOBYTE(v10) = IsPrecachedSound;
  v6 = (int)GetInfo(this: audiosourcecache, a2: 1, a3: v10, a4: pSfx);
  v7 = (CAudioSourceCachedInfo *)v6;
  if ( v6 != 0 && (*(_BYTE *)(v6 + 4) & 3) != 0 )
  {
    v8 = (CAudioSourceStreamWave *)MemAlloc_Alloc(nSize: 0x60u);
    if ( v8 != nullptr )
    {
      v3 = CAudioSourceStreamWave::CAudioSourceStreamWave(this: v8, pSfx, info: v7);
      if ( v3 == nullptr || v3->Format(this: v3) != 0 )
        return v3;
      ((void (__thiscall *)(CAudioSourceStreamWave *, int))v3->dtr_CAudioSource)(a1: v3, a2: 1);
    }
    return nullptr;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100409E0
// Name: class CAudioSource __near * Audio_CreateMemoryWave(class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMP3Cache *__cdecl Audio_CreateMemoryWave(CSfxTable *pSfx)
{
  char *FileName; // eax
  CAudioSourceMemWave *v3; // esi
  bool IsPrecachedSound; // al
  CAudioSourceCachedInfo *(__thiscall *GetInfo)(IAudioSourceCache *, int, bool, CSfxTable *); // edx
  int v6; // eax
  CAudioSourceCachedInfo *v7; // ebx
  CAudioSourceMemWave *v8; // eax
  char nameBuf[260]; // [esp+4h] [ebp-108h] BYREF
  BOOL v10; // [esp+108h] [ebp-4h]

  FileName = CSfxTable::GetFileName(this: pSfx, pOutBuf: nameBuf, bufLen: 0x104u);
  if ( Audio_IsMP3(pName: FileName) )
    return Audio_CreateMemoryMP3(pSfx);
  v3 = nullptr;
  IsPrecachedSound = CSfxTable::IsPrecachedSound(this: pSfx);
  GetInfo = audiosourcecache->GetInfo;
  LOBYTE(v10) = IsPrecachedSound;
  v6 = (int)GetInfo(this: audiosourcecache, a2: 1, a3: v10, a4: pSfx);
  v7 = (CAudioSourceCachedInfo *)v6;
  if ( v6 != 0 && (*(_BYTE *)(v6 + 4) & 3) != 0 )
  {
    v8 = (CAudioSourceMemWave *)MemAlloc_Alloc(nSize: 0x60u);
    if ( v8 != nullptr )
    {
      v3 = CAudioSourceMemWave::CAudioSourceMemWave(this: v8, pSfx, info: v7);
      if ( v3 == nullptr || v3->Format(this: v3) != 0 )
        return (CAudioSourceMP3Cache *)v3;
      ((void (__thiscall *)(CAudioSourceMemWave *, int))v3->dtr_CAudioSource)(a1: v3, a2: 1);
    }
    return nullptr;
  }
  return (CAudioSourceMP3Cache *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10040A90
// Name: public: virtual void CAudioSourceCachedInfo::Rebuild(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Rebuild(CAudioSourceCachedInfo *this, const char *filename)
{
  CAudioSourceMP3Cache *v3; // eax
  CAudioSourceMP3Cache *v4; // eax
  CAudioSourceMemWave *v5; // eax
  CAudioSourceMP3Cache *v6; // esi

  g_bSoundRebuilt = true;
  CAudioSourceCachedInfo::Clear(this);
  this->infolong ^= ((unsigned __int8)CAudioSourceCachedInfo::s_CurrentType ^ (unsigned __int8)this->infolong) & 3;
  if ( CAudioSourceCachedInfo::s_CurrentType == 1 )
  {
    v5 = (CAudioSourceMemWave *)MemAlloc_Alloc(nSize: 0x60u);
    if ( v5 != nullptr )
      v4 = (CAudioSourceMP3Cache *)CAudioSourceMemWave::CAudioSourceMemWave(
                                     this: v5,
                                     pSfx: CAudioSourceCachedInfo::s_pSfx);
    else
      v4 = nullptr;
    *((_DWORD *)&v4[1].CAudioSourceMP3 + 9) |= 8u;
    goto LABEL_9;
  }
  if ( CAudioSourceCachedInfo::s_CurrentType == 2 )
  {
    v3 = (CAudioSourceMP3Cache *)MemAlloc_Alloc(nSize: 0x2Cu);
    if ( v3 != nullptr )
    {
      v4 = CAudioSourceMP3Cache::CAudioSourceMP3Cache(this: v3, pSfx: CAudioSourceCachedInfo::s_pSfx);
LABEL_9:
      v6 = v4;
      if ( v4 != nullptr )
      {
        v4->GetCacheData(this: v4, a2: this);
        ((void (__thiscall *)(CAudioSourceMP3Cache *, int))v6->dtr_CAudioSource)(a1: v6, a2: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040B20
// Name: public: void CAudioSourceCache::WriteManifest(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAudioSourceCache::WriteManifest(CAudioSourceCache *this@<ecx>, int a2@<esi>)
{
  int v3; // edi
  int i; // esi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  void *v8; // eax
  void *v9; // esi
  char full[512]; // [esp+8h] [ebp-430h] BYREF
  char manifest_name[512]; // [esp+208h] [ebp-230h] BYREF
  CUtlBuffer buf; // [esp+408h] [ebp-30h] BYREF

  v3 = g_pSoundServices->GetPrecachedSoundCount(this: g_pSoundServices);
  if ( v3 != 0 )
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
    for ( i = 0; i < v3; ++i )
    {
      v5 = g_pSoundServices->GetPrecachedSound(this: g_pSoundServices, a2: i);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = PSkipSoundChars(pch: v5);
        V_snprintf(pDest: full, maxLen: 512, pFormat: "sound\\%s", v6);
        _V_strlower(start: full);
        V_FixSlashes(pname: full, separator: 92);
        CUtlBuffer::Printf(this: &buf, pFmt: "\"%s\"\r\n", full);
      }
    }
    ((void (__thiscall *)(IFileSystem *, const char *, const char *, int))g_pFullFileSystem->CreateDirHierarchy)(
      a1: g_pFullFileSystem,
      a2: "maps/soundcache",
      a3: "MOD",
      a4: a2);
    v7 = CUtlString::operator char const *(this: &this->m_szMapCacheBase);
    V_snprintf(pDest: manifest_name, maxLen: 512, pFormat: "%s.manifest", v7);
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD")
      && !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD") )
    {
      g_pFullFileSystem->SetFileWritable(
        this: &g_pFullFileSystem->IBaseFileSystem,
        a2: manifest_name,
        a3: true,
        a4: "MOD");
    }
    v8 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *))g_pFullFileSystem->Open)(
                   a1: &g_pFullFileSystem->IBaseFileSystem,
                   a2: manifest_name,
                   a3: "wb");
    v9 = v8;
    if ( v8 != nullptr )
    {
      g_pFullFileSystem->Write(
        this: &g_pFullFileSystem->IBaseFileSystem,
        a2: buf.m_Memory.m_pMemory,
        a3: buf.m_Put,
        a4: v8);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v9);
      DevMsg(a1: "WriteManifest:  Persisting cache manifest '%s' (%d entries)\n", manifest_name, v3);
    }
    else
    {
      _Warning(a1: "WriteManifest:  Unable to persist cache manifest '%s', check file permissions\n", manifest_name);
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
  else
  {
    DevMsg(a1: "Skipping WriteManifest, no entries in sound precache string table\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040D20
// Name: snd_writemanifest
// Source: json
//------------------------------------------------------------------------------
void __usercall snd_writemanifest(int a1@<esi>)
{
  CAudioSourceCache::WriteManifest(this: &g_ASCache, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10041920
// Name: public: char CUtlBuffer::GetChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al

  if ( !CUtlBuffer::CheckGet(this, nSize: 1) )
    return 0;
  result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  ++this->m_Get;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10041950
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100419A0
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041A00
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041A40
// Name: public: virtual void CAudioSourceWave::ParseSentence(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ParseSentence(CAudioSourceWave *this, IterateRIFF *walk)
{
  int SamplePosition; // eax
  int v4; // eax
  CSentence *v5; // eax
  CSentence *v6; // eax
  unsigned __int8 *m_pMemory; // [esp-8h] [ebp-40h]
  int m_Put; // [esp-4h] [ebp-3Ch]
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)walk);
  CUtlBuffer::EnsureCapacity(this: &buf, num: SamplePosition);
  IterateRIFF::ChunkRead(this: walk, pOutput: buf.m_Memory.m_pMemory);
  v4 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)walk);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v4);
  v5 = (CSentence *)MemAlloc_Alloc(nSize: 0x4Cu);
  if ( v5 != nullptr )
    v6 = CSentence::CSentence(this: v5);
  else
    v6 = nullptr;
  m_Put = buf.m_Put;
  m_pMemory = buf.m_Memory.m_pMemory;
  this->m_pTempSentence = v6;
  CSentence::InitFromDataChunk(this: v6, data: m_pMemory, size: m_Put);
  CSentence::MakeRuntimeOnly(this: this->m_pTempSentence);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10041AE0
// Name: public: CAudioSourceCache::~CAudioSourceCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::~CAudioSourceCache(CAudioSourceCache *this)
{
  this->m_szCurrentLanguage.m_Storage.m_nActualLength = 0;
  if ( this->m_szCurrentLanguage.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory);
      this->m_szCurrentLanguage.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szCurrentLanguage.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_szMasterCache.m_Storage.m_nActualLength = 0;
  if ( this->m_szMasterCache.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szMasterCache.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szMasterCache.m_Storage.m_Memory.m_pMemory);
      this->m_szMasterCache.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szMasterCache.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_szMapCacheBase.m_Storage.m_nActualLength = 0;
  if ( this->m_szMapCacheBase.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szMapCacheBase.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szMapCacheBase.m_Storage.m_Memory.m_pMemory);
      this->m_szMapCacheBase.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szMapCacheBase.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_szMODPath.m_Storage.m_nActualLength = 0;
  if ( this->m_szMODPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szMODPath.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szMODPath.m_Storage.m_Memory.m_pMemory);
      this->m_szMODPath.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szMODPath.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041B80
// Name: public: virtual void CAudioSourceCache::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::LevelShutdown(CAudioSourceCache *this)
{
  int v2; // eax

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-makereslists") != 0
    && g_pSoundServices->GetPrecachedSoundCount(this: g_pSoundServices) != 0
    && g_pSoundServices->GetServerCount(this: g_pSoundServices) != this->m_nServerCount )
  {
    this->m_nServerCount = g_pSoundServices->GetServerCount(this: g_pSoundServices);
    CAudioSourceCache::WriteManifest(this, a2: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041BE0
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::ForceRecheckDiskInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::ForceRecheckDiskInfo(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  unsigned __int16 i; // ax

  for ( i = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements,
              i) )
  {
    this->m_Elements.m_Elements.m_pMemory[i].m_Data.diskfileinfo = -2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041D40
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10041DE0
// Name: public: void CUtlBuffer::PutInt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutInt(CUtlBuffer *this, int i)
{
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this, pFmt: "%d", i);
  else
    CUtlBuffer::PutTypeBin<int>(this, src: i);
}

//------------------------------------------------------------------------------
// Address: 0x10041E10
// Name: public: virtual void CAudioSourceCachedInfo::Save(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Save(CAudioSourceCachedInfo *this, CUtlBuffer *buf)
{
  unsigned __int8 flagsbyte; // bl
  int m_Put; // eax
  unsigned int infolong; // [esp-4h] [ebp-Ch]
  int m_dataStart; // [esp-4h] [ebp-Ch]
  int m_dataSize; // [esp-4h] [ebp-Ch]
  int m_loopStart; // [esp-4h] [ebp-Ch]
  int m_sampleCount; // [esp-4h] [ebp-Ch]
  int m_usCachedDataSize; // [esp-4h] [ebp-Ch]

  infolong = this->infolong;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", infolong);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: infolong);
  flagsbyte = this->flagsbyte;
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = flagsbyte;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
  m_dataStart = this->m_dataStart;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_dataStart);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_dataStart);
  m_dataSize = this->m_dataSize;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_dataSize);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_dataSize);
  m_loopStart = this->m_loopStart;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_loopStart);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_loopStart);
  m_sampleCount = this->m_sampleCount;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_sampleCount);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_sampleCount);
  if ( (this->flagsbyte & 1) != 0 )
    CSentence::CacheSaveToBuffer(this: this->m_pSentence, buf, version: 1);
  if ( (this->flagsbyte & 2) != 0 && this->m_pCachedData != nullptr )
  {
    m_usCachedDataSize = this->m_usCachedDataSize;
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%d", m_usCachedDataSize);
    else
      CUtlBuffer::PutTypeBin<int>(this: buf, src: m_usCachedDataSize);
    CUtlBuffer::Put(this: buf, pMem: this->m_pCachedData, size: this->m_usCachedDataSize);
  }
  if ( (this->flagsbyte & 4) != 0 )
  {
    if ( (buf->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buf, pFmt: "%hd", (__int16)this->m_usHeaderSize);
    else
      CUtlBuffer::PutTypeBin<short>(this: buf, src: this->m_usHeaderSize);
    CUtlBuffer::Put(this: buf, pMem: this->m_pHeader, size: this->m_usHeaderSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041FA0
// Name: public: virtual void CAudioSourceCachedInfo::Restore(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCachedInfo::Restore(CAudioSourceCachedInfo *this, CUtlBuffer *buf)
{
  unsigned __int8 v3; // al
  int Int; // eax
  bool v5; // zf
  CSentence *v6; // eax
  CSentence *v7; // eax
  unsigned __int16 v8; // ax
  void *v9; // ebx
  char v10; // dl
  unsigned __int16 Short; // ax
  void *v12; // ebx
  char v13; // dl

  CAudioSourceCachedInfo::Clear(this);
  this->infolong = CUtlBuffer::GetInt(this: buf);
  if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
    ++buf->m_Get;
  }
  else
  {
    v3 = 0;
  }
  this->flagsbyte = v3;
  this->m_dataStart = CUtlBuffer::GetInt(this: buf);
  this->m_dataSize = CUtlBuffer::GetInt(this: buf);
  this->m_loopStart = CUtlBuffer::GetInt(this: buf);
  Int = CUtlBuffer::GetInt(this: buf);
  v5 = (this->flagsbyte & 1) == 0;
  this->m_sampleCount = Int;
  if ( !v5 )
  {
    v6 = (CSentence *)MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v6 != nullptr )
      v7 = CSentence::CSentence(this: v6);
    else
      v7 = nullptr;
    this->m_pSentence = v7;
    CSentence::CacheRestoreFromBuffer(this: v7, buf);
  }
  if ( (this->flagsbyte & 2) != 0 )
  {
    v8 = CUtlBuffer::GetInt(this: buf);
    this->m_usCachedDataSize = v8;
    if ( v8 != 0 )
    {
      v9 = MemAlloc_Alloc(nSize: v8);
      CUtlBuffer::Get(this: buf, pMem: v9, size: this->m_usCachedDataSize);
      v10 = this->flagsbyte ^ (2 * (v9 != nullptr));
      this->m_pCachedData = (unsigned __int8 *)v9;
      this->flagsbyte ^= v10 & 2;
    }
  }
  if ( (this->flagsbyte & 4) != 0 )
  {
    Short = CUtlBuffer::GetShort(this: buf);
    this->m_usHeaderSize = Short;
    if ( Short != 0 )
    {
      v12 = MemAlloc_Alloc(nSize: Short);
      CUtlBuffer::Get(this: buf, pMem: v12, size: this->m_usHeaderSize);
      v13 = this->flagsbyte ^ (4 * (v12 != nullptr));
      this->m_pHeader = (unsigned __int8 *)v12;
      this->flagsbyte ^= v13 & 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100420D0
// Name: public: CUtlCachedFileData<class CAudioSourceCachedInfo>::CUtlCachedFileData<class CAudioSourceCachedInfo>(char const __near *,int,unsigned int (*)(void),enum UtlCachedFileDataType_t,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CUtlCachedFileData<CAudioSourceCachedInfo> *__thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::CUtlCachedFileData<CAudioSourceCachedInfo>(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        const char *repositoryFileName,
        int version,
        unsigned int (__cdecl *checksumfunc)(),
        UtlCachedFileDataType_t fileCheckType,
        bool nevercheckdisk,
        bool readonly,
        bool savemanifest)
{
  char v9; // dl

  this->__vftable = (CUtlCachedFileData<CAudioSourceCachedInfo>_vtbl *)&CUtlCachedFileData<CAudioSourceCachedInfo>::`vftable';
  this->m_Elements.m_LessFunc = (bool (__cdecl *)(const CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *, const CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *))CDmxSerializationDictionary::LessFunc;
  this->m_Elements.m_Elements.m_pMemory = nullptr;
  this->m_Elements.m_Elements.m_nAllocationCount = 0;
  this->m_Elements.m_Elements.m_nGrowSize = 0;
  this->m_Elements.m_pElements = this->m_Elements.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Elements.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Elements.m_FirstFree = -1;
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_sRepositoryFileName, pString: repositoryFileName);
  this->m_nVersion = version;
  this->m_pfnMetaChecksum = checksumfunc;
  this->m_fileCheckType = fileCheckType;
  v9 = *((_BYTE *)this + 84) & 0xE0;
  this->m_uCurrentMetaChecksum = 0;
  *((_BYTE *)this + 84) = nevercheckdisk | v9 | (2 * (readonly | (2 * savemanifest)));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10042320
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::SaveManifest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::SaveManifest(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  signed int m_Size; // esi
  CUtlCachedFileData<CAudioSourceCachedInfo> *v2; // ebx
  int Inorder; // edi
  signed int v4; // ebx
  CSortedCacheFile *m_pMemory; // ecx
  CSortedCacheFile *v6; // ebx
  int *p_index; // edi
  const char *v8; // eax
  const char *v9; // eax
  void *v10; // eax
  void *v11; // esi
  char fn[512]; // [esp+Ch] [ebp-660h] BYREF
  char path[512]; // [esp+20Ch] [ebp-460h] BYREF
  char manifest_name[512]; // [esp+40Ch] [ebp-260h] BYREF
  char v15; // [esp+60Ch] [ebp-60h] BYREF
  CUtlBuffer buf; // [esp+614h] [ebp-58h] BYREF
  CSortedCacheFile insert; // [esp+644h] [ebp-28h] BYREF
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+64Ch] [ebp-20h] BYREF
  CUtlCachedFileData<CAudioSourceCachedInfo> *i; // [esp+668h] [ebp-4h]

  m_Size = 0;
  v2 = this;
  i = this;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  memset(&list, 0, 25);
  Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: &v2->m_Elements);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      insert.handle = v2->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
      list.m_bNeedsSort = true;
      v4 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)&list,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
      }
      m_pMemory = list.m_Memory.m_pMemory;
      list.m_Size = ++m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( m_Size - v4 - 1 > 0 )
      {
        _V_memmove(
          dest: &list.m_Memory.m_pMemory[v4 + 1],
          src: &list.m_Memory.m_pMemory[v4],
          count: 8 * (m_Size - v4 - 1));
        m_pMemory = list.m_Memory.m_pMemory;
      }
      v6 = &m_pMemory[v4];
      if ( v6 != nullptr )
      {
        v6->handle = insert.handle;
        v6->index = Inorder;
      }
      Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                    this: &i->m_Elements,
                                    i: Inorder);
      if ( Inorder == 0xFFFF )
        break;
      v2 = i;
    }
    if ( list.m_bNeedsSort && m_Size > 1 )
    {
      insert.handle = list.m_pLessContext;
      insert.index = (int)&v15;
      qsort_s(
        base: list.m_Memory.m_pMemory,
        num: m_Size,
        width: 8u,
        comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper,
        context: &insert);
    }
    v2 = i;
  }
  if ( m_Size > 0 )
  {
    p_index = &list.m_Memory.m_pMemory->index;
    for ( i = (CUtlCachedFileData<CAudioSourceCachedInfo> *)m_Size;
          i != nullptr;
          i = (CUtlCachedFileData<CAudioSourceCachedInfo> *)((char *)i - 1) )
    {
      ((void (__stdcall *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *, char *, int))g_pFullFileSystem->String)(
        a1: &v2->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)p_index].m_Data,
        a2: fn,
        a3: 512);
      CUtlBuffer::Printf(this: &buf, pFmt: "\"%s\"\r\n", fn);
      p_index += 2;
    }
  }
  v8 = CUtlString::operator char const *(this: &v2->m_sRepositoryFileName);
  V_strncpy(pDest: path, pSrc: v8, maxLen: 512);
  V_StripFilename(path);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: path, a3: "MOD");
  v9 = CUtlString::operator char const *(this: &v2->m_sRepositoryFileName);
  V_strncpy(pDest: manifest_name, pSrc: v9, maxLen: 512);
  V_SetExtension(path: manifest_name, extension: ".manifest", pathStringLength: 512);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD")
    && !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "MOD") )
  {
    g_pFullFileSystem->SetFileWritable(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: manifest_name,
      a3: true,
      a4: "MOD");
  }
  v10 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: manifest_name, a3: "wb", a4: 0);
  v11 = v10;
  if ( v10 != nullptr )
  {
    g_pFullFileSystem->Write(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: buf.m_Memory.m_pMemory,
      a3: buf.m_Put,
      a4: v10);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v11);
  }
  else
  {
    _Warning(a1: "Unable to persist cache manifest '%s', check file permissions\n", manifest_name);
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10042610
// Name: private: class CUtlCachedFileData<class CAudioSourceCachedInfo> __near * CAudioSourceCache::AllocAudioCache(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CUtlCachedFileData<CAudioSourceCachedInfo> *__thiscall CAudioSourceCache::AllocAudioCache(
        CAudioSourceCache *this,
        const char *cachename,
        bool bNeverCheckDisk)
{
  CUtlCachedFileData<CAudioSourceCachedInfo> *v4; // esi
  const char *v5; // eax
  CFmtStrN<256> *v6; // eax
  CFmtStrN<256> v8; // [esp+8h] [ebp-10Ch] BYREF

  v4 = (CUtlCachedFileData<CAudioSourceCachedInfo> *)MemAlloc_Alloc(nSize: 0x58u);
  if ( v4 == nullptr )
    return nullptr;
  v5 = CUtlString::operator char const *(this: &this->m_szMODPath);
  v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "%s%s", v5, cachename);
  return CUtlCachedFileData<CAudioSourceCachedInfo>::CUtlCachedFileData<CAudioSourceCachedInfo>(
           this: v4,
           repositoryFileName: v6->m_szBuf,
           version: 3,
           checksumfunc: nullptr,
           fileCheckType: UTL_CACHED_FILE_USE_FILESIZE,
           nevercheckdisk: bNeverCheckDisk,
           readonly: false,
           savemanifest: false);
}

//------------------------------------------------------------------------------
// Address: 0x10042680
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::Save(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::Save(CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  void *v7; // eax
  void *v8; // edi
  const char *v9; // eax
  int m_Size; // ebx
  int Inorder; // ecx
  CSortedCacheFile *v12; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // ebx
  int fileinfo; // eax
  CAudioSourceCachedInfo *v15; // ecx
  char fn[512]; // [esp+Ch] [ebp-470h] BYREF
  char path[512]; // [esp+20Ch] [ebp-270h] BYREF
  char v18; // [esp+40Ch] [ebp-70h] BYREF
  int inputBuffer; // [esp+410h] [ebp-6Ch] BYREF
  CUtlBuffer buf; // [esp+414h] [ebp-68h] BYREF
  int c; // [esp+444h] [ebp-38h] BYREF
  int j; // [esp+448h] [ebp-34h]
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+44Ch] [ebp-30h] BYREF
  CSortedCacheFile insert; // [esp+468h] [ebp-14h] BYREF
  int v; // [esp+470h] [ebp-Ch] BYREF
  int bufsize; // [esp+474h] [ebp-8h] BYREF
  int i; // [esp+478h] [ebp-4h]

  v2 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  V_strncpy(pDest: path, pSrc: v2, maxLen: 512);
  V_StripFilename(path);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: path, a3: "MOD");
  v3 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: "MOD") )
  {
    v4 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    if ( !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4, a3: "MOD") )
    {
      v5 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      g_pFullFileSystem->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: true, a4: "MOD");
    }
  }
  v6 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  v7 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6, a3: "wb", a4: 0);
  v8 = v7;
  if ( v7 != nullptr )
  {
    *((_BYTE *)this + 84) &= ~8u;
    v = 2;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v7);
    v = this->m_nVersion;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v8);
    v = this->m_uCurrentMetaChecksum;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v, a3: 4, a4: v8);
    c = this->m_Elements.m_NumElements;
    g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &c, a3: 4, a4: v8);
    m_Size = 0;
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    memset(&list, 0, 25);
    Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements);
    i = Inorder;
    if ( Inorder != 0xFFFF )
    {
      while ( 1 )
      {
        insert.handle = this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
        list.m_bNeedsSort = true;
        bufsize = m_Size;
        if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
            this: (CUtlMemory<ResourceEntryInfo,int> *)&list,
            num: m_Size - list.m_Memory.m_nAllocationCount + 1);
          m_Size = list.m_Size;
          Inorder = i;
        }
        ++m_Size;
        list.m_pElements = list.m_Memory.m_pMemory;
        list.m_Size = m_Size;
        if ( m_Size - bufsize - 1 > 0 )
        {
          _V_memmove(
            dest: &list.m_Memory.m_pMemory[bufsize + 1],
            src: &list.m_Memory.m_pMemory[bufsize],
            count: 8 * (m_Size - bufsize - 1));
          Inorder = i;
        }
        v12 = &list.m_Memory.m_pMemory[bufsize];
        if ( v12 != nullptr )
        {
          v12->handle = insert.handle;
          v12->index = Inorder;
        }
        i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_Elements,
                                i: Inorder);
        if ( i == 0xFFFF )
          break;
        Inorder = i;
      }
      if ( list.m_bNeedsSort && m_Size > 1 )
      {
        insert.handle = list.m_pLessContext;
        insert.index = (int)&v18;
        qsort_s(
          base: list.m_Memory.m_pMemory,
          num: m_Size,
          width: 8u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper,
          context: &insert);
      }
    }
    if ( m_Size > 0 )
    {
      i = (int)&list.m_Memory.m_pMemory->index;
      for ( j = m_Size; j != 0; --j )
      {
        p_m_Data = &this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)i].m_Data;
        CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: 0);
        g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)p_m_Data, a3: fn, a4: 512);
        CUtlBuffer::PutString(this: &buf, pString: fn);
        fileinfo = p_m_Data->fileinfo;
        insert.index = fileinfo;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%d", fileinfo);
        }
        else
        {
          inputBuffer = fileinfo;
          if ( CUtlBuffer::CheckPut(this: &buf, nSize: 4) )
          {
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &buf.m_Byteswap,
                outputBuffer: (int *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset],
                &inputBuffer,
                count: 1);
            else
              *(_DWORD *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = insert.index;
            buf.m_Put += 4;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
          }
        }
        v15 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
        v15->Save(this: v15, a2: &buf);
        bufsize = buf.m_Put;
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &bufsize, a3: 4, a4: v8);
        g_pFullFileSystem->Write(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: buf.m_Memory.m_pMemory,
          a3: bufsize,
          a4: v8);
        i += 8;
      }
    }
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8);
    if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
  else
  {
    v9 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Warning(a1: "Unable to persist cache '%s', check file permissions\n", v9);
  }
  if ( (*((_BYTE *)this + 84) & 4) != 0 )
    CUtlCachedFileData<CAudioSourceCachedInfo>::SaveManifest(this);
}

//------------------------------------------------------------------------------
// Address: 0x10042B80
// Name: private: void CAudioSourceCache::RecursiveBuildSoundList(class CUtlRBTree<void __near *,int,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,int>,int>> __near &,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::RecursiveBuildSoundList(
        CAudioSourceCache *this,
        CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *root,
        const char *pLanguage,
        const char *pCurrentDir,
        const char *pathID)
{
  const char *v5; // ebx
  const char *v6; // esi
  char path[512]; // [esp+8h] [ebp-414h] BYREF
  char relative[512]; // [esp+208h] [ebp-214h] BYREF
  char ext[12]; // [esp+408h] [ebp-14h] BYREF
  CAudioSourceCache *v10; // [esp+414h] [ebp-8h]
  void *handle; // [esp+418h] [ebp-4h] BYREF

  v5 = pCurrentDir;
  v10 = this;
  V_snprintf(pDest: path, maxLen: 512, pFormat: "%s/*.*", pCurrentDir);
  V_FixSlashes(pname: path, separator: 92);
  v6 = g_pFullFileSystem->FindFirstEx(this: g_pFullFileSystem, a2: path, a3: pathID, a4: &pCurrentDir);
  if ( v6 != nullptr )
  {
    do
    {
      if ( *v6 != 46 )
      {
        if ( g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: (int)pCurrentDir) )
        {
          V_snprintf(pDest: relative, maxLen: 512, pFormat: "%s/%s", v5, v6);
          CAudioSourceCache::RecursiveBuildSoundList(this: v10, root, pLanguage, pCurrentDir: relative, pathID);
        }
        else
        {
          V_ExtractFileExtension(path: v6, dest: ext, destSize: 10);
          if ( (_V_stricmp(s1: ext, s2: "wav") == 0 || _V_stricmp(s1: ext, s2: "mp3") == 0)
            && V_stristr(pStr: v6, pSearch: ".360.") == nullptr
            && V_stristr(pStr: v6, pSearch: ".ps3.") == nullptr )
          {
            V_snprintf(pDest: relative, maxLen: 512, pFormat: "%s/%s", v5, v6);
            V_FixSlashes(pname: relative, separator: 92);
            handle = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: relative);
            if ( CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Find(
                   this: root,
                   search: &handle) == -1 )
              CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Insert(
                this: root,
                insert: &handle);
          }
        }
      }
      v6 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: pCurrentDir);
    }
    while ( v6 != nullptr );
    g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)pCurrentDir);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042D40
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::Shutdown(CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  char v2; // al
  char v3; // al

  v2 = *((_BYTE *)this + 84);
  if ( (v2 & 0x10) != 0 )
  {
    v3 = v2 & 0xEF;
    *((_BYTE *)this + 84) = v3;
    if ( (v3 & 8) != 0 )
    {
      CUtlCachedFileData<CAudioSourceCachedInfo>::Save(this);
      CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements);
    }
    else
    {
      if ( (v3 & 4) != 0 && !CUtlCachedFileData<CAudioSourceCachedInfo>::ManifestExists(this) )
        CUtlCachedFileData<CAudioSourceCachedInfo>::SaveManifest(this);
      CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042D80
// Name: private: int CUtlCachedFileData<class CAudioSourceCachedInfo>::GetIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        CAudioSourceCachedInfo *filename)
{
  int result; // eax
  CAudioSourceCachedInfo *v4; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CAudioSourceCachedInfo **m_pMemory; // ecx
  int v8; // eax
  CAudioSourceCachedInfo **v9; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t element; // [esp+8h] [ebp-14h] BYREF
  CAudioSourceCachedInfo *data; // [esp+24h] [ebp+8h]

  element.handle = nullptr;
  element.fileinfo = 0;
  element.diskfileinfo = -2;
  element.dataIndex = -1;
  element.handle = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: filename);
  result = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::Find(
             this: &this->m_Elements,
             search: &element);
  if ( (unsigned __int16)result == 0xFFFF )
  {
    v4 = (CAudioSourceCachedInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
    if ( v4 != nullptr )
    {
      v4->__vftable = (CAudioSourceCachedInfo_vtbl *)&CAudioSourceCachedInfo::`vftable';
      v4->infolong = 0;
      v4->flagsbyte = 0;
      v4->m_loopStart = 0;
      v4->m_sampleCount = 0;
      v4->m_dataStart = 0;
      v4->m_dataSize = 0;
      *(_DWORD *)&v4->m_usCachedDataSize = 0;
      v4->m_pSentence = nullptr;
      v4->m_pCachedData = nullptr;
      v4->m_pHeader = nullptr;
      data = v4;
    }
    else
    {
      data = nullptr;
    }
    m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
    m_Size = this->m_Data.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_Data,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Data.m_Size;
    m_pMemory = this->m_Data.m_Memory.m_pMemory;
    v8 = this->m_Data.m_Size - m_Size - 1;
    this->m_Data.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_Data.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = data;
    result = CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::Insert(
               this: &this->m_Elements,
               insert: &element);
    this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)result].m_Data.dataIndex = m_Size;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10042E90
// Name: private: void CUtlCachedFileData<class CAudioSourceCachedInfo>::InitSmallBuffer(void __near * __near &,int,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::InitSmallBuffer(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        void **fh,
        int fileSize,
        bool *deleteFile)
{
  int Int; // eax
  const char *v6; // eax
  int v7; // esi
  int v8; // esi
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // esi
  int v10; // eax
  CAudioSourceCachedInfo *v11; // ecx
  const char *v12; // eax
  const char *v13; // eax
  char elementFileName[512]; // [esp+Ch] [ebp-264h] BYREF
  CUtlBuffer loadBuf; // [esp+20Ch] [ebp-64h] BYREF
  CUtlBuffer buf; // [esp+23Ch] [ebp-34h] BYREF
  int cacheversion; // [esp+26Ch] [ebp-4h] BYREF
  bool *deleteFilea; // [esp+280h] [ebp+10h]

  *deleteFile = false;
  CUtlBuffer::CUtlBuffer(this: &loadBuf, growSize: 0, initSize: 0, nFlags: 0);
  g_pFullFileSystem->ReadToBuffer(this: g_pFullFileSystem, a2: *fh, a3: &loadBuf, a4: 0, a5: nullptr);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: *fh);
  cacheversion = 0;
  CUtlBuffer::Get(this: &loadBuf, pMem: &cacheversion, size: 4);
  if ( cacheversion != 2 )
  {
    v13 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    DevMsg(a1: "Discarding repository '%s' due to cache system version change\n", v13);
    goto LABEL_17;
  }
  if ( CUtlBuffer::GetInt(this: &loadBuf) != this->m_nVersion )
  {
    v12 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Msg(a1: "Discarding repository '%s' due to version change\n", v12);
    *deleteFile = true;
    goto LABEL_18;
  }
  Int = CUtlBuffer::GetInt(this: &loadBuf);
  if ( this->m_pfnMetaChecksum != nullptr && Int != this->m_uCurrentMetaChecksum )
  {
    v6 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    _Msg(a1: "Discarding repository '%s' due to meta checksum change\n", v6);
LABEL_17:
    *deleteFile = true;
    goto LABEL_18;
  }
  v7 = CUtlBuffer::GetInt(this: &loadBuf);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( v7 > 0 )
  {
    for ( deleteFilea = (bool *)v7; deleteFilea != nullptr; --deleteFilea )
    {
      v8 = CUtlBuffer::GetInt(this: &loadBuf);
      memset(&buf.m_Get, 0, 9);
      buf.m_nOffset = 0;
      buf.m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
      CUtlBuffer::EnsureCapacity(this: &buf, num: v8);
      CUtlBuffer::Get(this: &loadBuf, pMem: buf.m_Memory.m_pMemory, size: v8);
      CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v8);
      CUtlBuffer::GetString(this: &buf, pString: elementFileName, nMaxChars: 512);
      p_m_Data = &this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(
                                                                            this,
                                                                            filename: (CAudioSourceCachedInfo *)elementFileName)].m_Data;
      v10 = CUtlBuffer::GetInt(this: &buf);
      p_m_Data->fileinfo = v10;
      if ( v10 == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
        p_m_Data->fileinfo = 0;
      v11 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
      v11->Restore(this: v11, a2: &buf);
    }
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
LABEL_18:
  if ( loadBuf.m_Memory.m_nGrowSize >= 0 && loadBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: loadBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10043090
// Name: private: void CUtlCachedFileData<class CAudioSourceCachedInfo>::InitLargeBuffer(void __near * __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::InitLargeBuffer(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        void **fh,
        bool *deleteFile)
{
  void **v3; // edi
  const char *v5; // eax
  int v6; // edi
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // edi
  int Int; // eax
  CAudioSourceCachedInfo *v9; // ecx
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  void *v13; // [esp-4h] [ebp-258h]
  void *v14; // [esp-4h] [ebp-258h]
  void *v15; // [esp-4h] [ebp-258h]
  void *v16; // [esp-4h] [ebp-258h]
  void *v17; // [esp-4h] [ebp-258h]
  char elementFileName[512]; // [esp+Ch] [ebp-248h] BYREF
  CUtlBuffer buf; // [esp+20Ch] [ebp-48h] BYREF
  unsigned int cache_meta_checksum; // [esp+23Ch] [ebp-18h] BYREF
  int cacheversion; // [esp+240h] [ebp-14h] BYREF
  int i; // [esp+244h] [ebp-10h]
  int version; // [esp+248h] [ebp-Ch] BYREF
  int count; // [esp+24Ch] [ebp-8h] BYREF
  int bufsize; // [esp+250h] [ebp-4h] BYREF

  v3 = fh;
  *deleteFile = false;
  v13 = *fh;
  cacheversion = 0;
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &cacheversion, a3: 4, a4: v13);
  if ( cacheversion == 2 )
  {
    v14 = *fh;
    version = 0;
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &version, a3: 4, a4: v14);
    if ( version == this->m_nVersion )
    {
      v15 = *fh;
      cache_meta_checksum = 0;
      g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &cache_meta_checksum, a3: 4, a4: v15);
      if ( this->m_pfnMetaChecksum == nullptr || cache_meta_checksum == this->m_uCurrentMetaChecksum )
      {
        v16 = *fh;
        count = 0;
        g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &count, a3: 4, a4: v16);
        CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
        i = 0;
        if ( count > 0 )
        {
          while ( 1 )
          {
            v17 = *v3;
            bufsize = 0;
            g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &bufsize, a3: 4, a4: v17);
            if ( bufsize > 1000000 )
              break;
            memset(&buf.m_Get, 0, 9);
            buf.m_nOffset = 0;
            buf.m_nMaxPut = -1;
            CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
            CUtlBuffer::EnsureCapacity(this: &buf, num: bufsize);
            v6 = g_pFullFileSystem->Read(
                   this: &g_pFullFileSystem->IBaseFileSystem,
                   a2: buf.m_Memory.m_pMemory,
                   a3: bufsize,
                   a4: *v3);
            CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
            CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v6);
            CUtlBuffer::GetString(this: &buf, pString: elementFileName, nMaxChars: 512);
            p_m_Data = &this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(
                                                                                  this,
                                                                                  filename: (CAudioSourceCachedInfo *)elementFileName)].m_Data;
            Int = CUtlBuffer::GetInt(this: &buf);
            p_m_Data->fileinfo = Int;
            if ( Int == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
              p_m_Data->fileinfo = 0;
            v9 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
            v9->Restore(this: v9, a2: &buf);
            v3 = fh;
            if ( ++i >= count )
              goto LABEL_14;
          }
          v10 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
          _Msg(a1: "Discarding repository '%s' due to corruption\n", v10);
          *deleteFile = true;
        }
LABEL_14:
        if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      }
      else
      {
        v5 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
        _Msg(a1: "Discarding repository '%s' due to meta checksum change\n", v5);
        *deleteFile = true;
      }
    }
    else
    {
      v11 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      _Msg(a1: "Discarding repository '%s' due to version change\n", v11);
      *deleteFile = true;
    }
  }
  else
  {
    v12 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    DevMsg(a1: "Discarding repository '%s' due to cache system version change\n", v12);
    *deleteFile = true;
  }
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: *v3);
}

//------------------------------------------------------------------------------
// Address: 0x10043300
// Name: public: virtual void CAudioSourceCache::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::Shutdown(CAudioSourceCache *this)
{
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // ecx
  CUtlCachedFileData<CAudioSourceCachedInfo> *v3; // ecx

  m_pMasterSoundCache = this->m_pMasterSoundCache;
  if ( m_pMasterSoundCache != nullptr )
  {
    CUtlCachedFileData<CAudioSourceCachedInfo>::Shutdown(this: m_pMasterSoundCache);
    v3 = this->m_pMasterSoundCache;
    if ( v3 != nullptr )
      ((void (__thiscall *)(CUtlCachedFileData<CAudioSourceCachedInfo> *, int))v3->dtr_CUtlCachedFileData<CAudioSourceCachedInfo>)(
        a1: v3,
        a2: 1);
  }
  if ( this->m_pMasterSoundCache != nullptr )
  {
    this->m_pMasterSoundCache = nullptr;
    ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
  }
  wavedatacache->Shutdown(this: wavedatacache);
}

//------------------------------------------------------------------------------
// Address: 0x10043340
// Name: public: class CAudioSourceCachedInfo __near * CUtlCachedFileData<class CAudioSourceCachedInfo>::Get(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceCachedInfo *__thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::Get(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        CAudioSourceCachedInfo *filename)
{
  unsigned __int16 Index; // ax
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *m_pMemory; // ecx
  int v5; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // esi
  IBaseFileSystem_vtbl *v7; // edx
  IBaseFileSystem *v8; // ecx
  int v9; // eax
  CAudioSourceCachedInfo *v10; // ebx
  char v11; // al
  int cachefileinfo; // [esp+Ch] [ebp-4h]

  Index = CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(this, filename);
  m_pMemory = this->m_Elements.m_Elements.m_pMemory;
  v5 = Index;
  p_m_Data = &m_pMemory[v5].m_Data;
  if ( m_pMemory[v5].m_Data.fileinfo == -1 && this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
    m_pMemory[v5].m_Data.fileinfo = 0;
  cachefileinfo = m_pMemory[v5].m_Data.fileinfo;
  if ( m_pMemory[v5].m_Data.diskfileinfo == -2 )
  {
    if ( (*((_BYTE *)this + 84) & 1) != 0 )
    {
      m_pMemory[v5].m_Data.diskfileinfo = m_pMemory[v5].m_Data.fileinfo;
    }
    else
    {
      v7 = g_pFullFileSystem->IBaseFileSystem::__vftable;
      v8 = &g_pFullFileSystem->IBaseFileSystem;
      if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
      {
        v9 = v7->Size(this: v8, a2: (const char *)filename, a3: "GAME");
        p_m_Data->diskfileinfo = v9;
        if ( v9 == -1 )
          p_m_Data->diskfileinfo = 0;
      }
      else
      {
        p_m_Data->diskfileinfo = v7->GetFileTime(this: v8, a2: (const char *)filename, a3: "GAME");
      }
    }
  }
  v10 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
  if ( cachefileinfo != p_m_Data->diskfileinfo )
  {
    v11 = *((_BYTE *)this + 84);
    if ( (v11 & 2) == 0 )
    {
      *((_BYTE *)this + 84) = v11 | 8;
      v10->Rebuild(this: v10, a2: (const char *)filename);
    }
    p_m_Data->fileinfo = p_m_Data->diskfileinfo;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10043400
// Name: public: class CAudioSourceCachedInfo __near * CUtlCachedFileData<class CAudioSourceCachedInfo>::RebuildItem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceCachedInfo *__thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::RebuildItem(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        CAudioSourceCachedInfo *filename)
{
  unsigned __int16 Index; // ax
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // edi
  IBaseFileSystem_vtbl *v6; // eax
  int v7; // eax
  CAudioSourceCachedInfo *v8; // ecx
  char v9; // al
  CAudioSourceCachedInfo *data; // [esp+14h] [ebp+8h]

  Index = CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(this, filename);
  p_m_Data = &this->m_Elements.m_Elements.m_pMemory[Index].m_Data;
  this->m_Elements.m_Elements.m_pMemory[Index].m_Data.diskfileinfo = -2;
  if ( (*((_BYTE *)this + 84) & 1) != 0 )
  {
    p_m_Data->diskfileinfo = p_m_Data->fileinfo;
  }
  else
  {
    v6 = g_pFullFileSystem->IBaseFileSystem::__vftable;
    if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
    {
      v7 = ((int (__stdcall *)(CAudioSourceCachedInfo *, const char *))v6->Size)(a1: filename, a2: "GAME");
      p_m_Data->diskfileinfo = v7;
      if ( v7 == -1 )
        p_m_Data->diskfileinfo = 0;
    }
    else
    {
      p_m_Data->diskfileinfo = ((int (__stdcall *)(CAudioSourceCachedInfo *, const char *))v6->GetFileTime)(
                                 a1: filename,
                                 a2: "GAME");
    }
  }
  v8 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
  v9 = *((_BYTE *)this + 84);
  data = v8;
  if ( (v9 & 2) == 0 )
  {
    *((_BYTE *)this + 84) = v9 | 8;
    v8->Rebuild(this: v8, a2: (const char *)filename);
    v8 = data;
  }
  p_m_Data->fileinfo = p_m_Data->diskfileinfo;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100434A0
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::RecheckItem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::RecheckItem(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        CAudioSourceCachedInfo *filename)
{
  unsigned __int16 Index; // ax
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *m_pMemory; // ecx
  int v6; // eax
  int fileinfo; // edx
  CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t *p_m_Data; // esi
  IBaseFileSystem_vtbl *v9; // eax
  IBaseFileSystem *v10; // ecx
  int v11; // eax
  CAudioSourceCachedInfo *v12; // ecx
  char v13; // al
  int cachefileinfo; // [esp+14h] [ebp+8h]

  Index = CUtlCachedFileData<CAudioSourceCachedInfo>::GetIndex(this, filename);
  m_pMemory = this->m_Elements.m_Elements.m_pMemory;
  v6 = Index;
  fileinfo = m_pMemory[v6].m_Data.fileinfo;
  p_m_Data = &m_pMemory[v6].m_Data;
  m_pMemory[v6].m_Data.diskfileinfo = -2;
  v9 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v10 = &g_pFullFileSystem->IBaseFileSystem;
  cachefileinfo = fileinfo;
  if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
  {
    v11 = v9->Size(this: v10, a2: (const char *)filename, a3: "GAME");
    p_m_Data->diskfileinfo = v11;
    if ( v11 == -1 )
      p_m_Data->diskfileinfo = 0;
  }
  else
  {
    p_m_Data->diskfileinfo = v9->GetFileTime(this: v10, a2: (const char *)filename, a3: "GAME");
  }
  v12 = this->m_Data.m_Memory.m_pMemory[p_m_Data->dataIndex];
  if ( cachefileinfo == p_m_Data->diskfileinfo )
  {
    p_m_Data->fileinfo = p_m_Data->diskfileinfo;
  }
  else
  {
    v13 = *((_BYTE *)this + 84);
    if ( (v13 & 2) == 0 )
    {
      *((_BYTE *)this + 84) = v13 | 8;
      v12->Rebuild(this: v12, a2: (const char *)filename);
    }
    p_m_Data->fileinfo = p_m_Data->diskfileinfo;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043550
// Name: public: void CUtlCachedFileData<class CAudioSourceCachedInfo>::CheckDiskInfo(bool,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::CheckDiskInfo(
        CUtlCachedFileData<CAudioSourceCachedInfo> *this,
        bool forcerebuild,
        int cacheFileTime)
{
  CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl*)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short> > *p_m_Elements; // ecx
  int i; // esi
  CSortedCacheFile *v6; // esi
  int m_Size; // ebx
  int Inorder; // edx
  void *handle; // ecx
  int v10; // esi
  CSortedCacheFile *m_pMemory; // ecx
  _DWORD *p_handle; // esi
  int v13; // esi
  int *v14; // ebx
  int v15; // eax
  int *p_index; // ebx
  int v17; // eax
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *v18; // ecx
  int p_m_Data; // esi
  IBaseFileSystem *v20; // ecx
  int v21; // eax
  const char *v22; // [esp+0h] [ebp-238h]
  char fn[512]; // [esp+Ch] [ebp-22Ch] BYREF
  CUtlSortVector<CSortedCacheFile,CSortedCacheFile> list; // [esp+20Ch] [ebp-2Ch] BYREF
  int listEnd; // [esp+228h] [ebp-10h]
  int v26; // [esp+22Ch] [ebp-Ch]
  int pathIndex; // [esp+230h] [ebp-8h]
  bool bSteam; // [esp+237h] [ebp-1h]
  int bCheck; // [esp+240h] [ebp+8h]
  int *bChecka; // [esp+240h] [ebp+8h]
  bool bCheck_3; // [esp+243h] [ebp+Bh]

  p_m_Elements = &this->m_Elements;
  if ( forcerebuild )
  {
    for ( i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: p_m_Elements);
          i != 0xFFFF;
          i = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                  this: &this->m_Elements,
                                  i) )
    {
      g_pFullFileSystem->String(
        this: g_pFullFileSystem,
        a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)i].m_Data,
        a3: fn,
        a4: 512);
      CUtlCachedFileData<CAudioSourceCachedInfo>::Get(this, filename: (CAudioSourceCachedInfo *)fn);
    }
    return;
  }
  v6 = nullptr;
  m_Size = 0;
  memset(&list, 0, 25);
  Inorder = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::FirstInorder(this: p_m_Elements);
  bCheck = Inorder;
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      handle = this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.handle;
      pathIndex = (int)&this->m_Elements.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data;
      listEnd = (int)handle;
      list.m_bNeedsSort = true;
      v10 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)&list,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
        Inorder = bCheck;
      }
      m_pMemory = list.m_Memory.m_pMemory;
      list.m_Size = ++m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( m_Size - v10 - 1 > 0 )
      {
        _V_memmove(
          dest: &list.m_Memory.m_pMemory[v10 + 1],
          src: &list.m_Memory.m_pMemory[v10],
          count: 8 * (m_Size - v10 - 1));
        Inorder = bCheck;
        m_pMemory = list.m_Memory.m_pMemory;
      }
      p_handle = &m_pMemory[v10].handle;
      if ( p_handle != nullptr )
      {
        *p_handle = listEnd;
        p_handle[1] = Inorder;
      }
      if ( (*((_BYTE *)this + 84) & 1) != 0 && *(_DWORD *)(pathIndex + 8) == -2 )
        *(_DWORD *)(pathIndex + 8) = *(_DWORD *)(pathIndex + 4);
      bCheck = (unsigned __int16)CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::NextInorder(
                                   this: &this->m_Elements,
                                   i: Inorder);
      if ( bCheck == 0xFFFF )
        break;
      Inorder = bCheck;
    }
    if ( m_Size != 0 && (*((_BYTE *)this + 84) & 1) == 0 )
    {
      v13 = 0;
      bSteam = g_pFullFileSystem->IsSteam(this: g_pFullFileSystem);
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          bChecka = &list.m_Memory.m_pMemory[v13].index;
          pathIndex = g_pFullFileSystem->GetPathIndex(
                        this: g_pFullFileSystem,
                        a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)bChecka].m_Data);
          v26 = v13;
          if ( v13 < m_Size )
          {
            v14 = bChecka;
            do
            {
              v15 = g_pFullFileSystem->GetPathIndex(
                      this: g_pFullFileSystem,
                      a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)v14].m_Data);
              if ( v15 != pathIndex )
                break;
              v14 += 2;
              ++v26;
            }
            while ( v26 < list.m_Size );
          }
          p_index = &list.m_Memory.m_pMemory[v13].index;
          g_pFullFileSystem->String(
            this: g_pFullFileSystem,
            a2: (void *const *)&this->m_Elements.m_Elements.m_pMemory[*(unsigned __int16 *)p_index].m_Data,
            a3: fn,
            a4: 512);
          V_StripFilename(path: fn);
          bCheck_3 = true;
          if ( !bSteam )
            bCheck_3 = g_pFullFileSystem->GetPathTime(this: g_pFullFileSystem, a2: fn, a3: "GAME") > cacheFileTime;
          v17 = v26;
          if ( v13 < v26 )
          {
            pathIndex = v26 - v13;
            do
            {
              v18 = this->m_Elements.m_Elements.m_pMemory;
              p_m_Data = (int)&v18[*(unsigned __int16 *)p_index].m_Data;
              if ( v18[*(unsigned __int16 *)p_index].m_Data.diskfileinfo == -2 )
              {
                if ( bCheck_3 )
                {
                  ((void (__thiscall *)(IFileSystem *, int, char *, int, const char *))g_pFullFileSystem->String)(
                    a1: g_pFullFileSystem,
                    a2: p_m_Data,
                    a3: fn,
                    a4: 512,
                    a5: v22);
                  v20 = &g_pFullFileSystem->IBaseFileSystem;
                  v22 = "GAME";
                  if ( this->m_fileCheckType == UTL_CACHED_FILE_USE_FILESIZE )
                  {
                    v21 = ((int (__thiscall *)(IBaseFileSystem *, char *))v20->Size)(a1: v20, a2: fn);
                    *(_DWORD *)(p_m_Data + 8) = v21;
                    if ( v21 == -1 )
                      *(_DWORD *)(p_m_Data + 8) = 0;
                  }
                  else
                  {
                    *(_DWORD *)(p_m_Data + 8) = ((int (__thiscall *)(IBaseFileSystem *, char *))v20->GetFileTime)(
                                                  a1: v20,
                                                  a2: fn);
                  }
                }
                else
                {
                  *(_DWORD *)(p_m_Data + 8) = *(_DWORD *)(p_m_Data + 4);
                }
              }
              p_index += 2;
              --pathIndex;
            }
            while ( pathIndex != 0 );
            v17 = v26;
          }
          v13 = v17 + 1;
          if ( v17 + 1 >= list.m_Size )
            break;
          m_Size = list.m_Size;
        }
      }
      if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      return;
    }
    v6 = list.m_Memory.m_pMemory;
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && v6 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100438B0
// Name: public: virtual class CAudioSourceCachedInfo __near * CAudioSourceCache::GetInfoByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceCachedInfo *__thiscall CAudioSourceCache::GetInfoByName(
        CAudioSourceCache *this,
        CAudioSourceCachedInfo *soundName)
{
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // ecx

  m_pMasterSoundCache = this->m_pMasterSoundCache;
  if ( m_pMasterSoundCache != nullptr )
    return CUtlCachedFileData<CAudioSourceCachedInfo>::Get(this: m_pMasterSoundCache, filename: soundName);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100438D0
// Name: public: virtual class CAudioSourceCachedInfo __near * CAudioSourceCache::GetInfo(int,bool,class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceCachedInfo *__thiscall CAudioSourceCache::GetInfo(
        CAudioSourceCache *this,
        int audiosourcetype,
        bool soundisprecached,
        CSfxTable *sfx)
{
  char *FileName; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pBuildingCache; // esi
  CAudioSourceCachedInfo *v8; // eax
  CAudioSourceCachedInfo *v9; // edi
  char nameBuf[260]; // [esp+8h] [ebp-304h] BYREF
  char fn[512]; // [esp+10Ch] [ebp-200h] BYREF

  FileName = CSfxTable::GetFileName(this: sfx, pOutBuf: nameBuf, bufLen: 0x104u);
  V_snprintf(pDest: fn, maxLen: 512, pFormat: "sound/%s", FileName);
  CAudioSourceCachedInfo::s_CurrentType = audiosourcetype;
  CAudioSourceCachedInfo::s_pSfx = sfx;
  CAudioSourceCachedInfo::s_bIsPrecacheSound = false;
  if ( this->m_pBuildingCache != nullptr )
    m_pBuildingCache = this->m_pBuildingCache;
  else
    m_pBuildingCache = this->m_pMasterSoundCache;
  if ( m_pBuildingCache == nullptr )
    return nullptr;
  v8 = CUtlCachedFileData<CAudioSourceCachedInfo>::Get(this: m_pBuildingCache, filename: (CAudioSourceCachedInfo *)fn);
  v9 = v8;
  if ( v8 != nullptr
    && (v8->infolong & 0x3000) == 0
    && g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: fn, a3: "BSP") )
  {
    _DevMsg(a1: 1, a2: "Forced rebuild of bsp cache sound '%s'\n", fn);
    return CUtlCachedFileData<CAudioSourceCachedInfo>::RebuildItem(
             this: m_pBuildingCache,
             filename: (CAudioSourceCachedInfo *)fn);
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x100439B0
// Name: public: virtual void CAudioSourceCache::RebuildCacheEntry(int,bool,class CSfxTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::RebuildCacheEntry(
        CAudioSourceCache *this,
        int audiosourcetype,
        bool soundisprecached,
        CSfxTable *sfx)
{
  char *FileName; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pBuildingCache; // eax
  char fn[512]; // [esp+8h] [ebp-304h] BYREF
  char nameBuf[260]; // [esp+208h] [ebp-104h] BYREF

  FileName = CSfxTable::GetFileName(this: sfx, pOutBuf: nameBuf, bufLen: 0x104u);
  V_snprintf(pDest: fn, maxLen: 512, pFormat: "sound/%s", FileName);
  CAudioSourceCachedInfo::s_CurrentType = audiosourcetype;
  CAudioSourceCachedInfo::s_pSfx = sfx;
  CAudioSourceCachedInfo::s_bIsPrecacheSound = false;
  m_pBuildingCache = this->m_pBuildingCache;
  if ( m_pBuildingCache == nullptr )
    m_pBuildingCache = this->m_pMasterSoundCache;
  if ( m_pBuildingCache != nullptr )
    CUtlCachedFileData<CAudioSourceCachedInfo>::RebuildItem(
      this: m_pBuildingCache,
      filename: (CAudioSourceCachedInfo *)fn);
}

//------------------------------------------------------------------------------
// Address: 0x10043A30
// Name: public: void CAudioSourceCache::ValidateSoundCache(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::ValidateSoundCache(CAudioSourceCache *this, CAudioSourceCachedInfo *pchWavFile)
{
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // eax
  CSfxTable *v5; // eax
  CSfxTable *v6; // esi
  CUtlCachedFileData<CAudioSourceCachedInfo> *v7; // ecx
  CUtlCachedFileData<CAudioSourceCachedInfo> *v8; // ecx
  const char *pchWavFilea; // [esp+Ch] [ebp+8h]

  m_pMasterSoundCache = this->m_pMasterSoundCache;
  if ( m_pMasterSoundCache != nullptr )
  {
    *((_BYTE *)m_pMasterSoundCache + 84) &= ~1u;
    pchWavFilea = (char *)&pchWavFile->info + 2;
    v5 = S_PrecacheSound(name: pchWavFilea);
    v6 = v5;
    if ( v5 != nullptr && v5->pSource != nullptr )
    {
      CAudioSourceCachedInfo::s_CurrentType = v5->pSource->GetType(this: v5->pSource);
      CAudioSourceCachedInfo::s_pSfx = v6;
      CAudioSourceCachedInfo::s_bIsPrecacheSound = false;
      v7 = this->m_pMasterSoundCache;
      g_bSoundRebuilt = false;
      CUtlCachedFileData<CAudioSourceCachedInfo>::RecheckItem(this: v7, filename: pchWavFile);
      if ( g_bSoundRebuilt )
        _Msg(a1: " updated '%s'\n", pchWavFilea);
    }
    *((_BYTE *)this->m_pMasterSoundCache + 84) |= 1u;
    v8 = this->m_pMasterSoundCache;
    if ( (*((_BYTE *)v8 + 84) & 8) != 0 )
      CUtlCachedFileData<CAudioSourceCachedInfo>::Save(this: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043AD0
// Name: public: bool CAudioSourceCache::UpdateMasterPrecachedSoundsCache(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioSourceCache::UpdateMasterPrecachedSoundsCache(CAudioSourceCache *this)
{
  void (*v2)(const char *, ...); // edi
  const char *v3; // eax
  int v4; // ebx
  CSfxTable *v5; // eax
  CSfxTable *v6; // edi
  int v7; // ecx
  double v8; // st7
  UtlRBTreeNode_t<void *,int> *m_pMemory; // eax
  char soundname[512]; // [esp+20h] [ebp-22Ch] BYREF
  float flStart; // [esp+220h] [ebp-2Ch]
  CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > soundsOnDisk; // [esp+224h] [ebp-28h] BYREF
  int nUpdated; // [esp+248h] [ebp-4h]

  if ( this->m_pMasterSoundCache != nullptr )
  {
    flStart = _Plat_FloatTime(a1: this);
    v2 = (void (*)(const char *, ...))_Msg;
    _Msg(a1: "Updating sound cache [%d entries]\n", this->m_pMasterSoundCache->m_Elements.m_NumElements);
    soundsOnDisk.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
    memset(&soundsOnDisk.m_Elements, 0, sizeof(soundsOnDisk.m_Elements));
    soundsOnDisk.m_Root = -1;
    soundsOnDisk.m_NumElements = 0;
    soundsOnDisk.m_FirstFree = -1;
    soundsOnDisk.m_LastAlloc.index = -1;
    soundsOnDisk.m_pElements = nullptr;
    v3 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
    CAudioSourceCache::RecursiveBuildSoundList(
      this,
      root: &soundsOnDisk,
      pLanguage: v3,
      pCurrentDir: "sound",
      pathID: "GAME");
    _Msg(a1: "Found %d sound files on disk\n", soundsOnDisk.m_NumElements);
    *((_BYTE *)this->m_pMasterSoundCache + 84) &= ~1u;
    CUtlCachedFileData<CAudioSourceCachedInfo>::ForceRecheckDiskInfo(this: this->m_pMasterSoundCache);
    nUpdated = 0;
    v4 = CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::FirstInorder(this: &soundsOnDisk);
    if ( v4 != -1 )
    {
      do
      {
        soundname[0] = 0;
        g_pFullFileSystem->String(
          this: g_pFullFileSystem,
          a2: &soundsOnDisk.m_Elements.m_pMemory[v4].m_Data,
          a3: soundname,
          a4: 512);
        g_bSoundRebuilt = false;
        v5 = S_PrecacheSound(name: &soundname[6]);
        v6 = v5;
        if ( v5 != nullptr && v5->pSource != nullptr )
        {
          CAudioSourceCachedInfo::s_CurrentType = v5->pSource->GetType(this: v5->pSource);
          CAudioSourceCachedInfo::s_pSfx = v6;
          CAudioSourceCachedInfo::s_bIsPrecacheSound = false;
          CUtlCachedFileData<CAudioSourceCachedInfo>::Get(
            this: this->m_pMasterSoundCache,
            filename: (CAudioSourceCachedInfo *)soundname);
        }
        if ( g_bSoundRebuilt )
        {
          ++nUpdated;
          _Msg(a1: " updated '%s'\n", &soundname[6]);
        }
        v4 = CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::NextInorder(
               this: &soundsOnDisk,
               i: v4);
      }
      while ( v4 != -1 );
      v2 = (void (*)(const char *, ...))_Msg;
    }
    *((_BYTE *)this->m_pMasterSoundCache + 84) |= 1u;
    CUtlCachedFileData<CAudioSourceCachedInfo>::Save(this: this->m_pMasterSoundCache);
    v8 = _Plat_FloatTime(a1: v7);
    v2(
      a1: "Updated %i out of %i cached files [%.3f msec]\n",
      nUpdated,
      soundsOnDisk.m_NumElements,
      (v8 - flStart) * 1000.0);
    ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::RemoveAll(this: &soundsOnDisk);
    m_pMemory = soundsOnDisk.m_Elements.m_pMemory;
    soundsOnDisk.m_FirstFree = -1;
    if ( soundsOnDisk.m_Elements.m_nGrowSize >= 0 )
    {
      if ( soundsOnDisk.m_Elements.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: soundsOnDisk.m_Elements.m_pMemory);
        m_pMemory = nullptr;
        soundsOnDisk.m_Elements.m_pMemory = nullptr;
      }
      soundsOnDisk.m_Elements.m_nAllocationCount = 0;
    }
    soundsOnDisk.m_LastAlloc.index = -1;
    if ( soundsOnDisk.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10043CD0
// Name: private: void CAudioSourceCache::PrefetchCommandSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceCache::PrefetchCommandSounds(CAudioSourceCache *this)
{
  unsigned __int8 *m_Size; // edi
  CUtlString *m_pMemory; // ebx
  unsigned __int8 *v3; // esi
  CUtlString *v4; // esi
  int v5; // ecx
  CAudioSourceCache *v6; // ecx
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // edi
  __int16 v8; // bx
  int v9; // esi
  int v10; // edi
  CUtlString *v11; // ebx
  const char *v12; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *v13; // eax
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *v14; // ecx
  CAudioSourceCachedInfo **v15; // eax
  int m_NumElements; // edx
  int m_nActualLength; // kr00_4
  const char *v18; // eax
  float value; // [esp+28h] [ebp-28Ch]
  double v20; // [esp+34h] [ebp-280h]
  characterset_t breakSet; // [esp+48h] [ebp-26Ch] BYREF
  char szFile[260]; // [esp+148h] [ebp-16Ch] BYREF
  CUtlBuffer buf; // [esp+24Ch] [ebp-68h] BYREF
  int m_nGrowSize; // [esp+27Ch] [ebp-38h]
  int v25; // [esp+280h] [ebp-34h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vecSearch; // [esp+284h] [ebp-30h] BYREF
  int i; // [esp+298h] [ebp-1Ch]
  CUtlString v28; // [esp+29Ch] [ebp-18h] BYREF
  CAudioSourceCache *flEnd; // [esp+2ACh] [ebp-8h]
  unsigned int uSoundsPrefetched; // [esp+2B0h] [ebp-4h]

  m_Size = nullptr;
  flEnd = this;
  if ( this->m_pMasterSoundCache == nullptr )
    return;
  m_pMemory = nullptr;
  memset(&vecSearch, 0, sizeof(vecSearch));
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: "scripts/sound_prefetch.txt",
         a3: "GAME",
         a4: &buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: defaultValue);
    if ( CUtlBuffer::ParseToken(this: &buf, pBreaks: &breakSet, pTokenBuf: szFile, nMaxLen: 260, bParseComments: true) > 0 )
    {
      do
      {
        V_FixSlashes(pname: szFile, separator: 92);
        _V_strlower(start: szFile);
        uSoundsPrefetched = (unsigned int)CUtlString::CUtlString(this: &v28, pString: szFile);
        v3 = m_Size;
        if ( (int)(m_Size + 1) > vecSearch.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CPortalRect,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&vecSearch,
            num: (int)&m_Size[-vecSearch.m_Memory.m_nAllocationCount + 1]);
          m_Size = (unsigned __int8 *)vecSearch.m_Size;
          m_pMemory = vecSearch.m_Memory.m_pMemory;
        }
        vecSearch.m_Size = (int)++m_Size;
        vecSearch.m_pElements = m_pMemory;
        if ( m_Size - v3 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[(int)v3 + 1], src: &m_pMemory[(_DWORD)v3], count: 16 * (m_Size - v3 - 1));
        v4 = &m_pMemory[(_DWORD)v3];
        if ( v4 != nullptr )
          CUtlString::CUtlString(this: v4, string: (const CUtlString *)uSoundsPrefetched);
        v28.m_Storage.m_nActualLength = 0;
        if ( v28.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v28.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28.m_Storage.m_Memory.m_pMemory);
            v28.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v28.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        _Msg(a1: "Prefetching data for subdir:  %s\n", szFile);
      }
      while ( CUtlBuffer::ParseToken(
                this: &buf,
                pBreaks: &breakSet,
                pTokenBuf: szFile,
                nMaxLen: 260,
                bParseComments: true) > 0 );
      if ( m_Size != nullptr )
      {
        _COM_TimestampedLog(a1: "PrefetchSounds Start");
        *(float *)&v25 = _Plat_FloatTime(a1: v5);
        v6 = flEnd;
        m_pMasterSoundCache = flEnd->m_pMasterSoundCache;
        v28.m_Storage.m_Memory.m_nGrowSize = 0;
        v28.m_Storage.m_nActualLength = 0;
        uSoundsPrefetched = 0;
        i = 0;
        if ( m_pMasterSoundCache->m_Elements.m_NumElements != 0 )
        {
          do
          {
            v8 = i;
            v9 = (unsigned __int16)i;
            szFile[0] = 0;
            if ( (unsigned __int16)i < m_pMasterSoundCache->m_Elements.m_Elements.m_nAllocationCount
              && (unsigned __int16)i <= m_pMasterSoundCache->m_Elements.m_LastAlloc.index
              && CUtlRBTree<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short,bool (__cdecl *)(CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &,CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t const &),CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short>>::LeftChild(
                   this: &m_pMasterSoundCache->m_Elements,
                   i) != v8 )
            {
              g_pFullFileSystem->String(
                this: g_pFullFileSystem,
                a2: (void *const *)&m_pMasterSoundCache->m_Elements.m_Elements.m_pMemory[v9].m_Data,
                a3: szFile,
                a4: 260);
            }
            V_FixSlashes(pname: szFile, separator: 92);
            _V_strlower(start: szFile);
            v10 = 0;
            if ( vecSearch.m_Size > 0 )
            {
              v11 = vecSearch.m_Memory.m_pMemory;
              while ( 1 )
              {
                v12 = CUtlString::operator char const *(this: v11);
                if ( V_stristr(pStr: szFile, pSearch: v12) != nullptr )
                  break;
                ++v10;
                ++v11;
                if ( v10 >= vecSearch.m_Size )
                  goto LABEL_31;
              }
              v13 = flEnd->m_pMasterSoundCache;
              v14 = v13->m_Elements.m_Elements.m_pMemory;
              v15 = v13->m_Data.m_Memory.m_pMemory;
              ++uSoundsPrefetched;
              *(_QWORD *)&v28.m_Storage.m_Memory.m_nGrowSize += v15[v14[v9].m_Data.dataIndex]->m_dataSize;
              S_PrefetchSound(name: szFile, bPlayOnce: false);
            }
LABEL_31:
            v6 = flEnd;
            m_pMasterSoundCache = flEnd->m_pMasterSoundCache;
            m_NumElements = m_pMasterSoundCache->m_Elements.m_NumElements;
            ++i;
          }
          while ( i < m_NumElements );
        }
        *(float *)&flEnd = _Plat_FloatTime(a1: v6);
        _COM_TimestampedLog(a1: "PrefetchSounds Finish");
        m_nGrowSize = v28.m_Storage.m_Memory.m_nGrowSize;
        v20 = (*(float *)&flEnd - *(float *)&v25) * 1000.0;
        m_nActualLength = v28.m_Storage.m_nActualLength;
        v25 = v28.m_Storage.m_nActualLength & 0x7FFFFFFF;
        *(_QWORD *)&v28.m_Storage.m_Memory.m_nGrowSize &= 0x8000000000000000uLL;
        value = (float)__PAIR64__(m_nActualLength, m_nGrowSize);
        v18 = V_pretifymem(value, digitsafterdecimal: 2, usebinaryonek: false);
        _Msg(a1: "Prefetched %u sounds, %s [%.3f msec]\n", uSoundsPrefetched, v18, v20);
        if ( buf.m_Memory.m_nGrowSize >= 0 )
        {
          if ( buf.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
            buf.m_Memory.m_pMemory = nullptr;
          }
          buf.m_Memory.m_nAllocationCount = 0;
        }
        goto LABEL_36;
      }
    }
  }
  if ( buf.m_Memory.m_nGrowSize < (int)m_Size )
  {
LABEL_36:
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecSearch);
    return;
  }
  if ( buf.m_Memory.m_pMemory != m_Size )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    buf.m_Memory.m_pMemory = m_Size;
  }
  buf.m_Memory.m_nAllocationCount = (int)m_Size;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecSearch);
}

//------------------------------------------------------------------------------
// Address: 0x10044070
// Name: snd_updateaudiocache
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_updateaudiocache()
{
  CAudioSourceCache::UpdateMasterPrecachedSoundsCache(this: &g_ASCache);
}

//------------------------------------------------------------------------------
// Address: 0x10044080
// Name: void S_ValidateSoundCache(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_ValidateSoundCache(CAudioSourceCachedInfo *pchWavFile)
{
  CAudioSourceCache::ValidateSoundCache(this: &g_ASCache, pchWavFile);
}

//------------------------------------------------------------------------------
// Address: 0x100440A0
// Name: public: bool CUtlCachedFileData<class CAudioSourceCachedInfo>::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlCachedFileData<CAudioSourceCachedInfo>::Init(CUtlCachedFileData<CAudioSourceCachedInfo> *this)
{
  char v2; // al
  int (*m_pfnMetaChecksum)(void); // eax
  unsigned int v5; // eax
  const char *v6; // eax
  void *v7; // edi
  char v8; // al
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  int fileTime; // [esp+4h] [ebp-Ch]
  void *fh; // [esp+8h] [ebp-8h] BYREF
  bool deletefile; // [esp+Fh] [ebp-1h] BYREF

  v2 = *((_BYTE *)this + 84);
  if ( (v2 & 0x10) != 0 )
    return 1;
  *((_BYTE *)this + 84) = v2 | 0x10;
  if ( CUtlString::Length(this: &this->m_sRepositoryFileName) == 0 )
  {
    _Error(a1: "CUtlCachedFileData:  Can't Init, no repository file specified.");
    return 0;
  }
  m_pfnMetaChecksum = (int (*)(void))this->m_pfnMetaChecksum;
  if ( m_pfnMetaChecksum != nullptr )
    v5 = m_pfnMetaChecksum();
  else
    v5 = 0;
  this->m_uCurrentMetaChecksum = v5;
  v6 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
  v7 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6, a3: "rb", a4: "MOD");
  fh = v7;
  if ( v7 != nullptr )
  {
    v9 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
    fileTime = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: v9, a3: "MOD");
    v10 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v7);
    deletefile = false;
    if ( v10 <= 0x100000 )
      CUtlCachedFileData<CAudioSourceCachedInfo>::InitSmallBuffer(this, &fh, fileSize: v10, deleteFile: &deletefile);
    else
      CUtlCachedFileData<CAudioSourceCachedInfo>::InitLargeBuffer(this, &fh, deleteFile: &deletefile);
    if ( deletefile && (*((_BYTE *)this + 84) & 2) == 0 )
    {
      v11 = CUtlString::operator char const *(this: &this->m_sRepositoryFileName);
      g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: v11, a3: "MOD");
      *((_BYTE *)this + 84) |= 8u;
    }
    CUtlCachedFileData<CAudioSourceCachedInfo>::CheckDiskInfo(this, forcerebuild: false, cacheFileTime: fileTime);
  }
  else
  {
    v8 = *((_BYTE *)this + 84);
    if ( (v8 & 2) == 0 )
    {
      *((_BYTE *)this + 84) = v8 | 8;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100441D0
// Name: private: bool CAudioSourceCache::LoadMasterCache(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioSourceCache::LoadMasterCache(CAudioSourceCache *this, const char *pchLanguage, bool bAllowEmpty)
{
  CFmtStrN<256> *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  CFmtStrN<256> *v7; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *v8; // ebx
  const char *v10; // eax
  const char *v11; // [esp-4h] [ebp-224h]
  CFmtStrN<256> v12; // [esp+Ch] [ebp-214h] BYREF
  char fullpath[260]; // [esp+118h] [ebp-108h] BYREF
  CUtlCachedFileData<CAudioSourceCachedInfo> *v14; // [esp+21Ch] [ebp-4h]
  const char *pchLanguagea; // [esp+228h] [ebp+8h]

  v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v12, pszFormat: "%s/_master%s.cache", "maps/soundcache", pchLanguage);
  CUtlString::operator=(this: &this->m_szMasterCache, src: v4->m_szBuf);
  v11 = CUtlString::operator char const *(this: &this->m_szMasterCache);
  v5 = CUtlString::operator char const *(this: &this->m_szMODPath);
  V_snprintf(pDest: fullpath, maxLen: 260, pFormat: "%s%s", v5, v11);
  V_FixSlashes(pname: fullpath, separator: 47);
  _V_strlower(start: fullpath);
  _DevMsg(a1: 1, a2: "Trying cache :  '%s'\n", fullpath);
  pchLanguagea = CUtlString::operator char const *(this: &this->m_szMasterCache);
  v14 = (CUtlCachedFileData<CAudioSourceCachedInfo> *)MemAlloc_Alloc(nSize: 0x58u);
  if ( v14 != nullptr )
  {
    v6 = CUtlString::operator char const *(this: &this->m_szMODPath);
    v7 = CFmtStrN<256>::CFmtStrN<256>(this: &v12, pszFormat: "%s%s", v6, pchLanguagea);
    v8 = CUtlCachedFileData<CAudioSourceCachedInfo>::CUtlCachedFileData<CAudioSourceCachedInfo>(
           this: v14,
           repositoryFileName: v7->m_szBuf,
           version: 3,
           checksumfunc: nullptr,
           fileCheckType: UTL_CACHED_FILE_USE_FILESIZE,
           nevercheckdisk: true,
           readonly: false,
           savemanifest: false);
  }
  else
  {
    v8 = nullptr;
  }
  if ( CUtlCachedFileData<CAudioSourceCachedInfo>::Init(this: v8) != 0
    && (bAllowEmpty || v8->m_Elements.m_NumElements != 0) )
  {
    _DevMsg(a1: 1, a2: "Successfully loaded audio cache file\n");
    if ( this->m_pMasterSoundCache != v8 )
    {
      this->m_pMasterSoundCache = v8;
      ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
    return 1;
  }
  else
  {
    v10 = CUtlString::operator char const *(this: &this->m_szMasterCache);
    _Warning(a1: "Failed to init '%s'\n", v10);
    CUtlString::operator=(this: &this->m_szMasterCache, src: defaultValue);
    if ( v8 != nullptr )
      ((void (__thiscall *)(CUtlCachedFileData<CAudioSourceCachedInfo> *, int))v8->dtr_CUtlCachedFileData<CAudioSourceCachedInfo>)(
        a1: v8,
        a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044340
// Name: private: class CUtlCachedFileData<class CAudioSourceCachedInfo> __near * CAudioSourceCache::BuildCacheFromList(char const __near *,class CUtlRBTree<void __near *,int,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,int>,int>> __near &,bool,float,float)
// Source: json
//------------------------------------------------------------------------------
CUtlCachedFileData<CAudioSourceCachedInfo> *__thiscall CAudioSourceCache::BuildCacheFromList(
        CAudioSourceCache *this,
        const char *cachename,
        CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *soundlist,
        bool showprogress,
        float flProgressStart,
        float flProgressEnd)
{
  CAudioSourceCache *v6; // esi
  int v7; // ebx
  CUtlCachedFileData<CAudioSourceCachedInfo> *v8; // edi
  int v9; // ecx
  int Inorder; // eax
  void **p_m_Data; // eax
  CSfxTable *v12; // eax
  CAudioSourceCache_vtbl *v13; // esi
  int v14; // eax
  int m_NumElements; // esi
  double v16; // st7
  float v18; // [esp+18h] [ebp-320h]
  char soundname[512]; // [esp+2Ch] [ebp-30Ch] BYREF
  char base[256]; // [esp+22Ch] [ebp-10Ch] BYREF
  float flStart; // [esp+32Ch] [ebp-Ch]
  CUtlCachedFileData<CAudioSourceCachedInfo> *newCache; // [esp+330h] [ebp-8h]
  CAudioSourceCache *v23; // [esp+334h] [ebp-4h]
  int i; // [esp+340h] [ebp+8h]

  v6 = this;
  v23 = this;
  flStart = _Plat_FloatTime(a1: this);
  v7 = 0;
  v8 = CAudioSourceCache::AllocAudioCache(this: v6, cachename, bNeverCheckDisk: false);
  newCache = v8;
  if ( CUtlCachedFileData<CAudioSourceCachedInfo>::Init(this: v8) != 0 )
  {
    if ( v6->m_pBuildingCache != v8 )
    {
      v6->m_pBuildingCache = v8;
      ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
    Inorder = CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::FirstInorder(this: soundlist);
    i = Inorder;
    if ( Inorder != -1 )
    {
      while ( 1 )
      {
        p_m_Data = &soundlist->m_Elements.m_pMemory[Inorder].m_Data;
        soundname[0] = 0;
        if ( g_pFullFileSystem->String(this: g_pFullFileSystem, a2: p_m_Data, a3: soundname, a4: 512) )
        {
          v12 = S_PrecacheSound(name: &soundname[6]);
          if ( v12 != nullptr && v12->pSource != nullptr )
          {
            v13 = v23->__vftable;
            v14 = ((int (__thiscall *)(CAudioSource *, _DWORD, CSfxTable *))v12->pSource->GetType)(
                    a1: v12->pSource,
                    a2: 0,
                    a3: v12);
            ((void (__thiscall *)(CAudioSourceCache *, int))v13->GetInfo)(a1: v23, a2: v14);
          }
        }
        if ( ++v7 % 100 == 0 )
          _Msg(
            a1: "  progress %i/%i (%i %%)\n",
            v7,
            soundlist->m_NumElements,
            (int)((double)v7 * 100.0 / (double)(unsigned int)soundlist->m_NumElements));
        if ( showprogress )
        {
          m_NumElements = soundlist->m_NumElements;
          V_FileBase(in: soundname, out: base, maxlen: 256);
          _V_strlower(start: base);
          v18 = flProgressStart
              + (flProgressEnd - flProgressStart) * ((double)(v7 - 1) / (double)(unsigned int)m_NumElements);
          ((void (__stdcall *)(_DWORD, char *))g_pSoundServices->CacheBuildingUpdateProgress)(
            a1: LODWORD(v18),
            a2: base);
        }
        i = CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::NextInorder(
              this: soundlist,
              i);
        if ( i == -1 )
          break;
        Inorder = i;
      }
      v6 = v23;
    }
    _Msg(a1: "Touched %i cached files\n", soundlist->m_NumElements);
    if ( v6->m_pBuildingCache != nullptr )
    {
      v6->m_pBuildingCache = nullptr;
      ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
    CUtlCachedFileData<CAudioSourceCachedInfo>::Save(this: newCache);
  }
  else
  {
    if ( v8 != nullptr )
      ((void (__thiscall *)(CUtlCachedFileData<CAudioSourceCachedInfo> *, int))v8->dtr_CUtlCachedFileData<CAudioSourceCachedInfo>)(
        a1: v8,
        a2: 1);
    newCache = nullptr;
  }
  v16 = _Plat_FloatTime(a1: v9);
  _Msg(a1: "Elapsed time:  %.2f seconds\n", v16 - flStart);
  return newCache;
}

//------------------------------------------------------------------------------
// Address: 0x10044560
// Name: public: bool CAudioSourceCache::BuildMasterPrecachedSoundsCache(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioSourceCache::BuildMasterPrecachedSoundsCache(CAudioSourceCache *this)
{
  const char *v2; // eax
  const char *v3; // eax
  CUtlCachedFileData<CAudioSourceCachedInfo> *v4; // edi
  CUtlCachedFileData<CAudioSourceCachedInfo> *m_pMasterSoundCache; // ecx
  char fn[512]; // [esp+14h] [ebp-224h] BYREF
  CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > other; // [esp+214h] [ebp-24h] BYREF

  v2 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
  V_snprintf(pDest: fn, maxLen: 512, pFormat: "%s/%s%s.cache", "maps/soundcache", "_master", v2);
  _DevMsg(a1: 1, a2: "Fast Build Temp Cache:  '%s'\n", fn);
  CAudioSourceCache::RemoveCache(this, cachename: fn);
  g_pSoundServices->CacheBuildingStart(this: g_pSoundServices);
  other.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
  memset(&other.m_Elements, 0, sizeof(other.m_Elements));
  other.m_Root = -1;
  other.m_NumElements = 0;
  other.m_FirstFree = -1;
  other.m_LastAlloc.index = -1;
  other.m_pElements = nullptr;
  v3 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
  CAudioSourceCache::RecursiveBuildSoundList(this, root: &other, pLanguage: v3, pCurrentDir: "sound", pathID: "GAME");
  v4 = CAudioSourceCache::BuildCacheFromList(
         this,
         cachename: fn,
         soundlist: &other,
         showprogress: true,
         flProgressStart: 0.0,
         flProgressEnd: 1.0);
  if ( v4 != nullptr )
  {
    m_pMasterSoundCache = this->m_pMasterSoundCache;
    if ( m_pMasterSoundCache != nullptr )
      ((void (__thiscall *)(CUtlCachedFileData<CAudioSourceCachedInfo> *, int))m_pMasterSoundCache->dtr_CUtlCachedFileData<CAudioSourceCachedInfo>)(
        a1: m_pMasterSoundCache,
        a2: 1);
    if ( this->m_pMasterSoundCache != v4 )
    {
      this->m_pMasterSoundCache = v4;
      ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
  }
  g_pSoundServices->CacheBuildingFinish(this: g_pSoundServices);
  CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::~CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>(this: &other);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10044670
// Name: snd_rebuildaudiocache
// Source: json
//------------------------------------------------------------------------------
void __cdecl snd_rebuildaudiocache()
{
  CAudioSourceCache::BuildMasterPrecachedSoundsCache(this: &g_ASCache);
}

//------------------------------------------------------------------------------
// Address: 0x10044680
// Name: public: virtual bool CAudioSourceCache::Init(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioSourceCache::Init(CAudioSourceCache *this, unsigned int memSize)
{
  const char *v4; // eax
  const char *v5; // eax
  int v6; // eax
  CFmtStrN<256> *v7; // eax
  const char *v8; // eax
  CFmtStrN<256> *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int v13; // eax
  int v14; // eax
  CFmtStrN<256> v15; // [esp+4h] [ebp-210h] BYREF
  char sz[260]; // [esp+110h] [ebp-104h] BYREF

  if ( wavedatacache->Init(this: wavedatacache, a2: memSize) != 0 )
  {
    CAudioSourceCache::GetAudioCacheLanguageSuffix(this, sLanguage: &this->m_szCurrentLanguage);
    if ( CUtlString::Length(this: &this->m_szCurrentLanguage) > 0 )
    {
      v4 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
      _DevMsg(a1: 1, a2: "Audio Caches using '%s' as suffix\n", v4);
    }
    v5 = g_pSoundServices->GetGameDir(this: g_pSoundServices);
    V_strncpy(pDest: sz, pSrc: v5, maxLen: 260);
    V_StripTrailingSlash(ppath: sz);
    v6 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-tempcontent") != 0 )
      V_strncat(pDest: sz, pSrc: "_tempcontent", destBufferSize: 0x104u, max_chars_to_copy: -1);
    V_FixSlashes(pname: sz, separator: 92);
    _V_strlower(start: sz);
    CUtlString::operator=(this: &this->m_szMODPath, src: sz);
    v7 = CFmtStrN<256>::CFmtStrN<256>(this: &v15, pszFormat: "%c", 92);
    CUtlString::operator+=(this: &this->m_szMODPath, rhs: v7->m_szBuf);
    v8 = CUtlString::operator char const *(this: &this->m_szMODPath);
    v9 = CFmtStrN<256>::CFmtStrN<256>(this: &v15, pszFormat: "%s%s", v8, "maps/soundcache");
    g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: v9->m_szBuf, a3: "GAME");
    if ( this->m_pMasterSoundCache != nullptr )
    {
      this->m_pMasterSoundCache = nullptr;
      ++CAudioSourceCachedInfoHandle_t::s_nCurrentFlushCount;
    }
    v10 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
    if ( CAudioSourceCache::LoadMasterCache(this, pchLanguage: v10, bAllowEmpty: false) != 0
      || (v11 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage),
          _V_stricmp(s1: v11, s2: defaultValue) != 0)
      && CAudioSourceCache::LoadMasterCache(this, pchLanguage: defaultValue, bAllowEmpty: true) != 0 )
    {
      v13 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: "-tools") != 0 )
      {
        v14 = _CommandLine();
        if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: "-norebuildaudiocache") == 0 )
          CAudioSourceCache::UpdateMasterPrecachedSoundsCache(this);
      }
    }
    else
    {
      v12 = CUtlString::operator char const *(this: &this->m_szCurrentLanguage);
      _Warning(a1: "  .cache load failed, forcing rebuild [lang:%s]!\n", v12);
      CAudioSourceCache::BuildMasterPrecachedSoundsCache(this);
    }
    if ( snd_prefetch_common.m_pParent != nullptr && snd_prefetch_common.m_pParent->m_Value.m_nValue != 0 )
      CAudioSourceCache::PrefetchCommandSounds(this);
    return 1;
  }
  else
  {
    _Error(a1: "Unable to init wavedatacache system\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057460
// Name: public: virtual int CAudioSourceWave::ZeroCrossingBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceWave::ZeroCrossingBefore(CAudioSourceMP3 *this, int sample)
{
  return sample;
}

//------------------------------------------------------------------------------
// Address: 0x10285560
// Name: public: virtual int CAudioSourceWave::SampleCount(void)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall CAudioSourceWave::SampleCount(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

} // namespace engine_xlsp
