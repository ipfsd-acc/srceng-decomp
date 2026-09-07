// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/resample.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041B970
// Name: ExtractFloatSamples
// Source: json
//------------------------------------------------------------------------------
void __usercall ExtractFloatSamples(
        const __int16 *pInputBuffer@<eax>,
        float *pOut,
        int sampleCount,
        unsigned int stride)
{
  float *v4; // ecx
  int v5; // esi
  int v6; // edi
  unsigned int v7; // edx
  float *v8; // ecx
  unsigned int v9; // esi
  int v10; // ebx
  const __int16 *v11; // eax
  int v12; // ebx
  const __int16 *v13; // eax

  v4 = pOut;
  v5 = sampleCount;
  v6 = 0;
  if ( sampleCount >= 4 )
  {
    v7 = stride;
    v8 = pOut + 2;
    v9 = ((unsigned int)(sampleCount - 4) >> 2) + 1;
    v6 = 4 * v9;
    do
    {
      *(v8 - 2) = (float)*pInputBuffer * 0.000030517578;
      v10 = pInputBuffer[stride];
      v11 = &pInputBuffer[v7];
      *(v8 - 1) = (float)v10 * 0.000030517578;
      v12 = v11[stride];
      v13 = &v11[v7];
      *v8 = (float)v12 * 0.000030517578;
      v8[1] = (float)v13[stride] * 0.000030517578;
      pInputBuffer = &v13[v7 + v7];
      v8 += 4;
      --v9;
    }
    while ( v9 != 0 );
    v5 = sampleCount;
    v4 = pOut;
  }
  for ( ; v6 < v5; pInputBuffer += stride )
    v4[v6++] = (float)*pInputBuffer * 0.000030517578;
}

//------------------------------------------------------------------------------
// Address: 0x0041BA30
// Name: void DecimateSampleBlock(float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecimateSampleBlock(float *pInOut, int sampleCount)
{
  float v2; // xmm6_4
  int v3; // eax
  float v4; // xmm5_4
  float v5; // xmm7_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float block; // [esp+0h] [ebp-3Ch]
  float block_4; // [esp+4h] [ebp-38h]
  float block_8; // [esp+8h] [ebp-34h]
  float block_12; // [esp+Ch] [ebp-30h]
  float block_20; // [esp+14h] [ebp-28h]
  float block_24; // [esp+18h] [ebp-24h]
  float block_28; // [esp+1Ch] [ebp-20h]
  float block_32; // [esp+20h] [ebp-1Ch]

  v2 = 0.0;
  v3 = 0;
  v4 = 0.0;
  v5 = 0.0;
  block_24 = 0.0;
  block_20 = 0.0;
  block_12 = 0.0;
  block_8 = 0.0;
  block_4 = 0.0;
  block = 0.0;
  while ( 1 )
  {
    v6 = pInOut[2 * v3];
    v7 = v6 * -0.0070800781;
    v8 = v6 * 0.026184082;
    block_32 = v5 + (float)(v6 * -0.0070800781);
    v9 = v6 * -0.077941895;
    v10 = v6 * 0.30773926;
    v11 = pInOut[2 * v3] * 0.0010986328;
    block_28 = block_24 + v8;
    block_24 = block_20 + v9;
    v12 = block_12 + v10;
    block_20 = v2 + v10;
    v13 = pInOut[2 * v3 + 1];
    block_12 = block_8 + v9;
    pInOut[v3++] = v4 + v11;
    v2 = (float)(v13 * 0.5) + v12;
    block_8 = block_4 + v8;
    block_4 = v7 + block;
    block = v11;
    if ( v3 >= sampleCount >> 1 )
      break;
    v4 = block_32;
    v5 = block_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BB40
// Name: void DecompressBlockMono(struct adpcmstate_t const __near &,short __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecompressBlockMono(const adpcmstate_t *state, __int16 *pOut, const char *pIn, int count)
{
  const adpcmcoef_tag *v4; // eax
  int iCoef1; // edx
  int v6; // esi
  int v7; // eax
  int v8; // edx
  const char *v9; // ecx
  __int16 *v10; // edi
  bool v11; // zf
  int v12; // edx
  char v13; // bl
  int v14; // edx
  int v15; // edx
  int co1; // [esp+8h] [ebp-Ch]
  int co2; // [esp+Ch] [ebp-8h]
  int samp1; // [esp+10h] [ebp-4h]
  int sample; // [esp+1Ch] [ebp+8h]
  int high; // [esp+20h] [ebp+Ch]
  int delta; // [esp+24h] [ebp+10h]
  int counta; // [esp+28h] [ebp+14h]

  v4 = &state->pCoefficients[*pIn];
  iCoef1 = v4->iCoef1;
  v6 = *(__int16 *)(pIn + 3);
  co2 = v4->iCoef2;
  v7 = *(__int16 *)(pIn + 5);
  co1 = iCoef1;
  v8 = *(__int16 *)(pIn + 1);
  *pOut = v7;
  pOut[1] = v6;
  v9 = pIn + 7;
  v10 = pOut + 2;
  v11 = count == 2;
  counta = count - 2;
  delta = v8;
  samp1 = v6;
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
      v6 = ((co1 * v6 + co2 * v7) >> 8) + delta * error_sign_lut[v15];
      delta = (delta * error_coefficients_lut[v15]) >> 8;
      if ( delta < 16 )
        delta = 16;
      if ( v6 <= 0x7FFF )
      {
        if ( v6 < -32768 )
          v6 = -32768;
      }
      else
      {
        v6 = 0x7FFF;
      }
      v7 = samp1;
      *v10++ = v6;
      v11 = counta-- == 1;
      samp1 = v6;
      if ( v11 )
        break;
      v12 = high;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BC40
// Name: void DecompressBlockStereo(struct adpcmstate_t const __near &,short __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecompressBlockStereo(const adpcmstate_t *state, __int16 *pOut, const char *pIn, int count)
{
  const adpcmcoef_tag *pCoefficients; // eax
  int v5; // ecx
  int iCoef1; // edx
  int v7; // ebx
  int v8; // ecx
  int v9; // edx
  int iCoef2; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // edi
  int v14; // ecx
  int v15; // edx
  const char *v16; // esi
  bool v17; // zf
  int i; // edx
  char v19; // al
  int v20; // ecx
  int v21; // ecx
  int v22; // edi
  int v23; // ebx
  int v24; // ecx
  int v25; // eax
  int co1[2]; // [esp+Ch] [ebp-30h]
  int co2[2]; // [esp+14h] [ebp-28h]
  int samp2[2]; // [esp+1Ch] [ebp-20h]
  int samp1[2]; // [esp+24h] [ebp-18h]
  int delta[2]; // [esp+2Ch] [ebp-10h]
  int sample; // [esp+34h] [ebp-8h]
  int high; // [esp+38h] [ebp-4h]
  __int16 *pOuta; // [esp+48h] [ebp+Ch]
  int counta; // [esp+50h] [ebp+14h]

  pCoefficients = state->pCoefficients;
  v5 = *pIn;
  iCoef1 = pCoefficients[v5].iCoef1;
  v7 = *((__int16 *)pIn + 6);
  co2[0] = pCoefficients[v5].iCoef2;
  v8 = pIn[1];
  co1[0] = iCoef1;
  v9 = pCoefficients[v8].iCoef1;
  iCoef2 = pCoefficients[v8].iCoef2;
  v11 = *((__int16 *)pIn + 1);
  co1[1] = v9;
  v12 = *((__int16 *)pIn + 2);
  v13 = *((__int16 *)pIn + 5);
  co2[1] = iCoef2;
  delta[0] = v11;
  v14 = *((__int16 *)pIn + 3);
  delta[1] = v12;
  v15 = *((__int16 *)pIn + 4);
  *pOut = v13;
  pOut[1] = v7;
  pOut[2] = v14;
  pOut[3] = v15;
  v16 = pIn + 14;
  v17 = count == 2;
  counta = count - 2;
  samp1[0] = v14;
  samp1[1] = v15;
  samp2[0] = v13;
  samp2[1] = v7;
  pOuta = pOut + 4;
  high = 1;
  sample = 0;
  if ( !v17 )
  {
    do
    {
      for ( i = 0; i < 2; ++i )
      {
        if ( high != 0 )
        {
          v19 = *v16;
          v20 = *(unsigned __int8 *)v16++;
          v21 = v20 >> 4;
          sample = v19 & 0xF;
          high = 0;
        }
        else
        {
          v21 = sample;
          high = 1;
        }
        v22 = delta[i];
        v23 = v22 * error_sign_lut[v21];
        v24 = (v22 * error_coefficients_lut[v21]) >> 8;
        v25 = v23 + ((samp1[i] * co1[i] + samp2[i] * co2[i]) >> 8);
        delta[i] = v24;
        if ( v24 < 16 )
          delta[i] = 16;
        if ( v25 <= 0x7FFF )
        {
          if ( v25 < -32768 )
            v25 = -32768;
        }
        else
        {
          v25 = 0x7FFF;
        }
        *pOuta++ = v25;
        samp2[i] = samp1[i];
        samp1[i] = v25;
      }
      --counta;
    }
    while ( counta != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BDA0
// Name: int ADPCMSampleCount(unsigned char const __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ADPCMSampleCount(const unsigned __int8 *pFormatChunk, const unsigned __int8 *pDataChunk, int dataSize)
{
  int v3; // edi
  __int64 v4; // rax
  int v5; // ecx
  int v6; // edi
  int state_8; // [esp+10h] [ebp-4h]

  if ( pFormatChunk != nullptr )
  {
    v3 = *((unsigned __int16 *)pFormatChunk + 1);
    v4 = v3 * (*((unsigned __int16 *)pFormatChunk + 9) - 2);
    v5 = 7 * v3 + (((int)v4 - HIDWORD(v4)) >> 1);
  }
  else
  {
    v5 = state_8;
  }
  v6 = dataSize / v5;
  if ( dataSize % v5 >= 8 )
    return 2 * (dataSize % v5 - v5) / *((unsigned __int16 *)pFormatChunk + 1)
         + *((unsigned __int16 *)pFormatChunk + 9)
         + v6 * *((unsigned __int16 *)pFormatChunk + 9);
  else
    return v6 * *((unsigned __int16 *)pFormatChunk + 9);
}

//------------------------------------------------------------------------------
// Address: 0x0041BE20
// Name: void DecompressADPCMSamples(unsigned char const __near *,unsigned char const __near *,int,short __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecompressADPCMSamples(
        const unsigned __int8 *pFormatChunk,
        const unsigned __int8 *pDataChunk,
        int dataSize,
        __int16 *pOutputBuffer)
{
  int v5; // esi
  __int64 v6; // rax
  int blockSize; // ecx
  int v8; // edi
  int v9; // esi
  adpcmstate_t state; // [esp+Ch] [ebp-Ch] BYREF
  int block; // [esp+20h] [ebp+8h]

  state.pFormat = (const adpcmwaveformat_tag *)pFormatChunk;
  if ( pFormatChunk != nullptr )
  {
    v5 = *((unsigned __int16 *)pFormatChunk + 1);
    state.pCoefficients = (const adpcmcoef_tag *)(pFormatChunk + 22);
    v6 = v5 * (*((unsigned __int16 *)pFormatChunk + 9) - 2);
    blockSize = 7 * v5 + (((int)v6 - HIDWORD(v6)) >> 1);
    state.blockSize = blockSize;
  }
  else
  {
    blockSize = state.blockSize;
  }
  v8 = dataSize;
  if ( dataSize > 0 )
  {
    while ( 1 )
    {
      v9 = *((unsigned __int16 *)pFormatChunk + 9);
      block = v8;
      if ( v8 <= blockSize )
      {
        if ( v8 >= 8 )
          v9 += 2 * (v8 - blockSize) / *((unsigned __int16 *)pFormatChunk + 1);
        else
          v9 = 0;
      }
      else
      {
        block = blockSize;
      }
      if ( *((_WORD *)pFormatChunk + 1) == 1 )
        DecompressBlockMono(&state, pOut: pOutputBuffer, pIn: (const char *)pDataChunk, count: v9);
      else
        DecompressBlockStereo(&state, pOut: pOutputBuffer, pIn: (const char *)pDataChunk, count: v9);
      pDataChunk += block;
      v8 -= block;
      pOutputBuffer += v9 * *((unsigned __int16 *)pFormatChunk + 1);
      if ( v8 <= 0 )
        break;
      blockSize = state.blockSize;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BEF0
// Name: void Convert8To16(unsigned char const __near *,short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Convert8To16(
        const unsigned __int8 *pInputBuffer,
        __int16 *pOutputBuffer,
        int sampleCount,
        int channelCount)
{
  int i; // eax

  for ( i = 0; i < channelCount * sampleCount; ++i )
    pOutputBuffer[i] = (unsigned __int8)(pInputBuffer[i] + 0x80) | ((unsigned __int8)(pInputBuffer[i] + 0x80) << 8);
}

//------------------------------------------------------------------------------
// Address: 0x0041BF30
// Name: void DecimateSampleRateBy2_16(short const __near *,short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecimateSampleRateBy2_16(char *pInputBuffer, __int16 *pOutputBuffer, int sampleCount, int channelCount)
{
  float *v4; // eax
  unsigned int v5; // edx
  float *v6; // edi
  int v7; // esi
  int v8; // ecx
  __int16 *v9; // ebx
  int v10; // eax
  __int16 *i; // edx
  int v12; // ecx
  int v13; // [esp+Ch] [ebp-4h]

  v4 = (float *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)sampleCount >> 30 != 0 ? -1 : 4 * sampleCount);
  v5 = channelCount;
  v6 = v4;
  if ( channelCount > 0 )
  {
    v7 = sampleCount >> 1;
    v8 = pInputBuffer - (char *)pOutputBuffer;
    v9 = pOutputBuffer;
    v13 = channelCount;
    while ( 1 )
    {
      ExtractFloatSamples(pInputBuffer: (__int16 *)((char *)v9 + v8), pOut: v6, sampleCount, stride: v5);
      DecimateSampleBlock(pInOut: v6, sampleCount);
      v10 = 0;
      for ( i = v9; v10 < v7; i += channelCount )
      {
        v12 = (int)(float)(v6[v10] * 32768.0);
        if ( v12 >= -32768 )
        {
          if ( v12 > 0x7FFF )
            LOWORD(v12) = 0x7FFF;
        }
        else
        {
          LOWORD(v12) = 0x8000;
        }
        *i = v12;
        ++v10;
      }
      ++v9;
      if ( --v13 == 0 )
        break;
      v5 = channelCount;
      v8 = pInputBuffer - (char *)pOutputBuffer;
    }
  }
  free(pMem: v6);
}
