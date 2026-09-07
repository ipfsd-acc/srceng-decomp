// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/snd_wave_mixer_adpcm.cpp
// Functions: 8
// ============================================================

#include "utils\hlfaceposer\snd_wave_mixer_adpcm.h"

//------------------------------------------------------------------------------
// Address: 0x00401BB0
// Name: public: CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWaveADPCM *__thiscall CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(
        CAudioMixerWaveADPCM *this,
        CWaveData *data)
{
  CWaveData *m_pData; // ecx
  CAudioSourceWave *v4; // eax
  char *Header; // eax
  __int16 *v6; // eax
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int v8; // eax

  CAudioMixerWave::CAudioMixerWave(this, data);
  m_pData = this->m_pData;
  this->__vftable = (CAudioMixerWaveADPCM_vtbl *)&CAudioMixerWaveADPCM::`vftable';
  this->m_currentBlock = -1;
  this->m_pSamples = nullptr;
  this->m_sampleCount = 0;
  this->m_samplePosition = 0;
  this->m_offset = 0;
  v4 = m_pData->Source(this: m_pData);
  Header = (char *)CAudioSourceWave::GetHeader(this: v4);
  this->m_pFormat = (const adpcmwaveformat_tag *)Header;
  if ( Header != nullptr )
  {
    this->m_pCoefficients = (const adpcmcoef_tag *)(Header + 22);
    v6 = (__int16 *)operator new(nSize: 2 * *((unsigned __int16 *)Header + 1) * *((unsigned __int16 *)Header + 9));
    m_pFormat = this->m_pFormat;
    this->m_pSamples = v6;
    v8 = m_pFormat->wfx.nChannels * (m_pFormat->wSamplesPerBlock - 2) / 2;
    this->m_blockSize = v8;
    this->m_blockSize = v8 + 7 * m_pFormat->wfx.nChannels;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401C60
// Name: public: virtual void CAudioMixerWaveADPCM::Mix(class IAudioDevice __near *,struct channel_s __near *,void __near *,int,int,unsigned int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveADPCM::Mix(
        CAudioMixerWaveADPCM *this,
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
  const adpcmwaveformat_tag *m_pFormat; // eax

  m_pFormat = this->m_pFormat;
  if ( m_pFormat != nullptr && m_pFormat->wfx.nChannels == 1 )
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
  else
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
// Address: 0x00401CD0
// Name: private: void CAudioMixerWaveADPCM::DecompressBlockMono(short __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveADPCM::DecompressBlockMono(
        CAudioMixerWaveADPCM *this,
        __int16 *pOut,
        const char *pIn,
        int count)
{
  const adpcmcoef_tag *v4; // eax
  int iCoef1; // ecx
  int v6; // eax
  int v7; // edi
  int v8; // ecx
  const char *v9; // edx
  __int16 *v10; // esi
  bool v11; // zf
  int v12; // ecx
  char v13; // bl
  int v14; // ecx
  int v15; // ecx
  int co1; // [esp+8h] [ebp-10h]
  int co2; // [esp+Ch] [ebp-Ch]
  int samp1; // [esp+10h] [ebp-8h]
  int high; // [esp+14h] [ebp-4h]
  int sample; // [esp+20h] [ebp+8h]
  int delta; // [esp+24h] [ebp+Ch]
  int counta; // [esp+28h] [ebp+10h]

  v4 = &this->m_pCoefficients[*pIn];
  iCoef1 = v4->iCoef1;
  co2 = v4->iCoef2;
  v6 = *(__int16 *)(pIn + 5);
  v7 = *(__int16 *)(pIn + 3);
  co1 = iCoef1;
  v8 = *(__int16 *)(pIn + 1);
  *pOut = v6;
  pOut[1] = v7;
  v9 = pIn + 7;
  v10 = pOut + 2;
  v11 = count == 2;
  counta = count - 2;
  delta = v8;
  samp1 = v7;
  v12 = 1;
  sample = 0;
  if ( !v11 )
  {
    while ( 1 )
    {
      if ( v12 != 0 )
      {
        v13 = *v9;
        v14 = *(unsigned __int8 *)v9++;
        v15 = v14 >> 4;
        sample = v13 & 0xF;
        high = 0;
      }
      else
      {
        v15 = sample;
        high = 1;
      }
      v7 = ((co1 * v7 + co2 * v6) >> 8) + delta * error_sign_lut[v15];
      delta = (delta * error_coefficients_lut[v15]) >> 8;
      if ( delta < 16 )
        delta = 16;
      if ( v7 <= 0x7FFF )
      {
        if ( v7 < -32768 )
          v7 = -32768;
      }
      else
      {
        v7 = 0x7FFF;
      }
      v6 = samp1;
      *v10++ = v7;
      v11 = counta-- == 1;
      samp1 = v7;
      if ( v11 )
        break;
      v12 = high;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401DD0
// Name: private: void CAudioMixerWaveADPCM::DecompressBlockStereo(short __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveADPCM::DecompressBlockStereo(
        CAudioMixerWaveADPCM *this,
        __int16 *pOut,
        const char *pIn,
        int count)
{
  const adpcmcoef_tag *m_pCoefficients; // eax
  int v5; // edx
  int iCoef1; // ecx
  int iCoef2; // edx
  int v8; // ebx
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // edi
  int v15; // ecx
  int v16; // edx
  const char *v17; // esi
  bool v18; // zf
  int i; // edx
  char v20; // al
  int v21; // ecx
  int v22; // ecx
  int v23; // edi
  int v24; // ebx
  int v25; // ecx
  int v26; // eax
  int co1[2]; // [esp+Ch] [ebp-2Ch]
  int co2[2]; // [esp+14h] [ebp-24h]
  int samp2[2]; // [esp+1Ch] [ebp-1Ch]
  int samp1[2]; // [esp+24h] [ebp-14h]
  int delta[2]; // [esp+2Ch] [ebp-Ch]
  int sample; // [esp+34h] [ebp-4h]
  __int16 *pOuta; // [esp+40h] [ebp+8h]
  int high; // [esp+44h] [ebp+Ch]
  int counta; // [esp+48h] [ebp+10h]

  m_pCoefficients = this->m_pCoefficients;
  v5 = *pIn;
  iCoef1 = m_pCoefficients[v5].iCoef1;
  iCoef2 = m_pCoefficients[v5].iCoef2;
  v8 = *((__int16 *)pIn + 6);
  co1[0] = iCoef1;
  v9 = pIn[1];
  co2[0] = iCoef2;
  v10 = m_pCoefficients[v9].iCoef1;
  v11 = m_pCoefficients[v9].iCoef2;
  v12 = *((__int16 *)pIn + 1);
  co1[1] = v10;
  v13 = *((__int16 *)pIn + 2);
  v14 = *((__int16 *)pIn + 5);
  co2[1] = v11;
  delta[0] = v12;
  v15 = *((__int16 *)pIn + 3);
  delta[1] = v13;
  v16 = *((__int16 *)pIn + 4);
  *pOut = v14;
  pOut[1] = v8;
  pOut[2] = v15;
  pOut[3] = v16;
  v17 = pIn + 14;
  v18 = count == 2;
  counta = count - 2;
  samp1[0] = v15;
  samp1[1] = v16;
  samp2[0] = v14;
  samp2[1] = v8;
  pOuta = pOut + 4;
  high = 1;
  sample = 0;
  if ( !v18 )
  {
    do
    {
      for ( i = 0; i < 2; ++i )
      {
        if ( high != 0 )
        {
          v20 = *v17;
          v21 = *(unsigned __int8 *)v17++;
          v22 = v21 >> 4;
          sample = v20 & 0xF;
          high = 0;
        }
        else
        {
          v22 = sample;
          high = 1;
        }
        v23 = delta[i];
        v24 = v23 * error_sign_lut[v22];
        v25 = (v23 * error_coefficients_lut[v22]) >> 8;
        v26 = v24 + ((samp1[i] * co1[i] + samp2[i] * co2[i]) >> 8);
        delta[i] = v25;
        if ( v25 < 16 )
          delta[i] = 16;
        if ( v26 <= 0x7FFF )
        {
          if ( v26 < -32768 )
            v26 = -32768;
        }
        else
        {
          v26 = 0x7FFF;
        }
        *pOuta++ = v26;
        samp2[i] = samp1[i];
        samp1[i] = v26;
      }
      --counta;
    }
    while ( counta != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401F20
// Name: class CAudioMixer __near * CreateADPCMMixer(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWaveADPCM *__cdecl CreateADPCMMixer(CWaveData *data)
{
  CAudioMixerWaveADPCM *v1; // eax

  v1 = (CAudioMixerWaveADPCM *)operator new(nSize: 0x54u);
  if ( v1 != nullptr )
    return CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(this: v1, data);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401F90
// Name: private: bool CAudioMixerWaveADPCM::DecodeBlock(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioMixerWaveADPCM::DecodeBlock(CAudioMixerWaveADPCM *this)
{
  int v2; // eax
  unsigned int v3; // edi
  int v4; // ebx
  int m_offset; // ecx
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int nChannels; // ebx
  int wSamplesPerBlock; // ecx
  int v10; // eax
  int v11; // eax
  __int16 *m_pSamples; // ecx
  unsigned __int8 dst[4100]; // [esp+Ch] [ebp-1008h] BYREF
  unsigned __int8 *src; // [esp+1010h] [ebp-4h] BYREF

  v2 = this->m_pData->ReadSourceData(
         this: this->m_pData,
         a2: (void **)&src,
         a3: this->m_offset,
         a4: this->m_blockSize,
         a5: true);
  v3 = v2;
  if ( v2 < this->m_blockSize )
  {
    v4 = 0;
    if ( v2 != 0 )
    {
      do
      {
        if ( v4 >= this->m_blockSize )
          break;
        memcpy(dst: &dst[v4], src, count: v3);
        v4 += v3;
        v3 = this->m_pData->ReadSourceData(
               this: this->m_pData,
               a2: (void **)&src,
               a3: v4 + this->m_offset,
               a4: this->m_blockSize - v4,
               a5: true);
      }
      while ( v3 != 0 );
    }
    src = dst;
    v3 = v4;
  }
  m_offset = this->m_offset;
  this->m_currentBlock = m_offset / this->m_blockSize;
  if ( v3 == 0 )
    return 0;
  this->m_offset = v3 + m_offset;
  m_pFormat = this->m_pFormat;
  if ( m_pFormat != nullptr )
    nChannels = m_pFormat->wfx.nChannels;
  else
    nChannels = 0;
  wSamplesPerBlock = m_pFormat->wSamplesPerBlock;
  v10 = (int)(2 * (v3 - this->m_blockSize)) / nChannels;
  this->m_samplePosition = 0;
  v11 = wSamplesPerBlock + v10;
  m_pSamples = this->m_pSamples;
  this->m_sampleCount = v11;
  if ( nChannels == 1 )
    CAudioMixerWaveADPCM::DecompressBlockMono(this, pOut: m_pSamples, pIn: (const char *)src, count: v11);
  else
    CAudioMixerWaveADPCM::DecompressBlockStereo(this, pOut: m_pSamples, pIn: (const char *)src, count: v11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402090
// Name: public: virtual int CAudioMixerWaveADPCM::GetOutputData(void __near * __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveADPCM::GetOutputData(
        CAudioMixerWaveADPCM *this,
        void **pData,
        int samplePosition,
        int sampleCount,
        bool forward)
{
  int m_samplePosition; // eax
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int nChannels; // ecx
  int v9; // ecx
  int result; // eax

  if ( samplePosition / this->m_pFormat->wSamplesPerBlock != this->m_currentBlock
    && !this->SetSamplePosition(this, a2: samplePosition, a3: false) )
  {
    return 0;
  }
  if ( this->m_samplePosition >= this->m_sampleCount && CAudioMixerWaveADPCM::DecodeBlock(this) == 0 )
    return 0;
  m_samplePosition = this->m_samplePosition;
  if ( m_samplePosition >= this->m_sampleCount )
    return 0;
  m_pFormat = this->m_pFormat;
  if ( m_pFormat != nullptr )
    nChannels = m_pFormat->wfx.nChannels;
  else
    nChannels = 0;
  *pData = &this->m_pSamples[nChannels * m_samplePosition];
  v9 = this->m_samplePosition;
  result = this->m_sampleCount - v9;
  if ( result > sampleCount )
    result = sampleCount;
  this->m_samplePosition = result + v9;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402120
// Name: public: virtual bool CAudioMixerWaveADPCM::SetSamplePosition(int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioMixerWaveADPCM::SetSamplePosition(CAudioMixerWaveADPCM *this, int position, bool scrubbing)
{
  int v4; // edi
  int v5; // ebx
  CAudioSourceWave *v6; // eax
  int v8; // edi
  int firstSample; // [esp+14h] [ebp+8h]

  v4 = position < 0 ? 0 : position;
  CAudioMixerWave::SetSamplePosition(this, position: v4, scrubbing);
  v5 = v4 / this->m_pFormat->wSamplesPerBlock;
  firstSample = v5 * this->m_pFormat->wSamplesPerBlock;
  v6 = this->m_pData->Source(this: this->m_pData);
  if ( firstSample >= v6->SampleCount(this: v6) )
    return 0;
  v8 = v4 - firstSample;
  if ( v5 != this->m_currentBlock )
  {
    this->m_offset = v5 * this->m_blockSize;
    if ( CAudioMixerWaveADPCM::DecodeBlock(this) == 0 )
      return 0;
  }
  this->m_samplePosition = v8;
  return 1;
}

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x00401B80
// Name: public: CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWaveADPCM *__thiscall CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(
        CAudioMixerWaveADPCM *this,
        CWaveData *data)
{
  CWaveData *m_pData; // ecx
  CAudioSourceWave *v4; // eax
  char *Header; // eax
  __int16 *v6; // eax
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int v8; // eax

  CAudioMixerWave::CAudioMixerWave(this, data);
  m_pData = this->m_pData;
  this->__vftable = (CAudioMixerWaveADPCM_vtbl *)&CAudioMixerWaveADPCM::`vftable';
  this->m_currentBlock = -1;
  this->m_pSamples = nullptr;
  this->m_sampleCount = 0;
  this->m_samplePosition = 0;
  this->m_offset = 0;
  v4 = m_pData->Source(this: m_pData);
  Header = (char *)CAudioSourceWave::GetHeader(this: v4);
  this->m_pFormat = (const adpcmwaveformat_tag *)Header;
  if ( Header != nullptr )
  {
    this->m_pCoefficients = (const adpcmcoef_tag *)(Header + 22);
    v6 = (__int16 *)operator new(nSize: 2 * *((unsigned __int16 *)Header + 1) * *((unsigned __int16 *)Header + 9));
    m_pFormat = this->m_pFormat;
    this->m_pSamples = v6;
    v8 = m_pFormat->wfx.nChannels * (m_pFormat->wSamplesPerBlock - 2) / 2;
    this->m_blockSize = v8;
    this->m_blockSize = v8 + 7 * m_pFormat->wfx.nChannels;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401C30
// Name: public: virtual void CAudioMixerWaveADPCM::Mix(class IAudioDevice __near *,struct channel_s __near *,void __near *,int,int,unsigned int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveADPCM::Mix(
        CAudioMixerWaveADPCM *this,
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
  const adpcmwaveformat_tag *m_pFormat; // eax

  m_pFormat = this->m_pFormat;
  if ( m_pFormat != nullptr && m_pFormat->wfx.nChannels == 1 )
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
  else
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
// Address: 0x00401CA0
// Name: private: void CAudioMixerWaveADPCM::DecompressBlockMono(short __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveADPCM::DecompressBlockMono(
        CAudioMixerWaveADPCM *this,
        __int16 *pOut,
        const char *pIn,
        int count)
{
  const adpcmcoef_tag *v4; // eax
  int iCoef1; // ecx
  int v6; // eax
  int v7; // edi
  int v8; // ecx
  const char *v9; // edx
  __int16 *v10; // esi
  bool v11; // zf
  int v12; // ecx
  char v13; // bl
  int v14; // ecx
  int v15; // ecx
  int co1; // [esp+8h] [ebp-10h]
  int co2; // [esp+Ch] [ebp-Ch]
  int samp1; // [esp+10h] [ebp-8h]
  int high; // [esp+14h] [ebp-4h]
  int sample; // [esp+20h] [ebp+8h]
  int delta; // [esp+24h] [ebp+Ch]
  int counta; // [esp+28h] [ebp+10h]

  v4 = &this->m_pCoefficients[*pIn];
  iCoef1 = v4->iCoef1;
  co2 = v4->iCoef2;
  v6 = *(__int16 *)(pIn + 5);
  v7 = *(__int16 *)(pIn + 3);
  co1 = iCoef1;
  v8 = *(__int16 *)(pIn + 1);
  *pOut = v6;
  pOut[1] = v7;
  v9 = pIn + 7;
  v10 = pOut + 2;
  v11 = count == 2;
  counta = count - 2;
  delta = v8;
  samp1 = v7;
  v12 = 1;
  sample = 0;
  if ( !v11 )
  {
    while ( 1 )
    {
      if ( v12 != 0 )
      {
        v13 = *v9;
        v14 = *(unsigned __int8 *)v9++;
        v15 = v14 >> 4;
        sample = v13 & 0xF;
        high = 0;
      }
      else
      {
        v15 = sample;
        high = 1;
      }
      v7 = ((co1 * v7 + co2 * v6) >> 8) + delta * error_sign_lut[v15];
      delta = (delta * error_coefficients_lut[v15]) >> 8;
      if ( delta < 16 )
        delta = 16;
      if ( v7 <= 0x7FFF )
      {
        if ( v7 < -32768 )
          v7 = -32768;
      }
      else
      {
        v7 = 0x7FFF;
      }
      v6 = samp1;
      *v10++ = v7;
      v11 = counta-- == 1;
      samp1 = v7;
      if ( v11 )
        break;
      v12 = high;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401DA0
// Name: private: void CAudioMixerWaveADPCM::DecompressBlockStereo(short __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveADPCM::DecompressBlockStereo(
        CAudioMixerWaveADPCM *this,
        __int16 *pOut,
        const char *pIn,
        int count)
{
  const adpcmcoef_tag *m_pCoefficients; // eax
  int v5; // edx
  int iCoef1; // ecx
  int iCoef2; // edx
  int v8; // ebx
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // edi
  int v15; // ecx
  int v16; // edx
  const char *v17; // esi
  bool v18; // zf
  int i; // edx
  char v20; // al
  int v21; // ecx
  int v22; // ecx
  int v23; // edi
  int v24; // ebx
  int v25; // ecx
  int v26; // eax
  int co1[2]; // [esp+Ch] [ebp-2Ch]
  int co2[2]; // [esp+14h] [ebp-24h]
  int samp2[2]; // [esp+1Ch] [ebp-1Ch]
  int samp1[2]; // [esp+24h] [ebp-14h]
  int delta[2]; // [esp+2Ch] [ebp-Ch]
  int sample; // [esp+34h] [ebp-4h]
  __int16 *pOuta; // [esp+40h] [ebp+8h]
  int high; // [esp+44h] [ebp+Ch]
  int counta; // [esp+48h] [ebp+10h]

  m_pCoefficients = this->m_pCoefficients;
  v5 = *pIn;
  iCoef1 = m_pCoefficients[v5].iCoef1;
  iCoef2 = m_pCoefficients[v5].iCoef2;
  v8 = *((__int16 *)pIn + 6);
  co1[0] = iCoef1;
  v9 = pIn[1];
  co2[0] = iCoef2;
  v10 = m_pCoefficients[v9].iCoef1;
  v11 = m_pCoefficients[v9].iCoef2;
  v12 = *((__int16 *)pIn + 1);
  co1[1] = v10;
  v13 = *((__int16 *)pIn + 2);
  v14 = *((__int16 *)pIn + 5);
  co2[1] = v11;
  delta[0] = v12;
  v15 = *((__int16 *)pIn + 3);
  delta[1] = v13;
  v16 = *((__int16 *)pIn + 4);
  *pOut = v14;
  pOut[1] = v8;
  pOut[2] = v15;
  pOut[3] = v16;
  v17 = pIn + 14;
  v18 = count == 2;
  counta = count - 2;
  samp1[0] = v15;
  samp1[1] = v16;
  samp2[0] = v14;
  samp2[1] = v8;
  pOuta = pOut + 4;
  high = 1;
  sample = 0;
  if ( !v18 )
  {
    do
    {
      for ( i = 0; i < 2; ++i )
      {
        if ( high != 0 )
        {
          v20 = *v17;
          v21 = *(unsigned __int8 *)v17++;
          v22 = v21 >> 4;
          sample = v20 & 0xF;
          high = 0;
        }
        else
        {
          v22 = sample;
          high = 1;
        }
        v23 = delta[i];
        v24 = v23 * error_sign_lut[v22];
        v25 = (v23 * error_coefficients_lut[v22]) >> 8;
        v26 = v24 + ((samp1[i] * co1[i] + samp2[i] * co2[i]) >> 8);
        delta[i] = v25;
        if ( v25 < 16 )
          delta[i] = 16;
        if ( v26 <= 0x7FFF )
        {
          if ( v26 < -32768 )
            v26 = -32768;
        }
        else
        {
          v26 = 0x7FFF;
        }
        *pOuta++ = v26;
        samp2[i] = samp1[i];
        samp1[i] = v26;
      }
      --counta;
    }
    while ( counta != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401EF0
// Name: class CAudioMixer __near * CreateADPCMMixer(class CWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWaveADPCM *__cdecl CreateADPCMMixer(CWaveData *data)
{
  CAudioMixerWaveADPCM *v1; // eax

  v1 = (CAudioMixerWaveADPCM *)operator new(nSize: 0x54u);
  if ( v1 != nullptr )
    return CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(this: v1, data);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401F60
// Name: private: bool CAudioMixerWaveADPCM::DecodeBlock(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioMixerWaveADPCM::DecodeBlock(CAudioMixerWaveADPCM *this)
{
  int v2; // eax
  unsigned int v3; // edi
  int v4; // ebx
  int m_offset; // ecx
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int nChannels; // ebx
  int wSamplesPerBlock; // ecx
  int v10; // eax
  int v11; // eax
  __int16 *m_pSamples; // ecx
  unsigned __int8 dst[4100]; // [esp+Ch] [ebp-1008h] BYREF
  unsigned __int8 *src; // [esp+1010h] [ebp-4h] BYREF

  v2 = this->m_pData->ReadSourceData(
         this: this->m_pData,
         a2: (void **)&src,
         a3: this->m_offset,
         a4: this->m_blockSize,
         a5: true);
  v3 = v2;
  if ( v2 < this->m_blockSize )
  {
    v4 = 0;
    if ( v2 != 0 )
    {
      do
      {
        if ( v4 >= this->m_blockSize )
          break;
        memcpy(dst: &dst[v4], src, count: v3);
        v4 += v3;
        v3 = this->m_pData->ReadSourceData(
               this: this->m_pData,
               a2: (void **)&src,
               a3: v4 + this->m_offset,
               a4: this->m_blockSize - v4,
               a5: true);
      }
      while ( v3 != 0 );
    }
    src = dst;
    v3 = v4;
  }
  m_offset = this->m_offset;
  this->m_currentBlock = m_offset / this->m_blockSize;
  if ( v3 == 0 )
    return 0;
  this->m_offset = v3 + m_offset;
  m_pFormat = this->m_pFormat;
  if ( m_pFormat != nullptr )
    nChannels = m_pFormat->wfx.nChannels;
  else
    nChannels = 0;
  wSamplesPerBlock = m_pFormat->wSamplesPerBlock;
  v10 = (int)(2 * (v3 - this->m_blockSize)) / nChannels;
  this->m_samplePosition = 0;
  v11 = wSamplesPerBlock + v10;
  m_pSamples = this->m_pSamples;
  this->m_sampleCount = v11;
  if ( nChannels == 1 )
    CAudioMixerWaveADPCM::DecompressBlockMono(this, pOut: m_pSamples, pIn: (const char *)src, count: v11);
  else
    CAudioMixerWaveADPCM::DecompressBlockStereo(this, pOut: m_pSamples, pIn: (const char *)src, count: v11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402060
// Name: public: virtual int CAudioMixerWaveADPCM::GetOutputData(void __near * __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveADPCM::GetOutputData(
        CAudioMixerWaveADPCM *this,
        void **pData,
        int samplePosition,
        int sampleCount,
        bool forward)
{
  int m_samplePosition; // eax
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int nChannels; // ecx
  int v9; // ecx
  int result; // eax

  if ( samplePosition / this->m_pFormat->wSamplesPerBlock != this->m_currentBlock
    && !this->SetSamplePosition(this, a2: samplePosition, a3: false) )
  {
    return 0;
  }
  if ( this->m_samplePosition >= this->m_sampleCount && CAudioMixerWaveADPCM::DecodeBlock(this) == 0 )
    return 0;
  m_samplePosition = this->m_samplePosition;
  if ( m_samplePosition >= this->m_sampleCount )
    return 0;
  m_pFormat = this->m_pFormat;
  if ( m_pFormat != nullptr )
    nChannels = m_pFormat->wfx.nChannels;
  else
    nChannels = 0;
  *pData = &this->m_pSamples[nChannels * m_samplePosition];
  v9 = this->m_samplePosition;
  result = this->m_sampleCount - v9;
  if ( result > sampleCount )
    result = sampleCount;
  this->m_samplePosition = result + v9;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004020F0
// Name: public: virtual bool CAudioMixerWaveADPCM::SetSamplePosition(int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioMixerWaveADPCM::SetSamplePosition(CAudioMixerWaveADPCM *this, int position, bool scrubbing)
{
  int v4; // edi
  int v5; // ebx
  CAudioSourceWave *v6; // eax
  int v8; // edi
  int firstSample; // [esp+14h] [ebp+8h]

  v4 = position < 0 ? 0 : position;
  CAudioMixerWave::SetSamplePosition(this, position: v4, scrubbing);
  v5 = v4 / this->m_pFormat->wSamplesPerBlock;
  firstSample = v5 * this->m_pFormat->wSamplesPerBlock;
  v6 = this->m_pData->Source(this: this->m_pData);
  if ( firstSample >= v6->SampleCount(this: v6) )
    return 0;
  v8 = v4 - firstSample;
  if ( v5 != this->m_currentBlock )
  {
    this->m_offset = v5 * this->m_blockSize;
    if ( CAudioMixerWaveADPCM::DecodeBlock(this) == 0 )
      return 0;
  }
  this->m_samplePosition = v8;
  return 1;
}

} // namespace localization_check
