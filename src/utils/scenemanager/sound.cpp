// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/sound.cpp
// Functions: 40
// ============================================================

#include "utils\scenemanager\sound.h"

//------------------------------------------------------------------------------
// Address: 0x00403D80
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
// Address: 0x00403E10
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
// Address: 0x00403EA0
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
// Address: 0x00403F30
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
// Address: 0x00403FD0
// Name: public: virtual int CAudioDeviceSWMix::MaxSampleCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDeviceSWMix::MaxSampleCount(CAudioDeviceSWMix *this)
{
  return 1024;
}

//------------------------------------------------------------------------------
// Address: 0x00403FE0
// Name: public: virtual void CAudioDeviceSWMix::MixBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceSWMix::MixBegin(CAudioDeviceSWMix *this)
{
  memset(dst: (unsigned __int8 *)this->m_paintbuffer, value: 0, count: sizeof(this->m_paintbuffer));
}

//------------------------------------------------------------------------------
// Address: 0x00404000
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
// Address: 0x00404080
// Name: private: void CAudioWaveOutput::SilenceBuffer(short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::SilenceBuffer(CAudioWaveOutput *this, __int16 *pSamples, int sampleCount)
{
  int v3; // ecx

  v3 = sampleCount;
  if ( sampleCount > 0 )
  {
    do
    {
      *pSamples = 0;
      pSamples[1] = 0;
      pSamples += 2;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004040B0
// Name: public: virtual void CAudioWaveOutput::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::Flush(CAudioWaveOutput *this)
{
  waveOutReset(hwo: this->m_deviceHandle);
}

//------------------------------------------------------------------------------
// Address: 0x004040C0
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
// Address: 0x00404180
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
// Address: 0x004041B0
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
// Address: 0x00404200
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
// Address: 0x00404230
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
// Address: 0x00404260
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
// Address: 0x00404350
// Name: public: virtual class CAudioSource __near * CSceneManagerSound::LoadSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSource *__thiscall CSceneManagerSound::LoadSound(CSceneManagerSound *this, const char *wavfile)
{
  if ( this->m_pAudio != nullptr )
    return AudioSource_Create(pName: wavfile);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00404370
// Name: public: virtual void CSceneManagerSound::PlaySoundA(char const __near *,class CAudioMixer __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManagerSound::PlaySoundA(CSceneManagerSound *this, const char *wavfile, CAudioMixer **ppMixer)
{
  CAudioSource *v4; // eax
  CAudioMixer *v5; // eax

  if ( this->m_pAudio != nullptr )
  {
    v4 = this->FindOrAddSound(this, a2: wavfile);
    if ( v4 != nullptr )
    {
      v5 = v4->CreateMixer(this: v4);
      if ( ppMixer != nullptr )
        *ppMixer = v5;
      this->m_pAudio->AddSource(this: this->m_pAudio, a2: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004043B0
// Name: public: virtual void CSceneManagerSound::PlaySoundA(class CAudioSource __near *,class CAudioMixer __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManagerSound::PlaySoundA(CSceneManagerSound *this, CAudioSource *source, CAudioMixer **ppMixer)
{
  CAudioMixer *v4; // eax

  if ( ppMixer != nullptr )
    *ppMixer = nullptr;
  if ( this->m_pAudio != nullptr )
  {
    v4 = source->CreateMixer(this: source);
    if ( ppMixer != nullptr )
      *ppMixer = v4;
    this->m_pAudio->AddSource(this: this->m_pAudio, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004043F0
// Name: public: virtual void CSceneManagerSound::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManagerSound::Update(CSceneManagerSound *this, float dt)
{
  CAudioOutput *m_pAudio; // ecx

  m_pAudio = this->m_pAudio;
  if ( m_pAudio != nullptr )
    ((void (__stdcall *)(_DWORD))m_pAudio->Update)(a1: LODWORD(this->m_flElapsedTime));
  this->m_flElapsedTime = this->m_flElapsedTime + dt;
}

//------------------------------------------------------------------------------
// Address: 0x00404430
// Name: public: virtual void CSceneManagerSound::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManagerSound::Flush(CSceneManagerSound *this)
{
  if ( this->m_pAudio != nullptr )
    this->m_pAudio->Flush(this: this->m_pAudio);
}

//------------------------------------------------------------------------------
// Address: 0x00404450
// Name: public: virtual void CSceneManagerSound::StopAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManagerSound::StopAll(CSceneManagerSound *this)
{
  if ( this->m_pAudio != nullptr )
    this->m_pAudio->StopSounds(this: this->m_pAudio);
}

//------------------------------------------------------------------------------
// Address: 0x00404470
// Name: public: virtual void CSceneManagerSound::StopSound(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManagerSound::StopSound(CSceneManagerSound *this, CAudioMixer *mixer)
{
  int v3; // eax

  v3 = this->m_pAudio->FindSourceIndex(this: this->m_pAudio, a2: mixer);
  if ( v3 != -1 )
    this->m_pAudio->FreeChannel(this: this->m_pAudio, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004044A0
// Name: public: virtual bool CSceneManagerSound::IsSoundPlaying(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneManagerSound::IsSoundPlaying(CSceneManagerSound *this, CAudioMixer *pMixer)
{
  return this->m_pAudio != nullptr
      && pMixer != nullptr
      && this->m_pAudio->FindSourceIndex(this: this->m_pAudio, a2: pMixer) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x004044D0
// Name: public: virtual class CAudioMixer __near * CSceneManagerSound::FindMixer(class CAudioSource __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixer *__thiscall CSceneManagerSound::FindMixer(CSceneManagerSound *this, CAudioSource *source)
{
  if ( this->m_pAudio != nullptr )
    return this->m_pAudio->GetMixerForSource(this: this->m_pAudio, a2: source);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004044F0
// Name: public: virtual int CAudioWaveOutput::GetNumberofSamplesAhead(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioWaveOutput::GetNumberofSamplesAhead(CAudioWaveOutput *this)
{
  CAudioWaveOutput::ComputeSampleAheadAmount(this);
  return this->m_nEstimatedSamplesAhead;
}

//------------------------------------------------------------------------------
// Address: 0x00404500
// Name: public: virtual float CAudioWaveOutput::GetAmountofTimeAhead(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAudioWaveOutput::GetAmountofTimeAhead(CAudioWaveOutput *this)
{
  CAudioWaveOutput::ComputeSampleAheadAmount(this);
  return (double)this->m_nEstimatedSamplesAhead * 0.000022675737;
}

//------------------------------------------------------------------------------
// Address: 0x00404520
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
// Address: 0x00404620
// Name: private: bool CAudioWaveOutput::IsSourceReferencedByActiveBuffer(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioWaveOutput::IsSourceReferencedByActiveBuffer(CAudioWaveOutput *this, CAudioMixer *mixer)
{
  int v3; // ebx
  int *i; // edi
  int v5; // ecx
  CAudioMixer **v6; // edx

  if ( this->m_deviceHandle == nullptr )
    return 0;
  v3 = 0;
  for ( i = &this->m_buffers[0].m_Referenced.m_Size; ; i += 8 )
  {
    if ( *((_BYTE *)i - 20) != 0 && (*(_BYTE *)(*(i - 6) + 16) & 1) == 0 )
    {
      v5 = 0;
      if ( *i > 0 )
        break;
    }
LABEL_10:
    if ( ++v3 >= 32 )
      return 0;
  }
  v6 = (CAudioMixer **)*(i - 3);
  while ( *v6 != mixer )
  {
    ++v5;
    v6 += 2;
    if ( v5 >= *i )
      goto LABEL_10;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404690
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
// Address: 0x004046F0
// Name: private: class CAudioBuffer __near * CAudioWaveOutput::GetEmptyBuffer(void)
// Source: json
//------------------------------------------------------------------------------
CAudioBuffer *__thiscall CAudioWaveOutput::GetEmptyBuffer(CAudioWaveOutput *this)
{
  CAudioBuffer *result; // eax
  int v2; // edx
  CAudioBuffer *i; // esi
  int v4; // edx
  CAudioBuffer *v5; // esi
  bool v6; // sf

  result = nullptr;
  if ( this->m_deviceHandle != nullptr )
  {
    v2 = 0;
    for ( i = this->m_buffers; i->submitted && (i->hdr->dwFlags & 1) == 0; ++i )
    {
      if ( ++v2 >= 32 )
        return nullptr;
    }
    v4 = v2;
    v5 = &this->m_buffers[v4];
    v5->submitted = true;
    v6 = this->m_buffers[v4].m_Referenced.m_Memory.m_nGrowSize < 0;
    v5->m_Referenced.m_Size = 0;
    if ( !v6 )
    {
      if ( this->m_buffers[v4].m_Referenced.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_buffers[v4].m_Referenced.m_Memory.m_pMemory);
        v5->m_Referenced.m_Memory.m_pMemory = nullptr;
      }
      v5->m_Referenced.m_Memory.m_nAllocationCount = 0;
    }
    v5->m_Referenced.m_pElements = v5->m_Referenced.m_Memory.m_pMemory;
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404770
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
// Address: 0x004047C0
// Name: public: CSceneManagerSound::~CSceneManagerSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManagerSound::~CSceneManagerSound(CSceneManagerSound *this)
{
  const char *v2; // eax
  int v3; // ebx
  CSoundFile *v4; // esi
  const char *v5; // eax
  CAudioSource *source; // ecx
  CSoundFile *m_pMemory; // eax
  int m_Size; // [esp-4h] [ebp-10h]
  int i; // [esp+8h] [ebp-4h]

  m_Size = this->m_ActiveSounds.m_Size;
  this->__vftable = (CSceneManagerSound_vtbl *)&CSceneManagerSound::`vftable';
  v2 = va(fmt: "Removing %i sounds\n", m_Size);
  OutputDebugStringA(lpOutputString: v2);
  v3 = 0;
  for ( i = 0; i < this->m_ActiveSounds.m_Size; ++i )
  {
    v4 = &this->m_ActiveSounds.m_Memory.m_pMemory[v3];
    v5 = va(fmt: "Removing sound:  %s\n", v4->filename);
    OutputDebugStringA(lpOutputString: v5);
    source = v4->source;
    if ( source != nullptr )
      ((void (__thiscall *)(CAudioSource *, int))source->dtr_CAudioSource)(a1: source, a2: 1);
    ++v3;
  }
  this->m_ActiveSounds.m_Size = 0;
  if ( this->m_ActiveSounds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ActiveSounds.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ActiveSounds.m_Memory.m_pMemory);
      this->m_ActiveSounds.m_Memory.m_pMemory = nullptr;
    }
    this->m_ActiveSounds.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_ActiveSounds.m_Memory.m_pMemory;
  this->m_ActiveSounds.m_pElements = m_pMemory;
  if ( this->m_ActiveSounds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_ActiveSounds.m_Memory.m_pMemory = nullptr;
    }
    this->m_ActiveSounds.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404890
// Name: private: void CAudioWaveOutput::AddToReferencedList(class CAudioMixer __near *,class CAudioBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::AddToReferencedList(CAudioWaveOutput *this, CAudioMixer *mixer, CAudioBuffer *buffer)
{
  int m_Size; // ecx
  int v4; // eax
  CAudioMixerState *v5; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CAudioMixerState *m_pMemory; // ecx
  int v9; // eax
  CAudioMixerState *v10; // esi

  m_Size = buffer->m_Referenced.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    m_nAllocationCount = buffer->m_Referenced.m_Memory.m_nAllocationCount;
    v7 = buffer->m_Referenced.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CAudioMixerState,int>::Grow(this: &buffer->m_Referenced.m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++buffer->m_Referenced.m_Size;
    m_pMemory = buffer->m_Referenced.m_Memory.m_pMemory;
    v9 = buffer->m_Referenced.m_Size - v7 - 1;
    buffer->m_Referenced.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 8 * v9);
    v10 = &buffer->m_Referenced.m_Memory.m_pMemory[v7];
    v10->mixer = mixer;
    v10->submit_mixer_sample = mixer->GetSamplePosition(this: mixer);
  }
  else
  {
    v5 = buffer->m_Referenced.m_Memory.m_pMemory;
    while ( v5->mixer != mixer )
    {
      ++v4;
      ++v5;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404920
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
// Address: 0x00404A30
// Name: public: virtual int CAudioWaveOutput::SampleSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioWaveOutput::SampleSize(CAudioWaveOutput *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00404A40
// Name: public: virtual int CAudioWaveOutput::SampleRate(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioWaveOutput::SampleRate(CAudioWaveOutput *this)
{
  return 44100;
}

//------------------------------------------------------------------------------
// Address: 0x00404A50
// Name: public: virtual void CAudioWaveOutput::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::Update(CAudioWaveOutput *this, float time)
{
  bool v3; // zf
  CAudioBuffer *EmptyBuffer; // eax
  CAudioBuffer *v5; // ebx
  wavehdr_tag *hdr; // eax
  int v7; // esi
  CAudioDeviceSWMix *p_m_audioDevice; // esi
  int v9; // eax
  int v10; // ebx
  CAudioMixer **m_sourceList; // eax
  CAudioMixer *v12; // esi
  int v13; // eax
  CAudioMixer_vtbl *v14; // edx
  bool v15; // al
  CAudioMixer_vtbl *v16; // edx
  CAudioMixer_vtbl *v17; // ebx
  int v18; // eax
  CAudioMixer v19; // ebx
  int v20; // eax
  int v21; // eax
  __int16 *v22; // ecx
  channel_s channel; // [esp+0h] [ebp-30h] BYREF
  CAudioBuffer *pBuffer; // [esp+14h] [ebp-1Ch]
  CAudioMixer **v25; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h]
  int currentsample; // [esp+20h] [ebp-10h]
  int forward; // [esp+24h] [ebp-Ch]
  __int16 *pSamples; // [esp+28h] [ebp-8h]
  int tempCount; // [esp+2Ch] [ebp-4h]
  int sampleCount; // [esp+38h] [ebp+8h]

  v3 = this->m_deviceHandle == nullptr;
  channel.leftvol = 200;
  channel.rightvol = 200;
  channel.pitch = 1.0;
  if ( !v3 )
  {
    if ( this->m_mixTime < 0.0 || this->m_baseTime > time )
    {
      this->m_baseTime = time;
      this->m_mixTime = 0.0;
    }
    if ( (float)(time - this->m_baseTime) > this->m_mixTime )
    {
      EmptyBuffer = CAudioWaveOutput::GetEmptyBuffer(this);
      v5 = EmptyBuffer;
      pBuffer = EmptyBuffer;
      if ( EmptyBuffer != nullptr )
      {
        hdr = EmptyBuffer->hdr;
        if ( v5->hdr != nullptr )
        {
          v7 = hdr->dwBufferLength >> 2;
          this->m_mixTime = (float)((float)v7 * 0.000022675737) + this->m_mixTime;
          pSamples = (__int16 *)v5->hdr->lpData;
          CAudioWaveOutput::SilenceBuffer(this, pSamples, sampleCount: v7);
          tempCount = v7;
          if ( v7 > 0 )
          {
            p_m_audioDevice = &this->m_audioDevice;
            do
            {
              v9 = p_m_audioDevice->MaxSampleCount(this: p_m_audioDevice);
              if ( tempCount <= v9 )
                sampleCount = tempCount;
              else
                sampleCount = p_m_audioDevice->MaxSampleCount(this: p_m_audioDevice);
              p_m_audioDevice->MixBegin(this: p_m_audioDevice);
              v10 = 0;
              m_sourceList = this->m_sourceList;
              i = 0;
              v25 = this->m_sourceList;
              do
              {
                v12 = *m_sourceList;
                if ( *m_sourceList != nullptr )
                {
                  v13 = v12->GetSamplePosition(this: v12);
                  v14 = v12->__vftable;
                  currentsample = v13;
                  v15 = v14->GetDirection(this: v12);
                  v16 = v12->__vftable;
                  LOBYTE(forward) = v15;
                  if ( v16->GetActive(this: v12) )
                  {
                    v17 = v12->__vftable;
                    v18 = ((int (__thiscall *)(CAudioWaveOutput *, int))this->SampleRate)(a1: this, a2: forward);
                    if ( ((unsigned __int8 (__thiscall *)(CAudioMixer *, CAudioDeviceSWMix *, channel_s *, int, int, int))v17->MixDataToDevice)(
                           a1: v12,
                           a2: &this->m_audioDevice,
                           a3: &channel,
                           a4: currentsample,
                           a5: sampleCount,
                           a6: v18) != 0 )
                      CAudioWaveOutput::AddToReferencedList(this, mixer: v12, buffer: pBuffer);
                    else
                      v12->SetActive(this: v12, a2: false);
                  }
                  else if ( CAudioWaveOutput::IsSourceReferencedByActiveBuffer(this, mixer: v12) != 0 )
                  {
                    v19.__vftable = v12->__vftable;
                    v20 = ((int (__thiscall *)(CAudioWaveOutput *, int))this->SampleRate)(a1: this, a2: forward);
                    ((void (__thiscall *)(CAudioMixer *, channel_s *, int, int, int))v19.IncrementSamples)(
                      a1: v12,
                      a2: &channel,
                      a3: currentsample,
                      a4: sampleCount,
                      a5: v20);
                  }
                  else if ( !v12->GetAutoDelete(this: v12) )
                  {
                    this->FreeChannel(this, a2: v10);
                  }
                }
                v10 = i + 1;
                m_sourceList = v25 + 1;
                i = v10;
                ++v25;
              }
              while ( v10 < 16 );
              p_m_audioDevice = &this->m_audioDevice;
              CAudioDeviceSWMix::TransferBufferStereo16(this: &this->m_audioDevice, pOutput: pSamples, sampleCount);
              v21 = tempCount;
              v22 = pSamples;
              this->m_sampleIndex += sampleCount;
              tempCount = v21 - sampleCount;
              pSamples = &v22[2 * sampleCount];
            }
            while ( v21 - sampleCount > 0 );
            v5 = pBuffer;
          }
          v5->submit_sample_count = this->GetOutputPosition(this);
          waveOutWrite(hwo: this->m_deviceHandle, pwh: v5->hdr, cbwh: 0x20u);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404C90
// Name: public: virtual class CAudioSource __near * CSceneManagerSound::FindOrAddSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSource *__thiscall CSceneManagerSound::FindOrAddSound(CSceneManagerSound *this, const char *filename)
{
  CSoundFile *v4; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CSoundFile *m_pMemory; // ecx
  int v8; // eax
  CSoundFile *v9; // edi
  CAudioSource *source; // ecx
  int i; // [esp+Ch] [ebp-8h]
  int v13; // [esp+10h] [ebp-4h]
  int filetime; // [esp+1Ch] [ebp+8h]

  i = 0;
  if ( this->m_ActiveSounds.m_Size <= 0 )
  {
LABEL_5:
    m_Size = this->m_ActiveSounds.m_Size;
    m_nAllocationCount = this->m_ActiveSounds.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CSoundFile,int>::Grow(this: &this->m_ActiveSounds.m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++this->m_ActiveSounds.m_Size;
    m_pMemory = this->m_ActiveSounds.m_Memory.m_pMemory;
    v8 = this->m_ActiveSounds.m_Size - m_Size - 1;
    this->m_ActiveSounds.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 520 * v8);
    v9 = &this->m_ActiveSounds.m_Memory.m_pMemory[m_Size];
    strcpy(v9->filename, filename);
    v9->source = this->LoadSound(this, a2: filename);
    v9->filetime = filesystem->GetFileTime(this: &filesystem->IBaseFileSystem, a2: filename, a3: nullptr);
    return v9->source;
  }
  else
  {
    v13 = 0;
    while ( 1 )
    {
      v4 = &this->m_ActiveSounds.m_Memory.m_pMemory[v13];
      if ( _V_stricmp(s1: v4->filename, s2: filename) == 0 )
        break;
      ++v13;
      if ( ++i >= this->m_ActiveSounds.m_Size )
        goto LABEL_5;
    }
    filetime = filesystem->GetFileTime(this: &filesystem->IBaseFileSystem, a2: filename, a3: nullptr);
    if ( filetime != v4->filetime )
    {
      Con_Printf(fmt: "Reloading sound %s\n", filename);
      source = v4->source;
      if ( source != nullptr )
        ((void (__thiscall *)(CAudioSource *, int))source->dtr_CAudioSource)(a1: source, a2: 1);
      v4->source = this->LoadSound(this, a2: filename);
      v4->filetime = filetime;
    }
    return v4->source;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404DF0
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
// Address: 0x00404EB0
// Name: public: virtual void CSceneManagerSound::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManagerSound::Init(CSceneManagerSound *this)
{
  CAudioOutput *v1; // eax
  CAudioWaveOutput *v3; // eax
  CAudioWaveOutput *v4; // eax

  v1 = (CAudioOutput *)dword_46F8B4;
  this->m_flElapsedTime = 0.0;
  if ( v1 == nullptr )
  {
    v3 = (CAudioWaveOutput *)operator new(nSize: 0x245Cu);
    if ( v3 != nullptr )
    {
      v4 = CAudioWaveOutput::CAudioWaveOutput(this: v3);
      this->m_pAudio = v4;
      dword_46F8B4 = (int)v4;
      return;
    }
    v1 = nullptr;
    dword_46F8B4 = 0;
  }
  this->m_pAudio = v1;
}
