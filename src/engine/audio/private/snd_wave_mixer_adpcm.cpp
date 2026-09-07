// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_wave_mixer_adpcm.cpp
// Functions: 9
// ============================================================

#include "engine\audio\private\snd_wave_mixer_adpcm.h"

//------------------------------------------------------------------------------
// Address: 0x1003DBF0
// Name: public: CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWaveADPCM *__thiscall CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(
        CAudioMixerWaveADPCM *this,
        IWaveData *data)
{
  IWaveData *m_pData; // ecx
  CVTFTexture *v4; // edi
  unsigned __int8 *v5; // eax
  __int16 *v6; // eax
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int v8; // kr00_4

  CAudioMixerWave::CAudioMixerWave(this, data);
  m_pData = this->m_pData;
  this->__vftable = (CAudioMixerWaveADPCM_vtbl *)&CAudioMixerWaveADPCM::`vftable';
  this->m_pSamples = nullptr;
  this->m_sampleCount = 0;
  this->m_samplePosition = 0;
  this->m_offset = 0;
  v4 = (CVTFTexture *)m_pData->Source(this: m_pData);
  v5 = CVTFTexture::ImageData(this: v4);
  this->m_pFormat = (const adpcmwaveformat_tag *)v5;
  if ( v5 != nullptr )
  {
    this->m_pCoefficients = (const adpcmcoef_tag *)(v5 + 22);
    v6 = (__int16 *)MemAlloc_Alloc(
                      nSize: (unsigned __int64)(*((unsigned __int16 *)v5 + 1) * (unsigned int)*((unsigned __int16 *)v5 + 9)) >> 31 != 0
                    ? -1
                    : 2 * *((unsigned __int16 *)v5 + 1) * *((unsigned __int16 *)v5 + 9));
    m_pFormat = this->m_pFormat;
    this->m_pSamples = v6;
    v8 = m_pFormat->wfx.nChannels * (m_pFormat->wSamplesPerBlock - 2);
    this->m_blockSize = v8 / 2;
    this->m_blockSize = v8 / 2 + 7 * m_pFormat->wfx.nChannels;
    this->m_totalBytes = ((int (__thiscall *)(CVTFTexture *))v4->LowResFileInfo)(a1: v4);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003DCA0
// Name: public: virtual void CAudioMixerWaveADPCM::Mix(class IAudioDevice __near *,struct channel_t __near *,void __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveADPCM::Mix(
        CAudioMixerWaveADPCM *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress)
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
// Address: 0x1003DD10
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
// Address: 0x1003DE10
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
// Address: 0x1003DF60
// Name: private: bool CAudioMixerWaveADPCM::DecodeBlock(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioMixerWaveADPCM::DecodeBlock(CAudioMixerWaveADPCM *this)
{
  CAudioSourceWave *v2; // eax
  int v3; // eax
  int m_totalBytes; // ecx
  int v5; // edi
  int v7; // edx
  int v8; // eax
  int v9; // ebx
  int m_blockSize; // ecx
  int v11; // eax
  unsigned int v12; // edi
  signed int v13; // ebx
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int nChannels; // ebx
  int wSamplesPerBlock; // ecx
  int v17; // eax
  __int16 *m_pSamples; // edx
  unsigned __int8 *v19; // [esp-Ch] [ebp-1020h]
  int v20; // [esp-8h] [ebp-101Ch]
  unsigned __int8 dst[4096]; // [esp+8h] [ebp-100Ch] BYREF
  int v22; // [esp+1008h] [ebp-Ch]
  int v23; // [esp+100Ch] [ebp-8h]
  unsigned __int8 *src; // [esp+1010h] [ebp-4h] BYREF

  v2 = (CAudioSourceWave *)this->m_pData->Source(this: this->m_pData);
  v3 = CAudioSourceWave::ConvertLoopedPosition(this: v2, samplePosition: this->m_offset);
  m_totalBytes = this->m_totalBytes;
  v5 = v3;
  this->m_offset = v3;
  if ( v3 >= m_totalBytes )
    return 0;
  v7 = v3 % this->m_blockSize;
  v8 = v3 - v7;
  v9 = m_totalBytes - (v5 - v7);
  m_blockSize = this->m_blockSize;
  v22 = v7;
  this->m_offset = v5 - v7;
  v23 = v9;
  if ( v9 > m_blockSize )
  {
    v23 = m_blockSize;
    v9 = m_blockSize;
  }
  v11 = ((int (__thiscall *)(IWaveData *, unsigned __int8 **, int, int, int, _DWORD))this->m_pData->ReadSourceData)(
          a1: this->m_pData,
          a2: &src,
          a3: v8,
          a4: v8 >> 31,
          a5: v9,
          a6: 0);
  v12 = v11;
  if ( v11 < v9 )
  {
    v13 = 0;
    if ( v11 != 0 )
    {
      do
      {
        if ( v13 >= v23 )
          break;
        memcpy(dst: &dst[v13], src, count: v12);
        v13 += v12;
        v12 = ((int (__thiscall *)(IWaveData *, unsigned __int8 **, int, int, int, _DWORD))this->m_pData->ReadSourceData)(
                a1: this->m_pData,
                a2: &src,
                a3: v13 + this->m_offset,
                a4: (v13 + this->m_offset) >> 31,
                a5: v23 - v13,
                a6: 0);
      }
      while ( v12 != 0 );
    }
    src = dst;
    v12 = v13;
  }
  if ( v12 == 0 )
    return 0;
  m_pFormat = this->m_pFormat;
  this->m_offset += v12;
  if ( m_pFormat != nullptr )
    nChannels = m_pFormat->wfx.nChannels;
  else
    nChannels = 0;
  wSamplesPerBlock = m_pFormat->wSamplesPerBlock;
  v17 = (int)(2 * (v12 - this->m_blockSize)) / nChannels;
  this->m_samplePosition = v22;
  m_pSamples = this->m_pSamples;
  v20 = wSamplesPerBlock + v17;
  v19 = src;
  this->m_sampleCount = wSamplesPerBlock + v17;
  if ( nChannels == 1 )
    CAudioMixerWaveADPCM::DecompressBlockMono(this, pOut: m_pSamples, pIn: (const char *)v19, count: v20);
  else
    CAudioMixerWaveADPCM::DecompressBlockStereo(this, pOut: m_pSamples, pIn: (const char *)v19, count: v20);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003E090
// Name: public: virtual int CAudioMixerWaveADPCM::GetOutputData(void __near * __near *,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveADPCM::GetOutputData(
        CAudioMixerWaveADPCM *this,
        void **pData,
        int sampleCount,
        char *copyBuf)
{
  int m_samplePosition; // eax
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int nChannels; // ecx
  int v8; // eax
  int v9; // ecx
  bool v11; // cf

  if ( this->m_samplePosition >= this->m_sampleCount && !CAudioMixerWaveADPCM::DecodeBlock(this) )
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
  v8 = this->m_samplePosition;
  v9 = this->m_sampleCount - v8;
  if ( v9 > sampleCount )
    v9 = sampleCount;
  this->m_samplePosition = v9 + v8;
  this->m_sample_max_loaded += v9;
  v11 = __CFADD__(v9, this->m_sample_loaded_index);
  LODWORD(this->m_sample_loaded_index) += v9;
  HIDWORD(this->m_sample_loaded_index) += (v9 >> 31) + v11;
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1003E100
// Name: public: virtual void CAudioMixerWaveADPCM::SetSampleStart(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveADPCM::SetSampleStart(CAudioMixerWaveADPCM *this, int newPosition)
{
  int v3; // edx
  int v4; // edi
  int m_sampleCount; // eax

  CAudioMixerWave::SetSampleStart(this, newPosition);
  v3 = newPosition % this->m_pFormat->wSamplesPerBlock;
  this->m_offset = newPosition / this->m_pFormat->wSamplesPerBlock * this->m_blockSize;
  v4 = v3;
  CAudioMixerWaveADPCM::DecodeBlock(this);
  m_sampleCount = this->m_sampleCount;
  if ( v4 >= m_sampleCount )
    this->m_samplePosition = v4;
  else
    this->m_samplePosition = m_sampleCount;
}

//------------------------------------------------------------------------------
// Address: 0x1003E150
// Name: class CAudioMixer __near * CreateADPCMMixer(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWaveADPCM *__cdecl CreateADPCMMixer(IWaveData *data)
{
  CAudioMixerWaveADPCM *v1; // eax

  v1 = (CAudioMixerWaveADPCM *)MemAlloc_Alloc(nSize: 0x58u);
  if ( v1 != nullptr )
    return CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(this: v1, data);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003E180
// Name: public: virtual int CAudioMixerWaveADPCM::GetMixSampleSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveADPCM::GetMixSampleSize(CAudioMixerWaveADPCM *this)
{
  const adpcmwaveformat_tag *m_pFormat; // eax

  m_pFormat = this->m_pFormat;
  if ( m_pFormat != nullptr )
    return 2 * m_pFormat->wfx.nChannels;
  else
    return 0;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1003D890
// Name: public: CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWaveADPCM *__thiscall CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(
        CAudioMixerWaveADPCM *this,
        IWaveData *data)
{
  IWaveData *m_pData; // ecx
  CVTFTexture *v4; // edi
  unsigned __int8 *v5; // eax
  __int16 *v6; // eax
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int v8; // kr00_4

  CAudioMixerWave::CAudioMixerWave(this, data);
  m_pData = this->m_pData;
  this->__vftable = (CAudioMixerWaveADPCM_vtbl *)&CAudioMixerWaveADPCM::`vftable';
  this->m_pSamples = nullptr;
  this->m_sampleCount = 0;
  this->m_samplePosition = 0;
  this->m_offset = 0;
  v4 = (CVTFTexture *)m_pData->Source(this: m_pData);
  v5 = CVTFTexture::ImageData(this: v4);
  this->m_pFormat = (const adpcmwaveformat_tag *)v5;
  if ( v5 != nullptr )
  {
    this->m_pCoefficients = (const adpcmcoef_tag *)(v5 + 22);
    v6 = (__int16 *)MemAlloc_Alloc(
                      nSize: (unsigned __int64)(*((unsigned __int16 *)v5 + 1) * (unsigned int)*((unsigned __int16 *)v5 + 9)) >> 31 != 0
                    ? -1
                    : 2 * *((unsigned __int16 *)v5 + 1) * *((unsigned __int16 *)v5 + 9));
    m_pFormat = this->m_pFormat;
    this->m_pSamples = v6;
    v8 = m_pFormat->wfx.nChannels * (m_pFormat->wSamplesPerBlock - 2);
    this->m_blockSize = v8 / 2;
    this->m_blockSize = v8 / 2 + 7 * m_pFormat->wfx.nChannels;
    this->m_totalBytes = ((int (__thiscall *)(CVTFTexture *))v4->LowResFileInfo)(a1: v4);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D940
// Name: public: virtual void CAudioMixerWaveADPCM::Mix(class IAudioDevice __near *,struct channel_t __near *,void __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveADPCM::Mix(
        CAudioMixerWaveADPCM *this,
        IAudioDevice *pDevice,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int fracRate,
        int outCount,
        int timecompress)
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
// Address: 0x1003D9B0
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
// Address: 0x1003DAB0
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
// Address: 0x1003DC00
// Name: private: bool CAudioMixerWaveADPCM::DecodeBlock(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioMixerWaveADPCM::DecodeBlock(CAudioMixerWaveADPCM *this)
{
  CAudioSourceWave *v2; // eax
  int v3; // eax
  int m_totalBytes; // ecx
  int v5; // edi
  int v7; // edx
  int v8; // eax
  int v9; // ebx
  int m_blockSize; // ecx
  int v11; // eax
  unsigned int v12; // edi
  signed int v13; // ebx
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int nChannels; // ebx
  int wSamplesPerBlock; // ecx
  int v17; // eax
  __int16 *m_pSamples; // edx
  unsigned __int8 *v19; // [esp-Ch] [ebp-1020h]
  int v20; // [esp-8h] [ebp-101Ch]
  unsigned __int8 dst[4096]; // [esp+8h] [ebp-100Ch] BYREF
  int v22; // [esp+1008h] [ebp-Ch]
  int v23; // [esp+100Ch] [ebp-8h]
  unsigned __int8 *src; // [esp+1010h] [ebp-4h] BYREF

  v2 = (CAudioSourceWave *)this->m_pData->Source(this: this->m_pData);
  v3 = CAudioSourceWave::ConvertLoopedPosition(this: v2, samplePosition: this->m_offset);
  m_totalBytes = this->m_totalBytes;
  v5 = v3;
  this->m_offset = v3;
  if ( v3 >= m_totalBytes )
    return 0;
  v7 = v3 % this->m_blockSize;
  v8 = v3 - v7;
  v9 = m_totalBytes - (v5 - v7);
  m_blockSize = this->m_blockSize;
  v22 = v7;
  this->m_offset = v5 - v7;
  v23 = v9;
  if ( v9 > m_blockSize )
  {
    v23 = m_blockSize;
    v9 = m_blockSize;
  }
  v11 = ((int (__thiscall *)(IWaveData *, unsigned __int8 **, int, int, int, _DWORD))this->m_pData->ReadSourceData)(
          a1: this->m_pData,
          a2: &src,
          a3: v8,
          a4: v8 >> 31,
          a5: v9,
          a6: 0);
  v12 = v11;
  if ( v11 < v9 )
  {
    v13 = 0;
    if ( v11 != 0 )
    {
      do
      {
        if ( v13 >= v23 )
          break;
        memcpy(dst: &dst[v13], src, count: v12);
        v13 += v12;
        v12 = ((int (__thiscall *)(IWaveData *, unsigned __int8 **, int, int, int, _DWORD))this->m_pData->ReadSourceData)(
                a1: this->m_pData,
                a2: &src,
                a3: v13 + this->m_offset,
                a4: (v13 + this->m_offset) >> 31,
                a5: v23 - v13,
                a6: 0);
      }
      while ( v12 != 0 );
    }
    src = dst;
    v12 = v13;
  }
  if ( v12 == 0 )
    return 0;
  m_pFormat = this->m_pFormat;
  this->m_offset += v12;
  if ( m_pFormat != nullptr )
    nChannels = m_pFormat->wfx.nChannels;
  else
    nChannels = 0;
  wSamplesPerBlock = m_pFormat->wSamplesPerBlock;
  v17 = (int)(2 * (v12 - this->m_blockSize)) / nChannels;
  this->m_samplePosition = v22;
  m_pSamples = this->m_pSamples;
  v20 = wSamplesPerBlock + v17;
  v19 = src;
  this->m_sampleCount = wSamplesPerBlock + v17;
  if ( nChannels == 1 )
    CAudioMixerWaveADPCM::DecompressBlockMono(this, pOut: m_pSamples, pIn: (const char *)v19, count: v20);
  else
    CAudioMixerWaveADPCM::DecompressBlockStereo(this, pOut: m_pSamples, pIn: (const char *)v19, count: v20);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003DD30
// Name: public: virtual int CAudioMixerWaveADPCM::GetOutputData(void __near * __near *,int,char __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveADPCM::GetOutputData(
        CAudioMixerWaveADPCM *this,
        void **pData,
        int sampleCount,
        char *copyBuf)
{
  int m_samplePosition; // eax
  const adpcmwaveformat_tag *m_pFormat; // ecx
  int nChannels; // ecx
  int v8; // eax
  int v9; // ecx
  bool v11; // cf

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
  v8 = this->m_samplePosition;
  v9 = this->m_sampleCount - v8;
  if ( v9 > sampleCount )
    v9 = sampleCount;
  this->m_samplePosition = v9 + v8;
  this->m_sample_max_loaded += v9;
  v11 = __CFADD__(v9, this->m_sample_loaded_index);
  LODWORD(this->m_sample_loaded_index) += v9;
  HIDWORD(this->m_sample_loaded_index) += (v9 >> 31) + v11;
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1003DDA0
// Name: public: virtual void CAudioMixerWaveADPCM::SetSampleStart(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioMixerWaveADPCM::SetSampleStart(CAudioMixerWaveADPCM *this, int newPosition)
{
  int v3; // edx
  int v4; // edi
  int m_sampleCount; // eax

  CAudioMixerWave::SetSampleStart(this, newPosition);
  v3 = newPosition % this->m_pFormat->wSamplesPerBlock;
  this->m_offset = newPosition / this->m_pFormat->wSamplesPerBlock * this->m_blockSize;
  v4 = v3;
  CAudioMixerWaveADPCM::DecodeBlock(this);
  m_sampleCount = this->m_sampleCount;
  if ( v4 >= m_sampleCount )
    this->m_samplePosition = v4;
  else
    this->m_samplePosition = m_sampleCount;
}

//------------------------------------------------------------------------------
// Address: 0x1003DDF0
// Name: class CAudioMixer __near * CreateADPCMMixer(class IWaveData __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWaveADPCM *__cdecl CreateADPCMMixer(IWaveData *data)
{
  CAudioMixerWaveADPCM *v1; // eax

  v1 = (CAudioMixerWaveADPCM *)MemAlloc_Alloc(nSize: 0x58u);
  if ( v1 != nullptr )
    return CAudioMixerWaveADPCM::CAudioMixerWaveADPCM(this: v1, data);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003DE20
// Name: public: virtual int CAudioMixerWaveADPCM::GetMixSampleSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioMixerWaveADPCM::GetMixSampleSize(CAudioMixerWaveADPCM *this)
{
  const adpcmwaveformat_tag *m_pFormat; // eax

  m_pFormat = this->m_pFormat;
  if ( m_pFormat != nullptr )
    return 2 * m_pFormat->wfx.nChannels;
  else
    return 0;
}

} // namespace engine_xlsp
