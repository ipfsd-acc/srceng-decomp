// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/localization_check/faceposersound_simple.cpp
// Functions: 35
// ============================================================

#include "utils\localization_check\faceposersound_simple.h"

//------------------------------------------------------------------------------
// Address: 0x00403110
// Name: public: virtual void CAudioDeviceSWMix::Mix8Mono(struct channel_s __near *,char __near *,int,int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceSWMix::Mix8Mono(
        CAudioDeviceSWMix *this,
        channel_s *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        int rateScaleFix,
        int outCount,
        int timecompress,
        bool forward)
{
  int v10; // edx
  int v11; // edi
  channel_s *v12; // ecx
  int v13; // esi
  BOOL v14; // ebx
  int v15; // eax
  int v16; // esi
  int fixupstep; // [esp+20h] [ebp+14h]
  int forwarda; // [esp+30h] [ebp+24h]

  v10 = 0;
  v11 = 0;
  fixupstep = 1;
  if ( !forward )
  {
    v11 = outCount - 1;
    fixupstep = -1;
  }
  if ( outCount > 0 )
  {
    v12 = pChannel;
    for ( forwarda = outCount; forwarda != 0; --forwarda )
    {
      v13 = v11 + outputOffset;
      v14 = v11 + outputOffset <= 0;
      v15 = rateScaleFix + inputOffset;
      v11 += fixupstep;
      v16 = v14 ? 0 : v13;
      this->m_paintbuffer[v16].left += v12->leftvol * pData[v10];
      v12 = pChannel;
      this->m_paintbuffer[v16].right += pChannel->rightvol * pData[v10];
      v10 += v15 >> 28;
      inputOffset = v15 & 0xFFFFFFF;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004031A0
// Name: public: virtual void CAudioDeviceSWMix::Mix8Stereo(struct channel_s __near *,char __near *,int,int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceSWMix::Mix8Stereo(
        CAudioDeviceSWMix *this,
        channel_s *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        int rateScaleFix,
        int outCount,
        int timecompress,
        bool forward)
{
  int v10; // edx
  int v11; // edi
  channel_s *v12; // ecx
  int v13; // esi
  BOOL v14; // ebx
  int v15; // eax
  int v16; // esi
  int fixupstep; // [esp+20h] [ebp+14h]
  int forwarda; // [esp+30h] [ebp+24h]

  v10 = 0;
  v11 = 0;
  fixupstep = 1;
  if ( !forward )
  {
    v11 = outCount - 1;
    fixupstep = -1;
  }
  if ( outCount > 0 )
  {
    v12 = pChannel;
    for ( forwarda = outCount; forwarda != 0; --forwarda )
    {
      v13 = v11 + outputOffset;
      v14 = v11 + outputOffset <= 0;
      v15 = rateScaleFix + inputOffset;
      v11 += fixupstep;
      v16 = v14 ? 0 : v13;
      this->m_paintbuffer[v16].left += v12->leftvol * pData[v10];
      v12 = pChannel;
      this->m_paintbuffer[v16].right += pChannel->rightvol * pData[v10 + 1];
      v10 += (v15 >> 27) & 0xFFFFFFFE;
      inputOffset = v15 & 0xFFFFFFF;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403230
// Name: public: virtual void CAudioDeviceSWMix::Mix16Mono(struct channel_s __near *,short __near *,int,int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceSWMix::Mix16Mono(
        CAudioDeviceSWMix *this,
        channel_s *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        int rateScaleFix,
        int outCount,
        int timecompress,
        bool forward)
{
  int v10; // edx
  int v11; // edi
  channel_s *v12; // ecx
  int v13; // esi
  BOOL v14; // ebx
  int v15; // eax
  int v16; // esi
  int fixupstep; // [esp+20h] [ebp+14h]
  int forwarda; // [esp+30h] [ebp+24h]

  v10 = 0;
  v11 = 0;
  fixupstep = 1;
  if ( !forward )
  {
    v11 = outCount - 1;
    fixupstep = -1;
  }
  if ( outCount > 0 )
  {
    v12 = pChannel;
    for ( forwarda = outCount; forwarda != 0; --forwarda )
    {
      v13 = v11 + outputOffset;
      v14 = v11 + outputOffset <= 0;
      v15 = rateScaleFix + inputOffset;
      v11 += fixupstep;
      v16 = v14 ? 0 : v13;
      this->m_paintbuffer[v16].left += (v12->leftvol * pData[v10]) >> 8;
      v12 = pChannel;
      this->m_paintbuffer[v16].right += (pChannel->rightvol * pData[v10]) >> 8;
      v10 += v15 >> 28;
      inputOffset = v15 & 0xFFFFFFF;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004032C0
// Name: public: virtual void CAudioDeviceSWMix::Mix16Stereo(struct channel_s __near *,short __near *,int,int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceSWMix::Mix16Stereo(
        CAudioDeviceSWMix *this,
        channel_s *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        int rateScaleFix,
        int outCount,
        int timecompress,
        bool forward)
{
  int v10; // edx
  int v11; // edi
  channel_s *v12; // ecx
  int v13; // esi
  BOOL v14; // ebx
  int v15; // eax
  int v16; // esi
  int fixupstep; // [esp+20h] [ebp+14h]
  int forwarda; // [esp+30h] [ebp+24h]

  v10 = 0;
  v11 = 0;
  fixupstep = 1;
  if ( !forward )
  {
    v11 = outCount - 1;
    fixupstep = -1;
  }
  if ( outCount > 0 )
  {
    v12 = pChannel;
    for ( forwarda = outCount; forwarda != 0; --forwarda )
    {
      v13 = v11 + outputOffset;
      v14 = v11 + outputOffset <= 0;
      v15 = rateScaleFix + inputOffset;
      v11 += fixupstep;
      v16 = v14 ? 0 : v13;
      this->m_paintbuffer[v16].left += (v12->leftvol * pData[v10]) >> 8;
      v12 = pChannel;
      this->m_paintbuffer[v16].right += (pChannel->rightvol * pData[v10 + 1]) >> 8;
      v10 += (v15 >> 27) & 0xFFFFFFFE;
      inputOffset = v15 & 0xFFFFFFF;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403360
// Name: public: virtual int CAudioDeviceSWMix::MaxSampleCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDeviceSWMix::MaxSampleCount(CAudioDeviceSWMix *this)
{
  return 1024;
}

//------------------------------------------------------------------------------
// Address: 0x00403370
// Name: public: virtual void CAudioDeviceSWMix::MixBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceSWMix::MixBegin(CAudioDeviceSWMix *this)
{
  memset(dst: (unsigned __int8 *)this->m_paintbuffer, value: 0, count: sizeof(this->m_paintbuffer));
}

//------------------------------------------------------------------------------
// Address: 0x00403390
// Name: public: void CAudioDeviceSWMix::TransferBufferStereo16(short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceSWMix::TransferBufferStereo16(CAudioDeviceSWMix *this, __int16 *pOutput, int sampleCount)
{
  int *p_right; // eax
  int i; // esi
  int v6; // edx

  if ( sampleCount > 0 )
  {
    p_right = &this->m_paintbuffer[0].right;
    for ( i = sampleCount; i != 0; --i )
    {
      v6 = *(p_right - 1);
      if ( v6 <= 0x7FFF )
      {
        if ( v6 < -32768 )
          *(p_right - 1) = -32768;
      }
      else
      {
        *(p_right - 1) = 0x7FFF;
      }
      if ( *p_right <= 0x7FFF )
      {
        if ( *p_right < -32768 )
          *p_right = -32768;
      }
      else
      {
        *p_right = 0x7FFF;
      }
      *pOutput = *((_WORD *)p_right - 2);
      pOutput[1] = *(_WORD *)p_right;
      pOutput += 2;
      p_right += 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403410
// Name: public: virtual void CAudioWaveOutput::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::Flush(CAudioWaveOutput *this)
{
  waveOutReset(hwo: this->m_deviceHandle);
}

//------------------------------------------------------------------------------
// Address: 0x00403420
// Name: public: virtual void CFacePoserSound::StopSound(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::StopSound(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00403430
// Name: private: void CAudioWaveOutput::ComputeSampleAheadAmount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::ComputeSampleAheadAmount(CAudioWaveOutput *this)
{
  int v2; // ecx
  int v3; // edi
  int v4; // edx
  int *p_submit_sample_count; // eax

  v2 = 0;
  v3 = -1;
  this->m_nEstimatedSamplesAhead = 0;
  if ( this->m_deviceHandle != nullptr )
  {
    v4 = 2;
    p_submit_sample_count = &this->m_buffers[0].submit_sample_count;
    do
    {
      if ( *((_BYTE *)p_submit_sample_count - 4) != 0
        && (*(_BYTE *)(*(p_submit_sample_count - 2) + 16) & 1) == 0
        && *p_submit_sample_count > v2 )
      {
        v3 = v4 - 2;
        v2 = *p_submit_sample_count;
      }
      if ( *((_BYTE *)p_submit_sample_count + 28) != 0
        && (*(_BYTE *)(p_submit_sample_count[6] + 16) & 1) == 0
        && p_submit_sample_count[8] > v2 )
      {
        v3 = v4 - 1;
        v2 = p_submit_sample_count[8];
      }
      if ( *((_BYTE *)p_submit_sample_count + 60) != 0
        && (*(_BYTE *)(p_submit_sample_count[14] + 16) & 1) == 0
        && p_submit_sample_count[16] > v2 )
      {
        v3 = v4;
        v2 = p_submit_sample_count[16];
      }
      if ( *((_BYTE *)p_submit_sample_count + 92) != 0
        && (*(_BYTE *)(p_submit_sample_count[22] + 16) & 1) == 0
        && p_submit_sample_count[24] > v2 )
      {
        v3 = v4 + 1;
        v2 = p_submit_sample_count[24];
      }
      v4 += 4;
      p_submit_sample_count += 32;
    }
    while ( v4 - 2 < 32 );
    if ( v3 != -1 )
      this->m_nEstimatedSamplesAhead = this->GetOutputPosition(this) - this->m_buffers[v3].submit_sample_count;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004034F0
// Name: public: virtual int CAudioWaveOutput::FindSourceIndex(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioWaveOutput::FindSourceIndex(CAudioWaveOutput *this, CAudioMixer *pSource)
{
  int result; // eax
  CAudioMixer **i; // ecx

  result = 0;
  for ( i = this->m_sourceList; pSource != *i; ++i )
  {
    if ( ++result >= 16 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403520
// Name: public: virtual class CAudioMixer __near * CAudioWaveOutput::GetMixerForSource(class CAudioSource __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixer *__thiscall CAudioWaveOutput::GetMixerForSource(CAudioWaveOutput *this, CAudioSource *source)
{
  int v2; // edi
  CAudioMixer **i; // esi

  v2 = 0;
  for ( i = this->m_sourceList; *i == nullptr || source != (*i)->GetSource(this: *i); ++i )
  {
    if ( ++v2 >= 16 )
      return nullptr;
  }
  return this->m_sourceList[v2];
}

//------------------------------------------------------------------------------
// Address: 0x00403570
// Name: public: virtual void CAudioWaveOutput::StopSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::StopSounds(CAudioWaveOutput *this)
{
  int v2; // esi
  CAudioMixer **m_sourceList; // edi

  v2 = 0;
  m_sourceList = this->m_sourceList;
  do
  {
    if ( *m_sourceList != nullptr )
      this->FreeChannel(this, a2: v2);
    ++v2;
    ++m_sourceList;
  }
  while ( v2 < 16 );
}

//------------------------------------------------------------------------------
// Address: 0x004035A0
// Name: public: virtual int CAudioWaveOutput::GetOutputPosition(void)
// Source: json
//------------------------------------------------------------------------------
HWAVEOUT__ *__thiscall CAudioWaveOutput::GetOutputPosition(CAudioWaveOutput *this)
{
  HWAVEOUT__ *result; // eax
  mmtime_tag mmtime; // [esp+0h] [ebp-Ch] BYREF

  result = this->m_deviceHandle;
  if ( result != nullptr )
  {
    mmtime.wType = 2;
    waveOutGetPosition(hwo: result, pmmt: &mmtime, cbmmt: 0xCu);
    return (HWAVEOUT__ *)mmtime.u.ms;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004035D0
// Name: private: void CAudioWaveOutput::OpenDevice(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::OpenDevice(CAudioWaveOutput *this)
{
  int v1; // ebx
  HWAVEOUT__ **p_m_deviceHandle; // edi
  CAudioBuffer *i; // esi
  int v5; // eax
  tWAVEFORMATEX waveFormat; // [esp+Ch] [ebp-14h] BYREF

  v1 = 0;
  p_m_deviceHandle = &this->m_deviceHandle;
  waveFormat.cbSize = 18;
  waveFormat.nAvgBytesPerSec = 176400;
  waveFormat.nSamplesPerSec = 44100;
  *(_DWORD *)&waveFormat.nBlockAlign = 1048580;
  *(_DWORD *)&waveFormat.wFormatTag = 131073;
  if ( waveOutOpen(
         phwo: &this->m_deviceHandle,
         uDeviceID: 0xFFFFFFFF,
         pwfx: &waveFormat,
         dwCallback: 0,
         dwInstance: 0,
         fdwOpen: 0) != 0 )
  {
    *p_m_deviceHandle = nullptr;
  }
  else
  {
    for ( i = this->m_buffers; ; ++i )
    {
      i->hdr = (wavehdr_tag *)operator new(nSize: 0x20u);
      i->hdr->lpData = (char *)operator new(nSize: 0x1588u);
      v5 = (int)i->hdr->lpData & 3;
      if ( v5 != 0 )
        i->hdr->lpData = (char *)((int)(i->hdr->lpData + 3) & 0xFFFFFFFC);
      i->hdr->dwBufferLength = 5512 - v5;
      i->hdr->dwFlags = 0;
      if ( waveOutPrepareHeader(hwo: *p_m_deviceHandle, pwh: i->hdr, cbwh: 0x20u) != 0 )
        break;
      if ( ++v1 >= 32 )
        return;
    }
    *p_m_deviceHandle = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004036C0
// Name: public: virtual void CFacePoserSound::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::Shutdown(CFacePoserSound *this)
{
  CAudioOutput *m_pAudio; // ecx

  m_pAudio = this->m_pAudio;
  if ( m_pAudio != nullptr )
    ((void (__thiscall *)(CAudioOutput *, int))m_pAudio->dtr_CAudioOutput)(a1: m_pAudio, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004036D0
// Name: public: virtual float CFacePoserSound::GetAmountofTimeAhead(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFacePoserSound::GetAmountofTimeAhead(CFacePoserSound *this)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004036E0
// Name: public: virtual class CAudioSource __near * CFacePoserSound::LoadSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSource *__thiscall CFacePoserSound::LoadSound(CFacePoserSound *this, const char *wavfile)
{
  if ( this->m_pAudio != nullptr )
    return AudioSource_Create(pName: wavfile);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403700
// Name: public: virtual void CFacePoserSound::PlaySoundA(class StudioModel __near *,float,char const __near *,class CAudioMixer __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::PlaySoundA(
        CFacePoserSound *this,
        struct StudioModel *model,
        float volume,
        const char *wavfile,
        CAudioMixer **ppMixer)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00403710
// Name: public: virtual void CFacePoserSound::PlayPartialSound(class StudioModel __near *,float,char const __near *,class CAudioMixer __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::PlayPartialSound(
        CFacePoserSound *this,
        struct StudioModel *model,
        float volume,
        const char *wavfile,
        CAudioMixer **ppMixer,
        CAudioMixer **startSample,
        int endSample)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00403720
// Name: public: virtual void CFacePoserSound::PlaySoundA(class CAudioSource __near *,float,class CAudioMixer __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::PlaySoundA(
        CFacePoserSound *this,
        CAudioSource *source,
        float volume,
        CAudioMixer **ppMixer)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00403730
// Name: public: virtual void CFacePoserSound::RenderWavToDC(struct HDC__ __near *,struct tagRECT __near &,class Color const __near &,float,float,class CAudioSource __near *,bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::RenderWavToDC(
        CFacePoserSound *this,
        HDC__ *dc,
        HDC__ *outrect,
        tagRECT *clr,
        float starttime,
        float endtime,
        CAudioSource *pWave,
        bool selected,
        int selectionstart,
        int selectionend)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00403740
// Name: public: virtual class CAudioMixer __near * CFacePoserSound::FindMixer(class CAudioSource __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixer *__thiscall CFacePoserSound::FindMixer(CFacePoserSound *this, CAudioSource *source)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403750
// Name: public: virtual int CAudioWaveOutput::GetNumberofSamplesAhead(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioWaveOutput::GetNumberofSamplesAhead(CAudioWaveOutput *this)
{
  CAudioWaveOutput::ComputeSampleAheadAmount(this);
  return this->m_nEstimatedSamplesAhead;
}

//------------------------------------------------------------------------------
// Address: 0x00403760
// Name: public: virtual float CAudioWaveOutput::GetAmountofTimeAhead(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAudioWaveOutput::GetAmountofTimeAhead(CAudioWaveOutput *this)
{
  CAudioWaveOutput::ComputeSampleAheadAmount(this);
  return (double)this->m_nEstimatedSamplesAhead * 0.000022675737;
}

//------------------------------------------------------------------------------
// Address: 0x00403780
// Name: public: virtual void CAudioWaveOutput::AddSource(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::AddSource(CAudioWaveOutput *this, CAudioMixer *pSource)
{
  unsigned int v3; // edi
  int v4; // eax
  CAudioMixer **m_sourceList; // ecx

  v3 = 0;
  v4 = 0;
  m_sourceList = this->m_sourceList;
  while ( *m_sourceList != nullptr )
  {
    ++v4;
    ++m_sourceList;
    if ( v4 >= 16 )
      goto LABEL_6;
  }
  v3 = v4;
LABEL_6:
  if ( this->m_sourceList[v3] != nullptr )
    this->FreeChannel(this, a2: v3);
  if ( v3 <= 0xF )
    this->m_sourceList[v3] = pSource;
  pSource->SetActive(this: pSource, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x004037E0
// Name: private: void CAudioWaveOutput::RemoveMixerChannelReferences(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::RemoveMixerChannelReferences(CAudioWaveOutput *this, CAudioMixer *mixer)
{
  CUtlVector<CAudioMixerState,CUtlMemory<CAudioMixerState,int> > *p_m_Referenced; // esi
  int i; // edi
  int m_Size; // edx
  int v5; // eax
  CAudioMixer **p_mixer; // ecx

  p_m_Referenced = &this->m_buffers[0].m_Referenced;
  for ( i = 32; i != 0; --i )
  {
    m_Size = p_m_Referenced->m_Size;
    v5 = 0;
    if ( m_Size > 0 )
    {
      p_mixer = &p_m_Referenced->m_Memory.m_pMemory->mixer;
      while ( *p_mixer != mixer )
      {
        ++v5;
        p_mixer += 2;
        if ( v5 >= m_Size )
          goto LABEL_10;
      }
      if ( m_Size - v5 - 1 > 0 )
        _V_memmove(
          dest: &p_m_Referenced->m_Memory.m_pMemory[v5],
          src: &p_m_Referenced->m_Memory.m_pMemory[v5 + 1],
          count: 8 * (m_Size - v5 - 1));
      --p_m_Referenced->m_Size;
    }
LABEL_10:
    p_m_Referenced = (CUtlVector<CAudioMixerState,CUtlMemory<CAudioMixerState,int> > *)((char *)p_m_Referenced + 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403840
// Name: private: virtual void CAudioWaveOutput::FreeChannel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::FreeChannel(CAudioWaveOutput *this, unsigned int channelIndex)
{
  CAudioMixer *v3; // ecx

  if ( channelIndex <= 0xF && this->m_sourceList[channelIndex] != nullptr )
  {
    CAudioWaveOutput::RemoveMixerChannelReferences(this, mixer: this->m_sourceList[channelIndex]);
    v3 = this->m_sourceList[channelIndex];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CAudioMixer *, int))v3->dtr_CAudioMixer)(a1: v3, a2: 1);
    this->m_sourceList[channelIndex] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403890
// Name: public: virtual CAudioWaveOutput::~CAudioWaveOutput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::~CAudioWaveOutput(CAudioWaveOutput *this)
{
  HWAVEOUT__ *m_deviceHandle; // eax
  CAudioBuffer *m_buffers; // esi
  CAudioMixer **v4; // esi
  CAudioMixer *v5; // eax
  int i; // [esp+Ch] [ebp-4h]
  int v7; // [esp+Ch] [ebp-4h]

  m_deviceHandle = this->m_deviceHandle;
  this->__vftable = (CAudioWaveOutput_vtbl *)&CAudioWaveOutput::`vftable';
  if ( m_deviceHandle != nullptr )
  {
    waveOutReset(hwo: m_deviceHandle);
    m_buffers = this->m_buffers;
    for ( i = 32; i != 0; --i )
    {
      if ( m_buffers->hdr != nullptr )
      {
        waveOutUnprepareHeader(hwo: this->m_deviceHandle, pwh: m_buffers->hdr, cbwh: 0x20u);
        free(pMem: m_buffers->hdr->lpData);
        free(pMem: m_buffers->hdr);
      }
      m_buffers->hdr = nullptr;
      m_buffers->submitted = false;
      m_buffers->submit_sample_count = 0;
      m_buffers->m_Referenced.m_Size = 0;
      if ( m_buffers->m_Referenced.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_buffers->m_Referenced.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_buffers->m_Referenced.m_Memory.m_pMemory);
          m_buffers->m_Referenced.m_Memory.m_pMemory = nullptr;
        }
        m_buffers->m_Referenced.m_Memory.m_nAllocationCount = 0;
      }
      m_buffers->m_Referenced.m_pElements = m_buffers->m_Referenced.m_Memory.m_pMemory;
      ++m_buffers;
    }
    waveOutClose(hwo: this->m_deviceHandle);
    this->m_deviceHandle = nullptr;
  }
  v7 = 31;
  v4 = &this->m_sourceList[3];
  do
  {
    v4 -= 8;
    v4[3] = nullptr;
    if ( (int)v4[2] >= 0 )
    {
      if ( *v4 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *v4);
        *v4 = nullptr;
      }
      v4[1] = nullptr;
    }
    v5 = *v4;
    v4[4] = *v4;
    if ( (int)v4[2] >= 0 )
    {
      if ( v5 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
        *v4 = nullptr;
      }
      v4[1] = nullptr;
    }
    --v7;
  }
  while ( v7 >= 0 );
  this->__vftable = (CAudioWaveOutput_vtbl *)&CAudioOutput::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x004039A0
// Name: public: virtual int CAudioWaveOutput::SampleSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioWaveOutput::SampleSize(CAudioWaveOutput *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x004039B0
// Name: public: virtual int CAudioWaveOutput::SampleRate(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioWaveOutput::SampleRate(CAudioWaveOutput *this)
{
  return 44100;
}

//------------------------------------------------------------------------------
// Address: 0x004039D0
// Name: public: CAudioWaveOutput::CAudioWaveOutput(void)
// Source: json
//------------------------------------------------------------------------------
CAudioWaveOutput *__thiscall CAudioWaveOutput::CAudioWaveOutput(CAudioWaveOutput *this)
{
  int v2; // ecx
  int *p_m_nGrowSize; // eax
  int *p_submit_sample_count; // eax
  int i; // ecx

  this->__vftable = (CAudioWaveOutput_vtbl *)&CAudioWaveOutput::`vftable';
  v2 = 31;
  p_m_nGrowSize = &this->m_buffers[0].m_Referenced.m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 8;
    --v2;
  }
  while ( v2 >= 0 );
  this->m_audioDevice.__vftable = (CAudioDeviceSWMix_vtbl *)&CAudioDeviceSWMix::`vftable';
  p_submit_sample_count = &this->m_buffers[0].submit_sample_count;
  for ( i = 32; i != 0; --i )
  {
    *(p_submit_sample_count - 2) = 0;
    *((_BYTE *)p_submit_sample_count - 4) = 0;
    *p_submit_sample_count = 0;
    p_submit_sample_count += 8;
  }
  this->m_deviceHandle = nullptr;
  CAudioWaveOutput::OpenDevice(this);
  this->m_mixTime = -1.0;
  this->m_sampleIndex = 0;
  memset(dst: (unsigned __int8 *)this->m_sourceList, value: 0, count: sizeof(this->m_sourceList));
  this->m_nEstimatedSamplesAhead = 4410;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403A90
// Name: public: virtual void CFacePoserSound::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::Init(CFacePoserSound *this)
{
  CAudioOutput *v1; // eax
  CAudioWaveOutput *v3; // eax
  CAudioWaveOutput *v4; // eax

  v1 = (CAudioOutput *)dword_4695C8;
  if ( dword_4695C8 == 0 )
  {
    v3 = (CAudioWaveOutput *)operator new(nSize: 0x245Cu);
    if ( v3 != nullptr )
    {
      v4 = CAudioWaveOutput::CAudioWaveOutput(this: v3);
      this->m_pAudio = v4;
      dword_4695C8 = (int)v4;
      return;
    }
    v1 = nullptr;
    dword_4695C8 = 0;
  }
  this->m_pAudio = v1;
}

//------------------------------------------------------------------------------
// Address: 0x00424FC0
// Name: public: virtual bool CFacePoserSound::IsSoundPlaying(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFacePoserSound::IsSoundPlaying(CUtlBuffer *this, int nSize)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00429010
// Name: public: virtual int CFacePoserSound::GetNumberofSamplesAhead(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFacePoserSound::GetNumberofSamplesAhead(ConVar *this)
{
  return 0;
}
