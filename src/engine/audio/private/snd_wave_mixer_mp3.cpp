// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_wave_mixer_mp3.cpp
// Functions: 11
// ============================================================

#include "engine\audio\private\snd_wave_mixer_mp3.h"

//------------------------------------------------------------------------------
// Address: 0x1003E1E0
// Name: public: virtual int CAudioMixerWaveMP3::GetPositionForSave(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAudioMixerWaveMP3::GetPositionForSave(CAudioMixerWaveMP3 *this)
{
  return this->m_pStream->GetPosition(this: this->m_pStream);
}

//------------------------------------------------------------------------------
// Address: 0x1003E1F0
// Name: public: virtual void CAudioMixerWaveMP3::SetPositionFromSaved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveMP3::SetPositionFromSaved(CAudioMixerWaveMP3 *this, unsigned int position)
{
  this->m_pStream->SetPosition(this: this->m_pStream, a2: position);
}

//------------------------------------------------------------------------------
// Address: 0x1003E200
// Name: public: virtual int CAudioMixerWaveMP3::GetStreamOutputRate(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveMP3::GetStreamOutputRate(CAudioMixerWaveMP3 *this)
{
  return this->m_pStream->GetOutputRate(this: this->m_pStream);
}

//------------------------------------------------------------------------------
// Address: 0x1003E210
// Name: public: virtual void CAudioMixerWaveMP3::Mix(class IAudioDevice __near *,struct channel_t __near *,void __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveMP3::Mix(
        CAudioMixerWaveMP3 *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress)
{
  if ( this->m_channelCount == 1 )
    pDevice->Mix16Mono(
      this: pDevice,
      a2: pChannel,
      a3: pData,
      a4: outputOffset,
      a5: inputOffset,
      a6: fracRate,
      a7: outCount,
      a8: timecompress);
  else
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
// Address: 0x1003E270
// Name: private: void CAudioMixerWaveMP3::GetID3HeaderOffset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveMP3::GetID3HeaderOffset(CAudioMixerWaveMP3 *this)
{
  _BYTE *v2; // eax
  unsigned __int8 v3; // bl
  unsigned __int8 v4; // dl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // al
  _BYTE v7[4096]; // [esp+4h] [ebp-1004h] BYREF
  _BYTE *v8; // [esp+1004h] [ebp-4h] BYREF

  if ( ((int (__thiscall *)(IWaveData *, _BYTE **, _DWORD, _DWORD, int, _BYTE *))this->m_pData->ReadSourceData)(
         a1: this->m_pData,
         a2: &v8,
         a3: 0,
         a4: 0,
         a5: 10,
         a6: v7) >= 10 )
  {
    v2 = v8;
    this->m_headerOffset = 0;
    if ( *v2 == 73 && v2[1] == 68 && v2[2] == 51 && v2[3] != 0xFF && v2[4] != 0xFF )
    {
      v3 = v2[6];
      if ( v3 < 0x80u )
      {
        v4 = v2[7];
        if ( v4 < 0x80u )
        {
          v5 = v2[8];
          if ( v5 < 0x80u )
          {
            v6 = v2[9];
            if ( v6 < 0x80u )
              this->m_headerOffset = (v6 | ((v5 | ((v4 | (v3 << 7)) << 7)) << 7)) + 10;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E320
// Name: public: virtual int CAudioMixerWaveMP3::StreamRequestData(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveMP3::StreamRequestData(
        CAudioMixerWaveMP3 *this,
        char *pBuffer,
        int bytesRequested,
        int offset)
{
  int v4; // esi
  int v6; // edi
  int v7; // esi
  unsigned __int8 *v9; // ebx
  int m_sampleCount; // ecx
  signed int v11; // esi
  int v12; // eax
  void *pData; // [esp+10h] [ebp-8h] BYREF
  CAudioMixerWaveMP3 *v14; // [esp+14h] [ebp-4h]
  int offseta; // [esp+28h] [ebp+10h]

  v4 = offset;
  v14 = this;
  if ( offset >= 0 )
    *(_DWORD *)&this->m_samples[16340] = offset;
  else
    v4 = *(_DWORD *)&this->m_samples[16340];
  v6 = 0;
  if ( v4 == 0 )
    CAudioMixerWaveMP3::GetID3HeaderOffset(this: (CAudioMixerWaveMP3 *)((char *)this - 56));
  v7 = *(_DWORD *)&this->m_samples[16348] + v4;
  offseta = v7;
  if ( bytesRequested > 0 )
  {
    while ( 1 )
    {
      v9 = (unsigned __int8 *)&pBuffer[v6];
      m_sampleCount = v14[-1].m_sampleCount;
      pData = nullptr;
      v11 = (*(int (__thiscall **)(int, void **, int, int, int, char *))(*(_DWORD *)m_sampleCount + 8))(
              a1: m_sampleCount,
              a2: &pData,
              a3: v6 + v7,
              a4: (v6 + v7) >> 31,
              a5: bytesRequested,
              a6: &pBuffer[v6]);
      if ( v11 == 0 )
        break;
      v12 = bytesRequested;
      if ( v11 > bytesRequested )
        v11 = bytesRequested;
      if ( pData != v9 )
      {
        memcpy(dst: v9, src: (unsigned __int8 *)pData, count: v11);
        v12 = bytesRequested;
      }
      v6 += v11;
      bytesRequested = v12 - v11;
      if ( v12 - v11 <= 0 )
        break;
      v7 = offseta;
    }
    *(_DWORD *)&v14->m_samples[16340] += v6;
    return v6;
  }
  else
  {
    *(_DWORD *)&this->m_samples[16340] = *(_DWORD *)&this->m_samples[16340];
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E3E0
// Name: public: virtual int CAudioMixerWaveMP3::GetOutputData(void __near * __near *,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveMP3::GetOutputData(
        CAudioMixerWaveMP3 *this,
        void **pData,
        int sampleCount,
        char *copyBuf)
{
  int v5; // eax
  int m_samplePosition; // eax
  int m_channelCount; // ecx
  int v8; // ecx
  int v9; // edi
  int v10; // eax
  int result; // eax
  bool v12; // cf

  if ( this->m_samplePosition >= this->m_sampleCount )
  {
    v5 = this->m_pStream->Decode(this: this->m_pStream, a2: this->m_samples, a3: 0x4000u);
    this->m_sampleCount = v5;
    this->m_samplePosition = 0;
    if ( v5 <= 0 )
      return 0;
  }
  m_samplePosition = this->m_samplePosition;
  if ( m_samplePosition >= this->m_sampleCount )
    return 0;
  m_channelCount = this->m_channelCount;
  *pData = &this->m_samples[m_samplePosition];
  v8 = 2 * m_channelCount;
  v9 = this->m_samplePosition;
  v10 = this->m_sampleCount - v9;
  if ( v10 > sampleCount * v8 )
    v10 = sampleCount * v8;
  this->m_samplePosition = v10 + v9;
  result = v10 / v8;
  this->m_sample_max_loaded += result;
  v12 = __CFADD__(result, this->m_sample_loaded_index);
  LODWORD(this->m_sample_loaded_index) += result;
  HIDWORD(this->m_sample_loaded_index) += (result >> 31) + v12;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003E480
// Name: public: virtual void CAudioMixerWaveMP3::SetStartupDelaySamples(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveMP3::SetStartupDelaySamples(CAudioMixerWaveMP3 *this, int delaySamples)
{
  this->m_delaySamples = delaySamples;
}

//------------------------------------------------------------------------------
// Address: 0x1003E490
// Name: public: virtual int CAudioMixerWaveMP3::GetMixSampleSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveMP3::GetMixSampleSize(CAudioMixerWaveMP3 *this)
{
  return 2 * this->m_channelCount;
}

//------------------------------------------------------------------------------
// Address: 0x1003E4A0
// Name: public: CAudioMixerWaveMP3::CAudioMixerWaveMP3(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWaveMP3 *__thiscall CAudioMixerWaveMP3::CAudioMixerWaveMP3(CAudioMixerWaveMP3 *this, IWaveData *data)
{
  IAudioStream *m_pStream; // ecx

  CAudioMixerWave::CAudioMixerWave(this, data);
  this->IAudioStreamEvent::__vftable = (IAudioStreamEvent_vtbl *)&IAudioStreamEvent::`vftable';
  this->CAudioMixerWave::CAudioMixer::__vftable = (CAudioMixerWaveMP3_vtbl *)&CAudioMixerWaveMP3::`vftable'{for `CAudioMixerWave'};
  this->IAudioStreamEvent::__vftable = (IAudioStreamEvent_vtbl *)&CAudioMixerWaveMP3::`vftable'{for `IAudioStreamEvent'};
  this->m_sampleCount = 0;
  this->m_samplePosition = 0;
  this->m_offset = 0;
  this->m_delaySamples = 0;
  this->m_headerOffset = 0;
  this->m_pStream = nullptr;
  if ( vaudio != nullptr )
    this->m_pStream = vaudio->CreateMP3StreamDecoder(this: vaudio, a2: &this->IAudioStreamEvent);
  m_pStream = this->m_pStream;
  if ( m_pStream != nullptr )
    this->m_channelCount = m_pStream->GetOutputChannels(this: m_pStream);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003E570
// Name: class CAudioMixer __near * CreateMP3Mixer(class IWaveData __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWaveMP3 *__cdecl CreateMP3Mixer(IWaveData *data, int *pSampleRate)
{
  CAudioMixerWaveMP3 *v2; // eax
  CAudioMixerWaveMP3 *v3; // esi

  v2 = (CAudioMixerWaveMP3 *)MemAlloc_Alloc(nSize: 0x4058u);
  if ( v2 != nullptr )
    v3 = CAudioMixerWaveMP3::CAudioMixerWaveMP3(this: v2, data);
  else
    v3 = nullptr;
  if ( v3->m_pStream != nullptr )
  {
    if ( pSampleRate != nullptr )
      *pSampleRate = v3->GetStreamOutputRate(this: v3);
    return v3;
  }
  else
  {
    ((void (__thiscall *)(CAudioMixerWaveMP3 *, int))v3->dtr_CAudioMixer)(a1: v3, a2: 1);
    return nullptr;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1003DE80
// Name: public: virtual int CAudioMixerWaveMP3::GetPositionForSave(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAudioMixerWaveMP3::GetPositionForSave(CAudioMixerWaveMP3 *this)
{
  return this->m_pStream->GetPosition(this: this->m_pStream);
}

//------------------------------------------------------------------------------
// Address: 0x1003DE90
// Name: public: virtual void CAudioMixerWaveMP3::SetPositionFromSaved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveMP3::SetPositionFromSaved(CAudioMixerWaveMP3 *this, unsigned int position)
{
  this->m_pStream->SetPosition(this: this->m_pStream, a2: position);
}

//------------------------------------------------------------------------------
// Address: 0x1003DEA0
// Name: public: virtual int CAudioMixerWaveMP3::GetStreamOutputRate(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveMP3::GetStreamOutputRate(CAudioMixerWaveMP3 *this)
{
  return this->m_pStream->GetOutputRate(this: this->m_pStream);
}

//------------------------------------------------------------------------------
// Address: 0x1003DEB0
// Name: public: virtual void CAudioMixerWaveMP3::Mix(class IAudioDevice __near *,struct channel_t __near *,void __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveMP3::Mix(
        CAudioMixerWaveMP3 *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress)
{
  if ( this->m_channelCount == 1 )
    pDevice->Mix16Mono(
      this: pDevice,
      a2: pChannel,
      a3: pData,
      a4: outputOffset,
      a5: inputOffset,
      a6: fracRate,
      a7: outCount,
      a8: timecompress);
  else
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
// Address: 0x1003DF10
// Name: private: void CAudioMixerWaveMP3::GetID3HeaderOffset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveMP3::GetID3HeaderOffset(CAudioMixerWaveMP3 *this)
{
  _BYTE *v2; // eax
  unsigned __int8 v3; // bl
  unsigned __int8 v4; // dl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // al
  _BYTE v7[4096]; // [esp+4h] [ebp-1004h] BYREF
  _BYTE *v8; // [esp+1004h] [ebp-4h] BYREF

  if ( ((int (__thiscall *)(IWaveData *, _BYTE **, _DWORD, _DWORD, int, _BYTE *))this->m_pData->ReadSourceData)(
         a1: this->m_pData,
         a2: &v8,
         a3: 0,
         a4: 0,
         a5: 10,
         a6: v7) >= 10 )
  {
    v2 = v8;
    this->m_headerOffset = 0;
    if ( *v2 == 73 && v2[1] == 68 && v2[2] == 51 && v2[3] != 0xFF && v2[4] != 0xFF )
    {
      v3 = v2[6];
      if ( v3 < 0x80u )
      {
        v4 = v2[7];
        if ( v4 < 0x80u )
        {
          v5 = v2[8];
          if ( v5 < 0x80u )
          {
            v6 = v2[9];
            if ( v6 < 0x80u )
              this->m_headerOffset = (v6 | ((v5 | ((v4 | (v3 << 7)) << 7)) << 7)) + 10;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DFC0
// Name: public: virtual int CAudioMixerWaveMP3::StreamRequestData(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveMP3::StreamRequestData(
        CAudioMixerWaveMP3 *this,
        char *pBuffer,
        int bytesRequested,
        int offset)
{
  int v4; // esi
  int v6; // edi
  int v7; // esi
  unsigned __int8 *v9; // ebx
  int m_sampleCount; // ecx
  signed int v11; // esi
  int v12; // eax
  void *pData; // [esp+10h] [ebp-8h] BYREF
  CAudioMixerWaveMP3 *v14; // [esp+14h] [ebp-4h]
  int offseta; // [esp+28h] [ebp+10h]

  v4 = offset;
  v14 = this;
  if ( offset >= 0 )
    *(_DWORD *)&this->m_samples[16340] = offset;
  else
    v4 = *(_DWORD *)&this->m_samples[16340];
  v6 = 0;
  if ( v4 == 0 )
    CAudioMixerWaveMP3::GetID3HeaderOffset(this: (CAudioMixerWaveMP3 *)((char *)this - 56));
  v7 = *(_DWORD *)&this->m_samples[16348] + v4;
  offseta = v7;
  if ( bytesRequested > 0 )
  {
    while ( 1 )
    {
      v9 = (unsigned __int8 *)&pBuffer[v6];
      m_sampleCount = v14[-1].m_sampleCount;
      pData = nullptr;
      v11 = (*(int (__thiscall **)(int, void **, int, int, int, char *))(*(_DWORD *)m_sampleCount + 8))(
              a1: m_sampleCount,
              a2: &pData,
              a3: v6 + v7,
              a4: (v6 + v7) >> 31,
              a5: bytesRequested,
              a6: &pBuffer[v6]);
      if ( v11 == 0 )
        break;
      v12 = bytesRequested;
      if ( v11 > bytesRequested )
        v11 = bytesRequested;
      if ( pData != v9 )
      {
        memcpy(dst: v9, src: (unsigned __int8 *)pData, count: v11);
        v12 = bytesRequested;
      }
      v6 += v11;
      bytesRequested = v12 - v11;
      if ( v12 - v11 <= 0 )
        break;
      v7 = offseta;
    }
    *(_DWORD *)&v14->m_samples[16340] += v6;
    return v6;
  }
  else
  {
    *(_DWORD *)&this->m_samples[16340] = *(_DWORD *)&this->m_samples[16340];
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E080
// Name: public: virtual int CAudioMixerWaveMP3::GetOutputData(void __near * __near *,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveMP3::GetOutputData(
        CAudioMixerWaveMP3 *this,
        void **pData,
        int sampleCount,
        char *copyBuf)
{
  int v5; // eax
  int m_samplePosition; // eax
  int m_channelCount; // ecx
  int v8; // ecx
  int v9; // edi
  int v10; // eax
  int result; // eax
  bool v12; // cf

  if ( this->m_samplePosition >= this->m_sampleCount )
  {
    v5 = this->m_pStream->Decode(this: this->m_pStream, a2: this->m_samples, a3: 0x4000u);
    this->m_sampleCount = v5;
    this->m_samplePosition = 0;
    if ( v5 <= 0 )
      return 0;
  }
  m_samplePosition = this->m_samplePosition;
  if ( m_samplePosition >= this->m_sampleCount )
    return 0;
  m_channelCount = this->m_channelCount;
  *pData = &this->m_samples[m_samplePosition];
  v8 = 2 * m_channelCount;
  v9 = this->m_samplePosition;
  v10 = this->m_sampleCount - v9;
  if ( v10 > sampleCount * v8 )
    v10 = sampleCount * v8;
  this->m_samplePosition = v10 + v9;
  result = v10 / v8;
  this->m_sample_max_loaded += result;
  v12 = __CFADD__(result, this->m_sample_loaded_index);
  LODWORD(this->m_sample_loaded_index) += result;
  HIDWORD(this->m_sample_loaded_index) += (result >> 31) + v12;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003E120
// Name: public: virtual void CAudioMixerWaveMP3::SetStartupDelaySamples(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveMP3::SetStartupDelaySamples(CAudioMixerWaveMP3 *this, int delaySamples)
{
  this->m_delaySamples = delaySamples;
}

//------------------------------------------------------------------------------
// Address: 0x1003E130
// Name: public: virtual int CAudioMixerWaveMP3::GetMixSampleSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveMP3::GetMixSampleSize(CAudioMixerWaveMP3 *this)
{
  return 2 * this->m_channelCount;
}

//------------------------------------------------------------------------------
// Address: 0x1003E140
// Name: public: CAudioMixerWaveMP3::CAudioMixerWaveMP3(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWaveMP3 *__thiscall CAudioMixerWaveMP3::CAudioMixerWaveMP3(CAudioMixerWaveMP3 *this, IWaveData *data)
{
  IAudioStream *m_pStream; // ecx

  CAudioMixerWave::CAudioMixerWave(this, data);
  this->IAudioStreamEvent::__vftable = (IAudioStreamEvent_vtbl *)&IAudioStreamEvent::`vftable';
  this->CAudioMixerWave::CAudioMixer::__vftable = (CAudioMixerWaveMP3_vtbl *)&CAudioMixerWaveMP3::`vftable'{for `CAudioMixerWave'};
  this->IAudioStreamEvent::__vftable = (IAudioStreamEvent_vtbl *)&CAudioMixerWaveMP3::`vftable'{for `IAudioStreamEvent'};
  this->m_sampleCount = 0;
  this->m_samplePosition = 0;
  this->m_offset = 0;
  this->m_delaySamples = 0;
  this->m_headerOffset = 0;
  this->m_pStream = nullptr;
  if ( vaudio != nullptr )
    this->m_pStream = vaudio->CreateMP3StreamDecoder(this: vaudio, a2: &this->IAudioStreamEvent);
  m_pStream = this->m_pStream;
  if ( m_pStream != nullptr )
    this->m_channelCount = m_pStream->GetOutputChannels(this: m_pStream);
  return this;
}

} // namespace engine_xlsp
