// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/sound.cpp
// Functions: 50
// ============================================================

#include "utils\hlfaceposer\sound.h"

//------------------------------------------------------------------------------
// Address: 0x00402A30
// Name: public: class CVoiceData __near * CMouthInfo::AddSource(class CAudioSource __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CVoiceData *__thiscall CMouthInfo::AddSource(CMouthInfo *this, CAudioSource *source, bool bIgnorePhonemes)
{
  __int16 m_nVoiceSources; // si
  int v4; // eax
  CVoiceData *m_VoiceSources; // edx
  CVoiceData *result; // eax

  m_nVoiceSources = this->m_nVoiceSources;
  v4 = 0;
  if ( m_nVoiceSources > 0 )
  {
    m_VoiceSources = this->m_VoiceSources;
    while ( m_VoiceSources == nullptr || m_VoiceSources->m_pAudioSource != source )
    {
      ++v4;
      ++m_VoiceSources;
      if ( v4 >= this->m_nVoiceSources )
        goto LABEL_8;
    }
    if ( v4 != -1 )
      goto LABEL_10;
  }
LABEL_8:
  if ( m_nVoiceSources < 4 )
  {
    v4 = m_nVoiceSources;
    this->m_nVoiceSources = m_nVoiceSources + 1;
LABEL_10:
    result = &this->m_VoiceSources[v4];
    result->m_pAudioSource = source;
    result->m_bIgnorePhonemes = bIgnorePhonemes;
    result->m_flElapsed = 0.0;
    return result;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00402AA0
// Name: public: class CStudioHdr __near * StudioModel::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__thiscall StudioModel::GetStudioHdr(StudioModel *this)
{
  CStudioHdr *result; // eax
  const studiohdr_t *v3; // eax

  result = this->m_pStudioHdr;
  if ( result != nullptr && result->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    return this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402AE0
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
// Address: 0x00402B70
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
// Address: 0x00402C00
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
// Address: 0x00402C90
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
// Address: 0x00402D30
// Name: public: virtual int CAudioDeviceSWMix::MaxSampleCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDeviceSWMix::MaxSampleCount(CAudioDeviceSWMix *this)
{
  return 1024;
}

//------------------------------------------------------------------------------
// Address: 0x00402D40
// Name: public: virtual void CAudioDeviceSWMix::MixBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceSWMix::MixBegin(CAudioDeviceSWMix *this)
{
  memset(dst: (unsigned __int8 *)this->m_paintbuffer, value: 0, count: sizeof(this->m_paintbuffer));
}

//------------------------------------------------------------------------------
// Address: 0x00402D60
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
// Address: 0x00402DE0
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
// Address: 0x00402E10
// Name: public: virtual void CAudioWaveOutput::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::Flush(CAudioWaveOutput *this)
{
  waveOutReset(hwo: this->m_deviceHandle);
}

//------------------------------------------------------------------------------
// Address: 0x00402E20
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
// Address: 0x00402EE0
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
// Address: 0x00402F10
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
// Address: 0x00402F60
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
// Address: 0x00402F90
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
// Address: 0x00402FC0
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
// Address: 0x004030A0
// Name: public: virtual float CFacePoserSound::GetAmountofTimeAhead(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFacePoserSound::GetAmountofTimeAhead(CFacePoserSound *this)
{
  if ( this->m_pAudio != nullptr )
    return this->m_pAudio->GetAmountofTimeAhead(this: this->m_pAudio);
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004030C0
// Name: public: virtual int CFacePoserSound::GetNumberofSamplesAhead(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFacePoserSound::GetNumberofSamplesAhead(CFacePoserSound *this)
{
  if ( this->m_pAudio != nullptr )
    return this->m_pAudio->GetNumberofSamplesAhead(this: this->m_pAudio);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004030E0
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
// Address: 0x00403100
// Name: public: virtual void CFacePoserSound::PlaySoundA(class CAudioSource __near *,float,class CAudioMixer __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFacePoserSound::PlaySoundA(
        CFacePoserSound *this@<ecx>,
        int a2@<esi>,
        CAudioSource *source,
        float volume,
        CAudioMixer **ppMixer)
{
  CAudioMixer *v6; // eax
  CAudioMixer *v7; // esi

  if ( ppMixer != nullptr )
    *ppMixer = nullptr;
  if ( this->m_pAudio != nullptr )
  {
    v6 = (CAudioMixer *)((int (__thiscall *)(CAudioSource *, int))source->CreateMixer)(a1: source, a2);
    v7 = v6;
    if ( ppMixer != nullptr )
      *ppMixer = v6;
    ((void (__thiscall *)(CAudioMixer *, _DWORD))v6->SetVolume)(a1: v6, a2: LODWORD(volume));
    this->m_pAudio->AddSource(this: this->m_pAudio, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403160
// Name: private: void CFacePoserSound::AddViseme(float,class StudioModel __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::AddViseme(
        CFacePoserSound *this,
        float intensity,
        StudioModel *model,
        int phoneme,
        float scale)
{
  CStudioHdr *m_pStudioHdr; // eax
  int v7; // edi
  const studiohdr_t *v8; // eax
  CExpClass **p_cl; // esi
  IExpressionManager *v10; // ecx
  const char *v11; // eax
  int v12; // eax
  const char *v13; // eax
  CExpression *v14; // ecx
  float v15; // xmm1_4
  float amount; // xmm0_4
  const studiohdr_t *v17; // eax
  LocalFlexController_t i; // esi
  int v19; // ecx
  float v20; // xmm1_4
  CStudioHdr *hdr; // [esp+1Ch] [ebp-4h]
  float add; // [esp+2Ch] [ebp+Ch]
  float curvalue; // [esp+30h] [ebp+10h]

  m_pStudioHdr = model->m_pStudioHdr;
  v7 = 0;
  if ( m_pStudioHdr == nullptr
    || m_pStudioHdr->m_pStudioHdr != nullptr
    || (v8 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->m_MDLHandle),
        CStudioHdr::Init(this: model->m_pStudioHdr, pStudioHdr: v8, mdlcache: nullptr),
        (m_pStudioHdr = model->m_pStudioHdr)->m_pStudioHdr != nullptr) )
  {
    hdr = m_pStudioHdr;
    if ( m_pStudioHdr != nullptr )
    {
      p_cl = &g_PhonemeClasses[0].cl;
      while ( 1 )
      {
        v10 = expressions;
        v11 = (const char *)*(p_cl - 2);
        *((_BYTE *)p_cl - 3) = 0;
        p_cl[1] = nullptr;
        p_cl[2] = nullptr;
        p_cl[3] = nullptr;
        v12 = (int)v10->FindClass(this: v10, a2: v11, a3: true);
        *p_cl = (CExpClass *)v12;
        if ( v12 != 0 )
        {
          v13 = ConvertPhoneme(code: phoneme);
          p_cl[1] = (CExpClass *)CExpClass::FindExpression(this: *p_cl, name: v13);
        }
        if ( *((_BYTE *)p_cl - 4) != 0 && (*p_cl == nullptr || p_cl[1] == nullptr) )
          break;
        v14 = (CExpression *)p_cl[1];
        if ( v14 != nullptr )
        {
          *((_BYTE *)p_cl - 3) = 1;
          p_cl[2] = (CExpClass *)CExpression::GetSettings(this: v14);
        }
        p_cl += 6;
        if ( (int)p_cl >= (int)&vec4_invalid )
        {
          if ( intensity <= 0.60000002 )
          {
            if ( intensity >= 0.40000001 )
            {
              amount = intensity * 2.0;
            }
            else if ( g_PhonemeClasses[0].valid )
            {
              amount = (float)((float)(1.0 - (float)((float)(0.40000001 - intensity) * 2.5)) * 2.0) * 0.40000001;
              g_PhonemeClasses[0].amount = (float)(0.40000001 - intensity) * 2.5;
            }
            else
            {
              amount = 0.80000001;
            }
          }
          else if ( g_PhonemeClasses[2].valid )
          {
            v15 = (float)(1.0 - intensity) * 2.5000002;
            amount = (float)(v15 * 2.0) * 0.60000002;
            g_PhonemeClasses[2].amount = 1.0 - v15;
          }
          else
          {
            amount = 1.2;
          }
          g_PhonemeClasses[1].amount = amount;
          v17 = hdr->m_pStudioHdr;
          for ( i = DUMMY_NULL_FLEX_CONTROLLER; i < hdr->m_pStudioHdr->numflexcontrollers; v7 += 20 )
          {
            v19 = *(int *)((char *)&v17->checksum + v7 + v17->flexcontrollerindex);
            v20 = 0.0;
            add = 0.0;
            if ( g_PhonemeClasses[0].valid && g_PhonemeClasses[0].amount != 0.0 )
            {
              v20 = g_PhonemeClasses[0].settings[v19] * g_PhonemeClasses[0].amount;
              add = v20;
            }
            if ( g_PhonemeClasses[1].valid && amount != 0.0 )
            {
              v20 = (float)(g_PhonemeClasses[1].settings[v19] * amount) + v20;
              add = v20;
            }
            if ( g_PhonemeClasses[2].valid && g_PhonemeClasses[2].amount != 0.0 )
            {
              v20 = v20 + (float)(g_PhonemeClasses[2].settings[v19] * g_PhonemeClasses[2].amount);
              add = v20;
            }
            if ( v20 != 0.0 )
            {
              curvalue = StudioModel::GetFlexController(this: model, iFlex: i) + add * scale;
              StudioModel::SetFlexController(this: model, iFlex: i, flValue: curvalue);
              amount = g_PhonemeClasses[1].amount;
            }
            v17 = hdr->m_pStudioHdr;
            ++i;
          }
          return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403400
// Name: public: virtual void CFacePoserSound::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::Flush(CFacePoserSound *this)
{
  if ( this->m_pAudio != nullptr )
    this->m_pAudio->Flush(this: this->m_pAudio);
}

//------------------------------------------------------------------------------
// Address: 0x00403420
// Name: public: virtual void CFacePoserSound::StopAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::StopAll(CFacePoserSound *this)
{
  int v2; // edi
  int i; // esi
  StudioModel *v4; // eax

  v2 = models->Count(this: models);
  for ( i = 0; i < v2; ++i )
  {
    v4 = models->GetStudioModel(this: models, a2: i);
    if ( v4 != nullptr )
      v4->m_mouth.m_nVoiceSources = 0;
  }
  if ( this->m_pAudio != nullptr )
    this->m_pAudio->StopSounds(this: this->m_pAudio);
}

//------------------------------------------------------------------------------
// Address: 0x00403480
// Name: public: virtual void CFacePoserSound::StopSound(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::StopSound(CFacePoserSound *this, CAudioMixer *mixer)
{
  int v3; // eax

  v3 = this->m_pAudio->FindSourceIndex(this: this->m_pAudio, a2: mixer);
  if ( v3 != -1 )
    this->m_pAudio->FreeChannel(this: this->m_pAudio, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004034B0
// Name: public: virtual bool CFacePoserSound::IsSoundPlaying(class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFacePoserSound::IsSoundPlaying(CFacePoserSound *this, CAudioMixer *pMixer)
{
  return this->m_pAudio != nullptr
      && pMixer != nullptr
      && this->m_pAudio->FindSourceIndex(this: this->m_pAudio, a2: pMixer) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x004034E0
// Name: public: virtual class CAudioMixer __near * CFacePoserSound::FindMixer(class CAudioSource __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixer *__thiscall CFacePoserSound::FindMixer(CFacePoserSound *this, CAudioSource *source)
{
  if ( this->m_pAudio != nullptr )
    return this->m_pAudio->GetMixerForSource(this: this->m_pAudio, a2: source);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004035A0
// Name: public: void CMouthInfo::RemoveSource(class CAudioSource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMouthInfo::RemoveSource(CMouthInfo *this, CAudioSource *source)
{
  __int16 m_nVoiceSources; // si
  int v3; // eax
  CVoiceData *i; // edx
  __int16 v5; // dx
  CVoiceData *v6; // eax

  m_nVoiceSources = this->m_nVoiceSources;
  v3 = 0;
  if ( m_nVoiceSources > 0 )
  {
    for ( i = this->m_VoiceSources; i == nullptr || i->m_pAudioSource != source; ++i )
    {
      if ( ++v3 >= this->m_nVoiceSources )
        return;
    }
    if ( v3 >= 0 && v3 < m_nVoiceSources )
    {
      v5 = m_nVoiceSources - 1;
      this->m_nVoiceSources = m_nVoiceSources - 1;
      if ( (__int16)(m_nVoiceSources - 1) > 0 )
      {
        v6 = &this->m_VoiceSources[v3];
        *(_QWORD *)&v6->m_flElapsed = *(_QWORD *)&this->m_VoiceSources[v5].m_flElapsed;
        *(_DWORD *)&v6->m_bIgnorePhonemes = *(_DWORD *)&this->m_VoiceSources[v5].m_bIgnorePhonemes;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403620
// Name: public: virtual int CAudioWaveOutput::GetNumberofSamplesAhead(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioWaveOutput::GetNumberofSamplesAhead(CAudioWaveOutput *this)
{
  CAudioWaveOutput::ComputeSampleAheadAmount(this);
  return this->m_nEstimatedSamplesAhead;
}

//------------------------------------------------------------------------------
// Address: 0x00403630
// Name: public: virtual float CAudioWaveOutput::GetAmountofTimeAhead(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAudioWaveOutput::GetAmountofTimeAhead(CAudioWaveOutput *this)
{
  CAudioWaveOutput::ComputeSampleAheadAmount(this);
  return (double)this->m_nEstimatedSamplesAhead * 0.000022675737;
}

//------------------------------------------------------------------------------
// Address: 0x00403650
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
// Address: 0x004036B0
// Name: public: virtual void CFacePoserSound::RenderWavToDC(struct HDC__ __near *,struct tagRECT __near &,class Color const __near &,float,float,class CAudioSource __near *,bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFacePoserSound::RenderWavToDC(
        CFacePoserSound *this@<ecx>,
        int a2@<ebx>,
        CAudioDeviceSWMix *a3@<edi>,
        channel_s *p_channel@<esi>,
        HDC dc,
        tagRECT *outrect,
        const Color *clr,
        float starttime,
        float endtime,
        CAudioSource *pWave,
        bool selected,
        int selectionstart,
        int selectionend)
{
  CAudioSource_vtbl *v14; // edx
  CAudioMixer *v15; // eax
  CAudioSource_vtbl *v17; // edx
  float v18; // xmm1_4
  int (__thiscall *SampleRate)(CAudioSource *); // eax
  float v20; // xmm0_4
  int (__thiscall *v21)(CAudioSource *); // eax
  double v22; // st7
  float (__thiscall *GetRunningLength)(CAudioSource *); // eax
  HPEN__ *v24; // eax
  int v25; // edx
  int bottom; // ecx
  CAudioDeviceSWMix *v28; // ecx
  CAudioSource_vtbl *v29; // edx
  int v30; // eax
  float v31; // xmm0_4
  char v32; // al
  int v33; // ecx
  int v34; // ecx
  HPEN__ **p_pen4; // eax
  HPEN__ *v36; // eax
  int v37; // ecx
  int v38; // edx
  int v39; // ecx
  int v40; // kr14_4
  int v41; // ecx
  channel_s channel; // [esp+0h] [ebp-5Ch] BYREF
  HPEN__ *oldPen; // [esp+14h] [ebp-48h]
  float v47; // [esp+18h] [ebp-44h]
  int height; // [esp+1Ch] [ebp-40h]
  HPEN__ *old; // [esp+20h] [ebp-3Ch]
  HPEN__ *pen4; // [esp+24h] [ebp-38h] BYREF
  float selectionendtime; // [esp+28h] [ebp-34h]
  float selectionstarttime; // [esp+2Ch] [ebp-30h]
  HPEN__ *pen3; // [esp+30h] [ebp-2Ch] BYREF
  HPEN__ *pen2; // [esp+34h] [ebp-28h]
  HPEN__ *pen; // [esp+38h] [ebp-24h]
  float timeperpixel; // [esp+3Ch] [ebp-20h]
  int midy; // [esp+40h] [ebp-1Ch]
  int maxvalue; // [esp+44h] [ebp-18h]
  int maxsamples; // [esp+48h] [ebp-14h]
  __int16 *samples; // [esp+4Ch] [ebp-10h]
  float currenttime; // [esp+50h] [ebp-Ch]
  int intsamplesperpixel; // [esp+54h] [ebp-8h]
  CAudioMixer *pMixer; // [esp+58h] [ebp-4h]
  bool (__thiscall **topb)(CAudioMixer *, IAudioDevice *, channel_s *, int, int, int, bool); // [esp+64h] [ebp+8h]
  int top; // [esp+64h] [ebp+8h]
  int topc; // [esp+64h] [ebp+8h]
  int topa; // [esp+64h] [ebp+8h]
  int pixel; // [esp+68h] [ebp+Ch]
  CAudioDeviceSWMix *clra; // [esp+6Ch] [ebp+10h]
  float totalsamplesa; // [esp+78h] [ebp+1Ch]
  int totalsamples; // [esp+78h] [ebp+1Ch]
  float totalsamplesb; // [esp+78h] [ebp+1Ch]
  char totalsamples_3; // [esp+7Bh] [ebp+1Fh]
  int count; // [esp+80h] [ebp+24h]
  int counta; // [esp+80h] [ebp+24h]
  int currentsample; // [esp+84h] [ebp+28h]
  int currentsamplea; // [esp+84h] [ebp+28h]

  channel.leftvol = 127;
  channel.rightvol = 127;
  channel.pitch = 1.0;
  if ( pWave != nullptr )
  {
    v14 = pWave->__vftable;
    maxvalue = (int)this->m_pAudio;
    v15 = v14->CreateMixer(this: pWave);
    v17 = pWave->__vftable;
    v18 = (float)(outrect->right - outrect->left);
    pMixer = v15;
    SampleRate = v17->SampleRate;
    timeperpixel = (float)(endtime - starttime) / v18;
    v20 = (float)SampleRate(this: pWave) * timeperpixel;
    if ( v20 >= 1024.0 )
      v20 = 1024.0;
    v21 = pWave->SampleRate;
    intsamplesperpixel = (int)v20;
    totalsamplesa = (float)v21(this: pWave);
    totalsamples = (int)(((double (__thiscall *)(CAudioSource *))pWave->GetRunningLength)(a1: pWave) * totalsamplesa);
    if ( totalsamples > 0 )
    {
      totalsamplesb = (float)totalsamples;
      v22 = ((double (__thiscall *)(CAudioSource *))pWave->GetRunningLength)(a1: pWave);
      GetRunningLength = pWave->GetRunningLength;
      selectionstarttime = v22 * (double)selectionstart / totalsamplesb;
      selectionendtime = ((double (__thiscall *)(CAudioSource *))GetRunningLength)(a1: pWave)
                       * (double)selectionend
                       / totalsamplesb;
      v24 = CreatePen(iStyle: 0, cWidth: 1, color: 0xFAAFAFu);
      v25 = clr->_color[1];
      pen = v24;
      pen2 = CreatePen(iStyle: 0, cWidth: 1, color: clr->_color[0] | ((v25 | (clr->_color[2] << 8)) << 8));
      pen3 = CreatePen(iStyle: 0, cWidth: 1, color: 0xF9C87Fu);
      pen4 = CreatePen(iStyle: 0, cWidth: 2, color: 0xC80000u);
      oldPen = (HPEN__ *)SelectObject(hdc: dc, h: pen);
      MoveToEx(hdc: dc, x: outrect->left, y: (outrect->bottom + outrect->top) / 2, lppt: nullptr);
      LineTo(hdc: dc, x: outrect->right, y: (outrect->bottom + outrect->top) / 2);
      SelectObject(hdc: dc, h: pen2);
      bottom = outrect->bottom;
      currenttime = 0.0;
      pixel = 0;
      height = (bottom - outrect->top) / 2;
      midy = (bottom + outrect->top) / 2;
      samples = (__int16 *)operator new(nSize: 4 * ((intsamplesperpixel + 3) & 0xFFFFFFFC));
      totalsamples_3 = 0;
      maxsamples = 32;
      if ( intsamplesperpixel / 16 >= 32 )
        maxsamples = intsamplesperpixel / 16;
      currentsample = 0;
      if ( endtime > 0.0 )
      {
        v28 = (CAudioDeviceSWMix *)(maxvalue + 1112);
        for ( clra = (CAudioDeviceSWMix *)(maxvalue + 1112); ; v28 = clra )
        {
          ((void (__thiscall *)(CAudioDeviceSWMix *, CAudioDeviceSWMix *, channel_s *, int))v28->MixBegin)(
            a1: v28,
            a2: a3,
            a3: p_channel,
            a4: a2);
          count = maxsamples;
          if ( maxsamples >= intsamplesperpixel )
            count = intsamplesperpixel;
          topb = &pMixer->MixDataToDevice;
          channel.rightvol = ((int (__thiscall *)(CAudioSource *, int, int, int))pWave->SampleRate)(
                               a1: pWave,
                               a2: 1,
                               a3: channel.leftvol,
                               a4: channel.rightvol);
          channel.leftvol = count;
          a2 = currentsample;
          p_channel = &channel;
          a3 = clra;
          if ( ((unsigned __int8 (__thiscall *)(CAudioMixer *))*topb)(a1: pMixer) == 0 )
            goto LABEL_36;
          currentsamplea = pMixer->GetSamplePosition(this: pMixer);
          top = intsamplesperpixel - count;
          if ( intsamplesperpixel - count > 0 )
          {
            v29 = pWave->__vftable;
            maxvalue = (int)&pMixer->SkipSamples;
            v30 = ((int (__thiscall *)(CAudioSource *, int))v29->SampleRate)(a1: pWave, a2: 1);
            if ( (*(unsigned __int8 (__thiscall **)(CAudioMixer *, channel_s *, int, int, int))maxvalue)(
                   a1: pMixer,
                   a2: &channel,
                   a3: currentsamplea,
                   a4: top,
                   a5: v30) == 0 )
              goto LABEL_36;
          }
          currentsample = pMixer->GetSamplePosition(this: pMixer);
          CAudioDeviceSWMix::TransferBufferStereo16(this: clra, pOutput: samples, sampleCount: count);
          v31 = currenttime;
          if ( currenttime >= starttime )
            break;
LABEL_35:
          currenttime = v31 + timeperpixel;
          if ( endtime <= (float)(v31 + timeperpixel) )
            goto LABEL_36;
        }
        if ( selected )
        {
          v32 = 0;
          if ( currenttime >= selectionstarttime && selectionendtime >= currenttime )
          {
            if ( totalsamples_3 != 0 )
            {
LABEL_24:
              v33 = outrect->bottom;
              maxvalue = v33;
              if ( v32 != 0 )
              {
                v34 = outrect->top;
                p_pen4 = &pen4;
              }
              else
              {
                p_pen4 = &pen3;
                v34 = v33 - 19;
              }
              topc = v34;
              v36 = (HPEN__ *)SelectObject(hdc: dc, h: *p_pen4);
              v37 = pixel + outrect->left;
              old = v36;
              MoveToEx(hdc: dc, x: v37, y: topc, lppt: nullptr);
              LineTo(hdc: dc, x: pixel + outrect->left, y: maxvalue - 1);
              SelectObject(hdc: dc, h: old);
              goto LABEL_28;
            }
            totalsamples_3 = 1;
LABEL_23:
            v32 = 1;
            goto LABEL_24;
          }
          if ( totalsamples_3 != 0 )
          {
            totalsamples_3 = 0;
            goto LABEL_23;
          }
        }
LABEL_28:
        v38 = -65536;
        v39 = 0;
        maxvalue = -65536;
        topa = 0x10000;
        counta = 2 * count;
        if ( counta > 0 )
        {
          do
          {
            v40 = samples[v39] + samples[v39 + 1];
            v38 = maxvalue;
            if ( v40 / 2 > maxvalue )
            {
              v38 = v40 / 2;
              maxvalue = v40 / 2;
            }
            if ( v40 / 2 < topa )
              topa = v40 / 2;
            v39 += 2;
          }
          while ( v39 < counta );
        }
        v41 = pixel + outrect->left;
        v47 = (float)height;
        MoveToEx(
          hdc: dc,
          x: v41,
          y: midy + (int)(float)((float)((float)v38 * 0.000030517578) * (float)height),
          lppt: nullptr);
        LineTo(hdc: dc, x: pixel + outrect->left, y: midy + (int)(float)((float)((float)topa * 0.000030517578) * v47));
        ++pixel;
        v31 = currenttime;
        goto LABEL_35;
      }
LABEL_36:
      free(pMem: samples);
      SelectObject(hdc: dc, h: oldPen);
      DeleteObject(ho: pen);
      DeleteObject(ho: pen2);
      DeleteObject(ho: pen3);
      if ( pMixer != nullptr )
        ((void (__thiscall *)(CAudioMixer *, int))pMixer->dtr_CAudioMixer)(a1: pMixer, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403B50
// Name: public: virtual void CFacePoserSound::EnsureNoModelReferences(class CAudioSource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::EnsureNoModelReferences(CFacePoserSound *this, CAudioSource *source)
{
  int v2; // edi
  StudioModel *v3; // eax
  int m_nVoiceSources; // esi
  CMouthInfo *p_m_mouth; // ecx
  int v6; // edx
  CVoiceData *m_VoiceSources; // eax
  int c; // [esp+4h] [ebp-4h]

  v2 = 0;
  c = models->Count(this: models);
  if ( c > 0 )
  {
    do
    {
      v3 = models->GetStudioModel(this: models, a2: v2);
      m_nVoiceSources = v3->m_mouth.m_nVoiceSources;
      p_m_mouth = &v3->m_mouth;
      v6 = 0;
      if ( m_nVoiceSources > 0 )
      {
        m_VoiceSources = v3->m_mouth.m_VoiceSources;
        while ( m_VoiceSources == nullptr || m_VoiceSources->m_pAudioSource != source )
        {
          ++v6;
          ++m_VoiceSources;
          if ( v6 >= m_nVoiceSources )
            goto LABEL_10;
        }
        if ( v6 != -1 )
          CMouthInfo::RemoveSource(this: p_m_mouth, source);
      }
LABEL_10:
      ++v2;
    }
    while ( v2 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403C60
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
// Address: 0x00403CD0
// Name: private: void CFacePoserSound::SetupWeights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::SetupWeights(CFacePoserSound *this)
{
  int v1; // edi
  int v2; // esi
  StudioModel *v3; // eax
  StudioModel *v4; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v6; // eax
  int v7; // eax
  CAudioSource *m_pAudioSource; // esi
  CAudioMixer *v9; // edi
  CSentence *v10; // ebx
  float v11; // xmm3_4
  int v12; // ecx
  float v13; // xmm4_4
  CWordTag *v14; // edi
  int m_Size; // eax
  int v16; // esi
  CPhonemeTag **m_pMemory; // ecx
  CPhonemeTag *v18; // edx
  CPhonemeTag **v19; // ecx
  float m_flStartTime; // xmm2_4
  float m_flEndTime; // xmm0_4
  float *v22; // ecx
  CWordTag *v23; // eax
  float v24; // xmm1_4
  bool v25; // zf
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  int c; // [esp+28h] [ebp-2Ch]
  float emphasis_intensity; // [esp+2Ch] [ebp-28h]
  float pos; // [esp+30h] [ebp-24h]
  int i; // [esp+34h] [ebp-20h]
  int s; // [esp+38h] [ebp-1Ch]
  int v37; // [esp+40h] [ebp-14h]
  StudioModel *model; // [esp+44h] [ebp-10h]
  float wa; // [esp+48h] [ebp-Ch]
  int w; // [esp+48h] [ebp-Ch]
  float t; // [esp+4Ch] [ebp-8h]
  int dt; // [esp+50h] [ebp-4h]

  v1 = models->Count(this: models);
  v2 = 0;
  c = v1;
  for ( i = 0; v2 < v1; i = v2 )
  {
    v3 = models->GetStudioModel(this: models, a2: v2);
    v4 = v3;
    model = v3;
    if ( v3 != nullptr )
    {
      m_pStudioHdr = v3->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr )
      {
        if ( m_pStudioHdr->m_pStudioHdr != nullptr
          || (v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v4->m_MDLHandle),
              CStudioHdr::Init(this: v4->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr),
              (m_pStudioHdr = v4->m_pStudioHdr)->m_pStudioHdr != nullptr) )
        {
          if ( m_pStudioHdr != nullptr )
          {
            v7 = 0;
            s = 0;
            if ( v4->m_mouth.m_nVoiceSources > 0 )
            {
              v37 = 0;
              do
              {
                if ( v7 >= 0
                  && v7 < v4->m_mouth.m_nVoiceSources
                  && (StudioModel *)((char *)v4 + v37 * 12) != (StudioModel *)-80
                  && !v4->m_mouth.m_VoiceSources[v37].m_bIgnorePhonemes )
                {
                  m_pAudioSource = v4->m_mouth.m_VoiceSources[v37].m_pAudioSource;
                  if ( m_pAudioSource != nullptr )
                  {
                    v9 = this->FindMixer(this, a2: m_pAudioSource);
                    if ( v9 != nullptr )
                    {
                      v10 = m_pAudioSource->GetSentence(this: m_pAudioSource);
                      if ( v10 != nullptr )
                      {
                        models->CheckResetFlexes(this: models);
                        pos = (float)v9->GetScrubPosition(this: v9);
                        t = pos / (float)m_pAudioSource->SampleRate(this: m_pAudioSource);
                        dt = 1034147594;
                        wa = m_pAudioSource->GetRunningLength(this: m_pAudioSource);
                        emphasis_intensity = CSentence::GetIntensity(this: v10, time: t, endtime: wa);
                        v11 = t;
                        if ( t > 0.0 )
                        {
                          v12 = 0;
                          w = 0;
                          if ( v10->m_Words.m_Size > 0 )
                          {
                            v13 = 0.079999998;
                            while ( 1 )
                            {
                              v14 = v10->m_Words.m_Memory.m_pMemory[v12];
                              if ( v14 != nullptr )
                              {
                                m_Size = v14->m_Phonemes.m_Size;
                                v16 = 0;
                                if ( m_Size > 0 )
                                  break;
                              }
LABEL_50:
                              w = ++v12;
                              if ( v12 >= v10->m_Words.m_Size )
                                goto LABEL_51;
                            }
                            while ( 2 )
                            {
                              m_pMemory = v14->m_Phonemes.m_Memory.m_pMemory;
                              v18 = m_pMemory[v16];
                              v19 = &m_pMemory[v16];
                              if ( v18 != nullptr )
                              {
                                m_flStartTime = v18->m_flStartTime;
                                if ( v11 > v18->m_flStartTime )
                                {
                                  m_flEndTime = v18->m_flEndTime;
                                  if ( m_flEndTime > v11 )
                                  {
                                    if ( v16 < m_Size - 1 )
                                    {
                                      v22 = (float *)v19[1];
                                      goto LABEL_29;
                                    }
                                    if ( w >= v10->m_Words.m_Size - 1 )
                                      goto LABEL_38;
                                    v23 = v10->m_Words.m_Memory.m_pMemory[w + 1];
                                    if ( v23->m_Phonemes.m_Size == 0 )
                                      goto LABEL_38;
                                    v22 = (float *)*v23->m_Phonemes.m_Memory.m_pMemory;
LABEL_29:
                                    if ( v22 != nullptr )
                                    {
                                      v24 = *v22;
                                      v25 = *v22 == m_flEndTime;
                                      v26 = m_flEndTime - m_flStartTime;
                                      if ( v25 )
                                        v24 = v22[1];
                                      v27 = v24 - v11;
                                      if ( v26 <= v27 )
                                        v28 = v26;
                                      else
                                        v28 = v27;
                                      if ( v13 <= v28 )
                                      {
                                        if ( v26 > v27 )
                                        {
                                          v13 = v27;
                                          goto LABEL_40;
                                        }
LABEL_39:
                                        v13 = v26;
LABEL_40:
                                        dt = LODWORD(v13);
                                      }
                                    }
                                    else
                                    {
LABEL_38:
                                      v26 = m_flEndTime - m_flStartTime;
                                      if ( v13 <= v26 )
                                        goto LABEL_39;
                                    }
                                  }
                                }
                                v29 = (float)(m_flStartTime - v11) * (float)(1.0 / v13);
                                v30 = (float)(v18->m_flEndTime - v11) * (float)(1.0 / v13);
                                if ( v29 < 1.0 && v30 > 0.0 )
                                {
                                  if ( v30 > 1.0 )
                                    v30 = 1.0;
                                  if ( v29 < 0.0 )
                                    v29 = 0.0;
                                  CFacePoserSound::AddViseme(
                                    this,
                                    intensity: emphasis_intensity,
                                    model,
                                    phoneme: v18->m_nPhonemeCode,
                                    scale: v30 - v29);
                                  v13 = *(float *)&dt;
                                  v11 = t;
                                }
                              }
                              m_Size = v14->m_Phonemes.m_Size;
                              if ( ++v16 >= m_Size )
                              {
                                v12 = w;
                                goto LABEL_50;
                              }
                              continue;
                            }
                          }
                        }
                      }
LABEL_51:
                      v4 = model;
                    }
                  }
                }
                ++v37;
                v7 = s + 1;
                s = v7;
              }
              while ( v7 < v4->m_mouth.m_nVoiceSources );
              v2 = i;
              v1 = c;
            }
          }
        }
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404000
// Name: public: virtual void CFacePoserSound::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::Update(CFacePoserSound *this, float dt)
{
  float v3; // xmm0_4

  if ( this->m_pAudio != nullptr )
  {
    CFacePoserSound::SetupWeights(this);
    ((void (__stdcall *)(_DWORD))this->m_pAudio->Update)(a1: LODWORD(this->m_flElapsedTime));
  }
  v3 = this->m_flElapsedTime + dt;
  ++g_nSoundFrameCount;
  this->m_flElapsedTime = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00404040
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
// Address: 0x004040A0
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
// Address: 0x00404120
// Name: private: virtual void CAudioWaveOutput::FreeChannel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::FreeChannel(CAudioWaveOutput *this, unsigned int channelIndex)
{
  CAudioMixer *v3; // ecx
  int v4; // eax
  StudioModel *v5; // ebx
  CAudioSource *v6; // eax
  CAudioMixer *v7; // ecx

  if ( channelIndex <= 0xF )
  {
    v3 = this->m_sourceList[channelIndex];
    if ( v3 != nullptr )
    {
      v4 = v3->GetModelIndex(this: v3);
      if ( v4 >= 0 )
      {
        v5 = models->GetStudioModel(this: models, a2: v4);
        if ( v5 != nullptr )
        {
          v6 = this->m_sourceList[channelIndex]->GetSource(this: this->m_sourceList[channelIndex]);
          CMouthInfo::RemoveSource(this: &v5->m_mouth, source: v6);
        }
      }
      CAudioWaveOutput::RemoveMixerChannelReferences(this, mixer: this->m_sourceList[channelIndex]);
      v7 = this->m_sourceList[channelIndex];
      if ( v7 != nullptr )
        ((void (__thiscall *)(CAudioMixer *, int))v7->dtr_CAudioMixer)(a1: v7, a2: 1);
      this->m_sourceList[channelIndex] = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004041B0
// Name: public: CFacePoserSound::~CFacePoserSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::~CFacePoserSound(CFacePoserSound *this)
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
  this->__vftable = (CFacePoserSound_vtbl *)&CFacePoserSound::`vftable';
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
// Address: 0x00404280
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
      CUtlMemory<VisibleStreamItem,int>::Grow(
        this: &buffer->m_Referenced.m_Memory,
        num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x00404310
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
// Address: 0x00404420
// Name: public: virtual int CAudioWaveOutput::SampleSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioWaveOutput::SampleSize(CAudioWaveOutput *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00404430
// Name: public: virtual int CAudioWaveOutput::SampleRate(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioWaveOutput::SampleRate(CAudioWaveOutput *this)
{
  return 44100;
}

//------------------------------------------------------------------------------
// Address: 0x00404440
// Name: public: virtual void CAudioWaveOutput::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioWaveOutput::Update(CAudioWaveOutput *this, float time)
{
  CAudioBuffer *EmptyBuffer; // eax
  CAudioBuffer *v4; // edi
  wavehdr_tag *hdr; // eax
  int v6; // esi
  CAudioDeviceSWMix *p_m_audioDevice; // esi
  CAudioMixer **m_sourceList; // eax
  CAudioMixer *v9; // esi
  int v10; // eax
  StudioModel *v11; // edi
  int v12; // eax
  int m_nVoiceSources; // edi
  int v14; // ecx
  CVoiceData *m_VoiceSources; // edx
  CChoreoScene *Scene; // eax
  CAudioSource *v17; // eax
  CAudioMixer_vtbl *v18; // edi
  int v19; // eax
  CAudioMixer_vtbl *v20; // edi
  int v21; // eax
  int v22; // eax
  CAudioMixer v23; // edi
  int v24; // eax
  int v25; // eax
  int v26; // eax
  __int16 **v27; // ecx
  int modelindex; // [esp+4h] [ebp-24h]
  CAudioBuffer *pBuffer; // [esp+8h] [ebp-20h]
  CAudioMixer **v30; // [esp+Ch] [ebp-1Ch]
  bool forward; // [esp+10h] [ebp-18h]
  bool bIgnorePhonemes; // [esp+14h] [ebp-14h]
  __int16 *pSamples; // [esp+18h] [ebp-10h]
  int tempCount; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  int sampleCount; // [esp+24h] [ebp-4h]
  StudioModel *model; // [esp+30h] [ebp+8h]
  StudioModel *modela; // [esp+30h] [ebp+8h]

  if ( this->m_deviceHandle == nullptr )
    return;
  if ( this->m_mixTime < 0.0 || this->m_baseTime > time )
  {
    this->m_baseTime = time;
    this->m_mixTime = 0.0;
  }
  if ( (float)(time - this->m_baseTime) <= this->m_mixTime )
    return;
  EmptyBuffer = CAudioWaveOutput::GetEmptyBuffer(this);
  v4 = EmptyBuffer;
  pBuffer = EmptyBuffer;
  if ( EmptyBuffer == nullptr )
    return;
  hdr = EmptyBuffer->hdr;
  if ( v4->hdr == nullptr )
    return;
  v6 = hdr->dwBufferLength >> 2;
  this->m_mixTime = (float)((float)v6 * 0.000022675737) + this->m_mixTime;
  pSamples = (__int16 *)v4->hdr->lpData;
  CAudioWaveOutput::SilenceBuffer(this, pSamples, sampleCount: v6);
  tempCount = v6;
  if ( v6 <= 0 )
    goto LABEL_44;
  p_m_audioDevice = &this->m_audioDevice;
  do
  {
    if ( tempCount <= p_m_audioDevice->MaxSampleCount(this: p_m_audioDevice) )
      sampleCount = tempCount;
    else
      sampleCount = p_m_audioDevice->MaxSampleCount(this: p_m_audioDevice);
    p_m_audioDevice->MixBegin(this: p_m_audioDevice);
    m_sourceList = this->m_sourceList;
    i = 0;
    v30 = this->m_sourceList;
    do
    {
      v9 = *m_sourceList;
      if ( *m_sourceList == nullptr )
        goto LABEL_41;
      v10 = v9->GetModelIndex(this: v9);
      modelindex = v10;
      if ( v10 >= 0 )
      {
        v11 = models->GetStudioModel(this: models, a2: v10);
        model = v11;
LABEL_20:
        if ( v11 != nullptr )
        {
          v12 = (int)v9->GetSource(this: v9);
          m_nVoiceSources = v11->m_mouth.m_nVoiceSources;
          v14 = 0;
          if ( m_nVoiceSources <= 0 )
            goto LABEL_28;
          m_VoiceSources = model->m_mouth.m_VoiceSources;
          while ( m_VoiceSources == nullptr || m_VoiceSources->m_pAudioSource != (CAudioSource *)v12 )
          {
            ++v14;
            ++m_VoiceSources;
            if ( v14 >= m_nVoiceSources )
              goto LABEL_28;
          }
          if ( v14 == -1 )
          {
LABEL_28:
            Scene = CChoreoView::GetScene(this: g_pChoreoView);
            bIgnorePhonemes = Scene != nullptr && CChoreoScene::ShouldIgnorePhonemes(this: Scene);
            v17 = v9->GetSource(this: v9);
            CMouthInfo::AddSource(this: &model->m_mouth, source: v17, bIgnorePhonemes);
            if ( modelindex < 0 )
            {
              v18 = v9->__vftable;
              v19 = models->GetIndexForStudioModel(this: models, a2: model);
              v18->SetModelIndex(this: v9, a2: v19);
            }
          }
        }
        goto LABEL_33;
      }
      if ( IFacePoserToolWindow::IsActiveTool(this: &g_pPhonemeEditor->IFacePoserToolWindow)
        || IFacePoserToolWindow::IsActiveTool(this: (IFacePoserToolWindow *)(`CUtlRBTree<CUtlSymbolTree::FileTreePath,int,bool (__cdecl *)(CUtlSymbolTree::FileTreePath const &,CUtlSymbolTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements
                                                                           + 12)) )
      {
        model = models->GetActiveStudioModel(this: models);
        v11 = model;
        goto LABEL_20;
      }
LABEL_33:
      modela = (StudioModel *)v9->GetSamplePosition(this: v9);
      forward = v9->GetDirection(this: v9);
      if ( v9->GetActive(this: v9) )
      {
        v20 = v9->__vftable;
        v21 = ((int (__thiscall *)(CAudioWaveOutput *, bool))this->SampleRate)(a1: this, a2: forward);
        v22 = ((int (__thiscall *)(CAudioMixer *, StudioModel *, int, int))v9->GetChannel)(
                a1: v9,
                a2: modela,
                a3: sampleCount,
                a4: v21);
        if ( ((unsigned __int8 (__thiscall *)(CAudioMixer *, CAudioDeviceSWMix *, int))v20->MixDataToDevice)(
               a1: v9,
               a2: &this->m_audioDevice,
               a3: v22) != 0 )
          CAudioWaveOutput::AddToReferencedList(this, mixer: v9, buffer: pBuffer);
        else
          v9->SetActive(this: v9, a2: false);
      }
      else if ( CAudioWaveOutput::IsSourceReferencedByActiveBuffer(this, mixer: v9) != 0 )
      {
        v23.__vftable = v9->__vftable;
        v24 = ((int (__thiscall *)(CAudioWaveOutput *, bool))this->SampleRate)(a1: this, a2: forward);
        v25 = ((int (__thiscall *)(CAudioMixer *, StudioModel *, int, int))v9->GetChannel)(
                a1: v9,
                a2: modela,
                a3: sampleCount,
                a4: v24);
        ((void (__thiscall *)(CAudioMixer *, int))v23.IncrementSamples)(a1: v9, a2: v25);
      }
      else if ( !v9->GetAutoDelete(this: v9) )
      {
        this->FreeChannel(this, a2: i);
      }
LABEL_41:
      m_sourceList = v30 + 1;
      ++i;
      ++v30;
    }
    while ( i < 16 );
    p_m_audioDevice = &this->m_audioDevice;
    CAudioDeviceSWMix::TransferBufferStereo16(this: &this->m_audioDevice, pOutput: pSamples, sampleCount);
    this->m_sampleIndex += sampleCount;
    tempCount -= sampleCount;
    pSamples += 2 * sampleCount;
  }
  while ( tempCount > 0 );
  v4 = pBuffer;
LABEL_44:
  v26 = this->GetOutputPosition(this);
  v27 = (__int16 **)v4->hdr;
  v4->submit_sample_count = v26;
  waveOutWrite(hwo: this->m_deviceHandle, pwh: (LPWAVEHDR)v27, cbwh: 0x20u);
}

//------------------------------------------------------------------------------
// Address: 0x00404760
// Name: private: class CAudioSource __near * CFacePoserSound::FindOrAddSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSource *__thiscall CFacePoserSound::FindOrAddSound(CFacePoserSound *this, const char *filename)
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
// Address: 0x004048C0
// Name: public: virtual void CFacePoserSound::PlaySoundA(class StudioModel __near *,float,char const __near *,class CAudioMixer __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFacePoserSound::PlaySoundA(
        CFacePoserSound *this@<ecx>,
        int a2@<esi>,
        StudioModel *model,
        float volume,
        const char *wavfile,
        CAudioMixer **ppMixer)
{
  CAudioSource *v7; // eax
  CAudioMixer *v8; // esi
  CAudioMixer v9; // edi
  int v10; // eax

  if ( this->m_pAudio != nullptr )
  {
    v7 = CFacePoserSound::FindOrAddSound(this, filename: wavfile);
    if ( v7 != nullptr )
    {
      v8 = (CAudioMixer *)((int (__thiscall *)(CAudioSource *, int))v7->CreateMixer)(a1: v7, a2);
      if ( ppMixer != nullptr )
        *ppMixer = v8;
      ((void (__thiscall *)(CAudioMixer *, _DWORD))v8->SetVolume)(a1: v8, a2: LODWORD(volume));
      this->m_pAudio->AddSource(this: this->m_pAudio, a2: v8);
      if ( model != nullptr )
      {
        v9.__vftable = v8->__vftable;
        v10 = models->GetIndexForStudioModel(this: models, a2: model);
        v9.SetModelIndex(this: v8, a2: v10);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404940
// Name: public: virtual void CFacePoserSound::PlayPartialSound(class StudioModel __near *,float,char const __near *,class CAudioMixer __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFacePoserSound::PlayPartialSound(
        CFacePoserSound *this@<ecx>,
        int a2@<esi>,
        StudioModel *model,
        float volume,
        const char *wavfile,
        CAudioMixer **ppMixer,
        int startSample,
        int endSample)
{
  CAudioSource *v9; // eax
  CAudioMixer *v10; // esi

  if ( this->m_pAudio != nullptr )
  {
    this->StopAll(this);
    v9 = CFacePoserSound::FindOrAddSound(this, filename: wavfile);
    if ( v9 != nullptr )
    {
      v10 = (CAudioMixer *)((int (__thiscall *)(CAudioSource *, int))v9->CreateMixer)(a1: v9, a2);
      if ( ppMixer != nullptr )
        *ppMixer = v10;
      ((void (__thiscall *)(CAudioMixer *, int))v10->SetSamplePosition)(a1: v10, a2: startSample);
      v10->SetLoopPosition(this: v10, a2: endSample);
      ((void (__thiscall *)(CAudioMixer *, _DWORD))v10->SetVolume)(a1: v10, a2: LODWORD(volume));
      this->m_pAudio->AddSource(this: this->m_pAudio, a2: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004049C0
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
// Address: 0x00404A80
// Name: public: virtual void CFacePoserSound::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFacePoserSound::Init(CFacePoserSound *this)
{
  CAudioOutput *v1; // eax
  CAudioWaveOutput *v3; // eax
  CAudioWaveOutput *v4; // eax

  v1 = (CAudioOutput *)dword_51D770;
  this->m_flElapsedTime = 0.0;
  if ( v1 == nullptr )
  {
    v3 = (CAudioWaveOutput *)operator new(nSize: 0x245Cu);
    if ( v3 != nullptr )
    {
      v4 = CAudioWaveOutput::CAudioWaveOutput(this: v3);
      this->m_pAudio = v4;
      dword_51D770 = (int)v4;
      return;
    }
    v1 = nullptr;
    dword_51D770 = 0;
  }
  this->m_pAudio = v1;
}
