// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/snd_wave_mixer.cpp
// Functions: 30
// ============================================================

#include "utils\hlfaceposer\snd_wave_mixer.h"

//------------------------------------------------------------------------------
// Address: 0x004010E0
// Name: public: virtual CAudioMixerWave::~CAudioMixerWave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::~CAudioMixerWave(CAudioMixerWave *this)
{
  CWaveData *m_pData; // ecx

  m_pData = this->m_pData;
  this->__vftable = (CAudioMixerWave_vtbl *)&CAudioMixerWave::`vftable';
  if ( m_pData != nullptr )
    ((void (__thiscall *)(CWaveData *, int))m_pData->dtr_CWaveData)(a1: m_pData, a2: 1);
  free(pMem: this->m_pChannel);
  this->__vftable = (CAudioMixerWave_vtbl *)&CAudioMixer::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00401110
// Name: public: virtual int CAudioMixerWave::GetOutputData(void __near * __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::GetOutputData(
        CAudioMixerWave *this,
        void **pData,
        int samplePosition,
        int sampleCount,
        BOOL forward)
{
  if ( samplePosition != this->m_sample )
  {
    this->m_sample = samplePosition;
    this->m_absoluteSample = samplePosition;
  }
  return this->m_pData->ReadSourceData(this: this->m_pData, a2: pData, a3: this->m_sample, a4: sampleCount, a5: forward);
}

//------------------------------------------------------------------------------
// Address: 0x00401150
// Name: public: virtual class CAudioSource __near * CAudioMixerWave::GetSource(void)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceWave *__thiscall CAudioMixerWave::GetSource(CAudioMixerWave *this)
{
  if ( this->m_pData != nullptr )
    return this->m_pData->Source(this: this->m_pData);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401170
// Name: public: virtual int CAudioMixerWave::GetScrubPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::GetScrubPosition(CAudioMixerWave *this)
{
  int result; // eax

  result = this->m_scrubSample;
  if ( result == -1 )
    return this->m_sample;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401180
// Name: public: virtual bool CAudioMixerWave::SetSamplePosition(int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioMixerWave::SetSamplePosition(CAudioMixerWave *this, int position, bool scrubbing)
{
  int v3; // eax

  v3 = position < 0 ? 0 : position;
  this->m_sample = v3;
  this->m_absoluteSample = v3;
  this->m_startpos = v3;
  if ( scrubbing )
    this->m_scrubSample = v3;
  else
    this->m_scrubSample = -1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004011C0
// Name: public: virtual void CAudioMixerWave::SetLoopPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetLoopPosition(CAudioMixerWave *this, int position)
{
  this->m_loop = position;
}

//------------------------------------------------------------------------------
// Address: 0x004011D0
// Name: public: virtual void CAudioMixerWave::SetModelIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetModelIndex(CAudioMixerWave *this, int index)
{
  this->m_nModelIndex = index;
}

//------------------------------------------------------------------------------
// Address: 0x004011E0
// Name: public: virtual int CAudioMixerWave::GetModelIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::GetModelIndex(CAudioMixerWave *this)
{
  return this->m_nModelIndex;
}

//------------------------------------------------------------------------------
// Address: 0x004011F0
// Name: public: virtual void CAudioMixerWave::SetDirection(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetDirection(CAudioMixerWave *this, bool forward)
{
  this->m_bForward = forward;
}

//------------------------------------------------------------------------------
// Address: 0x00401200
// Name: public: virtual bool CAudioMixerWave::GetDirection(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioMixerWave::GetDirection(CAudioMixerWave *this)
{
  return this->m_bForward;
}

//------------------------------------------------------------------------------
// Address: 0x00401210
// Name: public: virtual void CAudioMixerWave::SetAutoDelete(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetAutoDelete(CAudioMixerWave *this, bool autodelete)
{
  this->m_bAutoDelete = autodelete;
}

//------------------------------------------------------------------------------
// Address: 0x00401220
// Name: public: virtual bool CAudioMixerWave::GetAutoDelete(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioMixerWave::GetAutoDelete(CAudioMixerWave *this)
{
  return this->m_bAutoDelete;
}

//------------------------------------------------------------------------------
// Address: 0x00401230
// Name: public: virtual struct channel_s __near * CAudioMixerWave::GetChannel(void)
// Source: json
//------------------------------------------------------------------------------
channel_s *__thiscall CAudioMixerWave::GetChannel(CAudioMixerWave *this)
{
  return this->m_pChannel;
}

//------------------------------------------------------------------------------
// Address: 0x00401240
// Name: public: virtual void CAudioMixerWave::IncrementSamples(struct channel_s __near *,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::IncrementSamples(
        CAudioMixerWave *this,
        channel_s *pChannel,
        int startSample,
        int sampleCount,
        int outputRate,
        bool forward)
{
  CAudioSourceWave *v7; // eax
  int v8; // edi
  float v9; // xmm0_4
  int v10; // eax
  int v11; // eax

  v7 = this->m_pData->Source(this: this->m_pData);
  v8 = (int)(float)((float)v7->SampleRate(this: v7) * pChannel->pitch);
  v9 = (float)v8 / (float)outputRate;
  if ( !forward )
  {
    v10 = startSample - (int)(float)((float)sampleCount * v9);
    if ( v10 < 0 )
      return;
    this->SetSamplePosition(this, a2: v10 < 0 ? 0 : v10, a3: false);
    v9 = (float)v8 / (float)outputRate;
  }
  v11 = sampleCount;
  if ( sampleCount > 0 )
  {
    if ( outputRate != v8 )
      v11 = (int)(float)((float)sampleCount * v9);
    if ( forward )
    {
      this->m_sample += v11;
      this->m_absoluteSample += v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004012F0
// Name: public: virtual bool CAudioMixerWave::SkipSamples(struct channel_s __near *,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioMixerWave::SkipSamples(
        CAudioMixerWave *this,
        channel_s *pChannel,
        int startSample,
        int sampleCount,
        int outputRate,
        BOOL forward)
{
  CAudioSourceWave *v7; // eax
  int v8; // ebx
  int v9; // edi
  BOOL v10; // ecx
  int v11; // eax
  float v13; // xmm0_4
  int v14; // edi
  int v15; // eax
  int v16; // ecx
  float v17; // xmm0_4
  int v18; // eax
  int m_loop; // eax
  int inputSampleRate; // [esp+Ch] [ebp-8h]
  char *pData; // [esp+10h] [ebp-4h] BYREF
  float rate; // [esp+1Ch] [ebp+8h]

  v7 = this->m_pData->Source(this: this->m_pData);
  v8 = sampleCount;
  v9 = (int)(float)((float)v7->SampleRate(this: v7) * pChannel->pitch);
  inputSampleRate = v9;
  rate = (float)v9 / (float)outputRate;
  if ( sampleCount >= 1024 )
    v8 = 1024;
  v10 = forward;
  if ( !forward )
  {
    v11 = startSample - (int)(float)((float)v8 * (float)((float)v9 / (float)outputRate));
    if ( v11 < 0 )
      return 0;
    this->SetSamplePosition(this, a2: v11 < 0 ? 0 : v11, a3: false);
    v10 = forward;
  }
  if ( v8 <= 0 )
    return 1;
  while ( 1 )
  {
    pData = nullptr;
    if ( outputRate == v9 )
    {
      if ( !v10 )
        startSample = (startSample - v8) & ((startSample - v8 < 0) - 1);
      v18 = this->GetOutputData(this, a2: (void **)&pData, a3: startSample, a4: v8, a5: v10);
      if ( v18 == 0 )
        return 0;
      v14 = v18;
      v16 = v18;
    }
    else
    {
      v13 = (float)v8 * rate;
      v14 = (int)v13;
      if ( !v10 )
        startSample = (startSample - v14) & ((startSample - v14 < 0) - 1);
      v15 = this->GetOutputData(this, a2: (void **)&pData, a3: startSample, a4: (int)v13, a5: v10);
      if ( v15 == 0 )
        return 0;
      if ( v15 >= v14 )
      {
        v16 = v8;
      }
      else
      {
        v16 = (int)(float)((float)v15 / rate);
        v14 = v15;
      }
      v17 = (float)((float)v16 * rate) + (float)(this->m_fracOffset / 0x10000000);
      this->m_fracOffset = (int)(float)((float)(v17 - (float)(int)v17) * 268435460.0);
    }
    v8 -= v16;
    if ( forward )
    {
      this->m_sample += v14;
      this->m_absoluteSample += v14;
    }
    m_loop = this->m_loop;
    if ( m_loop != 0 && this->m_sample >= m_loop )
      this->SetSamplePosition(this, a2: this->m_startpos, a3: false);
    if ( v8 <= 0 )
      break;
    v9 = inputSampleRate;
    v10 = forward;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004014E0
// Name: public: virtual bool CAudioMixerWave::MixDataToDevice(class IAudioDevice __near *,struct channel_s __near *,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioMixerWave::MixDataToDevice(
        CAudioMixerWave *this,
        IAudioDevice *pDevice,
        channel_s *pChannel,
        char *startSample,
        int sampleCount,
        int outputRate,
        BOOL forward)
{
  CAudioSourceWave *v8; // eax
  int v9; // edi
  double v10; // st7
  char *v11; // eax
  int v12; // eax
  int (__thiscall *GetOutputData)(CAudioMixerWave *, void **, int, int, bool); // edx
  int v15; // ebx
  int v16; // eax
  float v17; // xmm0_4
  int v18; // eax
  int m_loop; // eax
  int inputSampleRate; // [esp+10h] [ebp-10h]
  int offset; // [esp+14h] [ebp-Ch]
  float rate; // [esp+18h] [ebp-8h]
  int startpos; // [esp+1Ch] [ebp-4h]

  offset = 0;
  v8 = this->m_pData->Source(this: this->m_pData);
  inputSampleRate = (int)(float)((float)v8->SampleRate(this: v8) * pChannel->pitch);
  v9 = sampleCount;
  v10 = (double)inputSampleRate / (double)outputRate;
  rate = v10;
  if ( sampleCount >= 1024 )
  {
    sampleCount = 1024;
    v9 = 1024;
  }
  v11 = startSample;
  startpos = (int)startSample;
  if ( !forward )
  {
    v12 = (int)&startSample[-(int)(float)((float)v9 * rate)];
    if ( v12 < 0 )
      return false;
    startpos = v12 < 0 ? 0 : v12;
    this->SetSamplePosition(this, a2: startpos, a3: false);
    v11 = (char *)startpos;
  }
  if ( v9 <= 0 )
    return true;
  while ( 1 )
  {
    GetOutputData = this->GetOutputData;
    startSample = nullptr;
    if ( outputRate != inputSampleRate )
      break;
    v18 = GetOutputData(this, a2: (void **)&startSample, a3: (int)v11, a4: v9, a5: forward);
    if ( v18 == 0 )
      return v9 <= 0;
    v9 = v18;
    v15 = v18;
    this->Mix(
      this,
      a2: pDevice,
      a3: pChannel,
      a4: startSample,
      a5: offset,
      a6: this->m_fracOffset,
      a7: 0x10000000u,
      a8: v18,
      a9: 0,
      a10: forward);
LABEL_17:
    offset += v9;
    sampleCount -= v9;
    if ( forward )
    {
      this->m_sample += v15;
      this->m_absoluteSample += v15;
    }
    m_loop = this->m_loop;
    if ( m_loop != 0 && this->m_sample >= m_loop )
      this->SetSamplePosition(this, a2: this->m_startpos, a3: false);
    if ( sampleCount <= 0 )
      return true;
    v9 = sampleCount;
    v11 = (char *)startpos;
  }
  v15 = (int)(float)((float)v9 * rate);
  v16 = GetOutputData(this, a2: (void **)&startSample, a3: (int)v11, a4: v15, a5: forward);
  if ( v16 != 0 )
  {
    if ( v16 < v15 )
    {
      v9 = (int)(float)((float)v16 / rate);
      v15 = v16;
    }
    this->Mix(
      this,
      a2: pDevice,
      a3: pChannel,
      a4: startSample,
      a5: offset,
      a6: this->m_fracOffset,
      a7: (__int64)(v10 * 268435460.0),
      a8: v9,
      a9: 0,
      a10: forward);
    v17 = (float)((float)v9 * rate) + (float)(this->m_fracOffset / 0x10000000);
    this->m_fracOffset = (int)(float)((float)(v17 - (float)(int)v17) * 268435460.0);
    goto LABEL_17;
  }
  v9 = sampleCount;
  return v9 <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401710
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x00401760
// Name: public: CAudioMixerWave::CAudioMixerWave(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave *__thiscall CAudioMixerWave::CAudioMixerWave(CAudioMixerWave *this, CWaveData *data)
{
  channel_s *v3; // eax

  this->m_pData = data;
  this->__vftable = (CAudioMixerWave_vtbl *)&CAudioMixerWave::`vftable';
  this->m_pChannel = nullptr;
  this->m_loop = 0;
  this->m_sample = 0;
  this->m_absoluteSample = 0;
  this->m_scrubSample = -1;
  this->m_fracOffset = 0;
  this->m_bActive = false;
  this->m_nModelIndex = -1;
  *(_WORD *)&this->m_bForward = 257;
  v3 = (channel_s *)operator new(nSize: 0x14u);
  this->m_pChannel = v3;
  v3->leftvol = 127;
  this->m_pChannel->rightvol = 127;
  this->m_pChannel->pitch = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004017D0
// Name: public: virtual void CAudioMixerWave::SetVolume(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetVolume(CAudioMixerWave *this, float volume)
{
  float v2; // xmm0_4
  int v3; // eax

  v2 = 0.0;
  if ( volume >= 0.0 )
  {
    v2 = 1.0;
    if ( volume <= 1.0 )
      v2 = volume;
  }
  v3 = (int)(float)(v2 * 127.0);
  this->m_pChannel->leftvol = v3;
  this->m_pChannel->rightvol = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00401810
// Name: public: CAudioMixerWave8Mono::CAudioMixerWave8Mono(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Mono *__thiscall CAudioMixerWave8Mono::CAudioMixerWave8Mono(
        CAudioMixerWave8Mono *this,
        CWaveData *data)
{
  channel_s *v3; // eax

  this->m_pData = data;
  this->__vftable = (CAudioMixerWave8Mono_vtbl *)&CAudioMixerWave::`vftable';
  this->m_pChannel = nullptr;
  this->m_loop = 0;
  this->m_sample = 0;
  this->m_absoluteSample = 0;
  this->m_scrubSample = -1;
  this->m_fracOffset = 0;
  this->m_bActive = false;
  this->m_nModelIndex = -1;
  *(_WORD *)&this->m_bForward = 257;
  v3 = (channel_s *)operator new(nSize: 0x14u);
  this->m_pChannel = v3;
  v3->leftvol = 127;
  this->m_pChannel->rightvol = 127;
  this->m_pChannel->pitch = 1.0;
  this->__vftable = (CAudioMixerWave8Mono_vtbl *)&CAudioMixerWave8Mono::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401880
// Name: public: virtual void CAudioMixerWave8Mono::Mix(class IAudioDevice __near *,struct channel_s __near *,void __near *,int,int,unsigned int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave8Mono::Mix(
        CAudioMixerWave8Mono *this,
        IAudioDevice *pDevice,
        channel_s *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress,
        BOOL forward)
{
  pDevice->Mix8Mono(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress,
    a9: forward);
}

//------------------------------------------------------------------------------
// Address: 0x00401910
// Name: public: CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Stereo *__thiscall CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(
        CAudioMixerWave8Stereo *this,
        CWaveData *data)
{
  channel_s *v3; // eax

  this->m_pData = data;
  this->__vftable = (CAudioMixerWave8Stereo_vtbl *)&CAudioMixerWave::`vftable';
  this->m_pChannel = nullptr;
  this->m_loop = 0;
  this->m_sample = 0;
  this->m_absoluteSample = 0;
  this->m_scrubSample = -1;
  this->m_fracOffset = 0;
  this->m_bActive = false;
  this->m_nModelIndex = -1;
  *(_WORD *)&this->m_bForward = 257;
  v3 = (channel_s *)operator new(nSize: 0x14u);
  this->m_pChannel = v3;
  v3->leftvol = 127;
  this->m_pChannel->rightvol = 127;
  this->m_pChannel->pitch = 1.0;
  this->__vftable = (CAudioMixerWave8Stereo_vtbl *)&CAudioMixerWave8Stereo::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401980
// Name: public: virtual void CAudioMixerWave8Stereo::Mix(class IAudioDevice __near *,struct channel_s __near *,void __near *,int,int,unsigned int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave8Stereo::Mix(
        CAudioMixerWave8Stereo *this,
        IAudioDevice *pDevice,
        channel_s *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress,
        BOOL forward)
{
  pDevice->Mix8Stereo(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress,
    a9: forward);
}

//------------------------------------------------------------------------------
// Address: 0x004019C0
// Name: public: CAudioMixerWave16Mono::CAudioMixerWave16Mono(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave16Mono *__thiscall CAudioMixerWave16Mono::CAudioMixerWave16Mono(
        CAudioMixerWave16Mono *this,
        CWaveData *data)
{
  channel_s *v3; // eax

  this->m_pData = data;
  this->__vftable = (CAudioMixerWave16Mono_vtbl *)&CAudioMixerWave::`vftable';
  this->m_pChannel = nullptr;
  this->m_loop = 0;
  this->m_sample = 0;
  this->m_absoluteSample = 0;
  this->m_scrubSample = -1;
  this->m_fracOffset = 0;
  this->m_bActive = false;
  this->m_nModelIndex = -1;
  *(_WORD *)&this->m_bForward = 257;
  v3 = (channel_s *)operator new(nSize: 0x14u);
  this->m_pChannel = v3;
  v3->leftvol = 127;
  this->m_pChannel->rightvol = 127;
  this->m_pChannel->pitch = 1.0;
  this->__vftable = (CAudioMixerWave16Mono_vtbl *)&CAudioMixerWave16Mono::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401A30
// Name: public: virtual void CAudioMixerWave16Mono::Mix(class IAudioDevice __near *,struct channel_s __near *,void __near *,int,int,unsigned int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave16Mono::Mix(
        CAudioMixerWave16Mono *this,
        IAudioDevice *pDevice,
        channel_s *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress,
        BOOL forward)
{
  pDevice->Mix16Mono(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress,
    a9: forward);
}

//------------------------------------------------------------------------------
// Address: 0x00401A70
// Name: public: CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave16Stereo *__thiscall CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(
        CAudioMixerWave16Stereo *this,
        CWaveData *data)
{
  channel_s *v3; // eax

  this->m_pData = data;
  this->__vftable = (CAudioMixerWave16Stereo_vtbl *)&CAudioMixerWave::`vftable';
  this->m_pChannel = nullptr;
  this->m_loop = 0;
  this->m_sample = 0;
  this->m_absoluteSample = 0;
  this->m_scrubSample = -1;
  this->m_fracOffset = 0;
  this->m_bActive = false;
  this->m_nModelIndex = -1;
  *(_WORD *)&this->m_bForward = 257;
  v3 = (channel_s *)operator new(nSize: 0x14u);
  this->m_pChannel = v3;
  v3->leftvol = 127;
  this->m_pChannel->rightvol = 127;
  this->m_pChannel->pitch = 1.0;
  this->__vftable = (CAudioMixerWave16Stereo_vtbl *)&CAudioMixerWave16Stereo::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401AE0
// Name: public: virtual void CAudioMixerWave16Stereo::Mix(class IAudioDevice __near *,struct channel_s __near *,void __near *,int,int,unsigned int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave16Stereo::Mix(
        CAudioMixerWave16Stereo *this,
        IAudioDevice *pDevice,
        channel_s *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress,
        BOOL forward)
{
  pDevice->Mix16Stereo(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress,
    a9: forward);
}

//------------------------------------------------------------------------------
// Address: 0x00401B20
// Name: class CAudioMixer __near * CreateWaveMixer(class CWaveData __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave16Stereo *__cdecl CreateWaveMixer(CWaveData *data, int format, int channels, int bits)
{
  CAudioMixerWave8Mono *v4; // eax

  if ( format == 1 )
  {
    v4 = (CAudioMixerWave8Mono *)operator new(nSize: 0x34u);
    if ( channels <= 1 )
    {
      if ( bits == 8 )
      {
        if ( v4 != nullptr )
          return (CAudioMixerWave16Stereo *)CAudioMixerWave8Mono::CAudioMixerWave8Mono(this: v4, data);
      }
      else if ( v4 != nullptr )
      {
        return (CAudioMixerWave16Stereo *)CAudioMixerWave16Mono::CAudioMixerWave16Mono(
                                            this: (CAudioMixerWave16Mono *)v4,
                                            data);
      }
    }
    else if ( bits == 8 )
    {
      if ( v4 != nullptr )
        return (CAudioMixerWave16Stereo *)CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(
                                            this: (CAudioMixerWave8Stereo *)v4,
                                            data);
    }
    else if ( v4 != nullptr )
    {
      return CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(this: (CAudioMixerWave16Stereo *)v4, data);
    }
  }
  else if ( format == 2 )
  {
    return (CAudioMixerWave16Stereo *)CreateADPCMMixer(data);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00448650
// Name: public: virtual int CAudioMixerWave::GetSamplePosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::GetSamplePosition(CAudioMixerWave *this)
{
  return this->m_sample;
}

//------------------------------------------------------------------------------
// Address: 0x00482780
// Name: public: virtual bool CAudioMixerWave::GetActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioMixerWave::GetActive(CAudioMixerWave *this)
{
  return this->m_bActive;
}

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x00401250
// Name: public: virtual struct channel_s __near * CAudioMixerWave::GetChannel(void)
// Source: json
//------------------------------------------------------------------------------
channel_s *__thiscall CAudioMixerWave::GetChannel(CAudioMixerWave *this)
{
  return this->m_pChannel;
}

//------------------------------------------------------------------------------
// Address: 0x00401260
// Name: public: virtual void CAudioMixerWave::IncrementSamples(struct channel_s __near *,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::IncrementSamples(
        CAudioMixerWave *this,
        channel_s *pChannel,
        int startSample,
        int sampleCount,
        int outputRate,
        bool forward)
{
  CAudioSourceWave *v7; // eax
  int v8; // edi
  float v9; // xmm0_4
  int v10; // eax
  int v11; // eax

  v7 = this->m_pData->Source(this: this->m_pData);
  v8 = (int)(float)((float)v7->SampleRate(this: v7) * pChannel->pitch);
  v9 = (float)v8 / (float)outputRate;
  if ( !forward )
  {
    v10 = startSample - (int)(float)((float)sampleCount * v9);
    if ( v10 < 0 )
      return;
    this->SetSamplePosition(this, a2: v10 < 0 ? 0 : v10, a3: false);
    v9 = (float)v8 / (float)outputRate;
  }
  v11 = sampleCount;
  if ( sampleCount > 0 )
  {
    if ( outputRate != v8 )
      v11 = (int)(float)((float)sampleCount * v9);
    if ( forward )
    {
      this->m_sample += v11;
      this->m_absoluteSample += v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401310
// Name: public: virtual bool CAudioMixerWave::SkipSamples(struct channel_s __near *,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioMixerWave::SkipSamples(
        CAudioMixerWave *this,
        channel_s *pChannel,
        int startSample,
        int sampleCount,
        int outputRate,
        BOOL forward)
{
  CAudioSourceWave *v7; // eax
  int v8; // ebx
  int v9; // edi
  BOOL v10; // ecx
  int v11; // eax
  float v13; // xmm0_4
  int v14; // edi
  int v15; // eax
  int v16; // ecx
  float v17; // xmm0_4
  int v18; // eax
  int m_loop; // eax
  int inputSampleRate; // [esp+Ch] [ebp-8h]
  char *pData; // [esp+10h] [ebp-4h] BYREF
  float rate; // [esp+1Ch] [ebp+8h]

  v7 = this->m_pData->Source(this: this->m_pData);
  v8 = sampleCount;
  v9 = (int)(float)((float)v7->SampleRate(this: v7) * pChannel->pitch);
  inputSampleRate = v9;
  rate = (float)v9 / (float)outputRate;
  if ( sampleCount >= 1024 )
    v8 = 1024;
  v10 = forward;
  if ( !forward )
  {
    v11 = startSample - (int)(float)((float)v8 * (float)((float)v9 / (float)outputRate));
    if ( v11 < 0 )
      return 0;
    this->SetSamplePosition(this, a2: v11 < 0 ? 0 : v11, a3: false);
    v10 = forward;
  }
  if ( v8 <= 0 )
    return 1;
  while ( 1 )
  {
    pData = nullptr;
    if ( outputRate == v9 )
    {
      if ( !v10 )
        startSample = (startSample - v8) & ((startSample - v8 < 0) - 1);
      v18 = this->GetOutputData(this, a2: (void **)&pData, a3: startSample, a4: v8, a5: v10);
      if ( v18 == 0 )
        return 0;
      v14 = v18;
      v16 = v18;
    }
    else
    {
      v13 = (float)v8 * rate;
      v14 = (int)v13;
      if ( !v10 )
        startSample = (startSample - v14) & ((startSample - v14 < 0) - 1);
      v15 = this->GetOutputData(this, a2: (void **)&pData, a3: startSample, a4: (int)v13, a5: v10);
      if ( v15 == 0 )
        return 0;
      if ( v15 >= v14 )
      {
        v16 = v8;
      }
      else
      {
        v16 = (int)(float)((float)v15 / rate);
        v14 = v15;
      }
      v17 = (float)((float)v16 * rate) + (float)(this->m_fracOffset / 0x10000000);
      this->m_fracOffset = (int)(float)((float)(v17 - (float)(int)v17) * 268435460.0);
    }
    v8 -= v16;
    if ( forward )
    {
      this->m_sample += v14;
      this->m_absoluteSample += v14;
    }
    m_loop = this->m_loop;
    if ( m_loop != 0 && this->m_sample >= m_loop )
      this->SetSamplePosition(this, a2: this->m_startpos, a3: false);
    if ( v8 <= 0 )
      break;
    v9 = inputSampleRate;
    v10 = forward;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401500
// Name: public: virtual bool CAudioMixerWave::MixDataToDevice(class IAudioDevice __near *,struct channel_s __near *,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioMixerWave::MixDataToDevice(
        CAudioMixerWave *this,
        IAudioDevice *pDevice,
        channel_s *pChannel,
        char *startSample,
        int sampleCount,
        int outputRate,
        BOOL forward)
{
  CAudioSourceWave *v8; // eax
  int v9; // edi
  double v10; // st7
  char *v11; // eax
  int v12; // eax
  int (__thiscall *GetOutputData)(CAudioMixerWave *, void **, int, int, bool); // edx
  int v15; // ebx
  int v16; // eax
  float v17; // xmm0_4
  int v18; // eax
  int m_loop; // eax
  int inputSampleRate; // [esp+10h] [ebp-10h]
  int offset; // [esp+14h] [ebp-Ch]
  float rate; // [esp+18h] [ebp-8h]
  int startpos; // [esp+1Ch] [ebp-4h]

  offset = 0;
  v8 = this->m_pData->Source(this: this->m_pData);
  inputSampleRate = (int)(float)((float)v8->SampleRate(this: v8) * pChannel->pitch);
  v9 = sampleCount;
  v10 = (double)inputSampleRate / (double)outputRate;
  rate = v10;
  if ( sampleCount >= 1024 )
  {
    sampleCount = 1024;
    v9 = 1024;
  }
  v11 = startSample;
  startpos = (int)startSample;
  if ( !forward )
  {
    v12 = (int)&startSample[-(int)(float)((float)v9 * rate)];
    if ( v12 < 0 )
      return false;
    startpos = v12 < 0 ? 0 : v12;
    this->SetSamplePosition(this, a2: startpos, a3: false);
    v11 = (char *)startpos;
  }
  if ( v9 <= 0 )
    return true;
  while ( 1 )
  {
    GetOutputData = this->GetOutputData;
    startSample = nullptr;
    if ( outputRate != inputSampleRate )
      break;
    v18 = GetOutputData(this, a2: (void **)&startSample, a3: (int)v11, a4: v9, a5: forward);
    if ( v18 == 0 )
      return v9 <= 0;
    v9 = v18;
    v15 = v18;
    this->Mix(
      this,
      a2: pDevice,
      a3: pChannel,
      a4: startSample,
      a5: offset,
      a6: this->m_fracOffset,
      a7: 0x10000000u,
      a8: v18,
      a9: 0,
      a10: forward);
LABEL_17:
    offset += v9;
    sampleCount -= v9;
    if ( forward )
    {
      this->m_sample += v15;
      this->m_absoluteSample += v15;
    }
    m_loop = this->m_loop;
    if ( m_loop != 0 && this->m_sample >= m_loop )
      this->SetSamplePosition(this, a2: this->m_startpos, a3: false);
    if ( sampleCount <= 0 )
      return true;
    v9 = sampleCount;
    v11 = (char *)startpos;
  }
  v15 = (int)(float)((float)v9 * rate);
  v16 = GetOutputData(this, a2: (void **)&startSample, a3: (int)v11, a4: v15, a5: forward);
  if ( v16 != 0 )
  {
    if ( v16 < v15 )
    {
      v9 = (int)(float)((float)v16 / rate);
      v15 = v16;
    }
    this->Mix(
      this,
      a2: pDevice,
      a3: pChannel,
      a4: startSample,
      a5: offset,
      a6: this->m_fracOffset,
      a7: (__int64)(v10 * 268435460.0),
      a8: v9,
      a9: 0,
      a10: forward);
    v17 = (float)((float)v9 * rate) + (float)(this->m_fracOffset / 0x10000000);
    this->m_fracOffset = (int)(float)((float)(v17 - (float)(int)v17) * 268435460.0);
    goto LABEL_17;
  }
  v9 = sampleCount;
  return v9 <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401730
// Name: public: CAudioMixerWave::CAudioMixerWave(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave *__thiscall CAudioMixerWave::CAudioMixerWave(CAudioMixerWave *this, CWaveData *data)
{
  channel_s *v3; // eax

  this->m_pData = data;
  this->__vftable = (CAudioMixerWave_vtbl *)&CAudioMixerWave::`vftable';
  this->m_pChannel = nullptr;
  this->m_loop = 0;
  this->m_sample = 0;
  this->m_absoluteSample = 0;
  this->m_scrubSample = -1;
  this->m_fracOffset = 0;
  this->m_bActive = false;
  this->m_nModelIndex = -1;
  *(_WORD *)&this->m_bForward = 257;
  v3 = (channel_s *)operator new(nSize: 0x14u);
  this->m_pChannel = v3;
  v3->leftvol = 127;
  this->m_pChannel->rightvol = 127;
  this->m_pChannel->pitch = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004017F0
// Name: public: virtual void CAudioMixerWave::SetVolume(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetVolume(CAudioMixerWave *this, float volume)
{
  float v2; // xmm0_4
  int v3; // eax

  v2 = 0.0;
  if ( volume >= 0.0 )
  {
    v2 = 1.0;
    if ( volume <= 1.0 )
      v2 = volume;
  }
  v3 = (int)(float)(v2 * 127.0);
  this->m_pChannel->leftvol = v3;
  this->m_pChannel->rightvol = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00401830
// Name: public: CAudioMixerWave8Mono::CAudioMixerWave8Mono(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Mono *__thiscall CAudioMixerWave8Mono::CAudioMixerWave8Mono(
        CAudioMixerWave8Mono *this,
        CWaveData *data)
{
  channel_s *v3; // eax

  this->m_pData = data;
  this->__vftable = (CAudioMixerWave8Mono_vtbl *)&CAudioMixerWave::`vftable';
  this->m_pChannel = nullptr;
  this->m_loop = 0;
  this->m_sample = 0;
  this->m_absoluteSample = 0;
  this->m_scrubSample = -1;
  this->m_fracOffset = 0;
  this->m_bActive = false;
  this->m_nModelIndex = -1;
  *(_WORD *)&this->m_bForward = 257;
  v3 = (channel_s *)operator new(nSize: 0x14u);
  this->m_pChannel = v3;
  v3->leftvol = 127;
  this->m_pChannel->rightvol = 127;
  this->m_pChannel->pitch = 1.0;
  this->__vftable = (CAudioMixerWave8Mono_vtbl *)&CAudioMixerWave8Mono::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004018A0
// Name: public: virtual void CAudioMixerWave8Mono::Mix(class IAudioDevice __near *,struct channel_s __near *,void __near *,int,int,unsigned int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave8Mono::Mix(
        CAudioMixerWave8Mono *this,
        IAudioDevice *pDevice,
        channel_s *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress,
        BOOL forward)
{
  pDevice->Mix8Mono(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress,
    a9: forward);
}

//------------------------------------------------------------------------------
// Address: 0x004018E0
// Name: public: CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Stereo *__thiscall CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(
        CAudioMixerWave8Stereo *this,
        CWaveData *data)
{
  channel_s *v3; // eax

  this->m_pData = data;
  this->__vftable = (CAudioMixerWave8Stereo_vtbl *)&CAudioMixerWave::`vftable';
  this->m_pChannel = nullptr;
  this->m_loop = 0;
  this->m_sample = 0;
  this->m_absoluteSample = 0;
  this->m_scrubSample = -1;
  this->m_fracOffset = 0;
  this->m_bActive = false;
  this->m_nModelIndex = -1;
  *(_WORD *)&this->m_bForward = 257;
  v3 = (channel_s *)operator new(nSize: 0x14u);
  this->m_pChannel = v3;
  v3->leftvol = 127;
  this->m_pChannel->rightvol = 127;
  this->m_pChannel->pitch = 1.0;
  this->__vftable = (CAudioMixerWave8Stereo_vtbl *)&CAudioMixerWave8Stereo::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401950
// Name: public: virtual void CAudioMixerWave8Stereo::Mix(class IAudioDevice __near *,struct channel_s __near *,void __near *,int,int,unsigned int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave8Stereo::Mix(
        CAudioMixerWave8Stereo *this,
        IAudioDevice *pDevice,
        channel_s *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress,
        BOOL forward)
{
  pDevice->Mix8Stereo(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress,
    a9: forward);
}

//------------------------------------------------------------------------------
// Address: 0x00401990
// Name: public: CAudioMixerWave16Mono::CAudioMixerWave16Mono(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave16Mono *__thiscall CAudioMixerWave16Mono::CAudioMixerWave16Mono(
        CAudioMixerWave16Mono *this,
        CWaveData *data)
{
  channel_s *v3; // eax

  this->m_pData = data;
  this->__vftable = (CAudioMixerWave16Mono_vtbl *)&CAudioMixerWave::`vftable';
  this->m_pChannel = nullptr;
  this->m_loop = 0;
  this->m_sample = 0;
  this->m_absoluteSample = 0;
  this->m_scrubSample = -1;
  this->m_fracOffset = 0;
  this->m_bActive = false;
  this->m_nModelIndex = -1;
  *(_WORD *)&this->m_bForward = 257;
  v3 = (channel_s *)operator new(nSize: 0x14u);
  this->m_pChannel = v3;
  v3->leftvol = 127;
  this->m_pChannel->rightvol = 127;
  this->m_pChannel->pitch = 1.0;
  this->__vftable = (CAudioMixerWave16Mono_vtbl *)&CAudioMixerWave16Mono::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401A00
// Name: public: virtual void CAudioMixerWave16Mono::Mix(class IAudioDevice __near *,struct channel_s __near *,void __near *,int,int,unsigned int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave16Mono::Mix(
        CAudioMixerWave16Mono *this,
        IAudioDevice *pDevice,
        channel_s *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress,
        BOOL forward)
{
  pDevice->Mix16Mono(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress,
    a9: forward);
}

//------------------------------------------------------------------------------
// Address: 0x00401A40
// Name: public: CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave16Stereo *__thiscall CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(
        CAudioMixerWave16Stereo *this,
        CWaveData *data)
{
  channel_s *v3; // eax

  this->m_pData = data;
  this->__vftable = (CAudioMixerWave16Stereo_vtbl *)&CAudioMixerWave::`vftable';
  this->m_pChannel = nullptr;
  this->m_loop = 0;
  this->m_sample = 0;
  this->m_absoluteSample = 0;
  this->m_scrubSample = -1;
  this->m_fracOffset = 0;
  this->m_bActive = false;
  this->m_nModelIndex = -1;
  *(_WORD *)&this->m_bForward = 257;
  v3 = (channel_s *)operator new(nSize: 0x14u);
  this->m_pChannel = v3;
  v3->leftvol = 127;
  this->m_pChannel->rightvol = 127;
  this->m_pChannel->pitch = 1.0;
  this->__vftable = (CAudioMixerWave16Stereo_vtbl *)&CAudioMixerWave16Stereo::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401AB0
// Name: public: virtual void CAudioMixerWave16Stereo::Mix(class IAudioDevice __near *,struct channel_s __near *,void __near *,int,int,unsigned int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave16Stereo::Mix(
        CAudioMixerWave16Stereo *this,
        IAudioDevice *pDevice,
        channel_s *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress,
        BOOL forward)
{
  pDevice->Mix16Stereo(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress,
    a9: forward);
}

//------------------------------------------------------------------------------
// Address: 0x00401AF0
// Name: class CAudioMixer __near * CreateWaveMixer(class CWaveData __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave16Stereo *__cdecl CreateWaveMixer(CWaveData *data, int format, int channels, int bits)
{
  CAudioMixerWave8Mono *v4; // eax

  if ( format == 1 )
  {
    v4 = (CAudioMixerWave8Mono *)operator new(nSize: 0x34u);
    if ( channels <= 1 )
    {
      if ( bits == 8 )
      {
        if ( v4 != nullptr )
          return (CAudioMixerWave16Stereo *)CAudioMixerWave8Mono::CAudioMixerWave8Mono(this: v4, data);
      }
      else if ( v4 != nullptr )
      {
        return (CAudioMixerWave16Stereo *)CAudioMixerWave16Mono::CAudioMixerWave16Mono(
                                            this: (CAudioMixerWave16Mono *)v4,
                                            data);
      }
    }
    else if ( bits == 8 )
    {
      if ( v4 != nullptr )
        return (CAudioMixerWave16Stereo *)CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(
                                            this: (CAudioMixerWave8Stereo *)v4,
                                            data);
    }
    else if ( v4 != nullptr )
    {
      return CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(this: (CAudioMixerWave16Stereo *)v4, data);
    }
  }
  else if ( format == 2 )
  {
    return (CAudioMixerWave16Stereo *)CreateADPCMMixer(data);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004036B0
// Name: public: virtual int CAudioMixerWave::GetSamplePosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::GetSamplePosition(CAudioMixerWave *this)
{
  return this->m_sample;
}

} // namespace localization_check
