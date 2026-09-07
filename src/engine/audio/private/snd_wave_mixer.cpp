// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_wave_mixer.cpp
// Functions: 27
// ============================================================

#include "engine\audio\private\snd_wave_mixer.h"

//------------------------------------------------------------------------------
// Address: 0x100363D0
// Name: public: virtual int CAudioMixerWave::GetPositionForSave(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::GetPositionForSave(CSentenceMixer *this)
{
  return this->GetSamplePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003D030
// Name: public: virtual bool CAudioMixerWave::IsReadyToMix(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioMixerWave::IsReadyToMix(CAudioMixerWave *this)
{
  return this->m_pData->IsReadyToMix(this: this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1003D040
// Name: public: virtual int CAudioMixerWave::GetOutputData(void __near * __near *,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall CAudioMixerWave::GetOutputData(CAudioMixerWave *this, void **pData, int sampleCount, char *copyBuf)
{
  __int64 result; // rax
  bool v6; // cf

  result = ((int (__thiscall *)(IWaveData *, void **, _DWORD, _DWORD, int, char *))this->m_pData->ReadSourceData)(
             a1: this->m_pData,
             a2: pData,
             a3: this->m_sample_max_loaded,
             a4: HIDWORD(this->m_sample_max_loaded),
             a5: sampleCount,
             a6: copyBuf);
  this->m_sample_max_loaded += (int)result;
  v6 = __CFADD__((_DWORD)result, this->m_sample_loaded_index);
  LODWORD(this->m_sample_loaded_index) += result;
  HIDWORD(this->m_sample_loaded_index) += ((int)result >> 31) + v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003D080
// Name: public: virtual class CAudioSource __near * CAudioMixerWave::GetSource(void)
// Source: json
//------------------------------------------------------------------------------
CAudioSource *__thiscall CAudioMixerWave::GetSource(CAudioMixerWave *this)
{
  if ( this->m_pData != nullptr )
    return this->m_pData->Source(this: this->m_pData);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003D0A0
// Name: public: virtual void CAudioMixerWave::SetSampleStart(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetSampleStart(CAudioMixerWave *this, int newPosition)
{
  CAudioSource *v3; // eax

  v3 = this->GetSource(this);
  if ( v3 != nullptr )
    newPosition = v3->ZeroCrossingAfter(this: v3, a2: newPosition);
  LODWORD(this->m_sample_loaded_index) = newPosition;
  this->m_fsample_index = (double)newPosition;
  HIDWORD(this->m_sample_loaded_index) = newPosition >> 31;
  this->m_sample_max_loaded = newPosition + 1LL;
}

//------------------------------------------------------------------------------
// Address: 0x1003D0F0
// Name: public: virtual void CAudioMixerWave::SetSampleEnd(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetSampleEnd(CAudioMixerWave *this, int newEndPosition)
{
  int v2; // edi
  CAudioSource *v4; // eax

  v2 = newEndPosition;
  if ( newEndPosition == 0 )
  {
    v2 = 1;
    newEndPosition = 1;
  }
  v4 = this->GetSource(this);
  if ( v4 != nullptr )
    newEndPosition = v4->ZeroCrossingBefore(this: v4, a2: v2);
  if ( this->m_fsample_index > (double)newEndPosition )
    newEndPosition = (int)this->m_fsample_index;
  this->m_forcedEndSample = (double)newEndPosition;
}

//------------------------------------------------------------------------------
// Address: 0x1003D150
// Name: double RoundToFixedPoint(double,int,bool)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RoundToFixedPoint(long double rate, int samples, bool bInterpolated_pitch)
{
  long double v3; // st7
  double v4; // st7

  if ( bInterpolated_pitch )
    v3 = rate * 16384.0;
  else
    v3 = rate * 268435456.0;
  v4 = (double)((unsigned int)(__int64)v3 * (__int64)samples);
  if ( bInterpolated_pitch )
    return v4 * 0.00006103515625;
  else
    return v4 * 0.000000003725290298461914;
}

//------------------------------------------------------------------------------
// Address: 0x1003D1E0
// Name: public: virtual bool CAudioMixerWave::ShouldContinueMixing(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioMixerWave::ShouldContinueMixing(CAudioMixerWave *this)
{
  return !this->m_finished;
}

//------------------------------------------------------------------------------
// Address: 0x1003D1F0
// Name: public: virtual float CAudioMixerWave::ModifyPitch(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAudioMixerWave::ModifyPitch(CAudioMixerWave *this, float pitch)
{
  return pitch;
}

//------------------------------------------------------------------------------
// Address: 0x1003D200
// Name: public: virtual float CAudioMixerWave::GetVolumeScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAudioMixerWave::GetVolumeScale(CAudioMixerWave *this)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1003D210
// Name: public: CAudioMixerWave::CAudioMixerWave(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave *__thiscall CAudioMixerWave::CAudioMixerWave(CAudioMixerWave *this, IWaveData *data)
{
  this->m_fsample_index = 0.0;
  this->m_pData = data;
  this->m_forcedEndSample = 0.0;
  this->__vftable = (CAudioMixerWave_vtbl *)&CAudioMixerWave::`vftable';
  this->m_sample_max_loaded = 0;
  this->m_sample_loaded_index = -1;
  this->m_finished = false;
  this->m_delaySamples = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D250
// Name: public: virtual void CAudioMixerWave::SetPositionFromSaved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetPositionFromSaved(CSentenceMixer *this, int savedPosition)
{
  this->SetSampleStart(this, a2: savedPosition);
}

//------------------------------------------------------------------------------
// Address: 0x1003D260
// Name: public: virtual CAudioMixerWave::~CAudioMixerWave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::~CAudioMixerWave(CAudioMixerWave *this)
{
  IWaveData *m_pData; // ecx
  int v3; // eax
  IWaveData *v4; // ecx

  m_pData = this->m_pData;
  this->__vftable = (CAudioMixerWave_vtbl *)&CAudioMixerWave::`vftable';
  if ( m_pData != nullptr )
  {
    v3 = (int)m_pData->Source(this: m_pData);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int, CAudioMixerWave *))(*(_DWORD *)v3 + 92))(a1: v3, a2: this);
  }
  v4 = this->m_pData;
  if ( v4 != nullptr )
    ((void (__thiscall *)(IWaveData *, int))v4->dtr_IWaveData)(a1: v4, a2: 1);
  this->__vftable = (CAudioMixerWave_vtbl *)&CAudioMixer::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1003D2A0
// Name: public: char __near * CAudioMixerWave::LoadMixBuffer(struct channel_t __near *,int,int __near *,char __near * const)
// Source: json
//------------------------------------------------------------------------------
portable_samplepair_t *__thiscall CAudioMixerWave::LoadMixBuffer(
        CAudioMixerWave *this,
        channel_t *pChannel,
        int sample_load_request,
        int *pSamplesLoaded,
        char *copyBuf)
{
  CAudioMixerWave *v5; // ebx
  int (__thiscall *GetOutputData)(CAudioMixerWave *, void **, int, char *); // edx
  int m_sample_loaded_index_high; // edi
  char *v8; // eax
  int v9; // eax
  char *m_pszString; // eax
  int v12; // eax
  portable_samplepair_t *v13; // esi
  int v14; // ecx
  int v15; // edi
  int v16; // edi
  CSfxTable *sfx; // ecx
  const char *v18; // eax
  _BYTE *v19; // esi
  int v20; // edi
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int v24; // ebx
  int v25; // edi
  int v26; // edi
  double X[2]; // [esp+14h] [ebp-128h] BYREF
  char nameBuf[260]; // [esp+28h] [ebp-114h]
  portable_samplepair_t *v29; // [esp+12Ch] [ebp-10h]
  void *dest; // [esp+130h] [ebp-Ch] BYREF
  __int64 sample_loaded_index; // [esp+134h] [ebp-8h]
  char *pData; // [esp+144h] [ebp+8h]

  v5 = this;
  GetOutputData = this->GetOutputData;
  m_sample_loaded_index_high = HIDWORD(this->m_sample_loaded_index);
  *(_DWORD *)&nameBuf[248] = this->m_sample_loaded_index;
  *(_DWORD *)&nameBuf[240] = this;
  dest = nullptr;
  *(_DWORD *)&nameBuf[252] = m_sample_loaded_index_high;
  HIDWORD(sample_loaded_index) = ((int (__stdcall *)(void **, int, char *))GetOutputData)(
                                   a1: &dest,
                                   a2: sample_load_request,
                                   a3: copyBuf);
  if ( HIDWORD(sample_loaded_index) != 0 || sample_load_request == 0 )
  {
    v12 = v5->GetMixSampleSize(this: v5);
    v13 = g_temppaintbuffer;
    LODWORD(sample_loaded_index) = v12;
    v29 = g_temppaintbuffer + 4096;
    if ( g_temppaintbuffer != nullptr )
    {
      *(_DWORD *)&nameBuf[244] = pChannel->sample_prev;
      *(_DWORD *)&nameBuf[256] = pChannel->sample_prev;
      if ( m_sample_loaded_index_high >= 0 )
      {
        *(double *)&nameBuf[248] = (double)*(__int64 *)&nameBuf[248];
        if ( floor(X: v5->m_fsample_index) <= *(double *)&nameBuf[248] )
        {
          if ( *(double *)&nameBuf[248] <= v5->m_fsample_index )
          {
            *(_DWORD *)&nameBuf[256] += sample_loaded_index;
            v14 = 1;
          }
          else
          {
            v14 = 2;
          }
          v15 = v14 * sample_loaded_index;
          if ( v14 * (int)sample_loaded_index >= (char *)v29 - (char *)v13 )
            v15 = (char *)v29 - (char *)v13;
          _V_memcpy(dest: v13, src: *(const void **)&nameBuf[256], count: v15);
          v13 = (portable_samplepair_t *)((char *)v13 + v15);
        }
      }
      v16 = HIDWORD(sample_loaded_index) * sample_loaded_index;
      if ( HIDWORD(sample_loaded_index) * (_DWORD)sample_loaded_index == 0 || dest != nullptr )
      {
        if ( v16 >= (char *)v29 - (char *)v13 )
          v16 = (char *)v29 - (char *)v13;
        _V_memcpy(dest: v13, src: dest, count: v16);
        v19 = (char *)v13 + v16;
        if ( SHIDWORD(sample_loaded_index) < sample_load_request )
        {
          v20 = -1;
          for ( pData = nullptr; (int)pData < 10000; ++pData )
          {
            if ( v20 == 0 )
              break;
            if ( SHIDWORD(sample_loaded_index) >= sample_load_request )
              goto LABEL_45;
            v21 = v5->GetOutputData(
                    this: v5,
                    a2: &dest,
                    a3: sample_load_request - HIDWORD(sample_loaded_index),
                    a4: copyBuf);
            v20 = v21;
            if ( v21 != 0 )
            {
              v22 = sample_loaded_index * v21;
              if ( v22 != 0 && dest == nullptr )
              {
                _Warning(
                  a1: "CAudioMixerWave::LoadMixBuffer:  samples_loaded_retry * samplesize = %i but pData == NULL\n",
                  (_DWORD)sample_loaded_index * v20);
                *pSamplesLoaded = 0;
                return nullptr;
              }
              v23 = v22;
              if ( v22 >= (char *)v29 - v19 )
                v23 = (char *)v29 - v19;
              _V_memcpy(dest: v19, src: dest, count: v23);
              v19 += v23;
              v5 = *(CAudioMixerWave **)&nameBuf[240];
              HIDWORD(sample_loaded_index) += v20;
            }
          }
          if ( SHIDWORD(sample_loaded_index) < sample_load_request )
          {
            v24 = sample_load_request - HIDWORD(sample_loaded_index);
            v25 = sample_loaded_index * (sample_load_request - HIDWORD(sample_loaded_index));
            if ( (char *)v29 - v19 < v25 )
              v25 = (char *)v29 - v19;
            _V_memset(dest: v19, fill: 0, count: v25);
            v19 += v25;
            HIDWORD(sample_loaded_index) += v24;
          }
        }
LABEL_45:
        v26 = HIDWORD(sample_loaded_index);
        if ( SHIDWORD(sample_loaded_index) >= 2 )
          _V_memcpy(dest: *(void **)&nameBuf[244], src: &v19[-2 * sample_loaded_index], count: 2 * sample_loaded_index);
        *pSamplesLoaded = v26;
        return g_temppaintbuffer;
      }
      else
      {
        sfx = pChannel->sfx;
        v18 = defaultValue;
        if ( sfx != nullptr )
          v18 = (const char *)sfx->getname(this: sfx, a2: (char *)X, a3: 260u);
        _Warning(
          a1: "CAudioMixerWave::LoadMixBuffer: '%s' samples_loaded * samplesize = %i but pData == NULL\n",
          v18,
          v16);
        *pSamplesLoaded = 0;
        return nullptr;
      }
    }
    else
    {
      _Warning(a1: "LoadMixBuffer: no paint buffer\n");
      *pSamplesLoaded = 0;
      return nullptr;
    }
  }
  else
  {
    *pSamplesLoaded = 0;
    if ( (snd_find_channel.m_nFlags & 0x1000) != 0
      || (v8 = snd_find_channel.m_pParent->m_Value.m_pszString) != nullptr && *v8 != 0 )
    {
      v9 = (int)v5->GetSource(this: v5);
      (*(void (__thiscall **)(int, double *, int))(*(_DWORD *)v9 + 112))(a1: v9, a2: X, a3: 260);
      if ( (snd_find_channel.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = snd_find_channel.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = (char *)defaultValue;
      }
      if ( V_stristr(pStr: (char *)X, pSearch: m_pszString) != nullptr )
        _Msg(
          a1: "%s(%d): Sound '%s' is finished or accumulated too much latency.\n",
          "audio\\private\\snd_wave_mixer.cpp",
          336,
          (const char *)X);
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D5D0
// Name: public: int CAudioMixerWave::MixDataToDevice_(class IAudioDevice __near *,struct channel_t __near *,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::MixDataToDevice_(
        CAudioMixerWave *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        int sampleCount,
        int outputRate,
        int outputOffset,
        bool bSkipAllMixing)
{
  IWaveData *m_pData; // ecx
  IWaveData_vtbl *v10; // edx
  int v11; // eax
  channel_t *v12; // edi
  long double v13; // st7
  long double m_forcedEndSample; // st6
  int v15; // ebx
  long double MaxRate; // st7
  int m_delaySamples; // eax
  CAudioMixerWave_vtbl *v18; // edx
  int v19; // eax
  char *MixBuffer; // edi
  __int64 v21; // rax
  int v22; // ecx
  int v23; // eax
  long double v24; // st7
  char v25[32]; // [esp+3Ch] [ebp-1054h] BYREF
  long double v26; // [esp+103Ch] [ebp-54h]
  long double m_fsample_index; // [esp+1044h] [ebp-4Ch]
  long double v28; // [esp+104Ch] [ebp-44h]
  __int64 v29; // [esp+1054h] [ebp-3Ch]
  long double v30; // [esp+105Ch] [ebp-34h]
  int v31; // [esp+1068h] [ebp-28h]
  __int64 v32; // [esp+106Ch] [ebp-24h]
  int X[2]; // [esp+1074h] [ebp-1Ch] BYREF
  int v34; // [esp+107Ch] [ebp-14h]
  int v35; // [esp+1080h] [ebp-10h]
  bool v36[8]; // [esp+1084h] [ebp-Ch]
  char v37; // [esp+10A7h] [ebp+17h]

  if ( this->m_finished )
    return 0;
  m_pData = this->m_pData;
  v10 = m_pData->__vftable;
  v31 = outputOffset;
  v11 = (int)v10->Source(this: m_pData);
  v12 = pChannel;
  *(_DWORD *)&v36[4] = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 20))(a1: v11);
  v13 = (double)*(int *)&v36[4] * pChannel->pitch / (double)outputRate;
  v26 = v13;
  if ( this->m_forcedEndSample == 0.0
    || (double)(int)((double)sampleCount * v13) + this->m_fsample_index < this->m_forcedEndSample )
  {
    v15 = sampleCount;
  }
  else
  {
    m_forcedEndSample = this->m_forcedEndSample;
    this->m_finished = true;
    v15 = (int)((m_forcedEndSample - this->m_fsample_index) / v13);
    sampleCount = v15;
  }
  if ( v15 > 0 )
  {
    while ( 1 )
    {
      m_fsample_index = this->m_fsample_index;
      v37 = 1;
      v36[4] = FUseHighQualityPitch(pChannel: v12);
      if ( v15 >= 1020 )
        v15 = 1020;
      MaxRate = MIX_GetMaxRate(rate: v26, sampleCount: v15);
      m_delaySamples = this->m_delaySamples;
      v30 = MaxRate;
      if ( m_delaySamples <= 0 )
      {
        *(double *)X = RoundToFixedPoint(rate: MaxRate, samples: v15 - 1, bInterpolated_pitch: v36[4])
                     + this->m_fsample_index;
        v21 = (unsigned __int64)ceil(X: *(double *)X);
        v22 = v21;
        v29 = v21;
        if ( *(double *)X >= (double)v21 )
          v22 = v21 + 1;
        MixBuffer = CAudioMixerWave::LoadMixBuffer(
                      this,
                      pChannel: v12,
                      sample_load_request: v22 - LODWORD(this->m_sample_loaded_index),
                      pSamplesLoaded: &X[1],
                      copyBuf: v25);
      }
      else
      {
        if ( m_delaySamples < v15 )
          v15 = m_delaySamples;
        v18 = this->__vftable;
        this->m_delaySamples = m_delaySamples - v15;
        v19 = v18->GetMixSampleSize(this);
        MixBuffer = (char *)g_temppaintbuffer;
        memset(dst: (unsigned __int8 *)g_temppaintbuffer, value: 0, count: v15 * v19);
        v37 = 0;
        v30 = 1.0;
      }
      v35 = v15;
      if ( MixBuffer == nullptr )
        break;
      SND_MouthEnvelopeFollower(pChannel, pData: MixBuffer, count: v15);
      v28 = this->m_fsample_index - floor(X: this->m_fsample_index);
      if ( !bSkipAllMixing )
      {
        X[1] = MIX_GetCurrentPaintbufferIndex();
        v23 = 0;
        *(_DWORD *)v36 = 0;
        v34 = 0;
        do
        {
          if ( *(&g_paintBuffers->factive + v23) )
          {
            MIX_SetCurrentPaintbuffer(ipaintbuffer: *(int *)v36);
            v32 = (__int64)(v30 * 268435456.0);
            this->Mix(
              this,
              a2: pDevice,
              a3: pChannel,
              a4: MixBuffer,
              a5: outputOffset,
              a6: (int)(268435456.0 * v28),
              a7: v32,
              a8: v15,
              a9: 0);
            v15 = v35;
            v23 = v34;
          }
          ++*(_DWORD *)v36;
          v23 += 312;
          v34 = v23;
        }
        while ( v23 < 1872 );
        MIX_SetCurrentPaintbuffer(ipaintbuffer: X[1]);
      }
      if ( v37 != 0 )
      {
        v24 = RoundToFixedPoint(rate: v30, samples: v15, bInterpolated_pitch: v36[4]);
        this->m_fsample_index = v24 + m_fsample_index;
      }
      outputOffset += v15;
      sampleCount -= v15;
      if ( sampleCount <= 0 )
        return outputOffset - v31;
      v15 = sampleCount;
      v12 = pChannel;
    }
    if ( sampleCount > 0 )
      this->m_finished = true;
  }
  return outputOffset - v31;
}

//------------------------------------------------------------------------------
// Address: 0x1003D880
// Name: public: CAudioMixerWave8Mono::CAudioMixerWave8Mono(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Mono *__thiscall CAudioMixerWave8Mono::CAudioMixerWave8Mono(
        CAudioMixerWave8Mono *this,
        IWaveData *data)
{
  this->m_fsample_index = 0.0;
  this->m_pData = data;
  this->m_forcedEndSample = 0.0;
  this->m_sample_max_loaded = 0;
  this->m_sample_loaded_index = -1;
  this->m_finished = false;
  this->m_delaySamples = 0;
  this->__vftable = (CAudioMixerWave8Mono_vtbl *)&CAudioMixerWave8Mono::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D8C0
// Name: public: virtual void CAudioMixerWave8Mono::Mix(class IAudioDevice __near *,struct channel_t __near *,void __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave8Mono::Mix(
        CAudioMixerWave8Mono *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress)
{
  pDevice->Mix8Mono(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress);
}

//------------------------------------------------------------------------------
// Address: 0x1003D8F0
// Name: public: CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Stereo *__thiscall CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(
        CAudioMixerWave8Stereo *this,
        IWaveData *data)
{
  this->m_fsample_index = 0.0;
  this->m_pData = data;
  this->m_forcedEndSample = 0.0;
  this->m_sample_max_loaded = 0;
  this->m_sample_loaded_index = -1;
  this->m_finished = false;
  this->m_delaySamples = 0;
  this->__vftable = (CAudioMixerWave8Stereo_vtbl *)&CAudioMixerWave8Stereo::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D930
// Name: public: virtual void CAudioMixerWave8Stereo::Mix(class IAudioDevice __near *,struct channel_t __near *,void __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave8Stereo::Mix(
        CAudioMixerWave8Stereo *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress)
{
  pDevice->Mix8Stereo(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress);
}

//------------------------------------------------------------------------------
// Address: 0x1003D960
// Name: public: CAudioMixerWave16Mono::CAudioMixerWave16Mono(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave16Mono *__thiscall CAudioMixerWave16Mono::CAudioMixerWave16Mono(
        CAudioMixerWave16Mono *this,
        IWaveData *data)
{
  this->m_fsample_index = 0.0;
  this->m_pData = data;
  this->m_forcedEndSample = 0.0;
  this->m_sample_max_loaded = 0;
  this->m_sample_loaded_index = -1;
  this->m_finished = false;
  this->m_delaySamples = 0;
  this->__vftable = (CAudioMixerWave16Mono_vtbl *)&CAudioMixerWave16Mono::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D9A0
// Name: public: virtual void CAudioMixerWave16Mono::Mix(class IAudioDevice __near *,struct channel_t __near *,void __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave16Mono::Mix(
        CAudioMixerWave16Mono *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress)
{
  pDevice->Mix16Mono(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress);
}

//------------------------------------------------------------------------------
// Address: 0x1003D9E0
// Name: public: CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave16Stereo *__thiscall CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(
        CAudioMixerWave16Stereo *this,
        IWaveData *data)
{
  this->m_fsample_index = 0.0;
  this->m_pData = data;
  this->m_forcedEndSample = 0.0;
  this->m_sample_max_loaded = 0;
  this->m_sample_loaded_index = -1;
  this->m_finished = false;
  this->m_delaySamples = 0;
  this->__vftable = (CAudioMixerWave16Stereo_vtbl *)&CAudioMixerWave16Stereo::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003DA20
// Name: public: virtual void CAudioMixerWave16Stereo::Mix(class IAudioDevice __near *,struct channel_t __near *,void __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave16Stereo::Mix(
        CAudioMixerWave16Stereo *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress)
{
  pDevice->Mix16Stereo(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress);
}

//------------------------------------------------------------------------------
// Address: 0x1003DA50
// Name: class CAudioMixer __near * CreateWaveMixer(class IWaveData __near *,int,int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Mono *__cdecl CreateWaveMixer(IWaveData *data, int format, int channels, int bits)
{
  CAudioMixerWave8Mono *v5; // eax

  if ( format == 1 )
  {
    v5 = (CAudioMixerWave8Mono *)MemAlloc_Alloc(nSize: 0x38u);
    if ( channels <= 1 )
    {
      if ( bits == 8 )
      {
        if ( v5 != nullptr )
          return CAudioMixerWave8Mono::CAudioMixerWave8Mono(this: v5, data);
      }
      else if ( v5 != nullptr )
      {
        return (CAudioMixerWave8Mono *)CAudioMixerWave16Mono::CAudioMixerWave16Mono(
                                         this: (CAudioMixerWave16Mono *)v5,
                                         data);
      }
    }
    else if ( bits == 8 )
    {
      if ( v5 != nullptr )
        return (CAudioMixerWave8Mono *)CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(
                                         this: (CAudioMixerWave8Stereo *)v5,
                                         data);
    }
    else if ( v5 != nullptr )
    {
      return (CAudioMixerWave8Mono *)CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(
                                       this: (CAudioMixerWave16Stereo *)v5,
                                       data);
    }
  }
  else if ( format == 2 )
  {
    return (CAudioMixerWave8Mono *)CreateADPCMMixer(data);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003DAD0
// Name: public: virtual int CAudioMixerWave::SkipSamples(struct channel_t __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::SkipSamples(
        CAudioMixerWave *this,
        channel_t *pChannel,
        int sampleCount,
        int outputRate,
        int outputOffset)
{
  CAudioSource *v6; // eax
  int result; // eax
  float flTempPitch; // [esp+10h] [ebp+8h]

  v6 = this->GetSource(this);
  if ( v6->GetType(this: v6) == 1 && this->IsSetSampleStartSupported(this) )
  {
    this->SetSampleStart(this, a2: sampleCount);
    return sampleCount;
  }
  else
  {
    flTempPitch = pChannel->pitch;
    pChannel->pitch = 1.0;
    result = CAudioMixerWave::MixDataToDevice_(
               this,
               pDevice: nullptr,
               pChannel,
               sampleCount,
               outputRate,
               outputOffset,
               bSkipAllMixing: true);
    pChannel->pitch = flTempPitch;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003DB60
// Name: public: virtual int CAudioMixerWave::MixDataToDevice(class IAudioDevice __near *,struct channel_t __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::MixDataToDevice(
        CAudioMixerWave *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        int sampleCount,
        int outputRate,
        int outputOffset)
{
  return CAudioMixerWave::MixDataToDevice_(
           this,
           pDevice,
           pChannel,
           sampleCount,
           outputRate,
           outputOffset,
           bSkipAllMixing: false);
}

//------------------------------------------------------------------------------
// Address: 0x102DC640
// Name: public: virtual int CAudioMixerWave::GetSamplePosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::GetSamplePosition(CVTFTexture *this)
{
  return this->m_nHeight;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10036110
// Name: public: virtual void CAudioMixerWave::SetPositionFromSaved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetPositionFromSaved(CSentenceMixer *this, int savedPosition)
{
  this->SetSampleStart(this, a2: savedPosition);
}

//------------------------------------------------------------------------------
// Address: 0x1003CCC0
// Name: public: virtual bool CAudioMixerWave::IsReadyToMix(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioMixerWave::IsReadyToMix(CAudioMixerWave *this)
{
  return this->m_pData->IsReadyToMix(this: this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1003CCD0
// Name: public: virtual int CAudioMixerWave::GetOutputData(void __near * __near *,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall CAudioMixerWave::GetOutputData(CAudioMixerWave *this, void **pData, int sampleCount, char *copyBuf)
{
  __int64 result; // rax
  bool v6; // cf

  result = ((int (__thiscall *)(IWaveData *, void **, _DWORD, _DWORD, int, char *))this->m_pData->ReadSourceData)(
             a1: this->m_pData,
             a2: pData,
             a3: this->m_sample_max_loaded,
             a4: HIDWORD(this->m_sample_max_loaded),
             a5: sampleCount,
             a6: copyBuf);
  this->m_sample_max_loaded += (int)result;
  v6 = __CFADD__((_DWORD)result, this->m_sample_loaded_index);
  LODWORD(this->m_sample_loaded_index) += result;
  HIDWORD(this->m_sample_loaded_index) += ((int)result >> 31) + v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003CD10
// Name: public: virtual class CAudioSource __near * CAudioMixerWave::GetSource(void)
// Source: json
//------------------------------------------------------------------------------
CAudioSource *__thiscall CAudioMixerWave::GetSource(CAudioMixerWave *this)
{
  if ( this->m_pData != nullptr )
    return this->m_pData->Source(this: this->m_pData);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003CD40
// Name: public: virtual void CAudioMixerWave::SetSampleStart(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetSampleStart(CAudioMixerWave *this, int newPosition)
{
  CAudioSource *v3; // eax

  v3 = this->GetSource(this);
  if ( v3 != nullptr )
    newPosition = v3->ZeroCrossingAfter(this: v3, a2: newPosition);
  LODWORD(this->m_sample_loaded_index) = newPosition;
  this->m_fsample_index = (double)newPosition;
  HIDWORD(this->m_sample_loaded_index) = newPosition >> 31;
  this->m_sample_max_loaded = newPosition + 1LL;
}

//------------------------------------------------------------------------------
// Address: 0x1003CD90
// Name: public: virtual void CAudioMixerWave::SetSampleEnd(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::SetSampleEnd(CAudioMixerWave *this, int newEndPosition)
{
  int v2; // edi
  CAudioSource *v4; // eax

  v2 = newEndPosition;
  if ( newEndPosition == 0 )
  {
    v2 = 1;
    newEndPosition = 1;
  }
  v4 = this->GetSource(this);
  if ( v4 != nullptr )
    newEndPosition = v4->ZeroCrossingBefore(this: v4, a2: v2);
  if ( this->m_fsample_index > (double)newEndPosition )
    newEndPosition = (int)this->m_fsample_index;
  this->m_forcedEndSample = (double)newEndPosition;
}

//------------------------------------------------------------------------------
// Address: 0x1003CDF0
// Name: double RoundToFixedPoint(double,int,bool)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RoundToFixedPoint(long double rate, int samples, bool bInterpolated_pitch)
{
  long double v3; // st7
  double v4; // st7

  if ( bInterpolated_pitch )
    v3 = rate * 16384.0;
  else
    v3 = rate * 268435456.0;
  v4 = (double)((unsigned int)(__int64)v3 * (__int64)samples);
  if ( bInterpolated_pitch )
    return v4 * 0.00006103515625;
  else
    return v4 * 0.000000003725290298461914;
}

//------------------------------------------------------------------------------
// Address: 0x1003CE80
// Name: public: virtual bool CAudioMixerWave::ShouldContinueMixing(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAudioMixerWave::ShouldContinueMixing(CAudioMixerWave *this)
{
  return !this->m_finished;
}

//------------------------------------------------------------------------------
// Address: 0x1003CE90
// Name: public: virtual float CAudioMixerWave::ModifyPitch(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAudioMixerWave::ModifyPitch(CAudioMixerWave *this, float pitch)
{
  return pitch;
}

//------------------------------------------------------------------------------
// Address: 0x1003CEA0
// Name: public: virtual float CAudioMixerWave::GetVolumeScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAudioMixerWave::GetVolumeScale(CAudioMixerWave *this)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1003CEB0
// Name: public: CAudioMixerWave::CAudioMixerWave(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave *__thiscall CAudioMixerWave::CAudioMixerWave(CAudioMixerWave *this, IWaveData *data)
{
  this->m_fsample_index = 0.0;
  this->m_pData = data;
  this->m_forcedEndSample = 0.0;
  this->__vftable = (CAudioMixerWave_vtbl *)&CAudioMixerWave::`vftable';
  this->m_sample_max_loaded = 0;
  this->m_sample_loaded_index = -1;
  this->m_finished = false;
  this->m_delaySamples = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003CEF0
// Name: public: virtual int CAudioMixerWave::GetPositionForSave(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::GetPositionForSave(CSentenceMixer *this)
{
  return this->GetSamplePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003CF00
// Name: public: virtual CAudioMixerWave::~CAudioMixerWave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave::~CAudioMixerWave(CAudioMixerWave *this)
{
  IWaveData *m_pData; // ecx
  int v3; // eax
  IWaveData *v4; // ecx

  m_pData = this->m_pData;
  this->__vftable = (CAudioMixerWave_vtbl *)&CAudioMixerWave::`vftable';
  if ( m_pData != nullptr )
  {
    v3 = (int)m_pData->Source(this: m_pData);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int, CAudioMixerWave *))(*(_DWORD *)v3 + 92))(a1: v3, a2: this);
  }
  v4 = this->m_pData;
  if ( v4 != nullptr )
    ((void (__thiscall *)(IWaveData *, int))v4->dtr_IWaveData)(a1: v4, a2: 1);
  this->__vftable = (CAudioMixerWave_vtbl *)&CAudioMixer::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1003CF40
// Name: public: char __near * CAudioMixerWave::LoadMixBuffer(struct channel_t __near *,int,int __near *,char __near * const)
// Source: json
//------------------------------------------------------------------------------
portable_samplepair_t *__thiscall CAudioMixerWave::LoadMixBuffer(
        CAudioMixerWave *this,
        channel_t *pChannel,
        int sample_load_request,
        int *pSamplesLoaded,
        char *copyBuf)
{
  CAudioMixerWave *v5; // ebx
  int (__thiscall *GetOutputData)(CAudioMixerWave *, void **, int, char *); // edx
  int m_sample_loaded_index_high; // edi
  char *v8; // eax
  int v9; // eax
  char *m_pszString; // eax
  int v12; // eax
  portable_samplepair_t *v13; // esi
  int v14; // ecx
  int v15; // edi
  int v16; // edi
  CSfxTable *sfx; // ecx
  const char *v18; // eax
  _BYTE *v19; // esi
  int v20; // edi
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int v24; // ebx
  int v25; // edi
  int v26; // edi
  char nameBuf[260]; // [esp+20h] [ebp-128h] BYREF
  CAudioMixerWave *v28; // [esp+124h] [ebp-24h]
  void *dest; // [esp+128h] [ebp-20h]
  __int64 sample_loaded_index; // [esp+12Ch] [ebp-1Ch]
  char *pSample; // [esp+134h] [ebp-14h]
  const char *pCopyBufferEnd; // [esp+138h] [ebp-10h]
  char *pData; // [esp+13Ch] [ebp-Ch] BYREF
  int samplesize; // [esp+140h] [ebp-8h]
  int samples_loaded; // [esp+144h] [ebp-4h]
  int k; // [esp+150h] [ebp+8h]

  v5 = this;
  GetOutputData = this->GetOutputData;
  m_sample_loaded_index_high = HIDWORD(this->m_sample_loaded_index);
  LODWORD(sample_loaded_index) = this->m_sample_loaded_index;
  v28 = this;
  pData = nullptr;
  HIDWORD(sample_loaded_index) = m_sample_loaded_index_high;
  samples_loaded = ((int (__stdcall *)(char **, int, char *))GetOutputData)(
                     a1: &pData,
                     a2: sample_load_request,
                     a3: copyBuf);
  if ( samples_loaded != 0 || sample_load_request == 0 )
  {
    v12 = v5->GetMixSampleSize(this: v5);
    v13 = g_temppaintbuffer;
    samplesize = v12;
    pCopyBufferEnd = (const char *)&g_temppaintbuffer[4096];
    if ( g_temppaintbuffer != nullptr )
    {
      dest = pChannel->sample_prev;
      pSample = pChannel->sample_prev;
      if ( m_sample_loaded_index_high >= 0 )
      {
        *(double *)&sample_loaded_index = (double)sample_loaded_index;
        if ( floor(X: v5->m_fsample_index) <= *(double *)&sample_loaded_index )
        {
          if ( *(double *)&sample_loaded_index <= v5->m_fsample_index )
          {
            pSample += samplesize;
            v14 = 1;
          }
          else
          {
            v14 = 2;
          }
          v15 = v14 * samplesize;
          if ( v14 * samplesize >= pCopyBufferEnd - (const char *)v13 )
            v15 = pCopyBufferEnd - (const char *)v13;
          _V_memcpy(dest: v13, src: pSample, count: v15);
          v13 = (portable_samplepair_t *)((char *)v13 + v15);
        }
      }
      v16 = samples_loaded * samplesize;
      if ( samples_loaded * samplesize == 0 || pData != nullptr )
      {
        if ( v16 >= pCopyBufferEnd - (const char *)v13 )
          v16 = pCopyBufferEnd - (const char *)v13;
        _V_memcpy(dest: v13, src: pData, count: v16);
        v19 = (char *)v13 + v16;
        if ( samples_loaded < sample_load_request )
        {
          v20 = -1;
          for ( k = 0; k < 10000; ++k )
          {
            if ( v20 == 0 )
              break;
            if ( samples_loaded >= sample_load_request )
              goto LABEL_45;
            v21 = v5->GetOutputData(
                    this: v5,
                    a2: (void **)&pData,
                    a3: sample_load_request - samples_loaded,
                    a4: copyBuf);
            v20 = v21;
            if ( v21 != 0 )
            {
              v22 = samplesize * v21;
              if ( v22 != 0 && pData == nullptr )
              {
                _Warning(
                  a1: "CAudioMixerWave::LoadMixBuffer:  samples_loaded_retry * samplesize = %i but pData == NULL\n",
                  samplesize * v20);
                *pSamplesLoaded = 0;
                return nullptr;
              }
              v23 = v22;
              if ( v22 >= pCopyBufferEnd - v19 )
                v23 = pCopyBufferEnd - v19;
              _V_memcpy(dest: v19, src: pData, count: v23);
              v19 += v23;
              v5 = v28;
              samples_loaded += v20;
            }
          }
          if ( samples_loaded < sample_load_request )
          {
            v24 = sample_load_request - samples_loaded;
            v25 = samplesize * (sample_load_request - samples_loaded);
            if ( pCopyBufferEnd - v19 < v25 )
              v25 = pCopyBufferEnd - v19;
            _V_memset(dest: v19, fill: 0, count: v25);
            v19 += v25;
            samples_loaded += v24;
          }
        }
LABEL_45:
        v26 = samples_loaded;
        if ( samples_loaded >= 2 )
          _V_memcpy(dest, src: &v19[-2 * samplesize], count: 2 * samplesize);
        *pSamplesLoaded = v26;
        return g_temppaintbuffer;
      }
      else
      {
        sfx = pChannel->sfx;
        v18 = defaultValue;
        if ( sfx != nullptr )
          v18 = (const char *)sfx->getname(this: sfx, a2: nameBuf, a3: 260u);
        _Warning(
          a1: "CAudioMixerWave::LoadMixBuffer: '%s' samples_loaded * samplesize = %i but pData == NULL\n",
          v18,
          v16);
        *pSamplesLoaded = 0;
        return nullptr;
      }
    }
    else
    {
      _Warning(a1: "LoadMixBuffer: no paint buffer\n");
      *pSamplesLoaded = 0;
      return nullptr;
    }
  }
  else
  {
    *pSamplesLoaded = 0;
    if ( (snd_find_channel.m_nFlags & 0x1000) != 0
      || (v8 = snd_find_channel.m_pParent->m_Value.m_pszString) != nullptr && *v8 != 0 )
    {
      v9 = (int)v5->GetSource(this: v5);
      (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v9 + 112))(a1: v9, a2: nameBuf, a3: 260);
      if ( (snd_find_channel.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = snd_find_channel.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = (char *)defaultValue;
      }
      if ( V_stristr(pStr: nameBuf, pSearch: m_pszString) != nullptr )
        _Msg(
          a1: "%s(%d): Sound '%s' is finished or accumulated too much latency.\n",
          "..\\engine\\audio\\private\\snd_wave_mixer.cpp",
          336,
          nameBuf);
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D270
// Name: public: int CAudioMixerWave::MixDataToDevice_(class IAudioDevice __near *,struct channel_t __near *,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::MixDataToDevice_(
        CAudioMixerWave *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        int sampleCount,
        int outputRate,
        int outputOffset,
        bool bSkipAllMixing)
{
  IWaveData *m_pData; // ecx
  IWaveData_vtbl *v10; // edx
  int v11; // eax
  channel_t *v12; // edi
  double v13; // st7
  long double m_forcedEndSample; // st6
  int v15; // ebx
  double MaxRate; // st7
  int m_delaySamples; // eax
  CAudioMixerWave_vtbl *v18; // edx
  int v19; // eax
  portable_samplepair_t *MixBuffer; // edi
  __int64 v21; // rax
  int v22; // ecx
  int v23; // eax
  double v24; // st7
  char copyBuf[4096]; // [esp+3Ch] [ebp-1054h] BYREF
  double rate; // [esp+103Ch] [ebp-54h]
  long double m_fsample_index; // [esp+1044h] [ebp-4Ch]
  long double v28; // [esp+104Ch] [ebp-44h]
  __int64 v29; // [esp+1054h] [ebp-3Ch]
  long double v30; // [esp+105Ch] [ebp-34h]
  int v31; // [esp+1068h] [ebp-28h]
  __int64 v32; // [esp+106Ch] [ebp-24h]
  int pSamplesLoaded[2]; // [esp+1074h] [ebp-1Ch] BYREF
  int v34; // [esp+107Ch] [ebp-14h]
  int v35; // [esp+1080h] [ebp-10h]
  int ipaintbuffer; // [esp+1084h] [ebp-Ch]
  bool bInterpolated_pitch[4]; // [esp+1088h] [ebp-8h]
  char v38; // [esp+10A7h] [ebp+17h]

  if ( this->m_finished )
    return 0;
  m_pData = this->m_pData;
  v10 = m_pData->__vftable;
  v31 = outputOffset;
  v11 = (int)v10->Source(this: m_pData);
  v12 = pChannel;
  *(_DWORD *)bInterpolated_pitch = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 20))(a1: v11);
  v13 = (double)*(int *)bInterpolated_pitch * pChannel->pitch / (double)outputRate;
  rate = v13;
  if ( this->m_forcedEndSample == 0.0
    || (double)(int)((double)sampleCount * v13) + this->m_fsample_index < this->m_forcedEndSample )
  {
    v15 = sampleCount;
  }
  else
  {
    m_forcedEndSample = this->m_forcedEndSample;
    this->m_finished = true;
    v15 = (int)((m_forcedEndSample - this->m_fsample_index) / v13);
    sampleCount = v15;
  }
  if ( v15 > 0 )
  {
    while ( 1 )
    {
      m_fsample_index = this->m_fsample_index;
      v38 = 1;
      bInterpolated_pitch[0] = FUseHighQualityPitch(pChannel: v12);
      if ( v15 >= 1020 )
        v15 = 1020;
      MaxRate = MIX_GetMaxRate(rate);
      m_delaySamples = this->m_delaySamples;
      v30 = MaxRate;
      if ( m_delaySamples <= 0 )
      {
        *(double *)pSamplesLoaded = RoundToFixedPoint(
                                      rate: MaxRate,
                                      samples: v15 - 1,
                                      bInterpolated_pitch: bInterpolated_pitch[0])
                                  + this->m_fsample_index;
        v21 = (unsigned __int64)ceil(X: *(double *)pSamplesLoaded);
        v22 = v21;
        v29 = v21;
        if ( *(double *)pSamplesLoaded >= (double)v21 )
          v22 = v21 + 1;
        MixBuffer = CAudioMixerWave::LoadMixBuffer(
                      this,
                      pChannel: v12,
                      sample_load_request: v22 - LODWORD(this->m_sample_loaded_index),
                      pSamplesLoaded: &pSamplesLoaded[1],
                      copyBuf);
      }
      else
      {
        if ( m_delaySamples < v15 )
          v15 = m_delaySamples;
        v18 = this->__vftable;
        this->m_delaySamples = m_delaySamples - v15;
        v19 = v18->GetMixSampleSize(this);
        MixBuffer = g_temppaintbuffer;
        memset(dst: (unsigned __int8 *)g_temppaintbuffer, value: 0, count: v15 * v19);
        v38 = 0;
        v30 = 1.0;
      }
      v35 = v15;
      if ( MixBuffer == nullptr )
        break;
      SND_MouthEnvelopeFollower(pChannel, pData: (char *)MixBuffer, count: v15);
      v28 = this->m_fsample_index - floor(X: this->m_fsample_index);
      if ( !bSkipAllMixing )
      {
        pSamplesLoaded[1] = MIX_GetCurrentPaintbufferIndex();
        v23 = 0;
        ipaintbuffer = 0;
        v34 = 0;
        do
        {
          if ( *(&g_paintBuffers->factive + v23) )
          {
            MIX_SetCurrentPaintbuffer(ipaintbuffer);
            v32 = (__int64)(v30 * 268435456.0);
            this->Mix(
              this,
              a2: pDevice,
              a3: pChannel,
              a4: MixBuffer,
              a5: outputOffset,
              a6: (int)(268435456.0 * v28),
              a7: v32,
              a8: v15,
              a9: 0);
            v23 = v34;
            v15 = v35;
          }
          ++ipaintbuffer;
          v23 += 312;
          v34 = v23;
        }
        while ( v23 < 1872 );
        MIX_SetCurrentPaintbuffer(ipaintbuffer: pSamplesLoaded[1]);
      }
      if ( v38 != 0 )
      {
        v24 = RoundToFixedPoint(rate: v30, samples: v15, bInterpolated_pitch: bInterpolated_pitch[0]);
        this->m_fsample_index = v24 + m_fsample_index;
      }
      outputOffset += v15;
      sampleCount -= v15;
      if ( sampleCount <= 0 )
        return outputOffset - v31;
      v15 = sampleCount;
      v12 = pChannel;
    }
    if ( sampleCount > 0 )
      this->m_finished = true;
  }
  return outputOffset - v31;
}

//------------------------------------------------------------------------------
// Address: 0x1003D520
// Name: public: CAudioMixerWave8Mono::CAudioMixerWave8Mono(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Mono *__thiscall CAudioMixerWave8Mono::CAudioMixerWave8Mono(
        CAudioMixerWave8Mono *this,
        IWaveData *data)
{
  this->m_fsample_index = 0.0;
  this->m_pData = data;
  this->m_forcedEndSample = 0.0;
  this->m_sample_max_loaded = 0;
  this->m_sample_loaded_index = -1;
  this->m_finished = false;
  this->m_delaySamples = 0;
  this->__vftable = (CAudioMixerWave8Mono_vtbl *)&CAudioMixerWave8Mono::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D560
// Name: public: virtual void CAudioMixerWave8Mono::Mix(class IAudioDevice __near *,struct channel_t __near *,void __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave8Mono::Mix(
        CAudioMixerWave8Mono *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress)
{
  pDevice->Mix8Mono(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress);
}

//------------------------------------------------------------------------------
// Address: 0x1003D590
// Name: public: CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Stereo *__thiscall CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(
        CAudioMixerWave8Stereo *this,
        IWaveData *data)
{
  this->m_fsample_index = 0.0;
  this->m_pData = data;
  this->m_forcedEndSample = 0.0;
  this->m_sample_max_loaded = 0;
  this->m_sample_loaded_index = -1;
  this->m_finished = false;
  this->m_delaySamples = 0;
  this->__vftable = (CAudioMixerWave8Stereo_vtbl *)&CAudioMixerWave8Stereo::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D600
// Name: public: CAudioMixerWave16Mono::CAudioMixerWave16Mono(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave16Mono *__thiscall CAudioMixerWave16Mono::CAudioMixerWave16Mono(
        CAudioMixerWave16Mono *this,
        IWaveData *data)
{
  this->m_fsample_index = 0.0;
  this->m_pData = data;
  this->m_forcedEndSample = 0.0;
  this->m_sample_max_loaded = 0;
  this->m_sample_loaded_index = -1;
  this->m_finished = false;
  this->m_delaySamples = 0;
  this->__vftable = (CAudioMixerWave16Mono_vtbl *)&CAudioMixerWave16Mono::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D640
// Name: public: virtual void CAudioMixerWave16Mono::Mix(class IAudioDevice __near *,struct channel_t __near *,void __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave16Mono::Mix(
        CAudioMixerWave16Mono *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress)
{
  pDevice->Mix16Mono(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress);
}

//------------------------------------------------------------------------------
// Address: 0x1003D680
// Name: public: CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave16Stereo *__thiscall CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(
        CAudioMixerWave16Stereo *this,
        IWaveData *data)
{
  this->m_fsample_index = 0.0;
  this->m_pData = data;
  this->m_forcedEndSample = 0.0;
  this->m_sample_max_loaded = 0;
  this->m_sample_loaded_index = -1;
  this->m_finished = false;
  this->m_delaySamples = 0;
  this->__vftable = (CAudioMixerWave16Stereo_vtbl *)&CAudioMixerWave16Stereo::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D6C0
// Name: public: virtual void CAudioMixerWave16Stereo::Mix(class IAudioDevice __near *,struct channel_t __near *,void __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWave16Stereo::Mix(
        CAudioMixerWave16Stereo *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress)
{
  pDevice->Mix16Stereo(
    this: pDevice,
    a2: pChannel,
    a3: pData,
    a4: outputOffset,
    a5: inputOffset,
    a6: fracRate,
    a7: outCount,
    a8: timecompress);
}

//------------------------------------------------------------------------------
// Address: 0x1003D6F0
// Name: class CAudioMixer __near * CreateWaveMixer(class IWaveData __near *,int,int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Mono *__cdecl CreateWaveMixer(IWaveData *data, int format, int channels, int bits)
{
  CAudioMixerWave8Mono *v5; // eax

  if ( format == 1 )
  {
    v5 = (CAudioMixerWave8Mono *)MemAlloc_Alloc(nSize: 0x38u);
    if ( channels <= 1 )
    {
      if ( bits == 8 )
      {
        if ( v5 != nullptr )
          return CAudioMixerWave8Mono::CAudioMixerWave8Mono(this: v5, data);
      }
      else if ( v5 != nullptr )
      {
        return (CAudioMixerWave8Mono *)CAudioMixerWave16Mono::CAudioMixerWave16Mono(
                                         this: (CAudioMixerWave16Mono *)v5,
                                         data);
      }
    }
    else if ( bits == 8 )
    {
      if ( v5 != nullptr )
        return (CAudioMixerWave8Mono *)CAudioMixerWave8Stereo::CAudioMixerWave8Stereo(
                                         this: (CAudioMixerWave8Stereo *)v5,
                                         data);
    }
    else if ( v5 != nullptr )
    {
      return (CAudioMixerWave8Mono *)CAudioMixerWave16Stereo::CAudioMixerWave16Stereo(
                                       this: (CAudioMixerWave16Stereo *)v5,
                                       data);
    }
  }
  else if ( format == 2 )
  {
    return (CAudioMixerWave8Mono *)CreateADPCMMixer(data);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003D7D0
// Name: public: virtual int CAudioMixerWave::SkipSamples(struct channel_t __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::SkipSamples(
        CAudioMixerWave *this,
        channel_t *pChannel,
        int sampleCount,
        int outputRate,
        int outputOffset)
{
  CAudioSource *v6; // eax
  int result; // eax
  float flTempPitch; // [esp+10h] [ebp+8h]

  v6 = this->GetSource(this);
  if ( v6->GetType(this: v6) == 1 && this->IsSetSampleStartSupported(this) )
  {
    this->SetSampleStart(this, a2: sampleCount);
    return sampleCount;
  }
  else
  {
    flTempPitch = pChannel->pitch;
    pChannel->pitch = 1.0;
    result = CAudioMixerWave::MixDataToDevice_(
               this,
               pDevice: nullptr,
               pChannel,
               sampleCount,
               outputRate,
               outputOffset,
               bSkipAllMixing: true);
    pChannel->pitch = flTempPitch;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003D860
// Name: public: virtual int CAudioMixerWave::MixDataToDevice(class IAudioDevice __near *,struct channel_t __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::MixDataToDevice(
        CAudioMixerWave *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        int sampleCount,
        int outputRate,
        int outputOffset)
{
  return CAudioMixerWave::MixDataToDevice_(
           this,
           pDevice,
           pChannel,
           sampleCount,
           outputRate,
           outputOffset,
           bSkipAllMixing: false);
}

//------------------------------------------------------------------------------
// Address: 0x1027EA70
// Name: public: virtual int CAudioMixerWave::GetSamplePosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWave::GetSamplePosition(CVTFTexture *this)
{
  return this->m_nHeight;
}

} // namespace engine_xlsp
